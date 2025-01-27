/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <LocalizedActor.h>
#include <Actor.h>
#include <VIPManager.h>
#include <BgmapSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 MainMenuMobileTiles[];
extern uint16 MainMenuMobileMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec OptionsMainMenuMobileDefaultEnglishAnimationSpec =
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


	// Animation's name
	"0",
};

AnimationFunctionROMSpec OptionsMainMenuMobileBlinkEnglishAnimationSpec =
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


	// Animation's name
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
	// Number of chars in function of the number of frames to load at the same time
	16,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	MainMenuMobileTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec OptionsMainMenuMobileTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&OptionsMainMenuMobileCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	MainMenuMobileMap,

	// Horizontal size in tiles of the texture (max. 64)
	8,

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

BgmapSpriteROMSpec OptionsMainMenuMobileSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// Is animated?
		true,

		// Spec for the texture to display
		(TextureSpec*)&OptionsMainMenuMobileTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const OptionsMainMenuMobileActorComponentSpecs[] = 
{
	(ComponentSpec*)&OptionsMainMenuMobileSpriteSpec,
	NULL
};

LocalizedActorROMSpec OptionsMainMenuMobileActorSpec =
{
	// Animated actor
	{
		// actor
		// Class allocator
		__TYPE(LocalizedActor),

		// Component specs
		(ComponentSpec**)OptionsMainMenuMobileActorComponentSpecs,

		// Children specs
		NULL,

		// Extra info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Actor's in-game type
		kTypeNone,

		// Pointer to animation functions array
		(const AnimationFunction**)&OptionsMainMenuMobileAnimationSpecs,

		// Animation to play automatically
		"0"
	}
};
