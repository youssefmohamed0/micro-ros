#include "ir_sensor.h"
#include "Arduino.h"

Ir_sensor::Ir_sensor(unsigned int pin)
{
    pinMode(pin, INPUT);
    this->pin_number = pin;
    this->ir_count = 0;
}

int Ir_sensor::get_reading()
{
    if (digitalRead(this->pin_number))
        return 1;
    return 0;
}