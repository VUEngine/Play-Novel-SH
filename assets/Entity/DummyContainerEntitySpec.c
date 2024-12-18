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

ComponentSpec** DummyContainerEntitySpecComponentSpecs[] = 
{
	@COMPONENTS:DummyContainerEntitySpec@
};

EntityROMSpec DummyContainerEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	@BEHAVIORS:NULL@,

	// extra
	NULL,

	@SPRITES:NULL@,

	// use z displacement in projection
	false,
			
	@WIREFRAMES:(WireframeSpec**)NULL@,

	@COLLIDERS:NULL@,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	@PHYSICS:NULL@,
};