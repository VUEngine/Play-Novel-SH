////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <BgmapSprite.h>
#include <InGameTypes.h>
#include <Texture.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 FlaurosActorFlaurosBlackTiles[];
extern uint16 FlaurosActorFlaurosBlackMap[];

extern uint32 FlaurosActorFlaurosBaseTiles[];
extern uint16 FlaurosActorFlaurosBaseMap[];

extern uint32 FlaurosActorFlaurosOverlayTiles[];
extern uint16 FlaurosActorFlaurosOverlayMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec FlaurosAnimation1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	7,

	// Frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 
	},

	// Number of cycles a frame of animation is displayed
	4,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"Spin",
};

AnimationFunctionROMSpec* FlaurosAnimationSpecs[] =
{
	(AnimationFunction*)&FlaurosAnimation1AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec FlaurosSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	4,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	FlaurosActorFlaurosBlackTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec FlaurosSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&FlaurosSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	FlaurosActorFlaurosBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	2,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec FlaurosSprite1SpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)FlaurosAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&FlaurosSprite1TextureSpec,

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
};


CharSetROMSpec FlaurosSprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	4,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	FlaurosActorFlaurosBaseTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec FlaurosSprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&FlaurosSprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	FlaurosActorFlaurosBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	2,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec FlaurosSprite2SpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)FlaurosAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&FlaurosSprite2TextureSpec,

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
};


CharSetROMSpec FlaurosSprite3CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	4,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	FlaurosActorFlaurosOverlayTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec FlaurosSprite3TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&FlaurosSprite3CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	FlaurosActorFlaurosOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	2,

	// Vertical size in tiles of the texture (max. 64)
	2,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec FlaurosSprite3SpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)FlaurosAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&FlaurosSprite3TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_ODD,

		// Displacement added to the sprite's position
		{0, 0, 0, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const FlaurosComponentSpecs[] = 
{
	(ComponentSpec*)&FlaurosSprite1SpriteSpec,
	(ComponentSpec*)&FlaurosSprite2SpriteSpec,
	(ComponentSpec*)&FlaurosSprite3SpriteSpec,
	NULL
};

ActorROMSpec FlaurosActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)FlaurosComponentSpecs,

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
	"Spin"
	
};
