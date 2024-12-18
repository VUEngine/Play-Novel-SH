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

extern uint32 LogoTiles[];
extern uint16 LogoAMap[];
extern uint16 LogoBMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

CharSetROMSpec LogoCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	192,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	LogoTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec LogoATextureSpec =
{
	// charset spec
	(CharSetSpec*)&LogoCharSetSpec,

	// bgmap spec
	LogoAMap,

	// cols (max 64)
	26,

	// rows (max 64)
	7,

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

BgmapSpriteROMSpec LogoASpriteSpec =
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
		(TextureSpec*)&LogoATextureSpec,

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

TextureROMSpec LogoBTextureSpec =
{
	// charset spec
	(CharSetSpec*)&LogoCharSetSpec,

	// bgmap spec
	LogoBMap,

	// cols (max 64)
	24,

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

BgmapSpriteROMSpec LogoBSpriteSpec =
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
		(TextureSpec*)&LogoBTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{-6, -4, -1, -1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const LogoSpriteSpecs[] =
{
	&LogoASpriteSpec,
	&LogoBSpriteSpec,
	NULL
};

ComponentSpec** LogoEntitySpecComponentSpecs[] = 
{
	@COMPONENTS:LogoEntitySpec@
};

EntityROMSpec LogoEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	@BEHAVIORS:NULL@,

	// extra
	NULL,

	@SPRITES:(SpriteSpec**)LogoSpriteSpecs@,

	// use z displacement in projection
	false,
			
	@WIREFRAMES:(WireframeSpec**)NULL@,

	@COLLIDERS:(ColliderSpec*)NULL@,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	@PHYSICS:(PhysicalProperties*)NULL@,
};
