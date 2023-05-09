#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/ceil.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/menugfx.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/inv.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/texdecompress.h"
#include "game/tex.h"
#include "game/modeldef.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

struct skeleton *g_Skeletons[] = {
	&g_SkelChr,
	&g_SkelClassicGun,
	&g_Skel06,
	&g_SkelUzi,
	&g_SkelBasic,
	&g_SkelCctv,
	&g_SkelWindowedDoor,
	&g_Skel11,
	&g_Skel12,
	&g_Skel13,
	&g_SkelTerminal,
	&g_SkelCiHub,
	&g_SkelAutogun,
	&g_Skel17,
	&g_Skel18,
	&g_Skel19,
	&g_Skel0A,
	&g_Skel0B,
	&g_SkelCasing,
	&g_SkelChrGun,
	&g_Skel0C,
	&g_SkelJoypad,
	&g_SkelLift,
	&g_SkelSkedar,
	&g_SkelLogo,
	&g_SkelPdLogo,
	&g_SkelHoverbike,
	&g_SkelJumpship,
	&g_Skel20,
	&g_Skel21,
	&g_Skel22,
	&g_SkelLaptopGun,
	&g_SkelK7Avenger,
	&g_SkelChopper,
	&g_SkelFalcon2,
	&g_SkelKnife,
	&g_SkelDrCaroll,
	&g_SkelRope,
	&g_SkelCmp150,
	&g_SkelBanner,
	&g_SkelDragon,
	&g_SkelSuperDragon,
	&g_SkelRocket,
	&g_Skel4A,
	&g_SkelShotgun,
	&g_SkelFarsight,
	&g_Skel4D,
	&g_SkelReaper,
	&g_SkelDropship,
	&g_SkelMauler,
	&g_SkelDevastator,
	&g_SkelRobot,
	&g_SkelPistol,
	&g_SkelAr34,
	&g_SkelMagnum,
	&g_SkelSlayerRocket,
	&g_SkelCyclone,
	&g_SkelSniperRifle,
	&g_SkelTranquilizer,
	&g_SkelCrossbow,
	&g_SkelHudPiece,
	&g_SkelTimedProxyMine,
	&g_SkelPhoenix,
	&g_SkelCallisto,
	&g_SkelHand,
	&g_SkelRcp120,
	&g_SkelSkShuttle,
	&g_SkelLaser,
	&g_SkelMaianUfo,
	&g_SkelGrenade,
	&g_SkelCableCar,
	&g_SkelSubmarine,
	&g_SkelTarget,
	&g_SkelEcmMine,
	&g_SkelUplink,
	&g_SkelRareLogo,
	&g_SkelWireFence,
	&g_SkelRemoteMine,
	&g_SkelBB,
};

void modeldef0f1a7560(struct modelfiledata *modeldef, u16 filenum, u32 arg2, struct modelfiledata *modeldef2, struct texpool *texpool, bool arg5)
{
	s32 allocsize;
	s32 loadedsize;
	s32 sp84;
	u32 s0;
	u32 s4;
	u32 s5;
	struct modelnode *node;
	struct modelnode *prevnode;
	u32 gdl;
	struct gfxvtx *vertices;

	allocsize = fileGetAllocationSize(filenum);
	loadedsize = fileGetLoadedSize(filenum);
	node = NULL;

	modelIterateDisplayLists(modeldef, &node, (Gfx **)&gdl);

	s5 = gdl;

	if (gdl) {
		s32 v1 = allocsize - (loadedsize - (s32)(((u32)modeldef + (gdl & 0xffffff)) - (u32)modeldef));
		sp84 = (s32)v1 + (s32)((s32)modeldef - ((u32)modeldef + (gdl & 0xffffff)));

		texCopyGdls((Gfx *)((u32)modeldef + (gdl & 0xffffff)), (Gfx *)(v1 + (u32)modeldef), loadedsize - (s32)(((u32)modeldef + (gdl & 0xffffff)) - (u32)modeldef));
		texLoadFromConfigs(modeldef->texconfigs, modeldef->numtexconfigs, texpool, (u32)modeldef2 - arg2);

		while (node) {
			prevnode = node;
			s0 = gdl;

			modelIterateDisplayLists(modeldef, &node, (Gfx **) &gdl);

			if (gdl) {
				s4 = gdl - s0;
			} else {
				s4 = loadedsize + (u32)modeldef - (u32)modeldef - (s0 & 0xffffff);
			}

			modelNodeReplaceGdl(modeldef, prevnode, (Gfx *) s0, (Gfx *) s5);

			if (prevnode->type == MODELNODETYPE_DL) {
				struct modelrodata_dl *rodata = &prevnode->rodata->dl;
				vertices = rodata->vertices;
			} else {
				vertices = NULL;
			}

			s5 += texLoadFromGdl((Gfx *)((u32)modeldef + (s0 & 0xffffff) + sp84), s4, (Gfx *)((u32)modeldef + (s5 & 0xffffff)), texpool, (u8 *) vertices);
		}

		fileSetSize(filenum, modeldef, (((u32)modeldef + (s5 & 0xffffff)) - (u32)modeldef + 0xf) & ~0xf, arg5);
	}
}

void modelPromoteTypeToPointer(struct modelfiledata *filedata)
{
	s32 i;

	if ((u32)filedata->skel < 0x10000) {
		for (i = 0; g_Skeletons[i] != NULL; i++) {
			if ((s16)filedata->skel == g_Skeletons[i]->skel) {
				filedata->skel = g_Skeletons[i];
				return;
			}
		}
	}
}

struct modelfiledata *modeldefLoad(u16 fileid, u8 *dst, s32 size, struct texpool *arg3)
{
	struct modelfiledata *filedata;

	if (dst) {
		filedata = fileLoadToAddr(fileid, FILELOADMETHOD_EXTRAMEM, dst, size);
	} else {
		filedata = fileLoadToNew(fileid, FILELOADMETHOD_EXTRAMEM);
	}

	modelPromoteTypeToPointer(filedata);
	modelPromoteOffsetsToPointers(filedata, 0x5000000, (u32) filedata);
	modeldef0f1a7560(filedata, fileid, 0x5000000, filedata, arg3, dst == NULL);

	return filedata;
}

struct modelfiledata *modeldefLoadToNew(u16 fileid)
{
	return modeldefLoad(fileid, NULL, 0, NULL);
}
