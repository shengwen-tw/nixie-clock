#include <Arduino.h>

#include "pindef.h"
#include "tube_control.h"


int tube_select_table[8][4] = {{LOW, LOW, LOW, LOW}, {HIGH, LOW, LOW, LOW},
      {LOW, HIGH, LOW, LOW}, {HIGH, HIGH, LOW, LOW}, {LOW, LOW, HIGH, LOW},
      {HIGH, LOW, HIGH, LOW}, {LOW, HIGH, HIGH, LOW}, {HIGH, HIGH, HIGH, LOW}};

int font_table[10][4] = {{LOW, LOW, LOW, LOW}, {HIGH, LOW, LOW, LOW},
      {LOW, HIGH, LOW, LOW}, {HIGH, HIGH, LOW, LOW}, {LOW, LOW, HIGH, LOW},
      {HIGH, LOW, HIGH, LOW}, {LOW, HIGH, HIGH, LOW}, {HIGH, HIGH, HIGH, LOW},
      {LOW, LOW, LOW, HIGH}, {HIGH, LOW, LOW, HIGH}};

void tube_control(int tube_number, int font)
{
  digitalWrite(pin_tube_select_a0, tube_select_table[tube_number][0]);
  digitalWrite(pin_tube_select_a1, tube_select_table[tube_number][1]);
  digitalWrite(pin_tube_select_a2, tube_select_table[tube_number][2]);
  digitalWrite(pin_tube_select_a3, tube_select_table[tube_number][3]);
  
  if(font == LEFT_DOT) {
    digitalWrite(pin_font_left_dot, HIGH);
    digitalWrite(pin_font_right_dot, LOW);
  } else if(font == RIGHT_DOT) {
    digitalWrite(pin_font_left_dot, LOW);
    digitalWrite(pin_font_right_dot, HIGH);    
  } else {
    digitalWrite(pin_font_a, font_table[font][0]);
    digitalWrite(pin_font_b, font_table[font][1]);
    digitalWrite(pin_font_c, font_table[font][2]);
    digitalWrite(pin_font_d, font_table[font][3]);
  }
}
