/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef MOBILE_SCREEN_STATE_H_
#define MOBILE_SCREEN_STATE_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <SplashScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//											CLASS'S MACROS

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define CONNECTION_TIMEOUT	10000

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

enum MobileScreenMessages
{
	kMobileScreenMessageShowPrepare,
	kMobileScreenMessageShowError,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

singleton class MobileScreenState : SplashScreenState
{
	static MobileScreenState getInstance();

	override void enter(void* owner);
	override bool handleMessage(Telegram telegram);
}

#endif
