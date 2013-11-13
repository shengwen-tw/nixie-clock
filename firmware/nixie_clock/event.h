#ifndef __EVENT_H__
#define __EVENT_H__

/* Button event handler */
void btn_search_event();
void btn_adjust_event();
void btn_mode_event();

extern int btnTime_record_flg; //The flag of program should record the time of  button press down or not
extern int btn_hold_time; //Record the time of user press down the button

#endif
