#include <Arduino.h>

#include "pindef.h" 
#include "tube_control.h"
#include "RTC.h"
#include "clock.h"

rtc_time_t time; //DS1307 time data
int tube[8]; //This array record the data of all tubes

int clock_mode = TIME_MODE;

void clock_display()
{
  int tube_index;
  for(tube_index = 0; tube_index < 8; tube_index++) {

    RTC_read_time(&time);

    tube_digit_sort(tube, &time, clock_mode);

    tube_control(tube_index, tube[tube_index]); 
  
    delay(1);
  }
}
