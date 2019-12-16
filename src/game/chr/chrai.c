#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/chr/chrai.h"
#include "library/library_12dc0.h"
#include "library/library_16110.h"

GLOBAL_ASM(
glabel chraiEndList
/*  f04d560:	3c08800a */ 	lui	$t0,%hi(var8009d030)
/*  f04d564:	2508d030 */ 	addiu	$t0,$t0,%lo(var8009d030)
/*  f04d568:	8d020018 */ 	lw	$v0,0x18($t0)
/*  f04d56c:	00a03825 */ 	or	$a3,$a1,$zero
/*  f04d570:	3c198008 */ 	lui	$t9,0x8008
/*  f04d574:	10400013 */ 	beqz	$v0,.L0f04d5c4
/*  f04d578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d57c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f04d580:	00001825 */ 	or	$v1,$zero,$zero
/*  f04d584:	00402825 */ 	or	$a1,$v0,$zero
/*  f04d588:	11c0000e */ 	beqz	$t6,.L0f04d5c4
/*  f04d58c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d590:	8c460000 */ 	lw	$a2,0x0($v0)
.L0f04d594:
/*  f04d594:	54860007 */ 	bnel	$a0,$a2,.L0f04d5b4
/*  f04d598:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f04d59c:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f04d5a0:	8d0f0018 */ 	lw	$t7,0x18($t0)
/*  f04d5a4:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f04d5a8:	03e00008 */ 	jr	$ra
/*  f04d5ac:	8f020004 */ 	lw	$v0,0x4($t8)
/*  f04d5b0:	8ca60008 */ 	lw	$a2,0x8($a1)
.L0f04d5b4:
/*  f04d5b4:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f04d5b8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f04d5bc:	14c0fff5 */ 	bnez	$a2,.L0f04d594
/*  f04d5c0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f04d5c4:
/*  f04d5c4:	8f39ac58 */ 	lw	$t9,-0x53a8($t9)
/*  f04d5c8:	3c098008 */ 	lui	$t1,0x8008
/*  f04d5cc:	2523ac58 */ 	addiu	$v1,$t1,-21416
/*  f04d5d0:	1320000b */ 	beqz	$t9,.L0f04d600
/*  f04d5d4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f04d5d8:	8c620000 */ 	lw	$v0,0x0($v1)
.L0f04d5dc:
/*  f04d5dc:	54820005 */ 	bnel	$a0,$v0,.L0f04d5f4
/*  f04d5e0:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f04d5e4:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f04d5e8:	03e00008 */ 	jr	$ra
/*  f04d5ec:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f04d5f0:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f04d5f4:
/*  f04d5f4:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f04d5f8:	1440fff8 */ 	bnez	$v0,.L0f04d5dc
/*  f04d5fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f04d600:
/*  f04d600:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f04d604:	03e00008 */ 	jr	$ra
/*  f04d608:	00000000 */ 	sll	$zero,$zero,0x0
);

u32 chraiGoToLabel(u8 *ailist, u32 aioffset, u8 label)
{
	do {
		u8 *cmd = aioffset + ailist;
		u32 type = (cmd[0] << 8) + cmd[1];

		if (type == CMD_LABEL) {
			if (label == cmd[2]) {
				return aioffset;
			}
		} else if (type == CMD_END) {
			return 0;
		}

		aioffset += chraiGetCommandLength(ailist, aioffset);
	} while (true);
}

void chraiExecute(void *entity, s32 entity_type)
{
	g_Vars.chrdata = NULL;
	g_Vars.objdata = NULL;
	g_Vars.aicdata = NULL;
	g_Vars.hovdata = NULL;
	g_Vars.ailist = NULL;
	g_Vars.aioffset = 0;

	if (entity_type == 3) {
		g_Vars.chrdata = entity;
	} else if (entity_type == 1) {
		struct defaultobj *obj = entity;

		if (obj->type == 0x27) {
			g_Vars.objdata = entity;
		} else if (obj->type == 0x28) {
			g_Vars.aicdata = entity;
		} else if (obj->type == OBJTYPE_HOVERVEHICLE || obj->type == OBJTYPE_ARMEDVEHICLE) {
			g_Vars.hovdata = entity;
		}
	}

	if (g_Vars.chrdata) {
		g_Vars.ailist = g_Vars.chrdata->ailist;
		g_Vars.aioffset = g_Vars.chrdata->aioffset;
	} else if (g_Vars.objdata) {
		g_Vars.ailist = g_Vars.objdata->ailist;
		g_Vars.aioffset = g_Vars.objdata->aioffset;
	} else if (g_Vars.aicdata) {
		g_Vars.ailist = g_Vars.aicdata->ailist;
		g_Vars.aioffset = g_Vars.aicdata->aioffset;
	} else if (g_Vars.hovdata) {
		g_Vars.ailist = g_Vars.hovdata->ailist;
		g_Vars.aioffset = g_Vars.hovdata->aioffset;
	}

	if (g_Vars.ailist) {
		if (g_Vars.chrdata) {
			func0f04c444(g_Vars.chrdata);
		}

		// Check if the ailist should be switched to a different one
		if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & 0x00200000)) {
			u32 animationmaybe = func0001d13c(g_Vars.chrdata->unk020);
			if (g_Vars.chrdata->aishotlist >= 0
					&& g_Vars.chrdata->cshield <= 0
					&& (0 <= g_Vars.chrdata->damage || g_Vars.chrdata->gungroundpos != NULL)
					&& animationmaybe != 0x269 && animationmaybe != 0x26b && animationmaybe != 0x26a) {
				// Set shot list
				g_Vars.chrdata->chrflags &= ~0x00200000;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishotlist);
				g_Vars.aioffset = 0;
			}
		} else if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & 0x08000000)) {
			g_Vars.chrdata->chrflags &= ~0x08000000;

			if (g_Vars.chrdata->aishootingatmelist >= 0
					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->dodgerating > (u32)random() % 100
					&& chrHasFlag(g_Vars.chrdata, 0x00000400, BANK_1) == 0
					&& chrHasFlag(g_Vars.chrdata, 0x00010000, BANK_0) == 0
					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->actiontype != 8
					&& g_Vars.chrdata->actiontype != 9
					&& g_Vars.chrdata->actiontype != 4
					&& g_Vars.chrdata->actiontype != 5
					&& g_Vars.chrdata->actiontype != 6
					&& g_Vars.chrdata->actiontype != 7
					&& g_Vars.chrdata->actiontype != 10) {
				// Set shooting at me list
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishootingatmelist);
				g_Vars.aioffset = 0;
				g_Vars.chrdata->dodgerating = 0;
			} else {
				// Increase dodge rating
				g_Vars.chrdata->dodgerating *= 2;

				if (g_Vars.chrdata->dodgerating > g_Vars.chrdata->maxdodgerating) {
					g_Vars.chrdata->dodgerating = g_Vars.chrdata->maxdodgerating;
				}
			}
		} else if (g_Vars.chrdata
				&& g_Vars.chrdata->darkroomthing
				&& chrHasFlag(g_Vars.chrdata, 0x00000400, BANK_1) == 0
				&& ailistFindById(g_Vars.chrdata->aidarkroomlist) != g_Vars.chrdata->ailist
				&& g_Vars.unk0004b4 != 0x1c) {
			g_Vars.chrdata->darkroomthing = 0;

			if (g_Vars.chrdata->aidarkroomlist >= 0
					&& g_Vars.chrdata->actiontype != 4
					&& g_Vars.chrdata->actiontype != 5
					&& g_Vars.chrdata->actiontype != 6) {
				// Set darkroom list
				chrSetFlags(g_Vars.chrdata, 0x00000400, BANK_1);
				chrSetFlags(g_Vars.chrdata, 0x10000000, BANK_1);
				g_Vars.chrdata->alertness = 0;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aidarkroomlist);
				g_Vars.aioffset = 0;
			}
		} else {
			// empty
		}

		// Iterate and execute the ailist
		while (g_Vars.ailist) {
			u8 *cmd = g_Vars.aioffset + g_Vars.ailist;
			s32 type = (cmd[0] << 8) + cmd[1];

			if (type >= 0 && type <= 0x1e0) {
				if (g_CommandPointers[type]()) {
					break;
				}
			} else {
				// This is attempting to handle situations where the command
				// type is invalid by passing over them and continuing
				// execution. This would very likely result in a crash though.
				g_Vars.aioffset += chraiGetCommandLength(g_Vars.ailist, g_Vars.aioffset);
			}
		}
	}
}

u32 chraiGetCommandLength(u8 *ailist, u32 aioffset)
{
	u8 *cmd = aioffset + ailist;
	s32 type = (cmd[0] << 8) + cmd[1];

	if (type == CMD_PRINT) {
		u32 pos = aioffset + 2;

		while (ailist[pos] != 0) {
			++pos;
		}

		return (pos - aioffset) + 1;
	}

	if (type >= 0 && type < 0x1e1) {
		return g_CommandLengths[type];
	}

	return 1;
}
