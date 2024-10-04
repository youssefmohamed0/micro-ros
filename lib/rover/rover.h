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
    Ir_sensor* irs[2];
    
    double distance;
    float wheele_circumference;
    int state;
    Servo servo;
    int servo_state;
    void close_gripper();
    void open_gripper();
public:
    Rover (Motor* motors[2], Ir_sensor* irs[2], Servo servo, int servo_pin,  float circumference);
    int ir1_count;
    int ir2_count;
    
    void move_forward();
    void move_backward();
    void turn_left();
    void turn_right();
    void stop();
    double get_distance();
    // void set_distance(double dist);
    unsigned int get_ir_reading(int choice);
    // float get_wheele_circumference();
    void operate_gripper();
};

#endif