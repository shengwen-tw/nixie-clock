#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

void serialEvent()
{
  int t = Serial.read();
  int v = 0;
  int temp;
  while((temp = Serial.read()) != -1){
    v = v * 10 + (temp - '0');
  }
  
  int y = year();
  int M = month();
  int d = day();
  int h = hour();
  int m = minute();
  int s = second();
  
  switch(t){
    case 'y':
      y = v;
      break;
    case 'M':
      M = v;
      break;
    case 'd':
      d = v;
      break;
    case 'h':
      h = v;
      break;
    case 'm':
      m = v;
      break;
    case 's':
      s = v;
      break;
    default:
      break;
  }
  
  tmElements_t tm;
  tm.Year = y - 1970; // 從1970年開始算
  tm.Month = M;
  tm.Day = d;
  tm.Hour = h;
  tm.Minute = m;
  tm.Second = s;
  setTime(makeTime(tm));
}
