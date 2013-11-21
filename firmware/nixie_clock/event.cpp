#include <Arduino.h>

#include "pin_def.h"
#include "display.h"
#include "clock_time.h"
#include "event.h"

buttonBase::buttonBase(int button_pin, clock_time *clock)
{
    hold_time = 0;
    this->button_pin = button_pin;
    this->clock = clock; 
}

void searchButton::button_click()
{
}

void adjustButton::button_click()
{
}

void modeButton::button_click()
{
}
