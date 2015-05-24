#ifndef __RTC_H
#define __RTC_H

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} rtc_time_t;

void RTC_init();
void RTC_set_time(int year, int month, int day, int hour, int minute, int second);
void RTC_read_time(rtc_time_t *time);

void print_time();

#endif
