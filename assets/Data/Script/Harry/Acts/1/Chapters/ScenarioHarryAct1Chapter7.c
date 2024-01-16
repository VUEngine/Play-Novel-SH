/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <VisualNovelState.h>
#include <Languages.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern EntitySpec Scene014EntitySpec;
extern EntitySpec Scene015EntitySpec;

extern SoundSpec MonsterSoundSoundSpec;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter7Sub1Scene1Entities[] =
{
	{&Scene014EntitySpec, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter7Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter7Sub1Scene1Entities,
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

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter7Sub1Scene2Entities[] =
{
	{&Scene015EntitySpec, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter7Sub1Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter7Sub1Scene2Entities,
	NULL,
	{
		{
			"\"Ah...\"",
			"And then my vitality is sucked away by these \nstrangely colliderd monsters until I finally \nlose consciousness..."
		},
		{
		}
	},
	NULL,
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter7Sub1Scene3Entities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter7Sub1Scene3 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	&MonsterSoundSoundSpec,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter7Sub1Scene3Entities,
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