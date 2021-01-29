#include <libultra_internal.h>

GLOBAL_ASM(
glabel osCreateViManager
/*     3050:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     3054:	afb00020 */ 	sw	$s0,0x20($sp)
/*     3058:	3c108006 */ 	lui	$s0,%hi(__osViDevMgr)
/*     305c:	2610cee0 */ 	addiu	$s0,$s0,%lo(__osViDevMgr)
/*     3060:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*     3064:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     3068:	afa40030 */ 	sw	$a0,0x30($sp)
/*     306c:	55c00054 */ 	bnezl	$t6,.L000031c0
/*     3070:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     3074:	0c01246c */ 	jal	__osTimerServicesInit
/*     3078:	00000000 */ 	nop
/*     307c:	3c018006 */ 	lui	$at,%hi(var8005cefc)
/*     3080:	3c048009 */ 	lui	$a0,%hi(__viEventQueue)
/*     3084:	3c058009 */ 	lui	$a1,%hi(viEventBuf)
/*     3088:	ac20cefc */ 	sw	$zero,%lo(var8005cefc)($at)
/*     308c:	24a50248 */ 	addiu	$a1,$a1,%lo(viEventBuf)
/*     3090:	24840230 */ 	addiu	$a0,$a0,%lo(__viEventQueue)
/*     3094:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     3098:	24060005 */ 	addiu	$a2,$zero,0x5
/*     309c:	3c068009 */ 	lui	$a2,%hi(viRetraceMsg)
/*     30a0:	3c078009 */ 	lui	$a3,%hi(viCounterMsg)
/*     30a4:	24e70278 */ 	addiu	$a3,$a3,%lo(viCounterMsg)
/*     30a8:	24c60260 */ 	addiu	$a2,$a2,%lo(viRetraceMsg)
/*     30ac:	240f000d */ 	addiu	$t7,$zero,0xd
/*     30b0:	2418000e */ 	addiu	$t8,$zero,0xe
/*     30b4:	3c058009 */ 	lui	$a1,%hi(__viEventQueue)
/*     30b8:	a4cf0000 */ 	sh	$t7,0x0($a2)
/*     30bc:	a0c00002 */ 	sb	$zero,0x2($a2)
/*     30c0:	acc00004 */ 	sw	$zero,0x4($a2)
/*     30c4:	a4f80000 */ 	sh	$t8,0x0($a3)
/*     30c8:	a0e00002 */ 	sb	$zero,0x2($a3)
/*     30cc:	ace00004 */ 	sw	$zero,0x4($a3)
/*     30d0:	24a50230 */ 	addiu	$a1,$a1,%lo(__viEventQueue)
/*     30d4:	0c012148 */ 	jal	osSetEventMesg
/*     30d8:	24040007 */ 	addiu	$a0,$zero,0x7
/*     30dc:	3c078009 */ 	lui	$a3,%hi(viCounterMsg)
/*     30e0:	3c058009 */ 	lui	$a1,%hi(__viEventQueue)
/*     30e4:	24e60278 */ 	addiu	$a2,$a3,%lo(viCounterMsg)
/*     30e8:	24a50230 */ 	addiu	$a1,$a1,%lo(__viEventQueue)
/*     30ec:	0c012148 */ 	jal	osSetEventMesg
/*     30f0:	24040003 */ 	addiu	$a0,$zero,0x3
/*     30f4:	2419ffff */ 	addiu	$t9,$zero,-1
/*     30f8:	afb90028 */ 	sw	$t9,0x28($sp)
/*     30fc:	0c012230 */ 	jal	osGetThreadPri
/*     3100:	00002025 */ 	or	$a0,$zero,$zero
/*     3104:	8fa80030 */ 	lw	$t0,0x30($sp)
/*     3108:	00002025 */ 	or	$a0,$zero,$zero
/*     310c:	0048082a */ 	slt	$at,$v0,$t0
/*     3110:	10200003 */ 	beqz	$at,.L00003120
/*     3114:	01002825 */ 	or	$a1,$t0,$zero
/*     3118:	0c01210c */ 	jal	osSetThreadPri
/*     311c:	afa20028 */ 	sw	$v0,0x28($sp)
.L00003120:
/*     3120:	0c01256c */ 	jal	__osDisableInt
/*     3124:	00000000 */ 	nop
/*     3128:	8fab0030 */ 	lw	$t3,0x30($sp)
/*     312c:	3c038009 */ 	lui	$v1,%hi(__viEventQueue)
/*     3130:	3c048009 */ 	lui	$a0,%hi(viThread)
/*     3134:	3c0a8009 */ 	lui	$t2,%hi(__viEventQueue)
/*     3138:	2484fe00 */ 	addiu	$a0,$a0,%lo(viThread)
/*     313c:	24630230 */ 	addiu	$v1,$v1,%lo(__viEventQueue)
/*     3140:	24090001 */ 	addiu	$t1,$zero,0x1
/*     3144:	254a0230 */ 	addiu	$t2,$t2,%lo(__viEventQueue)
/*     3148:	3c067000 */ 	lui	$a2,%hi(viMgrMain)
/*     314c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*     3150:	ae090000 */ 	sw	$t1,0x0($s0)
/*     3154:	ae040004 */ 	sw	$a0,0x4($s0)
/*     3158:	ae030008 */ 	sw	$v1,0x8($s0)
/*     315c:	ae03000c */ 	sw	$v1,0xc($s0)
/*     3160:	ae000010 */ 	sw	$zero,0x10($s0)
/*     3164:	ae000014 */ 	sw	$zero,0x14($s0)
/*     3168:	ae000018 */ 	sw	$zero,0x18($s0)
/*     316c:	24c631d0 */ 	addiu	$a2,$a2,%lo(viMgrMain)
/*     3170:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     3174:	00002825 */ 	or	$a1,$zero,$zero
/*     3178:	02003825 */ 	or	$a3,$s0,$zero
/*     317c:	0c000fb8 */ 	jal	osCreateThread
/*     3180:	afab0014 */ 	sw	$t3,0x14($sp)
/*     3184:	0c012590 */ 	jal	__osViInit
/*     3188:	00000000 */ 	nop
/*     318c:	3c048009 */ 	lui	$a0,%hi(viThread)
/*     3190:	0c01207c */ 	jal	osStartThread
/*     3194:	2484fe00 */ 	addiu	$a0,$a0,%lo(viThread)
/*     3198:	0c012588 */ 	jal	__osRestoreInt
/*     319c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*     31a0:	8fac0028 */ 	lw	$t4,0x28($sp)
/*     31a4:	2401ffff */ 	addiu	$at,$zero,-1
/*     31a8:	00002025 */ 	or	$a0,$zero,$zero
/*     31ac:	51810004 */ 	beql	$t4,$at,.L000031c0
/*     31b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     31b4:	0c01210c */ 	jal	osSetThreadPri
/*     31b8:	01802825 */ 	or	$a1,$t4,$zero
/*     31bc:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L000031c0:
/*     31c0:	8fb00020 */ 	lw	$s0,0x20($sp)
/*     31c4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*     31c8:	03e00008 */ 	jr	$ra
/*     31cc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel viMgrMain
/*     31d0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*     31d4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     31d8:	afb70030 */ 	sw	$s7,0x30($sp)
/*     31dc:	0080b825 */ 	or	$s7,$a0,$zero
/*     31e0:	afb6002c */ 	sw	$s6,0x2c($sp)
/*     31e4:	afb50028 */ 	sw	$s5,0x28($sp)
/*     31e8:	afb40024 */ 	sw	$s4,0x24($sp)
/*     31ec:	afb30020 */ 	sw	$s3,0x20($sp)
/*     31f0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     31f4:	afb10018 */ 	sw	$s1,0x18($sp)
/*     31f8:	afb00014 */ 	sw	$s0,0x14($sp)
/*     31fc:	0c0125e0 */ 	jal	__osViGetCurrentContext
/*     3200:	afa00044 */ 	sw	$zero,0x44($sp)
/*     3204:	94430002 */ 	lhu	$v1,0x2($v0)
/*     3208:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     320c:	2416000e */ 	addiu	$s6,$zero,0xe
/*     3210:	14600004 */ 	bnez	$v1,.L00003224
/*     3214:	a4230290 */ 	sh	$v1,%lo(var80090290)($at)
/*     3218:	24030001 */ 	addiu	$v1,$zero,0x1
/*     321c:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     3220:	a4230290 */ 	sh	$v1,%lo(var80090290)($at)
.L00003224:
/*     3224:	3c13800a */ 	lui	$s3,%hi(var8009c78c)
/*     3228:	3c12800a */ 	lui	$s2,%hi(var8009c788)
/*     322c:	3c11800a */ 	lui	$s1,%hi(var8009c780)
/*     3230:	2631c780 */ 	addiu	$s1,$s1,%lo(var8009c780)
/*     3234:	2652c788 */ 	addiu	$s2,$s2,%lo(var8009c788)
/*     3238:	2673c78c */ 	addiu	$s3,$s3,%lo(var8009c78c)
/*     323c:	2415000d */ 	addiu	$s5,$zero,0xd
/*     3240:	27b40044 */ 	addiu	$s4,$sp,0x44
.L00003244:
/*     3244:	8ee4000c */ 	lw	$a0,0xc($s7)
.L00003248:
/*     3248:	02802825 */ 	or	$a1,$s4,$zero
/*     324c:	0c0121bc */ 	jal	osRecvMesg
/*     3250:	24060001 */ 	addiu	$a2,$zero,0x1
/*     3254:	8fae0044 */ 	lw	$t6,0x44($sp)
/*     3258:	95c30000 */ 	lhu	$v1,0x0($t6)
/*     325c:	10750005 */ 	beq	$v1,$s5,.L00003274
/*     3260:	00000000 */ 	nop
/*     3264:	1076002a */ 	beq	$v1,$s6,.L00003310
/*     3268:	00000000 */ 	nop
/*     326c:	1000fff6 */ 	b	.L00003248
/*     3270:	8ee4000c */ 	lw	$a0,0xc($s7)
.L00003274:
/*     3274:	0c0125e4 */ 	jal	__osViSwapContext
/*     3278:	00000000 */ 	nop
/*     327c:	3c038009 */ 	lui	$v1,%hi(var80090290)
/*     3280:	94630290 */ 	lhu	$v1,%lo(var80090290)($v1)
/*     3284:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     3288:	2463ffff */ 	addiu	$v1,$v1,-1
/*     328c:	306fffff */ 	andi	$t7,$v1,0xffff
/*     3290:	15e0000e */ 	bnez	$t7,.L000032cc
/*     3294:	a42f0290 */ 	sh	$t7,%lo(var80090290)($at)
/*     3298:	0c0125e0 */ 	jal	__osViGetCurrentContext
/*     329c:	00000000 */ 	nop
/*     32a0:	8c580010 */ 	lw	$t8,0x10($v0)
/*     32a4:	00408025 */ 	or	$s0,$v0,$zero
/*     32a8:	00003025 */ 	or	$a2,$zero,$zero
/*     32ac:	53000005 */ 	beqzl	$t8,.L000032c4
/*     32b0:	96030002 */ 	lhu	$v1,0x2($s0)
/*     32b4:	8c440010 */ 	lw	$a0,0x10($v0)
/*     32b8:	0c012238 */ 	jal	osSendMesg
/*     32bc:	8c450014 */ 	lw	$a1,0x14($v0)
/*     32c0:	96030002 */ 	lhu	$v1,0x2($s0)
.L000032c4:
/*     32c4:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     32c8:	a4230290 */ 	sh	$v1,%lo(var80090290)($at)
.L000032cc:
/*     32cc:	8e790000 */ 	lw	$t9,0x0($s3)
/*     32d0:	8e500000 */ 	lw	$s0,0x0($s2)
/*     32d4:	27280001 */ 	addiu	$t0,$t9,0x1
/*     32d8:	0c012144 */ 	jal	osGetCount
/*     32dc:	ae680000 */ 	sw	$t0,0x0($s3)
/*     32e0:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*     32e4:	00508023 */ 	subu	$s0,$v0,$s0
/*     32e8:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*     32ec:	020d7821 */ 	addu	$t7,$s0,$t5
/*     32f0:	240a0000 */ 	addiu	$t2,$zero,0x0
/*     32f4:	01ed082b */ 	sltu	$at,$t7,$t5
/*     32f8:	002a7021 */ 	addu	$t6,$at,$t2
/*     32fc:	01cc7021 */ 	addu	$t6,$t6,$t4
/*     3300:	ae420000 */ 	sw	$v0,0x0($s2)
/*     3304:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*     3308:	1000ffce */ 	b	.L00003244
/*     330c:	ae2f0004 */ 	sw	$t7,0x4($s1)
.L00003310:
/*     3310:	0c01248f */ 	jal	__osTimerInterrupt
/*     3314:	00000000 */ 	nop
/*     3318:	1000ffcb */ 	b	.L00003248
/*     331c:	8ee4000c */ 	lw	$a0,0xc($s7)
/*     3320:	00000000 */ 	nop
/*     3324:	00000000 */ 	nop
/*     3328:	00000000 */ 	nop
/*     332c:	00000000 */ 	nop
/*     3330:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     3334:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     3338:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     333c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     3340:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     3344:	8fb40024 */ 	lw	$s4,0x24($sp)
/*     3348:	8fb50028 */ 	lw	$s5,0x28($sp)
/*     334c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*     3350:	8fb70030 */ 	lw	$s7,0x30($sp)
/*     3354:	03e00008 */ 	jr	$ra
/*     3358:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*     335c:	00000000 */ 	nop
);
