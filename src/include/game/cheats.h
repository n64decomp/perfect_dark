#ifndef IN_GAME_CHEATS_H
#define IN_GAME_CHEATS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct menudialogdef g_CheatsMenuDialog;
extern struct menudialogdef g_CheatsFunMenuDialog;
extern struct menudialogdef g_CheatsGameplayMenuDialog;
extern struct menudialogdef g_CheatsSoloWeaponsMenuDialog;
extern struct menudialogdef g_CheatsClassicWeaponsMenuDialog;
extern struct menudialogdef g_CheatsWeaponsMenuDialog;
extern struct menudialogdef g_CheatsBuddiesMenuDialog;

u32 cheat_is_unlocked(s32 cheat_id);
bool cheat_is_active(s32 cheat_id);
void cheat_activate(s32 cheat_id);
void cheat_deactivate(s32 cheat_id);
void cheats_init(void);
void cheats_reset(void);
s32 cheat_get_by_timed_stage_index(s32 stage_index, s32 difficulty);
s32 cheat_get_by_completed_stage_index(s32 stage_index);
s32 cheat_get_time(s32 cheat_id);
char *cheat_get_name(s32 cheat_id);

#endif
