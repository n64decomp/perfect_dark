#ifndef _IN_GAME_TIMING_H
#define _IN_GAME_TIMING_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void frametimeInit(void);
void frametimeApply(s32 diffframe60, s32 diffframe240, s32 frametime);
void frametimeCalculate(void);
void func0f16cf94(void);

extern const char var7f1b78c0[];
extern const char var7f1b78c8[];
extern const char var7f1b78d4[];
extern const char var7f1b78f4[];
extern const char var7f1b7900[];
extern const char var7f1b7908[];
extern const char var7f1b7910[];

#endif
