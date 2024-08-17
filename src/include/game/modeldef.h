#ifndef IN_GAME_MODELDEF_H
#define IN_GAME_MODELDEF_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void modeldef0f1a7560(struct modeldef *modeldef, u16 filenum, u32 arg2, struct modeldef *modeldef2, struct texpool *texpool, bool arg5);
void model_promote_type_to_pointer(struct modeldef *modeldef);
struct modeldef *modeldef_load(u16 fileid, u8 *arg1, s32 arg2, struct texpool *arg3);
struct modeldef *modeldef_load_to_new(u16 fileid);

#endif
