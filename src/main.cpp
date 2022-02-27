// #include <ESP32Servo.h>

#include <PIWiFI.h>
#include <PIMQTT.h>
#include <PICurtains.h>

char *wifiSSID = "CLARO_WIFI1F5";
char *wifiPassword = "CLAROI743";
char *mqttServerIP = "192.168.0.112";
int mqttPort = 1883;
char *mqttClientID = "CurtainsClient";

PIWiFi *wiFiController;
PIMQTT *mqttController;
PICurtains *curtainsManager;

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]");
  Serial.println();

  String message;

  for (int i = 0; i < length; i++)
  {
    message += (char)payload[i];
  }

  Serial.println(message);
  curtainsManager->handle(message);
}

void setup()
{
  Serial.begin(115200);

  wiFiController = new PIWiFi(wifiSSID, wifiPassword, 500);
  curtainsManager = new PICurtains();
  mqttController = new PIMQTT(mqttServerIP, mqttClientID, mqttPort);
  mqttController->_mqttClient->setCallback(callback);
}

void loop()
{
  wiFiController->loop();
  mqttController->loop();
}
