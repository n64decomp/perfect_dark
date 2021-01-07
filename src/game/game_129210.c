#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/chr/chr.h"
#include "game/game_129210.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_126b0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_1a500.h"
#include "types.h"

/**
 * Search all props and their model data for something, and replace it with
 * something else.
 */
void func0f129210(void *find, void *replacement)
{
	u32 stack;
	struct prop *prop = g_Vars.list1head;

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;
			struct model *model = obj->model;
			struct modelfiledata *filedata = model->filedata;
			struct modelnode *node = filedata->rootnode;
			struct modelnode_displaylist *data;

			while (node) {
				switch (node->type & 0xff) {
				case MODELNODETYPE_DISPLAYLIST:
					data = &node->data->displaylist;

					if (model->datas[data->index] == find) {
						model->datas[data->index] = replacement;
					}
					break;
				case MODELNODETYPE_NEARFAR:
					func0001c784(obj->model, node);
					break;
				case MODELNODETYPE_PARTID:
					func0001c7d0(obj->model, node);
					break;
				case MODELNODETYPE_HEADSPOT:
					func0001c81c(obj->model, node);
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

void func0f12939c(void)
{
	s32 i;
	s32 j;

	if (var8007e3d0[1].val2 < var8007e3d0[1].val1 >> 2) {
		for (i = 0; i < var8007e3d0[1].numallocated - 1; i++) {
			if (var8007e3d0[1].unk24[i].unk0e > 0) {
				for (j = i + 1; j < var8007e3d0[1].numallocated; j++) {
					if (var8007e3d0[1].unk24[j].unk0e > 0
							&& var8007e3d0[1].unk24[i].unk04 == var8007e3d0[1].unk24[j].unk04
							&& var8007e3d0[1].unk24[i].unk08 == var8007e3d0[1].unk24[j].unk08) {
						s32 size = ALIGN16(var8007e3d0[1].unk24[j].unk0c * 0x0c);
						func0f129210(var8007e3d0[1].unk24[j].unk00, var8007e3d0[1].unk24[i].unk00);
						var8007e3d0[1].unk24[i].unk0e += var8007e3d0[1].unk24[j].unk0e;
						func00012cb4(var8007e3d0[1].unk24[j].unk00, size);
						var8007e3d0[1].unk24[j].unk0e = 0;
						var8007e3d0[1].val2 += var8007e3d0[1].unk24[j].unk0c;
					}
				}
			}
		}
	}

	if (var8007e3d0[1].val2 < var8007e3d0[1].val1 >> 2) {
		func0f091030();
	}
}

void *func0f12955c(s32 count, s32 index, s32 arg2, s32 arg3)
{
	s32 i;
	s32 numchrs;
	s32 tally;
	s32 rand;
	u32 stack;
	struct chrdata *chrs[6];

	if (IS4MB()) {
		return NULL;
	}

	if (count <= var8007e3d0[index].val2) {
		for (i = 0; i < var8007e3d0[index].numallocated; i++) {
			if (var8007e3d0[index].unk24[i].unk0e == 0) {
				var8007e3d0[index].unk24[i].unk00 = func00012ab0(ALIGN16(count * 0xc));

				if (var8007e3d0[index].unk24[i].unk00) {
					var8007e3d0[index].unk24[i].unk0c = count;
					var8007e3d0[index].unk24[i].unk0e = 1;
					var8007e3d0[index].unk24[i].unk04 = arg2;
					var8007e3d0[index].unk24[i].unk08 = arg3;
					var8007e3d0[index].val2 -= count;

					return var8007e3d0[index].unk24[i].unk00;
				}

				return NULL;
			}
		}
	}

	// Build an array of all corpses. If the array becomes full then enable
	// reaping on a random corpose and replace its entry in the array.
	// So at the end, we'll have an array of up to six unreapable corpses and
	// all other corpses will be flagged for reaping.
	numchrs = getNumChrSlots();
	tally = 0;

	for (i = 0; i < numchrs; i++) {
		struct chrdata *chr = &g_ChrSlots[i];

		if (chr->model
				&& chr->prop
				&& (chr->prop->flags & PROPFLAG_80) == 0
				&& chr->actiontype == ACT_DEAD
				&& chr->act_dead.allowreap == false) {
			if (tally < 6) {
				chrs[tally] = chr;
				tally++;
			} else {
				rand = random() % tally;
				chrEnableReap(chrs[rand]);
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
			chrEnableReap(chrs[i]);
			chrs[i] = NULL;
			rand--;
		}
	}

	return NULL;
}

void func0f129818(s32 arg0, void *arg1)
{
	s32 i;

	for (i = 0; i < var8007e3d0[arg0].numallocated; i++) {
		if (var8007e3d0[arg0].unk24[i].unk0e > 0 && arg1 == var8007e3d0[arg0].unk24[i].unk00) {
			var8007e3d0[arg0].unk24[i].unk0e--;

			if (var8007e3d0[arg0].unk24[i].unk0e) {
				return;
			}

			func00012cb4(var8007e3d0[arg0].unk24[i].unk00, ALIGN16(var8007e3d0[arg0].unk24[i].unk0c * 0xc));

			var8007e3d0[arg0].val2 += var8007e3d0[arg0].unk24[i].unk0c;
			return;
		}
	}
}
