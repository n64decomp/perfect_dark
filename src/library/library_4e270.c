#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004e270
/*    4e270:	3c058006 */ 	lui	$a1,%hi(var8005cf68)
/*    4e274:	24a5cf68 */ 	addiu	$a1,$a1,%lo(var8005cf68)
/*    4e278:	8cae0000 */ 	lw	$t6,0x0($a1)
/*    4e27c:	44844000 */ 	mtc1	$a0,$f8
/*    4e280:	3c014f80 */ 	lui	$at,0x4f80
/*    4e284:	448e2000 */ 	mtc1	$t6,$f4
/*    4e288:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    4e28c:	04810004 */ 	bgez	$a0,.L0004e2a0
/*    4e290:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    4e294:	44818000 */ 	mtc1	$at,$f16
/*    4e298:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e29c:	46105280 */ 	add.s	$f10,$f10,$f16
.L0004e2a0:
/*    4e2a0:	460a3483 */ 	div.s	$f18,$f6,$f10
/*    4e2a4:	3c013f00 */ 	lui	$at,0x3f00
/*    4e2a8:	44812000 */ 	mtc1	$at,$f4
/*    4e2ac:	24030001 */ 	addiu	$v1,$zero,0x1
/*    4e2b0:	3c014f00 */ 	lui	$at,0x4f00
/*    4e2b4:	3c08a450 */ 	lui	$t0,0xa450
/*    4e2b8:	3c0aa450 */ 	lui	$t2,0xa450
/*    4e2bc:	46049000 */ 	add.s	$f0,$f18,$f4
/*    4e2c0:	444ff800 */ 	cfc1	$t7,$31
/*    4e2c4:	44c3f800 */ 	ctc1	$v1,$31
/*    4e2c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e2cc:	46000224 */ 	cvt.w.s	$f8,$f0
/*    4e2d0:	4443f800 */ 	cfc1	$v1,$31
/*    4e2d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e2d8:	30630078 */ 	andi	$v1,$v1,0x78
/*    4e2dc:	50600013 */ 	beqzl	$v1,.L0004e32c
/*    4e2e0:	44034000 */ 	mfc1	$v1,$f8
/*    4e2e4:	44814000 */ 	mtc1	$at,$f8
/*    4e2e8:	24030001 */ 	addiu	$v1,$zero,0x1
/*    4e2ec:	46080201 */ 	sub.s	$f8,$f0,$f8
/*    4e2f0:	44c3f800 */ 	ctc1	$v1,$31
/*    4e2f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e2f8:	46004224 */ 	cvt.w.s	$f8,$f8
/*    4e2fc:	4443f800 */ 	cfc1	$v1,$31
/*    4e300:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e304:	30630078 */ 	andi	$v1,$v1,0x78
/*    4e308:	14600005 */ 	bnez	$v1,.L0004e320
/*    4e30c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e310:	44034000 */ 	mfc1	$v1,$f8
/*    4e314:	3c018000 */ 	lui	$at,0x8000
/*    4e318:	10000007 */ 	beqz	$zero,.L0004e338
/*    4e31c:	00611825 */ 	or	$v1,$v1,$at
.L0004e320:
/*    4e320:	10000005 */ 	beqz	$zero,.L0004e338
/*    4e324:	2403ffff */ 	addiu	$v1,$zero,-1
/*    4e328:	44034000 */ 	mfc1	$v1,$f8
.L0004e32c:
/*    4e32c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e330:	0460fffb */ 	bltz	$v1,.L0004e320
/*    4e334:	00000000 */ 	sll	$zero,$zero,0x0
.L0004e338:
/*    4e338:	44cff800 */ 	ctc1	$t7,$31
/*    4e33c:	2c610084 */ 	sltiu	$at,$v1,0x84
/*    4e340:	10200003 */ 	beqz	$at,.L0004e350
/*    4e344:	2479ffff */ 	addiu	$t9,$v1,-1
/*    4e348:	03e00008 */ 	jr	$ra
/*    4e34c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004e350:
/*    4e350:	24010042 */ 	addiu	$at,$zero,0x42
/*    4e354:	0061001b */ 	divu	$zero,$v1,$at
/*    4e358:	00001012 */ 	mflo	$v0
/*    4e35c:	305800ff */ 	andi	$t8,$v0,0xff
/*    4e360:	2b010011 */ 	slti	$at,$t8,0x11
/*    4e364:	14200002 */ 	bnez	$at,.L0004e370
/*    4e368:	304400ff */ 	andi	$a0,$v0,0xff
/*    4e36c:	24040010 */ 	addiu	$a0,$zero,0x10
.L0004e370:
/*    4e370:	ad190010 */ 	sw	$t9,0x10($t0)
/*    4e374:	2489ffff */ 	addiu	$t1,$a0,-1
/*    4e378:	ad490014 */ 	sw	$t1,0x14($t2)
/*    4e37c:	8cab0000 */ 	lw	$t3,0x0($a1)
/*    4e380:	0163001a */ 	div	$zero,$t3,$v1
/*    4e384:	00001012 */ 	mflo	$v0
/*    4e388:	14600002 */ 	bnez	$v1,.L0004e394
/*    4e38c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e390:	0007000d */ 	break	0x7
.L0004e394:
/*    4e394:	2401ffff */ 	addiu	$at,$zero,-1
/*    4e398:	14610004 */ 	bne	$v1,$at,.L0004e3ac
/*    4e39c:	3c018000 */ 	lui	$at,0x8000
/*    4e3a0:	15610002 */ 	bne	$t3,$at,.L0004e3ac
/*    4e3a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e3a8:	0006000d */ 	break	0x6
.L0004e3ac:
/*    4e3ac:	03e00008 */ 	jr	$ra
/*    4e3b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e3b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e3b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e3bc:	00000000 */ 	sll	$zero,$zero,0x0
);