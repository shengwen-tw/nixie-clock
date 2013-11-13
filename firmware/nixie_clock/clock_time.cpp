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

/* Time format */
int hour_format = FORMAT_24HR;

/* Blink */
int blink_time = 0;
int blink_digit = -1;
int cur_blink_digit = 0; //Record the current digit which is blinking

/* Mode */
int clock_mode = CLOCK_TIME; //Current clock mode
int time_mode = TIME_MODE; //Current display mode of time

/* Digits data of time*/
int date_digit[8], time_digit[8];

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} time;

/* Time showing functions */
void read_time(time *cur_time)
{
    cur_time->year = year();
    cur_time->month = month();
    cur_time->day = day();
    hour_format ? cur_time->hour = hour() : cur_time->hour = hourFormat12();
    cur_time->minute = minute();
    cur_time->second = second();
}

void sort_to_digit(time *cur_time, int *date_digit, int *time_digit)
{
    /* Year */
    date_digit[7] = cur_time->year / 1000;
    date_digit[6] = (cur_time->year / 100) % 10;
    date_digit[5] = (cur_time->year / 10) % 100;
    date_digit[4] = cur_time->year % 10;
    /* Month */
    date_digit[3] = cur_time->month / 10;
    date_digit[2] = cur_time->month % 10;
    /* Day */
    date_digit[1] = cur_time->day / 10;
    date_digit[0] = cur_time->day % 10;
    
    /* Hour */
    time_digit[7] = cur_time->hour / 10;
    time_digit[6] = cur_time->hour % 10;
    /* Minute*/
    time_digit[4] = cur_time->minute / 10;
    time_digit[3] = cur_time->minute % 10;
    /* Second */
    time_digit[1] = cur_time->second / 10;
    time_digit[0] = cur_time->second % 10;
    /* Empty */
    time_digit[5] = -1;
    time_digit[2] = -1;
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
    
    if(clock_mode != CLOCK_SETTING) {
        read_time(&cur_time);
        sort_to_digit(&cur_time, date_digit, time_digit);
    }
    
    for(int i = 0; i < 8; i++) {
            /* Date mode */
            if(flag == DATE_MODE) {
                //If the blink digit is set, start blinking
                if(blink_time < BLINK_DUTY  && i == blink_digit) {
                    continue; //Switch off the light for half duty cycle
                }else {
                    show_number(date_digit[i], i);
                    if(i == 2 || i == 4)
                        show_dot(i);
                }
             /* Time mode */
            } else if(flag == TIME_MODE) {
                if(time_digit[i] != -1) {
                    //If the blink digit is set, start blinking
                    if(blink_time < BLINK_DUTY  && i == blink_digit)
                        continue; //Switch off the light for half duty cycle
                    else
                        show_number(time_digit[i], i);
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

/* Time setting functions */
void digit_num_inc(int digit, int *data, int type_mode)
{
    if(data[digit] < 9)
        data[digit]++;
    else
        data[digit] = 0;
    /*FIXME: The code at here need more judgement or will cause user setting a stange time
       like 25:61:99 */
}
