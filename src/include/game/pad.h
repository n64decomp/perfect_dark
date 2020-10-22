#ifndef IN_GAME_PAD_H
#define IN_GAME_PAD_H
#include <ultra64.h>
#include "types.h"

void padUnpack(s32 padnum, u32 fields, struct pad *pad);
bool padHasBboxData(s32 padnum);
void padGetCentre(s32 padnum, struct coord *coord);
void func0f116068(s32 padnum);
void padCopyBboxFromPad(s32 padnum, struct pad *src);
void padSetFlag(s32 padnum, u32 flag);
void padUnsetFlag(s32 padnum, u32 flag);
s32 coverGetCount(void);
bool coverLoad(s32 covernum, struct cover *cover);
bool coverHasFlag0002(s32 covernum);
void coverSetFlag0002(s32 covernum, bool enable);
void coverSetFlag(s32 covernum, u32 flag);
void coverUnsetFlag(s32 covernum, u32 flag);
void coverSetFlag0001(s32 covernum, bool enable);
bool coverHasSomeFlags(struct cover *cover);

#endif
