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
#include <BgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 TradingCardLargeBaseTiles[];
extern uint32 TradingCardLargeBaseTilesFrameOffsets[];
extern uint16 TradingCardLargeBaseMap[];
extern uint32 TradingCardLargeOverlayTiles[];
extern uint32 TradingCardLargeOverlayTilesFrameOffsets[];
extern uint16 TradingCardLargeOverlayMap[];
extern EntitySpec TradingCardLargeBlackEntity;


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec TradingCardLarge0Animation =
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

AnimationFunctionROMSpec TradingCardLarge1Animation =
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

AnimationFunctionROMSpec TradingCardLarge2Animation =
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

AnimationFunctionROMSpec TradingCardLarge3Animation =
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

AnimationFunctionROMSpec TradingCardLarge4Animation =
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

AnimationFunctionROMSpec TradingCardLarge5Animation =
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

AnimationFunctionROMSpec TradingCardLarge6Animation =
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

AnimationFunctionROMSpec TradingCardLarge7Animation =
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

AnimationFunctionROMSpec TradingCardLarge8Animation =
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

AnimationFunctionROMSpec TradingCardLarge9Animation =
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

AnimationFunctionROMSpec TradingCardLarge10Animation =
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

AnimationFunctionROMSpec TradingCardLarge11Animation =
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

AnimationFunctionROMSpec TradingCardLarge12Animation =
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

AnimationFunctionROMSpec TradingCardLarge13Animation =
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

AnimationFunctionROMSpec TradingCardLarge14Animation =
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

AnimationFunctionROMSpec TradingCardLarge15Animation =
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

AnimationFunctionROMSpec TradingCardLarge16Animation =
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

AnimationFunctionROMSpec TradingCardLarge17Animation =
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

AnimationFunctionROMSpec TradingCardLarge18Animation =
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

AnimationFunctionROMSpec TradingCardLarge19Animation =
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

AnimationFunctionROMSpec TradingCardLarge20Animation =
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

AnimationFunctionROMSpec TradingCardLarge21Animation =
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

AnimationFunctionROMSpec TradingCardLarge22Animation =
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

AnimationFunctionROMSpec TradingCardLarge23Animation =
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

AnimationFunctionROMSpec TradingCardLarge24Animation =
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

AnimationFunctionROMSpec TradingCardLarge25Animation =
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

AnimationFunctionROMSpec TradingCardLarge26Animation =
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

AnimationFunctionROMSpec TradingCardLarge27Animation =
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

AnimationFunctionROMSpec TradingCardLarge28Animation =
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

AnimationFunctionROMSpec TradingCardLarge29Animation =
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

AnimationFunctionROMSpec TradingCardLarge30Animation =
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

AnimationFunctionROMSpec TradingCardLarge31Animation =
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

AnimationFunctionROMSpec* const TradingCardLargeAnimation[] =
{
	(AnimationFunction*)&TradingCardLarge0Animation,
	(AnimationFunction*)&TradingCardLarge1Animation,
	(AnimationFunction*)&TradingCardLarge2Animation,
	(AnimationFunction*)&TradingCardLarge3Animation,
	(AnimationFunction*)&TradingCardLarge4Animation,
	(AnimationFunction*)&TradingCardLarge5Animation,
	(AnimationFunction*)&TradingCardLarge6Animation,
	(AnimationFunction*)&TradingCardLarge7Animation,
	(AnimationFunction*)&TradingCardLarge8Animation,
	(AnimationFunction*)&TradingCardLarge9Animation,
	(AnimationFunction*)&TradingCardLarge10Animation,
	(AnimationFunction*)&TradingCardLarge11Animation,
	(AnimationFunction*)&TradingCardLarge12Animation,
	(AnimationFunction*)&TradingCardLarge13Animation,
	(AnimationFunction*)&TradingCardLarge14Animation,
	(AnimationFunction*)&TradingCardLarge15Animation,
	(AnimationFunction*)&TradingCardLarge16Animation,
	(AnimationFunction*)&TradingCardLarge17Animation,
	(AnimationFunction*)&TradingCardLarge18Animation,
	(AnimationFunction*)&TradingCardLarge19Animation,
	(AnimationFunction*)&TradingCardLarge20Animation,
	(AnimationFunction*)&TradingCardLarge21Animation,
	(AnimationFunction*)&TradingCardLarge22Animation,
	(AnimationFunction*)&TradingCardLarge23Animation,
	(AnimationFunction*)&TradingCardLarge24Animation,
	(AnimationFunction*)&TradingCardLarge25Animation,
	(AnimationFunction*)&TradingCardLarge26Animation,
	(AnimationFunction*)&TradingCardLarge27Animation,
	(AnimationFunction*)&TradingCardLarge28Animation,
	(AnimationFunction*)&TradingCardLarge29Animation,
	(AnimationFunction*)&TradingCardLarge30Animation,
	(AnimationFunction*)&TradingCardLarge31Animation,
    NULL,
};

CharSetROMSpec TradingCardLargeBaseCharset =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	148,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char spec
	TradingCardLargeBaseTiles,

	// pointer to the frames offsets
	TradingCardLargeBaseTilesFrameOffsets,
};

TextureROMSpec TradingCardLargeBaseTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardLargeBaseCharset,

	// bgmap spec
	TradingCardLargeBaseMap,

	// cols (max 64)
	10,

	// rows (max 64)
	15,

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

BgmapSpriteROMSpec TradingCardLargeBaseSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardLargeBaseTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, -1, -2},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

CharSetROMSpec TradingCardLargeOverlayCharset =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	150,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char spec
	TradingCardLargeOverlayTiles,

	// pointer to the frames offsets
	TradingCardLargeOverlayTilesFrameOffsets,
};

TextureROMSpec TradingCardLargeOverlayTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardLargeOverlayCharset,

	// bgmap spec
	TradingCardLargeOverlayMap,

	// cols (max 64)
	10,

	// rows (max 64)
	15,

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

BgmapSpriteROMSpec TradingCardLargeOverlaySprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardLargeOverlayTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{0, 0, -2, -2},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const TradingCardLargeSprites[] =
{
	&TradingCardLargeBaseSprite,
	&TradingCardLargeOverlaySprite,
	NULL
};

PositionedEntityROMSpec TradingCardLargeChildrenEntities[] =
{
	{&TradingCardLargeBlackEntity, {0, 0, 0, 0}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0, 0}, 0, NULL, NULL, NULL, true},
};

AnimatedEntityROMSpec TradingCardLargeEntity =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// children
		(PositionedEntity*)TradingCardLargeChildrenEntities,

		// behaviors
		NULL,

		// extra
		NULL,

		// sprites
		(SpriteSpec**)TradingCardLargeSprites,

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
	(const AnimationFunction**)&TradingCardLargeAnimation,

	// initial animation
	"0",
};
