#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_0f09f0.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "game/game_176080.h"
#include "gvars/gvars.h"
#include "library/library_0e9d0.h"
#include "library/library_11420.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f16cfa0
/*  f16cfa0:	3c0e800a */ 	lui	$t6,0x800a
/*  f16cfa4:	8dcea474 */ 	lw	$t6,-0x5b8c($t6)
/*  f16cfa8:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f16cfac:	3c028008 */ 	lui	$v0,0x8008
/*  f16cfb0:	15c10003 */ 	bne	$t6,$at,.L0f16cfc0
/*  f16cfb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16cfb8:	03e00008 */ 	jr	$ra
/*  f16cfbc:	24025000 */ 	addiu	$v0,$zero,0x5000
.L0f16cfc0:
/*  f16cfc0:	944240ec */ 	lhu	$v0,0x40ec($v0)
/*  f16cfc4:	24035000 */ 	addiu	$v1,$zero,0x5000
/*  f16cfc8:	28415000 */ 	slti	$at,$v0,0x5000
/*  f16cfcc:	10200003 */ 	beqz	$at,.L0f16cfdc
/*  f16cfd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16cfd4:	10000001 */ 	beqz	$zero,.L0f16cfdc
/*  f16cfd8:	00401825 */ 	or	$v1,$v0,$zero
.L0f16cfdc:
/*  f16cfdc:	3062ffff */ 	andi	$v0,$v1,0xffff
/*  f16cfe0:	03e00008 */ 	jr	$ra
/*  f16cfe4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16cfe8
/*  f16cfe8:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f16cfec:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f16cff0:	3096ffff */ 	andi	$s6,$a0,0xffff
/*  f16cff4:	2ac15001 */ 	slti	$at,$s6,0x5001
/*  f16cff8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f16cffc:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f16d000:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f16d004:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f16d008:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f16d00c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f16d010:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16d014:	14200002 */ 	bnez	$at,.L0f16d020
/*  f16d018:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f16d01c:	24165000 */ 	addiu	$s6,$zero,0x5000
.L0f16d020:
/*  f16d020:	3c11800b */ 	lui	$s1,%hi(var800aaa38)
/*  f16d024:	3c138009 */ 	lui	$s3,%hi(var80094ed8)
/*  f16d028:	26734ed8 */ 	addiu	$s3,$s3,%lo(var80094ed8)
/*  f16d02c:	2631aa38 */ 	addiu	$s1,$s1,%lo(var800aaa38)
/*  f16d030:	00008025 */ 	or	$s0,$zero,$zero
/*  f16d034:	24150003 */ 	addiu	$s5,$zero,0x3
/*  f16d038:	24140108 */ 	addiu	$s4,$zero,0x108
/*  f16d03c:	24120005 */ 	addiu	$s2,$zero,0x5
.L0f16d040:
/*  f16d040:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f16d044:	5040000a */ 	beqzl	$v0,.L0f16d070
/*  f16d048:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d04c:	52420008 */ 	beql	$s2,$v0,.L0f16d070
/*  f16d050:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d054:	02140019 */ 	multu	$s0,$s4
/*  f16d058:	32c5ffff */ 	andi	$a1,$s6,0xffff
/*  f16d05c:	00007012 */ 	mflo	$t6
/*  f16d060:	026e2021 */ 	addu	$a0,$s3,$t6
/*  f16d064:	0c003f67 */ 	jal	func0000fd9c
/*  f16d068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d06c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f16d070:
/*  f16d070:	1615fff3 */ 	bne	$s0,$s5,.L0f16d040
/*  f16d074:	26310010 */ 	addiu	$s1,$s1,0x10
/*  f16d078:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f16d07c:	3c018008 */ 	lui	$at,0x8008
/*  f16d080:	a43640ec */ 	sh	$s6,0x40ec($at)
/*  f16d084:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f16d088:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16d08c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f16d090:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f16d094:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f16d098:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f16d09c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f16d0a0:	03e00008 */ 	jr	$ra
/*  f16d0a4:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f16d0a8
/*  f16d0a8:	3c03800b */ 	lui	$v1,%hi(var800aaa38)
/*  f16d0ac:	3c07800b */ 	lui	$a3,%hi(var800aaa68)
/*  f16d0b0:	24e7aa68 */ 	addiu	$a3,$a3,%lo(var800aaa68)
/*  f16d0b4:	2463aa38 */ 	addiu	$v1,$v1,%lo(var800aaa38)
/*  f16d0b8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f16d0bc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f16d0c0:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f16d0c4:
/*  f16d0c4:	548e0012 */ 	bnel	$a0,$t6,.L0f16d110
/*  f16d0c8:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f16d0cc:	50a00008 */ 	beqzl	$a1,.L0f16d0f0
/*  f16d0d0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f16d0d4:	10a20009 */ 	beq	$a1,$v0,.L0f16d0fc
/*  f16d0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d0dc:	10a60009 */ 	beq	$a1,$a2,.L0f16d104
/*  f16d0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d0e4:	1000000a */ 	beqz	$zero,.L0f16d110
/*  f16d0e8:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f16d0ec:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f16d0f0:
/*  f16d0f0:	2c4f0001 */ 	sltiu	$t7,$v0,0x1
/*  f16d0f4:	03e00008 */ 	jr	$ra
/*  f16d0f8:	01e01025 */ 	or	$v0,$t7,$zero
.L0f16d0fc:
/*  f16d0fc:	03e00008 */ 	jr	$ra
/*  f16d100:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f16d104:
/*  f16d104:	03e00008 */ 	jr	$ra
/*  f16d108:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f16d10c:	24630010 */ 	addiu	$v1,$v1,0x10
.L0f16d110:
/*  f16d110:	5467ffec */ 	bnel	$v1,$a3,.L0f16d0c4
/*  f16d114:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f16d118:	00001025 */ 	or	$v0,$zero,$zero
/*  f16d11c:	03e00008 */ 	jr	$ra
/*  f16d120:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d124
/*  f16d124:	3c03800b */ 	lui	$v1,%hi(var800aaa38)
/*  f16d128:	3c02800b */ 	lui	$v0,%hi(var800aaa68)
/*  f16d12c:	2442aa68 */ 	addiu	$v0,$v0,%lo(var800aaa68)
/*  f16d130:	2463aa38 */ 	addiu	$v1,$v1,%lo(var800aaa38)
/*  f16d134:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f16d138:
/*  f16d138:	548e000c */ 	bnel	$a0,$t6,.L0f16d16c
/*  f16d13c:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f16d140:	8c6f0008 */ 	lw	$t7,0x8($v1)
/*  f16d144:	51e00004 */ 	beqzl	$t7,.L0f16d158
/*  f16d148:	8c780004 */ 	lw	$t8,0x4($v1)
/*  f16d14c:	03e00008 */ 	jr	$ra
/*  f16d150:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f16d154:	8c780004 */ 	lw	$t8,0x4($v1)
.L0f16d158:
/*  f16d158:	53000004 */ 	beqzl	$t8,.L0f16d16c
/*  f16d15c:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f16d160:	03e00008 */ 	jr	$ra
/*  f16d164:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f16d168:	24630010 */ 	addiu	$v1,$v1,0x10
.L0f16d16c:
/*  f16d16c:	5462fff2 */ 	bnel	$v1,$v0,.L0f16d138
/*  f16d170:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f16d174:	00001025 */ 	or	$v0,$zero,$zero
/*  f16d178:	03e00008 */ 	jr	$ra
/*  f16d17c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d180:	3c02800b */ 	lui	$v0,%hi(var800aaa38)
/*  f16d184:	2442aa38 */ 	addiu	$v0,$v0,%lo(var800aaa38)
/*  f16d188:	00001825 */ 	or	$v1,$zero,$zero
/*  f16d18c:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f16d190:
/*  f16d190:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f16d194:	548e0004 */ 	bnel	$a0,$t6,.L0f16d1a8
/*  f16d198:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f16d19c:	03e00008 */ 	jr	$ra
/*  f16d1a0:	00601025 */ 	or	$v0,$v1,$zero
/*  f16d1a4:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f16d1a8:
/*  f16d1a8:	1465fff9 */ 	bne	$v1,$a1,.L0f16d190
/*  f16d1ac:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f16d1b0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f16d1b4:	03e00008 */ 	jr	$ra
/*  f16d1b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d1bc
/*  f16d1bc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f16d1c0:	8defdda0 */ 	lw	$t7,-0x2260($t7)
/*  f16d1c4:	44866000 */ 	mtc1	$a2,$f12
/*  f16d1c8:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f16d1cc:	15e0001a */ 	bnez	$t7,.L0f16d238
/*  f16d1d0:	30eeffff */ 	andi	$t6,$a3,0xffff
/*  f16d1d4:	3c088008 */ 	lui	$t0,%hi(var800840c4)
/*  f16d1d8:	250840c4 */ 	addiu	$t0,$t0,%lo(var800840c4)
/*  f16d1dc:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f16d1e0:	3c19800b */ 	lui	$t9,%hi(var800aa5d8)
/*  f16d1e4:	2739a5d8 */ 	addiu	$t9,$t9,%lo(var800aa5d8)
/*  f16d1e8:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f16d1ec:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f16d1f0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f16d1f4:	03191821 */ 	addu	$v1,$t8,$t9
/*  f16d1f8:	3c098008 */ 	lui	$t1,%hi(var800840d4)
/*  f16d1fc:	252940d4 */ 	addiu	$t1,$t1,%lo(var800840d4)
/*  f16d200:	8d260000 */ 	lw	$a2,0x0($t1)
/*  f16d204:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f16d208:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f16d20c:	24cb0001 */ 	addiu	$t3,$a2,0x1
/*  f16d210:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f16d214:	ac650004 */ 	sw	$a1,0x4($v1)
/*  f16d218:	e46c000c */ 	swc1	$f12,0xc($v1)
/*  f16d21c:	a46e0010 */ 	sh	$t6,0x10($v1)
/*  f16d220:	a46a0012 */ 	sh	$t2,0x12($v1)
/*  f16d224:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f16d228:	a4600018 */ 	sh	$zero,0x18($v1)
/*  f16d22c:	a4600016 */ 	sh	$zero,0x16($v1)
/*  f16d230:	ad0c0000 */ 	sw	$t4,0x0($t0)
/*  f16d234:	a4660014 */ 	sh	$a2,0x14($v1)
.L0f16d238:
/*  f16d238:	03e00008 */ 	jr	$ra
/*  f16d23c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d240
/*  f16d240:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16d244:	8dcedda0 */ 	lw	$t6,-0x2260($t6)
/*  f16d248:	3c068008 */ 	lui	$a2,%hi(var800840c4)
/*  f16d24c:	24c640c4 */ 	addiu	$a2,$a2,%lo(var800840c4)
/*  f16d250:	15c00014 */ 	bnez	$t6,.L0f16d2a4
/*  f16d254:	3c078008 */ 	lui	$a3,%hi(var800840d4)
/*  f16d258:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f16d25c:	3c18800b */ 	lui	$t8,%hi(var800aa5d8)
/*  f16d260:	2718a5d8 */ 	addiu	$t8,$t8,%lo(var800aa5d8)
/*  f16d264:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f16d268:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f16d26c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f16d270:	24e740d4 */ 	addiu	$a3,$a3,%lo(var800840d4)
/*  f16d274:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f16d278:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f16d27c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f16d280:	24490001 */ 	addiu	$t1,$v0,0x1
/*  f16d284:	24a80001 */ 	addiu	$t0,$a1,0x1
/*  f16d288:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f16d28c:	a4790012 */ 	sh	$t9,0x12($v1)
/*  f16d290:	ace80000 */ 	sw	$t0,0x0($a3)
/*  f16d294:	a4600018 */ 	sh	$zero,0x18($v1)
/*  f16d298:	a4600016 */ 	sh	$zero,0x16($v1)
/*  f16d29c:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16d2a0:	a4650014 */ 	sh	$a1,0x14($v1)
.L0f16d2a4:
/*  f16d2a4:	03e00008 */ 	jr	$ra
/*  f16d2a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d2ac
/*  f16d2ac:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16d2b0:	8dcedda0 */ 	lw	$t6,-0x2260($t6)
/*  f16d2b4:	44856000 */ 	mtc1	$a1,$f12
/*  f16d2b8:	3c078008 */ 	lui	$a3,%hi(var800840c4)
/*  f16d2bc:	15c00017 */ 	bnez	$t6,.L0f16d31c
/*  f16d2c0:	24e740c4 */ 	addiu	$a3,$a3,%lo(var800840c4)
/*  f16d2c4:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f16d2c8:	3c18800b */ 	lui	$t8,%hi(var800aa5d8)
/*  f16d2cc:	2718a5d8 */ 	addiu	$t8,$t8,%lo(var800aa5d8)
/*  f16d2d0:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f16d2d4:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f16d2d8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f16d2dc:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f16d2e0:	3c088008 */ 	lui	$t0,%hi(var800840d4)
/*  f16d2e4:	250840d4 */ 	addiu	$t0,$t0,%lo(var800840d4)
/*  f16d2e8:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f16d2ec:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f16d2f0:	244a0001 */ 	addiu	$t2,$v0,0x1
/*  f16d2f4:	24a90001 */ 	addiu	$t1,$a1,0x1
/*  f16d2f8:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f16d2fc:	e46c000c */ 	swc1	$f12,0xc($v1)
/*  f16d300:	ac660008 */ 	sw	$a2,0x8($v1)
/*  f16d304:	a4790012 */ 	sh	$t9,0x12($v1)
/*  f16d308:	ad090000 */ 	sw	$t1,0x0($t0)
/*  f16d30c:	a4600018 */ 	sh	$zero,0x18($v1)
/*  f16d310:	a4600016 */ 	sh	$zero,0x16($v1)
/*  f16d314:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f16d318:	a4650014 */ 	sh	$a1,0x14($v1)
.L0f16d31c:
/*  f16d31c:	03e00008 */ 	jr	$ra
/*  f16d320:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d324
/*  f16d324:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16d328:	8dcedda0 */ 	lw	$t6,-0x2260($t6)
/*  f16d32c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16d330:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d334:	15c00022 */ 	bnez	$t6,.L0f16d3c0
/*  f16d338:	3c03800b */ 	lui	$v1,%hi(var800aaa68)
/*  f16d33c:	3c04800b */ 	lui	$a0,%hi(var800aaa78)
/*  f16d340:	3c02800b */ 	lui	$v0,%hi(var800aaa88)
/*  f16d344:	3c05800b */ 	lui	$a1,%hi(var800aaa98)
/*  f16d348:	24a5aa98 */ 	addiu	$a1,$a1,%lo(var800aaa98)
/*  f16d34c:	2442aa88 */ 	addiu	$v0,$v0,%lo(var800aaa88)
/*  f16d350:	2484aa78 */ 	addiu	$a0,$a0,%lo(var800aaa78)
/*  f16d354:	2463aa68 */ 	addiu	$v1,$v1,%lo(var800aaa68)
.L0f16d358:
/*  f16d358:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f16d35c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f16d360:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f16d364:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f16d368:	ac80fffc */ 	sw	$zero,-0x4($a0)
/*  f16d36c:	1445fffa */ 	bne	$v0,$a1,.L0f16d358
/*  f16d370:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f16d374:	0fc5b50c */ 	jal	func0f16d430
/*  f16d378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d37c:	0fc5b4f4 */ 	jal	func0f16d3d0
/*  f16d380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d384:	0fc5b513 */ 	jal	func0f16d44c
/*  f16d388:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d38c:	3c018008 */ 	lui	$at,0x8008
/*  f16d390:	ac2040e8 */ 	sw	$zero,0x40e8($at)
/*  f16d394:	3c018008 */ 	lui	$at,0x8008
/*  f16d398:	ac2040f0 */ 	sw	$zero,0x40f0($at)
/*  f16d39c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f16d3a0:	3c018008 */ 	lui	$at,0x8008
/*  f16d3a4:	ac2240c0 */ 	sw	$v0,0x40c0($at)
/*  f16d3a8:	3c018008 */ 	lui	$at,0x8008
/*  f16d3ac:	ac2240c8 */ 	sw	$v0,0x40c8($at)
/*  f16d3b0:	3c018008 */ 	lui	$at,0x8008
/*  f16d3b4:	ac2240cc */ 	sw	$v0,0x40cc($at)
/*  f16d3b8:	3c018008 */ 	lui	$at,0x8008
/*  f16d3bc:	ac2040d8 */ 	sw	$zero,0x40d8($at)
.L0f16d3c0:
/*  f16d3c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d3c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16d3c8:	03e00008 */ 	jr	$ra
/*  f16d3cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d3d0
/*  f16d3d0:	3c02800b */ 	lui	$v0,%hi(var800aa5d8)
/*  f16d3d4:	3c048008 */ 	lui	$a0,%hi(var800840d4)
/*  f16d3d8:	248440d4 */ 	addiu	$a0,$a0,%lo(var800840d4)
/*  f16d3dc:	2442a5d8 */ 	addiu	$v0,$v0,%lo(var800aa5d8)
/*  f16d3e0:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f16d3e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16d3e8:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f16d3ec:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f16d3f0:	24780001 */ 	addiu	$t8,$v1,0x1
/*  f16d3f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d3f8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16d3fc:	a44f0012 */ 	sh	$t7,0x12($v0)
/*  f16d400:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f16d404:	a4400018 */ 	sh	$zero,0x18($v0)
/*  f16d408:	a4400016 */ 	sh	$zero,0x16($v0)
/*  f16d40c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f16d410:	3c018008 */ 	lui	$at,0x8008
/*  f16d414:	a4430014 */ 	sh	$v1,0x14($v0)
/*  f16d418:	0c004643 */ 	jal	func0001190c
/*  f16d41c:	ac3940c4 */ 	sw	$t9,0x40c4($at)
/*  f16d420:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d424:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16d428:	03e00008 */ 	jr	$ra
/*  f16d42c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d430
/*  f16d430:	3c028008 */ 	lui	$v0,%hi(var800840e0)
/*  f16d434:	244240e0 */ 	addiu	$v0,$v0,%lo(var800840e0)
/*  f16d438:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f16d43c:	3c018008 */ 	lui	$at,0x8008
/*  f16d440:	ac2e40d0 */ 	sw	$t6,0x40d0($at)
/*  f16d444:	03e00008 */ 	jr	$ra
/*  f16d448:	ac400000 */ 	sw	$zero,0x0($v0)
);

GLOBAL_ASM(
glabel func0f16d44c
/*  f16d44c:	3c068008 */ 	lui	$a2,%hi(var800840c4)
/*  f16d450:	24c640c4 */ 	addiu	$a2,$a2,%lo(var800840c4)
/*  f16d454:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f16d458:	3c078008 */ 	lui	$a3,%hi(var800840d4)
/*  f16d45c:	24e740d4 */ 	addiu	$a3,$a3,%lo(var800840d4)
/*  f16d460:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f16d464:	3c05800b */ 	lui	$a1,%hi(var800aa5d8)
/*  f16d468:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f16d46c:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f16d470:	24a5a5d8 */ 	addiu	$a1,$a1,%lo(var800aa5d8)
/*  f16d474:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16d478:	00ae1821 */ 	addu	$v1,$a1,$t6
/*  f16d47c:	240f0006 */ 	addiu	$t7,$zero,0x6
/*  f16d480:	24180005 */ 	addiu	$t8,$zero,0x5
/*  f16d484:	24990001 */ 	addiu	$t9,$a0,0x1
/*  f16d488:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f16d48c:	a4780012 */ 	sh	$t8,0x12($v1)
/*  f16d490:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f16d494:	3c088008 */ 	lui	$t0,0x8008
/*  f16d498:	a4640014 */ 	sh	$a0,0x14($v1)
/*  f16d49c:	8d0840d0 */ 	lw	$t0,0x40d0($t0)
/*  f16d4a0:	24490001 */ 	addiu	$t1,$v0,0x1
/*  f16d4a4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16d4a8:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f16d4ac:	a4a00018 */ 	sh	$zero,0x18($a1)
/*  f16d4b0:	03e00008 */ 	jr	$ra
/*  f16d4b4:	a4a00016 */ 	sh	$zero,0x16($a1)
);

GLOBAL_ASM(
glabel func0f16d4b8
/*  f16d4b8:	3c028008 */ 	lui	$v0,0x8008
/*  f16d4bc:	8c4240c8 */ 	lw	$v0,0x40c8($v0)
/*  f16d4c0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16d4c4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16d4c8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d4cc:	10410003 */ 	beq	$v0,$at,.L0f16d4dc
/*  f16d4d0:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f16d4d4:	10000005 */ 	beqz	$zero,.L0f16d4ec
/*  f16d4d8:	00402825 */ 	or	$a1,$v0,$zero
.L0f16d4dc:
/*  f16d4dc:	3c04800b */ 	lui	$a0,0x800b
/*  f16d4e0:	0fc5db10 */ 	jal	func0f176c40
/*  f16d4e4:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d4e8:	00402825 */ 	or	$a1,$v0,$zero
.L0f16d4ec:
/*  f16d4ec:	04a00012 */ 	bltz	$a1,.L0f16d538
/*  f16d4f0:	3c028008 */ 	lui	$v0,0x8008
/*  f16d4f4:	8c4240c8 */ 	lw	$v0,0x40c8($v0)
/*  f16d4f8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16d4fc:	3c04800b */ 	lui	$a0,0x800b
/*  f16d500:	10410003 */ 	beq	$v0,$at,.L0f16d510
/*  f16d504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d508:	10000004 */ 	beqz	$zero,.L0f16d51c
/*  f16d50c:	00402825 */ 	or	$a1,$v0,$zero
.L0f16d510:
/*  f16d510:	0fc5db10 */ 	jal	func0f176c40
/*  f16d514:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d518:	00402825 */ 	or	$a1,$v0,$zero
.L0f16d51c:
/*  f16d51c:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16d520:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f16d524:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f16d528:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16d52c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f16d530:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16d534:	3047ffff */ 	andi	$a3,$v0,0xffff
.L0f16d538:
/*  f16d538:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d53c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16d540:	03e00008 */ 	jr	$ra
/*  f16d544:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d548
/*  f16d548:	3c028008 */ 	lui	$v0,0x8008
/*  f16d54c:	8c4240cc */ 	lw	$v0,0x40cc($v0)
/*  f16d550:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16d554:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16d558:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d55c:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f16d560:	10410003 */ 	beq	$v0,$at,.L0f16d570
/*  f16d564:	00002825 */ 	or	$a1,$zero,$zero
/*  f16d568:	10000007 */ 	beqz	$zero,.L0f16d588
/*  f16d56c:	00401825 */ 	or	$v1,$v0,$zero
.L0f16d570:
/*  f16d570:	3c04800b */ 	lui	$a0,0x800b
/*  f16d574:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d578:	0fc5db36 */ 	jal	func0f176cd8
/*  f16d57c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f16d580:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f16d584:	00401825 */ 	or	$v1,$v0,$zero
.L0f16d588:
/*  f16d588:	0460002c */ 	bltz	$v1,.L0f16d63c
/*  f16d58c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16d590:	8dce40cc */ 	lw	$t6,0x40cc($t6)
/*  f16d594:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16d598:	11c10003 */ 	beq	$t6,$at,.L0f16d5a8
/*  f16d59c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d5a0:	10000026 */ 	beqz	$zero,.L0f16d63c
/*  f16d5a4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f16d5a8:
/*  f16d5a8:	0fc5b5b0 */ 	jal	func0f16d6c0
/*  f16d5ac:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f16d5b0:	10400022 */ 	beqz	$v0,.L0f16d63c
/*  f16d5b4:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f16d5b8:	3c0f800a */ 	lui	$t7,0x800a
/*  f16d5bc:	8defa26c */ 	lw	$t7,-0x5d94($t7)
/*  f16d5c0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16d5c4:	3c028008 */ 	lui	$v0,0x8008
/*  f16d5c8:	51e1001c */ 	beql	$t7,$at,.L0f16d63c
/*  f16d5cc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f16d5d0:	8c4240cc */ 	lw	$v0,0x40cc($v0)
/*  f16d5d4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16d5d8:	3c04800b */ 	lui	$a0,0x800b
/*  f16d5dc:	10410003 */ 	beq	$v0,$at,.L0f16d5ec
/*  f16d5e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d5e4:	10000004 */ 	beqz	$zero,.L0f16d5f8
/*  f16d5e8:	00401825 */ 	or	$v1,$v0,$zero
.L0f16d5ec:
/*  f16d5ec:	0fc5db36 */ 	jal	func0f176cd8
/*  f16d5f0:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d5f4:	00401825 */ 	or	$v1,$v0,$zero
.L0f16d5f8:
/*  f16d5f8:	3c04800b */ 	lui	$a0,0x800b
/*  f16d5fc:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d600:	0fc5db36 */ 	jal	func0f176cd8
/*  f16d604:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f16d608:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f16d60c:	5043000b */ 	beql	$v0,$v1,.L0f16d63c
/*  f16d610:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f16d614:	0fc5b490 */ 	jal	func0f16d240
/*  f16d618:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16d61c:	3c04800b */ 	lui	$a0,0x800b
/*  f16d620:	0fc5db36 */ 	jal	func0f176cd8
/*  f16d624:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d628:	0fc5b7f4 */ 	jal	audioSetAuxTrack
/*  f16d62c:	00402025 */ 	or	$a0,$v0,$zero
/*  f16d630:	10000020 */ 	beqz	$zero,.L0f16d6b4
/*  f16d634:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d638:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f16d63c:
/*  f16d63c:	50a0001d */ 	beqzl	$a1,.L0f16d6b4
/*  f16d640:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d644:	0fc5b449 */ 	jal	func0f16d124
/*  f16d648:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16d64c:	10400002 */ 	beqz	$v0,.L0f16d658
/*  f16d650:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16d654:	14410016 */ 	bne	$v0,$at,.L0f16d6b0
.L0f16d658:
/*  f16d658:	3c028008 */ 	lui	$v0,0x8008
/*  f16d65c:	8c4240cc */ 	lw	$v0,0x40cc($v0)
/*  f16d660:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16d664:	3c04800b */ 	lui	$a0,0x800b
/*  f16d668:	10410003 */ 	beq	$v0,$at,.L0f16d678
/*  f16d66c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d670:	10000004 */ 	beqz	$zero,.L0f16d684
/*  f16d674:	00402825 */ 	or	$a1,$v0,$zero
.L0f16d678:
/*  f16d678:	0fc5db36 */ 	jal	func0f176cd8
/*  f16d67c:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d680:	00402825 */ 	or	$a1,$v0,$zero
.L0f16d684:
/*  f16d684:	3c028006 */ 	lui	$v0,0x8006
/*  f16d688:	9442ddc8 */ 	lhu	$v0,-0x2238($v0)
/*  f16d68c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16d690:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f16d694:	28415001 */ 	slti	$at,$v0,0x5001
/*  f16d698:	14200003 */ 	bnez	$at,.L0f16d6a8
/*  f16d69c:	00401825 */ 	or	$v1,$v0,$zero
/*  f16d6a0:	10000001 */ 	beqz	$zero,.L0f16d6a8
/*  f16d6a4:	24035000 */ 	addiu	$v1,$zero,0x5000
.L0f16d6a8:
/*  f16d6a8:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16d6ac:	3067ffff */ 	andi	$a3,$v1,0xffff
.L0f16d6b0:
/*  f16d6b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16d6b4:
/*  f16d6b4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16d6b8:	03e00008 */ 	jr	$ra
/*  f16d6bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d6c0
/*  f16d6c0:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f16d6c4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f16d6c8:	8cae02ac */ 	lw	$t6,0x2ac($a1)
/*  f16d6cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16d6d0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16d6d4:	15c10003 */ 	bne	$t6,$at,.L0f16d6e4
/*  f16d6d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d6dc:	1000006b */ 	beqz	$zero,.L0f16d88c
/*  f16d6e0:	00001025 */ 	or	$v0,$zero,$zero
.L0f16d6e4:
/*  f16d6e4:	0fc5b364 */ 	jal	getVar80084014
/*  f16d6e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d6ec:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f16d6f0:	10400003 */ 	beqz	$v0,.L0f16d700
/*  f16d6f4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f16d6f8:	10000064 */ 	beqz	$zero,.L0f16d88c
/*  f16d6fc:	00001025 */ 	or	$v0,$zero,$zero
.L0f16d700:
/*  f16d700:	3c0f8008 */ 	lui	$t7,0x8008
/*  f16d704:	8def40e8 */ 	lw	$t7,0x40e8($t7)
/*  f16d708:	3c188008 */ 	lui	$t8,0x8008
/*  f16d70c:	11e00003 */ 	beqz	$t7,.L0f16d71c
/*  f16d710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d714:	1000005d */ 	beqz	$zero,.L0f16d88c
/*  f16d718:	00001025 */ 	or	$v0,$zero,$zero
.L0f16d71c:
/*  f16d71c:	8f1840d8 */ 	lw	$t8,0x40d8($t8)
/*  f16d720:	3c198008 */ 	lui	$t9,0x8008
/*  f16d724:	53000007 */ 	beqzl	$t8,.L0f16d744
/*  f16d728:	8cbf006c */ 	lw	$ra,0x6c($a1)
/*  f16d72c:	8f3940dc */ 	lw	$t9,0x40dc($t9)
/*  f16d730:	53200004 */ 	beqzl	$t9,.L0f16d744
/*  f16d734:	8cbf006c */ 	lw	$ra,0x6c($a1)
/*  f16d738:	10000054 */ 	beqz	$zero,.L0f16d88c
/*  f16d73c:	00001025 */ 	or	$v0,$zero,$zero
/*  f16d740:	8cbf006c */ 	lw	$ra,0x6c($a1)
.L0f16d744:
/*  f16d744:	00003825 */ 	or	$a3,$zero,$zero
/*  f16d748:	00003025 */ 	or	$a2,$zero,$zero
/*  f16d74c:	13e00003 */ 	beqz	$ra,.L0f16d75c
/*  f16d750:	00002025 */ 	or	$a0,$zero,$zero
/*  f16d754:	10000001 */ 	beqz	$zero,.L0f16d75c
/*  f16d758:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f16d75c:
/*  f16d75c:	8cad0068 */ 	lw	$t5,0x68($a1)
/*  f16d760:	00001825 */ 	or	$v1,$zero,$zero
/*  f16d764:	00001025 */ 	or	$v0,$zero,$zero
/*  f16d768:	11a00003 */ 	beqz	$t5,.L0f16d778
/*  f16d76c:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f16d770:	10000001 */ 	beqz	$zero,.L0f16d778
/*  f16d774:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f16d778:
/*  f16d778:	8cac0064 */ 	lw	$t4,0x64($a1)
/*  f16d77c:	3c0a800a */ 	lui	$t2,%hi(g_RoomPtrs)
/*  f16d780:	254a4928 */ 	addiu	$t2,$t2,%lo(g_RoomPtrs)
/*  f16d784:	11800003 */ 	beqz	$t4,.L0f16d794
/*  f16d788:	240b008c */ 	addiu	$t3,$zero,0x8c
/*  f16d78c:	10000001 */ 	beqz	$zero,.L0f16d794
/*  f16d790:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f16d794:
/*  f16d794:	8ca80070 */ 	lw	$t0,0x70($a1)
/*  f16d798:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f16d79c:	11000003 */ 	beqz	$t0,.L0f16d7ac
/*  f16d7a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d7a4:	10000001 */ 	beqz	$zero,.L0f16d7ac
/*  f16d7a8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16d7ac:
/*  f16d7ac:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16d7b0:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16d7b4:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f16d7b8:	1b000033 */ 	blez	$t8,.L0f16d888
/*  f16d7bc:	3c0e800a */ 	lui	$t6,%hi(g_Vars)
/*  f16d7c0:	25ce9fc0 */ 	addiu	$t6,$t6,%lo(g_Vars)
/*  f16d7c4:	032e2821 */ 	addu	$a1,$t9,$t6
/*  f16d7c8:	8caf0064 */ 	lw	$t7,0x64($a1)
.L0f16d7cc:
/*  f16d7cc:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f16d7d0:	8de200bc */ 	lw	$v0,0xbc($t7)
/*  f16d7d4:	10400015 */ 	beqz	$v0,.L0f16d82c
/*  f16d7d8:	24580028 */ 	addiu	$t8,$v0,0x28
/*  f16d7dc:	13000013 */ 	beqz	$t8,.L0f16d82c
/*  f16d7e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d7e4:	84430028 */ 	lh	$v1,0x28($v0)
/*  f16d7e8:	11230010 */ 	beq	$t1,$v1,.L0f16d82c
/*  f16d7ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d7f0:	006b0019 */ 	multu	$v1,$t3
/*  f16d7f4:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f16d7f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f16d7fc:	00007012 */ 	mflo	$t6
/*  f16d800:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f16d804:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f16d808:	33194000 */ 	andi	$t9,$t8,0x4000
/*  f16d80c:	13200003 */ 	beqz	$t9,.L0f16d81c
/*  f16d810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d814:	10000001 */ 	beqz	$zero,.L0f16d81c
/*  f16d818:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16d81c:
/*  f16d81c:	10400003 */ 	beqz	$v0,.L0f16d82c
/*  f16d820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d824:	10000019 */ 	beqz	$zero,.L0f16d88c
/*  f16d828:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16d82c:
/*  f16d82c:	13e00003 */ 	beqz	$ra,.L0f16d83c
/*  f16d830:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f16d834:	10000002 */ 	beqz	$zero,.L0f16d840
/*  f16d838:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f16d83c:
/*  f16d83c:	00003025 */ 	or	$a2,$zero,$zero
.L0f16d840:
/*  f16d840:	11a00003 */ 	beqz	$t5,.L0f16d850
/*  f16d844:	00002025 */ 	or	$a0,$zero,$zero
/*  f16d848:	10000001 */ 	beqz	$zero,.L0f16d850
/*  f16d84c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f16d850:
/*  f16d850:	11800003 */ 	beqz	$t4,.L0f16d860
/*  f16d854:	00001825 */ 	or	$v1,$zero,$zero
/*  f16d858:	10000001 */ 	beqz	$zero,.L0f16d860
/*  f16d85c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f16d860:
/*  f16d860:	11000003 */ 	beqz	$t0,.L0f16d870
/*  f16d864:	00001025 */ 	or	$v0,$zero,$zero
/*  f16d868:	10000001 */ 	beqz	$zero,.L0f16d870
/*  f16d86c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16d870:
/*  f16d870:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16d874:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16d878:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f16d87c:	00f8082a */ 	slt	$at,$a3,$t8
/*  f16d880:	5420ffd2 */ 	bnezl	$at,.L0f16d7cc
/*  f16d884:	8caf0064 */ 	lw	$t7,0x64($a1)
.L0f16d888:
/*  f16d888:	00001025 */ 	or	$v0,$zero,$zero
.L0f16d88c:
/*  f16d88c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d890:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16d894:	03e00008 */ 	jr	$ra
/*  f16d898:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d89c
/*  f16d89c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16d8a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d8a4:	3c04800b */ 	lui	$a0,0x800b
/*  f16d8a8:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f16d8ac:	0fc5db48 */ 	jal	func0f176d20
/*  f16d8b0:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d8b4:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16d8b8:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f16d8bc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16d8c0:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f16d8c4:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f16d8c8:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16d8cc:	3047ffff */ 	andi	$a3,$v0,0xffff
/*  f16d8d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d8d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16d8d8:	03e00008 */ 	jr	$ra
/*  f16d8dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d8e0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16d8e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d8e8:	0fc3f27d */ 	jal	func0f0fc9f4
/*  f16d8ec:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f16d8f0:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16d8f4:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f16d8f8:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16d8fc:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f16d900:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f16d904:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16d908:	3047ffff */ 	andi	$a3,$v0,0xffff
/*  f16d90c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d910:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16d914:	03e00008 */ 	jr	$ra
/*  f16d918:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d91c
/*  f16d91c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f16d920:	8def40c0 */ 	lw	$t7,0x40c0($t7)
/*  f16d924:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16d928:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d92c:	108f0018 */ 	beq	$a0,$t7,.L0f16d990
/*  f16d930:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f16d934:	0fc5b490 */ 	jal	func0f16d240
/*  f16d938:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16d93c:	0fc5b490 */ 	jal	func0f16d240
/*  f16d940:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16d944:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16d948:	3c053f00 */ 	lui	$a1,0x3f00
/*  f16d94c:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16d950:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16d954:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16d958:	3c053f00 */ 	lui	$a1,0x3f00
/*  f16d95c:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16d960:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16d964:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16d968:	3c053f00 */ 	lui	$a1,0x3f00
/*  f16d96c:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16d970:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16d974:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16d978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d97c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16d980:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f16d984:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f16d988:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16d98c:	3047ffff */ 	andi	$a3,$v0,0xffff
.L0f16d990:
/*  f16d990:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d994:	8fb80018 */ 	lw	$t8,0x18($sp)
/*  f16d998:	3c018008 */ 	lui	$at,0x8008
/*  f16d99c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16d9a0:	03e00008 */ 	jr	$ra
/*  f16d9a4:	ac3840c0 */ 	sw	$t8,0x40c0($at)
);

GLOBAL_ASM(
glabel func0f16d9a8
/*  f16d9a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16d9ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16d9b0:	3c01800b */ 	lui	$at,0x800b
/*  f16d9b4:	44806000 */ 	mtc1	$zero,$f12
/*  f16d9b8:	0fc5b52e */ 	jal	func0f16d4b8
/*  f16d9bc:	ac24a5d0 */ 	sw	$a0,-0x5a30($at)
/*  f16d9c0:	3c04800b */ 	lui	$a0,0x800b
/*  f16d9c4:	0fc5db36 */ 	jal	func0f176cd8
/*  f16d9c8:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16d9cc:	04420005 */ 	bltzl	$v0,.L0f16d9e4
/*  f16d9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16d9d4:	44806000 */ 	mtc1	$zero,$f12
/*  f16d9d8:	0fc5b552 */ 	jal	func0f16d548
/*  f16d9dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16d9e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16d9e4:
/*  f16d9e4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16d9e8:	03e00008 */ 	jr	$ra
/*  f16d9ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16d9f0
/*  f16d9f0:	3c01800b */ 	lui	$at,0x800b
/*  f16d9f4:	03e00008 */ 	jr	$ra
/*  f16d9f8:	ac24a5d0 */ 	sw	$a0,-0x5a30($at)
);

GLOBAL_ASM(
glabel func0f16d9fc
/*  f16d9fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16da00:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16da04:	0fc5b50c */ 	jal	func0f16d430
/*  f16da08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16da0c:	0fc5b4f4 */ 	jal	func0f16d3d0
/*  f16da10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16da14:	0fc5b513 */ 	jal	func0f16d44c
/*  f16da18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16da1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16da20:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16da24:	03e00008 */ 	jr	$ra
/*  f16da28:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16da2c
/*  f16da2c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16da30:	8dce40d8 */ 	lw	$t6,0x40d8($t6)
/*  f16da34:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16da38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16da3c:	15c00015 */ 	bnez	$t6,.L0f16da94
/*  f16da40:	3c04800b */ 	lui	$a0,0x800b
/*  f16da44:	0fc5db48 */ 	jal	func0f176d20
/*  f16da48:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16da4c:	04420012 */ 	bltzl	$v0,.L0f16da98
/*  f16da50:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16da54:	0fc5b490 */ 	jal	func0f16d240
/*  f16da58:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16da5c:	0fc5b490 */ 	jal	func0f16d240
/*  f16da60:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16da64:	0fc5b490 */ 	jal	func0f16d240
/*  f16da68:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16da6c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16da70:	3c053f00 */ 	lui	$a1,0x3f00
/*  f16da74:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16da78:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16da7c:	44806000 */ 	mtc1	$zero,$f12
/*  f16da80:	0fc5b627 */ 	jal	func0f16d89c
/*  f16da84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16da88:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f16da8c:	3c018008 */ 	lui	$at,0x8008
/*  f16da90:	ac2f40d8 */ 	sw	$t7,0x40d8($at)
.L0f16da94:
/*  f16da94:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16da98:
/*  f16da98:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16da9c:	03e00008 */ 	jr	$ra
/*  f16daa0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16daa4
/*  f16daa4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16daa8:	8dce40d8 */ 	lw	$t6,0x40d8($t6)
/*  f16daac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16dab0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16dab4:	51c00014 */ 	beqzl	$t6,.L0f16db08
/*  f16dab8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16dabc:	0fc5b490 */ 	jal	func0f16d240
/*  f16dac0:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16dac4:	0fc5b490 */ 	jal	func0f16d240
/*  f16dac8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16dacc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16dad0:	3c053f80 */ 	lui	$a1,0x3f80
/*  f16dad4:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16dad8:	00003025 */ 	or	$a2,$zero,$zero
/*  f16dadc:	3c0f800a */ 	lui	$t7,0x800a
/*  f16dae0:	8defa488 */ 	lw	$t7,-0x5b78($t7)
/*  f16dae4:	3c013f00 */ 	lui	$at,0x3f00
/*  f16dae8:	15e00004 */ 	bnez	$t7,.L0f16dafc
/*  f16daec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16daf0:	44816000 */ 	mtc1	$at,$f12
/*  f16daf4:	0fc5b52e */ 	jal	func0f16d4b8
/*  f16daf8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f16dafc:
/*  f16dafc:	3c018008 */ 	lui	$at,0x8008
/*  f16db00:	ac2040d8 */ 	sw	$zero,0x40d8($at)
/*  f16db04:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16db08:
/*  f16db08:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16db0c:	03e00008 */ 	jr	$ra
/*  f16db10:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16db14
/*  f16db14:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16db18:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16db1c:	0fc3f27d */ 	jal	func0f0fc9f4
/*  f16db20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16db24:	0fc5b647 */ 	jal	func0f16d91c
/*  f16db28:	00402025 */ 	or	$a0,$v0,$zero
/*  f16db2c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16db30:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16db34:	03e00008 */ 	jr	$ra
/*  f16db38:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16db3c
/*  f16db3c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16db40:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16db44:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16db48:	3c053f80 */ 	lui	$a1,0x3f80
/*  f16db4c:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16db50:	00003025 */ 	or	$a2,$zero,$zero
/*  f16db54:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16db58:	0fc5b42a */ 	jal	func0f16d0a8
/*  f16db5c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f16db60:	10400007 */ 	beqz	$v0,.L0f16db80
/*  f16db64:	3c013f80 */ 	lui	$at,0x3f80
/*  f16db68:	3c013f80 */ 	lui	$at,0x3f80
/*  f16db6c:	44816000 */ 	mtc1	$at,$f12
/*  f16db70:	0fc5b627 */ 	jal	func0f16d89c
/*  f16db74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16db78:	10000005 */ 	beqz	$zero,.L0f16db90
/*  f16db7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16db80:
/*  f16db80:	44816000 */ 	mtc1	$at,$f12
/*  f16db84:	0fc5b52e */ 	jal	func0f16d4b8
/*  f16db88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16db8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16db90:
/*  f16db90:	240effff */ 	addiu	$t6,$zero,-1
/*  f16db94:	3c018008 */ 	lui	$at,0x8008
/*  f16db98:	ac2e40c0 */ 	sw	$t6,0x40c0($at)
/*  f16db9c:	03e00008 */ 	jr	$ra
/*  f16dba0:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f16dba4
/*  f16dba4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16dba8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16dbac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f16dbb0:	3c018008 */ 	lui	$at,0x8008
/*  f16dbb4:	0fc5b50c */ 	jal	func0f16d430
/*  f16dbb8:	ac2e40e8 */ 	sw	$t6,0x40e8($at)
/*  f16dbbc:	0fc5b490 */ 	jal	func0f16d240
/*  f16dbc0:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16dbc4:	0fc5b490 */ 	jal	func0f16d240
/*  f16dbc8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16dbcc:	0fc5b82d */ 	jal	audioStopTrack
/*  f16dbd0:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f16dbd4:	0fc5b490 */ 	jal	func0f16d240
/*  f16dbd8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16dbdc:	0fc5b490 */ 	jal	func0f16d240
/*  f16dbe0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16dbe4:	0fc5b490 */ 	jal	func0f16d240
/*  f16dbe8:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16dbec:	3c028006 */ 	lui	$v0,0x8006
/*  f16dbf0:	9442ddc8 */ 	lhu	$v0,-0x2238($v0)
/*  f16dbf4:	28415001 */ 	slti	$at,$v0,0x5001
/*  f16dbf8:	14200003 */ 	bnez	$at,.L0f16dc08
/*  f16dbfc:	00401825 */ 	or	$v1,$v0,$zero
/*  f16dc00:	10000001 */ 	beqz	$zero,.L0f16dc08
/*  f16dc04:	24035000 */ 	addiu	$v1,$zero,0x5000
.L0f16dc08:
/*  f16dc08:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16dc0c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f16dc10:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f16dc14:	0043082a */ 	slt	$at,$v0,$v1
/*  f16dc18:	10200009 */ 	beqz	$at,.L0f16dc40
/*  f16dc1c:	3c028006 */ 	lui	$v0,0x8006
/*  f16dc20:	9442ddc8 */ 	lhu	$v0,-0x2238($v0)
/*  f16dc24:	28415001 */ 	slti	$at,$v0,0x5001
/*  f16dc28:	14200003 */ 	bnez	$at,.L0f16dc38
/*  f16dc2c:	00401825 */ 	or	$v1,$v0,$zero
/*  f16dc30:	10000006 */ 	beqz	$zero,.L0f16dc4c
/*  f16dc34:	24085000 */ 	addiu	$t0,$zero,0x5000
.L0f16dc38:
/*  f16dc38:	10000004 */ 	beqz	$zero,.L0f16dc4c
/*  f16dc3c:	00604025 */ 	or	$t0,$v1,$zero
.L0f16dc40:
/*  f16dc40:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16dc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dc48:	00404025 */ 	or	$t0,$v0,$zero
.L0f16dc4c:
/*  f16dc4c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16dc50:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f16dc54:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f16dc58:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16dc5c:	3107ffff */ 	andi	$a3,$t0,0xffff
/*  f16dc60:	0fc5b513 */ 	jal	func0f16d44c
/*  f16dc64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dc68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16dc6c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16dc70:	03e00008 */ 	jr	$ra
/*  f16dc74:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16dc78
/*  f16dc78:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f16dc7c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16dc80:	0fc5b50c */ 	jal	func0f16d430
/*  f16dc84:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f16dc88:	3c028006 */ 	lui	$v0,0x8006
/*  f16dc8c:	9442ddc8 */ 	lhu	$v0,-0x2238($v0)
/*  f16dc90:	28415001 */ 	slti	$at,$v0,0x5001
/*  f16dc94:	14200003 */ 	bnez	$at,.L0f16dca4
/*  f16dc98:	00401825 */ 	or	$v1,$v0,$zero
/*  f16dc9c:	10000001 */ 	beqz	$zero,.L0f16dca4
/*  f16dca0:	24035000 */ 	addiu	$v1,$zero,0x5000
.L0f16dca4:
/*  f16dca4:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16dca8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f16dcac:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f16dcb0:	0043082a */ 	slt	$at,$v0,$v1
/*  f16dcb4:	10200009 */ 	beqz	$at,.L0f16dcdc
/*  f16dcb8:	3c028006 */ 	lui	$v0,0x8006
/*  f16dcbc:	9442ddc8 */ 	lhu	$v0,-0x2238($v0)
/*  f16dcc0:	28415001 */ 	slti	$at,$v0,0x5001
/*  f16dcc4:	14200003 */ 	bnez	$at,.L0f16dcd4
/*  f16dcc8:	00401825 */ 	or	$v1,$v0,$zero
/*  f16dccc:	10000006 */ 	beqz	$zero,.L0f16dce8
/*  f16dcd0:	24085000 */ 	addiu	$t0,$zero,0x5000
.L0f16dcd4:
/*  f16dcd4:	10000004 */ 	beqz	$zero,.L0f16dce8
/*  f16dcd8:	00604025 */ 	or	$t0,$v1,$zero
.L0f16dcdc:
/*  f16dcdc:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16dce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dce4:	00404025 */ 	or	$t0,$v0,$zero
.L0f16dce8:
/*  f16dce8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16dcec:	24050019 */ 	addiu	$a1,$zero,0x19
/*  f16dcf0:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f16dcf4:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16dcf8:	3107ffff */ 	andi	$a3,$t0,0xffff
/*  f16dcfc:	0fc5b513 */ 	jal	func0f16d44c
/*  f16dd00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dd04:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16dd08:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f16dd0c:	03e00008 */ 	jr	$ra
/*  f16dd10:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16dd14
/*  f16dd14:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16dd18:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16dd1c:	0fc5b50c */ 	jal	func0f16d430
/*  f16dd20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dd24:	0fc5b490 */ 	jal	func0f16d240
/*  f16dd28:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16dd2c:	0fc5b490 */ 	jal	func0f16d240
/*  f16dd30:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16dd34:	0fc5b490 */ 	jal	func0f16d240
/*  f16dd38:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16dd3c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16dd40:	8dce40d8 */ 	lw	$t6,0x40d8($t6)
/*  f16dd44:	3c053dcc */ 	lui	$a1,0x3dcc
/*  f16dd48:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f16dd4c:	11c00008 */ 	beqz	$t6,.L0f16dd70
/*  f16dd50:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16dd54:	3c053dcc */ 	lui	$a1,0x3dcc
/*  f16dd58:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f16dd5c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16dd60:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16dd64:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16dd68:	10000004 */ 	beqz	$zero,.L0f16dd7c
/*  f16dd6c:	44806000 */ 	mtc1	$zero,$f12
.L0f16dd70:
/*  f16dd70:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16dd74:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16dd78:	44806000 */ 	mtc1	$zero,$f12
.L0f16dd7c:
/*  f16dd7c:	0fc5b71e */ 	jal	func0f16dc78
/*  f16dd80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dd84:	240f04b0 */ 	addiu	$t7,$zero,0x4b0
/*  f16dd88:	3c018008 */ 	lui	$at,0x8008
/*  f16dd8c:	ac2f40f0 */ 	sw	$t7,0x40f0($at)
/*  f16dd90:	3c018008 */ 	lui	$at,0x8008
/*  f16dd94:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f16dd98:	0fc5b513 */ 	jal	func0f16d44c
/*  f16dd9c:	ac3840dc */ 	sw	$t8,0x40dc($at)
/*  f16dda0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16dda4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16dda8:	03e00008 */ 	jr	$ra
/*  f16ddac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16ddb0
/*  f16ddb0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16ddb4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16ddb8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16ddbc:	3c054000 */ 	lui	$a1,0x4000
/*  f16ddc0:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16ddc4:	00003025 */ 	or	$a2,$zero,$zero
/*  f16ddc8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16ddcc:	8dce40d8 */ 	lw	$t6,0x40d8($t6)
/*  f16ddd0:	3c014000 */ 	lui	$at,0x4000
/*  f16ddd4:	44816000 */ 	mtc1	$at,$f12
/*  f16ddd8:	11c00005 */ 	beqz	$t6,.L0f16ddf0
/*  f16dddc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dde0:	0fc5b627 */ 	jal	func0f16d89c
/*  f16dde4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dde8:	10000004 */ 	beqz	$zero,.L0f16ddfc
/*  f16ddec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16ddf0:
/*  f16ddf0:	0fc5b52e */ 	jal	func0f16d4b8
/*  f16ddf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16ddf8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16ddfc:
/*  f16ddfc:	3c018008 */ 	lui	$at,0x8008
/*  f16de00:	ac2040dc */ 	sw	$zero,0x40dc($at)
/*  f16de04:	03e00008 */ 	jr	$ra
/*  f16de08:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel audioPlayTrack
/*  f16de0c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16de10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16de14:	0fc5b50c */ 	jal	func0f16d430
/*  f16de18:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f16de1c:	0fc5b490 */ 	jal	func0f16d240
/*  f16de20:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16de24:	0fc5b490 */ 	jal	func0f16d240
/*  f16de28:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16de2c:	0fc5b82d */ 	jal	audioStopTrack
/*  f16de30:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f16de34:	0fc5b490 */ 	jal	func0f16d240
/*  f16de38:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16de3c:	0fc5b490 */ 	jal	func0f16d240
/*  f16de40:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16de44:	0fc5b490 */ 	jal	func0f16d240
/*  f16de48:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16de4c:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16de50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16de54:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16de58:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f16de5c:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f16de60:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16de64:	3047ffff */ 	andi	$a3,$v0,0xffff
/*  f16de68:	0fc5b513 */ 	jal	func0f16d44c
/*  f16de6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16de70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16de74:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16de78:	03e00008 */ 	jr	$ra
/*  f16de7c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioRestartTrack
/*  f16de80:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16de84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16de88:	0fc5b490 */ 	jal	func0f16d240
/*  f16de8c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16de90:	0fc5b490 */ 	jal	func0f16d240
/*  f16de94:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16de98:	3c013f00 */ 	lui	$at,0x3f00
/*  f16de9c:	44816000 */ 	mtc1	$at,$f12
/*  f16dea0:	0fc5b52e */ 	jal	func0f16d4b8
/*  f16dea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dea8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16deac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16deb0:	03e00008 */ 	jr	$ra
/*  f16deb4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16deb8
/*  f16deb8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16debc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16dec0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f16dec4:	0fc5b490 */ 	jal	func0f16d240
/*  f16dec8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16decc:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f16ded0:	3c018008 */ 	lui	$at,0x8008
/*  f16ded4:	ac2e40c8 */ 	sw	$t6,0x40c8($at)
/*  f16ded8:	3c013f00 */ 	lui	$at,0x3f00
/*  f16dedc:	44816000 */ 	mtc1	$at,$f12
/*  f16dee0:	0fc5b52e */ 	jal	func0f16d4b8
/*  f16dee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16dee8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16deec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16def0:	03e00008 */ 	jr	$ra
/*  f16def4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioSetTrack
/*  f16def8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16defc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16df00:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f16df04:	0fc5b490 */ 	jal	func0f16d240
/*  f16df08:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16df0c:	0fc5b490 */ 	jal	func0f16d240
/*  f16df10:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f16df14:	0fc5b82d */ 	jal	audioStopTrack
/*  f16df18:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f16df1c:	0fc5b490 */ 	jal	func0f16d240
/*  f16df20:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f16df24:	0fc5b490 */ 	jal	func0f16d240
/*  f16df28:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16df2c:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16df30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16df34:	3c038006 */ 	lui	$v1,0x8006
/*  f16df38:	9463ddc8 */ 	lhu	$v1,-0x2238($v1)
/*  f16df3c:	0062082a */ 	slt	$at,$v1,$v0
/*  f16df40:	10200005 */ 	beqz	$at,.L0f16df58
/*  f16df44:	00604025 */ 	or	$t0,$v1,$zero
/*  f16df48:	0fc5b3e8 */ 	jal	func0f16cfa0
/*  f16df4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16df50:	10000001 */ 	beqz	$zero,.L0f16df58
/*  f16df54:	00404025 */ 	or	$t0,$v0,$zero
.L0f16df58:
/*  f16df58:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16df5c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f16df60:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f16df64:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16df68:	3107ffff */ 	andi	$a3,$t0,0xffff
/*  f16df6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16df70:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f16df74:	3c01800a */ 	lui	$at,0x800a
/*  f16df78:	ac2ea488 */ 	sw	$t6,-0x5b78($at)
/*  f16df7c:	03e00008 */ 	jr	$ra
/*  f16df80:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel audioRestartDefaultTrack
/*  f16df84:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16df88:	8dce24a4 */ 	lw	$t6,0x24a4($t6)
/*  f16df8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16df90:	3c01800a */ 	lui	$at,0x800a
/*  f16df94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16df98:	15c00009 */ 	bnez	$t6,.L0f16dfc0
/*  f16df9c:	ac20a488 */ 	sw	$zero,-0x5b78($at)
/*  f16dfa0:	0fc5b490 */ 	jal	func0f16d240
/*  f16dfa4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16dfa8:	0fc5b490 */ 	jal	func0f16d240
/*  f16dfac:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16dfb0:	3c013f00 */ 	lui	$at,0x3f00
/*  f16dfb4:	44816000 */ 	mtc1	$at,$f12
/*  f16dfb8:	0fc5b52e */ 	jal	func0f16d4b8
/*  f16dfbc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f16dfc0:
/*  f16dfc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16dfc4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16dfc8:	03e00008 */ 	jr	$ra
/*  f16dfcc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioSetAuxTrack
/*  f16dfd0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16dfd4:	3c018008 */ 	lui	$at,0x8008
/*  f16dfd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16dfdc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f16dfe0:	ac2440cc */ 	sw	$a0,0x40cc($at)
/*  f16dfe4:	0fc5b490 */ 	jal	func0f16d240
/*  f16dfe8:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16dfec:	3c028006 */ 	lui	$v0,0x8006
/*  f16dff0:	9442ddc8 */ 	lhu	$v0,-0x2238($v0)
/*  f16dff4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16dff8:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f16dffc:	28415001 */ 	slti	$at,$v0,0x5001
/*  f16e000:	14200003 */ 	bnez	$at,.L0f16e010
/*  f16e004:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f16e008:	10000002 */ 	beqz	$zero,.L0f16e014
/*  f16e00c:	24035000 */ 	addiu	$v1,$zero,0x5000
.L0f16e010:
/*  f16e010:	00401825 */ 	or	$v1,$v0,$zero
.L0f16e014:
/*  f16e014:	0fc5b46f */ 	jal	func0f16d1bc
/*  f16e018:	3067ffff */ 	andi	$a3,$v1,0xffff
/*  f16e01c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16e020:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16e024:	03e00008 */ 	jr	$ra
/*  f16e028:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioRestartAuxTrack
/*  f16e02c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16e030:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16e034:	240effff */ 	addiu	$t6,$zero,-1
/*  f16e038:	3c018008 */ 	lui	$at,0x8008
/*  f16e03c:	ac2e40cc */ 	sw	$t6,0x40cc($at)
/*  f16e040:	0fc5b490 */ 	jal	func0f16d240
/*  f16e044:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16e048:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16e04c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16e050:	03e00008 */ 	jr	$ra
/*  f16e054:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioPlayXTrack
/*  f16e058:	3c0e800b */ 	lui	$t6,%hi(var800aaa68)
/*  f16e05c:	25ceaa68 */ 	addiu	$t6,$t6,%lo(var800aaa68)
/*  f16e060:	00041080 */ 	sll	$v0,$a0,0x2
/*  f16e064:	004e1821 */ 	addu	$v1,$v0,$t6
/*  f16e068:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f16e06c:	240400f0 */ 	addiu	$a0,$zero,0xf0
/*  f16e070:	15e0000e */ 	bnez	$t7,.L0f16e0ac
/*  f16e074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e078:	00a40019 */ 	multu	$a1,$a0
/*  f16e07c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f16e080:	3c01800b */ 	lui	$at,0x800b
/*  f16e084:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f16e088:	00220821 */ 	addu	$at,$at,$v0
/*  f16e08c:	0000c812 */ 	mflo	$t9
/*  f16e090:	ac39aa78 */ 	sw	$t9,-0x5588($at)
/*  f16e094:	3c01800b */ 	lui	$at,0x800b
/*  f16e098:	00c40019 */ 	multu	$a2,$a0
/*  f16e09c:	00220821 */ 	addu	$at,$at,$v0
/*  f16e0a0:	00004012 */ 	mflo	$t0
/*  f16e0a4:	ac28aa88 */ 	sw	$t0,-0x5578($at)
/*  f16e0a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f16e0ac:
/*  f16e0ac:	03e00008 */ 	jr	$ra
/*  f16e0b0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioStopTrack
/*  f16e0b4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16e0b8:	04800006 */ 	bltz	$a0,.L0f16e0d4
/*  f16e0bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16e0c0:	00047080 */ 	sll	$t6,$a0,0x2
/*  f16e0c4:	3c01800b */ 	lui	$at,0x800b
/*  f16e0c8:	002e0821 */ 	addu	$at,$at,$t6
/*  f16e0cc:	10000016 */ 	beqz	$zero,.L0f16e128
/*  f16e0d0:	ac20aa68 */ 	sw	$zero,-0x5598($at)
.L0f16e0d4:
/*  f16e0d4:	3c03800b */ 	lui	$v1,%hi(var800aaa68)
/*  f16e0d8:	3c04800b */ 	lui	$a0,%hi(var800aaa78)
/*  f16e0dc:	3c02800b */ 	lui	$v0,%hi(var800aaa88)
/*  f16e0e0:	3c05800b */ 	lui	$a1,%hi(var800aaa98)
/*  f16e0e4:	24a5aa98 */ 	addiu	$a1,$a1,%lo(var800aaa98)
/*  f16e0e8:	2442aa88 */ 	addiu	$v0,$v0,%lo(var800aaa88)
/*  f16e0ec:	2484aa78 */ 	addiu	$a0,$a0,%lo(var800aaa78)
/*  f16e0f0:	2463aa68 */ 	addiu	$v1,$v1,%lo(var800aaa68)
.L0f16e0f4:
/*  f16e0f4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f16e0f8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f16e0fc:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f16e100:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f16e104:	ac80fffc */ 	sw	$zero,-0x4($a0)
/*  f16e108:	1445fffa */ 	bne	$v0,$a1,.L0f16e0f4
/*  f16e10c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f16e110:	3c0f8008 */ 	lui	$t7,0x8008
/*  f16e114:	8def40d8 */ 	lw	$t7,0x40d8($t7)
/*  f16e118:	51e00004 */ 	beqzl	$t7,.L0f16e12c
/*  f16e11c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16e120:	0fc5b6a9 */ 	jal	func0f16daa4
/*  f16e124:	00000000 */ 	sll	$zero,$zero,0x0
.L0f16e128:
/*  f16e128:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16e12c:
/*  f16e12c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16e130:	03e00008 */ 	jr	$ra
/*  f16e134:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16e138
/*  f16e138:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16e13c:	8dce40cc */ 	lw	$t6,0x40cc($t6)
/*  f16e140:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16e144:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16e148:	15c10014 */ 	bne	$t6,$at,.L0f16e19c
/*  f16e14c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16e150:	0fc5b5b0 */ 	jal	func0f16d6c0
/*  f16e154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e158:	10400006 */ 	beqz	$v0,.L0f16e174
/*  f16e15c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16e160:	44816000 */ 	mtc1	$at,$f12
/*  f16e164:	0fc5b552 */ 	jal	func0f16d548
/*  f16e168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e16c:	10000014 */ 	beqz	$zero,.L0f16e1c0
/*  f16e170:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16e174:
/*  f16e174:	0fc5b449 */ 	jal	func0f16d124
/*  f16e178:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16e17c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16e180:	1441000e */ 	bne	$v0,$at,.L0f16e1bc
/*  f16e184:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16e188:	3c053f80 */ 	lui	$a1,0x3f80
/*  f16e18c:	0fc5b4ab */ 	jal	func0f16d2ac
/*  f16e190:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16e194:	1000000a */ 	beqz	$zero,.L0f16e1c0
/*  f16e198:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16e19c:
/*  f16e19c:	3c04800b */ 	lui	$a0,0x800b
/*  f16e1a0:	0fc5db36 */ 	jal	func0f176cd8
/*  f16e1a4:	8c84a5d0 */ 	lw	$a0,-0x5a30($a0)
/*  f16e1a8:	04400004 */ 	bltz	$v0,.L0f16e1bc
/*  f16e1ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f16e1b0:	44816000 */ 	mtc1	$at,$f12
/*  f16e1b4:	0fc5b552 */ 	jal	func0f16d548
/*  f16e1b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f16e1bc:
/*  f16e1bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16e1c0:
/*  f16e1c0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16e1c4:	03e00008 */ 	jr	$ra
/*  f16e1c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e1cc:	03e00008 */ 	jr	$ra
/*  f16e1d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e1d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e1d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16e1dc:	00000000 */ 	sll	$zero,$zero,0x0
);
