#ifndef IN_GAME_GAME_0FD660_H
#define IN_GAME_GAME_0FD660_H
#include <ultra64.h>
#include "types.h"

void func0f0fd660(void);
u32 func0f0fdd00(void);
u32 func0f0fdd84(void);
s32 activemenuGetFirstBuddyIndex(void);
void activemenuApply(s32 arg0);
void activemenuGetSlotDetails(s32 slot, u32 *flags, char *dst);
u32 func0f0fe848(void);
u32 func0f0fea14(void);
void activemenuChangeScreen(s32 step);
u32 func0f0fecd4(void);
u32 func0f0fef68(void);
void activemenuClose(void);
u32 func0f0ff0bc(void);
u32 func0f0ff274(void);
u32 func0f0ff6f4(void);
u32 func0f0ff7bc(void);
u32 func0f100128(void);
u32 func0f100ad0(void);
s32 menudialog000fcd48(u32, u32, u32 *);
bool menudialogMpPickTarget(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem);
s32 menuhandler000fcc34(u32, u32, u32 *);
s32 menuhandler000fd6f0(u32, u32, u32 *);
s32 menuhandlerRepairPak(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerRetrySavePak(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerWarnRepairPak(u32 operation, struct menu_item *item, s32 *value);

#endif
