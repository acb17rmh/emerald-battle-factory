#include "../../../include/constants/factory_boss.h"
#include "../../../include/constants/items.h"
#include "../../../include/constants/moves.h"
#include "../../../include/constants/pokemon.h"
#include "../../../include/constants/species.h"

/////////////////////
//// Hoenn Gym Leaders
/////////////////////
static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_RoxanneDiancie =
{
    .species = SPECIES_DIANCIE,
    .nature = NATURE_TIMID,
    .heldItem = ITEM_DIANCITE,
    .abilityNum = 1,
    .hasTeraType = TRUE,
    .teraType = TYPE_STEEL,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 0,
        [STAT_DEF] = 4,
        [STAT_SPATK] = 252,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_POWER_GEM,
        MOVE_MOONBLAST,
        MOVE_MYSTICAL_FIRE,
        MOVE_EARTH_POWER,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_BrawlyMedicham =
{
    .species = SPECIES_MEDICHAM,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_MEDICHAMITE,
    .abilityNum = 1, // Pure Power
    .hasTeraType = TRUE,
    .teraType = TYPE_FIGHTING,
    .evs =
    {
        [STAT_HP] = 4,
        [STAT_ATK] = 252,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_FAKE_OUT,
        MOVE_CLOSE_COMBAT,
        MOVE_ZEN_HEADBUTT,
        MOVE_BULLET_PUNCH,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_WattsonManectric =
{
    .species = SPECIES_MANECTRIC,
    .nature = NATURE_TIMID,
    .heldItem = ITEM_MANECTITE,
    .abilityNum = 2, // Lightning Rod
    .hasTeraType = TRUE,
    .teraType = TYPE_FLYING,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 0,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 252,
        [STAT_SPDEF] = 4,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_VOLT_SWITCH,
        MOVE_THUNDERBOLT,
        MOVE_OVERHEAT,
        MOVE_SNARL
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_FlanneryBlaziken =
{
    .species = SPECIES_BLAZIKEN,
    .nature = NATURE_ADAMANT,
    .heldItem = ITEM_BLAZIKENITE,
    .abilityNum = 2, // Speed Boost
    .hasTeraType = TRUE,
    .teraType = TYPE_FIGHTING,
    .evs =
    {
        [STAT_HP] = 4,
        [STAT_ATK] = 252,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_PROTECT,
        MOVE_CLOSE_COMBAT,
        MOVE_SWORDS_DANCE,
        MOVE_FLARE_BLITZ
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_NormanKangaskhan =
{
    .species = SPECIES_KANGASKHAN,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_KANGASKHANITE,
    .abilityNum = 1, // Scrappy
    .hasTeraType = TRUE,
    .teraType = TYPE_NORMAL,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 252,
        [STAT_DEF] = 4,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_FAKE_OUT,
        MOVE_RETURN,
        MOVE_SUCKER_PUNCH,
        MOVE_POWER_UP_PUNCH,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_WinonaAltaria =
{
    .species = SPECIES_ALTARIA,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_ALTARIANITE,
    .abilityNum = 1,
    .hasTeraType = TRUE,
    .teraType = TYPE_FIRE,
    .evs =
    {
        [STAT_HP] = 4,
        [STAT_ATK] = 252,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_DOUBLE_EDGE,
        MOVE_EARTHQUAKE,
        MOVE_ROOST,
        MOVE_DRAGON_DANCE
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_JuanSwampert =
{
    .species = SPECIES_SWAMPERT,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_SWAMPERTITE,
    .abilityNum = 1,
    .hasTeraType = TRUE,
    .teraType = TYPE_GRASS,
    .evs =
    {
        [STAT_HP] = 4,
        [STAT_ATK] = 252,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_WATERFALL,
        MOVE_EARTHQUAKE,
        MOVE_FLIP_TURN,
        MOVE_ICE_PUNCH
    },
};

/////////////////////
//// Special Bosses
/////////////////////

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_StevenAceMetagross =
{
    .species = SPECIES_METAGROSS,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_METAGROSSITE,
    .abilityNum = 0, // Clear Body
    .hasTeraType = FALSE,
    .teraType = TYPE_NONE,
    .evs =
    {
        [STAT_HP] = 232,
        [STAT_ATK] = 60,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 40,
        [STAT_SPEED] = 176,
    },
    .moves =
    {
        MOVE_METEOR_MASH,
        MOVE_ICE_PUNCH,
        MOVE_ROCK_SLIDE,
        MOVE_BULLET_PUNCH,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_WallyGallade =
{
    .species = SPECIES_GALLADE,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_GALLADITE,
    .abilityNum = 2, // Justified
    .hasTeraType = FALSE,
    .teraType = TYPE_NONE,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 252,
        [STAT_DEF] = 4,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_CLOSE_COMBAT,
        MOVE_ZEN_HEADBUTT,
        MOVE_KNOCK_OFF,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_RedPikachu =
{
    .species = SPECIES_PIKACHU,
    .nature = NATURE_HASTY,
    .heldItem = ITEM_LIGHT_BALL,
    .abilityNum = 0, // Static
    .hasTeraType = TRUE,
    .teraType = TYPE_ELECTRIC,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 252,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 4,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_FAKE_OUT,
        MOVE_EXTREME_SPEED,
        MOVE_VOLT_SWITCH,
        MOVE_SURF,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_BlueAerodactyl =
{
    .species = SPECIES_AERODACTYL,
    .nature = NATURE_ADAMANT,
    .heldItem = ITEM_AERODACTYLITE,
    .abilityNum = 2, // Unnverve
    .hasTeraType = TRUE,
    .teraType = TYPE_GROUND,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 252,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 4,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_STONE_EDGE,
        MOVE_DUAL_WINGBEAT,
        MOVE_PURSUIT,
        MOVE_ROOST,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_CynthiaGarchomp =
{
    .species = SPECIES_GARCHOMP,
    .nature = NATURE_MILD,
    .heldItem = ITEM_GARCHOMPITE,
    .abilityNum = 2, // Rough Skin
    .hasTeraType = TRUE,
    .teraType = TYPE_FIRE,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 4,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 252,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_DRACO_METEOR,
        MOVE_EARTHQUAKE,
        MOVE_FIRE_BLAST,
        MOVE_ICE_FANG,
    },
};

static const struct FactoryCustomMonBuild *const sFactoryBossRewardMonBuilds[FACTORY_BOSS_COUNT] =
{
    [FACTORY_BOSS_NONE] = NULL,
    [FACTORY_BOSS_ROXANNE] = &sFactoryCustomMonBuild_RoxanneDiancie,
    [FACTORY_BOSS_BRAWLY] = &sFactoryCustomMonBuild_BrawlyMedicham,
    [FACTORY_BOSS_WATTSON] = &sFactoryCustomMonBuild_WattsonManectric,
    [FACTORY_BOSS_FLANNERY] = &sFactoryCustomMonBuild_FlanneryBlaziken,
    [FACTORY_BOSS_NORMAN] = &sFactoryCustomMonBuild_NormanKangaskhan,
    [FACTORY_BOSS_WINONA] = &sFactoryCustomMonBuild_WinonaAltaria,
    [FACTORY_BOSS_JUAN] = &sFactoryCustomMonBuild_JuanSwampert,
    [FACTORY_BOSS_WALLY] = &sFactoryCustomMonBuild_WallyGallade,
    [FACTORY_BOSS_STEVEN] = &sFactoryCustomMonBuild_StevenAceMetagross,
    [FACTORY_BOSS_RED] = &sFactoryCustomMonBuild_RedPikachu,
    [FACTORY_BOSS_BLUE] = &sFactoryCustomMonBuild_BlueAerodactyl,
    [FACTORY_BOSS_CYNTHIA] = &sFactoryCustomMonBuild_CynthiaGarchomp,
};

static const struct FactoryCustomMonBuild *const sFactoryBossAceMonBuilds[FACTORY_BOSS_COUNT] =
{
    [FACTORY_BOSS_NONE] = NULL,
    [FACTORY_BOSS_ROXANNE] = &sFactoryCustomMonBuild_RoxanneDiancie,
    [FACTORY_BOSS_BRAWLY] = &sFactoryCustomMonBuild_BrawlyMedicham,
    [FACTORY_BOSS_WATTSON] = &sFactoryCustomMonBuild_WattsonManectric,
    [FACTORY_BOSS_FLANNERY] = &sFactoryCustomMonBuild_FlanneryBlaziken,
    [FACTORY_BOSS_NORMAN] = &sFactoryCustomMonBuild_NormanKangaskhan,
    [FACTORY_BOSS_WINONA] = &sFactoryCustomMonBuild_WinonaAltaria,
    [FACTORY_BOSS_JUAN] = &sFactoryCustomMonBuild_JuanSwampert,
    [FACTORY_BOSS_WALLY] = &sFactoryCustomMonBuild_WallyGallade,
    [FACTORY_BOSS_STEVEN] = &sFactoryCustomMonBuild_StevenAceMetagross,
    [FACTORY_BOSS_RED] = &sFactoryCustomMonBuild_RedPikachu,
    [FACTORY_BOSS_BLUE] = &sFactoryCustomMonBuild_BlueAerodactyl,
    [FACTORY_BOSS_CYNTHIA] = &sFactoryCustomMonBuild_CynthiaGarchomp,
};
