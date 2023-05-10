#ifndef IN_GAME_BONDMOVE_H
#define IN_GAME_BONDMOVE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bmoveSetControlDef(u32 controldef);
void bmoveSetAutoMoveCentreEnabled(bool enabled);
void bmoveSetAutoAim(bool enabled);
bool bmoveIsAutoAimEnabledForCurrentWeapon(void);
void bmoveUpdateAutoAimProp(struct prop *prop, f32 x, f32 y);
struct prop *bmoveGetHoverbike(void);
struct prop *bmoveGetGrabbedProp(void);
void bmoveGrabProp(struct prop *prop);
void bmoveSetMode(u32 movemode);
void bmoveSetModeForAllPlayers(u32 movemode);
void bmoveFindEnteredRoomsByPos(struct player *player, struct coord *arg1, s16 *rooms);
void bmoveUpdateRooms(struct player *player);
void bmove0f0cb904(struct coord *coord);
void bmove0f0cba88(f32 *a, f32 *b, struct coord *c, f32 mult1, f32 mult2);
void bmoveUpdateMoveInitSpeed(struct coord *newpos);
void bmoveTick(bool allowc1x, bool allowc1y, bool allowc1buttons, bool ignorec2);
void bmoveUpdateVerta(void);
void bmove0f0cc19c(struct coord *arg);
void bmoveUpdateHead(f32 arg0, f32 arg1, f32 arg2, Mtxf *arg3, f32 arg4);
void bmove0f0cc654(f32 arg0, f32 arg1, f32 arg2);
s32 bmoveGetCrouchPos(void);
s32 bmoveGetCrouchPosByPlayer(s32 playernum);

#endif
