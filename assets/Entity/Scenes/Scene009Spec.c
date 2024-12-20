/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Entity.h>
#include <VIPManager.h>
#include <AutoScrollingMBgmapSprite.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 Scene009Tiles[];
extern uint16 Scene009BackgroundBaseMap[];
extern uint16 Scene009BackgroundOverlayMap[];
extern uint16 Scene009CarInteriorMap[];
extern uint16 Scene009Snow1Map[];
extern uint16 Scene009Snow2Map[];
extern uint16 Scene009SeatMap[];
extern uint16 Scene009HarryBlackMap[];
extern uint16 Scene009HarryBaseMap[];
extern uint16 Scene009HarryOverlayMap[];
extern uint16 Scene009SteeringWheelMap[];
extern uint16 Scene009FrameMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

CharSetROMSpec Scene009CharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	507,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	Scene009Tiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec Scene009BackgroundBaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009BackgroundBaseMap,

	// cols (max 64)
	32,

	// rows (max 64)
	12,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009BackgroundBaseSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009BackgroundBaseTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, -32, 8, 4},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009BackgroundOverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009BackgroundOverlayMap,

	// cols (max 64)
	32,

	// rows (max 64)
	12,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009BackgroundOverlaySpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009BackgroundOverlayTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{0, -32, 7, 4},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009Snow1TextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009Snow1Map,

	// cols (max 64)
	64,

	// rows (max 64)
	64,

	// padding for affine/hbias transformations (cols, rows)
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

TextureROMSpec* const Scene009Snow1Textures[] =
{
	(TextureSpec*)&Scene009Snow1TextureSpec,
	NULL
};

AutoScrollingMBgmapSpriteROMSpec Scene009Snow1SpriteSpec =
{
	{
		{
			{
				// Component
				{
					// Allocator
					__TYPE(AutoScrollingMBgmapSprite),

					// Component type
					kSpriteComponent
				},

				// texture spec
				(TextureSpec*)NULL,

				// transparency
				__TRANSPARENCY_NONE,

				// displacement
				{64, 0, 6, 3},
			},

			// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
			__WORLD_BGMAP,

			// pointer to affine/hbias manipulation function
			NULL,

			// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
			__WORLD_ON,
		},

		(TextureSpec**)Scene009Snow1Textures,

		// SCX/SCY (__WORLD_1x1, 1x2, 1x4, 1x8, 2x1, 2x2, 2x4, 4x1, 4x2, or 8x1)
		// textures must be 64x64 for anything other than 1x1
		__WORLD_1x1,

		// x loop
		false,

		// y loop
		true,

		// bounds the sprite's width to provide culling
		// if 0, the value is inferred from the texture
		0,

		// bounds the sprite's height to provide culling
		// if 0, the value is inferred from the texture
		0,
	},

	// scroll delay
	20,
};

TextureROMSpec Scene009Snow2TextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009Snow2Map,

	// cols (max 64)
	64,

	// rows (max 64)
	64,

	// padding for affine/hbias transformations (cols, rows)
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

TextureROMSpec* const Scene009Snow2Textures[] =
{
	(TextureSpec*)&Scene009Snow2TextureSpec,
	NULL
};

AutoScrollingMBgmapSpriteROMSpec Scene009Snow2SpriteSpec =
{
	{
		{
			{
				// Component
				{
					// Allocator
					__TYPE(AutoScrollingMBgmapSprite),

					// Component type
					kSpriteComponent
				},

				// texture spec
				(TextureSpec*)NULL,

				// transparency
				__TRANSPARENCY_NONE,

				// displacement
				{64, 0, 5, 2},
			},

			// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
			__WORLD_BGMAP,

			// pointer to affine/hbias manipulation function
			NULL,

			// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
			__WORLD_ON,
		},

		(TextureSpec**)Scene009Snow2Textures,

		// SCX/SCY (__WORLD_1x1, 1x2, 1x4, 1x8, 2x1, 2x2, 2x4, 4x1, 4x2, or 8x1)
		// textures must be 64x64 for anything other than 1x1
		__WORLD_1x1,

		// x loop
		false,

		// y loop
		true,

		// bounds the sprite's width to provide culling
		// if 0, the value is inferred from the texture
		0,

		// bounds the sprite's height to provide culling
		// if 0, the value is inferred from the texture
		0,
	},

	// scroll delay
	10,
};

TextureROMSpec Scene009CarInteriorTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009CarInteriorMap,

	// cols (max 64)
	32,

	// rows (max 64)
	20,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009CarInteriorSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009CarInteriorTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 4, 2},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009SeatTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009SeatMap,

	// cols (max 64)
	9,

	// rows (max 64)
	7,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009SeatSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009SeatTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{-68, -16, 3, 1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009HarryBlackTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009HarryBlackMap,

	// cols (max 64)
	12,

	// rows (max 64)
	10,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009HarryBlackSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009HarryBlackTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{20, -8, 2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009HarryBaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009HarryBaseMap,

	// cols (max 64)
	12,

	// rows (max 64)
	10,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009HarryBaseSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009HarryBaseTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{20, -8, 1, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009HarryOverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009HarryOverlayMap,

	// cols (max 64)
	12,

	// rows (max 64)
	10,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009HarryOverlaySpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009HarryOverlayTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// displacement
		{20, -8, -1, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009SteeringWheelTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009SteeringWheelMap,

	// cols (max 64)
	6,

	// rows (max 64)
	3,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009SteeringWheelSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009SteeringWheelTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{88, 3, -2, -1},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

TextureROMSpec Scene009FrameTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene009CharSetSpec,

	// bgmap spec
	Scene009FrameMap,

	// cols (max 64)
	64,

	// rows (max 64)
	64,

	// padding for affine/hbias transformations (cols, rows)
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

BgmapSpriteROMSpec Scene009FrameSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&Scene009FrameTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, -4, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

ComponentSpec* const Scene009EntityComponentSpecs[] = 
{
	(ComponentSpec*)&Scene009BackgroundBaseSpriteSpec,
	(ComponentSpec*)&Scene009BackgroundOverlaySpriteSpec,
	(ComponentSpec*)&Scene009Snow1SpriteSpec,
	(ComponentSpec*)&Scene009Snow2SpriteSpec,
	(ComponentSpec*)&Scene009CarInteriorSpriteSpec,
	(ComponentSpec*)&Scene009SeatSpriteSpec,
	(ComponentSpec*)&Scene009HarryBlackSpriteSpec,
	(ComponentSpec*)&Scene009HarryBaseSpriteSpec,
	(ComponentSpec*)&Scene009HarryOverlaySpriteSpec,
	(ComponentSpec*)&Scene009SteeringWheelSpriteSpec,
	(ComponentSpec*)&Scene009FrameSpriteSpec,
	NULL
};

EntityROMSpec Scene009EntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)Scene009EntityComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Entity's in-game type
	kTypeNone
};
