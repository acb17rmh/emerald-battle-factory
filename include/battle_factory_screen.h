#ifndef GUARD_BATTLE_FACTORY_SCREEN_H
#define GUARD_BATTLE_FACTORY_SCREEN_H

#include "global.h"
#include "main.h"

void DoBattleFactorySelectScreen(void);
void DoBattleFactoryRewardScreen(const struct Pokemon *choices, u8 count, MainCallback exitCallback);
void DoBattleFactorySwapScreen(void);

#endif // GUARD_BATTLE_FACTORY_SCREEN_H
