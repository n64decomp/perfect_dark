#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osPfsGetStatus
/*    4ba90:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4ba94:	afa40030 */ 	sw	$a0,0x30($sp)
/*    4ba98:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4ba9c:	afa50034 */ 	sw	$a1,0x34($sp)
/*    4baa0:	240e00fa */ 	addiu	$t6,$zero,0xfa
/*    4baa4:	3c018006 */ 	lui	$at,%hi(var80060984)
/*    4baa8:	00a02025 */ 	or	$a0,$a1,$zero
/*    4baac:	a02e0984 */ 	sb	$t6,%lo(var80060984)($at)
/*    4bab0:	0c012ed8 */ 	jal	__osPfsRequestOneChannel
/*    4bab4:	00002825 */ 	or	$a1,$zero,$zero
/*    4bab8:	3c058009 */ 	lui	$a1,%hi(var80090a20)
/*    4babc:	24a50a20 */ 	addiu	$a1,$a1,%lo(var80090a20)
/*    4bac0:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4bac4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4bac8:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    4bacc:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    4bad0:	0c0121bc */ 	jal	osRecvMesg
/*    4bad4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4bad8:	3c058009 */ 	lui	$a1,%hi(var80090a20)
/*    4badc:	24a50a20 */ 	addiu	$a1,$a1,%lo(var80090a20)
/*    4bae0:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4bae4:	00002025 */ 	or	$a0,$zero,$zero
/*    4bae8:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    4baec:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    4baf0:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    4baf4:	0c0121bc */ 	jal	osRecvMesg
/*    4baf8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4bafc:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    4bb00:	0c012f09 */ 	jal	__osPfsGetOneChannelData
/*    4bb04:	27a50024 */ 	addiu	$a1,$sp,0x24
/*    4bb08:	93a20026 */ 	lbu	$v0,0x26($sp)
/*    4bb0c:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    4bb10:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4bb14:	30430001 */ 	andi	$v1,$v0,0x1
/*    4bb18:	10600005 */ 	beqz	$v1,.L0004bb30
/*    4bb1c:	304f0002 */ 	andi	$t7,$v0,0x2
/*    4bb20:	11e00003 */ 	beqz	$t7,.L0004bb30
/*    4bb24:	00000000 */ 	nop
/*    4bb28:	1000000b */ 	b	.L0004bb58
/*    4bb2c:	24020002 */ 	addiu	$v0,$zero,0x2
.L0004bb30:
/*    4bb30:	17000003 */ 	bnez	$t8,.L0004bb40
/*    4bb34:	00000000 */ 	nop
/*    4bb38:	14600003 */ 	bnez	$v1,.L0004bb48
/*    4bb3c:	30590004 */ 	andi	$t9,$v0,0x4
.L0004bb40:
/*    4bb40:	10000005 */ 	b	.L0004bb58
/*    4bb44:	24020001 */ 	addiu	$v0,$zero,0x1
.L0004bb48:
/*    4bb48:	13200003 */ 	beqz	$t9,.L0004bb58
/*    4bb4c:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*    4bb50:	10000001 */ 	b	.L0004bb58
/*    4bb54:	24020004 */ 	addiu	$v0,$zero,0x4
.L0004bb58:
/*    4bb58:	03e00008 */ 	jr	$ra
/*    4bb5c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel __osPfsRequestOneChannel
/*    4bb60:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4bb64:	3c068009 */ 	lui	$a2,%hi(var80090a20)
/*    4bb68:	240700fe */ 	addiu	$a3,$zero,0xfe
/*    4bb6c:	3c01800a */ 	lui	$at,%hi(__osContLastCmd)
/*    4bb70:	24c20a20 */ 	addiu	$v0,$a2,%lo(var80090a20)
/*    4bb74:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4bb78:	a027c820 */ 	sb	$a3,%lo(__osContLastCmd)($at)
/*    4bb7c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4bb80:	ac4f003c */ 	sw	$t7,0x3c($v0)
/*    4bb84:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4bb88:	24190003 */ 	addiu	$t9,$zero,0x3
/*    4bb8c:	240800ff */ 	addiu	$t0,$zero,0xff
/*    4bb90:	240900ff */ 	addiu	$t1,$zero,0xff
/*    4bb94:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    4bb98:	a3b8000c */ 	sb	$t8,0xc($sp)
/*    4bb9c:	a3b9000d */ 	sb	$t9,0xd($sp)
/*    4bba0:	a3a5000e */ 	sb	$a1,0xe($sp)
/*    4bba4:	a3a8000f */ 	sb	$t0,0xf($sp)
/*    4bba8:	a3a90010 */ 	sb	$t1,0x10($sp)
/*    4bbac:	a3aa0011 */ 	sb	$t2,0x11($sp)
/*    4bbb0:	18800010 */ 	blez	$a0,.L0004bbf4
/*    4bbb4:	00001825 */ 	or	$v1,$zero,$zero
/*    4bbb8:	30860003 */ 	andi	$a2,$a0,0x3
/*    4bbbc:	10c00006 */ 	beqz	$a2,.L0004bbd8
/*    4bbc0:	00c02825 */ 	or	$a1,$a2,$zero
.L0004bbc4:
/*    4bbc4:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4bbc8:	a0400000 */ 	sb	$zero,0x0($v0)
/*    4bbcc:	14a3fffd */ 	bne	$a1,$v1,.L0004bbc4
/*    4bbd0:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4bbd4:	10640007 */ 	beq	$v1,$a0,.L0004bbf4
.L0004bbd8:
/*    4bbd8:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4bbdc:	a0400001 */ 	sb	$zero,0x1($v0)
/*    4bbe0:	a0400002 */ 	sb	$zero,0x2($v0)
/*    4bbe4:	a0400003 */ 	sb	$zero,0x3($v0)
/*    4bbe8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4bbec:	1464fffa */ 	bne	$v1,$a0,.L0004bbd8
/*    4bbf0:	a040fffc */ 	sb	$zero,-0x4($v0)
.L0004bbf4:
/*    4bbf4:	27ab000c */ 	addiu	$t3,$sp,0xc
/*    4bbf8:	8d610000 */ 	lw	$at,0x0($t3)
/*    4bbfc:	24420006 */ 	addiu	$v0,$v0,0x6
/*    4bc00:	a841fffa */ 	swl	$at,-0x6($v0)
/*    4bc04:	b841fffd */ 	swr	$at,-0x3($v0)
/*    4bc08:	91610004 */ 	lbu	$at,0x4($t3)
/*    4bc0c:	a041fffe */ 	sb	$at,-0x2($v0)
/*    4bc10:	916d0005 */ 	lbu	$t5,0x5($t3)
/*    4bc14:	a0470000 */ 	sb	$a3,0x0($v0)
/*    4bc18:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4bc1c:	03e00008 */ 	jr	$ra
/*    4bc20:	a04dffff */ 	sb	$t5,-0x1($v0)
);

GLOBAL_ASM(
glabel __osPfsGetOneChannelData
/*    4bc24:	3c028009 */ 	lui	$v0,%hi(var80090a20)
/*    4bc28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4bc2c:	24420a20 */ 	addiu	$v0,$v0,%lo(var80090a20)
/*    4bc30:	1880000b */ 	blez	$a0,.L0004bc60
/*    4bc34:	00001825 */ 	or	$v1,$zero,$zero
/*    4bc38:	30870003 */ 	andi	$a3,$a0,0x3
/*    4bc3c:	10e00005 */ 	beqz	$a3,.L0004bc54
/*    4bc40:	00e03025 */ 	or	$a2,$a3,$zero
.L0004bc44:
/*    4bc44:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4bc48:	14c3fffe */ 	bne	$a2,$v1,.L0004bc44
/*    4bc4c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4bc50:	10640003 */ 	beq	$v1,$a0,.L0004bc60
.L0004bc54:
/*    4bc54:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4bc58:	1464fffe */ 	bne	$v1,$a0,.L0004bc54
/*    4bc5c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0004bc60:
/*    4bc60:	88410000 */ 	lwl	$at,0x0($v0)
/*    4bc64:	98410003 */ 	lwr	$at,0x3($v0)
/*    4bc68:	27ae000c */ 	addiu	$t6,$sp,0xc
/*    4bc6c:	adc10000 */ 	sw	$at,0x0($t6)
/*    4bc70:	90410004 */ 	lbu	$at,0x4($v0)
/*    4bc74:	a1c10004 */ 	sb	$at,0x4($t6)
/*    4bc78:	90580005 */ 	lbu	$t8,0x5($v0)
/*    4bc7c:	a1d80005 */ 	sb	$t8,0x5($t6)
/*    4bc80:	93b9000d */ 	lbu	$t9,0xd($sp)
/*    4bc84:	332800c0 */ 	andi	$t0,$t9,0xc0
/*    4bc88:	00084903 */ 	sra	$t1,$t0,0x4
/*    4bc8c:	312a00ff */ 	andi	$t2,$t1,0xff
/*    4bc90:	15400008 */ 	bnez	$t2,.L0004bcb4
/*    4bc94:	a0a90003 */ 	sb	$t1,0x3($a1)
/*    4bc98:	93ab0010 */ 	lbu	$t3,0x10($sp)
/*    4bc9c:	93ad000f */ 	lbu	$t5,0xf($sp)
/*    4bca0:	000b6200 */ 	sll	$t4,$t3,0x8
/*    4bca4:	018d7825 */ 	or	$t7,$t4,$t5
/*    4bca8:	a4af0000 */ 	sh	$t7,0x0($a1)
/*    4bcac:	93ae0011 */ 	lbu	$t6,0x11($sp)
/*    4bcb0:	a0ae0002 */ 	sb	$t6,0x2($a1)
.L0004bcb4:
/*    4bcb4:	03e00008 */ 	jr	$ra
/*    4bcb8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4bcbc:	00000000 */ 	nop
);
