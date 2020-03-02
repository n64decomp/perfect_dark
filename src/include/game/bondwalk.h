#ifndef IN_GAME_BONDWALK_H
#define IN_GAME_BONDWALK_H
#include <ultra64.h>
#include "types.h"

void currentPlayerWalkInit(void);
void func0f0c3ad0(s32 value);
void currentPlayerAdjustCrouchPos(s32 value);
u32 func0f0c3b38(void);
u32 func0f0c3c8c(void);
u32 func0f0c3e14(void);
void func0f0c4250(struct coord *delta, f32 arg1, bool arg2, f32 arg3, s32 arg4);
u32 func0f0c4764(void);
u32 func0f0c47d0(void);
u32 func0f0c494c(void);
u32 func0f0c4a5c(void);
void func0f0c4d98(void);
u32 func0f0c4da0(void);
u32 func0f0c4ec4(void);
u32 func0f0c4fd8(void);
void currentPlayerApplyCrouchSpeed(void);
void func0f0c6080(void);
u32 func0f0c6180(void);
u32 func0f0c6318(void);
u32 func0f0c63bc(void);
void currentPlayerUpdatePrevPosWalk(void);
void func0f0c65a8(void);
u32 func0f0c65c8(void);
void currentPlayerApplyCrouchSpeedTheta(void);
u32 func0f0c69b8(void);
void func0f0c785c(void);

#endif
