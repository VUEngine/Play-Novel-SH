/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <VUEngine.h>
#include <Utilities.h>
#include <AnimatedEntity.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <MessageDispatcher.h>
#include <I18n.h>
#include <Languages.h>
#include <PhysicalWorld.h>
#include <LoadGameScreenState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <Telegram.h>
#include <VirtualList.h>
#include <AutomaticPauseManager.h>
#include <ScenarioSelectScreenState.h>
#include <VisualNovelState.h>
#include <Printing.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec LoadGameScreenStageSpec;
extern Script PlayNovelScenarios;
extern GameProgress EmptyProgress;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void LoadGameScreenState::constructor()
{
	Base::constructor();
}

void LoadGameScreenState::destructor()
{
	Base::destructor();
}

void LoadGameScreenState::enter(void* owner)
{
	Base::enter(this, owner);

	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&LoadGameScreenStageSpec, NULL, true, false);
	SplashScreenState::setNextState(SplashScreenState::safeCast(this), GameState::safeCast(ScenarioSelectScreenState::getInstance()));

	GameState::startClocks(GameState::safeCast(this));

	Printing::setWorldCoordinates(Printing::getInstance(), 0, 2, -4, -1);

	UIContainer uiContainer = VUEngine::getUIContainer(VUEngine::getInstance());
	this->entityCursor = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "CURSOR", true));
	this->entitySubChapterBackground = Entity::safeCast(UIContainer::getChildByName(uiContainer, "SUBCHPTR", true));
	this->entitySlot[0] = Entity::safeCast(UIContainer::getChildByName(uiContainer, "SLOT0", true));
	this->entitySlot[1] = Entity::safeCast(UIContainer::getChildByName(uiContainer, "SLOT1", true));
	this->entitySlot[2] = Entity::safeCast(UIContainer::getChildByName(uiContainer, "SLOT2", true));
	this->entitySlotLabel[0] = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "LABEL0", true));
	this->entitySlotLabel[1] = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "LABEL1", true));
	this->entitySlotLabel[2] = AnimatedEntity::safeCast(UIContainer::getChildByName(uiContainer, "LABEL2", true));

	this->slot = 0;
	this->slotMenuOption = 0;
	this->mode = kLoadGameScreenModeSelectSlot;
	LoadGameScreenState::positionCursor(this);

	Entity::hide(this->entitySubChapterBackground);

	LoadGameScreenState::loadProgress(this);
	LoadGameScreenState::printSlotsInfo(this);

	VUEngine::disableKeypad(VUEngine::getInstance());
	Camera::startEffect(Camera::getInstance(), kHide);
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kLoadGameScreenMessageShowScreen, 1900, 0);


//	VUEngine::enableKeypad(VUEngine::getInstance());
//	Camera::startEffect(Camera::getInstance(), kShow);
}

void LoadGameScreenState::execute(void* owner)
{
	Base::execute(this, owner);

	switch(this->mode) {
		case kLoadGameScreenModeMoveSelectedSlot:
			return LoadGameScreenState::executeMoveSelectedSlot(this, owner);
	}
}

void LoadGameScreenState::executeMoveSelectedSlot(void* owner __attribute__ ((unused)))
{
	Vector3D slotPosition = *Entity::getPosition(this->entitySlot[this->slot]);
	Vector3D slotLabelPosition = *Entity::getPosition(this->entitySlotLabel[this->slot]);
	if(slotPosition.y > __PIXELS_TO_METERS(64))
	{
		slotPosition.y -= __PIXELS_TO_METERS(2);
		Entity::setPosition(this->entitySlot[this->slot], &slotPosition);
		slotLabelPosition.y -= __PIXELS_TO_METERS(2);
		Entity::setPosition(this->entitySlotLabel[this->slot], &slotLabelPosition);
	}
	else
	{
		ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kLoadGameScreenMessageShowSlot, 10, 0);
	}
}

void LoadGameScreenState::processUserInput(UserInput userInput)
{
	switch(this->mode) {
		case kLoadGameScreenModeSelectSlot:
			return LoadGameScreenState::processUserInputSelectSlot(this, userInput);
		case kLoadGameScreenModeShowSlot:
			return LoadGameScreenState::processUserInputShowSlot(this, userInput);
		case kLoadGameScreenModeConfirmSlot:
			return LoadGameScreenState::processUserInputConfirmSlot(this, userInput);
			return;
	}
}

void LoadGameScreenState::processUserInputSelectSlot(UserInput userInput)
{
	if((K_LU | K_RU) & userInput.pressedKey)
	{
		this->slot = (this->slot > 0) ? this->slot - 1 : 2;
		LoadGameScreenState::positionCursor(this);
	}
	else if((K_LD | K_RD) & userInput.pressedKey)
	{
		this->slot = (this->slot < 2) ? this->slot + 1 : 0;
		LoadGameScreenState::positionCursor(this);
	}
	else if((K_A | K_STA) & userInput.releasedKey)
	{
		LoadGameScreenState::selectSlot(this);
	}
}

void LoadGameScreenState::processUserInputShowSlot(UserInput userInput)
{
	if((K_LU | K_RU) & userInput.pressedKey)
	{
		this->slotMenuOption = kLoadGameScreenSlotOptionContinue;
		OptionsSelector::setSelectedOption(this->slotMenu, this->slotMenuOption);
	}
	else if((K_LD | K_RD) & userInput.pressedKey)
	{
		this->slotMenuOption = kLoadGameScreenSlotOptionNewGame;
		OptionsSelector::setSelectedOption(this->slotMenu, this->slotMenuOption);
	}
	else if((K_A | K_STA) & userInput.releasedKey)
	{
		switch(this->slotMenuOption) 
		{
			case kLoadGameScreenSlotOptionContinue:
				LoadGameScreenState::startSlot(this);
				break;
			case kLoadGameScreenSlotOptionNewGame:
				LoadGameScreenState::showDeleteSlot(this);
				break;
		}
	}
}

void LoadGameScreenState::processUserInputConfirmSlot(UserInput userInput)
{
	if((K_LU | K_RU) & userInput.pressedKey)
	{
		this->slotMenuOption = kLoadGameScreenSlotOptionYes;
		OptionsSelector::setSelectedOption(this->slotMenu, this->slotMenuOption);
	}
	else if((K_LD | K_RD) & userInput.pressedKey)
	{
		this->slotMenuOption = kLoadGameScreenSlotOptionNo;
		OptionsSelector::setSelectedOption(this->slotMenu, this->slotMenuOption);
	}
	else if((K_A | K_STA) & userInput.releasedKey)
	{
		switch(this->slotMenuOption) 
		{
			case kLoadGameScreenSlotOptionYes:
				LoadGameScreenState::clearProgress(this);
				LoadGameScreenState::startSlot(this);
				break;
			case kLoadGameScreenSlotOptionNo:
				LoadGameScreenState::showSlot(this);
				break;
		}
	}
}

void LoadGameScreenState::positionCursor()
{
	Vector3D position =
	{
		__PIXELS_TO_METERS(0),
		__PIXELS_TO_METERS(-48 + this->slot * 48),
		__PIXELS_TO_METERS(0),
	};
	Entity::setLocalPosition(this->entityCursor, &position);
}

bool LoadGameScreenState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kLoadGameScreenMessageShowScreen:
		{
			VUEngine::enableKeypad(VUEngine::getInstance());
			Camera::startEffect(Camera::getInstance(),
				kFadeTo, // effect type
				0, // initial delay (in ms)
				NULL, // target brightness
				__FADE_DELAY, // delay between fading steps (in ms)
				NULL, // callback function
				NULL // callback scope
			);

			break;
		}
		case kLoadGameScreenMessageShowSlot:
		{
			LoadGameScreenState::showSlot(this);
			break;
		}
	}

	return true;
}

void LoadGameScreenState::loadProgress()
{

	for(uint8 slot = 0; slot < NUMBER_OF_SAVE_SLOTS; slot++) 
	{
		GameSaveDataManager::getValue(
			GameSaveDataManager::getInstance(), 
			(BYTE*)&this->progress[slot],
			offsetof(struct GameSaveData, gameProgress) + slot * sizeof(this->progress[slot]), 
			sizeof(this->progress[slot])
		);
	}
}

void LoadGameScreenState::clearProgress()
{
	GameSaveDataManager::setValue(
		GameSaveDataManager::getInstance(), 
		(BYTE*)&EmptyProgress, 
		offsetof(struct GameSaveData, gameProgress) + this->slot * sizeof(EmptyProgress), 
		sizeof(EmptyProgress)
	);
}

void LoadGameScreenState::printSlotsInfo()
{
	uint16 language = I18n::getActiveLanguage(I18n::getInstance());
	
	for(uint8 slot = 0; slot < NUMBER_OF_SAVE_SLOTS; slot++) 
	{
		if(this->progress[slot].started) {
			AnimatedEntity::playAnimation(this->entitySlotLabel[slot], Utilities::itoa(this->progress[slot].scenario, 10, 1));
			LoadGameScreenState::printSlotInfo(this, slot, 6 + slot * 6, false);
		}
		else
		{
			AnimatedEntity::playAnimation(this->entitySlotLabel[slot], language == 1 ? "EmptyDE" : "EmptyEN");
		}
	}
}

void LoadGameScreenState::printSlotInfo(uint8 slot, int8 yPos, bool withSubChapter)
{
	Printing::setPalette(Printing::getInstance(), 1);
	uint16 language = I18n::getActiveLanguage(I18n::getInstance());

	char* actTitle = PlayNovelScenarios.scenarios[this->progress[slot].scenario]->acts[this->progress[slot].act]->title[language];
	FontSize actTitleTextSize = Printing::getTextSize(Printing::getInstance(), actTitle, "Silent");
	Printing::text(Printing::getInstance(), actTitle, 43 - actTitleTextSize.x, yPos, "Silent");

	char* chapterTitle = PlayNovelScenarios.scenarios[this->progress[slot].scenario]->acts[this->progress[slot].act]->chapters[this->progress[slot].chapter]->title[language];
	FontSize chapterTitleTextSize = Printing::getTextSize(Printing::getInstance(), chapterTitle, "Silent");
	Printing::text(Printing::getInstance(), "\"", 41 - chapterTitleTextSize.x, yPos + 2, "Silent");
	Printing::text(Printing::getInstance(), "\"", 42, yPos + 2, "Silent");
	Printing::text(Printing::getInstance(), chapterTitle, 42 - chapterTitleTextSize.x, yPos + 2, "Silent");

	if(withSubChapter)
	{
		char* subChapterTitle = PlayNovelScenarios.scenarios[this->progress[slot].scenario]
			->acts[this->progress[slot].act]
			->chapters[this->progress[slot].chapter]
			->subChapters[this->progress[slot].subChapter]
			->title[language];
		FontSize subChapterTitleTextSize = Printing::getTextSize(Printing::getInstance(), subChapterTitle, "Silent");
		Printing::text(Printing::getInstance(), "\"", 41 - subChapterTitleTextSize.x, yPos + 6, "Silent");
		Printing::text(Printing::getInstance(), "\"", 42, yPos + 6, "Silent");
		Printing::text(Printing::getInstance(), subChapterTitle, 42 - subChapterTitleTextSize.x, yPos + 6, "Silent");
	}
}

void LoadGameScreenState::selectSlot() 
{
	VUEngine::disableKeypad(VUEngine::getInstance());
	if(this->progress[this->slot].started) 
	{
		Entity::hide(this->entityCursor);
		Printing::clear(Printing::getInstance());
		for(uint8 slot = 0; slot < NUMBER_OF_SAVE_SLOTS; slot++) 
		{
			if(this->slot != slot)
			{
				Entity::hide(this->entitySlot[slot]);
				Entity::hide(this->entitySlotLabel[slot]);
			}
		}

		if(this->slot == 0)
		{
			LoadGameScreenState::showSlot(this);
		}
		else
		{
			this->mode = kLoadGameScreenModeMoveSelectedSlot;
		}
	}
	else 
	{
		LoadGameScreenState::startSlot(this);
	}
}

void LoadGameScreenState::clearMenu() 
{
	for(uint8 i = 14; i < 28; i++)
	{
		Printing::text(Printing::getInstance(), "                                                ", 0, i, "Silent");
	}
}

void LoadGameScreenState::showSlot() 
{
	VUEngine::enableKeypad(VUEngine::getInstance());
	this->mode = kLoadGameScreenModeShowSlot;
	Entity::show(this->entitySubChapterBackground);
	LoadGameScreenState::printSlotInfo(this, this->slot, 6, true);
	LoadGameScreenState::printSlotMenu(this);
}

void LoadGameScreenState::showDeleteSlot() 
{
	this->mode = kLoadGameScreenModeConfirmSlot;
	LoadGameScreenState::printDeleteMenu(this);
}

void LoadGameScreenState::printSlotMenu() 
{
	Printing::setPalette(Printing::getInstance(), 0);
	LoadGameScreenState::clearMenu(this);
	VirtualList options = new VirtualList();

	const char* optionContinueText = I18n::getText(I18n::getInstance(), kStringContinue);
	Option* optionContinue = new Option;
	optionContinue->value = (char*)optionContinueText;
	optionContinue->type = kString;
	VirtualList::pushBack(options, optionContinue);

	const char* optionNewGameText = I18n::getText(I18n::getInstance(), kStringNewGame);
	Option* optionNewGame = new Option;
	optionNewGame->value = (char*)optionNewGameText;
	optionNewGame->type = kString;
	VirtualList::pushBack(options, optionNewGame);

	this->slotMenu = new OptionsSelector(1, 2, "Silent", "*", NULL);
	OptionsSelector::setOptions(this->slotMenu, options);
	delete options;
	this->slotMenuOption = 0;
	OptionsSelector::setSelectedOption(this->slotMenu, this->slotMenuOption);
	OptionsSelector::setColumnWidth(this->slotMenu, 8);
	OptionsSelector::printOptions(this->slotMenu, 20, 20, kOptionsAlignLeft, 0);
}

void LoadGameScreenState::printDeleteMenu() 
{
	Printing::setPalette(Printing::getInstance(), 0);
	LoadGameScreenState::clearMenu(this);

	const char* deleteDataText = I18n::getText(I18n::getInstance(), kStringDeleteData);
	FontSize deleteDataTextFontSize = Printing::getTextSize(Printing::getInstance(), deleteDataText, "Silent");
	Printing::text(Printing::getInstance(), deleteDataText, (__HALF_SCREEN_WIDTH_IN_CHARS) - (deleteDataTextFontSize.x >> 1), 17, "Silent");

	VirtualList options = new VirtualList();

	const char* optionYesText = I18n::getText(I18n::getInstance(), kStringYes);
	Option* optionYes = new Option;
	optionYes->value = (char*)optionYesText;
	optionYes->type = kString;
	VirtualList::pushBack(options, optionYes);

	const char* optionNoText = I18n::getText(I18n::getInstance(), kStringNo);
	Option* optionNo = new Option;
	optionNo->value = (char*)optionNoText;
	optionNo->type = kString;
	VirtualList::pushBack(options, optionNo);
	
	this->slotMenu = new OptionsSelector(1, 2, "Silent", "*", NULL);
	OptionsSelector::setOptions(this->slotMenu, options);
	delete options;
	this->slotMenuOption = 0;
	OptionsSelector::setSelectedOption(this->slotMenu, this->slotMenuOption);
	OptionsSelector::setColumnWidth(this->slotMenu, 8);
	OptionsSelector::printOptions(this->slotMenu, 20, 20, kOptionsAlignLeft, 0);
}

void LoadGameScreenState::startSlot() 
{
	VisualNovelState::setSaveSlot(VisualNovelState::getInstance(), this->slot);
	TitleScreenState::loadNextState(this);
}