#ifndef IN_GAME_TEX_H
#define IN_GAME_TEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void texInit(void);

void surfaceReset(void);

void texReset(void);

void texLoadFromConfig(struct textureconfig *config);
void texSelect(Gfx **gdl, struct textureconfig *tconfig, u32 arg2, s32 arg3, u32 ulst, bool arg5, struct texpool *pool);

s32 texGetWidthAtLod(struct tex *tex, s32 lod);
s32 texGetHeightAtLod(struct tex *tex, s32 lod);
void tex0f173e50(struct tex *tex, s32 *arg1, s32 *arg2);
s32 texLoadFromGdl(Gfx *arg0, s32 gdlsizeinbytes, Gfx *arg2, struct texpool *pool, u8 *arg4);
void texCopyGdls(Gfx *src, Gfx *dst, s32 numbytes);

#endif
