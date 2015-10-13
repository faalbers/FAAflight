#include <stdbool.h>
#include <stdio.h>
#include "config.h"


// Default settings
static void resetConf(void)
{
  masterConfig.looptime = 3500;
}

static bool isEEPROMContentValid(void)
{
    // looks good, let's roll!
    return false;
}

void ensureEEPROMContainsValidData(void)
{
    if (isEEPROMContentValid()) {
        return;
    }

    resetEEPROM();
}

void resetEEPROM(void)
{
    resetConf();
}
