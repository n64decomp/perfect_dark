#ifndef _IN_GAME_MPLAYER_INGAME_H
#define _IN_GAME_MPLAYER_INGAME_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

MenuItemHandlerResult mp_stats_for_player_dropdown_handler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mp_menu_text_in_game_limit(struct menuitem *item);
char *menutext_pause_or_unpause(s32 arg0);
char *menutext_match_time(s32 arg0);
char *mp_menu_text_weapon_description(struct menuitem *item);
char *mp_menu_title_stats_for(struct menudialogdef *dialogdef);
char *mp_menu_text_weapon_of_choice_name(struct menuitem *item);
char *mp_menu_text_award1(struct menuitem *item);
char *mp_menu_text_award2(struct menuitem *item);
char *mp_menu_text_placement_with_suffix(struct menuitem *item);
MenuItemHandlerResult mp_placement_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult mp_awards_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult mp_player_title_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mp_menu_text_player_title(s32 arg0);
MenuItemHandlerResult mp_confirm_player_name_handler(s32 operation, struct menuitem *item, union handlerdata *data);
void mp_push_pause_dialog(void);
void mp_push_endscreen_dialog(u32 arg0, u32 playernum);
MenuItemHandlerResult menuhandler_mp_end_game(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler00178018(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_in_game_limit_label(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_mp_pause(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
