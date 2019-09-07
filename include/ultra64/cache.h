#ifndef _ULTRA64_CACHE_H_
#define _ULTRA64_CACHE_H_

/* Functions */

void osInvalICache(void *vaddr, s32 nbytes);
void osInvalDCache(void *vaddr, s32 nbytes);
void osWritebackDCache(void *vaddr, s32 nbytes);
void osWritebackDCacheAll(void);

#endif
