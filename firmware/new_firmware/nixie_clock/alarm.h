#ifndef __ALARM_H
#define __ALARM_H

#define ENABLE_HACK_SAVE 1

#define UNO_EEPROM_LEN 1024
#define ALARM_SETTING_MAX 4

#define EEPROM_VERIFY_ADDRESS 0
#define EEPROM_ALARM_CNT_ADDRESS 1
#define EEPROM_MP3_VOLUME_ADDRESS 2
#define EEPROM_MP3_LOOP_PLAY_ADDRESS 3
#define EEPROM_ALARM_VOLUME_ADDRESS 4
/* Hibernation */
#define EEPROM_HIBERNATE_HOUR_START_ADDRESS 5
#define EEPROM_HIBERNATE_MINUTE_START_ADDRESS 6
#define EEPROM_HIBERNATE_HOUR_END_ADDRESS 7
#define EEPROM_HIBERNATE_MINUTE_END_ADDRESS 8
#define EEPROM_HIBERNATE_ENABLED_ADDRESS 9
#define EEPROM_ALARM_START_ADDRESS 10

#define EEPROM_VERIFY_CODE 19

#define ALARM_ITEM_CNT 4
#define CHECKSUM_ARRAY_SIZE (ALARM_ITEM_CNT - 1)
                                            

typedef struct {
  int hour;
  int minute;
  int alarm_on;
  int checksum;
  
  bool alarm_cleared;
  int timeup;
  int timeup_time;
} alarm_time_t;

void eeprom_clear();

void read_alarm_setting();
void add_new_alarm_setting(int _hour, int _minute, int alarm_on);
void set_alarm_setting(int index, int _hour, int _minute, int alarm_on);
void check_alarm(rtc_time_t *current_time);
int check_alarm_timeup_state();
void clear_alarm_timeup_state();
void print_alarm_setting(int index);

int get_alarm_count();
int get_alarm_time_hour(int index);
int get_alarm_time_minute(int index);
bool get_alarm_on_state(int index);
void set_alarm_on_state(int index, int state);
void set_alarm_volume(int volume);
int get_alarm_volume();

void eeprom_save_mp3_loop_setting();
void eeprom_save_music_volume_setting(int music_volume);
void eeprom_save_display_hibernation(int hour_start, int minute_start, int hour_end,
  int minute_end, bool enabled);
  
//Hack save
void trigger_alarm_hack_save();
void trigger_mp3_hack_save();
void eeprom_hack_save();

#endif
