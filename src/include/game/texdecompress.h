#ifndef IN_GAME_TEXDECOMPRESS_H
#define IN_GAME_TEXDECOMPRESS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f16e810(u32 arg0);
void texInitPool(struct texpool *pool, u8 *start, s32 len);
struct tex *texFindInPool(s32 texturenum, struct texpool *pool);
u8 *texGetPoolLeftPos(struct texpool *pool);
void texLoadFromDisplayList(Gfx *gdl, struct texpool *pool, s32 arg2);
void texLoad(s32 *updateword, struct texpool *pool, bool arg2);
void texLoadFromConfigs(struct textureconfig *configs, s32 numconfigs, struct texpool *pool, s32 arg3);
void texLoadFromTextureNum(u32 arg0, struct texpool *pool);

#endif
