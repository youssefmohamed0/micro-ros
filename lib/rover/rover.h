class Rover
{
private:
    // motors
    double distance;
    unsigned int wheele_circumference;
public:
    void move_forward();
    void move_backward();
    void turn_left();
    void turn_right();
    double get_distance();
};
