#include <ultra64.h>
#include "constants.h"
#include "game/bg.h"
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

/**
 * Vtxstores are used for:
 * - deforming objects when destroyed (obj vtx)
 * - darkening objects when destroyed (obj col)
 * - disfiguring chrs when damaged by explosions (chr vtx)
 * - darkening chrs when damaged by explosions (chr col)
 * - bruising chrs when shot or stabbed (chr col)
 *
 * Model vertices and colours are typically stored in the model definition,
 * which is shared between all instances of that model. To have different
 * vertices or colours for a single instance, this data has to be copied out of
 * the model definition and into its own allocation before it can be customised.
 * These allocations are managed using vtxstores.
 *
 * Despite the name, vtxstores are also used for colours.
 *
 * Vtxstores are allocated out of mema. They are freed by the caller when the
 * object or chr is deleted. The vtxstore system will force free offscreen
 * chrs and objects if it is low on memory.
 */

// Vertices are 12 bytes while colours are 4 bytes.
// The game allocates 12 bytes regardless of whether it's
// for a vertex or a colour. This is wasteful for colours.
#define UNIT_SIZE MAX(sizeof(Vtx), sizeof(Col))

struct vtxstoretype g_VtxstoreTypes[] = {
	//              |------ sp -------| |------ mp -------| |----- other -----| |- unused -|
	//              maxunits numbatches maxunits numbatches maxunits numbatches
	/* chr vtx */ { 3000,    120,       3000,    80,        0,       0,         500,  20, 12 },
	/* obj vtx */ { 1500,    40,        500,     20,        0,       0,         500,  20, 12 },
	/* chr col */ { 6000,    120,       6000,    80,        0,       0,         1000, 20, 4  },
	/* obj col */ { 1500,    40,        500,     20,        0,       0,         500,  20, 4  },
};

/**
 * Search all props and their model data for references to the `find` address
 * and replace it with the `replacement` address.
 */
void vtxstore_fix_refs(void *find, void *replacement)
{
	s32 count = 0;
	struct prop *prop = g_Vars.activeprops;

	osSyncPrintf("VTXSTORE : vtxfixrefs -> Start - p1=%x, p2=%x\n", find, replacement);

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;
			struct model *model = obj->model;
			struct modeldef *modeldef = model->definition;
			struct modelnode *node = modeldef->rootnode;
			struct modelrodata_dl *rodata;

			while (node) {
				switch (node->type & 0xff) {
				case MODELNODETYPE_DL:
					rodata = &node->rodata->dl;

					if (model->rwdatas[rodata->rwdataindex] == (uintptr_t) find) {
						osSyncPrintf("vtxfixrefs : Part=%x -- Mapping ptr %x -> %x\n", rodata->rwdataindex, model->rwdatas[rodata->rwdataindex], replacement);
						model->rwdatas[rodata->rwdataindex] = (uintptr_t) replacement;
						count++;
					}
					break;
				case MODELNODETYPE_DISTANCE:
					model_apply_distance_relations(obj->model, node);
					break;
				case MODELNODETYPE_TOGGLE:
					model_apply_toggle_relations(obj->model, node);
					break;
				case MODELNODETYPE_HEADSPOT:
					model_apply_head_relations(obj->model, node);
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

	osSyncPrintf("VTXSTORE : vtxfixrefs -> End - Done=%d\n", count);
}

void vtxstore_tick(void)
{
	s32 i;
	s32 j;

	// If the obj vtx stores are at least 75% full then iterate them and try to
	// find duplicates. Merge duplicates into the original.
	// I don't think it's possible for there to be duplicates though.
	if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numunitsfree < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numunitsmax >> 2) {
		for (i = 0; i < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numbatches - 1; i++) {
			if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[i].refcount > 0) {
				for (j = i + 1; j < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numbatches; j++) {
					if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].refcount > 0
							&& g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[i].node == g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].node
							&& g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[i].level == g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].level) {
						s32 size = ALIGN16(g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].numunitsalloced * UNIT_SIZE);

						vtxstore_fix_refs(g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].allocation, g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[i].allocation);

						g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[i].refcount += g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].refcount;

						osSyncPrintf("vtxstorecheck : memaFree -> %u bytes at Ptr=%x(%x)\n", size, g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].allocation);

						mema_free(g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].allocation, size);

						g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].refcount = 0;
						g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numunitsfree += g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].numunitsalloced;
					}

					osSyncPrintf("vtxstorecheck : At block 1 %d -> Ref1=%x, Ref2=%x\n", i, g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[i].node, g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[i].level);
					osSyncPrintf("vtxstorecheck : At block 2 %d -> Ref1=%x, Ref2=%x\n", j, g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].node, g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].batches[j].level);
				}
			}
		}
	}

	// If the obj vtx stores are still at least 75% full
	// then free all the offscreen and deformed objects.
	if (g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numunitsfree < g_VtxstoreTypes[VTXSTORETYPE_OBJVTX].numunitsmax >> 2) {
		osSyncPrintf("vtx buffer low, need to delete objects\n");
		obj_free_all_offscreen_deformed_objs();
	}
}

void *vtxstore_allocate(s32 count, s32 type, struct modelnode *node, s32 level)
{
	s32 i;
	s32 numchrs;
	s32 corpsecount;
	s32 rand;
	u32 size;
	struct chrdata *corpses[6];

#if VERSION >= VERSION_NTSC_1_0
	if (IS4MB()) {
		return NULL;
	}
#endif

	osSyncPrintf("getfreevertices : %d of type %d -> ref1=%x, ref2=%x\n", count, type, node, level);

	if (count <= g_VtxstoreTypes[type].numunitsfree) {
		for (i = 0; i < g_VtxstoreTypes[type].numbatches; i++) {
			if (g_VtxstoreTypes[type].batches[i].refcount == 0) {
				size = ALIGN16(count * UNIT_SIZE);

				osSyncPrintf("vtxstore: 1st mema alloc of %u bytes\n", size);

				g_VtxstoreTypes[type].batches[i].allocation = mema_alloc(size);

#if VERSION < VERSION_NTSC_1_0
				if (g_VtxstoreTypes[type].batches[i].allocation == NULL) {
					osSyncPrintf("vtxstore: Trying to free %d from mema (bgRooms)\n", size);
					bg_garbage_collect_rooms(size, false);
					g_VtxstoreTypes[type].batches[i].allocation = mema_alloc(size);
				}
#endif

				osSyncPrintf("getfreevertices : Return ptr = %x\n", g_VtxstoreTypes[type].batches[i].allocation);

				if (g_VtxstoreTypes[type].batches[i].allocation != NULL) {
					g_VtxstoreTypes[type].batches[i].numunitsalloced = count;
					g_VtxstoreTypes[type].batches[i].refcount = 1;
					g_VtxstoreTypes[type].batches[i].node = node;
					g_VtxstoreTypes[type].batches[i].level = level;
					g_VtxstoreTypes[type].numunitsfree -= count;

					return g_VtxstoreTypes[type].batches[i].allocation;
				}

				osSyncPrintf("vtxstore: Out of mema (returning NULL)\n");

				return NULL;
			}
		}
	}

	// Build an array of all corpses. If the array becomes full then enable
	// reaping on a random corpse and replace its entry in the array.
	// So at the end, we'll have an array of up to six unreapable corpses and
	// all other corpses will be flagged for reaping.
	numchrs = chrs_get_num_slots();
	corpsecount = 0;

	for (i = 0; i < numchrs; i++) {
		struct chrdata *chr = &g_ChrSlots[i];

		if (chr->model
				&& chr->prop
				&& (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) == 0
				&& chr->actiontype == ACT_DEAD
				&& chr->act_dead.fadewheninvis == false) {
			if (corpsecount < ARRAYCOUNT(corpses)) {
				corpses[corpsecount] = chr;
				corpsecount++;
			} else {
				rand = random() % corpsecount;
				osSyncPrintf("vtxstore: GROSS! CorspeCount > MAX_CORPSES corpses! Freeing corpse %x\n", &corpses[rand]);
				chr_fade_corpse_when_off_screen(corpses[rand]);
				corpses[rand] = chr;
			}
		}
	}

	// Enable reaping on half the remaining corpses.
	// I'm reusing the rand and i variables here in order to get a match.
	// The original code likely didn't reuse them.
	rand = corpsecount >> 1;

	osSyncPrintf("vtxstore:  CorpseCount %d, Trying to free %d\n", corpsecount, rand);

	while (rand) {
		i = random() % corpsecount;

		if (corpses[i]) {
			osSyncPrintf("vtxstore: Freeing corpse %x\n", &corpses[i]);
			chr_fade_corpse_when_off_screen(corpses[i]);
			corpses[i] = NULL;
			rand--;
		}
	}

	osSyncPrintf("vtxstore: Out of vertices type %d wanted %d free %d (returning NULL)\n", type, count, g_VtxstoreTypes[type].numunitsfree);

	return NULL;
}

void vtxstore_free(s32 type, void *allocation)
{
	s32 i;

	osSyncPrintf("vtxstore: freevertices type %d, list %x\n", type, allocation);

	for (i = 0; i < g_VtxstoreTypes[type].numbatches; i++) {
		if (g_VtxstoreTypes[type].batches[i].refcount > 0 && g_VtxstoreTypes[type].batches[i].allocation == allocation) {
			g_VtxstoreTypes[type].batches[i].refcount--;

			if (g_VtxstoreTypes[type].batches[i].refcount == 0) {
				mema_free(g_VtxstoreTypes[type].batches[i].allocation, ALIGN16(g_VtxstoreTypes[type].batches[i].numunitsalloced * UNIT_SIZE));

				g_VtxstoreTypes[type].numunitsfree += g_VtxstoreTypes[type].batches[i].numunitsalloced;
			}

			return;
		}
	}

	osSyncPrintf("freevertices: address not found in array %x\n", allocation);
}
