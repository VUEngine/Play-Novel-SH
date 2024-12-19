/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Libgccvb.h>
#include <AnimatedEntity.h>
#include <VIPManager.h>
#include <BgmapAnimatedSprite.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 TradingCardsBackgroundNumbersTiles[];
extern uint32 TradingCardsBackgroundNumbersTilesFrameOffsets[];
extern uint16 TradingCardsBackgroundNumbersMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec TradingCardsBackgroundNumbers0AnimationSpec =
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

AnimationFunctionROMSpec TradingCardsBackgroundNumbers1AnimationSpec =
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

AnimationFunctionROMSpec TradingCardsBackgroundNumbers2AnimationSpec =
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

AnimationFunctionROMSpec TradingCardsBackgroundNumbers3AnimationSpec =
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
	// number of chars in function of the number of frames to load at the same time
	51,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	TradingCardsBackgroundNumbersTiles,

	// pointer to the frames offsets
	TradingCardsBackgroundNumbersTilesFrameOffsets,
};

TextureROMSpec TradingCardsBackgroundNumbersTextureSpec =
{
	// charset spec
	(CharSetSpec*)&TradingCardsBackgroundNumbersCharSetSpec,

	// bgmap spec
	TradingCardsBackgroundNumbersMap,

	// cols (max 64)
	40,

	// rows (max 64)
	10,

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

BgmapSpriteROMSpec TradingCardsBackgroundNumbersSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&TradingCardsBackgroundNumbersTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

@COMP_ARRAY_START:TradingCardsBackgroundNumbersSpriteSpecs
	&TradingCardsBackgroundNumbersSpriteSpec,
	
@COMP_ARRAY_END:TradingCardsBackgroundNumbersSpriteSpecs

const ComponentSpec* TradingCardsBackgroundNumbersEntitySpecComponentSpecs[] = 
{
	
    (ComponentSpec*)TradingCardsBackgroundNumbersSpriteSpec,

};

AnimatedEntityROMSpec TradingCardsBackgroundNumbersEntitySpec =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// children
		NULL,

		(ComponentSpec**)TradingCardsBackgroundNumbersEntitySpecComponentSpecs,

		// extra
		NULL,

		

		// use z displacement in projection
		false,
			
		

		

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		0,

		
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&TradingCardsBackgroundNumbersAnimationSpecs,

	// initial animation
	"0",
};
