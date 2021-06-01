#ifndef _IN_GAME_SMOKE_SMOKE_H
#define _IN_GAME_SMOKE_SMOKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *smokeRenderPart(struct smoke *smoke, struct smokepart *part, Gfx *gdl, struct coord *coord, f32 size);
struct smoke *smokeCreate(struct coord *pos, s16 *rooms, s16 type);
bool func0f12e454(struct coord *pos, s16 *rooms, s16 type, u32 arg4);
bool smokeCreateAtPropIfNecessary(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, u32 arg4);
void smokeCreateAtProp(struct prop *prop, s16 type);
void func0f12e74c(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, u32 arg4);
void smokeClearForProp(struct prop *prop);
struct smoke *smokeCreateSimple(struct coord *pos, s16 *rooms, s16 type);
u32 func0f12e848(struct prop *prop);
u32 smokeTick(struct prop *prop);
Gfx *smokeRender(struct prop *prop, Gfx *gdl, bool withalpha);
void smokeClearSomeTypes(void);

#endif
