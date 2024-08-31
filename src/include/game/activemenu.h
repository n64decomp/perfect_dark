#ifndef IN_GAME_ACTIVEMENU_H
#define IN_GAME_ACTIVEMENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void am_tick(void);

void am_open_pick_target(void);
void am_apply(s32 slot);
void am_get_slot_details(s32 slot, u32 *flags, char *label);
void am_reset(void);
void am_change_screen(s32 step);
void am_assign_weapon_slots(void);
void am_open(void);
void am_close(void);
Gfx *am_render(Gfx *gdl);

#endif
