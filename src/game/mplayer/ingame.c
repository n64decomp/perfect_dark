#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/gset.h"
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

MenuItemHandlerResult mp_stats_for_player_dropdown_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
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

MenuItemHandlerResult menuhandler_mp_end_game(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.currentplayer->aborted = true;
		main_end_stage();
	}

	return 0;
}

/**
 * This is something near the top of the "End Game" dialog during gameplay.
 */
MenuItemHandlerResult menuhandler00178018(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_BossFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

char *mp_menu_text_in_game_limit(struct menuitem *item)
{
	*g_StringPointer = 0;

	switch (item->param) {
	case 0:
		sprintf(g_StringPointer, lang_get(L_MPMENU_114), g_MpSetup.timelimit + 1);
		break;
	case 1:
		sprintf(g_StringPointer, lang_get(L_MPMENU_113), g_MpSetup.scorelimit + 1);
		break;
	case 2:
		sprintf(g_StringPointer, lang_get(L_MPMENU_113), mp_calculate_team_score_limit() + 1);
		break;
	}

	return g_StringPointer;
}

MenuItemHandlerResult menuhandler_mp_in_game_limit_label(s32 operation, struct menuitem *item, union handlerdata *data)
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

MenuItemHandlerResult menuhandler_mp_pause(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (mp_is_paused()) {
			mp_set_paused(MPPAUSEMODE_UNPAUSED);
		} else {
			mp_set_paused(MPPAUSEMODE_PAUSED);
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

char *menutext_pause_or_unpause(s32 arg0)
{
	if (mp_is_paused()) {
		return lang_get(L_MPMENU_289); // "Unpause"
	}

	return lang_get(L_MPMENU_288); // "Pause"
}

char *menutext_match_time(s32 arg0)
{
#if PAL
	format_time(g_StringPointer, lv_get_stage_time60() * 60 / 50, TIMEPRECISION_SECONDS);
#else
	format_time(g_StringPointer, lv_get_stage_time60(), TIMEPRECISION_SECONDS);
#endif

	return g_StringPointer;
}

struct menuitem g_MpEndGameMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPMENU_291, // "Are you sure?"
		0,
		NULL,
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
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_292, // "Cancel"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_293, // "End Game"
		0,
		menuhandler_mp_end_game,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t) &mp_menu_text_challenge_name,
		0,
		menuhandler00178018,
	},
#if VERSION != VERSION_JPN_FINAL
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t) &mp_menu_text_scenario_name,
		0,
		NULL,
	},
#endif
	{
		MENUITEMTYPE_LABEL,
		0,
#if VERSION == VERSION_JPN_FINAL
		MENUITEMFLAG_LESSLEFTPADDING,
#else
		MENUITEMFLAG_SMALLFONT,
#endif
		L_MPWEAPONS_162, // "Time Limit:"
		(uintptr_t) &mp_menu_text_in_game_limit,
		menuhandler_mp_in_game_limit_label,
	},
	{
		MENUITEMTYPE_LABEL,
		1,
#if VERSION == VERSION_JPN_FINAL
		MENUITEMFLAG_LESSLEFTPADDING,
#else
		MENUITEMFLAG_SMALLFONT,
#endif
		L_MPWEAPONS_163, // "Score Limit:"
		(uintptr_t) &mp_menu_text_in_game_limit,
		menuhandler_mp_in_game_limit_label,
	},
	{
		MENUITEMTYPE_LABEL,
		2,
#if VERSION == VERSION_JPN_FINAL
		MENUITEMFLAG_LESSLEFTPADDING,
#else
		MENUITEMFLAG_SMALLFONT,
#endif
		L_MPWEAPONS_164, // "Team Score Limit:"
		(uintptr_t) &mp_menu_text_in_game_limit,
		menuhandler_mp_in_game_limit_label,
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
		MENUITEMTYPE_LABEL,
		0,
#if VERSION == VERSION_JPN_FINAL
		MENUITEMFLAG_LESSLEFTPADDING,
#else
		0,
#endif
		L_MPMENU_286, // "Game Time:"
		(uintptr_t)&menutext_match_time,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		1,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)&menutext_pause_or_unpause,
		0,
		menuhandler_mp_pause,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_287, // "End Game"
		0,
		(void *)&g_MpEndGameMenuDialog,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpPauseControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
#if VERSION >= VERSION_JPN_FINAL
	(uintptr_t)&mp_menu_text_scenario_name,
#else
	L_MPMENU_285, // "Control"
#endif
	g_MpPauseControlMenuItems,
	NULL,
	0,
	NULL,
};

#if VERSION >= VERSION_JPN_FINAL
char *mp_menu_text_weapon_description(struct menuitem *item)
{
	struct weapon *weapondef = gset_get_weapondef(g_Menus[g_MpPlayerNum].training.weaponnum);

	if (weapondef != NULL) {
		if (g_Menus[g_MpPlayerNum].training.weaponnum == WEAPON_EYESPY) {
			if (g_Vars.currentplayer->eyespy != NULL) {
				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
					return lang_get(L_GUN_237);
				}

				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
					return lang_get(L_GUN_236);
				}
			}
		}

		if (g_Menus[g_MpPlayerNum].training.weaponnum == WEAPON_NECKLACE && g_Vars.stagenum == STAGE_ATTACKSHIP) {
			if (lv_get_difficulty() >= DIFF_PA) {
				u8 username[] = {
					'C' + 9 * 1,
					'D' + 9 * 2,
					'V' + 9 * 3,
					'7' + 9 * 4,
					'8' + 9 * 5,
					'0' + 9 * 6,
					'3' + 9 * 7,
					'2' + 9 * 8,
					'2' + 9 * 9,
					'\0' + 9 * 10,
				};

				u8 password[] = {
					'I' + 4 * 1,
					'8' + 4 * 2,
					'M' + 4 * 3,
					'O' + 4 * 4,
					'Z' + 4 * 5,
					'Y' + 4 * 6,
					'M' + 4 * 7,
					'8' + 4 * 8,
					'N' + 4 * 9,
					'D' + 4 * 10,
					'I' + 4 * 11,
					'8' + 4 * 12,
					'5' + 4 * 13,
					'\0' + 4 * 14,
				};

				s32 i;

				for (i = 0; i < ARRAYCOUNT(username); i++) {
					username[i] -= i * 9 + 9;
				}

				for (i = 0; i < ARRAYCOUNT(password); i++) {
					password[i] -= i * 4 + 4;
				}

				sprintf(g_StringPointer, lang_get(L_GUN_239), username, password);

				return g_StringPointer;
			}
		}

		return lang_get(weapondef->description);
	}

	return lang_get(L_OPTIONS_003); // ""
}
#else
char *mp_menu_text_weapon_description(struct menuitem *item)
{
	struct weapon *weapon = gset_get_weapondef(g_Menus[g_MpPlayerNum].mppause.weaponnum);

	if (weapon) {
		return lang_get(weapon->description);
	}

	return "\n";
}
#endif

char *mp_menu_title_stats_for(struct menudialogdef *dialogdef)
{
	struct mpchrconfig *mpchr = MPCHR(g_MpSelectedPlayersForStats[g_MpPlayerNum]);

	// "Stats for %s"
	sprintf(g_StringPointer, lang_get(L_MPMENU_280), mpchr->name);
	return g_StringPointer;
}

MenuItemHandlerResult func0f178440(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation);

	return 0;
}

char *mp_menu_text_weapon_of_choice_name(struct menuitem *item)
{
	return mp_player_get_weapon_of_choice_name(g_Menus[g_MpPlayerNum].playernum, 0);
}

char *mp_menu_text_award1(struct menuitem *item)
{
	return g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->award1;
}

char *mp_menu_text_award2(struct menuitem *item)
{
	return g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->award2;
}

struct menuitem g_Mp2PMissionInventoryMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		0,
		0x00000078,
		0x00000042,
		menuhandler_inventory_list,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(uintptr_t)&mp_menu_text_weapon_description,
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_PLAYERSTATS,
		0,
		0,
		0,
		0,
		mp_stats_for_player_dropdown_handler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MpPausePlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)&mp_menu_title_stats_for,
	g_MpInGamePlayerStatsMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	&g_MpPauseInventoryMenuDialog,
};

struct menudialogdef g_MpEndscreenPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)&mp_menu_title_stats_for,
	g_MpInGamePlayerStatsMenuItems,
	NULL,
	VERSION >= VERSION_JPN_FINAL ? MENUDIALOGFLAG_1000 : 0,
	NULL,
};

struct menuitem g_MpPlayerRankingMenuItems[] = {
	{
		MENUITEMTYPE_RANKING,
		0,
		0,
		0,
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_RANKING,
		0,
		0,
		0x00000001,
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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

char *mp_menu_text_placement_with_suffix(struct menuitem *item)
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

	return lang_get(suffixes[g_PlayerConfigsArray[g_MpPlayerNum].base.placement]);
}

MenuItemHandlerResult mp_placement_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].base.placement == 0) { // winner
			data->label.colour2 = colour_blend(data->label.colour2, 0xffff00ff, menu_get_sin_osc_frac(40) * 255);
		}
	}

	return 0;
}

MenuItemHandlerResult mp_awards_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_RENDER) {
		Gfx *gdl = data->type19.gdl;
		struct menuitemrenderdata *renderdata = data->type19.renderdata2;
		bool configured = false;
		s32 x = renderdata->x + renderdata->width - 15;
		s32 i;
		u32 colour;

		for (i = 0; i < MAX_PLAYERS; i++) {
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

					tex_select(&gdl, &g_TexGeneralConfigs[35], 2, 0, 2, 1, NULL);

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

MenuItemHandlerResult mp_player_title_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR) {
		if (g_PlayerConfigsArray[g_MpPlayerNum].title != g_PlayerConfigsArray[g_MpPlayerNum].newtitle) {
			data->label.colour2 = colour_blend(data->label.colour2, 0xffff00ff, menu_get_sin_osc_frac(40) * 255);
		}
	}

	return 0;
}

char *mp_menu_text_player_title(s32 arg0)
{
	return lang_get(L_MISC_185 + g_PlayerConfigsArray[g_MpPlayerNum].title);
}

#if VERSION >= VERSION_NTSC_1_0
MenuItemHandlerResult mp_confirm_player_name_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
		filemgr_push_select_location_dialog(6, FILETYPE_MPPLAYER);
		break;
	}

	return 0;
}
#endif

void mp_push_pause_dialog(void)
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
					menu_push_root_dialog(&g_MpPauseTeamRankingsMenuDialog, MENUROOT_MPPAUSE);
				} else {
					menu_push_root_dialog(&g_MpPausePlayerRankingMenuDialog, MENUROOT_MPPAUSE);
				}
			} else {
				if (options_get_screen_split() == SCREENSPLIT_VERTICAL) {
					menu_push_root_dialog(&g_2PMissionPauseVMenuDialog, MENUROOT_MPPAUSE);
				} else {
					menu_push_root_dialog(&g_2PMissionPauseHMenuDialog, MENUROOT_MPPAUSE);
				}
			}
		}

		g_MpPlayerNum = prevplayernum;
	}
}

void mp_push_endscreen_dialog(u32 arg0, u32 playernum)
{
	u32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = playernum;

	g_Menus[g_MpPlayerNum].playernum = arg0;

	if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
		if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
			if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
				menu_push_root_dialog(&g_MpEndscreenChallengeCheatedMenuDialog, MENUROOT_MPENDSCREEN);
			} else if (challenge_is_complete_for_endscreen()) {
				menu_push_root_dialog(&g_MpEndscreenChallengeCompletedMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menu_push_root_dialog(&g_MpEndscreenChallengeFailedMenuDialog, MENUROOT_MPENDSCREEN);
			}
		} else {
			menu_push_root_dialog(&g_MpEndscreenTeamGameOverMenuDialog, MENUROOT_MPENDSCREEN);
		}
	} else {
		menu_push_root_dialog(&g_MpEndscreenIndGameOverMenuDialog, MENUROOT_MPENDSCREEN);
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
			menu_push_dialog(&g_MpEndscreenSavePlayerMenuDialog);
		}
	}
#endif

	g_MpPlayerNum = prevplayernum;
}

struct menuitem g_MpGameOverMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_LABEL_CUSTOMCOLOUR,
		(uintptr_t)&mp_get_current_player_name,
		(uintptr_t)&mp_menu_text_placement_with_suffix,
		mp_placement_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
#if VERSION >= VERSION_JPN_FINAL
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LABEL_CUSTOMCOLOUR,
		(uintptr_t)&mp_menu_text_player_title,
		0,
#else
		MENUITEMFLAG_LABEL_CUSTOMCOLOUR,
		L_MPMENU_261, // "Title:"
		(uintptr_t)&mp_menu_text_player_title,
#endif
		mp_player_title_menu_handler,
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
		L_MPMENU_262, // "Weapon of Choice:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LABEL_ALTCOLOUR,
		(uintptr_t)&mp_menu_text_weapon_of_choice_name,
		0,
		NULL,
	},
#if VERSION >= VERSION_JPN_FINAL
	{
		MENUITEMTYPE_MODEL,
		0,
		MENUITEMFLAG_00000002,
		0x00000001,
		0x00000003,
		NULL,
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
#if VERSION >= VERSION_JPN_FINAL
	{
		MENUITEMTYPE_MODEL,
		0,
		MENUITEMFLAG_00000002 | MENUITEMFLAG_LIST_CUSTOMRENDER,
		0x00000001,
		0x00000002,
		mp_awards_menu_handler,
	},
#else
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_LIST_CUSTOMRENDER,
		L_MPMENU_263, // "Awards:"
		0,
		mp_awards_menu_handler,
	},
#endif
	{
		MENUITEMTYPE_LABEL,
		0,
#if VERSION >= VERSION_JPN_FINAL
		MENUITEMFLAG_LABEL_ALTCOLOUR,
#else
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LABEL_ALTCOLOUR,
#endif
		(uintptr_t)&mp_menu_text_award1,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
#if VERSION >= VERSION_JPN_FINAL
		MENUITEMFLAG_LABEL_ALTCOLOUR,
#else
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LABEL_ALTCOLOUR,
#endif
		(uintptr_t)&mp_menu_text_award2,
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_250, // "Confirm player name:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_KEYBOARD,
		0,
		0,
		0,
		0,
		mp_confirm_player_name_handler,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_247, // "Save new player and statistics?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_248, // "Save Now"
		0,
		(void *)&g_MpEndscreenConfirmNameMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_249, // "No Thanks!"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
