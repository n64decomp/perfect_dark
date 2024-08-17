#ifndef IN_GAME_TEX_H
#define IN_GAME_TEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void tex_init(void);

void surface_reset(void);

void tex_set_bitstring(u8 *arg0);
s32 tex_read_bits(s32 arg0);
void tex_reset(void);

s32 tex_get_mask(s32 value);
s32 tex0f0b33f8(s32 width, s32 height, s32 lod);
s32 tex0f0b3468(s32 width, s32 height, s32 lod);
s32 tex0f0b34d8(s32 width, s32 height, s32 lod);
s32 tex0f0b3548(s32 width, s32 height, s32 lod);
void tex_set_render_mode(Gfx **gdlptr, s32 arg1, s32 numcycles, s32 arg3);
void tex_load_from_config(struct textureconfig *config);
void tex_select(Gfx **gdl, struct textureconfig *tconfig, u32 arg2, s32 arg3, u32 ulst, bool arg5, struct texpool *pool);

s32 tex_get_width_at_lod(struct tex *tex, s32 lod);
s32 tex_get_height_at_lod(struct tex *tex, s32 lod);
s32 tex_get_line_size_in_bytes(struct tex *tex, s32 lod);
s32 tex_get_size_in_bytes(struct tex *tex, s32 lod);
void tex_get_depth_and_size(struct tex *tex, s32 *arg1, s32 *arg2);
s32 tex_load_from_gdl(Gfx *instart, s32 gdlsizeinbytes, Gfx *outstart, struct texpool *pool, u8 *vtxstart);
void tex_copy_gdls(Gfx *src, Gfx *dst, s32 numbytes);

#endif
