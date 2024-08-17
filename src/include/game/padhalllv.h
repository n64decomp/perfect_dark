#ifndef IN_GAME_PADHALLLV_H
#define IN_GAME_PADHALLLV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void nav_set_seed(u32 upper, u32 lower);
struct waypoint *waypoint_find_closest_to_pos(struct coord *pos, RoomNum *rooms);
struct waygroup *waygroup_choose_neighbour(s32 *groupnums, s32 step, u32 ignoremask);
void waygroup_set_step_if_undiscovered(s32 *groupnums, s32 step, u32 ignoremask);
bool waygroup_discover_one_step(struct waygroup *group, s32 step, u32 ignoremask);
bool waygroup_discover_steps(struct waygroup *from, struct waygroup *to, struct waygroup *groups, bool discoverall, u32 ignoremask);
bool waygroup_find_route(struct waygroup *from, struct waygroup *to, struct waygroup *groups);
struct waypoint *waypoint_choose_neighbour(s32 *pointnums, s32 step, s32 groupnum, u32 ignoremask);
void waypoint_set_step_if_undiscovered(s32 *pointnums, s32 value, s32 groupnum, u32 ignoremask);
bool waypoint_discover_one_step(s32 *pointnums, s32 step, s32 groupnum, u32 ignoremask);
void waypoint_discover_steps(struct waypoint *from, struct waypoint *to, bool discoverall, u32 ignoremask);
void waypoint_find_route(struct waypoint *from, struct waypoint *to);
s32 waypoint_collect_local(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen);
void waypoint_find_segment_into_group(struct waygroup *fromgroup, struct waygroup *togroup, struct waypoint **frompoint, struct waypoint **topoint);
s32 nav_find_route(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen);
void waypoint_reset_all_steps(void);
struct waypoint *waypoint_find_random_at_step(s32 *pointnums, s32 step);
struct waygroup *waygroup_find_random_at_step(s32 *groupnums, s32 step);
struct waypoint *nav_choose_retreat_point(struct waypoint *chrpoint, struct waypoint *targetpoint);
void nav_disable_segment_in_direction(struct waypoint *a, struct waypoint *b);
void nav_enable_segment_in_direction(struct waypoint *a, struct waypoint *b);
void nav_disable_segment(struct waypoint *a, struct waypoint *b);
void nav_enable_segment(struct waypoint *a, struct waypoint *b);

#endif
