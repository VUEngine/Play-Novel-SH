/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef VISUAL_NOVEL_STATE_H_
#define VISUAL_NOVEL_STATE_H_


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <GameState.h>



//——————————————————————————————————————————————————————————————————————————————————————————————————————————

//											CLASS'S MACROS

//——————————————————————————————————————————————————————————————————————————————————————————————————————————


#define CHARACTER_DELAY			1
#define NUMBER_OF_LANGUAGES		2
#define MAX_CHOICES				3
#define MAX_BRANCHING_TARGETS	3


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

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
	kFadeTypeNone,
	kFadeTypeNormal,
	kFadeTypeSlow,
};



//——————————————————————————————————————————————————————————————————————————————————————————————————————————

// 											TYPE DEFINITIONS

//——————————————————————————————————————————————————————————————————————————————————————————————————————————


typedef struct TargetPage
{
	uint16 act;
	uint16 chapter;
	uint16 subChapter;
	uint16 scene;
} TargetPage;

typedef struct BranchingTarget
{
	TargetPage target;
	//TODO: conditions
} BranchingTarget;

typedef struct BranchingTargets
{
	BranchingTarget branchingTargets[MAX_BRANCHING_TARGETS];
} BranchingTargets;

typedef struct Choice
{
	char* text[NUMBER_OF_LANGUAGES];
	TargetPage targetPage;
} Choice;

typedef struct Choices
{
	Choice choices[MAX_CHOICES];
} Choices;

typedef struct Scene
{
	uint8 fadeInType;
	uint8 fadeOutType;
	int8 soundPlaybackType;
	const SoundSpec* sound;
	const PositionedEntity* positionedEntities;
	const Choices* choices;
	char* text[NUMBER_OF_LANGUAGES][MAX_TEXT_PER_SCENE];
	const BranchingTargets* branchingTargets;
} Scene;

typedef struct SubChapter
{
	char* title[NUMBER_OF_LANGUAGES];
	const Scene *scenes[];
} SubChapter;

typedef struct Chapter
{
	char* title[NUMBER_OF_LANGUAGES];
	const SubChapter *subChapters[];
} Chapter;

typedef struct Act
{
	char* title[NUMBER_OF_LANGUAGES];
	const Chapter *chapters[];
} Act;

typedef struct Scenario
{
	char* title[NUMBER_OF_LANGUAGES];
	const Act *acts[];
} Scenario;

typedef struct Script
{
	char* title[NUMBER_OF_LANGUAGES];
	const Scenario *scenarios[];
} Script;



//——————————————————————————————————————————————————————————————————————————————————————————————————————————

//											CLASS'S DECLARATION

//——————————————————————————————————————————————————————————————————————————————————————————————————————————


singleton class VisualNovelState : GameState
{
	Entity entityFlauros;
	GameProgress progress;
	uint16 textLength;
	uint16 charNumber;
	bool pageFinished;	
	const char* text;
	uint8 charX;
	uint8 charY;
	uint8 saveSlot;
	uint8 language;
	uint8 choicesMenuOptionCount;
	uint8 choicesMenuOption;

	static VisualNovelState getInstance();
	
	void setSaveSlot(uint8 saveSlot);
	override void enter(void* owner);
	override void execute(void* owner);
	override void processUserInput(UserInput userInput);
	override bool handleMessage(Telegram telegram);
}


#endif
