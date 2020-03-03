#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_0b2150.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "types.h"

const char var7f1aceb0[] = "MOT : Type 1  = %d/%d (%d)";
const char var7f1acecc[] = "MOT : Type 2  = %d/%d (%d)";
const char var7f1acee8[] = "MOT : Type 3  = %d/%d (%d)";
const char var7f1acf04[] = "MOT : Type OI = %d/%d/%d/%d";
const char var7f1acf20[] = "MOT : Type OA = %d/%d/%d/%d";
const char var7f1acf3c[] = "MOT : g_ObjCount = %d";
const char var7f1acf54[] = "MOT : g_AnimCount = %d";
const char var7f1acf6c[] = "Allocating %d bytes for objinst structure\n";
const char var7f1acf98[] = "MotInst: Using cache entry type 1 %d (0x%08x) - Bytes=%d\n";
const char var7f1acfd4[] = "MotInst: Using cache entry type 2 %d (0x%08x) - Bytes=%d\n";
const char var7f1ad010[] = "MotInst: Using cache entry type 3 %d (0x%08x) - Bytes=%d\n";
const char var7f1ad04c[] = "***************************************\n";
const char var7f1ad078[] = "***************************************\n";
const char var7f1ad0a4[] = "\nMotInst: Freeing type 2 cache entry %d (0x%08x)\n\n";
const char var7f1ad0d8[] = "\nMotInst: Freeing type 3 cache entry %d (0x%08x)\n\n";
const char var7f1ad10c[] = "MotInst -> Attempt to free item not in cache\n";

GLOBAL_ASM(
glabel func0f0b2150
/*  f0b2150:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0b2154:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b2158:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0b215c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0b2160:	44800000 */ 	mtc1	$zero,$f0
/*  f0b2164:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0b2168:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0b216c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2170:	4502015c */ 	bc1fl	.L0f0b26e4
/*  f0b2174:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b2178:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f0b217c:	3c014080 */ 	lui	$at,0x4080
/*  f0b2180:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0b2184:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0b2188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b218c:	45020155 */ 	bc1fl	.L0f0b26e4
/*  f0b2190:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b2194:	8c850000 */ 	lw	$a1,0x0($a0)
/*  f0b2198:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0b219c:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f0b21a0:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0b21a4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0b21a8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0b21ac:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f0b21b0:	c4c00000 */ 	lwc1	$f0,0x0($a2)
/*  f0b21b4:	44818000 */ 	mtc1	$at,$f16
/*  f0b21b8:	c70c0000 */ 	lwc1	$f12,0x0($t8)
/*  f0b21bc:	c4c20004 */ 	lwc1	$f2,0x4($a2)
/*  f0b21c0:	c70e0004 */ 	lwc1	$f14,0x4($t8)
/*  f0b21c4:	46006201 */ 	sub.s	$f8,$f12,$f0
/*  f0b21c8:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0b21cc:	00004025 */ 	or	$t0,$zero,$zero
/*  f0b21d0:	46027101 */ 	sub.s	$f4,$f14,$f2
/*  f0b21d4:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f0b21d8:	00004825 */ 	or	$t1,$zero,$zero
/*  f0b21dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b21e0:	46102182 */ 	mul.s	$f6,$f4,$f16
/*  f0b21e4:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b21e8:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0b21ec:	460c0280 */ 	add.s	$f10,$f0,$f12
/*  f0b21f0:	440a9000 */ 	mfc1	$t2,$f18
/*  f0b21f4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0b21f8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0b21fc:	460e1180 */ 	add.s	$f6,$f2,$f14
/*  f0b2200:	440b4000 */ 	mfc1	$t3,$f8
/*  f0b2204:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0b2208:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0b220c:	440c2000 */ 	mfc1	$t4,$f4
/*  f0b2210:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0b2214:	440d5000 */ 	mfc1	$t5,$f10
/*  f0b2218:	13000007 */ 	beqz	$t8,.L0f0b2238
/*  f0b221c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2220:	31420003 */ 	andi	$v0,$t2,0x3
/*  f0b2224:	31630003 */ 	andi	$v1,$t3,0x3
/*  f0b2228:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b222c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0b2230:	01425023 */ 	subu	$t2,$t2,$v0
/*  f0b2234:	01635823 */ 	subu	$t3,$t3,$v1
.L0f0b2238:
/*  f0b2238:	05820121 */ 	bltzl	$t4,.L0f0b26c0
/*  f0b223c:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0b2240:	05a0011e */ 	bltz	$t5,.L0f0b26bc
/*  f0b2244:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0b2248:	11c0000a */ 	beqz	$t6,.L0f0b2274
/*  f0b224c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2250:	8fbf0060 */ 	lw	$ra,0x60($sp)
/*  f0b2254:	00077840 */ 	sll	$t7,$a3,0x1
/*  f0b2258:	000f4100 */ 	sll	$t0,$t7,0x4
/*  f0b225c:	001fc840 */ 	sll	$t9,$ra,0x1
/*  f0b2260:	00194900 */ 	sll	$t1,$t9,0x4
/*  f0b2264:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0b2268:	00084023 */ 	negu	$t0,$t0
/*  f0b226c:	00094823 */ 	negu	$t1,$t1
/*  f0b2270:	afb90060 */ 	sw	$t9,0x60($sp)
.L0f0b2274:
/*  f0b2274:	0541002b */ 	bgez	$t2,.L0f0b2324
/*  f0b2278:	8fbf0060 */ 	lw	$ra,0x60($sp)
/*  f0b227c:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f0b2280:	000a7023 */ 	negu	$t6,$t2
/*  f0b2284:	000a7823 */ 	negu	$t7,$t2
/*  f0b2288:	13000014 */ 	beqz	$t8,.L0f0b22dc
/*  f0b228c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2290:	01df0019 */ 	multu	$t6,$ra
/*  f0b2294:	018ac023 */ 	subu	$t8,$t4,$t2
/*  f0b2298:	00007812 */ 	mflo	$t7
/*  f0b229c:	000fc940 */ 	sll	$t9,$t7,0x5
/*  f0b22a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b22a4:	0338001a */ 	div	$zero,$t9,$t8
/*  f0b22a8:	00007012 */ 	mflo	$t6
/*  f0b22ac:	012e4821 */ 	addu	$t1,$t1,$t6
/*  f0b22b0:	17000002 */ 	bnez	$t8,.L0f0b22bc
/*  f0b22b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b22b8:	0007000d */ 	break	0x7
.L0f0b22bc:
/*  f0b22bc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0b22c0:	17010004 */ 	bne	$t8,$at,.L0f0b22d4
/*  f0b22c4:	3c018000 */ 	lui	$at,0x8000
/*  f0b22c8:	17210002 */ 	bne	$t9,$at,.L0f0b22d4
/*  f0b22cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b22d0:	0006000d */ 	break	0x6
.L0f0b22d4:
/*  f0b22d4:	10000013 */ 	beqz	$zero,.L0f0b2324
/*  f0b22d8:	00005025 */ 	or	$t2,$zero,$zero
.L0f0b22dc:
/*  f0b22dc:	01e70019 */ 	multu	$t7,$a3
/*  f0b22e0:	018a7023 */ 	subu	$t6,$t4,$t2
/*  f0b22e4:	0000c812 */ 	mflo	$t9
/*  f0b22e8:	0019c140 */ 	sll	$t8,$t9,0x5
/*  f0b22ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b22f0:	030e001a */ 	div	$zero,$t8,$t6
/*  f0b22f4:	00007812 */ 	mflo	$t7
/*  f0b22f8:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f0b22fc:	15c00002 */ 	bnez	$t6,.L0f0b2308
/*  f0b2300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2304:	0007000d */ 	break	0x7
.L0f0b2308:
/*  f0b2308:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0b230c:	15c10004 */ 	bne	$t6,$at,.L0f0b2320
/*  f0b2310:	3c018000 */ 	lui	$at,0x8000
/*  f0b2314:	17010002 */ 	bne	$t8,$at,.L0f0b2320
/*  f0b2318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b231c:	0006000d */ 	break	0x6
.L0f0b2320:
/*  f0b2320:	00005025 */ 	or	$t2,$zero,$zero
.L0f0b2324:
/*  f0b2324:	05610029 */ 	bgez	$t3,.L0f0b23cc
/*  f0b2328:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0b232c:	13200015 */ 	beqz	$t9,.L0f0b2384
/*  f0b2330:	000b7023 */ 	negu	$t6,$t3
/*  f0b2334:	000bc023 */ 	negu	$t8,$t3
/*  f0b2338:	03070019 */ 	multu	$t8,$a3
/*  f0b233c:	01abc823 */ 	subu	$t9,$t5,$t3
/*  f0b2340:	00007012 */ 	mflo	$t6
/*  f0b2344:	000e7940 */ 	sll	$t7,$t6,0x5
/*  f0b2348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b234c:	01f9001a */ 	div	$zero,$t7,$t9
/*  f0b2350:	0000c012 */ 	mflo	$t8
/*  f0b2354:	01184021 */ 	addu	$t0,$t0,$t8
/*  f0b2358:	17200002 */ 	bnez	$t9,.L0f0b2364
/*  f0b235c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2360:	0007000d */ 	break	0x7
.L0f0b2364:
/*  f0b2364:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0b2368:	17210004 */ 	bne	$t9,$at,.L0f0b237c
/*  f0b236c:	3c018000 */ 	lui	$at,0x8000
/*  f0b2370:	15e10002 */ 	bne	$t7,$at,.L0f0b237c
/*  f0b2374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2378:	0006000d */ 	break	0x6
.L0f0b237c:
/*  f0b237c:	10000013 */ 	beqz	$zero,.L0f0b23cc
/*  f0b2380:	00005825 */ 	or	$t3,$zero,$zero
.L0f0b2384:
/*  f0b2384:	01df0019 */ 	multu	$t6,$ra
/*  f0b2388:	01abc023 */ 	subu	$t8,$t5,$t3
/*  f0b238c:	00007812 */ 	mflo	$t7
/*  f0b2390:	000fc940 */ 	sll	$t9,$t7,0x5
/*  f0b2394:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2398:	0338001a */ 	div	$zero,$t9,$t8
/*  f0b239c:	00007012 */ 	mflo	$t6
/*  f0b23a0:	012e4821 */ 	addu	$t1,$t1,$t6
/*  f0b23a4:	17000002 */ 	bnez	$t8,.L0f0b23b0
/*  f0b23a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b23ac:	0007000d */ 	break	0x7
.L0f0b23b0:
/*  f0b23b0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0b23b4:	17010004 */ 	bne	$t8,$at,.L0f0b23c8
/*  f0b23b8:	3c018000 */ 	lui	$at,0x8000
/*  f0b23bc:	17210002 */ 	bne	$t9,$at,.L0f0b23c8
/*  f0b23c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b23c4:	0006000d */ 	break	0x6
.L0f0b23c8:
/*  f0b23c8:	00005825 */ 	or	$t3,$zero,$zero
.L0f0b23cc:
/*  f0b23cc:	afbf0060 */ 	sw	$ra,0x60($sp)
/*  f0b23d0:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0b23d4:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0b23d8:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0b23dc:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0b23e0:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f0b23e4:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f0b23e8:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f0b23ec:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f0b23f0:	afac0040 */ 	sw	$t4,0x40($sp)
/*  f0b23f4:	0c002f02 */ 	jal	func0000bc08
/*  f0b23f8:	afad003c */ 	sw	$t5,0x3c($sp)
/*  f0b23fc:	00021880 */ 	sll	$v1,$v0,0x2
/*  f0b2400:	0c002f06 */ 	jal	func0000bc18
/*  f0b2404:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f0b2408:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f0b240c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0b2410:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0b2414:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f0b2418:	006c082a */ 	slt	$at,$v1,$t4
/*  f0b241c:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f0b2420:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f0b2424:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0b2428:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f0b242c:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0b2430:	10200002 */ 	beqz	$at,.L0f0b243c
/*  f0b2434:	8fbf0060 */ 	lw	$ra,0x60($sp)
/*  f0b2438:	00606025 */ 	or	$t4,$v1,$zero
.L0f0b243c:
/*  f0b243c:	00021880 */ 	sll	$v1,$v0,0x2
/*  f0b2440:	006d082a */ 	slt	$at,$v1,$t5
/*  f0b2444:	10200002 */ 	beqz	$at,.L0f0b2450
/*  f0b2448:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0b244c:	00606825 */ 	or	$t5,$v1,$zero
.L0f0b2450:
/*  f0b2450:	8fa30064 */ 	lw	$v1,0x64($sp)
/*  f0b2454:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f0b2458:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f0b245c:	50600018 */ 	beqzl	$v1,.L0f0b24c0
/*  f0b2460:	44823000 */ 	mtc1	$v0,$f6
/*  f0b2464:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f0b2468:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*  f0b246c:	3c014480 */ 	lui	$at,0x4480
/*  f0b2470:	44829000 */ 	mtc1	$v0,$f18
/*  f0b2474:	46021180 */ 	add.s	$f6,$f2,$f2
/*  f0b2478:	44816000 */ 	mtc1	$at,$f12
/*  f0b247c:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f0b2480:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0b2484:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f0b2488:	449f2000 */ 	mtc1	$ra,$f4
/*  f0b248c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2490:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0b2494:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0b2498:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0b249c:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0b24a0:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0b24a4:	44069000 */ 	mfc1	$a2,$f18
/*  f0b24a8:	460c5482 */ 	mul.s	$f18,$f10,$f12
/*  f0b24ac:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0b24b0:	44072000 */ 	mfc1	$a3,$f4
/*  f0b24b4:	10000015 */ 	beqz	$zero,.L0f0b250c
/*  f0b24b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b24bc:	44823000 */ 	mtc1	$v0,$f6
.L0f0b24c0:
/*  f0b24c0:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f0b24c4:	3c014480 */ 	lui	$at,0x4480
/*  f0b24c8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0b24cc:	44816000 */ 	mtc1	$at,$f12
/*  f0b24d0:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*  f0b24d4:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0b24d8:	460a4483 */ 	div.s	$f18,$f8,$f10
/*  f0b24dc:	449f4000 */ 	mtc1	$ra,$f8
/*  f0b24e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b24e4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0b24e8:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f0b24ec:	46021480 */ 	add.s	$f18,$f2,$f2
/*  f0b24f0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0b24f4:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f0b24f8:	44063000 */ 	mfc1	$a2,$f6
/*  f0b24fc:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0b2500:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0b2504:	44074000 */ 	mfc1	$a3,$f8
/*  f0b2508:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b250c:
/*  f0b250c:	1320000a */ 	beqz	$t9,.L0f0b2538
/*  f0b2510:	3c01e400 */ 	lui	$at,0xe400
/*  f0b2514:	01c60019 */ 	multu	$t6,$a2
/*  f0b2518:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f0b251c:	00007812 */ 	mflo	$t7
/*  f0b2520:	000fc1c3 */ 	sra	$t8,$t7,0x7
/*  f0b2524:	01184023 */ 	subu	$t0,$t0,$t8
/*  f0b2528:	03270019 */ 	multu	$t9,$a3
/*  f0b252c:	00007012 */ 	mflo	$t6
/*  f0b2530:	000e79c3 */ 	sra	$t7,$t6,0x7
/*  f0b2534:	012f4823 */ 	subu	$t1,$t1,$t7
.L0f0b2538:
/*  f0b2538:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f0b253c:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0b2540:	1300000b */ 	beqz	$t8,.L0f0b2570
/*  f0b2544:	3c190001 */ 	lui	$t9,0x1
/*  f0b2548:	11c00006 */ 	beqz	$t6,.L0f0b2564
/*  f0b254c:	03263023 */ 	subu	$a2,$t9,$a2
/*  f0b2550:	00027843 */ 	sra	$t7,$v0,0x1
/*  f0b2554:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0b2558:	0018c940 */ 	sll	$t9,$t8,0x5
/*  f0b255c:	10000004 */ 	beqz	$zero,.L0f0b2570
/*  f0b2560:	03284023 */ 	subu	$t0,$t9,$t0
.L0f0b2564:
/*  f0b2564:	244effff */ 	addiu	$t6,$v0,-1
/*  f0b2568:	000e7940 */ 	sll	$t7,$t6,0x5
/*  f0b256c:	01e84023 */ 	subu	$t0,$t7,$t0
.L0f0b2570:
/*  f0b2570:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0b2574:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0b2578:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0b257c:	1300000b */ 	beqz	$t8,.L0f0b25ac
/*  f0b2580:	3c190001 */ 	lui	$t9,0x1
/*  f0b2584:	11c00006 */ 	beqz	$t6,.L0f0b25a0
/*  f0b2588:	03273823 */ 	subu	$a3,$t9,$a3
/*  f0b258c:	001f7843 */ 	sra	$t7,$ra,0x1
/*  f0b2590:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0b2594:	0018c940 */ 	sll	$t9,$t8,0x5
/*  f0b2598:	10000004 */ 	beqz	$zero,.L0f0b25ac
/*  f0b259c:	03294823 */ 	subu	$t1,$t9,$t1
.L0f0b25a0:
/*  f0b25a0:	27eeffff */ 	addiu	$t6,$ra,-1
/*  f0b25a4:	000e7940 */ 	sll	$t7,$t6,0x5
/*  f0b25a8:	01e94823 */ 	subu	$t1,$t7,$t1
.L0f0b25ac:
/*  f0b25ac:	10600024 */ 	beqz	$v1,.L0f0b2640
/*  f0b25b0:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f0b25b4:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f0b25b8:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f0b25bc:	3c01e500 */ 	lui	$at,0xe500
/*  f0b25c0:	03217025 */ 	or	$t6,$t9,$at
/*  f0b25c4:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0b25c8:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f0b25cc:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0b25d0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0b25d4:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f0b25d8:	31580fff */ 	andi	$t8,$t2,0xfff
/*  f0b25dc:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b25e0:	332e0007 */ 	andi	$t6,$t9,0x7
/*  f0b25e4:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f0b25e8:	000e7e00 */ 	sll	$t7,$t6,0x18
/*  f0b25ec:	01f97025 */ 	or	$t6,$t7,$t9
/*  f0b25f0:	31780fff */ 	andi	$t8,$t3,0xfff
/*  f0b25f4:	01d87825 */ 	or	$t7,$t6,$t8
/*  f0b25f8:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0b25fc:	3c19b400 */ 	lui	$t9,0xb400
/*  f0b2600:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0b2604:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0b2608:	312fffff */ 	andi	$t7,$t1,0xffff
/*  f0b260c:	0008c400 */ 	sll	$t8,$t0,0x10
/*  f0b2610:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0b2614:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0b2618:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b261c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0b2620:	3c0eb300 */ 	lui	$t6,0xb300
/*  f0b2624:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0b2628:	30f9ffff */ 	andi	$t9,$a3,0xffff
/*  f0b262c:	00067c00 */ 	sll	$t7,$a2,0x10
/*  f0b2630:	01f97025 */ 	or	$t6,$t7,$t9
/*  f0b2634:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f0b2638:	10000020 */ 	beqz	$zero,.L0f0b26bc
/*  f0b263c:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0b2640:
/*  f0b2640:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f0b2644:	01e1c825 */ 	or	$t9,$t7,$at
/*  f0b2648:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0b264c:	032ec025 */ 	or	$t8,$t9,$t6
/*  f0b2650:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0b2654:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0b2658:	31580fff */ 	andi	$t8,$t2,0xfff
/*  f0b265c:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b2660:	31f90007 */ 	andi	$t9,$t7,0x7
/*  f0b2664:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f0b2668:	00197600 */ 	sll	$t6,$t9,0x18
/*  f0b266c:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f0b2670:	31780fff */ 	andi	$t8,$t3,0xfff
/*  f0b2674:	03387025 */ 	or	$t6,$t9,$t8
/*  f0b2678:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0b267c:	3c0fb400 */ 	lui	$t7,0xb400
/*  f0b2680:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0b2684:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0b2688:	312effff */ 	andi	$t6,$t1,0xffff
/*  f0b268c:	0008c400 */ 	sll	$t8,$t0,0x10
/*  f0b2690:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0b2694:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0b2698:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b269c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0b26a0:	3c19b300 */ 	lui	$t9,0xb300
/*  f0b26a4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0b26a8:	30efffff */ 	andi	$t7,$a3,0xffff
/*  f0b26ac:	00067400 */ 	sll	$t6,$a2,0x10
/*  f0b26b0:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f0b26b4:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f0b26b8:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0b26bc:
/*  f0b26bc:	00a01025 */ 	or	$v0,$a1,$zero
.L0f0b26c0:
/*  f0b26c0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0b26c4:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f0b26c8:	3c0e0008 */ 	lui	$t6,0x8
/*  f0b26cc:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0b26d0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0b26d4:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f0b26d8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b26dc:	ade50000 */ 	sw	$a1,0x0($t7)
/*  f0b26e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b26e4:
/*  f0b26e4:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0b26e8:	03e00008 */ 	jr	$ra
/*  f0b26ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b26f0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0b26f4:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0b26f8:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f0b26fc:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0b2700:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f0b2704:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f0b2708:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*  f0b270c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0b2710:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0b2714:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0b2718:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0b271c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0b2720:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0b2724:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0b2728:	0fc2c854 */ 	jal	func0f0b2150
/*  f0b272c:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f0b2730:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0b2734:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0b2738:	03e00008 */ 	jr	$ra
/*  f0b273c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b2740
/*  f0b2740:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0b2744:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0b2748:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f0b274c:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0b2750:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f0b2754:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f0b2758:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0b275c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0b2760:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0b2764:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0b2768:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0b276c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0b2770:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0b2774:	0fc2c854 */ 	jal	func0f0b2150
/*  f0b2778:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0b277c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0b2780:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0b2784:	03e00008 */ 	jr	$ra
/*  f0b2788:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b278c
/*  f0b278c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0b2790:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0b2794:	44800000 */ 	mtc1	$zero,$f0
/*  f0b2798:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0b279c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0b27a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b27a4:	45020044 */ 	bc1fl	.L0f0b28b8
/*  f0b27a8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0b27ac:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f0b27b0:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0b27b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b27b8:	4502003f */ 	bc1fl	.L0f0b28b8
/*  f0b27bc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0b27c0:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0b27c4:	3c0efb00 */ 	lui	$t6,0xfb00
/*  f0b27c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b27cc:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0b27d0:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0b27d4:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0b27d8:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0b27dc:	0018ce00 */ 	sll	$t9,$t8,0x18
/*  f0b27e0:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f0b27e4:	310900ff */ 	andi	$t1,$t0,0xff
/*  f0b27e8:	00095400 */ 	sll	$t2,$t1,0x10
/*  f0b27ec:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0b27f0:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f0b27f4:	032a5825 */ 	or	$t3,$t9,$t2
/*  f0b27f8:	016e7825 */ 	or	$t7,$t3,$t6
/*  f0b27fc:	330800ff */ 	andi	$t0,$t8,0xff
/*  f0b2800:	01e84825 */ 	or	$t1,$t7,$t0
/*  f0b2804:	ac690004 */ 	sw	$t1,0x4($v1)
/*  f0b2808:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0b280c:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0b2810:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b2814:	13200009 */ 	beqz	$t9,.L0f0b283c
/*  f0b2818:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f0b281c:	3c0afc26 */ 	lui	$t2,0xfc26
/*  f0b2820:	3c0c1f14 */ 	lui	$t4,0x1f14
/*  f0b2824:	358c93ff */ 	ori	$t4,$t4,0x93ff
/*  f0b2828:	354aa005 */ 	ori	$t2,$t2,0xa005
/*  f0b282c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0b2830:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f0b2834:	10000012 */ 	beqz	$zero,.L0f0b2880
/*  f0b2838:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b283c:
/*  f0b283c:	11a00009 */ 	beqz	$t5,.L0f0b2864
/*  f0b2840:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b2844:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b2848:	3c0bfc12 */ 	lui	$t3,0xfc12
/*  f0b284c:	356b9bff */ 	ori	$t3,$t3,0x9bff
/*  f0b2850:	240efe38 */ 	addiu	$t6,$zero,-456
/*  f0b2854:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f0b2858:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0b285c:	10000008 */ 	beqz	$zero,.L0f0b2880
/*  f0b2860:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b2864:
/*  f0b2864:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0b2868:	3c0fff37 */ 	lui	$t7,0xff37
/*  f0b286c:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f0b2870:	37189a25 */ 	ori	$t8,$t8,0x9a25
/*  f0b2874:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0b2878:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0b287c:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b2880:
/*  f0b2880:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f0b2884:	8faa0054 */ 	lw	$t2,0x54($sp)
/*  f0b2888:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0b288c:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0b2890:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0b2894:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0b2898:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0b289c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0b28a0:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0b28a4:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0b28a8:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0b28ac:	0fc2c854 */ 	jal	func0f0b2150
/*  f0b28b0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0b28b4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0b28b8:
/*  f0b28b8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0b28bc:	03e00008 */ 	jr	$ra
/*  f0b28c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b28c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b28c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b28cc:	00000000 */ 	sll	$zero,$zero,0x0
);
