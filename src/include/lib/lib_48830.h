#ifndef _IN_LIB_LIB_48830_H
#define _IN_LIB_LIB_48830_H
#include <ultra64.h>
#include "types.h"

void *osViGetCurrentFramebuffer(void);
void *osViGetNextFramebuffer(void);
OSPri osGetThreadPri(OSThread *thread);

#endif
