#ifndef __CLOCK_H
#define __CLOCK_H

#include "RTC.h"

extern int clock_mode;

enum{
  TIME_MODE,
  DATE_MODE,
  MODE_COUNT
};

void clock_display(rtc_time_t *time);
void mp3_init();

#endif
