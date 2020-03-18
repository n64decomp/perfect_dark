#ifndef _IN_GAME_GAME_177E00_H
#define _IN_GAME_GAME_177E00_H
#include <ultra64.h>
#include "types.h"

s32 menuhandler00177e00(u32, u32, u32 *);
u32 func0f178050(void);
char *menutextPauseOrUnpause(s32 arg0);
char *menutextMatchTime(s32 arg0);
u32 func0f178330(void);
u32 func0f1783a0(void);
u32 func0f178450(void);
u32 func0f1784a4(void);
u32 func0f1784f0(void);
u32 func0f17853c(void);
s32 menuhandler001785c4(u32, u32, u32 *);
s32 menuhandler001786d8(u32, u32, u32 *);
s32 menuhandler00178a94(u32, u32, u32 *);
char *mpMenuTextPlayerTitle(s32 arg0);
s32 menuhandler00178bf4(u32, u32, u32 *);
u32 func0f178dbc(void);
u32 func0f178ef0(void);
s32 menuhandlerMpEndGame(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler00178018(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerMpInGameLimitLabel(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerMpPause(u32 operation, struct menu_item *item, s32 *value);

#endif
