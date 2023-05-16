#ifndef _IN_LIB_DEBUGHUD_H
#define _IN_LIB_DEBUGHUD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dhudInit(void);
void dhudReset(void);
Gfx *dhudRender(Gfx *gdl);

#endif
