#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096750.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_152fa0.h"
#include "game/game_1531a0.h"
#include "game/game_17f930.h"
#include "game/game_18e5a0.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1b8dc0[] = "RadarDrawDot : Prop=%x";

const u32 var7f1b8dd8[] = {0x40490fdb};
const u32 var7f1b8ddc[] = {0x3b83126f};
const u32 var7f1b8de0[] = {0x3c8efa35};
const u32 var7f1b8de4[] = {0x00000000};
const u32 var7f1b8de8[] = {0x00000000};
const u32 var7f1b8dec[] = {0x00000000};

GLOBAL_ASM(
glabel func0f18e5a0
/*  f18e5a0:	3c018008 */ 	lui	$at,%hi(var80087cc0)
/*  f18e5a4:	03e00008 */ 	jr	$ra
/*  f18e5a8:	ac247cc0 */ 	sw	$a0,%lo(var80087cc0)($at)
);

GLOBAL_ASM(
glabel func0f18e5ac
/*  f18e5ac:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f18e5b0:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f18e5b4:	248f0008 */ 	addiu	$t7,$a0,0x8
/*  f18e5b8:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f18e5bc:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f18e5c0:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f18e5c4:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f18e5c8:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e5cc:	3c18ba00 */ 	lui	$t8,0xba00
/*  f18e5d0:	37180602 */ 	ori	$t8,$t8,0x602
/*  f18e5d4:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f18e5d8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f18e5dc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f18e5e0:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f18e5e4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f18e5e8:	358c1301 */ 	ori	$t4,$t4,0x1301
/*  f18e5ec:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f18e5f0:	afab00b8 */ 	sw	$t3,0xb8($sp)
/*  f18e5f4:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f18e5f8:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f18e5fc:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f18e600:	3c0fb900 */ 	lui	$t7,0xb900
/*  f18e604:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f18e608:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f18e60c:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e610:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f18e614:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f18e618:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e61c:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e620:	354a1001 */ 	ori	$t2,$t2,0x1001
/*  f18e624:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e628:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e62c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f18e630:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e634:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f18e638:	3c0dba00 */ 	lui	$t5,0xba00
/*  f18e63c:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f18e640:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f18e644:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f18e648:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f18e64c:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f18e650:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f18e654:	3c18ba00 */ 	lui	$t8,0xba00
/*  f18e658:	37180903 */ 	ori	$t8,$t8,0x903
/*  f18e65c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f18e660:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e664:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f18e668:	add90004 */ 	sw	$t9,0x4($t6)
/*  f18e66c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f18e670:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f18e674:	3c0cba00 */ 	lui	$t4,0xba00
/*  f18e678:	358c0e02 */ 	ori	$t4,$t4,0xe02
/*  f18e67c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f18e680:	afab00b8 */ 	sw	$t3,0xb8($sp)
/*  f18e684:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f18e688:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f18e68c:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f18e690:	3c0fe700 */ 	lui	$t7,0xe700
/*  f18e694:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e698:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f18e69c:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e6a0:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f18e6a4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f18e6a8:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e6ac:	354a1402 */ 	ori	$t2,$t2,0x1402
/*  f18e6b0:	3c0db900 */ 	lui	$t5,0xb900
/*  f18e6b4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e6b8:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e6bc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f18e6c0:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e6c4:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f18e6c8:	3c0e0050 */ 	lui	$t6,0x50
/*  f18e6cc:	35ce4240 */ 	ori	$t6,$t6,0x4240
/*  f18e6d0:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f18e6d4:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f18e6d8:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f18e6dc:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f18e6e0:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f18e6e4:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f18e6e8:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f18e6ec:	8fa700c0 */ 	lw	$a3,0xc0($sp)
/*  f18e6f0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f18e6f4:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f18e6f8:	3c0afffd */ 	lui	$t2,0xfffd
/*  f18e6fc:	3c19fcff */ 	lui	$t9,0xfcff
/*  f18e700:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f18e704:	354af6fb */ 	ori	$t2,$t2,0xf6fb
/*  f18e708:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f18e70c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f18e710:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f18e714:	3c0dfa00 */ 	lui	$t5,0xfa00
/*  f18e718:	00a08025 */ 	or	$s0,$a1,$zero
/*  f18e71c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f18e720:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f18e724:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f18e728:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f18e72c:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f18e730:	3c068008 */ 	lui	$a2,%hi(g_ScreenWidthMultiplier)
/*  f18e734:	24c6fac0 */ 	addiu	$a2,$a2,%lo(g_ScreenWidthMultiplier)
/*  f18e738:	248f0008 */ 	addiu	$t7,$a0,0x8
/*  f18e73c:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e740:	92050004 */ 	lbu	$a1,0x4($s0)
/*  f18e744:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f18e748:	3c01f600 */ 	lui	$at,0xf600
/*  f18e74c:	00a7c021 */ 	addu	$t8,$a1,$a3
/*  f18e750:	03190019 */ 	multu	$t8,$t9
/*  f18e754:	01257021 */ 	addu	$t6,$t1,$a1
/*  f18e758:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18e75c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f18e760:	312f03ff */ 	andi	$t7,$t1,0x3ff
/*  f18e764:	44894000 */ 	mtc1	$t1,$f8
/*  f18e768:	02002825 */ 	or	$a1,$s0,$zero
/*  f18e76c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f18e770:	00005012 */ 	mflo	$t2
/*  f18e774:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18e778:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f18e77c:	01816825 */ 	or	$t5,$t4,$at
/*  f18e780:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f18e784:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f18e788:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f18e78c:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f18e790:	00ea0019 */ 	multu	$a3,$t2
/*  f18e794:	00005812 */ 	mflo	$t3
/*  f18e798:	316c03ff */ 	andi	$t4,$t3,0x3ff
/*  f18e79c:	000c7380 */ 	sll	$t6,$t4,0xe
/*  f18e7a0:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f18e7a4:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f18e7a8:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f18e7ac:	8fa200c8 */ 	lw	$v0,0xc8($sp)
/*  f18e7b0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f18e7b4:	00e80019 */ 	multu	$a3,$t0
/*  f18e7b8:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f18e7bc:	00003825 */ 	or	$a3,$zero,$zero
/*  f18e7c0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f18e7c4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18e7c8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18e7cc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f18e7d0:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f18e7d4:	0000c812 */ 	mflo	$t9
/*  f18e7d8:	44992000 */ 	mtc1	$t9,$f4
/*  f18e7dc:	00000000 */ 	nop
/*  f18e7e0:	00480019 */ 	multu	$v0,$t0
/*  f18e7e4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f18e7e8:	44822000 */ 	mtc1	$v0,$f4
/*  f18e7ec:	e7a600b0 */ 	swc1	$f6,0xb0($sp)
/*  f18e7f0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f18e7f4:	00005012 */ 	mflo	$t2
/*  f18e7f8:	448a8000 */ 	mtc1	$t2,$f16
/*  f18e7fc:	00000000 */ 	nop
/*  f18e800:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f18e804:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f18e808:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f18e80c:	e7b200a8 */ 	swc1	$f18,0xa8($sp)
/*  f18e810:	920c0005 */ 	lbu	$t4,0x5($s0)
/*  f18e814:	92070004 */ 	lbu	$a3,0x4($s0)
/*  f18e818:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18e81c:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f18e820:	240d0028 */ 	addiu	$t5,$zero,0x28
/*  f18e824:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f18e828:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f18e82c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f18e830:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18e834:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18e838:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18e83c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18e840:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f18e844:	92180006 */ 	lbu	$t8,0x6($s0)
/*  f18e848:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f18e84c:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f18e850:	0018c82a */ 	slt	$t9,$zero,$t8
/*  f18e854:	afb90030 */ 	sw	$t9,0x30($sp)
/*  f18e858:	27a500b0 */ 	addiu	$a1,$sp,0xb0
/*  f18e85c:	0fc2c9e3 */ 	jal	func0f0b278c
/*  f18e860:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f18e864:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f18e868:	3c0ce700 */ 	lui	$t4,0xe700
/*  f18e86c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f18e870:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f18e874:	afab00b8 */ 	sw	$t3,0xb8($sp)
/*  f18e878:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f18e87c:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f18e880:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f18e884:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f18e888:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f18e88c:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f18e890:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e894:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f18e898:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f18e89c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f18e8a0:	3c0bba00 */ 	lui	$t3,0xba00
/*  f18e8a4:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f18e8a8:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f18e8ac:	afaa00b8 */ 	sw	$t2,0xb8($sp)
/*  f18e8b0:	3c0c0008 */ 	lui	$t4,0x8
/*  f18e8b4:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f18e8b8:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f18e8bc:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f18e8c0:	3c0db900 */ 	lui	$t5,0xb900
/*  f18e8c4:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f18e8c8:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f18e8cc:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e8d0:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f18e8d4:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f18e8d8:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e8dc:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e8e0:	354a1001 */ 	ori	$t2,$t2,0x1001
/*  f18e8e4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e8e8:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e8ec:	3c0b0001 */ 	lui	$t3,0x1
/*  f18e8f0:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f18e8f4:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e8f8:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f18e8fc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f18e900:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f18e904:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f18e908:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e90c:	240d2000 */ 	addiu	$t5,$zero,0x2000
/*  f18e910:	ad8d0004 */ 	sw	$t5,0x4($t4)
/*  f18e914:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f18e918:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e91c:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e920:	354a0903 */ 	ori	$t2,$t2,0x903
/*  f18e924:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e928:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e92c:	240b0c00 */ 	addiu	$t3,$zero,0xc00
/*  f18e930:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f18e934:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e938:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f18e93c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f18e940:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f18e944:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f18e948:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e94c:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f18e950:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f18e954:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f18e958:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f18e95c:	8fa200b8 */ 	lw	$v0,0xb8($sp)
/*  f18e960:	03e00008 */ 	jr	$ra
/*  f18e964:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

s32 teamGetIndex(s32 team)
{
	s32 index = 0;

	if (team & 1) {
		index = 0;
	} else if (team & 0x02) {
		index = 1;
	} else if (team & 0x04) {
		index = 2;
	} else if (team & 0x08) {
		index = 3;
	} else if (team & 0x10) {
		index = 4;
	} else if (team & 0x20) {
		index = 5;
	} else if (team & 0x40) {
		index = 6;
	} else if (team & 0x80) {
		index = 7;
	}

	return index;
}

GLOBAL_ASM(
glabel radarDrawDot
/*  f18e9ec:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f18e9f0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18e9f4:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18e9f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18e9fc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18ea00:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18ea04:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18ea08:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18ea0c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ea10:	afa700ec */ 	sw	$a3,0xec($sp)
/*  f18ea14:	00808025 */ 	or	$s0,$a0,$zero
/*  f18ea18:	00c09025 */ 	or	$s2,$a2,$zero
/*  f18ea1c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f18ea20:	c4ce0008 */ 	lwc1	$f14,0x8($a2)
/*  f18ea24:	0fc259d4 */ 	jal	func0f096750
/*  f18ea28:	c4cc0000 */ 	lwc1	$f12,0x0($a2)
/*  f18ea2c:	3c014334 */ 	lui	$at,0x4334
/*  f18ea30:	44818000 */ 	mtc1	$at,$f16
/*  f18ea34:	3c017f1c */ 	lui	$at,%hi(var7f1b8dd8)
/*  f18ea38:	c4268dd8 */ 	lwc1	$f6,%lo(var7f1b8dd8)($at)
/*  f18ea3c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f18ea40:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f18ea44:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f18ea48:	8eae0284 */ 	lw	$t6,0x284($s5)
/*  f18ea4c:	c5ca0144 */ 	lwc1	$f10,0x144($t6)
/*  f18ea50:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f18ea54:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f18ea58:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f18ea5c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f18ea60:	c64e0008 */ 	lwc1	$f14,0x8($s2)
/*  f18ea64:	c6420000 */ 	lwc1	$f2,0x0($s2)
/*  f18ea68:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f18ea6c:	00000000 */ 	nop
/*  f18ea70:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f18ea74:	0c012974 */ 	jal	sqrtf
/*  f18ea78:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f18ea7c:	3c014180 */ 	lui	$at,0x4180
/*  f18ea80:	44816000 */ 	mtc1	$at,$f12
/*  f18ea84:	3c017f1c */ 	lui	$at,%hi(var7f1b8ddc)
/*  f18ea88:	c42a8ddc */ 	lwc1	$f10,%lo(var7f1b8ddc)($at)
/*  f18ea8c:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f18ea90:	3c017f1c */ 	lui	$at,%hi(var7f1b8de0)
/*  f18ea94:	460a0382 */ 	mul.s	$f14,$f0,$f10
/*  f18ea98:	c7b200cc */ 	lwc1	$f18,0xcc($sp)
/*  f18ea9c:	460c703c */ 	c.lt.s	$f14,$f12
/*  f18eaa0:	00000000 */ 	nop
/*  f18eaa4:	45020004 */ 	bc1fl	.L0f18eab8
/*  f18eaa8:	46006386 */ 	mov.s	$f14,$f12
/*  f18eaac:	10000002 */ 	b	.L0f18eab8
/*  f18eab0:	00009825 */ 	or	$s3,$zero,$zero
/*  f18eab4:	46006386 */ 	mov.s	$f14,$f12
.L0f18eab8:
/*  f18eab8:	c4248de0 */ 	lwc1	$f4,%lo(var7f1b8de0)($at)
/*  f18eabc:	e7ae00d0 */ 	swc1	$f14,0xd0($sp)
/*  f18eac0:	46049302 */ 	mul.s	$f12,$f18,$f4
/*  f18eac4:	0c0068f7 */ 	jal	sinf
/*  f18eac8:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f18eacc:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18ead0:	3c19800b */ 	lui	$t9,%hi(var800acc70)
/*  f18ead4:	8f39cc70 */ 	lw	$t9,%lo(var800acc70)($t9)
/*  f18ead8:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f18eadc:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f18eae0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f18eae4:	44184000 */ 	mfc1	$t8,$f8
/*  f18eae8:	0c0068f4 */ 	jal	cosf
/*  f18eaec:	03198821 */ 	addu	$s1,$t8,$t9
/*  f18eaf0:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18eaf4:	8fac00f4 */ 	lw	$t4,0xf4($sp)
/*  f18eaf8:	3c0b800b */ 	lui	$t3,%hi(var800acc74)
/*  f18eafc:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f18eb00:	8d6bcc74 */ 	lw	$t3,%lo(var800acc74)($t3)
/*  f18eb04:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f18eb08:	440a9000 */ 	mfc1	$t2,$f18
/*  f18eb0c:	118001a8 */ 	beqz	$t4,.L0f18f1b0
/*  f18eb10:	014ba021 */ 	addu	$s4,$t2,$t3
/*  f18eb14:	8ead0284 */ 	lw	$t5,0x284($s5)
/*  f18eb18:	02002025 */ 	or	$a0,$s0,$zero
/*  f18eb1c:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18eb20:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f18eb24:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18eb28:	3c028008 */ 	lui	$v0,%hi(var80087cc0)
/*  f18eb2c:	16ce0086 */ 	bne	$s6,$t6,.L0f18ed48
/*  f18eb30:	00000000 */ 	nop
/*  f18eb34:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18eb38:	0fc54df7 */ 	jal	func0f1537dc
/*  f18eb3c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18eb40:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18eb44:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18eb48:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18eb4c:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18eb50:	268d0003 */ 	addiu	$t5,$s4,0x3
/*  f18eb54:	02b90019 */ 	multu	$s5,$t9
/*  f18eb58:	3c13f600 */ 	lui	$s3,0xf600
/*  f18eb5c:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18eb60:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18eb64:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18eb68:	26880002 */ 	addiu	$t0,$s4,0x2
/*  f18eb6c:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f18eb70:	00194080 */ 	sll	$t0,$t9,0x2
/*  f18eb74:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18eb78:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18eb7c:	00004812 */ 	mflo	$t1
/*  f18eb80:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f18eb84:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18eb88:	01736025 */ 	or	$t4,$t3,$s3
/*  f18eb8c:	018fc025 */ 	or	$t8,$t4,$t7
/*  f18eb90:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18eb94:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18eb98:	262f0002 */ 	addiu	$t7,$s1,0x2
/*  f18eb9c:	02ca0019 */ 	multu	$s6,$t2
/*  f18eba0:	00005812 */ 	mflo	$t3
/*  f18eba4:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18eba8:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f18ebac:	01c86025 */ 	or	$t4,$t6,$t0
/*  f18ebb0:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f18ebb4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ebb8:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f18ebbc:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f18ebc0:	01f80019 */ 	multu	$t7,$t8
/*  f18ebc4:	262ffffd */ 	addiu	$t7,$s1,-3
/*  f18ebc8:	0000c812 */ 	mflo	$t9
/*  f18ebcc:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ebd0:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ebd4:	01535825 */ 	or	$t3,$t2,$s3
/*  f18ebd8:	01686825 */ 	or	$t5,$t3,$t0
/*  f18ebdc:	ac4d0008 */ 	sw	$t5,0x8($v0)
/*  f18ebe0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ebe4:	01f80019 */ 	multu	$t7,$t8
/*  f18ebe8:	0000c812 */ 	mflo	$t9
/*  f18ebec:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ebf0:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ebf4:	01475825 */ 	or	$t3,$t2,$a3
/*  f18ebf8:	ac4b000c */ 	sw	$t3,0xc($v0)
/*  f18ebfc:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18ec00:	02ad0019 */ 	multu	$s5,$t5
/*  f18ec04:	00007012 */ 	mflo	$t6
/*  f18ec08:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ec0c:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18ec10:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18ec14:	0307c825 */ 	or	$t9,$t8,$a3
/*  f18ec18:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f18ec1c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ec20:	268efffe */ 	addiu	$t6,$s4,-2
/*  f18ec24:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ec28:	02c90019 */ 	multu	$s6,$t1
/*  f18ec2c:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f18ec30:	00005012 */ 	mflo	$t2
/*  f18ec34:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18ec38:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18ec3c:	01afc025 */ 	or	$t8,$t5,$t7
/*  f18ec40:	ac580014 */ 	sw	$t8,0x14($v0)
/*  f18ec44:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f18ec48:	0fc54e0e */ 	jal	func0f153838
/*  f18ec4c:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18ec50:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18ec54:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ec58:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ec5c:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18ec60:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ec64:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f18ec68:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18ec6c:	02290019 */ 	multu	$s1,$t1
/*  f18ec70:	2625ffff */ 	addiu	$a1,$s1,-1
/*  f18ec74:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18ec78:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f18ec7c:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f18ec80:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18ec84:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18ec88:	00005012 */ 	mflo	$t2
/*  f18ec8c:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18ec90:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18ec94:	01d36025 */ 	or	$t4,$t6,$s3
/*  f18ec98:	01886825 */ 	or	$t5,$t4,$t0
/*  f18ec9c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18eca0:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18eca4:	00b90019 */ 	multu	$a1,$t9
/*  f18eca8:	00004812 */ 	mflo	$t1
/*  f18ecac:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f18ecb0:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18ecb4:	01667025 */ 	or	$t6,$t3,$a2
/*  f18ecb8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18ecbc:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18ecc0:	00035080 */ 	sll	$t2,$v1,0x2
/*  f18ecc4:	01401825 */ 	or	$v1,$t2,$zero
/*  f18ecc8:	02ac0019 */ 	multu	$s5,$t4
/*  f18eccc:	00006812 */ 	mflo	$t5
/*  f18ecd0:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18ecd4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f18ecd8:	0313c825 */ 	or	$t9,$t8,$s3
/*  f18ecdc:	03264825 */ 	or	$t1,$t9,$a2
/*  f18ece0:	ac490008 */ 	sw	$t1,0x8($v0)
/*  f18ece4:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18ece8:	02cb0019 */ 	multu	$s6,$t3
/*  f18ecec:	00007012 */ 	mflo	$t6
/*  f18ecf0:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ecf4:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f18ecf8:	01aa7825 */ 	or	$t7,$t5,$t2
/*  f18ecfc:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18ed00:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ed04:	02380019 */ 	multu	$s1,$t8
/*  f18ed08:	0000c812 */ 	mflo	$t9
/*  f18ed0c:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ed10:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ed14:	01535825 */ 	or	$t3,$t2,$s3
/*  f18ed18:	01637025 */ 	or	$t6,$t3,$v1
/*  f18ed1c:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f18ed20:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18ed24:	00ac0019 */ 	multu	$a1,$t4
/*  f18ed28:	00006812 */ 	mflo	$t5
/*  f18ed2c:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18ed30:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f18ed34:	0307c825 */ 	or	$t9,$t8,$a3
/*  f18ed38:	0fc54e0e */ 	jal	func0f153838
/*  f18ed3c:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f18ed40:	100002c1 */ 	b	.L0f18f848
/*  f18ed44:	00408025 */ 	or	$s0,$v0,$zero
.L0f18ed48:
/*  f18ed48:	8c427cc0 */ 	lw	$v0,%lo(var80087cc0)($v0)
/*  f18ed4c:	3c01437a */ 	lui	$at,0x437a
/*  f18ed50:	1040006b */ 	beqz	$v0,.L0f18ef00
/*  f18ed54:	00000000 */ 	nop
/*  f18ed58:	44812000 */ 	mtc1	$at,$f4
/*  f18ed5c:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f18ed60:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ed64:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f18ed68:	4606203c */ 	c.lt.s	$f4,$f6
/*  f18ed6c:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18ed70:	45000063 */ 	bc1f	.L0f18ef00
/*  f18ed74:	00000000 */ 	nop
/*  f18ed78:	02699007 */ 	srav	$s2,$t1,$s3
/*  f18ed7c:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ed80:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18ed84:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18ed88:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18ed8c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18ed90:	262b0002 */ 	addiu	$t3,$s1,0x2
/*  f18ed94:	26990002 */ 	addiu	$t9,$s4,0x2
/*  f18ed98:	016e0019 */ 	multu	$t3,$t6
/*  f18ed9c:	3c13f600 */ 	lui	$s3,0xf600
/*  f18eda0:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18eda4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f18eda8:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18edac:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f18edb0:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f18edb4:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18edb8:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18edbc:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18edc0:	00006012 */ 	mflo	$t4
/*  f18edc4:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f18edc8:	000d7b80 */ 	sll	$t7,$t5,0xe
/*  f18edcc:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18edd0:	030a5825 */ 	or	$t3,$t8,$t2
/*  f18edd4:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18edd8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18eddc:	262dfffd */ 	addiu	$t5,$s1,-3
/*  f18ede0:	01af0019 */ 	multu	$t5,$t7
/*  f18ede4:	0000c812 */ 	mflo	$t9
/*  f18ede8:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18edec:	0009c380 */ 	sll	$t8,$t1,0xe
/*  f18edf0:	03075025 */ 	or	$t2,$t8,$a3
/*  f18edf4:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f18edf8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18edfc:	02ab0019 */ 	multu	$s5,$t3
/*  f18ee00:	00007012 */ 	mflo	$t6
/*  f18ee04:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ee08:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f18ee0c:	01b37825 */ 	or	$t7,$t5,$s3
/*  f18ee10:	01e7c825 */ 	or	$t9,$t7,$a3
/*  f18ee14:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f18ee18:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ee1c:	268efffe */ 	addiu	$t6,$s4,-2
/*  f18ee20:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ee24:	02c90019 */ 	multu	$s6,$t1
/*  f18ee28:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f18ee2c:	0000c012 */ 	mflo	$t8
/*  f18ee30:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18ee34:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18ee38:	016d7825 */ 	or	$t7,$t3,$t5
/*  f18ee3c:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18ee40:	0fc54e0e */ 	jal	func0f153838
/*  f18ee44:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18ee48:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18ee4c:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ee50:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ee54:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18ee58:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ee5c:	268b0001 */ 	addiu	$t3,$s4,0x1
/*  f18ee60:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18ee64:	02a90019 */ 	multu	$s5,$t1
/*  f18ee68:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f18ee6c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18ee70:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18ee74:	00034880 */ 	sll	$t1,$v1,0x2
/*  f18ee78:	01201825 */ 	or	$v1,$t1,$zero
/*  f18ee7c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18ee80:	0000c012 */ 	mflo	$t8
/*  f18ee84:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18ee88:	000a7380 */ 	sll	$t6,$t2,0xe
/*  f18ee8c:	01d36025 */ 	or	$t4,$t6,$s3
/*  f18ee90:	018fc825 */ 	or	$t9,$t4,$t7
/*  f18ee94:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18ee98:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ee9c:	02d80019 */ 	multu	$s6,$t8
/*  f18eea0:	00005012 */ 	mflo	$t2
/*  f18eea4:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18eea8:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18eeac:	01696825 */ 	or	$t5,$t3,$t1
/*  f18eeb0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18eeb4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18eeb8:	262effff */ 	addiu	$t6,$s1,-1
/*  f18eebc:	022c0019 */ 	multu	$s1,$t4
/*  f18eec0:	00007812 */ 	mflo	$t7
/*  f18eec4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18eec8:	00194b80 */ 	sll	$t1,$t9,0xe
/*  f18eecc:	0133c025 */ 	or	$t8,$t1,$s3
/*  f18eed0:	03035025 */ 	or	$t2,$t8,$v1
/*  f18eed4:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18eed8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18eedc:	01cb0019 */ 	multu	$t6,$t3
/*  f18eee0:	00006812 */ 	mflo	$t5
/*  f18eee4:	31ac03ff */ 	andi	$t4,$t5,0x3ff
/*  f18eee8:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18eeec:	01e7c825 */ 	or	$t9,$t7,$a3
/*  f18eef0:	0fc54e0e */ 	jal	func0f153838
/*  f18eef4:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f18eef8:	10000253 */ 	b	.L0f18f848
/*  f18eefc:	00408025 */ 	or	$s0,$v0,$zero
.L0f18ef00:
/*  f18ef00:	1040006a */ 	beqz	$v0,.L0f18f0ac
/*  f18ef04:	3c01c37a */ 	lui	$at,0xc37a
/*  f18ef08:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*  f18ef0c:	44815000 */ 	mtc1	$at,$f10
/*  f18ef10:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ef14:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f18ef18:	460a403c */ 	c.lt.s	$f8,$f10
/*  f18ef1c:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18ef20:	45000062 */ 	bc1f	.L0f18f0ac
/*  f18ef24:	02699007 */ 	srav	$s2,$t1,$s3
/*  f18ef28:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ef2c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18ef30:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18ef34:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18ef38:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18ef3c:	262b0002 */ 	addiu	$t3,$s1,0x2
/*  f18ef40:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18ef44:	016d0019 */ 	multu	$t3,$t5
/*  f18ef48:	3c13f600 */ 	lui	$s3,0xf600
/*  f18ef4c:	30ca03ff */ 	andi	$t2,$a2,0x3ff
/*  f18ef50:	000a3080 */ 	sll	$a2,$t2,0x2
/*  f18ef54:	262afffd */ 	addiu	$t2,$s1,-3
/*  f18ef58:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18ef5c:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18ef60:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18ef64:	00006012 */ 	mflo	$t4
/*  f18ef68:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18ef6c:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18ef70:	03334825 */ 	or	$t1,$t9,$s3
/*  f18ef74:	0126c025 */ 	or	$t8,$t1,$a2
/*  f18ef78:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18ef7c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18ef80:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18ef84:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18ef88:	014e0019 */ 	multu	$t2,$t6
/*  f18ef8c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f18ef90:	26990002 */ 	addiu	$t9,$s4,0x2
/*  f18ef94:	00005812 */ 	mflo	$t3
/*  f18ef98:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18ef9c:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f18efa0:	0189c025 */ 	or	$t8,$t4,$t1
/*  f18efa4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18efa8:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18efac:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f18efb0:	000c4880 */ 	sll	$t1,$t4,0x2
/*  f18efb4:	02aa0019 */ 	multu	$s5,$t2
/*  f18efb8:	00007012 */ 	mflo	$t6
/*  f18efbc:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18efc0:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18efc4:	01b37825 */ 	or	$t7,$t5,$s3
/*  f18efc8:	01e9c025 */ 	or	$t8,$t7,$t1
/*  f18efcc:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18efd0:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18efd4:	02ca0019 */ 	multu	$s6,$t2
/*  f18efd8:	00007012 */ 	mflo	$t6
/*  f18efdc:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18efe0:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18efe4:	01a6c825 */ 	or	$t9,$t5,$a2
/*  f18efe8:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f18efec:	0fc54e0e */ 	jal	func0f153838
/*  f18eff0:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18eff4:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f18eff8:	00402025 */ 	or	$a0,$v0,$zero
/*  f18effc:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f000:	024c2821 */ 	addu	$a1,$s2,$t4
/*  f18f004:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f008:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f00c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18f010:	02a90019 */ 	multu	$s5,$t1
/*  f18f014:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f18f018:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18f01c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f020:	0000c012 */ 	mflo	$t8
/*  f18f024:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f028:	000a7380 */ 	sll	$t6,$t2,0xe
/*  f18f02c:	01d35825 */ 	or	$t3,$t6,$s3
/*  f18f030:	016f6825 */ 	or	$t5,$t3,$t7
/*  f18f034:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18f038:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f03c:	2698ffff */ 	addiu	$t8,$s4,-1
/*  f18f040:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f044:	02d90019 */ 	multu	$s6,$t9
/*  f18f048:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f18f04c:	00006012 */ 	mflo	$t4
/*  f18f050:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18f054:	000f4b80 */ 	sll	$t1,$t7,0xe
/*  f18f058:	012e5825 */ 	or	$t3,$t1,$t6
/*  f18f05c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f18f060:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f064:	2629ffff */ 	addiu	$t1,$s1,-1
/*  f18f068:	022d0019 */ 	multu	$s1,$t5
/*  f18f06c:	0000c812 */ 	mflo	$t9
/*  f18f070:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f18f074:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18f078:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18f07c:	03065025 */ 	or	$t2,$t8,$a2
/*  f18f080:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18f084:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f088:	012e0019 */ 	multu	$t1,$t6
/*  f18f08c:	00005812 */ 	mflo	$t3
/*  f18f090:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f094:	000dcb80 */ 	sll	$t9,$t5,0xe
/*  f18f098:	03236025 */ 	or	$t4,$t9,$v1
/*  f18f09c:	0fc54e0e */ 	jal	func0f153838
/*  f18f0a0:	ac4c000c */ 	sw	$t4,0xc($v0)
/*  f18f0a4:	100001e8 */ 	b	.L0f18f848
/*  f18f0a8:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f0ac:
/*  f18f0ac:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18f0b0:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f0b4:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f0b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f0bc:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f0c0:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18f0c4:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f0c8:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f0cc:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f0d0:	262a0002 */ 	addiu	$t2,$s1,0x2
/*  f18f0d4:	268c0002 */ 	addiu	$t4,$s4,0x2
/*  f18f0d8:	01490019 */ 	multu	$t2,$t1
/*  f18f0dc:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f0e0:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18f0e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f18f0e8:	2629fffe */ 	addiu	$t1,$s1,-2
/*  f18f0ec:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f0f0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f0f4:	00007012 */ 	mflo	$t6
/*  f18f0f8:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18f0fc:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18f100:	01b3c825 */ 	or	$t9,$t5,$s3
/*  f18f104:	03385025 */ 	or	$t2,$t9,$t8
/*  f18f108:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f18f10c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f110:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18f114:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f18f118:	012e0019 */ 	multu	$t1,$t6
/*  f18f11c:	00005812 */ 	mflo	$t3
/*  f18f120:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f124:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f18f128:	01985025 */ 	or	$t2,$t4,$t8
/*  f18f12c:	0fc54e0e */ 	jal	func0f153838
/*  f18f130:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f18f134:	8fa900f0 */ 	lw	$t1,0xf0($sp)
/*  f18f138:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f13c:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f140:	02492821 */ 	addu	$a1,$s2,$t1
/*  f18f144:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f148:	262e0001 */ 	addiu	$t6,$s1,0x1
/*  f18f14c:	26980001 */ 	addiu	$t8,$s4,0x1
/*  f18f150:	01cb0019 */ 	multu	$t6,$t3
/*  f18f154:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f158:	000a4880 */ 	sll	$t1,$t2,0x2
/*  f18f15c:	262bffff */ 	addiu	$t3,$s1,-1
/*  f18f160:	268affff */ 	addiu	$t2,$s4,-1
/*  f18f164:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f168:	00006812 */ 	mflo	$t5
/*  f18f16c:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18f170:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f174:	03336025 */ 	or	$t4,$t9,$s3
/*  f18f178:	01897025 */ 	or	$t6,$t4,$t1
/*  f18f17c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f18f180:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f184:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f188:	000c4880 */ 	sll	$t1,$t4,0x2
/*  f18f18c:	016d0019 */ 	multu	$t3,$t5
/*  f18f190:	00007812 */ 	mflo	$t7
/*  f18f194:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18f198:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f18f19c:	03097025 */ 	or	$t6,$t8,$t1
/*  f18f1a0:	0fc54e0e */ 	jal	func0f153838
/*  f18f1a4:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18f1a8:	100001a7 */ 	b	.L0f18f848
/*  f18f1ac:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f1b0:
/*  f18f1b0:	8eab0284 */ 	lw	$t3,0x284($s5)
/*  f18f1b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f1b8:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f1bc:	8d6d00bc */ 	lw	$t5,0xbc($t3)
/*  f18f1c0:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f1c4:	3c028008 */ 	lui	$v0,%hi(var80087cc0)
/*  f18f1c8:	16cd0086 */ 	bne	$s6,$t5,.L0f18f3e4
/*  f18f1cc:	00000000 */ 	nop
/*  f18f1d0:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f1d4:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f1d8:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f1dc:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f1e0:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f1e4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f1e8:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f1ec:	268b0003 */ 	addiu	$t3,$s4,0x3
/*  f18f1f0:	02aa0019 */ 	multu	$s5,$t2
/*  f18f1f4:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f1f8:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f1fc:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f18f200:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f204:	26880002 */ 	addiu	$t0,$s4,0x2
/*  f18f208:	310a03ff */ 	andi	$t2,$t0,0x3ff
/*  f18f20c:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f18f210:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18f214:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18f218:	00006012 */ 	mflo	$t4
/*  f18f21c:	319803ff */ 	andi	$t8,$t4,0x3ff
/*  f18f220:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f224:	01337025 */ 	or	$t6,$t1,$s3
/*  f18f228:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f18f22c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18f230:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f234:	262f0002 */ 	addiu	$t7,$s1,0x2
/*  f18f238:	02d80019 */ 	multu	$s6,$t8
/*  f18f23c:	00004812 */ 	mflo	$t1
/*  f18f240:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f244:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18f248:	01a87025 */ 	or	$t6,$t5,$t0
/*  f18f24c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18f250:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f254:	30ed03ff */ 	andi	$t5,$a3,0x3ff
/*  f18f258:	000d3880 */ 	sll	$a3,$t5,0x2
/*  f18f25c:	01f90019 */ 	multu	$t7,$t9
/*  f18f260:	262ffffd */ 	addiu	$t7,$s1,-3
/*  f18f264:	00005012 */ 	mflo	$t2
/*  f18f268:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f26c:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f270:	03134825 */ 	or	$t1,$t8,$s3
/*  f18f274:	01285825 */ 	or	$t3,$t1,$t0
/*  f18f278:	ac4b0008 */ 	sw	$t3,0x8($v0)
/*  f18f27c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f280:	01f90019 */ 	multu	$t7,$t9
/*  f18f284:	00005012 */ 	mflo	$t2
/*  f18f288:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f28c:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f290:	03074825 */ 	or	$t1,$t8,$a3
/*  f18f294:	ac49000c */ 	sw	$t1,0xc($v0)
/*  f18f298:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f29c:	02ab0019 */ 	multu	$s5,$t3
/*  f18f2a0:	00006812 */ 	mflo	$t5
/*  f18f2a4:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f2a8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f2ac:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f2b0:	03275025 */ 	or	$t2,$t9,$a3
/*  f18f2b4:	ac4a0010 */ 	sw	$t2,0x10($v0)
/*  f18f2b8:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f2bc:	268dfffe */ 	addiu	$t5,$s4,-2
/*  f18f2c0:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f2c4:	02cc0019 */ 	multu	$s6,$t4
/*  f18f2c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18f2cc:	0000c012 */ 	mflo	$t8
/*  f18f2d0:	330903ff */ 	andi	$t1,$t8,0x3ff
/*  f18f2d4:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f2d8:	016fc825 */ 	or	$t9,$t3,$t7
/*  f18f2dc:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f18f2e0:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f18f2e4:	0fc54e0e */ 	jal	func0f153838
/*  f18f2e8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18f2ec:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18f2f0:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f2f4:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f2f8:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18f2fc:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f300:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f18f304:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18f308:	022c0019 */ 	multu	$s1,$t4
/*  f18f30c:	2625ffff */ 	addiu	$a1,$s1,-1
/*  f18f310:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18f314:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f18f318:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f18f31c:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f320:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18f324:	0000c012 */ 	mflo	$t8
/*  f18f328:	330903ff */ 	andi	$t1,$t8,0x3ff
/*  f18f32c:	00096b80 */ 	sll	$t5,$t1,0xe
/*  f18f330:	01b37025 */ 	or	$t6,$t5,$s3
/*  f18f334:	01c85825 */ 	or	$t3,$t6,$t0
/*  f18f338:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18f33c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f340:	00aa0019 */ 	multu	$a1,$t2
/*  f18f344:	00006012 */ 	mflo	$t4
/*  f18f348:	319803ff */ 	andi	$t8,$t4,0x3ff
/*  f18f34c:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f350:	01266825 */ 	or	$t5,$t1,$a2
/*  f18f354:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18f358:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f35c:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f18f360:	03001825 */ 	or	$v1,$t8,$zero
/*  f18f364:	02ae0019 */ 	multu	$s5,$t6
/*  f18f368:	00005812 */ 	mflo	$t3
/*  f18f36c:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f370:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f374:	03335025 */ 	or	$t2,$t9,$s3
/*  f18f378:	01466025 */ 	or	$t4,$t2,$a2
/*  f18f37c:	ac4c0008 */ 	sw	$t4,0x8($v0)
/*  f18f380:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f384:	02c90019 */ 	multu	$s6,$t1
/*  f18f388:	00006812 */ 	mflo	$t5
/*  f18f38c:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f390:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18f394:	01787825 */ 	or	$t7,$t3,$t8
/*  f18f398:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18f39c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f3a0:	02390019 */ 	multu	$s1,$t9
/*  f18f3a4:	00005012 */ 	mflo	$t2
/*  f18f3a8:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f3ac:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f3b0:	03134825 */ 	or	$t1,$t8,$s3
/*  f18f3b4:	01236825 */ 	or	$t5,$t1,$v1
/*  f18f3b8:	ac4d0010 */ 	sw	$t5,0x10($v0)
/*  f18f3bc:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f3c0:	00ae0019 */ 	multu	$a1,$t6
/*  f18f3c4:	00005812 */ 	mflo	$t3
/*  f18f3c8:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f3cc:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f3d0:	03275025 */ 	or	$t2,$t9,$a3
/*  f18f3d4:	0fc54e0e */ 	jal	func0f153838
/*  f18f3d8:	ac4a0014 */ 	sw	$t2,0x14($v0)
/*  f18f3dc:	1000011a */ 	b	.L0f18f848
/*  f18f3e0:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f3e4:
/*  f18f3e4:	8c427cc0 */ 	lw	$v0,%lo(var80087cc0)($v0)
/*  f18f3e8:	3c01437a */ 	lui	$at,0x437a
/*  f18f3ec:	1040006b */ 	beqz	$v0,.L0f18f59c
/*  f18f3f0:	00000000 */ 	nop
/*  f18f3f4:	44819000 */ 	mtc1	$at,$f18
/*  f18f3f8:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f18f3fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f400:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f18f404:	4604903c */ 	c.lt.s	$f18,$f4
/*  f18f408:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f18f40c:	45000063 */ 	bc1f	.L0f18f59c
/*  f18f410:	00000000 */ 	nop
/*  f18f414:	026c9007 */ 	srav	$s2,$t4,$s3
/*  f18f418:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f41c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18f420:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f424:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f428:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f42c:	26290002 */ 	addiu	$t1,$s1,0x2
/*  f18f430:	268a0002 */ 	addiu	$t2,$s4,0x2
/*  f18f434:	012d0019 */ 	multu	$t1,$t5
/*  f18f438:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f43c:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f440:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f18f444:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18f448:	30ed03ff */ 	andi	$t5,$a3,0x3ff
/*  f18f44c:	000d3880 */ 	sll	$a3,$t5,0x2
/*  f18f450:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f454:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f458:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f45c:	00007012 */ 	mflo	$t6
/*  f18f460:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18f464:	000b7b80 */ 	sll	$t7,$t3,0xe
/*  f18f468:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f46c:	03384825 */ 	or	$t1,$t9,$t8
/*  f18f470:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f18f474:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18f478:	262bfffd */ 	addiu	$t3,$s1,-3
/*  f18f47c:	016f0019 */ 	multu	$t3,$t7
/*  f18f480:	00005012 */ 	mflo	$t2
/*  f18f484:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f488:	000ccb80 */ 	sll	$t9,$t4,0xe
/*  f18f48c:	0327c025 */ 	or	$t8,$t9,$a3
/*  f18f490:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18f494:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f498:	02a90019 */ 	multu	$s5,$t1
/*  f18f49c:	00006812 */ 	mflo	$t5
/*  f18f4a0:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f4a4:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18f4a8:	01737825 */ 	or	$t7,$t3,$s3
/*  f18f4ac:	01e75025 */ 	or	$t2,$t7,$a3
/*  f18f4b0:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18f4b4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f4b8:	268dfffe */ 	addiu	$t5,$s4,-2
/*  f18f4bc:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f4c0:	02cc0019 */ 	multu	$s6,$t4
/*  f18f4c4:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f18f4c8:	0000c812 */ 	mflo	$t9
/*  f18f4cc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f4d0:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f4d4:	012b7825 */ 	or	$t7,$t1,$t3
/*  f18f4d8:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18f4dc:	0fc54e0e */ 	jal	func0f153838
/*  f18f4e0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18f4e4:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18f4e8:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f4ec:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f4f0:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18f4f4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f4f8:	26890001 */ 	addiu	$t1,$s4,0x1
/*  f18f4fc:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f500:	02ac0019 */ 	multu	$s5,$t4
/*  f18f504:	000b7880 */ 	sll	$t7,$t3,0x2
/*  f18f508:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18f50c:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f510:	00036080 */ 	sll	$t4,$v1,0x2
/*  f18f514:	01801825 */ 	or	$v1,$t4,$zero
/*  f18f518:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f51c:	0000c812 */ 	mflo	$t9
/*  f18f520:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f524:	00186b80 */ 	sll	$t5,$t8,0xe
/*  f18f528:	01b37025 */ 	or	$t6,$t5,$s3
/*  f18f52c:	01cf5025 */ 	or	$t2,$t6,$t7
/*  f18f530:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f18f534:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f538:	02d90019 */ 	multu	$s6,$t9
/*  f18f53c:	0000c012 */ 	mflo	$t8
/*  f18f540:	330d03ff */ 	andi	$t5,$t8,0x3ff
/*  f18f544:	000d4b80 */ 	sll	$t1,$t5,0xe
/*  f18f548:	012c5825 */ 	or	$t3,$t1,$t4
/*  f18f54c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f18f550:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f554:	262dffff */ 	addiu	$t5,$s1,-1
/*  f18f558:	022e0019 */ 	multu	$s1,$t6
/*  f18f55c:	00007812 */ 	mflo	$t7
/*  f18f560:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f564:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f18f568:	0193c825 */ 	or	$t9,$t4,$s3
/*  f18f56c:	0323c025 */ 	or	$t8,$t9,$v1
/*  f18f570:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18f574:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f578:	01a90019 */ 	multu	$t5,$t1
/*  f18f57c:	00005812 */ 	mflo	$t3
/*  f18f580:	316e03ff */ 	andi	$t6,$t3,0x3ff
/*  f18f584:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f588:	01e75025 */ 	or	$t2,$t7,$a3
/*  f18f58c:	0fc54e0e */ 	jal	func0f153838
/*  f18f590:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f18f594:	100000ac */ 	b	.L0f18f848
/*  f18f598:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f59c:
/*  f18f59c:	1040006a */ 	beqz	$v0,.L0f18f748
/*  f18f5a0:	3c01c37a */ 	lui	$at,0xc37a
/*  f18f5a4:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f18f5a8:	44814000 */ 	mtc1	$at,$f8
/*  f18f5ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f5b0:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f18f5b4:	4608303c */ 	c.lt.s	$f6,$f8
/*  f18f5b8:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f5bc:	45000062 */ 	bc1f	.L0f18f748
/*  f18f5c0:	026c9007 */ 	srav	$s2,$t4,$s3
/*  f18f5c4:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f5c8:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f5cc:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f5d0:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f5d4:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f5d8:	26290002 */ 	addiu	$t1,$s1,0x2
/*  f18f5dc:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18f5e0:	012b0019 */ 	multu	$t1,$t3
/*  f18f5e4:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f5e8:	30d803ff */ 	andi	$t8,$a2,0x3ff
/*  f18f5ec:	00183080 */ 	sll	$a2,$t8,0x2
/*  f18f5f0:	2638fffd */ 	addiu	$t8,$s1,-3
/*  f18f5f4:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f5f8:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f5fc:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f600:	00007012 */ 	mflo	$t6
/*  f18f604:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f608:	000f5380 */ 	sll	$t2,$t7,0xe
/*  f18f60c:	01536025 */ 	or	$t4,$t2,$s3
/*  f18f610:	0186c825 */ 	or	$t9,$t4,$a2
/*  f18f614:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18f618:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f61c:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f620:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f624:	030d0019 */ 	multu	$t8,$t5
/*  f18f628:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f18f62c:	268a0002 */ 	addiu	$t2,$s4,0x2
/*  f18f630:	00004812 */ 	mflo	$t1
/*  f18f634:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f638:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18f63c:	01ccc825 */ 	or	$t9,$t6,$t4
/*  f18f640:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f18f644:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f648:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18f64c:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f18f650:	02b80019 */ 	multu	$s5,$t8
/*  f18f654:	00006812 */ 	mflo	$t5
/*  f18f658:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f65c:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f660:	01737825 */ 	or	$t7,$t3,$s3
/*  f18f664:	01ecc825 */ 	or	$t9,$t7,$t4
/*  f18f668:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f18f66c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f670:	02d80019 */ 	multu	$s6,$t8
/*  f18f674:	00006812 */ 	mflo	$t5
/*  f18f678:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f67c:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f680:	01665025 */ 	or	$t2,$t3,$a2
/*  f18f684:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f18f688:	0fc54e0e */ 	jal	func0f153838
/*  f18f68c:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18f690:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f18f694:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f698:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f69c:	024e2821 */ 	addu	$a1,$s2,$t6
/*  f18f6a0:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f6a4:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f6a8:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18f6ac:	02ac0019 */ 	multu	$s5,$t4
/*  f18f6b0:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f18f6b4:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18f6b8:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f6bc:	0000c812 */ 	mflo	$t9
/*  f18f6c0:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f6c4:	00186b80 */ 	sll	$t5,$t8,0xe
/*  f18f6c8:	01b34825 */ 	or	$t1,$t5,$s3
/*  f18f6cc:	012f5825 */ 	or	$t3,$t1,$t7
/*  f18f6d0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18f6d4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f6d8:	2699ffff */ 	addiu	$t9,$s4,-1
/*  f18f6dc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f6e0:	02ca0019 */ 	multu	$s6,$t2
/*  f18f6e4:	00186880 */ 	sll	$t5,$t8,0x2
/*  f18f6e8:	00007012 */ 	mflo	$t6
/*  f18f6ec:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f6f0:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f18f6f4:	018d4825 */ 	or	$t1,$t4,$t5
/*  f18f6f8:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f18f6fc:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f700:	262cffff */ 	addiu	$t4,$s1,-1
/*  f18f704:	022b0019 */ 	multu	$s1,$t3
/*  f18f708:	00005012 */ 	mflo	$t2
/*  f18f70c:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18f710:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f714:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f718:	0326c025 */ 	or	$t8,$t9,$a2
/*  f18f71c:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18f720:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f724:	018d0019 */ 	multu	$t4,$t5
/*  f18f728:	00004812 */ 	mflo	$t1
/*  f18f72c:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f730:	000b5380 */ 	sll	$t2,$t3,0xe
/*  f18f734:	01437025 */ 	or	$t6,$t2,$v1
/*  f18f738:	0fc54e0e */ 	jal	func0f153838
/*  f18f73c:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f18f740:	10000041 */ 	b	.L0f18f848
/*  f18f744:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f748:
/*  f18f748:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f74c:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f750:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f754:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f758:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f75c:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f760:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f764:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f768:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f76c:	26380002 */ 	addiu	$t8,$s1,0x2
/*  f18f770:	268e0002 */ 	addiu	$t6,$s4,0x2
/*  f18f774:	030c0019 */ 	multu	$t8,$t4
/*  f18f778:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f77c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f780:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18f784:	262cfffe */ 	addiu	$t4,$s1,-2
/*  f18f788:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f78c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f790:	00006812 */ 	mflo	$t5
/*  f18f794:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f798:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f79c:	01735025 */ 	or	$t2,$t3,$s3
/*  f18f7a0:	0159c025 */ 	or	$t8,$t2,$t9
/*  f18f7a4:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18f7a8:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f7ac:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f7b0:	000ac880 */ 	sll	$t9,$t2,0x2
/*  f18f7b4:	018d0019 */ 	multu	$t4,$t5
/*  f18f7b8:	00004812 */ 	mflo	$t1
/*  f18f7bc:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f7c0:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18f7c4:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f18f7c8:	0fc54e0e */ 	jal	func0f153838
/*  f18f7cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18f7d0:	8fac00ec */ 	lw	$t4,0xec($sp)
/*  f18f7d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f7d8:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f7dc:	024c2821 */ 	addu	$a1,$s2,$t4
/*  f18f7e0:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f7e4:	262d0001 */ 	addiu	$t5,$s1,0x1
/*  f18f7e8:	26990001 */ 	addiu	$t9,$s4,0x1
/*  f18f7ec:	01a90019 */ 	multu	$t5,$t1
/*  f18f7f0:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f7f4:	00186080 */ 	sll	$t4,$t8,0x2
/*  f18f7f8:	2629ffff */ 	addiu	$t1,$s1,-1
/*  f18f7fc:	2698ffff */ 	addiu	$t8,$s4,-1
/*  f18f800:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f804:	00005812 */ 	mflo	$t3
/*  f18f808:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f80c:	000f5380 */ 	sll	$t2,$t7,0xe
/*  f18f810:	01537025 */ 	or	$t6,$t2,$s3
/*  f18f814:	01cc6825 */ 	or	$t5,$t6,$t4
/*  f18f818:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18f81c:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f820:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f18f824:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f18f828:	012b0019 */ 	multu	$t1,$t3
/*  f18f82c:	00007812 */ 	mflo	$t7
/*  f18f830:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f834:	000acb80 */ 	sll	$t9,$t2,0xe
/*  f18f838:	032c6825 */ 	or	$t5,$t9,$t4
/*  f18f83c:	0fc54e0e */ 	jal	func0f153838
/*  f18f840:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18f844:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f848:
/*  f18f848:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18f84c:	02001025 */ 	or	$v0,$s0,$zero
/*  f18f850:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18f854:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18f858:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18f85c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18f860:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18f864:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18f868:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18f86c:	03e00008 */ 	jr	$ra
/*  f18f870:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);

GLOBAL_ASM(
glabel func0f18f874
/*  f18f874:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f18f878:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f18f87c:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f18f880:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f18f884:	8e58006c */ 	lw	$t8,0x6c($s2)
/*  f18f888:	3c0e800b */ 	lui	$t6,%hi(var800ab5ac)
/*  f18f88c:	8dceb5ac */ 	lw	$t6,%lo(var800ab5ac)($t6)
/*  f18f890:	8e4f028c */ 	lw	$t7,0x28c($s2)
/*  f18f894:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18f898:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f18f89c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f18f8a0:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f18f8a4:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f18f8a8:	13000003 */ 	beqz	$t8,.L0f18f8b8
/*  f18f8ac:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f18f8b0:	10000002 */ 	b	.L0f18f8bc
/*  f18f8b4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18f8b8:
/*  f18f8b8:	00002825 */ 	or	$a1,$zero,$zero
.L0f18f8bc:
/*  f18f8bc:	8e590068 */ 	lw	$t9,0x68($s2)
/*  f18f8c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f18f8c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f18f8c8:	13200003 */ 	beqz	$t9,.L0f18f8d8
/*  f18f8cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f18f8d0:	10000001 */ 	b	.L0f18f8d8
/*  f18f8d4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f18f8d8:
/*  f18f8d8:	8e4a0064 */ 	lw	$t2,0x64($s2)
/*  f18f8dc:	11400003 */ 	beqz	$t2,.L0f18f8ec
/*  f18f8e0:	00000000 */ 	nop
/*  f18f8e4:	10000001 */ 	b	.L0f18f8ec
/*  f18f8e8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18f8ec:
/*  f18f8ec:	8e4b0070 */ 	lw	$t3,0x70($s2)
/*  f18f8f0:	11600003 */ 	beqz	$t3,.L0f18f900
/*  f18f8f4:	00000000 */ 	nop
/*  f18f8f8:	10000001 */ 	b	.L0f18f900
/*  f18f8fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18f900:
/*  f18f900:	8e4e0314 */ 	lw	$t6,0x314($s2)
/*  f18f904:	00446021 */ 	addu	$t4,$v0,$a0
/*  f18f908:	01836821 */ 	addu	$t5,$t4,$v1
/*  f18f90c:	01a53021 */ 	addu	$a2,$t5,$a1
/*  f18f910:	11c0001a */ 	beqz	$t6,.L0f18f97c
/*  f18f914:	afa6007c */ 	sw	$a2,0x7c($sp)
/*  f18f918:	8e4f0318 */ 	lw	$t7,0x318($s2)
/*  f18f91c:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0xc)
/*  f18f920:	51e00008 */ 	beqzl	$t7,.L0f18f944
/*  f18f924:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f18f928:	8f18cb94 */ 	lw	$t8,%lo(g_MpSetup+0xc)($t8)
/*  f18f92c:	33190004 */ 	andi	$t9,$t8,0x4
/*  f18f930:	53200004 */ 	beqzl	$t9,.L0f18f944
/*  f18f934:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f18f938:	100001c3 */ 	b	.L0f190048
/*  f18f93c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f18f940:	8e4a0288 */ 	lw	$t2,0x288($s2)
.L0f18f944:
/*  f18f944:	3c0d800b */ 	lui	$t5,%hi(g_MpPlayers+0x14)
/*  f18f948:	8d4b0070 */ 	lw	$t3,0x70($t2)
/*  f18f94c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f18f950:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f18f954:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f18f958:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f18f95c:	8dadc7cc */ 	lw	$t5,%lo(g_MpPlayers+0x14)($t5)
/*  f18f960:	31ae0004 */ 	andi	$t6,$t5,0x4
/*  f18f964:	15c00003 */ 	bnez	$t6,.L0f18f974
/*  f18f968:	00000000 */ 	nop
/*  f18f96c:	100001b6 */ 	b	.L0f190048
/*  f18f970:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f18f974:
/*  f18f974:	10000012 */ 	b	.L0f18f9c0
/*  f18f978:	8e480284 */ 	lw	$t0,0x284($s2)
.L0f18f97c:
/*  f18f97c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18f980:	3c0c800a */ 	lui	$t4,%hi(g_MissionConfig+0x3)
/*  f18f984:	8d181c54 */ 	lw	$t8,0x1c54($t0)
/*  f18f988:	8d0f00c4 */ 	lw	$t7,0xc4($t0)
/*  f18f98c:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f18f990:	01f95024 */ 	and	$t2,$t7,$t9
/*  f18f994:	314b0010 */ 	andi	$t3,$t2,0x10
/*  f18f998:	5560000a */ 	bnezl	$t3,.L0f18f9c4
/*  f18f99c:	8d18192c */ 	lw	$t8,0x192c($t0)
/*  f18f9a0:	818ddfeb */ 	lb	$t5,%lo(g_MissionConfig+0x3)($t4)
/*  f18f9a4:	05a10004 */ 	bgez	$t5,.L0f18f9b8
/*  f18f9a8:	00000000 */ 	nop
/*  f18f9ac:	8e4e0448 */ 	lw	$t6,0x448($s2)
/*  f18f9b0:	55c00004 */ 	bnezl	$t6,.L0f18f9c4
/*  f18f9b4:	8d18192c */ 	lw	$t8,0x192c($t0)
.L0f18f9b8:
/*  f18f9b8:	100001a3 */ 	b	.L0f190048
/*  f18f9bc:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f18f9c0:
/*  f18f9c0:	8d18192c */ 	lw	$t8,0x192c($t0)
.L0f18f9c4:
/*  f18f9c4:	17000005 */ 	bnez	$t8,.L0f18f9dc
/*  f18f9c8:	00000000 */ 	nop
/*  f18f9cc:	8d0f00d8 */ 	lw	$t7,0xd8($t0)
/*  f18f9d0:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f18f9d4:	11e00003 */ 	beqz	$t7,.L0f18f9e4
/*  f18f9d8:	00000000 */ 	nop
.L0f18f9dc:
/*  f18f9dc:	1000019a */ 	b	.L0f190048
/*  f18f9e0:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f18f9e4:
/*  f18f9e4:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f18f9e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18f9ec:	14590004 */ 	bne	$v0,$t9,.L0f18fa00
/*  f18f9f0:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f18f9f4:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f18f9f8:	10000003 */ 	b	.L0f18fa08
/*  f18f9fc:	ac2afac0 */ 	sw	$t2,%lo(g_ScreenWidthMultiplier)($at)
.L0f18fa00:
/*  f18fa00:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f18fa04:	ac22fac0 */ 	sw	$v0,%lo(g_ScreenWidthMultiplier)($at)
.L0f18fa08:
/*  f18fa08:	0c002f40 */ 	jal	viGetViewLeft
/*  f18fa0c:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18fa10:	00028400 */ 	sll	$s0,$v0,0x10
/*  f18fa14:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f18fa18:	0c002f22 */ 	jal	viGetViewX
/*  f18fa1c:	01608025 */ 	or	$s0,$t3,$zero
/*  f18fa20:	3c0d8008 */ 	lui	$t5,%hi(g_ScreenWidthMultiplier)
/*  f18fa24:	8dadfac0 */ 	lw	$t5,%lo(g_ScreenWidthMultiplier)($t5)
/*  f18fa28:	00506021 */ 	addu	$t4,$v0,$s0
/*  f18fa2c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fa30:	018d001a */ 	div	$zero,$t4,$t5
/*  f18fa34:	00007012 */ 	mflo	$t6
/*  f18fa38:	3c11800b */ 	lui	$s1,%hi(var800acc70)
/*  f18fa3c:	2631cc70 */ 	addiu	$s1,$s1,%lo(var800acc70)
/*  f18fa40:	15a00002 */ 	bnez	$t5,.L0f18fa4c
/*  f18fa44:	00000000 */ 	nop
/*  f18fa48:	0007000d */ 	break	0x7
.L0f18fa4c:
/*  f18fa4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f18fa50:	15a10004 */ 	bne	$t5,$at,.L0f18fa64
/*  f18fa54:	3c018000 */ 	lui	$at,0x8000
/*  f18fa58:	15810002 */ 	bne	$t4,$at,.L0f18fa64
/*  f18fa5c:	00000000 */ 	nop
/*  f18fa60:	0006000d */ 	break	0x6
.L0f18fa64:
/*  f18fa64:	25d8ffd7 */ 	addiu	$t8,$t6,-41
/*  f18fa68:	24010002 */ 	addiu	$at,$zero,0x2
/*  f18fa6c:	15e1001d */ 	bne	$t7,$at,.L0f18fae4
/*  f18fa70:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f18fa74:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f18fa78:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f18fa7c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fa80:	50410008 */ 	beql	$v0,$at,.L0f18faa4
/*  f18fa84:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f18fa88:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f18fa8c:	00000000 */ 	nop
/*  f18fa90:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fa94:	1441000f */ 	bne	$v0,$at,.L0f18fad4
/*  f18fa98:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f18fa9c:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f18faa0:	8fb90078 */ 	lw	$t9,0x78($sp)
.L0f18faa4:
/*  f18faa4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18faa8:	17200004 */ 	bnez	$t9,.L0f18fabc
/*  f18faac:	00000000 */ 	nop
/*  f18fab0:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f18fab4:	254b0010 */ 	addiu	$t3,$t2,0x10
/*  f18fab8:	ae2b0000 */ 	sw	$t3,0x0($s1)
.L0f18fabc:
/*  f18fabc:	14410017 */ 	bne	$v0,$at,.L0f18fb1c
/*  f18fac0:	00000000 */ 	nop
/*  f18fac4:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f18fac8:	258dfffc */ 	addiu	$t5,$t4,-4
/*  f18facc:	10000013 */ 	b	.L0f18fb1c
/*  f18fad0:	ae2d0000 */ 	sw	$t5,0x0($s1)
.L0f18fad4:
/*  f18fad4:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f18fad8:	25d8fff9 */ 	addiu	$t8,$t6,-7
/*  f18fadc:	1000000f */ 	b	.L0f18fb1c
/*  f18fae0:	ae380000 */ 	sw	$t8,0x0($s1)
.L0f18fae4:
/*  f18fae4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fae8:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f18faec:	29e10003 */ 	slti	$at,$t7,0x3
/*  f18faf0:	1420000a */ 	bnez	$at,.L0f18fb1c
/*  f18faf4:	332a0001 */ 	andi	$t2,$t9,0x1
/*  f18faf8:	55400006 */ 	bnezl	$t2,.L0f18fb14
/*  f18fafc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f18fb00:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f18fb04:	256c0007 */ 	addiu	$t4,$t3,0x7
/*  f18fb08:	10000004 */ 	b	.L0f18fb1c
/*  f18fb0c:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f18fb10:	8e2d0000 */ 	lw	$t5,0x0($s1)
.L0f18fb14:
/*  f18fb14:	25aefff9 */ 	addiu	$t6,$t5,-7
/*  f18fb18:	ae2e0000 */ 	sw	$t6,0x0($s1)
.L0f18fb1c:
/*  f18fb1c:	0c002f44 */ 	jal	viGetViewTop
/*  f18fb20:	00000000 */ 	nop
/*  f18fb24:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fb28:	3c10800b */ 	lui	$s0,%hi(var800acc74)
/*  f18fb2c:	2610cc74 */ 	addiu	$s0,$s0,%lo(var800acc74)
/*  f18fb30:	2458001a */ 	addiu	$t8,$v0,0x1a
/*  f18fb34:	24010002 */ 	addiu	$at,$zero,0x2
/*  f18fb38:	15e10015 */ 	bne	$t7,$at,.L0f18fb90
/*  f18fb3c:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f18fb40:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*  f18fb44:	93390af0 */ 	lbu	$t9,%lo(g_Is4Mb)($t9)
/*  f18fb48:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fb4c:	270bfffa */ 	addiu	$t3,$t8,-6
/*  f18fb50:	17210003 */ 	bne	$t9,$at,.L0f18fb60
/*  f18fb54:	00000000 */ 	nop
/*  f18fb58:	10000023 */ 	b	.L0f18fbe8
/*  f18fb5c:	ae0b0000 */ 	sw	$t3,0x0($s0)
.L0f18fb60:
/*  f18fb60:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f18fb64:	00000000 */ 	nop
/*  f18fb68:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fb6c:	1041001e */ 	beq	$v0,$at,.L0f18fbe8
/*  f18fb70:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f18fb74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fb78:	5581001c */ 	bnel	$t4,$at,.L0f18fbec
/*  f18fb7c:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f18fb80:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18fb84:	25aefff8 */ 	addiu	$t6,$t5,-8
/*  f18fb88:	10000017 */ 	b	.L0f18fbe8
/*  f18fb8c:	ae0e0000 */ 	sw	$t6,0x0($s0)
.L0f18fb90:
/*  f18fb90:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f18fb94:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f18fb98:	2b010003 */ 	slti	$at,$t8,0x3
/*  f18fb9c:	1420000b */ 	bnez	$at,.L0f18fbcc
/*  f18fba0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f18fba4:	54200006 */ 	bnezl	$at,.L0f18fbc0
/*  f18fba8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18fbac:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18fbb0:	272afff8 */ 	addiu	$t2,$t9,-8
/*  f18fbb4:	1000000c */ 	b	.L0f18fbe8
/*  f18fbb8:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f18fbbc:	8e0b0000 */ 	lw	$t3,0x0($s0)
.L0f18fbc0:
/*  f18fbc0:	256cfffe */ 	addiu	$t4,$t3,-2
/*  f18fbc4:	10000008 */ 	b	.L0f18fbe8
/*  f18fbc8:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0f18fbcc:
/*  f18fbcc:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f18fbd0:	00000000 */ 	nop
/*  f18fbd4:	50400005 */ 	beqzl	$v0,.L0f18fbec
/*  f18fbd8:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f18fbdc:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18fbe0:	25aefffa */ 	addiu	$t6,$t5,-6
/*  f18fbe4:	ae0e0000 */ 	sw	$t6,0x0($s0)
.L0f18fbe8:
/*  f18fbe8:	24180010 */ 	addiu	$t8,$zero,0x10
.L0f18fbec:
/*  f18fbec:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18fbf0:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18fbf4:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f18fbf8:	8e260000 */ 	lw	$a2,0x0($s1)
/*  f18fbfc:	0fc6396b */ 	jal	func0f18e5ac
/*  f18fc00:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f18fc04:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18fc08:	0fc54c4d */ 	jal	func0f153134
/*  f18fc0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f18fc10:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fc14:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18fc18:	00008825 */ 	or	$s1,$zero,$zero
/*  f18fc1c:	59e0004b */ 	blezl	$t7,.L0f18fd4c
/*  f18fc20:	8e4e0318 */ 	lw	$t6,0x318($s2)
/*  f18fc24:	8fb90078 */ 	lw	$t9,0x78($sp)
.L0f18fc28:
/*  f18fc28:	00115080 */ 	sll	$t2,$s1,0x2
/*  f18fc2c:	024a4821 */ 	addu	$t1,$s2,$t2
/*  f18fc30:	52390042 */ 	beql	$s1,$t9,.L0f18fd3c
/*  f18fc34:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f18fc38:	8d220064 */ 	lw	$v0,0x64($t1)
/*  f18fc3c:	8c4b00d8 */ 	lw	$t3,0xd8($v0)
/*  f18fc40:	5560003e */ 	bnezl	$t3,.L0f18fd3c
/*  f18fc44:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f18fc48:	8c4500bc */ 	lw	$a1,0xbc($v0)
/*  f18fc4c:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f18fc50:	8cac0004 */ 	lw	$t4,0x4($a1)
/*  f18fc54:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*  f18fc58:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f18fc5c:	05c20037 */ 	bltzl	$t6,.L0f18fd3c
/*  f18fc60:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f18fc64:	0fc61770 */ 	jal	scenarioRadar2
/*  f18fc68:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f18fc6c:	14400032 */ 	bnez	$v0,.L0f18fd38
/*  f18fc70:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f18fc74:	8d220064 */ 	lw	$v0,0x64($t1)
/*  f18fc78:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18fc7c:	8e4d0318 */ 	lw	$t5,0x318($s2)
/*  f18fc80:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f18fc84:	8d0f00bc */ 	lw	$t7,0xbc($t0)
/*  f18fc88:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0xc)
/*  f18fc8c:	c7040008 */ 	lwc1	$f4,0x8($t8)
/*  f18fc90:	c5e60008 */ 	lwc1	$f6,0x8($t7)
/*  f18fc94:	3c0700ff */ 	lui	$a3,0xff
/*  f18fc98:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18fc9c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fca0:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f18fca4:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f18fca8:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f18fcac:	8d0a00bc */ 	lw	$t2,0xbc($t0)
/*  f18fcb0:	c72a000c */ 	lwc1	$f10,0xc($t9)
/*  f18fcb4:	c550000c */ 	lwc1	$f16,0xc($t2)
/*  f18fcb8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fcbc:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*  f18fcc0:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f18fcc4:	8d0c00bc */ 	lw	$t4,0xbc($t0)
/*  f18fcc8:	c5640010 */ 	lwc1	$f4,0x10($t3)
/*  f18fccc:	c5860010 */ 	lwc1	$f6,0x10($t4)
/*  f18fcd0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fcd4:	11a00013 */ 	beqz	$t5,.L0f18fd24
/*  f18fcd8:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f18fcdc:	8dcecb94 */ 	lw	$t6,%lo(g_MpSetup+0xc)($t6)
/*  f18fce0:	001179c0 */ 	sll	$t7,$s1,0x7
/*  f18fce4:	024fc821 */ 	addu	$t9,$s2,$t7
/*  f18fce8:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f18fcec:	1300000d */ 	beqz	$t8,.L0f18fd24
/*  f18fcf0:	00000000 */ 	nop
/*  f18fcf4:	8f2a00e4 */ 	lw	$t2,0xe4($t9)
/*  f18fcf8:	3c03800b */ 	lui	$v1,%hi(g_MpPlayers+0x11)
/*  f18fcfc:	3c078008 */ 	lui	$a3,%hi(g_TeamColours)
/*  f18fd00:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f18fd04:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f18fd08:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f18fd0c:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f18fd10:	9063c7c9 */ 	lbu	$v1,%lo(g_MpPlayers+0x11)($v1)
/*  f18fd14:	00036080 */ 	sll	$t4,$v1,0x2
/*  f18fd18:	00ec3821 */ 	addu	$a3,$a3,$t4
/*  f18fd1c:	10000001 */ 	b	.L0f18fd24
/*  f18fd20:	8ce77cc4 */ 	lw	$a3,%lo(g_TeamColours)($a3)
.L0f18fd24:
/*  f18fd24:	8c4500bc */ 	lw	$a1,0xbc($v0)
/*  f18fd28:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18fd2c:	0fc63a7b */ 	jal	radarDrawDot
/*  f18fd30:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18fd34:	afa20088 */ 	sw	$v0,0x88($sp)
.L0f18fd38:
/*  f18fd38:	8fad007c */ 	lw	$t5,0x7c($sp)
.L0f18fd3c:
/*  f18fd3c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fd40:	562dffb9 */ 	bnel	$s1,$t5,.L0f18fc28
/*  f18fd44:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f18fd48:	8e4e0318 */ 	lw	$t6,0x318($s2)
.L0f18fd4c:
/*  f18fd4c:	3c18800a */ 	lui	$t8,%hi(g_MissionConfig+0x3)
/*  f18fd50:	55c0003b */ 	bnezl	$t6,.L0f18fe40
/*  f18fd54:	8e4e0318 */ 	lw	$t6,0x318($s2)
/*  f18fd58:	830fdfeb */ 	lb	$t7,%lo(g_MissionConfig+0x3)($t8)
/*  f18fd5c:	05e30038 */ 	bgezl	$t7,.L0f18fe40
/*  f18fd60:	8e4e0318 */ 	lw	$t6,0x318($s2)
/*  f18fd64:	8e440474 */ 	lw	$a0,0x474($s2)
/*  f18fd68:	0000c880 */ 	sll	$t9,$zero,0x2
/*  f18fd6c:	02594821 */ 	addu	$t1,$s2,$t9
/*  f18fd70:	18800032 */ 	blez	$a0,.L0f18fe3c
/*  f18fd74:	00008825 */ 	or	$s1,$zero,$zero
/*  f18fd78:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f18fd7c:	8d2504b8 */ 	lw	$a1,0x4b8($t1)
.L0f18fd80:
/*  f18fd80:	50a00029 */ 	beqzl	$a1,.L0f18fe28
/*  f18fd84:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fd88:	90aa0000 */ 	lbu	$t2,0x0($a1)
/*  f18fd8c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f18fd90:	55410025 */ 	bnel	$t2,$at,.L0f18fe28
/*  f18fd94:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fd98:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f18fd9c:	50400022 */ 	beqzl	$v0,.L0f18fe28
/*  f18fda0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fda4:	80430007 */ 	lb	$v1,0x7($v0)
/*  f18fda8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18fdac:	5203001e */ 	beql	$s0,$v1,.L0f18fe28
/*  f18fdb0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fdb4:	5061001c */ 	beql	$v1,$at,.L0f18fe28
/*  f18fdb8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fdbc:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18fdc0:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f18fdc4:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18fdc8:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f18fdcc:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f18fdd0:	3c0700ff */ 	lui	$a3,0xff
/*  f18fdd4:	c5700008 */ 	lwc1	$f16,0x8($t3)
/*  f18fdd8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fddc:	e7b20068 */ 	swc1	$f18,0x68($sp)
/*  f18fde0:	8d0c00bc */ 	lw	$t4,0xbc($t0)
/*  f18fde4:	c4a4000c */ 	lwc1	$f4,0xc($a1)
/*  f18fde8:	c586000c */ 	lwc1	$f6,0xc($t4)
/*  f18fdec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fdf0:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f18fdf4:	8d0d00bc */ 	lw	$t5,0xbc($t0)
/*  f18fdf8:	c4aa0010 */ 	lwc1	$f10,0x10($a1)
/*  f18fdfc:	c5b00010 */ 	lwc1	$f16,0x10($t5)
/*  f18fe00:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f18fe04:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18fe08:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fe0c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18fe10:	0fc63a7b */ 	jal	radarDrawDot
/*  f18fe14:	e7b20070 */ 	swc1	$f18,0x70($sp)
/*  f18fe18:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f18fe1c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18fe20:	8e440474 */ 	lw	$a0,0x474($s2)
/*  f18fe24:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18fe28:
/*  f18fe28:	0224082a */ 	slt	$at,$s1,$a0
/*  f18fe2c:	10200003 */ 	beqz	$at,.L0f18fe3c
/*  f18fe30:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f18fe34:	5630ffd2 */ 	bnel	$s1,$s0,.L0f18fd80
/*  f18fe38:	8d2504b8 */ 	lw	$a1,0x4b8($t1)
.L0f18fe3c:
/*  f18fe3c:	8e4e0318 */ 	lw	$t6,0x318($s2)
.L0f18fe40:
/*  f18fe40:	3c188008 */ 	lui	$t8,%hi(g_NumMpSimulantChrs)
/*  f18fe44:	11c00046 */ 	beqz	$t6,.L0f18ff60
/*  f18fe48:	00000000 */ 	nop
/*  f18fe4c:	93187d10 */ 	lbu	$t8,%lo(g_NumMpSimulantChrs)($t8)
/*  f18fe50:	3c10800b */ 	lui	$s0,%hi(g_MpSimulantChrs)
/*  f18fe54:	2610cc80 */ 	addiu	$s0,$s0,%lo(g_MpSimulantChrs)
/*  f18fe58:	1b000041 */ 	blez	$t8,.L0f18ff60
/*  f18fe5c:	00008825 */ 	or	$s1,$zero,$zero
.L0f18fe60:
/*  f18fe60:	0fc0e6a5 */ 	jal	chrIsDead
/*  f18fe64:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f18fe68:	14400036 */ 	bnez	$v0,.L0f18ff44
/*  f18fe6c:	00000000 */ 	nop
/*  f18fe70:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f18fe74:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f18fe78:	8c6f0014 */ 	lw	$t7,0x14($v1)
/*  f18fe7c:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18fe80:	07200030 */ 	bltz	$t9,.L0f18ff44
/*  f18fe84:	00000000 */ 	nop
/*  f18fe88:	0fc61770 */ 	jal	scenarioRadar2
/*  f18fe8c:	8c65001c */ 	lw	$a1,0x1c($v1)
/*  f18fe90:	1440002c */ 	bnez	$v0,.L0f18ff44
/*  f18fe94:	00000000 */ 	nop
/*  f18fe98:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f18fe9c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18fea0:	8e4f0318 */ 	lw	$t7,0x318($s2)
/*  f18fea4:	8c6a001c */ 	lw	$t2,0x1c($v1)
/*  f18fea8:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f18feac:	3c19800b */ 	lui	$t9,%hi(g_MpSetup+0xc)
/*  f18feb0:	c5440008 */ 	lwc1	$f4,0x8($t2)
/*  f18feb4:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f18feb8:	3c0700ff */ 	lui	$a3,0xff
/*  f18febc:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fec0:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f18fec4:	8c6c001c */ 	lw	$t4,0x1c($v1)
/*  f18fec8:	8d0d00bc */ 	lw	$t5,0xbc($t0)
/*  f18fecc:	c58a000c */ 	lwc1	$f10,0xc($t4)
/*  f18fed0:	c5b0000c */ 	lwc1	$f16,0xc($t5)
/*  f18fed4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fed8:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*  f18fedc:	8c6e001c */ 	lw	$t6,0x1c($v1)
/*  f18fee0:	8d1800bc */ 	lw	$t8,0xbc($t0)
/*  f18fee4:	c5c40010 */ 	lwc1	$f4,0x10($t6)
/*  f18fee8:	c7060010 */ 	lwc1	$f6,0x10($t8)
/*  f18feec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fef0:	11e0000d */ 	beqz	$t7,.L0f18ff28
/*  f18fef4:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f18fef8:	8f39cb94 */ 	lw	$t9,%lo(g_MpSetup+0xc)($t9)
/*  f18fefc:	332a0002 */ 	andi	$t2,$t9,0x2
/*  f18ff00:	11400009 */ 	beqz	$t2,.L0f18ff28
/*  f18ff04:	00000000 */ 	nop
/*  f18ff08:	0fc63a5a */ 	jal	teamGetIndex
/*  f18ff0c:	90640125 */ 	lbu	$a0,0x125($v1)
/*  f18ff10:	00025880 */ 	sll	$t3,$v0,0x2
/*  f18ff14:	3c078008 */ 	lui	$a3,%hi(g_TeamColours)
/*  f18ff18:	00eb3821 */ 	addu	$a3,$a3,$t3
/*  f18ff1c:	8ce77cc4 */ 	lw	$a3,%lo(g_TeamColours)($a3)
/*  f18ff20:	10000001 */ 	b	.L0f18ff28
/*  f18ff24:	8e030000 */ 	lw	$v1,0x0($s0)
.L0f18ff28:
/*  f18ff28:	8c65001c */ 	lw	$a1,0x1c($v1)
/*  f18ff2c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18ff30:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18ff34:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18ff38:	0fc63a7b */ 	jal	radarDrawDot
/*  f18ff3c:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f18ff40:	afa20088 */ 	sw	$v0,0x88($sp)
.L0f18ff44:
/*  f18ff44:	3c0c8008 */ 	lui	$t4,%hi(g_NumMpSimulantChrs)
/*  f18ff48:	918c7d10 */ 	lbu	$t4,%lo(g_NumMpSimulantChrs)($t4)
/*  f18ff4c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18ff50:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f18ff54:	022c082a */ 	slt	$at,$s1,$t4
/*  f18ff58:	1420ffc1 */ 	bnez	$at,.L0f18fe60
/*  f18ff5c:	00000000 */ 	nop
.L0f18ff60:
/*  f18ff60:	0fc61758 */ 	jal	scenarioRadar
/*  f18ff64:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18ff68:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18ff6c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18ff70:	8d0e1c54 */ 	lw	$t6,0x1c54($t0)
/*  f18ff74:	8d0d00c4 */ 	lw	$t5,0xc4($t0)
/*  f18ff78:	01c0c027 */ 	nor	$t8,$t6,$zero
/*  f18ff7c:	01b87824 */ 	and	$t7,$t5,$t8
/*  f18ff80:	31f90010 */ 	andi	$t9,$t7,0x10
/*  f18ff84:	53200006 */ 	beqzl	$t9,.L0f18ffa0
/*  f18ff88:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f18ff8c:	0fc64018 */ 	jal	radarDrawProps
/*  f18ff90:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ff94:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18ff98:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18ff9c:	27a40088 */ 	addiu	$a0,$sp,0x88
.L0f18ffa0:
/*  f18ffa0:	0fc61770 */ 	jal	scenarioRadar2
/*  f18ffa4:	8d0500bc */ 	lw	$a1,0xbc($t0)
/*  f18ffa8:	54400024 */ 	bnezl	$v0,.L0f19003c
/*  f18ffac:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f18ffb0:	44800000 */ 	mtc1	$zero,$f0
/*  f18ffb4:	8e4a0318 */ 	lw	$t2,0x318($s2)
/*  f18ffb8:	3c0b800b */ 	lui	$t3,%hi(g_MpSetup+0xc)
/*  f18ffbc:	e7a00068 */ 	swc1	$f0,0x68($sp)
/*  f18ffc0:	e7a0006c */ 	swc1	$f0,0x6c($sp)
/*  f18ffc4:	11400013 */ 	beqz	$t2,.L0f190014
/*  f18ffc8:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f18ffcc:	8d6bcb94 */ 	lw	$t3,%lo(g_MpSetup+0xc)($t3)
/*  f18ffd0:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f18ffd4:	316c0002 */ 	andi	$t4,$t3,0x2
/*  f18ffd8:	1180000e */ 	beqz	$t4,.L0f190014
/*  f18ffdc:	000e69c0 */ 	sll	$t5,$t6,0x7
/*  f18ffe0:	024dc021 */ 	addu	$t8,$s2,$t5
/*  f18ffe4:	8f0f00e4 */ 	lw	$t7,0xe4($t8)
/*  f18ffe8:	3c02800b */ 	lui	$v0,%hi(g_MpPlayers+0x11)
/*  f18ffec:	3c078008 */ 	lui	$a3,%hi(g_TeamColours)
/*  f18fff0:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18fff4:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f18fff8:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f18fffc:	00591021 */ 	addu	$v0,$v0,$t9
/*  f190000:	9042c7c9 */ 	lbu	$v0,%lo(g_MpPlayers+0x11)($v0)
/*  f190004:	00025080 */ 	sll	$t2,$v0,0x2
/*  f190008:	00ea3821 */ 	addu	$a3,$a3,$t2
/*  f19000c:	10000002 */ 	b	.L0f190018
/*  f190010:	8ce77cc4 */ 	lw	$a3,%lo(g_TeamColours)($a3)
.L0f190014:
/*  f190014:	3c0700ff */ 	lui	$a3,0xff
.L0f190018:
/*  f190018:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f19001c:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f190020:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f190024:	8d6500bc */ 	lw	$a1,0xbc($t3)
/*  f190028:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19002c:	0fc63a7b */ 	jal	radarDrawDot
/*  f190030:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f190034:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f190038:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f19003c:
/*  f19003c:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f190040:	ac2cfac0 */ 	sw	$t4,%lo(g_ScreenWidthMultiplier)($at)
/*  f190044:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f190048:
/*  f190048:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f19004c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f190050:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f190054:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f190058:	03e00008 */ 	jr	$ra
/*  f19005c:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

Gfx *radarDrawProps(Gfx *gdl)
{
	struct prop *prop = g_Vars.unk00033c;
	struct coord *playerpos = &g_Vars.currentplayer->prop->pos;
	struct defaultobj *obj;
	struct chrdata *chr;
	u32 stack1;
	struct coord dist1;
	u32 stack2;
	struct coord dist2;

	while (prop) {
		switch (prop->type) {
		case PROPTYPE_OBJ:
		case PROPTYPE_DOOR:
		case PROPTYPE_WEAPON:
			obj = prop->obj;

			if ((obj->flags3 & OBJFLAG3_RTRACKED_YELLOW) ||
					(cheatIsActive(CHEAT_RTRACKER) && (obj->flags3 & OBJFLAG3_RTRACKED_BLUE))) {
				dist1.x = prop->pos.x - playerpos->x;
				dist1.y = prop->pos.y - playerpos->y;
				dist1.z = prop->pos.z - playerpos->z;

				gdl = radarDrawDot(gdl, prop, &dist1,
						(obj->flags3 & OBJFLAG3_RTRACKED_YELLOW) ? 0xffff0000 : 0x0000ff00,
						0, 0);
			}
			break;
		case PROPTYPE_CHR:
			chr = prop->chr;

			if (chr && chr->unk32c_20
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DEAD
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0) {
				dist2.x = prop->pos.x - playerpos->x;
				dist2.y = prop->pos.y - playerpos->y;
				dist2.z = prop->pos.z - playerpos->z;
				gdl = radarDrawDot(gdl, prop, &dist2, 0xff000000, 0, 0);
			}
			break;
		}

		prop = prop->next;
	}

	return gdl;
}
