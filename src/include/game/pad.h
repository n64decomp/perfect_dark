#ifndef IN_GAME_PAD_H
#define IN_GAME_PAD_H
#include <ultra64.h>
#include "types.h"

void padUnpack(s32 padnum, u32 fields, struct pad *pad);
bool padHasBboxData(s32 padnum);
void padGetCentre(s32 padnum, struct coord *coord);
u32 func0f116068(void);
void padCopyBboxFromPad(s32 padnum, struct pad *src);
void padSetFlag(s32 padnum, u32 flag);
void padUnsetFlag(s32 padnum, u32 flag);
s32 func0f1162d0(void);
u32 func0f1162e0(s16 cover, struct coord **pos);
u32 func0f11645c(void);
void func0f1164a4(s16 cover, u32 arg1);
u32 func0f116508(void);
u32 func0f116528(void);
u32 func0f11654c(void);
u32 func0f1165b0(void);

#endif
