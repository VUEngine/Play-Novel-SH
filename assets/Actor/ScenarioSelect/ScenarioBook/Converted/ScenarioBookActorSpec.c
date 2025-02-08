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

extern uint32 ScenarioBookActorScenarioBookBlackLTiles[];
extern uint16 ScenarioBookActorScenarioBookBlackLMap[];
extern uint32 ScenarioBookActorScenarioBookBlackLTilesFrameOffsets[];

extern uint32 ScenarioBookActorScenarioBookCybilBaseLTiles[];
extern uint16 ScenarioBookActorScenarioBookCybilBaseLMap[];
extern uint32 ScenarioBookActorScenarioBookCybilBaseLTilesFrameOffsets[];

extern uint32 ScenarioBookActorScenarioBookCybilOverlayLTiles[];
extern uint16 ScenarioBookActorScenarioBookCybilOverlayLMap[];
extern uint32 ScenarioBookActorScenarioBookCybilOverlayLTilesFrameOffsets[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec ScenarioBookAnimation1AnimationSpec =
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

	// Animation's name
	"0",
};

AnimationFunctionROMSpec ScenarioBookAnimation2AnimationSpec =
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

	// Animation's name
	"1",
};

AnimationFunctionROMSpec* ScenarioBookAnimationSpecs[] =
{
	(AnimationFunction*)&ScenarioBookAnimation1AnimationSpec,
	(AnimationFunction*)&ScenarioBookAnimation2AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec ScenarioBookSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	2,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	ScenarioBookActorScenarioBookBlackLTiles,

	// Frame offsets array
	ScenarioBookActorScenarioBookBlackLTilesFrameOffsets
};

TextureROMSpec ScenarioBookSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&ScenarioBookSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	ScenarioBookActorScenarioBookBlackLMap,

	// Horizontal size in tiles of the texture (max. 64)
	13,

	// Vertical size in tiles of the texture (max. 64)
	8,

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

BgmapSpriteROMSpec ScenarioBookSprite1SpriteSpec =
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
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&ScenarioBookSprite1TextureSpec,

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
};


CharSetROMSpec ScenarioBookSprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	204,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	ScenarioBookActorScenarioBookCybilBaseLTiles,

	// Frame offsets array
	ScenarioBookActorScenarioBookCybilBaseLTilesFrameOffsets
};

TextureROMSpec ScenarioBookSprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&ScenarioBookSprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	ScenarioBookActorScenarioBookCybilBaseLMap,

	// Horizontal size in tiles of the texture (max. 64)
	13,

	// Vertical size in tiles of the texture (max. 64)
	16,

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

BgmapSpriteROMSpec ScenarioBookSprite2SpriteSpec =
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
			(const AnimationFunction**)ScenarioBookAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&ScenarioBookSprite2TextureSpec,

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


CharSetROMSpec ScenarioBookSprite3CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	208,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	ScenarioBookActorScenarioBookCybilOverlayLTiles,

	// Frame offsets array
	ScenarioBookActorScenarioBookCybilOverlayLTilesFrameOffsets
};

TextureROMSpec ScenarioBookSprite3TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&ScenarioBookSprite3CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	ScenarioBookActorScenarioBookCybilOverlayLMap,

	// Horizontal size in tiles of the texture (max. 64)
	13,

	// Vertical size in tiles of the texture (max. 64)
	16,

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

BgmapSpriteROMSpec ScenarioBookSprite3SpriteSpec =
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
			(const AnimationFunction**)ScenarioBookAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&ScenarioBookSprite3TextureSpec,

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

ComponentSpec* const ScenarioBookComponentSpecs[] = 
{
	(ComponentSpec*)&ScenarioBookSprite1SpriteSpec,
	(ComponentSpec*)&ScenarioBookSprite2SpriteSpec,
	(ComponentSpec*)&ScenarioBookSprite3SpriteSpec,
	NULL
};

ActorROMSpec ScenarioBookActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)ScenarioBookComponentSpecs,

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
	"0"
	
};
