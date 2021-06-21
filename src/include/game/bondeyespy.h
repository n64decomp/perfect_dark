#ifndef IN_GAME_BONDEYESPY_H
#define IN_GAME_BONDEYESPY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 eyespyFindGround(s16 *floorroom);
s32 eyespyTryMoveUpwards(f32 yvel);
s32 eyespyCalculateNewPosition(struct coord *vel);
bool eyespyCalculateNewPositionWithPush(struct coord *vel);
s32 eyespy0f0cf890(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
s32 eyespy0f0cf9f8(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 eyespy0f0cfafc(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 eyespy0f0cfdd0(struct coord *vel, struct coord *arg1, struct coord *arg2);
void eyespyUpdateVertical(void);
bool eyespyTryLaunch(void);
void eyespyProcessInput(bool allowbuttons);

#endif
