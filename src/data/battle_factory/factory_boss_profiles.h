// Boss dialogue symbols are generated from data/text/factory_boss_texts.pory

#include "../../../include/battle_transition.h"
#include "../../../include/constants/event_objects.h"
#include "../../../include/constants/factory_boss.h"
#include "../../../include/constants/opponents.h"
#include "../../../include/constants/pokemon.h"
#include "../../../include/constants/songs.h"
#include "../../../include/constants/species.h"
#include "../../../include/constants/trainer_slide.h"
// Steven
extern const u8 sText_DebugBossName_Steven[],
        sText_StevenScoutHint[],
        sText_StevenPreBattleCall[],
        sText_StevenBattleIntro[],
        sText_StevenBattleRoomPrompt[],
        sText_StevenLastMonSlide[],
        sText_StevenLastMonLowHpSlide[],
        sText_StevenBattleSpeechPlayerWon[],
        sText_StevenBattleSpeechPlayerLost[];

// Wally
extern const u8 sText_DebugBossName_Wally[],
        sText_WallyScoutHint[],
        sText_WallyPreBattleCall[],
        sText_WallyBattleIntro[],
        sText_WallyBattleRoomPrompt[],
        sText_WallyLastMonSlide[],
        sText_WallyLastMonLowHpSlide[],
        sText_WallyBattleSpeechPlayerWon[],
        sText_WallyBattleSpeechPlayerLost[];

// Roxanne
extern const u8 sText_DebugBossName_Roxanne[],
        sText_RoxanneScoutHint[],
        sText_RoxannePreBattleCall[],
        sText_RoxanneBattleIntro[],
        sText_RoxanneBattleRoomPrompt[],
        sText_RoxanneLastMonSlide[],
        sText_RoxanneLastMonLowHpSlide[],
        sText_RoxanneBattleSpeechPlayerWon[],
        sText_RoxanneBattleSpeechPlayerLost[];

// Brawly
extern const u8 sText_DebugBossName_Brawly[],
        sText_BrawlyScoutHint[],
        sText_BrawlyPreBattleCall[],
        sText_BrawlyBattleIntro[],
        sText_BrawlyBattleRoomPrompt[],
        sText_BrawlyLastMonSlide[],
        sText_BrawlyLastMonLowHpSlide[],
        sText_BrawlyBattleSpeechPlayerWon[],
        sText_BrawlyBattleSpeechPlayerLost[];

// Wattson
extern const u8 sText_DebugBossName_Wattson[],
        sText_WattsonScoutHint[],
        sText_WattsonPreBattleCall[],
        sText_WattsonBattleIntro[],
        sText_WattsonBattleRoomPrompt[],
        sText_WattsonLastMonSlide[],
        sText_WattsonLastMonLowHpSlide[],
        sText_WattsonBattleSpeechPlayerWon[],
        sText_WattsonBattleSpeechPlayerLost[];

// Flannery
extern const u8 sText_DebugBossName_Flannery[],
        sText_FlanneryScoutHint[],
        sText_FlanneryPreBattleCall[],
        sText_FlanneryBattleIntro[],
        sText_FlanneryBattleRoomPrompt[],
        sText_FlanneryLastMonSlide[],
        sText_FlanneryLastMonLowHpSlide[],
        sText_FlanneryBattleSpeechPlayerWon[],
        sText_FlanneryBattleSpeechPlayerLost[];

// Norman
extern const u8 sText_DebugBossName_Norman[],
        sText_NormanScoutHint[],
        sText_NormanPreBattleCall[],
        sText_NormanBattleIntro[],
        sText_NormanBattleRoomPrompt[],
        sText_NormanLastMonSlide[],
        sText_NormanLastMonLowHpSlide[],
        sText_NormanBattleSpeechPlayerWon[],
        sText_NormanBattleSpeechPlayerLost[];

// Winona
extern const u8 sText_DebugBossName_Winona[],
        sText_WinonaScoutHint[],
        sText_WinonaPreBattleCall[],
        sText_WinonaBattleIntro[],
        sText_WinonaBattleRoomPrompt[],
        sText_WinonaLastMonSlide[],
        sText_WinonaLastMonLowHpSlide[],
        sText_WinonaBattleSpeechPlayerWon[],
        sText_WinonaBattleSpeechPlayerLost[];

// Juan
extern const u8 sText_DebugBossName_Juan[],
        sText_JuanScoutHint[],
        sText_JuanPreBattleCall[],
        sText_JuanBattleIntro[],
        sText_JuanBattleRoomPrompt[],
        sText_JuanLastMonSlide[],
        sText_JuanLastMonLowHpSlide[],
        sText_JuanBattleSpeechPlayerWon[],
        sText_JuanBattleSpeechPlayerLost[];

// Red
extern const u8 sText_DebugBossName_Red[],
        sText_RedScoutHint[],
        sText_RedPreBattleCall[],
        sText_RedBattleIntro[],
        sText_RedBattleRoomPrompt[],
        sText_RedLastMonSlide[],
        sText_RedLastMonLowHpSlide[],
        sText_RedBattleSpeechPlayerWon[],
        sText_RedBattleSpeechPlayerLost[];

// Blue
extern const u8 sText_DebugBossName_Blue[],
        sText_BlueScoutHint[],
        sText_BluePreBattleCall[],
        sText_BlueBattleIntro[],
        sText_BlueBattleRoomPrompt[],
        sText_BlueLastMonSlide[],
        sText_BlueLastMonLowHpSlide[],
        sText_BlueMegaEvolutionSlide[],
        sText_BlueEnemyMonUnaffectedSlide[],
        sText_BlueBattleSpeechPlayerWon[],
        sText_BlueBattleSpeechPlayerLost[];

// Cynthia
extern const u8 sText_DebugBossName_Cynthia[],
        sText_CynthiaScoutHint[],
        sText_CynthiaPreBattleCall[],
        sText_CynthiaBattleIntro[],
        sText_CynthiaBattleRoomPrompt[],
        sText_CynthiaLastMonSlide[],
        sText_CynthiaLastMonLowHpSlide[],
        sText_CynthiaBattleSpeechPlayerWon[],
        sText_CynthiaBattleSpeechPlayerLost[];


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
        .scoutHintText = sText_StevenScoutHint,
        .preBattleCallText = sText_StevenPreBattleCall,
        .battleIntroText = sText_StevenBattleIntro,
        .battleRoomPromptText = sText_StevenBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_StevenLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_StevenLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_StevenBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_StevenBattleSpeechPlayerLost,
        .trainerId = TRAINER_STEVEN,
        .objEventGfx = OBJ_EVENT_GFX_STEVEN,
        .battleBgm = MUS_VS_CHAMPION,
        .preBattleRoomBgm = MUS_ENCOUNTER_CHAMPION,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_METAGROSS,
        .allowedTypes = {TYPE_NONE, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_BLUE,
    },
    [FACTORY_BOSS_WALLY] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Wally,
        .scoutHintText = sText_WallyScoutHint,
        .preBattleCallText = sText_WallyPreBattleCall,
        .battleIntroText = sText_WallyBattleIntro,
        .battleRoomPromptText = sText_WallyBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_WallyLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_WallyLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_WallyBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_WallyBattleSpeechPlayerLost,
        .trainerId = TRAINER_WALLY_VR_2,
        .objEventGfx = OBJ_EVENT_GFX_WALLY,
        .battleBgm = MUS_VS_RIVAL,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_GALLADE,
        .allowedTypes = {TYPE_NONE, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_GREEN,
    },
    [FACTORY_BOSS_ROXANNE] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Roxanne,
        .scoutHintText = sText_RoxanneScoutHint,
        .preBattleCallText = sText_RoxannePreBattleCall,
        .battleIntroText = sText_RoxanneBattleIntro,
        .battleRoomPromptText = sText_RoxanneBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_RoxanneLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_RoxanneLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_RoxanneBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_RoxanneBattleSpeechPlayerLost,
        .trainerId = TRAINER_ROXANNE_1,
        .objEventGfx = OBJ_EVENT_GFX_ROXANNE,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_COOL,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_FIRST,
        .aceSpecies = SPECIES_TYRANITAR,
        .allowedTypes = {TYPE_ROCK, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_GREEN,
    },
    [FACTORY_BOSS_BRAWLY] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Brawly,
        .scoutHintText = sText_BrawlyScoutHint,
        .preBattleCallText = sText_BrawlyPreBattleCall,
        .battleIntroText = sText_BrawlyBattleIntro,
        .battleRoomPromptText = sText_BrawlyBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_BrawlyLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_BrawlyLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_BrawlyBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_BrawlyBattleSpeechPlayerLost,
        .trainerId = TRAINER_BRAWLY_1,
        .objEventGfx = OBJ_EVENT_GFX_BRAWLY,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_MEDICHAM,
        .allowedTypes = {TYPE_FIGHTING, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_BLUE
    },
    [FACTORY_BOSS_WATTSON] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Wattson,
        .scoutHintText = sText_WattsonScoutHint,
        .preBattleCallText = sText_WattsonPreBattleCall,
        .battleIntroText = sText_WattsonBattleIntro,
        .battleRoomPromptText = sText_WattsonBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_WattsonLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_WattsonLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_WattsonBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_WattsonBattleSpeechPlayerLost,
        .trainerId = TRAINER_WATTSON_1,
        .objEventGfx = OBJ_EVENT_GFX_WATTSON,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_MANECTRIC,
        .allowedTypes = {TYPE_ELECTRIC, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_YELLOW
    },
    [FACTORY_BOSS_FLANNERY] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Flannery,
        .scoutHintText = sText_FlanneryScoutHint,
        .preBattleCallText = sText_FlanneryPreBattleCall,
        .battleIntroText = sText_FlanneryBattleIntro,
        .battleRoomPromptText = sText_FlanneryBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_FlanneryLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_FlanneryLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_FlanneryBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_FlanneryBattleSpeechPlayerLost,
        .trainerId = TRAINER_FLANNERY_1,
        .objEventGfx = OBJ_EVENT_GFX_FLANNERY,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_MANECTRIC,
        .allowedTypes = {TYPE_FIRE, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_PINK
    },
    [FACTORY_BOSS_NORMAN] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Norman,
        .scoutHintText = sText_NormanScoutHint,
        .preBattleCallText = sText_NormanPreBattleCall,
        .battleIntroText = sText_NormanBattleIntro,
        .battleRoomPromptText = sText_NormanBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_NormanLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_NormanLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_NormanBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_NormanBattleSpeechPlayerLost,
        .trainerId = TRAINER_NORMAN_1,
        .objEventGfx = OBJ_EVENT_GFX_NORMAN,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_KANGASKHAN,
        .allowedTypes = {TYPE_NORMAL, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_PURPLE,
    },
    [FACTORY_BOSS_WINONA] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Winona,
        .scoutHintText = sText_WinonaScoutHint,
        .preBattleCallText = sText_WinonaPreBattleCall,
        .battleIntroText = sText_WinonaBattleIntro,
        .battleRoomPromptText = sText_WinonaBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_WinonaLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_WinonaLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_WinonaBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_WinonaBattleSpeechPlayerLost,
        .trainerId = TRAINER_WINONA_1,
        .objEventGfx = OBJ_EVENT_GFX_WINONA,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_ALTARIA,
        .allowedTypes = {TYPE_FLYING, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_BLUE,
    },
    [FACTORY_BOSS_JUAN] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Juan,
        .scoutHintText = sText_JuanScoutHint,
        .preBattleCallText = sText_JuanPreBattleCall,
        .battleIntroText = sText_JuanBattleIntro,
        .battleRoomPromptText = sText_JuanBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_JuanLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_JuanLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_JuanBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_JuanBattleSpeechPlayerLost,
        .trainerId = TRAINER_JUAN_1,
        .objEventGfx = OBJ_EVENT_GFX_JUAN,
        .battleBgm = MUS_VS_GYM_LEADER,
        .preBattleRoomBgm = MUS_ENCOUNTER_INTENSE,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_ALTARIA,
        .allowedTypes = {TYPE_WATER, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_BLUE,
    },
    [FACTORY_BOSS_RED] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Red,
        .scoutHintText = sText_RedScoutHint,
        .preBattleCallText = sText_RedPreBattleCall,
        .battleIntroText = sText_RedBattleIntro,
        .battleRoomPromptText = sText_RedBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_RedLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_RedLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_RedBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_RedBattleSpeechPlayerLost,
        .trainerId = TRAINER_RED,
        .objEventGfx = OBJ_EVENT_GFX_RED,
        .battleBgm = MUS_HG_VS_CHAMPION,
        .preBattleRoomBgm = MUS_RG_ENCOUNTER_RIVAL,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_FIRST,
        .aceSpecies = SPECIES_PIKACHU,
        .allowedTypes = {TYPE_NONE, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_YELLOW,
    },
    [FACTORY_BOSS_BLUE] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Blue,
        .scoutHintText = sText_BlueScoutHint,
        .preBattleCallText = sText_BluePreBattleCall,
        .battleIntroText = sText_BlueBattleIntro,
        .battleRoomPromptText = sText_BlueBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_BlueLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_BlueLastMonLowHpSlide,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = sText_BlueMegaEvolutionSlide,
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = sText_BlueEnemyMonUnaffectedSlide
        },
        .battleSpeechPlayerWon = sText_BlueBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_BlueBattleSpeechPlayerLost,
        .trainerId = TRAINER_BLUE,
        .objEventGfx = OBJ_EVENT_GFX_BLUE,
        .battleBgm = MUS_RG_VS_CHAMPION,
        .preBattleRoomBgm = MUS_RG_VICTORY_ROAD,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_FIRST,
        .aceSpecies = SPECIES_AERODACTYL,
        .allowedTypes = {TYPE_NONE, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_BLUE,
    },
    [FACTORY_BOSS_CYNTHIA] =
    {
        .enabled = TRUE,
        .debugMenuName = sText_DebugBossName_Cynthia,
        .scoutHintText = sText_CynthiaScoutHint,
        .preBattleCallText = sText_CynthiaPreBattleCall,
        .battleIntroText = sText_CynthiaBattleIntro,
        .battleRoomPromptText = sText_CynthiaBattleRoomPrompt,
        .slideTexts =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = sText_CynthiaLastMonSlide,
            [TRAINER_SLIDE_LAST_LOW_HP] = sText_CynthiaLastMonLowHpSlide,
        },
        .battleSpeechPlayerWon = sText_CynthiaBattleSpeechPlayerWon,
        .battleSpeechPlayerLost = sText_CynthiaBattleSpeechPlayerLost,
        .trainerId = TRAINER_CYNTHIA,
        .objEventGfx = OBJ_EVENT_GFX_CYNTHIA,
        .battleBgm = MUS_DP_VS_CHAMPION,
        .preBattleRoomBgm = MUS_BW_CYNTHIA,
        .awardSymbol = FALSE,
        .acePolicy = FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST,
        .aceSpecies = SPECIES_GARCHOMP,
        .allowedTypes = {TYPE_NONE, TYPE_NONE},
        .mugshotColour = MUGSHOT_COLOR_PURPLE,
    },
};
