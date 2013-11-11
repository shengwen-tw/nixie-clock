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
void btn_search_event();
void btn_adjust_event();
void btn_mode_event();

int clock_mode = TIME_MODE; //Current clock mode
int isr_count = 0; //The counter of Timer
int btnTime_record_flg = 0; //The flag of program should record the time of  button press down or not
int btn_hold_time = 0; //Record the time of user press down the button
int cur_blink_digit = 0; //

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
    pinMode(btn_search, INPUT);
    pinMode(btn_adjust, INPUT);
    
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
  
        blink_time++;
        
        //Clean up for next duty cycle
        if(blink_time > BLINK_DUTY )
            blink_time = 0;
            
        if(btnTime_record_flg == 1) {
            btn_hold_time++;
        }
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
    btn_search_event();
    btn_adjust_event();
    btn_mode_event();
}

//Search button handler
void btn_search_event()
{
    int read_val;
    
    /* Check search button */
    read_val = digitalRead(btn_search);
    if(read_val == HIGH) {
        clock_mode++;
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
        display_time(clock_mode - 1);
        read_val = digitalRead(btn_search);
    }
    
    if(clock_mode == MODE_CNT)
        clock_mode = DATE_MODE;
}

//Adjust button handler
void btn_adjust_event()
{
    int read_val = digitalRead(btn_adjust);;

    //Waiting for user release the button
    while(read_val == HIGH) {
        btnTime_record_flg = 1;
        
        if(btn_hold_time >= 1) {
            //TODO: Switch to setting mode
            if(blink_digit == -1) {
                /* Fisrt time long press the button, switch to the setting mode */
                cur_blink_digit = 7;
                set_blink_digit(cur_blink_digit);
            } else {
                /* Second time long press the button, switch back to the normal mode */
                cur_blink_digit = -1;
                set_blink_digit(cur_blink_digit);
            }
        }
        
        display_time(clock_mode);
        read_val = digitalRead(btn_adjust);
    }
    
    //btnTime_record_flg means the button had been pressed
    if(btnTime_record_flg) {
        switch(clock_mode) {
              case TIME_MODE:
                hour_format++;
                hour_format %= 2;
                break;
        }
    }
    
    btnTime_record_flg = 0;
    btn_hold_time = 0;
}

void btn_mode_event()
{
    int read_val;
    
    /* Check mode button */
    read_val = digitalRead(btn_mode);
    
    if(read_val == HIGH) {
        if(blink_digit < 8 && cur_blink_digit != -1) {
            cur_blink_digit++;
            //FIXME
            set_blink_digit(cur_blink_digit);
        } else {
            cur_blink_digit = -1;
            //FIXME
            set_blink_digit(cur_blink_digit);
        }
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
        read_val = digitalRead(btn_mode);
        display_time(clock_mode);
    }
}

