/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <VisualNovelState.h>
#include <Languages.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern ActorSpec Scene014ActorSpec;
extern ActorSpec Scene015ActorSpec;

extern SoundSpec MonsterSoundSoundSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// SUB CHAPTER 1

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter7Sub1Scene1Actors[] =
{
	{&Scene014ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter7Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter7Sub1Scene1Actors,
	NULL,
	{
		{
			"I've got to get away. But I can't go back \nthe way I came... because that eerie \npresence is back there...",
			"So I move further in. I can only move \ngradually through the narrowing pitch-black \nalley by feeling around with my hands.",
			"But I only end up reaching a dead end. \nMetal fences surround the area, and they are \nso high that I don't think that I can ",
			"climb over them.",
			"They are coming from behind... \nI stood ready.",
			"\"What the... What are they...\"",
			"With beast-like rage, they have closed in \nto right where I am."
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter7Sub1Scene2Actors[] =
{
	{&Scene015ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter7Sub1Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter7Sub1Scene2Actors,
	NULL,
	{
		{
			"\"Ah...\"",
			"And then my vitality is sucked away by these \nstrangely shaped monsters until I finally \nlose consciousness..."
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter7Sub1Scene3Actors[] =
{
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter7Sub1Scene3 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	&MonsterSoundSoundSpec,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter7Sub1Scene3Actors,
	NULL,
	{
		{
			"You have reached the end of this demo.",
		},
		{
		}
	},
	NULL,
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter7Sub1 = {
	{
		"Harry runs away",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter7Sub1Scene1,
		&PlayNovelScenarioHarryAct1Chapter7Sub1Scene2,
		&PlayNovelScenarioHarryAct1Chapter7Sub1Scene3,
		NULL,
	},
};

const struct Chapter PlayNovelScenarioHarryAct1Chapter7 = {
	{
		"Escape into the Darkness",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter7Sub1,
		NULL,
	},
};