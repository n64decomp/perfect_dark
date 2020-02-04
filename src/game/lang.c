#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "types.h"
#include "game/game_0b28d0.h"
#include "game/game_0f09f0.h"
#include "game/game_129900.h"
#include "game/game_1668e0.h"
#include "game/game_176080.h"
#include "game/lang.h"

u32 langGetLangBankIndexFromStagenum(s32 stagenum)
{
	u32 index;

	switch (stagenum) {
	case STAGE_PELAGIC:       index = 0x0b; break;
	case STAGE_EXTRACTION:    index = 0x03; break;
	case STAGE_TEST_RUN:      index = 0x1c; break;
	case STAGE_24:            index = 0x1f; break;
	case STAGE_MAIANSOS:      index = 0x1e; break;
	case STAGE_TEST_DEST:     index = 0x0d; break;
	case STAGE_2B:            index = 0x20; break;
	case STAGE_RETAKING:      index = 0x1d; break;
	case STAGE_WAR:           index = 0x23; break;
	case STAGE_CHICAGO:       index = 0x19; break;
	case STAGE_G5BUILDING:    index = 0x0c; break;
	case STAGE_ESCAPE:        index = 0x24; break;
	case STAGE_MP_TEMPLE:     index = 0x12; break;
	case STAGE_MP_PIPES:      index = 0x09; break;
	case STAGE_MP_G5BUILDING: index = 0x0a; break;
	case STAGE_CITRAINING:    index = 0x0e; break;
	case STAGE_MP_COMPLEX:    index = 0x1a; break;
	case STAGE_MP_SKEDAR:     index = 0x17; break;
	case STAGE_TEST_LEN:      index = 0x14; break;
	case STAGE_DEFECTION:     index = 0x01; break;
	case STAGE_VILLA:         index = 0x10; break;
	case STAGE_DEFENSE:       index = 0x11; break;
	case STAGE_TEST_ASH:      index = 0x04; break;
	case STAGE_INVESTIGATION: index = 0x0f; break;
	case STAGE_ATTACKSHIP:    index = 0x13; break;
	case STAGE_RESCUE:        index = 0x15; break;
	case STAGE_INFILTRATION:  index = 0x16; break;
	case STAGE_28:            index = 0x0b; break;
	case STAGE_DEEPSEA:       index = 0x18; break;
	case STAGE_SKEDARRUINS:   index = 0x21; break;
	case STAGE_AIRFORCEONE:   index = 0x1b; break;
	case STAGE_TEST_ARCH:     index = 0x02; break;
	case STAGE_MP_RAVINE:     index = 0x08; break;
	case STAGE_CRASHSITE:     index = 0x05; break;
	case STAGE_AIRBASE:       index = 0x07; break;
	case STAGE_TEST_UFF:      index = 0x2d; break;
	case STAGE_TEST_OLD:      index = 0x2e; break;
	case STAGE_DUEL:          index = 0x2f; break;
	case STAGE_TEST_LAM:      index = 0x30; break;
	case STAGE_MP_BASE:       index = 0x31; break;
	case STAGE_TEST_MP2:      index = 0x32; break;
	case STAGE_MP_AREA52:     index = 0x33; break;
	case STAGE_MP_WAREHOUSE:  index = 0x34; break;
	case STAGE_MP_CARPARK:    index = 0x35; break;
	case STAGE_TEST_MP6:      index = 0x36; break;
	case STAGE_TEST_MP7:      index = 0x37; break;
	case STAGE_TEST_MP8:      index = 0x38; break;
	case STAGE_MP_RUINS:      index = 0x39; break;
	case STAGE_MP_SEWERS:     index = 0x3a; break;
	case STAGE_MP_FELICITY:   index = 0x3b; break;
	case STAGE_MP_FORTRESS:   index = 0x3c; break;
	case STAGE_MP_VILLA:      index = 0x3d; break;
	case STAGE_TEST_MP14:     index = 0x3e; break;
	case STAGE_MP_GRID:       index = 0x3f; break;
	case STAGE_TEST_MP16:     index = 0x40; break;
	case STAGE_TEST_MP17:     index = 0x41; break;
	case STAGE_TEST_MP18:     index = 0x42; break;
	case STAGE_TEST_MP19:     index = 0x43; break;
	case STAGE_TEST_MP20:     index = 0x44; break;
	case STAGE_MBR:           index = 0x25; break;
	case STAGE_TEST_SILO:     index = 0x22; break;
	default:
		while (true) {
			// empty
		}
	}

	return index;
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
/*  f16e424:	3c0c800b */ 	lui	$t4,0x800b
/*  f16e428:	8d8cabb8 */ 	lw	$t4,-0x5448($t4)
/*  f16e42c:	00002825 */ 	or	$a1,$zero,$zero
/*  f16e430:	00003825 */ 	or	$a3,$zero,$zero
/*  f16e434:	2409007c */ 	addiu	$t1,$zero,0x7c
/*  f16e438:	01802025 */ 	or	$a0,$t4,$zero
.L0f16e43c:
/*  f16e43c:	15000006 */ 	bnez	$t0,.L0f16e458
/*  f16e440:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f16e4d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e4d8:	1500000c */ 	bnez	$t0,.L0f16e50c
/*  f16e4dc:	240d0060 */ 	addiu	$t5,$zero,0x60
/*  f16e4e0:	00ad0019 */ 	multu	$a1,$t5
/*  f16e4e4:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f16e4e8:	31f9ff3f */ 	andi	$t9,$t7,0xff3f
/*  f16e4ec:	372e0080 */ 	ori	$t6,$t9,0x80
/*  f16e4f0:	a08e0000 */ 	sb	$t6,0x0($a0)
/*  f16e4f4:	3c0f800b */ 	lui	$t7,0x800b
/*  f16e4f8:	8defabb4 */ 	lw	$t7,-0x544c($t7)
/*  f16e4fc:	0000c012 */ 	mflo	$t8
/*  f16e500:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f16e504:	1000006f */ 	beqz	$zero,.L0f16e6c4
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
/*  f16e544:	3c19800b */ 	lui	$t9,0x800b
/*  f16e548:	8f39abb4 */ 	lw	$t9,-0x544c($t9)
/*  f16e54c:	00007812 */ 	mflo	$t7
/*  f16e550:	1000005b */ 	beqz	$zero,.L0f16e6c0
/*  f16e554:	01f91021 */ 	addu	$v0,$t7,$t9
.L0f16e558:
/*  f16e558:	15000025 */ 	bnez	$t0,.L0f16e5f0
/*  f16e55c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f16e5b8:	3c0f800b */ 	lui	$t7,0x800b
/*  f16e5bc:	8defabb4 */ 	lw	$t7,-0x544c($t7)
/*  f16e5c0:	3c190019 */ 	lui	$t9,0x19
/*  f16e5c4:	27394440 */ 	addiu	$t9,$t9,0x4440
/*  f16e5c8:	0000c012 */ 	mflo	$t8
/*  f16e5cc:	03192821 */ 	addu	$a1,$t8,$t9
/*  f16e5d0:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f16e5d4:	0c003504 */ 	jal	func0000d410
/*  f16e5d8:	010f2021 */ 	addu	$a0,$t0,$t7
/*  f16e5dc:	3c0e800b */ 	lui	$t6,0x800b
/*  f16e5e0:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f16e5e4:	8dceabb4 */ 	lw	$t6,-0x544c($t6)
/*  f16e5e8:	10000035 */ 	beqz	$zero,.L0f16e6c0
/*  f16e5ec:	010e1021 */ 	addu	$v0,$t0,$t6
.L0f16e5f0:
/*  f16e5f0:	11000032 */ 	beqz	$t0,.L0f16e6bc
/*  f16e5f4:	3c02800b */ 	lui	$v0,0x800b
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
/*  f16e670:	3c18800b */ 	lui	$t8,0x800b
/*  f16e674:	332ec000 */ 	andi	$t6,$t9,0xc000
/*  f16e678:	00ee7825 */ 	or	$t7,$a3,$t6
/*  f16e67c:	a44f0002 */ 	sh	$t7,0x2($v0)
/*  f16e680:	8f18abb4 */ 	lw	$t8,-0x544c($t8)
/*  f16e684:	32191fff */ 	andi	$t9,$s0,0x1fff
/*  f16e688:	00197043 */ 	sra	$t6,$t9,0x1
/*  f16e68c:	01182021 */ 	addu	$a0,$t0,$t8
/*  f16e690:	3c18001a */ 	lui	$t8,0x1a
/*  f16e694:	2718fb40 */ 	addiu	$t8,$t8,-1216
/*  f16e698:	000e79c0 */ 	sll	$t7,$t6,0x7
/*  f16e69c:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f16e6a0:	0c003504 */ 	jal	func0000d410
/*  f16e6a4:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f16e6a8:	3c19800b */ 	lui	$t9,0x800b
/*  f16e6ac:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f16e6b0:	8f39abb4 */ 	lw	$t9,-0x544c($t9)
/*  f16e6b4:	10000002 */ 	beqz	$zero,.L0f16e6c0
/*  f16e6b8:	01191021 */ 	addu	$v0,$t0,$t9
.L0f16e6bc:
/*  f16e6bc:	8c42abb4 */ 	lw	$v0,-0x544c($v0)
.L0f16e6c0:
/*  f16e6c0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f16e6c4:
/*  f16e6c4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16e6c8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f16e6cc:	03e00008 */ 	jr	$ra
/*  f16e6d0:	00000000 */ 	sll	$zero,$zero,0x0
);

/**
 * NTSC only supports English, while PAL supports 4 languages and JAP has its
 * own. Each English file is followed immediately by the other translations.
 *
 * As it stands in the NTSC version, g_LanguageId is a flag that controls
 * whether it uses English or Japanese text. This decomp is NTSC, so that's what
 * you see here.
 *
 * For PAL, I suspect this function was adjusted to return values other than
 * 0 and 1.
 */
s32 langGetLanguageId(void)
{
	s32 ret = 0;

	if (g_LanguageId != 0) {
		ret = 1;
	}

	return ret;
}

s32 langGetFileId(s32 bank)
{
	return g_LangFiles[bank] + langGetLanguageId();
}

void langSetBankSimple(s32 bank)
{
	s32 file_id = langGetFileId(bank);
	g_LangBanks[bank] = func0f1670fc(file_id, 0x22);
}

void langSetBank(s32 bank, s32 arg1, s32 arg2)
{
	s32 file_id = langGetFileId(bank);
	g_LangBanks[bank] = func0f167200(file_id, 0x22, arg1, arg2);
}

void langClearBank(s32 bank)
{
	g_LangBanks[bank] = NULL;
}

GLOBAL_ASM(
glabel langGet
/*  f16e7c4:	00047243 */ 	sra	$t6,$a0,0x9
/*  f16e7c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f16e7cc:	3c02800b */ 	lui	$v0,0x800b
/*  f16e7d0:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f16e7d4:	8c42aaa0 */ 	lw	$v0,-0x5560($v0)
/*  f16e7d8:	309801ff */ 	andi	$t8,$a0,0x1ff
/*  f16e7dc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f16e7e0:	10400006 */ 	beqz	$v0,.L0f16e7fc
/*  f16e7e4:	00594021 */ 	addu	$t0,$v0,$t9
/*  f16e7e8:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f16e7ec:	10a00003 */ 	beqz	$a1,.L0f16e7fc
/*  f16e7f0:	00a21821 */ 	addu	$v1,$a1,$v0
/*  f16e7f4:	03e00008 */ 	jr	$ra
/*  f16e7f8:	00601025 */ 	or	$v0,$v1,$zero
.L0f16e7fc:
/*  f16e7fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f16e800:	03e00008 */ 	jr	$ra
/*  f16e804:	00601025 */ 	or	$v0,$v1,$zero
);
