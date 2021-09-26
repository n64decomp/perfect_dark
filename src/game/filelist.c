#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/game_0b69d0.h"
#include "game/savebuffer.h"
#include "game/filelist.h"
#include "game/bg.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/lib_0bfb0.h"
#include "lib/snd.h"
#include "lib/lib_126b0.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

s32 var800a2330[5];

struct filelist *g_FileLists[] = { NULL, NULL, NULL, NULL };
bool var80075bd0[] = { true, true, true, true };
bool var80075be0[] = { false, false, false, false };
u32 var80075bf0 = false;

void func0f110bf0(void)
{
	// empty
}

void func0f110bf8(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_FileLists[i] != NULL) {
			func00012cb4(g_FileLists[i], align16(sizeof(struct filelist)));
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
		func0f15e5b8(align16(sizeof(struct filelist)), 1);
		g_FileLists[listnum] = func00012ab0(align16(sizeof(struct filelist)));
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

#if VERSION >= VERSION_NTSC_1_0
void func0f110d90(s32 device)
{
	var800a2330[device] = -1;
}
#endif

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

	i = 0;
	updateall = false;

	for (; i < 5; i++) {
#if VERSION >= VERSION_NTSC_1_0
		if (pak0f1167d8(i) && var800a2330[i] != pakGetUnk264(i)) {
			updateall = true;
			var800a2330[i] = pakGetUnk264(i);
		}
#else
		s32 tmp = pakGetUnk264(i);

		pak0f11698c(i);

		if (pak0f1167d8(i)) {
			tmp = 0;
		}

		if (var800a2330[i] != tmp) {
			updateall = true;
			var800a2330[i] = tmp;
		}
#endif
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
				osSyncPrintf("Rebuilding pakWad %d:\n", i);
				filelistUpdate(g_FileLists[i]);
				g_FileLists[i]->updatedthisframe = true;
			}
		}
	}

	for (i = 0; i < 4; i++) {
		var80075bd0[i] = false;
	}
}

void filelistUpdate(struct filelist *list)
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

GLOBAL_ASM(
glabel pheadAllocateTextures
/*  f111260:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f111264:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f111268:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11126c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f111270:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f111274:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f111278:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11127c:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f111280:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f111284:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f111288:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f11128c:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f111290:	8e030e68 */ 	lw	$v1,0xe68($s0)
/*  f111294:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f111298:	14600017 */ 	bnez	$v1,.L0f1112f8
/*  f11129c:	00000000 */ 	nop
/*  f1112a0:	54a00011 */ 	bnezl	$a1,.L0f1112e8
/*  f1112a4:	92090e40 */ 	lbu	$t1,0xe40($s0)
/*  f1112a8:	92190e40 */ 	lbu	$t9,0xe40($s0)
/*  f1112ac:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f1112b0:	37280040 */ 	ori	$t0,$t9,0x40
/*  f1112b4:	0fc5db69 */ 	jal	align16
/*  f1112b8:	a2080e40 */ 	sb	$t0,0xe40($s0)
/*  f1112bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1112c0:	0fc5796e */ 	jal	func0f15e5b8
/*  f1112c4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1112c8:	0fc5db69 */ 	jal	align16
/*  f1112cc:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f1112d0:	0c004aac */ 	jal	func00012ab0
/*  f1112d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1112d8:	ae020e68 */ 	sw	$v0,0xe68($s0)
/*  f1112dc:	10000006 */ 	b	.L0f1112f8
/*  f1112e0:	00401825 */ 	or	$v1,$v0,$zero
/*  f1112e4:	92090e40 */ 	lbu	$t1,0xe40($s0)
.L0f1112e8:
/*  f1112e8:	ae050e68 */ 	sw	$a1,0xe68($s0)
/*  f1112ec:	00a01825 */ 	or	$v1,$a1,$zero
/*  f1112f0:	312affbf */ 	andi	$t2,$t1,0xffbf
/*  f1112f4:	a20a0e40 */ 	sb	$t2,0xe40($s0)
.L0f1112f8:
/*  f1112f8:	14600006 */ 	bnez	$v1,.L0f111314
/*  f1112fc:	3c047f1b */ 	lui	$a0,%hi(var7f1b3a08)
/*  f111300:	3c057f1b */ 	lui	$a1,%hi(var7f1b3a14)
/*  f111304:	24a53a14 */ 	addiu	$a1,$a1,%lo(var7f1b3a14)
/*  f111308:	24843a08 */ 	addiu	$a0,$a0,%lo(var7f1b3a08)
/*  f11130c:	0c002ff4 */ 	jal	faultAssert
/*  f111310:	240601ca */ 	addiu	$a2,$zero,0x1ca
.L0f111314:
/*  f111314:	00001025 */ 	or	$v0,$zero,$zero
/*  f111318:	24030080 */ 	addiu	$v1,$zero,0x80
.L0f11131c:
/*  f11131c:	8e0b0e68 */ 	lw	$t3,0xe68($s0)
/*  f111320:	01626021 */ 	addu	$t4,$t3,$v0
/*  f111324:	ad800800 */ 	sw	$zero,0x800($t4)
/*  f111328:	8e0d0e68 */ 	lw	$t5,0xe68($s0)
/*  f11132c:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f111330:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f111334:	1443fff9 */ 	bne	$v0,$v1,.L0f11131c
/*  f111338:	a5c00804 */ 	sh	$zero,0x804($t6)
/*  f11133c:	8e0f0e68 */ 	lw	$t7,0xe68($s0)
/*  f111340:	24020010 */ 	addiu	$v0,$zero,0x10
/*  f111344:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f111348:	ade00880 */ 	sw	$zero,0x880($t7)
/*  f11134c:	8e180e68 */ 	lw	$t8,0xe68($s0)
/*  f111350:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f111354:	00001825 */ 	or	$v1,$zero,$zero
/*  f111358:	a3020888 */ 	sb	$v0,0x888($t8)
/*  f11135c:	8e190e68 */ 	lw	$t9,0xe68($s0)
/*  f111360:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f111364:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f111368:	a3220889 */ 	sb	$v0,0x889($t9)
/*  f11136c:	8e080e68 */ 	lw	$t0,0xe68($s0)
/*  f111370:	a100088a */ 	sb	$zero,0x88a($t0)
/*  f111374:	8e0a0e68 */ 	lw	$t2,0xe68($s0)
/*  f111378:	a149088b */ 	sb	$t1,0x88b($t2)
/*  f11137c:	8e0b0e68 */ 	lw	$t3,0xe68($s0)
/*  f111380:	a160088c */ 	sb	$zero,0x88c($t3)
/*  f111384:	8e0c0e68 */ 	lw	$t4,0xe68($s0)
/*  f111388:	a180088d */ 	sb	$zero,0x88d($t4)
/*  f11138c:	8e0e0e68 */ 	lw	$t6,0xe68($s0)
/*  f111390:	a1cd088e */ 	sb	$t5,0x88e($t6)
/*  f111394:	8e0f0e68 */ 	lw	$t7,0xe68($s0)
/*  f111398:	a1e0088f */ 	sb	$zero,0x88f($t7)
/*  f11139c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1113a0:
/*  f1113a0:	8e190e68 */ 	lw	$t9,0xe68($s0)
/*  f1113a4:	000341c0 */ 	sll	$t0,$v1,0x7
/*  f1113a8:	0040c025 */ 	or	$t8,$v0,$zero
/*  f1113ac:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1113b0:	01225021 */ 	addu	$t2,$t1,$v0
/*  f1113b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1113b8:	1444fff9 */ 	bne	$v0,$a0,.L0f1113a0
/*  f1113bc:	a1580000 */ 	sb	$t8,0x0($t2)
/*  f1113c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1113c4:	5465fff6 */ 	bnel	$v1,$a1,.L0f1113a0
/*  f1113c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1113cc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1113d0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1113d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1113d8:	03e00008 */ 	jr	$ra
/*  f1113dc:	00000000 */ 	nop
);

const char var7f1b3a08[] = "tc != NULL";
const char var7f1b3a14[] = "gamefile.c";

// Mismatch: In goal, k loop copies k to t8 then increments k, using t8 for the
// assign. The below uses k and increments it afterwards.
//void pheadAllocateTextures(s32 playernum, struct perfectheadtexturelist *textures)
//{
//	s32 i;
//	s32 j;
//	s32 k;
//
//	if (g_Menus[playernum].headtextures == NULL) {
//		if (textures == NULL) {
//			g_Menus[playernum].fm.unke40_01 = true;
//			func0f15e5b8(align16(sizeof(struct perfectheadtexturelist)), 1);
//			g_Menus[playernum].fm.headtextures = func00012ab0(align16(sizeof(struct perfectheadtexturelist)));
//		} else {
//			g_Menus[playernum].fm.headtextures = textures;
//			g_Menus[playernum].fm.unke40_01 = false;
//		}
//	}
//
//	if (g_Menus[playernum].fm.headtextures == NULL) {
//		faultAssert("tc != NULL", "gamefile.c", 458);
//	}
//
//	for (i = 0; i != ARRAYCOUNT(g_Menus[playernum].headtextures->fileguids); i++) {
//		g_Menus[playernum].fm.headtextures->fileguids[i].fileid = 0;
//		g_Menus[playernum].fm.headtextures->fileguids[i].deviceserial = 0;
//	}
//
//	g_Menus[playernum].fm.headtextures->lastupdated240 = 0;
//
//	g_Menus[playernum].fm.headtextures->selectedtexture.width = 16;
//	g_Menus[playernum].fm.headtextures->selectedtexture.height = 16;
//	g_Menus[playernum].fm.headtextures->selectedtexture.level = 0;
//	g_Menus[playernum].fm.headtextures->selectedtexture.format = G_IM_FMT_I;
//	g_Menus[playernum].fm.headtextures->selectedtexture.depth = 0;
//	g_Menus[playernum].fm.headtextures->selectedtexture.s = 0;
//	g_Menus[playernum].fm.headtextures->selectedtexture.t = 1;
//	g_Menus[playernum].fm.headtextures->selectedtexture.unk0b = 0;
//
//	for (j = 0; j < 16; j++) {
//		for (k = 0; k < 0x80; k++) {
//			g_Menus[playernum].fm.headtextures->unk000[j][k] = k;
//		}
//	}
//}

void pheadFreeTextures(s32 playernum)
{
	if (g_Menus[playernum].fm.headtextures != NULL) {
		if (g_Menus[playernum].fm.unke40_01) {
			func00012cb4(g_Menus[playernum].fm.headtextures, align16(sizeof(struct perfectheadtexturelist)));
		}

		g_Menus[playernum].fm.headtextures = NULL;
	}
}

struct textureconfig *pheadGetTexture(s32 playernum, s32 fileid, u16 deviceserial)
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
		s8 device = pakFindBySerial(deviceserial);

		if (device < 0) {
			return NULL;
		}

		if (freeslot == -1) {
			return NULL;
		}

		if (g_Vars.thisframe240 - g_Menus[playernum].fm.headtextures->lastupdated240 < 20) {
			return NULL;
		}

		g_Menus[playernum].fm.headtextures->lastupdated240 = g_Vars.thisframe240;

		func0f15015c(device, fileid, g_Menus[playernum].fm.headtextures->unk000[freeslot]);

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
