#include "motor.h"
class Rover
{
private:
    Motor m[2];
    double distance;
    unsigned int wheele_circumference;
public:
    Rover (Motor m[2]);
    void move_forward();
    void move_backward();
    void turn_left();
    void turn_right();
    double get_distance();
};
