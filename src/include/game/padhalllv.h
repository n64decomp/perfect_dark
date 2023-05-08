#ifndef IN_GAME_PADHALLLV_H
#define IN_GAME_PADHALLLV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void waypointSetHashThing(s32 hash1, s32 hash2);
struct waypoint *waypointFindClosestToPos(struct coord *pos, s16 *rooms);
s32 waypointFindRoute(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen);
struct waypoint *func0f1155e0(struct waypoint *pointa, struct waypoint *pointb);
void waypointDisableSegment(struct waypoint *a, struct waypoint *b);
void waypointEnableSegment(struct waypoint *a, struct waypoint *b);

#endif
