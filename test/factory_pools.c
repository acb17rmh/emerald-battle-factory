#include "global.h"
#include "battle_tower.h"
#include "event_data.h"
#include "test/test.h"
#include "constants/factory_pools.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/moves.h"

struct PoolSource
{
    const u16 *pool;
    u16 count;
};

struct RankPool
{
    const u16 *pool;
    u16 count;
};

static void SetFactoryMechanicFlags(bool8 tera, bool8 mega, bool8 zMove)
{
    if (tera)
        FlagSet(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    else
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);

    if (mega)
        FlagSet(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    else
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);

    if (zMove)
        FlagSet(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
    else
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
}

static bool8 MonHasMove(const struct TrainerMon *mon, u16 move)
{
    u32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (mon->moves[i] == move)
            return TRUE;
    }
    return FALSE;
}

static bool8 MonUsesMegaStone(const struct TrainerMon *mon)
{
    return mon->heldItem >= ITEM_VENUSAURITE && mon->heldItem <= ITEM_DIANCITE;
}

static bool8 MonUsesZCrystal(const struct TrainerMon *mon)
{
    return mon->heldItem >= ITEM_NORMALIUM_Z && mon->heldItem <= ITEM_ULTRANECROZIUM_Z;
}

static bool8 MonIsExcludedByCurrentFlags(u16 monId)
{
    const struct TrainerMon *mon = &gBattleFrontierMons[monId];

    if (!FlagGet(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION) && MonHasMove(mon, MOVE_TERA_BLAST))
        return TRUE;
    if (!FlagGet(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION) && MonUsesMegaStone(mon))
        return TRUE;
    if (!FlagGet(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES) && MonUsesZCrystal(mon))
        return TRUE;
    return FALSE;
}

static struct RankPool GetRankPool(u32 rank)
{
    switch (rank)
    {
    case 1:
        return (struct RankPool) { sFactoryPoolRank1, gFactoryPoolRank1Count };
    case 2:
        return (struct RankPool) { sFactoryPoolRank2, gFactoryPoolRank2Count };
    case 3:
        return (struct RankPool) { sFactoryPoolRank3, gFactoryPoolRank3Count };
    default:
        return (struct RankPool) { sFactoryPoolRank4, gFactoryPoolRank4Count };
    }
}

static u16 BuildExpectedPool(const struct PoolSource *sources, u32 sourceCount, u16 *expected)
{
    bool8 seenSpecies[NUM_SPECIES] = {FALSE};
    u16 expectedCount = 0;
    u32 i;
    u32 j;

    for (i = 0; i < sourceCount; i++)
    {
        for (j = 0; j < sources[i].count; j++)
        {
            u16 monId = sources[i].pool[j];
            u16 species = gBattleFrontierMons[monId].species;

            if (species == SPECIES_NONE || species >= NUM_SPECIES)
                continue;
            if (seenSpecies[species])
                continue;
            if (MonIsExcludedByCurrentFlags(monId))
                continue;
            if (expectedCount >= FACTORY_RANK_POOL_MAX_SIZE)
                return expectedCount;

            expected[expectedCount++] = monId;
            seenSpecies[species] = TRUE;
        }
    }

    return expectedCount;
}

TEST("Factory rank pools match deduped configured source tiers")
{
    static const struct PoolSource sRank1Sources[] =
    {
        { gFrontierFactoryPool_GEN9PU, FRONTIER_FACTORY_POOL_GEN9PU_COUNT },
        { gFrontierFactoryPool_GEN9ZU, FRONTIER_FACTORY_POOL_GEN9ZU_COUNT },
        { gFrontierFactoryPool_GEN9NU, FRONTIER_FACTORY_POOL_GEN9NU_COUNT },
    };
    static const struct PoolSource sRank2Sources[] =
    {
        { gFrontierFactoryPool_GEN9NU, FRONTIER_FACTORY_POOL_GEN9NU_COUNT },
        { gFrontierFactoryPool_GEN9RU, FRONTIER_FACTORY_POOL_GEN9RU_COUNT },
        { gFrontierFactoryPool_GEN9NATIONALDEXRU, FRONTIER_FACTORY_POOL_GEN9NATIONALDEXRU_COUNT },
    };
    static const struct PoolSource sRank3Sources[] =
    {
        { gFrontierFactoryPool_GEN9RU, FRONTIER_FACTORY_POOL_GEN9RU_COUNT },
        { gFrontierFactoryPool_GEN9UU, FRONTIER_FACTORY_POOL_GEN9UU_COUNT },
        { gFrontierFactoryPool_GEN9NATIONALDEXUU, FRONTIER_FACTORY_POOL_GEN9NATIONALDEXUU_COUNT },
    };
    static const struct PoolSource sRank4Sources[] =
    {
        { gFrontierFactoryPool_GEN9UU, FRONTIER_FACTORY_POOL_GEN9UU_COUNT },
        { gFrontierFactoryPool_GEN9OU, FRONTIER_FACTORY_POOL_GEN9OU_COUNT },
        { gFrontierFactoryPool_GEN9NATIONALDEX, FRONTIER_FACTORY_POOL_GEN9NATIONALDEX_COUNT },
    };
    static const struct PoolSource *const sSourcesByRank[] =
    {
        sRank1Sources,
        sRank2Sources,
        sRank3Sources,
        sRank4Sources,
    };
    static const u32 sSourceCountsByRank[] =
    {
        ARRAY_COUNT(sRank1Sources),
        ARRAY_COUNT(sRank2Sources),
        ARRAY_COUNT(sRank3Sources),
        ARRAY_COUNT(sRank4Sources),
    };
    u16 expected[FACTORY_RANK_POOL_MAX_SIZE];
    u16 expectedCount;
    struct RankPool rankPool;
    u32 rank;
    u32 i;

    SetFactoryMechanicFlags(TRUE, TRUE, TRUE);
    InitFactoryRankPools();

    for (rank = 1; rank <= 4; rank++)
    {
        expectedCount = BuildExpectedPool(sSourcesByRank[rank - 1], sSourceCountsByRank[rank - 1], expected);
        rankPool = GetRankPool(rank);
        EXPECT_EQ(rankPool.count, expectedCount);

        for (i = 0; i < expectedCount; i++)
            EXPECT_EQ(rankPool.pool[i], expected[i]);
    }
}

TEST("Factory rank pools exclude Tera Blast sets when terastallization is disabled")
{
    u32 rank;
    u32 i;

    SetFactoryMechanicFlags(FALSE, TRUE, TRUE);
    InitFactoryRankPools();

    for (rank = 1; rank <= 4; rank++)
    {
        struct RankPool rankPool = GetRankPool(rank);
        for (i = 0; i < rankPool.count; i++)
            EXPECT(!MonHasMove(&gBattleFrontierMons[rankPool.pool[i]], MOVE_TERA_BLAST));
    }
}

TEST("Factory rank pools exclude Mega Stone sets when mega evolution is disabled")
{
    u32 rank;
    u32 i;

    SetFactoryMechanicFlags(TRUE, FALSE, TRUE);
    InitFactoryRankPools();

    for (rank = 1; rank <= 4; rank++)
    {
        struct RankPool rankPool = GetRankPool(rank);
        for (i = 0; i < rankPool.count; i++)
            EXPECT(!MonUsesMegaStone(&gBattleFrontierMons[rankPool.pool[i]]));
    }
}

TEST("Factory rank pools exclude Z-Crystal sets when Z-Moves are disabled")
{
    u32 rank;
    u32 i;

    SetFactoryMechanicFlags(TRUE, TRUE, FALSE);
    InitFactoryRankPools();

    for (rank = 1; rank <= 4; rank++)
    {
        struct RankPool rankPool = GetRankPool(rank);
        for (i = 0; i < rankPool.count; i++)
            EXPECT(!MonUsesZCrystal(&gBattleFrontierMons[rankPool.pool[i]]));
    }
}
