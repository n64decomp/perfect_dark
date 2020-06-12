#ifndef _IN_GAME_SMOKE_H
#define _IN_GAME_SMOKE_H
#include <ultra64.h>
#include "types.h"

u32 func0f12d3f0(void);
struct smoke *smokeCreate(struct coord *pos, s16 *rooms, s16 type);
u32 func0f12e454(void);
bool func0f12e5b0(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, bool arg4);
void smokeCreateAtProp(struct prop *prop, s16 type);
void func0f12e74c(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, bool arg4);
u32 func0f12e77c(void);
struct smoke *smokeCreateSimple(struct coord *pos, s16 *rooms, s16 type);
u32 func0f12e848(void);
u32 smokeUpdateZ(struct prop *prop);
u32 func0f12f230(void);
u32 func0f12f5f8(void);

#endif
