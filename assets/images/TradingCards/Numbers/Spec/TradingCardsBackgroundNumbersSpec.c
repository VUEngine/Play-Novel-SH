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

extern uint32 TradingCardsBackgroundNumbersTiles[];
extern uint32 TradingCardsBackgroundNumbersTilesFrameOffsets[];
extern uint16 TradingCardsBackgroundNumbersMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec TradingCardsBackgroundNumbers0Animation =
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

AnimationFunctionROMSpec TradingCardsBackgroundNumbers1Animation =
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

AnimationFunctionROMSpec TradingCardsBackgroundNumbers2Animation =
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

AnimationFunctionROMSpec TradingCardsBackgroundNumbers3Animation =
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

AnimationFunctionROMSpec* const TradingCardsBackgroundNumbersAnimation[] =
{
    (AnimationFunction*)&TradingCardsBackgroundNumbers0Animation,
    (AnimationFunction*)&TradingCardsBackgroundNumbers1Animation,
    (AnimationFunction*)&TradingCardsBackgroundNumbers2Animation,
    (AnimationFunction*)&TradingCardsBackgroundNumbers3Animation,
    NULL,
};

CharSetROMSpec TradingCardsBackgroundNumbersCharset =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	51,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char spec
	TradingCardsBackgroundNumbersTiles,

	// pointer to the frames offsets
	TradingCardsBackgroundNumbersTilesFrameOffsets,
};

TextureROMSpec TradingCardsBackgroundNumbersTexture =
{
	// charset spec
	(CharSetSpec*)&TradingCardsBackgroundNumbersCharset,

	// bgmap spec
	TradingCardsBackgroundNumbersMap,

	// cols (max 64)
	40,

	// rows (max 64)
	10,

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

BgmapSpriteROMSpec TradingCardsBackgroundNumbersSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardsBackgroundNumbersTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, -1, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const TradingCardsBackgroundNumbersSprites[] =
{
	&TradingCardsBackgroundNumbersSprite,
	NULL
};

AnimatedEntityROMSpec TradingCardsBackgroundNumbersEntity =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// children
		NULL,

		// behaviors
		NULL,

		// extra
		NULL,

		// sprites
		(SpriteSpec**)TradingCardsBackgroundNumbersSprites,

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
	(const AnimationFunction**)&TradingCardsBackgroundNumbersAnimation,

	// initial animation
	"0",
};