#include <ultra64.h>
#include "lib/entry.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_074f0.h"
#include "lib/dma.h"
#include "lib/lib_48150.h"
#include "lib/lib_4d6f0.h"
#include "data.h"
#include "types.h"

u8 g_Is4Mb;
u32 var80090af4;
u32 var80090af8;
u32 var80090afc;
u32 var80090b00;
u32 var80090b04;
u32 var80090b08;
u32 var80090b0c;

u32 var8005cf80 = 0;
u32 var8005cf84 = 0;
u32 var8005cf88 = 0;

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func000070d0
/*     70d0:	27bdeb58 */ 	addiu	$sp,$sp,-5288
/*     70d4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*     70d8:	24100001 */ 	addiu	$s0,$zero,0x1
/*     70dc:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     70e0:	3c018009 */ 	lui	$at,%hi(var8008ae28)
/*     70e4:	afb70038 */ 	sw	$s7,0x38($sp)
/*     70e8:	afb60034 */ 	sw	$s6,0x34($sp)
/*     70ec:	afb50030 */ 	sw	$s5,0x30($sp)
/*     70f0:	afb4002c */ 	sw	$s4,0x2c($sp)
/*     70f4:	afb30028 */ 	sw	$s3,0x28($sp)
/*     70f8:	afb20024 */ 	sw	$s2,0x24($sp)
/*     70fc:	afb10020 */ 	sw	$s1,0x20($sp)
/*     7100:	0c00222c */ 	jal	func000088b0
/*     7104:	a030ae28 */ 	sb	$s0,%lo(var8008ae28)($at)
/*     7108:	0c0005b0 */ 	jal	initGetMemSize
/*     710c:	00000000 */ 	nop
/*     7110:	3c010040 */ 	lui	$at,0x40
/*     7114:	34210001 */ 	ori	$at,$at,0x1
/*     7118:	0041082a */ 	slt	$at,$v0,$at
/*     711c:	10200074 */ 	beqz	$at,.L000072f0
/*     7120:	3c087f1c */ 	lui	$t0,%hi(_gameSegmentEnd)
/*     7124:	3c087f1c */ 	lui	$t0,%hi(_gameSegmentEnd)
/*     7128:	3c097f00 */ 	lui	$t1,%hi(func0f000000)
/*     712c:	25290000 */ 	addiu	$t1,$t1,%lo(func0f000000)
/*     7130:	250899e0 */ 	addiu	$t0,$t0,%lo(_gameSegmentEnd)
/*     7134:	3c018009 */ 	lui	$at,%hi(g_Is4Mb)
/*     7138:	01097023 */ 	subu	$t6,$t0,$t1
/*     713c:	a0300af0 */ 	sb	$s0,%lo(g_Is4Mb)($at)
/*     7140:	25cf0fff */ 	addiu	$t7,$t6,0xfff
/*     7144:	3c178006 */ 	lui	$s7,%hi(var8005cf84)
/*     7148:	26f7cf84 */ 	addiu	$s7,$s7,%lo(var8005cf84)
/*     714c:	3c07803f */ 	lui	$a3,0x803f
/*     7150:	01091023 */ 	subu	$v0,$t0,$t1
/*     7154:	34e750b8 */ 	ori	$a3,$a3,0x50b8
/*     7158:	24420fff */ 	addiu	$v0,$v0,0xfff
/*     715c:	00027302 */ 	srl	$t6,$v0,0xc
/*     7160:	25c60002 */ 	addiu	$a2,$t6,0x2
/*     7164:	3c158009 */ 	lui	$s5,%hi(var8008ae30)
/*     7168:	25d60001 */ 	addiu	$s6,$t6,0x1
/*     716c:	3c120005 */ 	lui	$s2,%hi(_gamezipSegmentRomStart)
/*     7170:	26b5ae30 */ 	addiu	$s5,$s5,%lo(var8008ae30)
/*     7174:	05e10003 */ 	bgez	$t7,.L00007184
/*     7178:	000fc303 */ 	sra	$t8,$t7,0xc
/*     717c:	25e10fff */ 	addiu	$at,$t7,0xfff
/*     7180:	0001c303 */ 	sra	$t8,$at,0xc
.L00007184:
/*     7184:	3c017f00 */ 	lui	$at,0x7f00
/*     7188:	0018cb00 */ 	sll	$t9,$t8,0xc
/*     718c:	03216021 */ 	addu	$t4,$t9,$at
/*     7190:	aef80000 */ 	sw	$t8,0x0($s7)
/*     7194:	3c018009 */ 	lui	$at,%hi(var80090b04)
/*     7198:	ac2c0b04 */ 	sw	$t4,%lo(var80090b04)($at)
/*     719c:	3c018009 */ 	lui	$at,%hi(var80090b08)
/*     71a0:	001868c0 */ 	sll	$t5,$t8,0x3
/*     71a4:	ac270b08 */ 	sw	$a3,%lo(var80090b08)($at)
/*     71a8:	00ed9823 */ 	subu	$s3,$a3,$t5
/*     71ac:	3c018009 */ 	lui	$at,%hi(var8008ae24)
/*     71b0:	25cf0005 */ 	addiu	$t7,$t6,0x5
/*     71b4:	ac33ae24 */ 	sw	$s3,%lo(var8008ae24)($at)
/*     71b8:	000fc080 */ 	sll	$t8,$t7,0x2
/*     71bc:	00066880 */ 	sll	$t5,$a2,0x2
/*     71c0:	0278c823 */ 	subu	$t9,$s3,$t8
/*     71c4:	2401fff0 */ 	addiu	$at,$zero,-16
/*     71c8:	25a6000f */ 	addiu	$a2,$t5,0xf
/*     71cc:	03212024 */ 	and	$a0,$t9,$at
/*     71d0:	34ce000f */ 	ori	$t6,$a2,0xf
/*     71d4:	2652fc40 */ 	addiu	$s2,$s2,%lo(_gamezipSegmentRomStart)
/*     71d8:	02c0a025 */ 	or	$s4,$s6,$zero
/*     71dc:	aea40000 */ 	sw	$a0,0x0($s5)
/*     71e0:	02402825 */ 	or	$a1,$s2,$zero
/*     71e4:	0c003504 */ 	jal	dmaExec
/*     71e8:	39c6000f */ 	xori	$a2,$t6,0xf
/*     71ec:	240bfff0 */ 	addiu	$t3,$zero,-16
/*     71f0:	12c0000c */ 	beqz	$s6,.L00007224
/*     71f4:	00008025 */ 	or	$s0,$zero,$zero
/*     71f8:	00001825 */ 	or	$v1,$zero,$zero
.L000071fc:
/*     71fc:	8eb80000 */ 	lw	$t8,0x0($s5)
/*     7200:	26100001 */ 	addiu	$s0,$s0,0x1
/*     7204:	0214082b */ 	sltu	$at,$s0,$s4
/*     7208:	03031021 */ 	addu	$v0,$t8,$v1
/*     720c:	8c590000 */ 	lw	$t9,0x0($v0)
/*     7210:	24630004 */ 	addiu	$v1,$v1,0x4
/*     7214:	03326021 */ 	addu	$t4,$t9,$s2
/*     7218:	1420fff8 */ 	bnez	$at,.L000071fc
/*     721c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*     7220:	00008025 */ 	or	$s0,$zero,$zero
.L00007224:
/*     7224:	26cdffff */ 	addiu	$t5,$s6,-1
/*     7228:	11a0000e */ 	beqz	$t5,.L00007264
/*     722c:	00008825 */ 	or	$s1,$zero,$zero
/*     7230:	8ea20000 */ 	lw	$v0,0x0($s5)
/*     7234:	2684ffff */ 	addiu	$a0,$s4,-1
.L00007238:
/*     7238:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*     723c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*     7240:	26100001 */ 	addiu	$s0,$s0,0x1
/*     7244:	01cf1823 */ 	subu	$v1,$t6,$t7
/*     7248:	0223082b */ 	sltu	$at,$s1,$v1
/*     724c:	50200003 */ 	beqzl	$at,.L0000725c
/*     7250:	0204082b */ 	sltu	$at,$s0,$a0
/*     7254:	00608825 */ 	or	$s1,$v1,$zero
/*     7258:	0204082b */ 	sltu	$at,$s0,$a0
.L0000725c:
/*     725c:	1420fff6 */ 	bnez	$at,.L00007238
/*     7260:	24420004 */ 	addiu	$v0,$v0,0x4
.L00007264:
/*     7264:	8eb80000 */ 	lw	$t8,0x0($s5)
/*     7268:	26310040 */ 	addiu	$s1,$s1,0x40
/*     726c:	022b8824 */ 	and	$s1,$s1,$t3
/*     7270:	3c01ffef */ 	lui	$at,0xffef
/*     7274:	0311c823 */ 	subu	$t9,$t8,$s1
/*     7278:	032b6824 */ 	and	$t5,$t9,$t3
/*     727c:	34214000 */ 	ori	$at,$at,0x4000
/*     7280:	3c028009 */ 	lui	$v0,%hi(var8008ae2c)
/*     7284:	01a19821 */ 	addu	$s3,$t5,$at
/*     7288:	2442ae2c */ 	addiu	$v0,$v0,%lo(var8008ae2c)
/*     728c:	ac590000 */ 	sw	$t9,0x0($v0)
/*     7290:	326e1fff */ 	andi	$t6,$s3,0x1fff
/*     7294:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*     7298:	026e9823 */ 	subu	$s3,$s3,$t6
/*     729c:	3c018009 */ 	lui	$at,%hi(var8008ae20)
/*     72a0:	ac33ae20 */ 	sw	$s3,%lo(var8008ae20)($at)
/*     72a4:	3c018009 */ 	lui	$at,%hi(var80090b00)
/*     72a8:	0c000429 */ 	jal	boot000010a4
/*     72ac:	ac330b00 */ 	sw	$s3,%lo(var80090b00)($at)
/*     72b0:	8ee30000 */ 	lw	$v1,0x0($s7)
/*     72b4:	3c048009 */ 	lui	$a0,%hi(var8008ae24)
/*     72b8:	8c84ae24 */ 	lw	$a0,%lo(var8008ae24)($a0)
/*     72bc:	000378c0 */ 	sll	$t7,$v1,0x3
/*     72c0:	000f1883 */ 	sra	$v1,$t7,0x2
/*     72c4:	18600006 */ 	blez	$v1,.L000072e0
/*     72c8:	00008825 */ 	or	$s1,$zero,$zero
/*     72cc:	00801025 */ 	or	$v0,$a0,$zero
.L000072d0:
/*     72d0:	26310001 */ 	addiu	$s1,$s1,0x1
/*     72d4:	24420004 */ 	addiu	$v0,$v0,0x4
/*     72d8:	1623fffd */ 	bne	$s1,$v1,.L000072d0
/*     72dc:	ac40fffc */ 	sw	$zero,-0x4($v0)
.L000072e0:
/*     72e0:	0c00044f */ 	jal	boot0000113c
/*     72e4:	00000000 */ 	nop
/*     72e8:	1000006a */ 	b	.L00007494
/*     72ec:	00000000 */ 	nop
.L000072f0:
/*     72f0:	3c097f00 */ 	lui	$t1,%hi(func0f000000)
/*     72f4:	25290000 */ 	addiu	$t1,$t1,%lo(func0f000000)
/*     72f8:	250899e0 */ 	addiu	$t0,$t0,%lo(_gameSegmentEnd)
/*     72fc:	0109c823 */ 	subu	$t9,$t0,$t1
/*     7300:	272c003f */ 	addiu	$t4,$t9,0x3f
/*     7304:	01091023 */ 	subu	$v0,$t0,$t1
/*     7308:	3c0a803f */ 	lui	$t2,0x803f
/*     730c:	358d003f */ 	ori	$t5,$t4,0x3f
/*     7310:	24420fff */ 	addiu	$v0,$v0,0xfff
/*     7314:	355750b8 */ 	ori	$s7,$t2,0x50b8
/*     7318:	3c018009 */ 	lui	$at,%hi(g_Is4Mb)
/*     731c:	39ae003f */ 	xori	$t6,$t5,0x3f
/*     7320:	0002c302 */ 	srl	$t8,$v0,0xc
/*     7324:	a0200af0 */ 	sb	$zero,%lo(g_Is4Mb)($at)
/*     7328:	02ee3823 */ 	subu	$a3,$s7,$t6
/*     732c:	3c01fffe */ 	lui	$at,0xfffe
/*     7330:	27190005 */ 	addiu	$t9,$t8,0x5
/*     7334:	27060002 */ 	addiu	$a2,$t8,0x2
/*     7338:	00e19824 */ 	and	$s3,$a3,$at
/*     733c:	00067080 */ 	sll	$t6,$a2,0x2
/*     7340:	00196080 */ 	sll	$t4,$t9,0x2
/*     7344:	240bfff0 */ 	addiu	$t3,$zero,-16
/*     7348:	026c6823 */ 	subu	$t5,$s3,$t4
/*     734c:	25c6000f */ 	addiu	$a2,$t6,0xf
/*     7350:	3c120005 */ 	lui	$s2,%hi(_gamezipSegmentRomStart)
/*     7354:	3c018009 */ 	lui	$at,%hi(var80090b00)
/*     7358:	27160001 */ 	addiu	$s6,$t8,0x1
/*     735c:	2652fc40 */ 	addiu	$s2,$s2,%lo(_gamezipSegmentRomStart)
/*     7360:	34cf000f */ 	ori	$t7,$a2,0xf
/*     7364:	01aba824 */ 	and	$s5,$t5,$t3
/*     7368:	ac330b00 */ 	sw	$s3,%lo(var80090b00)($at)
/*     736c:	02a02025 */ 	or	$a0,$s5,$zero
/*     7370:	39e6000f */ 	xori	$a2,$t7,0xf
/*     7374:	02402825 */ 	or	$a1,$s2,$zero
/*     7378:	afb61474 */ 	sw	$s6,0x1474($sp)
/*     737c:	0c003504 */ 	jal	dmaExec
/*     7380:	afb30054 */ 	sw	$s3,0x54($sp)
/*     7384:	8fa31474 */ 	lw	$v1,0x1474($sp)
/*     7388:	12c0000b */ 	beqz	$s6,.L000073b8
/*     738c:	00008025 */ 	or	$s0,$zero,$zero
/*     7390:	00008825 */ 	or	$s1,$zero,$zero
.L00007394:
/*     7394:	02b11021 */ 	addu	$v0,$s5,$s1
/*     7398:	8c590000 */ 	lw	$t9,0x0($v0)
/*     739c:	26100001 */ 	addiu	$s0,$s0,0x1
/*     73a0:	0203082b */ 	sltu	$at,$s0,$v1
/*     73a4:	03326021 */ 	addu	$t4,$t9,$s2
/*     73a8:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*     73ac:	1420fff9 */ 	bnez	$at,.L00007394
/*     73b0:	26310004 */ 	addiu	$s1,$s1,0x4
/*     73b4:	00008025 */ 	or	$s0,$zero,$zero
.L000073b8:
/*     73b8:	26cdffff */ 	addiu	$t5,$s6,-1
/*     73bc:	11a00018 */ 	beqz	$t5,.L00007420
/*     73c0:	8fb20054 */ 	lw	$s2,0x54($sp)
/*     73c4:	26b4e000 */ 	addiu	$s4,$s5,-8192
/*     73c8:	268e0002 */ 	addiu	$t6,$s4,0x2
/*     73cc:	afae0048 */ 	sw	$t6,0x48($sp)
/*     73d0:	00008825 */ 	or	$s1,$zero,$zero
/*     73d4:	2476ffff */ 	addiu	$s6,$v1,-1
.L000073d8:
/*     73d8:	02b11021 */ 	addu	$v0,$s5,$s1
/*     73dc:	8c450000 */ 	lw	$a1,0x0($v0)
/*     73e0:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*     73e4:	02802025 */ 	or	$a0,$s4,$zero
/*     73e8:	01e53023 */ 	subu	$a2,$t7,$a1
/*     73ec:	24c6000f */ 	addiu	$a2,$a2,0xf
/*     73f0:	34d8000f */ 	ori	$t8,$a2,0xf
/*     73f4:	0c003504 */ 	jal	dmaExec
/*     73f8:	3b06000f */ 	xori	$a2,$t8,0xf
/*     73fc:	8fa40048 */ 	lw	$a0,0x48($sp)
/*     7400:	02402825 */ 	or	$a1,$s2,$zero
/*     7404:	0c001d3c */ 	jal	rzipInflate
/*     7408:	27a60068 */ 	addiu	$a2,$sp,0x68
/*     740c:	26100001 */ 	addiu	$s0,$s0,0x1
/*     7410:	0216082b */ 	sltu	$at,$s0,$s6
/*     7414:	02429021 */ 	addu	$s2,$s2,$v0
/*     7418:	1420ffef */ 	bnez	$at,.L000073d8
/*     741c:	26310004 */ 	addiu	$s1,$s1,0x4
.L00007420:
/*     7420:	8fac0054 */ 	lw	$t4,0x54($sp)
/*     7424:	3c01803f */ 	lui	$at,0x803f
/*     7428:	342150b9 */ 	ori	$at,$at,0x50b9
/*     742c:	0181082b */ 	sltu	$at,$t4,$at
/*     7430:	3c117f00 */ 	lui	$s1,0x7f00
/*     7434:	10200017 */ 	beqz	$at,.L00007494
/*     7438:	24100002 */ 	addiu	$s0,$zero,0x2
/*     743c:	3c160001 */ 	lui	$s6,0x1
/*     7440:	36d6e000 */ 	ori	$s6,$s6,0xe000
/*     7444:	3c150001 */ 	lui	$s5,0x1
/*     7448:	3c140002 */ 	lui	$s4,0x2
.L0000744c:
/*     744c:	0c012d20 */ 	jal	osVirtualToPhysical
/*     7450:	02602025 */ 	or	$a0,$s3,$zero
/*     7454:	00409025 */ 	or	$s2,$v0,$zero
/*     7458:	0c012d20 */ 	jal	osVirtualToPhysical
/*     745c:	02752021 */ 	addu	$a0,$s3,$s5
/*     7460:	240dffff */ 	addiu	$t5,$zero,-1
/*     7464:	afad0014 */ 	sw	$t5,0x14($sp)
/*     7468:	02002025 */ 	or	$a0,$s0,$zero
/*     746c:	02c02825 */ 	or	$a1,$s6,$zero
/*     7470:	02203025 */ 	or	$a2,$s1,$zero
/*     7474:	02403825 */ 	or	$a3,$s2,$zero
/*     7478:	0c01386c */ 	jal	osMapTLB
/*     747c:	afa20010 */ 	sw	$v0,0x10($sp)
/*     7480:	02749821 */ 	addu	$s3,$s3,$s4
/*     7484:	02f3082b */ 	sltu	$at,$s7,$s3
/*     7488:	02348821 */ 	addu	$s1,$s1,$s4
/*     748c:	1020ffef */ 	beqz	$at,.L0000744c
/*     7490:	26100001 */ 	addiu	$s0,$s0,0x1
.L00007494:
/*     7494:	3c018009 */ 	lui	$at,%hi(var80090af4)
/*     7498:	ac200af4 */ 	sw	$zero,%lo(var80090af4)($at)
/*     749c:	3c018009 */ 	lui	$at,%hi(var80090af8)
/*     74a0:	ac200af8 */ 	sw	$zero,%lo(var80090af8)($at)
/*     74a4:	3c018009 */ 	lui	$at,%hi(var80090afc)
/*     74a8:	ac200afc */ 	sw	$zero,%lo(var80090afc)($at)
/*     74ac:	00002025 */ 	or	$a0,$zero,$zero
/*     74b0:	0c012054 */ 	jal	osInvalICache
/*     74b4:	24054000 */ 	addiu	$a1,$zero,0x4000
/*     74b8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     74bc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*     74c0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*     74c4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*     74c8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*     74cc:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*     74d0:	8fb50030 */ 	lw	$s5,0x30($sp)
/*     74d4:	8fb60034 */ 	lw	$s6,0x34($sp)
/*     74d8:	8fb70038 */ 	lw	$s7,0x38($sp)
/*     74dc:	03e00008 */ 	jr	$ra
/*     74e0:	27bd14a8 */ 	addiu	$sp,$sp,0x14a8
);
#else
GLOBAL_ASM(
glabel func000070d0
/*     71b0:	27bdea98 */ 	addiu	$sp,$sp,-5480
/*     71b4:	afb00054 */ 	sw	$s0,0x54($sp)
/*     71b8:	24100001 */ 	addiu	$s0,$zero,0x1
/*     71bc:	afbf0074 */ 	sw	$ra,0x74($sp)
/*     71c0:	3c018009 */ 	lui	$at,0x8009
/*     71c4:	afb70070 */ 	sw	$s7,0x70($sp)
/*     71c8:	afb6006c */ 	sw	$s6,0x6c($sp)
/*     71cc:	afb50068 */ 	sw	$s5,0x68($sp)
/*     71d0:	afb40064 */ 	sw	$s4,0x64($sp)
/*     71d4:	afb30060 */ 	sw	$s3,0x60($sp)
/*     71d8:	afb2005c */ 	sw	$s2,0x5c($sp)
/*     71dc:	afb10058 */ 	sw	$s1,0x58($sp)
/*     71e0:	0c002294 */ 	jal	func000088b0
/*     71e4:	a030d458 */ 	sb	$s0,-0x2ba8($at)
/*     71e8:	0c013d4c */ 	jal	osGetMemSize
/*     71ec:	00000000 */ 	sll	$zero,$zero,0x0
/*     71f0:	3c010040 */ 	lui	$at,0x40
/*     71f4:	34210001 */ 	ori	$at,$at,0x1
/*     71f8:	0041082b */ 	sltu	$at,$v0,$at
/*     71fc:	10200074 */ 	beqz	$at,.NB000073d0
/*     7200:	3c077f1b */ 	lui	$a3,0x7f1b
/*     7204:	3c077f1b */ 	lui	$a3,0x7f1b
/*     7208:	3c087f00 */ 	lui	$t0,0x7f00
/*     720c:	25080000 */ 	addiu	$t0,$t0,0x0
/*     7210:	24e74000 */ 	addiu	$a3,$a3,0x4000
/*     7214:	3c018009 */ 	lui	$at,0x8009
/*     7218:	00e87023 */ 	subu	$t6,$a3,$t0
/*     721c:	a03030e0 */ 	sb	$s0,0x30e0($at)
/*     7220:	25cf0fff */ 	addiu	$t7,$t6,0xfff
/*     7224:	3c178006 */ 	lui	$s7,0x8006
/*     7228:	26f7e720 */ 	addiu	$s7,$s7,-6368
/*     722c:	00e81023 */ 	subu	$v0,$a3,$t0
/*     7230:	3c09803f */ 	lui	$t1,0x803f
/*     7234:	24420fff */ 	addiu	$v0,$v0,0xfff
/*     7238:	352950c0 */ 	ori	$t1,$t1,0x50c0
/*     723c:	00026b02 */ 	srl	$t5,$v0,0xc
/*     7240:	25ae0005 */ 	addiu	$t6,$t5,0x5
/*     7244:	25a60002 */ 	addiu	$a2,$t5,0x2
/*     7248:	3c148009 */ 	lui	$s4,0x8009
/*     724c:	3c130004 */ 	lui	$s3,0x4
/*     7250:	2694d460 */ 	addiu	$s4,$s4,-11168
/*     7254:	05e10003 */ 	bgez	$t7,.NB00007264
/*     7258:	000fc303 */ 	sra	$t8,$t7,0xc
/*     725c:	25e10fff */ 	addiu	$at,$t7,0xfff
/*     7260:	0001c303 */ 	sra	$t8,$at,0xc
.NB00007264:
/*     7264:	3c017f00 */ 	lui	$at,0x7f00
/*     7268:	0018cb00 */ 	sll	$t9,$t8,0xc
/*     726c:	03215821 */ 	addu	$t3,$t9,$at
/*     7270:	aef80000 */ 	sw	$t8,0x0($s7)
/*     7274:	3c018009 */ 	lui	$at,0x8009
/*     7278:	ac2b30f4 */ 	sw	$t3,0x30f4($at)
/*     727c:	3c018009 */ 	lui	$at,0x8009
/*     7280:	ac2930f8 */ 	sw	$t1,0x30f8($at)
/*     7284:	001860c0 */ 	sll	$t4,$t8,0x3
/*     7288:	012ca823 */ 	subu	$s5,$t1,$t4
/*     728c:	3c018009 */ 	lui	$at,0x8009
/*     7290:	ac35d454 */ 	sw	$s5,-0x2bac($at)
/*     7294:	000e7880 */ 	sll	$t7,$t6,0x2
/*     7298:	00065880 */ 	sll	$t3,$a2,0x2
/*     729c:	02afc023 */ 	subu	$t8,$s5,$t7
/*     72a0:	2401fff0 */ 	addiu	$at,$zero,-16
/*     72a4:	2566000f */ 	addiu	$a2,$t3,0xf
/*     72a8:	25b60001 */ 	addiu	$s6,$t5,0x1
/*     72ac:	03012024 */ 	and	$a0,$t8,$at
/*     72b0:	34cc000f */ 	ori	$t4,$a2,0xf
/*     72b4:	26733c40 */ 	addiu	$s3,$s3,0x3c40
/*     72b8:	02c09025 */ 	or	$s2,$s6,$zero
/*     72bc:	ae840000 */ 	sw	$a0,0x0($s4)
/*     72c0:	02602825 */ 	or	$a1,$s3,$zero
/*     72c4:	0c003664 */ 	jal	dmaExec
/*     72c8:	3986000f */ 	xori	$a2,$t4,0xf
/*     72cc:	240afff0 */ 	addiu	$t2,$zero,-16
/*     72d0:	12c0000c */ 	beqz	$s6,.NB00007304
/*     72d4:	00008025 */ 	or	$s0,$zero,$zero
/*     72d8:	00001825 */ 	or	$v1,$zero,$zero
.NB000072dc:
/*     72dc:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*     72e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*     72e4:	0212082b */ 	sltu	$at,$s0,$s2
/*     72e8:	01c31021 */ 	addu	$v0,$t6,$v1
/*     72ec:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*     72f0:	24630004 */ 	addiu	$v1,$v1,0x4
/*     72f4:	01f3c021 */ 	addu	$t8,$t7,$s3
/*     72f8:	1420fff8 */ 	bnez	$at,.NB000072dc
/*     72fc:	ac580000 */ 	sw	$t8,0x0($v0)
/*     7300:	00008025 */ 	or	$s0,$zero,$zero
.NB00007304:
/*     7304:	26d9ffff */ 	addiu	$t9,$s6,-1
/*     7308:	1320000e */ 	beqz	$t9,.NB00007344
/*     730c:	00008825 */ 	or	$s1,$zero,$zero
/*     7310:	8e820000 */ 	lw	$v0,0x0($s4)
/*     7314:	2644ffff */ 	addiu	$a0,$s2,-1
.NB00007318:
/*     7318:	8c4b0004 */ 	lw	$t3,0x4($v0)
/*     731c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*     7320:	26100001 */ 	addiu	$s0,$s0,0x1
/*     7324:	016c1823 */ 	subu	$v1,$t3,$t4
/*     7328:	0223082b */ 	sltu	$at,$s1,$v1
/*     732c:	50200003 */ 	beqzl	$at,.NB0000733c
/*     7330:	0204082b */ 	sltu	$at,$s0,$a0
/*     7334:	00608825 */ 	or	$s1,$v1,$zero
/*     7338:	0204082b */ 	sltu	$at,$s0,$a0
.NB0000733c:
/*     733c:	1420fff6 */ 	bnez	$at,.NB00007318
/*     7340:	24420004 */ 	addiu	$v0,$v0,0x4
.NB00007344:
/*     7344:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*     7348:	26310040 */ 	addiu	$s1,$s1,0x40
/*     734c:	022a8824 */ 	and	$s1,$s1,$t2
/*     7350:	3c01ffef */ 	lui	$at,0xffef
/*     7354:	01b17023 */ 	subu	$t6,$t5,$s1
/*     7358:	01cac024 */ 	and	$t8,$t6,$t2
/*     735c:	34216000 */ 	ori	$at,$at,0x6000
/*     7360:	3c028009 */ 	lui	$v0,0x8009
/*     7364:	0301a821 */ 	addu	$s5,$t8,$at
/*     7368:	2442d45c */ 	addiu	$v0,$v0,-11172
/*     736c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*     7370:	32b91fff */ 	andi	$t9,$s5,0x1fff
/*     7374:	ac580000 */ 	sw	$t8,0x0($v0)
/*     7378:	02b9a823 */ 	subu	$s5,$s5,$t9
/*     737c:	3c018009 */ 	lui	$at,0x8009
/*     7380:	ac35d450 */ 	sw	$s5,-0x2bb0($at)
/*     7384:	3c018009 */ 	lui	$at,0x8009
/*     7388:	0c000429 */ 	jal	boot000010a4
/*     738c:	ac3530f0 */ 	sw	$s5,0x30f0($at)
/*     7390:	8ee30000 */ 	lw	$v1,0x0($s7)
/*     7394:	3c048009 */ 	lui	$a0,0x8009
/*     7398:	8c84d454 */ 	lw	$a0,-0x2bac($a0)
/*     739c:	000358c0 */ 	sll	$t3,$v1,0x3
/*     73a0:	000b1883 */ 	sra	$v1,$t3,0x2
/*     73a4:	18600006 */ 	blez	$v1,.NB000073c0
/*     73a8:	00008825 */ 	or	$s1,$zero,$zero
/*     73ac:	00801025 */ 	or	$v0,$a0,$zero
.NB000073b0:
/*     73b0:	26310001 */ 	addiu	$s1,$s1,0x1
/*     73b4:	24420004 */ 	addiu	$v0,$v0,0x4
/*     73b8:	1623fffd */ 	bne	$s1,$v1,.NB000073b0
/*     73bc:	ac40fffc */ 	sw	$zero,-0x4($v0)
.NB000073c0:
/*     73c0:	0c00044f */ 	jal	boot0000113c
/*     73c4:	00000000 */ 	sll	$zero,$zero,0x0
/*     73c8:	1000009b */ 	beqz	$zero,.NB00007638
/*     73cc:	00000000 */ 	sll	$zero,$zero,0x0
.NB000073d0:
/*     73d0:	3c087f00 */ 	lui	$t0,0x7f00
/*     73d4:	25080000 */ 	addiu	$t0,$t0,0x0
/*     73d8:	24e74000 */ 	addiu	$a3,$a3,0x4000
/*     73dc:	00e86823 */ 	subu	$t5,$a3,$t0
/*     73e0:	00e81023 */ 	subu	$v0,$a3,$t0
/*     73e4:	25ae003f */ 	addiu	$t6,$t5,0x3f
/*     73e8:	24420fff */ 	addiu	$v0,$v0,0xfff
/*     73ec:	3c09803f */ 	lui	$t1,0x803f
/*     73f0:	3c018009 */ 	lui	$at,0x8009
/*     73f4:	35cf003f */ 	ori	$t7,$t6,0x3f
/*     73f8:	00025b02 */ 	srl	$t3,$v0,0xc
/*     73fc:	352950c0 */ 	ori	$t1,$t1,0x50c0
/*     7400:	a02030e0 */ 	sb	$zero,0x30e0($at)
/*     7404:	39f8003f */ 	xori	$t8,$t7,0x3f
/*     7408:	01381823 */ 	subu	$v1,$t1,$t8
/*     740c:	3c01fffe */ 	lui	$at,0xfffe
/*     7410:	256c0005 */ 	addiu	$t4,$t3,0x5
/*     7414:	25660002 */ 	addiu	$a2,$t3,0x2
/*     7418:	0061a824 */ 	and	$s5,$v1,$at
/*     741c:	00067880 */ 	sll	$t7,$a2,0x2
/*     7420:	000c6880 */ 	sll	$t5,$t4,0x2
/*     7424:	240afff0 */ 	addiu	$t2,$zero,-16
/*     7428:	02ad7023 */ 	subu	$t6,$s5,$t5
/*     742c:	25e6000f */ 	addiu	$a2,$t7,0xf
/*     7430:	3c130004 */ 	lui	$s3,0x4
/*     7434:	3c018009 */ 	lui	$at,0x8009
/*     7438:	25760001 */ 	addiu	$s6,$t3,0x1
/*     743c:	26733c40 */ 	addiu	$s3,$s3,0x3c40
/*     7440:	34d8000f */ 	ori	$t8,$a2,0xf
/*     7444:	01cab824 */ 	and	$s7,$t6,$t2
/*     7448:	afa9154c */ 	sw	$t1,0x154c($sp)
/*     744c:	ac3530f0 */ 	sw	$s5,0x30f0($at)
/*     7450:	02c0a025 */ 	or	$s4,$s6,$zero
/*     7454:	02e02025 */ 	or	$a0,$s7,$zero
/*     7458:	3b06000f */ 	xori	$a2,$t8,0xf
/*     745c:	02602825 */ 	or	$a1,$s3,$zero
/*     7460:	0c003664 */ 	jal	dmaExec
/*     7464:	afb5008c */ 	sw	$s5,0x8c($sp)
/*     7468:	12c0000b */ 	beqz	$s6,.NB00007498
/*     746c:	00008825 */ 	or	$s1,$zero,$zero
/*     7470:	00009025 */ 	or	$s2,$zero,$zero
.NB00007474:
/*     7474:	02f21021 */ 	addu	$v0,$s7,$s2
/*     7478:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*     747c:	26310001 */ 	addiu	$s1,$s1,0x1
/*     7480:	0234082b */ 	sltu	$at,$s1,$s4
/*     7484:	01736021 */ 	addu	$t4,$t3,$s3
/*     7488:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*     748c:	1420fff9 */ 	bnez	$at,.NB00007474
/*     7490:	26520004 */ 	addiu	$s2,$s2,0x4
/*     7494:	00008825 */ 	or	$s1,$zero,$zero
.NB00007498:
/*     7498:	26cdffff */ 	addiu	$t5,$s6,-1
/*     749c:	11a00048 */ 	beqz	$t5,.NB000075c0
/*     74a0:	8fb3008c */ 	lw	$s3,0x8c($sp)
/*     74a4:	26f0e000 */ 	addiu	$s0,$s7,-8192
/*     74a8:	260f0002 */ 	addiu	$t7,$s0,0x2
/*     74ac:	268effff */ 	addiu	$t6,$s4,-1
/*     74b0:	afae0090 */ 	sw	$t6,0x90($sp)
/*     74b4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*     74b8:	00009025 */ 	or	$s2,$zero,$zero
/*     74bc:	27b600a8 */ 	addiu	$s6,$sp,0xa8
.NB000074c0:
/*     74c0:	02f21021 */ 	addu	$v0,$s7,$s2
/*     74c4:	8c450000 */ 	lw	$a1,0x0($v0)
/*     74c8:	8c580004 */ 	lw	$t8,0x4($v0)
/*     74cc:	02002025 */ 	or	$a0,$s0,$zero
/*     74d0:	03053023 */ 	subu	$a2,$t8,$a1
/*     74d4:	24c6000f */ 	addiu	$a2,$a2,0xf
/*     74d8:	34d9000f */ 	ori	$t9,$a2,0xf
/*     74dc:	0c003664 */ 	jal	dmaExec
/*     74e0:	3b26000f */ 	xori	$a2,$t9,0xf
/*     74e4:	8fa40080 */ 	lw	$a0,0x80($sp)
/*     74e8:	02602825 */ 	or	$a1,$s3,$zero
/*     74ec:	0c001da4 */ 	jal	rzipInflate
/*     74f0:	27a60128 */ 	addiu	$a2,$sp,0x128
/*     74f4:	1440002c */ 	bnez	$v0,.NB000075a8
/*     74f8:	0040a025 */ 	or	$s4,$v0,$zero
/*     74fc:	920c0000 */ 	lbu	$t4,0x0($s0)
/*     7500:	3c057005 */ 	lui	$a1,0x7005
/*     7504:	3c067005 */ 	lui	$a2,0x7005
/*     7508:	afac0010 */ 	sw	$t4,0x10($sp)
/*     750c:	920d0001 */ 	lbu	$t5,0x1($s0)
/*     7510:	24c63b48 */ 	addiu	$a2,$a2,0x3b48
/*     7514:	24a53af0 */ 	addiu	$a1,$a1,0x3af0
/*     7518:	afad0014 */ 	sw	$t5,0x14($sp)
/*     751c:	920e0002 */ 	lbu	$t6,0x2($s0)
/*     7520:	02c02025 */ 	or	$a0,$s6,$zero
/*     7524:	2407012a */ 	addiu	$a3,$zero,0x12a
/*     7528:	afae0018 */ 	sw	$t6,0x18($sp)
/*     752c:	920f0003 */ 	lbu	$t7,0x3($s0)
/*     7530:	afaf001c */ 	sw	$t7,0x1c($sp)
/*     7534:	92180004 */ 	lbu	$t8,0x4($s0)
/*     7538:	afb80020 */ 	sw	$t8,0x20($sp)
/*     753c:	92190005 */ 	lbu	$t9,0x5($s0)
/*     7540:	afb90024 */ 	sw	$t9,0x24($sp)
/*     7544:	920b0006 */ 	lbu	$t3,0x6($s0)
/*     7548:	afab0028 */ 	sw	$t3,0x28($sp)
/*     754c:	920c0007 */ 	lbu	$t4,0x7($s0)
/*     7550:	afac002c */ 	sw	$t4,0x2c($sp)
/*     7554:	920d0008 */ 	lbu	$t5,0x8($s0)
/*     7558:	afad0030 */ 	sw	$t5,0x30($sp)
/*     755c:	920e0009 */ 	lbu	$t6,0x9($s0)
/*     7560:	afae0034 */ 	sw	$t6,0x34($sp)
/*     7564:	920f000a */ 	lbu	$t7,0xa($s0)
/*     7568:	afaf0038 */ 	sw	$t7,0x38($sp)
/*     756c:	9218000b */ 	lbu	$t8,0xb($s0)
/*     7570:	afb8003c */ 	sw	$t8,0x3c($sp)
/*     7574:	9219000c */ 	lbu	$t9,0xc($s0)
/*     7578:	afb90040 */ 	sw	$t9,0x40($sp)
/*     757c:	920b000d */ 	lbu	$t3,0xd($s0)
/*     7580:	afab0044 */ 	sw	$t3,0x44($sp)
/*     7584:	920c000e */ 	lbu	$t4,0xe($s0)
/*     7588:	afac0048 */ 	sw	$t4,0x48($sp)
/*     758c:	920d000f */ 	lbu	$t5,0xf($s0)
/*     7590:	0c004fc1 */ 	jal	sprintf
/*     7594:	afad004c */ 	sw	$t5,0x4c($sp)
/*     7598:	0c003074 */ 	jal	func0000c1d0nb
/*     759c:	02c02025 */ 	or	$a0,$s6,$zero
/*     75a0:	240e0045 */ 	addiu	$t6,$zero,0x45
/*     75a4:	a00e0000 */ 	sb	$t6,0x0($zero)
.NB000075a8:
/*     75a8:	8faf0090 */ 	lw	$t7,0x90($sp)
/*     75ac:	26310001 */ 	addiu	$s1,$s1,0x1
/*     75b0:	02749821 */ 	addu	$s3,$s3,$s4
/*     75b4:	022f082b */ 	sltu	$at,$s1,$t7
/*     75b8:	1420ffc1 */ 	bnez	$at,.NB000074c0
/*     75bc:	26520004 */ 	addiu	$s2,$s2,0x4
.NB000075c0:
/*     75c0:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*     75c4:	3c01803f */ 	lui	$at,0x803f
/*     75c8:	342150c1 */ 	ori	$at,$at,0x50c1
/*     75cc:	0301082b */ 	sltu	$at,$t8,$at
/*     75d0:	3c117f00 */ 	lui	$s1,0x7f00
/*     75d4:	10200018 */ 	beqz	$at,.NB00007638
/*     75d8:	24100002 */ 	addiu	$s0,$zero,0x2
/*     75dc:	3c160001 */ 	lui	$s6,0x1
/*     75e0:	36d6e000 */ 	ori	$s6,$s6,0xe000
/*     75e4:	3c140001 */ 	lui	$s4,0x1
/*     75e8:	3c130002 */ 	lui	$s3,0x2
.NB000075ec:
/*     75ec:	0c013100 */ 	jal	osVirtualToPhysical
/*     75f0:	02a02025 */ 	or	$a0,$s5,$zero
/*     75f4:	00409025 */ 	or	$s2,$v0,$zero
/*     75f8:	0c013100 */ 	jal	osVirtualToPhysical
/*     75fc:	02b42021 */ 	addu	$a0,$s5,$s4
/*     7600:	2419ffff */ 	addiu	$t9,$zero,-1
/*     7604:	afb90014 */ 	sw	$t9,0x14($sp)
/*     7608:	02002025 */ 	or	$a0,$s0,$zero
/*     760c:	02c02825 */ 	or	$a1,$s6,$zero
/*     7610:	02203025 */ 	or	$a2,$s1,$zero
/*     7614:	02403825 */ 	or	$a3,$s2,$zero
/*     7618:	0c013d94 */ 	jal	osMapTLB
/*     761c:	afa20010 */ 	sw	$v0,0x10($sp)
/*     7620:	8fab154c */ 	lw	$t3,0x154c($sp)
/*     7624:	02b3a821 */ 	addu	$s5,$s5,$s3
/*     7628:	02338821 */ 	addu	$s1,$s1,$s3
/*     762c:	0175082b */ 	sltu	$at,$t3,$s5
/*     7630:	1020ffee */ 	beqz	$at,.NB000075ec
/*     7634:	26100001 */ 	addiu	$s0,$s0,0x1
.NB00007638:
/*     7638:	3c018009 */ 	lui	$at,0x8009
/*     763c:	ac2030e4 */ 	sw	$zero,0x30e4($at)
/*     7640:	3c018009 */ 	lui	$at,0x8009
/*     7644:	ac2030e8 */ 	sw	$zero,0x30e8($at)
/*     7648:	3c018009 */ 	lui	$at,0x8009
/*     764c:	ac2030ec */ 	sw	$zero,0x30ec($at)
/*     7650:	00002025 */ 	or	$a0,$zero,$zero
/*     7654:	0c012548 */ 	jal	osInvalICache
/*     7658:	24054000 */ 	addiu	$a1,$zero,0x4000
/*     765c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*     7660:	8fb00054 */ 	lw	$s0,0x54($sp)
/*     7664:	8fb10058 */ 	lw	$s1,0x58($sp)
/*     7668:	8fb2005c */ 	lw	$s2,0x5c($sp)
/*     766c:	8fb30060 */ 	lw	$s3,0x60($sp)
/*     7670:	8fb40064 */ 	lw	$s4,0x64($sp)
/*     7674:	8fb50068 */ 	lw	$s5,0x68($sp)
/*     7678:	8fb6006c */ 	lw	$s6,0x6c($sp)
/*     767c:	8fb70070 */ 	lw	$s7,0x70($sp)
/*     7680:	03e00008 */ 	jr	$ra
/*     7684:	27bd1568 */ 	addiu	$sp,$sp,0x1568
);
#endif
