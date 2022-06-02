#ifndef IN_GAME_MODELDEF_H
#define IN_GAME_MODELDEF_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void modeldef0f1a7560(struct modelfiledata *modeldef, u16 filenum, u32 arg2, u32 arg3, struct texturething *arg4, bool arg5);
void modelPromoteTypeToPointer(struct modelfiledata *filedata);
struct modelfiledata *modeldefLoad(u16 fileid, u8 *arg1, s32 arg2, struct texturething *arg3);
struct modelfiledata *modeldefLoadToNew(u16 fileid);

#endif
