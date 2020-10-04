#include <libultra_internal.h>

GLOBAL_ASM(
glabel osEepromWrite
/*    4bcc0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    4bcc4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4bcc8:	afb10018 */ 	sw	$s1,0x18($sp)
/*    4bccc:	00808825 */ 	or	$s1,$a0,$zero
/*    4bcd0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    4bcd4:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    4bcd8:	0c012a18 */ 	jal	__osSiGetAccess
/*    4bcdc:	afa60050 */ 	sw	$a2,0x50($sp)
/*    4bce0:	27b0002c */ 	addiu	$s0,$sp,0x2c
/*    4bce4:	02002825 */ 	or	$a1,$s0,$zero
/*    4bce8:	0c012fb9 */ 	jal	__osEepStatus
/*    4bcec:	02202025 */ 	or	$a0,$s1,$zero
/*    4bcf0:	14400015 */ 	bnez	$v0,.L0004bd48
/*    4bcf4:	00401825 */ 	or	$v1,$v0,$zero
/*    4bcf8:	97ae002c */ 	lhu	$t6,0x2c($sp)
/*    4bcfc:	34018000 */ 	dli	$at,0x8000
/*    4bd00:	93b8004f */ 	lbu	$t8,0x4f($sp)
/*    4bd04:	31cfc000 */ 	andi	$t7,$t6,0xc000
/*    4bd08:	11e10005 */ 	beq	$t7,$at,.L0004bd20
/*    4bd0c:	3401c000 */ 	dli	$at,0xc000
/*    4bd10:	11e10008 */ 	beq	$t7,$at,.L0004bd34
/*    4bd14:	93b9004f */ 	lbu	$t9,0x4f($sp)
/*    4bd18:	1000000b */ 	b	.L0004bd48
/*    4bd1c:	24030008 */ 	addiu	$v1,$zero,0x8
.L0004bd20:
/*    4bd20:	2b010040 */ 	slti	$at,$t8,0x40
/*    4bd24:	14200008 */ 	bnez	$at,.L0004bd48
/*    4bd28:	00000000 */ 	nop
/*    4bd2c:	10000006 */ 	b	.L0004bd48
/*    4bd30:	2403ffff */ 	addiu	$v1,$zero,-1
.L0004bd34:
/*    4bd34:	2b210100 */ 	slti	$at,$t9,0x100
/*    4bd38:	14200003 */ 	bnez	$at,.L0004bd48
/*    4bd3c:	00000000 */ 	nop
/*    4bd40:	10000001 */ 	b	.L0004bd48
/*    4bd44:	2403ffff */ 	addiu	$v1,$zero,-1
.L0004bd48:
/*    4bd48:	10600005 */ 	beqz	$v1,.L0004bd60
/*    4bd4c:	93a8002e */ 	lbu	$t0,0x2e($sp)
/*    4bd50:	0c012a29 */ 	jal	__osSiRelAccess
/*    4bd54:	afa30044 */ 	sw	$v1,0x44($sp)
/*    4bd58:	10000032 */ 	b	.L0004be24
/*    4bd5c:	8fa20044 */ 	lw	$v0,0x44($sp)
.L0004bd60:
/*    4bd60:	31090080 */ 	andi	$t1,$t0,0x80
/*    4bd64:	11200007 */ 	beqz	$t1,.L0004bd84
/*    4bd68:	02202025 */ 	or	$a0,$s1,$zero
.L0004bd6c:
/*    4bd6c:	0c012fb9 */ 	jal	__osEepStatus
/*    4bd70:	02002825 */ 	or	$a1,$s0,$zero
/*    4bd74:	93aa002e */ 	lbu	$t2,0x2e($sp)
/*    4bd78:	314b0080 */ 	andi	$t3,$t2,0x80
/*    4bd7c:	5560fffb */ 	bnezl	$t3,.L0004bd6c
/*    4bd80:	02202025 */ 	or	$a0,$s1,$zero
.L0004bd84:
/*    4bd84:	93a4004f */ 	lbu	$a0,0x4f($sp)
/*    4bd88:	0c012f8e */ 	jal	__osPackEepWriteData
/*    4bd8c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    4bd90:	3c05800a */ 	lui	$a1,%hi(__osEepPifRam)
/*    4bd94:	24a5ca80 */ 	addiu	$a1,$a1,%lo(__osEepPifRam)
/*    4bd98:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4bd9c:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4bda0:	02202025 */ 	or	$a0,$s1,$zero
/*    4bda4:	00002825 */ 	or	$a1,$zero,$zero
/*    4bda8:	0c0121bc */ 	jal	osRecvMesg
/*    4bdac:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4bdb0:	3c05800a */ 	lui	$a1,%hi(__osEepPifRam)
/*    4bdb4:	24a5ca80 */ 	addiu	$a1,$a1,%lo(__osEepPifRam)
/*    4bdb8:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4bdbc:	00002025 */ 	or	$a0,$zero,$zero
/*    4bdc0:	240c0005 */ 	addiu	$t4,$zero,0x5
/*    4bdc4:	3c01800a */ 	lui	$at,%hi(__osContLastCmd)
/*    4bdc8:	a02cc820 */ 	sb	$t4,%lo(__osContLastCmd)($at)
/*    4bdcc:	02202025 */ 	or	$a0,$s1,$zero
/*    4bdd0:	00002825 */ 	or	$a1,$zero,$zero
/*    4bdd4:	0c0121bc */ 	jal	osRecvMesg
/*    4bdd8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4bddc:	3c07800a */ 	lui	$a3,%hi(var8009ca84)
/*    4bde0:	24e7ca84 */ 	addiu	$a3,$a3,%lo(var8009ca84)
/*    4bde4:	88e10000 */ 	lwl	$at,0x0($a3)
/*    4bde8:	98e10003 */ 	lwr	$at,0x3($a3)
/*    4bdec:	27ad0030 */ 	addiu	$t5,$sp,0x30
/*    4bdf0:	ada10000 */ 	sw	$at,0x0($t5)
/*    4bdf4:	88f80004 */ 	lwl	$t8,0x4($a3)
/*    4bdf8:	98f80007 */ 	lwr	$t8,0x7($a3)
/*    4bdfc:	adb80004 */ 	sw	$t8,0x4($t5)
/*    4be00:	88e10008 */ 	lwl	$at,0x8($a3)
/*    4be04:	98e1000b */ 	lwr	$at,0xb($a3)
/*    4be08:	ada10008 */ 	sw	$at,0x8($t5)
/*    4be0c:	93a30031 */ 	lbu	$v1,0x31($sp)
/*    4be10:	307900c0 */ 	andi	$t9,$v1,0xc0
/*    4be14:	00194103 */ 	sra	$t0,$t9,0x4
/*    4be18:	0c012a29 */ 	jal	__osSiRelAccess
/*    4be1c:	afa80044 */ 	sw	$t0,0x44($sp)
/*    4be20:	8fa20044 */ 	lw	$v0,0x44($sp)
.L0004be24:
/*    4be24:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4be28:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    4be2c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    4be30:	03e00008 */ 	jr	$ra
/*    4be34:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel __osPackEepWriteData
/*    4be38:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4be3c:	3c07800a */ 	lui	$a3,%hi(__osEepPifRam)
/*    4be40:	24e7ca80 */ 	addiu	$a3,$a3,%lo(__osEepPifRam)
/*    4be44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4be48:	2418000a */ 	addiu	$t8,$zero,0xa
/*    4be4c:	24190001 */ 	addiu	$t9,$zero,0x1
/*    4be50:	24080005 */ 	addiu	$t0,$zero,0x5
/*    4be54:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4be58:	acef003c */ 	sw	$t7,0x3c($a3)
/*    4be5c:	a3b80008 */ 	sb	$t8,0x8($sp)
/*    4be60:	a3b90009 */ 	sb	$t9,0x9($sp)
/*    4be64:	a3a8000a */ 	sb	$t0,0xa($sp)
/*    4be68:	a3a4000b */ 	sb	$a0,0xb($sp)
/*    4be6c:	27a60008 */ 	addiu	$a2,$sp,0x8
/*    4be70:	27a20010 */ 	addiu	$v0,$sp,0x10
.L0004be74:
/*    4be74:	90a90000 */ 	lbu	$t1,0x0($a1)
/*    4be78:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    4be7c:	00c2082b */ 	sltu	$at,$a2,$v0
/*    4be80:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    4be84:	1420fffb */ 	bnez	$at,.L0004be74
/*    4be88:	a0c90003 */ 	sb	$t1,0x3($a2)
/*    4be8c:	3c01800a */ 	lui	$at,%hi(__osEepPifRam)
/*    4be90:	3c02800a */ 	lui	$v0,%hi(__osEepPifRam+0x1)
/*    4be94:	2442ca81 */ 	addiu	$v0,$v0,%lo(__osEepPifRam+0x1)
/*    4be98:	a020ca80 */ 	sb	$zero,%lo(__osEepPifRam)($at)
/*    4be9c:	a0400002 */ 	sb	$zero,0x2($v0)
/*    4bea0:	a0400001 */ 	sb	$zero,0x1($v0)
/*    4bea4:	a0400000 */ 	sb	$zero,0x0($v0)
/*    4bea8:	27aa0008 */ 	addiu	$t2,$sp,0x8
/*    4beac:	8d410000 */ 	lw	$at,0x0($t2)
/*    4beb0:	240d00fe */ 	addiu	$t5,$zero,0xfe
/*    4beb4:	2442000f */ 	addiu	$v0,$v0,0xf
/*    4beb8:	a841fff4 */ 	swl	$at,-0xc($v0)
/*    4bebc:	b841fff7 */ 	swr	$at,-0x9($v0)
/*    4bec0:	8d4c0004 */ 	lw	$t4,0x4($t2)
/*    4bec4:	a84cfff8 */ 	swl	$t4,-0x8($v0)
/*    4bec8:	b84cfffb */ 	swr	$t4,-0x5($v0)
/*    4becc:	8d410008 */ 	lw	$at,0x8($t2)
/*    4bed0:	a04d0000 */ 	sb	$t5,0x0($v0)
/*    4bed4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4bed8:	a841fffc */ 	swl	$at,-0x4($v0)
/*    4bedc:	03e00008 */ 	jr	$ra
/*    4bee0:	b841ffff */ 	swr	$at,-0x1($v0)
);

GLOBAL_ASM(
glabel __osEepStatus
/*    4bee4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4bee8:	3c02800a */ 	lui	$v0,%hi(__osEepPifRam)
/*    4beec:	3c03800a */ 	lui	$v1,%hi(var8009cac0)
/*    4bef0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4bef4:	afa40030 */ 	sw	$a0,0x30($sp)
/*    4bef8:	afa50034 */ 	sw	$a1,0x34($sp)
/*    4befc:	2463cac0 */ 	addiu	$v1,$v1,%lo(var8009cac0)
/*    4bf00:	2442ca80 */ 	addiu	$v0,$v0,%lo(__osEepPifRam)
.L0004bf04:
/*    4bf04:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4bf08:	0043082b */ 	sltu	$at,$v0,$v1
/*    4bf0c:	1420fffd */ 	bnez	$at,.L0004bf04
/*    4bf10:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*    4bf14:	3c05800a */ 	lui	$a1,%hi(__osEepPifRam)
/*    4bf18:	24a5ca80 */ 	addiu	$a1,$a1,%lo(__osEepPifRam)
/*    4bf1c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4bf20:	acae003c */ 	sw	$t6,0x3c($a1)
/*    4bf24:	00a01025 */ 	or	$v0,$a1,$zero
/*    4bf28:	00001825 */ 	or	$v1,$zero,$zero
.L0004bf2c:
/*    4bf2c:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4bf30:	28610004 */ 	slti	$at,$v1,0x4
/*    4bf34:	a0400000 */ 	sb	$zero,0x0($v0)
/*    4bf38:	1420fffc */ 	bnez	$at,.L0004bf2c
/*    4bf3c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4bf40:	240f00ff */ 	addiu	$t7,$zero,0xff
/*    4bf44:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4bf48:	24190003 */ 	addiu	$t9,$zero,0x3
/*    4bf4c:	240800ff */ 	addiu	$t0,$zero,0xff
/*    4bf50:	240900ff */ 	addiu	$t1,$zero,0xff
/*    4bf54:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    4bf58:	240b00ff */ 	addiu	$t3,$zero,0xff
/*    4bf5c:	a3af001c */ 	sb	$t7,0x1c($sp)
/*    4bf60:	a3b8001d */ 	sb	$t8,0x1d($sp)
/*    4bf64:	a3b9001e */ 	sb	$t9,0x1e($sp)
/*    4bf68:	a3a0001f */ 	sb	$zero,0x1f($sp)
/*    4bf6c:	a3a80020 */ 	sb	$t0,0x20($sp)
/*    4bf70:	a3a90021 */ 	sb	$t1,0x21($sp)
/*    4bf74:	a3aa0022 */ 	sb	$t2,0x22($sp)
/*    4bf78:	a3ab0023 */ 	sb	$t3,0x23($sp)
/*    4bf7c:	27ac001c */ 	addiu	$t4,$sp,0x1c
/*    4bf80:	8d810000 */ 	lw	$at,0x0($t4)
/*    4bf84:	241800fe */ 	addiu	$t8,$zero,0xfe
/*    4bf88:	24420008 */ 	addiu	$v0,$v0,0x8
/*    4bf8c:	a841fff8 */ 	swl	$at,-0x8($v0)
/*    4bf90:	b841fffb */ 	swr	$at,-0x5($v0)
/*    4bf94:	8d8f0004 */ 	lw	$t7,0x4($t4)
/*    4bf98:	a0580000 */ 	sb	$t8,0x0($v0)
/*    4bf9c:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4bfa0:	a84ffffc */ 	swl	$t7,-0x4($v0)
/*    4bfa4:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4bfa8:	b84fffff */ 	swr	$t7,-0x1($v0)
/*    4bfac:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    4bfb0:	00002825 */ 	or	$a1,$zero,$zero
/*    4bfb4:	0c0121bc */ 	jal	osRecvMesg
/*    4bfb8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4bfbc:	241900fe */ 	addiu	$t9,$zero,0xfe
/*    4bfc0:	3c01800a */ 	lui	$at,%hi(__osContLastCmd)
/*    4bfc4:	3c05800a */ 	lui	$a1,%hi(__osEepPifRam)
/*    4bfc8:	a039c820 */ 	sb	$t9,%lo(__osContLastCmd)($at)
/*    4bfcc:	24a5ca80 */ 	addiu	$a1,$a1,%lo(__osEepPifRam)
/*    4bfd0:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4bfd4:	00002025 */ 	or	$a0,$zero,$zero
/*    4bfd8:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    4bfdc:	00002825 */ 	or	$a1,$zero,$zero
/*    4bfe0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4bfe4:	0c0121bc */ 	jal	osRecvMesg
/*    4bfe8:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    4bfec:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*    4bff0:	3c02800a */ 	lui	$v0,%hi(__osEepPifRam+0x1)
/*    4bff4:	2442ca81 */ 	addiu	$v0,$v0,%lo(__osEepPifRam+0x1)
/*    4bff8:	10600003 */ 	beqz	$v1,.L0004c008
/*    4bffc:	3c01800a */ 	lui	$at,%hi(__osEepPifRam)
/*    4c000:	1000001e */ 	b	.L0004c07c
/*    4c004:	00601025 */ 	or	$v0,$v1,$zero
.L0004c008:
/*    4c008:	a020ca80 */ 	sb	$zero,%lo(__osEepPifRam)($at)
/*    4c00c:	88410003 */ 	lwl	$at,0x3($v0)
/*    4c010:	98410006 */ 	lwr	$at,0x6($v0)
/*    4c014:	a0400002 */ 	sb	$zero,0x2($v0)
/*    4c018:	a0400001 */ 	sb	$zero,0x1($v0)
/*    4c01c:	a0400000 */ 	sb	$zero,0x0($v0)
/*    4c020:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    4c024:	27a8001c */ 	addiu	$t0,$sp,0x1c
/*    4c028:	ad010000 */ 	sw	$at,0x0($t0)
/*    4c02c:	884a0007 */ 	lwl	$t2,0x7($v0)
/*    4c030:	984a000a */ 	lwr	$t2,0xa($v0)
/*    4c034:	24420003 */ 	addiu	$v0,$v0,0x3
/*    4c038:	00001025 */ 	or	$v0,$zero,$zero
/*    4c03c:	ad0a0004 */ 	sw	$t2,0x4($t0)
/*    4c040:	93ab001e */ 	lbu	$t3,0x1e($sp)
/*    4c044:	316e00c0 */ 	andi	$t6,$t3,0xc0
/*    4c048:	000e6903 */ 	sra	$t5,$t6,0x4
/*    4c04c:	a08d0003 */ 	sb	$t5,0x3($a0)
/*    4c050:	93ac0021 */ 	lbu	$t4,0x21($sp)
/*    4c054:	93b80020 */ 	lbu	$t8,0x20($sp)
/*    4c058:	31a300ff */ 	andi	$v1,$t5,0xff
/*    4c05c:	000c7a00 */ 	sll	$t7,$t4,0x8
/*    4c060:	01f8c825 */ 	or	$t9,$t7,$t8
/*    4c064:	a4990000 */ 	sh	$t9,0x0($a0)
/*    4c068:	93a90022 */ 	lbu	$t1,0x22($sp)
/*    4c06c:	10600003 */ 	beqz	$v1,.L0004c07c
/*    4c070:	a0890002 */ 	sb	$t1,0x2($a0)
/*    4c074:	10000001 */ 	b	.L0004c07c
/*    4c078:	00601025 */ 	or	$v0,$v1,$zero
.L0004c07c:
/*    4c07c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4c080:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4c084:	03e00008 */ 	jr	$ra
/*    4c088:	00000000 */ 	nop
/*    4c08c:	00000000 */ 	nop
);
