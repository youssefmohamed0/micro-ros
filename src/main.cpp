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
// #include <std_msgs/msg/string.h>


rcl_subscription_t subscriber;
// rcl_publisher_t publisher;
std_msgs__msg__Int32 msg;
// std_msgs__msg__Int32 pub_msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;




#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

// Callback function triggered when an error occurs eg when subscriber node cannot communicate with the microROS agent
void error_loop(){
  while(1){
    // Serial.println("in error loop");
    delay(400);
  }
}

// Callback fuction triggered when some data is received via the key topic
void subscription_callback(const void * msgin)
{  
  const std_msgs__msg__Int32 * msg = (const std_msgs__msg__Int32 *)msgin;
  if (msg->data == 1)
    digitalWrite(BUILTIN_LED, !digitalRead(BUILTIN_LED));
    // forward
  if (msg->data == 2);
    // left
  if (msg->data == 3)
    digitalWrite(BUILTIN_LED, !digitalRead(BUILTIN_LED));
    // backward
  if (msg->data == 4);
    // right
}



void setup() {

  // Serial.begin(115200);
  // set_microros_serial_transports(Serial);

  char ssid[] = "Galaxy A71EEF6";
  char pass[]= "wqmg3499"; 

  IPAddress agent_ip(192, 168, 178, 14 );
  size_t agent_port = 8888;

  set_microros_wifi_transports(ssid, pass, agent_ip, agent_port);
  // // set_microros_wifi_transports("Youssef", pass, "192.168.0.147", 8888);

  
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, HIGH);  

  delay(2000);

  allocator = rcl_get_default_allocator();


  //create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));


  //create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_platformio_node", "", &support));


  //create subscriber
  RCCHECK(rclc_subscription_init_default(
    &subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),"key"));


  //create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber, &msg, &subscription_callback, ON_NEW_DATA));
  // RCCHECK(rclc_executor_add_timer(&executor, &timer));


}

void loop() {
  delay(100);
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));

}