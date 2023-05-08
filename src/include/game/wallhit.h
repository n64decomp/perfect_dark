#ifndef _IN_GAME_WALLHIT_H
#define _IN_GAME_WALLHIT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void wallhitReset(void);

void wallhitsFreeByProp(struct prop *prop, s8 layer);
bool chrIsUsingPaintball(struct chrdata *chr);
void wallhitChooseBloodColour(struct prop *prop);
void wallhitsTick(void);

void wallhitCreate(struct coord *relpos, struct coord *arg1, struct coord *arg2, s16 arg3[3],
		s16 arg4[3], s16 texnum, s16 room, struct prop *objprop,
		s8 mtxindex, s8 arg9, struct chrdata *chr, bool xlu);

void wallhitCreateWith20Args(struct coord *relpos, struct coord *arg1, struct coord *arg2, s16 arg3[3],
		s16 arg4[3], s16 texnum, s16 room, struct prop *objprop,
		struct prop *chrprop, s8 mtxindex, s8 arg10, struct chrdata *chr,
		f32 width, f32 height, u8 minalpha, u8 maxalpha,
		s32 rotdeg, u32 timermax, u32 timerspeed, bool xlu);

s32 wallhit0f140750(struct coord *coord);
Gfx *wallhitRenderPropHits(Gfx *gdl, struct prop *prop, bool xlupass);
Gfx *wallhitRenderBgHits(s32 roomnum, Gfx *gdl);
void wallhitsRecolour(void);
void wallhitFadeSplatsForRemovedChr(struct prop *chrprop);
void wallhitRemoveOldestWoundedSplatByChr(struct prop *chrprop);

#endif
