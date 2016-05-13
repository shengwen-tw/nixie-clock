#include <Arduino.h>
#include <EEPROM.h>

#include "alarm.h"
#include "serial.h"

alarm_time_t alarm_time[ALARM_SETTING_MAX];
int alarm_setting_count = 0;

void eeprom_clear()
{
  for (int i = 0 ;i < UNO_EEPROM_LEN; i++) {
    EEPROM.write(i, 0);
  }
}

int checksum_calc(int *array, int arr_size)
{
  int result = alarm_setting_count;
  
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
  }
  
  alarm_setting_count = EEPROM.read(EEPROM_ALARM_CNT_ADDRESS);
  
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
      my_printf("EEPROM checksum failed!\n");
      eeprom_clear();
      return;
    }
    
    my_printf("[ALARM%d]%d:%d\n", alarm_time[i].hour, alarm_time[i].minute);
    
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
  
  /* Save setting into EEPROM */
  int address = EEPROM_ALARM_START_ADDRESS + 2 * alarm_setting_count;
  
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
  int address = EEPROM_ALARM_START_ADDRESS + 2 * index;
  
  EEPROM.write(address, _hour);
  EEPROM.write(address + 1, _minute);
  EEPROM.write(address + 2, song);
  EEPROM.write(address + 3, alarm_time[index].checksum);
}
