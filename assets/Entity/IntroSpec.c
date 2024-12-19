/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <AnimatedEntityExtensions.h>
#include <BgmapAnimatedSprite.h>
#include <Libgccvb.h>
#include <VIPManager.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 IntroTiles[];
extern uint32 IntroTilesFrameOffsets[];
extern uint16 IntroMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec IntroDefaultAnimationSpec =
{
	// number of frames of this animation function
	160,

	// frames to play in animation
	{
		135, 135, 135, 135,  
		135, 135, 135, 135, 135, 135, 135, 135, 135, 135,
		135, 135, 135, 135, 135, 135, 135, 135, 135, 135,
		  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
		 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,
		 20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
		 30,  31,  32,  33,  34,  35,  36,  37,  38,  39,
		 40,  41,  42,  43,  44,  45,  46,  47,  48,  49,
		 50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
		 60,  61,  62,  63,  64,  65,  66,  67,  68,  69,
		 70,  71,  72,  73,  74,  75,  76,  77,  78,  79,
		 80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
		 90,  91,  92,  93,  94,  95,  96,  97,  98,  99,
		100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
		110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
		120, 121, 122, 123, 124, 125, 126, 127, 128, 129,
		130, 131, 132, 133, 134, 135, 
	},

	// number of cycles a frame of animation is displayed
	3,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	(EventListener)AnimatedEntity_onIntroDefaultAnimationComplete,

	// function's name
	"Default",
};

AnimationFunctionROMSpec* const IntroAnimationSpecs[] =
{
	(AnimationFunction*)&IntroDefaultAnimationSpec,
    NULL,
};

CharSetROMSpec IntroCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	581,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	IntroTiles,

	// pointer to the frames offsets
	IntroTilesFrameOffsets,
};

TextureROMSpec IntroTextureSpec =
{
	// charset spec
	(CharSetSpec*)&IntroCharSetSpec,

	// bgmap spec
	IntroMap,

	// cols (max 64)
	30,

	// rows (max 64)
	20,

	// padding for affine transformations
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec IntroSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&IntroTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

const ComponentSpec* IntroEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)&IntroSpriteSpec,
	NULL
};

AnimatedEntityROMSpec IntroEntitySpec =
{
	{
		// class allocator		
		__TYPE(AnimatedEntity),

		// Components
		(ComponentSpec**)IntroEntitySpecComponentSpecs,

		// children
		NULL,

		// extra
		NULL,

		

		
			
		

		

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		0,

		
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&IntroAnimationSpecs,

	// initial animation
	"Default",
};
