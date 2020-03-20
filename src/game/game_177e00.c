#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_016100.h"
#include "game/game_0b0420.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_167ae0.h"
#include "game/game_177e00.h"
#include "game/mplayer.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_0d520.h"
#include "lib/lib_13130.h"
#include "types.h"

const char var7f1b7e80[] = "";

GLOBAL_ASM(
glabel menuhandler00177e00
/*  f177e00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f177e04:	1081000c */ 	beq	$a0,$at,.L0f177e38
/*  f177e08:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f177e0c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f177e10:	1081001b */ 	beq	$a0,$at,.L0f177e80
/*  f177e14:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e18:	24010006 */ 	addiu	$at,$zero,0x6
/*  f177e1c:	1081003d */ 	beq	$a0,$at,.L0f177f14
/*  f177e20:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e24:	24010007 */ 	addiu	$at,$zero,0x7
/*  f177e28:	10810053 */ 	beq	$a0,$at,.L0f177f78
/*  f177e2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e30:	10000067 */ 	beqz	$zero,.L0f177fd0
/*  f177e34:	00001025 */ 	or	$v0,$zero,$zero
.L0f177e38:
/*  f177e38:	3c05800b */ 	lui	$a1,%hi(g_MpSetup)
/*  f177e3c:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f177e40:	24a5cb88 */ 	addiu	$a1,$a1,%lo(g_MpSetup)
/*  f177e44:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e48:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177e4c:	94ae0016 */ 	lhu	$t6,0x16($a1)
.L0f177e50:
/*  f177e50:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f177e54:	004fc004 */ 	sllv	$t8,$t7,$v0
/*  f177e58:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f177e5c:	13200004 */ 	beqz	$t9,.L0f177e70
/*  f177e60:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177e64:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f177e68:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f177e6c:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f177e70:
/*  f177e70:	5448fff7 */ 	bnel	$v0,$t0,.L0f177e50
/*  f177e74:	94ae0016 */ 	lhu	$t6,0x16($a1)
/*  f177e78:	10000055 */ 	beqz	$zero,.L0f177fd0
/*  f177e7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f177e80:
/*  f177e80:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x16)
/*  f177e84:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f177e88:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers)
/*  f177e8c:	2529c7b8 */ 	addiu	$t1,$t1,%lo(g_MpPlayers)
/*  f177e90:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f177e94:	9463cb9e */ 	lhu	$v1,%lo(g_MpSetup+0x16)($v1)
/*  f177e98:	00002825 */ 	or	$a1,$zero,$zero
/*  f177e9c:	240c004c */ 	addiu	$t4,$zero,0x4c
/*  f177ea0:	240a00a0 */ 	addiu	$t2,$zero,0xa0
/*  f177ea4:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177ea8:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f177eac:
/*  f177eac:	00aec004 */ 	sllv	$t8,$t6,$a1
/*  f177eb0:	0078c824 */ 	and	$t9,$v1,$t8
/*  f177eb4:	13200011 */ 	beqz	$t9,.L0f177efc
/*  f177eb8:	28a10004 */ 	slti	$at,$a1,0x4
/*  f177ebc:	10200006 */ 	beqz	$at,.L0f177ed8
/*  f177ec0:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f177ec4:	00aa0019 */ 	multu	$a1,$t2
/*  f177ec8:	00006812 */ 	mflo	$t5
/*  f177ecc:	012d3821 */ 	addu	$a3,$t1,$t5
/*  f177ed0:	10000005 */ 	beqz	$zero,.L0f177ee8
/*  f177ed4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f177ed8:
/*  f177ed8:	00ac0019 */ 	multu	$a1,$t4
/*  f177edc:	00007812 */ 	mflo	$t7
/*  f177ee0:	016f3821 */ 	addu	$a3,$t3,$t7
/*  f177ee4:	24e7fed0 */ 	addiu	$a3,$a3,-304
.L0f177ee8:
/*  f177ee8:	54440004 */ 	bnel	$v0,$a0,.L0f177efc
/*  f177eec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177ef0:	03e00008 */ 	jr	$ra
/*  f177ef4:	00e01025 */ 	or	$v0,$a3,$zero
/*  f177ef8:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f177efc:
/*  f177efc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f177f00:	54a8ffea */ 	bnel	$a1,$t0,.L0f177eac
/*  f177f04:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f177f08:	3c027f1b */ 	lui	$v0,%hi(var7f1b7e80)
/*  f177f0c:	03e00008 */ 	jr	$ra
/*  f177f10:	24427e80 */ 	addiu	$v0,$v0,%lo(var7f1b7e80)
.L0f177f14:
/*  f177f14:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x16)
/*  f177f18:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f177f1c:	3c07800a */ 	lui	$a3,%hi(var8009deb0)
/*  f177f20:	24e7deb0 */ 	addiu	$a3,$a3,%lo(var8009deb0)
/*  f177f24:	25291448 */ 	addiu	$t1,$t1,%lo(g_MpPlayerNum)
/*  f177f28:	9463cb9e */ 	lhu	$v1,%lo(g_MpSetup+0x16)($v1)
/*  f177f2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f177f30:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177f34:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f177f38:
/*  f177f38:	00aec004 */ 	sllv	$t8,$t6,$a1
/*  f177f3c:	0078c824 */ 	and	$t9,$v1,$t8
/*  f177f40:	53200009 */ 	beqzl	$t9,.L0f177f68
/*  f177f44:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f177f48:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f177f4c:	54440005 */ 	bnel	$v0,$a0,.L0f177f64
/*  f177f50:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177f54:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f177f58:	00ed7821 */ 	addu	$t7,$a3,$t5
/*  f177f5c:	a1e50000 */ 	sb	$a1,0x0($t7)
/*  f177f60:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f177f64:
/*  f177f64:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f177f68:
/*  f177f68:	54a8fff3 */ 	bnel	$a1,$t0,.L0f177f38
/*  f177f6c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f177f70:	10000017 */ 	beqz	$zero,.L0f177fd0
/*  f177f74:	00001025 */ 	or	$v0,$zero,$zero
.L0f177f78:
/*  f177f78:	3c05800b */ 	lui	$a1,%hi(g_MpSetup)
/*  f177f7c:	24a5cb88 */ 	addiu	$a1,$a1,%lo(g_MpSetup)
/*  f177f80:	00001825 */ 	or	$v1,$zero,$zero
/*  f177f84:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177f88:	94ae0016 */ 	lhu	$t6,0x16($a1)
.L0f177f8c:
/*  f177f8c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f177f90:	0078c804 */ 	sllv	$t9,$t8,$v1
/*  f177f94:	01d96824 */ 	and	$t5,$t6,$t9
/*  f177f98:	11a00009 */ 	beqz	$t5,.L0f177fc0
/*  f177f9c:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f177fa0:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f177fa4:	3c04800a */ 	lui	$a0,%hi(var8009deb0)
/*  f177fa8:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f177fac:	9084deb0 */ 	lbu	$a0,%lo(var8009deb0)($a0)
/*  f177fb0:	54640003 */ 	bnel	$v1,$a0,.L0f177fc0
/*  f177fb4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177fb8:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f177fbc:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f177fc0:
/*  f177fc0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177fc4:	5468fff1 */ 	bnel	$v1,$t0,.L0f177f8c
/*  f177fc8:	94ae0016 */ 	lhu	$t6,0x16($a1)
/*  f177fcc:	00001025 */ 	or	$v0,$zero,$zero
.L0f177fd0:
/*  f177fd0:	03e00008 */ 	jr	$ra
/*  f177fd4:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpEndGame(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_Vars.currentplayer->aborted = true;
		func0000e684();
	}

	return 0;
}

/**
 * This is something near the top of the "End Game" dialog during gameplay.
 */
s32 menuhandler00178018(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetup.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

char *mpMenuTextInGameLimit(struct menu_item *item)
{
	*g_StringPointer = 0;

	switch (item->param) {
	case 0:
		sprintf(g_StringPointer, langGet(L_MPMENU(114)), g_MpSetup.timelimit + 1);
		break;
	case 1:
		sprintf(g_StringPointer, langGet(L_MPMENU(113)), g_MpSetup.scorelimit + 1);
		break;
	case 2:
		sprintf(g_StringPointer, langGet(L_MPMENU(113)), func0f18844c() + 1);
		break;
	}

	return g_StringPointer;
}

s32 menuhandlerMpInGameLimitLabel(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		switch (item->param) {
		case 0: if (g_MpSetup.timelimit == 60) return true; break;
		case 1: if (g_MpSetup.scorelimit == 100) return true; break;
		case 2: if (g_MpSetup.teamscorelimit == 400) return true; break;
		}
	}

	return 0;
}

s32 menuhandlerMpPause(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (mpIsPaused()) {
			mpSetPaused(false);
		} else {
			mpSetPaused(true);
		}
	}

	if (operation == MENUOP_CHECKHIDDEN) {
		if (PLAYERCOUNT() == 1) {
			return true;
		}
	}

	if (operation == MENUOP_CHECKPREFOCUSED) {
		if (item->param == 1) {
			return true;
		}
	}

	return 0;
}

char *menutextPauseOrUnpause(s32 arg0)
{
	if (mpIsPaused()) {
		return langGet(L_MPMENU(289)); // "Unpause"
	}

	return langGet(L_MPMENU(288)); // "Pause"
}

char *menutextMatchTime(s32 arg0)
{
	formatTime(g_StringPointer, mpGetTimeElapsed(), 3);
	return g_StringPointer;
}

char *mpMenuTextWeaponDescription(struct menu_item *item)
{
	struct weapon *weapon = weaponFindById(g_MenuStack[g_MpPlayerNum].unke28);

	if (weapon) {
		return langGet(weapon->description);
	}

	return "\n";
}

GLOBAL_ASM(
glabel func0f1783a0
/*  f1783a0:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f1783a4:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f1783a8:	3c02800a */ 	lui	$v0,%hi(var8009deb0)
/*  f1783ac:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1783b0:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f1783b4:	9042deb0 */ 	lbu	$v0,%lo(var8009deb0)($v0)
/*  f1783b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1783bc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1783c0:	28410004 */ 	slti	$at,$v0,0x4
/*  f1783c4:	10200008 */ 	beqz	$at,.L0f1783e8
/*  f1783c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f1783cc:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1783d0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f1783d4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f1783d8:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f1783dc:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f1783e0:	1000000a */ 	beqz	$zero,.L0f17840c
/*  f1783e4:	01f83021 */ 	addu	$a2,$t7,$t8
.L0f1783e8:
/*  f1783e8:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1783ec:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f1783f0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1783f4:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f1783f8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1783fc:	3c09800b */ 	lui	$t1,%hi(g_MpSimulants)
/*  f178400:	2529c538 */ 	addiu	$t1,$t1,%lo(g_MpSimulants)
/*  f178404:	2728fed0 */ 	addiu	$t0,$t9,-304
/*  f178408:	01093021 */ 	addu	$a2,$t0,$t1
.L0f17840c:
/*  f17840c:	24045118 */ 	addiu	$a0,$zero,0x5118
/*  f178410:	0fc5b9f1 */ 	jal	langGet
/*  f178414:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f178418:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f17841c:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f178420:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f178424:	0c004dad */ 	jal	sprintf
/*  f178428:	00402825 */ 	or	$a1,$v0,$zero
/*  f17842c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178430:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f178434:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
/*  f178438:	03e00008 */ 	jr	$ra
/*  f17843c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f178440:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f178444:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f178448:	03e00008 */ 	jr	$ra
/*  f17844c:	00001025 */ 	or	$v0,$zero,$zero
);

char *mpMenuTextWeaponOfChoiceName(struct menu_item *item)
{
	return mpPlayerGetWeaponOfChoiceName(g_MenuStack[g_MpPlayerNum].playernum, 0);
}

char *mpMenuTextAward1(struct menu_item *item)
{
	return g_Vars.players[g_MenuStack[g_MpPlayerNum].playernum]->award1;
}

char *mpMenuTextAward2(struct menu_item *item)
{
	return g_Vars.players[g_MenuStack[g_MpPlayerNum].playernum]->award2;
}

char *mpMenuTextScorePositionWithSuffix(struct menu_item *item)
{
	u16 suffixes[12] = g_OrdinalSuffixes;

	return langGet(suffixes[g_MpPlayers[g_MpPlayerNum].base.scoreposition]);
}

GLOBAL_ASM(
glabel menuhandler001785c4
/*  f1785c4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1785c8:	24010016 */ 	addiu	$at,$zero,0x16
/*  f1785cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1785d0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1785d4:	1481003b */ 	bne	$a0,$at,.L0f1786c4
/*  f1785d8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1785dc:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f1785e0:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f1785e4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers+0x1e)
/*  f1785e8:	3c014220 */ 	lui	$at,0x4220
/*  f1785ec:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1785f0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1785f4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f1785f8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1785fc:	8318c7d6 */ 	lb	$t8,%lo(g_MpPlayers+0x1e)($t8)
/*  f178600:	57000031 */ 	bnezl	$t8,.L0f1786c8
/*  f178604:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178608:	44816000 */ 	mtc1	$at,$f12
/*  f17860c:	0fc01ac2 */ 	jal	func0f006b08
/*  f178610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178614:	3c01437f */ 	lui	$at,0x437f
/*  f178618:	44812000 */ 	mtc1	$at,$f4
/*  f17861c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178620:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f178624:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f178628:	3c05ffff */ 	lui	$a1,0xffff
/*  f17862c:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f178630:	3c014f00 */ 	lui	$at,0x4f00
/*  f178634:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f178638:	4448f800 */ 	cfc1	$t0,$31
/*  f17863c:	44c6f800 */ 	ctc1	$a2,$31
/*  f178640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178644:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f178648:	4446f800 */ 	cfc1	$a2,$31
/*  f17864c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178650:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178654:	50c00013 */ 	beqzl	$a2,.L0f1786a4
/*  f178658:	44064000 */ 	mfc1	$a2,$f8
/*  f17865c:	44814000 */ 	mtc1	$at,$f8
/*  f178660:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178664:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f178668:	44c6f800 */ 	ctc1	$a2,$31
/*  f17866c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178670:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f178674:	4446f800 */ 	cfc1	$a2,$31
/*  f178678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17867c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178680:	14c00005 */ 	bnez	$a2,.L0f178698
/*  f178684:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178688:	44064000 */ 	mfc1	$a2,$f8
/*  f17868c:	3c018000 */ 	lui	$at,0x8000
/*  f178690:	10000007 */ 	beqz	$zero,.L0f1786b0
/*  f178694:	00c13025 */ 	or	$a2,$a2,$at
.L0f178698:
/*  f178698:	10000005 */ 	beqz	$zero,.L0f1786b0
/*  f17869c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1786a0:	44064000 */ 	mfc1	$a2,$f8
.L0f1786a4:
/*  f1786a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1786a8:	04c0fffb */ 	bltz	$a2,.L0f178698
/*  f1786ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1786b0:
/*  f1786b0:	44c8f800 */ 	ctc1	$t0,$31
/*  f1786b4:	0fc01a40 */ 	jal	func0f006900
/*  f1786b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1786bc:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f1786c0:	ad220004 */ 	sw	$v0,0x4($t1)
.L0f1786c4:
/*  f1786c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1786c8:
/*  f1786c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1786cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1786d0:	03e00008 */ 	jr	$ra
/*  f1786d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler001786d8
/*  f1786d8:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1786dc:	24010013 */ 	addiu	$at,$zero,0x13
/*  f1786e0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f1786e4:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f1786e8:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f1786ec:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f1786f0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f1786f4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f1786f8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f1786fc:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f178700:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f178704:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f178708:	148100d5 */ 	bne	$a0,$at,.L0f178a60
/*  f17870c:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f178710:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f178714:	3c1e8007 */ 	lui	$s8,%hi(g_MpPlayerNum)
/*  f178718:	3c17800b */ 	lui	$s7,%hi(g_MpPlayers)
/*  f17871c:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f178720:	8cd50008 */ 	lw	$s5,0x8($a2)
/*  f178724:	3c14ba00 */ 	lui	$s4,0xba00
/*  f178728:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f17872c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f178730:	8eb80008 */ 	lw	$t8,0x8($s5)
/*  f178734:	0000b025 */ 	or	$s6,$zero,$zero
/*  f178738:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f17873c:	01f89021 */ 	addu	$s2,$t7,$t8
/*  f178740:	2652fff1 */ 	addiu	$s2,$s2,-15
/*  f178744:	36940c02 */ 	ori	$s4,$s4,0xc02
/*  f178748:	26f7c7b8 */ 	addiu	$s7,$s7,%lo(g_MpPlayers)
/*  f17874c:	27de1448 */ 	addiu	$s8,$s8,%lo(g_MpPlayerNum)
/*  f178750:	00008025 */ 	or	$s0,$zero,$zero
/*  f178754:	8fb10090 */ 	lw	$s1,0x90($sp)
/*  f178758:	8fd90000 */ 	lw	$t9,0x0($s8)
.L0f17875c:
/*  f17875c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f178760:	020b6004 */ 	sllv	$t4,$t3,$s0
/*  f178764:	00194080 */ 	sll	$t0,$t9,0x2
/*  f178768:	01194021 */ 	addu	$t0,$t0,$t9
/*  f17876c:	00084140 */ 	sll	$t0,$t0,0x5
/*  f178770:	02e84821 */ 	addu	$t1,$s7,$t0
/*  f178774:	912a0094 */ 	lbu	$t2,0x94($t1)
/*  f178778:	014c6824 */ 	and	$t5,$t2,$t4
/*  f17877c:	51a000b2 */ 	beqzl	$t5,.L0f178a48
/*  f178780:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f178784:	12000009 */ 	beqz	$s0,.L0f1787ac
/*  f178788:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17878c:	1201000a */ 	beq	$s0,$at,.L0f1787b8
/*  f178790:	24010002 */ 	addiu	$at,$zero,0x2
/*  f178794:	1201000b */ 	beq	$s0,$at,.L0f1787c4
/*  f178798:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17879c:	5201000d */ 	beql	$s0,$at,.L0f1787d4
/*  f1787a0:	3c1100bf */ 	lui	$s1,0xbf
/*  f1787a4:	1000000c */ 	beqz	$zero,.L0f1787d8
/*  f1787a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1787ac:
/*  f1787ac:	3c11ff7f */ 	lui	$s1,0xff7f
/*  f1787b0:	10000009 */ 	beqz	$zero,.L0f1787d8
/*  f1787b4:	36317fff */ 	ori	$s1,$s1,0x7fff
.L0f1787b8:
/*  f1787b8:	3c11bfbf */ 	lui	$s1,0xbfbf
/*  f1787bc:	10000006 */ 	beqz	$zero,.L0f1787d8
/*  f1787c0:	363100ff */ 	ori	$s1,$s1,0xff
.L0f1787c4:
/*  f1787c4:	3c1100ff */ 	lui	$s1,0xff
/*  f1787c8:	10000003 */ 	beqz	$zero,.L0f1787d8
/*  f1787cc:	363100ff */ 	ori	$s1,$s1,0xff
/*  f1787d0:	3c1100bf */ 	lui	$s1,0xbf
.L0f1787d4:
/*  f1787d4:	3631bfff */ 	ori	$s1,$s1,0xbfff
.L0f1787d8:
/*  f1787d8:	16c00053 */ 	bnez	$s6,.L0f178928
/*  f1787dc:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1787e0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1787e4:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1787e8:	3c18e700 */ 	lui	$t8,0xe700
/*  f1787ec:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1787f0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1787f4:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1787f8:	3c09ba00 */ 	lui	$t1,0xba00
/*  f1787fc:	35291301 */ 	ori	$t1,$t1,0x1301
/*  f178800:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f178804:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f178808:	af200004 */ 	sw	$zero,0x4($t9)
/*  f17880c:	af290000 */ 	sw	$t1,0x0($t9)
/*  f178810:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f178814:	3c0cb900 */ 	lui	$t4,0xb900
/*  f178818:	358c0002 */ 	ori	$t4,$t4,0x2
/*  f17881c:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f178820:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f178824:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f178828:	ad6c0000 */ 	sw	$t4,0x0($t3)
/*  f17882c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f178830:	3c0fba00 */ 	lui	$t7,0xba00
/*  f178834:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f178838:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17883c:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f178840:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f178844:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f178848:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*  f17884c:	3c08ba00 */ 	lui	$t0,0xba00
/*  f178850:	35080903 */ 	ori	$t0,$t0,0x903
/*  f178854:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f178858:	afb900a4 */ 	sw	$t9,0xa4($sp)
/*  f17885c:	24090c00 */ 	addiu	$t1,$zero,0xc00
/*  f178860:	af090004 */ 	sw	$t1,0x4($t8)
/*  f178864:	af080000 */ 	sw	$t0,0x0($t8)
/*  f178868:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f17886c:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f178870:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f178874:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f178878:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f17887c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f178880:	ad740000 */ 	sw	$s4,0x0($t3)
/*  f178884:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f178888:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f17888c:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f178890:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f178894:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f178898:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f17889c:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f1788a0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1788a4:	00003825 */ 	or	$a3,$zero,$zero
/*  f1788a8:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1788ac:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f1788b0:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1788b4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1788b8:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f1788bc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1788c0:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1788c4:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1788c8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1788cc:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1788d0:	3c09fcff */ 	lui	$t1,0xfcff
/*  f1788d4:	3c0bfffc */ 	lui	$t3,0xfffc
/*  f1788d8:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f1788dc:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f1788e0:	356bf279 */ 	ori	$t3,$t3,0xf279
/*  f1788e4:	3529ffff */ 	ori	$t1,$t1,0xffff
/*  f1788e8:	af290000 */ 	sw	$t1,0x0($t9)
/*  f1788ec:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f1788f0:	8faa00a4 */ 	lw	$t2,0xa4($sp)
/*  f1788f4:	3c18ff37 */ 	lui	$t8,0xff37
/*  f1788f8:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f1788fc:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f178900:	afac00a4 */ 	sw	$t4,0xa4($sp)
/*  f178904:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f178908:	ad540000 */ 	sw	$s4,0x0($t2)
/*  f17890c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f178910:	35ef9a25 */ 	ori	$t7,$t7,0x9a25
/*  f178914:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f178918:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17891c:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f178920:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f178924:	adaf0000 */ 	sw	$t7,0x0($t5)
.L0f178928:
/*  f178928:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f17892c:	3c09fb00 */ 	lui	$t1,0xfb00
/*  f178930:	264c000b */ 	addiu	$t4,$s2,0xb
/*  f178934:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f178938:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f17893c:	af310004 */ 	sw	$s1,0x4($t9)
/*  f178940:	af290000 */ 	sw	$t1,0x0($t9)
/*  f178944:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f178948:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f17894c:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f178950:	01ae0019 */ 	multu	$t5,$t6
/*  f178954:	03201025 */ 	or	$v0,$t9,$zero
/*  f178958:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f17895c:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f178960:	8ea90004 */ 	lw	$t1,0x4($s5)
/*  f178964:	01601825 */ 	or	$v1,$t3,$zero
/*  f178968:	3c01e400 */ 	lui	$at,0xe400
/*  f17896c:	252b0009 */ 	addiu	$t3,$t1,0x9
/*  f178970:	000b5080 */ 	sll	$t2,$t3,0x2
/*  f178974:	314c0fff */ 	andi	$t4,$t2,0xfff
/*  f178978:	00007812 */ 	mflo	$t7
/*  f17897c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f178980:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f178984:	03214025 */ 	or	$t0,$t9,$at
/*  f178988:	010c6825 */ 	or	$t5,$t0,$t4
/*  f17898c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f178990:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f178994:	00127080 */ 	sll	$t6,$s2,0x2
/*  f178998:	8eab0004 */ 	lw	$t3,0x4($s5)
/*  f17899c:	01cf0019 */ 	multu	$t6,$t7
/*  f1789a0:	2652fff2 */ 	addiu	$s2,$s2,-14
/*  f1789a4:	256afffe */ 	addiu	$t2,$t3,-2
/*  f1789a8:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f1789ac:	310c0fff */ 	andi	$t4,$t0,0xfff
/*  f1789b0:	3c08b300 */ 	lui	$t0,0xb300
/*  f1789b4:	0000c012 */ 	mflo	$t8
/*  f1789b8:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f1789bc:	00194b00 */ 	sll	$t1,$t9,0xc
/*  f1789c0:	012c6825 */ 	or	$t5,$t1,$t4
/*  f1789c4:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f1789c8:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1789cc:	3c190010 */ 	lui	$t9,0x10
/*  f1789d0:	37390150 */ 	ori	$t9,$t9,0x150
/*  f1789d4:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1789d8:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1789dc:	3c18b400 */ 	lui	$t8,0xb400
/*  f1789e0:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1789e4:	add90004 */ 	sw	$t9,0x4($t6)
/*  f1789e8:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f1789ec:	240c0400 */ 	addiu	$t4,$zero,0x400
/*  f1789f0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1789f4:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f1789f8:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f1789fc:	ad680000 */ 	sw	$t0,0x0($t3)
/*  f178a00:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f178a04:	01602825 */ 	or	$a1,$t3,$zero
/*  f178a08:	0189001a */ 	div	$zero,$t4,$t1
/*  f178a0c:	00006812 */ 	mflo	$t5
/*  f178a10:	31aeffff */ 	andi	$t6,$t5,0xffff
/*  f178a14:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f178a18:	35f8fc00 */ 	ori	$t8,$t7,0xfc00
/*  f178a1c:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f178a20:	15200002 */ 	bnez	$t1,.L0f178a2c
/*  f178a24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178a28:	0007000d */ 	break	0x7
.L0f178a2c:
/*  f178a2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f178a30:	15210004 */ 	bne	$t1,$at,.L0f178a44
/*  f178a34:	3c018000 */ 	lui	$at,0x8000
/*  f178a38:	15810002 */ 	bne	$t4,$at,.L0f178a44
/*  f178a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178a40:	0006000d */ 	break	0x6
.L0f178a44:
/*  f178a44:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f178a48:
/*  f178a48:	24010004 */ 	addiu	$at,$zero,0x4
/*  f178a4c:	5601ff43 */ 	bnel	$s0,$at,.L0f17875c
/*  f178a50:	8fd90000 */ 	lw	$t9,0x0($s8)
/*  f178a54:	afb10090 */ 	sw	$s1,0x90($sp)
/*  f178a58:	10000002 */ 	beqz	$zero,.L0f178a64
/*  f178a5c:	8fa200a4 */ 	lw	$v0,0xa4($sp)
.L0f178a60:
/*  f178a60:	00001025 */ 	or	$v0,$zero,$zero
.L0f178a64:
/*  f178a64:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f178a68:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f178a6c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f178a70:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f178a74:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f178a78:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f178a7c:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f178a80:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f178a84:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f178a88:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f178a8c:	03e00008 */ 	jr	$ra
/*  f178a90:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

GLOBAL_ASM(
glabel menuhandler00178a94
/*  f178a94:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f178a98:	24010016 */ 	addiu	$at,$zero,0x16
/*  f178a9c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178aa0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f178aa4:	1481003d */ 	bne	$a0,$at,.L0f178b9c
/*  f178aa8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f178aac:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f178ab0:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f178ab4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f178ab8:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f178abc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f178ac0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f178ac4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f178ac8:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f178acc:	90590095 */ 	lbu	$t9,0x95($v0)
/*  f178ad0:	90480096 */ 	lbu	$t0,0x96($v0)
/*  f178ad4:	3c014220 */ 	lui	$at,0x4220
/*  f178ad8:	53280031 */ 	beql	$t9,$t0,.L0f178ba0
/*  f178adc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178ae0:	44816000 */ 	mtc1	$at,$f12
/*  f178ae4:	0fc01ac2 */ 	jal	func0f006b08
/*  f178ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178aec:	3c01437f */ 	lui	$at,0x437f
/*  f178af0:	44812000 */ 	mtc1	$at,$f4
/*  f178af4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178af8:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f178afc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f178b00:	3c05ffff */ 	lui	$a1,0xffff
/*  f178b04:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f178b08:	3c014f00 */ 	lui	$at,0x4f00
/*  f178b0c:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f178b10:	444af800 */ 	cfc1	$t2,$31
/*  f178b14:	44c6f800 */ 	ctc1	$a2,$31
/*  f178b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b1c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f178b20:	4446f800 */ 	cfc1	$a2,$31
/*  f178b24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b28:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178b2c:	50c00013 */ 	beqzl	$a2,.L0f178b7c
/*  f178b30:	44064000 */ 	mfc1	$a2,$f8
/*  f178b34:	44814000 */ 	mtc1	$at,$f8
/*  f178b38:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178b3c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f178b40:	44c6f800 */ 	ctc1	$a2,$31
/*  f178b44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b48:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f178b4c:	4446f800 */ 	cfc1	$a2,$31
/*  f178b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b54:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178b58:	14c00005 */ 	bnez	$a2,.L0f178b70
/*  f178b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b60:	44064000 */ 	mfc1	$a2,$f8
/*  f178b64:	3c018000 */ 	lui	$at,0x8000
/*  f178b68:	10000007 */ 	beqz	$zero,.L0f178b88
/*  f178b6c:	00c13025 */ 	or	$a2,$a2,$at
.L0f178b70:
/*  f178b70:	10000005 */ 	beqz	$zero,.L0f178b88
/*  f178b74:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f178b78:	44064000 */ 	mfc1	$a2,$f8
.L0f178b7c:
/*  f178b7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b80:	04c0fffb */ 	bltz	$a2,.L0f178b70
/*  f178b84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178b88:
/*  f178b88:	44caf800 */ 	ctc1	$t2,$31
/*  f178b8c:	0fc01a40 */ 	jal	func0f006900
/*  f178b90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b94:	8fab0020 */ 	lw	$t3,0x20($sp)
/*  f178b98:	ad620004 */ 	sw	$v0,0x4($t3)
.L0f178b9c:
/*  f178b9c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178ba0:
/*  f178ba0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178ba4:	00001025 */ 	or	$v0,$zero,$zero
/*  f178ba8:	03e00008 */ 	jr	$ra
/*  f178bac:	00000000 */ 	sll	$zero,$zero,0x0
);

char *mpMenuTextPlayerTitle(s32 arg0)
{
	return langGet(L_MISC(185) + g_MpPlayers[g_MpPlayerNum].title);
}

GLOBAL_ASM(
glabel menuhandler00178bf4
/*  f178bf4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f178bf8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178bfc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f178c00:	24010006 */ 	addiu	$at,$zero,0x6
/*  f178c04:	10810065 */ 	beq	$a0,$at,.L0f178d9c
/*  f178c08:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f178c0c:	24010011 */ 	addiu	$at,$zero,0x11
/*  f178c10:	10810006 */ 	beq	$a0,$at,.L0f178c2c
/*  f178c14:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f178c18:	24010012 */ 	addiu	$at,$zero,0x12
/*  f178c1c:	10810033 */ 	beq	$a0,$at,.L0f178cec
/*  f178c20:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f178c24:	10000061 */ 	beqz	$zero,.L0f178dac
/*  f178c28:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178c2c:
/*  f178c2c:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f178c30:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f178c34:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f178c38:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f178c3c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f178c40:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f178c44:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f178c48:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f178c4c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f178c50:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f178c54:	00001825 */ 	or	$v1,$zero,$zero
/*  f178c58:	1138001a */ 	beq	$t1,$t8,.L0f178cc4
/*  f178c5c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f178c60:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f178c64:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f178c68:	00f92821 */ 	addu	$a1,$a3,$t9
/*  f178c6c:	90ab0000 */ 	lbu	$t3,0x0($a1)
/*  f178c70:	01401021 */ 	addu	$v0,$t2,$zero
/*  f178c74:	2406000b */ 	addiu	$a2,$zero,0xb
/*  f178c78:	51600013 */ 	beqzl	$t3,.L0f178cc8
/*  f178c7c:	2861000b */ 	slti	$at,$v1,0xb
/*  f178c80:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f178c84:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f178c88:
/*  f178c88:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f178c8c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178c90:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178c94:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f178c98:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f178c9c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f178ca0:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f178ca4:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f178ca8:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f178cac:	51240006 */ 	beql	$t1,$a0,.L0f178cc8
/*  f178cb0:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cb4:	50800004 */ 	beqzl	$a0,.L0f178cc8
/*  f178cb8:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cbc:	5466fff2 */ 	bnel	$v1,$a2,.L0f178c88
/*  f178cc0:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f178cc4:
/*  f178cc4:	2861000b */ 	slti	$at,$v1,0xb
.L0f178cc8:
/*  f178cc8:	10200037 */ 	beqz	$at,.L0f178da8
/*  f178ccc:	01431021 */ 	addu	$v0,$t2,$v1
.L0f178cd0:
/*  f178cd0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178cd4:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cd8:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f178cdc:	1420fffc */ 	bnez	$at,.L0f178cd0
/*  f178ce0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178ce4:	10000031 */ 	beqz	$zero,.L0f178dac
/*  f178ce8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178cec:
/*  f178cec:	91590000 */ 	lbu	$t9,0x0($t2)
/*  f178cf0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f178cf4:	00001825 */ 	or	$v1,$zero,$zero
/*  f178cf8:	13200014 */ 	beqz	$t9,.L0f178d4c
/*  f178cfc:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f178d00:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f178d04:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f178d08:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f178d0c:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f178d10:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f178d14:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f178d18:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f178d1c:	018e2021 */ 	addu	$a0,$t4,$t6
/*  f178d20:	01401021 */ 	addu	$v0,$t2,$zero
/*  f178d24:	91450000 */ 	lbu	$a1,0x0($t2)
/*  f178d28:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f178d2c:
/*  f178d2c:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d30:	a0850000 */ 	sb	$a1,0x0($a0)
/*  f178d34:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f178d38:	10200004 */ 	beqz	$at,.L0f178d4c
/*  f178d3c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178d40:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f178d44:	54a0fff9 */ 	bnezl	$a1,.L0f178d2c
/*  f178d48:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f178d4c:
/*  f178d4c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f178d50:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f178d54:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f178d58:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f178d5c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f178d60:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f178d64:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f178d68:	03232021 */ 	addu	$a0,$t9,$v1
/*  f178d6c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178d70:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d74:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f178d78:	1020000b */ 	beqz	$at,.L0f178da8
/*  f178d7c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f178d80:
/*  f178d80:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178d84:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d88:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f178d8c:	1420fffc */ 	bnez	$at,.L0f178d80
/*  f178d90:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f178d94:	10000005 */ 	beqz	$zero,.L0f178dac
/*  f178d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178d9c:
/*  f178d9c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f178da0:	0fc42947 */ 	jal	func0f10a51c
/*  f178da4:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f178da8:
/*  f178da8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178dac:
/*  f178dac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178db0:	00001025 */ 	or	$v0,$zero,$zero
/*  f178db4:	03e00008 */ 	jr	$ra
/*  f178db8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f178dbc
/*  f178dbc:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f178dc0:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f178dc4:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178dc8:	908f001e */ 	lbu	$t7,0x1e($a0)
/*  f178dcc:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
/*  f178dd0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f178dd4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f178dd8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f178ddc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178de0:	11e1003f */ 	beq	$t7,$at,.L0f178ee0
/*  f178de4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f178de8:	3c188006 */ 	lui	$t8,%hi(var8005d9d0)
/*  f178dec:	8f18d9d0 */ 	lw	$t8,%lo(var8005d9d0)($t8)
/*  f178df0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f178df4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f178df8:	5700003a */ 	bnezl	$t8,.L0f178ee4
/*  f178dfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178e00:	8c790288 */ 	lw	$t9,0x288($v1)
/*  f178e04:	3c0b800a */ 	lui	$t3,0x800a
/*  f178e08:	256be000 */ 	addiu	$t3,$t3,-8192
/*  f178e0c:	8f280070 */ 	lw	$t0,0x70($t9)
/*  f178e10:	000850c0 */ 	sll	$t2,$t0,0x3
/*  f178e14:	01485023 */ 	subu	$t2,$t2,$t0
/*  f178e18:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f178e1c:	01485021 */ 	addu	$t2,$t2,$t0
/*  f178e20:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f178e24:	01485023 */ 	subu	$t2,$t2,$t0
/*  f178e28:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f178e2c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f178e30:	904c083c */ 	lbu	$t4,0x83c($v0)
/*  f178e34:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f178e38:	55800028 */ 	bnezl	$t4,.L0f178edc
/*  f178e3c:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f178e40:	8c6e0318 */ 	lw	$t6,0x318($v1)
/*  f178e44:	8c6d028c */ 	lw	$t5,0x28c($v1)
/*  f178e48:	11c00012 */ 	beqz	$t6,.L0f178e94
/*  f178e4c:	a04d083b */ 	sb	$t5,0x83b($v0)
/*  f178e50:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f178e54:	3c048008 */ 	lui	$a0,%hi(menudialog_2a8b0)
/*  f178e58:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178e5c:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f178e60:	13000007 */ 	beqz	$t8,.L0f178e80
/*  f178e64:	24844890 */ 	addiu	$a0,$a0,%lo(menudialog_2a8b0)
/*  f178e68:	3c048008 */ 	lui	$a0,%hi(menudialog_2a908)
/*  f178e6c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178e70:	248448e8 */ 	addiu	$a0,$a0,%lo(menudialog_2a908)
/*  f178e74:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178e78:	10000017 */ 	beqz	$zero,.L0f178ed8
/*  f178e7c:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178e80:
/*  f178e80:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178e84:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178e88:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178e8c:	10000012 */ 	beqz	$zero,.L0f178ed8
/*  f178e90:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178e94:
/*  f178e94:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f178e98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178e9c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f178ea0:	14410008 */ 	bne	$v0,$at,.L0f178ec4
/*  f178ea4:	3c048007 */ 	lui	$a0,%hi(menudialog_196c8)
/*  f178ea8:	3c048007 */ 	lui	$a0,%hi(menudialog_status)
/*  f178eac:	248436c0 */ 	addiu	$a0,$a0,%lo(menudialog_status)
/*  f178eb0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178eb4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178eb8:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178ebc:	10000006 */ 	beqz	$zero,.L0f178ed8
/*  f178ec0:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178ec4:
/*  f178ec4:	248436a8 */ 	addiu	$a0,$a0,%lo(menudialog_196c8)
/*  f178ec8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178ecc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178ed0:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178ed4:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178ed8:
/*  f178ed8:	8fb9001c */ 	lw	$t9,0x1c($sp)
.L0f178edc:
/*  f178edc:	acd90000 */ 	sw	$t9,0x0($a2)
.L0f178ee0:
/*  f178ee0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178ee4:
/*  f178ee4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f178ee8:	03e00008 */ 	jr	$ra
/*  f178eec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f178ef0
/*  f178ef0:	3c028007 */ 	lui	$v0,%hi(g_MpPlayerNum)
/*  f178ef4:	0005c0c0 */ 	sll	$t8,$a1,0x3
/*  f178ef8:	24421448 */ 	addiu	$v0,$v0,%lo(g_MpPlayerNum)
/*  f178efc:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f178f00:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f178f04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f178f08:	ac450000 */ 	sw	$a1,0x0($v0)
/*  f178f0c:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f178f10:	3c19800b */ 	lui	$t9,%hi(g_MpSetup+0xc)
/*  f178f14:	8f39cb94 */ 	lw	$t9,%lo(g_MpSetup+0xc)($t9)
/*  f178f18:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f178f1c:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f178f20:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f178f24:	3c01800a */ 	lui	$at,%hi(g_MenuStack+0x83b)
/*  f178f28:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f178f2c:	00380821 */ 	addu	$at,$at,$t8
/*  f178f30:	33280002 */ 	andi	$t0,$t9,0x2
/*  f178f34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178f38:	a024e83b */ 	sb	$a0,%lo(g_MenuStack+0x83b)($at)
/*  f178f3c:	11000027 */ 	beqz	$t0,.L0f178fdc
/*  f178f40:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f178f44:	3c09800b */ 	lui	$t1,%hi(g_MpSetup+0x88)
/*  f178f48:	9129cc10 */ 	lbu	$t1,%lo(g_MpSetup+0x88)($t1)
/*  f178f4c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f178f50:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa30)
/*  f178f54:	1521001d */ 	bne	$t1,$at,.L0f178fcc
/*  f178f58:	24844a10 */ 	addiu	$a0,$a0,%lo(menudialog_2aa30)
/*  f178f5c:	3c0a800a */ 	lui	$t2,%hi(g_CheatsActiveBank0)
/*  f178f60:	8d4a21d0 */ 	lw	$t2,%lo(g_CheatsActiveBank0)($t2)
/*  f178f64:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa60)
/*  f178f68:	3c0b800a */ 	lui	$t3,%hi(g_CheatsActiveBank1)
/*  f178f6c:	15400004 */ 	bnez	$t2,.L0f178f80
/*  f178f70:	24844a40 */ 	addiu	$a0,$a0,%lo(menudialog_2aa60)
/*  f178f74:	8d6b21d4 */ 	lw	$t3,%lo(g_CheatsActiveBank1)($t3)
/*  f178f78:	11600005 */ 	beqz	$t3,.L0f178f90
/*  f178f7c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178f80:
/*  f178f80:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178f84:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178f88:	10000018 */ 	beqz	$zero,.L0f178fec
/*  f178f8c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178f90:
/*  f178f90:	0fc6714f */ 	jal	func0f19c53c
/*  f178f94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178f98:	10400007 */ 	beqz	$v0,.L0f178fb8
/*  f178f9c:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa78)
/*  f178fa0:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa48)
/*  f178fa4:	24844a28 */ 	addiu	$a0,$a0,%lo(menudialog_2aa48)
/*  f178fa8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fac:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178fb0:	1000000e */ 	beqz	$zero,.L0f178fec
/*  f178fb4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178fb8:
/*  f178fb8:	24844a58 */ 	addiu	$a0,$a0,%lo(menudialog_2aa78)
/*  f178fbc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fc0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178fc4:	10000009 */ 	beqz	$zero,.L0f178fec
/*  f178fc8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178fcc:
/*  f178fcc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fd0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178fd4:	10000005 */ 	beqz	$zero,.L0f178fec
/*  f178fd8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178fdc:
/*  f178fdc:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa18)
/*  f178fe0:	248449f8 */ 	addiu	$a0,$a0,%lo(menudialog_2aa18)
/*  f178fe4:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fe8:	24050005 */ 	addiu	$a1,$zero,0x5
.L0f178fec:
/*  f178fec:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f178ff0:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f178ff4:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f178ff8:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f178ffc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f179000:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f179004:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f179008:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f17900c:	94430048 */ 	lhu	$v1,0x48($v0)
/*  f179010:	306f4000 */ 	andi	$t7,$v1,0x4000
/*  f179014:	55e0000c */ 	bnezl	$t7,.L0f179048
/*  f179018:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17901c:	8c58004c */ 	lw	$t8,0x4c($v0)
/*  f179020:	57000009 */ 	bnezl	$t8,.L0f179048
/*  f179024:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f179028:	94590050 */ 	lhu	$t9,0x50($v0)
/*  f17902c:	3c048008 */ 	lui	$a0,%hi(menudialog_2ab34)
/*  f179030:	34684000 */ 	ori	$t0,$v1,0x4000
/*  f179034:	17200003 */ 	bnez	$t9,.L0f179044
/*  f179038:	24844b14 */ 	addiu	$a0,$a0,%lo(menudialog_2ab34)
/*  f17903c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f179040:	a4480048 */ 	sh	$t0,0x48($v0)
.L0f179044:
/*  f179044:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179048:
/*  f179048:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*  f17904c:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f179050:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f179054:	03e00008 */ 	jr	$ra
/*  f179058:	ac291448 */ 	sw	$t1,%lo(g_MpPlayerNum)($at)
/*  f17905c:	00000000 */ 	sll	$zero,$zero,0x0
);
