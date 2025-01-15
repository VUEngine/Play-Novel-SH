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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// GAME'S MAIN LOOP
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

int32 game(void)
{
	// Initialize plugins
	//AutomaticPauseManager::setAutomaticPauseState(AutomaticPauseManager::getInstance(), GameState::safeCast(AutomaticPauseScreenState::getInstance()));
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
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(VisualNovelState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(ScenarioSelectScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(LoadGameScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(MobileScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(TradingCardsScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(TitleScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(IntroScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(MobileSystemScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(KCETScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(KonamiScreenState::getInstance()));
	//return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(AdjustmentScreenState::getInstance()));
	return VUEngine::start(VUEngine::getInstance(), GameState::safeCast(PrecautionScreenState::getInstance()));
}
