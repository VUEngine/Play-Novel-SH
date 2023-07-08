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

extern Sound TheBeastLurksSound;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter5Sub1Scene1Entities[] =
{
	{&Scene014Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Choices PlayNovelScenarioHarryAct1Chapter5Sub1Scene1Choices =
{
	{
		{
			{
				"I don't know who it is. I will take a look.",
				"",
			},
			{
				1, 5, 0, 0,
			},
		},
		{
			{
				"I am going to get out of here... I don't \nhave anything with me to use as a weapon.",
				"",
			},
			{
				1, 6, 0, 0,
			},
		},
		{{ NULL }, { 0, 0, 0, 0 },},
	},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter5Sub1Scene1 = {
	kFadeTypeNone,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	&TheBeastLurksSound,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter5Sub1Scene1Entities,
	&PlayNovelScenarioHarryAct1Chapter5Sub1Scene1Choices,
	{
		{
			"From the darkness I can hear multiple \nfootsteps coming this way...",
		},
		{
		}
	},
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter5Sub1 = {
	{
		"The eerie alley",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter5Sub1Scene1,
		NULL,
	},
};

const struct Chapter PlayNovelScenarioHarryAct1Chapter5 = {
	{
		"Multiple Footsteps",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter5Sub1,
		NULL,
	},
};