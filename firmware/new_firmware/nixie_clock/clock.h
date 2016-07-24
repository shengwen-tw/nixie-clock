#ifndef __CLOCK_H
#define __CLOCK_H

#include "RTC.h"

extern int clock_mode;

typedef struct {
  int hour_start;
  int minute_start;
  int hour_end;
  int minute_end;

  bool enabled;
} hibernate_setting_t;

enum{
  TIME_MODE,
  DATE_MODE,
  MODE_COUNT
};

void clock_display();
void mp3_init();
void enable_timer2();

void load_display_hibernation_from_eeprom(int hour_start, int minute_start, int hour_end,
  int minute_end, bool enabled);
void set_display_hibernation(int hour_start, int minute_start, int hour_end, int minute_end, bool enabled);

void send_hibernate_command();
void check_hibernate_time(rtc_time_t *current_time);

#endif
