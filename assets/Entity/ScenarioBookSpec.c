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

extern uint32 ScenarioBookBaseTiles[];
extern uint32 ScenarioBookBaseTilesFrameOffsets[];
extern uint16 ScenarioBookBaseMap[];
extern uint32 ScenarioBookOverlayTiles[];
extern uint32 ScenarioBookOverlayTilesFrameOffsets[];
extern uint16 ScenarioBookOverlayMap[];
extern EntitySpec ScenarioBookBlackEntitySpec;


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec ScenarioBookHarryAnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 1 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"0",
};

AnimationFunctionROMSpec ScenarioBookCybilAnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 0 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
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
	// number of chars in function of the number of frames to load at the same time
	204,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	ScenarioBookBaseTiles,

	// pointer to the frames offsets
	ScenarioBookBaseTilesFrameOffsets,
};

TextureROMSpec ScenarioBookBaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&ScenarioBookBaseCharSetSpec,

	// bgmap spec
	ScenarioBookBaseMap,

	// cols (max 64)
	13,

	// rows (max 64)
	16,

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

		// texture spec
		(TextureSpec*)&ScenarioBookBaseTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, -1, -2},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

CharSetROMSpec ScenarioBookOverlayCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	208,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	ScenarioBookOverlayTiles,

	// pointer to the frames offsets
	ScenarioBookOverlayTilesFrameOffsets,
};

TextureROMSpec ScenarioBookOverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&ScenarioBookOverlayCharSetSpec,

	// bgmap spec
	ScenarioBookOverlayMap,

	// cols (max 64)
	13,

	// rows (max 64)
	16,

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

		// texture spec
		(TextureSpec*)&ScenarioBookOverlayTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{0, 0, -2, -2},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};



PositionedEntityROMSpec ScenarioBookChildrenEntities[] =
{
	{&ScenarioBookBlackEntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
};

const ComponentSpec* ScenarioBookEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)&ScenarioBookBaseSpriteSpec,
    (ComponentSpec*)&ScenarioBookOverlaySpriteSpec,
	NULL
};

AnimatedEntityROMSpec ScenarioBookEntitySpec =
{
	{
		// class allocator		
		__TYPE(AnimatedEntity),

		// Components
		(ComponentSpec**)ScenarioBookEntitySpecComponentSpecs,

		// children
		(PositionedEntity*)ScenarioBookChildrenEntities,

		// extra
		NULL,

		

		
			
		

		

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		0,

		
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&ScenarioBookAnimationSpecs,

	// initial animation
	"0",
};
