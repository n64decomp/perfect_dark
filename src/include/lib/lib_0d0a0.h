#ifndef _IN_LIB_LIB_0D0A0_H
#define _IN_LIB_LIB_0D0A0_H
#include <ultra64.h>
#include "types.h"

void dmaInit(void);
void func0000d0f8(void *memaddr, void *romaddr, u32 len, bool arg3);
u32 xorDeadbeef(u32 value);
u32 xorDeadbabe(u32 value);
void dmaCheckPiracy(void *memaddr, u32 len);
void func0000d350(void);
void func0000d410(void *memaddr, void *romaddr, u32 len);
void func0000d44c(void *memaddr, void *romaddr, u32 len);
void *func0000d488(void *memaddr, void *romaddr, u32 len);

#endif
