#include <Arduino.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"
#include "event.h"

buttonBase::buttonBase(int button_pin, clock_time *clock)
{
    hold_time = 0, time_record_flag = false;
    this->button_pin = button_pin;
    this->clock = clock; 
}

bool buttonBase::get_timer_flag()
{
    return time_record_flag;
}

void buttonBase::timer_enable()
{
    time_record_flag = true;
}

void buttonBase::timer_disable()
{
    hold_time = 0;
    time_record_flag = false;
}

void buttonBase::hold_time_inc()
{
    if(time_record_flag)
        hold_time++;
}

/* Button on-click event override */
void searchButton::button_click()
{
    int read_val = digitalRead(button_pin);
    
    //If the user press the button
    if(read_val == HIGH) {
        switch(clock->get_clock_mode()) {
          case CLOCK_TIME:
               //Switch the mode between time and date
               clock->set_time_mode((clock->get_time_mode() + 1) % 2);
              break;
          case CLOCK_SETTING:
              //TODO:Switch the setting content to the next
              clock->set_blink_time(BLINK_DUTY); //Interrupt blinking
              break;
        }
    }
    
    //Waiting for the user release the button
    while(read_val == HIGH) {
        switch(clock->get_clock_mode()) {
            case CLOCK_TIME:
                /* Not to switch the mode before user release the button */
                clock->set_time_mode((clock->get_time_mode() + 1) % 2); //Restore the previous time mode setting
                clock->display_time();
                clock->set_time_mode((clock->get_time_mode() + 1) % 2); //Set back the time mode setting
                break;
            case CLOCK_SETTING:
                clock->display_time();
                break;
        }
        
        read_val = digitalRead(button_pin);
    }
}

void adjustButton::button_click()
{
    int read_val = digitalRead(button_pin);
    
    //If the user press the button
    if(read_val == HIGH) {
    }
    
    //Waiting for the user release the button
    while(read_val == HIGH) {
        timer_enable();
        
        switch(clock->get_clock_mode()) {
          case CLOCK_TIME:
              break;
          case CLOCK_SETTING:
              if(!(hold_time >= 2))
                  break;
              //TODO:Switch the clock mode to setting mode
              break; 
        }
        
        timer_disable();
        clock->display_time();
        read_val = digitalRead(button_pin);
    }
    
    //btnTime_record_flg is true means the button had been pressed
    if(clock->get_clock_mode() == CLOCK_TIME && clock->get_time_mode() == TIME_MODE) {
        if(time_record_flag == false)
            return;
        clock->set_hour_format( ( clock->get_hour_format() + 1 ) % 2 );
    }
      
    read_val = digitalRead(button_pin);
}

void modeButton::button_click()
{
    int read_val = digitalRead(button_pin);
    
    //If the user press the button
    if(read_val == HIGH) {
        switch(clock->get_clock_mode()) {
          case CLOCK_TIME:
              break;
          case CLOCK_SETTING:
              break;
        }
    }
    
    //Waiting for the user release the button
    while(read_val == HIGH) {
        clock->display_time();   
      
        read_val = digitalRead(button_pin);
    }
}
