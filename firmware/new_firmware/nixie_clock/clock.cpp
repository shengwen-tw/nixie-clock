#include <Arduino.h>

#include "pindef.h" 
#include "tube_control.h"
#include "RTC.h"
#include "clock.h"
#include "mp3.h"
#include "serial.h"
#include "alarm.h"

int tube[8]; //This array records the data of all tubes
int tube_index = 0;

int clock_mode = TIME_MODE;
hibernate_setting_t hibernate_setting;
bool enable_hibernate = false;

void enable_timer2()
{
  TCCR2B = 0x00;        //Disbale Timer2 while we set it up
  TIFR2  = 0x00;        //Timer2 INT Flag Reg: Clear Timer Overflow Flag
  TIMSK2 = 0x01;        //Timer2 INT Reg: Timer2 Overflow Interrupt Enable
  TCCR2A = 0x00;        //Timer2 Control Reg A: Wave Gen Mode normal
  TCCR2B = 0x05;
}

ISR(TIMER2_OVF_vect)
{ 
  noInterrupts(); 

  clock_display();

  interrupts();
}

void display_time_mode()
{
  tube_control(tube_index, tube[tube_index]);

  /* Light the right dot of tube 2 and 5 */
  if(tube_index != 2 && tube_index != 5) { 
    digitalWrite(pin_font_right_dot, LOW);
  } else if(tube_index == 2 || tube_index == 5) { 
    digitalWrite(pin_font_right_dot, HIGH);
    //delayMicroseconds(500);
  }

  tube_index++;
  tube_index %= 8;
}

void display_date_mode()
{
  tube_control(tube_index, tube[tube_index]);

  /* Light the right dot of tube 2 and 4 */
  if(tube_index == 2 || tube_index == 4) {
    digitalWrite(pin_font_right_dot, HIGH);
  } else {
    digitalWrite(pin_font_right_dot, LOW);
  }

  tube_index++;
  tube_index %= 8;
}

void clock_display()
{
    if(enable_hibernate == true) {
      tube_hibernate();
      return;
    }
  
    if(clock_mode == TIME_MODE) {
      display_time_mode();
    } else if(clock_mode == DATE_MODE) {
      display_date_mode();
    }
}

void load_display_hibernation_from_eeprom(int hour_start, int minute_start, int hour_end,
  int minute_end, bool enabled)
{
  DEBUG_PRINTF("[Load clock display hibernation]%d:%d ~ %d:%d enabled:%s\n",
    hour_start,
    minute_start,
    hour_end,
    minute_end,
    enabled ? "on" : "off"
  );
  
  hibernate_setting.hour_start = hour_start;
  hibernate_setting.minute_start = minute_start;
  hibernate_setting.hour_end = hour_end;
  hibernate_setting.minute_end = minute_end;
  hibernate_setting.enabled = enabled;
}

void set_display_hibernation(int hour_start, int minute_start, int hour_end, int minute_end, bool enabled)
{
  DEBUG_PRINTF("[Set clock display hibernation]%d:%d ~ %d:%d enabled:%s\n",
    hour_start,
    minute_start,
    hour_end,
    minute_end,
    enabled ? "on" : "off"
  );

  hibernate_setting.hour_start = hour_start;
  hibernate_setting.minute_start = minute_start;
  hibernate_setting.hour_end = hour_end;
  hibernate_setting.minute_end = minute_end;
  hibernate_setting.enabled = enabled;

  eeprom_save_display_hibernation(hour_start, minute_start, hour_end, minute_end, enabled);
}

void send_hibernate_command()
{
 Serial.print(hibernate_setting.hour_start / 10);
 Serial.print(hibernate_setting.hour_start % 10);
 Serial.print(hibernate_setting.minute_start / 10);
 Serial.print(hibernate_setting.minute_start % 10);
 Serial.print(hibernate_setting.hour_end / 10);
 Serial.print(hibernate_setting.hour_end % 10);
 Serial.print(hibernate_setting.minute_end / 10);
 Serial.print(hibernate_setting.minute_end % 10);
 Serial.print(hibernate_setting.enabled ? 1 : 0); 
}

