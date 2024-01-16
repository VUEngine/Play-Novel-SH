/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


#ifndef AUTO_SCROLLING_MBGMAP_SPRITE_H_
#define AUTO_SCROLLING_MBGMAP_SPRITE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <MBgmapSprite.h>
#include <Texture.h>


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

enum AutoScrollingMBgmapSpriteMessages
{
	kAutoScrollingMBgmapSpriteMessageScroll,
};


//---------------------------------------------------------------------------------------------------------
// 											TYPE DEFINITIONS
//---------------------------------------------------------------------------------------------------------

typedef struct AutoScrollingMBgmapSpriteSpec
{
	MBgmapSpriteSpec mBgmapSpriteSpec;

	uint16 scrollDelay;

} AutoScrollingMBgmapSpriteSpec;

typedef const AutoScrollingMBgmapSpriteSpec AutoScrollingMBgmapSpriteROMSpec;


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

class AutoScrollingMBgmapSprite : MBgmapSprite
{
	uint16 scrollDelay;
	void constructor(SpatialObject owner, const AutoScrollingMBgmapSpriteSpec* autoScrollingMBgmapSpriteSpec);
	override bool handleMessage(Telegram telegram);
}


#endif
