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
extern EntitySpec TradingCardSmallBlackEntity;


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec TradingCardSmall0Animation =
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

AnimationFunctionROMSpec TradingCardSmall1Animation =
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

AnimationFunctionROMSpec TradingCardSmall2Animation =
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

AnimationFunctionROMSpec TradingCardSmall3Animation =
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

AnimationFunctionROMSpec TradingCardSmall4Animation =
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

AnimationFunctionROMSpec TradingCardSmall5Animation =
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

AnimationFunctionROMSpec TradingCardSmall6Animation =
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

AnimationFunctionROMSpec TradingCardSmall7Animation =
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

AnimationFunctionROMSpec TradingCardSmall8Animation =
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

AnimationFunctionROMSpec TradingCardSmall9Animation =
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

AnimationFunctionROMSpec TradingCardSmall10Animation =
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

AnimationFunctionROMSpec TradingCardSmall11Animation =
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

AnimationFunctionROMSpec TradingCardSmall12Animation =
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

AnimationFunctionROMSpec TradingCardSmall13Animation =
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

AnimationFunctionROMSpec TradingCardSmall14Animation =
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

AnimationFunctionROMSpec TradingCardSmall15Animation =
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

AnimationFunctionROMSpec TradingCardSmall16Animation =
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

AnimationFunctionROMSpec TradingCardSmall17Animation =
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

AnimationFunctionROMSpec TradingCardSmall18Animation =
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

AnimationFunctionROMSpec TradingCardSmall19Animation =
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

AnimationFunctionROMSpec TradingCardSmall20Animation =
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

AnimationFunctionROMSpec TradingCardSmall21Animation =
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

AnimationFunctionROMSpec TradingCardSmall22Animation =
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

AnimationFunctionROMSpec TradingCardSmall23Animation =
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

AnimationFunctionROMSpec TradingCardSmall24Animation =
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

AnimationFunctionROMSpec TradingCardSmall25Animation =
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

AnimationFunctionROMSpec TradingCardSmall26Animation =
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

AnimationFunctionROMSpec TradingCardSmall27Animation =
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

AnimationFunctionROMSpec TradingCardSmall28Animation =
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

AnimationFunctionROMSpec TradingCardSmall29Animation =
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

AnimationFunctionROMSpec TradingCardSmall30Animation =
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

AnimationFunctionROMSpec TradingCardSmall31Animation =
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

AnimationFunctionROMSpec* const TradingCardSmallAnimation[] =
{
	(AnimationFunction*)&TradingCardSmall0Animation,
	(AnimationFunction*)&TradingCardSmall1Animation,
	(AnimationFunction*)&TradingCardSmall2Animation,
	(AnimationFunction*)&TradingCardSmall3Animation,
	(AnimationFunction*)&TradingCardSmall4Animation,
	(AnimationFunction*)&TradingCardSmall5Animation,
	(AnimationFunction*)&TradingCardSmall6Animation,
	(AnimationFunction*)&TradingCardSmall7Animation,
	(AnimationFunction*)&TradingCardSmall8Animation,
	(AnimationFunction*)&TradingCardSmall9Animation,
	(AnimationFunction*)&TradingCardSmall10Animation,
	(AnimationFunction*)&TradingCardSmall11Animation,
	(AnimationFunction*)&TradingCardSmall12Animation,
	(AnimationFunction*)&TradingCardSmall13Animation,
	(AnimationFunction*)&TradingCardSmall14Animation,
	(AnimationFunction*)&TradingCardSmall15Animation,
	(AnimationFunction*)&TradingCardSmall16Animation,
	(AnimationFunction*)&TradingCardSmall17Animation,
	(AnimationFunction*)&TradingCardSmall18Animation,
	(AnimationFunction*)&TradingCardSmall19Animation,
	(AnimationFunction*)&TradingCardSmall20Animation,
	(AnimationFunction*)&TradingCardSmall21Animation,
	(AnimationFunction*)&TradingCardSmall22Animation,
	(AnimationFunction*)&TradingCardSmall23Animation,
	(AnimationFunction*)&TradingCardSmall24Animation,
	(AnimationFunction*)&TradingCardSmall25Animation,
	(AnimationFunction*)&TradingCardSmall26Animation,
	(AnimationFunction*)&TradingCardSmall27Animation,
	(AnimationFunction*)&TradingCardSmall28Animation,
	(AnimationFunction*)&TradingCardSmall29Animation,
	(AnimationFunction*)&TradingCardSmall30Animation,
	(AnimationFunction*)&TradingCardSmall31Animation,
    NULL,
};

CharSetROMSpec TradingCardSmallBaseCharset =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	24,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char spec
	TradingCardSmallBaseTiles,

	// pointer to the frames offsets
	TradingCardSmallBaseTilesFrameOffsets,
};

TextureROMSpec TradingCardSmallBaseTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardSmallBaseCharset,

	// bgmap spec
	TradingCardSmallBaseMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine transformations
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
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

BgmapSpriteROMSpec TradingCardSmallBaseSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardSmallBaseTexture,

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

CharSetROMSpec TradingCardSmallOverlayCharset =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	24,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char spec
	TradingCardSmallOverlayTiles,

	// pointer to the frames offsets
	TradingCardSmallOverlayTilesFrameOffsets,
};

TextureROMSpec TradingCardSmallOverlayTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardSmallOverlayCharset,

	// bgmap spec
	TradingCardSmallOverlayMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine transformations
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
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

BgmapSpriteROMSpec TradingCardSmallOverlaySprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardSmallOverlayTexture,

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

BgmapSpriteROMSpec* const TradingCardSmallSprites[] =
{
	&TradingCardSmallBaseSprite,
	&TradingCardSmallOverlaySprite,
	NULL
};

PositionedEntityROMSpec TradingCardSmallChildrenEntities[] =
{
	{&TradingCardSmallBlackEntity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0, 0}, 0, NULL, NULL, NULL, true},
};

AnimatedEntityROMSpec TradingCardSmallEntity =
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
		(SpriteSpec**)TradingCardSmallSprites,

		// use z displacement in projection
		false,
			
		// wireframes
		(WireframeSpec**)NULL,

		// collision shapes
		(ShapeSpec*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		0,

		// physical specification
		(PhysicalSpecification*)NULL,
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&TradingCardSmallAnimation,

	// initial animation
	"0",
};
