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
extern EntitySpec Scene002Entity;
extern EntitySpec Scene002HighlightEntity;
extern EntitySpec Scene003Entity;
extern EntitySpec Scene004Entity;
extern EntitySpec Scene005Entity;
extern EntitySpec Scene006Entity;
extern EntitySpec Scene007Entity;
extern EntitySpec Scene008Entity;

extern Sound CarEngineSound;
extern Sound CarBrakingSound;
extern Sound CarEngineSound;
extern Sound EnteringOtherWorldSound;
extern Sound SomethingStrangeSound;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene1Entities[] =
{
	{&Scene001Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen01a,
		kStringIntroductionScreen01b,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene1Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene2Entities[] =
{
	{&Scene002Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	//{&Scene002HighlightEntity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	&CarEngineSound,
	{
		kStringIntroductionScreen02,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene2Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene3Entities[] =
{
	{&Scene003Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene3 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
NULL,
	{
		kStringIntroductionScreen03a,
		kStringIntroductionScreen03b,
		kStringIntroductionScreen03c,
		kStringIntroductionScreen03d,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene3Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene4Entities[] =
{
	{&Scene002Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene4 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen04a,
		kStringIntroductionScreen04b,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene4Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene5Entities[] =
{
	{&Scene004Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene5 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen05a,
		kStringIntroductionScreen05b,
		kStringIntroductionScreen05c,
		kStringIntroductionScreen05d,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene5Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene6Entities[] =
{
	{&Scene003Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene6 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen06a,
		kStringIntroductionScreen06b,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene6Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene7Entities[] =
{
	{&Scene002Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene7 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen07a,
		kStringIntroductionScreen07b,
		kStringIntroductionScreen07c,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene7Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene8Entities[] =
{
	{&Scene005Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene8 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	&SomethingStrangeSound,
	{
		kStringIntroductionScreen08a,
		kStringIntroductionScreen08b,
		kStringIntroductionScreen08c,
		kStringIntroductionScreen08d,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene8Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene9Entities[] =
{
	{&Scene006Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene9 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen09a,
		kStringIntroductionScreen09b,
		kStringIntroductionScreen09c,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene9Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene10Entities[] =
{
	{&Scene002Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene10 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	&EnteringOtherWorldSound,
	{
		kStringIntroductionScreen10a,
		kStringIntroductionScreen10b,
		kStringIntroductionScreen10c,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene10Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene11Entities[] =
{
	{&Scene003Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene11 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen11a,
		kStringIntroductionScreen11b,
		kStringIntroductionScreen11c,
		kStringIntroductionScreen11d,
		kStringIntroductionScreen11e,
		kStringIntroductionScreen11f,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene11Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene12Entities[] =
{
	{&Scene007Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene12 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen12,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene12Entities,
};

PositionedEntityROMSpec PlayNovelScenarioHarryChapter0Sub1Scene13Entities[] =
{
	{&Scene008Entity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, false},
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene13 = {
	kFadeTypeNormal,
	kFadeTypeSlow,
	kSoundWrapperPlaybackNormal,
	NULL,
	{
		kStringIntroductionScreen13a,
		kStringIntroductionScreen13b,
	},
	(PositionedEntity*)PlayNovelScenarioHarryChapter0Sub1Scene13Entities,
};

const struct Scene PlayNovelScenarioHarryChapter0Sub1Scene14 = {
	kFadeTypeNormal,
	kFadeTypeSlow,
	kSoundWrapperPlaybackNormal,
	&CarBrakingSound,
	{
	},
	NULL,
};

const struct SubChapter PlayNovelScenarioHarryChapter0Sub1 = {
	kStringIntroductionSubChapter1Title,
	{
		&PlayNovelScenarioHarryChapter0Sub1Scene1,
		&PlayNovelScenarioHarryChapter0Sub1Scene2,
		&PlayNovelScenarioHarryChapter0Sub1Scene3,
		&PlayNovelScenarioHarryChapter0Sub1Scene4,
		&PlayNovelScenarioHarryChapter0Sub1Scene5,
		&PlayNovelScenarioHarryChapter0Sub1Scene6,
		&PlayNovelScenarioHarryChapter0Sub1Scene7,
		&PlayNovelScenarioHarryChapter0Sub1Scene8,
		&PlayNovelScenarioHarryChapter0Sub1Scene9,
		&PlayNovelScenarioHarryChapter0Sub1Scene10,
		&PlayNovelScenarioHarryChapter0Sub1Scene11,
		&PlayNovelScenarioHarryChapter0Sub1Scene12,
		&PlayNovelScenarioHarryChapter0Sub1Scene13,
		&PlayNovelScenarioHarryChapter0Sub1Scene14,
	},
};

const struct Chapter PlayNovelScenarioHarryChapter0 = {
	kStringIntroduction,
	kStringIntroductionTitle,
	{
		&PlayNovelScenarioHarryChapter0Sub1,
	},
};
