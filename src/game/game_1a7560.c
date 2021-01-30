#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/data/data_02e820.h"
#include "game/ceil.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b3350.h"
#include "game/game_0e0770.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/inventory/inventory.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/game_16e810.h"
#include "game/game_173a00.h"
#include "game/game_1a7560.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f1a7560
/*  f1a7560:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f1a7564:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f1a7568:	00809825 */ 	or	$s3,$a0,$zero
/*  f1a756c:	30a4ffff */ 	andi	$a0,$a1,0xffff
/*  f1a7570:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1a7574:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f1a7578:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1a757c:	00e08825 */ 	or	$s1,$a3,$zero
/*  f1a7580:	00c09025 */ 	or	$s2,$a2,$zero
/*  f1a7584:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f1a7588:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f1a758c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f1a7590:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f1a7594:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f1a7598:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1a759c:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f1a75a0:	0fc59ca5 */ 	jal	fileGetUnk04
/*  f1a75a4:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f1a75a8:	00408025 */ 	or	$s0,$v0,$zero
/*  f1a75ac:	0fc59ca0 */ 	jal	fileGetSize
/*  f1a75b0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f1a75b4:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f1a75b8:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f1a75bc:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a75c0:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f1a75c4:	0c008c67 */ 	jal	func0002319c
/*  f1a75c8:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f1a75cc:	8fb6006c */ 	lw	$s6,0x6c($sp)
/*  f1a75d0:	3c1700ff */ 	lui	$s7,0xff
/*  f1a75d4:	36f7ffff */ 	ori	$s7,$s7,0xffff
/*  f1a75d8:	12c00049 */ 	beqz	$s6,.L0f1a7700
/*  f1a75dc:	02c0a825 */ 	or	$s5,$s6,$zero
/*  f1a75e0:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f1a75e4:	02d77824 */ 	and	$t7,$s6,$s7
/*  f1a75e8:	026f2021 */ 	addu	$a0,$s3,$t7
/*  f1a75ec:	0093c823 */ 	subu	$t9,$a0,$s3
/*  f1a75f0:	03193023 */ 	subu	$a2,$t8,$t9
/*  f1a75f4:	02061823 */ 	subu	$v1,$s0,$a2
/*  f1a75f8:	02644023 */ 	subu	$t0,$s3,$a0
/*  f1a75fc:	00684821 */ 	addu	$t1,$v1,$t0
/*  f1a7600:	afa90084 */ 	sw	$t1,0x84($sp)
/*  f1a7604:	0fc5d7bd */ 	jal	func0f175ef4
/*  f1a7608:	00732821 */ 	addu	$a1,$v1,$s3
/*  f1a760c:	8fbe00a0 */ 	lw	$s8,0xa0($sp)
/*  f1a7610:	8e640018 */ 	lw	$a0,0x18($s3)
/*  f1a7614:	86650016 */ 	lh	$a1,0x16($s3)
/*  f1a7618:	02323823 */ 	subu	$a3,$s1,$s2
/*  f1a761c:	0fc5cd0d */ 	jal	func0f173434
/*  f1a7620:	03c03025 */ 	or	$a2,$s8,$zero
/*  f1a7624:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f1a7628:	5140002b */ 	beqzl	$t2,.L0f1a76d8
/*  f1a762c:	02b74824 */ 	and	$t1,$s5,$s7
/*  f1a7630:	8fb0006c */ 	lw	$s0,0x6c($sp)
.L0f1a7634:
/*  f1a7634:	8fb10074 */ 	lw	$s1,0x74($sp)
/*  f1a7638:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a763c:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f1a7640:	0c008c67 */ 	jal	func0002319c
/*  f1a7644:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f1a7648:	8fb6006c */ 	lw	$s6,0x6c($sp)
/*  f1a764c:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a7650:	02202825 */ 	or	$a1,$s1,$zero
/*  f1a7654:	12c00004 */ 	beqz	$s6,.L0f1a7668
/*  f1a7658:	02003025 */ 	or	$a2,$s0,$zero
/*  f1a765c:	02d0a023 */ 	subu	$s4,$s6,$s0
/*  f1a7660:	10000006 */ 	b	.L0f1a767c
/*  f1a7664:	02179024 */ 	and	$s2,$s0,$s7
.L0f1a7668:
/*  f1a7668:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f1a766c:	02179024 */ 	and	$s2,$s0,$s7
/*  f1a7670:	01736021 */ 	addu	$t4,$t3,$s3
/*  f1a7674:	01936823 */ 	subu	$t5,$t4,$s3
/*  f1a7678:	01b2a023 */ 	subu	$s4,$t5,$s2
.L0f1a767c:
/*  f1a767c:	0c008cc5 */ 	jal	func00023314
/*  f1a7680:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1a7684:	962e0000 */ 	lhu	$t6,0x0($s1)
/*  f1a7688:	24010018 */ 	addiu	$at,$zero,0x18
/*  f1a768c:	02727821 */ 	addu	$t7,$s3,$s2
/*  f1a7690:	15c10004 */ 	bne	$t6,$at,.L0f1a76a4
/*  f1a7694:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f1a7698:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f1a769c:	10000002 */ 	b	.L0f1a76a8
/*  f1a76a0:	8c43000c */ 	lw	$v1,0xc($v0)
.L0f1a76a4:
/*  f1a76a4:	00001825 */ 	or	$v1,$zero,$zero
.L0f1a76a8:
/*  f1a76a8:	02b7c824 */ 	and	$t9,$s5,$s7
/*  f1a76ac:	02793021 */ 	addu	$a2,$s3,$t9
/*  f1a76b0:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f1a76b4:	02802825 */ 	or	$a1,$s4,$zero
/*  f1a76b8:	03c03825 */ 	or	$a3,$s8,$zero
/*  f1a76bc:	0fc5d5b0 */ 	jal	func0f1756c0
/*  f1a76c0:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f1a76c4:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f1a76c8:	02a2a821 */ 	addu	$s5,$s5,$v0
/*  f1a76cc:	5500ffd9 */ 	bnezl	$t0,.L0f1a7634
/*  f1a76d0:	8fb0006c */ 	lw	$s0,0x6c($sp)
/*  f1a76d4:	02b74824 */ 	and	$t1,$s5,$s7
.L0f1a76d8:
/*  f1a76d8:	02695021 */ 	addu	$t2,$s3,$t1
/*  f1a76dc:	01533023 */ 	subu	$a2,$t2,$s3
/*  f1a76e0:	24c6000f */ 	addiu	$a2,$a2,0xf
/*  f1a76e4:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f1a76e8:	00c15824 */ 	and	$t3,$a2,$at
/*  f1a76ec:	01603025 */ 	or	$a2,$t3,$zero
/*  f1a76f0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f1a76f4:	02602825 */ 	or	$a1,$s3,$zero
/*  f1a76f8:	0fc59caa */ 	jal	func0f1672a8
/*  f1a76fc:	8fa700a4 */ 	lw	$a3,0xa4($sp)
.L0f1a7700:
/*  f1a7700:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1a7704:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1a7708:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f1a770c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f1a7710:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f1a7714:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f1a7718:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f1a771c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f1a7720:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f1a7724:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f1a7728:	03e00008 */ 	jr	$ra
/*  f1a772c:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f1a7730
/*  f1a7730:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f1a7734:	3c010001 */ 	lui	$at,0x1
/*  f1a7738:	3c0e8009 */ 	lui	$t6,%hi(var80089990)
/*  f1a773c:	0041082b */ 	sltu	$at,$v0,$at
/*  f1a7740:	10200012 */ 	beqz	$at,.L0f1a778c
/*  f1a7744:	00000000 */ 	nop
/*  f1a7748:	8dce9990 */ 	lw	$t6,%lo(var80089990)($t6)
/*  f1a774c:	00021c00 */ 	sll	$v1,$v0,0x10
/*  f1a7750:	00037c03 */ 	sra	$t7,$v1,0x10
/*  f1a7754:	11c0000d */ 	beqz	$t6,.L0f1a778c
/*  f1a7758:	01e01825 */ 	or	$v1,$t7,$zero
/*  f1a775c:	3c188009 */ 	lui	$t8,%hi(var80089990)
/*  f1a7760:	27059990 */ 	addiu	$a1,$t8,%lo(var80089990)
/*  f1a7764:	8ca60000 */ 	lw	$a2,0x0($a1)
/*  f1a7768:	84d90000 */ 	lh	$t9,0x0($a2)
.L0f1a776c:
/*  f1a776c:	54790004 */ 	bnel	$v1,$t9,.L0f1a7780
/*  f1a7770:	8ca60004 */ 	lw	$a2,0x4($a1)
/*  f1a7774:	03e00008 */ 	jr	$ra
/*  f1a7778:	ac860004 */ 	sw	$a2,0x4($a0)
/*  f1a777c:	8ca60004 */ 	lw	$a2,0x4($a1)
.L0f1a7780:
/*  f1a7780:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f1a7784:	54c0fff9 */ 	bnezl	$a2,.L0f1a776c
/*  f1a7788:	84d90000 */ 	lh	$t9,0x0($a2)
.L0f1a778c:
/*  f1a778c:	03e00008 */ 	jr	$ra
/*  f1a7790:	00000000 */ 	nop
);

void *func0f1a7794(u16 fileid, u8 *arg1, s32 arg2, s32 arg3)
{
	void *ptr;

	var8005d9a0 = 6;

	if (arg1) {
		ptr = func0f167200(fileid, 0x11, arg1, arg2);
	} else {
		ptr = func0f1670fc(fileid, 0x11);
	}

	func0f1a7730(ptr);
	func00022a24(ptr, 0x5000000, ptr);
	func0f1a7560(ptr, fileid, 0x5000000, ptr, arg3, arg1 == NULL);

	return ptr;
}

void *fileLoad(u16 fileid)
{
	return func0f1a7794(fileid, 0, 0, 0);
}

void *func0f1a7878(u16 fileid, u8 *arg1, s32 arg2)
{
	return func0f1a7794(fileid, arg1, arg2, 0);
}
