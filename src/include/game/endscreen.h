#ifndef IN_GAME_ENDSCREEN_H
#define IN_GAME_ENDSCREEN_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

MenuDialogHandlerResult endscreen_handle_retry_mission(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult endscreen_handle_2p_completed(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult endscreen_handle_2p_failed(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult endscreen_handle_decline_mission(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreen_handle_cheat_info(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreen_handle_continue_mission(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreen_handle_replay_last_level(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreen_handle_replay_previous_mission(s32 operation, struct menuitem *item, union handlerdata *data);
char *endscreen_menu_title_retry_mission(struct menudialogdef *dialogdef);
char *endscreen_menu_title_next_mission(struct menudialogdef *dialogdef);
char *endscreen_menu_text_num_kills(struct menuitem *item);
char *endscreen_menu_text_num_shots(struct menuitem *item);
char *endscreen_menu_text_num_head_shots(struct menuitem *item);
char *endscreen_menu_text_num_body_shots(struct menuitem *item);
char *endscreen_menu_text_num_limb_shots(struct menuitem *item);
char *endscreen_menu_text_num_other_shots(struct menuitem *item);
char *endscreen_menu_text_accuracy(struct menuitem *item);
char *endscreen_menu_text_mission_status(struct menuitem *item);
char *endscreen_menu_text_agent_status(struct menuitem *item);
char *endscreen_menu_title_stage_completed(struct menuitem *item);
char *endscreen_menu_text_current_stage_name3(struct menuitem *item);
char *endscreen_menu_title_stage_failed(struct menuitem *item);
char *endscreen_menu_text_mission_time(struct menuitem *item);
struct menudialogdef *endscreen_advance(void);
void endscreen_reset_models(void);
void endscreen_continue(s32 context);
char *endscreen_menu_text_timed_cheat_name(struct menuitem *item);
char *endscreen_menu_text_completion_cheat_name(struct menuitem *item);
char *endscreen_menu_text_target_time(struct menuitem *item);
void endscreen_set_coop_completed(void);
void endscreen_prepare(void);
void endscreen_push_coop(void);
void endscreen_push_solo(void);
void endscreen_push_anti(void);

#endif
