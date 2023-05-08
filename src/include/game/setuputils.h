#ifndef IN_GAME_SETUPUTILS_H
#define IN_GAME_SETUPUTILS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 setupGetCmdLength(u32 *cmd);
u32 *setupGetCmdByIndex(s32 cmdindex);
s32 setupGetCmdIndexByTag(struct tag *tag);
u32 setupGetCmdIndexByProp(struct prop *prop);
bool setupLoadModeldef(s32 modelnum);
bool setup0f092304(struct defaultobj *obj, struct coord *arg1, struct coord *arg2);
void setup0f09233c(struct defaultobj *obj, struct coord *pos, f32 realrot[3][3], s16 *rooms);
void setup0f0923d4(struct defaultobj *obj);
struct defaultobj *setupGetObjByCmdIndex(u32 cmdindex);
struct defaultobj *setupFindObjForReuse(s32 type, struct defaultobj **arg1, struct defaultobj **arg2, bool musthaveprop, bool musthavemodel, struct modelfiledata *filedata);

#endif
