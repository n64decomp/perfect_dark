#ifndef _ULTRA64_OS_MISC_H_
#define _ULTRA64_OS_MISC_H_

/* Miscellaneous OS functions */

void osInitialize(void);
u32 osGetCount(void);

u32 osVirtualToPhysical(void *);

f32 cosf(f32 arg0);
f32 sinf(f32 arg0);
f32 sqrtf(f32 arg0);

void *memcpy(void *, const void *, size_t);
u32 strlen(char *str);
u32 strchr(void);

#endif
