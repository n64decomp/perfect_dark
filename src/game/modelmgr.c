#include <ultra64.h>
#include "constants.h"
#include "game/modelmgr.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

struct model *g_ModelSlots;
struct anim *g_AnimSlots;
struct modelrwdatabinding *g_ModelRwdataBindings[3];

s32 g_MaxModels = 0;
s32 g_MaxAnims = 0;
bool g_ModelIsLvResetting = false;

#define NUMTYPE1() 35
#define NUMTYPE2() 25
#define NUMTYPE3() 20

bool modelmgrCanSlotFitRwdata(struct model *modelslot, struct modelfiledata *modeldef)
{
	return modeldef->rwdatalen <= 0
		|| (modelslot->rwdatas != NULL && modelslot->rwdatalen >= modeldef->rwdatalen);
}

static struct model *modelmgrInstantiateModel(struct modelfiledata *modeldef, bool withanim)
{
	struct model *model = NULL;
	union modelrwdata **rwdatas = NULL;
	s16 datalen = -1;
	s32 i;

	if (!g_ModelIsLvResetting) {
		// If it's being allocated mid-gameplay, look through all slots
		// and find any slot that's big enough.
		for (i = 0; i < g_MaxModels; i++) {
			if (g_ModelSlots[i].filedata == NULL && modelmgrCanSlotFitRwdata(&g_ModelSlots[i], modeldef)) {
				model = &g_ModelSlots[i];
				rwdatas = g_ModelSlots[i].rwdatas;
				datalen = g_ModelSlots[i].rwdatalen;
				break;
			}
		}
	}

	if (model == NULL) {
		// This is lv reset, or gameplay when a suitable slot can't be found

		// Find any spare slot or allocate a new one
		for (i = 0; i < g_MaxModels; i++) {
			if (g_ModelSlots[i].filedata == NULL) {
				model = &g_ModelSlots[i];
				break;
			}
		}

		if (model == NULL) {
			model = mempAlloc(ALIGN16(sizeof(struct model)), MEMPOOL_STAGE);
		}

		if (g_ModelIsLvResetting) {
			if (modeldef->rwdatalen > 0) {
				datalen = modeldef->rwdatalen;
				rwdatas = mempAlloc(ALIGN16(datalen * 4), MEMPOOL_STAGE);
			}
		} else {
			// At this point, it's during gameplay. A model instance slot has
			// been found or allocated, but rwdata needs to be allocated.
			if (modeldef->rwdatalen < 256) {
				bool done = false;
				u32 stack;

				// 4 words (0x10 bytes) or less -> try type 1
				if (modeldef->rwdatalen <= 4) {
					for (i = 0; i < NUMTYPE1(); i++) {
						if (g_ModelRwdataBindings[0][i].model == NULL) {
							rwdatas = g_ModelRwdataBindings[0][i].rwdata;
							g_ModelRwdataBindings[0][i].model = model;
							done = true;
							break;
						}
					}
				}

				// 52 words (0xd0 bytes) or less -> try type 2
				if (!done && modeldef->rwdatalen <= 52) {
					for (i = 0; i < NUMTYPE2(); i++) {
						if (g_ModelRwdataBindings[1][i].model == NULL) {
							rwdatas = g_ModelRwdataBindings[1][i].rwdata;
							g_ModelRwdataBindings[1][i].model = model;
							done = true;
							break;
						}
					}
				}

				// 256 words (0x400 bytes) or less -> try type 3
				// First looking for unused slots with an existing rwdata allocation
				if (!done && modeldef->rwdatalen <= 256) {
					for (i = 0; i < NUMTYPE3(); i++) {
						if (g_ModelRwdataBindings[2][i].model == NULL && g_ModelRwdataBindings[2][i].rwdata != NULL) {
							rwdatas = g_ModelRwdataBindings[2][i].rwdata;
							g_ModelRwdataBindings[2][i].model = model;
							done = true;
							break;
						}
					}
				}

				// Type 3 again, but looking for null rwdata allocations
				if (!done && modeldef->rwdatalen <= 256) {
					for (i = 0; i < NUMTYPE3(); i++) {
						if (g_ModelRwdataBindings[2][i].model == NULL && g_ModelRwdataBindings[2][i].rwdata == NULL) {
							g_ModelRwdataBindings[2][i].rwdata = mempAlloc(256 * 4, MEMPOOL_STAGE);
							rwdatas = g_ModelRwdataBindings[2][i].rwdata;
							g_ModelRwdataBindings[2][i].model = model;
							break;
						}
					}
				}
			} else {
				// empty
			}

			datalen = 256;

			if (datalen < modeldef->rwdatalen) {
				datalen = modeldef->rwdatalen;
			}

			if (rwdatas == NULL) {
				rwdatas = mempAlloc(ALIGN16(datalen * 4), MEMPOOL_STAGE);
			}
		}
	}

	if (model) {
		if (withanim) {
			model->anim = modelmgrInstantiateAnim();

			if (model->anim) {
				animInit(model->anim);
			} else {
				modelmgrFreeModel(model);
				model = NULL;
			}
		} else {
			model->anim = NULL;
		}
	}

	if (model) {
		modelInit(model, modeldef, rwdatas, false);
		model->rwdatalen = datalen;
	}


	return model;
}

struct model *modelmgrInstantiateModelWithoutAnim(struct modelfiledata *modelfiledata)
{
	return modelmgrInstantiateModel(modelfiledata, false);
}

void modelmgrFreeModel(struct model *model)
{
	bool done = false;
	s32 i;

	for (i = 0; i < NUMTYPE1(); i++) {
		if (g_ModelRwdataBindings[0][i].model == model) {
			g_ModelRwdataBindings[0][i].model = NULL;

			model->rwdatas = NULL;
			model->rwdatalen = -1;

			done = true;
			break;
		}
	}

	if (!done) {
		for (i = 0; i < NUMTYPE2(); i++) {
			if (g_ModelRwdataBindings[1][i].model == model) {

				g_ModelRwdataBindings[1][i].model = NULL;

				model->rwdatas = NULL;
				model->rwdatalen = -1;

				done = true;
				break;
			}
		}
	}

	if (!done) {
		for (i = 0; i < NUMTYPE3(); i++) {
			if (g_ModelRwdataBindings[2][i].model == model) {
				g_ModelRwdataBindings[2][i].model = NULL;

				model->rwdatas = NULL;
				model->rwdatalen = -1;

				done = true;
				break;
			}
		}
	}

	if (!done) {
	}

	if (model->anim) {
		modelmgrFreeAnim(model->anim);
		model->anim = NULL;
	}

	model->filedata = NULL;
}

struct model *modelmgrInstantiateModelWithAnim(struct modelfiledata *modelfiledata)
{
	return modelmgrInstantiateModel(modelfiledata, true);
}

void modelmgr0f0b32a0(struct model *model, struct modelnode *node, struct modelfiledata *headmodeldef)
{
	model00023108(model, model->filedata, node, headmodeldef);
	modelInitRwData(model, headmodeldef->rootnode);
}

struct anim *modelmgrInstantiateAnim(void)
{
	s32 i;
	struct anim *anim = NULL;

	for (i = 0; i < g_MaxAnims; i++) {
		if (g_AnimSlots[i].animnum == -1) {
			anim = &g_AnimSlots[i];
			break;
		}
	}

	return anim;
}

void modelmgrFreeAnim(struct anim *anim)
{
	anim->animnum = -1;
}
