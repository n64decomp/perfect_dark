#ifndef _IN_LIB_DEBUGHUD_H
#define _IN_LIB_DEBUGHUD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dhudPutCharAt(s32 x, s32 y, char c);
void dhudInit(void);
void dhudReset(void);
void dhudClear(void);
void dhudSetPos(s32 x, s32 y);
void dhudSetFgColour(s32 r, s32 g, s32 b, s32 a);
void dhudSetBgColour(s32 r, s32 g, s32 b, s32 a);
void dhudPrintChar(u8 c);
void dhudPrintString(char *text);
Gfx *dhudRender(Gfx *gdl);

#endif
