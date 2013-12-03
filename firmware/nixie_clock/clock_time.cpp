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

SoftwareSerial garanSerial(bargan_rx, bargan_tx);
Garan player(garanSerial);


clock_time::clock_time()
{
    clock_mode = CLOCK_TIME, time_mode = TIME_MODE;
    hour_format = FORMAT_24HR;
    now_set = HOUR;
    
    player.setVolume(15);
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
    cur_time.year = year();
    cur_time.month = month();
    cur_time.day = day();
    hour_format ? cur_time.hour = hour() : cur_time.hour = hourFormat12();
    cur_time.minute = minute();
    cur_time.second = second();
}

void clock_time::sort_to_digit(time *_time)
{
    /* Year */
    date_digit[7] = _time->year / 1000;
    date_digit[6] = (_time->year / 100) % 10;
    date_digit[5] = (_time->year / 10) % 100;
    date_digit[4] = _time->year % 10;
    /* Month */
    date_digit[3] = _time->month / 10;
    date_digit[2] = _time->month % 10;
    /* Day */
    date_digit[1] = _time->day / 10;
    date_digit[0] = _time->day % 10;
    
    /* Hour */
    time_digit[7] = _time->hour / 10;
    time_digit[6] = _time->hour % 10;
    /* Minute*/
    time_digit[4] = _time->minute / 10;
    time_digit[3] = _time->minute % 10;
    /* Second */
    time_digit[1] = _time->second / 10;
    time_digit[0] = _time->second % 10;
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
        
    if(get_clock_mode() == CLOCK_ALARM || get_clock_mode() == CLOCK_ALARM_SETTING) {
        sort_to_digit(&alarm_time);
        set_time_mode(TIME_MODE); //Turn to the time mode
    } else {   
        read_time();
        sort_to_digit(&cur_time);
    }
    
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
    setTime(0, 0, 1, 1, 1, 2000); //Initial the time with 2000/1/1 - 0:0:1
    set_alarm_time(0, 0, 1); //Set the alarm at 0:0:1
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

void clock_time::inc_time(int clock_mode)
{
    time *_time;
    if(clock_mode == CLOCK_TIME)
        _time = &cur_time;
    else if(clock_mode == CLOCK_ALARM)
        _time = &alarm_time;
    
    switch(get_now_setting()) {
      case YEAR:
          inc_in_range(&_time->year, 2000, 2100);
          break;
      case MONTH:
          inc_in_range(&_time->month, 1, 12);
          break;
      case DAY:
          /*  If the current month is set to be february */
          if(cur_time.month == 2) {
              if(isleap(_time->year))
                  inc_in_range(&_time->day, 1, 29); //Is the leap year
              else
                  inc_in_range(&_time->day, 1, 28); //Not the leap year
          /*  These month contain 30 days */
          } else if(cur_time.month == 2 || cur_time.month == 4 || cur_time.month == 6 || cur_time.month == 9 || cur_time.month == 11){
              inc_in_range(&_time->day, 1, 30);
          /* These month contain 31 days */
          } else {
              inc_in_range(&_time->day, 1, 31);
          }
          break;
      case HOUR:
          inc_in_range(&_time->hour, 0, 23);
          break;
      case MINUTE:
          inc_in_range(&_time->minute, 0, 59);
          break;
      case SECOND:
          inc_in_range(&_time->second, 0, 59);
          break;
    }
    
    setTime(cur_time.hour, cur_time.minute, cur_time.second, cur_time.day, cur_time.month, cur_time.year);
}

/* Music functions */
void play_music(char *music_name)
{
    player.singlePlayName("alarm.mp3");
}

void stop_music()
{
}

/* Alarm related functions */
void clock_time::set_alarm_time(int hour, int minute, int second)
{
    alarm_time.hour = hour;
    alarm_time.minute = minute;
    alarm_time.second = second;
}

bool clock_time::check_alarm_time()
{
    //If the current time minus the alarm time equal means time's up
    return !(bool)(cur_time.hour - alarm_time.hour + cur_time.minute - alarm_time.minute + cur_time.second - alarm_time.second);
}
