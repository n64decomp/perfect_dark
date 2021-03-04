#ifndef IN_GAME_INVENTORY_INVENTORY_H
#define IN_GAME_INVENTORY_INVENTORY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void invClear(void);
void invSortItem(struct invitem *item);
void invInsertItem(struct invitem *item);
void invRemoveItem(struct invitem *item);
struct invitem *invFindUnusedSlot(void);
void invSetAllGuns(bool enable);
struct invitem *invFindSingleWeapon(s32 weaponnum);
bool invHasSingleWeaponExcAllGuns(s32 weaponnum);
struct invitem *invFindDoubleWeapon(s32 weapon1, s32 weapon2);
bool invHasDoubleWeaponExcAllGuns(s32 weapon1, s32 weapon2);
bool invHasSingleWeaponOrProp(s32 weaponnum);
s32 invAddOneIfCantHaveSlayer(s32 arg0);
s32 currentStageForbidsSlayer(void);
bool invCanHaveAllGunsWeapon(s32 weaponnum);
bool invHasSingleWeaponIncAllGuns(s32 weaponnum);
bool invHasDoubleWeaponIncAllGuns(s32 weapon1, s32 weapon2);
bool invGiveSingleWeapon(s32 weaponnum);
bool invGiveDoubleWeapon(s32 weapon1, s32 weapon2);
void invRemoveItemByNum(s32 weaponnum);
bool invGiveProp(struct prop *prop);
void invRemoveProp(struct prop *prop);
s32 invGiveWeaponsByProp(struct prop *prop);
void func0f1122ec(s32 *weaponnum1, s32 *weaponnum2, s32 arg2);
void func0f11253c(s32 *weaponnum1, s32 *weaponnum2, s32 arg2);
bool invHasKeyFlags(u32 wantkeyflags);
bool invHasBriefcase(void);
bool invHasDataUplink(void);
bool invHasProp(struct prop *prop);
s32 invGetCount(void);
struct invitem *invGetItemByIndex(s32 index);
struct textoverride *invGetTextOverrideForObj(struct defaultobj *obj);
struct textoverride *invGetTextOverrideForWeapon(s32 weaponnum);
s32 invGetWeaponNumByIndex(s32 index);
u16 invGetNameIdByIndex(s32 index);
char *invGetNameByIndex(s32 index);
char *invGetShortNameByIndex(s32 index);
void invInsertTextOverride(struct textoverride *override);
u32 invGetCurrentIndex(void);
void invSetCurrentIndex(u32 item);
void invCalculateCurrentIndex(void);
char *invGetActivatedTextByObj(struct defaultobj *obj);
char *invGetActivatedTextByWeaponNum(s32 weaponnum);
void invIncrementHeldTime(s32 param_1, s32 param_2);
void invGetWeaponOfChoice(s32 *weapon1, s32 *weapon2);

#endif
