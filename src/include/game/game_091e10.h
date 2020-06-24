#ifndef IN_GAME_GAME_091e10_H
#define IN_GAME_GAME_091e10_H
#include <ultra64.h>
#include "types.h"

u32 setupGetCommandLength(u32 *cmd);
u32 *setupGetPtrToCommandByIndex(u32 cmdindex);
s32 tagGetCommandIndex(struct tag *tag);
u32 setupGetCommandOffset(struct prop *prop);
bool propLoad(s32 propnum);
bool func0f09220c(struct defaultobj *obj, struct coord *pos, f32 *realrot, u32 arg3, u32 arg4);
bool func0f092304(struct defaultobj *obj, u32 arg1, u32 arg2);
void func0f09233c(struct defaultobj *obj, struct coord *pos, f32 *realrot, s16 *rooms);
void func0f0923d4(struct defaultobj *obj);
struct defaultobj *setupCommandGetObject(u32 cmdindex);
u32 func0f092484(void);

#endif
