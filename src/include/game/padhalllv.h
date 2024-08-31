#ifndef IN_GAME_PADHALLLV_H
#define IN_GAME_PADHALLLV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void nav_set_seed(u32 upper, u32 lower);
struct waypoint *waypoint_find_closest_to_pos(struct coord *pos, RoomNum *rooms);
s32 nav_find_route(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen);
struct waypoint *nav_choose_retreat_point(struct waypoint *chrpoint, struct waypoint *targetpoint);
void nav_disable_segment(struct waypoint *a, struct waypoint *b);
void nav_enable_segment(struct waypoint *a, struct waypoint *b);

#endif
