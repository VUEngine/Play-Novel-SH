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
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		 0,
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"Default",
};

AnimationFunctionROMSpec SaveSlotLabelEmptyEnglishAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		 1,
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"EmptyEN",
};

AnimationFunctionROMSpec SaveSlotLabelEmptyGermanAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		 2,
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"EmptyDE",
};

AnimationFunctionROMSpec SaveSlotLabelHarryAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		 3,
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"0",
};

AnimationFunctionROMSpec SaveSlotLabelCybilAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{
		 4,
	},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
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
	// Number of chars in function of the number of frames to load at the same time
	16,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	SaveSlotLabelTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec SaveSlotLabelTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&SaveSlotLabelCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	SaveSlotLabelMap,

	// Horizontal size in tiles of the texture (max. 64)
	8,

	// Vertical size in tiles of the texture (max. 64)
	2,

	// padding for affine transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	2,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
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

		// Spec for the texture to display
		(TextureSpec*)&SaveSlotLabelTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, -1},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

	// Pointer to animation functions array
	(const AnimationFunction**)&SaveSlotLabelAnimationSpecs,

	// Animation to play automatically
	"Default",
};

