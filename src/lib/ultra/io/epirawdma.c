#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel osEPiRawStartDma
/*    49c20:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    49c24:	3c03a460 */ 	lui	$v1,0xa460
/*    49c28:	34630010 */ 	ori	$v1,$v1,0x10
/*    49c2c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    49c30:	afb00018 */ 	sw	$s0,0x18($sp)
/*    49c34:	afa60028 */ 	sw	$a2,0x28($sp)
/*    49c38:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49c3c:	00808025 */ 	or	$s0,$a0,$zero
/*    49c40:	304e0003 */ 	andi	$t6,$v0,0x3
/*    49c44:	51c00006 */ 	beqzl	$t6,.L00049c60
/*    49c48:	92020009 */ 	lbu	$v0,0x9($s0)
/*    49c4c:	8c620000 */ 	lw	$v0,0x0($v1)
.L00049c50:
/*    49c50:	304f0003 */ 	andi	$t7,$v0,0x3
/*    49c54:	55e0fffe */ 	bnezl	$t7,.L00049c50
/*    49c58:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49c5c:	92020009 */ 	lbu	$v0,0x9($s0)
.L00049c60:
/*    49c60:	3c048006 */ 	lui	$a0,%hi(__osCurrentHandle)
/*    49c64:	92190004 */ 	lbu	$t9,0x4($s0)
/*    49c68:	0002c080 */ 	sll	$t8,$v0,0x2
/*    49c6c:	00982021 */ 	addu	$a0,$a0,$t8
/*    49c70:	8c84cf20 */ 	lw	$a0,%lo(__osCurrentHandle)($a0)
/*    49c74:	90880004 */ 	lbu	$t0,0x4($a0)
/*    49c78:	5328003d */ 	beql	$t9,$t0,.L00049d70
/*    49c7c:	00e02025 */ 	or	$a0,$a3,$zero
/*    49c80:	14400019 */ 	bnez	$v0,.L00049ce8
/*    49c84:	00801825 */ 	or	$v1,$a0,$zero
/*    49c88:	92020005 */ 	lbu	$v0,0x5($s0)
/*    49c8c:	90890005 */ 	lbu	$t1,0x5($a0)
/*    49c90:	3c0aa460 */ 	lui	$t2,0xa460
/*    49c94:	3c0ca460 */ 	lui	$t4,0xa460
/*    49c98:	10490002 */ 	beq	$v0,$t1,.L00049ca4
/*    49c9c:	3c0ea460 */ 	lui	$t6,0xa460
/*    49ca0:	ad420014 */ 	sw	$v0,0x14($t2)
.L00049ca4:
/*    49ca4:	92020006 */ 	lbu	$v0,0x6($s0)
/*    49ca8:	906b0006 */ 	lbu	$t3,0x6($v1)
/*    49cac:	3c18a460 */ 	lui	$t8,0xa460
/*    49cb0:	504b0003 */ 	beql	$v0,$t3,.L00049cc0
/*    49cb4:	92020007 */ 	lbu	$v0,0x7($s0)
/*    49cb8:	ad82001c */ 	sw	$v0,0x1c($t4)
/*    49cbc:	92020007 */ 	lbu	$v0,0x7($s0)
.L00049cc0:
/*    49cc0:	906d0007 */ 	lbu	$t5,0x7($v1)
/*    49cc4:	504d0003 */ 	beql	$v0,$t5,.L00049cd4
/*    49cc8:	92020008 */ 	lbu	$v0,0x8($s0)
/*    49ccc:	adc20020 */ 	sw	$v0,0x20($t6)
/*    49cd0:	92020008 */ 	lbu	$v0,0x8($s0)
.L00049cd4:
/*    49cd4:	906f0008 */ 	lbu	$t7,0x8($v1)
/*    49cd8:	504f001b */ 	beql	$v0,$t7,.L00049d48
/*    49cdc:	920f0004 */ 	lbu	$t7,0x4($s0)
/*    49ce0:	10000018 */ 	b	.L00049d44
/*    49ce4:	af020018 */ 	sw	$v0,0x18($t8)
.L00049ce8:
/*    49ce8:	92020005 */ 	lbu	$v0,0x5($s0)
/*    49cec:	90790005 */ 	lbu	$t9,0x5($v1)
/*    49cf0:	3c08a460 */ 	lui	$t0,0xa460
/*    49cf4:	3c0aa460 */ 	lui	$t2,0xa460
/*    49cf8:	10590002 */ 	beq	$v0,$t9,.L00049d04
/*    49cfc:	3c0ca460 */ 	lui	$t4,0xa460
/*    49d00:	ad020024 */ 	sw	$v0,0x24($t0)
.L00049d04:
/*    49d04:	92020006 */ 	lbu	$v0,0x6($s0)
/*    49d08:	90690006 */ 	lbu	$t1,0x6($v1)
/*    49d0c:	3c0ea460 */ 	lui	$t6,0xa460
/*    49d10:	50490003 */ 	beql	$v0,$t1,.L00049d20
/*    49d14:	92020007 */ 	lbu	$v0,0x7($s0)
/*    49d18:	ad42002c */ 	sw	$v0,0x2c($t2)
/*    49d1c:	92020007 */ 	lbu	$v0,0x7($s0)
.L00049d20:
/*    49d20:	906b0007 */ 	lbu	$t3,0x7($v1)
/*    49d24:	504b0003 */ 	beql	$v0,$t3,.L00049d34
/*    49d28:	92020008 */ 	lbu	$v0,0x8($s0)
/*    49d2c:	ad820030 */ 	sw	$v0,0x30($t4)
/*    49d30:	92020008 */ 	lbu	$v0,0x8($s0)
.L00049d34:
/*    49d34:	906d0008 */ 	lbu	$t5,0x8($v1)
/*    49d38:	504d0003 */ 	beql	$v0,$t5,.L00049d48
/*    49d3c:	920f0004 */ 	lbu	$t7,0x4($s0)
/*    49d40:	adc20028 */ 	sw	$v0,0x28($t6)
.L00049d44:
/*    49d44:	920f0004 */ 	lbu	$t7,0x4($s0)
.L00049d48:
/*    49d48:	a06f0004 */ 	sb	$t7,0x4($v1)
/*    49d4c:	92180005 */ 	lbu	$t8,0x5($s0)
/*    49d50:	a0780005 */ 	sb	$t8,0x5($v1)
/*    49d54:	92190006 */ 	lbu	$t9,0x6($s0)
/*    49d58:	a0790006 */ 	sb	$t9,0x6($v1)
/*    49d5c:	92080007 */ 	lbu	$t0,0x7($s0)
/*    49d60:	a0680007 */ 	sb	$t0,0x7($v1)
/*    49d64:	92090008 */ 	lbu	$t1,0x8($s0)
/*    49d68:	a0690008 */ 	sb	$t1,0x8($v1)
/*    49d6c:	00e02025 */ 	or	$a0,$a3,$zero
.L00049d70:
/*    49d70:	0c012d20 */ 	jal	osVirtualToPhysical
/*    49d74:	afa50024 */ 	sw	$a1,0x24($sp)
/*    49d78:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    49d7c:	3c0aa460 */ 	lui	$t2,0xa460
/*    49d80:	ad420000 */ 	sw	$v0,0x0($t2)
/*    49d84:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    49d88:	8e0b000c */ 	lw	$t3,0xc($s0)
/*    49d8c:	3c011fff */ 	lui	$at,0x1fff
/*    49d90:	3421ffff */ 	ori	$at,$at,0xffff
/*    49d94:	016c6825 */ 	or	$t5,$t3,$t4
/*    49d98:	01a17024 */ 	and	$t6,$t5,$at
/*    49d9c:	3c0fa460 */ 	lui	$t7,0xa460
/*    49da0:	10a00006 */ 	beqz	$a1,.L00049dbc
/*    49da4:	adee0004 */ 	sw	$t6,0x4($t7)
/*    49da8:	24010001 */ 	addiu	$at,$zero,0x1
/*    49dac:	10a10008 */ 	beq	$a1,$at,.L00049dd0
/*    49db0:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    49db4:	1000000d */ 	b	.L00049dec
/*    49db8:	2402ffff */ 	addiu	$v0,$zero,-1
.L00049dbc:
/*    49dbc:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    49dc0:	3c08a460 */ 	lui	$t0,0xa460
/*    49dc4:	2719ffff */ 	addiu	$t9,$t8,-1
/*    49dc8:	10000007 */ 	b	.L00049de8
/*    49dcc:	ad19000c */ 	sw	$t9,0xc($t0)
.L00049dd0:
/*    49dd0:	252affff */ 	addiu	$t2,$t1,-1
/*    49dd4:	3c0ba460 */ 	lui	$t3,0xa460
/*    49dd8:	10000003 */ 	b	.L00049de8
/*    49ddc:	ad6a0008 */ 	sw	$t2,0x8($t3)
/*    49de0:	10000002 */ 	b	.L00049dec
/*    49de4:	2402ffff */ 	addiu	$v0,$zero,-1
.L00049de8:
/*    49de8:	00001025 */ 	or	$v0,$zero,$zero
.L00049dec:
/*    49dec:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    49df0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    49df4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    49df8:	03e00008 */ 	jr	$ra
/*    49dfc:	00000000 */ 	nop
);

// Mismatch: branch/branch-likely
//s32 osEPiRawStartDma(OSPiHandle *pihandle, s32 direction, u32 devAddr, void *dramAddr, u32 size)
//{
//	u32 stat;
//
//    WAIT_ON_IOBUSY(stat)
//
//	if (pihandle->type != __osCurrentHandle[pihandle->domain]->type) {
//		OSPiHandle *cHandle = __osCurrentHandle[pihandle->domain];
//
//		if (pihandle->domain == PI_DOMAIN1) {
//			UPDATE_REG(PI_BSD_DOM1_LAT_REG, latency);
//			UPDATE_REG(PI_BSD_DOM1_PGS_REG, pageSize);
//			UPDATE_REG(PI_BSD_DOM1_RLS_REG, relDuration);
//			UPDATE_REG(PI_BSD_DOM1_PWD_REG, pulse);
//		} else {
//			UPDATE_REG(PI_BSD_DOM2_LAT_REG, latency);
//			UPDATE_REG(PI_BSD_DOM2_PGS_REG, pageSize);
//			UPDATE_REG(PI_BSD_DOM2_RLS_REG, relDuration);
//			UPDATE_REG(PI_BSD_DOM2_PWD_REG, pulse);
//		}
//
//		cHandle->type = pihandle->type;
//		cHandle->latency = pihandle->latency;
//		cHandle->pageSize = pihandle->pageSize;
//		cHandle->relDuration = pihandle->relDuration;
//		cHandle->pulse = pihandle->pulse;
//	}
//
//	IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
//	IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS(pihandle->baseAddress | devAddr));
//
//	switch (direction) {
//	case OS_READ:
//		IO_WRITE(PI_WR_LEN_REG, size - 1);
//		break;
//	case OS_WRITE:
//		IO_WRITE(PI_RD_LEN_REG, size - 1);
//		break;
//	default:
//		return -1;
//	}
//
//	return 0;
//}
