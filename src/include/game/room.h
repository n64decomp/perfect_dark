#ifndef _IN_GAME_ROOM_H
#define _IN_GAME_ROOM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void roomsReset(void);

void roomSetLastForOffset(s32 room);
void roomLinkMtx(struct roommtx *roommtx, s32 roomnum);
void roomUnlinkMtx(struct roommtx *roommtx, s32 roomnum);
void roomFreeMtx(struct roommtx *roommtx);
struct roommtx *roomAllocateMtx(void);
void roomPopulateMtx(Mtxf *matrix, s32 roomnum);
struct roommtx *roomTouchMtx(s32 roomnum);
Gfx *roomApplyMtx(Gfx *gdl, s32 roomnum);
struct coord *roomGetPosPtr(s32 room);
void roomGetPos(s32 room, struct coord *globaldrawworldoffset);

#endif
