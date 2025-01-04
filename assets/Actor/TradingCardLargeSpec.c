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

extern uint32 TradingCardLargeBaseTiles[];
extern uint32 TradingCardLargeBaseTilesFrameOffsets[];
extern uint16 TradingCardLargeBaseMap[];
extern uint32 TradingCardLargeOverlayTiles[];
extern uint32 TradingCardLargeOverlayTilesFrameOffsets[];
extern uint16 TradingCardLargeOverlayMap[];
extern ActorSpec TradingCardLargeBlackActorSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec TradingCardLarge0AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge1AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge2AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge3AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge4AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge5AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge6AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge7AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge8AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge9AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge10AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge11AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge12AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge13AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge14AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge15AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge16AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge17AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge18AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge19AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge20AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge21AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge22AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge23AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge24AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge25AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge26AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge27AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge28AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge29AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge30AnimationSpec =
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

AnimationFunctionROMSpec TradingCardLarge31AnimationSpec =
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

AnimationFunctionROMSpec* const TradingCardLargeAnimationSpecs[] =
{
	(AnimationFunction*)&TradingCardLarge0AnimationSpec,
	(AnimationFunction*)&TradingCardLarge1AnimationSpec,
	(AnimationFunction*)&TradingCardLarge2AnimationSpec,
	(AnimationFunction*)&TradingCardLarge3AnimationSpec,
	(AnimationFunction*)&TradingCardLarge4AnimationSpec,
	(AnimationFunction*)&TradingCardLarge5AnimationSpec,
	(AnimationFunction*)&TradingCardLarge6AnimationSpec,
	(AnimationFunction*)&TradingCardLarge7AnimationSpec,
	(AnimationFunction*)&TradingCardLarge8AnimationSpec,
	(AnimationFunction*)&TradingCardLarge9AnimationSpec,
	(AnimationFunction*)&TradingCardLarge10AnimationSpec,
	(AnimationFunction*)&TradingCardLarge11AnimationSpec,
	(AnimationFunction*)&TradingCardLarge12AnimationSpec,
	(AnimationFunction*)&TradingCardLarge13AnimationSpec,
	(AnimationFunction*)&TradingCardLarge14AnimationSpec,
	(AnimationFunction*)&TradingCardLarge15AnimationSpec,
	(AnimationFunction*)&TradingCardLarge16AnimationSpec,
	(AnimationFunction*)&TradingCardLarge17AnimationSpec,
	(AnimationFunction*)&TradingCardLarge18AnimationSpec,
	(AnimationFunction*)&TradingCardLarge19AnimationSpec,
	(AnimationFunction*)&TradingCardLarge20AnimationSpec,
	(AnimationFunction*)&TradingCardLarge21AnimationSpec,
	(AnimationFunction*)&TradingCardLarge22AnimationSpec,
	(AnimationFunction*)&TradingCardLarge23AnimationSpec,
	(AnimationFunction*)&TradingCardLarge24AnimationSpec,
	(AnimationFunction*)&TradingCardLarge25AnimationSpec,
	(AnimationFunction*)&TradingCardLarge26AnimationSpec,
	(AnimationFunction*)&TradingCardLarge27AnimationSpec,
	(AnimationFunction*)&TradingCardLarge28AnimationSpec,
	(AnimationFunction*)&TradingCardLarge29AnimationSpec,
	(AnimationFunction*)&TradingCardLarge30AnimationSpec,
	(AnimationFunction*)&TradingCardLarge31AnimationSpec,
    NULL,
};

CharSetROMSpec TradingCardLargeBaseCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	148,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardLargeBaseTiles,

	// Frame offsets array
	TradingCardLargeBaseTilesFrameOffsets,
};

TextureROMSpec TradingCardLargeBaseTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardLargeBaseCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardLargeBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	10,

	// Vertical size in tiles of the texture (max. 64)
	15,

	// padding for affine transformations
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

BgmapSpriteROMSpec TradingCardLargeBaseSpriteSpec =
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
		(TextureSpec*)&TradingCardLargeBaseTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, -1, -2},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

CharSetROMSpec TradingCardLargeOverlayCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	150,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	TradingCardLargeOverlayTiles,

	// Frame offsets array
	TradingCardLargeOverlayTilesFrameOffsets,
};

TextureROMSpec TradingCardLargeOverlayTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&TradingCardLargeOverlayCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	TradingCardLargeOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	10,

	// Vertical size in tiles of the texture (max. 64)
	15,

	// padding for affine transformations
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

BgmapSpriteROMSpec TradingCardLargeOverlaySpriteSpec =
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
		(TextureSpec*)&TradingCardLargeOverlayTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// Displacement added to the sprite's position
		{0, 0, -2, -2},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

PositionedActorROMSpec TradingCardLargeChildrenActors[] =
{
	{&TradingCardLargeBlackActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
};

ComponentSpec* const TradingCardLargeActorComponentSpecs[] = 
{
	(ComponentSpec*)&TradingCardLargeBaseSpriteSpec,
	(ComponentSpec*)&TradingCardLargeOverlaySpriteSpec,
	NULL
};

ActorROMSpec TradingCardLargeActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TradingCardLargeActorComponentSpecs,

	// Children specs
	(PositionedActor*)TradingCardLargeChildrenActors,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	0,

	// Pointer to animation functions array
	(const AnimationFunction**)&TradingCardLargeAnimationSpecs,

	// Animation to play automatically
	"0",
};
