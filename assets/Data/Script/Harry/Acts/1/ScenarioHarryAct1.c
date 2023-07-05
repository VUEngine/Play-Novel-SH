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

extern Chapter PlayNovelScenarioHarryAct1Chapter1;
extern Chapter PlayNovelScenarioHarryAct1Chapter2;
extern Chapter PlayNovelScenarioHarryAct1Chapter3;
extern Chapter PlayNovelScenarioHarryAct1Chapter4;


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

const struct Act PlayNovelScenarioHarryAct1 = {
	{
		"Chapter 1",
		""
	},
	{
		&PlayNovelScenarioHarryAct1Chapter1,
		&PlayNovelScenarioHarryAct1Chapter2,
		&PlayNovelScenarioHarryAct1Chapter3,
		&PlayNovelScenarioHarryAct1Chapter4,
		NULL,
	},
};