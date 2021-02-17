#ifndef IN_GAME_MPSTATS_H
#define IN_GAME_MPSTATS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mpstatsIncrementPlayerShotCount(struct shorthand *hand, s32 region);
void mpstatsIncrementPlayerShotCount2(struct shorthand *hand, s32 region);
void mpstats0f0b0520(void);
s32 mpstatsGetPlayerShotCountByRegion(u32 type);
void mpstatsIncrementTotalKillCount(void);
void mpstatsIncrementTotalKnockoutCount(void);
void mpstatsDecrementTotalKnockoutCount(void);
u8 mpstatsGetTotalKnockoutCount(void);
u32 mpstatsGetTotalKillCount(void);
void mpstatsRecordPlayerKill(void);
s32 mpstatsGetPlayerKillCount(void);
void mpstatsRecordPlayerDeath(void);
void mpstatsRecordPlayerSuicide(void);
void mpstatsRecordDeath(s32 aplayernum, s32 vplayernum);

#endif
