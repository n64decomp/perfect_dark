#ifndef _IN_LIB_MEMP_H
#define _IN_LIB_MEMP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void memp_init(void);
void memp_set_heap(u8 *heapstart, u32 heaplen);
u32 memp_get_stage_free(void);
void *memp_get_next_stage_allocation(void);
void *memp_alloc(u32 len, u8 pool);
s32 memp_realloc(void *allocation, s32 newsize, u8 poolnum);
u32 memp_get_pool_free(u8 poolnum, u32 bank);
u32 memp_get_pool_size(u8 poolnum, u32 bank);
void memp_reset_pool(u8 pool);
void memp_disable_pool(u8 pool);
void *memp_alloc_from_right(u32 len, u8 pool);

#endif
