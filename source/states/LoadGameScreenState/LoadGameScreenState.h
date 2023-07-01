/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef LOAD_GAME_SCREEN_STATE_H_
#define LOAD_GAME_SCREEN_STATE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <SplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

enum LoadGameScreenMessages
{
	kLoadGameScreenMessageShow,
};


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class LoadGameScreenState : SplashScreenState
{
	Entity entityCursor;
	uint8 option;

	static LoadGameScreenState getInstance();

	override void enter(void* owner);
	override bool handleMessage(Telegram telegram);
	override void processUserInput(UserInput userInput);
}


#endif
