#include <libultra_internal.h>

GLOBAL_ASM(
glabel osInitialize
/*     5b60:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*     5b64:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     5b68:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     5b6c:	3c018009 */ 	lui	$at,%hi(var80090a60)
/*     5b70:	afb10018 */ 	sw	$s1,0x18($sp)
/*     5b74:	afb00014 */ 	sw	$s0,0x14($sp)
/*     5b78:	0c012b34 */ 	jal	__osGetSR
/*     5b7c:	ac2e0a60 */ 	sw	$t6,%lo(var80090a60)($at)
/*     5b80:	3c012000 */ 	lui	$at,0x2000
/*     5b84:	0c012b30 */ 	jal	__osSetSR
/*     5b88:	00412025 */ 	or	$a0,$v0,$at
/*     5b8c:	3c040100 */ 	lui	$a0,0x100
/*     5b90:	0c012078 */ 	jal	__osSetFpcCsr
/*     5b94:	34840800 */ 	ori	$a0,$a0,0x800
/*     5b98:	3c101fc0 */ 	lui	$s0,0x1fc0
/*     5b9c:	361007fc */ 	ori	$s0,$s0,0x7fc
/*     5ba0:	27b10034 */ 	addiu	$s1,$sp,0x34
/*     5ba4:	02202825 */ 	or	$a1,$s1,$zero
/*     5ba8:	0c012b38 */ 	jal	__osSiRawReadIo
/*     5bac:	02002025 */ 	or	$a0,$s0,$zero
/*     5bb0:	10400005 */ 	beqz	$v0,.L00005bc8
/*     5bb4:	02002025 */ 	or	$a0,$s0,$zero
.L00005bb8:
/*     5bb8:	0c012b38 */ 	jal	__osSiRawReadIo
/*     5bbc:	02202825 */ 	or	$a1,$s1,$zero
/*     5bc0:	5440fffd */ 	bnezl	$v0,.L00005bb8
/*     5bc4:	02002025 */ 	or	$a0,$s0,$zero
.L00005bc8:
/*     5bc8:	8fa50034 */ 	lw	$a1,0x34($sp)
/*     5bcc:	02002025 */ 	or	$a0,$s0,$zero
/*     5bd0:	34af0008 */ 	ori	$t7,$a1,0x8
/*     5bd4:	0c012b4c */ 	jal	__osSiRawWriteIo
/*     5bd8:	01e02825 */ 	or	$a1,$t7,$zero
/*     5bdc:	10400008 */ 	beqz	$v0,.L00005c00
/*     5be0:	00000000 */ 	nop
/*     5be4:	8fa50034 */ 	lw	$a1,0x34($sp)
.L00005be8:
/*     5be8:	02002025 */ 	or	$a0,$s0,$zero
/*     5bec:	34b80008 */ 	ori	$t8,$a1,0x8
/*     5bf0:	0c012b4c */ 	jal	__osSiRawWriteIo
/*     5bf4:	03002825 */ 	or	$a1,$t8,$zero
/*     5bf8:	5440fffb */ 	bnezl	$v0,.L00005be8
/*     5bfc:	8fa50034 */ 	lw	$a1,0x34($sp)
.L00005c00:
/*     5c00:	3c027000 */ 	lui	$v0,%hi(__osExceptionPreamble)
/*     5c04:	244234f0 */ 	addiu	$v0,$v0,%lo(__osExceptionPreamble)
/*     5c08:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c0c:	3c108000 */ 	lui	$s0,0x8000
/*     5c10:	3c098000 */ 	lui	$t1,0x8000
/*     5c14:	ae010000 */ 	sw	$at,0x0($s0)
/*     5c18:	8c480004 */ 	lw	$t0,0x4($v0)
/*     5c1c:	35290080 */ 	ori	$t1,$t1,0x80
/*     5c20:	3c0c8000 */ 	lui	$t4,0x8000
/*     5c24:	ae080004 */ 	sw	$t0,0x4($s0)
/*     5c28:	8c410008 */ 	lw	$at,0x8($v0)
/*     5c2c:	358c0100 */ 	ori	$t4,$t4,0x100
/*     5c30:	3c0f8000 */ 	lui	$t7,0x8000
/*     5c34:	ae010008 */ 	sw	$at,0x8($s0)
/*     5c38:	8c48000c */ 	lw	$t0,0xc($v0)
/*     5c3c:	35ef0180 */ 	ori	$t7,$t7,0x180
/*     5c40:	02002025 */ 	or	$a0,$s0,$zero
/*     5c44:	ae08000c */ 	sw	$t0,0xc($s0)
/*     5c48:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c4c:	24050190 */ 	addiu	$a1,$zero,0x190
/*     5c50:	ad210000 */ 	sw	$at,0x0($t1)
/*     5c54:	8c4b0004 */ 	lw	$t3,0x4($v0)
/*     5c58:	ad2b0004 */ 	sw	$t3,0x4($t1)
/*     5c5c:	8c410008 */ 	lw	$at,0x8($v0)
/*     5c60:	ad210008 */ 	sw	$at,0x8($t1)
/*     5c64:	8c4b000c */ 	lw	$t3,0xc($v0)
/*     5c68:	ad2b000c */ 	sw	$t3,0xc($t1)
/*     5c6c:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c70:	ad810000 */ 	sw	$at,0x0($t4)
/*     5c74:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*     5c78:	ad8e0004 */ 	sw	$t6,0x4($t4)
/*     5c7c:	8c410008 */ 	lw	$at,0x8($v0)
/*     5c80:	ad810008 */ 	sw	$at,0x8($t4)
/*     5c84:	8c4e000c */ 	lw	$t6,0xc($v0)
/*     5c88:	ad8e000c */ 	sw	$t6,0xc($t4)
/*     5c8c:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c90:	ade10000 */ 	sw	$at,0x0($t7)
/*     5c94:	8c590004 */ 	lw	$t9,0x4($v0)
/*     5c98:	adf90004 */ 	sw	$t9,0x4($t7)
/*     5c9c:	8c410008 */ 	lw	$at,0x8($v0)
/*     5ca0:	ade10008 */ 	sw	$at,0x8($t7)
/*     5ca4:	8c59000c */ 	lw	$t9,0xc($v0)
/*     5ca8:	0c012b60 */ 	jal	osWritebackDCache
/*     5cac:	adf9000c */ 	sw	$t9,0xc($t7)
/*     5cb0:	02002025 */ 	or	$a0,$s0,$zero
/*     5cb4:	0c012054 */ 	jal	osInvalICache
/*     5cb8:	24050190 */ 	addiu	$a1,$zero,0x190
/*     5cbc:	0c001770 */ 	jal	func00005dc0
/*     5cc0:	00000000 */ 	nop
/*     5cc4:	0c000bfc */ 	jal	osMapTLBRdb
/*     5cc8:	00000000 */ 	nop
/*     5ccc:	3c108006 */ 	lui	$s0,%hi(var8005cf60)
/*     5cd0:	2610cf60 */ 	addiu	$s0,$s0,%lo(var8005cf60)
/*     5cd4:	8e040000 */ 	lw	$a0,0x0($s0)
/*     5cd8:	8e050004 */ 	lw	$a1,0x4($s0)
/*     5cdc:	24060000 */ 	addiu	$a2,$zero,0x0
/*     5ce0:	0c012bda */ 	jal	func0004af68
/*     5ce4:	24070003 */ 	addiu	$a3,$zero,0x3
/*     5ce8:	00402025 */ 	or	$a0,$v0,$zero
/*     5cec:	00602825 */ 	or	$a1,$v1,$zero
/*     5cf0:	24060000 */ 	addiu	$a2,$zero,0x0
/*     5cf4:	0c012b9a */ 	jal	func0004ae68
/*     5cf8:	24070004 */ 	addiu	$a3,$zero,0x4
/*     5cfc:	ae020000 */ 	sw	$v0,0x0($s0)
/*     5d00:	ae030004 */ 	sw	$v1,0x4($s0)
/*     5d04:	3c088000 */ 	lui	$t0,0x8000
/*     5d08:	8d08030c */ 	lw	$t0,0x30c($t0)
/*     5d0c:	3c048000 */ 	lui	$a0,0x8000
/*     5d10:	2484031c */ 	addiu	$a0,$a0,0x31c
/*     5d14:	15000003 */ 	bnez	$t0,.L00005d24
/*     5d18:	00000000 */ 	nop
/*     5d1c:	0c012c30 */ 	jal	bzero
/*     5d20:	24050040 */ 	addiu	$a1,$zero,0x40
.L00005d24:
/*     5d24:	3c028000 */ 	lui	$v0,0x8000
/*     5d28:	8c420300 */ 	lw	$v0,0x300($v0)
/*     5d2c:	3c0a02f5 */ 	lui	$t2,0x2f5
/*     5d30:	354ab2d2 */ 	ori	$t2,$t2,0xb2d2
/*     5d34:	14400004 */ 	bnez	$v0,.L00005d48
/*     5d38:	24010002 */ 	addiu	$at,$zero,0x2
/*     5d3c:	3c018006 */ 	lui	$at,%hi(var8005cf68)
/*     5d40:	1000000b */ 	b	.L00005d70
/*     5d44:	ac2acf68 */ 	sw	$t2,%lo(var8005cf68)($at)
.L00005d48:
/*     5d48:	14410006 */ 	bne	$v0,$at,.L00005d64
/*     5d4c:	3c0b02e6 */ 	lui	$t3,0x2e6
/*     5d50:	3c0902e6 */ 	lui	$t1,0x2e6
/*     5d54:	3529d354 */ 	ori	$t1,$t1,0xd354
/*     5d58:	3c018006 */ 	lui	$at,%hi(var8005cf68)
/*     5d5c:	10000004 */ 	b	.L00005d70
/*     5d60:	ac29cf68 */ 	sw	$t1,%lo(var8005cf68)($at)
.L00005d64:
/*     5d64:	356bd354 */ 	ori	$t3,$t3,0xd354
/*     5d68:	3c018006 */ 	lui	$at,%hi(var8005cf68)
/*     5d6c:	ac2bcf68 */ 	sw	$t3,%lo(var8005cf68)($at)
.L00005d70:
/*     5d70:	0c012c58 */ 	jal	__osGetCause
/*     5d74:	00000000 */ 	nop
/*     5d78:	304d1000 */ 	andi	$t5,$v0,0x1000
/*     5d7c:	11a00003 */ 	beqz	$t5,.L00005d8c
/*     5d80:	240c0001 */ 	addiu	$t4,$zero,0x1
.L00005d84:
/*     5d84:	1000ffff */ 	b	.L00005d84
/*     5d88:	00000000 */ 	nop
.L00005d8c:
/*     5d8c:	3c0ea450 */ 	lui	$t6,0xa450
/*     5d90:	adcc0008 */ 	sw	$t4,0x8($t6)
/*     5d94:	24183fff */ 	addiu	$t8,$zero,0x3fff
/*     5d98:	3c0fa450 */ 	lui	$t7,0xa450
/*     5d9c:	adf80010 */ 	sw	$t8,0x10($t7)
/*     5da0:	2419000f */ 	addiu	$t9,$zero,0xf
/*     5da4:	3c08a450 */ 	lui	$t0,0xa450
/*     5da8:	ad190014 */ 	sw	$t9,0x14($t0)
/*     5dac:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     5db0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     5db4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     5db8:	03e00008 */ 	jr	$ra
/*     5dbc:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
