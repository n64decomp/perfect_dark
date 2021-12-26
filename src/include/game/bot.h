#ifndef _IN_GAME_BOT_H
#define _IN_GAME_BOT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool bot0f190260(struct chrdata *chr);
void botReset(struct chrdata *chr, u8 respawning);
void botSpawn(struct chrdata *chr, u8 full);
void botSpawnAll(void);
u32 add87654321(u32 value);
u32 botPickupProp(struct prop *prop, struct chrdata *chr);
bool botTestPropForPickup(struct prop *prop, struct chrdata *chr);
void botCheckPickups(struct chrdata *chr);
s32 botGuessCrouchPos(struct chrdata *chr);
bool botApplyMovement(struct chrdata *chr);
bool bot0f191638(struct chrdata *chr, bool arg1);
s32 botTick(struct prop *prop);
f32 botCalculateMaxSpeed(struct chrdata *chr);

#if VERSION >= VERSION_NTSC_1_0
void bot0f1921f8(struct chrdata *chr, f32 *move, s32 numupdates, f32 arg3);
#else
void bot0f1921f8(struct chrdata *chr, f32 *move);
#endif

void botLoseGun(struct chrdata *chr, struct prop *attacker);
void bot0f19277c(struct chrdata *chr, s32 propnum);
bool bot0f19294c(struct chrdata *botchr, struct chrdata *otherchr);
bool botHasGround(struct chrdata *chr);
void bot0f192a74(struct chrdata *chr);
bool botPassesPeaceCheck(struct chrdata *botchr, struct chrdata *otherchr);
bool botPassesCowardCheck(struct chrdata *botchr, struct chrdata *otherchr);
u32 bot0f192e90(void);
void bot0f19369c(struct chrdata *chr, s32 arg1);
s32 bot0f1937a4(struct chrdata *chr, s32 arg1);
s32 botGetNumOpponentsInHill(struct chrdata *chr);
void botTickUnpaused(struct chrdata *chr);
s32 botIsObjCollectable(struct defaultobj *obj);
s32 botGetWeaponNum(struct chrdata *chr);
u8 botGetTargetsWeaponNum(struct chrdata *chr);
char *botGetCommandName(s32 command);
void botApplyAttack(struct chrdata *chr, struct prop *prop);
void botApplyFollow(struct chrdata *chr, struct prop *prop);
void botApplyProtect(struct chrdata *chr, struct prop *prop);
void botApplyDefend(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3);
void botApplyHold(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3);
void botApplyScenarioCommand(struct chrdata *chr, u32 arg1);
bool botIsFollowing(struct chrdata *leader, struct chrdata *follower);
s32 bot0f193530(struct chrdata *chr, f32 range);
bool bot0f194670(struct chrdata *chr);
s32 bot0f194694(struct chrdata *chr);
s32 bot0f1946b4(struct chrdata *chr);
s32 botGetNumPlayerTeammates(struct chrdata *chr);
s32 botCountByCommand(struct chrdata *self, u32 command, bool includeself);
s32 botIsChrsTokenHeld(struct chrdata *chr);
bool bot0f19489c(struct chrdata *chr);
s32 botGetNumTeammatesDefendingHill(struct chrdata *bot);
void botCheckFetch(struct chrdata *chr);

#endif
