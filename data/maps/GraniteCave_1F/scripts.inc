GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_Grunt::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRANITE_GRUNT, GraniteCave_1F_Movement_Grunt_Intro
	waitmovement 0 
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox GraniteCave_1F_Text_WhatAreYouDoingHere, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CAMRON, PetalburgWoods_Text_YoureKiddingMe
	msgbox GraniteCave_1F_Text_HowDefeatSteven, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, GraniteCave_1F_Movement_OutOfWay
	applymovement LOCALID_GRANITE_GRUNT, GraniteCave_1F_Movement_Grunt_Defeated
	goto GraniteCave_1F_EventScript_Grunt_Defeated
	end
	
GraniteCave_1F_EventScript_Grunt_Defeated::
	removeobject LOCALID_GRANITE_GRUNT
	setvar VAR_GRANITE_GRUNT, 1
	setflag FLAG_HIDE_GRANITE_GRUNT
	releaseall
	end

GraniteCave_1F_Movement_Grunt_Intro:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right

GraniteCave_1F_Movement_OutOfWay:
	walk_fast_right
	delay_4
	face_down

GraniteCave_1F_Movement_Grunt_Defeated:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

GraniteCave_1F_Text_WhatAreYouDoingHere:
	.string "What are you doing here?\p"
	.string "After you bested me in Petalburg Woods\n"
	.string "I've been looking for a way to steal\l"
	.string "something else for TEAM MAGMA\p"
	.string "I heard that STEVEN was here.\p"
	.string "With all those shiny rocks he collects\n"
	.string "he seems like a perfect target.\p"
	.string "The BOSS will be so proud of me when I\n"
	.string "come back with a shiny Ruby, Sapphire, or\l"
	.string "even an Emerald!\p"
	.string "But first, I'll have to deal with you!make$"

GraniteCave_1F_Text_HowDefeatSteven:
	.string "I can't believe this. If I cannot beat\n"
	.string "a puny kid like you with these stronger\l"
	.string "POKéMON how could I steal from STEVEN?\p"
	.string "I'll get my revenge on you, eventually."
