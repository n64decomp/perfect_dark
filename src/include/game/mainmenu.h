#ifndef IN_GAME_MAINMENU_H
#define IN_GAME_MAINMENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u16 g_ControlStyleOptions[];

extern struct menudialogdef g_AcceptMissionMenuDialog;
extern struct menudialogdef g_PreAndPostMissionBriefingMenuDialog;
extern struct menudialogdef g_RetryMissionMenuDialog;
extern struct menudialogdef g_NextMissionMenuDialog;

char *menu_text_current_stage_name(struct menuitem *item);
char *solo_menu_text_difficulty(struct menuitem *item);
MenuItemHandlerResult menuhandler_control_style_impl(s32 operation, struct menuitem *item, union handlerdata *data, s32 mpindex);
char *solo_menu_title_stage_overview(struct menudialogdef *dialogdef);
f32 func0f1036ac(u8 value, s32 prop);
bool is_stage_difficulty_unlocked(s32 stageindex, s32 difficulty);
char *solo_menu_text_best_time(struct menuitem *item);
s32 get_max_ai_buddies(void);
s32 get_num_unlocked_special_stages(void);
s32 func0f104720(s32 value);
char *func0f105664(struct menuitem *item);
char *func0f1056a0(struct menuitem *item);
char *inv_menu_text_primary_function(struct menuitem *item);
char *inv_menu_text_secondary_function(struct menuitem *item);
void func0f105948(s32 weaponnum);
char *inv_menu_text_weapon_name(struct menuitem *item);
char *inv_menu_text_weapon_manufacturer(struct menuitem *item);
char *inv_menu_text_weapon_description(struct menuitem *item);
bool solo_choose_pause_dialog(void);
MenuDialogHandlerResult menudialog_briefing(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog00103608(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog_coop_anti_options(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog0010559c(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult inventory_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog_abort_mission(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult solo_menu_dialog_pause_status(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult menuhandler001024dc(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler001024fc(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_accept_mission(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_accept_pd_mode_settings(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_buddy_options_continue(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_coop_difficulty(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_anti_difficulty(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mission_list(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_control_style(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_fr_inventory_list(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_inventory_list(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_abort_mission(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_cinema(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_aim_control(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_alternative_title(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_always_show_target(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_ammo_on_screen(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_anti_player(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_anti_radar(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_autoaim(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_change_agent(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_coop_buddy(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_coop_friendly_fire(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_coop_radar(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_cutscene_subtitles(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_head_roll(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_hi_res(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_in_game_subtitles(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_lang_filter(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_look_ahead(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_music_volume(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_paintball(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_pd_mode(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_pd_mode_setting(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_reverse_pitch(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_screen_ratio(s32 operation, struct menuitem *item, union handlerdata *data);
#if PAL
MenuItemHandlerResult menuhandler_language(s32 operation, struct menuitem *item, union handlerdata *data);
#endif
MenuItemHandlerResult menuhandler_screen_size(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_screen_split(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_sfx_volume(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_show_gun_function(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_show_mission_time(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_show_zoom_range(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_sight_on_screen(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_solo_difficulty(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_sound_mode(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
