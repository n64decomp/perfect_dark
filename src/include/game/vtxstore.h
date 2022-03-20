#ifndef _IN_GAME_GAME_129210_H
#define _IN_GAME_GAME_129210_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void vtxstoreReset(void);

void vtxstoreFixRefs(union modelrwdata *find, union modelrwdata *replacement);
void vtxstoreTick(void);
void *vtxstoreAllocate(s32 count, s32 index, s32 arg2, s32 arg3);
void vtxstoreFree(s32 arg0, void *arg1);

#endif
