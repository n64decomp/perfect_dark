#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/text.h"
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

struct menuitem g_MpCharacterMenuItems[];
struct menudialogdef g_MpAddSimulantMenuDialog;
struct menudialogdef g_MpChangeSimulantMenuDialog;
struct menudialogdef g_MpChangeTeamNameMenuDialog;
struct menudialogdef g_MpEditSimulantMenuDialog;
struct menudialogdef g_MpSaveSetupNameMenuDialog;

void func0f17b8f0(void);
MenuItemHandlerResult menuhandler0017e9d8(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_start_challenge(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_abort_challenge(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler0017ec64(s32 operation, struct menuitem *item, union handlerdata *data);
void mp_close_dialogs_for_new_setup(void);

MenuItemHandlerResult menuhandler_mp_drop_out(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_pop_dialog();
		menu_pop_dialog();
	}

	return 0;
}

char *mp_get_current_player_name(struct menuitem *item)
{
	return g_PlayerConfigsArray[g_MpPlayerNum].base.name;
}

MenuItemHandlerResult menuhandler_mp_teams_label(s32 operation, struct menuitem *item, union handlerdata *data)
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
		menuhandler_mp_drop_out,
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

s32 mp_get_num_stages(void)
{
	return 17;
}

s16 mp_choose_random_stage(void)
{
	s32 i;
	s32 numchallengescomplete = 0;
	s32 index;

	for (i = 0; i < 16; i++) {
		if (challenge_is_feature_unlocked(g_MpArenas[i].requirefeature)) {
			numchallengescomplete++;
		}
	}

	index = random() % numchallengescomplete;

	for (i = 0; i < 16; i++) {
		if (challenge_is_feature_unlocked(g_MpArenas[i].requirefeature)) {
			if (index == 0) {
				return g_MpArenas[i].stagenum;
			}

			index--;
		}
	}

	return STAGE_MP_SKEDAR;
}

MenuItemHandlerResult mp_arena_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
			if (challenge_is_feature_unlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}

		data->list.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (challenge_is_feature_unlocked(g_MpArenas[i].requirefeature)) {
				if (count == data->list.value) {
					return (s32)lang_get(g_MpArenas[i].name);
				}

				count++;
			}
		}
		break;
	case MENUOP_SET:
		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (challenge_is_feature_unlocked(g_MpArenas[i].requirefeature)) {
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

			if (challenge_is_feature_unlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 3;

		if (!challenge_is_feature_unlocked(MPFEATURE_STAGE_COMPLEX)
				&& !challenge_is_feature_unlocked(MPFEATURE_STAGE_TEMPLE)
				&& !challenge_is_feature_unlocked(MPFEATURE_STAGE_FELICITY)) {
			data->list.value--;
		}
		break;
	case MENUOP_GETOPTGROUPTEXT:
		count = data->list.value;

		if (!challenge_is_feature_unlocked(MPFEATURE_STAGE_COMPLEX)
				&& !challenge_is_feature_unlocked(MPFEATURE_STAGE_TEMPLE)
				&& !challenge_is_feature_unlocked(MPFEATURE_STAGE_FELICITY)
				&& count > 0) {
			count++;
		}
		return (s32)lang_get(groups[count].name);
	case MENUOP_GETGROUPSTARTINDEX:
		groupindex = data->list.value;

		if (!challenge_is_feature_unlocked(MPFEATURE_STAGE_COMPLEX)
				&& !challenge_is_feature_unlocked(MPFEATURE_STAGE_TEMPLE)
				&& !challenge_is_feature_unlocked(MPFEATURE_STAGE_FELICITY)
				&& groupindex == 1) {
			groupindex++;
		}

		for (i = 0; i < groups[groupindex].offset; i++) {
			if (challenge_is_feature_unlocked(g_MpArenas[i].requirefeature)) {
				count++;
			}
		}
		data->list.groupstartindex = count;
		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_control_style(s32 operation, struct menuitem *item, union handlerdata *data)
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
		return (s32) lang_get(labels[data->dropdown.value]);
	case MENUOP_SET:
		options_set_control_mode(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = options_get_control_mode(g_MpPlayerNum);
		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_weapon_slot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = mp_get_num_weapon_options();
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) mp_get_weapon_label(data->dropdown.value);
	case MENUOP_SET:
		mp_set_weapon_slot(item->param3, data->dropdown.value);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = mp_get_weapon_slot(item->param3);
	}

	return 0;
}

char *mp_menu_text_weapon_name_for_slot(struct menuitem *item)
{
	return mp_get_weapon_label(mp_get_weapon_slot(item->param));
}

MenuItemHandlerResult menuhandler_mp_weapon_set_dropdown(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = func0f189058(item->param);
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) mp_get_weapon_set_name(data->dropdown.value);
	case MENUOP_SET:
		mp_set_weapon_set(data->dropdown.value);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = mp_get_weapon_set();
		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_control_checkbox(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult menuhandler_mp_aim_control(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
#if VERSION >= VERSION_PAL_FINAL
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
		return (s32) lang_get(labels[data->dropdown.value]);
	case MENUOP_SET:
		options_set_aim_control(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = options_get_aim_control(g_MpPlayerNum);
		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_checkbox_option(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult menuhandler_mp_teams_enabled(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE ||
				g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			return true;
		}

		return false;
	}

	return menuhandler_mp_checkbox_option(operation, item, data);
}

MenuItemHandlerResult menuhandler_mp_display_option_checkbox(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult menuhandler_mp_confirm_save_chr(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_pop_dialog();
		filemgr_push_select_location_dialog(6, FILETYPE_MPPLAYER);
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_setup_name(s32 operation, struct menuitem *item, union handlerdata *data)
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
		filemgr_push_select_location_dialog(7, FILETYPE_MPSETUP);
		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_save_setup_overwrite(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_pop_dialog();
		filemgr_save_or_load(&g_MpSetup.fileguid, FILEOP_SAVE_MPSETUP, 0);
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_save_setup_copy(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_pop_dialog();
		menu_push_dialog(&g_MpSaveSetupNameMenuDialog);
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
char *mp_menu_text_setup_name(struct menuitem *item)
{
	return g_MpSetup.name;
}
#endif

MenuItemHandlerResult func0f179b68(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult func0f179c14(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult func0f179cc0(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult func0f179d6c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f187fbc(g_MpPlayerNum);
	}

	return 0;
}

/**
 * This function is used by both player body selection and bot body selection.
 */
MenuItemHandlerResult mp_character_body_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data, s32 mpbodynum, s32 mpheadnum, bool isplayer)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->carousel.value = mp_get_num_bodies();
		break;
	case MENUOP_11:
		g_Menus[g_MpPlayerNum].menumodel.newanimnum = ANIM_01FC;
		g_Menus[g_MpPlayerNum].menumodel.newparams = MENUMODELPARAMS_SET_MP_HEADBODY(mpheadnum, mpbodynum);
		g_Menus[g_MpPlayerNum].menumodel.zoomtimer60 += g_Vars.diffframe60;

		if (g_Menus[g_MpPlayerNum].menumodel.zoomtimer60 > TICKS(480)) {
			g_Menus[g_MpPlayerNum].menumodel.zoomtimer60 -= TICKS(480);
		}

		if (g_Menus[g_MpPlayerNum].menumodel.rottimer60 > 0) {
			g_Menus[g_MpPlayerNum].menumodel.rottimer60 -= g_Vars.diffframe60;
		} else {
#if VERSION >= VERSION_PAL_BETA
			f32 value = g_Menus[g_MpPlayerNum].menumodel.curroty + 0.01f * g_Vars.diffframe60freal;
#else
			f32 value = g_Menus[g_MpPlayerNum].menumodel.curroty + 0.01f * g_Vars.diffframe60f;
#endif
			g_Menus[g_MpPlayerNum].menumodel.newroty = value;
			g_Menus[g_MpPlayerNum].menumodel.curroty = value;
		}

		g_Menus[g_MpPlayerNum].menumodel.partvisibility = NULL;
		g_Menus[g_MpPlayerNum].menumodel.zoom = 30;
		break;
	case MENUOP_21:
		if (!challenge_is_feature_unlocked(mp_get_body_required_feature(data->carousel.value))) {
			return 1;
		}
		break;
#if VERSION >= VERSION_NTSC_1_0
	case MENUOP_FOCUS:
		g_Menus[g_MpPlayerNum].menumodel.loaddelay = 3;
		break;
#endif
	case MENUOP_GETSELECTEDINDEX:
		data->carousel.value = mpbodynum;
		break;
	case MENUOP_SET:
	case MENUOP_CHECKPREFOCUSED:
		g_Menus[g_MpPlayerNum].menumodel.removingpiece = false;

		menu_configure_model(&g_Menus[g_MpPlayerNum].menumodel, 0, 0, 0, 0, 0, 0, 1, MENUMODELFLAG_HASSCALE);

		g_Menus[g_MpPlayerNum].menumodel.curposx = 8.2f;
		g_Menus[g_MpPlayerNum].menumodel.newposx = 8.2f;

		g_Menus[g_MpPlayerNum].menumodel.curposy = -4.1f;
		g_Menus[g_MpPlayerNum].menumodel.newposy = -4.1f;

		g_Menus[g_MpPlayerNum].menumodel.curscale = 0.002f;

		g_Menus[g_MpPlayerNum].menumodel.curroty = -0.2f;
		g_Menus[g_MpPlayerNum].menumodel.newroty = -0.2f;

		g_Menus[g_MpPlayerNum].menumodel.rottimer60 = TICKS(60);
		g_Menus[g_MpPlayerNum].menumodel.zoomtimer60 = TICKS(120);
		g_Menus[g_MpPlayerNum].menumodel.loaddelay = 8;

#if VERSION >= VERSION_NTSC_1_0
		if (operation == MENUOP_CHECKPREFOCUSED) {
			g_Menus[g_MpPlayerNum].menumodel.loaddelay = 16;
		}
#endif

		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_character_body(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		if (g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum < mp_get_num_heads()) {
#if VERSION >= VERSION_NTSC_1_0
			if (!data->carousel.unk04)
#endif
			{
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum = mp_get_mpheadnum_by_mpbodynum(data->carousel.value);
			}
		}
		g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum = data->carousel.value;
		func0f17b8f0();
		break;
	case MENUOP_CHECKPREFOCUSED:
#if VERSION >= VERSION_NTSC_1_0
		mp_character_body_menu_handler(operation, item, data,
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum,
				g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, true);
#endif
		return true;
	}

	return mp_character_body_menu_handler(operation, item, data,
			g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum,
			g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, true);
}

MenuDialogHandlerResult menudialog0017a174(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
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
			menuhandler_mp_character_body(MENUOP_11, &dialogdef->items[2], &data);
		}
	}

	return 0;
}

MenuItemHandlerResult mp_challenges_list_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
		data->list.value = challenge_get_auto_focused_index(g_MpPlayerNum);
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

		gdl = text_begin(gdl);

		name = challenge_get_name2(g_MpPlayerNum, challengeindex);

		gdl = text_render_v2(gdl, &x, &y, name,
				g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour,
				vi_get_width(), vi_get_height(), 0, 0);

		gdl = text_end(gdl);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		tex_select(&gdl, &g_TexGeneralConfigs[TEX_GENERAL_ENVSTAR], 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		for (i = 0, loopx = 10; i < maxplayers; i++) {
#if VERSION >= VERSION_NTSC_1_0
			if (challenge_is_completed_by_player_with_num_players2(g_MpPlayerNum, challengeindex, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, 0xb2efff00 | (renderdata->colour & 0xff) * 255 / 256);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0x30407000 | (renderdata->colour & 0xff) * 255 / 256);
			}
#else
			if (challenge_is_completed_by_player_with_num_players2(g_MpPlayerNum, challengeindex, i + 1)) {
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
					((renderdata->x + loopx) << 2) * g_UiScaleX,
					(renderdata->y + size) << 2,
					((renderdata->x + size + loopx) << 2) * g_UiScaleX,
					(renderdata->y + size * 2) << 2,
					G_TX_RENDERTILE,
					0, 0x0160, 0x0400 / g_UiScaleX, 0xfc00);

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

char *mp_menu_text_kills(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].kills);
	return g_StringPointer;
}

char *mp_menu_text_deaths(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].deaths);
	return g_StringPointer;
}

char *mp_menu_text_games_played(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gamesplayed);
	return g_StringPointer;
}

char *mp_menu_text_games_won(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gameswon);
	return g_StringPointer;
}

char *mp_menu_text_games_lost(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].gameslost);
	return g_StringPointer;
}

char *mp_menu_text_head_shots(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].headshots);
	return g_StringPointer;
}

char *mp_menu_text_medal_accuracy(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].accuracymedals);
	return g_StringPointer;
}

char *mp_menu_text_medal_head_shot(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].headshotmedals);
	return g_StringPointer;
}

char *mp_menu_text_medal_kill_master(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].killmastermedals);
	return g_StringPointer;
}

char *mp_menu_text_medal_survivor(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_PlayerConfigsArray[g_MpPlayerNum].survivormedals);
	return g_StringPointer;
}

char *mp_menu_text_ammo_used(struct menuitem *item)
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

char *mp_menu_text_distance(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s%s%.1fkm\n", "", "", g_PlayerConfigsArray[g_MpPlayerNum].distance / 10.0f);
	return g_StringPointer;
}

char *mp_menu_text_time(struct menuitem *item)
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

char *mp_menu_text_accuracy(struct menuitem *item)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_PlayerConfigsArray[g_MpPlayerNum].gamesplayed < 8) {
		return "-\n";
	}
#endif

	sprintf(g_StringPointer, "%s%s%.1f%%", "", "", g_PlayerConfigsArray[g_MpPlayerNum].accuracy / 10.0f);
	return g_StringPointer;
}

void mp_format_damage_value(char *dst, f32 damage)
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

char *mp_menu_text_pain_received(struct menuitem *item)
{
	mp_format_damage_value(g_StringPointer, g_PlayerConfigsArray[g_MpPlayerNum].painreceived / 10.0f);
	return g_StringPointer;
}

char *mp_menu_text_damage_dealt(struct menuitem *item)
{
	mp_format_damage_value(g_StringPointer, g_PlayerConfigsArray[g_MpPlayerNum].damagedealt / 10.0f);
	return g_StringPointer;
}

MenuItemHandlerResult mp_medal_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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

		tex_select(&gdl, &g_TexGeneralConfigs[TEX_GENERAL_ENVSTAR], 2, 0, 2, 1, NULL);

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
		colour = (colour & 0xffffff00) | (colour & 0xff) * (renderdata->colour & 0xff) >> 8;
#endif

		gDPSetEnvColorViaWord(gdl++, colour);

		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0);

		gSPTextureRectangle(gdl++,
				((renderdata->x + 9) << 2) * g_UiScaleX, renderdata->y << 2,
				((renderdata->x + 20) << 2) * g_UiScaleX, (renderdata->y + 11) << 2,
				G_TX_RENDERTILE, 0, 0x0160, 1024 / g_UiScaleX, -1024);

		return (s32) gdl;
	}

	return 0;
}

char *mp_menu_title_stats_for_player_name(struct menudialogdef *dialogdef)
{
	// "Stats for %s"
	sprintf(g_StringPointer, lang_get(L_MPMENU_145), g_PlayerConfigsArray[g_MpPlayerNum].base.name);
	return g_StringPointer;
}

MenuItemHandlerResult menuhandler_mp_username_password(s32 operation, struct menuitem *item, union handlerdata *data)
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
		menuhandler_mp_confirm_save_chr,
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
#if VERSION != VERSION_JPN_FINAL
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_189, // "Enter a name for your game setup file:"
		0,
		NULL,
	},
#endif
	{
		MENUITEMTYPE_KEYBOARD,
		0,
		0,
		0,
		0,
		menuhandler_mp_setup_name,
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
#if VERSION >= VERSION_NTSC_1_0
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_MPWEAPONS_230, // "Name:"
		(uintptr_t)&mp_menu_text_setup_name,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
		(uintptr_t)&filemgr_menu_text_device_name,
		0,
		NULL,
	},
#endif
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
		menuhandler_mp_save_setup_overwrite,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_186, // "Save Copy"
		0,
		menuhandler_mp_save_setup_copy,
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
		menuhandler_mp_weapon_set_dropdown,
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
		menuhandler_mp_weapon_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_177, // "2:"
		1,
		menuhandler_mp_weapon_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_178, // "3:"
		2,
		menuhandler_mp_weapon_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_179, // "4:"
		3,
		menuhandler_mp_weapon_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_180, // "5:"
		4,
		menuhandler_mp_weapon_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_DROPDOWN_BELOW | MENUITEMFLAG_LOCKABLEMINOR | MENUITEMFLAG_MPWEAPONSLOT,
		L_MPMENU_181, // "6:"
		5,
		menuhandler_mp_weapon_slot,
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
		menuhandler_mp_weapon_set_dropdown,
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
		(uintptr_t)&mp_menu_text_weapon_name_for_slot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		1,
		MENUITEMFLAG_00000002,
		L_MPMENU_177, // "2:"
		(uintptr_t)&mp_menu_text_weapon_name_for_slot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		2,
		MENUITEMFLAG_00000002,
		L_MPMENU_178, // "3:"
		(uintptr_t)&mp_menu_text_weapon_name_for_slot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		3,
		MENUITEMFLAG_00000002,
		L_MPMENU_179, // "4:"
		(uintptr_t)&mp_menu_text_weapon_name_for_slot,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		4,
		MENUITEMFLAG_00000002,
		L_MPMENU_180, // "5:"
		(uintptr_t)&mp_menu_text_weapon_name_for_slot,
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
		menuhandler_mp_display_option_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_169, // "Highlight Players"
		MPDISPLAYOPTION_HIGHLIGHTPLAYERS,
		menuhandler_mp_display_option_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_170, // "Highlight Teams"
		MPDISPLAYOPTION_HIGHLIGHTTEAMS,
		menuhandler_mp_display_option_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_171, // "Radar"
		MPDISPLAYOPTION_RADAR,
		menuhandler_mp_display_option_checkbox,
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
		menuhandler_mp_control_style,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_201, // "Reverse Pitch"
		OPTION_FORWARDPITCH,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_202, // "Look Ahead"
		OPTION_LOOKAHEAD,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_203, // "Head Roll"
		OPTION_HEADROLL,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_204, // "Auto-Aim"
		OPTION_AUTOAIM,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MPMENU_205, // "Aim Control"
		0,
		menuhandler_mp_aim_control,
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
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_207, // "Show Target"
		OPTION_ALWAYSSHOWTARGET,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_208, // "Zoom Range"
		OPTION_SHOWZOOMRANGE,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_209, // "Ammo on Screen"
		OPTION_AMMOONSCREEN,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_210, // "Gun Function"
		OPTION_SHOWGUNFUNCTION,
		menuhandler_mp_control_checkbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPMENU_211, // "Paintball"
		OPTION_PAINTBALL,
		menuhandler_mp_control_checkbox,
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
		mp_challenges_list_handler,
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

#if VERSION >= VERSION_NTSC_1_0
char *mp_menu_text_username_password(struct menuitem *item)
{
	// Phrases included here to assist people searching the code for them:
	// EnTROpIcDeCAy
	// ZeRo-Tau

	u8 username[] = {
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

	u8 password[] = {
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
		for (i = 0; i < ARRAYCOUNT(username); i++) {
			g_StringPointer[i] = username[i] - i * 9 - 9;
		}
	} else {
		for (i = 0; i < ARRAYCOUNT(password); i++) {
			g_StringPointer[i] = password[i] - i * 4 - 4;
		}
	}

	return g_StringPointer;
}
#endif

struct menuitem g_MpPlayerStatsMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_146, // "Kills:"
		(uintptr_t)&mp_menu_text_kills,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_147, // "Deaths:"
		(uintptr_t)&mp_menu_text_deaths,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_148, // "Accuracy:"
		(uintptr_t)&mp_menu_text_accuracy,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_149, // "Head Shots:"
		(uintptr_t)&mp_menu_text_head_shots,
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
		(uintptr_t)&mp_menu_text_ammo_used,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_151, // "Damage Dealt:"
		(uintptr_t)&mp_menu_text_damage_dealt,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_152, // "Pain Received:"
		(uintptr_t)&mp_menu_text_pain_received,
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
		(uintptr_t)&mp_menu_text_games_played,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_154, // "Games Won:"
		(uintptr_t)&mp_menu_text_games_won,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_155, // "Games Lost:"
		(uintptr_t)&mp_menu_text_games_lost,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_156, // "Time:"
		(uintptr_t)&mp_menu_text_time,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPMENU_157, // "Distance:"
		(uintptr_t)&mp_menu_text_distance,
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
		(uintptr_t)&mp_menu_text_medal_accuracy,
		mp_medal_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		1,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_160, // "Head Shot:"
		(uintptr_t)&mp_menu_text_medal_head_shot,
		mp_medal_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_161, // "KillMaster:"
		(uintptr_t)&mp_menu_text_medal_kill_master,
		mp_medal_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		3,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_162, // "Survivor:"
		(uintptr_t)&mp_menu_text_medal_survivor,
		mp_medal_menu_handler,
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
		(uintptr_t)&mp_menu_text_player_title,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_MPWEAPONS_219, // "USERNAME:"
		0,
		menuhandler_mp_username_password,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
#if VERSION >= VERSION_NTSC_1_0
		(uintptr_t)&mp_menu_text_username_password,
#else
		0x51f0,
#endif
		0,
		menuhandler_mp_username_password,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_MPWEAPONS_220, // "PASSWORD:"
		0,
		menuhandler_mp_username_password,
	},
	{
		MENUITEMTYPE_LABEL,
		(VERSION >= VERSION_NTSC_1_0 ? 1 : 0),
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
#if VERSION >= VERSION_NTSC_1_0
		(uintptr_t)&mp_menu_text_username_password,
#else
		0x51f1,
#endif
		0,
		menuhandler_mp_username_password,
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
	(uintptr_t)&mp_menu_title_stats_for_player_name,
	g_MpPlayerStatsMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_MpCompletedChallengesMenuDialog,
};

MenuItemHandlerResult mp_character_head_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data, s32 mpheadnum, bool arg4)
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
		data->carousel.value = mp_get_num_heads2();
		break;
	case MENUOP_11:
#if VERSION >= VERSION_PAL_BETA
		diffframe = g_Menus[g_MpPlayerNum].menumodel.curroty + 0.01f * g_Vars.diffframe60freal;
#else
		diffframe = g_Menus[g_MpPlayerNum].menumodel.curroty + 0.01f * g_Vars.diffframe60f;
#endif

		g_Menus[g_MpPlayerNum].menumodel.newroty = diffframe;
		g_Menus[g_MpPlayerNum].menumodel.curroty = diffframe;

		if (mpheadnum < mp_get_num_heads2()) {
			headnum = mp_get_head_id(mpheadnum);

			g_Menus[g_MpPlayerNum].menumodel.newparams = MENUMODELPARAMS_SET_FILENUM(g_HeadsAndBodies[headnum].filenum);
			g_Menus[g_MpPlayerNum].menumodel.isperfecthead = false;
		} else {
			headnum = mp_get_beau_head_id(phead_get_unk3a4(mpheadnum - mp_get_num_heads2()));

			g_Menus[g_MpPlayerNum].menumodel.newparams = MENUMODELPARAMS_SET_FILENUM(g_HeadsAndBodies[headnum].filenum);
			g_Menus[g_MpPlayerNum].menumodel.isperfecthead = true;
			g_Menus[g_MpPlayerNum].menumodel.perfectheadnum = mpheadnum - mp_get_num_heads2();
		}

		g_Menus[g_MpPlayerNum].menumodel.zoomtimer60 = 0;
		g_Menus[g_MpPlayerNum].menumodel.partvisibility = visibility;
		g_Menus[g_MpPlayerNum].menumodel.zoom = 30;
		break;
	case MENUOP_21:
		if (!challenge_is_feature_unlocked(mp_get_head_required_feature(data->carousel.value))) {
			return 1;
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->carousel.value = mpheadnum;
		break;
	case MENUOP_SET:
	case MENUOP_FOCUS:
#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].menumodel.loaddelay = 3;
#endif

		mp_get_num_heads2();

		menu_configure_model(&g_Menus[g_MpPlayerNum].menumodel, 0, 0, 0, 0, 0, 0, 1, MENUMODELFLAG_HASSCALE);

		g_Menus[g_MpPlayerNum].menumodel.curposx = 0;
		g_Menus[g_MpPlayerNum].menumodel.curposy = 0;

		g_Menus[g_MpPlayerNum].menumodel.newposx = 0;
		g_Menus[g_MpPlayerNum].menumodel.newposy = -3;

		g_Menus[g_MpPlayerNum].menumodel.curscale = 0.01f;

		g_Menus[g_MpPlayerNum].menumodel.curroty = -0.3f;
		g_Menus[g_MpPlayerNum].menumodel.newroty = -0.3f;

		g_Menus[g_MpPlayerNum].menumodel.newscale = 1;
		g_Menus[g_MpPlayerNum].menumodel.zoom = 30;
		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_character_head(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum = data->carousel.value;
	}

	return mp_character_head_menu_handler(operation, item, data, g_PlayerConfigsArray[g_MpPlayerNum].base.mpheadnum, 1);
}

char *mp_menu_text_body_name(struct menuitem *item)
{
	return mp_get_body_name(g_PlayerConfigsArray[g_MpPlayerNum].base.mpbodynum);
}

void func0f17b8f0(void)
{
	func0f0f139c(g_MpCharacterMenuItems, -0.4f);
}

MenuItemHandlerResult mp_player_name_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult mp_load_settings_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = mp_get_num_unlocked_presets();

		if (g_FileLists[1] != NULL) {
			data->list.value += g_FileLists[1]->numfiles;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		if (data->list.value < mp_get_num_unlocked_presets()) {
			return (s32)mp_get_preset_name_by_slot(data->list.value);
		}
		if (g_FileLists[1] != NULL) {
			func0f0d564c(g_FileLists[1]->files[data->list.value - mp_get_num_unlocked_presets()].name, g_StringPointer, false);
			return (s32)g_StringPointer;
		}
		break;
	case MENUOP_SET:
		mp_close_dialogs_for_new_setup();

		if (data->list.value < mp_get_num_unlocked_presets()) {
			mp0f18dec4(data->list.value);
		} else if (g_FileLists[1] != NULL) {
			struct filelistfile *file = &g_FileLists[1]->files[data->list.value - mp_get_num_unlocked_presets()];
			struct fileguid guid;

			guid.fileid = file->fileid;
			guid.deviceserial = file->deviceserial;

			filemgr_save_or_load(&guid, FILEOP_LOAD_MPSETUP, 0);
		}

		if (item->param == 1) {
			if (IS4MB()) {
				func0f0f820c(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
			} else {
				func0f0f820c(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
			}
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
			return (s32)lang_get(L_MPMENU_141); // "Presets"
		}
		if (g_FileLists[1] != NULL) {
			return (s32)filemgr_get_device_name_or_start_index(1, operation, data->list.value - 1);
		}
		break;
	case MENUOP_GETGROUPSTARTINDEX:
		if (data->list.value == 0) {
			data->list.groupstartindex = 0;
		} else {
			data->list.groupstartindex = mp_get_num_unlocked_presets();

			if (g_FileLists[1] != NULL) {
				data->list.groupstartindex += filemgr_get_device_name_or_start_index(1, operation, data->list.value - 1);
			}
		}
		break;
	case MENUOP_LISTITEMFOCUS:
		if (data->list.value < mp_get_num_unlocked_presets()) {
			g_Menus[g_MpPlayerNum].mpsetup.slotindex = 0xffff;
		} else {
			g_Menus[g_MpPlayerNum].mpsetup.slotindex = data->list.value - mp_get_num_unlocked_presets();
		}
		break;
	}

	return 0;
}

char *mp_menu_text_mpconfig_marquee(struct menuitem *item)
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

		mpsetupfile_get_overview(g_FileLists[1]->files[g_Menus[g_MpPlayerNum].mpsetup.slotindex].name,
				filename, &numsims, &stagenum, &scenarionum);

		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (g_MpArenas[i].stagenum == stagenum) {
				arenanum = i;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (scenarionum <= 5 && arenanum != -1 && numsims >= 0 && filename[0] != '\0' && numsims <= MAX_BOTS) {
			// "%s:  Scenario: %s   Arena: %s    Simulants: %d"
			sprintf(g_StringPointer, lang_get(L_MPMENU_140),
					filename,
					lang_get(g_MpScenarioOverviews[scenarionum].name),
					lang_get(g_MpArenas[arenanum].name),
					numsims);
		} else {
			return "";
		}
#else
		// "%s:  Scenario: %s   Arena: %s    Simulants: %d"
		sprintf(g_StringPointer, lang_get(L_MPMENU_140),
				filename,
				lang_get(g_MpScenarioOverviews[scenarionum].name),
				lang_get(g_MpArenas[arenanum].name),
				numsims);
#endif

		return g_StringPointer;
	}

	return "";
}

MenuItemHandlerResult mp_load_player_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
		filemgr_get_select_name(g_StringPointer, &g_FileLists[0]->files[data->list.value], FILETYPE_MPPLAYER);
		return (s32)g_StringPointer;
	case MENUOP_SET:
		file = &g_FileLists[0]->files[data->list.value];
		available = true;

		for (i = 0; i < MAX_PLAYERS; i++) {
			if (file->fileid == g_PlayerConfigsArray[i].fileguid.fileid
					&& file->deviceserial == g_PlayerConfigsArray[i].fileguid.deviceserial) {
				if ((g_MpSetup.chrslots & (1 << i)) == 0) {
					mp_player_set_defaults(i, true);
				} else {
					available = false;
				}
			}
		}

		if (available) {
			guid.fileid = file->fileid;
			guid.deviceserial = file->deviceserial;

			menu_pop_dialog();

			filemgr_save_or_load(&guid, FILEOP_LOAD_MPPLAYER, g_MpPlayerNum);
		} else {
			filemgr_push_error_dialog(FILEERROR_ALREADYLOADED);
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = 0xfffff;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = g_FileLists[0]->numdevices;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return filemgr_get_device_name_or_start_index(0, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = filemgr_get_device_name_or_start_index(0, operation, data->list.value);
		return 0;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_time_limit_slider(s32 operation, struct menuitem *item, union handlerdata *data)
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
			sprintf(data->slider.label, lang_get(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, lang_get(L_MPMENU_114), data->slider.value + 1); // "%d Min"
		}
	}
	return 0;
}

MenuItemHandlerResult menuhandler_mp_score_limit_slider(s32 operation, struct menuitem *item, union handlerdata *data)
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
			sprintf(data->slider.label, lang_get(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, lang_get(L_MPMENU_113), data->slider.value + 1); // "%d"
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_team_score_limit_slider(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = mp_calculate_team_score_limit();
		break;
	case MENUOP_SET:
		g_MpSetup.teamscorelimit = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (data->slider.value == 400) {
			sprintf(data->slider.label, lang_get(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, lang_get(L_MPMENU_113), data->slider.value + 1); // "%d"
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_restore_score_defaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f187fec();
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_handicap_player(s32 operation, struct menuitem *item, union handlerdata *data)
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
		sprintf(data->slider.label, "%s%s%.00f%%\n", "", "", mp_handicap_to_damage_scale(g_PlayerConfigsArray[item->param].handicap) * 100);
		break;
	}

	return 0;
}

char *mp_menu_text_handicap_player_name(struct menuitem *item)
{
	if (g_MpSetup.chrslots & (1 << item->param)) {
		return g_PlayerConfigsArray[item->param].base.name;
	}

	return "";
}

MenuItemHandlerResult menuhandler_mp_restore_handicap_defaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i < MAX_PLAYERS; i++) {
			g_PlayerConfigsArray[i].handicap = 0x80;
		}
	}

	return 0;
}

MenuDialogHandlerResult menudialog_mp_ready(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid && g_PlayerConfigsArray[g_MpPlayerNum].fileguid.deviceserial) {
			filemgr_save_or_load(&g_PlayerConfigsArray[g_MpPlayerNum].fileguid, FILEOP_SAVE_MPPLAYER, g_MpPlayerNum);
		}
	}

	return false;
}

MenuDialogHandlerResult menudialog_mp_simulant(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if ((u8)g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.name[0] == '\0') {
			menu_pop_dialog();
		}
	}

	return false;
}

struct menuitem g_MpCharacterMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_DARKERBG,
		(uintptr_t)&mp_menu_text_body_name,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_CAROUSEL,
		0,
		0,
		0,
		0x00000022,
		menuhandler_mp_character_head,
	},
	{
		MENUITEMTYPE_CAROUSEL,
		0,
		0,
		0,
		0x0000001b,
		menuhandler_mp_character_body,
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
		mp_player_name_menu_handler,
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
		mp_load_settings_menu_handler,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(uintptr_t)&mp_menu_text_mpconfig_marquee,
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
		mp_load_settings_menu_handler,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(uintptr_t)&mp_menu_text_mpconfig_marquee,
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
		mp_load_player_menu_handler,
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
		mp_arena_menu_handler,
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
		menuhandler_mp_time_limit_slider,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_109, // "Score"
		0x00000064,
		menuhandler_mp_score_limit_slider,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		L_MISC_447, // "Team Score"
		0x00000190,
		menuhandler_mp_team_score_limit_slider,
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
		menuhandler_mp_restore_score_defaults,
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
		(uintptr_t)&mp_menu_text_handicap_player_name,
		0x000000ff,
		menuhandler_mp_handicap_player,
	},
	{
		MENUITEMTYPE_SLIDER,
		1,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_handicap_player_name,
		0x000000ff,
		menuhandler_mp_handicap_player,
	},
	{
		MENUITEMTYPE_SLIDER,
		2,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_handicap_player_name,
		0x000000ff,
		menuhandler_mp_handicap_player,
	},
	{
		MENUITEMTYPE_SLIDER,
		3,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_handicap_player_name,
		0x000000ff,
		menuhandler_mp_handicap_player,
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
		menuhandler_mp_restore_handicap_defaults,
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
	menudialog_mp_ready,
	MENUDIALOGFLAG_CLOSEONSELECT,
	NULL,
};

MenuItemHandlerResult mp_add_change_simulant_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->list.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->list.value) {
					return (s32)lang_get(g_BotProfiles[i].name);
				}

				count++;
			}
		}
		break;
	case MENUOP_SET:
		botnum = g_Menus[g_MpPlayerNum].mpsetup.slotindex;
		creating = false;

		if (botnum < 0) {
			botnum = mp_get_slot_for_new_bot();
			creating = 1;
		} else if ((g_MpSetup.chrslots & (1 << (botnum + 4))) == 0) {
			creating = 1;
		}

		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->list.value) {
					break;
				}

				count++;
			}
		}

		if (creating) {
			mp_create_bot_from_profile(botnum, i);
		} else {
			g_BotConfigsArray[botnum].type = g_BotProfiles[i].type;

			if (g_BotConfigsArray[botnum].type == BOTTYPE_GENERAL) {
				mp_set_bot_difficulty(botnum, g_BotProfiles[i].difficulty);
			}
		}

		mp_generate_bot_names();
		g_Menus[g_MpPlayerNum].mpsetup.slotcount = data->list.value;
		break;
	case MENUOP_LISTITEMFOCUS:
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
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
		return (s32)lang_get(groups[data->list.value].name);
	case MENUOP_GETGROUPSTARTINDEX:
		for (i = 0; i < groups[data->list.value].offset; i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->list.groupstartindex = count;
		break;
	}

	return 0;
}

char *mp_menu_text_simulant_description(struct menuitem *item)
{
	return lang_get(L_MISC_106 + g_Menus[g_MpPlayerNum].mpsetup.unke24);
}

MenuItemHandlerResult menuhandler_mp_simulant_head(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 start = 0;

	if (item->param2 == 1) {
		start = mp_get_num_heads();
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

	return mp_character_head_menu_handler(operation, item, data, g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum, 0);
}

MenuItemHandlerResult menuhandler_mp_simulant_body(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpbodynum = data->carousel.value;
	}

	return mp_character_body_menu_handler(operation, item, data,
			g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpbodynum,
			g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.mpheadnum,
			false);
}

MenuDialogHandlerResult menudialog0017ccfc(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem != &dialogdef->items[0]
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem != &dialogdef->items[1]) {
			union handlerdata data;
			menuhandler_mp_character_body(MENUOP_11, &dialogdef->items[1], &data);
		}
	}

	return menudialog_mp_simulant(operation, dialogdef, data);
}

MenuItemHandlerResult mp_bot_difficulty_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 count = 0;
	s32 i;

	switch (operation) {
	case MENUOP_SET:
		mp_set_bot_difficulty(g_Menus[g_MpPlayerNum].mpsetup.slotindex, data->dropdown.value);
		mp_generate_bot_names();
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
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->dropdown.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < BOTDIFF_DISABLED; i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->dropdown.value) {
					// "Meat", "Easy", "Normal" etc
					return (s32) lang_get(L_MISC_082 + i);
				}

				count++;
			}
		}

		return (s32)"\n";
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_delete_simulant(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mp_remove_simulant(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
		menu_pop_dialog();
	}

	return 0;
}

char *mp_menu_title_edit_simulant(struct menudialogdef *dialogdef)
{
	sprintf(g_StringPointer, "%s", &g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].base.name);
	return g_StringPointer;
}

MenuItemHandlerResult menuhandler_mp_change_simulant_type(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		s32 count = 0;
		s32 profilenum = mp_find_bot_profile(
				g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].type,
				g_BotConfigsArray[g_Menus[g_MpPlayerNum].mpsetup.slotindex].difficulty);

		for (i = 0; i < profilenum; i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		g_Menus[g_MpPlayerNum].mpsetup.slotcount = count;

		menu_push_dialog(&g_MpChangeSimulantMenuDialog);
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_clear_all_simulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		for (i = 0; i < MAX_BOTS; i++) {
			mp_remove_simulant(i);
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_add_simulant(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = -1;
		menu_push_dialog(&g_MpAddSimulantMenuDialog);
		break;
	case MENUOP_CHECKDISABLED:
		if (mp_has_unused_bot_slots() == 0) {
			return true;
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_simulant_slot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = item->param;

		if ((g_MpSetup.chrslots & (1 << (item->param + 4))) == 0) {
			menu_push_dialog(&g_MpAddSimulantMenuDialog);
		} else if (IS4MB()) {
			menu_push_dialog(&g_MpEditSimulant4MbMenuDialog);
		} else {
			menu_push_dialog(&g_MpEditSimulantMenuDialog);
		}
		break;
	case MENUOP_CHECKHIDDEN:
		if (item->param >= 4 && !challenge_is_feature_unlocked(MPFEATURE_8BOTS)) {
			return true;
		}
		break;
	case MENUOP_CHECKDISABLED:
		if (!mp_is_sim_slot_enabled(item->param)) {
			return true;
		}
	}

	return 0;
}

char *mp_menu_text_simulant_name(struct menuitem *item)
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

MenuDialogHandlerResult menudialog_mp_simulants(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
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
		mp_add_change_simulant_menu_handler,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(uintptr_t)&mp_menu_text_simulant_description,
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
	menudialog_mp_simulant,
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
		menuhandler_mp_simulant_head,
	},
	{
		MENUITEMTYPE_CAROUSEL,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		0,
		0x0000001b,
		menuhandler_mp_simulant_body,
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
		mp_bot_difficulty_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_096, // "Change Type..."
		0,
		menuhandler_mp_change_simulant_type,
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
		menuhandler_mp_delete_simulant,
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
	(uintptr_t)&mp_menu_title_edit_simulant,
	g_MpEditSimulantMenuItems,
	menudialog_mp_simulant,
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
		menuhandler_mp_add_simulant,
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
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		1,
		0,
		L_MPMENU_086, // "2:"
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		2,
		0,
		L_MPMENU_087, // "3:"
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		3,
		0,
		L_MPMENU_088, // "4:"
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		4,
		0,
		L_MPMENU_089, // "5:"
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		5,
		0,
		L_MPMENU_090, // "6:"
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		6,
		0,
		L_MPMENU_091, // "7:"
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		7,
		0,
		L_MPMENU_092, // "8:"
		(uintptr_t)&mp_menu_text_simulant_name,
		menuhandler_mp_simulant_slot,
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
		menuhandler_mp_clear_all_simulants,
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
	menudialog_mp_simulants,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

MenuItemHandlerResult menuhandler_mp_n_teams(s32 operation, struct menuitem *item, union handlerdata *data, s32 numteams)
{
	if (operation == MENUOP_SET) {
		s32 numchrs = mp_get_num_chrs();
		s32 array[] = {0, 0, 0, 0};
		s32 somevalue = (numchrs + numteams - 1) / numteams;
		s32 teamsremaining = numteams;
		s32 chrsremaining = numchrs;
		s32 start = random() % numchrs;

		s32 i;
		s32 teamnum;

#if VERSION >= VERSION_NTSC_1_0
		if (!numchrs) {
			return 0;
		}
#endif

		i = (start + 1) % numchrs;

		do {
			struct mpchrconfig *mpchr = mp_get_chr_config_by_slot_num(i);

#if VERSION >= VERSION_NTSC_1_0
			if (teamsremaining);
#else
			if (start);
#endif

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

		menu_pop_dialog();
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_two_teams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandler_mp_n_teams(operation, item, data, 2);
}

MenuItemHandlerResult menuhandler_mp_three_teams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandler_mp_n_teams(operation, item, data, 3);
}

MenuItemHandlerResult menuhandler_mp_four_teams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandler_mp_n_teams(operation, item, data, 4);
}

MenuItemHandlerResult menuhandler_mp_maximum_teams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		u8 team = 0;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *mpchr = MPCHR(i);

				mpchr->team = team++;

				if (team >= scenario_get_max_teams()) {
					team = 0;
				}
			}
		}

		menu_pop_dialog();
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_humans_vs_simulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *mpchr = MPCHR(i);

				mpchr->team = i < 4 ? 0 : 1;
			}
		}

		menu_pop_dialog();
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_human_simulant_pairs(s32 operation, struct menuitem *item, union handlerdata *data)
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

		menu_pop_dialog();
	}

	return 0;
}

char *mp_menu_text_chr_name_for_team_setup(struct menuitem *item)
{
	struct mpchrconfig *mpchr = mp_get_chr_config_by_slot_num(item->param);

	if (mpchr) {
		return mpchr->name;
	}

	return "";
}

MenuItemHandlerResult func0f17dac4(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = scenario_get_max_teams();
		break;
	case MENUOP_GETOPTIONTEXT:
		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) {
			return (s32) "\n";
		}

		return (s32) g_BossFile.teamnames[data->list.value];
	}

	return menuhandler_mp_teams_label(operation, item, data);
}

MenuItemHandlerResult menuhandler_mp_team_slot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct mpchrconfig *mpchr;

	switch (operation) {
	case MENUOP_SET:
		mpchr = mp_get_chr_config_by_slot_num(item->param);
		mpchr->team = data->dropdown.value;
		break;
	case MENUOP_GETSELECTEDINDEX:
		mpchr = mp_get_chr_config_by_slot_num(item->param);

		if (!mpchr) {
			data->dropdown.value = 0xff;
		} else {
			data->dropdown.value = mpchr->team;
		}

		break;
	case MENUOP_CHECKDISABLED:
		mpchr = mp_get_chr_config_by_slot_num(item->param);

		if (!mpchr) {
			return 1;
		}

		return menuhandler_mp_teams_label(operation, item, data);
	}

	return func0f17dac4(operation, item, data);
}

char *mp_menu_text_select_tune_or_tunes(struct menuitem *item)
{
	if (mp_get_using_multiple_tunes()) {
		return lang_get(L_MPMENU_069); // "Select Tune"
	}

	return lang_get(L_MPMENU_068); // "Select Tunes"
}

struct menuitem g_MpAutoTeamMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_076, // "Two Teams"
		0,
		menuhandler_mp_two_teams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_077, // "Three Teams"
		0,
		menuhandler_mp_three_teams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_078, // "Four Teams"
		0,
		menuhandler_mp_four_teams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_079, // "Maximum Teams"
		0,
		menuhandler_mp_maximum_teams,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_080, // "Humans vs. Simulants"
		0,
		menuhandler_mp_humans_vs_simulants,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_081, // "Human-Simulant Pairs"
		0,
		menuhandler_mp_human_simulant_pairs,
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
		menuhandler_mp_teams_enabled,
	},
#if VERSION >= VERSION_PAL_FINAL
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x85,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPMENU_072, // "Teams:"
		0,
		menuhandler_mp_teams_label,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		1,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		2,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		3,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		4,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		5,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		6,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		7,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		8,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		9,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		10,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		11,
		MENUITEMFLAG_ADJUSTWIDTH | MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
#else
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
		menuhandler_mp_teams_label,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		1,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		2,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		3,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		4,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		5,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		6,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		7,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		8,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		9,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		10,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		11,
		MENUITEMFLAG_LOCKABLEMINOR,
		(uintptr_t)&mp_menu_text_chr_name_for_team_setup,
		0,
		menuhandler_mp_team_slot,
	},
#endif
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
MenuItemHandlerResult mp_select_tune_list_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = mp_get_num_unlocked_tracks();

		if (mp_get_using_multiple_tunes()) {
			data->list.value += 3;
		} else {
			data->list.value++;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		{
			s32 numtracks = mp_get_num_unlocked_tracks();

			if (data->list.value < numtracks) {
				return (s32) mp_get_track_name(data->list.value);
			}

			if (mp_get_using_multiple_tunes()) {
				return (s32) lang_get(var80085ce8[1 + data->list.value - numtracks]);
			}

			return (s32) lang_get(var80085ce8[data->list.value - numtracks]);
		}
	case MENUOP_SET:
		{
			s32 numtracks = mp_get_num_unlocked_tracks();

			if (data->list.value < numtracks) {
				if (data->list.unk04 == 0) {
					mp_set_track_slot_enabled(data->list.value);
				}
				g_Vars.modifiedfiles |= MODFILE_MPSETUP;
			} else if (mp_get_using_multiple_tunes()) {
				s32 index = data->list.value - numtracks;

				switch (index) {
				case 0:
					mp_enable_all_multi_tracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				case 1:
					mp_disable_all_multi_tracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				case 2:
					mp_randomise_multi_tracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				}
			} else {
				mp_set_track_to_random();
				g_Vars.modifiedfiles |= MODFILE_MPSETUP;
			}
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		if (mp_get_using_multiple_tunes()) {
			data->list.value = 0x000fffff;
		} else {
			s32 slotnum = mp_get_current_track_slot_num();

			if (slotnum < 0) {
				data->list.value = mp_get_num_unlocked_tracks();
			} else {
				data->list.value = slotnum;
			}
		}
		break;
	case MENUOP_LISTITEMFOCUS:
		if (data->list.value < mp_get_num_unlocked_tracks()) {
			music_start_track_as_menu(mp_get_track_music_num(data->list.value));
		}
		break;
	case MENUOP_GETLISTITEMCHECKBOX:
		{
			s32 numtracks = mp_get_num_unlocked_tracks();

			if (mp_get_using_multiple_tunes() && data->list.value < numtracks) {
				data->list.unk04 = mp_is_multi_track_slot_enabled(data->list.value);
			}
		}
		break;
	}

	return 0;
}

MenuDialogHandlerResult menudialog_mp_select_tune(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_MusicInterval240 = 80;
	}

	if (operation == MENUOP_CLOSE) {
		g_MusicInterval240 = 15;
	}

	return false;
}

char *mp_menu_text_current_track(struct menuitem *item)
{
	s32 slotnum;

	if (mp_get_using_multiple_tunes()) {
		return lang_get(L_MPMENU_066); // "Multiple Tunes"
	}

	slotnum = mp_get_current_track_slot_num();

	if (slotnum >= 0) {
		return mp_get_track_name(slotnum);
	}

	return lang_get(L_MPMENU_067); // "Random"
}

MenuItemHandlerResult menuhandler_mp_multiple_tunes(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		return mp_get_using_multiple_tunes();
	case MENUOP_SET:
		mp_set_using_multiple_tunes(data->checkbox.value);
		g_Vars.modifiedfiles |= MODFILE_MPSETUP;
	}

	return 0;
}

MenuItemHandlerResult mp_team_name_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
char *mp_menu_text_team_name(struct menuitem *item)
{
	s32 index = item->param2;
	index -= L_OPTIONS_008;

	return g_BossFile.teamnames[index];
}

MenuItemHandlerResult menuhandler_mp_team_name_slot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].mpsetup.slotindex = item->param2 - 0x5608;
		menu_push_dialog(&g_MpChangeTeamNameMenuDialog);
	}

	return 0;
}

char *func0f17e318(struct menudialogdef *dialogdef)
{
	sprintf(g_StringPointer, lang_get(L_MPMENU_056), challenge_get_name_by_slot(g_Menus[g_MpPlayerNum].mpsetup.slotindex));
	return g_StringPointer;
}

/**
 * An "Accept" item somewhere. Probably accepting a challenge.
 */
MenuItemHandlerResult menuhandler0017e38c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
#if VERSION >= VERSION_NTSC_1_0
		challenge_unset_current();
#endif

		menu_pop_dialog();
		challenge_set_current_by_slot(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
	}

	return 0;
}

MenuDialogHandlerResult menudialog0017e3fc(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		g_Menus[g_MpPlayerNum].menumodel.curparams = 0;

		g_Menus[g_MpPlayerNum].training.mpconfig = challenge_load_by_slot(
				g_Menus[g_MpPlayerNum].training.unke1c,
				g_Menus[g_MpPlayerNum].menumodel.allocstart,
				g_Menus[g_MpPlayerNum].menumodel.alloclen);
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
			menu_pop_dialog();
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
		mp_select_tune_list_handler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpSelectTunesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)&mp_menu_text_select_tune_or_tunes,
	g_MpSelectTunesMenuItems,
	menudialog_mp_select_tune,
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
		(uintptr_t)&mp_menu_text_current_track,
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
		(uintptr_t)&mp_menu_text_select_tune_or_tunes,
		0,
		(void *)&g_MpSelectTunesMenuDialog,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_064, // "Multiple Tunes"
		0,
		menuhandler_mp_multiple_tunes,
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
		mp_team_name_menu_handler,
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
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_009, // "Yellow"
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_010, // "Blue"
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_011, // "Magenta"
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_012, // "Cyan"
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_013, // "Orange"
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_014, // "Pink"
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_015, // "Brown"
		(uintptr_t)&mp_menu_text_team_name,
		menuhandler_mp_team_name_slot,
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
	(uintptr_t)&func0f17e318,
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
		mp_challenges_list_menu_handler,
	},
#if VERSION < VERSION_NTSC_1_0
	{
		MENUITEMTYPE_LABEL,
		2,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LABEL_ALTCOLOUR,
		0x7f179198,
		0,
		(void *)0x7f1790a8,
	},
#endif
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
		menuhandler_mp_start_challenge,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_051, // "Abort Challenge"
		0,
		menuhandler_mp_abort_challenge,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpChallengeListOrDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
#if VERSION >= VERSION_NTSC_1_0
	(uintptr_t)&mp_menu_text_challenge_name,
#else
	0x5032,
#endif
	g_MpChallengesListOrDetailsMenuItems,
	mp_combat_challenges_menu_dialog,
#if VERSION >= VERSION_NTSC_1_0
	0x00000808,
#else
	MENUDIALOGFLAG_DROPOUTONCLOSE,
#endif
	NULL,
};

struct menudialogdef g_MpAdvancedSetupViaAdvChallengeMenuDialog;

struct menudialogdef g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
#if VERSION >= VERSION_NTSC_1_0
	(uintptr_t)&mp_menu_text_challenge_name,
#else
	0x5032,
#endif
	g_MpChallengesListOrDetailsMenuItems,
	mp_combat_challenges_menu_dialog,
#if VERSION >= VERSION_NTSC_1_0
	0x00000808,
	&g_MpAdvancedSetupViaAdvChallengeMenuDialog,
#else
	MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpAdvancedSetupMenuDialog,
#endif
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
	(uintptr_t)&func0f17e318,
	g_MpConfirmChallengeMenuItems,
	menudialog0017e3fc,
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
};

MenuItemHandlerResult mp_challenges_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
		data->list.value = challenge_get_num_available();
		break;
	case MENUOP_SET:
		if (data->list.unk04 != 0) {
			data->list.unk04 = 2;
		}

		g_Menus[g_MpPlayerNum].mpsetup.slotindex = data->list.value;

		if (item->param == 0) {
			menu_push_dialog(&g_MpConfirmChallengeViaListOrDetailsMenuDialog);
		} else if (IS4MB()) {
			menu_push_dialog(&g_MpConfirmChallenge4MbMenuDialog);
		} else {
			menu_push_dialog(&g_MpConfirmChallengeMenuDialog);
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

		if (IS4MB()) {
			maxchrs = 2;
		}

		x = renderdata->x + 10;
		y = renderdata->y + 1;

		gdl = text_begin(gdl);
		gdl = text_render_v2(gdl, &x, &y, challenge_get_name_by_slot(data->type19.unk04), g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, vi_get_width(), vi_get_height(), 0, 0);
		gdl = text_end(gdl);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		tex_select(&gdl, &g_TexGeneralConfigs[TEX_GENERAL_ENVSTAR], 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		for (i = 0; i < maxchrs; i++) {
#if VERSION >= VERSION_NTSC_1_0
			if (challenge_is_completed_by_any_chr_with_num_players_by_slot(data->type19.unk04, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, (renderdata->colour & 0xff) * 0xff >> 8 | 0xffe56500);
			} else {
				gDPSetEnvColorViaWord(gdl++, (renderdata->colour & 0xff) * 0xff >> 8 | 0x43430000);
			}
#else
			if (challenge_is_completed_by_any_chr_with_num_players_by_slot(data->type19.unk04, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, 0xffe565ff);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0x434300ff);
			}
#endif

			gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0);

			gSPTextureRectangle(gdl++,
				((renderdata->x + marginleft) << 2) * g_UiScaleX, (renderdata->y + 11) << 2,
				((renderdata->x + marginleft + 11) << 2) * g_UiScaleX, (renderdata->y + 22) << 2,
				G_TX_RENDERTILE, 0, 0x0160, 1024 / g_UiScaleX, -1024);

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
MenuItemHandlerResult menuhandler0017e9d8(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_abort_challenge(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		challenge_remove_player_lock();
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_start_challenge(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}
	if (operation == MENUOP_SET) {
		menu_push_dialog(&g_MpReadyMenuDialog);
	}

	return 0;
}

char *mp_menu_text_challenge_name(struct menuitem *item)
{
#if VERSION >= VERSION_NTSC_1_0
	if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
		return lang_get(L_MPMENU_050); // "Combat Challenges"
	}
#endif

	sprintf(g_StringPointer, "%s:\n", challenge_get_name(challenge_get_current()));
	return g_StringPointer;
}

MenuDialogHandlerResult mp_combat_challenges_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE
				&& g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
				&& !challenge_is_loaded()) {
			g_Menus[g_MpPlayerNum].menumodel.curparams = 0x4fac5ace;

			challenge_load_and_store_current(
					g_Menus[g_MpPlayerNum].menumodel.allocstart,
					g_Menus[g_MpPlayerNum].menumodel.alloclen);
		}
	}

	if (operation == MENUOP_CLOSE) {
		if (g_Menus[g_MpPlayerNum].menumodel.curparams == 0x4fac5ace) {
			challenge_unset_current();
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler0017ec64(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		challenge_set_current_by_slot(g_Menus[g_MpPlayerNum].mpsetup.slotindex);
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
		mp_challenges_list_menu_handler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpChallengesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_050, // "Combat Challenges"
	g_MpChallengesMenuItems,
	mp_combat_challenges_menu_dialog,
	0,
	NULL,
};

MenuItemHandlerResult menuhandler_mp_lock(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
		L_MPMENU_045, // "None"
		L_MPMENU_046, // "Last Winner"
		L_MPMENU_047, // "Last Loser"
		L_MPMENU_048, // "Random"
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = mp_get_lock_type() == MPLOCKTYPE_CHALLENGE ? 1 : 5;
		break;
	case MENUOP_GETOPTIONTEXT:
		if (mp_get_lock_type() == MPLOCKTYPE_CHALLENGE) {
			return (s32) lang_get(L_MPMENU_049); // "Challenge"
		}
		if (data->dropdown.value <= 3) {
			return (s32) lang_get(labels[data->dropdown.value]);
		}
		if (mp_get_lock_type() == MPLOCKTYPE_PLAYER) {
			return (s32) g_PlayerConfigsArray[mp_get_lock_player_num()].base.name;
		}
		return (s32) mp_get_current_player_name(item);
	case MENUOP_SET:
		if (mp_get_lock_type() != MPLOCKTYPE_CHALLENGE) {
			mp_set_lock(data->dropdown.value, g_MpPlayerNum);
		}
		g_Vars.modifiedfiles |= MODFILE_MPSETUP;
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->dropdown.value = mp_get_lock_type() == MPLOCKTYPE_CHALLENGE ? 0 : mp_get_lock_type();
		break;
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_save_player(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid == 0) {
			filemgr_push_select_location_dialog(6, FILETYPE_MPPLAYER);
		} else {
			menu_push_dialog(&g_MpSavePlayerMenuDialog);
		}
	}

	return 0;
}

char *mp_menu_text_save_player_or_copy(struct menuitem *item)
{
	if (g_PlayerConfigsArray[g_MpPlayerNum].fileguid.fileid == 0) {
		return lang_get(L_MPMENU_038); // "Save Player"
	}

	return lang_get(L_MPMENU_039); // "Save Copy of Player"
}

MenuItemHandlerResult menuhandler0017ef30(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult menuhandler_mp_save_settings(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_MpSetup.fileguid.fileid == 0) {
			menu_push_dialog(&g_MpSaveSetupNameMenuDialog);
		} else {
#if VERSION >= VERSION_NTSC_1_0
			filemgr_set_device1_by_serial(g_MpSetup.fileguid.deviceserial);
#endif

			menu_push_dialog(&g_MpSaveSetupExistsMenuDialog);
		}
	}

	return 0;
}

char *mp_menu_text_arena_name(struct menuitem *item)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MpArenas); i++) {
		if (g_MpArenas[i].stagenum == g_MpSetup.stagenum) {
			return lang_get(g_MpArenas[i].name);
		}
	}

	return "\n";
}

char *mp_menu_text_weapon_set_name(struct menuitem *item)
{
	return mp_get_weapon_set_name(mp_get_weapon_set());
}

MenuDialogHandlerResult menudialog_mp_game_setup(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.mpsetupmenu = MPSETUPMENU_ADVSETUP;
		g_Vars.usingadvsetup = true;
	}

	return false;
}

MenuDialogHandlerResult menudialog_mp_quick_go(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.mpsetupmenu = MPSETUPMENU_QUICKGO;
	}

	return false;
}

void mp_configure_quick_team_players(void)
{
	s32 i;

	if (g_Vars.mpquickteam != MPQUICKTEAM_NONE) {
		for (i = 0; i < MAX_BOTS; i++) {
			mp_remove_simulant(i);
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

			for (i = 0; i < MAX_PLAYERS; i++) {
				g_PlayerConfigsArray[i].base.team = g_Vars.mpplayerteams[i];
			}

			break;
		case MPQUICKTEAM_PLAYERSVSSIMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < MAX_PLAYERS; i++) {
				g_PlayerConfigsArray[i].base.team = 0;
			}

			break;
		case MPQUICKTEAM_PLAYERSIMTEAMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < MAX_PLAYERS; i++) {
				g_PlayerConfigsArray[i].base.team = i;
			}

			break;
		}
	}
}

void mp_configure_quick_team_simulants(void)
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
				botnum = mp_get_slot_for_new_bot();

				if (botnum >= 0) {
					mp_create_bot_from_profile(botnum, g_Vars.mpsimdifficulty);
				}
			}

			mp_generate_bot_names();
			break;
		case MPQUICKTEAM_PLAYERSVSSIMS:
			for (i = 0; i < g_Vars.mpquickteamnumsims; i++) {
				botnum = mp_get_slot_for_new_bot();

				if (botnum >= 0) {
					mp_create_bot_from_profile(botnum, g_Vars.mpsimdifficulty);
				}
			}

			mp_generate_bot_names();

			for (i = 0; i < ARRAYCOUNT(g_BotConfigsArray); i++) {
				g_BotConfigsArray[i].base.team = 1;
			}

			break;
		case MPQUICKTEAM_PLAYERSIMTEAMS:
			for (i = mp_get_num_chrs() - 1; i >= 0; i--) {
				mpchr = mp_get_chr_config_by_slot_num(i);

				for (j = 0; j < g_Vars.unk0004a0; j++) {
					botnum = mp_get_slot_for_new_bot();

					if (botnum >= 0) {
						mp_create_bot_from_profile(botnum, g_Vars.mpsimdifficulty);
						g_BotConfigsArray[botnum].base.team = mpchr->team;
					}
				}
			}

			mp_generate_bot_names();
			break;
		case MPQUICKTEAM_PLAYERSONLY:
		case MPQUICKTEAM_PLAYERSTEAMS:
			break;
		}
	}
}

void func0f17f428(void)
{
	mp_configure_quick_team_players();

	if (IS4MB()) {
		func0f0f820c(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
	} else {
		func0f0f820c(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
	}
}

MenuItemHandlerResult menuhandler_mp_finished_setup(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult menuhandler_quick_team_separator(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY) {
			return true;
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler_player_team(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
#if VERSION >= VERSION_JPN_FINAL
		data->dropdown.value = scenario_get_max_teams();
#else
		data->dropdown.value = MAX_TEAMS;
#endif
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) &g_BossFile.teamnames[data->dropdown.value];
	case MENUOP_SET:
		g_Vars.mpplayerteams[item->param] = data->dropdown.value;
		break;
	case MENUOP_GETSELECTEDINDEX:
#if VERSION >= VERSION_JPN_FINAL
		if (g_Vars.mpplayerteams[item->param] >= scenario_get_max_teams()) {
			g_Vars.mpplayerteams[item->param] %= scenario_get_max_teams();
		}
#endif
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

MenuItemHandlerResult menuhandler_mp_number_of_simulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = !challenge_is_feature_unlocked(MPFEATURE_8BOTS) ? 4 : MAX_BOTS;
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

MenuItemHandlerResult menuhandler_mp_simulants_per_team(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult mp_quick_team_simulant_difficulty_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 count = 0;
	s32 i;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < NUM_BOTDIFFS; i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				count++;
			}
		}

		data->dropdown.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < NUM_BOTDIFFS; i++) {
			if (challenge_is_feature_unlocked(g_BotProfiles[i].requirefeature)) {
				if (count == data->dropdown.value) {
					return (s32) lang_get(i + L_MISC_082);
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
		if (g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSANDSIMS
				&& g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSVSSIMS
				&& g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSIMTEAMS) {
			return true;
		}
	}

	return 0;
}

MenuItemHandlerResult menuhandler_mp_quick_team_option(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.mpquickteam = item->param;

		if (mp_get_weapon_set() >= func0f189058(0)) {
			mp_set_weapon_set(0);
		}

		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY ||
				g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSANDSIMS) {
			if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL ||
					g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
				g_MpSetup.scenario = MPSCENARIO_COMBAT;
			}
		}

		menu_push_dialog(&g_MpQuickTeamGameSetupMenuDialog);
	}

	return 0;
}

MenuDialogHandlerResult menudialog_combat_simulator(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
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
		challenge_unset_current();
		challenge_remove_player_lock();
	}

	return false;
}

MenuItemHandlerResult menuhandler_mp_advanced_setup(s32 operation, struct menuitem *item, union handlerdata *data)
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
void mp_close_dialogs_for_new_setup(void)
{
	s32 i;
	s32 prevplayernum = g_MpPlayerNum;
	s32 j;
	s32 k;

	// Loop through each player
	for (i = 0; i < MAX_PLAYERS; i++) {
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
					menu_pop_dialog();
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
		menuhandler_mp_lock,
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
		menuhandler_screen_ratio,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MPWEAPONS_154, // "Split"
		0,
		menuhandler_screen_split,
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
		(uintptr_t)&mp_get_current_player_name,
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
		(uintptr_t)&mp_menu_text_save_player_or_copy,
		0,
		menuhandler_mp_save_player,
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
		(uintptr_t)&mp_menu_text_scenario_short_name,
		(void *)&g_MpScenarioMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_021, // "Options"
		0,
		menuhandler_mp_open_options,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_020, // "Arena"
		(uintptr_t)&mp_menu_text_arena_name,
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
		menuhandler_mp_save_settings,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpAdvancedSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialog_mp_game_setup,
	MENUDIALOGFLAG_MPLOCKABLE | MENUDIALOGFLAG_DROPOUTONCLOSE,
	&g_MpPlayerSetupViaAdvMenuDialog,
};

struct menudialogdef g_MpAdvancedSetupViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialog_mp_game_setup,
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
#if VERSION >= VERSION_NTSC_1_0
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_029, // "Load Player"
		0,
		(void *)&g_MpLoadPlayerMenuDialog,
	},
#endif
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
	menudialog_mp_quick_go,
	0,
	NULL,
};

struct menuitem g_MpQuickTeamGameSetupMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_019, // "Scenario"
		(uintptr_t)&mp_menu_text_scenario_short_name,
		(void *)&g_MpQuickTeamScenarioMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPMENU_021, // "Options"
		0,
		menuhandler_mp_open_options,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_020, // "Arena"
		(uintptr_t)&mp_menu_text_arena_name,
		(void *)&g_MpArenaMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPMENU_023, // "Weapons"
		(uintptr_t)&mp_menu_text_weapon_set_name,
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
		menuhandler_quick_team_separator,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_449, // "Player 1 Team"
		0,
		menuhandler_player_team,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		1,
		0,
		L_MISC_450, // "Player 2 Team"
		0,
		menuhandler_player_team,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		2,
		0,
		L_MISC_451, // "Player 3 Team"
		0,
		menuhandler_player_team,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		3,
		0,
		L_MISC_452, // "Player 4 Team"
		0,
		menuhandler_player_team,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_453, // "Number Of Simulants"
		0,
		menuhandler_mp_number_of_simulants,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_454, // "Simulants Per Team"
		0,
		menuhandler_mp_simulants_per_team,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		0,
		L_MISC_455, // "Simulant Difficulty"
		0,
		mp_quick_team_simulant_difficulty_handler,
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
		menuhandler_mp_finished_setup,
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
		menuhandler_mp_save_settings,
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
		menuhandler_mp_quick_team_option,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		1,
		MENUITEMFLAG_BIGFONT,
		L_MISC_464, // "Players and Simulants"
		0,
		menuhandler_mp_quick_team_option,
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
		menuhandler_mp_quick_team_option,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		3,
		MENUITEMFLAG_BIGFONT,
		L_MISC_466, // "Players vs. Simulants"
		0,
		menuhandler_mp_quick_team_option,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		4,
		MENUITEMFLAG_BIGFONT,
		L_MISC_467, // "Player-Simulant Teams"
		0,
		menuhandler_mp_quick_team_option,
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
		menuhandler_mp_advanced_setup,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CombatSimulatorMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_445, // "Combat Simulator"
	g_CombatSimulatorMenuItems,
	menudialog_combat_simulator,
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
};

void func0f17fcb0(s32 silent)
{
	g_Menus[g_MpPlayerNum].playernum = g_MpPlayerNum;

	if (IS4MB()) {
		menu_push_root_dialog(&g_AdvancedSetup4MbMenuDialog, MENUROOT_4MBMAINMENU);
		func0f0f8300();
	} else {
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
			menu_push_root_dialog(&g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog, MENUROOT_MPSETUP);
		} else {
			menu_push_root_dialog(&g_MpAdvancedSetupMenuDialog, MENUROOT_MPSETUP);
		}

		func0f0f8300();
	}

	if (!silent) {
		// Explosion sound
		snd_start(var80095200, SFX_EXPLOSION_809A, NULL, -1, -1, -1, -1, -1);
	}
}
