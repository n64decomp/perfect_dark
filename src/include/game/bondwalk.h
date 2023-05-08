#ifndef IN_GAME_BONDWALK_H
#define IN_GAME_BONDWALK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bwalkInit(void);
void bwalkAdjustCrouchPos(s32 value);
s32 bwalkTryMoveUpwards(f32 amount);
void bwalk0f0c4d98(void);
void bwalk0f0c63bc(struct coord *arg0, u32 arg1, s32 types);
void bwalkHandleActivate(void);
void bwalkApplyMoveData(struct movedata *data);
void bwalkUpdateSpeedTheta(void);
void bwalkTick(void);

#endif
