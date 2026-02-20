#include "global.h"
#include "event_data.h"
#include "frontier_util.h"
#include "test/test.h"
#include "constants/battle_frontier.h"
#include "constants/factory_boss.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/vars.h"

static void InitFactoryBossCadenceContext(void)
{
    VarSet(VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY);
    VarSet(VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES);
    VarSet(VAR_FACTORY_ACTIVE_BOSS, FACTORY_BOSS_NONE);
    VarSet(VAR_FACTORY_BOSS_UNLOCK_STATE, 0);
    VarSet(VAR_FACTORY_BOSS_CLEARED_MASK, 0);
    VarSet(VAR_FACTORY_BOSS_ROTATION_INDEX, 0);

    FlagClear(FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE);
    FlagClear(FLAG_SYS_TOWER_SILVER + FRONTIER_FACILITY_FACTORY * 2);
    FlagClear(FLAG_SYS_TOWER_GOLD + FRONTIER_FACILITY_FACTORY * 2);

    gSaveBlock2Ptr->frontier.lvlMode = FRONTIER_LVL_50;
    gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 0;
}

TEST("Factory boss cadence: does not schedule boss while progression is locked")
{
    InitFactoryBossCadenceContext();

    FlagSet(FLAG_SYS_TOWER_SILVER + FRONTIER_FACILITY_FACTORY * 2);
    gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 41;

    PrepareFactoryBossForNextBattle();
    EXPECT_EQ(VarGet(VAR_FACTORY_ACTIVE_BOSS), FACTORY_BOSS_NONE);
}

TEST("Factory boss cadence: schedules Steven on first post-unlock milestone")
{
    InitFactoryBossCadenceContext();

    VarSet(VAR_FACTORY_BOSS_UNLOCK_STATE, 1);
    FlagSet(FLAG_SYS_TOWER_SILVER + FRONTIER_FACILITY_FACTORY * 2);
    gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 41;

    PrepareFactoryBossForNextBattle();
    EXPECT_EQ(VarGet(VAR_FACTORY_ACTIVE_BOSS), FACTORY_BOSS_STEVEN);
}

TEST("Factory boss cadence: recording a boss defeat updates mask and rotation index")
{
    InitFactoryBossCadenceContext();

    VarSet(VAR_FACTORY_ACTIVE_BOSS, FACTORY_BOSS_STEVEN);
    RecordFactoryBossDefeat();

    EXPECT_EQ(VarGet(VAR_FACTORY_BOSS_CLEARED_MASK) & (1u << (FACTORY_BOSS_STEVEN - 1)), (1u << (FACTORY_BOSS_STEVEN - 1)));
    EXPECT_EQ(VarGet(VAR_FACTORY_BOSS_ROTATION_INDEX), 1);
}

TEST("Factory boss cadence: schedules next uncleared boss in rotation")
{
    InitFactoryBossCadenceContext();

    VarSet(VAR_FACTORY_BOSS_UNLOCK_STATE, 1);
    VarSet(VAR_FACTORY_BOSS_CLEARED_MASK, (1u << (FACTORY_BOSS_STEVEN - 1)));
    VarSet(VAR_FACTORY_BOSS_ROTATION_INDEX, 1);
    FlagSet(FLAG_SYS_TOWER_SILVER + FRONTIER_FACILITY_FACTORY * 2);
    gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 62;

    PrepareFactoryBossForNextBattle();
    EXPECT_EQ(VarGet(VAR_FACTORY_ACTIVE_BOSS), FACTORY_BOSS_WALLY);
}

TEST("Factory boss cadence: one-symbol phase is gated to cadence milestones")
{
    InitFactoryBossCadenceContext();

    VarSet(VAR_FACTORY_BOSS_UNLOCK_STATE, 1);
    FlagSet(FLAG_SYS_TOWER_SILVER + FRONTIER_FACILITY_FACTORY * 2);
    gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 55;

    EXPECT_EQ(GetFrontierBrainStatus(), FRONTIER_BRAIN_NOT_READY);
}

TEST("Factory boss cadence: after clearing tier-1 bosses, next milestone returns Gold Noland")
{
    u16 allClearedMask = 0;

    InitFactoryBossCadenceContext();
    allClearedMask |= (1u << (FACTORY_BOSS_STEVEN - 1));
    allClearedMask |= (1u << (FACTORY_BOSS_WALLY - 1));
    allClearedMask |= (1u << (FACTORY_BOSS_NORMAN - 1));
    allClearedMask |= (1u << (FACTORY_BOSS_RED - 1));

    VarSet(VAR_FACTORY_BOSS_UNLOCK_STATE, 1);
    VarSet(VAR_FACTORY_BOSS_CLEARED_MASK, allClearedMask);
    FlagSet(FLAG_SYS_TOWER_SILVER + FRONTIER_FACILITY_FACTORY * 2);
    gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 83;

    EXPECT_EQ(GetFrontierBrainStatus(), FRONTIER_BRAIN_GOLD);
}

TEST("Factory boss cadence: debug force Nolan overrides cadence and clears active custom boss")
{
    InitFactoryBossCadenceContext();

    FlagSet(FLAG_BATTLE_FACTORY_DEBUG_FORCE_NOLAND);
    VarSet(VAR_FACTORY_ACTIVE_BOSS, FACTORY_BOSS_STEVEN);

    EXPECT_EQ(GetFrontierBrainStatus(), FRONTIER_BRAIN_STREAK);

    PrepareFactoryBossForNextBattle();
    EXPECT_EQ(VarGet(VAR_FACTORY_ACTIVE_BOSS), FACTORY_BOSS_NONE);
}
