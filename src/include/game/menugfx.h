#ifndef IN_GAME_MENUGFX_H
#define IN_GAME_MENUGFX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void menugfx_create_blur(void);
Gfx *menugfx_render_bg_blur(Gfx *gdl, u32 colour, s16 arg2, s16 arg3);
Gfx *menugfx_render_dialog_background(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, struct menudialog *dialog, u32 colour1, u32 colour2, f32 arg8);
Gfx *menugfx_render_bg_green_haze(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);
Gfx *menugfx_draw_dropdown_background(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);

#if VERSION >= VERSION_NTSC_1_0
Gfx *menugfx_draw_list_group_header(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 x3, u8 alpha);
#else
Gfx *menugfx_draw_list_group_header(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 x3);
#endif

Gfx *menugfx_render_gradient(Gfx *gdl, s32 x, s32 y, s32 width, s32 height, u32 colour1, u32 colour2, u32 colour3);
Gfx *menugfx_render_slider(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 markerx, u32 colour);
Gfx *menugfx0f0e2348(Gfx *gdl);
Gfx *menugfx0f0e2498(Gfx *gdl);
Gfx *menugfx_draw_tri2(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2, bool arg7);
Gfx *menugfx_draw_line(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfx_draw_projected_line(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfx_draw_shimmer(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour, bool arg6, s32 arg7, bool lefttoright);
Gfx *menugfx_draw_dialog_border_line(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfx_draw_filled_rect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfx_draw_carousel_chevron(Gfx *gdl, s32 x, s32 y, s32 size, s32 direction, u32 colour1, u32 colour2);
Gfx *menugfx_draw_dialog_chevron(Gfx *gdl, s32 x, s32 y, s32 arg2, s32 arg3, u32 colour1, u32 colour2, f32 arg7);
Gfx *menugfx_draw_checkbox(Gfx *gdl, s32 x, s32 y, s32 size, bool fill, u32 bordercolour, u32 fillcolour);
Gfx *menugfx_render_bg_failure(Gfx *gdl);
Gfx *menugfx_render_bg_cone(Gfx *gdl);
Gfx *menugfx_render_bg_failure_copy(Gfx *gdl);
void menugfx_free_particles(void);
u32 menugfx_get_particle_array_size(void);
Gfx *menugfx_render_bg_success(Gfx *gdl);

#endif
