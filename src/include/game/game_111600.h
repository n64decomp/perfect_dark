#ifndef IN_GAME_GAME_111600_H
#define IN_GAME_GAME_111600_H
#include <ultra64.h>
#include "types.h"

void func0f111600(void);
u32 func0f11165c(void);
void func0f11179c(struct invitem *item);
u32 func0f1118cc(void);
struct invitem *currentPlayerCreateInvitem(void);
void currentPlayerSetAllGuns(bool enable);
u32 func0f1119d0(void);
bool func0f111a28(s32 weaponnum);
u32 func0f111a4c(void);
bool func0f111ab0(s32 weapon1, s32 weapon2);
u32 func0f111ad4(void);
u32 func0f111b88(void);
u32 func0f111be8(void);
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
u32 func0f112844(void);
bool func0f112884(void);
u32 currentPlayerHasProp(struct prop *prop);
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
