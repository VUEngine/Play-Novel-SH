/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef LOAD_GAME_SCREEN_STATE_H_
#define LOAD_GAME_SCREEN_STATE_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <SplashScreenState.h>
#include <GameSaveDataManager.h>
#include <OptionsSelector.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

enum LoadGameScreenMessages
{
	kLoadGameScreenMessageShowScreen,
	kLoadGameScreenMessageShowSlot,
	kLoadGameScreenMessageMoveSelectedSlot,
};

enum LoadGameScreenModes
{
	kLoadGameScreenModeSelectSlot,
	kLoadGameScreenModeMoveSelectedSlot,
	kLoadGameScreenModeShowSlot,
	kLoadGameScreenModeConfirmSlot,
};

enum LoadGameScreenSlotOptions
{
	kLoadGameScreenSlotOptionContinue,
	kLoadGameScreenSlotOptionNewGame,
};

enum LoadGameScreenDeleteSlotOptions
{
	kLoadGameScreenSlotOptionYes,
	kLoadGameScreenSlotOptionNo,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

singleton class LoadGameScreenState : SplashScreenState
{
	OptionsSelector slotMenu;
	Actor actorCursor;
	Actor actorSubChapterBackground;
	Actor actorSlot[NUMBER_OF_SAVE_SLOTS];
	Actor actorSlotLabel[NUMBER_OF_SAVE_SLOTS];
	GameProgress progress[3];
	uint8 slot;
	uint8 slotMenuOption;
	uint8 mode;

	static LoadGameScreenState getInstance();

	override void enter(void* owner);
	override void execute(void* owner);
	override bool handleMessage(Telegram telegram);
	override void processUserInput(UserInput userInput);
}

#endif
