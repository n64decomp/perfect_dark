#ifndef IN_GAME_ENV_H
#define IN_GAME_ENV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct distfadesettings {
    f32 opaperc;
    f32 xluperc;
    f32 refdist;
};

struct environment *envGetCurrent(void);
f32 envGetSquaredFogMax(void);
void envTick(void);
void envApplyFogEnvironment(struct fogenvironment *sky);
void envApplyNoFogEnvironment(struct nofogenvironment *sky);
void envSetStageNum(s32 stagenum);
void envChooseAndApply(s32 stagenum, bool allowoverride);
void envApplyTransitionFrac(f32 arg0);
Gfx *envStartFog(Gfx *gdl, bool xlupass);
Gfx *envStopFog(Gfx *gdl);
bool envIsPosInFogMaxDistance(struct coord *pos, f32 tolerance);
struct distfadesettings *envGetDistFadeSettings(void);
s32 envGetObjShadeMode(struct prop *prop, f32 arg1[4]);

#endif
