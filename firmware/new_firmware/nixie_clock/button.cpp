#include <Arduino.h>

#include "pindef.h"
#include "clock.h"
#include "alarm.h"

extern int clock_mode;

int mode_button_trigger = 0;

void button_status_check()
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
