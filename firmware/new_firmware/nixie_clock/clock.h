#ifndef __CLOCK_H
#define __CLOCK_H

typedef enum{
  TIME_MODE,
  DATE_MODE,
  ALARM_MODE
}ClockMode;

void clock_display();

#endif
