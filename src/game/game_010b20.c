#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/inventory/items.h"
#include "game/game_097ba0.h"
#include "game/game_1655c0.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "types.h"

GLOBAL_ASM(
glabel casingsReset
/*  f010b20:	3c04800a */ 	lui	$a0,%hi(var8009d0d0)
/*  f010b24:	2484d0d0 */ 	addiu	$a0,$a0,%lo(var8009d0d0)
/*  f010b28:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f010b2c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f010b30:	3c01800a */ 	lui	$at,%hi(var8009d0d8)
/*  f010b34:	3c03800a */ 	lui	$v1,%hi(var8009d0e0)
/*  f010b38:	3c02800a */ 	lui	$v0,%hi(var8009d0f0)
/*  f010b3c:	ac20d0d8 */ 	sw	$zero,%lo(var8009d0d8)($at)
/*  f010b40:	2442d0f0 */ 	addiu	$v0,$v0,%lo(var8009d0f0)
/*  f010b44:	2463d0e0 */ 	addiu	$v1,$v1,%lo(var8009d0e0)
.L0f010b48:
/*  f010b48:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f010b4c:	1462fffe */ 	bne	$v1,$v0,.L0f010b48
/*  f010b50:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f010b54:	3c02800a */ 	lui	$v0,%hi(var8009da60)
/*  f010b58:	3c03800a */ 	lui	$v1,%hi(g_Casings)
/*  f010b5c:	2442da60 */ 	addiu	$v0,$v0,%lo(var8009da60)
/*  f010b60:	2463d510 */ 	addiu	$v1,$v1,%lo(g_Casings)
.L0f010b64:
/*  f010b64:	24630044 */ 	addiu	$v1,$v1,0x44
/*  f010b68:	0062082b */ 	sltu	$at,$v1,$v0
/*  f010b6c:	1420fffd */ 	bnez	$at,.L0f010b64
/*  f010b70:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f010b74:	3c018007 */ 	lui	$at,%hi(g_CasingsActive)
/*  f010b78:	3c03800a */ 	lui	$v1,%hi(g_Fireslots)
/*  f010b7c:	3c04800a */ 	lui	$a0,%hi(g_Casings)
/*  f010b80:	ac200524 */ 	sw	$zero,%lo(g_CasingsActive)($at)
/*  f010b84:	2484d510 */ 	addiu	$a0,$a0,%lo(g_Casings)
/*  f010b88:	2463d150 */ 	addiu	$v1,$v1,%lo(g_Fireslots)
/*  f010b8c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f010b90:
/*  f010b90:	24630030 */ 	addiu	$v1,$v1,0x30
/*  f010b94:	1464fffe */ 	bne	$v1,$a0,.L0f010b90
/*  f010b98:	ac62ffd0 */ 	sw	$v0,-0x30($v1)
/*  f010b9c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f010ba0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f010ba4:	ac4002b0 */ 	sw	$zero,0x2b0($v0)
/*  f010ba8:	03e00008 */ 	jr	$ra
/*  f010bac:	ac4002b4 */ 	sw	$zero,0x2b4($v0)
);

// Mismatch: Two instructions are swapped
//void casingsReset(void)
//{
//	s32 i;
//
//	var8009d0d0[0] = 0;
//	var8009d0d0[1] = 0;
//	var8009d0d8 = 0;
//
//	for (i = 0; i != ARRAYCOUNT(var8009d0e0); i++) {
//		var8009d0e0[i] = 0;
//	}
//
//	for (i = 0; i < ARRAYCOUNT(g_Casings); i++) {
//		g_Casings[i].unk40 = 0;
//	}
//
//	g_CasingsActive = 0;
//
//	for (i = 0; i < ARRAYCOUNT(g_Fireslots); i++) {
//		g_Fireslots[i].unk00 = -1;
//	}
//
//	g_Vars.killcount = 0;
//	g_Vars.knockoutcount = 0;
//}

extern u32 var800700ac;

void func0f010bb0(void)
{
	s32 i;

	struct hand hand = {
		0,                 // weaponnum
		0,                 // unk0639
		0,                 // unk063a
		0,                 // weaponfunc
		0,                 // unk063c
		0,                 // torchon
		1,                 // unk063e
		0,                 // unk063f
		0,                 // unk0640
		0,                 // firing
		0,                 // prevfiring
		0,                 // unk064c
		0,                 // unk0650
		0,                 // unk0654
		0,                 // unk0658
		0,                 // unk065c
		0,                 // unk0660
		0,                 // unk0664
		0,                 // unk0668
		0,                 // unk066c
		0,                 // unk0670
		0,                 // unk0674
		0,                 // unk0678
		0,                 // unk067c
		0,                 // unk0680
		0,                 // unk0684
		0,                 // unk0688
		0,                 // unk068c
		0,                 // unk0690
		0,                 // unk0694
		0,                 // unk0698
		0,                 // unk069c
		0,                 // unk06a0
		0,                 // unk06a4
		0,                 // unk06a8
		1,                 // unk06ac
		0,                 // unk06b0
		0,                 // unk06b4
		0,                 // unk06b8
		0,                 // unk06bc
		1,                 // unk06c0
		0,                 // unk06c4
		0,                 // unk06c8
		0,                 // unk06cc
		0,                 // unk06d0
		1,                 // unk06d4
		0,                 // unk06d8
		0,                 // unk06dc
		0,                 // unk06e0
		0,                 // unk06e4
		1,                 // unk06e8
		0,                 // unk06ec
		0,                 // unk06f0
		0,                 // unk06f4
		0,                 // unk06f8
		0,                 // unk06fc
		0,                 // unk0700
		-1,                // unk0704
		0,                 // unk0708
		1,                 // unk070c
		0,                 // unk0710
		0,                 // unk0714
		0,                 // unk0718
		0,                 // unk071c
		0,                 // unk0720
		0,                 // unk0724
		-19.999996185303f, // unk0728
		0,                 // unk072c
		19.999996185303f,  // unk0730
		0,                 // unk0734
		0,                 // unk0738
		0,                 // unk073c
		0,                 // unk0740
		0,                 // unk0744
		0,                 // unk0748
		0,                 // unk074c
		0,                 // unk0750
		0,                 // unk0754
		0,                 // unk0758
		0,                 // unk075c
		0,                 // unk0760
		0,                 // unk0764
		0,                 // unk0768
		0,                 // unk076c
		-1,                // unk0770
		0,                 // unk0774
		0,                 // unk0778
		-1,                // unk077c
		0,                 // unk0780
		0,                 // unk0784
		-1,                // unk0788
		0,                 // unk078c
		0,                 // unk0790
		-1,                // unk0794
		0,                 // unk0798
		1,                 // unk079c
		0,                 // unk07a0
		0,                 // unk07a4
		1,                 // unk07a8
		0,                 // unk07ac
		0,                 // unk07b0
		1,                 // unk07b4
		0,                 // unk07b8
		0,                 // unk07bc
		1,                 // unk07c0
		0,                 // unk07c4
		0,                 // unk07c8
		0,                 // unk07cc
		1,                 // unk07d0
		1,                 // unk07d4
		0,                 // unk07d8
		0,                 // unk07dc
		0,                 // unk07e0
		0,                 // unk07e4
		0,                 // unk07e8
		0,                 // unk07ec
		0,                 // unk07f0
		0,                 // xoffset
		{0, 0, 1000},      // unk07f8
		0,                 // audiohandle2
		0,                 // unk0808
		0,                 // unk080c
		0,                 // unk0810
		{-1},              // bullettail
	};

	if (IS4MB() && PLAYERCOUNT() == 2) {
		i = ALIGN16(var800700ac);
	} else {
		i = ALIGN16(func0f09ddfc());
	}

	g_Vars.currentplayer->unk158c = malloc(i, MEMPOOL_STAGE);
	g_Vars.currentplayer->unk159c = 0;
	g_Vars.currentplayer->unk15a0 = 0;
	g_Vars.currentplayer->unk15a4 = 0;
	g_Vars.currentplayer->unk15b0 = 0;
	g_Vars.currentplayer->unk15b1 = 0;
	g_Vars.currentplayer->unk1588 = 0;
	g_Vars.currentplayer->unk1584 = -1;
	g_Vars.currentplayer->unk15ea = 2;
	g_Vars.currentplayer->unk15eb = 0;

	g_Vars.currentplayer->unk1583_06 = true;
	g_Vars.currentplayer->unk1583_00 = false;
	g_Vars.currentplayer->unk1583_04 = false;

	g_Vars.currentplayer->switchtoweaponnum = -1;
	g_Vars.currentplayer->unk15e7 = 0;

	g_Vars.currentplayer->invertgunfunc = false;

	g_Vars.currentplayer->hands[0] = hand;
	g_Vars.currentplayer->hands[1] = hand;

	g_Vars.currentplayer->hands[0].unk0d0f_02 = false;
	g_Vars.currentplayer->hands[1].unk0d0f_02 = false;

	g_Vars.currentplayer->hands[1].audiohandle = NULL;
	g_Vars.currentplayer->hands[0].audiohandle = NULL;

	g_Vars.currentplayer->unk15f2 = 0;

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->hands[1].unk0d74); i++) {
		g_Vars.currentplayer->hands[1].unk0d74[i] = 0;
		g_Vars.currentplayer->hands[0].unk0d74[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->ammoheldarr); i++) {
		g_Vars.currentplayer->ammoheldarr[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayerstats->shotcount); i++) {
		g_Vars.currentplayerstats->shotcount[i] = 0;
	}

	g_Vars.currentplayerstats->killcount = 0;
	g_Vars.currentplayerstats->ggkillcount = 0;
	g_Vars.currentplayer->deathcount = 0;
	g_Vars.currentplayer->unk15f8 = 1;
	g_Vars.currentplayer->unk15fc = 1;
	g_Vars.currentplayer->doautoselect = false;
	g_Vars.currentplayer->playertriggeron = false;
	g_Vars.currentplayer->playertriggerprev = false;
	g_Vars.currentplayer->playertrigtime240 = 0;
	g_Vars.currentplayer->curguntofire = 0;

	g_Vars.currentplayer->gunshadecol[0] = 0xff;
	g_Vars.currentplayer->gunshadecol[1] = 0xff;
	g_Vars.currentplayer->gunshadecol[2] = 0xff;
	g_Vars.currentplayer->gunshadecol[3] = 0;
	g_Vars.currentplayer->resetshadecol = 1;
	g_Vars.currentplayer->aimtype = 0;
	g_Vars.currentplayer->crosspos[0] = 0;
	g_Vars.currentplayer->crosspos[1] = 0;
	g_Vars.currentplayer->unk1668 = 0;
	g_Vars.currentplayer->unk166c = 0;
	g_Vars.currentplayer->unk1670 = 0.9f;
	g_Vars.currentplayer->unk1674 = 0;
	g_Vars.currentplayer->unk1678 = 0;
	g_Vars.currentplayer->unk167c = 0;
	g_Vars.currentplayer->unk1680 = 0;
	g_Vars.currentplayer->unk1684 = 0.9f;
	g_Vars.currentplayer->unk1688 = 0;
	g_Vars.currentplayer->unk168c = -M_PI;
	g_Vars.currentplayer->unk1690 = 0;
	g_Vars.currentplayer->unk16d4 = 0;
	g_Vars.currentplayer->magnetattracttime = -1;
	g_Vars.currentplayer->unk16dc = 0;
	g_Vars.currentplayer->unk16e0 = 0;
	g_Vars.currentplayer->unk16e4 = 0;
	g_Vars.currentplayer->unk16e8 = 0;
	g_Vars.currentplayer->unk16ec = 0;
	g_Vars.currentplayer->unk16f0 = 0;

	func0f09d140(HAND_RIGHT);
	func0f09d140(HAND_RIGHT);
	func0f09d140(HAND_RIGHT);
	func0f09d140(HAND_LEFT);
	func0f09d140(HAND_LEFT);
	func0f09d140(HAND_LEFT);

	g_Vars.currentplayer->unk16d8 = 0;
	g_Vars.currentplayer->gunsightoff = GUNSIGHTREASON_AIMING;
	g_Vars.currentplayer->gunzoomfovs[0] = 15;
	g_Vars.currentplayer->gunzoomfovs[1] = 60;
	g_Vars.currentplayer->gunzoomfovs[2] = 30;

	if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
		g_Weapons[WEAPON_EYESPY]->name = L_GUN(61); // "DrugSpy"
		g_Weapons[WEAPON_EYESPY]->shortname = L_GUN(61); // "DrugSpy"
		g_Weapons[WEAPON_EYESPY]->flags &= ~(WEAPONFLAG_00200000 | WEAPONFLAG_00400000);
	} else if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_CHICAGO
			|| (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR)) {
		g_Weapons[WEAPON_EYESPY]->name = L_GUN(62); // "BombSpy"
		g_Weapons[WEAPON_EYESPY]->shortname = L_GUN(62); // "BombSpy"
		g_Weapons[WEAPON_EYESPY]->flags &= ~(WEAPONFLAG_00200000 | WEAPONFLAG_00400000);
	} else {
		g_Weapons[WEAPON_EYESPY]->name = L_GUN(60); // "CamSpy"
		g_Weapons[WEAPON_EYESPY]->shortname = L_GUN(60); // "CamSpy"
		g_Weapons[WEAPON_EYESPY]->flags |= (WEAPONFLAG_00200000 | WEAPONFLAG_00400000);
	}

	func0f09ceac();
}
