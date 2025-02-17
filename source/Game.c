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
#include <I18n.h>
#include <GameSaveDataManager.h>
#include <TradingCardsManager.h>
#include <AutomaticPauseManager.h>
#include <PrecautionScreenState.h>
#include <AdjustmentScreenState.h>
#include <KCETScreenState.h>
#include <MobileSystemScreenState.h>
#include <KonamiScreenState.h>
#include <TitleScreenState.h>
#include <IntroScreenState.h>
#include <TradingCardsScreenState.h>
#include <MobileScreenState.h>
#include <LoadGameScreenState.h>
#include <ScenarioSelectScreenState.h>
#include <VisualNovelState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// GAME'S MAIN LOOP
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

GameState game(void)
{
	// Initialize plugins
	//AutomaticPauseManager::setAutomaticPauseState(AutomaticPauseManager::getInstance(), GameState::safeCast(AutomaticPauseScreenState::getInstance());
	//AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(), true);
	I18n::setActiveLanguage(I18n::getInstance(), GameSaveDataManager::getLanguage(GameSaveDataManager::getInstance()));
	
	TradingCardsManager::initialize(TradingCardsManager::getInstance());

	SplashScreenState::setNextState
	(
		SplashScreenState::safeCast(PrecautionScreenState::getInstance()),
		GameState::safeCast(AdjustmentScreenState::getInstance())
	);
	SplashScreenState::setNextState
	(
		SplashScreenState::safeCast(AdjustmentScreenState::getInstance()),
		GameState::safeCast(KonamiScreenState::getInstance())
	);

	// Start the game
	//return GameState::safeCast(VisualNovelState::getInstance());
	//return GameState::safeCast(ScenarioSelectScreenState::getInstance());
	//return GameState::safeCast(LoadGameScreenState::getInstance());
	//return GameState::safeCast(MobileScreenState::getInstance());
	//return GameState::safeCast(TradingCardsScreenState::getInstance());
	//return GameState::safeCast(TitleScreenState::getInstance());
	//return GameState::safeCast(IntroScreenState::getInstance());
	//return GameState::safeCast(MobileSystemScreenState::getInstance());
	//return GameState::safeCast(KCETScreenState::getInstance());
	//return GameState::safeCast(KonamiScreenState::getInstance());
	//return GameState::safeCast(AdjustmentScreenState::getInstance());
	return GameState::safeCast(PrecautionScreenState::getInstance());
}
