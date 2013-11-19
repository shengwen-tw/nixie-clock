#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"
#include "event.h"

clock_time clock;

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
    pinMode(btn_search, INPUT);
    pinMode(btn_adjust, INPUT);
    
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
}

void loop()
{
      clock.display_time();
}
