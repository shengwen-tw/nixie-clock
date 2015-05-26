#ifndef __TUBE_CONTROL_H
#define __TUBE_CONTROL_H

#include "RTC.h"
#include "clock.h"

#define LEFT_DOT 10
#define RIGHT_DOT 11

#define EMPTY_FONT -1

void tube_control(int tube_number, int tube_font);
void set_tube_brightness(int brightness);
void tube_digit_sort(int tube_font[8], rtc_time_t *time, int clock_mode);

#endif
