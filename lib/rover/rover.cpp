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
    this->motors[0]->stop();
    this->motors[1]->stop();
}
double Rover::get_distance(int ir_count)
{
    this->distance = ir_count/20 * this->wheele_circumference;
    return this->distance;
}
// void Rover::set_distance(double x)
// {
//     this->distance = x;
// }
unsigned int Rover::get_ir_reading()
{
    return this->ir->get_reading();
}
unsigned int Rover::get_wheele_circumference()
{
    return this->wheele_circumference;
}

Rover::Rover(Motor* m[2], Ir_sensor* ir, unsigned int circumference)
{
    this->distance = 0;
    this->wheele_circumference = circumference;
    this->motors[0] = m[0];
    this->motors[1] = m[1];
    this->ir = ir;
    this->state = 0;
}