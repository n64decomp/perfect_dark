#ifndef _IN_GAME_ROOM_H
#define _IN_GAME_ROOM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void roomsReset(void);

void roomPopulateMtx(Mtxf *mtx, s32 roomnum);
Gfx *roomApplyMtx(Gfx *gdl, s32 roomnum);

#endif
