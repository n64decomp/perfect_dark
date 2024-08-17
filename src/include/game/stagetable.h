#ifndef _IN_GAME_STAGETABLE_H
#define _IN_GAME_STAGETABLE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct stagetableentry *stage_get_current(void);
s32 stage_get_index(s32 stagenum);

#endif
