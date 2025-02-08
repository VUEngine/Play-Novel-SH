////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <BgmapSprite.h>
#include <InGameTypes.h>
#include <Texture.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 TradingCardsBackgroundActorTradingCardsBackgroundTiles[];
extern uint16 TradingCardsBackgroundActorTradingCardsBackgroundMap[];

extern uint32 TradingCardsBackgroundActorTradingCardsBackgroundSpineTiles[];
extern uint16 TradingCardsBackgroundActorTradingCardsBackgroundSpineMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec TradingCardsBackgroundSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	97,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardsBackgroundActorTradingCardsBackgroundTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec TradingCardsBackgroundSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardsBackgroundSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardsBackgroundActorTradingCardsBackgroundMap,

	// Horizontal size in tiles of the texture (max. 64)
	30,

	// Vertical size in tiles of the texture (max. 64)
	20,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec TradingCardsBackgroundSprite1SpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&TradingCardsBackgroundSprite1TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec TradingCardsBackgroundSprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	3,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardsBackgroundActorTradingCardsBackgroundSpineTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec TradingCardsBackgroundSprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardsBackgroundSprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardsBackgroundActorTradingCardsBackgroundSpineMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	15,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec TradingCardsBackgroundSprite2SpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&TradingCardsBackgroundSprite2TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{114, -5, -1, -1}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const TradingCardsBackgroundComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardsBackgroundSprite1SpriteSpec,
	(ComponentSpec*)&TradingCardsBackgroundSprite2SpriteSpec,
	NULL
};

ActorROMSpec TradingCardsBackgroundActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TradingCardsBackgroundComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Animation to play automatically
	NULL
	
};
