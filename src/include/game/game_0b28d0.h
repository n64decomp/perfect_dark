#ifndef IN_GAME_GAME_0B28D0_H
#define IN_GAME_GAME_0B28D0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 func0f0b28d0(void);
void func0f0b2904(void);
struct model *func0f0b2b64(struct modelfiledata *modelfiledata, bool arg1);
struct model *modelInstantiate(struct modelfiledata *modelfiledata);
void modelFree(struct model *model);
struct model *func0f0b3280(struct modelfiledata *modelfiledata);
void func0f0b32a0(struct model *model, struct modelnode *node, struct modelfiledata *headfiledata);
struct anim *func0f0b32e4(void);
void animTurnOff(struct anim *anim);

#endif
