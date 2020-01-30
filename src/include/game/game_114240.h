#ifndef IN_GAME_GAME_114240_H
#define IN_GAME_GAME_114240_H
#include <ultra64.h>
#include "types.h"

void waypointSetHashThing(s32 hash1, s32 hash2);
s32 *waypointFindClosestToPos(struct coord *pos, s16 *room);
u32 func0f114810(void);
u32 func0f114958(void);
u32 func0f1149b0(void);
u32 func0f114a2c(void);
u32 func0f114aec(void);
u32 func0f114b7c(void);
u32 func0f114ccc(void);
u32 func0f114d34(void);
u32 func0f114de0(void);
u32 func0f114ee4(void);
u32 func0f114f70(void);
u32 func0f11505c(void);
s32 waypointFindRoute(s32 *from, s32 *to, s32 **dst, s32 maxwaypoints);
u32 func0f115390(void);
u32 func0f1153c4(void);
u32 func0f1154cc(void);
u32 func0f1155e0(void);
u32 func0f115784(void);
u32 func0f11594c(void);
u32 func0f115a48(void);
u32 func0f115a78(void);

#endif
