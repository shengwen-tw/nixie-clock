#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"

#define EMPTY_DIGIT -1

#define DATE_MODE 0
#define TIME_MODE 1

int hour_format = FORMAT_24HR;

int blink_time = 0;
int blink_digit = -1;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} time;

void read_time(time *cur_time)
{
    cur_time->year = year();
    cur_time->month = month();
    cur_time->day = day();
    hour_format ? cur_time->hour = hour() : cur_time->hour = hourFormat12();
    cur_time->minute = minute();
    cur_time->second = second();
}

void sort_to_digit(time *cur_time, int *date_data, int *time_data)
{
    /* Year */
    date_data[7] = cur_time->year / 1000;
    date_data[6] = (cur_time->year / 100) % 10;
    date_data[5] = (cur_time->year / 10) % 100;
    date_data[4] = cur_time->year % 10;
    /* Month */
    date_data[3] = cur_time->month / 10;
    date_data[2] = cur_time->month % 10;
    /* Day */
    date_data[1] = cur_time->day / 10;
    date_data[0] = cur_time->day % 10;
    
    /* Hour */
    time_data[7] = cur_time->hour / 10;
    time_data[6] = cur_time->hour % 10;
    /* Minute*/
    time_data[4] = cur_time->minute / 10;
    time_data[3] = cur_time->minute % 10;
    /* Second */
    time_data[1] = cur_time->second / 10;
    time_data[0] = cur_time->second % 10;
    /* Empty */
    time_data[5] = -1;
    time_data[2] = -1;
}

void set_blink_digit(int digit)
{
    blink_digit = digit;
}

void display_time(int flag)
{
    if(timeStatus() != timeSet)
        return;

    time cur_time = {0};
    int date_data[8], time_data[8];
        
    read_time(&cur_time);
    sort_to_digit(&cur_time, date_data, time_data);
    
    for(int i = 0; i < 8; i++) {
            /* Date mode */
            if(flag == DATE_MODE) {
                //If the blink digit is set, start blinking
                if(blink_time < BLINK_DUTY  && i == blink_digit)
                    continue; //Switch off the light for half duty cycle
                else
                    show_number(date_data[i], i);
             /* Time mode */
            } else if(flag == TIME_MODE) {
                if(time_data[i] != -1) {
                    //If the blink digit is set, start blinking
                    if(blink_time < BLINK_DUTY  && i == blink_digit)
                        continue; //Switch off the light for half duty cycle
                    else
                        show_number(time_data[i], i);
                } else {
                    show_dot(i);
                }
            /* Unknown mode */
            } else {
                return;
            }
            
            delay(1);
    }
}
