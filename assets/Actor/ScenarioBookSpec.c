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
#include <BgmapAnimatedSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 ScenarioBookBaseTiles[];
extern uint32 ScenarioBookBaseTilesFrameOffsets[];
extern uint16 ScenarioBookBaseMap[];
extern uint32 ScenarioBookOverlayTiles[];
extern uint32 ScenarioBookOverlayTilesFrameOffsets[];
extern uint16 ScenarioBookOverlayMap[];
extern ActorSpec ScenarioBookBlackActorSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec ScenarioBookHarryAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 1 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"0",
};

AnimationFunctionROMSpec ScenarioBookCybilAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{ 0 },

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"1",
};

AnimationFunctionROMSpec* const ScenarioBookAnimationSpecs[] =
{
	(AnimationFunction*)&ScenarioBookHarryAnimationSpec,
	(AnimationFunction*)&ScenarioBookCybilAnimationSpec,
	NULL,
};

CharSetROMSpec ScenarioBookBaseCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	204,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	ScenarioBookBaseTiles,

	// Frame offsets array
	ScenarioBookBaseTilesFrameOffsets,
};

TextureROMSpec ScenarioBookBaseTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&ScenarioBookBaseCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	ScenarioBookBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	13,

	// Vertical size in tiles of the texture (max. 64)
	16,

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

BgmapSpriteROMSpec ScenarioBookBaseSpriteSpec =
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
		(TextureSpec*)&ScenarioBookBaseTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, -1, -2},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

CharSetROMSpec ScenarioBookOverlayCharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	208,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	ScenarioBookOverlayTiles,

	// Frame offsets array
	ScenarioBookOverlayTilesFrameOffsets,
};

TextureROMSpec ScenarioBookOverlayTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&ScenarioBookOverlayCharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	ScenarioBookOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	13,

	// Vertical size in tiles of the texture (max. 64)
	16,

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

BgmapSpriteROMSpec ScenarioBookOverlaySpriteSpec =
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
		(TextureSpec*)&ScenarioBookOverlayTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// Displacement added to the sprite's position
		{0, 0, -2, -2},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

PositionedActorROMSpec ScenarioBookChildrenActors[] =
{
	{&ScenarioBookBlackActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
};

ComponentSpec* const ScenarioBookActorComponentSpecs[] = 
{
	(ComponentSpec*)&ScenarioBookBaseSpriteSpec,
	(ComponentSpec*)&ScenarioBookOverlaySpriteSpec,
	NULL
};

ActorROMSpec ScenarioBookActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)ScenarioBookActorComponentSpecs,

	// Children specs
	(PositionedActor*)ScenarioBookChildrenActors,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	0,

	// Pointer to animation functions array
	(const AnimationFunction**)&ScenarioBookAnimationSpecs,

	// Animation to play automatically
	"0",
};
