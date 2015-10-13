#ifndef __CONFIG_H
#define __CONFIG_H

#include "config.h"
#include "config_master.h"
#include "config_profile.h"

master_t masterConfig;                 // master config struct with data independent from profiles
profile_t *currentProfile;

void ensureEEPROMContainsValidData(void);

#endif /* __CONFIG_H */
