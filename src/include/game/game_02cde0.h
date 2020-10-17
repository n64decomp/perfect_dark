#ifndef _IN_GAME_GAME_02CDE0_H
#define _IN_GAME_GAME_02CDE0_H
#include <ultra64.h>
#include "types.h"

u32 bodyGetRace(s32 bodynum);
bool bodyLoad(u32 bodynum);
u32 func0f02ce8c(void);
struct model *func0f02d338(u32 bodynum, u32 headnum, u32 arg2, u32 arg3, bool arg4, u32 arg5);
struct model *modelAllocateChr(u32 bodynum, u32 headnum, u32 flags);
u32 func0f02d3f8(void);
u32 bodyGetHead(u32 bodynum);
void chrUnpack(s32 stagenum, void *cmddata, s32 cmdindex);
struct prop *propAllocateEyespy(struct pad *pad, s16 room);
u32 func0f02ddbc(void);

#endif
