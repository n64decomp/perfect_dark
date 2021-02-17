#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4cc10.h"
#include "lib/lib_4ce60.h"
#include "lib/lib_4d000.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004d000
/*    4d000:	27bdfd68 */ 	addiu	$sp,$sp,-664
/*    4d004:	afb70040 */ 	sw	$s7,0x40($sp)
/*    4d008:	afb6003c */ 	sw	$s6,0x3c($sp)
/*    4d00c:	afb50038 */ 	sw	$s5,0x38($sp)
/*    4d010:	afb30030 */ 	sw	$s3,0x30($sp)
/*    4d014:	afa5029c */ 	sw	$a1,0x29c($sp)
/*    4d018:	30aeffff */ 	andi	$t6,$a1,0xffff
/*    4d01c:	01c02825 */ 	or	$a1,$t6,$zero
/*    4d020:	00809825 */ 	or	$s3,$a0,$zero
/*    4d024:	afbf0044 */ 	sw	$ra,0x44($sp)
/*    4d028:	afb40034 */ 	sw	$s4,0x34($sp)
/*    4d02c:	afb2002c */ 	sw	$s2,0x2c($sp)
/*    4d030:	afb10028 */ 	sw	$s1,0x28($sp)
/*    4d034:	afb00024 */ 	sw	$s0,0x24($sp)
/*    4d038:	afa702a4 */ 	sw	$a3,0x2a4($sp)
/*    4d03c:	0000b025 */ 	or	$s6,$zero,$zero
/*    4d040:	0000b825 */ 	or	$s7,$zero,$zero
/*    4d044:	11c00003 */ 	beqz	$t6,.L0004d054
/*    4d048:	0000a825 */ 	or	$s5,$zero,$zero
/*    4d04c:	14c00003 */ 	bnez	$a2,.L0004d05c
/*    4d050:	8fb102ac */ 	lw	$s1,0x2ac($sp)
.L0004d054:
/*    4d054:	100000ac */ 	b	.L0004d308
/*    4d058:	24020005 */ 	addiu	$v0,$zero,0x5
.L0004d05c:
/*    4d05c:	263000ff */ 	addiu	$s0,$s1,0xff
/*    4d060:	8fb802a8 */ 	lw	$t8,0x2a8($sp)
/*    4d064:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*    4d068:	06010003 */ 	bgez	$s0,.L0004d078
/*    4d06c:	00107a03 */ 	sra	$t7,$s0,0x8
/*    4d070:	260100ff */ 	addiu	$at,$s0,0xff
/*    4d074:	00017a03 */ 	sra	$t7,$at,0x8
.L0004d078:
/*    4d078:	01e08025 */ 	or	$s0,$t7,$zero
/*    4d07c:	01e0a025 */ 	or	$s4,$t7,$zero
/*    4d080:	02602025 */ 	or	$a0,$s3,$zero
/*    4d084:	8fa702a4 */ 	lw	$a3,0x2a4($sp)
/*    4d088:	a7a5029e */ 	sh	$a1,0x29e($sp)
/*    4d08c:	afa602a0 */ 	sw	$a2,0x2a0($sp)
/*    4d090:	afb80010 */ 	sw	$t8,0x10($sp)
/*    4d094:	0c013304 */ 	jal	func0004cc10
/*    4d098:	afb90014 */ 	sw	$t9,0x14($sp)
/*    4d09c:	10400005 */ 	beqz	$v0,.L0004d0b4
/*    4d0a0:	24010005 */ 	addiu	$at,$zero,0x5
/*    4d0a4:	50410004 */ 	beql	$v0,$at,.L0004d0b8
/*    4d0a8:	8fa802b0 */ 	lw	$t0,0x2b0($sp)
/*    4d0ac:	10000097 */ 	b	.L0004d30c
/*    4d0b0:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d0b4:
/*    4d0b4:	8fa802b0 */ 	lw	$t0,0x2b0($sp)
.L0004d0b8:
/*    4d0b8:	2401ffff */ 	addiu	$at,$zero,-1
/*    4d0bc:	02602025 */ 	or	$a0,$s3,$zero
/*    4d0c0:	8d090000 */ 	lw	$t1,0x0($t0)
/*    4d0c4:	11210003 */ 	beq	$t1,$at,.L0004d0d4
/*    4d0c8:	00000000 */ 	nop
/*    4d0cc:	1000008e */ 	b	.L0004d308
/*    4d0d0:	24020009 */ 	addiu	$v0,$zero,0x9
.L0004d0d4:
/*    4d0d4:	0c013398 */ 	jal	func0004ce60
/*    4d0d8:	27a50054 */ 	addiu	$a1,$sp,0x54
/*    4d0dc:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    4d0e0:	0151082a */ 	slt	$at,$t2,$s1
/*    4d0e4:	10200003 */ 	beqz	$at,.L0004d0f4
/*    4d0e8:	00000000 */ 	nop
/*    4d0ec:	10000086 */ 	b	.L0004d308
/*    4d0f0:	24020007 */ 	addiu	$v0,$zero,0x7
.L0004d0f4:
/*    4d0f4:	16000003 */ 	bnez	$s0,.L0004d104
/*    4d0f8:	02602025 */ 	or	$a0,$s3,$zero
/*    4d0fc:	10000082 */ 	b	.L0004d308
/*    4d100:	24020005 */ 	addiu	$v0,$zero,0x5
.L0004d104:
/*    4d104:	8fab02b0 */ 	lw	$t3,0x2b0($sp)
/*    4d108:	00002825 */ 	or	$a1,$zero,$zero
/*    4d10c:	00003025 */ 	or	$a2,$zero,$zero
/*    4d110:	00003825 */ 	or	$a3,$zero,$zero
/*    4d114:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4d118:	0c013304 */ 	jal	func0004cc10
/*    4d11c:	afab0014 */ 	sw	$t3,0x14($sp)
/*    4d120:	10400005 */ 	beqz	$v0,.L0004d138
/*    4d124:	24010005 */ 	addiu	$at,$zero,0x5
/*    4d128:	50410004 */ 	beql	$v0,$at,.L0004d13c
/*    4d12c:	8fac02b0 */ 	lw	$t4,0x2b0($sp)
/*    4d130:	10000076 */ 	b	.L0004d30c
/*    4d134:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d138:
/*    4d138:	8fac02b0 */ 	lw	$t4,0x2b0($sp)
.L0004d13c:
/*    4d13c:	2401ffff */ 	addiu	$at,$zero,-1
/*    4d140:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    4d144:	55a10004 */ 	bnel	$t5,$at,.L0004d158
/*    4d148:	926e0064 */ 	lbu	$t6,0x64($s3)
/*    4d14c:	1000006e */ 	b	.L0004d308
/*    4d150:	24020008 */ 	addiu	$v0,$zero,0x8
/*    4d154:	926e0064 */ 	lbu	$t6,0x64($s3)
.L0004d158:
/*    4d158:	00008025 */ 	or	$s0,$zero,$zero
/*    4d15c:	27b20180 */ 	addiu	$s2,$sp,0x180
/*    4d160:	19c00049 */ 	blez	$t6,.L0004d288
/*    4d164:	27b10080 */ 	addiu	$s1,$sp,0x80
.L0004d168:
/*    4d168:	02602025 */ 	or	$a0,$s3,$zero
/*    4d16c:	02402825 */ 	or	$a1,$s2,$zero
/*    4d170:	00003025 */ 	or	$a2,$zero,$zero
/*    4d174:	0c01324d */ 	jal	func0004c934
/*    4d178:	320700ff */ 	andi	$a3,$s0,0xff
/*    4d17c:	10400003 */ 	beqz	$v0,.L0004d18c
/*    4d180:	02602025 */ 	or	$a0,$s3,$zero
/*    4d184:	10000061 */ 	b	.L0004d30c
/*    4d188:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d18c:
/*    4d18c:	27af0290 */ 	addiu	$t7,$sp,0x290
/*    4d190:	27b8028c */ 	addiu	$t8,$sp,0x28c
/*    4d194:	afb80018 */ 	sw	$t8,0x18($sp)
/*    4d198:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    4d19c:	02402825 */ 	or	$a1,$s2,$zero
/*    4d1a0:	02803025 */ 	or	$a2,$s4,$zero
/*    4d1a4:	27a70294 */ 	addiu	$a3,$sp,0x294
/*    4d1a8:	0c0134cd */ 	jal	func0004d334
/*    4d1ac:	afb00010 */ 	sw	$s0,0x10($sp)
/*    4d1b0:	10400003 */ 	beqz	$v0,.L0004d1c0
/*    4d1b4:	8fa30294 */ 	lw	$v1,0x294($sp)
/*    4d1b8:	10000054 */ 	b	.L0004d30c
/*    4d1bc:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d1c0:
/*    4d1c0:	2401ffff */ 	addiu	$at,$zero,-1
/*    4d1c4:	5061002b */ 	beql	$v1,$at,.L0004d274
/*    4d1c8:	926b0064 */ 	lbu	$t3,0x64($s3)
/*    4d1cc:	16a00004 */ 	bnez	$s5,.L0004d1e0
/*    4d1d0:	0016c840 */ 	sll	$t9,$s6,0x1
/*    4d1d4:	a3a30051 */ 	sb	$v1,0x51($sp)
/*    4d1d8:	1000000d */ 	b	.L0004d210
/*    4d1dc:	a3b00050 */ 	sb	$s0,0x50($sp)
.L0004d1e0:
/*    4d1e0:	02391021 */ 	addu	$v0,$s1,$t9
/*    4d1e4:	a0500000 */ 	sb	$s0,0x0($v0)
/*    4d1e8:	a0430001 */ 	sb	$v1,0x1($v0)
/*    4d1ec:	02602025 */ 	or	$a0,$s3,$zero
/*    4d1f0:	02202825 */ 	or	$a1,$s1,$zero
/*    4d1f4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4d1f8:	0c01324d */ 	jal	func0004c934
/*    4d1fc:	32e700ff */ 	andi	$a3,$s7,0xff
/*    4d200:	50400004 */ 	beqzl	$v0,.L0004d214
/*    4d204:	8fa80290 */ 	lw	$t0,0x290($sp)
/*    4d208:	10000040 */ 	b	.L0004d30c
/*    4d20c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d210:
/*    4d210:	8fa80290 */ 	lw	$t0,0x290($sp)
.L0004d214:
/*    4d214:	02402025 */ 	or	$a0,$s2,$zero
/*    4d218:	02202825 */ 	or	$a1,$s1,$zero
/*    4d21c:	0114082a */ 	slt	$at,$t0,$s4
/*    4d220:	5020000a */ 	beqzl	$at,.L0004d24c
/*    4d224:	0000a025 */ 	or	$s4,$zero,$zero
/*    4d228:	0c012c5c */ 	jal	func0004b170
/*    4d22c:	24060100 */ 	addiu	$a2,$zero,0x100
/*    4d230:	8fa90290 */ 	lw	$t1,0x290($sp)
/*    4d234:	8fb6028c */ 	lw	$s6,0x28c($sp)
/*    4d238:	321700ff */ 	andi	$s7,$s0,0xff
/*    4d23c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*    4d240:	1000000b */ 	b	.L0004d270
/*    4d244:	0289a023 */ 	subu	$s4,$s4,$t1
/*    4d248:	0000a025 */ 	or	$s4,$zero,$zero
.L0004d24c:
/*    4d24c:	02602025 */ 	or	$a0,$s3,$zero
/*    4d250:	02402825 */ 	or	$a1,$s2,$zero
/*    4d254:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4d258:	0c01324d */ 	jal	func0004c934
/*    4d25c:	320700ff */ 	andi	$a3,$s0,0xff
/*    4d260:	10400009 */ 	beqz	$v0,.L0004d288
/*    4d264:	00000000 */ 	nop
/*    4d268:	10000028 */ 	b	.L0004d30c
/*    4d26c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d270:
/*    4d270:	926b0064 */ 	lbu	$t3,0x64($s3)
.L0004d274:
/*    4d274:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4d278:	320a00ff */ 	andi	$t2,$s0,0xff
/*    4d27c:	014b082a */ 	slt	$at,$t2,$t3
/*    4d280:	1420ffb9 */ 	bnez	$at,.L0004d168
/*    4d284:	01408025 */ 	or	$s0,$t2,$zero
.L0004d288:
/*    4d288:	1e800004 */ 	bgtz	$s4,.L0004d29c
/*    4d28c:	8fa30294 */ 	lw	$v1,0x294($sp)
/*    4d290:	2401ffff */ 	addiu	$at,$zero,-1
/*    4d294:	14610003 */ 	bne	$v1,$at,.L0004d2a4
/*    4d298:	97ac0050 */ 	lhu	$t4,0x50($sp)
.L0004d29c:
/*    4d29c:	1000001a */ 	b	.L0004d308
/*    4d2a0:	24020003 */ 	addiu	$v0,$zero,0x3
.L0004d2a4:
/*    4d2a4:	97ad029e */ 	lhu	$t5,0x29e($sp)
/*    4d2a8:	8fae02a0 */ 	lw	$t6,0x2a0($sp)
/*    4d2ac:	a7ac0066 */ 	sh	$t4,0x66($sp)
/*    4d2b0:	a7a0006a */ 	sh	$zero,0x6a($sp)
/*    4d2b4:	8fa402a4 */ 	lw	$a0,0x2a4($sp)
/*    4d2b8:	27a50070 */ 	addiu	$a1,$sp,0x70
/*    4d2bc:	24060010 */ 	addiu	$a2,$zero,0x10
/*    4d2c0:	a7ad0064 */ 	sh	$t5,0x64($sp)
/*    4d2c4:	0c012c5c */ 	jal	func0004b170
/*    4d2c8:	afae0060 */ 	sw	$t6,0x60($sp)
/*    4d2cc:	8fa402a8 */ 	lw	$a0,0x2a8($sp)
/*    4d2d0:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4d2d4:	0c012c5c */ 	jal	func0004b170
/*    4d2d8:	24060004 */ 	addiu	$a2,$zero,0x4
/*    4d2dc:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*    4d2e0:	8e79005c */ 	lw	$t9,0x5c($s3)
/*    4d2e4:	8e640004 */ 	lw	$a0,0x4($s3)
/*    4d2e8:	8df80000 */ 	lw	$t8,0x0($t7)
/*    4d2ec:	8e650008 */ 	lw	$a1,0x8($s3)
/*    4d2f0:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4d2f4:	03193021 */ 	addu	$a2,$t8,$t9
/*    4d2f8:	30c8ffff */ 	andi	$t0,$a2,0xffff
/*    4d2fc:	01003025 */ 	or	$a2,$t0,$zero
/*    4d300:	0c012d84 */ 	jal	__osContRamWrite
/*    4d304:	27a70060 */ 	addiu	$a3,$sp,0x60
.L0004d308:
/*    4d308:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d30c:
/*    4d30c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*    4d310:	8fb10028 */ 	lw	$s1,0x28($sp)
/*    4d314:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*    4d318:	8fb30030 */ 	lw	$s3,0x30($sp)
/*    4d31c:	8fb40034 */ 	lw	$s4,0x34($sp)
/*    4d320:	8fb50038 */ 	lw	$s5,0x38($sp)
/*    4d324:	8fb6003c */ 	lw	$s6,0x3c($sp)
/*    4d328:	8fb70040 */ 	lw	$s7,0x40($sp)
/*    4d32c:	03e00008 */ 	jr	$ra
/*    4d330:	27bd0298 */ 	addiu	$sp,$sp,0x298
);

GLOBAL_ASM(
glabel func0004d334
/*    4d334:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4d338:	afb00008 */ 	sw	$s0,0x8($sp)
/*    4d33c:	93b00023 */ 	lbu	$s0,0x23($sp)
/*    4d340:	afb1000c */ 	sw	$s1,0xc($sp)
/*    4d344:	00c08825 */ 	or	$s1,$a2,$zero
/*    4d348:	1a000003 */ 	blez	$s0,.L0004d358
/*    4d34c:	240b0080 */ 	addiu	$t3,$zero,0x80
/*    4d350:	10000002 */ 	b	.L0004d35c
/*    4d354:	24020001 */ 	addiu	$v0,$zero,0x1
.L0004d358:
/*    4d358:	8c820060 */ 	lw	$v0,0x60($a0)
.L0004d35c:
/*    4d35c:	28410080 */ 	slti	$at,$v0,0x80
/*    4d360:	1020000a */ 	beqz	$at,.L0004d38c
/*    4d364:	00401825 */ 	or	$v1,$v0,$zero
/*    4d368:	00027040 */ 	sll	$t6,$v0,0x1
/*    4d36c:	00ae1021 */ 	addu	$v0,$a1,$t6
/*    4d370:	240a0003 */ 	addiu	$t2,$zero,0x3
.L0004d374:
/*    4d374:	944f0000 */ 	lhu	$t7,0x0($v0)
/*    4d378:	514f0005 */ 	beql	$t2,$t7,.L0004d390
/*    4d37c:	240b0080 */ 	addiu	$t3,$zero,0x80
/*    4d380:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4d384:	146bfffb */ 	bne	$v1,$t3,.L0004d374
/*    4d388:	24420002 */ 	addiu	$v0,$v0,0x2
.L0004d38c:
/*    4d38c:	240b0080 */ 	addiu	$t3,$zero,0x80
.L0004d390:
/*    4d390:	146b0005 */ 	bne	$v1,$t3,.L0004d3a8
/*    4d394:	240a0003 */ 	addiu	$t2,$zero,0x3
/*    4d398:	2418ffff */ 	addiu	$t8,$zero,-1
/*    4d39c:	acf80000 */ 	sw	$t8,0x0($a3)
/*    4d3a0:	10000030 */ 	b	.L0004d464
/*    4d3a4:	00001025 */ 	or	$v0,$zero,$zero
.L0004d3a8:
/*    4d3a8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    4d3ac:	00602025 */ 	or	$a0,$v1,$zero
/*    4d3b0:	24190001 */ 	addiu	$t9,$zero,0x1
/*    4d3b4:	00604025 */ 	or	$t0,$v1,$zero
/*    4d3b8:	2a210002 */ 	slti	$at,$s1,0x2
/*    4d3bc:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4d3c0:	14200018 */ 	bnez	$at,.L0004d424
/*    4d3c4:	acd90000 */ 	sw	$t9,0x0($a2)
/*    4d3c8:	28610080 */ 	slti	$at,$v1,0x80
/*    4d3cc:	10200015 */ 	beqz	$at,.L0004d424
/*    4d3d0:	00036040 */ 	sll	$t4,$v1,0x1
/*    4d3d4:	00ac1021 */ 	addu	$v0,$a1,$t4
/*    4d3d8:	944d0000 */ 	lhu	$t5,0x0($v0)
.L0004d3dc:
/*    4d3dc:	00087040 */ 	sll	$t6,$t0,0x1
/*    4d3e0:	00ae4821 */ 	addu	$t1,$a1,$t6
/*    4d3e4:	554d0008 */ 	bnel	$t2,$t5,.L0004d408
/*    4d3e8:	8cd90000 */ 	lw	$t9,0x0($a2)
/*    4d3ec:	a1300000 */ 	sb	$s0,0x0($t1)
/*    4d3f0:	a1230001 */ 	sb	$v1,0x1($t1)
/*    4d3f4:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*    4d3f8:	00604025 */ 	or	$t0,$v1,$zero
/*    4d3fc:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    4d400:	acd80000 */ 	sw	$t8,0x0($a2)
/*    4d404:	8cd90000 */ 	lw	$t9,0x0($a2)
.L0004d408:
/*    4d408:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4d40c:	24420002 */ 	addiu	$v0,$v0,0x2
/*    4d410:	0331082a */ 	slt	$at,$t9,$s1
/*    4d414:	10200003 */ 	beqz	$at,.L0004d424
/*    4d418:	28610080 */ 	slti	$at,$v1,0x80
/*    4d41c:	5420ffef */ 	bnezl	$at,.L0004d3dc
/*    4d420:	944d0000 */ 	lhu	$t5,0x0($v0)
.L0004d424:
/*    4d424:	146b0008 */ 	bne	$v1,$t3,.L0004d448
/*    4d428:	ace40000 */ 	sw	$a0,0x0($a3)
/*    4d42c:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*    4d430:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    4d434:	0191082a */ 	slt	$at,$t4,$s1
/*    4d438:	50200004 */ 	beqzl	$at,.L0004d44c
/*    4d43c:	00087840 */ 	sll	$t7,$t0,0x1
/*    4d440:	10000007 */ 	b	.L0004d460
/*    4d444:	ada80000 */ 	sw	$t0,0x0($t5)
.L0004d448:
/*    4d448:	00087840 */ 	sll	$t7,$t0,0x1
.L0004d44c:
/*    4d44c:	00afc021 */ 	addu	$t8,$a1,$t7
/*    4d450:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4d454:	a70e0000 */ 	sh	$t6,0x0($t8)
/*    4d458:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    4d45c:	af200000 */ 	sw	$zero,0x0($t9)
.L0004d460:
/*    4d460:	00001025 */ 	or	$v0,$zero,$zero
.L0004d464:
/*    4d464:	8fb00008 */ 	lw	$s0,0x8($sp)
/*    4d468:	8fb1000c */ 	lw	$s1,0xc($sp)
/*    4d46c:	03e00008 */ 	jr	$ra
/*    4d470:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*    4d474:	00000000 */ 	nop
/*    4d478:	00000000 */ 	nop
/*    4d47c:	00000000 */ 	nop
);