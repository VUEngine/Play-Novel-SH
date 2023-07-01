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

extern Sound CarBrakingSound;
extern Sound CarEngineSound;
extern Sound EnteringOtherWorldSound;
extern Sound SomethingStrangeSound;

extern EntitySpec Scene001Entity;
extern EntitySpec Scene002Entity;
extern EntitySpec Scene002HighlightEntity;
extern EntitySpec Scene003Entity;
extern EntitySpec Scene004Entity;
extern EntitySpec Scene005Entity;
extern EntitySpec Scene006Entity;
extern EntitySpec Scene007Entity;
extern EntitySpec Scene008Entity;


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
	this->page = 1;
	this->saveSlot = 0;
	this->scenario = kScenarioHarry;

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

	VisualNovelState::setScene(this);
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
			}
			break;
	}

	return true;
}

void VisualNovelState::setScene()
{
	uint8 fade = kFadeTypeToBlack;

	switch(this->page)
	{
		case 1:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen01a);
			VisualNovelState::saveProgress(this);
			break;

		case 2:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen01b);
			fade = kFadeTypeNoFade;
			break;

		case 3:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen02);
			break;

		case 4:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen03a);
			break;

		case 5:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen03b);
			fade = kFadeTypeNoFade;
			break;

		case 6:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen03c);
			fade = kFadeTypeNoFade;
			break;

		case 7:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen03d);
			fade = kFadeTypeNoFade;
			break;

		case 8:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen04a);
			break;

		case 9:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen04b);
			fade = kFadeTypeNoFade;
			break;

		case 10:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen05a);
			break;

		case 11:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen05b);
			fade = kFadeTypeNoFade;
			break;

		case 12:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen05c);
			fade = kFadeTypeNoFade;
			break;

		case 13:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen05d);
			fade = kFadeTypeNoFade;
			break;

		case 14:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen06a);
			break;

		case 15:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen06b);
			fade = kFadeTypeNoFade;
			break;

		case 16:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen07a);
			break;

		case 17:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen07b);
			fade = kFadeTypeNoFade;
			break;

		case 18:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen07c);
			fade = kFadeTypeNoFade;
			break;

		case 19:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen08a);
			SoundManager::stopAllSounds(SoundManager::getInstance(), true, NULL);
			SoundManager::playSound(SoundManager::getInstance(), &SomethingStrangeSound, kPlayAll, NULL, kSoundWrapperPlaybackNormal, NULL, NULL);
			break;

		case 20:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen08b);
			fade = kFadeTypeNoFade;
			break;
		case 21:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen08c);
			fade = kFadeTypeNoFade;
			break;
		case 22:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen08d);
			fade = kFadeTypeNoFade;
			break;

		case 23:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen09a);
			break;
		case 24:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen09b);
			fade = kFadeTypeNoFade;
			break;
		case 25:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen09c);
			fade = kFadeTypeNoFade;
			break;

		case 26:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen10a);
			SoundManager::stopAllSounds(SoundManager::getInstance(), true, NULL);
			SoundManager::playSound(SoundManager::getInstance(), &EnteringOtherWorldSound, kPlayAll, NULL, kSoundWrapperPlaybackNormal, NULL, NULL);
			break;
		case 27:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen10b);
			fade = kFadeTypeNoFade;
			break;
		case 28:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen10c);
			fade = kFadeTypeNoFade;
			break;

		case 29:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen11a);
			break;
		case 30:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen11b);
			fade = kFadeTypeNoFade;
			break;
		case 31:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen11c);
			fade = kFadeTypeNoFade;
			break;
		case 32:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen11d);
			fade = kFadeTypeNoFade;
			break;
		case 33:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen11e);
			fade = kFadeTypeNoFade;
			break;
		case 34:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen11f);
			fade = kFadeTypeNoFade;
			break;

		case 35:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen12);
			break;

		case 36:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen13a);
			break;

		case 37:
			this->text = I18n::getText(I18n::getInstance(), kStringIntroductionScreen13b);
			fade = kFadeTypeNoFade;
			break;

		case 38:
			this->text = "This is the end of this demo.";
			fade = kFadeTypeToBlackSlow;
			break;

		default:
			return;
	}

	switch(fade)
	{
		case kFadeTypeNoFade:
		{
			VisualNovelState::clearText(this);
			VisualNovelState::startPrinting(this);
			break;
		}
		case kFadeTypeToBlack:
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
		case kFadeTypeToBlackSlow:
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

void VisualNovelState::clearText()
{
	this->textLength = strlen(this->text);
	this->charNumber = 0;
	this->charX = 0;
	this->charY = 0;
	Printing::clear(Printing::getInstance());
	Entity::hide(this->entityFlauros);
}

void VisualNovelState::loadBackground()
{
	Stage stage = VUEngine::getStage(VUEngine::getInstance());
	Container sceneEntity = Container::getChildByName(Container::safeCast(stage), "SCENE", true);
	Container sceneHighlightEntity = Container::getChildByName(Container::safeCast(stage), "HIGHLGHT", true);

	switch(this->page)
	{
		case 1:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene001PositionedEntity = {&Scene001Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene001PositionedEntity, true);
			break;
		}
		case 3:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene002PositionedEntity = {&Scene002Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			//PositionedEntity scene002HighlightPositionedEntity = {&Scene002HighlightEntity, {192, 84, 0, 0}, 0, "HIGHLGHT", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene002PositionedEntity, true);
			//Stage::addChildEntity(stage, &scene002HighlightPositionedEntity, true);
			SoundWrapper::setVolumeReduction(SoundManager::getInstance(), 1);
			SoundManager::playSound(SoundManager::getInstance(), &CarEngineSound, kPlayAll, NULL, kSoundWrapperPlaybackFadeIn, NULL, NULL);
			break;
		}
		case 4:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			if(!isDeleted(sceneHighlightEntity)) {
				Stage::removeChild(stage, sceneHighlightEntity, true);
			}
			PositionedEntity scene003PositionedEntity = {&Scene003Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene003PositionedEntity, true);
			break;
		}
		case 8:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene002PositionedEntity = {&Scene002Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene002PositionedEntity, true);
			break;
		}
		case 10:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene004PositionedEntity = {&Scene004Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene004PositionedEntity, true);
			break;
		}
		case 14:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene003PositionedEntity = {&Scene003Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene003PositionedEntity, true);
			break;
		}
		case 16:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene002PositionedEntity = {&Scene002Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene002PositionedEntity, true);
			break;
		}
		case 19:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}	
			PositionedEntity scene005PositionedEntity = {&Scene005Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene005PositionedEntity, true);
			
			break;
		}
		case 23:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene006PositionedEntity = {&Scene006Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene006PositionedEntity, true);

			break;
		}
		case 26:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene002PositionedEntity = {&Scene002Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene002PositionedEntity, true);
			break;
		}
		case 29:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene003PositionedEntity = {&Scene003Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene003PositionedEntity, true);
			break;
		}
		case 35:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene007PositionedEntity = {&Scene007Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene007PositionedEntity, true);
			break;
		}
		case 36:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}
			PositionedEntity scene008PositionedEntity = {&Scene008Entity, {192, 84, 0, 0}, 0, "SCENE", NULL, NULL, false};
			Stage::addChildEntity(stage, &scene008PositionedEntity, true);
			break;
		}
		case 38:
		{
			if(!isDeleted(sceneEntity)) {
				Stage::removeChild(stage, sceneEntity, true);
			}

			SoundManager::stopAllSounds(SoundManager::getInstance(), true, NULL);
			SoundManager::playSound(SoundManager::getInstance(), &CarBrakingSound, kPlayAll, NULL, kSoundWrapperPlaybackNormal, NULL, NULL);
			break;
		}
	}
}

void VisualNovelState::startPrinting()
{
	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kVisualNovelMessagePrintChar, CHARACTER_DELAY, 0);
}

void VisualNovelState::onSceneFadeOutComplete(ListenerObject eventFirer __attribute__ ((unused)))
{
	VisualNovelState::clearText(this);
	VisualNovelState::loadBackground(this);

	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		__FADE_DELAY, // delay between fading steps (in ms)
		(void (*)(ListenerObject, ListenerObject))VisualNovelState::onSceneFadeInComplete, // callback function
		ListenerObject::safeCast(this) // callback scope
	);
}

void VisualNovelState::onSceneFadeInComplete(ListenerObject eventFirer __attribute__ ((unused)))
{
	VUEngine::enableKeypad(VUEngine::getInstance());
	VisualNovelState::startPrinting(this);
}

void VisualNovelState::saveProgress()
{
	/* 
	const struct GameProgress *progress = {
		this->scenario,
		this->page,
		true
	};

	GameSaveDataManager::setValue(
		GameSaveDataManager::getInstance(), 
		(BYTE*)&progress, 
		offsetof(struct GameSaveData, gameProgress) + (this->saveSlot * sizeof(&progress)), 
		sizeof(&progress)
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
	this->textLength = 0;
	Printing::text(Printing::getInstance(), this->text, 0, 0, "Silent");
	if (this->page < 38) {
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
	/*if(K_SEL & userInput.releasedKey)
	{
		Printing::show(Printing::getInstance());
		Entity::show(this->entityFlauros);
	}*/

	if((K_A | K_STA) & userInput.pressedKey)
	{
		if(this->textLength == 0)
		{
			this->page++;
			VisualNovelState::setScene(this);
		}
		else
		{
			VisualNovelState::finishPage(this);
		}
	}
	/*else if(K_SEL & userInput.pressedKey)
	{
		if(this->textLength == 0)
		{
			Printing::hide(Printing::getInstance());
			Entity::hide(this->entityFlauros);
		}
	}*/
}
