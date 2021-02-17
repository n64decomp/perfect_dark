#ifndef IN_GAME_BONDGRAB_H
#define IN_GAME_BONDGRAB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bgrabInit(void);
void bgrabExit(void);
void bgrab0f0ccbf0(struct coord *delta, f32 angle);
bool bgrabTryMoveUpwards(f32 y);
s32 bgrabCalculateNewPosition(struct coord *delta, f32 angle, bool arg2);
bool bgrabCalculateNewPositiontWithPush(struct coord *delta, f32 angle, bool arg2);
bool bgrab0f0cdb04(f32 angle, bool arg2);
void bgrab0f0cdb68(f32 angle);
void bgrab0f0cdef0(void);
bool bgrab0f0cdf64(struct coord *delta, struct coord *arg1, struct coord *arg2);
s32 bgrab0f0cdfbc(struct coord *delta, struct coord *arg1, struct coord *arg2);
void bgrab0f0ce0bc(struct coord *arg0);
void bgrabUpdatePrevPos(void);
void bgrab0f0ce178(void);
void bgrabUpdateVertical(void);
void bgrabHandleActivate(void);
void bgrabUpdateSpeedSideways(f32 targetspeed, f32 accelspeed, s32 mult);
void bgrabUpdateSpeedForwards(f32 target, f32 speed);
void bgrabApplyMoveData(struct movedata *data);
void bgrabUpdateSpeedTheta(void);
void bgrab0f0ce924(void);
void bgrabTick(void);

#endif
