#ifndef IN_GAME_EXPLOSIONS_H
#define IN_GAME_EXPLOSIONS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void explosions_reset(void);

void explosions_stop(void);

bool explosion_create_simple(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum);
bool explosion_create_complex(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum);
bool explosion_create(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum, bool makescorch, struct coord *arg6, RoomNum room, struct coord *arg8);
void explosions_update_shake(struct coord *pos, struct coord *look, struct coord *arg2);
u32 explosion_tick(struct prop *prop);
u32 explosion_tick_player(struct prop *prop);
Gfx *explosion_render(struct prop *prop, Gfx *gdl, bool xlupass);

#endif
