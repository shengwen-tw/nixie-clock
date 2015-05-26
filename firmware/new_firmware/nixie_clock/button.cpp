#include <Arduino.h>

#include "pindef.h"
#include "clock.h"


extern int clock_mode;

int mode_button_trigger = 0;

void button_status_check()
{
  if(digitalRead(pin_mode_button) == HIGH)
    mode_button_trigger = 1;
   
  if(digitalRead(pin_mode_button) == LOW && mode_button_trigger == 1) {
    clock_mode++;
    clock_mode %= MODE_COUNT;
      
    mode_button_trigger = 0;
  }
}
