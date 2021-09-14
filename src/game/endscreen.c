#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_095320.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/game_0e0770.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/endscreen.h"
#include "game/game_1655c0.h"
#include "game/lv.h"
#include "game/mplayer/ingame.h"
#include "game/game_19aa80.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/options.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

s32 menuhandlerDeclineMission(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

s32 menudialogRetryMission(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_TICK:
		{
			/**
			 * NTSC Final adds this check to make sure the given dialog is
			 * either the one being displayed or its sibling. This most likely
			 * fixes a bug - perhaps there is some way that this handler is run
			 * when the dialog is not on screen?
			 */
#if VERSION >= VERSION_NTSC_FINAL
			if (g_Menus[g_MpPlayerNum].curframe) {
				if (dialog == g_Menus[g_MpPlayerNum].curframe->dialog
						|| (dialog->nextsibling && dialog->nextsibling == g_Menus[g_MpPlayerNum].curframe->dialog)) {
#endif
					struct menuinputs *inputs = data->dialog2.inputs;
					bool accept = false;

					if (inputs->back) {
						menuPopDialog();
						menuPopDialog();
					}

					inputs->back = false;

					if (inputs->start) {
						accept = true;
					}

					inputs->start = false;

					if (inputs->select
							&& g_Menus[g_MpPlayerNum].curframe
							&& dialog->nextsibling
							&& dialog->nextsibling == g_Menus[g_MpPlayerNum].curframe->dialog) {
						accept = true;
						inputs->select = false;
					}

					if (accept) {
						union handlerdata data2;
						menuhandlerAcceptMission(MENUOP_SET, &dialog->items[1], &data2);
					}
#if VERSION >= VERSION_NTSC_FINAL
				}
			}
#endif
		}
	}

	menudialog00103608(operation, dialog, data);
}

char *menuDialogTitleRetryStageName(struct menudialog *dialog)
{
	char *name;
	char *prefix;

	if (g_Menus[g_MpPlayerNum].curframe->dialog != dialog) {
		return langGet(L_OPTIONS_300); // "Objectives"
	}

	prefix = langGet(L_OPTIONS_296); // "Retry"
	name = langGet(g_StageNames[g_MissionConfig.stageindex].name3);

	sprintf(g_StringPointer, "%s: %s\n", prefix, name);

	return g_StringPointer;
}

char *menuDialogTitleNextMissionStageName(struct menudialog *dialog)
{
	char *name;
	char *prefix;

	if (g_Menus[g_MpPlayerNum].curframe->dialog != dialog) {
		return langGet(L_OPTIONS_300); // "Objectives"
	}

	prefix = langGet(L_OPTIONS_297); // "Next Mission"
	name = langGet(g_StageNames[g_MissionConfig.stageindex].name3);

	sprintf(g_StringPointer, "%s: %s\n", prefix, name);

	return g_StringPointer;
}

s32 menuhandlerReplayPreviousMission(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.stageindex--;
		g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stagenum;
	}

	return menuhandlerAcceptMission(operation, NULL, data);
}

struct menuitem g_RetryMissionMenuItems[] = {
	{ MENUITEMTYPE_OBJECTIVES,  1, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS_298, 0x00000000, menuhandlerAcceptMission }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS_299, 0x00000000, menuhandlerDeclineMission }, // "Decline"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_RetryMissionMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&menuDialogTitleRetryStageName,
	g_RetryMissionMenuItems,
	menudialogRetryMission,
	0x0000000c,
	&g_PreAndPostMissionBriefingMenuDialog,
};

struct menuitem g_NextMissionMenuItems[] = {
	{ MENUITEMTYPE_OBJECTIVES,  1, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS_298, 0x00000000, menuhandlerAcceptMission }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS_299, 0x00000000, menuhandlerDeclineMission }, // "Decline"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MISC_470, 0x00000000, menuhandlerReplayPreviousMission }, // "Replay Previous Mission"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_NextMissionMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&menuDialogTitleNextMissionStageName,
	g_NextMissionMenuItems,
	menudialogRetryMission,
	0x0000000c,
	&g_PreAndPostMissionBriefingMenuDialog,
};

char *soloMenuTextNumKills(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstatsGetPlayerKillCount());
	return g_StringPointer;
}

char *soloMenuTextNumShots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstatsGetPlayerShotCountByRegion(SHOTREGION_TOTAL));
	return g_StringPointer;
}

char *soloMenuTextNumHeadShots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstatsGetPlayerShotCountByRegion(SHOTREGION_HEAD));
	return g_StringPointer;
}

char *soloMenuTextNumBodyShots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstatsGetPlayerShotCountByRegion(SHOTREGION_BODY));
	return g_StringPointer;
}

char *soloMenuTextNumLimbShots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstatsGetPlayerShotCountByRegion(SHOTREGION_LIMB));
	return g_StringPointer;
}

char *soloMenuTextNumOtherShots(struct menuitem *item)
{
	u32 total = mpstatsGetPlayerShotCountByRegion(SHOTREGION_GUN) + mpstatsGetPlayerShotCountByRegion(SHOTREGION_HAT);
	sprintf(g_StringPointer, "%d", total);
	return g_StringPointer;
}

char *soloMenuTextAccuracy(struct menuitem *item)
{
	s32 total = mpstatsGetPlayerShotCountByRegion(SHOTREGION_TOTAL);
	s32 numhead = mpstatsGetPlayerShotCountByRegion(SHOTREGION_HEAD);
	s32 numbody = mpstatsGetPlayerShotCountByRegion(SHOTREGION_BODY);
	s32 numlimb = mpstatsGetPlayerShotCountByRegion(SHOTREGION_LIMB);
	s32 numgun = mpstatsGetPlayerShotCountByRegion(SHOTREGION_GUN);
	s32 numhat = mpstatsGetPlayerShotCountByRegion(SHOTREGION_HAT);
	s32 numobject = mpstatsGetPlayerShotCountByRegion(SHOTREGION_OBJECT);
	f32 accuracy;

	if (total > 0) {
		s32 hits = numhead + numbody + numlimb + numgun + numhat + numobject;
		accuracy = hits * 100.0f / total;
	} else {
		accuracy = 0;
	}

	if (accuracy > 100.0f) {
		accuracy = 100.0f;
	}

	sprintf(g_StringPointer, "%s%s%.1f%%", "", "", accuracy);
	return g_StringPointer;
}

char *soloMenuTextMissionStatus(struct menuitem *item)
{
	if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
		return langGet(L_MPWEAPONS_135); // "Cheated"
	}

	if (g_Vars.coopplayernum >= 0) {
		if (g_Vars.bond->aborted || g_Vars.coop->aborted) {
			return langGet(L_OPTIONS_295); // "Aborted"
		}

		if (g_Vars.bond->isdead && g_Vars.coop->isdead) {
			return langGet(L_OPTIONS_293); // "Failed"
		}
	} else if (g_Vars.antiplayernum >= 0) {
		if (g_Vars.currentplayer == g_Vars.bond) {
			if (g_Vars.bond->aborted) {
				return langGet(L_OPTIONS_295); // "Aborted"
			}

			if (g_Vars.anti->aborted) {
				return langGet(L_OPTIONS_295); // "Aborted"
			}

			if (g_Vars.bond->isdead) {
				return langGet(L_OPTIONS_293); // "Failed"
			}
		} else {
			if (g_Vars.anti->aborted) {
				return langGet(L_OPTIONS_295); // "Aborted"
			}

			if (!g_Vars.bond->aborted && !g_Vars.bond->isdead) {
				return langGet(L_OPTIONS_293); // "Failed"
			}
		}
	} else {
		if (g_Vars.bond->aborted) {
			return langGet(L_OPTIONS_295); // "Aborted"
		}

		if (g_Vars.bond->isdead) {
			return langGet(L_OPTIONS_293); // "Failed"
		}
	}

	if (objectiveIsAllComplete() == false) {
		return langGet(L_OPTIONS_293); // "Failed"
	}

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		return langGet(L_MPWEAPONS_062); // "Unknown"
	}

	return langGet(L_OPTIONS_294); // "Completed"
}

char *soloMenuTextAgentStatus(struct menuitem *item)
{
	if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
		return langGet(L_MPWEAPONS_134); // "Dishonored"
	}

	if (g_Vars.currentplayer->aborted) {
		return langGet(L_OPTIONS_292); // "Disavowed"
	}

	if (g_Vars.currentplayer->isdead) {
		return langGet(L_OPTIONS_290); // "Deceased"
	}

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		return langGet(L_MPWEAPONS_063); // "Missing"
	}

	return langGet(L_OPTIONS_291); // "Active"
}

char *menuTitleStageCompleted(struct menuitem *item)
{
#if VERSION >= VERSION_NTSC_1_0
	sprintf(g_StringPointer, "%s: %s\n",
			langGet(g_StageNames[g_Menus[g_MpPlayerNum].data.endscreen.stageindex].name3),
			langGet(L_OPTIONS_276)); // "Completed"
#else
	sprintf(g_StringPointer, "%s: %s\n",
			langGet(g_StageNames[g_MissionConfig.stageindex].name3),
			langGet(L_OPTIONS_276)); // "Completed"
#endif

	return g_StringPointer;
}

#if VERSION >= VERSION_NTSC_1_0
char *menuTextCurrentStageName3(struct menuitem *item)
{
	char *name = langGet(g_StageNames[g_MissionConfig.stageindex].name3);
	sprintf(g_StringPointer, "%s\n", name);

	return g_StringPointer;
}
#endif

char *menuTitleStageFailed(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s: %s\n",
			langGet(g_StageNames[g_MissionConfig.stageindex].name3),
			langGet(L_OPTIONS_277)); // "Failed"

	return g_StringPointer;
}

char *soloMenuTextMissionTime(struct menuitem *item)
{
	formatTime(g_StringPointer, getMissionTime(), 3);
	strcat(g_StringPointer, "\n");

	return g_StringPointer;
}

#if VERSION >= VERSION_NTSC_1_0
struct menudialog *func0f10d730(void)
{
	g_MissionConfig.stageindex++;
	g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stagenum;

	return &g_NextMissionMenuDialog;
}
#else
GLOBAL_ASM(
glabel func0f10d730
/*  f10876c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f108770:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f108774:	3c10800a */ 	lui	$s0,0x800a
/*  f108778:	261027a8 */ 	addiu	$s0,$s0,0x27a8
/*  f10877c:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f108780:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f108784:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f108788:	15c1000e */ 	bne	$t6,$at,.NB0f1087c4
/*  f10878c:	240f005c */ 	addiu	$t7,$zero,0x5c
/*  f108790:	a20f0001 */ 	sb	$t7,0x1($s0)
/*  f108794:	0fc06ba1 */ 	jal	titleSetNextStage
/*  f108798:	31e400ff */ 	andi	$a0,$t7,0xff
/*  f10879c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f1087a0:	0004c642 */ 	srl	$t8,$a0,0x19
/*  f1087a4:	0fc59ed6 */ 	jal	lvSetDifficulty
/*  f1087a8:	03002025 */ 	or	$a0,$t8,$zero
/*  f1087ac:	0fc06945 */ 	jal	titleSetNextMode
/*  f1087b0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f1087b4:	0c003c56 */ 	jal	mainSetStageNum
/*  f1087b8:	92040001 */ 	lbu	$a0,0x1($s0)
/*  f1087bc:	1000000e */ 	beqz	$zero,.NB0f1087f8
/*  f1087c0:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1087c4:
/*  f1087c4:	92190002 */ 	lbu	$t9,0x2($s0)
/*  f1087c8:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1087cc:	3c028007 */ 	lui	$v0,0x8007
/*  f1087d0:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f1087d4:	310900ff */ 	andi	$t1,$t0,0xff
/*  f1087d8:	00095080 */ 	sll	$t2,$t1,0x2
/*  f1087dc:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1087e0:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1087e4:	a2080002 */ 	sb	$t0,0x2($s0)
/*  f1087e8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f1087ec:	8d6b43fc */ 	lw	$t3,0x43fc($t3)
/*  f1087f0:	24427a90 */ 	addiu	$v0,$v0,0x7a90
/*  f1087f4:	a20b0001 */ 	sb	$t3,0x1($s0)
.NB0f1087f8:
/*  f1087f8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1087fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f108800:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f108804:	03e00008 */ 	jr	$ra
/*  f108808:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void func0f10d770(void)
{
	func0f0f8bb4(&g_Menus[0].unk840, bgun0f09ddfc() - func0f0e4fe0(), 0);
	g_Menus[0].mpconfigbuffer = bgun0f09ddec() + func0f0e4fe0();

	func0f0f8bb4(&g_Menus[1].unk840, bgun0f09ddfc() - func0f0e4fe0(), 0);
	g_Menus[1].mpconfigbuffer = bgun0f09ddec() + func0f0e4fe0();

	func0f0f8bb4(&g_Menus[2].unk840, bgun0f09ddfc() - func0f0e4fe0(), 0);
	g_Menus[2].mpconfigbuffer = bgun0f09ddec() + func0f0e4fe0();

	func0f0f8bb4(&g_Menus[3].unk840, bgun0f09ddfc() - func0f0e4fe0(), 0);
	g_Menus[3].mpconfigbuffer = bgun0f09ddec() + func0f0e4fe0();
}

#if VERSION >= VERSION_NTSC_1_0
s32 menuhandlerReplayLastLevel(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stagenum;
		return menuhandlerAcceptMission(operation, NULL, data);
	}

	return 0;
}
#endif

struct menuitem g_2PMissionEndscreenObjectivesVMenuItems[] = {
	{ MENUITEMTYPE_OBJECTIVES,  2, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_301, 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menuitem g_SoloEndscreenObjectivesMenuItems[] = {
	{ MENUITEMTYPE_OBJECTIVES,  0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_301, 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_SoloEndscreenObjectivesFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_300, // "Objectives"
	g_SoloEndscreenObjectivesMenuItems,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

struct menudialog g_SoloEndscreenObjectivesCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_300, // "Objectives"
	g_SoloEndscreenObjectivesMenuItems,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

struct menudialog g_2PMissionEndscreenObjectivesFailedVMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_300, // "Objectives"
	g_2PMissionEndscreenObjectivesVMenuItems,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

struct menudialog g_2PMissionEndscreenObjectivesCompletedVMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_300, // "Objectives"
	g_2PMissionEndscreenObjectivesVMenuItems,
	soloMenuDialogPauseStatus,
	0x00000048,
	NULL,
};

#if VERSION >= VERSION_NTSC_1_0
/**
 * Displayed after Defense and Skedar Ruins completion screens.
 */
s32 menuhandlerContinueMission(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		endscreenHandleContinue(2);
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_MissionContinueOrReplyMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_244, 0x00000000, menuhandlerContinueMission }, // "Continue"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_245, 0x00000000, menuhandlerReplayLastLevel }, // "Replay Last Level"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MissionContinueOrReplyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&menuTextCurrentStageName3,
	g_MissionContinueOrReplyMenuItems,
	NULL,
	0x00000004,
	NULL,
};
#endif

#if VERSION >= VERSION_NTSC_1_0
/**
 * Context is:
 *
 * 0 when closing a completed endscreen
 * 1 unsure - is invoked directly by menuTickAll
 * 2 when pressing continue
 */
void endscreenHandleContinue(s32 context)
{
	if (g_Vars.antiplayernum >= 0) {
		menuPopDialog();
	} else if (g_Vars.coopplayernum >= 0 && PLAYERCOUNT() >= 2 && context == 0) {
		menuPopDialog();
	} else {
		if (g_Vars.stagenum == STAGE_DEEPSEA || g_Vars.stagenum == STAGE_SKEDARRUINS) {
			if (context == 2 || g_Menus[g_MpPlayerNum].data.endscreen.isfirstcompletion) {
				// Pressed continue
				if (g_Vars.stagenum == STAGE_DEEPSEA) {
					if (!isStageDifficultyUnlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty)) {
						menuPopDialog();
						menuPopDialog();
					} else {
						// Commit to starting next stage
						g_MissionConfig.stageindex++;
						g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stagenum;

						titleSetNextStage(g_MissionConfig.stagenum);

						if (g_MissionConfig.iscoop) {
							if (g_Vars.numaibuddies == 0) {
								g_Vars.bondplayernum = 0;
								g_Vars.coopplayernum = 1;
								g_Vars.antiplayernum = -1;
								setNumPlayers(2);
							} else {
								g_Vars.bondplayernum = 0;
								g_Vars.coopplayernum = -1;
								g_Vars.antiplayernum = -1;
								setNumPlayers(1);
							}
						} else {
							g_Vars.bondplayernum = 0;
							g_Vars.coopplayernum = -1;
							g_Vars.antiplayernum = -1;
							setNumPlayers(1);
						}

						lvSetDifficulty(g_MissionConfig.difficulty);
						titleSetNextMode(TITLEMODE_SKIP);
						mainSetStageNum(g_MissionConfig.stagenum);
						func00009ec4(true);
					}
				} else if (g_Vars.stagenum == STAGE_SKEDARRUINS) {
					// Commit to starting credits
					g_MissionConfig.stagenum = STAGE_CREDITS;
					titleSetNextStage(g_MissionConfig.stagenum);
					lvSetDifficulty(g_MissionConfig.difficulty);
					titleSetNextMode(TITLEMODE_SKIP);
					mainSetStageNum(g_MissionConfig.stagenum);
					func00009ec4(true);
				}
			} else {
				if (context == 1) {
					menuPushRootDialog(&g_MissionContinueOrReplyMenuDialog, MENUROOT_COOPCONTINUE);
				} else {
					menuPushDialog(&g_MissionContinueOrReplyMenuDialog);
				}
			}
		} else {
			if (context == 2) {
				menuPopDialog();
			}

			if (isStageDifficultyUnlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty) == 0) {
				if (context == 2) {
					menuPopDialog();
					menuPopDialog();
				} else {
					menuPushDialog(&g_MissionContinueOrReplyMenuDialog);
				}
			} else if (stageGetIndex(g_MissionConfig.stagenum) < 0
						|| g_Vars.stagenum == STAGE_CITRAINING
						|| g_MissionConfig.stageindex >= SOLOSTAGEINDEX_MBR) {
				if (context == 2) {
					menuPopDialog();
					menuPopDialog();
				} else {
					menuPushDialog(&g_MissionContinueOrReplyMenuDialog);
				}
			} else {
				func0f10d770();

				if (context == 1) {
					menuPushRootDialog(func0f10d730(), MENUROOT_COOPCONTINUE);
				} else {
					menuPushDialog(func0f10d730());
				}
			}
		}
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
s32 menudialogSolo2PEndscreenCompleted(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Menus[g_MpPlayerNum].data.endscreen.unke1c = 0;
	}

	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curframe) {
			if (g_Menus[g_MpPlayerNum].curframe->dialog == dialog
					|| (dialog->nextsibling && dialog->nextsibling == g_Menus[g_MpPlayerNum].curframe->dialog)) {
				struct menuinputs *inputs = data->dialog2.inputs;

				if (inputs->select || inputs->back || inputs->start) {
					g_Menus[g_MpPlayerNum].data.endscreen.unke1c = 6;
				}

				if (g_Menus[g_MpPlayerNum].data.endscreen.unke1c) {
					if (var8009dfc0) {
						g_Menus[g_MpPlayerNum].data.endscreen.unke1c--;
					}

					if (g_Menus[g_MpPlayerNum].data.endscreen.unke1c == 0) {
						endscreenHandleContinue(0);
					}
				}

				inputs->select = inputs->back = inputs->start = false;
			}
		}
	}

	return 0;
}
#else
GLOBAL_ASM(
glabel menudialogSolo2PEndscreenCompleted
/*  f108918:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10891c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f108920:	1481000d */ 	bne	$a0,$at,.NB0f108958
/*  f108924:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108928:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10892c:	8dce3af0 */ 	lw	$t6,0x3af0($t6)
/*  f108930:	3c01800a */ 	lui	$at,0x800a
/*  f108934:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108938:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10893c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108940:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108944:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108948:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10894c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108950:	002f0821 */ 	addu	$at,$at,$t7
/*  f108954:	ac203538 */ 	sw	$zero,0x3538($at)
.NB0f108958:
/*  f108958:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10895c:	148100c9 */ 	bne	$a0,$at,.NB0f108c84
/*  f108960:	3c188007 */ 	lui	$t8,0x8007
/*  f108964:	8f183af0 */ 	lw	$t8,0x3af0($t8)
/*  f108968:	3c08800a */ 	lui	$t0,0x800a
/*  f10896c:	250827c0 */ 	addiu	$t0,$t0,0x27c0
/*  f108970:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f108974:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f108978:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10897c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f108980:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f108984:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f108988:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10898c:	03281821 */ 	addu	$v1,$t9,$t0
/*  f108990:	8c620488 */ 	lw	$v0,0x488($v1)
/*  f108994:	504000bc */ 	beqzl	$v0,.NB0f108c88
/*  f108998:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10899c:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1089a0:	50a40007 */ 	beql	$a1,$a0,.NB0f1089c0
/*  f1089a4:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f1089a8:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f1089ac:	504000b6 */ 	beqzl	$v0,.NB0f108c88
/*  f1089b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1089b4:	544400b4 */ 	bnel	$v0,$a0,.NB0f108c88
/*  f1089b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1089bc:	8cc90000 */ 	lw	$t1,0x0($a2)
.NB0f1089c0:
/*  f1089c0:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f1089c4:	3c0f800a */ 	lui	$t7,0x800a
/*  f1089c8:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f1089cc:	912b0002 */ 	lbu	$t3,0x2($t1)
/*  f1089d0:	55600008 */ 	bnezl	$t3,.NB0f1089f4
/*  f1089d4:	ac6e0d78 */ 	sw	$t6,0xd78($v1)
/*  f1089d8:	912c0003 */ 	lbu	$t4,0x3($t1)
/*  f1089dc:	55800005 */ 	bnezl	$t4,.NB0f1089f4
/*  f1089e0:	ac6e0d78 */ 	sw	$t6,0xd78($v1)
/*  f1089e4:	812d000a */ 	lb	$t5,0xa($t1)
/*  f1089e8:	51a00003 */ 	beqzl	$t5,.NB0f1089f8
/*  f1089ec:	8c620d78 */ 	lw	$v0,0xd78($v1)
/*  f1089f0:	ac6e0d78 */ 	sw	$t6,0xd78($v1)
.NB0f1089f4:
/*  f1089f4:	8c620d78 */ 	lw	$v0,0xd78($v1)
.NB0f1089f8:
/*  f1089f8:	5040009f */ 	beqzl	$v0,.NB0f108c78
/*  f1089fc:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f108a00:	8def2780 */ 	lw	$t7,0x2780($t7)
/*  f108a04:	3c05800a */ 	lui	$a1,0x800a
/*  f108a08:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f108a0c:	11e00003 */ 	beqz	$t7,.NB0f108a1c
/*  f108a10:	24a5e6c0 */ 	addiu	$a1,$a1,-6464
/*  f108a14:	ac780d78 */ 	sw	$t8,0xd78($v1)
/*  f108a18:	03001025 */ 	or	$v0,$t8,$zero
.NB0f108a1c:
/*  f108a1c:	54400096 */ 	bnezl	$v0,.NB0f108c78
/*  f108a20:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f108a24:	8cb904b4 */ 	lw	$t9,0x4b4($a1)
/*  f108a28:	24010038 */ 	addiu	$at,$zero,0x38
/*  f108a2c:	57210046 */ 	bnel	$t9,$at,.NB0f108b48
/*  f108a30:	8cad029c */ 	lw	$t5,0x29c($a1)
/*  f108a34:	8ca8029c */ 	lw	$t0,0x29c($a1)
/*  f108a38:	05010021 */ 	bgez	$t0,.NB0f108ac0
/*  f108a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108a40:	8ca90298 */ 	lw	$t1,0x298($a1)
/*  f108a44:	05200022 */ 	bltz	$t1,.NB0f108ad0
/*  f108a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108a4c:	8cab006c */ 	lw	$t3,0x6c($a1)
/*  f108a50:	00003025 */ 	or	$a2,$zero,$zero
/*  f108a54:	00002025 */ 	or	$a0,$zero,$zero
/*  f108a58:	11600003 */ 	beqz	$t3,.NB0f108a68
/*  f108a5c:	00001825 */ 	or	$v1,$zero,$zero
/*  f108a60:	10000001 */ 	beqz	$zero,.NB0f108a68
/*  f108a64:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f108a68:
/*  f108a68:	8cac0068 */ 	lw	$t4,0x68($a1)
/*  f108a6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f108a70:	11800003 */ 	beqz	$t4,.NB0f108a80
/*  f108a74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108a78:	10000001 */ 	beqz	$zero,.NB0f108a80
/*  f108a7c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f108a80:
/*  f108a80:	8caa0064 */ 	lw	$t2,0x64($a1)
/*  f108a84:	11400003 */ 	beqz	$t2,.NB0f108a94
/*  f108a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108a8c:	10000001 */ 	beqz	$zero,.NB0f108a94
/*  f108a90:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f108a94:
/*  f108a94:	8cad0070 */ 	lw	$t5,0x70($a1)
/*  f108a98:	11a00003 */ 	beqz	$t5,.NB0f108aa8
/*  f108a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108aa0:	10000001 */ 	beqz	$zero,.NB0f108aa8
/*  f108aa4:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f108aa8:
/*  f108aa8:	00437021 */ 	addu	$t6,$v0,$v1
/*  f108aac:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f108ab0:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f108ab4:	2b010002 */ 	slti	$at,$t8,0x2
/*  f108ab8:	14200005 */ 	bnez	$at,.NB0f108ad0
/*  f108abc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f108ac0:
/*  f108ac0:	0fc3c088 */ 	jal	menuPopDialog
/*  f108ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108ac8:	1000006b */ 	beqz	$zero,.NB0f108c78
/*  f108acc:	8fb8001c */ 	lw	$t8,0x1c($sp)
.NB0f108ad0:
/*  f108ad0:	3c03800a */ 	lui	$v1,0x800a
/*  f108ad4:	246327a8 */ 	addiu	$v1,$v1,0x27a8
/*  f108ad8:	90790002 */ 	lbu	$t9,0x2($v1)
/*  f108adc:	3c0c8007 */ 	lui	$t4,0x8007
/*  f108ae0:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f108ae4:	310900ff */ 	andi	$t1,$t0,0xff
/*  f108ae8:	00095880 */ 	sll	$t3,$t1,0x2
/*  f108aec:	01695823 */ 	subu	$t3,$t3,$t1
/*  f108af0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f108af4:	a0680002 */ 	sb	$t0,0x2($v1)
/*  f108af8:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f108afc:	8d8c43fc */ 	lw	$t4,0x43fc($t4)
/*  f108b00:	a06c0001 */ 	sb	$t4,0x1($v1)
/*  f108b04:	0fc06ba1 */ 	jal	titleSetNextStage
/*  f108b08:	318400ff */ 	andi	$a0,$t4,0xff
/*  f108b0c:	3c03800a */ 	lui	$v1,0x800a
/*  f108b10:	246327a8 */ 	addiu	$v1,$v1,0x27a8
/*  f108b14:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f108b18:	00045642 */ 	srl	$t2,$a0,0x19
/*  f108b1c:	0fc59ed6 */ 	jal	lvSetDifficulty
/*  f108b20:	01402025 */ 	or	$a0,$t2,$zero
/*  f108b24:	0fc06945 */ 	jal	titleSetNextMode
/*  f108b28:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f108b2c:	3c03800a */ 	lui	$v1,0x800a
/*  f108b30:	246327a8 */ 	addiu	$v1,$v1,0x27a8
/*  f108b34:	0c003c56 */ 	jal	mainSetStageNum
/*  f108b38:	90640001 */ 	lbu	$a0,0x1($v1)
/*  f108b3c:	1000004e */ 	beqz	$zero,.NB0f108c78
/*  f108b40:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f108b44:	8cad029c */ 	lw	$t5,0x29c($a1)
.NB0f108b48:
/*  f108b48:	05a10040 */ 	bgez	$t5,.NB0f108c4c
/*  f108b4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108b50:	8cae0298 */ 	lw	$t6,0x298($a1)
/*  f108b54:	05c0001d */ 	bltz	$t6,.NB0f108bcc
/*  f108b58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108b5c:	8caf006c */ 	lw	$t7,0x6c($a1)
/*  f108b60:	00003025 */ 	or	$a2,$zero,$zero
/*  f108b64:	00002025 */ 	or	$a0,$zero,$zero
/*  f108b68:	11e00003 */ 	beqz	$t7,.NB0f108b78
/*  f108b6c:	00001825 */ 	or	$v1,$zero,$zero
/*  f108b70:	10000001 */ 	beqz	$zero,.NB0f108b78
/*  f108b74:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f108b78:
/*  f108b78:	8cb80068 */ 	lw	$t8,0x68($a1)
/*  f108b7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f108b80:	13000003 */ 	beqz	$t8,.NB0f108b90
/*  f108b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108b88:	10000001 */ 	beqz	$zero,.NB0f108b90
/*  f108b8c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f108b90:
/*  f108b90:	8cb90064 */ 	lw	$t9,0x64($a1)
/*  f108b94:	13200003 */ 	beqz	$t9,.NB0f108ba4
/*  f108b98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108b9c:	10000001 */ 	beqz	$zero,.NB0f108ba4
/*  f108ba0:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f108ba4:
/*  f108ba4:	8ca80070 */ 	lw	$t0,0x70($a1)
/*  f108ba8:	11000003 */ 	beqz	$t0,.NB0f108bb8
/*  f108bac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108bb0:	10000001 */ 	beqz	$zero,.NB0f108bb8
/*  f108bb4:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f108bb8:
/*  f108bb8:	00434821 */ 	addu	$t1,$v0,$v1
/*  f108bbc:	01245821 */ 	addu	$t3,$t1,$a0
/*  f108bc0:	01666021 */ 	addu	$t4,$t3,$a2
/*  f108bc4:	29810002 */ 	slti	$at,$t4,0x2
/*  f108bc8:	10200020 */ 	beqz	$at,.NB0f108c4c
.NB0f108bcc:
/*  f108bcc:	3c03800a */ 	lui	$v1,0x800a
/*  f108bd0:	246327a8 */ 	addiu	$v1,$v1,0x27a8
/*  f108bd4:	0fc57f85 */ 	jal	stageGetIndex
/*  f108bd8:	90640001 */ 	lbu	$a0,0x1($v1)
/*  f108bdc:	3c03800a */ 	lui	$v1,0x800a
/*  f108be0:	3c05800a */ 	lui	$a1,0x800a
/*  f108be4:	24a5e6c0 */ 	addiu	$a1,$a1,-6464
/*  f108be8:	04400018 */ 	bltz	$v0,.NB0f108c4c
/*  f108bec:	246327a8 */ 	addiu	$v1,$v1,0x27a8
/*  f108bf0:	8caa04b4 */ 	lw	$t2,0x4b4($a1)
/*  f108bf4:	24010026 */ 	addiu	$at,$zero,0x26
/*  f108bf8:	11410014 */ 	beq	$t2,$at,.NB0f108c4c
/*  f108bfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c00:	90620002 */ 	lbu	$v0,0x2($v1)
/*  f108c04:	3c0d800a */ 	lui	$t5,0x800a
/*  f108c08:	28410011 */ 	slti	$at,$v0,0x11
/*  f108c0c:	1020000f */ 	beqz	$at,.NB0f108c4c
/*  f108c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c14:	8dad66c0 */ 	lw	$t5,0x66c0($t5)
/*  f108c18:	3c0e800a */ 	lui	$t6,0x800a
/*  f108c1c:	55a00005 */ 	bnezl	$t5,.NB0f108c34
/*  f108c20:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f108c24:	8dce66c4 */ 	lw	$t6,0x66c4($t6)
/*  f108c28:	11c0000c */ 	beqz	$t6,.NB0f108c5c
/*  f108c2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c30:	8c650000 */ 	lw	$a1,0x0($v1)
.NB0f108c34:
/*  f108c34:	24440001 */ 	addiu	$a0,$v0,0x1
/*  f108c38:	00057e42 */ 	srl	$t7,$a1,0x19
/*  f108c3c:	0fc3fdde */ 	jal	isStageDifficultyUnlocked
/*  f108c40:	01e02825 */ 	or	$a1,$t7,$zero
/*  f108c44:	14400005 */ 	bnez	$v0,.NB0f108c5c
/*  f108c48:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f108c4c:
/*  f108c4c:	0fc3c088 */ 	jal	menuPopDialog
/*  f108c50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c54:	10000008 */ 	beqz	$zero,.NB0f108c78
/*  f108c58:	8fb8001c */ 	lw	$t8,0x1c($sp)
.NB0f108c5c:
/*  f108c5c:	0fc42203 */ 	jal	func0f10d770
/*  f108c60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c64:	0fc421db */ 	jal	func0f10d730
/*  f108c68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c6c:	0fc3beda */ 	jal	menuPushDialog
/*  f108c70:	00402025 */ 	or	$a0,$v0,$zero
/*  f108c74:	8fb8001c */ 	lw	$t8,0x1c($sp)
.NB0f108c78:
/*  f108c78:	a300000a */ 	sb	$zero,0xa($t8)
/*  f108c7c:	a3000003 */ 	sb	$zero,0x3($t8)
/*  f108c80:	a3000002 */ 	sb	$zero,0x2($t8)
.NB0f108c84:
/*  f108c84:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f108c88:
/*  f108c88:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f108c8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f108c90:	03e00008 */ 	jr	$ra
/*  f108c94:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

s32 menudialogSolo2PEndscreenFailed(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Menus[g_MpPlayerNum].data.endscreen.unke1c = 0;
	}

	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curframe) {
			if (g_Menus[g_MpPlayerNum].curframe->dialog == dialog
					|| (dialog->nextsibling && dialog->nextsibling == g_Menus[g_MpPlayerNum].curframe->dialog)) {
				struct menuinputs *inputs = data->dialog2.inputs;

				if (inputs->select || inputs->back || inputs->start) {
					g_Menus[g_MpPlayerNum].data.endscreen.unke1c = 6;
				}

				if (g_Menus[g_MpPlayerNum].data.endscreen.unke1c) {
					if (var8009dfc0) {
						g_Menus[g_MpPlayerNum].data.endscreen.unke1c--;
					}

					if (g_Menus[g_MpPlayerNum].data.endscreen.unke1c == 0) {
						if (g_Vars.antiplayernum >= 0
								|| (g_Vars.coopplayernum >= 0 && PLAYERCOUNT() >= 2)
								|| stageGetIndex(g_MissionConfig.stagenum) < 0
								|| g_Vars.stagenum == STAGE_CITRAINING) {
							menuPopDialog();
						} else {
							func0f10d770();
							menuPushDialog(&g_RetryMissionMenuDialog);
						}
					}
				}

				inputs->select = inputs->back = inputs->start = false;
			}
		}
	}

	return 0;
}

struct menuitem g_2PMissionEndscreenVMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS_278, 0x00000000, NULL }, // "Mission Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextMissionStatus, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS_279, 0x00000000, NULL }, // "Agent Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextAgentStatus, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS_280, 0x00000000, NULL }, // "Mission Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextMissionTime, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPWEAPONS_129, 0x00000000, NULL }, // "Difficulty"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)soloMenuTextDifficulty, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_OPTIONS_281, 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_282, (u32)&soloMenuTextNumKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_283, (u32)&soloMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_284, (u32)&soloMenuTextNumShots, NULL }, // "Shot Total:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS_285, (u32)&soloMenuTextNumHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS_286, (u32)&soloMenuTextNumBodyShots, NULL }, // "Body Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS_287, (u32)&soloMenuTextNumLimbShots, NULL }, // "Limb Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_OPTIONS_288, (u32)&soloMenuTextNumOtherShots, NULL }, // "Others:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_289, 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

u32 g_CheatColour = 0xff7f7fff;

struct menuitem g_MissionEndscreenMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_278, (u32)&soloMenuTextMissionStatus, NULL }, // "Mission Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_279, (u32)&soloMenuTextAgentStatus, NULL }, // "Agent Status:"
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x01000000, L_OPTIONS_280, (u32)&soloMenuTextMissionTime, menuhandlerEndscreenCheats }, // "Mission Time:"
	{ MENUITEMTYPE_LABEL,       1, 0x01000000, L_MPWEAPONS_242, (u32)&soloMenuTextTargetTime, menuhandlerEndscreenCheats }, // "Target Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPWEAPONS_129, (u32)&soloMenuTextDifficulty, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_SEPARATOR,   2, 0x00000000, 0x00000000, 0x00000000, menuhandlerEndscreenCheats },
	{ MENUITEMTYPE_LABEL,       2, 0x00000000, L_MPWEAPONS_243, 0x00000000, menuhandlerEndscreenCheats }, // "New Cheat Available!:"
	{ MENUITEMTYPE_LABEL,       3, 0x01000020, (u32)&soloMenuTextTimedCheatName, 0x00000000, menuhandlerEndscreenCheats },
	{ MENUITEMTYPE_LABEL,       5, 0x01000020, (u32)&soloMenuTextCompletionCheatName, 0x00000000, menuhandlerEndscreenCheats },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_281, (u32)&mpMenuTextWeaponOfChoiceName, NULL }, // "Weapon of Choice"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_282, (u32)&soloMenuTextNumKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_283, (u32)&soloMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_284, (u32)&soloMenuTextNumShots, NULL }, // "Shot Total:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_285, (u32)&soloMenuTextNumHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_286, (u32)&soloMenuTextNumBodyShots, NULL }, // "Body Shots:"
	{ MENUITEMTYPE_LABEL,       6, 0x00000000, L_OPTIONS_287, (u32)&soloMenuTextNumLimbShots, menuhandlerEndscreenCheats }, // "Limb Shots:"
	{ MENUITEMTYPE_LABEL,       4, 0x00000000, L_OPTIONS_288, (u32)&soloMenuTextNumOtherShots, menuhandlerEndscreenCheats }, // "Others:"
#endif
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_289, 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

#if VERSION >= VERSION_NTSC_1_0
/**
 * This function is re-used for several values on the endscreen.
 * item->param is used to determine which value it is. Values are:
 *
 * 0 = mission time
 * 1 = target time
 * 2 = separator and new cheat available
 * 3 = completion cheat name
 * 4 = others (shots)
 * 5 = timed cheat name
 * 6 = limb shots
 */
s32 menuhandlerEndscreenCheats(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR
			&& ((g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x200) || item->param == 5)) {
		// Timed cheat just got unlocked, and this item is the timed cheat name
		u32 weight = func0f006b08(40) * 255;

		func0000db30("ctcol", &g_CheatColour);

		if (item->param == 0
				&& cheatGetTime(g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xff) == 0) {
			return 0;
		}

		data->label.colour2 = colourBlend(data->label.colour2, g_CheatColour, weight);

		if (item->param == 3) { // completion cheat name
			data->label.colour1 = colourBlend(data->label.colour1, g_CheatColour, weight);
		}

		if (item->param == 5) { // timed cheat name
			data->label.colour1 = colourBlend(data->label.colour1, g_CheatColour, weight);
		}
	}

	if (operation == MENUOP_CHECKHIDDEN) {
		if (item->param == 1) { // target time
			u32 info = g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo;

			if (info & 0x800) { // completion cheat just got unlocked
				return true;
			}

			// (has timed cheat)
			// and (timed cheat just got unlocked or timed cheat already unlocked) == 0
			// and cheat has a target time configured
			if ((info & 0x100) && (info & 0x600) == 0 && cheatGetTime(info & 0xff) > 0) {
				return false;
			}

			return true;
		} else if (item->param == 2 && (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xa00) == 0) {
			// new cheat available
			return true;
		} else if (item->param == 3 && (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x200) == 0) {
			// completion cheat name
			return true;
		} else if (item->param == 4 && (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xa00)) {
			// others (shots)
			return true;
		} else if (item->param == 6 && (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xa00) == 0xa00) {
			// limb shots
			return true;
		} else if (item->param == 5 && (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x800) == 0) {
			// timed cheat name
			return true;
		}
	}

	return false;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *soloMenuTextTimedCheatName(struct menuitem *item)
{
	if (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x00000300) {
		return cheatGetName(g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xff);
	}

	return NULL;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *soloMenuTextCompletionCheatName(struct menuitem *item)
{
	if (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x00000800) {
		return cheatGetName((g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo >> 16) & 0xff);
	}

	return NULL;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel soloMenuTextTargetTime
/*  f10e4d8:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10e4dc:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10e4e0:	3c02800a */ 	lui	$v0,%hi(g_Menus+0xe20)
/*  f10e4e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10e4e8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e4ec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e4f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e4f4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e4f8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e4fc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e500:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e504:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10e508:	8c42ee20 */ 	lw	$v0,%lo(g_Menus+0xe20)($v0)
/*  f10e50c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e510:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10e514:	30580100 */ 	andi	$t8,$v0,0x100
/*  f10e518:	17000003 */ 	bnez	$t8,.L0f10e528
/*  f10e51c:	00000000 */ 	nop
/*  f10e520:	10000015 */ 	b	.L0f10e578
/*  f10e524:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e528:
/*  f10e528:	0fc41fd9 */ 	jal	cheatGetTime
/*  f10e52c:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e530:	14400003 */ 	bnez	$v0,.L0f10e540
/*  f10e534:	00403825 */ 	or	$a3,$v0,$zero
/*  f10e538:	1000000f */ 	b	.L0f10e578
/*  f10e53c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e540:
/*  f10e540:	00072900 */ 	sll	$a1,$a3,0x4
/*  f10e544:	00a72823 */ 	subu	$a1,$a1,$a3
/*  f10e548:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10e54c:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10e550:	00052880 */ 	sll	$a1,$a1,0x2
/*  f10e554:	0fc355f8 */ 	jal	formatTime
/*  f10e558:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f10e55c:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10e560:	3c057f1b */ 	lui	$a1,%hi(var7f1b38bc)
/*  f10e564:	24a538bc */ 	addiu	$a1,$a1,%lo(var7f1b38bc)
/*  f10e568:	0c004c89 */ 	jal	strcat
/*  f10e56c:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10e570:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f10e574:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
.L0f10e578:
/*  f10e578:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10e57c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10e580:	03e00008 */ 	jr	$ra
/*  f10e584:	00000000 */ 	nop
);

const char var7f1b38bc[] = "\n";

// regalloc
//char *soloMenuTextTargetTime(struct menuitem *item)
//{
//	s32 time;
//
//	if ((g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x00000100) == 0) {
//		return NULL;
//	}
//
//	time = cheatGetTime(g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xff);
//
//	if (!time) {
//		return NULL;
//	}
//
//	formatTime(g_StringPointer, time * 60, 3);
//	strcat(g_StringPointer, "\n");
//	return g_StringPointer;
//}
#endif

void endscreenSetCoopCompleted(void)
{
	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0) {
#if VERSION >= VERSION_NTSC_1_0
		if (g_GameFile.coopcompletions[g_MissionConfig.difficulty] & (1 << g_MissionConfig.stageindex)) {
			g_Menus[g_MpPlayerNum].data.endscreen.isfirstcompletion = true;
		}
#endif

		g_GameFile.coopcompletions[g_MissionConfig.difficulty] |= (1 << g_MissionConfig.stageindex);
	}
}

struct menudialog g_SoloMissionEndscreenCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	(u32)&menuTitleStageCompleted,
	g_MissionEndscreenMenuItems,
	menudialogSolo2PEndscreenCompleted,
	0x00000048,
	&g_SoloEndscreenObjectivesCompletedMenuDialog,
};

struct menudialog g_SoloMissionEndscreenFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&menuTitleStageFailed,
	g_MissionEndscreenMenuItems,
	menudialogSolo2PEndscreenFailed,
	0x00000048,
	&g_SoloEndscreenObjectivesFailedMenuDialog,
};

#if VERSION >= VERSION_NTSC_1_0
void endscreenPrepare(void)
{
	s32 timedcheatid;
	s32 complcheatid;
	s32 d;
	s32 s;
	u32 secs;
	s32 timedalreadyunlocked;
	s32 complalreadyunlocked;
	u16 prevbest;
	bool nowunlocked;

	g_Menus[g_MpPlayerNum].data.endscreen.stageindex = g_MissionConfig.stageindex;

	if (g_MenuData.root != MENUROOT_ENDSCREEN && g_Vars.mplayerisrunning == false) {
		g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo = 0;
		g_Menus[g_MpPlayerNum].data.endscreen.isfirstcompletion = false;
		g_Menus[g_MpPlayerNum].playernum = 0;

		// Set cheat info
		if (g_MissionConfig.iscoop == false
				&& g_MissionConfig.isanti == false
				&& g_MissionConfig.pdmode == false) {
			timedcheatid = cheatGetByTimedStageIndex(g_MissionConfig.stageindex, g_MissionConfig.difficulty);
			complcheatid = cheatGetByCompletedStageIndex(g_MissionConfig.stageindex);

			if (timedcheatid >= 0) {
				g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo = 0x0100 | timedcheatid;
			}

			if (complcheatid >= 0) {
				g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo |= 0x1000 | (complcheatid << 16);
			}
		}

		// Push the endscreen
		if (g_Vars.currentplayer->isdead
				|| g_Vars.currentplayer->aborted
				|| !objectiveIsAllComplete()) {
			menuPushRootDialog(&g_SoloMissionEndscreenFailedMenuDialog, MENUROOT_ENDSCREEN);
		} else {
			menuPushRootDialog(&g_SoloMissionEndscreenCompletedMenuDialog, MENUROOT_ENDSCREEN);

			if (g_MissionConfig.iscoop) {
				endscreenSetCoopCompleted();
			}
		}

		if (g_MissionConfig.iscoop == false && g_MissionConfig.isanti == false) {
			timedalreadyunlocked = false;
			complalreadyunlocked = false;

			// If there's a timed cheat for this stage + difficulty
			if (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x100) {
				timedalreadyunlocked = cheatIsUnlocked(g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xff);

				if (timedalreadyunlocked) {
					g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo |= 0x400;
				}
			}

			// If there's a completion cheat for this stage (ie. not a special stage)
			if (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x1000) {
				complalreadyunlocked = cheatIsUnlocked((g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo >> 16) & 0xff);
			}

			// Update total mission time
			secs = getMissionTime() / 60;

			if (secs != 0) {
				if (secs >= S32_MAX || S32_MAX - secs <= g_GameFile.totaltime) {
					g_GameFile.totaltime = S32_MAX;
				} else {
					g_GameFile.totaltime += secs;
				}
			}

			g_GameFile.autostageindex = g_MissionConfig.stageindex;
			g_GameFile.autodifficulty = g_MissionConfig.difficulty;

			if (g_CheatsActiveBank0 == 0
					&& g_CheatsActiveBank1 == 0
					&& g_MissionConfig.pdmode == false
					&& g_Vars.currentplayer->isdead == false
					&& g_Vars.currentplayer->aborted == false
					&& objectiveIsAllComplete()) {
				secs = getMissionTime() / 60;

				// The save file allows 12 bits per time, which is up to
				// 1h 8m 16s. If the timer is higher than this, reduce it.
				if (secs > 0xfff) {
					secs = 0xfff;
				}

				// Zero is used as an indicator that the stage is not completed,
				// so if the player managed to legitly complete a stage in 0:00
				// adjust it to 0:01.
				if (secs == 0) {
					secs = 1;
				}

				// Set best time
				prevbest = g_GameFile.besttimes[g_MissionConfig.stageindex][g_MissionConfig.difficulty];

				if (prevbest == 0) {
					g_Menus[g_MpPlayerNum].data.endscreen.isfirstcompletion = true;
				}

				if (secs < prevbest || prevbest == 0) {
					g_GameFile.besttimes[g_MissionConfig.stageindex][g_MissionConfig.difficulty] = secs;
				}

				// Recalculate thumbnail for file select screen
				if (g_MissionConfig.stageindex <= SOLOSTAGEINDEX_SKEDARRUINS) {
					g_GameFile.autostageindex = g_MissionConfig.stageindex + 1;

					if (g_GameFile.autostageindex > SOLOSTAGEINDEX_SKEDARRUINS) {
						g_GameFile.autostageindex = SOLOSTAGEINDEX_SKEDARRUINS;
					}

					for (d = 0; d != 3; d++) {
						for (s = 0; s <= SOLOSTAGEINDEX_SKEDARRUINS; s++) {
							if (g_GameFile.besttimes[s][d]) {
								g_GameFile.thumbnail = s + 1;
							}
						}
					}
				}

				if (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x100) {
					nowunlocked = cheatIsUnlocked(g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0xff);

					if (!timedalreadyunlocked && nowunlocked) {
						g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo |= 0x0200;
					}
				}

				if (g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo & 0x1000) {
					nowunlocked = cheatIsUnlocked((g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo >> 16) & 0xff);

					if (!complalreadyunlocked && nowunlocked) {
						g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo |= 0x0800;
					}
				}

				mpDetermineUnlockedFeatures();

				if (g_MissionConfig.stagenum == STAGE_SKEDARRUINS && (u8)g_AltTitleUnlocked == false) {
					g_AltTitleUnlocked = true;
					g_AltTitleEnabled = true;
					bossfileSave();
				}
			}
		}

		func0f1094e4(&g_FilemgrLoadedMainFile, FILEOP_SAVE_GAME_000, 0);
	}

	if (g_MenuData.root == MENUROOT_ENDSCREEN) {
		lvSetPaused(true);
		g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;
	}
}
#else
GLOBAL_ASM(
glabel endscreenPrepare
/*  f108f00:	3c03800a */ 	lui	$v1,0x800a
/*  f108f04:	8c635eb4 */ 	lw	$v1,0x5eb4($v1)
/*  f108f08:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108f0c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f108f10:	106100b4 */ 	beq	$v1,$at,.NB0f1091e4
/*  f108f14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108f18:	3c0e800a */ 	lui	$t6,0x800a
/*  f108f1c:	8dcee9d4 */ 	lw	$t6,-0x162c($t6)
/*  f108f20:	3c0f8007 */ 	lui	$t7,0x8007
/*  f108f24:	3c01800a */ 	lui	$at,0x800a
/*  f108f28:	55c000af */ 	bnezl	$t6,.NB0f1091e8
/*  f108f2c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f108f30:	8def3af0 */ 	lw	$t7,0x3af0($t7)
/*  f108f34:	3c02800a */ 	lui	$v0,0x800a
/*  f108f38:	8c42e944 */ 	lw	$v0,-0x16bc($v0)
/*  f108f3c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f108f40:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f108f44:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f108f48:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f108f4c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f108f50:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f108f54:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f108f58:	00380821 */ 	addu	$at,$at,$t8
/*  f108f5c:	a0202f57 */ 	sb	$zero,0x2f57($at)
/*  f108f60:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f108f64:	17200008 */ 	bnez	$t9,.NB0f108f88
/*  f108f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108f6c:	8c48048c */ 	lw	$t0,0x48c($v0)
/*  f108f70:	15000005 */ 	bnez	$t0,.NB0f108f88
/*  f108f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108f78:	0fc24f11 */ 	jal	objectiveIsAllComplete
/*  f108f7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108f80:	1440000a */ 	bnez	$v0,.NB0f108fac
/*  f108f84:	3c048007 */ 	lui	$a0,0x8007
.NB0f108f88:
/*  f108f88:	3c048007 */ 	lui	$a0,0x8007
/*  f108f8c:	24847ee0 */ 	addiu	$a0,$a0,0x7ee0
/*  f108f90:	0fc3d326 */ 	jal	menuPushRootDialog
/*  f108f94:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f108f98:	3c02800a */ 	lui	$v0,0x800a
/*  f108f9c:	904227ab */ 	lbu	$v0,0x27ab($v0)
/*  f108fa0:	000249c2 */ 	srl	$t1,$v0,0x7
/*  f108fa4:	1000000f */ 	beqz	$zero,.NB0f108fe4
/*  f108fa8:	01201025 */ 	or	$v0,$t1,$zero
.NB0f108fac:
/*  f108fac:	24847ec8 */ 	addiu	$a0,$a0,0x7ec8
/*  f108fb0:	0fc3d326 */ 	jal	menuPushRootDialog
/*  f108fb4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f108fb8:	3c02800a */ 	lui	$v0,0x800a
/*  f108fbc:	904227ab */ 	lbu	$v0,0x27ab($v0)
/*  f108fc0:	000251c2 */ 	srl	$t2,$v0,0x7
/*  f108fc4:	11400007 */ 	beqz	$t2,.NB0f108fe4
/*  f108fc8:	01401025 */ 	or	$v0,$t2,$zero
/*  f108fcc:	0fc423a9 */ 	jal	endscreenSetCoopCompleted
/*  f108fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108fd4:	3c02800a */ 	lui	$v0,0x800a
/*  f108fd8:	904227ab */ 	lbu	$v0,0x27ab($v0)
/*  f108fdc:	000259c2 */ 	srl	$t3,$v0,0x7
/*  f108fe0:	01601025 */ 	or	$v0,$t3,$zero
.NB0f108fe4:
/*  f108fe4:	14400078 */ 	bnez	$v0,.NB0f1091c8
/*  f108fe8:	3c0c800a */ 	lui	$t4,0x800a
/*  f108fec:	8d8c27a8 */ 	lw	$t4,0x27a8($t4)
/*  f108ff0:	000c7640 */ 	sll	$t6,$t4,0x19
/*  f108ff4:	05c00074 */ 	bltz	$t6,.NB0f1091c8
/*  f108ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108ffc:	0fc2ff91 */ 	jal	getMissionTime
/*  f109000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109004:	0fc2ff91 */ 	jal	getMissionTime
/*  f109008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10900c:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f109010:	0041001a */ 	div	$zero,$v0,$at
/*  f109014:	00001812 */ 	mflo	$v1
/*  f109018:	3c047fff */ 	lui	$a0,0x7fff
/*  f10901c:	10600010 */ 	beqz	$v1,.NB0f109060
/*  f109020:	3484ffff */ 	ori	$a0,$a0,0xffff
/*  f109024:	0064082b */ 	sltu	$at,$v1,$a0
/*  f109028:	10200007 */ 	beqz	$at,.NB0f109048
/*  f10902c:	3c07800a */ 	lui	$a3,0x800a
/*  f109030:	24e766f0 */ 	addiu	$a3,$a3,0x66f0
/*  f109034:	8ce20010 */ 	lw	$v0,0x10($a3)
/*  f109038:	00837823 */ 	subu	$t7,$a0,$v1
/*  f10903c:	004f082b */ 	sltu	$at,$v0,$t7
/*  f109040:	14200005 */ 	bnez	$at,.NB0f109058
/*  f109044:	0043c021 */ 	addu	$t8,$v0,$v1
.NB0f109048:
/*  f109048:	3c07800a */ 	lui	$a3,0x800a
/*  f10904c:	24e766f0 */ 	addiu	$a3,$a3,0x66f0
/*  f109050:	10000003 */ 	beqz	$zero,.NB0f109060
/*  f109054:	ace40010 */ 	sw	$a0,0x10($a3)
.NB0f109058:
/*  f109058:	3c01800a */ 	lui	$at,0x800a
/*  f10905c:	ac386700 */ 	sw	$t8,0x6700($at)
.NB0f109060:
/*  f109060:	3c03800a */ 	lui	$v1,0x800a
/*  f109064:	246327a8 */ 	addiu	$v1,$v1,0x27a8
/*  f109068:	3c07800a */ 	lui	$a3,0x800a
/*  f10906c:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f109070:	24e766f0 */ 	addiu	$a3,$a3,0x66f0
/*  f109074:	90ec000b */ 	lbu	$t4,0xb($a3)
/*  f109078:	90790002 */ 	lbu	$t9,0x2($v1)
/*  f10907c:	00085642 */ 	srl	$t2,$t0,0x19
/*  f109080:	314b0007 */ 	andi	$t3,$t2,0x7
/*  f109084:	318dfff8 */ 	andi	$t5,$t4,0xfff8
/*  f109088:	016d7025 */ 	or	$t6,$t3,$t5
/*  f10908c:	a0ee000b */ 	sb	$t6,0xb($a3)
/*  f109090:	3c02800a */ 	lui	$v0,0x800a
/*  f109094:	a0f9000c */ 	sb	$t9,0xc($a3)
/*  f109098:	8c42e944 */ 	lw	$v0,-0x16bc($v0)
/*  f10909c:	8c4f00d8 */ 	lw	$t7,0xd8($v0)
/*  f1090a0:	15e00049 */ 	bnez	$t7,.NB0f1091c8
/*  f1090a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1090a8:	8c58048c */ 	lw	$t8,0x48c($v0)
/*  f1090ac:	17000046 */ 	bnez	$t8,.NB0f1091c8
/*  f1090b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1090b4:	0fc24f11 */ 	jal	objectiveIsAllComplete
/*  f1090b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1090bc:	10400042 */ 	beqz	$v0,.NB0f1091c8
/*  f1090c0:	3c19800a */ 	lui	$t9,0x800a
/*  f1090c4:	8f3966c0 */ 	lw	$t9,0x66c0($t9)
/*  f1090c8:	3c08800a */ 	lui	$t0,0x800a
/*  f1090cc:	1720003e */ 	bnez	$t9,.NB0f1091c8
/*  f1090d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1090d4:	8d0866c4 */ 	lw	$t0,0x66c4($t0)
/*  f1090d8:	1500003b */ 	bnez	$t0,.NB0f1091c8
/*  f1090dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1090e0:	0fc2ff91 */ 	jal	getMissionTime
/*  f1090e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1090e8:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f1090ec:	0041001a */ 	div	$zero,$v0,$at
/*  f1090f0:	00003012 */ 	mflo	$a2
/*  f1090f4:	3c07800a */ 	lui	$a3,0x800a
/*  f1090f8:	2cc11000 */ 	sltiu	$at,$a2,0x1000
/*  f1090fc:	14200002 */ 	bnez	$at,.NB0f109108
/*  f109100:	24e766f0 */ 	addiu	$a3,$a3,0x66f0
/*  f109104:	24060fff */ 	addiu	$a2,$zero,0xfff
.NB0f109108:
/*  f109108:	3c03800a */ 	lui	$v1,0x800a
/*  f10910c:	906327aa */ 	lbu	$v1,0x27aa($v1)
/*  f109110:	3c0c800a */ 	lui	$t4,0x800a
/*  f109114:	8d8c27a8 */ 	lw	$t4,0x27a8($t4)
/*  f109118:	00034880 */ 	sll	$t1,$v1,0x2
/*  f10911c:	01234823 */ 	subu	$t1,$t1,$v1
/*  f109120:	00094840 */ 	sll	$t1,$t1,0x1
/*  f109124:	000c5e42 */ 	srl	$t3,$t4,0x19
/*  f109128:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f10912c:	00e95021 */ 	addu	$t2,$a3,$t1
/*  f109130:	014d2021 */ 	addu	$a0,$t2,$t5
/*  f109134:	94820020 */ 	lhu	$v0,0x20($a0)
/*  f109138:	00c2082b */ 	sltu	$at,$a2,$v0
/*  f10913c:	54200004 */ 	bnezl	$at,.NB0f109150
/*  f109140:	a4860020 */ 	sh	$a2,0x20($a0)
/*  f109144:	54400003 */ 	bnezl	$v0,.NB0f109154
/*  f109148:	28610011 */ 	slti	$at,$v1,0x11
/*  f10914c:	a4860020 */ 	sh	$a2,0x20($a0)
.NB0f109150:
/*  f109150:	28610011 */ 	slti	$at,$v1,0x11
.NB0f109154:
/*  f109154:	1020000c */ 	beqz	$at,.NB0f109188
/*  f109158:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f10915c:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f109160:	29c10011 */ 	slti	$at,$t6,0x11
/*  f109164:	14200003 */ 	bnez	$at,.NB0f109174
/*  f109168:	a0e3000c */ 	sb	$v1,0xc($a3)
/*  f10916c:	240f0010 */ 	addiu	$t7,$zero,0x10
/*  f109170:	a0ef000c */ 	sb	$t7,0xc($a3)
.NB0f109174:
/*  f109174:	90e9000b */ 	lbu	$t1,0xb($a3)
/*  f109178:	000340c0 */ 	sll	$t0,$v1,0x3
/*  f10917c:	312cff07 */ 	andi	$t4,$t1,0xff07
/*  f109180:	010c5825 */ 	or	$t3,$t0,$t4
/*  f109184:	a0eb000b */ 	sb	$t3,0xb($a3)
.NB0f109188:
/*  f109188:	0fc65417 */ 	jal	mpDetermineUnlockedFeatures
/*  f10918c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109190:	3c0a800a */ 	lui	$t2,0x800a
/*  f109194:	914a27a9 */ 	lbu	$t2,0x27a9($t2)
/*  f109198:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f10919c:	3c03800a */ 	lui	$v1,0x800a
/*  f1091a0:	15410009 */ 	bne	$t2,$at,.NB0f1091c8
/*  f1091a4:	2463681b */ 	addiu	$v1,$v1,0x681b
/*  f1091a8:	906d0000 */ 	lbu	$t5,0x0($v1)
/*  f1091ac:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1091b0:	3c01800a */ 	lui	$at,0x800a
/*  f1091b4:	15a00004 */ 	bnez	$t5,.NB0f1091c8
/*  f1091b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1091bc:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f1091c0:	0fc42b8c */ 	jal	bossfileSave
/*  f1091c4:	a022681c */ 	sb	$v0,0x681c($at)
.NB0f1091c8:
/*  f1091c8:	3c04800a */ 	lui	$a0,0x800a
/*  f1091cc:	248467b0 */ 	addiu	$a0,$a0,0x67b0
/*  f1091d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1091d4:	0fc41358 */ 	jal	func0f1094e4
/*  f1091d8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1091dc:	3c03800a */ 	lui	$v1,0x800a
/*  f1091e0:	8c635eb4 */ 	lw	$v1,0x5eb4($v1)
.NB0f1091e4:
/*  f1091e4:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f1091e8:
/*  f1091e8:	54610008 */ 	bnel	$v1,$at,.NB0f10920c
/*  f1091ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1091f0:	0fc59ebc */ 	jal	lvSetPaused
/*  f1091f4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1091f8:	3c0f800a */ 	lui	$t7,0x800a
/*  f1091fc:	8defe944 */ 	lw	$t7,-0x16bc($t7)
/*  f109200:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f109204:	adee1a24 */ 	sw	$t6,0x1a24($t7)
/*  f109208:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f10920c:
/*  f10920c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f109210:	03e00008 */ 	jr	$ra
/*  f109214:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

struct menudialog g_2PMissionEndscreenCompletedHMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	(u32)&menuTitleStageCompleted,
	g_MissionEndscreenMenuItems,
	menudialogSolo2PEndscreenCompleted,
	0x00000048,
	&g_SoloEndscreenObjectivesCompletedMenuDialog,
};

struct menudialog g_2PMissionEndscreenFailedHMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&menuTitleStageFailed,
	g_MissionEndscreenMenuItems,
	menudialogSolo2PEndscreenFailed,
	0x00000048,
	&g_SoloEndscreenObjectivesFailedMenuDialog,
};

struct menudialog g_2PMissionEndscreenCompletedVMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_276, // "Completed"
	g_2PMissionEndscreenVMenuItems,
	menudialogSolo2PEndscreenCompleted,
	0x00000048,
	&g_2PMissionEndscreenObjectivesCompletedVMenuDialog,
};

struct menudialog g_2PMissionEndscreenFailedVMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_277, // "Failed"
	g_2PMissionEndscreenVMenuItems,
	menudialogSolo2PEndscreenFailed,
	0x00000048,
	&g_2PMissionEndscreenObjectivesFailedVMenuDialog,
};

void soloPushCoopModeEndscreen(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	lvSetPaused(true);

	g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;

#if VERSION >= VERSION_NTSC_1_0
	g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo = 0;
	g_Menus[g_MpPlayerNum].data.endscreen.isfirstcompletion = false;
	g_Menus[g_MpPlayerNum].data.endscreen.stageindex = g_MissionConfig.stageindex;
#endif

	g_Menus[g_MpPlayerNum].playernum = g_Vars.currentplayernum;

	if ((g_Vars.bond->isdead && g_Vars.coop->isdead)
			|| g_Vars.bond->aborted
			|| g_Vars.coop->aborted
			|| !objectiveIsAllComplete()) {
		// Failed or aborted
		if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
			menuPushRootDialog(&g_2PMissionEndscreenFailedVMenuDialog, MENUROOT_MPENDSCREEN);
		} else {
			menuPushRootDialog(&g_2PMissionEndscreenFailedHMenuDialog, MENUROOT_MPENDSCREEN);
		}
	} else {
		// Completed
		if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
			menuPushRootDialog(&g_2PMissionEndscreenCompletedVMenuDialog, MENUROOT_MPENDSCREEN);
		} else {
			menuPushRootDialog(&g_2PMissionEndscreenCompletedHMenuDialog, MENUROOT_MPENDSCREEN);
		}

		endscreenSetCoopCompleted();
	}

	if (g_Vars.currentplayer == g_Vars.bond) {
		func0f1094e4(&g_FilemgrLoadedMainFile, FILEOP_SAVE_GAME_000, NULL);
	}

	g_MpPlayerNum = prevplayernum;
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * This function is misnamed. It pushes the menu after the endscreen
 * (ie. retry, next mission or continue), and it looks like it might be for coop
 * only but I'm not 100% sure.
 *
 * This function is only called from menuTickAll, which is a bit weird...
 */
void soloPushSoloModeEndscreen(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	g_MpPlayerNum = 0;
	g_Menus[g_MpPlayerNum].playernum = 0;

	if ((g_Vars.bond->isdead && g_Vars.coop->isdead)
			|| g_Vars.bond->aborted
			|| g_Vars.coop->aborted
			|| !objectiveIsAllComplete()) {
		// Failed or aborted
		func0f10d770();
		menuPushRootDialog(&g_RetryMissionMenuDialog, MENUROOT_COOPCONTINUE);
	} else {
		// Completed
		endscreenHandleContinue(1);
	}

	g_MpPlayerNum = prevplayernum;
}
#else
GLOBAL_ASM(
glabel soloPushSoloModeEndscreen
/*  f10938c:	0000c0c0 */ 	sll	$t8,$zero,0x3
/*  f109390:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f109394:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f109398:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f10939c:	3c048007 */ 	lui	$a0,0x8007
/*  f1093a0:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f1093a4:	24843af0 */ 	addiu	$a0,$a0,0x3af0
/*  f1093a8:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f1093ac:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f1093b0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1093b4:	3c01800a */ 	lui	$at,0x800a
/*  f1093b8:	3c03800a */ 	lui	$v1,0x800a
/*  f1093bc:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1093c0:	00380821 */ 	addu	$at,$at,$t8
/*  f1093c4:	2463e6c0 */ 	addiu	$v1,$v1,-6464
/*  f1093c8:	a0202f57 */ 	sb	$zero,0x2f57($at)
/*  f1093cc:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f1093d0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1093d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1093d8:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1093dc:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f1093e0:	53200006 */ 	beqzl	$t9,.NB0f1093fc
/*  f1093e4:	8c4a048c */ 	lw	$t2,0x48c($v0)
/*  f1093e8:	8c6802a4 */ 	lw	$t0,0x2a4($v1)
/*  f1093ec:	8d0900d8 */ 	lw	$t1,0xd8($t0)
/*  f1093f0:	1520000c */ 	bnez	$t1,.NB0f109424
/*  f1093f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1093f8:	8c4a048c */ 	lw	$t2,0x48c($v0)
.NB0f1093fc:
/*  f1093fc:	15400009 */ 	bnez	$t2,.NB0f109424
/*  f109400:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109404:	8c6b02a4 */ 	lw	$t3,0x2a4($v1)
/*  f109408:	8d6c048c */ 	lw	$t4,0x48c($t3)
/*  f10940c:	15800005 */ 	bnez	$t4,.NB0f109424
/*  f109410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109414:	0fc24f11 */ 	jal	objectiveIsAllComplete
/*  f109418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10941c:	14400009 */ 	bnez	$v0,.NB0f109444
/*  f109420:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f109424:
/*  f109424:	0fc42203 */ 	jal	func0f10d770
/*  f109428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10942c:	3c048007 */ 	lui	$a0,0x8007
/*  f109430:	24847a00 */ 	addiu	$a0,$a0,0x7a00
/*  f109434:	0fc3d326 */ 	jal	menuPushRootDialog
/*  f109438:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f10943c:	1000000b */ 	beqz	$zero,.NB0f10946c
/*  f109440:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f109444:
/*  f109444:	0fc421db */ 	jal	func0f10d730
/*  f109448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10944c:	50400007 */ 	beqzl	$v0,.NB0f10946c
/*  f109450:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109454:	0fc42203 */ 	jal	func0f10d770
/*  f109458:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10945c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f109460:	0fc3d326 */ 	jal	menuPushRootDialog
/*  f109464:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f109468:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f10946c:
/*  f10946c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f109470:	3c018007 */ 	lui	$at,0x8007
/*  f109474:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f109478:	03e00008 */ 	jr	$ra
/*  f10947c:	ac2d3af0 */ 	sw	$t5,0x3af0($at)
);
#endif

void soloPushAntiModeEndscreen(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	lvSetPaused(true);

	g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;

#if VERSION >= VERSION_NTSC_1_0
	g_Menus[g_MpPlayerNum].data.endscreen.cheatinfo = 0;
	g_Menus[g_MpPlayerNum].data.endscreen.isfirstcompletion = false;
	g_Menus[g_MpPlayerNum].data.endscreen.stageindex = g_MissionConfig.stageindex;
#endif

	g_Menus[g_MpPlayerNum].playernum = g_Vars.currentplayernum;

	if (g_Vars.currentplayer == g_Vars.bond) {
		if (g_Vars.anti->aborted == 0 &&
				(g_Vars.bond->isdead || g_Vars.bond->aborted || objectiveIsAllComplete() == false)) {
			// Bond - failed or aborted
			if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
				menuPushRootDialog(&g_2PMissionEndscreenFailedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menuPushRootDialog(&g_2PMissionEndscreenFailedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		} else {
			// Bond - completed
			if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
				menuPushRootDialog(&g_2PMissionEndscreenCompletedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menuPushRootDialog(&g_2PMissionEndscreenCompletedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		}

		func0f1094e4(&g_FilemgrLoadedMainFile, FILEOP_SAVE_GAME_000, 0);
	} else {
		if (g_Vars.anti->aborted == 0 &&
				(g_Vars.bond->isdead || g_Vars.bond->aborted || objectiveIsAllComplete() == false)) {
			// Anti - completed
			if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
				menuPushRootDialog(&g_2PMissionEndscreenCompletedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menuPushRootDialog(&g_2PMissionEndscreenCompletedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		} else {
			// Anti - failed or aborted
			if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
				menuPushRootDialog(&g_2PMissionEndscreenFailedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menuPushRootDialog(&g_2PMissionEndscreenFailedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		}
	}

	g_MpPlayerNum = prevplayernum;
}

u32 var80075bb4 = 0;
u32 var80075bb8 = 0;
