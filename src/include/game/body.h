#ifndef IN_GAME_BODY_H
#define IN_GAME_BODY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bodiesInit(void);

void bodiesReset(s32 stagenum);

u32 bodyGetRace(s32 bodynum);
bool bodyLoad(s32 bodynum);
struct model *body0f02ce8c(s32 bodynum, s32 headnum, struct modelfiledata *bodyfiledata, struct modelfiledata *headfiledata, bool sunglasses, struct model *model, bool isplayer, u8 varyheight);
struct model *bodyAllocateModel(s32 bodynum, s32 headnum, u32 spawnflags);
s32 bodyChooseHead(s32 bodynum);
void bodyAllocateChr(s32 stagenum, struct packedchr *packed, s32 cmdindex);
struct prop *bodyAllocateEyespy(struct pad *pad, s16 room);
void bodyCalculateHeadOffset(struct modelfiledata *headfiledata, s32 headnum, s32 bodynum);

#endif
