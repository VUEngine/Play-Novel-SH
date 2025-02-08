////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <BgmapSprite.h>
#include <FrameBlendBgmapSprite.h>
#include <InGameTypes.h>
#include <AutoScrollingMBgmapSprite.h>
#include <Texture.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 Scene009ActorScene009BackgroundTiles[];
extern uint16 Scene009ActorScene009BackgroundMap[];

extern uint32 Scene009ActorScene009CarInteriorTiles[];
extern uint16 Scene009ActorScene009CarInteriorMap[];

extern uint32 Scene009ActorScene009FrameTiles[];
extern uint16 Scene009ActorScene009FrameMap[];

extern uint32 Scene009ActorScene009HarryTiles[];
extern uint16 Scene009ActorScene009HarryMap[];

extern uint32 Scene009ActorScene009HarryBlackTiles[];
extern uint16 Scene009ActorScene009HarryBlackMap[];

extern uint32 Scene009ActorScene009SeatTiles[];
extern uint16 Scene009ActorScene009SeatMap[];

extern uint32 Scene009ActorScene009SteeringWheelTiles[];
extern uint16 Scene009ActorScene009SteeringWheelMap[];

extern uint32 Scene009ActorScene009Snow1Tiles[];
extern uint16 Scene009ActorScene009Snow1Map[];

extern uint32 Scene009ActorScene009Snow2Tiles[];
extern uint16 Scene009ActorScene009Snow2Map[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec Scene009Sprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	157,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009BackgroundTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009BackgroundMap,

	// Horizontal size in tiles of the texture (max. 64)
	32,

	// Vertical size in tiles of the texture (max. 64)
	12,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	2,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

FrameBlendBgmapSpriteROMSpec Scene009Sprite1SpriteSpec =
{
	{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(FrameBlendBgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene009Sprite1TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, -32, 8, 4}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
	}
};


CharSetROMSpec Scene009Sprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	42,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009CarInteriorTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009CarInteriorMap,

	// Horizontal size in tiles of the texture (max. 64)
	32,

	// Vertical size in tiles of the texture (max. 64)
	20,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec Scene009Sprite2SpriteSpec =
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
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene009Sprite2TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 4, 2}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec Scene009Sprite3CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	2,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009FrameTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite3TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite3CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009FrameMap,

	// Horizontal size in tiles of the texture (max. 64)
	64,

	// Vertical size in tiles of the texture (max. 64)
	64,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec Scene009Sprite3SpriteSpec =
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
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene009Sprite3TextureSpec,

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


CharSetROMSpec Scene009Sprite4CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	117,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009HarryTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite4TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite4CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009HarryMap,

	// Horizontal size in tiles of the texture (max. 64)
	12,

	// Vertical size in tiles of the texture (max. 64)
	10,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	2,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

FrameBlendBgmapSpriteROMSpec Scene009Sprite4SpriteSpec =
{
	{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(FrameBlendBgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene009Sprite4TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{20, -8, 1, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
	}
};


CharSetROMSpec Scene009Sprite5CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	29,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009HarryBlackTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite5TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite5CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009HarryBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	12,

	// Vertical size in tiles of the texture (max. 64)
	10,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec Scene009Sprite5SpriteSpec =
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
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene009Sprite5TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{20, -8, 2, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec Scene009Sprite6CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	14,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009SeatTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite6TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite6CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009SeatMap,

	// Horizontal size in tiles of the texture (max. 64)
	9,

	// Vertical size in tiles of the texture (max. 64)
	7,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec Scene009Sprite6SpriteSpec =
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
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene009Sprite6TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{-68, -16, 3, 1}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec Scene009Sprite7CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	15,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009SteeringWheelTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite7TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite7CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009SteeringWheelMap,

	// Horizontal size in tiles of the texture (max. 64)
	6,

	// Vertical size in tiles of the texture (max. 64)
	3,

	// padding for affine/hbias transformations
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
	false
};

BgmapSpriteROMSpec Scene009Sprite7SpriteSpec =
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
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&Scene009Sprite7TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{88, 3, -2, -1}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec Scene009Sprite8CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	15,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009Snow1Tiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite8TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite8CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009Snow1Map,

	// Horizontal size in tiles of the texture (max. 64)
	64,

	// Vertical size in tiles of the texture (max. 64)
	64,

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

TextureROMSpec* const Scene009Sprite8TextureSpecs[] =
{
	(TextureSpec*)&Scene009Sprite8TextureSpec,
	NULL
};

MBgmapSpriteROMSpec Scene009Sprite8SpriteSpec =
{
	{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(AutoScrollingMBgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		NULL,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{64, 0, 6, 3}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
	},

	// Texture to use with the sprite
	(TextureSpec**)Scene009Sprite8TextureSpecs,

	// SCX/SCY value
	__WORLD_1x1,

	// Flag to loop the x axis
	true,

	// Flag to loop the y axis
	true,

	// Bounds the sprite's width to provide culling; if 0, the value is inferred from the texture
	0,

	// Bounds the sprite's height to provide culling; if 0, the value is inferred from the texture
	0
};


CharSetROMSpec Scene009Sprite9CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	14,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	Scene009ActorScene009Snow2Tiles,

	// Frame offsets array
	NULL
};

TextureROMSpec Scene009Sprite9TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene009Sprite9CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene009ActorScene009Snow2Map,

	// Horizontal size in tiles of the texture (max. 64)
	64,

	// Vertical size in tiles of the texture (max. 64)
	64,

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

TextureROMSpec* const Scene009Sprite9TextureSpecs[] =
{
	(TextureSpec*)&Scene009Sprite9TextureSpec,
	NULL
};

MBgmapSpriteROMSpec Scene009Sprite9SpriteSpec =
{
	{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(AutoScrollingMBgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		NULL,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{64, 0, 5, 2}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
	},

	// Texture to use with the sprite
	(TextureSpec**)Scene009Sprite9TextureSpecs,

	// SCX/SCY value
	__WORLD_1x1,

	// Flag to loop the x axis
	true,

	// Flag to loop the y axis
	true,

	// Bounds the sprite's width to provide culling; if 0, the value is inferred from the texture
	0,

	// Bounds the sprite's height to provide culling; if 0, the value is inferred from the texture
	0
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const Scene009ComponentSpecs[] = 
{
	(ComponentSpec*)&Scene009Sprite1SpriteSpec,
	(ComponentSpec*)&Scene009Sprite2SpriteSpec,
	(ComponentSpec*)&Scene009Sprite3SpriteSpec,
	(ComponentSpec*)&Scene009Sprite4SpriteSpec,
	(ComponentSpec*)&Scene009Sprite5SpriteSpec,
	(ComponentSpec*)&Scene009Sprite6SpriteSpec,
	(ComponentSpec*)&Scene009Sprite7SpriteSpec,
	(ComponentSpec*)&Scene009Sprite8SpriteSpec,
	(ComponentSpec*)&Scene009Sprite9SpriteSpec,
	NULL
};

ActorROMSpec Scene009ActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)Scene009ComponentSpecs,

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
	NULL
	
};
