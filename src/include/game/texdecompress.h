#ifndef IN_GAME_TEXDECOMPRESS_H
#define IN_GAME_TEXDECOMPRESS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void tex_init_pool(struct texpool *pool, u8 *start, s32 len);
struct tex *tex_find_in_pool(s32 texturenum, struct texpool *pool);
u8 *tex_get_pool_left_pos(struct texpool *pool);
void tex_load_from_display_list(Gfx *gdl, struct texpool *pool, s32 arg2);
void tex_load(s32 *updateword, struct texpool *pool, bool unusedarg);
void tex_load_from_configs(struct textureconfig *configs, s32 numconfigs, struct texpool *pool, s32 arg3);
void tex_load_from_texture_num(u32 arg0, struct texpool *pool);

#endif
