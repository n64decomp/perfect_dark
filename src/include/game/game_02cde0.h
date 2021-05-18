#ifndef _IN_GAME_GAME_02CDE0_H
#define _IN_GAME_GAME_02CDE0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 bodyGetRace(s32 bodynum);
bool bodyLoad(s32 bodynum);
struct model *func0f02ce8c(s32 bodynum, s32 headnum, struct modelfiledata *bodyfiledata, struct modelfiledata *headfiledata, bool sunglasses, struct model *model, bool isplayer, u8 varyheight);
struct model *func0f02d338(s32 bodynum, s32 headnum, struct modelfiledata *bodyfiledata, struct modelfiledata *headfiledata, bool sunglasses, u8 varyheight);
struct model *modelAllocateChr(s32 bodynum, s32 headnum, u32 spawnflags);
s32 func0f02d3f8(void);
s32 bodyChooseHead(s32 bodynum);
void chrUnpack(s32 stagenum, struct packedchr *packed, s32 cmdindex);
struct prop *propAllocateEyespy(struct pad *pad, s16 room);
void bodyCalculateHeadOffset(struct modelfiledata *headfiledata, s32 headnum, s32 bodynum);

#endif
