#ifndef IN_GAME_BOSSFILE_H
#define IN_GAME_BOSSFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool bossfileLoadFull(void);
u32 bossfileFindFileId(void);
void bossfileLoad(void);
void bossfileSave(void);
void bossfileSetDefaults(void);

#endif
