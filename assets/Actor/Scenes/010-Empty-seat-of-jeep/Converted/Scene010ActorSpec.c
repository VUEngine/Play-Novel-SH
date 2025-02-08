////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <FrameBlendBgmapSprite.h>
#include <InGameTypes.h>
#include <Texture.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 Scene010ActorScene010aTiles[];
extern uint16 Scene010ActorScene010aMap[];

extern uint32 Scene010ActorScene010bTiles[];
extern uint16 Scene010ActorScene010bMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec Scene010Sprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	272,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene010ActorScene010aTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene010Sprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene010Sprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene010ActorScene010aMap,

	// Horizontal size in tiles of the texture (max. 64)
	30,

	// Vertical size in tiles of the texture (max. 64)
	20,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	2,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

FrameBlendBgmapSpriteROMSpec Scene010Sprite1SpriteSpec =
{
	{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(FrameBlendBgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene010Sprite1TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 1, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
	}
};


CharSetROMSpec Scene010Sprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	340,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene010ActorScene010bTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene010Sprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene010Sprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene010ActorScene010bMap,

	// Horizontal size in tiles of the texture (max. 64)
	30,

	// Vertical size in tiles of the texture (max. 64)
	20,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	2,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

FrameBlendBgmapSpriteROMSpec Scene010Sprite2SpriteSpec =
{
	{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(FrameBlendBgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene010Sprite2TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
	}
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const Scene010ComponentSpecs[] = 
{
	(ComponentSpec*)&Scene010Sprite1SpriteSpec,
	(ComponentSpec*)&Scene010Sprite2SpriteSpec,
	NULL
};

ActorROMSpec Scene010ActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)Scene010ComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Animation to play automatically
	NULL
	
};
