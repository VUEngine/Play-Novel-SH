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

extern uint32 SaveSlotLabelActorSaveSlotLabelTiles[];
extern uint16 SaveSlotLabelActorSaveSlotLabelMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec SaveSlotLabelAnimation1AnimationSpec =
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
	"Default",
};

AnimationFunctionROMSpec SaveSlotLabelAnimation2AnimationSpec =
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
	true,

	// Animation's name
	"EmptyEN",
};

AnimationFunctionROMSpec SaveSlotLabelAnimation3AnimationSpec =
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
	true,

	// Animation's name
	"EmptyDE",
};

AnimationFunctionROMSpec SaveSlotLabelAnimation4AnimationSpec =
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
	true,

	// Animation's name
	"0",
};

AnimationFunctionROMSpec SaveSlotLabelAnimation5AnimationSpec =
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
	true,

	// Animation's name
	"1",
};

AnimationFunctionROMSpec* SaveSlotLabelAnimationSpecs[] =
{
	(AnimationFunction*)&SaveSlotLabelAnimation1AnimationSpec,
	(AnimationFunction*)&SaveSlotLabelAnimation2AnimationSpec,
	(AnimationFunction*)&SaveSlotLabelAnimation3AnimationSpec,
	(AnimationFunction*)&SaveSlotLabelAnimation4AnimationSpec,
	(AnimationFunction*)&SaveSlotLabelAnimation5AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec SaveSlotLabelSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	16,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	SaveSlotLabelActorSaveSlotLabelTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec SaveSlotLabelSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&SaveSlotLabelSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	SaveSlotLabelActorSaveSlotLabelMap,

	// Horizontal size in tiles of the texture (max. 64)
	8,

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

BgmapSpriteROMSpec SaveSlotLabelSprite1SpriteSpec =
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
			(const AnimationFunction**)SaveSlotLabelAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&SaveSlotLabelSprite1TextureSpec,

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

ComponentSpec* const SaveSlotLabelComponentSpecs[] = 
{
	(ComponentSpec*)&SaveSlotLabelSprite1SpriteSpec,
	NULL
};

ActorROMSpec SaveSlotLabelActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)SaveSlotLabelComponentSpecs,

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
	"Default"
	
};
