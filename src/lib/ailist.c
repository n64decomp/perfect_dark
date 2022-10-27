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

u8 g_TopLengths[] = {
	/* 0x00 */ 3,
	/* 0x01 */ 3,
	/* 0x02 */ 3,
	/* 0x03 */ 3,
	/* 0x04 */ 3,
	/* 0x05 */ 3,
	/* 0x06 */ 3,
	/* 0x07 */ 3,
	/* 0x08 */ 7,
	/* 0x09 */ 7,
	/* 0x0a */ 7,
	/* 0x0b */ 7,
	/* 0x0c */ 7,
	/* 0x0d */ 3,
	/* 0x0e */ 3,
	/* 0x0f */ 3,
	/* 0x10 */ 3,
	/* 0x11 */ 4,
	/* 0x12 */ 4,
	/* 0x13 */ 3,
	/* 0x14 */ 4,
	/* 0x15 */ 4,
	/* 0x16 */ 3,
	/* 0x17 */ 4,
	/* 0x18 */ 4,
	/* 0x19 */ 3,
	/* 0x1a */ 3,
	/* 0x1b */ 3,
	/* 0x1c */ 4,
	/* 0x1d */ 4,
	/* 0x1e */ 3,
	/* 0x1f */ 7,
	/* 0x20 */ 3,
	/* 0x21 */ 4,
	/* 0x22 */ 3,
	/* 0x23 */ 3,
	/* 0x24 */ 5,
	/* 0x25 */ 3,
	/* 0x26 */ 3,
	/* 0x27 */ 3,
	/* 0x28 */ 4,
	/* 0x29 */ 6,
	/* 0x2a */ 4,
	/* 0x2b */ 4,
	/* 0x2c */ 5,
	/* 0x2d */ 5,
	/* 0x2e */ 8,
	/* 0x2f */ 8,
	/* 0x30 */ 6,
	/* 0x31 */ 6,
	/* 0x32 */ 7,
	/* 0x33 */ 7,
	/* 0x34 */ 5,
	/* 0x35 */ 4,
	/* 0x36 */ 5,
	/* 0x37 */ 5,
	/* 0x38 */ 5,
	/* 0x39 */ 4,
	/* 0x3a */ 5,
	/* 0x3b */ 5,
	/* 0x3c */ 5,
	/* 0x3d */ 4,
	/* 0x3e */ 4,
	/* 0x3f */ 4,
	/* 0x40 */ 4,
	/* 0x41 */ 4,
	/* 0x42 */ 4,
	/* 0x43 */ 4,
	/* 0x44 */ 4,
	/* 0x45 */ 4,
	/* 0x46 */ 4,
	/* 0x47 */ 4,
	/* 0x48 */ 5,
	/* 0x49 */ 5,
	/* 0x4a */ 9,
	/* 0x4b */ 9,
	/* 0x4c */ 8,
	/* 0x4d */ 7,
	/* 0x4e */ 8,
	/* 0x4f */ 8,
	/* 0x50 */ 6,
	/* 0x51 */ 6,
	/* 0x52 */ 5,
	/* 0x53 */ 5,
	/* 0x54 */ 13,
	/* 0x55 */ 12,
	/* 0x56 */ 10,
	/* 0x57 */ 10,
	/* 0x58 */ 7,
	/* 0x59 */ 4,
	/* 0x5a */ 6,
	/* 0x5b */ 6,
	/* 0x5c */ 3,
	/* 0x5d */ 4,
	/* 0x5e */ 3,
	/* 0x5f */ 6,
	/* 0x60 */ 6,
	/* 0x61 */ 3,
	/* 0x62 */ 8,
	/* 0x63 */ 8,
	/* 0x64 */ 4,
	/* 0x65 */ 4,
	/* 0x66 */ 5,
	/* 0x67 */ 3,
	/* 0x68 */ 3,
	/* 0x69 */ 3,
	/* 0x6a */ 4,
	/* 0x6b */ 4,
	/* 0x6c */ 3,
	/* 0x6d */ 3,
	/* 0x6e */ 4,
	/* 0x6f */ 5,
	/* 0x70 */ 3,
	/* 0x71 */ 4,
	/* 0x72 */ 4,
	/* 0x73 */ 5,
	/* 0x74 */ 4,
	/* 0x75 */ 5,
	/* 0x76 */ 4,
	/* 0x77 */ 5,
	/* 0x78 */ 4,
	/* 0x79 */ 4,
	/* 0x7a */ 4,
	/* 0x7b */ 7,
	/* 0x7c */ 5,
	/* 0x7d */ 4,
	/* 0x7e */ 5,
	/* 0x7f */ 4,
	/* 0x80 */ 4,
	/* 0x81 */ 3,
	/* 0x82 */ 3,
	/* 0x83 */ 4,
	/* 0x84 */ 5,
	/* 0x85 */ 4,
	/* 0x86 */ 3,
	/* 0x87 */ 6,
	/* 0x88 */ 3,
	/* 0x89 */ 4,
	/* 0x8a */ 7,
	/* 0x8b */ 8,
	/* 0x8c */ 6,
	/* 0x8d */ 4,
	/* 0x8e */ 5,
	/* 0x8f */ 3,
	/* 0x90 */ 7,
	/* 0x91 */ 5,
	/* 0x92 */ 3,
	/* 0x93 */ 8,
	/* 0x94 */ 3,
	/* 0x95 */ 2,
	/* 0x96 */ 2,
	/* 0x97 */ 5,
	/* 0x98 */ 5,
	/* 0x99 */ 4,
	/* 0x9a */ 2,
	/* 0x9b */ 2,
	/* 0x9c */ 2,
	/* 0x9d */ 12,
	/* 0x9e */ 8,
	/* 0x9f */ 5,
	/* 0xa0 */ 4,
	/* 0xa1 */ 3,
	/* 0xa2 */ 4,
	/* 0xa3 */ 4,
	/* 0xa4 */ 2,
	/* 0xa5 */ 3,
	/* 0xa6 */ 2,
	/* 0xa7 */ 2,
	/* 0xa8 */ 2,
	/* 0xa9 */ 3,
	/* 0xaa */ 3,
	/* 0xab */ 3,
	/* 0xac */ 4,
	/* 0xad */ 5,
	/* 0xae */ 3,
	/* 0xaf */ 3,
	/* 0xb0 */ 4,
	/* 0xb1 */ 3,
	/* 0xb2 */ 3,
	/* 0xb3 */ 3,
	/* 0xb4 */ 3,
	/* 0xb5 */ 3,
	/* 0xb6 */ 4,
	/* 0xb7 */ 4,
	/* 0xb8 */ 3,
	/* 0xb9 */ 7,
	/* 0xba */ 7,
	/* 0xbb */ 8,
	/* 0xbc */ 8,
	/* 0xbd */ 6,
	/* 0xbe */ 6,
	/* 0xbf */ 6,
	/* 0xc0 */ 6,
	/* 0xc1 */ 7,
	/* 0xc2 */ 7,
	/* 0xc3 */ 7,
	/* 0xc4 */ 7,
	/* 0xc5 */ 7,
	/* 0xc6 */ 7,
	/* 0xc7 */ 3,
	/* 0xc8 */ 4,
	/* 0xc9 */ 4,
	/* 0xca */ 2,
	/* 0xcb */ 2,
	/* 0xcc */ 2,
	/* 0xcd */ 2,
	/* 0xce */ 5,
	/* 0xcf */ 6,
	/* 0xd0 */ 9,
	/* 0xd1 */ 5,
	/* 0xd2 */ 6,
	/* 0xd3 */ 3,
	/* 0xd4 */ 5,
	/* 0xd5 */ 3,
	/* 0xd6 */ 4,
	/* 0xd7 */ 5,
	/* 0xd8 */ 8,
	/* 0xd9 */ 3,
	/* 0xda */ 3,
	/* 0xdb */ 3,
	/* 0xdc */ 3,
	/* 0xdd */ 7,
	/* 0xde */ 7,
	/* 0xdf */ 7,
	/* 0xe0 */ 7,
	/* 0xe1 */ 3,
	/* 0xe2 */ 2,
	/* 0xe3 */ 10,
	/* 0xe4 */ 3,
	/* 0xe5 */ 4,
	/* 0xe6 */ 4,
	/* 0xe7 */ 8,
	/* 0xe8 */ 2,
	/* 0xe9 */ 2,
	/* 0xea */ 3,
	/* 0xeb */ 5,
	/* 0xec */ 3,
	/* 0xed */ 11,
	/* 0xee */ 5,
	/* 0xef */ 4,
	/* 0xf0 */ 5,
	/* 0xf1 */ 4,
	/* 0xf2 */ 2,
	/* 0xf3 */ 3,
	/* 0xf4 */ 6,
	/* 0xf5 */ 3,
	/* 0xf6 */ 5,
	/* 0xf7 */ 4,
	/* 0xf8 */ 4,
	/* 0xf9 */ 4,
	/* 0xfa */ 8,
	/* 0xfb */ 3,
	/* 0xfc */ 3,
	/* 0xfd */ 4,
};

u8 g_SubLengths[] = {
	/* 0x00 */ 3,
	/* 0x01 */ 4,
	/* 0x02 */ 4,
	/* 0x03 */ 4,
	/* 0x04 */ 3,
	/* 0x05 */ 4,
	/* 0x06 */ 4,
	/* 0x07 */ 3,
	/* 0x08 */ 2,
	/* 0x09 */ 2,
	/* 0x0a */ 4,
	/* 0x0b */ 3,
	/* 0x0c */ 3,
	/* 0x0d */ 5,
	/* 0x0e */ 4,
	/* 0x0f */ 3,
	/* 0x10 */ 3,
	/* 0x11 */ 3,
	/* 0x12 */ 2,
	/* 0x13 */ 2,
	/* 0x14 */ 4,
	/* 0x15 */ 2,
	/* 0x16 */ 2,
	/* 0x17 */ 7,
	/* 0x18 */ 3,
	/* 0x19 */ 6,
	/* 0x1a */ 6,
	/* 0x1b */ 2,
	/* 0x1c */ 2,
	/* 0x1d */ 4,
	/* 0x1e */ 4,
	/* 0x1f */ 3,
	/* 0x20 */ 4,
	/* 0x21 */ 3,
	/* 0x22 */ 5,
	/* 0x23 */ 3,
	/* 0x24 */ 3,
	/* 0x25 */ 11,
	/* 0x26 */ 4,
	/* 0x27 */ 4,
	/* 0x28 */ 4,
	/* 0x29 */ 3,
	/* 0x2a */ 9,
	/* 0x2b */ 4,
	/* 0x2c */ 2,
	/* 0x2d */ 3,
	/* 0x2e */ 3,
	/* 0x2f */ 2,
	/* 0x30 */ 10,
	/* 0x31 */ 5,
	/* 0x32 */ 9,
	/* 0x33 */ 3,
	/* 0x34 */ 2,
	/* 0x35 */ 3,
	/* 0x36 */ 2,
	/* 0x37 */ 2,
	/* 0x38 */ 3,
	/* 0x39 */ 4,
	/* 0x3a */ 4,
	/* 0x3b */ 3,
	/* 0x3c */ 3,
	/* 0x3d */ 4,
	/* 0x3e */ 3,
	/* 0x3f */ 3,
	/* 0x40 */ 4,
	/* 0x41 */ 18,
	/* 0x42 */ 3,
	/* 0x43 */ 3,
	/* 0x44 */ 2,
	/* 0x45 */ 5,
	/* 0x46 */ 4,
	/* 0x47 */ 3,
	/* 0x48 */ 5,
	/* 0x49 */ 4,
	/* 0x4a */ 3,
	/* 0x4b */ 4,
	/* 0x4c */ 5,
	/* 0x4d */ 5,
	/* 0x4e */ 5,
	/* 0x4f */ 6,
	/* 0x50 */ 3,
	/* 0x51 */ 6,
	/* 0x52 */ 11,
	/* 0x53 */ 3,
	/* 0x54 */ 3,
	/* 0x55 */ 2,
};

bool ailistIsGoto(u8 major, u8 minor)
{
	if (major == 0xff) {
		return minor <= 0x06;
	} else {
		return major <= 0x93 || major == 0xfd;
	}
}

bool ailistGetLen(u8 major, u8 minor)
{
	if (major == 0xff) {
		return g_SubLengths[minor];
	} else {
		return g_TopLengths[major];
	}
}

void ailistAnalyse(u8 *ailist, s32 *numcmdsptr, s32 *numlabelsptr, s32 *numgotosptr, s32 *oldsizeptr)
{
	s32 numcmds = 0;
	s32 numlabels = 0;
	s32 numgotos = 0;
	u8 *ptr = ailist;
	s32 type;

	do {
		u8 major = ptr[0];
		u8 minor = ptr[1];

		type = major << 8 | minor;

		if (type == CMD_LABEL) {
			numlabels++;
		} else if (ailistIsGoto(major, minor)) {
			numgotos++;
		}

		numcmds++;
		ptr += ailistGetLen(major, minor);
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
		u8 major = ptr[0];
		u8 minor = ptr[1];

		type = major << 8 | minor;

		cmds[i].type = type;
		cmds[i].oldoffset = ptr - src;
		cmds[i].newoffset = newoffset;
		cmds[i].labelnum = 0xff;
		cmds[i].gotolabelnum = 0xff;
		cmds[i].target = NULL;
		cmds[i].len = ailistGetLen(major, minor);

		if (type == CMD_LABEL) {
			cmds[i].labelnum = ptr[2];
		} else if (ailistIsGoto(major, minor)) {
			if (type == 0xff05) {
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
			j = cmds[i].type == CMD_GOTOFIRST ? 0 : i + 1;

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
		} else if (cmds[i].type == 0xff05) {
			// Special goto with label as first param instead of last
			ptr[0] = 0xff;
			ptr[1] = 0x05;
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
