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

extern uint32 SaveSlotBorderActorSaveSlotBorderTiles[];
extern uint16 SaveSlotBorderActorSaveSlotBorderMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec SaveSlotBorderAnimation1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	26,

	// Frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
		20, 21, 22, 23, 24, 25, 
	},

	// Number of cycles a frame of animation is displayed
	2,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"Animation",
};

AnimationFunctionROMSpec* SaveSlotBorderAnimationSpecs[] =
{
	(AnimationFunction*)&SaveSlotBorderAnimation1AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec SaveSlotBorderSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	240,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	SaveSlotBorderActorSaveSlotBorderTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec SaveSlotBorderSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&SaveSlotBorderSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	SaveSlotBorderActorSaveSlotBorderMap,

	// Horizontal size in tiles of the texture (max. 64)
	40,

	// Vertical size in tiles of the texture (max. 64)
	6,

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

BgmapSpriteROMSpec SaveSlotBorderSprite1SpriteSpec =
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
			(const AnimationFunction**)SaveSlotBorderAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&SaveSlotBorderSprite1TextureSpec,

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

ComponentSpec* const SaveSlotBorderComponentSpecs[] = 
{
	(ComponentSpec*)&SaveSlotBorderSprite1SpriteSpec,
	NULL
};

ActorROMSpec SaveSlotBorderActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)SaveSlotBorderComponentSpecs,

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
	"Animation"
	
};
