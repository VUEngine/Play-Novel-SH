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

extern uint32 SaveSlotLabelTiles[];
extern uint16 SaveSlotLabelMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec SaveSlotLabelNoneAnimationSpec =
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

AnimationFunctionROMSpec SaveSlotLabelEmptyEnglishAnimationSpec =
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

AnimationFunctionROMSpec SaveSlotLabelEmptyGermanAnimationSpec =
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

AnimationFunctionROMSpec SaveSlotLabelHarryAnimationSpec =
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

AnimationFunctionROMSpec SaveSlotLabelCybilAnimationSpec =
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

AnimationFunctionROMSpec* const SaveSlotLabelAnimationSpecs[] =
{
	(AnimationFunction*)&SaveSlotLabelNoneAnimationSpec,
	(AnimationFunction*)&SaveSlotLabelEmptyEnglishAnimationSpec,
	(AnimationFunction*)&SaveSlotLabelEmptyGermanAnimationSpec,
	(AnimationFunction*)&SaveSlotLabelHarryAnimationSpec,
	(AnimationFunction*)&SaveSlotLabelCybilAnimationSpec,
    NULL,
};

CharSetROMSpec SaveSlotLabelCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	16,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	SaveSlotLabelTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec SaveSlotLabelTextureSpec =
{
	// charset spec
	(CharSetSpec*)&SaveSlotLabelCharSetSpec,

	// bgmap spec
	SaveSlotLabelMap,

	// cols (max 64)
	8,

	// rows (max 64)
	2,

	// padding for affine transformations
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

BgmapSpriteROMSpec SaveSlotLabelSpriteSpec =
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
		(TextureSpec*)&SaveSlotLabelTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

ComponentSpec* const SaveSlotLabelEntityComponentSpecs[] = 
{
	(ComponentSpec*)&SaveSlotLabelSpriteSpec,
	NULL
};

AnimatedEntityROMSpec SaveSlotLabelEntitySpec =
{
	{
		// Class allocator		
		__TYPE(AnimatedEntity),

		// Component specs
		(ComponentSpec**)SaveSlotLabelEntityComponentSpecs,

		// Children specs
		NULL,

		// Extra info
		NULL,

		

		
			
		

		

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		0,

		
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&SaveSlotLabelAnimationSpecs,

	// initial animation
	"Default",
};

