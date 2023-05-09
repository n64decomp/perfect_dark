#ifndef IN_GAME_MAINMENU_H
#define IN_GAME_MAINMENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct menudialogdef g_AcceptMissionMenuDialog;
extern struct menudialogdef g_PreAndPostMissionBriefingMenuDialog;
extern struct menudialogdef g_RetryMissionMenuDialog;
extern struct menudialogdef g_NextMissionMenuDialog;

char *soloMenuTextDifficulty(struct menuitem *item);
bool isStageDifficultyUnlocked(s32 stageindex, s32 difficulty);
void func0f105948(s32 weaponnum);
bool soloChoosePauseDialog(void);
s32 menudialog00103608(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
s32 menudialog0010559c(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
s32 soloMenuDialogPauseStatus(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
s32 menuhandlerAcceptMission(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerInventoryList(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMusicVolume(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerScreenRatio(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerScreenSplit(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSfxVolume(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSoundMode(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
