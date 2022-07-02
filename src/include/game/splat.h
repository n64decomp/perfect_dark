#ifndef _IN_GAME_SPLAT_H
#define _IN_GAME_SPLAT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void splatTickChr(struct prop *prop);
void splatsCreateForChrHit(struct prop *prop, struct shotdata *arg1, struct coord *arg2, struct coord *arg3, s32 arg4, s32 arg5, struct chrdata *arg6);
s32 splatsCreate(s32 qty, f32 arg1, struct prop *prop, struct shotdata *arg3, struct coord *arg4, struct coord *arg5, s32 arg6, s32 arg7, s32 arg8, struct chrdata *arg9, s32 arg10);
bool splat0f149274(f32 arg0, struct prop *prop, struct shotdata *arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, struct chrdata *arg7, s32 arg8);
void splatsTick(void);
void splatResetChr(struct chrdata *chr);
void pheadInit2(void);

#endif
