#include <Arduino.h>

#include "RTC.h"
#include "alarm.h"

static void parse_time_setting_command(char *command);
static void parse_add_alarm_command(char *command);
static void parse_set_alarm_command(char *command);
static void parse_print_alarm_setting(char *command);

void my_printf(const char *fmt, ...)
{
    char tmp[128]; // resulting string limited to 128 chars
    va_list args;
    va_start (args, fmt );
    vsnprintf(tmp, 128, fmt, args);
    va_end (args);
    Serial.print(tmp);
}

void serial_read(char *buff, int count)
{
    for(int i = 0; i < count; i++) {
      while(Serial.available() == 0);
      buff[i] = Serial.read();
      Serial.print(buff[i]);
    }
    
    Serial.println("");
}

void serialEvent()
{
  char buff[14] = {0};
  
  char command = Serial.read();
  
  //Wait for start byte
  if(command == '@') {
    serial_read(buff, 14); //@20160512112800
    parse_time_setting_command(buff);
  
  } else if(command == '#') {
    serial_read(buff, 8); //#07250001 (hour 7, minute 25, song 0001)
    parse_add_alarm_command(buff);
    
  } else if(command == '$') {
    serial_read(buff, 10); //#0307250001 (item 3, hour 7, minute 25, song 0001)
    parse_set_alarm_command(buff);

  } else if(command == '&') {
    serial_read(buff, 2);
    parse_print_alarm_setting(buff);

  } else {
    my_printf("error:UNKNOWN_COMMAND\n");
    print_time();
  }
}

static void parse_time_setting_command(char *command)
{
  for(int i = 0; i < 14; i++) {
    command[i] = command[i] - '0';
  }
  
  int year = command[0] * 1000 + command[1] * 100 + command[2] * 10 + command[3];
  int month = command[4] * 10 + command[5];
  int day = command[6] * 10 + command[7];
  int hour = command[8] * 10 + command[9];
  int minute = command[10] * 10 + command[11];
  int second = command[12] * 10 + command[13];
  
  RTC_set_time(year, month, day, hour, minute, second);
}

static void parse_add_alarm_command(char *command)
{
  for(int i = 0; i < 8; i++) {
    command[i] = command[i] - '0';
  }
  
  int hour = command[0] * 10 + command[1];
  int minute = command[2] * 10 + command[3];
  int song = command[4] * 1000 + command[5] * 100 + command[6] * 10 + command[7];
  
  my_printf("%d:%d -> %d\n", hour, minute, song);
  
  add_new_alarm_setting(hour, minute, song);
}

static void parse_set_alarm_command(char *command)
{
  for(int i = 0; i < 10; i++) {
    command[i] = command[i] - '0';
  }
  
  int index = command[0] * 10 + command[1];
  int hour = command[2] * 10 + command[3];
  int minute = command[4] * 10 + command[5];
  int song = command[6] * 1000 + command[7] * 100 + command[8] * 10 + command[9];
  
  set_alarm_setting(index, hour, minute, song);
}

static void parse_print_alarm_setting(char *command)
{
  for(int i = 0; i < 2; i++) {
    command[i] = command[i] - '0';
  }
  
  int index = command[0] * 10 + command[1];
  
  print_alarm_setting(index);
}
