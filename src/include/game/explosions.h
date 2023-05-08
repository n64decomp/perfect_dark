#ifndef IN_GAME_EXPLOSIONS_H
#define IN_GAME_EXPLOSIONS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void explosionsReset(void);

void explosionsStop(void);

bool explosionCreateSimple(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
bool explosionCreateComplex(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum);
void explosionAlertChrs(f32 *radius, struct coord *noisepos);
bool explosionCreate(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum, bool makescorch, struct coord *arg6, s16 room, struct coord *arg8);
void explosionsUpdateShake(struct coord *arg0, struct coord *arg1, struct coord *arg2);
u32 explosionTickPlayer(struct prop *prop);
Gfx *explosionRender(struct prop *prop, Gfx *gdl, bool xlupass);

#endif
