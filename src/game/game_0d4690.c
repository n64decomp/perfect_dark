#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_166e40.h"
#include "game/utils.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_13130.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_4b480.h"
#include "lib/lib_4fe20.h"
#include "types.h"

const u32 var7f1adba0[] = {0x74786d75};
const u32 var7f1adba4[] = {0x6c000000};

const char var7f1adba8[] = "depthsub";
const char var7f1adbb4[] = "rsub";
const char var7f1adbbc[] = ":%02d";
const char var7f1adbc4[] = "%d";

const u32 var7f1adbc8[] = {0xc31fc000};
const u32 var7f1adbcc[] = {0x42f08000};
const u32 var7f1adbd0[] = {0x3dcccccd};
const u32 var7f1adbd4[] = {0x3dcccccd};
const u32 var7f1adbd8[] = {0x461c4000};
const u32 var7f1adbdc[] = {0x3dcccccd};
const u32 var7f1adbe0[] = {0x3dcccccd};
const u32 var7f1adbe4[] = {0x00000000};
const u32 var7f1adbe8[] = {0x00000000};
const u32 var7f1adbec[] = {0x00000000};

GLOBAL_ASM(
glabel func0f0d4690
/*  f0d4690:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0d4694:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d4698:	0c00566c */ 	jal	func000159b0
/*  f0d469c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0d46a0:	3c017f1b */ 	lui	$at,%hi(var7f1adbc8)
/*  f0d46a4:	c424dbc8 */ 	lwc1	$f4,%lo(var7f1adbc8)($at)
/*  f0d46a8:	3c017f1b */ 	lui	$at,%hi(var7f1adbcc)
/*  f0d46ac:	c426dbcc */ 	lwc1	$f6,%lo(var7f1adbcc)($at)
/*  f0d46b0:	44804000 */ 	mtc1	$zero,$f8
/*  f0d46b4:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0d46b8:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0d46bc:	0c002f02 */ 	jal	func0000bc08
/*  f0d46c0:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0d46c4:	44828000 */ 	mtc1	$v0,$f16
/*  f0d46c8:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d46cc:	44815000 */ 	mtc1	$at,$f10
/*  f0d46d0:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d46d4:	44813000 */ 	mtc1	$at,$f6
/*  f0d46d8:	46125101 */ 	sub.s	$f4,$f10,$f18
/*  f0d46dc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d46e0:	0c002f06 */ 	jal	func0000bc18
/*  f0d46e4:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*  f0d46e8:	44828000 */ 	mtc1	$v0,$f16
/*  f0d46ec:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d46f0:	44819000 */ 	mtc1	$at,$f18
/*  f0d46f4:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f0d46f8:	44813000 */ 	mtc1	$at,$f6
/*  f0d46fc:	44808000 */ 	mtc1	$zero,$f16
/*  f0d4700:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f0d4704:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f0d4708:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f0d470c:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f0d4710:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d4714:	0c005775 */ 	jal	func00015dd4
/*  f0d4718:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f0d471c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d4720:	44816000 */ 	mtc1	$at,$f12
/*  f0d4724:	0c005793 */ 	jal	func00015e4c
/*  f0d4728:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f0d472c:	3c0e8008 */ 	lui	$t6,%hi(var8007fac0)
/*  f0d4730:	8dcefac0 */ 	lw	$t6,%lo(var8007fac0)($t6)
/*  f0d4734:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d4738:	15c10004 */ 	bne	$t6,$at,.L0f0d474c
/*  f0d473c:	3c014000 */ 	lui	$at,0x4000
/*  f0d4740:	44816000 */ 	mtc1	$at,$f12
/*  f0d4744:	0c00577c */ 	jal	func00015df0
/*  f0d4748:	8fa50028 */ 	lw	$a1,0x28($sp)
.L0f0d474c:
/*  f0d474c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d4750:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0d4754:	03e00008 */ 	jr	$ra
/*  f0d4758:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d475c
/*  f0d475c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0d4760:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d4764:	0fc351a4 */ 	jal	func0f0d4690
/*  f0d4768:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0d476c:	3c017f1b */ 	lui	$at,%hi(var7f1adbd0)
/*  f0d4770:	c42cdbd0 */ 	lwc1	$f12,%lo(var7f1adbd0)($at)
/*  f0d4774:	0c00577c */ 	jal	func00015df0
/*  f0d4778:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0d477c:	3c017f1b */ 	lui	$at,%hi(var7f1adbd4)
/*  f0d4780:	c42cdbd4 */ 	lwc1	$f12,%lo(var7f1adbd4)($at)
/*  f0d4784:	0c005793 */ 	jal	func00015e4c
/*  f0d4788:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0d478c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d4790:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0d4794:	03e00008 */ 	jr	$ra
/*  f0d4798:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d479c
/*  f0d479c:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0d47a0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d47a4:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0d47a8:	00808825 */ 	or	$s1,$a0,$zero
/*  f0d47ac:	0fc59e66 */ 	jal	func0f167998
/*  f0d47b0:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0d47b4:	0fc59e66 */ 	jal	func0f167998
/*  f0d47b8:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0d47bc:	0c0059d8 */ 	jal	func00016760
/*  f0d47c0:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0d47c4:	27b00058 */ 	addiu	$s0,$sp,0x58
/*  f0d47c8:	0fc351d7 */ 	jal	func0f0d475c
/*  f0d47cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d47d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d47d4:	0c005815 */ 	jal	func00016054
/*  f0d47d8:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0d47dc:	0c00566c */ 	jal	func000159b0
/*  f0d47e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d47e4:	0c002f02 */ 	jal	func0000bc08
/*  f0d47e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d47ec:	0c002f02 */ 	jal	func0000bc08
/*  f0d47f0:	a7a20034 */ 	sh	$v0,0x34($sp)
/*  f0d47f4:	0c002f06 */ 	jal	func0000bc18
/*  f0d47f8:	a7a20036 */ 	sh	$v0,0x36($sp)
/*  f0d47fc:	0c002f06 */ 	jal	func0000bc18
/*  f0d4800:	a7a20038 */ 	sh	$v0,0x38($sp)
/*  f0d4804:	87ae0034 */ 	lh	$t6,0x34($sp)
/*  f0d4808:	87af0036 */ 	lh	$t7,0x36($sp)
/*  f0d480c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d4810:	448e2000 */ 	mtc1	$t6,$f4
/*  f0d4814:	448f8000 */ 	mtc1	$t7,$f16
/*  f0d4818:	44810000 */ 	mtc1	$at,$f0
/*  f0d481c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d4820:	87b80038 */ 	lh	$t8,0x38($sp)
/*  f0d4824:	3c014120 */ 	lui	$at,0x4120
/*  f0d4828:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d482c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d4830:	46003207 */ 	neg.s	$f8,$f6
/*  f0d4834:	44983000 */ 	mtc1	$t8,$f6
/*  f0d4838:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0d483c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d4840:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0d4844:	44829000 */ 	mtc1	$v0,$f18
/*  f0d4848:	44055000 */ 	mfc1	$a1,$f10
/*  f0d484c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d4850:	44062000 */ 	mfc1	$a2,$f4
/*  f0d4854:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0d4858:	46004287 */ 	neg.s	$f10,$f8
/*  f0d485c:	44814000 */ 	mtc1	$at,$f8
/*  f0d4860:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0d4864:	3c017f1b */ 	lui	$at,%hi(var7f1adbd8)
/*  f0d4868:	c42adbd8 */ 	lwc1	$f10,%lo(var7f1adbd8)($at)
/*  f0d486c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0d4870:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4874:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0d4878:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0d487c:	44078000 */ 	mfc1	$a3,$f16
/*  f0d4880:	44818000 */ 	mtc1	$at,$f16
/*  f0d4884:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0d4888:	0c013f88 */ 	jal	func0004fe20
/*  f0d488c:	e7b0001c */ 	swc1	$f16,0x1c($sp)
/*  f0d4890:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d4894:	0c005815 */ 	jal	func00016054
/*  f0d4898:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0d489c:	0c0059e1 */ 	jal	func00016784
/*  f0d48a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d48a4:	3c190102 */ 	lui	$t9,0x102
/*  f0d48a8:	37390040 */ 	ori	$t9,$t9,0x40
/*  f0d48ac:	02208025 */ 	or	$s0,$s1,$zero
/*  f0d48b0:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f0d48b4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0d48b8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d48bc:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0d48c0:	3c080103 */ 	lui	$t0,0x103
/*  f0d48c4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0d48c8:	35080040 */ 	ori	$t0,$t0,0x40
/*  f0d48cc:	02201825 */ 	or	$v1,$s1,$zero
/*  f0d48d0:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f0d48d4:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0d48d8:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f0d48dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d48e0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0d48e4:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f0d48e8:	3c108007 */ 	lui	$s0,%hi(var80070f10)
/*  f0d48ec:	26100f10 */ 	addiu	$s0,$s0,%lo(var80070f10)
/*  f0d48f0:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0d48f4:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f0d48f8:	55200023 */ 	bnezl	$t1,.L0f0d4988
/*  f0d48fc:	3c0f0380 */ 	lui	$t7,0x380
/*  f0d4900:	0fc5db69 */ 	jal	func0f176da4
/*  f0d4904:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f0d4908:	0fc59e7d */ 	jal	func0f1679f4
/*  f0d490c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d4910:	1040001c */ 	beqz	$v0,.L0f0d4984
/*  f0d4914:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0d4918:	0c002f02 */ 	jal	func0000bc08
/*  f0d491c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d4920:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f0d4924:	00025840 */ 	sll	$t3,$v0,0x1
/*  f0d4928:	0c002f06 */ 	jal	func0000bc18
/*  f0d492c:	a58b0000 */ 	sh	$t3,0x0($t4)
/*  f0d4930:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d4934:	00026840 */ 	sll	$t5,$v0,0x1
/*  f0d4938:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d493c:	a5cd0002 */ 	sh	$t5,0x2($t6)
/*  f0d4940:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d4944:	a70f0004 */ 	sh	$t7,0x4($t8)
/*  f0d4948:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d494c:	0c002f02 */ 	jal	func0000bc08
/*  f0d4950:	a7200006 */ 	sh	$zero,0x6($t9)
/*  f0d4954:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f0d4958:	00024040 */ 	sll	$t0,$v0,0x1
/*  f0d495c:	0c002f06 */ 	jal	func0000bc18
/*  f0d4960:	a5280008 */ 	sh	$t0,0x8($t1)
/*  f0d4964:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f0d4968:	00025040 */ 	sll	$t2,$v0,0x1
/*  f0d496c:	240c01ff */ 	addiu	$t4,$zero,0x1ff
/*  f0d4970:	a56a000a */ 	sh	$t2,0xa($t3)
/*  f0d4974:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f0d4978:	a5ac000c */ 	sh	$t4,0xc($t5)
/*  f0d497c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d4980:	a5c0000e */ 	sh	$zero,0xe($t6)
.L0f0d4984:
/*  f0d4984:	3c0f0380 */ 	lui	$t7,0x380
.L0f0d4988:
/*  f0d4988:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0d498c:	02201825 */ 	or	$v1,$s1,$zero
/*  f0d4990:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0d4994:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d4998:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0d499c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0d49a0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0d49a4:	3c19e700 */ 	lui	$t9,0xe700
/*  f0d49a8:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0d49ac:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0d49b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d49b4:	26220008 */ 	addiu	$v0,$s1,0x8
/*  f0d49b8:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0d49bc:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0d49c0:	03e00008 */ 	jr	$ra
/*  f0d49c4:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0d49c8
/*  f0d49c8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0d49cc:	3c0e0380 */ 	lui	$t6,0x380
/*  f0d49d0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0d49d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0d49d8:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f0d49dc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0d49e0:	afa40024 */ 	sw	$a0,0x24($sp)
/*  f0d49e4:	0c002ad3 */ 	jal	func0000ab4c
/*  f0d49e8:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f0d49ec:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f0d49f0:	3c018000 */ 	lui	$at,0x8000
/*  f0d49f4:	00417821 */ 	addu	$t7,$v0,$at
/*  f0d49f8:	3c180103 */ 	lui	$t8,0x103
/*  f0d49fc:	37180040 */ 	ori	$t8,$t8,0x40
/*  f0d4a00:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d4a04:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0d4a08:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0d4a0c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0d4a10:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f0d4a14:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d4a18:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d4a1c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d4a20:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f0d4a24:	af220004 */ 	sw	$v0,0x4($t9)
/*  f0d4a28:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0d4a2c:	02001025 */ 	or	$v0,$s0,$zero
/*  f0d4a30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0d4a34:	03e00008 */ 	jr	$ra
/*  f0d4a38:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f0d4a3c
/*  f0d4a3c:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0d4a40:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0d4a44:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f0d4a48:	0fc59e66 */ 	jal	func0f167998
/*  f0d4a4c:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f0d4a50:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0d4a54:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f0d4a58:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0d4a5c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d4a60:	afaf00a0 */ 	sw	$t7,0xa0($sp)
/*  f0d4a64:	3c18e700 */ 	lui	$t8,0xe700
/*  f0d4a68:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d4a6c:	1480000f */ 	bnez	$a0,.L0f0d4aac
/*  f0d4a70:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0d4a74:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f0d4a78:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f0d4a7c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0d4a80:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0d4a84:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0d4a88:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d4a8c:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0d4a90:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0d4a94:	00003825 */ 	or	$a3,$zero,$zero
/*  f0d4a98:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d4a9c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0d4aa0:	24a50048 */ 	addiu	$a1,$a1,0x0048
/*  f0d4aa4:	10000010 */ 	beqz	$zero,.L0f0d4ae8
/*  f0d4aa8:	8fab00a0 */ 	lw	$t3,0xa0($sp)
.L0f0d4aac:
/*  f0d4aac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d4ab0:	1481000c */ 	bne	$a0,$at,.L0f0d4ae4
/*  f0d4ab4:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f0d4ab8:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f0d4abc:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0d4ac0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0d4ac4:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0d4ac8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0d4acc:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0d4ad0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0d4ad4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0d4ad8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d4adc:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0d4ae0:	24a50084 */ 	addiu	$a1,$a1,0x0084
.L0f0d4ae4:
/*  f0d4ae4:	8fab00a0 */ 	lw	$t3,0xa0($sp)
.L0f0d4ae8:
/*  f0d4ae8:	3c0de700 */ 	lui	$t5,0xe700
/*  f0d4aec:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0d4af0:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0d4af4:	afac00a0 */ 	sw	$t4,0xa0($sp)
/*  f0d4af8:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0d4afc:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0d4b00:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0d4b04:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f0d4b08:	3c09b900 */ 	lui	$t1,0xb900
/*  f0d4b0c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d4b10:	afaf00a0 */ 	sw	$t7,0xa0($sp)
/*  f0d4b14:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0d4b18:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d4b1c:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f0d4b20:	35290002 */ 	ori	$t1,$t1,0x2
/*  f0d4b24:	3c0dff33 */ 	lui	$t5,0xff33
/*  f0d4b28:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f0d4b2c:	afa800a0 */ 	sw	$t0,0xa0($sp)
/*  f0d4b30:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0d4b34:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0d4b38:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f0d4b3c:	3c0cfc12 */ 	lui	$t4,0xfc12
/*  f0d4b40:	358c1824 */ 	ori	$t4,$t4,0x1824
/*  f0d4b44:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0d4b48:	afab00a0 */ 	sw	$t3,0xa0($sp)
/*  f0d4b4c:	35adffff */ 	ori	$t5,$t5,0xffff
/*  f0d4b50:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0d4b54:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0d4b58:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0d4b5c:	3c07b700 */ 	lui	$a3,0xb700
/*  f0d4b60:	24180004 */ 	addiu	$t8,$zero,0x4
/*  f0d4b64:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d4b68:	afaf00a0 */ 	sw	$t7,0xa0($sp)
/*  f0d4b6c:	add80004 */ 	sw	$t8,0x4($t6)
/*  f0d4b70:	adc70000 */ 	sw	$a3,0x0($t6)
/*  f0d4b74:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f0d4b78:	24090200 */ 	addiu	$t1,$zero,0x200
/*  f0d4b7c:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0d4b80:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f0d4b84:	afa800a0 */ 	sw	$t0,0xa0($sp)
/*  f0d4b88:	af290004 */ 	sw	$t1,0x4($t9)
/*  f0d4b8c:	af270000 */ 	sw	$a3,0x0($t9)
/*  f0d4b90:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f0d4b94:	240d3000 */ 	addiu	$t5,$zero,0x3000
/*  f0d4b98:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0d4b9c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0d4ba0:	afab00a0 */ 	sw	$t3,0xa0($sp)
/*  f0d4ba4:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0d4ba8:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0d4bac:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0d4bb0:	37180602 */ 	ori	$t8,$t8,0x602
/*  f0d4bb4:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f0d4bb8:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d4bbc:	afaf00a0 */ 	sw	$t7,0xa0($sp)
/*  f0d4bc0:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0d4bc4:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d4bc8:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f0d4bcc:	3c0aba00 */ 	lui	$t2,0xba00
/*  f0d4bd0:	354a0c02 */ 	ori	$t2,$t2,0xc02
/*  f0d4bd4:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f0d4bd8:	afa900a0 */ 	sw	$t1,0xa0($sp)
/*  f0d4bdc:	240b2000 */ 	addiu	$t3,$zero,0x2000
/*  f0d4be0:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f0d4be4:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f0d4be8:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f0d4bec:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0d4bf0:	3c0f0050 */ 	lui	$t7,0x50
/*  f0d4bf4:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0d4bf8:	afad00a0 */ 	sw	$t5,0xa0($sp)
/*  f0d4bfc:	35ef4240 */ 	ori	$t7,$t7,0x4240
/*  f0d4c00:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0d4c04:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0d4c08:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0d4c0c:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0d4c10:	3c08ba00 */ 	lui	$t0,0xba00
/*  f0d4c14:	35081301 */ 	ori	$t0,$t0,0x1301
/*  f0d4c18:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0d4c1c:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0d4c20:	3c090008 */ 	lui	$t1,0x8
/*  f0d4c24:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0d4c28:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0d4c2c:	0fc351a4 */ 	jal	func0f0d4690
/*  f0d4c30:	af080000 */ 	sw	$t0,0x0($t8)
/*  f0d4c34:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0d4c38:	0c005815 */ 	jal	func00016054
/*  f0d4c3c:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0d4c40:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f0d4c44:	3c0c0102 */ 	lui	$t4,0x102
/*  f0d4c48:	358c0040 */ 	ori	$t4,$t4,0x40
/*  f0d4c4c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0d4c50:	afab00a0 */ 	sw	$t3,0xa0($sp)
/*  f0d4c54:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0d4c58:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0d4c5c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d4c60:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f0d4c64:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f0d4c68:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0d4c6c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0d4c70:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0d4c74:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f0d4c78:	03e00008 */ 	jr	$ra
/*  f0d4c7c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d4c80
/*  f0d4c80:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0d4c84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d4c88:	0fc59e66 */ 	jal	func0f167998
/*  f0d4c8c:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0d4c90:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0d4c94:	0fc351a4 */ 	jal	func0f0d4690
/*  f0d4c98:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f0d4c9c:	3c017f1b */ 	lui	$at,%hi(var7f1adbdc)
/*  f0d4ca0:	c42cdbdc */ 	lwc1	$f12,%lo(var7f1adbdc)($at)
/*  f0d4ca4:	0c00577c */ 	jal	func00015df0
/*  f0d4ca8:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f0d4cac:	3c017f1b */ 	lui	$at,%hi(var7f1adbe0)
/*  f0d4cb0:	c42cdbe0 */ 	lwc1	$f12,%lo(var7f1adbe0)($at)
/*  f0d4cb4:	0c005793 */ 	jal	func00015e4c
/*  f0d4cb8:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f0d4cbc:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f0d4cc0:	0c005815 */ 	jal	func00016054
/*  f0d4cc4:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0d4cc8:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f0d4ccc:	3c0e0102 */ 	lui	$t6,0x102
/*  f0d4cd0:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0d4cd4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0d4cd8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0d4cdc:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0d4ce0:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f0d4ce4:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0d4ce8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d4cec:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0d4cf0:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0d4cf4:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0d4cf8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d4cfc:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f0d4d00:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0d4d04:	03e00008 */ 	jr	$ra
/*  f0d4d08:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d4d0c
/*  f0d4d0c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0d4d10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d4d14:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0d4d18:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0d4d1c:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0d4d20:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0d4d24:	0fc59e73 */ 	jal	func0f1679cc
/*  f0d4d28:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0d4d2c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f0d4d30:	0fc59e59 */ 	jal	func0f167964
/*  f0d4d34:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0d4d38:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4d3c:	44819000 */ 	mtc1	$at,$f18
/*  f0d4d40:	3c047f1b */ 	lui	$a0,%hi(var7f1adba0)
/*  f0d4d44:	3c058007 */ 	lui	$a1,%hi(var80070f18)
/*  f0d4d48:	24a50f18 */ 	addiu	$a1,$a1,%lo(var80070f18)
/*  f0d4d4c:	2484dba0 */ 	addiu	$a0,$a0,%lo(var7f1adba0)
/*  f0d4d50:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0d4d54:	e7b20030 */ 	swc1	$f18,0x30($sp)
/*  f0d4d58:	0c0036cc */ 	jal	func0000db30
/*  f0d4d5c:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0d4d60:	3c02800a */ 	lui	$v0,%hi(var8009de90)
/*  f0d4d64:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0d4d68:	8c42de90 */ 	lw	$v0,%lo(var8009de90)($v0)
/*  f0d4d6c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0d4d70:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0d4d74:	0122082a */ 	slt	$at,$t1,$v0
/*  f0d4d78:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f0d4d7c:	10200007 */ 	beqz	$at,.L0f0d4d9c
/*  f0d4d80:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f0d4d84:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d4d88:	01a2082a */ 	slt	$at,$t5,$v0
/*  f0d4d8c:	10200003 */ 	beqz	$at,.L0f0d4d9c
/*  f0d4d90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d4d94:	10000154 */ 	beqz	$zero,.L0f0d52e8
/*  f0d4d98:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d4d9c:
/*  f0d4d9c:	3c03800a */ 	lui	$v1,%hi(var8009de94)
/*  f0d4da0:	8c63de94 */ 	lw	$v1,%lo(var8009de94)($v1)
/*  f0d4da4:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d4da8:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0d4dac:	0069082a */ 	slt	$at,$v1,$t1
/*  f0d4db0:	10200006 */ 	beqz	$at,.L0f0d4dcc
/*  f0d4db4:	3c047f1b */ 	lui	$a0,%hi(var7f1adba8)
/*  f0d4db8:	006d082a */ 	slt	$at,$v1,$t5
/*  f0d4dbc:	50200004 */ 	beqzl	$at,.L0f0d4dd0
/*  f0d4dc0:	0122082a */ 	slt	$at,$t1,$v0
/*  f0d4dc4:	10000148 */ 	beqz	$zero,.L0f0d52e8
/*  f0d4dc8:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d4dcc:
/*  f0d4dcc:	0122082a */ 	slt	$at,$t1,$v0
.L0f0d4dd0:
/*  f0d4dd0:	10200002 */ 	beqz	$at,.L0f0d4ddc
/*  f0d4dd4:	2484dba8 */ 	addiu	$a0,$a0,%lo(var7f1adba8)
/*  f0d4dd8:	00404825 */ 	or	$t1,$v0,$zero
.L0f0d4ddc:
/*  f0d4ddc:	01a2082a */ 	slt	$at,$t5,$v0
/*  f0d4de0:	10200002 */ 	beqz	$at,.L0f0d4dec
/*  f0d4de4:	3c058007 */ 	lui	$a1,%hi(var80070f14)
/*  f0d4de8:	00406825 */ 	or	$t5,$v0,$zero
.L0f0d4dec:
/*  f0d4dec:	0069082a */ 	slt	$at,$v1,$t1
/*  f0d4df0:	10200002 */ 	beqz	$at,.L0f0d4dfc
/*  f0d4df4:	3c028007 */ 	lui	$v0,%hi(var80070f18)
/*  f0d4df8:	00604825 */ 	or	$t1,$v1,$zero
.L0f0d4dfc:
/*  f0d4dfc:	006d082a */ 	slt	$at,$v1,$t5
/*  f0d4e00:	10200002 */ 	beqz	$at,.L0f0d4e0c
/*  f0d4e04:	24a50f14 */ 	addiu	$a1,$a1,%lo(var80070f14)
/*  f0d4e08:	00606825 */ 	or	$t5,$v1,$zero
.L0f0d4e0c:
/*  f0d4e0c:	8c420f18 */ 	lw	$v0,%lo(var80070f18)($v0)
/*  f0d4e10:	01c97821 */ 	addu	$t7,$t6,$t1
/*  f0d4e14:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f0d4e18:	01e20019 */ 	multu	$t7,$v0
/*  f0d4e1c:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0d4e20:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0d4e24:	240e4000 */ 	addiu	$t6,$zero,0x4000
/*  f0d4e28:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d4e2c:	a7a0002a */ 	sh	$zero,0x2a($sp)
/*  f0d4e30:	a7ae0028 */ 	sh	$t6,0x28($sp)
/*  f0d4e34:	00005012 */ 	mflo	$t2
/*  f0d4e38:	000ac400 */ 	sll	$t8,$t2,0x10
/*  f0d4e3c:	00185403 */ 	sra	$t2,$t8,0x10
/*  f0d4e40:	01e20019 */ 	multu	$t7,$v0
/*  f0d4e44:	00005812 */ 	mflo	$t3
/*  f0d4e48:	000bc400 */ 	sll	$t8,$t3,0x10
/*  f0d4e4c:	14e10004 */ 	bne	$a3,$at,.L0f0d4e60
/*  f0d4e50:	00185c03 */ 	sra	$t3,$t8,0x10
/*  f0d4e54:	3c014000 */ 	lui	$at,0x4000
/*  f0d4e58:	44818000 */ 	mtc1	$at,$f16
/*  f0d4e5c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0d4e60:
/*  f0d4e60:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0d4e64:	afa90050 */ 	sw	$t1,0x50($sp)
/*  f0d4e68:	a7aa002e */ 	sh	$t2,0x2e($sp)
/*  f0d4e6c:	a7ab002c */ 	sh	$t3,0x2c($sp)
/*  f0d4e70:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d4e74:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f0d4e78:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0d4e7c:	0c0036cc */ 	jal	func0000db30
/*  f0d4e80:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0d4e84:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0d4e88:	3c014000 */ 	lui	$at,0x4000
/*  f0d4e8c:	44811000 */ 	mtc1	$at,$f2
/*  f0d4e90:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f0d4e94:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0d4e98:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0d4e9c:	87aa002e */ 	lh	$t2,0x2e($sp)
/*  f0d4ea0:	87ab002c */ 	lh	$t3,0x2c($sp)
/*  f0d4ea4:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0d4ea8:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d4eac:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f0d4eb0:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f0d4eb4:	10e20004 */ 	beq	$a3,$v0,.L0f0d4ec8
/*  f0d4eb8:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f0d4ebc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0d4ec0:	54e1000c */ 	bnel	$a3,$at,.L0f0d4ef4
/*  f0d4ec4:	3c014080 */ 	lui	$at,0x4080
.L0f0d4ec8:
/*  f0d4ec8:	14e20004 */ 	bne	$a3,$v0,.L0f0d4edc
/*  f0d4ecc:	3c014080 */ 	lui	$at,0x4080
/*  f0d4ed0:	00005025 */ 	or	$t2,$zero,$zero
/*  f0d4ed4:	10000003 */ 	beqz	$zero,.L0f0d4ee4
/*  f0d4ed8:	240b0400 */ 	addiu	$t3,$zero,0x400
.L0f0d4edc:
/*  f0d4edc:	240a0400 */ 	addiu	$t2,$zero,0x400
/*  f0d4ee0:	240b0800 */ 	addiu	$t3,$zero,0x800
.L0f0d4ee4:
/*  f0d4ee4:	44818000 */ 	mtc1	$at,$f16
/*  f0d4ee8:	24051770 */ 	addiu	$a1,$zero,0x1770
/*  f0d4eec:	46008486 */ 	mov.s	$f18,$f16
/*  f0d4ef0:	3c014080 */ 	lui	$at,0x4080
.L0f0d4ef4:
/*  f0d4ef4:	44810000 */ 	mtc1	$at,$f0
/*  f0d4ef8:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0d4efc:	10e10004 */ 	beq	$a3,$at,.L0f0d4f10
/*  f0d4f00:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0d4f04:	10e10002 */ 	beq	$a3,$at,.L0f0d4f10
/*  f0d4f08:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0d4f0c:	14e10008 */ 	bne	$a3,$at,.L0f0d4f30
.L0f0d4f10:
/*  f0d4f10:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0d4f14:	00005025 */ 	or	$t2,$zero,$zero
/*  f0d4f18:	240b0800 */ 	addiu	$t3,$zero,0x800
/*  f0d4f1c:	240507d0 */ 	addiu	$a1,$zero,0x7d0
/*  f0d4f20:	46000486 */ 	mov.s	$f18,$f0
/*  f0d4f24:	14e10002 */ 	bne	$a3,$at,.L0f0d4f30
/*  f0d4f28:	46000406 */ 	mov.s	$f16,$f0
/*  f0d4f2c:	46001406 */ 	mov.s	$f16,$f2
.L0f0d4f30:
/*  f0d4f30:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0d4f34:	14e10004 */ 	bne	$a3,$at,.L0f0d4f48
/*  f0d4f38:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4f3c:	44818000 */ 	mtc1	$at,$f16
/*  f0d4f40:	240507d0 */ 	addiu	$a1,$zero,0x7d0
/*  f0d4f44:	46008486 */ 	mov.s	$f18,$f16
.L0f0d4f48:
/*  f0d4f48:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0d4f4c:	10e10005 */ 	beq	$a3,$at,.L0f0d4f64
/*  f0d4f50:	3c047f1b */ 	lui	$a0,%hi(var7f1adbb4)
/*  f0d4f54:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0d4f58:	10e10002 */ 	beq	$a3,$at,.L0f0d4f64
/*  f0d4f5c:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f0d4f60:	14ff0013 */ 	bne	$a3,$ra,.L0f0d4fb0
.L0f0d4f64:
/*  f0d4f64:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0d4f68:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f0d4f6c:	240503e8 */ 	addiu	$a1,$zero,0x3e8
/*  f0d4f70:	00005025 */ 	or	$t2,$zero,$zero
/*  f0d4f74:	240b1000 */ 	addiu	$t3,$zero,0x1000
/*  f0d4f78:	14e10006 */ 	bne	$a3,$at,.L0f0d4f94
/*  f0d4f7c:	46000406 */ 	mov.s	$f16,$f0
/*  f0d4f80:	3c014100 */ 	lui	$at,0x4100
/*  f0d4f84:	44818000 */ 	mtc1	$at,$f16
/*  f0d4f88:	240a0180 */ 	addiu	$t2,$zero,0x180
/*  f0d4f8c:	10000008 */ 	beqz	$zero,.L0f0d4fb0
/*  f0d4f90:	240b1180 */ 	addiu	$t3,$zero,0x1180
.L0f0d4f94:
/*  f0d4f94:	14ff0005 */ 	bne	$a3,$ra,.L0f0d4fac
/*  f0d4f98:	3c014100 */ 	lui	$at,0x4100
/*  f0d4f9c:	44818000 */ 	mtc1	$at,$f16
/*  f0d4fa0:	240a0180 */ 	addiu	$t2,$zero,0x180
/*  f0d4fa4:	10000002 */ 	beqz	$zero,.L0f0d4fb0
/*  f0d4fa8:	240b1180 */ 	addiu	$t3,$zero,0x1180
.L0f0d4fac:
/*  f0d4fac:	46001486 */ 	mov.s	$f18,$f2
.L0f0d4fb0:
/*  f0d4fb0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0d4fb4:	14e10020 */ 	bne	$a3,$at,.L0f0d5038
/*  f0d4fb8:	2484dbb4 */ 	addiu	$a0,$a0,%lo(var7f1adbb4)
/*  f0d4fbc:	3c014100 */ 	lui	$at,0x4100
/*  f0d4fc0:	44818000 */ 	mtc1	$at,$f16
/*  f0d4fc4:	3c058007 */ 	lui	$a1,%hi(var80070f1c)
/*  f0d4fc8:	24a50f1c */ 	addiu	$a1,$a1,%lo(var80070f1c)
/*  f0d4fcc:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0d4fd0:	afa90050 */ 	sw	$t1,0x50($sp)
/*  f0d4fd4:	a7aa002e */ 	sh	$t2,0x2e($sp)
/*  f0d4fd8:	a7ab002c */ 	sh	$t3,0x2c($sp)
/*  f0d4fdc:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d4fe0:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f0d4fe4:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0d4fe8:	0c0036cc */ 	jal	func0000db30
/*  f0d4fec:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0d4ff0:	3c058007 */ 	lui	$a1,%hi(var80070f1c)
/*  f0d4ff4:	8ca50f1c */ 	lw	$a1,%lo(var80070f1c)($a1)
/*  f0d4ff8:	24190100 */ 	addiu	$t9,$zero,0x100
/*  f0d4ffc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0d5000:	00052823 */ 	negu	$a1,$a1
/*  f0d5004:	00057c00 */ 	sll	$t7,$a1,0x10
/*  f0d5008:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0d500c:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0d5010:	87aa002e */ 	lh	$t2,0x2e($sp)
/*  f0d5014:	87ab002c */ 	lh	$t3,0x2c($sp)
/*  f0d5018:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0d501c:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d5020:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f0d5024:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f0d5028:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f0d502c:	000f2c03 */ 	sra	$a1,$t7,0x10
/*  f0d5030:	a7b9002a */ 	sh	$t9,0x2a($sp)
/*  f0d5034:	a7a00028 */ 	sh	$zero,0x28($sp)
.L0f0d5038:
/*  f0d5038:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0d503c:	2408fff6 */ 	addiu	$t0,$zero,-10
/*  f0d5040:	a4c90002 */ 	sh	$t1,0x2($a2)
/*  f0d5044:	a4c80004 */ 	sh	$t0,0x4($a2)
/*  f0d5048:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*  f0d504c:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f0d5050:	a4cd000e */ 	sh	$t5,0xe($a2)
/*  f0d5054:	a4c80010 */ 	sh	$t0,0x10($a2)
/*  f0d5058:	3c19800a */ 	lui	$t9,%hi(var8009de98)
/*  f0d505c:	a4cf000c */ 	sh	$t7,0xc($a2)
/*  f0d5060:	8f39de98 */ 	lw	$t9,%lo(var8009de98)($t9)
/*  f0d5064:	44852000 */ 	mtc1	$a1,$f4
/*  f0d5068:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f0d506c:	44994000 */ 	mtc1	$t9,$f8
/*  f0d5070:	44983000 */ 	mtc1	$t8,$f6
/*  f0d5074:	3c0e800a */ 	lui	$t6,%hi(var8009de9c)
/*  f0d5078:	8dcede9c */ 	lw	$t6,%lo(var8009de9c)($t6)
/*  f0d507c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0d5080:	84d9000c */ 	lh	$t9,0xc($a2)
/*  f0d5084:	01051023 */ 	subu	$v0,$t0,$a1
/*  f0d5088:	a4c2001c */ 	sh	$v0,0x1c($a2)
/*  f0d508c:	a4c20028 */ 	sh	$v0,0x28($a2)
/*  f0d5090:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d5094:	3c014280 */ 	lui	$at,0x4280
/*  f0d5098:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0d509c:	448e3000 */ 	mtc1	$t6,$f6
/*  f0d50a0:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d50a4:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0d50a8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d50ac:	46022303 */ 	div.s	$f12,$f4,$f2
/*  f0d50b0:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0d50b4:	46025383 */ 	div.s	$f14,$f10,$f2
/*  f0d50b8:	4600610d */ 	trunc.w.s	$f4,$f12
/*  f0d50bc:	44032000 */ 	mfc1	$v1,$f4
/*  f0d50c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d50c4:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0d50c8:	a4cf0018 */ 	sh	$t7,0x18($a2)
/*  f0d50cc:	84cf0002 */ 	lh	$t7,0x2($a2)
/*  f0d50d0:	03237021 */ 	addu	$t6,$t9,$v1
/*  f0d50d4:	a4ce0024 */ 	sh	$t6,0x24($a2)
/*  f0d50d8:	4600718d */ 	trunc.w.s	$f6,$f14
/*  f0d50dc:	44043000 */ 	mfc1	$a0,$f6
/*  f0d50e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d50e4:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0d50e8:	84cf000e */ 	lh	$t7,0xe($a2)
/*  f0d50ec:	a4d8001a */ 	sh	$t8,0x1a($a2)
/*  f0d50f0:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0d50f4:	14ff0012 */ 	bne	$a3,$ra,.L0f0d5140
/*  f0d50f8:	a4d80026 */ 	sh	$t8,0x26($a2)
/*  f0d50fc:	3c014280 */ 	lui	$at,0x4280
/*  f0d5100:	44811000 */ 	mtc1	$at,$f2
/*  f0d5104:	3c014200 */ 	lui	$at,0x4200
/*  f0d5108:	44816000 */ 	mtc1	$at,$f12
/*  f0d510c:	3c018006 */ 	lui	$at,0x8006
/*  f0d5110:	c4201630 */ 	lwc1	$f0,0x1630($at)
/*  f0d5114:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0d5118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d511c:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d5120:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5124:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0d5128:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d512c:	44093000 */ 	mfc1	$t1,$f6
/*  f0d5130:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5134:	00097400 */ 	sll	$t6,$t1,0x10
/*  f0d5138:	10000014 */ 	beqz	$zero,.L0f0d518c
/*  f0d513c:	000e4c03 */ 	sra	$t1,$t6,0x10
.L0f0d5140:
/*  f0d5140:	44811000 */ 	mtc1	$at,$f2
/*  f0d5144:	3c014200 */ 	lui	$at,0x4200
/*  f0d5148:	44816000 */ 	mtc1	$at,$f12
/*  f0d514c:	3c018006 */ 	lui	$at,0x8006
/*  f0d5150:	c4201630 */ 	lwc1	$f0,0x1630($at)
/*  f0d5154:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d5158:	44814000 */ 	mtc1	$at,$f8
/*  f0d515c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5160:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f0d5164:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0d5168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d516c:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0d5170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5174:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f0d5178:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d517c:	44095000 */ 	mfc1	$t1,$f10
/*  f0d5180:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5184:	0009cc00 */ 	sll	$t9,$t1,0x10
/*  f0d5188:	00194c03 */ 	sra	$t1,$t9,0x10
.L0f0d518c:
/*  f0d518c:	14ff0010 */ 	bne	$a3,$ra,.L0f0d51d0
/*  f0d5190:	01491021 */ 	addu	$v0,$t2,$t1
/*  f0d5194:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d5198:	44812000 */ 	mtc1	$at,$f4
/*  f0d519c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d51a0:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0d51a4:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0d51a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d51ac:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d51b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d51b4:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0d51b8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d51bc:	44053000 */ 	mfc1	$a1,$f6
/*  f0d51c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d51c4:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f0d51c8:	1000000b */ 	beqz	$zero,.L0f0d51f8
/*  f0d51cc:	00182c03 */ 	sra	$a1,$t8,0x10
.L0f0d51d0:
/*  f0d51d0:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0d51d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d51d8:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d51dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d51e0:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0d51e4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d51e8:	44053000 */ 	mfc1	$a1,$f6
/*  f0d51ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d51f0:	00057c00 */ 	sll	$t7,$a1,0x10
/*  f0d51f4:	000f2c03 */ 	sra	$a1,$t7,0x10
.L0f0d51f8:
/*  f0d51f8:	a4c20008 */ 	sh	$v0,0x8($a2)
/*  f0d51fc:	87b9002a */ 	lh	$t9,0x2a($sp)
/*  f0d5200:	01692021 */ 	addu	$a0,$t3,$t1
/*  f0d5204:	a4c40014 */ 	sh	$a0,0x14($a2)
/*  f0d5208:	03251821 */ 	addu	$v1,$t9,$a1
/*  f0d520c:	a4c3000a */ 	sh	$v1,0xa($a2)
/*  f0d5210:	a4c30016 */ 	sh	$v1,0x16($a2)
/*  f0d5214:	a4c4002c */ 	sh	$a0,0x2c($a2)
/*  f0d5218:	87ae0028 */ 	lh	$t6,0x28($sp)
/*  f0d521c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0d5220:	a4c20020 */ 	sh	$v0,0x20($a2)
/*  f0d5224:	01c54021 */ 	addu	$t0,$t6,$a1
/*  f0d5228:	a4c8002e */ 	sh	$t0,0x2e($a2)
/*  f0d522c:	14e10007 */ 	bne	$a3,$at,.L0f0d524c
/*  f0d5230:	a4c80022 */ 	sh	$t0,0x22($a2)
/*  f0d5234:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0d5238:	a0c00007 */ 	sb	$zero,0x7($a2)
/*  f0d523c:	a0c00013 */ 	sb	$zero,0x13($a2)
/*  f0d5240:	a0c2001f */ 	sb	$v0,0x1f($a2)
/*  f0d5244:	10000006 */ 	beqz	$zero,.L0f0d5260
/*  f0d5248:	a0c2002b */ 	sb	$v0,0x2b($a2)
.L0f0d524c:
/*  f0d524c:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0d5250:	a0c00007 */ 	sb	$zero,0x7($a2)
/*  f0d5254:	a0c20013 */ 	sb	$v0,0x13($a2)
/*  f0d5258:	a0c0001f */ 	sb	$zero,0x1f($a2)
/*  f0d525c:	a0c2002b */ 	sb	$v0,0x2b($a2)
.L0f0d5260:
/*  f0d5260:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0d5264:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0d5268:	3c190704 */ 	lui	$t9,0x704
/*  f0d526c:	37390008 */ 	ori	$t9,$t9,0x8
/*  f0d5270:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f0d5274:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0d5278:	01801825 */ 	or	$v1,$t4,$zero
/*  f0d527c:	258c0008 */ 	addiu	$t4,$t4,0x8
/*  f0d5280:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0d5284:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0d5288:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d528c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0d5290:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d5294:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0d5298:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0d529c:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0d52a0:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0d52a4:	3c0e0430 */ 	lui	$t6,0x430
/*  f0d52a8:	35ce0030 */ 	ori	$t6,$t6,0x30
/*  f0d52ac:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0d52b0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f0d52b4:	24ac0008 */ 	addiu	$t4,$a1,0x8
/*  f0d52b8:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d52bc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d52c0:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f0d52c4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0d52c8:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f0d52cc:	3c0fb100 */ 	lui	$t7,0xb100
/*  f0d52d0:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0d52d4:	35ef0003 */ 	ori	$t7,$t7,0x3
/*  f0d52d8:	24182310 */ 	addiu	$t8,$zero,0x2310
/*  f0d52dc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0d52e0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0d52e4:	24620008 */ 	addiu	$v0,$v1,0x8
.L0f0d52e8:
/*  f0d52e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d52ec:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0d52f0:	03e00008 */ 	jr	$ra
/*  f0d52f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel scenarioDefaultCallback44
/*  f0d52f8:	24ce001f */ 	addiu	$t6,$a2,0x1f
/*  f0d52fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d5300:	01cf1004 */ 	sllv	$v0,$t7,$t6
/*  f0d5304:	10400014 */ 	beqz	$v0,.L0f0d5358
/*  f0d5308:	24090007 */ 	addiu	$t1,$zero,0x7
.L0f0d530c:
/*  f0d530c:	0045c024 */ 	and	$t8,$v0,$a1
/*  f0d5310:	5300000c */ 	beqzl	$t8,.L0f0d5344
/*  f0d5314:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f0d5318:	8c860000 */ 	lw	$a2,0x0($a0)
/*  f0d531c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0d5320:	000638c2 */ 	srl	$a3,$a2,0x3
/*  f0d5324:	00874021 */ 	addu	$t0,$a0,$a3
/*  f0d5328:	91190004 */ 	lbu	$t9,0x4($t0)
/*  f0d532c:	30c30007 */ 	andi	$v1,$a2,0x7
/*  f0d5330:	01235023 */ 	subu	$t2,$t1,$v1
/*  f0d5334:	014b6804 */ 	sllv	$t5,$t3,$t2
/*  f0d5338:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0d533c:	a10f0004 */ 	sb	$t7,0x4($t0)
/*  f0d5340:	8c8e0000 */ 	lw	$t6,0x0($a0)
.L0f0d5344:
/*  f0d5344:	00025842 */ 	srl	$t3,$v0,0x1
/*  f0d5348:	01601025 */ 	or	$v0,$t3,$zero
/*  f0d534c:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f0d5350:	1560ffee */ 	bnez	$t3,.L0f0d530c
/*  f0d5354:	ac980000 */ 	sw	$t8,0x0($a0)
.L0f0d5358:
/*  f0d5358:	03e00008 */ 	jr	$ra
/*  f0d535c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d5360
/*  f0d5360:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f0d5364:	24ce001f */ 	addiu	$t6,$a2,0x1f
/*  f0d5368:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d536c:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f0d5370:	01cf1004 */ 	sllv	$v0,$t7,$t6
/*  f0d5374:	1040001d */ 	beqz	$v0,.L0f0d53ec
/*  f0d5378:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0d537c:	24080007 */ 	addiu	$t0,$zero,0x7
.L0f0d5380:
/*  f0d5380:	8c850000 */ 	lw	$a1,0x0($a0)
/*  f0d5384:	0050c024 */ 	and	$t8,$v0,$s0
/*  f0d5388:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0d538c:	30a30007 */ 	andi	$v1,$a1,0x7
/*  f0d5390:	13000008 */ 	beqz	$t8,.L0f0d53b4
/*  f0d5394:	000530c2 */ 	srl	$a2,$a1,0x3
/*  f0d5398:	00e62821 */ 	addu	$a1,$a3,$a2
/*  f0d539c:	90b90000 */ 	lbu	$t9,0x0($a1)
/*  f0d53a0:	01034823 */ 	subu	$t1,$t0,$v1
/*  f0d53a4:	012a6004 */ 	sllv	$t4,$t2,$t1
/*  f0d53a8:	032c6825 */ 	or	$t5,$t9,$t4
/*  f0d53ac:	10000009 */ 	beqz	$zero,.L0f0d53d4
/*  f0d53b0:	a0ad0000 */ 	sb	$t5,0x0($a1)
.L0f0d53b4:
/*  f0d53b4:	00e62821 */ 	addu	$a1,$a3,$a2
/*  f0d53b8:	90af0000 */ 	lbu	$t7,0x0($a1)
/*  f0d53bc:	01037023 */ 	subu	$t6,$t0,$v1
/*  f0d53c0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d53c4:	01d84804 */ 	sllv	$t1,$t8,$t6
/*  f0d53c8:	01205827 */ 	nor	$t3,$t1,$zero
/*  f0d53cc:	01ebc824 */ 	and	$t9,$t7,$t3
/*  f0d53d0:	a0b90000 */ 	sb	$t9,0x0($a1)
.L0f0d53d4:
/*  f0d53d4:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*  f0d53d8:	0002c042 */ 	srl	$t8,$v0,0x1
/*  f0d53dc:	03001025 */ 	or	$v0,$t8,$zero
/*  f0d53e0:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0d53e4:	1700ffe6 */ 	bnez	$t8,.L0f0d5380
/*  f0d53e8:	ac8d0000 */ 	sw	$t5,0x0($a0)
.L0f0d53ec:
/*  f0d53ec:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f0d53f0:	03e00008 */ 	jr	$ra
/*  f0d53f4:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel scenarioDefaultCallback40
/*  f0d53f8:	24ae001f */ 	addiu	$t6,$a1,0x1f
/*  f0d53fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d5400:	01cf1004 */ 	sllv	$v0,$t7,$t6
/*  f0d5404:	10400013 */ 	beqz	$v0,.L0f0d5454
/*  f0d5408:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d540c:	24080007 */ 	addiu	$t0,$zero,0x7
.L0f0d5410:
/*  f0d5410:	8c850000 */ 	lw	$a1,0x0($a0)
/*  f0d5414:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0d5418:	00027042 */ 	srl	$t6,$v0,0x1
/*  f0d541c:	000538c2 */ 	srl	$a3,$a1,0x3
/*  f0d5420:	0087c021 */ 	addu	$t8,$a0,$a3
/*  f0d5424:	30a30007 */ 	andi	$v1,$a1,0x7
/*  f0d5428:	93190004 */ 	lbu	$t9,0x4($t8)
/*  f0d542c:	01034823 */ 	subu	$t1,$t0,$v1
/*  f0d5430:	012a5804 */ 	sllv	$t3,$t2,$t1
/*  f0d5434:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f0d5438:	032c6824 */ 	and	$t5,$t9,$t4
/*  f0d543c:	11a00002 */ 	beqz	$t5,.L0f0d5448
/*  f0d5440:	24af0001 */ 	addiu	$t7,$a1,0x1
/*  f0d5444:	00c23025 */ 	or	$a2,$a2,$v0
.L0f0d5448:
/*  f0d5448:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0d544c:	15c0fff0 */ 	bnez	$t6,.L0f0d5410
/*  f0d5450:	ac8f0000 */ 	sw	$t7,0x0($a0)
.L0f0d5454:
/*  f0d5454:	03e00008 */ 	jr	$ra
/*  f0d5458:	00c01025 */ 	or	$v0,$a2,$zero
);

GLOBAL_ASM(
glabel func0f0d545c
/*  f0d545c:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0d5460:	00801825 */ 	or	$v1,$a0,$zero
/*  f0d5464:	240400dc */ 	addiu	$a0,$zero,0xdc
/*  f0d5468:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d546c:
/*  f0d546c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d5470:	a0600004 */ 	sb	$zero,0x4($v1)
/*  f0d5474:	1444fffd */ 	bne	$v0,$a0,.L0f0d546c
/*  f0d5478:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0d547c:	03e00008 */ 	jr	$ra
/*  f0d5480:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d5484
/*  f0d5484:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f0d5488:	30c300ff */ 	andi	$v1,$a2,0xff
/*  f0d548c:	00a03825 */ 	or	$a3,$a1,$zero
/*  f0d5490:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0d5494:	18600009 */ 	blez	$v1,.L0f0d54bc
/*  f0d5498:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d549c:	00802825 */ 	or	$a1,$a0,$zero
/*  f0d54a0:	00e03025 */ 	or	$a2,$a3,$zero
.L0f0d54a4:
/*  f0d54a4:	90cf0000 */ 	lbu	$t7,0x0($a2)
/*  f0d54a8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d54ac:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0d54b0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0d54b4:	1443fffb */ 	bne	$v0,$v1,.L0f0d54a4
/*  f0d54b8:	a0af0003 */ 	sb	$t7,0x3($a1)
.L0f0d54bc:
/*  f0d54bc:	03e00008 */ 	jr	$ra
/*  f0d54c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d54c4
/*  f0d54c4:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f0d54c8:	00601025 */ 	or	$v0,$v1,$zero
/*  f0d54cc:	04410003 */ 	bgez	$v0,.L0f0d54dc
/*  f0d54d0:	000270c3 */ 	sra	$t6,$v0,0x3
/*  f0d54d4:	24410007 */ 	addiu	$at,$v0,0x7
/*  f0d54d8:	000170c3 */ 	sra	$t6,$at,0x3
.L0f0d54dc:
/*  f0d54dc:	03e00008 */ 	jr	$ra
/*  f0d54e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d54e4
/*  f0d54e4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0d54e8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0d54ec:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0d54f0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0d54f4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0d54f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0d54fc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d5500:	00809825 */ 	or	$s3,$a0,$zero
/*  f0d5504:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f0d5508:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d550c:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f0d5510:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d5514:	00009025 */ 	or	$s2,$zero,$zero
/*  f0d5518:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d551c:	2414000a */ 	addiu	$s4,$zero,0xa
/*  f0d5520:	02602025 */ 	or	$a0,$s3,$zero
.L0f0d5524:
/*  f0d5524:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f0d5528:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0d552c:	56200008 */ 	bnezl	$s1,.L0f0d5550
/*  f0d5530:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0d5534:	14400003 */ 	bnez	$v0,.L0f0d5544
/*  f0d5538:	02b07021 */ 	addu	$t6,$s5,$s0
/*  f0d553c:	10000003 */ 	beqz	$zero,.L0f0d554c
/*  f0d5540:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0d5544:
/*  f0d5544:	a1c20000 */ 	sb	$v0,0x0($t6)
/*  f0d5548:	02009025 */ 	or	$s2,$s0,$zero
.L0f0d554c:
/*  f0d554c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0d5550:
/*  f0d5550:	5614fff4 */ 	bnel	$s0,$s4,.L0f0d5524
/*  f0d5554:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d5558:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0d555c:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f0d5560:	51e00005 */ 	beqzl	$t7,.L0f0d5578
/*  f0d5564:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0d5568:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0d556c:	02b2c821 */ 	addu	$t9,$s5,$s2
/*  f0d5570:	a3380000 */ 	sb	$t8,0x0($t9)
/*  f0d5574:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0d5578:
/*  f0d5578:	02b24021 */ 	addu	$t0,$s5,$s2
/*  f0d557c:	a1000000 */ 	sb	$zero,0x0($t0)
/*  f0d5580:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d5584:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0d5588:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0d558c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0d5590:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0d5594:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0d5598:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0d559c:	03e00008 */ 	jr	$ra
/*  f0d55a0:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0d55a4
/*  f0d55a4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0d55a8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0d55ac:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0d55b0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0d55b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0d55b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0d55bc:	00809025 */ 	or	$s2,$a0,$zero
/*  f0d55c0:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0d55c4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d55c8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d55cc:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d55d0:	2413000a */ 	addiu	$s3,$zero,0xa
.L0f0d55d4:
/*  f0d55d4:	1600000d */ 	bnez	$s0,.L0f0d560c
/*  f0d55d8:	02917021 */ 	addu	$t6,$s4,$s1
/*  f0d55dc:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f0d55e0:	14400003 */ 	bnez	$v0,.L0f0d55f0
/*  f0d55e4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0d55e8:	10000008 */ 	beqz	$zero,.L0f0d560c
/*  f0d55ec:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d55f0:
/*  f0d55f0:	16630003 */ 	bne	$s3,$v1,.L0f0d5600
/*  f0d55f4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0d55f8:	10000004 */ 	beqz	$zero,.L0f0d560c
/*  f0d55fc:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d5600:
/*  f0d5600:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d5604:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f0d5608:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f0d560c:
/*  f0d560c:	12000004 */ 	beqz	$s0,.L0f0d5620
/*  f0d5610:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d5614:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d5618:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f0d561c:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f0d5620:
/*  f0d5620:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d5624:	1633ffeb */ 	bne	$s1,$s3,.L0f0d55d4
/*  f0d5628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d562c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d5630:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0d5634:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0d5638:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0d563c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0d5640:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0d5644:	03e00008 */ 	jr	$ra
/*  f0d5648:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0d564c
/*  f0d564c:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f0d5650:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f0d5654:	00802825 */ 	or	$a1,$a0,$zero
/*  f0d5658:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d565c:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f0d5660:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f0d5664:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0d5668:	0fc35521 */ 	jal	func0f0d5484
/*  f0d566c:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f0d5670:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f0d5674:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f0d5678:	0fc35539 */ 	jal	func0f0d54e4
/*  f0d567c:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0d5680:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d5684:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f0d5688:	03e00008 */ 	jr	$ra
/*  f0d568c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d5690
/*  f0d5690:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f0d5694:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0d5698:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0d569c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0d56a0:	00809025 */ 	or	$s2,$a0,$zero
/*  f0d56a4:	27b30048 */ 	addiu	$s3,$sp,0x48
/*  f0d56a8:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f0d56ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d56b0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d56b4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0d56b8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0d56bc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d56c0:	02402825 */ 	or	$a1,$s2,$zero
/*  f0d56c4:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d56c8:	0fc35521 */ 	jal	func0f0d5484
/*  f0d56cc:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0d56d0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d56d4:	2414000a */ 	addiu	$s4,$zero,0xa
.L0f0d56d8:
/*  f0d56d8:	1600000e */ 	bnez	$s0,.L0f0d5714
/*  f0d56dc:	02b17021 */ 	addu	$t6,$s5,$s1
/*  f0d56e0:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f0d56e4:	14400003 */ 	bnez	$v0,.L0f0d56f4
/*  f0d56e8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0d56ec:	10000009 */ 	beqz	$zero,.L0f0d5714
/*  f0d56f0:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d56f4:
/*  f0d56f4:	16830003 */ 	bne	$s4,$v1,.L0f0d5704
/*  f0d56f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0d56fc:	10000005 */ 	beqz	$zero,.L0f0d5714
/*  f0d5700:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d5704:
/*  f0d5704:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d5708:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d570c:	0fc354d8 */ 	jal	func0f0d5360
/*  f0d5710:	02403825 */ 	or	$a3,$s2,$zero
.L0f0d5714:
/*  f0d5714:	12000005 */ 	beqz	$s0,.L0f0d572c
/*  f0d5718:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d571c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d5720:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d5724:	0fc354d8 */ 	jal	func0f0d5360
/*  f0d5728:	02403825 */ 	or	$a3,$s2,$zero
.L0f0d572c:
/*  f0d572c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d5730:	1634ffe9 */ 	bne	$s1,$s4,.L0f0d56d8
/*  f0d5734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5738:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d573c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0d5740:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0d5744:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0d5748:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0d574c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0d5750:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0d5754:	03e00008 */ 	jr	$ra
/*  f0d5758:	27bd0128 */ 	addiu	$sp,$sp,0x128
);

GLOBAL_ASM(
glabel func0f0d575c
/*  f0d575c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0d5760:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d5764:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0d5768:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0d576c:	8ca50000 */ 	lw	$a1,0x0($a1)
/*  f0d5770:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f0d5774:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f0d5778:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f0d577c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0d5780:	2406000d */ 	addiu	$a2,$zero,0xd
/*  f0d5784:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f0d5788:	95e50004 */ 	lhu	$a1,0x4($t7)
/*  f0d578c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d5790:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0d5794:	03e00008 */ 	jr	$ra
/*  f0d5798:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d579c
/*  f0d579c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0d57a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d57a4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0d57a8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0d57ac:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f0d57b0:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f0d57b4:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f0d57b8:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f0d57bc:	adc20000 */ 	sw	$v0,0x0($t6)
/*  f0d57c0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f0d57c4:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0d57c8:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f0d57cc:	a5e20004 */ 	sh	$v0,0x4($t7)
/*  f0d57d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d57d4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0d57d8:	03e00008 */ 	jr	$ra
/*  f0d57dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel formatTime
/*  f0d57e0:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0d57e4:	00a2001a */ 	div	$zero,$a1,$v0
/*  f0d57e8:	00007010 */ 	mfhi	$t6
/*  f0d57ec:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0d57f0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0d57f4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0d57f8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0d57fc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0d5800:	01e2001a */ 	div	$zero,$t7,$v0
/*  f0d5804:	0000c012 */ 	mflo	$t8
/*  f0d5808:	240a0018 */ 	addiu	$t2,$zero,0x18
/*  f0d580c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0d5810:	00a2001a */ 	div	$zero,$a1,$v0
/*  f0d5814:	00001812 */ 	mflo	$v1
/*  f0d5818:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0d581c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0d5820:	0062001a */ 	div	$zero,$v1,$v0
/*  f0d5824:	00003812 */ 	mflo	$a3
/*  f0d5828:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0d582c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0d5830:	00e2001a */ 	div	$zero,$a3,$v0
/*  f0d5834:	00004012 */ 	mflo	$t0
/*  f0d5838:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0d583c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0d5840:	010a001a */ 	div	$zero,$t0,$t2
/*  f0d5844:	0000c812 */ 	mflo	$t9
/*  f0d5848:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d584c:	00809825 */ 	or	$s3,$a0,$zero
/*  f0d5850:	0062001a */ 	div	$zero,$v1,$v0
/*  f0d5854:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0d5858:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0d585c:	00009025 */ 	or	$s2,$zero,$zero
/*  f0d5860:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d5864:	14400002 */ 	bnez	$v0,.L0f0d5870
/*  f0d5868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d586c:	0007000d */ 	break	0x7
.L0f0d5870:
/*  f0d5870:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5874:	14410004 */ 	bne	$v0,$at,.L0f0d5888
/*  f0d5878:	3c018000 */ 	lui	$at,0x8000
/*  f0d587c:	14a10002 */ 	bne	$a1,$at,.L0f0d5888
/*  f0d5880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5884:	0006000d */ 	break	0x6
.L0f0d5888:
/*  f0d5888:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f0d588c:	14400002 */ 	bnez	$v0,.L0f0d5898
/*  f0d5890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5894:	0007000d */ 	break	0x7
.L0f0d5898:
/*  f0d5898:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d589c:	14410004 */ 	bne	$v0,$at,.L0f0d58b0
/*  f0d58a0:	3c018000 */ 	lui	$at,0x8000
/*  f0d58a4:	15e10002 */ 	bne	$t7,$at,.L0f0d58b0
/*  f0d58a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d58ac:	0006000d */ 	break	0x6
.L0f0d58b0:
/*  f0d58b0:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f0d58b4:	14400002 */ 	bnez	$v0,.L0f0d58c0
/*  f0d58b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d58bc:	0007000d */ 	break	0x7
.L0f0d58c0:
/*  f0d58c0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d58c4:	14410004 */ 	bne	$v0,$at,.L0f0d58d8
/*  f0d58c8:	3c018000 */ 	lui	$at,0x8000
/*  f0d58cc:	14a10002 */ 	bne	$a1,$at,.L0f0d58d8
/*  f0d58d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d58d4:	0006000d */ 	break	0x6
.L0f0d58d8:
/*  f0d58d8:	27b10054 */ 	addiu	$s1,$sp,0x54
/*  f0d58dc:	14400002 */ 	bnez	$v0,.L0f0d58e8
/*  f0d58e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d58e4:	0007000d */ 	break	0x7
.L0f0d58e8:
/*  f0d58e8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d58ec:	14410004 */ 	bne	$v0,$at,.L0f0d5900
/*  f0d58f0:	3c018000 */ 	lui	$at,0x8000
/*  f0d58f4:	14610002 */ 	bne	$v1,$at,.L0f0d5900
/*  f0d58f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d58fc:	0006000d */ 	break	0x6
.L0f0d5900:
/*  f0d5900:	3c147f1b */ 	lui	$s4,%hi(var7f1adbbc)
/*  f0d5904:	14400002 */ 	bnez	$v0,.L0f0d5910
/*  f0d5908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d590c:	0007000d */ 	break	0x7
.L0f0d5910:
/*  f0d5910:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5914:	14410004 */ 	bne	$v0,$at,.L0f0d5928
/*  f0d5918:	3c018000 */ 	lui	$at,0x8000
/*  f0d591c:	14e10002 */ 	bne	$a3,$at,.L0f0d5928
/*  f0d5920:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5924:	0006000d */ 	break	0x6
.L0f0d5928:
/*  f0d5928:	27b5005c */ 	addiu	$s5,$sp,0x5c
/*  f0d592c:	15400002 */ 	bnez	$t2,.L0f0d5938
/*  f0d5930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5934:	0007000d */ 	break	0x7
.L0f0d5938:
/*  f0d5938:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d593c:	15410004 */ 	bne	$t2,$at,.L0f0d5950
/*  f0d5940:	3c018000 */ 	lui	$at,0x8000
/*  f0d5944:	15010002 */ 	bne	$t0,$at,.L0f0d5950
/*  f0d5948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d594c:	0006000d */ 	break	0x6
.L0f0d5950:
/*  f0d5950:	3c167f1b */ 	lui	$s6,%hi(var7f1adbc4)
/*  f0d5954:	14400002 */ 	bnez	$v0,.L0f0d5960
/*  f0d5958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d595c:	0007000d */ 	break	0x7
.L0f0d5960:
/*  f0d5960:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5964:	14410004 */ 	bne	$v0,$at,.L0f0d5978
/*  f0d5968:	3c018000 */ 	lui	$at,0x8000
/*  f0d596c:	14610002 */ 	bne	$v1,$at,.L0f0d5978
/*  f0d5970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5974:	0006000d */ 	break	0x6
.L0f0d5978:
/*  f0d5978:	00001810 */ 	mfhi	$v1
/*  f0d597c:	afa30060 */ 	sw	$v1,0x60($sp)
/*  f0d5980:	27ad0054 */ 	addiu	$t5,$sp,0x54
/*  f0d5984:	00e2001a */ 	div	$zero,$a3,$v0
/*  f0d5988:	14400002 */ 	bnez	$v0,.L0f0d5994
/*  f0d598c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5990:	0007000d */ 	break	0x7
.L0f0d5994:
/*  f0d5994:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5998:	14410004 */ 	bne	$v0,$at,.L0f0d59ac
/*  f0d599c:	3c018000 */ 	lui	$at,0x8000
/*  f0d59a0:	14e10002 */ 	bne	$a3,$at,.L0f0d59ac
/*  f0d59a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d59a8:	0006000d */ 	break	0x6
.L0f0d59ac:
/*  f0d59ac:	00003810 */ 	mfhi	$a3
/*  f0d59b0:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0d59b4:	00004825 */ 	or	$t1,$zero,$zero
/*  f0d59b8:	010a001a */ 	div	$zero,$t0,$t2
/*  f0d59bc:	15400002 */ 	bnez	$t2,.L0f0d59c8
/*  f0d59c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d59c4:	0007000d */ 	break	0x7
.L0f0d59c8:
/*  f0d59c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d59cc:	15410004 */ 	bne	$t2,$at,.L0f0d59e0
/*  f0d59d0:	3c018000 */ 	lui	$at,0x8000
/*  f0d59d4:	15010002 */ 	bne	$t0,$at,.L0f0d59e0
/*  f0d59d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d59dc:	0006000d */ 	break	0x6
.L0f0d59e0:
/*  f0d59e0:	00004010 */ 	mfhi	$t0
/*  f0d59e4:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f0d59e8:	04c00019 */ 	bltz	$a2,.L0f0d5a50
/*  f0d59ec:	00065880 */ 	sll	$t3,$a2,0x2
/*  f0d59f0:	256c0004 */ 	addiu	$t4,$t3,0x4
/*  f0d59f4:	018db821 */ 	addu	$s7,$t4,$t5
/*  f0d59f8:	26d6dbc4 */ 	addiu	$s6,$s6,%lo(var7f1adbc4)
/*  f0d59fc:	2694dbbc */ 	addiu	$s4,$s4,%lo(var7f1adbbc)
.L0f0d5a00:
/*  f0d5a00:	12400006 */ 	beqz	$s2,.L0f0d5a1c
/*  f0d5a04:	02702021 */ 	addu	$a0,$s3,$s0
/*  f0d5a08:	02802825 */ 	or	$a1,$s4,$zero
/*  f0d5a0c:	0c004dad */ 	jal	sprintf
/*  f0d5a10:	8e260000 */ 	lw	$a2,0x0($s1)
/*  f0d5a14:	1000000b */ 	beqz	$zero,.L0f0d5a44
/*  f0d5a18:	02028021 */ 	addu	$s0,$s0,$v0
.L0f0d5a1c:
/*  f0d5a1c:	8e260000 */ 	lw	$a2,0x0($s1)
/*  f0d5a20:	0235082b */ 	sltu	$at,$s1,$s5
/*  f0d5a24:	02702021 */ 	addu	$a0,$s3,$s0
/*  f0d5a28:	14c00003 */ 	bnez	$a2,.L0f0d5a38
/*  f0d5a2c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0d5a30:	54200005 */ 	bnezl	$at,.L0f0d5a48
/*  f0d5a34:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f0d5a38:
/*  f0d5a38:	0c004dad */ 	jal	sprintf
/*  f0d5a3c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0d5a40:	02028021 */ 	addu	$s0,$s0,$v0
.L0f0d5a44:
/*  f0d5a44:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f0d5a48:
/*  f0d5a48:	16f1ffed */ 	bne	$s7,$s1,.L0f0d5a00
/*  f0d5a4c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0d5a50:
/*  f0d5a50:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0d5a54:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0d5a58:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0d5a5c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0d5a60:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0d5a64:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0d5a68:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0d5a6c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0d5a70:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0d5a74:	03e00008 */ 	jr	$ra
/*  f0d5a78:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0d5a7c
/*  f0d5a7c:	3c018007 */ 	lui	$at,0x8007
/*  f0d5a80:	03e00008 */ 	jr	$ra
/*  f0d5a84:	ac200f10 */ 	sw	$zero,0xf10($at)
/*  f0d5a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d5a8c:	00000000 */ 	sll	$zero,$zero,0x0
);
