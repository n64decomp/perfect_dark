#ifndef _IN_LIB_CRASH_H
#define _IN_LIB_CRASH_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern bool g_CrashEnabled;

void crashCreateThread(void);
void crashRenderFrame(u16 *fb);
void crashReset(void);

#endif
