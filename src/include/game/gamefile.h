#ifndef IN_GAME_GAMEFILE_H
#define IN_GAME_GAMEFILE_H
#include <ultra64.h>
#include "types.h"

u32 savefileHasFlag(u32 value);
void savefileSetFlag(u32 value);
void savefileUnsetFlag(u32 value);
void savefilePrintFlags(void);
void savefileApplyOptions(struct savefile_solo *file);
void savefileLoadDefaults(struct savefile_solo *file);
s32 func0f10fac8(s32 arg0);
s32 func0f10feac(s32 arg0, s32 arg1, u16 arg2);
void savefileGetOverview(char *arg0, char *name, u8 *stage, u8 *difficulty, u32 *time);
bool func0f1106c8(void);
u32 func0f110720(void);
u32 func0f11080c(void);
void func0f1109c0(void);
void func0f110b68(void);
void func0f110bf0(void);
void func0f110bf8(void);
void func0f110c5c(s32 listnum, u8 filetype);
u8 func0f110cf8(u8 arg0);
u32 func0f110d90(void);
void func0f110da8(void);
u32 func0f110f4c(void);
struct var800ab5a8 *func0f111460(s32 playernum, s32 arg1, s32 arg2);

#endif
