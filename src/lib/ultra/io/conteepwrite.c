#include <libultra_internal.h>
#include "bss.h"
#include "data.h"

void __osPackEepWriteData(u8 address, u8 *buffer);

s32 osEepromWrite(OSMesgQueue *mq, u8 address, u8 *buffer)
{
	s32 ret;
	u16 type;
	u8 *ptr;
	__OSContEepromFormat eepromformat;
	OSContStatus sdata;

	ret = 0;
	ptr = (u8 *)&__osEepPifRam.ramarray;
	__osSiGetAccess();
	ret = __osEepStatus(mq, &sdata);

	type = sdata.type & (CONT_EEPROM | CONT_EEP16K);

	if (ret == 0) {
		switch (type) {
		case CONT_EEPROM:
			// @bug: Should be > EEPROM_MAXBLOCKS
			if (address >= EEPROM_MAXBLOCKS) {
				ret = -1;
			}
			break;
		case CONT_EEPROM | CONT_EEP16K:
			// @bug: Should be > EEP16K_MAXBLOCKS
			if (address >= EEP16K_MAXBLOCKS) {
				ret = -1;
			}
			break;
		default:
			if (1);
			ret = CONT_NO_RESPONSE_ERROR;
			break;
		}
	}

	if (ret != 0) {
		__osSiRelAccess();
		return ret;
	}

	while (sdata.status & CONT_EEPROM_BUSY) {
		__osEepStatus(mq, &sdata);
	}

	__osPackEepWriteData(address, buffer);

	ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam);
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);

	ret = __osSiRawStartDma(OS_READ, &__osEepPifRam);
	__osContLastCmd = CONT_CMD_WRITE_EEPROM;
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);

	ptr += 4;

	eepromformat = *(__OSContEepromFormat *)ptr;

	ret = CHNL_ERR(eepromformat);

	__osSiRelAccess();
	return ret;
}

void __osPackEepWriteData(u8 address, u8 *buffer)
{
	u8 *ptr;
	__OSContEepromFormat eepromformat;
	int i;
	ptr = (u8 *)&__osEepPifRam.ramarray;
	__osEepPifRam.pifstatus = CONT_CMD_EXE;

	eepromformat.txsize = CONT_CMD_WRITE_EEPROM_TX;
	eepromformat.rxsize = CONT_CMD_WRITE_EEPROM_RX;
	eepromformat.cmd = CONT_CMD_WRITE_EEPROM;
	eepromformat.address = address;

	for (i = 0; i < ARRLEN(eepromformat.data); i++) {
		eepromformat.data[i] = *buffer++;
	}

	for (i = 0; i < 4; i++) {
		*ptr++ = 0;
	}

	*(__OSContEepromFormat *)(ptr) = eepromformat;
	ptr += sizeof(__OSContEepromFormat);
	ptr[0] = CONT_CMD_END;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel __osEepStatus
/*    4bee4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4bee8:	3c02800a */ 	lui	$v0,%hi(__osEepPifRam)
/*    4beec:	3c03800a */ 	lui	$v1,%hi(var8009d010pf)
/*    4bef0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4bef4:	afa40030 */ 	sw	$a0,0x30($sp)
/*    4bef8:	afa50034 */ 	sw	$a1,0x34($sp)
/*    4befc:	2463cac0 */ 	addiu	$v1,$v1,%lo(var8009d010pf)
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
);
#else
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
);
#endif
