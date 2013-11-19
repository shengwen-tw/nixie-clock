#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#ifndef __CLOCK_TIME_H__
#define __CLOCK_TIME_H__

#define FORMAT_24HR 1
#define FORMAT_12HR 0

#define EMPTY_DIGIT -1

/* Clock mode provide user have multiple functions like: time, alarm, timer... etc */
enum CLOCK_MODE {
    CLOCK_TIME,
    CLOCK_ALARM,
    CLOCK_SETTING,
    CLOCK_MODE_CNT
};

/* Time mode provide date and time */
enum TIME_MODE {
    DATE_MODE,
    TIME_MODE,
    TIME_MODE_CNT
};

class clock_time {
  private:
      int blink_time;
      /* Time display mode and format*/
      int clock_mode;
      int time_mode;
      int hour_format;
      /* Time data */
      int _year;
      int _month;
      int _day;
      int _hour;
      int _minute;
      int _second;
      /* Time data in digits */
      int date_digit[8];
      int time_digit[8];
      /* Internal functions */
      void read_time();
      void sort_to_digit();
      int is_blink_digit();
  public:
      clock_time();
      /* Digit blink related functions */
      void set_blink_digit();
      void clear_blink_digit();
      /* Time display functions */
      void display_time();
      /* Time setting functons */
};

#endif
