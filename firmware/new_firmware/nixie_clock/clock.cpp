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

//Hibernation
hibernate_setting_t hibernate_setting;
bool enable_hibernate = false;

//Display blinking
bool blink_display = false;
bool blink_trigger = false;
unsigned long blink_timer = 0;

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

void turn_on_blink_display()
{
  blink_display = true;
}

void turn_off_blink_display()
{
  blink_display = false;
}

void display_time_mode()
{
  tube_control(tube_index, tube[tube_index]);

  /* Light the right dot of tube 2 and 5 */
  if(tube_index != TUBE_2 && tube_index != TUBE_5) { 
    digitalWrite(pin_font_right_dot, LOW);
  } else if(tube_index == TUBE_2 || tube_index == TUBE_5) { 
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
  if(tube_index == TUBE_2 || tube_index == TUBE_4) {
    digitalWrite(pin_font_right_dot, HIGH);
  } else {
    digitalWrite(pin_font_right_dot, LOW);
  }

  tube_index++;
  tube_index %= 8;
}

/* Return true if need to turn off the light */
bool do_blink_display(unsigned long on_time, unsigned long off_time)
{
  if(blink_display == false) {
    return false;
  }
  
  unsigned long current = millis();
  
  if(blink_trigger == false) {
    
    /* Time check */
    if(current - blink_timer > off_time) {
      blink_trigger = true;
      blink_timer = current;
    }
      
    return true;
    
  } else {
    
    /* Time check */
    if(current - blink_timer > on_time) {
      blink_trigger = false;
      blink_timer = current;
    }
    
    return false;
  }
}

void clock_display()
{
    //Blink display is much important then hibernation (alarm)
    if((enable_hibernate && blink_display == false) || do_blink_display(1500, 1000)) {
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

void set_display_hibernation_state(bool state)
{
  hibernate_setting.enabled = state;
  eeprom_save_display_hibernation_state(state);
}

bool get_display_hibernation_state()
{
  return hibernate_setting.enabled;
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

static bool in_time_range(int now_hour, int now_minute, int start_hour,
  int start_minute, int end_hour, int end_minute)
{
  int start_time = start_hour * 60 + start_minute;
  int end_time = end_hour * 60 + end_minute;
  int now_time = now_hour * 60 + now_minute;

  if(now_time >= start_time && now_time <= end_time) {
    return true;
  } else {
    return false;
  }
}

void check_hibernate_time(rtc_time_t *current_time)
{
  if(hibernate_setting.enabled == false) {
    enable_hibernate = false;
    return;
  }

  /* Hibernate in same day */
  if(hibernate_setting.hour_start < hibernate_setting.hour_end ||
   (hibernate_setting.hour_start == hibernate_setting.hour_end && 
   hibernate_setting.minute_start <= hibernate_setting.minute_end)) {
    enable_hibernate = in_time_range(
      current_time->hour,
      current_time->minute,
      hibernate_setting.hour_start,
      hibernate_setting.minute_start,
      hibernate_setting.hour_end,
      hibernate_setting.minute_end
    );
  /* Hibernate cross day */
  } else {
    enable_hibernate = in_time_range(
      current_time->hour,
      current_time->minute,
      hibernate_setting.hour_start,
      hibernate_setting.minute_start,
      23,
      59
    );

    enable_hibernate |= in_time_range(
      current_time->hour,
      current_time->minute,
      0,
      0,
      hibernate_setting.hour_end,
      hibernate_setting.minute_end
    );
  }
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

