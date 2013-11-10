#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"

enum CLOCK_MODE {
    DATE_MODE,
    TIME_MODE,
    MODE_CNT
};

/* Button event handler */
void btn_clockMode_event();
void btn_displayMode_event();

//Flag of the hour format, which provide FORMAT_24HR and FORMAT_12HR two options
extern int hour_format;
int clock_mode = TIME_MODE; //Current clock mode
int isr_count = 0; //The counter of Timer
int btnTime_record_flg = 0; //The flag of program should record the time of  button press down or not
int btn_hold_time = 0; //Record the time of user press down the button

void setup()
{
    /* Setting the pin mode */
    //Fonts
    pinMode(font_pinA, OUTPUT);
    pinMode(font_pinB, OUTPUT);
    pinMode(font_pinC, OUTPUT);
    pinMode(font_pinD, OUTPUT);
    pinMode(dot_pin, OUTPUT);
    //Digits
    pinMode(digit_pinA, OUTPUT);
    pinMode(digit_pinB, OUTPUT);
    pinMode(digit_pinC, OUTPUT);
    //Display enable gate
    pinMode(display_enable_gate, OUTPUT);
    //Buttons
    pinMode(btn_time_mode, INPUT);
    pinMode(btn_display_mode, INPUT);
    
    /* Initial the real time clock */
    setSyncProvider(RTC.get);
    
    /* Initial the serial for debugging */
    Serial.begin(115200);
    
    /* Initial the Timer1 */
    TCCR1A = 0x00; //Normal mode
    //No prescaling : CS12, CS11, CS10 = 0, 0, 1
    TCCR1B &= ~_BV(CS12);
    TCCR1B &= ~_BV(CS11);
    TCCR1B |= _BV(CS10);
    //Enable the overflow interrupt of Timer1
    TIMSK1 |= _BV(TOIE1);
    //Clear the counter of Timer1
    TCNT1 = 0;
}

ISR (TIMER1_OVF_vect)
{  
    isr_count++;
    
    if(isr_count == 244) {
        if(btnTime_record_flg == 1)
            btn_hold_time++;
            
            isr_count = 0;
    }
}

void loop()
{
    /* Handle the action of the each clock mode*/
    switch(clock_mode) {
        case DATE_MODE:
        case TIME_MODE:
            display_time(clock_mode);
            break;
    }
    
    /* Check the status of the button */
    btn_clockMode_event();
    btn_displayMode_event();
}

//Clock mode switch button handler
void btn_clockMode_event()
{
    int read_val;
    
    /* Check the mode switch button */
    read_val = digitalRead(btn_time_mode);
    if(read_val == HIGH) {
        clock_mode++;
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
        display_time(clock_mode - 1);
        read_val = digitalRead(btn_time_mode);
    }
    
    if(clock_mode == MODE_CNT)
        clock_mode = DATE_MODE;
}

//Display mode switch button handler
void btn_displayMode_event()
{
    int read_val;

    /* Check the display mode switch button */
    read_val = digitalRead(btn_display_mode);
    if(read_val == HIGH) {
        switch(clock_mode) {
              case TIME_MODE:
                hour_format++;
                hour_format %= 2;
                break;
        }
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
        btnTime_record_flg = 1;
        
        if(btn_hold_time >= 2) {
            display_time(clock_mode);
            //TODO: Switch to setting mode
        } else {
            display_time(clock_mode);
        }
        read_val = digitalRead(btn_display_mode);
    }
    
    btnTime_record_flg = 0;
    btn_hold_time = 0;
}

