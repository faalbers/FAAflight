#include <stdbool.h>
#include <stdio.h>
#include "config.h"
#include "config_master.h"

master_t masterConfig;                 // master config struct with data independent from profiles

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
