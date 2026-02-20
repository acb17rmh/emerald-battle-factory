# 1 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
# 5 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnWarp:
# 8 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
# 9 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_UpdateBossUnlockNpcs
# 10 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_UpdateBossUnlockNpcs
# 11 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_UpdateBossUnlockNpcs
# 12 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_UpdateBossUnlockNpcs
# 13 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_UpdateBossUnlockNpcs
# 14 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 255, BattleFrontier_BattleFactoryLobby_EventScript_UpdateBossUnlockNpcs
# 15 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 16 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 17 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
# 18 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 20 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 21 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 22 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_UpdateBossUnlockNpcs::
# 23 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special GetFactorySymbolCount
# 24 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_EnsureBossUnlockStateAndShow
# 25 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_ne VAR_FACTORY_BOSS_UNLOCK_STATE, 0, BattleFrontier_BattleFactoryLobby_EventScript_EnsureBossUnlockStateAndShow
# 26 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_FACTORY_TOTAL_WINS, 0, BattleFrontier_BattleFactoryLobby_EventScript_HideBossUnlockNpcs
# 27 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnsureBossUnlockStateAndShow
# 28 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 29 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnsureBossUnlockStateAndShow::
# 30 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SYS_FRONTIER_PASS
# 31 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_ne VAR_FACTORY_BOSS_UNLOCK_STATE, 0, BattleFrontier_BattleFactoryLobby_EventScript_ShowBossUnlockNpcs
# 32 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FACTORY_BOSS_UNLOCK_STATE, 1
# 33 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FACTORY_BOSS_CLEARED_MASK, 0
# 34 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FACTORY_BOSS_ROTATION_INDEX, 0
# 35 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ShowBossUnlockNpcs
# 36 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 37 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_HideBossUnlockNpcs::
# 38 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_NOLAND
# 39 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_CAMERAMAN
# 40 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	hideobjectat LOCALID_FACTORY_NOLAND, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY
# 41 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	hideobjectat LOCALID_FACTORY_BOSS_SCOUT, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY
# 42 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 43 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 44 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowBossUnlockNpcs::
# 45 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_NOLAND
# 46 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_CAMERAMAN
# 47 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	showobjectat LOCALID_FACTORY_NOLAND, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY
# 48 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	showobjectat LOCALID_FACTORY_BOSS_SCOUT, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY
# 49 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 50 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 51 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnFrame:
# 52 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
# 53 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
# 54 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
# 55 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
# 56 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
# 57 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 58 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 59 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
# 60 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_getstatus
# 61 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 62 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 63 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
# 64 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 65 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 66 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 67 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_setswapped
# 68 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
# 69 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, 0
# 70 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 71 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 72 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 73 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 74 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 75 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 76 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
# 77 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 78 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_isbrain
# 79 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
# 80 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
# 81 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 82 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 83 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 84 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
# 85 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
# 86 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 87 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 88 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 89 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript::
# 90 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 91 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 92 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 93 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 94 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 95 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 96 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 97 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_giverewardmon
# 98 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 99 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript::
# 100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
# 105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
# 108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendant::
# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain::
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle, MSGBOX_DEFAULT
# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge
# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge
# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge::
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge, MSGBOX_DEFAULT
# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge::
# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE, BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc
# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc::
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your POKéMON for\n"
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.$"
# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal POKéMON.$"
# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a DOUBLE BATTLE competition using\l"
# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a DOUBLE BATTLE.\p"
# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle:
# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Random\n"
# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge.\p"
# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is still under\n"
# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development and may contain bugs.$"
# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge:
# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Random\n"
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge?$"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge:
# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This challenge uses rental POKeMON\n"
# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "sets from a Random Battles pool.\p"
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is under\n"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development, so issues may occur.\p"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Unlike Level 50 or Open Level modes,\n"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "each rental set has its own level,\l"
# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "balanced for that set.\p"
# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Rules for battling and swapping are\n"
# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "otherwise the same as the regular\l"
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap challenge.$"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 553 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 554 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 555 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 556 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 557 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 558 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 559 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 560 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 562 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 563 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 564 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your POKéMON\n"
# 565 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 567 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 568 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 569 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 570 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 571 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 572 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 573 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 574 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 575 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 576 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 577 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 578 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 579 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of POKéMON?\p"
# 580 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 581 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 582 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 583 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about POKéMON and their moves,\l"
# 584 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 585 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 586 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 587 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak POKéMON…\n"
# 588 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 589 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 590 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 591 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 593 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 594 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 595 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON during battle to see if\l"
# 596 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 597 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 598 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 599 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 600 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 601 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 602 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 603 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 604 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 605 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 606 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 607 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 608 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 609 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 610 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 611 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental POKéMON.$"
# 612 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 613 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 615 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 616 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 617 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 618 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 619 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 620 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 621 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three POKéMON.\p"
# 622 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 623 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 624 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same POKéMON.$"
# 625 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 626 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 627 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap POKéMON only with\n"
# 628 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the TRAINER you have just defeated.\p"
# 629 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those POKéMON\n"
# 630 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten TRAINER.$"
# 631 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 632 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 633 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 634 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 635 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's POKéMON.\p"
# 636 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap POKéMON\n"
# 637 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh TRAINER in the event.$"
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 639 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 640 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 641 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping POKéMON.\p"
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the POKéMON you are\l"
# 644 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 645 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the POKéMON on your team\n"
# 646 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 647 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 648 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 649 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 650 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 651 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 652 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental POKéMON\n"
# 653 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' POKéMON\l"
# 654 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"

BattleFrontier_BattleFactoryLobby_Noland::
# 658 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 659 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Noland_Text_0
# 660 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices
# 661 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_BossScout::
# 665 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 666 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 667 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special GetFactorySymbolCount
# 668 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_2
BattleFrontier_BattleFactoryLobby_EventScript_BossScout_1:
# 677 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_BOSS_UNLOCK_STATE, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_5
# 682 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special GetNextFactoryBossIdForScout
# 683 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_10
# 688 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 689 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special BufferFactoryBossNameFromVar
# 690 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_3
# 691 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_2:
# 669 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_BOSS_UNLOCK_STATE, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_7
	goto BattleFrontier_BattleFactoryLobby_EventScript_BossScout_1

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_5:
# 678 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_1
# 679 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_7:
# 670 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_12
	goto BattleFrontier_BattleFactoryLobby_EventScript_BossScout_1

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_10:
# 684 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_2
# 685 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_12:
# 671 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_0
# 672 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions::
# 696 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1:
# 699 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4:
# 702 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 706 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 707 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12
# 709 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13
# 711 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14
# 713 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15
# 715 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16
# 718 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10:
# 720 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2:
# 697 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5:
# 700 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8:
# 703 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12:
# 708 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13:
# 710 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14:
# 712 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15:
# 714 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16:
# 716 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic::
# 724 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 725 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 726 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3
# 728 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4
# 731 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1:
# 733 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3:
# 727 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4:
# 729 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground::
# 737 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 738 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 739 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3
# 741 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4
# 743 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5
# 746 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1:
# 748 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3:
# 740 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4:
# 742 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5:
# 744 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks::
# 752 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 753 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 754 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3
# 756 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4
# 758 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5
# 760 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6
# 763 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1:
# 765 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3:
# 755 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4:
# 757 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5:
# 759 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6:
# 761 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins::
# 769 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_FACTORY_TOTAL_WINS
# 770 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0
# 771 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1:
# 775 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4:
# 779 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7:
# 783 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10:
# 787 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13:
# 791 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6
# 792 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2:
# 772 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1
# 773 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5:
# 776 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2
# 777 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8:
# 780 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3
# 781 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11:
# 784 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4
# 785 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14:
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5
# 789 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13


BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices::
# 796 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1:
# 804 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4:
# 812 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9:
# 820 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14:
# 828 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19:
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2:
# 797 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5:
# 805 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7:
# 798 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 799 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 800 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0
# 801 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10:
# 813 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12:
# 806 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 807 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 808 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1
# 809 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15:
# 821 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17:
# 814 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 815 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 816 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2
# 817 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20:
# 829 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22:
# 822 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 823 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 824 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3
# 825 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24:
# 830 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 831 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 832 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4
# 833 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions::
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0
# 844 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1:
# 847 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4:
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 851 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 852 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9
# 854 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10
# 856 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11
# 858 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7:
# 863 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2:
# 845 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5:
# 848 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9:
# 853 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10:
# 855 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11:
# 857 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12:
# 859 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly::
# 867 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 868 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 869 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3
# 871 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4
# 874 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1:
# 876 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3:
# 870 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4:
# 872 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ::
# 880 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 881 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 882 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3
# 884 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4
# 886 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5
# 889 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1:
# 891 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3:
# 883 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4:
# 885 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5:
# 887 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode::
# 895 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1:
# 899 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5
# 903 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4:
# 905 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 907 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 908 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8:
# 915 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2:
# 896 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0
# 897 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5:
# 900 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10:
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11:
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7
# 913 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode::
# 919 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1:
# 923 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5
# 927 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4:
# 929 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3
# 930 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 931 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 932 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10
# 935 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2:
# 920 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0
# 921 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5:
# 924 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10:
# 933 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4
# 934 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11:
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5
# 937 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode::
# 943 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1:
# 947 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5
# 951 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4:
# 953 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3
# 954 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 955 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 956 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10
# 959 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8:
# 963 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2:
# 944 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0
# 945 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5:
# 948 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10:
# 957 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4
# 958 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11:
# 960 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5
# 961 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions::
# 967 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1
# 972 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 975 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5
# 977 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6
# 979 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7
# 981 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8
# 983 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9
# 985 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10
# 987 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11
# 991 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12
# 994 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2:
# 968 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0
# 969 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5:
# 976 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6:
# 978 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7:
# 980 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8:
# 982 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9:
# 984 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10:
# 986 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11:
# 988 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_BGM
# 989 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 990 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12:
# 992 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE::
# 999 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0
# 1000 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1004 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1005 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3
# 1007 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4
# 1009 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5
# 1011 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6
# 1013 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7
# 1015 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8
# 1017 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9
# 1019 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10
# 1021 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11
# 1023 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12
# 1025 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13
# 1027 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14
# 1029 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15
# 1032 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1:
# 1034 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1035 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1036 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3:
# 1006 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4:
# 1008 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5:
# 1010 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6:
# 1012 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 3
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7:
# 1014 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 4
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8:
# 1016 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 5
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9:
# 1018 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 6
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10:
# 1020 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11:
# 1022 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 8
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12:
# 1024 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 9
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13:
# 1026 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 10
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14:
# 1028 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 11
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15:
# 1030 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg::
# 1040 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0
# 1041 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1045 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1046 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3
# 1048 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4
# 1050 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5
# 1052 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6
# 1054 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7
# 1056 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8
# 1058 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9
# 1060 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10
# 1063 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1:
# 1065 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1066 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1067 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3:
# 1047 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4:
# 1049 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 13
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5:
# 1051 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 14
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6:
# 1053 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 15
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7:
# 1055 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 16
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8:
# 1057 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9:
# 1059 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 18
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10:
# 1061 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP::
# 1071 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0
# 1072 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1077 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3
# 1080 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4
# 1082 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5
# 1084 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6
# 1086 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7
# 1088 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8
# 1090 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9
# 1092 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10
# 1094 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11
# 1096 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12
# 1098 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13
# 1100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14
# 1102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15
# 1104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16
# 1107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1:
# 1109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3:
# 1079 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 19
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4:
# 1081 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 20
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5:
# 1083 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 21
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6:
# 1085 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7:
# 1087 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 23
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8:
# 1089 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9:
# 1091 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 25
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10:
# 1093 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 26
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11:
# 1095 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 27
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12:
# 1097 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 28
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13:
# 1099 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 29
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14:
# 1101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 30
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15:
# 1103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 31
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16:
# 1105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum::
# 1115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0
# 1116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3
# 1121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4
# 1123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5
# 1125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6
# 1128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1:
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3:
# 1120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 32
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4:
# 1122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 33
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5:
# 1124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 34
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6:
# 1126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs::
# 1136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0
# 1137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3
# 1146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4
# 1148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5
# 1150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6
# 1152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7
# 1154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8
# 1156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9
# 1158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10
# 1160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11
# 1162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12
# 1164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13
# 1166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14
# 1168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15
# 1170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16
# 1172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17
# 1174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18
# 1176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19
# 1178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20
# 1181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1:
# 1183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3:
# 1145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 35
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4:
# 1147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 36
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5:
# 1149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 37
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6:
# 1151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 38
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7:
# 1153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 39
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8:
# 1155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 40
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9:
# 1157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 41
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10:
# 1159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 42
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11:
# 1161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 43
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12:
# 1163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 44
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13:
# 1165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 45
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14:
# 1167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 46
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15:
# 1169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 47
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16:
# 1171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 48
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17:
# 1173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 49
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18:
# 1175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 50
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19:
# 1177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 51
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20:
# 1179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite::
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0
# 1190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3
# 1199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4
# 1201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5
# 1203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6
# 1205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7
# 1207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8
# 1209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9
# 1211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10
# 1213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11
# 1215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12
# 1217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13
# 1219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14
# 1221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15
# 1223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16
# 1225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17
# 1227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18
# 1229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19
# 1231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20
# 1233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21
# 1235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22
# 1237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23
# 1240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1:
# 1242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3:
# 1198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 52
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4:
# 1200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 53
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5:
# 1202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 54
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6:
# 1204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 55
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7:
# 1206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 56
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8:
# 1208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 57
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9:
# 1210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 58
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10:
# 1212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 59
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11:
# 1214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 60
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12:
# 1216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 61
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13:
# 1218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 62
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14:
# 1220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 63
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15:
# 1222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 64
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16:
# 1224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 65
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17:
# 1226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 66
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18:
# 1228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 67
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19:
# 1230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 68
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20:
# 1232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 69
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21:
# 1234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 70
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22:
# 1236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 71
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23:
# 1238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions::
# 1248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1:
# 1252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1
# 1253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 1259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6
# 1263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7
# 1265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8
# 1268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9
# 1271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10
# 1274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11
# 1277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12
# 1280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13
# 1283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14
# 1286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15
# 1289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16
# 1292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17
# 1295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18
# 1298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19
# 1301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20
# 1304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21
# 1307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22
# 1310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23
# 1313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24
# 1316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25
# 1319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26
# 1322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27
# 1325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28
# 1328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29
# 1331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 24, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30
# 1334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4:
# 1336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2:
# 1249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0
# 1250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6:
# 1261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 0
# 1262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7:
# 1264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8:
# 1266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 1
# 1267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9:
# 1269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 2
# 1270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10:
# 1272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 3
# 1273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11:
# 1275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 4
# 1276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12:
# 1278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 5
# 1279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13:
# 1281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 6
# 1282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14:
# 1284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 7
# 1285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15:
# 1287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 8
# 1288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16:
# 1290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 9
# 1291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17:
# 1293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 10
# 1294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18:
# 1296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 11
# 1297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19:
# 1299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 12
# 1300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20:
# 1302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 13
# 1303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21:
# 1305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 14
# 1306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22:
# 1308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 15
# 1309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23:
# 1311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 16
# 1312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24:
# 1314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 17
# 1315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25:
# 1317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 18
# 1318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26:
# 1320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 19
# 1321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27:
# 1323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 20
# 1324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28:
# 1326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 21
# 1327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29:
# 1329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 22
# 1330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30:
# 1332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess::
# 1341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0
# 1343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess::
# 1348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0
# 1350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse::
# 1355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0
# 1356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 1360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0
# 1362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_selectrewardmon
	end


BattleFrontier_BattleFactoryLobby_Noland_Text_0:
# 659 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, {PLAYER}. Can't handle the heat?\n"
	.string "Or just fancy a new challenge? Let me\l"
	.string "know and I'll adjust some things for ya.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_0:
# 671 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "No big rumors yet, {PLAYER}. Win your\n"
	.string "first symbol, and I'll keep my ears open.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_1:
# 678 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I've heard whispers, but nothing\n"
	.string "confirmed yet. Keep pushing your\l"
	.string "streak!$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_2:
# 684 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Breaking scoop! Looks like you've\n"
	.string "already cleared the current lineup of\l"
	.string "special challengers.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_3:
# 690 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Breaking scoop! The next powerful\n"
	.string "TRAINER expected at the FACTORY is\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GIMMICK OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MUSIC OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACKGROUND OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TOTAL WINS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CANCEL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0:
# 770 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You've won {STR_VAR_1} Battle\n"
	.string "Factory battle(s) in total.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1:
# 772 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 10 wins: MUSIC OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2:
# 776 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 20 wins: BACKGROUND\n"
	.string "OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3:
# 780 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 30 wins: MEGA EVOLUTION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4:
# 784 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 40 wins: Z-MOVES.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5:
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 50 wins:\n"
	.string "TERASTALLISATION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6:
# 791 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All current Noland options are\n"
	.string "unlocked.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0:
# 800 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, nice going! You've unlocked MUSIC\n"
	.string "OPTIONS!\p"
	.string "From now on, I can tune your battles\n"
	.string "however you like--pick your tracks or\l"
	.string "let me shuffle them.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1:
# 808 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whoa! You're on a roll--BACKGROUND\n"
	.string "OPTIONS unlocked!\p"
	.string "Now you can pick your battle scenery,\n"
	.string "or leave it to chance with a shuffle.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2:
# 816 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Now that's battle sense! MEGA\n"
	.string "EVOLUTION is unlocked!\p"
	.string "Want mega power in your runs? Just tell\n"
	.string "me and I'll switch it on--or off.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3:
# 824 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You're really heating up! Z-MOVES are\n"
	.string "unlocked!\p"
	.string "If you want high-impact finishes, I can\n"
	.string "enable them for your Factory runs\l"
	.string "anytime.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4:
# 832 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Outstanding battling! You've unlocked\n"
	.string "TERASTALLISATION!\p"
	.string "You've got the full set now--I can\n"
	.string "toggle it on or off for your next\l"
	.string "challenge.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0:
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Interested in spicing up your battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1:
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2:
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3:
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0:
# 896 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION unlocks at 50 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1:
# 900 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2:
# 903 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3:
# 905 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change\n"
	.string "TERASTALLISATION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ENABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DISABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6:
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled TERASTALLISATION!\n"
	.string "POKéMON with the TERA BLAST move will\l"
	.string "also be added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7:
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled TERASTALLISATION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0:
# 920 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION unlocks at 30 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1:
# 924 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2:
# 927 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3:
# 929 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change MEGA\n"
	.string "EVOLUTION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4:
# 933 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled MEGA EVOLUTION! POKéMON\n"
	.string "with the ability to MEGA EVOLVE will be\l"
	.string "added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5:
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled MEGA EVOLUTION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0:
# 944 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES unlock at 40 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1:
# 948 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2:
# 951 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3:
# 953 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change Z-MOVE mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4:
# 957 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled Z-MOVES! POKéMON with the\n"
	.string "ability to use Z-MOVES will be added to\l"
	.string "the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5:
# 960 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled Z-MOVES!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0:
# 968 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Music options unlock at 10 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I can change the music that plays\n"
	.string "during your battles!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "R/S/E MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FR/LG MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "D/P MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLATINUM MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "HG/SS MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BLACK/WHITE MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SHUFFLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0:
# 999 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Ruby, Sapphire\n"
	.string "and Emerald:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1:
# 1001 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2:
# 1001 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. FRONTIER BRAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3:
# 1001 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEW$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4:
# 1001 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5:
# 1001 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM AQUA & MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6:
# 1002 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7:
# 1002 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8:
# 1002 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. REGI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9:
# 1002 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE & GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10:
# 1002 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RIVAL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11:
# 1003 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ELITE FOUR$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12:
# 1003 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. AQUA & MAGMA LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13:
# 1003 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACK$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0:
# 1040 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from FireRed and\n"
	.string "LeafGreen:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1:
# 1043 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. DEOXYS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2:
# 1044 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEWTWO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3:
# 1044 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LEGEND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0:
# 1071 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Diamond and\n"
	.string "Pearl:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1:
# 1073 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. UXIE/ASELF/MESPRIT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2:
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC BOSS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3:
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS DIALGA/PALKIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4:
# 1075 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5:
# 1075 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ARCEUS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6:
# 1076 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GALACTIC COMMANDER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0:
# 1115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Platinum:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1:
# 1117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GIRATINA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0:
# 1136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from HeartGold and\n"
	.string "SoulSilver:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1:
# 1139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM ROCKET$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2:
# 1139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUICUNE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3:
# 1140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ENTEI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4:
# 1140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RAIKOU$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5:
# 1140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6:
# 1141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7:
# 1141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8:
# 1141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. HO-OH$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9:
# 1141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LUGIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10:
# 1142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE/GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0:
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Black and\n"
	.string "White:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM PLASMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WINNING THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (1)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. IN A PINCH THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RESHIRAM/ZEKROM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (2)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GHETSIS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUBWAY TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CYNTHIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. STRONG WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYUREM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WCS CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0:
# 1249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Background options unlock at 20 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1:
# 1252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Fancy a new lick of paint on your\n"
	.string "battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2:
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DEFAULT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3:
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4:
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "LONG GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5:
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SAND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6:
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "UNDERWATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7:
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "WATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8:
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9:
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MOUNTAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10:
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAVE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11:
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BUILDING$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12:
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13:
# 1256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14:
# 1256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15:
# 1256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16:
# 1256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM AQUA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17:
# 1257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR SIDNEY$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18:
# 1257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR PHOEBE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19:
# 1257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR GLACIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20:
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR DRAKE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21:
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22:
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23:
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "KYOGRE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24:
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "RAYQUAZA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0:
# 1342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your music selection has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0:
# 1349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your background has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0:
# 1355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Is there anything else I can help you\n"
	.string "with?$"

BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0:
# 1360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a reward for your display of skill,\n"
	.string "you will be able to select one of the\l"
	.string "POKéMON in your party to keep forever,\l"
	.string "for use in other BATTLE FRONTIER\l"
	.string "facilities.$"
