#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/game_092610.h"
#include "game/atan2f.h"
#include "game/game_0b3350.h"
#include "game/file.h"
#include "gvars/gvars.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

const u32 var7f1b7390[] = {0xc61c4000};
const u32 var7f1b7394[] = {0x461c4000};
const u32 var7f1b7398[] = {0xc61c4000};
const u32 var7f1b739c[] = {0x461c4000};

Gfx *shardsRenderWood(Gfx *gdl);

GLOBAL_ASM(
glabel shardsRenderWood
/*  f151780:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f151784:	3c0e8008 */ 	lui	$t6,%hi(g_ShardsActive)
/*  f151788:	8dcefa84 */ 	lw	$t6,%lo(g_ShardsActive)($t6)
/*  f15178c:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f151790:	00809825 */ 	or	$s3,$a0,$zero
/*  f151794:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f151798:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f15179c:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f1517a0:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f1517a4:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f1517a8:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f1517ac:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f1517b0:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f1517b4:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f1517b8:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f1517bc:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f1517c0:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f1517c4:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f1517c8:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f1517cc:	11c001ad */ 	beqz	$t6,.L0f151e84
/*  f1517d0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f1517d4:	a7a0012e */ 	sh	$zero,0x12e($sp)
/*  f1517d8:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f1517dc:	3c0fb600 */ 	lui	$t7,0xb600
/*  f1517e0:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f1517e4:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1517e8:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1517ec:	02601825 */ 	or	$v1,$s3,$zero
/*  f1517f0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1517f4:	3c19b700 */ 	lui	$t9,0xb700
/*  f1517f8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1517fc:	24080204 */ 	addiu	$t0,$zero,0x204
/*  f151800:	02602025 */ 	or	$a0,$s3,$zero
/*  f151804:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f151808:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f15180c:	3c09fcff */ 	lui	$t1,0xfcff
/*  f151810:	3c0afffe */ 	lui	$t2,0xfffe
/*  f151814:	354a793c */ 	ori	$t2,$t2,0x793c
/*  f151818:	3529ffff */ 	ori	$t1,$t1,0xffff
/*  f15181c:	02602825 */ 	or	$a1,$s3,$zero
/*  f151820:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f151824:	ac8a0004 */ 	sw	$t2,0x4($a0)
/*  f151828:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f15182c:	3c0bba00 */ 	lui	$t3,0xba00
/*  f151830:	356b0c02 */ 	ori	$t3,$t3,0xc02
/*  f151834:	240c2000 */ 	addiu	$t4,$zero,0x2000
/*  f151838:	02603025 */ 	or	$a2,$s3,$zero
/*  f15183c:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f151840:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f151844:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151848:	3c0dba00 */ 	lui	$t5,0xba00
/*  f15184c:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f151850:	3c0e0010 */ 	lui	$t6,0x10
/*  f151854:	02601025 */ 	or	$v0,$s3,$zero
/*  f151858:	acce0004 */ 	sw	$t6,0x4($a2)
/*  f15185c:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f151860:	3c0fba00 */ 	lui	$t7,0xba00
/*  f151864:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f151868:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f15186c:	3c180001 */ 	lui	$t8,0x1
/*  f151870:	3c190103 */ 	lui	$t9,0x103
/*  f151874:	3c17800a */ 	lui	$s7,%hi(g_Vars)
/*  f151878:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f15187c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f151880:	37390040 */ 	ori	$t9,$t9,0x40
/*  f151884:	02608025 */ 	or	$s0,$s3,$zero
/*  f151888:	26f79fc0 */ 	addiu	$s7,$s7,%lo(g_Vars)
/*  f15188c:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f151890:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f151894:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151898:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15189c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1518a0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f1518a4:	3c08800a */ 	lui	$t0,%hi(g_MaxShards)
/*  f1518a8:	8d0845c0 */ 	lw	$t0,%lo(g_MaxShards)($t0)
/*  f1518ac:	0000f025 */ 	or	$s8,$zero,$zero
/*  f1518b0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1518b4:	19000159 */ 	blez	$t0,.L0f151e1c
/*  f1518b8:	3c014316 */ 	lui	$at,0x4316
/*  f1518bc:	4481f000 */ 	mtc1	$at,$f30
/*  f1518c0:	3c017f1b */ 	lui	$at,%hi(var7f1b7390)
/*  f1518c4:	c43c7390 */ 	lwc1	$f28,%lo(var7f1b7390)($at)
/*  f1518c8:	3c017f1b */ 	lui	$at,%hi(var7f1b7394)
/*  f1518cc:	c43a7394 */ 	lwc1	$f26,%lo(var7f1b7394)($at)
/*  f1518d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1518d4:	3c158008 */ 	lui	$s5,%hi(var8007fa80)
/*  f1518d8:	3c12800a */ 	lui	$s2,%hi(g_Shards)
/*  f1518dc:	4481c000 */ 	mtc1	$at,$f24
/*  f1518e0:	265245c4 */ 	addiu	$s2,$s2,%lo(g_Shards)
/*  f1518e4:	26b5fa80 */ 	addiu	$s5,$s5,%lo(var8007fa80)
/*  f1518e8:	c7b600bc */ 	lwc1	$f22,0xbc($sp)
/*  f1518ec:	2416000c */ 	addiu	$s6,$zero,0xc
/*  f1518f0:	8e490000 */ 	lw	$t1,0x0($s2)
.L0f1518f4:
/*  f1518f4:	01341021 */ 	addu	$v0,$t1,$s4
/*  f1518f8:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*  f1518fc:	1940013f */ 	blez	$t2,.L0f151dfc
/*  f151900:	00000000 */ 	nop
/*  f151904:	904b0068 */ 	lbu	$t3,0x68($v0)
/*  f151908:	24010002 */ 	addiu	$at,$zero,0x2
/*  f15190c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f151910:	1561013a */ 	bne	$t3,$at,.L0f151dfc
/*  f151914:	00000000 */ 	nop
/*  f151918:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f15191c:	4600c506 */ 	mov.s	$f20,$f24
/*  f151920:	8ee30284 */ 	lw	$v1,0x284($s7)
/*  f151924:	24010001 */ 	addiu	$at,$zero,0x1
/*  f151928:	00408825 */ 	or	$s1,$v0,$zero
/*  f15192c:	946c0010 */ 	lhu	$t4,0x10($v1)
/*  f151930:	15810025 */ 	bne	$t4,$at,.L0f1519c8
/*  f151934:	00000000 */ 	nop
/*  f151938:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f15193c:	c46a0018 */ 	lwc1	$f10,0x18($v1)
/*  f151940:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f151944:	01b41021 */ 	addu	$v0,$t5,$s4
/*  f151948:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f15194c:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f151950:	c450000c */ 	lwc1	$f16,0xc($v0)
/*  f151954:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f151958:	c472001c */ 	lwc1	$f18,0x1c($v1)
/*  f15195c:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f151960:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f151964:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f151968:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f15196c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f151970:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f151974:	0c012974 */ 	jal	sqrtf
/*  f151978:	46085300 */ 	add.s	$f12,$f10,$f8
/*  f15197c:	8eee0284 */ 	lw	$t6,0x284($s7)
/*  f151980:	c5c20024 */ 	lwc1	$f2,0x24($t6)
/*  f151984:	4600103c */ 	c.lt.s	$f2,$f0
/*  f151988:	461e1301 */ 	sub.s	$f12,$f2,$f30
/*  f15198c:	45000002 */ 	bc1f	.L0f151998
/*  f151990:	46020583 */ 	div.s	$f22,$f0,$f2
/*  f151994:	00008025 */ 	or	$s0,$zero,$zero
.L0f151998:
/*  f151998:	4600603c */ 	c.lt.s	$f12,$f0
/*  f15199c:	00000000 */ 	nop
/*  f1519a0:	45020005 */ 	bc1fl	.L0f1519b8
/*  f1519a4:	4616c03c */ 	c.lt.s	$f24,$f22
/*  f1519a8:	460c0401 */ 	sub.s	$f16,$f0,$f12
/*  f1519ac:	461e8483 */ 	div.s	$f18,$f16,$f30
/*  f1519b0:	4612c501 */ 	sub.s	$f20,$f24,$f18
/*  f1519b4:	4616c03c */ 	c.lt.s	$f24,$f22
.L0f1519b8:
/*  f1519b8:	00000000 */ 	nop
/*  f1519bc:	45000002 */ 	bc1f	.L0f1519c8
/*  f1519c0:	00000000 */ 	nop
/*  f1519c4:	4600c586 */ 	mov.s	$f22,$f24
.L0f1519c8:
/*  f1519c8:	1200010c */ 	beqz	$s0,.L0f151dfc
/*  f1519cc:	00000000 */ 	nop
/*  f1519d0:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f1519d4:	27a600e8 */ 	addiu	$a2,$sp,0xe8
/*  f1519d8:	01f41021 */ 	addu	$v0,$t7,$s4
/*  f1519dc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f1519e0:	0c0059a9 */ 	jal	func000166a4
/*  f1519e4:	24450014 */ 	addiu	$a1,$v0,0x14
/*  f1519e8:	8ee30284 */ 	lw	$v1,0x284($s7)
/*  f1519ec:	c7a40118 */ 	lwc1	$f4,0x118($sp)
/*  f1519f0:	c7a8011c */ 	lwc1	$f8,0x11c($sp)
/*  f1519f4:	c4660038 */ 	lwc1	$f6,0x38($v1)
/*  f1519f8:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f1519fc:	c7a40120 */ 	lwc1	$f4,0x120($sp)
/*  f151a00:	e7aa0118 */ 	swc1	$f10,0x118($sp)
/*  f151a04:	c470003c */ 	lwc1	$f16,0x3c($v1)
/*  f151a08:	461a503c */ 	c.lt.s	$f10,$f26
/*  f151a0c:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f151a10:	e7b2011c */ 	swc1	$f18,0x11c($sp)
/*  f151a14:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f151a18:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f151a1c:	450000f7 */ 	bc1f	.L0f151dfc
/*  f151a20:	e7a80120 */ 	swc1	$f8,0x120($sp)
/*  f151a24:	460ae03c */ 	c.lt.s	$f28,$f10
/*  f151a28:	00000000 */ 	nop
/*  f151a2c:	450000f3 */ 	bc1f	.L0f151dfc
/*  f151a30:	00000000 */ 	nop
/*  f151a34:	461a903c */ 	c.lt.s	$f18,$f26
/*  f151a38:	00000000 */ 	nop
/*  f151a3c:	450000ef */ 	bc1f	.L0f151dfc
/*  f151a40:	00000000 */ 	nop
/*  f151a44:	4612e03c */ 	c.lt.s	$f28,$f18
/*  f151a48:	00000000 */ 	nop
/*  f151a4c:	450000eb */ 	bc1f	.L0f151dfc
/*  f151a50:	00000000 */ 	nop
/*  f151a54:	461a403c */ 	c.lt.s	$f8,$f26
/*  f151a58:	00000000 */ 	nop
/*  f151a5c:	450000e7 */ 	bc1f	.L0f151dfc
/*  f151a60:	00000000 */ 	nop
/*  f151a64:	4608e03c */ 	c.lt.s	$f28,$f8
/*  f151a68:	27a400e8 */ 	addiu	$a0,$sp,0xe8
/*  f151a6c:	450000e3 */ 	bc1f	.L0f151dfc
/*  f151a70:	00000000 */ 	nop
/*  f151a74:	0c005815 */ 	jal	func00016054
/*  f151a78:	02202825 */ 	or	$a1,$s1,$zero
/*  f151a7c:	3c180102 */ 	lui	$t8,0x102
/*  f151a80:	37180040 */ 	ori	$t8,$t8,0x40
/*  f151a84:	02608025 */ 	or	$s0,$s3,$zero
/*  f151a88:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f151a8c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151a90:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f151a94:	02202025 */ 	or	$a0,$s1,$zero
/*  f151a98:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f151a9c:	8ef90284 */ 	lw	$t9,0x284($s7)
/*  f151aa0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f151aa4:	97280010 */ 	lhu	$t0,0x10($t9)
/*  f151aa8:	150100ad */ 	bne	$t0,$at,.L0f151d60
/*  f151aac:	3c01437f */ 	lui	$at,0x437f
/*  f151ab0:	44818000 */ 	mtc1	$at,$f16
/*  f151ab4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f151ab8:	3c014f00 */ 	lui	$at,0x4f00
/*  f151abc:	4610b102 */ 	mul.s	$f4,$f22,$f16
/*  f151ac0:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f151ac4:	4449f800 */ 	cfc1	$t1,$31
/*  f151ac8:	44d0f800 */ 	ctc1	$s0,$31
/*  f151acc:	00000000 */ 	nop
/*  f151ad0:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f151ad4:	4450f800 */ 	cfc1	$s0,$31
/*  f151ad8:	00000000 */ 	nop
/*  f151adc:	32100078 */ 	andi	$s0,$s0,0x78
/*  f151ae0:	52000013 */ 	beqzl	$s0,.L0f151b30
/*  f151ae4:	44103000 */ 	mfc1	$s0,$f6
/*  f151ae8:	44813000 */ 	mtc1	$at,$f6
/*  f151aec:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f151af0:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f151af4:	44d0f800 */ 	ctc1	$s0,$31
/*  f151af8:	00000000 */ 	nop
/*  f151afc:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f151b00:	4450f800 */ 	cfc1	$s0,$31
/*  f151b04:	00000000 */ 	nop
/*  f151b08:	32100078 */ 	andi	$s0,$s0,0x78
/*  f151b0c:	16000005 */ 	bnez	$s0,.L0f151b24
/*  f151b10:	00000000 */ 	nop
/*  f151b14:	44103000 */ 	mfc1	$s0,$f6
/*  f151b18:	3c018000 */ 	lui	$at,0x8000
/*  f151b1c:	10000007 */ 	b	.L0f151b3c
/*  f151b20:	02018025 */ 	or	$s0,$s0,$at
.L0f151b24:
/*  f151b24:	10000005 */ 	b	.L0f151b3c
/*  f151b28:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f151b2c:	44103000 */ 	mfc1	$s0,$f6
.L0f151b30:
/*  f151b30:	00000000 */ 	nop
/*  f151b34:	0600fffb */ 	bltz	$s0,.L0f151b24
/*  f151b38:	00000000 */ 	nop
.L0f151b3c:
/*  f151b3c:	44c9f800 */ 	ctc1	$t1,$31
/*  f151b40:	3c01437f */ 	lui	$at,0x437f
/*  f151b44:	44819000 */ 	mtc1	$at,$f18
/*  f151b48:	4616c281 */ 	sub.s	$f10,$f24,$f22
/*  f151b4c:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f151b50:	3c014f00 */ 	lui	$at,0x4f00
/*  f151b54:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f151b58:	444af800 */ 	cfc1	$t2,$31
/*  f151b5c:	44d1f800 */ 	ctc1	$s1,$31
/*  f151b60:	00000000 */ 	nop
/*  f151b64:	46004424 */ 	cvt.w.s	$f16,$f8
/*  f151b68:	4451f800 */ 	cfc1	$s1,$31
/*  f151b6c:	00000000 */ 	nop
/*  f151b70:	32310078 */ 	andi	$s1,$s1,0x78
/*  f151b74:	52200013 */ 	beqzl	$s1,.L0f151bc4
/*  f151b78:	44118000 */ 	mfc1	$s1,$f16
/*  f151b7c:	44818000 */ 	mtc1	$at,$f16
/*  f151b80:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f151b84:	46104401 */ 	sub.s	$f16,$f8,$f16
/*  f151b88:	44d1f800 */ 	ctc1	$s1,$31
/*  f151b8c:	00000000 */ 	nop
/*  f151b90:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f151b94:	4451f800 */ 	cfc1	$s1,$31
/*  f151b98:	00000000 */ 	nop
/*  f151b9c:	32310078 */ 	andi	$s1,$s1,0x78
/*  f151ba0:	16200005 */ 	bnez	$s1,.L0f151bb8
/*  f151ba4:	00000000 */ 	nop
/*  f151ba8:	44118000 */ 	mfc1	$s1,$f16
/*  f151bac:	3c018000 */ 	lui	$at,0x8000
/*  f151bb0:	10000007 */ 	b	.L0f151bd0
/*  f151bb4:	02218825 */ 	or	$s1,$s1,$at
.L0f151bb8:
/*  f151bb8:	10000005 */ 	b	.L0f151bd0
/*  f151bbc:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f151bc0:	44118000 */ 	mfc1	$s1,$f16
.L0f151bc4:
/*  f151bc4:	00000000 */ 	nop
/*  f151bc8:	0620fffb */ 	bltz	$s1,.L0f151bb8
/*  f151bcc:	00000000 */ 	nop
.L0f151bd0:
/*  f151bd0:	44caf800 */ 	ctc1	$t2,$31
/*  f151bd4:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f151bd8:	00000000 */ 	nop
/*  f151bdc:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f151be0:	00403025 */ 	or	$a2,$v0,$zero
/*  f151be4:	01746021 */ 	addu	$t4,$t3,$s4
/*  f151be8:	8d830004 */ 	lw	$v1,0x4($t4)
/*  f151bec:	3c0b0708 */ 	lui	$t3,0x708
/*  f151bf0:	356b000c */ 	ori	$t3,$t3,0xc
/*  f151bf4:	28610064 */ 	slti	$at,$v1,0x64
/*  f151bf8:	54200013 */ 	bnezl	$at,.L0f151c48
/*  f151bfc:	3c013f00 */ 	lui	$at,0x3f00
/*  f151c00:	44832000 */ 	mtc1	$v1,$f4
/*  f151c04:	3c014248 */ 	lui	$at,0x4248
/*  f151c08:	44815000 */ 	mtc1	$at,$f10
/*  f151c0c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f151c10:	3c013f80 */ 	lui	$at,0x3f80
/*  f151c14:	44819000 */ 	mtc1	$at,$f18
/*  f151c18:	3c013f80 */ 	lui	$at,0x3f80
/*  f151c1c:	460a3003 */ 	div.s	$f0,$f6,$f10
/*  f151c20:	4600903c */ 	c.lt.s	$f18,$f0
/*  f151c24:	00000000 */ 	nop
/*  f151c28:	45020004 */ 	bc1fl	.L0f151c3c
/*  f151c2c:	4600c201 */ 	sub.s	$f8,$f24,$f0
/*  f151c30:	44810000 */ 	mtc1	$at,$f0
/*  f151c34:	00000000 */ 	nop
/*  f151c38:	4600c201 */ 	sub.s	$f8,$f24,$f0
.L0f151c3c:
/*  f151c3c:	46144502 */ 	mul.s	$f20,$f8,$f20
/*  f151c40:	00000000 */ 	nop
/*  f151c44:	3c013f00 */ 	lui	$at,0x3f00
.L0f151c48:
/*  f151c48:	44818000 */ 	mtc1	$at,$f16
/*  f151c4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f151c50:	00401825 */ 	or	$v1,$v0,$zero
/*  f151c54:	4610a502 */ 	mul.s	$f20,$f20,$f16
/*  f151c58:	00000000 */ 	nop
.L0f151c5c:
/*  f151c5c:	a0700000 */ 	sb	$s0,0x0($v1)
/*  f151c60:	a0710001 */ 	sb	$s1,0x1($v1)
/*  f151c64:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f151c68:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f151c6c:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f151c70:	3c014f80 */ 	lui	$at,0x4f80
/*  f151c74:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f151c78:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f151c7c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f151c80:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f151c84:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f151c88:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f151c8c:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f151c90:	9328005f */ 	lbu	$t0,0x5f($t9)
/*  f151c94:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f151c98:	44882000 */ 	mtc1	$t0,$f4
/*  f151c9c:	05010004 */ 	bgez	$t0,.L0f151cb0
/*  f151ca0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f151ca4:	44815000 */ 	mtc1	$at,$f10
/*  f151ca8:	00000000 */ 	nop
/*  f151cac:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f151cb0:
/*  f151cb0:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f151cb4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f151cb8:	3c014f00 */ 	lui	$at,0x4f00
/*  f151cbc:	4449f800 */ 	cfc1	$t1,$31
/*  f151cc0:	44caf800 */ 	ctc1	$t2,$31
/*  f151cc4:	00000000 */ 	nop
/*  f151cc8:	46009224 */ 	cvt.w.s	$f8,$f18
/*  f151ccc:	444af800 */ 	cfc1	$t2,$31
/*  f151cd0:	00000000 */ 	nop
/*  f151cd4:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f151cd8:	51400013 */ 	beqzl	$t2,.L0f151d28
/*  f151cdc:	440a4000 */ 	mfc1	$t2,$f8
/*  f151ce0:	44814000 */ 	mtc1	$at,$f8
/*  f151ce4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f151ce8:	46089201 */ 	sub.s	$f8,$f18,$f8
/*  f151cec:	44caf800 */ 	ctc1	$t2,$31
/*  f151cf0:	00000000 */ 	nop
/*  f151cf4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f151cf8:	444af800 */ 	cfc1	$t2,$31
/*  f151cfc:	00000000 */ 	nop
/*  f151d00:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f151d04:	15400005 */ 	bnez	$t2,.L0f151d1c
/*  f151d08:	00000000 */ 	nop
/*  f151d0c:	440a4000 */ 	mfc1	$t2,$f8
/*  f151d10:	3c018000 */ 	lui	$at,0x8000
/*  f151d14:	10000007 */ 	b	.L0f151d34
/*  f151d18:	01415025 */ 	or	$t2,$t2,$at
.L0f151d1c:
/*  f151d1c:	10000005 */ 	b	.L0f151d34
/*  f151d20:	240affff */ 	addiu	$t2,$zero,-1
/*  f151d24:	440a4000 */ 	mfc1	$t2,$f8
.L0f151d28:
/*  f151d28:	00000000 */ 	nop
/*  f151d2c:	0540fffb */ 	bltz	$t2,.L0f151d1c
/*  f151d30:	00000000 */ 	nop
.L0f151d34:
/*  f151d34:	44c9f800 */ 	ctc1	$t1,$31
/*  f151d38:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f151d3c:	1496ffc7 */ 	bne	$a0,$s6,.L0f151c5c
/*  f151d40:	a06affff */ 	sb	$t2,-0x1($v1)
/*  f151d44:	02608025 */ 	or	$s0,$s3,$zero
/*  f151d48:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f151d4c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151d50:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f151d54:	00c02025 */ 	or	$a0,$a2,$zero
/*  f151d58:	10000018 */ 	b	.L0f151dbc
/*  f151d5c:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f151d60:
/*  f151d60:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f151d64:	87ad012e */ 	lh	$t5,0x12e($sp)
/*  f151d68:	01947021 */ 	addu	$t6,$t4,$s4
/*  f151d6c:	85c50000 */ 	lh	$a1,0x0($t6)
/*  f151d70:	51a50009 */ 	beql	$t5,$a1,.L0f151d98
/*  f151d74:	3c080708 */ 	lui	$t0,0x708
/*  f151d78:	0fc0044e */ 	jal	func0f001138
/*  f151d7c:	02602025 */ 	or	$a0,$s3,$zero
/*  f151d80:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f151d84:	00409825 */ 	or	$s3,$v0,$zero
/*  f151d88:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f151d8c:	87190000 */ 	lh	$t9,0x0($t8)
/*  f151d90:	a7b9012e */ 	sh	$t9,0x12e($sp)
/*  f151d94:	3c080708 */ 	lui	$t0,0x708
.L0f151d98:
/*  f151d98:	3508000c */ 	ori	$t0,$t0,0xc
/*  f151d9c:	02608025 */ 	or	$s0,$s3,$zero
/*  f151da0:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f151da4:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f151da8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151dac:	01342021 */ 	addu	$a0,$t1,$s4
/*  f151db0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f151db4:	2484005c */ 	addiu	$a0,$a0,0x5c
/*  f151db8:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f151dbc:
/*  f151dbc:	3c0a0420 */ 	lui	$t2,0x420
/*  f151dc0:	354a0024 */ 	ori	$t2,$t2,0x24
/*  f151dc4:	02608025 */ 	or	$s0,$s3,$zero
/*  f151dc8:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f151dcc:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f151dd0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151dd4:	01742021 */ 	addu	$a0,$t3,$s4
/*  f151dd8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f151ddc:	24840038 */ 	addiu	$a0,$a0,0x38
/*  f151de0:	02601825 */ 	or	$v1,$s3,$zero
/*  f151de4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f151de8:	3c0cbf00 */ 	lui	$t4,0xbf00
/*  f151dec:	240e0a14 */ 	addiu	$t6,$zero,0xa14
/*  f151df0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f151df4:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f151df8:	26730008 */ 	addiu	$s3,$s3,0x8
.L0f151dfc:
/*  f151dfc:	3c0d800a */ 	lui	$t5,%hi(g_MaxShards)
/*  f151e00:	8dad45c0 */ 	lw	$t5,%lo(g_MaxShards)($t5)
/*  f151e04:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f151e08:	2694006c */ 	addiu	$s4,$s4,0x6c
/*  f151e0c:	03cd082a */ 	slt	$at,$s8,$t5
/*  f151e10:	5420feb8 */ 	bnezl	$at,.L0f1518f4
/*  f151e14:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f151e18:	e7b600bc */ 	swc1	$f22,0xbc($sp)
.L0f151e1c:
/*  f151e1c:	87af012e */ 	lh	$t7,0x12e($sp)
/*  f151e20:	55e00005 */ 	bnezl	$t7,.L0f151e38
/*  f151e24:	02601025 */ 	or	$v0,$s3,$zero
/*  f151e28:	0fc004c0 */ 	jal	func0f001300
/*  f151e2c:	02602025 */ 	or	$a0,$s3,$zero
/*  f151e30:	00409825 */ 	or	$s3,$v0,$zero
/*  f151e34:	02601025 */ 	or	$v0,$s3,$zero
.L0f151e38:
/*  f151e38:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151e3c:	3c18b600 */ 	lui	$t8,0xb600
/*  f151e40:	3c190006 */ 	lui	$t9,0x6
/*  f151e44:	3c080103 */ 	lui	$t0,0x103
/*  f151e48:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f151e4c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f151e50:	35080040 */ 	ori	$t0,$t0,0x40
/*  f151e54:	02608025 */ 	or	$s0,$s3,$zero
/*  f151e58:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f151e5c:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f151e60:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151e64:	3c090102 */ 	lui	$t1,0x102
/*  f151e68:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f151e6c:	35290040 */ 	ori	$t1,$t1,0x40
/*  f151e70:	02608825 */ 	or	$s1,$s3,$zero
/*  f151e74:	ae290000 */ 	sw	$t1,0x0($s1)
/*  f151e78:	0fc2d3ea */ 	jal	currentPlayerGetUnk173c
/*  f151e7c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f151e80:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f151e84:
/*  f151e84:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f151e88:	02601025 */ 	or	$v0,$s3,$zero
/*  f151e8c:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f151e90:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f151e94:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f151e98:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f151e9c:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f151ea0:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f151ea4:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f151ea8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f151eac:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f151eb0:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f151eb4:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f151eb8:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f151ebc:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f151ec0:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f151ec4:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f151ec8:	03e00008 */ 	jr	$ra
/*  f151ecc:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

Gfx *shardsRenderGlass(Gfx *gdl);

GLOBAL_ASM(
glabel shardsRenderGlass
/*  f151ed0:	27bdfec0 */ 	addiu	$sp,$sp,-320
/*  f151ed4:	3c0e8008 */ 	lui	$t6,%hi(g_ShardsActive)
/*  f151ed8:	8dcefa84 */ 	lw	$t6,%lo(g_ShardsActive)($t6)
/*  f151edc:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f151ee0:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f151ee4:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f151ee8:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f151eec:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f151ef0:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f151ef4:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f151ef8:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f151efc:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f151f00:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f151f04:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f151f08:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f151f0c:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f151f10:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f151f14:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f151f18:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f151f1c:	11c001de */ 	beqz	$t6,.L0f152698
/*  f151f20:	afa40140 */ 	sw	$a0,0x140($sp)
/*  f151f24:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f151f28:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f151f2c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f151f30:	a7a0013e */ 	sh	$zero,0x13e($sp)
/*  f151f34:	24010001 */ 	addiu	$at,$zero,0x1
/*  f151f38:	95f80010 */ 	lhu	$t8,0x10($t7)
/*  f151f3c:	27a40140 */ 	addiu	$a0,$sp,0x140
/*  f151f40:	3c05800b */ 	lui	$a1,%hi(var800ab590)
/*  f151f44:	1701000d */ 	bne	$t8,$at,.L0f151f7c
/*  f151f48:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f151f4c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f151f50:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f151f54:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f151f58:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f151f5c:	27a40140 */ 	addiu	$a0,$sp,0x140
/*  f151f60:	00002825 */ 	or	$a1,$zero,$zero
/*  f151f64:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f151f68:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f151f6c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f151f70:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f151f74:	1000000b */ 	b	.L0f151fa4
/*  f151f78:	8fab0140 */ 	lw	$t3,0x140($sp)
.L0f151f7c:
/*  f151f7c:	8ca5b590 */ 	lw	$a1,%lo(var800ab590)($a1)
/*  f151f80:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f151f84:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f151f88:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f151f8c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f151f90:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f151f94:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f151f98:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f151f9c:	24a5000c */ 	addiu	$a1,$a1,0x000c
/*  f151fa0:	8fab0140 */ 	lw	$t3,0x140($sp)
.L0f151fa4:
/*  f151fa4:	3c0dbb00 */ 	lui	$t5,0xbb00
/*  f151fa8:	3c0e0d80 */ 	lui	$t6,0xd80
/*  f151fac:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f151fb0:	afac0140 */ 	sw	$t4,0x140($sp)
/*  f151fb4:	35ce0d80 */ 	ori	$t6,$t6,0xd80
/*  f151fb8:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f151fbc:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f151fc0:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f151fc4:	8faf0140 */ 	lw	$t7,0x140($sp)
/*  f151fc8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f151fcc:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f151fd0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f151fd4:	afb80140 */ 	sw	$t8,0x140($sp)
/*  f151fd8:	3c080010 */ 	lui	$t0,0x10
/*  f151fdc:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f151fe0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f151fe4:	8fa90140 */ 	lw	$t1,0x140($sp)
/*  f151fe8:	3c0bba00 */ 	lui	$t3,0xba00
/*  f151fec:	356b1001 */ 	ori	$t3,$t3,0x1001
/*  f151ff0:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f151ff4:	afaa0140 */ 	sw	$t2,0x140($sp)
/*  f151ff8:	3c0c0001 */ 	lui	$t4,0x1
/*  f151ffc:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f152000:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f152004:	8fad0140 */ 	lw	$t5,0x140($sp)
/*  f152008:	3c0fb600 */ 	lui	$t7,0xb600
/*  f15200c:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f152010:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f152014:	afae0140 */ 	sw	$t6,0x140($sp)
/*  f152018:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f15201c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f152020:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f152024:	3c09ba00 */ 	lui	$t1,0xba00
/*  f152028:	35290c02 */ 	ori	$t1,$t1,0xc02
/*  f15202c:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f152030:	afa80140 */ 	sw	$t0,0x140($sp)
/*  f152034:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f152038:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f15203c:	af290000 */ 	sw	$t1,0x0($t9)
/*  f152040:	8ecb0284 */ 	lw	$t3,0x284($s6)
/*  f152044:	8fad0140 */ 	lw	$t5,0x140($sp)
/*  f152048:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15204c:	956c0010 */ 	lhu	$t4,0x10($t3)
/*  f152050:	3c0fb700 */ 	lui	$t7,0xb700
/*  f152054:	3c180006 */ 	lui	$t8,0x6
/*  f152058:	11810004 */ 	beq	$t4,$at,.L0f15206c
/*  f15205c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f152060:	afae0140 */ 	sw	$t6,0x140($sp)
/*  f152064:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f152068:	adaf0000 */ 	sw	$t7,0x0($t5)
.L0f15206c:
/*  f15206c:	8fb00140 */ 	lw	$s0,0x140($sp)
/*  f152070:	3c090103 */ 	lui	$t1,0x103
/*  f152074:	35290040 */ 	ori	$t1,$t1,0x40
/*  f152078:	26080008 */ 	addiu	$t0,$s0,0x8
/*  f15207c:	afa80140 */ 	sw	$t0,0x140($sp)
/*  f152080:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f152084:	ae090000 */ 	sw	$t1,0x0($s0)
/*  f152088:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15208c:	00402025 */ 	or	$a0,$v0,$zero
/*  f152090:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f152094:	3c0a800a */ 	lui	$t2,%hi(g_MaxShards)
/*  f152098:	8d4a45c0 */ 	lw	$t2,%lo(g_MaxShards)($t2)
/*  f15209c:	0000b825 */ 	or	$s7,$zero,$zero
/*  f1520a0:	00009825 */ 	or	$s3,$zero,$zero
/*  f1520a4:	1940015f */ 	blez	$t2,.L0f152624
/*  f1520a8:	3c014316 */ 	lui	$at,0x4316
/*  f1520ac:	4481f000 */ 	mtc1	$at,$f30
/*  f1520b0:	3c017f1b */ 	lui	$at,%hi(var7f1b7398)
/*  f1520b4:	c43c7398 */ 	lwc1	$f28,%lo(var7f1b7398)($at)
/*  f1520b8:	3c017f1b */ 	lui	$at,%hi(var7f1b739c)
/*  f1520bc:	c43a739c */ 	lwc1	$f26,%lo(var7f1b739c)($at)
/*  f1520c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1520c4:	3c148008 */ 	lui	$s4,%hi(var8007fa80)
/*  f1520c8:	3c12800a */ 	lui	$s2,%hi(g_Shards)
/*  f1520cc:	4481c000 */ 	mtc1	$at,$f24
/*  f1520d0:	265245c4 */ 	addiu	$s2,$s2,%lo(g_Shards)
/*  f1520d4:	2694fa80 */ 	addiu	$s4,$s4,%lo(var8007fa80)
/*  f1520d8:	c7b600cc */ 	lwc1	$f22,0xcc($sp)
/*  f1520dc:	27be00f8 */ 	addiu	$s8,$sp,0xf8
/*  f1520e0:	2415000c */ 	addiu	$s5,$zero,0xc
/*  f1520e4:	8e4b0000 */ 	lw	$t3,0x0($s2)
.L0f1520e8:
/*  f1520e8:	01731021 */ 	addu	$v0,$t3,$s3
/*  f1520ec:	8c4c0004 */ 	lw	$t4,0x4($v0)
/*  f1520f0:	19800144 */ 	blez	$t4,.L0f152604
/*  f1520f4:	00000000 */ 	nop
/*  f1520f8:	904d0068 */ 	lbu	$t5,0x68($v0)
/*  f1520fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f152100:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f152104:	11a1013f */ 	beq	$t5,$at,.L0f152604
/*  f152108:	00000000 */ 	nop
/*  f15210c:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f152110:	4600c506 */ 	mov.s	$f20,$f24
/*  f152114:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f152118:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15211c:	00408825 */ 	or	$s1,$v0,$zero
/*  f152120:	946e0010 */ 	lhu	$t6,0x10($v1)
/*  f152124:	15c10025 */ 	bne	$t6,$at,.L0f1521bc
/*  f152128:	00000000 */ 	nop
/*  f15212c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f152130:	c46a0018 */ 	lwc1	$f10,0x18($v1)
/*  f152134:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f152138:	01f31021 */ 	addu	$v0,$t7,$s3
/*  f15213c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f152140:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f152144:	c450000c */ 	lwc1	$f16,0xc($v0)
/*  f152148:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f15214c:	c472001c */ 	lwc1	$f18,0x1c($v1)
/*  f152150:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f152154:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f152158:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f15215c:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f152160:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f152164:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f152168:	0c012974 */ 	jal	sqrtf
/*  f15216c:	46085300 */ 	add.s	$f12,$f10,$f8
/*  f152170:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f152174:	c7020024 */ 	lwc1	$f2,0x24($t8)
/*  f152178:	4600103c */ 	c.lt.s	$f2,$f0
/*  f15217c:	461e1301 */ 	sub.s	$f12,$f2,$f30
/*  f152180:	45000002 */ 	bc1f	.L0f15218c
/*  f152184:	46020583 */ 	div.s	$f22,$f0,$f2
/*  f152188:	00008025 */ 	or	$s0,$zero,$zero
.L0f15218c:
/*  f15218c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f152190:	00000000 */ 	nop
/*  f152194:	45020005 */ 	bc1fl	.L0f1521ac
/*  f152198:	4616c03c */ 	c.lt.s	$f24,$f22
/*  f15219c:	460c0401 */ 	sub.s	$f16,$f0,$f12
/*  f1521a0:	461e8483 */ 	div.s	$f18,$f16,$f30
/*  f1521a4:	4612c501 */ 	sub.s	$f20,$f24,$f18
/*  f1521a8:	4616c03c */ 	c.lt.s	$f24,$f22
.L0f1521ac:
/*  f1521ac:	00000000 */ 	nop
/*  f1521b0:	45000002 */ 	bc1f	.L0f1521bc
/*  f1521b4:	00000000 */ 	nop
/*  f1521b8:	4600c586 */ 	mov.s	$f22,$f24
.L0f1521bc:
/*  f1521bc:	12000111 */ 	beqz	$s0,.L0f152604
/*  f1521c0:	00000000 */ 	nop
/*  f1521c4:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f1521c8:	03c03025 */ 	or	$a2,$s8,$zero
/*  f1521cc:	03331021 */ 	addu	$v0,$t9,$s3
/*  f1521d0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f1521d4:	0c0059a9 */ 	jal	func000166a4
/*  f1521d8:	24450014 */ 	addiu	$a1,$v0,0x14
/*  f1521dc:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f1521e0:	c7a40128 */ 	lwc1	$f4,0x128($sp)
/*  f1521e4:	c7a8012c */ 	lwc1	$f8,0x12c($sp)
/*  f1521e8:	c4660038 */ 	lwc1	$f6,0x38($v1)
/*  f1521ec:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f1521f0:	c7a40130 */ 	lwc1	$f4,0x130($sp)
/*  f1521f4:	e7aa0128 */ 	swc1	$f10,0x128($sp)
/*  f1521f8:	c470003c */ 	lwc1	$f16,0x3c($v1)
/*  f1521fc:	461a503c */ 	c.lt.s	$f10,$f26
/*  f152200:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f152204:	e7b2012c */ 	swc1	$f18,0x12c($sp)
/*  f152208:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f15220c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f152210:	450000fc */ 	bc1f	.L0f152604
/*  f152214:	e7a80130 */ 	swc1	$f8,0x130($sp)
/*  f152218:	460ae03c */ 	c.lt.s	$f28,$f10
/*  f15221c:	00000000 */ 	nop
/*  f152220:	450000f8 */ 	bc1f	.L0f152604
/*  f152224:	00000000 */ 	nop
/*  f152228:	461a903c */ 	c.lt.s	$f18,$f26
/*  f15222c:	00000000 */ 	nop
/*  f152230:	450000f4 */ 	bc1f	.L0f152604
/*  f152234:	00000000 */ 	nop
/*  f152238:	4612e03c */ 	c.lt.s	$f28,$f18
/*  f15223c:	00000000 */ 	nop
/*  f152240:	450000f0 */ 	bc1f	.L0f152604
/*  f152244:	00000000 */ 	nop
/*  f152248:	461a403c */ 	c.lt.s	$f8,$f26
/*  f15224c:	00000000 */ 	nop
/*  f152250:	450000ec */ 	bc1f	.L0f152604
/*  f152254:	00000000 */ 	nop
/*  f152258:	4608e03c */ 	c.lt.s	$f28,$f8
/*  f15225c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f152260:	450000e8 */ 	bc1f	.L0f152604
/*  f152264:	00000000 */ 	nop
/*  f152268:	0c005815 */ 	jal	func00016054
/*  f15226c:	02202825 */ 	or	$a1,$s1,$zero
/*  f152270:	8fb00140 */ 	lw	$s0,0x140($sp)
/*  f152274:	3c0a0102 */ 	lui	$t2,0x102
/*  f152278:	354a0040 */ 	ori	$t2,$t2,0x40
/*  f15227c:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f152280:	afa90140 */ 	sw	$t1,0x140($sp)
/*  f152284:	02202025 */ 	or	$a0,$s1,$zero
/*  f152288:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15228c:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f152290:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f152294:	8ecb0284 */ 	lw	$t3,0x284($s6)
/*  f152298:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15229c:	956c0010 */ 	lhu	$t4,0x10($t3)
/*  f1522a0:	158100ae */ 	bne	$t4,$at,.L0f15255c
/*  f1522a4:	3c01437f */ 	lui	$at,0x437f
/*  f1522a8:	44818000 */ 	mtc1	$at,$f16
/*  f1522ac:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f1522b0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1522b4:	4610b102 */ 	mul.s	$f4,$f22,$f16
/*  f1522b8:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f1522bc:	444df800 */ 	cfc1	$t5,$31
/*  f1522c0:	44d0f800 */ 	ctc1	$s0,$31
/*  f1522c4:	00000000 */ 	nop
/*  f1522c8:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f1522cc:	4450f800 */ 	cfc1	$s0,$31
/*  f1522d0:	00000000 */ 	nop
/*  f1522d4:	32100078 */ 	andi	$s0,$s0,0x78
/*  f1522d8:	52000013 */ 	beqzl	$s0,.L0f152328
/*  f1522dc:	44103000 */ 	mfc1	$s0,$f6
/*  f1522e0:	44813000 */ 	mtc1	$at,$f6
/*  f1522e4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f1522e8:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f1522ec:	44d0f800 */ 	ctc1	$s0,$31
/*  f1522f0:	00000000 */ 	nop
/*  f1522f4:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f1522f8:	4450f800 */ 	cfc1	$s0,$31
/*  f1522fc:	00000000 */ 	nop
/*  f152300:	32100078 */ 	andi	$s0,$s0,0x78
/*  f152304:	16000005 */ 	bnez	$s0,.L0f15231c
/*  f152308:	00000000 */ 	nop
/*  f15230c:	44103000 */ 	mfc1	$s0,$f6
/*  f152310:	3c018000 */ 	lui	$at,0x8000
/*  f152314:	10000007 */ 	b	.L0f152334
/*  f152318:	02018025 */ 	or	$s0,$s0,$at
.L0f15231c:
/*  f15231c:	10000005 */ 	b	.L0f152334
/*  f152320:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f152324:	44103000 */ 	mfc1	$s0,$f6
.L0f152328:
/*  f152328:	00000000 */ 	nop
/*  f15232c:	0600fffb */ 	bltz	$s0,.L0f15231c
/*  f152330:	00000000 */ 	nop
.L0f152334:
/*  f152334:	44cdf800 */ 	ctc1	$t5,$31
/*  f152338:	3c01437f */ 	lui	$at,0x437f
/*  f15233c:	44819000 */ 	mtc1	$at,$f18
/*  f152340:	4616c281 */ 	sub.s	$f10,$f24,$f22
/*  f152344:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f152348:	3c014f00 */ 	lui	$at,0x4f00
/*  f15234c:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f152350:	444ef800 */ 	cfc1	$t6,$31
/*  f152354:	44d1f800 */ 	ctc1	$s1,$31
/*  f152358:	00000000 */ 	nop
/*  f15235c:	46004424 */ 	cvt.w.s	$f16,$f8
/*  f152360:	4451f800 */ 	cfc1	$s1,$31
/*  f152364:	00000000 */ 	nop
/*  f152368:	32310078 */ 	andi	$s1,$s1,0x78
/*  f15236c:	52200013 */ 	beqzl	$s1,.L0f1523bc
/*  f152370:	44118000 */ 	mfc1	$s1,$f16
/*  f152374:	44818000 */ 	mtc1	$at,$f16
/*  f152378:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f15237c:	46104401 */ 	sub.s	$f16,$f8,$f16
/*  f152380:	44d1f800 */ 	ctc1	$s1,$31
/*  f152384:	00000000 */ 	nop
/*  f152388:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f15238c:	4451f800 */ 	cfc1	$s1,$31
/*  f152390:	00000000 */ 	nop
/*  f152394:	32310078 */ 	andi	$s1,$s1,0x78
/*  f152398:	16200005 */ 	bnez	$s1,.L0f1523b0
/*  f15239c:	00000000 */ 	nop
/*  f1523a0:	44118000 */ 	mfc1	$s1,$f16
/*  f1523a4:	3c018000 */ 	lui	$at,0x8000
/*  f1523a8:	10000007 */ 	b	.L0f1523c8
/*  f1523ac:	02218825 */ 	or	$s1,$s1,$at
.L0f1523b0:
/*  f1523b0:	10000005 */ 	b	.L0f1523c8
/*  f1523b4:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f1523b8:	44118000 */ 	mfc1	$s1,$f16
.L0f1523bc:
/*  f1523bc:	00000000 */ 	nop
/*  f1523c0:	0620fffb */ 	bltz	$s1,.L0f1523b0
/*  f1523c4:	00000000 */ 	nop
.L0f1523c8:
/*  f1523c8:	44cef800 */ 	ctc1	$t6,$31
/*  f1523cc:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f1523d0:	00000000 */ 	nop
/*  f1523d4:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f1523d8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1523dc:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f1523e0:	8f030004 */ 	lw	$v1,0x4($t8)
/*  f1523e4:	28610064 */ 	slti	$at,$v1,0x64
/*  f1523e8:	54200013 */ 	bnezl	$at,.L0f152438
/*  f1523ec:	3c013f00 */ 	lui	$at,0x3f00
/*  f1523f0:	44832000 */ 	mtc1	$v1,$f4
/*  f1523f4:	3c014248 */ 	lui	$at,0x4248
/*  f1523f8:	44815000 */ 	mtc1	$at,$f10
/*  f1523fc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f152400:	3c013f80 */ 	lui	$at,0x3f80
/*  f152404:	44819000 */ 	mtc1	$at,$f18
/*  f152408:	3c013f80 */ 	lui	$at,0x3f80
/*  f15240c:	460a3003 */ 	div.s	$f0,$f6,$f10
/*  f152410:	4600903c */ 	c.lt.s	$f18,$f0
/*  f152414:	00000000 */ 	nop
/*  f152418:	45020004 */ 	bc1fl	.L0f15242c
/*  f15241c:	4600c201 */ 	sub.s	$f8,$f24,$f0
/*  f152420:	44810000 */ 	mtc1	$at,$f0
/*  f152424:	00000000 */ 	nop
/*  f152428:	4600c201 */ 	sub.s	$f8,$f24,$f0
.L0f15242c:
/*  f15242c:	46144502 */ 	mul.s	$f20,$f8,$f20
/*  f152430:	00000000 */ 	nop
/*  f152434:	3c013f00 */ 	lui	$at,0x3f00
.L0f152438:
/*  f152438:	44818000 */ 	mtc1	$at,$f16
/*  f15243c:	00002025 */ 	or	$a0,$zero,$zero
/*  f152440:	00401825 */ 	or	$v1,$v0,$zero
/*  f152444:	4610a502 */ 	mul.s	$f20,$f20,$f16
/*  f152448:	00000000 */ 	nop
.L0f15244c:
/*  f15244c:	a0700000 */ 	sb	$s0,0x0($v1)
/*  f152450:	a0710001 */ 	sb	$s1,0x1($v1)
/*  f152454:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f152458:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f15245c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f152460:	3c014f80 */ 	lui	$at,0x4f80
/*  f152464:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f152468:	01284823 */ 	subu	$t1,$t1,$t0
/*  f15246c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f152470:	01284823 */ 	subu	$t1,$t1,$t0
/*  f152474:	00094880 */ 	sll	$t1,$t1,0x2
/*  f152478:	03295021 */ 	addu	$t2,$t9,$t1
/*  f15247c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f152480:	916c005f */ 	lbu	$t4,0x5f($t3)
/*  f152484:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f152488:	448c2000 */ 	mtc1	$t4,$f4
/*  f15248c:	05810004 */ 	bgez	$t4,.L0f1524a0
/*  f152490:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f152494:	44815000 */ 	mtc1	$at,$f10
/*  f152498:	00000000 */ 	nop
/*  f15249c:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f1524a0:
/*  f1524a0:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f1524a4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1524a8:	3c014f00 */ 	lui	$at,0x4f00
/*  f1524ac:	444df800 */ 	cfc1	$t5,$31
/*  f1524b0:	44cef800 */ 	ctc1	$t6,$31
/*  f1524b4:	00000000 */ 	nop
/*  f1524b8:	46009224 */ 	cvt.w.s	$f8,$f18
/*  f1524bc:	444ef800 */ 	cfc1	$t6,$31
/*  f1524c0:	00000000 */ 	nop
/*  f1524c4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1524c8:	51c00013 */ 	beqzl	$t6,.L0f152518
/*  f1524cc:	440e4000 */ 	mfc1	$t6,$f8
/*  f1524d0:	44814000 */ 	mtc1	$at,$f8
/*  f1524d4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1524d8:	46089201 */ 	sub.s	$f8,$f18,$f8
/*  f1524dc:	44cef800 */ 	ctc1	$t6,$31
/*  f1524e0:	00000000 */ 	nop
/*  f1524e4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1524e8:	444ef800 */ 	cfc1	$t6,$31
/*  f1524ec:	00000000 */ 	nop
/*  f1524f0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1524f4:	15c00005 */ 	bnez	$t6,.L0f15250c
/*  f1524f8:	00000000 */ 	nop
/*  f1524fc:	440e4000 */ 	mfc1	$t6,$f8
/*  f152500:	3c018000 */ 	lui	$at,0x8000
/*  f152504:	10000007 */ 	b	.L0f152524
/*  f152508:	01c17025 */ 	or	$t6,$t6,$at
.L0f15250c:
/*  f15250c:	10000005 */ 	b	.L0f152524
/*  f152510:	240effff */ 	addiu	$t6,$zero,-1
/*  f152514:	440e4000 */ 	mfc1	$t6,$f8
.L0f152518:
/*  f152518:	00000000 */ 	nop
/*  f15251c:	05c0fffb */ 	bltz	$t6,.L0f15250c
/*  f152520:	00000000 */ 	nop
.L0f152524:
/*  f152524:	44cdf800 */ 	ctc1	$t5,$31
/*  f152528:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f15252c:	1495ffc7 */ 	bne	$a0,$s5,.L0f15244c
/*  f152530:	a06effff */ 	sb	$t6,-0x1($v1)
/*  f152534:	8fb00140 */ 	lw	$s0,0x140($sp)
/*  f152538:	3c080708 */ 	lui	$t0,0x708
/*  f15253c:	3508000c */ 	ori	$t0,$t0,0xc
/*  f152540:	26180008 */ 	addiu	$t8,$s0,0x8
/*  f152544:	afb80140 */ 	sw	$t8,0x140($sp)
/*  f152548:	00c02025 */ 	or	$a0,$a2,$zero
/*  f15254c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f152550:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f152554:	10000019 */ 	b	.L0f1525bc
/*  f152558:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f15255c:
/*  f15255c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f152560:	87aa013e */ 	lh	$t2,0x13e($sp)
/*  f152564:	03334821 */ 	addu	$t1,$t9,$s3
/*  f152568:	85250000 */ 	lh	$a1,0x0($t1)
/*  f15256c:	51450009 */ 	beql	$t2,$a1,.L0f152594
/*  f152570:	8fb00140 */ 	lw	$s0,0x140($sp)
/*  f152574:	0fc0044e */ 	jal	func0f001138
/*  f152578:	8fa40140 */ 	lw	$a0,0x140($sp)
/*  f15257c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f152580:	afa20140 */ 	sw	$v0,0x140($sp)
/*  f152584:	01736021 */ 	addu	$t4,$t3,$s3
/*  f152588:	858d0000 */ 	lh	$t5,0x0($t4)
/*  f15258c:	a7ad013e */ 	sh	$t5,0x13e($sp)
/*  f152590:	8fb00140 */ 	lw	$s0,0x140($sp)
.L0f152594:
/*  f152594:	3c180708 */ 	lui	$t8,0x708
/*  f152598:	3718000c */ 	ori	$t8,$t8,0xc
/*  f15259c:	260f0008 */ 	addiu	$t7,$s0,0x8
/*  f1525a0:	afaf0140 */ 	sw	$t7,0x140($sp)
/*  f1525a4:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f1525a8:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f1525ac:	01132021 */ 	addu	$a0,$t0,$s3
/*  f1525b0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1525b4:	2484005c */ 	addiu	$a0,$a0,0x5c
/*  f1525b8:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f1525bc:
/*  f1525bc:	8fb00140 */ 	lw	$s0,0x140($sp)
/*  f1525c0:	3c0a0420 */ 	lui	$t2,0x420
/*  f1525c4:	354a0024 */ 	ori	$t2,$t2,0x24
/*  f1525c8:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f1525cc:	afa90140 */ 	sw	$t1,0x140($sp)
/*  f1525d0:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f1525d4:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f1525d8:	01732021 */ 	addu	$a0,$t3,$s3
/*  f1525dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1525e0:	24840038 */ 	addiu	$a0,$a0,0x38
/*  f1525e4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f1525e8:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f1525ec:	3c0ebf00 */ 	lui	$t6,0xbf00
/*  f1525f0:	240f0a14 */ 	addiu	$t7,$zero,0xa14
/*  f1525f4:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f1525f8:	afad0140 */ 	sw	$t5,0x140($sp)
/*  f1525fc:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f152600:	ad8e0000 */ 	sw	$t6,0x0($t4)
.L0f152604:
/*  f152604:	3c18800a */ 	lui	$t8,%hi(g_MaxShards)
/*  f152608:	8f1845c0 */ 	lw	$t8,%lo(g_MaxShards)($t8)
/*  f15260c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f152610:	2673006c */ 	addiu	$s3,$s3,0x6c
/*  f152614:	02f8082a */ 	slt	$at,$s7,$t8
/*  f152618:	5420feb3 */ 	bnezl	$at,.L0f1520e8
/*  f15261c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f152620:	e7b600cc */ 	swc1	$f22,0xcc($sp)
.L0f152624:
/*  f152624:	87a8013e */ 	lh	$t0,0x13e($sp)
/*  f152628:	55000005 */ 	bnezl	$t0,.L0f152640
/*  f15262c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f152630:	0fc004c0 */ 	jal	func0f001300
/*  f152634:	8fa40140 */ 	lw	$a0,0x140($sp)
/*  f152638:	afa20140 */ 	sw	$v0,0x140($sp)
/*  f15263c:	8fb90140 */ 	lw	$t9,0x140($sp)
.L0f152640:
/*  f152640:	3c0ab600 */ 	lui	$t2,0xb600
/*  f152644:	3c0b0006 */ 	lui	$t3,0x6
/*  f152648:	27290008 */ 	addiu	$t1,$t9,0x8
/*  f15264c:	afa90140 */ 	sw	$t1,0x140($sp)
/*  f152650:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f152654:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f152658:	8fb00140 */ 	lw	$s0,0x140($sp)
/*  f15265c:	3c0e0103 */ 	lui	$t6,0x103
/*  f152660:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f152664:	260d0008 */ 	addiu	$t5,$s0,0x8
/*  f152668:	afad0140 */ 	sw	$t5,0x140($sp)
/*  f15266c:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f152670:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f152674:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f152678:	8fb10140 */ 	lw	$s1,0x140($sp)
/*  f15267c:	3c080102 */ 	lui	$t0,0x102
/*  f152680:	35080040 */ 	ori	$t0,$t0,0x40
/*  f152684:	26380008 */ 	addiu	$t8,$s1,0x8
/*  f152688:	afb80140 */ 	sw	$t8,0x140($sp)
/*  f15268c:	0fc2d3ea */ 	jal	currentPlayerGetUnk173c
/*  f152690:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f152694:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f152698:
/*  f152698:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f15269c:	8fa20140 */ 	lw	$v0,0x140($sp)
/*  f1526a0:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f1526a4:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f1526a8:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f1526ac:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f1526b0:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f1526b4:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f1526b8:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f1526bc:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f1526c0:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f1526c4:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f1526c8:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f1526cc:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f1526d0:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f1526d4:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f1526d8:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f1526dc:	03e00008 */ 	jr	$ra
/*  f1526e0:	27bd0140 */ 	addiu	$sp,$sp,0x140
);

Gfx *shardsRender(Gfx *gdl)
{
	gdl = shardsRenderWood(gdl);
	gdl = shardsRenderGlass(gdl);

	return gdl;
}
