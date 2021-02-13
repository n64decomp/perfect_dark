#ifndef _IN_LIB_DMA_H
#define _IN_LIB_DMA_H
#include <ultra64.h>
#include "types.h"

void dmaInit(void);
void dmaStart(void *memaddr, u32 romaddr, u32 len, bool priority);
void dmaCheckPiracy(void *memaddr, u32 len);
void dmaWait(void);
void dmaExec(void *memaddr, void *romaddr, u32 len);
void dmaExecHighPriority(void *memaddr, void *romaddr, u32 len);
void *dmaExecWithAutoAlign(void *memaddr, u32 romaddr, u32 len);

#endif
