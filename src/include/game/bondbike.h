#ifndef IN_GAME_BONDBIKE_H
#define IN_GAME_BONDBIKE_H
#include <ultra64.h>
#include "types.h"

void currentPlayerBikeInit(void);
void func0f0d2184(void);
void func0f0d2294(void);
void currentPlayerTryBikeDismountAngle(f32 relativeangle, f32 distance);
void currentPlayerDismountBike(void);
void currentPlayerUpdateSpeedBike(struct movedata *data);
void func0f0d2b40(struct defaultobj *bike, struct coord *arg1, f32 arg2);
s32 func0f0d2e18(struct coord *arg0, f32 arg1);
s32 func0f0d3298(struct coord *arg0, f32 arg1);
u32 func0f0d341c(void);
s32 func0f0d363c(f32 arg0);
s32 func0f0d3680(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 func0f0d36d4(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
s32 func0f0d3840(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 func0f0d3940(struct coord *arg0, struct coord *arg1, struct coord *arg2);
void func0f0d3c60(struct coord *arg0);
void func0f0d3d50(void);

#endif
