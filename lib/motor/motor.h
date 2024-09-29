class Motor
{
private:
    unsigned int forward_pin;
    unsigned int backward_pin;
    unsigned int state;     // 0: static, 1,: forward, -1: backward
public:
    Motor (unsigned int fp, unsigned int bp);
    void rotate_forward();
    void rotate_backward();
    void stop();
};
