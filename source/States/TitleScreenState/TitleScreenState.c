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
#include <Utilities.h>
#include <AnimatedEntity.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <MessageDispatcher.h>
#include <I18n.h>
#include <Languages.h>
#include <PhysicalWorld.h>
#include <TitleScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <debugUtilities.h>
#include <AutomaticPauseManager.h>
#include <LoadGameScreenState.h>
#include <TradingCardsScreenState.h>
#include <MobileScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec TitleScreenStageSpec;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void TitleScreenState::constructor()
{
	Base::constructor();
}

void TitleScreenState::destructor()
{
	Base::destructor();
}

void TitleScreenState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&TitleScreenStageSpec, NULL, true, false);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// enable user input
	VUEngine::enableKeypad(VUEngine::getInstance());

	UIContainer uiContainer = Stage::getUIContainer(VUEngine::getStage(VUEngine::getInstance()));
	this->entityStart = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "Start", true));
	this->entityCards = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "Cards", true));
	this->entityMobile = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "Mobile", true));
	this->option = 0;
	TitleScreenState::updateOptionAnimations(this);

	// start fade in effect
	Camera::startEffect(Camera::getInstance(), kHide);
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		__FADE_DELAY, // delay between fading steps (in ms)
		NULL, // callback function
		NULL // callback scope
	);
}

void TitleScreenState::processUserInput(UserInput userInput)
{
	if((K_LU | K_RU) & userInput.pressedKey)
	{
		this->option = (this->option > 0) ? this->option - 1 : 2;
		TitleScreenState::updateOptionAnimations(this);
	}
	else if((K_LD | K_RD) & userInput.pressedKey)
	{
		this->option = (this->option < 2) ? this->option + 1 : 0;
		TitleScreenState::updateOptionAnimations(this);
	}
	else if((K_A | K_STA) & userInput.pressedKey)
	{
		TitleScreenState::loadSelectedOption(this);
	}
}

void TitleScreenState::updateOptionAnimations()
{
	switch(this->option)
	{
		case 0:
			AnimatedEntity::playAnimation(this->entityStart, "10");
			AnimatedEntity::playAnimation(this->entityCards, "0");
			AnimatedEntity::playAnimation(this->entityMobile, "0");
			break;
		case 1:
			AnimatedEntity::playAnimation(this->entityStart, "0");
			AnimatedEntity::playAnimation(this->entityCards, "10");
			AnimatedEntity::playAnimation(this->entityMobile, "0");
			break;
		case 2:
			AnimatedEntity::playAnimation(this->entityStart, "0");
			AnimatedEntity::playAnimation(this->entityCards, "0");
			AnimatedEntity::playAnimation(this->entityMobile, "10");
			break;
	}
}

void TitleScreenState::loadSelectedOption()
{
	switch(this->option)
	{
		case 0:
			SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(LoadGameScreenState::getInstance()));
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		case 1:
			SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(TradingCardsScreenState::getInstance()));
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
		case 2:
			SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(MobileScreenState::getInstance()));
			SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
			break;
	}
}
