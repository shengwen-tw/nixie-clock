#include <Arduino.h>

#include "RTC.h"
#include "alarm.h"
#include "mp3.h"

static void parse_time_setting_command(char *command);
static void parse_add_alarm_command(char *command);
static void parse_set_alarm_command(char *command);
static void parse_print_alarm_setting(char *command);
static void parse_volume_up(char *command);
static void parse_volume_down(char *command);
static void parse_music_command(char *command);

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
    serial_read(buff, 11); //#07250001151 (hour 7, minute 25, song 0001, volume 15, alarm 1)
    parse_add_alarm_command(buff);
    
  } else if(command == '$') {
    serial_read(buff, 13); //#030725000115 (item 3, hour 7, minute 25, song 0001, volume 15, alarm 1)
    parse_set_alarm_command(buff);

  } else if(command == '&') {
    serial_read(buff, 2);
    parse_print_alarm_setting(buff);
  } else if(command == '+') {
    serial_read(buff, 2);
    parse_volume_up(buff);
    
  } else if(command == '-') {
    serial_read(buff, 2);
    parse_volume_down(buff);
    
  } else if(command == '~') {
    serial_read(buff, 6);
    parse_music_command(buff);
    
  } else {
    //my_printf("error:UNKNOWN_COMMAND\n");
    //print_time();
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
  for(int i = 0; i < 11; i++) {
    command[i] = command[i] - '0';
  }
  
  int hour = command[0] * 10 + command[1];
  int minute = command[2] * 10 + command[3];
  int song = command[4] * 1000 + command[5] * 100 + command[6] * 10 + command[7];
  int volume = command[8] * 10 + command[9];
  int alarm_on = command[10];
  
  my_printf("%d:%d -> song:%d volume:%d\n", hour, minute, song, volume);
  
  add_new_alarm_setting(hour, minute, song, volume, alarm_on);
}

static void parse_set_alarm_command(char *command)
{
  for(int i = 0; i < 13; i++) {
    command[i] = command[i] - '0';
  }
  
  int index = command[0] * 10 + command[1];
  int hour = command[2] * 10 + command[3];
  int minute = command[4] * 10 + command[5];
  int song = command[6] * 1000 + command[7] * 100 + command[8] * 10 + command[9];
  int volume = command[10] * 10 + command[11];
  int alarm_on = command[12];
  
  set_alarm_setting(index, hour, minute, song, volume, alarm_on);
}

static void parse_print_alarm_setting(char *command)
{
  for(int i = 0; i < 2; i++) {
    command[i] = command[i] - '0';
  }
  
  int index = command[0] * 10 + command[1];
  
  print_alarm_setting(index);
}

static void parse_volume_up(char *command)
{
  if(command[0] == '1' && command[1] == '9') {
      volume_inc();
  }
}

static void parse_volume_down(char *command)
{
  if(command[0] == '4' && command[1] == '4') {
      volume_dec();
  }
}

static void parse_music_command(char *command)
{
  if(strcmp(command, "random") == 0) {
    play_radom_music();
  } else if(strcmp(command, "pause-") == 0) {
    pause_music();
  } else if(strcmp(command, "resume") == 0) {
    unpause_music();
  } else if(strcmp(command, "stop--") == 0) {
    stop_music();
  }
}
