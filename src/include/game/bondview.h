#ifndef _IN_GAME_BONDVIEW_H
#define _IN_GAME_BONDVIEW_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *bview_draw_ir_rect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);
Gfx *bview_copy_pixels(Gfx *gdl, u16 *fb, s32 top, u32 tile, s32 arg4, f32 arg5, s32 left, s32 width);
Gfx *bview_draw_fisheye_rect(Gfx *gdl, s32 arg1, f32 arg2, s32 arg3, s32 arg4);
Gfx *bview_prepare_static_rgba16(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bview_prepare_static_i8(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bview_draw_motion_blur(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bview_draw_static(Gfx *gdl, u32 arg1, s32 arg2);
Gfx *bview_draw_slayer_rocket_interlace(Gfx *gdl, u32 arg1, u32 arg2);
Gfx *bview_draw_film_interlace(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bview_draw_zoom_blur(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4);
f32 bview0f142d74(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
Gfx *bview_draw_fisheye(Gfx *gdl, u32 colour, u32 alpha, s32 shuttertime60, s8 startuptimer60, u8 hit);
Gfx *bview_draw_eyespy_side_rect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha);
Gfx *bview_draw_eyespy_metrics(Gfx *gdl);
Gfx *bview_draw_nv_lens(Gfx *gdl);
Gfx *bview_draw_ir_lens(Gfx *gdl);
Gfx *bview_draw_intro_text(Gfx *gdl);
Gfx *bview_draw_horizon_scanner(Gfx *gdl);
Gfx *bview_draw_ir_binoculars(Gfx *gdl);
void bview_set_motion_blur(u32 bluramount);
void bview_clear_motion_blur(void);
Gfx *bview_draw_nv_binoculars(Gfx *gdl);

#endif
