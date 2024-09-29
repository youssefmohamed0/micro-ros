#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
private:
    unsigned int forward_pin;
    unsigned int backward_pin;
    int state;     // 0: static, 1,: forward, -1: backward
    int speed;
public:
    Motor (unsigned int fp, unsigned int bp);
    void rotate_forward();
    void rotate_backward();
    void stop();
};


#endif