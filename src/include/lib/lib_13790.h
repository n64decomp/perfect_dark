#ifndef _IN_LIB_LIB_13790_H
#define _IN_LIB_LIB_13790_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dhudPutCharAt(s32 x, s32 y, char c);
void dhudInit(void);
void dhudTryReset(void);
void dhudReset(void);
void dhudSetPos(s32 x, s32 y);
void dhudPrintChar(u8 c);
void dhudPrintString(char *text);
Gfx *dhudRender(Gfx *gdl);

#endif
