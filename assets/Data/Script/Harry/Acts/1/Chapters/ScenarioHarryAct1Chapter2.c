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

extern EntitySpec Scene011Entity;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter2Sub1Scene1Entities[] =
{
	{&Scene011Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Choices PlayNovelScenarioHarryAct1Chapter2Sub1Scene1Choices =
{
	{
		{
			{
				"Cheryl's destination is...",
				"",
			},
			{
				1, 2, 0, 0, 0,
			},
		},
		{
			{
				"Is there no one in the town...",
				"",
			},
			{
				1, 3, 0, 0, 0,
			},
		},
		{{ NULL }, { 0, 0, 0, 0, 0 },},
	},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter2Sub1Scene1 = {
	kFadeTypeNone,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter2Sub1Scene1Entities,
	&PlayNovelScenarioHarryAct1Chapter2Sub1Scene1Choices,
	{
		{
			"What is going on...",
		},
		{
		}
	},
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter2Sub1 = {
	{
		"In search of anyone",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter2Sub1Scene1,
		NULL,
	},
};

// CHAPTER 2

const struct Chapter PlayNovelScenarioHarryAct1Chapter2 = {
	{
		"The Deserted Town",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter2Sub1,
		NULL,
	},
};