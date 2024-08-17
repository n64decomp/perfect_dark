#ifndef _IN_CHR_CHRAI_H
#define _IN_CHR_CHRAI_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 chrai_get_list_id_by_list(u8 *ailist, bool *is_global);
u32 chrai_go_to_label(u8 *ailist, u32 aioffset, u8 label);
void chrai_execute(void *entity, s32 proptype);
u32 chrai_get_command_length(u8 *ailist, u32 aioffset);

#endif
