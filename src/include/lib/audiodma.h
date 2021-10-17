#ifndef _IN_LIB_AUDIODMA_H
#define _IN_LIB_AUDIODMA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void admaInit(void);
void admaExec(void);
void admaClear(void);
u32 adma00009a08(void);

#endif
