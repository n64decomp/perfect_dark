#ifndef IN_GAME_BOTINV_H
#define IN_GAME_BOTINV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void botinvClear(struct chrdata *chr);
struct invitem *botinvGetItem(struct chrdata *chr, s32 weaponnum);
void botinvRemoveItem(struct chrdata *chr, s32 weaponnum);
u32 botinvGetItemType(struct chrdata *chr, u32 weaponnum);
bool botinvGiveSingleWeapon(struct chrdata *chr, u32 weaponnum);
void botinvGiveDualWeapon(struct chrdata *chr, u32 weaponnum);
s16 botinvGetWeaponPad(struct chrdata *chr, u32 weaponnum);
bool botinvGiveProp(struct chrdata *chr, struct prop *prop);
void botinvScoreAllWeapons(struct chrdata *chr, s32 *weaponnums, s32 *scores1, s32 *scores2);
bool mpHasShield(void);
s32 mpGetWeaponSlotByWeaponNum(s32 weaponnum);
void botinvScoreWeapon(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 arg3, bool arg4, s32 *dst1, s32 *dst2, bool arg7, bool arg8);
s32 botinvGetDistConfig(s32 weaponnum, s32 funcnum);
bool botinvAllowsWeapon(struct chrdata *chr, s32 weaponnum, s32 funcnum);
void botinvTick(struct chrdata *chr);
bool botinvSwitchToWeapon(struct chrdata *chr, s32 weaponnum, s32 funcnum);
void botinvDropAll(struct chrdata *chr, u32 weaponnum);
void botinvDropOne(struct chrdata *chr, u32 weaponnum);

#endif
