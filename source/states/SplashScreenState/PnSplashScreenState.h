/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */
 
#ifndef PN_SPLASH_SCREEN_STATE_H_
#define PN_SPLASH_SCREEN_STATE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <GameState.h>
#include "../config.h"


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

abstract class PnSplashScreenState : GameState
{
	// state to enter after this one
	GameState nextState;
	// spec of screen's stage
	StageSpec* stageSpec;

	void constructor();
	void loadNextState();
	void setNextState(GameState nextState);
	virtual void initNextState();
	virtual void print();
	override bool processMessage(void* owner, Telegram telegram);
	override void enter(void* owner);
	override void exit(void* owner);
	override void suspend(void* owner);
	override void resume(void* owner);
	override void processUserInput(UserInput userInput);
}


#endif
