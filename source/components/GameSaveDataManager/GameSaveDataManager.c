/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <stddef.h>
#include <VirtualList.h>
#include <SRAMManager.h>
#include <GameSaveDataManager.h>


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// The save data default values 
const GameSaveData GameSaveDataDefaults =
{
	// base save data
	{
		// save stamp
		__SAVE_DATA_MANAGER_SAVE_STAMP,
		// checksum
		0,
		// active language id
		0,
		// auto pause status (0: on, 1: off)
		0
	},

	// unlocked cards
	4294967295,

	// game progress
	{
		// 1
		{
			// scenario
			0,
			// page
			0,
			// started
			true,
		},
		// 2
		{
			// scenario
			1,
			// page
			12,
			// started
			true,
		},
		// 3
		{
			// scenario
			0,
			// page
			0,
			// started
			false,
		},
	},
};


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
void GameSaveDataManager::constructor()
{
	// construct base object
	Base::constructor();
}

// class's destructor
void GameSaveDataManager::destructor()
{
	// destroy base
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