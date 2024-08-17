#ifndef _IN_GAME_DYNTEX_H
#define _IN_GAME_DYNTEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dyntex_tick_room(s32 roomnum, Vtx *vertices);
void dyntex_add_vertex(Vtx *vertex);
void dyntex_set_current_type(s16 type);
void dyntex_set_current_room(RoomNum roomnum);
void dyntex_reset(void);
bool dyntex_has_room(void);

#endif
