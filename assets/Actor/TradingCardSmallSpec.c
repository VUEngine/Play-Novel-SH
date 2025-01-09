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
#include <BgmapAnimatedSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 TradingCardSmallBaseTiles[];
extern uint32 TradingCardSmallBaseTilesFrameOffsets[];
extern uint16 TradingCardSmallBaseMap[];
extern uint32 TradingCardSmallOverlayTiles[];
extern uint32 TradingCardSmallOverlayTilesFrameOffsets[];
extern uint16 TradingCardSmallOverlayMap[];
extern ActorSpec TradingCardSmallBlackActorSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec TradingCardSmall0AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 0 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"0",
};

AnimationFunctionROMSpec TradingCardSmall1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 1 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"1",
};

AnimationFunctionROMSpec TradingCardSmall2AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 2 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"2",
};

AnimationFunctionROMSpec TradingCardSmall3AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 3 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"3",
};

AnimationFunctionROMSpec TradingCardSmall4AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 4 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"4",
};

AnimationFunctionROMSpec TradingCardSmall5AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 5 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"5",
};

AnimationFunctionROMSpec TradingCardSmall6AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 6 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"6",
};

AnimationFunctionROMSpec TradingCardSmall7AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 7 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"7",
};

AnimationFunctionROMSpec TradingCardSmall8AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 8 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"8",
};

AnimationFunctionROMSpec TradingCardSmall9AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 9 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"9",
};

AnimationFunctionROMSpec TradingCardSmall10AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 10 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"10",
};

AnimationFunctionROMSpec TradingCardSmall11AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 11 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"11",
};

AnimationFunctionROMSpec TradingCardSmall12AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 12 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"12",
};

AnimationFunctionROMSpec TradingCardSmall13AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 13 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"13",
};

AnimationFunctionROMSpec TradingCardSmall14AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 14 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"14",
};

AnimationFunctionROMSpec TradingCardSmall15AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 15 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"15",
};

AnimationFunctionROMSpec TradingCardSmall16AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 16 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"16",
};

AnimationFunctionROMSpec TradingCardSmall17AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 17 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"17",
};

AnimationFunctionROMSpec TradingCardSmall18AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 18 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"18",
};

AnimationFunctionROMSpec TradingCardSmall19AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 19 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"19",
};

AnimationFunctionROMSpec TradingCardSmall20AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 20 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"20",
};

AnimationFunctionROMSpec TradingCardSmall21AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 21 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"21",
};

AnimationFunctionROMSpec TradingCardSmall22AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 22 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"22",
};

AnimationFunctionROMSpec TradingCardSmall23AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 23 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"23",
};

AnimationFunctionROMSpec TradingCardSmall24AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 24 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"24",
};

AnimationFunctionROMSpec TradingCardSmall25AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 25 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"25",
};

AnimationFunctionROMSpec TradingCardSmall26AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 26 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"26",
};

AnimationFunctionROMSpec TradingCardSmall27AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 27 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"27",
};

AnimationFunctionROMSpec TradingCardSmall28AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 28 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"28",
};

AnimationFunctionROMSpec TradingCardSmall29AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 29 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"29",
};

AnimationFunctionROMSpec TradingCardSmall30AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 30 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"30",
};

AnimationFunctionROMSpec TradingCardSmall31AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 31 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"31",
};

AnimationFunctionROMSpec* const TradingCardSmallAnimationSpecs[] =
{
	(AnimationFunction*)&TradingCardSmall0AnimationSpec,
	(AnimationFunction*)&TradingCardSmall1AnimationSpec,
	(AnimationFunction*)&TradingCardSmall2AnimationSpec,
	(AnimationFunction*)&TradingCardSmall3AnimationSpec,
	(AnimationFunction*)&TradingCardSmall4AnimationSpec,
	(AnimationFunction*)&TradingCardSmall5AnimationSpec,
	(AnimationFunction*)&TradingCardSmall6AnimationSpec,
	(AnimationFunction*)&TradingCardSmall7AnimationSpec,
	(AnimationFunction*)&TradingCardSmall8AnimationSpec,
	(AnimationFunction*)&TradingCardSmall9AnimationSpec,
	(AnimationFunction*)&TradingCardSmall10AnimationSpec,
	(AnimationFunction*)&TradingCardSmall11AnimationSpec,
	(AnimationFunction*)&TradingCardSmall12AnimationSpec,
	(AnimationFunction*)&TradingCardSmall13AnimationSpec,
	(AnimationFunction*)&TradingCardSmall14AnimationSpec,
	(AnimationFunction*)&TradingCardSmall15AnimationSpec,
	(AnimationFunction*)&TradingCardSmall16AnimationSpec,
	(AnimationFunction*)&TradingCardSmall17AnimationSpec,
	(AnimationFunction*)&TradingCardSmall18AnimationSpec,
	(AnimationFunction*)&TradingCardSmall19AnimationSpec,
	(AnimationFunction*)&TradingCardSmall20AnimationSpec,
	(AnimationFunction*)&TradingCardSmall21AnimationSpec,
	(AnimationFunction*)&TradingCardSmall22AnimationSpec,
	(AnimationFunction*)&TradingCardSmall23AnimationSpec,
	(AnimationFunction*)&TradingCardSmall24AnimationSpec,
	(AnimationFunction*)&TradingCardSmall25AnimationSpec,
	(AnimationFunction*)&TradingCardSmall26AnimationSpec,
	(AnimationFunction*)&TradingCardSmall27AnimationSpec,
	(AnimationFunction*)&TradingCardSmall28AnimationSpec,
	(AnimationFunction*)&TradingCardSmall29AnimationSpec,
	(AnimationFunction*)&TradingCardSmall30AnimationSpec,
	(AnimationFunction*)&TradingCardSmall31AnimationSpec,
    NULL,
};

CharSetROMSpec TradingCardSmallBaseCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	24,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardSmallBaseTiles,

	// Frame offsets array
	TradingCardSmallBaseTilesFrameOffsets,
};

TextureROMSpec TradingCardSmallBaseTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardSmallBaseCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardSmallBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

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

BgmapSpriteROMSpec TradingCardSmallBaseSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&TradingCardSmallBaseTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, -1, -1},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

CharSetROMSpec TradingCardSmallOverlayCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	24,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardSmallOverlayTiles,

	// Frame offsets array
	TradingCardSmallOverlayTilesFrameOffsets,
};

TextureROMSpec TradingCardSmallOverlayTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardSmallOverlayCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardSmallOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

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

BgmapSpriteROMSpec TradingCardSmallOverlaySpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&TradingCardSmallOverlayTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// Displacement added to the sprite's position
		{0, 0, -2, -1},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

PositionedActorROMSpec TradingCardSmallChildrenActors[] =
{
	{&TradingCardSmallBlackActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
};

ComponentSpec* const TradingCardSmallActorComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardSmallBaseSpriteSpec,
	(ComponentSpec*)&TradingCardSmallOverlaySpriteSpec,
	NULL
};

ActorROMSpec TradingCardSmallActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TradingCardSmallActorComponentSpecs,

	// Children specs
	(PositionedActor*)TradingCardSmallChildrenActors,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	0,

	// Pointer to animation functions array
	(const AnimationFunction**)&TradingCardSmallAnimationSpecs,

	// Animation to play automatically
	"0",
};
