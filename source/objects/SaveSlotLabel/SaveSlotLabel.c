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
#include <GameEvents.h>
#include <VUEngine.h>
#include <I18n.h>
#include <GameSaveDataManager.h>
#include <VisualNovelState.h>
#include <Utilities.h>
#include "SaveSlotLabel.h"


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern Script PlayNovelScenarios;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void SaveSlotLabel::constructor(AnimatedEntitySpec* animatedEntitySpec, int16 internalId, const char* const name)
{
	Base::constructor(animatedEntitySpec, internalId, name);
	this->index = atoi(name);
}

void SaveSlotLabel::destructor()
{
	Base::destructor();
}

void SaveSlotLabel::ready(bool recursive)
{
	Base::ready(this, recursive);

	SaveSlotLabel::loadProgress(this);
	SaveSlotLabel::printInfo(this);
}

void SaveSlotLabel::printInfo()
{
	uint16 language = I18n::getActiveLanguage(I18n::getInstance());
	if(this->progress.started) {
		AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this), Utilities::itoa(this->progress.scenario, 10, 1));

		uint8 yPos = 6 + this->index * 6;

		char* actTitle = PlayNovelScenarios.scenarios[this->progress.scenario]->acts[this->progress.act]->title[language];
		FontSize actTitleTextSize = Printing::getTextSize(Printing::getInstance(), actTitle, "Silent");
		Printing::text(Printing::getInstance(), actTitle, 43 - actTitleTextSize.x, yPos, "Silent");

		char* chapterTitle = PlayNovelScenarios.scenarios[this->progress.scenario]->acts[this->progress.act]->chapters[this->progress.chapter]->title[language];
		FontSize chapterTitleTextSize = Printing::getTextSize(Printing::getInstance(), chapterTitle, "Silent");
		Printing::text(Printing::getInstance(), "\"", 41 - chapterTitleTextSize.x, yPos + 2, "Silent");
		Printing::text(Printing::getInstance(), "\"", 42, yPos + 2, "Silent");
		Printing::text(Printing::getInstance(), chapterTitle, 42 - chapterTitleTextSize.x, yPos + 2, "Silent");
	}
	else
	{
		AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this), language == 1 ? "EmptyDE" : "EmptyEN");
	}
}

void SaveSlotLabel::loadProgress()
{
	GameSaveDataManager::getValue(
		GameSaveDataManager::getInstance(), 
		(BYTE*)&this->progress,
		offsetof(struct GameSaveData, gameProgress) + (this->index * sizeof(this->progress)), 
		sizeof(this->progress)
	);
}