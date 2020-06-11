#ifndef IN_GAME_GAME_129900_H
#define IN_GAME_GAME_129900_H
#include <ultra64.h>
#include "types.h"

bool func0f129900(struct prop *prop, struct coord *pos, s16 *room, s16 arg3, s32 playernum);
u32 func0f129940(void);
u32 func0f129b08(void);
u32 func0f129ba4(void);
u32 func0f129c08(void);
void alertNearbyChrsToNoise(f32 *radius, struct coord *noisepos);
bool explosionCreate(struct prop *prop, struct coord *pos, s16 *room, s16 arg3, s32 playernum, u32 arg5, u32 arg6, u32 arg7, u32 arg8);
u32 func0f12acec(void);
u32 func0f12af5c(void);
u32 func0f12b0e0(void);
u32 func0f12bbdc(void);
u32 func0f12c5a8(void);
u32 func0f12c654(void);
u32 func0f12cd64(void);

#endif
