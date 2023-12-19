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

extern uint32 SaveSlotBorderTiles[];
extern uint16 SaveSlotBorderMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec SaveSlotBorderDefaultAnimation =
{
	// number of frames of this animation function
	26,

	// frames to play in animation
	{
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
	},

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Default",
};

AnimationFunctionROMSpec* const SaveSlotBorderAnimation[] =
{
    (AnimationFunction*)&SaveSlotBorderDefaultAnimation,
    NULL,
};

CharSetROMSpec SaveSlotBorderCharset =
{
	// number of chars in function of the number of frames to load at the same time
	240,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	SaveSlotBorderTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec SaveSlotBorderTexture =
{
	// charset spec
	(CharSetSpec*)&SaveSlotBorderCharset,

	// bgmap spec
	SaveSlotBorderMap,

	// cols (max 64)
	40,

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

BgmapSpriteROMSpec SaveSlotBorderSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&SaveSlotBorderTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, -1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const SaveSlotBorderSprites[] =
{
	&SaveSlotBorderSprite,
	NULL
};

AnimatedEntityROMSpec SaveSlotBorderEntity =
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
		(SpriteSpec**)SaveSlotBorderSprites,

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
	(const AnimationFunction**)&SaveSlotBorderAnimation,

	// initial animation
	"Default",
};
