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

extern uint32 TradingCardsBackgroundTiles[];
extern uint16 TradingCardsBackgroundMap[];
extern uint32 TradingCardsBackgroundSpineTiles[];
extern uint16 TradingCardsBackgroundSpineMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec TradingCardsBackgroundCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	97,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	TradingCardsBackgroundTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec TradingCardsBackgroundTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardsBackgroundCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardsBackgroundMap,

	// Horizontal size in tiles of the texture (max. 64)
	30,

	// Vertical size in tiles of the texture (max. 64)
	20,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

BgmapSpriteROMSpec TradingCardsBackgroundSpriteSpec =
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
		(TextureSpec*)&TradingCardsBackgroundTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

CharSetROMSpec TradingCardsBackgroundSpineCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	3,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	TradingCardsBackgroundSpineTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec TradingCardsBackgroundSpineTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardsBackgroundSpineCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardsBackgroundSpineMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	15,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

BgmapSpriteROMSpec TradingCardsBackgroundSpineSpriteSpec =
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
		(TextureSpec*)&TradingCardsBackgroundSpineTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{114, -5, -1, -1},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const TradingCardsBackgroundActorComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardsBackgroundSpriteSpec,
	(ComponentSpec*)&TradingCardsBackgroundSpineSpriteSpec,
	NULL
};

ActorROMSpec TradingCardsBackgroundActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TradingCardsBackgroundActorComponentSpecs,

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
