#ifndef ROVER_H
#define ROVER_H

#include <Servo.h>
#include "motor.h"
#include "ir_sensor.h"
#include "metal_sensor.h"
class Rover
{
private:
    Motor* motors[2];
    Ir_sensor* ir;
    double distance;
    unsigned int wheele_circumference;
    int state;
    Servo servo;
    int servo_state;
    void close_gripper();
    void open_gripper();
public:
    Rover (Motor* motors[2], Ir_sensor* ir, Servo servo, int servo_pin,  unsigned int circumference);
    void move_forward();
    void move_backward();
    void turn_left();
    void turn_right();
    void stop();
    double get_distance(int ir_count);
    // void set_distance(double dist);
    unsigned int get_ir_reading();
    unsigned int get_wheele_circumference();
    void operate_gripper();
};

#endif