/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <AutoScrollingMBgmapSprite.h>
#include <VirtualList.h>
#include <Telegram.h>


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void AutoScrollingMBgmapSprite::constructor(SpatialObject owner, const AutoScrollingMBgmapSpriteSpec* autoScrollingMBgmapSpriteSpec)
{
	// Always explicitly call the base's constructor 
	Base::constructor(owner, &autoScrollingMBgmapSpriteSpec->mBgmapSpriteSpec);
	this->scrollDelay = autoScrollingMBgmapSpriteSpec->scrollDelay;

	ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kAutoScrollingMBgmapSpriteMessageScroll, this->scrollDelay, 0);
}

void AutoScrollingMBgmapSprite::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

bool AutoScrollingMBgmapSprite::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kAutoScrollingMBgmapSpriteMessageScroll:
		{
			AutoScrollingMBgmapSprite::scroll(this);
			ListenerObject::sendMessageToSelf(ListenerObject::safeCast(this), kAutoScrollingMBgmapSpriteMessageScroll, this->scrollDelay, 0);
			break;
		}
	}

	return true;
}

void AutoScrollingMBgmapSprite::scroll()
{
	this->position.y += 1;
	this->rendered = false;
}
