#ifndef _IN_GAME_MPLAYER_SETUP_H
#define _IN_GAME_MPLAYER_SETUP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *mp_get_current_player_name(struct menuitem *item);
s16 mp_choose_random_stage(void);
MenuItemHandlerResult mp_bot_difficulty_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mp_menu_title_edit_simulant(struct menudialogdef *dialogdef);
char *menutext_mp_challenge_name(struct menudialogdef *dialogdef);
MenuDialogHandlerResult menudialog_mp_confirm_challenge(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult mp_challenges_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mp_menu_text_challenge_name(struct menuitem *item);
MenuDialogHandlerResult mp_combat_challenges_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
char *mp_menu_text_save_player_or_copy(struct menuitem *item);
char *mp_menu_text_arena_name(struct menuitem *item);
void mp_configure_quick_team_simulants(void);
void mp_apply_quickstart(void);
void mp_open_advanced_setup(s32 silent);
MenuItemHandlerResult menuhandler_mp_slow_motion(s32 operation, struct menuitem *item, union handlerdata *data);
void htb_add_pad(s16 padnum);
void htb_remove_ammo_crate_at_pad(s16 padnum);
void htb_reset(void);
Gfx *htb_render_hud(Gfx *gdl);
void ctc_init_props(void);
bool ctc_highlight_prop(struct prop *prop, s32 *colour);
void ctc_add_pad(s32 *cmd);
void ctc_highlight_room(RoomNum roomnum, s32 *arg1, s32 *arg2, s32 *arg3);
void koh_tick(void);
Gfx *koh_render_hud(Gfx *gdl);
void koh_add_hill(s32 *cmd);
void koh_highlight_room(RoomNum roomnum, s32 *arg1, s32 *arg2, s32 *arg3);
void htm_add_pad(s16 padnum);
void htm_reset(void);
void htm_init_props(void);
void htm_tick_chr(struct chrdata *chr);
Gfx *htm_render_hud(Gfx *gdl);
Gfx *htm_radar_extra(Gfx *gdl);
bool pac_highlight_prop(struct prop *prop, s32 *colour);
void pac_handle_death(s32 cplayernum, s32 vplayernum);
void pac_tick(void);
Gfx *pac_render_hud(Gfx *gdl);
bool pac_radar_chr(Gfx **gdl, struct prop *prop);
MenuDialogHandlerResult mp_options_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
char *mp_menu_text_scenario_short_name(struct menuitem *item);
char *mp_menu_text_scenario_name(struct menuitem *item);
Gfx *scenario_render_hud(Gfx *gdl);
void scenario_calculate_player_score(struct mpchrconfig *mpchr, s32 chrnum, s32 *arg2, s32 *arg3);
bool scenario_highlight_prop(struct prop *prop, s32 *colour);
void scenario_reset(void);
struct prop *scenario_create_obj(s32 modelnum, s16 padnum, f32 arg2, u32 flags, u32 flags2, u32 flags3);
void scenario_create_hudmsg(s32 playernum, char *message);
bool scenario_chrs_are_same_team(s32 playernum1, s32 playernum2);
s32 scenario_pick_up_briefcase(struct chrdata *chr, struct prop *prop);
void scenario_handle_dropped_token(struct chrdata *chr, struct prop *prop);
s32 scenario_pick_up_uplink(struct chrdata *chr, struct prop *prop);
void scenario_handle_activated_prop(struct chrdata *chr, struct prop *prop);
s32 mp_get_num_stages(void);
MenuItemHandlerResult menuhandler_mp_checkbox_option(s32 operation, struct menuitem *item, union handlerdata *data);
MenuDialogHandlerResult menudialog_mp_simulant(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_delete_simulant(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_change_simulant_type(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_lock(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_save_player(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_save_settings(s32 operation, struct menuitem *item, union handlerdata *data);
MenuDialogHandlerResult menudialog_mp_game_setup(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog_mp_quick_go(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_display_team(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_one_hit_kills(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
