#ifndef IN_GAME_GAME_106D40_H
#define IN_GAME_GAME_106D40_H
#include <ultra64.h>
#include "types.h"

bool cheatIsUnlocked(s32 cheat_id);
bool cheatIsEnabled(s32 cheat_id);
u32 func0f106ea0(void);
u32 func0f1071c4(void);
void func0f1074ec(void);
u32 func0f107510(void);
char *cheatGetNameIfUnlocked(struct cheatthing *thing);
u32 func0f107a78(void);
s32 cheatGetByTimedStageIndex(s32 stage_index, s32 difficulty);
s32 cheatGetByCompletedStageIndex(s32 stage_index);
s32 cheatGetTime(s32 cheat_id);
char *cheatGetName(s32 cheat_id);
s32 menudialog00107990(u32, u32, u32 *);
s32 menuhandlerCheat(u32, u32, u32 *);
s32 menuhandlerCheatBuddy(u32, u32, u32 *);
bool menuhandlerTurnOffAllCheats(u32 arg0, u32 arg1, u32 *arg2);

#endif
