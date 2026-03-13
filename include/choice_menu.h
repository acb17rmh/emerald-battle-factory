#ifndef GUARD_CHOICE_MENU_H
#define GUARD_CHOICE_MENU_H

#include "global.h"

// Generic choice/selection state for UI screens that show N options and allow selecting up to K.
// This module is intentionally UI-agnostic: it only manages cursor/viewport and selection order.

#define CHOICE_MENU_MAX_OPTIONS 32
#define CHOICE_MENU_MAX_PICKS   8

enum ChoiceMenuToggleResult
{
    CHOICE_TOGGLE_SELECTED,
    CHOICE_TOGGLE_DESELECTED,
    CHOICE_TOGGLE_FULL,
};

struct ChoiceMenuState
{
    u8 optionCount;
    u8 viewportSize; // number of visible slots
    u8 viewportTop;  // first visible option index
    u8 cursorPos;    // cursor position within viewport [0..viewportSize-1]

    u8 maxPicks;
    bool8 orderMatters;

    // 0 = not selected, otherwise [1..maxPicks] indicates selection rank/order.
    u8 selectionRank[CHOICE_MENU_MAX_OPTIONS];
    u8 picksMade; // number of selected options
};

void ChoiceMenu_Init(struct ChoiceMenuState *state, u8 optionCount, u8 viewportSize, u8 maxPicks, bool8 orderMatters);
u8 ChoiceMenu_GetCursorIndex(const struct ChoiceMenuState *state);
void ChoiceMenu_SetCursorIndex(struct ChoiceMenuState *state, u8 optionIndex);
void ChoiceMenu_MoveCursor(struct ChoiceMenuState *state, s8 delta);
u8 ChoiceMenu_GetSelectionRank(const struct ChoiceMenuState *state, u8 optionIndex);
enum ChoiceMenuToggleResult ChoiceMenu_ToggleSelection(struct ChoiceMenuState *state, u8 optionIndex);

bool8 ChoiceMenu_CanPage(const struct ChoiceMenuState *state);
u8 ChoiceMenu_GetPageCount(const struct ChoiceMenuState *state);
u8 ChoiceMenu_GetPageIndex(const struct ChoiceMenuState *state);
void ChoiceMenu_SetPageIndex(struct ChoiceMenuState *state, u8 pageIndex);
void ChoiceMenu_CyclePage(struct ChoiceMenuState *state, s8 delta);

#endif // GUARD_CHOICE_MENU_H
