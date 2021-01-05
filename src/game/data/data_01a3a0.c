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
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/training/training.h"
#include "gvars/gvars.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "stagesetup.h"
#include "types.h"

// 1ae10
struct menuitem g_GameFiles4MbMenuItems[] = {
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
struct menudialog g_GameFiles4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(99), // "Game Files"
	g_GameFiles4MbMenuItems,
	NULL,
	0x00000020,
	NULL,
};

// 1af18
struct menuitem g_FilemgrFileSelect4MbMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(96), 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000f5, 0x00000000, filemgrChooseAgentListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1af54
struct menudialog g_FilemgrFileSelect4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(95), // "Perfect Dark"
	g_FilemgrFileSelect4MbMenuItems,
	filemgrMainMenuDialog,
	0x00000020,
	&g_GameFiles4MbMenuDialog,
};

// 1af6c
struct menuitem g_AudioVideo4MbMenuItems[] = {
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
struct menudialog g_AudioVideo4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(307), // "Audio/Visual"
	g_AudioVideo4MbMenuItems,
	menudialog0010559c,
	0x00000000,
	NULL,
};

// 1b024
struct menuitem g_MpPlayerSetup4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(30), (u32)&mpGetCurrentPlayerName, (void *)&g_MpPlayerNameMenuDialog }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(33), 0x00000000, (void *)&g_MpControlMenuDialog }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(34), 0x00000000, (void *)&g_MpPlayerOptionsMenuDialog }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(35), 0x00000000, (void *)&g_MpPlayerStatsMenuDialog }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b0c4
struct menudialog g_MpPlayerSetup4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	g_MpPlayerSetup4MbMenuItems,
	NULL,
	0x00000800,
	&g_MpChallengeListOrDetailsMenuDialog,
};

struct menudialog g_MpDropOut4MbMenuDialog;

// 1b0dc
struct menuitem g_MpQuickGo4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(456), 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(458), 0x00000000, (void *)&g_MpPlayerSetup4MbMenuDialog }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(457), 0x00000000, (void *)&g_MpDropOut4MbMenuDialog }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b140
struct menudialog g_MpQuickGo4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(460), // "Quick Go"
	g_MpQuickGo4MbMenuItems,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

// 1b158
struct menuitem g_MpConfirmChallenge4MbMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   0x00000037, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU(57), 0x00000000, menuhandler0010cabc }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU(58), 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

// 1b1bc
struct menudialog g_MpConfirmChallenge4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallenge4MbMenuItems,
	menudialog0017e3fc,
	0x00000000,
	NULL,
};

// 1b1d4
struct menuitem g_MpChallenges4MbMenuItems[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b1fc
struct menudialog g_MpChallenges4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(50), // "Combat Challenges"
	g_MpChallenges4MbMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000000,
	NULL,
};

// 1b214
struct menuitem g_MainMenu4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(441), 0x00000000, (void *)&g_MpChallenges4MbMenuDialog }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(442), 0x00000001, (void *)&g_MpLoadPresetMenuDialog }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(443), 0x00000002, (void *)&g_MpQuickTeamMenuDialog }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(444), 0x00000003, menuhandler4MbAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(305), 0x00000000, (void *)&g_AudioVideo4MbMenuDialog }, // "Audio/Video"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(306), 0x00000000, (void *)&g_ChangeAgentMenuDialog }, // "Change Agent"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b2b4
struct menudialog g_MainMenu4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(302), // "Small but Perfect Menu"
	g_MainMenu4MbMenuItems,
	menudialog4MbMainMenu,
	0x00000030,
	NULL,
};

// 1b2cc
struct menuitem g_MpDropOut4MbMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(196), 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(197), 0x00000000, menuhandler4MbDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(198), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b31c
struct menudialog g_MpDropOut4MbMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(195), // "Drop Out"
	g_MpDropOut4MbMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 1b334
struct menuitem g_UnusedAbortMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(53), 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(54), 0x00000000, menuhandler0010ca1c }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(55), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b384
struct menudialog g_UnusedAbortMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(52), // "Abort"
	g_UnusedAbortMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 1b39c
struct menuitem g_MpEditSimulant4MbMenuItems[] = {
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
	g_MpEditSimulant4MbMenuItems,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

// 1b42c
struct menuitem g_AdvancedSetup4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, (void *)&g_MpScenarioMenuDialog }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, (void *)&g_MpArenaMenuDialog }, // "Arena"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(44), 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), 0x00000000, (void *)&g_MpWeaponsMenuDialog }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, (void *)&g_MpLimitsMenuDialog }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(184), 0x00000000, (void *)&g_MpHandicapsMenuDialog }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(25), 0x00000000, (void *)&g_MpSimulantsMenuDialog }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(22), 0x00000000, (void *)&g_MpTeamsMenuDialog }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(36), 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU(18), 0x00000000, (void *)&g_MpLoadSettingsMenuDialog }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(26), 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b558
struct menudialog g_AdvancedSetup4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	g_AdvancedSetup4MbMenuItems,
	menudialogMpGameSetup,
	0x00000810,
	&g_MpPlayerSetup4MbMenuDialog,
};
