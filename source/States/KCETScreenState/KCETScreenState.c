/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <VUEngine.h>
#include <Telegram.h>
#include <KCETScreenState.h>
#include <MobileSystemScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec KCETScreenStageSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void KCETScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	this->stageSpec = (StageSpec*)&KCETScreenStageSpec;
}

void KCETScreenState::destructor()
{	// Always explicitly call the base's destructor 
	Base::destructor();
}

void KCETScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	this->nextState = GameState::safeCast(MobileSystemScreenState::getInstance());
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kKCETScreenMessageEnableInput, KCET_SCREEN_INITIAL_DELAY, 0);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kKCETScreenMessageAutoSkip, KCET_SCREEN_AUTO_SKIP_DELAY, 0);
}

bool KCETScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kKCETScreenMessageEnableInput:
		{
			VUEngine::enableKeypad();
			break;
		}
		case kKCETScreenMessageAutoSkip:
		{
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		}
	}

	return true;
}
