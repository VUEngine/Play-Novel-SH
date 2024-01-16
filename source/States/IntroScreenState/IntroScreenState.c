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
#include <AnimatedEntity.h>
#include <IntroScreenState.h>
#include <TitleScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec IntroScreenStageSpec;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void IntroScreenState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&IntroScreenStageSpec;
}

void IntroScreenState::destructor()
{
	Base::destructor();
}

void IntroScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	VUEngine::disableKeypad(VUEngine::getInstance());
	this->nextState = GameState::safeCast(TitleScreenState::getInstance());
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kIntroMessageStartVideo, INTRO_DELAY, 0);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kIntroMessageEndVideo, INTRO_DELAY + INTRO_DURATION, 0);
}

bool IntroScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kIntroMessageStartVideo:
		{
			VUEngine::enableKeypad(VUEngine::getInstance());
			UIContainer uiContainer = VUEngine::getUIContainer(VUEngine::getInstance());
			AnimatedEntity animatedEntity = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "VIDEO", true));
			AnimatedEntity::playAnimation(animatedEntity, "Default");
			break;
		}
		case kIntroMessageEndVideo:
		{
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		}
	}

	return true;
}