#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/ceil.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/menugfx.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/inv.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/texdecompress.h"
#include "game/trainingmenus.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

struct menudialogdef g_BioProfileMenuDialog;
struct menudialogdef g_BioTextMenuDialog;
struct menudialogdef g_HangarLocationDetailsMenuDialog;
struct menudialogdef g_HangarVehicleDetailsMenuDialog;

s32 frDetailsOkMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 i;

	switch (operation) {
	case MENUOP_CHECKPREFOCUSED:
		return true;
	case MENUOP_SET:
		if (frIsInTraining() == false) {
			s32 weapon = frGetWeaponBySlot(frGetSlot());

			if (g_FrWeaponNum != WEAPON_UNARMED) {
				invRemoveItemByNum(g_FrWeaponNum);
			}

			if (weapon != WEAPON_UNARMED) {
				invGiveSingleWeapon(weapon);
			}

			invSetCurrentIndex(1);

			if (bgunGetWeaponNum(HAND_RIGHT) != weapon) {
				bgunEquipWeapon2(HAND_RIGHT, weapon);
			}

			g_FrWeaponNum = weapon;

			for (i = 0; i < 4; i++) {
				g_Vars.currentplayer->hands[0].gunroundsspent[i] = 0;
				g_Vars.currentplayer->hands[1].gunroundsspent[i] = 0;
			}

			frBeginSession(weapon);
		}

		func0f0f8120();
		break;
	}

	return 0;
}

s32 frAbortMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (frIsInTraining()) {
			frEndSession(true);
		}
	}

	return 0;
}

struct menudialogdef g_FrDifficultyMenuDialog;

s32 frWeaponListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 weaponnum;
	s32 score;
	Gfx *gdl;
	struct menuitemrenderdata *renderdata;
	u32 colour;
	s32 weaponnum2;
	s32 score2;
	s32 i;
	s32 x;
	s32 y;

	switch (operation) {
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = LINEHEIGHT;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 0;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return 0;
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = 0;
		break;
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = frGetNumWeaponsAvailable();
		break;
	case MENUOP_GETOPTIONTEXT:
		return 0;
	case MENUOP_SET:
		weaponnum = frGetWeaponBySlot(data->list.value);
		score = ciGetFiringRangeScore(frGetWeaponIndexByWeapon(weaponnum));

#if VERSION < VERSION_NTSC_1_0
		if (g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1].numsiblings > 1) {
			menuCloseDialog();
			menuPushDialog(&g_FrWeaponListMenuDialog);
		}
#endif

		frLoadData();
		frSetSlot(data->list.value);

		if (score) {
			frSetDifficulty(ciGetFiringRangeScore(frGetWeaponIndexByWeapon(weaponnum)));
			menuPushDialog(&g_FrDifficultyMenuDialog);
		} else {
			frSetDifficulty(FRDIFFICULTY_BRONZE);
			menuPushDialog(&g_FrTrainingInfoPreGameMenuDialog);
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = frGetSlot();
		break;
	case MENUOP_RENDER:
		gdl = data->type19.gdl;
		renderdata = data->type19.renderdata2;
		weaponnum2 = frGetWeaponBySlot(data->type19.unk04);
		score2 = ciGetFiringRangeScore(frGetWeaponIndexByWeapon(weaponnum2));

		// Render weapon name
		x = renderdata->x + 10;
		y = renderdata->y;

#if VERSION == VERSION_JPN_FINAL
		y++;
#endif

		gdl = text0f153628(gdl);
		gdl = textRenderProjected(gdl, &x, &y, bgunGetName(weaponnum2), g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);
		gdl = text0f153780(gdl);

		// Prepare the star texture for the difficulties
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

		// Iterate and render the 3 difficulty stars
		for (i = 0; i < 3; i++) {
			if (score2 > i) {
				switch (i) {
				case FRDIFFICULTY_BRONZE:
					colour = 0x884400ff;
					break;
				case FRDIFFICULTY_SILVER:
					colour = 0x99999fff;
					break;
				case FRDIFFICULTY_GOLD:
					colour = 0xbb9922ff;
					break;
				}
			} else {
				colour = 0x99999944;
			}

#if VERSION >= VERSION_NTSC_1_0
			colour = colour & 0xffffff00 | ((colour & 0xff) * (renderdata->colour & 0xff)) >> 8;
#endif

			gDPSetEnvColorViaWord(gdl++, colour);

			gDPSetCombineLERP(gdl++,
					TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);

			gSPTextureRectangle(gdl++,
					(((renderdata->x + i * 13) + 125) << 2) * g_ScaleX, (renderdata->y) << 2,
					(((renderdata->x + i * 13) + 136) << 2) * g_ScaleX, (renderdata->y + 11) << 2,
					G_TX_RENDERTILE, 0, 0x0160, 1024 / g_ScaleX, -1024);
		}

		return (s32)gdl;
	}

	return 0;
}

s32 frTrainingInfoMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	u32 stack;
	s32 weaponnum;

	switch (operation) {
	case MENUOP_OPEN:
		weaponnum = frGetWeaponBySlot(frGetSlot());
		g_Menus[g_MpPlayerNum].training.weaponnum = weaponnum;
		func0f105948(weaponnum);

		if (!frIsInTraining()) {
			frInitAmmo(weaponnum);
		}
		break;
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curdialog && g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef) {
			g_Menus[g_MpPlayerNum].unk840.unk574 -= g_Vars.diffframe60;
			g_Menus[g_MpPlayerNum].unk840.unk54c = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unk840.unk524 = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unk840.unk528 = 0;
			g_Menus[g_MpPlayerNum].unk840.unk550 = 0;
		}
		break;
	case MENUOP_CLOSE:
		if (!frIsInTraining()) {
			frEndSession(true);
		}
		break;
	}

	return 0;
}

s32 frTrainingStatsMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		if (frIsInTraining() == false) {
			frEndSession(true);
		}
	}

	return 0;
}

/**
 * This is an unused menu handler which implements the difficulty selection
 * using a dropdown.
 */
s32 frDifficultyDropdownMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 names[] = {
		L_MPMENU_439, // "Bronze"
		L_MPMENU_440, // "Silver"
		L_MPMENU_441, // "Gold"
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = ciGetFiringRangeScore(frGetSlot()) + 1;

		if (data->dropdown.value > 3) {
			data->dropdown.value = 3;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(names[data->dropdown.value]);
	case MENUOP_SET:
		frSetDifficulty(data->dropdown.value);
		menuPushDialog(&g_FrTrainingInfoPreGameMenuDialog);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = frGetDifficulty();
		break;
	}

	return 0;
}

s32 frDifficultyMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_CHECKHIDDEN:
		if (ciGetFiringRangeScore(frGetWeaponIndexByWeapon(frGetWeaponBySlot(frGetSlot()))) < item->param) {
			return true;
		}
		break;
	case MENUOP_SET:
		frSetDifficulty(item->param);
		menuPushDialog(&g_FrTrainingInfoPreGameMenuDialog);
		break;
	case MENUOP_CHECKPREFOCUSED:
		if (ciGetFiringRangeScore(frGetWeaponIndexByWeapon(frGetWeaponBySlot(frGetSlot()))) >= item->param) {
			return true;
		}
		break;
	}

	return 0;
}

char *frPrimaryFunctionMenuText(struct menuitem *item)
{
	struct weaponfunc *func = weaponGetFunctionById(frGetWeaponBySlot(frGetSlot()), FUNC_PRIMARY);

	if (func) {
		return langGet(func->name);
	}

	return "\n";
}

char *frSecondaryFunctionMenuText(struct menuitem *item)
{
	struct weaponfunc *func = weaponGetFunctionById(frGetWeaponBySlot(frGetSlot()), FUNC_SECONDARY);

	if (func) {
		return langGet(func->name);
	}

	return "\n";
}

char *frMenuTextFailReason(struct menuitem *item)
{
	u16 reasons[] = {
		L_MPMENU_456, // "Not Failed"
		L_MPMENU_457, // "Out of Ammo"
		L_MPMENU_458, // "Time Over"
		L_MPMENU_459, // "Score Unattainable"
		L_MPMENU_460, // "Too Inaccurate"
	};

	struct frdata *frdata = frGetData();

	return langGet(reasons[frdata->failreason]);
}

char *frMenuTextDifficultyName(struct menuitem *item)
{
	u16 names[] = {
		L_MPMENU_439, // "Bronze"
		L_MPMENU_440, // "Silver"
		L_MPMENU_441, // "Gold"
	};

	struct frdata *frdata = frGetData();

	return langGet(names[frdata->difficulty]);
}

char *frMenuTextTimeTakenValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	f32 secs = frdata->timetaken / (PAL ? 50.0f : 60.0f);

	if (secs > frdata->timelimit) {
		secs = frdata->timelimit;
	}

	if (secs >= 60.0f) {
		s32 mins = 0;

		while (secs >= 60.0f) {
			secs -= 60.0f;
			mins++;
		}

		sprintf(g_StringPointer, "%dm %2ds\n", mins, (s32)ceilf(secs));
		return g_StringPointer;
	} else {
		sprintf(g_StringPointer, "%s%s%2.2fs\n", "", "", secs);
	}

	return g_StringPointer;
}

char *frMenuTextScoreValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	sprintf(g_StringPointer, "%d\n", frdata->score);
	return g_StringPointer;
}

char *frMenuTextGoalScoreValueUnconditional(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	sprintf(g_StringPointer, "%d\n", frdata->goalscore);
	return g_StringPointer;
}

char *frMenuTextWeaponName(struct menuitem *item)
{
	return bgunGetName(frGetWeaponBySlot(frGetSlot()));
}

char *frMenuTextTargetsDestroyedValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	sprintf(g_StringPointer, "%d\n", frdata->targetsdestroyed);
	return g_StringPointer;
}

char *frMenuTextAccuracyValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	f32 totalhits = (frdata->numhitsring3 + frdata->numhitsbullseye + frdata->numhitsring1 + frdata->numhitsring2) * 100.0f;
	f32 accuracy = 0;

	if (frdata->numshots) {
		accuracy = totalhits / frdata->numshots;
	}

	if (accuracy > 100.0f) {
		accuracy = 100.0f;
	}

	sprintf(g_StringPointer, "%s%s%.1f%%\n", "", "", accuracy);
	return g_StringPointer;
}

char *frMenuTextGoalScoreLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalscore > 0) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_475)); // "Goal Score:"
		return g_StringPointer;
	}

	return NULL;
}

char *frMenuTextGoalScoreValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalscore > 0) {
		sprintf(g_StringPointer2, "%d\n", frdata->goalscore);
		return g_StringPointer2;
	}

	return NULL;
}

char *frMenuTextMinAccuracyOrTargetsLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalaccuracy > 0) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_473)); // "Min Accuracy:"
	} else if (frdata->goaltargets != 255) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_474)); // "Goal Targets:"
	} else {
		return NULL;
	}

	return g_StringPointer;
}

char *frMenuTextMinAccuracyOrTargetsValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalaccuracy > 0) {
		sprintf(g_StringPointer2, "%d%%\n", frdata->goalaccuracy);
	} else if (frdata->goaltargets != 255) {
		sprintf(g_StringPointer2, "%d\n", frdata->goaltargets);
	} else {
		return NULL;
	}

	return g_StringPointer2;
}

char *frMenuTextTimeLimitLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->timelimit != 255) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_472)); // "Time Limit:"
	} else {
		return NULL;
	}

	return g_StringPointer;
}

char *frMenuTextTimeLimitValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->timelimit != 255) {
		s32 secs = frdata->timelimit;
		s32 mins = 0;

		while (secs >= 60) {
			secs -= 60;
			mins++;
		}

		if (mins > 0) {
			sprintf(g_StringPointer2, "%dm %ds\n", mins, secs);
		} else {
			sprintf(g_StringPointer2, "%ds\n", secs);
		}
	} else {
		return NULL;
	}

	return g_StringPointer2;
}

char *frMenuTextAmmoLimitLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->ammolimit != 255) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_471)); // "Ammo Limit:"
	} else {
		return NULL;
	}

	return g_StringPointer;
}

char *frMenuTextAmmoLimitValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	char suffix[16];
	s32 weaponnum;

	if (frdata->ammolimit != 255) {
		weaponnum = frGetWeaponBySlot(frdata->slot);

		if (weaponnum == WEAPON_SUPERDRAGON && frdata->sdgrenadelimit != 255) {
			sprintf(suffix, "/%d", frdata->sdgrenadelimit);
		} else {
			suffix[0] = '\0';
		}

		sprintf(g_StringPointer2, "%d%s\n", frdata->ammolimit, suffix);
	} else {
		return NULL;
	}

	return g_StringPointer2;
}

/**
 * Render the "Scoring" section of the firing range results screen.
 *
 * The screen contains a diagram of a target with the zones marked,
 * as well as the player's score chart. There are lines leading from
 * the score chart to the diagram.
 */
s32 frScoringMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_RENDER) {
		Gfx *gdl = data->type19.gdl;
		struct menuitemrenderdata *renderdata = data->type19.renderdata2;
		s32 x;
		s32 y;
		s32 textheight;
		s32 textwidth;
		struct textureconfig *tconfig = &g_TexGeneralConfigs[50];
		struct frdata *frdata = frGetData();
		char text[128];
		bool failed = frdata->menutype == FRMENUTYPE_FAILED;
#if VERSION >= VERSION_JPN_FINAL
		u32 linecolourmid = failed ? 0xff644477 : 0x00ff0077; // line gradient colour in middle
		u32 linecolourfig = failed ? 0xff664400 : 0x00ff0000; // line gradient colour at figures
		u32 linecolourtex = failed ? 0xff664433 : 0x00ff0033; // line gradient colour at target texture
#else
		u32 linecolourmid = failed ? 0xff000077 : 0x00ff0077; // line gradient colour in middle
		u32 linecolourfig = failed ? 0xff000000 : 0x00ff0000; // line gradient colour at figures
		u32 linecolourtex = failed ? 0xff000033 : 0x00ff0033; // line gradient colour at target texture
#endif

#if VERSION >= VERSION_NTSC_1_0
		u32 colour;
#endif

		static u32 x1 = 0;
		static u32 x2 = 0;
		static u32 y1 = 0;
		static u32 y2 = 0;
		static u32 x3 = 0;
		static u32 x4 = 0;
		static u32 y3 = 0;
		static u32 y4 = 0;

#if VERSION >= VERSION_NTSC_1_0
		linecolourmid = linecolourmid & 0xffffff00 | (linecolourmid & 0xff) * (renderdata->colour & 0xff) >> 8;
		linecolourfig = linecolourfig & 0xffffff00 | (linecolourfig & 0xff) * (renderdata->colour & 0xff) >> 8;
		linecolourtex = linecolourtex & 0xffffff00 | (linecolourtex & 0xff) * (renderdata->colour & 0xff) >> 8;
#endif

		mainOverrideVariable("x1", &x1);
		mainOverrideVariable("x2", &x2);
		mainOverrideVariable("y1", &y1);
		mainOverrideVariable("y2", &y2);
		mainOverrideVariable("x3", &x3);
		mainOverrideVariable("x4", &x4);
		mainOverrideVariable("y3", &y3);
		mainOverrideVariable("y4", &y4);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		texSelect(&gdl, tconfig, 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

#if VERSION >= VERSION_NTSC_1_0
		colour = (failed ? 0xff777799 : 0x55ff5588) & 0xffffff00 | ((failed ? 0xff777799 : 0x55ff5588) & 0xff) * (renderdata->colour & 0xff) >> 8;
		gDPSetEnvColorViaWord(gdl++, colour);
#else
		gDPSetEnvColorViaWord(gdl++, failed ? 0xff777799 : 0x55ff5588);
#endif

		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);

		// Top left quarter of target
		gSPTextureRectangle(gdl++,
				((renderdata->x + 10) << 2) * g_ScaleX, (renderdata->y + 5) << 2,
				((renderdata->x + 42) << 2) * g_ScaleX, (renderdata->y + 37) << 2,
				G_TX_RENDERTILE, 16, 1024, 1024 / g_ScaleX, -1024);

		// Top right quarter of target
		gSPTextureRectangle(gdl++,
				((renderdata->x + 41) << 2) * g_ScaleX, (renderdata->y + 5) << 2,
				((renderdata->x + 73) << 2) * g_ScaleX, (renderdata->y + 37) << 2,
				G_TX_RENDERTILE, 16, 1024, -1024 / g_ScaleX, -1024);

		// Bottom left quarter of target
		gSPTextureRectangle(gdl++,
				((renderdata->x + 10) << 2) * g_ScaleX, (renderdata->y + 36) << 2,
				((renderdata->x + 42) << 2) * g_ScaleX, (renderdata->y + 68) << 2,
				G_TX_RENDERTILE, 16, 1024, 1024 / g_ScaleX, 1024);

		// Bottom right quarter of target
		gSPTextureRectangle(gdl++,
				((renderdata->x + 41) << 2) * g_ScaleX, (renderdata->y + 36) << 2,
				((renderdata->x + 73) << 2) * g_ScaleX, (renderdata->y + 68) << 2,
				G_TX_RENDERTILE, 16, 1024, -1024 / g_ScaleX, 1024);

#if VERSION >= VERSION_NTSC_1_0
		gdl = textSetPrimColour(gdl, (failed ? 0xff000055 : 0x00ff0055) & 0xffffff00 | ((failed ? 0xff000055 : 0x00ff0055) & 0xff) * (renderdata->colour & 0xff) >> 8);
		colour = (failed ? 0xff6969aa : renderdata->colour) & 0xffffff00 | (((failed ? 0xff6969aa : renderdata->colour) & 0xff) * (renderdata->colour & 0xff)) >> 8;
#else
		gdl = textSetPrimColour(gdl, failed ? 0xff000055 : 0x00ff0055);
#endif

		// NTSC beta uses a static alpha channel, while newer versions take the
		// alpha from the menu item's renderdata. Additionally, NTSC beta
		// repeats its colour calculation throughout this function while newer
		// versions store it in a variable. To prevent having version checks
		// everywhere, this has been implemented here using macros.
#if VERSION >= VERSION_NTSC_1_0
#define COLOUR() (colour)
#define COLOURWHITE() (0xffffff00 | (((renderdata->colour & 0xff) * 0xff) >> 8))
#else
#define COLOUR() (failed ? 0xff6969aa : renderdata->colour)
#define COLOURWHITE() 0xffffffff
#endif

		// Bull's-eye count
		sprintf(text, "%d\n", frdata->numhitsbullseye);
		x = renderdata->x + 93;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 15 : 14);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// "Bull's-eye"
		sprintf(text, langGet(L_MPMENU_461));
		x = renderdata->x + 122;
		y = renderdata->y + 14;
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Bull's-eye score
		sprintf(text, "%d\n", frdata->numhitsbullseye * 10);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = renderdata->x - textheight + (VERSION == VERSION_JPN_FINAL ? 192 : 182);
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 15 : 14);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Zone 1 count
		sprintf(text, "%d\n", frdata->numhitsring1);
		x = renderdata->x + 93;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 27 : 25);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// "Zone 1"
		sprintf(text, langGet(L_MPMENU_462));
		x = renderdata->x + 122;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 26 : 25);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Zone 1 score
		sprintf(text, "%d\n", frdata->numhitsring1 * 5);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = renderdata->x - textheight + (VERSION == VERSION_JPN_FINAL ? 192 : 182);
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 27 : 25);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Zone 2 count
		sprintf(text, "%d\n", frdata->numhitsring2);
		x = renderdata->x + 93;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 39 : 36);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// "Zone 2"
		sprintf(text, langGet(L_MPMENU_463));
		x = renderdata->x + 122;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 38 : 36);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Zone 2 score
		sprintf(text, "%d\n", frdata->numhitsring2 * 2);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = renderdata->x - textheight + (VERSION == VERSION_JPN_FINAL ? 192 : 182);
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 39 : 36);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Zone 3 count
		sprintf(text, "%d\n", frdata->numhitsring3);
		x = renderdata->x + 93;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 51 : 47);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// "Zone 3"
		// Note: developers forgot to remove last argument when copy/pasting
		sprintf(text, langGet(L_MPMENU_464), frdata->numhitsring3);
		x = renderdata->x + 122;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 50 : 47);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Zone 3 score
		sprintf(text, "%d\n", frdata->numhitsring3);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = renderdata->x - textheight + (VERSION == VERSION_JPN_FINAL ? 192 : 182);
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 51 : 47);
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// "Hit total"
		sprintf(text, langGet(L_MPMENU_465));
		x = renderdata->x + 133;
		y = renderdata->y + 63;

#if VERSION >= VERSION_JPN_FINAL
		x -= 44;
		y += 3;
#endif

		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// Hit total count
		sprintf(text, "%d\n", frdata->numhitsring3 + frdata->numhitsbullseye + frdata->numhitsring1 + frdata->numhitsring2);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = renderdata->x - textheight + 188;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 64 : 63);

#if VERSION >= VERSION_JPN_FINAL
		x -= 27;
		y += 3;
#endif

		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// "Scoring"
		sprintf(text, langGet(L_MPMENU_466));
		x = renderdata->x + 83;
		y = renderdata->y + 1;
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, COLOUR(), viGetWidth(), viGetHeight(), 0, 0);

		// "10"
		sprintf(text, langGet(L_MPMENU_467));
		x = renderdata->x + 38;
		y = renderdata->y + 35;
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, COLOURWHITE(), viGetWidth(), viGetHeight(), 0, 0);

		// "5"
		sprintf(text, langGet(L_MPMENU_468));
		x = renderdata->x + 32;
		y = renderdata->y + 26;
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, COLOURWHITE(), viGetWidth(), viGetHeight(), 0, 0);

		// "2"
		sprintf(text, langGet(L_MPMENU_469));
		x = renderdata->x + 24;
		y = renderdata->y + 16;
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, COLOURWHITE(), viGetWidth(), viGetHeight(), 0, 0);

		// "1"
		sprintf(text, langGet(L_MPMENU_470));
		x = renderdata->x + 14;
		y = renderdata->y + 4;
		gdl = text0f153858(gdl, &x, &y, &textheight, &textwidth);
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, COLOURWHITE(), viGetWidth(), viGetHeight(), 0, 0);

		gdl = text0f153838(gdl);

		// Render lines between the score table and the target texture

		// Horizontal lines - bottom left
		gdl = menugfxDrawFilledRect(gdl, renderdata->x + 45, renderdata->y + 36, renderdata->x + 81, renderdata->y + 37, linecolourtex, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 52, renderdata->y + 44, renderdata->x + 84, renderdata->y + 45, linecolourtex, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 62, renderdata->y + 50, renderdata->x + 87, renderdata->y + 51, linecolourtex, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 70, renderdata->y + 60, renderdata->x + 90, renderdata->y + 61, linecolourtex, linecolourmid);

#if VERSION >= VERSION_JPN_FINAL
		// Vertical lines
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 81, renderdata->y + 17, renderdata->x + 82, renderdata->y + 37, linecolourmid, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 84, renderdata->y + 29, renderdata->x + 85, renderdata->y + 45, linecolourmid, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 87, renderdata->y + 41, renderdata->x + 88, renderdata->y + 51, linecolourmid, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 90, renderdata->y + 53, renderdata->x + 91, renderdata->y + 61, linecolourmid, linecolourmid);

		// Horizontal lines - top right
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 81, renderdata->y + 17, renderdata->x + 96, renderdata->y + 18, linecolourmid, linecolourfig);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 84, renderdata->y + 29, renderdata->x + 96, renderdata->y + 30, linecolourmid, linecolourfig);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 87, renderdata->y + 41, renderdata->x + 96, renderdata->y + 42, linecolourmid, linecolourfig);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 90, renderdata->y + 53, renderdata->x + 96, renderdata->y + 54, linecolourmid, linecolourfig);
#else
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 81, renderdata->y + 17, renderdata->x + 82, renderdata->y + 37, linecolourmid, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 84, renderdata->y + 28, renderdata->x + 85, renderdata->y + 45, linecolourmid, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 87, renderdata->y + 39, renderdata->x + 88, renderdata->y + 51, linecolourmid, linecolourmid);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 90, renderdata->y + 50, renderdata->x + 91, renderdata->y + 61, linecolourmid, linecolourmid);

		// Horizontal lines - top right
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 81, renderdata->y + 17, renderdata->x + 96, renderdata->y + 18, linecolourmid, linecolourfig);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 84, renderdata->y + 28, renderdata->x + 96, renderdata->y + 29, linecolourmid, linecolourfig);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 87, renderdata->y + 39, renderdata->x + 96, renderdata->y + 40, linecolourmid, linecolourfig);
		gdl = menugfxDrawDialogBorderLine(gdl, renderdata->x + 90, renderdata->y + 50, renderdata->x + 96, renderdata->y + 51, linecolourmid, linecolourfig);
#endif

		return (s32)gdl;
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
s32 menuhandlerFrFailedContinue(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.currentplayer->prop->rooms[0] == 0xa) {
			func0f0f3704(&g_FrWeaponListMenuDialog);
		} else {
			menuPopDialog();
		}
	}

	return 0;
}
#endif

struct menuitem g_FrDifficultyMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000012, L_MPMENU_444, L_MPMENU_445, NULL }, // "Select Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPMENU_439, L_OPTIONS_003, frDifficultyMenuHandler }, // "Bronze"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000020, L_MPMENU_440, L_OPTIONS_003, frDifficultyMenuHandler }, // "Silver"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000020, L_MPMENU_441, L_OPTIONS_003, frDifficultyMenuHandler }, // "Gold"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU_429, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FrDifficultyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_442, // "Difficulty"
	g_FrDifficultyMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

struct menuitem g_FrWeaponListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00200008, 0x000000aa, 0x00000000, frWeaponListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FrWeaponListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_446, // "Weapon"
	g_FrWeaponListMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

struct menuitem g_FrTrainingInfoInGameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_443,                             (u32)&frMenuTextDifficultyName,            NULL                   }, // "Difficulty"
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextGoalScoreLabel,            (u32)&frMenuTextGoalScoreValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextMinAccuracyOrTargetsLabel, (u32)&frMenuTextMinAccuracyOrTargetsValue, NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextTimeLimitLabel,            (u32)&frMenuTextTimeLimitValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextAmmoLimitLabel,            (u32)&frMenuTextAmmoLimitValue,            NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_FRWEAPON, 0x00004000, 0x0000010e,                                PAL ? 0x69 : 0x5f,                                NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_428,                             frDetailsOkMenuHandler }, // "", "Resume"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_430,                             frAbortMenuHandler    }, // "", "Abort"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
};

struct menudialogdef g_FrTrainingInfoInGameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_447, // "Training Info"
	g_FrTrainingInfoInGameMenuItems,
	frTrainingInfoMenuDialog,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_DISABLERESIZE | MENUDIALOGFLAG_0400,
	NULL,
};

struct menuitem g_FrTrainingInfoPreGameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_443,                             (u32)&frMenuTextDifficultyName,            NULL                   }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextGoalScoreLabel,            (u32)&frMenuTextGoalScoreValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextMinAccuracyOrTargetsLabel, (u32)&frMenuTextMinAccuracyOrTargetsValue, NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextTimeLimitLabel,            (u32)&frMenuTextTimeLimitValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextAmmoLimitLabel,            (u32)&frMenuTextAmmoLimitValue,            NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_FRWEAPON, 0x00004000, 0x0000010e,                                PAL ? 0x69 : 0x5f,                                NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_427,                             frDetailsOkMenuHandler }, // "", "Ok"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_429,                             frAbortMenuHandler    }, // "", "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
};

struct menudialogdef g_FrTrainingInfoPreGameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_447, // "Training Info"
	g_FrTrainingInfoPreGameMenuItems,
	frTrainingInfoMenuDialog,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_DISABLERESIZE | MENUDIALOGFLAG_0400,
	NULL,
};

struct menuitem g_FrCompletedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, L_MPMENU_449, 0x00000000, NULL }, // "Completed!"
#if VERSION < VERSION_NTSC_1_0
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_450, (u32)&frMenuTextScoreValue, NULL }, // "Score:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_451, (u32)&frMenuTextTargetsDestroyedValue, NULL }, // "Targets Destroyed:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_452, (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_453, (u32)&frMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_454, (u32)&frMenuTextWeaponName, NULL }, // "Weapon:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_455, (u32)&frMenuTextAccuracyValue, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x000000d2, 0x00000050, frScoringMenuHandler },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_252, 0x00000000, menuhandlerFrFailedContinue }, // "Continue"
#endif
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FrCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_448, // "Training Stats"
	g_FrCompletedMenuItems,
	frTrainingStatsMenuDialog,
#if VERSION >= VERSION_NTSC_1_0
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
#else
	0,
	&g_FrWeaponListMenuDialog,
#endif
};

struct menuitem g_FrFailedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&frMenuTextFailReason, 0x00000000, NULL },
#if VERSION < VERSION_NTSC_1_0
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_450, (u32)&frMenuTextScoreValue, NULL }, // "Score:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_451, (u32)&frMenuTextTargetsDestroyedValue, NULL }, // "Targets Destroyed:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_452, (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_453, (u32)&frMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_454, (u32)&frMenuTextWeaponName, NULL }, // "Weapon:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_455, (u32)&frMenuTextAccuracyValue, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x000000d2, 0x00000050, frScoringMenuHandler },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_252, 0x00000000, menuhandlerFrFailedContinue }, // "Continue"
#endif
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FrFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_448, // "Training Stats"
	g_FrFailedMenuItems,
	frTrainingStatsMenuDialog,
#if VERSION >= VERSION_NTSC_1_0
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
#else
	0,
	&g_FrWeaponListMenuDialog,
#endif
};

s32 ciOfficeInformationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct optiongroup groups[2] = {
		{ 0, L_MPMENU_421 }, // "Character Profiles"
		{ 0, L_MPMENU_422 }, // "Other Information"
	};

	s32 numunlockedchrbios = ciGetNumUnlockedChrBios();
	s32 numunlockedmiscbios = ciGetNumUnlockedMiscBios();
	struct chrbio *chrbio;
	struct miscbio *miscbio;

	groups[1].offset = numunlockedchrbios;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = numunlockedchrbios + numunlockedmiscbios;
		break;
	case MENUOP_GETOPTIONTEXT:
		if (data->list.value < numunlockedchrbios) {
			chrbio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(data->list.value));
			return (s32) langGet(chrbio->name);
		} else {
			miscbio = ciGetMiscBio(ciGetMiscBioIndexBySlot(data->list.value - numunlockedchrbios));
			return (s32) langGet(miscbio->name);
		}
		break;
	case MENUOP_SET:
		g_ChrBioSlot = data->list.value;
		if (g_ChrBioSlot < numunlockedchrbios) {
			menuPushDialog(&g_BioProfileMenuDialog);
		} else {
			menuPushDialog(&g_BioTextMenuDialog);
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = g_ChrBioSlot;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 2;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return (s32) langGet(groups[data->list.value].name);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = data->list.value == 0 ? 0 : numunlockedchrbios;
		break;
	}

	return 0;
}

struct menuitem g_BioListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000c8, 0x00000000, ciOfficeInformationMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_BioListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_418, // "Information"
	g_BioListMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_NowSafeMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, L_MPMENU_437, 0x00000000, NULL }, // "It is now safe to turn off your computer"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_438, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_NowSafeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_436, // "Cheats"
	g_NowSafeMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

s32 ciCharacterProfileMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	u32 bodynum = ciGetChrBioBodynumBySlot(g_ChrBioSlot);
	u32 mpbodynum = mpGetMpbodynumByBodynum(bodynum);
	u32 mpheadnum = mpGetMpheadnumByMpbodynum(mpbodynum);
	f32 x;
	f32 y;
	f32 scale;

	switch (operation) {
	case MENUOP_OPEN:
		if (bodynum == BODY_DRCAROLL) {
			scale = 0.7f;
			g_Menus[g_MpPlayerNum].unk840.unk554 = -1;
		} else {
			g_Menus[g_MpPlayerNum].unk840.unk554 = 30;
			scale = 1.0f;
		}

		g_Menus[g_MpPlayerNum].unk840.unk574 = TICKS(120);
		g_Menus[g_MpPlayerNum].unk840.unk580 = 0;

#if VERSION == VERSION_PAL_FINAL
		if (g_ViRes != VIRES_HI) {
			x = -117;

			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				x = -87;
			}
		} else {
			x = -177;

			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				x = -127;
			}
		}
#elif VERSION == VERSION_PAL_BETA
		x = -117;

		if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
			x = -87;
		}
#else
		x = -130;

		if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
			x = -100;
		}
#endif

		y = -15;

		if (bodynum == BODY_MRBLONDE) {
			y -= 12;
		}

		if (bodynum == BODY_THEKING) {
			scale = 0.8f;
		}

		func0f0f372c(&g_Menus[g_MpPlayerNum].unk840, x, y, 0, 0, 0, 0, scale, 7);

		g_Menus[g_MpPlayerNum].unk840.unk510 = 8.2f;
		g_Menus[g_MpPlayerNum].unk840.unk514 = -4.1f;
		g_Menus[g_MpPlayerNum].unk840.unk51c = 0.00393f;
		g_Menus[g_MpPlayerNum].unk840.unk524 = 0;
		g_Menus[g_MpPlayerNum].unk840.unk54c = 0;
		g_Menus[g_MpPlayerNum].unk840.unk578 = TICKS(60);
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (bodynum == BODY_DRCAROLL) {
			static struct modelpartvisibility vis[] = {
				{ MODELPART_DRCAROLL_0001, false },
				{ MODELPART_DRCAROLL_0002, false },
				{ MODELPART_DRCAROLL_0003, false },
				{ MODELPART_DRCAROLL_0004, false },
				{ MODELPART_DRCAROLL_0005, false },
				{ MODELPART_DRCAROLL_0007, false },
				{ MODELPART_DRCAROLL_0008, false },
				{ MODELPART_DRCAROLL_0009, false },
				{ MODELPART_DRCAROLL_000A, false },
				{ MODELPART_DRCAROLL_000B, false },
				{ 255 },
			};

			g_Menus[g_MpPlayerNum].unk840.partvisibility = vis;
			g_Menus[g_MpPlayerNum].unk840.unk05c = 318;
		} else {
			g_Menus[g_MpPlayerNum].unk840.unk05c = 106;
		}

		if (bodynum == BODY_THEKING) {
			static struct modelpartvisibility vis[] = {
				{ MODELPART_CHR_RIGHTHAND, false },
				{ 255 },
			};

			g_Menus[g_MpPlayerNum].unk840.partvisibility = vis;
		}

		g_Menus[g_MpPlayerNum].unk840.unk00c = 0xffff;
		g_Menus[g_MpPlayerNum].unk840.unk00c |= (mpheadnum << 16);
		g_Menus[g_MpPlayerNum].unk840.unk00c |= (mpbodynum << 24);

		if (g_Menus[g_MpPlayerNum].unk840.unk578 > 0) {
			g_Menus[g_MpPlayerNum].unk840.unk578 -= g_Vars.diffframe60;
		} else {
#if VERSION >= VERSION_PAL_BETA
			f32 tmp = g_Menus[g_MpPlayerNum].unk840.unk524 + 0.01f * g_Vars.diffframe60freal;
#else
			f32 tmp = g_Menus[g_MpPlayerNum].unk840.unk524 + 0.01f * g_Vars.diffframe60f;
#endif
			g_Menus[g_MpPlayerNum].unk840.unk54c = tmp;
			g_Menus[g_MpPlayerNum].unk840.unk524 = tmp;
		}

		break;
	}

	return 0;
}

char *ciMenuTextChrBioName(struct menuitem *item)
{
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(g_ChrBioSlot));
	sprintf(g_StringPointer, "%s\n", langGet(bio->name));

	return g_StringPointer;
}

char *ciMenuTextChrBioAge(struct menuitem *item)
{
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(g_ChrBioSlot));
	sprintf(g_StringPointer, "%s\n", langGet(bio->age));

	return g_StringPointer;
}

char *ciMenuTextChrBioRace(struct menuitem *item)
{
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(g_ChrBioSlot));
	sprintf(g_StringPointer, "%s\n", langGet(bio->race));

	return g_StringPointer;
}

char *ciMenuTextMiscBioName(struct menuitem *item)
{
	struct miscbio *bio = ciGetMiscBio(ciGetMiscBioIndexBySlot(g_ChrBioSlot - ciGetNumUnlockedChrBios()));

	sprintf(g_StringPointer, "%s\n", langGet(bio->name));

	return g_StringPointer;
}

s32 dtDeviceListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = dtGetNumAvailable();
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) bgunGetName(dtGetWeaponByDeviceIndex(dtGetIndexBySlot(data->list.value)));
	case MENUOP_SET:
		g_DtSlot = data->list.value;
		menuPushDialog(&g_DtDetailsMenuDialog);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = g_DtSlot;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 0;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return 0;
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = 0;
		break;
	}

	return 0;
}

char *dtMenuTextName(struct menuitem *item)
{
	u32 weaponnum = dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot));

	return bgunGetName(weaponnum);
}

s32 menuhandlerDtOkOrResume(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		// @bug: dtBegin() should not be called if training is already in
		// progress. Doing this resets the training timer.
		dtBegin();
		func0f0f8120();
	}

	return 0;
}

s32 menuhandler001a6514(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		dtEnd();
	}

	return 0;
}

struct menuitem g_BioProfileMenuItems[] = {
	{ MENUITEMTYPE_MODEL,      0,                  0x00000002, 0x00000046,    0x00000096,              NULL },
	{ MENUITEMTYPE_LABEL,      0,                  0x00000003, L_MPMENU_432, (u32)&ciMenuTextChrBioName, NULL }, // "Name:"
	{ MENUITEMTYPE_LABEL,      0,                  0x00000002, L_MPMENU_433, (u32)&ciMenuTextChrBioAge,  NULL }, // "Age:"
	{ MENUITEMTYPE_LABEL,      0,                  0x00000002, L_MPMENU_434, (u32)&ciMenuTextChrBioRace, NULL }, // "Race:"
	{ MENUITEMTYPE_SEPARATOR,  0,                  0x00000002, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_CHRBIO, 0x00000000, 0x000000b4,    0x00000064,              NULL },
	{ MENUITEMTYPE_SEPARATOR,  0,                  0x00000002, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_LABEL,      0,                  0x00000022, L_MPMENU_435, 0x00000000,              NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,        0,                  0x00000000, 0x00000000,    0x00000000,              NULL },
};

struct menudialogdef g_BioProfileMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_431, // "Character Profile"
	g_BioProfileMenuItems,
	ciCharacterProfileMenuDialog,
	MENUDIALOGFLAG_0002,
	NULL,
};

struct menuitem g_BioTextMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MISCBIO, 0x00000000, 0x000000c8,    0x00000096, NULL },
	{ MENUITEMTYPE_SEPARATOR,  0,                   0x00000002, 0x00000000,    0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,      0,                   0x00000022, L_MPMENU_414, 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,        0,                   0x00000000, 0x00000000,    0x00000000, NULL },
};

struct menudialogdef g_BioTextMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&ciMenuTextMiscBioName,
	g_BioTextMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

struct menuitem g_DtListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000a0, 0x00000000, dtDeviceListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_DtListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_417, // "Device List"
	g_DtListMenuItems,
	NULL,
	0,
	NULL,
};

s32 dtTrainingDetailsMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		{
			s32 weaponnum = dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot));
			u16 unused[] = {64250, 38500, 25650, 25700, 12950};
			func0f1a1ac0();
			g_Menus[g_MpPlayerNum].training.weaponnum = weaponnum;
			func0f105948(weaponnum);

#if VERSION == VERSION_PAL_FINAL
			if (g_ViRes == VIRES_HI) {
				if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
					g_Menus[g_MpPlayerNum].unk840.unk538 = 84;
					g_Menus[g_MpPlayerNum].unk840.unk510 = 84;
				} else {
					g_Menus[g_MpPlayerNum].unk840.unk538 = 104;
					g_Menus[g_MpPlayerNum].unk840.unk510 = 104;
				}
			} else {
				if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
					g_Menus[g_MpPlayerNum].unk840.unk538 = 64;
					g_Menus[g_MpPlayerNum].unk840.unk510 = 64;
				} else {
					g_Menus[g_MpPlayerNum].unk840.unk538 = 84;
					g_Menus[g_MpPlayerNum].unk840.unk510 = 84;
				}
			}
#elif VERSION == VERSION_PAL_BETA
			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				g_Menus[g_MpPlayerNum].unk840.unk538 = 64;
				g_Menus[g_MpPlayerNum].unk840.unk510 = 64;
			} else {
				g_Menus[g_MpPlayerNum].unk840.unk538 = 84;
				g_Menus[g_MpPlayerNum].unk840.unk510 = 84;
			}
#else
			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				g_Menus[g_MpPlayerNum].unk840.unk538 = 70;
				g_Menus[g_MpPlayerNum].unk840.unk510 = 70;
			} else {
				g_Menus[g_MpPlayerNum].unk840.unk538 = 90;
				g_Menus[g_MpPlayerNum].unk840.unk510 = 90;
			}
#endif

			g_Menus[g_MpPlayerNum].unk840.unk544 /= 2.5f;
		}
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curdialog && g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef) {
			s32 weaponnum = dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot));

			if (weaponnum == WEAPON_DISGUISE41) {
				g_Menus[g_MpPlayerNum].unk840.unk05c = ANIM_006A;
				g_Menus[g_MpPlayerNum].unk840.unk578 = TICKS(60);
				g_Menus[g_MpPlayerNum].unk840.unk574 = TICKS(120);
			}

			g_Menus[g_MpPlayerNum].unk840.unk54c = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unk840.unk524 = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unk840.unk550 = 0;
			g_Menus[g_MpPlayerNum].unk840.unk528 = 0;
		}
		break;
	}

	return 0;
}

char *dtMenuTextOkOrResume(struct menuitem *item)
{
	struct trainingdata *data = dtGetData();

	if (data->intraining) {
		return langGet(L_MPMENU_428); // "Resume"
	}

	return langGet(L_MPMENU_427); // "Ok"
}

char *dtMenuTextCancelOrAbort(struct menuitem *item)
{
	struct trainingdata *data = dtGetData();

	if (data->intraining) {
		return langGet(L_MPMENU_430); // "Abort"
	}

	return langGet(L_MPMENU_429); // "Cancel"
}

char *dtMenuTextTimeTakenValue(struct menuitem *item)
{
	struct trainingdata *data = dtGetData();
	f32 secs = data->timetaken / (PAL ? 50.0f : 60.0f);

	if (secs >= 60.0f) {
		s32 mins = 0;

		while (secs >= 60.0f) {
			secs -= 60.0f;
			mins++;
		}

		sprintf(g_StringPointer, "%dm %2ds\n", mins, (s32)ceilf(secs));
		return g_StringPointer;
	} else {
		sprintf(g_StringPointer, "%s%s%2.2fs\n", "", "", secs);
	}

	return g_StringPointer;
}

s32 menudialogDeviceTrainingResults(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		chrSetStageFlag(NULL, 0x08000000);
	}

	return false;
}

s32 htHoloListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = htGetNumUnlocked();
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) htGetName(htGetIndexBySlot(data->list.value));
	case MENUOP_SET:
		var80088bb4 = data->list.value;
		menuPushDialog(&g_HtDetailsMenuDialog);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = var80088bb4;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 0;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return 0;
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = 0;
		break;
	}

	return 0;
}

char *htMenuTextName(struct menuitem *item)
{
	return htGetName(htGetIndexBySlot(var80088bb4));
}

s32 menuhandler001a6a34(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		htBegin();
		func0f0f8120();
	}

	return 0;
}

s32 menuhandler001a6a70(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		htEnd();
	}

	return 0;
}

s32 menudialog001a6aa4(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		func0f1a2198();
		break;
	case MENUOP_CLOSE:
		break;
	}

	return false;
}

char *htMenuTextOkOrResume(struct menuitem *item)
{
	struct trainingdata *data = getHoloTrainingData();

	if (data->intraining) {
		return langGet(L_MPMENU_428); // "Resume"
	}

	return langGet(L_MPMENU_427); // "Ok"
}

char *htMenuTextCancelOrAbort(struct menuitem *item)
{
	struct trainingdata *data = getHoloTrainingData();

	if (data->intraining) {
		return langGet(L_MPMENU_430); // "Abort"
	}

	return langGet(L_MPMENU_429); // "Cancel"
}

char *htMenuTextTimeTakenValue(struct menuitem *item)
{
	struct trainingdata *data = getHoloTrainingData();
	f32 secs = data->timetaken / (PAL ? 50.0f : 60.0f);

	if (secs >= 60.0f) {
		s32 mins = 0;

		while (secs >= 60.0f) {
			secs -= 60.0f;
			mins++;
		}

		sprintf(g_StringPointer, "%dm %2ds\n", mins, (s32)ceilf(secs));
		return g_StringPointer;
	} else {
		sprintf(g_StringPointer, "%s%s%2.2fs\n", "", "", secs);
	}

	return g_StringPointer;
}

s32 menudialogFiringRangeResults(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		chrSetStageFlag(NULL, 0x08000000);
	}

	return false;
}

char *bioMenuTextName(struct menuitem *item)
{
	struct hangarbio *bio = ciGetHangarBio(ciGetHangarBioIndexBySlot(g_HangarBioSlot));

	return langGet(bio->name);
}

/**
 * The subheading is stored in the same string as the name, separated by a pipe.
 * eg. "Lucerne Tower\0|Global headquarters\n"
 */
char *ciMenuTextHangarBioSubheading(struct menuitem *item)
{
	s32 index = 0;
	struct hangarbio *bio = ciGetHangarBio(ciGetHangarBioIndexBySlot(g_HangarBioSlot));
	char *name = langGet(bio->name);

	while (name[index] != '|') {
		index++;
	}

	sprintf(g_StringPointer, "%s\n", &name[index + 1]);

	return g_StringPointer;
}

struct menuitem g_DtDetailsMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_DEVICETRAINING, 0x00000000, 0x000000aa,                    PAL ? 0xd6 : 0xbe, NULL                    },
	{ MENUITEMTYPE_MODEL,      0,                          0x00000003, 0x0000008c,                    PAL ? 0xb4 : 0x9c, NULL                    },
	{ MENUITEMTYPE_SEPARATOR,  0,                          0x00000002, 0x00000000,                    0x00000000, NULL                    },
	{ MENUITEMTYPE_SELECTABLE, 0,                          0x00000008, (u32)&dtMenuTextOkOrResume,    0x00000000, menuhandlerDtOkOrResume },
	{ MENUITEMTYPE_SELECTABLE, 0,                          0x00000008, (u32)&dtMenuTextCancelOrAbort, 0x00000000, menuhandler001a6514     },
	{ MENUITEMTYPE_END,        0,                          0x00000000, 0x00000000,                    0x00000000, NULL                    },
};

struct menudialogdef g_DtDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&dtMenuTextName,
	g_DtDetailsMenuItems,
	dtTrainingDetailsMenuDialog,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_STARTSELECTS | MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

struct menuitem g_DtFailedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                      0x00000032, L_MPMENU_426, 0x00000000,                     NULL }, // "Failed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                      0x00000002, L_MPMENU_424, (u32)&dtMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_DEVICETIP1, 0x00000000, 0x00000082,    PAL ? 110 : 100,                     NULL },
	{ MENUITEMTYPE_END,        0,                      0x00000000, 0x00000000,    0x00000000,                     NULL },
};

struct menudialogdef g_DtFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_423, // "Training Stats"
	g_DtFailedMenuItems,
	menudialogDeviceTrainingResults,
	MENUDIALOGFLAG_DISABLERESIZE,
	&g_DtListMenuDialog,
};

struct menuitem g_DtCompletedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                      0x00000032, L_MPMENU_425, 0x00000000,                     NULL }, // "Completed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                      0x00000002, L_MPMENU_424, (u32)&dtMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_DEVICETIP2, 0x00000000, 0x00000082,    PAL ? 110 : 100,                     NULL },
	{ MENUITEMTYPE_END,        0,                      0x00000000, 0x00000000,    0x00000000,                     NULL },
};

struct menudialogdef g_DtCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_423, // "Training Stats"
	g_DtCompletedMenuItems,
	menudialogDeviceTrainingResults,
	MENUDIALOGFLAG_DISABLERESIZE,
	&g_DtListMenuDialog,
};

struct menuitem g_HtListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000a0, 0x00000000, htHoloListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_HtListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_416, // "Holotraining"
	g_HtListMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_HtDetailsMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTRAINING, 0x00000000, 0x000000aa,                    0x000000be, NULL                },
	{ MENUITEMTYPE_MODEL,      0,                        0x00000003, 0x0000008c,                    0x0000009c, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                        0x00000002, 0x00000000,                    0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                        0x00000008, (u32)&htMenuTextOkOrResume,    0x00000000, menuhandler001a6a34 },
	{ MENUITEMTYPE_SELECTABLE, 0,                        0x00000008, (u32)&htMenuTextCancelOrAbort, 0x00000000, menuhandler001a6a70 },
	{ MENUITEMTYPE_END,        0,                        0x00000000, 0x00000000,                    0x00000000, NULL                },
};

struct menudialogdef g_HtDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&htMenuTextName,
	g_HtDetailsMenuItems,
	menudialog001a6aa4,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_STARTSELECTS | MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

struct menuitem g_HtFailedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000032, L_MPMENU_426, 0x00000000,                     NULL }, // "Failed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,   0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_424, (u32)&htMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,   0x00000000,                     NULL },
#if VERSION >= VERSION_JPN_FINAL
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP1, 0x00000000, 0x00000082,   120,                     NULL },
#elif PAL
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP1, 0x00000000, 0x00000082,   110,                     NULL },
#else
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP1, 0x00000000, 0x00000082,   100,                     NULL },
#endif
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000,                     NULL },
};

struct menudialogdef g_HtFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_423, // "Training Stats"
	g_HtFailedMenuItems,
	menudialogFiringRangeResults,
	MENUDIALOGFLAG_DISABLERESIZE,
	&g_HtListMenuDialog,
};

struct menuitem g_HtCompletedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000032, L_MPMENU_425, 0x00000000,                     NULL }, // "Completed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,   0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_424, (u32)&htMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,   0x00000000,                     NULL },
#if VERSION >= VERSION_JPN_FINAL
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP2, 0x00000000, 0x00000082,   120,                     NULL },
#elif PAL
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP2, 0x00000000, 0x00000082,   110,                     NULL },
#else
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP2, 0x00000000, 0x00000082,   100,                     NULL },
#endif
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000,                     NULL },
};

struct menudialogdef g_HtCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_423, // "Training Stats"
	g_HtCompletedMenuItems,
	menudialogFiringRangeResults,
	MENUDIALOGFLAG_DISABLERESIZE,
	&g_HtListMenuDialog,
};

s32 ciHangarInformationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct optiongroup groups[2] = {
		{ 0, L_MPMENU_419 }, // "Locations"
		{ 0, L_MPMENU_420 }, // "Vehicles"
	};

	s32 bioindex;
	struct hangarbio *bio;

	groups[1].offset = ciGetNumUnlockedLocationBios();

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = ciGetNumUnlockedHangarBios();
		break;
	case MENUOP_GETOPTIONTEXT:
		bio = ciGetHangarBio(ciGetHangarBioIndexBySlot(data->list.value));
		return (s32) langGet(bio->name);
	case MENUOP_SET:
		g_HangarBioSlot = data->list.value;
		bioindex = ciGetHangarBioIndexBySlot(g_HangarBioSlot);

		if (bioindex <= HANGARBIO_SKEDARRUINS) {
			menuPushDialog(&g_HangarLocationDetailsMenuDialog);
		} else {
			menuPushDialog(&g_HangarVehicleDetailsMenuDialog);
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = g_HangarBioSlot;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 2;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return (s32) langGet(groups[data->list.value].name);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = data->list.value == 0 ? 0 : groups[1].offset;
		break;
	}

	return 0;
}

s32 ciHangarTitleMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_RENDER) {
		Gfx *gdl = data->type19.gdl;
		struct menuitemrenderdata *renderdata = data->type19.renderdata2;
		s32 textwidth;
		s32 textheight;
		s32 leftmargin;
		char *text;
		s32 index = ciGetHangarBioIndexBySlot(g_HangarBioSlot);

		if (index < 14) {
			// Location bio - render texture
			u8 texturenums[] = { 0x1b, 0x0d, 0x0e, 0x10, 0x11, 0x12, 0x13, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1c, 0x1d };
			s32 texturenum = texturenums[index];

			gDPPipeSync(gdl++);
			gDPSetTexturePersp(gdl++, G_TP_NONE);
			gDPSetAlphaCompare(gdl++, G_AC_NONE);
			gDPSetTextureLOD(gdl++, G_TL_TILE);
			gDPSetTextureConvert(gdl++, G_TC_FILT);

			texSelect(&gdl, &g_TexGeneralConfigs[texturenum], 1, 0, 2, 1, NULL);

			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
			gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
			gDPSetTextureFilter(gdl++, G_TF_POINT);

#if VERSION >= VERSION_NTSC_1_0
			gDPSetEnvColorViaWord(gdl++, 0xffffff00 | ((renderdata->colour & 0xff) * 255) >> 8);
#endif

			gSPTextureRectangle(gdl++,
					((renderdata->x + 6) << 2) * g_ScaleX, (renderdata->y + 3) << 2,
					((renderdata->x + 60) << 2) * g_ScaleX, (renderdata->y + 39) << 2,
					G_TX_RENDERTILE, 0, 0x0480, 1024 / g_ScaleX, -1024);

			leftmargin = -1;
		} else {
			// Vehicle bio
			leftmargin = item->param2 / 2;
		}

		gdl = text0f153628(gdl);

		// Render title
		text = bioMenuTextName(NULL);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicMd, g_FontHandelGothicMd, 0);

		if (leftmargin == -1) {
			textwidth = renderdata->x + 64;
		} else {
			textwidth = (renderdata->x + leftmargin) - (textwidth >> 1);
		}

		textheight = renderdata->y + 8;
		gdl = textRenderProjected(gdl, &textwidth, &textheight, text, g_CharsHandelGothicMd, g_FontHandelGothicMd, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);

		// Render subheading
		text = ciMenuTextHangarBioSubheading(NULL);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		if (leftmargin == -1) {
			textwidth = renderdata->x + 64;
		} else {
			textwidth = (renderdata->x + leftmargin) - (textwidth >> 1);
		}

		textheight = renderdata->y + 25;
		gdl = textRenderProjected(gdl, &textwidth, &textheight, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);

		gdl = text0f153780(gdl);

		return (s32)gdl;
	}

	return 0;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel ciHangarHolographMenuDialog
.late_rodata
glabel var7f1b99d4
.word 0x3a83126f
glabel var7f1b99d8
.word 0x3c23d70a
.text
/*  f1a7eb4:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a7eb8:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f1a7ebc:	00803025 */ 	move	$a2,$a0
/*  f1a7ec0:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f1a7ec4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a7ec8:	3c048009 */ 	lui	$a0,0x8009
/*  f1a7ecc:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a7ed0:	90848fd4 */ 	lbu	$a0,-0x702c($a0)
/*  f1a7ed4:	0fc68836 */ 	jal	ciGetHangarBioIndexBySlot
/*  f1a7ed8:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1a7edc:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a7ee0:	14200076 */ 	bnez	$at,.JF0f1a80bc
/*  f1a7ee4:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f1a7ee8:	3c0e8009 */ 	lui	$t6,0x8009
/*  f1a7eec:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f1a7ef0:	25ce9e3c */ 	addiu	$t6,$t6,-25028
/*  f1a7ef4:	25d8006c */ 	addiu	$t8,$t6,0x6c
/*  f1a7ef8:	00e0c825 */ 	move	$t9,$a3
.JF0f1a7efc:
/*  f1a7efc:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a7f00:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a7f04:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f1a7f08:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f1a7f0c:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a7f10:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f1a7f14:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a7f18:	15d8fff8 */ 	bne	$t6,$t8,.JF0f1a7efc
/*  f1a7f1c:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f1a7f20:	24010064 */ 	li	$at,0x64
/*  f1a7f24:	10c10008 */ 	beq	$a2,$at,.JF0f1a7f48
/*  f1a7f28:	3c088007 */ 	lui	$t0,0x8007
/*  f1a7f2c:	24010065 */ 	li	$at,0x65
/*  f1a7f30:	10c10062 */ 	beq	$a2,$at,.JF0f1a80bc
/*  f1a7f34:	24010066 */ 	li	$at,0x66
/*  f1a7f38:	10c10019 */ 	beq	$a2,$at,.JF0f1a7fa0
/*  f1a7f3c:	00000000 */ 	nop
/*  f1a7f40:	1000005f */ 	b	.JF0f1a80c0
/*  f1a7f44:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f1a7f48:
/*  f1a7f48:	8d081998 */ 	lw	$t0,0x1998($t0)
/*  f1a7f4c:	44800000 */ 	mtc1	$zero,$f0
/*  f1a7f50:	3c0a800a */ 	lui	$t2,0x800a
/*  f1a7f54:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a7f58:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7f5c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a7f60:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1a7f64:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a7f68:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7f6c:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a7f70:	254ae700 */ 	addiu	$t2,$t2,-6400
/*  f1a7f74:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f1a7f78:	e4600d88 */ 	swc1	$f0,0xd88($v1)
/*  f1a7f7c:	e4600d60 */ 	swc1	$f0,0xd60($v1)
/*  f1a7f80:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a7f84:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a7f88:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f1a7f8c:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f1a7f90:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a7f94:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7f98:	10000048 */ 	b	.JF0f1a80bc
/*  f1a7f9c:	e4600d5c */ 	swc1	$f0,0xd5c($v1)
.JF0f1a7fa0:
/*  f1a7fa0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1a7fa4:	8d6b1998 */ 	lw	$t3,0x1998($t3)
/*  f1a7fa8:	3c0d800a */ 	lui	$t5,0x800a
/*  f1a7fac:	25ade700 */ 	addiu	$t5,$t5,-6400
/*  f1a7fb0:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1a7fb4:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7fb8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1a7fbc:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1a7fc0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1a7fc4:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7fc8:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f1a7fcc:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f1a7fd0:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f1a7fd4:	5080003a */ 	beqzl	$a0,.JF0f1a80c0
/*  f1a7fd8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a7fdc:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f1a7fe0:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f1a7fe4:	2445fff2 */ 	addiu	$a1,$v0,-14
/*  f1a7fe8:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1a7fec:	15f80027 */ 	bne	$t7,$t8,.JF0f1a808c
/*  f1a7ff0:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f1a7ff4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a7ff8:	00ee2021 */ 	addu	$a0,$a3,$t6
/*  f1a7ffc:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f1a8000:	94880008 */ 	lhu	$t0,0x8($a0)
/*  f1a8004:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a8008:	44992000 */ 	mtc1	$t9,$f4
/*  f1a800c:	44883000 */ 	mtc1	$t0,$f6
/*  f1a8010:	240a0008 */ 	li	$t2,0x8
/*  f1a8014:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1a8018:	05010004 */ 	bgez	$t0,.JF0f1a802c
/*  f1a801c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1a8020:	44815000 */ 	mtc1	$at,$f10
/*  f1a8024:	00000000 */ 	nop
/*  f1a8028:	460a4200 */ 	add.s	$f8,$f8,$f10
.JF0f1a802c:
/*  f1a802c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1a8030:	c430a944 */ 	lwc1	$f16,-0x56bc($at)
/*  f1a8034:	8c860000 */ 	lw	$a2,0x0($a0)
/*  f1a8038:	8c69084c */ 	lw	$t1,0x84c($v1)
/*  f1a803c:	46104082 */ 	mul.s	$f2,$f8,$f16
/*  f1a8040:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a8044:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a8048:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1a804c:	11260002 */ 	beq	$t1,$a2,.JF0f1a8058
/*  f1a8050:	e4620d84 */ 	swc1	$f2,0xd84($v1)
/*  f1a8054:	a06a0840 */ 	sb	$t2,0x840($v1)
.JF0f1a8058:
/*  f1a8058:	ac66084c */ 	sw	$a2,0x84c($v1)
/*  f1a805c:	c432a948 */ 	lwc1	$f18,-0x56b8($at)
/*  f1a8060:	3c01800a */ 	lui	$at,0x800a
/*  f1a8064:	c424a640 */ 	lwc1	$f4,-0x59c0($at)
/*  f1a8068:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f1a806c:	3c0b8009 */ 	lui	$t3,0x8009
/*  f1a8070:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f1a8074:	256b9e34 */ 	addiu	$t3,$t3,-25036
/*  f1a8078:	ac6b0df4 */ 	sw	$t3,0xdf4($v1)
/*  f1a807c:	46065000 */ 	add.s	$f0,$f10,$f6
/*  f1a8080:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a8084:	1000000d */ 	b	.JF0f1a80bc
/*  f1a8088:	e4600d64 */ 	swc1	$f0,0xd64($v1)
.JF0f1a808c:
/*  f1a808c:	44800000 */ 	mtc1	$zero,$f0
/*  f1a8090:	00000000 */ 	nop
/*  f1a8094:	e4600d88 */ 	swc1	$f0,0xd88($v1)
/*  f1a8098:	e4600d60 */ 	swc1	$f0,0xd60($v1)
/*  f1a809c:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a80a0:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a80a4:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f1a80a8:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f1a80ac:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a80b0:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a80b4:	e4600d84 */ 	swc1	$f0,0xd84($v1)
/*  f1a80b8:	e4600d5c */ 	swc1	$f0,0xd5c($v1)
.JF0f1a80bc:
/*  f1a80bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f1a80c0:
/*  f1a80c0:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f1a80c4:	00001025 */ 	move	$v0,$zero
/*  f1a80c8:	03e00008 */ 	jr	$ra
/*  f1a80cc:	00000000 */ 	nop
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel ciHangarHolographMenuDialog
.late_rodata
glabel var7f1b99d4
.word 0x3a83126f
glabel var7f1b99d8
.word 0x3c23d70a
.text
/*  f1a737c:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a7380:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f1a7384:	00803025 */ 	or	$a2,$a0,$zero
/*  f1a7388:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f1a738c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a7390:	3c048009 */ 	lui	$a0,%hi(g_HangarBioSlot)
/*  f1a7394:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a7398:	90848964 */ 	lbu	$a0,%lo(g_HangarBioSlot)($a0)
/*  f1a739c:	0fc685db */ 	jal	ciGetHangarBioIndexBySlot
/*  f1a73a0:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1a73a4:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a73a8:	14200065 */ 	bnez	$at,.L0f1a7540
/*  f1a73ac:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f1a73b0:	3c0e8009 */ 	lui	$t6,%hi(hoverprops)
/*  f1a73b4:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f1a73b8:	25ce97cc */ 	addiu	$t6,$t6,%lo(hoverprops)
/*  f1a73bc:	25d8006c */ 	addiu	$t8,$t6,0x6c
/*  f1a73c0:	00e0c825 */ 	or	$t9,$a3,$zero
.L0f1a73c4:
/*  f1a73c4:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a73c8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a73cc:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f1a73d0:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f1a73d4:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a73d8:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f1a73dc:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a73e0:	15d8fff8 */ 	bne	$t6,$t8,.L0f1a73c4
/*  f1a73e4:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f1a73e8:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1a73ec:	10c10008 */ 	beq	$a2,$at,.L0f1a7410
/*  f1a73f0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f1a73f4:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a73f8:	10c10051 */ 	beq	$a2,$at,.L0f1a7540
/*  f1a73fc:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a7400:	10c10019 */ 	beq	$a2,$at,.L0f1a7468
/*  f1a7404:	00000000 */ 	nop
/*  f1a7408:	1000004e */ 	b	.L0f1a7544
/*  f1a740c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7410:
/*  f1a7410:	8d081448 */ 	lw	$t0,%lo(g_MpPlayerNum)($t0)
/*  f1a7414:	44800000 */ 	mtc1	$zero,$f0
/*  f1a7418:	3c0a800a */ 	lui	$t2,%hi(g_Menus)
/*  f1a741c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a7420:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7424:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a7428:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1a742c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a7430:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7434:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a7438:	254ae000 */ 	addiu	$t2,$t2,%lo(g_Menus)
/*  f1a743c:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f1a7440:	e4600d88 */ 	swc1	$f0,0xd88($v1)
/*  f1a7444:	e4600d60 */ 	swc1	$f0,0xd60($v1)
/*  f1a7448:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a744c:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a7450:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f1a7454:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f1a7458:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a745c:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7460:	10000037 */ 	b	.L0f1a7540
/*  f1a7464:	e4600d5c */ 	swc1	$f0,0xd5c($v1)
.L0f1a7468:
/*  f1a7468:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f1a746c:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f1a7470:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f1a7474:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f1a7478:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1a747c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7480:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1a7484:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1a7488:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1a748c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7490:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f1a7494:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f1a7498:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f1a749c:	50800029 */ 	beqzl	$a0,.L0f1a7544
/*  f1a74a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a74a4:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f1a74a8:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f1a74ac:	2445fff2 */ 	addiu	$a1,$v0,-14
/*  f1a74b0:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1a74b4:	15f80022 */ 	bne	$t7,$t8,.L0f1a7540
/*  f1a74b8:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f1a74bc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a74c0:	00ee2021 */ 	addu	$a0,$a3,$t6
/*  f1a74c4:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f1a74c8:	94880008 */ 	lhu	$t0,0x8($a0)
/*  f1a74cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a74d0:	44992000 */ 	mtc1	$t9,$f4
/*  f1a74d4:	44883000 */ 	mtc1	$t0,$f6
/*  f1a74d8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1a74dc:	05010004 */ 	bgez	$t0,.L0f1a74f0
/*  f1a74e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1a74e4:	44815000 */ 	mtc1	$at,$f10
/*  f1a74e8:	00000000 */ 	nop
/*  f1a74ec:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1a74f0:
/*  f1a74f0:	3c017f1c */ 	lui	$at,%hi(var7f1b99d4)
/*  f1a74f4:	c43099d4 */ 	lwc1	$f16,%lo(var7f1b99d4)($at)
/*  f1a74f8:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f1a74fc:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7500:	46104302 */ 	mul.s	$f12,$f8,$f16
/*  f1a7504:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a7508:	3c017f1c */ 	lui	$at,%hi(var7f1b99d8)
/*  f1a750c:	ac69084c */ 	sw	$t1,0x84c($v1)
/*  f1a7510:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f1a7514:	3c0a8009 */ 	lui	$t2,%hi(var800897c4)
/*  f1a7518:	254a97c4 */ 	addiu	$t2,$t2,%lo(var800897c4)
/*  f1a751c:	e46c0d84 */ 	swc1	$f12,0xd84($v1)
/*  f1a7520:	c43299d8 */ 	lwc1	$f18,%lo(var7f1b99d8)($at)
/*  f1a7524:	3c01800a */ 	lui	$at,%hi(g_Vars+0x10)
/*  f1a7528:	c4249fc4 */ 	lwc1	$f4,%lo(g_Vars+0x10)($at)
/*  f1a752c:	ac6a0df4 */ 	sw	$t2,0xdf4($v1)
/*  f1a7530:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f1a7534:	46065080 */ 	add.s	$f2,$f10,$f6
/*  f1a7538:	e4620d8c */ 	swc1	$f2,0xd8c($v1)
/*  f1a753c:	e4620d64 */ 	swc1	$f2,0xd64($v1)
.L0f1a7540:
/*  f1a7540:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7544:
/*  f1a7544:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f1a7548:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a754c:	03e00008 */ 	jr	$ra
/*  f1a7550:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel ciHangarHolographMenuDialog
.late_rodata
glabel var7f1b99d4
.word 0x3a83126f
glabel var7f1b99d8
.word 0x3c23d70a
.text
/*  f1a737c:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a7380:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f1a7384:	00803025 */ 	or	$a2,$a0,$zero
/*  f1a7388:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f1a738c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a7390:	3c048009 */ 	lui	$a0,%hi(g_HangarBioSlot)
/*  f1a7394:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a7398:	90848964 */ 	lbu	$a0,%lo(g_HangarBioSlot)($a0)
/*  f1a739c:	0fc685db */ 	jal	ciGetHangarBioIndexBySlot
/*  f1a73a0:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1a73a4:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a73a8:	14200065 */ 	bnez	$at,.L0f1a7540
/*  f1a73ac:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f1a73b0:	3c0e8009 */ 	lui	$t6,%hi(hoverprops)
/*  f1a73b4:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f1a73b8:	25ce97cc */ 	addiu	$t6,$t6,%lo(hoverprops)
/*  f1a73bc:	25d8006c */ 	addiu	$t8,$t6,0x6c
/*  f1a73c0:	00e0c825 */ 	or	$t9,$a3,$zero
.L0f1a73c4:
/*  f1a73c4:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a73c8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a73cc:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f1a73d0:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f1a73d4:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a73d8:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f1a73dc:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a73e0:	15d8fff8 */ 	bne	$t6,$t8,.L0f1a73c4
/*  f1a73e4:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f1a73e8:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1a73ec:	10c10008 */ 	beq	$a2,$at,.L0f1a7410
/*  f1a73f0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f1a73f4:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a73f8:	10c10051 */ 	beq	$a2,$at,.L0f1a7540
/*  f1a73fc:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a7400:	10c10019 */ 	beq	$a2,$at,.L0f1a7468
/*  f1a7404:	00000000 */ 	nop
/*  f1a7408:	1000004e */ 	b	.L0f1a7544
/*  f1a740c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7410:
/*  f1a7410:	8d081448 */ 	lw	$t0,%lo(g_MpPlayerNum)($t0)
/*  f1a7414:	44800000 */ 	mtc1	$zero,$f0
/*  f1a7418:	3c0a800a */ 	lui	$t2,%hi(g_Menus)
/*  f1a741c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a7420:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7424:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a7428:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1a742c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a7430:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7434:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a7438:	254ae000 */ 	addiu	$t2,$t2,%lo(g_Menus)
/*  f1a743c:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f1a7440:	e4600d88 */ 	swc1	$f0,0xd88($v1)
/*  f1a7444:	e4600d60 */ 	swc1	$f0,0xd60($v1)
/*  f1a7448:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a744c:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a7450:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f1a7454:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f1a7458:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a745c:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7460:	10000037 */ 	b	.L0f1a7540
/*  f1a7464:	e4600d5c */ 	swc1	$f0,0xd5c($v1)
.L0f1a7468:
/*  f1a7468:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f1a746c:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f1a7470:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f1a7474:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f1a7478:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1a747c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7480:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1a7484:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1a7488:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1a748c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7490:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f1a7494:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f1a7498:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f1a749c:	50800029 */ 	beqzl	$a0,.L0f1a7544
/*  f1a74a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a74a4:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f1a74a8:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f1a74ac:	2445fff2 */ 	addiu	$a1,$v0,-14
/*  f1a74b0:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1a74b4:	15f80022 */ 	bne	$t7,$t8,.L0f1a7540
/*  f1a74b8:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f1a74bc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a74c0:	00ee2021 */ 	addu	$a0,$a3,$t6
/*  f1a74c4:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f1a74c8:	94880008 */ 	lhu	$t0,0x8($a0)
/*  f1a74cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a74d0:	44992000 */ 	mtc1	$t9,$f4
/*  f1a74d4:	44883000 */ 	mtc1	$t0,$f6
/*  f1a74d8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1a74dc:	05010004 */ 	bgez	$t0,.L0f1a74f0
/*  f1a74e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1a74e4:	44815000 */ 	mtc1	$at,$f10
/*  f1a74e8:	00000000 */ 	nop
/*  f1a74ec:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1a74f0:
/*  f1a74f0:	3c017f1c */ 	lui	$at,%hi(var7f1b99d4)
/*  f1a74f4:	c43099d4 */ 	lwc1	$f16,%lo(var7f1b99d4)($at)
/*  f1a74f8:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f1a74fc:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7500:	46104302 */ 	mul.s	$f12,$f8,$f16
/*  f1a7504:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a7508:	3c017f1c */ 	lui	$at,%hi(var7f1b99d8)
/*  f1a750c:	ac69084c */ 	sw	$t1,0x84c($v1)
/*  f1a7510:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f1a7514:	3c0a8009 */ 	lui	$t2,%hi(var800897c4)
/*  f1a7518:	254a97c4 */ 	addiu	$t2,$t2,%lo(var800897c4)
/*  f1a751c:	e46c0d84 */ 	swc1	$f12,0xd84($v1)
/*  f1a7520:	c43299d8 */ 	lwc1	$f18,%lo(var7f1b99d8)($at)
/*  f1a7524:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4)
/*  f1a7528:	c4249fc4 */ 	lwc1	$f4,%lo(g_Vars+0x4)($at)
/*  f1a752c:	ac6a0df4 */ 	sw	$t2,0xdf4($v1)
/*  f1a7530:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f1a7534:	46065080 */ 	add.s	$f2,$f10,$f6
/*  f1a7538:	e4620d8c */ 	swc1	$f2,0xd8c($v1)
/*  f1a753c:	e4620d64 */ 	swc1	$f2,0xd64($v1)
.L0f1a7540:
/*  f1a7540:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7544:
/*  f1a7544:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f1a7548:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a754c:	03e00008 */ 	jr	$ra
/*  f1a7550:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel ciHangarHolographMenuDialog
.late_rodata
glabel var7f1b99d4
.word 0x3a83126f
glabel var7f1b99d8
.word 0x3c23d70a
.text
/*  f1a1360:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a1364:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f1a1368:	00803025 */ 	or	$a2,$a0,$zero
/*  f1a136c:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f1a1370:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1374:	3c048009 */ 	lui	$a0,0x8009
/*  f1a1378:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a137c:	9084b0d4 */ 	lbu	$a0,-0x4f2c($a0)
/*  f1a1380:	0fc66ddf */ 	jal	ciGetHangarBioIndexBySlot
/*  f1a1384:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1a1388:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a138c:	14200065 */ 	bnez	$at,.NB0f1a1524
/*  f1a1390:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f1a1394:	3c0e8009 */ 	lui	$t6,0x8009
/*  f1a1398:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f1a139c:	25cebf3c */ 	addiu	$t6,$t6,-16580
/*  f1a13a0:	25d8006c */ 	addiu	$t8,$t6,0x6c
/*  f1a13a4:	00e0c825 */ 	or	$t9,$a3,$zero
.NB0f1a13a8:
/*  f1a13a8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a13ac:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a13b0:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f1a13b4:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f1a13b8:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a13bc:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f1a13c0:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a13c4:	15d8fff8 */ 	bne	$t6,$t8,.NB0f1a13a8
/*  f1a13c8:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f1a13cc:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1a13d0:	10c10008 */ 	beq	$a2,$at,.NB0f1a13f4
/*  f1a13d4:	3c088007 */ 	lui	$t0,0x8007
/*  f1a13d8:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a13dc:	10c10051 */ 	beq	$a2,$at,.NB0f1a1524
/*  f1a13e0:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a13e4:	10c10019 */ 	beq	$a2,$at,.NB0f1a144c
/*  f1a13e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a13ec:	1000004e */ 	beqz	$zero,.NB0f1a1528
/*  f1a13f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f1a13f4:
/*  f1a13f4:	8d083af0 */ 	lw	$t0,0x3af0($t0)
/*  f1a13f8:	44800000 */ 	mtc1	$zero,$f0
/*  f1a13fc:	3c0a800a */ 	lui	$t2,0x800a
/*  f1a1400:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a1404:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a1408:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a140c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a1410:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a1414:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a1418:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a141c:	254a27c0 */ 	addiu	$t2,$t2,0x27c0
/*  f1a1420:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f1a1424:	e4600ce4 */ 	swc1	$f0,0xce4($v1)
/*  f1a1428:	e4600cbc */ 	swc1	$f0,0xcbc($v1)
/*  f1a142c:	e4600ce8 */ 	swc1	$f0,0xce8($v1)
/*  f1a1430:	e4600cc0 */ 	swc1	$f0,0xcc0($v1)
/*  f1a1434:	e4600cd4 */ 	swc1	$f0,0xcd4($v1)
/*  f1a1438:	e4600cac */ 	swc1	$f0,0xcac($v1)
/*  f1a143c:	e4600cd8 */ 	swc1	$f0,0xcd8($v1)
/*  f1a1440:	e4600cb0 */ 	swc1	$f0,0xcb0($v1)
/*  f1a1444:	10000037 */ 	beqz	$zero,.NB0f1a1524
/*  f1a1448:	e4600cb8 */ 	swc1	$f0,0xcb8($v1)
.NB0f1a144c:
/*  f1a144c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1a1450:	8d6b3af0 */ 	lw	$t3,0x3af0($t3)
/*  f1a1454:	3c0d800a */ 	lui	$t5,0x800a
/*  f1a1458:	25ad27c0 */ 	addiu	$t5,$t5,0x27c0
/*  f1a145c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1a1460:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a1464:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1a1468:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a146c:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f1a1470:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a1474:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1a1478:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f1a147c:	8c640488 */ 	lw	$a0,0x488($v1)
/*  f1a1480:	50800029 */ 	beqzl	$a0,.NB0f1a1528
/*  f1a1484:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1488:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f1a148c:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f1a1490:	2445fff2 */ 	addiu	$a1,$v0,-14
/*  f1a1494:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1a1498:	15f80022 */ 	bne	$t7,$t8,.NB0f1a1524
/*  f1a149c:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f1a14a0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a14a4:	00ee2021 */ 	addu	$a0,$a3,$t6
/*  f1a14a8:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f1a14ac:	94880008 */ 	lhu	$t0,0x8($a0)
/*  f1a14b0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a14b4:	44992000 */ 	mtc1	$t9,$f4
/*  f1a14b8:	44883000 */ 	mtc1	$t0,$f6
/*  f1a14bc:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1a14c0:	05010004 */ 	bgez	$t0,.NB0f1a14d4
/*  f1a14c4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1a14c8:	44815000 */ 	mtc1	$at,$f10
/*  f1a14cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a14d0:	460a4200 */ 	add.s	$f8,$f8,$f10
.NB0f1a14d4:
/*  f1a14d4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1a14d8:	c4303ff4 */ 	lwc1	$f16,0x3ff4($at)
/*  f1a14dc:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f1a14e0:	e4600cb0 */ 	swc1	$f0,0xcb0($v1)
/*  f1a14e4:	46104302 */ 	mul.s	$f12,$f8,$f16
/*  f1a14e8:	e4600cd8 */ 	swc1	$f0,0xcd8($v1)
/*  f1a14ec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1a14f0:	ac6907a8 */ 	sw	$t1,0x7a8($v1)
/*  f1a14f4:	c46a0cc0 */ 	lwc1	$f10,0xcc0($v1)
/*  f1a14f8:	3c0a8009 */ 	lui	$t2,0x8009
/*  f1a14fc:	254abf34 */ 	addiu	$t2,$t2,-16588
/*  f1a1500:	e46c0ce0 */ 	swc1	$f12,0xce0($v1)
/*  f1a1504:	c4323ff8 */ 	lwc1	$f18,0x3ff8($at)
/*  f1a1508:	3c01800a */ 	lui	$at,0x800a
/*  f1a150c:	c424e6c4 */ 	lwc1	$f4,-0x193c($at)
/*  f1a1510:	ac6a0d50 */ 	sw	$t2,0xd50($v1)
/*  f1a1514:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f1a1518:	46065080 */ 	add.s	$f2,$f10,$f6
/*  f1a151c:	e4620ce8 */ 	swc1	$f2,0xce8($v1)
/*  f1a1520:	e4620cc0 */ 	swc1	$f2,0xcc0($v1)
.NB0f1a1524:
/*  f1a1524:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f1a1528:
/*  f1a1528:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f1a152c:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a1530:	03e00008 */ 	jr	$ra
/*  f1a1534:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

s8 var800897c4[] = {-73, 0, 5, 0};
u32 var800897c8 = 0x0400ff00;

struct hoverprop hoverprops[] = {
	// File ID, Y offset, size
	{ FILE_PDROPSHIP,       7,   8    },
	{ FILE_PHOVERCRATE1,    -5,  600  },
	{ FILE_PHOVBIKE,        -10, 50   },
	{ FILE_PHOOVERBOT,      -20, 1000 },
	{ FILE_PDD_HOVERCOPTER, 35,  30   },
	{ FILE_CCHICROB,        0,   70   },
	{ FILE_PA51INTERCEPTOR, -30, 500  },
	{ FILE_PELVIS_SAUCER,   0,   15   },
	{ FILE_PSK_SHUTTLE,     0,   10   },
};

// Can't match the 4bc part
//s32 ciHangarHolographMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
//{
//	s32 index = ciGetHangarBioIndexBySlot(g_HangarBioSlot);
//
//	if (index >= 14) {
//		struct hoverprop props[9] = hoverprops;
//		static s8 tmp[] = {0xb7, 0, 5, 0};
//
//		switch (operation) {
//		case MENUOP_OPEN:
//			g_Menus[g_MpPlayerNum].unkd88 = 0;
//			g_Menus[g_MpPlayerNum].unkd60 = 0;
//			g_Menus[g_MpPlayerNum].unkd8c = 0;
//			g_Menus[g_MpPlayerNum].unkd64 = 0;
//			g_Menus[g_MpPlayerNum].unkd78 = 0;
//			g_Menus[g_MpPlayerNum].unkd50 = 0;
//			g_Menus[g_MpPlayerNum].unkd7c = 0;
//			g_Menus[g_MpPlayerNum].unkd54 = 0;
//			g_Menus[g_MpPlayerNum].unkd5c = 0;
//			break;
//		case MENUOP_CLOSE:
//			break;
//		case MENUOP_TICK:
//			if (g_Menus[g_MpPlayerNum].curdialog && g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef) {
//				// 4bc
//				index -= 14;
//				g_Menus[g_MpPlayerNum].unkd54 = props[index].y_offset;
//				g_Menus[g_MpPlayerNum].unkd84 = props[index].size * 0.001f;
//				g_Menus[g_MpPlayerNum].unkd7c = props[index].y_offset;
//				g_Menus[g_MpPlayerNum].unk84c = props[index].fileid;
//				g_Menus[g_MpPlayerNum].unkd8c = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60f;
//				g_Menus[g_MpPlayerNum].unkd64 += 0.01f * g_Vars.diffframe60f;
//				g_Menus[g_MpPlayerNum].partvisibility = tmp;
//			}
//			break;
//		}
//	}
//
//	return 0;
//}

struct menudialogdef *ciGetFrWeaponListMenuDialog(void)
{
	return &g_FrWeaponListMenuDialog;
}

struct menuitem g_HangarDetailsMenuItems[] = {
	{ MENUITEMTYPE_MODEL,      0,                     0x00200002, 0x00000104,   0x0000002c, ciHangarTitleMenuHandler },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000002, 0x00000000,   0x00000000, NULL                     },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HANGARBIO, 0x00000000, 0x00000104,   0x0000005a, NULL                     },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000002, 0x00000000,   0x00000000, NULL                     },
	{ MENUITEMTYPE_LABEL,      0,                     0x00000022, L_MPMENU_414, 0x00000000, NULL                     }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,        0,                     0x00000000, 0x00000000,   0x00000000, NULL                     },
};

struct menuitem g_HangarVehicleHolographMenuItems[] = {
	{ MENUITEMTYPE_MODEL,       0, 0x00000002, 0x00000104, 0x0000006e, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000022, L_MPMENU_414, 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_HangarVehicleHolographMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_471, // "Holograph"
	g_HangarVehicleHolographMenuItems,
	ciHangarHolographMenuDialog,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

struct menudialogdef g_HangarVehicleDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&bioMenuTextName,
	g_HangarDetailsMenuItems,
	NULL,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_DISABLERESIZE,
	&g_HangarVehicleHolographMenuDialog,
};

struct menudialogdef g_HangarLocationDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&bioMenuTextName,
	g_HangarDetailsMenuItems,
	NULL,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_DISABLERESIZE,
	NULL,
};

struct menuitem g_HangarListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000a0, 0x00000000, ciHangarInformationMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_HangarListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_415, // "Hangar Information"
	g_HangarListMenuItems,
	NULL,
	0,
	NULL,
};
