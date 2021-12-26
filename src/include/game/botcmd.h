#ifndef IN_GAME_BOTCMD_H
#define IN_GAME_BOTCMD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void botcmdTickDistMode(struct chrdata *chr);
void botcmdApply(struct chrdata *chr, u32 command);

#endif
