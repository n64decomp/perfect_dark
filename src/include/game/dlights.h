#ifndef IN_GAME_DLIGHTS_H
#define IN_GAME_DLIGHTS_H
#include <ultra64.h>
#include "types.h"

u32 func0f000920(void);
u32 func0f00097c(void);
u32 func0f0009c0(void);
u32 func0f000a10(void);
u32 func0f000b24(void);
s32 roomGetBrightness(s16 room);
u32 func0f000c54(void);
u32 func0f000cc4(void);
u32 func0f000dbc(void);
u32 func0f000dfc(void);
u32 func0f000f50(void);
u32 func0f000f94(void);
u32 func0f000fbc(void);
u32 func0f001000(void);
u32 func0f0010d8(void);
u32 func0f001138(void);
u32 func0f001300(void);
u32 func0f0013c8(void);
u32 func0f001734(void);
void func0f001a64(s32, s32 value);
u32 func0f001b78(void);
void func0f001bdc(void);
u32 func0f001c0c(void);
u32 func0f00215c(void);
u32 func0f0023b8(void);
u32 func0f00259c(void);
u32 func0f002844(void);
u32 func0f002a98(void);
void func0f002b58(s32 roomthing, bool enable);
void func0f002c28(s32 room_id, s32 operation, s32 arg2, s32 arg3, s32 arg4);
u32 func0f002ef8(void);
void func0f0033b0(void);
u32 func0f003444(void);
u32 func0f0035c0(void);
u32 func0f00372c(void);
u32 func0f0037ac(void);
u32 func0f004314(void);
u32 func0f00438c(void);
u32 func0f004558(void);
u32 func0f004604(void);
u32 func0f004c6c(void);
u32 func0f00505c(void);
u32 func0f0053d0(void);
void func0f0056f4(s32 room1, struct coord *coord1, s32 room2, struct coord *coord2, s32 arg4, f32 *arg5, s32 arg6);
u32 func0f005bb0(void);

#endif
