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

extern uint32 SaveSlotBorderTiles[];
extern uint16 SaveSlotBorderMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec SaveSlotBorderDefaultAnimationSpec =
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

AnimationFunctionROMSpec* const SaveSlotBorderAnimationSpecs[] =
{
	(AnimationFunction*)&SaveSlotBorderDefaultAnimationSpec,
    NULL,
};

CharSetROMSpec SaveSlotBorderCharSetSpec =
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

TextureROMSpec SaveSlotBorderTextureSpec =
{
	// charset spec
	(CharSetSpec*)&SaveSlotBorderCharSetSpec,

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

BgmapSpriteROMSpec SaveSlotBorderSpriteSpec =
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
		(TextureSpec*)&SaveSlotBorderTextureSpec,

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

ComponentSpec* const SaveSlotBorderEntityComponentSpecs[] = 
{
	(ComponentSpec*)&SaveSlotBorderSpriteSpec,
	NULL
};

AnimatedEntityROMSpec SaveSlotBorderEntitySpec =
{
	{
		// Class allocator		
		__TYPE(AnimatedEntity),

		// Component specs
		(ComponentSpec**)SaveSlotBorderEntityComponentSpecs,

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
	(const AnimationFunction**)&SaveSlotBorderAnimationSpecs,

	// initial animation
	"Default",
};
