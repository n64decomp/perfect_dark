#ifndef _IN_LIB_MEMA_H
#define _IN_LIB_MEMA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mema_defrag(void);
void mema_init(void);
void mema_reset(void *ptr, u32 size);
void mema_print(void);
void *mema_alloc(u32 size);
void _mema_free(s32 addr, s32 size);
void mema_free(void *addr, s32 size);
s32 mema_get_longest_free(void);
bool mema_realloc(s32 addr, u32 oldsize, u32 newsize);

#endif
