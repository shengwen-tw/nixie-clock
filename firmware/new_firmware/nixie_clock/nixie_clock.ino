#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

#include "pindef.h" 
#include "tube_control.h"
#include "RTC.h"
#include "clock.h"
#include "button.h"
#include "alarm.h"
#include "mp3.h"

SoftwareSerial mp3_serial(mp3_rx, mp3_tx);
rtc_time_t time; //DS1307 time data

void play_music(int index)
{
  mp3_play(index);
}

void setup()
{
  Serial.begin(9600);
  mp3_serial.begin(9600);
  mp3_set_serial(mp3_serial);

  read_alarm_setting();

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
}


void loop()
{ 
  RTC_read_time(&time);
  
  clock_display(&time);
  
  check_alarm(&time);
  
  button_status_check();
}
