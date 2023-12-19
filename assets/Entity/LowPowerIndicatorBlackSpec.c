/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <LowPowerEntity.h>
#include <VIPManager.h>
#include <GuiBgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 LowPowerIndicatorBlackTiles[];
extern uint16 LowPowerIndicatorBlackMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec LowPowerIndicatorBlackHideAnimation =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{
		0,
	},

	// number of cycles a frame of animation is displayed
	4,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"Hide",
};

AnimationFunctionROMSpec LowPowerIndicatorBlackFlashAnimation =
{
	// number of frames of this animation function
	12,

	// frames to play in animation
	{
		0, 0, 0, 0, 3, 2, 1, 1, 1, 1, 2, 3,
	},

	// number of cycles a frame of animation is displayed
	4,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Flash",
};

AnimationFunctionROMSpec* const LowPowerIndicatorBlackAnimations[] =
{
	&LowPowerIndicatorBlackHideAnimation,
	&LowPowerIndicatorBlackFlashAnimation,
	NULL,
};

CharSetROMSpec LowPowerIndicatorBlackCharset =
{
	// number of chars in function of the number of frames to load at the same time
	2,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	LowPowerIndicatorBlackTiles,

	// pointer to the frames offsets
	NULL
};

TextureROMSpec LowPowerIndicatorBlackTexture =
{
	// charset spec
	(CharSetSpec*)&LowPowerIndicatorBlackCharset,

	// bgmap spec
	LowPowerIndicatorBlackMap,

	// cols (max 64)
	2,

	// rows (max 64)
	1,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	2,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec LowPowerIndicatorBlackSprite =
{
	{
		// sprite's type
		__TYPE(GuiBgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&LowPowerIndicatorBlackTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const LowPowerIndicatorBlackSprites[] =
{
	&LowPowerIndicatorBlackSprite,
	NULL
};

LowPowerEntityROMSpec LowPowerIndicatorBlackEntity =
{
	{
		// class allocator
		__TYPE(LowPowerEntity),

		// children
		NULL,

		// behaviors
		NULL,

		// extra
		NULL,

		// sprites
		(SpriteSpec**)LowPowerIndicatorBlackSprites,

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
		kTypeNone,

		// physical specification
		(PhysicalProperties*)NULL,
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)LowPowerIndicatorBlackAnimations,

	// initial animation
	"Hide",
};
