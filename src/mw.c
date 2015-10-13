#include <stdio.h>
#include "system.h"

uint32_t currentTime = 0;

void loop(void)
{
  static uint32_t loopTime;

  currentTime = micros();

  //if (masterConfig.looptime == 0 || (int32_t)(currentTime - loopTime) >= 0) {
  //}
}
