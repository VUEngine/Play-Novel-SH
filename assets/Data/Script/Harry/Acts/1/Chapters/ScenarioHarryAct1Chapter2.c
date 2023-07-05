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


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter2Sub1Scene1Entities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter2Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter2Sub1Scene1Entities,
	{
		{
			"What is going on...",
			"Cheryl's destination is...",
			"Is there no one in the town...",
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