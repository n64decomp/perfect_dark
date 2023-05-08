#ifndef IN_GAME_MODELMGR_H
#define IN_GAME_MODELMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool modelmgrCanSlotFitRwdata(struct model *modelslot, struct modelfiledata *filedata);
void modelmgrPrintCounts(void);
struct model *modelmgrInstantiateModelWithoutAnim(struct modelfiledata *modelfiledata);
void modelmgrFreeModel(struct model *model);
struct model *modelmgrInstantiateModelWithAnim(struct modelfiledata *modelfiledata);
void modelmgr0f0b32a0(struct model *model, struct modelnode *node, struct modelfiledata *headfiledata);
struct anim *modelmgrInstantiateAnim(void);
void modelmgrFreeAnim(struct anim *anim);

#endif
