#ifndef IN_GAME_ENV_H
#define IN_GAME_ENV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct environment *envGetCurrent(void);
f32 env0f1657e4(void);
void env0f1657f8(void);
void envApplyType1(struct envtype1 *sky);
void envApplyType2(struct envtype2 *sky);
void envSetStageNum(s32 stagenum);
void envChooseAndApply(s32 stagenum, bool allowoverride);
void envApplyTransitionFrac(f32 arg0);
Gfx *envStartFog(Gfx *gdl, bool withalpha);
Gfx *envStopFog(Gfx *gdl);
bool env0f1666f8(struct coord *pos, f32 arg1);
struct coord *env0f1667e8(void);
s32 env0f1667f4(struct prop *prop, f32 *arg1);

#endif
