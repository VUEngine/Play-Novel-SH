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

extern uint32 TradingCardsBackgroundNumbersActorTradingCardsBackgroundNumbers1LTiles[];
extern uint16 TradingCardsBackgroundNumbersActorTradingCardsBackgroundNumbers1LMap[];
extern uint32 TradingCardsBackgroundNumbersActorTradingCardsBackgroundNumbers1LTilesFrameOffsets[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec TradingCardsBackgroundNumbersAnimation1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		0, 
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Animation's name
	"0",
};

AnimationFunctionROMSpec TradingCardsBackgroundNumbersAnimation2AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		1, 
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Animation's name
	"1",
};

AnimationFunctionROMSpec TradingCardsBackgroundNumbersAnimation3AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		2, 
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Animation's name
	"2",
};

AnimationFunctionROMSpec TradingCardsBackgroundNumbersAnimation4AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		3, 
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Animation's name
	"3",
};

AnimationFunctionROMSpec* TradingCardsBackgroundNumbersAnimationSpecs[] =
{
	(AnimationFunction*)&TradingCardsBackgroundNumbersAnimation1AnimationSpec,
	(AnimationFunction*)&TradingCardsBackgroundNumbersAnimation2AnimationSpec,
	(AnimationFunction*)&TradingCardsBackgroundNumbersAnimation3AnimationSpec,
	(AnimationFunction*)&TradingCardsBackgroundNumbersAnimation4AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec TradingCardsBackgroundNumbersSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	51,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardsBackgroundNumbersActorTradingCardsBackgroundNumbers1LTiles,

	// Frame offsets array
	TradingCardsBackgroundNumbersActorTradingCardsBackgroundNumbers1LTilesFrameOffsets
};

TextureROMSpec TradingCardsBackgroundNumbersSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardsBackgroundNumbersSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardsBackgroundNumbersActorTradingCardsBackgroundNumbers1LMap,

	// Horizontal size in tiles of the texture (max. 64)
	40,

	// Vertical size in tiles of the texture (max. 64)
	10,

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

BgmapSpriteROMSpec TradingCardsBackgroundNumbersSprite1SpriteSpec =
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
			(const AnimationFunction**)TradingCardsBackgroundNumbersAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&TradingCardsBackgroundNumbersSprite1TextureSpec,

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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const TradingCardsBackgroundNumbersComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardsBackgroundNumbersSprite1SpriteSpec,
	NULL
};

ActorROMSpec TradingCardsBackgroundNumbersActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TradingCardsBackgroundNumbersComponentSpecs,

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
	"0"
	
};
