#ifndef IN_GAME_GAME_110680_H
#define IN_GAME_GAME_110680_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool bossfileLoadFull(void);
u32 func0f110720(void);
void bossfileLoad(void);
void bossfileSave(void);
void bossfileSetDefaults(void);
void func0f110bf0(void);
void func0f110bf8(void);
void func0f110c5c(s32 listnum, u8 filetype);
s32 func0f110cf8(u8 filetype);
void func0f110d90(s32 index);
void filelistsTick(void);
void filelistUpdate(struct filelist *list);
struct textureconfig *func0f111460(s32 playernum, s32 arg1, s32 arg2);

#endif
