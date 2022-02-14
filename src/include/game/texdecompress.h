#ifndef IN_GAME_TEXDECOMPRESS_H
#define IN_GAME_TEXDECOMPRESS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f16e810(u32 arg0);
s32 texLoadZlib(u8 *ptr, u32 *texturenum, s32 arg2, s32 lod, struct texturething *arg4, s32 arg5);
u32 func0f16edac(void);
u32 func0f16ee58(void);
u32 func0f16eefc(void);
u32 func0f16efa0(void);
u32 func0f16f044(void);
u32 func0f16f0f4(void);
u32 func0f16fc8c(void);
s32 func0f16fd50(u16 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 texLoadNonZlib(u8 *ptr, u32 *texturenum, s32 arg2, s32 lod, struct texturething *arg4, s32 arg5);
u32 func0f1706ec(void);
u32 func0f1711b4(void);
u32 func0f171558(void);
u32 func0f171724(void);
s32 func0f171828(s32 arg0);
void func0f17184c(u8 *arg0, s32 arg1);
u32 func0f1718a0(void);
u32 func0f171ba8(void);
u32 func0f17218c(void);
u32 func0f172554(void);
u32 func0f1729f8(void);
u32 func0f172b5c(void);
void func0f172e70(s32 *arg0, void *arg1, s32 arg2);
struct texloadthing *func0f172e8c(s32 texturenum, struct texturething *arg1);
s32 func0f172f44(struct texturething *arg0);
s32 func0f172f54(s32 *arg0);
void texLoadFromDisplayList(Gfx *gdl, struct texturething *arg1, s32 arg2);
void texLoad(u32 *texturenum, struct texturething *arg1, s32 arg2);
void texLoadFromConfigs(struct textureconfig *configs, s32 numconfigs, struct texturething *arg2, s32 arg3);
void texLoadFromTextureNum(u32 arg0, struct texturething *arg1);
void func0f173520(u8 *arg0);
s32 func0f17353c(s32 arg0);
void texturesLoadConfigs(void);

#endif
