#include <Arduino.h>
#include <micro_ros_platformio.h>
// #include <micro_ros_arduino.h>
#include <stdio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rcl/error_handling.h>
#include <WiFi.h>
#include <std_msgs/msg/int32.h>

class Communication
{
private:
    double baud_rate;
    char* wifi_ssif;
    char* wifi_pass;
    IPAddress agent_ip;
    unsigned int agent_port;
public:

};
