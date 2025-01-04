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

extern ActorSpec Scene012ActorSpec;
extern ActorSpec Scene012CherylActorSpec;
extern ActorSpec Scene013ActorSpec;
extern ActorSpec Scene014ActorSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// SUB CHAPTER 1

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene1Actors[] =
{
	{&Scene012ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNone,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene1Actors,
	NULL,
	{
		{
			"I begin to run. \nOnly the sounds of my footsteps echo in \nthe surroundings.",
			"Just where in the world has Cheryl gone? \nDid someone lead her away? \nVarious concerns run through my mind."
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene2Actors[] =
{
	{&Scene012ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&Scene012CherylActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene2 = {
	kFadeTypeNone,
	kFadeTypeNone,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene2Actors,
	NULL,
	{
		{
			"(Ta ta ta ta...)",
			"I suddenly get the feeling that I heard \nfootsteps other than my own, so I stop \nmoving right away to check it out.",
			"Through the thick fog I can see a figure \nthat is about the size of a child.",
			"\"Cheryl?\" \nWithout a thought I cry out. \nThe figure doesn't move at all."
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene3Actors[] =
{
	{&Scene012ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene3 = {
	kFadeTypeNone,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene3Actors,
	NULL,
	{
		{
			"At the moment I begin to move slowly \ntowards the figure it starts to run. \nI fiercely chase after the figure.",
			"That's definitely Cheryl. \nEven though it is faint, I would not \nmistake someone else for Cheryl.",
			"However, no matter how much I run I cannot \ncatch up.",
			"Instead the figure is gradually getting \nfarther away from me. The figure puts on \nspeed as if it is gliding through the air."
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene4Actors[] =
{
	{&Scene013ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene4 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene4Actors,
	NULL,
	{
		{
			"The figure appears to be absorbed by the fog \nas it begins to disappear.",
			"In order not to lose it, I run with all my \nstrength while keeping my vision centered \non the figure.",
			"I then notice that I have come to an alley \nsurrounded by buildings."
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene5Actors[] =
{
	{&Scene014ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene5 = {
	kFadeTypeNormal,
	kFadeTypeNone,
	-1,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene5Actors,
	NULL,
	{
		{
			"I don't know how, but it is like a cover was \nplaced over the sky, which had provided light \nuntil now.",
			"And the area has become engulfed \nin darkness."
		},
		{
		}
	},
	NULL,
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter4Sub1 = {
	{
		"Beginning the search for Cheryl",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter4Sub1Scene1,
		&PlayNovelScenarioHarryAct1Chapter4Sub1Scene2,
		&PlayNovelScenarioHarryAct1Chapter4Sub1Scene3,
		&PlayNovelScenarioHarryAct1Chapter4Sub1Scene4,
		&PlayNovelScenarioHarryAct1Chapter4Sub1Scene5,
		NULL,
	},
};

const struct Chapter PlayNovelScenarioHarryAct1Chapter4 = {
	{
		"Cheryl's Whereabouts",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter4Sub1,
		NULL,
	},
};