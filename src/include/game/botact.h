#ifndef IN_GAME_BOTACT_H
#define IN_GAME_BOTACT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 botactGetAmmoTypeByFunction(s32 weaponnum, s32 funcnum);
s32 botactGetClipCapacityByFunction(s32 weaponnum, u32 funcnum);
void botactReload(struct chrdata *chr, s32 handnum, bool withsound);
s32 botactGetAmmoQuantityByWeapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, bool include_equipped);
s32 botactGetAmmoQuantityByType(struct aibot *aibot, s32 ammotype, bool include_equipped);
s32 botactTryRemoveAmmoFromReserve(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty);
void botactGiveAmmoByWeapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty);
void botactGiveAmmoByType(struct aibot *aibot, u32 ammotype, s32 quantity);
bool botactShootFarsight(struct chrdata *chr, s32 arg1, struct coord *arg2, struct coord *arg3);
bool botactIsWeaponThrowable(s32 weaponnum, bool is_secondary);
u32 botactGetProjectileThrowInterval(u32 weapon);
s32 botactGetWeaponByAmmoType(s32 ammotype);
void botact0f19a37c(struct chrdata *chr);
s32 botactGetShootInterval60(s32 weaponnum, s32 funcnum);
bool botactFindRocketRoute(struct chrdata *chr, struct coord *frompos, struct coord *topos, s16 *fromrooms, s16 *torooms, struct projectile *projectile);
void botactGetRocketNextStepPos(u16 padnum, struct coord *pos);
void botactCreateSlayerRocket(struct chrdata *chr);

#endif
