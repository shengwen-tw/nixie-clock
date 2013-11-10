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

void check_button();

int clock_mode = TIME_MODE;
extern int hour_format;

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
    
    pinMode(btn_time_mode, INPUT);
    pinMode(btn_display_mode, INPUT);
    
    setSyncProvider(RTC.get);
    
    Serial.begin(115200);
}

void loop()
{
    display_time(clock_mode);
    check_button();
}

void check_button()
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
    
    /* Check the display mode switch button */
    read_val = digitalRead(btn_display_mode);
    if(read_val == HIGH) {
        hour_format++;
        hour_format %= 2;
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
      display_time(clock_mode);
      read_val = digitalRead(btn_display_mode);
    }
    
    if(clock_mode == MODE_CNT)
        clock_mode = DATE_MODE;
}

