#include <stdio.h>
#include "config.h"
#include "system.h"
#include "diag/Trace.h"

uint32_t currentTime = 0;
uint32_t previousTime = 0;
uint16_t cycleTime = 0;         // this is the number in micro second to achieve a full loop, it can differ a little and is taken into account in the PID loop

void loop(void)
{
  static uint32_t loopTime;

  currentTime = micros();

  if (masterConfig.looptime == 0 || (int32_t)(currentTime - loopTime) >= 0) {
    loopTime = currentTime + masterConfig.looptime;

    // Measure loop rate just after reading the sensors
    currentTime = micros();
    cycleTime = (int32_t)(currentTime - previousTime);
    previousTime = currentTime;

    //trace_printf("Loop Time: %u micros\n", loopTime);
  }
}
