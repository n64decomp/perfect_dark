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
s32 g_ModelNumObjs;
s32 g_ModelNumChrs;
struct modelrwdatabinding *g_ModelRwdataBindings[3];

s32 g_MaxModels = 0;
s32 g_MaxAnims = 0;
s32 g_MaxRwdataType1 = 0;
s32 g_MaxRwdataType2 = 0;
s32 g_MaxRwdataType3 = 0;
s32 g_Rwdata1EntrySizeInWords = 0;
s32 g_Rwdata2EntrySizeInWords = 0;
s32 g_Rwdata3EntrySizeInWords = 0;
bool g_ModelIsLvResetting = false;
s32 g_ModelMostType1 = 0;
s32 g_ModelMostType2 = 0;
s32 g_ModelMostType3 = 0;
s32 g_ModelMostModels = 0;
s32 g_ModelMostAnims = 0;

bool modelmgrCanSlotFitRwdata(struct model *modelslot, struct modelfiledata *modeldef)
{
	return modeldef->rwdatalen <= 0
		|| (modelslot->rwdatas != NULL && modelslot->rwdatalen >= modeldef->rwdatalen);
}

struct model *modelmgrInstantiateModel(struct modelfiledata *modeldef, bool withanim)
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
			osSyncPrintf("Allocating %d bytes for objinst structure\n", ALIGN16(sizeof(struct model)));
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
			if (modeldef->rwdatalen < g_Rwdata3EntrySizeInWords) {
				bool done = false;
				u32 stack;

				// Try type 1
				if (modeldef->rwdatalen <= g_Rwdata1EntrySizeInWords) {
					for (i = 0; i < g_MaxRwdataType1; i++) {
						if (g_ModelRwdataBindings[0][i].model == NULL) {
							osSyncPrintf("MotInst: Using cache entry type 1 %d (0x%08x) - Bytes=%d\n");
							rwdatas = g_ModelRwdataBindings[0][i].rwdata;
							g_ModelRwdataBindings[0][i].model = model;
							done = true;
							break;
						}
					}
				}

				// Try type 2
				if (!done && modeldef->rwdatalen <= g_Rwdata2EntrySizeInWords) {
					for (i = 0; i < g_MaxRwdataType2; i++) {
						if (g_ModelRwdataBindings[1][i].model == NULL) {
							osSyncPrintf("MotInst: Using cache entry type 2 %d (0x%08x) - Bytes=%d\n");
							rwdatas = g_ModelRwdataBindings[1][i].rwdata;
							g_ModelRwdataBindings[1][i].model = model;
							done = true;
							break;
						}
					}
				}

				// Try type 3
				// First looking for unused slots with an existing rwdata allocation
				if (!done && modeldef->rwdatalen <= g_Rwdata3EntrySizeInWords) {
					for (i = 0; i < g_MaxRwdataType3; i++) {
						if (g_ModelRwdataBindings[2][i].model == NULL && g_ModelRwdataBindings[2][i].rwdata != NULL) {
							osSyncPrintf("MotInst: Using cache entry type 3 %d (0x%08x) - Bytes=%d\n");
							rwdatas = g_ModelRwdataBindings[2][i].rwdata;
							g_ModelRwdataBindings[2][i].model = model;
							done = true;
							break;
						}
					}
				}

				// Type 3 again, but looking for null rwdata allocations
				if (!done && modeldef->rwdatalen <= g_Rwdata3EntrySizeInWords) {
					for (i = 0; i < g_MaxRwdataType3; i++) {
						if (g_ModelRwdataBindings[2][i].model == NULL && g_ModelRwdataBindings[2][i].rwdata == NULL) {
							g_ModelRwdataBindings[2][i].rwdata = mempAlloc(g_Rwdata3EntrySizeInWords * 4, MEMPOOL_STAGE);
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

	osSyncPrintf("***************************************\n");
	osSyncPrintf("***************************************\n");

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

	for (i = 0; i < g_MaxRwdataType1; i++) {
		if (g_ModelRwdataBindings[0][i].model == model) {
			g_ModelRwdataBindings[0][i].model = NULL;

			model->rwdatas = NULL;
			model->rwdatalen = -1;

			done = true;
			break;
		}
	}

	if (!done) {
		for (i = 0; i < g_MaxRwdataType2; i++) {
			if (g_ModelRwdataBindings[1][i].model == model) {
				osSyncPrintf("\nMotInst: Freeing type 2 cache entry %d (0x%08x)\n\n");

				g_ModelRwdataBindings[1][i].model = NULL;
				model->rwdatas = NULL;
				model->rwdatalen = -1;

				done = true;
				break;
			}
		}
	}

	if (!done) {
		for (i = 0; i < g_MaxRwdataType3; i++) {
			if (g_ModelRwdataBindings[2][i].model == model) {
				osSyncPrintf("\nMotInst: Freeing type 3 cache entry %d (0x%08x)\n\n");
				g_ModelRwdataBindings[2][i].model = NULL;

				model->rwdatas = NULL;
				model->rwdatalen = -1;

				done = true;
				break;
			}
		}
	}

	if (!done) {
		osSyncPrintf("MotInst -> Attempt to free item not in cache\n");
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
