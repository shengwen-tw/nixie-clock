#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "RTC.h"

void RTC_init()
{
  while(!Serial);
  setSyncProvider(RTC.get);
}

void RTC_set_time(int year, int month, int day, int hour, int minute, int second)
{
  tmElements_t tm;
  tm.Year = year - 1970;
  tm.Month = month;
  tm.Day = day;
  tm.Hour = hour;
  tm.Minute = minute;
  tm.Second = second;
  
  RTC.write(tm);
  setSyncProvider(RTC.get);
}

void RTC_read_time(rtc_time_t *time)
{
    time->year = year();
    time->month = month();
    time->day = day();
    time->hour = hour();
    time->minute = minute();
    time->second = second();
}

void print_time()
{
  Serial.print(year());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print("\n");
}
