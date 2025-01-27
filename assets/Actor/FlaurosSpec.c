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

extern uint32 FlaurosBlackTiles[];
extern uint16 FlaurosBlackMap[];
extern uint32 FlaurosBaseTiles[];
extern uint16 FlaurosBaseMap[];
extern uint32 FlaurosOverlayTiles[];
extern uint16 FlaurosOverlayMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec FlaurosDefaultAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	7,

	// Frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6
	},

	// Number of cycles a frame of animation is displayed
	4,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"Default",
};

AnimationFunctionROMSpec* const FlaurosAnimationSpecs[] =
{
	(AnimationFunction*)&FlaurosDefaultAnimationSpec,
	NULL,
};

CharSetROMSpec FlaurosBlackCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	FlaurosBlackTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec FlaurosBlackTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&FlaurosBlackCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	FlaurosBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	2,

	// Padding for affine transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	1,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

BgmapSpriteROMSpec FlaurosBlackSpriteSpec =
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
		(TextureSpec*)&FlaurosBlackTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, -5, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

CharSetROMSpec FlaurosBaseCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	FlaurosBaseTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec FlaurosBaseTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&FlaurosBaseCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	FlaurosBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	2,

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

BgmapSpriteROMSpec FlaurosBaseSpriteSpec =
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
		(TextureSpec*)&FlaurosBaseTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, -6, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

CharSetROMSpec FlaurosOverlayCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	FlaurosOverlayTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec FlaurosOverlayTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&FlaurosOverlayCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	FlaurosOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	2,

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

BgmapSpriteROMSpec FlaurosOverlaySpriteSpec =
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
		(TextureSpec*)&FlaurosOverlayTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// Displacement added to the sprite's position
		{0, 0, -6, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const FlaurosActorComponentSpecs[] = 
{
	//(ComponentSpec*)&FlaurosBlackSpriteSpec,
	(ComponentSpec*)&FlaurosBaseSpriteSpec,
	(ComponentSpec*)&FlaurosOverlaySpriteSpec,
	NULL
};

ActorROMSpec FlaurosActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)FlaurosActorComponentSpecs,

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
	(const AnimationFunction**)&FlaurosAnimationSpecs,

	// Animation to play automatically
	"Default",
};
