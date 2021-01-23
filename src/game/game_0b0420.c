#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/inventory/items.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b69d0.h"
#include "game/game_0dcdb0.h"
#include "game/game_127910.h"
#include "game/mplayer/setup.h"
#include "game/game_197600.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_13130.h"
#include "types.h"

const char var7f1acda0[] = "%s: %d\n";

void func0f0b0420(struct hand *hand, s32 index)
{
	if (!weaponHasFlag(hand->weaponnum, WEAPONFLAG_00100000)) {
		g_Vars.currentplayerstats->shotcount[index]++;
	}
}

void func0f0b046c(struct hand *hand, s32 index)
{
	if (index == 0) {
		if (!weaponHasFlag(hand->weaponnum, WEAPONFLAG_00100000)) {
			var80070590 = 1;
			g_Vars.currentplayerstats->shotcount[index]++;
		}
	} else {
		if (var80070590) {
			if (!weaponHasFlag(hand->weaponnum, WEAPONFLAG_00100000)) {
				g_Vars.currentplayerstats->shotcount[index]++;
			}

			var80070590 = 0;
		}
	}
}

void func0f0b0520(void)
{
	var80070590 = 0;
}

s32 currentPlayerGetShotCount(u32 type)
{
	return g_Vars.currentplayerstats->shotcount[type];
}

void incrementKillCount(void)
{
	g_Vars.killcount++;
}

void incrementKnockoutCount(void)
{
	g_Vars.knockoutcount++;
}

void decrementKnockoutCount(void)
{
	g_Vars.knockoutcount--;
}

u8 getKnockoutCount(void)
{
	return g_Vars.knockoutcount;
}

u32 getKillCount(void)
{
	return g_Vars.killcount;
}

GLOBAL_ASM(
glabel func0f0b05a4
/*  f0b05a4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b05a8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b05ac:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b05b0:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f0b05b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b05b8:	8c6e001c */ 	lw	$t6,0x1c($v1)
/*  f0b05bc:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0b05c0:	ac6f001c */ 	sw	$t7,0x1c($v1)
/*  f0b05c4:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b05c8:	8c581960 */ 	lw	$t8,0x1960($v0)
/*  f0b05cc:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0b05d0:	ac591960 */ 	sw	$t9,0x1960($v0)
/*  f0b05d4:	8d090318 */ 	lw	$t1,0x318($t0)
/*  f0b05d8:	51200055 */ 	beqzl	$t1,.L0f0b0730
/*  f0b05dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b05e0:	0fc3089f */ 	jal	getMissionTime
/*  f0b05e4:	00000000 */ 	nop
/*  f0b05e8:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f0b05ec:	0fc5b9f1 */ 	jal	langGet
/*  f0b05f0:	24044c01 */ 	addiu	$a0,$zero,0x4c01
/*  f0b05f4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b05f8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b05fc:	8d0a0288 */ 	lw	$t2,0x288($t0)
/*  f0b0600:	3c057f1b */ 	lui	$a1,%hi(var7f1acda0)
/*  f0b0604:	24a5cda0 */ 	addiu	$a1,$a1,%lo(var7f1acda0)
/*  f0b0608:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0b060c:	00403025 */ 	or	$a2,$v0,$zero
/*  f0b0610:	0c004dad */ 	jal	sprintf
/*  f0b0614:	8d47001c */ 	lw	$a3,0x1c($t2)
/*  f0b0618:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0b061c:	0fc377c7 */ 	jal	hudmsgCreateViaPreset
/*  f0b0620:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b0624:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b0628:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b062c:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b0630:	8c6b001c */ 	lw	$t3,0x1c($v1)
/*  f0b0634:	29610002 */ 	slti	$at,$t3,0x2
/*  f0b0638:	54200011 */ 	bnezl	$at,.L0f0b0680
/*  f0b063c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b0640:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0b0644:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f0b0648:	8c6f0048 */ 	lw	$t7,0x48($v1)
/*  f0b064c:	8dae194c */ 	lw	$t6,0x194c($t5)
/*  f0b0650:	018e1023 */ 	subu	$v0,$t4,$t6
/*  f0b0654:	01e2082a */ 	slt	$at,$t7,$v0
/*  f0b0658:	50200004 */ 	beqzl	$at,.L0f0b066c
/*  f0b065c:	8c780044 */ 	lw	$t8,0x44($v1)
/*  f0b0660:	ac620048 */ 	sw	$v0,0x48($v1)
/*  f0b0664:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b0668:	8c780044 */ 	lw	$t8,0x44($v1)
.L0f0b066c:
/*  f0b066c:	0058082a */ 	slt	$at,$v0,$t8
/*  f0b0670:	50200003 */ 	beqzl	$at,.L0f0b0680
/*  f0b0674:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b0678:	ac620044 */ 	sw	$v0,0x44($v1)
/*  f0b067c:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0b0680:
/*  f0b0680:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0b0684:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b0688:	8c591954 */ 	lw	$t9,0x1954($v0)
/*  f0b068c:	ac591958 */ 	sw	$t9,0x1958($v0)
/*  f0b0690:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b0694:	8c491950 */ 	lw	$t1,0x1950($v0)
/*  f0b0698:	ac491954 */ 	sw	$t1,0x1954($v0)
/*  f0b069c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b06a0:	8c4a194c */ 	lw	$t2,0x194c($v0)
/*  f0b06a4:	ac4a1950 */ 	sw	$t2,0x1950($v0)
/*  f0b06a8:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0b06ac:	8fab002c */ 	lw	$t3,0x2c($sp)
/*  f0b06b0:	adab194c */ 	sw	$t3,0x194c($t5)
/*  f0b06b4:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b06b8:	8c451950 */ 	lw	$a1,0x1950($v0)
/*  f0b06bc:	50c50016 */ 	beql	$a2,$a1,.L0f0b0718
/*  f0b06c0:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b06c4:	8c43194c */ 	lw	$v1,0x194c($v0)
/*  f0b06c8:	00656023 */ 	subu	$t4,$v1,$a1
/*  f0b06cc:	29810078 */ 	slti	$at,$t4,0x78
/*  f0b06d0:	50200011 */ 	beqzl	$at,.L0f0b0718
/*  f0b06d4:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b06d8:	8c451954 */ 	lw	$a1,0x1954($v0)
/*  f0b06dc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0b06e0:	10c5000c */ 	beq	$a2,$a1,.L0f0b0714
/*  f0b06e4:	00657023 */ 	subu	$t6,$v1,$a1
/*  f0b06e8:	29c10078 */ 	slti	$at,$t6,0x78
/*  f0b06ec:	5020000a */ 	beqzl	$at,.L0f0b0718
/*  f0b06f0:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b06f4:	8c451958 */ 	lw	$a1,0x1958($v0)
/*  f0b06f8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0b06fc:	10c50005 */ 	beq	$a2,$a1,.L0f0b0714
/*  f0b0700:	00657823 */ 	subu	$t7,$v1,$a1
/*  f0b0704:	29e10078 */ 	slti	$at,$t7,0x78
/*  f0b0708:	50200003 */ 	beqzl	$at,.L0f0b0718
/*  f0b070c:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b0710:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f0b0714:
/*  f0b0714:	8d030288 */ 	lw	$v1,0x288($t0)
.L0f0b0718:
/*  f0b0718:	8c780058 */ 	lw	$t8,0x58($v1)
/*  f0b071c:	0304082a */ 	slt	$at,$t8,$a0
/*  f0b0720:	50200003 */ 	beqzl	$at,.L0f0b0730
/*  f0b0724:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b0728:	ac640058 */ 	sw	$a0,0x58($v1)
/*  f0b072c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b0730:
/*  f0b0730:	27bd0138 */ 	addiu	$sp,$sp,0x138
/*  f0b0734:	03e00008 */ 	jr	$ra
/*  f0b0738:	00000000 */ 	nop
);

s32 currentPlayerGetNumKills(void)
{
	return g_Vars.currentplayerstats->killcount;
}

void currentPlayerIncrementGgKillCount(void)
{
	g_Vars.currentplayerstats->ggkillcount++;
}

void currentPlayerIncrementDeathCount(void)
{
	char buffer[256];

	g_Vars.currentplayer->deathcount++;

	if (g_Vars.normmplayerisrunning) {
		if (g_Vars.currentplayer->deathcount == 1) {
			sprintf(buffer, langGet(L_GUN(2))); // "Died once"
		} else {
			sprintf(buffer, "%s %d %s\n",
					langGet(L_GUN(3)), // "Died"
					g_Vars.currentplayer->deathcount,
					langGet(L_GUN(4))); // "times"
		}

		hudmsgCreateViaPreset(buffer, HUDMSGTYPE_DEFAULT);
	}
}

void currentPlayerRecordSuicide(void)
{
	char text[256];
	s32 simulkills;
	s32 duration;
	s32 time;
	s32 mpindex;
	struct mpchr *mpchr;

	if (g_Vars.normmplayerisrunning) {
		time = getMissionTime();
		mpindex = g_Vars.currentplayerstats->mpindex;

		if (mpindex < 4) {
			mpchr = &g_MpPlayers[mpindex].base;
		} else {
			mpchr = &g_MpSimulants[mpindex - 4].base;
		}

		// Show HUD message
		// "Suicide count: %d"
		sprintf(text, "%s: %d\n", langGet(L_GUN(5)), mpchr->killcounts[mpindex]);
		hudmsgCreateViaPreset(text, HUDMSGTYPE_DEFAULT);

		// Update slowest/fastest two kills
		if (g_Vars.currentplayerstats->killcount > 1) {
			duration = time - g_Vars.currentplayer->lastkilltime60;

			if (duration > g_Vars.currentplayerstats->slowest2kills) {
				g_Vars.currentplayerstats->slowest2kills = duration;
			}

			if (duration < g_Vars.currentplayerstats->fastest2kills) {
				g_Vars.currentplayerstats->fastest2kills = duration;
			}
		}

		// Update max simultaneous kills
		simulkills = 1;

		g_Vars.currentplayer->lastkilltime60_4 = g_Vars.currentplayer->lastkilltime60_3;
		g_Vars.currentplayer->lastkilltime60_3 = g_Vars.currentplayer->lastkilltime60_2;
		g_Vars.currentplayer->lastkilltime60_2 = g_Vars.currentplayer->lastkilltime60;
		g_Vars.currentplayer->lastkilltime60 = time;

		if (g_Vars.currentplayer->lastkilltime60_2 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_2 < 120) {
			simulkills++;

			if (g_Vars.currentplayer->lastkilltime60_3 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_3 < 120) {
				simulkills++;

				if (g_Vars.currentplayer->lastkilltime60_4 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_4 < 120) {
					simulkills++;
				}
			}
		}

		if (simulkills > g_Vars.currentplayerstats->maxsimulkills) {
			g_Vars.currentplayerstats->maxsimulkills = simulkills;
		}
	}
}

void mpstatsRecordDeath(s32 aplayernum, s32 vplayernum)
{
	s32 vmpindex = -1;
	struct mpchr *vmpchr = NULL;
	s32 ampindex;
	struct mpchr *ampchr = NULL;
	s32 prevplayernum;
	char text[256];

	if (g_Vars.normmplayerisrunning && g_MpSetup.scenario == MPSCENARIO_POPACAP) {
		func0f1847b8();
	}

	// Find attacker and victim mpchrs
	if (aplayernum >= 0) {
		ampindex = func0f18d074(aplayernum);

		if (ampindex >= 0) {
			if (ampindex < 4) {
				ampchr = &g_MpPlayers[ampindex].base;
			} else {
				ampchr = &g_MpSimulants[ampindex - 4].base;
			}
		}
	}

	if (vplayernum >= 0) {
		vmpindex = func0f18d074(vplayernum);

		if (vmpindex >= 0) {
			if (vmpindex < 4) {
				vmpchr = &g_MpPlayers[vmpindex].base;
			} else {
				vmpchr = &g_MpSimulants[vmpindex - 4].base;
			}
		}
	}

	if (vplayernum >= 0 && aplayernum == vplayernum) {
		// Player suicide
		if (vmpchr && vmpindex >= 0) {
			vmpchr->numdeaths++;
			vmpchr->killcounts[vmpindex]++;
		}

		if (vplayernum < PLAYERCOUNT()) {
			prevplayernum = g_Vars.currentplayernum;
			setCurrentPlayerNum(vplayernum);
			currentPlayerRecordSuicide();
			setCurrentPlayerNum(prevplayernum);
		}
	} else {
		// Normal kill
		if (vplayernum >= 0) {
			if (vmpchr) {
				vmpchr->numdeaths++;
			}

			if (vplayernum < PLAYERCOUNT()) {
				// Victim was a player
				prevplayernum = g_Vars.currentplayernum;
				setCurrentPlayerNum(vplayernum);

				if (g_Vars.normmplayerisrunning && aplayernum >= 0) {
					// "Killed by %s"
					sprintf(text, "%s %s", langGet(L_MISC(183)), var800ac500[aplayernum]->name);
					hudmsgCreateViaPreset(text, HUDMSGTYPE_DEFAULT);
				}

				currentPlayerIncrementDeathCount();
				setCurrentPlayerNum(prevplayernum);
			}
		}

		if (ampchr && vmpindex >= 0) {
			ampchr->killcounts[vmpindex]++;
		}

		if (aplayernum >= 0 && aplayernum < PLAYERCOUNT()) {
			// Attacker was a player
			prevplayernum = g_Vars.currentplayernum;
			setCurrentPlayerNum(aplayernum);

			if (g_Vars.normmplayerisrunning && vplayernum >= 0) {
				// "Killed %s"
				sprintf(text, "%s %s", langGet(L_MISC(184)), var800ac500[vplayernum]->name);
				hudmsgCreateViaPreset(text, HUDMSGTYPE_DEFAULT);
			}

			func0f0b05a4();
			setCurrentPlayerNum(prevplayernum);
		}

		// If someone killed an aibot
		if (g_Vars.normmplayerisrunning
				&& aplayernum >= 0
				&& vplayernum >= PLAYERCOUNT()
				&& aplayernum != vplayernum) {
			g_MpPlayerChrs[vplayernum]->aibot->lastkilledbyplayernum = aplayernum;
		}
	}

	if (g_Vars.normmplayerisrunning && aplayernum >= 0 && g_MpPlayerChrs[aplayernum]->aibot) {
		s32 thing = func0f1982d4(g_MpPlayerChrs[aplayernum]->aibot->weaponnum);

		if (thing >= 0) {
			if (aplayernum == vplayernum) {
				g_MpPlayerChrs[aplayernum]->aibot->unk244[thing][g_MpPlayerChrs[aplayernum]->aibot->gunfunc]++;
			} else {
				g_MpPlayerChrs[aplayernum]->aibot->unk214[thing][g_MpPlayerChrs[aplayernum]->aibot->gunfunc]++;
			}
		}
	}

	g_Vars.unk000488++;
}

const u32 var7f1acdcc[] = {0x00000000};

struct weapon *weaponFindById(s32 itemid)
{
	if (itemid < 0) {
		return NULL;
	}

	if (itemid >= NUM_WEAPONS) {
		return NULL;
	}

	return g_Weapons[itemid];
}

struct weaponfunc *weaponGetFunctionById(u32 weaponnum, u32 which)
{
	struct weapon *weapon = weaponFindById(weaponnum);

	if (weapon) {
		return weapon->functions[which];
	}

	return NULL;
}

struct weaponfunc *handGetWeaponFunction2(struct hand *hand)
{
	struct weapon *weapon = weaponFindById(hand->weaponnum);

	if (weapon) {
		return weapon->functions[hand->weaponfunc];
	}

	return NULL;
}

struct weaponfunc *handGetWeaponFunction(struct hand *hand)
{
	struct weapon *weapon = g_Weapons[hand->weaponnum];

	if (weapon) {
		return weapon->functions[hand->weaponfunc];
	}

	return NULL;
}

struct weaponfunc *weaponGetFunction(u8 *arg0, s32 which)
{
	struct weapon *weapon = g_Weapons[*arg0];

	if (weapon) {
		return weapon->functions[which];
	}

	return NULL;
}

struct weaponfunc *currentPlayerGetWeaponFunction(u32 hand)
{
	struct weapon *weapon = weaponFindById(g_Vars.currentplayer->hands[hand].weaponnum);

	if (weapon) {
		return weapon->functions[g_Vars.currentplayer->hands[hand].weaponfunc];
	}

	return NULL;
}

u32 weaponGetNumFunctions(u32 weaponnum)
{
	struct weapon *weapon = weaponFindById(weaponnum);
	s32 i;

	if (!weapon) {
		return 0;
	}

	for (i = 0; i < 2; i++) {
		if (weapon->functions[i] == NULL) {
			return i;
		}
	}

	return 2;
}

GLOBAL_ASM(
glabel func0f0b11bc
/*  f0b11bc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b11c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b11c4:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b11c8:	90840000 */ 	lbu	$a0,0x0($a0)
/*  f0b11cc:	10400003 */ 	beqz	$v0,.L0f0b11dc
/*  f0b11d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b11d4:	10000003 */ 	b	.L0f0b11e4
/*  f0b11d8:	8c420024 */ 	lw	$v0,0x24($v0)
.L0f0b11dc:
/*  f0b11dc:	3c028007 */ 	lui	$v0,%hi(inve_000110c0)
/*  f0b11e0:	2442b0a0 */ 	addiu	$v0,$v0,%lo(inve_000110c0)
.L0f0b11e4:
/*  f0b11e4:	03e00008 */ 	jr	$ra
/*  f0b11e8:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

struct inventory_ammo *weaponGetAmmoByFunction(u32 weaponnum, u32 funcnum)
{
	struct weapon *weapon = weaponFindById(weaponnum);
	struct weaponfunc *func = weaponGetFunctionById(weaponnum, funcnum);

	if (func && weapon && func->ammoindex >= 0) {
		return weapon->ammos[func->ammoindex];
	}

	return NULL;
}

void currentPlayerGetWeaponSway(struct coord *sway)
{
	struct weapon *weapon = weaponFindById(handGetWeaponNum(HAND_RIGHT));

	if (weapon) {
		sway->x = weapon->leftright;
		sway->y = weapon->updown;
		sway->z = weapon->frontback;
	}
}

void currentPlayerSetWeaponSway(struct coord *sway)
{
	struct weapon *weapon = weaponFindById(handGetWeaponNum(HAND_RIGHT));

	if (weapon) {
		weapon->leftright = sway->x;
		weapon->updown = sway->y;
		weapon->frontback = sway->z;
	}
}

f32 handGetXOffset(u32 hand)
{
	return g_Vars.currentplayer->hands[hand].xoffset;
}

f32 func0f0b131c(u32 hand)
{
	f32 x;
	struct weapon *weapon;

	if (hand == 0) {
		weapon = weaponFindById(getCurrentPlayerWeaponIdWrapper(0));
		x = weapon->leftright;

		if (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
			x -= 3.5f;

			if (g_Vars.currentplayernum == 0) {
				x += 2.0f;
			}
		}
	} else {
		weapon = weaponFindById(getCurrentPlayerWeaponIdWrapper(1));
		x = -weapon->leftright;

		if (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
			x += 3.5f;

			if (g_Vars.currentplayernum == 0) {
				x += 2.0f;
			}
		}
	}

	return x;
}

f32 currentPlayerGetGunZoomFov(void)
{
	s32 index = -1;
	struct weapon *weapon;

	switch (getCurrentPlayerWeaponIdWrapper(0)) {
	case WEAPON_SNIPERRIFLE:    index = 0; break;
	case WEAPON_FARSIGHTXR20:   index = 1; break;
	case WEAPON_HORIZONSCANNER: index = 2; break;
	}

	if (index >= 0) {
		return g_Vars.currentplayer->gunzoomfovs[index];
	}

	weapon = weaponFindById(getCurrentPlayerWeaponIdWrapper(0));

	if (weapon) {
		f32 fov = weapon->eptr->zoomfov;
		return fov;
	}

	return 0;
}

void currentPlayerZoomOut(f32 fovpersec)
{
	s32 index = -1;

	switch (getCurrentPlayerWeaponIdWrapper(0)) {
	case WEAPON_SNIPERRIFLE:    index = 0; break;
	case WEAPON_FARSIGHTXR20:   index = 1; break;
	case WEAPON_HORIZONSCANNER: index = 2; break;
	}

	if (index >= 0) {
		f32 amount = fovpersec * 0.25f * g_Vars.lvupdate240f;

		if (getCurrentPlayerWeaponIdWrapper(0) == WEAPON_FARSIGHTXR20) {
			amount *= 0.5f;
		}

		g_Vars.currentplayer->gunzoomfovs[index] *= 1.0f + amount * 0.1f;

		if (g_Vars.currentplayer->gunzoomfovs[index] > 60) {
			g_Vars.currentplayer->gunzoomfovs[index] = 60;
		}
	}
}

void currentPlayerZoomIn(f32 fovpersec)
{
	s32 index = -1;

	switch (getCurrentPlayerWeaponIdWrapper(0)) {
	case WEAPON_SNIPERRIFLE:    index = 0; break;
	case WEAPON_FARSIGHTXR20:   index = 1; break;
	case WEAPON_HORIZONSCANNER: index = 2; break;
	}

	if (index >= 0) {
		f32 amount = fovpersec * 0.25f * g_Vars.lvupdate240f;

		if (getCurrentPlayerWeaponIdWrapper(0) == WEAPON_FARSIGHTXR20) {
			amount *= 0.5f;
		}

		g_Vars.currentplayer->gunzoomfovs[index] /= 1 + amount * 0.1f;

		if (g_Vars.currentplayer->gunzoomfovs[index] < 2) {
			g_Vars.currentplayer->gunzoomfovs[index] = 2;
		}
	}
}

bool weaponHasFlag(s32 itemid, u32 flag)
{
	struct weapon *weapon = weaponFindById(itemid);

	if (!weapon) {
		return false;
	}

	return (weapon->flags & flag) != 0;
}

bool weaponHasInvEFlag(s32 weaponnum, u32 flag)
{
	struct weapon *weapon = weaponFindById(weaponnum);

	if (!weapon) {
		return false;
	}

	return (weapon->eptr->flags & flag) != 0;
}

GLOBAL_ASM(
glabel func0f0b184c
/*  f0b184c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1850:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1854:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b1858:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b185c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0b1860:	14400003 */ 	bnez	$v0,.L0f0b1870
/*  f0b1864:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1868:	1000000e */ 	b	.L0f0b18a4
/*  f0b186c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1870:
/*  f0b1870:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f0b1874:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f0b1878:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b187c:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0b1880:	8f03001c */ 	lw	$v1,0x1c($t8)
/*  f0b1884:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1888:	10600006 */ 	beqz	$v1,.L0f0b18a4
/*  f0b188c:	00000000 */ 	nop
/*  f0b1890:	90790010 */ 	lbu	$t9,0x10($v1)
/*  f0b1894:	03281024 */ 	and	$v0,$t9,$t0
/*  f0b1898:	0002482b */ 	sltu	$t1,$zero,$v0
/*  f0b189c:	10000001 */ 	b	.L0f0b18a4
/*  f0b18a0:	01201025 */ 	or	$v0,$t1,$zero
.L0f0b18a4:
/*  f0b18a4:	03e00008 */ 	jr	$ra
/*  f0b18a8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b18ac:	03e00008 */ 	jr	$ra
/*  f0b18b0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f0b18b4:	03e00008 */ 	jr	$ra
/*  f0b18b8:	afa40000 */ 	sw	$a0,0x0($sp)
);

s32 currentPlayerGetDeviceState(s32 weaponnum)
{
	struct weapon *weapon = weaponFindById(weaponnum);
	s32 i;

	if (!weapon) {
		return DEVICESTATE_UNEQUIPPED;
	}

	for (i = 0; i < ARRAYCOUNT(weapon->functions); i++) {
		if (weapon->functions[i]) {
			struct weaponfunc_device *devicefunc = weapon->functions[i];

			if ((devicefunc->base.type & 0xff) == INVENTORYFUNCTYPE_DEVICE) {
				if ((g_Vars.currentplayer->devicesactive & devicefunc->device) == 0) {
					return DEVICESTATE_INACTIVE;
				}

				return DEVICESTATE_ACTIVE;
			}
		}
	}

	return DEVICESTATE_UNEQUIPPED;
}

void currentPlayerSetDeviceActive(s32 weaponnum, bool active)
{
	struct weapon *weapon = weaponFindById(weaponnum);
	s32 i;

	if (!weapon) {
		return;
	}

	for (i = 0; i < ARRAYCOUNT(weapon->functions); i++) {
		if (weapon->functions[i]) {
			struct weaponfunc_device *devicefunc = weapon->functions[i];

			if ((devicefunc->base.type & 0xff) == INVENTORYFUNCTYPE_DEVICE) {
				if (active) {
					if (devicefunc->device & (DEVICE_NIGHTVISION | DEVICE_XRAYSCANNER | DEVICE_EYESPY | DEVICE_IRSCANNER)) {
						g_Vars.currentplayer->devicesactive &= ~(DEVICE_NIGHTVISION | DEVICE_XRAYSCANNER | DEVICE_EYESPY | DEVICE_IRSCANNER);
					}

					g_Vars.currentplayer->devicesactive |= devicefunc->device;
					return;
				}

				g_Vars.currentplayer->devicesactive &= ~devicefunc->device;
				return;
			}
		}
	}
}

u16 weaponGetModelNum(s32 weaponnum)
{
	struct weapon *weapon = NULL;

	if (weaponnum != -1) {
		weapon = g_Weapons[weaponnum];
	}

	if (weapon) {
		if (PLAYERCOUNT() >= 2) {
			return weapon->lo_model;
		}

		return weapon->hi_model;
	}

	return 0;
}

u16 weaponGetModelNum2(s32 weaponnum)
{
	return weaponGetModelNum(weaponnum);
}

GLOBAL_ASM(
glabel func0f0b1af0
/*  f0b1af0:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0b1af4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0b1af8:	8cce0284 */ 	lw	$t6,0x284($a2)
/*  f0b1afc:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0b1b00:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0b1b04:	81cf1580 */ 	lb	$t7,0x1580($t6)
/*  f0b1b08:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0b1b0c:	00441021 */ 	addu	$v0,$v0,$a0
/*  f0b1b10:	a0af0000 */ 	sb	$t7,0x0($a1)
/*  f0b1b14:	8cd80284 */ 	lw	$t8,0x284($a2)
/*  f0b1b18:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0b1b1c:	00441021 */ 	addu	$v0,$v0,$a0
/*  f0b1b20:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0b1b24:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f0b1b28:	9328063b */ 	lbu	$t0,0x63b($t9)
/*  f0b1b2c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0b1b30:	31e300ff */ 	andi	$v1,$t7,0xff
/*  f0b1b34:	a0a80003 */ 	sb	$t0,0x3($a1)
/*  f0b1b38:	8cc90284 */ 	lw	$t1,0x284($a2)
/*  f0b1b3c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f0b1b40:	914b063a */ 	lbu	$t3,0x63a($t2)
/*  f0b1b44:	a0ab0002 */ 	sb	$t3,0x2($a1)
/*  f0b1b48:	8ccc0284 */ 	lw	$t4,0x284($a2)
/*  f0b1b4c:	01826821 */ 	addu	$t5,$t4,$v0
/*  f0b1b50:	91ae0639 */ 	lbu	$t6,0x639($t5)
/*  f0b1b54:	1461002a */ 	bne	$v1,$at,.L0f0b1c00
/*  f0b1b58:	a0ae0001 */ 	sb	$t6,0x1($a1)
/*  f0b1b5c:	8ccf0284 */ 	lw	$t7,0x284($a2)
/*  f0b1b60:	3c014120 */ 	lui	$at,0x4120
/*  f0b1b64:	44813000 */ 	mtc1	$at,$f6
/*  f0b1b68:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f0b1b6c:	c7040874 */ 	lwc1	$f4,0x874($t8)
/*  f0b1b70:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b1b74:	3c014f00 */ 	lui	$at,0x4f00
/*  f0b1b78:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0b1b7c:	4459f800 */ 	cfc1	$t9,$31
/*  f0b1b80:	44c8f800 */ 	ctc1	$t0,$31
/*  f0b1b84:	00000000 */ 	nop
/*  f0b1b88:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0b1b8c:	4448f800 */ 	cfc1	$t0,$31
/*  f0b1b90:	00000000 */ 	nop
/*  f0b1b94:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0b1b98:	51000013 */ 	beqzl	$t0,.L0f0b1be8
/*  f0b1b9c:	44085000 */ 	mfc1	$t0,$f10
/*  f0b1ba0:	44815000 */ 	mtc1	$at,$f10
/*  f0b1ba4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b1ba8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0b1bac:	44c8f800 */ 	ctc1	$t0,$31
/*  f0b1bb0:	00000000 */ 	nop
/*  f0b1bb4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0b1bb8:	4448f800 */ 	cfc1	$t0,$31
/*  f0b1bbc:	00000000 */ 	nop
/*  f0b1bc0:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0b1bc4:	15000005 */ 	bnez	$t0,.L0f0b1bdc
/*  f0b1bc8:	00000000 */ 	nop
/*  f0b1bcc:	44085000 */ 	mfc1	$t0,$f10
/*  f0b1bd0:	3c018000 */ 	lui	$at,0x8000
/*  f0b1bd4:	10000007 */ 	b	.L0f0b1bf4
/*  f0b1bd8:	01014025 */ 	or	$t0,$t0,$at
.L0f0b1bdc:
/*  f0b1bdc:	10000005 */ 	b	.L0f0b1bf4
/*  f0b1be0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0b1be4:	44085000 */ 	mfc1	$t0,$f10
.L0f0b1be8:
/*  f0b1be8:	00000000 */ 	nop
/*  f0b1bec:	0500fffb */ 	bltz	$t0,.L0f0b1bdc
/*  f0b1bf0:	00000000 */ 	nop
.L0f0b1bf4:
/*  f0b1bf4:	44d9f800 */ 	ctc1	$t9,$31
/*  f0b1bf8:	a0a80002 */ 	sb	$t0,0x2($a1)
/*  f0b1bfc:	90a30000 */ 	lbu	$v1,0x0($a1)
.L0f0b1c00:
/*  f0b1c00:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0b1c04:	14610005 */ 	bne	$v1,$at,.L0f0b1c1c
/*  f0b1c08:	00000000 */ 	nop
/*  f0b1c0c:	8cc90284 */ 	lw	$t1,0x284($a2)
/*  f0b1c10:	01225021 */ 	addu	$t2,$t1,$v0
/*  f0b1c14:	8d4c0b90 */ 	lw	$t4,0xb90($t2)
/*  f0b1c18:	a0ac0002 */ 	sb	$t4,0x2($a1)
.L0f0b1c1c:
/*  f0b1c1c:	03e00008 */ 	jr	$ra
/*  f0b1c20:	00000000 */ 	nop
);

struct inventory_ammo *handGetAmmoDefinition(struct hand *hand)
{
	struct weaponfunc *func = handGetWeaponFunction(hand);
	struct weapon *weapon = weaponFindById(hand->weaponnum);

	if (func && func->ammoindex >= 0) {
		return weapon->ammos[func->ammoindex];
	}

	return NULL;
}

u8 handGetSingleUnk3c(struct hand *hand)
{
	struct weaponfunc *func = handGetWeaponFunction(hand);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT_SINGLE) {
		struct weaponfunc_shootsingle *funcshoot = (struct weaponfunc_shootsingle *)func;
		return funcshoot->unk3c;
	}

	return 0;
}

u32 handGetCasingEject(struct hand *hand)
{
	u32 result = 0;
	struct inventory_ammo *ammo = handGetAmmoDefinition(hand);

	if (ammo) {
		result = ammo->casingeject;
	}

	return result;
}

f32 handGetSingleUnk34(struct hand *hand)
{
	struct weaponfunc *func = handGetWeaponFunction(hand);
	f32 result = 0;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT_SINGLE) {
		struct weaponfunc_shootsingle *funcshoot = (struct weaponfunc_shootsingle *)func;
		result = funcshoot->unk34;
	}

	return result;
}

GLOBAL_ASM(
glabel func0f0b1d28
/*  f0b1d28:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b1d2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1d30:	0fc2c41f */ 	jal	handGetWeaponFunction
/*  f0b1d34:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0b1d38:	44801000 */ 	mtc1	$zero,$f2
/*  f0b1d3c:	10400016 */ 	beqz	$v0,.L0f0b1d98
/*  f0b1d40:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0b1d44:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f0b1d48:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b1d4c:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0b1d50:	15c10002 */ 	bne	$t6,$at,.L0f0b1d5c
/*  f0b1d54:	01c01825 */ 	or	$v1,$t6,$zero
/*  f0b1d58:	c442001c */ 	lwc1	$f2,0x1c($v0)
.L0f0b1d5c:
/*  f0b1d5c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b1d60:	5461000a */ 	bnel	$v1,$at,.L0f0b1d8c
/*  f0b1d64:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b1d68:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f0b1d6c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0b1d70:	c4420014 */ 	lwc1	$f2,0x14($v0)
/*  f0b1d74:	15e10004 */ 	bne	$t7,$at,.L0f0b1d88
/*  f0b1d78:	3c01800a */ 	lui	$at,%hi(g_Vars+0x44)
/*  f0b1d7c:	c424a004 */ 	lwc1	$f4,%lo(g_Vars+0x44)($at)
/*  f0b1d80:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0b1d84:	00000000 */ 	nop
.L0f0b1d88:
/*  f0b1d88:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0b1d8c:
/*  f0b1d8c:	54610003 */ 	bnel	$v1,$at,.L0f0b1d9c
/*  f0b1d90:	90980000 */ 	lbu	$t8,0x0($a0)
/*  f0b1d94:	c4420020 */ 	lwc1	$f2,0x20($v0)
.L0f0b1d98:
/*  f0b1d98:	90980000 */ 	lbu	$t8,0x0($a0)
.L0f0b1d9c:
/*  f0b1d9c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0b1da0:	57010012 */ 	bnel	$t8,$at,.L0f0b1dec
/*  f0b1da4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b1da8:	90990002 */ 	lbu	$t9,0x2($a0)
/*  f0b1dac:	3c014f80 */ 	lui	$at,0x4f80
/*  f0b1db0:	44993000 */ 	mtc1	$t9,$f6
/*  f0b1db4:	07210004 */ 	bgez	$t9,.L0f0b1dc8
/*  f0b1db8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0b1dbc:	44815000 */ 	mtc1	$at,$f10
/*  f0b1dc0:	00000000 */ 	nop
/*  f0b1dc4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f0b1dc8:
/*  f0b1dc8:	3c014040 */ 	lui	$at,0x4040
/*  f0b1dcc:	44818000 */ 	mtc1	$at,$f16
/*  f0b1dd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b1dd4:	44812000 */ 	mtc1	$at,$f4
/*  f0b1dd8:	46104483 */ 	div.s	$f18,$f8,$f16
/*  f0b1ddc:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0b1de0:	46023082 */ 	mul.s	$f2,$f6,$f2
/*  f0b1de4:	00000000 */ 	nop
/*  f0b1de8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b1dec:
/*  f0b1dec:	0fc2883f */ 	jal	handIsAttackingOnThisTick
/*  f0b1df0:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*  f0b1df4:	10400007 */ 	beqz	$v0,.L0f0b1e14
/*  f0b1df8:	c7a20018 */ 	lwc1	$f2,0x18($sp)
/*  f0b1dfc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1e00:	0fc2883f */ 	jal	handIsAttackingOnThisTick
/*  f0b1e04:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*  f0b1e08:	10400002 */ 	beqz	$v0,.L0f0b1e14
/*  f0b1e0c:	c7a20018 */ 	lwc1	$f2,0x18($sp)
/*  f0b1e10:	46021080 */ 	add.s	$f2,$f2,$f2
.L0f0b1e14:
/*  f0b1e14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1e18:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b1e1c:	46001006 */ 	mov.s	$f0,$f2
/*  f0b1e20:	03e00008 */ 	jr	$ra
/*  f0b1e24:	00000000 */ 	nop
);

u8 handGetSingleUnk38(struct hand *hand)
{
	struct weaponfunc *func = handGetWeaponFunction(hand);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT_SINGLE) {
		struct weaponfunc_shootsingle *funcshoot = (struct weaponfunc_shootsingle *)func;
		return funcshoot->unk38;
	}

	return 0;
}

u16 handGetSingleShootSound(struct hand *hand)
{
	struct weaponfunc *func = handGetWeaponFunction(hand);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT_SINGLE) {
		struct weaponfunc_shootsingle *funcshoot = (struct weaponfunc_shootsingle *)func;
		return funcshoot->shootsound;
	}

	return 0;
}

bool handHasFunctionFlags(struct hand *hand, u32 flags)
{
	struct weaponfunc *func = handGetWeaponFunction(hand);

	if (func) {
		return (func->flags & flags) == flags;
	}

	return false;
}

s8 weaponGetMaxFireRatePerTick(u32 weaponnum, u32 funcindex)
{
	u32 stack[2];
	s32 result = 0;
	struct weapon *weapon = weaponFindById(weaponnum);
	struct weaponfunc *func = weapon->functions[funcindex];

	if (func && func->type == INVENTORYFUNCTYPE_SHOOT_AUTOMATIC) {
		struct weaponfunc_shootauto *autofunc = (struct weaponfunc_shootauto *)func;

		result = 3600.0f / autofunc->maxfirerate;
	}

	return result;
}

u32 currentPlayerGetSight(void)
{
	struct weaponfunc *func = weaponGetFunctionById(
			g_Vars.currentplayer->hands[HAND_RIGHT].weaponnum,
			g_Vars.currentplayer->hands[HAND_RIGHT].weaponfunc);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
		return SIGHT_NONE;
	}

	if (cheatIsActive(CHEAT_CLASSICSIGHT)) {
		return SIGHT_CLASSIC;
	}

	switch (g_Vars.currentplayer->hands[HAND_RIGHT].weaponnum) {
	case WEAPON_HORIZONSCANNER:
		return SIGHT_NONE;
	case WEAPON_NONE:
	case WEAPON_UNARMED:
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_RCP120:
	case WEAPON_SHOTGUN:
	case WEAPON_DEVASTATOR:
	case WEAPON_ROCKETLAUNCHER:
	case WEAPON_SLAYER:
	case WEAPON_COMBATKNIFE:
	case WEAPON_CROSSBOW:
	case WEAPON_TRANQUILIZER:
	case WEAPON_LASER:
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
	case WEAPON_ECMMINE:
		return SIGHT_DEFAULT;
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
	case WEAPON_SNIPERRIFLE:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_SUPERDRAGON:
		return SIGHT_ZOOM;
	case WEAPON_MAULER:
	case WEAPON_REAPER:
		return SIGHT_SKEDAR;
	case WEAPON_PHOENIX:
	case WEAPON_CALLISTONTG:
	case WEAPON_FARSIGHTXR20:
		return SIGHT_MAIAN;
	case WEAPON_PP9I:
	case WEAPON_CC13:
	case WEAPON_KL01313:
	case WEAPON_KF7SPECIAL:
	case WEAPON_ZZT:
	case WEAPON_DMC:
	case WEAPON_AR53:
	case WEAPON_RCP45:
		return SIGHT_CLASSIC;
	}

	return SIGHT_DEFAULT;
}

GLOBAL_ASM(
glabel func0f0b201c
/*  f0b201c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b2020:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b2024:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0b2028:	0fc2c41f */ 	jal	handGetWeaponFunction
/*  f0b202c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0b2030:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0b2034:	10400002 */ 	beqz	$v0,.L0f0b2040
/*  f0b2038:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0b203c:	8c430008 */ 	lw	$v1,0x8($v0)
.L0f0b2040:
/*  f0b2040:	54600004 */ 	bnezl	$v1,.L0f0b2054
/*  f0b2044:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f0b2048:	3c038007 */ 	lui	$v1,%hi(invmenupos_00010fd0)
/*  f0b204c:	2463afb0 */ 	addiu	$v1,$v1,%lo(invmenupos_00010fd0)
/*  f0b2050:	c4640000 */ 	lwc1	$f4,0x0($v1)
.L0f0b2054:
/*  f0b2054:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f0b2058:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f0b205c:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f0b2060:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f0b2064:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f0b2068:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f0b206c:	e4aa000c */ 	swc1	$f10,0xc($a1)
/*  f0b2070:	c4700010 */ 	lwc1	$f16,0x10($v1)
/*  f0b2074:	e4b00010 */ 	swc1	$f16,0x10($a1)
/*  f0b2078:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b207c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b2080:	03e00008 */ 	jr	$ra
/*  f0b2084:	00000000 */ 	nop
/*  f0b2088:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b208c:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b2090:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b2094:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b2098:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b209c:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b20a0:	10600003 */ 	beqz	$v1,.L0f0b20b0
/*  f0b20a4:	00000000 */ 	nop
/*  f0b20a8:	03e00008 */ 	jr	$ra
/*  f0b20ac:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f0b20b0:
/*  f0b20b0:	03e00008 */ 	jr	$ra
/*  f0b20b4:	00000000 */ 	nop
/*  f0b20b8:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b20bc:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b20c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b20c4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b20c8:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b20cc:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b20d0:	10600003 */ 	beqz	$v1,.L0f0b20e0
/*  f0b20d4:	00000000 */ 	nop
/*  f0b20d8:	03e00008 */ 	jr	$ra
/*  f0b20dc:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f0b20e0:
/*  f0b20e0:	03e00008 */ 	jr	$ra
/*  f0b20e4:	00000000 */ 	nop
);

u32 *handGetPriToSecAnim(struct hand *hand)
{
	struct weapon *weapon = g_Weapons[hand->weaponnum];

	if (weapon) {
		return weapon->pritosec_animation;
	}

	return NULL;
}

u32 *handGetSecToPriAnim(struct hand *hand)
{
	struct weapon *weapon = g_Weapons[hand->weaponnum];

	if (weapon) {
		return weapon->sectopri_animation;
	}

	return NULL;
}
