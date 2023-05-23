#ifndef _IN_LIB_LIB_17CE0_H
#define _IN_LIB_LIB_17CE0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

#define PORTALINTERSECTION_NONE          0
#define PORTALINTERSECTION_BEHINDTOFRONT 1
#define PORTALINTERSECTION_FRONTTOBEHIND 2

void portalGetAvgVertexPos(s32 portalnum, struct coord *avg);
void portal00017dc4(s16 *rooms, s16 roomnum);
s32 portalCalculateIntersection(s32 portalnum, struct coord *pos1, struct coord *pos2);
void portal00018148(struct coord *pos, struct coord *pos2, s16 *rooms, s16 *arg3, s16 *arg4, s32 arg5);

#endif
