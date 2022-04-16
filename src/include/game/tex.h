#ifndef IN_GAME_TEX_H
#define IN_GAME_TEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void texInit(void);

s32 tex0f0b3350(s32 value);
s32 tex0f0b33f8(s32 arg0, s32 arg1, s32 arg2);
u32 tex0f0b3468(void);
u32 tex0f0b34d8(void);
u32 tex0f0b3548(void);
u32 tex0f0b35b8(void);
void tex0f0b3988(struct textureconfig *config);
void tex0f0b39c0(Gfx **gdl, struct textureconfig *arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5, u32 *arg6);

#endif
