#include <Arduino.h>

#include "pindef.h" 
#include "tube_control.h"
#include "RTC.h"
#include "clock.h"

rtc_time_t time; //DS1307 time data
int tube[8]; //This array record the data of all tubes

ClockMode clock_mode = TIME_MODE;

void clock_display()
{
  int tube_index = 0;

  while(1) {

    RTC_read_time(&time);

    time_digit_sort(tube, &time);

    //FIXME
    if(tube_index != 2 && tube_index != 5)
      tube_control(tube_index, tube[tube_index]); 

    tube_index++;
  
    if(tube_index > 7)
      tube_index = 0;
  
    delay(1);
  }
}
