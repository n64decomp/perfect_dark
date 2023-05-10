#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/chr.h"
#include "game/vtxstore.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/mema.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"



struct vtxstoretype g_VtxstoreTypes[] = {
	{ 3000, 120, 3000, 80, 0, 0, 500,  20, 12, 0, 0, 0, 0 },
	{ 1500, 40,  500,  20, 0, 0, 500,  20, 12, 0, 0, 0, 0 },
	{ 6000, 120, 6000, 80, 0, 0, 1000, 20, 4,  0, 0, 0, 0 },
	{ 1500, 40,  500,  20, 0, 0, 500,  20, 4,  0, 0, 0, 0 },
};

/**
 * Search all props and their model data for something, and replace it with
 * something else.
 */
static void vtxstoreFixRefs(union modelrwdata *find, union modelrwdata *replacement)
{
	u32 stack;
	struct prop *prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;
			struct model *model = obj->model;
			struct modelfiledata *filedata = model->filedata;
			struct modelnode *node = filedata->rootnode;
			struct modelrodata_dl *rodata;

			while (node) {
				switch (node->type & 0xff) {
				case MODELNODETYPE_DL:
					rodata = &node->rodata->dl;

					if (model->rwdatas[rodata->rwdataindex] == find) {
						model->rwdatas[rodata->rwdataindex] = replacement;
					}
					break;
				case MODELNODETYPE_DISTANCE:
					model0001c784(obj->model, node);
					break;
				case MODELNODETYPE_TOGGLE:
					model0001c7d0(obj->model, node);
					break;
				case MODELNODETYPE_HEADSPOT:
					modelAttachHead(obj->model, node);
					break;
				}

				if (node->child) {
					node = node->child;
				} else {
					while (node) {
						if (node->next) {
							node = node->next;
							break;
						}

						node = node->parent;
					}
				}
			}
		}

		prop = prop->next;
	}
}

void vtxstoreTick(void)
{
	s32 i;
	s32 j;

	if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].val2 < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].val1 >> 2) {
		for (i = 0; i < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numallocated - 1; i++) {
			if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[i].unk0e > 0) {
				for (j = i + 1; j < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numallocated; j++) {
					if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].unk0e > 0
							&& g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[i].node == g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].node
							&& g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[i].level == g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].level) {
						s32 size = ALIGN16(g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].count * 0x0c);
						vtxstoreFixRefs(g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].unk00, g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[i].unk00);
						g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[i].unk0e += g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].unk0e;
						memaFree(g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].unk00, size);
						g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].unk0e = 0;
						g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].val2 += g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].unk24[j].count;
					}
				}
			}
		}
	}

	if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].val2 < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].val1 >> 2) {
		func0f091030();
	}
}

void *vtxstoreAllocate(s32 count, s32 index, struct modelnode *node, s32 level)
{
	s32 i;
	s32 numchrs;
	s32 tally;
	s32 rand;
	u32 size;
	struct chrdata *chrs[6];

	if (count <= g_VtxstoreTypes[index].val2) {
		for (i = 0; i < g_VtxstoreTypes[index].numallocated; i++) {
			if (g_VtxstoreTypes[index].unk24[i].unk0e == 0) {
				size = ALIGN16(count * 0xc);
				g_VtxstoreTypes[index].unk24[i].unk00 = memaAlloc(size);

				if (g_VtxstoreTypes[index].unk24[i].unk00) {
					g_VtxstoreTypes[index].unk24[i].count = count;
					g_VtxstoreTypes[index].unk24[i].unk0e = 1;
					g_VtxstoreTypes[index].unk24[i].node = node;
					g_VtxstoreTypes[index].unk24[i].level = level;
					g_VtxstoreTypes[index].val2 -= count;

					return g_VtxstoreTypes[index].unk24[i].unk00;
				}

				return NULL;
			}
		}
	}

	// Build an array of all corpses. If the array becomes full then enable
	// reaping on a random corpse and replace its entry in the array.
	// So at the end, we'll have an array of up to six unreapable corpses and
	// all other corpses will be flagged for reaping.
	numchrs = g_NumChrSlots;
	tally = 0;

	for (i = 0; i < numchrs; i++) {
		struct chrdata *chr = &g_ChrSlots[i];

		if (chr->model
				&& chr->prop
				&& (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) == 0
				&& chr->actiontype == ACT_DEAD
				&& chr->act_dead.fadewheninvis == false) {
			if (tally < 6) {
				chrs[tally] = chr;
				tally++;
			} else {
				rand = random() % tally;
				chrFadeCorpseWhenOffScreen(chrs[rand]);
				chrs[rand] = chr;
			}
		}
	}

	// Enable reaping on half the remaining corpses.
	// I'm reusing the rand and i variables here in order to get a match.
	// The original code likely didn't reuse them.
	rand = tally >> 1;

	while (rand) {
		i = random() % tally;

		if (chrs[i]) {
			chrFadeCorpseWhenOffScreen(chrs[i]);
			chrs[i] = NULL;
			rand--;
		}
	}

	return NULL;
}

void vtxstoreFree(s32 type, void *arg1)
{
	s32 i;

	for (i = 0; i < g_VtxstoreTypes[type].numallocated; i++) {
		if (g_VtxstoreTypes[type].unk24[i].unk0e > 0 && arg1 == g_VtxstoreTypes[type].unk24[i].unk00) {
			g_VtxstoreTypes[type].unk24[i].unk0e--;

			if (g_VtxstoreTypes[type].unk24[i].unk0e) {
				return;
			}

			memaFree(g_VtxstoreTypes[type].unk24[i].unk00, ALIGN16(g_VtxstoreTypes[type].unk24[i].count * 0xc));

			g_VtxstoreTypes[type].val2 += g_VtxstoreTypes[type].unk24[i].count;
			return;
		}
	}
}
