/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Entity.h>
#include <VIPManager.h>
#include <BgmapSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 Scene013Tiles[];
extern uint16 Scene013BaseMap[];
extern uint16 Scene013OverlayMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

CharSetROMSpec Scene013CharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	687,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	Scene013Tiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec Scene013BaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene013CharSetSpec,

	// bgmap spec
	Scene013BaseMap,

	// cols (max 64)
	30,

	// rows (max 64)
	20,

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

BgmapSpriteROMSpec Scene013BaseSpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&Scene013BaseTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

TextureROMSpec Scene013OverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene013CharSetSpec,

	// bgmap spec
	Scene013OverlayMap,

	// cols (max 64)
	30,

	// rows (max 64)
	20,

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

BgmapSpriteROMSpec Scene013OverlaySpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&Scene013OverlayTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{0, 0, -1, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const Scene013SpriteSpecs[] =
{
	&Scene013BaseSpriteSpec,
	&Scene013OverlaySpriteSpec,
	NULL
};

EntityROMSpec Scene013EntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	// behaviors
	NULL,

	// extra
	NULL,

	// sprites
	(SpriteSpec**)Scene013SpriteSpecs,

	// use z displacement in projection
	false,
			
	// wireframes
	(WireframeSpec**)NULL,

	// collision colliders
	(ColliderSpec*)NULL,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	// physical specification
	(PhysicalProperties*)NULL,
};
