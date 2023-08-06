#ifndef _IN_GAME_DYNTEX_H
#define _IN_GAME_DYNTEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dyntexTickRoom(s32 roomnum, Vtx *vertices);
void dyntexAddVertex(Vtx *vertex);
void dyntexSetCurrentType(s16 type);
void dyntexSetCurrentRoom(RoomNum roomnum);
void dyntexReset(void);
bool dyntexHasRoom(void);

#endif
