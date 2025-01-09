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
#include <TradingCardsScreenState.h>
#include <Printing.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <AutomaticPauseManager.h>
#include <TradingCardsManager.h>
#include <TitleScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec TradingCardsScreenStageSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void TradingCardsScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}

void TradingCardsScreenState::destructor()
{	// Always explicitly call the base's destructor 
	Base::destructor();
}

void TradingCardsScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	// Load stage
	GameState::configureStage(GameState::safeCast(this), (StageSpec*)&TradingCardsScreenStageSpec, NULL);

	// Set next state
	SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(TitleScreenState::getInstance()));

	// Start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// Get actor references
	UIContainer uiContainer = VUEngine::getUIContainer();
	this->actorBackground = Actor::safeCast(UIContainer::getChildByName(uiContainer, "BG", true));
	this->actorCursor = Actor::safeCast(UIContainer::getChildByName(uiContainer, "CURSOR", true));
	this->actorNumbers = Actor::safeCast(UIContainer::getChildByName(uiContainer, "NUM", true));
	this->actorCard1 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "0", true));
	this->actorCard2 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "1", true));
	this->actorCard3 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "2", true));
	this->actorCard4 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "3", true));
	this->actorCard5 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "4", true));
	this->actorCard6 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "5", true));
	this->actorCard7 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "6", true));
	this->actorCard8 = Actor::safeCast(UIContainer::getChildByName(uiContainer, "7", true));
	this->actorLargeCard = Actor::safeCast(UIContainer::getChildByName(uiContainer, "CARD", true));

	// Initial selection
	this->page = 0;
	this->card = 0;
	this->mode = kTradingCardsScreenModeShowCards;
	TradingCardsScreenState::applyPage(this);
	TradingCardsScreenState::positionCursor(this);
	TradingCardsScreenState::applyMode(this);

	// Enable user input
	VUEngine::enableKeypad();

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

void TradingCardsScreenState::processUserInput(UserInput userInput)
{
	switch(this->mode)
	{
		case kTradingCardsScreenModeShowCards:
			return TradingCardsScreenState::processUserInputModeShowCards(this, userInput);
		case kTradingCardsScreenModeHighlightCard:
			return TradingCardsScreenState::processUserInputModeHighlightCard(this, userInput);
	}
}

void TradingCardsScreenState::processUserInputModeShowCards(UserInput userInput)
{
	if((K_LL | K_RL) & userInput.pressedKey)
	{
		if(this->card > 0)
		{
			this->card--;
			TradingCardsScreenState::positionCursor(this);
		}
	}
	else if((K_LR | K_RR) & userInput.pressedKey)
	{
		if(this->card < 7)
		{
			this->card++;
			TradingCardsScreenState::positionCursor(this);
		}
	}
	else if((K_LU | K_RU) & userInput.pressedKey)
	{
		if(this->card > 3)
		{
			this->card -= 4;
		}
		else
		{
			this->card += 4;
		}
		TradingCardsScreenState::positionCursor(this);
	}
	else if((K_LD | K_RD) & userInput.pressedKey)
	{
		if(this->card < 4)
		{
			this->card += 4;
		}
		else
		{
			this->card -= 4;
		}
		TradingCardsScreenState::positionCursor(this);
	}

	if(K_LT & userInput.pressedKey)
	{
		if(this->page > 0)
		{
			this->page--;
			TradingCardsScreenState::applyPage(this);
		}
	}

	if(K_RT & userInput.pressedKey)
	{
		if(this->page < 3)
		{
			this->page++;
			TradingCardsScreenState::applyPage(this);
		}
	}

	if(K_A & userInput.pressedKey)
	{
		if(TradingCardsManager::getCardUnlocked(TradingCardsManager::getInstance(), (this->page << 3) + this->card))
		{
			this->mode = kTradingCardsScreenModeHighlightCard;
			TradingCardsScreenState::applyMode(this);
		}
	}

	if(K_B & userInput.pressedKey)
	{
		SplashScreenState::loadNextState(SplashScreenState::safeCast(this));
	}
}

void TradingCardsScreenState::processUserInputModeHighlightCard(UserInput userInput)
{
	if(K_B & userInput.pressedKey)
	{
		this->mode = kTradingCardsScreenModeShowCards;
		TradingCardsScreenState::applyMode(this);
	}
}

void TradingCardsScreenState::positionCursor()
{
	Vector3D position =
	{
		__PIXELS_TO_METERS(-64 + ((this->card % 4) * 48)),
		__PIXELS_TO_METERS(this->card < 4 ? -24 : 40),
		__PIXELS_TO_METERS(-4),
	};
	Actor::setLocalPosition(Actor::safeCast(this->actorCursor), &position);
}

void TradingCardsScreenState::applyMode()
{
	switch(this->mode)
	{
		case kTradingCardsScreenModeShowCards:
		{
			Actor::hide(Actor::safeCast(this->actorLargeCard));
			Actor::show(Actor::safeCast(this->actorBackground));
			Actor::show(Actor::safeCast(this->actorNumbers));
			Actor::show(Actor::safeCast(this->actorCard1));
			Actor::show(Actor::safeCast(this->actorCard2));
			Actor::show(Actor::safeCast(this->actorCard3));
			Actor::show(Actor::safeCast(this->actorCard4));
			Actor::show(Actor::safeCast(this->actorCard5));
			Actor::show(Actor::safeCast(this->actorCard6));
			Actor::show(Actor::safeCast(this->actorCard7));
			Actor::show(Actor::safeCast(this->actorCard8));
			Actor::show(this->actorCursor);
			TradingCardsScreenState::applyPage(this);
			Printing::clear();
			break;
		}
		case kTradingCardsScreenModeHighlightCard:
		{
			uint8 cardNumber = (this->page << 3) + this->card;
			Actor::hide(Actor::safeCast(this->actorBackground));
			Actor::hide(this->actorCursor);
			Actor::hide(Actor::safeCast(this->actorNumbers));
			Actor::hide(Actor::safeCast(this->actorCard1));
			Actor::hide(Actor::safeCast(this->actorCard2));
			Actor::hide(Actor::safeCast(this->actorCard3));
			Actor::hide(Actor::safeCast(this->actorCard4));
			Actor::hide(Actor::safeCast(this->actorCard5));
			Actor::hide(Actor::safeCast(this->actorCard6));
			Actor::hide(Actor::safeCast(this->actorCard7));
			Actor::hide(Actor::safeCast(this->actorCard8));
			Actor::playAnimation(this->actorLargeCard, Utilities::itoa(cardNumber, 10, 1));

			const char* translation = I18n::getText(I18n::getInstance(), kStringTradingCard01Title + cardNumber);
			FontSize translationTextSize = Printing::getTextSize(translation, "Silent");
			Printing::text(translation, ((__HALF_SCREEN_WIDTH_IN_CHARS) - (translationTextSize.x >> 1)), 23, "Silent");
			Printing::int32(cardNumber + 1, cardNumber < 9 ? 24 : 23, 25, "Silent");
			Actor::show(Actor::safeCast(this->actorLargeCard));
			break;
		}
	}
}

void TradingCardsScreenState::applyPage()
{
	Actor::playAnimation(this->actorNumbers, Utilities::itoa(this->page, 10, 1));

	uint8 pageBase = this->page << 3;
	Actor::playAnimation(this->actorCard1, Utilities::itoa(pageBase + 0, 10, 1));
	Actor::playAnimation(this->actorCard2, Utilities::itoa(pageBase + 1, 10, 1));
	Actor::playAnimation(this->actorCard3, Utilities::itoa(pageBase + 2, 10, 1));
	Actor::playAnimation(this->actorCard4, Utilities::itoa(pageBase + 3, 10, 1));
	Actor::playAnimation(this->actorCard5, Utilities::itoa(pageBase + 4, 10, 1));
	Actor::playAnimation(this->actorCard6, Utilities::itoa(pageBase + 5, 10, 1));
	Actor::playAnimation(this->actorCard7, Utilities::itoa(pageBase + 6, 10, 1));
	Actor::playAnimation(this->actorCard8, Utilities::itoa(pageBase + 7, 10, 1));

	TradingCardsManager tradingCardsManager = TradingCardsManager::getInstance();
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 0))
	{
		Actor::show(Actor::safeCast(this->actorCard1));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard1));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 1))
	{
		Actor::show(Actor::safeCast(this->actorCard2));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard2));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 2))
	{
		Actor::show(Actor::safeCast(this->actorCard3));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard3));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 3))
	{
		Actor::show(Actor::safeCast(this->actorCard4));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard4));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 4))
	{
		Actor::show(Actor::safeCast(this->actorCard5));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard5));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 5))
	{
		Actor::show(Actor::safeCast(this->actorCard6));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard6));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 6))
	{
		Actor::show(Actor::safeCast(this->actorCard7));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard7));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 7))
	{
		Actor::show(Actor::safeCast(this->actorCard8));
	}
	else
	{
		Actor::hide(Actor::safeCast(this->actorCard8));
	}

}
