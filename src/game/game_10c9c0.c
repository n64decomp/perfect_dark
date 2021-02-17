#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_10c9c0.h"
#include "game/game_102240.h"
#include "game/game_19aa80.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/setup.h"
#include "gvars/gvars.h"
#include "types.h"

s32 menuhandler4MbDropOut(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();

		if (mpGetNumChrs() == 1) {
			func0f0f820c(&g_MainMenu4MbMenuDialog, MENUROOT_4MBMAINMENU);
		}
	}

	return 0;
}

s32 menuhandler0010ca1c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == STAGE_4MBMENU) {
			func0f0f820c(&g_MainMenu4MbMenuDialog, MENUROOT_4MBMAINMENU);
		} else {
			func0f0f820c(&g_SoloMissionPauseMenuDialog, MENUROOT_MAINMENU);
		}
	}

	return 0;
}

s32 menuhandler4MbAdvancedSetup(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(&g_AdvancedSetup4MbMenuDialog, MENUROOT_4MBMAINMENU);
	}

	return 0;
}

s32 menuhandler0010cabc(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mpSetCurrentChallenge(g_Menus[g_MpPlayerNum].data.main4mb.slotindex);
		func0f0f820c(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
	}

	return 0;
}

void func0f10cb2c(void)
{
	s32 i;
	u32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = 0;

	if (g_FileState != FILESTATE_UNSELECTED) {
		if (var80087260 == 0) {
			g_Vars.unk000490 = 2;
			menuPushRootDialog(&g_MainMenu4MbMenuDialog, MENUROOT_4MBMAINMENU);
		}
	} else {
		g_FileState = FILESTATE_SELECTED;

		for (i = 0; i != 6; i++) {
			mpPlayerSetDefaults(i, true);
		}

		g_Vars.bondplayernum = 0;
		g_Vars.coopplayernum = -1;
		g_Vars.antiplayernum = -1;

		mpDetermineUnlockedFeatures();

		menuPushRootDialog(&g_FilemgrFileSelect4MbMenuDialog, MENUROOT_4MBFILEMGR);
	}

	g_MpPlayerNum = prevplayernum;
}

s32 menudialog4MbMainMenu(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000494[0] = 0;
		g_Vars.unk000494[1] = 0;
		g_Vars.unk000494[2] = 0;
		g_Vars.unk000494[3] = 0;
	}

	if (g_Menus[g_MpPlayerNum].curframe &&
			g_Menus[g_MpPlayerNum].curframe->dialog == &g_MainMenu4MbMenuDialog &&
			operation == MENUOP_TICK) {
		g_Vars.unk000490 = 2;
		g_Vars.mpquickteam = MPQUICKTEAM_NONE;
		g_Vars.unk00049c = 0;
		mpClearCurrentChallenge();
		mpRemoveLock();
	}

	return false;
}

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

struct menudialog g_GameFiles4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(99), // "Game Files"
	g_GameFiles4MbMenuItems,
	NULL,
	0x00000020,
	NULL,
};

struct menuitem g_FilemgrFileSelect4MbMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(96), 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000f5, 0x00000000, filemgrChooseAgentListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileSelect4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(95), // "Perfect Dark"
	g_FilemgrFileSelect4MbMenuItems,
	filemgrMainMenuDialog,
	0x00000020,
	&g_GameFiles4MbMenuDialog,
};

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

struct menudialog g_AudioVideo4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(307), // "Audio/Visual"
	g_AudioVideo4MbMenuItems,
	menudialog0010559c,
	0x00000000,
	NULL,
};

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

struct menudialog g_MpPlayerSetup4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	g_MpPlayerSetup4MbMenuItems,
	NULL,
	0x00000800,
	&g_MpChallengeListOrDetailsMenuDialog,
};

struct menudialog g_MpDropOut4MbMenuDialog;

struct menuitem g_MpQuickGo4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(456), 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(458), 0x00000000, (void *)&g_MpPlayerSetup4MbMenuDialog }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(457), 0x00000000, (void *)&g_MpDropOut4MbMenuDialog }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickGo4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(460), // "Quick Go"
	g_MpQuickGo4MbMenuItems,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

struct menuitem g_MpConfirmChallenge4MbMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   0x00000037, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU(57), 0x00000000, menuhandler0010cabc }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU(58), 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

struct menudialog g_MpConfirmChallenge4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallenge4MbMenuItems,
	menudialog0017e3fc,
	0x00000000,
	NULL,
};

struct menuitem g_MpChallenges4MbMenuItems[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpChallenges4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(50), // "Combat Challenges"
	g_MpChallenges4MbMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000000,
	NULL,
};

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

struct menudialog g_MainMenu4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(302), // "Small but Perfect Menu"
	g_MainMenu4MbMenuItems,
	menudialog4MbMainMenu,
	0x00000030,
	NULL,
};

struct menuitem g_MpDropOut4MbMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(196), 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(197), 0x00000000, menuhandler4MbDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(198), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpDropOut4MbMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(195), // "Drop Out"
	g_MpDropOut4MbMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_UnusedAbortMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(53), 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(54), 0x00000000, menuhandler0010ca1c }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(55), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_UnusedAbortMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(52), // "Abort"
	g_UnusedAbortMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpEditSimulant4MbMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(95), 0x00000000, menuhandlerMpSimulantDifficulty }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(96), 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(98), 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(99), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpEditSimulant4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleEditSimulant,
	g_MpEditSimulant4MbMenuItems,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

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

struct menudialog g_AdvancedSetup4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	g_AdvancedSetup4MbMenuItems,
	menudialogMpGameSetup,
	0x00000810,
	&g_MpPlayerSetup4MbMenuDialog,
};
