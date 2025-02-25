/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef GAME_SAVE_DATA_MANAGER_H_
#define GAME_SAVE_DATA_MANAGER_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <SaveDataManager.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//											CLASS'S MACROS

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define NUMBER_OF_SAVE_SLOTS		3

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// 											TYPE DEFINITIONS

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef struct GameProgress
{
	uint16 scenario;
	uint16 act;
	uint16 chapter;
	uint16 subChapter;
	uint16 scene;
	uint16 page;
	bool started;
} GameProgress;

typedef struct GameSaveData
{
	SaveData baseSaveData;
	uint32 unlockedCards;
	GameProgress gameProgress[NUMBER_OF_SAVE_SLOTS];
} GameSaveData;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

singleton class GameSaveDataManager : SaveDataManager
{
	static GameSaveDataManager getInstance();
	override void writeDefaults();
	override int32 getSaveDataSize();
}

#endif
