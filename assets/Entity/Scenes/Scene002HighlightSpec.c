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
#include <BgmapSprite.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern CharSetSpec Scene002CharSetSpec;
extern uint16 Scene002HighlightMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

TextureROMSpec Scene002HighlightTextureSpec =
{
	// charset spec
	(CharSetSpec*)&Scene002CharSetSpec,

	// bgmap spec
	Scene002HighlightMap,

	// cols (max 64)
	6,

	// rows (max 64)
	13,

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

BgmapSpriteROMSpec Scene002HighlightSpriteSpec =
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
		(TextureSpec*)&Scene002HighlightTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{26, -15, -2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};



const ComponentSpec* Scene002HighlightEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)Scene002HighlightSpriteSpec,

};

EntityROMSpec Scene002HighlightEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpec**)Scene002HighlightEntitySpecComponentSpecs,

	// children
	NULL,

	// extra
	NULL,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone
};
