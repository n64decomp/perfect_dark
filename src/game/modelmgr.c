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
bool g_ModelIsLvResetting = false;
s32 g_ModelMostType1 = 0;
s32 g_ModelMostType2 = 0;
s32 g_ModelMostType3 = 0;
s32 g_ModelMostModels = 0;
s32 g_ModelMostAnims = 0;

#define NUMTYPE1() (IS4MB() ? 0 : 35)
#define NUMTYPE2() (IS4MB() ? 24 : 25)
#define NUMTYPE3() (IS4MB() ? 0 : 20)

bool modelmgr_can_slot_fit_rwdata(struct model *modelslot, struct modeldef *modeldef)
{
	return modeldef->rwdatalen <= 0
		|| (modelslot->rwdatas != NULL && modelslot->rwdatalen >= modeldef->rwdatalen);
}

void modelmgr_print_counts(void)
{
	s32 i;
	s32 numtype1 = 0;
	s32 numtype2 = 0;
	s32 numtype3 = 0;
	s32 nummodels = 0;
	s32 numanims = 0;

	for (i = 0; i < NUMTYPE1(); i++) {
		if (g_ModelRwdataBindings[0][i].model) {
			numtype1++;
		}
	}

	for (i = 0; i < NUMTYPE2(); i++) {
		if (g_ModelRwdataBindings[1][i].model) {
			numtype2++;
		}
	}

	for (i = 0; i < NUMTYPE3(); i++) {
		if (g_ModelRwdataBindings[2][i].model) {
			numtype3++;
		}
	}

	for (i = 0; i < g_MaxModels; i++) {
		if (g_ModelSlots[i].definition) {
			nummodels++;
		}
	}

	for (i = 0; i < g_MaxAnims; i++) {
		if (g_AnimSlots[i].animnum != -1) {
			numanims++;
		}
	}

	if (numtype1 > g_ModelMostType1) {
		g_ModelMostType1 = numtype1;
	}

	if (numtype2 > g_ModelMostType2) {
		g_ModelMostType2 = numtype2;
	}

	if (numtype3 > g_ModelMostType3) {
		g_ModelMostType3 = numtype3;
	}

	if (nummodels > g_ModelMostModels) {
		g_ModelMostModels = nummodels;
	}

	if (numanims > g_ModelMostAnims) {
		g_ModelMostAnims = numanims;
	}

	osSyncPrintf("MOT : Type 1  = %d/%d (%d)");
	osSyncPrintf("MOT : Type 2  = %d/%d (%d)");
	osSyncPrintf("MOT : Type 3  = %d/%d (%d)");
	osSyncPrintf("MOT : Type OI = %d/%d/%d/%d");
	osSyncPrintf("MOT : Type OA = %d/%d/%d/%d");
	osSyncPrintf("MOT : g_ObjCount = %d");
	osSyncPrintf("MOT : g_AnimCount = %d");

	if (IS4MB());
}

struct model *modelmgr_instantiate_model(struct modeldef *modeldef, bool withanim)
{
	struct model *model = NULL;
	u32 *rwdatas = NULL;
	s16 datalen = -1;
	s32 i;

	if (!g_ModelIsLvResetting) {
		// If it's being allocated mid-gameplay, look through all slots
		// and find any slot that's big enough.
		for (i = 0; i < g_MaxModels; i++) {
			if (g_ModelSlots[i].definition == NULL && modelmgr_can_slot_fit_rwdata(&g_ModelSlots[i], modeldef)) {
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
			if (g_ModelSlots[i].definition == NULL) {
				model = &g_ModelSlots[i];
				break;
			}
		}

		if (model == NULL) {
			osSyncPrintf("Allocating %d bytes for objinst structure\n", ALIGN16(sizeof(struct model)));
			model = memp_alloc(ALIGN16(sizeof(struct model)), MEMPOOL_STAGE);
		}

		if (g_ModelIsLvResetting) {
			if (modeldef->rwdatalen > 0) {
				datalen = modeldef->rwdatalen;
				rwdatas = memp_alloc(ALIGN16(datalen * 4), MEMPOOL_STAGE);
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
							osSyncPrintf("MotInst: Using cache entry type 1 %d (0x%08x) - Bytes=%d\n");
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
							osSyncPrintf("MotInst: Using cache entry type 2 %d (0x%08x) - Bytes=%d\n");
							if (IS4MB());
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
							osSyncPrintf("MotInst: Using cache entry type 3 %d (0x%08x) - Bytes=%d\n");
							if (IS4MB());
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
							g_ModelRwdataBindings[2][i].rwdata = memp_alloc(256 * 4, MEMPOOL_STAGE);
							rwdatas = g_ModelRwdataBindings[2][i].rwdata;
							g_ModelRwdataBindings[2][i].model = model;
							break;
						}
					}
				}
			} else {
				// empty
			}

			if (withanim) {
				datalen = 256;
			} else {
				datalen = IS4MB() ? 52 : 256;
			}

			if (datalen < modeldef->rwdatalen) {
				datalen = modeldef->rwdatalen;
			}

			if (rwdatas == NULL) {
				rwdatas = memp_alloc(ALIGN16(datalen * 4), MEMPOOL_STAGE);
			}
		}
	}

	if (model) {
		if (withanim) {
			model->anim = modelmgr_instantiate_anim();

			if (model->anim) {
				anim_init(model->anim);
			} else {
				modelmgr_free_model(model);
				model = NULL;
			}
		} else {
			model->anim = NULL;
		}
	}

	if (model) {
		model_init(model, modeldef, rwdatas, false);
		model->rwdatalen = datalen;
	}

	osSyncPrintf("***************************************\n");
	osSyncPrintf("***************************************\n");

	return model;
}

struct model *modelmgr_instantiate_model_without_anim(struct modeldef *modeldef)
{
	return modelmgr_instantiate_model(modeldef, false);
}

void modelmgr_free_model(struct model *model)
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
		for (i = 0; i < NUMTYPE3(); i++) {
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
		modelmgr_free_anim(model->anim);
		model->anim = NULL;
	}

	model->definition = NULL;
}

struct model *modelmgr_instantiate_model_with_anim(struct modeldef *modeldef)
{
	return modelmgr_instantiate_model(modeldef, true);
}

void modelmgr_attach_head(struct model *model, struct modelnode *node, struct modeldef *headmodeldef)
{
	model_attach_head(model, model->definition, node, headmodeldef);
	model_init_rw_data(model, headmodeldef->rootnode);
}

struct anim *modelmgr_instantiate_anim(void)
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

void modelmgr_free_anim(struct anim *anim)
{
	anim->animnum = -1;
}
