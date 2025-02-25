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

extern ActorSpec Scene012ActorSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// SUB CHAPTER 1

PositionedActorROMSpec PlayNovelScenarioHarryAct1Chapter3Sub1Scene1Actors[] =
{
	{&Scene012ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter3Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct1Chapter3Sub1Scene1Actors,
	NULL,
	{
		{
			"I thought, I must find out if there \nis anyone other than myself here.",
			"This is definitely Silent Hill. I recognize \nthe signboard on that store. A long time \nago, when I was young I visited here once.",
			"All the doors on the shops and houses are \ntightly shut. \nNo...",
			"Among them there is one shop with its door \nopen, but there is no sign of anyone \ninside.",
			"It feels like just the people here suddenly \nvanished."
		},
		{
		}
	},
	NULL,
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter3Sub1 = {
	{
		"Is there no one else here?",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter3Sub1Scene1,
		NULL,
	},
};

const struct Chapter PlayNovelScenarioHarryAct1Chapter3 = {
	{
		"The Presence of Townspeople",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter3Sub1,
		NULL,
	},
};