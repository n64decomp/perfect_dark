#ifndef IN_GAME_GFXREPLACE_H
#define IN_GAME_GFXREPLACE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void gfxReplaceGbiCommands(Gfx *gdl, Gfx *endgdl, s32 type);
void gfxReplaceGbiCommandsRecursively(struct roomgfxdata18 *arg0, s32 type);

#endif
