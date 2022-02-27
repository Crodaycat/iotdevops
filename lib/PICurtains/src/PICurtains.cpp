#include "PICurtains.h"

PICurtains::PICurtains() {}

PICurtains::PICurtains(int waitTime)
{
  _waitTime = waitTime;
}

void PICurtains::handle(String action)
{
  Serial.println("Handle from curtains handler");
  Serial.println(action);
}
