#ifndef METAL_SENSOR_H
#define METAL_SENSOR_H

class Metal_sensor
{
private:
    unsigned int pin_number;
public:
    bool get_reading();
    Metal_sensor(unsigned int pin);
};


#endif