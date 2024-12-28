/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Stage.h>
#include <Fonts.h>
#include <ObjectSpriteContainer.h>


//---------------------------------------------------------------------------------------------------------
//											DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern EntitySpec LowPowerIndicatorEntitySpec;
extern EntitySpec TradingCardsBackgroundEntitySpec;
extern EntitySpec TradingCardsBackgroundNumbersEntitySpec;
extern EntitySpec TradingCardSmallEntitySpec;
extern EntitySpec TradingCardLargeEntitySpec;
extern EntitySpec TradingCardsCursorEntitySpec;


//=========================================================================================================
// ENTITY LISTS
//=========================================================================================================

PositionedEntityROMSpec TradingCardsScreenStageSpecEntities[] =
{
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

PositionedEntityROMSpec TradingCardsScreenStageSpecUiEntities[] =
{
	{&TradingCardsBackgroundEntitySpec,				{  0,   0, 0},  {0, 0, 0}, {1, 1, 1},   	0, "BG", NULL, NULL, false},
	{&TradingCardsBackgroundNumbersEntitySpec,		{  0,  24, -1}, {0, 0, 0}, {1, 1, 1},   	0, "NUM", NULL, NULL, false},

	{&TradingCardsCursorEntitySpec,					{-64,  88, -4}, {0, 0, 0}, {1, 1, 1},   	0, "CURSOR", NULL, NULL, false},
	
	{&TradingCardSmallEntitySpec,					{-72, -40, -1}, {0, 0, 0}, {1, 1, 1},   	0, "0", NULL, NULL, false},
	{&TradingCardSmallEntitySpec,					{-24, -40, -1}, {0, 0, 0}, {1, 1, 1},   	0, "1", NULL, NULL, false},
	{&TradingCardSmallEntitySpec,					{ 24, -40, -1}, {0, 0, 0}, {1, 1, 1},   	0, "2", NULL, NULL, false},
	{&TradingCardSmallEntitySpec,					{ 72, -40, -1}, {0, 0, 0}, {1, 1, 1},   	0, "3", NULL, NULL, false},
	{&TradingCardSmallEntitySpec,					{-72,  24, -1}, {0, 0, 0}, {1, 1, 1},   	0, "4", NULL, NULL, false},
	{&TradingCardSmallEntitySpec,					{-24,  24, -1}, {0, 0, 0}, {1, 1, 1},   	0, "5", NULL, NULL, false},
	{&TradingCardSmallEntitySpec,					{ 24,  24, -1}, {0, 0, 0}, {1, 1, 1},   	0, "6", NULL, NULL, false},
	{&TradingCardSmallEntitySpec,					{ 72,  24, -1}, {0, 0, 0}, {1, 1, 1},   	0, "7", NULL, NULL, false},
	{&TradingCardLargeEntitySpec,					{  0,   0, -4}, {0, 0, 0}, {1, 1, 1},   	0, "CARD", NULL, NULL, false},

	{&LowPowerIndicatorEntitySpec, 					{ 368,  12,  -1}, {0, 0, 0}, {1, 1, 1},	0, NULL, NULL, NULL, false},

	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};


//=========================================================================================================
// ASSETS LISTS
//=========================================================================================================

FontROMSpec* const TradingCardsScreenStageSpecFonts[] =
{
	NULL
};


//=========================================================================================================
// STAGE DEFINITION
//=========================================================================================================

StageROMSpec TradingCardsScreenStageSpec =
{
	// Class allocator
	__TYPE(Stage),

	// Timer config
	{
		__TIMER_100US,
		10,
		kMS
	},

	// Sound config
	{
		__DEFAULT_PCM_HZ,
		false
	},

	// General stage's attributes
	{
		// Stage's size in pixels
		{
			// x
			__SCREEN_WIDTH,
			// y
			__SCREEN_HEIGHT,
			// z
			__SCREEN_DEPTH,
		},

		// Camera's initial position inside the stage
		{
			// x
			0,
			// y
			0,
			// z
			0,
			// p
			0,
		},

		// Camera's frustum
		{
			// x0
			0,
			// y0
			0,
			// z0
			-10,
			// x1
			__SCREEN_WIDTH,
			// y1
			__SCREEN_HEIGHT,
			// z1
			__SCREEN_WIDTH * 5,
		}
	},

	// Streaming
	{
		// Padding to be added to camera's frustum when checking if a entity spec
		// describes an entity that is within the camera's range
		40,
		// Padding to be added to camera's frustum when checking if a entity is
		// out of the camera's range
		16,
		// Amount of entity descriptions to check for streaming in entities
		24,
		// If true, entity instantiation is done over time
		false,
	},

	// Rendering
	{
		// Maximum number of texture's rows to write each time the texture writing is active
		64,

		// Maximum number of rows to compute on each call to the affine functions
		16,

		// Color configuration
		{
			// Background color
			__COLOR_BLACK,

			// Brightness
			// These values times the repeat values specified in the column table (max. 16) make the final
			// brightness values on the respective regions of the screen. maximum brightness is 128.
			{
				// Dark red
				__BRIGHTNESS_DARK_RED,
				// Medium red
				__BRIGHTNESS_MEDIUM_RED,
				// Bright red
				__BRIGHTNESS_BRIGHT_RED,
			},

			// Brightness repeat
			(BrightnessRepeatSpec*)NULL,
		},

		// Palettes' configuration
		{
			{
				// Bgmap palette 0
				__BGMAP_PALETTE_0,
				// Bgmap palette 1
				__BGMAP_PALETTE_1,
				// Bgmap palette 2
				__BGMAP_PALETTE_2,
				// Bgmap palette 3
				__BGMAP_PALETTE_3,
			},
			{
				// Object palette 0
				__OBJECT_PALETTE_0,
				// Object palette 1
				__OBJECT_PALETTE_1,
				// Object palette 2
				__OBJECT_PALETTE_2,
				// Object palette 3
				__OBJECT_PALETTE_3,
			},
		},

		// Bgmap segments configuration
		// Number of BGMAP segments reserved for the param
		0,

		// obj segments sizes (must total 1024)
		{
			// __spt0
			0,
			// __spt1
			0,
			// __spt2
			0,
			// __spt3
			0,
		},

		// OBJECT segments z coordinates
		// Note that each spt's z coordinate much be larger than or equal to the previous one's,
		// since the vip renders obj worlds in reverse order (__spt3 to __spt0)
		{
			// __spt0
			0,
			// __spt1
			0,
			// __spt2
			0,
			// __spt3
			0,
		},

		// Struct defining the optical settings for the stage
		{
			// Maximum view distance's power into the horizon
			__MAXIMUM_X_VIEW_DISTANCE, __MAXIMUM_Y_VIEW_DISTANCE,
			// Distance of the eyes to the screen
			__CAMERA_NEAR_PLANE,
			// Distance from left to right eye (depth sensation)
			__BASE_FACTOR,
			// Horizontal view point center
			__HORIZONTAL_VIEW_POINT_CENTER,
			// Vertical view point center
			__VERTICAL_VIEW_POINT_CENTER,
			// Scaling factor
			__SCALING_MODIFIER_FACTOR,
		},
	},

	// Physical world's properties
	{
		// Gravity
		{
			__I_TO_FIX10_6(0),
			__F_TO_FIX10_6(0),
			__I_TO_FIX10_6(0),
		},

		// Friction coefficient
		__F_TO_FIX10_6(0.1f),
	},

	// Assets
	{
		// Fonts to preload
		(FontSpec**)TradingCardsScreenStageSpecFonts,

		// CharSets to preload
		(CharSetSpec**)NULL,

		// Textures to preload
		(TextureSpec**)NULL,

		// Sounds to load
		(SoundSpec**)NULL,
	},

	// Entities
	{
		// UI configuration
		{
			(PositionedEntity*)TradingCardsScreenStageSpecUiEntities,
			__TYPE(UIContainer),
		},

		// Stage's children entities
		(PositionedEntity*)TradingCardsScreenStageSpecEntities,
	},

	// Post processing effects
	(PostProcessingEffect*)NULL,
};
