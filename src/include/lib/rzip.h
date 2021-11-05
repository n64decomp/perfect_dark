#ifndef _IN_LIB_RZIP_H
#define _IN_LIB_RZIP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 rzipInflate(void *src, void *dst, void *scratch);
u32 rzipInit(void);
bool rzipIs1173(void *buffer);
u32 rzipGetSomething(void);

#endif
