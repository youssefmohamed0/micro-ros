#include "metal_sensor.h"
#include "Arduino.h"

Metal_sensor::Metal_sensor(unsigned int pin)
{
    pinMode(pin, INPUT);
}

int Metal_sensor::get_reading()
{
    if (!digitalRead(this->pin_number))
    {
        return 1;
    }
    return 0;
}