#ifndef IN_GAME_GAMEFILE_H
#define IN_GAME_GAMEFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 gamefileHasFlag(u32 value);
void gamefileSetFlag(u32 value);
void gamefileUnsetFlag(u32 value);
void gamefilePrintFlags(void);
void gamefileApplyOptions(struct gamefile *file);
void gamefileLoadDefaults(struct gamefile *file);
s32 gamefileLoad(s32 arg0);
s32 gamefileSave(s32 arg0, s32 arg1, u16 arg2);
void gamefileGetOverview(char *arg0, char *name, u8 *stage, u8 *difficulty, u32 *time);

#endif
