#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/game_10c9c0.h"
#include "game/endscreen.h"
#include "game/pak/pak.h"
#include "game/utils.h"
#include "game/endscreen.h"
#include "game/game_177e00.h"
#include "game/game_179060.h"
#include "game/game_17f930.h"
#include "game/game_1a3340.h"
#include "gvars/gvars.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "stagesetup.h"
#include "types.h"

// 1ae10
struct menuitem menuitems_gamefiles2[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(100), 0x00000000, NULL }, // "Copy:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, menuhandlerOpenCopyFile }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, menuhandlerOpenCopyFile }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, menuhandlerOpenCopyFile }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(101), 0x00000000, NULL }, // "Delete:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, menuhandlerOpenDeleteFile }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, menuhandlerOpenDeleteFile }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, menuhandlerOpenDeleteFile }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_OPTIONS(102), 0x00000000, &menudialog_controllerpakmenu }, // "Delete Game Notes..."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1af00
struct menudialog menudialog_gamefiles2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(99), // "Game Files"
	menuitems_gamefiles2,
	NULL,
	0x00000020,
	NULL,
};

// 1af18
struct menuitem menuitems_fileselect2[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(96), 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_CUSTOM,      0, 0x00200000, 0x000000f5, 0x00000000, menucustomChooseAgent },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1af54
struct menudialog menudialog_fileselect2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(95), // "Perfect Dark"
	menuitems_fileselect2,
	menudialog0010c804,
	0x00000020,
	&menudialog_gamefiles2,
};

// 1af6c
struct menuitem menuitems_audiovisual[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00002800, L_OPTIONS(308), L_MPMENU(0), menuhandlerSfxVolume }, // "Sound"
	{ MENUITEMTYPE_SLIDER,      0, 0x00002800, L_OPTIONS(309), L_MPMENU(0), menuhandlerMusicVolume }, // "Music"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS(310), 0x00000000, menuhandlerSoundMode }, // "Sound Mode"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS(311), 0x00000000, menuhandlerScreenRatio }, // "Ratio"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_OPTIONS(312), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b00c
struct menudialog menudialog_1b00c = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(307), // "Audio/Visual"
	menuitems_audiovisual,
	menudialog0010559c,
	0x00000000,
	NULL,
};

// 1b024
struct menuitem menuitems_mpplayersetup[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(30), (u32)&mpGetCurrentPlayerName, &menudialog_mpplayername }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(33), 0x00000000, &menudialog_mpcontrol }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(34), 0x00000000, &menudialog_mpoptions }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(35), 0x00000000, &menudialog_mpplayerstats }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, &menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b0c4
struct menudialog menudialog_mpplayersetup = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup,
	NULL,
	0x00000800,
	&menudialog_mpchallengedetails,
};

struct menudialog menudialog_mpdropout;

// 1b0dc
struct menuitem menuitems_mpquickgo2[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(456), 0x00000000, &g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, &menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(458), 0x00000000, &menudialog_mpplayersetup }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(457), 0x00000000, &menudialog_mpdropout }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b140
struct menudialog menudialog_mpquickgo2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(460), // "Quick Go"
	menuitems_mpquickgo2,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

// 1b158
struct menuitem menuitems_1b158[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   0x00000037, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU(57), 0x00000000, menuhandler0010cabc }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU(58), 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

// 1b1bc
struct menudialog menudialog_1b1bc = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	menuitems_1b158,
	menudialog0017e3fc,
	0x00000000,
	NULL,
};

// 1b1d4
struct menuitem menuitems_mpcombatchallenges[] = {
	{ MENUITEMTYPE_CUSTOM,      1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b1fc
struct menudialog menudialog_mpcombatchallenges = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(50), // "Combat Challenges"
	menuitems_mpcombatchallenges,
	menudialog0017eb34,
	0x00000000,
	NULL,
};

// 1b214
struct menuitem menuitems_smallbutperfectmenu[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(441), 0x00000000, &menudialog_mpcombatchallenges }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(442), 0x00000001, &menudialog_mploadgamesettingstype1 }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(443), 0x00000002, &menudialog_mpquickteam }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(444), 0x00000003, menuhandler4MbAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(305), 0x00000000, &menudialog_1b00c }, // "Audio/Video"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(306), 0x00000000, &menudialog_changeagent }, // "Change Agent"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b2b4
struct menudialog g_4MbMainMenu = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(302), // "Small but Perfect Menu"
	menuitems_smallbutperfectmenu,
	menudialog4MbMainMenu,
	0x00000030,
	NULL,
};

// 1b2cc
struct menuitem menuitems_mpdropout[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(196), 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(197), 0x00000000, menuhandler4MbDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(198), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b31c
struct menudialog menudialog_mpdropout = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(195), // "Drop Out"
	menuitems_mpdropout,
	NULL,
	0x00000000,
	NULL,
};

// 1b334
struct menuitem menuitems_mpabort[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(53), 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(54), 0x00000000, menuhandler0010ca1c }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(55), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b384
struct menudialog menudialog_mpabort = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(52), // "Abort"
	menuitems_mpabort,
	NULL,
	0x00000000,
	NULL,
};

// 1b39c
struct menuitem menuitems_1b39c[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(95), 0x00000000, menuhandlerMpSimulantDifficulty }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(96), 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(98), 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(99), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b414
struct menudialog g_MpEditSimulant4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17cfc0,
	menuitems_1b39c,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

// 1b42c
struct menuitem menuitems_mpgamesetup[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, &menudialog_mpscenario }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, &menudialog_mparena }, // "Arena"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(44), 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), 0x00000000, &menudialog_mpweapons }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, &menudialog_mplimits }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(184), 0x00000000, &menudialog_mpplayerhandicaps }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(25), 0x00000000, &menudialog_mpsimulants }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(22), 0x00000000, &menudialog_mpteamcontrol }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(36), 0x00000000, &g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU(18), 0x00000000, &menudialog_mploadgamesettingstype0 }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(26), 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b558
struct menudialog g_4MbAdvancedSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	menuitems_mpgamesetup,
	menudialogMpGameSetup,
	0x00000810,
	&menudialog_mpplayersetup,
};

// 1b570
struct menuitem menuitems_1b570[] = {
	{ MENUITEMTYPE_OBJECTIVES,  1, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(298), 0x00000000, menuhandlerAcceptMission }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(299), 0x00000000, menuhandlerDeclineMission }, // "Decline"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b5c0
struct menudialog menudialog_1b5c0 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&menuDialogTitleRetryStageName,
	menuitems_1b570,
	menudialogRetryMission,
	0x0000000c,
	&menudialog_briefing,
};

// 1b5d8
struct menuitem g_MenuItemsPromptNextMission[] = {
	{ MENUITEMTYPE_OBJECTIVES,  1, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(298), 0x00000000, menuhandlerAcceptMission }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(299), 0x00000000, menuhandlerDeclineMission }, // "Decline"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MISC(470), 0x00000000, menuhandlerReplayPreviousMission }, // "Replay Previous Mission"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b650
struct menudialog g_MenuDialogPromptNextMission = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&menuDialogTitleNextMissionStageName,
	g_MenuItemsPromptNextMission,
	menudialogRetryMission,
	0x0000000c,
	&menudialog_briefing,
};

// 1b668
struct menuitem menuitems_1b668[] = {
	{ MENUITEMTYPE_OBJECTIVES,  2, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(301), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b6b8
struct menuitem menuitems_1b6b8[] = {
	{ MENUITEMTYPE_OBJECTIVES,  0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(301), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b708
struct menudialog menudialog_1b708 = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b6b8,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

// 1b720
struct menudialog menudialog_1b720 = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b6b8,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

// 1b738
struct menudialog menudialog_1b738 = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b668,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

// 1b750
struct menudialog menudialog_1b750 = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b668,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

// 1b768
struct menuitem menuitems_1b768[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(244), 0x00000000, menuhandlerContinueMission }, // "Continue"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(245), 0x00000000, menuhandlerReplayLastLevel }, // "Replay Last Level"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b7a4
struct menudialog menudialog_1b7a4 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&menuTextCurrentStageName3,
	menuitems_1b768,
	NULL,
	0x00000004,
	NULL,
};

// 1b7bc
struct menuitem g_MenuItemsSoloEndscreenNarrow[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS(278), 0x00000000, NULL }, // "Mission Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextMissionStatus, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS(279), 0x00000000, NULL }, // "Agent Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextAgentStatus, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS(280), 0x00000000, NULL }, // "Mission Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextMissionTime, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPWEAPONS(129), 0x00000000, NULL }, // "Difficulty"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)soloMenuTextDifficulty, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS(281), 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(282), (u32)&soloMenuTextNumKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(283), (u32)&soloMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(284), (u32)&soloMenuTextNumShots, NULL }, // "Shot Total:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS(285), (u32)&soloMenuTextNumHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS(286), (u32)&soloMenuTextNumBodyShots, NULL }, // "Body Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS(287), (u32)&soloMenuTextNumLimbShots, NULL }, // "Limb Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS(288), (u32)&soloMenuTextNumOtherShots, NULL }, // "Others:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(289), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

u32 g_CheatColour = 0xff7f7fff;

// 1b98c
struct menuitem g_MenuItemsSoloEndscreenWide[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(278), (u32)&soloMenuTextMissionStatus, NULL }, // "Mission Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(279), (u32)&soloMenuTextAgentStatus, NULL }, // "Agent Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x01000000, L_OPTIONS(280), (u32)&soloMenuTextMissionTime, menuhandlerEndscreenCheats }, // "Mission Time:"
	{ MENUITEMTYPE_LABEL,       1, 0x01000000, L_MPWEAPONS(242), (u32)&soloMenuTextTargetTime, menuhandlerEndscreenCheats }, // "Target Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPWEAPONS(129), (u32)&soloMenuTextDifficulty, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_SEPARATOR,   2, 0x00000000, 0x00000000, 0x00000000, menuhandlerEndscreenCheats },
	{ MENUITEMTYPE_LABEL,       2, 0x00000000, L_MPWEAPONS(243), 0x00000000, menuhandlerEndscreenCheats }, // "New Cheat Available!:"
	{ MENUITEMTYPE_LABEL,       3, 0x01000020, (u32)&soloMenuTextCheatName, 0x00000000, menuhandlerEndscreenCheats },
	{ MENUITEMTYPE_LABEL,       5, 0x01000020, (u32)&soloMenuTextCheatName2, 0x00000000, menuhandlerEndscreenCheats },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(281), (u32)&mpMenuTextWeaponOfChoiceName, NULL }, // "Weapon of Choice"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(282), (u32)&soloMenuTextNumKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(283), (u32)&soloMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(284), (u32)&soloMenuTextNumShots, NULL }, // "Shot Total:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(285), (u32)&soloMenuTextNumHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(286), (u32)&soloMenuTextNumBodyShots, NULL }, // "Body Shots:"
	{ MENUITEMTYPE_LABEL,       6, 0x00000000, L_OPTIONS(287), (u32)&soloMenuTextNumLimbShots, menuhandlerEndscreenCheats }, // "Limb Shots:"
	{ MENUITEMTYPE_LABEL,       4, 0x00000000, L_OPTIONS(288), (u32)&soloMenuTextNumOtherShots, menuhandlerEndscreenCheats }, // "Others:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(289), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1bb44
struct menudialog g_MenuDialogSoloEndscreenCompleted = {
	MENUDIALOGTYPE_SUCCESS,
	(u32)&menuTitleStageCompleted,
	g_MenuItemsSoloEndscreenWide,
	menudialog0010dd28,
	0x00000048,
	&menudialog_1b720,
};

// 1bb5c
struct menudialog g_MenuDialogSoloEndscreenFailed = {
	MENUDIALOGTYPE_DANGER,
	(u32)&menuTitleStageFailed,
	g_MenuItemsSoloEndscreenWide,
	menudialog0010de58,
	0x00000048,
	&menudialog_1b708,
};

// 1bb74
struct menudialog g_MenuDialogSolo2PEndscreenCompletedWide = {
	MENUDIALOGTYPE_SUCCESS,
	(u32)&menuTitleStageCompleted,
	g_MenuItemsSoloEndscreenWide,
	menudialog0010dd28,
	0x00000048,
	&menudialog_1b720,
};

// 1bb8c
struct menudialog g_MenuDialogSolo2PEndscreenFailedWide = {
	MENUDIALOGTYPE_DANGER,
	(u32)&menuTitleStageFailed,
	g_MenuItemsSoloEndscreenWide,
	menudialog0010de58,
	0x00000048,
	&menudialog_1b708,
};

// 1bba4
struct menudialog g_MenuDialogSolo2PEndscreenCompletedNarrow = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(276), // "Completed"
	g_MenuItemsSoloEndscreenNarrow,
	menudialog0010dd28,
	0x00000048,
	&menudialog_1b750,
};

// 1bbbc
struct menudialog g_MenuDialogSolo2PEndscreenFailedNarrow = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(277), // "Failed"
	g_MenuItemsSoloEndscreenNarrow,
	menudialog0010de58,
	0x00000048,
	&menudialog_1b738,
};

u32 var80075bb4 = 0x00000000;
u32 var80075bb8 = 0x00000000;
u32 var80075bbc = 0x00000000;

struct savelocation *g_SaveLocations[] = {NULL, NULL, NULL, NULL};

u32 var80075bd0 = 0x00000001;
u32 var80075bd4 = 0x00000001;
u32 var80075bd8 = 0x00000001;
u32 var80075bdc = 0x00000001;
u32 var80075be0 = 0x00000000;
u32 var80075be4 = 0x00000000;
u32 var80075be8 = 0x00000000;
u32 var80075bec = 0x00000000;
u32 var80075bf0 = 0x00000000;
u32 var80075bf4 = 0x00000000;
u32 var80075bf8 = 0x00000000;
u32 var80075bfc = 0x00000000;
