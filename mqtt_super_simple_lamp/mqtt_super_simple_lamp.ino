#define MQTT_DEBUG_MODE
#define WIFI_DEBUG_MODE

#include <WiFiConnector.h>
#include <MqttConnector.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

MqttConnector *mqtt;
WiFiConnector *wifi;

// MQTT_HOSTT
#define MQTT_HOST "192.168.15.148"
#define MQTT_PORT 1883

#include "init_wifi.h"
#include "_publish.h"
#include "_receive.h"
#include "init_mqtt.h"

void init_hardware()
{
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println("BEGIN");
}

void setup()
{
  init_hardware();
  init_wifi();
  init_mqtt();
}

void loop()
{
  mqtt->loop(wifi);
}

