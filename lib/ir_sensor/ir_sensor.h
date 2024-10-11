#ifndef IR_SENSOR_H
#define IR_SENSOR_H

class Ir_sensor
{
private:
    unsigned int pin_number;
public:
    int prev_state;
    int get_reading();
    Ir_sensor(unsigned int pin);
};


#endif