#include <stdio.h>
#include "stm32f4xx.h"

static uint32_t usTicks = 0;
static volatile uint32_t sysTickUptime = 0;

// SysTick
void SysTick_Handler(void)
{
    sysTickUptime++;
}

static void cycleCounterInit(void)
{
    usTicks = SystemCoreClock / 1000000;
}

// Return system uptime in microseconds (rollover in 70minutes)
uint32_t micros(void)
{
  register uint32_t ms, cycle_cnt;
  do {
    ms = sysTickUptime;
    cycle_cnt = SysTick->VAL;

    /*
     * If the SysTick timer expired during the previous instruction, we need to give it a little time for that
     * interrupt to be delivered before we can recheck sysTickUptime:
     */
    asm volatile("\tnop\n");
  } while (ms != sysTickUptime);
  return (ms * 1000) + (usTicks * 1000 - cycle_cnt) / usTicks;
}

void systemInit(void)
{
  // Init cycle counter
  cycleCounterInit();
}
