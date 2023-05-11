#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/filelist.h"
#include "game/bg.h"
#include "game/challenge.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/snd.h"
#include "lib/mema.h"
#include "data.h"
#include "types.h"

s32 var800a2330[5];

struct filelist *g_FileLists[] = { NULL, NULL, NULL, NULL };
bool var80075bd0[] = { true, true, true, true };

static void filelistUpdate(struct filelist *list);

void func0f110bf8(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_FileLists[i] != NULL) {
			memaFree(g_FileLists[i], ALIGN16(sizeof(struct filelist)));
			g_FileLists[i] = NULL;
		}
	}
}

/**
 * Allocate and build a file list.
 */
void filelistCreate(s32 listnum, u8 filetype)
{
	if (g_FileLists[listnum] == NULL) {
		g_FileLists[listnum] = memaAlloc(ALIGN16(sizeof(struct filelist)));
	}

	g_FileLists[listnum]->timeuntilupdate = 1;
	g_FileLists[listnum]->filetype = filetype;

	if (var80062944 == 0) {
		joy0001398c(3);
	}

	var80062944 = 1;
}

s32 filelistFindOrCreate(u8 filetype)
{
	s32 bestindex = -1;
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_FileLists[i]) {
			if (g_FileLists[i]->filetype == filetype) {
				return i;
			}
		} else {
			if (bestindex == -1) {
				bestindex = i;
			}
		}
	}

	if (bestindex >= 0) {
		filelistCreate(bestindex, filetype);
		return bestindex;
	}

	return -1;
}

void func0f110d90(s32 device)
{
	var800a2330[device] = -1;
}

void filelistsTick(void)
{
	u32 updateall;
	u32 update;
	s32 i;
	static bool var80075bf4 = false;

	if (!var80075bf4) {
		for (i = 0; i < 5; i++) {
			var800a2330[i] = -1;
		}

		var80075bf4 = true;
	}

	for (i = 0, updateall = false; i < 5; i++) {
		if (pak0f1167d8(i) && var800a2330[i] != pakGetUnk264(i)) {
			updateall = true;
			var800a2330[i] = pakGetUnk264(i);
		}
	}

	for (i = 0; i < 4; i++) {
		if (g_FileLists[i] != NULL) {
			g_FileLists[i]->updatedthisframe = false;

			update = updateall;

			if (g_FileLists[i]->timeuntilupdate > 0) {
				g_FileLists[i]->timeuntilupdate--;

				if (g_FileLists[i]->timeuntilupdate == 0) {
					update = true;
				}
			}

			if (var80075bd0[g_FileLists[i]->filetype]) {
				update = true;
			}

			if (update) {
				filelistUpdate(g_FileLists[i]);
				g_FileLists[i]->updatedthisframe = true;
			}
		}
	}

	for (i = 0; i < 4; i++) {
		var80075bd0[i] = false;
	}
}

static void filelistUpdate(struct filelist *list)
{
	static u32 sp3a88[] = {
		PAKFILETYPE_GAME,
		PAKFILETYPE_MPSETUP,
		PAKFILETYPE_MPPLAYER,
		PAKFILETYPE_CAMERA,
	};

	s32 sp1288[2560];
	u32 spa88[512];
	s8 filedevices[2560];
	s32 i;
	s32 j;
	s32 ret;
	s32 len;

	// Display order means game pak then controller paks
	// Device order means controller paks then game pak (ie. SAVEDEVICE constant order)

	// Mapping of display order to device order
	static s8 dis2dev[] = {
		SAVEDEVICE_GAMEPAK,
		SAVEDEVICE_CONTROLLERPAK1,
		SAVEDEVICE_CONTROLLERPAK2,
		SAVEDEVICE_CONTROLLERPAK3,
		SAVEDEVICE_CONTROLLERPAK4,
	};

	// Mapping of device order to display order
	static s8 dev2dis[] = { 1, 2, 3, 4, /* game pak */ 0 };

	list->numdevices = 0;

	// Iterating in display order (game pak then controller paks)
	for (i = 0, len = 0; i < 5; i++) {
		list->unk305[dis2dev[i]] = 0;
		list->devicestartindexes[i] = -1;

		ret = pakGetFileIdsByType(dis2dev[i], sp3a88[list->filetype], spa88);

		if (ret == 0) {
			// No error
			for (j = 0; spa88[j] != 0; j++) {
				sp1288[len] = spa88[j];
				filedevices[len] = dis2dev[i];
				len++;
			}

			list->spacesfree[dis2dev[i]] = 0;

			if (list->filetype == FILETYPE_CAMERA) {
				list->spacesfree[dis2dev[i]] = pakGetNumFreeCameraSpacesInPak(dis2dev[i]);
			}

			list->deviceguids[dis2dev[i]].fileid = 0;
			list->deviceguids[dis2dev[i]].deviceserial = pakGetSerial(dis2dev[i]);
		} else {
			// PFS error?
			list->spacesfree[dis2dev[i]] = -1;

			if (ret == 13) {
				list->timeuntilupdate = 5;
			}
		}
	}

	if (len);

	list->numfiles = 0;

	// Iterating files
	for (i = 0; i < len; i++) {
		struct filelistfile *file = &list->files[list->numfiles];
		s32 ret = pakReadBodyAtGuid(filedevices[i], sp1288[i], file->name, sizeof(file->name));

		if (ret);

		if (ret == 0) {
			// No error
			if (list->devicestartindexes[dev2dis[filedevices[i]]] == -1) {
				list->numdevices++;
				list->devicestartindexes[dev2dis[filedevices[i]]] = list->numfiles;
			}

			file->deviceserial = pakGetSerial(filedevices[i]);
			file->fileid = sp1288[i];

			list->numfiles++;
		} else if (ret == 10) {
			// PFS_ERR_ID_FATAL?
			list->unk305[filedevices[i]]++;

			if (list->unk305[filedevices[i]] >= 2) {
				list->spacesfree[filedevices[i]]++;

				if (list->deviceguids[filedevices[i]].fileid == 0) {
					list->deviceguids[filedevices[i]].fileid = sp1288[i];
					list->deviceguids[filedevices[i]].deviceserial = pakGetSerial(filedevices[i]);
				}
			}
		}
	}
}
