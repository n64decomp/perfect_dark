#ifndef IN_GAME_BONDBIKE_H
#define IN_GAME_BONDBIKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bbikeInit(void);
void bbikeExit(void);
void bbikeUpdateVehicleOffset(void);
void bbikeTryDismountAngle(f32 relativeangle, f32 distance);
void bbikeHandleActivate(void);
void bbikeApplyMoveData(struct movedata *data);
void bbike0f0d2b40(struct defaultobj *bike, struct coord *arg1, f32 arg2, struct defaultobj *obstacle);
s32 bbikeCalculateNewPosition(struct coord *arg0, f32 arg1);
s32 bbikeCalculateNewPositionWithPush(struct coord *arg0, f32 arg1);
void bbikeUpdateVertical(struct coord *arg0);
s32 bbike0f0d3680(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 bbike0f0d36d4(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
s32 bbike0f0d3840(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 bbike0f0d3940(struct coord *arg0, struct coord *arg1, struct coord *arg2);
void bbike0f0d3c60(struct coord *arg0);
void bbikeTick(void);

#endif
