#ifndef IN_GAME_BONDEYESPY_H
#define IN_GAME_BONDEYESPY_H
#include <ultra64.h>
#include "types.h"

f32 eyespyFindGround(s16 *floorroom);
u32 func0f0cf230(void);
s32 eyespyCalculateNewPosition(struct coord *vel);
bool func0f0cf728(struct coord *vel);
u32 func0f0cf890(void);
u32 func0f0cf9f8(void);
u32 func0f0cfafc(void);
bool func0f0cfdd0(struct coord *vel, struct coord *arg1, struct coord *arg2);
u32 func0f0cfe24(void);
bool eyespyTryLaunch(void);
void func0f0d0928(bool arg0);

#endif
