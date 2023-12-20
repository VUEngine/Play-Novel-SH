/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Libgccvb.h>
#include <AnimatedEntity.h>
#include <VIPManager.h>
#include <BgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 TradingCardSmallBaseTiles[];
extern uint32 TradingCardSmallBaseTilesFrameOffsets[];
extern uint16 TradingCardSmallBaseMap[];
extern uint32 TradingCardSmallOverlayTiles[];
extern uint32 TradingCardSmallOverlayTilesFrameOffsets[];
extern uint16 TradingCardSmallOverlayMap[];
extern EntitySpec TradingCardSmallBlackEntitySpec;


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec TradingCardSmall0AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 0 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"0",
};

AnimationFunctionROMSpec TradingCardSmall1AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 1 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"1",
};

AnimationFunctionROMSpec TradingCardSmall2AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 2 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"2",
};

AnimationFunctionROMSpec TradingCardSmall3AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 3 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"3",
};

AnimationFunctionROMSpec TradingCardSmall4AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 4 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"4",
};

AnimationFunctionROMSpec TradingCardSmall5AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 5 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"5",
};

AnimationFunctionROMSpec TradingCardSmall6AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 6 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"6",
};

AnimationFunctionROMSpec TradingCardSmall7AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 7 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"7",
};

AnimationFunctionROMSpec TradingCardSmall8AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 8 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"8",
};

AnimationFunctionROMSpec TradingCardSmall9AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 9 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"9",
};

AnimationFunctionROMSpec TradingCardSmall10AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 10 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"10",
};

AnimationFunctionROMSpec TradingCardSmall11AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 11 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"11",
};

AnimationFunctionROMSpec TradingCardSmall12AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 12 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"12",
};

AnimationFunctionROMSpec TradingCardSmall13AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 13 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"13",
};

AnimationFunctionROMSpec TradingCardSmall14AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 14 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"14",
};

AnimationFunctionROMSpec TradingCardSmall15AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 15 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"15",
};

AnimationFunctionROMSpec TradingCardSmall16AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 16 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"16",
};

AnimationFunctionROMSpec TradingCardSmall17AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 17 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"17",
};

AnimationFunctionROMSpec TradingCardSmall18AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 18 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"18",
};

AnimationFunctionROMSpec TradingCardSmall19AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 19 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"19",
};

AnimationFunctionROMSpec TradingCardSmall20AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 20 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"20",
};

AnimationFunctionROMSpec TradingCardSmall21AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 21 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"21",
};

AnimationFunctionROMSpec TradingCardSmall22AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 22 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"22",
};

AnimationFunctionROMSpec TradingCardSmall23AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 23 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"23",
};

AnimationFunctionROMSpec TradingCardSmall24AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 24 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"24",
};

AnimationFunctionROMSpec TradingCardSmall25AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 25 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"25",
};

AnimationFunctionROMSpec TradingCardSmall26AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 26 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"26",
};

AnimationFunctionROMSpec TradingCardSmall27AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 27 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"27",
};

AnimationFunctionROMSpec TradingCardSmall28AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 28 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"28",
};

AnimationFunctionROMSpec TradingCardSmall29AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 29 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"29",
};

AnimationFunctionROMSpec TradingCardSmall30AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 30 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"30",
};

AnimationFunctionROMSpec TradingCardSmall31AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 31 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
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
	// number of chars in function of the number of frames to load at the same time
	24,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	TradingCardSmallBaseTiles,

	// pointer to the frames offsets
	TradingCardSmallBaseTilesFrameOffsets,
};

TextureROMSpec TradingCardSmallBaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&TradingCardSmallBaseCharSetSpec,

	// bgmap spec
	TradingCardSmallBaseMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine transformations
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

BgmapSpriteROMSpec TradingCardSmallBaseSpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardSmallBaseTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, -1, -1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

CharSetROMSpec TradingCardSmallOverlayCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	24,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	TradingCardSmallOverlayTiles,

	// pointer to the frames offsets
	TradingCardSmallOverlayTilesFrameOffsets,
};

TextureROMSpec TradingCardSmallOverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&TradingCardSmallOverlayCharSetSpec,

	// bgmap spec
	TradingCardSmallOverlayMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine transformations
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

BgmapSpriteROMSpec TradingCardSmallOverlaySpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardSmallOverlayTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{0, 0, -2, -1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const TradingCardSmallSpriteSpecs[] =
{
	&TradingCardSmallBaseSpriteSpec,
	&TradingCardSmallOverlaySpriteSpec,
	NULL
};

PositionedEntityROMSpec TradingCardSmallChildrenEntities[] =
{
	{&TradingCardSmallBlackEntitySpec, {0, 0, 0, 0}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0, 0}, 0, NULL, NULL, NULL, true},
};

AnimatedEntityROMSpec TradingCardSmallEntitySpec =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// children
		(PositionedEntity*)TradingCardSmallChildrenEntities,

		// behaviors
		NULL,

		// extra
		NULL,

		// sprites
		(SpriteSpec**)TradingCardSmallSpriteSpecs,

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
		0,

		// physical specification
		(PhysicalProperties*)NULL,
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&TradingCardSmallAnimationSpecs,

	// initial animation
	"0",
};
