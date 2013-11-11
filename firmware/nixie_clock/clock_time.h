#ifndef __CLOCK_TIME_H__
#define __CLOCK_TIME_H__

#define FORMAT_24HR 1
#define FORMAT_12HR 0

#define BLINK_DUTY  1

//Flag of the hour format, which provide FORMAT_24HR and FORMAT_12HR two options
extern int hour_format;
extern int blink_time;
extern int blink_digit;

void set_blink_digit(int digit);
void display_time(int flag);

#endif
