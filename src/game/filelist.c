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
#include "lib/fault.h"
#include "lib/joy.h"
#include "lib/snd.h"
#include "lib/mema.h"
#include "data.h"
#include "types.h"

s32 g_FilelistKnownPlugCounts[5];

struct filelist *g_FileLists[MAX_PLAYERS] = { NULL };
bool var80075bd0[] = { true, true, true, true };
bool var80075be0[] = { false, false, false, false };
u32 var80075bf0 = false;

void filelist_update(struct filelist *list);

void func0f110bf0(void)
{
	// empty
}

void func0f110bf8(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_FileLists); i++) {
		if (g_FileLists[i] != NULL) {
			mema_free(g_FileLists[i], align16(sizeof(struct filelist)));
			g_FileLists[i] = NULL;
		}
	}
}

/**
 * Allocate and build a file list.
 */
void filelist_create(s32 listnum, u8 filetype)
{
	if (g_FileLists[listnum] == NULL) {
		bg_garbage_collect_rooms(align16(sizeof(struct filelist)), 1);
		g_FileLists[listnum] = mema_alloc(align16(sizeof(struct filelist)));
	}

	g_FileLists[listnum]->timeuntilupdate = 1;
	g_FileLists[listnum]->filetype = filetype;

	if (var80062944 == 0) {
		joy_set_pfs_poll_interval(3);
	}

	var80062944 = 1;
}

s32 filelist_find_or_create(u8 filetype)
{
	s32 bestindex = -1;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_FileLists); i++) {
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
		filelist_create(bestindex, filetype);
		return bestindex;
	}

	return -1;
}

#if VERSION >= VERSION_NTSC_1_0
void filelist_invalidate_pak(s32 device)
{
	g_FilelistKnownPlugCounts[device] = -1;
}
#endif

void filelists_tick(void)
{
	u32 updateall;
	u32 update;
	s32 i;
	static bool doneinit = false;

	if (!doneinit) {
		for (i = 0; i < ARRAYCOUNT(g_FilelistKnownPlugCounts); i++) {
			g_FilelistKnownPlugCounts[i] = -1;
		}

		doneinit = true;
	}

#if VERSION >= VERSION_NTSC_1_0
	for (i = 0, updateall = false; i < ARRAYCOUNT(g_FilelistKnownPlugCounts); i++) {
		if (pak0f1167d8(i) && pak_get_plug_count(i) != g_FilelistKnownPlugCounts[i]) {
			updateall = true;
			g_FilelistKnownPlugCounts[i] = pak_get_plug_count(i);
		}
	}
#else
	for (i = 0, updateall = false; i < ARRAYCOUNT(g_FilelistKnownPlugCounts); i++) {
		s32 plugcount = pak_get_plug_count(i);

		pak0f11698c(i);

		if (pak0f1167d8(i)) {
			plugcount = 0;
		}

		if (g_FilelistKnownPlugCounts[i] != plugcount) {
			updateall = true;
			g_FilelistKnownPlugCounts[i] = plugcount;
		}
	}
#endif

	for (i = 0; i < ARRAYCOUNT(g_FileLists); i++) {
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
				osSyncPrintf("Rebuilding pakWad %d:\n", i);
				filelist_update(g_FileLists[i]);
				g_FileLists[i]->updatedthisframe = true;
			}
		}
	}

	for (i = 0; i < ARRAYCOUNT(var80075bd0); i++) {
		var80075bd0[i] = false;
	}
}

void filelist_update(struct filelist *list)
{
	const u32 sp3a88[] = {
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
	const s8 dis2dev[] = {
		SAVEDEVICE_GAMEPAK,
		SAVEDEVICE_CONTROLLERPAK1,
		SAVEDEVICE_CONTROLLERPAK2,
		SAVEDEVICE_CONTROLLERPAK3,
		SAVEDEVICE_CONTROLLERPAK4,
	};

	// Mapping of device order to display order
	const s8 dev2dis[] = { 1, 2, 3, 4, /* game pak */ 0 };

	list->numdevices = 0;

	// Iterating in display order (game pak then controller paks)
	for (i = 0, len = 0; i < ARRAYCOUNT(dis2dev); i++) {
		list->unk305[dis2dev[i]] = 0;
		list->devicestartindexes[i] = -1;

		ret = pak_get_file_ids_by_type(dis2dev[i], sp3a88[list->filetype], spa88);

		if (ret == 0) {
			// No error
			for (j = 0; spa88[j] != 0; j++) {
				sp1288[len] = spa88[j];
				filedevices[len] = dis2dev[i];
				len++;
			}

			list->spacesfree[dis2dev[i]] = 0;

			if (list->filetype == FILETYPE_CAMERA) {
				list->spacesfree[dis2dev[i]] = pak_get_num_free_camera_spaces_in_pak(dis2dev[i]);
			}

			list->deviceguids[dis2dev[i]].fileid = 0;
			list->deviceguids[dis2dev[i]].deviceserial = pak_get_serial(dis2dev[i]);
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
		s32 ret = pak_read_body_at_guid(filedevices[i], sp1288[i], file->name, sizeof(file->name));

		if (ret);

		if (ret == 0) {
			// No error
			if (list->devicestartindexes[dev2dis[filedevices[i]]] == -1) {
				list->numdevices++;
				list->devicestartindexes[dev2dis[filedevices[i]]] = list->numfiles;
			}

			file->deviceserial = pak_get_serial(filedevices[i]);
			file->fileid = sp1288[i];

			list->numfiles++;
		} else if (ret == 10) {
			// PFS_ERR_ID_FATAL?
			list->unk305[filedevices[i]]++;

			if (list->unk305[filedevices[i]] >= 2) {
				list->spacesfree[filedevices[i]]++;

				if (list->deviceguids[filedevices[i]].fileid == 0) {
					list->deviceguids[filedevices[i]].fileid = sp1288[i];
					list->deviceguids[filedevices[i]].deviceserial = pak_get_serial(filedevices[i]);
				}
			}
		}
	}
}

void phead_allocate_textures(s32 playernum, struct perfectheadtexturelist *textures)
{
	s32 i;
	s32 j;
	s32 k;

	if (g_Menus[playernum].fm.headtextures == NULL) {
		if (textures == NULL) {
			g_Menus[playernum].fm.unke40_01 = true;
			bg_garbage_collect_rooms(align16(sizeof(struct perfectheadtexturelist)), 1);
			g_Menus[playernum].fm.headtextures = mema_alloc(align16(sizeof(struct perfectheadtexturelist)));
		} else {
			g_Menus[playernum].fm.headtextures = textures;
			g_Menus[playernum].fm.unke40_01 = false;
		}
	}

	if (g_Menus[playernum].fm.headtextures == NULL) {
#if VERSION >= VERSION_NTSC_1_0
		fault_assert("tc != NULL", "gamefile.c", 458);
#else
		fault_assert("tc != NULL", "gamefile.c", 450);
#endif
	}

	for (i = 0; i != ARRAYCOUNT(g_Menus[playernum].fm.headtextures->fileguids); i++) {
		g_Menus[playernum].fm.headtextures->fileguids[i].fileid = 0;
		g_Menus[playernum].fm.headtextures->fileguids[i].deviceserial = 0;
	}

	g_Menus[playernum].fm.headtextures->lastupdated240 = 0;

	g_Menus[playernum].fm.headtextures->selectedtexture.width = 16;
	g_Menus[playernum].fm.headtextures->selectedtexture.height = 16;
	g_Menus[playernum].fm.headtextures->selectedtexture.level = 0;
	g_Menus[playernum].fm.headtextures->selectedtexture.format = G_IM_FMT_I;
	g_Menus[playernum].fm.headtextures->selectedtexture.depth = 0;
	g_Menus[playernum].fm.headtextures->selectedtexture.s = 0;
	g_Menus[playernum].fm.headtextures->selectedtexture.t = 1;
	g_Menus[playernum].fm.headtextures->selectedtexture.unk0b = 0;

	for (j = 0; j < 16; j++) {
		for (k = 0; k < 0x80; k++) {
			g_Menus[playernum].fm.headtextures->unk000[j][k] = k & 0xff;
		}
	}
}

void phead_free_textures(s32 playernum)
{
	if (g_Menus[playernum].fm.headtextures != NULL) {
		if (g_Menus[playernum].fm.unke40_01) {
			mema_free(g_Menus[playernum].fm.headtextures, align16(sizeof(struct perfectheadtexturelist)));
		}

		g_Menus[playernum].fm.headtextures = NULL;
	}
}

struct textureconfig *phead_get_texture(s32 playernum, s32 fileid, u16 deviceserial)
{
	s32 i;
	s32 freeslot = -1;
	s32 indextouse = -1;

	for (i = 0; i < 16; i++) {
		if (g_Menus[playernum].fm.headtextures->fileguids[i].fileid == fileid
				&& g_Menus[playernum].fm.headtextures->fileguids[i].deviceserial == deviceserial) {
			indextouse = i;
			break;
		}

		if (g_Menus[playernum].fm.headtextures->fileguids[i].fileid == 0) {
			if (g_Menus[playernum].fm.headtextures->fileguids[i].deviceserial == 0) {
				freeslot = i;
			}
		}
	}

	if (indextouse == -1) {
		s8 device = pak_find_by_serial(deviceserial);

		if (device < 0) {
			return NULL;
		}

		if (freeslot == -1) {
			return NULL;
		}

		if (g_Vars.thisframestart240 - g_Menus[playernum].fm.headtextures->lastupdated240 < 20) {
			return NULL;
		}

		g_Menus[playernum].fm.headtextures->lastupdated240 = g_Vars.thisframestart240;

		camdraw_get_filemgr_preview(device, fileid, g_Menus[playernum].fm.headtextures->unk000[freeslot]);

		g_Menus[playernum].fm.headtextures->fileguids[freeslot].fileid = fileid;
		g_Menus[playernum].fm.headtextures->fileguids[freeslot].deviceserial = deviceserial;

		indextouse = freeslot;
	}

	if (indextouse == -1) {
		return NULL;
	}

	g_Menus[playernum].fm.headtextures->selectedtexture.textureptr = g_Menus[playernum].fm.headtextures->unk000[indextouse];

	return &g_Menus[playernum].fm.headtextures->selectedtexture;
}
