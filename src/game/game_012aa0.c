#include <ultra64.h>
#include "constants.h"
#include "game/game_0125a0.h"
#include "game/game_013ee0.h"
#include "game/bondhead.h"
#include "game/room.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "lib/lib_233c0.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f012aa0
/*  f012aa0:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f012aa4:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f012aa8:	3c15800a */ 	lui	$s5,%hi(g_StageSetup)
/*  f012aac:	26b5d030 */ 	addiu	$s5,$s5,%lo(g_StageSetup)
/*  f012ab0:	8ea2001c */ 	lw	$v0,0x1c($s5)
/*  f012ab4:	3c04800a */ 	lui	$a0,%hi(g_PadsFile)
/*  f012ab8:	3c07800a */ 	lui	$a3,%hi(g_PadOffsets)
/*  f012abc:	24e72354 */ 	addiu	$a3,$a3,%lo(g_PadOffsets)
/*  f012ac0:	24842350 */ 	addiu	$a0,$a0,%lo(g_PadsFile)
/*  f012ac4:	244e0014 */ 	addiu	$t6,$v0,0x14
/*  f012ac8:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f012acc:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f012ad0:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f012ad4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f012ad8:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f012adc:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f012ae0:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f012ae4:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f012ae8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f012aec:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f012af0:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f012af4:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f012af8:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f012afc:	00009025 */ 	or	$s2,$zero,$zero
/*  f012b00:	0000a025 */ 	or	$s4,$zero,$zero
/*  f012b04:	1900005e */ 	blez	$t0,.L0f012c80
/*  f012b08:	00401825 */ 	or	$v1,$v0,$zero
/*  f012b0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f012b10:	4481a000 */ 	mtc1	$at,$f20
/*  f012b14:	afa80120 */ 	sw	$t0,0x120($sp)
/*  f012b18:	241effff */ 	addiu	$s8,$zero,-1
/*  f012b1c:	27b70064 */ 	addiu	$s7,$sp,0x64
/*  f012b20:	27b60090 */ 	addiu	$s6,$sp,0x90
/*  f012b24:	27b300c8 */ 	addiu	$s3,$sp,0xc8
.L0f012b28:
/*  f012b28:	3c07800a */ 	lui	$a3,%hi(g_PadOffsets)
/*  f012b2c:	24e72354 */ 	addiu	$a3,$a3,%lo(g_PadOffsets)
/*  f012b30:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f012b34:	8eb9001c */ 	lw	$t9,0x1c($s5)
/*  f012b38:	02402025 */ 	or	$a0,$s2,$zero
/*  f012b3c:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f012b40:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f012b44:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f012b48:	02603025 */ 	or	$a2,$s3,$zero
/*  f012b4c:	0fc456ac */ 	jal	padUnpack
/*  f012b50:	03228821 */ 	addu	$s1,$t9,$v0
/*  f012b54:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f012b58:	00008025 */ 	or	$s0,$zero,$zero
/*  f012b5c:	02602025 */ 	or	$a0,$s3,$zero
/*  f012b60:	00095480 */ 	sll	$t2,$t1,0x12
/*  f012b64:	000a5d83 */ 	sra	$t3,$t2,0x16
/*  f012b68:	05610023 */ 	bgez	$t3,.L0f012bf8
/*  f012b6c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f012b70:	02e03025 */ 	or	$a2,$s7,$zero
/*  f012b74:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f012b78:	0fc58865 */ 	jal	func0f162194
/*  f012b7c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f012b80:	87ac0090 */ 	lh	$t4,0x90($sp)
/*  f012b84:	87ad0064 */ 	lh	$t5,0x64($sp)
/*  f012b88:	02602025 */ 	or	$a0,$s3,$zero
/*  f012b8c:	13cc0003 */ 	beq	$s8,$t4,.L0f012b9c
/*  f012b90:	00000000 */ 	nop
/*  f012b94:	10000004 */ 	b	.L0f012ba8
/*  f012b98:	02c08025 */ 	or	$s0,$s6,$zero
.L0f012b9c:
/*  f012b9c:	13cd0002 */ 	beq	$s8,$t5,.L0f012ba8
/*  f012ba0:	00000000 */ 	nop
/*  f012ba4:	02e08025 */ 	or	$s0,$s7,$zero
.L0f012ba8:
/*  f012ba8:	52000014 */ 	beqzl	$s0,.L0f012bfc
/*  f012bac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f012bb0:	0c00a900 */ 	jal	func0002a400
/*  f012bb4:	02002825 */ 	or	$a1,$s0,$zero
/*  f012bb8:	58400009 */ 	blezl	$v0,.L0f012be0
/*  f012bbc:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f012bc0:	86290002 */ 	lh	$t1,0x2($s1)
/*  f012bc4:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f012bc8:	33193ff0 */ 	andi	$t9,$t8,0x3ff0
/*  f012bcc:	312ac00f */ 	andi	$t2,$t1,0xc00f
/*  f012bd0:	032a5825 */ 	or	$t3,$t9,$t2
/*  f012bd4:	10000008 */ 	b	.L0f012bf8
/*  f012bd8:	a62b0002 */ 	sh	$t3,0x2($s1)
/*  f012bdc:	860e0000 */ 	lh	$t6,0x0($s0)
.L0f012be0:
/*  f012be0:	86290002 */ 	lh	$t1,0x2($s1)
/*  f012be4:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f012be8:	31f83ff0 */ 	andi	$t8,$t7,0x3ff0
/*  f012bec:	3139c00f */ 	andi	$t9,$t1,0xc00f
/*  f012bf0:	03195025 */ 	or	$t2,$t8,$t9
/*  f012bf4:	a62a0002 */ 	sh	$t2,0x2($s1)
.L0f012bf8:
/*  f012bf8:	8e2b0000 */ 	lw	$t3,0x0($s1)
.L0f012bfc:
/*  f012bfc:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f012c00:	000b6382 */ 	srl	$t4,$t3,0xe
/*  f012c04:	318d0200 */ 	andi	$t5,$t4,0x200
/*  f012c08:	51a00016 */ 	beqzl	$t5,.L0f012c64
/*  f012c0c:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f012c10:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f012c14:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f012c18:	c7b00100 */ 	lwc1	$f16,0x100($sp)
/*  f012c1c:	c7a40104 */ 	lwc1	$f4,0x104($sp)
/*  f012c20:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f012c24:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f012c28:	02402025 */ 	or	$a0,$s2,$zero
/*  f012c2c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f012c30:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f012c34:	c7b0010c */ 	lwc1	$f16,0x10c($sp)
/*  f012c38:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f012c3c:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
/*  f012c40:	02602825 */ 	or	$a1,$s3,$zero
/*  f012c44:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f012c48:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f012c4c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f012c50:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f012c54:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f012c58:	0fc45864 */ 	jal	padCopyBboxFromPad
/*  f012c5c:	e7b2010c */ 	swc1	$f18,0x10c($sp)
/*  f012c60:	8fae0120 */ 	lw	$t6,0x120($sp)
.L0f012c64:
/*  f012c64:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f012c68:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f012c6c:	164effae */ 	bne	$s2,$t6,.L0f012b28
/*  f012c70:	00000000 */ 	nop
/*  f012c74:	3c03800a */ 	lui	$v1,%hi(g_PadsFile)
/*  f012c78:	8c632350 */ 	lw	$v1,%lo(g_PadsFile)($v1)
/*  f012c7c:	8ea2001c */ 	lw	$v0,0x1c($s5)
.L0f012c80:
/*  f012c80:	8c6f0008 */ 	lw	$t7,0x8($v1)
/*  f012c84:	004f4821 */ 	addu	$t1,$v0,$t7
/*  f012c88:	aea90000 */ 	sw	$t1,0x0($s5)
/*  f012c8c:	8c78000c */ 	lw	$t8,0xc($v1)
/*  f012c90:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f012c94:	aeb90004 */ 	sw	$t9,0x4($s5)
/*  f012c98:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f012c9c:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f012ca0:	11600003 */ 	beqz	$t3,.L0f012cb0
/*  f012ca4:	aeab0008 */ 	sw	$t3,0x8($s5)
/*  f012ca8:	0fc050ba */ 	jal	coverLoad
/*  f012cac:	00000000 */ 	nop
.L0f012cb0:
/*  f012cb0:	8ea20000 */ 	lw	$v0,0x0($s5)
/*  f012cb4:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f012cb8:	05a20009 */ 	bltzl	$t5,.L0f012ce0
/*  f012cbc:	8ea20004 */ 	lw	$v0,0x4($s5)
.L0f012cc0:
/*  f012cc0:	8eae001c */ 	lw	$t6,0x1c($s5)
/*  f012cc4:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f012cc8:	8c580010 */ 	lw	$t8,0x10($v0)
/*  f012ccc:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f012cd0:	01cf4821 */ 	addu	$t1,$t6,$t7
/*  f012cd4:	0701fffa */ 	bgez	$t8,.L0f012cc0
/*  f012cd8:	ac49fff4 */ 	sw	$t1,-0xc($v0)
/*  f012cdc:	8ea20004 */ 	lw	$v0,0x4($s5)
.L0f012ce0:
/*  f012ce0:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f012ce4:	5060000c */ 	beqzl	$v1,.L0f012d18
/*  f012ce8:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f012cec:
/*  f012cec:	8eb9001c */ 	lw	$t9,0x1c($s5)
/*  f012cf0:	8c4c0004 */ 	lw	$t4,0x4($v0)
/*  f012cf4:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f012cf8:	03235021 */ 	addu	$t2,$t9,$v1
/*  f012cfc:	ac4afff4 */ 	sw	$t2,-0xc($v0)
/*  f012d00:	8eab001c */ 	lw	$t3,0x1c($s5)
/*  f012d04:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f012d08:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f012d0c:	1460fff7 */ 	bnez	$v1,.L0f012cec
/*  f012d10:	ac4dfff8 */ 	sw	$t5,-0x8($v0)
/*  f012d14:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f012d18:
/*  f012d18:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f012d1c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f012d20:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f012d24:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f012d28:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f012d2c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f012d30:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f012d34:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f012d38:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f012d3c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f012d40:	03e00008 */ 	jr	$ra
/*  f012d44:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
