#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/dma.h"
#include "data.h"
#include "types.h"

/**
 * NTSC appears to use a boolean for Japanese support.
 * PAL ignores this mostly and introduces g_LanguageId.
 */
#if VERSION >= VERSION_PAL_BETA
bool g_Jpn = VERSION == VERSION_JPN_FINAL ? true : false;
s32 var80084664pf = 0;
s32 var80084668pf = 0;
s32 var8008466cpf = 0;
u32 *g_LangBanks[69];
void *var800aabb4;
struct var800aabb8 *var800aabb8;
s32 g_LanguageId = LANGUAGE_NTSC_EN;
#else
u32 *g_LangBanks[69];
void *var800aabb4;
struct var800aabb8 *var800aabb8;
bool g_Jpn = false;
#endif

u16 g_LangFiles[] = {
	/* 0*/ 0,
	/* 1*/ FILE_LAMEE,
	/* 2*/ FILE_LARCHE,
	/* 3*/ FILE_LARKE,
	/* 4*/ FILE_LASHE,
	/* 5*/ FILE_LAZTE,
	/* 6*/ FILE_LCATE,
	/* 7*/ FILE_LCAVEE,
	/* 8*/ FILE_LARECE,
	/* 9*/ FILE_LCRADE,
	/*10*/ FILE_LCRYPE,
	/*11*/ FILE_LDAME,
	/*12*/ FILE_LDEPOE,
	/*13*/ FILE_LDESTE,
	/*14*/ FILE_LDISHE,
	/*15*/ FILE_LEARE,
	/*16*/ FILE_LELDE,
	/*17*/ FILE_LIMPE,
	/*18*/ FILE_LJUNE,
	/*19*/ FILE_LLEEE,
	/*20*/ FILE_LLENE,
	/*21*/ FILE_LLIPE,
	/*22*/ FILE_LLUEE,
	/*23*/ FILE_LOATE,
	/*24*/ FILE_LPAME,
	/*25*/ FILE_LPETEE,
	/*26*/ FILE_LREFE,
	/*27*/ FILE_LRITE,
	/*28*/ FILE_LRUNE,
	/*29*/ FILE_LSEVBE,
	/*30*/ FILE_LSEVE,
	/*31*/ FILE_LSEVXE,
	/*32*/ FILE_LSEVXBE,
	/*33*/ FILE_LSHOE,
	/*34*/ FILE_LSILOE,
	/*35*/ FILE_LSTATE,
	/*36*/ FILE_LTRAE,
	/*37*/ FILE_LWAXE,
	/*38*/ FILE_LGUNE,
	/*39*/ FILE_LTITLEE,
	/*40*/ FILE_LMPMENUE,
	/*41*/ FILE_LPROPOBJE,
	/*42*/ FILE_LMPWEAPONSE,
	/*43*/ FILE_LOPTIONSE,
	/*44*/ FILE_LMISCE,
	/*45*/ FILE_LUFFE,
	/*46*/ FILE_LOLDE,
	/*47*/ FILE_LATEE,
	/*48*/ FILE_LLAME,
	/*49*/ FILE_LMP1E,
	/*50*/ FILE_LMP2E,
	/*51*/ FILE_LMP3E,
	/*52*/ FILE_LMP4E,
	/*53*/ FILE_LMP5E,
	/*54*/ FILE_LMP6E,
	/*55*/ FILE_LMP7E,
	/*56*/ FILE_LMP8E,
	/*57*/ FILE_LMP9E,
	/*58*/ FILE_LMP10E,
	/*59*/ FILE_LMP11E,
	/*60*/ FILE_LMP12E,
	/*61*/ FILE_LMP13E,
	/*62*/ FILE_LMP14E,
	/*63*/ FILE_LMP15E,
	/*64*/ FILE_LMP16E,
	/*65*/ FILE_LMP17E,
	/*66*/ FILE_LMP18E,
	/*67*/ FILE_LMP19E,
	/*68*/ FILE_LMP20E,
};

u32 langGetLangBankIndexFromStagenum(s32 stagenum)
{
	u32 bank;

	switch (stagenum) {
	case STAGE_PELAGIC:       bank = LANGBANK_DAM; break;
	case STAGE_EXTRACTION:    bank = LANGBANK_ARK; break;
	case STAGE_TEST_RUN:      bank = LANGBANK_RUN; break;
	case STAGE_24:            bank = LANGBANK_SEVX; break;
	case STAGE_MAIANSOS:      bank = LANGBANK_SEV; break;
	case STAGE_TEST_DEST:     bank = LANGBANK_DEST; break;
	case STAGE_2B:            bank = LANGBANK_SEVXB; break;
	case STAGE_RETAKING:      bank = LANGBANK_SEVB; break;
	case STAGE_WAR:           bank = LANGBANK_STAT; break;
	case STAGE_CHICAGO:       bank = LANGBANK_PETE; break;
	case STAGE_G5BUILDING:    bank = LANGBANK_DEPO; break;
	case STAGE_ESCAPE:        bank = LANGBANK_TRA; break;
	case STAGE_MP_TEMPLE:     bank = LANGBANK_JUN; break;
	case STAGE_MP_PIPES:      bank = LANGBANK_CRAD; break;
	case STAGE_MP_G5BUILDING: bank = LANGBANK_CRYP; break;
	case STAGE_CITRAINING:    bank = LANGBANK_DISH; break;
	case STAGE_MP_COMPLEX:    bank = LANGBANK_REF; break;
	case STAGE_MP_SKEDAR:     bank = LANGBANK_OAT; break;
	case STAGE_TEST_LEN:      bank = LANGBANK_LEN; break;
	case STAGE_DEFECTION:     bank = LANGBANK_AME; break;
	case STAGE_VILLA:         bank = LANGBANK_ELD; break;
	case STAGE_DEFENSE:       bank = LANGBANK_IMP; break;
	case STAGE_TEST_ASH:      bank = LANGBANK_ASH; break;
	case STAGE_INVESTIGATION: bank = LANGBANK_EAR; break;
	case STAGE_ATTACKSHIP:    bank = LANGBANK_LEE; break;
	case STAGE_RESCUE:        bank = LANGBANK_LIP; break;
	case STAGE_INFILTRATION:  bank = LANGBANK_LUE; break;
	case STAGE_28:            bank = LANGBANK_DAM; break;
	case STAGE_DEEPSEA:       bank = LANGBANK_PAM; break;
	case STAGE_SKEDARRUINS:   bank = LANGBANK_SHO; break;
	case STAGE_AIRFORCEONE:   bank = LANGBANK_RIT; break;
	case STAGE_TEST_ARCH:     bank = LANGBANK_ARCH; break;
	case STAGE_MP_RAVINE:     bank = LANGBANK_AREC; break;
	case STAGE_CRASHSITE:     bank = LANGBANK_AZT; break;
	case STAGE_AIRBASE:       bank = LANGBANK_CAVE; break;
	case STAGE_TEST_UFF:      bank = LANGBANK_UFF; break;
	case STAGE_TEST_OLD:      bank = LANGBANK_OLD; break;
	case STAGE_DUEL:          bank = LANGBANK_ATE; break;
	case STAGE_TEST_LAM:      bank = LANGBANK_LAM; break;
	case STAGE_MP_BASE:       bank = LANGBANK_MP1; break;
	case STAGE_TEST_MP2:      bank = LANGBANK_MP2; break;
	case STAGE_MP_AREA52:     bank = LANGBANK_MP3; break;
	case STAGE_MP_WAREHOUSE:  bank = LANGBANK_MP4; break;
	case STAGE_MP_CARPARK:    bank = LANGBANK_MP5; break;
	case STAGE_TEST_MP6:      bank = LANGBANK_MP6; break;
	case STAGE_TEST_MP7:      bank = LANGBANK_MP7; break;
	case STAGE_TEST_MP8:      bank = LANGBANK_MP8; break;
	case STAGE_MP_RUINS:      bank = LANGBANK_MP9; break;
	case STAGE_MP_SEWERS:     bank = LANGBANK_MP10; break;
	case STAGE_MP_FELICITY:   bank = LANGBANK_MP11; break;
	case STAGE_MP_FORTRESS:   bank = LANGBANK_MP12; break;
	case STAGE_MP_VILLA:      bank = LANGBANK_MP13; break;
	case STAGE_TEST_MP14:     bank = LANGBANK_MP14; break;
	case STAGE_MP_GRID:       bank = LANGBANK_MP15; break;
	case STAGE_TEST_MP16:     bank = LANGBANK_MP16; break;
	case STAGE_TEST_MP17:     bank = LANGBANK_MP17; break;
	case STAGE_TEST_MP18:     bank = LANGBANK_MP18; break;
	case STAGE_TEST_MP19:     bank = LANGBANK_MP19; break;
	case STAGE_TEST_MP20:     bank = LANGBANK_MP20; break;
	case STAGE_MBR:           bank = LANGBANK_WAX; break;
	case STAGE_TEST_SILO:     bank = LANGBANK_SILO; break;
	default:
		while (true) {
			// empty
		}
	}

	return bank;
}

#if VERSION == VERSION_JPN_FINAL
const char var7f1b8850jf[] = "tmul";
const char var7f1b8858jf[] = "tload";
u32 var80084810jf = 0;
u32 var80084814jf = 8;

GLOBAL_ASM(
glabel func0f16e3fc
/*  f16e59c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f16e5a0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16e5a4:	308e2000 */ 	andi	$t6,$a0,0x2000
/*  f16e5a8:	00808025 */ 	move	$s0,$a0
/*  f16e5ac:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f16e5b0:	2409ffff */ 	li	$t1,-1
/*  f16e5b4:	240affff */ 	li	$t2,-1
/*  f16e5b8:	11c00002 */ 	beqz	$t6,.JF0f16e5c4
/*  f16e5bc:	00004025 */ 	move	$t0,$zero
/*  f16e5c0:	24080001 */ 	li	$t0,0x1
.JF0f16e5c4:
/*  f16e5c4:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f16e5c8:	3c058008 */ 	lui	$a1,0x8008
/*  f16e5cc:	24a54814 */ 	addiu	$a1,$a1,0x4814
/*  f16e5d0:	24848850 */ 	addiu	$a0,$a0,-30640
/*  f16e5d4:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f16e5d8:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f16e5dc:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f16e5e0:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f16e5e4:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f16e5e8:	3c058008 */ 	lui	$a1,0x8008
/*  f16e5ec:	24a54810 */ 	addiu	$a1,$a1,0x4810
/*  f16e5f0:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f16e5f4:	24848858 */ 	addiu	$a0,$a0,-30632
/*  f16e5f8:	3c028008 */ 	lui	$v0,0x8008
/*  f16e5fc:	8c424810 */ 	lw	$v0,0x4810($v0)
/*  f16e600:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f16e604:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f16e608:	10400002 */ 	beqz	$v0,.JF0f16e614
/*  f16e60c:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f16e610:	00408025 */ 	move	$s0,$v0
.JF0f16e614:
/*  f16e614:	3c07800a */ 	lui	$a3,0x800a
/*  f16e618:	8ce7d140 */ 	lw	$a3,-0x2ec0($a3)
/*  f16e61c:	00003025 */ 	move	$a2,$zero
/*  f16e620:	3c04800b */ 	lui	$a0,0x800b
/*  f16e624:	58e00026 */ 	blezl	$a3,.JF0f16e6c0
/*  f16e628:	00c7082a */ 	slt	$at,$a2,$a3
/*  f16e62c:	8c84b5a8 */ 	lw	$a0,-0x4a58($a0)
.JF0f16e630:
/*  f16e630:	15000005 */ 	bnez	$t0,.JF0f16e648
/*  f16e634:	00000000 */ 	nop
/*  f16e638:	948f0000 */ 	lhu	$t7,0x0($a0)
/*  f16e63c:	31f83fff */ 	andi	$t8,$t7,0x3fff
/*  f16e640:	5218001f */ 	beql	$s0,$t8,.JF0f16e6c0
/*  f16e644:	00c7082a */ 	slt	$at,$a2,$a3
.JF0f16e648:
/*  f16e648:	1100000a */ 	beqz	$t0,.JF0f16e674
/*  f16e64c:	94830000 */ 	lhu	$v1,0x0($a0)
/*  f16e650:	24d90001 */ 	addiu	$t9,$a2,0x1
/*  f16e654:	0327082a */ 	slt	$at,$t9,$a3
/*  f16e658:	10200006 */ 	beqz	$at,.JF0f16e674
/*  f16e65c:	306b3fff */ 	andi	$t3,$v1,0x3fff
/*  f16e660:	160b0004 */ 	bne	$s0,$t3,.JF0f16e674
/*  f16e664:	02001025 */ 	move	$v0,$s0
/*  f16e668:	948c0002 */ 	lhu	$t4,0x2($a0)
/*  f16e66c:	318d3fff */ 	andi	$t5,$t4,0x3fff
/*  f16e670:	104d0012 */ 	beq	$v0,$t5,.JF0f16e6bc
.JF0f16e674:
/*  f16e674:	00031382 */ 	srl	$v0,$v1,0xe
/*  f16e678:	14400002 */ 	bnez	$v0,.JF0f16e684
/*  f16e67c:	24c50001 */ 	addiu	$a1,$a2,0x1
/*  f16e680:	00c04825 */ 	move	$t1,$a2
.JF0f16e684:
/*  f16e684:	5440000a */ 	bnezl	$v0,.JF0f16e6b0
/*  f16e688:	00a7082a */ 	slt	$at,$a1,$a3
/*  f16e68c:	948e0002 */ 	lhu	$t6,0x2($a0)
/*  f16e690:	00a7082a */ 	slt	$at,$a1,$a3
/*  f16e694:	000e7b82 */ 	srl	$t7,$t6,0xe
/*  f16e698:	55e00005 */ 	bnezl	$t7,.JF0f16e6b0
/*  f16e69c:	00a7082a */ 	slt	$at,$a1,$a3
/*  f16e6a0:	50200003 */ 	beqzl	$at,.JF0f16e6b0
/*  f16e6a4:	00a7082a */ 	slt	$at,$a1,$a3
/*  f16e6a8:	00c05025 */ 	move	$t2,$a2
/*  f16e6ac:	00a7082a */ 	slt	$at,$a1,$a3
.JF0f16e6b0:
/*  f16e6b0:	00a03025 */ 	move	$a2,$a1
/*  f16e6b4:	1420ffde */ 	bnez	$at,.JF0f16e630
/*  f16e6b8:	24840002 */ 	addiu	$a0,$a0,0x2
.JF0f16e6bc:
/*  f16e6bc:	00c7082a */ 	slt	$at,$a2,$a3
.JF0f16e6c0:
/*  f16e6c0:	1020002b */ 	beqz	$at,.JF0f16e770
/*  f16e6c4:	3c18800b */ 	lui	$t8,0x800b
/*  f16e6c8:	8f18b5a8 */ 	lw	$t8,-0x4a58($t8)
/*  f16e6cc:	00061840 */ 	sll	$v1,$a2,0x1
/*  f16e6d0:	15000010 */ 	bnez	$t0,.JF0f16e714
/*  f16e6d4:	03032021 */ 	addu	$a0,$t8,$v1
/*  f16e6d8:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f16e6dc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f16e6e0:	3c18800b */ 	lui	$t8,0x800b
/*  f16e6e4:	332bff3f */ 	andi	$t3,$t9,0xff3f
/*  f16e6e8:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f16e6ec:	a08c0000 */ 	sb	$t4,0x0($a0)
/*  f16e6f0:	8dad4814 */ 	lw	$t5,0x4814($t5)
/*  f16e6f4:	8f18b5a4 */ 	lw	$t8,-0x4a5c($t8)
/*  f16e6f8:	00cd0019 */ 	multu	$a2,$t5
/*  f16e6fc:	00007012 */ 	mflo	$t6
/*  f16e700:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f16e704:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f16e708:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f16e70c:	1000007b */ 	b	.JF0f16e8fc
/*  f16e710:	01f81021 */ 	addu	$v0,$t7,$t8
.JF0f16e714:
/*  f16e714:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f16e718:	3c07800b */ 	lui	$a3,0x800b
/*  f16e71c:	24e7b5a8 */ 	addiu	$a3,$a3,-19032
/*  f16e720:	332bff3f */ 	andi	$t3,$t9,0xff3f
/*  f16e724:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f16e728:	a08c0000 */ 	sb	$t4,0x0($a0)
/*  f16e72c:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f16e730:	3c198008 */ 	lui	$t9,0x8008
/*  f16e734:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f16e738:	908e0002 */ 	lbu	$t6,0x2($a0)
/*  f16e73c:	3c0d800b */ 	lui	$t5,0x800b
/*  f16e740:	31cfff3f */ 	andi	$t7,$t6,0xff3f
/*  f16e744:	35f80080 */ 	ori	$t8,$t7,0x80
/*  f16e748:	a0980002 */ 	sb	$t8,0x2($a0)
/*  f16e74c:	8f394814 */ 	lw	$t9,0x4814($t9)
/*  f16e750:	8dadb5a4 */ 	lw	$t5,-0x4a5c($t5)
/*  f16e754:	00d90019 */ 	multu	$a2,$t9
/*  f16e758:	00005812 */ 	mflo	$t3
/*  f16e75c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f16e760:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f16e764:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f16e768:	10000064 */ 	b	.JF0f16e8fc
/*  f16e76c:	018d1021 */ 	addu	$v0,$t4,$t5
.JF0f16e770:
/*  f16e770:	15000039 */ 	bnez	$t0,.JF0f16e858
/*  f16e774:	00000000 */ 	nop
/*  f16e778:	05200037 */ 	bltz	$t1,.JF0f16e858
/*  f16e77c:	3c07800b */ 	lui	$a3,0x800b
/*  f16e780:	24e7b5a8 */ 	addiu	$a3,$a3,-19032
/*  f16e784:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f16e788:	00091840 */ 	sll	$v1,$t1,0x1
/*  f16e78c:	320d3fff */ 	andi	$t5,$s0,0x3fff
/*  f16e790:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f16e794:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f16e798:	2408000c */ 	li	$t0,0xc
/*  f16e79c:	3c0c800b */ 	lui	$t4,0x800b
/*  f16e7a0:	31f8ff3f */ 	andi	$t8,$t7,0xff3f
/*  f16e7a4:	37190080 */ 	ori	$t9,$t8,0x80
/*  f16e7a8:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f16e7ac:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f16e7b0:	3c198008 */ 	lui	$t9,0x8008
/*  f16e7b4:	01631021 */ 	addu	$v0,$t3,$v1
/*  f16e7b8:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f16e7bc:	31cfc000 */ 	andi	$t7,$t6,0xc000
/*  f16e7c0:	01afc025 */ 	or	$t8,$t5,$t7
/*  f16e7c4:	a4580000 */ 	sh	$t8,0x0($v0)
/*  f16e7c8:	8f394814 */ 	lw	$t9,0x4814($t9)
/*  f16e7cc:	8d8cb5a4 */ 	lw	$t4,-0x4a5c($t4)
/*  f16e7d0:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f16e7d4:	03280019 */ 	multu	$t9,$t0
/*  f16e7d8:	001978c0 */ 	sll	$t7,$t9,0x3
/*  f16e7dc:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f16e7e0:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f16e7e4:	00003012 */ 	mflo	$a2
/*  f16e7e8:	00000000 */ 	nop
/*  f16e7ec:	00000000 */ 	nop
/*  f16e7f0:	01260019 */ 	multu	$t1,$a2
/*  f16e7f4:	00005812 */ 	mflo	$t3
/*  f16e7f8:	016c2021 */ 	addu	$a0,$t3,$t4
/*  f16e7fc:	3c0b0018 */ 	lui	$t3,0x18
/*  f16e800:	02190019 */ 	multu	$s0,$t9
/*  f16e804:	256b8c40 */ 	addiu	$t3,$t3,-29632
/*  f16e808:	00007012 */ 	mflo	$t6
/*  f16e80c:	00000000 */ 	nop
/*  f16e810:	00000000 */ 	nop
/*  f16e814:	01c80019 */ 	multu	$t6,$t0
/*  f16e818:	00006812 */ 	mflo	$t5
/*  f16e81c:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f16e820:	0c0034ec */ 	jal	dmaExec
/*  f16e824:	030b2821 */ 	addu	$a1,$t8,$t3
/*  f16e828:	3c0c8008 */ 	lui	$t4,0x8008
/*  f16e82c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f16e830:	8d8c4814 */ 	lw	$t4,0x4814($t4)
/*  f16e834:	3c0d800b */ 	lui	$t5,0x800b
/*  f16e838:	8dadb5a4 */ 	lw	$t5,-0x4a5c($t5)
/*  f16e83c:	012c0019 */ 	multu	$t1,$t4
/*  f16e840:	00007012 */ 	mflo	$t6
/*  f16e844:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f16e848:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f16e84c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f16e850:	1000002a */ 	b	.JF0f16e8fc
/*  f16e854:	032d1021 */ 	addu	$v0,$t9,$t5
.JF0f16e858:
/*  f16e858:	11000021 */ 	beqz	$t0,.JF0f16e8e0
/*  f16e85c:	00000000 */ 	nop
/*  f16e860:	0540001f */ 	bltz	$t2,.JF0f16e8e0
/*  f16e864:	3c07800b */ 	lui	$a3,0x800b
/*  f16e868:	24e7b5a8 */ 	addiu	$a3,$a3,-19032
/*  f16e86c:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f16e870:	000a2040 */ 	sll	$a0,$t2,0x1
/*  f16e874:	3c02800b */ 	lui	$v0,0x800b
/*  f16e878:	01e41821 */ 	addu	$v1,$t7,$a0
/*  f16e87c:	90780000 */ 	lbu	$t8,0x0($v1)
/*  f16e880:	330bff3f */ 	andi	$t3,$t8,0xff3f
/*  f16e884:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f16e888:	a06c0000 */ 	sb	$t4,0x0($v1)
/*  f16e88c:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f16e890:	320b3fff */ 	andi	$t3,$s0,0x3fff
/*  f16e894:	01c41821 */ 	addu	$v1,$t6,$a0
/*  f16e898:	90790002 */ 	lbu	$t9,0x2($v1)
/*  f16e89c:	332dff3f */ 	andi	$t5,$t9,0xff3f
/*  f16e8a0:	35af0080 */ 	ori	$t7,$t5,0x80
/*  f16e8a4:	a06f0002 */ 	sb	$t7,0x2($v1)
/*  f16e8a8:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f16e8ac:	03041821 */ 	addu	$v1,$t8,$a0
/*  f16e8b0:	946c0000 */ 	lhu	$t4,0x0($v1)
/*  f16e8b4:	318ec000 */ 	andi	$t6,$t4,0xc000
/*  f16e8b8:	016ec825 */ 	or	$t9,$t3,$t6
/*  f16e8bc:	a4790000 */ 	sh	$t9,0x0($v1)
/*  f16e8c0:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f16e8c4:	01a41821 */ 	addu	$v1,$t5,$a0
/*  f16e8c8:	946f0002 */ 	lhu	$t7,0x2($v1)
/*  f16e8cc:	31f8c000 */ 	andi	$t8,$t7,0xc000
/*  f16e8d0:	01785825 */ 	or	$t3,$t3,$t8
/*  f16e8d4:	a46b0002 */ 	sh	$t3,0x2($v1)
/*  f16e8d8:	10000008 */ 	b	.JF0f16e8fc
/*  f16e8dc:	8c42b5a4 */ 	lw	$v0,-0x4a5c($v0)
.JF0f16e8e0:
/*  f16e8e0:	3c03800a */ 	lui	$v1,0x800a
/*  f16e8e4:	2463d370 */ 	addiu	$v1,$v1,-11408
/*  f16e8e8:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f16e8ec:	3c02800b */ 	lui	$v0,0x800b
/*  f16e8f0:	258e0001 */ 	addiu	$t6,$t4,0x1
/*  f16e8f4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f16e8f8:	8c42b5a4 */ 	lw	$v0,-0x4a5c($v0)
.JF0f16e8fc:
/*  f16e8fc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f16e900:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16e904:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f16e908:	03e00008 */ 	jr	$ra
/*  f16e90c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f16e3fc
/*  f16e3fc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f16e400:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16e404:	308e2000 */ 	andi	$t6,$a0,0x2000
/*  f16e408:	00808025 */ 	or	$s0,$a0,$zero
/*  f16e40c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f16e410:	240affff */ 	addiu	$t2,$zero,-1
/*  f16e414:	240bffff */ 	addiu	$t3,$zero,-1
/*  f16e418:	11c00002 */ 	beqz	$t6,.L0f16e424
/*  f16e41c:	00004025 */ 	or	$t0,$zero,$zero
/*  f16e420:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f16e424:
/*  f16e424:	3c0c800b */ 	lui	$t4,%hi(var800aabb8)
/*  f16e428:	8d8cabb8 */ 	lw	$t4,%lo(var800aabb8)($t4)
/*  f16e42c:	00002825 */ 	or	$a1,$zero,$zero
/*  f16e430:	00003825 */ 	or	$a3,$zero,$zero
/*  f16e434:	2409007c */ 	addiu	$t1,$zero,0x7c
/*  f16e438:	01802025 */ 	or	$a0,$t4,$zero
.L0f16e43c:
/*  f16e43c:	15000006 */ 	bnez	$t0,.L0f16e458
/*  f16e440:	00000000 */ 	nop
/*  f16e444:	94980000 */ 	lhu	$t8,0x0($a0)
/*  f16e448:	00107843 */ 	sra	$t7,$s0,0x1
/*  f16e44c:	33193fff */ 	andi	$t9,$t8,0x3fff
/*  f16e450:	51f9001f */ 	beql	$t7,$t9,.L0f16e4d0
/*  f16e454:	28a1007c */ 	slti	$at,$a1,0x7c
.L0f16e458:
/*  f16e458:	1100000b */ 	beqz	$t0,.L0f16e488
/*  f16e45c:	94830000 */ 	lhu	$v1,0x0($a0)
/*  f16e460:	24ae0001 */ 	addiu	$t6,$a1,0x1
/*  f16e464:	29c1007c */ 	slti	$at,$t6,0x7c
/*  f16e468:	10200007 */ 	beqz	$at,.L0f16e488
/*  f16e46c:	00101043 */ 	sra	$v0,$s0,0x1
/*  f16e470:	30783fff */ 	andi	$t8,$v1,0x3fff
/*  f16e474:	54580005 */ 	bnel	$v0,$t8,.L0f16e48c
/*  f16e478:	00031382 */ 	srl	$v0,$v1,0xe
/*  f16e47c:	948f0002 */ 	lhu	$t7,0x2($a0)
/*  f16e480:	31f93fff */ 	andi	$t9,$t7,0x3fff
/*  f16e484:	10590011 */ 	beq	$v0,$t9,.L0f16e4cc
.L0f16e488:
/*  f16e488:	00031382 */ 	srl	$v0,$v1,0xe
.L0f16e48c:
/*  f16e48c:	14400002 */ 	bnez	$v0,.L0f16e498
/*  f16e490:	24a60001 */ 	addiu	$a2,$a1,0x1
/*  f16e494:	00a05025 */ 	or	$t2,$a1,$zero
.L0f16e498:
/*  f16e498:	14400009 */ 	bnez	$v0,.L0f16e4c0
/*  f16e49c:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f16e4a0:	948e0002 */ 	lhu	$t6,0x2($a0)
/*  f16e4a4:	28c1007c */ 	slti	$at,$a2,0x7c
/*  f16e4a8:	000ec382 */ 	srl	$t8,$t6,0xe
/*  f16e4ac:	57000005 */ 	bnezl	$t8,.L0f16e4c4
/*  f16e4b0:	00c02825 */ 	or	$a1,$a2,$zero
/*  f16e4b4:	50200003 */ 	beqzl	$at,.L0f16e4c4
/*  f16e4b8:	00c02825 */ 	or	$a1,$a2,$zero
/*  f16e4bc:	00a05825 */ 	or	$t3,$a1,$zero
.L0f16e4c0:
/*  f16e4c0:	00c02825 */ 	or	$a1,$a2,$zero
.L0f16e4c4:
/*  f16e4c4:	14c9ffdd */ 	bne	$a2,$t1,.L0f16e43c
/*  f16e4c8:	24840002 */ 	addiu	$a0,$a0,0x2
.L0f16e4cc:
/*  f16e4cc:	28a1007c */ 	slti	$at,$a1,0x7c
.L0f16e4d0:
/*  f16e4d0:	10200021 */ 	beqz	$at,.L0f16e558
/*  f16e4d4:	00000000 */ 	nop
/*  f16e4d8:	1500000c */ 	bnez	$t0,.L0f16e50c
/*  f16e4dc:	240d0060 */ 	addiu	$t5,$zero,0x60
/*  f16e4e0:	00ad0019 */ 	multu	$a1,$t5
/*  f16e4e4:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f16e4e8:	31f9ff3f */ 	andi	$t9,$t7,0xff3f
/*  f16e4ec:	372e0080 */ 	ori	$t6,$t9,0x80
/*  f16e4f0:	a08e0000 */ 	sb	$t6,0x0($a0)
/*  f16e4f4:	3c0f800b */ 	lui	$t7,%hi(var800aabb4)
/*  f16e4f8:	8defabb4 */ 	lw	$t7,%lo(var800aabb4)($t7)
/*  f16e4fc:	0000c012 */ 	mflo	$t8
/*  f16e500:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f16e504:	1000006f */ 	b	.L0f16e6c4
/*  f16e508:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f16e50c:
/*  f16e50c:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f16e510:	3c09800b */ 	lui	$t1,%hi(var800aabb8)
/*  f16e514:	2529abb8 */ 	addiu	$t1,$t1,%lo(var800aabb8)
/*  f16e518:	332eff3f */ 	andi	$t6,$t9,0xff3f
/*  f16e51c:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f16e520:	a0980000 */ 	sb	$t8,0x0($a0)
/*  f16e524:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f16e528:	240d0060 */ 	addiu	$t5,$zero,0x60
/*  f16e52c:	00ad0019 */ 	multu	$a1,$t5
/*  f16e530:	01e72021 */ 	addu	$a0,$t7,$a3
/*  f16e534:	90990002 */ 	lbu	$t9,0x2($a0)
/*  f16e538:	332eff3f */ 	andi	$t6,$t9,0xff3f
/*  f16e53c:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f16e540:	a0980002 */ 	sb	$t8,0x2($a0)
/*  f16e544:	3c19800b */ 	lui	$t9,%hi(var800aabb4)
/*  f16e548:	8f39abb4 */ 	lw	$t9,%lo(var800aabb4)($t9)
/*  f16e54c:	00007812 */ 	mflo	$t7
/*  f16e550:	1000005b */ 	b	.L0f16e6c0
/*  f16e554:	01f91021 */ 	addu	$v0,$t7,$t9
.L0f16e558:
/*  f16e558:	15000025 */ 	bnez	$t0,.L0f16e5f0
/*  f16e55c:	00000000 */ 	nop
/*  f16e560:	05400023 */ 	bltz	$t2,.L0f16e5f0
/*  f16e564:	240d0060 */ 	addiu	$t5,$zero,0x60
/*  f16e568:	014d0019 */ 	multu	$t2,$t5
/*  f16e56c:	000a3840 */ 	sll	$a3,$t2,0x1
/*  f16e570:	01871821 */ 	addu	$v1,$t4,$a3
/*  f16e574:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f16e578:	3c09800b */ 	lui	$t1,%hi(var800aabb8)
/*  f16e57c:	2529abb8 */ 	addiu	$t1,$t1,%lo(var800aabb8)
/*  f16e580:	31d8ff3f */ 	andi	$t8,$t6,0xff3f
/*  f16e584:	370f0080 */ 	ori	$t7,$t8,0x80
/*  f16e588:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f16e58c:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f16e590:	00004012 */ 	mflo	$t0
/*  f16e594:	00101043 */ 	sra	$v0,$s0,0x1
/*  f16e598:	03271821 */ 	addu	$v1,$t9,$a3
/*  f16e59c:	004d0019 */ 	multu	$v0,$t5
/*  f16e5a0:	946f0000 */ 	lhu	$t7,0x0($v1)
/*  f16e5a4:	30583fff */ 	andi	$t8,$v0,0x3fff
/*  f16e5a8:	24060060 */ 	addiu	$a2,$zero,0x60
/*  f16e5ac:	31f9c000 */ 	andi	$t9,$t7,0xc000
/*  f16e5b0:	03197025 */ 	or	$t6,$t8,$t9
/*  f16e5b4:	a46e0000 */ 	sh	$t6,0x0($v1)
/*  f16e5b8:	3c0f800b */ 	lui	$t7,%hi(var800aabb4)
/*  f16e5bc:	8defabb4 */ 	lw	$t7,%lo(var800aabb4)($t7)
/*  f16e5c0:	3c190019 */ 	lui	$t9,%hi(_jpndata1)
/*  f16e5c4:	27394440 */ 	addiu	$t9,$t9,%lo(_jpndata1)
/*  f16e5c8:	0000c012 */ 	mflo	$t8
/*  f16e5cc:	03192821 */ 	addu	$a1,$t8,$t9
/*  f16e5d0:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f16e5d4:	0c003504 */ 	jal	dmaExec
/*  f16e5d8:	010f2021 */ 	addu	$a0,$t0,$t7
/*  f16e5dc:	3c0e800b */ 	lui	$t6,%hi(var800aabb4)
/*  f16e5e0:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f16e5e4:	8dceabb4 */ 	lw	$t6,%lo(var800aabb4)($t6)
/*  f16e5e8:	10000035 */ 	b	.L0f16e6c0
/*  f16e5ec:	010e1021 */ 	addu	$v0,$t0,$t6
.L0f16e5f0:
/*  f16e5f0:	11000032 */ 	beqz	$t0,.L0f16e6bc
/*  f16e5f4:	3c02800b */ 	lui	$v0,%hi(var800aabb4)
/*  f16e5f8:	05600030 */ 	bltz	$t3,.L0f16e6bc
/*  f16e5fc:	000b1840 */ 	sll	$v1,$t3,0x1
/*  f16e600:	01831021 */ 	addu	$v0,$t4,$v1
/*  f16e604:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f16e608:	3c09800b */ 	lui	$t1,%hi(var800aabb8)
/*  f16e60c:	2529abb8 */ 	addiu	$t1,$t1,%lo(var800aabb8)
/*  f16e610:	31f8ff3f */ 	andi	$t8,$t7,0xff3f
/*  f16e614:	37190080 */ 	ori	$t9,$t8,0x80
/*  f16e618:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f16e61c:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f16e620:	240d0060 */ 	addiu	$t5,$zero,0x60
/*  f16e624:	016d0019 */ 	multu	$t3,$t5
/*  f16e628:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f16e62c:	904f0002 */ 	lbu	$t7,0x2($v0)
/*  f16e630:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f16e634:	31f8ff3f */ 	andi	$t8,$t7,0xff3f
/*  f16e638:	37190080 */ 	ori	$t9,$t8,0x80
/*  f16e63c:	a0590002 */ 	sb	$t9,0x2($v0)
/*  f16e640:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f16e644:	00107843 */ 	sra	$t7,$s0,0x1
/*  f16e648:	31e73fff */ 	andi	$a3,$t7,0x3fff
/*  f16e64c:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f16e650:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f16e654:	00004012 */ 	mflo	$t0
/*  f16e658:	332ec000 */ 	andi	$t6,$t9,0xc000
/*  f16e65c:	00ee7825 */ 	or	$t7,$a3,$t6
/*  f16e660:	a44f0000 */ 	sh	$t7,0x0($v0)
/*  f16e664:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f16e668:	03031021 */ 	addu	$v0,$t8,$v1
/*  f16e66c:	94590002 */ 	lhu	$t9,0x2($v0)
/*  f16e670:	3c18800b */ 	lui	$t8,%hi(var800aabb4)
/*  f16e674:	332ec000 */ 	andi	$t6,$t9,0xc000
/*  f16e678:	00ee7825 */ 	or	$t7,$a3,$t6
/*  f16e67c:	a44f0002 */ 	sh	$t7,0x2($v0)
/*  f16e680:	8f18abb4 */ 	lw	$t8,%lo(var800aabb4)($t8)
/*  f16e684:	32191fff */ 	andi	$t9,$s0,0x1fff
/*  f16e688:	00197043 */ 	sra	$t6,$t9,0x1
/*  f16e68c:	01182021 */ 	addu	$a0,$t0,$t8
/*  f16e690:	3c18001a */ 	lui	$t8,%hi(_jpndata2)
/*  f16e694:	2718fb40 */ 	addiu	$t8,$t8,%lo(_jpndata2)
/*  f16e698:	000e79c0 */ 	sll	$t7,$t6,0x7
/*  f16e69c:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f16e6a0:	0c003504 */ 	jal	dmaExec
/*  f16e6a4:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f16e6a8:	3c19800b */ 	lui	$t9,%hi(var800aabb4)
/*  f16e6ac:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f16e6b0:	8f39abb4 */ 	lw	$t9,%lo(var800aabb4)($t9)
/*  f16e6b4:	10000002 */ 	b	.L0f16e6c0
/*  f16e6b8:	01191021 */ 	addu	$v0,$t0,$t9
.L0f16e6bc:
/*  f16e6bc:	8c42abb4 */ 	lw	$v0,%lo(var800aabb4)($v0)
.L0f16e6c0:
/*  f16e6c0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f16e6c4:
/*  f16e6c4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16e6c8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f16e6cc:	03e00008 */ 	jr	$ra
/*  f16e6d0:	00000000 */ 	nop
);
#endif

/**
 * NTSC only supports English, while PAL supports 4 languages and JPN has its
 * own. Each English file is followed immediately by the other translations.
 */
s32 langGetFileNumOffset(void)
{
#if PAL
	s32 offset = g_LanguageId;
	return offset + 2;
#else
	s32 offset = 0;

	if (g_Jpn) {
		offset = 1;
	}

	return offset;
#endif
}

s32 langGetFileId(s32 bank)
{
	return g_LangFiles[bank] + langGetFileNumOffset();
}

void langSetBankSimple(s32 bank)
{
#if VERSION >= VERSION_PAL_BETA
	s32 len = fileGetInflatedLength(langGetFileId(bank));

	if (var80084664pf + len + var8008466cpf - var80084668pf >= 0) {
		s32 len2 = var80084664pf + var8008466cpf - var80084668pf;
		len2 = len2 / 32 * 32;
		g_LangBanks[bank] = func0f167200(langGetFileId(bank), 0x22, (u8 *)var80084668pf, len2);
		var80084668pf = align32(var80084668pf + len);
	} else {
		CRASH();
	}
#else
	s32 file_id = langGetFileId(bank);
	g_LangBanks[bank] = func0f1670fc(file_id, 0x22);
#endif
}

void langSetBank(s32 bank, u8 *arg1, s32 arg2)
{
	s32 file_id = langGetFileId(bank);
	g_LangBanks[bank] = func0f167200(file_id, 0x22, arg1, arg2);
}

void langClearBank(s32 bank)
{
	g_LangBanks[bank] = NULL;
}

/**
 * Resolve a text ID to a string.
 *
 * g_LangBanks is an array of pointers to language file data in RAM. Many of
 * those pointers will be NULL because only the necessary language files are
 * loaded at any given time.
 *
 * The language file data consists of a variable-length array of offsets into
 * the file. Not to be confused with pointers.
 */
char *langGet(s32 textid)
{
	s32 bankindex = textid >> 9;
	s32 textindex = textid & 0x1ff;
	u32 *bank = g_LangBanks[bankindex];
	u32 addr;

	if (bank && bank[textindex]) {
		addr = (u32)bank + bank[textindex];
	} else {
		addr = 0;
	}

	return (char *)addr;
}

#if VERSION >= VERSION_PAL_BETA
void lang0f16f6ecpf(void)
{
	s32 i;

	var80084668pf = align32(var80084664pf);

	for (i = 0; i < 69; i++) {
		if (g_LangBanks[i] != NULL) {
			langSetBankSimple(i);
		}
	}
}
#endif

#if VERSION >= VERSION_PAL_BETA
void langSetEuropean(u32 arg0)
{
	u8 teams;
	bool hasoptionslang = false;

	if (g_LangBanks[LANGBANK_OPTIONS] != NULL) {
		hasoptionslang = true;
	}

	if (hasoptionslang) {
		mpGetTeamsWithDefaultName(&teams);
	}

	switch (arg0) {
	case 0:
		g_LanguageId = LANGUAGE_PAL_EN;
		break;
	case 1:
		g_LanguageId = LANGUAGE_PAL_DE;
		break;
	case 2:
		g_LanguageId = LANGUAGE_PAL_FR;
		break;
	case 3:
		g_LanguageId = LANGUAGE_PAL_ES;
		break;
	case 4:
		g_LanguageId = LANGUAGE_PAL_IT;
		break;
	case 5:
		g_LanguageId = -2;
		break;
	}

	lang0f16f6ecpf();

	if (hasoptionslang) {
		mpSetTeamNamesToDefault(teams);
	}
}
#endif

#if VERSION == VERSION_JPN_FINAL
void langSetJpnEnabled(bool enable)
{
	g_Jpn = enable ? true : false;

	lang0f16f6ecpf();
}
#endif
