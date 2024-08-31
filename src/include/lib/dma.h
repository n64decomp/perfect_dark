#ifndef _IN_LIB_DMA_H
#define _IN_LIB_DMA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dma_init(void);
void dma_wait(void);
void dma_exec(void *memaddr, u32 romaddr, u32 len);
void dma_exec_high_priority(void *memaddr, u32 romaddr, u32 len);
void *dma_exec_with_auto_align(void *memaddr, u32 romaddr, u32 len);

#endif
