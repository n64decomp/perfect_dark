#ifndef IN_GAME_GETITLE_H
#define IN_GAME_GETITLE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void getitle_reset(void);

void getitle_load(void *addr, u32 arg1);
Gfx *getitle_render(Gfx *gdl);

#endif
