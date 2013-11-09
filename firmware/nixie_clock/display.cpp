#include <Arduino.h>

#include "pin_def.h"
#include "display.h"

//The data of the font and the digit
int font_data[10][4] = { {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 1} };
int digit_data[8][3] = { {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1} };

void show_number(int num, int digit)
{
    //Set the digit of the seven segment display
   digitalWrite(font_pinA, font_data[num][3]);
   digitalWrite(font_pinB, font_data[num][2]);
   digitalWrite(font_pinC, font_data[num][1]);
   digitalWrite(font_pinD, font_data[num][0]);
   //Set the font of the seven segment display
   digitalWrite(digit_pinA, digit_data[digit][2]);
   digitalWrite(digit_pinB, digit_data[digit][1]);
   digitalWrite(digit_pinC, digit_data[digit][0]);
}
