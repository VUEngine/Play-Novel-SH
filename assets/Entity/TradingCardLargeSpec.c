/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Libgccvb.h>
#include <AnimatedEntity.h>
#include <VIPManager.h>
#include <BgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 TradingCardLargeBaseTiles[];
extern uint32 TradingCardLargeBaseTilesFrameOffsets[];
extern uint16 TradingCardLargeBaseMap[];
extern uint32 TradingCardLargeOverlayTiles[];
extern uint32 TradingCardLargeOverlayTilesFrameOffsets[];
extern uint16 TradingCardLargeOverlayMap[];
extern EntitySpec TradingCardLargeBlackEntitySpec;


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec TradingCardLarge0AnimationSpec =
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
	"0",
};

AnimationFunctionROMSpec TradingCardLarge1AnimationSpec =
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
	"1",
};

AnimationFunctionROMSpec TradingCardLarge2AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 2 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"2",
};

AnimationFunctionROMSpec TradingCardLarge3AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 3 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"3",
};

AnimationFunctionROMSpec TradingCardLarge4AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 4 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"4",
};

AnimationFunctionROMSpec TradingCardLarge5AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 5 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"5",
};

AnimationFunctionROMSpec TradingCardLarge6AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 6 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"6",
};

AnimationFunctionROMSpec TradingCardLarge7AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 7 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"7",
};

AnimationFunctionROMSpec TradingCardLarge8AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 8 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"8",
};

AnimationFunctionROMSpec TradingCardLarge9AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 9 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"9",
};

AnimationFunctionROMSpec TradingCardLarge10AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 10 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"10",
};

AnimationFunctionROMSpec TradingCardLarge11AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 11 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"11",
};

AnimationFunctionROMSpec TradingCardLarge12AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 12 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"12",
};

AnimationFunctionROMSpec TradingCardLarge13AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 13 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"13",
};

AnimationFunctionROMSpec TradingCardLarge14AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 14 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"14",
};

AnimationFunctionROMSpec TradingCardLarge15AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 15 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"15",
};

AnimationFunctionROMSpec TradingCardLarge16AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 16 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"16",
};

AnimationFunctionROMSpec TradingCardLarge17AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 17 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"17",
};

AnimationFunctionROMSpec TradingCardLarge18AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 18 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"18",
};

AnimationFunctionROMSpec TradingCardLarge19AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 19 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"19",
};

AnimationFunctionROMSpec TradingCardLarge20AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 20 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"20",
};

AnimationFunctionROMSpec TradingCardLarge21AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 21 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"21",
};

AnimationFunctionROMSpec TradingCardLarge22AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 22 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"22",
};

AnimationFunctionROMSpec TradingCardLarge23AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 23 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"23",
};

AnimationFunctionROMSpec TradingCardLarge24AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 24 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"24",
};

AnimationFunctionROMSpec TradingCardLarge25AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 25 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"25",
};

AnimationFunctionROMSpec TradingCardLarge26AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 26 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"26",
};

AnimationFunctionROMSpec TradingCardLarge27AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 27 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"27",
};

AnimationFunctionROMSpec TradingCardLarge28AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 28 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"28",
};

AnimationFunctionROMSpec TradingCardLarge29AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 29 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"29",
};

AnimationFunctionROMSpec TradingCardLarge30AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 30 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"30",
};

AnimationFunctionROMSpec TradingCardLarge31AnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{ 31 },

	// number of cycles a frame of animation is displayed
	2,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"31",
};

AnimationFunctionROMSpec* const TradingCardLargeAnimationSpecs[] =
{
	(AnimationFunction*)&TradingCardLarge0AnimationSpec,
	(AnimationFunction*)&TradingCardLarge1AnimationSpec,
	(AnimationFunction*)&TradingCardLarge2AnimationSpec,
	(AnimationFunction*)&TradingCardLarge3AnimationSpec,
	(AnimationFunction*)&TradingCardLarge4AnimationSpec,
	(AnimationFunction*)&TradingCardLarge5AnimationSpec,
	(AnimationFunction*)&TradingCardLarge6AnimationSpec,
	(AnimationFunction*)&TradingCardLarge7AnimationSpec,
	(AnimationFunction*)&TradingCardLarge8AnimationSpec,
	(AnimationFunction*)&TradingCardLarge9AnimationSpec,
	(AnimationFunction*)&TradingCardLarge10AnimationSpec,
	(AnimationFunction*)&TradingCardLarge11AnimationSpec,
	(AnimationFunction*)&TradingCardLarge12AnimationSpec,
	(AnimationFunction*)&TradingCardLarge13AnimationSpec,
	(AnimationFunction*)&TradingCardLarge14AnimationSpec,
	(AnimationFunction*)&TradingCardLarge15AnimationSpec,
	(AnimationFunction*)&TradingCardLarge16AnimationSpec,
	(AnimationFunction*)&TradingCardLarge17AnimationSpec,
	(AnimationFunction*)&TradingCardLarge18AnimationSpec,
	(AnimationFunction*)&TradingCardLarge19AnimationSpec,
	(AnimationFunction*)&TradingCardLarge20AnimationSpec,
	(AnimationFunction*)&TradingCardLarge21AnimationSpec,
	(AnimationFunction*)&TradingCardLarge22AnimationSpec,
	(AnimationFunction*)&TradingCardLarge23AnimationSpec,
	(AnimationFunction*)&TradingCardLarge24AnimationSpec,
	(AnimationFunction*)&TradingCardLarge25AnimationSpec,
	(AnimationFunction*)&TradingCardLarge26AnimationSpec,
	(AnimationFunction*)&TradingCardLarge27AnimationSpec,
	(AnimationFunction*)&TradingCardLarge28AnimationSpec,
	(AnimationFunction*)&TradingCardLarge29AnimationSpec,
	(AnimationFunction*)&TradingCardLarge30AnimationSpec,
	(AnimationFunction*)&TradingCardLarge31AnimationSpec,
    NULL,
};

CharSetROMSpec TradingCardLargeBaseCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	148,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	TradingCardLargeBaseTiles,

	// pointer to the frames offsets
	TradingCardLargeBaseTilesFrameOffsets,
};

TextureROMSpec TradingCardLargeBaseTextureSpec =
{
	// charset spec
	(CharSetSpec*)&TradingCardLargeBaseCharSetSpec,

	// bgmap spec
	TradingCardLargeBaseMap,

	// cols (max 64)
	10,

	// rows (max 64)
	15,

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

BgmapSpriteROMSpec TradingCardLargeBaseSpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardLargeBaseTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

CharSetROMSpec TradingCardLargeOverlayCharSetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	150,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	true,

	// char spec
	TradingCardLargeOverlayTiles,

	// pointer to the frames offsets
	TradingCardLargeOverlayTilesFrameOffsets,
};

TextureROMSpec TradingCardLargeOverlayTextureSpec =
{
	// charset spec
	(CharSetSpec*)&TradingCardLargeOverlayCharSetSpec,

	// bgmap spec
	TradingCardLargeOverlayMap,

	// cols (max 64)
	10,

	// rows (max 64)
	15,

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

BgmapSpriteROMSpec TradingCardLargeOverlaySpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&TradingCardLargeOverlayTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

BgmapSpriteROMSpec* const TradingCardLargeSpriteSpecs[] =
{
	&TradingCardLargeBaseSpriteSpec,
	&TradingCardLargeOverlaySpriteSpec,
	NULL
};

PositionedEntityROMSpec TradingCardLargeChildrenEntities[] =
{
	{&TradingCardLargeBlackEntitySpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, true},
};

AnimatedEntityROMSpec TradingCardLargeEntitySpec =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// children
		(PositionedEntity*)TradingCardLargeChildrenEntities,

		// behaviors
		NULL,

		// extra
		NULL,

		// sprites
		(SpriteSpec**)TradingCardLargeSpriteSpecs,

		// use z displacement in projection
		false,
			
		// wireframes
		(WireframeSpec**)NULL,

		// collision colliders
		(ColliderSpec*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		0,

		// physical specification
		(PhysicalProperties*)NULL,
	},

	// pointer to the animation spec for the item
	(const AnimationFunction**)&TradingCardLargeAnimationSpecs,

	// initial animation
	"0",
};
