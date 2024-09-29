#include "motor.h"
#include <Arduino.h>

void Motor::rotate_forward()
{
    digitalWrite(this->forward_pin,HIGH);
    digitalWrite(this->backward_pin,LOW);
    this->state = 1;
}
void Motor::rotate_backward()
{
    digitalWrite(this->forward_pin,LOW);
    digitalWrite(this->backward_pin,HIGH);
    this->state = -1;
}
void Motor::stop()
{
    digitalWrite(this->forward_pin,LOW);
    digitalWrite(this->backward_pin,LOW);
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