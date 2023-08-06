#ifndef IN_GAME_PADHALLLV_H
#define IN_GAME_PADHALLLV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void navSetSeed(u32 upper, u32 lower);
struct waypoint *waypointFindClosestToPos(struct coord *pos, RoomNum *rooms);
struct waygroup *waygroupChooseNeighbour(s32 *groupnums, s32 step, u32 ignoremask);
void waygroupSetStepIfUndiscovered(s32 *groupnums, s32 step, u32 ignoremask);
bool waygroupDiscoverOneStep(struct waygroup *group, s32 step, u32 ignoremask);
bool waygroupDiscoverSteps(struct waygroup *from, struct waygroup *to, struct waygroup *groups, bool discoverall, u32 ignoremask);
bool waygroupFindRoute(struct waygroup *from, struct waygroup *to, struct waygroup *groups);
struct waypoint *waypointChooseNeighbour(s32 *pointnums, s32 step, s32 groupnum, u32 ignoremask);
void waypointSetStepIfUndiscovered(s32 *pointnums, s32 value, s32 groupnum, u32 ignoremask);
bool waypointDiscoverOneStep(s32 *pointnums, s32 step, s32 groupnum, u32 ignoremask);
void waypointDiscoverSteps(struct waypoint *from, struct waypoint *to, bool discoverall, u32 ignoremask);
void waypointFindRoute(struct waypoint *from, struct waypoint *to);
s32 waypointCollectLocal(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen);
void waypointFindSegmentIntoGroup(struct waygroup *fromgroup, struct waygroup *togroup, struct waypoint **frompoint, struct waypoint **topoint);
s32 navFindRoute(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen);
void waypointResetAllSteps(void);
struct waypoint *waypointFindRandomAtStep(s32 *pointnums, s32 step);
struct waygroup *waygroupFindRandomAtStep(s32 *groupnums, s32 step);
struct waypoint *navChooseRetreatPoint(struct waypoint *chrpoint, struct waypoint *targetpoint);
void navDisableSegmentInDirection(struct waypoint *a, struct waypoint *b);
void navEnableSegmentInDirection(struct waypoint *a, struct waypoint *b);
void navDisableSegment(struct waypoint *a, struct waypoint *b);
void navEnableSegment(struct waypoint *a, struct waypoint *b);

#endif
