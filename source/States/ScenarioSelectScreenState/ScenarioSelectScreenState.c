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
#include <ScenarioSelectScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <AutomaticPauseManager.h>
#include <LoadGameScreenState.h>
#include <TradingCardsScreenState.h>
#include <VisualNovelState.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec ScenarioSelectScreenStageSpec;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void ScenarioSelectScreenState::constructor()
{
	Base::constructor();
}

void ScenarioSelectScreenState::destructor()
{
	Base::destructor();
}

void ScenarioSelectScreenState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::configureStage(GameState::safeCast(this), (StageSpec*)&ScenarioSelectScreenStageSpec, NULL);

	// set next state
	SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(VisualNovelState::getInstance()));

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// enable user input
	VUEngine::enableKeypad(VUEngine::getInstance());

	this->option = 0;

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

void ScenarioSelectScreenState::processUserInput(UserInput userInput)
{
	if((K_LL | K_RL | K_LR | K_RR) & userInput.pressedKey)
	{
		this->option = this->option == 0 ? 1 : 0;
	}
	else if((K_A | K_STA) & userInput.pressedKey)
	{
		ScenarioSelectScreenState::loadNextState(this);
	}
}
