/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <string.h>
#include <VUEngine.h>
#include <Utilities.h>
#include <Actor.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <MessageDispatcher.h>
#include <I18n.h>
#include <Languages.h>
#include <Telegram.h>
#include <BodyManager.h>
#include <VisualNovelState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <Printing.h>
#include <AutomaticPauseManager.h>
#include <GameSaveDataManager.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec VisualNovelStageSpec;
extern Script PlayNovelScenarios;
extern ActorSpec DummyContainerActorSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VisualNovelState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	this->saveSlot = 0;
}

void VisualNovelState::destructor()
{	// Always explicitly call the base's destructor 
	Base::destructor();
}

void VisualNovelState::enter(void* owner)
{
	Base::enter(this, owner);

	// Load stage
	GameState::configureStage(GameState::safeCast(this), (StageSpec*)&VisualNovelStageSpec, NULL);

	// Start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// Optimize printing layer to save performance
	Printing::setWorldCoordinates(16, 172, -6, 0);
	Printing::setPalette(0);

	// Initialize variables
	UIContainer uiContainer = VUEngine::getUIContainer();
	this->actorFlauros = Actor::safeCast(UIContainer::getChildByName(uiContainer, "FLAUROS", true));
	this->charNumber = 0;
	this->charX = 0;
	this->charY = 0;
	this->text = "";
	this->textLength = 0;
	this->pageFinished = false;
	this->language = I18n::getActiveLanguage(I18n::getInstance());
	this->choicesMenuOption = 0;
	this->choicesMenuOptionCount = 0;

	// Load progress, always start at page 0
	VisualNovelState::loadProgress(this);
	this->progress.page = 0;
	this->progress.started = true;

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

	// Start scene
	VisualNovelState::setUpScene(this);
	VisualNovelState::setUpPage(this);
	VisualNovelState::showPage(this);
}

void VisualNovelState::execute(void* owner)
{
	Base::execute(this, owner);

	/*
	Printing::int32(this->progress.act, 0, 5, "Silent");
	Printing::int32(this->progress.chapter, 3, 5, "Silent");
	Printing::int32(this->progress.subChapter, 6, 5, "Silent");
	Printing::int32(this->progress.scene, 9, 5, "Silent");
	Printing::int32(this->progress.page, 12, 5, "Silent");
	*/
}

bool VisualNovelState::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kVisualNovelMessagePrintChar:
		{
			if(this->charNumber < this->textLength)
			{
				VisualNovelState::printCharacter(this);
			}
			else
			{
				VisualNovelState::finishPage(this);
			}
			break;
		}
		case kVisualNovelMessageStartPage:
		{
			VisualNovelState::startPage(this);
			break;
		}
	}

	return true;
}

void VisualNovelState::nextPage()
{
	const struct BranchingTargets *branchingTargets = PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene]
		->branchingTargets;

	if (this->choicesMenuOptionCount > 0) {
		const struct Choices *choices = PlayNovelScenarios.scenarios[this->progress.scenario]
			->acts[this->progress.act]->chapters[this->progress.chapter]
			->subChapters[this->progress.subChapter]
			->scenes[this->progress.scene]
			->choices;

		this->progress.act = choices->choices[this->choicesMenuOption].targetPage.act;
		this->progress.chapter = choices->choices[this->choicesMenuOption].targetPage.chapter;
		this->progress.subChapter = choices->choices[this->choicesMenuOption].targetPage.subChapter;
		this->progress.scene = choices->choices[this->choicesMenuOption].targetPage.scene;
		this->progress.page = 0;

		VisualNovelState::setUpScene(this);
		VisualNovelState::saveProgress(this);
	}
	else 
	{
		this->progress.page++;
		if(PlayNovelScenarios.scenarios[this->progress.scenario]
			->acts[this->progress.act]
			->chapters[this->progress.chapter]
			->subChapters[this->progress.subChapter]
			->scenes[this->progress.scene]
			->text[this->language][this->progress.page] == NULL)
		{
			if (branchingTargets != NULL)
			{
				// TODO: iterate and check conditions
				this->progress.act = branchingTargets->branchingTargets[0].target.act;
				this->progress.chapter = branchingTargets->branchingTargets[0].target.chapter;
				this->progress.subChapter = branchingTargets->branchingTargets[0].target.subChapter;
				this->progress.scene = branchingTargets->branchingTargets[0].target.scene;
				this->progress.page = 0;

				VisualNovelState::setUpScene(this);
				VisualNovelState::saveProgress(this);
			}
			else
			{
				this->progress.page = 0;
				VisualNovelState::nextScene(this);
			}
		}
	}

	VisualNovelState::setUpPage(this);
	VisualNovelState::showPage(this);
}

void VisualNovelState::nextScene()
{
	this->progress.scene++;
	if(PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]
		->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene] == NULL)
	{
		this->progress.scene = 0;
		VisualNovelState::nextSubChapter(this);
	}

	VisualNovelState::setUpScene(this);
	VisualNovelState::saveProgress(this);
}

void VisualNovelState::nextSubChapter()
{
	this->progress.subChapter++;
	if(PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]
		->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter] == NULL)
	{
		this->progress.subChapter = 0;
		VisualNovelState::nextChapter(this);
	}
}

void VisualNovelState::nextChapter()
{
	this->progress.chapter++;
	if(PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]
		->chapters[this->progress.chapter] == NULL)
	{
		this->progress.chapter = 0;
		VisualNovelState::nextAct(this);
	}
}

void VisualNovelState::nextAct()
{
	this->progress.act++;
	if(PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act] == NULL)
	{
		this->progress.act = 0;
		// TODO: Go to credits
	}
}

void VisualNovelState::showPage()
{
	uint8 fade = this->progress.page == 0
		? PlayNovelScenarios.scenarios[this->progress.scenario]
			->acts[this->progress.act]
			->chapters[this->progress.chapter]
			->subChapters[this->progress.subChapter]
			->scenes[this->progress.scene]
			->fadeInType
		: kFadeTypeNone;

	switch(fade)
	{
		case kFadeTypeNone:
		{
			ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kVisualNovelMessageStartPage, 100, 0);
			break;
		}
		case kFadeTypeNormal:
		{
			Camera::startEffect(
				kFadeTo, // effect type
				200, // initial delay (in ms)
				NULL, // target brightness
				__FADE_DELAY, // delay between fading steps (in ms)
				(void (*)(ListenerObject, ListenerObject))VisualNovelState::onSceneFadeInComplete, // callback function
				ListenerObject::safeCast(this) // callback scope
			);
			break;
		}
		case kFadeTypeSlow:
		{
			Camera::startEffect(
				kFadeTo, // effect type
				200, // initial delay (in ms)
				NULL, // target brightness
				50, // delay between fading steps (in ms)
				(void (*)(ListenerObject, ListenerObject))VisualNovelState::onSceneFadeInComplete, // callback function
				ListenerObject::safeCast(this) // callback scope
			);
			break;
		}
	}
}

void VisualNovelState::hidePage()
{
	uint8 fade = PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]
		->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene]
		->text[this->language][this->progress.page + 1] == 0
		? PlayNovelScenarios.scenarios[this->progress.scenario]
			->acts[this->progress.act]
			->chapters[this->progress.chapter]
			->subChapters[this->progress.subChapter]
			->scenes[this->progress.scene]
			->fadeOutType
		: kFadeTypeNone;

	VUEngine::disableKeypad();

	switch(fade)
	{
		case kFadeTypeNone:
		{
			VisualNovelState::nextPage(this);
			break;
		}
		case kFadeTypeNormal:
		{
			VUEngine::disableKeypad();
			Brightness brightness = (Brightness){0, 0, 0};
			Camera::startEffect(
				kFadeTo, // effect type
				0, // initial delay (in ms)
				&brightness, // target brightness
				__FADE_DELAY, // delay between fading steps (in ms)
				(void (*)(ListenerObject, ListenerObject))VisualNovelState::onSceneFadeOutComplete, // callback function
				ListenerObject::safeCast(this) // callback scope
			);
			break;
		}
		case kFadeTypeSlow:
		{
			VUEngine::disableKeypad();
			Brightness brightness = (Brightness){0, 0, 0};
			Camera::startEffect(
				kFadeTo, // effect type
				0, // initial delay (in ms)
				&brightness, // target brightness
				50, // delay between fading steps (in ms)
				(void (*)(ListenerObject, ListenerObject))VisualNovelState::onSceneFadeOutComplete, // callback function
				ListenerObject::safeCast(this) // callback scope
			);
			break;
		}
	}
}

void VisualNovelState::setUpPage()
{
	this->charNumber = 0;
	this->charX = 0;
	this->charY = 0;
	Printing::clear();
	Actor::hide(this->actorFlauros);
	this->text = PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene]
		->text[this->language][this->progress.page];
	this->textLength = strlen(this->text);
	this->pageFinished = false;
	this->choicesMenuOptionCount = 0;

	Printing::setPalette(0);
}

void VisualNovelState::setUpScene()
{
	const struct Scene *scene = PlayNovelScenarios.scenarios[this->progress.scenario]
			->acts[this->progress.act]->chapters[this->progress.chapter]
			->subChapters[this->progress.subChapter]
			->scenes[this->progress.scene];

	Stage stage = VUEngine::getStage();
	Container sceneActor = Container::getChildByName(Container::safeCast(stage), "SCENE", true);
	if(!isDeleted(sceneActor)) {
		Stage::destroyChildActor(stage, Actor::safeCast(sceneActor));
	}
	PositionedActor scenePositionedActor = {&DummyContainerActorSpec, {0, -32, 0}, {0, 0, 0}, {1, 1, 1}, 0, "SCENE", (struct PositionedActor*)scene->positionedActors, NULL, false};
	Stage::spawnChildActor(stage, &scenePositionedActor, true);

	if(NULL != scene->sound)
	{
		SoundManager::stopAllSounds(true, NULL);
		SoundManager::playSound(scene->sound, NULL, scene->soundPlaybackType, NULL, NULL);
	}
	else if(scene->soundPlaybackType == -1)
	{
		SoundManager::stopAllSounds(true, NULL);
	}
}

void VisualNovelState::startPage()
{
	VUEngine::enableKeypad();
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kVisualNovelMessagePrintChar, CHARACTER_DELAY, 0);
}

void VisualNovelState::onSceneFadeOutComplete(ListenerObject eventFirer __attribute__ ((unused)))
{
	VisualNovelState::nextPage(this);
}

void VisualNovelState::onSceneFadeInComplete(ListenerObject eventFirer __attribute__ ((unused)))
{
	VisualNovelState::startPage(this);
}

void VisualNovelState::loadProgress()
{
	GameSaveDataManager::getValue(
		GameSaveDataManager::getInstance(), 
		(BYTE*)&this->progress,
		offsetof(struct GameSaveData, gameProgress) + (this->saveSlot * sizeof(this->progress)), 
		sizeof(this->progress)
	);
}

void VisualNovelState::saveProgress()
{
	GameSaveDataManager::setValue(
		GameSaveDataManager::getInstance(), 
		(BYTE*)&this->progress, 
		offsetof(struct GameSaveData, gameProgress) + (this->saveSlot * sizeof(this->progress)), 
		sizeof(this->progress)
	);
}

void VisualNovelState::printCharacter()
{
	char text[2] = " \0";
	text[0] = this->text[this->charNumber++];
	switch(text[0])
	{
		// Line feed
		case 13:
			break;
		// Tab
		case 9:
			this->charX += __TAB_SIZE;
			break;
		// Carriage return
		case 10:
			this->charX = 0;
			this->charY += 2;
			break;
		default:
			Printing::text((const char *)&text, this->charX++, this->charY, "Silent");
			break;
	}

	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kVisualNovelMessagePrintChar, CHARACTER_DELAY, 0);
}

void VisualNovelState::finishPage()
{
	this->pageFinished = true;
	Printing::text(this->text, 0, 0, "Silent");
	if(this->textLength > 0)
	{
		Actor::show(this->actorFlauros);
	}
	Vector3D position = VisualNovelState::findFlaurosPosition(this);
	Actor::setLocalPosition(this->actorFlauros, &position);
}

Vector3D VisualNovelState::findFlaurosPosition()
{
	uint16 i = 0, x = 0, y = 0;
	while(this->text[i])
	{
		switch(this->text[i++])
		{
			// Line feed
			case 13:
				break;
			// Tab
			case 9:
				x += __TAB_SIZE;
				break;
			// Carriage return
			case 10:
				x = 0;
				y++;
				break;
			default:
				x++;
				break;
		}
	}

	return (Vector3D){
		__PIXELS_TO_METERS((x << 3) - 166),
		__PIXELS_TO_METERS((y << 4) + 67),
		__PIXELS_TO_METERS(0),
	};
}

void VisualNovelState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey & (K_A | K_STA))
	{
		if(this->pageFinished)
		{
			if(this->choicesMenuOptionCount == 0 && VisualNovelState::sceneHasChoices(this))
			{
				Printing::clear();
				Actor::hide(this->actorFlauros);
				VisualNovelState::printChoices(this);
			}
			else
			{
				VisualNovelState::hidePage(this);
			}
		}
		else
		{
			VisualNovelState::finishPage(this);
		}
	}
	else if(userInput.pressedKey & (K_LU | K_RU))
	{
		if (this->choicesMenuOption > 0)
		{
			this->choicesMenuOption--;
			VisualNovelState::printChoices(this);
		}
	}
	else if(userInput.pressedKey & (K_LD | K_RD))
	{
		if (this->choicesMenuOption < (this->choicesMenuOptionCount - 1))
		{
			this->choicesMenuOption++;
			VisualNovelState::printChoices(this);
		}
	}
}

void VisualNovelState::setSaveSlot(uint8 saveSlot)
{
	this->saveSlot = saveSlot;
}

bool VisualNovelState::sceneHasChoices()
{
	return PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene]
		->choices != NULL;
}

void VisualNovelState::printChoices() 
{
	const struct Choices *choices = PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene]
		->choices;

	this->choicesMenuOptionCount = 0;
	for(uint8 i = 0; i < MAX_CHOICES; i++)
	{
		if(choices->choices[i].text[0] != NULL)
		{
			this->choicesMenuOptionCount++;
			Printing::setPalette(i == this->choicesMenuOption ? 0 : 3);
			switch(i)
			{
				case 0: Printing::text("A)", 0, i * 2, "Silent"); break;
				case 1: Printing::text("B)", 0, i * 2, "Silent"); break;
				case 2: Printing::text("C)", 0, i * 2, "Silent"); break;
			}
			Printing::text(choices->choices[i].text[this->language], 3, i * 2, "Silent");
		}
	}
}