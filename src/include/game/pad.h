#ifndef IN_GAME_PAD_H
#define IN_GAME_PAD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void padUnpack(s32 padnum, u32 fields, struct pad *pad);
bool padHasBboxData(s32 padnum);
void padGetCentre(s32 padnum, struct coord *coord);
void padRotateForDoor(s32 padnum);
void padCopyBboxFromPad(s32 padnum, struct pad *src);
void padSetFlag(s32 padnum, u32 flag);
void padUnsetFlag(s32 padnum, u32 flag);
s32 coverGetCount(void);
bool coverUnpack(s32 covernum, struct cover *cover);
bool coverIsInUse(s32 covernum);
void coverSetInUse(s32 covernum, bool enable);
void coverSetFlag(s32 covernum, u32 flag);
void coverUnsetFlag(s32 covernum, u32 flag);
void coverSetFlag0001(s32 covernum, bool enable);
bool coverIsSpecial(struct cover *cover);

#endif
