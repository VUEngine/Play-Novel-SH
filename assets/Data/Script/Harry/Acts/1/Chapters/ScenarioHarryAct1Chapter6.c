/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <VisualNovelState.h>
#include <Languages.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern ActorSpec Scene014ActorSpec;
extern ActorSpec Scene015ActorSpec;

extern SoundSpec MonsterSoundSoundSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// SUB CHAPTER 1

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter6Sub1Scene1Actors[] =
{
	{&Scene014ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter6Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter6Sub1Scene1Actors,
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

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter6Sub1Scene2Actors[] =
{
	{&Scene015ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
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
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter6Sub1Scene2Actors,
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