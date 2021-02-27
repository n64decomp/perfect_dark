#ifndef IN_GAME_SHARDS_H
#define IN_GAME_SHARDS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void shardsCreate(struct coord *pos, f32 *rotx, f32 *roty, f32 *rotz, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 type, struct prop *prop);
void shardsInit(void);
Gfx *shardsRender(Gfx *gdl);
void shardsReset(void);
void shardsTick(void);

#endif
