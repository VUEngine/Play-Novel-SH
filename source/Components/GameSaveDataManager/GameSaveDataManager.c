/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stddef.h>
#include <VirtualList.h>
#include <SRAMManager.h>
#include <GameSaveDataManager.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const GameProgress EmptyProgress =
{
	0, 0, 0, 0, 0, 0, false 
};

const GameSaveData GameSaveDataDefaults =
{
	// base save data
	{
		// save stamp
		__PLUGIN_SAVE_DATA_MANAGER_SAVE_STAMP,
		// checksum
		0,
		// active language id
		0,
		// auto pause status (0: on, 1: off)
		0
	},

	// unlocked cards
	//33322222222221111111111000000000
	//21098765432109876543210987654321
	0xFFFFFFFF,

	// game progress
	{
		// 1
		{
			0, // scenario
			0, // act
			0, // chapter
			0, // subChapter
			0, // scene
			0, // page
			false, // started
		},
		// 2
		{
			0, // scenario
			0, // act
			0, // chapter
			0, // subChapter
			0, // scene
			0, // page
			false, // started
		},
		// 3
		{
			0, // scenario
			0, // act
			0, // chapter
			0, // subChapter
			0, // scene
			0, // page
			false, // started
		},
	},
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS'S METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// class's constructor
void GameSaveDataManager::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}

// class's destructor
void GameSaveDataManager::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

void GameSaveDataManager::writeDefaults()
{
	SRAMManager::save(SRAMManager::getInstance(), (BYTE*)&GameSaveDataDefaults, 0, sizeof(GameSaveDataDefaults));
}

int32 GameSaveDataManager::getSaveDataSize()
{
	return (int32)sizeof(GameSaveData);
}