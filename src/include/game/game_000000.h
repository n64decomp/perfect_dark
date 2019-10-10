#ifndef _IN_GAME_000000_H
#define _IN_GAME_000000_H
#include <ultra64.h>
#include "constants.h"

struct chrdata *chrFindById(struct chrdata *data, u8 chrnum);

float chrGetTimer(struct chrdata *chr);

s32 padResolve(struct chrdata *chr, s32 pad_id);

#endif
