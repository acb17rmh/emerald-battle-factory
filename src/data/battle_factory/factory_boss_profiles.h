// Boss dialogue symbols are generated from data/text/factory_boss_texts.pory

#include "../../../include/battle_transition.h"
#include "../../../include/constants/event_objects.h"
#include "../../../include/constants/factory_boss.h"
#include "../../../include/constants/opponents.h"
#include "../../../include/constants/songs.h"
#include "../../../include/constants/species.h"
// Steven
extern const u8 sText_DebugBossName_Steven[],
        sText_StevenPreBattleCall[],
        sText_StevenBattleIntro[],
        sText_StevenBattleRoomPrompt[],
        sText_StevenLastMonSlide[],
        sText_StevenLastMonLowHpSlide[],
        sText_StevenBattlePostWin[],
        sText_StevenBattleSpeechPlayerWon[],
        sText_StevenBattleSpeechPlayerLost[];

// Wally
extern const u8 sText_DebugBossName_Wally[],
        sText_WallyPreBattleCall[],
        sText_WallyBattleIntro[],
        sText_WallyBattleRoomPrompt[],
        sText_WallyLastMonSlide[],
        sText_WallyLastMonLowHpSlide[],
        sText_WallyBattlePostWin[],
        sText_WallyBattleSpeechPlayerWon[],
        sText_WallyBattleSpeechPlayerLost[];

// Roxanne
extern const u8 sText_DebugBossName_Roxanne[],
        sText_RoxannePreBattleCall[],
        sText_RoxanneBattleIntro[],
        sText_RoxanneBattleRoomPrompt[],
        sText_RoxanneLastMonSlide[],
        sText_RoxanneLastMonLowHpSlide[],
        sText_RoxanneBattlePostWin[],
        sText_RoxanneBattleSpeechPlayerWon[],
        sText_RoxanneBattleSpeechPlayerLost[];

// Brawly
extern const u8 sText_DebugBossName_Brawly[],
        sText_BrawlyPreBattleCall[],
        sText_BrawlyBattleIntro[],
        sText_BrawlyBattleRoomPrompt[],
        sText_BrawlyLastMonSlide[],
        sText_BrawlyLastMonLowHpSlide[],
        sText_BrawlyBattlePostWin[],
        sText_BrawlyBattleSpeechPlayerWon[],
        sText_BrawlyBattleSpeechPlayerLost[];

// Wattson
extern const u8 sText_DebugBossName_Wattson[],
        sText_WattsonPreBattleCall[],
        sText_WattsonBattleIntro[],
        sText_WattsonBattleRoomPrompt[],
        sText_WattsonLastMonSlide[],
        sText_WattsonLastMonLowHpSlide[],
        sText_WattsonBattlePostWin[],
        sText_WattsonBattleSpeechPlayerWon[],
        sText_WattsonBattleSpeechPlayerLost[];

// Wattson
extern const u8 sText_DebugBossName_Flannery[],
        sText_FlanneryPreBattleCall[],
        sText_FlanneryBattleIntro[],
        sText_FlanneryBattleRoomPrompt[],
        sText_FlanneryLastMonSlide[],
        sText_FlanneryLastMonLowHpSlide[],
        sText_FlanneryBattlePostWin[],
        sText_FlanneryBattleSpeechPlayerWon[],
        sText_FlanneryBattleSpeechPlayerLost[];

// Norman
extern const u8 sText_DebugBossName_Norman[],
        sText_NormanPreBattleCall[],
        sText_NormanBattleIntro[],
        sText_NormanBattleRoomPrompt[],
        sText_NormanLastMonSlide[],
        sText_NormanLastMonLowHpSlide[],
        sText_NormanBattlePostWin[],
        sText_NormanBattleSpeechPlayerWon[],
        sText_NormanBattleSpeechPlayerLost[];

// Red
extern const u8 sText_DebugBossName_Red[],
        sText_RedPreBattleCall[],
        sText_RedBattleIntro[],
        sText_RedBattleRoomPrompt[],
        sText_RedLastMonSlide[],
        sText_RedLastMonLowHpSlide[],
        sText_RedBattlePostWin[],
        sText_RedBattleSpeechPlayerWon[],
        sText_RedBattleSpeechPlayerLost[];

static const struct FactoryBossProfile sFactoryBossProfiles[FACTORY_BOSS_COUNT] =
{
    [FACTORY_BOSS_NONE] =
    {
        .enabled = FALSE,
        .mugshotColour = MUGSHOT_COLOR_NONE,
    },
    [FACTORY_BOSS_STEVEN] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Steven,
        .preBattleCallText = sText_StevenPreBattleCall,
        .battleIntroText = sText_StevenBattleIntro,
        .battleRoomPromptText = sText_StevenBattleRoomPrompt,
        .lastSwitchInSlideText = sText_StevenLastMonSlide,
        .lastLowHpSlideText = sText_StevenLastMonLowHpSlide,
        .battlePostWinText = sText_StevenBattlePostWin,
        .battleSpeechPlayerWon = sText_StevenBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_StevenBattleSpeechPlayerLost,
        .trainerId = TRAINER_STEVEN,
        .objEventGfx = OBJ_EVENT_GFX_STEVEN,
        .battleBgm = MUS_VS_CHAMPION,
        .preBattleRoomBgm = MUS_ENCOUNTER_CHAMPION,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_METAGROSS,
        .mugshotColour = MUGSHOT_COLOR_BLUE,
    },
    [FACTORY_BOSS_WALLY] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Wally,
        .preBattleCallText = sText_WallyPreBattleCall,
        .battleIntroText = sText_WallyBattleIntro,
        .battleRoomPromptText = sText_WallyBattleRoomPrompt,
        .lastSwitchInSlideText = sText_WallyLastMonSlide,
        .lastLowHpSlideText = sText_WallyLastMonLowHpSlide,
        .battlePostWinText = sText_WallyBattlePostWin,
        .battleSpeechPlayerWon = sText_WallyBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_WallyBattleSpeechPlayerLost,
        .trainerId = TRAINER_WALLY_VR_2,
        .objEventGfx = OBJ_EVENT_GFX_WALLY,
        .battleBgm = MUS_VS_RIVAL,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_GALLADE,
        .mugshotColour = MUGSHOT_COLOR_GREEN,
    },
    [FACTORY_BOSS_ROXANNE] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Roxanne,
        .preBattleCallText = sText_RoxannePreBattleCall,
        .battleIntroText = sText_RoxanneBattleIntro,
        .battleRoomPromptText = sText_RoxanneBattleRoomPrompt,
        .lastSwitchInSlideText = sText_RoxanneLastMonSlide,
        .lastLowHpSlideText = sText_RoxanneLastMonLowHpSlide,
        .battlePostWinText = sText_RoxanneBattlePostWin,
        .battleSpeechPlayerWon = sText_RoxanneBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_RoxanneBattleSpeechPlayerLost,
        .trainerId = TRAINER_ROXANNE_1,
        .objEventGfx = OBJ_EVENT_GFX_ROXANNE,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_COOL,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_FIRST,
        .aceSpecies = SPECIES_TYRANITAR,
        .mugshotColour = MUGSHOT_COLOR_GREEN,
    },
    [FACTORY_BOSS_BRAWLY] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Brawly,
        .preBattleCallText = sText_BrawlyPreBattleCall,
        .battleIntroText = sText_BrawlyBattleIntro,
        .battleRoomPromptText = sText_BrawlyBattleRoomPrompt,
        .lastSwitchInSlideText = sText_BrawlyLastMonSlide,
        .lastLowHpSlideText = sText_BrawlyLastMonLowHpSlide,
        .battlePostWinText = sText_BrawlyBattlePostWin,
        .battleSpeechPlayerWon = sText_BrawlyBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_BrawlyBattleSpeechPlayerLost,
        .trainerId = TRAINER_BRAWLY_1,
        .objEventGfx = OBJ_EVENT_GFX_BRAWLY,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_MEDICHAM,
        .mugshotColour = MUGSHOT_COLOR_BLUE
    },
    [FACTORY_BOSS_WATTSON] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Wattson,
        .preBattleCallText = sText_WattsonPreBattleCall,
        .battleIntroText = sText_WattsonBattleIntro,
        .battleRoomPromptText = sText_WattsonBattleRoomPrompt,
        .lastSwitchInSlideText = sText_WattsonLastMonSlide,
        .lastLowHpSlideText = sText_WattsonLastMonLowHpSlide,
        .battlePostWinText = sText_WattsonBattlePostWin,
        .battleSpeechPlayerWon = sText_WattsonBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_WattsonBattleSpeechPlayerLost,
        .trainerId = TRAINER_WATTSON_1,
        .objEventGfx = OBJ_EVENT_GFX_WATTSON,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_MANECTRIC,
        .mugshotColour = MUGSHOT_COLOR_YELLOW
    },
    [FACTORY_BOSS_FLANNERY] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Flannery,
        .preBattleCallText = sText_FlanneryPreBattleCall,
        .battleIntroText = sText_FlanneryBattleIntro,
        .battleRoomPromptText = sText_FlanneryBattleRoomPrompt,
        .lastSwitchInSlideText = sText_FlanneryLastMonSlide,
        .lastLowHpSlideText = sText_FlanneryLastMonLowHpSlide,
        .battlePostWinText = sText_FlanneryBattlePostWin,
        .battleSpeechPlayerWon = sText_FlanneryBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_FlanneryBattleSpeechPlayerLost,
        .trainerId = TRAINER_FLANNERY_1,
        .objEventGfx = OBJ_EVENT_GFX_FLANNERY,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_MANECTRIC,
        .mugshotColour = MUGSHOT_COLOR_PINK
    },
    [FACTORY_BOSS_NORMAN] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Norman,
        .preBattleCallText = sText_NormanPreBattleCall,
        .battleIntroText = sText_NormanBattleIntro,
        .battleRoomPromptText = sText_NormanBattleRoomPrompt,
        .lastSwitchInSlideText = sText_NormanLastMonSlide,
        .lastLowHpSlideText = sText_NormanLastMonLowHpSlide,
        .battlePostWinText = sText_NormanBattlePostWin,
        .battleSpeechPlayerWon = sText_NormanBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_NormanBattleSpeechPlayerLost,
        .trainerId = TRAINER_NORMAN_1,
        .objEventGfx = OBJ_EVENT_GFX_NORMAN,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_KANGASKHAN,
        .mugshotColour = MUGSHOT_COLOR_PURPLE,
    },
    [FACTORY_BOSS_RED] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Red,
        .preBattleCallText = sText_RedPreBattleCall,
        .battleIntroText = sText_RedBattleIntro,
        .battleRoomPromptText = sText_RedBattleRoomPrompt,
        .lastSwitchInSlideText = sText_RedLastMonSlide,
        .lastLowHpSlideText = sText_RedLastMonLowHpSlide,
        .battlePostWinText = sText_RedBattlePostWin,
        .battleSpeechPlayerWon = sText_RedBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_RedBattleSpeechPlayerLost,
        .trainerId = TRAINER_RED,
        .objEventGfx = OBJ_EVENT_GFX_RED,
        .battleBgm = MUS_HG_VS_CHAMPION,
        .preBattleRoomBgm = MUS_RG_ENCOUNTER_RIVAL,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_FIRST,
        .aceSpecies = SPECIES_PIKACHU,
        .mugshotColour = MUGSHOT_COLOR_YELLOW,
    },
};
