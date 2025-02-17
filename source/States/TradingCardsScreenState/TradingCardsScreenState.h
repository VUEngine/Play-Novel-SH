/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef TRADING_CARDS_SCREEN_STATE_H_
#define TRADING_CARDS_SCREEN_STATE_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <SplashScreenState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

enum TradingCardsScreenModes
{
	kTradingCardsScreenModeShowCards,
	kTradingCardsScreenModeHighlightCard,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

singleton class TradingCardsScreenState : SplashScreenState
{
	Actor actorBackground;
	Actor actorCursor;
	Actor actorNumbers;
	Actor actorCard1;
	Actor actorCard2;
	Actor actorCard3;
	Actor actorCard4;
	Actor actorCard5;
	Actor actorCard6;
	Actor actorCard7;
	Actor actorCard8;
	Actor actorLargeCard;
	uint8 page;
	uint8 card;
	uint8 mode;

	static TradingCardsScreenState getInstance();

	override void enter(void* owner);
	override void processUserInput(UserInput userInput);
}

#endif
