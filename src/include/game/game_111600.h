#ifndef IN_GAME_GAME_111600_H
#define IN_GAME_GAME_111600_H
#include <ultra64.h>
#include "types.h"

void currentPlayerClearInventory(void);
void currentPlayerSortInvItem(struct invitem *item);
void currentPlayerInsertInvItem(struct invitem *item);
void currentPlayerRemoveInvItem(struct invitem *item);
struct invitem *currentPlayerGetUnusedInvItem(void);
void currentPlayerSetAllGuns(bool enable);
struct invitem *currentPlayerGetWeaponInvItem(s32 weaponnum);
bool currentPlayerHasWeapon(s32 weaponnum);
struct invitem *func0f111a4c(s32 weapon1, s32 weapon2);
bool func0f111ab0(s32 weapon1, s32 weapon2);
u32 func0f111ad4(void);
u32 func0f111b88(void);
bool currentStageForbidsSlayer(void);
bool currentPlayerCanHaveAllGunsWeapon(s32 weaponnum);
bool currentPlayerCanHaveWeapon(s32 weaponnum);
bool func0f111cf8(s32 weapon1, s32 weapon2);
bool currentPlayerGiveWeapon(s32 weaponnum);
bool currentPlayerGiveWeaponWithArgument(s32 weapon1, s32 weapon2);
void func0f111ea4(u32 arg0);
bool currentPlayerGiveProp(struct prop *prop);
u32 func0f112054(void);
u32 func0f1120f0(void);
u32 func0f1122ec(void);
u32 func0f11253c(void);
u32 func0f112790(void);
bool currentPlayerHasBriefcase(void);
bool currentPlayerHasDataUplink(void);
bool currentPlayerHasProp(struct prop *prop);
u32 func0f112950(void);
u32 func0f112a58(void);
struct textoverride *objGetTextOverride(struct defaultobj *obj);
u32 func0f112bfc(void);
s32 func0f112c44(s32 equipcuritem);
u32 func0f112cf8(void);
u32 func0f112dfc(void);
u32 func0f112e24(void);
u32 func0f112f38(void);
u32 func0f112f50(void);
u32 func0f112f60(void);
void func0f112f70(void);
u32 func0f112fec(void);
u32 func0f113034(void);
u32 func0f11307c(void);
u32 func0f1131ac(void);

#endif
