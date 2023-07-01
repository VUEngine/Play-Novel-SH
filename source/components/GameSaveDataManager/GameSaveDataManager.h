/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef GAME_SAVE_DATA_MANAGER_H_
#define GAME_SAVE_DATA_MANAGER_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <SaveDataManager.h>


//---------------------------------------------------------------------------------------------------------
// 											TYPE DEFINITIONS
//---------------------------------------------------------------------------------------------------------

typedef struct GameProgress
{
	uint8 scenario;
	uint8 page;
	bool started;
} GameProgress;

typedef struct GameSaveData
{
	SaveData baseSaveData;
	uint32 unlockedCards;
	GameProgress gameProgress[3];
} GameSaveData;


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class GameSaveDataManager : SaveDataManager
{
	static GameSaveDataManager getInstance();
	override void writeDefaults();
	override int32 getSaveDataSize();
}


#endif
