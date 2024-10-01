#ifndef IR_SENSOR_H
#define IR_SENSOR_H

class Ir_sensor
{
private:
    unsigned int pin_number;
public:
    int ir_count;
    int get_reading();
    Ir_sensor(unsigned int pin);
};


#endif