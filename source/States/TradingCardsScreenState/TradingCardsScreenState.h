/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef TRADING_CARDS_SCREEN_STATE_H_
#define TRADING_CARDS_SCREEN_STATE_H_


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <SplashScreenState.h>


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

enum TradingCardsScreenModes
{
	kTradingCardsScreenModeShowCards,
	kTradingCardsScreenModeHighlightCard,
};


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class TradingCardsScreenState : SplashScreenState
{
	Entity entityBackground;
	Entity entityCursor;
	AnimatedEntity entityNumbers;
	AnimatedEntity entityCard1;
	AnimatedEntity entityCard2;
	AnimatedEntity entityCard3;
	AnimatedEntity entityCard4;
	AnimatedEntity entityCard5;
	AnimatedEntity entityCard6;
	AnimatedEntity entityCard7;
	AnimatedEntity entityCard8;
	AnimatedEntity entityLargeCard;
	uint8 page;
	uint8 card;
	uint8 mode;

	static TradingCardsScreenState getInstance();

	override void enter(void* owner);
	override void processUserInput(UserInput userInput);
}


#endif
