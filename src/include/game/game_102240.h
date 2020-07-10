#ifndef IN_GAME_GAME_102240_H
#define IN_GAME_GAME_102240_H
#include <ultra64.h>
#include "types.h"

char *menuTextCurrentStageName(struct menuitem *item);
char *soloMenuTextDifficulty(struct menuitem *item);
char *menuhandlerControlStyleImpl(u32 operation, struct menuitem *item, s32 *value, s32 arg3);
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
s32 menudialog00103368(u32, u32, u32 *);
s32 menudialog00103608(u32 operation, struct menudialog *dialog, struct menuthing **thingptr);
bool menudialogCoopAntiOptions(u32 operation, struct menudialog *dialog, struct menu *menu);
s32 menudialog0010559c(u32 operation, struct menudialog *dialog, s32 *arg2);
s32 menudialog00105c54(u32, u32, u32 *);
s32 menudialog001063d4(u32, u32, u32 *);
s32 soloMenuDialogPauseStatus(u32 operation, s32 arg1, s32 arg2);
char *menuhandler001024dc(u32 operation, struct menuitem *item, s32 *value);
char *menuhandler001024fc(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerAcceptMission(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerAcceptPdModeSettings(s32 operation, struct menuitem *item, bool *value);
s32 menuhandlerBuddyOptionsContinue(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerCoopDifficulty(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerAntiDifficulty(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandler0010476c(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerControlStyle(s32 operation, struct menuitem *item, u32 *value);
s32 menuhandler00106028(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandler00106178(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerAbortMission(u32 operation, struct menuitem *item, s32 *value);
char *menuhandlerCinema(u32 operation, struct menuitem *item, s32 *value);
char *menuhandlerAimControl(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerAlternativeTitle(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerAlwaysShowTarget(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerAmmoOnScreen(u32 operation, struct menuitem *item, bool *enable);
char *menuhandlerAntiPlayer(u32 operation, struct menudialog *dialog, s32 *value);
s32 menuhandlerAntiRadar(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerAutoAim(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerChangeAgent(s32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerCoopBuddy(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerCoopFriendlyFire(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerCoopRadar(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerCutsceneSubtitles(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerHeadRoll(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerHiRes(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerInGameSubtitles(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerLangFilter(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerLookAhead(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerMusicVolume(u32 operation, struct menuitem *item, u32 *volume);
s32 menuhandlerPaintball(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerPdMode(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerPdModeSetting(u32 operation, struct menuitem *item, struct numandtext *value);
s32 menuhandlerReversePitch(u32 operation, struct menuitem *item, bool *enable);
char *menuhandlerScreenRatio(u32 operation, struct menuitem *item, s32 *value);
char *menuhandlerScreenSize(u32 operation, struct menuitem *item, s32 *value);
char *menuhandlerScreenSplit(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerSfxVolume(u32 operation, struct menuitem *item, u32 *volume);
s32 menuhandlerShowGunFunction(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerShowMissionTime(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerShowZoomRange(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerSightOnScreen(u32 operation, struct menuitem *item, bool *enable);
s32 menuhandlerSoloDifficulty(u32 operation, struct menuitem *item, s32 *value);
char *menuhandlerSoundMode(u32 operation, struct menuitem *item, s32 *value);

#endif
