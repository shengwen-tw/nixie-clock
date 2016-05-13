#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>
#include <EEPROM.h>

#include "pindef.h" 
#include "tube_control.h"
#include "RTC.h"
#include "clock.h"
#include "button.h"
#include "alarm.h"

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
  
  pinMode(pin_search_button, INPUT);
  pinMode(pin_adjust_button, INPUT);
  pinMode(pin_mode_button, INPUT);
  
  RTC_init();
  
  read_alarm_setting();
}


void loop()
{ 
  clock_display();
  
  button_status_check();
}
