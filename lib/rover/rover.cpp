// #include "rover.h"
// #include <Arduino.h>

// void Rover::move_forward()
// {
//     this->motors[0].rotate_forward();
//     this->motors[1].rotate_forward();
// }
// void Rover::move_backward()
// {
//     this->motors[0].rotate_backward();
//     this->motors[1].rotate_backward();
// }
// void Rover::turn_left()
// {
//     this->motors[0].rotate_forward();
//     this->motors[1].rotate_backward();
// }
// void Rover::turn_right()
// {
//     this->motors[0].rotate_backward();
//     this->motors[1].rotate_forward();
// }
// void Rover::stop()
// {
//     this->motors[0].stop();
//     this->motors[1].stop();
// }
// double Rover::get_distance()
// {
//     return this->distance;
// }
// void Rover::set_distance(double x)
// {
//     this->distance = x;
// }


// Rover::Rover(Motor m1, Motor m2, Ir_sensor ir, unsigned int circumference)
// {
//     this->distance = 0;
//     this->wheele_circumference = circumference;
//     this->motor1 = m1;
//     this->motor2 = m2;
//     this->ir = ir;
// }