#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/game_005fd0.h"
#include "game/game_096750.h"
#include "game/game_0d4690.h"
#include "game/game_11f000.h"
#include "game/game_141820.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_13900.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

s32 var8007f840 = 0x00000000;
u8 var8007f844 = 0;
u8 var8007f848 = 0;
u32 var8007f84c = 0x0000005a;
u32 var8007f850 = 0x00000003;
u32 var8007f854 = 0x00000000;
u32 var8007f858 = 0xb8000000;
u32 var8007f85c = 0x00000000;

GLOBAL_ASM(
glabel func0f141820
/*  f141820:	8fb90010 */ 	lw	$t9,0x10($sp)
/*  f141824:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f141828:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f14182c:	3c01f600 */ 	lui	$at,0xf600
/*  f141830:	01e1c025 */ 	or	$t8,$t7,$at
/*  f141834:	30ab03ff */ 	andi	$t3,$a1,0x3ff
/*  f141838:	30cd03ff */ 	andi	$t5,$a2,0x3ff
/*  f14183c:	332803ff */ 	andi	$t0,$t9,0x3ff
/*  f141840:	00084880 */ 	sll	$t1,$t0,0x2
/*  f141844:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f141848:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f14184c:	018e7825 */ 	or	$t7,$t4,$t6
/*  f141850:	03095025 */ 	or	$t2,$t8,$t1
/*  f141854:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f141858:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f14185c:	03e00008 */ 	jr	$ra
/*  f141860:	24820008 */ 	addiu	$v0,$a0,0x8
/*  f141864:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f141868:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14186c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f141870:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f141874:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f141878:	0c002f02 */ 	jal	viGetX
/*  f14187c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f141880:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f141884:	3c0ee700 */ 	lui	$t6,0xe700
/*  f141888:	3c0ffd88 */ 	lui	$t7,0xfd88
/*  f14188c:	00801825 */ 	or	$v1,$a0,$zero
/*  f141890:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141894:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f141898:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f14189c:	00802825 */ 	or	$a1,$a0,$zero
/*  f1418a0:	35ef013f */ 	ori	$t7,$t7,0x13f
/*  f1418a4:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f1418a8:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f1418ac:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f1418b0:	8fac001c */ 	lw	$t4,0x1c($sp)
/*  f1418b4:	00580019 */ 	multu	$v0,$t8
/*  f1418b8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1418bc:	00803025 */ 	or	$a2,$a0,$zero
/*  f1418c0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1418c4:	3c0ee600 */ 	lui	$t6,0xe600
/*  f1418c8:	00803825 */ 	or	$a3,$a0,$zero
/*  f1418cc:	3c0ff300 */ 	lui	$t7,0xf300
/*  f1418d0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1418d4:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f1418d8:	0000c812 */ 	mflo	$t9
/*  f1418dc:	03295021 */ 	addu	$t2,$t9,$t1
/*  f1418e0:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f1418e4:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f1418e8:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f1418ec:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f1418f0:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f1418f4:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f1418f8:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f1418fc:	8fa90024 */ 	lw	$t1,0x24($sp)
/*  f141900:	2508ffff */ 	addiu	$t0,$t0,-1
/*  f141904:	290107ff */ 	slti	$at,$t0,0x7ff
/*  f141908:	10200003 */ 	beqz	$at,.L0f141918
/*  f14190c:	312a0007 */ 	andi	$t2,$t1,0x7
/*  f141910:	10000001 */ 	b	.L0f141918
/*  f141914:	01001825 */ 	or	$v1,$t0,$zero
.L0f141918:
/*  f141918:	30780fff */ 	andi	$t8,$v1,0xfff
/*  f14191c:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f141920:	000a5e00 */ 	sll	$t3,$t2,0x18
/*  f141924:	032b6025 */ 	or	$t4,$t9,$t3
/*  f141928:	acec0004 */ 	sw	$t4,0x4($a3)
/*  f14192c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f141930:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f141934:	00801025 */ 	or	$v0,$a0,$zero
/*  f141938:	03e00008 */ 	jr	$ra
/*  f14193c:	00000000 */ 	nop
/*  f141940:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f141944:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f141948:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f14194c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f141950:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f141954:	0c002f02 */ 	jal	viGetX
/*  f141958:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f14195c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f141960:	3c0ee700 */ 	lui	$t6,0xe700
/*  f141964:	3c01fd10 */ 	lui	$at,0xfd10
/*  f141968:	00801825 */ 	or	$v1,$a0,$zero
/*  f14196c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f141970:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f141974:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f141978:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f14197c:	00802825 */ 	or	$a1,$a0,$zero
/*  f141980:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f141984:	30ef0fff */ 	andi	$t7,$a3,0xfff
/*  f141988:	01e1c025 */ 	or	$t8,$t7,$at
/*  f14198c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f141990:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f141994:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f141998:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f14199c:	00590019 */ 	multu	$v0,$t9
/*  f1419a0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1419a4:	00803025 */ 	or	$a2,$a0,$zero
/*  f1419a8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1419ac:	3c0fe600 */ 	lui	$t7,0xe600
/*  f1419b0:	00804025 */ 	or	$t0,$a0,$zero
/*  f1419b4:	3c18f300 */ 	lui	$t8,0xf300
/*  f1419b8:	28e107ff */ 	slti	$at,$a3,0x7ff
/*  f1419bc:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1419c0:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f1419c4:	00004812 */ 	mflo	$t1
/*  f1419c8:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f1419cc:	000b6040 */ 	sll	$t4,$t3,0x1
/*  f1419d0:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f1419d4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1419d8:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f1419dc:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1419e0:	10200003 */ 	beqz	$at,.L0f1419f0
/*  f1419e4:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f1419e8:	10000001 */ 	b	.L0f1419f0
/*  f1419ec:	00e01825 */ 	or	$v1,$a3,$zero
.L0f1419f0:
/*  f1419f0:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f1419f4:	30790fff */ 	andi	$t9,$v1,0xfff
/*  f1419f8:	00194b00 */ 	sll	$t1,$t9,0xc
/*  f1419fc:	314b0007 */ 	andi	$t3,$t2,0x7
/*  f141a00:	000b6600 */ 	sll	$t4,$t3,0x18
/*  f141a04:	012c6825 */ 	or	$t5,$t1,$t4
/*  f141a08:	ad0d0004 */ 	sw	$t5,0x4($t0)
/*  f141a0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f141a10:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f141a14:	00801025 */ 	or	$v0,$a0,$zero
/*  f141a18:	03e00008 */ 	jr	$ra
/*  f141a1c:	00000000 */ 	nop
/*  f141a20:	00801025 */ 	or	$v0,$a0,$zero
/*  f141a24:	3c0ee700 */ 	lui	$t6,0xe700
/*  f141a28:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f141a2c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f141a30:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f141a34:	24ad0001 */ 	addiu	$t5,$a1,0x1
/*  f141a38:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f141a3c:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f141a40:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f141a44:	332a0fff */ 	andi	$t2,$t9,0xfff
/*  f141a48:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f141a4c:	3c01e400 */ 	lui	$at,0xe400
/*  f141a50:	01616025 */ 	or	$t4,$t3,$at
/*  f141a54:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f141a58:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f141a5c:	24830008 */ 	addiu	$v1,$a0,0x8
/*  f141a60:	018fc025 */ 	or	$t8,$t4,$t7
/*  f141a64:	332a0fff */ 	andi	$t2,$t9,0xfff
/*  f141a68:	00056880 */ 	sll	$t5,$a1,0x2
/*  f141a6c:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f141a70:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f141a74:	016e6025 */ 	or	$t4,$t3,$t6
/*  f141a78:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f141a7c:	24680008 */ 	addiu	$t0,$v1,0x8
/*  f141a80:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f141a84:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f141a88:	00066e80 */ 	sll	$t5,$a2,0x1a
/*  f141a8c:	3c0fb400 */ 	lui	$t7,0xb400
/*  f141a90:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f141a94:	35ab0400 */ 	ori	$t3,$t5,0x400
/*  f141a98:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f141a9c:	3c18b300 */ 	lui	$t8,0xb300
/*  f141aa0:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f141aa4:	ad2b0004 */ 	sw	$t3,0x4($t1)
/*  f141aa8:	03e00008 */ 	jr	$ra
/*  f141aac:	25220008 */ 	addiu	$v0,$t1,0x8
);

GLOBAL_ASM(
glabel func0f141ab0
/*  f141ab0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f141ab4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f141ab8:	8fb0009c */ 	lw	$s0,0x9c($sp)
/*  f141abc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f141ac0:	afa50084 */ 	sw	$a1,0x84($sp)
/*  f141ac4:	2a010141 */ 	slti	$at,$s0,0x141
/*  f141ac8:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f141acc:	142000a5 */ 	bnez	$at,.L0f141d64
/*  f141ad0:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f141ad4:	06010003 */ 	bgez	$s0,.L0f141ae4
/*  f141ad8:	00103043 */ 	sra	$a2,$s0,0x1
/*  f141adc:	26010001 */ 	addiu	$at,$s0,0x1
/*  f141ae0:	00013043 */ 	sra	$a2,$at,0x1
.L0f141ae4:
/*  f141ae4:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f141ae8:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f141aec:	0c002f02 */ 	jal	viGetX
/*  f141af0:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f141af4:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f141af8:	3c0efd10 */ 	lui	$t6,0xfd10
/*  f141afc:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f141b00:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f141b04:	35ce013f */ 	ori	$t6,$t6,0x13f
/*  f141b08:	00801825 */ 	or	$v1,$a0,$zero
/*  f141b0c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f141b10:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f141b14:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f141b18:	3c0100ff */ 	lui	$at,0xff
/*  f141b1c:	004f0019 */ 	multu	$v0,$t7
/*  f141b20:	3421ffff */ 	ori	$at,$at,0xffff
/*  f141b24:	44902000 */ 	mtc1	$s0,$f4
/*  f141b28:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141b2c:	24c5ffff */ 	addiu	$a1,$a2,-1
/*  f141b30:	00804025 */ 	or	$t0,$a0,$zero
/*  f141b34:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141b38:	240207ff */ 	addiu	$v0,$zero,0x7ff
/*  f141b3c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f141b40:	0000c012 */ 	mflo	$t8
/*  f141b44:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f141b48:	00196840 */ 	sll	$t5,$t9,0x1
/*  f141b4c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f141b50:	01e1c024 */ 	and	$t8,$t7,$at
/*  f141b54:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f141b58:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f141b5c:	3c19f300 */ 	lui	$t9,0xf300
/*  f141b60:	10200003 */ 	beqz	$at,.L0f141b70
/*  f141b64:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f141b68:	10000001 */ 	b	.L0f141b70
/*  f141b6c:	00a01025 */ 	or	$v0,$a1,$zero
.L0f141b70:
/*  f141b70:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f141b74:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f141b78:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f141b7c:	46020183 */ 	div.s	$f6,$f0,$f2
/*  f141b80:	304f0fff */ 	andi	$t7,$v0,0xfff
/*  f141b84:	312d0007 */ 	andi	$t5,$t1,0x7
/*  f141b88:	000d4e00 */ 	sll	$t1,$t5,0x18
/*  f141b8c:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f141b90:	0309c825 */ 	or	$t9,$t8,$t1
/*  f141b94:	00e67821 */ 	addu	$t7,$a3,$a2
/*  f141b98:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f141b9c:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f141ba0:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f141ba4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f141ba8:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f141bac:	31ab0fff */ 	andi	$t3,$t5,0xfff
/*  f141bb0:	00196b00 */ 	sll	$t5,$t9,0xc
/*  f141bb4:	3c01e400 */ 	lui	$at,0xe400
/*  f141bb8:	01a17025 */ 	or	$t6,$t5,$at
/*  f141bbc:	3c014180 */ 	lui	$at,0x4180
/*  f141bc0:	44815000 */ 	mtc1	$at,$f10
/*  f141bc4:	3c014480 */ 	lui	$at,0x4480
/*  f141bc8:	44812000 */ 	mtc1	$at,$f4
/*  f141bcc:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f141bd0:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f141bd4:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f141bd8:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f141bdc:	00801825 */ 	or	$v1,$a0,$zero
/*  f141be0:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f141be4:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f141be8:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f141bec:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f141bf0:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f141bf4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f141bf8:	01d87825 */ 	or	$t7,$t6,$t8
/*  f141bfc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f141c00:	03006025 */ 	or	$t4,$t8,$zero
/*  f141c04:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f141c08:	3c18b400 */ 	lui	$t8,0xb400
/*  f141c0c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f141c10:	24a20008 */ 	addiu	$v0,$a1,0x8
/*  f141c14:	3c18b300 */ 	lui	$t8,0xb300
/*  f141c18:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f141c1c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f141c20:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f141c24:	440e9000 */ 	mfc1	$t6,$f18
/*  f141c28:	440d4000 */ 	mfc1	$t5,$f8
/*  f141c2c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f141c30:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f141c34:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f141c38:	35d00400 */ 	ori	$s0,$t6,0x400
/*  f141c3c:	ac500004 */ 	sw	$s0,0x4($v0)
/*  f141c40:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f141c44:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f141c48:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f141c4c:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f141c50:	00f83821 */ 	addu	$a3,$a3,$t8
/*  f141c54:	afa70098 */ 	sw	$a3,0x98($sp)
/*  f141c58:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f141c5c:	0c002f02 */ 	jal	viGetX
/*  f141c60:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f141c64:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f141c68:	3c19fd10 */ 	lui	$t9,0xfd10
/*  f141c6c:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f141c70:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f141c74:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f141c78:	8fac0020 */ 	lw	$t4,0x20($sp)
/*  f141c7c:	3739013f */ 	ori	$t9,$t9,0x13f
/*  f141c80:	00801825 */ 	or	$v1,$a0,$zero
/*  f141c84:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f141c88:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f141c8c:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f141c90:	3c0100ff */ 	lui	$at,0xff
/*  f141c94:	004d0019 */ 	multu	$v0,$t5
/*  f141c98:	3421ffff */ 	ori	$at,$at,0xffff
/*  f141c9c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141ca0:	00804025 */ 	or	$t0,$a0,$zero
/*  f141ca4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141ca8:	240207ff */ 	addiu	$v0,$zero,0x7ff
/*  f141cac:	00007012 */ 	mflo	$t6
/*  f141cb0:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f141cb4:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f141cb8:	03196821 */ 	addu	$t5,$t8,$t9
/*  f141cbc:	01a17024 */ 	and	$t6,$t5,$at
/*  f141cc0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f141cc4:	3c0ff300 */ 	lui	$t7,0xf300
/*  f141cc8:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f141ccc:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f141cd0:	00801825 */ 	or	$v1,$a0,$zero
/*  f141cd4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141cd8:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f141cdc:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f141ce0:	10200003 */ 	beqz	$at,.L0f141cf0
/*  f141ce4:	00000000 */ 	nop
/*  f141ce8:	10000001 */ 	b	.L0f141cf0
/*  f141cec:	00a01025 */ 	or	$v0,$a1,$zero
.L0f141cf0:
/*  f141cf0:	30580fff */ 	andi	$t8,$v0,0xfff
/*  f141cf4:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f141cf8:	03296825 */ 	or	$t5,$t9,$t1
/*  f141cfc:	ad0d0004 */ 	sw	$t5,0x4($t0)
/*  f141d00:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f141d04:	3c01e400 */ 	lui	$at,0xe400
/*  f141d08:	00802825 */ 	or	$a1,$a0,$zero
/*  f141d0c:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f141d10:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f141d14:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f141d18:	00196b00 */ 	sll	$t5,$t9,0xc
/*  f141d1c:	01a17025 */ 	or	$t6,$t5,$at
/*  f141d20:	0007c080 */ 	sll	$t8,$a3,0x2
/*  f141d24:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f141d28:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f141d2c:	00196b00 */ 	sll	$t5,$t9,0xc
/*  f141d30:	01ac7025 */ 	or	$t6,$t5,$t4
/*  f141d34:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f141d38:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f141d3c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141d40:	00803025 */ 	or	$a2,$a0,$zero
/*  f141d44:	3c0fb400 */ 	lui	$t7,0xb400
/*  f141d48:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f141d4c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f141d50:	3c18b300 */ 	lui	$t8,0xb300
/*  f141d54:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f141d58:	acd00004 */ 	sw	$s0,0x4($a2)
/*  f141d5c:	10000058 */ 	b	.L0f141ec0
/*  f141d60:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f141d64:
/*  f141d64:	0c002f02 */ 	jal	viGetX
/*  f141d68:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f141d6c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f141d70:	3c19fd10 */ 	lui	$t9,0xfd10
/*  f141d74:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f141d78:	3739013f */ 	ori	$t9,$t9,0x13f
/*  f141d7c:	00801825 */ 	or	$v1,$a0,$zero
/*  f141d80:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f141d84:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f141d88:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f141d8c:	3c0100ff */ 	lui	$at,0xff
/*  f141d90:	004d0019 */ 	multu	$v0,$t5
/*  f141d94:	3421ffff */ 	ori	$at,$at,0xffff
/*  f141d98:	44905000 */ 	mtc1	$s0,$f10
/*  f141d9c:	2605ffff */ 	addiu	$a1,$s0,-1
/*  f141da0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141da4:	00803025 */ 	or	$a2,$a0,$zero
/*  f141da8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141dac:	240207ff */ 	addiu	$v0,$zero,0x7ff
/*  f141db0:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f141db4:	00007012 */ 	mflo	$t6
/*  f141db8:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f141dbc:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f141dc0:	03196821 */ 	addu	$t5,$t8,$t9
/*  f141dc4:	01a17024 */ 	and	$t6,$t5,$at
/*  f141dc8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f141dcc:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f141dd0:	3c0ff300 */ 	lui	$t7,0xf300
/*  f141dd4:	10200003 */ 	beqz	$at,.L0f141de4
/*  f141dd8:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f141ddc:	10000001 */ 	b	.L0f141de4
/*  f141de0:	00a01025 */ 	or	$v0,$a1,$zero
.L0f141de4:
/*  f141de4:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f141de8:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f141dec:	30580fff */ 	andi	$t8,$v0,0xfff
/*  f141df0:	46020403 */ 	div.s	$f16,$f0,$f2
/*  f141df4:	31ae0007 */ 	andi	$t6,$t5,0x7
/*  f141df8:	000e7e00 */ 	sll	$t7,$t6,0x18
/*  f141dfc:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f141e00:	032fc025 */ 	or	$t8,$t9,$t7
/*  f141e04:	00f06821 */ 	addu	$t5,$a3,$s0
/*  f141e08:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f141e0c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f141e10:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f141e14:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f141e18:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f141e1c:	3c01e400 */ 	lui	$at,0xe400
/*  f141e20:	01e1c025 */ 	or	$t8,$t7,$at
/*  f141e24:	3c014180 */ 	lui	$at,0x4180
/*  f141e28:	44812000 */ 	mtc1	$at,$f4
/*  f141e2c:	3c014480 */ 	lui	$at,0x4480
/*  f141e30:	44815000 */ 	mtc1	$at,$f10
/*  f141e34:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f141e38:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f141e3c:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f141e40:	03197825 */ 	or	$t7,$t8,$t9
/*  f141e44:	00076880 */ 	sll	$t5,$a3,0x2
/*  f141e48:	00801825 */ 	or	$v1,$a0,$zero
/*  f141e4c:	46100481 */ 	sub.s	$f18,$f0,$f16
/*  f141e50:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f141e54:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f141e58:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f141e5c:	000ac880 */ 	sll	$t9,$t2,0x2
/*  f141e60:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f141e64:	000ec300 */ 	sll	$t8,$t6,0xc
/*  f141e68:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f141e6c:	030f6825 */ 	or	$t5,$t8,$t7
/*  f141e70:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141e74:	00802825 */ 	or	$a1,$a0,$zero
/*  f141e78:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f141e7c:	3c0eb400 */ 	lui	$t6,0xb400
/*  f141e80:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f141e84:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141e88:	00801025 */ 	or	$v0,$a0,$zero
/*  f141e8c:	3c0eb300 */ 	lui	$t6,0xb300
/*  f141e90:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141e94:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f141e98:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f141e9c:	440f4000 */ 	mfc1	$t7,$f8
/*  f141ea0:	00000000 */ 	nop
/*  f141ea4:	000f6c00 */ 	sll	$t5,$t7,0x10
/*  f141ea8:	440f9000 */ 	mfc1	$t7,$f18
/*  f141eac:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f141eb0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f141eb4:	000f6c00 */ 	sll	$t5,$t7,0x10
/*  f141eb8:	35ae0400 */ 	ori	$t6,$t5,0x400
/*  f141ebc:	ac4e0004 */ 	sw	$t6,0x4($v0)
.L0f141ec0:
/*  f141ec0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f141ec4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f141ec8:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f141ecc:	03e00008 */ 	jr	$ra
/*  f141ed0:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0f141ed4
/*  f141ed4:	3c013f80 */ 	lui	$at,0x3f80
/*  f141ed8:	44866000 */ 	mtc1	$a2,$f12
/*  f141edc:	44812000 */ 	mtc1	$at,$f4
/*  f141ee0:	30a803ff */ 	andi	$t0,$a1,0x3ff
/*  f141ee4:	0008c880 */ 	sll	$t9,$t0,0x2
/*  f141ee8:	4604603c */ 	c.lt.s	$f12,$f4
/*  f141eec:	8fa20010 */ 	lw	$v0,0x10($sp)
/*  f141ef0:	03204025 */ 	or	$t0,$t9,$zero
/*  f141ef4:	4500006c */ 	bc1f	.L0f1420a8
/*  f141ef8:	00000000 */ 	nop
/*  f141efc:	44823000 */ 	mtc1	$v0,$f6
/*  f141f00:	3c013f00 */ 	lui	$at,0x3f00
/*  f141f04:	44815000 */ 	mtc1	$at,$f10
/*  f141f08:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f141f0c:	44878000 */ 	mtc1	$a3,$f16
/*  f141f10:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f141f14:	00801825 */ 	or	$v1,$a0,$zero
/*  f141f18:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141f1c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f141f20:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f141f24:	24a60001 */ 	addiu	$a2,$a1,0x1
/*  f141f28:	30d803ff */ 	andi	$t8,$a2,0x3ff
/*  f141f2c:	00804825 */ 	or	$t1,$a0,$zero
/*  f141f30:	3c0af600 */ 	lui	$t2,0xf600
/*  f141f34:	00183080 */ 	sll	$a2,$t8,0x2
/*  f141f38:	3c014f00 */ 	lui	$at,0x4f00
/*  f141f3c:	46006102 */ 	mul.s	$f4,$f12,$f0
/*  f141f40:	46009080 */ 	add.s	$f2,$f18,$f0
/*  f141f44:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141f48:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f141f4c:	440f3000 */ 	mfc1	$t7,$f6
/*  f141f50:	00000000 */ 	nop
/*  f141f54:	448f4000 */ 	mtc1	$t7,$f8
/*  f141f58:	00000000 */ 	nop
/*  f141f5c:	468043a0 */ 	cvt.s.w	$f14,$f8
/*  f141f60:	460e1281 */ 	sub.s	$f10,$f2,$f14
/*  f141f64:	444bf800 */ 	cfc1	$t3,$31
/*  f141f68:	44ccf800 */ 	ctc1	$t4,$31
/*  f141f6c:	00000000 */ 	nop
/*  f141f70:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f141f74:	444cf800 */ 	cfc1	$t4,$31
/*  f141f78:	00000000 */ 	nop
/*  f141f7c:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f141f80:	51800013 */ 	beqzl	$t4,.L0f141fd0
/*  f141f84:	440c8000 */ 	mfc1	$t4,$f16
/*  f141f88:	44818000 */ 	mtc1	$at,$f16
/*  f141f8c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f141f90:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f141f94:	44ccf800 */ 	ctc1	$t4,$31
/*  f141f98:	00000000 */ 	nop
/*  f141f9c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f141fa0:	444cf800 */ 	cfc1	$t4,$31
/*  f141fa4:	00000000 */ 	nop
/*  f141fa8:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f141fac:	15800005 */ 	bnez	$t4,.L0f141fc4
/*  f141fb0:	00000000 */ 	nop
/*  f141fb4:	440c8000 */ 	mfc1	$t4,$f16
/*  f141fb8:	3c018000 */ 	lui	$at,0x8000
/*  f141fbc:	10000007 */ 	b	.L0f141fdc
/*  f141fc0:	01816025 */ 	or	$t4,$t4,$at
.L0f141fc4:
/*  f141fc4:	10000005 */ 	b	.L0f141fdc
/*  f141fc8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f141fcc:	440c8000 */ 	mfc1	$t4,$f16
.L0f141fd0:
/*  f141fd0:	00000000 */ 	nop
/*  f141fd4:	0580fffb */ 	bltz	$t4,.L0f141fc4
/*  f141fd8:	00000000 */ 	nop
.L0f141fdc:
/*  f141fdc:	44cbf800 */ 	ctc1	$t3,$31
/*  f141fe0:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f141fe4:	30eb03ff */ 	andi	$t3,$a3,0x3ff
/*  f141fe8:	460e1480 */ 	add.s	$f18,$f2,$f14
/*  f141fec:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f141ff0:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f141ff4:	01996825 */ 	or	$t5,$t4,$t9
/*  f141ff8:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f141ffc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f142000:	444cf800 */ 	cfc1	$t4,$31
/*  f142004:	44cdf800 */ 	ctc1	$t5,$31
/*  f142008:	01ca7825 */ 	or	$t7,$t6,$t2
/*  f14200c:	01e6c025 */ 	or	$t8,$t7,$a2
/*  f142010:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f142014:	00e27021 */ 	addu	$t6,$a3,$v0
/*  f142018:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f14201c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f142020:	444df800 */ 	cfc1	$t5,$31
/*  f142024:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f142028:	030ac825 */ 	or	$t9,$t8,$t2
/*  f14202c:	03265825 */ 	or	$t3,$t9,$a2
/*  f142030:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f142034:	11a00013 */ 	beqz	$t5,.L0f142084
/*  f142038:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f14203c:	3c014f00 */ 	lui	$at,0x4f00
/*  f142040:	44812000 */ 	mtc1	$at,$f4
/*  f142044:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f142048:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f14204c:	44cdf800 */ 	ctc1	$t5,$31
/*  f142050:	00000000 */ 	nop
/*  f142054:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f142058:	444df800 */ 	cfc1	$t5,$31
/*  f14205c:	00000000 */ 	nop
/*  f142060:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f142064:	15a00005 */ 	bnez	$t5,.L0f14207c
/*  f142068:	00000000 */ 	nop
/*  f14206c:	440d2000 */ 	mfc1	$t5,$f4
/*  f142070:	3c018000 */ 	lui	$at,0x8000
/*  f142074:	10000007 */ 	b	.L0f142094
/*  f142078:	01a16825 */ 	or	$t5,$t5,$at
.L0f14207c:
/*  f14207c:	10000005 */ 	b	.L0f142094
/*  f142080:	240dffff */ 	addiu	$t5,$zero,-1
.L0f142084:
/*  f142084:	440d2000 */ 	mfc1	$t5,$f4
/*  f142088:	00000000 */ 	nop
/*  f14208c:	05a0fffb */ 	bltz	$t5,.L0f14207c
/*  f142090:	00000000 */ 	nop
.L0f142094:
/*  f142094:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f142098:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f14209c:	44ccf800 */ 	ctc1	$t4,$31
/*  f1420a0:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f1420a4:	ad380004 */ 	sw	$t8,0x4($t1)
.L0f1420a8:
/*  f1420a8:	03e00008 */ 	jr	$ra
/*  f1420ac:	00801025 */ 	or	$v0,$a0,$zero
);

Gfx *func0f1420b0(Gfx *gdl, u32 colour, u32 alpha)
{
	static u32 envcol = 0xffffffff;
	static u32 primcol = 0x7f7f7fff;

	func0000db30("envcol", &envcol);
	func0000db30("primcol", &primcol);

	gDPPipeSync(gdl++);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 5, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, G_TX_RENDERTILE, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x0800, 0x0020);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetColor(gdl++, G_SETENVCOLOR, colour & 0xffffff00 | alpha & 0xff);
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetAlphaDither(gdl++, G_AD_NOISE);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_NOOP2);

	return gdl;
}

Gfx *func0f142274(Gfx *gdl, u32 colour, u32 alpha)
{
	static u32 envcol = 0xffffffff;
	static u32 primcol = 0x7f7f7fff;

	func0000db30("envcol", &envcol);
	func0000db30("primcol", &primcol);

	gDPPipeSync(gdl++);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_8b, 0, 0x0000, 5, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 160, 0, G_TX_RENDERTILE, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x0800, 0x0020);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetColor(gdl++, G_SETENVCOLOR, colour & 0xffffff00 | alpha & 0xff);
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetAlphaDither(gdl++, G_AD_NOISE);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_NOOP2);

	return gdl;
}

GLOBAL_ASM(
glabel hudRenderMotionBlur
/*  f142438:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f14243c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f142440:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f142444:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f142448:	00c08825 */ 	or	$s1,$a2,$zero
/*  f14244c:	00809025 */ 	or	$s2,$a0,$zero
/*  f142450:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f142454:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f142458:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f14245c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f142460:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f142464:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f142468:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f14246c:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f142470:	0c002acb */ 	jal	vi2GetUnk28
/*  f142474:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f142478:	0c002f44 */ 	jal	viGetViewTop
/*  f14247c:	0040b025 */ 	or	$s6,$v0,$zero
/*  f142480:	0c002f26 */ 	jal	viGetViewY
/*  f142484:	00409825 */ 	or	$s3,$v0,$zero
/*  f142488:	0c002f22 */ 	jal	viGetViewX
/*  f14248c:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f142490:	0c002f40 */ 	jal	viGetViewLeft
/*  f142494:	0040a025 */ 	or	$s4,$v0,$zero
/*  f142498:	3c038008 */ 	lui	$v1,%hi(var8007f848)
/*  f14249c:	2463f848 */ 	addiu	$v1,$v1,%lo(var8007f848)
/*  f1424a0:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f1424a4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1424a8:	3c028008 */ 	lui	$v0,%hi(var8007f844)
/*  f1424ac:	11c00003 */ 	beqz	$t6,.L0f1424bc
/*  f1424b0:	2442f844 */ 	addiu	$v0,$v0,%lo(var8007f844)
/*  f1424b4:	10000056 */ 	b	.L0f142610
/*  f1424b8:	02401025 */ 	or	$v0,$s2,$zero
.L0f1424bc:
/*  f1424bc:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1424c0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1424c4:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f1424c8:	02388021 */ 	addu	$s0,$s1,$t8
/*  f1424cc:	2a0100e7 */ 	slti	$at,$s0,0xe7
/*  f1424d0:	14200002 */ 	bnez	$at,.L0f1424dc
/*  f1424d4:	3c047f1b */ 	lui	$a0,%hi(var7f1b5d90)
/*  f1424d8:	241000e6 */ 	addiu	$s0,$zero,0xe6
.L0f1424dc:
/*  f1424dc:	3c058008 */ 	lui	$a1,%hi(var8007f874)
/*  f1424e0:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f1424e4:	24a5f874 */ 	addiu	$a1,$a1,%lo(var8007f874)
/*  f1424e8:	0c0036cc */ 	jal	func0000db30
/*  f1424ec:	24845d90 */ 	addiu	$a0,$a0,%lo(var7f1b5d90)
/*  f1424f0:	3c198008 */ 	lui	$t9,%hi(var8007f874)
/*  f1424f4:	8f39f874 */ 	lw	$t9,%lo(var8007f874)($t9)
/*  f1424f8:	3c01447a */ 	lui	$at,0x447a
/*  f1424fc:	4481b000 */ 	mtc1	$at,$f22
/*  f142500:	44992000 */ 	mtc1	$t9,$f4
/*  f142504:	3c047f1b */ 	lui	$a0,%hi(var7f1b5d98)
/*  f142508:	07210005 */ 	bgez	$t9,.L0f142520
/*  f14250c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f142510:	3c014f80 */ 	lui	$at,0x4f80
/*  f142514:	44814000 */ 	mtc1	$at,$f8
/*  f142518:	00000000 */ 	nop
/*  f14251c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f142520:
/*  f142520:	3c058008 */ 	lui	$a1,%hi(var8007f870)
/*  f142524:	46163603 */ 	div.s	$f24,$f6,$f22
/*  f142528:	24a5f870 */ 	addiu	$a1,$a1,%lo(var8007f870)
/*  f14252c:	0c0036cc */ 	jal	func0000db30
/*  f142530:	24845d98 */ 	addiu	$a0,$a0,%lo(var7f1b5d98)
/*  f142534:	3c088008 */ 	lui	$t0,%hi(var8007f870)
/*  f142538:	8d08f870 */ 	lw	$t0,%lo(var8007f870)($t0)
/*  f14253c:	3c014f80 */ 	lui	$at,0x4f80
/*  f142540:	44885000 */ 	mtc1	$t0,$f10
/*  f142544:	05010004 */ 	bgez	$t0,.L0f142558
/*  f142548:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f14254c:	44819000 */ 	mtc1	$at,$f18
/*  f142550:	00000000 */ 	nop
/*  f142554:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f142558:
/*  f142558:	46168083 */ 	div.s	$f2,$f16,$f22
/*  f14255c:	02401025 */ 	or	$v0,$s2,$zero
/*  f142560:	3c09e700 */ 	lui	$t1,0xe700
/*  f142564:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f142568:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f14256c:	8faa006c */ 	lw	$t2,0x6c($sp)
/*  f142570:	3c013f00 */ 	lui	$at,0x3f00
/*  f142574:	44815000 */ 	mtc1	$at,$f10
/*  f142578:	448a2000 */ 	mtc1	$t2,$f4
/*  f14257c:	26440008 */ 	addiu	$a0,$s2,0x8
/*  f142580:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*  f142584:	02003025 */ 	or	$a2,$s0,$zero
/*  f142588:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f14258c:	e7a20064 */ 	swc1	$f2,0x64($sp)
/*  f142590:	46020203 */ 	div.s	$f8,$f0,$f2
/*  f142594:	46080181 */ 	sub.s	$f6,$f0,$f8
/*  f142598:	460a3502 */ 	mul.s	$f20,$f6,$f10
/*  f14259c:	0fc5082c */ 	jal	func0f1420b0
/*  f1425a0:	00000000 */ 	nop
/*  f1425a4:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1425a8:	c7a20064 */ 	lwc1	$f2,0x64($sp)
/*  f1425ac:	00409025 */ 	or	$s2,$v0,$zero
/*  f1425b0:	026b8821 */ 	addu	$s1,$s3,$t3
/*  f1425b4:	0271082a */ 	slt	$at,$s3,$s1
/*  f1425b8:	10200014 */ 	beqz	$at,.L0f14260c
/*  f1425bc:	02608025 */ 	or	$s0,$s3,$zero
/*  f1425c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1425c4:	44819000 */ 	mtc1	$at,$f18
/*  f1425c8:	00000000 */ 	nop
/*  f1425cc:	46029583 */ 	div.s	$f22,$f18,$f2
.L0f1425d0:
/*  f1425d0:	4600a40d */ 	trunc.w.s	$f16,$f20
/*  f1425d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1425d8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f1425dc:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1425e0:	440d8000 */ 	mfc1	$t5,$f16
/*  f1425e4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1425e8:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f1425ec:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f1425f0:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f1425f4:	0fc506ac */ 	jal	func0f141ab0
/*  f1425f8:	01b33021 */ 	addu	$a2,$t5,$s3
/*  f1425fc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f142600:	00409025 */ 	or	$s2,$v0,$zero
/*  f142604:	1611fff2 */ 	bne	$s0,$s1,.L0f1425d0
/*  f142608:	4616a500 */ 	add.s	$f20,$f20,$f22
.L0f14260c:
/*  f14260c:	02401025 */ 	or	$v0,$s2,$zero
.L0f142610:
/*  f142610:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f142614:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f142618:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f14261c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f142620:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f142624:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f142628:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f14262c:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f142630:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f142634:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f142638:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f14263c:	03e00008 */ 	jr	$ra
/*  f142640:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

const char var7f1b5d90[] = "sfxxx";
const char var7f1b5d98[] = "sfyyy";

Gfx *hudRenderStatic(Gfx *gdl, u32 arg1, s32 arg2)
{
	s32 unk28 = vi2GetUnk28();
	s32 top = viGetViewTop();
	s32 y = viGetViewY();
	s32 x = viGetViewX();
	s32 left = viGetViewLeft();
	s32 rand = random() & 0xfff00 | 0x80000000;
	s32 ypos;

	gDPPipeSync(gdl++);

	gdl = func0f142274(gdl, arg1, arg2);

	for (ypos = top; ypos < top + y; ypos++) {
		gdl = func0f141ab0(gdl, rand, random() % 240, 5, ypos, 1.0f, left, x);
	}

	if (rand) {
		// empty
	}

	return gdl;
}

Gfx *hudRenderSlayerRocketLens(Gfx *gdl, u32 colour, u32 alpha)
{
	s32 sp7c = viGetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewY();
	s32 viewwidth = viGetViewX();
	s32 y;
	s32 viewleft = viGetViewLeft();
	f32 angle = 0.52359879016876f;
	s32 offset = (s32)(var80061630 * 600.0f) % 12;
	f32 increment;
	s32 offsety;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "interlaceGfx");

	gDPPipeSync(gdl++);

	increment = (2.6179938316345f - angle) / viewheight;

	gdl = func0f1420b0(gdl, colour, alpha);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		offsety = y - offset;

		if ((offsety % 8) == 0 || y == viewtop) {
			if ((offsety % 16) < 8) {
				gDPSetEnvColor(gdl++, 0xff, 0xff, 0x00, 0xff);
			} else {
				gDPSetEnvColor(gdl++, 0xff, 0xff, 0xbf, 0xff);
			}
		}

		gdl = func0f141ab0(gdl, sp7c, y, 5, y, 2.0f - sinf(angle), viewleft, viewwidth);

		angle += increment;
	}

	return gdl;
}

const char var7f1b5db0[] = "BlueInterlaceGfx";
const char var7f1b5dc4[] = "stretchBlurGfx";
const char var7f1b5dd4[] = "blurGfxFisheye";

GLOBAL_ASM(
glabel func0f14298c
/*  f14298c:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f142990:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f142994:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f142998:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f14299c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f1429a0:	00a08025 */ 	or	$s0,$a1,$zero
/*  f1429a4:	00809825 */ 	or	$s3,$a0,$zero
/*  f1429a8:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f1429ac:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f1429b0:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f1429b4:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f1429b8:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f1429bc:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f1429c0:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f1429c4:	0c002ac7 */ 	jal	viGetUnk28
/*  f1429c8:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f1429cc:	0c002f44 */ 	jal	viGetViewTop
/*  f1429d0:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f1429d4:	0c002f26 */ 	jal	viGetViewY
/*  f1429d8:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f1429dc:	0c002f22 */ 	jal	viGetViewX
/*  f1429e0:	00408825 */ 	or	$s1,$v0,$zero
/*  f1429e4:	0c002f40 */ 	jal	viGetViewLeft
/*  f1429e8:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f1429ec:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f1429f0:	c4241630 */ 	lwc1	$f4,%lo(var80061630)($at)
/*  f1429f4:	3c014416 */ 	lui	$at,0x4416
/*  f1429f8:	44813000 */ 	mtc1	$at,$f6
/*  f1429fc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f142a00:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f142a04:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f142a08:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f142a0c:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f142a10:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f142a14:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f142a18:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f142a1c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f142a20:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f142a24:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f142a28:	3c057f1b */ 	lui	$a1,%hi(var7f1b5db0)
/*  f142a2c:	44125000 */ 	mfc1	$s2,$f10
/*  f142a30:	00000000 */ 	nop
/*  f142a34:	0241001a */ 	div	$zero,$s2,$at
/*  f142a38:	00009010 */ 	mfhi	$s2
/*  f142a3c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f142a40:	14200003 */ 	bnez	$at,.L0f142a50
/*  f142a44:	00000000 */ 	nop
/*  f142a48:	1000005c */ 	b	.L0f142bbc
/*  f142a4c:	02601025 */ 	or	$v0,$s3,$zero
.L0f142a50:
/*  f142a50:	0c004c4c */ 	jal	strcpy
/*  f142a54:	24a55db0 */ 	addiu	$a1,$a1,%lo(var7f1b5db0)
/*  f142a58:	02601825 */ 	or	$v1,$s3,$zero
/*  f142a5c:	3c09e700 */ 	lui	$t1,0xe700
/*  f142a60:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f142a64:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f142a68:	26640008 */ 	addiu	$a0,$s3,0x8
/*  f142a6c:	02002825 */ 	or	$a1,$s0,$zero
/*  f142a70:	0fc5082c */ 	jal	func0f1420b0
/*  f142a74:	02803025 */ 	or	$a2,$s4,$zero
/*  f142a78:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f142a7c:	00409825 */ 	or	$s3,$v0,$zero
/*  f142a80:	241e0014 */ 	addiu	$s8,$zero,0x14
/*  f142a84:	00915021 */ 	addu	$t2,$a0,$s1
/*  f142a88:	008a082a */ 	slt	$at,$a0,$t2
/*  f142a8c:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f142a90:	01405825 */ 	or	$t3,$t2,$zero
/*  f142a94:	10200048 */ 	beqz	$at,.L0f142bb8
/*  f142a98:	00808025 */ 	or	$s0,$a0,$zero
/*  f142a9c:	3c013f80 */ 	lui	$at,0x3f80
/*  f142aa0:	3c167fff */ 	lui	$s6,0x7fff
/*  f142aa4:	4481a000 */ 	mtc1	$at,$f20
/*  f142aa8:	36d6ffff */ 	ori	$s6,$s6,0xffff
/*  f142aac:	00928823 */ 	subu	$s1,$a0,$s2
/*  f142ab0:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f142ab4:	24150006 */ 	addiu	$s5,$zero,0x6
/*  f142ab8:	3c14fb00 */ 	lui	$s4,0xfb00
.L0f142abc:
/*  f142abc:	0235001a */ 	div	$zero,$s1,$s5
/*  f142ac0:	00006010 */ 	mfhi	$t4
/*  f142ac4:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f142ac8:	02009025 */ 	or	$s2,$s0,$zero
/*  f142acc:	16a00002 */ 	bnez	$s5,.L0f142ad8
/*  f142ad0:	00000000 */ 	nop
/*  f142ad4:	0007000d */ 	break	0x7
.L0f142ad8:
/*  f142ad8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f142adc:	16a10004 */ 	bne	$s5,$at,.L0f142af0
/*  f142ae0:	3c018000 */ 	lui	$at,0x8000
/*  f142ae4:	16210002 */ 	bne	$s1,$at,.L0f142af0
/*  f142ae8:	00000000 */ 	nop
/*  f142aec:	0006000d */ 	break	0x6
.L0f142af0:
/*  f142af0:	2401000c */ 	addiu	$at,$zero,0xc
/*  f142af4:	11800003 */ 	beqz	$t4,.L0f142b04
/*  f142af8:	00000000 */ 	nop
/*  f142afc:	1604000e */ 	bne	$s0,$a0,.L0f142b38
/*  f142b00:	00000000 */ 	nop
.L0f142b04:
/*  f142b04:	0221001a */ 	div	$zero,$s1,$at
/*  f142b08:	00006810 */ 	mfhi	$t5
/*  f142b0c:	29a10006 */ 	slti	$at,$t5,0x6
/*  f142b10:	10200005 */ 	beqz	$at,.L0f142b28
/*  f142b14:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f142b18:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f142b1c:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f142b20:	10000005 */ 	b	.L0f142b38
/*  f142b24:	ac560004 */ 	sw	$s6,0x4($v0)
.L0f142b28:
/*  f142b28:	3c0e00af */ 	lui	$t6,0xaf
/*  f142b2c:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f142b30:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f142b34:	ac540000 */ 	sw	$s4,0x0($v0)
.L0f142b38:
/*  f142b38:	0c004b70 */ 	jal	random
/*  f142b3c:	00000000 */ 	nop
/*  f142b40:	005e001b */ 	divu	$zero,$v0,$s8
/*  f142b44:	00007810 */ 	mfhi	$t7
/*  f142b48:	17c00002 */ 	bnez	$s8,.L0f142b54
/*  f142b4c:	00000000 */ 	nop
/*  f142b50:	0007000d */ 	break	0x7
.L0f142b54:
/*  f142b54:	56ef0009 */ 	bnel	$s7,$t7,.L0f142b7c
/*  f142b58:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f142b5c:	0c004b70 */ 	jal	random
/*  f142b60:	00000000 */ 	nop
/*  f142b64:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f142b68:	0041001b */ 	divu	$zero,$v0,$at
/*  f142b6c:	00009010 */ 	mfhi	$s2
/*  f142b70:	00000000 */ 	nop
/*  f142b74:	00000000 */ 	nop
/*  f142b78:	8fb80078 */ 	lw	$t8,0x78($sp)
.L0f142b7c:
/*  f142b7c:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f142b80:	02602025 */ 	or	$a0,$s3,$zero
/*  f142b84:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f142b88:	02403025 */ 	or	$a2,$s2,$zero
/*  f142b8c:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f142b90:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f142b94:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f142b98:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f142b9c:	0fc506ac */ 	jal	func0f141ab0
/*  f142ba0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f142ba4:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f142ba8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f142bac:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f142bb0:	1608ffc2 */ 	bne	$s0,$t0,.L0f142abc
/*  f142bb4:	00409825 */ 	or	$s3,$v0,$zero
.L0f142bb8:
/*  f142bb8:	02601025 */ 	or	$v0,$s3,$zero
.L0f142bbc:
/*  f142bbc:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f142bc0:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f142bc4:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f142bc8:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f142bcc:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f142bd0:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f142bd4:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f142bd8:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f142bdc:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f142be0:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f142be4:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f142be8:	03e00008 */ 	jr	$ra
/*  f142bec:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f142bf0
/*  f142bf0:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f142bf4:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f142bf8:	4487c000 */ 	mtc1	$a3,$f24
/*  f142bfc:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f142c00:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f142c04:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f142c08:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f142c0c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f142c10:	00c08825 */ 	or	$s1,$a2,$zero
/*  f142c14:	00809025 */ 	or	$s2,$a0,$zero
/*  f142c18:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f142c1c:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f142c20:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f142c24:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f142c28:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f142c2c:	0c002acb */ 	jal	vi2GetUnk28
/*  f142c30:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f142c34:	0c002f44 */ 	jal	viGetViewTop
/*  f142c38:	0040b025 */ 	or	$s6,$v0,$zero
/*  f142c3c:	0c002f26 */ 	jal	viGetViewY
/*  f142c40:	0040a825 */ 	or	$s5,$v0,$zero
/*  f142c44:	0c002f22 */ 	jal	viGetViewX
/*  f142c48:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f142c4c:	0c002f40 */ 	jal	viGetViewLeft
/*  f142c50:	00409825 */ 	or	$s3,$v0,$zero
/*  f142c54:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f142c58:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f142c5c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f142c60:	0040a025 */ 	or	$s4,$v0,$zero
/*  f142c64:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f142c68:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f142c6c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f142c70:	14200003 */ 	bnez	$at,.L0f142c80
/*  f142c74:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f142c78:	10000031 */ 	b	.L0f142d40
/*  f142c7c:	02401025 */ 	or	$v0,$s2,$zero
.L0f142c80:
/*  f142c80:	3c057f1b */ 	lui	$a1,%hi(var7f1b5dc4)
/*  f142c84:	24a55dc4 */ 	addiu	$a1,$a1,%lo(var7f1b5dc4)
/*  f142c88:	0c004c4c */ 	jal	strcpy
/*  f142c8c:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f142c90:	3c19e700 */ 	lui	$t9,0xe700
/*  f142c94:	ae590000 */ 	sw	$t9,0x0($s2)
/*  f142c98:	ae400004 */ 	sw	$zero,0x4($s2)
/*  f142c9c:	8fa80064 */ 	lw	$t0,0x64($sp)
/*  f142ca0:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*  f142ca4:	3c013f00 */ 	lui	$at,0x3f00
/*  f142ca8:	44882000 */ 	mtc1	$t0,$f4
/*  f142cac:	44818000 */ 	mtc1	$at,$f16
/*  f142cb0:	26440008 */ 	addiu	$a0,$s2,0x8
/*  f142cb4:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f142cb8:	02002825 */ 	or	$a1,$s0,$zero
/*  f142cbc:	02203025 */ 	or	$a2,$s1,$zero
/*  f142cc0:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f142cc4:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f142cc8:	46105502 */ 	mul.s	$f20,$f10,$f16
/*  f142ccc:	0fc5082c */ 	jal	func0f1420b0
/*  f142cd0:	00000000 */ 	nop
/*  f142cd4:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f142cd8:	00409025 */ 	or	$s2,$v0,$zero
/*  f142cdc:	02a08025 */ 	or	$s0,$s5,$zero
/*  f142ce0:	02a98821 */ 	addu	$s1,$s5,$t1
/*  f142ce4:	02b1082a */ 	slt	$at,$s5,$s1
/*  f142ce8:	10200014 */ 	beqz	$at,.L0f142d3c
/*  f142cec:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f142cf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f142cf4:	44819000 */ 	mtc1	$at,$f18
/*  f142cf8:	00000000 */ 	nop
/*  f142cfc:	46049583 */ 	div.s	$f22,$f18,$f4
.L0f142d00:
/*  f142d00:	4600a18d */ 	trunc.w.s	$f6,$f20
/*  f142d04:	02402025 */ 	or	$a0,$s2,$zero
/*  f142d08:	02c02825 */ 	or	$a1,$s6,$zero
/*  f142d0c:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f142d10:	440b3000 */ 	mfc1	$t3,$f6
/*  f142d14:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f142d18:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f142d1c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f142d20:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f142d24:	0fc506ac */ 	jal	func0f141ab0
/*  f142d28:	01753021 */ 	addu	$a2,$t3,$s5
/*  f142d2c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f142d30:	00409025 */ 	or	$s2,$v0,$zero
/*  f142d34:	1611fff2 */ 	bne	$s0,$s1,.L0f142d00
/*  f142d38:	4616a500 */ 	add.s	$f20,$f20,$f22
.L0f142d3c:
/*  f142d3c:	02401025 */ 	or	$v0,$s2,$zero
.L0f142d40:
/*  f142d40:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f142d44:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f142d48:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f142d4c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f142d50:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f142d54:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f142d58:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f142d5c:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f142d60:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f142d64:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f142d68:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f142d6c:	03e00008 */ 	jr	$ra
/*  f142d70:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f142d74
.late_rodata
glabel var7f1b5f34
.word 0x3c23d70a
glabel var7f1b5f38
.word 0x3bcccccd
glabel var7f1b5f3c
.word 0x3c23d70a
.text
/*  f142d74:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f142d78:	44866000 */ 	mtc1	$a2,$f12
/*  f142d7c:	44877000 */ 	mtc1	$a3,$f14
/*  f142d80:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f142d84:	04800003 */ 	bltz	$a0,.L0f142d94
/*  f142d88:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f142d8c:	28810080 */ 	slti	$at,$a0,0x80
/*  f142d90:	14200003 */ 	bnez	$at,.L0f142da0
.L0f142d94:
/*  f142d94:	3c017f1b */ 	lui	$at,%hi(var7f1b5f34)
/*  f142d98:	10000015 */ 	b	.L0f142df0
/*  f142d9c:	c4205f34 */ 	lwc1	$f0,%lo(var7f1b5f34)($at)
.L0f142da0:
/*  f142da0:	44842000 */ 	mtc1	$a0,$f4
/*  f142da4:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*  f142da8:	3c017f1b */ 	lui	$at,%hi(var7f1b5f3c)
/*  f142dac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f142db0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f142db4:	460a6000 */ 	add.s	$f0,$f12,$f10
/*  f142db8:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f142dbc:	460e103c */ 	c.lt.s	$f2,$f14
/*  f142dc0:	00000000 */ 	nop
/*  f142dc4:	45000008 */ 	bc1f	.L0f142de8
/*  f142dc8:	00000000 */ 	nop
/*  f142dcc:	0c012974 */ 	jal	sqrtf
/*  f142dd0:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f142dd4:	3c017f1b */ 	lui	$at,%hi(var7f1b5f38)
/*  f142dd8:	c4305f38 */ 	lwc1	$f16,%lo(var7f1b5f38)($at)
/*  f142ddc:	46100082 */ 	mul.s	$f2,$f0,$f16
/*  f142de0:	10000003 */ 	b	.L0f142df0
/*  f142de4:	46001006 */ 	mov.s	$f0,$f2
.L0f142de8:
/*  f142de8:	c4225f3c */ 	lwc1	$f2,%lo(var7f1b5f3c)($at)
/*  f142dec:	46001006 */ 	mov.s	$f0,$f2
.L0f142df0:
/*  f142df0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f142df4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f142df8:	03e00008 */ 	jr	$ra
/*  f142dfc:	00000000 */ 	nop
);


GLOBAL_ASM(
glabel hudRenderEyespyView
.late_rodata
glabel var7f1b5f40
.word 0x3f83d70a
glabel var7f1b5f44
.word 0x3bcccccd
glabel var7f1b5f48
.word 0x3c23d70a
.text
/*  f142e00:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f142e04:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f142e08:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f142e0c:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f142e10:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f142e14:	00c08025 */ 	or	$s0,$a2,$zero
/*  f142e18:	00808825 */ 	or	$s1,$a0,$zero
/*  f142e1c:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f142e20:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f142e24:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f142e28:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f142e2c:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f142e30:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f142e34:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f142e38:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f142e3c:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f142e40:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f142e44:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f142e48:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f142e4c:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f142e50:	0c002ac7 */ 	jal	viGetUnk28
/*  f142e54:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f142e58:	0c002f44 */ 	jal	viGetViewTop
/*  f142e5c:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f142e60:	0c002f26 */ 	jal	viGetViewY
/*  f142e64:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f142e68:	44822000 */ 	mtc1	$v0,$f4
/*  f142e6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f142e70:	44813000 */ 	mtc1	$at,$f6
/*  f142e74:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f142e78:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f142e7c:	46061702 */ 	mul.s	$f28,$f2,$f6
/*  f142e80:	461ce200 */ 	add.s	$f8,$f28,$f28
/*  f142e84:	461ce602 */ 	mul.s	$f24,$f28,$f28
/*  f142e88:	46004287 */ 	neg.s	$f10,$f8
/*  f142e8c:	0c002f22 */ 	jal	viGetViewX
/*  f142e90:	46025683 */ 	div.s	$f26,$f10,$f2
/*  f142e94:	0c002f40 */ 	jal	viGetViewLeft
/*  f142e98:	0040b025 */ 	or	$s6,$v0,$zero
/*  f142e9c:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f142ea0:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f142ea4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f142ea8:	3c013f80 */ 	lui	$at,0x3f80
/*  f142eac:	4481f000 */ 	mtc1	$at,$f30
/*  f142eb0:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f142eb4:	29e10002 */ 	slti	$at,$t7,0x2
/*  f142eb8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f142ebc:	00009025 */ 	or	$s2,$zero,$zero
/*  f142ec0:	14200003 */ 	bnez	$at,.L0f142ed0
/*  f142ec4:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f142ec8:	100001d9 */ 	b	.L0f143630
/*  f142ecc:	02201025 */ 	or	$v0,$s1,$zero
.L0f142ed0:
/*  f142ed0:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f142ed4:	3c057f1b */ 	lui	$a1,%hi(var7f1b5dd4)
/*  f142ed8:	24a55dd4 */ 	addiu	$a1,$a1,%lo(var7f1b5dd4)
/*  f142edc:	0c004c4c */ 	jal	strcpy
/*  f142ee0:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f142ee4:	83a30143 */ 	lb	$v1,0x143($sp)
/*  f142ee8:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f142eec:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f142ef0:	28670032 */ 	slti	$a3,$v1,0x32
/*  f142ef4:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f142ef8:	1320001d */ 	beqz	$t9,.L0f142f70
/*  f142efc:	03203825 */ 	or	$a3,$t9,$zero
/*  f142f00:	44833000 */ 	mtc1	$v1,$f6
/*  f142f04:	3c013f00 */ 	lui	$at,0x3f00
/*  f142f08:	44812000 */ 	mtc1	$at,$f4
/*  f142f0c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f142f10:	3c014248 */ 	lui	$at,0x4248
/*  f142f14:	44815000 */ 	mtc1	$at,$f10
/*  f142f18:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f142f1c:	3c01437f */ 	lui	$at,0x437f
/*  f142f20:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f142f24:	460a4783 */ 	div.s	$f30,$f8,$f10
/*  f142f28:	44888000 */ 	mtc1	$t0,$f16
/*  f142f2c:	00000000 */ 	nop
/*  f142f30:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f142f34:	46049582 */ 	mul.s	$f22,$f18,$f4
/*  f142f38:	44812000 */ 	mtc1	$at,$f4
/*  f142f3c:	461eb402 */ 	mul.s	$f16,$f22,$f30
/*  f142f40:	e7b600f4 */ 	swc1	$f22,0xf4($sp)
/*  f142f44:	4604f182 */ 	mul.s	$f6,$f30,$f4
/*  f142f48:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f142f4c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f142f50:	440a9000 */ 	mfc1	$t2,$f18
/*  f142f54:	44024000 */ 	mfc1	$v0,$f8
/*  f142f58:	afaa00fc */ 	sw	$t2,0xfc($sp)
/*  f142f5c:	28410100 */ 	slti	$at,$v0,0x100
/*  f142f60:	14200003 */ 	bnez	$at,.L0f142f70
/*  f142f64:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f142f68:	afac00ec */ 	sw	$t4,0xec($sp)
/*  f142f6c:	e7b600f4 */ 	swc1	$f22,0xf4($sp)
.L0f142f70:
/*  f142f70:	c7b600f4 */ 	lwc1	$f22,0xf4($sp)
/*  f142f74:	02201025 */ 	or	$v0,$s1,$zero
/*  f142f78:	3c0de700 */ 	lui	$t5,0xe700
/*  f142f7c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f142f80:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f142f84:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f142f88:	02e02825 */ 	or	$a1,$s7,$zero
/*  f142f8c:	0fc5082c */ 	jal	func0f1420b0
/*  f142f90:	02003025 */ 	or	$a2,$s0,$zero
/*  f142f94:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f142f98:	00408825 */ 	or	$s1,$v0,$zero
/*  f142f9c:	8fb00128 */ 	lw	$s0,0x128($sp)
/*  f142fa0:	11c00055 */ 	beqz	$t6,.L0f1430f8
/*  f142fa4:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f142fa8:	8fa30128 */ 	lw	$v1,0x128($sp)
/*  f142fac:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f142fb0:	00608025 */ 	or	$s0,$v1,$zero
/*  f142fb4:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f142fb8:	0078082a */ 	slt	$at,$v1,$t8
/*  f142fbc:	102000d4 */ 	beqz	$at,.L0f143310
/*  f142fc0:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f142fc4:	448f5000 */ 	mtc1	$t7,$f10
/*  f142fc8:	3c013f00 */ 	lui	$at,0x3f00
/*  f142fcc:	44819000 */ 	mtc1	$at,$f18
/*  f142fd0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f142fd4:	241eff00 */ 	addiu	$s8,$zero,-256
/*  f142fd8:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f142fdc:	46128502 */ 	mul.s	$f20,$f16,$f18
/*  f142fe0:	00000000 */ 	nop
.L0f142fe4:
/*  f142fe4:	06010004 */ 	bgez	$s0,.L0f142ff8
/*  f142fe8:	32080001 */ 	andi	$t0,$s0,0x1
/*  f142fec:	11000002 */ 	beqz	$t0,.L0f142ff8
/*  f142ff0:	00000000 */ 	nop
/*  f142ff4:	2508fffe */ 	addiu	$t0,$t0,-2
.L0f142ff8:
/*  f142ff8:	5100002e */ 	beqzl	$t0,.L0f1430b4
/*  f142ffc:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143000:	44832000 */ 	mtc1	$v1,$f4
/*  f143004:	8fa900fc */ 	lw	$t1,0xfc($sp)
/*  f143008:	44905000 */ 	mtc1	$s0,$f10
/*  f14300c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f143010:	44894000 */ 	mtc1	$t1,$f8
/*  f143014:	00000000 */ 	nop
/*  f143018:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f14301c:	46163000 */ 	add.s	$f0,$f6,$f22
/*  f143020:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f143024:	46020401 */ 	sub.s	$f16,$f0,$f2
/*  f143028:	460c803c */ 	c.lt.s	$f16,$f12
/*  f14302c:	00000000 */ 	nop
/*  f143030:	45020020 */ 	bc1fl	.L0f1430b4
/*  f143034:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143038:	46020480 */ 	add.s	$f18,$f0,$f2
/*  f14303c:	02201025 */ 	or	$v0,$s1,$zero
/*  f143040:	02fe5024 */ 	and	$t2,$s7,$s8
/*  f143044:	02402025 */ 	or	$a0,$s2,$zero
/*  f143048:	4612603c */ 	c.lt.s	$f12,$f18
/*  f14304c:	00000000 */ 	nop
/*  f143050:	45020018 */ 	bc1fl	.L0f1430b4
/*  f143054:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143058:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f14305c:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f143060:	4405d000 */ 	mfc1	$a1,$f26
/*  f143064:	4406e000 */ 	mfc1	$a2,$f28
/*  f143068:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f14306c:	014c6825 */ 	or	$t5,$t2,$t4
/*  f143070:	4407c000 */ 	mfc1	$a3,$f24
/*  f143074:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f143078:	0fc50b5d */ 	jal	func0f142d74
/*  f14307c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143080:	461e0102 */ 	mul.s	$f4,$f0,$f30
/*  f143084:	02202025 */ 	or	$a0,$s1,$zero
/*  f143088:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f14308c:	02003025 */ 	or	$a2,$s0,$zero
/*  f143090:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f143094:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f143098:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f14309c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f1430a0:	0fc506ac */ 	jal	func0f141ab0
/*  f1430a4:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f1430a8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1430ac:	8fa30128 */ 	lw	$v1,0x128($sp)
/*  f1430b0:	02539021 */ 	addu	$s2,$s2,$s3
.L0f1430b4:
/*  f1430b4:	44923000 */ 	mtc1	$s2,$f6
/*  f1430b8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f1430bc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1430c0:	4608a03e */ 	c.le.s	$f20,$f8
/*  f1430c4:	00000000 */ 	nop
/*  f1430c8:	45020006 */ 	bc1fl	.L0f1430e4
/*  f1430cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1430d0:	4600a28d */ 	trunc.w.s	$f10,$f20
/*  f1430d4:	00139823 */ 	negu	$s3,$s3
/*  f1430d8:	44125000 */ 	mfc1	$s2,$f10
/*  f1430dc:	00000000 */ 	nop
/*  f1430e0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1430e4:
/*  f1430e4:	1618ffbf */ 	bne	$s0,$t8,.L0f142fe4
/*  f1430e8:	00000000 */ 	nop
/*  f1430ec:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f1430f0:	10000087 */ 	b	.L0f143310
/*  f1430f4:	00608025 */ 	or	$s0,$v1,$zero
.L0f1430f8:
/*  f1430f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1430fc:	4481b000 */ 	mtc1	$at,$f22
/*  f143100:	020f4021 */ 	addu	$t0,$s0,$t7
/*  f143104:	0208082a */ 	slt	$at,$s0,$t0
/*  f143108:	10200081 */ 	beqz	$at,.L0f143310
/*  f14310c:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f143110:	448f8000 */ 	mtc1	$t7,$f16
/*  f143114:	3c013f00 */ 	lui	$at,0x3f00
/*  f143118:	44812000 */ 	mtc1	$at,$f4
/*  f14311c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f143120:	93be0147 */ 	lbu	$s8,0x147($sp)
/*  f143124:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f143128:	46049502 */ 	mul.s	$f20,$f18,$f4
/*  f14312c:	00000000 */ 	nop
.L0f143130:
/*  f143130:	24010004 */ 	addiu	$at,$zero,0x4
/*  f143134:	17c1001f */ 	bne	$s8,$at,.L0f1431b4
/*  f143138:	02201025 */ 	or	$v0,$s1,$zero
/*  f14313c:	0c004b70 */ 	jal	random
/*  f143140:	00000000 */ 	nop
/*  f143144:	24010078 */ 	addiu	$at,$zero,0x78
/*  f143148:	0041001b */ 	divu	$zero,$v0,$at
/*  f14314c:	0000b810 */ 	mfhi	$s7
/*  f143150:	26e90078 */ 	addiu	$t1,$s7,0x78
/*  f143154:	3c01ff33 */ 	lui	$at,0xff33
/*  f143158:	34213300 */ 	ori	$at,$at,0x3300
/*  f14315c:	312b00ff */ 	andi	$t3,$t1,0xff
/*  f143160:	0c004b70 */ 	jal	random
/*  f143164:	0161b825 */ 	or	$s7,$t3,$at
/*  f143168:	304c001f */ 	andi	$t4,$v0,0x1f
/*  f14316c:	448c3000 */ 	mtc1	$t4,$f6
/*  f143170:	3c014f80 */ 	lui	$at,0x4f80
/*  f143174:	05810004 */ 	bgez	$t4,.L0f143188
/*  f143178:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f14317c:	44815000 */ 	mtc1	$at,$f10
/*  f143180:	00000000 */ 	nop
/*  f143184:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f143188:
/*  f143188:	3c01435c */ 	lui	$at,0x435c
/*  f14318c:	44818000 */ 	mtc1	$at,$f16
/*  f143190:	3c013b80 */ 	lui	$at,0x3b80
/*  f143194:	44812000 */ 	mtc1	$at,$f4
/*  f143198:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f14319c:	02201825 */ 	or	$v1,$s1,$zero
/*  f1431a0:	ac740000 */ 	sw	$s4,0x0($v1)
/*  f1431a4:	ac770004 */ 	sw	$s7,0x4($v1)
/*  f1431a8:	46049582 */ 	mul.s	$f22,$f18,$f4
/*  f1431ac:	10000005 */ 	b	.L0f1431c4
/*  f1431b0:	26310008 */ 	addiu	$s1,$s1,0x8
.L0f1431b4:
/*  f1431b4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1431b8:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1431bc:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1431c0:	ac540000 */ 	sw	$s4,0x0($v0)
.L0f1431c4:
/*  f1431c4:	4405d000 */ 	mfc1	$a1,$f26
/*  f1431c8:	4406e000 */ 	mfc1	$a2,$f28
/*  f1431cc:	4407c000 */ 	mfc1	$a3,$f24
/*  f1431d0:	0fc50b5d */ 	jal	func0f142d74
/*  f1431d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1431d8:	46160182 */ 	mul.s	$f6,$f0,$f22
/*  f1431dc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1431e0:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f1431e4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1431e8:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1431ec:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1431f0:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f1431f4:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f1431f8:	0fc506ac */ 	jal	func0f141ab0
/*  f1431fc:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f143200:	24010004 */ 	addiu	$at,$zero,0x4
/*  f143204:	17c10019 */ 	bne	$s8,$at,.L0f14326c
/*  f143208:	00408825 */ 	or	$s1,$v0,$zero
/*  f14320c:	02201025 */ 	or	$v0,$s1,$zero
/*  f143210:	3c0eddaa */ 	lui	$t6,0xddaa
/*  f143214:	35ceaa99 */ 	ori	$t6,$t6,0xaa99
/*  f143218:	4405d000 */ 	mfc1	$a1,$f26
/*  f14321c:	4406e000 */ 	mfc1	$a2,$f28
/*  f143220:	4407c000 */ 	mfc1	$a3,$f24
/*  f143224:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f143228:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f14322c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143230:	0fc50b5d */ 	jal	func0f142d74
/*  f143234:	02402025 */ 	or	$a0,$s2,$zero
/*  f143238:	3c017f1b */ 	lui	$at,%hi(var7f1b5f40)
/*  f14323c:	c42a5f40 */ 	lwc1	$f10,%lo(var7f1b5f40)($at)
/*  f143240:	02202025 */ 	or	$a0,$s1,$zero
/*  f143244:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f143248:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f14324c:	02003025 */ 	or	$a2,$s0,$zero
/*  f143250:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f143254:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f143258:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f14325c:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f143260:	0fc506ac */ 	jal	func0f141ab0
/*  f143264:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f143268:	00408825 */ 	or	$s1,$v0,$zero
.L0f14326c:
/*  f14326c:	32180001 */ 	andi	$t8,$s0,0x1
/*  f143270:	17000017 */ 	bnez	$t8,.L0f1432d0
/*  f143274:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143278:	02b64021 */ 	addu	$t0,$s5,$s6
/*  f14327c:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f143280:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f143284:	24190055 */ 	addiu	$t9,$zero,0x55
/*  f143288:	000f4b80 */ 	sll	$t1,$t7,0xe
/*  f14328c:	3c01f600 */ 	lui	$at,0xf600
/*  f143290:	260a0001 */ 	addiu	$t2,$s0,0x1
/*  f143294:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143298:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f14329c:	01215825 */ 	or	$t3,$t1,$at
/*  f1432a0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1432a4:	320803ff */ 	andi	$t0,$s0,0x3ff
/*  f1432a8:	32b803ff */ 	andi	$t8,$s5,0x3ff
/*  f1432ac:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f1432b0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1432b4:	00087880 */ 	sll	$t7,$t0,0x2
/*  f1432b8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f1432bc:	016d7025 */ 	or	$t6,$t3,$t5
/*  f1432c0:	032f4825 */ 	or	$t1,$t9,$t7
/*  f1432c4:	ac890004 */ 	sw	$t1,0x4($a0)
/*  f1432c8:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1432cc:	26310008 */ 	addiu	$s1,$s1,0x8
.L0f1432d0:
/*  f1432d0:	44928000 */ 	mtc1	$s2,$f16
/*  f1432d4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f1432d8:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f1432dc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1432e0:	4612a03e */ 	c.le.s	$f20,$f18
/*  f1432e4:	00000000 */ 	nop
/*  f1432e8:	45000005 */ 	bc1f	.L0f143300
/*  f1432ec:	00000000 */ 	nop
/*  f1432f0:	4600a10d */ 	trunc.w.s	$f4,$f20
/*  f1432f4:	00139823 */ 	negu	$s3,$s3
/*  f1432f8:	44122000 */ 	mfc1	$s2,$f4
/*  f1432fc:	00000000 */ 	nop
.L0f143300:
/*  f143300:	144cff8b */ 	bne	$v0,$t4,.L0f143130
/*  f143304:	00408025 */ 	or	$s0,$v0,$zero
/*  f143308:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f14330c:	8fb00128 */ 	lw	$s0,0x128($sp)
.L0f143310:
/*  f143310:	02201025 */ 	or	$v0,$s1,$zero
/*  f143314:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143318:	3c0be700 */ 	lui	$t3,0xe700
/*  f14331c:	02201825 */ 	or	$v1,$s1,$zero
/*  f143320:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f143324:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f143328:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f14332c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f143330:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f143334:	02202025 */ 	or	$a0,$s1,$zero
/*  f143338:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f14333c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f143340:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143344:	3c0eb900 */ 	lui	$t6,0xb900
/*  f143348:	3c180050 */ 	lui	$t8,0x50
/*  f14334c:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f143350:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f143354:	02202825 */ 	or	$a1,$s1,$zero
/*  f143358:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f14335c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f143360:	3c08fcff */ 	lui	$t0,0xfcff
/*  f143364:	3c19fffd */ 	lui	$t9,0xfffd
/*  f143368:	3739f6fb */ 	ori	$t9,$t9,0xf6fb
/*  f14336c:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f143370:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143374:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f143378:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f14337c:	02203025 */ 	or	$a2,$s1,$zero
/*  f143380:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f143384:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f143388:	acc90004 */ 	sw	$t1,0x4($a2)
/*  f14338c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f143390:	8fa3013c */ 	lw	$v1,0x13c($sp)
/*  f143394:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143398:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f14339c:	14600003 */ 	bnez	$v1,.L0f1433ac
/*  f1433a0:	8fac0124 */ 	lw	$t4,0x124($sp)
/*  f1433a4:	1140007a */ 	beqz	$t2,.L0f143590
/*  f1433a8:	8fb90128 */ 	lw	$t9,0x128($sp)
.L0f1433ac:
/*  f1433ac:	448c3000 */ 	mtc1	$t4,$f6
/*  f1433b0:	3c013f00 */ 	lui	$at,0x3f00
/*  f1433b4:	44814000 */ 	mtc1	$at,$f8
/*  f1433b8:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1433bc:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f1433c0:	2463fff4 */ 	addiu	$v1,$v1,-12
/*  f1433c4:	8fb700fc */ 	lw	$s7,0xfc($sp)
/*  f1433c8:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f1433cc:	46085402 */ 	mul.s	$f16,$f10,$f8
/*  f1433d0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1433d4:	44029000 */ 	mfc1	$v0,$f18
/*  f1433d8:	15a00011 */ 	bnez	$t5,.L0f143420
/*  f1433dc:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f1433e0:	04630003 */ 	bgezl	$v1,.L0f1433f0
/*  f1433e4:	44832000 */ 	mtc1	$v1,$f4
/*  f1433e8:	00031823 */ 	negu	$v1,$v1
/*  f1433ec:	44832000 */ 	mtc1	$v1,$f4
.L0f1433f0:
/*  f1433f0:	3c014140 */ 	lui	$at,0x4140
/*  f1433f4:	44815000 */ 	mtc1	$at,$f10
/*  f1433f8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1433fc:	44828000 */ 	mtc1	$v0,$f16
/*  f143400:	00000000 */ 	nop
/*  f143404:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f143408:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f14340c:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f143410:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f143414:	44173000 */ 	mfc1	$s7,$f6
/*  f143418:	10000002 */ 	b	.L0f143424
/*  f14341c:	8fa30128 */ 	lw	$v1,0x128($sp)
.L0f143420:
/*  f143420:	8fa30128 */ 	lw	$v1,0x128($sp)
.L0f143424:
/*  f143424:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*  f143428:	0062f021 */ 	addu	$s8,$v1,$v0
/*  f14342c:	03d7a023 */ 	subu	$s4,$s8,$s7
/*  f143430:	0074082a */ 	slt	$at,$v1,$s4
/*  f143434:	10200017 */ 	beqz	$at,.L0f143494
/*  f143438:	00784021 */ 	addu	$t0,$v1,$t8
/*  f14343c:	0063c821 */ 	addu	$t9,$v1,$v1
/*  f143440:	032f4821 */ 	addu	$t1,$t9,$t7
/*  f143444:	4480a000 */ 	mtc1	$zero,$f20
/*  f143448:	01309023 */ 	subu	$s2,$t1,$s0
/*  f14344c:	01179823 */ 	subu	$s3,$t0,$s7
.L0f143450:
/*  f143450:	4406a000 */ 	mfc1	$a2,$f20
/*  f143454:	02202025 */ 	or	$a0,$s1,$zero
/*  f143458:	02002825 */ 	or	$a1,$s0,$zero
/*  f14345c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f143460:	0fc507b5 */ 	jal	func0f141ed4
/*  f143464:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143468:	4406a000 */ 	mfc1	$a2,$f20
/*  f14346c:	00402025 */ 	or	$a0,$v0,$zero
/*  f143470:	02402825 */ 	or	$a1,$s2,$zero
/*  f143474:	02a03825 */ 	or	$a3,$s5,$zero
/*  f143478:	0fc507b5 */ 	jal	func0f141ed4
/*  f14347c:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143480:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f143484:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f143488:	1613fff1 */ 	bne	$s0,$s3,.L0f143450
/*  f14348c:	00408825 */ 	or	$s1,$v0,$zero
/*  f143490:	8fa30128 */ 	lw	$v1,0x128($sp)
.L0f143494:
/*  f143494:	02201025 */ 	or	$v0,$s1,$zero
/*  f143498:	3c0afa00 */ 	lui	$t2,0xfa00
/*  f14349c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f1434a0:	03d4082a */ 	slt	$at,$s8,$s4
/*  f1434a4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f1434a8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f1434ac:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1434b0:	4600e506 */ 	mov.s	$f20,$f28
/*  f1434b4:	1420005d */ 	bnez	$at,.L0f14362c
/*  f1434b8:	02808025 */ 	or	$s0,$s4,$zero
/*  f1434bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1434c0:	44885000 */ 	mtc1	$t0,$f10
/*  f1434c4:	44972000 */ 	mtc1	$s7,$f4
/*  f1434c8:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f1434cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1434d0:	8fab00a8 */ 	lw	$t3,0xa8($sp)
/*  f1434d4:	00636821 */ 	addu	$t5,$v1,$v1
/*  f1434d8:	3c017f1b */ 	lui	$at,%hi(var7f1b5f44)
/*  f1434dc:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f1434e0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1434e4:	461c8482 */ 	mul.s	$f18,$f16,$f28
/*  f1434e8:	03149023 */ 	subu	$s2,$t8,$s4
/*  f1434ec:	c4365f44 */ 	lwc1	$f22,%lo(var7f1b5f44)($at)
/*  f1434f0:	006b9821 */ 	addu	$s3,$v1,$t3
/*  f1434f4:	46009207 */ 	neg.s	$f8,$f18
/*  f1434f8:	46064683 */ 	div.s	$f26,$f8,$f6
.L0f1434fc:
/*  f1434fc:	4614a002 */ 	mul.s	$f0,$f20,$f20
/*  f143500:	3c017f1b */ 	lui	$at,%hi(var7f1b5f48)
/*  f143504:	4618003c */ 	c.lt.s	$f0,$f24
/*  f143508:	00000000 */ 	nop
/*  f14350c:	45000006 */ 	bc1f	.L0f143528
/*  f143510:	00000000 */ 	nop
/*  f143514:	0c012974 */ 	jal	sqrtf
/*  f143518:	4600c301 */ 	sub.s	$f12,$f24,$f0
/*  f14351c:	46160082 */ 	mul.s	$f2,$f0,$f22
/*  f143520:	10000002 */ 	b	.L0f14352c
/*  f143524:	00000000 */ 	nop
.L0f143528:
/*  f143528:	c4225f48 */ 	lwc1	$f2,%lo(var7f1b5f48)($at)
.L0f14352c:
/*  f14352c:	461e1002 */ 	mul.s	$f0,$f2,$f30
/*  f143530:	461aa500 */ 	add.s	$f20,$f20,$f26
/*  f143534:	02202025 */ 	or	$a0,$s1,$zero
/*  f143538:	02002825 */ 	or	$a1,$s0,$zero
/*  f14353c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f143540:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143544:	44060000 */ 	mfc1	$a2,$f0
/*  f143548:	0fc507b5 */ 	jal	func0f141ed4
/*  f14354c:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f143550:	c7a00090 */ 	lwc1	$f0,0x90($sp)
/*  f143554:	12120008 */ 	beq	$s0,$s2,.L0f143578
/*  f143558:	00408825 */ 	or	$s1,$v0,$zero
/*  f14355c:	44060000 */ 	mfc1	$a2,$f0
/*  f143560:	00402025 */ 	or	$a0,$v0,$zero
/*  f143564:	02402825 */ 	or	$a1,$s2,$zero
/*  f143568:	02a03825 */ 	or	$a3,$s5,$zero
/*  f14356c:	0fc507b5 */ 	jal	func0f141ed4
/*  f143570:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143574:	00408825 */ 	or	$s1,$v0,$zero
.L0f143578:
/*  f143578:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14357c:	0270082a */ 	slt	$at,$s3,$s0
/*  f143580:	1020ffde */ 	beqz	$at,.L0f1434fc
/*  f143584:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f143588:	10000029 */ 	b	.L0f143630
/*  f14358c:	02201025 */ 	or	$v0,$s1,$zero
.L0f143590:
/*  f143590:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f143594:	00009025 */ 	or	$s2,$zero,$zero
/*  f143598:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f14359c:	032f082a */ 	slt	$at,$t9,$t7
/*  f1435a0:	50200023 */ 	beqzl	$at,.L0f143630
/*  f1435a4:	02201025 */ 	or	$v0,$s1,$zero
/*  f1435a8:	44895000 */ 	mtc1	$t1,$f10
/*  f1435ac:	3c013f00 */ 	lui	$at,0x3f00
/*  f1435b0:	44819000 */ 	mtc1	$at,$f18
/*  f1435b4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1435b8:	46128502 */ 	mul.s	$f20,$f16,$f18
/*  f1435bc:	00000000 */ 	nop
/*  f1435c0:	4405d000 */ 	mfc1	$a1,$f26
.L0f1435c4:
/*  f1435c4:	4406e000 */ 	mfc1	$a2,$f28
/*  f1435c8:	4407c000 */ 	mfc1	$a3,$f24
/*  f1435cc:	0fc50b5d */ 	jal	func0f142d74
/*  f1435d0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1435d4:	44060000 */ 	mfc1	$a2,$f0
/*  f1435d8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1435dc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1435e0:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1435e4:	0fc507b5 */ 	jal	func0f141ed4
/*  f1435e8:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f1435ec:	02539021 */ 	addu	$s2,$s2,$s3
/*  f1435f0:	44922000 */ 	mtc1	$s2,$f4
/*  f1435f4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f1435f8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1435fc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f143600:	4608a03e */ 	c.le.s	$f20,$f8
/*  f143604:	00000000 */ 	nop
/*  f143608:	45020006 */ 	bc1fl	.L0f143624
/*  f14360c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f143610:	4600a18d */ 	trunc.w.s	$f6,$f20
/*  f143614:	00139823 */ 	negu	$s3,$s3
/*  f143618:	44123000 */ 	mfc1	$s2,$f6
/*  f14361c:	00000000 */ 	nop
/*  f143620:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f143624:
/*  f143624:	560cffe7 */ 	bnel	$s0,$t4,.L0f1435c4
/*  f143628:	4405d000 */ 	mfc1	$a1,$f26
.L0f14362c:
/*  f14362c:	02201025 */ 	or	$v0,$s1,$zero
.L0f143630:
/*  f143630:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f143634:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f143638:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f14363c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f143640:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f143644:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f143648:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f14364c:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f143650:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f143654:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f143658:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f14365c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f143660:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f143664:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f143668:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f14366c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f143670:	03e00008 */ 	jr	$ra
/*  f143674:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel hudRenderEyespySideBar
/*  f143678:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f14367c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f143680:	00808025 */ 	or	$s0,$a0,$zero
/*  f143684:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f143688:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f14368c:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f143690:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f143694:	0fc59e59 */ 	jal	func0f167964
/*  f143698:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f14369c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1436a0:	0fc59e73 */ 	jal	func0f1679cc
/*  f1436a4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1436a8:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f1436ac:	3c014120 */ 	lui	$at,0x4120
/*  f1436b0:	44810000 */ 	mtc1	$at,$f0
/*  f1436b4:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f1436b8:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f1436bc:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f1436c0:	448e2000 */ 	mtc1	$t6,$f4
/*  f1436c4:	24080004 */ 	addiu	$t0,$zero,0x4
/*  f1436c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1436cc:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f1436d0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1436d4:	44185000 */ 	mfc1	$t8,$f10
/*  f1436d8:	00000000 */ 	nop
/*  f1436dc:	a4780000 */ 	sh	$t8,0x0($v1)
/*  f1436e0:	8cb90004 */ 	lw	$t9,0x4($a1)
/*  f1436e4:	a4670004 */ 	sh	$a3,0x4($v1)
/*  f1436e8:	44998000 */ 	mtc1	$t9,$f16
/*  f1436ec:	00000000 */ 	nop
/*  f1436f0:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1436f4:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f1436f8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1436fc:	440a3000 */ 	mfc1	$t2,$f6
/*  f143700:	00000000 */ 	nop
/*  f143704:	a46a0002 */ 	sh	$t2,0x2($v1)
/*  f143708:	8cab0008 */ 	lw	$t3,0x8($a1)
/*  f14370c:	448b4000 */ 	mtc1	$t3,$f8
/*  f143710:	00000000 */ 	nop
/*  f143714:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f143718:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f14371c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f143720:	440d9000 */ 	mfc1	$t5,$f18
/*  f143724:	00000000 */ 	nop
/*  f143728:	a46d000c */ 	sh	$t5,0xc($v1)
/*  f14372c:	8cae000c */ 	lw	$t6,0xc($a1)
/*  f143730:	a4670010 */ 	sh	$a3,0x10($v1)
/*  f143734:	448e2000 */ 	mtc1	$t6,$f4
/*  f143738:	00000000 */ 	nop
/*  f14373c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f143740:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f143744:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f143748:	44185000 */ 	mfc1	$t8,$f10
/*  f14374c:	00000000 */ 	nop
/*  f143750:	a478000e */ 	sh	$t8,0xe($v1)
/*  f143754:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f143758:	44998000 */ 	mtc1	$t9,$f16
/*  f14375c:	00000000 */ 	nop
/*  f143760:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f143764:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f143768:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f14376c:	440a3000 */ 	mfc1	$t2,$f6
/*  f143770:	00000000 */ 	nop
/*  f143774:	a46a0018 */ 	sh	$t2,0x18($v1)
/*  f143778:	8cab0014 */ 	lw	$t3,0x14($a1)
/*  f14377c:	a467001c */ 	sh	$a3,0x1c($v1)
/*  f143780:	448b4000 */ 	mtc1	$t3,$f8
/*  f143784:	00000000 */ 	nop
/*  f143788:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14378c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f143790:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f143794:	440d9000 */ 	mfc1	$t5,$f18
/*  f143798:	00000000 */ 	nop
/*  f14379c:	a46d001a */ 	sh	$t5,0x1a($v1)
/*  f1437a0:	8cae0018 */ 	lw	$t6,0x18($a1)
/*  f1437a4:	448e2000 */ 	mtc1	$t6,$f4
/*  f1437a8:	00000000 */ 	nop
/*  f1437ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1437b0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f1437b4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1437b8:	44185000 */ 	mfc1	$t8,$f10
/*  f1437bc:	00000000 */ 	nop
/*  f1437c0:	a4780024 */ 	sh	$t8,0x24($v1)
/*  f1437c4:	8cb9001c */ 	lw	$t9,0x1c($a1)
/*  f1437c8:	a4670028 */ 	sh	$a3,0x28($v1)
/*  f1437cc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1437d0:	44998000 */ 	mtc1	$t9,$f16
/*  f1437d4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1437d8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1437dc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1437e0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1437e4:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f1437e8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1437ec:	440a3000 */ 	mfc1	$t2,$f6
/*  f1437f0:	00000000 */ 	nop
/*  f1437f4:	a46a0026 */ 	sh	$t2,0x26($v1)
/*  f1437f8:	93ad0037 */ 	lbu	$t5,0x37($sp)
/*  f1437fc:	93ab0033 */ 	lbu	$t3,0x33($sp)
/*  f143800:	93b8003b */ 	lbu	$t8,0x3b($sp)
/*  f143804:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f143808:	000b6600 */ 	sll	$t4,$t3,0x18
/*  f14380c:	018e7825 */ 	or	$t7,$t4,$t6
/*  f143810:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f143814:	01f92025 */ 	or	$a0,$t7,$t9
/*  f143818:	348900ff */ 	ori	$t1,$a0,0xff
/*  f14381c:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f143820:	93aa003f */ 	lbu	$t2,0x3f($sp)
/*  f143824:	3c0d0704 */ 	lui	$t5,0x704
/*  f143828:	35ad0008 */ 	ori	$t5,$t5,0x8
/*  f14382c:	008a5825 */ 	or	$t3,$a0,$t2
/*  f143830:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f143834:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f143838:	a0600013 */ 	sb	$zero,0x13($v1)
/*  f14383c:	a068001f */ 	sb	$t0,0x1f($v1)
/*  f143840:	a068002b */ 	sb	$t0,0x2b($v1)
/*  f143844:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f143848:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f14384c:	3c0c0430 */ 	lui	$t4,0x430
/*  f143850:	358c0030 */ 	ori	$t4,$t4,0x30
/*  f143854:	acc30004 */ 	sw	$v1,0x4($a2)
/*  f143858:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f14385c:	02001825 */ 	or	$v1,$s0,$zero
/*  f143860:	3c0eb100 */ 	lui	$t6,0xb100
/*  f143864:	35ce0032 */ 	ori	$t6,$t6,0x32
/*  f143868:	24182010 */ 	addiu	$t8,$zero,0x2010
/*  f14386c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f143870:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f143874:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f143878:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f14387c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f143880:	03e00008 */ 	jr	$ra
/*  f143884:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

const char var7f1b5de4[] = "%s %s%5.2f";
const char var7f1b5df0[] = "";
const char var7f1b5df4[] = "%s %s%4.2f";
const char var7f1b5e00[] = "";
const char var7f1b5e04[] = "%s %d";
const char var7f1b5e0c[] = "%s %d";
const char var7f1b5e14[] = "%s";
const char var7f1b5e18[] = "%s";
const char var7f1b5e1c[] = "%s";
const char var7f1b5e20[] = "%s";
const char var7f1b5e24[] = "   %s";
const char var7f1b5e2c[] = "   %s";
const char var7f1b5e34[] = "   %s";
const char var7f1b5e3c[] = "%s";
const char var7f1b5e40[] = "%s";
const char var7f1b5e44[] = "%s";
const char var7f1b5e48[] = "%s";
const char var7f1b5e4c[] = "%s";

GLOBAL_ASM(
glabel hudRenderEyespyUi
.late_rodata
glabel var7f1b5f4c
.word 0x3a83126f
glabel var7f1b5f50
.word 0x3f19999a
glabel var7f1b5f54
.word 0x3c23d70a
glabel var7f1b5f58
.word 0x3bcccccd
.text
/*  f143888:	27bdfbf8 */ 	addiu	$sp,$sp,-1032
/*  f14388c:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f143890:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f143894:	0080a825 */ 	or	$s5,$a0,$zero
/*  f143898:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f14389c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f1438a0:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f1438a4:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1438a8:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1438ac:	0c002f40 */ 	jal	viGetViewLeft
/*  f1438b0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1438b4:	0c002f44 */ 	jal	viGetViewTop
/*  f1438b8:	afa20304 */ 	sw	$v0,0x304($sp)
/*  f1438bc:	0c002f22 */ 	jal	viGetViewX
/*  f1438c0:	afa20300 */ 	sw	$v0,0x300($sp)
/*  f1438c4:	0c002f26 */ 	jal	viGetViewY
/*  f1438c8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1438cc:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f1438d0:	44806000 */ 	mtc1	$zero,$f12
/*  f1438d4:	2a210141 */ 	slti	$at,$s1,0x141
/*  f1438d8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f1438dc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f1438e0:	afa202f8 */ 	sw	$v0,0x2f8($sp)
/*  f1438e4:	14200004 */ 	bnez	$at,.L0f1438f8
/*  f1438e8:	afb802f0 */ 	sw	$t8,0x2f0($sp)
/*  f1438ec:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f1438f0:	10000003 */ 	b	.L0f143900
/*  f1438f4:	afb902ac */ 	sw	$t9,0x2ac($sp)
.L0f1438f8:
/*  f1438f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1438fc:	afae02ac */ 	sw	$t6,0x2ac($sp)
.L0f143900:
/*  f143900:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f143904:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f143908:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14390c:	afa002a8 */ 	sw	$zero,0x2a8($sp)
/*  f143910:	8de20480 */ 	lw	$v0,0x480($t7)
/*  f143914:	10400007 */ 	beqz	$v0,.L0f143934
/*  f143918:	00000000 */ 	nop
/*  f14391c:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f143920:	10600004 */ 	beqz	$v1,.L0f143934
/*  f143924:	00000000 */ 	nop
/*  f143928:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f14392c:	14400003 */ 	bnez	$v0,.L0f14393c
/*  f143930:	00408025 */ 	or	$s0,$v0,$zero
.L0f143934:
/*  f143934:	10000e65 */ 	b	.L0f1472cc
/*  f143938:	02a01025 */ 	or	$v0,$s5,$zero
.L0f14393c:
/*  f14393c:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f143940:	e7ac02bc */ 	swc1	$f12,0x2bc($sp)
/*  f143944:	44800000 */ 	mtc1	$zero,$f0
/*  f143948:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14394c:	1441001f */ 	bne	$v0,$at,.L0f1439cc
/*  f143950:	c7ac02bc */ 	lwc1	$f12,0x2bc($sp)
/*  f143954:	8ed8006c */ 	lw	$t8,0x6c($s6)
/*  f143958:	00002825 */ 	or	$a1,$zero,$zero
/*  f14395c:	00001825 */ 	or	$v1,$zero,$zero
/*  f143960:	13000003 */ 	beqz	$t8,.L0f143970
/*  f143964:	00002025 */ 	or	$a0,$zero,$zero
/*  f143968:	10000001 */ 	b	.L0f143970
/*  f14396c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f143970:
/*  f143970:	8ed90068 */ 	lw	$t9,0x68($s6)
/*  f143974:	00001025 */ 	or	$v0,$zero,$zero
/*  f143978:	13200003 */ 	beqz	$t9,.L0f143988
/*  f14397c:	00000000 */ 	nop
/*  f143980:	10000001 */ 	b	.L0f143988
/*  f143984:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f143988:
/*  f143988:	8ece0064 */ 	lw	$t6,0x64($s6)
/*  f14398c:	11c00003 */ 	beqz	$t6,.L0f14399c
/*  f143990:	00000000 */ 	nop
/*  f143994:	10000001 */ 	b	.L0f14399c
/*  f143998:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f14399c:
/*  f14399c:	8ecf0070 */ 	lw	$t7,0x70($s6)
/*  f1439a0:	11e00003 */ 	beqz	$t7,.L0f1439b0
/*  f1439a4:	00000000 */ 	nop
/*  f1439a8:	10000001 */ 	b	.L0f1439b0
/*  f1439ac:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1439b0:
/*  f1439b0:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f1439b4:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f1439b8:	03257021 */ 	addu	$t6,$t9,$a1
/*  f1439bc:	29c10002 */ 	slti	$at,$t6,0x2
/*  f1439c0:	14200002 */ 	bnez	$at,.L0f1439cc
/*  f1439c4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1439c8:	afaf02a8 */ 	sw	$t7,0x2a8($sp)
.L0f1439cc:
/*  f1439cc:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f1439d0:	c60600c8 */ 	lwc1	$f6,0xc8($s0)
/*  f1439d4:	3c017f1b */ 	lui	$at,%hi(var7f1b5f4c)
/*  f1439d8:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f1439dc:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1439e0:	c60600cc */ 	lwc1	$f6,0xcc($s0)
/*  f1439e4:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f1439e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1439ec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1439f0:	44035000 */ 	mfc1	$v1,$f10
/*  f1439f4:	c60600d0 */ 	lwc1	$f6,0xd0($s0)
/*  f1439f8:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f1439fc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f143a00:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f143a04:	44832000 */ 	mtc1	$v1,$f4
/*  f143a08:	44045000 */ 	mfc1	$a0,$f10
/*  f143a0c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f143a10:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f143a14:	46060032 */ 	c.eq.s	$f0,$f6
/*  f143a18:	44055000 */ 	mfc1	$a1,$f10
/*  f143a1c:	4500000f */ 	bc1f	.L0f143a5c
/*  f143a20:	00000000 */ 	nop
/*  f143a24:	44844000 */ 	mtc1	$a0,$f8
/*  f143a28:	00000000 */ 	nop
/*  f143a2c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f143a30:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f143a34:	00000000 */ 	nop
/*  f143a38:	45000008 */ 	bc1f	.L0f143a5c
/*  f143a3c:	00000000 */ 	nop
/*  f143a40:	44852000 */ 	mtc1	$a1,$f4
/*  f143a44:	00000000 */ 	nop
/*  f143a48:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f143a4c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f143a50:	00000000 */ 	nop
/*  f143a54:	4501000f */ 	bc1t	.L0f143a94
/*  f143a58:	00000000 */ 	nop
.L0f143a5c:
/*  f143a5c:	00630019 */ 	multu	$v1,$v1
/*  f143a60:	00007812 */ 	mflo	$t7
/*  f143a64:	00000000 */ 	nop
/*  f143a68:	00000000 */ 	nop
/*  f143a6c:	00840019 */ 	multu	$a0,$a0
/*  f143a70:	0000c012 */ 	mflo	$t8
/*  f143a74:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f143a78:	00000000 */ 	nop
/*  f143a7c:	00a50019 */ 	multu	$a1,$a1
/*  f143a80:	00007012 */ 	mflo	$t6
/*  f143a84:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f143a88:	448f4000 */ 	mtc1	$t7,$f8
/*  f143a8c:	00000000 */ 	nop
/*  f143a90:	46804320 */ 	cvt.s.w	$f12,$f8
.L0f143a94:
/*  f143a94:	c42a5f4c */ 	lwc1	$f10,%lo(var7f1b5f4c)($at)
/*  f143a98:	460c503c */ 	c.lt.s	$f10,$f12
/*  f143a9c:	00000000 */ 	nop
/*  f143aa0:	45020006 */ 	bc1fl	.L0f143abc
/*  f143aa4:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
/*  f143aa8:	0c012974 */ 	jal	sqrtf
/*  f143aac:	00000000 */ 	nop
/*  f143ab0:	10000002 */ 	b	.L0f143abc
/*  f143ab4:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
/*  f143ab8:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
.L0f143abc:
/*  f143abc:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f143ac0:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f143ac4:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f143ac8:	14600006 */ 	bnez	$v1,.L0f143ae4
/*  f143acc:	3c0500ff */ 	lui	$a1,0xff
/*  f143ad0:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f143ad4:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f143ad8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f143adc:	1000000e */ 	b	.L0f143b18
/*  f143ae0:	0040a825 */ 	or	$s5,$v0,$zero
.L0f143ae4:
/*  f143ae4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f143ae8:	14610007 */ 	bne	$v1,$at,.L0f143b08
/*  f143aec:	02a02025 */ 	or	$a0,$s5,$zero
/*  f143af0:	3c052244 */ 	lui	$a1,0x2244
/*  f143af4:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f143af8:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f143afc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f143b00:	10000005 */ 	b	.L0f143b18
/*  f143b04:	0040a825 */ 	or	$s5,$v0,$zero
.L0f143b08:
/*  f143b08:	3c05ff33 */ 	lui	$a1,0xff33
/*  f143b0c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f143b10:	34a500a0 */ 	ori	$a1,$a1,0xa0
/*  f143b14:	0040a825 */ 	or	$s5,$v0,$zero
.L0f143b18:
/*  f143b18:	8fae02a8 */ 	lw	$t6,0x2a8($sp)
/*  f143b1c:	55c00182 */ 	bnezl	$t6,.L0f144128
/*  f143b20:	44912000 */ 	mtc1	$s1,$f4
/*  f143b24:	44913000 */ 	mtc1	$s1,$f6
/*  f143b28:	3c013f80 */ 	lui	$at,0x3f80
/*  f143b2c:	44818000 */ 	mtc1	$at,$f16
/*  f143b30:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f143b34:	3c0140a0 */ 	lui	$at,0x40a0
/*  f143b38:	44814000 */ 	mtc1	$at,$f8
/*  f143b3c:	8fad02f0 */ 	lw	$t5,0x2f0($sp)
/*  f143b40:	8fbf0304 */ 	lw	$ra,0x304($sp)
/*  f143b44:	3c0cf600 */ 	lui	$t4,0xf600
/*  f143b48:	46087003 */ 	div.s	$f0,$f14,$f8
/*  f143b4c:	25a4ffe8 */ 	addiu	$a0,$t5,-24
/*  f143b50:	308f03ff */ 	andi	$t7,$a0,0x3ff
/*  f143b54:	27f9001a */ 	addiu	$t9,$ra,0x1a
/*  f143b58:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f143b5c:	000f2080 */ 	sll	$a0,$t7,0x2
/*  f143b60:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f143b64:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f143b68:	27e50019 */ 	addiu	$a1,$ra,0x19
/*  f143b6c:	44852000 */ 	mtc1	$a1,$f4
/*  f143b70:	0304c825 */ 	or	$t9,$t8,$a0
/*  f143b74:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f143b78:	8fa70300 */ 	lw	$a3,0x300($sp)
/*  f143b7c:	30a803ff */ 	andi	$t0,$a1,0x3ff
/*  f143b80:	00087380 */ 	sll	$t6,$t0,0xe
/*  f143b84:	24e70037 */ 	addiu	$a3,$a3,0x37
/*  f143b88:	30ef03ff */ 	andi	$t7,$a3,0x3ff
/*  f143b8c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f143b90:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f143b94:	03003825 */ 	or	$a3,$t8,$zero
/*  f143b98:	01c04025 */ 	or	$t0,$t6,$zero
/*  f143b9c:	25a9ffd6 */ 	addiu	$t1,$t5,-42
/*  f143ba0:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f143ba4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143ba8:	312e03ff */ 	andi	$t6,$t1,0x3ff
/*  f143bac:	27f80020 */ 	addiu	$t8,$ra,0x20
/*  f143bb0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f143bb4:	000e4880 */ 	sll	$t1,$t6,0x2
/*  f143bb8:	46001280 */ 	add.s	$f10,$f2,$f0
/*  f143bbc:	00197380 */ 	sll	$t6,$t9,0xe
/*  f143bc0:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f143bc4:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f143bc8:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f143bcc:	27ea001f */ 	addiu	$t2,$ra,0x1f
/*  f143bd0:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f143bd4:	01e9c025 */ 	or	$t8,$t7,$t1
/*  f143bd8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f143bdc:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f143be0:	00195380 */ 	sll	$t2,$t9,0xe
/*  f143be4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f143be8:	4458f800 */ 	cfc1	$t8,$31
/*  f143bec:	44d9f800 */ 	ctc1	$t9,$31
/*  f143bf0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143bf4:	01477825 */ 	or	$t7,$t2,$a3
/*  f143bf8:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f143bfc:	02a05825 */ 	or	$t3,$s5,$zero
/*  f143c00:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f143c04:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143c08:	4459f800 */ 	cfc1	$t9,$31
/*  f143c0c:	3c014f00 */ 	lui	$at,0x4f00
/*  f143c10:	33390078 */ 	andi	$t9,$t9,0x78
/*  f143c14:	53200013 */ 	beqzl	$t9,.L0f143c64
/*  f143c18:	44193000 */ 	mfc1	$t9,$f6
/*  f143c1c:	44813000 */ 	mtc1	$at,$f6
/*  f143c20:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f143c24:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f143c28:	44d9f800 */ 	ctc1	$t9,$31
/*  f143c2c:	00000000 */ 	nop
/*  f143c30:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f143c34:	4459f800 */ 	cfc1	$t9,$31
/*  f143c38:	00000000 */ 	nop
/*  f143c3c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f143c40:	17200005 */ 	bnez	$t9,.L0f143c58
/*  f143c44:	00000000 */ 	nop
/*  f143c48:	44193000 */ 	mfc1	$t9,$f6
/*  f143c4c:	3c018000 */ 	lui	$at,0x8000
/*  f143c50:	10000007 */ 	b	.L0f143c70
/*  f143c54:	0321c825 */ 	or	$t9,$t9,$at
.L0f143c58:
/*  f143c58:	10000005 */ 	b	.L0f143c70
/*  f143c5c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f143c60:	44193000 */ 	mfc1	$t9,$f6
.L0f143c64:
/*  f143c64:	00000000 */ 	nop
/*  f143c68:	0720fffb */ 	bltz	$t9,.L0f143c58
/*  f143c6c:	00000000 */ 	nop
.L0f143c70:
/*  f143c70:	3c0140e0 */ 	lui	$at,0x40e0
/*  f143c74:	44d8f800 */ 	ctc1	$t8,$31
/*  f143c78:	44814000 */ 	mtc1	$at,$f8
/*  f143c7c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f143c80:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f143c84:	46087303 */ 	div.s	$f12,$f14,$f8
/*  f143c88:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f143c8c:	0304c825 */ 	or	$t9,$t8,$a0
/*  f143c90:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f143c94:	8fb002f0 */ 	lw	$s0,0x2f0($sp)
/*  f143c98:	02a01025 */ 	or	$v0,$s5,$zero
/*  f143c9c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143ca0:	260effe7 */ 	addiu	$t6,$s0,-25
/*  f143ca4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f143ca8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f143cac:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143cb0:	0118c825 */ 	or	$t9,$t0,$t8
/*  f143cb4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f143cb8:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f143cbc:	3c04f600 */ 	lui	$a0,0xf600
/*  f143cc0:	3c014f00 */ 	lui	$at,0x4f00
/*  f143cc4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143cc8:	2605ffca */ 	addiu	$a1,$s0,-54
/*  f143ccc:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f143cd0:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f143cd4:	444ef800 */ 	cfc1	$t6,$31
/*  f143cd8:	44cff800 */ 	ctc1	$t7,$31
/*  f143cdc:	00000000 */ 	nop
/*  f143ce0:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f143ce4:	444ff800 */ 	cfc1	$t7,$31
/*  f143ce8:	00000000 */ 	nop
/*  f143cec:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143cf0:	51e00013 */ 	beqzl	$t7,.L0f143d40
/*  f143cf4:	440f3000 */ 	mfc1	$t7,$f6
/*  f143cf8:	44813000 */ 	mtc1	$at,$f6
/*  f143cfc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143d00:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f143d04:	44cff800 */ 	ctc1	$t7,$31
/*  f143d08:	00000000 */ 	nop
/*  f143d0c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f143d10:	444ff800 */ 	cfc1	$t7,$31
/*  f143d14:	00000000 */ 	nop
/*  f143d18:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143d1c:	15e00005 */ 	bnez	$t7,.L0f143d34
/*  f143d20:	00000000 */ 	nop
/*  f143d24:	440f3000 */ 	mfc1	$t7,$f6
/*  f143d28:	3c018000 */ 	lui	$at,0x8000
/*  f143d2c:	10000007 */ 	b	.L0f143d4c
/*  f143d30:	01e17825 */ 	or	$t7,$t7,$at
.L0f143d34:
/*  f143d34:	10000005 */ 	b	.L0f143d4c
/*  f143d38:	240fffff */ 	addiu	$t7,$zero,-1
/*  f143d3c:	440f3000 */ 	mfc1	$t7,$f6
.L0f143d40:
/*  f143d40:	00000000 */ 	nop
/*  f143d44:	05e0fffb */ 	bltz	$t7,.L0f143d34
/*  f143d48:	00000000 */ 	nop
.L0f143d4c:
/*  f143d4c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f143d50:	44cef800 */ 	ctc1	$t6,$31
/*  f143d54:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f143d58:	03247025 */ 	or	$t6,$t9,$a0
/*  f143d5c:	01c97825 */ 	or	$t7,$t6,$t1
/*  f143d60:	2618ffd5 */ 	addiu	$t8,$s0,-43
/*  f143d64:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f143d68:	00197080 */ 	sll	$t6,$t9,0x2
/*  f143d6c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f143d70:	014e7825 */ 	or	$t7,$t2,$t6
/*  f143d74:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f143d78:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f143d7c:	3c01f600 */ 	lui	$at,0xf600
/*  f143d80:	02a01025 */ 	or	$v0,$s5,$zero
/*  f143d84:	0311f821 */ 	addu	$ra,$t8,$s1
/*  f143d88:	27ffffff */ 	addiu	$ra,$ra,-1
/*  f143d8c:	27f9ffe8 */ 	addiu	$t9,$ra,-24
/*  f143d90:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f143d94:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f143d98:	30b803ff */ 	andi	$t8,$a1,0x3ff
/*  f143d9c:	00182880 */ 	sll	$a1,$t8,0x2
/*  f143da0:	01e46825 */ 	or	$t5,$t7,$a0
/*  f143da4:	01a57025 */ 	or	$t6,$t5,$a1
/*  f143da8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f143dac:	8fa60300 */ 	lw	$a2,0x300($sp)
/*  f143db0:	27ecffe7 */ 	addiu	$t4,$ra,-25
/*  f143db4:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f143db8:	24c60019 */ 	addiu	$a2,$a2,0x19
/*  f143dbc:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f143dc0:	448c4000 */ 	mtc1	$t4,$f8
/*  f143dc4:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f143dc8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f143dcc:	27e4ffe2 */ 	addiu	$a0,$ra,-30
/*  f143dd0:	01c67825 */ 	or	$t7,$t6,$a2
/*  f143dd4:	309803ff */ 	andi	$t8,$a0,0x3ff
/*  f143dd8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f143ddc:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f143de0:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f143de4:	8faa0300 */ 	lw	$t2,0x300($sp)
/*  f143de8:	03217025 */ 	or	$t6,$t9,$at
/*  f143dec:	01c57825 */ 	or	$t7,$t6,$a1
/*  f143df0:	afbf008c */ 	sw	$ra,0x8c($sp)
/*  f143df4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f143df8:	27eeffe1 */ 	addiu	$t6,$ra,-31
/*  f143dfc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f143e00:	2548002b */ 	addiu	$t0,$t2,0x2b
/*  f143e04:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f143e08:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f143e0c:	00184080 */ 	sll	$t0,$t8,0x2
/*  f143e10:	46001281 */ 	sub.s	$f10,$f2,$f0
/*  f143e14:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f143e18:	254e001a */ 	addiu	$t6,$t2,0x1a
/*  f143e1c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f143e20:	0308c825 */ 	or	$t9,$t8,$t0
/*  f143e24:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f143e28:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143e2c:	444ef800 */ 	cfc1	$t6,$31
/*  f143e30:	44cff800 */ 	ctc1	$t7,$31
/*  f143e34:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143e38:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143e3c:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f143e40:	02a01825 */ 	or	$v1,$s5,$zero
/*  f143e44:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f143e48:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f143e4c:	444ff800 */ 	cfc1	$t7,$31
/*  f143e50:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143e54:	3c014f00 */ 	lui	$at,0x4f00
/*  f143e58:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143e5c:	51e00013 */ 	beqzl	$t7,.L0f143eac
/*  f143e60:	440f2000 */ 	mfc1	$t7,$f4
/*  f143e64:	44812000 */ 	mtc1	$at,$f4
/*  f143e68:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143e6c:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f143e70:	44cff800 */ 	ctc1	$t7,$31
/*  f143e74:	00000000 */ 	nop
/*  f143e78:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f143e7c:	444ff800 */ 	cfc1	$t7,$31
/*  f143e80:	00000000 */ 	nop
/*  f143e84:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143e88:	15e00005 */ 	bnez	$t7,.L0f143ea0
/*  f143e8c:	00000000 */ 	nop
/*  f143e90:	440f2000 */ 	mfc1	$t7,$f4
/*  f143e94:	3c018000 */ 	lui	$at,0x8000
/*  f143e98:	10000007 */ 	b	.L0f143eb8
/*  f143e9c:	01e17825 */ 	or	$t7,$t7,$at
.L0f143ea0:
/*  f143ea0:	10000005 */ 	b	.L0f143eb8
/*  f143ea4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f143ea8:	440f2000 */ 	mfc1	$t7,$f4
.L0f143eac:
/*  f143eac:	00000000 */ 	nop
/*  f143eb0:	05e0fffb */ 	bltz	$t7,.L0f143ea0
/*  f143eb4:	00000000 */ 	nop
.L0f143eb8:
/*  f143eb8:	44cef800 */ 	ctc1	$t6,$31
/*  f143ebc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f143ec0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f143ec4:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f143ec8:	254f002c */ 	addiu	$t7,$t2,0x2c
/*  f143ecc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f143ed0:	03267025 */ 	or	$t6,$t9,$a2
/*  f143ed4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f143ed8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f143edc:	444ff800 */ 	cfc1	$t7,$31
/*  f143ee0:	44d8f800 */ 	ctc1	$t8,$31
/*  f143ee4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f143ee8:	00997025 */ 	or	$t6,$a0,$t9
/*  f143eec:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f143ef0:	02a04825 */ 	or	$t1,$s5,$zero
/*  f143ef4:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f143ef8:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f143efc:	4458f800 */ 	cfc1	$t8,$31
/*  f143f00:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143f04:	3c014f00 */ 	lui	$at,0x4f00
/*  f143f08:	33180078 */ 	andi	$t8,$t8,0x78
/*  f143f0c:	53000013 */ 	beqzl	$t8,.L0f143f5c
/*  f143f10:	44184000 */ 	mfc1	$t8,$f8
/*  f143f14:	44814000 */ 	mtc1	$at,$f8
/*  f143f18:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f143f1c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f143f20:	44d8f800 */ 	ctc1	$t8,$31
/*  f143f24:	00000000 */ 	nop
/*  f143f28:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f143f2c:	4458f800 */ 	cfc1	$t8,$31
/*  f143f30:	00000000 */ 	nop
/*  f143f34:	33180078 */ 	andi	$t8,$t8,0x78
/*  f143f38:	17000005 */ 	bnez	$t8,.L0f143f50
/*  f143f3c:	00000000 */ 	nop
/*  f143f40:	44184000 */ 	mfc1	$t8,$f8
/*  f143f44:	3c018000 */ 	lui	$at,0x8000
/*  f143f48:	10000007 */ 	b	.L0f143f68
/*  f143f4c:	0301c025 */ 	or	$t8,$t8,$at
.L0f143f50:
/*  f143f50:	10000005 */ 	b	.L0f143f68
/*  f143f54:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f143f58:	44184000 */ 	mfc1	$t8,$f8
.L0f143f5c:
/*  f143f5c:	00000000 */ 	nop
/*  f143f60:	0700fffb */ 	bltz	$t8,.L0f143f50
/*  f143f64:	00000000 */ 	nop
.L0f143f68:
/*  f143f68:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f143f6c:	44cff800 */ 	ctc1	$t7,$31
/*  f143f70:	00197380 */ 	sll	$t6,$t9,0xe
/*  f143f74:	01c87825 */ 	or	$t7,$t6,$t0
/*  f143f78:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f143f7c:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f143f80:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f143f84:	02a01025 */ 	or	$v0,$s5,$zero
/*  f143f88:	44985000 */ 	mtc1	$t8,$f10
/*  f143f8c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143f90:	3c014f00 */ 	lui	$at,0x4f00
/*  f143f94:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f143f98:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f143f9c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f143fa0:	4459f800 */ 	cfc1	$t9,$31
/*  f143fa4:	44cef800 */ 	ctc1	$t6,$31
/*  f143fa8:	00000000 */ 	nop
/*  f143fac:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f143fb0:	444ef800 */ 	cfc1	$t6,$31
/*  f143fb4:	00000000 */ 	nop
/*  f143fb8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f143fbc:	51c00013 */ 	beqzl	$t6,.L0f14400c
/*  f143fc0:	440e5000 */ 	mfc1	$t6,$f10
/*  f143fc4:	44815000 */ 	mtc1	$at,$f10
/*  f143fc8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f143fcc:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f143fd0:	44cef800 */ 	ctc1	$t6,$31
/*  f143fd4:	00000000 */ 	nop
/*  f143fd8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f143fdc:	444ef800 */ 	cfc1	$t6,$31
/*  f143fe0:	00000000 */ 	nop
/*  f143fe4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f143fe8:	15c00005 */ 	bnez	$t6,.L0f144000
/*  f143fec:	00000000 */ 	nop
/*  f143ff0:	440e5000 */ 	mfc1	$t6,$f10
/*  f143ff4:	3c018000 */ 	lui	$at,0x8000
/*  f143ff8:	10000007 */ 	b	.L0f144018
/*  f143ffc:	01c17025 */ 	or	$t6,$t6,$at
.L0f144000:
/*  f144000:	10000005 */ 	b	.L0f144018
/*  f144004:	240effff */ 	addiu	$t6,$zero,-1
/*  f144008:	440e5000 */ 	mfc1	$t6,$f10
.L0f14400c:
/*  f14400c:	00000000 */ 	nop
/*  f144010:	05c0fffb */ 	bltz	$t6,.L0f144000
/*  f144014:	00000000 */ 	nop
.L0f144018:
/*  f144018:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14401c:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f144020:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144024:	44d9f800 */ 	ctc1	$t9,$31
/*  f144028:	3c01f600 */ 	lui	$at,0xf600
/*  f14402c:	0301c825 */ 	or	$t9,$t8,$at
/*  f144030:	25cf0038 */ 	addiu	$t7,$t6,0x38
/*  f144034:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144038:	44842000 */ 	mtc1	$a0,$f4
/*  f14403c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f144040:	032e7825 */ 	or	$t7,$t9,$t6
/*  f144044:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f144048:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14404c:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f144050:	02a01825 */ 	or	$v1,$s5,$zero
/*  f144054:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144058:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f14405c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144060:	24980001 */ 	addiu	$t8,$a0,0x1
/*  f144064:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f144068:	01c77825 */ 	or	$t7,$t6,$a3
/*  f14406c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144070:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144074:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f144078:	01c17825 */ 	or	$t7,$t6,$at
/*  f14407c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f144080:	4459f800 */ 	cfc1	$t9,$31
/*  f144084:	44cef800 */ 	ctc1	$t6,$31
/*  f144088:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f14408c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f144090:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f144094:	3c014f00 */ 	lui	$at,0x4f00
/*  f144098:	444ef800 */ 	cfc1	$t6,$31
/*  f14409c:	00000000 */ 	nop
/*  f1440a0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1440a4:	51c00013 */ 	beqzl	$t6,.L0f1440f4
/*  f1440a8:	440e5000 */ 	mfc1	$t6,$f10
/*  f1440ac:	44815000 */ 	mtc1	$at,$f10
/*  f1440b0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1440b4:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f1440b8:	44cef800 */ 	ctc1	$t6,$31
/*  f1440bc:	00000000 */ 	nop
/*  f1440c0:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f1440c4:	444ef800 */ 	cfc1	$t6,$31
/*  f1440c8:	00000000 */ 	nop
/*  f1440cc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1440d0:	15c00005 */ 	bnez	$t6,.L0f1440e8
/*  f1440d4:	00000000 */ 	nop
/*  f1440d8:	440e5000 */ 	mfc1	$t6,$f10
/*  f1440dc:	3c018000 */ 	lui	$at,0x8000
/*  f1440e0:	10000007 */ 	b	.L0f144100
/*  f1440e4:	01c17025 */ 	or	$t6,$t6,$at
.L0f1440e8:
/*  f1440e8:	10000005 */ 	b	.L0f144100
/*  f1440ec:	240effff */ 	addiu	$t6,$zero,-1
/*  f1440f0:	440e5000 */ 	mfc1	$t6,$f10
.L0f1440f4:
/*  f1440f4:	00000000 */ 	nop
/*  f1440f8:	05c0fffb */ 	bltz	$t6,.L0f1440e8
/*  f1440fc:	00000000 */ 	nop
.L0f144100:
/*  f144100:	44d9f800 */ 	ctc1	$t9,$31
/*  f144104:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f144108:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14410c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144110:	272effc9 */ 	addiu	$t6,$t9,-55
/*  f144114:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f144118:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f14411c:	03197025 */ 	or	$t6,$t8,$t9
/*  f144120:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f144124:	44912000 */ 	mtc1	$s1,$f4
.L0f144128:
/*  f144128:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14412c:	44815000 */ 	mtc1	$at,$f10
/*  f144130:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f144134:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144138:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f14413c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144140:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144144:	03317021 */ 	addu	$t6,$t9,$s1
/*  f144148:	460a0103 */ 	div.s	$f4,$f0,$f10
/*  f14414c:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f144150:	448f3000 */ 	mtc1	$t7,$f6
/*  f144154:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144158:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f14415c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f144160:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f144164:	1461006c */ 	bne	$v1,$at,.L0f144318
/*  f144168:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f14416c:	0011c043 */ 	sra	$t8,$s1,0x1
/*  f144170:	8fae02f8 */ 	lw	$t6,0x2f8($sp)
/*  f144174:	03191021 */ 	addu	$v0,$t8,$t9
/*  f144178:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f14417c:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f144180:	3c0cf600 */ 	lui	$t4,0xf600
/*  f144184:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f144188:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f14418c:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f144190:	244f0007 */ 	addiu	$t7,$v0,0x7
/*  f144194:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144198:	00191880 */ 	sll	$v1,$t9,0x2
/*  f14419c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1441a0:	032c7025 */ 	or	$t6,$t9,$t4
/*  f1441a4:	01c37825 */ 	or	$t7,$t6,$v1
/*  f1441a8:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f1441ac:	308503ff */ 	andi	$a1,$a0,0x3ff
/*  f1441b0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1441b4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1441b8:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f1441bc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1441c0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1441c4:	01f83825 */ 	or	$a3,$t7,$t8
/*  f1441c8:	03002825 */ 	or	$a1,$t8,$zero
/*  f1441cc:	24580005 */ 	addiu	$t8,$v0,0x5
/*  f1441d0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1441d4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1441d8:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f1441dc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1441e0:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f1441e4:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f1441e8:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f1441ec:	02a04025 */ 	or	$t0,$s5,$zero
/*  f1441f0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1441f4:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f1441f8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1441fc:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f144200:	2459fffa */ 	addiu	$t9,$v0,-6
/*  f144204:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144208:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14420c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144210:	03035025 */ 	or	$t2,$t8,$v1
/*  f144214:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f144218:	02a04825 */ 	or	$t1,$s5,$zero
/*  f14421c:	2459fffc */ 	addiu	$t9,$v0,-4
/*  f144220:	ad070004 */ 	sw	$a3,0x4($t0)
/*  f144224:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144228:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f14422c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144230:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144234:	24430001 */ 	addiu	$v1,$v0,0x1
/*  f144238:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f14423c:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f144240:	02a05825 */ 	or	$t3,$s5,$zero
/*  f144244:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f144248:	ad780004 */ 	sw	$t8,0x4($t3)
/*  f14424c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144250:	24980007 */ 	addiu	$t8,$a0,0x7
/*  f144254:	3c01f600 */ 	lui	$at,0xf600
/*  f144258:	01c11825 */ 	or	$v1,$t6,$at
/*  f14425c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144260:	00197080 */ 	sll	$t6,$t9,0x2
/*  f144264:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144268:	006e7825 */ 	or	$t7,$v1,$t6
/*  f14426c:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f144270:	02a02825 */ 	or	$a1,$s5,$zero
/*  f144274:	24990002 */ 	addiu	$t9,$a0,0x2
/*  f144278:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f14427c:	0008c380 */ 	sll	$t8,$t0,0xe
/*  f144280:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144284:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f144288:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14428c:	030f3825 */ 	or	$a3,$t8,$t7
/*  f144290:	03004025 */ 	or	$t0,$t8,$zero
/*  f144294:	24980005 */ 	addiu	$t8,$a0,0x5
/*  f144298:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f14429c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1442a0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1442a4:	006e7825 */ 	or	$t7,$v1,$t6
/*  f1442a8:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f1442ac:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1442b0:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f1442b4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1442b8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1442bc:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1442c0:	248ffffa */ 	addiu	$t7,$a0,-6
/*  f1442c4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1442c8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1442cc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1442d0:	02a04825 */ 	or	$t1,$s5,$zero
/*  f1442d4:	006e5025 */ 	or	$t2,$v1,$t6
/*  f1442d8:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f1442dc:	01197025 */ 	or	$t6,$t0,$t9
/*  f1442e0:	248ffffc */ 	addiu	$t7,$a0,-4
/*  f1442e4:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f1442e8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1442ec:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1442f0:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f1442f4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1442f8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f1442fc:	01197025 */ 	or	$t6,$t0,$t9
/*  f144300:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f144304:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f144308:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14430c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144310:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144314:	9303006b */ 	lbu	$v1,0x6b($t8)
.L0f144318:
/*  f144318:	1460000a */ 	bnez	$v1,.L0f144344
/*  f14431c:	24045849 */ 	addiu	$a0,$zero,0x5849
/*  f144320:	3c190050 */ 	lui	$t9,0x50
/*  f144324:	3c0e000f */ 	lui	$t6,0xf
/*  f144328:	3c1400ff */ 	lui	$s4,0xff
/*  f14432c:	373900ff */ 	ori	$t9,$t9,0xff
/*  f144330:	35ce00ff */ 	ori	$t6,$t6,0xff
/*  f144334:	369400a0 */ 	ori	$s4,$s4,0xa0
/*  f144338:	afb902b4 */ 	sw	$t9,0x2b4($sp)
/*  f14433c:	1000000f */ 	b	.L0f14437c
/*  f144340:	afae02b0 */ 	sw	$t6,0x2b0($sp)
.L0f144344:
/*  f144344:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144348:	14610007 */ 	bne	$v1,$at,.L0f144368
/*  f14434c:	3c02ff33 */ 	lui	$v0,0xff33
/*  f144350:	3c022244 */ 	lui	$v0,0x2244
/*  f144354:	3454ffff */ 	ori	$s4,$v0,0xffff
/*  f144358:	240f0fff */ 	addiu	$t7,$zero,0xfff
/*  f14435c:	afb402b4 */ 	sw	$s4,0x2b4($sp)
/*  f144360:	10000006 */ 	b	.L0f14437c
/*  f144364:	afaf02b0 */ 	sw	$t7,0x2b0($sp)
.L0f144368:
/*  f144368:	3c180f00 */ 	lui	$t8,0xf00
/*  f14436c:	345400ff */ 	ori	$s4,$v0,0xff
/*  f144370:	371800ff */ 	ori	$t8,$t8,0xff
/*  f144374:	afb402b4 */ 	sw	$s4,0x2b4($sp)
/*  f144378:	afb802b0 */ 	sw	$t8,0x2b0($sp)
.L0f14437c:
/*  f14437c:	0fc5b9f1 */ 	jal	langGet
/*  f144380:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f144384:	3c017f1b */ 	lui	$at,%hi(var7f1b5f50)
/*  f144388:	c4285f50 */ 	lwc1	$f8,%lo(var7f1b5f50)($at)
/*  f14438c:	c7aa02c0 */ 	lwc1	$f10,0x2c0($sp)
/*  f144390:	27b30308 */ 	addiu	$s3,$sp,0x308
/*  f144394:	3c057f1b */ 	lui	$a1,%hi(var7f1b5de4)
/*  f144398:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f14439c:	3c077f1b */ 	lui	$a3,%hi(var7f1b5df0)
/*  f1443a0:	24e75df0 */ 	addiu	$a3,$a3,%lo(var7f1b5df0)
/*  f1443a4:	24a55de4 */ 	addiu	$a1,$a1,%lo(var7f1b5de4)
/*  f1443a8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1443ac:	00403025 */ 	or	$a2,$v0,$zero
/*  f1443b0:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f1443b4:	0c004dad */ 	jal	sprintf
/*  f1443b8:	f7a60010 */ 	sdc1	$f6,0x10($sp)
/*  f1443bc:	3c198008 */ 	lui	$t9,%hi(var8007fb04)
/*  f1443c0:	8f39fb04 */ 	lw	$t9,%lo(var8007fb04)($t9)
/*  f1443c4:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f1443c8:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f1443cc:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f1443d0:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f1443d4:	02603025 */ 	or	$a2,$s3,$zero
/*  f1443d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1443dc:	0fc55cbe */ 	jal	textMeasure
/*  f1443e0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1443e4:	8fa902ac */ 	lw	$t1,0x2ac($sp)
/*  f1443e8:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f1443ec:	8fb20300 */ 	lw	$s2,0x300($sp)
/*  f1443f0:	00097080 */ 	sll	$t6,$t1,0x2
/*  f1443f4:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f1443f8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f1443fc:	01c97021 */ 	addu	$t6,$t6,$t1
/*  f144400:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f144404:	01c04825 */ 	or	$t1,$t6,$zero
/*  f144408:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f14440c:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144410:	2652000e */ 	addiu	$s2,$s2,0xe
/*  f144414:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f144418:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f14441c:	024e7821 */ 	addu	$t7,$s2,$t6
/*  f144420:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144424:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144428:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f14442c:	afb202e8 */ 	sw	$s2,0x2e8($sp)
/*  f144430:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f144434:	afa202ec */ 	sw	$v0,0x2ec($sp)
/*  f144438:	afa90080 */ 	sw	$t1,0x80($sp)
/*  f14443c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144440:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144444:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144448:	0fc54e16 */ 	jal	func0f153858
/*  f14444c:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144450:	0c002f02 */ 	jal	viGetX
/*  f144454:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144458:	00028400 */ 	sll	$s0,$v0,0x10
/*  f14445c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144460:	0c002f06 */ 	jal	viGetY
/*  f144464:	03208025 */ 	or	$s0,$t9,$zero
/*  f144468:	3c0e8008 */ 	lui	$t6,%hi(var8007fb08)
/*  f14446c:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f144470:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f144474:	8dcefb08 */ 	lw	$t6,%lo(var8007fb08)($t6)
/*  f144478:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f14447c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144480:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144484:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144488:	02603825 */ 	or	$a3,$s3,$zero
/*  f14448c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f144490:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144494:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144498:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f14449c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1444a0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1444a4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1444a8:	0fc55b92 */ 	jal	textRender
/*  f1444ac:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1444b0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1444b4:	0fc5b9f1 */ 	jal	langGet
/*  f1444b8:	2404584a */ 	addiu	$a0,$zero,0x584a
/*  f1444bc:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1444c0:	3c017f1b */ 	lui	$at,%hi(var7f1b5f54)
/*  f1444c4:	c4285f54 */ 	lwc1	$f8,%lo(var7f1b5f54)($at)
/*  f1444c8:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f1444cc:	3c057f1b */ 	lui	$a1,%hi(var7f1b5df4)
/*  f1444d0:	3c077f1b */ 	lui	$a3,%hi(var7f1b5e00)
/*  f1444d4:	c5ca0060 */ 	lwc1	$f10,0x60($t6)
/*  f1444d8:	24e75e00 */ 	addiu	$a3,$a3,%lo(var7f1b5e00)
/*  f1444dc:	24a55df4 */ 	addiu	$a1,$a1,%lo(var7f1b5df4)
/*  f1444e0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f1444e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1444e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1444ec:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f1444f0:	0c004dad */ 	jal	sprintf
/*  f1444f4:	f7a60010 */ 	sdc1	$f6,0x10($sp)
/*  f1444f8:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f1444fc:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f144500:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f144504:	26510009 */ 	addiu	$s1,$s2,0x9
/*  f144508:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f14450c:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144510:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144514:	02603025 */ 	or	$a2,$s3,$zero
/*  f144518:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f14451c:	0fc55cbe */ 	jal	textMeasure
/*  f144520:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144524:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f144528:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f14452c:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144530:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144534:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f144538:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f14453c:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f144540:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144544:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144548:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f14454c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144550:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144554:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144558:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f14455c:	0fc54e16 */ 	jal	func0f153858
/*  f144560:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144564:	0c002f02 */ 	jal	viGetX
/*  f144568:	0040a825 */ 	or	$s5,$v0,$zero
/*  f14456c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144570:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144574:	0c002f06 */ 	jal	viGetY
/*  f144578:	03208025 */ 	or	$s0,$t9,$zero
/*  f14457c:	3c0e8008 */ 	lui	$t6,%hi(var8007fb08)
/*  f144580:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f144584:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f144588:	8dcefb08 */ 	lw	$t6,%lo(var8007fb08)($t6)
/*  f14458c:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144590:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144594:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144598:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f14459c:	02603825 */ 	or	$a3,$s3,$zero
/*  f1445a0:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f1445a4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1445a8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1445ac:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1445b0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1445b4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1445b8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1445bc:	0fc55b92 */ 	jal	textRender
/*  f1445c0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1445c4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1445c8:	0fc5b9f1 */ 	jal	langGet
/*  f1445cc:	2404584b */ 	addiu	$a0,$zero,0x584b
/*  f1445d0:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1445d4:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e04)
/*  f1445d8:	24a55e04 */ 	addiu	$a1,$a1,%lo(var7f1b5e04)
/*  f1445dc:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f1445e0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1445e4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1445e8:	c5ca001c */ 	lwc1	$f10,0x1c($t6)
/*  f1445ec:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f1445f0:	44074000 */ 	mfc1	$a3,$f8
/*  f1445f4:	0c004dad */ 	jal	sprintf
/*  f1445f8:	00000000 */ 	nop
/*  f1445fc:	3c188008 */ 	lui	$t8,%hi(var8007fb04)
/*  f144600:	8f18fb04 */ 	lw	$t8,%lo(var8007fb04)($t8)
/*  f144604:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f144608:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f14460c:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f144610:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144614:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144618:	02603025 */ 	or	$a2,$s3,$zero
/*  f14461c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144620:	0fc55cbe */ 	jal	textMeasure
/*  f144624:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144628:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f14462c:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f144630:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f144634:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144638:	00797021 */ 	addu	$t6,$v1,$t9
/*  f14463c:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f144640:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f144644:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f144648:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14464c:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f144650:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144654:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144658:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f14465c:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f144660:	0fc54e16 */ 	jal	func0f153858
/*  f144664:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144668:	0c002f02 */ 	jal	viGetX
/*  f14466c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144670:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144674:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144678:	0c002f06 */ 	jal	viGetY
/*  f14467c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f144680:	3c0f8008 */ 	lui	$t7,%hi(var8007fb08)
/*  f144684:	3c188008 */ 	lui	$t8,%hi(var8007fb04)
/*  f144688:	8f18fb04 */ 	lw	$t8,%lo(var8007fb04)($t8)
/*  f14468c:	8deffb08 */ 	lw	$t7,%lo(var8007fb08)($t7)
/*  f144690:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f144694:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144698:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f14469c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1446a0:	02603825 */ 	or	$a3,$s3,$zero
/*  f1446a4:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f1446a8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1446ac:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1446b0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1446b4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1446b8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1446bc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1446c0:	0fc55b92 */ 	jal	textRender
/*  f1446c4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1446c8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1446cc:	0fc5b9f1 */ 	jal	langGet
/*  f1446d0:	2404584c */ 	addiu	$a0,$zero,0x584c
/*  f1446d4:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1446d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e0c)
/*  f1446dc:	24a55e0c */ 	addiu	$a1,$a1,%lo(var7f1b5e0c)
/*  f1446e0:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f1446e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1446e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1446ec:	c5e40028 */ 	lwc1	$f4,0x28($t7)
/*  f1446f0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1446f4:	44073000 */ 	mfc1	$a3,$f6
/*  f1446f8:	0c004dad */ 	jal	sprintf
/*  f1446fc:	00000000 */ 	nop
/*  f144700:	3c198008 */ 	lui	$t9,%hi(var8007fb04)
/*  f144704:	8f39fb04 */ 	lw	$t9,%lo(var8007fb04)($t9)
/*  f144708:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f14470c:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f144710:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f144714:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144718:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f14471c:	02603025 */ 	or	$a2,$s3,$zero
/*  f144720:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144724:	0fc55cbe */ 	jal	textMeasure
/*  f144728:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14472c:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f144730:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f144734:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f144738:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14473c:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f144740:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f144744:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f144748:	afb902d8 */ 	sw	$t9,0x2d8($sp)
/*  f14474c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144750:	afaf02dc */ 	sw	$t7,0x2dc($sp)
/*  f144754:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144758:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f14475c:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144760:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f144764:	0fc54e16 */ 	jal	func0f153858
/*  f144768:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f14476c:	0c002f02 */ 	jal	viGetX
/*  f144770:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144774:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144778:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f14477c:	0c002f06 */ 	jal	viGetY
/*  f144780:	01e08025 */ 	or	$s0,$t7,$zero
/*  f144784:	3c188008 */ 	lui	$t8,%hi(var8007fb08)
/*  f144788:	3c198008 */ 	lui	$t9,%hi(var8007fb04)
/*  f14478c:	8f39fb04 */ 	lw	$t9,%lo(var8007fb04)($t9)
/*  f144790:	8f18fb08 */ 	lw	$t8,%lo(var8007fb08)($t8)
/*  f144794:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f144798:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14479c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1447a0:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1447a4:	02603825 */ 	or	$a3,$s3,$zero
/*  f1447a8:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f1447ac:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1447b0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1447b4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1447b8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1447bc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1447c0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1447c4:	0fc55b92 */ 	jal	textRender
/*  f1447c8:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1447cc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1447d0:	0fc5b9f1 */ 	jal	langGet
/*  f1447d4:	2404584d */ 	addiu	$a0,$zero,0x584d
/*  f1447d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e14)
/*  f1447dc:	24a55e14 */ 	addiu	$a1,$a1,%lo(var7f1b5e14)
/*  f1447e0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1447e4:	0c004dad */ 	jal	sprintf
/*  f1447e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1447ec:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f1447f0:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f1447f4:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f1447f8:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f1447fc:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144800:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144804:	02603025 */ 	or	$a2,$s3,$zero
/*  f144808:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f14480c:	0fc55cbe */ 	jal	textMeasure
/*  f144810:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144814:	8fa902a8 */ 	lw	$t1,0x2a8($sp)
/*  f144818:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f14481c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f144820:	11200003 */ 	beqz	$t1,.L0f144830
/*  f144824:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f144828:	10000002 */ 	b	.L0f144834
/*  f14482c:	2402fffd */ 	addiu	$v0,$zero,-3
.L0f144830:
/*  f144830:	00001025 */ 	or	$v0,$zero,$zero
.L0f144834:
/*  f144834:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f144838:	032e1821 */ 	addu	$v1,$t9,$t6
/*  f14483c:	11200003 */ 	beqz	$t1,.L0f14484c
/*  f144840:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f144844:	10000002 */ 	b	.L0f144850
/*  f144848:	24020012 */ 	addiu	$v0,$zero,0x12
.L0f14484c:
/*  f14484c:	00001025 */ 	or	$v0,$zero,$zero
.L0f144850:
/*  f144850:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f144854:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144858:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f14485c:	2508ffd7 */ 	addiu	$t0,$t0,-41
/*  f144860:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f144864:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f144868:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f14486c:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144870:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144874:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f144878:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f14487c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144880:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144884:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144888:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f14488c:	0fc54e16 */ 	jal	func0f153858
/*  f144890:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144894:	0c002f02 */ 	jal	viGetX
/*  f144898:	0040a825 */ 	or	$s5,$v0,$zero
/*  f14489c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1448a0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f1448a4:	0c002f06 */ 	jal	viGetY
/*  f1448a8:	03208025 */ 	or	$s0,$t9,$zero
/*  f1448ac:	3c0e8008 */ 	lui	$t6,%hi(var8007fb08)
/*  f1448b0:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f1448b4:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f1448b8:	8dcefb08 */ 	lw	$t6,%lo(var8007fb08)($t6)
/*  f1448bc:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f1448c0:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f1448c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1448c8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1448cc:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1448d0:	02603825 */ 	or	$a3,$s3,$zero
/*  f1448d4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1448d8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1448dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1448e0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1448e4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1448e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1448ec:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1448f0:	0fc55b92 */ 	jal	textRender
/*  f1448f4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1448f8:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1448fc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144900:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f144904:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f144908:	5460000b */ 	bnezl	$v1,.L0f144938
/*  f14490c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144910:	0fc5b9f1 */ 	jal	langGet
/*  f144914:	2404584e */ 	addiu	$a0,$zero,0x584e
/*  f144918:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e18)
/*  f14491c:	24a55e18 */ 	addiu	$a1,$a1,%lo(var7f1b5e18)
/*  f144920:	02602025 */ 	or	$a0,$s3,$zero
/*  f144924:	0c004dad */ 	jal	sprintf
/*  f144928:	00403025 */ 	or	$a2,$v0,$zero
/*  f14492c:	10000014 */ 	b	.L0f144980
/*  f144930:	00000000 */ 	nop
/*  f144934:	24010001 */ 	addiu	$at,$zero,0x1
.L0f144938:
/*  f144938:	1461000a */ 	bne	$v1,$at,.L0f144964
/*  f14493c:	00000000 */ 	nop
/*  f144940:	0fc5b9f1 */ 	jal	langGet
/*  f144944:	240458d0 */ 	addiu	$a0,$zero,0x58d0
/*  f144948:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e1c)
/*  f14494c:	24a55e1c */ 	addiu	$a1,$a1,%lo(var7f1b5e1c)
/*  f144950:	02602025 */ 	or	$a0,$s3,$zero
/*  f144954:	0c004dad */ 	jal	sprintf
/*  f144958:	00403025 */ 	or	$a2,$v0,$zero
/*  f14495c:	10000008 */ 	b	.L0f144980
/*  f144960:	00000000 */ 	nop
.L0f144964:
/*  f144964:	0fc5b9f1 */ 	jal	langGet
/*  f144968:	240458d9 */ 	addiu	$a0,$zero,0x58d9
/*  f14496c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e20)
/*  f144970:	24a55e20 */ 	addiu	$a1,$a1,%lo(var7f1b5e20)
/*  f144974:	02602025 */ 	or	$a0,$s3,$zero
/*  f144978:	0c004dad */ 	jal	sprintf
/*  f14497c:	00403025 */ 	or	$a2,$v0,$zero
.L0f144980:
/*  f144980:	3c188008 */ 	lui	$t8,%hi(var8007fb04)
/*  f144984:	8f18fb04 */ 	lw	$t8,%lo(var8007fb04)($t8)
/*  f144988:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f14498c:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f144990:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144994:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144998:	02603025 */ 	or	$a2,$s3,$zero
/*  f14499c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1449a0:	0fc55cbe */ 	jal	textMeasure
/*  f1449a4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1449a8:	8fa902a8 */ 	lw	$t1,0x2a8($sp)
/*  f1449ac:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f1449b0:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f1449b4:	11200003 */ 	beqz	$t1,.L0f1449c4
/*  f1449b8:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f1449bc:	10000002 */ 	b	.L0f1449c8
/*  f1449c0:	2402fffd */ 	addiu	$v0,$zero,-3
.L0f1449c4:
/*  f1449c4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1449c8:
/*  f1449c8:	00597021 */ 	addu	$t6,$v0,$t9
/*  f1449cc:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f1449d0:	11200003 */ 	beqz	$t1,.L0f1449e0
/*  f1449d4:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f1449d8:	10000002 */ 	b	.L0f1449e4
/*  f1449dc:	24020014 */ 	addiu	$v0,$zero,0x14
.L0f1449e0:
/*  f1449e0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1449e4:
/*  f1449e4:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f1449e8:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f1449ec:	00584021 */ 	addu	$t0,$v0,$t8
/*  f1449f0:	2508ffde */ 	addiu	$t0,$t0,-34
/*  f1449f4:	00797021 */ 	addu	$t6,$v1,$t9
/*  f1449f8:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f1449fc:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f144a00:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f144a04:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144a08:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f144a0c:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144a10:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144a14:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144a18:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144a1c:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144a20:	0fc54e16 */ 	jal	func0f153858
/*  f144a24:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144a28:	0c002f02 */ 	jal	viGetX
/*  f144a2c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144a30:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144a34:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144a38:	0c002f06 */ 	jal	viGetY
/*  f144a3c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f144a40:	3c0f8008 */ 	lui	$t7,%hi(var8007fb08)
/*  f144a44:	3c188008 */ 	lui	$t8,%hi(var8007fb04)
/*  f144a48:	8f18fb04 */ 	lw	$t8,%lo(var8007fb04)($t8)
/*  f144a4c:	8deffb08 */ 	lw	$t7,%lo(var8007fb08)($t7)
/*  f144a50:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f144a54:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f144a58:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144a5c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144a60:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144a64:	02603825 */ 	or	$a3,$s3,$zero
/*  f144a68:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144a6c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144a70:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144a74:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144a78:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f144a7c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144a80:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f144a84:	0fc55b92 */ 	jal	textRender
/*  f144a88:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f144a8c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144a90:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144a94:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144a98:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144a9c:	5460004f */ 	bnezl	$v1,.L0f144bdc
/*  f144aa0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144aa4:	0fc5b9f1 */ 	jal	langGet
/*  f144aa8:	2404584f */ 	addiu	$a0,$zero,0x584f
/*  f144aac:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e24)
/*  f144ab0:	24a55e24 */ 	addiu	$a1,$a1,%lo(var7f1b5e24)
/*  f144ab4:	02602025 */ 	or	$a0,$s3,$zero
/*  f144ab8:	0c004dad */ 	jal	sprintf
/*  f144abc:	00403025 */ 	or	$a2,$v0,$zero
/*  f144ac0:	3c198008 */ 	lui	$t9,%hi(var8007fb04)
/*  f144ac4:	8f39fb04 */ 	lw	$t9,%lo(var8007fb04)($t9)
/*  f144ac8:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f144acc:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f144ad0:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144ad4:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144ad8:	02603025 */ 	or	$a2,$s3,$zero
/*  f144adc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144ae0:	0fc55cbe */ 	jal	textMeasure
/*  f144ae4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144ae8:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f144aec:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f144af0:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f144af4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f144af8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f144afc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144b00:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f144b04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144b08:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f144b0c:	01d81823 */ 	subu	$v1,$t6,$t8
/*  f144b10:	13200003 */ 	beqz	$t9,.L0f144b20
/*  f144b14:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144b18:	10000002 */ 	b	.L0f144b24
/*  f144b1c:	2402fff3 */ 	addiu	$v0,$zero,-13
.L0f144b20:
/*  f144b20:	00001025 */ 	or	$v0,$zero,$zero
.L0f144b24:
/*  f144b24:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f144b28:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f144b2c:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f144b30:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f144b34:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f144b38:	006ec021 */ 	addu	$t8,$v1,$t6
/*  f144b3c:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f144b40:	01197821 */ 	addu	$t7,$t0,$t9
/*  f144b44:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144b48:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144b4c:	afb802dc */ 	sw	$t8,0x2dc($sp)
/*  f144b50:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144b54:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144b58:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144b5c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144b60:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144b64:	0fc54e16 */ 	jal	func0f153858
/*  f144b68:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144b6c:	0c002f02 */ 	jal	viGetX
/*  f144b70:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144b74:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144b78:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f144b7c:	0c002f06 */ 	jal	viGetY
/*  f144b80:	03008025 */ 	or	$s0,$t8,$zero
/*  f144b84:	3c198008 */ 	lui	$t9,%hi(var8007fb08)
/*  f144b88:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f144b8c:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f144b90:	8f39fb08 */ 	lw	$t9,%lo(var8007fb08)($t9)
/*  f144b94:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f144b98:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144b9c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144ba0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144ba4:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144ba8:	02603825 */ 	or	$a3,$s3,$zero
/*  f144bac:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144bb0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144bb4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144bb8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144bbc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144bc0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144bc4:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f144bc8:	0fc55b92 */ 	jal	textRender
/*  f144bcc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144bd0:	1000009b */ 	b	.L0f144e40
/*  f144bd4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144bd8:	24010001 */ 	addiu	$at,$zero,0x1
.L0f144bdc:
/*  f144bdc:	1461004e */ 	bne	$v1,$at,.L0f144d18
/*  f144be0:	00000000 */ 	nop
/*  f144be4:	0fc5b9f1 */ 	jal	langGet
/*  f144be8:	240459d4 */ 	addiu	$a0,$zero,0x59d4
/*  f144bec:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e2c)
/*  f144bf0:	24a55e2c */ 	addiu	$a1,$a1,%lo(var7f1b5e2c)
/*  f144bf4:	02602025 */ 	or	$a0,$s3,$zero
/*  f144bf8:	0c004dad */ 	jal	sprintf
/*  f144bfc:	00403025 */ 	or	$a2,$v0,$zero
/*  f144c00:	3c198008 */ 	lui	$t9,%hi(var8007fb04)
/*  f144c04:	8f39fb04 */ 	lw	$t9,%lo(var8007fb04)($t9)
/*  f144c08:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f144c0c:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f144c10:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144c14:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144c18:	02603025 */ 	or	$a2,$s3,$zero
/*  f144c1c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144c20:	0fc55cbe */ 	jal	textMeasure
/*  f144c24:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144c28:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f144c2c:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f144c30:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f144c34:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f144c38:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f144c3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144c40:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f144c44:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144c48:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f144c4c:	01f81823 */ 	subu	$v1,$t7,$t8
/*  f144c50:	13200003 */ 	beqz	$t9,.L0f144c60
/*  f144c54:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144c58:	10000002 */ 	b	.L0f144c64
/*  f144c5c:	2402fff3 */ 	addiu	$v0,$zero,-13
.L0f144c60:
/*  f144c60:	00001025 */ 	or	$v0,$zero,$zero
.L0f144c64:
/*  f144c64:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f144c68:	8faf02e4 */ 	lw	$t7,0x2e4($sp)
/*  f144c6c:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f144c70:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f144c74:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f144c78:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f144c7c:	27af02d8 */ 	addiu	$t7,$sp,0x2d8
/*  f144c80:	01197021 */ 	addu	$t6,$t0,$t9
/*  f144c84:	afae02d8 */ 	sw	$t6,0x2d8($sp)
/*  f144c88:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144c8c:	afb802dc */ 	sw	$t8,0x2dc($sp)
/*  f144c90:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144c94:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144c98:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144c9c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144ca0:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144ca4:	0fc54e16 */ 	jal	func0f153858
/*  f144ca8:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144cac:	0c002f02 */ 	jal	viGetX
/*  f144cb0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144cb4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144cb8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f144cbc:	0c002f06 */ 	jal	viGetY
/*  f144cc0:	03008025 */ 	or	$s0,$t8,$zero
/*  f144cc4:	3c198008 */ 	lui	$t9,%hi(var8007fb08)
/*  f144cc8:	3c0e8008 */ 	lui	$t6,%hi(var8007fb04)
/*  f144ccc:	8dcefb04 */ 	lw	$t6,%lo(var8007fb04)($t6)
/*  f144cd0:	8f39fb08 */ 	lw	$t9,%lo(var8007fb08)($t9)
/*  f144cd4:	8faf02b4 */ 	lw	$t7,0x2b4($sp)
/*  f144cd8:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144cdc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144ce0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144ce4:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144ce8:	02603825 */ 	or	$a3,$s3,$zero
/*  f144cec:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144cf0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144cf4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144cf8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144cfc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f144d00:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144d04:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f144d08:	0fc55b92 */ 	jal	textRender
/*  f144d0c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144d10:	1000004b */ 	b	.L0f144e40
/*  f144d14:	0040a825 */ 	or	$s5,$v0,$zero
.L0f144d18:
/*  f144d18:	0fc5b9f1 */ 	jal	langGet
/*  f144d1c:	240459d5 */ 	addiu	$a0,$zero,0x59d5
/*  f144d20:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e34)
/*  f144d24:	24a55e34 */ 	addiu	$a1,$a1,%lo(var7f1b5e34)
/*  f144d28:	02602025 */ 	or	$a0,$s3,$zero
/*  f144d2c:	0c004dad */ 	jal	sprintf
/*  f144d30:	00403025 */ 	or	$a2,$v0,$zero
/*  f144d34:	3c198008 */ 	lui	$t9,%hi(var8007fb04)
/*  f144d38:	8f39fb04 */ 	lw	$t9,%lo(var8007fb04)($t9)
/*  f144d3c:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f144d40:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f144d44:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144d48:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144d4c:	02603025 */ 	or	$a2,$s3,$zero
/*  f144d50:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144d54:	0fc55cbe */ 	jal	textMeasure
/*  f144d58:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144d5c:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f144d60:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f144d64:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f144d68:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f144d6c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f144d70:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144d74:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f144d78:	01d81823 */ 	subu	$v1,$t6,$t8
/*  f144d7c:	13200003 */ 	beqz	$t9,.L0f144d8c
/*  f144d80:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144d84:	10000002 */ 	b	.L0f144d90
/*  f144d88:	2402fff3 */ 	addiu	$v0,$zero,-13
.L0f144d8c:
/*  f144d8c:	00001025 */ 	or	$v0,$zero,$zero
.L0f144d90:
/*  f144d90:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f144d94:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f144d98:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f144d9c:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f144da0:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f144da4:	006ec021 */ 	addu	$t8,$v1,$t6
/*  f144da8:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f144dac:	01197821 */ 	addu	$t7,$t0,$t9
/*  f144db0:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144db4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144db8:	afb802dc */ 	sw	$t8,0x2dc($sp)
/*  f144dbc:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144dc0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144dc4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144dc8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144dcc:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144dd0:	0fc54e16 */ 	jal	func0f153858
/*  f144dd4:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144dd8:	0c002f02 */ 	jal	viGetX
/*  f144ddc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144de0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144de4:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f144de8:	0c002f06 */ 	jal	viGetY
/*  f144dec:	03008025 */ 	or	$s0,$t8,$zero
/*  f144df0:	3c198008 */ 	lui	$t9,%hi(var8007fb08)
/*  f144df4:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f144df8:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f144dfc:	8f39fb08 */ 	lw	$t9,%lo(var8007fb08)($t9)
/*  f144e00:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f144e04:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144e08:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144e0c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144e10:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144e14:	02603825 */ 	or	$a3,$s3,$zero
/*  f144e18:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144e1c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144e20:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144e24:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144e28:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144e2c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144e30:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f144e34:	0fc55b92 */ 	jal	textRender
/*  f144e38:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144e3c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f144e40:
/*  f144e40:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f144e44:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f144e48:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f144e4c:	5460000b */ 	bnezl	$v1,.L0f144e7c
/*  f144e50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144e54:	0fc5b9f1 */ 	jal	langGet
/*  f144e58:	24045850 */ 	addiu	$a0,$zero,0x5850
/*  f144e5c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e3c)
/*  f144e60:	24a55e3c */ 	addiu	$a1,$a1,%lo(var7f1b5e3c)
/*  f144e64:	02602025 */ 	or	$a0,$s3,$zero
/*  f144e68:	0c004dad */ 	jal	sprintf
/*  f144e6c:	00403025 */ 	or	$a2,$v0,$zero
/*  f144e70:	10000014 */ 	b	.L0f144ec4
/*  f144e74:	00000000 */ 	nop
/*  f144e78:	24010001 */ 	addiu	$at,$zero,0x1
.L0f144e7c:
/*  f144e7c:	1461000a */ 	bne	$v1,$at,.L0f144ea8
/*  f144e80:	00000000 */ 	nop
/*  f144e84:	0fc5b9f1 */ 	jal	langGet
/*  f144e88:	240458cf */ 	addiu	$a0,$zero,0x58cf
/*  f144e8c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e40)
/*  f144e90:	24a55e40 */ 	addiu	$a1,$a1,%lo(var7f1b5e40)
/*  f144e94:	02602025 */ 	or	$a0,$s3,$zero
/*  f144e98:	0c004dad */ 	jal	sprintf
/*  f144e9c:	00403025 */ 	or	$a2,$v0,$zero
/*  f144ea0:	10000008 */ 	b	.L0f144ec4
/*  f144ea4:	00000000 */ 	nop
.L0f144ea8:
/*  f144ea8:	0fc5b9f1 */ 	jal	langGet
/*  f144eac:	240458d8 */ 	addiu	$a0,$zero,0x58d8
/*  f144eb0:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e44)
/*  f144eb4:	24a55e44 */ 	addiu	$a1,$a1,%lo(var7f1b5e44)
/*  f144eb8:	02602025 */ 	or	$a0,$s3,$zero
/*  f144ebc:	0c004dad */ 	jal	sprintf
/*  f144ec0:	00403025 */ 	or	$a2,$v0,$zero
.L0f144ec4:
/*  f144ec4:	3c0e8008 */ 	lui	$t6,%hi(var8007fb04)
/*  f144ec8:	8dcefb04 */ 	lw	$t6,%lo(var8007fb04)($t6)
/*  f144ecc:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f144ed0:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f144ed4:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144ed8:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144edc:	02603025 */ 	or	$a2,$s3,$zero
/*  f144ee0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144ee4:	0fc55cbe */ 	jal	textMeasure
/*  f144ee8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144eec:	8fa902a8 */ 	lw	$t1,0x2a8($sp)
/*  f144ef0:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f144ef4:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f144ef8:	11200003 */ 	beqz	$t1,.L0f144f08
/*  f144efc:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f144f00:	10000002 */ 	b	.L0f144f0c
/*  f144f04:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f144f08:
/*  f144f08:	00001025 */ 	or	$v0,$zero,$zero
.L0f144f0c:
/*  f144f0c:	01cf7023 */ 	subu	$t6,$t6,$t7
/*  f144f10:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f144f14:	01cf7023 */ 	subu	$t6,$t6,$t7
/*  f144f18:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f144f1c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f144f20:	032e1823 */ 	subu	$v1,$t9,$t6
/*  f144f24:	11200003 */ 	beqz	$t1,.L0f144f34
/*  f144f28:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144f2c:	10000002 */ 	b	.L0f144f38
/*  f144f30:	2402fff5 */ 	addiu	$v0,$zero,-11
.L0f144f34:
/*  f144f34:	00001025 */ 	or	$v0,$zero,$zero
.L0f144f38:
/*  f144f38:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f144f3c:	8faf02e4 */ 	lw	$t7,0x2e4($sp)
/*  f144f40:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144f44:	00584021 */ 	addu	$t0,$v0,$t8
/*  f144f48:	25080022 */ 	addiu	$t0,$t0,0x22
/*  f144f4c:	006fc821 */ 	addu	$t9,$v1,$t7
/*  f144f50:	27af02d8 */ 	addiu	$t7,$sp,0x2d8
/*  f144f54:	010ec021 */ 	addu	$t8,$t0,$t6
/*  f144f58:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f144f5c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144f60:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f144f64:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144f68:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144f6c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144f70:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144f74:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144f78:	0fc54e16 */ 	jal	func0f153858
/*  f144f7c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144f80:	0c002f02 */ 	jal	viGetX
/*  f144f84:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144f88:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144f8c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144f90:	0c002f06 */ 	jal	viGetY
/*  f144f94:	03208025 */ 	or	$s0,$t9,$zero
/*  f144f98:	3c0e8008 */ 	lui	$t6,%hi(var8007fb08)
/*  f144f9c:	3c188008 */ 	lui	$t8,%hi(var8007fb04)
/*  f144fa0:	8f18fb04 */ 	lw	$t8,%lo(var8007fb04)($t8)
/*  f144fa4:	8dcefb08 */ 	lw	$t6,%lo(var8007fb08)($t6)
/*  f144fa8:	8faf02b4 */ 	lw	$t7,0x2b4($sp)
/*  f144fac:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f144fb0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144fb4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144fb8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144fbc:	02603825 */ 	or	$a3,$s3,$zero
/*  f144fc0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144fc4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144fc8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144fcc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144fd0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f144fd4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144fd8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f144fdc:	0fc55b92 */ 	jal	textRender
/*  f144fe0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f144fe4:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f144fe8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144fec:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f144ff0:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144ff4:	10600003 */ 	beqz	$v1,.L0f145004
/*  f144ff8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f144ffc:	1461000a */ 	bne	$v1,$at,.L0f145028
/*  f145000:	00000000 */ 	nop
.L0f145004:
/*  f145004:	0fc5b9f1 */ 	jal	langGet
/*  f145008:	24045851 */ 	addiu	$a0,$zero,0x5851
/*  f14500c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e48)
/*  f145010:	24a55e48 */ 	addiu	$a1,$a1,%lo(var7f1b5e48)
/*  f145014:	02602025 */ 	or	$a0,$s3,$zero
/*  f145018:	0c004dad */ 	jal	sprintf
/*  f14501c:	00403025 */ 	or	$a2,$v0,$zero
/*  f145020:	10000008 */ 	b	.L0f145044
/*  f145024:	00000000 */ 	nop
.L0f145028:
/*  f145028:	0fc5b9f1 */ 	jal	langGet
/*  f14502c:	240458ce */ 	addiu	$a0,$zero,0x58ce
/*  f145030:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e4c)
/*  f145034:	24a55e4c */ 	addiu	$a1,$a1,%lo(var7f1b5e4c)
/*  f145038:	02602025 */ 	or	$a0,$s3,$zero
/*  f14503c:	0c004dad */ 	jal	sprintf
/*  f145040:	00403025 */ 	or	$a2,$v0,$zero
.L0f145044:
/*  f145044:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f145048:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f14504c:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f145050:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f145054:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145058:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f14505c:	02603025 */ 	or	$a2,$s3,$zero
/*  f145060:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145064:	0fc55cbe */ 	jal	textMeasure
/*  f145068:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f14506c:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f145070:	8fb402ac */ 	lw	$s4,0x2ac($sp)
/*  f145074:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f145078:	13200003 */ 	beqz	$t9,.L0f145088
/*  f14507c:	00147080 */ 	sll	$t6,$s4,0x2
/*  f145080:	10000002 */ 	b	.L0f14508c
/*  f145084:	2402ffdd */ 	addiu	$v0,$zero,-35
.L0f145088:
/*  f145088:	00001025 */ 	or	$v0,$zero,$zero
.L0f14508c:
/*  f14508c:	01d47021 */ 	addu	$t6,$t6,$s4
/*  f145090:	3c014040 */ 	lui	$at,0x4040
/*  f145094:	44814000 */ 	mtc1	$at,$f8
/*  f145098:	25d8fffb */ 	addiu	$t8,$t6,-5
/*  f14509c:	44983000 */ 	mtc1	$t8,$f6
/*  f1450a0:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f1450a4:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f1450a8:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f1450ac:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1450b0:	44823000 */ 	mtc1	$v0,$f6
/*  f1450b4:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f1450b8:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f1450bc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1450c0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1450c4:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*  f1450c8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1450cc:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f1450d0:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f1450d4:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f1450d8:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1450dc:	44033000 */ 	mfc1	$v1,$f6
/*  f1450e0:	53200004 */ 	beqzl	$t9,.L0f1450f4
/*  f1450e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1450e8:	10000002 */ 	b	.L0f1450f4
/*  f1450ec:	2402fffe */ 	addiu	$v0,$zero,-2
/*  f1450f0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1450f4:
/*  f1450f4:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f1450f8:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f1450fc:	2508fff4 */ 	addiu	$t0,$t0,-12
/*  f145100:	00787821 */ 	addu	$t7,$v1,$t8
/*  f145104:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f145108:	01197021 */ 	addu	$t6,$t0,$t9
/*  f14510c:	afae02d8 */ 	sw	$t6,0x2d8($sp)
/*  f145110:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145114:	afaf02dc */ 	sw	$t7,0x2dc($sp)
/*  f145118:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f14511c:	0fc54e16 */ 	jal	func0f153858
/*  f145120:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f145124:	0c002f02 */ 	jal	viGetX
/*  f145128:	0040a825 */ 	or	$s5,$v0,$zero
/*  f14512c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145130:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f145134:	0c002f06 */ 	jal	viGetY
/*  f145138:	01e08025 */ 	or	$s0,$t7,$zero
/*  f14513c:	3c198008 */ 	lui	$t9,%hi(var8007fb08)
/*  f145140:	3c0e8008 */ 	lui	$t6,%hi(var8007fb04)
/*  f145144:	8dcefb04 */ 	lw	$t6,%lo(var8007fb04)($t6)
/*  f145148:	8f39fb08 */ 	lw	$t9,%lo(var8007fb08)($t9)
/*  f14514c:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f145150:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f145154:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145158:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f14515c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145160:	02603825 */ 	or	$a3,$s3,$zero
/*  f145164:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145168:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f14516c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145170:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145174:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f145178:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14517c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f145180:	0fc55b92 */ 	jal	textRender
/*  f145184:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f145188:	0fc54e0e */ 	jal	func0f153838
/*  f14518c:	00402025 */ 	or	$a0,$v0,$zero
/*  f145190:	8ed90288 */ 	lw	$t9,0x288($s6)
/*  f145194:	0040a825 */ 	or	$s5,$v0,$zero
/*  f145198:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f14519c:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f1451a0:	00028600 */ 	sll	$s0,$v0,0x18
/*  f1451a4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f1451a8:	00107603 */ 	sra	$t6,$s0,0x18
/*  f1451ac:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1451b0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f1451b4:	03002025 */ 	or	$a0,$t8,$zero
/*  f1451b8:	0c0053d8 */ 	jal	contGetButtons
/*  f1451bc:	3405ffff */ 	dli	$a1,0xffff
/*  f1451c0:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1451c4:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f1451c8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1451cc:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f1451d0:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f1451d4:	3405ffff */ 	dli	$a1,0xffff
/*  f1451d8:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1451dc:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f1451e0:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f1451e4:	0c005384 */ 	jal	contGetStickX
/*  f1451e8:	03202025 */ 	or	$a0,$t9,$zero
/*  f1451ec:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1451f0:	00047603 */ 	sra	$t6,$a0,0x18
/*  f1451f4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1451f8:	0c0053ae */ 	jal	contGetStickY
/*  f1451fc:	a3a20251 */ 	sb	$v0,0x251($sp)
/*  f145200:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145204:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145208:	3c18e700 */ 	lui	$t8,0xe700
/*  f14520c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f145210:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145214:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145218:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f14521c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f145220:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f145224:	02a02825 */ 	or	$a1,$s5,$zero
/*  f145228:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f14522c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f145230:	3c19ba00 */ 	lui	$t9,0xba00
/*  f145234:	37390602 */ 	ori	$t9,$t9,0x602
/*  f145238:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14523c:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f145240:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f145244:	02a03025 */ 	or	$a2,$s5,$zero
/*  f145248:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f14524c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f145250:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f145254:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f145258:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14525c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f145260:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f145264:	3c0fb900 */ 	lui	$t7,0xb900
/*  f145268:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f14526c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145270:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145274:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f145278:	3c19ba00 */ 	lui	$t9,0xba00
/*  f14527c:	37391001 */ 	ori	$t9,$t9,0x1001
/*  f145280:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145284:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f145288:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f14528c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145290:	3c0eba00 */ 	lui	$t6,0xba00
/*  f145294:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f145298:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14529c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1452a0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1452a4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1452a8:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f1452ac:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1452b0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1452b4:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f1452b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1452bc:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f1452c0:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1452c4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1452c8:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f1452cc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1452d0:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f1452d4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1452d8:	02a04025 */ 	or	$t0,$s5,$zero
/*  f1452dc:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f1452e0:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f1452e4:	3c0f0050 */ 	lui	$t7,0x50
/*  f1452e8:	3c18b900 */ 	lui	$t8,0xb900
/*  f1452ec:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f1452f0:	35ef4340 */ 	ori	$t7,$t7,0x4340
/*  f1452f4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1452f8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1452fc:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f145300:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f145304:	3c0efffd */ 	lui	$t6,0xfffd
/*  f145308:	3c19fcff */ 	lui	$t9,0xfcff
/*  f14530c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f145310:	35cef6fb */ 	ori	$t6,$t6,0xf6fb
/*  f145314:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145318:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f14531c:	8fb802a8 */ 	lw	$t8,0x2a8($sp)
/*  f145320:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145324:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145328:	170001ff */ 	bnez	$t8,.L0f145b28
/*  f14532c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f145330:	15e10003 */ 	bne	$t7,$at,.L0f145340
/*  f145334:	2407ffab */ 	addiu	$a3,$zero,-85
/*  f145338:	10000001 */ 	b	.L0f145340
/*  f14533c:	2407ffb4 */ 	addiu	$a3,$zero,-76
.L0f145340:
/*  f145340:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145344:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145348:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f14534c:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f145350:	32380808 */ 	andi	$t8,$s1,0x808
/*  f145354:	324f0808 */ 	andi	$t7,$s2,0x808
/*  f145358:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f14535c:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145360:	3c0b1020 */ 	lui	$t3,0x1020
/*  f145364:	14600011 */ 	bnez	$v1,.L0f1453ac
/*  f145368:	00000000 */ 	nop
/*  f14536c:	13000002 */ 	beqz	$t8,.L0f145378
/*  f145370:	02202825 */ 	or	$a1,$s1,$zero
/*  f145374:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145378:
/*  f145378:	11e00004 */ 	beqz	$t7,.L0f14538c
/*  f14537c:	02403025 */ 	or	$a2,$s2,$zero
/*  f145380:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145384:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145388:	03209825 */ 	or	$s3,$t9,$zero
.L0f14538c:
/*  f14538c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145390:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145394:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145398:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f14539c:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1453a0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1453a4:	1000002f */ 	b	.L0f145464
/*  f1453a8:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f1453ac:
/*  f1453ac:	14610017 */ 	bne	$v1,$at,.L0f14540c
/*  f1453b0:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1453b4:	32390808 */ 	andi	$t9,$s1,0x808
/*  f1453b8:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f1453bc:	13200002 */ 	beqz	$t9,.L0f1453c8
/*  f1453c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1453c4:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f1453c8:
/*  f1453c8:	324e0808 */ 	andi	$t6,$s2,0x808
/*  f1453cc:	11c00004 */ 	beqz	$t6,.L0f1453e0
/*  f1453d0:	02403025 */ 	or	$a2,$s2,$zero
/*  f1453d4:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f1453d8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1453dc:	03009825 */ 	or	$s3,$t8,$zero
.L0f1453e0:
/*  f1453e0:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1453e4:	000fca00 */ 	sll	$t9,$t7,0x8
/*  f1453e8:	3c0b1020 */ 	lui	$t3,0x1020
/*  f1453ec:	032b7025 */ 	or	$t6,$t9,$t3
/*  f1453f0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1453f4:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f1453f8:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f1453fc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145400:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145404:	10000017 */ 	b	.L0f145464
/*  f145408:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f14540c:
/*  f14540c:	322f0808 */ 	andi	$t7,$s1,0x808
/*  f145410:	11e00002 */ 	beqz	$t7,.L0f14541c
/*  f145414:	02202825 */ 	or	$a1,$s1,$zero
/*  f145418:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14541c:
/*  f14541c:	32590808 */ 	andi	$t9,$s2,0x808
/*  f145420:	13200004 */ 	beqz	$t9,.L0f145434
/*  f145424:	02403025 */ 	or	$a2,$s2,$zero
/*  f145428:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14542c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145430:	01c09825 */ 	or	$s3,$t6,$zero
.L0f145434:
/*  f145434:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f145438:	332e00ff */ 	andi	$t6,$t9,0xff
/*  f14543c:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145440:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145444:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f145448:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f14544c:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f145450:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145454:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145458:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f14545c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145460:	3c0b1020 */ 	lui	$t3,0x1020
.L0f145464:
/*  f145464:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145468:	24ef0008 */ 	addiu	$t7,$a3,0x8
/*  f14546c:	8fb0008c */ 	lw	$s0,0x8c($sp)
/*  f145470:	01ff0019 */ 	multu	$t7,$ra
/*  f145474:	8fb10300 */ 	lw	$s1,0x300($sp)
/*  f145478:	3c01f600 */ 	lui	$at,0xf600
/*  f14547c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145480:	262c0012 */ 	addiu	$t4,$s1,0x12
/*  f145484:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f145488:	00196080 */ 	sll	$t4,$t9,0x2
/*  f14548c:	262d000a */ 	addiu	$t5,$s1,0xa
/*  f145490:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145494:	0000c012 */ 	mflo	$t8
/*  f145498:	03105021 */ 	addu	$t2,$t8,$s0
/*  f14549c:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f1454a0:	00ff0019 */ 	multu	$a3,$ra
/*  f1454a4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1454a8:	0301c825 */ 	or	$t9,$t8,$at
/*  f1454ac:	032c7025 */ 	or	$t6,$t9,$t4
/*  f1454b0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1454b4:	31b803ff */ 	andi	$t8,$t5,0x3ff
/*  f1454b8:	00186880 */ 	sll	$t5,$t8,0x2
/*  f1454bc:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f1454c0:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f1454c4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1454c8:	00007812 */ 	mflo	$t7
/*  f1454cc:	01f04021 */ 	addu	$t0,$t7,$s0
/*  f1454d0:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f1454d4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1454d8:	01edc025 */ 	or	$t8,$t7,$t5
/*  f1454dc:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1454e0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1454e4:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f1454e8:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f1454ec:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1454f0:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1454f4:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f1454f8:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1454fc:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f145500:	01194021 */ 	addu	$t0,$t0,$t9
/*  f145504:	14600012 */ 	bnez	$v1,.L0f145550
/*  f145508:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f14550c:	30b90404 */ 	andi	$t9,$a1,0x404
/*  f145510:	13200002 */ 	beqz	$t9,.L0f14551c
/*  f145514:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145518:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14551c:
/*  f14551c:	30ce0404 */ 	andi	$t6,$a2,0x404
/*  f145520:	11c00004 */ 	beqz	$t6,.L0f145534
/*  f145524:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145528:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14552c:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145530:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145534:
/*  f145534:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145538:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f14553c:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f145540:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145544:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145548:	10000028 */ 	b	.L0f1455ec
/*  f14554c:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145550:
/*  f145550:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145554:	14610013 */ 	bne	$v1,$at,.L0f1455a4
/*  f145558:	30ae0404 */ 	andi	$t6,$a1,0x404
/*  f14555c:	30af0404 */ 	andi	$t7,$a1,0x404
/*  f145560:	11e00002 */ 	beqz	$t7,.L0f14556c
/*  f145564:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f145568:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f14556c:
/*  f14556c:	30d80404 */ 	andi	$t8,$a2,0x404
/*  f145570:	13000004 */ 	beqz	$t8,.L0f145584
/*  f145574:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145578:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f14557c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145580:	03209825 */ 	or	$s3,$t9,$zero
.L0f145584:
/*  f145584:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145588:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f14558c:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f145590:	371900ff */ 	ori	$t9,$t8,0xff
/*  f145594:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145598:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14559c:	10000013 */ 	b	.L0f1455ec
/*  f1455a0:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1455a4:
/*  f1455a4:	11c00002 */ 	beqz	$t6,.L0f1455b0
/*  f1455a8:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1455ac:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1455b0:
/*  f1455b0:	30cf0404 */ 	andi	$t7,$a2,0x404
/*  f1455b4:	11e00004 */ 	beqz	$t7,.L0f1455c8
/*  f1455b8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1455bc:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1455c0:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1455c4:	03009825 */ 	or	$s3,$t8,$zero
.L0f1455c8:
/*  f1455c8:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1455cc:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1455d0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1455d4:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1455d8:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1455dc:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1455e0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1455e4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1455e8:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1455ec:
/*  f1455ec:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f1455f0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1455f4:	3c01f600 */ 	lui	$at,0xf600
/*  f1455f8:	03217825 */ 	or	$t7,$t9,$at
/*  f1455fc:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f145600:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145604:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f145608:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f14560c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145610:	032d7825 */ 	or	$t7,$t9,$t5
/*  f145614:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f145618:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f14561c:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145620:	001fc080 */ 	sll	$t8,$ra,0x2
/*  f145624:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f145628:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f14562c:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f145630:	031fc021 */ 	addu	$t8,$t8,$ra
/*  f145634:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145638:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f14563c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f145640:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145644:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f145648:	14600012 */ 	bnez	$v1,.L0f145694
/*  f14564c:	01184021 */ 	addu	$t0,$t0,$t8
/*  f145650:	30b80202 */ 	andi	$t8,$a1,0x202
/*  f145654:	13000002 */ 	beqz	$t8,.L0f145660
/*  f145658:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f14565c:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145660:
/*  f145660:	30ce0202 */ 	andi	$t6,$a2,0x202
/*  f145664:	11c00004 */ 	beqz	$t6,.L0f145678
/*  f145668:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14566c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145670:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145674:	03209825 */ 	or	$s3,$t9,$zero
.L0f145678:
/*  f145678:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14567c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145680:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f145684:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145688:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14568c:	10000028 */ 	b	.L0f145730
/*  f145690:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145694:
/*  f145694:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145698:	14610013 */ 	bne	$v1,$at,.L0f1456e8
/*  f14569c:	30ae0202 */ 	andi	$t6,$a1,0x202
/*  f1456a0:	30b90202 */ 	andi	$t9,$a1,0x202
/*  f1456a4:	13200002 */ 	beqz	$t9,.L0f1456b0
/*  f1456a8:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f1456ac:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f1456b0:
/*  f1456b0:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f1456b4:	11e00004 */ 	beqz	$t7,.L0f1456c8
/*  f1456b8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1456bc:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f1456c0:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1456c4:	03009825 */ 	or	$s3,$t8,$zero
.L0f1456c8:
/*  f1456c8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1456cc:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f1456d0:	032b7825 */ 	or	$t7,$t9,$t3
/*  f1456d4:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1456d8:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1456dc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1456e0:	10000013 */ 	b	.L0f145730
/*  f1456e4:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1456e8:
/*  f1456e8:	11c00002 */ 	beqz	$t6,.L0f1456f4
/*  f1456ec:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1456f0:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1456f4:
/*  f1456f4:	30d90202 */ 	andi	$t9,$a2,0x202
/*  f1456f8:	13200004 */ 	beqz	$t9,.L0f14570c
/*  f1456fc:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145700:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145704:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145708:	01e09825 */ 	or	$s3,$t7,$zero
.L0f14570c:
/*  f14570c:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f145710:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f145714:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145718:	00137600 */ 	sll	$t6,$s3,0x18
/*  f14571c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f145720:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145724:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145728:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14572c:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145730:
/*  f145730:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f145734:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145738:	3c01f600 */ 	lui	$at,0xf600
/*  f14573c:	0301c825 */ 	or	$t9,$t8,$at
/*  f145740:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f145744:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145748:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f14574c:	032c7825 */ 	or	$t7,$t9,$t4
/*  f145750:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145754:	030dc825 */ 	or	$t9,$t8,$t5
/*  f145758:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f14575c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f145760:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145764:	001f7880 */ 	sll	$t7,$ra,0x2
/*  f145768:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f14576c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f145770:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f145774:	01ff7821 */ 	addu	$t7,$t7,$ra
/*  f145778:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f14577c:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f145780:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f145784:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145788:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f14578c:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f145790:	14600012 */ 	bnez	$v1,.L0f1457dc
/*  f145794:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f145798:	30af0101 */ 	andi	$t7,$a1,0x101
/*  f14579c:	11e00002 */ 	beqz	$t7,.L0f1457a8
/*  f1457a0:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1457a4:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1457a8:
/*  f1457a8:	30ce0101 */ 	andi	$t6,$a2,0x101
/*  f1457ac:	11c00004 */ 	beqz	$t6,.L0f1457c0
/*  f1457b0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1457b4:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1457b8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1457bc:	03009825 */ 	or	$s3,$t8,$zero
.L0f1457c0:
/*  f1457c0:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1457c4:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f1457c8:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f1457cc:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1457d0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1457d4:	10000028 */ 	b	.L0f145878
/*  f1457d8:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1457dc:
/*  f1457dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1457e0:	14610013 */ 	bne	$v1,$at,.L0f145830
/*  f1457e4:	30ae0101 */ 	andi	$t6,$a1,0x101
/*  f1457e8:	30b80101 */ 	andi	$t8,$a1,0x101
/*  f1457ec:	13000002 */ 	beqz	$t8,.L0f1457f8
/*  f1457f0:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f1457f4:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f1457f8:
/*  f1457f8:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f1457fc:	13200004 */ 	beqz	$t9,.L0f145810
/*  f145800:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145804:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145808:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14580c:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145810:
/*  f145810:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145814:	000ec200 */ 	sll	$t8,$t6,0x8
/*  f145818:	030bc825 */ 	or	$t9,$t8,$t3
/*  f14581c:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145820:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145824:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145828:	10000013 */ 	b	.L0f145878
/*  f14582c:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145830:
/*  f145830:	11c00002 */ 	beqz	$t6,.L0f14583c
/*  f145834:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145838:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14583c:
/*  f14583c:	30d80101 */ 	andi	$t8,$a2,0x101
/*  f145840:	13000004 */ 	beqz	$t8,.L0f145854
/*  f145844:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145848:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14584c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145850:	03209825 */ 	or	$s3,$t9,$zero
.L0f145854:
/*  f145854:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f145858:	331900ff */ 	andi	$t9,$t8,0xff
/*  f14585c:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f145860:	00137600 */ 	sll	$t6,$s3,0x18
/*  f145864:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f145868:	371900ff */ 	ori	$t9,$t8,0xff
/*  f14586c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145870:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145874:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145878:
/*  f145878:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f14587c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f145880:	3c01f600 */ 	lui	$at,0xf600
/*  f145884:	01e1c025 */ 	or	$t8,$t7,$at
/*  f145888:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f14588c:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145890:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f145894:	030cc825 */ 	or	$t9,$t8,$t4
/*  f145898:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14589c:	01edc025 */ 	or	$t8,$t7,$t5
/*  f1458a0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1458a4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1458a8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1458ac:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f1458b0:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f1458b4:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1458b8:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f1458bc:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f1458c0:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1458c4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1458c8:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1458cc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1458d0:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f1458d4:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1458d8:	14600012 */ 	bnez	$v1,.L0f145924
/*  f1458dc:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f1458e0:	30b90030 */ 	andi	$t9,$a1,0x30
/*  f1458e4:	13200002 */ 	beqz	$t9,.L0f1458f0
/*  f1458e8:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1458ec:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1458f0:
/*  f1458f0:	30ce0030 */ 	andi	$t6,$a2,0x30
/*  f1458f4:	11c00004 */ 	beqz	$t6,.L0f145908
/*  f1458f8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1458fc:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145900:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145904:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145908:
/*  f145908:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14590c:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f145910:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f145914:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145918:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14591c:	10000028 */ 	b	.L0f1459c0
/*  f145920:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145924:
/*  f145924:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145928:	14610013 */ 	bne	$v1,$at,.L0f145978
/*  f14592c:	30ae0030 */ 	andi	$t6,$a1,0x30
/*  f145930:	30af0030 */ 	andi	$t7,$a1,0x30
/*  f145934:	11e00002 */ 	beqz	$t7,.L0f145940
/*  f145938:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f14593c:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f145940:
/*  f145940:	30d80030 */ 	andi	$t8,$a2,0x30
/*  f145944:	13000004 */ 	beqz	$t8,.L0f145958
/*  f145948:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14594c:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145950:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145954:	03209825 */ 	or	$s3,$t9,$zero
.L0f145958:
/*  f145958:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f14595c:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f145960:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f145964:	371900ff */ 	ori	$t9,$t8,0xff
/*  f145968:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f14596c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145970:	10000013 */ 	b	.L0f1459c0
/*  f145974:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145978:
/*  f145978:	11c00002 */ 	beqz	$t6,.L0f145984
/*  f14597c:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145980:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145984:
/*  f145984:	30cf0030 */ 	andi	$t7,$a2,0x30
/*  f145988:	11e00004 */ 	beqz	$t7,.L0f14599c
/*  f14598c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145990:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145994:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145998:	03009825 */ 	or	$s3,$t8,$zero
.L0f14599c:
/*  f14599c:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1459a0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1459a4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1459a8:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1459ac:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1459b0:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1459b4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1459b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1459bc:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1459c0:
/*  f1459c0:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f1459c4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1459c8:	3c01f600 */ 	lui	$at,0xf600
/*  f1459cc:	03217825 */ 	or	$t7,$t9,$at
/*  f1459d0:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f1459d4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1459d8:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f1459dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1459e0:	032d7825 */ 	or	$t7,$t9,$t5
/*  f1459e4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1459e8:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f1459ec:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1459f0:	8fb802ac */ 	lw	$t8,0x2ac($sp)
/*  f1459f4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1459f8:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f1459fc:	00187080 */ 	sll	$t6,$t8,0x2
/*  f145a00:	01d87021 */ 	addu	$t6,$t6,$t8
/*  f145a04:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145a08:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f145a0c:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f145a10:	14600012 */ 	bnez	$v1,.L0f145a5c
/*  f145a14:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f145a18:	30b82000 */ 	andi	$t8,$a1,0x2000
/*  f145a1c:	13000002 */ 	beqz	$t8,.L0f145a28
/*  f145a20:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145a24:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145a28:
/*  f145a28:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f145a2c:	11c00004 */ 	beqz	$t6,.L0f145a40
/*  f145a30:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145a34:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145a38:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145a3c:	03209825 */ 	or	$s3,$t9,$zero
.L0f145a40:
/*  f145a40:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145a44:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145a48:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f145a4c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145a50:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145a54:	10000028 */ 	b	.L0f145af8
/*  f145a58:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145a5c:
/*  f145a5c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145a60:	14610013 */ 	bne	$v1,$at,.L0f145ab0
/*  f145a64:	30ae2000 */ 	andi	$t6,$a1,0x2000
/*  f145a68:	30b92000 */ 	andi	$t9,$a1,0x2000
/*  f145a6c:	13200002 */ 	beqz	$t9,.L0f145a78
/*  f145a70:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f145a74:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f145a78:
/*  f145a78:	30cf2000 */ 	andi	$t7,$a2,0x2000
/*  f145a7c:	11e00004 */ 	beqz	$t7,.L0f145a90
/*  f145a80:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145a84:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145a88:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145a8c:	03009825 */ 	or	$s3,$t8,$zero
.L0f145a90:
/*  f145a90:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145a94:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f145a98:	032b7825 */ 	or	$t7,$t9,$t3
/*  f145a9c:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f145aa0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145aa4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145aa8:	10000013 */ 	b	.L0f145af8
/*  f145aac:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145ab0:
/*  f145ab0:	11c00002 */ 	beqz	$t6,.L0f145abc
/*  f145ab4:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145ab8:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145abc:
/*  f145abc:	30d92000 */ 	andi	$t9,$a2,0x2000
/*  f145ac0:	13200004 */ 	beqz	$t9,.L0f145ad4
/*  f145ac4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145ac8:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145acc:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145ad0:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145ad4:
/*  f145ad4:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f145ad8:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f145adc:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145ae0:	00137600 */ 	sll	$t6,$s3,0x18
/*  f145ae4:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f145ae8:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145aec:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145af0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145af4:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145af8:
/*  f145af8:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f145afc:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145b00:	3c01f600 */ 	lui	$at,0xf600
/*  f145b04:	0301c825 */ 	or	$t9,$t8,$at
/*  f145b08:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f145b0c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145b10:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145b14:	032c7825 */ 	or	$t7,$t9,$t4
/*  f145b18:	030dc825 */ 	or	$t9,$t8,$t5
/*  f145b1c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145b20:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f145b24:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f145b28:
/*  f145b28:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145b2c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f145b30:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145b34:	15e10003 */ 	bne	$t7,$at,.L0f145b44
/*  f145b38:	3c0b1020 */ 	lui	$t3,0x1020
/*  f145b3c:	10000002 */ 	b	.L0f145b48
/*  f145b40:	2407ffd0 */ 	addiu	$a3,$zero,-48
.L0f145b44:
/*  f145b44:	2407ffc9 */ 	addiu	$a3,$zero,-55
.L0f145b48:
/*  f145b48:	83ae0251 */ 	lb	$t6,0x251($sp)
/*  f145b4c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f145b50:	44817000 */ 	mtc1	$at,$f14
/*  f145b54:	448e2000 */ 	mtc1	$t6,$f4
/*  f145b58:	3c0142c0 */ 	lui	$at,0x42c0
/*  f145b5c:	44818000 */ 	mtc1	$at,$f16
/*  f145b60:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f145b64:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145b68:	00022600 */ 	sll	$a0,$v0,0x18
/*  f145b6c:	46106202 */ 	mul.s	$f8,$f12,$f16
/*  f145b70:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f145b74:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f145b78:	44033000 */ 	mfc1	$v1,$f6
/*  f145b7c:	00000000 */ 	nop
/*  f145b80:	04610005 */ 	bgez	$v1,.L0f145b98
/*  f145b84:	307300ff */ 	andi	$s3,$v1,0xff
/*  f145b88:	00039823 */ 	negu	$s3,$v1
/*  f145b8c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145b90:	10000001 */ 	b	.L0f145b98
/*  f145b94:	03209825 */ 	or	$s3,$t9,$zero
.L0f145b98:
/*  f145b98:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f145b9c:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145ba0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f145ba4:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f145ba8:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145bac:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f145bb0:	14600006 */ 	bnez	$v1,.L0f145bcc
/*  f145bb4:	00000000 */ 	nop
/*  f145bb8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145bbc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145bc0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145bc4:	10000031 */ 	b	.L0f145c8c
/*  f145bc8:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f145bcc:
/*  f145bcc:	14610026 */ 	bne	$v1,$at,.L0f145c68
/*  f145bd0:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145bd4:	44932000 */ 	mtc1	$s3,$f4
/*  f145bd8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145bdc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145be0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145be4:	06610005 */ 	bgez	$s3,.L0f145bfc
/*  f145be8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f145bec:	3c014f80 */ 	lui	$at,0x4f80
/*  f145bf0:	44814000 */ 	mtc1	$at,$f8
/*  f145bf4:	00000000 */ 	nop
/*  f145bf8:	46080000 */ 	add.s	$f0,$f0,$f8
.L0f145bfc:
/*  f145bfc:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f145c00:	3c014180 */ 	lui	$at,0x4180
/*  f145c04:	44815000 */ 	mtc1	$at,$f10
/*  f145c08:	3c014200 */ 	lui	$at,0x4200
/*  f145c0c:	44814000 */ 	mtc1	$at,$f8
/*  f145c10:	3c014020 */ 	lui	$at,0x4020
/*  f145c14:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f145c18:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145c1c:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f145c20:	44192000 */ 	mfc1	$t9,$f4
/*  f145c24:	44812000 */ 	mtc1	$at,$f4
/*  f145c28:	00197e00 */ 	sll	$t7,$t9,0x18
/*  f145c2c:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f145c30:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f145c34:	44183000 */ 	mfc1	$t8,$f6
/*  f145c38:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f145c3c:	331900ff */ 	andi	$t9,$t8,0xff
/*  f145c40:	00197400 */ 	sll	$t6,$t9,0x10
/*  f145c44:	01eec025 */ 	or	$t8,$t7,$t6
/*  f145c48:	440f5000 */ 	mfc1	$t7,$f10
/*  f145c4c:	00000000 */ 	nop
/*  f145c50:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f145c54:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f145c58:	03197825 */ 	or	$t7,$t8,$t9
/*  f145c5c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f145c60:	1000000a */ 	b	.L0f145c8c
/*  f145c64:	ac6e0004 */ 	sw	$t6,0x4($v1)
.L0f145c68:
/*  f145c68:	00137883 */ 	sra	$t7,$s3,0x2
/*  f145c6c:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f145c70:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145c74:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145c78:	03387825 */ 	or	$t7,$t9,$t8
/*  f145c7c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f145c80:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145c84:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145c88:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f145c8c:
/*  f145c8c:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f145c90:	83b80251 */ 	lb	$t8,0x251($sp)
/*  f145c94:	57200050 */ 	bnezl	$t9,.L0f145dd8
/*  f145c98:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f145c9c:	1b000028 */ 	blez	$t8,.L0f145d40
/*  f145ca0:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145ca4:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145ca8:	44819000 */ 	mtc1	$at,$f18
/*  f145cac:	8fb802ac */ 	lw	$t8,0x2ac($sp)
/*  f145cb0:	3c01f600 */ 	lui	$at,0xf600
/*  f145cb4:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f145cb8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145cbc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145cc0:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f145cc4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f145cc8:	440e4000 */ 	mfc1	$t6,$f8
/*  f145ccc:	00000000 */ 	nop
/*  f145cd0:	01c7c821 */ 	addu	$t9,$t6,$a3
/*  f145cd4:	03380019 */ 	multu	$t9,$t8
/*  f145cd8:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f145cdc:	00007812 */ 	mflo	$t7
/*  f145ce0:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f145ce4:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f145ce8:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145cec:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f145cf0:	01e17025 */ 	or	$t6,$t7,$at
/*  f145cf4:	27380015 */ 	addiu	$t8,$t9,0x15
/*  f145cf8:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145cfc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f145d00:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145d04:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f145d08:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145d0c:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f145d10:	00ef0019 */ 	multu	$a3,$t7
/*  f145d14:	00007012 */ 	mflo	$t6
/*  f145d18:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f145d1c:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145d20:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145d24:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f145d28:	27380013 */ 	addiu	$t8,$t9,0x13
/*  f145d2c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145d30:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f145d34:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145d38:	10000026 */ 	b	.L0f145dd4
/*  f145d3c:	ac780004 */ 	sw	$t8,0x4($v1)
.L0f145d40:
/*  f145d40:	44819000 */ 	mtc1	$at,$f18
/*  f145d44:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145d48:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f145d4c:	46126282 */ 	mul.s	$f10,$f12,$f18
/*  f145d50:	3c01f600 */ 	lui	$at,0xf600
/*  f145d54:	00ef0019 */ 	multu	$a3,$t7
/*  f145d58:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145d5c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145d60:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f145d64:	00007012 */ 	mflo	$t6
/*  f145d68:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f145d6c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145d70:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f145d74:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f145d78:	01c1c825 */ 	or	$t9,$t6,$at
/*  f145d7c:	270f0015 */ 	addiu	$t7,$t8,0x15
/*  f145d80:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f145d84:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f145d88:	03387825 */ 	or	$t7,$t9,$t8
/*  f145d8c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f145d90:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145d94:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145d98:	44192000 */ 	mfc1	$t9,$f4
/*  f145d9c:	00000000 */ 	nop
/*  f145da0:	0327c021 */ 	addu	$t8,$t9,$a3
/*  f145da4:	030f0019 */ 	multu	$t8,$t7
/*  f145da8:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f145dac:	00007012 */ 	mflo	$t6
/*  f145db0:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f145db4:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145db8:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145dbc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f145dc0:	27380013 */ 	addiu	$t8,$t9,0x13
/*  f145dc4:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145dc8:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f145dcc:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145dd0:	ac780004 */ 	sw	$t8,0x4($v1)
.L0f145dd4:
/*  f145dd4:	00047e03 */ 	sra	$t7,$a0,0x18
.L0f145dd8:
/*  f145dd8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f145ddc:	44844000 */ 	mtc1	$a0,$f8
/*  f145de0:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145de4:	44819000 */ 	mtc1	$at,$f18
/*  f145de8:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f145dec:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145df0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145df4:	46106282 */ 	mul.s	$f10,$f12,$f16
/*  f145df8:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f145dfc:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145e00:	44032000 */ 	mfc1	$v1,$f4
/*  f145e04:	00000000 */ 	nop
/*  f145e08:	04610005 */ 	bgez	$v1,.L0f145e20
/*  f145e0c:	307300ff */ 	andi	$s3,$v1,0xff
/*  f145e10:	00039823 */ 	negu	$s3,$v1
/*  f145e14:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145e18:	10000001 */ 	b	.L0f145e20
/*  f145e1c:	03209825 */ 	or	$s3,$t9,$zero
.L0f145e20:
/*  f145e20:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145e24:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145e28:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f145e2c:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f145e30:	373800ff */ 	ori	$t8,$t9,0xff
/*  f145e34:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145e38:	14600005 */ 	bnez	$v1,.L0f145e50
/*  f145e3c:	00000000 */ 	nop
/*  f145e40:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145e44:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f145e48:	10000031 */ 	b	.L0f145f10
/*  f145e4c:	ac580004 */ 	sw	$t8,0x4($v0)
.L0f145e50:
/*  f145e50:	14610026 */ 	bne	$v1,$at,.L0f145eec
/*  f145e54:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145e58:	44934000 */ 	mtc1	$s3,$f8
/*  f145e5c:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145e60:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f145e64:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145e68:	06610005 */ 	bgez	$s3,.L0f145e80
/*  f145e6c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f145e70:	3c014f80 */ 	lui	$at,0x4f80
/*  f145e74:	44815000 */ 	mtc1	$at,$f10
/*  f145e78:	00000000 */ 	nop
/*  f145e7c:	460a0000 */ 	add.s	$f0,$f0,$f10
.L0f145e80:
/*  f145e80:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f145e84:	3c014180 */ 	lui	$at,0x4180
/*  f145e88:	44813000 */ 	mtc1	$at,$f6
/*  f145e8c:	3c014200 */ 	lui	$at,0x4200
/*  f145e90:	44815000 */ 	mtc1	$at,$f10
/*  f145e94:	3c014020 */ 	lui	$at,0x4020
/*  f145e98:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f145e9c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f145ea0:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f145ea4:	44194000 */ 	mfc1	$t9,$f8
/*  f145ea8:	44814000 */ 	mtc1	$at,$f8
/*  f145eac:	0019c600 */ 	sll	$t8,$t9,0x18
/*  f145eb0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f145eb4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145eb8:	440e2000 */ 	mfc1	$t6,$f4
/*  f145ebc:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f145ec0:	31d900ff */ 	andi	$t9,$t6,0xff
/*  f145ec4:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f145ec8:	030f7025 */ 	or	$t6,$t8,$t7
/*  f145ecc:	44183000 */ 	mfc1	$t8,$f6
/*  f145ed0:	00000000 */ 	nop
/*  f145ed4:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f145ed8:	000fca00 */ 	sll	$t9,$t7,0x8
/*  f145edc:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145ee0:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145ee4:	1000000a */ 	b	.L0f145f10
/*  f145ee8:	ac4f0004 */ 	sw	$t7,0x4($v0)
.L0f145eec:
/*  f145eec:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f145ef0:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f145ef4:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f145ef8:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145efc:	032ec025 */ 	or	$t8,$t9,$t6
/*  f145f00:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145f04:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f145f08:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145f0c:	ac490000 */ 	sw	$t1,0x0($v0)
.L0f145f10:
/*  f145f10:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f145f14:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f145f18:	57200042 */ 	bnezl	$t9,.L0f146024
/*  f145f1c:	8ec40284 */ 	lw	$a0,0x284($s6)
/*  f145f20:	00ee0019 */ 	multu	$a3,$t6
/*  f145f24:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f145f28:	0000c012 */ 	mflo	$t8
/*  f145f2c:	030f1821 */ 	addu	$v1,$t8,$t7
/*  f145f30:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f145f34:	1880001d */ 	blez	$a0,.L0f145fac
/*  f145f38:	00191b80 */ 	sll	$v1,$t9,0xe
/*  f145f3c:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f145f40:	3c01f600 */ 	lui	$at,0xf600
/*  f145f44:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145f48:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145f4c:	460e2203 */ 	div.s	$f8,$f4,$f14
/*  f145f50:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f145f54:	44185000 */ 	mfc1	$t8,$f10
/*  f145f58:	00000000 */ 	nop
/*  f145f5c:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f145f60:	032e0019 */ 	multu	$t9,$t6
/*  f145f64:	0000c012 */ 	mflo	$t8
/*  f145f68:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f145f6c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f145f70:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145f74:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145f78:	03017825 */ 	or	$t7,$t8,$at
/*  f145f7c:	272e0018 */ 	addiu	$t6,$t9,0x18
/*  f145f80:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f145f84:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f145f88:	01f97025 */ 	or	$t6,$t7,$t9
/*  f145f8c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f145f90:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f145f94:	270f0016 */ 	addiu	$t7,$t8,0x16
/*  f145f98:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f145f9c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f145fa0:	006ec025 */ 	or	$t8,$v1,$t6
/*  f145fa4:	1000001e */ 	b	.L0f146020
/*  f145fa8:	ac580004 */ 	sw	$t8,0x4($v0)
.L0f145fac:
/*  f145fac:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f145fb0:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145fb4:	3c01f600 */ 	lui	$at,0xf600
/*  f145fb8:	00617825 */ 	or	$t7,$v1,$at
/*  f145fbc:	272e0018 */ 	addiu	$t6,$t9,0x18
/*  f145fc0:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f145fc4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f145fc8:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f145fcc:	01f97025 */ 	or	$t6,$t7,$t9
/*  f145fd0:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145fd4:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f145fd8:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f145fdc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145fe0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f145fe4:	440f4000 */ 	mfc1	$t7,$f8
/*  f145fe8:	00000000 */ 	nop
/*  f145fec:	01e7c821 */ 	addu	$t9,$t7,$a3
/*  f145ff0:	032e0019 */ 	multu	$t9,$t6
/*  f145ff4:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f145ff8:	0000c012 */ 	mflo	$t8
/*  f145ffc:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f146000:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f146004:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f146008:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f14600c:	25f90016 */ 	addiu	$t9,$t7,0x16
/*  f146010:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f146014:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f146018:	030fc825 */ 	or	$t9,$t8,$t7
/*  f14601c:	ac590004 */ 	sw	$t9,0x4($v0)
.L0f146020:
/*  f146020:	8ec40284 */ 	lw	$a0,0x284($s6)
.L0f146024:
/*  f146024:	8fb802a8 */ 	lw	$t8,0x2a8($sp)
/*  f146028:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14602c:	8c8e0480 */ 	lw	$t6,0x480($a0)
/*  f146030:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f146034:	1460015b */ 	bnez	$v1,.L0f1465a4
/*  f146038:	00000000 */ 	nop
/*  f14603c:	1700030a */ 	bnez	$t8,.L0f146c68
/*  f146040:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f146044:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146048:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f14604c:	3c01420c */ 	lui	$at,0x420c
/*  f146050:	44816000 */ 	mtc1	$at,$f12
/*  f146054:	44193000 */ 	mfc1	$t9,$f6
/*  f146058:	25d8fff3 */ 	addiu	$t8,$t6,-13
/*  f14605c:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f146060:	afb902ec */ 	sw	$t9,0x2ec($sp)
/*  f146064:	8c8f0480 */ 	lw	$t7,0x480($a0)
/*  f146068:	3c0143b4 */ 	lui	$at,0x43b4
/*  f14606c:	44817000 */ 	mtc1	$at,$f14
/*  f146070:	c5e0001c */ 	lwc1	$f0,0x1c($t7)
/*  f146074:	3c06f600 */ 	lui	$a2,0xf600
/*  f146078:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14607c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146080:	00000000 */ 	nop
/*  f146084:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146088:	460e2203 */ 	div.s	$f8,$f4,$f14
/*  f14608c:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f146090:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146094:	44025000 */ 	mfc1	$v0,$f10
/*  f146098:	00000000 */ 	nop
/*  f14609c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1460a0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1460a4:	44184000 */ 	mfc1	$t8,$f8
/*  f1460a8:	04410005 */ 	bgez	$v0,.L0f1460c0
/*  f1460ac:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f1460b0:	00029823 */ 	negu	$s3,$v0
/*  f1460b4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1460b8:	10000001 */ 	b	.L0f1460c0
/*  f1460bc:	01e09825 */ 	or	$s3,$t7,$zero
.L0f1460c0:
/*  f1460c0:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1460c4:	00197400 */ 	sll	$t6,$t9,0x10
/*  f1460c8:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f1460cc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1460d0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1460d4:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f1460d8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1460dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1460e0:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f1460e4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1460e8:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f1460ec:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f1460f0:	03067825 */ 	or	$t7,$t8,$a2
/*  f1460f4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1460f8:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f1460fc:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f146100:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146104:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146108:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14610c:	3c013f00 */ 	lui	$at,0x3f00
/*  f146110:	44811000 */ 	mtc1	$at,$f2
/*  f146114:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f146118:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f14611c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f146120:	00197080 */ 	sll	$t6,$t9,0x2
/*  f146124:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f146128:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f14612c:	032e7825 */ 	or	$t7,$t9,$t6
/*  f146130:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146134:	8fa502ac */ 	lw	$a1,0x2ac($sp)
/*  f146138:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f14613c:	3c013f80 */ 	lui	$at,0x3f80
/*  f146140:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f146144:	03002825 */ 	or	$a1,$t8,$zero
/*  f146148:	03387021 */ 	addu	$t6,$t9,$t8
/*  f14614c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146150:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f146154:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f146158:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f14615c:	44819000 */ 	mtc1	$at,$f18
/*  f146160:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146164:	c72a0020 */ 	lwc1	$f10,0x20($t9)
/*  f146168:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14616c:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f146170:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f146174:	00000000 */ 	nop
/*  f146178:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f14617c:	00000000 */ 	nop
/*  f146180:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f146184:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146188:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f14618c:	44024000 */ 	mfc1	$v0,$f8
/*  f146190:	00000000 */ 	nop
/*  f146194:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146198:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f14619c:	44182000 */ 	mfc1	$t8,$f4
/*  f1461a0:	04410005 */ 	bgez	$v0,.L0f1461b8
/*  f1461a4:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f1461a8:	00029823 */ 	negu	$s3,$v0
/*  f1461ac:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1461b0:	10000001 */ 	b	.L0f1461b8
/*  f1461b4:	03209825 */ 	or	$s3,$t9,$zero
.L0f1461b8:
/*  f1461b8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1461bc:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f1461c0:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1461c4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1461c8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1461cc:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1461d0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1461d4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1461d8:	02997021 */ 	addu	$t6,$s4,$t9
/*  f1461dc:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1461e0:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1461e4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1461e8:	0306c825 */ 	or	$t9,$t8,$a2
/*  f1461ec:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1461f0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1461f4:	03387025 */ 	or	$t6,$t9,$t8
/*  f1461f8:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1461fc:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f146200:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f146204:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146208:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14620c:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f146210:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146214:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146218:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14621c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146220:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146224:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f146228:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f14622c:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146230:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146234:	03057021 */ 	addu	$t6,$t8,$a1
/*  f146238:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f14623c:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f146240:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f146244:	c7080024 */ 	lwc1	$f8,0x24($t8)
/*  f146248:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f14624c:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f146250:	00000000 */ 	nop
/*  f146254:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f146258:	00000000 */ 	nop
/*  f14625c:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f146260:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146264:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f146268:	44022000 */ 	mfc1	$v0,$f4
/*  f14626c:	00000000 */ 	nop
/*  f146270:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146274:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146278:	44193000 */ 	mfc1	$t9,$f6
/*  f14627c:	04410005 */ 	bgez	$v0,.L0f146294
/*  f146280:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f146284:	00029823 */ 	negu	$s3,$v0
/*  f146288:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14628c:	10000001 */ 	b	.L0f146294
/*  f146290:	03009825 */ 	or	$s3,$t8,$zero
.L0f146294:
/*  f146294:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146298:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f14629c:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f1462a0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1462a4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1462a8:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f1462ac:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1462b0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1462b4:	02987021 */ 	addu	$t6,$s4,$t8
/*  f1462b8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1462bc:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1462c0:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f1462c4:	0326c025 */ 	or	$t8,$t9,$a2
/*  f1462c8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1462cc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1462d0:	03197025 */ 	or	$t6,$t8,$t9
/*  f1462d4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1462d8:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f1462dc:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1462e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1462e4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1462e8:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f1462ec:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f1462f0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1462f4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1462f8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1462fc:	00197380 */ 	sll	$t6,$t9,0xe
/*  f146300:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f146304:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146308:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f14630c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146310:	03257021 */ 	addu	$t6,$t9,$a1
/*  f146314:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f146318:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f14631c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f146320:	c7200028 */ 	lwc1	$f0,0x28($t9)
/*  f146324:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146328:	00000000 */ 	nop
/*  f14632c:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146330:	460e2203 */ 	div.s	$f8,$f4,$f14
/*  f146334:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f146338:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f14633c:	44025000 */ 	mfc1	$v0,$f10
/*  f146340:	00000000 */ 	nop
/*  f146344:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146348:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f14634c:	44184000 */ 	mfc1	$t8,$f8
/*  f146350:	04410005 */ 	bgez	$v0,.L0f146368
/*  f146354:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f146358:	00029823 */ 	negu	$s3,$v0
/*  f14635c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146360:	10000001 */ 	b	.L0f146368
/*  f146364:	03209825 */ 	or	$s3,$t9,$zero
.L0f146368:
/*  f146368:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f14636c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f146370:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f146374:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146378:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14637c:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146380:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146384:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146388:	02997021 */ 	addu	$t6,$s4,$t9
/*  f14638c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f146390:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f146394:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f146398:	0306c825 */ 	or	$t9,$t8,$a2
/*  f14639c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1463a0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1463a4:	03387025 */ 	or	$t6,$t9,$t8
/*  f1463a8:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1463ac:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f1463b0:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1463b4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1463b8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1463bc:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f1463c0:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1463c4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1463c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1463cc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1463d0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1463d4:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f1463d8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1463dc:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f1463e0:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1463e4:	03057021 */ 	addu	$t6,$t8,$a1
/*  f1463e8:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f1463ec:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1463f0:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f1463f4:	c70a002c */ 	lwc1	$f10,0x2c($t8)
/*  f1463f8:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f1463fc:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f146400:	00000000 */ 	nop
/*  f146404:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f146408:	00000000 */ 	nop
/*  f14640c:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f146410:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146414:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f146418:	44024000 */ 	mfc1	$v0,$f8
/*  f14641c:	00000000 */ 	nop
/*  f146420:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146424:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146428:	44192000 */ 	mfc1	$t9,$f4
/*  f14642c:	04410005 */ 	bgez	$v0,.L0f146444
/*  f146430:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f146434:	00029823 */ 	negu	$s3,$v0
/*  f146438:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14643c:	10000001 */ 	b	.L0f146444
/*  f146440:	03009825 */ 	or	$s3,$t8,$zero
.L0f146444:
/*  f146444:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146448:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f14644c:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f146450:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146454:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146458:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f14645c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146460:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146464:	02987021 */ 	addu	$t6,$s4,$t8
/*  f146468:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14646c:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f146470:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f146474:	0326c025 */ 	or	$t8,$t9,$a2
/*  f146478:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14647c:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f146480:	03197025 */ 	or	$t6,$t8,$t9
/*  f146484:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146488:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f14648c:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f146490:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146494:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f146498:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f14649c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1464a0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1464a4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1464a8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1464ac:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f1464b0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1464b4:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1464b8:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1464bc:	03257021 */ 	addu	$t6,$t9,$a1
/*  f1464c0:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f1464c4:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1464c8:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1464cc:	c7280030 */ 	lwc1	$f8,0x30($t9)
/*  f1464d0:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f1464d4:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1464d8:	00000000 */ 	nop
/*  f1464dc:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f1464e0:	00000000 */ 	nop
/*  f1464e4:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1464e8:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1464ec:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1464f0:	44022000 */ 	mfc1	$v0,$f4
/*  f1464f4:	00000000 */ 	nop
/*  f1464f8:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1464fc:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146500:	44183000 */ 	mfc1	$t8,$f6
/*  f146504:	04410005 */ 	bgez	$v0,.L0f14651c
/*  f146508:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f14650c:	00029823 */ 	negu	$s3,$v0
/*  f146510:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146514:	10000001 */ 	b	.L0f14651c
/*  f146518:	03209825 */ 	or	$s3,$t9,$zero
.L0f14651c:
/*  f14651c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146520:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f146524:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146528:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f14652c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f146530:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146534:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146538:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14653c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146540:	02997021 */ 	addu	$t6,$s4,$t9
/*  f146544:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f146548:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14654c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f146550:	0306c825 */ 	or	$t9,$t8,$a2
/*  f146554:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f146558:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f14655c:	03387025 */ 	or	$t6,$t9,$t8
/*  f146560:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f146564:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f146568:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f14656c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146570:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f146574:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146578:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f14657c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f146580:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146584:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146588:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f14658c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146590:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146594:	03057021 */ 	addu	$t6,$t8,$a1
/*  f146598:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f14659c:	100001b2 */ 	b	.L0f146c68
/*  f1465a0:	afaf02ec */ 	sw	$t7,0x2ec($sp)
.L0f1465a4:
/*  f1465a4:	14610170 */ 	bne	$v1,$at,.L0f146b68
/*  f1465a8:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f1465ac:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f1465b0:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f1465b4:	3c06f600 */ 	lui	$a2,0xf600
/*  f1465b8:	172001ab */ 	bnez	$t9,.L0f146c68
/*  f1465bc:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1465c0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1465c4:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f1465c8:	3c01420c */ 	lui	$at,0x420c
/*  f1465cc:	44816000 */ 	mtc1	$at,$f12
/*  f1465d0:	440e4000 */ 	mfc1	$t6,$f8
/*  f1465d4:	25f9fff3 */ 	addiu	$t9,$t7,-13
/*  f1465d8:	afb902e8 */ 	sw	$t9,0x2e8($sp)
/*  f1465dc:	afae02ec */ 	sw	$t6,0x2ec($sp)
/*  f1465e0:	8c980480 */ 	lw	$t8,0x480($a0)
/*  f1465e4:	3c0143b4 */ 	lui	$at,0x43b4
/*  f1465e8:	44817000 */ 	mtc1	$at,$f14
/*  f1465ec:	c700001c */ 	lwc1	$f0,0x1c($t8)
/*  f1465f0:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1465f4:	00000000 */ 	nop
/*  f1465f8:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1465fc:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f146600:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f146604:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146608:	44022000 */ 	mfc1	$v0,$f4
/*  f14660c:	00000000 */ 	nop
/*  f146610:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146614:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146618:	44193000 */ 	mfc1	$t9,$f6
/*  f14661c:	04410005 */ 	bgez	$v0,.L0f146634
/*  f146620:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f146624:	00029823 */ 	negu	$s3,$v0
/*  f146628:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14662c:	10000001 */ 	b	.L0f146634
/*  f146630:	03009825 */ 	or	$s3,$t8,$zero
.L0f146634:
/*  f146634:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f146638:	333800ff */ 	andi	$t8,$t9,0xff
/*  f14663c:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146640:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f146644:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146648:	373800ff */ 	ori	$t8,$t9,0xff
/*  f14664c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146650:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146654:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146658:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14665c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146660:	028f7021 */ 	addu	$t6,$s4,$t7
/*  f146664:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146668:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14666c:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f146670:	03067825 */ 	or	$t7,$t8,$a2
/*  f146674:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146678:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f14667c:	01f87025 */ 	or	$t6,$t7,$t8
/*  f146680:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146684:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146688:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14668c:	3c013f00 */ 	lui	$at,0x3f00
/*  f146690:	44811000 */ 	mtc1	$at,$f2
/*  f146694:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f146698:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f14669c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1466a0:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1466a4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1466a8:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1466ac:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1466b0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1466b4:	8fa502ac */ 	lw	$a1,0x2ac($sp)
/*  f1466b8:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f1466bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1466c0:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f1466c4:	03002825 */ 	or	$a1,$t8,$zero
/*  f1466c8:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f1466cc:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1466d0:	03347821 */ 	addu	$t7,$t9,$s4
/*  f1466d4:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1466d8:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f1466dc:	44819000 */ 	mtc1	$at,$f18
/*  f1466e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1466e4:	c5c40020 */ 	lwc1	$f4,0x20($t6)
/*  f1466e8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1466ec:	3c01f600 */ 	lui	$at,0xf600
/*  f1466f0:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f1466f4:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f1466f8:	00000000 */ 	nop
/*  f1466fc:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f146700:	00000000 */ 	nop
/*  f146704:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f146708:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f14670c:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f146710:	44023000 */ 	mfc1	$v0,$f6
/*  f146714:	00000000 */ 	nop
/*  f146718:	305300ff */ 	andi	$s3,$v0,0xff
/*  f14671c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146720:	44185000 */ 	mfc1	$t8,$f10
/*  f146724:	04410005 */ 	bgez	$v0,.L0f14673c
/*  f146728:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f14672c:	00029823 */ 	negu	$s3,$v0
/*  f146730:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146734:	10000001 */ 	b	.L0f14673c
/*  f146738:	01c09825 */ 	or	$s3,$t6,$zero
.L0f14673c:
/*  f14673c:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146740:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f146744:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146748:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f14674c:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146750:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146754:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146758:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14675c:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146760:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146764:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146768:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f14676c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146770:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146774:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146778:	01c67825 */ 	or	$t7,$t6,$a2
/*  f14677c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146780:	00187080 */ 	sll	$t6,$t8,0x2
/*  f146784:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146788:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f14678c:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146790:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146794:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146798:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14679c:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f1467a0:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f1467a4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1467a8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1467ac:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f1467b0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1467b4:	03387825 */ 	or	$t7,$t9,$t8
/*  f1467b8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1467bc:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f1467c0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1467c4:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f1467c8:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f1467cc:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f1467d0:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f1467d4:	c5c60024 */ 	lwc1	$f6,0x24($t6)
/*  f1467d8:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f1467dc:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f1467e0:	00000000 */ 	nop
/*  f1467e4:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f1467e8:	00000000 */ 	nop
/*  f1467ec:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f1467f0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1467f4:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f1467f8:	44025000 */ 	mfc1	$v0,$f10
/*  f1467fc:	00000000 */ 	nop
/*  f146800:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146804:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146808:	440f4000 */ 	mfc1	$t7,$f8
/*  f14680c:	04410005 */ 	bgez	$v0,.L0f146824
/*  f146810:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f146814:	00029823 */ 	negu	$s3,$v0
/*  f146818:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f14681c:	10000001 */ 	b	.L0f146824
/*  f146820:	01c09825 */ 	or	$s3,$t6,$zero
.L0f146824:
/*  f146824:	00137883 */ 	sra	$t7,$s3,0x2
/*  f146828:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f14682c:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146830:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f146834:	03197825 */ 	or	$t7,$t8,$t9
/*  f146838:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f14683c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146840:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146844:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146848:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14684c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146850:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f146854:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146858:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14685c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146860:	01c6c025 */ 	or	$t8,$t6,$a2
/*  f146864:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146868:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f14686c:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146870:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146874:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f146878:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f14687c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146880:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146884:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f146888:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f14688c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146890:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146894:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146898:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f14689c:	032fc025 */ 	or	$t8,$t9,$t7
/*  f1468a0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1468a4:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f1468a8:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1468ac:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f1468b0:	03347821 */ 	addu	$t7,$t9,$s4
/*  f1468b4:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1468b8:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f1468bc:	c5c00028 */ 	lwc1	$f0,0x28($t6)
/*  f1468c0:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1468c4:	00000000 */ 	nop
/*  f1468c8:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1468cc:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f1468d0:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f1468d4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1468d8:	44022000 */ 	mfc1	$v0,$f4
/*  f1468dc:	00000000 */ 	nop
/*  f1468e0:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1468e4:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1468e8:	44183000 */ 	mfc1	$t8,$f6
/*  f1468ec:	04410005 */ 	bgez	$v0,.L0f146904
/*  f1468f0:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f1468f4:	00029823 */ 	negu	$s3,$v0
/*  f1468f8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1468fc:	10000001 */ 	b	.L0f146904
/*  f146900:	01c09825 */ 	or	$s3,$t6,$zero
.L0f146904:
/*  f146904:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146908:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f14690c:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146910:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f146914:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146918:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f14691c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146920:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146924:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146928:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14692c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146930:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f146934:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146938:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14693c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146940:	01c67825 */ 	or	$t7,$t6,$a2
/*  f146944:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146948:	00187080 */ 	sll	$t6,$t8,0x2
/*  f14694c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146950:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146954:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146958:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f14695c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146960:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146964:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f146968:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f14696c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146970:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f146974:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146978:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f14697c:	03387825 */ 	or	$t7,$t9,$t8
/*  f146980:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146984:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146988:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14698c:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146990:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f146994:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f146998:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f14699c:	c5c4002c */ 	lwc1	$f4,0x2c($t6)
/*  f1469a0:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f1469a4:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f1469a8:	00000000 */ 	nop
/*  f1469ac:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1469b0:	00000000 */ 	nop
/*  f1469b4:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f1469b8:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1469bc:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f1469c0:	44023000 */ 	mfc1	$v0,$f6
/*  f1469c4:	00000000 */ 	nop
/*  f1469c8:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1469cc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1469d0:	440f5000 */ 	mfc1	$t7,$f10
/*  f1469d4:	04410005 */ 	bgez	$v0,.L0f1469ec
/*  f1469d8:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f1469dc:	00029823 */ 	negu	$s3,$v0
/*  f1469e0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1469e4:	10000001 */ 	b	.L0f1469ec
/*  f1469e8:	01c09825 */ 	or	$s3,$t6,$zero
.L0f1469ec:
/*  f1469ec:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1469f0:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f1469f4:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1469f8:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f1469fc:	03197825 */ 	or	$t7,$t8,$t9
/*  f146a00:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f146a04:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146a08:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146a0c:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146a10:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a14:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146a18:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f146a1c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146a20:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146a24:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146a28:	01c1c025 */ 	or	$t8,$t6,$at
/*  f146a2c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146a30:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f146a34:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146a38:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146a3c:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f146a40:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f146a44:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a48:	3c01f600 */ 	lui	$at,0xf600
/*  f146a4c:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f146a50:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146a54:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146a58:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146a5c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146a60:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f146a64:	032fc025 */ 	or	$t8,$t9,$t7
/*  f146a68:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146a6c:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146a70:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146a74:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146a78:	03347821 */ 	addu	$t7,$t9,$s4
/*  f146a7c:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f146a80:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f146a84:	c5c60030 */ 	lwc1	$f6,0x30($t6)
/*  f146a88:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f146a8c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146a90:	00000000 */ 	nop
/*  f146a94:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f146a98:	00000000 */ 	nop
/*  f146a9c:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146aa0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146aa4:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f146aa8:	44025000 */ 	mfc1	$v0,$f10
/*  f146aac:	00000000 */ 	nop
/*  f146ab0:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146ab4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146ab8:	44184000 */ 	mfc1	$t8,$f8
/*  f146abc:	04410005 */ 	bgez	$v0,.L0f146ad4
/*  f146ac0:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f146ac4:	00029823 */ 	negu	$s3,$v0
/*  f146ac8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146acc:	10000001 */ 	b	.L0f146ad4
/*  f146ad0:	01c09825 */ 	or	$s3,$t6,$zero
.L0f146ad4:
/*  f146ad4:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146ad8:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f146adc:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146ae0:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f146ae4:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146ae8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146aec:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146af0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f146af4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146af8:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146afc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b00:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146b04:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f146b08:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146b0c:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146b10:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146b14:	01c17825 */ 	or	$t7,$t6,$at
/*  f146b18:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146b1c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f146b20:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146b24:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f146b28:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146b2c:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146b30:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b34:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f146b38:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146b3c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146b40:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f146b44:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146b48:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f146b4c:	03387825 */ 	or	$t7,$t9,$t8
/*  f146b50:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146b54:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146b58:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146b5c:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f146b60:	10000041 */ 	b	.L0f146c68
/*  f146b64:	afb802ec */ 	sw	$t8,0x2ec($sp)
.L0f146b68:
/*  f146b68:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146b6c:	44813000 */ 	mtc1	$at,$f6
/*  f146b70:	8fa702ac */ 	lw	$a3,0x2ac($sp)
/*  f146b74:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f146b78:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f146b7c:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f146b80:	00077900 */ 	sll	$t7,$a3,0x4
/*  f146b84:	01e77823 */ 	subu	$t7,$t7,$a3
/*  f146b88:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146b8c:	2508fff3 */ 	addiu	$t0,$t0,-13
/*  f146b90:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f146b94:	000f3840 */ 	sll	$a3,$t7,0x1
/*  f146b98:	44034000 */ 	mfc1	$v1,$f8
/*  f146b9c:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146ba0:	13200006 */ 	beqz	$t9,.L0f146bbc
/*  f146ba4:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146ba8:	2463fff4 */ 	addiu	$v1,$v1,-12
/*  f146bac:	2508fffd */ 	addiu	$t0,$t0,-3
/*  f146bb0:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146bb4:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146bb8:	2407000f */ 	addiu	$a3,$zero,0xf
.L0f146bbc:
/*  f146bbc:	00002025 */ 	or	$a0,$zero,$zero
/*  f146bc0:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f146bc4:
/*  f146bc4:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146bc8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146bcc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146bd0:	8f0f0490 */ 	lw	$t7,0x490($t8)
/*  f146bd4:	008f082a */ 	slt	$at,$a0,$t7
/*  f146bd8:	54200003 */ 	bnezl	$at,.L0f146be8
/*  f146bdc:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f146be0:	24050088 */ 	addiu	$a1,$zero,0x88
/*  f146be4:	30ae00ff */ 	andi	$t6,$a1,0xff
.L0f146be8:
/*  f146be8:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f146bec:	032bc025 */ 	or	$t8,$t9,$t3
/*  f146bf0:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f146bf4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f146bf8:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146bfc:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146c00:	3c01f600 */ 	lui	$at,0xf600
/*  f146c04:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146c08:	01c7c821 */ 	addu	$t9,$t6,$a3
/*  f146c0c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146c10:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146c14:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f146c18:	01e17025 */ 	or	$t6,$t7,$at
/*  f146c1c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146c20:	00187880 */ 	sll	$t7,$t8,0x2
/*  f146c24:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f146c28:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f146c2c:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146c30:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146c34:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f146c38:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146c3c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f146c40:	2738fffc */ 	addiu	$t8,$t9,-4
/*  f146c44:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146c48:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146c4c:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146c50:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146c54:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f146c58:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c5c:	25cffffb */ 	addiu	$t7,$t6,-5
/*  f146c60:	1486ffd8 */ 	bne	$a0,$a2,.L0f146bc4
/*  f146c64:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
.L0f146c68:
/*  f146c68:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146c6c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c70:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146c74:	3c19e700 */ 	lui	$t9,0xe700
/*  f146c78:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f146c7c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f146c80:	3c18ba00 */ 	lui	$t8,0xba00
/*  f146c84:	37180602 */ 	ori	$t8,$t8,0x602
/*  f146c88:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c8c:	240e0040 */ 	addiu	$t6,$zero,0x40
/*  f146c90:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146c94:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146c98:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f146c9c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f146ca0:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f146ca4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146ca8:	3c190008 */ 	lui	$t9,0x8
/*  f146cac:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146cb0:	02a02825 */ 	or	$a1,$s5,$zero
/*  f146cb4:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146cb8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f146cbc:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f146cc0:	3c0e0001 */ 	lui	$t6,0x1
/*  f146cc4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f146cc8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f146ccc:	8ecf0298 */ 	lw	$t7,0x298($s6)
/*  f146cd0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146cd4:	05e1017b */ 	bgez	$t7,.L0f1472c4
/*  f146cd8:	00000000 */ 	nop
/*  f146cdc:	8ed9029c */ 	lw	$t9,0x29c($s6)
/*  f146ce0:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f146ce4:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f146ce8:	07210176 */ 	bgez	$t9,.L0f1472c4
/*  f146cec:	8fa202f8 */ 	lw	$v0,0x2f8($sp)
/*  f146cf0:	030e7823 */ 	subu	$t7,$t8,$t6
/*  f146cf4:	25f9ff99 */ 	addiu	$t9,$t7,-103
/*  f146cf8:	44995000 */ 	mtc1	$t9,$f10
/*  f146cfc:	3c014188 */ 	lui	$at,0x4188
/*  f146d00:	44810000 */ 	mtc1	$at,$f0
/*  f146d04:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f146d08:	3c013f80 */ 	lui	$at,0x3f80
/*  f146d0c:	44814000 */ 	mtc1	$at,$f8
/*  f146d10:	3c0141c8 */ 	lui	$at,0x41c8
/*  f146d14:	240f0011 */ 	addiu	$t7,$zero,0x11
/*  f146d18:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f146d1c:	46003103 */ 	div.s	$f4,$f6,$f0
/*  f146d20:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146d24:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f146d28:	c7a402c0 */ 	lwc1	$f4,0x2c0($sp)
/*  f146d2c:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f146d30:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146d34:	44815000 */ 	mtc1	$at,$f10
/*  f146d38:	44033000 */ 	mfc1	$v1,$f6
/*  f146d3c:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f146d40:	0060a025 */ 	or	$s4,$v1,$zero
/*  f146d44:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146d48:	44052000 */ 	mfc1	$a1,$f4
/*  f146d4c:	00000000 */ 	nop
/*  f146d50:	28a10012 */ 	slti	$at,$a1,0x12
/*  f146d54:	54200003 */ 	bnezl	$at,.L0f146d64
/*  f146d58:	240100dc */ 	addiu	$at,$zero,0xdc
/*  f146d5c:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f146d60:	240100dc */ 	addiu	$at,$zero,0xdc
.L0f146d64:
/*  f146d64:	14410003 */ 	bne	$v0,$at,.L0f146d74
/*  f146d68:	01e52823 */ 	subu	$a1,$t7,$a1
/*  f146d6c:	10000008 */ 	b	.L0f146d90
/*  f146d70:	a3b900c7 */ 	sb	$t9,0xc7($sp)
.L0f146d74:
/*  f146d74:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f146d78:	14410004 */ 	bne	$v0,$at,.L0f146d8c
/*  f146d7c:	2418fff8 */ 	addiu	$t8,$zero,-8
/*  f146d80:	2474ffff */ 	addiu	$s4,$v1,-1
/*  f146d84:	10000002 */ 	b	.L0f146d90
/*  f146d88:	a3b800c7 */ 	sb	$t8,0xc7($sp)
.L0f146d8c:
/*  f146d8c:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.L0f146d90:
/*  f146d90:	0fc351e7 */ 	jal	func0f0d479c
/*  f146d94:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f146d98:	3c0eb600 */ 	lui	$t6,0xb600
/*  f146d9c:	240f3000 */ 	addiu	$t7,$zero,0x3000
/*  f146da0:	3c19b700 */ 	lui	$t9,0xb700
/*  f146da4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f146da8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f146dac:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f146db0:	3c0efcff */ 	lui	$t6,0xfcff
/*  f146db4:	3c0ffffe */ 	lui	$t7,0xfffe
/*  f146db8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f146dbc:	35ef793c */ 	ori	$t7,$t7,0x793c
/*  f146dc0:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f146dc4:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f146dc8:	24180204 */ 	addiu	$t8,$zero,0x204
/*  f146dcc:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f146dd0:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f146dd4:	ac590018 */ 	sw	$t9,0x18($v0)
/*  f146dd8:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f146ddc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f146de0:	3c190050 */ 	lui	$t9,0x50
/*  f146de4:	3c0fb900 */ 	lui	$t7,0xb900
/*  f146de8:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f146dec:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f146df0:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f146df4:	373941c8 */ 	ori	$t9,$t9,0x41c8
/*  f146df8:	ac58001c */ 	sw	$t8,0x1c($v0)
/*  f146dfc:	ac4e0020 */ 	sw	$t6,0x20($v0)
/*  f146e00:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f146e04:	ac59002c */ 	sw	$t9,0x2c($v0)
/*  f146e08:	ac4f0028 */ 	sw	$t7,0x28($v0)
/*  f146e0c:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f146e10:	8faf02f8 */ 	lw	$t7,0x2f8($sp)
/*  f146e14:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f146e18:	270e003a */ 	addiu	$t6,$t8,0x3a
/*  f146e1c:	24550030 */ 	addiu	$s5,$v0,0x30
/*  f146e20:	15e10003 */ 	bne	$t7,$at,.L0f146e30
/*  f146e24:	afae02e8 */ 	sw	$t6,0x2e8($sp)
/*  f146e28:	25c80005 */ 	addiu	$t0,$t6,0x5
/*  f146e2c:	afa802e8 */ 	sw	$t0,0x2e8($sp)
.L0f146e30:
/*  f146e30:	8fb902f8 */ 	lw	$t9,0x2f8($sp)
/*  f146e34:	3c013f00 */ 	lui	$at,0x3f00
/*  f146e38:	44813000 */ 	mtc1	$at,$f6
/*  f146e3c:	44994000 */ 	mtc1	$t9,$f8
/*  f146e40:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f146e44:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f146e48:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f146e4c:	00009025 */ 	or	$s2,$zero,$zero
/*  f146e50:	27380022 */ 	addiu	$t8,$t9,0x22
/*  f146e54:	afb8007c */ 	sw	$t8,0x7c($sp)
/*  f146e58:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f146e5c:	44813000 */ 	mtc1	$at,$f6
/*  f146e60:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f146e64:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146e68:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f146e6c:	440f4000 */ 	mfc1	$t7,$f8
/*  f146e70:	00000000 */ 	nop
/*  f146e74:	01ef0019 */ 	multu	$t7,$t7
/*  f146e78:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f146e7c:	01e88823 */ 	subu	$s1,$t7,$t0
/*  f146e80:	83af00c7 */ 	lb	$t7,0xc7($sp)
/*  f146e84:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f146e88:	e7a40070 */ 	swc1	$f4,0x70($sp)
/*  f146e8c:	022f8023 */ 	subu	$s0,$s1,$t7
/*  f146e90:	00007012 */ 	mflo	$t6
/*  f146e94:	afae0080 */ 	sw	$t6,0x80($sp)
/*  f146e98:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f146e9c:	448e4000 */ 	mtc1	$t6,$f8
/*  f146ea0:	00000000 */ 	nop
/*  f146ea4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f146ea8:	e7aa006c */ 	swc1	$f10,0x6c($sp)
.L0f146eac:
/*  f146eac:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f146eb0:	24130050 */ 	addiu	$s3,$zero,0x50
/*  f146eb4:	24020056 */ 	addiu	$v0,$zero,0x56
/*  f146eb8:	0244082a */ 	slt	$at,$s2,$a0
/*  f146ebc:	10200003 */ 	beqz	$at,.L0f146ecc
/*  f146ec0:	00000000 */ 	nop
/*  f146ec4:	10000001 */ 	b	.L0f146ecc
/*  f146ec8:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f146ecc:
/*  f146ecc:	0244082a */ 	slt	$at,$s2,$a0
/*  f146ed0:	10200003 */ 	beqz	$at,.L0f146ee0
/*  f146ed4:	00000000 */ 	nop
/*  f146ed8:	10000001 */ 	b	.L0f146ee0
/*  f146edc:	24020022 */ 	addiu	$v0,$zero,0x22
.L0f146ee0:
/*  f146ee0:	02100019 */ 	multu	$s0,$s0
/*  f146ee4:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f146ee8:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*  f146eec:	0114c821 */ 	addu	$t9,$t0,$s4
/*  f146ef0:	afa80228 */ 	sw	$t0,0x228($sp)
/*  f146ef4:	afb90230 */ 	sw	$t9,0x230($sp)
/*  f146ef8:	a3a200d3 */ 	sb	$v0,0xd3($sp)
/*  f146efc:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146f00:	afa30224 */ 	sw	$v1,0x224($sp)
/*  f146f04:	afa3022c */ 	sw	$v1,0x22c($sp)
/*  f146f08:	00007812 */ 	mflo	$t7
/*  f146f0c:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f146f10:	448e3000 */ 	mtc1	$t6,$f6
/*  f146f14:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146f18:	0c012974 */ 	jal	sqrtf
/*  f146f1c:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f146f20:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f146f24:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f146f28:	83af00c7 */ 	lb	$t7,0xc7($sp)
/*  f146f2c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f146f30:	02348823 */ 	subu	$s1,$s1,$s4
/*  f146f34:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146f38:	022f8023 */ 	subu	$s0,$s1,$t7
/*  f146f3c:	02100019 */ 	multu	$s0,$s0
/*  f146f40:	44814000 */ 	mtc1	$at,$f8
/*  f146f44:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f146f48:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f146f4c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f146f50:	0114c021 */ 	addu	$t8,$t0,$s4
/*  f146f54:	afb80238 */ 	sw	$t8,0x238($sp)
/*  f146f58:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f146f5c:	0000c812 */ 	mflo	$t9
/*  f146f60:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f146f64:	01d9c023 */ 	subu	$t8,$t6,$t9
/*  f146f68:	44983000 */ 	mtc1	$t8,$f6
/*  f146f6c:	44035000 */ 	mfc1	$v1,$f10
/*  f146f70:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f146f74:	afa3023c */ 	sw	$v1,0x23c($sp)
/*  f146f78:	0c012974 */ 	jal	sqrtf
/*  f146f7c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146f80:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f146f84:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f146f88:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146f8c:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f146f90:	44812000 */ 	mtc1	$at,$f4
/*  f146f94:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146f98:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146f9c:	93a200d3 */ 	lbu	$v0,0xd3($sp)
/*  f146fa0:	afb90240 */ 	sw	$t9,0x240($sp)
/*  f146fa4:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f146fa8:	460a4181 */ 	sub.s	$f6,$f8,$f10
/*  f146fac:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f146fb0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146fb4:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f146fb8:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f146fbc:	00003025 */ 	or	$a2,$zero,$zero
/*  f146fc0:	326700ff */ 	andi	$a3,$s3,0xff
/*  f146fc4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f146fc8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146fcc:	440e5000 */ 	mfc1	$t6,$f10
/*  f146fd0:	00000000 */ 	nop
/*  f146fd4:	afae02ec */ 	sw	$t6,0x2ec($sp)
/*  f146fd8:	afae0234 */ 	sw	$t6,0x234($sp)
/*  f146fdc:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f146fe0:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f146fe4:	14600006 */ 	bnez	$v1,.L0f147000
/*  f146fe8:	00000000 */ 	nop
/*  f146fec:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f146ff0:	0fc50d9e */ 	jal	hudRenderEyespySideBar
/*  f146ff4:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f146ff8:	10000017 */ 	b	.L0f147058
/*  f146ffc:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147000:
/*  f147000:	1461000c */ 	bne	$v1,$at,.L0f147034
/*  f147004:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147008:	00137080 */ 	sll	$t6,$s3,0x2
/*  f14700c:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f147010:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f147014:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147018:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f14701c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f147020:	326700ff */ 	andi	$a3,$s3,0xff
/*  f147024:	0fc50d9e */ 	jal	hudRenderEyespySideBar
/*  f147028:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14702c:	1000000a */ 	b	.L0f147058
/*  f147030:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147034:
/*  f147034:	00133883 */ 	sra	$a3,$s3,0x2
/*  f147038:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f14703c:	03203825 */ 	or	$a3,$t9,$zero
/*  f147040:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f147044:	326600ff */ 	andi	$a2,$s3,0xff
/*  f147048:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f14704c:	0fc50d9e */ 	jal	hudRenderEyespySideBar
/*  f147050:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147054:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147058:
/*  f147058:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f14705c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f147060:	2a410011 */ 	slti	$at,$s2,0x11
/*  f147064:	01144021 */ 	addu	$t0,$t0,$s4
/*  f147068:	1420ff90 */ 	bnez	$at,.L0f146eac
/*  f14706c:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f147070:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147074:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f147078:	3c014188 */ 	lui	$at,0x4188
/*  f14707c:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f147080:	44812000 */ 	mtc1	$at,$f4
/*  f147084:	3c017f1b */ 	lui	$at,%hi(var7f1b5f58)
/*  f147088:	c5e60060 */ 	lwc1	$f6,0x60($t7)
/*  f14708c:	c42a5f58 */ 	lwc1	$f10,%lo(var7f1b5f58)($at)
/*  f147090:	24190011 */ 	addiu	$t9,$zero,0x11
/*  f147094:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f147098:	8fa80300 */ 	lw	$t0,0x300($sp)
/*  f14709c:	8fb802f8 */ 	lw	$t8,0x2f8($sp)
/*  f1470a0:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1470a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1470a8:	83ae00c7 */ 	lb	$t6,0xc7($sp)
/*  f1470ac:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f1470b0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1470b4:	44042000 */ 	mfc1	$a0,$f4
/*  f1470b8:	00000000 */ 	nop
/*  f1470bc:	28810012 */ 	slti	$at,$a0,0x12
/*  f1470c0:	54200003 */ 	bnezl	$at,.L0f1470d0
/*  f1470c4:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f1470c8:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f1470cc:	240100b4 */ 	addiu	$at,$zero,0xb4
.L0f1470d0:
/*  f1470d0:	03242023 */ 	subu	$a0,$t9,$a0
/*  f1470d4:	17010002 */ 	bne	$t8,$at,.L0f1470e0
/*  f1470d8:	2508002e */ 	addiu	$t0,$t0,0x2e
/*  f1470dc:	25080005 */ 	addiu	$t0,$t0,0x5
.L0f1470e0:
/*  f1470e0:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f1470e4:	01e88823 */ 	subu	$s1,$t7,$t0
/*  f1470e8:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f1470ec:	2738ffde */ 	addiu	$t8,$t9,-34
/*  f1470f0:	afb8007c */ 	sw	$t8,0x7c($sp)
/*  f1470f4:	022e8023 */ 	subu	$s0,$s1,$t6
/*  f1470f8:	afa400c0 */ 	sw	$a0,0xc0($sp)
.L0f1470fc:
/*  f1470fc:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f147100:	24130050 */ 	addiu	$s3,$zero,0x50
/*  f147104:	24020056 */ 	addiu	$v0,$zero,0x56
/*  f147108:	0244082a */ 	slt	$at,$s2,$a0
/*  f14710c:	10200003 */ 	beqz	$at,.L0f14711c
/*  f147110:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*  f147114:	10000001 */ 	b	.L0f14711c
/*  f147118:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14711c:
/*  f14711c:	0244082a */ 	slt	$at,$s2,$a0
/*  f147120:	10200003 */ 	beqz	$at,.L0f147130
/*  f147124:	00000000 */ 	nop
/*  f147128:	10000001 */ 	b	.L0f147130
/*  f14712c:	24020022 */ 	addiu	$v0,$zero,0x22
.L0f147130:
/*  f147130:	02100019 */ 	multu	$s0,$s0
/*  f147134:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f147138:	01147821 */ 	addu	$t7,$t0,$s4
/*  f14713c:	afa30224 */ 	sw	$v1,0x224($sp)
/*  f147140:	afa80228 */ 	sw	$t0,0x228($sp)
/*  f147144:	afaf0230 */ 	sw	$t7,0x230($sp)
/*  f147148:	afa3022c */ 	sw	$v1,0x22c($sp)
/*  f14714c:	a3a200d3 */ 	sb	$v0,0xd3($sp)
/*  f147150:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f147154:	afa400c0 */ 	sw	$a0,0xc0($sp)
/*  f147158:	0000c812 */ 	mflo	$t9
/*  f14715c:	01d9c023 */ 	subu	$t8,$t6,$t9
/*  f147160:	44984000 */ 	mtc1	$t8,$f8
/*  f147164:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f147168:	0c012974 */ 	jal	sqrtf
/*  f14716c:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f147170:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f147174:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f147178:	83b900c7 */ 	lb	$t9,0xc7($sp)
/*  f14717c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f147180:	02348823 */ 	subu	$s1,$s1,$s4
/*  f147184:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147188:	02398023 */ 	subu	$s0,$s1,$t9
/*  f14718c:	02100019 */ 	multu	$s0,$s0
/*  f147190:	44815000 */ 	mtc1	$at,$f10
/*  f147194:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f147198:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f14719c:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f1471a0:	01147021 */ 	addu	$t6,$t0,$s4
/*  f1471a4:	afae0238 */ 	sw	$t6,0x238($sp)
/*  f1471a8:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f1471ac:	00007812 */ 	mflo	$t7
/*  f1471b0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1471b4:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f1471b8:	448e4000 */ 	mtc1	$t6,$f8
/*  f1471bc:	44032000 */ 	mfc1	$v1,$f4
/*  f1471c0:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f1471c4:	afa3023c */ 	sw	$v1,0x23c($sp)
/*  f1471c8:	0c012974 */ 	jal	sqrtf
/*  f1471cc:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f1471d0:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f1471d4:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f1471d8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1471dc:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f1471e0:	44815000 */ 	mtc1	$at,$f10
/*  f1471e4:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1471e8:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1471ec:	93a200d3 */ 	lbu	$v0,0xd3($sp)
/*  f1471f0:	afaf0240 */ 	sw	$t7,0x240($sp)
/*  f1471f4:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f1471f8:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f1471fc:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f147200:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147204:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f147208:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f14720c:	00003025 */ 	or	$a2,$zero,$zero
/*  f147210:	326700ff */ 	andi	$a3,$s3,0xff
/*  f147214:	24010001 */ 	addiu	$at,$zero,0x1
/*  f147218:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f14721c:	44182000 */ 	mfc1	$t8,$f4
/*  f147220:	00000000 */ 	nop
/*  f147224:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f147228:	afb80234 */ 	sw	$t8,0x234($sp)
/*  f14722c:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f147230:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f147234:	14600006 */ 	bnez	$v1,.L0f147250
/*  f147238:	00000000 */ 	nop
/*  f14723c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147240:	0fc50d9e */ 	jal	hudRenderEyespySideBar
/*  f147244:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147248:	10000017 */ 	b	.L0f1472a8
/*  f14724c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147250:
/*  f147250:	1461000c */ 	bne	$v1,$at,.L0f147284
/*  f147254:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147258:	0013c080 */ 	sll	$t8,$s3,0x2
/*  f14725c:	0313c023 */ 	subu	$t8,$t8,$s3
/*  f147260:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f147264:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147268:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f14726c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f147270:	326700ff */ 	andi	$a3,$s3,0xff
/*  f147274:	0fc50d9e */ 	jal	hudRenderEyespySideBar
/*  f147278:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14727c:	1000000a */ 	b	.L0f1472a8
/*  f147280:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147284:
/*  f147284:	00133883 */ 	sra	$a3,$s3,0x2
/*  f147288:	30ef00ff */ 	andi	$t7,$a3,0xff
/*  f14728c:	01e03825 */ 	or	$a3,$t7,$zero
/*  f147290:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f147294:	326600ff */ 	andi	$a2,$s3,0xff
/*  f147298:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f14729c:	0fc50d9e */ 	jal	hudRenderEyespySideBar
/*  f1472a0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1472a4:	0040a825 */ 	or	$s5,$v0,$zero
.L0f1472a8:
/*  f1472a8:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f1472ac:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1472b0:	24010011 */ 	addiu	$at,$zero,0x11
/*  f1472b4:	01144021 */ 	addu	$t0,$t0,$s4
/*  f1472b8:	1641ff90 */ 	bne	$s2,$at,.L0f1470fc
/*  f1472bc:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f1472c0:	afa802e8 */ 	sw	$t0,0x2e8($sp)
.L0f1472c4:
/*  f1472c4:	0fc35272 */ 	jal	func0f0d49c8
/*  f1472c8:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1472cc:
/*  f1472cc:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f1472d0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1472d4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1472d8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1472dc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1472e0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1472e4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1472e8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1472ec:	03e00008 */ 	jr	$ra
/*  f1472f0:	27bd0408 */ 	addiu	$sp,$sp,0x408
);

/**
 * Renders the eyespy user interface, excluding the fisheye lens. The lens is
 * drawn first by another function, then this one is called to draw the outer
 * information. Care must be taken not to draw over the top of the fisheye lens.
 *
 * Note that the dimensions of the view can differ based on hi-res on/off, as
 * well as using coop mode in both the vertical and horizontal screen splits.
 * Some elements are omitted if a vertical split is being used, and to handle
 * hi-res a scale variable is used to multiply X values and widths where needed.
 *
 * @bug: Many of the X values and widths are not multiplied by the scale which
 * causes them to display incorrectly when using hi-res:
 * - Some of the horizontal lines don't touch the lens circle.
 * - The vertical lines are thinner and closer to the screen edges than intended.
 * - The speed and height bars are stretched.
 * - The device name and model are closer to the screen edge than intended.
 */
// Mismatch:
// 4420: writes to x2 and y2 are misordered
// Other mismatches are mostly regalloc and swapped instructions which will likely
// resolve themselves once the above is fixed.
//Gfx *hudRenderEyespyUi(Gfx *gdl)
//{
//	char text[256]; // 308
//	s32 viewleft = viGetViewLeft(); // 304
//	s32 viewtop = viGetViewTop(); // 300
//	s32 viewwidth = viGetViewX(); // s1
//	s32 viewheight = viGetViewY(); // 2f8
//	s32 viewright = viewleft + viewwidth - 1;
//	s32 viewbottom = viewtop + viewheight - 1; // 2f0
//	s32 x; // 2ec
//	s32 y; // 2e8
//	s32 textwidth; // 2e4
//	s32 textheight; // 2e0
//	s32 x2; // 2dc
//	s32 y2; // 2d8
//	struct chrdata *chr;
//	s32 savedy;
//	s32 movex;
//	s32 movey;
//	s32 movez;
//	f32 movedist; // 2c0
//	f32 sqmovedist = 0.0f; // 2bc
//	u32 colourtextbright;
//	u32 colourtextdull; // 2b4
//	u32 colourglow; // 2b0
//	s32 scale = viewwidth > 320 ? 2 : 1; // 2ac
//	bool vsplit = false; // 2a8
//
//	// 3914
//	if (g_Vars.currentplayer->eyespy == NULL
//			|| g_Vars.currentplayer->eyespy->prop == NULL
//			|| g_Vars.currentplayer->eyespy->prop->chr == NULL) {
//		return gdl;
//	}
//
//	chr = g_Vars.currentplayer->eyespy->prop->chr;
//
//	// 393c
//	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
//		vsplit = true;
//	}
//
//	// 39cc
//	movex = chr->prop->pos.x - chr->prevpos.x;
//	movey = chr->prop->pos.y - chr->prevpos.y;
//	movez = chr->prop->pos.z - chr->prevpos.z;
//
//	// 3a1c
//	if (movex != 0.0f || movey != 0.0f || movez != 0.0f) {
//		sqmovedist = movex * movex + movey * movey + movez * movez;
//	}
//
//	// 3aa0
//	if (sqmovedist > 0.001f) {
//		movedist = sqrtf(sqmovedist);
//	} else {
//		movedist = 0.0f;
//	}
//
//	// 3abc
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		gdl = gfxSetPrimColour(gdl, 0x00ff0028);
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		gdl = gfxSetPrimColour(gdl, 0x2244ffa0);
//	} else {
//		gdl = gfxSetPrimColour(gdl, 0xff3300a0);
//	}
//
//	// 3b1c
//	if (!vsplit) {
//		// Render borders/lines in background
//		gDPFillRectangle(gdl++, viewleft + 25, viewtop + 55, viewleft + 26, viewbottom - 24);
//		gDPFillRectangle(gdl++, viewleft + 31, viewtop + 55, viewleft + 32, viewbottom - 42);
//		gDPFillRectangle(gdl++, viewleft + 25, viewbottom - 25, viewleft + 25 + viewwidth / 5.0f + 1, viewbottom - 24);
//		gDPFillRectangle(gdl++, viewleft + 31, viewbottom - 43, viewleft + 25 + viewwidth / 7.0f + 1, viewbottom - 42);
//		gDPFillRectangle(gdl++, viewright - 25, viewtop + 25, viewright - 24, viewbottom - 54);
//		gDPFillRectangle(gdl++, viewright - 31, viewtop + 43, viewright - 30, viewbottom - 54);
//		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 5.0f, viewtop + 25, viewright - 24, viewtop + 26);
//		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 7.0f, viewtop + 43, viewright - 30, viewtop + 44);
//		gDPFillRectangle(gdl++, viewleft, viewtop + 55, viewleft + viewwidth / 5.0f + 1, viewtop + 56);
//		gDPFillRectangle(gdl++, viewright - viewwidth / 5.0f, viewbottom - 55, viewright + 1, viewbottom - 54);
//	}
//
//	// 4164
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		// Render crosshair
//		s32 x = viewleft + (viewwidth >> 1);
//		s32 y = viewtop + (viewheight >> 1);
//
//		gDPFillRectangle(gdl++, x + 2, y + 0, x + 7, y + 1);
//		gDPFillRectangle(gdl++, x + 2, y + 0, x + 5, y + 1);
//		gDPFillRectangle(gdl++, x - 6, y + 0, x - 1, y + 1);
//		gDPFillRectangle(gdl++, x - 4, y + 0, x - 1, y + 1);
//		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 7);
//		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 5);
//		gDPFillRectangle(gdl++, x + 0, y - 6, x + 1, y - 1);
//		gDPFillRectangle(gdl++, x + 0, y - 4, x + 1, y - 1);
//	}
//
//	// 4318
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		colourtextbright = 0x00ff00a0;
//		colourtextdull = 0x005000ff;
//		colourglow = 0x000f00ff;
//	} else /*4348*/ if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		colourtextbright = 0x2244ffff;
//		colourtextdull = 0x2244ffff;
//		colourglow = 0x00000fff;
//	} else {
//		// 4368
//		colourtextbright = 0xff3300ff;
//		colourtextdull = 0xff3300ff;
//		colourglow = 0x0f0000ff;
//	}
//
//	// "S/MPS"
//	// 437c
//	sprintf(text, "%s %s%5.2f", langGet(L_MISC(73)), "", movedist * 0.6f);
//	savedy = viewtop + 14;
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//	x = viewleft + 25 * scale;
//	y = savedy;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextbright, colourglow, viGetX(), viGetY(), 0, 0);
//
//	// "H/M"
//	// 44b4
//	sprintf(text, "%s %s%4.2f", langGet(L_MISC(74)), "", g_Vars.currentplayer->eyespy->height * 0.01f);
//	savedy += 9;
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//	x = viewleft + 25 * scale;
//	y = savedy;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextbright, colourglow, viGetX(), viGetY(), 0, 0);
//
//	// "Y/D"
//	// 45c8
//	sprintf(text, "%s %d", langGet(L_MISC(75)), (s32)g_Vars.currentplayer->eyespy->theta);
//	savedy += 9;
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//	y = savedy;
//	x = viewleft + 25 * scale;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextbright, colourglow, viGetX(), viGetY(), 0, 0);
//
//	// "P/D"
//	// 46cc
//	sprintf(text, "%s %d", langGet(L_MISC(76)), (s32)g_Vars.currentplayer->eyespy->verta);
//	savedy += 9;
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//	y = savedy;
//	x = viewleft + 25 * scale;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextbright, colourglow, viGetX(), viGetY(), 0, 0);
//
//	// "CI 2023"
//	// 47d0
//	sprintf(text, "%s", langGet(L_MISC(77)));
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//
//	x = (vsplit ? -3 : 0) + viewleft + 25 * scale + 5;
//	y = (vsplit ? 18 : 0) + viewbottom - 41;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextdull, colourglow, viGetX(), viGetY(), 0, 0);
//
//	// 48f8
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		sprintf(text, "%s", langGet(L_MISC(78))); // "YKK: 95935"
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		sprintf(text, "%s", langGet(L_MISC(208))); // "JM: 201172"
//	} else {
//		sprintf(text, "%s", langGet(L_MISC(217))); // "BNC: 15877"
//	}
//
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//
//	// 49a8
//	x = (vsplit ? -3 : 0) + viewleft + 25 * scale + 5;
//	y = (vsplit ? 20 : 0) + viewbottom - 34;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextdull, colourglow, viGetX(), viGetY(), 0, 0);
//
//	// 4a8c
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		// "CAMSPY"
//		sprintf(text, "   %s", langGet(L_MISC(79)));
//		textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//
//		x = viewright - scale * 53 - 25;
//		y = (vsplit ? -13 : 0) + viewtop + 27;
//		x2 = x + textwidth;
//		y2 = y + textheight;
//		gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//		gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//				colourtextdull, colourglow, viGetX(), viGetY(), 0, 0);
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		// "DRUGSPY"
//		// 4be4
//		sprintf(text, "   %s", langGet(L_MISC(468)));
//		textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//
//		x = viewright - scale * 53 - 25;
//		y = (vsplit ? -13 : 0) + viewtop + 27;
//		x2 = x + textwidth;
//		y2 = y + textheight;
//		gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//		gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//				colourtextdull, colourglow, viGetX(), viGetY(), 0, 0);
//	} else {
//		// "BOMBSPY"
//		// 4d18
//		sprintf(text, "   %s", langGet(L_MISC(469)));
//		textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//
//		x = viewright - scale * 59 - 25;
//		y = (vsplit ? -13 : 0) + viewtop + 27;
//		x2 = x + textwidth;
//		y2 = y + textheight;
//		gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//		gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//				colourtextdull, colourglow, viGetX(), viGetY(), 0, 0);
//	}
//
//	// 4e3c
//	// Model number
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		sprintf(text, "%s", langGet(L_MISC(80))); // "MODEL 1.2"
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		sprintf(text, "%s", langGet(L_MISC(207))); // "MODEL 1.4"
//	} else {
//		sprintf(text, "%s", langGet(L_MISC(216))); // "MODEL 1.3"
//	}
//
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//	x = (vsplit ? 3 : 0) + viewright - scale * 46 - 25;
//	y = (vsplit ? -11 : 0) + viewtop + 34;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextdull, colourglow, viGetX(), viGetY(), 0, 0);
//
//	// 4fe4
//	// Gyrostat/dartammo text
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY
//			|| g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
//		sprintf(text, "%s", langGet(L_MISC(81))); // "GYROSTAT"
//	} else {
//		sprintf(text, "%s", langGet(L_MISC(206))); // "DARTAMMO"
//	}
//
//	textMeasure(&textheight, &textwidth, text, var8007fb08, var8007fb04, 0);
//	x = (vsplit ? -35 : 0) + (viewright - viewwidth / 5.0f - 3 - (scale * 5 - 5));
//	y = (vsplit ? -2 : 0) + viewbottom - 12;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, var8007fb08, var8007fb04,
//			colourtextdull, colourglow, viGetX(), viGetY(), 0, 0);
//
//	gdl = func0f153838(gdl);
//
//	// 5190
//	{
//		s8 contpadnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
//		u16 buttonsdown = contGetButtons(contpadnum, 0xffff);
//		u16 buttonsthisframe = contGetButtonsPressedThisFrame(contpadnum, 0xffff);
//		s8 cstickx = contGetStickX(contpadnum); // 251
//		s8 csticky = contGetStickY(contpadnum);
//		s32 xpos;
//		s32 tmpval;
//		u8 brightness;
//		u8 brightness2;
//		s32 points[8]; // 224
//		s32 r;
//		s32 g;
//		s32 b;
//
//		// 5200
//		gDPPipeSync(gdl++);
//		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//		gDPSetColorDither(gdl++, G_CD_DISABLE);
//		gDPSetTexturePersp(gdl++, G_TP_NONE);
//		gDPSetAlphaCompare(gdl++, G_AC_NONE);
//		gDPSetTextureLOD(gdl++, G_TL_TILE);
//		gDPSetTextureFilter(gdl++, G_TF_BILERP);
//		gDPSetTextureConvert(gdl++, G_TC_FILT);
//		gDPSetTextureLUT(gdl++, G_TT_NONE);
//		gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
//		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
//
//		// 5328
//		if (!vsplit) {
//			// 5330
//			xpos = (scale == 2 ? -76 : -85);
//
//			// Up
//			// 5364
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 53b4
//				brightness = 127;
//
//				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				brightness = 20;
//
//				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5464
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Down
//
//			// 5504
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 555c
//				brightness = 127;
//
//				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 55ac
//				brightness = 20;
//
//				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 55ec
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Left
//
//			// 5648
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 56a0
//				brightness = 127;
//
//				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 56e8
//				brightness = 20;
//
//				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5730
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Right
//
//			// 5790
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 57e8
//				brightness = 127;
//
//				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 5838
//				brightness = 20;
//
//				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5878
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Shoulder buttons
//
//			// 58d8
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 5930
//				brightness = 127;
//
//				if (buttonsdown & (L_TRIG | R_TRIG)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 5978
//				brightness = 20;
//
//				if (buttonsdown & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 59c0
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Z button
//
//			// 5a10
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & Z_TRIG) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & Z_TRIG) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 5a68
//				brightness = 127;
//
//				if (buttonsdown & Z_TRIG) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & Z_TRIG) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 5ab8
//				brightness = 20;
//
//				if (buttonsdown & Z_TRIG) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & Z_TRIG) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5af8
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//		}
//
//		// 5b28
//		xpos = (scale == 2 ? -48 : -55);
//
//		tmpval = cstickx * 96.0f / 80.0f;
//		brightness = tmpval < 0 ? -tmpval : tmpval;
//
//		// 5bb0
//		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//		} else /*5bcc*/ if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//			r = brightness / 96.0f * 16.0f;
//			g = brightness / 96.0f * 32.0f;
//			b = brightness * 2.5f;
//			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
//		} else {
//			// 5c68
//			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//		}
//
//		// 5c8c
//		if (!vsplit) {
//			tmpval = cstickx * 28.0f / 80.0f;
//
//			if (cstickx > 0) {
//				gDPFillRectangle(gdl++,
//						xpos * scale + viewright,
//						viewtop + 19,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 21);
//			} else {
//				// 5d40
//				gDPFillRectangle(gdl++,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 19,
//						xpos * scale + viewright,
//						viewtop + 21);
//			}
//		}
//
//		// 5dd4
//		tmpval = csticky * 96.0f / 80.0f;
//		brightness = tmpval < 0 ? -tmpval : tmpval;
//
//		// 5e38
//		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//			r = brightness / 96.0f * 16.0f;
//			g = brightness / 96.0f * 32.0f;
//			b = brightness * 2.5f;
//			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
//		} else {
//			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//		}
//
//		// 5f10
//		if (!vsplit) {
//			tmpval = csticky * 28.0f / 80.0f;
//
//			if (csticky > 0) {
//				gDPFillRectangle(gdl++,
//						xpos * scale + viewright,
//						viewtop + 22,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 24);
//			} else {
//				gDPFillRectangle(gdl++,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 22,
//						xpos * scale + viewright,
//						viewtop + 24);
//			}
//		}
//
//		// 6020
//		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//			if (!vsplit) {
//				// Camspy gyrobar 1
//				x = viewright - viewwidth / 5.0f;
//				y = viewbottom - 13;
//
//				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 2
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 3
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 4
//				x += scale * 2 + scale * 5;
//
//				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 5
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 6
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				x += scale * 2 + scale * 5;
//			}
//		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
//			// 65ac
//			if (!vsplit) {
//				// Bombspy gyrobar 1
//				x = viewright - viewwidth / 5.0f;
//				y = viewbottom - 13;
//
//				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 2
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 3
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 4
//				x += scale * 2 + scale * 5;
//
//				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 5
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 6
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				x += scale * 2 + scale * 5;
//			}
//		} else {
//			// 6b68
//			// Drugspy ammo
//			s32 i;
//			s32 width;
//			x = viewright - viewwidth / 5.0f + 5;
//			y = viewbottom - 13;
//
//			brightness2 = 0xff;
//			width = scale * 30;
//
//			if (vsplit) {
//				x -= 12;
//				y -= 3;
//				width = 15;
//			}
//
//			for (i = 0; i < 8; i++) {
//				if (i >= g_Vars.currentplayer->eyespydarts) {
//					brightness2 = 0x88;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness2, 0xff);
//				gDPFillRectangle(gdl++, x, y - 4, x + width, y);
//
//				y -= 5;
//			}
//		}
//
//		// 6c68
//		gDPPipeSync(gdl++);
//		gDPSetColorDither(gdl++, G_CD_BAYER);
//		gDPSetTexturePersp(gdl++, G_TP_PERSP);
//		gDPSetTextureLOD(gdl++, G_TL_LOD);
//
//		// 6cd4
//		if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
//			s32 barheight = (viewbottom - viewtop - 103) / 17.0f - 1;
//			s32 centrey;
//			s32 sqcentrey;
//			s32 ypos;
//			u8 alpha; // d3
//			u32 stack;
//			u32 stack2;
//			s8 yoffset; // c7
//			s32 value = 17.0f * movedist / 25.0f; // c0
//			s32 i;
//
//			if (value > 17) {
//				value = 17;
//			}
//
//			value = 17 - value;
//
//			if (viewheight == 220) {
//				yoffset = 10;
//			} else if (viewheight == 180) {
//				barheight--;
//				yoffset = -8;
//			} else {
//				yoffset = 0;
//			}
//
//			// 6d90
//			gdl = func0f0d479c(gdl);
//
//			gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//			gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
//			gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
//			gDPSetTextureFilter(gdl++, G_TF_BILERP);
//			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//			gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//
//			// Speed bars (left side)
//			y = viewtop + 58;
//
//			if (viewheight == 180) {
//				y += 5;
//			}
//
//			centrey = viewheight * .5f;
//			ypos = centrey - y + 10;
//			sqcentrey = centrey * centrey;
//
//			for (i = 0; i < 17; i++) {
//				// 6eac
//				brightness = i < value ? 0x28 : 0x50;
//				alpha = i < value ? 0x22 : 0x56;
//
//				points[0] = x = viewleft + 34;
//				points[1] = y;
//				points[2] = x = viewleft + 34;
//				points[3] = y + barheight;
//
//				// 6f18
//				points[6] = x = viewwidth * .5f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
//				points[5] = y + barheight;
//
//				ypos -= barheight;
//
//				// 6f78
//				points[4] = x = viewwidth * .5f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
//				points[7] = y;
//
//				ypos -= 2;
//
//				// 6fec
//				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//					gdl = hudRenderEyespySideBar(gdl, points, 0, brightness, 0, alpha);
//				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//					// 7014
//					gdl = hudRenderEyespySideBar(gdl, points, 0x10, brightness, brightness * 3, alpha);
//				} else {
//					// 7080
//					gdl = hudRenderEyespySideBar(gdl, points, brightness, brightness >> 2, 0, alpha);
//				}
//
//				y += barheight;
//				y += 2;
//			}
//
//			// Height bars (right side)
//			value = g_Vars.currentplayer->eyespy->height * 17.0f * 0.00625f;
//
//			if (value > 17) {
//				value = 17;
//			}
//
//			value = 17 - value;
//
//			y = viewtop + 46;
//
//			if (viewheight == 180) {
//				y += 5;
//			}
//
//			ypos = centrey - y + 10;
//
//			for (i = 0; i < 17; i++) {
//				// 70fc
//				brightness = i < value ? 0x28 : 0x50;
//				alpha = i < value ? 0x22 : 0x56;
//
//				points[0] = x = viewright - 34;
//				points[1] = y;
//				points[3] = y + barheight;
//				points[2] = x = viewright - 34;
//
//				// 7168
//				points[6] = x = viewwidth * .5f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
//				points[5] = y + barheight;
//
//				ypos -= barheight;
//
//				// 71c8
//				points[4] = x = viewwidth * .5f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
//				points[7] = y;
//
//				ypos -= 2;
//
//				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//					// 7240
//					gdl = hudRenderEyespySideBar(gdl, points, 0, brightness, 0, alpha);
//				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//					gdl = hudRenderEyespySideBar(gdl, points, 0x10, brightness, brightness * 3, alpha);
//				} else {
//					gdl = hudRenderEyespySideBar(gdl, points, brightness, brightness >> 2, 0, alpha);
//				}
//
//				y += barheight;
//				y += 2;
//			}
//		}
//
//		// 72c4
//		gdl = func0f0d49c8(gdl);
//	}
//
//	return gdl;
//}

void func0f1572f8(void)
{
	// empty
}

const char var7f1b5e50[] = "Fullscreen_DrawFaultScope";
const char var7f1b5e6c[] = "Fullscreen_DrawFaultScope";
const char var7f1b5e88[] = "IntroFaderBlurGfx";

GLOBAL_ASM(
glabel func0f1472fc
/*  f1472fc:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f147300:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f147304:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f147308:	00808825 */ 	or	$s1,$a0,$zero
/*  f14730c:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f147310:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f147314:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f147318:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f14731c:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f147320:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f147324:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f147328:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f14732c:	0c002ac7 */ 	jal	viGetUnk28
/*  f147330:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f147334:	0c002f26 */ 	jal	viGetViewY
/*  f147338:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f14733c:	0c002f22 */ 	jal	viGetViewX
/*  f147340:	00408025 */ 	or	$s0,$v0,$zero
/*  f147344:	0c002f44 */ 	jal	viGetViewTop
/*  f147348:	0040b025 */ 	or	$s6,$v0,$zero
/*  f14734c:	0c002f40 */ 	jal	viGetViewLeft
/*  f147350:	00409825 */ 	or	$s3,$v0,$zero
/*  f147354:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f147358:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f14735c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f147360:	0270a021 */ 	addu	$s4,$s3,$s0
/*  f147364:	0040b825 */ 	or	$s7,$v0,$zero
/*  f147368:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f14736c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f147370:	0280f025 */ 	or	$s8,$s4,$zero
/*  f147374:	14200003 */ 	bnez	$at,.L0f147384
/*  f147378:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f14737c:	1000006f */ 	b	.L0f14753c
/*  f147380:	02201025 */ 	or	$v0,$s1,$zero
.L0f147384:
/*  f147384:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f147388:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e50)
/*  f14738c:	24a55e50 */ 	addiu	$a1,$a1,%lo(var7f1b5e50)
/*  f147390:	0c004c4c */ 	jal	strcpy
/*  f147394:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f147398:	241900bc */ 	addiu	$t9,$zero,0xbc
/*  f14739c:	3c01800a */ 	lui	$at,%hi(var8009caec)
/*  f1473a0:	a039caec */ 	sb	$t9,%lo(var8009caec)($at)
/*  f1473a4:	3c01800a */ 	lui	$at,%hi(var8009caec+0x3)
/*  f1473a8:	240800be */ 	addiu	$t0,$zero,0xbe
/*  f1473ac:	a028caef */ 	sb	$t0,%lo(var8009caec+0x3)($at)
/*  f1473b0:	3c01800a */ 	lui	$at,%hi(var8009caf0)
/*  f1473b4:	240900de */ 	addiu	$t1,$zero,0xde
/*  f1473b8:	a029caf0 */ 	sb	$t1,%lo(var8009caf0)($at)
/*  f1473bc:	3c01800a */ 	lui	$at,%hi(var8009caec+0x1)
/*  f1473c0:	240a0050 */ 	addiu	$t2,$zero,0x50
/*  f1473c4:	a02acaed */ 	sb	$t2,%lo(var8009caec+0x1)($at)
/*  f1473c8:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f1473cc:	3c01800a */ 	lui	$at,%hi(var8009caec+0x2)
/*  f1473d0:	240b00c0 */ 	addiu	$t3,$zero,0xc0
/*  f1473d4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f1473d8:	a02bcaee */ 	sb	$t3,%lo(var8009caec+0x2)($at)
/*  f1473dc:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f1473e0:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f1473e4:	0fc00270 */ 	jal	func0f0009c0
/*  f1473e8:	85a40028 */ 	lh	$a0,0x28($t5)
/*  f1473ec:	28410081 */ 	slti	$at,$v0,0x81
/*  f1473f0:	14200004 */ 	bnez	$at,.L0f147404
/*  f1473f4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1473f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1473fc:	0fc49ccd */ 	jal	func0f127334
/*  f147400:	00403025 */ 	or	$a2,$v0,$zero
.L0f147404:
/*  f147404:	8e0e0288 */ 	lw	$t6,0x288($s0)
/*  f147408:	3c19800a */ 	lui	$t9,%hi(g_Menus+0x4f8)
/*  f14740c:	02202025 */ 	or	$a0,$s1,$zero
/*  f147410:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f147414:	3c0500ff */ 	lui	$a1,0xff
/*  f147418:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f14741c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f147420:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f147424:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f147428:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f14742c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f147430:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f147434:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f147438:	8f39e4f8 */ 	lw	$t9,%lo(g_Menus+0x4f8)($t9)
/*  f14743c:	57200005 */ 	bnezl	$t9,.L0f147454
/*  f147440:	02201025 */ 	or	$v0,$s1,$zero
/*  f147444:	0fc5090e */ 	jal	hudRenderMotionBlur
/*  f147448:	24060060 */ 	addiu	$a2,$zero,0x60
/*  f14744c:	00408825 */ 	or	$s1,$v0,$zero
/*  f147450:	02201025 */ 	or	$v0,$s1,$zero
.L0f147454:
/*  f147454:	3c08e700 */ 	lui	$t0,0xe700
/*  f147458:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f14745c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f147460:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f147464:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f147468:	0fc5082c */ 	jal	func0f1420b0
/*  f14746c:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f147470:	3c128008 */ 	lui	$s2,%hi(var8007f878)
/*  f147474:	2652f878 */ 	addiu	$s2,$s2,%lo(var8007f878)
/*  f147478:	92490000 */ 	lbu	$t1,0x0($s2)
/*  f14747c:	0274082a */ 	slt	$at,$s3,$s4
/*  f147480:	00408825 */ 	or	$s1,$v0,$zero
/*  f147484:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f147488:	a24a0000 */ 	sb	$t2,0x0($s2)
/*  f14748c:	1020002a */ 	beqz	$at,.L0f147538
/*  f147490:	02608025 */ 	or	$s0,$s3,$zero
/*  f147494:	3c013f80 */ 	lui	$at,0x3f80
/*  f147498:	4481a000 */ 	mtc1	$at,$f20
/*  f14749c:	3c15fb00 */ 	lui	$s5,0xfb00
/*  f1474a0:	2414000c */ 	addiu	$s4,$zero,0xc
/*  f1474a4:	241300ff */ 	addiu	$s3,$zero,0xff
.L0f1474a8:
/*  f1474a8:	924c0000 */ 	lbu	$t4,0x0($s2)
/*  f1474ac:	320b0001 */ 	andi	$t3,$s0,0x1
/*  f1474b0:	24030094 */ 	addiu	$v1,$zero,0x94
/*  f1474b4:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f1474b8:	116d000e */ 	beq	$t3,$t5,.L0f1474f4
/*  f1474bc:	00000000 */ 	nop
/*  f1474c0:	0c004b70 */ 	jal	random
/*  f1474c4:	00000000 */ 	nop
/*  f1474c8:	0054001b */ 	divu	$zero,$v0,$s4
/*  f1474cc:	00007810 */ 	mfhi	$t7
/*  f1474d0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1474d4:	02781823 */ 	subu	$v1,$s3,$t8
/*  f1474d8:	307900ff */ 	andi	$t9,$v1,0xff
/*  f1474dc:	16800002 */ 	bnez	$s4,.L0f1474e8
/*  f1474e0:	00000000 */ 	nop
/*  f1474e4:	0007000d */ 	break	0x7
.L0f1474e8:
/*  f1474e8:	03201825 */ 	or	$v1,$t9,$zero
/*  f1474ec:	10000002 */ 	b	.L0f1474f8
/*  f1474f0:	02201025 */ 	or	$v0,$s1,$zero
.L0f1474f4:
/*  f1474f4:	02201025 */ 	or	$v0,$s1,$zero
.L0f1474f8:
/*  f1474f8:	00034400 */ 	sll	$t0,$v1,0x10
/*  f1474fc:	250900ff */ 	addiu	$t1,$t0,0xff
/*  f147500:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f147504:	ac550000 */ 	sw	$s5,0x0($v0)
/*  f147508:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f14750c:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f147510:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f147514:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f147518:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f14751c:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f147520:	02003025 */ 	or	$a2,$s0,$zero
/*  f147524:	0fc506ac */ 	jal	func0f141ab0
/*  f147528:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f14752c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f147530:	161effdd */ 	bne	$s0,$s8,.L0f1474a8
/*  f147534:	00408825 */ 	or	$s1,$v0,$zero
.L0f147538:
/*  f147538:	02201025 */ 	or	$v0,$s1,$zero
.L0f14753c:
/*  f14753c:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f147540:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f147544:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f147548:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f14754c:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f147550:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f147554:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f147558:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f14755c:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f147560:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f147564:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f147568:	03e00008 */ 	jr	$ra
/*  f14756c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

Gfx *func0f147570(Gfx *gdl)
{
	return gdl;
}

GLOBAL_ASM(
glabel func0f147578
/*  f147578:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f14757c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f147580:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f147584:	0080a025 */ 	or	$s4,$a0,$zero
/*  f147588:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f14758c:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f147590:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f147594:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f147598:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f14759c:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1475a0:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1475a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1475a8:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f1475ac:	0c002ac7 */ 	jal	viGetUnk28
/*  f1475b0:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f1475b4:	0c002f26 */ 	jal	viGetViewY
/*  f1475b8:	0040f025 */ 	or	$s8,$v0,$zero
/*  f1475bc:	0c002f22 */ 	jal	viGetViewX
/*  f1475c0:	00409825 */ 	or	$s3,$v0,$zero
/*  f1475c4:	0c002f44 */ 	jal	viGetViewTop
/*  f1475c8:	afa200dc */ 	sw	$v0,0xdc($sp)
/*  f1475cc:	0c002f40 */ 	jal	viGetViewLeft
/*  f1475d0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1475d4:	3c038008 */ 	lui	$v1,%hi(var8007f84c)
/*  f1475d8:	8c63f84c */ 	lw	$v1,%lo(var8007f84c)($v1)
/*  f1475dc:	3c0a8008 */ 	lui	$t2,%hi(var8007f850)
/*  f1475e0:	8d4af850 */ 	lw	$t2,%lo(var8007f850)($t2)
/*  f1475e4:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f1475e8:	3c048008 */ 	lui	$a0,%hi(var8007f840)
/*  f1475ec:	006a001a */ 	div	$zero,$v1,$t2
/*  f1475f0:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f1475f4:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1475f8:	2484f840 */ 	addiu	$a0,$a0,%lo(var8007f840)
/*  f1475fc:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f147600:	0000a812 */ 	mflo	$s5
/*  f147604:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f147608:	07010003 */ 	bgez	$t8,.L0f147618
/*  f14760c:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f147610:	27010001 */ 	addiu	$at,$t8,0x1
/*  f147614:	0001c843 */ 	sra	$t9,$at,0x1
.L0f147618:
/*  f147618:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f14761c:	afb900c8 */ 	sw	$t9,0xc8($sp)
/*  f147620:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f147624:	01806825 */ 	or	$t5,$t4,$zero
/*  f147628:	00609025 */ 	or	$s2,$v1,$zero
/*  f14762c:	15400002 */ 	bnez	$t2,.L0f147638
/*  f147630:	00000000 */ 	nop
/*  f147634:	0007000d */ 	break	0x7
.L0f147638:
/*  f147638:	2401ffff */ 	addiu	$at,$zero,-1
/*  f14763c:	15410004 */ 	bne	$t2,$at,.L0f147650
/*  f147640:	3c018000 */ 	lui	$at,0x8000
/*  f147644:	14610002 */ 	bne	$v1,$at,.L0f147650
/*  f147648:	00000000 */ 	nop
/*  f14764c:	0006000d */ 	break	0x6
.L0f147650:
/*  f147650:	29810002 */ 	slti	$at,$t4,0x2
/*  f147654:	14200003 */ 	bnez	$at,.L0f147664
/*  f147658:	00000000 */ 	nop
/*  f14765c:	10000119 */ 	b	.L0f147ac4
/*  f147660:	02801025 */ 	or	$v0,$s4,$zero
.L0f147664:
/*  f147664:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f147668:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e6c)
/*  f14766c:	24a55e6c */ 	addiu	$a1,$a1,%lo(var7f1b5e6c)
/*  f147670:	0c004c4c */ 	jal	strcpy
/*  f147674:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f147678:	02131821 */ 	addu	$v1,$s0,$s3
/*  f14767c:	02033821 */ 	addu	$a3,$s0,$v1
/*  f147680:	04e10003 */ 	bgez	$a3,.L0f147690
/*  f147684:	00077043 */ 	sra	$t6,$a3,0x1
/*  f147688:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f14768c:	00017043 */ 	sra	$t6,$at,0x1
.L0f147690:
/*  f147690:	01d28823 */ 	subu	$s1,$t6,$s2
/*  f147694:	01d22821 */ 	addu	$a1,$t6,$s2
/*  f147698:	0071082a */ 	slt	$at,$v1,$s1
/*  f14769c:	01c03825 */ 	or	$a3,$t6,$zero
/*  f1476a0:	10200002 */ 	beqz	$at,.L0f1476ac
/*  f1476a4:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1476a8:	00608825 */ 	or	$s1,$v1,$zero
.L0f1476ac:
/*  f1476ac:	0065082a */ 	slt	$at,$v1,$a1
/*  f1476b0:	50200003 */ 	beqzl	$at,.L0f1476c0
/*  f1476b4:	0230082a */ 	slt	$at,$s1,$s0
/*  f1476b8:	00603025 */ 	or	$a2,$v1,$zero
/*  f1476bc:	0230082a */ 	slt	$at,$s1,$s0
.L0f1476c0:
/*  f1476c0:	10200002 */ 	beqz	$at,.L0f1476cc
/*  f1476c4:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f1476c8:	02008825 */ 	or	$s1,$s0,$zero
.L0f1476cc:
/*  f1476cc:	00d0082a */ 	slt	$at,$a2,$s0
/*  f1476d0:	10200002 */ 	beqz	$at,.L0f1476dc
/*  f1476d4:	240401e0 */ 	addiu	$a0,$zero,0x1e0
/*  f1476d8:	02003025 */ 	or	$a2,$s0,$zero
.L0f1476dc:
/*  f1476dc:	44932000 */ 	mtc1	$s3,$f4
/*  f1476e0:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f1476e4:	448f3000 */ 	mtc1	$t7,$f6
/*  f1476e8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1476ec:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f1476f0:	44992000 */ 	mtc1	$t9,$f4
/*  f1476f4:	3c014370 */ 	lui	$at,0x4370
/*  f1476f8:	44811000 */ 	mtc1	$at,$f2
/*  f1476fc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f147700:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f147704:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f147708:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f14770c:	00008025 */ 	or	$s0,$zero,$zero
/*  f147710:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f147714:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f147718:	00c04825 */ 	or	$t1,$a2,$zero
/*  f14771c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f147720:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f147724:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f147728:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f14772c:	44059000 */ 	mfc1	$a1,$f18
/*  f147730:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f147734:	440b8000 */ 	mfc1	$t3,$f16
/*  f147738:	00000000 */ 	nop
/*  f14773c:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f147740:	846c1c60 */ 	lh	$t4,0x1c60($v1)
/*  f147744:	524c0010 */ 	beql	$s2,$t4,.L0f147788
/*  f147748:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f14774c:	8ecd028c */ 	lw	$t5,0x28c($s6)
/*  f147750:	3c0f800a */ 	lui	$t7,%hi(var800a41d8)
/*  f147754:	25ef41d8 */ 	addiu	$t7,$t7,%lo(var800a41d8)
/*  f147758:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f14775c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f147760:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f147764:	01cf1021 */ 	addu	$v0,$t6,$t7
.L0f147768:
/*  f147768:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14776c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f147770:	1604fffd */ 	bne	$s0,$a0,.L0f147768
/*  f147774:	a048ffff */ 	sb	$t0,-0x1($v0)
/*  f147778:	a4601c62 */ 	sh	$zero,0x1c62($v1)
/*  f14777c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147780:	a7121c60 */ 	sh	$s2,0x1c60($t8)
/*  f147784:	240800ff */ 	addiu	$t0,$zero,0xff
.L0f147788:
/*  f147788:	00008025 */ 	or	$s0,$zero,$zero
/*  f14778c:	afa600ac */ 	sw	$a2,0xac($sp)
/*  f147790:	18a0001b */ 	blez	$a1,.L0f147800
/*  f147794:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f147798:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f14779c:	3c07800a */ 	lui	$a3,%hi(var800a41d8)
/*  f1477a0:	24e741d8 */ 	addiu	$a3,$a3,%lo(var800a41d8)
/*  f1477a4:	afa600ac */ 	sw	$a2,0xac($sp)
/*  f1477a8:	240400ff */ 	addiu	$a0,$zero,0xff
.L0f1477ac:
/*  f1477ac:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f1477b0:	84621c62 */ 	lh	$v0,0x1c62($v1)
/*  f1477b4:	0049082a */ 	slt	$at,$v0,$t1
/*  f1477b8:	54200005 */ 	bnezl	$at,.L0f1477d0
/*  f1477bc:	8eca028c */ 	lw	$t2,0x28c($s6)
/*  f1477c0:	a4711c62 */ 	sh	$s1,0x1c62($v1)
/*  f1477c4:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f1477c8:	84621c62 */ 	lh	$v0,0x1c62($v1)
/*  f1477cc:	8eca028c */ 	lw	$t2,0x28c($s6)
.L0f1477d0:
/*  f1477d0:	0090c823 */ 	subu	$t9,$a0,$s0
/*  f1477d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1477d8:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f1477dc:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f1477e0:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f1477e4:	00eb6021 */ 	addu	$t4,$a3,$t3
/*  f1477e8:	01826821 */ 	addu	$t5,$t4,$v0
/*  f1477ec:	a1b90000 */ 	sb	$t9,0x0($t5)
/*  f1477f0:	846e1c62 */ 	lh	$t6,0x1c62($v1)
/*  f1477f4:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1477f8:	1605ffec */ 	bne	$s0,$a1,.L0f1477ac
/*  f1477fc:	a46f1c62 */ 	sh	$t7,0x1c62($v1)
.L0f147800:
/*  f147800:	3c01800a */ 	lui	$at,%hi(var8009caec)
/*  f147804:	a028caec */ 	sb	$t0,%lo(var8009caec)($at)
/*  f147808:	240300de */ 	addiu	$v1,$zero,0xde
/*  f14780c:	3c01800a */ 	lui	$at,%hi(var8009caec+0x3)
/*  f147810:	a023caef */ 	sb	$v1,%lo(var8009caec+0x3)($at)
/*  f147814:	3c01800a */ 	lui	$at,%hi(var8009caf0)
/*  f147818:	a023caf0 */ 	sb	$v1,%lo(var8009caf0)($at)
/*  f14781c:	02801025 */ 	or	$v0,$s4,$zero
/*  f147820:	3c18e700 */ 	lui	$t8,0xe700
/*  f147824:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f147828:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f14782c:	26840008 */ 	addiu	$a0,$s4,0x8
/*  f147830:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f147834:	0fc5082c */ 	jal	func0f1420b0
/*  f147838:	01003025 */ 	or	$a2,$t0,$zero
/*  f14783c:	8faa00ac */ 	lw	$t2,0xac($sp)
/*  f147840:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147844:	02208025 */ 	or	$s0,$s1,$zero
/*  f147848:	022a082a */ 	slt	$at,$s1,$t2
/*  f14784c:	5020008a */ 	beqzl	$at,.L0f147a78
/*  f147850:	8ecf0288 */ 	lw	$t7,0x288($s6)
/*  f147854:	02b50019 */ 	multu	$s5,$s5
/*  f147858:	8ecb028c */ 	lw	$t3,0x28c($s6)
/*  f14785c:	3c0d800a */ 	lui	$t5,%hi(var800a41d8)
/*  f147860:	3c013f80 */ 	lui	$at,0x3f80
/*  f147864:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f147868:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f14786c:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f147870:	0191c821 */ 	addu	$t9,$t4,$s1
/*  f147874:	25ad41d8 */ 	addiu	$t5,$t5,%lo(var800a41d8)
/*  f147878:	4481b000 */ 	mtc1	$at,$f22
/*  f14787c:	0000b812 */ 	mflo	$s7
/*  f147880:	032d1021 */ 	addu	$v0,$t9,$t5
/*  f147884:	3c15fb00 */ 	lui	$s5,0xfb00
/*  f147888:	320e0001 */ 	andi	$t6,$s0,0x1
.L0f14788c:
/*  f14788c:	51c00004 */ 	beqzl	$t6,.L0f1478a0
/*  f147890:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f147894:	10000008 */ 	b	.L0f1478b8
/*  f147898:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f14789c:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f1478a0:
/*  f1478a0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1478a4:	00037840 */ 	sll	$t7,$v1,0x1
/*  f1478a8:	01e1001a */ 	div	$zero,$t7,$at
/*  f1478ac:	00001812 */ 	mflo	$v1
/*  f1478b0:	00000000 */ 	nop
/*  f1478b4:	00000000 */ 	nop
.L0f1478b8:
/*  f1478b8:	0c004b70 */ 	jal	random
/*  f1478bc:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f1478c0:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f1478c4:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f1478c8:	02801025 */ 	or	$v0,$s4,$zero
/*  f1478cc:	006a1821 */ 	addu	$v1,$v1,$t2
/*  f1478d0:	2c610100 */ 	sltiu	$at,$v1,0x100
/*  f1478d4:	14200002 */ 	bnez	$at,.L0f1478e0
/*  f1478d8:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1478dc:	240300ff */ 	addiu	$v1,$zero,0xff
.L0f1478e0:
/*  f1478e0:	00035e00 */ 	sll	$t3,$v1,0x18
/*  f1478e4:	256c00ff */ 	addiu	$t4,$t3,0xff
/*  f1478e8:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f1478ec:	ac550000 */ 	sw	$s5,0x0($v0)
/*  f1478f0:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f1478f4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1478f8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1478fc:	03302023 */ 	subu	$a0,$t9,$s0
/*  f147900:	00840019 */ 	multu	$a0,$a0
/*  f147904:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f147908:	00006812 */ 	mflo	$t5
/*  f14790c:	01b7082a */ 	slt	$at,$t5,$s7
/*  f147910:	5020003d */ 	beqzl	$at,.L0f147a08
/*  f147914:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f147918:	44849000 */ 	mtc1	$a0,$f18
/*  f14791c:	8faa00dc */ 	lw	$t2,0xdc($sp)
/*  f147920:	3c0143a0 */ 	lui	$at,0x43a0
/*  f147924:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f147928:	448a5000 */ 	mtc1	$t2,$f10
/*  f14792c:	44819000 */ 	mtc1	$at,$f18
/*  f147930:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f147934:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f147938:	46128503 */ 	div.s	$f20,$f16,$f18
/*  f14793c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147940:	440f3000 */ 	mfc1	$t7,$f6
/*  f147944:	00000000 */ 	nop
/*  f147948:	02efc023 */ 	subu	$t8,$s7,$t7
/*  f14794c:	44984000 */ 	mtc1	$t8,$f8
/*  f147950:	0c012974 */ 	jal	sqrtf
/*  f147954:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f147958:	46140102 */ 	mul.s	$f4,$f0,$f20
/*  f14795c:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f147960:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f147964:	8fb900d4 */ 	lw	$t9,0xd4($sp)
/*  f147968:	02802025 */ 	or	$a0,$s4,$zero
/*  f14796c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f147970:	02003025 */ 	or	$a2,$s0,$zero
/*  f147974:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147978:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f14797c:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f147980:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f147984:	44023000 */ 	mfc1	$v0,$f6
/*  f147988:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f14798c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f147990:	01029021 */ 	addu	$s2,$t0,$v0
/*  f147994:	01929823 */ 	subu	$s3,$t4,$s2
/*  f147998:	0fc506ac */ 	jal	func0f141ab0
/*  f14799c:	00408825 */ 	or	$s1,$v0,$zero
/*  f1479a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1479a4:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1479a8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1479ac:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1479b0:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1479b4:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1479b8:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f1479bc:	0fc506ac */ 	jal	func0f141ab0
/*  f1479c0:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f1479c4:	3c0dee00 */ 	lui	$t5,0xee00
/*  f1479c8:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f1479cc:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1479d0:	ac550000 */ 	sw	$s5,0x0($v0)
/*  f1479d4:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*  f1479d8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1479dc:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1479e0:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1479e4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f1479e8:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1479ec:	02003025 */ 	or	$a2,$s0,$zero
/*  f1479f0:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1479f4:	0fc506ac */ 	jal	func0f141ab0
/*  f1479f8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1479fc:	1000000a */ 	b	.L0f147a28
/*  f147a00:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147a04:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.L0f147a08:
/*  f147a08:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f147a0c:	02802025 */ 	or	$a0,$s4,$zero
/*  f147a10:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f147a14:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f147a18:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f147a1c:	0fc506ac */ 	jal	func0f141ab0
/*  f147a20:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f147a24:	0040a025 */ 	or	$s4,$v0,$zero
.L0f147a28:
/*  f147a28:	8eca028c */ 	lw	$t2,0x28c($s6)
/*  f147a2c:	3c19800a */ 	lui	$t9,%hi(var800a41d8)
/*  f147a30:	273941d8 */ 	addiu	$t9,$t9,%lo(var800a41d8)
/*  f147a34:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f147a38:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f147a3c:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f147a40:	01706021 */ 	addu	$t4,$t3,$s0
/*  f147a44:	01991021 */ 	addu	$v0,$t4,$t9
/*  f147a48:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f147a4c:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f147a50:	0083082a */ 	slt	$at,$a0,$v1
/*  f147a54:	10200002 */ 	beqz	$at,.L0f147a60
/*  f147a58:	00646823 */ 	subu	$t5,$v1,$a0
/*  f147a5c:	a04d0000 */ 	sb	$t5,0x0($v0)
.L0f147a60:
/*  f147a60:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f147a64:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f147a68:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f147a6c:	560eff87 */ 	bnel	$s0,$t6,.L0f14788c
/*  f147a70:	320e0001 */ 	andi	$t6,$s0,0x1
/*  f147a74:	8ecf0288 */ 	lw	$t7,0x288($s6)
.L0f147a78:
/*  f147a78:	3c0b800a */ 	lui	$t3,%hi(g_Menus+0x4f8)
/*  f147a7c:	02802025 */ 	or	$a0,$s4,$zero
/*  f147a80:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f147a84:	3c05ff00 */ 	lui	$a1,0xff00
/*  f147a88:	001850c0 */ 	sll	$t2,$t8,0x3
/*  f147a8c:	01585023 */ 	subu	$t2,$t2,$t8
/*  f147a90:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f147a94:	01585021 */ 	addu	$t2,$t2,$t8
/*  f147a98:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f147a9c:	01585023 */ 	subu	$t2,$t2,$t8
/*  f147aa0:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f147aa4:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f147aa8:	8d6be4f8 */ 	lw	$t3,%lo(g_Menus+0x4f8)($t3)
/*  f147aac:	55600005 */ 	bnezl	$t3,.L0f147ac4
/*  f147ab0:	02801025 */ 	or	$v0,$s4,$zero
/*  f147ab4:	0fc5090e */ 	jal	hudRenderMotionBlur
/*  f147ab8:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f147abc:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147ac0:	02801025 */ 	or	$v0,$s4,$zero
.L0f147ac4:
/*  f147ac4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f147ac8:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f147acc:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f147ad0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f147ad4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f147ad8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f147adc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f147ae0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f147ae4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f147ae8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f147aec:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f147af0:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f147af4:	03e00008 */ 	jr	$ra
/*  f147af8:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*  f147afc:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f147b00:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f147b04:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f147b08:	00809025 */ 	or	$s2,$a0,$zero
/*  f147b0c:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f147b10:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f147b14:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f147b18:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f147b1c:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f147b20:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f147b24:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f147b28:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f147b2c:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f147b30:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f147b34:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f147b38:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f147b3c:	0c002ac7 */ 	jal	viGetUnk28
/*  f147b40:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f147b44:	0c002f44 */ 	jal	viGetViewTop
/*  f147b48:	0040b025 */ 	or	$s6,$v0,$zero
/*  f147b4c:	0c002f26 */ 	jal	viGetViewY
/*  f147b50:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f147b54:	0c002f22 */ 	jal	viGetViewX
/*  f147b58:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f147b5c:	0c002f40 */ 	jal	viGetViewLeft
/*  f147b60:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147b64:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f147b68:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f147b6c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f147b70:	0040a825 */ 	or	$s5,$v0,$zero
/*  f147b74:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f147b78:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f147b7c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f147b80:	14200003 */ 	bnez	$at,.L0f147b90
/*  f147b84:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f147b88:	1000004b */ 	b	.L0f147cb8
/*  f147b8c:	02401025 */ 	or	$v0,$s2,$zero
.L0f147b90:
/*  f147b90:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e88)
/*  f147b94:	24a55e88 */ 	addiu	$a1,$a1,%lo(var7f1b5e88)
/*  f147b98:	0c004c4c */ 	jal	strcpy
/*  f147b9c:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f147ba0:	3c19e700 */ 	lui	$t9,0xe700
/*  f147ba4:	ae590000 */ 	sw	$t9,0x0($s2)
/*  f147ba8:	26440008 */ 	addiu	$a0,$s2,0x8
/*  f147bac:	ae400004 */ 	sw	$zero,0x4($s2)
/*  f147bb0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f147bb4:	0fc5082c */ 	jal	func0f1420b0
/*  f147bb8:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f147bbc:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f147bc0:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f147bc4:	00409025 */ 	or	$s2,$v0,$zero
/*  f147bc8:	00608025 */ 	or	$s0,$v1,$zero
/*  f147bcc:	00649821 */ 	addu	$s3,$v1,$a0
/*  f147bd0:	0073082a */ 	slt	$at,$v1,$s3
/*  f147bd4:	10200037 */ 	beqz	$at,.L0f147cb4
/*  f147bd8:	00638823 */ 	subu	$s1,$v1,$v1
/*  f147bdc:	44842000 */ 	mtc1	$a0,$f4
/*  f147be0:	3c013f00 */ 	lui	$at,0x3f00
/*  f147be4:	44814000 */ 	mtc1	$at,$f8
/*  f147be8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f147bec:	44815000 */ 	mtc1	$at,$f10
/*  f147bf0:	44818000 */ 	mtc1	$at,$f16
/*  f147bf4:	3c012f80 */ 	lui	$at,0x2f80
/*  f147bf8:	4481f000 */ 	mtc1	$at,$f30
/*  f147bfc:	3c013f80 */ 	lui	$at,0x3f80
/*  f147c00:	4481b000 */ 	mtc1	$at,$f22
/*  f147c04:	4480e000 */ 	mtc1	$zero,$f28
/*  f147c08:	46083602 */ 	mul.s	$f24,$f6,$f8
/*  f147c0c:	46105680 */ 	add.s	$f26,$f10,$f16
.L0f147c10:
/*  f147c10:	44919000 */ 	mtc1	$s1,$f18
/*  f147c14:	00000000 */ 	nop
/*  f147c18:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f147c1c:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f147c20:	46183003 */ 	div.s	$f0,$f6,$f24
/*  f147c24:	461c003c */ 	c.lt.s	$f0,$f28
/*  f147c28:	46000506 */ 	mov.s	$f20,$f0
/*  f147c2c:	45020003 */ 	bc1fl	.L0f147c3c
/*  f147c30:	461aa500 */ 	add.s	$f20,$f20,$f26
/*  f147c34:	46000507 */ 	neg.s	$f20,$f0
/*  f147c38:	461aa500 */ 	add.s	$f20,$f20,$f26
.L0f147c3c:
/*  f147c3c:	4614b03c */ 	c.lt.s	$f22,$f20
/*  f147c40:	00000000 */ 	nop
/*  f147c44:	45000002 */ 	bc1f	.L0f147c50
/*  f147c48:	00000000 */ 	nop
/*  f147c4c:	4600b506 */ 	mov.s	$f20,$f22
.L0f147c50:
/*  f147c50:	0c004b70 */ 	jal	random
/*  f147c54:	00000000 */ 	nop
/*  f147c58:	44824000 */ 	mtc1	$v0,$f8
/*  f147c5c:	02402025 */ 	or	$a0,$s2,$zero
/*  f147c60:	02c02825 */ 	or	$a1,$s6,$zero
/*  f147c64:	02003025 */ 	or	$a2,$s0,$zero
/*  f147c68:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f147c6c:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f147c70:	04410005 */ 	bgez	$v0,.L0f147c88
/*  f147c74:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f147c78:	3c014f80 */ 	lui	$at,0x4f80
/*  f147c7c:	44818000 */ 	mtc1	$at,$f16
/*  f147c80:	00000000 */ 	nop
/*  f147c84:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f147c88:
/*  f147c88:	461e5482 */ 	mul.s	$f18,$f10,$f30
/*  f147c8c:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f147c90:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f147c94:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f147c98:	46162180 */ 	add.s	$f6,$f4,$f22
/*  f147c9c:	0fc506ac */ 	jal	func0f141ab0
/*  f147ca0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f147ca4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f147ca8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f147cac:	1613ffd8 */ 	bne	$s0,$s3,.L0f147c10
/*  f147cb0:	00409025 */ 	or	$s2,$v0,$zero
.L0f147cb4:
/*  f147cb4:	02401025 */ 	or	$v0,$s2,$zero
.L0f147cb8:
/*  f147cb8:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f147cbc:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f147cc0:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f147cc4:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f147cc8:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f147ccc:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f147cd0:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f147cd4:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f147cd8:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f147cdc:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f147ce0:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f147ce4:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f147ce8:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f147cec:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f147cf0:	03e00008 */ 	jr	$ra
/*  f147cf4:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

/**
 * Called from the title screen's "Rare Presents" mode, which is unused.
 */
Gfx *func0f147cf8(Gfx *gdl)
{
	s32 unk28 = viGetUnk28();
	s32 top = viGetViewTop();
	s32 y = viGetViewY();
	s32 x = viGetViewX();
	s32 left = viGetViewLeft();
	s32 ypos;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "IntroTextInterfereGfx");

	gDPPipeSync(gdl++);

	gdl = func0f1420b0(gdl, 0x8f8f8f8f, 255);

	for (ypos = top; ypos < top + y; ypos += 2) {
		gdl = func0f141ab0(gdl, unk28, ypos, 5, ypos, 1.0f, left, x);
	}

	return gdl;
}

u32 var8007f870 = 0x000003e8;
u32 var8007f874 = 0x000003e8;
u32 var8007f878 = 0x00000000;

Gfx *hudRenderHorizonScanner(Gfx *gdl)
{
	s32 sp194 = viGetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewY();
	s32 viewwidth = viGetViewX();
	s32 viewleft = viGetViewLeft();
	char directiontext[32];
	char hertztext[24];
	char zoomtext[24];
	char nametext[52];
	f32 lookx = g_Vars.currentplayer->cam_look.x;
	f32 lookz = g_Vars.currentplayer->cam_look.z;
	s32 x;
	s32 y;

	char directions[][3] = {
		{'n', '\0', '\0'},
		{'n', 'e',  '\0'},
		{'e', '\0', '\0'},
		{'s', 'e',  '\0'},
		{'s', '\0', '\0'},
		{'s', 'w',  '\0'},
		{'w', '\0', '\0'},
		{'n', 'w',  '\0'},
		{'n', '\0', '\0'},
	};

	s32 turnangle = func0f096750(-lookx, lookz) * 180.0f / M_PI;
	f32 fovy;
	char arrows[12];
	s32 tmplensheight = 130;
	s32 lenstop;
	s32 lensheight;
	s32 liney;
	s32 scale = 1;
	s32 vsplit = false;
	u32 colour;
	f32 range;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "BinocularViewGfx");

	if (g_HiResActive == true) {
		scale = 2;
	}

	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
		vsplit = true;
	}

	if (tmplensheight > viewheight - 30) {
		tmplensheight = viewheight - 30;
	}

	if (((s32)(var80061630 * 30.0f) & 1) == 1) {
		sprintf(arrows, ">> ");
	} else {
		sprintf(arrows, " >>");
	}

	lensheight = tmplensheight;
	lenstop = viewtop + (viewheight / 2) - (lensheight / 2);

	// Black out areas above and below lens
	gdl = gfxSetPrimColour(gdl, 0x000000ff);

	gDPFillRectangle(gdl++, viewleft, viewtop, viewleft + viewwidth, lenstop);
	gDPFillRectangle(gdl++, viewleft, lenstop + lensheight, viewleft + viewwidth, viewtop + viewheight);

	gdl = func0f153838(gdl);

	// Prepare text buffers
	sprintf(directiontext, "%s %s:%03d", arrows, &directions[(turnangle + 22) / 45], turnangle);
	sprintf(hertztext, "%s %s%s%4.2fh", arrows, "", "", func0f006b54(4) * 4.6f + 917.4f);

	fovy = viGetFovY();

	if (fovy == 0 || fovy == 60.0f) {
		fovy = 1;
	} else {
		fovy = 60.0f / fovy + 1;
	}

	sprintf(zoomtext, "%s %s%s%4.2fX", arrows, "", "", fovy);

	gdl = func0f153628(gdl);

	// Arrows left of product name
	if (vsplit) {
		x = viewleft + 15 * scale;
	} else {
		x = viewleft + 25 * scale;
	}

	y = lenstop - 7;
	gdl = textRenderProjected(gdl, &x, &y, arrows,
			var8007fb08, var8007fb04, 0xffffff7f, viGetX(), viGetY(), 0, 0);

	// Product name
	strcpy(nametext, " JMBC");

	if (!vsplit) {
		strcat(nametext, " WIDE BAND");
	}

	strcat(nametext, " SCANNER\n");

	gdl = textRenderProjected(gdl, &x, &y, nametext,
			var8007fb08, var8007fb04, 0xffffff7f, viGetX(), viGetY(), 0, 0);

	// Hertz
	x = viewleft + 75 * scale;
	y = lenstop + lensheight + 1;
	gdl = textRenderProjected(gdl, &x, &y, hertztext,
			var8007fb08, var8007fb04, 0xffffff7f, viGetX(), viGetY(), 0, 0);

	// Zoom level
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 8;
	} else {
		x = viewleft + 150 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, zoomtext,
			var8007fb08, var8007fb04, 0xffffff7f, viGetX(), viGetY(), 0, 0);

	// Direction
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 15;
	} else {
		x = viewleft + 225 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, directiontext,
			var8007fb08, var8007fb04, 0xffffff7f, viGetX(), viGetY(), 0, 0);
	gdl = func0f153780(gdl);

	gDPPipeSync(gdl++);

	gdl = func0f1420b0(gdl, 0xffffffff, 255);

	if (vsplit) {
		vsplit = 14;
	}

	// Iterate horizontal lines down the lens with a bit extra on top and bottom
	for (liney = lenstop - 9; liney < lenstop + lensheight + vsplit + 9; liney++) {
		if (liney < lenstop + lensheight && liney >= lenstop) {
			// Inside the lens
			if ((liney % 2) == 0) {
				colour = 0x00ffffff;
			} else {
				colour = 0x7fffffff;
			}

			range = (liney - lenstop - lensheight * 0.5f) / (lensheight * 0.5f);

			if (range < 0) {
				range = -range;
			}

			if (range > 1) {
				range = 0;
			}

			range = (range - 0.75f) * 4.0f;

			if (range < 0) {
				range = 0;
			}

			if (range > 0) {
				colour = colourBlend(0x000000ff, colour, range * 255.0f);
			}
		} else {
			// Outside of the lens
			if ((liney % 2) == 0) {
				colour = 0x007f7fff;
			} else {
				colour = 0x7fffffff;
			}

			range = 0;
		}

		// Different coloured lines at 1/4 and 3/4 marks in the lens
		if (liney == lenstop + lensheight / 4 || liney == lenstop + lensheight - lensheight / 4) {
			colour = 0xffffffff;
		}

		gDPSetColor(gdl++, G_SETENVCOLOR, colour);

		gdl = func0f141ab0(gdl, sp194, liney, 5, liney, random() * (1.0f / U32_MAX) * range + 1, viewleft, viewwidth);
	}

	return gdl;
}

GLOBAL_ASM(
glabel func0f14886c
/*  f14886c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f148870:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f148874:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f148878:	00809825 */ 	or	$s3,$a0,$zero
/*  f14887c:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f148880:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f148884:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f148888:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f14888c:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f148890:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f148894:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f148898:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f14889c:	0c002f26 */ 	jal	viGetViewY
/*  f1488a0:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f1488a4:	0c002f22 */ 	jal	viGetViewX
/*  f1488a8:	00408025 */ 	or	$s0,$v0,$zero
/*  f1488ac:	0c002f44 */ 	jal	viGetViewTop
/*  f1488b0:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f1488b4:	0c002f40 */ 	jal	viGetViewLeft
/*  f1488b8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1488bc:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f1488c0:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f1488c4:	02302821 */ 	addu	$a1,$s1,$s0
/*  f1488c8:	3c078008 */ 	lui	$a3,%hi(var8007f84c)
/*  f1488cc:	00c9001a */ 	div	$zero,$a2,$t1
/*  f1488d0:	00067840 */ 	sll	$t7,$a2,0x1
/*  f1488d4:	00007012 */ 	mflo	$t6
/*  f1488d8:	02601825 */ 	or	$v1,$s3,$zero
/*  f1488dc:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f1488e0:	01e9001a */ 	div	$zero,$t7,$t1
/*  f1488e4:	8ce7f84c */ 	lw	$a3,%lo(var8007f84c)($a3)
/*  f1488e8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1488ec:	3c19e700 */ 	lui	$t9,0xe700
/*  f1488f0:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1488f4:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1488f8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1488fc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f148900:	3c0aba00 */ 	lui	$t2,0xba00
/*  f148904:	0000c012 */ 	mflo	$t8
/*  f148908:	354a1402 */ 	ori	$t2,$t2,0x1402
/*  f14890c:	02604025 */ 	or	$t0,$s3,$zero
/*  f148910:	0040a025 */ 	or	$s4,$v0,$zero
/*  f148914:	01c2b021 */ 	addu	$s6,$t6,$v0
/*  f148918:	0302f021 */ 	addu	$s8,$t8,$v0
/*  f14891c:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f148920:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f148924:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f148928:	3c0bb900 */ 	lui	$t3,0xb900
/*  f14892c:	3c0c0050 */ 	lui	$t4,0x50
/*  f148930:	0046a821 */ 	addu	$s5,$v0,$a2
/*  f148934:	15200002 */ 	bnez	$t1,.L0f148940
/*  f148938:	00000000 */ 	nop
/*  f14893c:	0007000d */ 	break	0x7
.L0f148940:
/*  f148940:	2401ffff */ 	addiu	$at,$zero,-1
/*  f148944:	15210004 */ 	bne	$t1,$at,.L0f148958
/*  f148948:	3c018000 */ 	lui	$at,0x8000
/*  f14894c:	14c10002 */ 	bne	$a2,$at,.L0f148958
/*  f148950:	00000000 */ 	nop
/*  f148954:	0006000d */ 	break	0x6
.L0f148958:
/*  f148958:	358c4240 */ 	ori	$t4,$t4,0x4240
/*  f14895c:	15200002 */ 	bnez	$t1,.L0f148968
/*  f148960:	00000000 */ 	nop
/*  f148964:	0007000d */ 	break	0x7
.L0f148968:
/*  f148968:	2401ffff */ 	addiu	$at,$zero,-1
/*  f14896c:	15210004 */ 	bne	$t1,$at,.L0f148980
/*  f148970:	3c018000 */ 	lui	$at,0x8000
/*  f148974:	15e10002 */ 	bne	$t7,$at,.L0f148980
/*  f148978:	00000000 */ 	nop
/*  f14897c:	0006000d */ 	break	0x6
.L0f148980:
/*  f148980:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f148984:	02601025 */ 	or	$v0,$s3,$zero
/*  f148988:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f14898c:	ad0c0004 */ 	sw	$t4,0x4($t0)
/*  f148990:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f148994:	3c0efffd */ 	lui	$t6,0xfffd
/*  f148998:	3c0dfcff */ 	lui	$t5,0xfcff
/*  f14899c:	35adffff */ 	ori	$t5,$t5,0xffff
/*  f1489a0:	35cef6fb */ 	ori	$t6,$t6,0xf6fb
/*  f1489a4:	02601825 */ 	or	$v1,$s3,$zero
/*  f1489a8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1489ac:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1489b0:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f1489b4:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f1489b8:	0225082a */ 	slt	$at,$s1,$a1
/*  f1489bc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1489c0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1489c4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1489c8:	1020004d */ 	beqz	$at,.L0f148b00
/*  f1489cc:	02208025 */ 	or	$s0,$s1,$zero
/*  f1489d0:	00e70019 */ 	multu	$a3,$a3
/*  f1489d4:	0225c821 */ 	addu	$t9,$s1,$a1
/*  f1489d8:	07210003 */ 	bgez	$t9,.L0f1489e8
/*  f1489dc:	00195043 */ 	sra	$t2,$t9,0x1
/*  f1489e0:	27210001 */ 	addiu	$at,$t9,0x1
/*  f1489e4:	00015043 */ 	sra	$t2,$at,0x1
.L0f1489e8:
/*  f1489e8:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f1489ec:	0000b812 */ 	mflo	$s7
/*  f1489f0:	00000000 */ 	nop
/*  f1489f4:	00000000 */ 	nop
/*  f1489f8:	8fab0050 */ 	lw	$t3,0x50($sp)
.L0f1489fc:
/*  f1489fc:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f148a00:	02602025 */ 	or	$a0,$s3,$zero
/*  f148a04:	01701023 */ 	subu	$v0,$t3,$s0
/*  f148a08:	00420019 */ 	multu	$v0,$v0
/*  f148a0c:	02802825 */ 	or	$a1,$s4,$zero
/*  f148a10:	02a03825 */ 	or	$a3,$s5,$zero
/*  f148a14:	26120001 */ 	addiu	$s2,$s0,0x1
/*  f148a18:	00001812 */ 	mflo	$v1
/*  f148a1c:	0077082a */ 	slt	$at,$v1,$s7
/*  f148a20:	50200030 */ 	beqzl	$at,.L0f148ae4
/*  f148a24:	02003025 */ 	or	$a2,$s0,$zero
/*  f148a28:	44863000 */ 	mtc1	$a2,$f6
/*  f148a2c:	02e36023 */ 	subu	$t4,$s7,$v1
/*  f148a30:	3c0143a0 */ 	lui	$at,0x43a0
/*  f148a34:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f148a38:	44815000 */ 	mtc1	$at,$f10
/*  f148a3c:	448c2000 */ 	mtc1	$t4,$f4
/*  f148a40:	00000000 */ 	nop
/*  f148a44:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f148a48:	0c012974 */ 	jal	sqrtf
/*  f148a4c:	460a4503 */ 	div.s	$f20,$f8,$f10
/*  f148a50:	46140402 */ 	mul.s	$f16,$f0,$f20
/*  f148a54:	02602025 */ 	or	$a0,$s3,$zero
/*  f148a58:	02802825 */ 	or	$a1,$s4,$zero
/*  f148a5c:	02003025 */ 	or	$a2,$s0,$zero
/*  f148a60:	260f0001 */ 	addiu	$t7,$s0,0x1
/*  f148a64:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f148a68:	44029000 */ 	mfc1	$v0,$f18
/*  f148a6c:	00000000 */ 	nop
/*  f148a70:	02c27023 */ 	subu	$t6,$s6,$v0
/*  f148a74:	028e082a */ 	slt	$at,$s4,$t6
/*  f148a78:	10200005 */ 	beqz	$at,.L0f148a90
/*  f148a7c:	00408825 */ 	or	$s1,$v0,$zero
/*  f148a80:	02c23823 */ 	subu	$a3,$s6,$v0
/*  f148a84:	0fc50608 */ 	jal	func0f141820
/*  f148a88:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f148a8c:	00409825 */ 	or	$s3,$v0,$zero
.L0f148a90:
/*  f148a90:	02d12821 */ 	addu	$a1,$s6,$s1
/*  f148a94:	03d13823 */ 	subu	$a3,$s8,$s1
/*  f148a98:	00a7082a */ 	slt	$at,$a1,$a3
/*  f148a9c:	10200006 */ 	beqz	$at,.L0f148ab8
/*  f148aa0:	26120001 */ 	addiu	$s2,$s0,0x1
/*  f148aa4:	02602025 */ 	or	$a0,$s3,$zero
/*  f148aa8:	02003025 */ 	or	$a2,$s0,$zero
/*  f148aac:	0fc50608 */ 	jal	func0f141820
/*  f148ab0:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f148ab4:	00409825 */ 	or	$s3,$v0,$zero
.L0f148ab8:
/*  f148ab8:	03d12821 */ 	addu	$a1,$s8,$s1
/*  f148abc:	00b5082a */ 	slt	$at,$a1,$s5
/*  f148ac0:	1020000b */ 	beqz	$at,.L0f148af0
/*  f148ac4:	02602025 */ 	or	$a0,$s3,$zero
/*  f148ac8:	02003025 */ 	or	$a2,$s0,$zero
/*  f148acc:	02a03825 */ 	or	$a3,$s5,$zero
/*  f148ad0:	0fc50608 */ 	jal	func0f141820
/*  f148ad4:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f148ad8:	10000005 */ 	b	.L0f148af0
/*  f148adc:	00409825 */ 	or	$s3,$v0,$zero
/*  f148ae0:	02003025 */ 	or	$a2,$s0,$zero
.L0f148ae4:
/*  f148ae4:	0fc50608 */ 	jal	func0f141820
/*  f148ae8:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f148aec:	00409825 */ 	or	$s3,$v0,$zero
.L0f148af0:
/*  f148af0:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f148af4:	02408025 */ 	or	$s0,$s2,$zero
/*  f148af8:	5658ffc0 */ 	bnel	$s2,$t8,.L0f1489fc
/*  f148afc:	8fab0050 */ 	lw	$t3,0x50($sp)
.L0f148b00:
/*  f148b00:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f148b04:	02601025 */ 	or	$v0,$s3,$zero
/*  f148b08:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f148b0c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f148b10:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f148b14:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f148b18:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f148b1c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f148b20:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f148b24:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f148b28:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f148b2c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f148b30:	03e00008 */ 	jr	$ra
/*  f148b34:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f148b38:	03e00008 */ 	jr	$ra
/*  f148b3c:	00801025 */ 	or	$v0,$a0,$zero
);

void func0f148b40(u32 arg0)
{
	var8007f840 = 0;
	var8007f848 = 0;
	var8007f844 = (arg0 << 1) / 3;
}

void func0f148b6c(void)
{
	var8007f844 = 0;
}
