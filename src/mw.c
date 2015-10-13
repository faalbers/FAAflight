#include <stdio.h>
#include "system.h"

uint32_t currentTime = 0;

void loop(void)
{
    static uint32_t loopTime;

    currentTime = micros();
}
