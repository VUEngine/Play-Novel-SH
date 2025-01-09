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
#include <Telegram.h>
#include <I18n.h>
#include <Languages.h>
#include <BodyManager.h>
#include <MobileScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <AutomaticPauseManager.h>
#include <TitleScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec MobileScreenStageSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void MobileScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}

void MobileScreenState::destructor()
{	// Always explicitly call the base's destructor 
	Base::destructor();
}

void MobileScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	// Load stage
	GameState::configureStage(GameState::safeCast(this), (StageSpec*)&MobileScreenStageSpec, NULL);

	// Set next state
	SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(TitleScreenState::getInstance()));

	// Start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// Disable user input
	VUEngine::disableKeypad();

	// Show prepare message
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileScreenMessageShowPrepare, 1, 0);

	// Show error message in 5 seconds
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileScreenMessageShowPrepare, 1, 0);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileScreenMessageShowError, CONNECTION_TIMEOUT, 0);

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

bool MobileScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kMobileScreenMessageShowPrepare:
			MobileScreenState::printPrepare(this);
			break;
		case kMobileScreenMessageShowError:
			MobileScreenState::printError(this);
			VUEngine::enableKeypad();
			break;
	}

	return true;
}

void MobileScreenState::printPrepare()
{
	const char* translations = I18n::getText(I18n::getInstance(), kStringMobilePrepareCommunication);
	Printing::text(translations, 0, 0, "Silent");
}

void MobileScreenState::printError()
{
	const char* translations = I18n::getText(I18n::getInstance(), kStringMobileError);
	Printing::clear();
	Printing::text(translations, 0, 0, "Silent");
}