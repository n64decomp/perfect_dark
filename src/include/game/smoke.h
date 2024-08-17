#ifndef _IN_GAME_SMOKE_H
#define _IN_GAME_SMOKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void smokes_init(void);

void smoke_reset(void);

void smoke_stop(void);

Gfx *smoke_render_part(struct smoke *smoke, struct smokepart *part, Gfx *gdl, struct coord *coord, f32 size);
struct smoke *smoke_create(struct coord *pos, RoomNum *rooms, s16 type);
bool smoke_create_for_hand(struct coord *pos, RoomNum *rooms, s16 type, s32 handnum);
bool smoke_create_with_source(void *source, struct coord *pos, RoomNum *rooms, s16 type, bool srcispadeffect);
void smoke_create_at_prop(struct prop *prop, s16 type);
void smoke_create_at_pad_effect(struct padeffectobj *effect, struct coord *pos, RoomNum *rooms, s16 type);
void smoke_clear_for_prop(struct prop *prop);
struct smoke *smoke_create_simple(struct coord *pos, RoomNum *rooms, s16 type);
u32 smoke_tick(struct prop *prop);
u32 smoke_tick_player(struct prop *prop);
Gfx *smoke_render(struct prop *prop, Gfx *gdl, bool xlupass);
void smoke_clear_some_types(void);

#endif
