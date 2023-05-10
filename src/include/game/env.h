#ifndef IN_GAME_ENV_H
#define IN_GAME_ENV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct environment g_Env;
extern f32 var80081050;

void env0f1657f8(void);
void envSetStageNum(s32 stagenum);
void envChooseAndApply(s32 stagenum, bool allowoverride);
void envApplyTransitionFrac(f32 arg0);
Gfx *envStartFog(Gfx *gdl, bool xlupass);
Gfx *envStopFog(Gfx *gdl);
bool env0f1666f8(struct coord *pos, f32 arg1);
s32 env0f1667f4(struct prop *prop, f32 arg1[4]);

#endif
