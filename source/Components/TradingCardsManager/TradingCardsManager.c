/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */



//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————


#include <stddef.h>
#include <Utilities.h>
#include <TradingCardsManager.h>
#include <GameSaveDataManager.h>



//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————


// class's constructor
void TradingCardsManager::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}

// class's destructor
void TradingCardsManager::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

void TradingCardsManager::initialize()
{
	TradingCardsManager::loadUnlockedCards(this);
}

void TradingCardsManager::loadUnlockedCards()
{
	GameSaveDataManager::getValue(GameSaveDataManager::getInstance(), (BYTE*)&this->unlockedCards, offsetof(struct GameSaveData, unlockedCards), sizeof(this->unlockedCards));
}

void TradingCardsManager::saveUnlockedCards()
{
	GameSaveDataManager::setValue(GameSaveDataManager::getInstance(), (BYTE*)&this->unlockedCards, offsetof(struct GameSaveData, unlockedCards), sizeof(this->unlockedCards));
}

bool TradingCardsManager::getCardUnlocked(uint8 index)
{
	return GET_BIT(this->unlockedCards, index);
}

void TradingCardsManager::setCardUnlocked(uint8 index)
{
	SET_BIT(this->unlockedCards, index);
	TradingCardsManager::saveUnlockedCards(this);
}
