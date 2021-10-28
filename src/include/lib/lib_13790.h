#ifndef _IN_LIB_LIB_13790_H
#define _IN_LIB_LIB_13790_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dhudInit(void);
void dhudTryClear(void);
void dhudClear(void);
void dhudSetPos(s32 x, s32 y);
void dhudPrintChar(u8 c);
void dhudPrintString(char *text);
Gfx *dhudRender(Gfx *gdl);

#endif
