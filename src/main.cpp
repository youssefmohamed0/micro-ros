#include "communication.h"

int baud_rate = 115200;
char wifi_ssid[] = "Galaxy A71EEF6";
char wifi_pass[]= "wqmg3499"; 
IPAddress agent_ip(192, 168, 178, 14 );
unsigned int agent_port = 8888;

Communication comms(baud_rate, wifi_ssid, wifi_pass, agent_ip, agent_port);

void setup()
{
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);

    comms.serial_comm();
    // comms.wifi_comm();
    delay(2000);
    comms.intialize_comms();
}

void loop()
{
    comms.execute();
}