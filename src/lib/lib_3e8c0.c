#include <ultra64.h>
#include "PR/synthInternals.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3e8c0.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_44f60.h"
#include "lib/lib_45ed0.h"
#include "lib/lib_461c0.h"
#include "lib/lib_46650.h"
#include "lib/lib_47550.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

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
/*    3e9ec:	0c011582 */ 	jal	func00045608
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
/*    3ea88:	3c088006 */ 	lui	$t0,%hi(var8005f570)
/*    3ea8c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ea90:	91cf0013 */ 	lbu	$t7,0x13($t6)
/*    3ea94:	31f8007f */ 	andi	$t8,$t7,0x7f
/*    3ea98:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3ea9c:	01194021 */ 	addu	$t0,$t0,$t9
/*    3eaa0:	8508f570 */ 	lh	$t0,%lo(var8005f570)($t0)
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
/*    3ead8:	3c0c8006 */ 	lui	$t4,%hi(var8005f570+0xfe)
/*    3eadc:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3eae0:	910f0013 */ 	lbu	$t7,0x13($t0)
/*    3eae4:	31e9007f */ 	andi	$t1,$t7,0x7f
/*    3eae8:	00095023 */ 	negu	$t2,$t1
/*    3eaec:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3eaf0:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3eaf4:	858cf66e */ 	lh	$t4,%lo(var8005f570+0xfe)($t4)
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
/*    3eb74:	3c0c8006 */ 	lui	$t4,%hi(var8005f570)
/*    3eb78:	85ca0058 */ 	lh	$t2,0x58($t6)
/*    3eb7c:	85cd005a */ 	lh	$t5,0x5a($t6)
/*    3eb80:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3eb84:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3eb88:	858cf570 */ 	lh	$t4,%lo(var8005f570)($t4)
/*    3eb8c:	018d0019 */ 	multu	$t4,$t5
/*    3eb90:	0000c012 */ 	mflo	$t8
/*    3eb94:	0018cbc3 */ 	sra	$t9,$t8,0xf
/*    3eb98:	a5d9005c */ 	sh	$t9,0x5c($t6)
/*    3eb9c:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3eba0:	3c0b8006 */ 	lui	$t3,%hi(var8005f570+0xfe)
/*    3eba4:	850f0058 */ 	lh	$t7,0x58($t0)
/*    3eba8:	850c005a */ 	lh	$t4,0x5a($t0)
/*    3ebac:	000f4823 */ 	negu	$t1,$t7
/*    3ebb0:	00095040 */ 	sll	$t2,$t1,0x1
/*    3ebb4:	016a5821 */ 	addu	$t3,$t3,$t2
/*    3ebb8:	856bf66e */ 	lh	$t3,%lo(var8005f570+0xfe)($t3)
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
/*    3ec40:	0c00fcca */ 	jal	func0003f328
/*    3ec44:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    3ec48:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3ec4c:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ec50:	8d6c0070 */ 	lw	$t4,0x70($t3)
/*    3ec54:	8d6d0074 */ 	lw	$t5,0x74($t3)
/*    3ec58:	018d082a */ 	slt	$at,$t4,$t5
/*    3ec5c:	14200022 */ 	bnez	$at,.L0003ece8
/*    3ec60:	00000000 */ 	nop
/*    3ec64:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3ec68:	3c0e8006 */ 	lui	$t6,%hi(var8005f570)
/*    3ec6c:	87080058 */ 	lh	$t0,0x58($t8)
/*    3ec70:	870f005a */ 	lh	$t7,0x5a($t8)
/*    3ec74:	0008c840 */ 	sll	$t9,$t0,0x1
/*    3ec78:	01d97021 */ 	addu	$t6,$t6,$t9
/*    3ec7c:	85cef570 */ 	lh	$t6,%lo(var8005f570)($t6)
/*    3ec80:	01cf0019 */ 	multu	$t6,$t7
/*    3ec84:	00004812 */ 	mflo	$t1
/*    3ec88:	000953c3 */ 	sra	$t2,$t1,0xf
/*    3ec8c:	a70a0068 */ 	sh	$t2,0x68($t8)
/*    3ec90:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ec94:	3c198006 */ 	lui	$t9,%hi(var8005f570+0xfe)
/*    3ec98:	856c0058 */ 	lh	$t4,0x58($t3)
/*    3ec9c:	856e005a */ 	lh	$t6,0x5a($t3)
/*    3eca0:	000c6823 */ 	negu	$t5,$t4
/*    3eca4:	000d4040 */ 	sll	$t0,$t5,0x1
/*    3eca8:	0328c821 */ 	addu	$t9,$t9,$t0
/*    3ecac:	8739f66e */ 	lh	$t9,%lo(var8005f570+0xfe)($t9)
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
/*    3eef4:	3c0e8006 */ 	lui	$t6,%hi(var8005f570)
/*    3eef8:	8f2d007c */ 	lw	$t5,0x7c($t9)
/*    3eefc:	872b0060 */ 	lh	$t3,0x60($t9)
/*    3ef00:	8daf000c */ 	lw	$t7,0xc($t5)
/*    3ef04:	31780001 */ 	andi	$t8,$t3,0x1
/*    3ef08:	31e9007f */ 	andi	$t1,$t7,0x7f
/*    3ef0c:	00095040 */ 	sll	$t2,$t1,0x1
/*    3ef10:	01ca7021 */ 	addu	$t6,$t6,$t2
/*    3ef14:	85cef570 */ 	lh	$t6,%lo(var8005f570)($t6)
/*    3ef18:	31c8fffe */ 	andi	$t0,$t6,0xfffe
/*    3ef1c:	01186025 */ 	or	$t4,$t0,$t8
/*    3ef20:	a72c0060 */ 	sh	$t4,0x60($t9)
/*    3ef24:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3ef28:	3c088006 */ 	lui	$t0,%hi(var8005f570+0xfe)
/*    3ef2c:	8daf007c */ 	lw	$t7,0x7c($t5)
/*    3ef30:	85ac0062 */ 	lh	$t4,0x62($t5)
/*    3ef34:	8de9000c */ 	lw	$t1,0xc($t7)
/*    3ef38:	31990001 */ 	andi	$t9,$t4,0x1
/*    3ef3c:	312a007f */ 	andi	$t2,$t1,0x7f
/*    3ef40:	000a7023 */ 	negu	$t6,$t2
/*    3ef44:	000e5840 */ 	sll	$t3,$t6,0x1
/*    3ef48:	010b4021 */ 	addu	$t0,$t0,$t3
/*    3ef4c:	8508f66e */ 	lh	$t0,%lo(var8005f570+0xfe)($t0)
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
/*    3efa4:	0c011582 */ 	jal	func00045608
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
/*    3efd4:	0c00fcca */ 	jal	func0003f328
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
/*    3f014:	0c00c57d */ 	jal	_freePVoice
/*    3f018:	8f04000c */ 	lw	$a0,0xc($t8)
/*    3f01c:	1000003c */ 	b	.L0003f110
/*    3f020:	00000000 */ 	nop
/*    3f024:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    3f028:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f02c:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f030:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f034:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f038:	0c00fcca */ 	jal	func0003f328
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
/*    3f070:	0c00fcca */ 	jal	func0003f328
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
/*    3f0a4:	0c00fcca */ 	jal	func0003f328
/*    3f0a8:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3f0ac:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f0b0:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3f0b4:	24050005 */ 	addiu	$a1,$zero,0x5
/*    3f0b8:	8d0c007c */ 	lw	$t4,0x7c($t0)
/*    3f0bc:	01002025 */ 	or	$a0,$t0,$zero
/*    3f0c0:	0c011582 */ 	jal	func00045608
/*    3f0c4:	8d86000c */ 	lw	$a2,0xc($t4)
/*    3f0c8:	10000011 */ 	b	.L0003f110
/*    3f0cc:	00000000 */ 	nop
.L0003f0d0:
/*    3f0d0:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    3f0d4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f0d8:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f0dc:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f0e0:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f0e4:	0c00fcca */ 	jal	func0003f328
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
/*    3f168:	0c00c559 */ 	jal	__freeParam
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
/*    3f194:	0c00fcca */ 	jal	func0003f328
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

s32 n_alEnvmixerParam(void *filter, s32 paramID, void *param)
{
	ALEnvMixer	*e = (ALEnvMixer *) filter;

	switch (paramID) {
	case AL_FILTER_ADD_UPDATE:
		if (e->ctrlTail) {
			e->ctrlTail->next = (ALParam *)param;
		} else {
			e->ctrlList = (ALParam *)param;
		}

		e->ctrlTail = (ALParam *)param;
		break;
	case AL_FILTER_RESET:
		e->first = 1;
		e->motion = AL_STOPPED;
		e->volume = 1;

		// @dangerous: Unsure which properties these refer to
		// as the ALEnvMixer struct was modified
		*(s32 *)((u32)e + 0x74) = 0;
		*(f32 *)((u32)e + 0x4c) = 0;
		*(s32 *)((u32)e + 0x50) = 1;
		*(s32 *)((u32)e + 0x48) = 0;

		n_alLoadParam(e, AL_FILTER_RESET, param);
		break;
	case AL_FILTER_START:
		e->motion = AL_PLAYING;
		break;
	default:
		n_alLoadParam(e, paramID, param);
		break;
	}

	return 0;
}

GLOBAL_ASM(
glabel func0003f328
/*    3f328:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    3f32c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3f330:	afa40038 */ 	sw	$a0,0x38($sp)
/*    3f334:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    3f338:	afa60040 */ 	sw	$a2,0x40($sp)
/*    3f33c:	afa70044 */ 	sw	$a3,0x44($sp)
/*    3f340:	8fae0048 */ 	lw	$t6,0x48($sp)
/*    3f344:	afae0034 */ 	sw	$t6,0x34($sp)
/*    3f348:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3f34c:	afaf0030 */ 	sw	$t7,0x30($sp)
/*    3f350:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    3f354:	24010001 */ 	addiu	$at,$zero,0x1
/*    3f358:	8f190084 */ 	lw	$t9,0x84($t8)
/*    3f35c:	17210004 */ 	bne	$t9,$at,.L0003f370
/*    3f360:	00000000 */ 	nop
/*    3f364:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    3f368:	15000003 */ 	bnez	$t0,.L0003f378
/*    3f36c:	00000000 */ 	nop
.L0003f370:
/*    3f370:	100000a2 */ 	b	.L0003f5fc
/*    3f374:	8fa20034 */ 	lw	$v0,0x34($sp)
.L0003f378:
/*    3f378:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    3f37c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*    3f380:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3f384:	0c0116ac */ 	jal	func00045ab0
/*    3f388:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    3f38c:	afa20034 */ 	sw	$v0,0x34($sp)
/*    3f390:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f394:	8d2a0078 */ 	lw	$t2,0x78($t1)
/*    3f398:	11400080 */ 	beqz	$t2,.L0003f59c
/*    3f39c:	00000000 */ 	nop
/*    3f3a0:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3f3a4:	ad600078 */ 	sw	$zero,0x78($t3)
/*    3f3a8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3f3ac:	3c0f8006 */ 	lui	$t7,%hi(var8005f570)
/*    3f3b0:	858d0058 */ 	lh	$t5,0x58($t4)
/*    3f3b4:	8598005a */ 	lh	$t8,0x5a($t4)
/*    3f3b8:	000d7040 */ 	sll	$t6,$t5,0x1
/*    3f3bc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    3f3c0:	85eff570 */ 	lh	$t7,%lo(var8005f570)($t7)
/*    3f3c4:	01f80019 */ 	multu	$t7,$t8
/*    3f3c8:	0000c812 */ 	mflo	$t9
/*    3f3cc:	001943c3 */ 	sra	$t0,$t9,0xf
/*    3f3d0:	a5880068 */ 	sh	$t0,0x68($t4)
/*    3f3d4:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f3d8:	852a005c */ 	lh	$t2,0x5c($t1)
/*    3f3dc:	852b0068 */ 	lh	$t3,0x68($t1)
/*    3f3e0:	8d260074 */ 	lw	$a2,0x74($t1)
/*    3f3e4:	448a2000 */ 	mtc1	$t2,$f4
/*    3f3e8:	448b3000 */ 	mtc1	$t3,$f6
/*    3f3ec:	25270064 */ 	addiu	$a3,$t1,0x64
/*    3f3f0:	46802320 */ 	cvt.s.w	$f12,$f4
/*    3f3f4:	0c00fd83 */ 	jal	func0003f60c
/*    3f3f8:	468033a0 */ 	cvt.s.w	$f14,$f6
/*    3f3fc:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    3f400:	a5a20066 */ 	sh	$v0,0x66($t5)
/*    3f404:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    3f408:	3c088006 */ 	lui	$t0,%hi(var8005f570+0xfe)
/*    3f40c:	85cf0058 */ 	lh	$t7,0x58($t6)
/*    3f410:	85cc005a */ 	lh	$t4,0x5a($t6)
/*    3f414:	000fc023 */ 	negu	$t8,$t7
/*    3f418:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3f41c:	01194021 */ 	addu	$t0,$t0,$t9
/*    3f420:	8508f66e */ 	lh	$t0,%lo(var8005f570+0xfe)($t0)
/*    3f424:	010c0019 */ 	multu	$t0,$t4
/*    3f428:	00005012 */ 	mflo	$t2
/*    3f42c:	000a5bc3 */ 	sra	$t3,$t2,0xf
/*    3f430:	a5cb006e */ 	sh	$t3,0x6e($t6)
/*    3f434:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f438:	852d005e */ 	lh	$t5,0x5e($t1)
/*    3f43c:	852f006e */ 	lh	$t7,0x6e($t1)
/*    3f440:	8d260074 */ 	lw	$a2,0x74($t1)
/*    3f444:	448d4000 */ 	mtc1	$t5,$f8
/*    3f448:	448f5000 */ 	mtc1	$t7,$f10
/*    3f44c:	2527006a */ 	addiu	$a3,$t1,0x6a
/*    3f450:	46804320 */ 	cvt.s.w	$f12,$f8
/*    3f454:	0c00fd83 */ 	jal	func0003f60c
/*    3f458:	468053a0 */ 	cvt.s.w	$f14,$f10
/*    3f45c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    3f460:	a702006c */ 	sh	$v0,0x6c($t8)
/*    3f464:	8fb90034 */ 	lw	$t9,0x34($sp)
/*    3f468:	27280008 */ 	addiu	$t0,$t9,0x8
/*    3f46c:	afa80034 */ 	sw	$t0,0x34($sp)
/*    3f470:	afb9002c */ 	sw	$t9,0x2c($sp)
/*    3f474:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3f478:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3f47c:	3c010906 */ 	lui	$at,0x906
/*    3f480:	858a005c */ 	lh	$t2,0x5c($t4)
/*    3f484:	314bffff */ 	andi	$t3,$t2,0xffff
/*    3f488:	01617025 */ 	or	$t6,$t3,$at
/*    3f48c:	adae0000 */ 	sw	$t6,0x0($t5)
/*    3f490:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3f494:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3f498:	85e90060 */ 	lh	$t1,0x60($t7)
/*    3f49c:	85e80062 */ 	lh	$t0,0x62($t7)
/*    3f4a0:	3138ffff */ 	andi	$t8,$t1,0xffff
/*    3f4a4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*    3f4a8:	310cffff */ 	andi	$t4,$t0,0xffff
/*    3f4ac:	032c5025 */ 	or	$t2,$t9,$t4
/*    3f4b0:	ad6a0004 */ 	sw	$t2,0x4($t3)
/*    3f4b4:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    3f4b8:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*    3f4bc:	afad0034 */ 	sw	$t5,0x34($sp)
/*    3f4c0:	afae0028 */ 	sw	$t6,0x28($sp)
/*    3f4c4:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f4c8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3f4cc:	3c010904 */ 	lui	$at,0x904
/*    3f4d0:	8538006e */ 	lh	$t8,0x6e($t1)
/*    3f4d4:	330fffff */ 	andi	$t7,$t8,0xffff
/*    3f4d8:	01e14025 */ 	or	$t0,$t7,$at
/*    3f4dc:	af280000 */ 	sw	$t0,0x0($t9)
/*    3f4e0:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3f4e4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3f4e8:	858a006c */ 	lh	$t2,0x6c($t4)
/*    3f4ec:	958d006a */ 	lhu	$t5,0x6a($t4)
/*    3f4f0:	314bffff */ 	andi	$t3,$t2,0xffff
/*    3f4f4:	000b7400 */ 	sll	$t6,$t3,0x10
/*    3f4f8:	31a9ffff */ 	andi	$t1,$t5,0xffff
/*    3f4fc:	01c9c025 */ 	or	$t8,$t6,$t1
/*    3f500:	adf80004 */ 	sw	$t8,0x4($t7)
/*    3f504:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    3f508:	25190008 */ 	addiu	$t9,$t0,0x8
/*    3f50c:	afb90034 */ 	sw	$t9,0x34($sp)
/*    3f510:	afa80024 */ 	sw	$t0,0x24($sp)
/*    3f514:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    3f518:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3f51c:	3c010900 */ 	lui	$at,0x900
/*    3f520:	854b0068 */ 	lh	$t3,0x68($t2)
/*    3f524:	316cffff */ 	andi	$t4,$t3,0xffff
/*    3f528:	01816825 */ 	or	$t5,$t4,$at
/*    3f52c:	adcd0000 */ 	sw	$t5,0x0($t6)
/*    3f530:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f534:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3f538:	85380066 */ 	lh	$t8,0x66($t1)
/*    3f53c:	95390064 */ 	lhu	$t9,0x64($t1)
/*    3f540:	330fffff */ 	andi	$t7,$t8,0xffff
/*    3f544:	000f4400 */ 	sll	$t0,$t7,0x10
/*    3f548:	332affff */ 	andi	$t2,$t9,0xffff
/*    3f54c:	010a5825 */ 	or	$t3,$t0,$t2
/*    3f550:	ad8b0004 */ 	sw	$t3,0x4($t4)
/*    3f554:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    3f558:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*    3f55c:	afae0034 */ 	sw	$t6,0x34($sp)
/*    3f560:	afad0020 */ 	sw	$t5,0x20($sp)
/*    3f564:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    3f568:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3f56c:	3c010301 */ 	lui	$at,0x301
/*    3f570:	870f005e */ 	lh	$t7,0x5e($t8)
/*    3f574:	31e9ffff */ 	andi	$t1,$t7,0xffff
/*    3f578:	0121c825 */ 	or	$t9,$t1,$at
/*    3f57c:	ad190000 */ 	sw	$t9,0x0($t0)
/*    3f580:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    3f584:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3f588:	8d440054 */ 	lw	$a0,0x54($t2)
/*    3f58c:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3f590:	ad620004 */ 	sw	$v0,0x4($t3)
/*    3f594:	1000000d */ 	b	.L0003f5cc
/*    3f598:	00000000 */ 	nop
.L0003f59c:
/*    3f59c:	8fac0034 */ 	lw	$t4,0x34($sp)
/*    3f5a0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    3f5a4:	afad0034 */ 	sw	$t5,0x34($sp)
/*    3f5a8:	afac001c */ 	sw	$t4,0x1c($sp)
/*    3f5ac:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3f5b0:	3c0e0300 */ 	lui	$t6,0x300
/*    3f5b4:	af0e0000 */ 	sw	$t6,0x0($t8)
/*    3f5b8:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3f5bc:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3f5c0:	8de40054 */ 	lw	$a0,0x54($t7)
/*    3f5c4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3f5c8:	ad220004 */ 	sw	$v0,0x4($t1)
.L0003f5cc:
/*    3f5cc:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    3f5d0:	87280000 */ 	lh	$t0,0x0($t9)
/*    3f5d4:	250a0170 */ 	addiu	$t2,$t0,0x170
/*    3f5d8:	a72a0000 */ 	sh	$t2,0x0($t9)
/*    3f5dc:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3f5e0:	8d6c0070 */ 	lw	$t4,0x70($t3)
/*    3f5e4:	258d00b8 */ 	addiu	$t5,$t4,0xb8
/*    3f5e8:	ad6d0070 */ 	sw	$t5,0x70($t3)
/*    3f5ec:	10000003 */ 	b	.L0003f5fc
/*    3f5f0:	8fa20034 */ 	lw	$v0,0x34($sp)
/*    3f5f4:	10000001 */ 	b	.L0003f5fc
/*    3f5f8:	00000000 */ 	nop
.L0003f5fc:
/*    3f5fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3f600:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    3f604:	03e00008 */ 	jr	$ra
/*    3f608:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003f60c
.late_rodata
glabel var70054b34
.word 0x477fff00
.text
/*    3f60c:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    3f610:	14c0000e */ 	bnez	$a2,.L0003f64c
/*    3f614:	00000000 */ 	nop
/*    3f618:	460e603e */ 	c.le.s	$f12,$f14
/*    3f61c:	00000000 */ 	nop
/*    3f620:	45000007 */ 	bc1f	.L0003f640
/*    3f624:	00000000 */ 	nop
/*    3f628:	340effff */ 	dli	$t6,0xffff
/*    3f62c:	a4ee0000 */ 	sh	$t6,0x0($a3)
/*    3f630:	10000078 */ 	b	.L0003f814
/*    3f634:	24027fff */ 	addiu	$v0,$zero,0x7fff
/*    3f638:	10000004 */ 	b	.L0003f64c
/*    3f63c:	00000000 */ 	nop
.L0003f640:
/*    3f640:	a4e00000 */ 	sh	$zero,0x0($a3)
/*    3f644:	10000073 */ 	b	.L0003f814
/*    3f648:	24028000 */ 	addiu	$v0,$zero,-32768
.L0003f64c:
/*    3f64c:	44863000 */ 	mtc1	$a2,$f6
/*    3f650:	3c013f80 */ 	lui	$at,0x3f80
/*    3f654:	44812000 */ 	mtc1	$at,$f4
/*    3f658:	46803220 */ 	cvt.s.w	$f8,$f6
/*    3f65c:	46082283 */ 	div.s	$f10,$f4,$f8
/*    3f660:	e7aa0008 */ 	swc1	$f10,0x8($sp)
/*    3f664:	3c013f80 */ 	lui	$at,0x3f80
/*    3f668:	44818000 */ 	mtc1	$at,$f16
/*    3f66c:	00000000 */ 	nop
/*    3f670:	4610703c */ 	c.lt.s	$f14,$f16
/*    3f674:	00000000 */ 	nop
/*    3f678:	45000004 */ 	bc1f	.L0003f68c
/*    3f67c:	00000000 */ 	nop
/*    3f680:	3c013f80 */ 	lui	$at,0x3f80
/*    3f684:	44817000 */ 	mtc1	$at,$f14
/*    3f688:	00000000 */ 	nop
.L0003f68c:
/*    3f68c:	44809000 */ 	mtc1	$zero,$f18
/*    3f690:	00000000 */ 	nop
/*    3f694:	4612603e */ 	c.le.s	$f12,$f18
/*    3f698:	00000000 */ 	nop
/*    3f69c:	45000004 */ 	bc1f	.L0003f6b0
/*    3f6a0:	00000000 */ 	nop
/*    3f6a4:	3c013f80 */ 	lui	$at,0x3f80
/*    3f6a8:	44816000 */ 	mtc1	$at,$f12
/*    3f6ac:	00000000 */ 	nop
.L0003f6b0:
/*    3f6b0:	460c7181 */ 	sub.s	$f6,$f14,$f12
/*    3f6b4:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    3f6b8:	3c014100 */ 	lui	$at,0x4100
/*    3f6bc:	44815000 */ 	mtc1	$at,$f10
/*    3f6c0:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    3f6c4:	00000000 */ 	nop
/*    3f6c8:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    3f6cc:	e7b00004 */ 	swc1	$f16,0x4($sp)
/*    3f6d0:	c7b20004 */ 	lwc1	$f18,0x4($sp)
/*    3f6d4:	4600918d */ 	trunc.w.s	$f6,$f18
/*    3f6d8:	44183000 */ 	mfc1	$t8,$f6
/*    3f6dc:	00000000 */ 	nop
/*    3f6e0:	a7b8000e */ 	sh	$t8,0xe($sp)
/*    3f6e4:	87b9000e */ 	lh	$t9,0xe($sp)
/*    3f6e8:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    3f6ec:	44994000 */ 	mtc1	$t9,$f8
/*    3f6f0:	00000000 */ 	nop
/*    3f6f4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    3f6f8:	460a2401 */ 	sub.s	$f16,$f4,$f10
/*    3f6fc:	e7b00000 */ 	swc1	$f16,0x0($sp)
/*    3f700:	87a8000e */ 	lh	$t0,0xe($sp)
/*    3f704:	2509ffff */ 	addiu	$t1,$t0,-1
/*    3f708:	a7a9000e */ 	sh	$t1,0xe($sp)
/*    3f70c:	3c013f80 */ 	lui	$at,0x3f80
/*    3f710:	44813000 */ 	mtc1	$at,$f6
/*    3f714:	c7b20000 */ 	lwc1	$f18,0x0($sp)
/*    3f718:	46069200 */ 	add.s	$f8,$f18,$f6
/*    3f71c:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*    3f720:	c7a40000 */ 	lwc1	$f4,0x0($sp)
/*    3f724:	4600228d */ 	trunc.w.s	$f10,$f4
/*    3f728:	440b5000 */ 	mfc1	$t3,$f10
/*    3f72c:	00000000 */ 	nop
/*    3f730:	a7ab000c */ 	sh	$t3,0xc($sp)
/*    3f734:	87ac000e */ 	lh	$t4,0xe($sp)
/*    3f738:	87ad000c */ 	lh	$t5,0xc($sp)
/*    3f73c:	018d7021 */ 	addu	$t6,$t4,$t5
/*    3f740:	a7ae000e */ 	sh	$t6,0xe($sp)
/*    3f744:	87af000c */ 	lh	$t7,0xc($sp)
/*    3f748:	c7b00000 */ 	lwc1	$f16,0x0($sp)
/*    3f74c:	448f9000 */ 	mtc1	$t7,$f18
/*    3f750:	00000000 */ 	nop
/*    3f754:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    3f758:	46068201 */ 	sub.s	$f8,$f16,$f6
/*    3f75c:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*    3f760:	3c017005 */ 	lui	$at,%hi(var70054b34)
/*    3f764:	c4244b34 */ 	lwc1	$f4,%lo(var70054b34)($at)
/*    3f768:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    3f76c:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3f770:	460a2482 */ 	mul.s	$f18,$f4,$f10
/*    3f774:	4458f800 */ 	cfc1	$t8,$31
/*    3f778:	44d9f800 */ 	ctc1	$t9,$31
/*    3f77c:	00000000 */ 	nop
/*    3f780:	46009424 */ 	cvt.w.s	$f16,$f18
/*    3f784:	4459f800 */ 	cfc1	$t9,$31
/*    3f788:	00000000 */ 	nop
/*    3f78c:	33210004 */ 	andi	$at,$t9,0x4
/*    3f790:	33390078 */ 	andi	$t9,$t9,0x78
/*    3f794:	13200014 */ 	beqz	$t9,.L0003f7e8
/*    3f798:	00000000 */ 	nop
/*    3f79c:	3c014f00 */ 	lui	$at,0x4f00
/*    3f7a0:	44818000 */ 	mtc1	$at,$f16
/*    3f7a4:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3f7a8:	46109401 */ 	sub.s	$f16,$f18,$f16
/*    3f7ac:	44d9f800 */ 	ctc1	$t9,$31
/*    3f7b0:	00000000 */ 	nop
/*    3f7b4:	46008424 */ 	cvt.w.s	$f16,$f16
/*    3f7b8:	4459f800 */ 	cfc1	$t9,$31
/*    3f7bc:	00000000 */ 	nop
/*    3f7c0:	33210004 */ 	andi	$at,$t9,0x4
/*    3f7c4:	33390078 */ 	andi	$t9,$t9,0x78
/*    3f7c8:	17200005 */ 	bnez	$t9,.L0003f7e0
/*    3f7cc:	00000000 */ 	nop
/*    3f7d0:	44198000 */ 	mfc1	$t9,$f16
/*    3f7d4:	3c018000 */ 	lui	$at,0x8000
/*    3f7d8:	10000007 */ 	b	.L0003f7f8
/*    3f7dc:	0321c825 */ 	or	$t9,$t9,$at
.L0003f7e0:
/*    3f7e0:	10000005 */ 	b	.L0003f7f8
/*    3f7e4:	2419ffff */ 	addiu	$t9,$zero,-1
.L0003f7e8:
/*    3f7e8:	44198000 */ 	mfc1	$t9,$f16
/*    3f7ec:	00000000 */ 	nop
/*    3f7f0:	0720fffb */ 	bltz	$t9,.L0003f7e0
/*    3f7f4:	00000000 */ 	nop
.L0003f7f8:
/*    3f7f8:	44d8f800 */ 	ctc1	$t8,$31
/*    3f7fc:	a4f90000 */ 	sh	$t9,0x0($a3)
/*    3f800:	00000000 */ 	nop
/*    3f804:	10000003 */ 	b	.L0003f814
/*    3f808:	87a2000e */ 	lh	$v0,0xe($sp)
/*    3f80c:	10000001 */ 	b	.L0003f814
/*    3f810:	00000000 */ 	nop
.L0003f814:
/*    3f814:	03e00008 */ 	jr	$ra
/*    3f818:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel _getVol
/*    3f81c:	00042400 */ 	sll	$a0,$a0,0x10
/*    3f820:	00063400 */ 	sll	$a2,$a2,0x10
/*    3f824:	00063403 */ 	sra	$a2,$a2,0x10
/*    3f828:	00042403 */ 	sra	$a0,$a0,0x10
/*    3f82c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3f830:	30e7ffff */ 	andi	$a3,$a3,0xffff
/*    3f834:	000528c3 */ 	sra	$a1,$a1,0x3
/*    3f838:	14a00003 */ 	bnez	$a1,.L0003f848
/*    3f83c:	00000000 */ 	nop
/*    3f840:	10000015 */ 	b	.L0003f898
/*    3f844:	00801025 */ 	or	$v0,$a0,$zero
.L0003f848:
/*    3f848:	00e50019 */ 	multu	$a3,$a1
/*    3f84c:	00007012 */ 	mflo	$t6
/*    3f850:	afae0004 */ 	sw	$t6,0x4($sp)
/*    3f854:	00000000 */ 	nop
/*    3f858:	8faf0004 */ 	lw	$t7,0x4($sp)
/*    3f85c:	000fc403 */ 	sra	$t8,$t7,0x10
/*    3f860:	afb80004 */ 	sw	$t8,0x4($sp)
/*    3f864:	00c50019 */ 	multu	$a2,$a1
/*    3f868:	8fb90004 */ 	lw	$t9,0x4($sp)
/*    3f86c:	00004012 */ 	mflo	$t0
/*    3f870:	03284821 */ 	addu	$t1,$t9,$t0
/*    3f874:	afa90004 */ 	sw	$t1,0x4($sp)
/*    3f878:	8faa0004 */ 	lw	$t2,0x4($sp)
/*    3f87c:	008a2021 */ 	addu	$a0,$a0,$t2
/*    3f880:	00042400 */ 	sll	$a0,$a0,0x10
/*    3f884:	00042403 */ 	sra	$a0,$a0,0x10
/*    3f888:	10000003 */ 	b	.L0003f898
/*    3f88c:	00801025 */ 	or	$v0,$a0,$zero
/*    3f890:	10000001 */ 	b	.L0003f898
/*    3f894:	00000000 */ 	nop
.L0003f898:
/*    3f898:	03e00008 */ 	jr	$ra
/*    3f89c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

//s16 _getVol(s16 ivol, s32 samples, s16 ratem, u16 ratel)
//{
//	s32 sp4;
//
//	/*
//	 * Rate values are actually rate^8
//	 */
//	samples >>= 3;
//
//	if (samples == 0) {
//		return ivol;
//	}
//
//	sp4 = ratel * samples;
//	sp4 >>= 16;
//	sp4 += ratem * samples;
//
//	ivol += sp4;
//
//	return ivol;
//}
