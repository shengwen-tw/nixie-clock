#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

void RTC_init()
{
  while(!Serial);
  setSyncProvider(RTC.get);
}

void RTC_set_time(int year, int month, int day, int hour, int minute, int second)
{
  setTime(hour, minute, second, day, month, year);
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
