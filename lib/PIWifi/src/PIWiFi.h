#ifndef PIWIFI_H
#define PIWIFI_H
#include <Arduino.h>
#include <PIWiFiState.h>

class PIWiFi
{
private:
  int _waitTime = 500;
  unsigned long _lastInteraction;
  boolean _isConnecting = false;
  PIWiFiState *_wifiState;

  void setUpWiFi();
  void setIsConnecting(boolean isConnecting);

public:
  PIWiFi(char *ssid, char *password, int waitTime);

  void loop();
};

#endif