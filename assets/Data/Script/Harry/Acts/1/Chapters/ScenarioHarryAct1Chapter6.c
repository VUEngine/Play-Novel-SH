/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <VisualNovelState.h>
#include <Languages.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern EntitySpec Scene014EntitySpec;
extern EntitySpec Scene015EntitySpec;

extern SoundSpec MonsterSoundSoundSpec;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter6Sub1Scene1Entities[] =
{
	{&Scene014EntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter6Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
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
	NULL,
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter6Sub1Scene2Entities[] =
{
	{&Scene015EntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct BranchingTargets PlayNovelScenarioHarryAct1Chapter6Sub1Scene2BranchingTargets =
{
	{
		{
			{
				1, 6, 0, 2,
			},
		}
	}
};

const struct Scene PlayNovelScenarioHarryAct1Chapter6Sub1Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
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
	&PlayNovelScenarioHarryAct1Chapter6Sub1Scene2BranchingTargets,
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter6Sub1 = {
	{
		"Harry looks around",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter6Sub1Scene1,
		&PlayNovelScenarioHarryAct1Chapter6Sub1Scene2,
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