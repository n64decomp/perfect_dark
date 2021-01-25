#ifndef _IN_LIB_LIB_08A20_H
#define _IN_LIB_LIB_08A20_H
#include <ultra64.h>
#include "types.h"

void audioAllocateStack(void);
u32 func00008a48(void);
void audioStartThread(void);
OSMesgQueue *func00009118(void);
void audioStopThread(void);
u32 func00009448(void);
u32 func00009614(void);

#endif
