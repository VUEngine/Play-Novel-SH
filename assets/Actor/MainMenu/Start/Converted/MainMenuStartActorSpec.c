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

extern uint32 MainMenuStartActorMainMenuStartTiles[];
extern uint16 MainMenuStartActorMainMenuStartMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec MainMenuStartAnimation1AnimationSpec =
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
	true,

	// Animation's name
	"0",
};

AnimationFunctionROMSpec MainMenuStartAnimation2AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	30,

	// Frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
		10, 11, 12, 12, 11, 10, 9, 8, 7, 6, 
		5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 
	},

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"10",
};

AnimationFunctionROMSpec* MainMenuStartAnimationSpecs[] =
{
	(AnimationFunction*)&MainMenuStartAnimation1AnimationSpec,
	(AnimationFunction*)&MainMenuStartAnimation2AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec MainMenuStartSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	14,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	MainMenuStartActorMainMenuStartTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec MainMenuStartSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&MainMenuStartSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	MainMenuStartActorMainMenuStartMap,

	// Horizontal size in tiles of the texture (max. 64)
	7,

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

BgmapSpriteROMSpec MainMenuStartSprite1SpriteSpec =
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
			(const AnimationFunction**)MainMenuStartAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&MainMenuStartSprite1TextureSpec,

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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const MainMenuStartComponentSpecs[] = 
{
	(ComponentSpec*)&MainMenuStartSprite1SpriteSpec,
	NULL
};

ActorROMSpec MainMenuStartActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)MainMenuStartComponentSpecs,

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
