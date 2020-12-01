#ifndef ZUMO_CONFIG_H_
#define ZUMO_CONFIG_H_

/* Change the following definition to 0 to run in normal mode and to 1 to enable simulator mode  */

#define ZUMO_SIMULATOR 1  
  
/* Change the following definition to 0 to disable MQTT and to 1 to enable MQTT  */
#define START_MQTT 1

/* The following definitions must all be in double quotes */
#define NETWORK_SSID "MY_NETWORK"

#define NETWORK_PASSWORD "password"

#define MQTT_BROKER "192.168.1.179"  
    
#define MQTT_CLIENT_ID "Zumo101"    
    
#endif