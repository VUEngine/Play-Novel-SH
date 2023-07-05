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

extern EntitySpec Scene001Entity;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub1Scene1Entities[] =
{
	{&Scene001Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub1Scene1Entities,
	{
		{
			"The silence pierces my ears.\nAs the wind blew, it was accompanied by \npiercing cold.",
			"Where am I? \nI can feel light faintly passing \nthrough my eyelids.",
			"I don't seem to be hurt. \nThat much is clear to me because I \ndon't feel any pain in my body.",
			"No, perhaps I've suffered an injury \nthat doesn't cause any pain? \nI...slowly try opening my heavy eyelids."
		},
		{
		}
	},
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter1Sub1 = {
	{
		"Harry wakes up in his jeep",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter1Sub1Scene1,
	},
};

// SUB CHAPTER 2

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub2Scene1Entities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub2Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub2Scene1Entities,
	{
		{
			"Out of season snow is pouring into the town. \nOther than the sound of droplets of ice \nhitting the ground, ",
			"there is nothing else to be heard.",
			"\"Silent Hill\" \nThat is what is assuredly written on the \nsign by the side of the road.",
			"Without realizing it, Cheryl and I have \nreached our destination.",
			"All my memories up to that point are gone. \nThe wind is blowing in... \nWhen I take a look next to me, I am shocked."
		},
		{
		}
	},
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub2Scene2Entities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub2Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub2Scene2Entities,
	{
		{
			"The passenger door has been left open. \nCheryl is nowhere to be seen."
		},
		{
		}
	},
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter1Sub2 = {
	{
		"Out of season snow",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter1Sub2Scene1,
		&PlayNovelScenarioHarryAct1Chapter1Sub2Scene2,
	},
};

// SUB CHAPTER 3

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub3Scene1Entities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub3Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub3Scene1Entities,
	{
		{
			"\"Silent Hill.\" This town, which should just \nbe a resort area, appears to have become just \nlike a ghost town for some reason, ",
			"or maybe it was waiting for us to \narrive, or perhaps the town just nestled \nup to us...",
			"So now I am alone. \nCheryl is not here.",
			"While I was sleeping, no, while I was knocked \nout Cheryl opened the passenger door and stepped \nout alone into this tourist spot that is ",
			"ruled by an unsettling silence. \nAnd then she left me to head somewhere..."
		},
		{
		}
	},
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub3Scene2Entities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub3Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub3Scene2Entities,
	{
		{
			"I tightly close my jacket around my neck and \nset off on foot in search of Cheryl. \nI wonder what in the world happened here?",
			"Nothing makes any sense. The silence, \nthe out of season snow... And strangest of \nall, the entire town is wrapped in a thick fog."
		},
		{
		}
	},
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter1Sub3 = {
	{
		"Ghost Town",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter1Sub3Scene1,
		&PlayNovelScenarioHarryAct1Chapter1Sub3Scene2,
		NULL,
	},
};

const struct Chapter PlayNovelScenarioHarryAct1Chapter1 = {
	{
		"Arrival",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter1Sub1,
		&PlayNovelScenarioHarryAct1Chapter1Sub2,
		&PlayNovelScenarioHarryAct1Chapter1Sub3,
		NULL,
	},
};
