#include "communication.h"
rcl_subscription_t subscriber;
rcl_publisher_t publisher;
std_msgs__msg__Int32 msg;
std_msgs__msg__Int32 pub_msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;
double distance = 0;  /////////////////////*\\\\\\\\\\\\\\\\\\\\\

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

void subscription_callback(const void * msgin)
{  
  const std_msgs__msg__Int32 * msg = (const std_msgs__msg__Int32 *)msgin;
  if (msg->data == 1)
    digitalWrite(BUILTIN_LED, !digitalRead(BUILTIN_LED));
    // digitalWrite(motor1_forward,HIGH);
    // digitalWrite(motor2_forward,HIGH);
    // forward
  if (msg->data == 2);
    // left
  if (msg->data == 3)
    digitalWrite(BUILTIN_LED, !digitalRead(BUILTIN_LED));
    // backward
  if (msg->data == 4);
    // right
}
void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{  
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    RCSOFTCHECK(rcl_publish(&publisher, &pub_msg, NULL));
    pub_msg.data = distance;
  }
}

void Communication::serial_comm()
{
  Serial.begin(this->baud_rate);
  set_microros_serial_transports(Serial);
}
void Communication::wifi_comm()
{
    // set_microros_wifi_transports(this->wifi_ssid, this->wifi_ssid, this->agent_ip, this->agent_port);
}
void Communication::intialize_comms()
{
  allocator = rcl_get_default_allocator();


  //create init_options
  rclc_support_init(&support, 0, NULL, &allocator);


  //create node
  rclc_node_init_default(&node, "micro_ros_platformio_node", "", &support);

  // create publisher
  rclc_publisher_init_default(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "distance");

  // create timer,
  const unsigned int timer_timeout = 1;
  rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(timer_timeout), timer_callback);

  //create subscriber
  rclc_subscription_init_default(&subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),"key");


  //create executor
  rclc_executor_init(&executor, &support.context, 2, &allocator);
  rclc_executor_add_subscription(&executor, &subscriber, &msg, &subscription_callback, ON_NEW_DATA);
  rclc_executor_add_timer(&executor, &timer);

}
void Communication::execute()
{
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}
Communication::Communication(int baud_rate, char* wifi_ssid, char* wifi_pass, IPAddress agent_ip, unsigned int agent_port)
{
    this->baud_rate = baud_rate;
    this->wifi_ssid = wifi_ssid;
    this->wifi_pass = wifi_pass;
    this->agent_ip = agent_ip;
    this->agent_port = agent_port;
}
