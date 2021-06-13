#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/lv.h"
#include "game/mplayer/ingame.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/setup.h"
#include "game/options.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

struct menudialog g_MpEndscreenChallengeCompletedMenuDialog;
struct menudialog g_MpEndscreenIndGameOverMenuDialog;
struct menudialog g_MpEndscreenSavePlayerMenuDialog;
struct menudialog g_MpEndscreenTeamGameOverMenuDialog;

s32 mpStatsForPlayerDropdownHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name;
	s32 v0;
	s32 v1;
	s32 a1;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = 0;

		for (v0 = 0; v0 < 12; v0++) {
			if (g_MpSetup.chrslots & (1 << v0)) {
				data->list.value++;
			}
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		v0 = 0;

		for (a1 = 0; a1 < 12; a1++) {
			if (g_MpSetup.chrslots & (1 << a1)) {
				if (a1 < 4) {
					name = g_MpPlayers[a1].base.name;
				} else {
					name = g_MpSimulants[a1 - 4].base.name;
				}

				if (v0 == data->list.value) {
					return (s32) name;
				}

				v0++;
			}
		}

		return (s32) "";
	case MENUOP_SET:
		v0 = 0;

		for (a1 = 0; a1 < 12; a1++) {
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

		for (v1 = 0; v1 < 12; v1++) {
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
		if (g_MpSetupSaveFile.locktype != MPLOCKTYPE_CHALLENGE) {
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
	formatTime(g_StringPointer, lvGetStageTime60() * 60 / 50, 3);
#else
	formatTime(g_StringPointer, lvGetStageTime60(), 3);
#endif

	return g_StringPointer;
}

char *mpMenuTextWeaponDescription(struct menuitem *item)
{
	struct weapon *weapon = weaponFindById(g_Menus[g_MpPlayerNum].data.mppause.weaponnum);

	if (weapon) {
		return langGet(weapon->description);
	}

	return "\n";
}

char *mpMenuTitleStatsFor(struct menudialog *dialog)
{
	char *name;

	if (g_MpSelectedPlayersForStats[g_MpPlayerNum] < 4) {
		name = g_MpPlayers[g_MpSelectedPlayersForStats[g_MpPlayerNum]].base.name;
	} else {
		name = g_MpSimulants[g_MpSelectedPlayersForStats[g_MpPlayerNum] - 4].base.name;
	}

	// "Stats for %s"
	sprintf(g_StringPointer, langGet(L_MPMENU_280), name);
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

struct menudialog g_MpEndGameMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_290, // "End Game"
	g_MpEndGameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpPauseControlMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextChallengeName, 0x00000000, menuhandler00178018 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextScenarioName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_162, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Time Limit:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000200, L_MPWEAPONS_163, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Score Limit:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000200, L_MPWEAPONS_164, (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Team Score Limit:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_286, (u32)&menutextMatchTime, NULL }, // "Game Time:"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000020, (u32)&menutextPauseOrUnpause, 0x00000000, menuhandlerMpPause },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000024, L_MPMENU_287, 0x00000000, (void *)&g_MpEndGameMenuDialog }, // "End Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPauseControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_285, // "Control"
	g_MpPauseControlMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_Mp2PMissionInventoryMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x00000078, 0x00000042, menuhandler00106178 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextWeaponDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPauseInventoryMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_284, // "Inventory"
	g_Mp2PMissionInventoryMenuItems,
	NULL,
	0x00000000,
	&g_MpPauseControlMenuDialog,
};

struct menudialog g_2PMissionInventoryHMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_284, // "Inventory"
	g_Mp2PMissionInventoryMenuItems,
	NULL,
	0x00000000,
	&g_2PMissionOptionsHMenuDialog,
};

struct menudialog g_2PMissionInventoryVMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_284, // "Inventory"
	g_Mp2PMissionInventoryMenuItems,
	NULL,
	0x00000000,
	&g_2PMissionOptionsVMenuDialog,
};

struct menuitem g_MpInGamePlayerStatsMenuItems[] = {
	{ MENUITEMTYPE_PLAYERSTATS, 0, 0x00000000, 0x00000000, 0x00000000, mpStatsForPlayerDropdownHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPausePlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsFor,
	g_MpInGamePlayerStatsMenuItems,
	NULL,
	0x00000000,
	&g_MpPauseInventoryMenuDialog,
};

struct menudialog g_MpEndscreenPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsFor,
	g_MpInGamePlayerStatsMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpPlayerRankingMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPausePlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_276, // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpPausePlayerStatsMenuDialog,
};

struct menudialog g_MpEndscreenPlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_276, // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerStatsMenuDialog,
};

struct menuitem g_MpTeamRankingsMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000001, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPauseTeamRankingsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_279, // "Team Ranking"
	g_MpTeamRankingsMenuItems,
	NULL,
	0x00000000,
	&g_MpPausePlayerRankingMenuDialog,
};

struct menudialog g_MpEndscreenTeamRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_279, // "Team Ranking"
	g_MpTeamRankingsMenuItems,
	NULL,
	0x00000000,
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

	return langGet(suffixes[g_MpPlayers[g_MpPlayerNum].base.placement]);
}

s32 mpPlacementMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR) {
		if (g_MpPlayers[g_MpPlayerNum].base.placement == 0) { // winner
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
			if (g_MpPlayers[g_MpPlayerNum].medals & (1 << i)) {
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

					func0f0b39c0(&gdl, &var800ab5a8[35], 2, 0, 2, 1, 0);

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

				gSPTextureRectangle(gdl++,
						(x << 2) * g_ScaleX,
						(renderdata->y - 2) << 2,
						((x + 11) << 2) * g_ScaleX,
						(renderdata->y + 9) << 2,
						G_TX_RENDERTILE, 0x0010, 0x0150, 1024 / g_ScaleX, -1024);

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
		if (g_MpPlayers[g_MpPlayerNum].title != g_MpPlayers[g_MpPlayerNum].newtitle) {
			data->label.colour2 = colourBlend(data->label.colour2, 0xffff00ff, func0f006b08(40) * 255);
		}
	}

	return 0;
}

char *mpMenuTextPlayerTitle(s32 arg0)
{
	return langGet(L_MISC_185 + g_MpPlayers[g_MpPlayerNum].title);
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuhandler00178bf4
/*  f178bf4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f178bf8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178bfc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f178c00:	24010006 */ 	addiu	$at,$zero,0x6
/*  f178c04:	10810065 */ 	beq	$a0,$at,.L0f178d9c
/*  f178c08:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f178c0c:	24010011 */ 	addiu	$at,$zero,0x11
/*  f178c10:	10810006 */ 	beq	$a0,$at,.L0f178c2c
/*  f178c14:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f178c18:	24010012 */ 	addiu	$at,$zero,0x12
/*  f178c1c:	10810033 */ 	beq	$a0,$at,.L0f178cec
/*  f178c20:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f178c24:	10000061 */ 	b	.L0f178dac
/*  f178c28:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178c2c:
/*  f178c2c:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f178c30:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f178c34:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f178c38:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f178c3c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f178c40:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f178c44:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f178c48:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f178c4c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f178c50:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f178c54:	00001825 */ 	or	$v1,$zero,$zero
/*  f178c58:	1138001a */ 	beq	$t1,$t8,.L0f178cc4
/*  f178c5c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f178c60:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f178c64:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f178c68:	00f92821 */ 	addu	$a1,$a3,$t9
/*  f178c6c:	90ab0000 */ 	lbu	$t3,0x0($a1)
/*  f178c70:	01401021 */ 	addu	$v0,$t2,$zero
/*  f178c74:	2406000b */ 	addiu	$a2,$zero,0xb
/*  f178c78:	51600013 */ 	beqzl	$t3,.L0f178cc8
/*  f178c7c:	2861000b */ 	slti	$at,$v1,0xb
/*  f178c80:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f178c84:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f178c88:
/*  f178c88:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f178c8c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178c90:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178c94:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f178c98:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f178c9c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f178ca0:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f178ca4:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f178ca8:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f178cac:	51240006 */ 	beql	$t1,$a0,.L0f178cc8
/*  f178cb0:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cb4:	50800004 */ 	beqzl	$a0,.L0f178cc8
/*  f178cb8:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cbc:	5466fff2 */ 	bnel	$v1,$a2,.L0f178c88
/*  f178cc0:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f178cc4:
/*  f178cc4:	2861000b */ 	slti	$at,$v1,0xb
.L0f178cc8:
/*  f178cc8:	10200037 */ 	beqz	$at,.L0f178da8
/*  f178ccc:	01431021 */ 	addu	$v0,$t2,$v1
.L0f178cd0:
/*  f178cd0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178cd4:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cd8:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f178cdc:	1420fffc */ 	bnez	$at,.L0f178cd0
/*  f178ce0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178ce4:	10000031 */ 	b	.L0f178dac
/*  f178ce8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178cec:
/*  f178cec:	91590000 */ 	lbu	$t9,0x0($t2)
/*  f178cf0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f178cf4:	00001825 */ 	or	$v1,$zero,$zero
/*  f178cf8:	13200014 */ 	beqz	$t9,.L0f178d4c
/*  f178cfc:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f178d00:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f178d04:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f178d08:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f178d0c:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f178d10:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f178d14:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f178d18:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f178d1c:	018e2021 */ 	addu	$a0,$t4,$t6
/*  f178d20:	01401021 */ 	addu	$v0,$t2,$zero
/*  f178d24:	91450000 */ 	lbu	$a1,0x0($t2)
/*  f178d28:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f178d2c:
/*  f178d2c:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d30:	a0850000 */ 	sb	$a1,0x0($a0)
/*  f178d34:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f178d38:	10200004 */ 	beqz	$at,.L0f178d4c
/*  f178d3c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178d40:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f178d44:	54a0fff9 */ 	bnezl	$a1,.L0f178d2c
/*  f178d48:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f178d4c:
/*  f178d4c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f178d50:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f178d54:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f178d58:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f178d5c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f178d60:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f178d64:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f178d68:	03232021 */ 	addu	$a0,$t9,$v1
/*  f178d6c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178d70:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d74:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f178d78:	1020000b */ 	beqz	$at,.L0f178da8
/*  f178d7c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f178d80:
/*  f178d80:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178d84:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d88:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f178d8c:	1420fffc */ 	bnez	$at,.L0f178d80
/*  f178d90:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f178d94:	10000005 */ 	b	.L0f178dac
/*  f178d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178d9c:
/*  f178d9c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f178da0:	0fc42947 */ 	jal	filemgrPushSelectLocationDialog
/*  f178da4:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f178da8:
/*  f178da8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178dac:
/*  f178dac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178db0:	00001025 */ 	or	$v0,$zero,$zero
/*  f178db4:	03e00008 */ 	jr	$ra
/*  f178db8:	00000000 */ 	nop
);
#endif

void mpPushPauseDialog(void)
{
	u32 prevplayernum = g_MpPlayerNum;

#if VERSION >= VERSION_NTSC_1_0
	if (g_MpSetup.paused != MPPAUSEMODE_GAMEOVER && g_MainIsEndscreen == 0)
#endif
	{
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;

		if (g_Menus[g_MpPlayerNum].unk83c == 0) {
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
		if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
			if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
				menuPushRootDialog(&g_MpEndscreenChallengeCheatedMenuDialog, MENUROOT_MPENDSCREEN);
			} else if (mpIsChallengeCompleteForEndscreen()) {
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
	if ((g_MpPlayers[g_MpPlayerNum].options & OPTION_ASKEDSAVEPLAYER) == 0
			&& g_MpPlayers[g_MpPlayerNum].unk4c.unk00 == false
			&& g_MpPlayers[g_MpPlayerNum].unk4c.unk04 == 0) {
		g_MpPlayers[g_MpPlayerNum].options |= OPTION_ASKEDSAVEPLAYER;
		menuPushDialog(&g_MpEndscreenSavePlayerMenuDialog);
	}
#endif

	g_MpPlayerNum = prevplayernum;
}

struct menuitem g_MpGameOverMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x01000010, (u32)&mpGetCurrentPlayerName, (u32)&mpMenuTextPlacementWithSuffix, mpPlacementMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x01000000, L_MPMENU_261, (u32)&mpMenuTextPlayerTitle, mpPlayerTitleMenuHandler }, // "Title:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU_262, 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00200210, L_MPMENU_263, 0x00000000, mpAwardsMenuHandler }, // "Awards:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward1, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward2, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpEndscreenIndGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_260, // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerRankingMenuDialog,
};

struct menudialog g_MpEndscreenTeamGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_260, // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenTeamRankingMenuDialog,
};

struct menudialog g_MpEndscreenChallengeCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPWEAPONS_165, // "Challenge Completed!"
	g_MpTeamRankingsMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndGameOverMenuDialog,
};

struct menudialog g_MpEndscreenChallengeCheatedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_167, // "Challenge Cheated!"
	g_MpTeamRankingsMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndGameOverMenuDialog,
};

struct menudialog g_MpEndscreenChallengeFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_166, // "Challenge Failed!"
	g_MpTeamRankingsMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndGameOverMenuDialog,
};

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_MpEndscreenConfirmNameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_250, 0x00000000, NULL }, // "Confirm player name:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler00178bf4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpEndscreenConfirmNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_142, // "Player Name"
	g_MpEndscreenConfirmNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpEndscreenSavePlayerMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_247, 0x00000000, NULL }, // "Save new player and statistics?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x0000002c, L_MPWEAPONS_248, 0x00000000, (void *)&g_MpEndscreenConfirmNameMenuDialog }, // "Save Now"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_249, 0x00000000, NULL }, // "No Thanks!"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpEndscreenSavePlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_246, // "Save Player"
	g_MpEndscreenSavePlayerMenuItems,
	NULL,
	0x00000004,
	NULL,
};
#endif
