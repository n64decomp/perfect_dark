#ifndef _IN_BOOT_SEGMENTS_H
#define _IN_BOOT_SEGMENTS_H
#include <ultra64.h>

void *segGetDataStart(void);
void *segGetDatazipRomStart(void);
void *segGetInflateRomStart(void);
void *segGetInflateRomStart2(void);
void *segGetGamezipsRomStart(void);
u32 segInflate();

#endif
