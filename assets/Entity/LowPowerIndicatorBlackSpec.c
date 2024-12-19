/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <BgmapAnimatedSprite.h>
#include <LowPowerEntity.h>
#include <VIPManager.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 LowPowerIndicatorBlackTiles[];
extern uint16 LowPowerIndicatorBlackMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec LowPowerIndicatorBlackHideAnimationSpec =
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

AnimationFunctionROMSpec LowPowerIndicatorBlackFlashAnimationSpec =
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

AnimationFunctionROMSpec* const LowPowerIndicatorBlackAnimationSpecs[] =
{
	&LowPowerIndicatorBlackHideAnimationSpec,
	&LowPowerIndicatorBlackFlashAnimationSpec,
	NULL,
};

CharSetROMSpec LowPowerIndicatorBlackCharSetSpec =
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

TextureROMSpec LowPowerIndicatorBlackTextureSpec =
{
	// charset spec
	(CharSetSpec*)&LowPowerIndicatorBlackCharSetSpec,

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

BgmapSpriteROMSpec LowPowerIndicatorBlackSpriteSpec =
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
		(TextureSpec*)&LowPowerIndicatorBlackTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

const ComponentSpec* LowPowerIndicatorBlackEntityComponentSpecs[] = 
{
	(ComponentSpec*)&LowPowerIndicatorBlackSpriteSpec,
	NULL
};

LowPowerEntityROMSpec LowPowerIndicatorBlackEntitySpec =
{
	// animated entity
	{
		// entity
		{
			// Class allocator			
			__TYPE(LowPowerEntity),

			// Component specs
			(ComponentSpec**)LowPowerIndicatorBlackEntityComponentSpecs,

			// Children specs
			NULL,

			// Extra info
			NULL,

			

			
				
			

			

			// Size
			// If 0, it is computed from the visual components if any
			{0, 0, 0},

			// In-game entity's type
			kTypeNone,

			
		},

		// pointer to the animation spec for the item
		(const AnimationFunction**)LowPowerIndicatorBlackAnimationSpecs,

		// initial animation
		"Hide",
	}
};
