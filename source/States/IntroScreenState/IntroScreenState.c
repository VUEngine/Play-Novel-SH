/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Singleton.h>
#include <Actor.h>
#include <GameEvents.h>
#include <Telegram.h>
#include <TitleScreenState.h>
#include <VUEngine.h>

#include "IntroScreenState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec IntroScreenStageSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void IntroScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	this->stageSpec = (StageSpec*)&IntroScreenStageSpec;
}

void IntroScreenState::destructor()
{	// Always explicitly call the base's destructor 
	Base::destructor();
}

bool IntroScreenState::onEvent(ListenerObject eventFirer __attribute__((unused)), uint16 eventCode)
{
	switch(eventCode)
	{
		case kEventAnimationCompleted:
		{
			ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kIntroMessageEndVideo, INTRO_DELAY, 0);	
	
			return false;
		}
	}

	return Base::onEvent(this, eventFirer, eventCode);
}

void IntroScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	KeypadManager::disable();
	this->nextState = GameState::safeCast(TitleScreenState::getInstance());
	IntroScreenState::addEventListener(this, ListenerObject::safeCast(this), kEventIntroAnimationCompleted);
}

bool IntroScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kIntroMessageEndVideo:
		{
			IntroScreenState::removeEventListener(this, ListenerObject::safeCast(this), kEventIntroAnimationCompleted);
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		}
	}

	return true;
}