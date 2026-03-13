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
	map_script_2 VAR_FACTORY_BOSS_UNLOCK_STATE, 1, BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter
# 10 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_FACTORY_BOSS_UNLOCK_STATE, 2, BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter
# 11 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 12 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
# 14 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 16 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 17 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 18 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnFrame:
# 19 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
# 20 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
# 21 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
# 22 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
# 23 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
# 24 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_FACTORY_BOSS_UNLOCK_STATE, 1, BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview
# 25 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_FACTORY_BOSS_UNLOCK_STATE, 2, BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview
# 26 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 27 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
# 29 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_getstatus
# 30 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 31 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 32 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
# 33 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 34 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 35 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 36 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_setswapped
# 37 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
# 38 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, 0
# 39 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 40 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 41 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 42 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 43 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
# 46 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 47 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_isbrain
# 48 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
# 49 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
# 50 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 51 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 52 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 53 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
# 54 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 56 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 57 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 58 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript::
# 59 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 60 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 61 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 62 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 63 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 64 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 65 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 66 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_giverewardmon
# 67 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 68 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript::
# 69 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 70 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 71 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 72 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 73 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
# 74 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 75 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 76 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
# 77 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 78 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 79 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 80 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 81 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 82 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 83 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 84 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 85 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 86 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 87 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 88 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
# 89 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 90 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 91 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 92 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 93 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 94 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 95 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 96 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 97 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 98 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 99 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
# 100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
# 102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
# 109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendant::
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain::
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle, MSGBOX_DEFAULT
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge
# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge::
# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge, MSGBOX_DEFAULT
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge::
# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE, BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc
# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc::
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your POKéMON for\n"
# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.$"
# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal POKéMON.$"
# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a DOUBLE BATTLE competition using\l"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a DOUBLE BATTLE.\p"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle:
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Random\n"
# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge.\p"
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is still under\n"
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development and may contain bugs.$"
# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge:
# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Random\n"
# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge?$"
# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge:
# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This challenge uses rental POKeMON\n"
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "sets from a Random Battles pool.\p"
# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is under\n"
# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development, so issues may occur.\p"
# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Unlike Level 50 or Open Level modes,\n"
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "each rental set has its own level,\l"
# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "balanced for that set.\p"
# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Rules for battling and swapping are\n"
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "otherwise the same as the regular\l"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap challenge.$"
# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your POKéMON\n"
# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of POKéMON?\p"
# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about POKéMON and their moves,\l"
# 553 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 554 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 555 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 556 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak POKéMON…\n"
# 557 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 558 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 559 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 560 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 562 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 563 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 564 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON during battle to see if\l"
# 565 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 567 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 568 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 569 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 570 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 571 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 572 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 573 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 574 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 575 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 576 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 577 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 578 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 579 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 580 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental POKéMON.$"
# 581 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 582 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 583 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 584 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 585 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 586 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 587 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 588 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 589 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 590 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three POKéMON.\p"
# 591 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 593 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same POKéMON.$"
# 594 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 595 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 596 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap POKéMON only with\n"
# 597 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the TRAINER you have just defeated.\p"
# 598 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those POKéMON\n"
# 599 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten TRAINER.$"
# 600 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 601 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 602 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 603 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 604 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's POKéMON.\p"
# 605 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap POKéMON\n"
# 606 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh TRAINER in the event.$"
# 607 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 608 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 609 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 610 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping POKéMON.\p"
# 611 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 612 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the POKéMON you are\l"
# 613 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the POKéMON on your team\n"
# 615 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 616 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 617 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 618 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 619 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 620 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 621 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental POKéMON\n"
# 622 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' POKéMON\l"
# 623 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"

BattleFrontier_BattleFactoryLobby_Noland::
# 627 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 628 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Noland_Text_0
# 629 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices
# 630 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions::
# 634 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1:
# 637 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4:
# 640 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7:
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 644 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 645 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12
# 647 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13
# 649 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14
# 651 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15
# 653 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16
# 656 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10:
# 658 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2:
# 635 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8:
# 641 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12:
# 646 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13:
# 648 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14:
# 650 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15:
# 652 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16:
# 654 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic::
# 662 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 663 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 664 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3
# 666 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4
# 669 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1:
# 671 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3:
# 665 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4:
# 667 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground::
# 675 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 676 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 677 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3
# 679 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4
# 681 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5
# 684 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1:
# 686 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3:
# 678 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4:
# 680 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5:
# 682 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks::
# 690 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 691 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 692 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3
# 694 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4
# 696 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5
# 698 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6
# 701 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1:
# 703 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4:
# 695 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5:
# 697 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6:
# 699 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins::
# 707 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_FACTORY_TOTAL_WINS
# 708 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0
# 709 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1:
# 713 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4:
# 717 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10:
# 725 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13:
# 729 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6
# 730 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2:
# 710 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1
# 711 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5:
# 714 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2
# 715 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8:
# 718 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3
# 719 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11:
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4
# 723 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14:
# 726 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5
# 727 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13


BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices::
# 734 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1:
# 742 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4:
# 750 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9:
# 758 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14:
# 766 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19:
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2:
# 735 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5:
# 743 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7:
# 736 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 737 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 738 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0
# 739 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10:
# 751 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12:
# 744 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 745 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 746 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1
# 747 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15:
# 759 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17:
# 752 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 753 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 754 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2
# 755 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20:
# 767 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22:
# 760 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 761 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 762 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3
# 763 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24:
# 768 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 769 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 770 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4
# 771 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions::
# 781 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0
# 782 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1:
# 785 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4:
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 789 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 790 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9
# 792 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10
# 794 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11
# 796 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12
# 799 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7:
# 801 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2:
# 783 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5:
# 786 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9:
# 791 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10:
# 793 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11:
# 795 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12:
# 797 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly::
# 805 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 806 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 807 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3
# 809 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4
# 812 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1:
# 814 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3:
# 808 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4:
# 810 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ::
# 818 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 819 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 820 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3
# 822 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4
# 824 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5
# 827 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1:
# 829 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3:
# 821 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4:
# 823 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5:
# 825 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode::
# 833 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1:
# 837 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5
# 841 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4:
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3
# 844 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 845 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 846 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10
# 849 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8:
# 853 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2:
# 834 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0
# 835 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5:
# 838 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10:
# 847 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6
# 848 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11:
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7
# 851 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode::
# 857 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1:
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5
# 865 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4:
# 867 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3
# 868 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 869 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 870 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10
# 873 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8:
# 877 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2:
# 858 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0
# 859 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5:
# 862 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10:
# 871 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4
# 872 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11:
# 874 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5
# 875 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode::
# 881 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1:
# 885 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5
# 889 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4:
# 891 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3
# 892 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 893 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 894 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10
# 897 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8:
# 901 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2:
# 882 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0
# 883 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5:
# 886 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10:
# 895 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4
# 896 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11:
# 898 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5
# 899 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions::
# 905 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1:
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 913 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5
# 915 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6
# 917 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7
# 919 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8
# 921 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9
# 923 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10
# 925 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11
# 929 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12
# 932 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0
# 907 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5:
# 914 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6:
# 916 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7:
# 918 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8:
# 920 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9:
# 922 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10:
# 924 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11:
# 926 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_BGM
# 927 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 928 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12:
# 930 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE::
# 937 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 942 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 943 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3
# 945 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4
# 947 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5
# 949 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6
# 951 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7
# 953 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8
# 955 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9
# 957 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10
# 959 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11
# 961 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12
# 963 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13
# 965 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14
# 967 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15
# 970 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1:
# 972 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3:
# 944 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4:
# 946 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5:
# 948 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6:
# 950 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 3
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7:
# 952 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 4
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8:
# 954 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 5
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9:
# 956 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 6
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10:
# 958 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11:
# 960 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 8
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12:
# 962 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 9
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13:
# 964 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 10
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14:
# 966 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 11
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15:
# 968 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg::
# 978 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0
# 979 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 983 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 984 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3
# 986 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4
# 988 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5
# 990 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6
# 992 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7
# 994 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8
# 996 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9
# 998 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10
# 1001 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1:
# 1003 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1004 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1005 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3:
# 985 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4:
# 987 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 13
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5:
# 989 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 14
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6:
# 991 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 15
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7:
# 993 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 16
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8:
# 995 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9:
# 997 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 18
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10:
# 999 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP::
# 1009 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0
# 1010 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1015 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1016 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3
# 1018 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4
# 1020 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5
# 1022 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6
# 1024 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7
# 1026 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8
# 1028 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9
# 1030 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10
# 1032 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11
# 1034 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12
# 1036 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13
# 1038 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14
# 1040 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15
# 1042 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16
# 1045 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1:
# 1047 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1048 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1049 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3:
# 1017 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 19
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4:
# 1019 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 20
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5:
# 1021 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 21
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6:
# 1023 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7:
# 1025 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 23
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8:
# 1027 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9:
# 1029 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 25
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10:
# 1031 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 26
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11:
# 1033 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 27
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12:
# 1035 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 28
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13:
# 1037 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 29
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14:
# 1039 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 30
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15:
# 1041 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 31
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16:
# 1043 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum::
# 1053 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0
# 1054 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1056 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1057 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3
# 1059 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4
# 1061 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5
# 1063 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6
# 1066 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1:
# 1068 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1069 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1070 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3:
# 1058 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 32
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4:
# 1060 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 33
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5:
# 1062 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 34
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6:
# 1064 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs::
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0
# 1075 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1081 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1082 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3
# 1084 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4
# 1086 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5
# 1088 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6
# 1090 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7
# 1092 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8
# 1094 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9
# 1096 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10
# 1098 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11
# 1100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12
# 1102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13
# 1104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14
# 1106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15
# 1108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16
# 1110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17
# 1112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18
# 1114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19
# 1116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20
# 1119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1:
# 1121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3:
# 1083 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 35
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4:
# 1085 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 36
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5:
# 1087 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 37
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6:
# 1089 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 38
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7:
# 1091 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 39
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8:
# 1093 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 40
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9:
# 1095 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 41
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10:
# 1097 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 42
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11:
# 1099 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 43
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12:
# 1101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 44
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13:
# 1103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 45
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14:
# 1105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 46
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15:
# 1107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 47
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16:
# 1109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 48
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17:
# 1111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 49
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18:
# 1113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 50
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19:
# 1115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 51
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20:
# 1117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite::
# 1127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0
# 1128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3
# 1137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4
# 1139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5
# 1141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6
# 1143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7
# 1145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8
# 1147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9
# 1149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10
# 1151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11
# 1153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12
# 1155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13
# 1157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14
# 1159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15
# 1161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16
# 1163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17
# 1165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18
# 1167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19
# 1169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20
# 1171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21
# 1173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22
# 1175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23
# 1178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1:
# 1180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3:
# 1136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 52
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4:
# 1138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 53
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5:
# 1140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 54
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6:
# 1142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 55
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7:
# 1144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 56
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8:
# 1146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 57
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9:
# 1148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 58
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10:
# 1150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 59
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11:
# 1152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 60
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12:
# 1154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 61
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13:
# 1156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 62
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14:
# 1158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 63
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15:
# 1160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 64
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16:
# 1162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 65
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17:
# 1164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 66
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18:
# 1166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 67
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19:
# 1168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 68
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20:
# 1170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 69
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21:
# 1172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 70
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22:
# 1174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 71
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23:
# 1176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions::
# 1186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1:
# 1190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 1197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6
# 1201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7
# 1203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8
# 1206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9
# 1209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10
# 1212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11
# 1215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12
# 1218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13
# 1221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14
# 1224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15
# 1227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16
# 1230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17
# 1233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18
# 1236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19
# 1239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20
# 1242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21
# 1245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22
# 1248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23
# 1251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25
# 1257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26
# 1260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27
# 1263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28
# 1266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29
# 1269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 24, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30
# 1272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4:
# 1274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0
# 1188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6:
# 1199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 0
# 1200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7:
# 1202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8:
# 1204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 1
# 1205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9:
# 1207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 2
# 1208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10:
# 1210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 3
# 1211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11:
# 1213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 4
# 1214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12:
# 1216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 5
# 1217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13:
# 1219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 6
# 1220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14:
# 1222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 7
# 1223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15:
# 1225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 8
# 1226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16:
# 1228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 9
# 1229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17:
# 1231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 10
# 1232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18:
# 1234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 11
# 1235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19:
# 1237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 12
# 1238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20:
# 1240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 13
# 1241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21:
# 1243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 14
# 1244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22:
# 1246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 15
# 1247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23:
# 1249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 16
# 1250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24:
# 1252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 17
# 1253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25:
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 18
# 1256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26:
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 19
# 1259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27:
# 1261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 20
# 1262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28:
# 1264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 21
# 1265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29:
# 1267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 22
# 1268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30:
# 1270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess::
# 1279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0
# 1281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess::
# 1286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0
# 1288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse::
# 1293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0
# 1294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 1298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_selectrewardmon
	return


BattleFrontier_BattleFactoryLobby_EventScript_BossScout::
# 1302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 1303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 1304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_BOSS_UNLOCK_STATE, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_2
# 1309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special GetNextFactoryBossIdForScout
# 1310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_5
# 1315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setorcopyvar VAR_0x8004, VAR_RESULT
# 1316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special BufferFactoryBossScoutHintTextFromVar
# 1317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox gStringVar4
# 1318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_2:
# 1305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_0
# 1306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_5:
# 1311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_1
# 1312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end


BattleFrontier_BattleFactoryLobby_EventScript_BossReporter::
# 1323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossReporter_Text_0
	end


BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter::
# 1328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_SCOUT_INTRO_SEEN, BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_2
BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_1:
# 1331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_HIDE_BATTLE_FACTORY_LOBBY_CAMERAMAN, BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_5
BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_4:
# 1334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_REPORTER
# 1335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	addobject LOCALID_FACTORY_BOSS_REPORTER
	end

BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_2:
# 1329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_Hide
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_1

BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_5:
# 1332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_Hide
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_4


BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_Hide::
# 1340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_REPORTER
	end


BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview::
# 1345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_SCOUT_INTRO_SEEN, BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_2
BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_1:
# 1348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_HIDE_BATTLE_FACTORY_LOBBY_CAMERAMAN, BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_5
BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_4:
# 1351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 1352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_FACTORY_BOSS_SCOUT, DIR_SOUTH
# 1353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, Common_Movement_ExclamationMark
# 1354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
# 1356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, BattleFrontier_BattleFactoryLobby_Movement_ReporterApproachPlayer
# 1357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 1359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewIntro
# 1360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, BattleFrontier_BattleFactoryLobby_Movement_ReporterLeadToCamera
# 1361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerFollowReporterToCamera
# 1362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_FACTORY_BOSS_REPORTER, DIR_SOUTH
# 1364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 1365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionOne
# 1366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionTwo
# 1367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionThree
# 1368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewRumor
# 1369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewCameramanCut
# 1370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	fadedefaultbgm
# 1371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewWrapUp
# 1372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 1373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, BattleFrontier_BattleFactoryLobby_Movement_ReporterExitAfterInterview
# 1374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_FACTORY_BOSS_SCOUT, DIR_SOUTH
# 1376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CameramanHint
# 1377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 1378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_REPORTER
# 1379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_SCOUT_INTRO_SEEN
# 1380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_2:
# 1346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_Done
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_1

BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_5:
# 1349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_Done
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_4


BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_Done::
	end


# 1419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_ReporterApproachPlayer:
# 1420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_left
# 1420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_left
	step_end

# 1423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_ReporterLeadToCamera:
# 1424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
	step_end

# 1429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerFollowReporterToCamera:
# 1430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	face_up
	step_end

# 1435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_ReporterExitAfterInterview:
# 1436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	face_down
# 1439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay_8
# 1440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Noland_Text_0:
# 628 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, {PLAYER}. Can't handle the heat?\n"
	.string "Or just fancy a new challenge? Let me\l"
	.string "know and I'll adjust some things for ya.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0:
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GIMMICK OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1:
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MUSIC OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2:
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACKGROUND OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3:
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TOTAL WINS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4:
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CANCEL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0:
# 708 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You've won {STR_VAR_1} Battle\n"
	.string "Factory battle(s) in total.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1:
# 710 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 10 wins: MUSIC OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2:
# 714 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 20 wins: BACKGROUND\n"
	.string "OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3:
# 718 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 30 wins: MEGA EVOLUTION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4:
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 40 wins: Z-MOVES.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5:
# 726 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 50 wins:\n"
	.string "TERASTALLISATION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6:
# 729 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All current Noland options are\n"
	.string "unlocked.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0:
# 738 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, nice going! You've unlocked MUSIC\n"
	.string "OPTIONS!\p"
	.string "From now on, I can tune your battles\n"
	.string "however you like--pick your tracks or\l"
	.string "let me shuffle them.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1:
# 746 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whoa! You're on a roll--BACKGROUND\n"
	.string "OPTIONS unlocked!\p"
	.string "Now you can pick your battle scenery,\n"
	.string "or leave it to chance with a shuffle.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2:
# 754 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Now that's battle sense! MEGA\n"
	.string "EVOLUTION is unlocked!\p"
	.string "Want mega power in your runs? Just tell\n"
	.string "me and I'll switch it on--or off.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3:
# 762 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You're really heating up! Z-MOVES are\n"
	.string "unlocked!\p"
	.string "If you want high-impact finishes, I can\n"
	.string "enable them for your Factory runs\l"
	.string "anytime.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4:
# 770 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Outstanding battling! You've unlocked\n"
	.string "TERASTALLISATION!\p"
	.string "You've got the full set now--I can\n"
	.string "toggle it on or off for your next\l"
	.string "challenge.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0:
# 781 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Interested in spicing up your battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1:
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2:
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3:
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0:
# 834 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION unlocks at 50 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1:
# 838 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2:
# 841 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3:
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change\n"
	.string "TERASTALLISATION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4:
# 844 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ENABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5:
# 844 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DISABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6:
# 847 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled TERASTALLISATION!\n"
	.string "POKéMON with the TERA BLAST move will\l"
	.string "also be added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7:
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled TERASTALLISATION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0:
# 858 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION unlocks at 30 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1:
# 862 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2:
# 865 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3:
# 867 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change MEGA\n"
	.string "EVOLUTION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4:
# 871 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled MEGA EVOLUTION! POKéMON\n"
	.string "with the ability to MEGA EVOLVE will be\l"
	.string "added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5:
# 874 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled MEGA EVOLUTION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0:
# 882 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES unlock at 40 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1:
# 886 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2:
# 889 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3:
# 891 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change Z-MOVE mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4:
# 895 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled Z-MOVES! POKéMON with the\n"
	.string "ability to use Z-MOVES will be added to\l"
	.string "the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5:
# 898 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled Z-MOVES!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Music options unlock at 10 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1:
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I can change the music that plays\n"
	.string "during your battles!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "R/S/E MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FR/LG MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "D/P MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLATINUM MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "HG/SS MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BLACK/WHITE MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SHUFFLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0:
# 937 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Ruby, Sapphire\n"
	.string "and Emerald:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. FRONTIER BRAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEW$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM AQUA & MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. REGI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE & GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RIVAL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11:
# 941 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ELITE FOUR$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12:
# 941 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. AQUA & MAGMA LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13:
# 941 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACK$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0:
# 978 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from FireRed and\n"
	.string "LeafGreen:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1:
# 981 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. DEOXYS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2:
# 982 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEWTWO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3:
# 982 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LEGEND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0:
# 1009 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Diamond and\n"
	.string "Pearl:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1:
# 1011 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. UXIE/ASELF/MESPRIT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2:
# 1012 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC BOSS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3:
# 1012 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS DIALGA/PALKIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4:
# 1013 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5:
# 1013 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ARCEUS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6:
# 1014 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GALACTIC COMMANDER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0:
# 1053 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Platinum:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1:
# 1055 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GIRATINA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0:
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from HeartGold and\n"
	.string "SoulSilver:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1:
# 1077 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM ROCKET$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2:
# 1077 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUICUNE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ENTEI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RAIKOU$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6:
# 1079 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7:
# 1079 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8:
# 1079 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. HO-OH$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9:
# 1079 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LUGIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10:
# 1080 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE/GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0:
# 1127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Black and\n"
	.string "White:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1:
# 1129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM PLASMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2:
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WINNING THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3:
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (1)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4:
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. IN A PINCH THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5:
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RESHIRAM/ZEKROM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6:
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (2)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7:
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GHETSIS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8:
# 1132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUBWAY TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9:
# 1132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CYNTHIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10:
# 1132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. STRONG WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11:
# 1133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYUREM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12:
# 1133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WCS CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Background options unlock at 20 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1:
# 1190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Fancy a new lick of paint on your\n"
	.string "battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DEFAULT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "LONG GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SAND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "UNDERWATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "WATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MOUNTAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAVE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BUILDING$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM AQUA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR SIDNEY$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR PHOEBE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR GLACIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20:
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR DRAKE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21:
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22:
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23:
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "KYOGRE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24:
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "RAYQUAZA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0:
# 1280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your music selection has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0:
# 1287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your background has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0:
# 1293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Is there anything else I can help you\n"
	.string "with?$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_0:
# 1305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "No special challengers are scheduled\n"
	.string "yet.\p"
	.string "Beat NOLAND once and I'll start\n"
	.string "tracking who's coming next.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_1:
# 1311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You've already beaten the current\n"
	.string "special challenger lineup.\p"
	.string "If new contenders show up, I'll let you\n"
	.string "know right away.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossReporter_Text_0:
# 1323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm with the FACTORY EXCLUSIVE team.\p"
	.string "Talk to my cameraman partner if you\n"
	.string "want the latest on incoming top\l"
	.string "TRAINERS.$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewIntro::
# 1387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Thank you for joining us.\p"
	.string "How does it feel to be the new HEAD of\n"
	.string "the BATTLE FACTORY?$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionOne::
# 1391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: That battle had the whole\n"
	.string "FRONTIER on its feet! How did you\l"
	.string "maintain your composure?$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionTwo::
# 1395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Do you have any advice for\n"
	.string "our audience on picking a strong team\l"
	.string "of rental POKeMON in the FACTORY?$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionThree::
# 1399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Last question. Will you\n"
	.string "defend your title?\p"
	.string "There's bound to be huge interest in\n"
	.string "the BATTLE FACTORY after this victory.$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewRumor::
# 1403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAMERAMAN: Big scoop time! Powerful\n"
	.string "TRAINERS from far and wide are already\l"
	.string "en route to the FACTORY.\p"
	.string "REPORTER: We'll be here around the\n"
	.string "clock to cover all the action.$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewCameramanCut::
# 1407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAMERAMAN: And... cut! Great take!$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewWrapUp::
# 1411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Thanks for your time! I've\n"
	.string "got to rush to another facility for the\l"
	.string "next big interview.\p"
	.string "See you on the FRONTIER feed!$"

BattleFrontier_BattleFactoryLobby_Text_CameramanHint::
# 1415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAMERAMAN: Psst, champ! I'm out here all\n"
	.string "day, so if you wanna know which\l"
	.string "powerful TRAINERS I've seen nearby,\l"
	.string "just let me know.$"
