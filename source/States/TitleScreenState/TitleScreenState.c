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
#include <Utilities.h>
#include <Actor.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <MessageDispatcher.h>
#include <I18n.h>
#include <Languages.h>
#include <BodyManager.h>
#include <TitleScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <AutomaticPauseManager.h>
#include <LoadGameScreenState.h>
#include <TradingCardsScreenState.h>
#include <MobileScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec TitleScreenStageSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void TitleScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}

void TitleScreenState::destructor()
{	// Always explicitly call the base's destructor 
	Base::destructor();
}

void TitleScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	// Load stage
	GameState::configureStage(GameState::safeCast(this), (StageSpec*)&TitleScreenStageSpec, NULL);

	// Start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// Enable user input
	VUEngine::enableKeypad();

	UIContainer uiContainer = VUEngine::getUIContainer();
	this->actorStart = Actor::safeCast(UIContainer::getChildByName(uiContainer, "Start", true));
	this->actorCards = Actor::safeCast(UIContainer::getChildByName(uiContainer, "Cards", true));
	this->actorMobile = Actor::safeCast(UIContainer::getChildByName(uiContainer, "Mobile", true));
	this->option = 0;
	TitleScreenState::updateOptionAnimations(this);

	// Start fade in effect
	Camera::startEffect(kHide);
	Camera::startEffect(
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
			Actor::playAnimation(this->actorStart, "10");
			Actor::playAnimation(this->actorCards, "0");
			Actor::playAnimation(this->actorMobile, "0");
			break;
		case 1:
			Actor::playAnimation(this->actorStart, "0");
			Actor::playAnimation(this->actorCards, "10");
			Actor::playAnimation(this->actorMobile, "0");
			break;
		case 2:
			Actor::playAnimation(this->actorStart, "0");
			Actor::playAnimation(this->actorCards, "0");
			Actor::playAnimation(this->actorMobile, "10");
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
