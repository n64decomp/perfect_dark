#ifndef _IN_GAME_WALLHIT_H
#define _IN_GAME_WALLHIT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void wallhitReset(void);

s16 wallhit0f13e0e0(f32 arg0);
void wallhitFree(struct wallhit *wallhit);
void wallhitsFreeByProp(struct prop *prop, s8 layer);
bool chrIsUsingPaintball(struct chrdata *chr);
void wallhit0f13e5c8(struct prop *prop);
void wallhit0f13e640(struct wallhit *wallhit, u32 arg1);
bool wallhit0f13e744(s32 arg0);
void wallhit0f13e994(void);
void wallhitsTick(void);

void wallhitCreate(struct coord *arg0, struct coord *arg1, struct coord *arg2, u32 arg3,
		u32 arg4, s16 arg5, s16 room, struct prop *arg7,
		s8 arg8, s8 arg9, struct chrdata *chr, bool arg11);

void wallhit0f13f504(struct coord *arg0, struct coord *arg1, struct coord *arg2, u32 arg3,
		u32 arg4, s16 arg5, s16 room, struct prop *arg7,
		u32 arg8, s8 arg9, s8 arg10, struct chrdata *chr,
		f32 arg12, f32 arg13, u8 arg14, u8 arg15,
		u32 arg16, u32 arg17, u32 arg18, bool arg19);

s32 wallhit0f140750(struct coord *coord);
Gfx *wallhitRenderBgHitsLayer1(s32 roomnum, Gfx *gdl);
Gfx *wallhitRenderBgHitsLayer2(s32 roomnum, Gfx *gdl);
Gfx *wallhitRenderPropHits(Gfx *gdl, struct prop *prop, bool withalpha);
Gfx *wallhitRenderBgHits(s32 roomnum, Gfx *gdl);
void wallhitsRecolour(void);
void wallhit0f14159c(struct prop *prop);
void wallhit0f141704(struct prop *prop);

#endif
