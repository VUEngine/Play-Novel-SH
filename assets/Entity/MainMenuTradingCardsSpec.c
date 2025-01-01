/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <LocalizedEntity.h>
#include <VIPManager.h>
#include <BgmapAnimatedSprite.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 MainMenuTradingCardsTiles[];
extern uint16 MainMenuTradingCardsMap[];


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec OptionsMainMenuTradingCardsDefaultEnglishAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		0,
	},

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"0",
};

AnimationFunctionROMSpec OptionsMainMenuTradingCardsBlinkEnglishAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	30,

	// Frames to play in animation
	{
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,
		 0,  0,  0,  0,  
	},

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	true,

	// Callback on animation completion
	NULL,

	// Animation's name
	"10",
};

// an animation spec
AnimationFunctionROMSpec* const OptionsMainMenuTradingCardsAnimationSpecs[] =
{
	(AnimationFunction*)&OptionsMainMenuTradingCardsDefaultEnglishAnimationSpec,
	(AnimationFunction*)&OptionsMainMenuTradingCardsBlinkEnglishAnimationSpec,
    NULL,
};

CharSetROMSpec OptionsMainMenuTradingCardsCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	32,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	MainMenuTradingCardsTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec OptionsMainMenuTradingCardsTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&OptionsMainMenuTradingCardsCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	MainMenuTradingCardsMap,

	// Horizontal size in tiles of the texture (max. 64)
	16,

	// Vertical size in tiles of the texture (max. 64)
	2,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

BgmapSpriteROMSpec OptionsMainMenuTradingCardsSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&OptionsMainMenuTradingCardsTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

ComponentSpec* const OptionsMainMenuTradingCardsEntityComponentSpecs[] = 
{
	(ComponentSpec*)&OptionsMainMenuTradingCardsSpriteSpec,
	NULL
};

LocalizedEntityROMSpec OptionsMainMenuTradingCardsEntitySpec =
{
	// animated entity
	{
		// entity
		{
			// Class allocator			
			__TYPE(LocalizedEntity),

			// Component specs
			(ComponentSpec**)OptionsMainMenuTradingCardsEntityComponentSpecs,

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

		// Pointer to animation functions array
		(const AnimationFunction**)&OptionsMainMenuTradingCardsAnimationSpecs,

		// Animation to play automatically
		"0"
	}
};
