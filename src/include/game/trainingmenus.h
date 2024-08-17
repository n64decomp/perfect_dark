#ifndef IN_GAME_TRAINING_MENUS_H
#define IN_GAME_TRAINING_MENUS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *fr_menu_text_fail_reason(struct menuitem *item);
char *fr_menu_text_difficulty_name(struct menuitem *item);
char *fr_menu_text_time_taken_value(struct menuitem *item);
char *fr_menu_text_score_value(struct menuitem *item);
char *fr_menu_text_weapon_name(struct menuitem *item);
char *fr_menu_text_targets_destroyed_value(struct menuitem *item);
char *fr_menu_text_accuracy_value(struct menuitem *item);
char *fr_menu_text_goal_score_label(struct menuitem *item);
char *fr_menu_text_goal_score_value(struct menuitem *item);
char *fr_menu_text_min_accuracy_or_targets_label(struct menuitem *item);
char *fr_menu_text_min_accuracy_or_targets_value(struct menuitem *item);
char *fr_menu_text_time_limit_label(struct menuitem *item);
char *fr_menu_text_time_limit_value(struct menuitem *item);
char *fr_menu_text_ammo_limit_label(struct menuitem *item);
char *fr_menu_text_ammo_limit_value(struct menuitem *item);
char *ci_menu_text_chr_bio_name(struct menuitem *item);
char *ci_menu_text_chr_bio_age(struct menuitem *item);
char *ci_menu_text_chr_bio_race(struct menuitem *item);
char *ci_menu_text_misc_bio_name(struct menuitem *item);
char *dt_menu_text_name(struct menuitem *item);
char *dt_menu_text_ok_or_resume(struct menuitem *item);
char *dt_menu_text_cancel_or_abort(struct menuitem *item);
char *dt_menu_text_time_taken_value(struct menuitem *item);
char *ht_menu_text_name(struct menuitem *item);
char *ht_menu_text_ok_or_resume(struct menuitem *item);
char *ht_menu_text_cancel_or_abort(struct menuitem *item);
char *ht_menu_text_time_taken_value(struct menuitem *item);
char *bio_menu_text_name(struct menuitem *item);
char *ci_menu_text_hangar_bio_subheading(struct menuitem *item);
struct menudialogdef *ci_get_fr_weapon_list_menu_dialog(void);
MenuDialogHandlerResult fr_training_info_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult fr_training_stats_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult ci_character_profile_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult dt_training_details_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog_device_training_results(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog001a6aa4(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog_firing_range_results(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult ci_hangar_holograph_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult fr_details_ok_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fr_abort_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fr_weapon_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fr_scoring_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_fr_failed_continue(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult ci_office_information_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult dt_device_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_dt_ok_or_resume(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler001a6514(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult ht_holo_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler001a6a34(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler001a6a70(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult ci_hangar_information_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult ci_hangar_title_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fr_difficulty_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
