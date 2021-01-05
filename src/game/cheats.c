#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/pak/pak.h"
#include "gvars/gvars.h"
#include "lib/lib_13130.h"
#include "types.h"

struct cheat g_Cheats[NUM_CHEATS] = {
	{ L_MPWEAPONS(75),  123,               SOLOSTAGEINDEX_EXTRACTION,     DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Hurricane Fists
	{ L_MPWEAPONS(76),  100,               SOLOSTAGEINDEX_G5BUILDING,     DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Cloaking Device
	{ L_MPWEAPONS(77),  230,               SOLOSTAGEINDEX_ESCAPE,         DIFF_A,  CHEATFLAG_TIMED                              }, // Invincible
	{ L_MPWEAPONS(78),  331,               SOLOSTAGEINDEX_SKEDARRUINS,    DIFF_PA, CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // All Guns in Solo
	{ L_MPWEAPONS(79),  427,               SOLOSTAGEINDEX_PELAGIC,        DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo
	{ L_MPWEAPONS(80),  191,               SOLOSTAGEINDEX_AIRBASE,        DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo, No Reloads
	{ L_MPWEAPONS(81),  0,                 SOLOSTAGEINDEX_INVESTIGATION,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Slo-mo Single Player
	{ L_MPWEAPONS(82),  0,                 SOLOSTAGEINDEX_CHICAGO,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // DK Mode
	{ L_MPWEAPONS(83),  170,               SOLOSTAGEINDEX_CRASHSITE,      DIFF_A,  CHEATFLAG_TIMED                              }, // Trent's Magnum
	{ L_MPWEAPONS(84),  447,               SOLOSTAGEINDEX_DEEPSEA,        DIFF_PA, CHEATFLAG_TIMED                              }, // FarSight
	{ L_MPWEAPONS(85),  0,                 SOLOSTAGEINDEX_G5BUILDING,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Jo
	{ L_MPWEAPONS(86),  0,                 SOLOSTAGEINDEX_INFILTRATION,   DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Characters
	{ L_MPWEAPONS(87),  0,                 SOLOSTAGEINDEX_DEFENSE,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Shields
	{ L_MPWEAPONS(88),  0,                 SOLOSTAGEINDEX_DEEPSEA,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Jo Shield
	{ L_MPWEAPONS(89),  105,               SOLOSTAGEINDEX_DEFENSE,        DIFF_A,  CHEATFLAG_TIMED                              }, // Super Shield
	{ L_MPWEAPONS(90),  0,                 SOLOSTAGEINDEX_DEFECTION,      DIFF_A,  CHEATFLAG_COMPLETION                         }, // Classic Sight
	{ L_MPWEAPONS(91),  0,                 SOLOSTAGEINDEX_AIRBASE,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Team Heads Only
	{ L_MPWEAPONS(92),  479,               SOLOSTAGEINDEX_RESCUE,         DIFF_PA, CHEATFLAG_TIMED                              }, // Play as Elvis
	{ L_MPWEAPONS(93),  0,                 SOLOSTAGEINDEX_PELAGIC,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Rockets
	{ L_MPWEAPONS(94),  235,               SOLOSTAGEINDEX_AIRFORCEONE,    DIFF_PA, CHEATFLAG_TIMED                              }, // Unlimited Ammo - Laptop Sentry Gun
	{ L_MPWEAPONS(95),  90,                SOLOSTAGEINDEX_DEFECTION,      DIFF_SA, CHEATFLAG_TIMED                              }, // Marquis of Queensbury Rules
	{ L_MPWEAPONS(96),  0,                 SOLOSTAGEINDEX_CRASHSITE,      DIFF_A,  CHEATFLAG_COMPLETION                         }, // Perfect Darkness
	{ L_MPWEAPONS(97),  390,               SOLOSTAGEINDEX_INVESTIGATION,  DIFF_PA, CHEATFLAG_TIMED                              }, // Pugilist
	{ L_MPWEAPONS(98),  300,               SOLOSTAGEINDEX_INFILTRATION,   DIFF_SA, CHEATFLAG_TIMED                              }, // Hotshot
	{ L_MPWEAPONS(99),  150,               SOLOSTAGEINDEX_VILLA,          DIFF_SA, CHEATFLAG_TIMED                              }, // Hit and Run
	{ L_MPWEAPONS(100), 317,               SOLOSTAGEINDEX_ATTACKSHIP,     DIFF_SA, CHEATFLAG_TIMED                              }, // Alien
	{ L_MPWEAPONS(101), 0,                 SOLOSTAGEINDEX_SKEDARRUINS,    DIFF_A,  CHEATFLAG_COMPLETION | CHEATFLAG_TRANSFERPAK }, // R-Tracker/Weapon Cache Locations
	{ L_MPWEAPONS(102), 0,                 SOLOSTAGEINDEX_EXTRACTION,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Rocket Launcher
	{ L_MPWEAPONS(103), 0,                 SOLOSTAGEINDEX_VILLA,          DIFF_A,  CHEATFLAG_COMPLETION                         }, // Sniper Rifle
	{ L_MPWEAPONS(104), 0,                 SOLOSTAGEINDEX_RESCUE,         DIFF_A,  CHEATFLAG_COMPLETION                         }, // X-Ray Scanner
	{ L_MPWEAPONS(105), 0,                 SOLOSTAGEINDEX_ESCAPE,         DIFF_A,  CHEATFLAG_COMPLETION                         }, // SuperDragon
	{ L_MPWEAPONS(106), 0,                 SOLOSTAGEINDEX_AIRFORCEONE,    DIFF_A,  CHEATFLAG_COMPLETION                         }, // Laptop Gun
	{ L_MPWEAPONS(107), 0,                 SOLOSTAGEINDEX_ATTACKSHIP,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Phoenix
	{ L_MPWEAPONS(108), 120,               SOLOSTAGEINDEX_CHICAGO,        DIFF_PA, CHEATFLAG_TIMED                              }, // Psychosis Gun
	{ L_MPWEAPONS(109), WEAPON_PP9I,       0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // PP9i
	{ L_MPWEAPONS(110), WEAPON_CC13,       0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // CC13
	{ L_MPWEAPONS(111), WEAPON_KL01313,    0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // KL01313
	{ L_MPWEAPONS(112), WEAPON_KF7SPECIAL, 0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // KF7 Special
	{ L_MPWEAPONS(113), WEAPON_ZZT,        0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // ZZT (9mm)
	{ L_MPWEAPONS(114), WEAPON_DMC,        0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // DMC
	{ L_MPWEAPONS(115), WEAPON_AR53,       0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // AR53
	{ L_MPWEAPONS(116), WEAPON_RCP45,      0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // RC-P45
};

u32 cheatIsUnlocked(s32 cheat_id)
{
	struct cheat *cheat = &g_Cheats[cheat_id];
	u32 unlocked = 0;

	if (cheat->flags & CHEATFLAG_FIRINGRANGE) {
		if (frIsClassicWeaponUnlocked(cheat->time)) {
			unlocked++;
		}
	} else if (cheat->flags & CHEATFLAG_COMPLETION) {
		if (g_SoloSaveFile.besttimes[cheat->stage_index][0]) {
			unlocked++;
		}
		if (g_SoloSaveFile.besttimes[cheat->stage_index][1]) {
			unlocked++;
		}
		if (g_SoloSaveFile.besttimes[cheat->stage_index][2]) {
			unlocked++;
		}
	} else {
		if (g_SoloSaveFile.besttimes[cheat->stage_index][cheat->difficulty] &&
				g_SoloSaveFile.besttimes[cheat->stage_index][cheat->difficulty] <= cheat->time) {
			unlocked++;
		}
	}

	if ((cheat->flags & CHEATFLAG_TRANSFERPAK) && savefileHasFlag(SAVEFILEFLAG_USED_TRANSFERPAK)) {
		unlocked++;
	}

	return unlocked;
}

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

		for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
			setCurrentPlayerNum(playernum);
			g_Vars.currentplayer->invincible = 1;
		}

		setCurrentPlayerNum(prevplayernum);
		break;
	case CHEAT_ALLGUNS:
		// Give all guns if only one player playing
		if (PLAYERCOUNT() == 1 && g_Vars.normmplayerisrunning == false) {
			prevplayernum = g_Vars.currentplayernum;

			for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
				setCurrentPlayerNum(playernum);
				invSetAllGuns(true);
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

		for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
			setCurrentPlayerNum(playernum);
			g_Vars.currentplayer->invincible = 1; // @bug?
		}

		setCurrentPlayerNum(prevplayernum);
		break;
	case CHEAT_ALLGUNS:
		if (PLAYERCOUNT() == 1 && g_Vars.normmplayerisrunning == false) {
			prevplayernum = g_Vars.currentplayernum;

			for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
				setCurrentPlayerNum(playernum);
				invSetAllGuns(false);
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

	if (g_Vars.stagenum != STAGE_CITRAINING) {
		g_CheatsActiveBank0 = g_CheatsEnabledBank0;
		g_CheatsActiveBank1 = g_CheatsEnabledBank1;

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 || g_Vars.normmplayerisrunning) {
			// Co-op/counter-op/multi - deactivate "Weapons for Jo in Solo" cheats
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
				(1 << CHEAT_KL01313 - 32) |
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
/*  f107708:	00000000 */ 	nop
/*  f10770c:	10000045 */ 	b	.L0f107824
/*  f107710:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107714:
/*  f107714:	10000043 */ 	b	.L0f107824
/*  f107718:	00001025 */ 	or	$v0,$zero,$zero
.L0f10771c:
/*  f10771c:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f107720:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f107724:	00484804 */ 	sllv	$t1,$t0,$v0
/*  f107728:	012a5824 */ 	and	$t3,$t1,$t2
/*  f10772c:	11600003 */ 	beqz	$t3,.L0f10773c
/*  f107730:	00000000 */ 	nop
/*  f107734:	1000003b */ 	b	.L0f107824
/*  f107738:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10773c:
/*  f10773c:	10000039 */ 	b	.L0f107824
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
/*  f10776c:	00000000 */ 	nop
/*  f107770:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f107774:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f107778:	004c2004 */ 	sllv	$a0,$t4,$v0
/*  f10777c:	00836824 */ 	and	$t5,$a0,$v1
/*  f107780:	11a00005 */ 	beqz	$t5,.L0f107798
/*  f107784:	24010014 */ 	addiu	$at,$zero,0x14
/*  f107788:	00807027 */ 	nor	$t6,$a0,$zero
/*  f10778c:	01c37824 */ 	and	$t7,$t6,$v1
/*  f107790:	10000023 */ 	b	.L0f107820
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
/*  f1077e0:	1000000f */ 	b	.L0f107820
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
/*  f107810:	10000003 */ 	b	.L0f107820
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
/*  f107830:	00000000 */ 	nop
);

// Mismatch due to different registers in case 6 (v1/a0)
//s32 cheatMenuHandleCheatCheckbox(u32 arg0, struct menuitem *item, s32 arg2)
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

s32 cheatMenuHandleBuddyCheckbox(u32 operation, struct menuitem *item, union handlerdata *data)
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

char *cheatGetNameIfUnlocked(struct menuitem *item)
{
	if (cheatIsUnlocked(item->param)) {
		return langGet(g_Cheats[item->param].nametextid);
	}

	return langGet(L_MPWEAPONS(74)); // "----------"
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
/*  f1079b0:	00000000 */ 	nop
/*  f1079b4:	0fc479e3 */ 	jal	func0f11e78c
/*  f1079b8:	00000000 */ 	nop
/*  f1079bc:	10400003 */ 	beqz	$v0,.L0f1079cc
/*  f1079c0:	00000000 */ 	nop
/*  f1079c4:	0fc43c4f */ 	jal	savefileSetFlag
/*  f1079c8:	24040023 */ 	addiu	$a0,$zero,0x23
.L0f1079cc:
/*  f1079cc:	3c067000 */ 	lui	$a2,%hi(func00002148)
/*  f1079d0:	3c057000 */ 	lui	$a1,%hi(func000022e0)
/*  f1079d4:	24c62148 */ 	addiu	$a2,$a2,%lo(func00002148)
/*  f1079d8:	24a422e0 */ 	addiu	$a0,$a1,%lo(func000022e0)
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
/*  f107a04:	3c016f76 */ 	lui	$at,0x99aa
/*  f107a08:	34214531 */ 	ori	$at,$at,0xbbcc
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
/*  f107a48:	00000000 */ 	nop
/*  f107a4c:	10400003 */ 	beqz	$v0,.L0f107a5c
/*  f107a50:	00000000 */ 	nop
/*  f107a54:	0fc43c4f */ 	jal	savefileSetFlag
/*  f107a58:	24040023 */ 	addiu	$a0,$zero,0x23
.L0f107a5c:
/*  f107a5c:	0fc52958 */ 	jal	func0f14a560
/*  f107a60:	00000000 */ 	nop
/*  f107a64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f107a68:
/*  f107a68:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f107a6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f107a70:	03e00008 */ 	jr	$ra
/*  f107a74:	00000000 */ 	nop
);

// Mismatch because it optimises the `end = &ptr[4]` line.
// It's calculating it as &func00002148 + 24 rather than ptr + 4.
//bool cheatMenuHandleDialog(u32 operation, struct menudialog *dialog, struct menu *menu)
//{
//	if (operation == MENUOP_OPEN) {
//		func0f14a52c();
//
//		if (func0f11e78c()) {
//			savefileSetFlag(SAVEFILEFLAG_USED_TRANSFERPAK);
//		}
//
//#if PIRACYCHECKS
//		{
//			u32 *ptr = (u32 *)&func00002148;
//			u32 *end = (u32 *)&func000022e0;
//			u32 checksum = 0;
//
//			while (ptr < end) {
//				checksum ^= ~*ptr;
//				ptr++;
//			}
//
//			if (checksum != 0x6f764531) {
//				ptr = (u32 *)&func00002148 + 20;
//				end = &ptr[4];
//
//				while (ptr < end) {
//					*ptr = 0x00000012;
//					ptr++;
//				}
//			}
//		}
//#endif
//	}
//
//	if (operation == MENUOP_CLOSE) {
//		if (func0f11e78c()) {
//			savefileSetFlag(SAVEFILEFLAG_USED_TRANSFERPAK);
//		}
//
//		func0f14a560();
//	}
//
//	return 0;
//}

char *cheatGetMarquee(struct menuitem *arg0)
{
	u32 cheat_id;
	char *ptr;
	char difficultyname[256];
	char cheatname[256];

	if (g_Menus[g_MpPlayerNum].curframe
			&& g_Menus[g_MpPlayerNum].curframe->focuseditem
			&& g_Menus[g_MpPlayerNum].curframe->focuseditem->type == MENUITEMTYPE_CHECKBOX) {
		cheat_id = g_Menus[g_MpPlayerNum].curframe->focuseditem->param;

		if (g_Menus[g_MpPlayerNum].curframe->dialog == &g_CheatsBuddiesMenuDialog
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem == &g_CheatsBuddiesMenuItems[0]) {
			// Velvet
			sprintf(g_CheatMarqueeString, "%s: %s", langGet(L_MPWEAPONS(143)), langGet(L_MPWEAPONS(117))); // "Buddy Available", "Velvet Dark"
			return g_CheatMarqueeString;
		}

		if (cheatIsUnlocked(cheat_id)) {
			// Show cheat name
			sprintf(g_CheatMarqueeString, "%s: %s\n",
					g_Menus[g_MpPlayerNum].curframe->dialog == &g_CheatsBuddiesMenuDialog ? langGet(L_MPWEAPONS(143)) : langGet(L_MPWEAPONS(136)), // "Buddy Available", "Cheat available"
					langGet(g_Cheats[cheat_id].nametextid)
			);
			return g_CheatMarqueeString;
		}

		// Locked
		strcpy(cheatname, langGet(g_Cheats[cheat_id].nametextid));
		ptr = cheatname;

		while (*ptr != '\n') {
			ptr++;
		}

		*ptr = '\0';

		if (g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION) {
			sprintf(g_CheatMarqueeString, "%s %s: %s %s %s",
					langGet(L_MPWEAPONS(137)), // "Complete"
					langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
					langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
					langGet(L_MPWEAPONS(138)), // "for cheat:"
					&cheatname
			);
		} else {
			// Timed
			strcpy(difficultyname, langGet(L_OPTIONS(251) + g_Cheats[cheat_id].difficulty));
			ptr = difficultyname;

			while (*ptr != '\n') {
				ptr++;
			}

			*ptr = '\0';

			sprintf(g_CheatMarqueeString, "%s %s: %s %s %s %s %d:%02d %s %s",
					langGet(L_MPWEAPONS(137)), // "Complete"
					langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
					langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
					langGet(L_MPWEAPONS(139)), // "on"
					&difficultyname,
					langGet(L_MPWEAPONS(140)), // "in under"
					g_Cheats[cheat_id].time / 60,
					g_Cheats[cheat_id].time % 60,
					langGet(L_MPWEAPONS(138)), // "for cheat:"
					&cheatname
			);
		}

		if (g_Cheats[cheat_id].flags & CHEATFLAG_TRANSFERPAK) {
			strcat(g_CheatMarqueeString, langGet(L_MPWEAPONS(141))); // " or insert Game Boy ..."
		}

		strcat(g_CheatMarqueeString, "\n");

		return g_CheatMarqueeString;
	}

	// No cheat selected
	return langGet(L_MPWEAPONS(142)); // "Select cheat for information"
}

s32 cheatMenuHandleTurnOffAllCheats(u32 operation, struct menuitem *item, union handlerdata *data)
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
	return langGet(g_Cheats[cheat_id].nametextid);
}

struct menuitem g_CheatsWarningMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(479), 0x00000000, NULL }, // "If you activate any cheats, then you will be unable to progress further in the game while those cheats are active."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(480), 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(481), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_CheatsWarningMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU(478), // "Warning"
	g_CheatsWarningMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_CheatsFunMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_DKMODE,          0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_SMALLJO,         0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_SMALLCHARACTERS, 0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_TEAMHEADSONLY,   0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_PLAYASELVIS,     0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_SLOMO,           0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_MARQUEE,    0,                     0x00000a00, (u32)&cheatGetMarquee,        0x00000000, NULL                         },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_SELECTABLE, 0,                     0x00000028, L_MPMENU(477),                0x00000000, NULL                         }, // "Done"
	{ MENUITEMTYPE_END,        0,                     0x00000000, 0x00000000,                   0x00000000, NULL                         },
};

struct menudialog g_CheatsFunMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(118), // "Fun"
	g_CheatsFunMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menuitem g_CheatsGameplayMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_INVINCIBLE,      0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_CLOAKINGDEVICE,  0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_MARQUIS,         0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_JOSHIELD,        0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_SUPERSHIELD,     0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_ENEMYSHIELDS,    0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_ENEMYROCKETS,    0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_PERFECTDARKNESS, 0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_MARQUEE,    0,                     0x00000a00, (u32)&cheatGetMarquee,        0x00000000, NULL                         },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_SELECTABLE, 0,                     0x00000028, L_MPMENU(477),                0x00000000, NULL                         }, // "Done"
	{ MENUITEMTYPE_END,        0,                     0x00000000, 0x00000000,                   0x00000000, NULL                         },
};

struct menudialog g_CheatsGameplayMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(119), // "Gameplay"
	g_CheatsGameplayMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menuitem g_CheatsSoloWeaponsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_ROCKETLAUNCHER, 0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_SNIPERRIFLE,    0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_SUPERDRAGON,    0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_LAPTOPGUN,      0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_PHOENIX,        0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_PSYCHOSISGUN,   0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_TRENTSMAGNUM,   0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_FARSIGHT,       0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_MARQUEE,    0,                    0x00000a00, (u32)&cheatGetMarquee,        0x00000000, NULL                         },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_MPMENU(477),                0x00000000, NULL                         }, // "Done"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,                   0x00000000, NULL                         },
};

struct menudialog g_CheatsSoloWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(122), // "Weapons for Jo in Solo"
	g_CheatsSoloWeaponsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menuitem g_CheatsClassicWeaponsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_PP9I,       0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_CC13,       0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_KL01313,    0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_KF7SPECIAL, 0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_ZZT,        0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_DMC,        0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_AR53,       0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_RCP45,      0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,  0,                0x00000000, 0x000000c8,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_MARQUEE,    0,                0x00000a00, L_MPWEAPONS(144),             0x00000000, NULL                         }, // "Win Golds on the firing range to enable classic guns."
	{ MENUITEMTYPE_SEPARATOR,  0,                0x00000000, 0x000000c8,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_SELECTABLE, 0,                0x00000028, L_MPMENU(477),                0x00000000, NULL                         }, // "Done"
	{ MENUITEMTYPE_END,        0,                0x00000000, 0x00000000,                   0x00000000, NULL                         },
};

struct menudialog g_CheatsClassicWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(123), // "Classic Weapons for Jo in Solo"
	g_CheatsClassicWeaponsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menuitem g_CheatsWeaponsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_CLASSICSIGHT,           0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_UNLIMITEDAMMOLAPTOP,    0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_HURRICANEFISTS,         0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_UNLIMITEDAMMO,          0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_UNLIMITEDAMMONORELOADS, 0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_XRAYSCANNER,            0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_RTRACKER,               0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_ALLGUNS,                0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,  0,                            0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_MARQUEE,    0,                            0x00000a00, (u32)&cheatGetMarquee,        0x00000000, NULL                         },
	{ MENUITEMTYPE_SEPARATOR,  0,                            0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_SELECTABLE, 0,                            0x00000028, L_MPMENU(477),                0x00000000, NULL                         }, // "Done"
	{ MENUITEMTYPE_END,        0,                            0x00000000, 0x00000000,                   0x00000000, NULL                         },
};

struct menudialog g_CheatsWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(120), // "Weapons"
	g_CheatsWeaponsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menuitem g_CheatsBuddiesMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0,               0x00000000, L_MPWEAPONS(117),             0x00000000, cheatMenuHandleBuddyCheckbox }, // "Velvet Dark"
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_PUGILIST,  0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_HOTSHOT,   0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_HITANDRUN, 0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_CHECKBOX,   CHEAT_ALIEN,     0x00000000, (u32)&cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_SEPARATOR,  0,               0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_MARQUEE,    0,               0x00000a00, (u32)&cheatGetMarquee,        0x00000000, NULL                         },
	{ MENUITEMTYPE_SEPARATOR,  0,               0x00000000, 0x00000096,                   0x00000000, NULL                         },
	{ MENUITEMTYPE_SELECTABLE, 0,               0x00000028, L_MPMENU(477),                0x00000000, NULL                         }, // "Done"
	{ MENUITEMTYPE_END,        0,               0x00000000, 0x00000000,                   0x00000000, NULL                         },
};

struct menudialog g_CheatsBuddiesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(121), // "Buddies"
	g_CheatsBuddiesMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menuitem g_CheatsMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000004, L_MPWEAPONS(118), 0x00000000, (void *)&g_CheatsFunMenuDialog            }, // "Fun"
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000004, L_MPWEAPONS(119), 0x00000000, (void *)&g_CheatsGameplayMenuDialog       }, // "Gameplay"
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000004, L_MPWEAPONS(122), 0x00000000, (void *)&g_CheatsSoloWeaponsMenuDialog    }, // "Weapons for Jo in Solo"
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000004, L_MPWEAPONS(123), 0x00000000, (void *)&g_CheatsClassicWeaponsMenuDialog }, // "Classic Weapons for Jo in Solo"
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000004, L_MPWEAPONS(120), 0x00000000, (void *)&g_CheatsWeaponsMenuDialog        }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000004, L_MPWEAPONS(121), 0x00000000, (void *)&g_CheatsBuddiesMenuDialog        }, // "Buddies"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000096,       0x00000000, NULL                              },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000000, L_MPWEAPONS(217), 0x00000000, cheatMenuHandleTurnOffAllCheats   }, // "Turn off all Cheats"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000096,       0x00000000, NULL                              },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000028, L_MPMENU(477),    0x00000000, NULL                              }, // "Done"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,       0x00000000, NULL                              },
};

struct menudialog g_CheatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(476), // "Cheats"
	g_CheatsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};
