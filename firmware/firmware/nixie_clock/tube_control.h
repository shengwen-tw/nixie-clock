#ifndef __TUBE_CONTROL_H
#define __TUBE_CONTROL_H

#include "RTC.h"
#include "clock.h"

#define USE_HACKED_FONT 1

#if USE_HACKED_FONT == 0
  #define TUBE_0 0
  #define TUBE_1 1
  #define TUBE_2 2
  #define TUBE_3 3
  #define TUBE_4 4
  #define TUBE_5 5
  #define TUBE_6 6
  #define TUBE_7 7
#else
  #define TUBE_0 7
  #define TUBE_1 3
  #define TUBE_2 6 
  #define TUBE_3 2
  #define TUBE_4 5
  #define TUBE_5 1
  #define TUBE_6 4
  #define TUBE_7 0
#endif

#define LEFT_DOT 10
#define RIGHT_DOT 11

#define EMPTY_FONT -1

void tube_control(int tube_number, int tube_font);
void set_tube_brightness(int brightness);
void tube_digit_sort(int tube_font[8], rtc_time_t *time, int clock_mode);
void sort_tube_digit_for_music(int tube_font[8], int song);
void tube_hibernate();

#endif
