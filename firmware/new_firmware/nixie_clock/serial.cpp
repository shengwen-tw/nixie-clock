#include <Arduino.h>

#include "RTC.h"

static void parse_time_setting_command(char *command);

void serialEvent()
{
  char buff[14] = {0};
  
  //Wait for start byte
  if(Serial.read() == '@') {
    int i;
    for(i = 0; i < 14; i++) {
      while(Serial.available() == 0);
      buff[i] = Serial.read();
      Serial.print(buff[i]);
    }
    
    parse_time_setting_command(buff);
  }
}

static void parse_time_setting_command(char *command)
{
  int i;
  for(i = 0; i < 14; i++)
    command[i] = command[i] - '0';
  
  int year = command[0] * 1000 + command[1] * 100 + command[2] * 10 + command[3];
  int month = command[4] * 10 + command[5];
  int day = command[6] * 10 + command[7];
  int hour = command[8] * 10 + command[9];
  int minute = command[10] * 10 + command[11];
  int second = command[12] * 10 + command[13];
  
  RTC_set_time(year, month, day, hour, minute, second);
}
