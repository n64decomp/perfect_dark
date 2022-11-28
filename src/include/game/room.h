#ifndef _IN_GAME_ROOM_H
#define _IN_GAME_ROOM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void roomsReset(void);

void roomsTick(void);

void roomSetLastForOffset(s32 room);
void roomLinkMtx(s32 index, s32 roomnum);
void roomUnlinkMtx(s32 index, s32 roomnum);
void roomFreeMtx(s32 index);
s32 roomAllocateMtx(void);
void roomPopulateMtx(Mtxf *matrix, s32 roomnum);
s32 roomTouchMtx(s32 roomnum);
Gfx *roomApplyMtx(Gfx *gdl, s32 roomnum);
struct coord *roomGetPosPtr(s32 room);
void roomGetPos(s32 room, struct coord *pos);

#endif
