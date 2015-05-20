#include "pindef.h" 
#include "tube_control.h"


void setup() {
  Serial.begin(9600);
  
  pinMode(pin_font_a, OUTPUT);
  pinMode(pin_font_b, OUTPUT);
  pinMode(pin_font_c, OUTPUT);
  pinMode(pin_font_d, OUTPUT);
  
  pinMode(pin_font_left_dot, OUTPUT);
  pinMode(pin_font_right_dot, OUTPUT);
  
  pinMode(pin_tube_select_a0, OUTPUT);
  pinMode(pin_tube_select_a1, OUTPUT);
  pinMode(pin_tube_select_a2, OUTPUT);
  pinMode(pin_tube_select_a3, OUTPUT);
  
  pinMode(pin_brightness, OUTPUT);
  
  set_tube_brightness(100);
}

void loop() {
  tube_control(6, RIGHT_DOT);
  
  Serial.print("test");
  delay(1000);
}
