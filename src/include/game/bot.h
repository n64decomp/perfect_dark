#ifndef _IN_GAME_BOT_H
#define _IN_GAME_BOT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool botroomFindPos(s16 room, struct coord *pos, f32 *angleptr, s32 *padnumptr, s32 *covernumptr);

void botSpawn(struct chrdata *chr, u8 full);
void botSpawnAll(void);
u32 add87654321(u32 value);
u32 botPickupProp(struct prop *prop, struct chrdata *chr);
s32 botGuessCrouchPos(struct chrdata *chr);
s32 botTick(struct prop *prop);
f32 botCalculateMaxSpeed(struct chrdata *chr);
void bot0f1921f8(struct chrdata *chr, f32 *move, s32 numupdates, f32 arg3);
void botDisarm(struct chrdata *chr, struct prop *attacker);
bool botIsTargetInvisible(struct chrdata *botchr, struct chrdata *otherchr);
bool botHasGround(struct chrdata *chr);
void botTickUnpaused(struct chrdata *chr);
u8 botGetTargetsWeaponNum(struct chrdata *chr);
char *botGetCommandName(s32 command);
void botApplyAttack(struct chrdata *chr, struct prop *prop);
void botApplyFollow(struct chrdata *chr, struct prop *prop);
void botApplyProtect(struct chrdata *chr, struct prop *prop);
void botApplyDefend(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3);
void botApplyHold(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3);
void botApplyScenarioCommand(struct chrdata *chr, u32 arg1);
void botCheckFetch(struct chrdata *chr);

#endif
