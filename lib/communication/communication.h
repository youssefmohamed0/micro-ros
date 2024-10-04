#ifndef COMMUNICATION_H
#define COMMUNICATION_H


#include <Arduino.h>
#include <Servo.h>
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
    int baud_rate;
    char* wifi_ssid;
    char* wifi_pass;
    IPAddress agent_ip;
    unsigned int agent_port;
public:
    Communication(int , char*, char*, IPAddress, unsigned int);
    void serial_comm();
    void wifi_comm();
    // void sub_callback(const void* );
    // void timer_callback(rcl_timer_t*, int64_t);
    void intialize_comms();
    void execute();
};


#endif