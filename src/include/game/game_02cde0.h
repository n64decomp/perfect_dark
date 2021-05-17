#ifndef _IN_GAME_GAME_02CDE0_H
#define _IN_GAME_GAME_02CDE0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 bodyGetRace(s32 bodynum);
bool bodyLoad(s32 bodynum);
struct model *func0f02ce8c(s32 bodynum, s32 headnum, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
struct model *func0f02d338(u32 bodynum, u32 headnum, u32 arg2, u32 arg3, bool arg4, u32 arg5);
struct model *modelAllocateChr(u32 bodynum, u32 headnum, u32 flags);
s32 func0f02d3f8(void);
s32 bodyChooseHead(s32 bodynum);
void chrUnpack(s32 stagenum, struct packedchr *packed, s32 cmdindex);
struct prop *propAllocateEyespy(struct pad *pad, s16 room);
u32 func0f02ddbc(void);

#endif
