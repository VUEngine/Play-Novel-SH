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
#include "SaveSlotLabel.h"


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

	SaveSlotLabel::setNameFrame(this);
}

void SaveSlotLabel::setNameFrame()
{
	/*if(this->index == 0)
	{
		AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this), "Harry");
	}
	else
	{*/
		AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this), "EmptyEN");
	/*}*/
}
