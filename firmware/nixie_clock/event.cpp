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
               clock->set_time_mode((clock->get_time_mode() + 1) % TIME_MODE_CNT);
              break;
          case CLOCK_SETTING:
              /* TODO:increase the time until to maximum. 
                   if the time achieve the maximum, reset the time */
              clock->inc_cur_time();
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
    
    //Waiting for the user release the button
    while(read_val == HIGH) {
        timer_enable();
        
        /* If the user switch the mode, freeze until user release the button */
        if(mode_changed == false) {
            switch(clock->get_clock_mode()) {
              case CLOCK_TIME:
                  if(hold_time >= 2) {
                  clock->set_clock_mode(CLOCK_SETTING);
                  clock->set_time_mode(TIME_MODE);
                  
                  clock->set_blink_digit(7, ENABLE);
                  clock->set_blink_digit(6, ENABLE);
                  
                  mode_changed = true;
                  }
                  break;
              case CLOCK_SETTING:
                  clock->set_clock_mode(CLOCK_TIME);
                  clock->clear_blink_digit();
                  mode_changed = true;
                  break;
            }
        }
        
        clock->display_time();
        read_val = digitalRead(button_pin);
    }
    
    //btnTime_record_flg is true means the button had been pressed
    if(clock->get_clock_mode() == CLOCK_TIME && clock->get_time_mode() == TIME_MODE) {
        if(time_record_flag == false || mode_changed == true)
            return;
        clock->set_hour_format( ( clock->get_hour_format() + 1 ) % 2 );
    }
    
    timer_disable();
    mode_changed = false;
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
              /* Switch the setting content to the next */
              
              //Clean up the blink digits
              clock->clear_blink_digit();
              
              /* Switch the mode for setting first */
              if(((clock->get_now_setting() + 1) % TIME_CNT) == YEAR)
                  clock->set_time_mode(DATE_MODE);
              else if(((clock->get_now_setting() + 1) % TIME_CNT) == HOUR)
                  clock->set_time_mode(TIME_MODE);
                      
              clock->set_setting_digit((clock->get_now_setting() + 1) % TIME_CNT); //Set the digits to blink

              clock->set_blink_time(BLINK_DUTY); //Interrupt blinking
              break;
        }
    }
    
    //Waiting for the user release the button
    while(read_val == HIGH) {
        clock->display_time();   
      
        read_val = digitalRead(button_pin);
    }
}
