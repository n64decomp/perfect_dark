#include <ultra64.h>
#include "constants.h"
#include "boot/sched.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/pak/pak.h"
#include "gvars/gvars.h"
#include "data.h"
#include "types.h"

u32 g_CheatsActiveBank0;
u32 g_CheatsActiveBank1;
u32 g_CheatsEnabledBank0;
u32 g_CheatsEnabledBank1;

struct menuitem g_CheatsBuddiesMenuItems[];
struct menudialog g_CheatsBuddiesMenuDialog;

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

s32 cheatMenuHandleBuddyCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
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

s32 cheatMenuHandleDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		func0f14a52c();

		if (func0f11e78c()) {
			savefileSetFlag(SAVEFILEFLAG_USED_TRANSFERPAK);
		}

#if PIRACYCHECKS
		{
			u32 *ptr = (u32 *)&__scHandleRetrace;
			u32 *end = (u32 *)&__scHandleRSP;
			u32 checksum = 0;

			while (ptr < end) {
				checksum ^= ~*ptr;
				ptr++;
			}

			if (checksum != CHECKSUM_PLACEHOLDER) {
				ptr = (u32 *)&__scHandleRetrace + 20;
				if (1);
				end = &ptr[4];

				while (ptr < end) {
					*ptr = 0x00000012;
					ptr++;
				}
			}
		}
#endif
	}

	if (operation == MENUOP_CLOSE) {
		if (func0f11e78c()) {
			savefileSetFlag(SAVEFILEFLAG_USED_TRANSFERPAK);
		}

		func0f14a560();
	}

	return 0;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel cheatGetMarquee
/*  f108368:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10836c:	8dce1728 */ 	lw	$t6,0x1728($t6)
/*  f108370:	3c03800a */ 	lui	$v1,0x800a
/*  f108374:	27bdfd98 */ 	addiu	$sp,$sp,-616
/*  f108378:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10837c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108380:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108384:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108388:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10838c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108390:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108394:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f108398:	8c63ea98 */ 	lw	$v1,-0x1568($v1)
/*  f10839c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1083a0:	afa40268 */ 	sw	$a0,0x268($sp)
/*  f1083a4:	106000fd */ 	beqz	$v1,.PF0f10879c
/*  f1083a8:	00000000 */ 	nop
/*  f1083ac:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f1083b0:	104000fa */ 	beqz	$v0,.PF0f10879c
/*  f1083b4:	00000000 */ 	nop
/*  f1083b8:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1083bc:	24010009 */ 	li	$at,0x9
/*  f1083c0:	170100f6 */ 	bne	$t8,$at,.PF0f10879c
/*  f1083c4:	00000000 */ 	nop
/*  f1083c8:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f1083cc:	3c198007 */ 	lui	$t9,0x8007
/*  f1083d0:	2739465c */ 	addiu	$t9,$t9,0x465c
/*  f1083d4:	17290013 */ 	bne	$t9,$t1,.PF0f108424
/*  f1083d8:	90440001 */ 	lbu	$a0,0x1($v0)
/*  f1083dc:	3c0a8007 */ 	lui	$t2,0x8007
/*  f1083e0:	254a4594 */ 	addiu	$t2,$t2,0x4594
/*  f1083e4:	1542000f */ 	bne	$t2,$v0,.PF0f108424
/*  f1083e8:	00000000 */ 	nop
/*  f1083ec:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f1083f0:	24045490 */ 	li	$a0,0x5490
/*  f1083f4:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f1083f8:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f1083fc:	24045476 */ 	li	$a0,0x5476
/*  f108400:	3c04800a */ 	lui	$a0,0x800a
/*  f108404:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f108408:	24a541a0 */ 	addiu	$a1,$a1,0x41a0
/*  f10840c:	2484e430 */ 	addiu	$a0,$a0,-7120
/*  f108410:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f108414:	0c004d11 */ 	jal	0x13444
/*  f108418:	00403825 */ 	move	$a3,$v0
/*  f10841c:	100000cd */ 	b	.PF0f108754
/*  f108420:	00000000 */ 	nop
.PF0f108424:
/*  f108424:	0fc41d8c */ 	jal	0xf107630
/*  f108428:	afa40264 */ 	sw	$a0,0x264($sp)
/*  f10842c:	10400028 */ 	beqz	$v0,.PF0f1084d0
/*  f108430:	8fa90264 */ 	lw	$t1,0x264($sp)
/*  f108434:	3c0c8007 */ 	lui	$t4,0x8007
/*  f108438:	8d8c1728 */ 	lw	$t4,0x1728($t4)
/*  f10843c:	3c0e800a */ 	lui	$t6,0x800a
/*  f108440:	3c0b8007 */ 	lui	$t3,0x8007
/*  f108444:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f108448:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f10844c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f108450:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f108454:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f108458:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f10845c:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f108460:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f108464:	8dceea98 */ 	lw	$t6,-0x1568($t6)
/*  f108468:	256b465c */ 	addiu	$t3,$t3,0x465c
/*  f10846c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f108470:	156f0005 */ 	bne	$t3,$t7,.PF0f108488
/*  f108474:	00000000 */ 	nop
/*  f108478:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f10847c:	24045490 */ 	li	$a0,0x5490
/*  f108480:	10000004 */ 	b	.PF0f108494
/*  f108484:	afa20054 */ 	sw	$v0,0x54($sp)
.PF0f108488:
/*  f108488:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f10848c:	24045489 */ 	li	$a0,0x5489
/*  f108490:	afa20054 */ 	sw	$v0,0x54($sp)
.PF0f108494:
/*  f108494:	8fb80264 */ 	lw	$t8,0x264($sp)
/*  f108498:	3c048007 */ 	lui	$a0,0x8007
/*  f10849c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f1084a0:	00992021 */ 	addu	$a0,$a0,$t9
/*  f1084a4:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f1084a8:	94843e70 */ 	lhu	$a0,0x3e70($a0)
/*  f1084ac:	3c04800a */ 	lui	$a0,0x800a
/*  f1084b0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1084b4:	24a541a8 */ 	addiu	$a1,$a1,0x41a8
/*  f1084b8:	2484e430 */ 	addiu	$a0,$a0,-7120
/*  f1084bc:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f1084c0:	0c004d11 */ 	jal	0x13444
/*  f1084c4:	00403825 */ 	move	$a3,$v0
/*  f1084c8:	100000a2 */ 	b	.PF0f108754
/*  f1084cc:	00000000 */ 	nop
.PF0f1084d0:
/*  f1084d0:	3c0c8007 */ 	lui	$t4,0x8007
/*  f1084d4:	258c3e70 */ 	addiu	$t4,$t4,0x3e70
/*  f1084d8:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1084dc:	014c1021 */ 	addu	$v0,$t2,$t4
/*  f1084e0:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f1084e4:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f1084e8:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f1084ec:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f1084f0:	0c004bb0 */ 	jal	0x12ec0
/*  f1084f4:	00402825 */ 	move	$a1,$v0
/*  f1084f8:	93ad0060 */ 	lbu	$t5,0x60($sp)
/*  f1084fc:	2406000a */ 	li	$a2,0xa
/*  f108500:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f108504:	10cd0005 */ 	beq	$a2,$t5,.PF0f10851c
/*  f108508:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f10850c:	906e0001 */ 	lbu	$t6,0x1($v1)
.PF0f108510:
/*  f108510:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f108514:	54cefffe */ 	bnel	$a2,$t6,.PF0f108510
/*  f108518:	906e0001 */ 	lbu	$t6,0x1($v1)
.PF0f10851c:
/*  f10851c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f108520:	904b0006 */ 	lbu	$t3,0x6($v0)
/*  f108524:	316f0004 */ 	andi	$t7,$t3,0x4
/*  f108528:	51e00029 */ 	beqzl	$t7,.PF0f1085d0
/*  f10852c:	90440005 */ 	lbu	$a0,0x5($v0)
/*  f108530:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f108534:	2404548a */ 	li	$a0,0x548a
/*  f108538:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f10853c:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f108540:	3c048007 */ 	lui	$a0,0x8007
/*  f108544:	93190004 */ 	lbu	$t9,0x4($t8)
/*  f108548:	00194880 */ 	sll	$t1,$t9,0x2
/*  f10854c:	01394823 */ 	subu	$t1,$t1,$t9
/*  f108550:	00094880 */ 	sll	$t1,$t1,0x2
/*  f108554:	00892021 */ 	addu	$a0,$a0,$t1
/*  f108558:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f10855c:	94842162 */ 	lhu	$a0,0x2162($a0)
/*  f108560:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f108564:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f108568:	3c048007 */ 	lui	$a0,0x8007
/*  f10856c:	914c0004 */ 	lbu	$t4,0x4($t2)
/*  f108570:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f108574:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f108578:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f10857c:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f108580:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f108584:	94842164 */ 	lhu	$a0,0x2164($a0)
/*  f108588:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f10858c:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f108590:	2404548b */ 	li	$a0,0x548b
/*  f108594:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f108598:	3c04800a */ 	lui	$a0,0x800a
/*  f10859c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1085a0:	27ab0060 */ 	addiu	$t3,$sp,0x60
/*  f1085a4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1085a8:	24a541b0 */ 	addiu	$a1,$a1,0x41b0
/*  f1085ac:	2484e430 */ 	addiu	$a0,$a0,-7120
/*  f1085b0:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f1085b4:	8fa70050 */ 	lw	$a3,0x50($sp)
/*  f1085b8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1085bc:	0c004d11 */ 	jal	0x13444
/*  f1085c0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1085c4:	10000054 */ 	b	.PF0f108718
/*  f1085c8:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f1085cc:	90440005 */ 	lbu	$a0,0x5($v0)
.PF0f1085d0:
/*  f1085d0:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f1085d4:	248456fb */ 	addiu	$a0,$a0,0x56fb
/*  f1085d8:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f1085dc:	0c004bb0 */ 	jal	0x12ec0
/*  f1085e0:	00402825 */ 	move	$a1,$v0
/*  f1085e4:	93af0160 */ 	lbu	$t7,0x160($sp)
/*  f1085e8:	2406000a */ 	li	$a2,0xa
/*  f1085ec:	27a30160 */ 	addiu	$v1,$sp,0x160
/*  f1085f0:	10cf0005 */ 	beq	$a2,$t7,.PF0f108608
/*  f1085f4:	2404548a */ 	li	$a0,0x548a
/*  f1085f8:	90780001 */ 	lbu	$t8,0x1($v1)
.PF0f1085fc:
/*  f1085fc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f108600:	54d8fffe */ 	bnel	$a2,$t8,.PF0f1085fc
/*  f108604:	90780001 */ 	lbu	$t8,0x1($v1)
.PF0f108608:
/*  f108608:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f10860c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f108610:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f108614:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f108618:	3c048007 */ 	lui	$a0,0x8007
/*  f10861c:	93290004 */ 	lbu	$t1,0x4($t9)
/*  f108620:	00095080 */ 	sll	$t2,$t1,0x2
/*  f108624:	01495023 */ 	subu	$t2,$t2,$t1
/*  f108628:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f10862c:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f108630:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f108634:	94842162 */ 	lhu	$a0,0x2162($a0)
/*  f108638:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f10863c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f108640:	3c048007 */ 	lui	$a0,0x8007
/*  f108644:	918d0004 */ 	lbu	$t5,0x4($t4)
/*  f108648:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f10864c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f108650:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f108654:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f108658:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f10865c:	94842164 */ 	lhu	$a0,0x2164($a0)
/*  f108660:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f108664:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f108668:	2404548c */ 	li	$a0,0x548c
/*  f10866c:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f108670:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f108674:	2404548d */ 	li	$a0,0x548d
/*  f108678:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f10867c:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f108680:	2404548b */ 	li	$a0,0x548b
/*  f108684:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f108688:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f10868c:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f108690:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f108694:	27b80160 */ 	addiu	$t8,$sp,0x160
/*  f108698:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f10869c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1086a0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1086a4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1086a8:	95230002 */ 	lhu	$v1,0x2($t1)
/*  f1086ac:	2408003c */ 	li	$t0,0x3c
/*  f1086b0:	3c04800a */ 	lui	$a0,0x800a
/*  f1086b4:	0068001a */ 	div	$zero,$v1,$t0
/*  f1086b8:	00006010 */ 	mfhi	$t4
/*  f1086bc:	00005012 */ 	mflo	$t2
/*  f1086c0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1086c4:	27ad0060 */ 	addiu	$t5,$sp,0x60
/*  f1086c8:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f1086cc:	24a541c0 */ 	addiu	$a1,$a1,0x41c0
/*  f1086d0:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f1086d4:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f1086d8:	2484e430 */ 	addiu	$a0,$a0,-7120
/*  f1086dc:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f1086e0:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f1086e4:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f1086e8:	15000002 */ 	bnez	$t0,.PF0f1086f4
/*  f1086ec:	00000000 */ 	nop
/*  f1086f0:	0007000d */ 	break	0x7
.PF0f1086f4:
/*  f1086f4:	2401ffff */ 	li	$at,-1
/*  f1086f8:	15010004 */ 	bne	$t0,$at,.PF0f10870c
/*  f1086fc:	3c018000 */ 	lui	$at,0x8000
/*  f108700:	14610002 */ 	bne	$v1,$at,.PF0f10870c
/*  f108704:	00000000 */ 	nop
/*  f108708:	0006000d */ 	break	0x6
.PF0f10870c:
/*  f10870c:	0c004d11 */ 	jal	0x13444
/*  f108710:	00000000 */ 	nop
/*  f108714:	8fae0040 */ 	lw	$t6,0x40($sp)
.PF0f108718:
/*  f108718:	91cb0006 */ 	lbu	$t3,0x6($t6)
/*  f10871c:	316f0002 */ 	andi	$t7,$t3,0x2
/*  f108720:	11e00007 */ 	beqz	$t7,.PF0f108740
/*  f108724:	00000000 */ 	nop
/*  f108728:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f10872c:	2404548e */ 	li	$a0,0x548e
/*  f108730:	3c04800a */ 	lui	$a0,0x800a
/*  f108734:	2484e430 */ 	addiu	$a0,$a0,-7120
/*  f108738:	0c004bed */ 	jal	0x12fb4
/*  f10873c:	00402825 */ 	move	$a1,$v0
.PF0f108740:
/*  f108740:	3c04800a */ 	lui	$a0,0x800a
/*  f108744:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f108748:	24a541e4 */ 	addiu	$a1,$a1,0x41e4
/*  f10874c:	0c004bed */ 	jal	0x12fb4
/*  f108750:	2484e430 */ 	addiu	$a0,$a0,-7120
.PF0f108754:
/*  f108754:	3c04800a */ 	lui	$a0,0x800a
/*  f108758:	0c0127c3 */ 	jal	0x49f0c
/*  f10875c:	2484e430 */ 	addiu	$a0,$a0,-7120
/*  f108760:	3c188007 */ 	lui	$t8,0x8007
/*  f108764:	8f18402c */ 	lw	$t8,0x402c($t8)
/*  f108768:	3c198007 */ 	lui	$t9,0x8007
/*  f10876c:	13020008 */ 	beq	$t8,$v0,.PF0f108790
/*  f108770:	00000000 */ 	nop
/*  f108774:	8f394028 */ 	lw	$t9,0x4028($t9)
/*  f108778:	3c018007 */ 	lui	$at,0x8007
/*  f10877c:	ac22402c */ 	sw	$v0,0x402c($at)
/*  f108780:	0322082a */ 	slt	$at,$t9,$v0
/*  f108784:	10200002 */ 	beqz	$at,.PF0f108790
/*  f108788:	3c018007 */ 	lui	$at,0x8007
/*  f10878c:	ac224028 */ 	sw	$v0,0x4028($at)
.PF0f108790:
/*  f108790:	3c02800a */ 	lui	$v0,0x800a
/*  f108794:	10000003 */ 	b	.PF0f1087a4
/*  f108798:	2442e430 */ 	addiu	$v0,$v0,-7120
.PF0f10879c:
/*  f10879c:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f1087a0:	2404548f */ 	li	$a0,0x548f
.PF0f1087a4:
/*  f1087a4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1087a8:	27bd0268 */ 	addiu	$sp,$sp,0x268
/*  f1087ac:	03e00008 */ 	jr	$ra
/*  f1087b0:	00000000 */ 	nop
);
#else
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
#endif

s32 cheatMenuHandleTurnOffAllCheats(s32 operation, struct menuitem *item, union handlerdata *data)
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
