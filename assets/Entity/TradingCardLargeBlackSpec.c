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

extern uint32 TradingCardLargeBlackTiles[];
extern uint16 TradingCardLargeBlackMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

CharSetROMSpec TradingCardLargeBlackCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	TradingCardLargeBlackTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec TradingCardLargeBlackTextureSpec =
{
	// charset spec
	(CharSetSpec*)&TradingCardLargeBlackCharSetSpec,

	// bgmap spec
	TradingCardLargeBlackMap,

	// cols (max 64)
	10,

	// rows (max 64)
	15,

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

BgmapSpriteROMSpec TradingCardLargeBlackSpriteSpec =
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
		(TextureSpec*)&TradingCardLargeBlackTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, -2},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

ComponentSpec* const TradingCardLargeBlackEntityComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardLargeBlackSpriteSpec,
	NULL
};

EntityROMSpec TradingCardLargeBlackEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)TradingCardLargeBlackEntityComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Entity's in-game type
	kTypeNone
};
