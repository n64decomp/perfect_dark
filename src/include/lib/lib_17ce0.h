#ifndef _IN_LIB_LIB_17CE0_H
#define _IN_LIB_LIB_17CE0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

#define PORTALINTERSECTION_NONE          0
#define PORTALINTERSECTION_BEHINDTOFRONT 1
#define PORTALINTERSECTION_FRONTTOBEHIND 2

void portal_get_centre(s32 portalnum, struct coord *avg);
s32 portal_calculate_intersection(s32 portalnum, struct coord *pos1, struct coord *pos2);
void portal_find_rooms(struct coord *frompos, struct coord *topos, RoomNum *fromrooms, RoomNum *finalrooms, RoomNum *intersecting, s32 maxintersecting);

#endif
