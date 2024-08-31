#ifndef _IN_GAME_ROOM_H
#define _IN_GAME_ROOM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void rooms_reset(void);

void rooms_tick(void);

void room_set_last_for_offset(s32 room);
void room_free_mtx(s32 index);
void room_populate_mtx(Mtxf *matrix, s32 roomnum);
Gfx *room_apply_mtx(Gfx *gdl, s32 roomnum);
struct coord *room_get_pos_ptr(s32 room);
void room_get_pos(s32 room, struct coord *pos);

#endif
