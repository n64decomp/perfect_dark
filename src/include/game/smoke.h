#ifndef _IN_GAME_SMOKE_H
#define _IN_GAME_SMOKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void smokesInit(void);

void smokeReset(void);

void smokeStop(void);

Gfx *smokeRenderPart(struct smoke *smoke, struct smokepart *part, Gfx *gdl, struct coord *coord, f32 size);
struct smoke *smokeCreate(struct coord *pos, RoomNum *rooms, s16 type);
bool smokeCreateForHand(struct coord *pos, RoomNum *rooms, s16 type, s32 handnum);
bool smokeCreateWithSource(void *source, struct coord *pos, RoomNum *rooms, s16 type, bool srcispadeffect);
void smokeCreateAtProp(struct prop *prop, s16 type);
void smokeCreateAtPadEffect(struct padeffectobj *effect, struct coord *pos, RoomNum *rooms, s16 type);
void smokeClearForProp(struct prop *prop);
struct smoke *smokeCreateSimple(struct coord *pos, RoomNum *rooms, s16 type);
u32 smokeTick(struct prop *prop);
u32 smokeTickPlayer(struct prop *prop);
Gfx *smokeRender(struct prop *prop, Gfx *gdl, bool xlupass);
void smokeClearSomeTypes(void);

#endif
