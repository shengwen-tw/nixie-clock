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
    now_set = HOUR;
#ifdef NO_DS1307
    for(int i = 0; i < 8; i++) {
        time_digit[i] = 0;
        date_digit[i] = 0;
    }
    
    time_digit[2] = EMPTY_DIGIT;
    time_digit[5] = EMPTY_DIGIT;
#endif
}

/* Digit blink related functions */
int clock_time::get_blink_time()
{
    return blink_time;
}

void clock_time::set_blink_time(int time)
{
    blink_time = time;
}

void clock_time::set_blink_digit(int digit, int status)
{
    status ? blink_digit[digit] = true : blink_digit[digit] = false;
}
  
void clock_time::clear_blink_digit()
{
    for(int i = 0; i < 8; i++)
        blink_digit[i] = false;
}

bool clock_time::is_blink_digit(int digit)
{
    for(int i = 0; i < 8; i++) {
          if(blink_digit[digit] == true)
              return true;
    }
    
    return false;
}

/* Clock mode functions */
int clock_time::get_clock_mode()
{
    return clock_mode;
}

void clock_time::set_clock_mode(int mode)
{
    clock_mode = mode;
}

int clock_time::get_time_mode()
{
    return time_mode;
}

void clock_time::set_time_mode(int mode)
{
    time_mode = mode;
}

int clock_time::get_hour_format()
{
    return hour_format;
}

void clock_time::set_hour_format(int format)
{
    format ? hour_format = FORMAT_24HR : hour_format =  FORMAT_12HR;
}

/* Time display functions */
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
    /* Initial the time of the RTC if the flag of it is set to be timeNotSet */
    if(timeStatus() == timeNotSet)
        initial_time();
    /* If the RTC is not finished Initializing, stop actions */
    else if(timeStatus() == timeNeedsSync)
        return;
        
    read_time();
    sort_to_digit();
    
    for(int i = 0; i < 8; i++) {
        /* Date mode */
        if(time_mode == DATE_MODE) {
            if(get_blink_time() < blink_duty && is_blink_digit(i)) {
                continue;
            } else {
                show_number(date_digit[i], i);
                if(i == 2 || i == 4)
                    show_dot(i);
            }
        /* Time mode */
        } else if(time_mode == TIME_MODE) {
            if(time_digit[i] != EMPTY_DIGIT) {
                if(get_blink_time() < blink_duty && is_blink_digit(i))
                    continue;
                else
                    show_number(time_digit[i], i);
            } else {
                    show_dot(i);
            }
        /* Unknown mode */
        } else {
        }
        
        delay(1);
    }
}

/* Time setting functons */
void clock_time::initial_time()
{
    setTime(0, 0, 1, 1, 1, 2000);
}

int clock_time::get_now_setting()
{
    return now_set;
}

void clock_time::set_setting_digit(int time)
{
    now_set = time;
     
    /* XXX: Hardcode can be improve! */  
    switch(time) {
      case YEAR:
          set_blink_digit(7, ENABLE);
          set_blink_digit(6, ENABLE);
          set_blink_digit(5, ENABLE);
          set_blink_digit(4, ENABLE);
          break;
      case MONTH:
          set_blink_digit(3, ENABLE);
          set_blink_digit(2, ENABLE);
          break;
      case DAY:
          set_blink_digit(1, ENABLE);
          set_blink_digit(0, ENABLE);
          break;
      case HOUR:
          set_blink_digit(7, ENABLE);
          set_blink_digit(6, ENABLE);
          break;
      case MINUTE:
          set_blink_digit(4, ENABLE);
          set_blink_digit(3, ENABLE);
          break;
      case SECOND:
          set_blink_digit(1, ENABLE);
          set_blink_digit(0, ENABLE);
          break;
    }
}

void clock_time::inc_in_range(int *num, int lower, int upper)
{
    if(*num >= lower && *num < upper)
        (*num)++;
    else
        *num = lower;
}

void clock_time::inc_cur_time()
{
    switch(get_now_setting()) {
      case YEAR:
          inc_in_range(&_year, 2000, 2100);
          break;
      case MONTH:
          break;
      case DAY:
          break;
      case HOUR:
          inc_in_range(&_hour, 0, 23);
          break;
      case MINUTE:
          inc_in_range(&_minute, 0, 59);
          break;
      case SECOND:
          inc_in_range(&_second, 0, 59);
          break;
    }
    
    setTime(_hour, _minute, _second, _day, _month, _year);
}
