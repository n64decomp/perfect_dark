#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_166e40.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

void stageLoadCommonLang(s32 stagenum)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_LangBanks); i++) {
		g_LangBanks[i] = NULL;
	}

	g_LangBanks[LANGBANK_GUN] = func0f1670fc(langGetFileId(LANGBANK_GUN), 0x22);
	g_LangBanks[LANGBANK_MPMENU] = func0f1670fc(langGetFileId(LANGBANK_MPMENU), 0x22);
	g_LangBanks[LANGBANK_PROPOBJ] = func0f1670fc(langGetFileId(LANGBANK_PROPOBJ), 0x22);
	g_LangBanks[LANGBANK_MPWEAPONS] = func0f1670fc(langGetFileId(LANGBANK_MPWEAPONS), 0x22);
	g_LangBanks[LANGBANK_OPTIONS] = func0f1670fc(langGetFileId(LANGBANK_OPTIONS), 0x22);
	g_LangBanks[LANGBANK_MISC] = func0f1670fc(langGetFileId(LANGBANK_MISC), 0x22);

	if (stagenum == STAGE_CREDITS) {
		g_LangBanks[LANGBANK_TITLE] = func0f1670fc(langGetFileId(LANGBANK_TITLE), 0x22);
	}
}

GLOBAL_ASM(
glabel func0f00b420
/*  f00b420:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00b424:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b428:	3c018006 */ 	lui	$at,%hi(var80062410)
/*  f00b42c:	ac202410 */ 	sw	$zero,%lo(var80062410)($at)
/*  f00b430:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b434:	0c0048f2 */ 	jal	malloc
/*  f00b438:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b43c:	3c01800a */ 	lui	$at,%hi(var8009cc80)
/*  f00b440:	ac22cc80 */ 	sw	$v0,%lo(var8009cc80)($at)
/*  f00b444:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b448:	0c0048f2 */ 	jal	malloc
/*  f00b44c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b450:	3c01800a */ 	lui	$at,%hi(var8009cc84)
/*  f00b454:	ac22cc84 */ 	sw	$v0,%lo(var8009cc84)($at)
/*  f00b458:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b45c:	0c0048f2 */ 	jal	malloc
/*  f00b460:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b464:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b468:	3c01800a */ 	lui	$at,%hi(var8009cc88)
/*  f00b46c:	ac22cc88 */ 	sw	$v0,%lo(var8009cc88)($at)
/*  f00b470:	03e00008 */ 	jr	$ra
/*  f00b474:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00b478:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b47c:	00000000 */ 	sll	$zero,$zero,0x0
);
