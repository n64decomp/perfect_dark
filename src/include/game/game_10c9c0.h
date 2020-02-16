#ifndef _IN_GAME_GAME_10C9C0_H
#define _IN_GAME_GAME_10C9C0_H
#include <ultra64.h>
#include "types.h"

u32 func0f10cb2c(void);
s32 menuhandler4MbDropOut(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler0010ca1c(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler4MbAdvancedSetup(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler0010cabc(u32 operation, struct menu_item *item, s32 *value);
bool menudialog4MbMainMenu(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem);

#endif
