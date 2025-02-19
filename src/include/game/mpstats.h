#ifndef IN_GAME_MPSTATS_H
#define IN_GAME_MPSTATS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mpstats_increment_player_shotcount_projectiles(struct gset *gset, s32 region);
void mpstats_increment_player_shotcount(struct gset *gset, s32 region);
void mpstats_end_shot(void);
s32 mpstats_get_player_shotcount_by_region(s32 region);
void mpstats_increment_total_kill_count(void);
void mpstats_increment_total_knockout_count(void);
void mpstats_decrement_total_knockout_count(void);
u8 mpstats_get_total_knockout_count(void);
void mpstats_record_player_kill(void);
s32 mpstats_get_player_kill_count(void);
void mpstats_record_death(s32 aplayernum, s32 vplayernum);

#endif
