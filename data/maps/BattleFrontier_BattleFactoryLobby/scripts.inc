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

# 57 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript::
# 58 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 59 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 60 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 61 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 62 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 63 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 64 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 65 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_giverewardmon
# 66 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 67 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript::
# 68 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 69 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 70 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 71 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 72 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
# 73 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 74 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 75 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
# 76 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 77 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 78 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 79 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 80 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 81 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 82 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 83 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 84 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 85 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 86 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 87 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
# 88 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 89 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 90 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 91 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 92 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 93 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 94 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 95 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 96 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 97 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 98 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
# 99 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
# 101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
# 108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendant::
# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain::
# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle, MSGBOX_DEFAULT
# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge
# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge::
# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge, MSGBOX_DEFAULT
# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge::
# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE, BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc::
# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your POKéMON for\n"
# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.$"
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal POKéMON.$"
# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a DOUBLE BATTLE competition using\l"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a DOUBLE BATTLE.\p"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle:
# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Random\n"
# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge.\p"
# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is still under\n"
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development and may contain bugs.$"
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge:
# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Random\n"
# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge?$"
# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge:
# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This challenge uses rental POKeMON\n"
# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "sets from a Random Battles pool.\p"
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is under\n"
# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development, so issues may occur.\p"
# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Unlike Level 50 or Open Level modes,\n"
# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "each rental set has its own level,\l"
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "balanced for that set.\p"
# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Rules for battling and swapping are\n"
# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "otherwise the same as the regular\l"
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap challenge.$"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your POKéMON\n"
# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of POKéMON?\p"
# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about POKéMON and their moves,\l"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 553 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 554 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 555 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak POKéMON…\n"
# 556 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 557 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 558 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 559 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 560 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 562 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 563 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON during battle to see if\l"
# 564 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 565 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 567 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 568 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 569 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 570 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 571 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 572 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 573 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 574 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 575 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 576 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 577 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 578 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 579 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental POKéMON.$"
# 580 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 581 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 582 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 583 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 584 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 585 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 586 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 587 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 588 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 589 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three POKéMON.\p"
# 590 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 591 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same POKéMON.$"
# 593 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 594 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 595 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap POKéMON only with\n"
# 596 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the TRAINER you have just defeated.\p"
# 597 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those POKéMON\n"
# 598 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten TRAINER.$"
# 599 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 600 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 601 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 602 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 603 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's POKéMON.\p"
# 604 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap POKéMON\n"
# 605 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh TRAINER in the event.$"
# 606 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 607 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 608 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 609 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping POKéMON.\p"
# 610 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 611 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the POKéMON you are\l"
# 612 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 613 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the POKéMON on your team\n"
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 615 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 616 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 617 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 618 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 619 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 620 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental POKéMON\n"
# 621 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' POKéMON\l"
# 622 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"

BattleFrontier_BattleFactoryLobby_Noland::
# 626 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 627 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Noland_Text_0
# 628 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices
# 629 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions::
# 633 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1:
# 636 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4:
# 639 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7:
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 644 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12
# 646 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13
# 648 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14
# 650 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15
# 652 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16
# 655 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10:
# 657 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2:
# 634 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5:
# 637 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8:
# 640 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12:
# 645 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13:
# 647 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14:
# 649 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15:
# 651 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16:
# 653 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic::
# 661 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 662 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 663 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3
# 665 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4
# 668 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1:
# 670 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3:
# 664 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4:
# 666 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground::
# 674 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 675 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 676 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3
# 678 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4
# 680 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5
# 683 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1:
# 685 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3:
# 677 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4:
# 679 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5:
# 681 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks::
# 689 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 690 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 691 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4
# 695 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5
# 697 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6
# 700 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1:
# 702 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3:
# 692 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4:
# 694 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5:
# 696 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6:
# 698 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins::
# 706 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_FACTORY_TOTAL_WINS
# 707 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0
# 708 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1:
# 712 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4:
# 716 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7:
# 720 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10:
# 724 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13:
# 728 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6
# 729 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2:
# 709 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1
# 710 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5:
# 713 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2
# 714 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8:
# 717 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3
# 718 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14:
# 725 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5
# 726 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13


BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices::
# 733 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1:
# 741 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4:
# 749 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9:
# 757 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14:
# 765 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19:
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2:
# 734 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5:
# 742 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7:
# 735 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 736 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 737 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0
# 738 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10:
# 750 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12:
# 743 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 744 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 745 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1
# 746 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15:
# 758 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17:
# 751 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 752 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 753 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2
# 754 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20:
# 766 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22:
# 759 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 760 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 761 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3
# 762 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24:
# 767 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 768 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 769 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4
# 770 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions::
# 780 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0
# 781 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1:
# 784 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4:
# 787 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 789 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9
# 791 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10
# 793 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11
# 795 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12
# 798 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7:
# 800 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2:
# 782 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5:
# 785 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9:
# 790 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10:
# 792 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11:
# 794 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12:
# 796 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly::
# 804 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 805 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 806 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3
# 808 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4
# 811 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1:
# 813 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3:
# 807 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4:
# 809 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ::
# 817 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 818 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 819 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3
# 821 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4
# 823 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5
# 826 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1:
# 828 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3:
# 820 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4:
# 822 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5:
# 824 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode::
# 832 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1:
# 836 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5
# 840 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4:
# 842 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 844 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 845 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10
# 848 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8:
# 852 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2:
# 833 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0
# 834 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5:
# 837 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10:
# 846 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6
# 847 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11:
# 849 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode::
# 856 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1:
# 860 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5
# 864 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4:
# 866 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3
# 867 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 868 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 869 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10
# 872 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8:
# 876 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2:
# 857 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0
# 858 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5:
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10:
# 870 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4
# 871 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11:
# 873 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5
# 874 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode::
# 880 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1:
# 884 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5
# 888 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4:
# 890 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3
# 891 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 892 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 893 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10
# 896 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8:
# 900 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2:
# 881 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0
# 882 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5:
# 885 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10:
# 894 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4
# 895 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11:
# 897 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5
# 898 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions::
# 904 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1:
# 908 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5
# 914 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6
# 916 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7
# 918 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8
# 920 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9
# 922 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10
# 924 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11
# 928 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12
# 931 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2:
# 905 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5:
# 913 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6:
# 915 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7:
# 917 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8:
# 919 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9:
# 921 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10:
# 923 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11:
# 925 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_BGM
# 926 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 927 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12:
# 929 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE::
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0
# 937 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 941 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 942 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3
# 944 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4
# 946 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5
# 948 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6
# 950 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7
# 952 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8
# 954 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9
# 956 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10
# 958 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11
# 960 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12
# 962 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13
# 964 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14
# 966 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15
# 969 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 972 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3:
# 943 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4:
# 945 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5:
# 947 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6:
# 949 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 3
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7:
# 951 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 4
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8:
# 953 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 5
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9:
# 955 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 6
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10:
# 957 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11:
# 959 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 8
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12:
# 961 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 9
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13:
# 963 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 10
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14:
# 965 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 11
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15:
# 967 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg::
# 977 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0
# 978 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 982 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 983 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3
# 985 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4
# 987 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5
# 989 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6
# 991 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7
# 993 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8
# 995 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9
# 997 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10
# 1000 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1:
# 1002 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1003 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1004 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3:
# 984 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4:
# 986 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 13
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5:
# 988 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 14
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6:
# 990 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 15
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7:
# 992 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 16
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8:
# 994 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9:
# 996 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 18
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10:
# 998 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP::
# 1008 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0
# 1009 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1014 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1015 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3
# 1017 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4
# 1019 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5
# 1021 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6
# 1023 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7
# 1025 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8
# 1027 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9
# 1029 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10
# 1031 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11
# 1033 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12
# 1035 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13
# 1037 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14
# 1039 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15
# 1041 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16
# 1044 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1:
# 1046 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1047 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1048 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3:
# 1016 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 19
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4:
# 1018 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 20
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5:
# 1020 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 21
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6:
# 1022 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7:
# 1024 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 23
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8:
# 1026 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9:
# 1028 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 25
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10:
# 1030 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 26
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11:
# 1032 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 27
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12:
# 1034 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 28
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13:
# 1036 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 29
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14:
# 1038 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 30
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15:
# 1040 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 31
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16:
# 1042 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum::
# 1052 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0
# 1053 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1055 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1056 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3
# 1058 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4
# 1060 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5
# 1062 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6
# 1065 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1:
# 1067 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1068 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1069 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3:
# 1057 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 32
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4:
# 1059 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 33
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5:
# 1061 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 34
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6:
# 1063 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs::
# 1073 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1080 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1081 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3
# 1083 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4
# 1085 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5
# 1087 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6
# 1089 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7
# 1091 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8
# 1093 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9
# 1095 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10
# 1097 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11
# 1099 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12
# 1101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13
# 1103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14
# 1105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15
# 1107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16
# 1109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17
# 1111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18
# 1113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19
# 1115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20
# 1118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1:
# 1120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3:
# 1082 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 35
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4:
# 1084 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 36
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5:
# 1086 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 37
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6:
# 1088 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 38
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7:
# 1090 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 39
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8:
# 1092 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 40
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9:
# 1094 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 41
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10:
# 1096 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 42
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11:
# 1098 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 43
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12:
# 1100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 44
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13:
# 1102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 45
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14:
# 1104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 46
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15:
# 1106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 47
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16:
# 1108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 48
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17:
# 1110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 49
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18:
# 1112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 50
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19:
# 1114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 51
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20:
# 1116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite::
# 1126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0
# 1127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3
# 1136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4
# 1138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5
# 1140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6
# 1142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7
# 1144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8
# 1146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9
# 1148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10
# 1150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11
# 1152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12
# 1154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13
# 1156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14
# 1158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15
# 1160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16
# 1162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17
# 1164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18
# 1166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19
# 1168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20
# 1170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21
# 1172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22
# 1174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23
# 1177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1:
# 1179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3:
# 1135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 52
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4:
# 1137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 53
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5:
# 1139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 54
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6:
# 1141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 55
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7:
# 1143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 56
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8:
# 1145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 57
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9:
# 1147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 58
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10:
# 1149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 59
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11:
# 1151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 60
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12:
# 1153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 61
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13:
# 1155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 62
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14:
# 1157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 63
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15:
# 1159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 64
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16:
# 1161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 65
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17:
# 1163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 66
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18:
# 1165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 67
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19:
# 1167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 68
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20:
# 1169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 69
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21:
# 1171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 70
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22:
# 1173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 71
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23:
# 1175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions::
# 1185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1:
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1
# 1190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6
# 1200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7
# 1202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8
# 1205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9
# 1208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10
# 1211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11
# 1214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12
# 1217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13
# 1220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14
# 1223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15
# 1226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16
# 1229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17
# 1232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18
# 1235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19
# 1238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20
# 1241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21
# 1244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22
# 1247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23
# 1250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24
# 1253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25
# 1256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26
# 1259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27
# 1262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28
# 1265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29
# 1268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 24, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30
# 1271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4:
# 1273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2:
# 1186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6:
# 1198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 0
# 1199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7:
# 1201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8:
# 1203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 1
# 1204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9:
# 1206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 2
# 1207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10:
# 1209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 3
# 1210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11:
# 1212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 4
# 1213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12:
# 1215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 5
# 1216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13:
# 1218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 6
# 1219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14:
# 1221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 7
# 1222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15:
# 1224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 8
# 1225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16:
# 1227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 9
# 1228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17:
# 1230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 10
# 1231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18:
# 1233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 11
# 1234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19:
# 1236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 12
# 1237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20:
# 1239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 13
# 1240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21:
# 1242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 14
# 1243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22:
# 1245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 15
# 1246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23:
# 1248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 16
# 1249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24:
# 1251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 17
# 1252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25:
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 18
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26:
# 1257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 19
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27:
# 1260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 20
# 1261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28:
# 1263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 21
# 1264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29:
# 1266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 22
# 1267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30:
# 1269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess::
# 1278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0
# 1280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess::
# 1285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0
# 1287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse::
# 1292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0
# 1293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 1297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0
# 1299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_selectrewardmon
	return


BattleFrontier_BattleFactoryLobby_EventScript_BossScout::
# 1303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 1304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 1305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_BOSS_UNLOCK_STATE, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_2
# 1310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special GetNextFactoryBossIdForScout
# 1311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_BossScout_5
# 1316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setorcopyvar VAR_0x8004, VAR_RESULT
# 1317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special BufferFactoryBossScoutHintTextFromVar
# 1318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox gStringVar4
# 1319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_2:
# 1306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_0
# 1307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_5:
# 1312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_1
# 1313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end


BattleFrontier_BattleFactoryLobby_EventScript_BossReporter::
# 1324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_BossReporter_Text_0
	end


BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter::
# 1329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_SCOUT_INTRO_SEEN, BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_2
BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_1:
# 1332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_HIDE_BATTLE_FACTORY_LOBBY_CAMERAMAN, BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_5
BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_4:
# 1335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_REPORTER
# 1336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	addobject LOCALID_FACTORY_BOSS_REPORTER
	end

BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_2:
# 1330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_Hide
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_1

BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_5:
# 1333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_Hide
	goto BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_4


BattleFrontier_BattleFactoryLobby_EventScript_PrepareScoutReporter_Hide::
# 1341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_REPORTER
	end


BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview::
# 1346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_SCOUT_INTRO_SEEN, BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_2
BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_1:
# 1349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_HIDE_BATTLE_FACTORY_LOBBY_CAMERAMAN, BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_5
BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_4:
# 1352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 1353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_FACTORY_BOSS_SCOUT, DIR_SOUTH
# 1354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, Common_Movement_ExclamationMark
# 1355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
# 1357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, BattleFrontier_BattleFactoryLobby_Movement_ReporterApproachPlayer
# 1358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 1360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewIntro
# 1361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, BattleFrontier_BattleFactoryLobby_Movement_ReporterLeadToCamera
# 1362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerFollowReporterToCamera
# 1363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_FACTORY_BOSS_REPORTER, DIR_SOUTH
# 1365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 1366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionOne
# 1367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionTwo
# 1368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionThree
# 1369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewRumor
# 1370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewCameramanCut
# 1371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	fadedefaultbgm
# 1372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewWrapUp
# 1373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 1374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_FACTORY_BOSS_REPORTER, BattleFrontier_BattleFactoryLobby_Movement_ReporterExitAfterInterview
# 1375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 1376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_FACTORY_BOSS_SCOUT, DIR_SOUTH
# 1377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CameramanHint
# 1378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 1379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_HIDE_BATTLE_FACTORY_LOBBY_REPORTER
# 1380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_SCOUT_INTRO_SEEN
# 1381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_2:
# 1347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_Done
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_1

BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_5:
# 1350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_Done
	goto BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_4


BattleFrontier_BattleFactoryLobby_EventScript_MaybeScoutInterview_Done::
	end


# 1420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_ReporterApproachPlayer:
# 1421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_left
# 1421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_left
	step_end

# 1424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_ReporterLeadToCamera:
# 1425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
	step_end

# 1430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerFollowReporterToCamera:
# 1431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	face_up
	step_end

# 1436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_ReporterExitAfterInterview:
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_down
# 1438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_right
# 1439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	face_down
# 1440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay_8
# 1441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Noland_Text_0:
# 627 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, {PLAYER}. Can't handle the heat?\n"
	.string "Or just fancy a new challenge? Let me\l"
	.string "know and I'll adjust some things for ya.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0:
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GIMMICK OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1:
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MUSIC OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2:
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACKGROUND OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3:
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TOTAL WINS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4:
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CANCEL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0:
# 707 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You've won {STR_VAR_1} Battle\n"
	.string "Factory battle(s) in total.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1:
# 709 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 10 wins: MUSIC OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2:
# 713 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 20 wins: BACKGROUND\n"
	.string "OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3:
# 717 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 30 wins: MEGA EVOLUTION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 40 wins: Z-MOVES.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5:
# 725 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 50 wins:\n"
	.string "TERASTALLISATION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6:
# 728 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All current Noland options are\n"
	.string "unlocked.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0:
# 737 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, nice going! You've unlocked MUSIC\n"
	.string "OPTIONS!\p"
	.string "From now on, I can tune your battles\n"
	.string "however you like--pick your tracks or\l"
	.string "let me shuffle them.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1:
# 745 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whoa! You're on a roll--BACKGROUND\n"
	.string "OPTIONS unlocked!\p"
	.string "Now you can pick your battle scenery,\n"
	.string "or leave it to chance with a shuffle.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2:
# 753 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Now that's battle sense! MEGA\n"
	.string "EVOLUTION is unlocked!\p"
	.string "Want mega power in your runs? Just tell\n"
	.string "me and I'll switch it on--or off.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3:
# 761 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You're really heating up! Z-MOVES are\n"
	.string "unlocked!\p"
	.string "If you want high-impact finishes, I can\n"
	.string "enable them for your Factory runs\l"
	.string "anytime.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4:
# 769 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Outstanding battling! You've unlocked\n"
	.string "TERASTALLISATION!\p"
	.string "You've got the full set now--I can\n"
	.string "toggle it on or off for your next\l"
	.string "challenge.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0:
# 780 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Interested in spicing up your battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1:
# 787 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2:
# 787 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3:
# 787 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0:
# 833 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION unlocks at 50 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1:
# 837 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2:
# 840 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3:
# 842 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change\n"
	.string "TERASTALLISATION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4:
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ENABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5:
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DISABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6:
# 846 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled TERASTALLISATION!\n"
	.string "POKéMON with the TERA BLAST move will\l"
	.string "also be added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7:
# 849 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled TERASTALLISATION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0:
# 857 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION unlocks at 30 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1:
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2:
# 864 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3:
# 866 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change MEGA\n"
	.string "EVOLUTION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4:
# 870 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled MEGA EVOLUTION! POKéMON\n"
	.string "with the ability to MEGA EVOLVE will be\l"
	.string "added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5:
# 873 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled MEGA EVOLUTION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0:
# 881 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES unlock at 40 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1:
# 885 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2:
# 888 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3:
# 890 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change Z-MOVE mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4:
# 894 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled Z-MOVES! POKéMON with the\n"
	.string "ability to use Z-MOVES will be added to\l"
	.string "the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5:
# 897 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled Z-MOVES!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0:
# 905 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Music options unlock at 10 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1:
# 908 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I can change the music that plays\n"
	.string "during your battles!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2:
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "R/S/E MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3:
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FR/LG MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4:
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "D/P MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5:
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLATINUM MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6:
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "HG/SS MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7:
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BLACK/WHITE MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8:
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SHUFFLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0:
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Ruby, Sapphire\n"
	.string "and Emerald:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1:
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2:
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. FRONTIER BRAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3:
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEW$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4:
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5:
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM AQUA & MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. REGI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE & GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RIVAL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ELITE FOUR$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. AQUA & MAGMA LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACK$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0:
# 977 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from FireRed and\n"
	.string "LeafGreen:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1:
# 980 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. DEOXYS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2:
# 981 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEWTWO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3:
# 981 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LEGEND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0:
# 1008 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Diamond and\n"
	.string "Pearl:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1:
# 1010 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. UXIE/ASELF/MESPRIT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2:
# 1011 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC BOSS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3:
# 1011 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS DIALGA/PALKIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4:
# 1012 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5:
# 1012 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ARCEUS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6:
# 1013 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GALACTIC COMMANDER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0:
# 1052 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Platinum:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1:
# 1054 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GIRATINA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0:
# 1073 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from HeartGold and\n"
	.string "SoulSilver:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1:
# 1076 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM ROCKET$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2:
# 1076 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUICUNE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3:
# 1077 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ENTEI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4:
# 1077 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RAIKOU$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5:
# 1077 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. HO-OH$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LUGIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10:
# 1079 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE/GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0:
# 1126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Black and\n"
	.string "White:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1:
# 1128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM PLASMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2:
# 1129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WINNING THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3:
# 1129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (1)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4:
# 1129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. IN A PINCH THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5:
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RESHIRAM/ZEKROM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6:
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (2)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7:
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GHETSIS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8:
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUBWAY TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9:
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CYNTHIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10:
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. STRONG WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11:
# 1132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYUREM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12:
# 1132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WCS CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0:
# 1186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Background options unlock at 20 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1:
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Fancy a new lick of paint on your\n"
	.string "battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DEFAULT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "LONG GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SAND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "UNDERWATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "WATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MOUNTAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAVE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BUILDING$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12:
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16:
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM AQUA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR SIDNEY$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR PHOEBE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR GLACIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR DRAKE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "KYOGRE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24:
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "RAYQUAZA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0:
# 1279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your music selection has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0:
# 1286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your background has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0:
# 1292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Is there anything else I can help you\n"
	.string "with?$"

BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0:
# 1297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a reward for your display of skill, you will be able to select one of the POKéMON in your party to keep\n"
	.string "forever, for use in other BATTLE FRONTIER facilities.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_0:
# 1306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "No special challengers are scheduled\n"
	.string "yet.\p"
	.string "Beat NOLAND once and I'll start\n"
	.string "tracking who's coming next.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossScout_Text_1:
# 1312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You've already beaten the current\n"
	.string "special challenger lineup.\p"
	.string "If new contenders show up, I'll let you\n"
	.string "know right away.$"

BattleFrontier_BattleFactoryLobby_EventScript_BossReporter_Text_0:
# 1324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm with the FACTORY EXCLUSIVE team.\p"
	.string "Talk to my cameraman partner if you\n"
	.string "want the latest on incoming top\l"
	.string "TRAINERS.$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewIntro::
# 1388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Thank you for joining us.\p"
	.string "How does it feel to be the new HEAD of\n"
	.string "the BATTLE FACTORY?$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionOne::
# 1392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: That battle had the whole\n"
	.string "FRONTIER on its feet! How did you\l"
	.string "maintain your composure?$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionTwo::
# 1396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Do you have any advice for\n"
	.string "our audience on picking a strong team\l"
	.string "of rental POKeMON in the FACTORY?$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewQuestionThree::
# 1400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Last question. Will you\n"
	.string "defend your title?\p"
	.string "There's bound to be huge interest in\n"
	.string "the BATTLE FACTORY after this victory.$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewRumor::
# 1404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAMERAMAN: Big scoop time! Powerful\n"
	.string "TRAINERS from far and wide are already\l"
	.string "en route to the FACTORY.\p"
	.string "REPORTER: We'll be here around the\n"
	.string "clock to cover all the action.$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewCameramanCut::
# 1408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAMERAMAN: And... cut! Great take!$"

BattleFrontier_BattleFactoryLobby_Text_ScoutInterviewWrapUp::
# 1412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "REPORTER: Thanks for your time! I've\n"
	.string "got to rush to another facility for the\l"
	.string "next big interview.\p"
	.string "See you on the FRONTIER feed!$"

BattleFrontier_BattleFactoryLobby_Text_CameramanHint::
# 1416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAMERAMAN: Psst, champ! I'm out here all\n"
	.string "day, so if you wanna know which\l"
	.string "powerful TRAINERS I've seen nearby,\l"
	.string "just let me know.$"
