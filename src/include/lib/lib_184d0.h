#ifndef _IN_LIB_LIB_184D0_H
#define _IN_LIB_LIB_184D0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u8 *ailistFindById(s32 ailistid);
void objSetBlockedPathUnblocked(struct defaultobj *blocker, bool unblocked);

#endif
