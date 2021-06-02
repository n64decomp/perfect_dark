#ifndef _IN_GAME_SPARKS_SPARKS_H
#define _IN_GAME_SPARKS_SPARKS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 func0f12f6c0(void);
void sparkgroupEnsureFreeSparkSlot(struct sparkgroup *group);
void sparksCreate(s32 room, struct prop *prop, struct coord *pos, struct coord *arg3, struct coord *dir, s32 arg5);
Gfx *sparksRender(Gfx *gdl);

#endif
