#include "ir_sensor.h"
#include "Arduino.h"

Ir_sensor::Ir_sensor(unsigned int pin)
{
    pinMode(pin, INPUT);
}

bool Ir_sensor::get_reading()
{
    return digitalRead(this->pin_number);
}