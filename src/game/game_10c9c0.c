#include <ultra64.h>
#include "constants.h"
#include "game/menu.h"
#include "game/filemgr.h"
#include "game/game_10c9c0.h"
#include "game/mainmenu.h"
#include "game/game_19aa80.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/setup.h"
#include "bss.h"
#include "data.h"
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
		mpSetCurrentChallenge(g_Menus[g_MpPlayerNum].main4mb.slotindex);
		func0f0f820c(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
	}

	return 0;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f10cb2c
/*  f10d4ac:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10d4b0:	8dce1728 */ 	lw	$t6,0x1728($t6)
/*  f10d4b4:	3c028006 */ 	lui	$v0,0x8006
/*  f10d4b8:	3c018007 */ 	lui	$at,0x8007
/*  f10d4bc:	24422610 */ 	addiu	$v0,$v0,0x2610
/*  f10d4c0:	ac201728 */ 	sw	$zero,0x1728($at)
/*  f10d4c4:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f10d4c8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10d4cc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10d4d0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f10d4d4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f10d4d8:	11e0000e */ 	beqz	$t7,.PF0f10d514
/*  f10d4dc:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f10d4e0:	3c188008 */ 	lui	$t8,0x8008
/*  f10d4e4:	8f1877b0 */ 	lw	$t8,0x77b0($t8)
/*  f10d4e8:	3c10800a */ 	lui	$s0,0x800a
/*  f10d4ec:	2610a510 */ 	addiu	$s0,$s0,-23280
/*  f10d4f0:	17000024 */ 	bnez	$t8,.PF0f10d584
/*  f10d4f4:	24190002 */ 	li	$t9,0x2
/*  f10d4f8:	3c048007 */ 	lui	$a0,0x8007
/*  f10d4fc:	ae190490 */ 	sw	$t9,0x490($s0)
/*  f10d500:	24845758 */ 	addiu	$a0,$a0,0x5758
/*  f10d504:	0fc3e29d */ 	jal	menuPushRootDialog
/*  f10d508:	2405000b */ 	li	$a1,0xb
/*  f10d50c:	1000001e */ 	b	.PF0f10d588
/*  f10d510:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PF0f10d514:
/*  f10d514:	24080001 */ 	li	$t0,0x1
/*  f10d518:	a0480000 */ 	sb	$t0,0x0($v0)
/*  f10d51c:	00008025 */ 	move	$s0,$zero
/*  f10d520:	24110006 */ 	li	$s1,0x6
/*  f10d524:	02002025 */ 	move	$a0,$s0
.PF0f10d528:
/*  f10d528:	0fc623e7 */ 	jal	mpPlayerSetDefaults
/*  f10d52c:	24050001 */ 	li	$a1,0x1
/*  f10d530:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10d534:	5611fffc */ 	bnel	$s0,$s1,.PF0f10d528
/*  f10d538:	02002025 */ 	move	$a0,$s0
/*  f10d53c:	3c10800a */ 	lui	$s0,0x800a
/*  f10d540:	2610a510 */ 	addiu	$s0,$s0,-23280
/*  f10d544:	2402ffff */ 	li	$v0,-1
/*  f10d548:	ae000294 */ 	sw	$zero,0x294($s0)
/*  f10d54c:	ae020298 */ 	sw	$v0,0x298($s0)
/*  f10d550:	0fc67037 */ 	jal	mpDetermineUnlockedFeatures
/*  f10d554:	ae02029c */ 	sw	$v0,0x29c($s0)
/*  f10d558:	3c048007 */ 	lui	$a0,0x8007
/*  f10d55c:	248453e4 */ 	addiu	$a0,$a0,0x53e4
/*  f10d560:	0fc3e29d */ 	jal	menuPushRootDialog
/*  f10d564:	2405000a */ 	li	$a1,0xa
/*  f10d568:	96090482 */ 	lhu	$t1,0x482($s0)
/*  f10d56c:	3c048007 */ 	lui	$a0,0x8007
/*  f10d570:	29210006 */ 	slti	$at,$t1,0x6
/*  f10d574:	54200004 */ 	bnezl	$at,.PF0f10d588
/*  f10d578:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10d57c:	0fc3cda8 */ 	jal	menuPushDialog
/*  f10d580:	24844810 */ 	addiu	$a0,$a0,0x4810
.PF0f10d584:
/*  f10d584:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PF0f10d588:
/*  f10d588:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f10d58c:	3c018007 */ 	lui	$at,0x8007
/*  f10d590:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f10d594:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f10d598:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10d59c:	03e00008 */ 	jr	$ra
/*  f10d5a0:	ac2a1728 */ 	sw	$t2,0x1728($at)
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel func0f10cb2c
/*  f10d20c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10d210:	8dce3118 */ 	lw	$t6,0x3118($t6)
/*  f10d214:	3c028006 */ 	lui	$v0,0x8006
/*  f10d218:	3c018007 */ 	lui	$at,0x8007
/*  f10d21c:	24424000 */ 	addiu	$v0,$v0,0x4000
/*  f10d220:	ac203118 */ 	sw	$zero,0x3118($at)
/*  f10d224:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f10d228:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10d22c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10d230:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f10d234:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f10d238:	11e0000e */ 	beqz	$t7,.PB0f10d274
/*  f10d23c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f10d240:	3c188009 */ 	lui	$t8,0x8009
/*  f10d244:	8f189740 */ 	lw	$t8,-0x68c0($t8)
/*  f10d248:	3c10800a */ 	lui	$s0,0x800a
/*  f10d24c:	2610e4d0 */ 	addiu	$s0,$s0,-6960
/*  f10d250:	17000024 */ 	bnez	$t8,.PB0f10d2e4
/*  f10d254:	24190002 */ 	li	$t9,0x2
/*  f10d258:	3c048007 */ 	lui	$a0,0x8007
/*  f10d25c:	ae190490 */ 	sw	$t9,0x490($s0)
/*  f10d260:	24847068 */ 	addiu	$a0,$a0,0x7068
/*  f10d264:	0fc3e223 */ 	jal	0xf0f888c
/*  f10d268:	2405000b */ 	li	$a1,0xb
/*  f10d26c:	1000001e */ 	b	.PB0f10d2e8
/*  f10d270:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PB0f10d274:
/*  f10d274:	24080001 */ 	li	$t0,0x1
/*  f10d278:	a0480000 */ 	sb	$t0,0x0($v0)
/*  f10d27c:	00008025 */ 	move	$s0,$zero
/*  f10d280:	24110006 */ 	li	$s1,0x6
/*  f10d284:	02002025 */ 	move	$a0,$s0
.PB0f10d288:
/*  f10d288:	0fc626a7 */ 	jal	0xf189a9c
/*  f10d28c:	24050001 */ 	li	$a1,0x1
/*  f10d290:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10d294:	5611fffc */ 	bnel	$s0,$s1,.PB0f10d288
/*  f10d298:	02002025 */ 	move	$a0,$s0
/*  f10d29c:	3c10800a */ 	lui	$s0,0x800a
/*  f10d2a0:	2610e4d0 */ 	addiu	$s0,$s0,-6960
/*  f10d2a4:	2402ffff */ 	li	$v0,-1
/*  f10d2a8:	ae000294 */ 	sw	$zero,0x294($s0)
/*  f10d2ac:	ae020298 */ 	sw	$v0,0x298($s0)
/*  f10d2b0:	0fc67317 */ 	jal	0xf19cc5c
/*  f10d2b4:	ae02029c */ 	sw	$v0,0x29c($s0)
/*  f10d2b8:	3c048007 */ 	lui	$a0,0x8007
/*  f10d2bc:	24846cf4 */ 	addiu	$a0,$a0,0x6cf4
/*  f10d2c0:	0fc3e223 */ 	jal	0xf0f888c
/*  f10d2c4:	2405000a */ 	li	$a1,0xa
/*  f10d2c8:	96090482 */ 	lhu	$t1,0x482($s0)
/*  f10d2cc:	3c048007 */ 	lui	$a0,0x8007
/*  f10d2d0:	29210006 */ 	slti	$at,$t1,0x6
/*  f10d2d4:	54200004 */ 	bnezl	$at,.PB0f10d2e8
/*  f10d2d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10d2dc:	0fc3cd2e */ 	jal	0xf0f34b8
/*  f10d2e0:	24846120 */ 	addiu	$a0,$a0,0x6120
.PB0f10d2e4:
/*  f10d2e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PB0f10d2e8:
/*  f10d2e8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f10d2ec:	3c018007 */ 	lui	$at,0x8007
/*  f10d2f0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f10d2f4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f10d2f8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10d2fc:	03e00008 */ 	jr	$ra
/*  f10d300:	ac2a3118 */ 	sw	$t2,0x3118($at)
);
#else
void func0f10cb2c(void)
{
	s32 i;
	u32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = 0;

	if (g_FileState != FILESTATE_UNSELECTED) {
		if (var80087260 == 0) {
			g_Vars.mpsetupmenu = MPSETUPMENU_GENERAL;
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
#endif

s32 menudialog4MbMainMenu(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.waitingtojoin[0] = false;
		g_Vars.waitingtojoin[1] = false;
		g_Vars.waitingtojoin[2] = false;
		g_Vars.waitingtojoin[3] = false;
	}

	if (g_Menus[g_MpPlayerNum].curdialog
			&& g_Menus[g_MpPlayerNum].curdialog->definition == &g_MainMenu4MbMenuDialog
			&& operation == MENUOP_TICK) {
		g_Vars.mpsetupmenu = MPSETUPMENU_GENERAL;
		g_Vars.mpquickteam = MPQUICKTEAM_NONE;
		g_Vars.usingadvsetup = false;
		mpClearCurrentChallenge();
		mpRemoveLock();
	}

	return false;
}

struct menuitem g_GameFiles4MbMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_100, 0x00000000, NULL }, // "Copy:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS_103, 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS_104, 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS_105, 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_101, 0x00000000, NULL }, // "Delete:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS_103, 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS_104, 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS_105, 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_OPTIONS_102, 0x00000000, (void *)&g_PakChoosePakMenuDialog }, // "Delete Game Notes..."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_GameFiles4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_099, // "Game Files"
	g_GameFiles4MbMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK,
	NULL,
};

struct menuitem g_FilemgrFileSelect4MbMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_096, 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000f5, 0x00000000, filemgrChooseAgentListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrFileSelect4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_095, // "Perfect Dark"
	g_FilemgrFileSelect4MbMenuItems,
	filemgrMainMenuDialog,
	MENUDIALOGFLAG_IGNOREBACK,
	&g_GameFiles4MbMenuDialog,
};

struct menuitem g_AudioVideo4MbMenuItems[] = {
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SLIDER,      0, 0x00002800, L_OPTIONS_308, L_MPMENU_000, menuhandlerSfxVolume }, // "Sound"
	{ MENUITEMTYPE_SLIDER,      0, 0x00002800, L_OPTIONS_309, L_MPMENU_000, menuhandlerMusicVolume }, // "Music"
#else
	{ MENUITEMTYPE_SLIDER,      0, 0x00002800, L_OPTIONS_308, 0x7fff, menuhandlerSfxVolume }, // "Sound"
	{ MENUITEMTYPE_SLIDER,      0, 0x00002800, L_OPTIONS_309, 0x7fff, menuhandlerMusicVolume }, // "Music"
#endif
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS_310, 0x00000000, menuhandlerSoundMode }, // "Sound Mode"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS_311, 0x00000000, menuhandlerScreenRatio }, // "Ratio"
#if PAL
	{ MENUITEMTYPE_DROPDOWN,  0, 0x00000000, L_MPWEAPONS_269, 0x00000000, func0f1030e4pf }, // "Language"
#endif
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_OPTIONS_312, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_AudioVideo4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_307, // "Audio/Visual"
	g_AudioVideo4MbMenuItems,
	menudialog0010559c,
	0,
	NULL,
};

struct menuitem g_MpPlayerSetup4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_030, (u32)&mpGetCurrentPlayerName, (void *)&g_MpPlayerNameMenuDialog }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_033, 0x00000000, (void *)&g_MpControlMenuDialog }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_034, 0x00000000, (void *)&g_MpPlayerOptionsMenuDialog }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_035, 0x00000000, (void *)&g_MpPlayerStatsMenuDialog }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_029, 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpPlayerSetup4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup4MbMenuItems,
	NULL,
	MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpChallengeListOrDetailsMenuDialog,
};

struct menudialogdef g_MpDropOut4MbMenuDialog;

struct menuitem g_MpQuickGo4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_456, 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_029, 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
#endif
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_458, 0x00000000, (void *)&g_MpPlayerSetup4MbMenuDialog }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_457, 0x00000000, (void *)&g_MpDropOut4MbMenuDialog }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpQuickGo4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_460, // "Quick Go"
	g_MpQuickGo4MbMenuItems,
	menudialogMpQuickGo,
	0,
	NULL,
};

struct menuitem g_MpConfirmChallenge4MbMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   PAL ? 65 : 55, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU_057, 0x00000000, menuhandler0010cabc }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU_058, 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

struct menudialogdef g_MpConfirmChallenge4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallenge4MbMenuItems,
	menudialog0017e3fc,
	0,
	NULL,
};

struct menuitem g_MpChallenges4MbMenuItems[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000078, 0x0000004d, mpChallengesListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpChallenges4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_050, // "Combat Challenges"
	g_MpChallenges4MbMenuItems,
	mpCombatChallengesMenuDialog,
	0,
	NULL,
};

struct menuitem g_MainMenu4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_441, 0x00000000, (void *)&g_MpChallenges4MbMenuDialog }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_442, 0x00000001, (void *)&g_MpLoadPresetMenuDialog }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_443, 0x00000002, (void *)&g_MpQuickTeamMenuDialog }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC_444, 0x00000003, menuhandler4MbAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS_305, 0x00000000, (void *)&g_AudioVideo4MbMenuDialog }, // "Audio/Video"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS_306, 0x00000000, (void *)&g_ChangeAgentMenuDialog }, // "Change Agent"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MainMenu4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_302, // "Small but Perfect Menu"
	g_MainMenu4MbMenuItems,
	menudialog4MbMainMenu,
	MENUDIALOGFLAG_MPLOCKABLE | MENUDIALOGFLAG_IGNOREBACK,
	NULL,
};

struct menuitem g_MpDropOut4MbMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_196, 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_197, 0x00000000, menuhandler4MbDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_198, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpDropOut4MbMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_195, // "Drop Out"
	g_MpDropOut4MbMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_UnusedAbortMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_053, 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_054, 0x00000000, menuhandler0010ca1c }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_055, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_UnusedAbortMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_052, // "Abort"
	g_UnusedAbortMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpEditSimulant4MbMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU_095, 0x00000000, mpBotDifficultyMenuHandler }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_096, 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_098, 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_099, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpEditSimulant4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleEditSimulant,
	g_MpEditSimulant4MbMenuItems,
	menudialogMpSimulant,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_AdvancedSetup4MbMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU_019, (u32)&mpMenuTextScenarioShortName, (void *)&g_MpScenarioMenuDialog }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_021, 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_020, (u32)&mpMenuTextArenaName, (void *)&g_MpArenaMenuDialog }, // "Arena"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU_044, 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_023, 0x00000000, (void *)&g_MpWeaponsMenuDialog }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_024, 0x00000000, (void *)&g_MpLimitsMenuDialog }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS_184, 0x00000000, (void *)&g_MpHandicapsMenuDialog }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_025, 0x00000000, (void *)&g_MpSimulantsMenuDialog }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_022, 0x00000000, (void *)&g_MpTeamsMenuDialog }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_036, 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU_018, 0x00000000, (void *)&g_MpLoadSettingsMenuDialog }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_026, 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_AdvancedSetup4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_AdvancedSetup4MbMenuItems,
	menudialogMpGameSetup,
	MENUDIALOGFLAG_MPLOCKABLE | MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpPlayerSetup4MbMenuDialog,
};
