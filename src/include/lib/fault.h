#ifndef _IN_LIB_FAULT_H
#define _IN_LIB_FAULT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void fault_init(void);
void fault_assert(char *msg, char *file, s32 line);

#endif
