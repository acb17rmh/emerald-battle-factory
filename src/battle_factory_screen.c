#include "global.h"
#include "battle.h"
#include "battle_factory_screen.h"
#include "battle_factory.h"
#include "sprite.h"
#include "event_data.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "text.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "string_util.h"
#include "international_string_util.h"
#include "window.h"
#include "data.h"
#include "decompress.h"
#include "pokemon_summary_screen.h"
#include "sound.h"
#include "pokedex.h"
#include "util.h"
#include "trainer_pokemon_sprites.h"
#include "strings.h"
#include "graphics.h"
#include "choice_menu.h"
#include "pokemon_icon.h"
#include "constants/battle_frontier.h"
#include "constants/battle_tent.h"
#include "constants/songs.h"
#include "constants/rgb.h"

// Select_ refers to the first Pokémon selection screen where you choose your initial 3 rental Pokémon.
// Swap_   refers to the subsequent selection screens where you can swap a Pokémon with one from the beaten trainer

// Note that, generally, "Action" will refer to the immediate actions that can be taken on each screen,
// i.e. selecting a Pokémon or selecting the Cancel button
// The "Options menu" will refer to the popup menu that shows when some actions have been selected

#define SWAP_PLAYER_SCREEN 0  // The screen where the player selects which of their Pokémon to swap away
#define SWAP_ENEMY_SCREEN  1  // The screen where the player selects which new Pokémon from the defeated party to swap for

#define SELECTABLE_MONS_COUNT 6
#define FACTORY_SELECT_OFFER_COUNT BATTLE_FACTORY_INITIAL_OFFER_COUNT
#define FACTORY_SELECT_PAGE_SIZE SELECTABLE_MONS_COUNT
#define FACTORY_SELECT_PAGE_COUNT (FACTORY_SELECT_OFFER_COUNT / FACTORY_SELECT_PAGE_SIZE)

#define FACTORY_GRID_COLS 6
#define FACTORY_GRID_ROWS 2
#define FACTORY_GRID_COUNT (FACTORY_GRID_COLS * FACTORY_GRID_ROWS)

#define FACTORY_GRID_START_X 24
#define FACTORY_GRID_START_Y 64
#define FACTORY_GRID_X_SPACING 36
#define FACTORY_GRID_Y_SPACING 32

#define FACTORY_GRID_BG_FILL PIXEL_FILL(1)
#define FACTORY_GRID_BG_STRIPE_FILL PIXEL_FILL(4)
#define FACTORY_GRID_SEL_FILL PIXEL_FILL(2)
#define FACTORY_GRID_CURSOR_FILL PIXEL_FILL(3)

#define SWAP_ICON_START_X 72
#define SWAP_ICON_Y 78
#define SWAP_ICON_X_SPACING 48
#define SWAP_CURSOR_WIN_LEFT 0
#define SWAP_CURSOR_WIN_TOP 4

#define PALNUM_FADE_TEXT 14
#define PALNUM_TEXT      15
#define PALNUM_GRID      13

enum {
    PALTAG_BALL_GRAY = 100,
    PALTAG_BALL_SELECTED,
    PALTAG_INTERFACE,
    PALTAG_MON_PIC_BG,
    PALTAG_FACTORY_CAUGHT_BALL,
};

enum {
    GFXTAG_BALL = 100,
    GFXTAG_ARROW,
    GFXTAG_MENU_HIGHLIGHT_LEFT,
    GFXTAG_MENU_HIGHLIGHT_RIGHT,
    GFXTAG_ACTION_BOX_LEFT,
    GFXTAG_ACTION_BOX_RIGHT,
    GFXTAG_ACTION_HIGHLIGHT_LEFT,
    GFXTAG_ACTION_HIGHLIGHT_MIDDLE,
    GFXTAG_ACTION_HIGHLIGHT_RIGHT,
    GFXTAG_MON_PIC_BG_ANIM,
    GFXTAG_FACTORY_CAUGHT_BALL,
};

// Tasks in this file universally use data[0] as a state for switches
#define tState   data[0]

// States for both Select/Swap versions of Task_FadeSpeciesName
enum {
    FADESTATE_INIT,
    FADESTATE_RUN,
    FADESTATE_DELAY
};

// Return states for the Select Actions
enum {
    SELECT_SUMMARY,
    SELECT_CONTINUE_CHOOSING,
    SELECT_CONFIRM_MONS,
    SELECT_INVALID_MON,
};

struct FactorySelectableMon
{
    u16 monId;
    struct Pokemon monData;
};

struct FactoryOfferMon
{
    u16 monId;
    struct Pokemon monData;
};

struct FactoryMonPic
{
    u8 monSpriteId;
    u8 bgSpriteId;
};

struct FactorySelectScreen
{
    u8 cursorPos;
    struct ChoiceMenuState choice;
    u8 offerCount;
    bool8 fromSummaryScreen;
    u8 yesNoCursorPos;
    u8 bobCounter;
    bool8 bobUp;
    bool8 bobPaused;
    u8 lastCursorIdx;
    struct FactorySelectableMon mons[SELECTABLE_MONS_COUNT];
    struct FactoryOfferMon offers[FACTORY_SELECT_OFFER_COUNT];
    u8 offerIconSpriteIds[FACTORY_SELECT_OFFER_COUNT];
    u8 pickedStripIconSpriteIds[FRONTIER_PARTY_SIZE];
    u8 caughtBallSpriteIds[FACTORY_SELECT_OFFER_COUNT];
};

struct FactorySwapScreen
{
    u8 menuCursorPos;
    u8 menuCursor1SpriteId;
    u8 menuCursor2SpriteId;
    u8 cursorPos;
    u8 cursorSpriteId;
    u8 ballSpriteIds[FRONTIER_PARTY_SIZE];
    u8 playerIconSpriteIds[FRONTIER_PARTY_SIZE];
    u8 enemyIconSpriteIds[FRONTIER_PARTY_SIZE];
    u8 mapIconSpriteIds[FRONTIER_PARTY_SIZE];
    u8 pkmnForSwapButtonSpriteIds[2][3]; // For this and sprite ID array below, [0][i] is the button background, [1][i] is the button highlight
    u8 cancelButtonSpriteIds[2][2];
    u8 playerMonId;
    u8 enemyMonId;
    bool8 inEnemyScreen;
    bool8 fromSummaryScreen;
    u8 yesNoCursorPos;
    struct ChoiceMenuState choice;
    bool8 monSwapped;
    u8 fadeSpeciesNameTaskId;
    bool8 fadeSpeciesNameActive;
    u16 speciesNameColorBackup;
    bool8 fadeSpeciesNameFadeOut;
    u8 fadeSpeciesNameCoeffDelay;
    u8 fadeSpeciesNameCoeff;
    u8 faceSpeciesNameDelay;
    struct FactoryMonPic monPic;
    bool8 monPicAnimating;
};

static void SpriteCB_Pokeball(struct Sprite *);
static void SpriteCB_OpenMonPic(struct Sprite *);
static void OpenMonPic(u8 *, bool8 *, bool8);
static void HideMonPic(struct FactoryMonPic, bool8 *);
static void CloseMonPic(struct FactoryMonPic, bool8 *, bool8);
static void Task_OpenMonPic(u8);
static void Task_CloseMonPic(u8);

// Select screen
static void CB2_InitSelectScreen(void);
static void Select_InitMonsData(void);
static void Select_PrintSelectMonString(void);
static void Select_PrintMonSpecies(void);
static void Select_PrintMonCategory(void);
static void Select_PrintRentalPkmnString(void);
static u8 Select_GetRequiredPicks(void);
static void Select_CopyMonsToPlayerParty(void);
static void Select_PrintCantSelectSameMon(void);
static void SelectGrid_GetOfferIconCoords(u8 idx, s16 *x, s16 *y);
static void SelectGrid_InitIcons(void);
static void SelectGrid_DestroyIcons(void);
static void SelectGrid_DrawHighlights(void);
static void SelectGrid_InitPickedStripIcons(void);
static void SelectGrid_DestroyPickedStripIcons(void);
static void SelectGrid_UpdatePickedStripIcons(void);
static void SelectGrid_InitCaughtBallSprites(void);
static void SelectGrid_DestroyCaughtBallSprites(void);
static void SelectGrid_UpdateCaughtBallSprites(void);
static void SelectGrid_DeselectLastPick(void);
static void SelectGrid_UpdateCursorBob(bool8 reset);
static void SelectGrid_Task_HandleInput(u8);
static void SelectGrid_Task_OpenSummaryScreen(u8);
static void SelectGrid_Task_Exit(u8);
static void SelectGrid_Task_HandleYesNo(u8);
static void CreateFrontierFactorySelectableMons(u8);
static void CreateSlateportTentSelectableMons(u8);
static void Select_RefreshVisibleMonsFromPage(void);
static bool32 Select_AreSpeciesValid(u16);

// Swap screen
static void CB2_InitSwapScreen(void);
static void Swap_DestroyAllSprites(void);
static void Swap_ShowYesNoOptions(void);
static void Swap_HideActionButtonHighlights(void);
static void Swap_EraseSpeciesWindow(void);
static void Swap_UpdateYesNoCursorPosition(s8);
static void Swap_InitChoiceState(u8);
static u8 Swap_GetCursorPos(void);
static void Swap_SetCursorPos(u8);
static void Swap_ErasePopupMenu(u8);
static void Swap_Task_HandleChooseMons(u8);
static void Swap_PrintChoosePrompt(void);
static void Swap_UpdateCursorBox(void);
static void Swap_PrintOnInfoWindow(const u8 *);
static void Swap_PrintYesNoOptions(void);
static void Swap_PrintMonSpecies(void);
static void Swap_PrintMonSpeciesAtFade(void);
static void Swap_PrintMonSpeciesForTransition(void);
static void Swap_PrintMonCategory(void);
static void Swap_InitAllSprites(void);
static void Swap_InitMonIcons(void);
static void Swap_DestroyMonIcons(void);
static void Swap_UpdateMonIcons(void);
static void Swap_UpdateSwapMapIcons(void);
static void Swap_PrintPkmnSwap(void);
static void Swap_EraseSpeciesAtFadeWindow(void);
static void Swap_UpdateBallCursorPosition(s8);
static void Swap_RunActionFunc(u8);
static void Swap_TaskCantHaveSameMons(u8);
static void Swap_CreateMonSprite(void);
static void Swap_InitActions(u8);
static bool8 Swap_AlreadyHasSameSpecies(u8);
static void Swap_ActionMon(u8);

static EWRAM_DATA u8 *sSelectMenuTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSelectMonPicBgTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSelectMenuTilemapBuffer = NULL;
static EWRAM_DATA u8 *sSelectMonPicBgTilemapBuffer = NULL;
static EWRAM_DATA struct Pokemon *sFactorySelectMons = NULL;
static EWRAM_DATA u8 *sSwapMenuTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSwapMonPicBgTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSwapMenuTilemapBuffer = NULL;
static EWRAM_DATA u8 *sSwapMonPicBgTilemapBuffer = NULL;

static struct FactorySelectScreen *sFactorySelectScreen;
static TaskFunc sSwap_CurrentOptionFunc;
static struct FactorySwapScreen *sFactorySwapScreen;
static EWRAM_DATA struct Pokemon sFactorySelectOverrideMons[FACTORY_SELECT_OFFER_COUNT];
static EWRAM_DATA u8 sFactorySelectOverrideCount = 0;
static EWRAM_DATA bool8 sFactorySelectRewardMode = FALSE;
static EWRAM_DATA MainCallback sFactorySelectExitCallback = NULL;

// Task data for Task_CloseMonPic and Task_OpenMonPic
#define tWinLeft      data[3]
#ifndef UBFIX
#define tWinRight     data[24] // UB: Typo? Likely meant data[4], 24 is out of bounds
#else
#define tWinRight     data[4]
#endif
#define tWinTop       data[5]
#define tWinBottom    data[8]
#define tSpriteId     data[6]
#define tIsSwapScreen data[7]

static const u16 sPokeballGray_Pal[]         = INCBIN_U16("graphics/battle_frontier/factory_screen/pokeball_gray.gbapal");
static const u16 sPokeballSelected_Pal[]     = INCBIN_U16("graphics/battle_frontier/factory_screen/pokeball_selected.gbapal");
static const u16 sInterface_Pal[]            = INCBIN_U16("graphics/battle_frontier/factory_screen/interface.gbapal"); // Arrow, menu/action highlights, action box, etc
static const struct CompressedSpriteSheet sFactoryCaughtBall_Gfx = {gPartyMenuPokeballSmall_Gfx, 0x0300, GFXTAG_FACTORY_CAUGHT_BALL};
static const struct SpritePalette sFactoryCaughtBall_Pal = {gPartyMenuPokeball_Pal, PALTAG_FACTORY_CAUGHT_BALL};
static const u32 sPokeball_Gfx[]             = INCBIN_U32("graphics/battle_frontier/factory_screen/pokeball.4bpp");
static const u8 sArrow_Gfx[]                 = INCBIN_U8( "graphics/battle_frontier/factory_screen/arrow.4bpp");
static const u8 sMenuHighlightLeft_Gfx[]     = INCBIN_U8( "graphics/battle_frontier/factory_screen/menu_highlight_left.4bpp");
static const u8 sMenuHighlightRight_Gfx[]    = INCBIN_U8( "graphics/battle_frontier/factory_screen/menu_highlight_right.4bpp");
static const u8 sActionBoxLeft_Gfx[]         = INCBIN_U8( "graphics/battle_frontier/factory_screen/action_box_left.4bpp");
static const u8 sActionBoxRight_Gfx[]        = INCBIN_U8( "graphics/battle_frontier/factory_screen/action_box_right.4bpp");
static const u8 sActionHighlightLeft_Gfx[]   = INCBIN_U8( "graphics/battle_frontier/factory_screen/action_highlight_left.4bpp");
static const u8 sActionHighlightMiddle_Gfx[] = INCBIN_U8( "graphics/battle_frontier/factory_screen/action_highlight_middle.4bpp");
static const u8 sActionHighlightRight_Gfx[]  = INCBIN_U8( "graphics/battle_frontier/factory_screen/action_highlight_right.4bpp");
static const u8 sMonPicBgAnim_Gfx[]          = INCBIN_U8( "graphics/battle_frontier/factory_screen/mon_pic_bg_anim.4bpp");
static const u8 sMonPicBg_Tilemap[]          = INCBIN_U8( "graphics/battle_frontier/factory_screen/mon_pic_bg.bin");
static const u16 sMonPicBg_Gfx[]             = INCBIN_U16("graphics/battle_frontier/factory_screen/mon_pic_bg.4bpp");
static const u16 sMonPicBg_Pal[]             = INCBIN_U16("graphics/battle_frontier/factory_screen/mon_pic_bg.gbapal");

static const struct BgTemplate sSelect_BgTemplates[] =
{
	    {
	        .bg = 0,
	        .charBaseIndex = 0,
	        .mapBaseIndex = 24,
	        .screenSize = 0,
	        .paletteMode = 0,
	        .priority = 3,
	        .baseTile = 0
	    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

enum {
    SELECT_WIN_TITLE,
    SELECT_WIN_SPECIES,
    SELECT_WIN_INFO,
    SELECT_WIN_LIST,
    SELECT_WIN_OPTIONS,
    SELECT_WIN_YES_NO,
    SELECT_WIN_MON_CATEGORY,
};

static const struct WindowTemplate sSelect_WindowTemplates[] =
{
	[SELECT_WIN_TITLE] = {
	    .bg = 0,
	    .tilemapLeft = 0,
	    .tilemapTop = 2,
	    .width = 12,
	    .height = 2,
	    .paletteNum = PALNUM_TEXT,
	    .baseBlock = 0x0001,
	},
	[SELECT_WIN_SPECIES] = {
	    .bg = 0,
	    .tilemapLeft = 19,
	    .tilemapTop = 2,
	    .width = 11,
	    .height = 2,
	    .paletteNum = PALNUM_FADE_TEXT,
	    .baseBlock = 0x0019,
	},
	[SELECT_WIN_INFO] = {
	    .bg = 0,
	    .tilemapLeft = 0,
	    .tilemapTop = 14,
	    .width = 30,
	    .height = 6,
	    .paletteNum = PALNUM_TEXT,
	    .baseBlock = 0x002f,
	},
	[SELECT_WIN_LIST] = {
	    .bg = 0,
	    .tilemapLeft = 0,
	    .tilemapTop = 4,
	    .width = 30,
	    .height = 10,
	    .paletteNum = PALNUM_GRID,
	    // Must not overlap SELECT_WIN_INFO tile space.
	    .baseBlock = 0x00e3,
	},
	[SELECT_WIN_OPTIONS] = {
	    .bg = 0,
	    .tilemapLeft = 22,
	    .tilemapTop = 14,
	    .width = 8,
	    .height = 6,
	    .paletteNum = PALNUM_TEXT,
	    .baseBlock = 0x0217,
	},
	[SELECT_WIN_YES_NO] = {
		.bg = 0,
		.tilemapLeft = 22,
		.tilemapTop = 14,
		.width = 8,
		.height = 4,
		.paletteNum = PALNUM_TEXT,
		.baseBlock = 0x0247,
	},
	[SELECT_WIN_MON_CATEGORY] = {
	    .bg = 0,
	    .tilemapLeft = 15,
	    .tilemapTop = 0,
	    .width = 15,
	    .height = 2,
	    .paletteNum = PALNUM_TEXT,
	    .baseBlock = 0x0267,
	},
    DUMMY_WIN_TEMPLATE,
};

static const u16 sSelectText_Pal[] = INCBIN_U16("graphics/battle_frontier/factory_screen/text.gbapal");
static const u16 sGridUi_Pal[] =
{
    RGB(0, 0, 0),      // 0: transparent / unused
    RGB(10, 12, 15),   // 1: panel bg (factory-ish steel)
    RGB(24, 24, 24),   // 2: selected border (subtle)
    RGB(31, 26, 0),    // 3: cursor border
    RGB(12, 14, 18),   // 4: stripe bg (subtle)
};
static const u8 sMenuOptionTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_TRANSPARENT};
static const u8 sSpeciesNameTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_TRANSPARENT};

static const struct OamData sOam_Select_CaughtBall =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_Select_Interface[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Select_Interface[] =
{
    sAnim_Select_Interface,
};

static const struct SpriteTemplate sSpriteTemplate_Select_CaughtBall =
{
    .tileTag = GFXTAG_FACTORY_CAUGHT_BALL,
    .paletteTag = PALTAG_FACTORY_CAUGHT_BALL,
    .oam = &sOam_Select_CaughtBall,
    .anims = sAnims_Select_Interface,
};

static const struct SpriteSheet sSwap_SpriteSheets[] =
{
    {sArrow_Gfx,                 sizeof(sArrow_Gfx),                 GFXTAG_ARROW},
    {sMenuHighlightLeft_Gfx,     sizeof(sMenuHighlightLeft_Gfx),     GFXTAG_MENU_HIGHLIGHT_LEFT},
    {sMenuHighlightRight_Gfx,    sizeof(sMenuHighlightRight_Gfx),    GFXTAG_MENU_HIGHLIGHT_RIGHT},
    {sActionBoxLeft_Gfx,         sizeof(sActionBoxLeft_Gfx),         GFXTAG_ACTION_BOX_LEFT},
    {sActionBoxRight_Gfx,        sizeof(sActionBoxRight_Gfx),        GFXTAG_ACTION_BOX_RIGHT},
#ifdef BUGFIX
    {sActionHighlightLeft_Gfx,   sizeof(sActionHighlightLeft_Gfx),   GFXTAG_ACTION_HIGHLIGHT_LEFT},
#else
    {sActionHighlightLeft_Gfx,   8 * TILE_SIZE_4BPP, /* Incorrect size */ GFXTAG_ACTION_HIGHLIGHT_LEFT},
#endif
    {sActionHighlightMiddle_Gfx, sizeof(sActionHighlightMiddle_Gfx), GFXTAG_ACTION_HIGHLIGHT_MIDDLE},
    {sActionHighlightRight_Gfx,  sizeof(sActionHighlightRight_Gfx),  GFXTAG_ACTION_HIGHLIGHT_RIGHT},
    {sMonPicBgAnim_Gfx,          sizeof(sMonPicBgAnim_Gfx),          GFXTAG_MON_PIC_BG_ANIM},
    {},
};

static const struct CompressedSpriteSheet sSwap_BallGfx[] =
{
    {sPokeball_Gfx, 0x800, GFXTAG_BALL},
    {},
};

static const struct SpritePalette sSwap_SpritePalettes[] =
{
    {sPokeballGray_Pal,     PALTAG_BALL_GRAY},
    {sPokeballSelected_Pal, PALTAG_BALL_SELECTED},
    {sInterface_Pal,        PALTAG_INTERFACE},
    {sMonPicBg_Pal,         PALTAG_MON_PIC_BG},
    {},
};

static const struct OamData sOam_Swap_Pokeball =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_Swap_Arrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_Swap_MenuHighlight =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_Swap_MonPicBgAnim =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 1,
};

static const union AnimCmd sAnim_Swap_Interface[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swap_MonPicBgAnim[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swap_Pokeball_Still[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swap_Pokeball_Moving[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Swap_Interface[] =
{
    sAnim_Swap_Interface,
};

static const union AnimCmd *const sAnims_Swap_MonPicBgAnim[] =
{
    sAnim_Swap_MonPicBgAnim,
};

static const union AnimCmd *const sAnims_Swap_Pokeball[] =
{
    sAnim_Swap_Pokeball_Still,
    sAnim_Swap_Pokeball_Moving,
};

static const union AffineAnimCmd sAffineAnim_Swap_MonPicBg_Opening[] =
{
    AFFINEANIMCMD_FRAME(5, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(16, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(32, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(64, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(128, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(256, 5, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Swap_MonPicBg_Closing[] =
{
    AFFINEANIMCMD_FRAME(128, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(64, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(32, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(16, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(5, 5, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Swap_MonPicBg_Open[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_Swap_MonPicBgAnim[] =
{
    sAffineAnim_Swap_MonPicBg_Opening,
    sAffineAnim_Swap_MonPicBg_Closing,
    sAffineAnim_Swap_MonPicBg_Open,
};

static const struct SpriteTemplate sSpriteTemplate_Swap_Pokeball =
{
    .tileTag = GFXTAG_BALL,
    .paletteTag = PALTAG_BALL_GRAY,
    .oam = &sOam_Swap_Pokeball,
    .anims = sAnims_Swap_Pokeball,
    .callback = SpriteCB_Pokeball
};

static const struct SpriteTemplate sSpriteTemplate_Swap_Arrow =
{
    .tileTag = GFXTAG_ARROW,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_Swap_Arrow,
    .anims = sAnims_Swap_Interface,
};

static const struct SpriteTemplate sSpriteTemplate_Swap_MenuHighlightLeft =
{
    .tileTag = GFXTAG_MENU_HIGHLIGHT_LEFT,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_Swap_MenuHighlight,
    .anims = sAnims_Swap_Interface,
};

static const struct SpriteTemplate sSpriteTemplate_Swap_MenuHighlightRight =
{
    .tileTag = GFXTAG_MENU_HIGHLIGHT_RIGHT,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_Swap_MenuHighlight,
    .anims = sAnims_Swap_Interface,
};

static const struct SpriteTemplate sSpriteTemplate_Swap_MonPicBgAnim =
{
    .tileTag = GFXTAG_MON_PIC_BG_ANIM,
    .paletteTag = PALTAG_MON_PIC_BG,
    .oam = &sOam_Swap_MonPicBgAnim,
    .anims = sAnims_Swap_MonPicBgAnim,
    .affineAnims = sAffineAnims_Swap_MonPicBgAnim,
};

static const struct BgTemplate sSwap_BgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

enum {
    SWAP_WIN_TITLE,
    SWAP_WIN_SPECIES,
    SWAP_WIN_INFO,
    SWAP_WIN_CURSOR,
    SWAP_WIN_OPTIONS,
    SWAP_WIN_YES_NO,
    SWAP_WIN_ACTION_FADE, // Used for action text fading out during screen transition
    SWAP_WIN_SPECIES_AT_FADE, // Used to print species name stopped at current fade level
    SWAP_WIN_MON_CATEGORY,
};

static const struct WindowTemplate sSwap_WindowTemplates[] =
{
    [SWAP_WIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 12,
        .height = 2,
        .paletteNum = PALNUM_TEXT,
        .baseBlock = 0x0001,
    },
    [SWAP_WIN_SPECIES] = {
        .bg = 2,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 11,
        .height = 2,
        .paletteNum = PALNUM_FADE_TEXT,
        .baseBlock = 0x0019,
    },
    [SWAP_WIN_INFO] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 14,
        .width = 30,
        .height = 6,
        .paletteNum = PALNUM_TEXT,
        .baseBlock = 0x002f,
    },
    [SWAP_WIN_CURSOR] = {
        .bg = 0,
        .tilemapLeft = SWAP_CURSOR_WIN_LEFT,
        .tilemapTop = SWAP_CURSOR_WIN_TOP,
        .width = 30,
        .height = 10,
        .paletteNum = PALNUM_GRID,
        .baseBlock = 0x00e3,
    },
    [SWAP_WIN_OPTIONS] = {
        .bg = 2,
        .tilemapLeft = 21,
        .tilemapTop = 14,
        .width = 9,
        .height = 6,
        .paletteNum = PALNUM_TEXT,
        .baseBlock = 0x0030,
    },
    [SWAP_WIN_YES_NO] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 14,
        .width = 8,
        .height = 4,
        .paletteNum = PALNUM_TEXT,
        .baseBlock = 0x020f,
    },
    [SWAP_WIN_ACTION_FADE] = {
        .bg = 2,
        .tilemapLeft = 21,
        .tilemapTop = 15,
        .width = 9,
        .height = 5,
        .paletteNum = PALNUM_FADE_TEXT,
        .baseBlock = 0x0066,
    },
    [SWAP_WIN_SPECIES_AT_FADE] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 11,
        .height = 2,
        .paletteNum = PALNUM_TEXT,
        .baseBlock = 0x022f,
    },
    [SWAP_WIN_MON_CATEGORY] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 0,
        .width = 15,
        .height = 2,
        .paletteNum = PALNUM_TEXT,
        .baseBlock = 0x0245,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u16 sSwapText_Pal[] = INCBIN_U16("graphics/battle_frontier/factory_screen/text.gbapal"); // Identical to sSelectText_Pal
static const u8 sSwapMenuOptionsTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_TRANSPARENT};
static const u8 sSwapSpeciesNameTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_TRANSPARENT};

static void SpriteCB_Pokeball(struct Sprite *sprite)
{
    if (sprite->oam.paletteNum == IndexOfSpritePaletteTag(PALTAG_BALL_SELECTED))
    {
        // Poké Ball selected, do rocking animation
        if (sprite->animEnded)
        {
            if (sprite->data[0] != 0)
            {
                sprite->data[0]--;
            }
            else if (Random() % 5 == 0)
            {
                StartSpriteAnim(sprite, 0);
                sprite->data[0] = 32;
            }
            else
            {
                StartSpriteAnim(sprite, 1);
            }
        }
        else
        {
            StartSpriteAnimIfDifferent(sprite, 1);
        }
    }
    else
    {
        // Poké Ball not selected, remain still
        StartSpriteAnimIfDifferent(sprite, 0);
    }
}

static void CB2_SelectScreen(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void VBlankCB_SelectScreen(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static u8 Select_GetRequiredPicks(void)
{
    if (sFactorySelectRewardMode)
        return 1;
    return FRONTIER_PARTY_SIZE;
}

void DoBattleFactorySelectScreen(void)
{
    DebugPrintf("DoBattleFactorySelectScreen");
    sFactorySelectScreen = NULL;
    sFactorySelectRewardMode = FALSE;
    sFactorySelectOverrideCount = 0;
    sFactorySelectExitCallback = NULL;
    SetMainCallback2(CB2_InitSelectScreen);
}

void DoBattleFactoryRewardScreen(const struct Pokemon *choices, u8 count, MainCallback exitCallback)
{
    u8 i;

    DebugPrintf("DoBattleFactoryRewardScreen");
    sFactorySelectScreen = NULL;
    sFactorySelectRewardMode = TRUE;
    sFactorySelectExitCallback = exitCallback;
    sFactorySelectOverrideCount = (count < FACTORY_SELECT_OFFER_COUNT)
        ? count
        : FACTORY_SELECT_OFFER_COUNT;

    for (i = 0; i < sFactorySelectOverrideCount; i++)
        sFactorySelectOverrideMons[i] = choices[i];
    for (; i < FACTORY_SELECT_OFFER_COUNT; i++)
        ZeroMonData(&sFactorySelectOverrideMons[i]);

    SetMainCallback2(CB2_InitSelectScreen);
}

static void CB2_InitSelectScreen(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        TRY_FREE_AND_SET_NULL(sFactorySelectMons);
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSelect_BgTemplates, ARRAY_COUNT(sSelect_BgTemplates));
        InitWindows(sSelect_WindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 1:
        sSelectMenuTilesetBuffer = Alloc(sizeof(gFrontierFactoryMenu_Gfx));
#ifdef BUGFIX
        sSelectMonPicBgTilesetBuffer = AllocZeroed(sizeof(sMonPicBg_Gfx));
#else
        sSelectMonPicBgTilesetBuffer = AllocZeroed(sizeof(gFrontierFactoryMenu_Gfx)); // Incorrect size
#endif
        sSelectMenuTilemapBuffer = Alloc(BG_SCREEN_SIZE);
        sSelectMonPicBgTilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        CpuCopy16(gFrontierFactoryMenu_Gfx, sSelectMenuTilesetBuffer, sizeof(gFrontierFactoryMenu_Gfx));
        CpuCopy16(sMonPicBg_Gfx, sSelectMonPicBgTilesetBuffer, sizeof(sMonPicBg_Gfx));
        LoadBgTiles(1, sSelectMenuTilesetBuffer, sizeof(gFrontierFactoryMenu_Gfx), 0);
        LoadBgTiles(3, sSelectMonPicBgTilesetBuffer, sizeof(sMonPicBg_Gfx), 0);
        CpuCopy16(gFrontierFactoryMenu_Tilemap, sSelectMenuTilemapBuffer, BG_SCREEN_SIZE);
        LoadBgTilemap(1, sSelectMenuTilemapBuffer, BG_SCREEN_SIZE, 0);
	        LoadPalette(gFrontierFactoryMenu_Pal, 0, 2 * PLTT_SIZE_4BPP);
	        LoadPalette(sSelectText_Pal, BG_PLTT_ID(PALNUM_TEXT), PLTT_SIZEOF(4));
	        LoadPalette(sSelectText_Pal, BG_PLTT_ID(PALNUM_FADE_TEXT), PLTT_SIZEOF(5));
	        LoadPalette(sGridUi_Pal, BG_PLTT_ID(PALNUM_GRID), PLTT_SIZEOF(5));
        LoadPalette(sMonPicBg_Pal, BG_PLTT_ID(2), PLTT_SIZEOF(2));
        gMain.state++;
        break;
    case 3:
        SetBgTilemapBuffer(3, sSelectMonPicBgTilemapBuffer);
        CopyToBgTilemapBufferRect(3, sMonPicBg_Tilemap, 11, 4, 8, 8);
        CopyToBgTilemapBufferRect(3, sMonPicBg_Tilemap,  2, 4, 8, 8);
        CopyToBgTilemapBufferRect(3, sMonPicBg_Tilemap, 20, 4, 8, 8);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
	    case 4:
		        LoadSpritePalette(&sFactoryCaughtBall_Pal);
		        LoadCompressedSpriteSheet(&sFactoryCaughtBall_Gfx);
		        ShowBg(0);
		        HideBg(1);
		        HideBg(3);
		        SetVBlankCallback(VBlankCB_SelectScreen);
	        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
	        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
	        // Reset leftover WIN0/blending from older transitions.
	        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
	        SetGpuReg(REG_OFFSET_BLDCNT, 0);
	        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
	        gMain.state++;
	        break;
	    case 5:
	        Select_InitMonsData();
#ifdef UBFIX
	        if (sFactorySelectScreen && sFactorySelectScreen->fromSummaryScreen)
#else
	        if (sFactorySelectScreen->fromSummaryScreen == TRUE)
#endif
	        {
	            ChoiceMenu_SetCursorIndex(&sFactorySelectScreen->choice, gLastViewedMonIndex);
	            sFactorySelectScreen->cursorPos = sFactorySelectScreen->choice.cursorPos;
	            Select_RefreshVisibleMonsFromPage();
	        }
	        gMain.state++;
	        break;
	    case 6:
	        Select_PrintSelectMonString();
	        PutWindowTilemap(SELECT_WIN_INFO);
	        PutWindowTilemap(SELECT_WIN_LIST);
	        SelectGrid_InitIcons();
	        SelectGrid_DrawHighlights();
	        gMain.state++;
	        break;
	    case 7:
	        Select_PrintMonCategory();
	        PutWindowTilemap(SELECT_WIN_MON_CATEGORY);
        gMain.state++;
        break;
    case 8:
        Select_PrintMonSpecies();
        PutWindowTilemap(SELECT_WIN_SPECIES);
        gMain.state++;
        break;
    case 9:
        Select_PrintRentalPkmnString();
        PutWindowTilemap(SELECT_WIN_TITLE);
        gMain.state++;
        break;
	    case 10:
	        taskId = CreateTask(SelectGrid_Task_HandleInput, 0);
	        gTasks[taskId].tState = 0;
	        SetMainCallback2(CB2_SelectScreen);
	        break;
	    }
	}

static void Select_InitMonsData(void)
{
    u8 i;

    if (sFactorySelectScreen != NULL)
        return;

    sFactorySelectScreen = AllocZeroed(sizeof(*sFactorySelectScreen));
    sFactorySelectScreen->cursorPos = 0;
    if (sFactorySelectRewardMode)
        sFactorySelectScreen->offerCount = sFactorySelectOverrideCount;
    else
        sFactorySelectScreen->offerCount = (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
            ? SELECTABLE_MONS_COUNT
            : FACTORY_SELECT_OFFER_COUNT;

    if (sFactorySelectScreen->offerCount == 0)
        sFactorySelectScreen->offerCount = 1;

    ChoiceMenu_Init(&sFactorySelectScreen->choice, sFactorySelectScreen->offerCount,
        (sFactorySelectScreen->offerCount > FACTORY_GRID_COUNT) ? FACTORY_GRID_COUNT : sFactorySelectScreen->offerCount,
        Select_GetRequiredPicks(), TRUE);
    sFactorySelectScreen->fromSummaryScreen = FALSE;
    for (i = 0; i < FACTORY_SELECT_OFFER_COUNT; i++)
        sFactorySelectScreen->offerIconSpriteIds[i] = SPRITE_NONE;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        sFactorySelectScreen->pickedStripIconSpriteIds[i] = SPRITE_NONE;
    for (i = 0; i < FACTORY_SELECT_OFFER_COUNT; i++)
        sFactorySelectScreen->caughtBallSpriteIds[i] = SPRITE_NONE;
    sFactorySelectScreen->bobCounter = 0;
    sFactorySelectScreen->bobUp = TRUE;
    sFactorySelectScreen->bobPaused = FALSE;
    sFactorySelectScreen->lastCursorIdx = 0xFF;

    if (sFactorySelectRewardMode)
    {
        for (i = 0; i < sFactorySelectScreen->offerCount; i++)
        {
            sFactorySelectScreen->offers[i].monId = i;
            sFactorySelectScreen->offers[i].monData = sFactorySelectOverrideMons[i];
        }
    }
    else if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
    {
        CreateFrontierFactorySelectableMons(0);
    }
    else
    {
        CreateSlateportTentSelectableMons(0);
    }

    Select_RefreshVisibleMonsFromPage();
}

static void Select_RefreshVisibleMonsFromPage(void)
{
    u8 i;

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
    {
        u8 offerIdx = sFactorySelectScreen->choice.viewportTop + i;
        if (offerIdx < sFactorySelectScreen->offerCount)
        {
            sFactorySelectScreen->mons[i].monId = sFactorySelectScreen->offers[offerIdx].monId;
            sFactorySelectScreen->mons[i].monData = sFactorySelectScreen->offers[offerIdx].monData;
        }
        else
        {
            sFactorySelectScreen->mons[i].monId = 0xFFFF;
            ZeroMonData(&sFactorySelectScreen->mons[i].monData);
        }
    }
}

static void CreateFrontierFactorySelectableMons(u8 firstMonId)
{
    u8 i = 0;
    u8 ivs = 0;
    u32 otId = 0;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
    u8 rentalRank = 0;

    gFacilityTrainerMons = gBattleFrontierMons;

    rentalRank = GetNumPastRentalsRank(battleMode, lvlMode);
    otId = READ_OTID_FROM_SAVE;

    for (i = 0; i < sFactorySelectScreen->offerCount; i++)
    {
        u16 monId = gBattleFactoryInitialOfferMonIds[i];
        if (monId == 0xFFFF && i < SELECTABLE_MONS_COUNT)
            monId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;

        sFactorySelectScreen->offers[i].monId = monId;
        if (monId == 0xFFFF)
            continue;

        if (i < rentalRank)
            ivs = GetFactoryMonFixedIV(challengeNum + 1, FALSE);
        else
            ivs = GetFactoryMonFixedIV(challengeNum, FALSE);

        CreateFacilityMon(&gFacilityTrainerMons[monId],
                GetBattleFactoryMonLevel(monId), ivs, otId, FLAG_FRONTIER_MON_FACTORY,
                &sFactorySelectScreen->offers[i].monData);
    }
}

static void CreateSlateportTentSelectableMons(u8 firstMonId)
{
    u8 i;
    u8 ivs = 0;
    u8 level = TENT_MIN_LEVEL;
    u32 otId = 0;

    gFacilityTrainerMons = gSlateportBattleTentMons;
    otId = READ_OTID_FROM_SAVE;

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
        sFactorySelectScreen->offers[i].monId = monId;
        CreateFacilityMon(&gFacilityTrainerMons[monId], level, ivs, otId, 0, &sFactorySelectScreen->offers[i].monData);
    }
}

static void Select_CopyMonsToPlayerParty(void)
{
    u8 i, j;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        for (j = 0; j < sFactorySelectScreen->offerCount; j++)
        {
            if (ChoiceMenu_GetSelectionRank(&sFactorySelectScreen->choice, j) == i + 1)
            {
                gPlayerParty[i] = sFactorySelectScreen->offers[j].monData;
                gSaveBlock2Ptr->frontier.rentalMons[i].monId = sFactorySelectScreen->offers[j].monId;
                gSaveBlock2Ptr->frontier.rentalMons[i].personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
                gSaveBlock2Ptr->frontier.rentalMons[i].abilityNum = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ABILITY_NUM);
                gSaveBlock2Ptr->frontier.rentalMons[i].ivs = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ATK_IV);
                break;
            }
        }
    }
    CalculatePlayerPartyCount();
}

static void Select_PrintRentalPkmnString(void)
{
    static const u8 sText_Rentals[] = _("RENTALS");
    static const u8 sText_Rewards[] = _("REWARDS");

    FillWindowPixelBuffer(SELECT_WIN_TITLE, PIXEL_FILL(0));
    if (sFactorySelectRewardMode)
        AddTextPrinterParameterized(SELECT_WIN_TITLE, FONT_NORMAL, sText_Rewards, 2, 1, 0, NULL);
    else
        AddTextPrinterParameterized(SELECT_WIN_TITLE, FONT_NORMAL, sText_Rentals, 2, 1, 0, NULL);
    CopyWindowToVram(SELECT_WIN_TITLE, COPYWIN_FULL);
}

static void Select_PrintMonSpecies(void)
{
    u16 species;
    s32 x;
    const u8 *speciesName;
    u8 monId = ChoiceMenu_GetCursorIndex(&sFactorySelectScreen->choice);

    FillWindowPixelBuffer(SELECT_WIN_SPECIES, PIXEL_FILL(0));
    species = GetMonData(&sFactorySelectScreen->offers[monId].monData, MON_DATA_SPECIES);
    speciesName = GetSpeciesName(species);
    x = GetStringRightAlignXOffset(FONT_NORMAL, speciesName, 86);
    if (x < 0)
        x = 0;
    AddTextPrinterParameterized3(SELECT_WIN_SPECIES, FONT_NORMAL, x, 1, sSpeciesNameTextColors, 0, speciesName);
    CopyWindowToVram(SELECT_WIN_SPECIES, COPYWIN_GFX);
}

static void Select_PrintSelectMonString(void)
{
    const u8 *str = NULL;
    static const u8 sText_Controls[] = _("{A_BUTTON} Select  {B_BUTTON} Undo  {R_BUTTON} Summary");
    static const u8 sText_RewardControls[] = _("{A_BUTTON} Select  {R_BUTTON} Summary");
    static const u8 sText_SelectRewardMon[] = _("Select a reward {PKMN}.");
    static const u8 sText_KeepRewardMon[] = _("Keep this {PKMN}?");
    u8 selectingMonsState = sFactorySelectScreen->choice.picksMade + 1;
    u8 requiredPicks = Select_GetRequiredPicks();

    FillWindowPixelBuffer(SELECT_WIN_INFO, PIXEL_FILL(0));
    if (sFactorySelectRewardMode)
    {
        if (sFactorySelectScreen->choice.picksMade < requiredPicks)
            str = sText_SelectRewardMon;
        else
            str = sText_KeepRewardMon;
    }
    else if (selectingMonsState == 1)
    {
        str = gText_SelectFirstPkmn;
    }
    else if (selectingMonsState == 2)
    {
        str = gText_SelectSecondPkmn;
    }
    else if (selectingMonsState == 3)
    {
        str = gText_SelectThirdPkmn;
    }
    else
    {
        str = gText_TheseThreePkmnOkay;
    }

    AddTextPrinterParameterized(SELECT_WIN_INFO, FONT_NORMAL, str, 2, 1, 0, NULL);
    if (sFactorySelectRewardMode)
        AddTextPrinterParameterized(SELECT_WIN_INFO, FONT_NORMAL, sText_RewardControls, 2, 17, 0, NULL);
    else
        AddTextPrinterParameterized(SELECT_WIN_INFO, FONT_NORMAL, sText_Controls, 2, 17, 0, NULL);
    CopyWindowToVram(SELECT_WIN_INFO, COPYWIN_GFX);
}

static void SelectGrid_GetOfferIconCoords(u8 idx, s16 *x, s16 *y)
{
    if (sFactorySelectRewardMode && sFactorySelectScreen->offerCount <= FRONTIER_PARTY_SIZE)
    {
        u8 count = sFactorySelectScreen->offerCount;
        s16 startX = SWAP_ICON_START_X;

        if (count == 1)
            startX = SWAP_ICON_START_X + SWAP_ICON_X_SPACING;
        else if (count == 2)
            startX = SWAP_ICON_START_X + (SWAP_ICON_X_SPACING / 2);

        *x = startX + (idx * SWAP_ICON_X_SPACING);
        *y = SWAP_ICON_Y;
    }
    else
    {
        *x = FACTORY_GRID_START_X + (idx % FACTORY_GRID_COLS) * FACTORY_GRID_X_SPACING;
        *y = FACTORY_GRID_START_Y + (idx / FACTORY_GRID_COLS) * FACTORY_GRID_Y_SPACING;
    }
}

static void SelectGrid_InitIcons(void)
{
    u8 i;

    LoadMonIconPalettes();

    for (i = 0; i < sFactorySelectScreen->offerCount && i < FACTORY_GRID_COUNT; i++)
    {
        u16 species = GetMonData(&sFactorySelectScreen->offers[i].monData, MON_DATA_SPECIES);
        s16 x, y;

        SelectGrid_GetOfferIconCoords(i, &x, &y);

        if (sFactorySelectScreen->offerIconSpriteIds[i] == SPRITE_NONE)
            sFactorySelectScreen->offerIconSpriteIds[i] = CreateMonIconNoPersonality(species, SpriteCB_MonIcon, x, y, 2);
    }

    SelectGrid_InitPickedStripIcons();
    SelectGrid_InitCaughtBallSprites();
    SelectGrid_UpdateCursorBob(TRUE);
}

static void SelectGrid_DestroyIcons(void)
{
    u8 i;

    SelectGrid_DestroyPickedStripIcons();
    SelectGrid_DestroyCaughtBallSprites();
    for (i = 0; i < FACTORY_SELECT_OFFER_COUNT; i++)
    {
        if (sFactorySelectScreen->offerIconSpriteIds[i] != SPRITE_NONE)
        {
            FreeAndDestroyMonIconSprite(&gSprites[sFactorySelectScreen->offerIconSpriteIds[i]]);
            sFactorySelectScreen->offerIconSpriteIds[i] = SPRITE_NONE;
        }
    }

    FreeMonIconPalettes();
}

static void SelectGrid_InitPickedStripIcons(void)
{
    u8 i;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        sFactorySelectScreen->pickedStripIconSpriteIds[i] = SPRITE_NONE;

    SelectGrid_UpdatePickedStripIcons();
}

static void SelectGrid_DestroyPickedStripIcons(void)
{
    u8 i;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u8 spriteId = sFactorySelectScreen->pickedStripIconSpriteIds[i];
        if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
        {
            FreeSpriteOamMatrix(&gSprites[spriteId]);
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
        }
        sFactorySelectScreen->pickedStripIconSpriteIds[i] = SPRITE_NONE;
    }
}

static void SelectGrid_UpdatePickedStripIcons(void)
{
    u8 rank;
    static const s16 sStripX[FRONTIER_PARTY_SIZE] = { 24, 48, 72 };
    static const s16 sStripY = 44; // centered in strip box (y=36..51)

    if (sFactorySelectRewardMode)
    {
        for (rank = 0; rank < FRONTIER_PARTY_SIZE; rank++)
        {
            u8 spriteId = sFactorySelectScreen->pickedStripIconSpriteIds[rank];
            if (spriteId != SPRITE_NONE)
                gSprites[spriteId].invisible = TRUE;
        }
        return;
    }

    for (rank = 1; rank <= FRONTIER_PARTY_SIZE; rank++)
    {
        u8 slot = rank - 1;
        u8 i;
        u16 species = SPECIES_NONE;

        for (i = 0; i < sFactorySelectScreen->offerCount && i < FACTORY_GRID_COUNT; i++)
        {
            if (ChoiceMenu_GetSelectionRank(&sFactorySelectScreen->choice, i) == rank)
            {
                species = GetMonData(&sFactorySelectScreen->offers[i].monData, MON_DATA_SPECIES);
                break;
            }
        }

        if (species == SPECIES_NONE)
        {
            if (sFactorySelectScreen->pickedStripIconSpriteIds[slot] != SPRITE_NONE)
                gSprites[sFactorySelectScreen->pickedStripIconSpriteIds[slot]].invisible = TRUE;
            continue;
        }

        if (sFactorySelectScreen->pickedStripIconSpriteIds[slot] != SPRITE_NONE)
        {
            struct Sprite *spr = &gSprites[sFactorySelectScreen->pickedStripIconSpriteIds[slot]];
            if ((u16)spr->data[0] != species)
            {
                FreeSpriteOamMatrix(spr);
                FreeAndDestroyMonIconSprite(spr);
                sFactorySelectScreen->pickedStripIconSpriteIds[slot] = SPRITE_NONE;
            }
            else
            {
                // Ensure these icons stay scaled down and don't run any affine anim.
                spr->affineAnims = gDummySpriteAffineAnimTable;
                spr->affineAnimBeginning = FALSE;
                spr->affineAnimPaused = TRUE;
                spr->affineAnimEnded = TRUE;
            }
        }

        if (sFactorySelectScreen->pickedStripIconSpriteIds[slot] == SPRITE_NONE)
        {
            u8 spriteId = CreateMonIconNoPersonality(species, SpriteCB_MonIcon, sStripX[slot], sStripY, 0);
            if (spriteId == SPRITE_NONE)
                continue;
            sFactorySelectScreen->pickedStripIconSpriteIds[slot] = spriteId;
            gSprites[spriteId].data[0] = species;
            // Scale down to 16x16 using an allocated OAM matrix (so it won't be clobbered by other affine users).
            gSprites[spriteId].affineAnims = gDummySpriteAffineAnimTable;
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].oam.matrixNum = AllocOamMatrix();
            if (gSprites[spriteId].oam.matrixNum != 0xFF)
            {
                // NOTE: For OBJ affine matrices, values are effectively inverse scale.
                // 0x100 = 1.0x, 0x200 = 0.5x (half-size), 0x80 = 2.0x.
                SetOamMatrix(gSprites[spriteId].oam.matrixNum, 0x200, 0, 0, 0x200);
            }
            else
            {
                // If we can't allocate a matrix, don't enable affine (otherwise scaling will be unpredictable).
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_OFF;
            }
            // Prevent any affine anim init from touching the matrix on subsequent frames.
            gSprites[spriteId].affineAnimBeginning = FALSE;
            gSprites[spriteId].affineAnimPaused = TRUE;
            gSprites[spriteId].affineAnimEnded = TRUE;
            CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
        }

        gSprites[sFactorySelectScreen->pickedStripIconSpriteIds[slot]].x = sStripX[slot];
        gSprites[sFactorySelectScreen->pickedStripIconSpriteIds[slot]].y = sStripY;
        gSprites[sFactorySelectScreen->pickedStripIconSpriteIds[slot]].invisible = FALSE;
        // Re-assert the scale every update, in case other affine users modify shared matrices.
        if (gSprites[sFactorySelectScreen->pickedStripIconSpriteIds[slot]].oam.affineMode & ST_OAM_AFFINE_ON_MASK)
            SetOamMatrix(gSprites[sFactorySelectScreen->pickedStripIconSpriteIds[slot]].oam.matrixNum, 0x200, 0, 0, 0x200);
    }
}

static void SelectGrid_InitCaughtBallSprites(void)
{
    u8 i;

    for (i = 0; i < sFactorySelectScreen->offerCount && i < FACTORY_GRID_COUNT; i++)
    {
        if (sFactorySelectScreen->caughtBallSpriteIds[i] == SPRITE_NONE)
        {
            u8 spriteId = CreateSprite(&sSpriteTemplate_Select_CaughtBall, 0, 0, 0);
            if (spriteId != MAX_SPRITES)
            {
                sFactorySelectScreen->caughtBallSpriteIds[i] = spriteId;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                gSprites[spriteId].oam.matrixNum = AllocOamMatrix();
                if (gSprites[spriteId].oam.matrixNum != 0xFF)
                    SetOamMatrix(gSprites[spriteId].oam.matrixNum, 0x155, 0, 0, 0x155); // 16x16 -> ~12x12
                else
                    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_OFF;
                CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
                gSprites[spriteId].invisible = TRUE;
                StartSpriteAnim(&gSprites[spriteId], 0);
            }
        }
    }
    SelectGrid_UpdateCaughtBallSprites();
}

static void SelectGrid_DestroyCaughtBallSprites(void)
{
    u8 i;

    for (i = 0; i < FACTORY_SELECT_OFFER_COUNT; i++)
    {
        u8 spriteId = sFactorySelectScreen->caughtBallSpriteIds[i];
        if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
        {
            if (gSprites[spriteId].oam.affineMode & ST_OAM_AFFINE_ON_MASK)
                FreeSpriteOamMatrix(&gSprites[spriteId]);
            DestroySprite(&gSprites[spriteId]);
        }
        sFactorySelectScreen->caughtBallSpriteIds[i] = SPRITE_NONE;
    }
}

static void SelectGrid_UpdateCaughtBallSprites(void)
{
    u8 i;

    for (i = 0; i < sFactorySelectScreen->offerCount && i < FACTORY_GRID_COUNT; i++)
    {
        u8 spriteId = sFactorySelectScreen->caughtBallSpriteIds[i];
        u8 iconSpriteId = sFactorySelectScreen->offerIconSpriteIds[i];
        u16 species;
        u16 dexNum;

        if (spriteId == SPRITE_NONE || spriteId >= MAX_SPRITES || iconSpriteId == SPRITE_NONE)
            continue;

        species = GetMonData(&sFactorySelectScreen->offers[i].monData, MON_DATA_SPECIES);
        dexNum = SpeciesToNationalPokedexNum(species);

        // Anchor at the top-right of the icon.
        gSprites[spriteId].x = gSprites[iconSpriteId].x + 9;
        gSprites[spriteId].y = gSprites[iconSpriteId].y - 8;
        gSprites[spriteId].invisible = (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT) != TRUE);
    }
}

static void SelectGrid_DrawHighlights(void)
{
    u8 i;
    u8 cursorIdx = ChoiceMenu_GetCursorIndex(&sFactorySelectScreen->choice);
    u8 y;

    // BG panel behind icons + highlight borders/labels
    FillWindowPixelBuffer(SELECT_WIN_LIST, FACTORY_GRID_BG_FILL);
    // Add subtle horizontal stripes so the panel doesn't look like a flat rectangle.
    for (y = 0; y < (sSelect_WindowTemplates[SELECT_WIN_LIST].height * 8); y += 16)
        FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_BG_STRIPE_FILL, 0, y, sSelect_WindowTemplates[SELECT_WIN_LIST].width * 8, 8);

    if (!sFactorySelectRewardMode)
    {
        // Picked strip (order left->right). This is meant to be reusable for other choice screens too.
        FillWindowPixelRect(SELECT_WIN_LIST, PIXEL_FILL(0), 8, 4, 76, 16);
        FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_SEL_FILL, 8, 4, 76, 1);
        FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_SEL_FILL, 8, 19, 76, 1);
        FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_SEL_FILL, 8, 4, 1, 16);
        FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_SEL_FILL, 83, 4, 1, 16);
    }

    // Cursor-only highlight (selection state is shown via the picked strip).
    for (i = 0; i < sFactorySelectScreen->offerCount && i < FACTORY_GRID_COUNT; i++)
    {
        if (i == cursorIdx)
        {
            s16 x, y;
            // Window coords are relative to its top-left in pixels.
            s16 winX;
            s16 winY;
            u8 thickness = 2;

            SelectGrid_GetOfferIconCoords(i, &x, &y);
            winX = (x - 16) - (sSelect_WindowTemplates[SELECT_WIN_LIST].tilemapLeft * 8);
            winY = (y - 16) - (sSelect_WindowTemplates[SELECT_WIN_LIST].tilemapTop * 8);

            if (winX < 0) winX = 0;
            if (winY < 0) winY = 0;
            // Border highlight so we don't cover the icon.
            FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_CURSOR_FILL, winX, winY, 32, thickness);
            FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_CURSOR_FILL, winX, winY + 32 - thickness, 32, thickness);
            FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_CURSOR_FILL, winX, winY, thickness, 32);
            FillWindowPixelRect(SELECT_WIN_LIST, FACTORY_GRID_CURSOR_FILL, winX + 32 - thickness, winY, thickness, 32);
            break;
        }
    }

    CopyWindowToVram(SELECT_WIN_LIST, COPYWIN_GFX);
    SelectGrid_UpdatePickedStripIcons();
    SelectGrid_UpdateCaughtBallSprites();
}

static void SelectGrid_UpdateCursorBob(bool8 reset)
{
    u8 i;
    u8 idx;
    u8 spriteId;
    s16 baseY;
    s16 offsetY;
    u8 selectedRank;

    if (sFactorySelectScreen->bobPaused)
        return;

    // First, reset all offer icons to their base Y so only the cursor target can bob.
    for (i = 0; i < sFactorySelectScreen->offerCount && i < FACTORY_GRID_COUNT; i++)
    {
        s16 baseX;
        if (sFactorySelectScreen->offerIconSpriteIds[i] == SPRITE_NONE)
            continue;
        SelectGrid_GetOfferIconCoords(i, &baseX, &baseY);
        gSprites[sFactorySelectScreen->offerIconSpriteIds[i]].x = baseX;
        gSprites[sFactorySelectScreen->offerIconSpriteIds[i]].y = baseY;
    }

    idx = ChoiceMenu_GetCursorIndex(&sFactorySelectScreen->choice);
    if (idx >= sFactorySelectScreen->offerCount || idx >= FACTORY_GRID_COUNT)
        return;

    spriteId = sFactorySelectScreen->offerIconSpriteIds[idx];
    if (spriteId == SPRITE_NONE)
        return;

    {
        s16 baseX;
        SelectGrid_GetOfferIconCoords(idx, &baseX, &baseY);
        gSprites[spriteId].x = baseX;
    }
    selectedRank = ChoiceMenu_GetSelectionRank(&sFactorySelectScreen->choice, idx);
    if (selectedRank == 0)
    {
        // Only bob selected mons. Ensure unselected cursor mon is at its base position.
        if (reset || sFactorySelectScreen->lastCursorIdx != idx)
            sFactorySelectScreen->lastCursorIdx = idx;
        return;
    }
    if (reset || sFactorySelectScreen->lastCursorIdx != idx)
    {
        sFactorySelectScreen->bobCounter = 0;
        sFactorySelectScreen->bobUp = TRUE;
        sFactorySelectScreen->lastCursorIdx = idx;
    }

    if (++sFactorySelectScreen->bobCounter >= 10)
    {
        sFactorySelectScreen->bobCounter = 0;
        sFactorySelectScreen->bobUp ^= 1;
    }

    offsetY = sFactorySelectScreen->bobUp ? -2 : 0;
    gSprites[spriteId].y = baseY + offsetY;
    SelectGrid_UpdateCaughtBallSprites();
}

static void SelectGrid_DeselectLastPick(void)
{
    u8 i;
    u8 rank = sFactorySelectScreen->choice.picksMade;

    if (rank == 0)
        return;

    for (i = 0; i < sFactorySelectScreen->offerCount; i++)
    {
        if (ChoiceMenu_GetSelectionRank(&sFactorySelectScreen->choice, i) == rank)
        {
            ChoiceMenu_ToggleSelection(&sFactorySelectScreen->choice, i);
            break;
        }
    }

    Select_PrintSelectMonString();
    SelectGrid_DrawHighlights();
    SelectGrid_UpdatePickedStripIcons();
    Select_PrintMonCategory();
    Select_PrintMonSpecies();
}

static void SelectGrid_ShowYesNoPrompt(void)
{
    FillWindowPixelBuffer(SELECT_WIN_YES_NO, PIXEL_FILL(0));
    PutWindowTilemap(SELECT_WIN_YES_NO);
    AddTextPrinterParameterized3(SELECT_WIN_YES_NO, FONT_NORMAL, 16, 1, sMenuOptionTextColors, 0, gText_Yes2);
    AddTextPrinterParameterized3(SELECT_WIN_YES_NO, FONT_NORMAL, 16, 17, sMenuOptionTextColors, 0, gText_No2);
    AddTextPrinterParameterized(SELECT_WIN_YES_NO, FONT_NORMAL, gText_SelectorArrow2, 0, 1, 0, NULL);
    CopyWindowToVram(SELECT_WIN_YES_NO, COPYWIN_FULL);
    ScheduleBgCopyTilemapToVram(0);
    CopyBgTilemapBufferToVram(0);

    sFactorySelectScreen->bobPaused = TRUE;
    SelectGrid_DrawHighlights();
}

static void SelectGrid_UpdateYesNoCursor(void)
{
    FillWindowPixelBuffer(SELECT_WIN_YES_NO, PIXEL_FILL(0));
    AddTextPrinterParameterized3(SELECT_WIN_YES_NO, FONT_NORMAL, 16, 1, sMenuOptionTextColors, 0, gText_Yes2);
    AddTextPrinterParameterized3(SELECT_WIN_YES_NO, FONT_NORMAL, 16, 17, sMenuOptionTextColors, 0, gText_No2);
    AddTextPrinterParameterized(SELECT_WIN_YES_NO, FONT_NORMAL, gText_SelectorArrow2, 0, sFactorySelectScreen->yesNoCursorPos ? 17 : 1, 0, NULL);
    CopyWindowToVram(SELECT_WIN_YES_NO, COPYWIN_FULL);
}

static void SelectGrid_EraseYesNoPrompt(void)
{
    FillWindowPixelBuffer(SELECT_WIN_YES_NO, PIXEL_FILL(0));
    CopyWindowToVram(SELECT_WIN_YES_NO, COPYWIN_GFX);
    ClearWindowTilemap(SELECT_WIN_YES_NO);
    // Restore other windows' tilemaps in case the prompt overlapped them.
    PutWindowTilemap(SELECT_WIN_LIST);
    PutWindowTilemap(SELECT_WIN_INFO);
    PutWindowTilemap(SELECT_WIN_SPECIES);
    PutWindowTilemap(SELECT_WIN_MON_CATEGORY);
    PutWindowTilemap(SELECT_WIN_TITLE);
    ScheduleBgCopyTilemapToVram(0);
    CopyBgTilemapBufferToVram(0);

    sFactorySelectScreen->bobPaused = FALSE;
    SelectGrid_DrawHighlights();
    SelectGrid_UpdateCursorBob(TRUE);
}

static void SelectGrid_MoveCursor(s8 dx, s8 dy)
{
    s8 col;
    s8 row;
    u8 idx = ChoiceMenu_GetCursorIndex(&sFactorySelectScreen->choice);

    col = idx % FACTORY_GRID_COLS;
    row = idx / FACTORY_GRID_COLS;

    if (dx)
    {
        col += dx;
        while (col < 0) col += FACTORY_GRID_COLS;
        while (col >= FACTORY_GRID_COLS) col -= FACTORY_GRID_COLS;
    }
    if (dy)
    {
        row += dy;
        while (row < 0) row += FACTORY_GRID_ROWS;
        while (row >= FACTORY_GRID_ROWS) row -= FACTORY_GRID_ROWS;
    }

    idx = (row * FACTORY_GRID_COLS) + col;
    if (idx >= sFactorySelectScreen->offerCount)
        idx = 0;

    ChoiceMenu_SetCursorIndex(&sFactorySelectScreen->choice, idx);
    sFactorySelectScreen->cursorPos = sFactorySelectScreen->choice.cursorPos;
    SelectGrid_DrawHighlights();
    SelectGrid_UpdateCursorBob(TRUE);
    Select_PrintMonCategory();
    Select_PrintMonSpecies();
}

static void SelectGrid_Task_HandleInput(u8 taskId)
{
    u8 offerIdx;
    u16 monId;
    u8 requiredPicks = Select_GetRequiredPicks();

    SelectGrid_UpdateCursorBob(FALSE);
    SelectGrid_UpdateCaughtBallSprites();

    if (JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = SelectGrid_Task_OpenSummaryScreen;
        return;
    }

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        SelectGrid_DeselectLastPick();
        return;
    }

    if (JOY_REPEAT(DPAD_LEFT))
    {
        PlaySE(SE_SELECT);
        SelectGrid_MoveCursor(-1, 0);
        return;
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        PlaySE(SE_SELECT);
        SelectGrid_MoveCursor(1, 0);
        return;
    }
    else if (JOY_REPEAT(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        SelectGrid_MoveCursor(0, -1);
        return;
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        SelectGrid_MoveCursor(0, 1);
        return;
    }

    if (JOY_NEW(A_BUTTON))
    {
        offerIdx = ChoiceMenu_GetCursorIndex(&sFactorySelectScreen->choice);
        monId = sFactorySelectScreen->offers[offerIdx].monId;

        if (!sFactorySelectRewardMode
            && ChoiceMenu_GetSelectionRank(&sFactorySelectScreen->choice, offerIdx) == 0
            && !Select_AreSpeciesValid(monId))
        {
            PlaySE(SE_BOO);
            Select_PrintCantSelectSameMon();
            return;
        }

        if (ChoiceMenu_ToggleSelection(&sFactorySelectScreen->choice, offerIdx) == CHOICE_TOGGLE_FULL)
        {
            PlaySE(SE_BOO);
            return;
        }

        PlaySE(SE_SELECT);
        Select_PrintSelectMonString();
        SelectGrid_DrawHighlights();
        SelectGrid_UpdateCursorBob(TRUE);

        if (sFactorySelectScreen->choice.picksMade >= requiredPicks)
        {
            sFactorySelectScreen->yesNoCursorPos = 0;
            SelectGrid_ShowYesNoPrompt();
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = SelectGrid_Task_HandleYesNo;
        }
    }
}

static void SelectGrid_Task_HandleYesNo(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sFactorySelectScreen->yesNoCursorPos == 0)
        {
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = SelectGrid_Task_Exit;
        }
        else
        {
            SelectGrid_EraseYesNoPrompt();
            SelectGrid_DeselectLastPick();
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = SelectGrid_Task_HandleInput;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        SelectGrid_EraseYesNoPrompt();
        SelectGrid_DeselectLastPick();
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = SelectGrid_Task_HandleInput;
    }
    else if (JOY_REPEAT(DPAD_UP) || JOY_REPEAT(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        sFactorySelectScreen->yesNoCursorPos ^= 1;
        SelectGrid_UpdateYesNoCursor();
    }
}

static void SelectGrid_Task_Exit(u8 taskId)
{
    u8 i;
    MainCallback exitCallback = CB2_ReturnToFieldContinueScript;

    switch (gTasks[taskId].tState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tState++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            if (sFactorySelectRewardMode)
            {
                gSpecialVar_Result = 0;
                for (i = 0; i < sFactorySelectScreen->offerCount; i++)
                {
                    if (ChoiceMenu_GetSelectionRank(&sFactorySelectScreen->choice, i) == 1)
                    {
                        gSpecialVar_Result = i;
                        break;
                    }
                }
                if (sFactorySelectExitCallback != NULL)
                    exitCallback = sFactorySelectExitCallback;
            }
            else
            {
                Select_CopyMonsToPlayerParty();
            }

            SelectGrid_DestroyIcons();
            FREE_AND_SET_NULL(sSelectMenuTilesetBuffer);
            FREE_AND_SET_NULL(sSelectMenuTilemapBuffer);
            FREE_AND_SET_NULL(sSelectMonPicBgTilemapBuffer);
            FREE_AND_SET_NULL(sSelectMonPicBgTilesetBuffer);
            FREE_AND_SET_NULL(sFactorySelectScreen);
            sFactorySelectRewardMode = FALSE;
            sFactorySelectOverrideCount = 0;
            sFactorySelectExitCallback = NULL;
            FreeAllWindowBuffers();
            SetMainCallback2(exitCallback);
            DestroyTask(taskId);
        }
        break;
    }
}

static void SelectGrid_Task_OpenSummaryScreen(u8 taskId)
{
    u8 i;
    u8 currMonId;

    switch (gTasks[taskId].tState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SelectGrid_DestroyIcons();
            FREE_AND_SET_NULL(sSelectMenuTilesetBuffer);
            FREE_AND_SET_NULL(sSelectMenuTilemapBuffer);
            FREE_AND_SET_NULL(sSelectMonPicBgTilemapBuffer);
            FREE_AND_SET_NULL(sSelectMonPicBgTilesetBuffer);
            FreeAllWindowBuffers();

            DestroyTask(taskId);
            sFactorySelectScreen->fromSummaryScreen = TRUE;
            currMonId = ChoiceMenu_GetCursorIndex(&sFactorySelectScreen->choice);
            sFactorySelectMons = AllocZeroed(sizeof(struct Pokemon) * sFactorySelectScreen->offerCount);
            for (i = 0; i < sFactorySelectScreen->offerCount; i++)
                sFactorySelectMons[i] = sFactorySelectScreen->offers[i].monData;
            ShowPokemonSummaryScreen(SUMMARY_MODE_LOCK_MOVES, sFactorySelectMons, currMonId, sFactorySelectScreen->offerCount - 1, CB2_InitSelectScreen);
        }
        break;
    }
}

static void Select_PrintCantSelectSameMon(void)
{
    FillWindowPixelBuffer(SELECT_WIN_INFO, PIXEL_FILL(0));
    AddTextPrinterParameterized(SELECT_WIN_INFO, FONT_NORMAL, gText_CantSelectSamePkmn, 2, 5, 0, NULL);
    CopyWindowToVram(SELECT_WIN_INFO, COPYWIN_GFX);
}

static void Select_PrintMonCategory(void)
{
    u16 species;
    u8 text[30];
    u8 x;
    u8 monId = ChoiceMenu_GetCursorIndex(&sFactorySelectScreen->choice);
    if (monId < sFactorySelectScreen->offerCount)
    {
        PutWindowTilemap(SELECT_WIN_MON_CATEGORY);
        FillWindowPixelBuffer(SELECT_WIN_MON_CATEGORY, PIXEL_FILL(0));
        species = GetMonData(&sFactorySelectScreen->offers[monId].monData, MON_DATA_SPECIES);
        CopyMonCategoryText(species, text);
        x = GetStringRightAlignXOffset(FONT_NORMAL, text, 118);
        AddTextPrinterParameterized(SELECT_WIN_MON_CATEGORY, FONT_NORMAL, text, x, 1, 0, NULL);
        CopyWindowToVram(SELECT_WIN_MON_CATEGORY, COPYWIN_GFX);
    }
}

static bool32 Select_AreSpeciesValid(u16 monId)
{
    u8 j;
    u32 species = gFacilityTrainerMons[monId].species;

    for (j = 0; j < sFactorySelectScreen->offerCount; j++)
    {
        if (ChoiceMenu_GetSelectionRank(&sFactorySelectScreen->choice, j) != 0
            && gFacilityTrainerMons[sFactorySelectScreen->offers[j].monId].species == species)
        {
            return FALSE;
        }
    }
    return TRUE;
}

// Swap Screen's section begins here.

static void Swap_CB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void Swap_VblankCb(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CopySwappedMonData(void)
{
    u8 friendship;

    gPlayerParty[sFactorySwapScreen->playerMonId] = gEnemyParty[sFactorySwapScreen->enemyMonId];
    friendship = 0;
    SetMonData(&gPlayerParty[sFactorySwapScreen->playerMonId], MON_DATA_FRIENDSHIP, &friendship);
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].monId = gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->enemyMonId + FRONTIER_PARTY_SIZE].monId;
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].ivs = gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->enemyMonId + FRONTIER_PARTY_SIZE].ivs;
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].personality = GetMonData(&gEnemyParty[sFactorySwapScreen->enemyMonId], MON_DATA_PERSONALITY);
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].abilityNum = GetBoxMonData(&gEnemyParty[sFactorySwapScreen->enemyMonId].box, MON_DATA_ABILITY_NUM);
}

// Main swap states
// States for the main tasks of the Swap_ functions after initialization, including:
// Swap_Task_OpenSummaryScreen, Swap_Task_HandleYesNo, Swap_Task_HandleMenu, and Swap_Task_HandleChooseMons
// Tasks sharing states was unnecessary, see "Main select states"
#define STATE_CHOOSE_MONS_INIT 0
#define STATE_CHOOSE_MONS_HANDLE_INPUT 1
#define STATE_MENU_INIT 2
#define STATE_MENU_HANDLE_INPUT 3
#define STATE_YESNO_SHOW  4
#define STATE_YESNO_HANDLE_INPUT 5
#define STATE_SUMMARY_FADE 6
#define STATE_SUMMARY_CLEAN 7
#define STATE_SUMMARY_SHOW 8
#define STATE_MENU_SHOW_OPTIONS 9

static void Swap_Task_OpenSummaryScreen(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case STATE_SUMMARY_FADE:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tState = STATE_SUMMARY_CLEAN;
        break;
    case STATE_SUMMARY_CLEAN:
        if (!gPaletteFade.active)
        {
            DestroyTask(sFactorySwapScreen->fadeSpeciesNameTaskId);
            HideMonPic(sFactorySwapScreen->monPic, &sFactorySwapScreen->monPicAnimating);
            Swap_DestroyAllSprites();
            FREE_AND_SET_NULL(sSwapMenuTilesetBuffer);
            FREE_AND_SET_NULL(sSwapMonPicBgTilesetBuffer);
            FREE_AND_SET_NULL(sSwapMenuTilemapBuffer);
            FREE_AND_SET_NULL(sSwapMonPicBgTilemapBuffer);
            FreeAllWindowBuffers();
            gTasks[taskId].tState = STATE_SUMMARY_SHOW;
        }
        break;
    case STATE_SUMMARY_SHOW:
        DestroyTask(taskId);
        sFactorySwapScreen->fromSummaryScreen = TRUE;
        sFactorySwapScreen->speciesNameColorBackup = gPlttBufferUnfaded[BG_PLTT_ID(PALNUM_TEXT) + 4];
        if (sFactorySwapScreen->inEnemyScreen)
            ShowPokemonSummaryScreen(SUMMARY_MODE_NORMAL, gEnemyParty, sFactorySwapScreen->cursorPos, FRONTIER_PARTY_SIZE - 1, CB2_InitSwapScreen);
        else
            ShowPokemonSummaryScreen(SUMMARY_MODE_NORMAL, gPlayerParty, sFactorySwapScreen->cursorPos, FRONTIER_PARTY_SIZE - 1, CB2_InitSwapScreen);
        break;
    }
}

static void Swap_Task_Exit(u8 taskId)
{
    if (sFactorySwapScreen->monPicAnimating == TRUE)
        return;

    switch (gTasks[taskId].tState)
    {
    case 0:
        // Set return value for script
        // TRUE if player kept their current Pokémon
        if (sFactorySwapScreen->monSwapped == TRUE)
        {
            gTasks[taskId].tState++;
            gSpecialVar_Result = FALSE;
        }
        else
        {
            gTasks[taskId].tState = 2;
            gSpecialVar_Result = TRUE;
        }
        break;
    case 1:
        if (sFactorySwapScreen->monSwapped == TRUE)
        {
            sFactorySwapScreen->enemyMonId = sFactorySwapScreen->cursorPos;
            CopySwappedMonData();
        }
        gTasks[taskId].tState++;
        break;
    case 2:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tState++;
        break;
    case 3:
        if (!UpdatePaletteFade())
        {
            DestroyTask(sFactorySwapScreen->fadeSpeciesNameTaskId);
            Swap_DestroyAllSprites();
            FREE_AND_SET_NULL(sSwapMenuTilesetBuffer);
            FREE_AND_SET_NULL(sSwapMonPicBgTilesetBuffer);
            FREE_AND_SET_NULL(sSwapMenuTilemapBuffer);
            FREE_AND_SET_NULL(sSwapMonPicBgTilemapBuffer);
            FREE_AND_SET_NULL(sFactorySwapScreen);
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_ReturnToFieldContinueScript);
            DestroyTask(taskId);
        }
        break;
    }
}

#define tSaidYes           data[1]
#define tFollowUpTaskState data[5]
#define tFollowUpTaskPtrHi data[6]
#define tFollowUpTaskPtrLo data[7]

static void Swap_Task_HandleYesNo(u8 taskId)
{
    u16 loPtr, hiPtr;

    if (sFactorySwapScreen->monPicAnimating == TRUE)
        return;

    switch (gTasks[taskId].tState)
    {
    case STATE_YESNO_SHOW:
        Swap_ShowYesNoOptions();
        gTasks[taskId].tState = STATE_YESNO_HANDLE_INPUT;
        break;
    case STATE_YESNO_HANDLE_INPUT:
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (sFactorySwapScreen->yesNoCursorPos == 0)
            {
                // Selected Yes
                gTasks[taskId].tSaidYes = TRUE;
                hiPtr = gTasks[taskId].tFollowUpTaskPtrHi;
                loPtr = gTasks[taskId].tFollowUpTaskPtrLo;
                gTasks[taskId].func = (void *)((hiPtr << 16) | loPtr);
            }
            else
            {
                // Selected No
                gTasks[taskId].tSaidYes = FALSE;
                Swap_ErasePopupMenu(SWAP_WIN_YES_NO);
                hiPtr = gTasks[taskId].tFollowUpTaskPtrHi;
                loPtr = gTasks[taskId].tFollowUpTaskPtrLo;
                gTasks[taskId].func = (void *)((hiPtr << 16) | loPtr);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gTasks[taskId].tSaidYes = FALSE;
            Swap_ErasePopupMenu(SWAP_WIN_YES_NO);
            hiPtr = gTasks[taskId].tFollowUpTaskPtrHi;
            loPtr = gTasks[taskId].tFollowUpTaskPtrLo;
            gTasks[taskId].func = (void *)((hiPtr << 16) | loPtr);
        }
        else if (JOY_REPEAT(DPAD_UP))
        {
            PlaySE(SE_SELECT);
            Swap_UpdateYesNoCursorPosition(-1);
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            Swap_UpdateYesNoCursorPosition(1);
        }
        break;
    }
}

static void Swap_HandleQuitSwappingResponse(u8 taskId)
{
    if (gTasks[taskId].tSaidYes == TRUE)
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Swap_Task_Exit;
    }
    else
    {
        Swap_EraseSpeciesAtFadeWindow();
        Swap_PrintChoosePrompt();
        Swap_PrintMonCategory();
        Swap_PrintMonSpecies();
        Swap_UpdateMonIcons();
        Swap_UpdateCursorBox();
        sFactorySwapScreen->fadeSpeciesNameActive = TRUE;
        gTasks[taskId].tState = STATE_CHOOSE_MONS_HANDLE_INPUT;
        gTasks[taskId].func = Swap_Task_HandleChooseMons;
    }
}

static void Swap_AskQuitSwapping(u8 taskId)
{
    if (gTasks[taskId].tState == 0)
    {
        Swap_PrintOnInfoWindow(gText_QuitSwapping);
        sFactorySwapScreen->monSwapped = FALSE;
        gTasks[taskId].tState = STATE_YESNO_SHOW;
        gTasks[taskId].tFollowUpTaskPtrHi = (u32)(Swap_HandleQuitSwappingResponse) >> 16;
        gTasks[taskId].tFollowUpTaskPtrLo = (u32)(Swap_HandleQuitSwappingResponse);
        gTasks[taskId].func = Swap_Task_HandleYesNo;
    }
}

static void Swap_HandleAcceptMonResponse(u8 taskId)
{
    if (gTasks[taskId].tSaidYes == TRUE)
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Swap_Task_Exit;
    }
    else
    {
        sFactorySwapScreen->monSwapped = FALSE;
        Swap_EraseSpeciesAtFadeWindow();
        Swap_PrintChoosePrompt();
        Swap_PrintMonCategory();
        Swap_PrintMonSpecies();
        Swap_UpdateMonIcons();
        Swap_UpdateCursorBox();
        sFactorySwapScreen->fadeSpeciesNameActive = TRUE;
        gTasks[taskId].tState = STATE_CHOOSE_MONS_HANDLE_INPUT;
        gTasks[taskId].func = Swap_Task_HandleChooseMons;
    }
}

static void Swap_AskAcceptMon(u8 taskId)
{
    if (gTasks[taskId].tState == 0)
    {
        Swap_PrintOnInfoWindow(gText_AcceptThisPkmn);
        sFactorySwapScreen->monSwapped = TRUE;
        gTasks[taskId].tState = STATE_YESNO_SHOW;
        gTasks[taskId].tFollowUpTaskPtrHi = (u32)(Swap_HandleAcceptMonResponse) >> 16;
        gTasks[taskId].tFollowUpTaskPtrLo = (u32)(Swap_HandleAcceptMonResponse);
        gTasks[taskId].func = Swap_Task_HandleYesNo;
    }
}

// Handles input on the two main swap screens (choosing a current pokeon to get rid of, and choosing a new Pokémon to receive)
static void Swap_Task_HandleChooseMons(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case STATE_CHOOSE_MONS_INIT:
        if (!gPaletteFade.active)
        {
            sFactorySwapScreen->fadeSpeciesNameActive = TRUE;
            Swap_UpdateCursorBox();
            gTasks[taskId].tState = STATE_CHOOSE_MONS_HANDLE_INPUT;
        }
        break;
    case STATE_CHOOSE_MONS_HANDLE_INPUT:
        if (JOY_NEW(A_BUTTON))
        {
            // Run whatever action is currently selected (a Poké Ball, the Cancel button, etc.)
            PlaySE(SE_SELECT);
            sFactorySwapScreen->fadeSpeciesNameActive = FALSE;
            Swap_PrintMonSpeciesAtFade();
            Swap_EraseSpeciesWindow();
            Swap_RunActionFunc(taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (sFactorySwapScreen->inEnemyScreen)
            {
                Swap_InitActions(SWAP_PLAYER_SCREEN);
                Swap_EraseSpeciesAtFadeWindow();
                Swap_PrintChoosePrompt();
                Swap_PrintMonCategory();
                Swap_PrintMonSpecies();
                Swap_UpdateMonIcons();
                Swap_HideActionButtonHighlights();
                Swap_UpdateCursorBox();
            }
            else
            {
                sFactorySwapScreen->fadeSpeciesNameActive = FALSE;
                gTasks[taskId].tState = 0;
                gTasks[taskId].func = Swap_AskQuitSwapping;
            }
        }
        else if (JOY_NEW(R_BUTTON)
              && sFactorySwapScreen->cursorPos < FRONTIER_PARTY_SIZE)
        {
            PlaySE(SE_SELECT);
            sFactorySwapScreen->fadeSpeciesNameActive = FALSE;
            Swap_PrintMonSpeciesAtFade();
            Swap_EraseSpeciesWindow();
            gTasks[taskId].tState = STATE_SUMMARY_FADE;
            gTasks[taskId].func = Swap_Task_OpenSummaryScreen;
        }
        else if (JOY_REPEAT(DPAD_LEFT))
        {
            Swap_UpdateBallCursorPosition(-1);
            Swap_PrintMonCategory();
            Swap_PrintMonSpecies();
            Swap_UpdateMonIcons();
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            Swap_UpdateBallCursorPosition(1);
            Swap_PrintMonCategory();
            Swap_PrintMonSpecies();
            Swap_UpdateMonIcons();
        }
        break;
    }
}

static void Swap_Task_FadeSpeciesName(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case FADESTATE_INIT:
        sFactorySwapScreen->fadeSpeciesNameCoeffDelay = 0;
        sFactorySwapScreen->fadeSpeciesNameCoeff = 0;
        sFactorySwapScreen->fadeSpeciesNameFadeOut = TRUE;
        gTasks[taskId].tState = FADESTATE_RUN;
        break;
    case FADESTATE_RUN:
        if (sFactorySwapScreen->fadeSpeciesNameActive)
        {
            if (sFactorySwapScreen->faceSpeciesNameDelay)
            {
                gTasks[taskId].tState = FADESTATE_DELAY;
            }
            else
            {
                sFactorySwapScreen->fadeSpeciesNameCoeffDelay++;
                if (sFactorySwapScreen->fadeSpeciesNameCoeffDelay > 6)
                {
                    sFactorySwapScreen->fadeSpeciesNameCoeffDelay = 0;
                    if (!sFactorySwapScreen->fadeSpeciesNameFadeOut)
                        sFactorySwapScreen->fadeSpeciesNameCoeff--;
                    else
                        sFactorySwapScreen->fadeSpeciesNameCoeff++;
                }
                BlendPalettes(1 << PALNUM_FADE_TEXT, sFactorySwapScreen->fadeSpeciesNameCoeff, 0);
                if (sFactorySwapScreen->fadeSpeciesNameCoeff > 5)
                {
                    sFactorySwapScreen->fadeSpeciesNameFadeOut = FALSE;
                }
                else if (sFactorySwapScreen->fadeSpeciesNameCoeff == 0)
                {
                    gTasks[taskId].tState = FADESTATE_DELAY;
                    sFactorySwapScreen->fadeSpeciesNameFadeOut = TRUE;
                }
            }
        }
        break;
    case FADESTATE_DELAY:
        if (sFactorySwapScreen->faceSpeciesNameDelay > 14)
        {
            sFactorySwapScreen->faceSpeciesNameDelay = 0;
            gTasks[taskId].tState = FADESTATE_RUN;
        }
        else
        {
            sFactorySwapScreen->faceSpeciesNameDelay++;
        }
        break;
    }
}

static void Swap_InitStruct(void)
{
    u8 i;

    if (sFactorySwapScreen == NULL)
    {
        sFactorySwapScreen = AllocZeroed(sizeof(*sFactorySwapScreen));
        sFactorySwapScreen->cursorPos = 0;
        sFactorySwapScreen->monPicAnimating = FALSE;
        sFactorySwapScreen->fromSummaryScreen = FALSE;
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            sFactorySwapScreen->playerIconSpriteIds[i] = SPRITE_NONE;
            sFactorySwapScreen->enemyIconSpriteIds[i] = SPRITE_NONE;
        }
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            sFactorySwapScreen->mapIconSpriteIds[i] = SPRITE_NONE;
    }
}

void DoBattleFactorySwapScreen(void)
{
    sFactorySwapScreen = NULL;
    SetMainCallback2(CB2_InitSwapScreen);
}

static void CB2_InitSwapScreen(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSwap_BgTemplates, ARRAY_COUNT(sSwap_BgTemplates));
        InitWindows(sSwap_WindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 1:
        sSwapMenuTilesetBuffer = Alloc(sizeof(gFrontierFactoryMenu_Gfx));
#ifdef BUGFIX
        sSwapMonPicBgTilesetBuffer = AllocZeroed(sizeof(sMonPicBg_Gfx));
#else
        sSwapMonPicBgTilesetBuffer = AllocZeroed(sizeof(gFrontierFactoryMenu_Gfx)); // Incorrect size
#endif
        sSwapMenuTilemapBuffer = Alloc(BG_SCREEN_SIZE);
        sSwapMonPicBgTilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        ResetAllPicSprites();
        CpuCopy16(gFrontierFactoryMenu_Gfx, sSwapMenuTilesetBuffer, sizeof(gFrontierFactoryMenu_Gfx));
        CpuCopy16(sMonPicBg_Gfx, sSwapMonPicBgTilesetBuffer, sizeof(sMonPicBg_Gfx));
        LoadBgTiles(1, sSwapMenuTilesetBuffer, sizeof(gFrontierFactoryMenu_Gfx), 0);
        LoadBgTiles(3, sSwapMonPicBgTilesetBuffer, sizeof(sMonPicBg_Gfx), 0);
        CpuCopy16(gFrontierFactoryMenu_Tilemap, sSwapMenuTilemapBuffer, BG_SCREEN_SIZE);
        LoadBgTilemap(1, sSwapMenuTilemapBuffer, BG_SCREEN_SIZE, 0);
        LoadPalette(gFrontierFactoryMenu_Pal, 0, 2 * PLTT_SIZE_4BPP);
        LoadPalette(sSwapText_Pal, BG_PLTT_ID(PALNUM_TEXT), sizeof(sSwapText_Pal));
        LoadPalette(sSwapText_Pal, BG_PLTT_ID(PALNUM_FADE_TEXT), sizeof(sSwapText_Pal));
        LoadPalette(sGridUi_Pal, BG_PLTT_ID(PALNUM_GRID), PLTT_SIZEOF(5));
        LoadPalette(sMonPicBg_Pal, BG_PLTT_ID(2), PLTT_SIZEOF(2));
        gMain.state++;
        break;
    case 3:
        SetBgTilemapBuffer(3, sSwapMonPicBgTilemapBuffer);
        CopyToBgTilemapBufferRect(3, sMonPicBg_Tilemap, 11, 4, 8, 8);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        LoadSpritePalettes(sSwap_SpritePalettes);
        LoadSpriteSheets(sSwap_SpriteSheets);
        LoadCompressedSpriteSheet(sSwap_BallGfx);
        SetVBlankCallback(Swap_VblankCb);
        gMain.state++;
        break;
    case 5:
#ifdef UBFIX
        if (sFactorySwapScreen && sFactorySwapScreen->fromSummaryScreen)
#else
        if (sFactorySwapScreen->fromSummaryScreen == TRUE)
#endif
        {
            sFactorySwapScreen->cursorPos = gLastViewedMonIndex;
        }
        gMain.state++;
        break;
    case 6:
        Swap_InitStruct();
        Swap_InitAllSprites();
        Swap_InitActions(sFactorySwapScreen->inEnemyScreen ? SWAP_ENEMY_SCREEN : SWAP_PLAYER_SCREEN);
        sFactorySwapScreen->fromSummaryScreen = FALSE;
        gMain.state++;
        break;
    case 7:
        Swap_PrintChoosePrompt();
        PutWindowTilemap(SWAP_WIN_INFO);
        gMain.state++;
        break;
    case 8:
        Swap_PrintMonCategory();
        PutWindowTilemap(SWAP_WIN_MON_CATEGORY);
        gMain.state++;
        break;
    case 9:
        Swap_PrintMonSpecies();
        PutWindowTilemap(SWAP_WIN_SPECIES);
        gMain.state++;
        break;
    case 10:
        Swap_PrintPkmnSwap();
        PutWindowTilemap(SWAP_WIN_TITLE);
        gMain.state++;
        break;
    case 11:
        Swap_UpdateCursorBox();
        gMain.state++;
        break;
    case 12:
        gMain.state++;
        break;
    case 13:
        FillWindowPixelBuffer(SWAP_WIN_OPTIONS, PIXEL_FILL(0));
        CopyWindowToVram(SWAP_WIN_OPTIONS, COPYWIN_GFX);
        ClearWindowTilemap(SWAP_WIN_OPTIONS);
        gMain.state++;
        break;
    case 14:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        HideBg(1);
        ShowBg(2);
        HideBg(3);
        gMain.state++;
        break;
    case 15:
        sFactorySwapScreen->fadeSpeciesNameTaskId = CreateTask(Swap_Task_FadeSpeciesName, 0);
        gTasks[sFactorySwapScreen->fadeSpeciesNameTaskId].tState = FADESTATE_INIT;
        taskId = CreateTask(Swap_Task_HandleChooseMons, 0);
        gTasks[taskId].tState = STATE_CHOOSE_MONS_INIT;
        Swap_UpdateMonIcons();
        Swap_UpdateCursorBox();
        SetMainCallback2(Swap_CB2);
        break;
    }
}

static void Swap_InitAllSprites(void)
{
    u8 i;
    u8 x;
    struct SpriteTemplate spriteTemplate;

    spriteTemplate = sSpriteTemplate_Swap_Pokeball;
    spriteTemplate.paletteTag = PALTAG_BALL_SELECTED;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        sFactorySwapScreen->ballSpriteIds[i] = CreateSprite(&spriteTemplate, (48 * i) + 72, 64, 1);
        gSprites[sFactorySwapScreen->ballSpriteIds[i]].data[0] = 0;
        gSprites[sFactorySwapScreen->ballSpriteIds[i]].invisible = TRUE;
    }
    sFactorySwapScreen->cursorSpriteId = CreateSprite(&sSpriteTemplate_Swap_Arrow, gSprites[sFactorySwapScreen->ballSpriteIds[sFactorySwapScreen->cursorPos]].x, 88, 0);
    gSprites[sFactorySwapScreen->cursorSpriteId].invisible = TRUE;
    sFactorySwapScreen->menuCursor1SpriteId = CreateSprite(&sSpriteTemplate_Swap_MenuHighlightLeft, 176, 112, 0);
    sFactorySwapScreen->menuCursor2SpriteId = CreateSprite(&sSpriteTemplate_Swap_MenuHighlightRight, 176, 144, 0);
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = TRUE;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = TRUE;
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].centerToCornerVecX = 0;
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].centerToCornerVecY = 0;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].centerToCornerVecX = 0;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].centerToCornerVecY = 0;

    if (sFactorySwapScreen->fromSummaryScreen == TRUE)
        x = DISPLAY_WIDTH;
    else
        x = DISPLAY_WIDTH - 48;

    // Unusual way to create sprites
    // The sprite template for the selector arrow is re-used
    // with the tiles swapped out
    spriteTemplate = sSpriteTemplate_Swap_Arrow;
    spriteTemplate.tileTag = GFXTAG_ACTION_BOX_LEFT;
    sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0][0] = CreateSprite(&spriteTemplate, DISPLAY_WIDTH, 120, 10);

    spriteTemplate = sSpriteTemplate_Swap_MenuHighlightLeft;
    spriteTemplate.tileTag = GFXTAG_ACTION_BOX_RIGHT;
    sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0][1] = CreateSprite(&spriteTemplate, DISPLAY_WIDTH + 16, 120, 10);
    sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0][2] = CreateSprite(&spriteTemplate, DISPLAY_WIDTH + 48, 120, 10);

    spriteTemplate = sSpriteTemplate_Swap_Arrow;
    spriteTemplate.tileTag = GFXTAG_ACTION_HIGHLIGHT_LEFT;
    sFactorySwapScreen->pkmnForSwapButtonSpriteIds[1][0] = CreateSprite(&spriteTemplate, DISPLAY_WIDTH, 120, 1);

    spriteTemplate = sSpriteTemplate_Swap_MenuHighlightLeft;
    spriteTemplate.tileTag = GFXTAG_ACTION_HIGHLIGHT_MIDDLE;
    sFactorySwapScreen->pkmnForSwapButtonSpriteIds[1][1] = CreateSprite(&spriteTemplate, DISPLAY_WIDTH + 16, 120, 1);
    spriteTemplate.tileTag = GFXTAG_ACTION_HIGHLIGHT_RIGHT;
    sFactorySwapScreen->pkmnForSwapButtonSpriteIds[1][2] = CreateSprite(&spriteTemplate, DISPLAY_WIDTH + 48, 120, 1);

    spriteTemplate = sSpriteTemplate_Swap_Arrow;
    spriteTemplate.tileTag = GFXTAG_ACTION_BOX_LEFT;
    sFactorySwapScreen->cancelButtonSpriteIds[0][0] = CreateSprite(&spriteTemplate, x, 144, 10);

    spriteTemplate = sSpriteTemplate_Swap_MenuHighlightLeft;
    spriteTemplate.tileTag = GFXTAG_ACTION_BOX_RIGHT;
    sFactorySwapScreen->cancelButtonSpriteIds[0][1] = CreateSprite(&spriteTemplate, x + 16, 144, 10);

    spriteTemplate = sSpriteTemplate_Swap_Arrow;
    spriteTemplate.tileTag = GFXTAG_ACTION_HIGHLIGHT_LEFT;
    sFactorySwapScreen->cancelButtonSpriteIds[1][0] = CreateSprite(&spriteTemplate, x, 144, 1);

    spriteTemplate = sSpriteTemplate_Swap_MenuHighlightLeft;
    spriteTemplate.tileTag = GFXTAG_ACTION_HIGHLIGHT_RIGHT;
    sFactorySwapScreen->cancelButtonSpriteIds[1][1] = CreateSprite(&spriteTemplate, x + 16, 144, 1);

    for (i = 0; i < 2; i++)
    {
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][0]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][0]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][1]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][1]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][2]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][2]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->cancelButtonSpriteIds[i][0]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->cancelButtonSpriteIds[i][0]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->cancelButtonSpriteIds[i][1]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->cancelButtonSpriteIds[i][1]].centerToCornerVecY = 0;

        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][0]].invisible = TRUE;
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][1]].invisible = TRUE;
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][2]].invisible = TRUE;
        gSprites[sFactorySwapScreen->cancelButtonSpriteIds[i][0]].invisible = TRUE;
        gSprites[sFactorySwapScreen->cancelButtonSpriteIds[i][1]].invisible = TRUE;
    }

    gSprites[sFactorySwapScreen->cancelButtonSpriteIds[0][0]].invisible = TRUE;
    gSprites[sFactorySwapScreen->cancelButtonSpriteIds[0][1]].invisible = TRUE;
    gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0][0]].invisible = TRUE;
    gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0][1]].invisible = TRUE;
    gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0][2]].invisible = TRUE;

    Swap_InitMonIcons();
}

static void Swap_DestroyAllSprites(void)
{
    u8 i, j;

    Swap_DestroyMonIcons();

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        DestroySprite(&gSprites[sFactorySwapScreen->ballSpriteIds[i]]);
    DestroySprite(&gSprites[sFactorySwapScreen->cursorSpriteId]);
    DestroySprite(&gSprites[sFactorySwapScreen->menuCursor1SpriteId]);
    DestroySprite(&gSprites[sFactorySwapScreen->menuCursor2SpriteId]);
    for (i = 0; i < ARRAY_COUNT(sFactorySwapScreen->pkmnForSwapButtonSpriteIds); i++)
    {
        for (j = 0; j < ARRAY_COUNT(sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0]); j++)
            DestroySprite(&gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[i][j]]);
    }
    for (i = 0; i < ARRAY_COUNT(sFactorySwapScreen->cancelButtonSpriteIds); i++)
    {
        for (j = 0; j < ARRAY_COUNT(sFactorySwapScreen->cancelButtonSpriteIds[0]); j++)
            DestroySprite(&gSprites[sFactorySwapScreen->cancelButtonSpriteIds[i][j]]);
    }
}

static void Swap_InitMonIcons(void)
{
    LoadMonIconPalettes();
    Swap_UpdateMonIcons();
}

static void Swap_DestroyMonIcons(void)
{
    u8 i;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u8 spriteId = sFactorySwapScreen->playerIconSpriteIds[i];
        if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
        sFactorySwapScreen->playerIconSpriteIds[i] = SPRITE_NONE;

        spriteId = sFactorySwapScreen->enemyIconSpriteIds[i];
        if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
        sFactorySwapScreen->enemyIconSpriteIds[i] = SPRITE_NONE;
    }

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u8 spriteId = sFactorySwapScreen->mapIconSpriteIds[i];
        if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
        {
            if (gSprites[spriteId].oam.affineMode & ST_OAM_AFFINE_ON_MASK)
                FreeSpriteOamMatrix(&gSprites[spriteId]);
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
        }
        sFactorySwapScreen->mapIconSpriteIds[i] = SPRITE_NONE;
    }

    FreeMonIconPalettes();
}

static void Swap_UpdateMonIcons(void)
{
    u8 i;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        u8 spriteId = sFactorySwapScreen->playerIconSpriteIds[i];
        s16 x = SWAP_ICON_START_X + (i * SWAP_ICON_X_SPACING);

        if (spriteId != SPRITE_NONE && (u16)gSprites[spriteId].data[0] != species)
        {
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
            sFactorySwapScreen->playerIconSpriteIds[i] = SPRITE_NONE;
            spriteId = SPRITE_NONE;
        }
        if (spriteId == SPRITE_NONE)
        {
            spriteId = CreateMonIconNoPersonality(species, SpriteCB_MonIcon, x, SWAP_ICON_Y, 2);
            if (spriteId != SPRITE_NONE)
            {
                sFactorySwapScreen->playerIconSpriteIds[i] = spriteId;
                gSprites[spriteId].data[0] = species;
            }
        }

        species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES);
        spriteId = sFactorySwapScreen->enemyIconSpriteIds[i];
        if (spriteId != SPRITE_NONE && (u16)gSprites[spriteId].data[0] != species)
        {
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
            sFactorySwapScreen->enemyIconSpriteIds[i] = SPRITE_NONE;
            spriteId = SPRITE_NONE;
        }
        if (spriteId == SPRITE_NONE)
        {
            spriteId = CreateMonIconNoPersonality(species, SpriteCB_MonIcon, x, SWAP_ICON_Y, 2);
            if (spriteId != SPRITE_NONE)
            {
                sFactorySwapScreen->enemyIconSpriteIds[i] = spriteId;
                gSprites[spriteId].data[0] = species;
            }
        }

        if (sFactorySwapScreen->playerIconSpriteIds[i] != SPRITE_NONE)
        {
            spriteId = sFactorySwapScreen->playerIconSpriteIds[i];
            gSprites[spriteId].x = x;
            gSprites[spriteId].y = SWAP_ICON_Y;
            gSprites[spriteId].invisible = sFactorySwapScreen->inEnemyScreen;
        }
        if (sFactorySwapScreen->enemyIconSpriteIds[i] != SPRITE_NONE)
        {
            spriteId = sFactorySwapScreen->enemyIconSpriteIds[i];
            gSprites[spriteId].x = x;
            gSprites[spriteId].y = SWAP_ICON_Y;
            gSprites[spriteId].invisible = !sFactorySwapScreen->inEnemyScreen;
        }
    }

    Swap_UpdateSwapMapIcons();
}

static void Swap_UpdateSwapMapIcons(void)
{
    u16 species[FRONTIER_PARTY_SIZE] = {SPECIES_NONE, SPECIES_NONE, SPECIES_NONE};
    static const s16 sMapX[FRONTIER_PARTY_SIZE] = {24, 48, 72};
    static const s16 sMapY = 44;
    u8 i;

    if (sFactorySwapScreen->inEnemyScreen
     && sFactorySwapScreen->playerMonId < FRONTIER_PARTY_SIZE
     && sFactorySwapScreen->cursorPos < FRONTIER_PARTY_SIZE)
    {
        // Preview final team in party order:
        // current team with the chosen outgoing slot replaced by highlighted enemy mon.
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            species[i] = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        species[sFactorySwapScreen->playerMonId] = GetMonData(&gEnemyParty[sFactorySwapScreen->cursorPos], MON_DATA_SPECIES);
    }

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u8 spriteId = sFactorySwapScreen->mapIconSpriteIds[i];

        if (species[i] == SPECIES_NONE)
        {
            if (spriteId != SPRITE_NONE)
                gSprites[spriteId].invisible = TRUE;
            continue;
        }

        if (spriteId != SPRITE_NONE && (u16)gSprites[spriteId].data[0] != species[i])
        {
            if (gSprites[spriteId].oam.affineMode & ST_OAM_AFFINE_ON_MASK)
                FreeSpriteOamMatrix(&gSprites[spriteId]);
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
            sFactorySwapScreen->mapIconSpriteIds[i] = SPRITE_NONE;
            spriteId = SPRITE_NONE;
        }

        if (spriteId == SPRITE_NONE)
        {
            spriteId = CreateMonIconNoPersonality(species[i], SpriteCB_MonIcon, sMapX[i], sMapY, 0);
            if (spriteId == SPRITE_NONE)
                continue;
            sFactorySwapScreen->mapIconSpriteIds[i] = spriteId;
            gSprites[spriteId].data[0] = species[i];
            gSprites[spriteId].affineAnims = gDummySpriteAffineAnimTable;
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].oam.matrixNum = AllocOamMatrix();
            if (gSprites[spriteId].oam.matrixNum != 0xFF)
                SetOamMatrix(gSprites[spriteId].oam.matrixNum, 0x200, 0, 0, 0x200);
            else
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_OFF;
            gSprites[spriteId].affineAnimBeginning = FALSE;
            gSprites[spriteId].affineAnimPaused = TRUE;
            gSprites[spriteId].affineAnimEnded = TRUE;
            CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
        }

        gSprites[sFactorySwapScreen->mapIconSpriteIds[i]].x = sMapX[i];
        gSprites[sFactorySwapScreen->mapIconSpriteIds[i]].y = sMapY;
        gSprites[sFactorySwapScreen->mapIconSpriteIds[i]].invisible = FALSE;
        if (gSprites[sFactorySwapScreen->mapIconSpriteIds[i]].oam.affineMode & ST_OAM_AFFINE_ON_MASK)
            SetOamMatrix(gSprites[sFactorySwapScreen->mapIconSpriteIds[i]].oam.matrixNum, 0x200, 0, 0, 0x200);
    }
}

static void Swap_InitChoiceState(u8 initialCursorPos)
{
    ChoiceMenu_Init(&sFactorySwapScreen->choice, FRONTIER_PARTY_SIZE, FRONTIER_PARTY_SIZE, 1, FALSE);
    ChoiceMenu_SetCursorIndex(&sFactorySwapScreen->choice, initialCursorPos);
    sFactorySwapScreen->cursorPos = ChoiceMenu_GetCursorIndex(&sFactorySwapScreen->choice);
}

static u8 Swap_GetCursorPos(void)
{
    sFactorySwapScreen->cursorPos = ChoiceMenu_GetCursorIndex(&sFactorySwapScreen->choice);
    return sFactorySwapScreen->cursorPos;
}

static void Swap_SetCursorPos(u8 cursorPos)
{
    ChoiceMenu_SetCursorIndex(&sFactorySwapScreen->choice, cursorPos);
    sFactorySwapScreen->cursorPos = ChoiceMenu_GetCursorIndex(&sFactorySwapScreen->choice);
}

static void Swap_UpdateBallCursorPosition(s8 direction)
{
    u8 cursorPos;
    PlaySE(SE_SELECT);
    cursorPos = Swap_GetCursorPos();
    if (direction > 0) // Move cursor right.
    {
        if (cursorPos + 1 != FRONTIER_PARTY_SIZE)
            cursorPos++;
        else
            cursorPos = 0;
    }
    else // Move cursor left.
    {
        if (cursorPos != 0)
            cursorPos--;
        else
            cursorPos = FRONTIER_PARTY_SIZE - 1;
    }

    Swap_SetCursorPos(cursorPos);
    Swap_HideActionButtonHighlights();
    Swap_UpdateCursorBox();
}

static void Swap_UpdateYesNoCursorPosition(s8 direction)
{
    if (direction > 0) // Move cursor down.
    {
        if (sFactorySwapScreen->yesNoCursorPos != 1)
            sFactorySwapScreen->yesNoCursorPos++;
        else
            sFactorySwapScreen->yesNoCursorPos = 0;
    }
    else // Move cursor up.
    {
        if (sFactorySwapScreen->yesNoCursorPos != 0)
            sFactorySwapScreen->yesNoCursorPos--;
        else
            sFactorySwapScreen->yesNoCursorPos = 1;
    }

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].y = (sFactorySwapScreen->yesNoCursorPos * 16) + 112;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].y = (sFactorySwapScreen->yesNoCursorPos * 16) + 112;
}

static void Swap_HideActionButtonHighlights(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sFactorySwapScreen->pkmnForSwapButtonSpriteIds[0]); i++)
    {
        // Hide button highlight on "Pkmn for Swap"
        gSprites[sFactorySwapScreen->pkmnForSwapButtonSpriteIds[1][i]].invisible = TRUE;

        // Hide button highlight on Cancel
        if (i < ARRAY_COUNT(sFactorySwapScreen->cancelButtonSpriteIds[0]))
            gSprites[sFactorySwapScreen->cancelButtonSpriteIds[1][i]].invisible = TRUE;
    }
}

static void Swap_ShowYesNoOptions(void)
{
    sFactorySwapScreen->yesNoCursorPos = 0;

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].x = 176;
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].y = 112;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].x = 208;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].y = 112;

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = FALSE;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = FALSE;

    Swap_PrintYesNoOptions();
}

static void Swap_ErasePopupMenu(u8 windowId)
{
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = TRUE;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = TRUE;
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    CopyWindowToVram(windowId, COPYWIN_GFX);
    ClearWindowTilemap(windowId);
}

static void Swap_EraseSpeciesWindow(void)
{
    PutWindowTilemap(SWAP_WIN_SPECIES);
    FillWindowPixelBuffer(SWAP_WIN_SPECIES, PIXEL_FILL(0));
    CopyWindowToVram(SWAP_WIN_SPECIES, COPYWIN_GFX);
}

static void Swap_EraseSpeciesAtFadeWindow(void)
{
    PutWindowTilemap(SWAP_WIN_SPECIES_AT_FADE);
    FillWindowPixelBuffer(SWAP_WIN_SPECIES_AT_FADE, PIXEL_FILL(0));
    CopyWindowToVram(SWAP_WIN_SPECIES_AT_FADE, COPYWIN_GFX);
}

static void Swap_PrintPkmnSwap(void)
{
    FillWindowPixelBuffer(SWAP_WIN_TITLE, PIXEL_FILL(1));
    AddTextPrinterParameterized(SWAP_WIN_TITLE, FONT_NORMAL, gText_PkmnSwap, 2, 1, 0, NULL);
    CopyWindowToVram(SWAP_WIN_TITLE, COPYWIN_FULL);
}

static void Swap_PrintMonSpecies(void)
{
    u16 species;
    u8 x;

    FillWindowPixelBuffer(SWAP_WIN_SPECIES, PIXEL_FILL(0));
    if (sFactorySwapScreen->cursorPos >= FRONTIER_PARTY_SIZE)
    {
        CopyWindowToVram(SWAP_WIN_SPECIES, COPYWIN_GFX);
    }
    else
    {
        u8 monId = sFactorySwapScreen->cursorPos;
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES);
        StringCopy(gStringVar4, GetSpeciesName(species));
        x = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 86);
        AddTextPrinterParameterized3(SWAP_WIN_SPECIES, FONT_NORMAL, x, 1, sSwapSpeciesNameTextColors, 0, gStringVar4);
        CopyWindowToVram(SWAP_WIN_SPECIES, COPYWIN_FULL);
    }
}

static void Swap_PrintChoosePrompt(void)
{
    static const u8 sText_ChooseControlsPlayer[] = _("{A_BUTTON} Select  {B_BUTTON} Cancel  {R_BUTTON} Summary");
    static const u8 sText_ChooseControlsEnemy[] = _("{A_BUTTON} Select  {B_BUTTON} Back  {R_BUTTON} Summary");

    FillWindowPixelBuffer(SWAP_WIN_INFO, PIXEL_FILL(0));
    if (!sFactorySwapScreen->inEnemyScreen)
        AddTextPrinterParameterized(SWAP_WIN_INFO, FONT_NORMAL, gText_SelectPkmnToSwap, 2, 1, 0, NULL);
    else
        AddTextPrinterParameterized(SWAP_WIN_INFO, FONT_NORMAL, gText_SelectPkmnToAccept, 2, 1, 0, NULL);

    if (sFactorySwapScreen->inEnemyScreen)
    {
        AddTextPrinterParameterized(SWAP_WIN_INFO, FONT_NORMAL, sText_ChooseControlsEnemy, 2, 17, 0, NULL);
    }
    else
    {
        AddTextPrinterParameterized(SWAP_WIN_INFO, FONT_NORMAL, sText_ChooseControlsPlayer, 2, 17, 0, NULL);
    }
    CopyWindowToVram(SWAP_WIN_INFO, COPYWIN_GFX);

    // Keep legacy action/yes-no windows hidden in the new chooser flow.
    FillWindowPixelBuffer(SWAP_WIN_OPTIONS, PIXEL_FILL(0));
    CopyWindowToVram(SWAP_WIN_OPTIONS, COPYWIN_GFX);
    ClearWindowTilemap(SWAP_WIN_OPTIONS);
    FillWindowPixelBuffer(SWAP_WIN_ACTION_FADE, PIXEL_FILL(0));
    CopyWindowToVram(SWAP_WIN_ACTION_FADE, COPYWIN_GFX);
    ClearWindowTilemap(SWAP_WIN_ACTION_FADE);
    FillWindowPixelBuffer(SWAP_WIN_YES_NO, PIXEL_FILL(0));
    CopyWindowToVram(SWAP_WIN_YES_NO, COPYWIN_GFX);
    ClearWindowTilemap(SWAP_WIN_YES_NO);
}

static void Swap_UpdateCursorBox(void)
{
    s16 winX;
    s16 winY;
    u8 y;
    u8 thickness = 2;

    PutWindowTilemap(SWAP_WIN_CURSOR);
    FillWindowPixelBuffer(SWAP_WIN_CURSOR, FACTORY_GRID_BG_FILL);
    for (y = 0; y < (sSwap_WindowTemplates[SWAP_WIN_CURSOR].height * 8); y += 16)
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_BG_STRIPE_FILL, 0, y, sSwap_WindowTemplates[SWAP_WIN_CURSOR].width * 8, 8);

    if (sFactorySwapScreen->inEnemyScreen)
    {
        FillWindowPixelRect(SWAP_WIN_CURSOR, PIXEL_FILL(0), 8, 4, 76, 16);
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_SEL_FILL, 8, 4, 76, 1);
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_SEL_FILL, 8, 19, 76, 1);
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_SEL_FILL, 8, 4, 1, 16);
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_SEL_FILL, 83, 4, 1, 16);
    }

    if (sFactorySwapScreen->cursorPos < FRONTIER_PARTY_SIZE)
    {
        winX = (SWAP_ICON_START_X + sFactorySwapScreen->cursorPos * SWAP_ICON_X_SPACING - 16) - SWAP_CURSOR_WIN_LEFT * 8;
        winY = (SWAP_ICON_Y - 16) - SWAP_CURSOR_WIN_TOP * 8;
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_CURSOR_FILL, winX, winY, 32, thickness);
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_CURSOR_FILL, winX, winY + 32 - thickness, 32, thickness);
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_CURSOR_FILL, winX, winY, thickness, 32);
        FillWindowPixelRect(SWAP_WIN_CURSOR, FACTORY_GRID_CURSOR_FILL, winX + 32 - thickness, winY, thickness, 32);
    }

    CopyWindowToVram(SWAP_WIN_CURSOR, COPYWIN_FULL);
}

static void Swap_PrintOnInfoWindow(const u8 *str)
{
    FillWindowPixelBuffer(SWAP_WIN_INFO, PIXEL_FILL(0));
    AddTextPrinterParameterized(SWAP_WIN_INFO, FONT_NORMAL, str, 2, 5, 0, NULL);
    CopyWindowToVram(SWAP_WIN_INFO, COPYWIN_GFX);
}

static void Swap_PrintYesNoOptions(void)
{
    PutWindowTilemap(SWAP_WIN_YES_NO);
    FillWindowPixelBuffer(SWAP_WIN_YES_NO, PIXEL_FILL(0));
    AddTextPrinterParameterized3(SWAP_WIN_YES_NO, FONT_NORMAL, 7, 1,  sSwapMenuOptionsTextColors, 0, gText_Yes3);
    AddTextPrinterParameterized3(SWAP_WIN_YES_NO, FONT_NORMAL, 7, 17, sSwapMenuOptionsTextColors, 0, gText_No3);
    CopyWindowToVram(SWAP_WIN_YES_NO, COPYWIN_FULL);
}

// For printing the species name once its selected. Keep the current fade but don't keep fading in and out
static void Swap_PrintMonSpeciesAtFade(void)
{
    u16 species;
    u8 x;
    u16 pal[5];

    CpuCopy16(sSwapText_Pal, pal, 8);
    if (!sFactorySwapScreen->fromSummaryScreen)
        pal[4] = gPlttBufferFaded[BG_PLTT_ID(PALNUM_FADE_TEXT) + 4];
    else
        pal[4] = sFactorySwapScreen->speciesNameColorBackup;
    LoadPalette(pal, BG_PLTT_ID(PALNUM_TEXT), sizeof(sSwapText_Pal));

    PutWindowTilemap(SWAP_WIN_SPECIES_AT_FADE);
    FillWindowPixelBuffer(SWAP_WIN_SPECIES_AT_FADE, PIXEL_FILL(0));
    if (sFactorySwapScreen->cursorPos >= FRONTIER_PARTY_SIZE)
    {
        CopyWindowToVram(SWAP_WIN_SPECIES_AT_FADE, COPYWIN_FULL);
    }
    else
    {
        u8 monId = sFactorySwapScreen->cursorPos;
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES);
        StringCopy(gStringVar4, GetSpeciesName(species));
        x = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 86);
        AddTextPrinterParameterized3(SWAP_WIN_SPECIES_AT_FADE, FONT_NORMAL, x, 1, sSwapSpeciesNameTextColors, 0, gStringVar4);
        CopyWindowToVram(SWAP_WIN_SPECIES_AT_FADE, COPYWIN_FULL);
    }
}

// Reprints the species name over the faded one after a transition
static void Swap_PrintMonSpeciesForTransition(void)
{
    u16 species;
    u8 x;

    LoadPalette(sSwapText_Pal, BG_PLTT_ID(PALNUM_FADE_TEXT), sizeof(sSwapText_Pal));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(PALNUM_TEXT)], &gPlttBufferFaded[BG_PLTT_ID(PALNUM_FADE_TEXT)], PLTT_SIZEOF(5));

    if (sFactorySwapScreen->cursorPos >= FRONTIER_PARTY_SIZE)
    {
        CopyWindowToVram(SWAP_WIN_SPECIES, COPYWIN_GFX);
    }
    else
    {
        u8 monId = sFactorySwapScreen->cursorPos;
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES);
        StringCopy(gStringVar4, GetSpeciesName(species));
        x = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 86);
        AddTextPrinterParameterized3(SWAP_WIN_SPECIES, FONT_NORMAL, x, 1, sSwapSpeciesNameTextColors, 0, gStringVar4);
        CopyWindowToVram(SWAP_WIN_SPECIES, COPYWIN_FULL);
    }
}

static void Swap_PrintMonCategory(void)
{
    u16 species;
    u8 text[30];
    u8 x;
    u8 monId = sFactorySwapScreen->cursorPos;

    FillWindowPixelBuffer(SWAP_WIN_MON_CATEGORY, PIXEL_FILL(0));
    if (monId >= FRONTIER_PARTY_SIZE)
    {
        CopyWindowToVram(SWAP_WIN_MON_CATEGORY, COPYWIN_GFX);
    }
    else
    {
        PutWindowTilemap(SWAP_WIN_MON_CATEGORY);
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES);
        CopyMonCategoryText(species, text);
        x = GetStringRightAlignXOffset(FONT_NORMAL, text, 118);
        AddTextPrinterParameterized(SWAP_WIN_MON_CATEGORY, FONT_NORMAL, text, x, 1, 0, NULL);
        CopyWindowToVram(SWAP_WIN_MON_CATEGORY, COPYWIN_GFX);
    }
}

static void Swap_InitActions(u8 id)
{
    switch (id)
    {
    case SWAP_PLAYER_SCREEN:
        sFactorySwapScreen->inEnemyScreen = FALSE;
        break;
    case SWAP_ENEMY_SCREEN:
        sFactorySwapScreen->inEnemyScreen = TRUE;
        break;
    }
    Swap_InitChoiceState(sFactorySwapScreen->cursorPos);
}

static void Swap_RunActionFunc(u8 taskId)
{
    sSwap_CurrentOptionFunc = Swap_ActionMon;
    sSwap_CurrentOptionFunc(taskId);
}

static void Swap_ActionMon(u8 taskId)
{
    if (!sFactorySwapScreen->inEnemyScreen)
    {
        sFactorySwapScreen->playerMonId = sFactorySwapScreen->cursorPos;
        Swap_InitActions(SWAP_ENEMY_SCREEN);
        Swap_EraseSpeciesAtFadeWindow();
        Swap_PrintChoosePrompt();
        Swap_PrintMonCategory();
        Swap_PrintMonSpecies();
        Swap_UpdateMonIcons();
        Swap_HideActionButtonHighlights();
        Swap_UpdateCursorBox();
        return;
    }
    else if (Swap_AlreadyHasSameSpecies(sFactorySwapScreen->cursorPos) == TRUE)
    {
        OpenMonPic(&sFactorySwapScreen->monPic.bgSpriteId, &sFactorySwapScreen->monPicAnimating, TRUE);
        gTasks[taskId].tState = 0;
        gTasks[taskId].tFollowUpTaskState = STATE_CHOOSE_MONS_HANDLE_INPUT;
        gTasks[taskId].func = Swap_TaskCantHaveSameMons;
        return;
    }
    else
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Swap_AskAcceptMon;
        return;
    }
}

#define sIsSwapScreen data[7]

static void OpenMonPic(u8 *spriteId, bool8 *animating, bool8 swapScreen)
{
    *spriteId = CreateSprite(&sSpriteTemplate_Swap_MonPicBgAnim, 120, 64, 1);
    gSprites[*spriteId].callback = SpriteCB_OpenMonPic;
    gSprites[*spriteId].sIsSwapScreen = swapScreen;
    *animating = TRUE;
}

static void CloseMonPic(struct FactoryMonPic pic, bool8 *animating, bool8 swapScreen)
{
    u8 taskId;

    FreeAndDestroyMonPicSprite(pic.monSpriteId);
    taskId = CreateTask(Task_CloseMonPic, 1);
    gTasks[taskId].tIsSwapScreen = swapScreen;
    gTasks[taskId].tSpriteId = pic.bgSpriteId;
    gTasks[taskId].func(taskId);
    *animating = TRUE;
}

static void HideMonPic(struct FactoryMonPic pic, bool8 *animating)
{
    FreeAndDestroyMonPicSprite(pic.monSpriteId);
    FreeOamMatrix(gSprites[pic.bgSpriteId].oam.matrixNum);
    DestroySprite(&gSprites[pic.bgSpriteId]);
    *animating = FALSE;
}

static void Swap_TaskCantHaveSameMons(u8 taskId)
{
    if (sFactorySwapScreen->monPicAnimating == TRUE)
        return;

    switch (gTasks[taskId].tState)
    {
    case 0:
        Swap_PrintOnInfoWindow(gText_SamePkmnInPartyAlready);
        sFactorySwapScreen->monSwapped = FALSE;
        gTasks[taskId].tState++;
        break;
    case 1:
        if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseMonPic(sFactorySwapScreen->monPic, &sFactorySwapScreen->monPicAnimating, TRUE);
            gTasks[taskId].tState++;
        }
        break;
    case 2:
        if (sFactorySwapScreen->monPicAnimating != TRUE)
        {
            FillWindowPixelBuffer(SWAP_WIN_ACTION_FADE, PIXEL_FILL(0));
            CopyWindowToVram(SWAP_WIN_ACTION_FADE, COPYWIN_GFX);
            gTasks[taskId].tState++;
        }
        break;
    case 3:
        Swap_PrintChoosePrompt();
        gTasks[taskId].tState++;
        break;
    case 4:
        Swap_PrintMonSpeciesForTransition();
        Swap_EraseSpeciesAtFadeWindow();
        sFactorySwapScreen->fadeSpeciesNameActive = TRUE;
        gTasks[taskId].tState = gTasks[taskId].tFollowUpTaskState;
        gTasks[taskId].func = Swap_Task_HandleChooseMons;
        break;
    }
}

static bool8 Swap_AlreadyHasSameSpecies(u8 monId)
{
    u8 i;
    u16 species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES);

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        if (i != sFactorySwapScreen->playerMonId && (u16)(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == species)
            return TRUE;
    }
    return FALSE;
}

static void SpriteCB_OpenMonPic(struct Sprite *sprite)
{
    u8 taskId;

    if (sprite->affineAnimEnded)
    {
        sprite->invisible = TRUE;
        taskId = CreateTask(Task_OpenMonPic, 1);
        gTasks[taskId].tIsSwapScreen = sprite->sIsSwapScreen;
        gTasks[taskId].func(taskId);
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_CloseMonPic(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        FreeOamMatrix(sprite->oam.matrixNum);
        if (sprite->sIsSwapScreen == TRUE)
            sFactorySwapScreen->monPicAnimating = FALSE;
        DestroySprite(sprite);
    }
}

static void Task_OpenMonPic(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->tState)
    {
    case 0:
        // Init
        task->tWinLeft = 88;
        task->tWinRight = DISPLAY_WIDTH - 88;
        task->tWinTop = 64;
        task->tWinBottom = 65;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR | WINOUT_WIN01_OBJ);
        break;
    case 1:
        // Show mon pic bg
        ShowBg(3);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        break;
    case 2:
        // Animate mon pic bg
        task->tWinTop -= 4;
        task->tWinBottom += 4;
        if (task->tWinTop <= 32 || task->tWinBottom >= 96)
        {
            task->tWinTop = 32;
            task->tWinBottom = 96;
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        if (task->tWinTop != 32)
            return;
        break;
    default:
        DestroyTask(taskId);
        // Accessing data of destroyed task. Task data isn't reset until a new task needs that task id.
        if (gTasks[taskId].tIsSwapScreen == TRUE)
            Swap_CreateMonSprite();
        return;
    }
    task->tState++;
}

static void Task_CloseMonPic(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->tState)
    {
    case 0:
        // Init
        task->tWinLeft = 88;
        task->tWinRight = DISPLAY_WIDTH - 88;
        task->tWinTop = 32;
        task->tWinBottom = 96;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR | WINOUT_WIN01_OBJ);
        task->tState++;
        break;
    case 1:
        // Animate bg
        task->tWinTop += 4;
        task->tWinBottom -= 4;
        if (task->tWinTop >= 64 || task->tWinBottom <= 65)
        {
            task->tWinTop = 64;
            task->tWinBottom = 65;
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        if (task->tWinTop == 64)
            task->tState++;
        break;
    default:
        // Hide bg
        HideBg(3);
        gSprites[task->tSpriteId].sIsSwapScreen = task->tIsSwapScreen;
        gSprites[task->tSpriteId].invisible = FALSE;
        gSprites[task->tSpriteId].callback = SpriteCB_CloseMonPic;
        StartSpriteAffineAnim(&gSprites[task->tSpriteId], 1);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        DestroyTask(taskId);
        break;
    }
}

static void Swap_CreateMonSprite(void)
{
    struct Pokemon *mon;
    u16 species;
    u32 personality;
    bool8 isShiny;

    if (!sFactorySwapScreen->inEnemyScreen)
        mon = &gPlayerParty[sFactorySwapScreen->cursorPos];
    else
        mon = &gEnemyParty[sFactorySwapScreen->cursorPos];

    species = GetMonData(mon, MON_DATA_SPECIES);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);
    isShiny = GetMonData(mon, MON_DATA_IS_SHINY);

    sFactorySwapScreen->monPic.monSpriteId = CreateMonPicSprite(species, isShiny, personality, TRUE, 88, 32, 15, TAG_NONE);
    gSprites[sFactorySwapScreen->monPic.monSpriteId].centerToCornerVecX = 0;
    gSprites[sFactorySwapScreen->monPic.monSpriteId].centerToCornerVecY = 0;

    sFactorySwapScreen->monPicAnimating = FALSE;
}
