#ifndef IN_GAME_TEXDECOMPRESS_H
#define IN_GAME_TEXDECOMPRESS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f16e810(u32 arg0);
s32 tex_inflate_zlib(u8 *src, u8 *dst, bool arg2, s32 forcenumimages, struct texpool *pool, s32 unusedarg);
s32 tex_align_indices(u8 *arg0, s32 width, s32 height, s32 format, u8 *dst);
s32 tex_get_average_red(u16 colour1, u16 colour2, u16 colour3, u16 colour4);
s32 tex_get_average_green(u16 colour1, u16 colour2, u16 colour3, u16 colour4);
s32 tex_get_average_blue(u16 colour1, u16 colour2, u16 colour3, u16 colour4);
s32 tex_get_average_alpha(u16 colour1, u16 colour2, u16 colour3, u16 colour4);
s32 tex_shrink_paletted(u8 *src, u8 *dst, s32 srcwidth, s32 srcheight, s32 format, u16 *palette, s32 numcolours);
s32 tex_find_closest_colour_index_r_g_b_a(u8 *palette, s32 numcolours, s32 r, s32 g, s32 b, s32 a);
s32 tex_find_closest_colour_index_i_a(u16 *palette, s32 numcolours, s32 intensity, s32 alpha);
s32 tex_inflate_non_zlib(u8 *src, u8 *dst, s32 arg2, s32 forcenumimages, struct texpool *pool, s32 unusedarg);
s32 tex_shrink_non_paletted(u8 *src, u8 *dst, s32 srcwidth, s32 srcheight, s32 format);
void tex_inflate_huffman(u8 *dst, s32 numiterations, s32 chansize);
void tex_inflate_rle(u8 *arg0, s32 arg1);
s32 tex_build_lookup(u8 *arg0, s32 bpp);
s32 tex_get_bit_size(s32 arg0);
void tex_read_alpha_bits(u8 *dst, s32 count);
s32 tex_read_uncompressed(u8 *dst, s32 width, s32 height, s32 format);
s32 tex_channels_to_pixels(u8 *src, s32 width, s32 height, u8 *dst, s32 format);
s32 tex_inflate_lookup(s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format);
s32 tex_inflate_lookup_from_buffer(u8 *src, s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format);
void tex_swizzle(u8 *arg0, s32 width, s32 height, s32 format);
void tex_blur(u8 *pixels, s32 width, s32 height, s32 method, s32 chansize);
void tex_init_pool(struct texpool *pool, u8 *start, s32 len);
struct tex *tex_find_in_pool(s32 texturenum, struct texpool *pool);
s32 tex_get_pool_free_bytes(struct texpool *pool);
u8 *tex_get_pool_left_pos(struct texpool *pool);
void tex_load_from_display_list(Gfx *gdl, struct texpool *pool, s32 arg2);
void tex_load(s32 *updateword, struct texpool *pool, bool unusedarg);
void tex_load_from_configs(struct textureconfig *configs, s32 numconfigs, struct texpool *pool, s32 arg3);
void tex_load_from_texture_num(u32 arg0, struct texpool *pool);

#endif
