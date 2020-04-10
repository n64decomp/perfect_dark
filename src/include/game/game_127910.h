#ifndef _IN_GAME_GAME_127910_H
#define _IN_GAME_GAME_127910_H
#include <ultra64.h>
#include "types.h"

void func0f127910(void);
void playersUnrefAll(void);
void playersAllocate(s32 count);
void playerAllocate(u32 index);
void currentPlayerCalculateAiBuddyNums(void);
u32 propGetPlayerNum(struct prop *prop);
void currentPlayerSetViewSize(s32 viewx, s32 viewy);
void currentPlayerSetViewPosition(s32 viewleft, s32 viewtop);
void currentPlayerSetFovY(f32 fovy);
void currentPlayerSetAspectRatio(f32 aspect);
s32 weaponGetModel(s32 arg0);
void currentPlayerSetWeaponFlag4(s32 weaponslot);
void func0f128d20(s32 slot);
void randomisePlayerOrder(void);
s32 getPlayerByOrderNum(s32 arg0);
void setCurrentPlayerNum(u32 playernum);
u32 calculatePlayerIndex(u32 playernum);

#endif
