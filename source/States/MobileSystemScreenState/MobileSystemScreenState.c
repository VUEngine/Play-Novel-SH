/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <VUEngine.h>
#include <Telegram.h>
#include <MobileSystemScreenState.h>
#include <IntroScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec MobileSystemScreenStageSpec;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void MobileSystemScreenState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&MobileSystemScreenStageSpec;
}

void MobileSystemScreenState::destructor()
{
	Base::destructor();
}

void MobileSystemScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	this->nextState = GameState::safeCast(IntroScreenState::getInstance());
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileSystemScreenMessageEnableInput, MOBILE_SYSTEM_SCREEN_INITIAL_DELAY, 0);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileSystemScreenMessageAutoSkip, MOBILE_SYSTEM_SCREEN_AUTO_SKIP_DELAY, 0);
}

bool MobileSystemScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kMobileSystemScreenMessageEnableInput:
		{
			VUEngine::enableKeypad(VUEngine::getInstance());
			break;
		}
		case kMobileSystemScreenMessageAutoSkip:
		{
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		}
	}

	return true;
}
