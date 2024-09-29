#include "motor.h"
#include <Arduino.h>

void Motor::rotate_forward()
{
    if(this->state == 0 || this->state == 1)
    {
        this->speed+=70;
        if(this->speed > 255)
            this->speed == 255;
        analogWrite(this->forward_pin,this->speed);
        analogWrite(this->backward_pin,0);
        this->state = 1;
    }
    else if (this->state == -1)
    {
        this->stop();
    }
}
void Motor::rotate_backward()
{
    if(this->state == 0 || this->state == -1)
    {
        this->speed-=70;
        if(this->speed < -255)
            this->speed == -255;
        analogWrite(this->forward_pin,0);
        analogWrite(this->backward_pin,abs(this->speed));
        this->state = -1;
    }
    else if (this->state == 1)
    {
        this->stop();
    }
}
void Motor::stop()
{
    analogWrite(this->forward_pin,0);
    analogWrite(this->backward_pin,0);
    this->speed = 0;
    this->state = 0;
}

Motor::Motor(unsigned int forward_pin, unsigned int backward_pin)
{
    pinMode(forward_pin,OUTPUT);
    pinMode(backward_pin,OUTPUT);

    this->forward_pin = forward_pin;
    this->backward_pin = backward_pin;
    this->stop();
}