#include "rover.h"
#include <Arduino.h>

void Rover::move_forward()
{   
    if (this->state == 0 || this->state == 1)
    {
    this->motors[0]->rotate_forward();
    this->motors[1]->rotate_forward();  
    this->state = 1;     
    }
    else
    {
        this->stop();
    }

}
void Rover::move_backward()
{
    if (this->state == 0 || this->state == 3)
    {
    this->motors[0]->rotate_backward();
    this->motors[1]->rotate_backward();  
    this->state = 3;     
    }
    else
    {
        this->stop();
    }
}
void Rover::turn_left()
{
    if (this->state == 0)
    {
    this->motors[0]->rotate_forward();
    this->motors[1]->rotate_backward();  
    this->state = 2;     
    }
    else
    {
        this->stop();
    }
}
void Rover::turn_right()
{
    if (this->state == 0)
    {
    this->motors[0]->rotate_backward();
    this->motors[1]->rotate_forward();  
    this->state = 4;     
    }
    else
    {
        this->stop();
    }
}
void Rover::stop()
{
    this->state = 0;
    this->motors[0]->stop();
    this->motors[1]->stop();
}
double Rover::get_distance()
{
    this->distance = (this->ir1_count + this->ir2_count) /40 * this->wheele_circumference;
    return this->distance;
}
unsigned int Rover::get_ir_reading(int choice)
{
    if (choice == 1)
        return this->irs[0]->get_reading();
    if (choice == 2)
        return this->irs[1]->get_reading();
}
// float Rover::get_wheele_circumference()
// {
//     return this->wheele_circumference;
// }
void Rover::close_gripper()
{
    this->servo.write(0);
    this->servo_state = 0;
}
void Rover::open_gripper()
{
    this->servo.write(1023);
    this->servo_state = 1;
}
void Rover::operate_gripper()
{
    if(this->servo_state == 0)
    {
        this->open_gripper();
    }
    else
    {
        this->close_gripper();
    }
}
Rover::Rover(Motor* m[2], Ir_sensor* ir[2], Servo servo, int servo_pin, float circumference)
{
    this->distance = 0;
    this->wheele_circumference = circumference;

    this->motors[0] = m[0];
    this->motors[1] = m[1];
    this->state = 0;

    this->irs[0] = ir[0];
    this->irs[1] = ir[1];
    this->ir1_count = 0;
    this->ir2_count = 0;

    this->servo = servo;
    servo.attach(servo_pin);
    this->servo_state = 0;
    
}