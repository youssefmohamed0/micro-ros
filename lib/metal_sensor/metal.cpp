#include "metal_sensor.h"
#include "Arduino.h"

Metal_sensor::Metal_sensor(unsigned int pin)
{
    pinMode(pin, INPUT);
}

bool Metal_sensor::get_reading()
{
    return digitalRead(this->pin_number);
}