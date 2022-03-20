#ifndef _IN_GAME_STAGETABLE_H
#define _IN_GAME_STAGETABLE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct stagetableentry *stageGetCurrent(void);
s32 stageGetIndex(s32 stagenum);

#endif
