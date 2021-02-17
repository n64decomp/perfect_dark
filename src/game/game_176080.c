#include <ultra64.h>
#include "constants.h"
#include "boot/sched.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "game/game_0b69d0.h"
#include "game/game_176080.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/memory.h"
#include "types.h"

void *var800844f0 = NULL;
void *var800844f4 = NULL;
u32 var800844f8 = 0;
u32 var800844fc = 0;

struct stagemusic g_StageTracks[] = {
	// stage,              main theme,           background sfx,          X theme
	{ STAGE_CITRAINING,    MUSIC_CI,             -1,                      MUSIC_DEFENSE_X       },
	{ STAGE_DEFECTION,     MUSIC_DEFECTION,      MUSIC_DDTOWER_SFX,       MUSIC_DEFECTION_X     },
	{ STAGE_INVESTIGATION, MUSIC_INVESTIGATION,  MUSIC_INVESTIGATION_SFX, MUSIC_INVESTIGATION_X },
	{ STAGE_EXTRACTION,    MUSIC_EXTRACTION,     MUSIC_DDTOWER_SFX,       MUSIC_EXTRACTION_X    },
	{ STAGE_VILLA,         MUSIC_VILLA,          MUSIC_OCEAN,             MUSIC_VILLA_X         },
	{ STAGE_CHICAGO,       MUSIC_CHICAGO,        MUSIC_TRAFFIC,           MUSIC_CHICAGO_X       },
	{ STAGE_G5BUILDING,    MUSIC_G5,             MUSIC_TRAFFIC,           MUSIC_G5_X            },
	{ STAGE_INFILTRATION,  MUSIC_INFILTRATION,   MUSIC_INFILTRATION_SFX,  MUSIC_INFILTRATION_X  },
	{ STAGE_RESCUE,        MUSIC_RESCUE,         MUSIC_A51_LOUDSPEAKER1,  MUSIC_RESCUE_X        },
	{ STAGE_ESCAPE,        MUSIC_ESCAPE,         MUSIC_A51_LOUDSPEAKER2,  MUSIC_ESCAPE_X        },
	{ STAGE_AIRBASE,       MUSIC_AIRBASE,        MUSIC_WIND,              MUSIC_AIRBASE_X       },
	{ STAGE_AIRFORCEONE,   MUSIC_AIRFORCEONE,    MUSIC_AIRFORCEONE_SFX,   MUSIC_AIRFORCEONE_X   },
	{ STAGE_CRASHSITE,     MUSIC_CRASHSITE,      MUSIC_CRASHSITE_WIND,    MUSIC_CRASHSITE_X     },
	{ STAGE_PELAGIC,       MUSIC_PELAGIC,        MUSIC_OCEAN,             MUSIC_PELAGIC_X       },
	{ STAGE_DEEPSEA,       MUSIC_DEEPSEA,        MUSIC_DEEPSEA_SFX,       MUSIC_DEEPSEA_X       },
	{ STAGE_DEFENSE,       MUSIC_DEFENSE,        -1,                      MUSIC_DEFENSE_X       },
	{ STAGE_ATTACKSHIP,    MUSIC_ATTACKSHIP,     MUSIC_ATTACKSHIP_SFX,    MUSIC_ATTACKSHIP_X    },
	{ STAGE_SKEDARRUINS,   MUSIC_SKEDARRUINS,    MUSIC_SKEDAR_WIND,       MUSIC_SKEDARRUINS_X   },
	{ STAGE_MBR,           MUSIC_DARK_COMBAT,    MUSIC_DDTOWER_SFX,       MUSIC_DARK_COMBAT     },
	{ STAGE_MAIANSOS,      MUSIC_MAIAN_TEARS,    MUSIC_A51_LOUDSPEAKER2,  MUSIC_MAIAN_TEARS     },
	{ STAGE_RETAKING,      MUSIC_CI_OPERATIVE,   -1,                      MUSIC_CI_OPERATIVE    },
	{ STAGE_WAR,           MUSIC_ALIEN_CONFLICT, MUSIC_SKEDAR_WIND,       MUSIC_ALIEN_CONFLICT  },
	{ STAGE_DUEL,          MUSIC_CREDITS,        -1,                      MUSIC_CREDITS         },
	{ STAGE_CREDITS,       MUSIC_ALIEN_CONFLICT, -1,                      MUSIC_ALIEN_CONFLICT  },
	{ 0,                   0,                    0,                       0  },
};

void *func0f176080(void)
{
	return var800844f0;
}

void func0f17608c(s32 stagenum)
{
	var800844f0 = 0;
	var800844f4 = 0;

	if (stagenum != STAGE_TITLE) {
		func0f1760c4();
	}
}

void func0f1760c4(void)
{
	if (IS4MB()) {
		var800ab7c0 = 320;

		if (g_Vars.normmplayerisrunning && PLAYERCOUNT() >= 2) {
			var800ab7c4 = 110;
		} else {
			var800ab7c4 = 220;
		}
	} else {
		var800ab7c0 = 640;

		if (g_Vars.normmplayerisrunning && PLAYERCOUNT() >= 2) {
			var800ab7c4 = 220;
		} else {
			var800ab7c4 = 220;
		}
	}

	var800844f0 = malloc(var800ab7c0 * var800ab7c4 * 2 + 0x40, MEMPOOL_STAGE);
	var800844f0 = (void *)((u32)var800844f0 + 0x3f & ~0x3f);
	var800844f4 = var800844f0;
}

void func0f176298(void)
{
	var800844f4 = var800844f0;
}

Gfx *func0f1762ac(Gfx *gdl)
{
	u32 subamount;
	u32 addr;

	if (g_Vars.normmplayerisrunning
			&& (g_Vars.currentplayernum >= 2 || (PLAYERCOUNT() == 2 && g_Vars.currentplayernum == 1))) {
		subamount = viGetFbWidth() * viGetFbHeight();

		if (IS4MB() || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
			subamount = 0;
		}
	} else {
		subamount = 0;
	}

	addr = (u32)var800844f4 - subamount;
	addr &= ~0x3f;

	gDPPipeSync(gdl++);
	gDPSetDepthImage(gdl++, addr);

	return gdl;
}

Gfx *func0f1763f4(Gfx *gdl)
{
	s32 left;
	s32 right;

	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetX(), OS_PHYSICAL_TO_K0(var800844f4));
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetFillColor(gdl++, 0xfffcfffc);
	gDPSetScissorFrac(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetFbWidth() * 4.0f, viGetFbHeight() * 4.0f);

	if (PLAYERCOUNT() <= 2) {
		left = 0;
		right = viGetFbWidth() - 1;
	} else if (g_Vars.currentplayernum == 0 || g_Vars.currentplayernum == 2) {
		left = 0;
		right = viGetFbWidth() / 2 - 1;
	} else {
		left = viGetFbWidth() / 2;
		right = viGetFbWidth() - 1;
	}

	gDPFillRectangle(gdl++, left, 0, right, viGetFbHeight() - 1);
	gDPPipeSync(gdl++);

	return gdl;
}

void *func0f176668(s32 arg0)
{
	void *addr;

	if (arg0 == 0) {
		addr = &var800ab7c8;
	}

	if (arg0 == 1) {
		addr = &var800abac8;
	}

	if (arg0 == 2) {
		addr = &var800abdc8;
	}

	addr = (void *)(((u32)addr + 0x3f) & ~0x3f);

	return addr;
}

GLOBAL_ASM(
glabel func0f1766b4
/*  f1766b4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f1766b8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1766bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1766c0:	00808025 */ 	or	$s0,$a0,$zero
/*  f1766c4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f1766c8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1766cc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1766d0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1766d4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1766d8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1766dc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1766e0:	0c000913 */ 	jal	bbufGetIndex0Buffer
/*  f1766e4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1766e8:	3c0e8008 */ 	lui	$t6,%hi(var800844f0)
/*  f1766ec:	8dce44f0 */ 	lw	$t6,%lo(var800844f0)($t6)
/*  f1766f0:	00409025 */ 	or	$s2,$v0,$zero
/*  f1766f4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1766f8:	0c002ac7 */ 	jal	viGetUnk28
/*  f1766fc:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f176700:	3c138009 */ 	lui	$s3,%hi(g_BootBufferIndex0)
/*  f176704:	2673fa6c */ 	addiu	$s3,$s3,%lo(g_BootBufferIndex0)
/*  f176708:	0fc5d99a */ 	jal	func0f176668
/*  f17670c:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f176710:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f176714:	3c018009 */ 	lui	$at,%hi(g_BootBufferDirtyIndexes)
/*  f176718:	02001825 */ 	or	$v1,$s0,$zero
/*  f17671c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f176720:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176724:	00380821 */ 	addu	$at,$at,$t8
/*  f176728:	3c16e700 */ 	lui	$s6,0xe700
/*  f17672c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f176730:	a02ffa68 */ 	sb	$t7,%lo(g_BootBufferDirtyIndexes)($at)
/*  f176734:	02008825 */ 	or	$s1,$s0,$zero
/*  f176738:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f17673c:	ac760000 */ 	sw	$s6,0x0($v1)
/*  f176740:	0c002ef1 */ 	jal	viGetBufX
/*  f176744:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176748:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f17674c:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f176750:	3c01ff10 */ 	lui	$at,0xff10
/*  f176754:	01014825 */ 	or	$t1,$t0,$at
/*  f176758:	ae290000 */ 	sw	$t1,0x0($s1)
/*  f17675c:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f176760:	3c018000 */ 	lui	$at,0x8000
/*  f176764:	02001825 */ 	or	$v1,$s0,$zero
/*  f176768:	01415821 */ 	addu	$t3,$t2,$at
/*  f17676c:	ae2b0004 */ 	sw	$t3,0x4($s1)
/*  f176770:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176774:	3c0ced00 */ 	lui	$t4,0xed00
/*  f176778:	3c0d0050 */ 	lui	$t5,0x50
/*  f17677c:	35ad03c0 */ 	ori	$t5,$t5,0x3c0
/*  f176780:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f176784:	02002025 */ 	or	$a0,$s0,$zero
/*  f176788:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f17678c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176790:	3c0eba00 */ 	lui	$t6,0xba00
/*  f176794:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f176798:	3c0f0020 */ 	lui	$t7,0x20
/*  f17679c:	02002825 */ 	or	$a1,$s0,$zero
/*  f1767a0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1767a4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1767a8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767ac:	3c190500 */ 	lui	$t9,0x500
/*  f1767b0:	3c18f510 */ 	lui	$t8,0xf510
/*  f1767b4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1767b8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1767bc:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1767c0:	3c08f510 */ 	lui	$t0,0xf510
/*  f1767c4:	35080080 */ 	ori	$t0,$t0,0x80
/*  f1767c8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767cc:	3c090400 */ 	lui	$t1,0x400
/*  f1767d0:	acc90004 */ 	sw	$t1,0x4($a2)
/*  f1767d4:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f1767d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1767dc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767e0:	3c0af511 */ 	lui	$t2,0xf511
/*  f1767e4:	354a4000 */ 	ori	$t2,$t2,0x4000
/*  f1767e8:	02001825 */ 	or	$v1,$s0,$zero
/*  f1767ec:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f1767f0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1767f4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767f8:	3c0c0100 */ 	lui	$t4,0x100
/*  f1767fc:	3c0bf589 */ 	lui	$t3,0xf589
/*  f176800:	356b4080 */ 	ori	$t3,$t3,0x4080
/*  f176804:	358c000f */ 	ori	$t4,$t4,0xf
/*  f176808:	02002025 */ 	or	$a0,$s0,$zero
/*  f17680c:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f176810:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f176814:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176818:	3c0dbb00 */ 	lui	$t5,0xbb00
/*  f17681c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f176820:	35ad0001 */ 	ori	$t5,$t5,0x1
/*  f176824:	02002825 */ 	or	$a1,$s0,$zero
/*  f176828:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f17682c:	ac870004 */ 	sw	$a3,0x4($a0)
/*  f176830:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176834:	3c0efb00 */ 	lui	$t6,0xfb00
/*  f176838:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f17683c:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f176840:	02003025 */ 	or	$a2,$s0,$zero
/*  f176844:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176848:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f17684c:	02001025 */ 	or	$v0,$s0,$zero
/*  f176850:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f176854:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f176858:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17685c:	3c18b900 */ 	lui	$t8,0xb900
/*  f176860:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f176864:	02001825 */ 	or	$v1,$s0,$zero
/*  f176868:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f17686c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f176870:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176874:	3c08fffc */ 	lui	$t0,0xfffc
/*  f176878:	3c19fcff */ 	lui	$t9,0xfcff
/*  f17687c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f176880:	3508f279 */ 	ori	$t0,$t0,0xf279
/*  f176884:	02002025 */ 	or	$a0,$s0,$zero
/*  f176888:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f17688c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f176890:	3c09ba00 */ 	lui	$t1,0xba00
/*  f176894:	35290c02 */ 	ori	$t1,$t1,0xc02
/*  f176898:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17689c:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f1768a0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1768a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1768a8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1768ac:	3c0aba00 */ 	lui	$t2,0xba00
/*  f1768b0:	354a1301 */ 	ori	$t2,$t2,0x1301
/*  f1768b4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1768b8:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f1768bc:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1768c0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1768c4:	3c0bba00 */ 	lui	$t3,0xba00
/*  f1768c8:	356b0602 */ 	ori	$t3,$t3,0x602
/*  f1768cc:	240c00c0 */ 	addiu	$t4,$zero,0xc0
/*  f1768d0:	02001025 */ 	or	$v0,$s0,$zero
/*  f1768d4:	accc0004 */ 	sw	$t4,0x4($a2)
/*  f1768d8:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f1768dc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1768e0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f1768e4:	35ad0402 */ 	ori	$t5,$t5,0x402
/*  f1768e8:	240e0030 */ 	addiu	$t6,$zero,0x30
/*  f1768ec:	02001825 */ 	or	$v1,$s0,$zero
/*  f1768f0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1768f4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1768f8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1768fc:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f176900:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176904:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f176908:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f17690c:	02002025 */ 	or	$a0,$s0,$zero
/*  f176910:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176914:	3c18ba00 */ 	lui	$t8,0xba00
/*  f176918:	37181102 */ 	ori	$t8,$t8,0x1102
/*  f17691c:	02002825 */ 	or	$a1,$s0,$zero
/*  f176920:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f176924:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f176928:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17692c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f176930:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f176934:	02003025 */ 	or	$a2,$s0,$zero
/*  f176938:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f17693c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f176940:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176944:	3c08b900 */ 	lui	$t0,0xb900
/*  f176948:	35080002 */ 	ori	$t0,$t0,0x2
/*  f17694c:	02001025 */ 	or	$v0,$s0,$zero
/*  f176950:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f176954:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f176958:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17695c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f176960:	3c09b600 */ 	lui	$t1,0xb600
/*  f176964:	02001825 */ 	or	$v1,$s0,$zero
/*  f176968:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f17696c:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f176970:	3c0be800 */ 	lui	$t3,0xe800
/*  f176974:	3c1efd10 */ 	lui	$s8,0xfd10
/*  f176978:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f17697c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f176980:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176984:	37de013f */ 	ori	$s8,$s8,0x13f
/*  f176988:	02408825 */ 	or	$s1,$s2,$zero
/*  f17698c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f176990:	3c17e600 */ 	lui	$s7,0xe600
.L0f176994:
/*  f176994:	962c0000 */ 	lhu	$t4,0x0($s1)
/*  f176998:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f17699c:	1180004a */ 	beqz	$t4,.L0f176ac8
/*  f1769a0:	00146840 */ 	sll	$t5,$s4,0x1
/*  f1769a4:	0c002f02 */ 	jal	viGetX
/*  f1769a8:	01ae9021 */ 	addu	$s2,$t5,$t6
/*  f1769ac:	962f000c */ 	lhu	$t7,0xc($s1)
/*  f1769b0:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f1769b4:	02001825 */ 	or	$v1,$s0,$zero
/*  f1769b8:	004f0019 */ 	multu	$v0,$t7
/*  f1769bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1769c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1769c4:	ac760000 */ 	sw	$s6,0x0($v1)
/*  f1769c8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1769cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1769d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1769d4:	ac9e0000 */ 	sw	$s8,0x0($a0)
/*  f1769d8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1769dc:	02009825 */ 	or	$s3,$s0,$zero
/*  f1769e0:	0000c012 */ 	mflo	$t8
/*  f1769e4:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f1769e8:	03283021 */ 	addu	$a2,$t9,$t0
/*  f1769ec:	ac860004 */ 	sw	$a2,0x4($a0)
/*  f1769f0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1769f4:	acb70000 */ 	sw	$s7,0x0($a1)
/*  f1769f8:	3c09f300 */ 	lui	$t1,0xf300
/*  f1769fc:	ae690000 */ 	sw	$t1,0x0($s3)
/*  f176a00:	0c002f02 */ 	jal	viGetX
/*  f176a04:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a08:	244affff */ 	addiu	$t2,$v0,-1
/*  f176a0c:	294107ff */ 	slti	$at,$t2,0x7ff
/*  f176a10:	10200005 */ 	beqz	$at,.L0f176a28
/*  f176a14:	240507ff */ 	addiu	$a1,$zero,0x7ff
/*  f176a18:	0c002f02 */ 	jal	viGetX
/*  f176a1c:	00000000 */ 	nop
/*  f176a20:	10000001 */ 	b	.L0f176a28
/*  f176a24:	2445ffff */ 	addiu	$a1,$v0,-1
.L0f176a28:
/*  f176a28:	30ab0fff */ 	andi	$t3,$a1,0xfff
/*  f176a2c:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f176a30:	3c010500 */ 	lui	$at,0x500
/*  f176a34:	01816825 */ 	or	$t5,$t4,$at
/*  f176a38:	02001025 */ 	or	$v0,$s0,$zero
/*  f176a3c:	268e0003 */ 	addiu	$t6,$s4,0x3
/*  f176a40:	ae6d0004 */ 	sw	$t5,0x4($s3)
/*  f176a44:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a48:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f176a4c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f176a50:	02001825 */ 	or	$v1,$s0,$zero
/*  f176a54:	00144880 */ 	sll	$t1,$s4,0x2
/*  f176a58:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f176a5c:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f176a60:	312a0fff */ 	andi	$t2,$t1,0xfff
/*  f176a64:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f176a68:	3c01e400 */ 	lui	$at,0xe400
/*  f176a6c:	03214025 */ 	or	$t0,$t9,$at
/*  f176a70:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f176a74:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a78:	02002025 */ 	or	$a0,$s0,$zero
/*  f176a7c:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f176a80:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f176a84:	3c0cb400 */ 	lui	$t4,0xb400
/*  f176a88:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f176a8c:	962d000e */ 	lhu	$t5,0xe($s1)
/*  f176a90:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a94:	02003025 */ 	or	$a2,$s0,$zero
/*  f176a98:	000d7140 */ 	sll	$t6,$t5,0x5
/*  f176a9c:	25d80010 */ 	addiu	$t8,$t6,0x10
/*  f176aa0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f176aa4:	37280010 */ 	ori	$t0,$t9,0x10
/*  f176aa8:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f176aac:	3c0a1000 */ 	lui	$t2,0x1000
/*  f176ab0:	3c09b300 */ 	lui	$t1,0xb300
/*  f176ab4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f176ab8:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f176abc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176ac0:	ae32000c */ 	sw	$s2,0xc($s1)
/*  f176ac4:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f176ac8:
/*  f176ac8:	26b50014 */ 	addiu	$s5,$s5,0x14
/*  f176acc:	24010960 */ 	addiu	$at,$zero,0x960
/*  f176ad0:	16a1ffb0 */ 	bne	$s5,$at,.L0f176994
/*  f176ad4:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f176ad8:	02001025 */ 	or	$v0,$s0,$zero
/*  f176adc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176ae0:	02001825 */ 	or	$v1,$s0,$zero
/*  f176ae4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176ae8:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f176aec:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f176af0:	02002025 */ 	or	$a0,$s0,$zero
/*  f176af4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176af8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f176afc:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f176b00:	3c0be800 */ 	lui	$t3,0xe800
/*  f176b04:	02008825 */ 	or	$s1,$s0,$zero
/*  f176b08:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f176b0c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f176b10:	0c002ef1 */ 	jal	viGetBufX
/*  f176b14:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b18:	244cffff */ 	addiu	$t4,$v0,-1
/*  f176b1c:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f176b20:	3c01ff10 */ 	lui	$at,0xff10
/*  f176b24:	01a17025 */ 	or	$t6,$t5,$at
/*  f176b28:	0c002ac7 */ 	jal	viGetUnk28
/*  f176b2c:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f176b30:	3c018000 */ 	lui	$at,0x8000
/*  f176b34:	00417821 */ 	addu	$t7,$v0,$at
/*  f176b38:	ae2f0004 */ 	sw	$t7,0x4($s1)
/*  f176b3c:	02009025 */ 	or	$s2,$s0,$zero
/*  f176b40:	3c18ed00 */ 	lui	$t8,0xed00
/*  f176b44:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f176b48:	0c002f02 */ 	jal	viGetX
/*  f176b4c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b50:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f176b54:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f176b58:	0c002f06 */ 	jal	viGetY
/*  f176b5c:	03208825 */ 	or	$s1,$t9,$zero
/*  f176b60:	44822000 */ 	mtc1	$v0,$f4
/*  f176b64:	44918000 */ 	mtc1	$s1,$f16
/*  f176b68:	3c014080 */ 	lui	$at,0x4080
/*  f176b6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f176b70:	44810000 */ 	mtc1	$at,$f0
/*  f176b74:	02001825 */ 	or	$v1,$s0,$zero
/*  f176b78:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b7c:	3c18b700 */ 	lui	$t8,0xb700
/*  f176b80:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f176b84:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f176b88:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f176b8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f176b90:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b94:	3c08ba00 */ 	lui	$t0,0xba00
/*  f176b98:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f176b9c:	35080c02 */ 	ori	$t0,$t0,0xc02
/*  f176ba0:	02002825 */ 	or	$a1,$s0,$zero
/*  f176ba4:	3c0bba00 */ 	lui	$t3,0xba00
/*  f176ba8:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f176bac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176bb0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f176bb4:	02003025 */ 	or	$a2,$s0,$zero
/*  f176bb8:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f176bbc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f176bc0:	44095000 */ 	mfc1	$t1,$f10
/*  f176bc4:	440c3000 */ 	mfc1	$t4,$f6
/*  f176bc8:	312a0fff */ 	andi	$t2,$t1,0xfff
/*  f176bcc:	24092000 */ 	addiu	$t1,$zero,0x2000
/*  f176bd0:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f176bd4:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f176bd8:	014e7825 */ 	or	$t7,$t2,$t6
/*  f176bdc:	ae4f0004 */ 	sw	$t7,0x4($s2)
/*  f176be0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f176be4:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f176be8:	ac890004 */ 	sw	$t1,0x4($a0)
/*  f176bec:	ac880000 */ 	sw	$t0,0x0($a0)
/*  f176bf0:	3c0c0008 */ 	lui	$t4,0x8
/*  f176bf4:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f176bf8:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f176bfc:	3c0dba00 */ 	lui	$t5,0xba00
/*  f176c00:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f176c04:	240a0040 */ 	addiu	$t2,$zero,0x40
/*  f176c08:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f176c0c:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f176c10:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f176c14:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f176c18:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f176c1c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f176c20:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f176c24:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f176c28:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f176c2c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f176c30:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f176c34:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f176c38:	03e00008 */ 	jr	$ra
/*  f176c3c:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

// Mismatch: Need to know more about the stack variables and
// bootbufferthingdeep->unk0c.
//Gfx *func0f1766b4(Gfx *gdl)
//{
//	struct bootbufferthing *thing = bbufGetIndex0Buffer();
//	u32 sp4c = (u32) var800844f0;
//	s32 s4 = 0;
//	u32 sp44;
//	s32 i;
//
//	viGetUnk28();
//	sp44 = (u32)func0f176668(g_BootBufferIndex0);
//	g_BootBufferDirtyIndexes[g_BootBufferIndex0] = 1;
//
//	gDPPipeSync(gdl++);
//	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetBufX(), OS_PHYSICAL_TO_K0(sp44));
//	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
//	gDPSetCycleType(gdl++, G_CYC_COPY);
//	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0080, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//	gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 160, 0x0080, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 15);
//	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
//	gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, 0xff);
//	gDPSetPrimColor(gdl++, 0, 0, 0xff, 0xff, 0xff, 0xff);
//	gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
//	gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
//	gDPSetTextureFilter(gdl++, G_TF_POINT);
//	gDPSetTexturePersp(gdl++, G_TP_NONE);
//	gDPSetColorDither(gdl++, G_CD_DISABLE);
//	gDPSetAlphaDither(gdl++, G_AD_DISABLE);
//	gDPSetTextureLOD(gdl++, G_TL_TILE);
//	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
//	gDPSetTextureLUT(gdl++, G_TT_NONE);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gSPClearGeometryMode(gdl++, G_ZBUFFER);
//	gDPTileSync(gdl++);
//
//	for (i = 0; i < 120; i++) {
//		if (thing->unk00[i].unk00) {
//			u32 tmp = viGetX() * thing->unk00[i].unk0c.u16_1 * 2 + sp4c;
//
//			gDPPipeSync(gdl++);
//			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, tmp);
//			gDPLoadSync(gdl++);
//			gDPLoadBlock(gdl++, 5, 0, 0, viGetX() - 1, 0);
//			gDPPipeSync(gdl++);
//
//			gSPTextureRectangle(gdl++,
//					s4 << 2, 0,
//					(s4 + 3) << 2, 0,
//					G_TX_RENDERTILE, (thing->unk00[i].unk0c.u16_2 * 32) + 16, 0x0010, 0x1000, 0);
//
//			// Note: s4 should have * 2 in the following expression,
//			// but this produces a shifted codegen.
//			thing->unk00[i].unk0c.u16p = (u16 *)(s4 + sp44);
//			s4++;
//		}
//	}
//
//	gDPPipeSync(gdl++);
//	gDPLoadSync(gdl++);
//	gDPTileSync(gdl++);
//	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetBufX(), OS_PHYSICAL_TO_K0(viGetUnk28()));
//	gDPSetScissorFrac(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetX() * 4.0f, viGetY() * 4.0f);
//	gSPSetGeometryMode(gdl++, G_ZBUFFER);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//	gDPSetTexturePersp(gdl++, G_TP_PERSP);
//	gDPSetColorDither(gdl++, G_CD_BAYER);
//
//	return gdl;
//}

s32 stageGetPrimaryTrack(s32 stagenum)
{
	s32 i;

	if (g_Vars.normmplayerisrunning) {
		return func0f18c4c0();
	}

	i = 0;

	while (g_StageTracks[i].stagenum) {
		if (g_StageTracks[i].stagenum == stagenum) {
			if (g_StageTracks[i].primarytrack == -1) {
				return func0f18c4c0();
			}

			return g_StageTracks[i].primarytrack;
		}

		i++;
	}

	return func0f18c4c0();
}

s32 stageGetAmbientTrack(s32 stagenum)
{
	s32 i = 0;

	while (g_StageTracks[i].stagenum) {
		if (g_StageTracks[i].stagenum == stagenum) {
			return g_StageTracks[i].ambienttrack;
		}

		i++;
	}

	return -1;
}

s32 stageGetXTrack(s32 stagenum)
{
	s32 i = 0;

	while (g_StageTracks[i].stagenum) {
		if (g_StageTracks[i].stagenum == stagenum) {
			return g_StageTracks[i].xtrack;
		}

		i++;
	}

	return -1;
}
