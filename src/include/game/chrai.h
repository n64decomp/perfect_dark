#ifndef _IN_CHR_CHRAI_H
#define _IN_CHR_CHRAI_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 chraiGetListIdByList(u8 *ailist, bool *is_global);
void chraiExecute(void *entity, s32 proptype);

#endif
