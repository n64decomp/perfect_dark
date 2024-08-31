#ifndef IN_GAME_MODELMGR_H
#define IN_GAME_MODELMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool modelmgr_can_slot_fit_rwdata(struct model *modelslot, struct modeldef *modeldef);
void modelmgr_print_counts(void);
struct model *modelmgr_instantiate_model_without_anim(struct modeldef *modeldef);
void modelmgr_free_model(struct model *model);
struct model *modelmgr_instantiate_model_with_anim(struct modeldef *modeldef);
void modelmgr_attach_head(struct model *model, struct modelnode *node, struct modeldef *headmodeldef);
struct anim *modelmgr_instantiate_anim(void);
void modelmgr_free_anim(struct anim *anim);

#endif
