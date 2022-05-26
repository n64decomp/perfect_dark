#include <ultra64.h>
#include "constants.h"
#include "game/game_0b28d0.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

struct model *var8009dd00;
struct anim *var8009dd04;
u32 var8009dd08;
u32 var8009dd0c;
struct var8009dd10 *var8009dd10[3];
u32 var8009dd1c;

s32 var800705a0 = 0;
s32 var800705a4 = 0;
bool var800705a8 = false;
s32 var800705ac = 0;
s32 var800705b0 = 0;
s32 var800705b4 = 0;
s32 var800705b8 = 0;
s32 var800705bc = 0;

#define NUMTHINGS1() (IS4MB() ? 0 : 35)
#define NUMTHINGS2() (IS4MB() ? 24 : 25)
#define NUMTHINGS3() (IS4MB() ? 0 : 20)

GLOBAL_ASM(
glabel func0f0b28d0
/*  f0b28d0:	84a30014 */ 	lh	$v1,0x14($a1)
/*  f0b28d4:	28620001 */ 	slti	$v0,$v1,0x1
/*  f0b28d8:	14400008 */ 	bnez	$v0,.L0f0b28fc
/*  f0b28dc:	00000000 */ 	nop
/*  f0b28e0:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0b28e4:	0002702b */ 	sltu	$t6,$zero,$v0
/*  f0b28e8:	11c00004 */ 	beqz	$t6,.L0f0b28fc
/*  f0b28ec:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0b28f0:	848f0002 */ 	lh	$t7,0x2($a0)
/*  f0b28f4:	01e3102a */ 	slt	$v0,$t7,$v1
/*  f0b28f8:	38420001 */ 	xori	$v0,$v0,0x1
.L0f0b28fc:
/*  f0b28fc:	03e00008 */ 	jr	$ra
/*  f0b2900:	00000000 */ 	nop
);

void func0f0b2904(void)
{
	s32 i;
	s32 count1 = 0;
	s32 count2 = 0;
	s32 count3 = 0;
	s32 count4 = 0;
	s32 count5 = 0;

	for (i = 0; i < NUMTHINGS1(); i++) {
		if (var8009dd10[0][i].model) {
			count1++;
		}
	}

	for (i = 0; i < NUMTHINGS2(); i++) {
		if (var8009dd10[1][i].model) {
			count2++;
		}
	}

	for (i = 0; i < NUMTHINGS3(); i++) {
		if (var8009dd10[2][i].model) {
			count3++;
		}
	}

	for (i = 0; i < var800705a0; i++) {
		if (var8009dd00[i].filedata) {
			count4++;
		}
	}

	for (i = 0; i < var800705a4; i++) {
		if (var8009dd04[i].animnum != -1) {
			count5++;
		}
	}

	if (count1 > var800705ac) {
		var800705ac = count1;
	}

	if (count2 > var800705b0) {
		var800705b0 = count2;
	}

	if (count3 > var800705b4) {
		var800705b4 = count3;
	}

	if (count4 > var800705b8) {
		var800705b8 = count4;
	}

	if (count5 > var800705bc) {
		var800705bc = count5;
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

struct model *modelInstantiate(struct modelfiledata *modeldef, bool withanim)
{
	struct model *model;
	union modelrwdata **rwdatas;
	s16 sp36;
	s32 i;

	model = NULL;
	rwdatas = NULL;
	sp36 = -1;

	if (!var800705a8) {
		for (i = 0; i < var800705a0; i++) {
			if (var8009dd00[i].filedata == NULL && func0f0b28d0(&var8009dd00[i], modeldef)) {
				model = &var8009dd00[i];
				rwdatas = var8009dd00[i].rwdatas;
				sp36 = var8009dd00[i].unk02;
				break;
			}
		}
	}

	if (model == NULL) {
		for (i = 0; i < var800705a0; i++) {
			if (var8009dd00[i].filedata == NULL) {
				model = &var8009dd00[i];
				break;
			}
		}

		if (model == NULL) {
			osSyncPrintf("Allocating %d bytes for objinst structure\n", ALIGN16(sizeof(struct model)));
			model = mempAlloc(ALIGN16(sizeof(struct model)), MEMPOOL_STAGE);
		}

		if (var800705a8) {
			if (modeldef->rwdatalen > 0) {
				sp36 = modeldef->rwdatalen;
				rwdatas = mempAlloc(ALIGN16(sp36 * 4), MEMPOOL_STAGE);
			}
		} else {
			if (modeldef->rwdatalen < 256) {
				bool done = false;
				u32 stack;

				if (modeldef->rwdatalen <= 4) {
					for (i = 0; i < NUMTHINGS1(); i++) {
						if (var8009dd10[0][i].model == NULL) {
							osSyncPrintf("MotInst: Using cache entry type 1 %d (0x%08x) - Bytes=%d\n");
							rwdatas = var8009dd10[0][i].rwdata;
							var8009dd10[0][i].model = model;
							done = true;
							break;
						}
					}
				}

				if (!done && modeldef->rwdatalen <= 52) {
					for (i = 0; i < NUMTHINGS2(); i++) {
						if (var8009dd10[1][i].model == NULL) {
							osSyncPrintf("MotInst: Using cache entry type 2 %d (0x%08x) - Bytes=%d\n");
							if (IS4MB());
							rwdatas = var8009dd10[1][i].rwdata;
							var8009dd10[1][i].model = model;
							done = true;
							break;
						}
					}
				}

				if (!done && modeldef->rwdatalen <= 256) {
					for (i = 0; i < NUMTHINGS3(); i++) {
						if (var8009dd10[2][i].model == NULL && var8009dd10[2][i].rwdata != NULL) {
							osSyncPrintf("MotInst: Using cache entry type 3 %d (0x%08x) - Bytes=%d\n");
							if (IS4MB());
							rwdatas = var8009dd10[2][i].rwdata;
							var8009dd10[2][i].model = model;
							done = true;
							break;
						}
					}
				}

				if (!done && modeldef->rwdatalen <= 256) {
					for (i = 0; i < NUMTHINGS3(); i++) {
						if (var8009dd10[2][i].model == NULL && var8009dd10[2][i].rwdata == NULL) {
							var8009dd10[2][i].rwdata = mempAlloc(0x400, MEMPOOL_STAGE);
							rwdatas = var8009dd10[2][i].rwdata;
							var8009dd10[2][i].model = model;
							break;
						}
					}
				}
			} else {
				// empty
			}

			if (withanim) {
				sp36 = 256;
			} else {
				sp36 = IS4MB() ? 52 : 256;
			}

			if (sp36 < modeldef->rwdatalen) {
				sp36 = modeldef->rwdatalen;
			}

			if (rwdatas == NULL) {
				rwdatas = mempAlloc(ALIGN16(sp36 * 4), MEMPOOL_STAGE);
			}
		}
	}

	if (model) {
		if (withanim) {
			model->anim = func0f0b32e4();

			if (model->anim) {
				animInit(model->anim);
			} else {
				modelFree(model);
				model = NULL;
			}
		} else {
			model->anim = NULL;
		}
	}

	if (model) {
		modelInit(model, modeldef, rwdatas, false);
		model->unk02 = sp36;
	}

	osSyncPrintf("***************************************\n");
	osSyncPrintf("***************************************\n");

	return model;
}

struct model *modelInstantiateWithoutAnim(struct modelfiledata *modelfiledata)
{
	return modelInstantiate(modelfiledata, false);
}

void modelFree(struct model *model)
{
	bool done = false;
	s32 i;

	for (i = 0; i < NUMTHINGS1(); i++) {
		if (var8009dd10[0][i].model == model) {
			var8009dd10[0][i].model = NULL;

			model->rwdatas = NULL;
			model->unk02 = -1;

			done = true;
			break;
		}
	}

	if (!done) {
		for (i = 0; i < NUMTHINGS2(); i++) {
			if (var8009dd10[1][i].model == model) {
				osSyncPrintf("\nMotInst: Freeing type 2 cache entry %d (0x%08x)\n\n");

				var8009dd10[1][i].model = NULL;

				model->rwdatas = NULL;
				model->unk02 = -1;

				done = true;
				break;
			}
		}
	}

	if (!done) {
		for (i = 0; i < NUMTHINGS3(); i++) {
			if (var8009dd10[2][i].model == model) {
				osSyncPrintf("\nMotInst: Freeing type 3 cache entry %d (0x%08x)\n\n");
				var8009dd10[2][i].model = NULL;

				model->rwdatas = NULL;
				model->unk02 = -1;

				done = true;
				break;
			}
		}
	}

	if (!done) {
		osSyncPrintf("MotInst -> Attempt to free item not in cache\n");
	}

	if (model->anim) {
		animTurnOff(model->anim);
		model->anim = NULL;
	}

	model->filedata = NULL;
}

struct model *modelInstantiateWithAnim(struct modelfiledata *modelfiledata)
{
	return modelInstantiate(modelfiledata, true);
}

void func0f0b32a0(struct model *model, struct modelnode *node, struct modelfiledata *headmodeldef)
{
	model00023108(model, model->filedata, node, headmodeldef);
	modelInitRwData(model, headmodeldef->rootnode);
}

struct anim *func0f0b32e4(void)
{
	s32 i;
	struct anim *anim = NULL;

	for (i = 0; i < var800705a4; i++) {
		if (var8009dd04[i].animnum == -1) {
			anim = &var8009dd04[i];
			break;
		}
	}

	return anim;
}

void animTurnOff(struct anim *anim)
{
	anim->animnum = -1;
}
