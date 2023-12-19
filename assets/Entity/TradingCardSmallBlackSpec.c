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

extern uint32 TradingCardSmallBlackTiles[];
extern uint16 TradingCardSmallBlackMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

CharSetROMSpec TradingCardSmallBlackCharset =
{
	// number of chars in function of the number of frames to load at the same time
	1,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	TradingCardSmallBlackTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec TradingCardSmallBlackTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardSmallBlackCharset,

	// bgmap spec
	TradingCardSmallBlackMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	1,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec TradingCardSmallBlackSprite =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&TradingCardSmallBlackTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, -1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const TradingCardSmallBlackSprites[] =
{
	&TradingCardSmallBlackSprite,
	NULL
};

EntityROMSpec TradingCardSmallBlackEntity =
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
	(SpriteSpec**)TradingCardSmallBlackSprites,

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
