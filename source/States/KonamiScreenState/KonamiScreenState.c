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
#include <KonamiScreenState.h>
#include <KCETScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec KonamiScreenStageSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void KonamiScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	this->stageSpec = (StageSpec*)&KonamiScreenStageSpec;
}

void KonamiScreenState::destructor()
{	// Always explicitly call the base's destructor 
	Base::destructor();
}

void KonamiScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	this->nextState = GameState::safeCast(KCETScreenState::getInstance());
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kKonamiScreenMessageEnableInput, KONAMI_SCREEN_INITIAL_DELAY, 0);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kKonamiScreenMessageAutoSkip, KONAMI_SCREEN_AUTO_SKIP_DELAY, 0);
}

bool KonamiScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kKonamiScreenMessageEnableInput:
		{
			VUEngine::enableKeypad();
			break;
		}
		case kKonamiScreenMessageAutoSkip:
		{
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		}
	}

	return true;
}
