#ifndef IN_GAME_MENUITEM_H
#define IN_GAME_MENUITEM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *menuitemRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitemInit(struct menuitem *item, union menuitemdata *data);
Gfx *menuitemOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data);

#endif
