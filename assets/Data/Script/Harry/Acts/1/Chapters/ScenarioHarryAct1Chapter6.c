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

extern EntitySpec Scene014Entity;
extern EntitySpec Scene015Entity;

extern Sound MonsterSoundSound;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter6Sub1Scene1Entities[] =
{
	{&Scene014Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter6Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter6Sub1Scene1Entities,
	NULL,
	{
		{
			"\"What the... What are they...\"",
			"With beast-like rage, they have closed in \nto right where I am.",
			"I stood ready."
		},
		{
		}
	},
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter6Sub1Scene2Entities[] =
{
	{&Scene015Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter6Sub1Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter6Sub1Scene2Entities,
	NULL,
	{
		{
			"\"Ah...\"",
			"And then my vitality is sucked away by these \nstrangely shaped monsters until I finally \nlose consciousness..."
		},
		{
		}
	},
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter6Sub1Scene3Entities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter6Sub1Scene3 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	&MonsterSoundSound,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter6Sub1Scene3Entities,
	NULL,
	{
		{
			"You have reached the end of this demo.",
		},
		{
		}
	},
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter6Sub1 = {
	{
		"Harry looks around",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter6Sub1Scene1,
		&PlayNovelScenarioHarryAct1Chapter6Sub1Scene2,
		&PlayNovelScenarioHarryAct1Chapter6Sub1Scene3,
		NULL,
	},
};

const struct Chapter PlayNovelScenarioHarryAct1Chapter6 = {
	{
		"Listen Carefully",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter6Sub1,
		NULL,
	},
};