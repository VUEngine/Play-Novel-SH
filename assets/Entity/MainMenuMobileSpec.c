/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <LocalizedEntity.h>
#include <Actor.h>
#include <VIPManager.h>
#include <BgmapAnimatedSprite.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 MainMenuMobileTiles[];
extern uint16 MainMenuMobileMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec OptionsMainMenuMobileDefaultEnglishAnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{
		0,
	},

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"0",
};

AnimationFunctionROMSpec OptionsMainMenuMobileBlinkEnglishAnimationSpec =
{
	// number of frames of this animation function
	30,

	// frames to play in animation
	{
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,
		 0,  0,  0,  0,  
	},

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"10",
};

// an animation spec
AnimationFunctionROMSpec* const OptionsMainMenuMobileAnimationSpecs[] =
{
	(AnimationFunction*)&OptionsMainMenuMobileDefaultEnglishAnimationSpec,
	(AnimationFunction*)&OptionsMainMenuMobileBlinkEnglishAnimationSpec,
    NULL,
};

CharSetROMSpec OptionsMainMenuMobileCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	16,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	MainMenuMobileTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec OptionsMainMenuMobileTextureSpec =
{
	// charset spec
	(CharSetSpec*)&OptionsMainMenuMobileCharSetSpec,

	// bgmap spec
	MainMenuMobileMap,

	// cols (max 64)
	8,

	// rows (max 64)
	2,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec OptionsMainMenuMobileSpriteSpec =
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
		(TextureSpec*)&OptionsMainMenuMobileTextureSpec,

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

ComponentSpec* const OptionsMainMenuMobileEntityComponentSpecs[] = 
{
	(ComponentSpec*)&OptionsMainMenuMobileSpriteSpec,
	NULL
};

LocalizedEntityROMSpec OptionsMainMenuMobileEntitySpec =
{
	// animated entity
	{
		// entity
		{
			// Class allocator			
			__TYPE(LocalizedEntity),

			// Component specs
			(ComponentSpec**)OptionsMainMenuMobileEntityComponentSpecs,

			// Children specs
			NULL,

			// Extra info
			NULL,

			

			
				
			

			

			// Size
			// If 0, it is computed from the visual components if any
			{0, 0, 0},

			// Entity's in-game type
			kTypeNone,

			
		},

		// pointer to the animation spec for the item
		(const AnimationFunction**)&OptionsMainMenuMobileAnimationSpecs,

		// initial animation
		"0"
	}
};
