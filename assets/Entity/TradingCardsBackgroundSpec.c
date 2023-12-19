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

extern uint32 TradingCardsBackgroundTiles[];
extern uint16 TradingCardsBackgroundMap[];
extern uint32 TradingCardsBackgroundSpineTiles[];
extern uint16 TradingCardsBackgroundSpineMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

CharSetROMSpec TradingCardsBackgroundCharset =
{
	// number of chars in function of the number of frames to load at the same time
	97,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	TradingCardsBackgroundTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec TradingCardsBackgroundTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardsBackgroundCharset,

	// bgmap spec
	TradingCardsBackgroundMap,

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

BgmapSpriteROMSpec TradingCardsBackgroundSprite =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&TradingCardsBackgroundTexture,

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

CharSetROMSpec TradingCardsBackgroundSpineCharset =
{
	// number of chars in function of the number of frames to load at the same time
	3,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	TradingCardsBackgroundSpineTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec TradingCardsBackgroundSpineTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardsBackgroundSpineCharset,

	// bgmap spec
	TradingCardsBackgroundSpineMap,

	// cols (max 64)
	2,

	// rows (max 64)
	15,

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

BgmapSpriteROMSpec TradingCardsBackgroundSpineSprite =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&TradingCardsBackgroundSpineTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{114, -5, -1, -1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const TradingCardsBackgroundSprites[] =
{
	&TradingCardsBackgroundSprite,
	&TradingCardsBackgroundSpineSprite,
	NULL
};

EntityROMSpec TradingCardsBackgroundEntity =
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
	(SpriteSpec**)TradingCardsBackgroundSprites,

	// use z displacement in projection
	false,
			
	// wireframes
	(WireframeSpec**)NULL,

	// collision shapes
	(ColliderSpec*)NULL,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	// physical specification
	(PhysicalProperties*)NULL,
};
