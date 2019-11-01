#ifndef _IN_CHR_CHRAI_H
#define _IN_CHR_CHRAI_H
#include <ultra64.h>

s32 chraiEndList(u8 *ailist, u64 *unk);
u32 chraiGoToLabel(u8 *ailist, u32 aioffset, u8 label);
void chraiExecute(void *entity, s32 entity_type);
u32 chraiGetCommandLength(u8 *ailist, u32 aioffset);

#endif
