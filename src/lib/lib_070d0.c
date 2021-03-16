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
/*     7108:	0c0005b0 */ 	jal	osGetMemSize
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
/*     74e4:	00000000 */ 	nop
/*     74e8:	00000000 */ 	nop
/*     74ec:	00000000 */ 	nop
);
