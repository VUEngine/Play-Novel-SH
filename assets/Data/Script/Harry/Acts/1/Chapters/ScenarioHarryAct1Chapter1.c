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

extern EntitySpec Scene009EntitySpec;
extern EntitySpec Scene010EntitySpec;
extern EntitySpec Scene011EntitySpec;

extern SoundSpec SilenceEndSoundSpec;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// SUB CHAPTER 1

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub1Scene1Entities[] =
{
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub1Scene1Entities,
	NULL,
	{
		{
			"The silence pierces my ears.\nAs the wind blew, it was accompanied by \npiercing cold.",
			"Where am I? \nI can feel light faintly passing through \nmy eyelids.",
			"I don't seem to be hurt. \nThat much is clear to me because I don't \nfeel any pain in my body.",
			"No, perhaps I've suffered an injury that \ndoesn't cause any pain? \nI... slowly try opening my heavy eyelids."
		},
		{
		}
	},
	NULL,
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter1Sub1 = {
	{
		"Harry wakes up in his jeep",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter1Sub1Scene1,
		NULL,
	},
};

// SUB CHAPTER 2

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub2Scene1Entities[] =
{
	{&Scene009EntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub2Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	&SilenceEndSoundSpec,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub2Scene1Entities,
	NULL,
	{
		{
			"Out of season snow is pouring \ninto the town.", 
			"Other than the sound of droplets of ice \nhitting the ground, there is nothing else \nto be heard.",
			"\"Silent Hill\" \nThat is what is assuredly written on the \nsign by the side of the road.",
			"Without realizing it, Cheryl and I have \nreached our destination.",
			"All my memories up to that point are gone. \nThe wind is blowing in... \nWhen I take a look next to me, I am shocked."
		},
		{
		}
	},
	NULL,
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub2Scene2Entities[] =
{
	{&Scene010EntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub2Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNone,
	kSoundPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub2Scene2Entities,
	NULL,
	{
		{
			"The passenger door has been left open. \nCheryl is nowhere to be seen."
		},
		{
		}
	},
	NULL,
};

const struct SubChapter PlayNovelScenarioHarryAct1Chapter1Sub2 = {
	{
		"Out of season snow",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter1Sub2Scene1,
		&PlayNovelScenarioHarryAct1Chapter1Sub2Scene2,
		NULL,
	},
};

// SUB CHAPTER 3

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub3Scene1Entities[] =
{
	{&Scene010EntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub3Scene1 = {
	kFadeTypeNone,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub3Scene1Entities,
	NULL,
	{
		{
			"\"Silent Hill.\" This town, which should just \nbe a resort area, appears to have become just \nlike a ghost town for some reason, ",
			"or maybe it was waiting for us to arrive, \nor perhaps the town just nestled \nup to us...",
			"So now I am alone. \nCheryl is not here.",
			"While I was sleeping, no, while I was knocked \nout, Cheryl opened the passenger door and \nstepped out alone into this ",
			"tourist spot that is ruled by an \nunsettling silence. \nAnd then she left me to head somewhere..."
		},
		{
		}
	},
	NULL,
};

PositionedEntityROMSpec PlayNovelScenarioHarryAct1Chapter1Sub3Scene2Entities[] =
{
	{&Scene011EntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct1Chapter1Sub3Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNone,
	kSoundPlaybackNormal,
	NULL,
	(PositionedEntity*)PlayNovelScenarioHarryAct1Chapter1Sub3Scene2Entities,
	NULL,
	{
		{
			"I tightly close my jacket around my neck and \nset off on foot in search of Cheryl. \nI wonder what in the world happened here?",
			"Nothing makes any sense. The silence, the \nout of season snow... And strangest of all, \nthe entire town is wrapped in a thick fog."
		},
		{
		}
	},
	NULL,
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
