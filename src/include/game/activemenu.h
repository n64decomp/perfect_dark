#ifndef IN_GAME_ACTIVEMENU_H
#define IN_GAME_ACTIVEMENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void am_tick(void);

void am_open_pick_target(void);
MenuDialogHandlerResult menudialog000fcd48(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult am_pick_target_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
void am_set_ai_buddy_temperament(bool aggressive);
void am_set_ai_buddy_stealth(void);
s32 am_get_first_buddy_index(void);
void am_apply(s32 slot);
void am_get_slot_details(s32 slot, u32 *flags, char *label);
void am_reset(void);
s16 am_calculate_slot_width(void);
void am_change_screen(s32 step);
void am_assign_weapon_slots(void);
void am_open(void);
void am_close(void);
bool am_is_cramped(void);
void am_calculate_slot_position(s16 column, s16 row, s16 *x, s16 *y);
Gfx *am_render_text(Gfx *gdl, char *text, u32 colour, s16 left, s16 top);
Gfx *am_render_aibot_info(Gfx *gdl, s32 buddynum);
Gfx *am_render_slot(Gfx *gdl, char *text, s16 x, s16 y, s32 mode, s32 flags);
Gfx *am_render(Gfx *gdl);

#endif
