#ifndef IN_GAME_TRAINING_TRAINING_H
#define IN_GAME_TRAINING_TRAINING_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u8 g_FrIsValidWeapon;
extern s32 g_FrWeaponNum;
extern u8 g_ChrBioSlot;
extern u8 var80088bb4;
extern u8 g_HangarBioSlot;
extern u8 g_DtSlot;

bool ciIsTourDone(void);
u8 ciGetFiringRangeScore(s32 weaponindex);
u8 frIsWeaponFound(s32 weapon);
void frSetWeaponFound(s32 weaponnum);
bool func0f19cbcc(s32 weapon);
u32 frGetWeaponIndexByWeapon(u32 weaponnum);
s32 frIsClassicWeaponUnlocked(u32 weapon);
s32 frGetSlot(void);
void frSetSlot(s32 slot);
u32 frGetWeaponBySlot(s32 slot);
s32 frGetNumWeaponsAvailable(void);
void frReset(void);
void frSetDifficulty(s32 difficulty);
u32 frGetDifficulty(void);
struct frdata *frGetData(void);
void frLoadData(void);
u32 frInitAmmo(s32 weapon);
void frBeginSession(s32 weapon);
char *frGetWeaponDescription(void);
void frEndSession(bool hidetargets);
bool frIsTargetOneHitExplodable(struct prop *prop);
bool frIsTargetFacingPos(struct prop *prop, struct coord *pos);
struct prop *frChooseAutogunTarget(struct coord *autogunpos);
void frTick(void);
void func0f1a0924(struct prop *prop);
bool frChooseFarsightTarget(void);
s32 frIsInTraining(void);
void frCalculateHit(struct defaultobj *obj, struct coord *hitpos, f32 maulercharge);
void frIncrementNumShots(void);
struct chrbio *ciGetChrBioByBodynum(u32 bodynum);
char *ciGetChrBioDescription(void);
s32 ciGetNumUnlockedChrBios(void);
s32 ciGetChrBioBodynumBySlot(s32 slot);
struct miscbio *ciGetMiscBio(s32 index);
s32 ciGetNumUnlockedMiscBios(void);
s32 ciGetMiscBioIndexBySlot(s32 slot);
char *ciGetMiscBioDescription(void);
struct hangarbio *ciGetHangarBio(s32 index);
s32 ciGetNumUnlockedLocationBios(void);
s32 ciGetNumUnlockedHangarBios(void);
s32 ciGetHangarBioIndexBySlot(s32 slot);
char *ciGetHangarBioDescription(void);
struct trainingdata *dtGetData(void);
void dtPushEndscreen(void);
void dtTick(void);
void func0f1a1ac0(void);
void dtBegin(void);
void dtEnd(void);
s32 dtGetNumAvailable(void);
s32 dtGetIndexBySlot(s32 wantindex);
u32 dtGetWeaponByDeviceIndex(s32 deviceindex);
char *dtGetDescription(void);
char *dtGetTip1(void);
char *dtGetTip2(void);
struct trainingdata *getHoloTrainingData(void);
void htPushEndscreen(void);
void htTick(void);
void func0f1a2198(void);
void htBegin(void);
void htEnd(void);
s32 htGetNumUnlocked(void);
s32 htGetIndexBySlot(s32 slot);
char *htGetName(s32 index);
char *htGetDescription(void);
char *htGetTip1(void);
char *htGetTip2(void);
Gfx *frRenderHud(Gfx *gdl);

#endif
