/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef VISUAL_NOVEL_STATE_H_
#define VISUAL_NOVEL_STATE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <GameState.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define CHARACTER_DELAY		1


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

enum VisualNovelMessages
{
	kVisualNovelMessagePrintChar,
	kVisualNovelMessageStartPage,
};

enum PlayNovelScenario
{
	kScenarioHarry,
	kScenarioCybil,
	kScenarioBoy,
};

enum PlayNovelFadeTypes
{
	kFadeTypeNoFade,
	kFadeTypeNormal,
	kFadeTypeSlow,
};


//---------------------------------------------------------------------------------------------------------
// 											TYPE DEFINITIONS
//---------------------------------------------------------------------------------------------------------

typedef struct Scene
{
	uint8 fadeInType;
	uint8 fadeOutType;
	uint8 soundPlaybackType;
	const Sound *sound;
	uint16 text[MAX_TEXT_PER_SCENE];
	const PositionedEntity* positionedEntities;
} Scene;

typedef struct SubChapter
{
	uint16 title;
	const Scene *scenes[];
} SubChapter;

typedef struct Chapter
{
	uint16 chapter;
	uint16 title;
	const SubChapter *subChapters[];
} Chapter;

typedef struct Scenario
{
	char* name;
	const Chapter *chapters[];
} Scenario;

typedef struct Script
{
	char* name;
	const Scenario *scenarios[];
} Script;


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class VisualNovelState : GameState
{
	Entity entityFlauros;
	uint16 chapter;
	uint16 subChapter;
	uint16 scene;
	uint16 page;
	uint16 textLength;
	uint16 charNumber;
	bool pageFinished;	
	const char* text;
	uint8 charX;
	uint8 charY;
	uint8 saveSlot;
	uint8 scenario;

	static VisualNovelState getInstance();

	override void enter(void* owner);
	override void processUserInput(UserInput userInput);
	override bool handleMessage(Telegram telegram);
}


#endif
