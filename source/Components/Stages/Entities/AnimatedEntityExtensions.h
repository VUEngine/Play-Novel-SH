/*
 * Formula V
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef ANIMATED_ENTITY_EXTENSIONS_H_
#define ANIMATED_ENTITY_EXTENSIONS_H_


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <AnimatedEntity.h>



//——————————————————————————————————————————————————————————————————————————————————————————————————————————

//											CLASS'S DECLARATION

//——————————————————————————————————————————————————————————————————————————————————————————————————————————


extension class AnimatedEntity : Entity
{
	void onIntroDefaultAnimationComplete(ListenerObject eventFirer);
}


#endif
