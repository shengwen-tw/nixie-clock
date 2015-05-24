#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "pindef.h" 
#include "tube_control.h"
#include "RTC.h"
#include "clock.h"

void setup()
{
  Serial.begin(9600);
  
  pinMode(pin_font_a, OUTPUT);
  pinMode(pin_font_b, OUTPUT);
  pinMode(pin_font_c, OUTPUT);
  pinMode(pin_font_d, OUTPUT);
  
  pinMode(pin_font_left_dot, OUTPUT);
  pinMode(pin_font_right_dot, OUTPUT);
  
  pinMode(pin_tube_select_a0, OUTPUT);
  pinMode(pin_tube_select_a1, OUTPUT);
  pinMode(pin_tube_select_a2, OUTPUT);
  pinMode(pin_tube_select_a3, OUTPUT);
  
  pinMode(pin_brightness, OUTPUT);
  
  RTC_init();
  
  RTC_set_time(2015, 5, 24, 23, 11, 0);
  
  set_tube_brightness(100);
}


void loop()
{
  clock_display(); //Loop forever inside the function
}
