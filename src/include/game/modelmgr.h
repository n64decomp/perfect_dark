#ifndef IN_GAME_MODELMGR_H
#define IN_GAME_MODELMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool modelmgrCanSlotFitRwdata(struct model *modelslot, struct modeldef *modeldef);
void modelmgrPrintCounts(void);
struct model *modelmgrInstantiateModel(struct modeldef *modeldef, bool arg1);
struct model *modelmgrInstantiateModelWithoutAnim(struct modeldef *modeldef);
void modelmgrFreeModel(struct model *model);
struct model *modelmgrInstantiateModelWithAnim(struct modeldef *modeldef);
void modelmgrAttachHead(struct model *model, struct modelnode *node, struct modeldef *headmodeldef);
struct anim *modelmgrInstantiateAnim(void);
void modelmgrFreeAnim(struct anim *anim);

#endif
