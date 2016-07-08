#include <Arduino.h>

#include "pindef.h" 
#include "tube_control.h"
#include "RTC.h"
#include "clock.h"
#include "mp3.h"

int tube[8]; //This array record the data of all tubes

int clock_mode = TIME_MODE;

void display_time_mode(rtc_time_t *time)
{

  for(int tube_index = 0; tube_index < 8; tube_index++) {
    
    tube_digit_sort(tube, time, clock_mode);

    /* Light the right dot of tube 2 and 5 */
    if(tube_index != 2 && tube_index != 5) { 
      digitalWrite(pin_font_right_dot, LOW);
      //delayMicroseconds(500);
    }

    tube_control(tube_index, tube[tube_index]);

    /* Light the right dot of tube 2 and 5 */
    if(tube_index == 2 || tube_index == 5) { 
      digitalWrite(pin_font_right_dot, HIGH);
      //delayMicroseconds(500);
    }
    
    delayMicroseconds(1000);
  }
}

void display_date_mode(rtc_time_t *time)
{
  for(int tube_index = 0; tube_index < 8; tube_index++) {
    delay(1);
    
    tube_digit_sort(tube, time, clock_mode);

    tube_control(tube_index, tube[tube_index]);

    /* Light the right dot of tube 2 and 4 */
    if(tube_index == 2 || tube_index == 4) {
      digitalWrite(pin_font_right_dot, HIGH);
    } else {
      digitalWrite(pin_font_right_dot, LOW);
      delay(1);
    }
    
    delayMicroseconds(1);
  }
}

void display_music_mode()
{
  sort_tube_digit_for_music(tube, music_current_select);

  for(int tube_index = 0; tube_index < 8; tube_index++) {
    delay(1);

    tube_control(tube_index, tube[tube_index]);

    /* Light the right dot of tube 0 */
    if(tube_index == 0) { 
      digitalWrite(pin_font_right_dot, HIGH);
    } else {
      digitalWrite(pin_font_right_dot, LOW);
      delay(1);
    }
    
    delayMicroseconds(1);
  }
}

void clock_display(rtc_time_t *time)
{
    if(clock_mode == TIME_MODE) {
      display_time_mode(time);
    } else if(clock_mode == DATE_MODE) {
      display_date_mode(time);
    }
}
