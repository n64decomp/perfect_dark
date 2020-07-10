#ifndef IN_GAME_CHEATS_H
#define IN_GAME_CHEATS_H
#include <ultra64.h>
#include "types.h"

extern struct menudialog g_CheatsMenuDialog;

u32 cheatIsUnlocked(s32 cheat_id);
bool cheatIsActive(s32 cheat_id);
void cheatActivate(s32 cheat_id);
void cheatDeactivate(s32 cheat_id);
void cheatsDisableAll(void);
void cheatsActivate(void);
char *cheatGetNameIfUnlocked(struct menuitem *item);
char *cheatGetMarquee(struct menuitem *item);
s32 cheatGetByTimedStageIndex(s32 stage_index, s32 difficulty);
s32 cheatGetByCompletedStageIndex(s32 stage_index);
s32 cheatGetTime(s32 cheat_id);
char *cheatGetName(s32 cheat_id);
bool cheatMenuHandleDialog(u32 operation, struct menudialog *dialog, struct menu *menu);
s32 cheatMenuHandleCheatCheckbox(u32 arg0, struct menuitem *item, s32 arg2);
s32 cheatMenuHandleBuddyCheckbox(s32 arg0, struct menuitem *item, s32 arg2);
bool cheatMenuHandleTurnOffAllCheats(u32 arg0, u32 arg1, u32 *arg2);

#endif
