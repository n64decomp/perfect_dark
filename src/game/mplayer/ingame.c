#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "game/game_005fd0.h"
#include "game/title.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/core.h"
#include "game/mplayer/ingame.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "gvars/gvars.h"
#include "lib/main.h"
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
/*  f177e30:	10000067 */ 	b	.L0f177fd0
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
/*  f177e78:	10000055 */ 	b	.L0f177fd0
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
/*  f177ed0:	10000005 */ 	b	.L0f177ee8
/*  f177ed4:	00000000 */ 	nop
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
/*  f177f1c:	3c07800a */ 	lui	$a3,%hi(g_MpSelectedPlayersForStats)
/*  f177f20:	24e7deb0 */ 	addiu	$a3,$a3,%lo(g_MpSelectedPlayersForStats)
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
/*  f177f70:	10000017 */ 	b	.L0f177fd0
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
/*  f177fa4:	3c04800a */ 	lui	$a0,%hi(g_MpSelectedPlayersForStats)
/*  f177fa8:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f177fac:	9084deb0 */ 	lbu	$a0,%lo(g_MpSelectedPlayersForStats)($a0)
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
/*  f177fd4:	00000000 */ 	nop
);

s32 menuhandlerMpEndGame(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.currentplayer->aborted = true;
		mainEndStage();
	}

	return 0;
}

/**
 * This is something near the top of the "End Game" dialog during gameplay.
 */
s32 menuhandler00178018(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetupSaveFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

char *mpMenuTextInGameLimit(struct menuitem *item)
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
		sprintf(g_StringPointer, langGet(L_MPMENU(113)), mpCalculateTeamScoreLimit() + 1);
		break;
	}

	return g_StringPointer;
}

s32 menuhandlerMpInGameLimitLabel(s32 operation, struct menuitem *item, union handlerdata *data)
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

s32 menuhandlerMpPause(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (mpIsPaused()) {
			mpSetPaused(MPPAUSEMODE_UNPAUSED);
		} else {
			mpSetPaused(MPPAUSEMODE_PAUSED);
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
	formatTime(g_StringPointer, coreGetStageTime60(), 3);
	return g_StringPointer;
}

char *mpMenuTextWeaponDescription(struct menuitem *item)
{
	struct weapon *weapon = weaponFindById(g_Menus[g_MpPlayerNum].data.mppause.weaponnum);

	if (weapon) {
		return langGet(weapon->description);
	}

	return "\n";
}

char *mpMenuTitleStatsFor(struct menudialog *dialog)
{
	char *name;

	if (g_MpSelectedPlayersForStats[g_MpPlayerNum] < 4) {
		name = g_MpPlayers[g_MpSelectedPlayersForStats[g_MpPlayerNum]].base.name;
	} else {
		name = g_MpSimulants[g_MpSelectedPlayersForStats[g_MpPlayerNum] - 4].base.name;
	}

	// "Stats for %s"
	sprintf(g_StringPointer, langGet(L_MPMENU(280)), name);
	return g_StringPointer;
}

s32 func0f178440(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation);

	return 0;
}

char *mpMenuTextWeaponOfChoiceName(struct menuitem *item)
{
	return mpPlayerGetWeaponOfChoiceName(g_Menus[g_MpPlayerNum].playernum, 0);
}

char *mpMenuTextAward1(struct menuitem *item)
{
	return g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->award1;
}

char *mpMenuTextAward2(struct menuitem *item)
{
	return g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->award2;
}

char *mpMenuTextPlacementWithSuffix(struct menuitem *item)
{
	u16 suffixes[12] = g_OrdinalSuffixes;

	return langGet(suffixes[g_MpPlayers[g_MpPlayerNum].base.placement]);
}

s32 mpPlacementMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR) {
		if (g_MpPlayers[g_MpPlayerNum].base.placement == 0) { // winner
			data->label.colour2 = colourBlend(data->label.colour2, 0xffff00ff, func0f006b08(40) * 255);
		}
	}

	return 0;
}

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
/*  f178728:	3c138008 */ 	lui	$s3,%hi(g_ScaleX)
/*  f17872c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f178730:	8eb80008 */ 	lw	$t8,0x8($s5)
/*  f178734:	0000b025 */ 	or	$s6,$zero,$zero
/*  f178738:	2673fac0 */ 	addiu	$s3,$s3,%lo(g_ScaleX)
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
/*  f1787a4:	1000000c */ 	b	.L0f1787d8
/*  f1787a8:	00000000 */ 	nop
.L0f1787ac:
/*  f1787ac:	3c11ff7f */ 	lui	$s1,0xff7f
/*  f1787b0:	10000009 */ 	b	.L0f1787d8
/*  f1787b4:	36317fff */ 	ori	$s1,$s1,0x7fff
.L0f1787b8:
/*  f1787b8:	3c11bfbf */ 	lui	$s1,0xbfbf
/*  f1787bc:	10000006 */ 	b	.L0f1787d8
/*  f1787c0:	363100ff */ 	ori	$s1,$s1,0xff
.L0f1787c4:
/*  f1787c4:	3c1100ff */ 	lui	$s1,0xff
/*  f1787c8:	10000003 */ 	b	.L0f1787d8
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
/*  f178a24:	00000000 */ 	nop
/*  f178a28:	0007000d */ 	break	0x7
.L0f178a2c:
/*  f178a2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f178a30:	15210004 */ 	bne	$t1,$at,.L0f178a44
/*  f178a34:	3c018000 */ 	lui	$at,0x8000
/*  f178a38:	15810002 */ 	bne	$t4,$at,.L0f178a44
/*  f178a3c:	00000000 */ 	nop
/*  f178a40:	0006000d */ 	break	0x6
.L0f178a44:
/*  f178a44:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f178a48:
/*  f178a48:	24010004 */ 	addiu	$at,$zero,0x4
/*  f178a4c:	5601ff43 */ 	bnel	$s0,$at,.L0f17875c
/*  f178a50:	8fd90000 */ 	lw	$t9,0x0($s8)
/*  f178a54:	afb10090 */ 	sw	$s1,0x90($sp)
/*  f178a58:	10000002 */ 	b	.L0f178a64
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

s32 mpPlayerTitleMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_GETCOLOUR) {
		if (g_MpPlayers[g_MpPlayerNum].title != g_MpPlayers[g_MpPlayerNum].newtitle) {
			data->label.colour2 = colourBlend(data->label.colour2, 0xffff00ff, func0f006b08(40) * 255);
		}
	}

	return 0;
}

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
/*  f178c24:	10000061 */ 	b	.L0f178dac
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
/*  f178ce4:	10000031 */ 	b	.L0f178dac
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
/*  f178d94:	10000005 */ 	b	.L0f178dac
/*  f178d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178d9c:
/*  f178d9c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f178da0:	0fc42947 */ 	jal	filemgrPushSelectLocationDialog
/*  f178da4:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f178da8:
/*  f178da8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178dac:
/*  f178dac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178db0:	00001025 */ 	or	$v0,$zero,$zero
/*  f178db4:	03e00008 */ 	jr	$ra
/*  f178db8:	00000000 */ 	nop
);

void mpPushPauseDialog(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	if (g_MpSetup.paused != MPPAUSEMODE_GAMEOVER && var8005d9d0 == 0) {
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;

		if (g_Menus[g_MpPlayerNum].unk83c == 0) {
			g_Menus[g_MpPlayerNum].playernum = g_Vars.currentplayernum;

			if (g_Vars.normmplayerisrunning) {
				if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
					menuPushRootDialog(&g_MpPauseTeamRankingsMenuDialog, MENUROOT_MPPAUSE);
				} else {
					menuPushRootDialog(&g_MpPausePlayerRankingMenuDialog, MENUROOT_MPPAUSE);
				}
			} else {
				if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
					menuPushRootDialog(&g_2PMissionPauseVMenuDialog, MENUROOT_MPPAUSE);
				} else {
					menuPushRootDialog(&g_2PMissionPauseHMenuDialog, MENUROOT_MPPAUSE);
				}
			}
		}

		g_MpPlayerNum = prevplayernum;
	}
}

void mpPushEndscreenDialog(u32 arg0, u32 playernum)
{
	u32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = playernum;

	g_Menus[g_MpPlayerNum].playernum = arg0;

	if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
		if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
			if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
				menuPushRootDialog(&g_MpEndscreenChallengeCheatedMenuDialog, MENUROOT_MPENDSCREEN);
			} else if (mpIsChallengeCompleteForEndscreen()) {
				menuPushRootDialog(&g_MpEndscreenChallengeCompletedMenuDialog, MENUROOT_MPENDSCREEN);
			} else {
				menuPushRootDialog(&g_MpEndscreenChallengeFailedMenuDialog, MENUROOT_MPENDSCREEN);
			}
		} else {
			menuPushRootDialog(&g_MpEndscreenTeamGameOverMenuDialog, MENUROOT_MPENDSCREEN);
		}
	} else {
		menuPushRootDialog(&g_MpEndscreenIndGameOverMenuDialog, MENUROOT_MPENDSCREEN);
	}

	if ((g_MpPlayers[g_MpPlayerNum].options & OPTION_ASKEDSAVEPLAYER) == 0
			&& g_MpPlayers[g_MpPlayerNum].unk4c.unk00 == false
			&& g_MpPlayers[g_MpPlayerNum].unk4c.unk04 == 0) {
		g_MpPlayers[g_MpPlayerNum].options |= OPTION_ASKEDSAVEPLAYER;
		menuPushDialog(&g_MpEndscreenSavePlayerMenuDialog);
	}

	g_MpPlayerNum = prevplayernum;
}
