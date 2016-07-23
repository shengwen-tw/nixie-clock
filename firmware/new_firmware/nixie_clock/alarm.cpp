#include <Arduino.h>
#include <EEPROM.h>

#include "RTC.h"
#include "alarm.h"
#include "serial.h"
#include "mp3.h"

alarm_time_t alarm_time[ALARM_SETTING_MAX] = {0};
int alarm_setting_count = 0;
int alarm_music_volume = 20;

/* Hacking for AI2 */
bool prepare_alarm_hack_save = false;
bool prepare_mp3_hack_save = false;
unsigned long previous_time_alarm_volume;
unsigned long previous_time_mp3_volume;

void eeprom_clear()
{
  for (int i = 0 ;i < UNO_EEPROM_LEN; i++) {
    EEPROM.write(i, 0);
  }

  //Reset parameters
  EEPROM.write(EEPROM_MP3_VOLUME_ADDRESS, 20);
  EEPROM.write(EEPROM_ALARM_CNT_ADDRESS , ALARM_ITEM_CNT);
  EEPROM.write(EEPROM_ALARM_VOLUME_ADDRESS, 25);
  EEPROM.write(EEPROM_VERIFY_ADDRESS, EEPROM_VERIFY_CODE);

  for(int i = 0; i < ALARM_ITEM_CNT; i++) {
    int address = EEPROM_ALARM_START_ADDRESS + ALARM_ITEM_CNT * i;
  
    EEPROM.write(address, 0); //hour
    EEPROM.write(address + 1, 0); //minute
    EEPROM.write(address + 2, 0); //alarm on state
    EEPROM.write(address + 3, EEPROM_VERIFY_CODE); //checksum
  }
}

int checksum_calc(int *array, int arr_size)
{
  int result = EEPROM_VERIFY_CODE;
  
  for(int i = 0; i < arr_size; i++) {
    result ^= array[i];
  }
  
  return result;
}

void read_alarm_setting()
{
  int eeprom_verify = EEPROM.read(EEPROM_VERIFY_ADDRESS);
  
  if(eeprom_verify != EEPROM_VERIFY_CODE) {
    eeprom_clear();
    
    return;
  }
  
  alarm_setting_count = EEPROM.read(EEPROM_ALARM_CNT_ADDRESS);
  
  if(alarm_setting_count > ALARM_SETTING_MAX) {
    Serial.println("error:EEPROM alarm count bigger than MAX value");
    alarm_setting_count = 0;
    eeprom_clear();

    return;
  }

  //Set music volume
  int music_volume = EEPROM.read(EEPROM_MP3_VOLUME_ADDRESS);
  load_music_volume_from_eeprom(music_volume);

  //Set mp3 loop state
  bool mp3_loop = EEPROM.read(EEPROM_MP3_LOOP_PLAY_ADDRESS);
  set_mp3_loop_play_state(mp3_loop);

  //Set alarm volume
  alarm_music_volume = EEPROM.read(EEPROM_ALARM_VOLUME_ADDRESS);

  DEBUG_PRINTF("ALARM COUNT: %d\n", alarm_setting_count);
  DEBUG_PRINTF("ALARM VOLUME: %d\n", alarm_music_volume);
  DEBUG_PRINTF("MUSIC VOLUME: %d\n", music_volume);
  
  if(!alarm_setting_count) return; //If there is no alarm setting
  
  /* Read alarm setting from EEPROM */
  int address = EEPROM_ALARM_START_ADDRESS;
  int checksum_arr[CHECKSUM_ARRAY_SIZE];
  int checksum;
  
  for(int i = 0; i < alarm_setting_count; i++) {
    /* Read alarm setting from EEPROM */
    checksum_arr[0] = alarm_time[i].hour = EEPROM.read(address);
    checksum_arr[1] = alarm_time[i].minute = EEPROM.read(address + 1);
    checksum_arr[2] = alarm_time[i].alarm_on = EEPROM.read(address + 2);
    checksum = alarm_time[i].checksum = EEPROM.read(address + 3);

    /* Checksum test */
    if(checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE) != checksum) {
      
      DEBUG_PRINTF(
        "[ALARM%d] EEPROM checksum failed! (%d and %d)\n",
        i,
        checksum,
        checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE)
      );
      
      eeprom_clear();
      
      return;
    }
    
    DEBUG_PRINTF("[Read %d]%d:%d alarm_on:%d Checksum %d\n",
      i,
      alarm_time[i].hour,
      alarm_time[i].minute,
      alarm_time[i].alarm_on,
      alarm_time[i].checksum
    );
    
    address += ALARM_ITEM_CNT;
  }
}

void add_new_alarm_setting(int _hour, int _minute, int alarm_on)
{
  if(alarm_setting_count >= ALARM_SETTING_MAX) {
    DEBUG_PRINTF("error:MAX_ALARM_SETTING\n");
    return;
  }
  
  int checksum_arr[CHECKSUM_ARRAY_SIZE];
  
  checksum_arr[0] = alarm_time[alarm_setting_count].hour = _hour;
  checksum_arr[1] = alarm_time[alarm_setting_count].minute = _minute;
  checksum_arr[2] = alarm_time[alarm_setting_count].alarm_on = alarm_on;
  alarm_time[alarm_setting_count].checksum = checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE);
  
  DEBUG_PRINTF("[Save %d]%d:%d alarm_on:%d Checksum %d\n",
    alarm_setting_count,
    alarm_time[alarm_setting_count].hour,
    alarm_time[alarm_setting_count].minute,
    alarm_time[alarm_setting_count].alarm_on,
    alarm_time[alarm_setting_count].checksum
  );
  
  /* Save setting into EEPROM */
  int address = EEPROM_ALARM_START_ADDRESS + ALARM_ITEM_CNT * alarm_setting_count;
  
  EEPROM.write(address, _hour);
  EEPROM.write(address + 1, _minute);
  EEPROM.write(address + 2, alarm_on);
  EEPROM.write(address + 3, alarm_time[alarm_setting_count].checksum);
  
  alarm_setting_count++;
  
  EEPROM.write(EEPROM_ALARM_CNT_ADDRESS, alarm_setting_count);
}

void set_alarm_setting(int index, int _hour, int _minute, int alarm_on)
{
  if(index >= alarm_setting_count) {
    DEBUG_PRINTF("error:ALARM_INDEX_ERROR\n");
    return;
  }
  
  int checksum_arr[CHECKSUM_ARRAY_SIZE];

  alarm_time[index].alarm_cleared = false;
  
  checksum_arr[0] = alarm_time[index].hour = _hour;
  checksum_arr[1] = alarm_time[index].minute = _minute;
  checksum_arr[2] = alarm_time[index].alarm_on = alarm_on;
  alarm_time[index].checksum = checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE);
  
  /* Save setting into EEPROM */
  int address = EEPROM_ALARM_START_ADDRESS + ALARM_ITEM_CNT * index;
  
  EEPROM.write(address, _hour);
  EEPROM.write(address + 1, _minute);
  EEPROM.write(address + 2, alarm_on);
  EEPROM.write(address + 3, alarm_time[index].checksum);

  DEBUG_PRINTF("[Modify %d]%d:%d alarm_on:%d Checksum %d\n",
    index,
    alarm_time[index].hour,
    alarm_time[index].minute,
    alarm_time[index].alarm_on,
    alarm_time[index].checksum
  );
}

void clear_alarm_setting()
{
  EEPROM.write(EEPROM_ALARM_CNT_ADDRESS, 0);
  alarm_setting_count = 0;
}

void print_alarm_setting(int index)
{
  if(index < alarm_setting_count) {
    DEBUG_PRINTF("[ALARM%d]%d:%d alarm_on:%d\n",
      index,
      alarm_time[index].hour,
      alarm_time[index].minute,
      alarm_time[index].alarm_on
    );
  } else {
    Serial.println("error:ALARM_NOT_SET");
  }
}

int timeup(int hour_now, int minute_now, int hour_alarm, int minute_alarm)
{
  if((hour_now == hour_alarm) && (minute_now == minute_alarm)) {
    return 1;
  }
  
  return 0;
}

static void turn_on_alarm()
{
  for(int i = 0; i < alarm_setting_count; i++) {
    alarm_time[i].alarm_cleared = false;
  }
}

void check_alarm(rtc_time_t *current_time)
{
  /* New day comes */
  if(timeup(current_time->hour, current_time->minute, 0, 0)) {
    turn_on_alarm();
  }
  
  for(int i = 0; i < alarm_setting_count; i++) {
    if(alarm_time[i].timeup == 1) {
      
    } else {
      if(timeup(current_time->hour, current_time->minute, alarm_time[i].hour, alarm_time[i].minute) && 
        (alarm_time[i].alarm_cleared == 0))
      {
        Serial.println("ALARM_TIMEUP");
        alarm_time[i].timeup = 1;
        
        //TODO:Play music & blink
        play_radom_music(alarm_music_volume);
      }
    }
  }
}

int check_alarm_timeup_state()
{
  for(int i = 0; i < alarm_setting_count; i++) {
    if(alarm_time[i].timeup == 1) {
      return 1;
    }
  }
  
  return 0;
}

void clear_alarm_timeup_state()
{
  for(int i = 0; i < alarm_setting_count; i++) {
    if(alarm_time[i].timeup == 1) {
      alarm_time[i].timeup = 0;
      alarm_time[i].alarm_cleared = true;

      stop_music();
    }
  }
}

int get_alarm_count()
{
  return alarm_setting_count;
}

int get_alarm_time_hour(int index)
{
  return alarm_time[index].hour;
}

int get_alarm_time_minute(int index)
{
  return alarm_time[index].minute;
}

bool get_alarm_on_state(int index)
{
  return alarm_time[index].alarm_on ? true : false;
}

void set_alarm_on_state(int index, int state)
{
  int address = EEPROM_ALARM_START_ADDRESS + ALARM_ITEM_CNT * index;
  int checksum_arr[CHECKSUM_ARRAY_SIZE];

  /* Calculate checksum and change the alarm state*/
  checksum_arr[0] = alarm_time[index].hour;
  checksum_arr[1] = alarm_time[index].minute;
  checksum_arr[2] = alarm_time[index].alarm_on = state;
  alarm_time[index].checksum = checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE);

  /* Save alarm state and checksum into EEPROM */
  EEPROM.write(address + 2, state);
  EEPROM.write(address + 3, alarm_time[index].checksum);
}


/************************
 * EEPROM Save Function *
 ************************/
void eeprom_save_alarm_volume_setting(int alarm_volume)
{
  DEBUG_PRINTF("[Save alarm volume]%d\n", alarm_volume);
  EEPROM.write(EEPROM_ALARM_VOLUME_ADDRESS, alarm_volume);
}

void eeprom_save_music_volume_setting(int music_volume)
{
  DEBUG_PRINTF("[Save mp3 volume]%d\n", music_volume);
  EEPROM.write(EEPROM_MP3_VOLUME_ADDRESS, music_volume);
}

void eeprom_save_mp3_loop_setting()
{
  EEPROM.write(EEPROM_MP3_LOOP_PLAY_ADDRESS, get_mp3_loop_play_state()); 
}

/************************
 * AI2 EEPROM Hack Save *
 ************************/
void trigger_alarm_hack_save()
{
  prepare_alarm_hack_save = true;
  previous_time_alarm_volume = millis();
}

void trigger_mp3_hack_save()
{
  prepare_mp3_hack_save = true;
  previous_time_mp3_volume = millis();
}

void eeprom_hack_save()
{
    /* Wait 1 second until AI2 slider lost focus */
    if(prepare_alarm_hack_save == true && (millis() - previous_time_alarm_volume) > 1000) {
        DEBUG_PRINTF("[EEPROM HACK SAVE]Alarm volume: %d\n", alarm_music_volume);
        eeprom_save_alarm_volume_setting(alarm_music_volume);
        prepare_alarm_hack_save = false;
    }
    
    if(prepare_mp3_hack_save == true && (millis() - previous_time_mp3_volume) > 1000) {
      DEBUG_PRINTF("[EEPROM HACK SAVE]MP3 volume: %d\n", get_mp3_volume());
      eeprom_save_music_volume_setting(get_mp3_volume());
      prepare_mp3_hack_save = false;
    }
}

