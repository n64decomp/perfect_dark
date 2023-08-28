#ifndef IN_GAME_TEX_H
#define IN_GAME_TEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void texInit(void);

void surfaceReset(void);

void texSetBitstring(u8 *arg0);
s32 texReadBits(s32 arg0);
void texReset(void);

s32 texGetMask(s32 value);
s32 tex0f0b33f8(s32 width, s32 height, s32 lod);
s32 tex0f0b3468(s32 width, s32 height, s32 lod);
s32 tex0f0b34d8(s32 width, s32 height, s32 lod);
s32 tex0f0b3548(s32 width, s32 height, s32 lod);
void texSetRenderMode(Gfx **gdlptr, s32 arg1, s32 numcycles, s32 arg3);
void texLoadFromConfig(struct textureconfig *config);
void texSelect(Gfx **gdl, struct textureconfig *tconfig, u32 arg2, s32 arg3, u32 ulst, bool arg5, struct texpool *pool);

s32 texGetWidthAtLod(struct tex *tex, s32 lod);
s32 texGetHeightAtLod(struct tex *tex, s32 lod);
s32 texGetLineSizeInBytes(struct tex *tex, s32 lod);
s32 texGetSizeInBytes(struct tex *tex, s32 lod);
void texGetDepthAndSize(struct tex *tex, s32 *arg1, s32 *arg2);
s32 texLoadFromGdl(Gfx *instart, s32 gdlsizeinbytes, Gfx *outstart, struct texpool *pool, u8 *vtxstart);
void texCopyGdls(Gfx *src, Gfx *dst, s32 numbytes);

#endif
