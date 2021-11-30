#ifndef IN_GAME_GAME_091e10_H
#define IN_GAME_GAME_091e10_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 setupGetCommandLength(u32 *cmd);
u32 *setupGetPtrToCommandByIndex(s32 cmdindex);
s32 tagGetCommandIndex(struct tag *tag);
u32 setupGetCommandIndexByProp(struct prop *prop);
bool modelLoad(s32 propnum);
bool func0f09220c(struct defaultobj *obj, struct coord *pos, f32 realrot[3][3], struct coord *arg3, struct coord *arg4);
bool func0f092304(struct defaultobj *obj, struct coord *arg1, struct coord *arg2);
void func0f09233c(struct defaultobj *obj, struct coord *pos, f32 realrot[3][3], s16 *rooms);
void func0f0923d4(struct defaultobj *obj);
struct defaultobj *setupCommandGetObject(u32 cmdindex);
struct defaultobj *func0f092484(s32 arg0, void *arg1, void *arg2, bool musthaveprop, bool musthavemodel, struct modelfiledata *filedata);

#endif
