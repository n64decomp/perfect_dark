#ifndef IN_GAME_GAME_102240_H
#define IN_GAME_GAME_102240_H
#include <ultra64.h>
#include "types.h"

char *menuTextCurrentStageName(struct menuitem *item);
char *soloMenuTextDifficulty(struct menuitem *item);
s32 menuhandlerControlStyleImpl(u32 operation, struct menuitem *item, union handlerdata *data, s32 mpindex);
char *soloMenuTitleStageOverview(struct menudialog *dialog);
f32 func0f1036ac(u8 value, s32 prop);
bool isStageDifficultyUnlocked(s32 stageindex, s32 difficulty);
char *soloMenuTextBestTime(struct menuitem *item);
s32 getMaxAiBuddies(void);
s32 getNumUnlockedSpecialStages(void);
s32 func0f104720(s32 value);
char *func0f105664(struct menuitem *item);
char *func0f1056a0(struct menuitem *item);
char *invMenuTextPrimaryFunction(struct menuitem *item);
char *invMenuTextSecondaryFunction(struct menuitem *item);
void func0f105948(s32 weaponnum);
char *invMenuTextWeaponName(struct menuitem *item);
char *invMenuTextWeaponManufacturer(struct menuitem *item);
char *invMenuTextWeaponDescription(struct menuitem *item);
bool soloChoosePauseDialog(void);
s32 menudialog00103368(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialog00103608(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialogCoopAntiOptions(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialog0010559c(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialog00105c54(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialogAbortMission(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 soloMenuDialogPauseStatus(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menuhandler001024dc(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001024fc(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAcceptMission(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAcceptPdModeSettings(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerBuddyOptionsContinue(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerCoopDifficulty(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAntiDifficulty(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler0010476c(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerControlStyle(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler00106028(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler00106178(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAbortMission(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerCinema(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAimControl(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAlternativeTitle(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAlwaysShowTarget(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAmmoOnScreen(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAntiPlayer(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAntiRadar(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAutoAim(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerChangeAgent(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerCoopBuddy(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerCoopFriendlyFire(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerCoopRadar(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerCutsceneSubtitles(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerHeadRoll(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerHiRes(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerInGameSubtitles(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerLangFilter(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerLookAhead(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMusicVolume(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPaintball(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPdMode(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPdModeSetting(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerReversePitch(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerScreenRatio(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerScreenSize(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerScreenSplit(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSfxVolume(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerShowGunFunction(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerShowMissionTime(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerShowZoomRange(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSightOnScreen(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSoloDifficulty(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSoundMode(u32 operation, struct menuitem *item, union handlerdata *data);

#endif
