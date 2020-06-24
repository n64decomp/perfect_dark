#ifndef IN_GAME_EXPLOSION_H
#define IN_GAME_EXPLOSION_H
#include <ultra64.h>
#include "types.h"

bool explosionCreateSimple(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
bool explosionCreateComplex(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
f32 explosionGetHorizontalRangeAtFrame(struct explosion *exp, s32 frame);
f32 explosionGetVerticalRangeAtFrame(struct explosion *exp, s32 frame);
void explosionGetBboxAtFrame(struct coord *lower, struct coord *upper, s32 frame, struct prop *prop);
void explosionAlertChrs(f32 *radius, struct coord *noisepos);
bool explosionCreate(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum, bool arg5, struct coord *arg6, s16 arg7, struct coord *arg8);
u32 func0f12acec(void);
bool func0f12af5c(struct explosion *exp, struct prop *prop, struct coord *pos1, struct coord *pos2);
u32 func0f12b0e0(void);
u32 func0f12bbdc(struct prop *prop);
u32 explosionUpdateZ(struct prop *prop);
u32 func0f12c654(void);
u32 func0f12cd64(void);

#endif
