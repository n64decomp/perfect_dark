#ifndef IN_GAME_BONDEYESPY_H
#define IN_GAME_BONDEYESPY_H
#include <ultra64.h>
#include "types.h"

f32 eyespyFindGround(s16 *floorroom);
s32 eyespyCalculateNewY(f32 yvel);
s32 eyespyCalculateNewPosition(struct coord *vel);
bool func0f0cf728(struct coord *vel);
s32 func0f0cf890(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
s32 func0f0cf9f8(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 func0f0cfafc(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 func0f0cfdd0(struct coord *vel, struct coord *arg1, struct coord *arg2);
void eyespyCalculateVerticalMovement(void);
bool eyespyTryLaunch(void);
void func0f0d0928(bool arg0);

#endif
