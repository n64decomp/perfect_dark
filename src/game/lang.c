#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/dma.h"
#include "data.h"
#include "types.h"

/**
 * Officially, the NTSC versions are American English only, while the PAL
 * versions support British English, French, German, Italian and Spanish, and
 * the Japanese version is Japanese only. However all versions actually have
 * support for all 7 languages, despite some being inaccessible and not even
 * translated.
 *
 * All strings are categorised into areas, which we call banks. There is one
 * bank per stage, as well as some common banks such as menus and weapon names.
 * Each bank contains 7 files; one for each translation.
 *
 * An example language filename is LoptionsE. "options" is the bank name, and E
 * means it's the American English file.
 *
 * The list of suffixes are:
 * E - American English
 * J - Japanese
 * P - British English (P is for PAL)
 * _str_f = French
 * _str_g = German
 * _str_i = Italian
 * _str_s = Spanish
 *
 * Banks are loaded based on the current stage. When loading a bank, only the
 * current translation is loaded.
 *
 * Text is referenced using a 16 bit text ID. The text ID is made up of a 7-bit
 * bank index and a 9-bit string index within that bank:
 *
 *     bbbbbbbs ssssssss
 *
 * For versions prior to PAL, the language files are loaded during stage load
 * and allocated from memp. This method doesn't work for PAL because PAL
 * supports changing the language mid-stage and memp allocations cannot be freed
 * until a new stage is loaded. So for PAL, during stage load a single buffer is
 * allocated from memp to hold all loaded language files. The buffer is
 * repopulated when the language is changed, and the lang banks point to their
 * relevant offsets within that buffer.
 */

u32 *g_LangBanks[69];
struct var800aabb4 *var800aabb4;
struct var800aabb8 *var800aabb8;

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
glabel lang0f16e3fc
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
extern u8 _jpndata1;
extern u8 _jpndata2;

struct var800aabb4 *lang0f16e3fc(s32 arg0)
{
	s32 i;
	s32 t2 = -1;
	s32 t3 = -1;
	bool t0 = false;

	if (arg0 & 0x2000) {
		if (1);
		t0 = true;
	}

	if (arg0 && arg0);

	for (i = 0; i < 0x7c; i++) {
		if ((t0 || (arg0 >> 1) != var800aabb8[i].unk00_02)
				&& (!t0 || i + 1 >= 0x7c
					|| (arg0 >> 1) != var800aabb8[i + 0].unk00_02
					|| (arg0 >> 1) != var800aabb8[i + 1].unk00_02)) {
			if (var800aabb8[i].unk00_00 == 0) {
				if (1);
				t2 = i;
			}

			if (var800aabb8[i].unk00_00 == 0 && var800aabb8[i + 1].unk00_00 == 0 && i + 1 < 0x7c) {
				t3 = i;
			}
		} else {
			break;
		}
	}

	if (i < 0x7c) {
		if (!t0) {
			var800aabb8[i].unk00_00 = 2;

			return &var800aabb4[i];
		} else {
			var800aabb8[i + 0].unk00_00 = 2;
			var800aabb8[i + 1].unk00_00 = 2;

			return &var800aabb4[i];
		}
	}

	if (!t0 && t2 >= 0) {
		var800aabb8[t2].unk00_00 = 2;
		var800aabb8[t2].unk00_02 = arg0 >> 1;

		dmaExec(&var800aabb4[t2], (u32)&_jpndata1 + (arg0 >> 1) * 0x60, 0x60);

		return &var800aabb4[t2];
	}

	if (t0 && t3 >= 0) {
		var800aabb8[t3 + 0].unk00_00 = 2;
		var800aabb8[t3 + 1].unk00_00 = 2;
		var800aabb8[t3 + 0].unk00_02 = arg0 >> 1;
		var800aabb8[t3 + 1].unk00_02 = arg0 >> 1;

		dmaExec(&var800aabb4[t3], (u32)&_jpndata2 + ((arg0 & 0x1fff) >> 1) * 0x80, 0x80);

		return &var800aabb4[t3];
	}

	return &var800aabb4[0];
}
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

	return offset;
#endif
}

s32 langGetFileId(s32 bank)
{
	return g_LangFiles[bank] + langGetFileNumOffset();
}

void langLoad(s32 bank)
{
#if VERSION >= VERSION_PAL_BETA
	s32 len = fileGetInflatedSize(langGetFileId(bank));

	if ((s32)g_LangBuffer + len + g_LangBufferSize - (s32)g_LangBufferPos >= 0) {
		s32 len2 = (s32)g_LangBuffer + g_LangBufferSize - (s32)g_LangBufferPos;
		len2 = len2 / 32 * 32;
		g_LangBanks[bank] = fileLoadToAddr(langGetFileId(bank), FILELOADMETHOD_DEFAULT, (u8 *)g_LangBufferPos, len2);
		g_LangBufferPos = (u8 *)(align32((s32)g_LangBufferPos + len));
	} else {
		CRASH();
	}
#else
	s32 file_id = langGetFileId(bank);
	g_LangBanks[bank] = fileLoadToNew(file_id, FILELOADMETHOD_DEFAULT);
#endif
}

void langLoadToAddr(s32 bank, u8 *dst, s32 size)
{
	s32 file_id = langGetFileId(bank);
	g_LangBanks[bank] = fileLoadToAddr(file_id, FILELOADMETHOD_DEFAULT, dst, size);
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
void langReload(void)
{
	s32 i;

	g_LangBufferPos = (u8 *)align32(g_LangBuffer);

	for (i = 0; i < ARRAYCOUNT(g_LangBanks); i++) {
		if (g_LangBanks[i] != NULL) {
			langLoad(i);
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

	langReload();

	if (hasoptionslang) {
		mpSetTeamNamesToDefault(teams);
	}
}
#endif
