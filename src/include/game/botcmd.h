#ifndef IN_GAME_BOTCMD_H
#define IN_GAME_BOTCMD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void botcmd_tick_dist_mode(struct chrdata *chr);
void botcmd_apply(struct chrdata *chr, u32 command);

#endif
