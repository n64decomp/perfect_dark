#ifndef IN_GAME_GAME_0B0FD0_H
#define IN_GAME_GAME_0B0FD0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct weapon *weaponFindById(s32 itemid);
struct weaponfunc *weaponGetFunctionById(u32 weaponnum, u32 which);
struct weaponfunc *handGetWeaponFunction2(struct shorthand *hand);
struct weaponfunc *handGetWeaponFunction(struct shorthand *hand);
struct weaponfunc *weaponGetFunction(struct shorthand *hand, s32 which);
struct weaponfunc *currentPlayerGetWeaponFunction(u32 hand);
struct inventory_typee *func0f0b11bc(struct shorthand *hand);
struct inventory_ammo *weaponGetAmmoByFunction(u32 weaponnum, u32 funcnum);
f32 handGetXShift(s32 handnum);
f32 func0f0b131c(u32 hand);
f32 currentPlayerGetGunZoomFov(void);
void currentPlayerZoomOut(f32 fovpersec);
void currentPlayerZoomIn(f32 fovpersec);
bool weaponHasFlag(s32 itemid, u32 flag);
bool weaponHasInvEFlag(s32 weaponnum, u32 flag);
bool func0f0b184c(s32 weaponnum, s32 funcnum, bool arg2);
s32 currentPlayerGetDeviceState(s32 weaponnum);
void currentPlayerSetDeviceActive(s32 weaponum, bool active);
u16 weaponGetModelNum(s32 weaponnum);
u16 weaponGetModelNum2(s32 weaponnum);
void handPopulateFromCurrentPlayer(s32 handnum, struct shorthand *hand);
struct inventory_ammo *handGetAmmoDefinition(struct shorthand *hand);
u8 handGetSingleUnk3c(struct shorthand *hand);
f32 handGetSingleUnk34(struct shorthand *hand);
f32 handGetDamage(struct shorthand *hand);
u8 handGetSingleUnk38(struct shorthand *hand);
u16 handGetSingleShootSound(struct shorthand *hand);
bool handHasFunctionFlags(struct shorthand *hand, u32 flags);
s8 weaponGetMaxFireRatePerTick(u32 weaponnum, u32 funcindex);
u32 currentPlayerGetSight(void);
u32 func0f0b201c(void);
u32 *handGetPriToSecAnim(struct shorthand *hand);
u32 *handGetSecToPriAnim(struct shorthand *hand);

#endif
