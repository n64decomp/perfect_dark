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
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(101), 0x00000000, NULL }, // "Delete:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_OPTIONS(102), 0x00000000, (void *)&g_PakChoosePakMenuDialog }, // "Delete Game Notes..."
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
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000f5, 0x00000000, filemgrChooseAgentListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1af54
struct menudialog menudialog_fileselect2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(95), // "Perfect Dark"
	menuitems_fileselect2,
	filemgrMainMenuDialog,
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
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(30), (u32)&mpGetCurrentPlayerName, (void *)&menudialog_mpplayername }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(33), 0x00000000, (void *)&menudialog_mpcontrol }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(34), 0x00000000, (void *)&menudialog_mpoptions }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(35), 0x00000000, (void *)&menudialog_mpplayerstats }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, (void *)&menudialog_mploadplayer }, // "Load Player"
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
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(456), 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, (void *)&menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(458), 0x00000000, (void *)&menudialog_mpplayersetup }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(457), 0x00000000, (void *)&menudialog_mpdropout }, // "Drop Out"
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
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b1fc
struct menudialog menudialog_mpcombatchallenges = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(50), // "Combat Challenges"
	menuitems_mpcombatchallenges,
	mpCombatChallengesMenuDialog,
	0x00000000,
	NULL,
};

// 1b214
struct menuitem menuitems_smallbutperfectmenu[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(441), 0x00000000, (void *)&menudialog_mpcombatchallenges }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(442), 0x00000001, (void *)&menudialog_mploadgamesettingstype1 }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(443), 0x00000002, (void *)&menudialog_mpquickteam }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(444), 0x00000003, menuhandler4MbAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(305), 0x00000000, (void *)&menudialog_1b00c }, // "Audio/Video"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(306), 0x00000000, (void *)&menudialog_changeagent }, // "Change Agent"
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
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, (void *)&menudialog_mpscenario }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, (void *)&menudialog_mparena }, // "Arena"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(44), 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), 0x00000000, (void *)&menudialog_mpweapons }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, (void *)&menudialog_mplimits }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(184), 0x00000000, (void *)&menudialog_mpplayerhandicaps }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(25), 0x00000000, (void *)&menudialog_mpsimulants }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(22), 0x00000000, (void *)&menudialog_mpteamcontrol }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(36), 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU(18), 0x00000000, (void *)&menudialog_mploadgamesettingstype0 }, // "Load Settings"
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
