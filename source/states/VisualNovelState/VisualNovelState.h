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
};

enum PlayNovelScenario
{
	kScenarioHarry,
	kScenarioCybil,
	kScenarioBoy,
};

enum PlayNoveFadeTypes
{
	kFadeTypeNoFade,
	kFadeTypeToBlack,
	kFadeTypeToBlackSlow,
};


//---------------------------------------------------------------------------------------------------------
// 											TYPE DEFINITIONS
//---------------------------------------------------------------------------------------------------------
/*
typedef struct VisualNovelEvent
{
	// scene,
	uint16 text;
	// sound,
} VisualNovelEvent;

typedef struct VisualNovelSubChapters
{
	uint16 chapter;
	uint16 title;
	uint16 description;
	VisualNovelEvent events[];
} VisualNovelSubChapters;

typedef struct VisualNovelScript
{
	char* name;
	VisualNovelSubChapters chapters[];
} VisualNovelScript;
*/

//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class VisualNovelState : GameState
{
	Entity entityFlauros;
	uint16 page;
	uint16 textLength;
	uint16 charNumber;
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
