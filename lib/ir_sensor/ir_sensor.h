class Ir_sensor
{
private:
    unsigned int pin_number;
public:
    bool get_reading();
    Ir_sensor(unsigned int pin);
};
