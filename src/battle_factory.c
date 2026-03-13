#include "global.h"
#include "battle.h"
#include "battle_factory.h"
#include "battle_factory_screen.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "frontier_util.h"
#include "factory_boss.h"
#include "factory_boss_team.h"
#include "factory_reward.h"
#include "battle_tower.h"
#include "random.h"
#include "pokedex.h"
#include "pokemon.h"
#include "constants/battle_ai.h"
#include "constants/battle_factory.h"

#include "fieldmap.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "main.h"
#include "palette.h"
#include "script_pokemon_util.h"
#include "starter_choose.h"
#include "task.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_tent.h"
#include "constants/frontier_util.h"
#include "constants/layouts.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/factory_pools.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/rgb.h"
#include "data/battle_frontier/facility_classes_types.h"

EWRAM_DATA u16 gBattleFactoryInitialOfferMonIds[BATTLE_FACTORY_INITIAL_OFFER_COUNT];

static bool8 sPerformedRentalSwap;
static struct Pokemon sFactoryRewardBuffer;
static struct Pokemon sFactoryRunRewardChoices[FRONTIER_PARTY_SIZE];
static u8 sFactoryRunRewardChoiceCount;
static u8 sLastGeneratedFactoryBossId;
static u8 sPendingFactoryRewardBossId;
extern const u8 BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript[];
extern const u8 BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript[];
static bool8 sFactoryPoolsReady = FALSE;

static void InitFactoryChallenge(void);
static void GetBattleFactoryData(void);
static void SetBattleFactoryData(void);
static void SaveFactoryChallenge(void);
static void FactoryDummy1(void);
static void FactoryDummy2(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void SetPerformedRentalSwap(void);
static void SetRentalsToOpponentParty(void);
static void SetPlayerAndOpponentParties(void);
static void SetOpponentGfxVar(void);
static void GenerateOpponentMons(void);
static void GenerateInitialRentalMons(void);
static void GetOpponentMostCommonMonType(void);
static void GetOpponentBattleStyle(void);
static void RestorePlayerPartyHeldItems(void);
static u16 GetFactoryMonId(enum FrontierLevelMode lvlMode, u8 challengeNum, bool8 useBetterRange);
static enum FactoryStyle GetMoveBattleStyle(enum Move move);
void DebugAction_FactoryWinChallenge(void);
void DebugAction_TriggerNolandBattle(void);
void DebugAction_TriggerStevenBattle(void);
void DebugAction_TriggerFactoryBoss(u8 bossId);
const u8 *GetFacilityClassTypeWhitelist(u8 facilityClass, u8 *count);
static void SelectRewardMonFromParty(void);
static void GiveRewardMonFromParty(void);
static void CB2_GiveReward(void);
static void CB2_HandleFactoryRunRewardSelection(void);
static bool8 CanUseFactoryBrainMonId(u16 monId, s32 partyCount, const u16 *species, const u16 *heldItems);
static bool8 IsRewardCandidateUsable(struct Pokemon *mon);
static bool8 TryUseBossPartyFallbackReward(u8 bossId, struct Pokemon *outMon);
static bool8 TryBuildBossAceSpeciesFallbackReward(u8 bossId, enum FrontierLevelMode lvlMode, struct Pokemon *outMon);

// Number of moves needed on the team to be considered using a certain battle style
static const u8 sRequiredMoveCounts[FACTORY_NUM_STYLES - 1] = {
    [FACTORY_STYLE_PREPARATION - 1]   = 3,
    [FACTORY_STYLE_SLOW_STEADY - 1]   = 3,
    [FACTORY_STYLE_ENDURANCE - 1]     = 3,
    [FACTORY_STYLE_HIGH_RISK - 1]     = 2,
    [FACTORY_STYLE_WEAKENING - 1]     = 2,
    [FACTORY_STYLE_UNPREDICTABLE - 1] = 2,
    [FACTORY_STYLE_WEATHER - 1]       = 2
};
static const enum Move sMoves_TotalPreparation[] =
{
    MOVE_SWORDS_DANCE, MOVE_GROWTH, MOVE_MEDITATE, MOVE_AGILITY, MOVE_DOUBLE_TEAM, MOVE_HARDEN,
    MOVE_MINIMIZE, MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_BARRIER, MOVE_FOCUS_ENERGY, MOVE_AMNESIA,
    MOVE_ACID_ARMOR, MOVE_SHARPEN, MOVE_CONVERSION, MOVE_CONVERSION_2, MOVE_BELLY_DRUM, MOVE_PSYCH_UP,
    MOVE_CHARGE, MOVE_SNATCH, MOVE_TAIL_GLOW, MOVE_COSMIC_POWER, MOVE_IRON_DEFENSE, MOVE_HOWL, MOVE_BULK_UP, MOVE_CALM_MIND, MOVE_DRAGON_DANCE,
    MOVE_NONE
};

static const enum Move sMoves_ImpossibleToPredict[] =
{
    MOVE_MIMIC, MOVE_METRONOME, MOVE_MIRROR_MOVE, MOVE_TRANSFORM, MOVE_SUBSTITUTE, MOVE_SKETCH, MOVE_CURSE,
    MOVE_PRESENT, MOVE_FOLLOW_ME, MOVE_TRICK, MOVE_ROLE_PLAY, MOVE_ASSIST, MOVE_SKILL_SWAP, MOVE_CAMOUFLAGE,
    MOVE_NONE
};

static const enum Move sMoves_WeakeningTheFoe[] =
{
    MOVE_SAND_ATTACK, MOVE_TAIL_WHIP, MOVE_LEER, MOVE_GROWL, MOVE_STRING_SHOT, MOVE_SCREECH, MOVE_SMOKESCREEN, MOVE_KINESIS,
    MOVE_FLASH, MOVE_COTTON_SPORE, MOVE_SPITE, MOVE_SCARY_FACE, MOVE_CHARM, MOVE_KNOCK_OFF, MOVE_SWEET_SCENT, MOVE_FEATHER_DANCE,
    MOVE_FAKE_TEARS, MOVE_METAL_SOUND, MOVE_TICKLE,
    MOVE_NONE
};

static const enum Move sMoves_HighRiskHighReturn[] =
{
    MOVE_GUILLOTINE, MOVE_HORN_DRILL, MOVE_DOUBLE_EDGE, MOVE_HYPER_BEAM, MOVE_COUNTER, MOVE_FISSURE,
    MOVE_BIDE, MOVE_SELF_DESTRUCT, MOVE_SKY_ATTACK, MOVE_EXPLOSION, MOVE_FLAIL, MOVE_REVERSAL, MOVE_DESTINY_BOND,
    MOVE_PERISH_SONG, MOVE_PAIN_SPLIT, MOVE_MIRROR_COAT, MOVE_MEMENTO, MOVE_GRUDGE, MOVE_FACADE, MOVE_FOCUS_PUNCH,
    MOVE_BLAST_BURN, MOVE_HYDRO_CANNON, MOVE_OVERHEAT, MOVE_FRENZY_PLANT, MOVE_PSYCHO_BOOST, MOVE_VOLT_TACKLE,
    MOVE_NONE
};

static const enum Move sMoves_Endurance[] =
{
    MOVE_MIST, MOVE_RECOVER, MOVE_LIGHT_SCREEN, MOVE_HAZE, MOVE_REFLECT, MOVE_SOFT_BOILED, MOVE_REST, MOVE_PROTECT,
    MOVE_DETECT, MOVE_ENDURE, MOVE_MILK_DRINK, MOVE_HEAL_BELL, MOVE_SAFEGUARD, MOVE_BATON_PASS, MOVE_MORNING_SUN,
    MOVE_SYNTHESIS, MOVE_MOONLIGHT, MOVE_SWALLOW, MOVE_WISH, MOVE_INGRAIN, MOVE_MAGIC_COAT, MOVE_RECYCLE, MOVE_REFRESH,
    MOVE_MUD_SPORT, MOVE_SLACK_OFF, MOVE_AROMATHERAPY, MOVE_WATER_SPORT,
    MOVE_NONE
};

static const enum Move sMoves_SlowAndSteady[] =
{
    MOVE_SING, MOVE_SUPERSONIC, MOVE_DISABLE, MOVE_LEECH_SEED, MOVE_POISON_POWDER, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER,
    MOVE_THUNDER_WAVE, MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_CONFUSE_RAY, MOVE_GLARE, MOVE_POISON_GAS, MOVE_LOVELY_KISS, MOVE_SPORE,
    MOVE_SPIDER_WEB, MOVE_SWEET_KISS, MOVE_SPIKES, MOVE_SWAGGER, MOVE_MEAN_LOOK, MOVE_ATTRACT, MOVE_ENCORE, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_WILL_O_WISP, MOVE_TAUNT, MOVE_YAWN, MOVE_IMPRISON, MOVE_SNATCH, MOVE_TEETER_DANCE, MOVE_GRASS_WHISTLE, MOVE_BLOCK,
    MOVE_NONE
};

static const enum Move sMoves_DependsOnTheBattlesFlow[] =
{
    MOVE_SANDSTORM, MOVE_RAIN_DANCE, MOVE_SUNNY_DAY, MOVE_HAIL, MOVE_WEATHER_BALL,
    MOVE_NONE
};

// Excludes FACTORY_STYLE_NONE
static const enum Move *const sMoveStyles[FACTORY_NUM_STYLES - 1] =
{
    [FACTORY_STYLE_PREPARATION - 1]   = sMoves_TotalPreparation,
    [FACTORY_STYLE_SLOW_STEADY - 1]   = sMoves_SlowAndSteady,
    [FACTORY_STYLE_ENDURANCE - 1]     = sMoves_Endurance,
    [FACTORY_STYLE_HIGH_RISK - 1]     = sMoves_HighRiskHighReturn,
    [FACTORY_STYLE_WEAKENING - 1]     = sMoves_WeakeningTheFoe,
    [FACTORY_STYLE_UNPREDICTABLE - 1] = sMoves_ImpossibleToPredict,
    [FACTORY_STYLE_WEATHER - 1]       = sMoves_DependsOnTheBattlesFlow,
};

static void (*const sBattleFactoryFunctions[])(void) =
{
    [BATTLE_FACTORY_FUNC_INIT]                   = InitFactoryChallenge,
    [BATTLE_FACTORY_FUNC_GET_DATA]               = GetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SET_DATA]               = SetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SAVE]                   = SaveFactoryChallenge,
    [BATTLE_FACTORY_FUNC_NULL]                   = FactoryDummy1,
    [BATTLE_FACTORY_FUNC_NULL2]                  = FactoryDummy2,
    [BATTLE_FACTORY_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [BATTLE_FACTORY_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [BATTLE_FACTORY_FUNC_SET_SWAPPED]            = SetPerformedRentalSwap,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_MONS]      = SetRentalsToOpponentParty,
    [BATTLE_FACTORY_FUNC_SET_PARTIES]            = SetPlayerAndOpponentParties,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_GFX]       = SetOpponentGfxVar,
    [BATTLE_FACTORY_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [BATTLE_FACTORY_FUNC_GENERATE_RENTAL_MONS]   = GenerateInitialRentalMons,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_MON_TYPE]  = GetOpponentMostCommonMonType,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_STYLE]     = GetOpponentBattleStyle,
    [BATTLE_FACTORY_FUNC_RESET_HELD_ITEMS]       = RestorePlayerPartyHeldItems,
    [BATTLE_FACTORY_FUNC_SELECT_REWARD_MON]      = SelectRewardMonFromParty,
    [BATTLE_FACTORY_FUNC_GIVE_REWARD_MON]        = GiveRewardMonFromParty
};

static const u32 sWinStreakFlags[FRONTIER_MODE_COUNT][2] =
{
    [FRONTIER_MODE_SINGLES] = {STREAK_FACTORY_SINGLES_50, STREAK_FACTORY_SINGLES_OPEN},
    [FRONTIER_MODE_DOUBLES] = {STREAK_FACTORY_DOUBLES_50, STREAK_FACTORY_DOUBLES_OPEN},
    // Not supported for the Factory, but keep safe values for any debug/incorrect state.
    [FRONTIER_MODE_MULTIS] = {0, 0},
    [FRONTIER_MODE_LINK_MULTIS] = {0, 0},
};

static const u32 sWinStreakMasks[FRONTIER_MODE_COUNT][2] =
{
    [FRONTIER_MODE_SINGLES] = {~(STREAK_FACTORY_SINGLES_50), ~(STREAK_FACTORY_SINGLES_OPEN)},
    [FRONTIER_MODE_DOUBLES] = {~(STREAK_FACTORY_DOUBLES_50), ~(STREAK_FACTORY_DOUBLES_OPEN)},
    [FRONTIER_MODE_MULTIS] = {~0u, ~0u},
    [FRONTIER_MODE_LINK_MULTIS] = {~0u, ~0u},
};

static const u8 sFixedIVTable[][2] =
{
    {3, 6},
    {6, 9},
    {9, 12},
    {12, 15},
    {15, 18},
    {21, 31},
    {31, 31},
    {31, 31},
};

// code
static void EnsureFactoryPoolsReady(void)
{
    if (!sFactoryPoolsReady)
    {
        InitFactoryRankPools();
        sFactoryPoolsReady = TRUE;
    }
}

bool8 IsBattleFactoryRandomBattlesModeEnabled(void)
{
    return (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT
         && FlagGet(FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE));
}

u8 GetBattleFactoryMonLevel(u16 monId)
{
    u8 defaultLevel;

    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
        return TENT_MIN_LEVEL;

    defaultLevel = (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
        ? FRONTIER_MAX_LEVEL_OPEN
        : FRONTIER_MAX_LEVEL_50;

    if (IsBattleFactoryRandomBattlesModeEnabled())
    {
        // Some legacy non-randbats entries can have lvl 0; fall back to normal facility level.
        if (gBattleFrontierMons[monId].lvl != 0)
            return gBattleFrontierMons[monId].lvl;
        return defaultLevel;
    }

    return defaultLevel;
}

void CallBattleFactoryFunction(void)
{
    DebugPrintf("🚩 CallBattleFactoryFunction: index = %d", gSpecialVar_0x8004);
    sBattleFactoryFunctions[gSpecialVar_0x8004]();
}

static void InitFactoryChallenge(void) {
    DebugPrintf("Battle Factory init");
    u8 i;
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    EnsureFactoryPoolsReady();

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (!(gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
    {
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
        gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = 0;
    }

    sPerformedRentalSwap = FALSE;
    for (i = 0; i < ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); i++)
        gSaveBlock2Ptr->frontier.rentalMons[i].monId = 0xFFFF;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        gFrontierTempParty[i] = 0xFFFF;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    TRAINER_BATTLE_PARAM.opponentA = 0;
    sLastGeneratedFactoryBossId = FACTORY_BOSS_NONE;
    sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
    sFactoryRunRewardChoiceCount = 0;
    ZeroMonData(&sFactoryRewardBuffer);
    VarSet(VAR_FACTORY_LAST_DEFEATED_BOSS, FACTORY_BOSS_NONE);
    SetFactoryDebugStevenBossEnabled(FALSE);
}

static void GetBattleFactoryData(void) {
    DebugPrintf("GetBattleFactoryData");

    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]) != 0);
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
        break;
    }
}

static void SetBattleFactoryData(void) {
    DebugPrintf("SetBattleFactoryData");

    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        if (sPerformedRentalSwap == TRUE)
        {
            gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = gSpecialVar_0x8006;
            sPerformedRentalSwap = FALSE;
        }
        break;
    }
}

static void SaveFactoryChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void FactoryDummy1(void)
{

}

static void FactoryDummy2(void)
{

}

static void SelectInitialRentalMons(void) {
    DebugPrintf("SelectInitialRentalMons");
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

static void SetPerformedRentalSwap(void)
{
    sPerformedRentalSwap = TRUE;
}

static void GenerateOpponentMons(void)
{
    int i, j, k;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    u16 trainerId = 0;
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    u32 challengeNum = winStreak / FRONTIER_STAGES_PER_CHALLENGE;
    gFacilityTrainers = gBattleFrontierTrainers;

    do
    {
        // Choose a random trainer, ensuring no repeats in this challenge
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    TRAINER_BATTLE_PARAM.opponentA = trainerId;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < FRONTIER_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;

    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);

        // Unown (FRONTIER_MON_UNOWN) is forbidden on opponent Factory teams.
        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        // Ensure none of the opponent's Pokémon are the same as the potential rental Pokémon for the player.
        // Offers are 12-wide; only 6 are persisted in save (for historical reasons).
        for (j = 0; j < (int)BATTLE_FACTORY_INITIAL_OFFER_COUNT; j++)
        {
            u16 offerMonId = gBattleFactoryInitialOfferMonIds[j];
            if (offerMonId != 0xFFFF
             && gFacilityTrainerMons[monId].species == gFacilityTrainerMons[offerMonId].species)
                break;
        }
        if (j != (int)BATTLE_FACTORY_INITIAL_OFFER_COUNT)
            continue;

        // Ensure this species hasn't already been chosen for the opponent
        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != i)
            continue;

        // Ensure held items don't repeat on the opponent's team
        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gFacilityTrainerMons[monId].heldItem)
                break;
        }
        if (k != i)
            continue;

        // Successful selection
        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gFacilityTrainerMons[monId].heldItem;
        gFrontierTempParty[i] = monId;
        i++;
    }
}

static void SetOpponentGfxVar(void)
{
    SetBattleFacilityTrainerGfxId(TRAINER_BATTLE_PARAM.opponentA, 0);
}

static void SetRentalsToOpponentParty(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId = gFrontierTempParty[i];
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ATK_IV);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality = GetMonData(&gEnemyParty[i], MON_DATA_PERSONALITY);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ABILITY_NUM);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gFacilityTrainerMons[gFrontierTempParty[i]].heldItem);
    }
}

static void SetPlayerAndOpponentParties(void)
{
    int i;
    u16 monId;
    u8 ivs;

    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        gFacilityTrainerMons = gSlateportBattleTentMons;
    }
    else
    {
        gFacilityTrainerMons = gBattleFrontierMons;
    }

    if (gSpecialVar_0x8005 < 2)
    {
        ZeroPlayerPartyMons();
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i].ivs;

            CreateFacilityMon(&gFacilityTrainerMons[monId], GetBattleFactoryMonLevel(monId), ivs, READ_OTID_FROM_SAVE, FLAG_FRONTIER_MON_FACTORY, &gPlayerParty[i]);
        }
    }

    switch (gSpecialVar_0x8005)
    {
    case 0:
    case 2:
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs;
            CreateFacilityMon(&gFacilityTrainerMons[monId], GetBattleFactoryMonLevel(monId), ivs, READ_OTID_FROM_SAVE, FLAG_FRONTIER_MON_FACTORY, &gEnemyParty[i]);
        }
        break;
    }
}

static void GenerateInitialRentalMons(void)
{
    for (int idx = 0; idx < (int)BATTLE_FACTORY_INITIAL_OFFER_COUNT; idx++)
        gBattleFactoryInitialOfferMonIds[idx] = 0xFFFF;

	    int i;
	    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
	    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
	    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
	    u8 rentalRank = GetNumPastRentalsRank(battleMode, lvlMode);
	    enum FrontierLevelMode factoryLvlMode = (lvlMode != FRONTIER_LVL_50) ? FRONTIER_LVL_OPEN : FRONTIER_LVL_50;
	    u16 monId;
	    u16 species[BATTLE_FACTORY_INITIAL_OFFER_COUNT];
	    u16 heldItems[BATTLE_FACTORY_INITIAL_OFFER_COUNT];

    DebugPrintf("GenerateInitialRentalMons");
    DebugPrintf("challengeNum = %d (streak = %d)", challengeNum, gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]);

    gFacilityTrainerMons = gBattleFrontierMons;

    for (i = 0; i < (int)BATTLE_FACTORY_INITIAL_OFFER_COUNT; i++)
    {
        species[i] = SPECIES_NONE;
        heldItems[i] = ITEM_NONE;
    }

    i = 0;
    int retry = 0;

    while (i < (int)BATTLE_FACTORY_INITIAL_OFFER_COUNT && retry < 5000)
    {
        retry++;

        bool8 useBetterRange = (i < rentalRank);
        monId = GetFactoryMonId(factoryLvlMode, challengeNum, useBetterRange);

        u16 thisSpecies = gBattleFrontierMons[monId].species;
        u16 item = gBattleFrontierMons[monId].heldItem;

        DebugPrintf("Trying monId %d: species=%d, item=%d", monId, thisSpecies, item);

        // Skip Unown
        if (thisSpecies == SPECIES_UNOWN)
        {
            DebugPrintf("❌ Skipped: Unown");
            continue;
        }

        // Check duplicate species
        bool8 dupSpecies = FALSE;
        for (int j = 0; j < i; j++)
        {
            if (thisSpecies == species[j])
            {
                dupSpecies = TRUE;
                break;
            }
        }
        if (dupSpecies)
        {
            DebugPrintf("❌ Skipped: Duplicate species");
            continue;
        }

        // Check duplicate held items
        bool8 dupItem = FALSE;
        for (int j = 0; j < i; j++)
        {
            if (item != ITEM_NONE && heldItems[j] == item)
            {
                dupItem = TRUE;
                break;
            }
        }
        if (dupItem)
        {
            DebugPrintf("❌ Skipped: Duplicate held item");
            continue;
        }

        // ✅ Passed all checks
        species[i] = thisSpecies;
        heldItems[i] = item;
        gBattleFactoryInitialOfferMonIds[i] = monId;
        if (i < PARTY_SIZE)
            gSaveBlock2Ptr->frontier.rentalMons[i].monId = monId;
        DebugPrintf("✅ Selected monId %d", monId);
        i++;
    }

    if (retry >= 5000)
        DebugPrintf("‼️ Rental loop bailed out after 5000 attempts.");
}


// Determines if the upcoming opponent has a single most-common
// type in its party. If there are two different types that are
// tied, then the opponent is deemed to have no preferred type,
// and NUMBER_OF_MON_TYPES is the result.
static void GetOpponentMostCommonMonType(void)
{
    u8 i;
    u8 typeCounts[NUMBER_OF_MON_TYPES];
    u8 mostCommonTypes[2];

    gFacilityTrainerMons = gBattleFrontierMons;

    // Count the number of times each type occurs in the opponent's party.
    for (i = TYPE_NORMAL; i < NUMBER_OF_MON_TYPES; i++)
        typeCounts[i] = 0;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u32 species = gFacilityTrainerMons[gFrontierTempParty[i]].species;
        typeCounts[GetSpeciesType(species, 0)]++;
        if (GetSpeciesType(species, 0) != GetSpeciesType(species, 1))
            typeCounts[GetSpeciesType(species, 1)]++;
    }

    // Determine which are the two most-common types.
    // The second most-common type is only updated if
    // its count is equal to the most-common type.
    mostCommonTypes[0] = 0;
    mostCommonTypes[1] = 0;
    for (i = 1; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (typeCounts[mostCommonTypes[0]] < typeCounts[i])
            mostCommonTypes[0] = i;
        else if (typeCounts[mostCommonTypes[0]] == typeCounts[i])
            mostCommonTypes[1] = i;
    }

    if (typeCounts[mostCommonTypes[0]] != 0)
    {
        // The most-common type must be strictly greater than
        // the second-most-common type, or the top two must be
        // the same type.
        if (typeCounts[mostCommonTypes[0]] > typeCounts[mostCommonTypes[1]])
            gSpecialVar_Result = mostCommonTypes[0];
        else if (mostCommonTypes[0] == mostCommonTypes[1])
            gSpecialVar_Result = mostCommonTypes[0];
        else
            gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
    else
    {
        gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
}

static void GetOpponentBattleStyle(void)
{
    u8 i, j, count;
    u8 stylePoints[FACTORY_NUM_STYLES];

    count = 0;
    gFacilityTrainerMons = gBattleFrontierMons;
    for (i = 0; i < FACTORY_NUM_STYLES; i++)
        stylePoints[i] = 0;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            u8 battleStyle = GetMoveBattleStyle(gFacilityTrainerMons[monId].moves[j]);
            stylePoints[battleStyle]++;
        }
    }

    gSpecialVar_Result = FACTORY_STYLE_NONE;
    for (i = 1; i < FACTORY_NUM_STYLES; i++)
    {
        if (stylePoints[i] >= sRequiredMoveCounts[i - 1])
        {
            gSpecialVar_Result = i;
            count++;
        }
    }

    // Has no singular style
    if (count > 2)
        gSpecialVar_Result = FACTORY_NUM_STYLES;
}

static enum FactoryStyle GetMoveBattleStyle(enum Move move)
{
    enum FactoryStyle style = gBattleMoveEffects[GetMoveEffect(move)].battleFactoryStyle;

    if (style != FACTORY_STYLE_NONE)
        return style;

    // Conditional effects
    switch (GetMoveEffect(move))
    {
    case EFFECT_TWO_TURNS_ATTACK:
        // Potential to miss a two-turn move
        if (GetMoveAccuracy(move) < 100 && GetMoveAccuracy(move) != 0)
            return FACTORY_STYLE_HIGH_RISK;
        break;
    case EFFECT_RECOIL:
        // Only higher recoil moves are considered risky
        if (GetMoveRecoil(move) >= 33)
            return FACTORY_STYLE_HIGH_RISK;
        break;
    default:
        break;
    }
    // Bad secondary effects for the user
    if (MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_RECHARGE)
     || MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_SP_ATK_MINUS_2))
        return FACTORY_STYLE_HIGH_RISK;

    // Non-volatile effects
    if (GetMoveNonVolatileStatus(move) != MOVE_EFFECT_NONE)
        return FACTORY_STYLE_SLOW_STEADY;

    if (IsExplosionMove(move))
        return FACTORY_STYLE_SLOW_STEADY;

    return FACTORY_STYLE_NONE;
}

bool8 InBattleFactory(void)
{
    return gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM;
}

static void RestorePlayerPartyHeldItems(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        SetMonData(&gPlayerParty[i],
                   MON_DATA_HELD_ITEM,
                   &gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[i].monId].heldItem);
    }
}

// Get the IV to use for the opponent's pokémon.
// The IVs get higher for each subsequent challenge and for
// the last trainer in each challenge. Noland is an exception
// to this, as he uses the IVs that would be used by the regular
// trainers 2 challenges ahead of the current one.
// Due to a mistake in FillFactoryFrontierTrainerParty, the
// challenge number used to determine the IVs for regular trainers
// is Battle Tower's instead of Battle Factory's.
u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle)
{
    u8 ivSet;
    bool8 useHigherIV = isLastBattle ? TRUE : FALSE;

// The Factory has an out-of-bounds access when generating the rental draft for round 9 (challengeNum==8),
// or the "elevated" rentals from round 8 (challengeNum+1==8)
// This happens to land on a number higher than 31, which is interpreted as "random IVs"
#ifdef BUGFIX
    if (challengeNum >= ARRAY_COUNT(sFixedIVTable))
#else
    if (challengeNum > ARRAY_COUNT(sFixedIVTable))
#endif
        ivSet = ARRAY_COUNT(sFixedIVTable) - 1;
    else
        ivSet = challengeNum;

    return sFixedIVTable[ivSet][useHigherIV];
}

static bool8 DoesSpeciesMatchAllowedBossTypes(u16 species, const enum Type allowedTypes[static 2])
{
    enum Type type1, type2;

    if (allowedTypes[0] == TYPE_NONE && allowedTypes[1] == TYPE_NONE)
        return TRUE;

    species = SanitizeSpeciesId(species);
    type1 = gSpeciesInfo[species].types[0];
    type2 = gSpeciesInfo[species].types[1];

    if (allowedTypes[0] != TYPE_NONE && (type1 == allowedTypes[0] || type2 == allowedTypes[0]))
        return TRUE;

    if (allowedTypes[1] != TYPE_NONE && (type1 == allowedTypes[1] || type2 == allowedTypes[1]))
        return TRUE;

    return FALSE;
}

void FillFactoryBrainParty(void)
{
    int i;
    s32 aceSlot = -1;
    const bool8 isSingles = (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_SINGLES);
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    const struct FactoryBossProfile *bossProfile = GetActiveFactoryBossProfile();
    bool8 enforceBossTypes = (bossProfile != NULL
        && (bossProfile->allowedTypes[0] != TYPE_NONE || bossProfile->allowedTypes[1] != TYPE_NONE));
    u32 typeEnforcementAttempts = 0;
    sLastGeneratedFactoryBossId = GetActiveFactoryBossId();
    const bool8 hasBossAce = (bossProfile != NULL
        && (bossProfile->acePolicy == FACTORY_BOSS_ACE_SPECIES_ANCHOR_LAST
         || bossProfile->acePolicy == FACTORY_BOSS_ACE_SPECIES_ANCHOR_FIRST)
        && bossProfile->aceSpecies != SPECIES_NONE);
    const u16 bossAceMonId = hasBossAce
        ? ChooseFactoryBossAceMonId(bossProfile,
                                    gFacilityTrainerMons,
                                    gSaveBlock2Ptr->frontier.rentalMons)
        : 0xFFFF;
    u8 fixedIV;
    u32 otId;

    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    fixedIV = GetFactoryMonFixedIV(challengeNum + 2, FALSE);
    i = 0;
    otId = READ_OTID_FROM_SAVE;

    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId;

        if (enforceBossTypes && ++typeEnforcementAttempts > 5000)
        {
            // Avoid extremely long generation loops if a type theme is too restrictive for the active pool.
            enforceBossTypes = FALSE;
            typeEnforcementAttempts = 0;
            DebugPrintf("Boss type restriction fallback: disabling type filter for bossId=%d", sLastGeneratedFactoryBossId);
        }

        monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);

        if (enforceBossTypes
            && !DoesSpeciesMatchAllowedBossTypes(gFacilityTrainerMons[monId].species, bossProfile->allowedTypes))
            continue;

        if (!CanUseFactoryBrainMonId(monId, i, species, heldItems))
            continue;

        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gFacilityTrainerMons[monId].heldItem;
        CreateFacilityMon(&gFacilityTrainerMons[monId],
                GetBattleFactoryMonLevel(monId), fixedIV, otId, FLAG_FRONTIER_MON_FACTORY,
                &gEnemyParty[i]);
        i++;
    }

    // Keep normal stable generation, then promote the configured boss ace into the configured anchor slot when possible.
    if (hasBossAce
        && bossAceMonId != 0xFFFF)
    {
        aceSlot = (bossProfile->acePolicy == FACTORY_BOSS_ACE_SPECIES_ANCHOR_FIRST)
            ? 0
            : FRONTIER_PARTY_SIZE - 1;

        // In standard singles mode, prefer a boss's reward build as its ace template.
        if (isSingles && BuildFactoryBossRewardMon(sLastGeneratedFactoryBossId, lvlMode, &gEnemyParty[aceSlot]))
        {
            species[aceSlot] = GetMonData(&gEnemyParty[aceSlot], MON_DATA_SPECIES);
            heldItems[aceSlot] = GetMonData(&gEnemyParty[aceSlot], MON_DATA_HELD_ITEM);
            return;
        }

        if (!FactoryBossCanUseAceMonIdForSlot(gFacilityTrainerMons,
                                              gSaveBlock2Ptr->frontier.rentalMons,
                                              bossAceMonId,
                                              aceSlot,
                                              species,
                                              heldItems))
            return;

        if (!BuildFactoryBossAceMon(sLastGeneratedFactoryBossId, GetBattleFactoryMonLevel(bossAceMonId), fixedIV, &gEnemyParty[aceSlot]))
        {
            CreateFacilityMon(&gFacilityTrainerMons[bossAceMonId],
                    GetBattleFactoryMonLevel(bossAceMonId), fixedIV, otId, FLAG_FRONTIER_MON_FACTORY,
                    &gEnemyParty[aceSlot]);
        }

        species[aceSlot] = GetMonData(&gEnemyParty[aceSlot], MON_DATA_SPECIES);
        heldItems[aceSlot] = GetMonData(&gEnemyParty[aceSlot], MON_DATA_HELD_ITEM);
    }
}

static bool8 CanUseFactoryBrainMonId(u16 monId, s32 partyCount, const u16 *species, const u16 *heldItems)
{
    s32 j, k;

    if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
        return FALSE;

    for (j = 0; j < ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
    {
        if (monId == gSaveBlock2Ptr->frontier.rentalMons[j].monId)
            return FALSE;
    }

    for (k = 0; k < partyCount; k++)
    {
        if (species[k] == gFacilityTrainerMons[monId].species)
            return FALSE;
    }

    for (k = 0; k < partyCount; k++)
    {
        if (heldItems[k] != ITEM_NONE && heldItems[k] == gFacilityTrainerMons[monId].heldItem)
            return FALSE;
    }

    return TRUE;
}

static const u16 *GetFactoryRentalPool(enum FrontierLevelMode lvlMode, u8 challengeNum, u16 *poolSize)
{
    (void)lvlMode;
    if (challengeNum < 1) {
        *poolSize = gFactoryPoolRank1Count;
        DebugPrintf("Using Rank 1 pool, size=%d", *poolSize);
        return sFactoryPoolRank1;
    } else if (challengeNum < 2) {
        *poolSize = gFactoryPoolRank2Count;
        DebugPrintf("Using Rank 2 pool, size=%d", *poolSize);
        return sFactoryPoolRank2;
    } else if (challengeNum < 3) {
        *poolSize = gFactoryPoolRank3Count;
        DebugPrintf("Using Rank 3 pool, size=%d", *poolSize);
        return sFactoryPoolRank3;
    } else {
        *poolSize = gFactoryPoolRank4Count;
        DebugPrintf("Using Rank 4 pool, size=%d", *poolSize);
        return sFactoryPoolRank4;
    }
}


static u16 GetFactoryMonId(enum FrontierLevelMode lvlMode, u8 challengeNum, bool8 useBetterRange)
{
    DebugPrintf("GetFactoryMonId");

    if (IsBattleFactoryRandomBattlesModeEnabled())
    {
        u16 monId = FRONTIER_MON_GEN9RANDOMBATTLE_FIRST + (Random() % FRONTIER_MON_GEN9RANDOMBATTLE_COUNT);
        DebugPrintf("BF randbats selected monId = %d", monId);
        return monId;
    }

    EnsureFactoryPoolsReady();

    u16 poolSize;
    const u16 *pool = GetFactoryRentalPool(lvlMode, challengeNum, &poolSize);

    DebugPrintf("lvlMode: %d", lvlMode);
    DebugPrintf("challengeNum: %d", challengeNum);
    DebugPrintf("poolSize: %d", poolSize);

    if (pool == NULL || poolSize == 0)
    {
        DebugPrintfLevel(MGBA_LOG_FATAL, "❌ No factory rental pool found for challengeNum=%d", challengeNum);
        return 0;
    }

    u16 monId = pool[Random() % poolSize];

    DebugPrintf("BF: selected monId = %d", monId);
    return monId;
}

u8 GetNumPastRentalsRank(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u8 ret;
    u8 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];

    if (rents < 15)
        ret = 0;
    else if (rents < 22)
        ret = 1;
    else if (rents < 29)
        ret = 2;
    else if (rents < 36)
        ret = 3;
    else if (rents < 43)
        ret = 4;
    else
        ret = 5;

    return ret;
}

u64 GetAiScriptsInBattleFactory(void)
{
    return AI_FLAG_SMART_TRAINER;
}

void SetMonMoveAvoidReturn(struct Pokemon *mon, enum Move moveArg, u8 moveSlot)
{
    enum Move move = moveArg;
    if (moveArg == MOVE_RETURN)
        move = MOVE_FRUSTRATION;
    SetMonMoveSlot(mon, move, moveSlot);
}

void DebugAction_FactoryWinChallenge(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    DebugPrintf("Complete factory challenge triggered");

    // Simulate full challenge win
    gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] += 7;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 6;
    gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = 0;
    gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];

    DebugPrintf("Simulated full Factory challenge win.");
    DebugPrintf("Total wins: %d → challengeNum: %d",
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode],
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE);

    // Now end the battle
    BattleDebug_WonBattle();
}

void DebugAction_TriggerNolandBattle(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode;

    if (!InBattleFactory())
    {
        DebugPrintf("Trigger Noland ignored (not in Battle Factory)");
        return;
    }

    // Force the expected Factory singles context for brain-status checks.
    VarSet(VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY);
    VarSet(VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES);
    battleMode = FRONTIER_MODE_SINGLES;

    // Queue the run state so the next battle is Noland:
    // after this forced win, streak becomes 20 and battleNum becomes 6.
    FlagSet(FLAG_BATTLE_FACTORY_DEBUG_FORCE_NOLAND);
    SetFactoryDebugStevenBossEnabled(FALSE);
    FlagClear(FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE);
    VarSet(VAR_FACTORY_ACTIVE_BOSS, FACTORY_BOSS_NONE);
    gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 19;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 5;
    gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];

    DebugPrintf("Noland trigger queued");
    DebugPrintf("Factory streak=%d, battleNum=%d",
                gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode],
                gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    BattleDebug_WonBattle();
}

void DebugAction_TriggerStevenBattle(void)
{
    DebugAction_TriggerFactoryBoss(FACTORY_BOSS_STEVEN);
}

void DebugAction_TriggerFactoryBoss(u8 bossId)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    const struct FactoryBossProfile *bossProfile = GetFactoryBossProfile(bossId);

    if (!InBattleFactory())
    {
        DebugPrintf("Trigger boss ignored (not in Battle Factory)");
        return;
    }

    if (bossProfile == NULL)
    {
        DebugPrintf("Trigger boss ignored (invalid bossId=%d)", bossId);
        return;
    }

    FlagClear(FLAG_BATTLE_FACTORY_DEBUG_FORCE_NOLAND);
    FlagClear(FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE);

    // Queue the run state so the next battle is the Frontier Brain, then skin it as the selected boss.
    VarSet(VAR_FACTORY_ACTIVE_BOSS, bossId);
    if (bossId == FACTORY_BOSS_STEVEN)
        FlagSet(FLAG_BATTLE_FACTORY_DEBUG_STEVEN_BOSS);
    else
        FlagClear(FLAG_BATTLE_FACTORY_DEBUG_STEVEN_BOSS);

    gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 19;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 5;
    gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];

    DebugPrintf("Boss trigger queued (bossId=%d, trainerId=%d)", bossId, bossProfile->trainerId);
    DebugPrintf("Factory streak=%d, battleNum=%d",
                gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode],
                gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    BattleDebug_WonBattle();
}

void SetPendingFactoryRewardBossFromActive(void)
{
    u8 bossId = GetActiveFactoryBossId();

    if (HasFactoryRewardForBossId(bossId))
        sPendingFactoryRewardBossId = bossId;
    else
        sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
}

void MarkAllFactorySpeciesAsSeen(void)
{
    for (int i = NUM_ORIGINAL_FRONTIER_MONS; i < NUM_FRONTIER_MONS; i++)
    {
        u16 species = gBattleFrontierMons[i].species;
        u16 nationalDexNo = SpeciesToNationalPokedexNum(species);

        if (nationalDexNo != 0)
            GetSetPokedexFlag(nationalDexNo, FLAG_SET_SEEN);
    }
}

static bool8 IsRewardCandidateUsable(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    return (!GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG)
         && species > SPECIES_NONE
         && species < NUM_SPECIES
         && IsSpeciesEnabled(species));
}

static bool8 TryUseBossPartyFallbackReward(u8 bossId, struct Pokemon *outMon)
{
    const struct FactoryBossProfile *bossProfile = GetFactoryBossProfile(bossId);
    u16 preferredSpecies = SPECIES_NONE;
    s8 firstValidIndex = -1;
    s8 preferredIndex = -1;
    u8 i;

    if (bossProfile != NULL)
        preferredSpecies = bossProfile->aceSpecies;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 species;

        if (!IsRewardCandidateUsable(&gEnemyParty[i]))
            continue;

        species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES);
        if (firstValidIndex < 0)
            firstValidIndex = i;
        if (preferredSpecies != SPECIES_NONE && species == preferredSpecies)
        {
            preferredIndex = i;
            break;
        }
    }

    if (preferredIndex >= 0)
        *outMon = gEnemyParty[(u8)preferredIndex];
    else if (firstValidIndex >= 0)
        *outMon = gEnemyParty[(u8)firstValidIndex];
    else
        return FALSE;

    return TRUE;
}

static bool8 TryBuildBossAceSpeciesFallbackReward(u8 bossId, enum FrontierLevelMode lvlMode, struct Pokemon *outMon)
{
    const struct FactoryBossProfile *bossProfile = GetFactoryBossProfile(bossId);
    u8 level;

    if (bossProfile == NULL
     || bossProfile->aceSpecies == SPECIES_NONE
     || !IsSpeciesEnabled(bossProfile->aceSpecies))
        return FALSE;

    switch (lvlMode)
    {
    case FRONTIER_LVL_TENT:
        level = TENT_MIN_LEVEL;
        break;
    case FRONTIER_LVL_50:
        level = FRONTIER_MAX_LEVEL_50;
        break;
    case FRONTIER_LVL_OPEN:
    default:
        level = FRONTIER_MAX_LEVEL_OPEN;
        break;
    }

    CreateRandomMonWithIVs(outMon, bossProfile->aceSpecies, level, MAX_PER_STAT_IVS);
    return IsRewardCandidateUsable(outMon);
}

static void SelectRewardMonFromParty(void)
{
    u8 resolvedBossId = FACTORY_BOSS_NONE;

    DebugPrintf("SelectRewardMonFromParty: activeBoss=%d lastBoss=%d pendingBoss=%d",
                GetActiveFactoryBossId(),
                sLastGeneratedFactoryBossId,
                sPendingFactoryRewardBossId);

    resolvedBossId = sPendingFactoryRewardBossId;
    if (resolvedBossId == FACTORY_BOSS_NONE)
        resolvedBossId = VarGet(VAR_FACTORY_LAST_DEFEATED_BOSS);
    if (resolvedBossId == FACTORY_BOSS_NONE)
        resolvedBossId = GetFactoryRewardBossId(GetActiveFactoryBossId(), sLastGeneratedFactoryBossId);
    if (!HasFactoryRewardForBossId(resolvedBossId))
    {
        u8 i;

        DebugPrintf("No boss reward for bossId=%d; opening run reward selection", resolvedBossId);
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            sFactoryRunRewardChoices[i] = gPlayerParty[i];
        sFactoryRunRewardChoiceCount = FRONTIER_PARTY_SIZE;

        sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
        VarSet(VAR_FACTORY_LAST_DEFEATED_BOSS, FACTORY_BOSS_NONE);
        DoBattleFactoryRewardScreen(sFactoryRunRewardChoices, sFactoryRunRewardChoiceCount, CB2_HandleFactoryRunRewardSelection);
        return;
    }

    if (!BuildFactoryBossRewardMon(resolvedBossId,
                                   gSaveBlock2Ptr->frontier.lvlMode,
                                   &sFactoryRewardBuffer))
    {
        DebugPrintfLevel(MGBA_LOG_WARN, "Failed to build reward for bossId=%d; trying fallback candidates", resolvedBossId);
        if (!TryUseBossPartyFallbackReward(resolvedBossId, &sFactoryRewardBuffer)
         && !TryBuildBossAceSpeciesFallbackReward(resolvedBossId,
                                                  gSaveBlock2Ptr->frontier.lvlMode,
                                                  &sFactoryRewardBuffer))
        {
            u8 i;

            DebugPrintfLevel(MGBA_LOG_WARN, "No valid fallback reward for bossId=%d; using run reward selection", resolvedBossId);
            for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
                sFactoryRunRewardChoices[i] = gPlayerParty[i];
            sFactoryRunRewardChoiceCount = FRONTIER_PARTY_SIZE;

            sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
            VarSet(VAR_FACTORY_LAST_DEFEATED_BOSS, FACTORY_BOSS_NONE);
            DoBattleFactoryRewardScreen(sFactoryRunRewardChoices, sFactoryRunRewardChoiceCount, CB2_HandleFactoryRunRewardSelection);
            return;
        }
    }

    if (!IsFactoryRewardMonValid(&sFactoryRewardBuffer, resolvedBossId))
    {
        if ((!TryUseBossPartyFallbackReward(resolvedBossId, &sFactoryRewardBuffer)
          || !IsFactoryRewardMonValid(&sFactoryRewardBuffer, resolvedBossId))
         && (!TryBuildBossAceSpeciesFallbackReward(resolvedBossId,
                                                   gSaveBlock2Ptr->frontier.lvlMode,
                                                   &sFactoryRewardBuffer)
          || !IsFactoryRewardMonValid(&sFactoryRewardBuffer, resolvedBossId)))
        {
            u8 i;

            DebugPrintfLevel(MGBA_LOG_WARN, "Built invalid reward for bossId=%d; using run reward selection", resolvedBossId);
            for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
                sFactoryRunRewardChoices[i] = gPlayerParty[i];
            sFactoryRunRewardChoiceCount = FRONTIER_PARTY_SIZE;

            sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
            VarSet(VAR_FACTORY_LAST_DEFEATED_BOSS, FACTORY_BOSS_NONE);
            DoBattleFactoryRewardScreen(sFactoryRunRewardChoices, sFactoryRunRewardChoiceCount, CB2_HandleFactoryRunRewardSelection);
            return;
        }
    }

    sPendingFactoryRewardBossId = resolvedBossId;
    sFactoryRunRewardChoices[0] = sFactoryRewardBuffer;
    sFactoryRunRewardChoiceCount = 1;
    DoBattleFactoryRewardScreen(sFactoryRunRewardChoices, sFactoryRunRewardChoiceCount, CB2_HandleFactoryRunRewardSelection);
}

static void GiveRewardMonFromParty(void)
{
    SetMainCallback2(CB2_GiveReward);
    gMain.savedCallback = CB2_GiveReward;
}

static void CB2_HandleFactoryRunRewardSelection(void)
{
    u8 selectedIdx = gSpecialVar_Result;

    if (sPendingFactoryRewardBossId != FACTORY_BOSS_NONE)
    {
        // Boss-reward path (currently single choice shown). Keep/rebuild the prepared reward mon.
        if (!IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId)
         && (!BuildFactoryBossRewardMon(sPendingFactoryRewardBossId,
                                        gSaveBlock2Ptr->frontier.lvlMode,
                                        &sFactoryRewardBuffer)
          || !IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId))
         && (!TryUseBossPartyFallbackReward(sPendingFactoryRewardBossId, &sFactoryRewardBuffer)
          || !IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId))
         && (!TryBuildBossAceSpeciesFallbackReward(sPendingFactoryRewardBossId,
                                                   gSaveBlock2Ptr->frontier.lvlMode,
                                                   &sFactoryRewardBuffer)
          || !IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId)))
        {
            DebugPrintfLevel(MGBA_LOG_WARN, "Boss reward became invalid before grant (bossId=%d)", sPendingFactoryRewardBossId);
            sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
            sFactoryRunRewardChoiceCount = 0;
            VarSet(VAR_FACTORY_LAST_DEFEATED_BOSS, FACTORY_BOSS_NONE);
            ScriptContext_SetupScript(BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript);
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            return;
        }
    }
    else
    {
        if (sFactoryRunRewardChoiceCount == 0)
            sFactoryRunRewardChoiceCount = 1;
        if (selectedIdx >= sFactoryRunRewardChoiceCount)
            selectedIdx = 0;
        sFactoryRewardBuffer = sFactoryRunRewardChoices[selectedIdx];
    }

    ScriptContext_SetupScript(BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript);
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void CB2_GiveReward(void)
{
    if (!IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId))
    {
        if (sPendingFactoryRewardBossId != FACTORY_BOSS_NONE
         && BuildFactoryBossRewardMon(sPendingFactoryRewardBossId,
                                      gSaveBlock2Ptr->frontier.lvlMode,
                                      &sFactoryRewardBuffer)
         && IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId))
        {
            // recovered
        }
        else if (sPendingFactoryRewardBossId != FACTORY_BOSS_NONE
              && TryUseBossPartyFallbackReward(sPendingFactoryRewardBossId, &sFactoryRewardBuffer)
              && IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId))
        {
            // recovered from boss battle party
        }
        else if (sPendingFactoryRewardBossId != FACTORY_BOSS_NONE
              && TryBuildBossAceSpeciesFallbackReward(sPendingFactoryRewardBossId,
                                                      gSaveBlock2Ptr->frontier.lvlMode,
                                                      &sFactoryRewardBuffer)
              && IsFactoryRewardMonValid(&sFactoryRewardBuffer, sPendingFactoryRewardBossId))
        {
            // recovered from boss ace species fallback
        }
        else
        {
        DebugPrintfLevel(MGBA_LOG_WARN,
                         "Reward mon invalid before grant (activeBoss=%d lastBoss=%d pendingBoss=%d)",
                         GetActiveFactoryBossId(),
                         sLastGeneratedFactoryBossId,
                         sPendingFactoryRewardBossId);
        sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
        VarSet(VAR_FACTORY_LAST_DEFEATED_BOSS, FACTORY_BOSS_NONE);
        ScriptContext_SetupScript(BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript);
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        return;
        }
    }

    u8 result = GiveCapturedMonToPlayer(&sFactoryRewardBuffer);
    DebugPrintf("GiveCapturedMonToPlayer: %d", result);
    sPendingFactoryRewardBossId = FACTORY_BOSS_NONE;
    sFactoryRunRewardChoiceCount = 0;
    VarSet(VAR_FACTORY_LAST_DEFEATED_BOSS, FACTORY_BOSS_NONE);

    u16 species = GetMonData(&sFactoryRewardBuffer, MON_DATA_SPECIES);
    u16 nationalDexNum = SpeciesToNationalPokedexNum(species);
    if (nationalDexNum != 0)
    {
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
    }

    ScriptContext_SetupScript(BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript);
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void FillFactoryFrontierTrainerParty(u16 trainerId, u8 firstMonId)
{
    u8 i;
    u8 level;
    u8 fixedIV;
    u32 otID;

    if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
    // By mistake Battle Tower's Level 50 challenge number is used to determine the IVs for Battle Factory.
    #ifdef BUGFIX
        enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
        u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    #else
        enum FrontierLevelMode UNUSED lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
        u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u8 challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][FRONTIER_LVL_50] / FRONTIER_STAGES_PER_CHALLENGE;
    #endif
        if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < FRONTIER_STAGES_PER_CHALLENGE - 1)
            fixedIV = GetFactoryMonFixedIV(challengeNum, FALSE);
        else
            fixedIV = GetFactoryMonFixedIV(challengeNum, TRUE); // Last trainer in challenge uses higher IVs
    }
    else if (trainerId == TRAINER_EREADER)
    {
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        for (i = firstMonId; i < firstMonId + FRONTIER_PARTY_SIZE; i++)
            CreateBattleTowerMon(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i - firstMonId]);
    #endif //FREE_BATTLE_TOWER_E_READER
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        FillFactoryBrainParty();
        return;
    }
    else
    {
        fixedIV = MAX_PER_STAT_IVS;
    }

    level = SetFacilityPtrsGetLevel();
    otID = READ_OTID_FROM_SAVE;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        CreateFacilityMon(&gFacilityTrainerMons[monId],
                level, fixedIV, otID, FLAG_FRONTIER_MON_FACTORY,
                &gEnemyParty[firstMonId + i]);
    }
}

static void FillFactoryTentTrainerParty(u16 trainerId, u8 firstMonId)
{
    u8 i;
    u8 level = TENT_MIN_LEVEL;
    u8 fixedIV = 0;
    u32 otID = READ_OTID_FROM_SAVE;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        CreateFacilityMon(&gFacilityTrainerMons[monId],
                level, fixedIV, otID, 0,
                &gEnemyParty[firstMonId + i]);
    }
}

void FillFactoryTrainerParty(void)
{
    ZeroEnemyPartyMons();
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        FillFactoryFrontierTrainerParty(TRAINER_BATTLE_PARAM.opponentA, 0);
    else
        FillFactoryTentTrainerParty(TRAINER_BATTLE_PARAM.opponentA, 0);
}
