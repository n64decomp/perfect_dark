#ifndef IN_GAME_GAME_10CCD0_H
#define IN_GAME_GAME_10CCD0_H
#include <ultra64.h>
#include "types.h"

u32 savefileHasFlag(u32 value);
void savefileSetFlag(u32 value);
void savefileUnsetFlag(u32 value);
u32 func0f10ce74(void);
u32 func0f10cf2c(void);
u32 func0f10d044(void);
u32 func0f10d080(void);
u32 func0f10d0c0(void);
u32 func0f10d100(void);
u32 func0f10d140(void);
u32 func0f10d180(void);
u32 func0f10d1d0(void);
u32 func0f10d2e0(void);
u32 func0f10d4d4(void);
u32 func0f10d588(void);
u32 func0f10d61c(void);
u32 func0f10d678(void);
char *menutextMissionTime(s32 arg0);
u32 func0f10d730(void);
void func0f10d770(void);
void func0f10d910(s32 arg0);
u32 func0f10e3fc(void);
u32 func0f10e468(void);
u32 func0f10e4d8(void);
u32 func0f10e588(void);
u32 func0f10e620(void);
u32 func0f10ecb4(void);
u32 func0f10ee40(void);
u32 func0f10ef10(void);
u32 func0f10f1b0(void);
u32 func0f10f204(void);
u32 func0f10f698(void);
u32 func0f10fac8(void);
u32 func0f10feac(void);
u32 func0f1105fc(void);
u32 func0f1106c8(void);
u32 func0f110720(void);
u32 func0f11080c(void);
u32 func0f1109c0(void);
u32 func0f110b68(void);
void func0f110bf0(void);
u32 func0f110bf8(void);
void func0f110c5c(s32 arg0, s32 arg1);
u32 func0f110cf8(void);
u32 func0f110d90(void);
u32 func0f110da8(void);
u32 func0f110f4c(void);
u32 func0f111460(void);
s32 menudialog0010cd0c(u32, u32, u32 *);
s32 menudialog0010dd28(u32, u32, u32 *);
s32 menudialog0010de58(u32, u32, u32 *);
s32 menuhandlerDeclineMission(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler0010e064(u32, u32, u32 *);
s32 menuhandlerContinueMission(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerReplayLastLevel(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerReplayPreviousMission(u32 operation, struct menu_item *item, s32 *value);

#endif
