/**
 * VUEngine Plugins Library
 *
 * (c) Christian Radke and Jorge Eremiev
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <VUEngine.h>
#include <Camera.h>
#include <SplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void SplashScreenState::constructor()
{
	Base::constructor();

	// init class members
	this->stageSpec = NULL;
	this->nextState = NULL;
}

void SplashScreenState::destructor()
{
	// destroy the super object
	// must always be called at the end of the destructor
	Base::destructor();
}

void SplashScreenState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	if(this->stageSpec)
	{
		SplashScreenState::loadStage(this, this->stageSpec, NULL, true, false);
	}

	SplashScreenState::print(this);
	SplashScreenState::startClocks(this);
	Camera::startEffect(Camera::getInstance(), kShow);
	VUEngine::enableKeypad(VUEngine::getInstance());
}

void SplashScreenState::exit(void* owner)
{
	// call base
	Base::exit(this, owner);

	// destroy the state
	delete this;
}

// state's suspend
void SplashScreenState::suspend(void* owner)
{
	if(!VUEngine::isEnteringSpecialMode(VUEngine::getInstance()))
	{
		Camera::startEffect(Camera::getInstance(), kHide);
	}

	// call base
	Base::suspend(this, owner);
}

// state's resume
void SplashScreenState::resume(void* owner)
{
	Base::resume(this, owner);

	SplashScreenState::print(this);

	if(!VUEngine::isExitingSpecialMode(VUEngine::getInstance()))
	{
		Camera::startEffect(Camera::getInstance(), kShow);
	}
}

bool SplashScreenState::processMessage(void* owner __attribute__ ((unused)), Telegram telegram __attribute__ ((unused)))
{
	return false;
}

void SplashScreenState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey & (K_STA | K_SEL | K_A | K_B))
	{
		SplashScreenState::loadNextState(this);
	}
}

void SplashScreenState::print()
{
}

void SplashScreenState::initNextState()
{
}

void SplashScreenState::setNextState(GameState nextState)
{
	this->nextState = nextState;
}

void SplashScreenState::loadNextState()
{
	Camera::startEffect(Camera::getInstance(), kHide);
	if(this->nextState == NULL)
	{
		SplashScreenState::initNextState(this);
	}
	VUEngine::changeState(VUEngine::getInstance(), this->nextState);
}
