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
#include <Camera.h>
#include <CameraEffectManager.h>
#include <PnSplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void PnSplashScreenState::constructor()
{
	Base::constructor();

	// init class members
	this->stageSpec = NULL;
	this->nextState = NULL;
}

void PnSplashScreenState::destructor()
{
	// destroy the super object
	// must always be called at the end of the destructor
	Base::destructor();
}

void PnSplashScreenState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	if(this->stageSpec)
	{
		PnSplashScreenState::configureStage(this, this->stageSpec, NULL);
	}

	PnSplashScreenState::print(this);
	PnSplashScreenState::startClocks(this);
	Camera::startEffect(Camera::getInstance(), kShow);
	VUEngine::enableKeypad(VUEngine::getInstance());
}

void PnSplashScreenState::exit(void* owner)
{
	// call base
	Base::exit(this, owner);

	// destroy the state
	delete this;
}

// state's suspend
void PnSplashScreenState::suspend(void* owner)
{
	Camera::startEffect(Camera::getInstance(), kHide);

	// call base
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

void PnSplashScreenState::initNextState()
{
}

void PnSplashScreenState::setNextState(GameState nextState)
{
	this->nextState = nextState;
}

void PnSplashScreenState::loadNextState()
{
	Camera::startEffect(Camera::getInstance(), kHide);
	if(this->nextState == NULL)
	{
		PnSplashScreenState::initNextState(this);
	}
	VUEngine::changeState(VUEngine::getInstance(), this->nextState);
}
