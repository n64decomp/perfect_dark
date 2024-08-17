#ifndef _IN_GAME_WALLHIT_H
#define _IN_GAME_WALLHIT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void wallhit_reset(void);

s16 wallhit_finalise_axis(f32 arg0);
void wallhit_free(struct wallhit *wallhit);
void wallhits_free_by_prop(struct prop *prop, s8 layer);
bool chr_is_using_paintball(struct chrdata *chr);
void wallhit_choose_blood_colour(struct prop *prop);
void wallhit_fade(struct wallhit *wallhit, u32 arg1);
bool wallhit_remove_one_in_room(s32 arg0);
void wallhit_remove_one(void);
void wallhits_tick(void);

void wallhit_create(struct coord *relpos, struct coord *arg1, struct coord *arg2, s16 arg3[3],
		s16 arg4[3], s16 texnum, RoomNum room, struct prop *objprop,
		s8 mtxindex, s8 arg9, struct chrdata *chr, bool xlu);

void wallhit_create_with_20_args(struct coord *relpos, struct coord *arg1, struct coord *arg2, s16 arg3[3],
		s16 arg4[3], s16 texnum, RoomNum room, struct prop *objprop,
		struct prop *chrprop, s8 mtxindex, s8 arg10, struct chrdata *chr,
		f32 width, f32 height, u8 minalpha, u8 maxalpha,
		s32 rotdeg, u32 timermax, u32 timerspeed, bool xlu);

s32 wallhit0f140750(struct coord *coord);
Gfx *wallhit_render_prop_hits(Gfx *gdl, struct prop *prop, bool xlupass);
Gfx *wallhit_render_bg_hits(s32 roomnum, Gfx *gdl);
void wallhits_recolour(void);
void wallhit_fade_splats_for_removed_chr(struct prop *chrprop);
void wallhit_remove_oldest_wounded_splat_by_chr(struct prop *chrprop);

#endif
