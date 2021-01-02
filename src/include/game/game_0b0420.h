#ifndef IN_GAME_GAME_0B0420_H
#define IN_GAME_GAME_0B0420_H
#include <ultra64.h>
#include "types.h"

u32 func0f0b0420(void);
u32 func0f0b046c(void);
u32 func0f0b0520(void);
s32 currentPlayerGetShotCount(u32 type);
void incrementKillCount(void);
void incrementKnockoutCount(void);
void decrementKnockoutCount(void);
u8 getKnockoutCount(void);
u32 getKillCount(void);
u32 func0f0b05a4(void);
s32 currentPlayerGetNumKills(void);
void currentPlayerIncrementDeathCount(void);
u32 func0f0b0818(void);
s32 func0f0b09f4(s32 arg0, s32 playernum);
struct weapon *weaponFindById(s32 itemid);
struct weaponfunc *weaponGetFunctionById(u32 weaponnum, u32 which);
struct weaponfunc *handGetWeaponFunction2(struct hand *hand);
struct weaponfunc *handGetWeaponFunction(struct hand *hand);
struct weaponfunc *weaponGetFunction(u8 *arg0, s32 which);
struct weaponfunc *currentPlayerGetWeaponFunction(u32 hand);
u32 func0f0b11bc(void);
struct inventory_ammo *weaponGetAmmoByFunction(u32 weaponnum, u32 funcnum);
f32 handGetXOffset(u32 arg0);
f32 func0f0b131c(u32 hand);
f32 currentPlayerGetGunZoomFov(void);
void currentPlayerZoomOut(f32 fovpersec);
void currentPlayerZoomIn(f32 fovpersec);
bool weaponHasFlag(s32 itemid, u32 flag);
bool weaponHasInvEFlag(s32 weaponnum, u32 flag);
u32 func0f0b184c(void);
s32 currentPlayerGetDeviceState(s32 weaponnum);
void currentPlayerSetDeviceActive(s32 weaponum, bool active);
u16 weaponGetModelNum(s32 weaponnum);
u32 func0f0b1ad0(void);
u32 func0f0b1af0(void);
struct inventory_ammo *handGetAmmoDefinition(struct hand *hand);
u8 handGetSingleUnk3c(struct hand *hand);
f32 handGetSingleUnk34(struct hand *hand);
f32 func0f0b1d28(u8 *weaponnum);
u8 handGetSingleUnk38(struct hand *hand);
u16 handGetSingleShootSound(struct hand *hand);
bool handHasFunctionFlags(struct hand *hand, u32 flags);
s8 weaponGetMaxFireRatePerTick(u32 weaponnum, u32 funcindex);
u32 currentPlayerGetSight(void);
u32 func0f0b201c(void);
u32 func0f0b20e8(void);
u32 func0f0b2118(void);

#endif
