#include <Arduino.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"
#include "event.h"

/* Timer */
int btnTime_record_flg = 0; //The flag of program should record the time of  button press down or not
int btn_hold_time = 0; //Record the time of user press down the button

//Search button handler
void btn_search_event()
{
    int read_val;
    
    /* Check search button */
    read_val = digitalRead(btn_search);
    if(read_val == HIGH) {
        switch(clock_mode) {
            case CLOCK_TIME:
                time_mode++;
                break;
            case CLOCK_SETTING:
                digit_num_inc(cur_blink_digit, time_mode ? time_digit : date_digit, time_mode);
                break;
        }
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
        switch(clock_mode) {
            case CLOCK_TIME:
                display_time(time_mode - 1);
                break;
            case CLOCK_SETTING:
                display_time(time_mode);
                break;
        }
        
        read_val = digitalRead(btn_search);
    }
    
    if(time_mode == TIME_MODE_CNT)
        time_mode = DATE_MODE;
}

//Adjust button handler
void btn_adjust_event()
{
    int read_val = digitalRead(btn_adjust);;

    if(read_val == HIGH) {
        switch(clock_mode) {
            case CLOCK_SETTING:        
                cur_blink_digit = -1;
                set_blink_digit(cur_blink_digit);
                //Set the clock mode back to the time mode 
                clock_mode = CLOCK_TIME; 
                time_mode = TIME_MODE;
                break;
        }
    }

    //Waiting for user release the button
    while(read_val == HIGH) {
        btnTime_record_flg = 1;
        
        if(btn_hold_time >= 2) {
            switch(clock_mode) {
                case CLOCK_TIME:
                    //TODO: Switch to setting mode
                    clock_mode = CLOCK_SETTING; //Set the clock mode to time setting mode
                    time_mode = TIME_MODE;            

                    if(blink_digit == -1) {
                        cur_blink_digit = 7;
                        set_blink_digit(cur_blink_digit);
                    }
                    break;
            }
        }
        
        display_time(time_mode);
        read_val = digitalRead(btn_adjust);
    }
    
    //btnTime_record_flg is true means the button had been pressed
    if(btnTime_record_flg == 1 && clock_mode == CLOCK_TIME) {
        switch(time_mode) {
              case TIME_MODE:
                hour_format++;
                hour_format %= 2;
                break;
        }
    }
    
    btnTime_record_flg = 0;
    btn_hold_time = 0;
}

//Mode button handler
void btn_mode_event()
{
    int read_val;
    
    /* Check mode button */
    read_val = digitalRead(btn_mode);
    
    if(read_val == HIGH) {
        if(cur_blink_digit != -1) {
            if(blink_digit > 0) {
                //Avoid the digit with empty font
                if(time_mode == TIME_MODE  && ( cur_blink_digit == 3 || cur_blink_digit == 6) )
                    cur_blink_digit -= 2;
                else
                    cur_blink_digit--; 
                set_blink_digit(cur_blink_digit);
            } else {
                time_mode++;
                if(time_mode == TIME_MODE_CNT)
                    time_mode %= 2;
                cur_blink_digit = 7;
                set_blink_digit(cur_blink_digit);
            }
        }
    }
    
    //Waiting for user release the button
    while(read_val == HIGH) {
        read_val = digitalRead(btn_mode);
        display_time(time_mode);
    }
}
