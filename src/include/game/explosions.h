#ifndef IN_GAME_EXPLOSIONS_H
#define IN_GAME_EXPLOSIONS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void explosions_reset(void);

void explosions_stop(void);

bool explosion_create_simple(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum);
bool explosion_create_complex(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum);
f32 explosion_get_horizontal_range_at_frame(struct explosion *exp, s32 frame);
f32 explosion_get_vertical_range_at_frame(struct explosion *exp, s32 frame);
void explosion_get_bbox_at_frame(struct coord *lower, struct coord *upper, s32 frame, struct prop *prop);
void explosion_alert_chrs(f32 *radius, struct coord *noisepos);
bool explosion_create(struct prop *prop, struct coord *pos, RoomNum *rooms, s16 type, s32 playernum, bool makescorch, struct coord *arg6, RoomNum room, struct coord *arg8);
void explosions_update_shake(struct coord *arg0, struct coord *arg1, struct coord *arg2);
bool explosion_overlaps_prop(struct explosion *exp, struct prop *prop, struct coord *pos1, struct coord *pos2);
void explosion_inflict_damage(struct prop *prop);
u32 explosion_tick(struct prop *prop);
u32 explosion_tick_player(struct prop *prop);
Gfx *explosion_render(struct prop *prop, Gfx *gdl, bool xlupass);
Gfx *explosion_render_part(struct explosion *exp, struct explosionpart *part, Gfx *gdl, struct coord *coord, s32 arg4);

#endif
