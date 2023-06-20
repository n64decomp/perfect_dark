#ifndef IN_GAME_EXPLOSIONS_H
#define IN_GAME_EXPLOSIONS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void explosionsReset(void);

void explosionsStop(void);

bool explosionCreateSimple(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum);
bool explosionCreateComplex(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum);
f32 explosionGetHorizontalRangeAtFrame(struct explosion *exp, s32 frame);
f32 explosionGetVerticalRangeAtFrame(struct explosion *exp, s32 frame);
void explosionGetBboxAtFrame(struct coord *lower, struct coord *upper, s32 frame, struct prop *prop);
void explosionAlertChrs(f32 *radius, struct coord *noisepos);
bool explosionCreate(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum, bool makescorch, struct coord *arg6, RoomNum room, struct coord *arg8);
void explosionsUpdateShake(struct coord *arg0, struct coord *arg1, struct coord *arg2);
bool explosionOverlapsProp(struct explosion *exp, struct prop *prop, struct coord *pos1, struct coord *pos2);
void explosionInflictDamage(struct prop *prop);
u32 explosionTick(struct prop *prop);
u32 explosionTickPlayer(struct prop *prop);
Gfx *explosionRender(struct prop *prop, Gfx *gdl, bool xlupass);
Gfx *explosionRenderPart(struct explosion *exp, struct explosionpart *part, Gfx *gdl, struct coord *coord, s32 arg4);

#endif
