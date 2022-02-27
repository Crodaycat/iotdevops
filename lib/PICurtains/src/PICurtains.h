#ifndef PI_CURTAINS_H
#define PI_CURTAINS_H
#include <Arduino.h>
#include <PIMQTT.h>

class PICurtains : public PIMQTTHandler
{
private:
  int _waitTime = 500;
  unsigned long _lastInteraction;

public:
  PICurtains();
  PICurtains(int waitTime);

  void handle(String action);
};

#endif
