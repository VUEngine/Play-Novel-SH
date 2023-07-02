/**
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <VisualNovelState.h>
#include <Languages.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern Scenario PlayNovelScenarioHarry;
extern Scenario PlayNovelScenarioCybil;
extern Scenario PlayNovelScenarioAndy;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

const struct Script PlayNovelScenarios = {
	"Play Novel: Silent Hill",
	{
		&PlayNovelScenarioHarry,
		&PlayNovelScenarioCybil,
		&PlayNovelScenarioAndy,
	},
};
