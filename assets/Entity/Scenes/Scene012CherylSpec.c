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

extern CharSetROMSpec Scene012CharSetSpec;
extern uint16 Scene012CherylBaseMap[];
extern uint16 Scene012CherylOverlayMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

TextureROMSpec Scene012CherylBaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene012CharSetSpec,

	// bgmap spec
	Scene012CherylBaseMap,

	// cols (max 64)
	3,

	// rows (max 64)
	8,

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

BgmapSpriteROMSpec Scene012CherylBaseSpriteSpec =
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
		(TextureSpec*)&Scene012CherylBaseTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{5, 20, -2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene012CherylOverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene012CharSetSpec,

	// bgmap spec
	Scene012CherylOverlayMap,

	// cols (max 64)
	3,

	// rows (max 64)
	8,

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

BgmapSpriteROMSpec Scene012CherylOverlaySpriteSpec =
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
		(TextureSpec*)&Scene012CherylOverlayTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{5, 20, -2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

@COMP_ARRAY_START:Scene012CherylSpriteSpecs
	&Scene012CherylBaseSpriteSpec,
	&Scene012CherylOverlaySpriteSpec,
	
@COMP_ARRAY_END:Scene012CherylSpriteSpecs

const ComponentSpec* Scene012CherylEntitySpecComponentSpecs[] = 
{
	
    (ComponentSpec*)Scene012CherylBaseSpriteSpec,
    (ComponentSpec*)Scene012CherylOverlaySpriteSpec,

};

EntityROMSpec Scene012CherylEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	(ComponentSpec**)Scene012CherylEntitySpecComponentSpecs,

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
