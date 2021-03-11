#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/dma.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_PAL_FINAL
u32 var80084660pf = 0;
u32 var80084664pf = 0;
u32 var80084668pf = 0;
u32 var8008466cpf = 0;
#endif

u32 *g_LangBanks[69];
void *var800aabb4;
struct var800aabb8 *var800aabb8;

u32 g_LanguageId = 0;

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
/*  f16e5c0:	3c190019 */ 	lui	$t9,0x19
/*  f16e5c4:	27394440 */ 	addiu	$t9,$t9,0x4440
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
/*  f16e690:	3c18001a */ 	lui	$t8,0x1a
/*  f16e694:	2718fb40 */ 	addiu	$t8,$t8,-1216
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

/**
 * NTSC only supports English, while PAL supports 4 languages and JPN has its
 * own. Each English file is followed immediately by the other translations.
 */
s32 langGetLanguageId(void)
{
#if PAL
	s32 ret = g_LanguageId;
	return ret + 2;
#else
	s32 ret = LANGUAGE_NTSC_EN;

	if (g_LanguageId != LANGUAGE_NTSC_EN) {
		ret = LANGUAGE_NTSC_JP;
	}

	return ret;
#endif
}

s32 langGetFileId(s32 bank)
{
	return g_LangFiles[bank] + langGetLanguageId();
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel langSetBankSimple
/*  f16f578:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16f57c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16f580:	0fc5bd51 */ 	jal	0xf16f544
/*  f16f584:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f16f588:	0fc59ff5 */ 	jal	0xf167fd4
/*  f16f58c:	00402025 */ 	move	$a0,$v0
/*  f16f590:	3c038008 */ 	lui	$v1,0x8008
/*  f16f594:	8c634664 */ 	lw	$v1,0x4664($v1)
/*  f16f598:	3c058008 */ 	lui	$a1,0x8008
/*  f16f59c:	8ca5466c */ 	lw	$a1,0x466c($a1)
/*  f16f5a0:	3c068008 */ 	lui	$a2,0x8008
/*  f16f5a4:	8cc64668 */ 	lw	$a2,0x4668($a2)
/*  f16f5a8:	00627021 */ 	addu	$t6,$v1,$v0
/*  f16f5ac:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f16f5b0:	01e6c023 */ 	subu	$t8,$t7,$a2
/*  f16f5b4:	0700001e */ 	bltz	$t8,.PF0f16f630
/*  f16f5b8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f16f5bc:	0065c821 */ 	addu	$t9,$v1,$a1
/*  f16f5c0:	03263823 */ 	subu	$a3,$t9,$a2
/*  f16f5c4:	04e10003 */ 	bgez	$a3,.PF0f16f5d4
/*  f16f5c8:	00074143 */ 	sra	$t0,$a3,0x5
/*  f16f5cc:	24e1001f */ 	addiu	$at,$a3,0x1f
/*  f16f5d0:	00014143 */ 	sra	$t0,$at,0x5
.PF0f16f5d4:
/*  f16f5d4:	00084940 */ 	sll	$t1,$t0,0x5
/*  f16f5d8:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f16f5dc:	0fc5bd51 */ 	jal	0xf16f544
/*  f16f5e0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f16f5e4:	3c068008 */ 	lui	$a2,0x8008
/*  f16f5e8:	8cc64668 */ 	lw	$a2,0x4668($a2)
/*  f16f5ec:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f16f5f0:	00402025 */ 	move	$a0,$v0
/*  f16f5f4:	0fc5a060 */ 	jal	0xf168180
/*  f16f5f8:	24050022 */ 	li	$a1,0x22
/*  f16f5fc:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f16f600:	3c0c8008 */ 	lui	$t4,0x8008
/*  f16f604:	8d8c4668 */ 	lw	$t4,0x4668($t4)
/*  f16f608:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f16f60c:	3c01800b */ 	lui	$at,0x800b
/*  f16f610:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f16f614:	002b0821 */ 	addu	$at,$at,$t3
/*  f16f618:	ac22b040 */ 	sw	$v0,-0x4fc0($at)
/*  f16f61c:	0fc5df7c */ 	jal	0xf177df0
/*  f16f620:	018d2021 */ 	addu	$a0,$t4,$t5
/*  f16f624:	3c018008 */ 	lui	$at,0x8008
/*  f16f628:	10000003 */ 	b	.PF0f16f638
/*  f16f62c:	ac224668 */ 	sw	$v0,0x4668($at)
.PF0f16f630:
/*  f16f630:	240e0045 */ 	li	$t6,0x45
/*  f16f634:	a00e0000 */ 	sb	$t6,0x0($zero)
.PF0f16f638:
/*  f16f638:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16f63c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16f640:	03e00008 */ 	jr	$ra
/*  f16f644:	00000000 */ 	nop
);
#else
void langSetBankSimple(s32 bank)
{
	s32 file_id = langGetFileId(bank);
	g_LangBanks[bank] = func0f1670fc(file_id, 0x22);
}
#endif

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

#if PAL
GLOBAL_ASM(
glabel func0f16f6ecpf
/*  f16f6ec:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f16f6f0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f16f6f4:	3c048008 */ 	lui	$a0,0x8008
/*  f16f6f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f16f6fc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f16f700:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16f704:	0fc5df7c */ 	jal	0xf177df0
/*  f16f708:	8c844664 */ 	lw	$a0,0x4664($a0)
/*  f16f70c:	3c018008 */ 	lui	$at,0x8008
/*  f16f710:	3c11800b */ 	lui	$s1,0x800b
/*  f16f714:	ac224668 */ 	sw	$v0,0x4668($at)
/*  f16f718:	2631b040 */ 	addiu	$s1,$s1,-20416
/*  f16f71c:	00008025 */ 	move	$s0,$zero
/*  f16f720:	24120045 */ 	li	$s2,0x45
.PF0f16f724:
/*  f16f724:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f16f728:	51c00004 */ 	beqzl	$t6,.PF0f16f73c
/*  f16f72c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16f730:	0fc5bd5e */ 	jal	0xf16f578
/*  f16f734:	02002025 */ 	move	$a0,$s0
/*  f16f738:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f16f73c:
/*  f16f73c:	1612fff9 */ 	bne	$s0,$s2,.PF0f16f724
/*  f16f740:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f16f744:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f16f748:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16f74c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f16f750:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f16f754:	03e00008 */ 	jr	$ra
/*  f16f758:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#endif

#if PAL
GLOBAL_ASM(
glabel func0f16f75c
.late_rodata
glabel var7f1b9080pf
.word 0x7f16f7b4
glabel var7f1b9084pf
.word 0x7f16f7c0
glabel var7f1b9088pf
.word 0x7f16f7d0
glabel var7f1b908cpf
.word 0x7f16f7e0
glabel var7f1b9090pf
.word 0x7f16f7f0
glabel var7f1b9094pf
.word 0x7f16f800
.text
/*  f16f75c:	3c0e800b */ 	lui	$t6,0x800b
/*  f16f760:	8dceb0ec */ 	lw	$t6,-0x4f14($t6)
/*  f16f764:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16f768:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16f76c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f16f770:	11c00002 */ 	beqz	$t6,.PF0f16f77c
/*  f16f774:	00001025 */ 	move	$v0,$zero
/*  f16f778:	24020001 */ 	li	$v0,0x1
.PF0f16f77c:
/*  f16f77c:	10400004 */ 	beqz	$v0,.PF0f16f790
/*  f16f780:	27a4001f */ 	addiu	$a0,$sp,0x1f
/*  f16f784:	0fc624bf */ 	jal	0xf1892fc
/*  f16f788:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f16f78c:	8fa20018 */ 	lw	$v0,0x18($sp)
.PF0f16f790:
/*  f16f790:	8faf0020 */ 	lw	$t7,0x20($sp)
/*  f16f794:	2de10006 */ 	sltiu	$at,$t7,0x6
/*  f16f798:	1020001c */ 	beqz	$at,.PF0f16f80c
/*  f16f79c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f16f7a0:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16f7a4:	002f0821 */ 	addu	$at,$at,$t7
/*  f16f7a8:	8c2f9080 */ 	lw	$t7,-0x6f80($at)
/*  f16f7ac:	01e00008 */ 	jr	$t7
/*  f16f7b0:	00000000 */ 	nop
/*  f16f7b4:	3c018008 */ 	lui	$at,0x8008
/*  f16f7b8:	10000014 */ 	b	.PF0f16f80c
/*  f16f7bc:	ac204670 */ 	sw	$zero,0x4670($at)
/*  f16f7c0:	24180002 */ 	li	$t8,0x2
/*  f16f7c4:	3c018008 */ 	lui	$at,0x8008
/*  f16f7c8:	10000010 */ 	b	.PF0f16f80c
/*  f16f7cc:	ac384670 */ 	sw	$t8,0x4670($at)
/*  f16f7d0:	24190001 */ 	li	$t9,0x1
/*  f16f7d4:	3c018008 */ 	lui	$at,0x8008
/*  f16f7d8:	1000000c */ 	b	.PF0f16f80c
/*  f16f7dc:	ac394670 */ 	sw	$t9,0x4670($at)
/*  f16f7e0:	24080004 */ 	li	$t0,0x4
/*  f16f7e4:	3c018008 */ 	lui	$at,0x8008
/*  f16f7e8:	10000008 */ 	b	.PF0f16f80c
/*  f16f7ec:	ac284670 */ 	sw	$t0,0x4670($at)
/*  f16f7f0:	24090003 */ 	li	$t1,0x3
/*  f16f7f4:	3c018008 */ 	lui	$at,0x8008
/*  f16f7f8:	10000004 */ 	b	.PF0f16f80c
/*  f16f7fc:	ac294670 */ 	sw	$t1,0x4670($at)
/*  f16f800:	240afffe */ 	li	$t2,-2
/*  f16f804:	3c018008 */ 	lui	$at,0x8008
/*  f16f808:	ac2a4670 */ 	sw	$t2,0x4670($at)
.PF0f16f80c:
/*  f16f80c:	0fc5bdbb */ 	jal	0xf16f6ec
/*  f16f810:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f16f814:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f16f818:	50400004 */ 	beqzl	$v0,.PF0f16f82c
/*  f16f81c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16f820:	0fc624e1 */ 	jal	0xf189384
/*  f16f824:	93a4001f */ 	lbu	$a0,0x1f($sp)
/*  f16f828:	8fbf0014 */ 	lw	$ra,0x14($sp)
.PF0f16f82c:
/*  f16f82c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16f830:	03e00008 */ 	jr	$ra
/*  f16f834:	00000000 */ 	nop
);
#endif
