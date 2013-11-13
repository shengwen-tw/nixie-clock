#ifndef __CLOCK_TIME_H__
#define __CLOCK_TIME_H__

#define FORMAT_24HR 1
#define FORMAT_12HR 0

#define BLINK_DUTY  1

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

/* Flag of the hour format, which provide FORMAT_24HR and FORMAT_12HR two options */
extern int hour_format;
/* Blink */
extern int blink_time;
extern int blink_digit;
extern int cur_blink_digit; //Record the current digit which is blinking
/* Mode */
extern int clock_mode; //Current clock mode
extern int time_mode; //Current display mode of time

void set_blink_digit(int digit);
void display_time(int flag);

#endif
