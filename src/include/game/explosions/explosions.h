#ifndef IN_GAME_EXPLOSIONS_EXPLOSIONS_H
#define IN_GAME_EXPLOSIONS_EXPLOSIONS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool explosionCreateSimple(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
bool explosionCreateComplex(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
f32 explosionGetHorizontalRangeAtFrame(struct explosion *exp, s32 frame);
f32 explosionGetVerticalRangeAtFrame(struct explosion *exp, s32 frame);
void explosionGetBboxAtFrame(struct coord *lower, struct coord *upper, s32 frame, struct prop *prop);
void explosionAlertChrs(f32 *radius, struct coord *noisepos);
bool explosionCreate(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum, bool arg5, struct coord *arg6, s16 room, struct coord *arg8);
void func0f12acec(struct coord *arg0, struct coord *arg1, struct coord *arg2);
bool func0f12af5c(struct explosion *exp, struct prop *prop, struct coord *pos1, struct coord *pos2);
u32 func0f12b0e0(void);
u32 func0f12bbdc(struct prop *prop);
u32 explosionUpdateZ(struct prop *prop);
Gfx *explosionRender(struct prop *prop, Gfx *gdl, bool withalpha);
Gfx *explosionRenderPart(struct explosion *exp, struct explosionpart *part, Gfx *gdl, struct coord *coord, s32 arg4);

#endif
