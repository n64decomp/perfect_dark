#ifndef IN_GAME_GAME_000130_H
#define IN_GAME_GAME_000130_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f000130(void);
u16 func0f0002a0(s16 animnum, s32 frame, s32 endframe);
s32 func0f000358(s16 animnum, s32 startframe, s32 endframe);
void func0f00040c(struct attackanimconfig *config);
void func0f00052c(struct attackanimgroup **group);
u32 func0f000590(struct animtablerow *row);
f32 func0f0005c0(s16 animnum);
void func0f000648(void);

#endif
