#include "n_synthInternals.h"
#include <os.h>
#include <math.h>
#include <assert.h>

#define N_EQPOWER_LENGTH 128

s16 n_eqpower[] = {
	0x7fff, 0x7ffc, 0x7ff5, 0x7fe8, 0x7fd7, 0x7fc0, 0x7fa5, 0x7f84,
	0x7f5f, 0x7f34, 0x7f05, 0x7ed0, 0x7e97, 0x7e58, 0x7e15, 0x7dcd,
	0x7d7f, 0x7d2d, 0x7cd6, 0x7c7a, 0x7c1a, 0x7bb4, 0x7b49, 0x7ada,
	0x7a66, 0x79ed, 0x796f, 0x78ed, 0x7866, 0x77da, 0x7749, 0x76b4,
	0x761a, 0x757b, 0x74d8, 0x7430, 0x7384, 0x72d3, 0x721e, 0x7164,
	0x70a6, 0x6fe3, 0x6f1c, 0x6e51, 0x6d81, 0x6cad, 0x6bd5, 0x6af9,
	0x6a18, 0x6933, 0x684a, 0x675d, 0x666c, 0x6577, 0x647e, 0x6381,
	0x6280, 0x617c, 0x6073, 0x5f67, 0x5e57, 0x5d43, 0x5c2c, 0x5b11,
	0x59f2, 0x58d0, 0x57aa, 0x5681, 0x5555, 0x5425, 0x52f2, 0x51bc,
	0x5082, 0x4f46, 0x4e06, 0x4cc3, 0x4b7d, 0x4a35, 0x48e9, 0x479b,
	0x4649, 0x44f5, 0x439e, 0x4245, 0x40e9, 0x3f8a, 0x3e29, 0x3cc6,
	0x3b60, 0x39f8, 0x388d, 0x3721, 0x35b2, 0x3441, 0x32ce, 0x3159,
	0x2fe2, 0x2e69, 0x2cef, 0x2b72, 0x29f4, 0x2875, 0x26f3, 0x2570,
	0x23ec, 0x2266, 0x20df, 0x1f57, 0x1dce, 0x1c43, 0x1ab7, 0x192a,
	0x179c, 0x160e, 0x147e, 0x12ed, 0x115c, 0x0fca, 0x0e38, 0x0ca5,
	0x0b11, 0x097d, 0x07e9, 0x0654, 0x04c0, 0x032a, 0x0195, 0x0000,
};

s16 _getRate(f32 vol, f32 tgt, s32 count, u16 *ratel);

GLOBAL_ASM(
glabel func0003e8c0
.late_rodata
glabel var70054af0
.word func0003e8c0+0x738
glabel var70054af4
.word func0003e8c0+0x810
glabel var70054af8
.word func0003e8c0+0x810
glabel var70054afc
.word func0003e8c0+0x810
glabel var70054b00
.word func0003e8c0+0x810
glabel var70054b04
.word func0003e8c0+0x7d0
glabel var70054b08
.word func0003e8c0+0x810
glabel var70054b0c
.word func0003e8c0+0x764
glabel var70054b10
.word func0003e8c0+0x79c
glabel var70054b14
.word func0003e8c0+0x810
glabel var70054b18
.word func0003e8c0+0x810
glabel var70054b1c
.word func0003e8c0+0x36c
glabel var70054b20
.word func0003e8c0+0x36c
glabel var70054b24
.word func0003e8c0+0x0f8
glabel var70054b28
.word func0003e8c0+0x6b0
glabel var70054b2c
.word func0003e8c0+0x700
glabel var70054b30
.word func0003e8c0+0x36c
.text
/*    3e8c0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    3e8c4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3e8c8:	afa40058 */ 	sw	$a0,0x58($sp)
/*    3e8cc:	afa5005c */ 	sw	$a1,0x5c($sp)
/*    3e8d0:	afa60060 */ 	sw	$a2,0x60($sp)
/*    3e8d4:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    3e8d8:	afae0054 */ 	sw	$t6,0x54($sp)
/*    3e8dc:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    3e8e0:	afaf0050 */ 	sw	$t7,0x50($sp)
/*    3e8e4:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    3e8e8:	afb80044 */ 	sw	$t8,0x44($sp)
/*    3e8ec:	a7a0003e */ 	sh	$zero,0x3e($sp)
/*    3e8f0:	241900b8 */ 	addiu	$t9,$zero,0xb8
/*    3e8f4:	afb90030 */ 	sw	$t9,0x30($sp)
/*    3e8f8:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*    3e8fc:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3e900:	8d09007c */ 	lw	$t1,0x7c($t0)
/*    3e904:	1120021e */ 	beqz	$t1,.L0003f180
/*    3e908:	00000000 */ 	nop
.L0003e90c:
/*    3e90c:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    3e910:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    3e914:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3e918:	8d6c007c */ 	lw	$t4,0x7c($t3)
/*    3e91c:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    3e920:	afad0044 */ 	sw	$t5,0x44($sp)
/*    3e924:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    3e928:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    3e92c:	240100b8 */ 	addiu	$at,$zero,0xb8
/*    3e930:	01cfc023 */ 	subu	$t8,$t6,$t7
/*    3e934:	271900b7 */ 	addiu	$t9,$t8,0xb7
/*    3e938:	0321001a */ 	div	$zero,$t9,$at
/*    3e93c:	00004012 */ 	mflo	$t0
/*    3e940:	00084880 */ 	sll	$t1,$t0,0x2
/*    3e944:	01284823 */ 	subu	$t1,$t1,$t0
/*    3e948:	000948c0 */ 	sll	$t1,$t1,0x3
/*    3e94c:	01284823 */ 	subu	$t1,$t1,$t0
/*    3e950:	000948c0 */ 	sll	$t1,$t1,0x3
/*    3e954:	afa90040 */ 	sw	$t1,0x40($sp)
/*    3e958:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3e95c:	15400003 */ 	bnez	$t2,.L0003e96c
/*    3e960:	00000000 */ 	nop
/*    3e964:	8fab0048 */ 	lw	$t3,0x48($sp)
/*    3e968:	afab0044 */ 	sw	$t3,0x44($sp)
.L0003e96c:
/*    3e96c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3e970:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    3e974:	01ac082a */ 	slt	$at,$t5,$t4
/*    3e978:	10200003 */ 	beqz	$at,.L0003e988
/*    3e97c:	00000000 */ 	nop
/*    3e980:	100001ff */ 	b	.L0003f180
/*    3e984:	00000000 */ 	nop
.L0003e988:
/*    3e988:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3e98c:	8dcf007c */ 	lw	$t7,0x7c($t6)
/*    3e990:	95f80008 */ 	lhu	$t8,0x8($t7)
/*    3e994:	2f010011 */ 	sltiu	$at,$t8,0x11
/*    3e998:	102001cd */ 	beqz	$at,.L0003f0d0
/*    3e99c:	00000000 */ 	nop
/*    3e9a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3e9a4:	3c017005 */ 	lui	$at,%hi(var70054af0)
/*    3e9a8:	00380821 */ 	addu	$at,$at,$t8
/*    3e9ac:	8c384af0 */ 	lw	$t8,%lo(var70054af0)($at)
/*    3e9b0:	03000008 */ 	jr	$t8
/*    3e9b4:	00000000 */ 	nop
/*    3e9b8:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3e9bc:	8f28007c */ 	lw	$t0,0x7c($t9)
/*    3e9c0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*    3e9c4:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3e9c8:	852a000a */ 	lh	$t2,0xa($t1)
/*    3e9cc:	11400004 */ 	beqz	$t2,.L0003e9e0
/*    3e9d0:	00000000 */ 	nop
/*    3e9d4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3e9d8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    3e9dc:	ad8b0048 */ 	sw	$t3,0x48($t4)
.L0003e9e0:
/*    3e9e0:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3e9e4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3e9e8:	24050005 */ 	addiu	$a1,$zero,0x5
/*    3e9ec:	0c011582 */ 	jal	n_alLoadParam
/*    3e9f0:	8da60020 */ 	lw	$a2,0x20($t5)
/*    3e9f4:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3e9f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3e9fc:	adee0084 */ 	sw	$t6,0x84($t7)
/*    3ea00:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ea04:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3ea08:	af380078 */ 	sw	$t8,0x78($t9)
/*    3ea0c:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ea10:	ad000070 */ 	sw	$zero,0x70($t0)
/*    3ea14:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3ea18:	240100b8 */ 	addiu	$at,$zero,0xb8
/*    3ea1c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ea20:	8d2a001c */ 	lw	$t2,0x1c($t1)
/*    3ea24:	254b00b7 */ 	addiu	$t3,$t2,0xb7
/*    3ea28:	0161001a */ 	div	$zero,$t3,$at
/*    3ea2c:	00006012 */ 	mflo	$t4
/*    3ea30:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3ea34:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    3ea38:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    3ea3c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    3ea40:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    3ea44:	adcd0074 */ 	sw	$t5,0x74($t6)
/*    3ea48:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3ea4c:	85f80010 */ 	lh	$t8,0x10($t7)
/*    3ea50:	0318c821 */ 	addu	$t9,$t8,$t8
/*    3ea54:	07210003 */ 	bgez	$t9,.L0003ea64
/*    3ea58:	00194043 */ 	sra	$t0,$t9,0x1
/*    3ea5c:	27210001 */ 	addiu	$at,$t9,0x1
/*    3ea60:	00014043 */ 	sra	$t0,$at,0x1
.L0003ea64:
/*    3ea64:	afa80028 */ 	sw	$t0,0x28($sp)
/*    3ea68:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    3ea6c:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ea70:	a549005a */ 	sh	$t1,0x5a($t2)
/*    3ea74:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3ea78:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3ea7c:	916c0012 */ 	lbu	$t4,0x12($t3)
/*    3ea80:	a5ac0058 */ 	sh	$t4,0x58($t5)
/*    3ea84:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3ea88:	3c088006 */ 	lui	$t0,%hi(n_eqpower)
/*    3ea8c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ea90:	91cf0013 */ 	lbu	$t7,0x13($t6)
/*    3ea94:	31f8007f */ 	andi	$t8,$t7,0x7f
/*    3ea98:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3ea9c:	01194021 */ 	addu	$t0,$t0,$t9
/*    3eaa0:	8508f570 */ 	lh	$t0,%lo(n_eqpower)($t0)
/*    3eaa4:	000f51c3 */ 	sra	$t2,$t7,0x7
/*    3eaa8:	3109fffe */ 	andi	$t1,$t0,0xfffe
/*    3eaac:	012a5825 */ 	or	$t3,$t1,$t2
/*    3eab0:	a58b0060 */ 	sh	$t3,0x60($t4)
/*    3eab4:	3c0d800a */ 	lui	$t5,%hi(var8009c340)
/*    3eab8:	91adc340 */ 	lbu	$t5,%lo(var8009c340)($t5)
/*    3eabc:	15a00005 */ 	bnez	$t5,.L0003ead4
/*    3eac0:	00000000 */ 	nop
/*    3eac4:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3eac8:	85d80060 */ 	lh	$t8,0x60($t6)
/*    3eacc:	3319fffe */ 	andi	$t9,$t8,0xfffe
/*    3ead0:	a5d90060 */ 	sh	$t9,0x60($t6)
.L0003ead4:
/*    3ead4:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3ead8:	3c0c8006 */ 	lui	$t4,%hi(n_eqpower+0xfe)
/*    3eadc:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3eae0:	910f0013 */ 	lbu	$t7,0x13($t0)
/*    3eae4:	31e9007f */ 	andi	$t1,$t7,0x7f
/*    3eae8:	00095023 */ 	negu	$t2,$t1
/*    3eaec:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3eaf0:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3eaf4:	858cf66e */ 	lh	$t4,%lo(n_eqpower+0xfe)($t4)
/*    3eaf8:	318dfffe */ 	andi	$t5,$t4,0xfffe
/*    3eafc:	a70d0062 */ 	sh	$t5,0x62($t8)
/*    3eb00:	3c19800a */ 	lui	$t9,%hi(var8009c340+0x2)
/*    3eb04:	9339c342 */ 	lbu	$t9,%lo(var8009c340+0x2)($t9)
/*    3eb08:	13200007 */ 	beqz	$t9,.L0003eb28
/*    3eb0c:	00000000 */ 	nop
/*    3eb10:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3eb14:	85c80058 */ 	lh	$t0,0x58($t6)
/*    3eb18:	00087843 */ 	sra	$t7,$t0,0x1
/*    3eb1c:	25e90020 */ 	addiu	$t1,$t7,0x20
/*    3eb20:	10000008 */ 	b	.L0003eb44
/*    3eb24:	a5c90058 */ 	sh	$t1,0x58($t6)
.L0003eb28:
/*    3eb28:	3c0a800a */ 	lui	$t2,%hi(var8009c340+0x1)
/*    3eb2c:	914ac341 */ 	lbu	$t2,%lo(var8009c340+0x1)($t2)
/*    3eb30:	11400004 */ 	beqz	$t2,.L0003eb44
/*    3eb34:	00000000 */ 	nop
/*    3eb38:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3eb3c:	240b0040 */ 	addiu	$t3,$zero,0x40
/*    3eb40:	a58b0058 */ 	sh	$t3,0x58($t4)
.L0003eb44:
/*    3eb44:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3eb48:	8db8001c */ 	lw	$t8,0x1c($t5)
/*    3eb4c:	13000008 */ 	beqz	$t8,.L0003eb70
/*    3eb50:	00000000 */ 	nop
/*    3eb54:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3eb58:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3eb5c:	a519005c */ 	sh	$t9,0x5c($t0)
/*    3eb60:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3eb64:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    3eb68:	10000018 */ 	b	.L0003ebcc
/*    3eb6c:	a52f005e */ 	sh	$t7,0x5e($t1)
.L0003eb70:
/*    3eb70:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3eb74:	3c0c8006 */ 	lui	$t4,%hi(n_eqpower)
/*    3eb78:	85ca0058 */ 	lh	$t2,0x58($t6)
/*    3eb7c:	85cd005a */ 	lh	$t5,0x5a($t6)
/*    3eb80:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3eb84:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3eb88:	858cf570 */ 	lh	$t4,%lo(n_eqpower)($t4)
/*    3eb8c:	018d0019 */ 	multu	$t4,$t5
/*    3eb90:	0000c012 */ 	mflo	$t8
/*    3eb94:	0018cbc3 */ 	sra	$t9,$t8,0xf
/*    3eb98:	a5d9005c */ 	sh	$t9,0x5c($t6)
/*    3eb9c:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3eba0:	3c0b8006 */ 	lui	$t3,%hi(n_eqpower+0xfe)
/*    3eba4:	850f0058 */ 	lh	$t7,0x58($t0)
/*    3eba8:	850c005a */ 	lh	$t4,0x5a($t0)
/*    3ebac:	000f4823 */ 	negu	$t1,$t7
/*    3ebb0:	00095040 */ 	sll	$t2,$t1,0x1
/*    3ebb4:	016a5821 */ 	addu	$t3,$t3,$t2
/*    3ebb8:	856bf66e */ 	lh	$t3,%lo(n_eqpower+0xfe)($t3)
/*    3ebbc:	016c0019 */ 	multu	$t3,$t4
/*    3ebc0:	00006812 */ 	mflo	$t5
/*    3ebc4:	000dc3c3 */ 	sra	$t8,$t5,0xf
/*    3ebc8:	a518005e */ 	sh	$t8,0x5e($t0)
.L0003ebcc:
/*    3ebcc:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3ebd0:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ebd4:	c724000c */ 	lwc1	$f4,0xc($t9)
/*    3ebd8:	e5c40044 */ 	swc1	$f4,0x44($t6)
/*    3ebdc:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3ebe0:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ebe4:	91e90015 */ 	lbu	$t1,0x15($t7)
/*    3ebe8:	a5490092 */ 	sh	$t1,0x92($t2)
/*    3ebec:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3ebf0:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3ebf4:	c5660018 */ 	lwc1	$f6,0x18($t3)
/*    3ebf8:	4600320d */ 	trunc.w.s	$f8,$f6
/*    3ebfc:	440d4000 */ 	mfc1	$t5,$f8
/*    3ec00:	00000000 */ 	nop
/*    3ec04:	a70d0090 */ 	sh	$t5,0x90($t8)
/*    3ec08:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ec0c:	24080001 */ 	addiu	$t0,$zero,0x1
/*    3ec10:	af2800b8 */ 	sw	$t0,0xb8($t9)
/*    3ec14:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3ec18:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3ec1c:	91cf0014 */ 	lbu	$t7,0x14($t6)
/*    3ec20:	a12f008c */ 	sb	$t7,0x8c($t1)
/*    3ec24:	1000013a */ 	b	.L0003f110
/*    3ec28:	00000000 */ 	nop
/*    3ec2c:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3ec30:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3ec34:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3ec38:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3ec3c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3ec40:	0c00fcca */ 	jal	_pullSubFrame
/*    3ec44:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    3ec48:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3ec4c:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ec50:	8d6c0070 */ 	lw	$t4,0x70($t3)
/*    3ec54:	8d6d0074 */ 	lw	$t5,0x74($t3)
/*    3ec58:	018d082a */ 	slt	$at,$t4,$t5
/*    3ec5c:	14200022 */ 	bnez	$at,.L0003ece8
/*    3ec60:	00000000 */ 	nop
/*    3ec64:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3ec68:	3c0e8006 */ 	lui	$t6,%hi(n_eqpower)
/*    3ec6c:	87080058 */ 	lh	$t0,0x58($t8)
/*    3ec70:	870f005a */ 	lh	$t7,0x5a($t8)
/*    3ec74:	0008c840 */ 	sll	$t9,$t0,0x1
/*    3ec78:	01d97021 */ 	addu	$t6,$t6,$t9
/*    3ec7c:	85cef570 */ 	lh	$t6,%lo(n_eqpower)($t6)
/*    3ec80:	01cf0019 */ 	multu	$t6,$t7
/*    3ec84:	00004812 */ 	mflo	$t1
/*    3ec88:	000953c3 */ 	sra	$t2,$t1,0xf
/*    3ec8c:	a70a0068 */ 	sh	$t2,0x68($t8)
/*    3ec90:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ec94:	3c198006 */ 	lui	$t9,%hi(n_eqpower+0xfe)
/*    3ec98:	856c0058 */ 	lh	$t4,0x58($t3)
/*    3ec9c:	856e005a */ 	lh	$t6,0x5a($t3)
/*    3eca0:	000c6823 */ 	negu	$t5,$t4
/*    3eca4:	000d4040 */ 	sll	$t0,$t5,0x1
/*    3eca8:	0328c821 */ 	addu	$t9,$t9,$t0
/*    3ecac:	8739f66e */ 	lh	$t9,%lo(n_eqpower+0xfe)($t9)
/*    3ecb0:	032e0019 */ 	multu	$t9,$t6
/*    3ecb4:	00007812 */ 	mflo	$t7
/*    3ecb8:	000f4bc3 */ 	sra	$t1,$t7,0xf
/*    3ecbc:	a569006e */ 	sh	$t1,0x6e($t3)
/*    3ecc0:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ecc4:	8d580074 */ 	lw	$t8,0x74($t2)
/*    3ecc8:	ad580070 */ 	sw	$t8,0x70($t2)
/*    3eccc:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ecd0:	858d0068 */ 	lh	$t5,0x68($t4)
/*    3ecd4:	a58d005c */ 	sh	$t5,0x5c($t4)
/*    3ecd8:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ecdc:	8519006e */ 	lh	$t9,0x6e($t0)
/*    3ece0:	10000011 */ 	b	.L0003ed28
/*    3ece4:	a519005e */ 	sh	$t9,0x5e($t0)
.L0003ece8:
/*    3ece8:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ecec:	85c4005c */ 	lh	$a0,0x5c($t6)
/*    3ecf0:	8dc50070 */ 	lw	$a1,0x70($t6)
/*    3ecf4:	85c60066 */ 	lh	$a2,0x66($t6)
/*    3ecf8:	0c00fe07 */ 	jal	_getVol
/*    3ecfc:	95c70064 */ 	lhu	$a3,0x64($t6)
/*    3ed00:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3ed04:	a5e2005c */ 	sh	$v0,0x5c($t7)
/*    3ed08:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3ed0c:	8524005e */ 	lh	$a0,0x5e($t1)
/*    3ed10:	8d250070 */ 	lw	$a1,0x70($t1)
/*    3ed14:	8526006c */ 	lh	$a2,0x6c($t1)
/*    3ed18:	0c00fe07 */ 	jal	_getVol
/*    3ed1c:	9527006a */ 	lhu	$a3,0x6a($t1)
/*    3ed20:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ed24:	a562005e */ 	sh	$v0,0x5e($t3)
.L0003ed28:
/*    3ed28:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3ed2c:	870a005c */ 	lh	$t2,0x5c($t8)
/*    3ed30:	15400004 */ 	bnez	$t2,.L0003ed44
/*    3ed34:	00000000 */ 	nop
/*    3ed38:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ed3c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    3ed40:	a58d005c */ 	sh	$t5,0x5c($t4)
.L0003ed44:
/*    3ed44:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ed48:	8728005e */ 	lh	$t0,0x5e($t9)
/*    3ed4c:	15000004 */ 	bnez	$t0,.L0003ed60
/*    3ed50:	00000000 */ 	nop
/*    3ed54:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3ed58:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3ed5c:	a5ee005e */ 	sh	$t6,0x5e($t7)
.L0003ed60:
/*    3ed60:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3ed64:	2401000c */ 	addiu	$at,$zero,0xc
/*    3ed68:	8d2b007c */ 	lw	$t3,0x7c($t1)
/*    3ed6c:	85780008 */ 	lh	$t8,0x8($t3)
/*    3ed70:	17010018 */ 	bne	$t8,$at,.L0003edd4
/*    3ed74:	00000000 */ 	nop
/*    3ed78:	3c0a800a */ 	lui	$t2,%hi(var8009c340+0x2)
/*    3ed7c:	914ac342 */ 	lbu	$t2,%lo(var8009c340+0x2)($t2)
/*    3ed80:	11400008 */ 	beqz	$t2,.L0003eda4
/*    3ed84:	00000000 */ 	nop
/*    3ed88:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3ed8c:	8dac007c */ 	lw	$t4,0x7c($t5)
/*    3ed90:	8599000e */ 	lh	$t9,0xe($t4)
/*    3ed94:	00194043 */ 	sra	$t0,$t9,0x1
/*    3ed98:	250e0020 */ 	addiu	$t6,$t0,0x20
/*    3ed9c:	1000000d */ 	b	.L0003edd4
/*    3eda0:	a5ae0058 */ 	sh	$t6,0x58($t5)
.L0003eda4:
/*    3eda4:	3c0f800a */ 	lui	$t7,%hi(var8009c340+0x1)
/*    3eda8:	91efc341 */ 	lbu	$t7,%lo(var8009c340+0x1)($t7)
/*    3edac:	11e00005 */ 	beqz	$t7,.L0003edc4
/*    3edb0:	00000000 */ 	nop
/*    3edb4:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3edb8:	24090040 */ 	addiu	$t1,$zero,0x40
/*    3edbc:	10000005 */ 	b	.L0003edd4
/*    3edc0:	a5690058 */ 	sh	$t1,0x58($t3)
.L0003edc4:
/*    3edc4:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3edc8:	8f0a007c */ 	lw	$t2,0x7c($t8)
/*    3edcc:	8d4c000c */ 	lw	$t4,0xc($t2)
/*    3edd0:	a70c0058 */ 	sh	$t4,0x58($t8)
.L0003edd4:
/*    3edd4:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3edd8:	2401000b */ 	addiu	$at,$zero,0xb
/*    3eddc:	8f28007c */ 	lw	$t0,0x7c($t9)
/*    3ede0:	850e0008 */ 	lh	$t6,0x8($t0)
/*    3ede4:	15c1001e */ 	bne	$t6,$at,.L0003ee60
/*    3ede8:	00000000 */ 	nop
/*    3edec:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3edf0:	ada00070 */ 	sw	$zero,0x70($t5)
/*    3edf4:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3edf8:	8de9007c */ 	lw	$t1,0x7c($t7)
/*    3edfc:	8d2b000c */ 	lw	$t3,0xc($t1)
/*    3ee00:	afab0038 */ 	sw	$t3,0x38($sp)
/*    3ee04:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    3ee08:	014a6021 */ 	addu	$t4,$t2,$t2
/*    3ee0c:	05810003 */ 	bgez	$t4,.L0003ee1c
/*    3ee10:	000cc043 */ 	sra	$t8,$t4,0x1
/*    3ee14:	25810001 */ 	addiu	$at,$t4,0x1
/*    3ee18:	0001c043 */ 	sra	$t8,$at,0x1
.L0003ee1c:
/*    3ee1c:	afb80038 */ 	sw	$t8,0x38($sp)
/*    3ee20:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    3ee24:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ee28:	a519005a */ 	sh	$t9,0x5a($t0)
/*    3ee2c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ee30:	240100b8 */ 	addiu	$at,$zero,0xb8
/*    3ee34:	8dcd007c */ 	lw	$t5,0x7c($t6)
/*    3ee38:	8daf0010 */ 	lw	$t7,0x10($t5)
/*    3ee3c:	25e900b7 */ 	addiu	$t1,$t7,0xb7
/*    3ee40:	0121001a */ 	div	$zero,$t1,$at
/*    3ee44:	00005812 */ 	mflo	$t3
/*    3ee48:	000b5080 */ 	sll	$t2,$t3,0x2
/*    3ee4c:	014b5023 */ 	subu	$t2,$t2,$t3
/*    3ee50:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    3ee54:	014b5023 */ 	subu	$t2,$t2,$t3
/*    3ee58:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    3ee5c:	adca0074 */ 	sw	$t2,0x74($t6)
.L0003ee60:
/*    3ee60:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ee64:	24010010 */ 	addiu	$at,$zero,0x10
/*    3ee68:	8d98007c */ 	lw	$t8,0x7c($t4)
/*    3ee6c:	87190008 */ 	lh	$t9,0x8($t8)
/*    3ee70:	1721003a */ 	bne	$t9,$at,.L0003ef5c
/*    3ee74:	00000000 */ 	nop
/*    3ee78:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ee7c:	8d0a007c */ 	lw	$t2,0x7c($t0)
/*    3ee80:	850d0060 */ 	lh	$t5,0x60($t0)
/*    3ee84:	850f0062 */ 	lh	$t7,0x62($t0)
/*    3ee88:	8d4e000c */ 	lw	$t6,0xc($t2)
/*    3ee8c:	01af4826 */ 	xor	$t1,$t5,$t7
/*    3ee90:	25cc0001 */ 	addiu	$t4,$t6,0x1
/*    3ee94:	000cc1c3 */ 	sra	$t8,$t4,0x7
/*    3ee98:	312b0001 */ 	andi	$t3,$t1,0x1
/*    3ee9c:	0178c826 */ 	xor	$t9,$t3,$t8
/*    3eea0:	13200013 */ 	beqz	$t9,.L0003eef0
/*    3eea4:	00000000 */ 	nop
/*    3eea8:	3c0d800a */ 	lui	$t5,%hi(var8009c340)
/*    3eeac:	91adc340 */ 	lbu	$t5,%lo(var8009c340)($t5)
/*    3eeb0:	11a0000f */ 	beqz	$t5,.L0003eef0
/*    3eeb4:	00000000 */ 	nop
/*    3eeb8:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3eebc:	85e90058 */ 	lh	$t1,0x58($t7)
/*    3eec0:	29210041 */ 	slti	$at,$t1,0x41
/*    3eec4:	14200006 */ 	bnez	$at,.L0003eee0
/*    3eec8:	00000000 */ 	nop
/*    3eecc:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3eed0:	850a0060 */ 	lh	$t2,0x60($t0)
/*    3eed4:	394e0001 */ 	xori	$t6,$t2,0x1
/*    3eed8:	10000005 */ 	b	.L0003eef0
/*    3eedc:	a50e0060 */ 	sh	$t6,0x60($t0)
.L0003eee0:
/*    3eee0:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3eee4:	858b0062 */ 	lh	$t3,0x62($t4)
/*    3eee8:	39780001 */ 	xori	$t8,$t3,0x1
/*    3eeec:	a5980062 */ 	sh	$t8,0x62($t4)
.L0003eef0:
/*    3eef0:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3eef4:	3c0e8006 */ 	lui	$t6,%hi(n_eqpower)
/*    3eef8:	8f2d007c */ 	lw	$t5,0x7c($t9)
/*    3eefc:	872b0060 */ 	lh	$t3,0x60($t9)
/*    3ef00:	8daf000c */ 	lw	$t7,0xc($t5)
/*    3ef04:	31780001 */ 	andi	$t8,$t3,0x1
/*    3ef08:	31e9007f */ 	andi	$t1,$t7,0x7f
/*    3ef0c:	00095040 */ 	sll	$t2,$t1,0x1
/*    3ef10:	01ca7021 */ 	addu	$t6,$t6,$t2
/*    3ef14:	85cef570 */ 	lh	$t6,%lo(n_eqpower)($t6)
/*    3ef18:	31c8fffe */ 	andi	$t0,$t6,0xfffe
/*    3ef1c:	01186025 */ 	or	$t4,$t0,$t8
/*    3ef20:	a72c0060 */ 	sh	$t4,0x60($t9)
/*    3ef24:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3ef28:	3c088006 */ 	lui	$t0,%hi(n_eqpower+0xfe)
/*    3ef2c:	8daf007c */ 	lw	$t7,0x7c($t5)
/*    3ef30:	85ac0062 */ 	lh	$t4,0x62($t5)
/*    3ef34:	8de9000c */ 	lw	$t1,0xc($t7)
/*    3ef38:	31990001 */ 	andi	$t9,$t4,0x1
/*    3ef3c:	312a007f */ 	andi	$t2,$t1,0x7f
/*    3ef40:	000a7023 */ 	negu	$t6,$t2
/*    3ef44:	000e5840 */ 	sll	$t3,$t6,0x1
/*    3ef48:	010b4021 */ 	addu	$t0,$t0,$t3
/*    3ef4c:	8508f66e */ 	lh	$t0,%lo(n_eqpower+0xfe)($t0)
/*    3ef50:	3118fffe */ 	andi	$t8,$t0,0xfffe
/*    3ef54:	03197825 */ 	or	$t7,$t8,$t9
/*    3ef58:	a5af0062 */ 	sh	$t7,0x62($t5)
.L0003ef5c:
/*    3ef5c:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ef60:	24090001 */ 	addiu	$t1,$zero,0x1
/*    3ef64:	ad490078 */ 	sw	$t1,0x78($t2)
/*    3ef68:	10000069 */ 	b	.L0003f110
/*    3ef6c:	00000000 */ 	nop
/*    3ef70:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ef74:	8dcb007c */ 	lw	$t3,0x7c($t6)
/*    3ef78:	afab0024 */ 	sw	$t3,0x24($sp)
/*    3ef7c:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    3ef80:	850c000a */ 	lh	$t4,0xa($t0)
/*    3ef84:	11800004 */ 	beqz	$t4,.L0003ef98
/*    3ef88:	00000000 */ 	nop
/*    3ef8c:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ef90:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3ef94:	af380048 */ 	sw	$t8,0x48($t9)
.L0003ef98:
/*    3ef98:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3ef9c:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3efa0:	24050005 */ 	addiu	$a1,$zero,0x5
/*    3efa4:	0c011582 */ 	jal	n_alLoadParam
/*    3efa8:	8de6000c */ 	lw	$a2,0xc($t7)
/*    3efac:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3efb0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    3efb4:	ad2d0084 */ 	sw	$t5,0x84($t1)
/*    3efb8:	10000055 */ 	b	.L0003f110
/*    3efbc:	00000000 */ 	nop
/*    3efc0:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3efc4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3efc8:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3efcc:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3efd0:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3efd4:	0c00fcca */ 	jal	_pullSubFrame
/*    3efd8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    3efdc:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3efe0:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3efe4:	24050004 */ 	addiu	$a1,$zero,0x4
/*    3efe8:	0c00fc79 */ 	jal	n_alEnvmixerParam
/*    3efec:	00003025 */ 	or	$a2,$zero,$zero
/*    3eff0:	10000047 */ 	b	.L0003f110
/*    3eff4:	00000000 */ 	nop
/*    3eff8:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3effc:	8dcb007c */ 	lw	$t3,0x7c($t6)
/*    3f000:	afab0020 */ 	sw	$t3,0x20($sp)
/*    3f004:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3f008:	8d0c000c */ 	lw	$t4,0xc($t0)
/*    3f00c:	ad800088 */ 	sw	$zero,0x88($t4)
/*    3f010:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3f014:	0c00c57d */ 	jal	_n_freePVoice
/*    3f018:	8f04000c */ 	lw	$a0,0xc($t8)
/*    3f01c:	1000003c */ 	b	.L0003f110
/*    3f020:	00000000 */ 	nop
/*    3f024:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    3f028:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f02c:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f030:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f034:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f038:	0c00fcca */ 	jal	_pullSubFrame
/*    3f03c:	afb90010 */ 	sw	$t9,0x10($sp)
/*    3f040:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f044:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3f048:	8ded007c */ 	lw	$t5,0x7c($t7)
/*    3f04c:	c5aa000c */ 	lwc1	$f10,0xc($t5)
/*    3f050:	e5ea0044 */ 	swc1	$f10,0x44($t7)
/*    3f054:	1000002e */ 	b	.L0003f110
/*    3f058:	00000000 */ 	nop
/*    3f05c:	8fa90054 */ 	lw	$t1,0x54($sp)
/*    3f060:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f064:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f068:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f06c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f070:	0c00fcca */ 	jal	_pullSubFrame
/*    3f074:	afa90010 */ 	sw	$t1,0x10($sp)
/*    3f078:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f07c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3f080:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    3f084:	adca0048 */ 	sw	$t2,0x48($t6)
/*    3f088:	10000021 */ 	b	.L0003f110
/*    3f08c:	00000000 */ 	nop
/*    3f090:	8fab0054 */ 	lw	$t3,0x54($sp)
/*    3f094:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f098:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f09c:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f0a0:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f0a4:	0c00fcca */ 	jal	_pullSubFrame
/*    3f0a8:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3f0ac:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f0b0:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3f0b4:	24050005 */ 	addiu	$a1,$zero,0x5
/*    3f0b8:	8d0c007c */ 	lw	$t4,0x7c($t0)
/*    3f0bc:	01002025 */ 	or	$a0,$t0,$zero
/*    3f0c0:	0c011582 */ 	jal	n_alLoadParam
/*    3f0c4:	8d86000c */ 	lw	$a2,0xc($t4)
/*    3f0c8:	10000011 */ 	b	.L0003f110
/*    3f0cc:	00000000 */ 	nop
.L0003f0d0:
/*    3f0d0:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    3f0d4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f0d8:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f0dc:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f0e0:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f0e4:	0c00fcca */ 	jal	_pullSubFrame
/*    3f0e8:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3f0ec:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f0f0:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3f0f4:	8f2d007c */ 	lw	$t5,0x7c($t9)
/*    3f0f8:	03202025 */ 	or	$a0,$t9,$zero
/*    3f0fc:	85a50008 */ 	lh	$a1,0x8($t5)
/*    3f100:	0c00fc79 */ 	jal	n_alEnvmixerParam
/*    3f104:	8da6000c */ 	lw	$a2,0xc($t5)
/*    3f108:	10000001 */ 	b	.L0003f110
/*    3f10c:	00000000 */ 	nop
.L0003f110:
/*    3f110:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    3f114:	87af003e */ 	lh	$t7,0x3e($sp)
/*    3f118:	00095040 */ 	sll	$t2,$t1,0x1
/*    3f11c:	01ea7021 */ 	addu	$t6,$t7,$t2
/*    3f120:	a7ae003e */ 	sh	$t6,0x3e($sp)
/*    3f124:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3f128:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    3f12c:	01686023 */ 	subu	$t4,$t3,$t0
/*    3f130:	afac0030 */ 	sw	$t4,0x30($sp)
/*    3f134:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3f138:	8f19007c */ 	lw	$t9,0x7c($t8)
/*    3f13c:	afb90034 */ 	sw	$t9,0x34($sp)
/*    3f140:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3f144:	8da9007c */ 	lw	$t1,0x7c($t5)
/*    3f148:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*    3f14c:	adaf007c */ 	sw	$t7,0x7c($t5)
/*    3f150:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3f154:	8d4e007c */ 	lw	$t6,0x7c($t2)
/*    3f158:	15c00003 */ 	bnez	$t6,.L0003f168
/*    3f15c:	00000000 */ 	nop
/*    3f160:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3f164:	ad600080 */ 	sw	$zero,0x80($t3)
.L0003f168:
/*    3f168:	0c00c559 */ 	jal	_n_freeParam
/*    3f16c:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    3f170:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3f174:	8d0c007c */ 	lw	$t4,0x7c($t0)
/*    3f178:	1580fde4 */ 	bnez	$t4,.L0003e90c
/*    3f17c:	00000000 */ 	nop
.L0003f180:
/*    3f180:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    3f184:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f188:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f18c:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f190:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    3f194:	0c00fcca */ 	jal	_pullSubFrame
/*    3f198:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3f19c:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f1a0:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3f1a4:	8f290070 */ 	lw	$t1,0x70($t9)
/*    3f1a8:	8f2f0074 */ 	lw	$t7,0x74($t9)
/*    3f1ac:	01e9082a */ 	slt	$at,$t7,$t1
/*    3f1b0:	10200004 */ 	beqz	$at,.L0003f1c4
/*    3f1b4:	00000000 */ 	nop
/*    3f1b8:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3f1bc:	8daa0074 */ 	lw	$t2,0x74($t5)
/*    3f1c0:	adaa0070 */ 	sw	$t2,0x70($t5)
.L0003f1c4:
/*    3f1c4:	10000003 */ 	b	.L0003f1d4
/*    3f1c8:	8fa20054 */ 	lw	$v0,0x54($sp)
/*    3f1cc:	10000001 */ 	b	.L0003f1d4
/*    3f1d0:	00000000 */ 	nop
.L0003f1d4:
/*    3f1d4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3f1d8:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    3f1dc:	03e00008 */ 	jr	$ra
/*    3f1e0:	00000000 */ 	nop
);

s32 n_alEnvmixerParam(N_PVoice *filter, s32 paramID, void *param)
{
	N_PVoice *e = filter;

	switch (paramID) {
	case AL_FILTER_ADD_UPDATE:
		if (e->em_ctrlTail) {
			e->em_ctrlTail->next = (ALParam *)param;
		} else {
			e->em_ctrlList = (ALParam *)param;
		}

		e->em_ctrlTail = (ALParam *)param;
		break;
	case AL_FILTER_RESET:
		e->em_first = 1;
		e->em_motion = AL_STOPPED;
		e->em_volume = 1;
		e->em_segEnd = 0;
		e->rs_delta = 0;
		e->rs_first = 1;
		e->rs_upitch = 0;

		func00045da8(e, AL_FILTER_RESET, param);
		break;
	case AL_FILTER_START:
		e->em_motion = AL_PLAYING;
		break;
	default:
		func00045da8(e, paramID, param);
		break;
	}

	return 0;
}

Acmd *_pullSubFrame(N_PVoice *filter, s16 *inp, s16 *outp, s32 outCount, Acmd *p)
{
	Acmd *ptr = p;
	N_PVoice *e = filter;

	/* filter must be playing and request non-zero output samples to pull. */
	if (e->em_motion != AL_PLAYING || !outCount) {
		return ptr;
	}

	/*
	 * ask all filters upstream from us to build their command
	 * lists.
	 */

	ptr = n_alResamplePull(e, inp, outCount, p);

	/*
	 * construct our portion of the command list
	 */
	if (e->em_first) {
		e->em_first = 0;

		/*
		 * Calculate derived parameters
		 */
		e->em_ltgt = (e->em_volume * n_eqpower[e->em_pan]) >> 15;
		e->em_lratm = _getRate(e->em_cvolL, e->em_ltgt, e->em_segEnd, &(e->em_lratl));
		e->em_rtgt = (e->em_volume * n_eqpower[N_EQPOWER_LENGTH - e->em_pan - 1]) >> 15;
		e->em_rratm = _getRate(e->em_cvolR, e->em_rtgt, e->em_segEnd, &(e->em_rratl));

		n_aSetVolume(ptr++, A_LEFT  | A_VOL, e->em_cvolL, e->em_dryamt, e->em_wetamt);
		n_aSetVolume(ptr++, A_RIGHT | A_VOL, e->em_rtgt, e->em_rratm,  e->em_rratl);
		n_aSetVolume(ptr++, A_RATE, e->em_ltgt, e->em_lratm, e->em_lratl);
		n_aEnvMixer (ptr++, A_INIT, e->em_cvolR, osVirtualToPhysical(e->em_state));
	} else {
		n_aEnvMixer(ptr++, A_CONTINUE, 0, osVirtualToPhysical(e->em_state));
	}

	/*
	 * bump the input buffer pointer
	 */
	*inp += (FIXED_SAMPLE << 1);
	e->em_delta += FIXED_SAMPLE;

	return ptr;
}

s16 _getRate(f32 vol, f32 tgt, s32 count, u16 *ratel)
{
	s16 s;
	s16 tmp;
	f32 invn;
	f32 a;
	f32 f;

	if (count == 0) {
		if (tgt >= vol) {
			*ratel = 0xffff;
			return 0x7fff;
		} else {
			*ratel = 0;
			return -0x8000;
		}
	}

	invn = 1 / (f32) count;

	if (tgt < 1) {
		tgt = 1;
	}

	if (vol <= 0) {
		vol = 1;
	}

	a = (tgt - vol) * invn * 8;
	s = a;

	f = a - s;
	s--;
	f++;

	tmp = f;
	s += tmp;
	f -= tmp;

	*ratel = 65535 * f;

	return s;
}

s16 _getVol(s16 ivol, s32 samples, s16 ratem, u16 ratel)
{
	s32 sp4;

	/*
	 * Rate values are actually rate^8
	 */
	samples >>= 3;

	if (samples == 0) {
		return ivol;
	}

	sp4 = ratel * samples;
	sp4 >>= 16;
	sp4 += ratem * samples;

	ivol += sp4;

	return ivol;
}
