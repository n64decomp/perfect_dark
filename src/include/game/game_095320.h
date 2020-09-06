#ifndef IN_GAME_GAME_095320_H
#define IN_GAME_GAME_095320_H
#include <ultra64.h>
#include "types.h"

u32 xorBaffbeff(u32 value);
u32 xorBabeffff(u32 value);
u32 xorBoobless(u32 value);
void func0f0953cc(void);
s32 func0f095560(struct defaultobj *obj);
s32 objectiveGetCount(void);
u32 objectiveGetDifficultyBits(s32 index);
s32 objectiveCheck(s32 index);
u32 objectiveIsAllComplete(void);
void objectivesDisableChecking(void);
void objectivesShowHudmsg(char *buffer, s32 hudmsgtype);
void objectivesCheckAll(void);
void objectiveCheckRoomEntered(s32 currentroom);
void objectiveCheckMultiroomEntered(s32 arg0, s16 *requiredrooms);
void objectiveCheckHolograph(s32 arg0);
struct prop *chopperGetTargetProp(struct chopperobj *heli);
struct defaultobj *objFindByTagId(s32 tag_id);
struct tag *tagFindById(s32 tag_id);

#endif
