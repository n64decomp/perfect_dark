#ifndef IN_GAME_PADHALLLV_H
#define IN_GAME_PADHALLLV_H
#include <ultra64.h>
#include "types.h"

void waypointSetHashThing(s32 hash1, s32 hash2);
struct waypoint *waypointFindClosestToPos(struct coord *pos, s16 *rooms);
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
s32 waypointFindRoute(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 maxwaypoints);
u32 func0f115390(void);
u32 func0f1153c4(void);
u32 func0f1154cc(void);
u32 func0f1155e0(void);
u32 func0f115784(void);
u32 func0f11594c(void);
void waypointDisableSegment(struct waypoint *a, struct waypoint *b);
void waypointEnableSegment(struct waypoint *a, struct waypoint *b);

#endif
