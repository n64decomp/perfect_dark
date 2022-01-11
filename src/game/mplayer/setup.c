#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_0b3350.h"
#include "game/savebuffer.h"
#include "game/game_0f09f0.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/game_1531a0.h"
#include "game/music.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/vi.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct menuitem g_MpCharacterMenuItems[];
struct menudialog g_MpAddSimulantMenuDialog;
struct menudialog g_MpChangeSimulantMenuDialog;
struct menudialog g_MpChangeTeamNameMenuDialog;
struct menudialog g_MpEditSimulantMenuDialog;
struct menudialog g_MpSaveSetupNameMenuDialog;

s32 menuhandlerMpDropOut(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

char *mpGetCurrentPlayerName(struct menuitem *item)
{
	return g_PlayerConfigsArray[g_MpPlayerNum].base.name;
}

s32 menuhandlerMpTeamsLabel(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) {
			return true;
		}
	}

	return 0;
}

struct menuitem g_MpDropOutMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_196, 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_197, 0x00000000, menuhandlerMpDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_198, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpDropOutMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_195, // "Drop Out"
	g_MpDropOutMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct mparena g_MpArenas[] = {
	// Stage, unlock, name
	{ STAGE_MP_SKEDAR,     0,                          L_MPMENU_119 },
	{ STAGE_MP_PIPES,      0,                          L_MPMENU_120 },
	{ STAGE_MP_RAVINE,     MPFEATURE_STAGE_RAVINE,     L_MPMENU_121 },
	{ STAGE_MP_G5BUILDING, MPFEATURE_STAGE_G5BUILDING, L_MPMENU_122 },
	{ STAGE_MP_SEWERS,     MPFEATURE_STAGE_SEWERS,     L_MPMENU_123 },
	{ STAGE_MP_WAREHOUSE,  MPFEATURE_STAGE_WAREHOUSE,  L_MPMENU_124 },
	{ STAGE_MP_GRID,       MPFEATURE_STAGE_GRID,       L_MPMENU_125 },
	{ STAGE_MP_RUINS,      MPFEATURE_STAGE_RUINS,      L_MPMENU_126 },
	{ STAGE_MP_AREA52,     0,                          L_MPMENU_127 },
	{ STAGE_MP_BASE,       MPFEATURE_STAGE_BASE,       L_MPMENU_128 },
	{ STAGE_MP_FORTRESS,   MPFEATURE_STAGE_FORTRESS,   L_MPMENU_130 },
	{ STAGE_MP_VILLA,      MPFEATURE_STAGE_VILLA,      L_MPMENU_131 },
	{ STAGE_MP_CARPARK,    MPFEATURE_STAGE_CARPARK,    L_MPMENU_132 },
	{ STAGE_MP_TEMPLE,     MPFEATURE_STAGE_TEMPLE,     L_MPMENU_133 },
	{ STAGE_MP_COMPLEX,    MPFEATURE_STAGE_COMPLEX,    L_MPMENU_134 },
	{ STAGE_MP_FELICITY,   MPFEATURE_STAGE_FELICITY,   L_MPMENU_135 },
	{ 1,                   0,                          L_MPMENU_136 }, // "Random"
};

s32 mpGetNumStages(void)
{
	return 17;
}

s16 mpChooseRandomStage(void)
{
	s32 i;
	s32 numchallengescomplete = 0;
	s32 index;

	for (i = 0; i < 16; i++) {
		if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
			numchallengescomplete++;
		}
	}

	index = random() % numchallengescomplete;

	for (i = 0; i < 16; i++) {
		if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
			if (index == 0) {
				return g_MpArenas[i].stagenum;
			}

			index--;
		}
	}

	return STAGE_MP_SKEDAR;
}

s32 mpArenaMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct optiongroup groups[] = {
		{ 0,  L_MPMENU_116 }, // "Dark"
		{ 13, L_MPMENU_117 }, // "Classic"
		{ 16, L_MPMENU_118 }, // "Random"
	};

	s32 i;
	s32 count = 0;
	s32 groupindex;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}

		data->list.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				if (count == data->list.value) {
					return (s32)langGet(g_MpArenas[i].name);
				}

				count++;
			}
		}
		break;
	case MENUOP_SET:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				if (count == data->list.value) {
					break;
				}

				count++;
			}
		}

		g_MpSetup.stagenum = g_MpArenas[i].stagenum;
		break;
	case MENUOP_GETOPTIONVALUE:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (g_MpSetup.stagenum == g_MpArenas[i].stagenum) {
				data->list.value = count;
			}

			if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 3;

		if (!mpIsFeatureUnlocked(MPFEATURE_STAGE_COMPLEX)
				&& !mpIsFeatureUnlocked(MPFEATURE_STAGE_TEMPLE)
				&& !mpIsFeatureUnlocked(MPFEATURE_STAGE_FELICITY)) {
			data->list.value--;
		}
		break;
	case MENUOP_GETOPTGROUPTEXT:
		count = data->list.value;

		if (!mpIsFeatureUnlocked(MPFEATURE_STAGE_COMPLEX)
				&& !mpIsFeatureUnlocked(MPFEATURE_STAGE_TEMPLE)
				&& !mpIsFeatureUnlocked(MPFEATURE_STAGE_FELICITY)
				&& count > 0) {
			count++;
		}
		return (s32)langGet(groups[count].name);
	case MENUOP_GETGROUPSTARTINDEX:
		groupindex = data->list.value;

		if (!mpIsFeatureUnlocked(MPFEATURE_STAGE_COMPLEX)
				&& !mpIsFeatureUnlocked(MPFEATURE_STAGE_TEMPLE)
				&& !mpIsFeatureUnlocked(MPFEATURE_STAGE_FELICITY)
				&& groupindex == 1) {
			groupindex++;
		}

		for (i = 0; i < groups[groupindex].offset; i++) {
			if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}
		data->list.groupstartindex = count;
		break;
	}

	return 0;
}

s32 menuhandlerMpControlStyle(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
		L_OPTIONS_239, // "1.1"
		L_OPTIONS_240, // "1.2"
		L_OPTIONS_241, // "1.3"
		L_OPTIONS_242, // "1.4"
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 4;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(labels[data->dropdown.value]);
	case MENUOP_SET:
		optionsSetControlMode(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = optionsGetControlMode(g_MpPlayerNum);
		break;
	}

	return 0;
}

s32 menuhandlerMpWeaponSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = mpGetNumWeaponOptions();
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) mpGetWeaponLabel(data->dropdown.value);
	case MENUOP_SET:
		mpSetWeaponSlot(item->param3, data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = mpGetWeaponSlot(item->param3);
	}

	return 0;
}

char *mpMenuTextWeaponNameForSlot(struct menuitem *item)
{
	return mpGetWeaponLabel(mpGetWeaponSlot(item->param));
}

s32 menuhandlerMpWeaponSetDropdown(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = func0f189058(item->param);
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) mpGetWeaponSetName(data->dropdown.value);
	case MENUOP_SET:
		mpSetWeaponSet(data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = mpGetWeaponSet();
		break;
	}

	return 0;
}

s32 menuhandlerMpControlCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 val;

	switch (operation) {
	case MENUOP_GET:
		if (item->param3 == OPTION_FORWARDPITCH) {
			if ((g_PlayerConfigsArray[g_MpPlayerNum].options & item->param3) == 0) {
				return true;
			}
			return false;
		}
		if ((g_PlayerConfigsArray[g_MpPlayerNum].options & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		val = OPTION_FORWARDPITCH;

		if (item->param3 == val) {
			if (data->checkbox.value == 0) {
				data->checkbox.value = val;
			} else {
				data->checkbox.value = 0;
			}
		}

		g_PlayerConfigsArray[g_MpPlayerNum].options &= ~item->param3;

		if (data->checkbox.value) {
			g_PlayerConfigsArray[g_MpPlayerNum].options |= item->param3;
		}
	}

	return 0;
}

s32 menuhandlerMpAimControl(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
#if PAL
		L_MPWEAPONS_276, // "Hold"
		L_MPWEAPONS_277, // "Toggle"
#else
		L_MPMENU_213, // "Hold"
		L_MPMENU_214, // "Toggle"
#endif
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 2;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(labels[data->dropdown.value]);
	case MENUOP_SET:
		optionsSetAimControl(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = optionsGetAimControl(g_MpPlayerNum);
		break;
	}

	return 0;
}

s32 menuhandlerMpCheckboxOption(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		if ((g_MpSetup.options & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		g_MpSetup.options = g_MpSetup.options & ~item->param3;
		if (data->checkbox.value) {
			g_MpSetup.options = g_MpSetup.options | item->param3;
		}
	}

	return 0;
}

s32 menuhandlerMpTeamsEnabled(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE ||
				g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			return true;
		}

		return false;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

s32 menuhandlerMpDisplayOptionCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		if ((g_PlayerConfigsArray[g_MpPlayerNum].base.displayoptions & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		g_PlayerConfigsArray[g_MpPlayerNum].base.displayoptions &= ~(u8)item->param3;

		if (data->checkbox.value) {
			g_PlayerConfigsArray[g_MpPlayerNum].base.displayoptions |= (u8)item->param3;
		}
		break;
	}

	return 0;
}

s32 menuhandlerMpConfirmSaveChr(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		filemgrPushSelectLocationDialog(6, FILETYPE_MPPLAYER);
	}

	return 0;
}

s32 menuhandlerMpSetupName(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;

	switch (operation) {
	case MENUOP_GETTEXT:
		strcpy(name, g_MpSetup.name);
		break;
	case MENUOP_SETTEXT:
		strcpy(g_MpSetup.name, name);
		break;
	case MENUOP_SET:
		filemgrPushSelectLocationDialog(7, FILETYPE_MPSETUP);
		break;
	}

	return 0;
}

s32 menuhandlerMpSaveSetupOverwrite(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		filemgrSaveOrLoad(&g_MpSetup.fileguid, FILEOP_SAVE_MPSETUP, 0);
	}

	return 0;
}

s32 menuhandlerMpSaveSetupCopy(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&g_MpSaveSetupNameMenuDialog);
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
char *mpMenuTextSetupName(struct menuitem *item)
{
	return g_MpSetup.name;
}
#endif

s32 func0f179b68(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_PlayerConfigsArray[g_MpPlayerNum].base.unk18;
		break;
	case MENUOP_SET:
		g_PlayerConfigsArray[g_MpPlayerNum].base.unk18 = (u8) data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%d%%\n", data->slider.value + 20);
		break;
	}

	return 0;
}

s32 func0f179c14(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_PlayerConfigsArray[g_MpPlayerNum].base.unk1a;
		break;
	case MENUOP_SET:
		g_PlayerConfigsArray[g_MpPlayerNum].base.unk1a = (u8) data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%d%%\n", data->slider.value + 20);
		break;
	}

	return 0;
}

s32 func0f179cc0(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_PlayerConfigsArray[g_MpPlayerNum].base.unk1c;
		break;
	case MENUOP_SET:
		g_PlayerConfigsArray[g_MpPlayerNum].base.unk1c = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%d%%\n", data->slider.value + 25);
		break;
	}

	return 0;
}

s32 func0f179d6c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f187fbc(g_MpPlayerNum);
	}

	return 0;
}

/**
 * This function is used by both player body selection and bot body selection.
 */
s32 mpCharacterBodyMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data, s32 mpheadnum, s32 mpbodynum, bool isplayer)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->carousel.value = mpGetNumBodies();
		break;
	case MENUOP_11:
		g_Menus[g_MpPlayerNum].unk89c = 0x1fc;
		g_Menus[g_MpPlayerNum].unk84c = mpbodynum << 16 | 0xffff | mpheadnum << 24;
		g_Menus[g_MpPlayerNum].unkdb4 += g_Vars.diffframe60;

		if (g_Menus[g_MpPlayerNum].unkdb4 > PALDOWN(480)) {
			g_Menus[g_MpPlayerNum].unkdb4 -= PALDOWN(480);
		}

		if (g_Menus[g_MpPlayerNum].unkdb8 > 0) {
			g_Menus[g_MpPlayerNum].unkdb8 -= g_Vars.diffframe60;
		} else {
#if VERSION >= VERSION_PAL_FINAL
			f32 value = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60freal;
#else
			f32 value = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60f;
#endif
			g_Menus[g_MpPlayerNum].unkd8c = value;
			g_Menus[g_MpPlayerNum].unkd64 = value;
		}

		g_Menus[g_MpPlayerNum].partvisibility = NULL;
		g_Menus[g_MpPlayerNum].unkd94 = 30;
		break;
	case MENUOP_21:
		if (!mpIsFeatureUnlocked(mpGetBodyRequiredFeature(data->carousel.value))) {
			return 1;
		}
		break;
#if VERSION >= VERSION_NTSC_1_0
	case MENUOP_FOCUS:
		g_Menus[g_MpPlayerNum].unk840 = 3;
		break;
#endif
	case MENUOP_GETOPTIONVALUE:
		data->carousel.value = mpheadnum;
		break;
	case MENUOP_SET:
	case MENUOP_CHECKPREFOCUSED:
		g_Menus[g_MpPlayerNum].unkdc0 = 0;

		func0f0f372c(&g_Menus[g_MpPlayerNum].unk840, 0, 0, 0, 0, 0, 0, 1, 1);

		g_Menus[g_MpPlayerNum].unkd50 = 8.2f;
		g_Menus[g_MpPlayerNum].unkd54 = -4.1f;
		g_Menus[g_MpPlayerNum].unkd7c = -4.1f;

		g_Menus[g_MpPlayerNum].unkd78 = 8.2f;
		g_Menus[g_MpPlayerNum].unkd5c = 0.002f;
		g_Menus[g_MpPlayerNum].unkd64 = -0.2f;
		g_Menus[g_MpPlayerNum].unkd8c = -0.2f;

		g_Menus[g_MpPlayerNum].unkdb8 = PALDOWN(60);
		g_Menus[g_MpPlayerNum].unkdb4 = PALDOWN(120);
		g_Menus[g_MpPlayerNum].unk840 = 8;

#if VERSION >= VERSION_NTSC_1_0
		if (operation == MENUOP_CHECKPREFOCUSED) {
			g_Menus[g_MpPlayerNum].unk840 = 16;
		}
#endif

		break;
	}

	return 0;
}

s32 menuhandlerMpCharacterBody(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		if (g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum < mpGetNumHeads()) {
#if VERSION >= VERSION_NTSC_1_0
			if (!data->carousel.unk04)
#endif
			{
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum = mpGetMpheadnumByMpbodynum(data->carousel.value);
			}
		}
		g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum = data->carousel.value;
		func0f17b8f0();
		break;
	case MENUOP_CHECKPREFOCUSED:
#if VERSION >= VERSION_NTSC_1_0
		mpCharacterBodyMenuHandler(operation, item, data,
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum,
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, true);
#endif
		return true;
	}

	return mpCharacterBodyMenuHandler(operation, item, data,
			g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum,
			g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, true);
}

s32 menudialog0017a174(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curframe->dialog == dialog
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[1]
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[2]) {
			union handlerdata data;
			menuhandlerMpCharacterBody(MENUOP_11, &dialog->items[2], &data);
		}
	}

	return 0;
}

s32 mpChallengesListHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	Gfx *gdl;
	struct menuitemrenderdata *renderdata;
	s32 challengeindex;
	s32 x;
	s32 y;
	s32 loopx;
	s32 maxplayers;
	s32 i;
	char *name;
	s32 size = 11;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = mpGetAutoFocusedChallengeIndex(g_MpPlayerNum);
		break;
	case MENUOP_RENDER:
		maxplayers = 4;
		gdl = data->type19.gdl;
		renderdata = data->type19.renderdata2;
		challengeindex = data->list.unk04;

		if (IS4MB()) {
			maxplayers = 2;
		}

		x = renderdata->x + 10;
		y = renderdata->y + 1;

		gdl = func0f153628(gdl);

		name = mpChallengeGetNameWithArg(g_MpPlayerNum, challengeindex);

		gdl = textRenderProjected(gdl, &x, &y, name,
				g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour,
				viGetWidth(), viGetHeight(), 0, 0);

		gdl = func0f153780(gdl);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		func0f0b39c0(&gdl, &var800ab5a8[35], 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		for (i = 0, loopx = 10; i < maxplayers; i++) {
#if VERSION >= VERSION_NTSC_1_0
			if (mpIsChallengeCompletedByPlayerWithNumPlayers2(g_MpPlayerNum, challengeindex, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, 0xb2efff00 | (renderdata->colour & 0xff) * 255 / 256);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0x30407000 | (renderdata->colour & 0xff) * 255 / 256);
			}
#else
			if (mpIsChallengeCompletedByPlayerWithNumPlayers2(g_MpPlayerNum, challengeindex, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, 0xb2efffff);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0x304070ff);
			}
#endif

			gDPSetCombineLERP(gdl++,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0);

			gSPTextureRectangle(gdl++,
					((renderdata->x + loopx) << 2) * g_ScaleX,
					(renderdata->y + size) << 2,
					((renderdata->x + size + loopx) << 2) * g_ScaleX,
					(renderdata->y + size * 2) << 2,
					G_TX_RENDERTILE,
					0, 0x0160, 0x0400 / g_ScaleX, 0xfc00);

			loopx += 13;
		}

		return (s32) gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 26;
		break;
	}

	return 0;
}

const char var7f1b7ea8[] = "Menu99 -> Calling Camera Module Start\n";
const char var7f1b7ed0[] = "Menu99 -> Calling Camera Module Finish\n";

char *mpMenuTextKills(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].kills);
	return g_StringPointer;
}

char *mpMenuTextDeaths(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].deaths);
	return g_StringPointer;
}

char *mpMenuTextGamesPlayed(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gamesplayed);
	return g_StringPointer;
}

char *mpMenuTextGamesWon(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gameswon);
	return g_StringPointer;
}

char *mpMenuTextGamesLost(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gameslost);
	return g_StringPointer;
}

char *mpMenuTextHeadShots(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].headshots);
	return g_StringPointer;
}

char *mpMenuTextMedalAccuracy(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].accuracymedals);
	return g_StringPointer;
}

char *mpMenuTextMedalHeadShot(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].headshotmedals);
	return g_StringPointer;
}

char *mpMenuTextMedalKillMaster(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].killmastermedals);
	return g_StringPointer;
}

char *mpMenuTextMedalSurvivor(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].survivormedals);
	return g_StringPointer;
}

char *mpMenuTextAmmoUsed(struct menuitem *item)
{
	s32 value = g_PlayerConfigsArray[g_MpPlayerNum].ammoused;

	if (value > 100000) {
		value = value / 1000;

		if (value > 100000) {
			value = value / 1000;
			sprintf(g_StringPointer, "%dM\n", value);
		} else {
			sprintf(g_StringPointer, "%dK\n", value);
		}
	} else {
		sprintf(g_StringPointer, "%d\n", value);
	}

	return g_StringPointer;
}

char *mpMenuTextDistance(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s%s%.1fkm\n", "", "", g_PlayerConfigsArray[g_MpPlayerNum].distance / 10.0f);
	return g_StringPointer;
}

char *mpMenuTextTime(struct menuitem *item)
{
	u32 raw = g_PlayerConfigsArray[g_MpPlayerNum].time;
	s32 secs = raw % 60;
	s32 hours;
	s32 days;

	if (raw == 0) {
		return "--:--\n";
	}

	if (raw >= 0x7fffffff) {
		return "==:==\n";
	}

	raw = raw / 60;
	hours = raw / 60;
	days = hours / 24;

	if (days == 0) {
		sprintf(g_StringPointer, "%d:%02d.%02d", hours % 24, raw % 60, secs);
	} else {
		sprintf(g_StringPointer, "%d:%02d:%02d", days, hours % 24, raw % 60);
	}

	return g_StringPointer;
}

char *mpMenuTextAccuracy(struct menuitem *item)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_PlayerConfigsArray[g_MpPlayerNum].gamesplayed < 8) {
		return "-\n";
	}
#endif

	sprintf(g_StringPointer, "%s%s%.1f%%", "", "", g_PlayerConfigsArray[g_MpPlayerNum].accuracy / 10.0f);
	return g_StringPointer;
}

void mpFormatDamageValue(char *dst, f32 damage)
{
#if VERSION >= VERSION_NTSC_1_0
	if (damage < 1000) {
		sprintf(dst, "%s%s%.1f", "", "", damage);
	} else if (damage < 10000) {
		sprintf(dst, "%s%s%.0f", "", "", damage);
	} else if (damage < 100000) {
		damage = damage / 1000;
		sprintf(dst, "%s%s%.1fK", "", "", damage);
	} else if (damage < 1000000) {
		damage = damage / 1000;
		sprintf(dst, "%s%s%.0fK", "", "", damage);
	} else if (damage < 10000000) {
		damage = damage / 1000;
		damage = damage / 1000;
		sprintf(dst, "%s%s%.1fM", "", "", damage);
	} else {
		damage = damage / 1000;
		damage = damage / 1000;
		sprintf(dst, "%s%s%.0fM", "", "", damage);
	}
#else
	if (damage > 100000) {
		damage = damage / 1000;
		sprintf(dst, "%s%s%.1fKL", "", "", damage);
	} else {
		sprintf(dst, "%s%s%.1fL", "", "", damage);
	}
#endif
}

char *mpMenuTextPainReceived(struct menuitem *item)
{
	mpFormatDamageValue(g_StringPointer, g_PlayerConfigsArray[g_MpPlayerNum].painreceived / 10.0f);
	return g_StringPointer;
}

char *mpMenuTextDamageDealt(struct menuitem *item)
{
	mpFormatDamageValue(g_StringPointer, g_PlayerConfigsArray[g_MpPlayerNum].damagedealt / 10.0f);
	return g_StringPointer;
}

s32 mpMedalMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_RENDER) {
		Gfx *gdl = data->type19.gdl;
		struct menuitemrenderdata *renderdata = data->type19.renderdata2;
		u32 colour;

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		func0f0b39c0(&gdl, &var800ab5a8[35], 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		switch (item->param) {
		case 0: // KillMaster - red
			colour = 0xff7f7fff;
			break;
		case 1: // Headshot - yellow
			colour = 0xbfbf00ff;
			break;
		case 2: // Accuracy - green
			colour = 0x00ff00ff;
			break;
		case 3: // Survivor - blue
			colour = 0x00bfbfff;
			break;
		}

#if VERSION >= VERSION_NTSC_1_0
		colour = colour & 0xffffff00 | (colour & 0xff) * (renderdata->colour & 0xff) >> 8;
#endif

		gDPSetEnvColorViaWord(gdl++, colour);

		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0);

		gSPTextureRectangle(gdl++,
				((renderdata->x + 9) << 2) * g_ScaleX, renderdata->y << 2,
				((renderdata->x + 20) << 2) * g_ScaleX, (renderdata->y + 11) << 2,
				G_TX_RENDERTILE, 0, 0x0160, 1024 / g_ScaleX, -1024);

		return (s32) gdl;
	}

	return 0;
}

char *mpMenuTitleStatsForPlayerName(struct menudialog *dialog)
{
	// "Stats for %s"
	sprintf(g_StringPointer, langGet(L_MPMENU_145), g_PlayerConfigsArray[g_MpPlayerNum].base.name);
	return g_StringPointer;
}

s32 menuhandlerMpUsernamePassword(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].title != MPPLAYERTITLE_PERFECT) {
			return true;
		}
	}

	return 0;
}

struct menuitem g_MpSavePlayerMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_191, 0x00000000, NULL }, // "Your player file is always saved automatically."
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_192, 0x00000000, NULL }, // "Save a copy now?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_193, 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_194, 0x00000000, menuhandlerMpConfirmSaveChr }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSavePlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_190, // "Confirm"
	g_MpSavePlayerMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpSaveSetupNameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_189, 0x00000000, NULL }, // "Enter a name for your game setup file:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandlerMpSetupName },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSaveSetupNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_188, // "Game File Name"
	g_MpSaveSetupNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpSaveSetupExistsMenuItems[] = {
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPWEAPONS_230, (u32)&mpMenuTextSetupName, NULL }, // "Name:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_184, 0x00000000, NULL }, // "Do you want to save over your original game file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_185, 0x00000000, menuhandlerMpSaveSetupOverwrite }, // "Save Over Original"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_186, 0x00000000, menuhandlerMpSaveSetupCopy }, // "Save Copy"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_187, 0x00000000, NULL }, // "Do Not Save"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSaveSetupExistsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_183, // "Save Game Setup"
	g_MpSaveSetupExistsMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpWeaponsMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00020090, L_MPMENU_174, 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000212, L_MPMENU_175, 0x00000000, NULL }, // "Current Weapon Setup:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_176, 0x00000000, menuhandlerMpWeaponSlot }, // "1:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_177, 0x00000001, menuhandlerMpWeaponSlot }, // "2:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_178, 0x00000002, menuhandlerMpWeaponSlot }, // "3:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_179, 0x00000003, menuhandlerMpWeaponSlot }, // "4:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_180, 0x00000004, menuhandlerMpWeaponSlot }, // "5:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_181, 0x00000005, menuhandlerMpWeaponSlot }, // "6:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_182, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_173, // "Weapons"
	g_MpWeaponsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpQuickTeamWeaponsMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020090, L_MPMENU_174, 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_176, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "1:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000002, L_MPMENU_177, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "2:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000002, L_MPMENU_178, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "3:"
	{ MENUITEMTYPE_LABEL,       3, 0x00000002, L_MPMENU_179, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "4:"
	{ MENUITEMTYPE_LABEL,       4, 0x00000002, L_MPMENU_180, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "5:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_182, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_173, // "Weapons"
	g_MpQuickTeamWeaponsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpPlayerOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_168, MPDISPLAYOPTION_HIGHLIGHTPICKUPS, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Pickups"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_169, MPDISPLAYOPTION_HIGHLIGHTPLAYERS, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Players"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_170, MPDISPLAYOPTION_HIGHLIGHTTEAMS,   menuhandlerMpDisplayOptionCheckbox }, // "Highlight Teams"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_171, MPDISPLAYOPTION_RADAR,            menuhandlerMpDisplayOptionCheckbox }, // "Radar"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_172, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_167, // "Options"
	g_MpPlayerOptionsMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpControlMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU_200, 0x00000000,              menuhandlerMpControlStyle }, // "Control Style"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_201, OPTION_FORWARDPITCH,     menuhandlerMpControlCheckbox }, // "Reverse Pitch"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_202, OPTION_LOOKAHEAD,        menuhandlerMpControlCheckbox }, // "Look Ahead"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_203, OPTION_HEADROLL,         menuhandlerMpControlCheckbox }, // "Head Roll"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_204, OPTION_AUTOAIM,          menuhandlerMpControlCheckbox }, // "Auto-Aim"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU_205, 0x00000000,              menuhandlerMpAimControl }, // "Aim Control"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_206, OPTION_SIGHTONSCREEN,    menuhandlerMpControlCheckbox }, // "Sight on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_207, OPTION_ALWAYSSHOWTARGET, menuhandlerMpControlCheckbox }, // "Show Target"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_208, OPTION_SHOWZOOMRANGE,    menuhandlerMpControlCheckbox }, // "Show Zoom Range"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_209, OPTION_AMMOONSCREEN,     menuhandlerMpControlCheckbox }, // "Ammo on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_210, OPTION_SHOWGUNFUNCTION,  menuhandlerMpControlCheckbox }, // "Gun Function"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_211, OPTION_PAINTBALL,        menuhandlerMpControlCheckbox }, // "Paintball"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_212, 0x00000000,              NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000,    0x00000000,              NULL },
};

struct menudialog g_MpControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_199, // "Control"
	g_MpControlMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpCompletedChallengesMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x00000078, 0x0000004d, mpChallengesListHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpCompletedChallengesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_165, // "Completed Challenges"
	g_MpCompletedChallengesMenuItems,
	NULL,
	0x00000048,
	NULL,
};

#if VERSION >= VERSION_NTSC_1_0
char *mpMenuTextUsernamePassword(struct menuitem *item)
{
	// Phrases included here to assist people searching the code for them:
	// EnTROpIcDeCAy
	// ZeRo-Tau

	u8 username[15] = {
		'E' + 9 * 1,
		'n' + 9 * 2,
		'T' + 9 * 3,
		'R' + 9 * 4,
		'O' + 9 * 5,
		'p' + 9 * 6,
		'I' + 9 * 7,
		'c' + 9 * 8,
		'D' + 9 * 9,
		'e' + 9 * 10,
		'C' + 9 * 11,
		'A' + 9 * 12,
		'y' + 9 * 13,
		'\n' + 9 * 14,
		'\0' + 9 * 15,
	};

	u8 password[10] = {
		'Z' + 4 * 1,
		'e' + 4 * 2,
		'R' + 4 * 3,
		'o' + 4 * 4,
		'-' + 4 * 5,
		'T' + 4 * 6,
		'a' + 4 * 7,
		'u' + 4 * 8,
		'\n' + 4 * 9,
		'\0' + 4 * 10,
	};

	u32 stack;
	s32 i;

	if (item->param == 0) {
		for (i = 0; i < 15; i++) {
			g_StringPointer[i] = username[i] - i * 9 - 9;
		}
	} else {
		for (i = 0; i < 10; i++) {
			g_StringPointer[i] = password[i] - i * 4 - 4;
		}
	}

	return g_StringPointer;
}
#endif

struct menuitem g_MpPlayerStatsMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_146, (u32)&mpMenuTextKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_147, (u32)&mpMenuTextDeaths, NULL }, // "Deaths:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_148, (u32)&mpMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_149, (u32)&mpMenuTextHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_150, (u32)&mpMenuTextAmmoUsed, NULL }, // "Ammo Used:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_151, (u32)&mpMenuTextDamageDealt, NULL }, // "Damage Dealt:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_152, (u32)&mpMenuTextPainReceived, NULL }, // "Pain Received:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_153, (u32)&mpMenuTextGamesPlayed, NULL }, // "Games Played:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_154, (u32)&mpMenuTextGamesWon, NULL }, // "Games Won:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_155, (u32)&mpMenuTextGamesLost, NULL }, // "Games Lost:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_156, (u32)&mpMenuTextTime, NULL }, // "Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_157, (u32)&mpMenuTextDistance, NULL }, // "Distance:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU_158, 0x00000000, NULL }, // "Medals Won:"
	{ MENUITEMTYPE_LABEL,       2, 0x00200000, L_MPMENU_159, (u32)&mpMenuTextMedalAccuracy, mpMedalMenuHandler }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       1, 0x00200000, L_MPMENU_160, (u32)&mpMenuTextMedalHeadShot, mpMedalMenuHandler }, // "Head Shot:"
	{ MENUITEMTYPE_LABEL,       0, 0x00200000, L_MPMENU_161, (u32)&mpMenuTextMedalKillMaster, mpMedalMenuHandler }, // "KillMaster:"
	{ MENUITEMTYPE_LABEL,       3, 0x00200000, L_MPMENU_162, (u32)&mpMenuTextMedalSurvivor, mpMedalMenuHandler }, // "Survivor:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_163, 0x00000000, NULL }, // "Your Title:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextPlayerTitle, 0x00000000, NULL },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_219, 0x00000000, menuhandlerMpUsernamePassword }, // "USERNAME:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_220, 0x00000000, menuhandlerMpUsernamePassword }, // "PASSWORD:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
#else
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_219, 0x00000000, menuhandlerMpUsernamePassword }, // "USERNAME:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000220, 0x51f0, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_220, 0x00000000, menuhandlerMpUsernamePassword }, // "PASSWORD:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000220, 0x51f1, 0x00000000, menuhandlerMpUsernamePassword },
#endif
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_164, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsForPlayerName,
	g_MpPlayerStatsMenuItems,
	NULL,
	0x00000048,
	&g_MpCompletedChallengesMenuDialog,
};

s32 mpCharacterHeadMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data, s32 mpheadnum, bool arg4)
{
	f32 diffframe;
	s32 headnum;

	static struct modelpartvisibility visibility[] = {
		{ MODELPART_HEAD_SUNGLASSES, false },
		{ MODELPART_HEAD_EYESCLOSED, false },
		{ MODELPART_HEAD_HUDPIECE,   false },
		{ 255, false },
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->carousel.value = mpGetNumHeads2();
		break;
	case MENUOP_11:
#if VERSION >= VERSION_PAL_FINAL
		diffframe = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60freal;
#else
		diffframe = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60f;
#endif

		g_Menus[g_MpPlayerNum].unkd8c = diffframe;
		g_Menus[g_MpPlayerNum].unkd64 = diffframe;

		if (mpheadnum < mpGetNumHeads2()) {
			headnum = mpGetHeadId(mpheadnum);

			g_Menus[g_MpPlayerNum].unk84c = g_HeadsAndBodies[headnum].filenum;
			g_Menus[g_MpPlayerNum].unkdf1 = false;
		} else {
			headnum = mpGetBeauHeadId(func0f14a9f8(mpheadnum - mpGetNumHeads2()));

			g_Menus[g_MpPlayerNum].unk84c = g_HeadsAndBodies[headnum].filenum;
			g_Menus[g_MpPlayerNum].unkdf1 = true;
			g_Menus[g_MpPlayerNum].unkdf0 = mpheadnum - mpGetNumHeads2();
		}

		g_Menus[g_MpPlayerNum].unkdb4 = 0;
		g_Menus[g_MpPlayerNum].partvisibility = visibility;
		g_Menus[g_MpPlayerNum].unkd94 = 30;
		break;
	case MENUOP_21:
		if (!mpIsFeatureUnlocked(mpGetHeadRequiredFeature(data->carousel.value))) {
			return 1;
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		data->carousel.value = mpheadnum;
		break;
	case MENUOP_SET:
	case MENUOP_FOCUS:
#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].unk840 = 3;
#endif

		mpGetNumHeads2();

		func0f0f372c(&g_Menus[g_MpPlayerNum].unk840, 0, 0, 0, 0, 0, 0, 1, 1);

		g_Menus[g_MpPlayerNum].unkd50 = 0;
		g_Menus[g_MpPlayerNum].unkd54 = 0;
		g_Menus[g_MpPlayerNum].unkd7c = -3;

		g_Menus[g_MpPlayerNum].unkd78 = 0;
		g_Menus[g_MpPlayerNum].unkd5c = 0.01f;
		g_Menus[g_MpPlayerNum].unkd64 = -0.3f;
		g_Menus[g_MpPlayerNum].unkd8c = -0.3f;

		g_Menus[g_MpPlayerNum].unkd84 = 1;
		g_Menus[g_MpPlayerNum].unkd94 = 30;
		break;
	}

	return 0;
}

s32 menuhandlerMpCharacterHead(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum = data->carousel.value;
	}

	return mpCharacterHeadMenuHandler(operation, item, data, g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, 1);
}

char *mpMenuTextBodyName(struct menuitem *item)
{
	return mpGetBodyName(g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum);
}

void func0f17b8f0(void)
{
	func0f0f139c(g_MpCharacterMenuItems, -0.4f);
}

s32 mpPlayerNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;
	s32 i;

	switch (operation) {
	case MENUOP_GETTEXT:
		i = 0;

		while (g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] != '\n'
				&& g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] != '\0'
				&& i < 11) {
			name[i] = g_PlayerConfigsArray[g_MpPlayerNum].base.name[i];
			i++;
		}

		while (i < 11) {
			name[i] = '\0';
			i++;
		}
		break;
	case MENUOP_SETTEXT:
		i = 0;

		while (i < 11 && name[i] != '\0') {
			g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] = name[i];
			i++;
		}

		g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] = '\n';
		i++;

		while (i < 11) {
			g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] = '\0';
			i++;
		}
		break;
	}

	return 0;
}

s32 mpLoadSettingsMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = mpGetNumUnlockedPresets();

		if (g_FileLists[1] != NULL) {
			data->list.value += g_FileLists[1]->numfiles;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		if (data->list.value < mpGetNumUnlockedPresets()) {
			return (s32)mpGetPresetNameBySlot(data->list.value);
		}
		if (g_FileLists[1] != NULL) {
			func0f0d564c(g_FileLists[1]->files[data->list.value - mpGetNumUnlockedPresets()].name, g_StringPointer, false);
			return (s32)g_StringPointer;
		}
		break;
	case MENUOP_SET:
		mpCloseDialogsForNewSetup();

		if (data->list.value < mpGetNumUnlockedPresets()) {
			func0f18dec4(data->list.value);
		} else if (g_FileLists[1] != NULL) {
			struct filelistfile *file = &g_FileLists[1]->files[data->list.value - mpGetNumUnlockedPresets()];
			struct fileguid guid;

			guid.fileid = file->fileid;
			guid.deviceserial = file->deviceserial;

			filemgrSaveOrLoad(&guid, FILEOP_LOAD_MPSETUP, 0);
		}

		if (item->param == 1) {
			if (IS4MB()) {
				func0f0f820c(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
			} else {
				func0f0f820c(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
			}
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		data->list.value = 0xfffff;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 1;

		if (g_FileLists[1] != NULL) {
			data->list.value += g_FileLists[1]->numdevices;
		}
		break;
	case MENUOP_GETOPTGROUPTEXT:
		if (data->list.value == 0) {
			return (s32)langGet(L_MPMENU_141); // "Presets"
		}
		if (g_FileLists[1] != NULL) {
			return (s32)filemgrGetDeviceNameOrStartIndex(1, operation, data->list.value - 1);
		}
		break;
	case MENUOP_GETGROUPSTARTINDEX:
		if (data->list.value == 0) {
			data->list.groupstartindex = 0;
		} else {
			data->list.groupstartindex = mpGetNumUnlockedPresets();

			if (g_FileLists[1] != NULL) {
				data->list.groupstartindex += filemgrGetDeviceNameOrStartIndex(1, operation, data->list.value - 1);
			}
		}
		break;
	case MENUOP_LISTITEMFOCUS:
		if (data->list.value < mpGetNumUnlockedPresets()) {
			g_Menus[g_MpPlayerNum].mpsetup.slotindex = 0xffff;
		} else {
			g_Menus[g_MpPlayerNum].mpsetup.slotindex = data->list.value - mpGetNumUnlockedPresets();
		}
		break;
	}

	return 0;
}

char *mpMenuTextMpconfigMarquee(struct menuitem *item)
{
	char filename[20];
	u16 numsims;
	u16 stagenum;
	u16 scenarionum;
	s32 arenanum;
	s32 i;

	if (g_Menus[g_MpPlayerNum].mpsetup.slotindex < 0xffff && g_FileLists[1]) {
#if VERSION >= VERSION_NTSC_1_0
		arenanum = -1;
#else
		arenanum = 0;
#endif

		mpsetupfileGetOverview(g_FileLists[1]->files[g_Menus[g_MpPlayerNum].mpsetup.slotindex].name,
				filename, &numsims, &stagenum, &scenarionum);

		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (g_MpArenas[i].stagenum == stagenum) {
				arenanum = i;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (scenarionum <= 5 && arenanum != -1 && numsims >= 0 && filename[0] != '\0' && numsims <= 8) {
			// "%s:  Scenario: %s   Arena: %s    Simulants: %d"
			sprintf(g_StringPointer, langGet(L_MPMENU_140),
					filename,
					langGet(g_MpScenarioOverviews[scenarionum].name),
					langGet(g_MpArenas[arenanum].name),
					numsims);
		} else {
			return "";
		}
#else
		// "%s:  Scenario: %s   Arena: %s    Simulants: %d"
		sprintf(g_StringPointer, langGet(L_MPMENU_140),
				filename,
				langGet(g_MpScenarioOverviews[scenarionum].name),
				langGet(g_MpArenas[arenanum].name),
				numsims);
#endif

		return g_StringPointer;
	}

	return "";
}

s32 mpLoadPlayerMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 i;
	struct fileguid guid;
	struct filelistfile *file;
	bool available;

	if (g_FileLists[0] == NULL) {
		return 0;
	}

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = g_FileLists[0]->numfiles;
		break;
	case MENUOP_GETOPTIONTEXT:
		filemgrGetSelectName(g_StringPointer, &g_FileLists[0]->files[data->list.value], FILETYPE_MPPLAYER);
		return (s32)g_StringPointer;
	case MENUOP_SET:
		file = &g_FileLists[0]->files[data->list.value];
		available = true;

		for (i = 0; i < 4; i++) {
			if (file->fileid == g_PlayerConfigsArray[i].fileguid.fileid
					&& file->deviceserial == g_PlayerConfigsArray[i].fileguid.deviceserial) {
				if ((g_MpSetup.chrslots & (1 << i)) == 0) {
					mpPlayerSetDefaults(i, true);
				} else {
					available = false;
				}
			}
		}

		if (available) {
			guid.fileid = file->fileid;
			guid.deviceserial = file->deviceserial;

			menuPopDialog();

			filemgrSaveOrLoad(&guid, FILEOP_LOAD_MPPLAYER, g_MpPlayerNum);
		} else {
			filemgrPushErrorDialog(FILEERROR_ALREADYLOADED);
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		data->list.value = 0xfffff;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = g_FileLists[0]->numdevices;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return filemgrGetDeviceNameOrStartIndex(0, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = filemgrGetDeviceNameOrStartIndex(0, operation, data->list.value);
		return 0;
	}

	return 0;
}

s32 menuhandlerMpTimeLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpSetup.timelimit;
		break;
	case MENUOP_SET:
		g_MpSetup.timelimit = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (data->slider.value == 60) {
			sprintf(data->slider.label, langGet(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, langGet(L_MPMENU_114), data->slider.value + 1); // "%d Min"
		}
	}
	return 0;
}

s32 menuhandlerMpScoreLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpSetup.scorelimit;
		break;
	case MENUOP_SET:
		g_MpSetup.scorelimit = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (data->slider.value == 100) {
			sprintf(data->slider.label, langGet(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, langGet(L_MPMENU_113), data->slider.value + 1); // "%d"
		}
	}

	return 0;
}

s32 menuhandlerMpTeamScoreLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = mpCalculateTeamScoreLimit();
		break;
	case MENUOP_SET:
		g_MpSetup.teamscorelimit = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (data->slider.value == 400) {
			sprintf(data->slider.label, langGet(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, langGet(L_MPMENU_113), data->slider.value + 1); // "%d"
		}
	}

	return 0;
}

s32 menuhandlerMpRestoreScoreDefaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f187fec();
	}

	return 0;
}

s32 menuhandlerMpHandicapPlayer(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_CHECKHIDDEN:
		if ((g_MpSetup.chrslots & (1 << item->param)) == 0) {
			return 1;
		}
		break;
	case MENUOP_GETSLIDER:
		data->slider.value = g_PlayerConfigsArray[item->param].handicap;
		break;
	case MENUOP_SET:
		g_PlayerConfigsArray[item->param].handicap = (u16)data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%s%s%.00f%%\n", "", "", mpHandicapToDamageScale(g_PlayerConfigsArray[item->param].handicap) * 100);
		break;
	}

	return 0;
}

char *mpMenuTextHandicapPlayerName(struct menuitem *item)
{
	if (g_MpSetup.chrslots & (1 << item->param)) {
		return g_PlayerConfigsArray[item->param].base.name;
	}

	return "";
}

s32 menuhandlerMpRestoreHandicapDefaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i < 4; i++) {
			g_PlayerConfigsArray[i].handicap = 0x80;
		}
	}

	return 0;
}

s32 menudialogMpReady(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid && g_PlayerConfigsArray[g_MpPlayerNum].fileguid.deviceserial) {
			filemgrSaveOrLoad(&g_PlayerConfigsArray[g_MpPlayerNum].fileguid, FILEOP_SAVE_MPPLAYER, g_MpPlayerNum);
		}
	}

	return false;
}

s32 menudialogMpSimulant(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if ((u8)g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.name[0] == '\0') {
			menuPopDialog();
		}
	}

	return false;
}

struct menuitem g_MpCharacterMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004230, (u32)&mpMenuTextBodyName, 0x00000000, NULL },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x00000022, menuhandlerMpCharacterHead },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x0000001b, menuhandlerMpCharacterBody },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpCharacterMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_143, // "Character"
	g_MpCharacterMenuItems,
	menudialog0017a174,
	0x00000002,
	NULL,
};

struct menuitem g_MpPlayerNameMenuItems[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, mpPlayerNameMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_142, // "Player Name"
	g_MpPlayerNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpLoadSettingsMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x00000078, 0x00000042, mpLoadSettingsMenuHandler },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextMpconfigMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLoadSettingsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_139, // "Load Game Settings"
	g_MpLoadSettingsMenuItems,
	NULL,
	0x00000001,
	NULL,
};

struct menuitem g_MpLoadPresetMenuItems[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00000000, 0x00000078, 0x00000042, mpLoadSettingsMenuHandler },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextMpconfigMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLoadPresetMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_139, // "Load Game Settings"
	g_MpLoadPresetMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpLoadPlayerMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x0000007e, 0x00000042, mpLoadPlayerMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPMENU_138, 0x00000000, NULL }, // "B Button to cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLoadPlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_137, // "Load Player"
	g_MpLoadPlayerMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpArenaMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x0000004d, mpArenaMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpArenaMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_115, // "Arena"
	g_MpArenaMenuItems,
	NULL,
	0x00000011,
	NULL,
};

struct menuitem g_MpLimitsMenuItems[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU_108, 0x0000003c, menuhandlerMpTimeLimitSlider }, // "Time"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU_109, 0x00000064, menuhandlerMpScoreLimitSlider }, // "Score"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MISC_447, 0x00000190, menuhandlerMpTeamScoreLimitSlider }, // "Team Score"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_110, 0x00000000, menuhandlerMpRestoreScoreDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_111, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLimitsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_107, // "Limits"
	g_MpLimitsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpHandicapsMenuItems[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      1, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      2, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      3, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_110, 0x00000000, menuhandlerMpRestoreHandicapDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_111, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpHandicapsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_184, // "Player Handicaps"
	g_MpHandicapsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpReadyMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_106, 0x00000000, NULL }, // "...and waiting"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpReadyMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_105, // "Ready!"
	g_MpReadyMenuItems,
	menudialogMpReady,
	0x00000001,
	NULL,
};

s32 mpAddChangeSimulantMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 i;
	s32 count = 0;

	struct optiongroup groups[] = {
		{ 0, L_MPMENU_103 }, // "Normal Simulants"
		{ 6, L_MPMENU_104 }, // "Special Simulants"
	};

	s32 botnum;
	bool creating;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->list.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->list.value) {
					return (s32)langGet(g_BotProfiles[i].name);
				}

				count++;
			}
		}
		break;
	case MENUOP_SET:
		botnum = g_Menus[g_MpPlayerNum].mpsetup.slotindex;
		creating = false;

		if (botnum < 0) {
			botnum = mpGetSlotForNewBot();
			creating = 1;
		} else if ((g_MpSetup.chrslots & (1 << (botnum + 4))) == 0) {
			creating = 1;
		}

		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->list.value) {
					break;
				}

				count++;
			}
		}

		if (creating) {
			mpCreateBotFromProfile(botnum, i);
		} else {
			g_BotConfigsArray[botnum].type = g_BotProfiles[i].type;

			if (g_BotConfigsArray[botnum].type == BOTTYPE_GENERAL) {
				mpSetBotDifficulty(botnum, g_BotProfiles[i].difficulty);
			}
		}

		mpGenerateBotNames();
		g_Menus[g_MpPlayerNum].mpsetup.slotcount = data->list.value;
		break;
	case MENUOP_LISTITEMFOCUS:
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->list.value) {
					break;
				}

				count++;
			}
		}

		g_Menus[g_MpPlayerNum].mpsetup.unke24 = i;
		// fall-through
	case MENUOP_GETOPTIONVALUE:
		data->list.value = g_Menus[g_MpPlayerNum].mpsetup.slotcount;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 2;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return (s32)langGet(groups[data->list.value].name);
	case MENUOP_GETGROUPSTARTINDEX:
		for (i = 0; i < groups[data->list.value].offset; i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->list.groupstartindex = count;
		break;
	}

	return 0;
}

char *mpMenuTextSimulantDescription(struct menuitem *item)
{
	return langGet(L_MISC_106 + g_Menus[g_MpPlayerNum].mpsetup.unke24);
}

s32 menuhandlerMpSimulantHead(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 start = 0;

	if (item->param2 == 1) {
		start = mpGetNumHeads();
	}

	/**
	 * Rare developers forgot to add a break statement to the first case,
	 * and when they noticed a problem their fix was to add an additional
	 * MENUOP_FOCUS check in the next case.
	 */
	switch (operation) {
	case MENUOP_SET:
		g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum = start + data->carousel.value;
	case MENUOP_FOCUS:
		if (operation == MENUOP_FOCUS
				&& item->param2 == 1
				&& g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum < start) {
			g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum = start;
		}
		break;
	}

	return mpCharacterHeadMenuHandler(operation, item, data, g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum, 0);
}

s32 menuhandlerMpSimulantBody(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpbodynum = data->carousel.value;
	}

	return mpCharacterBodyMenuHandler(operation, item, data,
			g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpbodynum,
			g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum,
			false);
}

s32 menudialog0017ccfc(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curframe->dialog == dialog
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[0]
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[1]) {
			union handlerdata data;
			menuhandlerMpCharacterBody(MENUOP_11, &dialog->items[1], &data);
		}
	}

	return menudialogMpSimulant(operation, dialog, data);
}

s32 mpBotDifficultyMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 count = 0;
	s32 i;

	switch (operation) {
	case MENUOP_SET:
		mpSetBotDifficulty(g_Menus[g_MpPlayerNum].mpsetup.slotindex, data->dropdown.value);
		mpGenerateBotNames();
		break;
	case MENUOP_GETOPTIONVALUE:
		if (g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty >= 0
				&& g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty < BOTDIFF_DISABLED) {
			data->dropdown.value = g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty;
		} else {
			data->dropdown.value = 0;
		}
		break;
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < BOTDIFF_DISABLED; i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->dropdown.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < BOTDIFF_DISABLED; i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->dropdown.value) {
					// "Meat", "Easy", "Normal" etc
					return (s32) langGet(L_MISC_082 + i);
				}

				count++;
			}
		}

		return (s32)"\n";
	}

	return 0;
}

s32 menuhandlerMpDeleteSimulant(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mpRemoveSimulant(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
		menuPopDialog();
	}

	return 0;
}

char *mpMenuTitleEditSimulant(struct menudialog *dialog)
{
	sprintf(g_StringPointer, "%s", &g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.name);
	return g_StringPointer;
}

s32 menuhandlerMpChangeSimulantType(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		s32 count = 0;
		s32 profilenum = mpFindBotProfile(
				g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].type,
				g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty);

		for (i = 0; i < profilenum; i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		g_Menus[g_MpPlayerNum].mpsetup.slotcount = count;

		menuPushDialog(&g_MpChangeSimulantMenuDialog);
	}

	return 0;
}

s32 menuhandlerMpClearAllSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		for (i = 0; i < MAX_SIMULANTS; i++) {
			mpRemoveSimulant(i);
		}
	}

	return 0;
}

s32 menuhandlerMpAddSimulant(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = -1;
		menuPushDialog(&g_MpAddSimulantMenuDialog);
		break;
	case MENUOP_CHECKDISABLED:
		if (mpHasUnusedBotSlots() == 0) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpSimulantSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = item->param;

		if ((g_MpSetup.chrslots & (1 << (item->param + 4))) == 0) {
			menuPushDialog(&g_MpAddSimulantMenuDialog);
		} else if (IS4MB()) {
			menuPushDialog(&g_MpEditSimulant4MbMenuDialog);
		} else {
			menuPushDialog(&g_MpEditSimulantMenuDialog);
		}
		break;
	case MENUOP_CHECKHIDDEN:
		if (item->param >= 4 && !mpIsFeatureUnlocked(MPFEATURE_8BOTS)) {
			return true;
		}
		break;
	case MENUOP_CHECKDISABLED:
		if (!mpIsSimSlotEnabled(item->param)) {
			return true;
		}
	}

	return 0;
}

char *mpMenuTextSimulantName(struct menuitem *item)
{
	s32 index = item->param;

	if (g_BotConfigsArray[index].base.name[0] == '\0' || (g_MpSetup.chrslots & 1 << (index + 4)) == 0) {
		return "";
	}

	return g_BotConfigsArray[index].base.name;
}

char *func0f17d3dc(struct menuitem *item)
{
	s32 index = item->param;

	if (g_BotConfigsArray[index].base.name[0] == '\0'
			|| ((g_MpSetup.chrslots & 1 << (index + 4)) == 0)) {
		return "";
	}

	sprintf(g_StringPointer, "%d:\n", index + 1);
	return g_StringPointer;
}

s32 menudialogMpSimulants(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Menus[g_MpPlayerNum].mpsetup.slotcount = 0;
	}

	return false;
}

struct menuitem g_MpAddChangeSimulantMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x00000042, mpAddChangeSimulantMenuHandler },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextSimulantDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAddSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_101, // "Add Simulant"
	g_MpAddChangeSimulantMenuItems,
	NULL,
	0x00000011,
	NULL,
};

struct menudialog g_MpChangeSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_102, // "Change Simulant"
	g_MpAddChangeSimulantMenuItems,
	menudialogMpSimulant,
	0x00000011,
	NULL,
};

struct menuitem g_MpSimulantCharacterMenuItems[] = {
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x00000025, menuhandlerMpSimulantHead },
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x0000001b, menuhandlerMpSimulantBody },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSimulantCharacterMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_100, // "Simulant Character"
	g_MpSimulantCharacterMenuItems,
	menudialog0017ccfc,
	0x00000012,
	NULL,
};

struct menuitem g_MpEditSimulantMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU_095, 0x00000000, mpBotDifficultyMenuHandler }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_096, 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_097, 0x00000000, (void *)&g_MpSimulantCharacterMenuDialog }, // "Character..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_098, 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_099, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpEditSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleEditSimulant,
	g_MpEditSimulantMenuItems,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

struct menuitem g_MpSimulantsMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_084, 0x00000000, menuhandlerMpAddSimulant }, // "Add Simulant..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_085, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "1:"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_MPMENU_086, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "2:"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_MPMENU_087, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "3:"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, L_MPMENU_088, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "4:"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00000000, L_MPMENU_089, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "5:"
	{ MENUITEMTYPE_SELECTABLE,  5, 0x00000000, L_MPMENU_090, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "6:"
	{ MENUITEMTYPE_SELECTABLE,  6, 0x00000000, L_MPMENU_091, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "7:"
	{ MENUITEMTYPE_SELECTABLE,  7, 0x00000000, L_MPMENU_092, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "8:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_093, 0x00000000, menuhandlerMpClearAllSimulants }, // "Clear All"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_094, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSimulantsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_083, // "Simulants"
	g_MpSimulantsMenuItems,
	menudialogMpSimulants,
	0x00000010,
	NULL,
};

#if VERSION >= VERSION_NTSC_1_0
s32 menuhandlerMpNTeams(s32 operation, struct menuitem *item, union handlerdata *data, s32 numteams)
{
	if (operation == MENUOP_SET) {
		s32 numchrs = mpGetNumChrs();
		s32 array[] = {0, 0, 0, 0};
		s32 somevalue = (numchrs + numteams - 1) / numteams;
		s32 teamsremaining = numteams;
		s32 chrsremaining = numchrs;
		s32 start = random() % numchrs;

		s32 i;
		s32 teamnum;

		if (!numchrs) {
			return 0;
		}

		i = (start + 1) % numchrs;

		do {
			struct mpchrconfig *mpchr = mpGetChrConfigBySlotNum(i);

			if (teamsremaining);

			if (teamsremaining >= chrsremaining) {
				teamnum = random() % numteams;

				while (true) {
					if (array[teamnum] == 0) {
						mpchr->team = teamnum;

						array[teamnum]++;
						teamsremaining--;
						chrsremaining--;
						break;
					} else {
						teamnum = (teamnum + 1) % numteams;
					}
				}
			} else {
				teamnum = random() % numteams;

				while (true) {
					if (array[teamnum] < somevalue) {
						mpchr->team = teamnum;

						if (array[teamnum] == 0) {
							teamsremaining--;
						}

						array[teamnum]++;
						chrsremaining--;
						break;
					} else {
						teamnum = (teamnum + 1) % numteams;
					}
				}
			}

			if (i == start) {
				break;
			}

			i = (i + 1) % numchrs;
		} while (true);

		menuPopDialog();
	}

	return 0;
}
#else
u32 var800881f0nb[4] = {0};

GLOBAL_ASM(
glabel menuhandlerMpNTeams
/*  f177bd0:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f177bd4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f177bd8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f177bdc:	00e08025 */ 	or	$s0,$a3,$zero
/*  f177be0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f177be4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f177be8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f177bec:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f177bf0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f177bf4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f177bf8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f177bfc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f177c00:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f177c04:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f177c08:	1481008c */ 	bne	$a0,$at,.NB0f177e3c
/*  f177c0c:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f177c10:	0fc61aa0 */ 	jal	mpGetNumChrs
/*  f177c14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177c18:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f177c1c:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f177c20:	0110001a */ 	div	$zero,$t0,$s0
/*  f177c24:	3c0e8009 */ 	lui	$t6,0x8009
/*  f177c28:	25ce81f0 */ 	addiu	$t6,$t6,-32272
/*  f177c2c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f177c30:	27b10064 */ 	addiu	$s1,$sp,0x64
/*  f177c34:	00009012 */ 	mflo	$s2
/*  f177c38:	ae210000 */ 	sw	$at,0x0($s1)
/*  f177c3c:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  f177c40:	0040f025 */ 	or	$s8,$v0,$zero
/*  f177c44:	02009825 */ 	or	$s3,$s0,$zero
/*  f177c48:	ae380004 */ 	sw	$t8,0x4($s1)
/*  f177c4c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f177c50:	0040a025 */ 	or	$s4,$v0,$zero
/*  f177c54:	ae210008 */ 	sw	$at,0x8($s1)
/*  f177c58:	8dd8000c */ 	lw	$t8,0xc($t6)
/*  f177c5c:	ae38000c */ 	sw	$t8,0xc($s1)
/*  f177c60:	16000002 */ 	bnez	$s0,.NB0f177c6c
/*  f177c64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177c68:	0007000d */ 	break	0x7
.NB0f177c6c:
/*  f177c6c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f177c70:	16010004 */ 	bne	$s0,$at,.NB0f177c84
/*  f177c74:	3c018000 */ 	lui	$at,0x8000
/*  f177c78:	15010002 */ 	bne	$t0,$at,.NB0f177c84
/*  f177c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177c80:	0006000d */ 	break	0x6
.NB0f177c84:
/*  f177c84:	0c004d84 */ 	jal	random
/*  f177c88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177c8c:	005e001b */ 	divu	$zero,$v0,$s8
/*  f177c90:	00001810 */ 	mfhi	$v1
/*  f177c94:	24690001 */ 	addiu	$t1,$v1,0x1
/*  f177c98:	0060b825 */ 	or	$s7,$v1,$zero
/*  f177c9c:	013e001a */ 	div	$zero,$t1,$s8
/*  f177ca0:	0000a810 */ 	mfhi	$s5
/*  f177ca4:	17c00002 */ 	bnez	$s8,.NB0f177cb0
/*  f177ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177cac:	0007000d */ 	break	0x7
.NB0f177cb0:
/*  f177cb0:	17c00002 */ 	bnez	$s8,.NB0f177cbc
/*  f177cb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177cb8:	0007000d */ 	break	0x7
.NB0f177cbc:
/*  f177cbc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f177cc0:	17c10004 */ 	bne	$s8,$at,.NB0f177cd4
/*  f177cc4:	3c018000 */ 	lui	$at,0x8000
/*  f177cc8:	15210002 */ 	bne	$t1,$at,.NB0f177cd4
/*  f177ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177cd0:	0006000d */ 	break	0x6
.NB0f177cd4:
/*  f177cd4:	0fc61a7b */ 	jal	mpGetChrConfigBySlotNum
/*  f177cd8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f177cdc:	0274082a */ 	slt	$at,$s3,$s4
/*  f177ce0:	14200022 */ 	bnez	$at,.NB0f177d6c
/*  f177ce4:	0040b025 */ 	or	$s6,$v0,$zero
/*  f177ce8:	0c004d84 */ 	jal	random
/*  f177cec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177cf0:	0050001b */ 	divu	$zero,$v0,$s0
/*  f177cf4:	00001810 */ 	mfhi	$v1
/*  f177cf8:	16000002 */ 	bnez	$s0,.NB0f177d04
/*  f177cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177d00:	0007000d */ 	break	0x7
.NB0f177d04:
/*  f177d04:	00035080 */ 	sll	$t2,$v1,0x2
.NB0f177d08:
/*  f177d08:	022a1021 */ 	addu	$v0,$s1,$t2
/*  f177d0c:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f177d10:	55600009 */ 	bnezl	$t3,.NB0f177d38
/*  f177d14:	246f0001 */ 	addiu	$t7,$v1,0x1
/*  f177d18:	a2c30011 */ 	sb	$v1,0x11($s6)
/*  f177d1c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f177d20:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f177d24:	2694ffff */ 	addiu	$s4,$s4,-1
/*  f177d28:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f177d2c:	10000032 */ 	beqz	$zero,.NB0f177df8
/*  f177d30:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f177d34:	246f0001 */ 	addiu	$t7,$v1,0x1
.NB0f177d38:
/*  f177d38:	01f0001a */ 	div	$zero,$t7,$s0
/*  f177d3c:	00001810 */ 	mfhi	$v1
/*  f177d40:	16000002 */ 	bnez	$s0,.NB0f177d4c
/*  f177d44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177d48:	0007000d */ 	break	0x7
.NB0f177d4c:
/*  f177d4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f177d50:	16010004 */ 	bne	$s0,$at,.NB0f177d64
/*  f177d54:	3c018000 */ 	lui	$at,0x8000
/*  f177d58:	15e10002 */ 	bne	$t7,$at,.NB0f177d64
/*  f177d5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177d60:	0006000d */ 	break	0x6
.NB0f177d64:
/*  f177d64:	1000ffe8 */ 	beqz	$zero,.NB0f177d08
/*  f177d68:	00035080 */ 	sll	$t2,$v1,0x2
.NB0f177d6c:
/*  f177d6c:	0c004d84 */ 	jal	random
/*  f177d70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177d74:	0050001b */ 	divu	$zero,$v0,$s0
/*  f177d78:	00001810 */ 	mfhi	$v1
/*  f177d7c:	16000002 */ 	bnez	$s0,.NB0f177d88
/*  f177d80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177d84:	0007000d */ 	break	0x7
.NB0f177d88:
/*  f177d88:	00037080 */ 	sll	$t6,$v1,0x2
.NB0f177d8c:
/*  f177d8c:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f177d90:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f177d94:	0312082a */ 	slt	$at,$t8,$s2
/*  f177d98:	5020000a */ 	beqzl	$at,.NB0f177dc4
/*  f177d9c:	24680001 */ 	addiu	$t0,$v1,0x1
/*  f177da0:	a2c30011 */ 	sb	$v1,0x11($s6)
/*  f177da4:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f177da8:	2694ffff */ 	addiu	$s4,$s4,-1
/*  f177dac:	14800002 */ 	bnez	$a0,.NB0f177db8
/*  f177db0:	24990001 */ 	addiu	$t9,$a0,0x1
/*  f177db4:	2673ffff */ 	addiu	$s3,$s3,-1
.NB0f177db8:
/*  f177db8:	1000000f */ 	beqz	$zero,.NB0f177df8
/*  f177dbc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f177dc0:	24680001 */ 	addiu	$t0,$v1,0x1
.NB0f177dc4:
/*  f177dc4:	0110001a */ 	div	$zero,$t0,$s0
/*  f177dc8:	00001810 */ 	mfhi	$v1
/*  f177dcc:	16000002 */ 	bnez	$s0,.NB0f177dd8
/*  f177dd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177dd4:	0007000d */ 	break	0x7
.NB0f177dd8:
/*  f177dd8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f177ddc:	16010004 */ 	bne	$s0,$at,.NB0f177df0
/*  f177de0:	3c018000 */ 	lui	$at,0x8000
/*  f177de4:	15010002 */ 	bne	$t0,$at,.NB0f177df0
/*  f177de8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177dec:	0006000d */ 	break	0x6
.NB0f177df0:
/*  f177df0:	1000ffe6 */ 	beqz	$zero,.NB0f177d8c
/*  f177df4:	00037080 */ 	sll	$t6,$v1,0x2
.NB0f177df8:
/*  f177df8:	12b7000e */ 	beq	$s5,$s7,.NB0f177e34
/*  f177dfc:	26a90001 */ 	addiu	$t1,$s5,0x1
/*  f177e00:	013e001a */ 	div	$zero,$t1,$s8
/*  f177e04:	0000a810 */ 	mfhi	$s5
/*  f177e08:	17c00002 */ 	bnez	$s8,.NB0f177e14
/*  f177e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177e10:	0007000d */ 	break	0x7
.NB0f177e14:
/*  f177e14:	2401ffff */ 	addiu	$at,$zero,-1
/*  f177e18:	17c10004 */ 	bne	$s8,$at,.NB0f177e2c
/*  f177e1c:	3c018000 */ 	lui	$at,0x8000
/*  f177e20:	15210002 */ 	bne	$t1,$at,.NB0f177e2c
/*  f177e24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177e28:	0006000d */ 	break	0x6
.NB0f177e2c:
/*  f177e2c:	1000ffa9 */ 	beqz	$zero,.NB0f177cd4
/*  f177e30:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f177e34:
/*  f177e34:	0fc3c088 */ 	jal	menuPopDialog
/*  f177e38:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f177e3c:
/*  f177e3c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f177e40:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f177e44:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f177e48:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f177e4c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f177e50:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f177e54:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f177e58:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f177e5c:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f177e60:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f177e64:	27bd0078 */ 	addiu	$sp,$sp,0x78
/*  f177e68:	03e00008 */ 	jr	$ra
/*  f177e6c:	00001025 */ 	or	$v0,$zero,$zero
);
#endif

s32 menuhandlerMpTwoTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 2);
}

s32 menuhandlerMpThreeTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 3);
}

s32 menuhandlerMpFourTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 4);
}

s32 menuhandlerMpMaximumTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		u8 team = 0;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *mpchr = MPCHR(i);

				mpchr->team = team++;

				if (team >= scenarioGetMaxTeams()) {
					team = 0;
				}
			}
		}

		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerMpHumansVsSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *mpchr = MPCHR(i);

				mpchr->team = i < 4 ? 0 : 1;
			}
		}

		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerMpHumanSimulantPairs(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		u8 team_ids[4] = {0, 1, 2, 3};
		s32 i;
		s32 playerindex = 0;
		s32 simindex = 0;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *mpchr = MPCHR(i);

				if (i < 4) {
					mpchr->team = team_ids[playerindex++];
				} else {
					mpchr->team = team_ids[simindex++];

					if (simindex >= playerindex) {
						simindex = 0;
					}
				}
			}
		}

		menuPopDialog();
	}

	return 0;
}

char *mpMenuTextChrNameForTeamSetup(struct menuitem *item)
{
	struct mpchrconfig *mpchr = mpGetChrConfigBySlotNum(item->param);

	if (mpchr) {
		return mpchr->name;
	}

	return "";
}

s32 func0f17dac4(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = scenarioGetMaxTeams();
		break;
	case MENUOP_GETOPTIONTEXT:
		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) {
			return (s32) "\n";
		}

		return (s32) g_BossFile.teamnames[data->list.value];
	}

	return menuhandlerMpTeamsLabel(operation, item, data);
}

s32 menuhandlerMpTeamSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct mpchrconfig *mpchr;

	switch (operation) {
	case MENUOP_SET:
		mpchr = mpGetChrConfigBySlotNum(item->param);
		mpchr->team = data->dropdown.value;
		break;
	case MENUOP_GETOPTIONVALUE:
		mpchr = mpGetChrConfigBySlotNum(item->param);

		if (!mpchr) {
			data->dropdown.value = 0xff;
		} else {
			data->dropdown.value = mpchr->team;
		}

		break;
	case MENUOP_CHECKDISABLED:
		mpchr = mpGetChrConfigBySlotNum(item->param);

		if (!mpchr) {
			return 1;
		}

		return menuhandlerMpTeamsLabel(operation, item, data);
	}

	return func0f17dac4(operation, item, data);
}

char *mpMenuTextSelectTuneOrTunes(struct menuitem *item)
{
	if (mpGetUsingMultipleTunes()) {
		return langGet(L_MPMENU_069); // "Select Tune"
	}

	return langGet(L_MPMENU_068); // "Select Tunes"
}

struct menuitem g_MpAutoTeamMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_076, 0x00000000, menuhandlerMpTwoTeams }, // "Two Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_077, 0x00000000, menuhandlerMpThreeTeams }, // "Three Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_078, 0x00000000, menuhandlerMpFourTeams }, // "Four Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_079, 0x00000000, menuhandlerMpMaximumTeams }, // "Maximum Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_080, 0x00000000, menuhandlerMpHumansVsSimulants }, // "Humans vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_081, 0x00000000, menuhandlerMpHumanSimulantPairs }, // "Human-Simulant Pairs"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_082, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAutoTeamMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_075, // "Auto Team"
	g_MpAutoTeamMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpTeamsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,     0, 0x00020000, L_MPMENU_071, 0x00000002, menuhandlerMpTeamsEnabled }, // "Teams Enabled"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, PAL ? 0x85 : 0, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,        0, 0x00000010, L_MPMENU_072, 0x00000000, menuhandlerMpTeamsLabel }, // "Teams:"
	{ MENUITEMTYPE_DROPDOWN,     0, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     1, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     2, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     3, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     4, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     5, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     6, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     7, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     8, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     9, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    10, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    11, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000004, L_MPMENU_073, 0x00000000, (void *)&g_MpAutoTeamMenuDialog }, // "Auto Team..."
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000008, L_MPMENU_074, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpTeamsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_070, // "Team Control"
	g_MpTeamsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

u32 var80085ce8[] = {
	L_MISC_166, // "Random"
	L_MISC_167, // "Select All"
	L_MISC_168, // "Select None"
	L_MISC_169, // "Randomize"
};

/**
 * List handler for the select tune dialog.
 *
 * If multiple tracks are disabled, the listing contains the track listing plus
 * one item for Randomize.
 *
 * If multiple tracks are disabled, the listing contains the track listing plus
 * 3 items for Select All, Select None and Randomize.
 */
s32 mpSelectTuneListHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = mpGetNumUnlockedTracks();

		if (mpGetUsingMultipleTunes()) {
			data->list.value += 3;
		} else {
			data->list.value++;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		{
			s32 numtracks = mpGetNumUnlockedTracks();

			if (data->list.value < numtracks) {
				return (s32) mpGetTrackName(data->list.value);
			}

			if (mpGetUsingMultipleTunes()) {
				return (s32) langGet(var80085ce8[1 + data->list.value - numtracks]);
			}

			return (s32) langGet(var80085ce8[data->list.value - numtracks]);
		}
	case MENUOP_SET:
		{
			s32 numtracks = mpGetNumUnlockedTracks();

			if (data->list.value < numtracks) {
				if (data->list.unk04 == 0) {
					mpSetTrackSlotEnabled(data->list.value);
				}
				g_Vars.modifiedfiles |= MODFILE_MPSETUP;
			} else if (mpGetUsingMultipleTunes()) {
				s32 index = data->list.value - numtracks;

				switch (index) {
				case 0:
					mpEnableAllMultiTracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				case 1:
					mpDisableAllMultiTracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				case 2:
					mpRandomiseMultiTracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				}
			} else {
				mpSetTrackToRandom();
				g_Vars.modifiedfiles |= MODFILE_MPSETUP;
			}
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		if (mpGetUsingMultipleTunes()) {
			data->list.value = 0x000fffff;
		} else {
			s32 slotnum = mpGetCurrentTrackSlotNum();

			if (slotnum < 0) {
				data->list.value = mpGetNumUnlockedTracks();
			} else {
				data->list.value = slotnum;
			}
		}
		break;
	case MENUOP_LISTITEMFOCUS:
		if (data->list.value < mpGetNumUnlockedTracks()) {
			musicStartTrackAsMenu(mpGetTrackMusicNum(data->list.value));
		}
		break;
	case MENUOP_GETLISTITEMCHECKBOX:
		{
			s32 numtracks = mpGetNumUnlockedTracks();

			if (mpGetUsingMultipleTunes() && data->list.value < numtracks) {
				data->list.unk04 = mpIsMultiTrackSlotEnabled(data->list.value);
			}
		}
		break;
	}

	return 0;
}

s32 menudialogMpSelectTune(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		var800840e0 = 80;
	}

	if (operation == MENUOP_CLOSE) {
		var800840e0 = 15;
	}

	return false;
}

char *mpMenuTextCurrentTrack(struct menuitem *item)
{
	s32 slotnum;

	if (mpGetUsingMultipleTunes()) {
		return langGet(L_MPMENU_066); // "Multiple Tunes"
	}

	slotnum = mpGetCurrentTrackSlotNum();

	if (slotnum >= 0) {
		return mpGetTrackName(slotnum);
	}

	return langGet(L_MPMENU_067); // "Random"
}

s32 menuhandlerMpMultipleTunes(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		return mpGetUsingMultipleTunes();
	case MENUOP_SET:
		mpSetUsingMultipleTunes(data->checkbox.value);
		g_Vars.modifiedfiles |= MODFILE_MPSETUP;
	}

	return 0;
}

s32 mpTeamNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;
	s32 i;

	switch (operation) {
	case MENUOP_GETTEXT:
		i = 0;

		while (g_BossFile.teamnames[g_Menus[g_MpPlayerNum].mpsetup.slotindex][i] != '\n'
				&& g_BossFile.teamnames[g_Menus[g_MpPlayerNum].mpsetup.slotindex][i] != '\0'
				&& i < 11) {
			name[i] = g_BossFile.teamnames[g_Menus[g_MpPlayerNum].mpsetup.slotindex][i];
			i++;
		}

		while (i < 11) {
			name[i] = '\0';
			i++;
		}
		break;
	case MENUOP_SETTEXT:
		i = 0;

		while (i < 11 && name[i] != '\0') {
			g_BossFile.teamnames[g_Menus[g_MpPlayerNum].mpsetup.slotindex][i] = name[i];
			i++;
		}

		g_BossFile.teamnames[g_Menus[g_MpPlayerNum].mpsetup.slotindex][i] = '\n';
		i++;

		while (i < 11) {
			g_BossFile.teamnames[g_Menus[g_MpPlayerNum].mpsetup.slotindex][i] = '\0';
			i++;
		}

		g_Vars.modifiedfiles |= MODFILE_MPSETUP;
		break;
	}

	return 0;
}

/**
 * item->param2 is a text ID for that team's colour. The text IDs for team
 * colours are consecutive, so the index of the team is determined by
 * subtracting the first team's colour text ID.
 */
char *mpMenuTextTeamName(struct menuitem *item)
{
	s32 index = item->param2;
	index -= L_OPTIONS_008;

	return g_BossFile.teamnames[index];
}

s32 menuhandlerMpTeamNameSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = item->param2 - 0x5608;
		menuPushDialog(&g_MpChangeTeamNameMenuDialog);
	}

	return 0;
}

char *func0f17e318(struct menudialog *dialog)
{
	sprintf(g_StringPointer, langGet(L_MPMENU_056), mpGetChallengeNameBySlot(g_Menus[g_MpPlayerNum].mpsetup.slotindex));
	return g_StringPointer;
}

/**
 * An "Accept" item somewhere. Probably accepting a challenge.
 */
s32 menuhandler0017e38c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
#if VERSION >= VERSION_NTSC_1_0
		mpClearCurrentChallenge();
#endif

		menuPopDialog();
		mpSetCurrentChallenge(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
	}

	return 0;
}

s32 menudialog0017e3fc(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		g_Menus[g_MpPlayerNum].unk850 = 0;

		g_Menus[g_MpPlayerNum].training.mpconfig = mpGetNthAvailableChallengeSomething(
				g_Menus[g_MpPlayerNum].training.unke1c,
				g_Menus[g_MpPlayerNum].mpconfigbuffer,
				g_Menus[g_MpPlayerNum].mpconfigbufferlen);
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
			menuPopDialog();
		}
		break;
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuhandler0017e4d4
.late_rodata
glabel var7f1b822c
.word menuhandler0017e4d4+0x6c # f17e540
glabel var7f1b8230
.word menuhandler0017e4d4+0x12c # f17e600
glabel var7f1b8234
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8238
.word menuhandler0017e4d4+0x134 # f17e608
glabel var7f1b823c
.word menuhandler0017e4d4+0x13c # f17e610
glabel var7f1b8240
.word menuhandler0017e4d4+0x7c # f17e550
glabel var7f1b8244
.word menuhandler0017e4d4+0x11c # f17e5f0
glabel var7f1b8248
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b824c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8250
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8254
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8258
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b825c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8260
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8264
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8268
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b826c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8270
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8274
.word menuhandler0017e4d4+0x144 # f17e618
glabel var7f1b8278
.word menuhandler0017e4d4+0x4cc # f17e9a0
glabel var7f1b827c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8280
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8284
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8288
.word menuhandler0017e4d4+0x50 # f17e524
.text
/*  f17e4d4:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f17e4d8:	248effff */ 	addiu	$t6,$a0,-1
/*  f17e4dc:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f17e4e0:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f17e4e4:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f17e4e8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f17e4ec:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f17e4f0:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f17e4f4:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f17e4f8:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f17e4fc:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f17e500:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f17e504:	10200128 */ 	beqz	$at,.L0f17e9a8
/*  f17e508:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f17e50c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17e510:	3c017f1c */ 	lui	$at,%hi(var7f1b822c)
/*  f17e514:	002e0821 */ 	addu	$at,$at,$t6
/*  f17e518:	8c2e822c */ 	lw	$t6,%lo(var7f1b822c)($at)
/*  f17e51c:	01c00008 */ 	jr	$t6
/*  f17e520:	00000000 */ 	nop
/*  f17e524:	3c0f800b */ 	lui	$t7,%hi(g_MpSetup+0x88)
/*  f17e528:	91efcc10 */ 	lbu	$t7,%lo(g_MpSetup+0x88)($t7)
/*  f17e52c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17e530:	55e1011e */ 	bnel	$t7,$at,.L0f17e9ac
/*  f17e534:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e538:	1000011c */ 	b	.L0f17e9ac
/*  f17e53c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17e540:	0fc66d99 */ 	jal	mpGetNumAvailableChallenges
/*  f17e544:	00000000 */ 	nop
/*  f17e548:	10000117 */ 	b	.L0f17e9a8
/*  f17e54c:	aec20000 */ 	sw	$v0,0x0($s6)
/*  f17e550:	8ed80004 */ 	lw	$t8,0x4($s6)
/*  f17e554:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f17e558:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f17e55c:	13000002 */ 	beqz	$t8,.L0f17e568
/*  f17e560:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f17e564:	aed90004 */ 	sw	$t9,0x4($s6)
.L0f17e568:
/*  f17e568:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f17e56c:	8ecb0000 */ 	lw	$t3,0x0($s6)
/*  f17e570:	3c01800a */ 	lui	$at,%hi(g_Menus+0xe1c)
/*  f17e574:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17e578:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17e57c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17e580:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17e584:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17e588:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17e58c:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17e590:	002d0821 */ 	addu	$at,$at,$t5
/*  f17e594:	ac2bee1c */ 	sw	$t3,%lo(g_Menus+0xe1c)($at)
/*  f17e598:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f17e59c:	3c048008 */ 	lui	$a0,%hi(g_MpConfirmChallengeViaListOrDetailsMenuDialog)
/*  f17e5a0:	15c00005 */ 	bnez	$t6,.L0f17e5b8
/*  f17e5a4:	00000000 */ 	nop
/*  f17e5a8:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5ac:	24845f88 */ 	addiu	$a0,$a0,%lo(g_MpConfirmChallengeViaListOrDetailsMenuDialog)
/*  f17e5b0:	100000fe */ 	b	.L0f17e9ac
/*  f17e5b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e5b8:
/*  f17e5b8:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f17e5bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17e5c0:	3c048008 */ 	lui	$a0,%hi(g_MpConfirmChallengeMenuDialog)
/*  f17e5c4:	15e10006 */ 	bne	$t7,$at,.L0f17e5e0
/*  f17e5c8:	00000000 */ 	nop
/*  f17e5cc:	3c048007 */ 	lui	$a0,%hi(g_MpConfirmChallenge4MbMenuDialog)
/*  f17e5d0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5d4:	2484519c */ 	addiu	$a0,$a0,%lo(g_MpConfirmChallenge4MbMenuDialog)
/*  f17e5d8:	100000f4 */ 	b	.L0f17e9ac
/*  f17e5dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e5e0:
/*  f17e5e0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5e4:	248460ac */ 	addiu	$a0,$a0,%lo(g_MpConfirmChallengeMenuDialog)
/*  f17e5e8:	100000f0 */ 	b	.L0f17e9ac
/*  f17e5ec:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e5f0:	3c18000f */ 	lui	$t8,0xf
/*  f17e5f4:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f17e5f8:	100000eb */ 	b	.L0f17e9a8
/*  f17e5fc:	aed80000 */ 	sw	$t8,0x0($s6)
/*  f17e600:	100000e9 */ 	b	.L0f17e9a8
/*  f17e604:	aec00000 */ 	sw	$zero,0x0($s6)
/*  f17e608:	100000e8 */ 	b	.L0f17e9ac
/*  f17e60c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e610:	100000e5 */ 	b	.L0f17e9a8
/*  f17e614:	aec00008 */ 	sw	$zero,0x8($s6)
/*  f17e618:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f17e61c:	3c0c8009 */ 	lui	$t4,%hi(g_Is4Mb)
/*  f17e620:	918c0af0 */ 	lbu	$t4,%lo(g_Is4Mb)($t4)
/*  f17e624:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17e628:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f17e62c:	8ed00008 */ 	lw	$s0,0x8($s6)
/*  f17e630:	2413000a */ 	addiu	$s3,$zero,0xa
/*  f17e634:	15810002 */ 	bne	$t4,$at,.L0f17e640
/*  f17e638:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f17e63c:	24170002 */ 	addiu	$s7,$zero,0x2
.L0f17e640:
/*  f17e640:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f17e644:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f17e648:	256d000a */ 	addiu	$t5,$t3,0xa
/*  f17e64c:	afad00ac */ 	sw	$t5,0xac($sp)
/*  f17e650:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f17e654:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f17e658:	0fc54d8a */ 	jal	func0f153628
/*  f17e65c:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*  f17e660:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f17e664:	0fc66dbe */ 	jal	mpGetChallengeNameBySlot
/*  f17e668:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f17e66c:	0c002f02 */ 	jal	viGetWidth
/*  f17e670:	00408825 */ 	or	$s1,$v0,$zero
/*  f17e674:	00029400 */ 	sll	$s2,$v0,0x10
/*  f17e678:	0012c403 */ 	sra	$t8,$s2,0x10
/*  f17e67c:	0c002f06 */ 	jal	viGetHeight
/*  f17e680:	03009025 */ 	or	$s2,$t8,$zero
/*  f17e684:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicSm)
/*  f17e688:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm)
/*  f17e68c:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm)($t4)
/*  f17e690:	8f39fb10 */ 	lw	$t9,%lo(g_CharsHandelGothicSm)($t9)
/*  f17e694:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f17e698:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f17e69c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f17e6a0:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f17e6a4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f17e6a8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f17e6ac:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f17e6b0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f17e6b4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f17e6b8:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f17e6bc:	02203825 */ 	or	$a3,$s1,$zero
/*  f17e6c0:	0fc5580f */ 	jal	textRenderProjected
/*  f17e6c4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f17e6c8:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f17e6cc:	0fc54de0 */ 	jal	func0f153780
/*  f17e6d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f17e6d4:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f17e6d8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e6dc:	3c0ee700 */ 	lui	$t6,0xe700
/*  f17e6e0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f17e6e4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f17e6e8:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e6ec:	3c19ba00 */ 	lui	$t9,0xba00
/*  f17e6f0:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f17e6f4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e6f8:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e6fc:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f17e700:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17e704:	8fac00b4 */ 	lw	$t4,0xb4($sp)
/*  f17e708:	3c0db900 */ 	lui	$t5,0xb900
/*  f17e70c:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f17e710:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f17e714:	afab00b4 */ 	sw	$t3,0xb4($sp)
/*  f17e718:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f17e71c:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*  f17e720:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f17e724:	3c18ba00 */ 	lui	$t8,0xba00
/*  f17e728:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f17e72c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f17e730:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f17e734:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f17e738:	add80000 */ 	sw	$t8,0x0($t6)
/*  f17e73c:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f17e740:	3c0bba00 */ 	lui	$t3,0xba00
/*  f17e744:	356b0903 */ 	ori	$t3,$t3,0x903
/*  f17e748:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f17e74c:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f17e750:	240d0c00 */ 	addiu	$t5,$zero,0xc00
/*  f17e754:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f17e758:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f17e75c:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f17e760:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f17e764:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f17e768:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f17e76c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f17e770:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f17e774:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17e778:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f17e77c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17e780:	00003825 */ 	or	$a3,$zero,$zero
/*  f17e784:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f17e788:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f17e78c:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f17e790:	3c0cba00 */ 	lui	$t4,0xba00
/*  f17e794:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f17e798:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f17e79c:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f17e7a0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f17e7a4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f17e7a8:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e7ac:	3c0eba00 */ 	lui	$t6,0xba00
/*  f17e7b0:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f17e7b4:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17e7b8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e7bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e7c0:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f17e7c4:	1ae00074 */ 	blez	$s7,.L0f17e998
/*  f17e7c8:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f17e7cc:	3c128008 */ 	lui	$s2,%hi(g_ScaleX)
/*  f17e7d0:	2652fac0 */ 	addiu	$s2,$s2,%lo(g_ScaleX)
/*  f17e7d4:	241500ff */ 	addiu	$s5,$zero,0xff
/*  f17e7d8:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f17e7dc:	24510001 */ 	addiu	$s1,$v0,0x1
.L0f17e7e0:
/*  f17e7e0:	02202825 */ 	or	$a1,$s1,$zero
/*  f17e7e4:	0fc66e00 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayersBySlot
/*  f17e7e8:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f17e7ec:	1040000f */ 	beqz	$v0,.L0f17e82c
/*  f17e7f0:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e7f4:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e7f8:	3c01ffe5 */ 	lui	$at,0xffe5
/*  f17e7fc:	34216500 */ 	ori	$at,$at,0x6500
/*  f17e800:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e804:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e808:	adf40000 */ 	sw	$s4,0x0($t7)
/*  f17e80c:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f17e810:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f17e814:	01950019 */ 	multu	$t4,$s5
/*  f17e818:	00005812 */ 	mflo	$t3
/*  f17e81c:	000b6a02 */ 	srl	$t5,$t3,0x8
/*  f17e820:	01a17025 */ 	or	$t6,$t5,$at
/*  f17e824:	1000000c */ 	b	.L0f17e858
/*  f17e828:	adee0004 */ 	sw	$t6,0x4($t7)
.L0f17e82c:
/*  f17e82c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e830:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e834:	adf40000 */ 	sw	$s4,0x0($t7)
/*  f17e838:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f17e83c:	3c014343 */ 	lui	$at,0x4343
/*  f17e840:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f17e844:	01950019 */ 	multu	$t4,$s5
/*  f17e848:	00005812 */ 	mflo	$t3
/*  f17e84c:	000b6a02 */ 	srl	$t5,$t3,0x8
/*  f17e850:	01a17025 */ 	or	$t6,$t5,$at
/*  f17e854:	adee0004 */ 	sw	$t6,0x4($t7)
.L0f17e858:
/*  f17e858:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e85c:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f17e860:	3c0cff37 */ 	lui	$t4,0xff37
/*  f17e864:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e868:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e86c:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f17e870:	37399a25 */ 	ori	$t9,$t9,0x9a25
/*  f17e874:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17e878:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f17e87c:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e880:	01e01025 */ 	or	$v0,$t7,$zero
/*  f17e884:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f17e888:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17e88c:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e890:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f17e894:	01601825 */ 	or	$v1,$t3,$zero
/*  f17e898:	3c01e400 */ 	lui	$at,0xe400
/*  f17e89c:	01d37821 */ 	addu	$t7,$t6,$s3
/*  f17e8a0:	25f8000b */ 	addiu	$t8,$t7,0xb
/*  f17e8a4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8a8:	032c0019 */ 	multu	$t9,$t4
/*  f17e8ac:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f17e8b0:	02201025 */ 	or	$v0,$s1,$zero
/*  f17e8b4:	27190016 */ 	addiu	$t9,$t8,0x16
/*  f17e8b8:	00196080 */ 	sll	$t4,$t9,0x2
/*  f17e8bc:	00005812 */ 	mflo	$t3
/*  f17e8c0:	316d0fff */ 	andi	$t5,$t3,0xfff
/*  f17e8c4:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f17e8c8:	01c17825 */ 	or	$t7,$t6,$at
/*  f17e8cc:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f17e8d0:	01eb6825 */ 	or	$t5,$t7,$t3
/*  f17e8d4:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f17e8d8:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f17e8dc:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f17e8e0:	01d3c021 */ 	addu	$t8,$t6,$s3
/*  f17e8e4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8e8:	032c0019 */ 	multu	$t9,$t4
/*  f17e8ec:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f17e8f0:	2673000d */ 	addiu	$s3,$s3,0xd
/*  f17e8f4:	25d8000b */ 	addiu	$t8,$t6,0xb
/*  f17e8f8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8fc:	332c0fff */ 	andi	$t4,$t9,0xfff
/*  f17e900:	24190160 */ 	addiu	$t9,$zero,0x160
/*  f17e904:	3c18b400 */ 	lui	$t8,0xb400
/*  f17e908:	00007812 */ 	mflo	$t7
/*  f17e90c:	31eb0fff */ 	andi	$t3,$t7,0xfff
/*  f17e910:	000b6b00 */ 	sll	$t5,$t3,0xc
/*  f17e914:	01ac7825 */ 	or	$t7,$t5,$t4
/*  f17e918:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f17e91c:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e920:	3c0fb300 */ 	lui	$t7,0xb300
/*  f17e924:	256e0008 */ 	addiu	$t6,$t3,0x8
/*  f17e928:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f17e92c:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f17e930:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f17e934:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f17e938:	01602025 */ 	or	$a0,$t3,$zero
/*  f17e93c:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f17e940:	25ac0008 */ 	addiu	$t4,$t5,0x8
/*  f17e944:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f17e948:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f17e94c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f17e950:	01a02825 */ 	or	$a1,$t5,$zero
/*  f17e954:	01cb001a */ 	div	$zero,$t6,$t3
/*  f17e958:	0000c012 */ 	mflo	$t8
/*  f17e95c:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f17e960:	00196c00 */ 	sll	$t5,$t9,0x10
/*  f17e964:	35acfc00 */ 	ori	$t4,$t5,0xfc00
/*  f17e968:	15600002 */ 	bnez	$t3,.L0f17e974
/*  f17e96c:	00000000 */ 	nop
/*  f17e970:	0007000d */ 	break	0x7
.L0f17e974:
/*  f17e974:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17e978:	15610004 */ 	bne	$t3,$at,.L0f17e98c
/*  f17e97c:	3c018000 */ 	lui	$at,0x8000
/*  f17e980:	15c10002 */ 	bne	$t6,$at,.L0f17e98c
/*  f17e984:	00000000 */ 	nop
/*  f17e988:	0006000d */ 	break	0x6
.L0f17e98c:
/*  f17e98c:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f17e990:	5637ff93 */ 	bnel	$s1,$s7,.L0f17e7e0
/*  f17e994:	24510001 */ 	addiu	$s1,$v0,0x1
.L0f17e998:
/*  f17e998:	10000004 */ 	b	.L0f17e9ac
/*  f17e99c:	8fa200b4 */ 	lw	$v0,0xb4($sp)
/*  f17e9a0:	240f001a */ 	addiu	$t7,$zero,0x1a
/*  f17e9a4:	aecf0000 */ 	sw	$t7,0x0($s6)
.L0f17e9a8:
/*  f17e9a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e9ac:
/*  f17e9ac:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f17e9b0:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f17e9b4:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f17e9b8:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f17e9bc:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f17e9c0:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f17e9c4:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f17e9c8:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f17e9cc:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f17e9d0:	03e00008 */ 	jr	$ra
/*  f17e9d4:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);
#else
GLOBAL_ASM(
glabel menuhandler0017e4d4
.late_rodata
glabel var7f1b2b20nb
.word menuhandler0017e4d4+0x068
glabel var7f1b2b24nb
.word menuhandler0017e4d4+0x128
glabel var7f1b2b28nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b2cnb
.word menuhandler0017e4d4+0x130
glabel var7f1b2b30nb
.word menuhandler0017e4d4+0x138
glabel var7f1b2b34nb
.word menuhandler0017e4d4+0x078
glabel var7f1b2b38nb
.word menuhandler0017e4d4+0x118
glabel var7f1b2b3cnb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b40nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b44nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b48nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b4cnb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b50nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b54nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b58nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b5cnb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b60nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b64nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b68nb
.word menuhandler0017e4d4+0x140
glabel var7f1b2b6cnb
.word menuhandler0017e4d4+0x498
glabel var7f1b2b70nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b74nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b78nb
.word menuhandler0017e4d4+0x4a0
glabel var7f1b2b7cnb
.word menuhandler0017e4d4+0x04c
.text
/*  f178bdc:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f178be0:	248effff */ 	addiu	$t6,$a0,-1
/*  f178be4:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f178be8:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f178bec:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f178bf0:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f178bf4:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f178bf8:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f178bfc:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f178c00:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f178c04:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f178c08:	1020011c */ 	beqz	$at,.NB0f17907c
/*  f178c0c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f178c10:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f178c14:	3c017f1b */ 	lui	$at,0x7f1b
/*  f178c18:	002e0821 */ 	addu	$at,$at,$t6
/*  f178c1c:	8c2e2b20 */ 	lw	$t6,0x2b20($at)
/*  f178c20:	01c00008 */ 	jr	$t6
/*  f178c24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178c28:	3c0f800b */ 	lui	$t7,0x800b
/*  f178c2c:	91ef14c0 */ 	lbu	$t7,0x14c0($t7)
/*  f178c30:	24010005 */ 	addiu	$at,$zero,0x5
/*  f178c34:	55e10112 */ 	bnel	$t7,$at,.NB0f179080
/*  f178c38:	00001025 */ 	or	$v0,$zero,$zero
/*  f178c3c:	10000110 */ 	beqz	$zero,.NB0f179080
/*  f178c40:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f178c44:	0fc655bf */ 	jal	mpGetNumAvailableChallenges
/*  f178c48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178c4c:	1000010b */ 	beqz	$zero,.NB0f17907c
/*  f178c50:	aea20000 */ 	sw	$v0,0x0($s5)
/*  f178c54:	8eb80004 */ 	lw	$t8,0x4($s5)
/*  f178c58:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f178c5c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f178c60:	13000002 */ 	beqz	$t8,.NB0f178c6c
/*  f178c64:	3c0f8009 */ 	lui	$t7,0x8009
/*  f178c68:	aeb90004 */ 	sw	$t9,0x4($s5)
.NB0f178c6c:
/*  f178c6c:	8d8c3af0 */ 	lw	$t4,0x3af0($t4)
/*  f178c70:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f178c74:	3c01800a */ 	lui	$at,0x800a
/*  f178c78:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f178c7c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f178c80:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f178c84:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f178c88:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f178c8c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f178c90:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f178c94:	002d0821 */ 	addu	$at,$at,$t5
/*  f178c98:	ac2b3538 */ 	sw	$t3,0x3538($at)
/*  f178c9c:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f178ca0:	3c048009 */ 	lui	$a0,0x8009
/*  f178ca4:	15c00005 */ 	bnez	$t6,.NB0f178cbc
/*  f178ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178cac:	0fc3beda */ 	jal	menuPushDialog
/*  f178cb0:	24848704 */ 	addiu	$a0,$a0,-30972
/*  f178cb4:	100000f2 */ 	beqz	$zero,.NB0f179080
/*  f178cb8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f178cbc:
/*  f178cbc:	91ef30e0 */ 	lbu	$t7,0x30e0($t7)
/*  f178cc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f178cc4:	3c048009 */ 	lui	$a0,0x8009
/*  f178cc8:	15e10006 */ 	bne	$t7,$at,.NB0f178ce4
/*  f178ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178cd0:	3c048007 */ 	lui	$a0,0x8007
/*  f178cd4:	0fc3beda */ 	jal	menuPushDialog
/*  f178cd8:	248475f8 */ 	addiu	$a0,$a0,0x75f8
/*  f178cdc:	100000e8 */ 	beqz	$zero,.NB0f179080
/*  f178ce0:	00001025 */ 	or	$v0,$zero,$zero
.NB0f178ce4:
/*  f178ce4:	0fc3beda */ 	jal	menuPushDialog
/*  f178ce8:	2484883c */ 	addiu	$a0,$a0,-30660
/*  f178cec:	100000e4 */ 	beqz	$zero,.NB0f179080
/*  f178cf0:	00001025 */ 	or	$v0,$zero,$zero
/*  f178cf4:	3c18000f */ 	lui	$t8,0xf
/*  f178cf8:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f178cfc:	100000df */ 	beqz	$zero,.NB0f17907c
/*  f178d00:	aeb80000 */ 	sw	$t8,0x0($s5)
/*  f178d04:	100000dd */ 	beqz	$zero,.NB0f17907c
/*  f178d08:	aea00000 */ 	sw	$zero,0x0($s5)
/*  f178d0c:	100000dc */ 	beqz	$zero,.NB0f179080
/*  f178d10:	00001025 */ 	or	$v0,$zero,$zero
/*  f178d14:	100000d9 */ 	beqz	$zero,.NB0f17907c
/*  f178d18:	aea00008 */ 	sw	$zero,0x8($s5)
/*  f178d1c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f178d20:	3c0c8009 */ 	lui	$t4,0x8009
/*  f178d24:	918c30e0 */ 	lbu	$t4,0x30e0($t4)
/*  f178d28:	24010001 */ 	addiu	$at,$zero,0x1
/*  f178d2c:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f178d30:	8eb20008 */ 	lw	$s2,0x8($s5)
/*  f178d34:	2413000a */ 	addiu	$s3,$zero,0xa
/*  f178d38:	15810002 */ 	bne	$t4,$at,.NB0f178d44
/*  f178d3c:	24160004 */ 	addiu	$s6,$zero,0x4
/*  f178d40:	24160002 */ 	addiu	$s6,$zero,0x2
.NB0f178d44:
/*  f178d44:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f178d48:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f178d4c:	256d000a */ 	addiu	$t5,$t3,0xa
/*  f178d50:	afad00ac */ 	sw	$t5,0xac($sp)
/*  f178d54:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f178d58:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f178d5c:	0fc5374a */ 	jal	func0f153628
/*  f178d60:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*  f178d64:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f178d68:	0fc655e4 */ 	jal	mpGetChallengeNameBySlot
/*  f178d6c:	8ea40004 */ 	lw	$a0,0x4($s5)
/*  f178d70:	0c002f77 */ 	jal	viGetWidth
/*  f178d74:	00408025 */ 	or	$s0,$v0,$zero
/*  f178d78:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f178d7c:	0011c403 */ 	sra	$t8,$s1,0x10
/*  f178d80:	0c002f7b */ 	jal	viGetHeight
/*  f178d84:	03008825 */ 	or	$s1,$t8,$zero
/*  f178d88:	3c198008 */ 	lui	$t9,0x8008
/*  f178d8c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f178d90:	8d8c236c */ 	lw	$t4,0x236c($t4)
/*  f178d94:	8f392370 */ 	lw	$t9,0x2370($t9)
/*  f178d98:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f178d9c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f178da0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f178da4:	8e4b000c */ 	lw	$t3,0xc($s2)
/*  f178da8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f178dac:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f178db0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f178db4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f178db8:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f178dbc:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f178dc0:	02003825 */ 	or	$a3,$s0,$zero
/*  f178dc4:	0fc541a6 */ 	jal	textRenderProjected
/*  f178dc8:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f178dcc:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f178dd0:	0fc537a0 */ 	jal	func0f153780
/*  f178dd4:	00402025 */ 	or	$a0,$v0,$zero
/*  f178dd8:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f178ddc:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f178de0:	3c0ee700 */ 	lui	$t6,0xe700
/*  f178de4:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f178de8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f178dec:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f178df0:	3c19ba00 */ 	lui	$t9,0xba00
/*  f178df4:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f178df8:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f178dfc:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f178e00:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f178e04:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f178e08:	8fac00b4 */ 	lw	$t4,0xb4($sp)
/*  f178e0c:	3c0db900 */ 	lui	$t5,0xb900
/*  f178e10:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f178e14:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f178e18:	afab00b4 */ 	sw	$t3,0xb4($sp)
/*  f178e1c:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f178e20:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*  f178e24:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f178e28:	3c18ba00 */ 	lui	$t8,0xba00
/*  f178e2c:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f178e30:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f178e34:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f178e38:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f178e3c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f178e40:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f178e44:	3c0bba00 */ 	lui	$t3,0xba00
/*  f178e48:	356b0903 */ 	ori	$t3,$t3,0x903
/*  f178e4c:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f178e50:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f178e54:	240d0c00 */ 	addiu	$t5,$zero,0xc00
/*  f178e58:	3c05800b */ 	lui	$a1,0x800b
/*  f178e5c:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f178e60:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f178e64:	8ca5fe58 */ 	lw	$a1,-0x1a8($a1)
/*  f178e68:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f178e6c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f178e70:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f178e74:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f178e78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f178e7c:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f178e80:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f178e84:	00003825 */ 	or	$a3,$zero,$zero
/*  f178e88:	0fc2c5c8 */ 	jal	func0f0b39c0
/*  f178e8c:	24a501a4 */ 	addiu	$a1,$a1,0x1a4
/*  f178e90:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f178e94:	3c0cba00 */ 	lui	$t4,0xba00
/*  f178e98:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f178e9c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f178ea0:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f178ea4:	af000004 */ 	sw	$zero,0x4($t8)
/*  f178ea8:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f178eac:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f178eb0:	3c0eba00 */ 	lui	$t6,0xba00
/*  f178eb4:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f178eb8:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f178ebc:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f178ec0:	00001025 */ 	or	$v0,$zero,$zero
/*  f178ec4:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f178ec8:	1ac00068 */ 	blez	$s6,.NB0f17906c
/*  f178ecc:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f178ed0:	3c118008 */ 	lui	$s1,0x8008
/*  f178ed4:	26312320 */ 	addiu	$s1,$s1,0x2320
/*  f178ed8:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f178edc:	24500001 */ 	addiu	$s0,$v0,0x1
.NB0f178ee0:
/*  f178ee0:	02002825 */ 	or	$a1,$s0,$zero
/*  f178ee4:	0fc65626 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayersBySlot
/*  f178ee8:	8ea40004 */ 	lw	$a0,0x4($s5)
/*  f178eec:	10400009 */ 	beqz	$v0,.NB0f178f14
/*  f178ef0:	8fac00b4 */ 	lw	$t4,0xb4($sp)
/*  f178ef4:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f178ef8:	3c19ffe5 */ 	lui	$t9,0xffe5
/*  f178efc:	373965ff */ 	ori	$t9,$t9,0x65ff
/*  f178f00:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f178f04:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f178f08:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f178f0c:	10000007 */ 	beqz	$zero,.NB0f178f2c
/*  f178f10:	adf40000 */ 	sw	$s4,0x0($t7)
.NB0f178f14:
/*  f178f14:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f178f18:	afab00b4 */ 	sw	$t3,0xb4($sp)
/*  f178f1c:	3c0d4343 */ 	lui	$t5,0x4343
/*  f178f20:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f178f24:	ad8d0004 */ 	sw	$t5,0x4($t4)
/*  f178f28:	ad940000 */ 	sw	$s4,0x0($t4)
.NB0f178f2c:
/*  f178f2c:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f178f30:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f178f34:	3c19ff37 */ 	lui	$t9,0xff37
/*  f178f38:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f178f3c:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f178f40:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f178f44:	37189a25 */ 	ori	$t8,$t8,0x9a25
/*  f178f48:	add80000 */ 	sw	$t8,0x0($t6)
/*  f178f4c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f178f50:	8fac00b4 */ 	lw	$t4,0xb4($sp)
/*  f178f54:	01c01025 */ 	or	$v0,$t6,$zero
/*  f178f58:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f178f5c:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f178f60:	afab00b4 */ 	sw	$t3,0xb4($sp)
/*  f178f64:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f178f68:	01801825 */ 	or	$v1,$t4,$zero
/*  f178f6c:	3c01e400 */ 	lui	$at,0xe400
/*  f178f70:	01b37021 */ 	addu	$t6,$t5,$s3
/*  f178f74:	25cf000b */ 	addiu	$t7,$t6,0xb
/*  f178f78:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f178f7c:	03190019 */ 	multu	$t8,$t9
/*  f178f80:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f178f84:	02001025 */ 	or	$v0,$s0,$zero
/*  f178f88:	25f80016 */ 	addiu	$t8,$t7,0x16
/*  f178f8c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f178f90:	00006012 */ 	mflo	$t4
/*  f178f94:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f178f98:	000b6b00 */ 	sll	$t5,$t3,0xc
/*  f178f9c:	01a17025 */ 	or	$t6,$t5,$at
/*  f178fa0:	332c0fff */ 	andi	$t4,$t9,0xfff
/*  f178fa4:	01cc5825 */ 	or	$t3,$t6,$t4
/*  f178fa8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f178fac:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f178fb0:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f178fb4:	01b37821 */ 	addu	$t7,$t5,$s3
/*  f178fb8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f178fbc:	03190019 */ 	multu	$t8,$t9
/*  f178fc0:	8e4d0004 */ 	lw	$t5,0x4($s2)
/*  f178fc4:	2673000d */ 	addiu	$s3,$s3,0xd
/*  f178fc8:	25af000b */ 	addiu	$t7,$t5,0xb
/*  f178fcc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f178fd0:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f178fd4:	24180160 */ 	addiu	$t8,$zero,0x160
/*  f178fd8:	3c0fb400 */ 	lui	$t7,0xb400
/*  f178fdc:	00007012 */ 	mflo	$t6
/*  f178fe0:	31cc0fff */ 	andi	$t4,$t6,0xfff
/*  f178fe4:	000c5b00 */ 	sll	$t3,$t4,0xc
/*  f178fe8:	01797025 */ 	or	$t6,$t3,$t9
/*  f178fec:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f178ff0:	8fac00b4 */ 	lw	$t4,0xb4($sp)
/*  f178ff4:	3c0eb300 */ 	lui	$t6,0xb300
/*  f178ff8:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f178ffc:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f179000:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f179004:	ad8f0000 */ 	sw	$t7,0x0($t4)
/*  f179008:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17900c:	01802025 */ 	or	$a0,$t4,$zero
/*  f179010:	240d0400 */ 	addiu	$t5,$zero,0x400
/*  f179014:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f179018:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f17901c:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f179020:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f179024:	01602825 */ 	or	$a1,$t3,$zero
/*  f179028:	01ac001a */ 	div	$zero,$t5,$t4
/*  f17902c:	00007812 */ 	mflo	$t7
/*  f179030:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f179034:	00185c00 */ 	sll	$t3,$t8,0x10
/*  f179038:	3579fc00 */ 	ori	$t9,$t3,0xfc00
/*  f17903c:	15800002 */ 	bnez	$t4,.NB0f179048
/*  f179040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179044:	0007000d */ 	break	0x7
.NB0f179048:
/*  f179048:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17904c:	15810004 */ 	bne	$t4,$at,.NB0f179060
/*  f179050:	3c018000 */ 	lui	$at,0x8000
/*  f179054:	15a10002 */ 	bne	$t5,$at,.NB0f179060
/*  f179058:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17905c:	0006000d */ 	break	0x6
.NB0f179060:
/*  f179060:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f179064:	5616ff9e */ 	bnel	$s0,$s6,.NB0f178ee0
/*  f179068:	24500001 */ 	addiu	$s0,$v0,0x1
.NB0f17906c:
/*  f17906c:	10000004 */ 	beqz	$zero,.NB0f179080
/*  f179070:	8fa200b4 */ 	lw	$v0,0xb4($sp)
/*  f179074:	240e001a */ 	addiu	$t6,$zero,0x1a
/*  f179078:	aeae0000 */ 	sw	$t6,0x0($s5)
.NB0f17907c:
/*  f17907c:	00001025 */ 	or	$v0,$zero,$zero
.NB0f179080:
/*  f179080:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f179084:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f179088:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f17908c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f179090:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f179094:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f179098:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f17909c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1790a0:	03e00008 */ 	jr	$ra
/*  f1790a4:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);
#endif

/**
 * This is for a separator and fixed height thing in the dialog at:
 * Combat Simulator > Advanced Setup > Challenges > pick one > Accept
 */
s32 menuhandler0017e9d8(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpAbortChallenge(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		mpRemoveLock();
	}

	return 0;
}

s32 menuhandlerMpStartChallenge(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}
	if (operation == MENUOP_SET) {
		menuPushDialog(&g_MpReadyMenuDialog);
	}

	return 0;
}

char *mpMenuTextChallengeName(struct menuitem *item)
{
#if VERSION >= VERSION_NTSC_1_0
	if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
		return langGet(L_MPMENU_050); // "Combat Challenges"
	}
#endif

	sprintf(g_StringPointer, "%s:\n", mpChallengeGetName(mpGetCurrentChallengeIndex()));
	return g_StringPointer;
}

s32 mpCombatChallengesMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE
				&& g_Menus[g_MpPlayerNum].curframe
				&& g_Menus[g_MpPlayerNum].curframe->dialog == dialog
				&& !mpIsChallengeLoaded()) {
			g_Menus[g_MpPlayerNum].unk850 = 0x4fac5ace;

			mpLoadAndStoreCurrentChallenge(
					g_Menus[g_MpPlayerNum].mpconfigbuffer,
					g_Menus[g_MpPlayerNum].mpconfigbufferlen);
		}
	}

	if (operation == MENUOP_CLOSE) {
		if (g_Menus[g_MpPlayerNum].unk850 == 0x4fac5ace) {
			mpClearCurrentChallenge();
		}
	}

	return 0;
}

s32 menuhandler0017ec64(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mpSetCurrentChallenge(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
		func0f0f820c(&g_MpQuickGoMenuDialog, 3);
	}

	return 0;
}

struct menuitem g_MpSelectTunesMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x0000004d, mpSelectTuneListHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSelectTunesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextSelectTuneOrTunes,
	g_MpSelectTunesMenuItems,
	menudialogMpSelectTune,
	0x00000010,
	NULL,
};

struct menuitem g_MpSoundtrackMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_063, 0x00000000, NULL }, // "Current:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_003, (u32)&mpMenuTextCurrentTrack, NULL }, // ""
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, (u32)&mpMenuTextSelectTuneOrTunes, 0x00000000, (void *)&g_MpSelectTunesMenuDialog },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00020000, L_MPMENU_064, 0x00000000, menuhandlerMpMultipleTunes }, // "Multiple Tunes"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_065, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSoundtrackMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_062, // "Soundtrack"
	g_MpSoundtrackMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpChangeTeamNameMenuItems[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, mpTeamNameMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpChangeTeamNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_061, // "Change Team Name"
	g_MpChangeTeamNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpTeamNamesMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_008, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Red"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_009, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Yellow"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_010, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Blue"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_011, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Magenta"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_012, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Cyan"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_013, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Orange"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_014, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Pink"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_015, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Brown"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_060, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpTeamNamesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_059, // "Team Names"
	g_MpTeamNamesMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpConfirmChallengeViaListOrDetailsMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   PAL ? 0x41 : 0x37, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00060000, L_MPMENU_057, 0x00000000, menuhandler0017e38c }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU_058, 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

struct menudialog g_MpConfirmChallengeViaListOrDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallengeViaListOrDetailsMenuItems,
	menudialog0017e3fc,
	0x00000014,
	NULL,
};

struct menuitem g_MpChallengesListOrDetailsMenuItems[] = {
	{ MENUITEMTYPE_LIST,       0,                       0x00200000, 0x00000078,       0x0000004d, menuhandler0017e4d4         },
#if VERSION < VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL, 2, 0x110, 0x7f179198, 0, (void *)0x7f1790a8 },
#endif
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCHALLENGE, 0x00000000, 0x0000007c,       PAL ? 0x41 : 0x37, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SEPARATOR,  0,                       0x00000000, 0x00000000,       0x00000000, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPWEAPONS_171, 0x00000000, menuhandlerMpStartChallenge }, // "Start Challenge"
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPMENU_051,     0x00000000, menuhandlerMpAbortChallenge }, // "Abort Challenge"
	{ MENUITEMTYPE_END,        0,                       0x00000000, 0x00000000,       0x00000000, NULL                        },
};

struct menudialog g_MpChallengeListOrDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
#if VERSION >= VERSION_NTSC_1_0
	(u32)&mpMenuTextChallengeName,
#else
	0x5032,
#endif
	g_MpChallengesListOrDetailsMenuItems,
	mpCombatChallengesMenuDialog,
#if VERSION >= VERSION_NTSC_1_0
	0x00000808,
#else
	0x00000800,
#endif
	NULL,
};

struct menudialog g_MpAdvancedSetupViaAdvChallengeMenuDialog;

struct menudialog g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
#if VERSION >= VERSION_NTSC_1_0
	(u32)&mpMenuTextChallengeName,
#else
	0x5032,
#endif
	g_MpChallengesListOrDetailsMenuItems,
	mpCombatChallengesMenuDialog,
#if VERSION >= VERSION_NTSC_1_0
	0x00000808,
	&g_MpAdvancedSetupViaAdvChallengeMenuDialog,
#else
	0x00000800,
	&g_MpAdvancedSetupMenuDialog,
#endif
};

struct menuitem g_MpConfirmChallengeMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   PAL ? 0x41 : 0x37, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU_057, 0x00000000, menuhandler0017ec64 }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU_058, 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

struct menudialog g_MpConfirmChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallengeMenuItems,
	menudialog0017e3fc,
	0x00000004,
	NULL,
};

struct menuitem g_MpChallengesMenuItems[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpChallengesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_050, // "Combat Challenges"
	g_MpChallengesMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000000,
	NULL,
};

s32 menuhandlerMpLock(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
		L_MPMENU_045, // "None"
		L_MPMENU_046, // "Last Winner"
		L_MPMENU_047, // "Last Loser"
		L_MPMENU_048, // "Random"
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = mpGetLockType() == MPLOCKTYPE_CHALLENGE ? 1 : 5;
		break;
	case MENUOP_GETOPTIONTEXT:
		if (mpGetLockType() == MPLOCKTYPE_CHALLENGE) {
			return (s32) langGet(L_MPMENU_049); // "Challenge"
		}
		if (data->dropdown.value <= 3) {
			return (s32) langGet(labels[data->dropdown.value]);
		}
		if (mpGetLockType() == MPLOCKTYPE_PLAYER) {
			return (s32) g_PlayerConfigsArray[mpGetLockPlayerNum()].base.name;
		}
		return (s32) mpGetCurrentPlayerName(item);
	case MENUOP_SET:
		if (mpGetLockType() != MPLOCKTYPE_CHALLENGE) {
			mpSetLock(data->dropdown.value, g_MpPlayerNum);
		}
		g_Vars.modifiedfiles |= MODFILE_MPSETUP;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = mpGetLockType() == MPLOCKTYPE_CHALLENGE ? 0 : mpGetLockType();
		break;
	}

	return 0;
}

s32 menuhandlerMpSavePlayer(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid == 0) {
			filemgrPushSelectLocationDialog(6, FILETYPE_MPPLAYER);
		} else {
			menuPushDialog(&g_MpSavePlayerMenuDialog);
		}
	}

	return 0;
}

char *mpMenuTextSavePlayerOrCopy(struct menuitem *item)
{
	if (g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid == 0) {
		return langGet(L_MPMENU_038); // "Save Player"
	}

	return langGet(L_MPMENU_039); // "Save Copy of Player"
}

s32 menuhandler0017ef30(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			if (IS4MB()) {
				func0f0f820c(&g_CiMenuViaPauseMenuDialog, 2);
			} else {
				func0f0f820c(&g_CiMenuViaPcMenuDialog, 2);
			}
		} else {
			func0f0f820c(&g_SoloMissionPauseMenuDialog, 2);
		}
	}

	return 0;
}

s32 menuhandlerMpSaveSettings(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_MpSetup.fileguid.fileid == 0) {
			menuPushDialog(&g_MpSaveSetupNameMenuDialog);
		} else {
#if VERSION >= VERSION_NTSC_1_0
			filemgrSetDevice1BySerial(g_MpSetup.fileguid.deviceserial);
#endif

			menuPushDialog(&g_MpSaveSetupExistsMenuDialog);
		}
	}

	return 0;
}

char *mpMenuTextArenaName(struct menuitem *item)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MpArenas); i++) {
		if (g_MpArenas[i].stagenum == g_MpSetup.stagenum) {
			return langGet(g_MpArenas[i].name);
		}
	}

	return "\n";
}

char *mpMenuTextWeaponSetName(struct menuitem *item)
{
	return mpGetWeaponSetName(mpGetWeaponSet());
}

s32 menudialogMpGameSetup(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000490 = 1;
		g_Vars.unk00049c = 1;
	}

	return false;
}

s32 menudialogMpQuickGo(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000490 = 3;
	}

	return false;
}

void mpConfigureQuickTeamPlayers(void)
{
	s32 i;

	if (g_Vars.mpquickteam != MPQUICKTEAM_NONE) {
		for (i = 0; i < 8; i++) {
			mpRemoveSimulant(i);
		}

		switch (g_Vars.mpquickteam) {
		case MPQUICKTEAM_PLAYERSONLY:
			g_MpSetup.options &= ~MPOPTION_TEAMSENABLED;
			break;
		case MPQUICKTEAM_PLAYERSANDSIMS:
			g_MpSetup.options &= ~MPOPTION_TEAMSENABLED;
			break;
		case MPQUICKTEAM_PLAYERSTEAMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < 4; i++) {
				g_PlayerConfigsArray[i].base.team = g_Vars.mpplayerteams[i];
			}

			break;
		case MPQUICKTEAM_PLAYERSVSSIMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < 4; i++) {
				g_PlayerConfigsArray[i].base.team = 0;
			}

			break;
		case MPQUICKTEAM_PLAYERSIMTEAMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < 4; i++) {
				g_PlayerConfigsArray[i].base.team = i;
			}

			break;
		}
	}
}

void mpConfigureQuickTeamSimulants(void)
{
	struct mpchrconfig *mpchr;
	s32 numchrs;
	s32 botnum;
	s32 i;
	s32 j;

	if (g_Vars.mpquickteam != MPQUICKTEAM_NONE) {
		switch (g_Vars.mpquickteam) {
		case MPQUICKTEAM_PLAYERSANDSIMS:
			for (i = 0; i < g_Vars.mpquickteamnumsims; i++) {
				botnum = mpGetSlotForNewBot();

				if (botnum >= 0) {
					mpCreateBotFromProfile(botnum, g_Vars.mpsimdifficulty);
				}
			}

			mpGenerateBotNames();
			break;
		case MPQUICKTEAM_PLAYERSVSSIMS:
			for (i = 0; i < g_Vars.mpquickteamnumsims; i++) {
				botnum = mpGetSlotForNewBot();

				if (botnum >= 0) {
					mpCreateBotFromProfile(botnum, g_Vars.mpsimdifficulty);
				}
			}

			mpGenerateBotNames();

			for (i = 0; i < ARRAYCOUNT(g_BotConfigsArray); i++) {
				g_BotConfigsArray[i].base.team = 1;
			}

			break;
		case MPQUICKTEAM_PLAYERSIMTEAMS:
			for (i = mpGetNumChrs() - 1; i >= 0; i--) {
				mpchr = mpGetChrConfigBySlotNum(i);

				for (j = 0; j < g_Vars.unk0004a0; j++) {
					botnum = mpGetSlotForNewBot();

					if (botnum >= 0) {
						mpCreateBotFromProfile(botnum, g_Vars.mpsimdifficulty);
						g_BotConfigsArray[botnum].base.team = mpchr->team;
					}
				}
			}

			mpGenerateBotNames();
			break;
		case MPQUICKTEAM_PLAYERSONLY:
		case MPQUICKTEAM_PLAYERSTEAMS:
			break;
		}
	}
}

void func0f17f428(void)
{
	mpConfigureQuickTeamPlayers();

	if (IS4MB()) {
		func0f0f820c(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
	} else {
		func0f0f820c(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
	}
}

s32 menuhandlerMpFinishedSetup(s32 operation, struct menuitem *item, union handlerdata *data)
{
#if VERSION >= VERSION_NTSC_1_0
	if (operation == MENUOP_CHECKPREFOCUSED) {
		return true;
	}
#endif

	if (operation == MENUOP_SET) {
		func0f17f428();
	}

	return 0;
}

s32 menuhandlerQuickTeamSeparator(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerPlayerTeam(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 8;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) &g_BossFile.teamnames[data->dropdown.value];
	case MENUOP_SET:
		g_Vars.mpplayerteams[item->param] = data->dropdown.value;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.mpplayerteams[item->param];
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSTEAMS) {
			return true;
		}
		break;
	}

	return 0;
}

s32 menuhandlerMpNumberOfSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = !mpIsFeatureUnlocked(MPFEATURE_8BOTS) ? 4 : 8;
		break;
	case MENUOP_GETOPTIONTEXT:
		sprintf(g_StringPointer, "%d\n", data->dropdown.value + 1);
		return (s32) g_StringPointer;
	case MENUOP_SET:
		g_Vars.mpquickteamnumsims = data->dropdown.value + 1;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.mpquickteamnumsims - 1;
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSANDSIMS
				&& g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSVSSIMS) {
			return true;
		}
		break;
	}

	return 0;
}

s32 menuhandlerMpSimulantsPerTeam(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 2;
		break;
	case MENUOP_GETOPTIONTEXT:
		sprintf(g_StringPointer, "%d\n", data->dropdown.value + 1);
		return (s32) g_StringPointer;
	case MENUOP_SET:
		g_Vars.unk0004a0 = data->dropdown.value + 1;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.unk0004a0 - 1;
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSIMTEAMS) {
			return true;
		}
		break;
	}

	return 0;
}

s32 mpQuickTeamSimulantDifficultyHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 count = 0;
	s32 i;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < 6; i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->dropdown.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < 6; i++) {
			if (mpIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->dropdown.value) {
					return (s32) langGet(i + L_MISC_082);
				}

				count++;
			}
		}
		break;
	case MENUOP_SET:
		g_Vars.mpsimdifficulty = data->dropdown.value;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.mpsimdifficulty;
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != 1 && g_Vars.mpquickteam != 3 && g_Vars.mpquickteam != 4) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpQuickTeamOption(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.mpquickteam = item->param;

		if (mpGetWeaponSet() >= func0f189058(0)) {
			mpSetWeaponSet(0);
		}

		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY ||
				g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSANDSIMS) {
			if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL ||
					g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
				g_MpSetup.scenario = MPSCENARIO_COMBAT;
			}
		}

		menuPushDialog(&g_MpQuickTeamGameSetupMenuDialog);
	}

	return 0;
}

s32 menudialogCombatSimulator(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000494[0] = 0;
		g_Vars.unk000494[1] = 0;
		g_Vars.unk000494[2] = 0;
		g_Vars.unk000494[3] = 0;
	}

	if (g_Menus[g_MpPlayerNum].curframe
			&& g_Menus[g_MpPlayerNum].curframe->dialog == &g_CombatSimulatorMenuDialog
			&& operation == MENUOP_TICK) {
		g_Vars.unk000490 = 2;
		g_Vars.mpquickteam = MPQUICKTEAM_NONE;
		g_Vars.unk00049c = 0;
		mpClearCurrentChallenge();
		mpRemoveLock();
	}

	return false;
}

s32 menuhandlerMpAdvancedSetup(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(&g_MpAdvancedSetupMenuDialog, 3);
	}

	return 0;
}

/**
 * When a player is loading a saved setup, check which dialogs the other players
 * have open and close them if they no longer apply or need to be updated.
 */
void mpCloseDialogsForNewSetup(void)
{
	s32 i;
	s32 prevplayernum = g_MpPlayerNum;
	s32 j;
	s32 k;

	// Loop through each player
	for (i = 0; i < 4; i++) {
		g_MpPlayerNum = i;

		// If they have a menu open
		if (g_Menus[g_MpPlayerNum].curframe) {
			bool ok = false;

			// Repeat the following steps until we've stopped finding dialogs
			// that should be closed
			while (!ok) {
				ok = true;

				// Loop through each layer of menus
				for (j = 0; j < g_Menus[g_MpPlayerNum].depth; j++) {
					// Loop through the siblings (left/right) in this layer
					for (k = 0; k < g_Menus[g_MpPlayerNum].layers[j].numsiblings; k++) {
						if (g_Menus[g_MpPlayerNum].layers[j].siblings[k]) {
							struct menudialog *dialog = g_Menus[g_MpPlayerNum].layers[j].siblings[k]->dialog;

							if (dialog == &g_MpSaveSetupNameMenuDialog) ok = false;
							if (dialog == &g_MpSaveSetupExistsMenuDialog) ok = false;
							if (dialog == &g_MpAddSimulantMenuDialog) ok = false;
							if (dialog == &g_MpChangeSimulantMenuDialog) ok = false;
							if (dialog == &g_MpEditSimulantMenuDialog) ok = false;
							if (dialog == &g_MpCombatOptionsMenuDialog) ok = false;
							if (dialog == &g_HtbOptionsMenuDialog) ok = false;
							if (dialog == &g_CtcOptionsMenuDialog) ok = false;
							if (dialog == &g_KohOptionsMenuDialog) ok = false;
							if (dialog == &g_HtmOptionsMenuDialog) ok = false;
							if (dialog == &g_PacOptionsMenuDialog) ok = false;
						}
					}
				}

				// Close the leaf layer
				if (!ok) {
					menuPopDialog();
				}
			}
		}
	}

	g_MpPlayerNum = prevplayernum;
}

struct menudialog g_MpAbortMenuDialog;

struct menuitem g_MpStuffMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_041, 0x00000000, (void *)&g_MpSoundtrackMenuDialog }, // "Soundtrack"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_042, 0x00000000, (void *)&g_MpTeamNamesMenuDialog }, // "Team Names"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU_044, 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS_216, 0x00000000, menuhandlerScreenRatio }, // "Ratio"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPWEAPONS_154, 0x00000000, menuhandlerScreenSplit }, // "Split"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_036, 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_037, 0x00000000, (void *)&g_MpDropOutMenuDialog }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_027, 0x00000000, (void *)&g_MpAbortMenuDialog }, // "Abort Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpStuffMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_040, // "Stuff"
	g_MpStuffMenuItems,
	NULL,
	0x00000810,
	&g_MpChallengeListOrDetailsMenuDialog,
};

struct menudialog g_MpStuffViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_040, // "Stuff"
	g_MpStuffMenuItems,
	NULL,
	0x00000810,
	NULL,
};

struct menuitem g_MpPlayerSetup234MenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_030, (u32)&mpGetCurrentPlayerName, (void *)&g_MpPlayerNameMenuDialog }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_031, 0x00000000, (void *)&g_MpCharacterMenuDialog }, // "Character"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_033, 0x00000000, (void *)&g_MpControlMenuDialog }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_034, 0x00000000, (void *)&g_MpPlayerOptionsMenuDialog }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_035, 0x00000000, (void *)&g_MpPlayerStatsMenuDialog }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_029, 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerSetupViaAdvMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	0x00000800,
	&g_MpStuffMenuDialog,
};

struct menudialog g_MpPlayerSetupViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	0x00000800,
	&g_MpStuffViaAdvChallengeMenuDialog,
};

struct menudialog g_MpPlayerSetupViaQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpAbortMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_053, 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_054, 0x00000000, menuhandler0017ef30 }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_055, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAbortMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_052, // "Abort"
	g_MpAbortMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpAdvancedSetupMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU_019, (u32)&mpMenuTextScenarioShortName, (void *)&g_MpScenarioMenuDialog }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_021, 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_020, (u32)&mpMenuTextArenaName, (void *)&g_MpArenaMenuDialog }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_023, 0x00000000, (void *)&g_MpWeaponsMenuDialog }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_024, 0x00000000, (void *)&g_MpLimitsMenuDialog }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS_184, 0x00000000, (void *)&g_MpHandicapsMenuDialog }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_025, 0x00000000, (void *)&g_MpSimulantsMenuDialog }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_022, 0x00000000, (void *)&g_MpTeamsMenuDialog }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU_018, 0x00000000, (void *)&g_MpLoadSettingsMenuDialog }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_026, 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAdvancedSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialogMpGameSetup,
	0x00000810,
	&g_MpPlayerSetupViaAdvMenuDialog,
};

struct menudialog g_MpAdvancedSetupViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialogMpGameSetup,
	0x00000810,
	&g_MpPlayerSetupViaAdvChallengeMenuDialog,
};

struct menuitem g_MpQuickGoMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_456, 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_029, 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
#endif
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_458, 0x00000000, (void *)&g_MpPlayerSetupViaQuickGoMenuDialog }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_457, 0x00000000, (void *)&g_MpDropOutMenuDialog }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_460, // "Quick Go"
	g_MpQuickGoMenuItems,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

struct menuitem g_MpQuickTeamGameSetupMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU_019, (u32)&mpMenuTextScenarioShortName, (void *)&g_MpQuickTeamScenarioMenuDialog }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_021, 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_020, (u32)&mpMenuTextArenaName, (void *)&g_MpArenaMenuDialog }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_023, (u32)&mpMenuTextWeaponSetName, (void *)&g_MpQuickTeamWeaponsMenuDialog }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_024, 0x00000000, (void *)&g_MpLimitsMenuDialog }, // "Limits"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, menuhandlerQuickTeamSeparator },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_449, 0x00000000, menuhandlerPlayerTeam }, // "Player 1 Team"
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00000000, L_MISC_450, 0x00000000, menuhandlerPlayerTeam }, // "Player 2 Team"
	{ MENUITEMTYPE_DROPDOWN,    2, 0x00000000, L_MISC_451, 0x00000000, menuhandlerPlayerTeam }, // "Player 3 Team"
	{ MENUITEMTYPE_DROPDOWN,    3, 0x00000000, L_MISC_452, 0x00000000, menuhandlerPlayerTeam }, // "Player 4 Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_453, 0x00000000, menuhandlerMpNumberOfSimulants }, // "Number Of Simulants"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_454, 0x00000000, menuhandlerMpSimulantsPerTeam }, // "Simulants Per Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_455, 0x00000000, mpQuickTeamSimulantDifficultyHandler }, // "Simulant Difficulty"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MISC_448, 0x00000000, menuhandlerMpFinishedSetup }, // "Finished Setup"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_026, 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamGameSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpQuickTeamGameSetupMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpQuickTeamMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC_463, 0x00000000, menuhandlerMpQuickTeamOption }, // "Players Only"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00400000, L_MISC_464, 0x00000000, menuhandlerMpQuickTeamOption }, // "Players and Simulants"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00400000, L_MISC_465, 0x00000000, menuhandlerMpQuickTeamOption }, // "Player Teams"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00400000, L_MISC_466, 0x00000000, menuhandlerMpQuickTeamOption }, // "Players vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00400000, L_MISC_467, 0x00000000, menuhandlerMpQuickTeamOption }, // "Player-Simulant Teams"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_462, // "Quick Team"
	g_MpQuickTeamMenuItems,
	NULL,
	0x00000004,
	NULL,
};

struct menuitem g_CombatSimulatorMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_441, 0x00000000, (void *)&g_MpChallengesMenuDialog }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_442, 0x00000001, (void *)&g_MpLoadPresetMenuDialog }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_443, 0x00000002, (void *)&g_MpQuickTeamMenuDialog }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC_444, 0x00000003, menuhandlerMpAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_CombatSimulatorMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_445, // "Combat Simulator"
	g_CombatSimulatorMenuItems,
	menudialogCombatSimulator,
	0x00000004,
	NULL,
};

void func0f17fcb0(s32 silent)
{
	g_Menus[g_MpPlayerNum].playernum = g_MpPlayerNum;

	if (IS4MB()) {
		menuPushRootDialog(&g_AdvancedSetup4MbMenuDialog, MENUROOT_4MBMAINMENU);
		func0f0f8300();
	} else {
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
			menuPushRootDialog(&g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog, MENUROOT_MPSETUP);
		} else {
			menuPushRootDialog(&g_MpAdvancedSetupMenuDialog, MENUROOT_MPSETUP);
		}

		func0f0f8300();
	}

	if (!silent) {
		// Explosion sound
		sndStart(var80095200, SFX_EXPLOSION_809A, NULL, -1, -1, -1, -1, -1);
	}
}
