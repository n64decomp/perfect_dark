#ifndef _IN_GAME_GUNFX_H
#define _IN_GAME_GUNFX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void boltbeams_reset(void);
void lasersights_reset(void);

void beam_create(struct beam *beam, s32 weaponnum, struct coord *from, struct coord *to);
void beam_create_for_hand(s32 handnum);
Gfx *beam_render(Gfx *gdl, struct beam *beam, bool arg2, u8 texnum);
void beam_tick(struct beam *beam);

void casing_create_for_hand(s32 handnum, f32 ground, Mtxf *mtx);
void casings_render(Gfx **gdlptr);

s32 boltbeam_find_by_prop(struct prop *prop);
s32 boltbeam_create(struct prop *prop);
void boltbeam_set_head_pos(s32 beamnum, struct coord *pos);
void boltbeam_set_tail_pos(s32 beamnum, struct coord *pos);
void boltbeam_increment_head_pos(s32 beamnum, f32 newlength, bool arg2);
void boltbeam_set_automatic(s32 beamnum, f32 speed);
Gfx *boltbeams_render(Gfx *gdl);
void boltbeams_tick(void);

Gfx *lasersight_render_dot(Gfx *gdl);
Gfx *lasersight_render_beam(Gfx *gdl);
void lasersight_set_beam(s32 id, s32 arg1, struct coord *near, struct coord *far);
void lasersight_set_dot(s32 arg0, struct coord *pos, struct coord *rot);
void lasersight_free(s32 arg0);

#endif
