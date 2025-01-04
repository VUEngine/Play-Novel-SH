/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

void IntroScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	VUEngine::disableKeypad(VUEngine::getInstance());
	this->nextState = GameState::safeCast(TitleScreenState::getInstance());
	IntroScreenState::addEventListener(this, ListenerObject::safeCast(this), (EventListener)IntroScreenState::onIntroDefaultAnimationComplete, kEventIntroAnimationCompleted);
}

void IntroScreenState::onIntroDefaultAnimationComplete(ListenerObject eventFirer __attribute__((unused)))
{
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kIntroMessageEndVideo, INTRO_DELAY, 0);	
	IntroScreenState::removeEventListener(this, ListenerObject::safeCast(this), (EventListener)IntroScreenState::onIntroDefaultAnimationComplete, kEventIntroAnimationCompleted);
}

bool IntroScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kIntroMessageEndVideo:
		{
			IntroScreenState::removeEventListener(this, ListenerObject::safeCast(this), (EventListener)IntroScreenState::onIntroDefaultAnimationComplete, kEventIntroAnimationCompleted);
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		}
	}

	return true;
}