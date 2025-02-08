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

extern uint32 IntroActorIntro00001LTiles[];
extern uint16 IntroActorIntro00001LMap[];
extern uint32 IntroActorIntro00001LTilesFrameOffsets[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec IntroAnimation1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	148,

	// Frames to play in animation
	{
		135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 
		135, 135, 0, 1, 2, 3, 4, 5, 6, 7, 
		8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
		18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 
		28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 
		38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 
		58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 
		68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 
		78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 
		88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 
		98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 
		108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 
		118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 
		128, 129, 130, 131, 132, 133, 134, 135, 
	},

	// Number of cycles a frame of animation is displayed
	3,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"Default",
};

AnimationFunctionROMSpec* IntroAnimationSpecs[] =
{
	(AnimationFunction*)&IntroAnimation1AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec IntroSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	581,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	IntroActorIntro00001LTiles,

	// Frame offsets array
	IntroActorIntro00001LTilesFrameOffsets
};

TextureROMSpec IntroSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&IntroSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	IntroActorIntro00001LMap,

	// Horizontal size in tiles of the texture (max. 64)
	30,

	// Vertical size in tiles of the texture (max. 64)
	20,

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

BgmapSpriteROMSpec IntroSprite1SpriteSpec =
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
			(const AnimationFunction**)IntroAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&IntroSprite1TextureSpec,

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

ComponentSpec* const IntroComponentSpecs[] = 
{
	(ComponentSpec*)&IntroSprite1SpriteSpec,
	NULL
};

ActorROMSpec IntroActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)IntroComponentSpecs,

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
