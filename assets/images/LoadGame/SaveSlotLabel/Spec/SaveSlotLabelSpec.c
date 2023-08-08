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

extern uint32 SaveSlotLabelTiles[];
extern uint32 SaveSlotLabelTilesFrameOffsets[];
extern uint16 SaveSlotLabelMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec SaveSlotLabelNoneAnimation =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{
		 0,
	},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"Default",
};

AnimationFunctionROMSpec SaveSlotLabelEmptyEnglishAnimation =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{
		 1,
	},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"EmptyEN",
};

AnimationFunctionROMSpec SaveSlotLabelEmptyGermanAnimation =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{
		 2,
	},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"EmptyDE",
};

AnimationFunctionROMSpec SaveSlotLabelHarryAnimation =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{
		 3,
	},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"0",
};

AnimationFunctionROMSpec SaveSlotLabelCybilAnimation =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{
		 4,
	},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"1",
};

AnimationFunctionROMSpec* const SaveSlotLabelAnimation[] =
{
    (AnimationFunction*)&SaveSlotLabelNoneAnimation,
    (AnimationFunction*)&SaveSlotLabelEmptyEnglishAnimation,
    (AnimationFunction*)&SaveSlotLabelEmptyGermanAnimation,
    (AnimationFunction*)&SaveSlotLabelHarryAnimation,
    (AnimationFunction*)&SaveSlotLabelCybilAnimation,
    NULL,
};

CharSetROMSpec SaveSlotLabelCharset =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	16,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE,

	// char spec
	SaveSlotLabelTiles,

	// pointer to the frames offsets
	SaveSlotLabelTilesFrameOffsets,
};

TextureROMSpec SaveSlotLabelTexture =
{
	// charset spec
	(CharSetSpec*)&SaveSlotLabelCharset,

	// bgmap spec
	SaveSlotLabelMap,

	// cols (max 64)
	8,

	// rows (max 64)
	2,

	// padding for affine transformations
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
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

BgmapSpriteROMSpec SaveSlotLabelSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&SaveSlotLabelTexture,

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

BgmapSpriteROMSpec* const SaveSlotLabelSprites[] =
{
	&SaveSlotLabelSprite,
	NULL
};

AnimatedEntityROMSpec SaveSlotLabelEntity =
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
		(SpriteSpec**)SaveSlotLabelSprites,

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
	(const AnimationFunction**)&SaveSlotLabelAnimation,

	// initial animation
	"Default",
};

