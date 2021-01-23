#ifndef IN_GAME_GAME_0B0FD0_H
#define IN_GAME_GAME_0B0FD0_H
#include <ultra64.h>
#include "types.h"

struct weapon *weaponFindById(s32 itemid);
struct weaponfunc *weaponGetFunctionById(u32 weaponnum, u32 which);
struct weaponfunc *handGetWeaponFunction2(struct hand *hand);
struct weaponfunc *handGetWeaponFunction(struct hand *hand);
struct weaponfunc *weaponGetFunction(u8 *arg0, s32 which);
struct weaponfunc *currentPlayerGetWeaponFunction(u32 hand);
struct inventory_typee *func0f0b11bc(struct hand *hand);
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
u16 weaponGetModelNum2(s32 weaponnum);
void handPopulateFromCurrentPlayer(s32 handnum, struct hand *hand);
struct inventory_ammo *handGetAmmoDefinition(struct hand *hand);
u8 handGetSingleUnk3c(struct hand *hand);
f32 handGetSingleUnk34(struct hand *hand);
f32 handGetDamage(struct hand *hand);
u8 handGetSingleUnk38(struct hand *hand);
u16 handGetSingleShootSound(struct hand *hand);
bool handHasFunctionFlags(struct hand *hand, u32 flags);
s8 weaponGetMaxFireRatePerTick(u32 weaponnum, u32 funcindex);
u32 currentPlayerGetSight(void);
u32 func0f0b201c(void);
u32 *handGetPriToSecAnim(struct hand *hand);
u32 *handGetSecToPriAnim(struct hand *hand);

#endif
