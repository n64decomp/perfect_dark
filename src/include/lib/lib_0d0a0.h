#ifndef _IN_LIB_LIB_0D0A0_H
#define _IN_LIB_LIB_0D0A0_H
#include <ultra64.h>
#include "types.h"

void dmaInit(void);
void dmaStart(void *memaddr, u32 romaddr, u32 len, bool priority);
u32 xorDeadbeef(u32 value);
u32 xorDeadbabe(u32 value);
void dmaCheckPiracy(void *memaddr, u32 len);
void dmaWait(void);
void dmaExec(void *memaddr, void *romaddr, u32 len);
void dmaExecHighPriority(void *memaddr, void *romaddr, u32 len);
void *func0000d488(void *memaddr, void *romaddr, u32 len);

#endif
