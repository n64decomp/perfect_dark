#ifndef _IN_GAME_ROOM_H
#define _IN_GAME_ROOM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void roomsReset(void);

void roomsTick(void);

void roomSetLastForOffset(s32 room);
void room0f1668f0(struct roommtx *roommtx, s32 roomnum);
void room0f16692c(struct roommtx *roommtx, s32 roomnum);
void room0f16696c(struct roommtx *roommtx);
struct roommtx *room0f1669fc(void);
void room0f166a6c(Mtxf *matrix, s32 roomnum);
struct roommtx *room0f166c20(s32 roomnum);
Gfx *roomPushMtx(Gfx *gdl, s32 roomnum);
struct coord *roomGetPos(s32 room);
void room0f166df0(s32 room, struct coord *globaldrawworldoffset);

#endif
