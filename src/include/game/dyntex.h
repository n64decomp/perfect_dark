#ifndef _IN_GAME_DYNTEX_H
#define _IN_GAME_DYNTEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern s32 g_DyntexCurRoom;

void dyntexTickRoom(s32 roomnum, struct gfxvtx *vertices);
void dyntexAddVertex(struct gfxvtx *vertex);
void dyntexSetCurrentType(s16 type);
void dyntexSetCurrentRoom(s16 roomnum);
void dyntexReset(void);
bool dyntexHasRoom(void);

#endif
