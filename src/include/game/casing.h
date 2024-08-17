#ifndef IN_GAME_CASING_H
#define IN_GAME_CASING_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void casings_reset(void);
void casing_tick(struct casing *arg0);
void casings_tick(void);

#endif
