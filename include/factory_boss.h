#ifndef GUARD_FACTORY_BOSS_H
#define GUARD_FACTORY_BOSS_H

#include "global.h"
#include "constants/pokemon.h"
#include "constants/factory_boss.h"
#include "constants/trainer_slide.h"

struct FactoryBossProfile
{
    bool8 enabled;
    const u8 *debugMenuName;
    const u8 *scoutHintText;
    const u8 *preBattleCallText;
    const u8 *battleIntroText;
    const u8 *battleRoomPromptText;
    const u8 *slideTexts[TRAINER_SLIDE_COUNT];
    const u8 *battleSpeechPlayerWon;
    const u8 *battleSpeechPlayerLost;
    u16 trainerId;
    u16 objEventGfx;
    u16 battleBgm;
    u16 preBattleRoomBgm;
    bool8 awardSymbol;
    u8 acePolicy;
    u16 aceSpecies;
    enum Type allowedTypes[2];
    u8 mugshotColour;
};

u8 GetActiveFactoryBossId(void);
const struct FactoryBossProfile *GetFactoryBossProfile(u8 bossId);
const struct FactoryBossProfile *GetActiveFactoryBossProfile(void);
bool8 IsActiveFactoryBossUsingMugshot(void);
u8 GetActiveFactoryBossMugshotColour(void);

#endif // GUARD_FACTORY_BOSS_H
