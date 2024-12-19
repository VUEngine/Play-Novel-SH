/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Entity.h>


//---------------------------------------------------------------------------------------------------------
//											DECLARATIONS
//---------------------------------------------------------------------------------------------------------

const ComponentSpec* DummyContainerEntitySpecComponentSpecs[] = 
{
	

};

EntityROMSpec DummyContainerEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpec**)DummyContainerEntitySpecComponentSpecs,

	// children
	NULL,

	// extra
	NULL,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone
};