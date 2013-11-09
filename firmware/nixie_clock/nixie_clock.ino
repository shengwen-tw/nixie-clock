#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"

void setup()
{
    pinMode(font_pinA, OUTPUT);
    pinMode(font_pinB, OUTPUT);
    pinMode(font_pinC, OUTPUT);
    pinMode(font_pinD, OUTPUT);
  
    pinMode(digit_pinA, OUTPUT);
    pinMode(digit_pinB, OUTPUT);
    pinMode(digit_pinC, OUTPUT);
    
    setSyncProvider(RTC.get);
}

void loop()
{
    while(1) {
        display_time(TIME_MODE);
    }
}


