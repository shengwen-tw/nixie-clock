#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"

clock_time::clock_time()
{
    clock_mode = CLOCK_TIME, time_mode = TIME_MODE;
    hour_format = FORMAT_24HR;
}

void clock_time::read_time()
{
    _year = year();
    _month = month();
    _day = day();
    hour_format ? _hour = hour() : _hour = hourFormat12();
    _minute = minute();
    _second = second();
}

void clock_time::sort_to_digit()
{
    /* Year */
    date_digit[7] = _year / 1000;
    date_digit[6] = (_year / 100) % 10;
    date_digit[5] = (_year / 10) % 100;
    date_digit[4] = _year % 10;
    /* Month */
    date_digit[3] = _month / 10;
    date_digit[2] = _month % 10;
    /* Day */
    date_digit[1] = _day / 10;
    date_digit[0] = _day % 10;
    
    /* Hour */
    time_digit[7] = _hour / 10;
    time_digit[6] = _hour % 10;
    /* Minute*/
    time_digit[4] = _minute / 10;
    time_digit[3] = _minute % 10;
    /* Second */
    time_digit[1] = _second / 10;
    time_digit[0] = _second % 10;
    /* Empty */
    time_digit[5] = EMPTY_DIGIT;
    time_digit[2] = EMPTY_DIGIT;
}

void clock_time::display_time()
{
    /* If the RTC is not finished Initializing, stop actions */
    if(timeStatus() != timeSet)
        return;
        
    /* Stop reading time and sort to digits while the clock mode is set to be setting */
    if(clock_mode != CLOCK_SETTING) {
        read_time();
        sort_to_digit();
    }
    
    for(int i = 0; i < 8; i++) {
        /* Date mode */
        if(time_mode == DATE_MODE) {
            show_number(date_digit[i], i);
            if(i == 2 || i == 4)
                show_dot(i);
        /* Time mode */
        } else if(time_mode == TIME_MODE) {
            show_number(time_digit[i], i);
        /* Unknown mode */
        } else {
        }
        
        delay(1);
    }
}
