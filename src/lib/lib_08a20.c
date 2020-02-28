#include <ultra64.h>
#include "boot/boot.h"
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_03ee0.h"
#include "lib/lib_08a20.h"
#include "lib/lib_09660.h"
#include "lib/lib_2faf0.h"
#include "lib/lib_2fba0.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48650.h"
#include "lib/lib_490b0.h"
#include "lib/lib_4ae00.h"
#include "lib/lib_4b480.h"
#include "lib/lib_4e270.h"
#include "lib/lib_4e3c0.h"
#include "lib/lib_4e470.h"
#include "types.h"

GLOBAL_ASM(
glabel func00008a20
/*     8a20:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     8a24:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     8a28:	24040004 */ 	addiu	$a0,$zero,0x4
/*     8a2c:	0c00062b */ 	jal	func000018ac
/*     8a30:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     8a34:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     8a38:	3c018009 */ 	lui	$at,0x8009
/*     8a3c:	ac2218f0 */ 	sw	$v0,0x18f0($at)
/*     8a40:	03e00008 */ 	jr	$ra
/*     8a44:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func00008a48
/*     8a48:	27bdfa40 */ 	addiu	$sp,$sp,-1472
/*     8a4c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     8a50:	afa405c0 */ 	sw	$a0,0x5c0($sp)
/*     8a54:	afb50030 */ 	sw	$s5,0x30($sp)
/*     8a58:	afb4002c */ 	sw	$s4,0x2c($sp)
/*     8a5c:	afb30028 */ 	sw	$s3,0x28($sp)
/*     8a60:	afb20024 */ 	sw	$s2,0x24($sp)
/*     8a64:	afb10020 */ 	sw	$s1,0x20($sp)
/*     8a68:	afb0001c */ 	sw	$s0,0x1c($sp)
/*     8a6c:	0c01389c */ 	jal	func0004e270
/*     8a70:	24045604 */ 	addiu	$a0,$zero,0x5604
/*     8a74:	44822000 */ 	mtc1	$v0,$f4
/*     8a78:	3c0141f0 */ 	lui	$at,0x41f0
/*     8a7c:	44814000 */ 	mtc1	$at,$f8
/*     8a80:	468021a0 */ 	cvt.s.w	$f6,$f4
/*     8a84:	8fa505c0 */ 	lw	$a1,0x5c0($sp)
/*     8a88:	3c0e7001 */ 	lui	$t6,0x7001
/*     8a8c:	3c158009 */ 	lui	$s5,%hi(g_Is4Mb)
/*     8a90:	25ce9844 */ 	addiu	$t6,$t6,-26556
/*     8a94:	26b50af0 */ 	addiu	$s5,$s5,%lo(g_Is4Mb)
/*     8a98:	46083083 */ 	div.s	$f2,$f6,$f8
/*     8a9c:	aca20018 */ 	sw	$v0,0x18($a1)
/*     8aa0:	acae0010 */ 	sw	$t6,0x10($a1)
/*     8aa4:	92af0000 */ 	lbu	$t7,0x0($s5)
/*     8aa8:	24140001 */ 	addiu	$s4,$zero,0x1
/*     8aac:	240400b8 */ 	addiu	$a0,$zero,0xb8
/*     8ab0:	168f0006 */ 	bne	$s4,$t7,.L00008acc
/*     8ab4:	46001006 */ 	mov.s	$f0,$f2
/*     8ab8:	3c013f00 */ 	lui	$at,0x3f00
/*     8abc:	44815000 */ 	mtc1	$at,$f10
/*     8ac0:	00000000 */ 	sll	$zero,$zero,0x0
/*     8ac4:	460a1002 */ 	mul.s	$f0,$f2,$f10
/*     8ac8:	00000000 */ 	sll	$zero,$zero,0x0
.L00008acc:
/*     8acc:	4600040d */ 	trunc.w.s	$f16,$f0
/*     8ad0:	3c038009 */ 	lui	$v1,%hi(var800918e0)
/*     8ad4:	246318e0 */ 	addiu	$v1,$v1,%lo(var800918e0)
/*     8ad8:	44198000 */ 	mfc1	$t9,$f16
/*     8adc:	00000000 */ 	sll	$zero,$zero,0x0
/*     8ae0:	03201025 */ 	or	$v0,$t9,$zero
/*     8ae4:	44829000 */ 	mtc1	$v0,$f18
/*     8ae8:	ac790000 */ 	sw	$t9,0x0($v1)
/*     8aec:	07210005 */ 	bgez	$t9,.L00008b04
/*     8af0:	46809120 */ 	cvt.s.w	$f4,$f18
/*     8af4:	3c014f80 */ 	lui	$at,0x4f80
/*     8af8:	44813000 */ 	mtc1	$at,$f6
/*     8afc:	00000000 */ 	sll	$zero,$zero,0x0
/*     8b00:	46062100 */ 	add.s	$f4,$f4,$f6
.L00008b04:
/*     8b04:	4600203c */ 	c.lt.s	$f4,$f0
/*     8b08:	00000000 */ 	sll	$zero,$zero,0x0
/*     8b0c:	45000004 */ 	bc1f	.L00008b20
/*     8b10:	00000000 */ 	sll	$zero,$zero,0x0
/*     8b14:	24480001 */ 	addiu	$t0,$v0,0x1
/*     8b18:	ac680000 */ 	sw	$t0,0x0($v1)
/*     8b1c:	01001025 */ 	or	$v0,$t0,$zero
.L00008b20:
/*     8b20:	0044001b */ 	divu	$zero,$v0,$a0
/*     8b24:	00004812 */ 	mflo	$t1
/*     8b28:	3c018009 */ 	lui	$at,0x8009
/*     8b2c:	14800002 */ 	bnez	$a0,.L00008b38
/*     8b30:	00000000 */ 	sll	$zero,$zero,0x0
/*     8b34:	0007000d */ 	break	0x7
.L00008b38:
/*     8b38:	01240019 */ 	multu	$t1,$a0
/*     8b3c:	00005012 */ 	mflo	$t2
/*     8b40:	254b00b8 */ 	addiu	$t3,$t2,0xb8
/*     8b44:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*     8b48:	256cff48 */ 	addiu	$t4,$t3,-184
/*     8b4c:	ac2c18dc */ 	sw	$t4,0x18dc($at)
/*     8b50:	3c018009 */ 	lui	$at,0x8009
/*     8b54:	256d0050 */ 	addiu	$t5,$t3,0x50
/*     8b58:	ac2d18e4 */ 	sw	$t5,0x18e4($at)
/*     8b5c:	3c018006 */ 	lui	$at,0x8006
/*     8b60:	0c002598 */ 	jal	func00009660
/*     8b64:	a020cf94 */ 	sb	$zero,-0x306c($at)
/*     8b68:	3c048009 */ 	lui	$a0,%hi(var80091848)
/*     8b6c:	3c058009 */ 	lui	$a1,%hi(var80091860)
/*     8b70:	24a51860 */ 	addiu	$a1,$a1,%lo(var80091860)
/*     8b74:	24841848 */ 	addiu	$a0,$a0,%lo(var80091848)
/*     8b78:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     8b7c:	24060008 */ 	addiu	$a2,$zero,0x8
/*     8b80:	3c048009 */ 	lui	$a0,%hi(var80091810)
/*     8b84:	3c058009 */ 	lui	$a1,%hi(var80091828)
/*     8b88:	24a51828 */ 	addiu	$a1,$a1,%lo(var80091828)
/*     8b8c:	24841810 */ 	addiu	$a0,$a0,%lo(var80091810)
/*     8b90:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     8b94:	24060008 */ 	addiu	$a2,$zero,0x8
/*     8b98:	92af0000 */ 	lbu	$t7,0x0($s5)
/*     8b9c:	3c128009 */ 	lui	$s2,%hi(var800918ec)
/*     8ba0:	265218ec */ 	addiu	$s2,$s2,%lo(var800918ec)
/*     8ba4:	240e07d0 */ 	addiu	$t6,$zero,0x7d0
/*     8ba8:	168f0003 */ 	bne	$s4,$t7,.L00008bb8
/*     8bac:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*     8bb0:	000ec843 */ 	sra	$t9,$t6,0x1
/*     8bb4:	ae590000 */ 	sw	$t9,0x0($s2)
.L00008bb8:
/*     8bb8:	3c108009 */ 	lui	$s0,%hi(var800915c8)
/*     8bbc:	3c138009 */ 	lui	$s3,%hi(var800915d0)
/*     8bc0:	3c118009 */ 	lui	$s1,%hi(var800951f0)
/*     8bc4:	263151f0 */ 	addiu	$s1,$s1,%lo(var800951f0)
/*     8bc8:	267315d0 */ 	addiu	$s3,$s3,%lo(var800915d0)
/*     8bcc:	261015c8 */ 	addiu	$s0,$s0,%lo(var800915c8)
.L00008bd0:
/*     8bd0:	8e480000 */ 	lw	$t0,0x0($s2)
/*     8bd4:	00002025 */ 	or	$a0,$zero,$zero
/*     8bd8:	00002825 */ 	or	$a1,$zero,$zero
/*     8bdc:	000848c0 */ 	sll	$t1,$t0,0x3
/*     8be0:	afa90010 */ 	sw	$t1,0x10($sp)
/*     8be4:	02203025 */ 	or	$a2,$s1,$zero
/*     8be8:	0c00bec5 */ 	jal	func0002fb14
/*     8bec:	02803825 */ 	or	$a3,$s4,$zero
/*     8bf0:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8bf4:	0213082b */ 	sltu	$at,$s0,$s3
/*     8bf8:	1420fff5 */ 	bnez	$at,.L00008bd0
/*     8bfc:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*     8c00:	3c108009 */ 	lui	$s0,%hi(var800915c8)
/*     8c04:	3c128009 */ 	lui	$s2,%hi(var800915d4)
/*     8c08:	265215d4 */ 	addiu	$s2,$s2,%lo(var800915d4)
/*     8c0c:	261015c8 */ 	addiu	$s0,$s0,%lo(var800915c8)
.L00008c10:
/*     8c10:	240a0060 */ 	addiu	$t2,$zero,0x60
/*     8c14:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     8c18:	00002025 */ 	or	$a0,$zero,$zero
/*     8c1c:	00002825 */ 	or	$a1,$zero,$zero
/*     8c20:	02203025 */ 	or	$a2,$s1,$zero
/*     8c24:	0c00bec5 */ 	jal	func0002fb14
/*     8c28:	02803825 */ 	or	$a3,$s4,$zero
/*     8c2c:	ae020008 */ 	sw	$v0,0x8($s0)
/*     8c30:	a4400004 */ 	sh	$zero,0x4($v0)
/*     8c34:	240b0c00 */ 	addiu	$t3,$zero,0xc00
/*     8c38:	afab0010 */ 	sw	$t3,0x10($sp)
/*     8c3c:	00002025 */ 	or	$a0,$zero,$zero
/*     8c40:	00002825 */ 	or	$a1,$zero,$zero
/*     8c44:	02203025 */ 	or	$a2,$s1,$zero
/*     8c48:	0c00bec5 */ 	jal	func0002fb14
/*     8c4c:	02803825 */ 	or	$a3,$s4,$zero
/*     8c50:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*     8c54:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8c58:	0212082b */ 	sltu	$at,$s0,$s2
/*     8c5c:	1420ffec */ 	bnez	$at,.L00008c10
/*     8c60:	ad820000 */ 	sw	$v0,0x0($t4)
/*     8c64:	3c0e8006 */ 	lui	$t6,%hi(var8005cf98)
/*     8c68:	25cecf98 */ 	addiu	$t6,$t6,%lo(var8005cf98)
/*     8c6c:	27a201c0 */ 	addiu	$v0,$sp,0x1c0
/*     8c70:	27a30090 */ 	addiu	$v1,$sp,0x90
/*     8c74:	27a50198 */ 	addiu	$a1,$sp,0x198
/*     8c78:	27a60068 */ 	addiu	$a2,$sp,0x68
/*     8c7c:	25d80024 */ 	addiu	$t8,$t6,0x24
/*     8c80:	27ad0590 */ 	addiu	$t5,$sp,0x590
.L00008c84:
/*     8c84:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8c88:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8c8c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8c90:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*     8c94:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8c98:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*     8c9c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8ca0:	15d8fff8 */ 	bne	$t6,$t8,.L00008c84
/*     8ca4:	ada1fffc */ 	sw	$at,-0x4($t5)
/*     8ca8:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8cac:	3c088006 */ 	lui	$t0,%hi(var8005cfc0)
/*     8cb0:	2508cfc0 */ 	addiu	$t0,$t0,%lo(var8005cfc0)
/*     8cb4:	250a0024 */ 	addiu	$t2,$t0,0x24
/*     8cb8:	27b90568 */ 	addiu	$t9,$sp,0x568
/*     8cbc:	ada10000 */ 	sw	$at,0x0($t5)
.L00008cc0:
/*     8cc0:	8d010000 */ 	lw	$at,0x0($t0)
/*     8cc4:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8cc8:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8ccc:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     8cd0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8cd4:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     8cd8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8cdc:	150afff8 */ 	bne	$t0,$t2,.L00008cc0
/*     8ce0:	af21fffc */ 	sw	$at,-0x4($t9)
/*     8ce4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8ce8:	3c0c8006 */ 	lui	$t4,%hi(var8005cfe8)
/*     8cec:	258ccfe8 */ 	addiu	$t4,$t4,%lo(var8005cfe8)
/*     8cf0:	25980024 */ 	addiu	$t8,$t4,0x24
/*     8cf4:	27ab0540 */ 	addiu	$t3,$sp,0x540
/*     8cf8:	af210000 */ 	sw	$at,0x0($t9)
.L00008cfc:
/*     8cfc:	8d810000 */ 	lw	$at,0x0($t4)
/*     8d00:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8d04:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8d08:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8d0c:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8d10:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8d14:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8d18:	1598fff8 */ 	bne	$t4,$t8,.L00008cfc
/*     8d1c:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8d20:	8d810000 */ 	lw	$at,0x0($t4)
/*     8d24:	3c0d8006 */ 	lui	$t5,%hi(var8005d010)
/*     8d28:	25add010 */ 	addiu	$t5,$t5,%lo(var8005d010)
/*     8d2c:	25aa00c0 */ 	addiu	$t2,$t5,0xc0
/*     8d30:	27ae0478 */ 	addiu	$t6,$sp,0x478
/*     8d34:	ad610000 */ 	sw	$at,0x0($t3)
.L00008d38:
/*     8d38:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d3c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8d40:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8d44:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     8d48:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8d4c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     8d50:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8d54:	15aafff8 */ 	bne	$t5,$t2,.L00008d38
/*     8d58:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     8d5c:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d60:	8daa0004 */ 	lw	$t2,0x4($t5)
/*     8d64:	3c198006 */ 	lui	$t9,%hi(var8005d0d8)
/*     8d68:	2739d0d8 */ 	addiu	$t9,$t9,%lo(var8005d0d8)
/*     8d6c:	27380048 */ 	addiu	$t8,$t9,0x48
/*     8d70:	27a80430 */ 	addiu	$t0,$sp,0x430
/*     8d74:	adc10000 */ 	sw	$at,0x0($t6)
/*     8d78:	adca0004 */ 	sw	$t2,0x4($t6)
.L00008d7c:
/*     8d7c:	8f210000 */ 	lw	$at,0x0($t9)
/*     8d80:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8d84:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8d88:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*     8d8c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     8d90:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*     8d94:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     8d98:	1738fff8 */ 	bne	$t9,$t8,.L00008d7c
/*     8d9c:	ad01fffc */ 	sw	$at,-0x4($t0)
/*     8da0:	3c0b8006 */ 	lui	$t3,%hi(var8005d120)
/*     8da4:	256bd120 */ 	addiu	$t3,$t3,%lo(var8005d120)
/*     8da8:	256a0060 */ 	addiu	$t2,$t3,0x60
/*     8dac:	27ac03c8 */ 	addiu	$t4,$sp,0x3c8
.L00008db0:
/*     8db0:	8d610000 */ 	lw	$at,0x0($t3)
/*     8db4:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8db8:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8dbc:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8dc0:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*     8dc4:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8dc8:	8d61fffc */ 	lw	$at,-0x4($t3)
/*     8dcc:	156afff8 */ 	bne	$t3,$t2,.L00008db0
/*     8dd0:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     8dd4:	8d610000 */ 	lw	$at,0x0($t3)
/*     8dd8:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*     8ddc:	3c0e8006 */ 	lui	$t6,%hi(var8005d188)
/*     8de0:	25ced188 */ 	addiu	$t6,$t6,%lo(var8005d188)
/*     8de4:	25d80060 */ 	addiu	$t8,$t6,0x60
/*     8de8:	27ad0360 */ 	addiu	$t5,$sp,0x360
/*     8dec:	ad810000 */ 	sw	$at,0x0($t4)
/*     8df0:	ad8a0004 */ 	sw	$t2,0x4($t4)
.L00008df4:
/*     8df4:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8df8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8dfc:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8e00:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*     8e04:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8e08:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*     8e0c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8e10:	15d8fff8 */ 	bne	$t6,$t8,.L00008df4
/*     8e14:	ada1fffc */ 	sw	$at,-0x4($t5)
/*     8e18:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8e1c:	8dd80004 */ 	lw	$t8,0x4($t6)
/*     8e20:	3c088006 */ 	lui	$t0,%hi(var8005d1f0)
/*     8e24:	2508d1f0 */ 	addiu	$t0,$t0,%lo(var8005d1f0)
/*     8e28:	250a0060 */ 	addiu	$t2,$t0,0x60
/*     8e2c:	27b902f8 */ 	addiu	$t9,$sp,0x2f8
/*     8e30:	ada10000 */ 	sw	$at,0x0($t5)
/*     8e34:	adb80004 */ 	sw	$t8,0x4($t5)
.L00008e38:
/*     8e38:	8d010000 */ 	lw	$at,0x0($t0)
/*     8e3c:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8e40:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8e44:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     8e48:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8e4c:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     8e50:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8e54:	150afff8 */ 	bne	$t0,$t2,.L00008e38
/*     8e58:	af21fffc */ 	sw	$at,-0x4($t9)
/*     8e5c:	8d010000 */ 	lw	$at,0x0($t0)
/*     8e60:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*     8e64:	3c0c8006 */ 	lui	$t4,%hi(var8005d258)
/*     8e68:	258cd258 */ 	addiu	$t4,$t4,%lo(var8005d258)
/*     8e6c:	25980084 */ 	addiu	$t8,$t4,0x84
/*     8e70:	27ab0270 */ 	addiu	$t3,$sp,0x270
/*     8e74:	af210000 */ 	sw	$at,0x0($t9)
/*     8e78:	af2a0004 */ 	sw	$t2,0x4($t9)
.L00008e7c:
/*     8e7c:	8d810000 */ 	lw	$at,0x0($t4)
/*     8e80:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8e84:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8e88:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8e8c:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8e90:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8e94:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8e98:	1598fff8 */ 	bne	$t4,$t8,.L00008e7c
/*     8e9c:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8ea0:	8d810000 */ 	lw	$at,0x0($t4)
/*     8ea4:	3c0d8006 */ 	lui	$t5,%hi(var8005d2e0)
/*     8ea8:	25add2e0 */ 	addiu	$t5,$t5,%lo(var8005d2e0)
/*     8eac:	25aa0024 */ 	addiu	$t2,$t5,0x24
/*     8eb0:	27ae0248 */ 	addiu	$t6,$sp,0x248
/*     8eb4:	ad610000 */ 	sw	$at,0x0($t3)
.L00008eb8:
/*     8eb8:	8da10000 */ 	lw	$at,0x0($t5)
/*     8ebc:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8ec0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8ec4:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     8ec8:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8ecc:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     8ed0:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8ed4:	15aafff8 */ 	bne	$t5,$t2,.L00008eb8
/*     8ed8:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     8edc:	8da10000 */ 	lw	$at,0x0($t5)
/*     8ee0:	3c088006 */ 	lui	$t0,%hi(var8005d308)
/*     8ee4:	2508d308 */ 	addiu	$t0,$t0,%lo(var8005d308)
/*     8ee8:	250f0084 */ 	addiu	$t7,$t0,0x84
/*     8eec:	0040c025 */ 	or	$t8,$v0,$zero
/*     8ef0:	adc10000 */ 	sw	$at,0x0($t6)
.L00008ef4:
/*     8ef4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8ef8:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8efc:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8f00:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     8f04:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8f08:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     8f0c:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8f10:	150ffff8 */ 	bne	$t0,$t7,.L00008ef4
/*     8f14:	af01fffc */ 	sw	$at,-0x4($t8)
/*     8f18:	8d010000 */ 	lw	$at,0x0($t0)
/*     8f1c:	3c0c8006 */ 	lui	$t4,%hi(var8005d390)
/*     8f20:	258cd390 */ 	addiu	$t4,$t4,%lo(var8005d390)
/*     8f24:	25890024 */ 	addiu	$t1,$t4,0x24
/*     8f28:	00a05025 */ 	or	$t2,$a1,$zero
/*     8f2c:	af010000 */ 	sw	$at,0x0($t8)
.L00008f30:
/*     8f30:	8d810000 */ 	lw	$at,0x0($t4)
/*     8f34:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8f38:	254a000c */ 	addiu	$t2,$t2,0xc
/*     8f3c:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*     8f40:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8f44:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*     8f48:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8f4c:	1589fff8 */ 	bne	$t4,$t1,.L00008f30
/*     8f50:	ad41fffc */ 	sw	$at,-0x4($t2)
/*     8f54:	8d810000 */ 	lw	$at,0x0($t4)
/*     8f58:	3c0d8006 */ 	lui	$t5,%hi(var8005d3b8)
/*     8f5c:	25add3b8 */ 	addiu	$t5,$t5,%lo(var8005d3b8)
/*     8f60:	25b90108 */ 	addiu	$t9,$t5,0x108
/*     8f64:	00607825 */ 	or	$t7,$v1,$zero
/*     8f68:	ad410000 */ 	sw	$at,0x0($t2)
.L00008f6c:
/*     8f6c:	8da10000 */ 	lw	$at,0x0($t5)
/*     8f70:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8f74:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     8f78:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*     8f7c:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8f80:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*     8f84:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8f88:	15b9fff8 */ 	bne	$t5,$t9,.L00008f6c
/*     8f8c:	ade1fffc */ 	sw	$at,-0x4($t7)
/*     8f90:	3c088006 */ 	lui	$t0,%hi(var8005d4c0)
/*     8f94:	2508d4c0 */ 	addiu	$t0,$t0,%lo(var8005d4c0)
/*     8f98:	250b0024 */ 	addiu	$t3,$t0,0x24
/*     8f9c:	00c04825 */ 	or	$t1,$a2,$zero
.L00008fa0:
/*     8fa0:	8d010000 */ 	lw	$at,0x0($t0)
/*     8fa4:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8fa8:	2529000c */ 	addiu	$t1,$t1,0xc
/*     8fac:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*     8fb0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8fb4:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*     8fb8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8fbc:	150bfff8 */ 	bne	$t0,$t3,.L00008fa0
/*     8fc0:	ad21fffc */ 	sw	$at,-0x4($t1)
/*     8fc4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8fc8:	3c0a8006 */ 	lui	$t2,%hi(var8005d4e8)
/*     8fcc:	254ad4e8 */ 	addiu	$t2,$t2,%lo(var8005d4e8)
/*     8fd0:	25590024 */ 	addiu	$t9,$t2,0x24
/*     8fd4:	27ac0040 */ 	addiu	$t4,$sp,0x40
/*     8fd8:	ad210000 */ 	sw	$at,0x0($t1)
.L00008fdc:
/*     8fdc:	8d410000 */ 	lw	$at,0x0($t2)
/*     8fe0:	254a000c */ 	addiu	$t2,$t2,0xc
/*     8fe4:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8fe8:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8fec:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*     8ff0:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8ff4:	8d41fffc */ 	lw	$at,-0x4($t2)
/*     8ff8:	1559fff8 */ 	bne	$t2,$t9,.L00008fdc
/*     8ffc:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     9000:	8d410000 */ 	lw	$at,0x0($t2)
/*     9004:	ad810000 */ 	sw	$at,0x0($t4)
/*     9008:	92ad0000 */ 	lbu	$t5,0x0($s5)
/*     900c:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
/*     9010:	568d0004 */ 	bnel	$s4,$t5,.L00009024
/*     9014:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
/*     9018:	10000003 */ 	beqz	$zero,.L00009028
/*     901c:	ace20020 */ 	sw	$v0,0x20($a3)
/*     9020:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
.L00009024:
/*     9024:	ace30020 */ 	sw	$v1,0x20($a3)
.L00009028:
/*     9028:	3c048009 */ 	lui	$a0,%hi(var80094ea8)
/*     902c:	24844ea8 */ 	addiu	$a0,$a0,%lo(var80094ea8)
/*     9030:	8c820000 */ 	lw	$v0,0x0($a0)
/*     9034:	28410002 */ 	slti	$at,$v0,0x2
/*     9038:	14200010 */ 	bnez	$at,.L0000907c
/*     903c:	28410002 */ 	slti	$at,$v0,0x2
/*     9040:	1420000e */ 	bnez	$at,.L0000907c
/*     9044:	02801825 */ 	or	$v1,$s4,$zero
/*     9048:	24e20004 */ 	addiu	$v0,$a3,0x4
/*     904c:	92b80000 */ 	lbu	$t8,0x0($s5)
.L00009050:
/*     9050:	56980004 */ 	bnel	$s4,$t8,.L00009064
/*     9054:	ac460020 */ 	sw	$a2,0x20($v0)
/*     9058:	10000002 */ 	beqz	$zero,.L00009064
/*     905c:	ac450020 */ 	sw	$a1,0x20($v0)
/*     9060:	ac460020 */ 	sw	$a2,0x20($v0)
.L00009064:
/*     9064:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*     9068:	24630001 */ 	addiu	$v1,$v1,0x1
/*     906c:	24420004 */ 	addiu	$v0,$v0,0x4
/*     9070:	006b082a */ 	slt	$at,$v1,$t3
/*     9074:	5420fff6 */ 	bnezl	$at,.L00009050
/*     9078:	92b80000 */ 	lbu	$t8,0x0($s5)
.L0000907c:
/*     907c:	3c048009 */ 	lui	$a0,%hi(var80091880)
/*     9080:	24841880 */ 	addiu	$a0,$a0,%lo(var80091880)
/*     9084:	0c00bee8 */ 	jal	func0002fba0
/*     9088:	00e02825 */ 	or	$a1,$a3,$zero
/*     908c:	00002025 */ 	or	$a0,$zero,$zero
/*     9090:	0c00c2ff */ 	jal	func00030bfc
/*     9094:	2405003c */ 	addiu	$a1,$zero,0x3c
/*     9098:	3c088009 */ 	lui	$t0,0x8009
/*     909c:	8d0818f0 */ 	lw	$t0,0x18f0($t0)
/*     90a0:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*     90a4:	3c067001 */ 	lui	$a2,0x7001
/*     90a8:	24090014 */ 	addiu	$t1,$zero,0x14
/*     90ac:	afa90014 */ 	sw	$t1,0x14($sp)
/*     90b0:	24c69154 */ 	addiu	$a2,$a2,-28332
/*     90b4:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*     90b8:	24050004 */ 	addiu	$a1,$zero,0x4
/*     90bc:	00003825 */ 	or	$a3,$zero,$zero
/*     90c0:	0c000fb8 */ 	jal	func00003ee0
/*     90c4:	afa80010 */ 	sw	$t0,0x10($sp)
/*     90c8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     90cc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*     90d0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*     90d4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*     90d8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*     90dc:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*     90e0:	8fb50030 */ 	lw	$s5,0x30($sp)
/*     90e4:	03e00008 */ 	jr	$ra
/*     90e8:	27bd05c0 */ 	addiu	$sp,$sp,0x5c0
);

GLOBAL_ASM(
glabel func000090ec
/*     90ec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     90f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     90f4:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*     90f8:	0c01207c */ 	jal	osStartThread
/*     90fc:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*     9100:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     9104:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     9108:	3c018006 */ 	lui	$at,0x8006
/*     910c:	a02ed510 */ 	sb	$t6,-0x2af0($at)
/*     9110:	03e00008 */ 	jr	$ra
/*     9114:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func00009118
/*     9118:	3c028009 */ 	lui	$v0,%hi(var80091810)
/*     911c:	03e00008 */ 	jr	$ra
/*     9120:	24421810 */ 	addiu	$v0,$v0,%lo(var80091810)
);

GLOBAL_ASM(
glabel func00009124
/*     9124:	3c0e8006 */ 	lui	$t6,0x8006
/*     9128:	81ced510 */ 	lb	$t6,-0x2af0($t6)
/*     912c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     9130:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     9134:	11c00003 */ 	beqz	$t6,.L00009144
/*     9138:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*     913c:	0c0120dc */ 	jal	func00048370
/*     9140:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
.L00009144:
/*     9144:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     9148:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     914c:	03e00008 */ 	jr	$ra
/*     9150:	00000000 */ 	sll	$zero,$zero,0x0
/*     9154:	27bdff90 */ 	addiu	$sp,$sp,-112
/*     9158:	3c078009 */ 	lui	$a3,0x8009
/*     915c:	90e70af0 */ 	lbu	$a3,0xaf0($a3)
/*     9160:	afa40070 */ 	sw	$a0,0x70($sp)
/*     9164:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     9168:	38ee0001 */ 	xori	$t6,$a3,0x1
/*     916c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     9170:	afb20020 */ 	sw	$s2,0x20($sp)
/*     9174:	2dce0001 */ 	sltiu	$t6,$t6,0x1
/*     9178:	3c048009 */ 	lui	$a0,%hi(var8008dbd0)
/*     917c:	3c058009 */ 	lui	$a1,%hi(var800918d0)
/*     9180:	3c068009 */ 	lui	$a2,%hi(var80091810)
/*     9184:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     9188:	afb70034 */ 	sw	$s7,0x34($sp)
/*     918c:	afb60030 */ 	sw	$s6,0x30($sp)
/*     9190:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     9194:	afb40028 */ 	sw	$s4,0x28($sp)
/*     9198:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     919c:	afb00018 */ 	sw	$s0,0x18($sp)
/*     91a0:	00009025 */ 	or	$s2,$zero,$zero
/*     91a4:	00009825 */ 	or	$s3,$zero,$zero
/*     91a8:	afa00064 */ 	sw	$zero,0x64($sp)
/*     91ac:	afa00060 */ 	sw	$zero,0x60($sp)
/*     91b0:	24c61810 */ 	addiu	$a2,$a2,%lo(var80091810)
/*     91b4:	24a518d0 */ 	addiu	$a1,$a1,%lo(var800918d0)
/*     91b8:	2484dbd0 */ 	addiu	$a0,$a0,%lo(var8008dbd0)
/*     91bc:	0c00078c */ 	jal	func00001e30
/*     91c0:	2dc70001 */ 	sltiu	$a3,$t6,0x1
/*     91c4:	3c158009 */ 	lui	$s5,%hi(var80091590)
/*     91c8:	3c148009 */ 	lui	$s4,%hi(var80091588)
/*     91cc:	3c118009 */ 	lui	$s1,%hi(var80091568)
/*     91d0:	3c108009 */ 	lui	$s0,%hi(var80091580)
/*     91d4:	26101580 */ 	addiu	$s0,$s0,%lo(var80091580)
/*     91d8:	26311568 */ 	addiu	$s1,$s1,%lo(var80091568)
/*     91dc:	26941588 */ 	addiu	$s4,$s4,%lo(var80091588)
/*     91e0:	26b51590 */ 	addiu	$s5,$s5,%lo(var80091590)
/*     91e4:	241e0005 */ 	addiu	$s8,$zero,0x5
/*     91e8:	24170004 */ 	addiu	$s7,$zero,0x4
/*     91ec:	27b60064 */ 	addiu	$s6,$sp,0x64
.L000091f0:
/*     91f0:	3c048009 */ 	lui	$a0,%hi(var80091810)
/*     91f4:	24841810 */ 	addiu	$a0,$a0,%lo(var80091810)
/*     91f8:	02c02825 */ 	or	$a1,$s6,$zero
/*     91fc:	0c0121bc */ 	jal	osRecvMesg
/*     9200:	24060001 */ 	addiu	$a2,$zero,0x1
/*     9204:	8faf0064 */ 	lw	$t7,0x64($sp)
/*     9208:	85e70000 */ 	lh	$a3,0x0($t7)
/*     920c:	10f70007 */ 	beq	$a3,$s7,.L0000922c
/*     9210:	00000000 */ 	sll	$zero,$zero,0x0
/*     9214:	10fe0078 */ 	beq	$a3,$s8,.L000093f8
/*     9218:	2401000a */ 	addiu	$at,$zero,0xa
/*     921c:	50e10079 */ 	beql	$a3,$at,.L00009404
/*     9220:	24130001 */ 	addiu	$s3,$zero,0x1
/*     9224:	10000077 */ 	beqz	$zero,.L00009404
/*     9228:	00000000 */ 	sll	$zero,$zero,0x0
.L0000922c:
/*     922c:	0c012448 */ 	jal	func00049120
/*     9230:	00000000 */ 	sll	$zero,$zero,0x0
/*     9234:	ae820000 */ 	sw	$v0,0x0($s4)
/*     9238:	ae830004 */ 	sw	$v1,0x4($s4)
/*     923c:	0c0026a8 */ 	jal	func00009aa0
/*     9240:	3c040003 */ 	lui	$a0,0x3
/*     9244:	3c188009 */ 	lui	$t8,0x8009
/*     9248:	8f182828 */ 	lw	$t8,0x2828($t8)
/*     924c:	24010003 */ 	addiu	$at,$zero,0x3
/*     9250:	3c048009 */ 	lui	$a0,0x8009
/*     9254:	0301001b */ 	divu	$zero,$t8,$at
/*     9258:	0000c810 */ 	mfhi	$t9
/*     925c:	00194080 */ 	sll	$t0,$t9,0x2
/*     9260:	00882021 */ 	addu	$a0,$a0,$t0
/*     9264:	8c8415d0 */ 	lw	$a0,0x15d0($a0)
/*     9268:	0c002512 */ 	jal	func00009448
/*     926c:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     9270:	0c002682 */ 	jal	func00009a08
/*     9274:	00000000 */ 	sll	$zero,$zero,0x0
/*     9278:	26520001 */ 	addiu	$s2,$s2,0x1
/*     927c:	0c0026a8 */ 	jal	func00009aa0
/*     9280:	3c040006 */ 	lui	$a0,0x6
/*     9284:	0c012448 */ 	jal	func00049120
/*     9288:	00000000 */ 	sll	$zero,$zero,0x0
/*     928c:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*     9290:	8e8d0004 */ 	lw	$t5,0x4($s4)
/*     9294:	aea20000 */ 	sw	$v0,0x0($s5)
/*     9298:	004c4023 */ 	subu	$t0,$v0,$t4
/*     929c:	006d082b */ 	sltu	$at,$v1,$t5
/*     92a0:	01014023 */ 	subu	$t0,$t0,$at
/*     92a4:	aea30004 */ 	sw	$v1,0x4($s5)
/*     92a8:	3c018009 */ 	lui	$at,0x8009
/*     92ac:	006d4823 */ 	subu	$t1,$v1,$t5
/*     92b0:	ac291574 */ 	sw	$t1,0x1574($at)
/*     92b4:	ac281570 */ 	sw	$t0,0x1570($at)
/*     92b8:	240100f0 */ 	addiu	$at,$zero,0xf0
/*     92bc:	0241001a */ 	div	$zero,$s2,$at
/*     92c0:	00005010 */ 	mfhi	$t2
/*     92c4:	afa90044 */ 	sw	$t1,0x44($sp)
/*     92c8:	afa80040 */ 	sw	$t0,0x40($sp)
/*     92cc:	afa20050 */ 	sw	$v0,0x50($sp)
/*     92d0:	afa30054 */ 	sw	$v1,0x54($sp)
/*     92d4:	afac0048 */ 	sw	$t4,0x48($sp)
/*     92d8:	1540001c */ 	bnez	$t2,.L0000934c
/*     92dc:	afad004c */ 	sw	$t5,0x4c($sp)
/*     92e0:	8e040000 */ 	lw	$a0,0x0($s0)
/*     92e4:	8e050004 */ 	lw	$a1,0x4($s0)
/*     92e8:	24060000 */ 	addiu	$a2,$zero,0x0
/*     92ec:	0c012b9a */ 	jal	func0004ae68
/*     92f0:	240700f0 */ 	addiu	$a3,$zero,0xf0
/*     92f4:	3c018009 */ 	lui	$at,0x8009
/*     92f8:	ac221578 */ 	sw	$v0,0x1578($at)
/*     92fc:	ac23157c */ 	sw	$v1,0x157c($at)
/*     9300:	8e890004 */ 	lw	$t1,0x4($s4)
/*     9304:	8e880000 */ 	lw	$t0,0x0($s4)
/*     9308:	8eb90004 */ 	lw	$t9,0x4($s5)
/*     930c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*     9310:	240c0000 */ 	addiu	$t4,$zero,0x0
/*     9314:	0329082b */ 	sltu	$at,$t9,$t1
/*     9318:	03085023 */ 	subu	$t2,$t8,$t0
/*     931c:	01415023 */ 	subu	$t2,$t2,$at
/*     9320:	240d0000 */ 	addiu	$t5,$zero,0x0
/*     9324:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     9328:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     932c:	03295823 */ 	subu	$t3,$t9,$t1
/*     9330:	afab0044 */ 	sw	$t3,0x44($sp)
/*     9334:	ae2f0004 */ 	sw	$t7,0x4($s1)
/*     9338:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*     933c:	ae0d0004 */ 	sw	$t5,0x4($s0)
/*     9340:	afaa0040 */ 	sw	$t2,0x40($sp)
/*     9344:	10000011 */ 	beqz	$zero,.L0000938c
/*     9348:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0000934c:
/*     934c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*     9350:	8faf0054 */ 	lw	$t7,0x54($sp)
/*     9354:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*     9358:	8fae0050 */ 	lw	$t6,0x50($sp)
/*     935c:	01afc821 */ 	addu	$t9,$t5,$t7
/*     9360:	8fa80048 */ 	lw	$t0,0x48($sp)
/*     9364:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*     9368:	032f082b */ 	sltu	$at,$t9,$t7
/*     936c:	002cc021 */ 	addu	$t8,$at,$t4
/*     9370:	030ec021 */ 	addu	$t8,$t8,$t6
/*     9374:	03085023 */ 	subu	$t2,$t8,$t0
/*     9378:	0329082b */ 	sltu	$at,$t9,$t1
/*     937c:	01415023 */ 	subu	$t2,$t2,$at
/*     9380:	03295823 */ 	subu	$t3,$t9,$t1
/*     9384:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*     9388:	ae0a0000 */ 	sw	$t2,0x0($s0)
.L0000938c:
/*     938c:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*     9390:	8fae0040 */ 	lw	$t6,0x40($sp)
/*     9394:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*     9398:	8faf0044 */ 	lw	$t7,0x44($sp)
/*     939c:	01cc082b */ 	sltu	$at,$t6,$t4
/*     93a0:	14200008 */ 	bnez	$at,.L000093c4
/*     93a4:	3c188006 */ 	lui	$t8,0x8006
/*     93a8:	018e082b */ 	sltu	$at,$t4,$t6
/*     93ac:	14200003 */ 	bnez	$at,.L000093bc
/*     93b0:	01af082b */ 	sltu	$at,$t5,$t7
/*     93b4:	10200003 */ 	beqz	$at,.L000093c4
/*     93b8:	00000000 */ 	sll	$zero,$zero,0x0
.L000093bc:
/*     93bc:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*     93c0:	ae2f0004 */ 	sw	$t7,0x4($s1)
.L000093c4:
/*     93c4:	8f18d514 */ 	lw	$t8,-0x2aec($t8)
/*     93c8:	3c048009 */ 	lui	$a0,%hi(var80091848)
/*     93cc:	24841848 */ 	addiu	$a0,$a0,%lo(var80091848)
/*     93d0:	17000003 */ 	bnez	$t8,.L000093e0
/*     93d4:	27a50060 */ 	addiu	$a1,$sp,0x60
/*     93d8:	0c0121bc */ 	jal	osRecvMesg
/*     93dc:	24060001 */ 	addiu	$a2,$zero,0x1
.L000093e0:
/*     93e0:	3c018006 */ 	lui	$at,0x8006
/*     93e4:	ac20d514 */ 	sw	$zero,-0x2aec($at)
/*     93e8:	0c002585 */ 	jal	func00009614
/*     93ec:	8fa40060 */ 	lw	$a0,0x60($sp)
/*     93f0:	10000004 */ 	beqz	$zero,.L00009404
/*     93f4:	00000000 */ 	sll	$zero,$zero,0x0
.L000093f8:
/*     93f8:	10000002 */ 	beqz	$zero,.L00009404
/*     93fc:	24130001 */ 	addiu	$s3,$zero,0x1
/*     9400:	24130001 */ 	addiu	$s3,$zero,0x1
.L00009404:
/*     9404:	1260ff7a */ 	beqz	$s3,.L000091f0
/*     9408:	00000000 */ 	sll	$zero,$zero,0x0
/*     940c:	3c048009 */ 	lui	$a0,%hi(var80091880)
/*     9410:	0c00bf03 */ 	jal	func0002fc0c
/*     9414:	24841880 */ 	addiu	$a0,$a0,%lo(var80091880)
/*     9418:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     941c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     9420:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     9424:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     9428:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     942c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     9430:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     9434:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     9438:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     943c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     9440:	03e00008 */ 	jr	$ra
/*     9444:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func00009448
/*     9448:	3c068009 */ 	lui	$a2,0x8009
/*     944c:	8cc618f4 */ 	lw	$a2,0x18f4($a2)
/*     9450:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     9454:	afb00018 */ 	sw	$s0,0x18($sp)
/*     9458:	00808025 */ 	or	$s0,$a0,$zero
/*     945c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     9460:	10c00007 */ 	beqz	$a2,.L00009480
/*     9464:	afa50034 */ 	sw	$a1,0x34($sp)
/*     9468:	3c048009 */ 	lui	$a0,%hi(var8008dbd0)
/*     946c:	3c018009 */ 	lui	$at,0x8009
/*     9470:	ac2618f4 */ 	sw	$a2,0x18f4($at)
/*     9474:	2484dbd0 */ 	addiu	$a0,$a0,%lo(var8008dbd0)
/*     9478:	0c0007ea */ 	jal	func00001fa8
/*     947c:	00c02825 */ 	or	$a1,$a2,$zero
.L00009480:
/*     9480:	0c00264f */ 	jal	func0000993c
/*     9484:	00000000 */ 	sll	$zero,$zero,0x0
/*     9488:	3c198006 */ 	lui	$t9,0x8006
/*     948c:	8f39cf90 */ 	lw	$t9,-0x3070($t9)
/*     9490:	3c0ea450 */ 	lui	$t6,0xa450
/*     9494:	3c098009 */ 	lui	$t1,0x8009
/*     9498:	00194080 */ 	sll	$t0,$t9,0x2
/*     949c:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*     94a0:	01284821 */ 	addu	$t1,$t1,$t0
/*     94a4:	8d2915c8 */ 	lw	$t1,0x15c8($t1)
/*     94a8:	000fc082 */ 	srl	$t8,$t7,0x2
/*     94ac:	afb8002c */ 	sw	$t8,0x2c($sp)
/*     94b0:	afa90024 */ 	sw	$t1,0x24($sp)
/*     94b4:	0c012d20 */ 	jal	osVirtualToPhysical
/*     94b8:	8e040000 */ 	lw	$a0,0x0($s0)
/*     94bc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*     94c0:	00403025 */ 	or	$a2,$v0,$zero
/*     94c4:	50600009 */ 	beqzl	$v1,.L000094ec
/*     94c8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     94cc:	84650004 */ 	lh	$a1,0x4($v1)
/*     94d0:	8c640000 */ 	lw	$a0,0x0($v1)
/*     94d4:	afa20028 */ 	sw	$v0,0x28($sp)
/*     94d8:	00055080 */ 	sll	$t2,$a1,0x2
/*     94dc:	0c0138f0 */ 	jal	func0004e3c0
/*     94e0:	01402825 */ 	or	$a1,$t2,$zero
/*     94e4:	8fa60028 */ 	lw	$a2,0x28($sp)
/*     94e8:	8fab002c */ 	lw	$t3,0x2c($sp)
.L000094ec:
/*     94ec:	3c058009 */ 	lui	$a1,%hi(var800918e8)
/*     94f0:	3c038006 */ 	lui	$v1,%hi(var8005cf94)
/*     94f4:	2d6100f9 */ 	sltiu	$at,$t3,0xf9
/*     94f8:	1420000b */ 	bnez	$at,.L00009528
/*     94fc:	24a518e8 */ 	addiu	$a1,$a1,%lo(var800918e8)
/*     9500:	2463cf94 */ 	addiu	$v1,$v1,%lo(var8005cf94)
/*     9504:	906c0000 */ 	lbu	$t4,0x0($v1)
/*     9508:	3c0d8009 */ 	lui	$t5,0x8009
/*     950c:	15800006 */ 	bnez	$t4,.L00009528
/*     9510:	00000000 */ 	sll	$zero,$zero,0x0
/*     9514:	8dad18dc */ 	lw	$t5,0x18dc($t5)
/*     9518:	240e0002 */ 	addiu	$t6,$zero,0x2
/*     951c:	a60d0004 */ 	sh	$t5,0x4($s0)
/*     9520:	1000000a */ 	beqz	$zero,.L0000954c
/*     9524:	a06e0000 */ 	sb	$t6,0x0($v1)
.L00009528:
/*     9528:	3c0f8009 */ 	lui	$t7,0x8009
/*     952c:	8def18e0 */ 	lw	$t7,0x18e0($t7)
/*     9530:	3c038006 */ 	lui	$v1,%hi(var8005cf94)
/*     9534:	2463cf94 */ 	addiu	$v1,$v1,%lo(var8005cf94)
/*     9538:	a60f0004 */ 	sh	$t7,0x4($s0)
/*     953c:	90620000 */ 	lbu	$v0,0x0($v1)
/*     9540:	10400002 */ 	beqz	$v0,.L0000954c
/*     9544:	2458ffff */ 	addiu	$t8,$v0,-1
/*     9548:	a0780000 */ 	sb	$t8,0x0($v1)
.L0000954c:
/*     954c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*     9550:	0c00c4b9 */ 	jal	func000312e4
/*     9554:	86070004 */ 	lh	$a3,0x4($s0)
/*     9558:	26060008 */ 	addiu	$a2,$s0,0x8
/*     955c:	3c038006 */ 	lui	$v1,%hi(var80059fe0)
/*     9560:	3c088006 */ 	lui	$t0,%hi(var8005a0b0)
/*     9564:	24639fe0 */ 	addiu	$v1,$v1,%lo(var80059fe0)
/*     9568:	24040002 */ 	addiu	$a0,$zero,0x2
/*     956c:	3c198009 */ 	lui	$t9,%hi(var80091848)
/*     9570:	2508a0b0 */ 	addiu	$t0,$t0,%lo(var8005a0b0)
/*     9574:	3c0a8006 */ 	lui	$t2,%hi(var8005b4d0)
/*     9578:	3c0b8009 */ 	lui	$t3,%hi(var8008a2d0)
/*     957c:	27391848 */ 	addiu	$t9,$t9,%lo(var80091848)
/*     9580:	01034823 */ 	subu	$t1,$t0,$v1
/*     9584:	254ab4d0 */ 	addiu	$t2,$t2,%lo(var8005b4d0)
/*     9588:	256ba2d0 */ 	addiu	$t3,$t3,%lo(var8008a2d0)
/*     958c:	240c1000 */ 	addiu	$t4,$zero,0x1000
/*     9590:	240d0800 */ 	addiu	$t5,$zero,0x800
/*     9594:	acc00000 */ 	sw	$zero,0x0($a2)
/*     9598:	acd90050 */ 	sw	$t9,0x50($a2)
/*     959c:	acd00054 */ 	sw	$s0,0x54($a2)
/*     95a0:	acc40008 */ 	sw	$a0,0x8($a2)
/*     95a4:	acc40010 */ 	sw	$a0,0x10($a2)
/*     95a8:	acc00014 */ 	sw	$zero,0x14($a2)
/*     95ac:	acc30018 */ 	sw	$v1,0x18($a2)
/*     95b0:	acc9001c */ 	sw	$t1,0x1c($a2)
/*     95b4:	acca0020 */ 	sw	$t2,0x20($a2)
/*     95b8:	accb0028 */ 	sw	$t3,0x28($a2)
/*     95bc:	accc0024 */ 	sw	$t4,0x24($a2)
/*     95c0:	accd002c */ 	sw	$t5,0x2c($a2)
/*     95c4:	8fae0024 */ 	lw	$t6,0x24($sp)
/*     95c8:	3c018009 */ 	lui	$at,0x8009
/*     95cc:	acce0040 */ 	sw	$t6,0x40($a2)
/*     95d0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*     95d4:	acc00048 */ 	sw	$zero,0x48($a2)
/*     95d8:	acc0004c */ 	sw	$zero,0x4c($a2)
/*     95dc:	004fc023 */ 	subu	$t8,$v0,$t7
/*     95e0:	0018c8c3 */ 	sra	$t9,$t8,0x3
/*     95e4:	001940c0 */ 	sll	$t0,$t9,0x3
/*     95e8:	3c028006 */ 	lui	$v0,%hi(var8005cf90)
/*     95ec:	acc80044 */ 	sw	$t0,0x44($a2)
/*     95f0:	2442cf90 */ 	addiu	$v0,$v0,%lo(var8005cf90)
/*     95f4:	8c490000 */ 	lw	$t1,0x0($v0)
/*     95f8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     95fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     9600:	392a0001 */ 	xori	$t2,$t1,0x1
/*     9604:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*     9608:	ac2618f4 */ 	sw	$a2,0x18f4($at)
/*     960c:	03e00008 */ 	jr	$ra
/*     9610:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func00009614
/*     9614:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     9618:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     961c:	0c01391c */ 	jal	func0004e470
/*     9620:	afa40018 */ 	sw	$a0,0x18($sp)
/*     9624:	00027083 */ 	sra	$t6,$v0,0x2
/*     9628:	15c00006 */ 	bnez	$t6,.L00009644
/*     962c:	3c0f8006 */ 	lui	$t7,0x8006
/*     9630:	8defd518 */ 	lw	$t7,-0x2ae8($t7)
/*     9634:	3c018006 */ 	lui	$at,0x8006
/*     9638:	55e00003 */ 	bnezl	$t7,.L00009648
/*     963c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     9640:	ac20d518 */ 	sw	$zero,-0x2ae8($at)
.L00009644:
/*     9644:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00009648:
/*     9648:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     964c:	03e00008 */ 	jr	$ra
/*     9650:	00000000 */ 	sll	$zero,$zero,0x0
/*     9654:	00000000 */ 	sll	$zero,$zero,0x0
/*     9658:	00000000 */ 	sll	$zero,$zero,0x0
/*     965c:	00000000 */ 	sll	$zero,$zero,0x0
);