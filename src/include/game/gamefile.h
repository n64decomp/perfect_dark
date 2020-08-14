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
u32 func0f10fac8(void);
u32 func0f10feac(void);
u32 func0f1105fc(void);
bool func0f1106c8(void);
u32 func0f110720(void);
u32 func0f11080c(void);
void func0f1109c0(void);
void func0f110b68(void);
void func0f110bf0(void);
void func0f110bf8(void);
void func0f110c5c(s32 locationindex, u8 filetype);
u32 func0f110cf8(void);
u32 func0f110d90(void);
u32 func0f110da8(void);
u32 func0f110f4c(void);
u32 func0f111460(void);

#endif
