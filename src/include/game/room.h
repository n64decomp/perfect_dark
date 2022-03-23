#ifndef _IN_GAME_ROOM_H
#define _IN_GAME_ROOM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void roomsReset(void);

void roomsTick(void);

void roomSetLastForOffset(s32 room);
void room0f1668f0(s32 index, s32 roomnum);
void room0f16692c(s32 index, s32 roomnum);
void room0f16696c(s32 index);
s32 room0f1669fc(void);
void room0f166a6c(Mtxf *matrix, s32 roomnum);
s32 room0f166c20(s32 roomnum);
Gfx *room0f166d7c(Gfx *gdl, s32 roomnum);
struct coord *room0f166dd0(s32 room);
void room0f166df0(s32 room, struct coord *globaldrawworldoffset);

#endif
