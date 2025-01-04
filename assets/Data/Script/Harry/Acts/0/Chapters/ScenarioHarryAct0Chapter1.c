/*
 * Play Novel: Silent Hill
 * ©1999 2001 KCE Tokyo ALL RIGHTS RESERVED.
 *
 * Virtual Boy port by Christian Radke <c.radke@posteo.de>
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <VisualNovelState.h>
#include <Languages.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern ActorSpec Scene001ActorSpec;
extern ActorSpec Scene002ActorSpec;
extern ActorSpec Scene002HighlightActorSpec;
extern ActorSpec Scene003ActorSpec;
extern ActorSpec Scene004ActorSpec;
extern ActorSpec Scene005ActorSpec;
extern ActorSpec Scene006ActorSpec;
extern ActorSpec Scene007ActorSpec;
extern ActorSpec Scene008ActorSpec;

extern SoundSpec CarEngineSoundSpec;
extern SoundSpec CarBrakingSoundSpec;
extern SoundSpec EnteringOtherWorldSoundSpec;
extern SoundSpec SomethingStrangeSoundSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene1Actors[] =
{
	{&Scene001ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene1 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene1Actors,
	NULL,
	{
		{
			"It's been a while since I have taken a\nvacation. I am driving my jeep, heading to-\nwards the quiet resort town of Silent Hill.",
			"The sound of the engine reverberates in the \ndarkness. Due to some slight car trouble \nearlier, it has become this late.",
		},
		{
			"Es ist schon eine Weile her, dass ich Urlaub gemacht habe. Ich fahre in meinem Jeep in\nRichtung des ruhigen Ferienortes Silent Hill. ",
			"Das Geräusch des Motors hallt in der \nDunkelheit wider. Wegen einer kleinen Panne\nvorhin ist es so spät geworden.",
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene2Actors[] =
{
	{&Scene002ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	//{&Scene002HighlightActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene2 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	&CarEngineSoundSpec,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene2Actors,
	NULL,
	{
		{
			"I am Harry Mason.\nA run of the mill writer.",
		},
		{
			"Ich bin Harry Mason.\nEin Allerweltsschriftsteller.",
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene3Actors[] =
{
	{&Scene003ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene3 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene3Actors,
	NULL,
	{
		{
			"Her eyes closed, my daughter Cheryl \nsleeps peacefully in the passenger seat.",
			"She is cheerful and lively, and the \noccasional carefree smiles she shows \nme make me feel happy.",
			"I don't have many relationships with people \nbecause of what I do for a living, so \nCheryl's existence has become ",
			"irreplaceable to me.\nCheryl was very much looking forward to \nthis trip.",
		},
		{
			"Die Augen geschlossen, schläft meine \nTochter Cheryl friedlich auf dem \nBeifahrersitz.",
			"Sie ist ein fröhliches und lebendiges \nMädchen. Ihr gelegentliche unbeschwertes \nLächeln macht mich glücklich.",
			"Meines Berufs wegen habe ich nicht sehr\nviele Beziehungen zu Menschen, daher ist\nCheryls Existenz für mich ",
			"unersetzlich geworden. \nCheryl hatte sich sehr auf diese Reise \ngefreut.",
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene4Actors[] =
{
	{&Scene002ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene4 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene4Actors,
	NULL,
	{
		{
			"Although paved, this is still very much a \nmountain road. At this hour there is little \nreason for any other drivers to be about.",
			"I push in the accelerator.\nThere is no light off in the darkness.\nI can depend only on my headlights.",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene5Actors[] =
{
	{&Scene004ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene5 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene5Actors,
	NULL,
	{
		{
			"Light reflects off the rear view mirror. \nThere is a motorcycle headed toward the same \ndestination as we are at ",
			"terrific speed at this late hour. \nWith a roar the motorcycle effortlessly \npasses by the side of my jeep.",
			"The seal of the police... Perhaps there has \nbeen an accident or something?",
			"But I don't recall hearing about an \naccident or anything on the radio.",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene6Actors[] =
{
	{&Scene003ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene6 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene6Actors,
	NULL,
	{
		{
			"Cheryl is sleeping. A child should not \nbe awake at this hour. I wonder if she \nis dreaming about something?",
			"Tomorrow I have planned to take her to \nthe amusement park. Maybe she is dreaming \nabout riding the merry-go-round? ",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene7Actors[] =
{
	{&Scene002ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene7 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene7Actors,
	NULL,
	{
		{
			"I glance over at Cheryl's sleeping face and \nthen return my eyes forward.",
			"The lighted area of the road almost appears \nto be belched out from the darkness as it \nmoves toward me.",
			"Huh? Something enters my field of view.",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene8Actors[] =
{
	{&Scene005ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene8 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	&SomethingStrangeSoundSpec,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene8Actors,
	NULL,
	{
		{
			"It's the motorcycle from just before. \nIt is lying on its shoulder on the side \nof the road.",
			"No doubt about it, it's the same motorcycle \nthat just passed me.",
			"There is no sign of the driver. \nIt looks like the driver smashed into the \nsurface of the rocks by the side ",
			"of the road while trying to avoid some \nkind of obstacle, and thus that part of \nthe motorcycle has been destroyed.",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene9Actors[] =
{
	{&Scene006ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene9 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene9Actors,
	NULL,
	{
		{
			"I carefully check the way in which my \nvehicle is headed.",
			"However, I don't see anything that could \nbe an obstacle to my advance in the area \nilluminated by the headlights. ",
			"A strange atmosphere creeps in around me. \nThe radio reception begins to become \nerratic.",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene10Actors[] =
{
	{&Scene002ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene10 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	&EnteringOtherWorldSoundSpec,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene10Actors,
	NULL,
	{
		{
			"Perhaps I should turn back? But my foot \npersistently pushes down the accelerator \nwith no intention of letting off.",
			"\"You can no longer turn back now...\" \nSomething murmurs within me.",
			"\"Please increase your speed some more...\" \nSomeone murmurs within me.",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene11Actors[] =
{
	{&Scene003ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene11 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene11Actors,
	NULL,
	{
		{
			"Cheryl's eyes are closed. She is dreaming.\nI know that I should be awake.\nBut what is this uneasy feeling?",
			"I feel as if my body is not totally my own.\nIt's like someone, some strange being that \nis not me, is controlling me...",
			"like I am floating. \nMy eyelids are heavy.",
			"As the steering wheel leaves my hand it \ncreates the illusion of setting the course \non its own.",
			"Freezing cold... Uneasiness...",
			"Almost like being ready to fall asleep, \nI am just barely conscious, and now at \nmy limit to maintain even that.",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene12Actors[] =
{
	{&Scene007ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene12 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene12Actors,
	NULL,
	{
		{
			"Ah...",
		},
		{
		}
	},
	NULL,
};

PositionedActorROMSpec PlayNovelScenarioHarryAct0Chapter1Sub1Scene13Actors[] =
{
	{&Scene008ActorSpec, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene13 = {
	kFadeTypeNormal,
	kFadeTypeSlow,
	kSoundPlaybackNormal,
	NULL,
	(PositionedActor*)PlayNovelScenarioHarryAct0Chapter1Sub1Scene13Actors,
	NULL,
	{
		{
			"When I saw the human figure on the road \nI cut the wheel hard, and then there was \nnowhere else for my jeep and I to go ",
			"but down into the darkness below the cliff.",
		},
		{
		}
	},
	NULL,
};

const struct Scene PlayNovelScenarioHarryAct0Chapter1Sub1Scene14 = {
	kFadeTypeNormal,
	kFadeTypeNormal,
	kSoundPlaybackNormal,
	&CarBrakingSoundSpec,
	NULL,
	NULL,
	{
		{
			""
		},
		{
			""
		}
	},
	NULL,
};

const struct SubChapter PlayNovelScenarioHarryAct0Chapter1Sub1 = {
	{
		"A first vacation in a while",
		""
	},
	{
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene1,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene2,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene3,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene4,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene5,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene6,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene7,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene8,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene9,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene10,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene11,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene12,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene13,
		&PlayNovelScenarioHarryAct0Chapter1Sub1Scene14,
		NULL,
	},
};

const struct Chapter PlayNovelScenarioHarryAct0Chapter1 = {
	{
		"The Beginning of the Nightmare",
		""
	},
	{
		&PlayNovelScenarioHarryAct0Chapter1Sub1,
		NULL,
	},
};
