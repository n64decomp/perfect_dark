#ifndef _IN_GAME_MPLAYER_INGAME_H
#define _IN_GAME_MPLAYER_INGAME_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *menutextPauseOrUnpause(s32 arg0);
char *mpMenuTextWeaponOfChoiceName(struct menuitem *item);
char *mpMenuTextPlayerTitle(s32 arg0);
void mpPushPauseDialog(void);
void mpPushEndscreenDialog(u32 arg0, u32 playernum);
s32 menuhandlerMpPause(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
