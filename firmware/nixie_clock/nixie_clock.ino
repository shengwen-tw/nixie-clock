#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"

void check_button();

enum CLOCK_MODE {
    DATE_MODE,
    TIME_MODE,
    MODE_CNT
};

int clock_mode = DATE_MODE;

void setup()
{
    pinMode(font_pinA, OUTPUT);
    pinMode(font_pinB, OUTPUT);
    pinMode(font_pinC, OUTPUT);
    pinMode(font_pinD, OUTPUT);
  
    pinMode(digit_pinA, OUTPUT);
    pinMode(digit_pinB, OUTPUT);
    pinMode(digit_pinC, OUTPUT);
    
    pinMode(dot_pin, OUTPUT);
    
    pinMode(display_enable_gate, OUTPUT);
    
    pinMode(btn_mode_pin, INPUT);
    
    setSyncProvider(RTC.get);
}

void loop()
{
    display_time(clock_mode);
    check_button();
}

void check_button()
{  
    int read_val;
    
    //Check the mode switch button
    read_val = digitalRead(btn_mode_pin);
    if(read_val == HIGH) {
        clock_mode++;
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
      display_time(clock_mode - 1);
      read_val = digitalRead(btn_mode_pin);
    }
        
    if(clock_mode == MODE_CNT)
        clock_mode = DATE_MODE;
}

