/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Libgccvb.h>
#include <AnimatedEntity.h>
#include <VIPManager.h>
#include <BgmapAnimatedSprite.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 FlaurosBlackTiles[];
extern uint16 FlaurosBlackMap[];
extern uint32 FlaurosBaseTiles[];
extern uint16 FlaurosBaseMap[];
extern uint32 FlaurosOverlayTiles[];
extern uint16 FlaurosOverlayMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec FlaurosDefaultAnimationSpec =
{
	// number of frames of this animation function
	7,

	// frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6
	},

	// number of cycles a frame of animation is displayed
	4,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Default",
};

AnimationFunctionROMSpec* const FlaurosAnimationSpecs[] =
{
	(AnimationFunction*)&FlaurosDefaultAnimationSpec,
    NULL,
};

CharSetROMSpec FlaurosBlackCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	FlaurosBlackTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec FlaurosBlackTextureSpec =
{
	// charset spec
	(CharSetSpec*)&FlaurosBlackCharSetSpec,

	// bgmap spec
	FlaurosBlackMap,

	// cols (max 64)
	2,

	// rows (max 64)
	2,

	// padding for affine transformations
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	1,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec FlaurosBlackSpriteSpec =
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
		(TextureSpec*)&FlaurosBlackTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, -5, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

CharSetROMSpec FlaurosBaseCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	FlaurosBaseTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec FlaurosBaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&FlaurosBaseCharSetSpec,

	// bgmap spec
	FlaurosBaseMap,

	// cols (max 64)
	2,

	// rows (max 64)
	2,

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

BgmapSpriteROMSpec FlaurosBaseSpriteSpec =
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
		(TextureSpec*)&FlaurosBaseTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, -6, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

CharSetROMSpec FlaurosOverlayCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	FlaurosOverlayTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec FlaurosOverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&FlaurosOverlayCharSetSpec,

	// bgmap spec
	FlaurosOverlayMap,

	// cols (max 64)
	2,

	// rows (max 64)
	2,

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

BgmapSpriteROMSpec FlaurosOverlaySpriteSpec =
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
		(TextureSpec*)&FlaurosOverlayTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{0, 0, -6, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

ComponentSpec* const FlaurosEntityComponentSpecs[] = 
{
	//(ComponentSpec*)&FlaurosBlackSpriteSpec,
	(ComponentSpec*)&FlaurosBaseSpriteSpec,
	(ComponentSpec*)&FlaurosOverlaySpriteSpec,
	NULL
};

AnimatedEntityROMSpec FlaurosEntitySpec =
{
	{
		// Class allocator		
		__TYPE(AnimatedEntity),

		// Component specs
		(ComponentSpec**)FlaurosEntityComponentSpecs,

		// Children specs
		NULL,

		// Extra info
		NULL,

		

		
			
		

		

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		0,

		
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&FlaurosAnimationSpecs,

	// initial animation
	"Default",
};
