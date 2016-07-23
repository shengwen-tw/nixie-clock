#ifndef __ALARM_H
#define __ALARM_H

#define UNO_EEPROM_LEN 1024
#define ALARM_SETTING_MAX 4

#define EEPROM_VERIFY_ADDRESS 0
#define EEPROM_ALARM_CNT_ADDRESS 1
#define EEPROM_MP3_VOLUME_ADDRESS 2
#define EEPROM_ALARM_VOLUME_ADDRESS 3
#define EEPROM_ALARM_START_ADDRESS 4

#define EEPROM_VERIFY_CODE 19

#define ALARM_ITEM_CNT 4
#define CHECKSUM_ARRAY_SIZE (ALARM_ITEM_CNT - 1)

typedef struct {
  int hour;
  int minute;
  int alarm_on;
  int checksum;
  
  int notify_times;
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
void save_music_volume_setting(int music_volume);

int get_alarm_count();
int get_alarm_time_hour(int index);
int get_alarm_time_minute(int index);
bool get_alarm_on_state(int index);
void set_alarm_on_state(int index, int state);

#endif
