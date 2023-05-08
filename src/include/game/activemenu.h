#ifndef IN_GAME_ACTIVEMENU_H
#define IN_GAME_ACTIVEMENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void amTick(void);

void amOpenPickTarget(void);
void amApply(s32 slot);
void amGetSlotDetails(s32 slot, u32 *flags, char *label);
void amReset(void);
void amChangeScreen(s32 step);
void amAssignWeaponSlots(void);
void amOpen(void);
void amClose(void);
Gfx *amRender(Gfx *gdl);

#endif
