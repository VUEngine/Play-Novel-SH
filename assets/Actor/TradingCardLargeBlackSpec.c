/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <VIPManager.h>
#include <BgmapSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 TradingCardLargeBlackTiles[];
extern uint16 TradingCardLargeBlackMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec TradingCardLargeBlackCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	TradingCardLargeBlackTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec TradingCardLargeBlackTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardLargeBlackCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardLargeBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	10,

	// Vertical size in tiles of the texture (max. 64)
	15,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	1,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
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

		// Spec for the texture to display
		(TextureSpec*)&TradingCardLargeBlackTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, -2},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const TradingCardLargeBlackActorComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardLargeBlackSpriteSpec,
	NULL
};

ActorROMSpec TradingCardLargeBlackActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TradingCardLargeBlackActorComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Pointer to animation functions array
	NULL,

	// Animation to play automatically
	NULL
};
