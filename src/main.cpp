#include <PIWiFI.h>
#include <PIMQTT.h>
#include <PICurtains.h>
#include <PIOTA.h>

char *wifiSSID = "CLARO_WIFI1F5";
char *wifiPassword = "CLAROI743";
char *mqttServerIP = "192.168.0.112";
int mqttPort = 1883;
char *mqttClientID = "CurtainsClient";

PIWiFi *wiFiController;
PIMQTT *mqttController;
PICurtains *curtainsManager;
PIOTA *otaManager;

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.println("Message arrived [" + String(topic) + "]");

  String message;

  for (int i = 0; i < length; i++)
  {
    message += (char)payload[i];
  }

  Serial.println(message);

  if (String(topic) == "gym/main/curtains")
  {
    curtainsManager->handle(message);
  }
}

void setup()
{
  Serial.begin(115200);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  wiFiController = new PIWiFi(wifiSSID, wifiPassword, 500);
  mqttController = new PIMQTT(mqttServerIP, mqttClientID, mqttPort);
  mqttController->_mqttClient->setCallback(callback);

  otaManager = new PIOTA();

  curtainsManager = new PICurtains(17, 1000);
}

void loop()
{
  wiFiController->loop();
  mqttController->loop();
  otaManager->loop();
}
