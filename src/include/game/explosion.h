#ifndef IN_GAME_EXPLOSION_H
#define IN_GAME_EXPLOSION_H
#include <ultra64.h>
#include "types.h"

bool explosionCreateSimple(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
bool explosionCreateComplex(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
u32 func0f129b08(void);
u32 func0f129ba4(void);
u32 func0f129c08(void);
void alertNearbyChrsToNoise(f32 *radius, struct coord *noisepos);
bool explosionCreate(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum, bool arg5, struct coord *arg6, s16 arg7, struct coord *arg8);
u32 func0f12acec(void);
u32 func0f12af5c(void);
u32 func0f12b0e0(void);
u32 func0f12bbdc(void);
u32 func0f12c5a8(void);
u32 func0f12c654(void);
u32 func0f12cd64(void);

#endif
