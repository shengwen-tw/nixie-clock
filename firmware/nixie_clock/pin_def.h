#ifndef __PIN_DEF_H__
#define __PIN_DEF_H__

//Seven segment font control pin
extern int font_pinA, font_pinB, font_pinC, font_pinD;
//The dot point of the display
extern int dot_pin;
//Seven segment digit control pin
extern int digit_pinA, digit_pinB, digit_pinC;
//Display work status gate
extern int display_enable_gate;
//Button pin
extern int btn_mode_pin;

#endif
