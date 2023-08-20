#ifndef _IN_GAME_GAME_129210_H
#define _IN_GAME_GAME_129210_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void vtxstoreReset(void);

void vtxstoreFixRefs(void *find, void *replacement);
void vtxstoreTick(void);
void *vtxstoreAllocate(s32 count, s32 index, struct modelnode *node, s32 level);
void vtxstoreFree(s32 type, void *arg1);

#endif
