#ifndef _IN_GAME_SPARKS_SPARKS_H
#define _IN_GAME_SPARKS_SPARKS_H
#include <ultra64.h>
#include "types.h"

u32 func0f12f6c0(void);
void sparkgroupEnsureFreeSparkSlot(struct sparkgroup *group);
void sparksCreate(s32 room, struct prop *prop, struct coord *pos, struct coord *arg3, s32 arg4, s32 arg5);
Gfx *func0f130044(Gfx *gdl);

#endif
