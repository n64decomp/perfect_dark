#ifndef IN_GAME_GETITLE_H
#define IN_GAME_GETITLE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void getitleReset(void);

void getitleLoad(void *addr, u32 arg1);
Gfx *getitleRender(Gfx *gdl);

#endif
