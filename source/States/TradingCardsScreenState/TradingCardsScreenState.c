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
#include <TradingCardsScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <DebugUtilities.h>
#include <AutomaticPauseManager.h>
#include <TradingCardsManager.h>
#include <TitleScreenState.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec TradingCardsScreenStageSpec;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void TradingCardsScreenState::constructor()
{
	Base::constructor();
}

void TradingCardsScreenState::destructor()
{
	Base::destructor();
}

void TradingCardsScreenState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&TradingCardsScreenStageSpec, NULL, true, false);

	// set next state
	SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(TitleScreenState::getInstance()));

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// get entity references
	UIContainer uiContainer = Stage::getUIContainer(VUEngine::getStage(VUEngine::getInstance()));
	this->entityBackground = Entity::safeCast(UIContainer::getChildByName(uiContainer, "BG", true));
	this->entityCursor = Entity::safeCast(UIContainer::getChildByName(uiContainer, "CURSOR", true));
	this->entityNumbers = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "NUM", true));
	this->entityCard1 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "0", true));
	this->entityCard2 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "1", true));
	this->entityCard3 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "2", true));
	this->entityCard4 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "3", true));
	this->entityCard5 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "4", true));
	this->entityCard6 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "5", true));
	this->entityCard7 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "6", true));
	this->entityCard8 = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "7", true));
	this->entityLargeCard = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "CARD", true));

	// initial selection
	this->page = 0;
	this->card = 0;
	this->mode = kTradingCardsScreenModeShowCards;
	TradingCardsScreenState::applyPage(this);
	TradingCardsScreenState::positionCursor(this);
	TradingCardsScreenState::applyMode(this);

	// enable user input
	VUEngine::enableKeypad(VUEngine::getInstance());

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
	Entity::setLocalPosition(Entity::safeCast(this->entityCursor), &position);
}

void TradingCardsScreenState::applyMode()
{
	switch(this->mode)
	{
		case kTradingCardsScreenModeShowCards:
		{
			Entity::hide(Entity::safeCast(this->entityLargeCard));
			Entity::show(Entity::safeCast(this->entityBackground));
			Entity::show(Entity::safeCast(this->entityNumbers));
			Entity::show(Entity::safeCast(this->entityCard1));
			Entity::show(Entity::safeCast(this->entityCard2));
			Entity::show(Entity::safeCast(this->entityCard3));
			Entity::show(Entity::safeCast(this->entityCard4));
			Entity::show(Entity::safeCast(this->entityCard5));
			Entity::show(Entity::safeCast(this->entityCard6));
			Entity::show(Entity::safeCast(this->entityCard7));
			Entity::show(Entity::safeCast(this->entityCard8));
			Entity::show(this->entityCursor);
			TradingCardsScreenState::applyPage(this);
			Printing::clear(Printing::getInstance());
			break;
		}
		case kTradingCardsScreenModeHighlightCard:
		{
			uint8 cardNumber = (this->page << 3) + this->card;
			Entity::hide(Entity::safeCast(this->entityBackground));
			Entity::hide(this->entityCursor);
			Entity::hide(Entity::safeCast(this->entityNumbers));
			Entity::hide(Entity::safeCast(this->entityCard1));
			Entity::hide(Entity::safeCast(this->entityCard2));
			Entity::hide(Entity::safeCast(this->entityCard3));
			Entity::hide(Entity::safeCast(this->entityCard4));
			Entity::hide(Entity::safeCast(this->entityCard5));
			Entity::hide(Entity::safeCast(this->entityCard6));
			Entity::hide(Entity::safeCast(this->entityCard7));
			Entity::hide(Entity::safeCast(this->entityCard8));
			AnimatedEntity::playAnimation(this->entityLargeCard, Utilities::itoa(cardNumber, 10, 1));

			const char* translation = I18n::getText(I18n::getInstance(), kStringTradingCard01Title + cardNumber);
			FontSize translationTextSize = Printing::getTextSize(Printing::getInstance(), translation, "Silent");
			Printing::text(Printing::getInstance(), translation, ((__HALF_SCREEN_WIDTH_IN_CHARS) - (translationTextSize.x >> 1)), 23, "Silent");
			Printing::int32(Printing::getInstance(), cardNumber + 1, cardNumber < 9 ? 24 : 23, 25, "Silent");
			Entity::show(Entity::safeCast(this->entityLargeCard));
			break;
		}
	}
}

void TradingCardsScreenState::applyPage()
{
	AnimatedEntity::playAnimation(this->entityNumbers, Utilities::itoa(this->page, 10, 1));

	uint8 pageBase = this->page << 3;
	AnimatedEntity::playAnimation(this->entityCard1, Utilities::itoa(pageBase + 0, 10, 1));
	AnimatedEntity::playAnimation(this->entityCard2, Utilities::itoa(pageBase + 1, 10, 1));
	AnimatedEntity::playAnimation(this->entityCard3, Utilities::itoa(pageBase + 2, 10, 1));
	AnimatedEntity::playAnimation(this->entityCard4, Utilities::itoa(pageBase + 3, 10, 1));
	AnimatedEntity::playAnimation(this->entityCard5, Utilities::itoa(pageBase + 4, 10, 1));
	AnimatedEntity::playAnimation(this->entityCard6, Utilities::itoa(pageBase + 5, 10, 1));
	AnimatedEntity::playAnimation(this->entityCard7, Utilities::itoa(pageBase + 6, 10, 1));
	AnimatedEntity::playAnimation(this->entityCard8, Utilities::itoa(pageBase + 7, 10, 1));

	TradingCardsManager tradingCardsManager = TradingCardsManager::getInstance();
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 0))
	{
		Entity::show(Entity::safeCast(this->entityCard1));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard1));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 1))
	{
		Entity::show(Entity::safeCast(this->entityCard2));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard2));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 2))
	{
		Entity::show(Entity::safeCast(this->entityCard3));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard3));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 3))
	{
		Entity::show(Entity::safeCast(this->entityCard4));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard4));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 4))
	{
		Entity::show(Entity::safeCast(this->entityCard5));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard5));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 5))
	{
		Entity::show(Entity::safeCast(this->entityCard6));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard6));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 6))
	{
		Entity::show(Entity::safeCast(this->entityCard7));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard7));
	}
	
	if(TradingCardsManager::getCardUnlocked(tradingCardsManager, pageBase + 7))
	{
		Entity::show(Entity::safeCast(this->entityCard8));
	}
	else
	{
		Entity::hide(Entity::safeCast(this->entityCard8));
	}

}
