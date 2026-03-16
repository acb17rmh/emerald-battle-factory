#include "choice_menu.h"

#include "global.h"

static u8 GetMinU8(u8 a, u8 b)
{
    return (a < b) ? a : b;
}

void ChoiceMenu_Init(struct ChoiceMenuState *state, u8 optionCount, u8 viewportSize, u8 maxPicks, bool8 orderMatters)
{
    u8 i;

    if (optionCount > CHOICE_MENU_MAX_OPTIONS)
        optionCount = CHOICE_MENU_MAX_OPTIONS;
    if (viewportSize == 0)
        viewportSize = 1;
    viewportSize = GetMinU8(viewportSize, optionCount);
    if (maxPicks > CHOICE_MENU_MAX_PICKS)
        maxPicks = CHOICE_MENU_MAX_PICKS;

    state->optionCount = optionCount;
    state->viewportSize = viewportSize;
    state->viewportTop = 0;
    state->cursorPos = 0;
    state->maxPicks = maxPicks;
    state->orderMatters = orderMatters;

    state->picksMade = 0;
    for (i = 0; i < CHOICE_MENU_MAX_OPTIONS; i++)
        state->selectionRank[i] = 0;
}

u8 ChoiceMenu_GetCursorIndex(const struct ChoiceMenuState *state)
{
    u8 idx = state->viewportTop + state->cursorPos;
    if (idx >= state->optionCount)
        idx = state->optionCount - 1;
    return idx;
}

void ChoiceMenu_SetCursorIndex(struct ChoiceMenuState *state, u8 optionIndex)
{
    if (state->optionCount == 0)
        return;
    if (optionIndex >= state->optionCount)
        optionIndex = state->optionCount - 1;

    if (optionIndex < state->viewportTop)
        state->viewportTop = optionIndex;
    else if (optionIndex >= state->viewportTop + state->viewportSize)
        state->viewportTop = optionIndex - state->viewportSize + 1;

    state->cursorPos = optionIndex - state->viewportTop;
}

void ChoiceMenu_MoveCursor(struct ChoiceMenuState *state, s8 delta)
{
    s16 idx;
    u8 optionCount;
    u8 cursorIndex;

    optionCount = state->optionCount;
    if (optionCount == 0)
        return;

    cursorIndex = ChoiceMenu_GetCursorIndex(state);
    idx = (s16)cursorIndex + delta;
    while (idx < 0)
        idx += optionCount;
    while (idx >= optionCount)
        idx -= optionCount;

    ChoiceMenu_SetCursorIndex(state, (u8)idx);
}

u8 ChoiceMenu_GetSelectionRank(const struct ChoiceMenuState *state, u8 optionIndex)
{
    if (optionIndex >= state->optionCount)
        return 0;
    return state->selectionRank[optionIndex];
}

enum ChoiceMenuToggleResult ChoiceMenu_ToggleSelection(struct ChoiceMenuState *state, u8 optionIndex)
{
    u8 i;
    u8 rank;

    if (optionIndex >= state->optionCount)
        return CHOICE_TOGGLE_FULL;

    rank = state->selectionRank[optionIndex];
    if (rank != 0)
    {
        // Deselect, and compact selection ranks above it.
        state->selectionRank[optionIndex] = 0;
        if (state->picksMade)
            state->picksMade--;
        for (i = 0; i < state->optionCount; i++)
        {
            if (state->selectionRank[i] > rank)
                state->selectionRank[i]--;
        }
        return CHOICE_TOGGLE_DESELECTED;
    }

    if (state->picksMade >= state->maxPicks)
        return CHOICE_TOGGLE_FULL;

    // Select, assigning next rank.
    state->picksMade++;
    state->selectionRank[optionIndex] = state->picksMade;
    return CHOICE_TOGGLE_SELECTED;
}

bool8 ChoiceMenu_CanPage(const struct ChoiceMenuState *state)
{
    return state->optionCount > state->viewportSize;
}

u8 ChoiceMenu_GetPageCount(const struct ChoiceMenuState *state)
{
    u8 pageSize = state->viewportSize;
    if (pageSize == 0)
        return 1;
    return (state->optionCount + pageSize - 1) / pageSize;
}

u8 ChoiceMenu_GetPageIndex(const struct ChoiceMenuState *state)
{
    u8 pageSize = state->viewportSize;
    if (pageSize == 0)
        return 0;
    return state->viewportTop / pageSize;
}

void ChoiceMenu_SetPageIndex(struct ChoiceMenuState *state, u8 pageIndex)
{
    u8 pageCount = ChoiceMenu_GetPageCount(state);
    u8 pageSize = state->viewportSize;

    if (pageCount == 0)
        pageCount = 1;
    if (pageIndex >= pageCount)
        pageIndex = 0;

    state->viewportTop = pageIndex * pageSize;
    if (state->viewportTop >= state->optionCount)
        state->viewportTop = 0;

    if (state->cursorPos >= state->viewportSize)
        state->cursorPos = 0;
    if (state->viewportTop + state->cursorPos >= state->optionCount)
        state->cursorPos = 0;
}

void ChoiceMenu_CyclePage(struct ChoiceMenuState *state, s8 delta)
{
    s16 next;
    u8 pageCount;
    u8 pageIndex;

    if (!ChoiceMenu_CanPage(state))
        return;

    pageCount = ChoiceMenu_GetPageCount(state);
    pageIndex = ChoiceMenu_GetPageIndex(state);
    next = (s16)pageIndex + delta;
    while (next < 0)
        next += pageCount;
    while (next >= pageCount)
        next -= pageCount;

    ChoiceMenu_SetPageIndex(state, (u8)next);
}
