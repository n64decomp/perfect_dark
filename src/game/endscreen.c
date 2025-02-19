#include <ultra64.h>
#include "constants.h"
#include "game/bossfile.h"
#include "game/cheats.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/pdmode.h"
#include "game/objectives.h"
#include "game/bondgun.h"
#include "game/debug.h"
#include "game/gset.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/menugfx.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/endscreen.h"
#include "game/stagetable.h"
#include "game/lv.h"
#include "game/mplayer/ingame.h"
#include "game/challenge.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/options.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

#define CHEATINFO_TIMED_EXISTS       0x000100
#define CHEATINFO_TIMED_UNLOCKING    0x000200
#define CHEATINFO_TIMED_PREVUNLOCKED 0x000400
#define CHEATINFO_COMPL_UNLOCKING    0x000800
#define CHEATINFO_COMPL_EXISTS       0x001000

#define CHEATINFO_GET_TIMED_CHEATNUM(info)     ((info) & 0xff)
#define CHEATINFO_GET_COMPL_CHEATNUM(info)     (((info) >> 16) & 0xff)
#define CHEATINFO_SET_TIMED_CHEATNUM(cheatnum) (cheatnum)
#define CHEATINFO_SET_COMPL_CHEATNUM(cheatnum) ((cheatnum) << 16)

void endscreen_continue(s32 context);
char *endscreen_menu_text_target_time(struct menuitem *item);
char *endscreen_menu_text_timed_cheat_name(struct menuitem *item);
char *endscreen_menu_text_completion_cheat_name(struct menuitem *item);

MenuItemHandlerResult endscreen_handle_decline_mission(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CONFIRM) {
		menu_pop_dialog();
		menu_pop_dialog();
	}

	return 0;
}

MenuDialogHandlerResult endscreen_handle_retry_mission(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_ON_TICK:
		{
			/**
			 * NTSC Final adds this check to make sure the given dialog is
			 * either the one being displayed or its sibling. This most likely
			 * fixes a bug - perhaps there is some way that this handler is run
			 * when the dialog is not on screen?
			 */
#if VERSION >= VERSION_NTSC_FINAL
			if (g_Menus[g_MpPlayerNum].curdialog) {
				if (dialogdef == g_Menus[g_MpPlayerNum].curdialog->definition
						|| (dialogdef->nextsibling && dialogdef->nextsibling == g_Menus[g_MpPlayerNum].curdialog->definition)) {
#endif
					struct menuinputs *inputs = data->dialog2.inputs;
					bool accept = false;

					if (inputs->back) {
						menu_pop_dialog();
						menu_pop_dialog();
					}

					inputs->back = false;

					if (inputs->start) {
						accept = true;
					}

					inputs->start = false;

					if (inputs->select
							&& g_Menus[g_MpPlayerNum].curdialog
							&& dialogdef->nextsibling
							&& dialogdef->nextsibling == g_Menus[g_MpPlayerNum].curdialog->definition) {
						accept = true;
						inputs->select = false;
					}

					if (accept) {
						union handlerdata data2;
						menuhandler_accept_mission(MENUOP_CONFIRM, &dialogdef->items[1], &data2);
					}
#if VERSION >= VERSION_NTSC_FINAL
				}
			}
#endif
		}
	}

	return menudialog_accept_mission(operation, dialogdef, data);
}

char *endscreen_menu_title_retry_mission(struct menudialogdef *dialogdef)
{
	char *name;
	char *prefix;

	if (g_Menus[g_MpPlayerNum].curdialog->definition != dialogdef) {
		return lang_get(L_OPTIONS_300); // "Objectives"
	}

	prefix = lang_get(L_OPTIONS_296); // "Retry"
	name = lang_get(g_SoloStages[g_MissionConfig.stageindex].name3);

	sprintf(g_StringPointer, "%s: %s\n", prefix, name);

	return g_StringPointer;
}

char *endscreen_menu_title_next_mission(struct menudialogdef *dialogdef)
{
	char *name;
	char *prefix;

	if (g_Menus[g_MpPlayerNum].curdialog->definition != dialogdef) {
		return lang_get(L_OPTIONS_300); // "Objectives"
	}

	prefix = lang_get(L_OPTIONS_297); // "Next Mission"
	name = lang_get(g_SoloStages[g_MissionConfig.stageindex].name3);

	sprintf(g_StringPointer, "%s: %s\n", prefix, name);

	return g_StringPointer;
}

MenuItemHandlerResult endscreen_handle_replay_previous_mission(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CONFIRM) {
		g_MissionConfig.stageindex--;
		g_MissionConfig.stagenum = g_SoloStages[g_MissionConfig.stageindex].stagenum;
	}

	return menuhandler_accept_mission(operation, NULL, data);
}

struct menuitem g_RetryMissionMenuItems[] = {
	{
		MENUITEMTYPE_OBJECTIVES,
		1,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_OPTIONS_298, // "Accept"
		0,
		menuhandler_accept_mission,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_OPTIONS_299, // "Decline"
		0,
		endscreen_handle_decline_mission,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_RetryMissionMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)&endscreen_menu_title_retry_mission,
	g_RetryMissionMenuItems,
	endscreen_handle_retry_mission,
	MENUDIALOGFLAG_STARTSELECTS | MENUDIALOGFLAG_DISABLEITEMSCROLL,
	&g_PreAndPostMissionBriefingMenuDialog,
};

struct menuitem g_NextMissionMenuItems[] = {
	{
		MENUITEMTYPE_OBJECTIVES,
		1,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_OPTIONS_298, // "Accept"
		0,
		menuhandler_accept_mission,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_OPTIONS_299, // "Decline"
		0,
		endscreen_handle_decline_mission,
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
		L_MISC_470, // "Replay Previous Mission"
		0,
		endscreen_handle_replay_previous_mission,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_NextMissionMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)&endscreen_menu_title_next_mission,
	g_NextMissionMenuItems,
	endscreen_handle_retry_mission,
	MENUDIALOGFLAG_STARTSELECTS | MENUDIALOGFLAG_DISABLEITEMSCROLL,
	&g_PreAndPostMissionBriefingMenuDialog,
};

char *endscreen_menu_text_num_kills(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstats_get_player_kill_count());
	return g_StringPointer;
}

char *endscreen_menu_text_num_shots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstats_get_player_shotcount_by_region(SHOTREGION_TOTAL));
	return g_StringPointer;
}

char *endscreen_menu_text_num_head_shots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstats_get_player_shotcount_by_region(SHOTREGION_HEAD));
	return g_StringPointer;
}

char *endscreen_menu_text_num_body_shots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstats_get_player_shotcount_by_region(SHOTREGION_BODY));
	return g_StringPointer;
}

char *endscreen_menu_text_num_limb_shots(struct menuitem *item)
{
	sprintf(g_StringPointer, "%d", mpstats_get_player_shotcount_by_region(SHOTREGION_LIMB));
	return g_StringPointer;
}

char *endscreen_menu_text_num_other_shots(struct menuitem *item)
{
	u32 total = mpstats_get_player_shotcount_by_region(SHOTREGION_GUN) + mpstats_get_player_shotcount_by_region(SHOTREGION_HAT);
	sprintf(g_StringPointer, "%d", total);
	return g_StringPointer;
}

char *endscreen_menu_text_accuracy(struct menuitem *item)
{
	s32 total = mpstats_get_player_shotcount_by_region(SHOTREGION_TOTAL);
	s32 numhead = mpstats_get_player_shotcount_by_region(SHOTREGION_HEAD);
	s32 numbody = mpstats_get_player_shotcount_by_region(SHOTREGION_BODY);
	s32 numlimb = mpstats_get_player_shotcount_by_region(SHOTREGION_LIMB);
	s32 numgun = mpstats_get_player_shotcount_by_region(SHOTREGION_GUN);
	s32 numhat = mpstats_get_player_shotcount_by_region(SHOTREGION_HAT);
	s32 numobject = mpstats_get_player_shotcount_by_region(SHOTREGION_OBJECT);
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

char *endscreen_menu_text_mission_status(struct menuitem *item)
{
	if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
		return lang_get(L_MPWEAPONS_135); // "Cheated"
	}

	if (g_Vars.coopplayernum >= 0) {
		if (g_Vars.bond->aborted || g_Vars.coop->aborted) {
			return lang_get(L_OPTIONS_295); // "Aborted"
		}

		if (g_Vars.bond->isdead && g_Vars.coop->isdead) {
			return lang_get(L_OPTIONS_293); // "Failed"
		}
	} else if (g_Vars.antiplayernum >= 0) {
		if (g_Vars.currentplayer == g_Vars.bond) {
			if (g_Vars.bond->aborted) {
				return lang_get(L_OPTIONS_295); // "Aborted"
			}

			if (g_Vars.anti->aborted) {
				return lang_get(L_OPTIONS_295); // "Aborted"
			}

			if (g_Vars.bond->isdead) {
				return lang_get(L_OPTIONS_293); // "Failed"
			}
		} else {
			if (g_Vars.anti->aborted) {
				return lang_get(L_OPTIONS_295); // "Aborted"
			}

			if (!g_Vars.bond->aborted && !g_Vars.bond->isdead) {
				return lang_get(L_OPTIONS_293); // "Failed"
			}
		}
	} else {
		if (g_Vars.bond->aborted) {
			return lang_get(L_OPTIONS_295); // "Aborted"
		}

		if (g_Vars.bond->isdead) {
			return lang_get(L_OPTIONS_293); // "Failed"
		}
	}

	if (objective_is_all_complete() == false) {
		return lang_get(L_OPTIONS_293); // "Failed"
	}

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		return lang_get(L_MPWEAPONS_062); // "Unknown"
	}

	return lang_get(L_OPTIONS_294); // "Completed"
}

char *endscreen_menu_text_agent_status(struct menuitem *item)
{
	if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
		return lang_get(L_MPWEAPONS_134); // "Dishonored"
	}

	if (g_Vars.currentplayer->aborted) {
		return lang_get(L_OPTIONS_292); // "Disavowed"
	}

	if (g_Vars.currentplayer->isdead) {
		return lang_get(L_OPTIONS_290); // "Deceased"
	}

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		return lang_get(L_MPWEAPONS_063); // "Missing"
	}

	return lang_get(L_OPTIONS_291); // "Active"
}

char *endscreen_menu_title_stage_completed(struct menuitem *item)
{
#if VERSION >= VERSION_NTSC_1_0
	sprintf(g_StringPointer, "%s: %s\n",
			lang_get(g_SoloStages[g_Menus[g_MpPlayerNum].endscreen.stageindex].name3),
			lang_get(L_OPTIONS_276)); // "Completed"
#else
	sprintf(g_StringPointer, "%s: %s\n",
			lang_get(g_SoloStages[g_MissionConfig.stageindex].name3),
			lang_get(L_OPTIONS_276)); // "Completed"
#endif

	return g_StringPointer;
}

#if VERSION >= VERSION_NTSC_1_0
char *endscreen_menu_text_current_stage_name3(struct menuitem *item)
{
	char *name = lang_get(g_SoloStages[g_MissionConfig.stageindex].name3);
	sprintf(g_StringPointer, "%s\n", name);

	return g_StringPointer;
}
#endif

char *endscreen_menu_title_stage_failed(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s: %s\n",
			lang_get(g_SoloStages[g_MissionConfig.stageindex].name3),
			lang_get(L_OPTIONS_277)); // "Failed"

	return g_StringPointer;
}

char *endscreen_menu_text_mission_time(struct menuitem *item)
{
	format_time(g_StringPointer, player_get_mission_time(), TIMEPRECISION_SECONDS);
	strcat(g_StringPointer, "\n");

	return g_StringPointer;
}

struct menudialogdef *endscreen_advance(void)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_MissionConfig.stagenum == STAGE_SKEDARRUINS) {
		g_MissionConfig.stagenum = STAGE_CREDITS;
		title_set_next_stage(g_MissionConfig.stagenum);
		lv_set_difficulty(g_MissionConfig.difficulty);
		title_set_next_mode(TITLEMODE_SKIP);
		main_change_to_stage(g_MissionConfig.stagenum);

		return NULL;
	}
#endif

	g_MissionConfig.stageindex++;
	g_MissionConfig.stagenum = g_SoloStages[g_MissionConfig.stageindex].stagenum;

	return &g_NextMissionMenuDialog;
}

void endscreen_reset_models(void)
{
	menu_reset_model(&g_Menus[0].menumodel, bgun_calculate_gun_mem_capacity() - menugfx_get_particle_array_size(), false);
	g_Menus[0].menumodel.allocstart = bgun_get_gun_mem() + menugfx_get_particle_array_size();

	menu_reset_model(&g_Menus[1].menumodel, bgun_calculate_gun_mem_capacity() - menugfx_get_particle_array_size(), false);
	g_Menus[1].menumodel.allocstart = bgun_get_gun_mem() + menugfx_get_particle_array_size();

	menu_reset_model(&g_Menus[2].menumodel, bgun_calculate_gun_mem_capacity() - menugfx_get_particle_array_size(), false);
	g_Menus[2].menumodel.allocstart = bgun_get_gun_mem() + menugfx_get_particle_array_size();

	menu_reset_model(&g_Menus[3].menumodel, bgun_calculate_gun_mem_capacity() - menugfx_get_particle_array_size(), false);
	g_Menus[3].menumodel.allocstart = bgun_get_gun_mem() + menugfx_get_particle_array_size();
}

#if VERSION >= VERSION_NTSC_1_0
MenuItemHandlerResult endscreen_handle_replay_last_level(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CONFIRM) {
		g_MissionConfig.stagenum = g_SoloStages[g_MissionConfig.stageindex].stagenum;
		return menuhandler_accept_mission(operation, NULL, data);
	}

	return 0;
}
#endif

struct menuitem g_2PMissionEndscreenObjectivesVMenuItems[] = {
	{
		MENUITEMTYPE_OBJECTIVES,
		2,
		0,
		0,
		0,
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
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_301, // "Press START"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menuitem g_SoloEndscreenObjectivesMenuItems[] = {
	{
		MENUITEMTYPE_OBJECTIVES,
		0,
		0,
		0,
		0,
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
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_301, // "Press START"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_SoloEndscreenObjectivesFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_300, // "Objectives"
	g_SoloEndscreenObjectivesMenuItems,
	solo_menu_dialog_pause_status,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	NULL,
};

struct menudialogdef g_SoloEndscreenObjectivesCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_300, // "Objectives"
	g_SoloEndscreenObjectivesMenuItems,
	solo_menu_dialog_pause_status,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	NULL,
};

struct menudialogdef g_2PMissionEndscreenObjectivesFailedVMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_300, // "Objectives"
	g_2PMissionEndscreenObjectivesVMenuItems,
	solo_menu_dialog_pause_status,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	NULL,
};

struct menudialogdef g_2PMissionEndscreenObjectivesCompletedVMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_300, // "Objectives"
	g_2PMissionEndscreenObjectivesVMenuItems,
	solo_menu_dialog_pause_status,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	NULL,
};

#if VERSION >= VERSION_NTSC_1_0
/**
 * Displayed after Defense and Skedar Ruins completion screens.
 */
MenuItemHandlerResult endscreen_handle_continue_mission(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CONFIRM) {
		endscreen_continue(2);
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_MissionContinueOrReplyMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_244, // "Continue"
		0,
		endscreen_handle_continue_mission,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_245, // "Replay Last Level"
		0,
		endscreen_handle_replay_last_level,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_MissionContinueOrReplyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)&endscreen_menu_text_current_stage_name3,
	g_MissionContinueOrReplyMenuItems,
	NULL,
	MENUDIALOGFLAG_STARTSELECTS,
	NULL,
};
#endif

#if VERSION >= VERSION_NTSC_1_0
/**
 * Context is:
 *
 * 0 when closing a completed endscreen
 * 1 unsure - is invoked directly by menu_tick
 * 2 when pressing continue
 */
void endscreen_continue(s32 context)
{
	if (g_Vars.antiplayernum >= 0) {
		menu_pop_dialog();
	} else if (g_Vars.coopplayernum >= 0 && PLAYERCOUNT() >= 2 && context == 0) {
		menu_pop_dialog();
	} else {
		if (g_Vars.stagenum == STAGE_DEEPSEA || g_Vars.stagenum == STAGE_SKEDARRUINS) {
			if (context == 2 || g_Menus[g_MpPlayerNum].endscreen.isfirstcompletion) {
				// Pressed continue
				if (g_Vars.stagenum == STAGE_DEEPSEA) {
					if (!is_stage_difficulty_unlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty)) {
						menu_pop_dialog();
						menu_pop_dialog();
					} else {
						// Commit to starting next stage
						g_MissionConfig.stageindex++;
						g_MissionConfig.stagenum = g_SoloStages[g_MissionConfig.stageindex].stagenum;

						title_set_next_stage(g_MissionConfig.stagenum);

						if (g_MissionConfig.iscoop) {
							if (g_Vars.numaibuddies == 0) {
								g_Vars.bondplayernum = 0;
								g_Vars.coopplayernum = 1;
								g_Vars.antiplayernum = -1;
								set_num_players(2);
							} else {
								g_Vars.bondplayernum = 0;
								g_Vars.coopplayernum = -1;
								g_Vars.antiplayernum = -1;
								set_num_players(1);
							}
						} else {
							g_Vars.bondplayernum = 0;
							g_Vars.coopplayernum = -1;
							g_Vars.antiplayernum = -1;
							set_num_players(1);
						}

						lv_set_difficulty(g_MissionConfig.difficulty);
						title_set_next_mode(TITLEMODE_SKIP);
						main_change_to_stage(g_MissionConfig.stagenum);
						vi_black(true);
					}
				} else if (g_Vars.stagenum == STAGE_SKEDARRUINS) {
					// Commit to starting credits
					g_MissionConfig.stagenum = STAGE_CREDITS;
					title_set_next_stage(g_MissionConfig.stagenum);
					lv_set_difficulty(g_MissionConfig.difficulty);
					title_set_next_mode(TITLEMODE_SKIP);
					main_change_to_stage(g_MissionConfig.stagenum);
					vi_black(true);
				}
			} else {
				if (context == 1) {
					menu_push_root_dialog(&g_MissionContinueOrReplyMenuDialog, MENUROOT_COOPCONTINUE);
				} else {
					menu_push_dialog(&g_MissionContinueOrReplyMenuDialog);
				}
			}
		} else {
			if (context == 2) {
				menu_pop_dialog();
			}

			if (is_stage_difficulty_unlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty) == 0) {
				if (context == 2) {
					menu_pop_dialog();
					menu_pop_dialog();
				} else {
					menu_push_dialog(&g_MissionContinueOrReplyMenuDialog);
				}
			} else if (stage_get_index(g_MissionConfig.stagenum) < 0
						|| g_Vars.stagenum == STAGE_CITRAINING
						|| g_MissionConfig.stageindex >= SOLOSTAGEINDEX_MBR) {
				if (context == 2) {
					menu_pop_dialog();
					menu_pop_dialog();
				} else {
					menu_push_dialog(&g_MissionContinueOrReplyMenuDialog);
				}
			} else {
				endscreen_reset_models();

				if (context == 1) {
					menu_push_root_dialog(endscreen_advance(), MENUROOT_COOPCONTINUE);
				} else {
					menu_push_dialog(endscreen_advance());
				}
			}
		}
	}
}
#endif

MenuDialogHandlerResult endscreen_handle_2p_completed(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_ON_OPEN) {
		g_Menus[g_MpPlayerNum].endscreen.unke1c = 0;
	}

	if (operation == MENUOP_ON_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog) {
			if (g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
					|| (dialogdef->nextsibling && dialogdef->nextsibling == g_Menus[g_MpPlayerNum].curdialog->definition)) {
				struct menuinputs *inputs = data->dialog2.inputs;

				if (inputs->select || inputs->back || inputs->start) {
					g_Menus[g_MpPlayerNum].endscreen.unke1c = VERSION >= VERSION_NTSC_1_0 ? 6 : 3;
				}

				if (g_Menus[g_MpPlayerNum].endscreen.unke1c) {
					if (var8009dfc0) {
						g_Menus[g_MpPlayerNum].endscreen.unke1c--;
					}

					if (g_Menus[g_MpPlayerNum].endscreen.unke1c == 0) {
#if VERSION >= VERSION_NTSC_1_0
						endscreen_continue(0);
#else
						if (g_Vars.stagenum == STAGE_DEEPSEA) {
							if (g_Vars.antiplayernum >= 0 || (g_Vars.coopplayernum >= 0 && PLAYERCOUNT() >= 2)) {
								menu_pop_dialog();
							} else {
								g_MissionConfig.stageindex++;
								g_MissionConfig.stagenum = g_SoloStages[g_MissionConfig.stageindex].stagenum;

								title_set_next_stage(g_MissionConfig.stagenum);
								lv_set_difficulty(g_MissionConfig.difficulty);
								title_set_next_mode(TITLEMODE_SKIP);
								main_change_to_stage(g_MissionConfig.stagenum);
							}
						} else if (g_Vars.antiplayernum >= 0
								|| (g_Vars.coopplayernum >= 0 && PLAYERCOUNT() >= 2)
								|| (stage_get_index(g_MissionConfig.stagenum) < 0
									|| g_Vars.stagenum == STAGE_CITRAINING
									|| g_MissionConfig.stageindex > SOLOSTAGEINDEX_SKEDARRUINS
									|| ((g_CheatsActiveBank0 || g_CheatsActiveBank1)
										&& !is_stage_difficulty_unlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty)))) {
							menu_pop_dialog();
						} else {
							endscreen_reset_models();
							menu_push_dialog(endscreen_advance());
						}
#endif
					}
				}

				inputs->select = inputs->back = inputs->start = false;
			}
		}
	}

	return 0;
}

MenuDialogHandlerResult endscreen_handle_2p_failed(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_ON_OPEN) {
		g_Menus[g_MpPlayerNum].endscreen.unke1c = 0;
	}

	if (operation == MENUOP_ON_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog) {
			if (g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
					|| (dialogdef->nextsibling && dialogdef->nextsibling == g_Menus[g_MpPlayerNum].curdialog->definition)) {
				struct menuinputs *inputs = data->dialog2.inputs;

				if (inputs->select || inputs->back || inputs->start) {
					g_Menus[g_MpPlayerNum].endscreen.unke1c = VERSION >= VERSION_NTSC_1_0 ? 6 : 3;
				}

				if (g_Menus[g_MpPlayerNum].endscreen.unke1c) {
					if (var8009dfc0) {
						g_Menus[g_MpPlayerNum].endscreen.unke1c--;
					}

					if (g_Menus[g_MpPlayerNum].endscreen.unke1c == 0) {
						if (g_Vars.antiplayernum >= 0
								|| (g_Vars.coopplayernum >= 0 && PLAYERCOUNT() >= 2)
								|| stage_get_index(g_MissionConfig.stagenum) < 0
								|| g_Vars.stagenum == STAGE_CITRAINING) {
							menu_pop_dialog();
						} else {
							endscreen_reset_models();
							menu_push_dialog(&g_RetryMissionMenuDialog);
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_OPTIONS_278, // "Mission Status:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)&endscreen_menu_text_mission_status,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_OPTIONS_279, // "Agent Status:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)&endscreen_menu_text_agent_status,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_OPTIONS_280, // "Mission Time:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)&endscreen_menu_text_mission_time,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT,
		L_MPWEAPONS_129, // "Difficulty:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)solo_menu_text_difficulty,
		0,
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
		L_OPTIONS_281, // "Weapon of Choice:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)&mp_menu_text_weapon_of_choice_name,
		0,
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
		L_OPTIONS_282, // "Kills:"
		(uintptr_t)&endscreen_menu_text_num_kills,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_283, // "Accuracy:"
		(uintptr_t)&endscreen_menu_text_accuracy,
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
		L_OPTIONS_284, // "Shot Total:"
		(uintptr_t)&endscreen_menu_text_num_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_OPTIONS_285, // "Head Shots:"
		(uintptr_t)&endscreen_menu_text_num_head_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_OPTIONS_286, // "Body Shots:"
		(uintptr_t)&endscreen_menu_text_num_body_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_OPTIONS_287, // "Limb Shots:"
		(uintptr_t)&endscreen_menu_text_num_limb_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SMALLFONT,
		L_OPTIONS_288, // "Others:"
		(uintptr_t)&endscreen_menu_text_num_other_shots,
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
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_289, // "Press START"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
MenuItemHandlerResult endscreen_handle_cheat_info(s32 operation, struct menuitem *item, union handlerdata *data)
{
	static u32 cheatcolour = 0xff7f7fff;

	if (operation == MENUOP_GET_LABEL_COLOURS
			&& ((g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_TIMED_UNLOCKING) || item->param == 5)) {
		// Timed cheat just got unlocked, or this item is the timed cheat name
		u32 weight = menu_get_sin_osc_frac(40) * 255;

		main_override_variable("ctcol", &cheatcolour);

		if (item->param == 0
				&& cheat_get_time(CHEATINFO_GET_TIMED_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo)) == 0) {
			return 0;
		}

		data->label.colour2 = colour_blend(data->label.colour2, cheatcolour, weight);

		if (item->param == 3) { // completion cheat name
			data->label.colour1 = colour_blend(data->label.colour1, cheatcolour, weight);
		}

		if (item->param == 5) { // timed cheat name
			data->label.colour1 = colour_blend(data->label.colour1, cheatcolour, weight);
		}
	}

	if (operation == MENUOP_IS_HIDDEN) {
		if (item->param == 1) { // target time
			u32 info = g_Menus[g_MpPlayerNum].endscreen.cheatinfo;

			if (info & CHEATINFO_COMPL_UNLOCKING) {
				return true;
			}

			if ((info & CHEATINFO_TIMED_EXISTS)
					&& (info & (CHEATINFO_TIMED_UNLOCKING | CHEATINFO_TIMED_PREVUNLOCKED)) == 0
					&& cheat_get_time(CHEATINFO_GET_TIMED_CHEATNUM(info)) > 0) {
				return false;
			}

			return true;
		} else if (item->param == 2 && (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & (CHEATINFO_TIMED_UNLOCKING | CHEATINFO_COMPL_UNLOCKING)) == 0) {
			// new cheat available
			return true;
		} else if (item->param == 3 && (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_TIMED_UNLOCKING) == 0) {
			// completion cheat name
			return true;
		} else if (item->param == 4 && (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & (CHEATINFO_TIMED_UNLOCKING | CHEATINFO_COMPL_UNLOCKING))) {
			// others (shots)
			return true;
		} else if (item->param == 6 && (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & (CHEATINFO_TIMED_UNLOCKING | CHEATINFO_COMPL_UNLOCKING)) == (CHEATINFO_TIMED_UNLOCKING | CHEATINFO_COMPL_UNLOCKING)) {
			// limb shots
			return true;
		} else if (item->param == 5 && (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_COMPL_UNLOCKING) == 0) {
			// timed cheat name
			return true;
		}
	}

	return false;
}
#endif

struct menuitem g_MissionEndscreenMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_278, // "Mission Status:"
		(uintptr_t)&endscreen_menu_text_mission_status,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_279, // "Agent Status:"
		(uintptr_t)&endscreen_menu_text_agent_status,
		NULL,
	},
#if VERSION >= VERSION_NTSC_1_0
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LABEL_CUSTOMCOLOUR,
		L_OPTIONS_280, // "Mission Time:"
		(uintptr_t)&endscreen_menu_text_mission_time,
		endscreen_handle_cheat_info,
	},
	{
		MENUITEMTYPE_LABEL,
		1,
		MENUITEMFLAG_LABEL_CUSTOMCOLOUR,
		L_MPWEAPONS_242, // "Target Time:"
		(uintptr_t)&endscreen_menu_text_target_time,
		endscreen_handle_cheat_info,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPWEAPONS_129, // "Difficulty:"
		(uintptr_t)&solo_menu_text_difficulty,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		2,
		0,
		0,
		0,
		endscreen_handle_cheat_info,
	},
	{
		MENUITEMTYPE_LABEL,
		2,
		0,
		L_MPWEAPONS_243, // "New Cheat Available!:"
		0,
		endscreen_handle_cheat_info,
	},
	{
		MENUITEMTYPE_LABEL,
		3,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LABEL_CUSTOMCOLOUR,
		(uintptr_t)&endscreen_menu_text_timed_cheat_name,
		0,
		endscreen_handle_cheat_info,
	},
	{
		MENUITEMTYPE_LABEL,
		5,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LABEL_CUSTOMCOLOUR,
		(uintptr_t)&endscreen_menu_text_completion_cheat_name,
		0,
		endscreen_handle_cheat_info,
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
		L_OPTIONS_281, // "Weapon of Choice:"
		(uintptr_t)&mp_menu_text_weapon_of_choice_name,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_282, // "Kills:"
		(uintptr_t)&endscreen_menu_text_num_kills,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_283, // "Accuracy:"
		(uintptr_t)&endscreen_menu_text_accuracy,
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
		L_OPTIONS_284, // "Shot Total:"
		(uintptr_t)&endscreen_menu_text_num_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_285, // "Head Shots:"
		(uintptr_t)&endscreen_menu_text_num_head_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_286, // "Body Shots:"
		(uintptr_t)&endscreen_menu_text_num_body_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		6,
		0,
		L_OPTIONS_287, // "Limb Shots:"
		(uintptr_t)&endscreen_menu_text_num_limb_shots,
		endscreen_handle_cheat_info,
	},
	{
		MENUITEMTYPE_LABEL,
		4,
		0,
		L_OPTIONS_288, // "Others:"
		(uintptr_t)&endscreen_menu_text_num_other_shots,
		endscreen_handle_cheat_info,
	},
#else
	// NTSC beta's endscreen dialog lacks cheat information
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_280, // "Mission Time:"
		(uintptr_t)&endscreen_menu_text_mission_time,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_MPWEAPONS_129, // "Difficulty:"
		(uintptr_t)&solo_menu_text_difficulty,
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
		L_OPTIONS_281, // "Weapon of Choice:"
		(uintptr_t)&mp_menu_text_weapon_of_choice_name,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_282, // "Kills:"
		(uintptr_t)&endscreen_menu_text_num_kills,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_283, // "Accuracy:"
		(uintptr_t)&endscreen_menu_text_accuracy,
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
		L_OPTIONS_284, // "Shot Total:"
		(uintptr_t)&endscreen_menu_text_num_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_285, // "Head Shots:"
		(uintptr_t)&endscreen_menu_text_num_head_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_286, // "Body Shots:"
		(uintptr_t)&endscreen_menu_text_num_body_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_287, // "Limb Shots:"
		(uintptr_t)&endscreen_menu_text_num_limb_shots,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		0,
		L_OPTIONS_288, // "Others:"
		(uintptr_t)&endscreen_menu_text_num_other_shots,
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
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_289, // "Press START"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

#if VERSION >= VERSION_NTSC_1_0
char *endscreen_menu_text_timed_cheat_name(struct menuitem *item)
{
	if (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & (CHEATINFO_TIMED_EXISTS | CHEATINFO_TIMED_UNLOCKING)) {
		return cheat_get_name(CHEATINFO_GET_TIMED_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo));
	}

	return NULL;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *endscreen_menu_text_completion_cheat_name(struct menuitem *item)
{
	if (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_COMPL_UNLOCKING) {
		return cheat_get_name(CHEATINFO_GET_COMPL_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo));
	}

	return NULL;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *endscreen_menu_text_target_time(struct menuitem *item)
{
	s32 time;

	if ((g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_TIMED_EXISTS) == 0) {
		return NULL;
	}

	time = CHEATINFO_GET_TIMED_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo);
	time = cheat_get_time(time);

	if (!time) {
		return NULL;
	}

	format_time(g_StringPointer, time * 60, TIMEPRECISION_SECONDS);
	strcat(g_StringPointer, "\n");
	return g_StringPointer;
}
#endif

void endscreen_set_coop_completed(void)
{
	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0) {
#if VERSION >= VERSION_NTSC_1_0
		if (g_GameFile.coopcompletions[g_MissionConfig.difficulty] & (1 << g_MissionConfig.stageindex)) {
			g_Menus[g_MpPlayerNum].endscreen.isfirstcompletion = true;
		}
#endif

		g_GameFile.coopcompletions[g_MissionConfig.difficulty] |= (1 << g_MissionConfig.stageindex);
	}
}

struct menudialogdef g_SoloMissionEndscreenCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	(uintptr_t)&endscreen_menu_title_stage_completed,
	g_MissionEndscreenMenuItems,
	endscreen_handle_2p_completed,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_SoloEndscreenObjectivesCompletedMenuDialog,
};

struct menudialogdef g_SoloMissionEndscreenFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(uintptr_t)&endscreen_menu_title_stage_failed,
	g_MissionEndscreenMenuItems,
	endscreen_handle_2p_failed,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_SoloEndscreenObjectivesFailedMenuDialog,
};

/**
 * Prepare the endscreen by calculating unlocked cheats, setting the new best
 * time, choosing the default stage and difficulty and saving the game file.
 *
 * NTSC beta doesn't have cheats implemented, and has a different autostageindex
 * and thumbnail calculation.
 */
void endscreen_prepare(void)
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

#if VERSION >= VERSION_NTSC_1_0
	g_Menus[g_MpPlayerNum].endscreen.stageindex = g_MissionConfig.stageindex;
#endif

	if (g_MenuData.root != MENUROOT_ENDSCREEN && g_Vars.mplayerisrunning == false) {
#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].endscreen.cheatinfo = 0;
		g_Menus[g_MpPlayerNum].endscreen.isfirstcompletion = false;
		g_Menus[g_MpPlayerNum].playernum = 0;

		// Set cheat info
		if (g_MissionConfig.iscoop == false
				&& g_MissionConfig.isanti == false
				&& g_MissionConfig.pdmode == false) {
			timedcheatid = cheat_get_by_timed_stage_index(g_MissionConfig.stageindex, g_MissionConfig.difficulty);
			complcheatid = cheat_get_by_completed_stage_index(g_MissionConfig.stageindex);

			if (timedcheatid >= 0) {
				g_Menus[g_MpPlayerNum].endscreen.cheatinfo = CHEATINFO_TIMED_EXISTS | CHEATINFO_SET_TIMED_CHEATNUM(timedcheatid);
			}

			if (complcheatid >= 0) {
				g_Menus[g_MpPlayerNum].endscreen.cheatinfo |= CHEATINFO_COMPL_EXISTS | CHEATINFO_SET_COMPL_CHEATNUM(complcheatid);
			}
		}
#else
		g_Menus[g_MpPlayerNum].playernum = 0;
#endif

		// Push the endscreen
#if VERSION >= VERSION_NTSC_1_0 && defined(DEBUG)
		if ((g_Vars.currentplayer->isdead || g_Vars.currentplayer->aborted || !objective_is_all_complete()) && !debug_is_set_complete_enabled())
#else
		if (g_Vars.currentplayer->isdead || g_Vars.currentplayer->aborted || !objective_is_all_complete())
#endif
		{
			menu_push_root_dialog(&g_SoloMissionEndscreenFailedMenuDialog, MENUROOT_ENDSCREEN);
		} else {
			menu_push_root_dialog(&g_SoloMissionEndscreenCompletedMenuDialog, MENUROOT_ENDSCREEN);

			if (g_MissionConfig.iscoop) {
				endscreen_set_coop_completed();
			}
		}

		if (g_MissionConfig.iscoop == false && g_MissionConfig.isanti == false) {
#if VERSION >= VERSION_NTSC_1_0
			timedalreadyunlocked = false;
			complalreadyunlocked = false;

			if (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_TIMED_EXISTS) {
				timedalreadyunlocked = cheat_is_unlocked(CHEATINFO_GET_TIMED_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo));

				if (timedalreadyunlocked) {
					g_Menus[g_MpPlayerNum].endscreen.cheatinfo |= CHEATINFO_TIMED_PREVUNLOCKED;
				}
			}

			// If there's a completion cheat for this stage (ie. not a special stage)
			if (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_COMPL_EXISTS) {
				complalreadyunlocked = cheat_is_unlocked(CHEATINFO_GET_COMPL_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo));
			}
#else
			player_get_mission_time();
#endif

			// Update total mission time
			secs = player_get_mission_time() / 60;

			if (secs != 0) {
				if (secs >= S32_MAX || S32_MAX - secs <= g_GameFile.totaltime) {
					g_GameFile.totaltime = S32_MAX;
				} else {
					g_GameFile.totaltime += secs;
				}
			}

			g_GameFile.autostageindex = g_MissionConfig.stageindex;
			g_GameFile.autodifficulty = g_MissionConfig.difficulty;

#if VERSION >= VERSION_NTSC_1_0 && defined(DEBUG)
			if (g_CheatsActiveBank0 == 0
					&& g_CheatsActiveBank1 == 0
					&& g_MissionConfig.pdmode == false
					&& ((g_Vars.currentplayer->isdead == false
							&& g_Vars.currentplayer->aborted == false
							&& objective_is_all_complete())
						|| debug_is_set_complete_enabled()))
#elif VERSION >= VERSION_NTSC_1_0
			if (g_CheatsActiveBank0 == 0
					&& g_CheatsActiveBank1 == 0
					&& g_MissionConfig.pdmode == false
					&& g_Vars.currentplayer->isdead == false
					&& g_Vars.currentplayer->aborted == false
					&& objective_is_all_complete())
#else
			if (g_Vars.currentplayer->isdead == false
					&& g_Vars.currentplayer->aborted == false
					&& objective_is_all_complete()
					&& g_CheatsActiveBank0 == 0
					&& g_CheatsActiveBank1 == 0)
#endif
			{
				secs = player_get_mission_time() / 60;

				// The save file allows 12 bits per time, which is up to
				// 1h 8m 16s. If the timer is higher than this, reduce it.
				if (secs > 0xfff) {
					secs = 0xfff;
				}

#if VERSION >= VERSION_NTSC_1_0
				// Zero is used as an indicator that the stage is not completed,
				// so if the player managed to legitly complete a stage in 0:00
				// adjust it to 0:01.
				if (secs == 0) {
					secs = 1;
				}

				// Set best time
				prevbest = g_GameFile.besttimes[g_MissionConfig.stageindex][g_MissionConfig.difficulty];

				if (prevbest == 0) {
					g_Menus[g_MpPlayerNum].endscreen.isfirstcompletion = true;
				}

				if (secs < prevbest || prevbest == 0) {
					g_GameFile.besttimes[g_MissionConfig.stageindex][g_MissionConfig.difficulty] = secs;
				}
#else
				prevbest = g_GameFile.besttimes[g_MissionConfig.stageindex][g_MissionConfig.difficulty];

				if (secs < prevbest || prevbest == 0) {
					g_GameFile.besttimes[g_MissionConfig.stageindex][g_MissionConfig.difficulty] = secs;
				}
#endif

#if VERSION >= VERSION_NTSC_1_0
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

				if (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_TIMED_EXISTS) {
					nowunlocked = cheat_is_unlocked(CHEATINFO_GET_TIMED_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo));

					if (!timedalreadyunlocked && nowunlocked) {
						g_Menus[g_MpPlayerNum].endscreen.cheatinfo |= CHEATINFO_TIMED_UNLOCKING;
					}
				}

				if (g_Menus[g_MpPlayerNum].endscreen.cheatinfo & CHEATINFO_COMPL_EXISTS) {
					nowunlocked = cheat_is_unlocked(CHEATINFO_GET_COMPL_CHEATNUM(g_Menus[g_MpPlayerNum].endscreen.cheatinfo));

					if (!complalreadyunlocked && nowunlocked) {
						g_Menus[g_MpPlayerNum].endscreen.cheatinfo |= CHEATINFO_COMPL_UNLOCKING;
					}
				}
#else
				if (g_MissionConfig.stageindex <= SOLOSTAGEINDEX_SKEDARRUINS) {
					g_GameFile.autostageindex = g_MissionConfig.stageindex + 1;

					if (g_GameFile.autostageindex > SOLOSTAGEINDEX_SKEDARRUINS) {
						g_GameFile.autostageindex = SOLOSTAGEINDEX_SKEDARRUINS;
					}

					g_GameFile.thumbnail = g_MissionConfig.stageindex + 1;
				}
#endif

				challenge_determine_unlocked_features();

				if (g_MissionConfig.stagenum == STAGE_SKEDARRUINS && g_AltTitleUnlocked == false) {
					g_AltTitleUnlocked = true;
#if VERSION >= VERSION_NTSC_1_0
					*(s8 *)&g_AltTitleEnabled = true;
#else
					g_AltTitleEnabled = true;
#endif
					bossfile_save();
				}
			}
		}

		filemgr_save_or_load(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
	}

	if (g_MenuData.root == MENUROOT_ENDSCREEN) {
		lv_set_paused(true);
		g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;
	}
}

struct menudialogdef g_2PMissionEndscreenCompletedHMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	(uintptr_t)&endscreen_menu_title_stage_completed,
	g_MissionEndscreenMenuItems,
	endscreen_handle_2p_completed,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_SoloEndscreenObjectivesCompletedMenuDialog,
};

struct menudialogdef g_2PMissionEndscreenFailedHMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(uintptr_t)&endscreen_menu_title_stage_failed,
	g_MissionEndscreenMenuItems,
	endscreen_handle_2p_failed,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_SoloEndscreenObjectivesFailedMenuDialog,
};

struct menudialogdef g_2PMissionEndscreenCompletedVMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_276, // "Completed"
	g_2PMissionEndscreenVMenuItems,
	endscreen_handle_2p_completed,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_2PMissionEndscreenObjectivesCompletedVMenuDialog,
};

struct menudialogdef g_2PMissionEndscreenFailedVMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_277, // "Failed"
	g_2PMissionEndscreenVMenuItems,
	endscreen_handle_2p_failed,
	MENUDIALOGFLAG_DISABLEITEMSCROLL | MENUDIALOGFLAG_SMOOTHSCROLLABLE,
	&g_2PMissionEndscreenObjectivesFailedVMenuDialog,
};

void endscreen_push_coop(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	lv_set_paused(true);

	g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;

#if VERSION >= VERSION_NTSC_1_0
	g_Menus[g_MpPlayerNum].endscreen.cheatinfo = 0;
	g_Menus[g_MpPlayerNum].endscreen.isfirstcompletion = false;
	g_Menus[g_MpPlayerNum].endscreen.stageindex = g_MissionConfig.stageindex;
#endif

	g_Menus[g_MpPlayerNum].playernum = g_Vars.currentplayernum;

#if VERSION >= VERSION_NTSC_1_0 && defined(DEBUG)
	if (((g_Vars.bond->isdead && g_Vars.coop->isdead)
			|| g_Vars.bond->aborted
			|| g_Vars.coop->aborted
			|| !objective_is_all_complete()) && !debug_is_set_complete_enabled())
#else
	if ((g_Vars.bond->isdead && g_Vars.coop->isdead)
			|| g_Vars.bond->aborted
			|| g_Vars.coop->aborted
			|| !objective_is_all_complete())
#endif
	{
		// Failed or aborted
		if (options_get_screen_split() == SCREENSPLIT_VERTICAL) {
			menu_push_root_dialog(&g_2PMissionEndscreenFailedVMenuDialog, MENUROOT_MPENDSCREEN);
		} else {
			menu_push_root_dialog(&g_2PMissionEndscreenFailedHMenuDialog, MENUROOT_MPENDSCREEN);
		}
	} else {
		// Completed
		if (options_get_screen_split() == SCREENSPLIT_VERTICAL) {
			menu_push_root_dialog(&g_2PMissionEndscreenCompletedVMenuDialog, MENUROOT_MPENDSCREEN);
		} else {
			menu_push_root_dialog(&g_2PMissionEndscreenCompletedHMenuDialog, MENUROOT_MPENDSCREEN);
		}

		endscreen_set_coop_completed();
	}

	if (g_Vars.currentplayer == g_Vars.bond) {
		filemgr_save_or_load(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
	}

	g_MpPlayerNum = prevplayernum;
}

/**
 * This function is misnamed. It pushes the menu after the endscreen
 * (ie. retry, next mission or continue), and it looks like it might be for coop
 * only but I'm not 100% sure.
 *
 * This function is only called from menu_tick, which is a bit weird...
 */
void endscreen_push_solo(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	g_MpPlayerNum = 0;
	g_Menus[g_MpPlayerNum].playernum = 0;

#if VERSION >= VERSION_NTSC_1_0 && defined(DEBUG)
	if (((g_Vars.bond->isdead && g_Vars.coop->isdead)
			|| g_Vars.bond->aborted
			|| g_Vars.coop->aborted
			|| !objective_is_all_complete()) && !debug_is_set_complete_enabled())
#else
	if ((g_Vars.bond->isdead && g_Vars.coop->isdead)
			|| g_Vars.bond->aborted
			|| g_Vars.coop->aborted
			|| !objective_is_all_complete())
#endif
	{
		// Failed or aborted
		endscreen_reset_models();
		menu_push_root_dialog(&g_RetryMissionMenuDialog, MENUROOT_COOPCONTINUE);
	} else {
		// Completed
#if VERSION >= VERSION_NTSC_1_0
		endscreen_continue(1);
#else
		struct menudialogdef *definition = endscreen_advance();

		if (definition) {
			endscreen_reset_models();
			menu_push_root_dialog(definition, MENUROOT_COOPCONTINUE);
		}
#endif
	}

	g_MpPlayerNum = prevplayernum;
}

void endscreen_push_anti(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	lv_set_paused(true);

	g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;

#if VERSION >= VERSION_NTSC_1_0
	g_Menus[g_MpPlayerNum].endscreen.cheatinfo = 0;
	g_Menus[g_MpPlayerNum].endscreen.isfirstcompletion = false;
	g_Menus[g_MpPlayerNum].endscreen.stageindex = g_MissionConfig.stageindex;
#endif

	g_Menus[g_MpPlayerNum].playernum = g_Vars.currentplayernum;

	if (g_Vars.currentplayer == g_Vars.bond) {
#if VERSION >= VERSION_NTSC_1_0 && defined(DEBUG)
		if (!g_Vars.anti->aborted && (g_Vars.bond->isdead || g_Vars.bond->aborted || !objective_is_all_complete()) && !debug_is_set_complete_enabled())
#else
		if (!g_Vars.anti->aborted && (g_Vars.bond->isdead || g_Vars.bond->aborted || !objective_is_all_complete()))
#endif
		{
			// Bond - failed or aborted
			if (options_get_screen_split() == SCREENSPLIT_VERTICAL) {
				menu_push_root_dialog(&g_2PMissionEndscreenFailedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menu_push_root_dialog(&g_2PMissionEndscreenFailedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		} else {
			// Bond - completed
			if (options_get_screen_split() == SCREENSPLIT_VERTICAL) {
				menu_push_root_dialog(&g_2PMissionEndscreenCompletedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menu_push_root_dialog(&g_2PMissionEndscreenCompletedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		}

		filemgr_save_or_load(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
	} else {
#if VERSION >= VERSION_NTSC_1_0 && defined(DEBUG)
		if (!g_Vars.anti->aborted && (g_Vars.bond->isdead || g_Vars.bond->aborted || !objective_is_all_complete()) && !debug_is_set_complete_enabled())
#else
		if (!g_Vars.anti->aborted && (g_Vars.bond->isdead || g_Vars.bond->aborted || !objective_is_all_complete()))
#endif
		{
			// Anti - completed
			if (options_get_screen_split() == SCREENSPLIT_VERTICAL) {
				menu_push_root_dialog(&g_2PMissionEndscreenCompletedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menu_push_root_dialog(&g_2PMissionEndscreenCompletedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		} else {
			// Anti - failed or aborted
			if (options_get_screen_split() == SCREENSPLIT_VERTICAL) {
				menu_push_root_dialog(&g_2PMissionEndscreenFailedVMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menu_push_root_dialog(&g_2PMissionEndscreenFailedHMenuDialog, MENUROOT_MPENDSCREEN);
			}
		}
	}

	g_MpPlayerNum = prevplayernum;
}
