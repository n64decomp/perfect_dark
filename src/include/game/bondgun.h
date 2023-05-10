#ifndef _IN_GAME_BONDGUN_H
#define _IN_GAME_BONDGUN_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct ammotype g_AmmoTypes[];

void bgunReset(void);

void bgunStop(void);

void bgunPreload(void);
s32 bgunGetMinClipQty(s32 weaponnum, s32 funcnum);
s32 bgunTickIncState2(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
void bgunInitHandAnims(void);
void bgunCalculateBlend(s32 hand);
void bgun0f09d8dc(f32 breathing, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
u32 bgunCalculateGunMemCapacity(void);
bool bgun0f09e004(s32 newowner);
void bgunTickGunLoad(void);
bool bgun0f09eae4(void);
void bgun0f09ebcc(struct defaultobj *obj, struct coord *coord, s16 *rooms, Mtxf *matrix1, struct coord *velocity, Mtxf *matrix2, struct prop *prop, struct coord *pos);
struct defaultobj *bgunCreateThrownProjectile2(struct chrdata *chr, struct gset *gset, struct coord *pos, s16 *rooms, Mtxf *arg4, struct coord *velocity);
void bgunCreateThrownProjectile(s32 handnum, struct gset *gset);
void bgunCreateFiredProjectile(s32 handnum);
void bgunSwivel(f32 autoaimx, f32 autoaimy, f32 crossdamp, f32 aimdamp);
void bgunSwivelWithDamp(f32 screenx, f32 screeny, f32 damp);
void bgunSwivelWithoutDamp(f32 arg0, f32 arg1);
void bgunGetCrossPos(f32 *x, f32 *y);
void bgun0f0a0c08(struct coord *arg0, struct coord *arg1);
void bgunCalculatePlayerShotSpread(struct coord *arg0, struct coord *arg1, s32 handnum, bool dorandom);
void bgunCalculateBotShotSpread(struct coord *arg0, s32 weaponnum, s32 funcnum, bool arg3, s32 crouchpos, bool dual);
void bgunSetLastShootInfo(struct coord *pos, struct coord *dir, s32 handnum);
s32 bgunGetShotsToTake(s32 handnum);
void bgunEquipWeapon(s32 weaponnum);
s32 bgunGetWeaponNum(s32 handnum);
bool bgun0f0a1a10(s32 weaponnum);
void bgunCycleForward(void);
void bgunCycleBack(void);
bool bgunHasAmmoForWeapon(s32 weaponnum);
void bgunEquipWeapon2(s32 handnum, s32 weaponnum);
char *bgunGetName(s32 weaponnum);
char *bgunGetShortName(s32 arg0);
void bgunReloadIfPossible(s32 handnum);
void bgunSetAdjustPos(f32 angle);
bool bgun0f0a27c8(void);
void bgunHandlePlayerDead(void);
bool bgunIsMissionCritical(s32 weaponnum);
void bgunDisarm(struct prop *attacker);
void bgunStartDetonateAnimation(s32 playernum);
void bgunTickGameplay2(void);
s32 bgunAllocateFireslot(void);
void bgunRender(Gfx **gdl);
void bgunPlayPropHitSound(struct gset *gset, struct prop *prop, s32 texturenum);
void bgunPlayGlassHitSound(struct coord *pos, s16 *rooms, s32 texturenum);
void bgunPlayBgHitSound(struct gset *gset, struct coord *hitpos, s32 texturenum, s16 *arg3);
s32 bgunConsiderToggleGunFunction(s32 usedowntime, bool trigpressed, bool fromactivemenu);
void bgun0f0a8c50(void);
void bgunTickGameplay(bool triggeron);
void bgunSetPassiveMode(bool enable);
void bgunSetHitPos(struct coord *coord);
void bgun0f0a9494(u32 operation);
void bgun0f0a94d0(u32 operation, struct coord *pos, struct coord *rot);
void bgunSetGunAmmoVisible(u32 reason, bool enable);
void bgunSetAmmoQuantity(s32 ammotype, s32 quantity);
s32 bgunGetReservedAmmoCount(s32 type);
s32 bgunGetAmmoCount(s32 ammotype);
void bgunGiveMaxAmmo(bool force);
u32 bgunGetAmmoTypeForWeapon(u32 weaponnum, u32 func);
s32 bgunGetAmmoQtyForWeapon(u32 weaponnum, u32 func);
void bgunSetAmmoQtyForWeapon(u32 weaponnum, u32 func, u32 quantity);
s32 bgunGetAmmoCapacityForWeapon(s32 weaponnum, s32 func);
Gfx *bgunDrawHudString(Gfx *gdl, char *text, s32 x, bool halign, s32 y, s32 valign, u32 colour);
Gfx *bgunDrawHudInteger(Gfx *gdl, s32 value, s32 x, bool halign, s32 y, s32 valign, u32 colour);
Gfx *bgunDrawHud(Gfx *gdl);
void bgunApplyBoost(void);
void bgunRevertBoost(void);
void bgunTickBoost(void);
void bgunSetSightVisible(u32 bits, bool visible);
Gfx *bgunDrawSight(Gfx *gdl);
s32 bgunGetWeaponNum2(s32 handnum);
void bgunFreeFireslotWrapper(s32 fireslot);
void bgunFreeFireslot(s32 fireslot);

static inline s32 bgunGetCapacityByAmmotype(s32 ammotype)
{
	return g_AmmoTypes[ammotype].capacity;
}

#endif
