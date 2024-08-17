#ifndef _IN_LIB_RZIP_H
#define _IN_LIB_RZIP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 rzip_inflate(void *src, void *dst, void *scratch);
u32 rzip_init(void);
bool rzip_is_1173(void *buffer);
void *rzip_get_something(void);

#endif
