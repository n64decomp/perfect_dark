#ifndef IN_GAME_BONDMOVE_H
#define IN_GAME_BONDMOVE_H
#include <ultra64.h>
#include "types.h"

void bmoveSetControlDef(u32 controldef);
void bmoveSetAutoMoveCentreEnabled(bool enabled);
void bmoveSetAutoAimY(bool enabled);
bool bmoveIsAutoAimYEnabled(void);
bool bmoveIsAutoAimYEnabledForCurrentWeapon(void);
bool bmoveIsInSightAimMode(void);
void bmoveUpdateAutoAimYProp(struct prop *prop, f32 autoaimy);
void bmoveSetAutoAimX(bool enabled);
bool bmoveIsAutoAimXEnabled(void);
bool bmoveIsAutoAimXEnabledForCurrentWeapon(void);
void bmoveUpdateAutoAimXProp(struct prop *prop, f32 autoaimx);
struct prop *bmoveGetHoverbike(void);
struct prop *bmoveGetGrabbedProp(void);
void bmoveGrabProp(struct prop *prop);
void bmoveSetMode(u32 movemode);
void bmoveSetModeForAllPlayers(u32 movemode);
void bmoveHandleActivate(void);
void bmoveApplyMoveData(struct movedata *data);
void bmoveUpdateSpeedTheta(void);
f32 bmoveGetSpeedVertaLimit(f32 value);
void bmoveUpdateSpeedVerta(f32 value);
f32 bmoveGetSpeedThetaControlLimit(f32 value);
void bmoveUpdateSpeedThetaControl(f32 value);
s32 bmove0f0c8598(void);
void bmoveResetMoveData(struct movedata *data);
void bmoveProcessInput(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void bmove0f0cb79c(struct player *player, struct coord *arg1, s16 *rooms);
void bmove0f0cb89c(struct player *player, s16 *rooms);
void bmove0f0cb8c4(struct player *player);
void bmove0f0cb904(struct coord *coord);
void bmove0f0cba88(f32 *a, f32 *b, struct coord *c, f32 mult1, f32 mult2);
void bmoveUpdateMoveInitSpeed(struct coord *newpos);
void bmoveTick(bool arg0, bool arg1, bool arg2, bool arg3);
void bmoveUpdateVerta(void);
void bmove0f0cc19c(struct coord *arg);
void bmoveUpdateHead(f32 arg0, f32 arg1, f32 arg2, Mtxf *arg3, f32 arg4);
void bmove0f0cc654(f32 arg0, f32 arg1, f32 arg2);
s32 bmoveGetCrouchPos(void);
s32 bmoveGetCrouchPosByPlayer(s32 playernum);

#endif
