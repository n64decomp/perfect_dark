#ifndef IN_GAME_BONDWALK_H
#define IN_GAME_BONDWALK_H
#include <ultra64.h>
#include "types.h"

void currentPlayerWalkInit(void);
void func0f0c3ad0(s32 value);
void currentPlayerAdjustCrouchPos(s32 value);
void func0f0c3b38(struct coord *param_1, struct defaultobj *obj);
bool currentPlayerHasGapToCeiling(f32 y);
u32 func0f0c3e14(void);
bool func0f0c4250(struct coord *delta, f32 arg1, bool arg2, f32 arg3, s32 arg4);
bool func0f0c4764(struct coord *delta, struct coord *arg1, struct coord *arg2, s32 arg3);
s32 func0f0c47d0(struct coord *a, struct coord *b, struct coord *c, struct coord *d, struct coord *e, s32 arg6);
u32 func0f0c494c(void);
u32 func0f0c4a5c(void);
void func0f0c4d98(void);
void currentPlayerUpdateSpeedSidewaysWalk(f32 targetspeed, f32 accelspeed, s32 arg2);
void currentPlayerUpdateSpeedForwardsWalk(f32 targetspeed, f32 accelspeed);
void currentPlayerUpdateVerticalMovement(void);
void currentPlayerApplyCrouchSpeed(void);
void currentPlayerUpdateCrouchOffsetWalk(void);
void func0f0c6180(void);
u32 func0f0c6318(void);
u32 func0f0c63bc(void);
void currentPlayerUpdatePrevPosWalk(void);
void func0f0c65a8(void);
u32 func0f0c65c8(void);
void currentPlayerApplyCrouchSpeedTheta(void);
u32 func0f0c69b8(void);
void func0f0c785c(void);

#endif
