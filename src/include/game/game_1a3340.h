#ifndef IN_GAME_GAME_1A3340_H
#define IN_GAME_GAME_1A3340_H
#include <ultra64.h>
#include "types.h"

char *frMenuTextFailReason(struct menu_item *item);
char *frMenuTextDifficultyName(struct menu_item *item);
char *frMenuTextTimeTakenValue(struct menu_item *item);
char *frMenuTextScoreValue(struct menu_item *item);
char *frMenuTextWeaponName(struct menu_item *item);
char *frMenuTextTargetsDestroyedValue(struct menu_item *item);
char *frMenuTextAccuracyValue(struct menu_item *item);
char *frMenuTextGoalScoreLabel(struct menu_item *item);
char *frMenuTextGoalScoreValue(struct menu_item *item);
char *frMenuTextMinAccuracyOrTargetsLabel(struct menu_item *item);
char *frMenuTextMinAccuracyOrTargetsValue(struct menu_item *item);
char *frMenuTextTimeLimitLabel(struct menu_item *item);
char *frMenuTextTimeLimitValue(struct menu_item *item);
char *frMenuTextAmmoLimitLabel(struct menu_item *item);
char *frMenuTextAmmoLimitValue(struct menu_item *item);
char *ciMenuTextBioName(struct menu_item *item);
char *ciMenuTextBioAge(struct menu_item *item);
char *ciMenuTextBioRace(struct menu_item *item);
u32 func0f1a6388(void);
u32 func0f1a64a0(void);
char *dtMenuTextOkOrResume(struct menu_item *item);
char *dtMenuTextCancelOrAbort(struct menu_item *item);
char *dtMenuTextTimeTakenValue(struct menu_item *item);
u32 func0f1a6a04(void);
char *htMenuTextOkOrResume(struct menu_item *item);
char *htMenuTextCancelOrAbort(struct menu_item *item);
char *htMenuTextTimeTakenValue(struct menu_item *item);
u32 func0f1a6c8c(void);
u32 func0f1a6cc4(void);
struct menu_dialog *ciGetFrWeaponListMenuDialog(void);
void func0f1a7560(void *ptr, u16 fileid, u32 arg2, void *arg3, s32 arg4, bool arg5);
void func0f1a7730(void *ptr);
void *func0f1a7794(u16 fileid, u32 arg1, s32 arg2, s32 arg3);
void *fileLoad(u16 fileid);
s32 menudialog001a39a8(u32, u32, u32 *);
s32 menudialog001a3af4(u32, u32, u32 *);
s32 menudialog001a5f48(u32, u32, u32 *);
s32 menudialog001a6548(u32, u32, u32 *);
bool menudialogDeviceTrainingResults(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem);
bool menudialog001a6aa4(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem);
bool menudialogFiringRangeResults(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem);
s32 menudialog001a737c(u32, u32, u32 *);
s32 menuhandler001a3340(u32, u32, u32 *);
s32 menuhandler001a3448(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler001a348c(u32, u32, u32 *);
s32 menuhandler001a44c0(u32, u32, u32 *);
s32 menuhandlerFrFailedContinue(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler001a5dc0(u32, u32, u32 *);
s32 menuhandler001a63e4(u32, u32, u32 *);
s32 menuhandler001a64d8(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler001a6514(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler001a6950(u32, u32, u32 *);
s32 menuhandler001a6a34(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler001a6a70(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler001a6d4c(u32, u32, u32 *);
s32 menuhandler001a6ea4(u32, u32, u32 *);
s32 menuhandlerFrDifficulty(u32, u32, u32 *);

#endif
