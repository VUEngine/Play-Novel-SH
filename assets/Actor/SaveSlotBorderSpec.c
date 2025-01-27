/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <LibVUEngine.h>
#include <Actor.h>
#include <VIPManager.h>
#include <BgmapSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 SaveSlotBorderTiles[];
extern uint16 SaveSlotBorderMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec SaveSlotBorderDefaultAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	26,

	// Frames to play in animation
	{
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
	},

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	true,


	// Animation's name
	"Default",
};

AnimationFunctionROMSpec* const SaveSlotBorderAnimationSpecs[] =
{
	(AnimationFunction*)&SaveSlotBorderDefaultAnimationSpec,
	NULL,
};

CharSetROMSpec SaveSlotBorderCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	240,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	SaveSlotBorderTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec SaveSlotBorderTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&SaveSlotBorderCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	SaveSlotBorderMap,

	// Horizontal size in tiles of the texture (max. 64)
	40,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding for affine transformations
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

BgmapSpriteROMSpec SaveSlotBorderSpriteSpec =
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
		(TextureSpec*)&SaveSlotBorderTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, -1},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const SaveSlotBorderActorComponentSpecs[] = 
{
	(ComponentSpec*)&SaveSlotBorderSpriteSpec,
	NULL
};

ActorROMSpec SaveSlotBorderActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)SaveSlotBorderActorComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	0,

	// Pointer to animation functions array
	(const AnimationFunction**)&SaveSlotBorderAnimationSpecs,

	// Animation to play automatically
	"Default",
};
