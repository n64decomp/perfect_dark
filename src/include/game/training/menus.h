#ifndef IN_GAME_TRAINING_MENUS_H
#define IN_GAME_TRAINING_MENUS_H
#include <ultra64.h>
#include "types.h"

char *frMenuTextFailReason(struct menuitem *item);
char *frMenuTextDifficultyName(struct menuitem *item);
char *frMenuTextTimeTakenValue(struct menuitem *item);
char *frMenuTextScoreValue(struct menuitem *item);
char *frMenuTextWeaponName(struct menuitem *item);
char *frMenuTextTargetsDestroyedValue(struct menuitem *item);
char *frMenuTextAccuracyValue(struct menuitem *item);
char *frMenuTextGoalScoreLabel(struct menuitem *item);
char *frMenuTextGoalScoreValue(struct menuitem *item);
char *frMenuTextMinAccuracyOrTargetsLabel(struct menuitem *item);
char *frMenuTextMinAccuracyOrTargetsValue(struct menuitem *item);
char *frMenuTextTimeLimitLabel(struct menuitem *item);
char *frMenuTextTimeLimitValue(struct menuitem *item);
char *frMenuTextAmmoLimitLabel(struct menuitem *item);
char *frMenuTextAmmoLimitValue(struct menuitem *item);
char *ciMenuTextChrBioName(struct menuitem *item);
char *ciMenuTextChrBioAge(struct menuitem *item);
char *ciMenuTextChrBioRace(struct menuitem *item);
char *ciMenuTextMiscBioName(struct menuitem *item);
char *dtMenuTextName(struct menuitem *item);
char *dtMenuTextOkOrResume(struct menuitem *item);
char *dtMenuTextCancelOrAbort(struct menuitem *item);
char *dtMenuTextTimeTakenValue(struct menuitem *item);
char *htMenuTextName(struct menuitem *item);
char *htMenuTextOkOrResume(struct menuitem *item);
char *htMenuTextCancelOrAbort(struct menuitem *item);
char *htMenuTextTimeTakenValue(struct menuitem *item);
char *bioMenuTextName(struct menuitem *item);
char *ciMenuTextHangarBioSubheading(struct menuitem *item);
struct menudialog *ciGetFrWeaponListMenuDialog(void);
s32 frTrainingInfoMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 frTrainingStatsMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 ciCharacterProfileMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 dtTrainingDetailsMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialogDeviceTrainingResults(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialog001a6aa4(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialogFiringRangeResults(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 ciHangarHolographMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 frDetailsOkMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 frAbortMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001a348c(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001a44c0(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerFrFailedContinue(s32 operation, struct menuitem *item, union handlerdata *data);
s32 ciOfficeInformationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 dtDeviceListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerDtOkOrResume(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001a6514(s32 operation, struct menuitem *item, union handlerdata *data);
s32 htHoloListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001a6a34(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001a6a70(s32 operation, struct menuitem *item, union handlerdata *data);
s32 ciHangarInformationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001a6ea4(s32 operation, struct menuitem *item, union handlerdata *data);
s32 frDifficultyMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
