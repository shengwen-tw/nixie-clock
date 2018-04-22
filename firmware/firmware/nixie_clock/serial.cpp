#include <Arduino.h>
#include <DFPlayer_AltSerial.h>

#include "serial.h"
#include "RTC.h"
#include "alarm.h"
#include "mp3.h"
#include "clock.h"

extern int music_volume;
extern DFPlayer *dfplayer;

static void parse_time_setting_command(char *command);
static void parse_add_alarm_command(char *command);
static void parse_set_alarm_command(char *command);
static void parse_set_alarm_state_command(char *command);
static void parse_print_alarm_setting(char *command);
static void parse_set_mp3_volume(char *command);
static void parse_set_alarm_volume(char *command);
static void parse_music_command(char *command);
static void parse_eeprom_command(char *command);
static void parse_sync_command(char *command);
static void parse_alarm_time_request_command(char *command);
static void parse_set_hibernation_time_command(char *command);
static void parse_set_hibernation_state_command(char *command);
static void parse_test_alarm_volume_command(char *command);

void my_printf(const char *fmt, ...)
{
    char tmp[128]; // resulting string limited to 128 chars
    va_list args;
    va_start (args, fmt );
    vsnprintf(tmp, 128, fmt, args);
    va_end (args);
    Serial.print(tmp);
}

int serial_read(char *buff, int count)
{
    for(int i = 0; i < count; i++) {
      unsigned long timeout = millis();
      while(Serial.available() == 0) {
        if((millis() - timeout) >= 100) {
          DEBUG_PRINTF("USART Timeout!\n");
          return 1;
        }
      }
      
      buff[i] = Serial.read();
      //DEBUG_PRINTF("%c", buff[i]);  
    }
    //DEBUG_PRINTF("\n");
    
    return 0;
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
  REGISTER_NEW_CMD('{', 2, parse_set_mp3_volume);
  REGISTER_NEW_CMD('}', 2, parse_set_alarm_volume);
  REGISTER_NEW_CMD('~', 6, parse_music_command);
  REGISTER_NEW_CMD(';', 5, parse_eeprom_command);
  REGISTER_NEW_CMD('!', 11, parse_sync_command);
  REGISTER_NEW_CMD('*', 3, parse_alarm_time_request_command);
  REGISTER_NEW_CMD('%', 9, parse_set_hibernation_time_command);
  REGISTER_NEW_CMD('^', 1, parse_set_hibernation_state_command);
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

#if ENABLE_TIME_TESTING == 0
  RTC_set_time(year, month, day, hour, minute, second);
#endif
}

static void parse_add_alarm_command(char *command)
{
  for(int i = 0; i < 11; i++) {
    command[i] = command[i] - '0';
  }
  
  int hour = command[0] * 10 + command[1];
  int minute = command[2] * 10 + command[3];
  int alarm_on = command[4];
  
  DEBUG_PRINTF("[ADD_ALARM]%d:%d\n", hour, minute);
  
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

  DEBUG_PRINTF("[EDIT_ALARM]%d:%d\n", hour, minute);

#if ENABLE_TIME_TESTING == 0
  set_alarm_setting(index, hour, minute, alarm_on);
#endif
}

static void parse_print_alarm_setting(char *command)
{
  for(int i = 0; i < 2; i++) {
    command[i] = command[i] - '0';
  }
  
  int index = command[0] * 10 + command[1];
  
  print_alarm_setting(index);
}

static void parse_set_mp3_volume(char *command)
{
  for(int i = 0; i < 2; i++) {
    command[i] = command[i] - '0';
  }
  
  int mp3_volume = command[0] * 10 + command[1];

  set_music_volume(mp3_volume);

  //XXX:Hack save
  trigger_mp3_hack_save();
}

static void parse_set_alarm_volume(char *command)
{  
  for(int i = 0; i < 2; i++) {
    command[i] = command[i] - '0';
  }
  
  int alarm_volume = command[0] * 10 + command[1];

  set_alarm_volume(alarm_volume);

  //XXX:Hack save
  trigger_alarm_hack_save();
}

static void parse_music_command(char *command)
{
  if(strcmp(command, "loop-o") == 0) {
    set_mp3_loop_play_state(true);
    return;
  } else if(strcmp(command, "loop-x") == 0) {
    set_mp3_loop_play_state(false);
    return;
  }

  if(check_alarm_timeup_state()) {
    Serial.print(1);
    return;
  }
  
  /* These commands have no effect while alarming */
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
  } else if(strcmp(command, "al-try") == 0) {
    play_radom_music(get_alarm_volume());
  }

  Serial.print(0);
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
    int mp3_volume = get_mp3_volume();
    Serial.print(mp3_volume / 10);
    Serial.print(mp3_volume % 10);
    
  } else if(strcmp(command, "music-loop-") == 0) {
    get_mp3_loop_play_state() ? Serial.print(1) : Serial.print(0);
  } else if(strcmp(command, "alarm-volum") == 0) {
    Serial.print(get_alarm_volume() / 10);
    Serial.print(get_alarm_volume() % 10);
    
  } else if(strcmp(command, "clock-count") == 0) {
    Serial.print(get_alarm_count());
    
  } else if(strcmp(command, "hibernate--") == 0) {
    send_hibernate_command();
    
  } else if(strcmp(command, "hib-enabled") == 0) {
    get_display_hibernation_state() ? Serial.print(1) : Serial.print(0);
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
  DEBUG_PRINTF("[Set alarm %d state]%d\n", index, state);
}

static void parse_set_hibernation_time_command(char *command)
{
  for(int i = 0; i < 9; i++) {
    command[i] = command[i] - '0';
  }

  int hour_start = command[0] * 10 + command[1];
  int minute_start = command[2] * 10 + command[3];
  int hour_end = command[4] * 10 + command[5];
  int minute_end = command[6] * 10 + command[7];

  int enabled = command[8];

  set_display_hibernation(hour_start, minute_start, hour_end, minute_end, enabled == 0 ? false : true);
}

static void parse_set_hibernation_state_command(char *command)
{
  int state = command[0] - '0';

  set_display_hibernation_state(state);
  DEBUG_PRINTF("[Set hibernation %d state]%d\n", state);
}

