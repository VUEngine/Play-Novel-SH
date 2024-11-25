/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef KONAMI_SCREEN_STATE_H_
#define KONAMI_SCREEN_STATE_H_


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <SplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define KONAMI_SCREEN_INITIAL_DELAY			    500
#define KONAMI_SCREEN_AUTO_SKIP_DELAY			2600


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

enum KonamiScreenMessages
{
	kKonamiScreenMessageEnableInput,
	kKonamiScreenMessageAutoSkip,
};


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class KonamiScreenState : SplashScreenState
{
	static KonamiScreenState getInstance();

	override void enter(void* owner);
	override bool handleMessage(Telegram telegram);
}


#endif
