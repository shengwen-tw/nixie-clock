#include <Arduino.h>
#include <DFPlayer.h>

#include "serial.h"
#include "RTC.h"
#include "alarm.h"
#include "mp3.h"

extern int music_volume;
extern DFPlayer *dfplayer;

static void parse_time_setting_command(char *command);
static void parse_add_alarm_command(char *command);
static void parse_set_alarm_command(char *command);
static void parse_set_alarm_state_command(char *command);
static void parse_print_alarm_setting(char *command);
static void parse_set_volume(char *command);
static void parse_music_command(char *command);
static void parse_eeprom_command(char *command);
static void parse_sync_command(char *command);
static void parse_alarm_time_request_command(char *command);

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
      //DEBUG_PRINTF("%d ", buff[i]);
    }
    
    //DEBUG_PRINTF("\n");
}

void serialEvent()
{
  char buff[14] = {0};
  char command = Serial.read();
  
  //Register bluetooth command and its handle at here
  REGISTER_NEW_CMD_START('@', 14, parse_time_setting_command);
  REGISTER_NEW_CMD('#', 5, parse_add_alarm_command);
  REGISTER_NEW_CMD('$', 7, parse_set_alarm_command); //$0307251 (item 3, hour 7, minute 25, alarm 1)
  REGISTER_NEW_CMD('+', 2, parse_set_alarm_state_command);
  REGISTER_NEW_CMD('&', 2, parse_print_alarm_setting);
  REGISTER_NEW_CMD('{', 2, parse_set_volume);
  REGISTER_NEW_CMD('~', 6, parse_music_command);
  REGISTER_NEW_CMD(';', 5, parse_eeprom_command);
  REGISTER_NEW_CMD('!', 11, parse_sync_command);
  REGISTER_NEW_CMD('*', 3, parse_alarm_time_request_command);
  //REGISTER_EXCEPTION(print_error_message); //"error:UNKNOWN_COMMAND\n time: hh:mm:ss"
  REGISTER_NEW_CMD_END();
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
  int alarm_on = command[4];
  
  my_printf("[ADD_ALARM]%d:%d\n", hour, minute);
  
  add_new_alarm_setting(hour, minute, alarm_on);
}

static void parse_set_alarm_command(char *command)
{
  for(int i = 0; i < 13; i++) {
    command[i] = command[i] - '0';
  }
  
  int index = command[0] * 10 + command[1];
  int hour = command[2] * 10 + command[3];
  int minute = command[4] * 10 + command[5];
  int alarm_on = command[6];

  my_printf("[EDIT_ALARM]%d:%d\n", hour, minute);
  
  set_alarm_setting(index, hour, minute, alarm_on);
}

static void parse_print_alarm_setting(char *command)
{
  for(int i = 0; i < 2; i++) {
    command[i] = command[i] - '0';
  }
  
  int index = command[0] * 10 + command[1];
  
  print_alarm_setting(index);
}

static void parse_set_volume(char *command)
{
  for(int i = 0; i < 2; i++) {
    command[i] = command[i] - '0';
  }
  
  int volume = command[0] * 10 + command[1];

  dfplayer->set_volume(volume);
}

static void parse_music_command(char *command)
{
  if(strcmp(command, "random") == 0) {
    play_radom_music(music_volume);
  } else if(strcmp(command, "pause-") == 0) {
    pause_music();
  } else if(strcmp(command, "resume") == 0) {
    unpause_music();
  } else if(strcmp(command, "stop--") == 0) {
    stop_music();
  } else if(strcmp(command, "next--") == 0) {
    next_music();    
  } else if(strcmp(command, "last--") == 0) {
    previous_music();
  } else if(strcmp(command, "loop-o") == 0) {
    set_mp3_loop_play_state(true);
  } else if(strcmp(command, "loop-x") == 0) {
    set_mp3_loop_play_state(false);
  }
}

static void parse_eeprom_command(char *command)
{
  if(strcmp(command, "clear") == 0) {
    eeprom_clear();
  }
}

static void parse_sync_command(char *command)
{
  if(strcmp(command, "mp3-volume-") == 0) {
    Serial.print(get_mp3_volume());
    
  } else if(strcmp(command, "music-loop-") == 0) {
    get_mp3_loop_play_state() ? Serial.print(1) : Serial.print(0);
  } else if(strcmp(command, "clock-sound") == 0) {
    
  } else if(strcmp(command, "clock-count") == 0) {
    Serial.print(get_alarm_count());
    
  }
}

static void parse_alarm_time_request_command(char *command)
{
  int index = command[2] - '0';
  int digit[2];
    
  if(command[0] == '1' && command[1] == '9') {
    digit[0] = get_alarm_time_hour(index) / 10;
    digit[1] = get_alarm_time_hour(index) % 10;
    Serial.print(digit[0]);
    Serial.print(digit[1]);
  } else if(command[0] == '4' && command[1] == '4') {
    digit[0] = get_alarm_time_minute(index) / 10;
    digit[1] = get_alarm_time_minute(index) % 10;
    Serial.print(digit[0]);
    Serial.print(digit[1]);
  } else if(command[0] == '1' && command[1] == '7') {
    get_alarm_on_state(index) ? Serial.print(1) : Serial.print(0);
  }
}

static void parse_set_alarm_state_command(char *command)
{
  int index = command[0] - '0';
  int state = command[1] - '0';

  set_alarm_on_state(index, state);
}

