#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/lv.h"
#include "game/mplayer/ingame.h"
#include "game/challenge.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/setup.h"
#include "game/options.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

struct menudialogdef g_MpEndscreenChallengeCompletedMenuDialog;
struct menudialogdef g_MpEndscreenIndGameOverMenuDialog;
struct menudialogdef g_MpEndscreenTeamGameOverMenuDialog;

#if VERSION >= VERSION_NTSC_1_0
struct menudialogdef g_MpEndscreenSavePlayerMenuDialog;
#endif

s32 mpStatsForPlayerDropdownHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct mpchrconfig *mpchr;
	s32 v0;
	s32 v1;
	s32 a1;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = 0;

		for (v0 = 0; v0 < MAX_MPCHRS; v0++) {
			if (g_MpSetup.chrslots & (1 << v0)) {
				data->list.value++;
			}
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		v0 = 0;

		for (a1 = 0; a1 < MAX_MPCHRS; a1++) {
			if (g_MpSetup.chrslots & (1 << a1)) {
				mpchr = MPCHR(a1);

				if (v0 == data->list.value) {
					return (s32) mpchr->name;
				}

				v0++;
			}
		}

		return (s32) "";
	case MENUOP_SET:
		v0 = 0;

		for (a1 = 0; a1 < MAX_MPCHRS; a1++) {
			if (g_MpSetup.chrslots & (1 << a1)) {
				if (v0);

				if (data->list.value == v0) {
					g_MpSelectedPlayersForStats[g_MpPlayerNum] = a1;
				}

				v0++;
			}
		}

		break;
	case MENUOP_GETOPTIONVALUE:
		v0 = 0;

		for (v1 = 0; v1 < MAX_MPCHRS; v1++) {
			if (g_MpSetup.chrslots & (1 << v1)) {
				if (v0);

				if (g_MpSelectedPlayersForStats[g_MpPlayerNum] == v1) {
					data->list.value = v0;
				}

				v0++;
			}
		}

		break;
	}

	return 0;
}

s32 menuhandlerMpEndGame(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.currentplayer->aborted = true;
		mainEndStage();
	}

	return 0;
}

/**
 * This is something near the top of the "End Game" dialog during gameplay.
 */
s32 menuhandler00178018(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

char *mpMenuTextInGameLimit(struct menuitem *item)
{
	*g_StringPointer = 0;

	switch (item->param) {
	case 0:
		sprintf(g_StringPointer, langGet(L_MPMENU_114), g_MpSetup.timelimit + 1);
		break;
	case 1:
		sprintf(g_StringPointer, langGet(L_MPMENU_113), g_MpSetup.scorelimit + 1);
		break;
	case 2:
		sprintf(g_StringPointer, langGet(L_MPMENU_113), mpCalculateTeamScoreLimit() + 1);
		break;
	}

	return g_StringPointer;
}

s32 menuhandlerMpInGameLimitLabel(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		switch (item->param) {
		case 0: if (g_MpSetup.timelimit == 60) return true; break;
		case 1: if (g_MpSetup.scorelimit == 100) return true; break;
		case 2: if (g_MpSetup.teamscorelimit == 400) return true; break;
		}
	}

	return 0;
}

s32 menuhandlerMpPause(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (mpIsPaused()) {
			mpSetPaused(MPPAUSEMODE_UNPAUSED);
		} else {
			mpSetPaused(MPPAUSEMODE_PAUSED);
		}
	}

	if (operation == MENUOP_CHECKHIDDEN) {
		if (PLAYERCOUNT() == 1) {
			return true;
		}
	}

	if (operation == MENUOP_CHECKPREFOCUSED) {
		if (item->param == 1) {
			return true;
		}
	}

	return 0;
}

char *menutextPauseOrUnpause(s32 arg0)
{
	if (mpIsPaused()) {
		return langGet(L_MPMENU_289); // "Unpause"
	}

	return langGet(L_MPMENU_288); // "Pause"
}

char *menutextMatchTime(s32 arg0)
{
#if PAL
	formatTime(g_StringPointer, lvGetStageTime60() * 60 / 50, TIMEPRECISION_SECONDS);
#else
	formatTime(g_StringPointer, lvGetStageTime60(), TIMEPRECISION_SECONDS);
#endif

	return g_StringPointer;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel mpMenuTextWeaponDescription
/*  f178780:	3c0e8007 */ 	lui	$t6,0x8007
/*  f178784:	8dce1998 */ 	lw	$t6,0x1998($t6)
/*  f178788:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f17878c:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f178790:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f178794:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f178798:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17879c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1787a0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1787a4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1787a8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1787ac:	3c04800a */ 	lui	$a0,0x800a
/*  f1787b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1787b4:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f1787b8:	0fc2c814 */ 	jal	weaponFindById
/*  f1787bc:	8c84f528 */ 	lw	$a0,-0xad8($a0)
/*  f1787c0:	10400067 */ 	beqz	$v0,.JF0f178960
/*  f1787c4:	00402825 */ 	move	$a1,$v0
/*  f1787c8:	3c188007 */ 	lui	$t8,0x8007
/*  f1787cc:	8f181998 */ 	lw	$t8,0x1998($t8)
/*  f1787d0:	3c02800a */ 	lui	$v0,0x800a
/*  f1787d4:	2401002e */ 	li	$at,0x2e
/*  f1787d8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f1787dc:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1787e0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1787e4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1787e8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f1787ec:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1787f0:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f1787f4:	00591021 */ 	addu	$v0,$v0,$t9
/*  f1787f8:	8c42f528 */ 	lw	$v0,-0xad8($v0)
/*  f1787fc:	3c08800a */ 	lui	$t0,0x800a
/*  f178800:	54410015 */ 	bnel	$v0,$at,.JF0f178858
/*  f178804:	24010050 */ 	li	$at,0x50
/*  f178808:	8d08a8b4 */ 	lw	$t0,-0x574c($t0)
/*  f17880c:	8d030480 */ 	lw	$v1,0x480($t0)
/*  f178810:	50600011 */ 	beqzl	$v1,.JF0f178858
/*  f178814:	24010050 */ 	li	$at,0x50
/*  f178818:	9064006b */ 	lbu	$a0,0x6b($v1)
/*  f17881c:	24010001 */ 	li	$at,0x1
/*  f178820:	54810006 */ 	bnel	$a0,$at,.JF0f17883c
/*  f178824:	24010002 */ 	li	$at,0x2
/*  f178828:	0fc5baa5 */ 	jal	langGet
/*  f17882c:	24044ced */ 	li	$a0,0x4ced
/*  f178830:	1000004e */ 	b	.JF0f17896c
/*  f178834:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178838:	24010002 */ 	li	$at,0x2
.JF0f17883c:
/*  f17883c:	54810006 */ 	bnel	$a0,$at,.JF0f178858
/*  f178840:	24010050 */ 	li	$at,0x50
/*  f178844:	0fc5baa5 */ 	jal	langGet
/*  f178848:	24044cec */ 	li	$a0,0x4cec
/*  f17884c:	10000047 */ 	b	.JF0f17896c
/*  f178850:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178854:	24010050 */ 	li	$at,0x50
.JF0f178858:
/*  f178858:	1441003d */ 	bne	$v0,$at,.JF0f178950
/*  f17885c:	3c09800a */ 	lui	$t1,0x800a
/*  f178860:	8d29aae4 */ 	lw	$t1,-0x551c($t1)
/*  f178864:	24010034 */ 	li	$at,0x34
/*  f178868:	15210039 */ 	bne	$t1,$at,.JF0f178950
/*  f17886c:	00000000 */ 	nop
/*  f178870:	0fc5b3cf */ 	jal	lvGetDifficulty
/*  f178874:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f178878:	28410002 */ 	slti	$at,$v0,0x2
/*  f17887c:	14200034 */ 	bnez	$at,.JF0f178950
/*  f178880:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f178884:	3c0b8008 */ 	lui	$t3,0x8008
/*  f178888:	256b4de8 */ 	addiu	$t3,$t3,0x4de8
/*  f17888c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f178890:	27aa0040 */ 	addiu	$t2,$sp,0x40
/*  f178894:	8d6d0004 */ 	lw	$t5,0x4($t3)
/*  f178898:	ad410000 */ 	sw	$at,0x0($t2)
/*  f17889c:	95610008 */ 	lhu	$at,0x8($t3)
/*  f1788a0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1788a4:	25ef4df4 */ 	addiu	$t7,$t7,0x4df4
/*  f1788a8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f1788ac:	a5410008 */ 	sh	$at,0x8($t2)
/*  f1788b0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1788b4:	27ae0030 */ 	addiu	$t6,$sp,0x30
/*  f1788b8:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f1788bc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1788c0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1788c4:	27a20040 */ 	addiu	$v0,$sp,0x40
/*  f1788c8:	00001825 */ 	move	$v1,$zero
/*  f1788cc:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1788d0:	95e1000c */ 	lhu	$at,0xc($t7)
/*  f1788d4:	24040038 */ 	li	$a0,0x38
/*  f1788d8:	add90004 */ 	sw	$t9,0x4($t6)
/*  f1788dc:	a5c1000c */ 	sh	$at,0xc($t6)
.JF0f1788e0:
/*  f1788e0:	90480000 */ 	lbu	$t0,0x0($v0)
/*  f1788e4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1788e8:	01034823 */ 	subu	$t1,$t0,$v1
/*  f1788ec:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f1788f0:	2861005a */ 	slti	$at,$v1,0x5a
/*  f1788f4:	252cfff7 */ 	addiu	$t4,$t1,-9
/*  f1788f8:	1420fff9 */ 	bnez	$at,.JF0f1788e0
/*  f1788fc:	a04cffff */ 	sb	$t4,-0x1($v0)
/*  f178900:	27a20030 */ 	addiu	$v0,$sp,0x30
/*  f178904:	00001825 */ 	move	$v1,$zero
.JF0f178908:
/*  f178908:	904a0000 */ 	lbu	$t2,0x0($v0)
/*  f17890c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178910:	01435823 */ 	subu	$t3,$t2,$v1
/*  f178914:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f178918:	256dfffc */ 	addiu	$t5,$t3,-4
/*  f17891c:	1464fffa */ 	bne	$v1,$a0,.JF0f178908
/*  f178920:	a04dffff */ 	sb	$t5,-0x1($v0)
/*  f178924:	0fc5baa5 */ 	jal	langGet
/*  f178928:	24044cef */ 	li	$a0,0x4cef
/*  f17892c:	3c048007 */ 	lui	$a0,0x8007
/*  f178930:	8c841990 */ 	lw	$a0,0x1990($a0)
/*  f178934:	00402825 */ 	move	$a1,$v0
/*  f178938:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f17893c:	0c004d95 */ 	jal	sprintf
/*  f178940:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f178944:	3c028007 */ 	lui	$v0,0x8007
/*  f178948:	10000007 */ 	b	.JF0f178968
/*  f17894c:	8c421990 */ 	lw	$v0,0x1990($v0)
.JF0f178950:
/*  f178950:	0fc5baa5 */ 	jal	langGet
/*  f178954:	94a4004a */ 	lhu	$a0,0x4a($a1)
/*  f178958:	10000004 */ 	b	.JF0f17896c
/*  f17895c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f178960:
/*  f178960:	0fc5baa5 */ 	jal	langGet
/*  f178964:	24045603 */ 	li	$a0,0x5603
.JF0f178968:
/*  f178968:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f17896c:
/*  f17896c:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f178970:	03e00008 */ 	jr	$ra
/*  f178974:	00000000 */ 	nop
);
#else
char *mpMenuTextWeaponDescription(struct menuitem *item)
{
	struct weapon *weapon = weaponFindById(g_Menus[g_MpPlayerNum].mppause.weaponnum);

	if (weapon) {
		return langGet(weapon->description);
	}

	return "\n";
}
#endif

char *mpMenuTitleStatsFor(struct menudialogdef *dialogdef)
{
	struct mpchrconfig *mpchr = MPCHR(g_MpSelectedPlayersForStats[g_MpPlayerNum]);

	// "Stats for %s"
	sprintf(g_StringPointer, langGet(L_MPMENU_280), mpchr->name);
	return g_StringPointer;
}

s32 func0f178440(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation);

	return 0;
}

char *mpMenuTextWeaponOfChoiceName(struct menuitem *item)
{
	return mpPlayerGetWeaponOfChoiceName(g_Menus[g_MpPlayerNum].playernum, 0);
}

char *mpMenuTextAward1(struct menuitem *item)
{
	return g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->award1;
}

char *mpMenuTextAward2(struct menuitem *item)
{
	return g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->award2;
}

struct menuitem g_MpEndGameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x02000020, L_MPMENU_291, 0x00000000, NULL }, // "Are you sure?"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU_292, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPMENU_293, 0x00000000, menuhandlerMpEndGame }, // "End Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpEndGameMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_290, // "End Game"
	g_MpEndGameMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpPauseControlMenuItems[] = {
#if VERSION == VERSION_JPN_FINAL
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextChallengeName, 0x00000000, menuhandler00178018 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_162, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Time Limit:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000010, L_MPWEAPONS_163, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Score Limit:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000010, L_MPWEAPONS_164, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Team Score Limit:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_286, (u32)&menutextMatchTime, NULL }, // "Game Time:"
#else
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextChallengeName, 0x00000000, menuhandler00178018 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextScenarioName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_162, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Time Limit:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000200, L_MPWEAPONS_163, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Score Limit:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000200, L_MPWEAPONS_164, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Team Score Limit:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_286, (u32)&menutextMatchTime, NULL }, // "Game Time:"
#endif
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000020, (u32)&menutextPauseOrUnpause, 0x00000000, menuhandlerMpPause },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000024, L_MPMENU_287, 0x00000000, (void *)&g_MpEndGameMenuDialog }, // "End Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpPauseControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
#if VERSION >= VERSION_JPN_FINAL
	(u32)&mpMenuTextScenarioName,
#else
	L_MPMENU_285, // "Control"
#endif
	g_MpPauseControlMenuItems,
	NULL,
	0,
	NULL,
};

#if VERSION == VERSION_JPN_FINAL
u32 var80084de8jf[] = {
	0x4c56715b,
	0x6566727a,
	0x835a0000,
	0x4d40595f,
	0x6e716958,
	0x726c7568,
	0x69380000,
};
#endif

struct menuitem g_Mp2PMissionInventoryMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x00000078, 0x00000042, menuhandlerInventoryList },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextWeaponDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpPauseInventoryMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_284, // "Inventory"
	g_Mp2PMissionInventoryMenuItems,
	NULL,
	0,
	&g_MpPauseControlMenuDialog,
};

struct menudialogdef g_2PMissionInventoryHMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_284, // "Inventory"
	g_Mp2PMissionInventoryMenuItems,
	NULL,
	0,
	&g_2PMissionOptionsHMenuDialog,
};

struct menudialogdef g_2PMissionInventoryVMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_284, // "Inventory"
	g_Mp2PMissionInventoryMenuItems,
	NULL,
	0,
	&g_2PMissionOptionsVMenuDialog,
};

struct menuitem g_MpInGamePlayerStatsMenuItems[] = {
	{ MENUITEMTYPE_PLAYERSTATS, 0, 0x00000000, 0x00000000, 0x00000000, mpStatsForPlayerDropdownHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpPausePlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsFor,
	g_MpInGamePlayerStatsMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	&g_MpPauseInventoryMenuDialog,
};

struct menudialogdef g_MpEndscreenPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsFor,
	g_MpInGamePlayerStatsMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	NULL,
};

struct menuitem g_MpPlayerRankingMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpPausePlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_276, // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	&g_MpPausePlayerStatsMenuDialog,
};

struct menudialogdef g_MpEndscreenPlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_276, // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	&g_MpEndscreenPlayerStatsMenuDialog,
};

struct menuitem g_MpTeamRankingsMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000001, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpPauseTeamRankingsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_279, // "Team Ranking"
	g_MpTeamRankingsMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	&g_MpPausePlayerRankingMenuDialog,
};

struct menudialogdef g_MpEndscreenTeamRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_279, // "Team Ranking"
	g_MpTeamRankingsMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	&g_MpEndscreenPlayerRankingMenuDialog,
};

char *mpMenuTextPlacementWithSuffix(struct menuitem *item)
{
	u16 suffixes[] = {
		L_MPMENU_264, // "1st"
		L_MPMENU_265, // "2nd"
		L_MPMENU_266, // "3rd"
		L_MPMENU_267, // "4th"
		L_MPMENU_268, // "5th"
		L_MPMENU_269, // "6th"
		L_MPMENU_270, // "7th"
		L_MPMENU_271, // "8th"
		L_MPMENU_272, // "9th"
		L_MPMENU_273, // "10th"
		L_MPMENU_274, // "11th"
		L_MPMENU_275, // "12th"
	};

	return langGet(suffixes[g_PlayerConfigsArray[g_MpPlayerNum].base.placement]);
}

s32 mpPlacementMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].base.placement == 0) { // winner
			data->label.colour2 = colourBlend(data->label.colour2, 0xffff00ff, func0f006b08(40) * 255);
		}
	}

	return 0;
}

s32 mpAwardsMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_RENDER) {
		Gfx *gdl = data->type19.gdl;
		struct menuitemrenderdata *renderdata = data->type19.renderdata2;
		bool configured = false;
		s32 x = renderdata->x + renderdata->width - 15;
		s32 i;
		u32 colour;

		for (i = 0; i < 4; i++) {
			if (g_PlayerConfigsArray[g_MpPlayerNum].medals & (1 << i)) {
				switch (i) {
				case 0: colour = 0xff7f7fff; break; // killmaster - red
				case 1: colour = 0xbfbf00ff; break; // headshot - yellow
				case 2: colour = 0x00ff00ff; break; // accuracy - green
				case 3: colour = 0x00bfbfff; break; // survivor - blue
				}

				if (!configured) {
					gDPPipeSync(gdl++);
					gDPSetTexturePersp(gdl++, G_TP_NONE);
					gDPSetAlphaCompare(gdl++, G_AC_NONE);
					gDPSetTextureLOD(gdl++, G_TL_TILE);
					gDPSetTextureConvert(gdl++, G_TC_FILT);
					gDPSetTextureFilter(gdl++, G_TF_POINT);

					texSelect(&gdl, &g_TexGeneralConfigs[35], 2, 0, 2, 1, NULL);

					gDPSetCycleType(gdl++, G_CYC_1CYCLE);
					gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
					gDPSetTextureFilter(gdl++, G_TF_POINT);

					gDPSetCombineLERP(gdl++,
							TEXEL0, 0, ENVIRONMENT, 0,
							TEXEL0, 0, ENVIRONMENT, 0,
							TEXEL0, 0, ENVIRONMENT, 0,
							TEXEL0, 0, ENVIRONMENT, 0);

					configured = true;
				}

				gDPSetEnvColorViaWord(gdl++, colour);

#if VERSION == VERSION_JPN_FINAL
				gSPTextureRectangle(gdl++,
						(x << 2) * g_ScaleX,
						(renderdata->y - 6) << 2,
						((x + 11) << 2) * g_ScaleX,
						(renderdata->y + 5) << 2,
						G_TX_RENDERTILE, 0x0010, 0x0150, 1024 / g_ScaleX, -1024);
#else
				gSPTextureRectangle(gdl++,
						(x << 2) * g_ScaleX,
						(renderdata->y - 2) << 2,
						((x + 11) << 2) * g_ScaleX,
						(renderdata->y + 9) << 2,
						G_TX_RENDERTILE, 0x0010, 0x0150, 1024 / g_ScaleX, -1024);
#endif

				x -= 14;
			}
		}

		return (s32) gdl;
	}

	return 0;
}

s32 mpPlayerTitleMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].title != g_PlayerConfigsArray[g_MpPlayerNum].newtitle) {
			data->label.colour2 = colourBlend(data->label.colour2, 0xffff00ff, func0f006b08(40) * 255);
		}
	}

	return 0;
}

char *mpMenuTextPlayerTitle(s32 arg0)
{
	return langGet(L_MISC_185 + g_PlayerConfigsArray[g_MpPlayerNum].title);
}

#if VERSION >= VERSION_NTSC_1_0
s32 mpConfirmPlayerNameHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;
	s32 i;

	switch (operation) {
	case MENUOP_GETTEXT:
		i = 0;

		while (g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] != '\n'
				&& g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] != '\0'
				&& i <= 10) {
			name[i] = g_PlayerConfigsArray[g_MpPlayerNum].base.name[i];
			i++;
		}

		while (i <= 10) {
			name[i] = '\0';
			i++;
		}
		break;
	case MENUOP_SETTEXT:
		i = 0;

		while (i <= 10 && name[i] != '\0') {
			g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] = name[i];
			i++;
		}

		g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] = '\n';
		i++;

		while (i <= 10) {
			g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] = '\0';
			i++;
		}
		break;
	case MENUOP_SET:
		filemgrPushSelectLocationDialog(6, FILETYPE_MPPLAYER);
		break;
	}

	return 0;
}
#endif

void mpPushPauseDialog(void)
{
	u32 prevplayernum = g_MpPlayerNum;

#if VERSION >= VERSION_NTSC_1_0
	if (g_MpSetup.paused != MPPAUSEMODE_GAMEOVER && g_MainIsEndscreen == 0)
#endif
	{
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;

		if (g_Menus[g_MpPlayerNum].openinhibit == 0) {
			g_Menus[g_MpPlayerNum].playernum = g_Vars.currentplayernum;

			if (g_Vars.normmplayerisrunning) {
				if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
					menuPushRootDialog(&g_MpPauseTeamRankingsMenuDialog, MENUROOT_MPPAUSE);
				} else {
					menuPushRootDialog(&g_MpPausePlayerRankingMenuDialog, MENUROOT_MPPAUSE);
				}
			} else {
				if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
					menuPushRootDialog(&g_2PMissionPauseVMenuDialog, MENUROOT_MPPAUSE);
				} else {
					menuPushRootDialog(&g_2PMissionPauseHMenuDialog, MENUROOT_MPPAUSE);
				}
			}
		}

		g_MpPlayerNum = prevplayernum;
	}
}

void mpPushEndscreenDialog(u32 arg0, u32 playernum)
{
	u32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = playernum;

	g_Menus[g_MpPlayerNum].playernum = arg0;

	if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
			if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
				menuPushRootDialog(&g_MpEndscreenChallengeCheatedMenuDialog, MENUROOT_MPENDSCREEN);
			} else if (challengeIsCompleteForEndscreen()) {
				menuPushRootDialog(&g_MpEndscreenChallengeCompletedMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menuPushRootDialog(&g_MpEndscreenChallengeFailedMenuDialog, MENUROOT_MPENDSCREEN);
			}
		} else {
			menuPushRootDialog(&g_MpEndscreenTeamGameOverMenuDialog, MENUROOT_MPENDSCREEN);
		}
	} else {
		menuPushRootDialog(&g_MpEndscreenIndGameOverMenuDialog, MENUROOT_MPENDSCREEN);
	}

#if VERSION >= VERSION_NTSC_1_0
#if VERSION >= VERSION_JPN_FINAL
	if (IS8MB())
#endif
	{
		if ((g_PlayerConfigsArray[g_MpPlayerNum].options & OPTION_ASKEDSAVEPLAYER) == 0
				&& g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid == 0
				&& g_PlayerConfigsArray[g_MpPlayerNum].fileguid.deviceserial == 0) {
			g_PlayerConfigsArray[g_MpPlayerNum].options |= OPTION_ASKEDSAVEPLAYER;
			menuPushDialog(&g_MpEndscreenSavePlayerMenuDialog);
		}
	}
#endif

	g_MpPlayerNum = prevplayernum;
}

struct menuitem g_MpGameOverMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x01000010, (u32)&mpGetCurrentPlayerName, (u32)&mpMenuTextPlacementWithSuffix, mpPlacementMenuHandler },
#if VERSION >= VERSION_JPN_FINAL
	{ MENUITEMTYPE_LABEL,       0, 0x01000020, (u32)&mpMenuTextPlayerTitle, 0, mpPlayerTitleMenuHandler }, // "Title:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU_262, 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00000002, 0x00000001, 0x00000003, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x00000001, 0x00000002, mpAwardsMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000100, (u32)&mpMenuTextAward1, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000100, (u32)&mpMenuTextAward2, 0x00000000, NULL },
#else
	{ MENUITEMTYPE_LABEL,       0, 0x01000000, L_MPMENU_261, (u32)&mpMenuTextPlayerTitle, mpPlayerTitleMenuHandler }, // "Title:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU_262, 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00200210, L_MPMENU_263, 0x00000000, mpAwardsMenuHandler }, // "Awards:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward1, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward2, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpEndscreenIndGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_260, // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0,
	&g_MpEndscreenPlayerRankingMenuDialog,
};

struct menudialogdef g_MpEndscreenTeamGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_260, // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0,
	&g_MpEndscreenTeamRankingMenuDialog,
};

struct menudialogdef g_MpEndscreenChallengeCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPWEAPONS_165, // "Challenge Completed!"
	g_MpTeamRankingsMenuItems,
	NULL,
	0,
	&g_MpEndscreenIndGameOverMenuDialog,
};

struct menudialogdef g_MpEndscreenChallengeCheatedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_167, // "Challenge Cheated!"
	g_MpTeamRankingsMenuItems,
	NULL,
	0,
	&g_MpEndscreenIndGameOverMenuDialog,
};

struct menudialogdef g_MpEndscreenChallengeFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_166, // "Challenge Failed!"
	g_MpTeamRankingsMenuItems,
	NULL,
	0,
	&g_MpEndscreenIndGameOverMenuDialog,
};

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_MpEndscreenConfirmNameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_250, 0x00000000, NULL }, // "Confirm player name:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, mpConfirmPlayerNameHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpEndscreenConfirmNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_142, // "Player Name"
	g_MpEndscreenConfirmNameMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpEndscreenSavePlayerMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_247, 0x00000000, NULL }, // "Save new player and statistics?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x0000002c, L_MPWEAPONS_248, 0x00000000, (void *)&g_MpEndscreenConfirmNameMenuDialog }, // "Save Now"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_249, 0x00000000, NULL }, // "No Thanks!"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpEndscreenSavePlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_246, // "Save Player"
	g_MpEndscreenSavePlayerMenuItems,
	NULL,
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
};
#endif
