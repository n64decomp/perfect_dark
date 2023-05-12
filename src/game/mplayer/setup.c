#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/game_1531a0.h"
#include "game/music.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/challenge.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/vi.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "data.h"
#include "gbiex.h"
#include "types.h"

static s32 menuhandlerMpStartChallenge(s32 operation, struct menuitem *item, union handlerdata *data);
static void mpCloseDialogsForNewSetup(void);
static s32 menuhandler0017e9d8(s32 operation, struct menuitem *item, union handlerdata *data);
static s32 menuhandlerMpAbortChallenge(s32 operation, struct menuitem *item, union handlerdata *data);
static void func0f17b8f0(void);
static s32 menuhandler0017ec64(s32 operation, struct menuitem *item, union handlerdata *data);

struct menuitem g_MpCharacterMenuItems[];
struct menudialogdef g_MpAddSimulantMenuDialog;
struct menudialogdef g_MpChangeSimulantMenuDialog;
struct menudialogdef g_MpChangeTeamNameMenuDialog;
struct menudialogdef g_MpEditSimulantMenuDialog;
struct menudialogdef g_MpSaveSetupNameMenuDialog;

static s32 menuhandlerMpDropOut(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpTeamsLabel(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) {
			return true;
		}
	}

	return 0;
}

struct menuitem g_MpDropOutMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_196, // "Are you sure you want to drop out?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_197, // "Drop Out"
		0,
		menuhandlerMpDropOut,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_198, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpDropOutMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_195, // "Drop Out"
	g_MpDropOutMenuItems,
	NULL,
	0,
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

s16 mpChooseRandomStage(void)
{
	s32 i;
	s32 numchallengescomplete = 0;
	s32 index;

	for (i = 0; i < 16; i++) {
		if (challengeIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
			numchallengescomplete++;
		}
	}

	index = random() % numchallengescomplete;

	for (i = 0; i < 16; i++) {
		if (challengeIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
			if (index == 0) {
				return g_MpArenas[i].stagenum;
			}

			index--;
		}
	}

	return STAGE_MP_SKEDAR;
}

static s32 mpArenaMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	static struct optiongroup groups[] = {
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
			if (challengeIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}

		data->list.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (challengeIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				if (count == data->list.value) {
					return (s32)langGet(g_MpArenas[i].name);
				}

				count++;
			}
		}
		break;
	case MENUOP_SET:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (challengeIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				if (count == data->list.value) {
					break;
				}

				count++;
			}
		}

		g_MpSetup.stagenum = g_MpArenas[i].stagenum;
		break;
	case MENUOP_GETSELECTEDINDEX:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (g_MpSetup.stagenum == g_MpArenas[i].stagenum) {
				data->list.value = count;
			}

			if (challengeIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 3;

		if (!challengeIsFeatureUnlocked(MPFEATURE_STAGE_COMPLEX)
				&& !challengeIsFeatureUnlocked(MPFEATURE_STAGE_TEMPLE)
				&& !challengeIsFeatureUnlocked(MPFEATURE_STAGE_FELICITY)) {
			data->list.value--;
		}
		break;
	case MENUOP_GETOPTGROUPTEXT:
		count = data->list.value;

		if (!challengeIsFeatureUnlocked(MPFEATURE_STAGE_COMPLEX)
				&& !challengeIsFeatureUnlocked(MPFEATURE_STAGE_TEMPLE)
				&& !challengeIsFeatureUnlocked(MPFEATURE_STAGE_FELICITY)
				&& count > 0) {
			count++;
		}
		return (s32)langGet(groups[count].name);
	case MENUOP_GETGROUPSTARTINDEX:
		groupindex = data->list.value;

		if (!challengeIsFeatureUnlocked(MPFEATURE_STAGE_COMPLEX)
				&& !challengeIsFeatureUnlocked(MPFEATURE_STAGE_TEMPLE)
				&& !challengeIsFeatureUnlocked(MPFEATURE_STAGE_FELICITY)
				&& groupindex == 1) {
			groupindex++;
		}

		for (i = 0; i < groups[groupindex].offset; i++) {
			if (challengeIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}
		data->list.groupstartindex = count;
		break;
	}

	return 0;
}

static s32 menuhandlerMpControlStyle(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 4;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(L_OPTIONS_239 + data->dropdown.value);
	case MENUOP_SET:
		optionsSetControlMode(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = g_PlayerConfigsArray[g_MpPlayerNum].controlmode;
		break;
	}

	return 0;
}

static s32 menuhandlerMpWeaponSlot(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = mpGetWeaponSlot(item->param3);
	}

	return 0;
}

static char *mpMenuTextWeaponNameForSlot(struct menuitem *item)
{
	return mpGetWeaponLabel(mpGetWeaponSlot(item->param));
}

static s32 menuhandlerMpWeaponSetDropdown(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = mpGetWeaponSet();
		break;
	}

	return 0;
}

static s32 menuhandlerMpControlCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpAimControl(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 2;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(L_MPMENU_213 + data->dropdown.value);
	case MENUOP_SET:
		optionsSetAimControl(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETSELECTEDINDEX:
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

static s32 menuhandlerMpTeamsEnabled(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpDisplayOptionCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpConfirmSaveChr(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		filemgrPushSelectLocationDialog(6, FILETYPE_MPPLAYER);
	}

	return 0;
}

static s32 menuhandlerMpSetupName(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpSaveSetupOverwrite(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		filemgrSaveOrLoad(&g_MpSetup.fileguid, FILEOP_SAVE_MPSETUP, 0);
	}

	return 0;
}

static s32 menuhandlerMpSaveSetupCopy(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&g_MpSaveSetupNameMenuDialog);
	}

	return 0;
}

static char *mpMenuTextSetupName(struct menuitem *item)
{
	return g_MpSetup.name;
}

/**
 * This function is used by both player body selection and bot body selection.
 */
static s32 mpCharacterBodyMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data, s32 mpheadnum, s32 mpbodynum, bool isplayer)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->carousel.value = mpGetNumBodies();
		break;
	case MENUOP_11:
		g_Menus[g_MpPlayerNum].unk840.unk05c = 0x1fc;
		g_Menus[g_MpPlayerNum].unk840.unk00c = mpbodynum << 16 | 0xffff | mpheadnum << 24;
		g_Menus[g_MpPlayerNum].unk840.unk574 += g_Vars.diffframe60;

		if (g_Menus[g_MpPlayerNum].unk840.unk574 > TICKS(480)) {
			g_Menus[g_MpPlayerNum].unk840.unk574 -= TICKS(480);
		}

		if (g_Menus[g_MpPlayerNum].unk840.unk578 > 0) {
			g_Menus[g_MpPlayerNum].unk840.unk578 -= g_Vars.diffframe60;
		} else {
			f32 value = g_Menus[g_MpPlayerNum].unk840.unk524 + 0.01f * g_Vars.diffframe60f;
			g_Menus[g_MpPlayerNum].unk840.unk54c = value;
			g_Menus[g_MpPlayerNum].unk840.unk524 = value;
		}

		g_Menus[g_MpPlayerNum].unk840.partvisibility = NULL;
		g_Menus[g_MpPlayerNum].unk840.unk554 = 30;
		break;
	case MENUOP_21:
		if (!challengeIsFeatureUnlocked(mpGetBodyRequiredFeature(data->carousel.value))) {
			return 1;
		}
		break;
	case MENUOP_FOCUS:
		g_Menus[g_MpPlayerNum].unk840.unk000 = 3;
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->carousel.value = mpheadnum;
		break;
	case MENUOP_SET:
	case MENUOP_CHECKPREFOCUSED:
		g_Menus[g_MpPlayerNum].unk840.unk580 = 0;

		func0f0f372c(&g_Menus[g_MpPlayerNum].unk840, 0, 0, 0, 0, 0, 0, 1, 1);

		g_Menus[g_MpPlayerNum].unk840.unk510 = 8.2f;
		g_Menus[g_MpPlayerNum].unk840.unk514 = -4.1f;
		g_Menus[g_MpPlayerNum].unk840.unk53c = -4.1f;

		g_Menus[g_MpPlayerNum].unk840.unk538 = 8.2f;
		g_Menus[g_MpPlayerNum].unk840.unk51c = 0.002f;
		g_Menus[g_MpPlayerNum].unk840.unk524 = -0.2f;
		g_Menus[g_MpPlayerNum].unk840.unk54c = -0.2f;

		g_Menus[g_MpPlayerNum].unk840.unk578 = TICKS(60);
		g_Menus[g_MpPlayerNum].unk840.unk574 = TICKS(120);
		g_Menus[g_MpPlayerNum].unk840.unk000 = 8;

		if (operation == MENUOP_CHECKPREFOCUSED) {
			g_Menus[g_MpPlayerNum].unk840.unk000 = 16;
		}

		break;
	}

	return 0;
}

static s32 menuhandlerMpCharacterBody(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		if (g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum < mpGetNumHeads()) {
			if (!data->carousel.unk04) {
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum = mpGetMpheadnumByMpbodynum(data->carousel.value);
			}
		}
		g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum = data->carousel.value;
		func0f17b8f0();
		break;
	case MENUOP_CHECKPREFOCUSED:
		mpCharacterBodyMenuHandler(operation, item, data,
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum,
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, true);
		return true;
	}

	return mpCharacterBodyMenuHandler(operation, item, data,
			g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum,
			g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, true);
}

static s32 menudialog0017a174(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem != &dialogdef->items[1]
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem != &dialogdef->items[2]) {
			union handlerdata data;
			menuhandlerMpCharacterBody(MENUOP_11, &dialogdef->items[2], &data);
		}
	}

	return 0;
}

static s32 mpChallengesListHandler(s32 operation, struct menuitem *item, union handlerdata *data)
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
		data->list.value = challengeGetAutoFocusedIndex(g_MpPlayerNum);
		break;
	case MENUOP_RENDER:
		maxplayers = 4;
		gdl = data->type19.gdl;
		renderdata = data->type19.renderdata2;
		challengeindex = data->list.unk04;

		x = renderdata->x + 10;
		y = renderdata->y + 1;

		gdl = text0f153628(gdl);

		name = xhallengeGetName(g_MpPlayerNum, challengeindex);

		gdl = textRenderProjected(gdl, &x, &y, name,
				g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour,
				g_ViBackData->x, g_ViBackData->y, 0, 0);

		gdl = text0f153780(gdl);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		texSelect(&gdl, &g_TexGeneralConfigs[35], 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		for (i = 0, loopx = 10; i < maxplayers; i++) {
			if (challengeIsCompletedByPlayerWithNumPlayers2(g_MpPlayerNum, challengeindex, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, 0xb2efff00 | (renderdata->colour & 0xff) * 255 / 256);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0x30407000 | (renderdata->colour & 0xff) * 255 / 256);
			}

			gDPSetCombineLERP(gdl++,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0);

			gSPTextureRectangle(gdl++,
					(renderdata->x + loopx) << 2,
					(renderdata->y + size) << 2,
					(renderdata->x + size + loopx) << 2,
					(renderdata->y + size * 2) << 2,
					G_TX_RENDERTILE,
					0, 0x0160, 0x0400, 0xfc00);

			loopx += 13;
		}

		return (s32) gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 26;
		break;
	}

	return 0;
}


static char *mpMenuTextKills(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].kills);
	return g_StringPointer;
}

static char *mpMenuTextDeaths(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].deaths);
	return g_StringPointer;
}

static char *mpMenuTextGamesPlayed(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gamesplayed);
	return g_StringPointer;
}

static char *mpMenuTextGamesWon(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gameswon);
	return g_StringPointer;
}

static char *mpMenuTextGamesLost(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gameslost);
	return g_StringPointer;
}

static char *mpMenuTextHeadShots(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].headshots);
	return g_StringPointer;
}

static char *mpMenuTextMedalAccuracy(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].accuracymedals);
	return g_StringPointer;
}

static char *mpMenuTextMedalHeadShot(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].headshotmedals);
	return g_StringPointer;
}

static char *mpMenuTextMedalKillMaster(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].killmastermedals);
	return g_StringPointer;
}

static char *mpMenuTextMedalSurvivor(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].survivormedals);
	return g_StringPointer;
}

static char *mpMenuTextAmmoUsed(struct menuitem *item)
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

static char *mpMenuTextDistance(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s%s%.1fkm\n", "", "", g_PlayerConfigsArray[g_MpPlayerNum].distance / 10.0f);
	return g_StringPointer;
}

static char *mpMenuTextTime(struct menuitem *item)
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

static char *mpMenuTextAccuracy(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s%s%.1f%%", "", "", g_PlayerConfigsArray[g_MpPlayerNum].accuracy / 10.0f);
	return g_StringPointer;
}

static void mpFormatDamageValue(char *dst, f32 damage)
{
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
}

static char *mpMenuTextPainReceived(struct menuitem *item)
{
	mpFormatDamageValue(g_StringPointer, g_PlayerConfigsArray[g_MpPlayerNum].painreceived / 10.0f);
	return g_StringPointer;
}

static char *mpMenuTextDamageDealt(struct menuitem *item)
{
	mpFormatDamageValue(g_StringPointer, g_PlayerConfigsArray[g_MpPlayerNum].damagedealt / 10.0f);
	return g_StringPointer;
}

static s32 mpMedalMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
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

		texSelect(&gdl, &g_TexGeneralConfigs[35], 2, 0, 2, 1, NULL);

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

		colour = (colour & 0xffffff00) | (colour & 0xff) * (renderdata->colour & 0xff) >> 8;

		gDPSetEnvColorViaWord(gdl++, colour);

		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0);

		gSPTextureRectangle(gdl++,
				((renderdata->x + 9) << 2), renderdata->y << 2,
				((renderdata->x + 20) << 2), (renderdata->y + 11) << 2,
				G_TX_RENDERTILE, 0, 0x0160, 1024, -1024);

		return (s32) gdl;
	}

	return 0;
}

static char *mpMenuTitleStatsForPlayerName(struct menudialogdef *dialogdef)
{
	// "Stats for %s"
	sprintf(g_StringPointer, langGet(L_MPMENU_145), g_PlayerConfigsArray[g_MpPlayerNum].base.name);
	return g_StringPointer;
}

static s32 menuhandlerMpUsernamePassword(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].title != MPPLAYERTITLE_PERFECT) {
			return true;
		}
	}

	return 0;
}

struct menuitem g_MpSavePlayerMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_191, // "Your player file is always saved automatically."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_192, // "Save a copy now?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_193, // "No"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_194, // "Yes"
		0,
		menuhandlerMpConfirmSaveChr,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSavePlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_190, // "Confirm"
	g_MpSavePlayerMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpSaveSetupNameMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_189, // "Enter a name for your game setup file:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_KEYBOARD,
		0,
		0,
		0,
		0,
		menuhandlerMpSetupName,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSaveSetupNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_188, // "Game File Name"
	g_MpSaveSetupNameMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpSaveSetupExistsMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_MPWEAPONS_230, // "Name:"
		(u32)&mpMenuTextSetupName,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
		(u32)&filemgrMenuTextDeviceName,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_184, // "Do you want to save over your original game file?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_185, // "Save Over Original"
		0,
		menuhandlerMpSaveSetupOverwrite,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_186, // "Save Copy"
		0,
		menuhandlerMpSaveSetupCopy,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_187, // "Do Not Save"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSaveSetupExistsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_183, // "Save Game Setup"
	g_MpSaveSetupExistsMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpWeaponsMenuItems[] = {
	{
		MENUITEMTYPE_DROPDOWN,
		1,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_174, // "Set:"
		0,
		menuhandlerMpWeaponSetDropdown,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_00000002 | MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_MPMENU_175, // "Current Weapon Setup:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_176, // "1:"
		0,
		menuhandlerMpWeaponSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_177, // "2:"
		0x00000001,
		menuhandlerMpWeaponSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_178, // "3:"
		0x00000002,
		menuhandlerMpWeaponSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_179, // "4:"
		0x00000003,
		menuhandlerMpWeaponSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_180, // "5:"
		0x00000004,
		menuhandlerMpWeaponSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_181, // "6:"
		0x00000005,
		menuhandlerMpWeaponSlot,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_182, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_173, // "Weapons"
	g_MpWeaponsMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpQuickTeamWeaponsMenuItems[] = {
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_174, // "Set:"
		0,
		menuhandlerMpWeaponSetDropdown,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_00000002,
		L_MPMENU_176, // "1:"
		(u32)&mpMenuTextWeaponNameForSlot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		1,
		MENUITEMFLAG_00000002,
		L_MPMENU_177, // "2:"
		(u32)&mpMenuTextWeaponNameForSlot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		2,
		MENUITEMFLAG_00000002,
		L_MPMENU_178, // "3:"
		(u32)&mpMenuTextWeaponNameForSlot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		3,
		MENUITEMFLAG_00000002,
		L_MPMENU_179, // "4:"
		(u32)&mpMenuTextWeaponNameForSlot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		4,
		MENUITEMFLAG_00000002,
		L_MPMENU_180, // "5:"
		(u32)&mpMenuTextWeaponNameForSlot,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_182, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpQuickTeamWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_173, // "Weapons"
	g_MpQuickTeamWeaponsMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpPlayerOptionsMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_168, // "Highlight Pickups"
		MPDISPLAYOPTION_HIGHLIGHTPICKUPS,
		menuhandlerMpDisplayOptionCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_169, // "Highlight Players"
		MPDISPLAYOPTION_HIGHLIGHTPLAYERS,
		menuhandlerMpDisplayOptionCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_170, // "Highlight Teams"
		MPDISPLAYOPTION_HIGHLIGHTTEAMS,
		menuhandlerMpDisplayOptionCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_171, // "Radar"
		MPDISPLAYOPTION_RADAR,
		menuhandlerMpDisplayOptionCheckbox,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_172, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpPlayerOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_167, // "Options"
	g_MpPlayerOptionsMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpControlMenuItems[] = {
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MPMENU_200, // "Control Style"
		0,
		menuhandlerMpControlStyle,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_201, // "Reverse Pitch"
		OPTION_FORWARDPITCH,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_202, // "Look Ahead"
		OPTION_LOOKAHEAD,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_203, // "Head Roll"
		OPTION_HEADROLL,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_204, // "Auto-Aim"
		OPTION_AUTOAIM,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MPMENU_205, // "Aim Control"
		0,
		menuhandlerMpAimControl,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_206, // "Sight on Screen"
		OPTION_SIGHTONSCREEN,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_207, // "Show Target"
		OPTION_ALWAYSSHOWTARGET,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_208, // "Zoom Range"
		OPTION_SHOWZOOMRANGE,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_209, // "Ammo on Screen"
		OPTION_AMMOONSCREEN,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_210, // "Gun Function"
		OPTION_SHOWGUNFUNCTION,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_211, // "Paintball"
		OPTION_PAINTBALL,
		menuhandlerMpControlCheckbox,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_212, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_199, // "Control"
	g_MpControlMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpCompletedChallengesMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0x00000078,
		0x0000004d,
		mpChallengesListHandler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpCompletedChallengesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_165, // "Completed Challenges"
	g_MpCompletedChallengesMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	NULL,
};

static char *mpMenuTextUsernamePassword(struct menuitem *item)
{
	if (item->param == 0) {
		strcpy(g_StringPointer, "EnTROpIcDeCAy\n");
	} else {
		strcpy(g_StringPointer, "ZeRo-Tau\n");
	}

	return g_StringPointer;
}

struct menuitem g_MpPlayerStatsMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_146, // "Kills:"
		(u32)&mpMenuTextKills,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_147, // "Deaths:"
		(u32)&mpMenuTextDeaths,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_148, // "Accuracy:"
		(u32)&mpMenuTextAccuracy,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_149, // "Head Shots:"
		(u32)&mpMenuTextHeadShots,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_150, // "Ammo Used:"
		(u32)&mpMenuTextAmmoUsed,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_151, // "Damage Dealt:"
		(u32)&mpMenuTextDamageDealt,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_152, // "Pain Received:"
		(u32)&mpMenuTextPainReceived,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_153, // "Games Played:"
		(u32)&mpMenuTextGamesPlayed,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_154, // "Games Won:"
		(u32)&mpMenuTextGamesWon,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_155, // "Games Lost:"
		(u32)&mpMenuTextGamesLost,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_156, // "Time:"
		(u32)&mpMenuTextTime,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_157, // "Distance:"
		(u32)&mpMenuTextDistance,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_MPMENU_158, // "Medals Won:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		2,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_159, // "Accuracy:"
		(u32)&mpMenuTextMedalAccuracy,
		mpMedalMenuHandler,
	},
	{
		MENUITEMTYPE_LABEL,
		1,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_160, // "Head Shot:"
		(u32)&mpMenuTextMedalHeadShot,
		mpMedalMenuHandler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_161, // "KillMaster:"
		(u32)&mpMenuTextMedalKillMaster,
		mpMedalMenuHandler,
	},
	{
		MENUITEMTYPE_LABEL,
		3,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_162, // "Survivor:"
		(u32)&mpMenuTextMedalSurvivor,
		mpMedalMenuHandler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_163, // "Your Title:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(u32)&mpMenuTextPlayerTitle,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_MPWEAPONS_219, // "USERNAME:"
		0,
		menuhandlerMpUsernamePassword,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
		(u32)&mpMenuTextUsernamePassword,
		0,
		menuhandlerMpUsernamePassword,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_MPWEAPONS_220, // "PASSWORD:"
		0,
		menuhandlerMpUsernamePassword,
	},
	{
		MENUITEMTYPE_LABEL,
		1,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
		(u32)&mpMenuTextUsernamePassword,
		0,
		menuhandlerMpUsernamePassword,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_164, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsForPlayerName,
	g_MpPlayerStatsMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_MpCompletedChallengesMenuDialog,
};

static s32 mpCharacterHeadMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data, s32 mpheadnum, bool arg4)
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
		diffframe = g_Menus[g_MpPlayerNum].unk840.unk524 + 0.01f * g_Vars.diffframe60f;

		g_Menus[g_MpPlayerNum].unk840.unk54c = diffframe;
		g_Menus[g_MpPlayerNum].unk840.unk524 = diffframe;

		if (mpheadnum < mpGetNumHeads2()) {
			headnum = mpGetHeadId(mpheadnum);

			g_Menus[g_MpPlayerNum].unk840.unk00c = g_HeadsAndBodies[headnum].filenum;
			g_Menus[g_MpPlayerNum].unk840.unk5b1_01 = false;
		}

		g_Menus[g_MpPlayerNum].unk840.unk574 = 0;
		g_Menus[g_MpPlayerNum].unk840.partvisibility = visibility;
		g_Menus[g_MpPlayerNum].unk840.unk554 = 30;
		break;
	case MENUOP_21:
		if (!challengeIsFeatureUnlocked(mpGetHeadRequiredFeature(data->carousel.value))) {
			return 1;
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->carousel.value = mpheadnum;
		break;
	case MENUOP_SET:
	case MENUOP_FOCUS:
		g_Menus[g_MpPlayerNum].unk840.unk000 = 3;

		mpGetNumHeads2();

		func0f0f372c(&g_Menus[g_MpPlayerNum].unk840, 0, 0, 0, 0, 0, 0, 1, 1);

		g_Menus[g_MpPlayerNum].unk840.unk510 = 0;
		g_Menus[g_MpPlayerNum].unk840.unk514 = 0;
		g_Menus[g_MpPlayerNum].unk840.unk53c = -3;
		g_Menus[g_MpPlayerNum].unk840.unk538 = 0;
		g_Menus[g_MpPlayerNum].unk840.unk51c = 0.01f;
		g_Menus[g_MpPlayerNum].unk840.unk524 = -0.3f;
		g_Menus[g_MpPlayerNum].unk840.unk54c = -0.3f;
		g_Menus[g_MpPlayerNum].unk840.unk544 = 1;
		g_Menus[g_MpPlayerNum].unk840.unk554 = 30;
		break;
	}

	return 0;
}

static s32 menuhandlerMpCharacterHead(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum = data->carousel.value;
	}

	return mpCharacterHeadMenuHandler(operation, item, data, g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, 1);
}

static char *mpMenuTextBodyName(struct menuitem *item)
{
	return mpGetBodyName(g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum);
}

static void func0f17b8f0(void)
{
	func0f0f139c(g_MpCharacterMenuItems, -0.4f);
}

static s32 mpPlayerNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 mpLoadSettingsMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
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
			mp0f18dec4(data->list.value);
		} else if (g_FileLists[1] != NULL) {
			struct filelistfile *file = &g_FileLists[1]->files[data->list.value - mpGetNumUnlockedPresets()];
			struct fileguid guid;

			guid.fileid = file->fileid;
			guid.deviceserial = file->deviceserial;

			filemgrSaveOrLoad(&guid, FILEOP_LOAD_MPSETUP, 0);
		}

		if (item->param == 1) {
			func0f0f820c(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
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

static char *mpMenuTextMpconfigMarquee(struct menuitem *item)
{
	char filename[20];
	u16 numsims;
	u16 stagenum;
	u16 scenarionum;
	s32 arenanum;
	s32 i;

	if (g_Menus[g_MpPlayerNum].mpsetup.slotindex < 0xffff && g_FileLists[1]) {
		arenanum = -1;

		mpsetupfileGetOverview(g_FileLists[1]->files[g_Menus[g_MpPlayerNum].mpsetup.slotindex].name,
				filename, &numsims, &stagenum, &scenarionum);

		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (g_MpArenas[i].stagenum == stagenum) {
				arenanum = i;
			}
		}

		if (scenarionum <= 5 && arenanum != -1 && numsims >= 0 && filename[0] != '\0' && numsims <= MAX_BOTS) {
			// "%s:  Scenario: %s   Arena: %s    Simulants: %d"
			sprintf(g_StringPointer, langGet(L_MPMENU_140),
					filename,
					langGet(g_MpScenarioOverviews[scenarionum].name),
					langGet(g_MpArenas[arenanum].name),
					numsims);
		} else {
			return "";
		}

		return g_StringPointer;
	}

	return "";
}

static s32 mpLoadPlayerMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
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

static s32 menuhandlerMpTimeLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpScoreLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpTeamScoreLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpRestoreScoreDefaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f187fec();
	}

	return 0;
}

static s32 menuhandlerMpHandicapPlayer(s32 operation, struct menuitem *item, union handlerdata *data)
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

static char *mpMenuTextHandicapPlayerName(struct menuitem *item)
{
	if (g_MpSetup.chrslots & (1 << item->param)) {
		return g_PlayerConfigsArray[item->param].base.name;
	}

	return "";
}

static s32 menuhandlerMpRestoreHandicapDefaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i < 4; i++) {
			g_PlayerConfigsArray[i].handicap = 0x80;
		}
	}

	return 0;
}

static s32 menudialogMpReady(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid && g_PlayerConfigsArray[g_MpPlayerNum].fileguid.deviceserial) {
			filemgrSaveOrLoad(&g_PlayerConfigsArray[g_MpPlayerNum].fileguid, FILEOP_SAVE_MPPLAYER, g_MpPlayerNum);
		}
	}

	return false;
}

s32 menudialogMpSimulant(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if ((u8)g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.name[0] == '\0') {
			menuPopDialog();
		}
	}

	return false;
}

struct menuitem g_MpCharacterMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_DARKERBG,
		(u32)&mpMenuTextBodyName,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_CAROUSEL,
		0,
		0,
		0,
		0x00000022,
		menuhandlerMpCharacterHead,
	},
	{
		MENUITEMTYPE_CAROUSEL,
		0,
		0,
		0,
		0x0000001b,
		menuhandlerMpCharacterBody,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpCharacterMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_143, // "Character"
	g_MpCharacterMenuItems,
	menudialog0017a174,
	MENUDIALOGFLAG_0002,
	NULL,
};

struct menuitem g_MpPlayerNameMenuItems[] = {
	{
		MENUITEMTYPE_KEYBOARD,
		0,
		0,
		0,
		0,
		mpPlayerNameMenuHandler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpPlayerNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_142, // "Player Name"
	g_MpPlayerNameMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpLoadSettingsMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		0,
		0x00000078,
		0x00000042,
		mpLoadSettingsMenuHandler,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&mpMenuTextMpconfigMarquee,
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpLoadSettingsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_139, // "Load Game Settings"
	g_MpLoadSettingsMenuItems,
	NULL,
	MENUDIALOGFLAG_CLOSEONSELECT,
	NULL,
};

struct menuitem g_MpLoadPresetMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		1,
		0,
		0x00000078,
		0x00000042,
		mpLoadSettingsMenuHandler,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&mpMenuTextMpconfigMarquee,
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpLoadPresetMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_139, // "Load Game Settings"
	g_MpLoadPresetMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpLoadPlayerMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		0,
		0x0000007e,
		0x00000042,
		mpLoadPlayerMenuHandler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_MPMENU_138, // "B Button to cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpLoadPlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_137, // "Load Player"
	g_MpLoadPlayerMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpArenaMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		0x00000078,
		0x0000004d,
		mpArenaMenuHandler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpArenaMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_115, // "Arena"
	g_MpArenaMenuItems,
	NULL,
	MENUDIALOGFLAG_CLOSEONSELECT | MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpLimitsMenuItems[] = {
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_108, // "Time"
		0x0000003c,
		menuhandlerMpTimeLimitSlider,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_109, // "Score"
		0x00000064,
		menuhandlerMpScoreLimitSlider,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		L_MISC_447, // "Team Score"
		0x00000190,
		menuhandlerMpTeamScoreLimitSlider,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_LOCKABLEMAJOR,
		L_MPMENU_110, // "Restore Defaults"
		0,
		menuhandlerMpRestoreScoreDefaults,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_111, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpLimitsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_107, // "Limits"
	g_MpLimitsMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpHandicapsMenuItems[] = {
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextHandicapPlayerName,
		0x000000ff,
		menuhandlerMpHandicapPlayer,
	},
	{
		MENUITEMTYPE_SLIDER,
		1,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextHandicapPlayerName,
		0x000000ff,
		menuhandlerMpHandicapPlayer,
	},
	{
		MENUITEMTYPE_SLIDER,
		2,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextHandicapPlayerName,
		0x000000ff,
		menuhandlerMpHandicapPlayer,
	},
	{
		MENUITEMTYPE_SLIDER,
		3,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextHandicapPlayerName,
		0x000000ff,
		menuhandlerMpHandicapPlayer,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_LOCKABLEMAJOR,
		L_MPMENU_110, // "Restore Defaults"
		0,
		menuhandlerMpRestoreHandicapDefaults,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_111, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpHandicapsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_184, // "Player Handicaps"
	g_MpHandicapsMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpReadyMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_106, // "...and waiting"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpReadyMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_105, // "Ready!"
	g_MpReadyMenuItems,
	menudialogMpReady,
	MENUDIALOGFLAG_CLOSEONSELECT,
	NULL,
};

static s32 mpAddChangeSimulantMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 i;
	s32 count = 0;

	static struct optiongroup groups[] = {
		{ 0, L_MPMENU_103 }, // "Normal Simulants"
		{ 6, L_MPMENU_104 }, // "Special Simulants"
	};

	s32 botnum;
	bool creating;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->list.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
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
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
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
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->list.value) {
					break;
				}

				count++;
			}
		}

		g_Menus[g_MpPlayerNum].mpsetup.unke24 = i;
		// fall-through
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = g_Menus[g_MpPlayerNum].mpsetup.slotcount;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 2;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return (s32)langGet(groups[data->list.value].name);
	case MENUOP_GETGROUPSTARTINDEX:
		for (i = 0; i < groups[data->list.value].offset; i++) {
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->list.groupstartindex = count;
		break;
	}

	return 0;
}

static char *mpMenuTextSimulantDescription(struct menuitem *item)
{
	return langGet(L_MISC_106 + g_Menus[g_MpPlayerNum].mpsetup.unke24);
}

static s32 menuhandlerMpSimulantHead(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpSimulantBody(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpbodynum = data->carousel.value;
	}

	return mpCharacterBodyMenuHandler(operation, item, data,
			g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpbodynum,
			g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum,
			false);
}

static s32 menudialog0017ccfc(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem != &dialogdef->items[0]
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem != &dialogdef->items[1]) {
			union handlerdata data;
			menuhandlerMpCharacterBody(MENUOP_11, &dialogdef->items[1], &data);
		}
	}

	return menudialogMpSimulant(operation, dialogdef, data);
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
	case MENUOP_GETSELECTEDINDEX:
		if (g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty >= 0
				&& g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty < BOTDIFF_DISABLED) {
			data->dropdown.value = g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty;
		} else {
			data->dropdown.value = 0;
		}
		break;
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < BOTDIFF_DISABLED; i++) {
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->dropdown.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < BOTDIFF_DISABLED; i++) {
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
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

char *mpMenuTitleEditSimulant(struct menudialogdef *dialogdef)
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
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		g_Menus[g_MpPlayerNum].mpsetup.slotcount = count;

		menuPushDialog(&g_MpChangeSimulantMenuDialog);
	}

	return 0;
}

static s32 menuhandlerMpClearAllSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		for (i = 0; i < MAX_BOTS; i++) {
			mpRemoveSimulant(i);
		}
	}

	return 0;
}

static s32 menuhandlerMpAddSimulant(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpSimulantSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = item->param;

		if ((g_MpSetup.chrslots & (1 << (item->param + 4))) == 0) {
			menuPushDialog(&g_MpAddSimulantMenuDialog);
		} else {
			menuPushDialog(&g_MpEditSimulantMenuDialog);
		}
		break;
	case MENUOP_CHECKHIDDEN:
		if (item->param >= 4 && !challengeIsFeatureUnlocked(MPFEATURE_8BOTS)) {
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

static char *mpMenuTextSimulantName(struct menuitem *item)
{
	s32 index = item->param;

	if (g_BotConfigsArray[index].base.name[0] == '\0' || (g_MpSetup.chrslots & 1 << (index + 4)) == 0) {
		return "";
	}

	return g_BotConfigsArray[index].base.name;
}

static s32 menudialogMpSimulants(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Menus[g_MpPlayerNum].mpsetup.slotcount = 0;
	}

	return false;
}

struct menuitem g_MpAddChangeSimulantMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		0x00000078,
		0x00000042,
		mpAddChangeSimulantMenuHandler,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&mpMenuTextSimulantDescription,
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpAddSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_101, // "Add Simulant"
	g_MpAddChangeSimulantMenuItems,
	NULL,
	MENUDIALOGFLAG_CLOSEONSELECT | MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menudialogdef g_MpChangeSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_102, // "Change Simulant"
	g_MpAddChangeSimulantMenuItems,
	menudialogMpSimulant,
	MENUDIALOGFLAG_CLOSEONSELECT | MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpSimulantCharacterMenuItems[] = {
	{
		MENUITEMTYPE_CAROUSEL,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		0,
		0x00000025,
		menuhandlerMpSimulantHead,
	},
	{
		MENUITEMTYPE_CAROUSEL,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		0,
		0x0000001b,
		menuhandlerMpSimulantBody,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSimulantCharacterMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_100, // "Simulant Character"
	g_MpSimulantCharacterMenuItems,
	menudialog0017ccfc,
	MENUDIALOGFLAG_0002 | MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpEditSimulantMenuItems[] = {
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_095, // "Difficulty:"
		0,
		mpBotDifficultyMenuHandler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_096, // "Change Type..."
		0,
		menuhandlerMpChangeSimulantType,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_097, // "Character..."
		0,
		(void *)&g_MpSimulantCharacterMenuDialog,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_098, // "Delete Simulant"
		0,
		menuhandlerMpDeleteSimulant,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_099, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpEditSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleEditSimulant,
	g_MpEditSimulantMenuItems,
	menudialogMpSimulant,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpSimulantsMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_084, // "Add Simulant..."
		0,
		menuhandlerMpAddSimulant,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_085, // "1:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		1,
		0,
		L_MPMENU_086, // "2:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		2,
		0,
		L_MPMENU_087, // "3:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		3,
		0,
		L_MPMENU_088, // "4:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		4,
		0,
		L_MPMENU_089, // "5:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		5,
		0,
		L_MPMENU_090, // "6:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		6,
		0,
		L_MPMENU_091, // "7:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		7,
		0,
		L_MPMENU_092, // "8:"
		(u32)&mpMenuTextSimulantName,
		menuhandlerMpSimulantSlot,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_093, // "Clear All"
		0,
		menuhandlerMpClearAllSimulants,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_094, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSimulantsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_083, // "Simulants"
	g_MpSimulantsMenuItems,
	menudialogMpSimulants,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

static s32 menuhandlerMpNTeams(s32 operation, struct menuitem *item, union handlerdata *data, s32 numteams)
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

		i = start + 1;
		WRAP(i, numchrs);

		do {
			struct mpchrconfig *mpchr = mpGetChrConfigBySlotNum(i);

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
						teamnum++;
						WRAP(teamnum, numteams);
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
						teamnum++;
						WRAP(teamnum, numteams);
					}
				}
			}

			if (i == start) {
				break;
			}

			i++;
			WRAP(i, numchrs);
		} while (true);

		menuPopDialog();
	}

	return 0;
}

static s32 menuhandlerMpTwoTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 2);
}

static s32 menuhandlerMpThreeTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 3);
}

static s32 menuhandlerMpFourTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 4);
}

static s32 menuhandlerMpMaximumTeams(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpHumansVsSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpHumanSimulantPairs(s32 operation, struct menuitem *item, union handlerdata *data)
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

static char *mpMenuTextChrNameForTeamSetup(struct menuitem *item)
{
	struct mpchrconfig *mpchr = mpGetChrConfigBySlotNum(item->param);

	if (mpchr) {
		return mpchr->name;
	}

	return "";
}

static s32 func0f17dac4(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menuhandlerMpTeamSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct mpchrconfig *mpchr;

	switch (operation) {
	case MENUOP_SET:
		mpchr = mpGetChrConfigBySlotNum(item->param);
		mpchr->team = data->dropdown.value;
		break;
	case MENUOP_GETSELECTEDINDEX:
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

static char *mpMenuTextSelectTuneOrTunes(struct menuitem *item)
{
	if (mpGetUsingMultipleTunes()) {
		return langGet(L_MPMENU_069); // "Select Tune"
	}

	return langGet(L_MPMENU_068); // "Select Tunes"
}

struct menuitem g_MpAutoTeamMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_076, // "Two Teams"
		0,
		menuhandlerMpTwoTeams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_077, // "Three Teams"
		0,
		menuhandlerMpThreeTeams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_078, // "Four Teams"
		0,
		menuhandlerMpFourTeams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_079, // "Maximum Teams"
		0,
		menuhandlerMpMaximumTeams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_080, // "Humans vs. Simulants"
		0,
		menuhandlerMpHumansVsSimulants,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_081, // "Human-Simulant Pairs"
		0,
		menuhandlerMpHumanSimulantPairs,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_082, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpAutoTeamMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_075, // "Auto Team"
	g_MpAutoTeamMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpTeamsMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_071, // "Teams Enabled"
		0x00000002,
		menuhandlerMpTeamsEnabled,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_072, // "Teams:"
		0,
		menuhandlerMpTeamsLabel,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		1,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		2,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		3,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		4,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		5,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		6,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		7,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		8,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		9,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		10,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		11,
		MENUITEMFLAG_LOCKABLEMINOR,
		(u32)&mpMenuTextChrNameForTeamSetup,
		0,
		menuhandlerMpTeamSlot,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_073, // "Auto Team..."
		0,
		(void *)&g_MpAutoTeamMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_074, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpTeamsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_070, // "Team Control"
	g_MpTeamsMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
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
static s32 mpSelectTuneListHandler(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
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

static s32 menudialogMpSelectTune(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		var800840e0 = 80;
	}

	if (operation == MENUOP_CLOSE) {
		var800840e0 = 15;
	}

	return false;
}

static char *mpMenuTextCurrentTrack(struct menuitem *item)
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

static s32 menuhandlerMpMultipleTunes(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 mpTeamNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
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
static char *mpMenuTextTeamName(struct menuitem *item)
{
	s32 index = item->param2;
	index -= L_OPTIONS_008;

	return g_BossFile.teamnames[index];
}

static s32 menuhandlerMpTeamNameSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = item->param2 - 0x5608;
		menuPushDialog(&g_MpChangeTeamNameMenuDialog);
	}

	return 0;
}

char *func0f17e318(struct menudialogdef *dialogdef)
{
	sprintf(g_StringPointer, langGet(L_MPMENU_056), challengeGetNameBySlot(g_Menus[g_MpPlayerNum].mpsetup.slotindex));
	return g_StringPointer;
}

/**
 * An "Accept" item somewhere. Probably accepting a challenge.
 */
static s32 menuhandler0017e38c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		challengeUnsetCurrent();

		menuPopDialog();
		challengeSetCurrentBySlot(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
	}

	return 0;
}

s32 menudialog0017e3fc(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		g_Menus[g_MpPlayerNum].unk840.unk010 = 0;

		g_Menus[g_MpPlayerNum].training.mpconfig = challengeLoadBySlot(
				g_Menus[g_MpPlayerNum].training.unke1c,
				g_Menus[g_MpPlayerNum].unk840.unk004,
				g_Menus[g_MpPlayerNum].unk840.unk008);
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

struct menuitem g_MpSelectTunesMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		0x00000078,
		0x0000004d,
		mpSelectTuneListHandler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSelectTunesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextSelectTuneOrTunes,
	g_MpSelectTunesMenuItems,
	menudialogMpSelectTune,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpSoundtrackMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_063, // "Current:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_003, // ""
		(u32)&mpMenuTextCurrentTrack,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		(u32)&mpMenuTextSelectTuneOrTunes,
		0,
		(void *)&g_MpSelectTunesMenuDialog,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_064, // "Multiple Tunes"
		0,
		menuhandlerMpMultipleTunes,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_065, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSoundtrackMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_062, // "Soundtrack"
	g_MpSoundtrackMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpChangeTeamNameMenuItems[] = {
	{
		MENUITEMTYPE_KEYBOARD,
		0,
		0,
		0,
		0,
		mpTeamNameMenuHandler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpChangeTeamNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_061, // "Change Team Name"
	g_MpChangeTeamNameMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpTeamNamesMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_008, // "Red"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_009, // "Yellow"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_010, // "Blue"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_011, // "Magenta"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_012, // "Cyan"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_013, // "Orange"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_014, // "Pink"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_015, // "Brown"
		(u32)&mpMenuTextTeamName,
		menuhandlerMpTeamNameSlot,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_060, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpTeamNamesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_059, // "Team Names"
	g_MpTeamNamesMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpConfirmChallengeViaListOrDetailsMenuItems[] = {
	{
		MENUITEMTYPE_SCROLLABLE,
		DESCRIPTION_MPCONFIG,
		0,
		0x0000007c,
		PAL ? 0x41 : 0x37,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_LOCKABLEMAJOR,
		L_MPMENU_057, // "Accept"
		0,
		menuhandler0017e38c,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_058, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpConfirmChallengeViaListOrDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallengeViaListOrDetailsMenuItems,
	menudialog0017e3fc,
	MENUDIALOGFLAG_STARTSELECTS | MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpChallengesListOrDetailsMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0x00000078,
		0x0000004d,
		mpChallengesListMenuHandler,
	},
	{
		MENUITEMTYPE_SCROLLABLE,
		DESCRIPTION_MPCHALLENGE,
		0,
		0x0000007c,
		PAL ? 0x41 : 0x37,
		menuhandler0017e9d8,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		menuhandler0017e9d8,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPWEAPONS_171, // "Start Challenge"
		0,
		menuhandlerMpStartChallenge,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_051, // "Abort Challenge"
		0,
		menuhandlerMpAbortChallenge,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpChallengeListOrDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	g_MpChallengesListOrDetailsMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000808,
	NULL,
};

struct menudialogdef g_MpAdvancedSetupViaAdvChallengeMenuDialog;

struct menudialogdef g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	g_MpChallengesListOrDetailsMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000808,
	&g_MpAdvancedSetupViaAdvChallengeMenuDialog,
};

struct menuitem g_MpConfirmChallengeMenuItems[] = {
	{
		MENUITEMTYPE_SCROLLABLE,
		DESCRIPTION_MPCONFIG,
		0,
		0x0000007c,
		PAL ? 0x41 : 0x37,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_057, // "Accept"
		0,
		menuhandler0017ec64,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_058, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpConfirmChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallengeMenuItems,
	menudialog0017e3fc,
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
};

s32 mpChallengesListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	Gfx *gdl;
	struct menuitemrenderdata *renderdata;
	s32 x;
	s32 y;
	s32 maxchrs;
	s32 marginleft;
	s32 i;

	switch (operation) {
	case MENUOP_CHECKHIDDEN:
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
			return 1;
		}
		break;
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = challengeGetNumAvailable();
		break;
	case MENUOP_SET:
		if (data->list.unk04 != 0) {
			data->list.unk04 = 2;
		}

		g_Menus[g_MpPlayerNum].mpsetup.slotindex = data->list.value;

		if (item->param == 0) {
			menuPushDialog(&g_MpConfirmChallengeViaListOrDetailsMenuDialog);
		} else {
			menuPushDialog(&g_MpConfirmChallengeMenuDialog);
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = 0xfffff;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 0;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return 0;
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = 0;
		break;
	case MENUOP_RENDER:
		gdl = data->type19.gdl;
		renderdata = data->type19.renderdata2;
		marginleft = 10;
		maxchrs = 4;

		x = renderdata->x + 10;
		y = renderdata->y + 1;

		gdl = text0f153628(gdl);
		gdl = textRenderProjected(gdl, &x, &y, challengeGetNameBySlot(data->type19.unk04), g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, g_ViBackData->x, g_ViBackData->y, 0, 0);
		gdl = text0f153780(gdl);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		texSelect(&gdl, &g_TexGeneralConfigs[35], 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		for (i = 0; i < maxchrs; i++) {
			if (challengeIsCompletedByAnyChrWithNumPlayersBySlot(data->type19.unk04, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, (renderdata->colour & 0xff) * 0xff >> 8 | 0xffe56500);
			} else {
				gDPSetEnvColorViaWord(gdl++, (renderdata->colour & 0xff) * 0xff >> 8 | 0x43430000);
			}

			gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0);

			gSPTextureRectangle(gdl++,
				((renderdata->x + marginleft) << 2), (renderdata->y + 11) << 2,
				((renderdata->x + marginleft + 11) << 2), (renderdata->y + 22) << 2,
				G_TX_RENDERTILE, 0, 0x0160, 1024, -1024);

			marginleft += 13;
		}
		return (s32)gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 26;
		break;
	}

	return 0;
}

/**
 * This is for a separator and fixed height thing in the dialog at:
 * Combat Simulator > Advanced Setup > Challenges > pick one > Accept
 */
static s32 menuhandler0017e9d8(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

static s32 menuhandlerMpAbortChallenge(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		challengeRemovePlayerLock();
	}

	return 0;
}

static s32 menuhandlerMpStartChallenge(s32 operation, struct menuitem *item, union handlerdata *data)
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
	if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
		return langGet(L_MPMENU_050); // "Combat Challenges"
	}

	sprintf(g_StringPointer, "%s:\n", challengeGetName(challengeGetCurrent()));
	return g_StringPointer;
}

s32 mpCombatChallengesMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE
				&& g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
				&& !challengeIsLoaded()) {
			g_Menus[g_MpPlayerNum].unk840.unk010 = 0x4fac5ace;

			challengeLoadAndStoreCurrent(
					g_Menus[g_MpPlayerNum].unk840.unk004,
					g_Menus[g_MpPlayerNum].unk840.unk008);
		}
	}

	if (operation == MENUOP_CLOSE) {
		if (g_Menus[g_MpPlayerNum].unk840.unk010 == 0x4fac5ace) {
			challengeUnsetCurrent();
		}
	}

	return 0;
}

static s32 menuhandler0017ec64(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		challengeSetCurrentBySlot(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
		func0f0f820c(&g_MpQuickGoMenuDialog, 3);
	}

	return 0;
}

struct menuitem g_MpChallengesMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		1,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0x00000078,
		0x0000004d,
		mpChallengesListMenuHandler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpChallengesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_050, // "Combat Challenges"
	g_MpChallengesMenuItems,
	mpCombatChallengesMenuDialog,
	0,
	NULL,
};

s32 menuhandlerMpLock(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = mpGetLockType() == MPLOCKTYPE_CHALLENGE ? 1 : 5;
		break;
	case MENUOP_GETOPTIONTEXT:
		if (mpGetLockType() == MPLOCKTYPE_CHALLENGE) {
			return (s32) langGet(L_MPMENU_049); // "Challenge"
		}
		if (data->dropdown.value <= 3) {
			return (s32) langGet(L_MPMENU_045 + data->dropdown.value);
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
	case MENUOP_GETSELECTEDINDEX:
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

static s32 menuhandler0017ef30(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			func0f0f820c(&g_CiMenuViaPcMenuDialog, 2);
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
			filemgrSetDevice1BySerial(g_MpSetup.fileguid.deviceserial);

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

static char *mpMenuTextWeaponSetName(struct menuitem *item)
{
	return mpGetWeaponSetName(mpGetWeaponSet());
}

s32 menudialogMpGameSetup(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.mpsetupmenu = MPSETUPMENU_ADVSETUP;
		g_Vars.usingadvsetup = true;
	}

	return false;
}

s32 menudialogMpQuickGo(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.mpsetupmenu = MPSETUPMENU_QUICKGO;
	}

	return false;
}

static void mpConfigureQuickTeamPlayers(void)
{
	s32 i;

	if (g_Vars.mpquickteam != MPQUICKTEAM_NONE) {
		for (i = 0; i < MAX_BOTS; i++) {
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

	func0f0f820c(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
}

static s32 menuhandlerMpFinishedSetup(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKPREFOCUSED) {
		return true;
	}

	if (operation == MENUOP_SET) {
		func0f17f428();
	}

	return 0;
}

static s32 menuhandlerQuickTeamSeparator(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY) {
			return true;
		}
	}

	return 0;
}

static s32 menuhandlerPlayerTeam(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = MAX_TEAMS;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) &g_BossFile.teamnames[data->dropdown.value];
	case MENUOP_SET:
		g_Vars.mpplayerteams[item->param] = data->dropdown.value;
		break;
	case MENUOP_GETSELECTEDINDEX:
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

static s32 menuhandlerMpNumberOfSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = !challengeIsFeatureUnlocked(MPFEATURE_8BOTS) ? 4 : MAX_BOTS;
		break;
	case MENUOP_GETOPTIONTEXT:
		sprintf(g_StringPointer, "%d\n", data->dropdown.value + 1);
		return (s32) g_StringPointer;
	case MENUOP_SET:
		g_Vars.mpquickteamnumsims = data->dropdown.value + 1;
		break;
	case MENUOP_GETSELECTEDINDEX:
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

static s32 menuhandlerMpSimulantsPerTeam(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
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

static s32 mpQuickTeamSimulantDifficultyHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 count = 0;
	s32 i;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < 6; i++) {
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->dropdown.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < 6; i++) {
			if (challengeIsFeatureUnlocked(g_BotProfiles[i].requirefeature)) {
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
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = g_Vars.mpsimdifficulty;
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != 1 && g_Vars.mpquickteam != 3 && g_Vars.mpquickteam != 4) {
			return true;
		}
	}

	return 0;
}

static s32 menuhandlerMpQuickTeamOption(s32 operation, struct menuitem *item, union handlerdata *data)
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

static s32 menudialogCombatSimulator(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.waitingtojoin[0] = false;
		g_Vars.waitingtojoin[1] = false;
		g_Vars.waitingtojoin[2] = false;
		g_Vars.waitingtojoin[3] = false;
	}

	if (g_Menus[g_MpPlayerNum].curdialog
			&& g_Menus[g_MpPlayerNum].curdialog->definition == &g_CombatSimulatorMenuDialog
			&& operation == MENUOP_TICK) {
		g_Vars.mpsetupmenu = MPSETUPMENU_GENERAL;
		g_Vars.mpquickteam = MPQUICKTEAM_NONE;
		g_Vars.usingadvsetup = false;
		challengeUnsetCurrent();
		challengeRemovePlayerLock();
	}

	return false;
}

static s32 menuhandlerMpAdvancedSetup(s32 operation, struct menuitem *item, union handlerdata *data)
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
static void mpCloseDialogsForNewSetup(void)
{
	s32 i;
	s32 prevplayernum = g_MpPlayerNum;
	s32 j;
	s32 k;

	// Loop through each player
	for (i = 0; i < 4; i++) {
		g_MpPlayerNum = i;

		// If they have a menu open
		if (g_Menus[g_MpPlayerNum].curdialog) {
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
							struct menudialogdef *dialogdef = g_Menus[g_MpPlayerNum].layers[j].siblings[k]->definition;

							if (dialogdef == &g_MpSaveSetupNameMenuDialog) ok = false;
							if (dialogdef == &g_MpSaveSetupExistsMenuDialog) ok = false;
							if (dialogdef == &g_MpAddSimulantMenuDialog) ok = false;
							if (dialogdef == &g_MpChangeSimulantMenuDialog) ok = false;
							if (dialogdef == &g_MpEditSimulantMenuDialog) ok = false;
							if (dialogdef == &g_MpCombatOptionsMenuDialog) ok = false;
							if (dialogdef == &g_HtbOptionsMenuDialog) ok = false;
							if (dialogdef == &g_CtcOptionsMenuDialog) ok = false;
							if (dialogdef == &g_KohOptionsMenuDialog) ok = false;
							if (dialogdef == &g_HtmOptionsMenuDialog) ok = false;
							if (dialogdef == &g_PacOptionsMenuDialog) ok = false;
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

struct menudialogdef g_MpAbortMenuDialog;

struct menuitem g_MpStuffMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_041, // "Soundtrack"
		0,
		(void *)&g_MpSoundtrackMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_042, // "Team Names"
		0,
		(void *)&g_MpTeamNamesMenuDialog,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_044, // "Lock"
		0,
		menuhandlerMpLock,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_OPTIONS_216, // "Ratio"
		0,
		menuhandlerScreenRatio,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MPWEAPONS_154, // "Split"
		0,
		menuhandlerScreenSplit,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_036, // "Start Game"
		0,
		(void *)&g_MpReadyMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_037, // "Drop Out"
		0,
		(void *)&g_MpDropOutMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_027, // "Abort Game"
		0,
		(void *)&g_MpAbortMenuDialog,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpStuffMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_040, // "Stuff"
	g_MpStuffMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE | MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpChallengeListOrDetailsMenuDialog,
};

struct menudialogdef g_MpStuffViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_040, // "Stuff"
	g_MpStuffMenuItems,
	NULL,
	MENUDIALOGFLAG_MPLOCKABLE | MENUDIALOGFLAG_DROPOUTONCLOSE,
	NULL,
};

struct menuitem g_MpPlayerSetup234MenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_030, // "Name"
		(u32)&mpGetCurrentPlayerName,
		(void *)&g_MpPlayerNameMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_031, // "Character"
		0,
		(void *)&g_MpCharacterMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_033, // "Control"
		0,
		(void *)&g_MpControlMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_034, // "Player Options"
		0,
		(void *)&g_MpPlayerOptionsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_035, // "Statistics"
		0,
		(void *)&g_MpPlayerStatsMenuDialog,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_029, // "Load Player"
		0,
		(void *)&g_MpLoadPlayerMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		(u32)&mpMenuTextSavePlayerOrCopy,
		0,
		menuhandlerMpSavePlayer,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpPlayerSetupViaAdvMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpStuffMenuDialog,
};

struct menudialogdef g_MpPlayerSetupViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpStuffViaAdvChallengeMenuDialog,
};

struct menudialogdef g_MpPlayerSetupViaQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpAbortMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_053, // "Are you sure you want to abort the game?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_054, // "Abort"
		0,
		menuhandler0017ef30,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_055, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpAbortMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_052, // "Abort"
	g_MpAbortMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpAdvancedSetupMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_019, // "Scenario"
		(u32)&mpMenuTextScenarioShortName,
		(void *)&g_MpScenarioMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_021, // "Options"
		0,
		menuhandlerMpOpenOptions,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_020, // "Arena"
		(u32)&mpMenuTextArenaName,
		(void *)&g_MpArenaMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_023, // "Weapons"
		0,
		(void *)&g_MpWeaponsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_024, // "Limits"
		0,
		(void *)&g_MpLimitsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPWEAPONS_184, // "Player Handicaps"
		0,
		(void *)&g_MpHandicapsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_025, // "Simulants"
		0,
		(void *)&g_MpSimulantsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_022, // "Teams"
		0,
		(void *)&g_MpTeamsMenuDialog,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_LOCKABLEMAJOR,
		L_MPMENU_018, // "Load Settings"
		0,
		(void *)&g_MpLoadSettingsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_LOCKABLEMAJOR,
		L_MPMENU_026, // "Save Settings"
		0,
		menuhandlerMpSaveSettings,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpAdvancedSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialogMpGameSetup,
	MENUDIALOGFLAG_MPLOCKABLE | MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpPlayerSetupViaAdvMenuDialog,
};

struct menudialogdef g_MpAdvancedSetupViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialogMpGameSetup,
	MENUDIALOGFLAG_MPLOCKABLE | MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpPlayerSetupViaAdvChallengeMenuDialog,
};

struct menuitem g_MpQuickGoMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MISC_456, // "Start Game"
		0,
		(void *)&g_MpReadyMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_029, // "Load Player"
		0,
		(void *)&g_MpLoadPlayerMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MISC_458, // "Player Settings"
		0,
		(void *)&g_MpPlayerSetupViaQuickGoMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MISC_457, // "Drop Out"
		0,
		(void *)&g_MpDropOutMenuDialog,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_460, // "Quick Go"
	g_MpQuickGoMenuItems,
	menudialogMpQuickGo,
	0,
	NULL,
};

struct menuitem g_MpQuickTeamGameSetupMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_019, // "Scenario"
		(u32)&mpMenuTextScenarioShortName,
		(void *)&g_MpQuickTeamScenarioMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_021, // "Options"
		0,
		menuhandlerMpOpenOptions,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_020, // "Arena"
		(u32)&mpMenuTextArenaName,
		(void *)&g_MpArenaMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_023, // "Weapons"
		(u32)&mpMenuTextWeaponSetName,
		(void *)&g_MpQuickTeamWeaponsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_024, // "Limits"
		0,
		(void *)&g_MpLimitsMenuDialog,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		menuhandlerQuickTeamSeparator,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_449, // "Player 1 Team"
		0,
		menuhandlerPlayerTeam,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		1,
		0,
		L_MISC_450, // "Player 2 Team"
		0,
		menuhandlerPlayerTeam,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		2,
		0,
		L_MISC_451, // "Player 3 Team"
		0,
		menuhandlerPlayerTeam,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		3,
		0,
		L_MISC_452, // "Player 4 Team"
		0,
		menuhandlerPlayerTeam,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_453, // "Number Of Simulants"
		0,
		menuhandlerMpNumberOfSimulants,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_454, // "Simulants Per Team"
		0,
		menuhandlerMpSimulantsPerTeam,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_455, // "Simulant Difficulty"
		0,
		mpQuickTeamSimulantDifficultyHandler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MISC_448, // "Finished Setup"
		0,
		menuhandlerMpFinishedSetup,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_LOCKABLEMAJOR,
		L_MPMENU_026, // "Save Settings"
		0,
		menuhandlerMpSaveSettings,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpQuickTeamGameSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpQuickTeamGameSetupMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_MpQuickTeamMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_BIGFONT,
		L_MISC_463, // "Players Only"
		0,
		menuhandlerMpQuickTeamOption,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		1,
		MENUITEMFLAG_BIGFONT,
		L_MISC_464, // "Players and Simulants"
		0,
		menuhandlerMpQuickTeamOption,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		2,
		MENUITEMFLAG_BIGFONT,
		L_MISC_465, // "Player Teams"
		0,
		menuhandlerMpQuickTeamOption,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		3,
		MENUITEMFLAG_BIGFONT,
		L_MISC_466, // "Players vs. Simulants"
		0,
		menuhandlerMpQuickTeamOption,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		4,
		MENUITEMFLAG_BIGFONT,
		L_MISC_467, // "Player-Simulant Teams"
		0,
		menuhandlerMpQuickTeamOption,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpQuickTeamMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_462, // "Quick Team"
	g_MpQuickTeamMenuItems,
	NULL,
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
};

struct menuitem g_CombatSimulatorMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_BIGFONT,
		L_MISC_441, // "Challenges"
		0,
		(void *)&g_MpChallengesMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_BIGFONT,
		L_MISC_442, // "Load/Preset Games"
		0x00000001,
		(void *)&g_MpLoadPresetMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_BIGFONT,
		L_MISC_443, // "Quick Start"
		0x00000002,
		(void *)&g_MpQuickTeamMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_BIGFONT,
		L_MISC_444, // "Advanced Setup"
		0x00000003,
		menuhandlerMpAdvancedSetup,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CombatSimulatorMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_445, // "Combat Simulator"
	g_CombatSimulatorMenuItems,
	menudialogCombatSimulator,
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
};

void func0f17fcb0(s32 silent)
{
	g_Menus[g_MpPlayerNum].playernum = g_MpPlayerNum;

	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
		menuPushRootDialog(&g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog, MENUROOT_MPSETUP);
	} else {
		menuPushRootDialog(&g_MpAdvancedSetupMenuDialog, MENUROOT_MPSETUP);
	}

	func0f0f8300();

	if (!silent) {
		// Explosion sound
		sndStart(var80095200, SFX_EXPLOSION_809A, NULL, -1, -1, -1, -1, -1);
	}
}
