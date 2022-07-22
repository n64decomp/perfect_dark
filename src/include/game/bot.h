#ifndef _IN_GAME_BOT_H
#define _IN_GAME_BOT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool botroomFindPos(s16 room, struct coord *pos, f32 *angleptr, s32 *padnumptr, s32 *covernumptr);

bool botIsDizzy(struct chrdata *chr);
void botReset(struct chrdata *chr, u8 respawning);
void botSpawn(struct chrdata *chr, u8 full);
void botSpawnAll(void);
u32 add87654321(u32 value);
u32 botPickupProp(struct prop *prop, struct chrdata *chr);
bool botTestPropForPickup(struct prop *prop, struct chrdata *chr);
void botCheckPickups(struct chrdata *chr);
s32 botGuessCrouchPos(struct chrdata *chr);
bool botApplyMovement(struct chrdata *chr);
bool botIsAboutToAttack(struct chrdata *chr, bool arg1);
s32 botTick(struct prop *prop);
f32 botCalculateMaxSpeed(struct chrdata *chr);

#if VERSION >= VERSION_NTSC_1_0
void bot0f1921f8(struct chrdata *chr, f32 *move, s32 numupdates, f32 arg3);
#else
void bot0f1921f8(struct chrdata *chr, f32 *move);
#endif

void botDisarm(struct chrdata *chr, struct prop *attacker);
void botSetTarget(struct chrdata *chr, s32 propnum);
bool botIsTargetInvisible(struct chrdata *botchr, struct chrdata *otherchr);
bool botHasGround(struct chrdata *chr);
void bot0f192a74(struct chrdata *chr);
bool botPassesPeaceCheck(struct chrdata *botchr, struct chrdata *otherchr);
bool botPassesCowardCheck(struct chrdata *botchr, struct chrdata *otherchr);
void botChooseGeneralTarget(struct chrdata *chr);
void botScheduleReload(struct chrdata *chr, s32 handnum);
struct prop *botFindPickup(struct chrdata *chr, s32 criteria);
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
bool botCanFollow(struct chrdata *leader, struct chrdata *follower);
s32 botFindTeammateToFollow(struct chrdata *chr, f32 range);
bool botCanDoCriticalPickup(struct chrdata *chr);
struct prop *botFindDefaultPickup(struct chrdata *chr);
struct prop *botFindAnyPickup(struct chrdata *chr);
s32 botGetTeamSize(struct chrdata *chr);
s32 botGetCountInTeamDoingCommand(struct chrdata *self, u32 command, bool includeself);
s32 botIsChrsCtcTokenHeld(struct chrdata *chr);
bool botShouldReturnCtcToken(struct chrdata *chr);
s32 botGetNumTeammatesDefendingHill(struct chrdata *bot);
void botCheckFetch(struct chrdata *chr);

#endif
