#ifndef _IN_GAME_SPLAT_H
#define _IN_GAME_SPLAT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void splat_tick_chr(struct prop *prop);
void splats_create_for_chr_hit(struct prop *prop, struct shotdata *arg1, struct coord *arg2, struct coord *arg3, s32 arg4, s32 arg5, struct chrdata *arg6);
s32 splats_create(s32 qty, f32 arg1, struct prop *prop, struct shotdata *arg3, struct coord *arg4, struct coord *arg5, bool isskedar, s32 arg7, s32 arg8, struct chrdata *arg9, s32 arg10);
void splats_tick(void);
void splat_reset_chr(struct chrdata *chr);

#endif
