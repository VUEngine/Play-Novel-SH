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
#include <MessageDispatcher.h>
#include <I18n.h>
#include <Languages.h>
#include <PhysicalWorld.h>
#include <LoadGameScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <GameEvents.h>
#include <debugUtilities.h>
#include <AutomaticPauseManager.h>
#include <GameEvents.h>
#include <ScenarioSelectScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec LoadGameScreenStageSpec;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void LoadGameScreenState::constructor()
{
	Base::constructor();
}

void LoadGameScreenState::destructor()
{
	Base::destructor();
}

void LoadGameScreenState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&LoadGameScreenStageSpec, NULL, true, false);

	// set next state
	SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(ScenarioSelectScreenState::getInstance()));

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	this->entityCursor = Entity::safeCast(Container::getChildByName(Container::safeCast(VUEngine::getStage(VUEngine::getInstance())), "CURSOR", true));
	this->option = 0;
	LoadGameScreenState::positionCursor(this);

	VUEngine::disableKeypad(VUEngine::getInstance());
	Camera::startEffect(Camera::getInstance(), kHide);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kLoadGameScreenMessageShow, 1900, 0);
}

void LoadGameScreenState::processUserInput(UserInput userInput)
{
	if((K_LU | K_RU) & userInput.pressedKey)
	{
		this->option = (this->option > 0) ? this->option - 1 : 2;
		LoadGameScreenState::positionCursor(this);
	}
	else if((K_LD | K_RD) & userInput.pressedKey)
	{
		this->option = (this->option < 2) ? this->option + 1 : 0;
		LoadGameScreenState::positionCursor(this);
	}
	else if((K_A | K_STA) & userInput.pressedKey)
	{
		TitleScreenState::loadNextState(this);
	}
}

void LoadGameScreenState::positionCursor()
{
	Vector3D position =
	{
		__PIXELS_TO_METERS(192),
		__PIXELS_TO_METERS(64 + this->option * 48),
		__PIXELS_TO_METERS(0),
	};
	Entity::setLocalPosition(this->entityCursor, &position);
}

bool LoadGameScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kLoadGameScreenMessageShow:
		{
			VUEngine::enableKeypad(VUEngine::getInstance());
			Camera::startEffect(Camera::getInstance(),
				kFadeTo, // effect type
				0, // initial delay (in ms)
				NULL, // target brightness
				__FADE_DELAY, // delay between fading steps (in ms)
				NULL, // callback function
				NULL // callback scope
			);

			break;
		}
	}

	return true;
}