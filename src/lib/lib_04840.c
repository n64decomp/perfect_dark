#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_04840.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

const u32 var700524b0[] = {0x3c8efa35};
const u32 var700524b4[] = {0x00000000};
const u32 var700524b8[] = {0x00000000};
const u32 var700524bc[] = {0x00000000};

GLOBAL_ASM(
glabel func00004840
/*     4840:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     4844:	44867000 */ 	mtc1	$a2,$f14
/*     4848:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     484c:	afa50034 */ 	sw	$a1,0x34($sp)
/*     4850:	afa7003c */ 	sw	$a3,0x3c($sp)
/*     4854:	afa50034 */ 	sw	$a1,0x34($sp)
/*     4858:	afa40030 */ 	sw	$a0,0x30($sp)
/*     485c:	0c012918 */ 	jal	func0004a460
/*     4860:	e7ae0038 */ 	swc1	$f14,0x38($sp)
/*     4864:	3c017005 */ 	lui	$at,%hi(var700524b0)
/*     4868:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*     486c:	c42424b0 */ 	lwc1	$f4,%lo(var700524b0)($at)
/*     4870:	3c013f00 */ 	lui	$at,0x3f00
/*     4874:	44813000 */ 	mtc1	$at,$f6
/*     4878:	46047382 */ 	mul.s	$f14,$f14,$f4
/*     487c:	00000000 */ 	sll	$zero,$zero,0x0
/*     4880:	46067302 */ 	mul.s	$f12,$f14,$f6
/*     4884:	0c0068f4 */ 	jal	cosf
/*     4888:	e7ac001c */ 	swc1	$f12,0x1c($sp)
/*     488c:	c7ac001c */ 	lwc1	$f12,0x1c($sp)
/*     4890:	0c0068f7 */ 	jal	sinf
/*     4894:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*     4898:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*     489c:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*     48a0:	c7ac0040 */ 	lwc1	$f12,0x40($sp)
/*     48a4:	46004083 */ 	div.s	$f2,$f8,$f0
/*     48a8:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*     48ac:	8fa60030 */ 	lw	$a2,0x30($sp)
/*     48b0:	8fa70034 */ 	lw	$a3,0x34($sp)
/*     48b4:	46106480 */ 	add.s	$f18,$f12,$f16
/*     48b8:	3c01bf80 */ 	lui	$at,0xbf80
/*     48bc:	44814000 */ 	mtc1	$at,$f8
/*     48c0:	46106381 */ 	sub.s	$f14,$f12,$f16
/*     48c4:	00002825 */ 	or	$a1,$zero,$zero
/*     48c8:	e4c8002c */ 	swc1	$f8,0x2c($a2)
/*     48cc:	44804000 */ 	mtc1	$zero,$f8
/*     48d0:	24040004 */ 	addiu	$a0,$zero,0x4
/*     48d4:	e4c8003c */ 	swc1	$f8,0x3c($a2)
/*     48d8:	460e9183 */ 	div.s	$f6,$f18,$f14
/*     48dc:	e4c20014 */ 	swc1	$f2,0x14($a2)
/*     48e0:	460a1103 */ 	div.s	$f4,$f2,$f10
/*     48e4:	e4c60028 */ 	swc1	$f6,0x28($a2)
/*     48e8:	460c6280 */ 	add.s	$f10,$f12,$f12
/*     48ec:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*     48f0:	46105102 */ 	mul.s	$f4,$f10,$f16
/*     48f4:	460e2183 */ 	div.s	$f6,$f4,$f14
/*     48f8:	e4c60038 */ 	swc1	$f6,0x38($a2)
/*     48fc:	c7a00048 */ 	lwc1	$f0,0x48($sp)
.L00004900:
/*     4900:	00001825 */ 	or	$v1,$zero,$zero
/*     4904:	00c01025 */ 	or	$v0,$a2,$zero
/*     4908:	c44e0000 */ 	lwc1	$f14,0x0($v0)
/*     490c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     4910:	46007402 */ 	mul.s	$f16,$f14,$f0
/*     4914:	50640008 */ 	beql	$v1,$a0,.L00004938
/*     4918:	24420004 */ 	addiu	$v0,$v0,0x4
.L0000491c:
/*     491c:	c44e0004 */ 	lwc1	$f14,0x4($v0)
/*     4920:	24630001 */ 	addiu	$v1,$v1,0x1
/*     4924:	e4500000 */ 	swc1	$f16,0x0($v0)
/*     4928:	46007402 */ 	mul.s	$f16,$f14,$f0
/*     492c:	1464fffb */ 	bne	$v1,$a0,.L0000491c
/*     4930:	24420004 */ 	addiu	$v0,$v0,0x4
/*     4934:	24420004 */ 	addiu	$v0,$v0,0x4
.L00004938:
/*     4938:	e450fffc */ 	swc1	$f16,-0x4($v0)
/*     493c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     4940:	14a4ffef */ 	bne	$a1,$a0,.L00004900
/*     4944:	24c60010 */ 	addiu	$a2,$a2,0x10
/*     4948:	10e00032 */ 	beqz	$a3,.L00004a14
/*     494c:	3c014000 */ 	lui	$at,0x4000
/*     4950:	44813000 */ 	mtc1	$at,$f6
/*     4954:	340effff */ 	dli	$t6,0xffff
/*     4958:	3c014800 */ 	lui	$at,0x4800
/*     495c:	4606903e */ 	c.le.s	$f18,$f6
/*     4960:	00000000 */ 	sll	$zero,$zero,0x0
/*     4964:	45020004 */ 	bc1fl	.L00004978
/*     4968:	44814000 */ 	mtc1	$at,$f8
/*     496c:	10000029 */ 	beqz	$zero,.L00004a14
/*     4970:	a4ee0000 */ 	sh	$t6,0x0($a3)
/*     4974:	44814000 */ 	mtc1	$at,$f8
.L00004978:
/*     4978:	24180001 */ 	addiu	$t8,$zero,0x1
/*     497c:	3c014f00 */ 	lui	$at,0x4f00
/*     4980:	46124283 */ 	div.s	$f10,$f8,$f18
/*     4984:	24080001 */ 	addiu	$t0,$zero,0x1
/*     4988:	444ff800 */ 	cfc1	$t7,$31
/*     498c:	44d8f800 */ 	ctc1	$t8,$31
/*     4990:	00000000 */ 	sll	$zero,$zero,0x0
/*     4994:	46005124 */ 	cvt.w.s	$f4,$f10
/*     4998:	4458f800 */ 	cfc1	$t8,$31
/*     499c:	00000000 */ 	sll	$zero,$zero,0x0
/*     49a0:	33180078 */ 	andi	$t8,$t8,0x78
/*     49a4:	53000013 */ 	beqzl	$t8,.L000049f4
/*     49a8:	44182000 */ 	mfc1	$t8,$f4
/*     49ac:	44812000 */ 	mtc1	$at,$f4
/*     49b0:	24180001 */ 	addiu	$t8,$zero,0x1
/*     49b4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*     49b8:	44d8f800 */ 	ctc1	$t8,$31
/*     49bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     49c0:	46002124 */ 	cvt.w.s	$f4,$f4
/*     49c4:	4458f800 */ 	cfc1	$t8,$31
/*     49c8:	00000000 */ 	sll	$zero,$zero,0x0
/*     49cc:	33180078 */ 	andi	$t8,$t8,0x78
/*     49d0:	17000005 */ 	bnez	$t8,.L000049e8
/*     49d4:	00000000 */ 	sll	$zero,$zero,0x0
/*     49d8:	44182000 */ 	mfc1	$t8,$f4
/*     49dc:	3c018000 */ 	lui	$at,0x8000
/*     49e0:	10000007 */ 	beqz	$zero,.L00004a00
/*     49e4:	0301c025 */ 	or	$t8,$t8,$at
.L000049e8:
/*     49e8:	10000005 */ 	beqz	$zero,.L00004a00
/*     49ec:	2418ffff */ 	addiu	$t8,$zero,-1
/*     49f0:	44182000 */ 	mfc1	$t8,$f4
.L000049f4:
/*     49f4:	00000000 */ 	sll	$zero,$zero,0x0
/*     49f8:	0700fffb */ 	bltz	$t8,.L000049e8
/*     49fc:	00000000 */ 	sll	$zero,$zero,0x0
.L00004a00:
/*     4a00:	44cff800 */ 	ctc1	$t7,$31
/*     4a04:	3319ffff */ 	andi	$t9,$t8,0xffff
/*     4a08:	1f200002 */ 	bgtz	$t9,.L00004a14
/*     4a0c:	a4f80000 */ 	sh	$t8,0x0($a3)
/*     4a10:	a4e80000 */ 	sh	$t0,0x0($a3)
.L00004a14:
/*     4a14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     4a18:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*     4a1c:	03e00008 */ 	jr	$ra
/*     4a20:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00004a24
/*     4a24:	27bdff98 */ 	addiu	$sp,$sp,-104
/*     4a28:	44866000 */ 	mtc1	$a2,$f12
/*     4a2c:	44877000 */ 	mtc1	$a3,$f14
/*     4a30:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*     4a34:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*     4a38:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*     4a3c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     4a40:	afa40068 */ 	sw	$a0,0x68($sp)
/*     4a44:	44066000 */ 	mfc1	$a2,$f12
/*     4a48:	44077000 */ 	mfc1	$a3,$f14
/*     4a4c:	27a40028 */ 	addiu	$a0,$sp,0x28
/*     4a50:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*     4a54:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*     4a58:	0c001210 */ 	jal	func00004840
/*     4a5c:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*     4a60:	27a40028 */ 	addiu	$a0,$sp,0x28
/*     4a64:	0c0128d8 */ 	jal	func0004a360
/*     4a68:	8fa50068 */ 	lw	$a1,0x68($sp)
/*     4a6c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     4a70:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*     4a74:	03e00008 */ 	jr	$ra
/*     4a78:	00000000 */ 	sll	$zero,$zero,0x0
/*     4a7c:	00000000 */ 	sll	$zero,$zero,0x0
);