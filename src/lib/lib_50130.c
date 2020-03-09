#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_48650.h"
#include "lib/lib_4a810.h"
#include "lib/lib_4ba90.h"
#include "lib/lib_50130.h"
#include "types.h"

GLOBAL_ASM(
glabel func00050130
/*    50130:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    50134:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    50138:	0c012a18 */ 	jal	__osSiGetAccess
/*    5013c:	afa40030 */ 	sw	$a0,0x30($sp)
/*    50140:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    50144:	0c012fb9 */ 	jal	__osEepStatus
/*    50148:	27a50024 */ 	addiu	$a1,$sp,0x24
/*    5014c:	10400003 */ 	beqz	$v0,.L0005015c
/*    50150:	97ae0024 */ 	lhu	$t6,0x24($sp)
/*    50154:	1000000b */ 	beqz	$zero,.L00050184
/*    50158:	00001825 */ 	or	$v1,$zero,$zero
.L0005015c:
/*    5015c:	31cfc000 */ 	andi	$t7,$t6,0xc000
/*    50160:	34018000 */ 	dli	$at,0x8000
/*    50164:	11e10005 */ 	beq	$t7,$at,.L0005017c
/*    50168:	3401c000 */ 	dli	$at,0xc000
/*    5016c:	11e10005 */ 	beq	$t7,$at,.L00050184
/*    50170:	24030002 */ 	addiu	$v1,$zero,0x2
/*    50174:	10000003 */ 	beqz	$zero,.L00050184
/*    50178:	00001825 */ 	or	$v1,$zero,$zero
.L0005017c:
/*    5017c:	10000001 */ 	beqz	$zero,.L00050184
/*    50180:	24030001 */ 	addiu	$v1,$zero,0x1
.L00050184:
/*    50184:	0c012a29 */ 	jal	__osSiRelAccess
/*    50188:	afa3002c */ 	sw	$v1,0x2c($sp)
/*    5018c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    50190:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*    50194:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    50198:	03e00008 */ 	jr	$ra
/*    5019c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000501a0
/*    501a0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*    501a4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    501a8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    501ac:	afb20020 */ 	sw	$s2,0x20($sp)
/*    501b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    501b4:	3c11800a */ 	lui	$s1,%hi(var8009ca80)
/*    501b8:	00c08025 */ 	or	$s0,$a2,$zero
/*    501bc:	00809025 */ 	or	$s2,$a0,$zero
/*    501c0:	afa50054 */ 	sw	$a1,0x54($sp)
/*    501c4:	0c012a18 */ 	jal	__osSiGetAccess
/*    501c8:	2631ca80 */ 	addiu	$s1,$s1,%lo(var8009ca80)
/*    501cc:	02402025 */ 	or	$a0,$s2,$zero
/*    501d0:	0c012fb9 */ 	jal	__osEepStatus
/*    501d4:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*    501d8:	14400015 */ 	bnez	$v0,.L00050230
/*    501dc:	00402025 */ 	or	$a0,$v0,$zero
/*    501e0:	97ae003c */ 	lhu	$t6,0x3c($sp)
/*    501e4:	34018000 */ 	dli	$at,0x8000
/*    501e8:	93b80057 */ 	lbu	$t8,0x57($sp)
/*    501ec:	31cfc000 */ 	andi	$t7,$t6,0xc000
/*    501f0:	11e10005 */ 	beq	$t7,$at,.L00050208
/*    501f4:	3401c000 */ 	dli	$at,0xc000
/*    501f8:	11e10008 */ 	beq	$t7,$at,.L0005021c
/*    501fc:	93b90057 */ 	lbu	$t9,0x57($sp)
/*    50200:	1000000b */ 	beqz	$zero,.L00050230
/*    50204:	24040008 */ 	addiu	$a0,$zero,0x8
.L00050208:
/*    50208:	2b010040 */ 	slti	$at,$t8,0x40
/*    5020c:	14200008 */ 	bnez	$at,.L00050230
/*    50210:	00000000 */ 	sll	$zero,$zero,0x0
/*    50214:	10000006 */ 	beqz	$zero,.L00050230
/*    50218:	2404ffff */ 	addiu	$a0,$zero,-1
.L0005021c:
/*    5021c:	2b210100 */ 	slti	$at,$t9,0x100
/*    50220:	14200003 */ 	bnez	$at,.L00050230
/*    50224:	00000000 */ 	sll	$zero,$zero,0x0
/*    50228:	10000001 */ 	beqz	$zero,.L00050230
/*    5022c:	2404ffff */ 	addiu	$a0,$zero,-1
.L00050230:
/*    50230:	10800005 */ 	beqz	$a0,.L00050248
/*    50234:	93a8003e */ 	lbu	$t0,0x3e($sp)
/*    50238:	0c012a29 */ 	jal	__osSiRelAccess
/*    5023c:	afa4004c */ 	sw	$a0,0x4c($sp)
/*    50240:	10000042 */ 	beqz	$zero,.L0005034c
/*    50244:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L00050248:
/*    50248:	31090080 */ 	andi	$t1,$t0,0x80
/*    5024c:	11200007 */ 	beqz	$t1,.L0005026c
/*    50250:	02402025 */ 	or	$a0,$s2,$zero
.L00050254:
/*    50254:	0c012fb9 */ 	jal	__osEepStatus
/*    50258:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*    5025c:	93aa003e */ 	lbu	$t2,0x3e($sp)
/*    50260:	314b0080 */ 	andi	$t3,$t2,0x80
/*    50264:	5560fffb */ 	bnezl	$t3,.L00050254
/*    50268:	02402025 */ 	or	$a0,$s2,$zero
.L0005026c:
/*    5026c:	0c0140d9 */ 	jal	func00050364
/*    50270:	93a40057 */ 	lbu	$a0,0x57($sp)
/*    50274:	3c05800a */ 	lui	$a1,%hi(var8009ca80)
/*    50278:	24a5ca80 */ 	addiu	$a1,$a1,%lo(var8009ca80)
/*    5027c:	0c012a34 */ 	jal	__osSiRawStartDma
/*    50280:	24040001 */ 	addiu	$a0,$zero,0x1
/*    50284:	02402025 */ 	or	$a0,$s2,$zero
/*    50288:	00002825 */ 	or	$a1,$zero,$zero
/*    5028c:	0c0121bc */ 	jal	osRecvMesg
/*    50290:	24060001 */ 	addiu	$a2,$zero,0x1
/*    50294:	3c05800a */ 	lui	$a1,%hi(var8009ca80)
/*    50298:	24a5ca80 */ 	addiu	$a1,$a1,%lo(var8009ca80)
/*    5029c:	0c012a34 */ 	jal	__osSiRawStartDma
/*    502a0:	00002025 */ 	or	$a0,$zero,$zero
/*    502a4:	240c0004 */ 	addiu	$t4,$zero,0x4
/*    502a8:	3c01800a */ 	lui	$at,0x800a
/*    502ac:	a02cc820 */ 	sb	$t4,-0x37e0($at)
/*    502b0:	02402025 */ 	or	$a0,$s2,$zero
/*    502b4:	00002825 */ 	or	$a1,$zero,$zero
/*    502b8:	0c0121bc */ 	jal	osRecvMesg
/*    502bc:	24060001 */ 	addiu	$a2,$zero,0x1
/*    502c0:	00001825 */ 	or	$v1,$zero,$zero
.L000502c4:
/*    502c4:	24630001 */ 	addiu	$v1,$v1,0x1
/*    502c8:	28610004 */ 	slti	$at,$v1,0x4
/*    502cc:	1420fffd */ 	bnez	$at,.L000502c4
/*    502d0:	26310001 */ 	addiu	$s1,$s1,0x1
/*    502d4:	8a210000 */ 	lwl	$at,0x0($s1)
/*    502d8:	9a210003 */ 	lwr	$at,0x3($s1)
/*    502dc:	27ad0030 */ 	addiu	$t5,$sp,0x30
/*    502e0:	27a30038 */ 	addiu	$v1,$sp,0x38
/*    502e4:	ada10000 */ 	sw	$at,0x0($t5)
/*    502e8:	8a2f0004 */ 	lwl	$t7,0x4($s1)
/*    502ec:	9a2f0007 */ 	lwr	$t7,0x7($s1)
/*    502f0:	adaf0004 */ 	sw	$t7,0x4($t5)
/*    502f4:	8a210008 */ 	lwl	$at,0x8($s1)
/*    502f8:	9a21000b */ 	lwr	$at,0xb($s1)
/*    502fc:	ada10008 */ 	sw	$at,0x8($t5)
/*    50300:	93a20031 */ 	lbu	$v0,0x31($sp)
/*    50304:	305800c0 */ 	andi	$t8,$v0,0xc0
/*    50308:	00182103 */ 	sra	$a0,$t8,0x4
/*    5030c:	1480000c */ 	bnez	$a0,.L00050340
/*    50310:	27a20030 */ 	addiu	$v0,$sp,0x30
.L00050314:
/*    50314:	90480004 */ 	lbu	$t0,0x4($v0)
/*    50318:	24420004 */ 	addiu	$v0,$v0,0x4
/*    5031c:	26100004 */ 	addiu	$s0,$s0,0x4
/*    50320:	a208fffc */ 	sb	$t0,-0x4($s0)
/*    50324:	90490001 */ 	lbu	$t1,0x1($v0)
/*    50328:	a209fffd */ 	sb	$t1,-0x3($s0)
/*    5032c:	904a0002 */ 	lbu	$t2,0x2($v0)
/*    50330:	a20afffe */ 	sb	$t2,-0x2($s0)
/*    50334:	904b0003 */ 	lbu	$t3,0x3($v0)
/*    50338:	1443fff6 */ 	bne	$v0,$v1,.L00050314
/*    5033c:	a20bffff */ 	sb	$t3,-0x1($s0)
.L00050340:
/*    50340:	0c012a29 */ 	jal	__osSiRelAccess
/*    50344:	afa4004c */ 	sw	$a0,0x4c($sp)
/*    50348:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0005034c:
/*    5034c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    50350:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    50354:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    50358:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    5035c:	03e00008 */ 	jr	$ra
/*    50360:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func00050364
/*    50364:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    50368:	3c03800a */ 	lui	$v1,%hi(var8009ca80)
/*    5036c:	2463ca80 */ 	addiu	$v1,$v1,%lo(var8009ca80)
/*    50370:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    50374:	ac6f003c */ 	sw	$t7,0x3c($v1)
/*    50378:	24180002 */ 	addiu	$t8,$zero,0x2
/*    5037c:	24190008 */ 	addiu	$t9,$zero,0x8
/*    50380:	24080004 */ 	addiu	$t0,$zero,0x4
/*    50384:	3c01800a */ 	lui	$at,0x800a
/*    50388:	3c02800a */ 	lui	$v0,0x800a
/*    5038c:	afa40018 */ 	sw	$a0,0x18($sp)
/*    50390:	a3b80008 */ 	sb	$t8,0x8($sp)
/*    50394:	a3b90009 */ 	sb	$t9,0x9($sp)
/*    50398:	a3a8000a */ 	sb	$t0,0xa($sp)
/*    5039c:	a3a4000b */ 	sb	$a0,0xb($sp)
/*    503a0:	2442ca81 */ 	addiu	$v0,$v0,-13695
/*    503a4:	a020ca80 */ 	sb	$zero,-0x3580($at)
/*    503a8:	a0400002 */ 	sb	$zero,0x2($v0)
/*    503ac:	a0400001 */ 	sb	$zero,0x1($v0)
/*    503b0:	a0400000 */ 	sb	$zero,0x0($v0)
/*    503b4:	27a90008 */ 	addiu	$t1,$sp,0x8
/*    503b8:	8d210000 */ 	lw	$at,0x0($t1)
/*    503bc:	240c00fe */ 	addiu	$t4,$zero,0xfe
/*    503c0:	2442000f */ 	addiu	$v0,$v0,0xf
/*    503c4:	a841fff4 */ 	swl	$at,-0xc($v0)
/*    503c8:	b841fff7 */ 	swr	$at,-0x9($v0)
/*    503cc:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*    503d0:	a84bfff8 */ 	swl	$t3,-0x8($v0)
/*    503d4:	b84bfffb */ 	swr	$t3,-0x5($v0)
/*    503d8:	8d210008 */ 	lw	$at,0x8($t1)
/*    503dc:	a04c0000 */ 	sb	$t4,0x0($v0)
/*    503e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    503e4:	a841fffc */ 	swl	$at,-0x4($v0)
/*    503e8:	03e00008 */ 	jr	$ra
/*    503ec:	b841ffff */ 	swr	$at,-0x1($v0)
);

GLOBAL_ASM(
glabel func000503f0
/*    503f0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    503f4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    503f8:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    503fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    50400:	afa40020 */ 	sw	$a0,0x20($sp)
/*    50404:	afa50024 */ 	sw	$a1,0x24($sp)
/*    50408:	afa60028 */ 	sw	$a2,0x28($sp)
/*    5040c:	19c00016 */ 	blez	$t6,.L00050468
/*    50410:	afa0001c */ 	sw	$zero,0x1c($sp)
.L00050414:
/*    50414:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    50418:	93a50027 */ 	lbu	$a1,0x27($sp)
/*    5041c:	0c014068 */ 	jal	func000501a0
/*    50420:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    50424:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    50428:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    5042c:	11e00003 */ 	beqz	$t7,.L0005043c
/*    50430:	00000000 */ 	sll	$zero,$zero,0x0
/*    50434:	1000000d */ 	beqz	$zero,.L0005046c
/*    50438:	01e01025 */ 	or	$v0,$t7,$zero
.L0005043c:
/*    5043c:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    50440:	93a80027 */ 	lbu	$t0,0x27($sp)
/*    50444:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    50448:	2719fff8 */ 	addiu	$t9,$t8,-8
/*    5044c:	afb9002c */ 	sw	$t9,0x2c($sp)
/*    50450:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    50454:	25090001 */ 	addiu	$t1,$t0,0x1
/*    50458:	254b0008 */ 	addiu	$t3,$t2,0x8
/*    5045c:	a3a90027 */ 	sb	$t1,0x27($sp)
/*    50460:	1d80ffec */ 	bgtz	$t4,.L00050414
/*    50464:	afab0028 */ 	sw	$t3,0x28($sp)
.L00050468:
/*    50468:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L0005046c:
/*    5046c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    50470:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    50474:	03e00008 */ 	jr	$ra
/*    50478:	00000000 */ 	sll	$zero,$zero,0x0
/*    5047c:	00000000 */ 	sll	$zero,$zero,0x0
);
