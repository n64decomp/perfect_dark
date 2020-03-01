#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004ae00
/*    4ae00:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4ae04:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4ae08:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4ae0c:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4ae10:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4ae14:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4ae18:	01ee1016 */ 	dsrlv	$v0,$t6,$t7
/*    4ae1c:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4ae20:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4ae24:	03e00008 */ 	jr	$ra
/*    4ae28:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0004ae2c
/*    4ae2c:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4ae30:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4ae34:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4ae38:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4ae3c:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4ae40:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4ae44:	01cf001f */ 	ddivu	$zero,$t6,$t7
/*    4ae48:	15e00002 */ 	bnez	$t7,.L0004ae54
/*    4ae4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ae50:	0007000d */ 	break	0x7
.L0004ae54:
/*    4ae54:	00001010 */ 	mfhi	$v0
/*    4ae58:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4ae5c:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4ae60:	03e00008 */ 	jr	$ra
/*    4ae64:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0004ae68
/*    4ae68:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4ae6c:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4ae70:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4ae74:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4ae78:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4ae7c:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4ae80:	01cf001f */ 	ddivu	$zero,$t6,$t7
/*    4ae84:	15e00002 */ 	bnez	$t7,.L0004ae90
/*    4ae88:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ae8c:	0007000d */ 	break	0x7
.L0004ae90:
/*    4ae90:	00001012 */ 	mflo	$v0
/*    4ae94:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4ae98:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4ae9c:	03e00008 */ 	jr	$ra
/*    4aea0:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0004aea4
/*    4aea4:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4aea8:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4aeac:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4aeb0:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4aeb4:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4aeb8:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4aebc:	01ee1014 */ 	dsllv	$v0,$t6,$t7
/*    4aec0:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4aec4:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4aec8:	03e00008 */ 	jr	$ra
/*    4aecc:	0002103f */ 	dsra32	$v0,$v0,0x0
/*    4aed0:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4aed4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4aed8:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4aedc:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4aee0:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4aee4:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4aee8:	01cf001f */ 	ddivu	$zero,$t6,$t7
/*    4aeec:	15e00002 */ 	bnez	$t7,.L0004aef8
/*    4aef0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4aef4:	0007000d */ 	break	0x7
.L0004aef8:
/*    4aef8:	00001010 */ 	mfhi	$v0
/*    4aefc:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4af00:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4af04:	03e00008 */ 	jr	$ra
/*    4af08:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0004af0c
/*    4af0c:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4af10:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4af14:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4af18:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4af1c:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4af20:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4af24:	01cf001e */ 	ddiv	$zero,$t6,$t7
/*    4af28:	00000000 */ 	sll	$zero,$zero,0x0
/*    4af2c:	15e00002 */ 	bnez	$t7,.L0004af38
/*    4af30:	00000000 */ 	sll	$zero,$zero,0x0
/*    4af34:	0007000d */ 	break	0x7
.L0004af38:
/*    4af38:	6401ffff */ 	daddiu	$at,$zero,-1
/*    4af3c:	15e10005 */ 	bne	$t7,$at,.L0004af54
/*    4af40:	64010001 */ 	daddiu	$at,$zero,0x1
/*    4af44:	00010ffc */ 	dsll32	$at,$at,0x1f
/*    4af48:	15c10002 */ 	bne	$t6,$at,.L0004af54
/*    4af4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4af50:	0006000d */ 	break	0x6
.L0004af54:
/*    4af54:	00001012 */ 	mflo	$v0
/*    4af58:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4af5c:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4af60:	03e00008 */ 	jr	$ra
/*    4af64:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0004af68
/*    4af68:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4af6c:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4af70:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4af74:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4af78:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4af7c:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4af80:	01cf001d */ 	dmultu	$t6,$t7
/*    4af84:	00001012 */ 	mflo	$v0
/*    4af88:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4af8c:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4af90:	03e00008 */ 	jr	$ra
/*    4af94:	0002103f */ 	dsra32	$v0,$v0,0x0
/*    4af98:	87af0012 */ 	lh	$t7,0x12($sp)
/*    4af9c:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4afa0:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4afa4:	dfae0008 */ 	ld	$t6,0x8($sp)
/*    4afa8:	01e0c025 */ 	or	$t8,$t7,$zero
/*    4afac:	0300c825 */ 	or	$t9,$t8,$zero
/*    4afb0:	01d9001f */ 	ddivu	$zero,$t6,$t9
/*    4afb4:	17200002 */ 	bnez	$t9,.L0004afc0
/*    4afb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4afbc:	0007000d */ 	break	0x7
.L0004afc0:
/*    4afc0:	00004012 */ 	mflo	$t0
/*    4afc4:	fc880000 */ 	sd	$t0,0x0($a0)
/*    4afc8:	87aa0012 */ 	lh	$t2,0x12($sp)
/*    4afcc:	dfa90008 */ 	ld	$t1,0x8($sp)
/*    4afd0:	01405825 */ 	or	$t3,$t2,$zero
/*    4afd4:	01606025 */ 	or	$t4,$t3,$zero
/*    4afd8:	012c001f */ 	ddivu	$zero,$t1,$t4
/*    4afdc:	15800002 */ 	bnez	$t4,.L0004afe8
/*    4afe0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4afe4:	0007000d */ 	break	0x7
.L0004afe8:
/*    4afe8:	00006810 */ 	mfhi	$t5
/*    4afec:	fcad0000 */ 	sd	$t5,0x0($a1)
/*    4aff0:	03e00008 */ 	jr	$ra
/*    4aff4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4aff8:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    4affc:	afa40008 */ 	sw	$a0,0x8($sp)
/*    4b000:	afa5000c */ 	sw	$a1,0xc($sp)
/*    4b004:	afa60010 */ 	sw	$a2,0x10($sp)
/*    4b008:	afa70014 */ 	sw	$a3,0x14($sp)
/*    4b00c:	dfaf0010 */ 	ld	$t7,0x10($sp)
/*    4b010:	dfae0008 */ 	ld	$t6,0x8($sp)
/*    4b014:	01cf001e */ 	ddiv	$zero,$t6,$t7
/*    4b018:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b01c:	15e00002 */ 	bnez	$t7,.L0004b028
/*    4b020:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b024:	0007000d */ 	break	0x7
.L0004b028:
/*    4b028:	6401ffff */ 	daddiu	$at,$zero,-1
/*    4b02c:	15e10005 */ 	bne	$t7,$at,.L0004b044
/*    4b030:	64010001 */ 	daddiu	$at,$zero,0x1
/*    4b034:	00010ffc */ 	dsll32	$at,$at,0x1f
/*    4b038:	15c10002 */ 	bne	$t6,$at,.L0004b044
/*    4b03c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b040:	0006000d */ 	break	0x6
.L0004b044:
/*    4b044:	0000c010 */ 	mfhi	$t8
/*    4b048:	ffb80000 */ 	sd	$t8,0x0($sp)
/*    4b04c:	07010003 */ 	bgez	$t8,.L0004b05c
/*    4b050:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b054:	1de00007 */ 	bgtz	$t7,.L0004b074
/*    4b058:	00000000 */ 	sll	$zero,$zero,0x0
.L0004b05c:
/*    4b05c:	dfb90000 */ 	ld	$t9,0x0($sp)
/*    4b060:	1b200008 */ 	blez	$t9,.L0004b084
/*    4b064:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b068:	dfa80010 */ 	ld	$t0,0x10($sp)
/*    4b06c:	05010005 */ 	bgez	$t0,.L0004b084
/*    4b070:	00000000 */ 	sll	$zero,$zero,0x0
.L0004b074:
/*    4b074:	dfa90000 */ 	ld	$t1,0x0($sp)
/*    4b078:	dfaa0010 */ 	ld	$t2,0x10($sp)
/*    4b07c:	012a582d */ 	daddu	$t3,$t1,$t2
/*    4b080:	ffab0000 */ 	sd	$t3,0x0($sp)
.L0004b084:
/*    4b084:	8fa20000 */ 	lw	$v0,0x0($sp)
/*    4b088:	8fa30004 */ 	lw	$v1,0x4($sp)
/*    4b08c:	03e00008 */ 	jr	$ra
/*    4b090:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    4b094:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4b098:	afa50004 */ 	sw	$a1,0x4($sp)
/*    4b09c:	afa60008 */ 	sw	$a2,0x8($sp)
/*    4b0a0:	afa7000c */ 	sw	$a3,0xc($sp)
/*    4b0a4:	dfaf0008 */ 	ld	$t7,0x8($sp)
/*    4b0a8:	dfae0000 */ 	ld	$t6,0x0($sp)
/*    4b0ac:	01ee1017 */ 	dsrav	$v0,$t6,$t7
/*    4b0b0:	0002183c */ 	dsll32	$v1,$v0,0x0
/*    4b0b4:	0003183f */ 	dsra32	$v1,$v1,0x0
/*    4b0b8:	03e00008 */ 	jr	$ra
/*    4b0bc:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0004b0c0
/*    4b0c0:	28a1000c */ 	slti	$at,$a1,0xc
/*    4b0c4:	1420001d */ 	bnez	$at,.L0004b13c
/*    4b0c8:	00041823 */ 	negu	$v1,$a0
/*    4b0cc:	30630003 */ 	andi	$v1,$v1,0x3
/*    4b0d0:	10600003 */ 	beqz	$v1,.L0004b0e0
/*    4b0d4:	00a32823 */ 	subu	$a1,$a1,$v1
/*    4b0d8:	a8800000 */ 	swl	$zero,0x0($a0)
/*    4b0dc:	00832021 */ 	addu	$a0,$a0,$v1
.L0004b0e0:
/*    4b0e0:	2401ffe0 */ 	addiu	$at,$zero,-32
/*    4b0e4:	00a13824 */ 	and	$a3,$a1,$at
/*    4b0e8:	10e0000c */ 	beqz	$a3,.L0004b11c
/*    4b0ec:	00a72823 */ 	subu	$a1,$a1,$a3
/*    4b0f0:	00e43821 */ 	addu	$a3,$a3,$a0
.L0004b0f4:
/*    4b0f4:	24840020 */ 	addiu	$a0,$a0,0x20
/*    4b0f8:	ac80ffe0 */ 	sw	$zero,-0x20($a0)
/*    4b0fc:	ac80ffe4 */ 	sw	$zero,-0x1c($a0)
/*    4b100:	ac80ffe8 */ 	sw	$zero,-0x18($a0)
/*    4b104:	ac80ffec */ 	sw	$zero,-0x14($a0)
/*    4b108:	ac80fff0 */ 	sw	$zero,-0x10($a0)
/*    4b10c:	ac80fff4 */ 	sw	$zero,-0xc($a0)
/*    4b110:	ac80fff8 */ 	sw	$zero,-0x8($a0)
/*    4b114:	1487fff7 */ 	bne	$a0,$a3,.L0004b0f4
/*    4b118:	ac80fffc */ 	sw	$zero,-0x4($a0)
.L0004b11c:
/*    4b11c:	2401fffc */ 	addiu	$at,$zero,-4
/*    4b120:	00a13824 */ 	and	$a3,$a1,$at
/*    4b124:	10e00005 */ 	beqz	$a3,.L0004b13c
/*    4b128:	00a72823 */ 	subu	$a1,$a1,$a3
/*    4b12c:	00e43821 */ 	addu	$a3,$a3,$a0
.L0004b130:
/*    4b130:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4b134:	1487fffe */ 	bne	$a0,$a3,.L0004b130
/*    4b138:	ac80fffc */ 	sw	$zero,-0x4($a0)
.L0004b13c:
/*    4b13c:	18a00005 */ 	blez	$a1,.L0004b154
/*    4b140:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b144:	00a42821 */ 	addu	$a1,$a1,$a0
.L0004b148:
/*    4b148:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4b14c:	1485fffe */ 	bne	$a0,$a1,.L0004b148
/*    4b150:	a080ffff */ 	sb	$zero,-0x1($a0)
.L0004b154:
/*    4b154:	03e00008 */ 	jr	$ra
/*    4b158:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b15c:	00000000 */ 	sll	$zero,$zero,0x0
);