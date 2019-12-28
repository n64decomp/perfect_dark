#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/cheats.h"
#include "game/game_10ccd0.h"
#include "game/game_111600.h"
#include "game/game_115ab0.h"
#include "game/game_11ecf0.h"
#include "game/game_129900.h"
#include "game/game_16cfa0.h"
#include "game/game_19c990.h"

GLOBAL_ASM(
glabel cheatIsUnlocked
/*  f106d40:	3c0f8007 */ 	lui	$t7,%hi(g_Cheats)
/*  f106d44:	25ef3a90 */ 	addiu	$t7,$t7,%lo(g_Cheats)
/*  f106d48:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f106d4c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f106d50:	90660006 */ 	lbu	$a2,0x6($v1)
/*  f106d54:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f106d58:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106d5c:	30d80008 */ 	andi	$t8,$a2,0x8
/*  f106d60:	1300000b */ 	beqz	$t8,.L0f106d90
/*  f106d64:	00002825 */ 	or	$a1,$zero,$zero
/*  f106d68:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f106d6c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f106d70:	0fc673c8 */ 	jal	func0f19cf20
/*  f106d74:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f106d78:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f106d7c:	10400002 */ 	beqz	$v0,.L0f106d88
/*  f106d80:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f106d84:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106d88:
/*  f106d88:	10000029 */ 	beqz	$zero,.L0f106e30
/*  f106d8c:	90660006 */ 	lbu	$a2,0x6($v1)
.L0f106d90:
/*  f106d90:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f106d94:	53200016 */ 	beqzl	$t9,.L0f106df0
/*  f106d98:	906e0004 */ 	lbu	$t6,0x4($v1)
/*  f106d9c:	90680004 */ 	lbu	$t0,0x4($v1)
/*  f106da0:	3c0a800a */ 	lui	$t2,%hi(var800a2200)
/*  f106da4:	254a2200 */ 	addiu	$t2,$t2,%lo(var800a2200)
/*  f106da8:	00084880 */ 	sll	$t1,$t0,0x2
/*  f106dac:	01284823 */ 	subu	$t1,$t1,$t0
/*  f106db0:	00094840 */ 	sll	$t1,$t1,0x1
/*  f106db4:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f106db8:	944b0020 */ 	lhu	$t3,0x20($v0)
/*  f106dbc:	51600003 */ 	beqzl	$t3,.L0f106dcc
/*  f106dc0:	944c0022 */ 	lhu	$t4,0x22($v0)
/*  f106dc4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f106dc8:	944c0022 */ 	lhu	$t4,0x22($v0)
.L0f106dcc:
/*  f106dcc:	51800003 */ 	beqzl	$t4,.L0f106ddc
/*  f106dd0:	944d0024 */ 	lhu	$t5,0x24($v0)
/*  f106dd4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f106dd8:	944d0024 */ 	lhu	$t5,0x24($v0)
.L0f106ddc:
/*  f106ddc:	51a00015 */ 	beqzl	$t5,.L0f106e34
/*  f106de0:	30ca0002 */ 	andi	$t2,$a2,0x2
/*  f106de4:	10000012 */ 	beqz	$zero,.L0f106e30
/*  f106de8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f106dec:	906e0004 */ 	lbu	$t6,0x4($v1)
.L0f106df0:
/*  f106df0:	90780005 */ 	lbu	$t8,0x5($v1)
/*  f106df4:	3c02800a */ 	lui	$v0,0x800a
/*  f106df8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f106dfc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f106e00:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f106e04:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f106e08:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f106e0c:	00481021 */ 	addu	$v0,$v0,$t0
/*  f106e10:	94422220 */ 	lhu	$v0,0x2220($v0)
/*  f106e14:	50400007 */ 	beqzl	$v0,.L0f106e34
/*  f106e18:	30ca0002 */ 	andi	$t2,$a2,0x2
/*  f106e1c:	94690002 */ 	lhu	$t1,0x2($v1)
/*  f106e20:	0122082a */ 	slt	$at,$t1,$v0
/*  f106e24:	54200003 */ 	bnezl	$at,.L0f106e34
/*  f106e28:	30ca0002 */ 	andi	$t2,$a2,0x2
/*  f106e2c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106e30:
/*  f106e30:	30ca0002 */ 	andi	$t2,$a2,0x2
.L0f106e34:
/*  f106e34:	11400006 */ 	beqz	$t2,.L0f106e50
/*  f106e38:	24040023 */ 	addiu	$a0,$zero,0x23
/*  f106e3c:	0fc43c63 */ 	jal	eepromGet
/*  f106e40:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f106e44:	10400002 */ 	beqz	$v0,.L0f106e50
/*  f106e48:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f106e4c:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f106e50:
/*  f106e50:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f106e54:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f106e58:	00a01025 */ 	or	$v0,$a1,$zero
/*  f106e5c:	03e00008 */ 	jr	$ra
/*  f106e60:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch due to incorrect jump address for g_BestTimes.
// It appears to be in a struct that starts 0x20 earlier, but this means other
// variables like g_EepromFlags are in the struct too. Resolving this will be
// done separately.
//bool cheatIsUnlocked(s32 cheat_id)
//{
//	struct cheat *cheat = &g_Cheats[cheat_id];
//	bool unlocked = false;
//
//	if (cheat->flags & CHEATFLAG_FIRINGRANGE) {
//		if (func0f19cf20(cheat->time)) {
//			unlocked = true;
//		}
//	} else if (cheat->flags & CHEATFLAG_COMPLETION) {
//		if (g_BestTimes[cheat->stage_index * 3]) {
//			unlocked++;
//		}
//		if (g_BestTimes[cheat->stage_index * 3 + 1]) {
//			unlocked++;
//		}
//		if (g_BestTimes[cheat->stage_index * 3 + 2]) {
//			unlocked++;
//		}
//	} else {
//		s32 mytime = g_BestTimes[cheat->stage_index * 3 + cheat->difficulty];
//
//		if (mytime && mytime <= cheat->time) {
//			unlocked = true;
//		}
//	}
//
//	if (cheat->flags & CHEATFLAG_TRANSFERPAK) {
//		if (eepromGet(0x23)) {
//			unlocked++;
//		}
//	}
//
//	return unlocked;
//}

bool cheatIsActive(s32 cheat_id)
{
	if (cheat_id < 32) {
		return g_CheatsActiveBank0 & (1 << cheat_id);
	}

	return g_CheatsActiveBank1 & (1 << cheat_id);
}

void cheatActivate(s32 cheat_id)
{
	u32 prevplayernum;
	s32 playernum;

	switch (cheat_id) {
	case CHEAT_INVINCIBLE:
		// Make all players invincible
		prevplayernum = g_Vars.currentplayernum;

		for (playernum = 0; playernum < (g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0); playernum++) {
			setCurrentPlayerNum(playernum);
			g_Vars.currentplayer->invincible = 1;
		}

		setCurrentPlayerNum(prevplayernum);
		break;
	case CHEAT_ALLGUNS:
		// Give all guns if only one player playing
		if ((g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0) == 1 && g_Vars.unk000318 == 0) {
			prevplayernum = g_Vars.currentplayernum;

			for (playernum = 0; playernum < (g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0); playernum++) {
				setCurrentPlayerNum(playernum);
				currentPlayerSetAllGuns(true);
			}

			setCurrentPlayerNum(prevplayernum);
		}
		break;
	}

	if (cheat_id < 32) {
		g_CheatsActiveBank0 = g_CheatsActiveBank0 | (1 << cheat_id);
	} else {
		g_CheatsActiveBank1 = g_CheatsActiveBank1 | (1 << cheat_id);
	}
}

void cheatDeactivate(s32 cheat_id)
{
	u32 prevplayernum;
	s32 playernum;

	switch (cheat_id) {
	case CHEAT_INVINCIBLE:
		prevplayernum = g_Vars.currentplayernum;

		for (playernum = 0; playernum < (g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0); playernum++) {
			setCurrentPlayerNum(playernum);
			g_Vars.currentplayer->invincible = 1; // @bug?
		}

		setCurrentPlayerNum(prevplayernum);
		break;
	case CHEAT_ALLGUNS:
		if ((g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0) == 1 && g_Vars.unk000318 == 0) {
			prevplayernum = g_Vars.currentplayernum;

			for (playernum = 0; playernum < (g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0); playernum++) {
				setCurrentPlayerNum(playernum);
				currentPlayerSetAllGuns(false);
			}

			setCurrentPlayerNum(prevplayernum);
		}
		break;
	}

	if (cheat_id < 32) {
		g_CheatsActiveBank0 = g_CheatsActiveBank0 & ~(1 << cheat_id);
	} else {
		g_CheatsActiveBank1 = g_CheatsActiveBank1 & ~(1 << cheat_id);
	}
}

void cheatsDisableAll(void)
{
	g_CheatsActiveBank0 = 0;
	g_CheatsActiveBank1 = 0;
	g_CheatsEnabledBank0 = 0;
	g_CheatsEnabledBank1 = 0;
}

void cheatsActivate(void)
{
	s32 cheat_id;

	if (g_Vars.unk0004b4 != 38) {
		g_CheatsActiveBank0 = g_CheatsEnabledBank0;
		g_CheatsActiveBank1 = g_CheatsEnabledBank1;

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 || g_Vars.unk000318) {
			// Co-op/counter-op - deactivate "Weapons for Jo in Solo" cheats
			g_CheatsActiveBank0 &= ~(
				(1 << CHEAT_TRENTSMAGNUM) |
				(1 << CHEAT_FARSIGHT) |
				(1 << CHEAT_ROCKETLAUNCHER) |
				(1 << CHEAT_SNIPERRIFLE) |
				(1 << CHEAT_XRAYSCANNER) |
				(1 << CHEAT_SUPERDRAGON) |
				(1 << CHEAT_LAPTOPGUN)
			);
			g_CheatsActiveBank1 &= ~(
				(1 << CHEAT_PHOENIX - 32) |
				(1 << CHEAT_PSYCHOSISGUN - 32) |
				(1 << CHEAT_PP9I - 32) |
				(1 << CHEAT_CC13 - 32) |
				(1 << CHEAT_KLO1313 - 32) |
				(1 << CHEAT_KF7SPECIAL - 32) |
				(1 << CHEAT_ZZT - 32) |
				(1 << CHEAT_DMC - 32) |
				(1 << CHEAT_AR53 - 32) |
				(1 << CHEAT_RCP45 - 32)
			);
		}
	} else {
		g_CheatsActiveBank0 = 0;
		g_CheatsActiveBank1 = 0;
	}

	for (cheat_id = 0; cheat_id != NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].flags & CHEATFLAG_ALWAYSON) {
			if (cheatIsUnlocked(cheat_id)) {
				if (cheat_id < 32) {
					g_CheatsActiveBank0 = g_CheatsActiveBank0 | (1 << cheat_id);
				} else {
					g_CheatsActiveBank1 = g_CheatsActiveBank1 | (1 << cheat_id);
				}
			} else {
				if (cheat_id < 32) {
					g_CheatsActiveBank0 = g_CheatsActiveBank0 & ~(1 << cheat_id);
				} else {
					g_CheatsActiveBank1 = g_CheatsActiveBank1 & ~(1 << cheat_id);
				}
			}
		}

		if (cheatIsActive(cheat_id)) {
			cheatActivate(cheat_id);
		}
	}
}

GLOBAL_ASM(
glabel cheatMenuHandleCheatCheckbox
/*  f1076b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1076b4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1076b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1076bc:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1076c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1076c4:	1081001f */ 	beq	$a0,$at,.L0f107744
/*  f1076c8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1076cc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f1076d0:	54810054 */ 	bnel	$a0,$at,.L0f107824
/*  f1076d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1076d8:	90a20001 */ 	lbu	$v0,0x1($a1)
/*  f1076dc:	3c06800a */ 	lui	$a2,%hi(g_CheatsEnabledBank1)
/*  f1076e0:	3c05800a */ 	lui	$a1,%hi(g_CheatsEnabledBank0)
/*  f1076e4:	28410020 */ 	slti	$at,$v0,0x20
/*  f1076e8:	1020000c */ 	beqz	$at,.L0f10771c
/*  f1076ec:	24c621dc */ 	addiu	$a2,$a2,%lo(g_CheatsEnabledBank1)
/*  f1076f0:	24a521d8 */ 	addiu	$a1,$a1,%lo(g_CheatsEnabledBank0)
/*  f1076f4:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f1076f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1076fc:	004e7804 */ 	sllv	$t7,$t6,$v0
/*  f107700:	01f8c824 */ 	and	$t9,$t7,$t8
/*  f107704:	13200003 */ 	beqz	$t9,.L0f107714
/*  f107708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10770c:	10000045 */ 	beqz	$zero,.L0f107824
/*  f107710:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107714:
/*  f107714:	10000043 */ 	beqz	$zero,.L0f107824
/*  f107718:	00001025 */ 	or	$v0,$zero,$zero
.L0f10771c:
/*  f10771c:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f107720:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f107724:	00484804 */ 	sllv	$t1,$t0,$v0
/*  f107728:	012a5824 */ 	and	$t3,$t1,$t2
/*  f10772c:	11600003 */ 	beqz	$t3,.L0f10773c
/*  f107730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107734:	1000003b */ 	beqz	$zero,.L0f107824
/*  f107738:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10773c:
/*  f10773c:	10000039 */ 	beqz	$zero,.L0f107824
/*  f107740:	00001025 */ 	or	$v0,$zero,$zero
.L0f107744:
/*  f107744:	90c40001 */ 	lbu	$a0,0x1($a2)
/*  f107748:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10774c:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f107750:	10400033 */ 	beqz	$v0,.L0f107820
/*  f107754:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f107758:	90c20001 */ 	lbu	$v0,0x1($a2)
/*  f10775c:	3c05800a */ 	lui	$a1,%hi(g_CheatsEnabledBank0)
/*  f107760:	24a521d8 */ 	addiu	$a1,$a1,%lo(g_CheatsEnabledBank0)
/*  f107764:	28410020 */ 	slti	$at,$v0,0x20
/*  f107768:	1020001f */ 	beqz	$at,.L0f1077e8
/*  f10776c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107770:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f107774:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f107778:	004c2004 */ 	sllv	$a0,$t4,$v0
/*  f10777c:	00836824 */ 	and	$t5,$a0,$v1
/*  f107780:	11a00005 */ 	beqz	$t5,.L0f107798
/*  f107784:	24010014 */ 	addiu	$at,$zero,0x14
/*  f107788:	00807027 */ 	nor	$t6,$a0,$zero
/*  f10778c:	01c37824 */ 	and	$t7,$t6,$v1
/*  f107790:	10000023 */ 	beqz	$zero,.L0f107820
/*  f107794:	acaf0000 */ 	sw	$t7,0x0($a1)
.L0f107798:
/*  f107798:	14410007 */ 	bne	$v0,$at,.L0f1077b8
/*  f10779c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1077a0:	3c01fffb */ 	lui	$at,0xfffb
/*  f1077a4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1077a8:	0061c024 */ 	and	$t8,$v1,$at
/*  f1077ac:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1077b0:	90c20001 */ 	lbu	$v0,0x1($a2)
/*  f1077b4:	03001825 */ 	or	$v1,$t8,$zero
.L0f1077b8:
/*  f1077b8:	24010012 */ 	addiu	$at,$zero,0x12
/*  f1077bc:	14410006 */ 	bne	$v0,$at,.L0f1077d8
/*  f1077c0:	3c01ffef */ 	lui	$at,0xffef
/*  f1077c4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1077c8:	0061c824 */ 	and	$t9,$v1,$at
/*  f1077cc:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f1077d0:	90c20001 */ 	lbu	$v0,0x1($a2)
/*  f1077d4:	03201825 */ 	or	$v1,$t9,$zero
.L0f1077d8:
/*  f1077d8:	00484804 */ 	sllv	$t1,$t0,$v0
/*  f1077dc:	01235025 */ 	or	$t2,$t1,$v1
/*  f1077e0:	1000000f */ 	beqz	$zero,.L0f107820
/*  f1077e4:	acaa0000 */ 	sw	$t2,0x0($a1)
.L0f1077e8:
/*  f1077e8:	3c06800a */ 	lui	$a2,%hi(g_CheatsEnabledBank1)
/*  f1077ec:	24c621dc */ 	addiu	$a2,$a2,%lo(g_CheatsEnabledBank1)
/*  f1077f0:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f1077f4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1077f8:	004b2004 */ 	sllv	$a0,$t3,$v0
/*  f1077fc:	00836024 */ 	and	$t4,$a0,$v1
/*  f107800:	11800005 */ 	beqz	$t4,.L0f107818
/*  f107804:	00802825 */ 	or	$a1,$a0,$zero
/*  f107808:	00806827 */ 	nor	$t5,$a0,$zero
/*  f10780c:	01a37024 */ 	and	$t6,$t5,$v1
/*  f107810:	10000003 */ 	beqz	$zero,.L0f107820
/*  f107814:	acce0000 */ 	sw	$t6,0x0($a2)
.L0f107818:
/*  f107818:	00a37825 */ 	or	$t7,$a1,$v1
/*  f10781c:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f107820:
/*  f107820:	00001025 */ 	or	$v0,$zero,$zero
.L0f107824:
/*  f107824:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f107828:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10782c:	03e00008 */ 	jr	$ra
/*  f107830:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch due to different registers in case 6 (v1/a0)
//s32 cheatMenuHandleCheatCheckbox(u32 arg0, struct menu_item *item, s32 arg2)
//{
//	switch (arg0) {
//	case 8:
//		if (item->param < 32) {
//			if (g_CheatsEnabledBank0 & (1 << item->param)) {
//				return true;
//			}
//
//			return false;
//		}
//
//		if (g_CheatsEnabledBank1 & (1 << item->param)) {
//			return true;
//		}
//
//		return false;
//	case 6:
//		if (cheatIsUnlocked(item->param)) {
//			if (item->param < 32) { // Bank 0
//				if (g_CheatsEnabledBank0 & (1 << item->param)) { // Turning off
//					g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(1 << item->param);
//				} else { // Turning on
//					// If enabling Marquis or enemy rockets, turn off the other
//					if (item->param == CHEAT_MARQUIS) {
//						g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(1 << CHEAT_ENEMYROCKETS);
//					}
//
//					if (item->param == CHEAT_ENEMYROCKETS) {
//						g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(1 << CHEAT_MARQUIS);
//					}
//
//					g_CheatsEnabledBank0 = g_CheatsEnabledBank0 | (1 << item->param);
//				}
//			} else { // Bank 1
//				if ((1 << item->param) & g_CheatsEnabledBank1) { // Turning off
//					g_CheatsEnabledBank1 = g_CheatsEnabledBank1 & ~(1 << item->param);
//				} else { // Turning on
//					g_CheatsEnabledBank1 = g_CheatsEnabledBank1 | (1 << item->param);
//				}
//			}
//		}
//	}
//
//	return 0;
//}

s32 cheatMenuHandleBuddyCheckbox(s32 operation, struct menu_item *item, s32 arg2)
{
	switch (operation) {
	case MENUOP_GET:
		if (item->param == 0) {
			if (g_CheatsEnabledBank0 & (1 << CHEAT_PUGILIST | 1 << CHEAT_HOTSHOT | 1 << CHEAT_HITANDRUN | 1 << CHEAT_ALIEN)) {
				return false;
			}

			return true;
		}

		if (g_CheatsEnabledBank0 & (1 << item->param)) {
			return true;
		}

		return false;
	case MENUOP_SET:
		if (item->param == 0) {
			// Velvet
			g_CheatsEnabledBank0 &= ~(
				(1 << CHEAT_PUGILIST) |
				(1 << CHEAT_HOTSHOT) |
				(1 << CHEAT_HITANDRUN) |
				(1 << CHEAT_ALIEN)
			);
		} else if (cheatIsUnlocked(item->param)) {
			// Not Velvet
			g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(
				(1 << CHEAT_PUGILIST) |
				(1 << CHEAT_HOTSHOT) |
				(1 << CHEAT_HITANDRUN) |
				(1 << CHEAT_ALIEN)
			);
			g_CheatsEnabledBank0 = g_CheatsEnabledBank0 | (1 << item->param);
		}
	}

	return 0;
}

char *cheatGetNameIfUnlocked(struct menu_item *item)
{
	if (cheatIsUnlocked(item->param)) {
		return textGet(g_Cheats[item->param].nametextid);
	}

	return textGet(0x544a); // "----------"
}

GLOBAL_ASM(
glabel cheatMenuHandleDialog
/*  f107990:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f107994:	24010064 */ 	addiu	$at,$zero,0x64
/*  f107998:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10799c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1079a0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1079a4:	14810023 */ 	bne	$a0,$at,.L0f107a34
/*  f1079a8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1079ac:	0fc5294b */ 	jal	func0f14a52c
/*  f1079b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1079b4:	0fc479e3 */ 	jal	func0f11e78c
/*  f1079b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1079bc:	10400003 */ 	beqz	$v0,.L0f1079cc
/*  f1079c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1079c4:	0fc43c4f */ 	jal	eepromSet
/*  f1079c8:	24040023 */ 	addiu	$a0,$zero,0x23
.L0f1079cc:
/*  f1079cc:	3c067000 */ 	lui	$a2,0x7000
/*  f1079d0:	3c057000 */ 	lui	$a1,0x7000
/*  f1079d4:	24c62148 */ 	addiu	$a2,$a2,0x2148
/*  f1079d8:	24a422e0 */ 	addiu	$a0,$a1,0x22e0
/*  f1079dc:	00c4082b */ 	sltu	$at,$a2,$a0
/*  f1079e0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f1079e4:	10200007 */ 	beqz	$at,.L0f107a04
/*  f1079e8:	00001825 */ 	or	$v1,$zero,$zero
.L0f1079ec:
/*  f1079ec:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f1079f0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1079f4:	0044082b */ 	sltu	$at,$v0,$a0
/*  f1079f8:	01e0c027 */ 	nor	$t8,$t7,$zero
/*  f1079fc:	1420fffb */ 	bnez	$at,.L0f1079ec
/*  f107a00:	00781826 */ 	xor	$v1,$v1,$t8
.L0f107a04:
/*  f107a04:	3c016f76 */ 	lui	$at,0x6f76
/*  f107a08:	34214531 */ 	ori	$at,$at,0x4531
/*  f107a0c:	10610009 */ 	beq	$v1,$at,.L0f107a34
/*  f107a10:	24c20050 */ 	addiu	$v0,$a2,0x50
/*  f107a14:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f107a18:	0044082b */ 	sltu	$at,$v0,$a0
/*  f107a1c:	10200005 */ 	beqz	$at,.L0f107a34
/*  f107a20:	24030012 */ 	addiu	$v1,$zero,0x12
.L0f107a24:
/*  f107a24:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f107a28:	0044082b */ 	sltu	$at,$v0,$a0
/*  f107a2c:	1420fffd */ 	bnez	$at,.L0f107a24
/*  f107a30:	ac43fffc */ 	sw	$v1,-0x4($v0)
.L0f107a34:
/*  f107a34:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f107a38:	24010065 */ 	addiu	$at,$zero,0x65
/*  f107a3c:	5721000a */ 	bnel	$t9,$at,.L0f107a68
/*  f107a40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f107a44:	0fc479e3 */ 	jal	func0f11e78c
/*  f107a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107a4c:	10400003 */ 	beqz	$v0,.L0f107a5c
/*  f107a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107a54:	0fc43c4f */ 	jal	eepromSet
/*  f107a58:	24040023 */ 	addiu	$a0,$zero,0x23
.L0f107a5c:
/*  f107a5c:	0fc52958 */ 	jal	func0f14a560
/*  f107a60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107a64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f107a68:
/*  f107a68:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f107a6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f107a70:	03e00008 */ 	jr	$ra
/*  f107a74:	00000000 */ 	sll	$zero,$zero,0x0
);

char *cheatGetMarquee(struct menu_item *arg0)
{
	u32 cheat_id;
	u8 *ptr;
	u8 difficultyname[256];
	u8 cheatname[256];

	if (g_MenuStack[g_MenuStackDepth].unk00 && g_MenuStack[g_MenuStackDepth].unk00->item && g_MenuStack[g_MenuStackDepth].unk00->item->type == MENUITEMTYPE_CHECKBOX) {
		cheat_id = g_MenuStack[g_MenuStackDepth].unk00->item->param;

		if (g_MenuStack[g_MenuStackDepth].unk00->dialog == &menudialog_cheats_buddies && g_MenuStack[g_MenuStackDepth].unk00->item == &menuitems_cheats_buddies[0]) {
			// Velvet
			sprintf(g_CheatMarqueeString, "%s: %s", textGet(0x548f), textGet(0x5475)); // "Buddy Available", "Velvet Dark"
			return g_CheatMarqueeString;
		}

		if (cheatIsUnlocked(cheat_id)) {
			// Show cheat name
			sprintf(g_CheatMarqueeString, "%s: %s\n",
					g_MenuStack[g_MenuStackDepth].unk00->dialog == &menudialog_cheats_buddies ? textGet(0x548f) : textGet(0x5488), // "Buddy Available", "Cheat available"
					textGet(g_Cheats[cheat_id].nametextid)
			);
			return g_CheatMarqueeString;
		}

		// Locked
		strcpy(&cheatname, textGet(g_Cheats[cheat_id].nametextid));
		ptr = cheatname;

		while (*ptr != '\n') {
			ptr++;
		}

		*ptr = '\0';

		if (g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION) {
			sprintf(g_CheatMarqueeString, "%s %s: %s %s %s",
					textGet(0x5489), // "Complete"
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
					textGet(0x548a), // "for cheat:"
					&cheatname
			);
		} else {
			// Timed
			strcpy(&difficultyname, textGet(0x56fb + g_Cheats[cheat_id].difficulty));
			ptr = difficultyname;

			while (*ptr != '\n') {
				ptr++;
			}

			*ptr = '\0';

			sprintf(g_CheatMarqueeString, "%s %s: %s %s %s %s %d:%02d %s %s",
					textGet(0x5489), // "Complete"
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
					textGet(0x548b), // "on"
					&difficultyname,
					textGet(0x548c), // "in under"
					g_Cheats[cheat_id].time / 60,
					g_Cheats[cheat_id].time % 60,
					textGet(0x548a), // "for cheat:"
					&cheatname
			);
		}

		if (g_Cheats[cheat_id].flags & CHEATFLAG_TRANSFERPAK) {
			func00013224(&g_CheatMarqueeString, textGet(0x548d)); // " or insert Game Boy ..."
		}

		func00013224(&g_CheatMarqueeString, "\n");
		return g_CheatMarqueeString;
	}

	// No cheat selected
	return textGet(0x548e); // "Select cheat for information"
}

bool cheatMenuHandleTurnOffAllCheats(u32 operation, u32 arg1, u32 *arg2)
{
	if (operation == MENUOP_SET) {
		g_CheatsEnabledBank0 = 0;
		g_CheatsEnabledBank1 = 0;
	}

	return false;
}

s32 cheatGetByTimedStageIndex(s32 stage_index, s32 difficulty)
{
	s32 cheat_id;

	for (cheat_id = 0; cheat_id < NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].stage_index == stage_index &&
				g_Cheats[cheat_id].difficulty == difficulty &&
				(g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION) == 0 &&
				(g_Cheats[cheat_id].flags & CHEATFLAG_FIRINGRANGE) == 0) {
			return cheat_id;
		}
	}

	return -1;
}

s32 cheatGetByCompletedStageIndex(s32 stage_index)
{
	s32 cheat_id;

	for (cheat_id = 0; cheat_id < NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].stage_index == stage_index && (g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION)) {
			return cheat_id;
		}
	}

	return -1;
}

s32 cheatGetTime(s32 cheat_id)
{
	return g_Cheats[cheat_id].time;
}

char *cheatGetName(s32 cheat_id)
{
	return textGet(g_Cheats[cheat_id].nametextid);
}
