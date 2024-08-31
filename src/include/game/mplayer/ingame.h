#ifndef _IN_GAME_MPLAYER_INGAME_H
#define _IN_GAME_MPLAYER_INGAME_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *menutext_pause_or_unpause(s32 arg0);
char *mp_menu_text_weapon_of_choice_name(struct menuitem *item);
char *mp_menu_text_player_title(s32 arg0);
void mp_push_pause_dialog(void);
void mp_push_endscreen_dialog(u32 arg0, u32 playernum);
MenuItemHandlerResult menuhandler_mp_pause(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
