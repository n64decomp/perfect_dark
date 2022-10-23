#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/ailist.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

s32 g_NumGlobalAilists = 0;
s32 g_NumLvAilists = 0;

u8 *ailistFindById(s32 ailistid)
{
	s32 lower;
	s32 upper;
	s32 index;

	if (ailistid >= 0x401) {
		if (g_StageSetup.ailists) {
			lower = 0;
			upper = g_NumLvAilists;
			index;

			while (upper >= lower) {
				index = (lower + upper) / 2;

				if (g_StageSetup.ailists[index].id == ailistid) {
					return g_StageSetup.ailists[index].list;
				}

				if (ailistid < g_StageSetup.ailists[index].id) {
					upper = index - 1;
				} else {
					lower = index + 1;
				}
			}
		}
	} else {
		lower = 0;
		upper = g_NumGlobalAilists;
		index;

		while (upper >= lower) {
			index = (lower + upper) / 2;

			if (g_GlobalAilists[index].id == ailistid) {
				return g_GlobalAilists[index].list;
			}

			if (ailistid < g_GlobalAilists[index].id) {
				upper = index - 1;
			} else {
				lower = index + 1;
			}
		}
	}

	return NULL;
}

bool ailistIsGoto(s32 type)
{
	switch (type) {
	case 0x0000:
	case 0x0001:
	case 0x000c:
	case 0x000f:
	case 0x0010:
	case 0x0011:
	case 0x0012:
	case 0x0013:
	case 0x0014:
	case 0x0015:
	case 0x0016:
	case 0x0017:
	case 0x0018:
	case 0x001b:
	case 0x001c:
	case 0x0023:
	case 0x0027:
	case 0x002a:
	case 0x002b:
	case 0x002c:
	case 0x002d:
	case 0x002e:
	case 0x002f:
	case 0x0030:
	case 0x0031:
	case 0x0032:
	case 0x0033:
	case 0x0034:
	case 0x0035:
	case 0x0037:
	case 0x0038:
	case 0x0039:
	case 0x003a:
	case 0x003b:
	case 0x003c:
	case 0x003d:
	case 0x003e:
	case 0x003f:
	case 0x0040:
	case 0x0041:
	case 0x0042:
	case 0x0043:
	case 0x0044:
	case 0x0045:
	case 0x0046:
	case 0x0047:
	case 0x0048:
	case 0x0049:
	case 0x004a:
	case 0x004b:
	case 0x004c:
	case 0x004d:
	case 0x004e:
	case 0x004f:
	case 0x0050:
	case 0x0051:
	case 0x0052:
	case 0x0053:
	case 0x0054:
	case 0x0055:
	case 0x0056:
	case 0x0057:
	case 0x0058:
	case 0x0059:
	case 0x005a:
	case 0x005b:
	case 0x005c:
	case 0x005d:
	case 0x005e:
	case 0x005f:
	case 0x0060:
	case 0x0061:
	case 0x0062:
	case 0x0063:
	case 0x006e:
	case 0x006f:
	case 0x0072:
	case 0x0073:
	case 0x0074:
	case 0x0075:
	case 0x0076:
	case 0x0077:
	case 0x0078:
	case 0x0079:
	case 0x007a:
	case 0x007b:
	case 0x007c:
	case 0x007d:
	case 0x007e:
	case 0x007f:
	case 0x0080:
	case 0x0081:
	case 0x0082:
	case 0x0083:
	case 0x0088:
	case 0x0089:
	case 0x008e:
	case 0x008f:
	case 0x0090:
	case 0x009d:
	case 0x00a0:
	case 0x00a3:
	case 0x00a6:
	case 0x00a9:
	case 0x00ac:
	case 0x00af:
	case 0x00ba:
	case 0x00bb:
	case 0x00bd:
	case 0x00bc:
	case 0x00c3:
	case 0x00c4:
	case 0x00c5:
	case 0x00c6:
	case 0x00c7:
	case 0x00c8:
	case 0x00c9:
	case 0x00ca:
	case 0x00d4:
	case 0x00e2:
	case 0x00e5:
	case 0x00ea:
	case 0x00eb:
	case 0x00ef:
	case 0x00f0:
	case 0x00f1:
	case 0x00f6:
	case 0x00f7:
	case 0x00f8:
	case 0x00fc:
	case 0x00fd:
	case 0x0103:
	case 0x0105:
	case 0x0107:
	case 0x0108:
	case 0x0109:
	case 0x010a:
	case 0x010c:
	case 0x010f:
	case 0x0110:
	case 0x0113:
	case 0x011a:
	case 0x011d:
	case 0x011e:
	case 0x011f:
	case 0x0120:
	case 0x0121:
	case 0x0122:
	case 0x0123:
	case 0x0125:
	case 0x0126:
	case 0x0127:
	case 0x0128:
	case 0x0129:
	case 0x012a:
	case 0x012b:
	case 0x012c:
	case 0x0133:
	case 0x0134:
	case 0x0135:
	case 0x0137:
	case 0x0138:
	case 0x013a:
	case 0x013c:
	case 0x013d:
	case 0x013f:
	case 0x0140:
	case 0x0147:
	case 0x0149:
	case 0x014a:
	case 0x014b:
	case 0x0152:
	case 0x0165:
	case 0x0166:
	case 0x0168:
	case 0x0169:
	case 0x016a:
	case 0x016f:
	case 0x0170:
	case 0x0171:
	case 0x0172:
	case 0x0173:
	case 0x0174:
	case 0x0176:
	case 0x0178:
	case 0x017a:
	case 0x017b:
	case 0x0181:
	case 0x0182:
	case 0x0183:
	case 0x0186:
	case 0x0187:
	case 0x0188:
	case 0x018a:
	case 0x018e:
	case 0x018f:
	case 0x0192:
	case 0x0193:
	case 0x019e:
	case 0x01a5:
	case 0x01a6:
	case 0x01a7:
	case 0x01aa:
	case 0x01ab:
	case 0x01b4:
	case 0x01ba:
	case 0x01bc:
	case 0x01bd:
	case 0x01be:
	case 0x01c0:
	case 0x01c9:
	case 0x01cc:
	case 0x01d7:
	case 0x01d8:
	case 0x01dd:
	case 0x01df:
	case 0x01de:
		return true;
	}

	return false;
}

extern u16 g_CommandLengths[];

void ailistAnalyse(u8 *ailist, s32 *numcmdsptr, s32 *numlabelsptr, s32 *numgotosptr, s32 *oldsizeptr)
{
	s32 numcmds = 0;
	s32 numlabels = 0;
	s32 numgotos = 0;
	u8 *ptr = ailist;
	s32 type;

	do {
		type = ptr[0] << 8 | ptr[1];

		if (type == 0x0002) {
			numlabels++;
		} else if (ailistIsGoto(type)) {
			numgotos++;
		}

		numcmds++;
		ptr += g_CommandLengths[type];
	} while (type != CMD_END);

	*numcmdsptr = numcmds;
	*numlabelsptr = numlabels;
	*numgotosptr = numgotos;
	*oldsizeptr = ptr - ailist;
}

struct tmpcmd {
	u16 type;
	u16 oldoffset;
	u16 newoffset;
	u8 len;
	u8 labelnum; // if label
	u8 gotolabelnum; // if goto
	struct tmpcmd *target;
};

void ailistConvert(u8 *src, u8 *dst, struct tmpcmd *cmds, s32 numcmds)
{
	s32 i = 0;
	s32 j;
	u8 *ptr = src;
	s32 newoffset = 0;
	s32 type;

	// Start by building the tmpcmd list, but keeping the target pointers NULL
	do {
		type = ptr[0] << 8 | ptr[1];

		cmds[i].type = type;
		cmds[i].oldoffset = ptr - src;
		cmds[i].newoffset = newoffset;
		cmds[i].labelnum = 0xff;
		cmds[i].gotolabelnum = 0xff;
		cmds[i].target = NULL;
		cmds[i].len = g_CommandLengths[type];

		if (type == 0x0002) {
			cmds[i].labelnum = ptr[2];
		} else if (ailistIsGoto(type)) {
			if (type == 0x01c0) {
				cmds[i].gotolabelnum = ptr[2];
			} else {
				cmds[i].gotolabelnum = ptr[cmds[i].len - 1];
			}

			newoffset += cmds[i].len + 1;
		} else {
			newoffset += cmds[i].len;
		}

		ptr += cmds[i].len;
		i++;
	} while (type != CMD_END);

	// Iterate again and populate the target pointers
	for (i = 0; i < numcmds; i++) {
		if (cmds[i].gotolabelnum != 0xff) {
			j = cmds[i].type == 0x0001 ? 0 : i + 1;

			while (j < numcmds) {
				if (cmds[j].labelnum == cmds[i].gotolabelnum) {
					cmds[i].target = &cmds[j];
					break;
				}

				j++;
			}

			if (j == numcmds) {
				// Label wasn't found
				cmds[i].target = &cmds[0];
			}
		}
	}

	// Write the new data
	ptr = dst;

	for (i = 0; i < numcmds; i++) {
		if (cmds[i].labelnum != 0xff) {
			// Label - don't write it
		} else if (cmds[i].type == 0x01c0) {
			// Special goto with label as first param instead of last
			ptr[0] = 0x01;
			ptr[1] = 0xc0;
			ptr[2] = cmds[i].target->newoffset >> 8;
			ptr[3] = cmds[i].target->newoffset & 0xff;
			ptr[4] = src[cmds[i].oldoffset + 3];
			ptr += 5;
		} else if (cmds[i].gotolabelnum != 0xff) {
			// Goto - write it and replace the label with the offset
			for (j = 0; j < cmds[i].len - 1; j++) {
				ptr[j] = src[cmds[i].oldoffset + j];
			}

			ptr += cmds[i].len + 1;
			ptr[-2] = cmds[i].target->newoffset >> 8;
			ptr[-1] = cmds[i].target->newoffset & 0xff;
		} else {
			// Other command - copy it verbatim
			for (j = 0; j < cmds[i].len; j++) {
				ptr[j] = src[cmds[i].oldoffset + j];
			}

			ptr += cmds[i].len;
		}
	}
}

/**
 * Preprocess a single ailist.
 */
u8 *ailistPreprocessList(u8 *ailist, s32 mempool)
{
	s32 numcmds;
	s32 numlabels;
	s32 numgotos;
	s32 oldsize;
	s32 newsize;
	s32 newsizealigned;
	u8 *ptr;
	u8 *scratch;
	struct tmpcmd *tmpcmds;

	// Do the initial pass over the function, counting the number of commands,
	// labels, gotos and also totalling out the byte size of the list.
	ailistAnalyse(ailist, &numcmds, &numlabels, &numgotos, &oldsize);

	// All goto instructions are having one byte added,
	// and all labels (3 bytes each) are being removed.
	newsize = oldsize + numgotos - numlabels * 3;
	newsizealigned = ALIGN4(newsize);

	// Allocate some scratch space where the new list will be built,
	// and some space for a temporary command list.
	ptr = mempAlloc(newsizealigned + numcmds * sizeof(struct tmpcmd), mempool);

	scratch = ptr;
	ptr += newsizealigned;
	tmpcmds = (void *) ptr;

	// Build the new list
	ailistConvert(ailist, scratch, tmpcmds, numcmds);

	if (newsize > oldsize) {
		// It's too big to copy back to its original spot,
		// so the scratch space is now becoming permanent.
		// Free the tmpcmds part by resizing the allocation
		// to the size of the scratch.
		mempRealloc(scratch, newsize, mempool);

		return scratch;
	}

	// Copy it back into its original spot
	bcopy(scratch, ailist, newsize);

	// Free the scratch space and cmds
	mempRealloc(scratch, 0, mempool);

	return NULL;
}

/**
 * What we're doing here is preprocessing ailists to remove all label commands,
 * and replace "goto label"-like statements with "goto offset".
 *
 * This allows the engine to jump directly to an offset in the ailist without
 * having to iterate the commands in the list to find the label.
 *
 * In most cases the converted ailist is smaller than the original and can
 * just overwrite the original data. In a few cases the new ailist is bigger
 * so it must be relocated.
 *
 * This function in particular is processing all ailists in the file
 * (file meaning gailists.c or a stage setup file). The ailist argument is a
 * pointer to the start of the ailist table, usually found near the bottom of
 * the file.
 *
 * Some ailists have multiple entries in the table, so we have to track which
 * ones have been done to prevent doing them twice.
 */
void ailistPreprocessFile(struct ailist *ailist, s32 mempool)
{
	u8 *done[150];
	s32 donelen = 0;
	s32 i;

	// Iterate the ailists in the table
	while (ailist->list) {
		// Check it's not done already
		for (i = 0; i < donelen; i++) {
			if (done[i] == ailist->list) {
				break;
			}
		}

		if (i == donelen) {
			// Convert the list, which might require relocating it in memory
			u8 *newaddr = ailistPreprocessList(ailist->list, mempool);

			if (newaddr) {
				// Update this ailist's pointer to its commands
				// and any future ailists that point to the same commands
				struct ailist *tmp = ailist;

				while (tmp->list) {
					if (tmp->list == ailist->list) {
						tmp->list = newaddr;
					}

					tmp++;
				}
			}

			done[donelen] = ailist->list;
			donelen++;
		}

		ailist++;
	}
}
