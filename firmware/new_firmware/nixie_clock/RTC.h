#ifndef __RTC_H
#define __RTC_H

void RTC_init();
void RTC_set_time(int year, int month, int day, int hour, int minute, int second);

void print_time();

#endif
