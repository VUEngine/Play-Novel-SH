/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <string.h>
#include <VUEngine.h>
#include <Utilities.h>
#include <AnimatedEntity.h>
#include <Camera.h>
#include <MessageDispatcher.h>
#include <I18n.h>
#include <Languages.h>
#include <PhysicalWorld.h>
#include <VisualNovelState.h>
#include <ParticleSystem.h>
#include <KeypadManager.h>
#include <GameEvents.h>
#include <debugUtilities.h>
#include <AutomaticPauseManager.h>
#include <GameEvents.h>
#include <GameSaveDataManager.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec VisualNovelStageSpec;
extern Script PlayNovelScenarios;
extern EntitySpec DummyContainerEntity;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void VisualNovelState::constructor()
{
	Base::constructor();
}

void VisualNovelState::destructor()
{
	Base::destructor();
}

void VisualNovelState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&VisualNovelStageSpec, NULL, true, false);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// optimize printing layer to save performance
	Printing::setWorldCoordinates(Printing::getInstance(), 16, 172, -4, -1);
	Printing::setPalette(Printing::getInstance(), 3);

	// initialize variables
	this->entityFlauros = Entity::safeCast(Container::getChildByName(Container::safeCast(VUEngine::getStage(VUEngine::getInstance())), "FLAUROS", true));
	this->charNumber = 0;
	this->charX = 0;
	this->charY = 0;
	this->text = "";
	this->textLength = 0;
	this->pageFinished = false;
	this->language = I18n::getActiveLanguage(I18n::getInstance());
	this->saveSlot = 0;

	// load progress, always start at page 0
	VisualNovelState::loadProgress(this);
	this->progress.page = 0;

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

	// start scene
	VisualNovelState::setUpScene(this);
	VisualNovelState::setUpPage(this);
	VisualNovelState::showPage(this);
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
	this->progress.page++;
	if(PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]
		->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene]
		->text[this->language][this->progress.page] == NULL)
	{
		this->progress.page = 0;
		VisualNovelState::nextScene(this);
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
	this->progress.chapter++;
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
		: kFadeTypeNoFade;

	switch(fade)
	{
		case kFadeTypeNoFade:
		{
			ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kVisualNovelMessageStartPage, 100, 0);
			break;
		}
		case kFadeTypeNormal:
		{
			Camera::startEffect(Camera::getInstance(),
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
			Camera::startEffect(Camera::getInstance(),
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
		: kFadeTypeNoFade;

	VUEngine::disableKeypad(VUEngine::getInstance());

	switch(fade)
	{
		case kFadeTypeNoFade:
		{
			VisualNovelState::nextPage(this);
			break;
		}
		case kFadeTypeNormal:
		{
			VUEngine::disableKeypad(VUEngine::getInstance());
			Brightness brightness = (Brightness){0, 0, 0};
			Camera::startEffect(Camera::getInstance(),
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
			VUEngine::disableKeypad(VUEngine::getInstance());
			Brightness brightness = (Brightness){0, 0, 0};
			Camera::startEffect(Camera::getInstance(),
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
	Printing::clear(Printing::getInstance());
	Entity::hide(this->entityFlauros);
	this->text = PlayNovelScenarios.scenarios[this->progress.scenario]
		->acts[this->progress.act]->chapters[this->progress.chapter]
		->subChapters[this->progress.subChapter]
		->scenes[this->progress.scene]
		->text[this->language][this->progress.page];
	this->textLength = strlen(this->text);
	this->pageFinished = false;
}

void VisualNovelState::setUpScene()
{
	const struct Scene *scene = PlayNovelScenarios.scenarios[this->progress.scenario]
			->acts[this->progress.act]->chapters[this->progress.chapter]
			->subChapters[this->progress.subChapter]
			->scenes[this->progress.scene];

	Stage stage = VUEngine::getStage(VUEngine::getInstance());
	Container sceneEntity = Container::getChildByName(Container::safeCast(stage), "SCENE", true);
	if(!isDeleted(sceneEntity)) {
		Stage::removeChild(stage, sceneEntity, true);
	}
	PositionedEntity scenePositionedEntity = {&DummyContainerEntity, {192, 80, 0, 0}, 0, "SCENE", (struct PositionedEntity*)scene->positionedEntities, NULL, false};
	Stage::addChildEntity(stage, &scenePositionedEntity, true);

	if(scene->sound)
	{
		SoundManager::stopAllSounds(SoundManager::getInstance(), true, NULL);
		SoundManager::playSound(SoundManager::getInstance(), scene->sound, kPlayAll, NULL, scene->soundPlaybackType, NULL, NULL);
	}
}

void VisualNovelState::startPage()
{
	VUEngine::enableKeypad(VUEngine::getInstance());
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
	/*
	GameSaveDataManager::setValue(
		GameSaveDataManager::getInstance(), 
		(BYTE*)&this->progress, 
		offsetof(struct GameSaveData, gameProgress) + (this->saveSlot * sizeof(this->progress)), 
		sizeof(this->progress)
	);
	*/
}

void VisualNovelState::printCharacter()
{
	char text[2] = " \0";
	text[0] = this->text[this->charNumber++];
	switch(text[0])
	{
		// line feed
		case 13:
			break;
		// tab
		case 9:
			this->charX += __TAB_SIZE;
			break;
		// carriage return
		case 10:
			this->charX = 0;
			this->charY += 2;
			break;
		default:
			Printing::text(Printing::getInstance(), (const char *)&text, this->charX++, this->charY, "Silent");
			break;
	}

	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kVisualNovelMessagePrintChar, CHARACTER_DELAY, 0);
}

void VisualNovelState::finishPage()
{
	this->pageFinished = true;
	Printing::text(Printing::getInstance(), this->text, 0, 0, "Silent");
	if(this->textLength > 0)
	{
		Entity::show(this->entityFlauros);
	}
	Vector3D position = VisualNovelState::findFlaurosPosition(this);
	Entity::setLocalPosition(this->entityFlauros, &position);
}

Vector3D VisualNovelState::findFlaurosPosition()
{
	uint16 i = 0, x = 0, y = 0;
	while(this->text[i])
	{
		switch(this->text[i++])
		{
			// line feed
			case 13:
				break;
			// tab
			case 9:
				x += __TAB_SIZE;
				break;
			// carriage return
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
		__PIXELS_TO_METERS((x << 3) + 24),
		__PIXELS_TO_METERS((y << 4) + 178),
		__PIXELS_TO_METERS(-4),
	};
}

void VisualNovelState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey & (K_A | K_STA))
	{
		if(this->pageFinished)
		{
			VisualNovelState::hidePage(this);
		}
		else
		{
			VisualNovelState::finishPage(this);
		}
	}
}
