#ifndef _IN_LIB_FAULT_H
#define _IN_LIB_FAULT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void faultCreateThread(void);
void faultAssert(char *msg, char *file, s32 line);

#endif
