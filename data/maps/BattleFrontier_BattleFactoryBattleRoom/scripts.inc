# 1 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_FACTORY_BATTLE_PLAYER).
# 4 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_F.
# 5 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by factory_setopponentgfx.
# 6 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_MapScripts::
# 8 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleFactoryBattleRoom_OnTransition
# 9 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnWarp
# 10 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnFrame
# 11 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.byte 0
# 12 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_OnTransition:
# 14 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_settrainers
# 15 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	checkplayergender
# 16 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale
# 17 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale
# 18 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_DEBUG_FORCE_NOLAND, BattleFrontier_BattleFactoryBattleRoom_EventScript_DebugForceNolandStatus
# 19 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 20 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 21 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj
# 22 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 23 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DebugForceNolandStatus::
# 25 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_TEMP_F, FRONTIER_BRAIN_STREAK
# 26 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj
# 27 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj::
# 29 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 30 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_FACTORY_BATTLE_OPPONENT, 7, 9
# 31 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 32 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 33 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_OnWarp:
# 34 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects
# 35 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.2byte 0
# 36 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 37 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects::
# 38 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 39 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM
# 40 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects
# 41 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	hideobjectat LOCALID_FACTORY_BATTLE_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM
# 42 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects::
# 43 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale::
# 46 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 47 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 48 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 49 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale::
# 50 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 51 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 52 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 53 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_OnFrame:
# 54 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom
# 55 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.2byte 0
# 56 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 57 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle::
# 58 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special PlayFactoryBossPreBattleRoomBgmIfSet
# 59 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special BufferFactoryBossBattleRoomPromptText
# 60 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 61 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 62 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_OPPONENT, BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle
# 63 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 64 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 65 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 66 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
# 67 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent
# 68 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 69 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 70 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom::
# 71 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle
# 72 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 73 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 74 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
# 76 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_setopponentgfx
# 77 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	removeobject LOCALID_FACTORY_BATTLE_OPPONENT
# 78 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_FACTORY_BATTLE_OPPONENT, 7, 1
# 79 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addobject LOCALID_FACTORY_BATTLE_OPPONENT
# 80 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_OPPONENT, BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter
# 81 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent::
# 83 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland
# 84 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	palace_getopponentintro
# 85 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	lockall
# 86 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 87 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 88 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 89 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 90 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special HealPlayerParty
# 91 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
# 92 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 93 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 94 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 95 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	switch VAR_RESULT
# 96 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent
# 97 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost::
# 98 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 99 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby
# 100 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 101 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent::
# 102 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_FACTORY_TOTAL_WINS, 1
# 103 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_get FACTORY_DATA_WIN_STREAK_SWAPS
# 104 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
# 105 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 106 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 107 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS  @ uses VAR_0x8006 above
# 108 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak::
# 109 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 110 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum::
# 111 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 112 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 113 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 114 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	switch VAR_RESULT
# 115 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
# 116 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 117 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 8
# 118 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 119 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon::
# 120 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 121 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby
# 122 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 123 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland::
# 124 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_DEBUG_FORCE_NOLAND
# 125 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FACTORY_ACTIVE_BOSS
# 126 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleCustomBoss
# 127 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 128 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold
# 129 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
# 130 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
# 131 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 132 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
# 133 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead, MSGBOX_DEFAULT
# 134 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 135 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver::
# 136 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn, MSGBOX_DEFAULT
# 137 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
# 138 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver
# 139 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 140 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 141 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_UnlockFactoryBossesIfNeeded::
# 142 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_FACTORY_BOSS_UNLOCK_STATE, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_UnlockFactoryBossesIfNeeded_Done
# 143 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_FACTORY_BOSS_UNLOCK_STATE, 1
# 144 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_FACTORY_BOSS_CLEARED_MASK, 0
# 145 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_FACTORY_BOSS_ROTATION_INDEX, 0
# 146 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_SCOUT_INTRO_SEEN
# 147 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_NOLAND
# 148 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_CAMERAMAN
# 149 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_REPORTER
# 150 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_UnlockFactoryBossesIfNeeded_Done::
# 151 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 152 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 153 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver::
# 154 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_UnlockFactoryBossesIfNeeded
# 155 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_getsymbols
# 156 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 157 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass, MSGBOX_DEFAULT
# 158 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 159 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
# 160 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 161 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 162 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol
# 163 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 164 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitfanfare
# 165 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_givesymbol
# 166 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred, MSGBOX_DEFAULT
# 167 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 168 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 169 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold::
# 170 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 171 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
# 172 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime, MSGBOX_DEFAULT
# 173 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 174 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold::
# 175 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn, MSGBOX_DEFAULT
# 176 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
# 177 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold
# 178 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 179 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 180 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold::
# 181 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_UnlockFactoryBossesIfNeeded
# 182 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_getsymbols
# 183 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 184 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass, MSGBOX_DEFAULT
# 185 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 186 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
# 187 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 188 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 189 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine
# 190 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 191 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitfanfare
# 192 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_givesymbol
# 193 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou, MSGBOX_DEFAULT
# 194 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 195 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 196 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle::
# 197 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 198 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 199 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special HealPlayerParty
# 200 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
# 201 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 202 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 203 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 204 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 205 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 206 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleCustomBoss::
# 207 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special BufferFactoryBossBattleIntroText
# 208 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 209 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
# 210 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedCustomBoss
# 211 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_FACTORY_ACTIVE_BOSS, 0
# 212 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_DEBUG_STEVEN_BOSS
# 213 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 214 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 215 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedCustomBoss::
# 216 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special RecordFactoryBossDefeat
# 217 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special SetPendingFactoryRewardBossFromActive
# 218 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	copyvar VAR_FACTORY_LAST_DEFEATED_BOSS, VAR_FACTORY_ACTIVE_BOSS
# 219 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special BufferFactoryBossBattlePostWinText
# 220 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 221 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_FACTORY_ACTIVE_BOSS, 0
# 222 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_DEBUG_STEVEN_BOSS
# 223 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 224 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland::
# 226 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_FACTORY_TOTAL_WINS, 1
# 227 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_get FACTORY_DATA_WIN_STREAK_SWAPS
# 228 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
# 229 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 230 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 231 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS  @ uses VAR_0x8006 above
# 232 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_get FACTORY_DATA_WIN_STREAK
# 233 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum
# 234 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 235 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, VAR_RESULT
# 236 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 237 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 238 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
# 239 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 240 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 241 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom:
# 242 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 244 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 245 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 246 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 247 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	face_right
# 248 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 249 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland:
# 251 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_right
# 252 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 253 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 254 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter:
# 255 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 256 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 257 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 258 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 259 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 260 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	face_left
# 261 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 262 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 263 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle:
# 264 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 265 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 266 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 267 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	face_left
# 268 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 269 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 270 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby::
# 271 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyRandom
# 272 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 273 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles
# 274 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 4, 8
# 275 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 276 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 277 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 278 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles::
# 279 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 14, 8
# 280 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 281 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 282 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 283 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyRandom::
# 284 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 22, 8
# 285 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 286 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 287 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 288 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle::
# 289 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_SCIENTIST_1, Common_Movement_WalkInPlaceFasterRight
# 290 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_SCIENTIST_2, Common_Movement_WalkInPlaceFasterRight
# 291 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_SCIENTIST_3, Common_Movement_WalkInPlaceFasterRight
# 292 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_SCIENTIST_4, Common_Movement_WalkInPlaceFasterLeft
# 293 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_SCIENTIST_5, Common_Movement_WalkInPlaceFasterLeft
# 294 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_BATTLE_SCIENTIST_6, Common_Movement_WalkInPlaceFasterLeft
# 295 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 296 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 297 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 298 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_GetAMoveOn:
# 299 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Hey, hey!\n"
# 300 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Get a move on!$"
# 301 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 302 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead:
# 303 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Hey, my name's NOLAND!\n"
# 304 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'm basically in charge of this place,\l"
# 305 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "which is why I'm the FACTORY HEAD!\p"
# 306 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I had a look at your Battle Swap data.\p"
# 307 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You seem to have the right idea,\n"
# 308 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "but you're still square in your head!\p"
# 309 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Listen up, okay? Knowledge isn't only\n"
# 310 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "about reading books or doing desk work.\p"
# 311 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Just doing that sort of thing…\n"
# 312 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "It may as well be useless!\p"
# 313 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You have to experience things with\n"
# 314 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "your heart and your body, understand?\p"
# 315 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'll take you on under the same\n"
# 316 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "conditions as you.\p"
# 317 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'll be using rental POKéMON, too!$"
# 318 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 319 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn:
# 320 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Shake out every last bit of your\n"
# 321 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "knowledge and bring it on!$"
# 322 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 323 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass:
# 324 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "NOLAND: Smart going!\n"
# 325 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS.$"
# 326 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 327 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol:
# 328 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "The Knowledge Symbol was embossed\n"
# 329 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "on the FRONTIER PASS!$"
# 330 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 331 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred:
# 332 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Heh…\n"
# 333 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You're a pretty bright spark…\p"
# 334 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Next time, I'll come after you hard.\n"
# 335 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "No holds barred, understand?\p"
# 336 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You keep up your studies!$"
# 337 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 338 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime:
# 339 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "NOLAND: Hey, hey! How's it going?\n"
# 340 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You keeping up with your studies?\p"
# 341 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "…Oh?\p"
# 342 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You've taken on a harder look than\n"
# 343 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "the last time I saw you.\p"
# 344 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Now, this should be fun!\n"
# 345 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'm getting excited, hey!$"
# 346 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 347 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn:
# 348 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "All right!\n"
# 349 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Bring it on!$"
# 350 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 351 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass:
# 352 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "NOLAND: What the…\n"
# 353 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You're getting out of my league!\p"
# 354 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Sheesh!\n"
# 355 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Let's see that FRONTIER PASS!$"
# 356 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 357 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine:
# 358 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "The Knowledge Symbol took on\n"
# 359 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 360 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 361 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou:
# 362 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Pfft, man!\p"
# 363 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "That's absolutely the last time\n"
# 364 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I lose to you!\p"
# 365 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "We have to do this again, hey?$"
