/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <VUEngine.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <PnSplashScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PnSplashScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	// Init class members
	this->stageSpec = NULL;
	this->nextState = NULL;
}

void PnSplashScreenState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

void PnSplashScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	if(this->stageSpec)
	{
		PnSplashScreenState::configureStage(this, this->stageSpec, NULL);
	}

	PnSplashScreenState::print(this);
	PnSplashScreenState::startClocks(this);
	Camera::startEffect(Camera::getInstance(), kShow);
	KeypadManager::enable();
}

void PnSplashScreenState::exit(void* owner)
{
	Base::exit(this, owner);

	// Destroy the state
	delete this;
}

// state's suspend
void PnSplashScreenState::suspend(void* owner)
{
	Camera::startEffect(Camera::getInstance(), kHide);

	Base::suspend(this, owner);
}

// state's resume
void PnSplashScreenState::resume(void* owner)
{
	Base::resume(this, owner);

	PnSplashScreenState::print(this);

	Camera::startEffect(Camera::getInstance(), kShow);
}

bool PnSplashScreenState::processMessage(void* owner __attribute__ ((unused)), Telegram telegram __attribute__ ((unused)))
{
	return false;
}

void PnSplashScreenState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey & (K_STA | K_SEL | K_A | K_B))
	{
		PnSplashScreenState::loadNextState(this);
	}
}

void PnSplashScreenState::print()
{
}
void PnSplashScreenState::setNextState(GameState nextState)
{
	this->nextState = nextState;
}

void PnSplashScreenState::loadNextState()
{
	Camera::startEffect(Camera::getInstance(), kHide);

	VUEngine::changeState(this->nextState);
}
