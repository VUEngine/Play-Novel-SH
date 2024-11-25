/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef KCET_SCREEN_STATE_H_
#define KCET_SCREEN_STATE_H_


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <SplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define KCET_SCREEN_INITIAL_DELAY			500
#define KCET_SCREEN_AUTO_SKIP_DELAY			2600


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

enum KCETScreenMessages
{
	kKCETScreenMessageEnableInput,
	kKCETScreenMessageAutoSkip,
};


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class KCETScreenState : SplashScreenState
{
	static KCETScreenState getInstance();

	override void enter(void* owner);
	override bool handleMessage(Telegram telegram);
}


#endif
