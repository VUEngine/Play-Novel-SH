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
#include <BgmapSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern CharSetROMSpec Scene012CharSetSpec;
extern uint16 Scene012CherylBaseMap[];
extern uint16 Scene012CherylOverlayMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

TextureROMSpec Scene012CherylBaseTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene012CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene012CherylBaseMap,

	// Horizontal size in tiles of the texture (max. 64)
	3,

	// Vertical size in tiles of the texture (max. 64)
	8,

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

BgmapSpriteROMSpec Scene012CherylBaseSpriteSpec =
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
		(TextureSpec*)&Scene012CherylBaseTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{5, 20, -2, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

TextureROMSpec Scene012CherylOverlayTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&Scene012CharSetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	Scene012CherylOverlayMap,

	// Horizontal size in tiles of the texture (max. 64)
	3,

	// Vertical size in tiles of the texture (max. 64)
	8,

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

BgmapSpriteROMSpec Scene012CherylOverlaySpriteSpec =
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
		(TextureSpec*)&Scene012CherylOverlayTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_EVEN,

		// Displacement added to the sprite's position
		{5, 20, -2, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL
};

ComponentSpec* const Scene012CherylActorComponentSpecs[] = 
{
	(ComponentSpec*)&Scene012CherylBaseSpriteSpec,
	(ComponentSpec*)&Scene012CherylOverlaySpriteSpec,
	NULL
};

ActorROMSpec Scene012CherylActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)Scene012CherylActorComponentSpecs,

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
