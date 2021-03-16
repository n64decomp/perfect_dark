#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_06100.h"
#include "lib/lib_06330.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4d6f0.h"
#include "lib/lib_50a00.h"
#include "lib/lib_513b0.h"
#include "data.h"
#include "types.h"

u32 var800611f0 = 0xceed6666;
u32 var800611f4 = 0xcc0d000b;
u32 var800611f8 = 0x03730083;
u32 var800611fc = 0x000c000d;
u32 var80061200 = 0x0008111f;
u32 var80061204 = 0x8889000e;
u32 var80061208 = 0xdccc6ee6;
u32 var8006120c = 0xddddd999;
u32 var80061210 = 0xbbbb6763;
u32 var80061214 = 0x6e0eeccc;
u32 var80061218 = 0xdddc999f;
u32 var8006121c = 0xbbb9333e;

u32 var80061220 = 0x00010101;
u32 var80061224 = 0xff0202ff;
u32 var80061228 = 0x0000ffff;
u32 var8006122c = 0xffffff03;
u32 var80061230 = 0x03030303;

GLOBAL_ASM(
glabel func00050d60
/*    50d60:	27bdff70 */ 	addiu	$sp,$sp,-144
/*    50d64:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    50d68:	afa50094 */ 	sw	$a1,0x94($sp)
/*    50d6c:	afa40090 */ 	sw	$a0,0x90($sp)
/*    50d70:	afa60098 */ 	sw	$a2,0x98($sp)
/*    50d74:	0c0142f8 */ 	jal	func00050be0
/*    50d78:	00c02825 */ 	or	$a1,$a2,$zero
/*    50d7c:	2401000d */ 	addiu	$at,$zero,0xd
/*    50d80:	14410005 */ 	bne	$v0,$at,.L00050d98
/*    50d84:	00403825 */ 	or	$a3,$v0,$zero
/*    50d88:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50d8c:	0c0142f8 */ 	jal	func00050be0
/*    50d90:	8fa50098 */ 	lw	$a1,0x98($sp)
/*    50d94:	00403825 */ 	or	$a3,$v0,$zero
.L00050d98:
/*    50d98:	2401000d */ 	addiu	$at,$zero,0xd
/*    50d9c:	14410003 */ 	bne	$v0,$at,.L00050dac
/*    50da0:	00000000 */ 	nop
/*    50da4:	10000058 */ 	b	.L00050f08
/*    50da8:	24020004 */ 	addiu	$v0,$zero,0x4
.L00050dac:
/*    50dac:	14400055 */ 	bnez	$v0,.L00050f04
/*    50db0:	8fae0098 */ 	lw	$t6,0x98($sp)
/*    50db4:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*    50db8:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50dbc:	31f80001 */ 	andi	$t8,$t7,0x1
/*    50dc0:	57000008 */ 	bnezl	$t8,.L00050de4
/*    50dc4:	24190060 */ 	addiu	$t9,$zero,0x60
/*    50dc8:	0c0018cc */ 	jal	func00006330
/*    50dcc:	24050001 */ 	addiu	$a1,$zero,0x1
/*    50dd0:	50400004 */ 	beqzl	$v0,.L00050de4
/*    50dd4:	24190060 */ 	addiu	$t9,$zero,0x60
/*    50dd8:	1000004c */ 	b	.L00050f0c
/*    50ddc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    50de0:	24190060 */ 	addiu	$t9,$zero,0x60
.L00050de4:
/*    50de4:	afb90010 */ 	sw	$t9,0x10($sp)
/*    50de8:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50dec:	00002825 */ 	or	$a1,$zero,$zero
/*    50df0:	24060100 */ 	addiu	$a2,$zero,0x100
/*    50df4:	0c0144ec */ 	jal	func000513b0
/*    50df8:	27a70024 */ 	addiu	$a3,$sp,0x24
/*    50dfc:	10400003 */ 	beqz	$v0,.L00050e0c
/*    50e00:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50e04:	10000041 */ 	b	.L00050f0c
/*    50e08:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00050e0c:
/*    50e0c:	0c0142f8 */ 	jal	func00050be0
/*    50e10:	8fa50098 */ 	lw	$a1,0x98($sp)
/*    50e14:	2401000d */ 	addiu	$at,$zero,0xd
/*    50e18:	14410002 */ 	bne	$v0,$at,.L00050e24
/*    50e1c:	00403825 */ 	or	$a3,$v0,$zero
/*    50e20:	24070004 */ 	addiu	$a3,$zero,0x4
.L00050e24:
/*    50e24:	10e00003 */ 	beqz	$a3,.L00050e34
/*    50e28:	3c048006 */ 	lui	$a0,%hi(var800611f0)
/*    50e2c:	10000036 */ 	b	.L00050f08
/*    50e30:	00e01025 */ 	or	$v0,$a3,$zero
.L00050e34:
/*    50e34:	248411f0 */ 	addiu	$a0,$a0,%lo(var800611f0)
/*    50e38:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    50e3c:	24060030 */ 	addiu	$a2,$zero,0x30
/*    50e40:	0c013824 */ 	jal	func0004e090
/*    50e44:	afa70088 */ 	sw	$a3,0x88($sp)
/*    50e48:	10400003 */ 	beqz	$v0,.L00050e58
/*    50e4c:	8fa70088 */ 	lw	$a3,0x88($sp)
/*    50e50:	1000002d */ 	b	.L00050f08
/*    50e54:	24020004 */ 	addiu	$v0,$zero,0x4
.L00050e58:
/*    50e58:	93a20058 */ 	lbu	$v0,0x58($sp)
/*    50e5c:	93a80059 */ 	lbu	$t0,0x59($sp)
/*    50e60:	27a3005a */ 	addiu	$v1,$sp,0x5a
/*    50e64:	27a40072 */ 	addiu	$a0,$sp,0x72
/*    50e68:	00481021 */ 	addu	$v0,$v0,$t0
/*    50e6c:	304900ff */ 	andi	$t1,$v0,0xff
/*    50e70:	01201025 */ 	or	$v0,$t1,$zero
.L00050e74:
/*    50e74:	906a0000 */ 	lbu	$t2,0x0($v1)
/*    50e78:	906c0001 */ 	lbu	$t4,0x1($v1)
/*    50e7c:	906e0002 */ 	lbu	$t6,0x2($v1)
/*    50e80:	90780003 */ 	lbu	$t8,0x3($v1)
/*    50e84:	004a5821 */ 	addu	$t3,$v0,$t2
/*    50e88:	016c6821 */ 	addu	$t5,$t3,$t4
/*    50e8c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    50e90:	01f81021 */ 	addu	$v0,$t7,$t8
/*    50e94:	305900ff */ 	andi	$t9,$v0,0xff
/*    50e98:	24630004 */ 	addiu	$v1,$v1,0x4
/*    50e9c:	1464fff5 */ 	bne	$v1,$a0,.L00050e74
/*    50ea0:	03201025 */ 	or	$v0,$t9,$zero
/*    50ea4:	27280019 */ 	addiu	$t0,$t9,0x19
/*    50ea8:	310900ff */ 	andi	$t1,$t0,0xff
/*    50eac:	11200003 */ 	beqz	$t1,.L00050ebc
/*    50eb0:	27a40024 */ 	addiu	$a0,$sp,0x24
/*    50eb4:	10000014 */ 	b	.L00050f08
/*    50eb8:	24020004 */ 	addiu	$v0,$zero,0x4
.L00050ebc:
/*    50ebc:	8fa50094 */ 	lw	$a1,0x94($sp)
/*    50ec0:	24060050 */ 	addiu	$a2,$zero,0x50
/*    50ec4:	0c012c5c */ 	jal	func0004b170
/*    50ec8:	afa70088 */ 	sw	$a3,0x88($sp)
/*    50ecc:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    50ed0:	3c0b8006 */ 	lui	$t3,%hi(var80061220)
/*    50ed4:	8fa70088 */ 	lw	$a3,0x88($sp)
/*    50ed8:	91420047 */ 	lbu	$v0,0x47($t2)
/*    50edc:	8fac0090 */ 	lw	$t4,0x90($sp)
/*    50ee0:	28410014 */ 	slti	$at,$v0,0x14
/*    50ee4:	10200003 */ 	beqz	$at,.L00050ef4
/*    50ee8:	01625821 */ 	addu	$t3,$t3,$v0
/*    50eec:	916b1220 */ 	lbu	$t3,%lo(var80061220)($t3)
/*    50ef0:	ad8b004c */ 	sw	$t3,0x4c($t4)
.L00050ef4:
/*    50ef4:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    50ef8:	8faf0090 */ 	lw	$t7,0x90($sp)
/*    50efc:	91ae0049 */ 	lbu	$t6,0x49($t5)
/*    50f00:	adee0050 */ 	sw	$t6,0x50($t7)
.L00050f04:
/*    50f04:	00e01025 */ 	or	$v0,$a3,$zero
.L00050f08:
/*    50f08:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00050f0c:
/*    50f0c:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*    50f10:	03e00008 */ 	jr	$ra
/*    50f14:	00000000 */ 	nop
);
