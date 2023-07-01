/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

#ifndef SAVE_SLOT_LABEL_H_
#define SAVE_SLOT_LABEL_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <AnimatedEntity.h>
#include <macros.h>


//---------------------------------------------------------------------------------------------------------
//										PUBLIC INTERFACE
//---------------------------------------------------------------------------------------------------------

class SaveSlotLabel : AnimatedEntity
{
	uint8 index;

	void constructor(AnimatedEntitySpec* animatedEntitySpec, int16 internalId, const char* const name);
	override void ready(bool recursive);
}


#endif
