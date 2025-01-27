/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <VIPManager.h>
#include <AutoScrollingMBgmapSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec Scene009CharSetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	507,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	Scene009Tiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec Scene009BackgroundBaseTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009BackgroundBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	32,

	// Vertical size in tiles of the texture (max. 64)
	12,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009BackgroundBaseTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, -32, 8, 4},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009BackgroundOverlayTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009BackgroundOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	32,

	// Vertical size in tiles of the texture (max. 64)
	12,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009BackgroundOverlayTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// Displacement added to the sprite's position
		{0, -32, 7, 4},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009Snow1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009Snow1Map,

	// Horizontal size in tiles of the texture (max. 64)
	64,

	// Vertical size in tiles of the texture (max. 64)
	64,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

				// Is animated?
				false,

				// Spec for the texture to display
				(TextureSpec*)NULL,

				// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
				__TRANSPARENCY_NONE,

				// Displacement added to the sprite's position
				{64, 0, 6, 3},
			},

			// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
			__WORLD_ON,

			// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
			__WORLD_BGMAP,

			// Pointer to affine/hbias manipulation function
			NULL
		},

		(TextureSpec**)Scene009Snow1Textures,

		// SCX/SCY (__WORLD_1x1, 1x2, 1x4, 1x8, 2x1, 2x2, 2x4, 4x1, 4x2, or 8x1)
		// textures must be 64x64 for anything other than 1x1
		__WORLD_1x1,

		// Flag to loop the x axis
		false,

		// Flag to loop the y axis
		true,

		// Bounds the sprite's width to provide culling
		// if 0, the value is inferred from the texture
		0,

		// Bounds the sprite's height to provide culling
		// if 0, the value is inferred from the texture
		0,
	},

	// Scroll delay
	20,
};

TextureROMSpec Scene009Snow2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009Snow2Map,

	// Horizontal size in tiles of the texture (max. 64)
	64,

	// Vertical size in tiles of the texture (max. 64)
	64,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

				// Is animated?
				false,

				// Spec for the texture to display
				(TextureSpec*)NULL,

				// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
				__TRANSPARENCY_NONE,

				// Displacement added to the sprite's position
				{64, 0, 5, 2},
			},

			// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
			__WORLD_ON,

			// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
			__WORLD_BGMAP,

			// Pointer to affine/hbias manipulation function
			NULL
		},

		(TextureSpec**)Scene009Snow2Textures,

		// SCX/SCY (__WORLD_1x1, 1x2, 1x4, 1x8, 2x1, 2x2, 2x4, 4x1, 4x2, or 8x1)
		// textures must be 64x64 for anything other than 1x1
		__WORLD_1x1,

		// Flag to loop the x axis
		false,

		// Flag to loop the y axis
		true,

		// Bounds the sprite's width to provide culling
		// if 0, the value is inferred from the texture
		0,

		// Bounds the sprite's height to provide culling
		// if 0, the value is inferred from the texture
		0,
	},

	// Scroll delay
	10,
};

TextureROMSpec Scene009CarInteriorTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009CarInteriorMap,

	// Horizontal size in tiles of the texture (max. 64)
	32,

	// Vertical size in tiles of the texture (max. 64)
	20,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009CarInteriorTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 4, 2},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009SeatTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009SeatMap,

	// Horizontal size in tiles of the texture (max. 64)
	9,

	// Vertical size in tiles of the texture (max. 64)
	7,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009SeatTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{-68, -16, 3, 1},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009HarryBlackTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009HarryBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	12,

	// Vertical size in tiles of the texture (max. 64)
	10,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009HarryBlackTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{20, -8, 2, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009HarryBaseTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009HarryBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	12,

	// Vertical size in tiles of the texture (max. 64)
	10,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009HarryBaseTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{20, -8, 1, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009HarryOverlayTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009HarryOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	12,

	// Vertical size in tiles of the texture (max. 64)
	10,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009HarryOverlayTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// Displacement added to the sprite's position
		{20, -8, -1, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009SteeringWheelTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009SteeringWheelMap,

	// Horizontal size in tiles of the texture (max. 64)
	6,

	// Vertical size in tiles of the texture (max. 64)
	3,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009SteeringWheelTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{88, 3, -2, -1},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene009FrameTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009FrameMap,

	// Horizontal size in tiles of the texture (max. 64)
	64,

	// Vertical size in tiles of the texture (max. 64)
	64,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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

		// Is animated?
		false,

		// Spec for the texture to display
		(TextureSpec*)&Scene009FrameTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, -4, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const Scene009ActorComponentSpecs[] = 
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

ActorROMSpec Scene009ActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)Scene009ActorComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Pointer to animation functions array
	NULL,

	// Animation to play automatically
	NULL
};
