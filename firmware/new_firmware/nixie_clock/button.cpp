#include <Arduino.h>

#include "pindef.h"
#include "clock.h"
#include "alarm.h"
#include "mp3.h"

extern int clock_mode;

int mode_button_trigger = 0;
int adjust_button_trigger = 0;

void check_mode_button()
{
  if(digitalRead(pin_mode_button) == HIGH) {
    if(check_alarm_timeup_state() == 1) {
      clear_alarm_timeup_state();
      Serial.println("Clear alarm state");
    } else {
      mode_button_trigger = 1;
    }
  }
   
  if(digitalRead(pin_mode_button) == LOW && mode_button_trigger == 1) {
    clock_mode = (clock_mode + 1 ) % MODE_COUNT;
      
    mode_button_trigger = 0;
  }
}

void check_adjust_button()
{
  if(digitalRead(pin_adjust_button) == HIGH) {
    adjust_button_trigger = 1;
  }
   
  if(digitalRead(pin_adjust_button) == LOW && adjust_button_trigger == 1) {
    music_current_select = (music_current_select + 1 );// % music_count;
      
    adjust_button_trigger = 0;
  }
}

void button_status_check()
{
  check_mode_button();
  check_adjust_button();
}
