#ifndef IN_GAME_ACTIVEMENU_ACTIVEMENU_H
#define IN_GAME_ACTIVEMENU_ACTIVEMENU_H
#include <ultra64.h>
#include "types.h"

void amOpenPickTarget(void);
s32 menudialog000fcd48(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 amPickTargetMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
void amSetAiBuddyTemperament(bool aggressive);
void amSetAiBuddyStealth(void);
s32 amGetFirstBuddyIndex(void);
void amApply(s32 slot);
void amGetSlotDetails(s32 slot, u32 *flags, char *label);
void amInit(void);
s16 amCalculateSlotWidth(void);
void amChangeScreen(s32 step);
void amAssignWeaponSlots(void);
void amOpen(void);
void amClose(void);
bool amIsCramped(void);
void amCalculateSlotPosition(s16 column, s16 row, s16 *x, s16 *y);
Gfx *amRenderText(Gfx *gdl, char *text, u32 colour, s16 left, s16 top);
Gfx *amRenderAibotInfo(Gfx *gdl, s32 buddynum);
Gfx *amRenderSlot(Gfx *gdl, char *text, s16 x, s16 y, s32 mode, s32 flags);
Gfx *amRender(Gfx *gdl);

#endif
