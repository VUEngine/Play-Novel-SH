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
#include <VIPManager.h>
#include <BgmapSprite.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern CharSetSpec SaveSlotBackgroundCharSetSpec;
extern uint16 SaveSlotWideBackgroundExtraMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

TextureROMSpec SaveSlotWideBackgroundExtraTextureSpec =
{
	// charset spec
	(CharSetSpec*)&SaveSlotBackgroundCharSetSpec,

	// bgmap spec
	SaveSlotWideBackgroundExtraMap,

	// cols (max 64)
	39,

	// rows (max 64)
	3,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec SaveSlotWideBackgroundExtraSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&SaveSlotWideBackgroundExtraTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

@COMP_ARRAY_START:SaveSlotWideBackgroundExtraSpriteSpecs
	&SaveSlotWideBackgroundExtraSpriteSpec,
	
@COMP_ARRAY_END:SaveSlotWideBackgroundExtraSpriteSpecs

const ComponentSpec* SaveSlotWideBackgroundExtraEntitySpecComponentSpecs[] = 
{
	
    (ComponentSpec*)SaveSlotWideBackgroundExtraSpriteSpec,

};

EntityROMSpec SaveSlotWideBackgroundExtraEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	(ComponentSpec**)SaveSlotWideBackgroundExtraEntitySpecComponentSpecs,

	// extra
	NULL,

	

	// use z displacement in projection
	false,
			
	

	

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	
};
