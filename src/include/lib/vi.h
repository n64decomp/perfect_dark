#ifndef _IN_LIB_VI_H
#define _IN_LIB_VI_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void vi_configure_for_logos(void);
void vi_configure_for_copyright(u16 *fb);
void vi_configure_for_legal(void);
void vi_reset(s32 stagenum);
void vi_black(bool black);
void vi_handle_retrace(void);
void vi_update_mode(void);
void vi_shake(f32 intensity);
void vi_set_mode(s32 mode);
void vi_set_16bit(void);
u16 *vi_get_back_buffer(void);
u16 *vi_get_front_buffer(void);
Vp *vi_get_current_player_viewport(void);
u16 vi_get_persp_scale(void);
Gfx *vi0000ab78(Gfx *gdl);
Gfx *vi0000aca4(Gfx *gdl, f32 znear, f32 zfar);
Gfx *vi0000af00(Gfx *gdl, Vp *vp);
Gfx *vi0000b0e8(Gfx *gdl, f32 fovy, f32 aspect);
Gfx *vi0000b1a8(Gfx *gdl);
Gfx *vi0000b1d0(Gfx *gdl);
Gfx *vi_prepare_zbuf(Gfx *gdl);
Gfx *vi_fill_buffer(Gfx *gdl);
Gfx *vi_render_viewport_edges(Gfx *gdl);
void vi_set_buf_size(s16 width, s16 height);
s16 vi_get_buf_width(void);
s16 vi_get_buf_height(void);
void vi_set_size(s16 width, s16 height);
s16 vi_get_width(void);
s16 vi_get_height(void);
void vi_set_view_size(s16 width, s16 height);
s16 vi_get_view_width(void);
s16 vi_get_view_height(void);
void vi_set_view_position(s16 left, s16 top);
s16 vi_get_view_left(void);
s16 vi_get_view_top(void);
void vi_set_use_z_buf(bool use);
void vi_set_fov_y(f32 fovy);
void vi_set_aspect(f32 aspect);
f32 vi_get_aspect(void);
void vi_set_fov_aspect_and_size(f32 fovy, f32 aspect, s16 width, s16 height);
f32 vi_get_fov_y(void);
void vi_set_z_range(f32 arg0, f32 arg1);
void vi_get_z_range(struct zrange *zrange);
Gfx *vi_set_fill_colour(Gfx *gdl, s32 r, s32 g, s32 b);
void vi_grab_jpg32(void);
void vi_grab_rgb32(void);

#endif
