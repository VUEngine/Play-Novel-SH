/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <LibVUEngine.h>
#include <Actor.h>
#include <VIPManager.h>
#include <BgmapSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 TradingCardsBackgroundNumbersTiles[];
extern uint32 TradingCardsBackgroundNumbersTilesFrameOffsets[];
extern uint16 TradingCardsBackgroundNumbersMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec TradingCardsBackgroundNumbers0AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 0 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,


	// Animation's name
	"0",
};

AnimationFunctionROMSpec TradingCardsBackgroundNumbers1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 1 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,


	// Animation's name
	"1",
};

AnimationFunctionROMSpec TradingCardsBackgroundNumbers2AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 2 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,


	// Animation's name
	"2",
};

AnimationFunctionROMSpec TradingCardsBackgroundNumbers3AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 3 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,


	// Animation's name
	"3",
};

AnimationFunctionROMSpec* const TradingCardsBackgroundNumbersAnimationSpecs[] =
{
	(AnimationFunction*)&TradingCardsBackgroundNumbers0AnimationSpec,
	(AnimationFunction*)&TradingCardsBackgroundNumbers1AnimationSpec,
	(AnimationFunction*)&TradingCardsBackgroundNumbers2AnimationSpec,
	(AnimationFunction*)&TradingCardsBackgroundNumbers3AnimationSpec,
	NULL,
};

CharSetROMSpec TradingCardsBackgroundNumbersCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	51,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardsBackgroundNumbersTiles,

	// Frame offsets array
	TradingCardsBackgroundNumbersTilesFrameOffsets,
};

TextureROMSpec TradingCardsBackgroundNumbersTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardsBackgroundNumbersCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardsBackgroundNumbersMap,

	// Horizontal size in tiles of the texture (max. 64)
	40,

	// Vertical size in tiles of the texture (max. 64)
	10,

	// Padding for affine transformations
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

BgmapSpriteROMSpec TradingCardsBackgroundNumbersSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// Is animated?
		true,

		// Spec for the texture to display
		(TextureSpec*)&TradingCardsBackgroundNumbersTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, -1, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const TradingCardsBackgroundNumbersActorComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardsBackgroundNumbersSpriteSpec,
	NULL
};

ActorROMSpec TradingCardsBackgroundNumbersActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TradingCardsBackgroundNumbersActorComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	0,

	// Pointer to animation functions array
	(const AnimationFunction**)&TradingCardsBackgroundNumbersAnimationSpecs,

	// Animation to play automatically
	"0",
};
