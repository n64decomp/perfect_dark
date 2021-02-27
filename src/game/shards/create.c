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

s32 g_MaxShards;
struct shard *g_Shards;

s32 g_NextShardNum = 0;
bool g_ShardsActive = false;

const u32 var7f1b7370[] = {0x3dcccccd};
const u32 var7f1b7374[] = {0x3f333333};

GLOBAL_ASM(
glabel shardsCreate
/*  f150820:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f150824:	afbf0094 */ 	sw	$ra,0x94($sp)
/*  f150828:	afb70090 */ 	sw	$s7,0x90($sp)
/*  f15082c:	afb6008c */ 	sw	$s6,0x8c($sp)
/*  f150830:	afb50088 */ 	sw	$s5,0x88($sp)
/*  f150834:	afb40084 */ 	sw	$s4,0x84($sp)
/*  f150838:	afb30080 */ 	sw	$s3,0x80($sp)
/*  f15083c:	afb2007c */ 	sw	$s2,0x7c($sp)
/*  f150840:	afb10078 */ 	sw	$s1,0x78($sp)
/*  f150844:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f150848:	f7be0068 */ 	sdc1	$f30,0x68($sp)
/*  f15084c:	f7bc0060 */ 	sdc1	$f28,0x60($sp)
/*  f150850:	f7ba0058 */ 	sdc1	$f26,0x58($sp)
/*  f150854:	f7b80050 */ 	sdc1	$f24,0x50($sp)
/*  f150858:	f7b60048 */ 	sdc1	$f22,0x48($sp)
/*  f15085c:	f7b40040 */ 	sdc1	$f20,0x40($sp)
/*  f150860:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f150864:	00c08025 */ 	or	$s0,$a2,$zero
/*  f150868:	00808825 */ 	or	$s1,$a0,$zero
/*  f15086c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f150870:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f150874:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f150878:	00e09025 */ 	or	$s2,$a3,$zero
/*  f15087c:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f150880:	460a5402 */ 	mul.s	$f16,$f10,$f10
/*  f150884:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*  f150888:	c7b200d0 */ 	lwc1	$f18,0xd0($sp)
/*  f15088c:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f150890:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f150894:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f150898:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f15089c:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f1508a0:	0c012974 */ 	jal	sqrtf
/*  f1508a4:	46065300 */ 	add.s	$f12,$f10,$f6
/*  f1508a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1508ac:	4481f000 */ 	mtc1	$at,$f30
/*  f1508b0:	c7b200cc */ 	lwc1	$f18,0xcc($sp)
/*  f1508b4:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*  f1508b8:	4600f503 */ 	div.s	$f20,$f30,$f0
/*  f1508bc:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f1508c0:	c7b60128 */ 	lwc1	$f22,0x128($sp)
/*  f1508c4:	c7ba012c */ 	lwc1	$f26,0x12c($sp)
/*  f1508c8:	46149402 */ 	mul.s	$f16,$f18,$f20
/*  f1508cc:	00000000 */ 	nop
/*  f1508d0:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f1508d4:	00000000 */ 	nop
/*  f1508d8:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f1508dc:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f1508e0:	4600b582 */ 	mul.s	$f22,$f22,$f0
/*  f1508e4:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f1508e8:	4600d682 */ 	mul.s	$f26,$f26,$f0
/*  f1508ec:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f1508f0:	c6120000 */ 	lwc1	$f18,0x0($s0)
/*  f1508f4:	e7b200c0 */ 	swc1	$f18,0xc0($sp)
/*  f1508f8:	c6100004 */ 	lwc1	$f16,0x4($s0)
/*  f1508fc:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f150900:	e7b000c4 */ 	swc1	$f16,0xc4($sp)
/*  f150904:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f150908:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f15090c:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f150910:	e7a400c8 */ 	swc1	$f4,0xc8($sp)
/*  f150914:	46063482 */ 	mul.s	$f18,$f6,$f6
/*  f150918:	c7a400c8 */ 	lwc1	$f4,0xc8($sp)
/*  f15091c:	46042202 */ 	mul.s	$f8,$f4,$f4
/*  f150920:	46125400 */ 	add.s	$f16,$f10,$f18
/*  f150924:	0c012974 */ 	jal	sqrtf
/*  f150928:	46104300 */ 	add.s	$f12,$f8,$f16
/*  f15092c:	4600f503 */ 	div.s	$f20,$f30,$f0
/*  f150930:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f150934:	c7b200c4 */ 	lwc1	$f18,0xc4($sp)
/*  f150938:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f15093c:	c7b80130 */ 	lwc1	$f24,0x130($sp)
/*  f150940:	c7bc0134 */ 	lwc1	$f28,0x134($sp)
/*  f150944:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f150948:	00000000 */ 	nop
/*  f15094c:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f150950:	00000000 */ 	nop
/*  f150954:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f150958:	e7aa00c0 */ 	swc1	$f10,0xc0($sp)
/*  f15095c:	4600c602 */ 	mul.s	$f24,$f24,$f0
/*  f150960:	e7a400c4 */ 	swc1	$f4,0xc4($sp)
/*  f150964:	4600e702 */ 	mul.s	$f28,$f28,$f0
/*  f150968:	e7b000c8 */ 	swc1	$f16,0xc8($sp)
/*  f15096c:	c64e0008 */ 	lwc1	$f14,0x8($s2)
/*  f150970:	0fc259d4 */ 	jal	atan2f
/*  f150974:	c64c0000 */ 	lwc1	$f12,0x0($s2)
/*  f150978:	3c0e800a */ 	lui	$t6,%hi(g_MaxShards)
/*  f15097c:	8dce45c0 */ 	lw	$t6,%lo(g_MaxShards)($t6)
/*  f150980:	4616d501 */ 	sub.s	$f20,$f26,$f22
/*  f150984:	46000786 */ 	mov.s	$f30,$f0
/*  f150988:	4618e081 */ 	sub.s	$f2,$f28,$f24
/*  f15098c:	4602a182 */ 	mul.s	$f6,$f20,$f2
/*  f150990:	05c10003 */ 	bgez	$t6,.L0f1509a0
/*  f150994:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f150998:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f15099c:	00017843 */ 	sra	$t7,$at,0x1
.L0f1509a0:
/*  f1509a0:	448f5000 */ 	mtc1	$t7,$f10
/*  f1509a4:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f1509a8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1509ac:	0c012974 */ 	jal	sqrtf
/*  f1509b0:	46123303 */ 	div.s	$f12,$f6,$f18
/*  f1509b4:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f1509b8:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f1509bc:	e7a000ec */ 	swc1	$f0,0xec($sp)
/*  f1509c0:	c6300000 */ 	lwc1	$f16,0x0($s1)
/*  f1509c4:	44122000 */ 	mfc1	$s2,$f4
/*  f1509c8:	c7a400c0 */ 	lwc1	$f4,0xc0($sp)
/*  f1509cc:	8fb40138 */ 	lw	$s4,0x138($sp)
/*  f1509d0:	0012c843 */ 	sra	$t9,$s2,0x1
/*  f1509d4:	44994000 */ 	mtc1	$t9,$f8
/*  f1509d8:	8fb3013c */ 	lw	$s3,0x13c($sp)
/*  f1509dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1509e0:	468043a0 */ 	cvt.s.w	$f14,$f8
/*  f1509e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1509e8:	24068078 */ 	addiu	$a2,$zero,-32648
/*  f1509ec:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1509f0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f1509f4:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1509f8:	460eb300 */ 	add.s	$f12,$f22,$f14
/*  f1509fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f150a00:	02408025 */ 	or	$s0,$s2,$zero
/*  f150a04:	460ec080 */ 	add.s	$f2,$f24,$f14
/*  f150a08:	460a6182 */ 	mul.s	$f6,$f12,$f10
/*  f150a0c:	26690008 */ 	addiu	$t1,$s3,0x8
/*  f150a10:	266a0028 */ 	addiu	$t2,$s3,0x28
/*  f150a14:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f150a18:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f150a1c:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f150a20:	46124280 */ 	add.s	$f10,$f8,$f18
/*  f150a24:	46066102 */ 	mul.s	$f4,$f12,$f6
/*  f150a28:	c7b200c4 */ 	lwc1	$f18,0xc4($sp)
/*  f150a2c:	e7aa00d8 */ 	swc1	$f10,0xd8($sp)
/*  f150a30:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f150a34:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f150a38:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f150a3c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f150a40:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f150a44:	46046482 */ 	mul.s	$f18,$f12,$f4
/*  f150a48:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f150a4c:	e7a600dc */ 	swc1	$f6,0xdc($sp)
/*  f150a50:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f150a54:	c6300008 */ 	lwc1	$f16,0x8($s1)
/*  f150a58:	46128280 */ 	add.s	$f10,$f16,$f18
/*  f150a5c:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f150a60:	16800011 */ 	bnez	$s4,.L0f150aa8
/*  f150a64:	e7a400e0 */ 	swc1	$f4,0xe0($sp)
/*  f150a68:	3c01bf80 */ 	lui	$at,0xbf80
/*  f150a6c:	44810000 */ 	mtc1	$at,$f0
/*  f150a70:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f150a74:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f150a78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f150a7c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f150a80:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f150a84:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f150a88:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f150a8c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f150a90:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f150a94:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f150a98:	0fc24e7e */ 	jal	func0f0939f8
/*  f150a9c:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f150aa0:	1000003c */ 	b	.L0f150b94
/*  f150aa4:	44908000 */ 	mtc1	$s0,$f16
.L0f150aa8:
/*  f150aa8:	56810021 */ 	bnel	$s4,$at,.L0f150b30
/*  f150aac:	24010002 */ 	addiu	$at,$zero,0x2
/*  f150ab0:	0c004b70 */ 	jal	random
/*  f150ab4:	00000000 */ 	nop
/*  f150ab8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f150abc:	44810000 */ 	mtc1	$at,$f0
/*  f150ac0:	8fb3013c */ 	lw	$s3,0x13c($sp)
/*  f150ac4:	30460001 */ 	andi	$a2,$v0,0x1
/*  f150ac8:	00066040 */ 	sll	$t4,$a2,0x1
/*  f150acc:	25860010 */ 	addiu	$a2,$t4,0x10
/*  f150ad0:	00066c00 */ 	sll	$t5,$a2,0x10
/*  f150ad4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f150ad8:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f150adc:	26780008 */ 	addiu	$t8,$s3,0x8
/*  f150ae0:	26790028 */ 	addiu	$t9,$s3,0x28
/*  f150ae4:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f150ae8:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f150aec:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f150af0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f150af4:	000d3403 */ 	sra	$a2,$t5,0x10
/*  f150af8:	00002025 */ 	or	$a0,$zero,$zero
/*  f150afc:	00002825 */ 	or	$a1,$zero,$zero
/*  f150b00:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f150b04:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f150b08:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f150b0c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f150b10:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f150b14:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f150b18:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f150b1c:	0fc24e7e */ 	jal	func0f0939f8
/*  f150b20:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f150b24:	1000001b */ 	b	.L0f150b94
/*  f150b28:	44908000 */ 	mtc1	$s0,$f16
/*  f150b2c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f150b30:
/*  f150b30:	16810017 */ 	bne	$s4,$at,.L0f150b90
/*  f150b34:	8fb3013c */ 	lw	$s3,0x13c($sp)
/*  f150b38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f150b3c:	44810000 */ 	mtc1	$at,$f0
/*  f150b40:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f150b44:	266a0008 */ 	addiu	$t2,$s3,0x8
/*  f150b48:	266b0028 */ 	addiu	$t3,$s3,0x28
/*  f150b4c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f150b50:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f150b54:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f150b58:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f150b5c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f150b60:	00002025 */ 	or	$a0,$zero,$zero
/*  f150b64:	00002825 */ 	or	$a1,$zero,$zero
/*  f150b68:	240605d8 */ 	addiu	$a2,$zero,0x5d8
/*  f150b6c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f150b70:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f150b74:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f150b78:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f150b7c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f150b80:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f150b84:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f150b88:	0fc24e7e */ 	jal	func0f0939f8
/*  f150b8c:	e7a00038 */ 	swc1	$f0,0x38($sp)
.L0f150b90:
/*  f150b90:	44908000 */ 	mtc1	$s0,$f16
.L0f150b94:
/*  f150b94:	44923000 */ 	mtc1	$s2,$f6
/*  f150b98:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f150b9c:	468085a0 */ 	cvt.s.w	$f22,$f16
/*  f150ba0:	8fb3013c */ 	lw	$s3,0x13c($sp)
/*  f150ba4:	0000a825 */ 	or	$s5,$zero,$zero
/*  f150ba8:	3c017f1b */ 	lui	$at,%hi(var7f1b7370)
/*  f150bac:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f150bb0:	4616a483 */ 	div.s	$f18,$f20,$f22
/*  f150bb4:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f150bb8:	c7b000a4 */ 	lwc1	$f16,0xa4($sp)
/*  f150bbc:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f150bc0:	46102483 */ 	div.s	$f18,$f4,$f16
/*  f150bc4:	44164000 */ 	mfc1	$s6,$f8
/*  f150bc8:	00000000 */ 	nop
/*  f150bcc:	02c08825 */ 	or	$s1,$s6,$zero
/*  f150bd0:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f150bd4:	44174000 */ 	mfc1	$s7,$f8
/*  f150bd8:	00000000 */ 	nop
/*  f150bdc:	5ae00046 */ 	blezl	$s7,.L0f150cf8
/*  f150be0:	8fbf0094 */ 	lw	$ra,0x94($sp)
/*  f150be4:	c43c7370 */ 	lwc1	$f28,%lo(var7f1b7370)($at)
/*  f150be8:	3c017f1b */ 	lui	$at,%hi(var7f1b7374)
/*  f150bec:	c43a7374 */ 	lwc1	$f26,%lo(var7f1b7374)($at)
/*  f150bf0:	3c012f80 */ 	lui	$at,0x2f80
/*  f150bf4:	4481c000 */ 	mtc1	$at,$f24
/*  f150bf8:	27b200fc */ 	addiu	$s2,$sp,0xfc
.L0f150bfc:
/*  f150bfc:	1ac00039 */ 	blez	$s6,.L0f150ce4
/*  f150c00:	00008025 */ 	or	$s0,$zero,$zero
/*  f150c04:	44953000 */ 	mtc1	$s5,$f6
/*  f150c08:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f150c0c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f150c10:	46045502 */ 	mul.s	$f20,$f10,$f4
/*  f150c14:	00000000 */ 	nop
/*  f150c18:	44908000 */ 	mtc1	$s0,$f16
.L0f150c1c:
/*  f150c1c:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f150c20:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f150c24:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f150c28:	c7b000c0 */ 	lwc1	$f16,0xc0($sp)
/*  f150c2c:	46169002 */ 	mul.s	$f0,$f18,$f22
/*  f150c30:	00000000 */ 	nop
/*  f150c34:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f150c38:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f150c3c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f150c40:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f150c44:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f150c48:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f150c4c:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f150c50:	c7a400c4 */ 	lwc1	$f4,0xc4($sp)
/*  f150c54:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f150c58:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f150c5c:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f150c60:	c7b000d4 */ 	lwc1	$f16,0xd4($sp)
/*  f150c64:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*  f150c68:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f150c6c:	46123280 */ 	add.s	$f10,$f6,$f18
/*  f150c70:	c7b200c8 */ 	lwc1	$f18,0xc8($sp)
/*  f150c74:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f150c78:	e7aa0100 */ 	swc1	$f10,0x100($sp)
/*  f150c7c:	46149282 */ 	mul.s	$f10,$f18,$f20
/*  f150c80:	46065400 */ 	add.s	$f16,$f10,$f6
/*  f150c84:	0c004b70 */ 	jal	random
/*  f150c88:	e7b00104 */ 	swc1	$f16,0x104($sp)
/*  f150c8c:	44824000 */ 	mtc1	$v0,$f8
/*  f150c90:	4406f000 */ 	mfc1	$a2,$f30
/*  f150c94:	86640028 */ 	lh	$a0,0x28($s3)
/*  f150c98:	02402825 */ 	or	$a1,$s2,$zero
/*  f150c9c:	04410005 */ 	bgez	$v0,.L0f150cb4
/*  f150ca0:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f150ca4:	3c014f80 */ 	lui	$at,0x4f80
/*  f150ca8:	44819000 */ 	mtc1	$at,$f18
/*  f150cac:	00000000 */ 	nop
/*  f150cb0:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f150cb4:
/*  f150cb4:	46182282 */ 	mul.s	$f10,$f4,$f24
/*  f150cb8:	c7a800ec */ 	lwc1	$f8,0xec($sp)
/*  f150cbc:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f150cc0:	461a5182 */ 	mul.s	$f6,$f10,$f26
/*  f150cc4:	461c3400 */ 	add.s	$f16,$f6,$f28
/*  f150cc8:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f150ccc:	44079000 */ 	mfc1	$a3,$f18
/*  f150cd0:	0fc5434e */ 	jal	shardCreate
/*  f150cd4:	00000000 */ 	nop
/*  f150cd8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f150cdc:	5611ffcf */ 	bnel	$s0,$s1,.L0f150c1c
/*  f150ce0:	44908000 */ 	mtc1	$s0,$f16
.L0f150ce4:
/*  f150ce4:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f150ce8:	02b7082a */ 	slt	$at,$s5,$s7
/*  f150cec:	1420ffc3 */ 	bnez	$at,.L0f150bfc
/*  f150cf0:	00000000 */ 	nop
/*  f150cf4:	8fbf0094 */ 	lw	$ra,0x94($sp)
.L0f150cf8:
/*  f150cf8:	d7b40040 */ 	ldc1	$f20,0x40($sp)
/*  f150cfc:	d7b60048 */ 	ldc1	$f22,0x48($sp)
/*  f150d00:	d7b80050 */ 	ldc1	$f24,0x50($sp)
/*  f150d04:	d7ba0058 */ 	ldc1	$f26,0x58($sp)
/*  f150d08:	d7bc0060 */ 	ldc1	$f28,0x60($sp)
/*  f150d0c:	d7be0068 */ 	ldc1	$f30,0x68($sp)
/*  f150d10:	8fb00074 */ 	lw	$s0,0x74($sp)
/*  f150d14:	8fb10078 */ 	lw	$s1,0x78($sp)
/*  f150d18:	8fb2007c */ 	lw	$s2,0x7c($sp)
/*  f150d1c:	8fb30080 */ 	lw	$s3,0x80($sp)
/*  f150d20:	8fb40084 */ 	lw	$s4,0x84($sp)
/*  f150d24:	8fb50088 */ 	lw	$s5,0x88($sp)
/*  f150d28:	8fb6008c */ 	lw	$s6,0x8c($sp)
/*  f150d2c:	8fb70090 */ 	lw	$s7,0x90($sp)
/*  f150d30:	03e00008 */ 	jr	$ra
/*  f150d34:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

void shardCreate(s16 room, struct coord *pos, f32 rotx, f32 size, s32 type)
{
	f32 velx = random() * (1.0f / U32_MAX) * 2.0f - 1.0f;
	f32 vely = random() * (1.0f / U32_MAX) * 1.12f - 0.12f;
	f32 velz = random() * (1.0f / U32_MAX) * 2.0f - 1.0f;
	s32 i;

	g_Shards[g_NextShardNum].type = type;
	g_Shards[g_NextShardNum].room = room;
	g_Shards[g_NextShardNum].age60 = 1;

	g_Shards[g_NextShardNum].pos.x = pos->x;
	g_Shards[g_NextShardNum].pos.y = pos->y;
	g_Shards[g_NextShardNum].pos.z = pos->z;

	g_Shards[g_NextShardNum].vel.x = velx * 1.5f;
	g_Shards[g_NextShardNum].vel.y = vely * 3.0f;
	g_Shards[g_NextShardNum].vel.z = velz * 1.5f;

	g_Shards[g_NextShardNum].vertices[0].x = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[0].y = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[1].x = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[1].y = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * -size;
	g_Shards[g_NextShardNum].vertices[2].x = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * -size;
	g_Shards[g_NextShardNum].vertices[2].y = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * -size;

	for (i = 0; i < 3; i++) {
		g_Shards[g_NextShardNum].vertices[i].z = 0;
		g_Shards[g_NextShardNum].vertices[i].unk08 = 0;
		g_Shards[g_NextShardNum].vertices[i].unk0a = 0;
		g_Shards[g_NextShardNum].vertices[i].s = i * 4;
	}

	if (type == SHARDTYPE_WOOD) {
		s32 rand = random() % 100;

		if (rand < 20) {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0xbbbbbbf0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0xaaaaaaf0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0x777777f0;
		} else if (rand < 40) {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0x000000f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0x000000f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0x000000f0;
		} else if (rand < 60) {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0x553311f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0x553311f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0x553311f0;
		} else {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0xddaa88f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0xddaa88f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0xddaa88f0;
		}
	} else {
		s32 i;
		s32 j;

		g_Shards[g_NextShardNum].colours[0][0] = 0x05;
		g_Shards[g_NextShardNum].colours[0][1] = 0x05;
		g_Shards[g_NextShardNum].colours[0][2] = 0x7e;

		g_Shards[g_NextShardNum].colours[1][0] = 0x05;
		g_Shards[g_NextShardNum].colours[1][1] = 0xfb;
		g_Shards[g_NextShardNum].colours[1][2] = 0x7e;

		g_Shards[g_NextShardNum].colours[2][0] = 0xfb;
		g_Shards[g_NextShardNum].colours[2][1] = 0xfb;
		g_Shards[g_NextShardNum].colours[2][2] = 0x7e;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				g_Shards[g_NextShardNum].colours[i][j] = random() % 0xff;
			}
		}

		g_Shards[g_NextShardNum].colours[0][3] = g_Shards[g_NextShardNum].colours[1][3] = g_Shards[g_NextShardNum].colours[2][3] = 0xff;
	}

	g_Shards[g_NextShardNum].rot.x = rotx;
	g_Shards[g_NextShardNum].rot.y = 0;
	g_Shards[g_NextShardNum].rot.z = random() * (1.0f / U32_MAX) * M_BADTAU;

	g_Shards[g_NextShardNum].rotspeed.x = random() * (1.0f / U32_MAX) * 0.1f;
	g_Shards[g_NextShardNum].rotspeed.y = random() * (1.0f / U32_MAX) * 0.1f;
	g_Shards[g_NextShardNum].rotspeed.z = random() * (1.0f / U32_MAX) * 0.1f;

	g_NextShardNum++;

	if (g_NextShardNum >= g_MaxShards) {
		g_NextShardNum = 0;
	}

	if (!g_ShardsActive) {
		g_ShardsActive = true;
	}
}
