#include <Arduino.h>
#include <Wire.h>

/* RTC Clock  */
#include <Time.h>
#include <DS1307RTC.h>

/* Music player module */
#include <Garan.h>
#include <SoftwareSerial.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"
#include "event.h"

/* Clock core */
clock_time clock;
/* Create the buttons */
searchButton btn_search(btn_search_pin, &clock);
adjustButton btn_adjust(btn_adjust_pin, &clock);
modeButton btn_mode(btn_mode_pin, &clock);

int isr_count = 0; //The counter of Timer

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
    pinMode(btn_search_pin, INPUT);
    pinMode(btn_adjust_pin, INPUT);
    pinMode(btn_mode_pin, INPUT);
    
    /* Enable the display */
    digitalWrite(display_enable_gate, HIGH);
    
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
        clock.set_blink_time(clock.get_blink_time() + 1);
        
        //Reset the blink time for next duty
        if(clock.get_blink_time() > clock.blink_duty)
            clock.set_blink_time(0);
            
        //If the timer flag of the button is set to be enabled, start to increase the time 
        btn_search.hold_time_inc();
        btn_adjust.hold_time_inc();
        btn_mode.hold_time_inc();
                
        //Check time of the alarm
        if(clock.check_alarm_time() == true) {
            clock.play_music("alarm.mp3");
        }
        
        isr_count = 0;
    }
}

void loop()
{
      //Show the time on the display
      clock.display_time();
      
      //Check the status of the button and do the proper actions
      btn_search.button_click();
      btn_adjust.button_click();
      btn_mode.button_click();
}
