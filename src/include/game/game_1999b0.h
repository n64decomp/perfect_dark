#ifndef IN_GAME_GAME_1999B0_H
#define IN_GAME_GAME_1999B0_H
#include <ultra64.h>
#include "types.h"

s32 weaponGetAmmoTypeByFunction(s32 weaponnum, u32 funcnum);
s32 weaponGetClipSizeByFunction(s32 weaponnum, u32 funcnum);
void func0f199a40(struct chrdata *chr, u32 index, bool arg2);
s32 func0f199be4(struct aibot *aibot, s32 weaponnum, s32 funcnum, bool include_equipped);
s32 aibotGetAmmoQty(struct aibot *aibot, s32 ammotype, bool include_equipped);
s32 func0f199d70(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty);
void aibotGiveAmmoByWeapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty);
void aibotGiveAmmoByType(struct aibot *aibot, u32 ammotype, s32 quantity);
u32 func0f199f84(void);
bool func0f19a29c(u32 weaponnum, bool is_secondary);
u32 func0f19a2dc(u32 value);
u32 ammotypeGetWeapon(u32 ammotype);
void func0f19a37c(struct chrdata *chr);
s32 func0f19a60c(s32 weaponnum, s32 funcnum);
bool func0f19a6d0(struct chrdata *chr, struct coord *frompos, struct coord *topos, s16 *fromrooms, s16 *torooms, struct obj48 *obj48);
void func0f19a7d0(u16 padnum, struct coord *pos);
void aibotCreateSlayerRocket(struct chrdata *chr);

#endif
