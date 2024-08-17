#ifndef IN_GAME_SHARDS_H
#define IN_GAME_SHARDS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void shards_create(struct coord *pos, f32 *rotx, f32 *roty, f32 *rotz, f32 xmin, f32 xmax, f32 ymin, f32 ymax, s32 type, struct prop *prop);
void shards_reset(void);
Gfx *shards_render(Gfx *gdl);
void shards_stop(void);
void shards_tick(void);

#endif
