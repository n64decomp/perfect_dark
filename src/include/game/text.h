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
void text0f1531dc(bool arg0);
void text_reset(void);
Gfx *text0f153628(Gfx *gdl);
Gfx *text0f153780(Gfx *gdl);
Gfx *text_set_prim_colour(Gfx *gdl, u32 colour);
Gfx *text0f153838(Gfx *gdl);
Gfx *text0f153858(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2);
Gfx *text0f1538e4(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2);
Gfx *text0f153990(Gfx *gdl, s32 left, s32 top, s32 width, s32 height);
Gfx *text0f153a34(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour);
Gfx *text0f153ab0(Gfx *gdl);
void text0f153b40(void);
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
u32 text0f1543ac(s32 x, s32 y, u32 colour);
Gfx *text0f1552d4(Gfx *gdl, f32 x, f32 y, f32 widthscale, f32 heightscale, char *text, struct fontchar *chars, struct font *font, u32 colour, s32 hdir, s32 vdir);
void text0f156024(s32 arg0);
void text0f156030(u32 colour);
Gfx *text_render_projected(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *chars, struct font *font, s32 colour, s32 width, s32 height, s32 arg9, s32 lineheight);
Gfx *text_render(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *font1, struct font *font2, u32 arg6, u32 colour, s32 width, s32 height, u32 arg10, s32 arg11);
void text_measure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight);
void text_wrap(s32 width, char *in, char *out, struct fontchar *font1, struct font *font2);

Gfx *func0f1574d0jf(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *font1, struct font *font2, s32 colour, u32 colour2, s32 width, s32 height, s32 arg9, u32 arg10);

#endif
