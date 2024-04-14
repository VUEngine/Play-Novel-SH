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
#include <Telegram.h>
#include <I18n.h>
#include <Languages.h>
#include <PhysicalWorld.h>
#include <MobileScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <AutomaticPauseManager.h>
#include <TitleScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec MobileScreenStageSpec;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void MobileScreenState::constructor()
{
	Base::constructor();
}

void MobileScreenState::destructor()
{
	Base::destructor();
}

void MobileScreenState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&MobileScreenStageSpec, NULL, true, false);

	// set next state
	SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(TitleScreenState::getInstance()));

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// disable user input
	VUEngine::disableKeypad(VUEngine::getInstance());

	// Show prepare message
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileScreenMessageShowPrepare, 1, 0);

	// Show error message in 5 seconds
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileScreenMessageShowPrepare, 1, 0);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kMobileScreenMessageShowError, CONNECTION_TIMEOUT, 0);

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

bool MobileScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kMobileScreenMessageShowPrepare:
			MobileScreenState::printPrepare(this);
			break;
		case kMobileScreenMessageShowError:
			MobileScreenState::printError(this);
			VUEngine::enableKeypad(VUEngine::getInstance());
			break;
	}

	return true;
}

void MobileScreenState::printPrepare()
{
	const char* translations = I18n::getText(I18n::getInstance(), kStringMobilePrepareCommunication);
	Printing::text(Printing::getInstance(), translations, 0, 0, "Silent");
}

void MobileScreenState::printError()
{
	const char* translations = I18n::getText(I18n::getInstance(), kStringMobileError);
	Printing::clear(Printing::getInstance());
	Printing::text(Printing::getInstance(), translations, 0, 0, "Silent");
}