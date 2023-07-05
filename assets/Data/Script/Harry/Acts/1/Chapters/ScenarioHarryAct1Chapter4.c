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

extern EntitySpec Scene012Entity;
extern EntitySpec Scene012CherylEntity;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene1Entities[] =
{
	{&Scene012Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};


const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNone,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene1Entities,
	NULL,
	{
		{
			"I begin to run. \nOnly the sounds of my footsteps echo in \nthe surroundings.",
			"Just where in the world has Cheryl gone? \nDid someone lead her away? \nVarious concerns run through my mind."
		},
		{
		}
	},
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene2Entities[] =
{
	{&Scene012Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{&Scene012CherylEntity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};


const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene2 = {
	kFadeTypeNone,
	kFadeTypeNone,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene2Entities,
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
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter4Sub1Scene3Entities[] =
{
	{&Scene012Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};


const struct Scene PlayNovelScenarioHarryAct1Chapter4Sub1Scene3 = {
	kFadeTypeNone,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter4Sub1Scene3Entities,
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