/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef TITLE_SCREEN_STATE_H_
#define TITLE_SCREEN_STATE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <SplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class TitleScreenState : SplashScreenState
{
	AnimatedEntity entityStart;
	AnimatedEntity entityCards;
	AnimatedEntity entityMobile;
	uint8 option;

	static TitleScreenState getInstance();

	override void enter(void* owner);
	override void processUserInput(UserInput userInput);
}


#endif
