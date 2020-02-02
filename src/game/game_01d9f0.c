#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "types.h"
#include "game/game_01d9f0.h"
#include "library/library_12dc0.h"

const u32 var7f1a8660[] = {0x3e8e38e4};
const u32 var7f1a8664[] = {0x3f7ae148};
const u32 var7f1a8668[] = {0x00000000};
const u32 var7f1a866c[] = {0x00000000};
const u32 var7f1a8670[] = {0x46ea6000};
const u32 var7f1a8674[] = {0xc6ea6000};
const u32 var7f1a8678[] = {0x3dcccccd};
const u32 var7f1a867c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f01d9f0
/*  f01d9f0:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f01d9f4:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f01d9f8:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f01d9fc:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f01da00:	3c017f1b */ 	lui	$at,%hi(var7f1a8660)
/*  f01da04:	c682004c */ 	lwc1	$f2,0x4c($s4)
/*  f01da08:	c4248660 */ 	lwc1	$f4,%lo(var7f1a8660)($at)
/*  f01da0c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f01da10:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f01da14:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f01da18:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f01da1c:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f01da20:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f01da24:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f01da28:	c4800014 */ 	lwc1	$f0,0x14($a0)
/*  f01da2c:	3c013f00 */ 	lui	$at,0x3f00
/*  f01da30:	44814000 */ 	mtc1	$at,$f8
/*  f01da34:	46060301 */ 	sub.s	$f12,$f0,$f6
/*  f01da38:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f01da3c:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f01da40:	3c12800a */ 	lui	$s2,%hi(var8009d0d8)
/*  f01da44:	460c0400 */ 	add.s	$f16,$f0,$f12
/*  f01da48:	0080a825 */ 	or	$s5,$a0,$zero
/*  f01da4c:	2652d0d8 */ 	addiu	$s2,$s2,%lo(var8009d0d8)
/*  f01da50:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f01da54:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f01da58:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f01da5c:	e4860008 */ 	swc1	$f6,0x8($a0)
/*  f01da60:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f01da64:	460a403c */ 	c.lt.s	$f8,$f10
/*  f01da68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01da6c:	4502004c */ 	bc1fl	.L0f01dba0
/*  f01da70:	c6aa0010 */ 	lwc1	$f10,0x10($s5)
/*  f01da74:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f01da78:	3c13800a */ 	lui	$s3,%hi(var8009d0d0)
/*  f01da7c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f01da80:	15c00009 */ 	bnez	$t6,.L0f01daa8
/*  f01da84:	2673d0d0 */ 	addiu	$s3,$s3,%lo(var8009d0d0)
/*  f01da88:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f01da8c:	55e00003 */ 	bnezl	$t7,.L0f01da9c
/*  f01da90:	8e780004 */ 	lw	$t8,0x4($s3)
/*  f01da94:	00008825 */ 	or	$s1,$zero,$zero
/*  f01da98:	8e780004 */ 	lw	$t8,0x4($s3)
.L0f01da9c:
/*  f01da9c:	57000003 */ 	bnezl	$t8,.L0f01daac
/*  f01daa0:	8e990034 */ 	lw	$t9,0x34($s4)
/*  f01daa4:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f01daa8:
/*  f01daa8:	8e990034 */ 	lw	$t9,0x34($s4)
.L0f01daac:
/*  f01daac:	3c13800a */ 	lui	$s3,%hi(var8009d0d0)
/*  f01dab0:	2673d0d0 */ 	addiu	$s3,$s3,%lo(var8009d0d0)
/*  f01dab4:	1b200037 */ 	blez	$t9,.L0f01db94
/*  f01dab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dabc:	06200035 */ 	bltz	$s1,.L0f01db94
/*  f01dac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dac4:	8e820284 */ 	lw	$v0,0x284($s4)
/*  f01dac8:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f01dacc:	8c4a0658 */ 	lw	$t2,0x658($v0)
/*  f01dad0:	106a0030 */ 	beq	$v1,$t2,.L0f01db94
/*  f01dad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dad8:	8c4b0dfc */ 	lw	$t3,0xdfc($v0)
/*  f01dadc:	106b002d */ 	beq	$v1,$t3,.L0f01db94
/*  f01dae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dae4:	0c004b70 */ 	jal	random
/*  f01dae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01daec:	44828000 */ 	mtc1	$v0,$f16
/*  f01daf0:	240c0014 */ 	addiu	$t4,$zero,0x14
/*  f01daf4:	04410005 */ 	bgez	$v0,.L0f01db0c
/*  f01daf8:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f01dafc:	3c014f80 */ 	lui	$at,0x4f80
/*  f01db00:	44819000 */ 	mtc1	$at,$f18
/*  f01db04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01db08:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f01db0c:
/*  f01db0c:	3c012f80 */ 	lui	$at,0x2f80
/*  f01db10:	44813000 */ 	mtc1	$at,$f6
/*  f01db14:	3c013e80 */ 	lui	$at,0x3e80
/*  f01db18:	44815000 */ 	mtc1	$at,$f10
/*  f01db1c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f01db20:	3c017f1b */ 	lui	$at,%hi(var7f1a8664)
/*  f01db24:	c4328664 */ 	lwc1	$f18,%lo(var7f1a8664)($at)
/*  f01db28:	3c01bf80 */ 	lui	$at,0xbf80
/*  f01db2c:	44813000 */ 	mtc1	$at,$f6
/*  f01db30:	00116880 */ 	sll	$t5,$s1,0x2
/*  f01db34:	ae4c0000 */ 	sw	$t4,0x0($s2)
/*  f01db38:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f01db3c:	026d8021 */ 	addu	$s0,$s3,$t5
/*  f01db40:	3c048009 */ 	lui	$a0,%hi(var80090004)
/*  f01db44:	240effff */ 	addiu	$t6,$zero,-1
/*  f01db48:	240fffff */ 	addiu	$t7,$zero,-1
/*  f01db4c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f01db50:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f01db54:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f01db58:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f01db5c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f01db60:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f01db64:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f01db68:	02003025 */ 	or	$a2,$s0,$zero
/*  f01db6c:	24058051 */ 	addiu	$a1,$zero,-32687
/*  f01db70:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f01db74:	0c004241 */ 	jal	func00010904
/*  f01db78:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f01db7c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f01db80:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f01db84:	10800003 */ 	beqz	$a0,.L0f01db94
/*  f01db88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01db8c:	0c00cf94 */ 	jal	func00033e50
/*  f01db90:	8fa60058 */ 	lw	$a2,0x58($sp)
.L0f01db94:
/*  f01db94:	1000006c */ 	beqz	$zero,.L0f01dd48
/*  f01db98:	aea00040 */ 	sw	$zero,0x40($s5)
/*  f01db9c:	c6aa0010 */ 	lwc1	$f10,0x10($s5)
.L0f01dba0:
/*  f01dba0:	c6a60018 */ 	lwc1	$f6,0x18($s5)
/*  f01dba4:	c6a80004 */ 	lwc1	$f8,0x4($s5)
/*  f01dba8:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f01dbac:	c6a4000c */ 	lwc1	$f4,0xc($s5)
/*  f01dbb0:	3c013980 */ 	lui	$at,0x3980
/*  f01dbb4:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f01dbb8:	44810000 */ 	mtc1	$at,$f0
/*  f01dbbc:	e6ac0014 */ 	swc1	$f12,0x14($s5)
/*  f01dbc0:	27a7008c */ 	addiu	$a3,$sp,0x8c
/*  f01dbc4:	02a04025 */ 	or	$t0,$s5,$zero
/*  f01dbc8:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f01dbcc:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f01dbd0:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f01dbd4:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f01dbd8:	e6b20004 */ 	swc1	$f18,0x4($s5)
/*  f01dbdc:	27a9008c */ 	addiu	$t1,$sp,0x8c
/*  f01dbe0:	e6a8000c */ 	swc1	$f8,0xc($s5)
.L0f01dbe4:
/*  f01dbe4:	00001825 */ 	or	$v1,$zero,$zero
/*  f01dbe8:	00e02825 */ 	or	$a1,$a3,$zero
/*  f01dbec:	01001025 */ 	or	$v0,$t0,$zero
/*  f01dbf0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f01dbf4:	8459002e */ 	lh	$t9,0x2e($v0)
/*  f01dbf8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01dbfc:	44998000 */ 	mtc1	$t9,$f16
/*  f01dc00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dc04:	46808420 */ 	cvt.s.w	$f16,$f16
/*  f01dc08:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f01dc0c:	50700013 */ 	beql	$v1,$s0,.L0f01dc5c
/*  f01dc10:	e4b20000 */ 	swc1	$f18,0x0($a1)
/*  f01dc14:	e4b20000 */ 	swc1	$f18,0x0($a1)
.L0f01dc18:
/*  f01dc18:	844a001c */ 	lh	$t2,0x1c($v0)
/*  f01dc1c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01dc20:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f01dc24:	448a8000 */ 	mtc1	$t2,$f16
/*  f01dc28:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01dc2c:	24840004 */ 	addiu	$a0,$a0,%lo(var80090004)
/*  f01dc30:	46808420 */ 	cvt.s.w	$f16,$f16
/*  f01dc34:	46008402 */ 	mul.s	$f16,$f16,$f0
/*  f01dc38:	e490fffc */ 	swc1	$f16,-0x4($a0)
/*  f01dc3c:	8459002e */ 	lh	$t9,0x2e($v0)
/*  f01dc40:	44998000 */ 	mtc1	$t9,$f16
/*  f01dc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dc48:	46808420 */ 	cvt.s.w	$f16,$f16
/*  f01dc4c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f01dc50:	5470fff1 */ 	bnel	$v1,$s0,.L0f01dc18
/*  f01dc54:	e4b20000 */ 	swc1	$f18,0x0($a1)
/*  f01dc58:	e4b20000 */ 	swc1	$f18,0x0($a1)
.L0f01dc5c:
/*  f01dc5c:	844a001c */ 	lh	$t2,0x1c($v0)
/*  f01dc60:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f01dc64:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01dc68:	448a8000 */ 	mtc1	$t2,$f16
/*  f01dc6c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f01dc70:	46808420 */ 	cvt.s.w	$f16,$f16
/*  f01dc74:	46008402 */ 	mul.s	$f16,$f16,$f0
/*  f01dc78:	e490fffc */ 	swc1	$f16,-0x4($a0)
/*  f01dc7c:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f01dc80:	00c9082b */ 	sltu	$at,$a2,$t1
/*  f01dc84:	24e7000c */ 	addiu	$a3,$a3,0xc
/*  f01dc88:	1420ffd6 */ 	bnez	$at,.L0f01dbe4
/*  f01dc8c:	25080006 */ 	addiu	$t0,$t0,0x6
/*  f01dc90:	8e8b0034 */ 	lw	$t3,0x34($s4)
/*  f01dc94:	00008825 */ 	or	$s1,$zero,$zero
/*  f01dc98:	27b30068 */ 	addiu	$s3,$sp,0x68
/*  f01dc9c:	19600009 */ 	blez	$t3,.L0f01dcc4
/*  f01dca0:	27b2008c */ 	addiu	$s2,$sp,0x8c
/*  f01dca4:	02402025 */ 	or	$a0,$s2,$zero
.L0f01dca8:
/*  f01dca8:	0c005844 */ 	jal	func00016110
/*  f01dcac:	02602825 */ 	or	$a1,$s3,$zero
/*  f01dcb0:	8e8c0034 */ 	lw	$t4,0x34($s4)
/*  f01dcb4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01dcb8:	022c082a */ 	slt	$at,$s1,$t4
/*  f01dcbc:	5420fffa */ 	bnezl	$at,.L0f01dca8
/*  f01dcc0:	02402025 */ 	or	$a0,$s2,$zero
.L0f01dcc4:
/*  f01dcc4:	3c014580 */ 	lui	$at,0x4580
/*  f01dcc8:	44810000 */ 	mtc1	$at,$f0
/*  f01dccc:	02a04025 */ 	or	$t0,$s5,$zero
/*  f01dcd0:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f01dcd4:	27a5008c */ 	addiu	$a1,$sp,0x8c
.L0f01dcd8:
/*  f01dcd8:	00001825 */ 	or	$v1,$zero,$zero
/*  f01dcdc:	01001025 */ 	or	$v0,$t0,$zero
/*  f01dce0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f01dce4:	c4900000 */ 	lwc1	$f16,0x0($a0)
/*  f01dce8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01dcec:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f01dcf0:	5070000d */ 	beql	$v1,$s0,.L0f01dd28
/*  f01dcf4:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f01dcf8:	4600940d */ 	trunc.w.s	$f16,$f18
.L0f01dcfc:
/*  f01dcfc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01dd00:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01dd04:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f01dd08:	440e8000 */ 	mfc1	$t6,$f16
/*  f01dd0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dd10:	a44e001a */ 	sh	$t6,0x1a($v0)
/*  f01dd14:	c4900000 */ 	lwc1	$f16,0x0($a0)
/*  f01dd18:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f01dd1c:	5470fff7 */ 	bnel	$v1,$s0,.L0f01dcfc
/*  f01dd20:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f01dd24:	4600940d */ 	trunc.w.s	$f16,$f18
.L0f01dd28:
/*  f01dd28:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01dd2c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f01dd30:	440e8000 */ 	mfc1	$t6,$f16
/*  f01dd34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dd38:	a44e001a */ 	sh	$t6,0x1a($v0)
/*  f01dd3c:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f01dd40:	14c5ffe5 */ 	bne	$a2,$a1,.L0f01dcd8
/*  f01dd44:	25080006 */ 	addiu	$t0,$t0,0x6
.L0f01dd48:
/*  f01dd48:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f01dd4c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f01dd50:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f01dd54:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f01dd58:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f01dd5c:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f01dd60:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f01dd64:	03e00008 */ 	jr	$ra
/*  f01dd68:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel func0f01dd6c
/*  f01dd6c:	3c03800a */ 	lui	$v1,%hi(var8009d0d8)
/*  f01dd70:	2463d0d8 */ 	addiu	$v1,$v1,%lo(var8009d0d8)
/*  f01dd74:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f01dd78:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f01dd7c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f01dd80:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f01dd84:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f01dd88:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f01dd8c:	18400006 */ 	blez	$v0,.L0f01dda8
/*  f01dd90:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f01dd94:	3c0e800a */ 	lui	$t6,0x800a
/*  f01dd98:	8dce9ff4 */ 	lw	$t6,-0x600c($t6)
/*  f01dd9c:	004e7823 */ 	subu	$t7,$v0,$t6
/*  f01dda0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f01dda4:	01e01025 */ 	or	$v0,$t7,$zero
.L0f01dda8:
/*  f01dda8:	04410002 */ 	bgez	$v0,.L0f01ddb4
/*  f01ddac:	3c118007 */ 	lui	$s1,%hi(var80070524)
/*  f01ddb0:	ac600000 */ 	sw	$zero,0x0($v1)
.L0f01ddb4:
/*  f01ddb4:	26310524 */ 	addiu	$s1,$s1,%lo(var80070524)
/*  f01ddb8:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f01ddbc:	3c13800a */ 	lui	$s3,%hi(var8009da60)
/*  f01ddc0:	2673da60 */ 	addiu	$s3,$s3,%lo(var8009da60)
/*  f01ddc4:	13000011 */ 	beqz	$t8,.L0f01de0c
/*  f01ddc8:	3c10800a */ 	lui	$s0,%hi(var8009d510)
/*  f01ddcc:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f01ddd0:	2610d510 */ 	addiu	$s0,$s0,%lo(var8009d510)
/*  f01ddd4:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f01ddd8:	8e190040 */ 	lw	$t9,0x40($s0)
.L0f01dddc:
/*  f01dddc:	53200008 */ 	beqzl	$t9,.L0f01de00
/*  f01dde0:	26100044 */ 	addiu	$s0,$s0,0x44
/*  f01dde4:	0fc0767c */ 	jal	func0f01d9f0
/*  f01dde8:	02002025 */ 	or	$a0,$s0,$zero
/*  f01ddec:	8e280000 */ 	lw	$t0,0x0($s1)
/*  f01ddf0:	55000003 */ 	bnezl	$t0,.L0f01de00
/*  f01ddf4:	26100044 */ 	addiu	$s0,$s0,0x44
/*  f01ddf8:	ae320000 */ 	sw	$s2,0x0($s1)
/*  f01ddfc:	26100044 */ 	addiu	$s0,$s0,0x44
.L0f01de00:
/*  f01de00:	0213082b */ 	sltu	$at,$s0,$s3
/*  f01de04:	5420fff5 */ 	bnezl	$at,.L0f01dddc
/*  f01de08:	8e190040 */ 	lw	$t9,0x40($s0)
.L0f01de0c:
/*  f01de0c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f01de10:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f01de14:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f01de18:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f01de1c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f01de20:	03e00008 */ 	jr	$ra
/*  f01de24:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f01de28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01de2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01de30
/*  f01de30:	3c088008 */ 	lui	$t0,%hi(var8007fa84)
/*  f01de34:	2508fa84 */ 	addiu	$t0,$t0,%lo(var8007fa84)
/*  f01de38:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f01de3c:	3c09800a */ 	lui	$t1,%hi(var800a45c0)
/*  f01de40:	252945c0 */ 	addiu	$t1,$t1,%lo(var800a45c0)
/*  f01de44:	11c0007d */ 	beqz	$t6,.L0f01e03c
/*  f01de48:	3c02800a */ 	lui	$v0,0x800a
/*  f01de4c:	8c429ff8 */ 	lw	$v0,-0x6008($v0)
/*  f01de50:	00001825 */ 	or	$v1,$zero,$zero
/*  f01de54:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f01de58:	2841000f */ 	slti	$at,$v0,0xf
/*  f01de5c:	10200004 */ 	beqz	$at,.L0f01de70
/*  f01de60:	3c0a800a */ 	lui	$t2,%hi(var800a45c4)
/*  f01de64:	44822000 */ 	mtc1	$v0,$f4
/*  f01de68:	10000004 */ 	beqz	$zero,.L0f01de7c
/*  f01de6c:	46802020 */ 	cvt.s.w	$f0,$f4
.L0f01de70:
/*  f01de70:	3c014170 */ 	lui	$at,0x4170
/*  f01de74:	44810000 */ 	mtc1	$at,$f0
/*  f01de78:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01de7c:
/*  f01de7c:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f01de80:	00001025 */ 	or	$v0,$zero,$zero
/*  f01de84:	3c017f1b */ 	lui	$at,%hi(var7f1a8670)
/*  f01de88:	19e0006c */ 	blez	$t7,.L0f01e03c
/*  f01de8c:	254a45c4 */ 	addiu	$t2,$t2,%lo(var800a45c4)
/*  f01de90:	c4308670 */ 	lwc1	$f16,%lo(var7f1a8670)($at)
/*  f01de94:	3c017f1b */ 	lui	$at,%hi(var7f1a8674)
/*  f01de98:	c42e8674 */ 	lwc1	$f14,%lo(var7f1a8674)($at)
/*  f01de9c:	3c017f1b */ 	lui	$at,%hi(var7f1a8678)
/*  f01dea0:	c42c8678 */ 	lwc1	$f12,%lo(var7f1a8678)($at)
/*  f01dea4:	8d580000 */ 	lw	$t8,0x0($t2)
.L0f01dea8:
/*  f01dea8:	03032021 */ 	addu	$a0,$t8,$v1
/*  f01deac:	8c850004 */ 	lw	$a1,0x4($a0)
/*  f01deb0:	58a0005d */ 	blezl	$a1,.L0f01e028
/*  f01deb4:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f01deb8:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f01debc:	00003825 */ 	or	$a3,$zero,$zero
/*  f01dec0:	44063000 */ 	mfc1	$a2,$f6
/*  f01dec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dec8:	00a66021 */ 	addu	$t4,$a1,$a2
/*  f01decc:	ac8c0004 */ 	sw	$t4,0x4($a0)
/*  f01ded0:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*  f01ded4:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f01ded8:	c48a002c */ 	lwc1	$f10,0x2c($a0)
/*  f01dedc:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f01dee0:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f01dee4:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f01dee8:	e4840014 */ 	swc1	$f4,0x14($a0)
/*  f01deec:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f01def0:	01c32021 */ 	addu	$a0,$t6,$v1
/*  f01def4:	c48a0030 */ 	lwc1	$f10,0x30($a0)
/*  f01def8:	c4860018 */ 	lwc1	$f6,0x18($a0)
/*  f01defc:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f01df00:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f01df04:	e4920018 */ 	swc1	$f18,0x18($a0)
/*  f01df08:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f01df0c:	01e32021 */ 	addu	$a0,$t7,$v1
/*  f01df10:	c48a0034 */ 	lwc1	$f10,0x34($a0)
/*  f01df14:	c484001c */ 	lwc1	$f4,0x1c($a0)
/*  f01df18:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f01df1c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f01df20:	e488001c */ 	swc1	$f8,0x1c($a0)
/*  f01df24:	8d580000 */ 	lw	$t8,0x0($t2)
/*  f01df28:	03032021 */ 	addu	$a0,$t8,$v1
/*  f01df2c:	c48a0020 */ 	lwc1	$f10,0x20($a0)
/*  f01df30:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f01df34:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f01df38:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f01df3c:	e4860008 */ 	swc1	$f6,0x8($a0)
/*  f01df40:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f01df44:	03232021 */ 	addu	$a0,$t9,$v1
/*  f01df48:	c48a0028 */ 	lwc1	$f10,0x28($a0)
/*  f01df4c:	c4880010 */ 	lwc1	$f8,0x10($a0)
/*  f01df50:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f01df54:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f01df58:	18c0001b */ 	blez	$a2,.L0f01dfc8
/*  f01df5c:	e4840010 */ 	swc1	$f4,0x10($a0)
/*  f01df60:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f01df64:	10e6000e */ 	beq	$a3,$a2,.L0f01dfa0
/*  f01df68:	8d4c0000 */ 	lw	$t4,0x0($t2)
.L0f01df6c:
/*  f01df6c:	01832021 */ 	addu	$a0,$t4,$v1
/*  f01df70:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f01df74:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01df78:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f01df7c:	460a9280 */ 	add.s	$f10,$f18,$f10
/*  f01df80:	e48a000c */ 	swc1	$f10,0xc($a0)
/*  f01df84:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*  f01df88:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f01df8c:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01df90:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f01df94:	e48a0024 */ 	swc1	$f10,0x24($a0)
/*  f01df98:	14e6fff4 */ 	bne	$a3,$a2,.L0f01df6c
/*  f01df9c:	8d4c0000 */ 	lw	$t4,0x0($t2)
.L0f01dfa0:
/*  f01dfa0:	01832021 */ 	addu	$a0,$t4,$v1
/*  f01dfa4:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f01dfa8:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01dfac:	460a9280 */ 	add.s	$f10,$f18,$f10
/*  f01dfb0:	e48a000c */ 	swc1	$f10,0xc($a0)
/*  f01dfb4:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*  f01dfb8:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f01dfbc:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01dfc0:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f01dfc4:	e48a0024 */ 	swc1	$f10,0x24($a0)
.L0f01dfc8:
/*  f01dfc8:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f01dfcc:	01c32021 */ 	addu	$a0,$t6,$v1
/*  f01dfd0:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f01dfd4:	29e10096 */ 	slti	$at,$t7,0x96
/*  f01dfd8:	54200005 */ 	bnezl	$at,.L0f01dff0
/*  f01dfdc:	c482000c */ 	lwc1	$f2,0xc($a0)
/*  f01dfe0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f01dfe4:	8d580000 */ 	lw	$t8,0x0($t2)
/*  f01dfe8:	03032021 */ 	addu	$a0,$t8,$v1
/*  f01dfec:	c482000c */ 	lwc1	$f2,0xc($a0)
.L0f01dff0:
/*  f01dff0:	460e103c */ 	c.lt.s	$f2,$f14
/*  f01dff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dff8:	45030006 */ 	bc1tl	.L0f01e014
/*  f01dffc:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f01e000:	4602803c */ 	c.lt.s	$f16,$f2
/*  f01e004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e008:	45020003 */ 	bc1fl	.L0f01e018
/*  f01e00c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f01e010:	ac800004 */ 	sw	$zero,0x4($a0)
.L0f01e014:
/*  f01e014:	8d190000 */ 	lw	$t9,0x0($t0)
.L0f01e018:
/*  f01e018:	57200003 */ 	bnezl	$t9,.L0f01e028
/*  f01e01c:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f01e020:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f01e024:	8d2c0000 */ 	lw	$t4,0x0($t1)
.L0f01e028:
/*  f01e028:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f01e02c:	2463006c */ 	addiu	$v1,$v1,0x6c
/*  f01e030:	004c082a */ 	slt	$at,$v0,$t4
/*  f01e034:	5420ff9c */ 	bnezl	$at,.L0f01dea8
/*  f01e038:	8d580000 */ 	lw	$t8,0x0($t2)
.L0f01e03c:
/*  f01e03c:	03e00008 */ 	jr	$ra
/*  f01e040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e04c:	00000000 */ 	sll	$zero,$zero,0x0
);
