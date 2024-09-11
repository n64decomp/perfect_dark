#ifndef _IN_GAME_TEXT_H
#define _IN_GAME_TEXT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

#define DIAGMODE_FADEIN  0
#define DIAGMODE_REDRAW  1
#define DIAGMODE_FADEOUT 2

void text_init(void);
void text_set_rotation90(bool rotated);
void text_set_hires(bool hires);
void text_reset(void);
Gfx *text_begin(Gfx *gdl);
Gfx *text_end(Gfx *gdl);
Gfx *text_begin_boxmode(Gfx *gdl, u32 colour);
Gfx *text_end_boxmode(Gfx *gdl);
Gfx *text_draw_black_box(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2);
Gfx *text_draw_black_uibox(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2);
Gfx *text_draw_black_textbox(Gfx *gdl, s32 left, s32 top, s32 width, s32 height);
Gfx *text_draw_box(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour);
Gfx *text_enable_holo_ray(Gfx *gdl);
void text_disable_holo_ray(void);
void text_set_diagonal_blend(s32 x, s32 y, f32 redrawtimer, u8 populated);
void text_backup_diagonal_blend_settings(void);
void text_restore_diagonal_blend_settings(void);
void text_set_horizontal_blend(s32 x1, s32 x2, u32 arg2);
void text_backup_and_reset_blends(void);
void text_restore_blends(void);
void text_set_wave_blend(s32 arg0, s32 arg1, s32 cthresh);
void text_set_menu_blend(f32 arg0);
void text_set_wave_colours(u32 colour1, u32 colour2);
void text_reset_blends(void);
bool text_has_diagonal_blend(void);
u32 text_apply_projection_colour(s32 x, s32 y, u32 colour);
u32 text_get_colour_at_pos(s32 x, s32 y, u32 colour);
Gfx *text_render_credits(Gfx *gdl, f32 x, f32 y, f32 widthscale, f32 heightscale, char *text, struct fontchar *chars, struct font *font, u32 colour, s32 hdir, s32 vdir);
void text_set_shadow_enabled(bool enabled);
void text_set_shadow_colour(u32 colour);
Gfx *text_render_v2(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *chars, struct font *font, u32 textcolour, s32 width, s32 height, s32 shadowoffset, s32 lineheight);
Gfx *text_render_v1(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *font1, struct font *font2, u32 textcolour, u32 shadowcolour, s32 width, s32 height, s32 shadowoffset, s32 lineheight);
void text_measure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight);
void text_wrap(s32 width, char *in, char *out, struct fontchar *font1, struct font *font2);

#if VERSION == VERSION_JPN_FINAL
Gfx *text_render_vx(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *font1, struct font *font2, u32 textcolour, u32 shadowcolour, s32 width, s32 height, s32 shadowoffset, s32 lineheight);
#else
#define text_render_vx text_render_v1
#endif

#endif
