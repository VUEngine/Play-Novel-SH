/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef TITLE_SCREEN_STATE_H_
#define TITLE_SCREEN_STATE_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <SplashScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

singleton class TitleScreenState : SplashScreenState
{
	Actor actorStart;
	Actor actorCards;
	Actor actorMobile;
	uint8 option;

	static TitleScreenState getInstance();

	override void enter(void* owner);
	override void processUserInput(UserInput userInput);
}

#endif
