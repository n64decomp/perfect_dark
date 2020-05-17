#ifndef IN_GAME_GAME_1999B0_H
#define IN_GAME_GAME_1999B0_H
#include <ultra64.h>
#include "types.h"

s32 func0f1999b0(u32 weaponnum, u32 arg1);
u32 func0f1999f8(void);
u32 func0f199a40(void);
s32 func0f199be4(struct aibot *aibot, u32 weaponnum, u32 arg2, u32 arg3);
u32 func0f199cb8(void);
u32 func0f199d70(void);
void func0f199e3c(struct aibot *aibot, u32 weaponnum, bool proxy, u32 qty);
void aibotGiveAmmo(struct aibot *aibot, u32 ammotype, s32 quantity);
u32 func0f199f84(void);
bool func0f19a29c(u32 value, bool fallback);
u32 func0f19a2dc(u32 value);
u32 ammotypeGetWeapon(u32 ammotype);
u32 func0f19a37c(void);
u32 func0f19a60c(void);
u32 func0f19a6d0(void);
u32 func0f19a7d0(void);
u32 func0f19a850(void);

#endif
