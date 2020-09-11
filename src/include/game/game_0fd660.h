#ifndef IN_GAME_GAME_0FD660_H
#define IN_GAME_GAME_0FD660_H
#include <ultra64.h>
#include "types.h"

void mpOpenPickTarget(void);
void activemenuSetAiBuddyTemperament(bool aggressive);
void activemenuSetAiBuddyStealth(void);
s32 activemenuGetFirstBuddyIndex(void);
void activemenuApply(s32 slot);
void activemenuGetSlotDetails(s32 slot, u32 *flags, char *dst);
void func0f0fe848(void);
s16 activemenuCalculateSlotWidth(void);
void activemenuChangeScreen(s32 step);
u32 func0f0fecd4(void);
void activemenuOpen(void);
void activemenuClose(void);
u32 func0f0ff0bc(void);
u32 func0f0ff274(void);
u32 func0f0ff6f4(void);
u32 func0f0ff7bc(void);
u32 func0f100128(void);
u32 func0f100ad0(void);
s32 menudialog000fcd48(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialogMpPickTarget(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menuhandler000fcc34(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler000fd6f0(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerRepairPak(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerRetrySavePak(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerWarnRepairPak(u32 operation, struct menuitem *item, union handlerdata *data);

#endif
