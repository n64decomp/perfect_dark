#ifndef _IN_GAME_SMOKE_H
#define _IN_GAME_SMOKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void smokesInit(void);

void smokeReset(void);

void smokeStop(void);

bool smokeCreateForHand(struct coord *pos, s16 *rooms, s16 type, s32 handnum);
void smokeCreateAtProp(struct prop *prop, s16 type);
void smokeCreateAtPadEffect(struct padeffectobj *effect, struct coord *pos, s16 *rooms, s16 type);
void smokeClearForProp(struct prop *prop);
struct smoke *smokeCreateSimple(struct coord *pos, s16 *rooms, s16 type);
u32 smokeTickPlayer(struct prop *prop);
Gfx *smokeRender(struct prop *prop, Gfx *gdl, bool xlupass);
void smokeClearSomeTypes(void);

#endif
