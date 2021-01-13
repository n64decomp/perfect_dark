#ifndef IN_GAME_BONDWALK_H
#define IN_GAME_BONDWALK_H
#include <ultra64.h>
#include "types.h"

void currentPlayerWalkInit(void);
void currentPlayerSetSwayTarget(s32 value);
void currentPlayerAdjustCrouchPos(s32 value);
void func0f0c3b38(struct coord *param_1, struct defaultobj *obj);
s32 bwalkTryMoveUpwards(f32 amount);
bool bwalkCalculateNewPosition(struct coord *vel, f32 rotateamount, bool apply, f32 extrawidth, s32 arg4);
bool func0f0c4250(struct coord *delta, f32 rotateamount, bool apply, f32 extrawidth, s32 types);
s32 func0f0c4764(struct coord *delta, struct coord *arg1, struct coord *arg2, s32 types);
s32 func0f0c47d0(struct coord *a, struct coord *b, struct coord *c, struct coord *d, struct coord *e, s32 types);
s32 func0f0c494c(struct coord *a, struct coord *b, struct coord *c, s32 types);
s32 func0f0c4a5c(struct coord *a, struct coord *b, struct coord *c, s32 types);
void func0f0c4d98(void);
void currentPlayerUpdateSpeedSidewaysWalk(f32 targetspeed, f32 accelspeed, s32 mult);
void currentPlayerUpdateSpeedForwardsWalk(f32 targetspeed, f32 accelspeed);
void currentPlayerUpdateVerticalMovement(void);
void currentPlayerApplyCrouchSpeed(void);
void currentPlayerUpdateCrouchOffsetWalk(void);
void func0f0c6180(void);
void func0f0c6318(void);
void func0f0c63bc(struct coord *arg0, u32 arg1, s32 types);
void currentPlayerUpdatePrevPosWalk(void);
void func0f0c65a8(void);
void currentPlayerUpdateSpeedWalk(struct movedata *data);
void currentPlayerApplyCrouchSpeedTheta(void);
u32 func0f0c69b8(void);
void func0f0c785c(void);

#endif
