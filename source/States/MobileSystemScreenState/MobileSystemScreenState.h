/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef MOBILE_SYSTEM_SCREEN_STATE_H_
#define MOBILE_SYSTEM_SCREEN_STATE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <SplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define MOBILE_SYSTEM_SCREEN_INITIAL_DELAY				500
#define MOBILE_SYSTEM_SCREEN_AUTO_SKIP_DELAY			2600


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

enum MobileSystemScreenMessages
{
	kMobileSystemScreenMessageEnableInput,
	kMobileSystemScreenMessageAutoSkip,
};


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class MobileSystemScreenState : SplashScreenState
{
	static MobileSystemScreenState getInstance();

	override void enter(void* owner);
	override bool handleMessage(Telegram telegram);
}


#endif
