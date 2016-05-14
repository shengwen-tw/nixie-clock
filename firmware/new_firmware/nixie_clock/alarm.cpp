#include <Arduino.h>
#include <EEPROM.h>

#include "RTC.h"
#include "alarm.h"
#include "serial.h"
#include "mp3.h"

alarm_time_t alarm_time[ALARM_SETTING_MAX] = {0};
int alarm_setting_count = 0;

void eeprom_clear()
{
  for (int i = 0 ;i < UNO_EEPROM_LEN; i++) {
    EEPROM.write(i, 0);
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
    
    EEPROM.write(EEPROM_VERIFY_ADDRESS, EEPROM_VERIFY_CODE);
    
    return;
  }
  
  alarm_setting_count = EEPROM.read(EEPROM_ALARM_CNT_ADDRESS);
  
  if(alarm_setting_count > ALARM_SETTING_MAX) {
    Serial.println("error:EEPROM alarm count bigger than MAX value");
    eeprom_clear();
  }
  
  my_printf("ALARM COUNT: %d\n", alarm_setting_count);
  
  if(!alarm_setting_count) return; //If there is no alarm setting
  
  /* Read alarm setting from EEPROM */
  int address = EEPROM_ALARM_START_ADDRESS;
  int checksum_arr[CHECKSUM_ARRAY_SIZE];
  int checksum;
  
  for(int i = 0; i < alarm_setting_count; i++) {
    /* Read alarm setting from EEPROM */
    checksum_arr[0] = alarm_time[i].hour = EEPROM.read(address);
    checksum_arr[1] = alarm_time[i].minute = EEPROM.read(address + 1);
    checksum_arr[2] = alarm_time[i].song = EEPROM.read(address + 2);
    checksum = alarm_time[i].checksum = EEPROM.read(address + 3);

    /* Checksum test */
    if(checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE) != checksum) {
      
      my_printf(
        "[ALARM%d] EEPROM checksum failed! (%d and %d)\n",
        i,
        checksum,
        checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE)
      );
      
      eeprom_clear();
      
      return;
    }
    
    my_printf("[Read %d]%d:%d -> song:%d -> Checksum %d\n",
      i,
      alarm_time[i].hour,
      alarm_time[i].minute,
      alarm_time[i].song,
      alarm_time[i].checksum
    );
    
    address += ALARM_ITEM_CNT;
  }
}

void add_new_alarm_setting(int _hour, int _minute, int song)
{
  if(alarm_setting_count >= ALARM_SETTING_MAX) {
    my_printf("error:MAX_ALARM_SETTING\n");
    return;
  }
  
  int checksum_arr[CHECKSUM_ARRAY_SIZE];
  
  checksum_arr[0] = alarm_time[alarm_setting_count].hour = _hour;
  checksum_arr[1] = alarm_time[alarm_setting_count].minute = _minute;
  checksum_arr[2] = alarm_time[alarm_setting_count].song = song;
  alarm_time[alarm_setting_count].checksum = checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE);
  
  my_printf("[Save %d]%d:%d -> song:%d -> Checksum %d\n",
    alarm_setting_count,
    alarm_time[alarm_setting_count].hour,
    alarm_time[alarm_setting_count].minute,
    alarm_time[alarm_setting_count].song,
    alarm_time[alarm_setting_count].checksum
  );
  
  /* Save setting into EEPROM */
  int address = EEPROM_ALARM_START_ADDRESS + ALARM_ITEM_CNT * alarm_setting_count;
  
  EEPROM.write(address, _hour);
  EEPROM.write(address + 1, _minute);
  EEPROM.write(address + 2, song);
  EEPROM.write(address + 3, alarm_time[alarm_setting_count].checksum);
  
  alarm_setting_count++;
  
  EEPROM.write(EEPROM_ALARM_CNT_ADDRESS, alarm_setting_count);
}

void set_alarm_setting(int index, int _hour, int _minute, int song)
{
  if(index >= alarm_setting_count) {
    my_printf("error:ALARM_INDEX_ERROR\n");
    return;
  }
  
  int checksum_arr[CHECKSUM_ARRAY_SIZE];
  
  checksum_arr[0] = alarm_time[index].hour = _hour;
  checksum_arr[1] = alarm_time[index].minute = _minute;
  checksum_arr[2] = alarm_time[index].song = song;
  alarm_time[index].checksum = checksum_calc(checksum_arr, CHECKSUM_ARRAY_SIZE);
  
  /* Save setting into EEPROM */
  int address = EEPROM_ALARM_START_ADDRESS + ALARM_ITEM_CNT * index;
  
  EEPROM.write(address, _hour);
  EEPROM.write(address + 1, _minute);
  EEPROM.write(address + 2, song);
  EEPROM.write(address + 3, alarm_time[index].checksum);

  my_printf("[Modify %d]%d:%d -> song:%d -> Checksum %d\n",
    index,
    alarm_time[index].hour,
    alarm_time[index].minute,
    alarm_time[index].song,
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
    my_printf("[ALARM%d]%d:%d -> song:%d\n", index, alarm_time[index].hour, alarm_time[index].minute, alarm_time[index].song);
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
    alarm_time[i].off = 0;
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
      if(timeup(current_time->hour, current_time->minute, alarm_time[i].hour, alarm_time[i].minute) && (alarm_time[i].off == 0)) {
        Serial.println("ALARM_TIMEUP");
        alarm_time[i].timeup = 1;
        
        //TODO:Play music & blink
        play_music(alarm_time[i].song);
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
      alarm_time[i].off = 1;

      stop_music();
    }
  }
}
