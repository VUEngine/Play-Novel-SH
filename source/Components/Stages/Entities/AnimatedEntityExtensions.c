/**
 * Formula V
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <IntroScreenState.h>
#include <GameEvents.h>

#include "AnimatedEntityExtensions.h"


//---------------------------------------------------------------------------------------------------------
//												CLASS'S DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extension class AnimatedEntity;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S DEFINITIONS
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void AnimatedEntity::onIntroDefaultAnimationComplete(ListenerObject eventFirer __attribute__((unused)))
{
	IntroScreenState::fireEvent(IntroScreenState::getInstance(), kEventIntroAnimationCompleted);
}