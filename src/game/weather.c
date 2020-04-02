#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/game_0b3350.h"
#include "game/game_12f6c0.h"
#include "game/weather.h"
#include "game/game_157db0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "gvars/gvars.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_317f0.h"
#include "lib/lib_481e0.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4b480.h"
#include "types.h"

const char var7f1b5620[] = "rainspeedxtra";
const char var7f1b5630[] = "snowspeed";
const char var7f1b563c[] = "snowspeedxtra";
const char var7f1b564c[] = "raincol1";
const char var7f1b5658[] = "raincol2";
const char var7f1b5664[] = "rainwidth";
const char var7f1b5670[] = "rainout";
const char var7f1b5678[] = "cddiv";
const char var7f1b5680[] = "wetclip";
const char var7f1b5688[] = "bounder";
const char var7f1b5690[] = "trypitch";
const char var7f1b569c[] = "snowwidth";
const char var7f1b56a8[] = "snowheight";
const char var7f1b56b4[] = "snowcol1";
const char var7f1b56c0[] = "snowcol2";

GLOBAL_ASM(
glabel weatherRender
/*  f131060:	3c058008 */ 	lui	$a1,%hi(g_WeatherData)
/*  f131064:	8ca5f0c0 */ 	lw	$a1,%lo(g_WeatherData)($a1)
/*  f131068:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f13106c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f131070:	14a00003 */ 	bnez	$a1,.L0f131080
/*  f131074:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f131078:	10000093 */ 	beqz	$zero,.L0f1312c8
/*  f13107c:	00801025 */ 	or	$v0,$a0,$zero
.L0f131080:
/*  f131080:	3c028008 */ 	lui	$v0,%hi(g_StageIndex)
/*  f131084:	8c42fc00 */ 	lw	$v0,%lo(g_StageIndex)($v0)
/*  f131088:	24010013 */ 	addiu	$at,$zero,0x13
/*  f13108c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f131090:	5441000c */ 	bnel	$v0,$at,.L0f1310c4
/*  f131094:	2401000a */ 	addiu	$at,$zero,0xa
/*  f131098:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f13109c:	3c01c4fa */ 	lui	$at,0xc4fa
/*  f1310a0:	44813000 */ 	mtc1	$at,$f6
/*  f1310a4:	c5c41bb8 */ 	lwc1	$f4,0x1bb8($t6)
/*  f1310a8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1310ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1310b0:	45020004 */ 	bc1fl	.L0f1310c4
/*  f1310b4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f1310b8:	10000083 */ 	beqz	$zero,.L0f1312c8
/*  f1310bc:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f1310c0:	2401000a */ 	addiu	$at,$zero,0xa
.L0f1310c4:
/*  f1310c4:	14410007 */ 	bne	$v0,$at,.L0f1310e4
/*  f1310c8:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x2ac)
/*  f1310cc:	8defa26c */ 	lw	$t7,%lo(g_Vars+0x2ac)($t7)
/*  f1310d0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1310d4:	51e10004 */ 	beql	$t7,$at,.L0f1310e8
/*  f1310d8:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f1310dc:	1000007a */ 	beqz	$zero,.L0f1312c8
/*  f1310e0:	8fa20030 */ 	lw	$v0,0x30($sp)
.L0f1310e4:
/*  f1310e4:	8fb80030 */ 	lw	$t8,0x30($sp)
.L0f1310e8:
/*  f1310e8:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f1310ec:	3c088006 */ 	lui	$t0,%hi(var800613a0)
/*  f1310f0:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1310f4:	afb90030 */ 	sw	$t9,0x30($sp)
/*  f1310f8:	3c040600 */ 	lui	$a0,0x600
/*  f1310fc:	250813a0 */ 	addiu	$t0,$t0,%lo(var800613a0)
/*  f131100:	af080004 */ 	sw	$t0,0x4($t8)
/*  f131104:	af040000 */ 	sw	$a0,0x0($t8)
/*  f131108:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f13110c:	3c0b8006 */ 	lui	$t3,%hi(var80061380)
/*  f131110:	256b1380 */ 	addiu	$t3,$t3,%lo(var80061380)
/*  f131114:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f131118:	afaa0030 */ 	sw	$t2,0x30($sp)
/*  f13111c:	ad2b0004 */ 	sw	$t3,0x4($t1)
/*  f131120:	ad240000 */ 	sw	$a0,0x0($t1)
/*  f131124:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f131128:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13112c:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f131130:	8d860020 */ 	lw	$a2,0x20($t4)
/*  f131134:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f131138:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f13113c:	14c10051 */ 	bne	$a2,$at,.L0f131284
/*  f131140:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f131144:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f131148:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f13114c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f131150:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f131154:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f131158:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f13115c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f131160:	24a5000c */ 	addiu	$a1,$a1,0x000c
/*  f131164:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f131168:	3c19ba00 */ 	lui	$t9,0xba00
/*  f13116c:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f131170:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f131174:	afb80030 */ 	sw	$t8,0x30($sp)
/*  f131178:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f13117c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f131180:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f131184:	3c0aba00 */ 	lui	$t2,0xba00
/*  f131188:	354a0602 */ 	ori	$t2,$t2,0x602
/*  f13118c:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f131190:	afa90030 */ 	sw	$t1,0x30($sp)
/*  f131194:	240b0080 */ 	addiu	$t3,$zero,0x80
/*  f131198:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f13119c:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f1311a0:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f1311a4:	3c0f0050 */ 	lui	$t7,0x50
/*  f1311a8:	3c0eb900 */ 	lui	$t6,0xb900
/*  f1311ac:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f1311b0:	afad0030 */ 	sw	$t5,0x30($sp)
/*  f1311b4:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f1311b8:	35ef49d8 */ 	ori	$t7,$t7,0x49d8
/*  f1311bc:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f1311c0:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f1311c4:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f1311c8:	3c08b900 */ 	lui	$t0,0xb900
/*  f1311cc:	35080002 */ 	ori	$t0,$t0,0x2
/*  f1311d0:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1311d4:	afb90030 */ 	sw	$t9,0x30($sp)
/*  f1311d8:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1311dc:	af080000 */ 	sw	$t0,0x0($t8)
/*  f1311e0:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f1311e4:	3c0bba00 */ 	lui	$t3,0xba00
/*  f1311e8:	356b1001 */ 	ori	$t3,$t3,0x1001
/*  f1311ec:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f1311f0:	afaa0030 */ 	sw	$t2,0x30($sp)
/*  f1311f4:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f1311f8:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f1311fc:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f131200:	3c0eba00 */ 	lui	$t6,0xba00
/*  f131204:	35ce0903 */ 	ori	$t6,$t6,0x903
/*  f131208:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f13120c:	afad0030 */ 	sw	$t5,0x30($sp)
/*  f131210:	240f0c00 */ 	addiu	$t7,$zero,0xc00
/*  f131214:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f131218:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f13121c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f131220:	3c09fffe */ 	lui	$t1,0xfffe
/*  f131224:	3c08fcff */ 	lui	$t0,0xfcff
/*  f131228:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f13122c:	afb90030 */ 	sw	$t9,0x30($sp)
/*  f131230:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f131234:	3529793c */ 	ori	$t1,$t1,0x793c
/*  f131238:	af090004 */ 	sw	$t1,0x4($t8)
/*  f13123c:	af080000 */ 	sw	$t0,0x0($t8)
/*  f131240:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f131244:	3c0cb700 */ 	lui	$t4,0xb700
/*  f131248:	240d0204 */ 	addiu	$t5,$zero,0x204
/*  f13124c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f131250:	afab0030 */ 	sw	$t3,0x30($sp)
/*  f131254:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f131258:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f13125c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f131260:	3c18ba00 */ 	lui	$t8,0xba00
/*  f131264:	37180402 */ 	ori	$t8,$t8,0x402
/*  f131268:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f13126c:	afaf0030 */ 	sw	$t7,0x30($sp)
/*  f131270:	24190020 */ 	addiu	$t9,$zero,0x20
/*  f131274:	add90004 */ 	sw	$t9,0x4($t6)
/*  f131278:	add80000 */ 	sw	$t8,0x0($t6)
/*  f13127c:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f131280:	8d060020 */ 	lw	$a2,0x20($t0)
.L0f131284:
/*  f131284:	10c00006 */ 	beqz	$a2,.L0f1312a0
/*  f131288:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f13128c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f131290:	10c10008 */ 	beq	$a2,$at,.L0f1312b4
/*  f131294:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f131298:	1000000b */ 	beqz	$zero,.L0f1312c8
/*  f13129c:	8fa20030 */ 	lw	$v0,0x30($sp)
.L0f1312a0:
/*  f1312a0:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f1312a4:	0fc4cb8a */ 	jal	weatherRenderRain
/*  f1312a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1312ac:	10000005 */ 	beqz	$zero,.L0f1312c4
/*  f1312b0:	afa20030 */ 	sw	$v0,0x30($sp)
.L0f1312b4:
/*  f1312b4:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f1312b8:	0fc4d1ac */ 	jal	weatherRenderSnow
/*  f1312bc:	00003025 */ 	or	$a2,$zero,$zero
/*  f1312c0:	afa20030 */ 	sw	$v0,0x30($sp)
.L0f1312c4:
/*  f1312c4:	8fa20030 */ 	lw	$v0,0x30($sp)
.L0f1312c8:
/*  f1312c8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1312cc:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1312d0:	03e00008 */ 	jr	$ra
/*  f1312d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1312d8
/*  f1312d8:	44866000 */ 	mtc1	$a2,$f12
/*  f1312dc:	44801000 */ 	mtc1	$zero,$f2
/*  f1312e0:	44877000 */ 	mtc1	$a3,$f14
/*  f1312e4:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1312e8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1312ec:	008e1021 */ 	addu	$v0,$a0,$t6
/*  f1312f0:	e44c3e98 */ 	swc1	$f12,0x3e98($v0)
/*  f1312f4:	e44e3e8c */ 	swc1	$f14,0x3e8c($v0)
/*  f1312f8:	45020004 */ 	bc1fl	.L0f13130c
/*  f1312fc:	46006007 */ 	neg.s	$f0,$f12
/*  f131300:	10000002 */ 	beqz	$zero,.L0f13130c
/*  f131304:	46006006 */ 	mov.s	$f0,$f12
/*  f131308:	46006007 */ 	neg.s	$f0,$f12
.L0f13130c:
/*  f13130c:	460e103c */ 	c.lt.s	$f2,$f14
/*  f131310:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131314:	45020004 */ 	bc1fl	.L0f131328
/*  f131318:	46007087 */ 	neg.s	$f2,$f14
/*  f13131c:	10000002 */ 	beqz	$zero,.L0f131328
/*  f131320:	46007086 */ 	mov.s	$f2,$f14
/*  f131324:	46007087 */ 	neg.s	$f2,$f14
.L0f131328:
/*  f131328:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f13132c:	03e00008 */ 	jr	$ra
/*  f131330:	e4443ea4 */ 	swc1	$f4,0x3ea4($v0)
);

GLOBAL_ASM(
glabel func0f131334
.late_rodata
glabel var7f1b56cc
.word 0x3f333333
.text
/*  f131334:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f131338:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f13133c:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f131340:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f131344:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f131348:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f13134c:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f131350:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f131354:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f131358:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f13135c:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f131360:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f131364:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f131368:	24043f00 */ 	addiu	$a0,$zero,0x3f00
/*  f13136c:	0c0048f2 */ 	jal	malloc
/*  f131370:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f131374:	3c01c448 */ 	lui	$at,0xc448
/*  f131378:	4481b000 */ 	mtc1	$at,$f22
/*  f13137c:	3c014448 */ 	lui	$at,0x4448
/*  f131380:	4481e000 */ 	mtc1	$at,$f28
/*  f131384:	4480a000 */ 	mtc1	$zero,$f20
/*  f131388:	4406b000 */ 	mfc1	$a2,$f22
/*  f13138c:	4407e000 */ 	mfc1	$a3,$f28
/*  f131390:	0040a025 */ 	or	$s4,$v0,$zero
/*  f131394:	00402025 */ 	or	$a0,$v0,$zero
/*  f131398:	00002825 */ 	or	$a1,$zero,$zero
/*  f13139c:	e4543e80 */ 	swc1	$f20,0x3e80($v0)
/*  f1313a0:	e4543e84 */ 	swc1	$f20,0x3e84($v0)
/*  f1313a4:	0fc4c4b6 */ 	jal	func0f1312d8
/*  f1313a8:	e4543e88 */ 	swc1	$f20,0x3e88($v0)
/*  f1313ac:	3c0e8008 */ 	lui	$t6,%hi(g_StageIndex)
/*  f1313b0:	8dcefc00 */ 	lw	$t6,%lo(g_StageIndex)($t6)
/*  f1313b4:	24100008 */ 	addiu	$s0,$zero,0x8
/*  f1313b8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1313bc:	160e0007 */ 	bne	$s0,$t6,.L0f1313dc
/*  f1313c0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1313c4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1313c8:	3c06c3fa */ 	lui	$a2,0xc3fa
/*  f1313cc:	0fc4c4b6 */ 	jal	func0f1312d8
/*  f1313d0:	3c0743fa */ 	lui	$a3,0x43fa
/*  f1313d4:	10000006 */ 	beqz	$zero,.L0f1313f0
/*  f1313d8:	4406b000 */ 	mfc1	$a2,$f22
.L0f1313dc:
/*  f1313dc:	4406b000 */ 	mfc1	$a2,$f22
/*  f1313e0:	4407e000 */ 	mfc1	$a3,$f28
/*  f1313e4:	0fc4c4b6 */ 	jal	func0f1312d8
/*  f1313e8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1313ec:	4406b000 */ 	mfc1	$a2,$f22
.L0f1313f0:
/*  f1313f0:	4407e000 */ 	mfc1	$a3,$f28
/*  f1313f4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1313f8:	0fc4c4b6 */ 	jal	func0f1312d8
/*  f1313fc:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f131400:	00001025 */ 	or	$v0,$zero,$zero
/*  f131404:	02801825 */ 	or	$v1,$s4,$zero
.L0f131408:
/*  f131408:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f13140c:	e4743ec8 */ 	swc1	$f20,0x3ec8($v1)
/*  f131410:	1450fffd */ 	bne	$v0,$s0,.L0f131408
/*  f131414:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f131418:	3c01c120 */ 	lui	$at,0xc120
/*  f13141c:	4481f000 */ 	mtc1	$at,$f30
/*  f131420:	3c0140a0 */ 	lui	$at,0x40a0
/*  f131424:	4481d000 */ 	mtc1	$at,$f26
/*  f131428:	3c014120 */ 	lui	$at,0x4120
/*  f13142c:	4481c000 */ 	mtc1	$at,$f24
/*  f131430:	3c0144c8 */ 	lui	$at,0x44c8
/*  f131434:	4481b000 */ 	mtc1	$at,$f22
/*  f131438:	3c012f80 */ 	lui	$at,0x2f80
/*  f13143c:	4481a000 */ 	mtc1	$at,$f20
/*  f131440:	00008825 */ 	or	$s1,$zero,$zero
/*  f131444:	02808025 */ 	or	$s0,$s4,$zero
/*  f131448:	24133e80 */ 	addiu	$s3,$zero,0x3e80
.L0f13144c:
/*  f13144c:	0c004b70 */ 	jal	random
/*  f131450:	02009025 */ 	or	$s2,$s0,$zero
/*  f131454:	44822000 */ 	mtc1	$v0,$f4
/*  f131458:	3c014f80 */ 	lui	$at,0x4f80
/*  f13145c:	04410004 */ 	bgez	$v0,.L0f131470
/*  f131460:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f131464:	44814000 */ 	mtc1	$at,$f8
/*  f131468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13146c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f131470:
/*  f131470:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f131474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131478:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f13147c:	461c8481 */ 	sub.s	$f18,$f16,$f28
/*  f131480:	0c004b70 */ 	jal	random
/*  f131484:	e6120000 */ 	swc1	$f18,0x0($s0)
/*  f131488:	44822000 */ 	mtc1	$v0,$f4
/*  f13148c:	3c014f80 */ 	lui	$at,0x4f80
/*  f131490:	04410004 */ 	bgez	$v0,.L0f1314a4
/*  f131494:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f131498:	44813000 */ 	mtc1	$at,$f6
/*  f13149c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1314a0:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f1314a4:
/*  f1314a4:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f1314a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1314ac:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f1314b0:	461c8481 */ 	sub.s	$f18,$f16,$f28
/*  f1314b4:	0c004b70 */ 	jal	random
/*  f1314b8:	e6120004 */ 	swc1	$f18,0x4($s0)
/*  f1314bc:	44822000 */ 	mtc1	$v0,$f4
/*  f1314c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1314c4:	04410004 */ 	bgez	$v0,.L0f1314d8
/*  f1314c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1314cc:	44814000 */ 	mtc1	$at,$f8
/*  f1314d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1314d4:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f1314d8:
/*  f1314d8:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f1314dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1314e0:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f1314e4:	461c8481 */ 	sub.s	$f18,$f16,$f28
/*  f1314e8:	0c004b70 */ 	jal	random
/*  f1314ec:	e6120008 */ 	swc1	$f18,0x8($s0)
/*  f1314f0:	44822000 */ 	mtc1	$v0,$f4
/*  f1314f4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1314f8:	04410004 */ 	bgez	$v0,.L0f13150c
/*  f1314fc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f131500:	44813000 */ 	mtc1	$at,$f6
/*  f131504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131508:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f13150c:
/*  f13150c:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f131510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131514:	46185402 */ 	mul.s	$f16,$f10,$f24
/*  f131518:	461a8481 */ 	sub.s	$f18,$f16,$f26
/*  f13151c:	0c004b70 */ 	jal	random
/*  f131520:	e6120010 */ 	swc1	$f18,0x10($s0)
/*  f131524:	44822000 */ 	mtc1	$v0,$f4
/*  f131528:	3c014f80 */ 	lui	$at,0x4f80
/*  f13152c:	04410004 */ 	bgez	$v0,.L0f131540
/*  f131530:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f131534:	44814000 */ 	mtc1	$at,$f8
/*  f131538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13153c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f131540:
/*  f131540:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f131544:	3c014220 */ 	lui	$at,0x4220
/*  f131548:	44818000 */ 	mtc1	$at,$f16
/*  f13154c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131550:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f131554:	4612f101 */ 	sub.s	$f4,$f30,$f18
/*  f131558:	0c004b70 */ 	jal	random
/*  f13155c:	e6040014 */ 	swc1	$f4,0x14($s0)
/*  f131560:	44824000 */ 	mtc1	$v0,$f8
/*  f131564:	3c014f80 */ 	lui	$at,0x4f80
/*  f131568:	04410004 */ 	bgez	$v0,.L0f13157c
/*  f13156c:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f131570:	44815000 */ 	mtc1	$at,$f10
/*  f131574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131578:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f13157c:
/*  f13157c:	46143402 */ 	mul.s	$f16,$f6,$f20
/*  f131580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131584:	46188482 */ 	mul.s	$f18,$f16,$f24
/*  f131588:	461a9101 */ 	sub.s	$f4,$f18,$f26
/*  f13158c:	0c004b70 */ 	jal	random
/*  f131590:	e6040018 */ 	swc1	$f4,0x18($s0)
/*  f131594:	44824000 */ 	mtc1	$v0,$f8
/*  f131598:	3c014f80 */ 	lui	$at,0x4f80
/*  f13159c:	04410004 */ 	bgez	$v0,.L0f1315b0
/*  f1315a0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1315a4:	44813000 */ 	mtc1	$at,$f6
/*  f1315a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1315ac:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f1315b0:
/*  f1315b0:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f1315b4:	3c017f1b */ 	lui	$at,%hi(var7f1b56cc)
/*  f1315b8:	c43256cc */ 	lwc1	$f18,%lo(var7f1b56cc)($at)
/*  f1315bc:	26310020 */ 	addiu	$s1,$s1,0x20
/*  f1315c0:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f1315c4:	ae40000c */ 	sw	$zero,0xc($s2)
/*  f1315c8:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f1315cc:	1633ff9f */ 	bne	$s1,$s3,.L0f13144c
/*  f1315d0:	e644001c */ 	swc1	$f4,0x1c($s2)
/*  f1315d4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1315d8:	02801025 */ 	or	$v0,$s4,$zero
/*  f1315dc:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f1315e0:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1315e4:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f1315e8:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f1315ec:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f1315f0:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f1315f4:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f1315f8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f1315fc:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f131600:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f131604:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f131608:	03e00008 */ 	jr	$ra
/*  f13160c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

void func0f131610(struct weatherdata *weather)
{
	weather->unk94 = 0;
	weather->unk98 = (random() & 7) + 1;
	weather->unk9c = (random() & 7) + 1;
	weather->unka0 = (random() & 7) + 1;
	weather->unka4 = (random() & 0xf) + 10;
}

void func0f131678(s32 arg0)
{
	s32 i;

	for (i = 0; i < arg0 + 1; i++) {
		if ((g_WeatherData->unk58[i].unk08 > 0 && g_WeatherData->unk58[i].unk04 > 0.0f)
				|| (g_WeatherData->unk58[i].unk08 < 1 && g_WeatherData->unk58[i].unk00 > 0)) {
			g_WeatherData->unk58[i].unk04 = 0.0f;
			g_WeatherData->unk58[i].unk08 = 100;

			if (g_WeatherData->unk58[i].unk08 < 0) {
				g_WeatherData->unk58[i].unk08 = -g_WeatherData->unk58[i].unk08;
			}
		}
	}
}

void weatherSetIntensity(s32 intensity)
{
	s32 dotheloop = -1;
	s32 special = -1;
	s32 i;

	if (intensity == g_WeatherData->intensity) {
		return;
	}

	switch (g_WeatherData->type) {
	case WEATHERTYPE_RAIN:
		if (g_WeatherData->intensity == 0) {
			func0f131610(g_WeatherData);
		}

		special = -1;
		dotheloop = 1;

		switch (intensity) {
		case 0:
			g_WeatherData->unkd4 = 0;
			g_WeatherData->unkbc = 100;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			dotheloop = -1;
			g_WeatherData->unkc4 = -1;
			break;
		case 1:
			g_WeatherData->unkc8 = 15;
			g_WeatherData->unkd4 = 200;
			g_WeatherData->unkbc = 100;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			special = 0;
			g_WeatherData->unkc4 = 0.001f;
			break;
		case 2:
			g_WeatherData->unkc8 = 18;
			g_WeatherData->unkd4 = 400;
			g_WeatherData->unkbc = 150;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			special = 1;
			g_WeatherData->unkc4 = 0.01f;
			break;
		case 3:
			g_WeatherData->unkc8 = 30;
			g_WeatherData->unkd4 = 500;
			g_WeatherData->unkbc = 300;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			special = 2;
			g_WeatherData->unkc4 = 0.03f;
			break;
		}
		break;
	case WEATHERTYPE_SNOW:
		switch (intensity) {
		case 0:
			g_WeatherData->unkd4 = 0;
			break;
		case 1:
			g_WeatherData->unkd4 = 500;
			break;
		}
		break;
	}

	if (dotheloop >= 0) {
		for (i = 0; i != 3; i++) {
			if (i != special) {
				g_WeatherData->unk58[i].unk04 = 0;
				g_WeatherData->unk58[i].unk08 = 100;

				if (g_WeatherData->unk58[i].unk08 < 0) {
					g_WeatherData->unk58[i].unk08 = -g_WeatherData->unk58[i].unk08;
				}
			}
		}
	}

	if (special >= 0) {
		g_WeatherData->unk58[special].unk04 = 1;
		g_WeatherData->unk58[special].unk08 = 100;

		if (g_WeatherData->unk58[special].unk08 < 0) {
			g_WeatherData->unk58[special].unk08 = -g_WeatherData->unk58[special].unk08;
		}
	}

	g_WeatherData->intensity = intensity;
}

GLOBAL_ASM(
glabel weatherTickRain
.late_rodata
glabel var7f1b56dc
.word 0x46fffe00
glabel var7f1b56e0
.word 0x3fc90fdb
glabel var7f1b56e4
.word 0x40c90fdb
glabel var7f1b56e8
.word 0x3f7d70a4
glabel var7f1b56ec
.word 0x40490fdb
glabel var7f1b56f0
.word 0x3c23d70a
glabel var7f1b56f4
.word 0x3f333333
.text
/*  f131a30:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f131a34:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f131a38:	00809025 */ 	or	$s2,$a0,$zero
/*  f131a3c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f131a40:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f131a44:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f131a48:	3c047f1b */ 	lui	$a0,%hi(var7f1b5620)
/*  f131a4c:	3c058008 */ 	lui	$a1,%hi(var8007f0d4)
/*  f131a50:	0000b025 */ 	or	$s6,$zero,$zero
/*  f131a54:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f131a58:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f131a5c:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f131a60:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f131a64:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f131a68:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f131a6c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f131a70:	24a5f0d4 */ 	addiu	$a1,$a1,%lo(var8007f0d4)
/*  f131a74:	0c0036cc */ 	jal	func0000db30
/*  f131a78:	24845620 */ 	addiu	$a0,$a0,%lo(var7f1b5620)
/*  f131a7c:	8e420090 */ 	lw	$v0,0x90($s2)
/*  f131a80:	0240a025 */ 	or	$s4,$s2,$zero
/*  f131a84:	00009825 */ 	or	$s3,$zero,$zero
/*  f131a88:	18400009 */ 	blez	$v0,.L0f131ab0
/*  f131a8c:	02408025 */ 	or	$s0,$s2,$zero
/*  f131a90:	44824000 */ 	mtc1	$v0,$f8
/*  f131a94:	c6400088 */ 	lwc1	$f0,0x88($s2)
/*  f131a98:	c644008c */ 	lwc1	$f4,0x8c($s2)
/*  f131a9c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f131aa0:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f131aa4:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f131aa8:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f131aac:	e6520088 */ 	swc1	$f18,0x88($s2)
.L0f131ab0:
/*  f131ab0:	8e430060 */ 	lw	$v1,0x60($s2)
/*  f131ab4:	244effff */ 	addiu	$t6,$v0,-1
/*  f131ab8:	ae4e0090 */ 	sw	$t6,0x90($s2)
/*  f131abc:	1860000b */ 	blez	$v1,.L0f131aec
/*  f131ac0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f131ac4:	44833000 */ 	mtc1	$v1,$f6
/*  f131ac8:	c6400058 */ 	lwc1	$f0,0x58($s2)
/*  f131acc:	c644005c */ 	lwc1	$f4,0x5c($s2)
/*  f131ad0:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f131ad4:	246fffff */ 	addiu	$t7,$v1,-1
/*  f131ad8:	ae4f0060 */ 	sw	$t7,0x60($s2)
/*  f131adc:	46002201 */ 	sub.s	$f8,$f4,$f0
/*  f131ae0:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f131ae4:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f131ae8:	e6520058 */ 	swc1	$f18,0x58($s2)
.L0f131aec:
/*  f131aec:	8e42006c */ 	lw	$v0,0x6c($s2)
/*  f131af0:	4481b000 */ 	mtc1	$at,$f22
/*  f131af4:	3c017f1b */ 	lui	$at,%hi(var7f1b56dc)
/*  f131af8:	5840000c */ 	blezl	$v0,.L0f131b2c
/*  f131afc:	8e420078 */ 	lw	$v0,0x78($s2)
/*  f131b00:	44824000 */ 	mtc1	$v0,$f8
/*  f131b04:	c6400064 */ 	lwc1	$f0,0x64($s2)
/*  f131b08:	c6440068 */ 	lwc1	$f4,0x68($s2)
/*  f131b0c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f131b10:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f131b14:	ae58006c */ 	sw	$t8,0x6c($s2)
/*  f131b18:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f131b1c:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f131b20:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f131b24:	e6520064 */ 	swc1	$f18,0x64($s2)
/*  f131b28:	8e420078 */ 	lw	$v0,0x78($s2)
.L0f131b2c:
/*  f131b2c:	1840000b */ 	blez	$v0,.L0f131b5c
/*  f131b30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131b34:	44823000 */ 	mtc1	$v0,$f6
/*  f131b38:	c6400070 */ 	lwc1	$f0,0x70($s2)
/*  f131b3c:	c6440074 */ 	lwc1	$f4,0x74($s2)
/*  f131b40:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f131b44:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f131b48:	ae590078 */ 	sw	$t9,0x78($s2)
/*  f131b4c:	46002201 */ 	sub.s	$f8,$f4,$f0
/*  f131b50:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f131b54:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f131b58:	e6520070 */ 	swc1	$f18,0x70($s2)
.L0f131b5c:
/*  f131b5c:	c43456dc */ 	lwc1	$f20,%lo(var7f1b56dc)($at)
.L0f131b60:
/*  f131b60:	3c098008 */ 	lui	$t1,%hi(var8007f0c4)
/*  f131b64:	2529f0c4 */ 	addiu	$t1,$t1,%lo(var8007f0c4)
/*  f131b68:	8d210000 */ 	lw	$at,0x0($t1)
/*  f131b6c:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*  f131b70:	27a8008c */ 	addiu	$t0,$sp,0x8c
/*  f131b74:	ad010000 */ 	sw	$at,0x0($t0)
/*  f131b78:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f131b7c:	8d2b000c */ 	lw	$t3,0xc($t1)
/*  f131b80:	8d210008 */ 	lw	$at,0x8($t1)
/*  f131b84:	ad0b000c */ 	sw	$t3,0xc($t0)
/*  f131b88:	ad010008 */ 	sw	$at,0x8($t0)
/*  f131b8c:	c6840058 */ 	lwc1	$f4,0x58($s4)
/*  f131b90:	c6480088 */ 	lwc1	$f8,0x88($s2)
/*  f131b94:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f131b98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131b9c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f131ba0:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f131ba4:	44118000 */ 	mfc1	$s1,$f16
/*  f131ba8:	0fc5b364 */ 	jal	getVar80084014
/*  f131bac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131bb0:	10400002 */ 	beqz	$v0,.L0f131bbc
/*  f131bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131bb8:	00008825 */ 	or	$s1,$zero,$zero
.L0f131bbc:
/*  f131bbc:	5a200034 */ 	blezl	$s1,.L0f131c90
/*  f131bc0:	8e040034 */ 	lw	$a0,0x34($s0)
/*  f131bc4:	8e040034 */ 	lw	$a0,0x34($s0)
/*  f131bc8:	03b31021 */ 	addu	$v0,$sp,$s3
/*  f131bcc:	14800012 */ 	bnez	$a0,.L0f131c18
/*  f131bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131bd4:	8c42008c */ 	lw	$v0,0x8c($v0)
/*  f131bd8:	26060034 */ 	addiu	$a2,$s0,0x34
/*  f131bdc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f131be0:	0440000d */ 	bltz	$v0,.L0f131c18
/*  f131be4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f131be8:	a64200f8 */ 	sh	$v0,0xf8($s2)
/*  f131bec:	864500f8 */ 	lh	$a1,0xf8($s2)
/*  f131bf0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f131bf4:	240effff */ 	addiu	$t6,$zero,-1
/*  f131bf8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f131bfc:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f131c00:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f131c04:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f131c08:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f131c0c:	0c004241 */ 	jal	func00010904
/*  f131c10:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f131c14:	8e040034 */ 	lw	$a0,0x34($s0)
.L0f131c18:
/*  f131c18:	50800022 */ 	beqzl	$a0,.L0f131ca4
/*  f131c1c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f131c20:	0c00cdfc */ 	jal	func000337f0
/*  f131c24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131c28:	1040001d */ 	beqz	$v0,.L0f131ca0
/*  f131c2c:	26040034 */ 	addiu	$a0,$s0,0x34
/*  f131c30:	00113080 */ 	sll	$a2,$s1,0x2
/*  f131c34:	00d13023 */ 	subu	$a2,$a2,$s1
/*  f131c38:	865900f8 */ 	lh	$t9,0xf8($s2)
/*  f131c3c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f131c40:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f131c44:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f131c48:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f131c4c:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f131c50:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f131c54:	00002825 */ 	or	$a1,$zero,$zero
/*  f131c58:	04c10003 */ 	bgez	$a2,.L0f131c68
/*  f131c5c:	0006c083 */ 	sra	$t8,$a2,0x2
/*  f131c60:	24c10003 */ 	addiu	$at,$a2,0x3
/*  f131c64:	0001c083 */ 	sra	$t8,$at,0x2
.L0f131c68:
/*  f131c68:	3c013f80 */ 	lui	$at,0x3f80
/*  f131c6c:	44819000 */ 	mtc1	$at,$f18
/*  f131c70:	03003025 */ 	or	$a2,$t8,$zero
/*  f131c74:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f131c78:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f131c7c:	0c004128 */ 	jal	func000104a0
/*  f131c80:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f131c84:	10000007 */ 	beqz	$zero,.L0f131ca4
/*  f131c88:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f131c8c:	8e040034 */ 	lw	$a0,0x34($s0)
.L0f131c90:
/*  f131c90:	50800004 */ 	beqzl	$a0,.L0f131ca4
/*  f131c94:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f131c98:	0c00cec9 */ 	jal	func00033b24
/*  f131c9c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f131ca0:
/*  f131ca0:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f131ca4:
/*  f131ca4:	24010010 */ 	addiu	$at,$zero,0x10
/*  f131ca8:	2694000c */ 	addiu	$s4,$s4,0xc
/*  f131cac:	1661ffac */ 	bne	$s3,$at,.L0f131b60
/*  f131cb0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f131cb4:	8e4200c0 */ 	lw	$v0,0xc0($s2)
/*  f131cb8:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f131cbc:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f131cc0:	18400015 */ 	blez	$v0,.L0f131d18
/*  f131cc4:	3c0c8008 */ 	lui	$t4,%hi(g_StageIndex)
/*  f131cc8:	8e830038 */ 	lw	$v1,0x38($s4)
/*  f131ccc:	0043082a */ 	slt	$at,$v0,$v1
/*  f131cd0:	50200005 */ 	beqzl	$at,.L0f131ce8
/*  f131cd4:	44825000 */ 	mtc1	$v0,$f10
/*  f131cd8:	c64400bc */ 	lwc1	$f4,0xbc($s2)
/*  f131cdc:	1000000e */ 	beqz	$zero,.L0f131d18
/*  f131ce0:	e64400b8 */ 	swc1	$f4,0xb8($s2)
/*  f131ce4:	44825000 */ 	mtc1	$v0,$f10
.L0f131ce8:
/*  f131ce8:	c64000b8 */ 	lwc1	$f0,0xb8($s2)
/*  f131cec:	c64600bc */ 	lwc1	$f6,0xbc($s2)
/*  f131cf0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f131cf4:	44832000 */ 	mtc1	$v1,$f4
/*  f131cf8:	00435823 */ 	subu	$t3,$v0,$v1
/*  f131cfc:	ae4b00c0 */ 	sw	$t3,0xc0($s2)
/*  f131d00:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f131d04:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f131d08:	46104483 */ 	div.s	$f18,$f8,$f16
/*  f131d0c:	46123282 */ 	mul.s	$f10,$f6,$f18
/*  f131d10:	460a0200 */ 	add.s	$f8,$f0,$f10
/*  f131d14:	e64800b8 */ 	swc1	$f8,0xb8($s2)
.L0f131d18:
/*  f131d18:	8d8cfc00 */ 	lw	$t4,%lo(g_StageIndex)($t4)
/*  f131d1c:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f131d20:	24010013 */ 	addiu	$at,$zero,0x13
/*  f131d24:	1581000c */ 	bne	$t4,$at,.L0f131d58
/*  f131d28:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f131d2c:	c6440014 */ 	lwc1	$f4,0x14($s2)
/*  f131d30:	3c017f1b */ 	lui	$at,%hi(var7f1b56e0)
/*  f131d34:	c43056e0 */ 	lwc1	$f16,%lo(var7f1b56e0)($at)
/*  f131d38:	4480b000 */ 	mtc1	$zero,$f22
/*  f131d3c:	3c012f80 */ 	lui	$at,0x2f80
/*  f131d40:	46002187 */ 	neg.s	$f6,$f4
/*  f131d44:	4481a000 */ 	mtc1	$at,$f20
/*  f131d48:	e6460004 */ 	swc1	$f6,0x4($s2)
/*  f131d4c:	e6500008 */ 	swc1	$f16,0x8($s2)
/*  f131d50:	1000005e */ 	beqz	$zero,.L0f131ecc
/*  f131d54:	e6560000 */ 	swc1	$f22,0x0($s2)
.L0f131d58:
/*  f131d58:	8e420010 */ 	lw	$v0,0x10($s2)
/*  f131d5c:	1840002e */ 	blez	$v0,.L0f131e18
/*  f131d60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131d64:	8e830038 */ 	lw	$v1,0x38($s4)
/*  f131d68:	0043082a */ 	slt	$at,$v0,$v1
/*  f131d6c:	50200005 */ 	beqzl	$at,.L0f131d84
/*  f131d70:	44828000 */ 	mtc1	$v0,$f16
/*  f131d74:	c652000c */ 	lwc1	$f18,0xc($s2)
/*  f131d78:	1000000e */ 	beqz	$zero,.L0f131db4
/*  f131d7c:	e6520008 */ 	swc1	$f18,0x8($s2)
/*  f131d80:	44828000 */ 	mtc1	$v0,$f16
.L0f131d84:
/*  f131d84:	c64c0008 */ 	lwc1	$f12,0x8($s2)
/*  f131d88:	c64a000c */ 	lwc1	$f10,0xc($s2)
/*  f131d8c:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f131d90:	44839000 */ 	mtc1	$v1,$f18
/*  f131d94:	00436823 */ 	subu	$t5,$v0,$v1
/*  f131d98:	ae4d0010 */ 	sw	$t5,0x10($s2)
/*  f131d9c:	460c5201 */ 	sub.s	$f8,$f10,$f12
/*  f131da0:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f131da4:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f131da8:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f131dac:	46106200 */ 	add.s	$f8,$f12,$f16
/*  f131db0:	e6480008 */ 	swc1	$f8,0x8($s2)
.L0f131db4:
/*  f131db4:	3c017f1b */ 	lui	$at,%hi(var7f1b56e4)
/*  f131db8:	c42456e4 */ 	lwc1	$f4,%lo(var7f1b56e4)($at)
/*  f131dbc:	c64c0008 */ 	lwc1	$f12,0x8($s2)
/*  f131dc0:	460c203c */ 	c.lt.s	$f4,$f12
/*  f131dc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131dc8:	45000005 */ 	bc1f	.L0f131de0
/*  f131dcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131dd0:	4480b000 */ 	mtc1	$zero,$f22
/*  f131dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131dd8:	e6560008 */ 	swc1	$f22,0x8($s2)
/*  f131ddc:	c64c0008 */ 	lwc1	$f12,0x8($s2)
.L0f131de0:
/*  f131de0:	0c0068f4 */ 	jal	cosf
/*  f131de4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131de8:	c6520014 */ 	lwc1	$f18,0x14($s2)
/*  f131dec:	c64c0008 */ 	lwc1	$f12,0x8($s2)
/*  f131df0:	46120282 */ 	mul.s	$f10,$f0,$f18
/*  f131df4:	0c0068f7 */ 	jal	sinf
/*  f131df8:	e64a0000 */ 	swc1	$f10,0x0($s2)
/*  f131dfc:	c6460014 */ 	lwc1	$f6,0x14($s2)
/*  f131e00:	3c012f80 */ 	lui	$at,0x2f80
/*  f131e04:	4481a000 */ 	mtc1	$at,$f20
/*  f131e08:	46060402 */ 	mul.s	$f16,$f0,$f6
/*  f131e0c:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f131e10:	1000002e */ 	beqz	$zero,.L0f131ecc
/*  f131e14:	e6500004 */ 	swc1	$f16,0x4($s2)
.L0f131e18:
/*  f131e18:	0c004b70 */ 	jal	random
/*  f131e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131e20:	3c012f80 */ 	lui	$at,0x2f80
/*  f131e24:	44822000 */ 	mtc1	$v0,$f4
/*  f131e28:	4481a000 */ 	mtc1	$at,$f20
/*  f131e2c:	3c017f1b */ 	lui	$at,%hi(var7f1b56e8)
/*  f131e30:	c42856e8 */ 	lwc1	$f8,%lo(var7f1b56e8)($at)
/*  f131e34:	04410005 */ 	bgez	$v0,.L0f131e4c
/*  f131e38:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f131e3c:	3c014f80 */ 	lui	$at,0x4f80
/*  f131e40:	44815000 */ 	mtc1	$at,$f10
/*  f131e44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131e48:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f131e4c:
/*  f131e4c:	46149182 */ 	mul.s	$f6,$f18,$f20
/*  f131e50:	4606403c */ 	c.lt.s	$f8,$f6
/*  f131e54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131e58:	4500001c */ 	bc1f	.L0f131ecc
/*  f131e5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131e60:	0c004b70 */ 	jal	random
/*  f131e64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131e68:	44828000 */ 	mtc1	$v0,$f16
/*  f131e6c:	3c014f80 */ 	lui	$at,0x4f80
/*  f131e70:	04410004 */ 	bgez	$v0,.L0f131e84
/*  f131e74:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f131e78:	44815000 */ 	mtc1	$at,$f10
/*  f131e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131e80:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f131e84:
/*  f131e84:	46142002 */ 	mul.s	$f0,$f4,$f20
/*  f131e88:	3c017f1b */ 	lui	$at,%hi(var7f1b56ec)
/*  f131e8c:	c42856ec */ 	lwc1	$f8,%lo(var7f1b56ec)($at)
/*  f131e90:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f131e94:	3c017f1b */ 	lui	$at,%hi(var7f1b56f0)
/*  f131e98:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f131e9c:	46089082 */ 	mul.s	$f2,$f18,$f8
/*  f131ea0:	46061401 */ 	sub.s	$f16,$f2,$f6
/*  f131ea4:	e642000c */ 	swc1	$f2,0xc($s2)
/*  f131ea8:	c42a56f0 */ 	lwc1	$f10,%lo(var7f1b56f0)($at)
/*  f131eac:	460a8103 */ 	div.s	$f4,$f16,$f10
/*  f131eb0:	4600248d */ 	trunc.w.s	$f18,$f4
/*  f131eb4:	44039000 */ 	mfc1	$v1,$f18
/*  f131eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131ebc:	04610003 */ 	bgez	$v1,.L0f131ecc
/*  f131ec0:	ae430010 */ 	sw	$v1,0x10($s2)
/*  f131ec4:	0003c023 */ 	negu	$t8,$v1
/*  f131ec8:	ae580010 */ 	sw	$t8,0x10($s2)
.L0f131ecc:
/*  f131ecc:	3c198008 */ 	lui	$t9,%hi(g_WeatherData)
/*  f131ed0:	8f39f0c0 */ 	lw	$t9,%lo(g_WeatherData)($t9)
/*  f131ed4:	4480b000 */ 	mtc1	$zero,$f22
/*  f131ed8:	00009825 */ 	or	$s3,$zero,$zero
/*  f131edc:	8f310024 */ 	lw	$s1,0x24($t9)
/*  f131ee0:	02208025 */ 	or	$s0,$s1,$zero
.L0f131ee4:
/*  f131ee4:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f131ee8:	c6860044 */ 	lwc1	$f6,0x44($s4)
/*  f131eec:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f131ef0:	c6120014 */ 	lwc1	$f18,0x14($s0)
/*  f131ef4:	46064402 */ 	mul.s	$f16,$f8,$f6
/*  f131ef8:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f131efc:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f131f00:	e6040000 */ 	swc1	$f4,0x0($s0)
/*  f131f04:	c6880044 */ 	lwc1	$f8,0x44($s4)
/*  f131f08:	c6040018 */ 	lwc1	$f4,0x18($s0)
/*  f131f0c:	46089182 */ 	mul.s	$f6,$f18,$f8
/*  f131f10:	46065400 */ 	add.s	$f16,$f10,$f6
/*  f131f14:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f131f18:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f131f1c:	c6920044 */ 	lwc1	$f18,0x44($s4)
/*  f131f20:	c6100004 */ 	lwc1	$f16,0x4($s0)
/*  f131f24:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f131f28:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f131f2c:	e6060008 */ 	swc1	$f6,0x8($s0)
/*  f131f30:	c6243e9c */ 	lwc1	$f4,0x3e9c($s1)
/*  f131f34:	4604803c */ 	c.lt.s	$f16,$f4
/*  f131f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131f3c:	45000083 */ 	bc1f	.L0f13214c
/*  f131f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131f44:	0c004b70 */ 	jal	random
/*  f131f48:	24160002 */ 	addiu	$s6,$zero,0x2
/*  f131f4c:	c62c3e98 */ 	lwc1	$f12,0x3e98($s1)
/*  f131f50:	00401825 */ 	or	$v1,$v0,$zero
/*  f131f54:	44835000 */ 	mtc1	$v1,$f10
/*  f131f58:	460cb03c */ 	c.lt.s	$f22,$f12
/*  f131f5c:	3c014f80 */ 	lui	$at,0x4f80
/*  f131f60:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f131f64:	45020004 */ 	bc1fl	.L0f131f78
/*  f131f68:	46006387 */ 	neg.s	$f14,$f12
/*  f131f6c:	10000002 */ 	beqz	$zero,.L0f131f78
/*  f131f70:	46006386 */ 	mov.s	$f14,$f12
/*  f131f74:	46006387 */ 	neg.s	$f14,$f12
.L0f131f78:
/*  f131f78:	c6203e8c */ 	lwc1	$f0,0x3e8c($s1)
/*  f131f7c:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f131f80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131f84:	45020004 */ 	bc1fl	.L0f131f98
/*  f131f88:	46000087 */ 	neg.s	$f2,$f0
/*  f131f8c:	10000002 */ 	beqz	$zero,.L0f131f98
/*  f131f90:	46000086 */ 	mov.s	$f2,$f0
/*  f131f94:	46000087 */ 	neg.s	$f2,$f0
.L0f131f98:
/*  f131f98:	04610004 */ 	bgez	$v1,.L0f131fac
/*  f131f9c:	460e1480 */ 	add.s	$f18,$f2,$f14
/*  f131fa0:	44813000 */ 	mtc1	$at,$f6
/*  f131fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131fa8:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f131fac:
/*  f131fac:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f131fb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131fb4:	46109102 */ 	mul.s	$f4,$f18,$f16
/*  f131fb8:	460c2280 */ 	add.s	$f10,$f4,$f12
/*  f131fbc:	0c004b70 */ 	jal	random
/*  f131fc0:	e60a0000 */ 	swc1	$f10,0x0($s0)
/*  f131fc4:	c62c3ea0 */ 	lwc1	$f12,0x3ea0($s1)
/*  f131fc8:	00401825 */ 	or	$v1,$v0,$zero
/*  f131fcc:	44834000 */ 	mtc1	$v1,$f8
/*  f131fd0:	460cb03c */ 	c.lt.s	$f22,$f12
/*  f131fd4:	3c014f80 */ 	lui	$at,0x4f80
/*  f131fd8:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f131fdc:	45020004 */ 	bc1fl	.L0f131ff0
/*  f131fe0:	46006387 */ 	neg.s	$f14,$f12
/*  f131fe4:	10000002 */ 	beqz	$zero,.L0f131ff0
/*  f131fe8:	46006386 */ 	mov.s	$f14,$f12
/*  f131fec:	46006387 */ 	neg.s	$f14,$f12
.L0f131ff0:
/*  f131ff0:	c6203e94 */ 	lwc1	$f0,0x3e94($s1)
/*  f131ff4:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f131ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f131ffc:	45020004 */ 	bc1fl	.L0f132010
/*  f132000:	46000087 */ 	neg.s	$f2,$f0
/*  f132004:	10000002 */ 	beqz	$zero,.L0f132010
/*  f132008:	46000086 */ 	mov.s	$f2,$f0
/*  f13200c:	46000087 */ 	neg.s	$f2,$f0
.L0f132010:
/*  f132010:	04610004 */ 	bgez	$v1,.L0f132024
/*  f132014:	460e1180 */ 	add.s	$f6,$f2,$f14
/*  f132018:	44818000 */ 	mtc1	$at,$f16
/*  f13201c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132020:	46109480 */ 	add.s	$f18,$f18,$f16
.L0f132024:
/*  f132024:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f132028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13202c:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f132030:	460c5200 */ 	add.s	$f8,$f10,$f12
/*  f132034:	0c004b70 */ 	jal	random
/*  f132038:	e6080008 */ 	swc1	$f8,0x8($s0)
/*  f13203c:	44828000 */ 	mtc1	$v0,$f16
/*  f132040:	3c014f80 */ 	lui	$at,0x4f80
/*  f132044:	04410004 */ 	bgez	$v0,.L0f132058
/*  f132048:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f13204c:	44813000 */ 	mtc1	$at,$f6
/*  f132050:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132054:	46069480 */ 	add.s	$f18,$f18,$f6
.L0f132058:
/*  f132058:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f13205c:	3c017f1b */ 	lui	$at,%hi(var7f1b56f4)
/*  f132060:	c42a56f4 */ 	lwc1	$f10,%lo(var7f1b56f4)($at)
/*  f132064:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f132068:	0c004b70 */ 	jal	random
/*  f13206c:	e608001c */ 	swc1	$f8,0x1c($s0)
/*  f132070:	44828000 */ 	mtc1	$v0,$f16
/*  f132074:	3c0a8008 */ 	lui	$t2,%hi(var8007f0d4)
/*  f132078:	04410005 */ 	bgez	$v0,.L0f132090
/*  f13207c:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f132080:	3c014f80 */ 	lui	$at,0x4f80
/*  f132084:	44819000 */ 	mtc1	$at,$f18
/*  f132088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13208c:	46123180 */ 	add.s	$f6,$f6,$f18
.L0f132090:
/*  f132090:	8d4af0d4 */ 	lw	$t2,%lo(var8007f0d4)($t2)
/*  f132094:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f132098:	3c014f80 */ 	lui	$at,0x4f80
/*  f13209c:	448a5000 */ 	mtc1	$t2,$f10
/*  f1320a0:	00151823 */ 	negu	$v1,$s5
/*  f1320a4:	05410004 */ 	bgez	$t2,.L0f1320b8
/*  f1320a8:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f1320ac:	44818000 */ 	mtc1	$at,$f16
/*  f1320b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1320b4:	46104200 */ 	add.s	$f8,$f8,$f16
.L0f1320b8:
/*  f1320b8:	46082482 */ 	mul.s	$f18,$f4,$f8
/*  f1320bc:	c64600c8 */ 	lwc1	$f6,0xc8($s2)
/*  f1320c0:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f1320c4:	46005407 */ 	neg.s	$f16,$f10
/*  f1320c8:	1aa00003 */ 	blez	$s5,.L0f1320d8
/*  f1320cc:	e6100014 */ 	swc1	$f16,0x14($s0)
/*  f1320d0:	10000001 */ 	beqz	$zero,.L0f1320d8
/*  f1320d4:	02a01825 */ 	or	$v1,$s5,$zero
.L0f1320d8:
/*  f1320d8:	28610002 */ 	slti	$at,$v1,0x2
/*  f1320dc:	1020001b */ 	beqz	$at,.L0f13214c
/*  f1320e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1320e4:	8e4200d4 */ 	lw	$v0,0xd4($s2)
/*  f1320e8:	8e4300d0 */ 	lw	$v1,0xd0($s2)
/*  f1320ec:	10430017 */ 	beq	$v0,$v1,.L0f13214c
/*  f1320f0:	0062082a */ 	slt	$at,$v1,$v0
/*  f1320f4:	5020000d */ 	beqzl	$at,.L0f13212c
/*  f1320f8:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f1320fc:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f132100:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f132104:	31090003 */ 	andi	$t1,$t0,0x3
/*  f132108:	15200010 */ 	bnez	$t1,.L0f13214c
/*  f13210c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132110:	ae0b000c */ 	sw	$t3,0xc($s0)
/*  f132114:	8e4c00d0 */ 	lw	$t4,0xd0($s2)
/*  f132118:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f13211c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f132120:	1000000a */ 	beqz	$zero,.L0f13214c
/*  f132124:	ae4d00d0 */ 	sw	$t5,0xd0($s2)
/*  f132128:	8e0e000c */ 	lw	$t6,0xc($s0)
.L0f13212c:
/*  f13212c:	31cf0003 */ 	andi	$t7,$t6,0x3
/*  f132130:	11e00006 */ 	beqz	$t7,.L0f13214c
/*  f132134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132138:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f13213c:	8e5800d0 */ 	lw	$t8,0xd0($s2)
/*  f132140:	26b5ffff */ 	addiu	$s5,$s5,-1
/*  f132144:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f132148:	ae5900d0 */ 	sw	$t9,0xd0($s2)
.L0f13214c:
/*  f13214c:	1ac00008 */ 	blez	$s6,.L0f132170
/*  f132150:	26730020 */ 	addiu	$s3,$s3,0x20
/*  f132154:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*  f132158:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f13215c:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f132160:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f132164:	c6520004 */ 	lwc1	$f18,0x4($s2)
/*  f132168:	46009182 */ 	mul.s	$f6,$f18,$f0
/*  f13216c:	e6060018 */ 	swc1	$f6,0x18($s0)
.L0f132170:
/*  f132170:	24013e80 */ 	addiu	$at,$zero,0x3e80
/*  f132174:	1661ff5b */ 	bne	$s3,$at,.L0f131ee4
/*  f132178:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f13217c:	8e4a00cc */ 	lw	$t2,0xcc($s2)
/*  f132180:	55400008 */ 	bnezl	$t2,.L0f1321a4
/*  f132184:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f132188:	8e4800d0 */ 	lw	$t0,0xd0($s2)
/*  f13218c:	29010064 */ 	slti	$at,$t0,0x64
/*  f132190:	50200004 */ 	beqzl	$at,.L0f1321a4
/*  f132194:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f132198:	0fc4c59e */ 	jal	func0f131678
/*  f13219c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f1321a0:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f1321a4:
/*  f1321a4:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f1321a8:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f1321ac:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f1321b0:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f1321b4:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f1321b8:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f1321bc:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f1321c0:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f1321c4:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f1321c8:	03e00008 */ 	jr	$ra
/*  f1321cc:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel weatherTickSnow
.late_rodata
glabel var7f1b56f8
.word 0x3fc90fdb
glabel var7f1b56fc
.word 0x40c90fdb
glabel var7f1b5700
.word 0x40c90fdb
glabel var7f1b5704
.word 0x40c90fdb
glabel var7f1b5708
.word 0x3f7d70a4
glabel var7f1b570c
.word 0x40490fdb
glabel var7f1b5710
.word 0x3c23d70a
glabel var7f1b5714
.word 0x40c90fdb
glabel var7f1b5718
.word 0x3d23d70a
glabel var7f1b571c
.word 0xbcf5c28f
glabel var7f1b5720
.word 0x3cf5c28f
glabel var7f1b5724
.word 0x3ca3d70a
glabel var7f1b5728
.word 0x3c23d70a
glabel var7f1b572c
.word 0xbc23d70a
glabel var7f1b5730
.word 0xbca3d70a
glabel var7f1b5734
.word 0x3f333333
.text
/*  f1321d0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1321d4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f1321d8:	00809025 */ 	or	$s2,$a0,$zero
/*  f1321dc:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1321e0:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f1321e4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f1321e8:	3c047f1b */ 	lui	$a0,%hi(var7f1b5630)
/*  f1321ec:	3c058008 */ 	lui	$a1,%hi(var8007f0d8)
/*  f1321f0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1321f4:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f1321f8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f1321fc:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f132200:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f132204:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f132208:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f13220c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f132210:	24a5f0d8 */ 	addiu	$a1,$a1,%lo(var8007f0d8)
/*  f132214:	0c0036cc */ 	jal	func0000db30
/*  f132218:	24845630 */ 	addiu	$a0,$a0,%lo(var7f1b5630)
/*  f13221c:	3c047f1b */ 	lui	$a0,%hi(var7f1b563c)
/*  f132220:	3c058008 */ 	lui	$a1,%hi(var8007f0dc)
/*  f132224:	24a5f0dc */ 	addiu	$a1,$a1,%lo(var8007f0dc)
/*  f132228:	0c0036cc */ 	jal	func0000db30
/*  f13222c:	2484563c */ 	addiu	$a0,$a0,%lo(var7f1b563c)
/*  f132230:	3c0e8008 */ 	lui	$t6,%hi(g_StageIndex)
/*  f132234:	8dcefc00 */ 	lw	$t6,%lo(g_StageIndex)($t6)
/*  f132238:	24010013 */ 	addiu	$at,$zero,0x13
/*  f13223c:	55c1000d */ 	bnel	$t6,$at,.L0f132274
/*  f132240:	8e420010 */ 	lw	$v0,0x10($s2)
/*  f132244:	c6460014 */ 	lwc1	$f6,0x14($s2)
/*  f132248:	3c017f1b */ 	lui	$at,%hi(var7f1b56f8)
/*  f13224c:	c42456f8 */ 	lwc1	$f4,%lo(var7f1b56f8)($at)
/*  f132250:	4480a000 */ 	mtc1	$zero,$f20
/*  f132254:	3c012f80 */ 	lui	$at,0x2f80
/*  f132258:	46003207 */ 	neg.s	$f8,$f6
/*  f13225c:	4481b000 */ 	mtc1	$at,$f22
/*  f132260:	e6480004 */ 	swc1	$f8,0x4($s2)
/*  f132264:	e6440008 */ 	swc1	$f4,0x8($s2)
/*  f132268:	10000060 */ 	beqz	$zero,.L0f1323ec
/*  f13226c:	e6540000 */ 	swc1	$f20,0x0($s2)
/*  f132270:	8e420010 */ 	lw	$v0,0x10($s2)
.L0f132274:
/*  f132274:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f132278:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f13227c:	1840002e */ 	blez	$v0,.L0f132338
/*  f132280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132284:	8ea30038 */ 	lw	$v1,0x38($s5)
/*  f132288:	0043082a */ 	slt	$at,$v0,$v1
/*  f13228c:	50200005 */ 	beqzl	$at,.L0f1322a4
/*  f132290:	44822000 */ 	mtc1	$v0,$f4
/*  f132294:	c64a000c */ 	lwc1	$f10,0xc($s2)
/*  f132298:	1000000e */ 	beqz	$zero,.L0f1322d4
/*  f13229c:	e64a0008 */ 	swc1	$f10,0x8($s2)
/*  f1322a0:	44822000 */ 	mtc1	$v0,$f4
.L0f1322a4:
/*  f1322a4:	c64c0008 */ 	lwc1	$f12,0x8($s2)
/*  f1322a8:	c650000c */ 	lwc1	$f16,0xc($s2)
/*  f1322ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1322b0:	44835000 */ 	mtc1	$v1,$f10
/*  f1322b4:	00437823 */ 	subu	$t7,$v0,$v1
/*  f1322b8:	ae4f0010 */ 	sw	$t7,0x10($s2)
/*  f1322bc:	460c8481 */ 	sub.s	$f18,$f16,$f12
/*  f1322c0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1322c4:	46069203 */ 	div.s	$f8,$f18,$f6
/*  f1322c8:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f1322cc:	46046480 */ 	add.s	$f18,$f12,$f4
/*  f1322d0:	e6520008 */ 	swc1	$f18,0x8($s2)
.L0f1322d4:
/*  f1322d4:	3c017f1b */ 	lui	$at,%hi(var7f1b56fc)
/*  f1322d8:	c42256fc */ 	lwc1	$f2,%lo(var7f1b56fc)($at)
/*  f1322dc:	c64c0008 */ 	lwc1	$f12,0x8($s2)
/*  f1322e0:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1322e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1322e8:	45000005 */ 	bc1f	.L0f132300
/*  f1322ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1322f0:	4480a000 */ 	mtc1	$zero,$f20
/*  f1322f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1322f8:	e6540008 */ 	swc1	$f20,0x8($s2)
/*  f1322fc:	c64c0008 */ 	lwc1	$f12,0x8($s2)
.L0f132300:
/*  f132300:	0c0068f4 */ 	jal	cosf
/*  f132304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132308:	c6460014 */ 	lwc1	$f6,0x14($s2)
/*  f13230c:	c64c0008 */ 	lwc1	$f12,0x8($s2)
/*  f132310:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f132314:	0c0068f7 */ 	jal	sinf
/*  f132318:	e64a0000 */ 	swc1	$f10,0x0($s2)
/*  f13231c:	c6500014 */ 	lwc1	$f16,0x14($s2)
/*  f132320:	3c012f80 */ 	lui	$at,0x2f80
/*  f132324:	4481b000 */ 	mtc1	$at,$f22
/*  f132328:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f13232c:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f132330:	1000002e */ 	beqz	$zero,.L0f1323ec
/*  f132334:	e6480004 */ 	swc1	$f8,0x4($s2)
.L0f132338:
/*  f132338:	0c004b70 */ 	jal	random
/*  f13233c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132340:	3c012f80 */ 	lui	$at,0x2f80
/*  f132344:	44829000 */ 	mtc1	$v0,$f18
/*  f132348:	4481b000 */ 	mtc1	$at,$f22
/*  f13234c:	3c017f1b */ 	lui	$at,%hi(var7f1b5708)
/*  f132350:	c4245708 */ 	lwc1	$f4,%lo(var7f1b5708)($at)
/*  f132354:	04410005 */ 	bgez	$v0,.L0f13236c
/*  f132358:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f13235c:	3c014f80 */ 	lui	$at,0x4f80
/*  f132360:	44815000 */ 	mtc1	$at,$f10
/*  f132364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132368:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f13236c:
/*  f13236c:	46163402 */ 	mul.s	$f16,$f6,$f22
/*  f132370:	4610203c */ 	c.lt.s	$f4,$f16
/*  f132374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132378:	4500001c */ 	bc1f	.L0f1323ec
/*  f13237c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132380:	0c004b70 */ 	jal	random
/*  f132384:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132388:	44824000 */ 	mtc1	$v0,$f8
/*  f13238c:	3c014f80 */ 	lui	$at,0x4f80
/*  f132390:	04410004 */ 	bgez	$v0,.L0f1323a4
/*  f132394:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f132398:	44815000 */ 	mtc1	$at,$f10
/*  f13239c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1323a0:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f1323a4:
/*  f1323a4:	46169002 */ 	mul.s	$f0,$f18,$f22
/*  f1323a8:	3c017f1b */ 	lui	$at,%hi(var7f1b570c)
/*  f1323ac:	c424570c */ 	lwc1	$f4,%lo(var7f1b570c)($at)
/*  f1323b0:	c6500008 */ 	lwc1	$f16,0x8($s2)
/*  f1323b4:	3c017f1b */ 	lui	$at,%hi(var7f1b5710)
/*  f1323b8:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f1323bc:	46043082 */ 	mul.s	$f2,$f6,$f4
/*  f1323c0:	46101201 */ 	sub.s	$f8,$f2,$f16
/*  f1323c4:	e642000c */ 	swc1	$f2,0xc($s2)
/*  f1323c8:	c42a5710 */ 	lwc1	$f10,%lo(var7f1b5710)($at)
/*  f1323cc:	460a4483 */ 	div.s	$f18,$f8,$f10
/*  f1323d0:	4600918d */ 	trunc.w.s	$f6,$f18
/*  f1323d4:	44033000 */ 	mfc1	$v1,$f6
/*  f1323d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1323dc:	04610003 */ 	bgez	$v1,.L0f1323ec
/*  f1323e0:	ae430010 */ 	sw	$v1,0x10($s2)
/*  f1323e4:	00034023 */ 	negu	$t0,$v1
/*  f1323e8:	ae480010 */ 	sw	$t0,0x10($s2)
.L0f1323ec:
/*  f1323ec:	3c017f1b */ 	lui	$at,%hi(var7f1b5714)
/*  f1323f0:	c4225714 */ 	lwc1	$f2,%lo(var7f1b5714)($at)
/*  f1323f4:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f1323f8:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f1323fc:	3c017f1b */ 	lui	$at,%hi(var7f1b5718)
/*  f132400:	c42c5718 */ 	lwc1	$f12,%lo(var7f1b5718)($at)
/*  f132404:	c6b00044 */ 	lwc1	$f16,0x44($s5)
/*  f132408:	3c098008 */ 	lui	$t1,%hi(g_WeatherData)
/*  f13240c:	8d29f0c0 */ 	lw	$t1,%lo(g_WeatherData)($t1)
/*  f132410:	46106202 */ 	mul.s	$f8,$f12,$f16
/*  f132414:	4480a000 */ 	mtc1	$zero,$f20
/*  f132418:	8d310024 */ 	lw	$s1,0x24($t1)
/*  f13241c:	3c017f1b */ 	lui	$at,%hi(var7f1b571c)
/*  f132420:	c6243ec8 */ 	lwc1	$f4,0x3ec8($s1)
/*  f132424:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f132428:	e62a3ec8 */ 	swc1	$f10,0x3ec8($s1)
/*  f13242c:	c6203ec8 */ 	lwc1	$f0,0x3ec8($s1)
/*  f132430:	4614003c */ 	c.lt.s	$f0,$f20
/*  f132434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132438:	45020005 */ 	bc1fl	.L0f132450
/*  f13243c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f132440:	46020480 */ 	add.s	$f18,$f0,$f2
/*  f132444:	e6323ec8 */ 	swc1	$f18,0x3ec8($s1)
/*  f132448:	c6203ec8 */ 	lwc1	$f0,0x3ec8($s1)
/*  f13244c:	4600103c */ 	c.lt.s	$f2,$f0
.L0f132450:
/*  f132450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132454:	45000003 */ 	bc1f	.L0f132464
/*  f132458:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13245c:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f132460:	e6263ec8 */ 	swc1	$f6,0x3ec8($s1)
.L0f132464:
/*  f132464:	c430571c */ 	lwc1	$f16,%lo(var7f1b571c)($at)
/*  f132468:	c6a40044 */ 	lwc1	$f4,0x44($s5)
/*  f13246c:	c62a3ecc */ 	lwc1	$f10,0x3ecc($s1)
/*  f132470:	3c017f1b */ 	lui	$at,%hi(var7f1b5720)
/*  f132474:	46048202 */ 	mul.s	$f8,$f16,$f4
/*  f132478:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f13247c:	e6323ecc */ 	swc1	$f18,0x3ecc($s1)
/*  f132480:	c6203ecc */ 	lwc1	$f0,0x3ecc($s1)
/*  f132484:	4614003c */ 	c.lt.s	$f0,$f20
/*  f132488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13248c:	45020005 */ 	bc1fl	.L0f1324a4
/*  f132490:	4600103c */ 	c.lt.s	$f2,$f0
/*  f132494:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f132498:	e6263ecc */ 	swc1	$f6,0x3ecc($s1)
/*  f13249c:	c6203ecc */ 	lwc1	$f0,0x3ecc($s1)
/*  f1324a0:	4600103c */ 	c.lt.s	$f2,$f0
.L0f1324a4:
/*  f1324a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1324a8:	45020004 */ 	bc1fl	.L0f1324bc
/*  f1324ac:	c6aa0044 */ 	lwc1	$f10,0x44($s5)
/*  f1324b0:	46020401 */ 	sub.s	$f16,$f0,$f2
/*  f1324b4:	e6303ecc */ 	swc1	$f16,0x3ecc($s1)
/*  f1324b8:	c6aa0044 */ 	lwc1	$f10,0x44($s5)
.L0f1324bc:
/*  f1324bc:	c6243ed0 */ 	lwc1	$f4,0x3ed0($s1)
/*  f1324c0:	460a6202 */ 	mul.s	$f8,$f12,$f10
/*  f1324c4:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f1324c8:	e6323ed0 */ 	swc1	$f18,0x3ed0($s1)
/*  f1324cc:	c6203ed0 */ 	lwc1	$f0,0x3ed0($s1)
/*  f1324d0:	4614003c */ 	c.lt.s	$f0,$f20
/*  f1324d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1324d8:	45020005 */ 	bc1fl	.L0f1324f0
/*  f1324dc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f1324e0:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f1324e4:	e6263ed0 */ 	swc1	$f6,0x3ed0($s1)
/*  f1324e8:	c6203ed0 */ 	lwc1	$f0,0x3ed0($s1)
/*  f1324ec:	4600103c */ 	c.lt.s	$f2,$f0
.L0f1324f0:
/*  f1324f0:	00009825 */ 	or	$s3,$zero,$zero
/*  f1324f4:	02208025 */ 	or	$s0,$s1,$zero
/*  f1324f8:	45000003 */ 	bc1f	.L0f132508
/*  f1324fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132500:	46020401 */ 	sub.s	$f16,$f0,$f2
/*  f132504:	e6303ed0 */ 	swc1	$f16,0x3ed0($s1)
.L0f132508:
/*  f132508:	c42a5720 */ 	lwc1	$f10,%lo(var7f1b5720)($at)
/*  f13250c:	c6a40044 */ 	lwc1	$f4,0x44($s5)
/*  f132510:	c6323ed4 */ 	lwc1	$f18,0x3ed4($s1)
/*  f132514:	3c017f1b */ 	lui	$at,%hi(var7f1b5724)
/*  f132518:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f13251c:	46089180 */ 	add.s	$f6,$f18,$f8
/*  f132520:	e6263ed4 */ 	swc1	$f6,0x3ed4($s1)
/*  f132524:	c6203ed4 */ 	lwc1	$f0,0x3ed4($s1)
/*  f132528:	4614003c */ 	c.lt.s	$f0,$f20
/*  f13252c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132530:	45020005 */ 	bc1fl	.L0f132548
/*  f132534:	4600103c */ 	c.lt.s	$f2,$f0
/*  f132538:	46020400 */ 	add.s	$f16,$f0,$f2
/*  f13253c:	e6303ed4 */ 	swc1	$f16,0x3ed4($s1)
/*  f132540:	c6203ed4 */ 	lwc1	$f0,0x3ed4($s1)
/*  f132544:	4600103c */ 	c.lt.s	$f2,$f0
.L0f132548:
/*  f132548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13254c:	45000003 */ 	bc1f	.L0f13255c
/*  f132550:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132554:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f132558:	e62a3ed4 */ 	swc1	$f10,0x3ed4($s1)
.L0f13255c:
/*  f13255c:	c4245724 */ 	lwc1	$f4,%lo(var7f1b5724)($at)
/*  f132560:	c6b20044 */ 	lwc1	$f18,0x44($s5)
/*  f132564:	c6263ed8 */ 	lwc1	$f6,0x3ed8($s1)
/*  f132568:	3c017f1b */ 	lui	$at,%hi(var7f1b5728)
/*  f13256c:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f132570:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f132574:	e6303ed8 */ 	swc1	$f16,0x3ed8($s1)
/*  f132578:	c6203ed8 */ 	lwc1	$f0,0x3ed8($s1)
/*  f13257c:	4614003c */ 	c.lt.s	$f0,$f20
/*  f132580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132584:	45020005 */ 	bc1fl	.L0f13259c
/*  f132588:	4600103c */ 	c.lt.s	$f2,$f0
/*  f13258c:	46020280 */ 	add.s	$f10,$f0,$f2
/*  f132590:	e62a3ed8 */ 	swc1	$f10,0x3ed8($s1)
/*  f132594:	c6203ed8 */ 	lwc1	$f0,0x3ed8($s1)
/*  f132598:	4600103c */ 	c.lt.s	$f2,$f0
.L0f13259c:
/*  f13259c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1325a0:	45000003 */ 	bc1f	.L0f1325b0
/*  f1325a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1325a8:	46020101 */ 	sub.s	$f4,$f0,$f2
/*  f1325ac:	e6243ed8 */ 	swc1	$f4,0x3ed8($s1)
.L0f1325b0:
/*  f1325b0:	c4325728 */ 	lwc1	$f18,%lo(var7f1b5728)($at)
/*  f1325b4:	c6a60044 */ 	lwc1	$f6,0x44($s5)
/*  f1325b8:	c6303edc */ 	lwc1	$f16,0x3edc($s1)
/*  f1325bc:	3c017f1b */ 	lui	$at,%hi(var7f1b572c)
/*  f1325c0:	46069202 */ 	mul.s	$f8,$f18,$f6
/*  f1325c4:	46088280 */ 	add.s	$f10,$f16,$f8
/*  f1325c8:	e62a3edc */ 	swc1	$f10,0x3edc($s1)
/*  f1325cc:	c6203edc */ 	lwc1	$f0,0x3edc($s1)
/*  f1325d0:	4614003c */ 	c.lt.s	$f0,$f20
/*  f1325d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1325d8:	45020005 */ 	bc1fl	.L0f1325f0
/*  f1325dc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f1325e0:	46020100 */ 	add.s	$f4,$f0,$f2
/*  f1325e4:	e6243edc */ 	swc1	$f4,0x3edc($s1)
/*  f1325e8:	c6203edc */ 	lwc1	$f0,0x3edc($s1)
/*  f1325ec:	4600103c */ 	c.lt.s	$f2,$f0
.L0f1325f0:
/*  f1325f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1325f4:	45000003 */ 	bc1f	.L0f132604
/*  f1325f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1325fc:	46020481 */ 	sub.s	$f18,$f0,$f2
/*  f132600:	e6323edc */ 	swc1	$f18,0x3edc($s1)
.L0f132604:
/*  f132604:	c426572c */ 	lwc1	$f6,%lo(var7f1b572c)($at)
/*  f132608:	c6b00044 */ 	lwc1	$f16,0x44($s5)
/*  f13260c:	c62a3ee0 */ 	lwc1	$f10,0x3ee0($s1)
/*  f132610:	3c017f1b */ 	lui	$at,%hi(var7f1b5730)
/*  f132614:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f132618:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f13261c:	e6243ee0 */ 	swc1	$f4,0x3ee0($s1)
/*  f132620:	c6203ee0 */ 	lwc1	$f0,0x3ee0($s1)
/*  f132624:	4614003c */ 	c.lt.s	$f0,$f20
/*  f132628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13262c:	45020005 */ 	bc1fl	.L0f132644
/*  f132630:	4600103c */ 	c.lt.s	$f2,$f0
/*  f132634:	46020480 */ 	add.s	$f18,$f0,$f2
/*  f132638:	e6323ee0 */ 	swc1	$f18,0x3ee0($s1)
/*  f13263c:	c6203ee0 */ 	lwc1	$f0,0x3ee0($s1)
/*  f132640:	4600103c */ 	c.lt.s	$f2,$f0
.L0f132644:
/*  f132644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132648:	45000003 */ 	bc1f	.L0f132658
/*  f13264c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132650:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f132654:	e6263ee0 */ 	swc1	$f6,0x3ee0($s1)
.L0f132658:
/*  f132658:	c4305730 */ 	lwc1	$f16,%lo(var7f1b5730)($at)
/*  f13265c:	c6aa0044 */ 	lwc1	$f10,0x44($s5)
/*  f132660:	c6243ee4 */ 	lwc1	$f4,0x3ee4($s1)
/*  f132664:	460a8202 */ 	mul.s	$f8,$f16,$f10
/*  f132668:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f13266c:	e6323ee4 */ 	swc1	$f18,0x3ee4($s1)
/*  f132670:	c6203ee4 */ 	lwc1	$f0,0x3ee4($s1)
/*  f132674:	4614003c */ 	c.lt.s	$f0,$f20
/*  f132678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13267c:	45020005 */ 	bc1fl	.L0f132694
/*  f132680:	4600103c */ 	c.lt.s	$f2,$f0
/*  f132684:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f132688:	e6263ee4 */ 	swc1	$f6,0x3ee4($s1)
/*  f13268c:	c6203ee4 */ 	lwc1	$f0,0x3ee4($s1)
/*  f132690:	4600103c */ 	c.lt.s	$f2,$f0
.L0f132694:
/*  f132694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132698:	45000003 */ 	bc1f	.L0f1326a8
/*  f13269c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1326a0:	46020401 */ 	sub.s	$f16,$f0,$f2
/*  f1326a4:	e6303ee4 */ 	swc1	$f16,0x3ee4($s1)
.L0f1326a8:
/*  f1326a8:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f1326ac:	c6a40044 */ 	lwc1	$f4,0x44($s5)
/*  f1326b0:	c6120000 */ 	lwc1	$f18,0x0($s0)
/*  f1326b4:	c6100014 */ 	lwc1	$f16,0x14($s0)
/*  f1326b8:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f1326bc:	46089180 */ 	add.s	$f6,$f18,$f8
/*  f1326c0:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f1326c4:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f1326c8:	c6aa0044 */ 	lwc1	$f10,0x44($s5)
/*  f1326cc:	c6060018 */ 	lwc1	$f6,0x18($s0)
/*  f1326d0:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f1326d4:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f1326d8:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f1326dc:	e6080004 */ 	swc1	$f8,0x4($s0)
/*  f1326e0:	c6b00044 */ 	lwc1	$f16,0x44($s5)
/*  f1326e4:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f1326e8:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f1326ec:	460a9100 */ 	add.s	$f4,$f18,$f10
/*  f1326f0:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f1326f4:	c6263e9c */ 	lwc1	$f6,0x3e9c($s1)
/*  f1326f8:	4606403c */ 	c.lt.s	$f8,$f6
/*  f1326fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132700:	45000096 */ 	bc1f	.L0f13295c
/*  f132704:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132708:	0c004b70 */ 	jal	random
/*  f13270c:	24160002 */ 	addiu	$s6,$zero,0x2
/*  f132710:	c62c3e98 */ 	lwc1	$f12,0x3e98($s1)
/*  f132714:	00401825 */ 	or	$v1,$v0,$zero
/*  f132718:	44839000 */ 	mtc1	$v1,$f18
/*  f13271c:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f132720:	3c014f80 */ 	lui	$at,0x4f80
/*  f132724:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f132728:	45020004 */ 	bc1fl	.L0f13273c
/*  f13272c:	46006387 */ 	neg.s	$f14,$f12
/*  f132730:	10000002 */ 	beqz	$zero,.L0f13273c
/*  f132734:	46006386 */ 	mov.s	$f14,$f12
/*  f132738:	46006387 */ 	neg.s	$f14,$f12
.L0f13273c:
/*  f13273c:	c6203e8c */ 	lwc1	$f0,0x3e8c($s1)
/*  f132740:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f132744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132748:	45020004 */ 	bc1fl	.L0f13275c
/*  f13274c:	46000087 */ 	neg.s	$f2,$f0
/*  f132750:	10000002 */ 	beqz	$zero,.L0f13275c
/*  f132754:	46000086 */ 	mov.s	$f2,$f0
/*  f132758:	46000087 */ 	neg.s	$f2,$f0
.L0f13275c:
/*  f13275c:	04610004 */ 	bgez	$v1,.L0f132770
/*  f132760:	460e1400 */ 	add.s	$f16,$f2,$f14
/*  f132764:	44812000 */ 	mtc1	$at,$f4
/*  f132768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13276c:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f132770:
/*  f132770:	46165202 */ 	mul.s	$f8,$f10,$f22
/*  f132774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132778:	46088182 */ 	mul.s	$f6,$f16,$f8
/*  f13277c:	460c3480 */ 	add.s	$f18,$f6,$f12
/*  f132780:	0c004b70 */ 	jal	random
/*  f132784:	e6120000 */ 	swc1	$f18,0x0($s0)
/*  f132788:	c62c3ea0 */ 	lwc1	$f12,0x3ea0($s1)
/*  f13278c:	00401825 */ 	or	$v1,$v0,$zero
/*  f132790:	44835000 */ 	mtc1	$v1,$f10
/*  f132794:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f132798:	3c014f80 */ 	lui	$at,0x4f80
/*  f13279c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1327a0:	45020004 */ 	bc1fl	.L0f1327b4
/*  f1327a4:	46006387 */ 	neg.s	$f14,$f12
/*  f1327a8:	10000002 */ 	beqz	$zero,.L0f1327b4
/*  f1327ac:	46006386 */ 	mov.s	$f14,$f12
/*  f1327b0:	46006387 */ 	neg.s	$f14,$f12
.L0f1327b4:
/*  f1327b4:	c6203e94 */ 	lwc1	$f0,0x3e94($s1)
/*  f1327b8:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1327bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1327c0:	45020004 */ 	bc1fl	.L0f1327d4
/*  f1327c4:	46000087 */ 	neg.s	$f2,$f0
/*  f1327c8:	10000002 */ 	beqz	$zero,.L0f1327d4
/*  f1327cc:	46000086 */ 	mov.s	$f2,$f0
/*  f1327d0:	46000087 */ 	neg.s	$f2,$f0
.L0f1327d4:
/*  f1327d4:	04610004 */ 	bgez	$v1,.L0f1327e8
/*  f1327d8:	460e1100 */ 	add.s	$f4,$f2,$f14
/*  f1327dc:	44814000 */ 	mtc1	$at,$f8
/*  f1327e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1327e4:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f1327e8:
/*  f1327e8:	46168182 */ 	mul.s	$f6,$f16,$f22
/*  f1327ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1327f0:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f1327f4:	460c9280 */ 	add.s	$f10,$f18,$f12
/*  f1327f8:	0c004b70 */ 	jal	random
/*  f1327fc:	e60a0008 */ 	swc1	$f10,0x8($s0)
/*  f132800:	44824000 */ 	mtc1	$v0,$f8
/*  f132804:	3c014f80 */ 	lui	$at,0x4f80
/*  f132808:	04410004 */ 	bgez	$v0,.L0f13281c
/*  f13280c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f132810:	44812000 */ 	mtc1	$at,$f4
/*  f132814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132818:	46048400 */ 	add.s	$f16,$f16,$f4
.L0f13281c:
/*  f13281c:	46168182 */ 	mul.s	$f6,$f16,$f22
/*  f132820:	3c017f1b */ 	lui	$at,%hi(var7f1b5734)
/*  f132824:	c4325734 */ 	lwc1	$f18,%lo(var7f1b5734)($at)
/*  f132828:	46123280 */ 	add.s	$f10,$f6,$f18
/*  f13282c:	0c004b70 */ 	jal	random
/*  f132830:	e60a001c */ 	swc1	$f10,0x1c($s0)
/*  f132834:	44824000 */ 	mtc1	$v0,$f8
/*  f132838:	3c014120 */ 	lui	$at,0x4120
/*  f13283c:	44811000 */ 	mtc1	$at,$f2
/*  f132840:	04410005 */ 	bgez	$v0,.L0f132858
/*  f132844:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f132848:	3c014f80 */ 	lui	$at,0x4f80
/*  f13284c:	44818000 */ 	mtc1	$at,$f16
/*  f132850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132854:	46102100 */ 	add.s	$f4,$f4,$f16
.L0f132858:
/*  f132858:	3c0a8008 */ 	lui	$t2,%hi(var8007f0dc)
/*  f13285c:	8d4af0dc */ 	lw	$t2,%lo(var8007f0dc)($t2)
/*  f132860:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f132864:	3c014f80 */ 	lui	$at,0x4f80
/*  f132868:	448a9000 */ 	mtc1	$t2,$f18
/*  f13286c:	00141823 */ 	negu	$v1,$s4
/*  f132870:	05410004 */ 	bgez	$t2,.L0f132884
/*  f132874:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f132878:	44814000 */ 	mtc1	$at,$f8
/*  f13287c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132880:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f132884:
/*  f132884:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f132888:	3c0b8008 */ 	lui	$t3,%hi(var8007f0d8)
/*  f13288c:	8d6bf0d8 */ 	lw	$t3,%lo(var8007f0d8)($t3)
/*  f132890:	3c014f80 */ 	lui	$at,0x4f80
/*  f132894:	448b9000 */ 	mtc1	$t3,$f18
/*  f132898:	46028103 */ 	div.s	$f4,$f16,$f2
/*  f13289c:	05610004 */ 	bgez	$t3,.L0f1328b0
/*  f1328a0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f1328a4:	44813000 */ 	mtc1	$at,$f6
/*  f1328a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1328ac:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f1328b0:
/*  f1328b0:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f1328b4:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*  f1328b8:	46005407 */ 	neg.s	$f16,$f10
/*  f1328bc:	46048481 */ 	sub.s	$f18,$f16,$f4
/*  f1328c0:	e6120014 */ 	swc1	$f18,0x14($s0)
/*  f1328c4:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f1328c8:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f1328cc:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f1328d0:	c64a0004 */ 	lwc1	$f10,0x4($s2)
/*  f1328d4:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f1328d8:	1a800003 */ 	blez	$s4,.L0f1328e8
/*  f1328dc:	e6100018 */ 	swc1	$f16,0x18($s0)
/*  f1328e0:	10000001 */ 	beqz	$zero,.L0f1328e8
/*  f1328e4:	02801825 */ 	or	$v1,$s4,$zero
.L0f1328e8:
/*  f1328e8:	28610014 */ 	slti	$at,$v1,0x14
/*  f1328ec:	1020001b */ 	beqz	$at,.L0f13295c
/*  f1328f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1328f4:	8e4200d4 */ 	lw	$v0,0xd4($s2)
/*  f1328f8:	8e4300d0 */ 	lw	$v1,0xd0($s2)
/*  f1328fc:	10430017 */ 	beq	$v0,$v1,.L0f13295c
/*  f132900:	0062082a */ 	slt	$at,$v1,$v0
/*  f132904:	5020000d */ 	beqzl	$at,.L0f13293c
/*  f132908:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f13290c:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f132910:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f132914:	318d0003 */ 	andi	$t5,$t4,0x3
/*  f132918:	15a00010 */ 	bnez	$t5,.L0f13295c
/*  f13291c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132920:	ae0e000c */ 	sw	$t6,0xc($s0)
/*  f132924:	8e4f00d0 */ 	lw	$t7,0xd0($s2)
/*  f132928:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f13292c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f132930:	1000000a */ 	beqz	$zero,.L0f13295c
/*  f132934:	ae5800d0 */ 	sw	$t8,0xd0($s2)
/*  f132938:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f13293c:
/*  f13293c:	33280003 */ 	andi	$t0,$t9,0x3
/*  f132940:	11000006 */ 	beqz	$t0,.L0f13295c
/*  f132944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132948:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f13294c:	8e4900d0 */ 	lw	$t1,0xd0($s2)
/*  f132950:	2694ffff */ 	addiu	$s4,$s4,-1
/*  f132954:	252affff */ 	addiu	$t2,$t1,-1
/*  f132958:	ae4a00d0 */ 	sw	$t2,0xd0($s2)
.L0f13295c:
/*  f13295c:	1ac00008 */ 	blez	$s6,.L0f132980
/*  f132960:	26730020 */ 	addiu	$s3,$s3,0x20
/*  f132964:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*  f132968:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f13296c:	46002482 */ 	mul.s	$f18,$f4,$f0
/*  f132970:	e6120010 */ 	swc1	$f18,0x10($s0)
/*  f132974:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f132978:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f13297c:	e6080018 */ 	swc1	$f8,0x18($s0)
.L0f132980:
/*  f132980:	24013e80 */ 	addiu	$at,$zero,0x3e80
/*  f132984:	1661ff48 */ 	bne	$s3,$at,.L0f1326a8
/*  f132988:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f13298c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f132990:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f132994:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f132998:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f13299c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f1329a0:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f1329a4:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f1329a8:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f1329ac:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f1329b0:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f1329b4:	03e00008 */ 	jr	$ra
/*  f1329b8:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

void weatherConfigureRain(u32 intensity)
{
	if (g_WeatherData) {
		g_WeatherData->type = WEATHERTYPE_RAIN;
		weatherSetIntensity(intensity);
	}
}

void weatherConfigureSnow(u32 intensity)
{
	if (g_WeatherData) {
		g_WeatherData->type = WEATHERTYPE_SNOW;
		weatherSetIntensity(intensity);
	}
}

bool weatherIsRoomWeatherProof(u32 room)
{
	if (g_StageIndex == STAGEINDEX_CHICAGO) {
		// Rooms listed do not have weather
		if (room == 0x62
				|| room == 0x61
				|| room == 0x0f
				|| room == 0x52
				|| room == 0x45
				|| room == 0x44
				|| room == 0x43
				|| room == 0x3d
				|| room == 0x0e
				|| room == 0x0d
				|| room == 0x0c
				|| room == 0x0b
				|| room == 0x0a
				|| room == 0x09
				|| room == 0x08
				|| room == 0x07
				|| room == 0x06
				|| room == 0x05
				|| room == 0x04
				|| room == 0x37
				|| room == 0x5b
				|| room == 0x5f
				|| room == 0x60
				|| room == 0x5d
				|| room == 0x1d
				|| room == 0x1f
				|| room == 0x27
				|| room == 0x50
				|| room == 0x2c
				|| room == 0x2f
				|| room == 0x30
				|| room == 0x11
				|| room == 0x24
				|| room == 0x33
				|| room == 0x34
				|| room == 0x35
				|| room == 0x36
				|| room == 0x3c
				|| room == 0x46
				|| room == 0x47
				|| room == 0x49
				|| room == 0x55
				|| room == 0x56
				|| room == 0x5e
				|| room == 0x63
				|| room == 0x69
				|| room == 0x03
				|| room == 0x16
				|| room == 0x4f
				|| room == 0x4b
				|| room == 0x3f
				|| room == 0x13
				|| room == 0x19) {
			return true;
		}

		return false;
	}

	if (g_StageIndex == STAGEINDEX_AIRBASE) {
		// Rooms listed have weather
		if (room == 0x88
				|| room == 0x91
				|| room == 0x87
				|| room == 0x90
				|| room == 0x86
				|| room == 0x80
				|| room == 0x83
				|| room == 0x84
				|| room == 0x85
				|| room == 0x7f
				|| room == 0x7e
				|| room == 0x82
				|| room == 0x8f
				|| room == 0x8e
				|| room == 0x7b
				|| room == 0x7c
				|| room == 0x7d
				|| room == 0x81
				|| room == 0x6f) {
			return false;
		}

		return true;
	}

	if (g_StageIndex == STAGEINDEX_CRASHSITE) {
		// Rooms listed do not have weather
		if (room == 0x1f
				|| room == 0x20
				|| room == 0x21
				|| room == 0x22
				|| room == 0x23
				|| room == 0x24
				|| room == 0x51
				|| room == 0x52
				|| room == 0x53
				|| room == 0x54
				|| room == 0x55
				|| room == 0x56
				|| room == 0x57
				|| room == 0x58
				|| room == 0x59
				|| room == 0x5a
				|| room == 0x5b
				|| room == 0x5c
				|| room == 0x5d
				|| room == 0x5e
				|| room == 0x5f
				|| room == 0x60
				|| room == 0x61
				|| room == 0x62
				|| room == 0x63
				|| room == 0x64
				|| room == 0x2d
				|| room == 0x40
				|| room == 0x41
				|| room == 0x42
				|| room == 0x43
				|| room == 0x44
				|| room == 0x45
				|| room == 0x46
				|| room == 0x47
				|| room == 0x48
				|| room == 0x49
				|| room == 0x4a
				|| room == 0x4b
				|| room == 0x4c
				|| room == 0x4d
				|| room == 0x4e
				|| room == 0x4f
				|| room == 0x50) {
			return true;
		}

		return false;
	}

	return false;
}

GLOBAL_ASM(
glabel weatherRenderRain
.late_rodata
glabel var7f1b5738
.word 0x3f7d70a4
glabel var7f1b573c
.word 0x3f266666
glabel var7f1b5740
.word 0x3f28f5c3
glabel var7f1b5744
.word 0x3ecccccd
glabel var7f1b5748
.word 0x3e4ccccd
glabel var7f1b574c
.word 0x3dcccccd
glabel var7f1b5750
.word 0x3e99999a
glabel var7f1b5754
.word 0x3e4cccce
glabel var7f1b5758
.word 0x3e99999a
glabel var7f1b575c
.word 0x3ecccccd
glabel var7f1b5760
.word 0x3f19999a
glabel var7f1b5764
.word 0x3f333333
glabel var7f1b5768
.word 0x3f199999
glabel var7f1b576c
.word 0x3f4ccccd
glabel var7f1b5770
.word 0x3f333333
glabel var7f1b5774
.word 0x3f666666
glabel var7f1b5778
.word 0x3f4ccccc
glabel var7f1b577c
.word 0x3f666666
glabel var7f1b5780
.word 0x3727c5ac
.text
/*  f132e28:	27bdf218 */ 	addiu	$sp,$sp,-3560
/*  f132e2c:	afa40de8 */ 	sw	$a0,0xde8($sp)
/*  f132e30:	afa50dec */ 	sw	$a1,0xdec($sp)
/*  f132e34:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f132e38:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f132e3c:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f132e40:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f132e44:	3c058008 */ 	lui	$a1,%hi(var8007f0e4)
/*  f132e48:	3c047f1b */ 	lui	$a0,%hi(var7f1b564c)
/*  f132e4c:	00c08825 */ 	or	$s1,$a2,$zero
/*  f132e50:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f132e54:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f132e58:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f132e5c:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f132e60:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f132e64:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f132e68:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f132e6c:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f132e70:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f132e74:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f132e78:	afae0d80 */ 	sw	$t6,0xd80($sp)
/*  f132e7c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f132e80:	afa00708 */ 	sw	$zero,0x708($sp)
/*  f132e84:	2484564c */ 	addiu	$a0,$a0,%lo(var7f1b564c)
/*  f132e88:	0c0036cc */ 	jal	func0000db30
/*  f132e8c:	24a5f0e4 */ 	addiu	$a1,$a1,%lo(var8007f0e4)
/*  f132e90:	3c047f1b */ 	lui	$a0,%hi(var7f1b5658)
/*  f132e94:	3c058008 */ 	lui	$a1,%hi(var8007f0e8)
/*  f132e98:	24a5f0e8 */ 	addiu	$a1,$a1,%lo(var8007f0e8)
/*  f132e9c:	0c0036cc */ 	jal	func0000db30
/*  f132ea0:	24845658 */ 	addiu	$a0,$a0,%lo(var7f1b5658)
/*  f132ea4:	3c047f1b */ 	lui	$a0,%hi(var7f1b5664)
/*  f132ea8:	3c058008 */ 	lui	$a1,%hi(var8007f0e0)
/*  f132eac:	24a5f0e0 */ 	addiu	$a1,$a1,%lo(var8007f0e0)
/*  f132eb0:	0c0036cc */ 	jal	func0000db30
/*  f132eb4:	24845664 */ 	addiu	$a0,$a0,%lo(var7f1b5664)
/*  f132eb8:	3c047f1b */ 	lui	$a0,%hi(var7f1b5670)
/*  f132ebc:	3c058008 */ 	lui	$a1,%hi(var8007f0ec)
/*  f132ec0:	24a5f0ec */ 	addiu	$a1,$a1,%lo(var8007f0ec)
/*  f132ec4:	0c0036cc */ 	jal	func0000db30
/*  f132ec8:	24845670 */ 	addiu	$a0,$a0,%lo(var7f1b5670)
/*  f132ecc:	3c047f1b */ 	lui	$a0,%hi(var7f1b5678)
/*  f132ed0:	3c058008 */ 	lui	$a1,%hi(var8007f0f0)
/*  f132ed4:	24a5f0f0 */ 	addiu	$a1,$a1,%lo(var8007f0f0)
/*  f132ed8:	0c0036cc */ 	jal	func0000db30
/*  f132edc:	24845678 */ 	addiu	$a0,$a0,%lo(var7f1b5678)
/*  f132ee0:	3c047f1b */ 	lui	$a0,%hi(var7f1b5680)
/*  f132ee4:	3c058008 */ 	lui	$a1,%hi(var8007f0f4)
/*  f132ee8:	24a5f0f4 */ 	addiu	$a1,$a1,%lo(var8007f0f4)
/*  f132eec:	0c0036cc */ 	jal	func0000db30
/*  f132ef0:	24845680 */ 	addiu	$a0,$a0,%lo(var7f1b5680)
/*  f132ef4:	3c047f1b */ 	lui	$a0,%hi(var7f1b5688)
/*  f132ef8:	3c058008 */ 	lui	$a1,%hi(var8007f0f8)
/*  f132efc:	24a5f0f8 */ 	addiu	$a1,$a1,%lo(var8007f0f8)
/*  f132f00:	0c0036cc */ 	jal	func0000db30
/*  f132f04:	24845688 */ 	addiu	$a0,$a0,%lo(var7f1b5688)
/*  f132f08:	3c047f1b */ 	lui	$a0,%hi(var7f1b5690)
/*  f132f0c:	3c058008 */ 	lui	$a1,%hi(var8007f0fc)
/*  f132f10:	24a5f0fc */ 	addiu	$a1,$a1,%lo(var8007f0fc)
/*  f132f14:	0c0036cc */ 	jal	func0000db30
/*  f132f18:	24845690 */ 	addiu	$a0,$a0,%lo(var7f1b5690)
/*  f132f1c:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f132f20:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f132f24:	8e6f0034 */ 	lw	$t7,0x34($s3)
/*  f132f28:	1de00002 */ 	bgtz	$t7,.L0f132f34
/*  f132f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132f30:	afa00d80 */ 	sw	$zero,0xd80($sp)
.L0f132f34:
/*  f132f34:	0c012144 */ 	jal	osGetCount
/*  f132f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f132f3c:	27a30db0 */ 	addiu	$v1,$sp,0xdb0
/*  f132f40:	27a20dd8 */ 	addiu	$v0,$sp,0xdd8
.L0f132f44:
/*  f132f44:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f132f48:	1462fffe */ 	bne	$v1,$v0,.L0f132f44
/*  f132f4c:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f132f50:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f132f54:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f132f58:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f132f5c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f132f60:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f132f64:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f132f68:	27a40de8 */ 	addiu	$a0,$sp,0xde8
/*  f132f6c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f132f70:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f132f74:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f132f78:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f132f7c:	24a5000c */ 	addiu	$a1,$a1,0x000c
/*  f132f80:	8fab0de8 */ 	lw	$t3,0xde8($sp)
/*  f132f84:	3c0dba00 */ 	lui	$t5,0xba00
/*  f132f88:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f132f8c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f132f90:	afac0de8 */ 	sw	$t4,0xde8($sp)
/*  f132f94:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f132f98:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f132f9c:	8fae0de8 */ 	lw	$t6,0xde8($sp)
/*  f132fa0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f132fa4:	37180602 */ 	ori	$t8,$t8,0x602
/*  f132fa8:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f132fac:	afaf0de8 */ 	sw	$t7,0xde8($sp)
/*  f132fb0:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f132fb4:	add90004 */ 	sw	$t9,0x4($t6)
/*  f132fb8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f132fbc:	8fab0de8 */ 	lw	$t3,0xde8($sp)
/*  f132fc0:	3c0e0040 */ 	lui	$t6,0x40
/*  f132fc4:	3c0db900 */ 	lui	$t5,0xb900
/*  f132fc8:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f132fcc:	afac0de8 */ 	sw	$t4,0xde8($sp)
/*  f132fd0:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f132fd4:	35ce49d8 */ 	ori	$t6,$t6,0x49d8
/*  f132fd8:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f132fdc:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f132fe0:	8faf0de8 */ 	lw	$t7,0xde8($sp)
/*  f132fe4:	3c19b900 */ 	lui	$t9,0xb900
/*  f132fe8:	37390002 */ 	ori	$t9,$t9,0x2
/*  f132fec:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f132ff0:	afb80de8 */ 	sw	$t8,0xde8($sp)
/*  f132ff4:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f132ff8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f132ffc:	8fab0de8 */ 	lw	$t3,0xde8($sp)
/*  f133000:	3c0dba00 */ 	lui	$t5,0xba00
/*  f133004:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f133008:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f13300c:	afac0de8 */ 	sw	$t4,0xde8($sp)
/*  f133010:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f133014:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f133018:	8fae0de8 */ 	lw	$t6,0xde8($sp)
/*  f13301c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f133020:	37180903 */ 	ori	$t8,$t8,0x903
/*  f133024:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f133028:	afaf0de8 */ 	sw	$t7,0xde8($sp)
/*  f13302c:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f133030:	add90004 */ 	sw	$t9,0x4($t6)
/*  f133034:	add80000 */ 	sw	$t8,0x0($t6)
/*  f133038:	8fab0de8 */ 	lw	$t3,0xde8($sp)
/*  f13303c:	3c0eff32 */ 	lui	$t6,0xff32
/*  f133040:	3c0dfcff */ 	lui	$t5,0xfcff
/*  f133044:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f133048:	afac0de8 */ 	sw	$t4,0xde8($sp)
/*  f13304c:	35ad99ff */ 	ori	$t5,$t5,0x99ff
/*  f133050:	35ce7f3f */ 	ori	$t6,$t6,0x7f3f
/*  f133054:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f133058:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f13305c:	8faf0dec */ 	lw	$t7,0xdec($sp)
/*  f133060:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f133064:	27b001c8 */ 	addiu	$s0,$sp,0x1c8
/*  f133068:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f13306c:	8f370024 */ 	lw	$s7,0x24($t9)
/*  f133070:	afa00194 */ 	sw	$zero,0x194($sp)
/*  f133074:	0c00566c */ 	jal	func000159b0
/*  f133078:	02002025 */ 	or	$a0,$s0,$zero
/*  f13307c:	0fc2d5be */ 	jal	currentPlayerGetUnk1740
/*  f133080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133084:	00402025 */ 	or	$a0,$v0,$zero
/*  f133088:	0c0056f8 */ 	jal	func00015be0
/*  f13308c:	02002825 */ 	or	$a1,$s0,$zero
/*  f133090:	4480a000 */ 	mtc1	$zero,$f20
/*  f133094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133098:	e7b401f8 */ 	swc1	$f20,0x1f8($sp)
/*  f13309c:	e7b401fc */ 	swc1	$f20,0x1fc($sp)
/*  f1330a0:	0fc59e66 */ 	jal	func0f167998
/*  f1330a4:	e7b40200 */ 	swc1	$f20,0x200($sp)
/*  f1330a8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1330ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f1330b0:	0c005815 */ 	jal	func00016054
/*  f1330b4:	00402825 */ 	or	$a1,$v0,$zero
/*  f1330b8:	8fb00de8 */ 	lw	$s0,0xde8($sp)
/*  f1330bc:	3c0d0102 */ 	lui	$t5,0x102
/*  f1330c0:	35ad0040 */ 	ori	$t5,$t5,0x40
/*  f1330c4:	260c0008 */ 	addiu	$t4,$s0,0x8
/*  f1330c8:	afac0de8 */ 	sw	$t4,0xde8($sp)
/*  f1330cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1330d0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1330d4:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f1330d8:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f1330dc:	8e630284 */ 	lw	$v1,0x284($s3)
/*  f1330e0:	02e09025 */ 	or	$s2,$s7,$zero
/*  f1330e4:	24043e80 */ 	addiu	$a0,$zero,0x3e80
/*  f1330e8:	c4641bb0 */ 	lwc1	$f4,0x1bb0($v1)
/*  f1330ec:	e7a40230 */ 	swc1	$f4,0x230($sp)
/*  f1330f0:	c4661bb4 */ 	lwc1	$f6,0x1bb4($v1)
/*  f1330f4:	c7aa0230 */ 	lwc1	$f10,0x230($sp)
/*  f1330f8:	e7a60234 */ 	swc1	$f6,0x234($sp)
/*  f1330fc:	c4681bb8 */ 	lwc1	$f8,0x1bb8($v1)
/*  f133100:	00001825 */ 	or	$v1,$zero,$zero
/*  f133104:	e7a80238 */ 	swc1	$f8,0x238($sp)
/*  f133108:	c6e43e80 */ 	lwc1	$f4,0x3e80($s7)
/*  f13310c:	c7a80234 */ 	lwc1	$f8,0x234($sp)
/*  f133110:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f133114:	e7a60224 */ 	swc1	$f6,0x224($sp)
/*  f133118:	c6ea3e84 */ 	lwc1	$f10,0x3e84($s7)
/*  f13311c:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f133120:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f133124:	c7a80238 */ 	lwc1	$f8,0x238($sp)
/*  f133128:	e7a40228 */ 	swc1	$f4,0x228($sp)
/*  f13312c:	c6ea3e88 */ 	lwc1	$f10,0x3e88($s7)
/*  f133130:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f133134:	45000003 */ 	bc1f	.L0f133144
/*  f133138:	e7a4022c */ 	swc1	$f4,0x22c($sp)
/*  f13313c:	10000003 */ 	beqz	$zero,.L0f13314c
/*  f133140:	46003386 */ 	mov.s	$f14,$f6
.L0f133144:
/*  f133144:	c7ae0224 */ 	lwc1	$f14,0x224($sp)
/*  f133148:	46007387 */ 	neg.s	$f14,$f14
.L0f13314c:
/*  f13314c:	c6ec3e98 */ 	lwc1	$f12,0x3e98($s7)
/*  f133150:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f133154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133158:	45020004 */ 	bc1fl	.L0f13316c
/*  f13315c:	46006407 */ 	neg.s	$f16,$f12
/*  f133160:	10000002 */ 	beqz	$zero,.L0f13316c
/*  f133164:	46006406 */ 	mov.s	$f16,$f12
/*  f133168:	46006407 */ 	neg.s	$f16,$f12
.L0f13316c:
/*  f13316c:	c6e03e8c */ 	lwc1	$f0,0x3e8c($s7)
/*  f133170:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f133174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133178:	45020004 */ 	bc1fl	.L0f13318c
/*  f13317c:	46000087 */ 	neg.s	$f2,$f0
/*  f133180:	10000002 */ 	beqz	$zero,.L0f13318c
/*  f133184:	46000086 */ 	mov.s	$f2,$f0
/*  f133188:	46000087 */ 	neg.s	$f2,$f0
.L0f13318c:
/*  f13318c:	46101200 */ 	add.s	$f8,$f2,$f16
/*  f133190:	460e403c */ 	c.lt.s	$f8,$f14
/*  f133194:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133198:	4503003b */ 	bc1tl	.L0f133288
/*  f13319c:	3c013f00 */ 	lui	$at,0x3f00
/*  f1331a0:	c7a00228 */ 	lwc1	$f0,0x228($sp)
/*  f1331a4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1331a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1331ac:	45020004 */ 	bc1fl	.L0f1331c0
/*  f1331b0:	46000307 */ 	neg.s	$f12,$f0
/*  f1331b4:	10000002 */ 	beqz	$zero,.L0f1331c0
/*  f1331b8:	46000306 */ 	mov.s	$f12,$f0
/*  f1331bc:	46000307 */ 	neg.s	$f12,$f0
.L0f1331c0:
/*  f1331c0:	c6ee3e9c */ 	lwc1	$f14,0x3e9c($s7)
/*  f1331c4:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f1331c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1331cc:	45020004 */ 	bc1fl	.L0f1331e0
/*  f1331d0:	46007407 */ 	neg.s	$f16,$f14
/*  f1331d4:	10000002 */ 	beqz	$zero,.L0f1331e0
/*  f1331d8:	46007406 */ 	mov.s	$f16,$f14
/*  f1331dc:	46007407 */ 	neg.s	$f16,$f14
.L0f1331e0:
/*  f1331e0:	c6e03e90 */ 	lwc1	$f0,0x3e90($s7)
/*  f1331e4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1331e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1331ec:	45020004 */ 	bc1fl	.L0f133200
/*  f1331f0:	46000087 */ 	neg.s	$f2,$f0
/*  f1331f4:	10000002 */ 	beqz	$zero,.L0f133200
/*  f1331f8:	46000086 */ 	mov.s	$f2,$f0
/*  f1331fc:	46000087 */ 	neg.s	$f2,$f0
.L0f133200:
/*  f133200:	46101280 */ 	add.s	$f10,$f2,$f16
/*  f133204:	c7a0022c */ 	lwc1	$f0,0x22c($sp)
/*  f133208:	460c503c */ 	c.lt.s	$f10,$f12
/*  f13320c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133210:	4503001d */ 	bc1tl	.L0f133288
/*  f133214:	3c013f00 */ 	lui	$at,0x3f00
/*  f133218:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f13321c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133220:	45020004 */ 	bc1fl	.L0f133234
/*  f133224:	46000387 */ 	neg.s	$f14,$f0
/*  f133228:	10000002 */ 	beqz	$zero,.L0f133234
/*  f13322c:	46000386 */ 	mov.s	$f14,$f0
/*  f133230:	46000387 */ 	neg.s	$f14,$f0
.L0f133234:
/*  f133234:	c6ec3ea0 */ 	lwc1	$f12,0x3ea0($s7)
/*  f133238:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f13323c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133240:	45020004 */ 	bc1fl	.L0f133254
/*  f133244:	46006407 */ 	neg.s	$f16,$f12
/*  f133248:	10000002 */ 	beqz	$zero,.L0f133254
/*  f13324c:	46006406 */ 	mov.s	$f16,$f12
/*  f133250:	46006407 */ 	neg.s	$f16,$f12
.L0f133254:
/*  f133254:	c6e03e94 */ 	lwc1	$f0,0x3e94($s7)
/*  f133258:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f13325c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133260:	45020004 */ 	bc1fl	.L0f133274
/*  f133264:	46000087 */ 	neg.s	$f2,$f0
/*  f133268:	10000002 */ 	beqz	$zero,.L0f133274
/*  f13326c:	46000086 */ 	mov.s	$f2,$f0
/*  f133270:	46000087 */ 	neg.s	$f2,$f0
.L0f133274:
/*  f133274:	46101100 */ 	add.s	$f4,$f2,$f16
/*  f133278:	460e203c */ 	c.lt.s	$f4,$f14
/*  f13327c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133280:	4500000b */ 	bc1f	.L0f1332b0
/*  f133284:	3c013f00 */ 	lui	$at,0x3f00
.L0f133288:
/*  f133288:	44810000 */ 	mtc1	$at,$f0
/*  f13328c:	c6e63ea4 */ 	lwc1	$f6,0x3ea4($s7)
/*  f133290:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f133294:	e7a80224 */ 	swc1	$f8,0x224($sp)
/*  f133298:	c6ea3ea8 */ 	lwc1	$f10,0x3ea8($s7)
/*  f13329c:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f1332a0:	e7a40228 */ 	swc1	$f4,0x228($sp)
/*  f1332a4:	c6e63eac */ 	lwc1	$f6,0x3eac($s7)
/*  f1332a8:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f1332ac:	e7a8022c */ 	swc1	$f8,0x22c($sp)
.L0f1332b0:
/*  f1332b0:	c6ec3e98 */ 	lwc1	$f12,0x3e98($s7)
/*  f1332b4:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f1332b8:	c7a60224 */ 	lwc1	$f6,0x224($sp)
/*  f1332bc:	02401025 */ 	or	$v0,$s2,$zero
/*  f1332c0:	460c5101 */ 	sub.s	$f4,$f10,$f12
/*  f1332c4:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f1332c8:	4614003c */ 	c.lt.s	$f0,$f20
/*  f1332cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1332d0:	45020004 */ 	bc1fl	.L0f1332e4
/*  f1332d4:	c6e23ea4 */ 	lwc1	$f2,0x3ea4($s7)
/*  f1332d8:	c6e83ea4 */ 	lwc1	$f8,0x3ea4($s7)
/*  f1332dc:	46080000 */ 	add.s	$f0,$f0,$f8
/*  f1332e0:	c6e23ea4 */ 	lwc1	$f2,0x3ea4($s7)
.L0f1332e4:
/*  f1332e4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f1332e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1332ec:	45020003 */ 	bc1fl	.L0f1332fc
/*  f1332f0:	46006280 */ 	add.s	$f10,$f12,$f0
/*  f1332f4:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f1332f8:	46006280 */ 	add.s	$f10,$f12,$f0
.L0f1332fc:
/*  f1332fc:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f133300:	e64a0000 */ 	swc1	$f10,0x0($s2)
/*  f133304:	c6ee3e9c */ 	lwc1	$f14,0x3e9c($s7)
/*  f133308:	c7a80228 */ 	lwc1	$f8,0x228($sp)
/*  f13330c:	460e2181 */ 	sub.s	$f6,$f4,$f14
/*  f133310:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f133314:	4614003c */ 	c.lt.s	$f0,$f20
/*  f133318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13331c:	45020004 */ 	bc1fl	.L0f133330
/*  f133320:	c6e23ea8 */ 	lwc1	$f2,0x3ea8($s7)
/*  f133324:	c6ea3ea8 */ 	lwc1	$f10,0x3ea8($s7)
/*  f133328:	460a0000 */ 	add.s	$f0,$f0,$f10
/*  f13332c:	c6e23ea8 */ 	lwc1	$f2,0x3ea8($s7)
.L0f133330:
/*  f133330:	4600103c */ 	c.lt.s	$f2,$f0
/*  f133334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133338:	45020003 */ 	bc1fl	.L0f133348
/*  f13333c:	46007100 */ 	add.s	$f4,$f14,$f0
/*  f133340:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f133344:	46007100 */ 	add.s	$f4,$f14,$f0
.L0f133348:
/*  f133348:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f13334c:	e6440004 */ 	swc1	$f4,0x4($s2)
/*  f133350:	c6ec3ea0 */ 	lwc1	$f12,0x3ea0($s7)
/*  f133354:	c7aa022c */ 	lwc1	$f10,0x22c($sp)
/*  f133358:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*  f13335c:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f133360:	4614003c */ 	c.lt.s	$f0,$f20
/*  f133364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133368:	45020004 */ 	bc1fl	.L0f13337c
/*  f13336c:	c6e23eac */ 	lwc1	$f2,0x3eac($s7)
/*  f133370:	c6e43eac */ 	lwc1	$f4,0x3eac($s7)
/*  f133374:	46040000 */ 	add.s	$f0,$f0,$f4
/*  f133378:	c6e23eac */ 	lwc1	$f2,0x3eac($s7)
.L0f13337c:
/*  f13337c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f133380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133384:	45020003 */ 	bc1fl	.L0f133394
/*  f133388:	46006180 */ 	add.s	$f6,$f12,$f0
/*  f13338c:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f133390:	46006180 */ 	add.s	$f6,$f12,$f0
.L0f133394:
/*  f133394:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f133398:	26520020 */ 	addiu	$s2,$s2,0x20
/*  f13339c:	1464ffc4 */ 	bne	$v1,$a0,.L0f1332b0
/*  f1333a0:	e4460008 */ 	swc1	$f6,0x8($v0)
/*  f1333a4:	c7a80230 */ 	lwc1	$f8,0x230($sp)
/*  f1333a8:	e6e83e80 */ 	swc1	$f8,0x3e80($s7)
/*  f1333ac:	c7aa0234 */ 	lwc1	$f10,0x234($sp)
/*  f1333b0:	e6ea3e84 */ 	swc1	$f10,0x3e84($s7)
/*  f1333b4:	c7a40238 */ 	lwc1	$f4,0x238($sp)
/*  f1333b8:	e6e43e88 */ 	swc1	$f4,0x3e88($s7)
/*  f1333bc:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f1333c0:	0fc4ca87 */ 	jal	weatherIsRoomWeatherProof
/*  f1333c4:	8dc41ba0 */ 	lw	$a0,0x1ba0($t6)
/*  f1333c8:	1040000f */ 	beqz	$v0,.L0f133408
/*  f1333cc:	8fb80dec */ 	lw	$t8,0xdec($sp)
/*  f1333d0:	8fa70dec */ 	lw	$a3,0xdec($sp)
/*  f1333d4:	3c017f1b */ 	lui	$at,%hi(var7f1b5738)
/*  f1333d8:	c4265738 */ 	lwc1	$f6,%lo(var7f1b5738)($at)
/*  f1333dc:	c4e80088 */ 	lwc1	$f8,0x88($a3)
/*  f1333e0:	3c017f1b */ 	lui	$at,%hi(var7f1b573c)
/*  f1333e4:	240f0009 */ 	addiu	$t7,$zero,0x9
/*  f1333e8:	4608303c */ 	c.lt.s	$f6,$f8
/*  f1333ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1333f0:	45020012 */ 	bc1fl	.L0f13343c
/*  f1333f4:	8e6b0034 */ 	lw	$t3,0x34($s3)
/*  f1333f8:	c42a573c */ 	lwc1	$f10,%lo(var7f1b573c)($at)
/*  f1333fc:	acef0090 */ 	sw	$t7,0x90($a3)
/*  f133400:	1000000d */ 	beqz	$zero,.L0f133438
/*  f133404:	e4ea008c */ 	swc1	$f10,0x8c($a3)
.L0f133408:
/*  f133408:	3c017f1b */ 	lui	$at,%hi(var7f1b5740)
/*  f13340c:	c4265740 */ 	lwc1	$f6,%lo(var7f1b5740)($at)
/*  f133410:	c7040088 */ 	lwc1	$f4,0x88($t8)
/*  f133414:	3c013f80 */ 	lui	$at,0x3f80
/*  f133418:	4606203c */ 	c.lt.s	$f4,$f6
/*  f13341c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133420:	45020006 */ 	bc1fl	.L0f13343c
/*  f133424:	8e6b0034 */ 	lw	$t3,0x34($s3)
/*  f133428:	4481c000 */ 	mtc1	$at,$f24
/*  f13342c:	24190007 */ 	addiu	$t9,$zero,0x7
/*  f133430:	af190090 */ 	sw	$t9,0x90($t8)
/*  f133434:	e718008c */ 	swc1	$f24,0x8c($t8)
.L0f133438:
/*  f133438:	8e6b0034 */ 	lw	$t3,0x34($s3)
.L0f13343c:
/*  f13343c:	3c013f80 */ 	lui	$at,0x3f80
/*  f133440:	4481c000 */ 	mtc1	$at,$f24
/*  f133444:	1960011b */ 	blez	$t3,.L0f1338b4
/*  f133448:	8fa70dec */ 	lw	$a3,0xdec($sp)
/*  f13344c:	3c05800a */ 	lui	$a1,%hi(var800a33a4)
/*  f133450:	24a533a4 */ 	addiu	$a1,$a1,%lo(var800a33a4)
/*  f133454:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f133458:	8ce20094 */ 	lw	$v0,0x94($a3)
/*  f13345c:	04430018 */ 	bgezl	$v0,.L0f1334c0
/*  f133460:	8ce30098 */ 	lw	$v1,0x98($a3)
/*  f133464:	0c004b70 */ 	jal	random
/*  f133468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13346c:	44824000 */ 	mtc1	$v0,$f8
/*  f133470:	3c012f80 */ 	lui	$at,0x2f80
/*  f133474:	4481a000 */ 	mtc1	$at,$f20
/*  f133478:	04410005 */ 	bgez	$v0,.L0f133490
/*  f13347c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f133480:	3c014f80 */ 	lui	$at,0x4f80
/*  f133484:	44812000 */ 	mtc1	$at,$f4
/*  f133488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13348c:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f133490:
/*  f133490:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f133494:	8fac0dec */ 	lw	$t4,0xdec($sp)
/*  f133498:	c58800c4 */ 	lwc1	$f8,0xc4($t4)
/*  f13349c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f1334a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1334a4:	45000003 */ 	bc1f	.L0f1334b4
/*  f1334a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1334ac:	0fc4c584 */ 	jal	func0f131610
/*  f1334b0:	01802025 */ 	or	$a0,$t4,$zero
.L0f1334b4:
/*  f1334b4:	100000ff */ 	beqz	$zero,.L0f1338b4
/*  f1334b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1334bc:	8ce30098 */ 	lw	$v1,0x98($a3)
.L0f1334c0:
/*  f1334c0:	244d0001 */ 	addiu	$t5,$v0,0x1
/*  f1334c4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1334c8:	51a3000a */ 	beql	$t5,$v1,.L0f1334f4
/*  f1334cc:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1334d0:	8ce4009c */ 	lw	$a0,0x9c($a3)
/*  f1334d4:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f1334d8:	51c40006 */ 	beql	$t6,$a0,.L0f1334f4
/*  f1334dc:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1334e0:	8cf900a0 */ 	lw	$t9,0xa0($a3)
/*  f1334e4:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f1334e8:	15f90005 */ 	bne	$t7,$t9,.L0f133500
/*  f1334ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1334f0:	acb80000 */ 	sw	$t8,0x0($a1)
.L0f1334f4:
/*  f1334f4:	8ce4009c */ 	lw	$a0,0x9c($a3)
/*  f1334f8:	8ce30098 */ 	lw	$v1,0x98($a3)
/*  f1334fc:	8ce20094 */ 	lw	$v0,0x94($a3)
.L0f133500:
/*  f133500:	10430006 */ 	beq	$v0,$v1,.L0f13351c
/*  f133504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133508:	10440004 */ 	beq	$v0,$a0,.L0f13351c
/*  f13350c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133510:	8ceb00a0 */ 	lw	$t3,0xa0($a3)
/*  f133514:	544b0017 */ 	bnel	$v0,$t3,.L0f133574
/*  f133518:	8cef00a4 */ 	lw	$t7,0xa4($a3)
.L0f13351c:
/*  f13351c:	14440002 */ 	bne	$v0,$a0,.L0f133528
/*  f133520:	24110096 */ 	addiu	$s1,$zero,0x96
/*  f133524:	241100c8 */ 	addiu	$s1,$zero,0xc8
.L0f133528:
/*  f133528:	8e6c02bc */ 	lw	$t4,0x2bc($s3)
/*  f13352c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f133530:	29810002 */ 	slti	$at,$t4,0x2
/*  f133534:	5420000f */ 	bnezl	$at,.L0f133574
/*  f133538:	8cef00a4 */ 	lw	$t7,0xa4($a3)
.L0f13353c:
/*  f13353c:	0fc4ca87 */ 	jal	weatherIsRoomWeatherProof
/*  f133540:	02002025 */ 	or	$a0,$s0,$zero
/*  f133544:	14400003 */ 	bnez	$v0,.L0f133554
/*  f133548:	02002025 */ 	or	$a0,$s0,$zero
/*  f13354c:	0fc00400 */ 	jal	func0f001000
/*  f133550:	02202825 */ 	or	$a1,$s1,$zero
.L0f133554:
/*  f133554:	8e6d02bc */ 	lw	$t5,0x2bc($s3)
/*  f133558:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f13355c:	020d082a */ 	slt	$at,$s0,$t5
/*  f133560:	1420fff6 */ 	bnez	$at,.L0f13353c
/*  f133564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133568:	8fa70dec */ 	lw	$a3,0xdec($sp)
/*  f13356c:	8ce20094 */ 	lw	$v0,0x94($a3)
/*  f133570:	8cef00a4 */ 	lw	$t7,0xa4($a3)
.L0f133574:
/*  f133574:	544f00c8 */ 	bnel	$v0,$t7,.L0f133898
/*  f133578:	8fa70dec */ 	lw	$a3,0xdec($sp)
/*  f13357c:	0c004b70 */ 	jal	random
/*  f133580:	341180ba */ 	dli	$s1,0x80ba
/*  f133584:	3c012f80 */ 	lui	$at,0x2f80
/*  f133588:	44822000 */ 	mtc1	$v0,$f4
/*  f13358c:	4481a000 */ 	mtc1	$at,$f20
/*  f133590:	3c017f1b */ 	lui	$at,%hi(var7f1b5744)
/*  f133594:	c4365744 */ 	lwc1	$f22,%lo(var7f1b5744)($at)
/*  f133598:	04410005 */ 	bgez	$v0,.L0f1335b0
/*  f13359c:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f1335a0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1335a4:	44813000 */ 	mtc1	$at,$f6
/*  f1335a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1335ac:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f1335b0:
/*  f1335b0:	46145202 */ 	mul.s	$f8,$f10,$f20
/*  f1335b4:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f1335b8:	44812000 */ 	mtc1	$at,$f4
/*  f1335bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1335c0:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f1335c4:	46163280 */ 	add.s	$f10,$f6,$f22
/*  f1335c8:	0c004b70 */ 	jal	random
/*  f1335cc:	e7aa0174 */ 	swc1	$f10,0x174($sp)
/*  f1335d0:	44824000 */ 	mtc1	$v0,$f8
/*  f1335d4:	8fb90dec */ 	lw	$t9,0xdec($sp)
/*  f1335d8:	04410005 */ 	bgez	$v0,.L0f1335f0
/*  f1335dc:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f1335e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1335e4:	44813000 */ 	mtc1	$at,$f6
/*  f1335e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1335ec:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f1335f0:
/*  f1335f0:	46142002 */ 	mul.s	$f0,$f4,$f20
/*  f1335f4:	3c017f1b */ 	lui	$at,%hi(var7f1b5748)
/*  f1335f8:	c42a5748 */ 	lwc1	$f10,%lo(var7f1b5748)($at)
/*  f1335fc:	3c017f1b */ 	lui	$at,%hi(var7f1b574c)
/*  f133600:	460a003e */ 	c.le.s	$f0,$f10
/*  f133604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133608:	45000007 */ 	bc1f	.L0f133628
/*  f13360c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133610:	c428574c */ 	lwc1	$f8,%lo(var7f1b574c)($at)
/*  f133614:	4600403c */ 	c.lt.s	$f8,$f0
/*  f133618:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13361c:	45000002 */ 	bc1f	.L0f133628
/*  f133620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133624:	341180bb */ 	dli	$s1,0x80bb
.L0f133628:
/*  f133628:	3c017f1b */ 	lui	$at,%hi(var7f1b5750)
/*  f13362c:	c4265750 */ 	lwc1	$f6,%lo(var7f1b5750)($at)
/*  f133630:	3c017f1b */ 	lui	$at,%hi(var7f1b5754)
/*  f133634:	4606003e */ 	c.le.s	$f0,$f6
/*  f133638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13363c:	45020008 */ 	bc1fl	.L0f133660
/*  f133640:	4616003e */ 	c.le.s	$f0,$f22
/*  f133644:	c4245754 */ 	lwc1	$f4,%lo(var7f1b5754)($at)
/*  f133648:	4600203c */ 	c.lt.s	$f4,$f0
/*  f13364c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133650:	45020003 */ 	bc1fl	.L0f133660
/*  f133654:	4616003e */ 	c.le.s	$f0,$f22
/*  f133658:	341180bc */ 	dli	$s1,0x80bc
/*  f13365c:	4616003e */ 	c.le.s	$f0,$f22
.L0f133660:
/*  f133660:	3c017f1b */ 	lui	$at,%hi(var7f1b5758)
/*  f133664:	45020008 */ 	bc1fl	.L0f133688
/*  f133668:	3c013f00 */ 	lui	$at,0x3f00
/*  f13366c:	c42a5758 */ 	lwc1	$f10,%lo(var7f1b5758)($at)
/*  f133670:	4600503c */ 	c.lt.s	$f10,$f0
/*  f133674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133678:	45020003 */ 	bc1fl	.L0f133688
/*  f13367c:	3c013f00 */ 	lui	$at,0x3f00
/*  f133680:	341180bd */ 	dli	$s1,0x80bd
/*  f133684:	3c013f00 */ 	lui	$at,0x3f00
.L0f133688:
/*  f133688:	44814000 */ 	mtc1	$at,$f8
/*  f13368c:	3c017f1b */ 	lui	$at,%hi(var7f1b575c)
/*  f133690:	4608003e */ 	c.le.s	$f0,$f8
/*  f133694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133698:	45000007 */ 	bc1f	.L0f1336b8
/*  f13369c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336a0:	c426575c */ 	lwc1	$f6,%lo(var7f1b575c)($at)
/*  f1336a4:	4600303c */ 	c.lt.s	$f6,$f0
/*  f1336a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336ac:	45000002 */ 	bc1f	.L0f1336b8
/*  f1336b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336b4:	341180be */ 	dli	$s1,0x80be
.L0f1336b8:
/*  f1336b8:	3c017f1b */ 	lui	$at,%hi(var7f1b5760)
/*  f1336bc:	c4245760 */ 	lwc1	$f4,%lo(var7f1b5760)($at)
/*  f1336c0:	27300040 */ 	addiu	$s0,$t9,0x40
/*  f1336c4:	3c013f00 */ 	lui	$at,0x3f00
/*  f1336c8:	4604003e */ 	c.le.s	$f0,$f4
/*  f1336cc:	02003025 */ 	or	$a2,$s0,$zero
/*  f1336d0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f1336d4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1336d8:	45000008 */ 	bc1f	.L0f1336fc
/*  f1336dc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1336e0:	44815000 */ 	mtc1	$at,$f10
/*  f1336e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336e8:	4600503c */ 	c.lt.s	$f10,$f0
/*  f1336ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336f0:	45000002 */ 	bc1f	.L0f1336fc
/*  f1336f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336f8:	341180bf */ 	dli	$s1,0x80bf
.L0f1336fc:
/*  f1336fc:	3c017f1b */ 	lui	$at,%hi(var7f1b5764)
/*  f133700:	c4285764 */ 	lwc1	$f8,%lo(var7f1b5764)($at)
/*  f133704:	3c017f1b */ 	lui	$at,%hi(var7f1b5768)
/*  f133708:	240dffff */ 	addiu	$t5,$zero,-1
/*  f13370c:	4608003e */ 	c.le.s	$f0,$f8
/*  f133710:	240effff */ 	addiu	$t6,$zero,-1
/*  f133714:	45000007 */ 	bc1f	.L0f133734
/*  f133718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13371c:	c4265768 */ 	lwc1	$f6,%lo(var7f1b5768)($at)
/*  f133720:	4600303c */ 	c.lt.s	$f6,$f0
/*  f133724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133728:	45000002 */ 	bc1f	.L0f133734
/*  f13372c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133730:	341180c0 */ 	dli	$s1,0x80c0
.L0f133734:
/*  f133734:	3c017f1b */ 	lui	$at,%hi(var7f1b576c)
/*  f133738:	c424576c */ 	lwc1	$f4,%lo(var7f1b576c)($at)
/*  f13373c:	3c017f1b */ 	lui	$at,%hi(var7f1b5770)
/*  f133740:	4604003e */ 	c.le.s	$f0,$f4
/*  f133744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133748:	45000007 */ 	bc1f	.L0f133768
/*  f13374c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133750:	c42a5770 */ 	lwc1	$f10,%lo(var7f1b5770)($at)
/*  f133754:	4600503c */ 	c.lt.s	$f10,$f0
/*  f133758:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13375c:	45000002 */ 	bc1f	.L0f133768
/*  f133760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133764:	341180c1 */ 	dli	$s1,0x80c1
.L0f133768:
/*  f133768:	3c017f1b */ 	lui	$at,%hi(var7f1b5774)
/*  f13376c:	c4285774 */ 	lwc1	$f8,%lo(var7f1b5774)($at)
/*  f133770:	3c017f1b */ 	lui	$at,%hi(var7f1b5778)
/*  f133774:	4608003e */ 	c.le.s	$f0,$f8
/*  f133778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13377c:	45020008 */ 	bc1fl	.L0f1337a0
/*  f133780:	4618003e */ 	c.le.s	$f0,$f24
/*  f133784:	c4265778 */ 	lwc1	$f6,%lo(var7f1b5778)($at)
/*  f133788:	4600303c */ 	c.lt.s	$f6,$f0
/*  f13378c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133790:	45020003 */ 	bc1fl	.L0f1337a0
/*  f133794:	4618003e */ 	c.le.s	$f0,$f24
/*  f133798:	341180c2 */ 	dli	$s1,0x80c2
/*  f13379c:	4618003e */ 	c.le.s	$f0,$f24
.L0f1337a0:
/*  f1337a0:	3c017f1b */ 	lui	$at,%hi(var7f1b577c)
/*  f1337a4:	45020008 */ 	bc1fl	.L0f1337c8
/*  f1337a8:	8f380040 */ 	lw	$t8,0x40($t9)
/*  f1337ac:	c424577c */ 	lwc1	$f4,%lo(var7f1b577c)($at)
/*  f1337b0:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1337b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1337b8:	45020003 */ 	bc1fl	.L0f1337c8
/*  f1337bc:	8f380040 */ 	lw	$t8,0x40($t9)
/*  f1337c0:	341180c3 */ 	dli	$s1,0x80c3
/*  f1337c4:	8f380040 */ 	lw	$t8,0x40($t9)
.L0f1337c8:
/*  f1337c8:	00112c00 */ 	sll	$a1,$s1,0x10
/*  f1337cc:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f1337d0:	17000030 */ 	bnez	$t8,.L0f133894
/*  f1337d4:	01602825 */ 	or	$a1,$t3,$zero
/*  f1337d8:	a73100f8 */ 	sh	$s1,0xf8($t9)
/*  f1337dc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1337e0:	44815000 */ 	mtc1	$at,$f10
/*  f1337e4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1337e8:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1337ec:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1337f0:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f1337f4:	0c004241 */ 	jal	func00010904
/*  f1337f8:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f1337fc:	8faf0dec */ 	lw	$t7,0xdec($sp)
/*  f133800:	3c013f80 */ 	lui	$at,0x3f80
/*  f133804:	4481b000 */ 	mtc1	$at,$f22
/*  f133808:	8df80040 */ 	lw	$t8,0x40($t7)
/*  f13380c:	02002025 */ 	or	$a0,$s0,$zero
/*  f133810:	00002825 */ 	or	$a1,$zero,$zero
/*  f133814:	1300001f */ 	beqz	$t8,.L0f133894
/*  f133818:	e5f6007c */ 	swc1	$f22,0x7c($t7)
/*  f13381c:	c5e80088 */ 	lwc1	$f8,0x88($t7)
/*  f133820:	8e7902ac */ 	lw	$t9,0x2ac($s3)
/*  f133824:	24010006 */ 	addiu	$at,$zero,0x6
/*  f133828:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f13382c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f133830:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f133834:	8fad0dec */ 	lw	$t5,0xdec($sp)
/*  f133838:	44063000 */ 	mfc1	$a2,$f6
/*  f13383c:	17210006 */ 	bne	$t9,$at,.L0f133858
/*  f133840:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f133844:	04c10003 */ 	bgez	$a2,.L0f133854
/*  f133848:	00066043 */ 	sra	$t4,$a2,0x1
/*  f13384c:	24c10001 */ 	addiu	$at,$a2,0x1
/*  f133850:	00016043 */ 	sra	$t4,$at,0x1
.L0f133854:
/*  f133854:	01803025 */ 	or	$a2,$t4,$zero
.L0f133858:
/*  f133858:	85ae00f8 */ 	lh	$t6,0xf8($t5)
/*  f13385c:	3c013f80 */ 	lui	$at,0x3f80
/*  f133860:	44812000 */ 	mtc1	$at,$f4
/*  f133864:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f133868:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f13386c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f133870:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f133874:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f133878:	0c004128 */ 	jal	func000104a0
/*  f13387c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f133880:	8fb90dec */ 	lw	$t9,0xdec($sp)
/*  f133884:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f133888:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f13388c:	0c00cf94 */ 	jal	func00033e50
/*  f133890:	8f240040 */ 	lw	$a0,0x40($t9)
.L0f133894:
/*  f133894:	8fa70dec */ 	lw	$a3,0xdec($sp)
.L0f133898:
/*  f133898:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f13389c:	8cec0094 */ 	lw	$t4,0x94($a3)
/*  f1338a0:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1338a4:	29a10097 */ 	slti	$at,$t5,0x97
/*  f1338a8:	14200002 */ 	bnez	$at,.L0f1338b4
/*  f1338ac:	aced0094 */ 	sw	$t5,0x94($a3)
/*  f1338b0:	acf80094 */ 	sw	$t8,0x94($a3)
.L0f1338b4:
/*  f1338b4:	3c0f8008 */ 	lui	$t7,%hi(var8007f0f4)
/*  f1338b8:	8deff0f4 */ 	lw	$t7,%lo(var8007f0f4)($t7)
/*  f1338bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1338c0:	4481b000 */ 	mtc1	$at,$f22
/*  f1338c4:	11e000dc */ 	beqz	$t7,.L0f133c38
/*  f1338c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1338cc:	8e630284 */ 	lw	$v1,0x284($s3)
/*  f1338d0:	c6e83e98 */ 	lwc1	$f8,0x3e98($s7)
/*  f1338d4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f1338d8:	c46a1bb0 */ 	lwc1	$f10,0x1bb0($v1)
/*  f1338dc:	27b30128 */ 	addiu	$s3,$sp,0x128
/*  f1338e0:	4600c506 */ 	mov.s	$f20,$f24
/*  f1338e4:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f1338e8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1338ec:	27b10cb8 */ 	addiu	$s1,$sp,0xcb8
/*  f1338f0:	2415008c */ 	addiu	$s5,$zero,0x8c
/*  f1338f4:	e7a60150 */ 	swc1	$f6,0x150($sp)
/*  f1338f8:	c6ea3e8c */ 	lwc1	$f10,0x3e8c($s7)
/*  f1338fc:	c4641bb0 */ 	lwc1	$f4,0x1bb0($v1)
/*  f133900:	27b00cb8 */ 	addiu	$s0,$sp,0xcb8
/*  f133904:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f133908:	e7a8015c */ 	swc1	$f8,0x15c($sp)
/*  f13390c:	c6e43e9c */ 	lwc1	$f4,0x3e9c($s7)
/*  f133910:	c4661bb4 */ 	lwc1	$f6,0x1bb4($v1)
/*  f133914:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f133918:	e7aa0154 */ 	swc1	$f10,0x154($sp)
/*  f13391c:	c6e63e90 */ 	lwc1	$f6,0x3e90($s7)
/*  f133920:	c4681bb4 */ 	lwc1	$f8,0x1bb4($v1)
/*  f133924:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f133928:	e7a40160 */ 	swc1	$f4,0x160($sp)
/*  f13392c:	c6e83ea0 */ 	lwc1	$f8,0x3ea0($s7)
/*  f133930:	c46a1bb8 */ 	lwc1	$f10,0x1bb8($v1)
/*  f133934:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f133938:	e7a60158 */ 	swc1	$f6,0x158($sp)
/*  f13393c:	c6ea3e94 */ 	lwc1	$f10,0x3e94($s7)
/*  f133940:	c4641bb8 */ 	lwc1	$f4,0x1bb8($v1)
/*  f133944:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f133948:	e7a80164 */ 	swc1	$f8,0x164($sp)
/*  f13394c:	8c6b1ba0 */ 	lw	$t3,0x1ba0($v1)
/*  f133950:	1a800055 */ 	blez	$s4,.L0f133aa8
/*  f133954:	afab0cb8 */ 	sw	$t3,0xcb8($sp)
.L0f133958:
/*  f133958:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f13395c:	02602825 */ 	or	$a1,$s3,$zero
/*  f133960:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f133964:	0fc5916a */ 	jal	func0f1645a8
/*  f133968:	00001025 */ 	or	$v0,$zero,$zero
/*  f13396c:	1840004a */ 	blez	$v0,.L0f133a98
/*  f133970:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f133974:	3c08800a */ 	lui	$t0,%hi(g_RoomPtrs)
/*  f133978:	27a70128 */ 	addiu	$a3,$sp,0x128
/*  f13397c:	00026040 */ 	sll	$t4,$v0,0x1
/*  f133980:	01875021 */ 	addu	$t2,$t4,$a3
/*  f133984:	8d084928 */ 	lw	$t0,%lo(g_RoomPtrs)($t0)
/*  f133988:	84e50000 */ 	lh	$a1,0x0($a3)
.L0f13398c:
/*  f13398c:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f133990:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f133994:	00b50019 */ 	multu	$a1,$s5
/*  f133998:	00006812 */ 	mflo	$t5
/*  f13399c:	010d3021 */ 	addu	$a2,$t0,$t5
/*  f1339a0:	94ce0000 */ 	lhu	$t6,0x0($a2)
/*  f1339a4:	31d80004 */ 	andi	$t8,$t6,0x4
/*  f1339a8:	53000039 */ 	beqzl	$t8,.L0f133a90
/*  f1339ac:	00ea082b */ 	sltu	$at,$a3,$t2
/*  f1339b0:	1a800009 */ 	blez	$s4,.L0f1339d8
/*  f1339b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1339b8:	27a30cb8 */ 	addiu	$v1,$sp,0xcb8
.L0f1339bc:
/*  f1339bc:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f1339c0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1339c4:	15e50002 */ 	bne	$t7,$a1,.L0f1339d0
/*  f1339c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1339cc:	00002025 */ 	or	$a0,$zero,$zero
.L0f1339d0:
/*  f1339d0:	1454fffa */ 	bne	$v0,$s4,.L0f1339bc
/*  f1339d4:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f1339d8:
/*  f1339d8:	10800025 */ 	beqz	$a0,.L0f133a70
/*  f1339dc:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f1339e0:	c4c40018 */ 	lwc1	$f4,0x18($a2)
/*  f1339e4:	c7a80150 */ 	lwc1	$f8,0x150($sp)
/*  f1339e8:	4604303c */ 	c.lt.s	$f6,$f4
/*  f1339ec:	c7a60160 */ 	lwc1	$f6,0x160($sp)
/*  f1339f0:	45030007 */ 	bc1tl	.L0f133a10
/*  f1339f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1339f8:	c4ca0024 */ 	lwc1	$f10,0x24($a2)
/*  f1339fc:	4608503c */ 	c.lt.s	$f10,$f8
/*  f133a00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133a04:	45020003 */ 	bc1fl	.L0f133a14
/*  f133a08:	c4c4001c */ 	lwc1	$f4,0x1c($a2)
/*  f133a0c:	00002025 */ 	or	$a0,$zero,$zero
.L0f133a10:
/*  f133a10:	c4c4001c */ 	lwc1	$f4,0x1c($a2)
.L0f133a14:
/*  f133a14:	c7a80154 */ 	lwc1	$f8,0x154($sp)
/*  f133a18:	4604303c */ 	c.lt.s	$f6,$f4
/*  f133a1c:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f133a20:	45030007 */ 	bc1tl	.L0f133a40
/*  f133a24:	00002025 */ 	or	$a0,$zero,$zero
/*  f133a28:	c4ca0028 */ 	lwc1	$f10,0x28($a2)
/*  f133a2c:	4608503c */ 	c.lt.s	$f10,$f8
/*  f133a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133a34:	45020003 */ 	bc1fl	.L0f133a44
/*  f133a38:	c4c40020 */ 	lwc1	$f4,0x20($a2)
/*  f133a3c:	00002025 */ 	or	$a0,$zero,$zero
.L0f133a40:
/*  f133a40:	c4c40020 */ 	lwc1	$f4,0x20($a2)
.L0f133a44:
/*  f133a44:	c7a80158 */ 	lwc1	$f8,0x158($sp)
/*  f133a48:	4604303c */ 	c.lt.s	$f6,$f4
/*  f133a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133a50:	45030007 */ 	bc1tl	.L0f133a70
/*  f133a54:	00002025 */ 	or	$a0,$zero,$zero
/*  f133a58:	c4ca002c */ 	lwc1	$f10,0x2c($a2)
/*  f133a5c:	4608503c */ 	c.lt.s	$f10,$f8
/*  f133a60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133a64:	45000002 */ 	bc1f	.L0f133a70
/*  f133a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133a6c:	00002025 */ 	or	$a0,$zero,$zero
.L0f133a70:
/*  f133a70:	10800006 */ 	beqz	$a0,.L0f133a8c
/*  f133a74:	2a810032 */ 	slti	$at,$s4,0x32
/*  f133a78:	10200004 */ 	beqz	$at,.L0f133a8c
/*  f133a7c:	00145880 */ 	sll	$t3,$s4,0x2
/*  f133a80:	020b6021 */ 	addu	$t4,$s0,$t3
/*  f133a84:	ad850000 */ 	sw	$a1,0x0($t4)
/*  f133a88:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f133a8c:
/*  f133a8c:	00ea082b */ 	sltu	$at,$a3,$t2
.L0f133a90:
/*  f133a90:	5420ffbe */ 	bnezl	$at,.L0f13398c
/*  f133a94:	84e50000 */ 	lh	$a1,0x0($a3)
.L0f133a98:
/*  f133a98:	0254082a */ 	slt	$at,$s2,$s4
/*  f133a9c:	1420ffae */ 	bnez	$at,.L0f133958
/*  f133aa0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f133aa4:	00009025 */ 	or	$s2,$zero,$zero
.L0f133aa8:
/*  f133aa8:	1a800031 */ 	blez	$s4,.L0f133b70
/*  f133aac:	2415008c */ 	addiu	$s5,$zero,0x8c
/*  f133ab0:	3c16800a */ 	lui	$s6,%hi(g_RoomPtrs)
/*  f133ab4:	26d64928 */ 	addiu	$s6,$s6,%lo(g_RoomPtrs)
/*  f133ab8:	27b10cb8 */ 	addiu	$s1,$sp,0xcb8
/*  f133abc:	27be070c */ 	addiu	$s8,$sp,0x70c
/*  f133ac0:	2413000c */ 	addiu	$s3,$zero,0xc
/*  f133ac4:	27b00964 */ 	addiu	$s0,$sp,0x964
.L0f133ac8:
/*  f133ac8:	0fc4ca87 */ 	jal	weatherIsRoomWeatherProof
/*  f133acc:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f133ad0:	10400025 */ 	beqz	$v0,.L0f133b68
/*  f133ad4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f133ad8:	8fa70708 */ 	lw	$a3,0x708($sp)
/*  f133adc:	8e260000 */ 	lw	$a2,0x0($s1)
/*  f133ae0:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f133ae4:	00f30019 */ 	multu	$a3,$s3
/*  f133ae8:	28e10032 */ 	slti	$at,$a3,0x32
/*  f133aec:	00002812 */ 	mflo	$a1
/*  f133af0:	02051821 */ 	addu	$v1,$s0,$a1
/*  f133af4:	03c52021 */ 	addu	$a0,$s8,$a1
/*  f133af8:	00d50019 */ 	multu	$a2,$s5
/*  f133afc:	00006812 */ 	mflo	$t5
/*  f133b00:	032d1021 */ 	addu	$v0,$t9,$t5
/*  f133b04:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f133b08:	46183103 */ 	div.s	$f4,$f6,$f24
/*  f133b0c:	e4640000 */ 	swc1	$f4,0x0($v1)
/*  f133b10:	c44a001c */ 	lwc1	$f10,0x1c($v0)
/*  f133b14:	46185203 */ 	div.s	$f8,$f10,$f24
/*  f133b18:	e4680004 */ 	swc1	$f8,0x4($v1)
/*  f133b1c:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f133b20:	46183103 */ 	div.s	$f4,$f6,$f24
/*  f133b24:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f133b28:	c44a0024 */ 	lwc1	$f10,0x24($v0)
/*  f133b2c:	46185203 */ 	div.s	$f8,$f10,$f24
/*  f133b30:	e4880000 */ 	swc1	$f8,0x0($a0)
/*  f133b34:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f133b38:	46183103 */ 	div.s	$f4,$f6,$f24
/*  f133b3c:	e4840004 */ 	swc1	$f4,0x4($a0)
/*  f133b40:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f133b44:	46185203 */ 	div.s	$f8,$f10,$f24
/*  f133b48:	10200007 */ 	beqz	$at,.L0f133b68
/*  f133b4c:	e4880008 */ 	swc1	$f8,0x8($a0)
/*  f133b50:	8fae0708 */ 	lw	$t6,0x708($sp)
/*  f133b54:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f133b58:	03b87821 */ 	addu	$t7,$sp,$t8
/*  f133b5c:	ade60bbc */ 	sw	$a2,0xbbc($t7)
/*  f133b60:	25cb0001 */ 	addiu	$t3,$t6,0x1
/*  f133b64:	afab0708 */ 	sw	$t3,0x708($sp)
.L0f133b68:
/*  f133b68:	1654ffd7 */ 	bne	$s2,$s4,.L0f133ac8
/*  f133b6c:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f133b70:
/*  f133b70:	8fac0708 */ 	lw	$t4,0x708($sp)
/*  f133b74:	3c16800a */ 	lui	$s6,%hi(g_RoomPtrs)
/*  f133b78:	26d64928 */ 	addiu	$s6,$s6,%lo(g_RoomPtrs)
/*  f133b7c:	00008025 */ 	or	$s0,$zero,$zero
/*  f133b80:	1980002d */ 	blez	$t4,.L0f133c38
/*  f133b84:	e7b40c84 */ 	swc1	$f20,0xc84($sp)
/*  f133b88:	8ec80000 */ 	lw	$t0,0x0($s6)
/*  f133b8c:	27a60258 */ 	addiu	$a2,$sp,0x258
/*  f133b90:	27b10bbc */ 	addiu	$s1,$sp,0xbbc
/*  f133b94:	8e390000 */ 	lw	$t9,0x0($s1)
.L0f133b98:
/*  f133b98:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f133b9c:	24c60018 */ 	addiu	$a2,$a2,0x18
/*  f133ba0:	03350019 */ 	multu	$t9,$s5
/*  f133ba4:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f133ba8:	00006812 */ 	mflo	$t5
/*  f133bac:	010d1021 */ 	addu	$v0,$t0,$t5
/*  f133bb0:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f133bb4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f133bb8:	440f2000 */ 	mfc1	$t7,$f4
/*  f133bbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133bc0:	accfffe8 */ 	sw	$t7,-0x18($a2)
/*  f133bc4:	c44a001c */ 	lwc1	$f10,0x1c($v0)
/*  f133bc8:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f133bcc:	440b4000 */ 	mfc1	$t3,$f8
/*  f133bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133bd4:	accbffec */ 	sw	$t3,-0x14($a2)
/*  f133bd8:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f133bdc:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f133be0:	44192000 */ 	mfc1	$t9,$f4
/*  f133be4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133be8:	acd9fff0 */ 	sw	$t9,-0x10($a2)
/*  f133bec:	c44a0024 */ 	lwc1	$f10,0x24($v0)
/*  f133bf0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f133bf4:	44184000 */ 	mfc1	$t8,$f8
/*  f133bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133bfc:	acd8fff4 */ 	sw	$t8,-0xc($a2)
/*  f133c00:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f133c04:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f133c08:	440e2000 */ 	mfc1	$t6,$f4
/*  f133c0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133c10:	accefff8 */ 	sw	$t6,-0x8($a2)
/*  f133c14:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f133c18:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f133c1c:	440c4000 */ 	mfc1	$t4,$f8
/*  f133c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133c24:	acccfffc */ 	sw	$t4,-0x4($a2)
/*  f133c28:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f133c2c:	5619ffda */ 	bnel	$s0,$t9,.L0f133b98
/*  f133c30:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f133c34:	e7b40c84 */ 	swc1	$f20,0xc84($sp)
.L0f133c38:
/*  f133c38:	3c16800a */ 	lui	$s6,%hi(g_RoomPtrs)
/*  f133c3c:	26d64928 */ 	addiu	$s6,$s6,%lo(g_RoomPtrs)
/*  f133c40:	2415008c */ 	addiu	$s5,$zero,0x8c
/*  f133c44:	c7b40c84 */ 	lwc1	$f20,0xc84($sp)
/*  f133c48:	0fc59e73 */ 	jal	func0f1679cc
/*  f133c4c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f133c50:	3c0d8008 */ 	lui	$t5,%hi(var8007f0e4)
/*  f133c54:	8dadf0e4 */ 	lw	$t5,%lo(var8007f0e4)($t5)
/*  f133c58:	3c188008 */ 	lui	$t8,%hi(var8007f0e8)
/*  f133c5c:	3c0b0704 */ 	lui	$t3,0x704
/*  f133c60:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f133c64:	8f18f0e8 */ 	lw	$t8,%lo(var8007f0e8)($t8)
/*  f133c68:	356b0008 */ 	ori	$t3,$t3,0x8
/*  f133c6c:	00402025 */ 	or	$a0,$v0,$zero
/*  f133c70:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f133c74:	8fb00de8 */ 	lw	$s0,0xde8($sp)
/*  f133c78:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f133c7c:	afae0de8 */ 	sw	$t6,0xde8($sp)
/*  f133c80:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f133c84:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f133c88:	0c012144 */ 	jal	osGetCount
/*  f133c8c:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f133c90:	afa20d84 */ 	sw	$v0,0xd84($sp)
/*  f133c94:	00001825 */ 	or	$v1,$zero,$zero
/*  f133c98:	02e09025 */ 	or	$s2,$s7,$zero
/*  f133c9c:	27be01c8 */ 	addiu	$s8,$sp,0x1c8
/*  f133ca0:	afa30088 */ 	sw	$v1,0x88($sp)
.L0f133ca4:
/*  f133ca4:	8e4c000c */ 	lw	$t4,0xc($s2)
/*  f133ca8:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f133cac:	31990003 */ 	andi	$t9,$t4,0x3
/*  f133cb0:	5320023b */ 	beqzl	$t9,.L0f1345a0
/*  f133cb4:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f133cb8:	0c012144 */ 	jal	osGetCount
/*  f133cbc:	afa30088 */ 	sw	$v1,0x88($sp)
/*  f133cc0:	afa20da0 */ 	sw	$v0,0xda0($sp)
/*  f133cc4:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f133cc8:	c6e63e80 */ 	lwc1	$f6,0x3e80($s7)
/*  f133ccc:	27a40108 */ 	addiu	$a0,$sp,0x108
/*  f133cd0:	3c054316 */ 	lui	$a1,0x4316
/*  f133cd4:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f133cd8:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f133cdc:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f133ce0:	c6e83e84 */ 	lwc1	$f8,0x3e84($s7)
/*  f133ce4:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f133ce8:	e7a4010c */ 	swc1	$f4,0x10c($sp)
/*  f133cec:	c6480008 */ 	lwc1	$f8,0x8($s2)
/*  f133cf0:	c6ea3e88 */ 	lwc1	$f10,0x3e88($s7)
/*  f133cf4:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f133cf8:	0fc2d6e7 */ 	jal	func0f0b5b9c
/*  f133cfc:	e7a60110 */ 	swc1	$f6,0x110($sp)
/*  f133d00:	50400227 */ 	beqzl	$v0,.L0f1345a0
/*  f133d04:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f133d08:	0c012144 */ 	jal	osGetCount
/*  f133d0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133d10:	8fad0dcc */ 	lw	$t5,0xdcc($sp)
/*  f133d14:	8faf0da0 */ 	lw	$t7,0xda0($sp)
/*  f133d18:	01a2c021 */ 	addu	$t8,$t5,$v0
/*  f133d1c:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f133d20:	afae0dcc */ 	sw	$t6,0xdcc($sp)
/*  f133d24:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f133d28:	e7a40218 */ 	swc1	$f4,0x218($sp)
/*  f133d2c:	c64a0008 */ 	lwc1	$f10,0x8($s2)
/*  f133d30:	c7a40218 */ 	lwc1	$f4,0x218($sp)
/*  f133d34:	e7aa021c */ 	swc1	$f10,0x21c($sp)
/*  f133d38:	c7a8021c */ 	lwc1	$f8,0x21c($sp)
/*  f133d3c:	46084182 */ 	mul.s	$f6,$f8,$f8
/*  f133d40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133d44:	46042282 */ 	mul.s	$f10,$f4,$f4
/*  f133d48:	0c012974 */ 	jal	sqrtf
/*  f133d4c:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f133d50:	3c017f1b */ 	lui	$at,%hi(var7f1b5780)
/*  f133d54:	c4285780 */ 	lwc1	$f8,%lo(var7f1b5780)($at)
/*  f133d58:	8fab0194 */ 	lw	$t3,0x194($sp)
/*  f133d5c:	e7a00214 */ 	swc1	$f0,0x214($sp)
/*  f133d60:	4608003c */ 	c.lt.s	$f0,$f8
/*  f133d64:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f133d68:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f133d6c:	000cc880 */ 	sll	$t9,$t4,0x2
/*  f133d70:	4501020a */ 	bc1t	.L0f13459c
/*  f133d74:	032cc823 */ 	subu	$t9,$t9,$t4
/*  f133d78:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f133d7c:	15600004 */ 	bnez	$t3,.L0f133d90
/*  f133d80:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f133d84:	0fc59e59 */ 	jal	func0f167964
/*  f133d88:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f133d8c:	afa20210 */ 	sw	$v0,0x210($sp)
.L0f133d90:
/*  f133d90:	c7a40218 */ 	lwc1	$f4,0x218($sp)
/*  f133d94:	c7a60214 */ 	lwc1	$f6,0x214($sp)
/*  f133d98:	c7a8021c */ 	lwc1	$f8,0x21c($sp)
/*  f133d9c:	8fad0210 */ 	lw	$t5,0x210($sp)
/*  f133da0:	46062283 */ 	div.s	$f10,$f4,$f6
/*  f133da4:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f133da8:	27a20198 */ 	addiu	$v0,$sp,0x198
/*  f133dac:	01b81821 */ 	addu	$v1,$t5,$t8
/*  f133db0:	46064103 */ 	div.s	$f4,$f8,$f6
/*  f133db4:	e7aa0218 */ 	swc1	$f10,0x218($sp)
/*  f133db8:	e7a4021c */ 	swc1	$f4,0x21c($sp)
.L0f133dbc:
/*  f133dbc:	a4600008 */ 	sh	$zero,0x8($v1)
/*  f133dc0:	a460000a */ 	sh	$zero,0xa($v1)
/*  f133dc4:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f133dc8:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f133dcc:	005e082b */ 	sltu	$at,$v0,$s8
/*  f133dd0:	e44afff4 */ 	swc1	$f10,-0xc($v0)
/*  f133dd4:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*  f133dd8:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f133ddc:	e448fff8 */ 	swc1	$f8,-0x8($v0)
/*  f133de0:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f133de4:	1420fff5 */ 	bnez	$at,.L0f133dbc
/*  f133de8:	e446fffc */ 	swc1	$f6,-0x4($v0)
/*  f133dec:	0c012144 */ 	jal	osGetCount
/*  f133df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133df4:	0c012144 */ 	jal	osGetCount
/*  f133df8:	afa20d88 */ 	sw	$v0,0xd88($sp)
/*  f133dfc:	3c0f8008 */ 	lui	$t7,%hi(var8007f0f4)
/*  f133e00:	8deff0f4 */ 	lw	$t7,%lo(var8007f0f4)($t7)
/*  f133e04:	afa20d8c */ 	sw	$v0,0xd8c($sp)
/*  f133e08:	8fae0708 */ 	lw	$t6,0x708($sp)
/*  f133e0c:	11e000a3 */ 	beqz	$t7,.L0f13409c
/*  f133e10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133e14:	19c000a1 */ 	blez	$t6,.L0f13409c
/*  f133e18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133e1c:	c6e43e80 */ 	lwc1	$f4,0x3e80($s7)
/*  f133e20:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f133e24:	3c0c8008 */ 	lui	$t4,%hi(var8007f0ec)
/*  f133e28:	8d8cf0ec */ 	lw	$t4,%lo(var8007f0ec)($t4)
/*  f133e2c:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f133e30:	8fa20dec */ 	lw	$v0,0xdec($sp)
/*  f133e34:	3c014f80 */ 	lui	$at,0x4f80
/*  f133e38:	46144082 */ 	mul.s	$f2,$f8,$f20
/*  f133e3c:	e7a20c90 */ 	swc1	$f2,0xc90($sp)
/*  f133e40:	e7a20ca8 */ 	swc1	$f2,0xca8($sp)
/*  f133e44:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f133e48:	c6e63e84 */ 	lwc1	$f6,0x3e84($s7)
/*  f133e4c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f133e50:	46145082 */ 	mul.s	$f2,$f10,$f20
/*  f133e54:	448c5000 */ 	mtc1	$t4,$f10
/*  f133e58:	e7a20c94 */ 	swc1	$f2,0xc94($sp)
/*  f133e5c:	e7a20cac */ 	swc1	$f2,0xcac($sp)
/*  f133e60:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f133e64:	c6e83e88 */ 	lwc1	$f8,0x3e88($s7)
/*  f133e68:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f133e6c:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f133e70:	46142082 */ 	mul.s	$f2,$f4,$f20
/*  f133e74:	e7a20c98 */ 	swc1	$f2,0xc98($sp)
/*  f133e78:	05810004 */ 	bgez	$t4,.L0f133e8c
/*  f133e7c:	e7a20cb0 */ 	swc1	$f2,0xcb0($sp)
/*  f133e80:	44813000 */ 	mtc1	$at,$f6
/*  f133e84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133e88:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f133e8c:
/*  f133e8c:	3c014120 */ 	lui	$at,0x4120
/*  f133e90:	44812000 */ 	mtc1	$at,$f4
/*  f133e94:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f133e98:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f133e9c:	46044003 */ 	div.s	$f0,$f8,$f4
/*  f133ea0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f133ea4:	c6e63e80 */ 	lwc1	$f6,0x3e80($s7)
/*  f133ea8:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f133eac:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f133eb0:	46145202 */ 	mul.s	$f8,$f10,$f20
/*  f133eb4:	e7a80c9c */ 	swc1	$f8,0xc9c($sp)
/*  f133eb8:	c44400b8 */ 	lwc1	$f4,0xb8($v0)
/*  f133ebc:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f133ec0:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f133ec4:	c6e63e84 */ 	lwc1	$f6,0x3e84($s7)
/*  f133ec8:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f133ecc:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f133ed0:	e7a60ca0 */ 	swc1	$f6,0xca0($sp)
/*  f133ed4:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f133ed8:	c64a0008 */ 	lwc1	$f10,0x8($s2)
/*  f133edc:	46002102 */ 	mul.s	$f4,$f4,$f0
/*  f133ee0:	46045281 */ 	sub.s	$f10,$f10,$f4
/*  f133ee4:	c6e43e88 */ 	lwc1	$f4,0x3e88($s7)
/*  f133ee8:	460a2100 */ 	add.s	$f4,$f4,$f10
/*  f133eec:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f133ef0:	c7a40c90 */ 	lwc1	$f4,0xc90($sp)
/*  f133ef4:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f133ef8:	e7aa0ca4 */ 	swc1	$f10,0xca4($sp)
/*  f133efc:	e7a400fc */ 	swc1	$f4,0xfc($sp)
/*  f133f00:	c7a40c94 */ 	lwc1	$f4,0xc94($sp)
/*  f133f04:	46043181 */ 	sub.s	$f6,$f6,$f4
/*  f133f08:	46025101 */ 	sub.s	$f4,$f10,$f2
/*  f133f0c:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f133f10:	c7a60ca8 */ 	lwc1	$f6,0xca8($sp)
/*  f133f14:	c7aa0ca8 */ 	lwc1	$f10,0xca8($sp)
/*  f133f18:	e7a40104 */ 	swc1	$f4,0x104($sp)
/*  f133f1c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f133f20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133f24:	45020004 */ 	bc1fl	.L0f133f38
/*  f133f28:	c7ac0cac */ 	lwc1	$f12,0xcac($sp)
/*  f133f2c:	e7aa0c9c */ 	swc1	$f10,0xc9c($sp)
/*  f133f30:	e7a80ca8 */ 	swc1	$f8,0xca8($sp)
/*  f133f34:	c7ac0cac */ 	lwc1	$f12,0xcac($sp)
.L0f133f38:
/*  f133f38:	c7ae0ca0 */ 	lwc1	$f14,0xca0($sp)
/*  f133f3c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f133f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133f44:	45020004 */ 	bc1fl	.L0f133f58
/*  f133f48:	c7ac0ca4 */ 	lwc1	$f12,0xca4($sp)
/*  f133f4c:	e7ae0cac */ 	swc1	$f14,0xcac($sp)
/*  f133f50:	e7ac0ca0 */ 	swc1	$f12,0xca0($sp)
/*  f133f54:	c7ac0ca4 */ 	lwc1	$f12,0xca4($sp)
.L0f133f58:
/*  f133f58:	460c103c */ 	c.lt.s	$f2,$f12
/*  f133f5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133f60:	45000003 */ 	bc1f	.L0f133f70
/*  f133f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133f68:	e7ac0cb0 */ 	swc1	$f12,0xcb0($sp)
/*  f133f6c:	e7a20ca4 */ 	swc1	$f2,0xca4($sp)
.L0f133f70:
/*  f133f70:	0c012144 */ 	jal	osGetCount
/*  f133f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133f78:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f133f7c:	afa20d90 */ 	sw	$v0,0xd90($sp)
/*  f133f80:	00008025 */ 	or	$s0,$zero,$zero
/*  f133f84:	1b20003e */ 	blez	$t9,.L0f134080
/*  f133f88:	27b10bbc */ 	addiu	$s1,$sp,0xbbc
/*  f133f8c:	8e2d0000 */ 	lw	$t5,0x0($s1)
.L0f133f90:
/*  f133f90:	8ecb0000 */ 	lw	$t3,0x0($s6)
/*  f133f94:	c7a60c9c */ 	lwc1	$f6,0xc9c($sp)
/*  f133f98:	01b50019 */ 	multu	$t5,$s5
/*  f133f9c:	c7a80ca8 */ 	lwc1	$f8,0xca8($sp)
/*  f133fa0:	0000c012 */ 	mflo	$t8
/*  f133fa4:	01781021 */ 	addu	$v0,$t3,$t8
/*  f133fa8:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*  f133fac:	4604303e */ 	c.le.s	$f6,$f4
/*  f133fb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133fb4:	4502002e */ 	bc1fl	.L0f134070
/*  f133fb8:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f133fbc:	c44a0018 */ 	lwc1	$f10,0x18($v0)
/*  f133fc0:	c7a60ca4 */ 	lwc1	$f6,0xca4($sp)
/*  f133fc4:	4608503e */ 	c.le.s	$f10,$f8
/*  f133fc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133fcc:	45020028 */ 	bc1fl	.L0f134070
/*  f133fd0:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f133fd4:	c444002c */ 	lwc1	$f4,0x2c($v0)
/*  f133fd8:	c7a80cb0 */ 	lwc1	$f8,0xcb0($sp)
/*  f133fdc:	4604303e */ 	c.le.s	$f6,$f4
/*  f133fe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133fe4:	45020022 */ 	bc1fl	.L0f134070
/*  f133fe8:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f133fec:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f133ff0:	c7a60ca0 */ 	lwc1	$f6,0xca0($sp)
/*  f133ff4:	4608503e */ 	c.le.s	$f10,$f8
/*  f133ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133ffc:	4502001c */ 	bc1fl	.L0f134070
/*  f134000:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f134004:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f134008:	c7a80cac */ 	lwc1	$f8,0xcac($sp)
/*  f13400c:	4604303e */ 	c.le.s	$f6,$f4
/*  f134010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134014:	45020016 */ 	bc1fl	.L0f134070
/*  f134018:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f13401c:	c44a001c */ 	lwc1	$f10,0x1c($v0)
/*  f134020:	3c0f8008 */ 	lui	$t7,%hi(var8007f0f8)
/*  f134024:	4608503e */ 	c.le.s	$f10,$f8
/*  f134028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13402c:	45020010 */ 	bc1fl	.L0f134070
/*  f134030:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f134034:	8deff0f8 */ 	lw	$t7,%lo(var8007f0f8)($t7)
/*  f134038:	27a40c90 */ 	addiu	$a0,$sp,0xc90
/*  f13403c:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*  f134040:	11e0000a */ 	beqz	$t7,.L0f13406c
/*  f134044:	00107080 */ 	sll	$t6,$s0,0x2
/*  f134048:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f13404c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f134050:	27ac0258 */ 	addiu	$t4,$sp,0x258
/*  f134054:	01cc3021 */ 	addu	$a2,$t6,$t4
/*  f134058:	0fc57c83 */ 	jal	func0f15f20c
/*  f13405c:	24c7000c */ 	addiu	$a3,$a2,0xc
/*  f134060:	50400003 */ 	beqzl	$v0,.L0f134070
/*  f134064:	8fb90708 */ 	lw	$t9,0x708($sp)
/*  f134068:	00009825 */ 	or	$s3,$zero,$zero
.L0f13406c:
/*  f13406c:	8fb90708 */ 	lw	$t9,0x708($sp)
.L0f134070:
/*  f134070:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f134074:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f134078:	5619ffc5 */ 	bnel	$s0,$t9,.L0f133f90
/*  f13407c:	8e2d0000 */ 	lw	$t5,0x0($s1)
.L0f134080:
/*  f134080:	0c012144 */ 	jal	osGetCount
/*  f134084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134088:	8fad0dbc */ 	lw	$t5,0xdbc($sp)
/*  f13408c:	8fb80d90 */ 	lw	$t8,0xd90($sp)
/*  f134090:	01a25821 */ 	addu	$t3,$t5,$v0
/*  f134094:	01787823 */ 	subu	$t7,$t3,$t8
/*  f134098:	afaf0dbc */ 	sw	$t7,0xdbc($sp)
.L0f13409c:
/*  f13409c:	0c012144 */ 	jal	osGetCount
/*  f1340a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1340a4:	8fae0db8 */ 	lw	$t6,0xdb8($sp)
/*  f1340a8:	8fb90d8c */ 	lw	$t9,0xd8c($sp)
/*  f1340ac:	8fab0210 */ 	lw	$t3,0x210($sp)
/*  f1340b0:	01c26021 */ 	addu	$t4,$t6,$v0
/*  f1340b4:	01996823 */ 	subu	$t5,$t4,$t9
/*  f1340b8:	12600138 */ 	beqz	$s3,.L0f13459c
/*  f1340bc:	afad0db8 */ 	sw	$t5,0xdb8($sp)
/*  f1340c0:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f1340c4:	0c012144 */ 	jal	osGetCount
/*  f1340c8:	01789821 */ 	addu	$s3,$t3,$t8
/*  f1340cc:	3c0f8008 */ 	lui	$t7,%hi(var8007f0f0)
/*  f1340d0:	8deff0f0 */ 	lw	$t7,%lo(var8007f0f0)($t7)
/*  f1340d4:	c7ac021c */ 	lwc1	$f12,0x21c($sp)
/*  f1340d8:	afa20d94 */ 	sw	$v0,0xd94($sp)
/*  f1340dc:	448f2000 */ 	mtc1	$t7,$f4
/*  f1340e0:	46006307 */ 	neg.s	$f12,$f12
/*  f1340e4:	05e10005 */ 	bgez	$t7,.L0f1340fc
/*  f1340e8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1340ec:	3c014f80 */ 	lui	$at,0x4f80
/*  f1340f0:	44814000 */ 	mtc1	$at,$f8
/*  f1340f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1340f8:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f1340fc:
/*  f1340fc:	3c014120 */ 	lui	$at,0x4120
/*  f134100:	44815000 */ 	mtc1	$at,$f10
/*  f134104:	c7a80214 */ 	lwc1	$f8,0x214($sp)
/*  f134108:	3c0e8008 */ 	lui	$t6,%hi(var8007f0e0)
/*  f13410c:	460a3103 */ 	div.s	$f4,$f6,$f10
/*  f134110:	8dcef0e0 */ 	lw	$t6,%lo(var8007f0e0)($t6)
/*  f134114:	3c014f80 */ 	lui	$at,0x4f80
/*  f134118:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f13411c:	448e4000 */ 	mtc1	$t6,$f8
/*  f134120:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134124:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f134128:	05c10004 */ 	bgez	$t6,.L0f13413c
/*  f13412c:	4606c280 */ 	add.s	$f10,$f24,$f6
/*  f134130:	44813000 */ 	mtc1	$at,$f6
/*  f134134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134138:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f13413c:
/*  f13413c:	460a2082 */ 	mul.s	$f2,$f4,$f10
/*  f134140:	c7a80198 */ 	lwc1	$f8,0x198($sp)
/*  f134144:	c7a40218 */ 	lwc1	$f4,0x218($sp)
/*  f134148:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
/*  f13414c:	3c0c8008 */ 	lui	$t4,%hi(var8007f0ec)
/*  f134150:	8d8cf0ec */ 	lw	$t4,%lo(var8007f0ec)($t4)
/*  f134154:	3c014f80 */ 	lui	$at,0x4f80
/*  f134158:	46001387 */ 	neg.s	$f14,$f2
/*  f13415c:	460e6402 */ 	mul.s	$f16,$f12,$f14
/*  f134160:	46104180 */ 	add.s	$f6,$f8,$f16
/*  f134164:	460e2482 */ 	mul.s	$f18,$f4,$f14
/*  f134168:	e7a60198 */ 	swc1	$f6,0x198($sp)
/*  f13416c:	46026182 */ 	mul.s	$f6,$f12,$f2
/*  f134170:	46125200 */ 	add.s	$f8,$f10,$f18
/*  f134174:	c7aa01a4 */ 	lwc1	$f10,0x1a4($sp)
/*  f134178:	e7a60090 */ 	swc1	$f6,0x90($sp)
/*  f13417c:	e7a801a0 */ 	swc1	$f8,0x1a0($sp)
/*  f134180:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f134184:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f134188:	46022282 */ 	mul.s	$f10,$f4,$f2
/*  f13418c:	e7a601a4 */ 	swc1	$f6,0x1a4($sp)
/*  f134190:	c7a601ac */ 	lwc1	$f6,0x1ac($sp)
/*  f134194:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f134198:	448c3000 */ 	mtc1	$t4,$f6
/*  f13419c:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f1341a0:	e7a401ac */ 	swc1	$f4,0x1ac($sp)
/*  f1341a4:	05810004 */ 	bgez	$t4,.L0f1341b8
/*  f1341a8:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f1341ac:	44813000 */ 	mtc1	$at,$f6
/*  f1341b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1341b4:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f1341b8:
/*  f1341b8:	3c014120 */ 	lui	$at,0x4120
/*  f1341bc:	44813000 */ 	mtc1	$at,$f6
/*  f1341c0:	8fb90dec */ 	lw	$t9,0xdec($sp)
/*  f1341c4:	8fad0dec */ 	lw	$t5,0xdec($sp)
/*  f1341c8:	46062003 */ 	div.s	$f0,$f4,$f6
/*  f1341cc:	c7240000 */ 	lwc1	$f4,0x0($t9)
/*  f1341d0:	8fab0dec */ 	lw	$t3,0xdec($sp)
/*  f1341d4:	8fb80dec */ 	lw	$t8,0xdec($sp)
/*  f1341d8:	8faf0dec */ 	lw	$t7,0xdec($sp)
/*  f1341dc:	8fae0dec */ 	lw	$t6,0xdec($sp)
/*  f1341e0:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f1341e4:	24190004 */ 	addiu	$t9,$zero,0x4
/*  f1341e8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f1341ec:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f1341f0:	c7a601bc */ 	lwc1	$f6,0x1bc($sp)
/*  f1341f4:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f1341f8:	c7a601c0 */ 	lwc1	$f6,0x1c0($sp)
/*  f1341fc:	e7a801bc */ 	swc1	$f8,0x1bc($sp)
/*  f134200:	c5a400b8 */ 	lwc1	$f4,0xb8($t5)
/*  f134204:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f134208:	e7a801c0 */ 	swc1	$f8,0x1c0($sp)
/*  f13420c:	c5660004 */ 	lwc1	$f6,0x4($t3)
/*  f134210:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f134214:	c7a601c4 */ 	lwc1	$f6,0x1c4($sp)
/*  f134218:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f13421c:	c7aa01b0 */ 	lwc1	$f10,0x1b0($sp)
/*  f134220:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f134224:	e7a401c4 */ 	swc1	$f4,0x1c4($sp)
/*  f134228:	c7060000 */ 	lwc1	$f6,0x0($t8)
/*  f13422c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f134230:	46104100 */ 	add.s	$f4,$f8,$f16
/*  f134234:	c7a801b4 */ 	lwc1	$f8,0x1b4($sp)
/*  f134238:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f13423c:	e7a601b0 */ 	swc1	$f6,0x1b0($sp)
/*  f134240:	c5ea00b8 */ 	lwc1	$f10,0xb8($t7)
/*  f134244:	c7a601b8 */ 	lwc1	$f6,0x1b8($sp)
/*  f134248:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f13424c:	e7a401b4 */ 	swc1	$f4,0x1b4($sp)
/*  f134250:	c5c80004 */ 	lwc1	$f8,0x4($t6)
/*  f134254:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f134258:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f13425c:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f134260:	e7a801b8 */ 	swc1	$f8,0x1b8($sp)
/*  f134264:	a2600007 */ 	sb	$zero,0x7($s3)
/*  f134268:	a2600013 */ 	sb	$zero,0x13($s3)
/*  f13426c:	a26c001f */ 	sb	$t4,0x1f($s3)
/*  f134270:	a279002b */ 	sb	$t9,0x2b($s3)
/*  f134274:	8fad0d80 */ 	lw	$t5,0xd80($sp)
/*  f134278:	19a0005a */ 	blez	$t5,.L0f1343e4
/*  f13427c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134280:	c6ea3e80 */ 	lwc1	$f10,0x3e80($s7)
/*  f134284:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f134288:	00008025 */ 	or	$s0,$zero,$zero
/*  f13428c:	27b10cb8 */ 	addiu	$s1,$sp,0xcb8
/*  f134290:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f134294:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f134298:	e7a800e4 */ 	swc1	$f8,0xe4($sp)
/*  f13429c:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f1342a0:	c6ea3e84 */ 	lwc1	$f10,0x3e84($s7)
/*  f1342a4:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f1342a8:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f1342ac:	e7a800e8 */ 	swc1	$f8,0xe8($sp)
/*  f1342b0:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f1342b4:	c6ea3e88 */ 	lwc1	$f10,0x3e88($s7)
/*  f1342b8:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f1342bc:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f1342c0:	1a800048 */ 	blez	$s4,.L0f1343e4
/*  f1342c4:	e7a800ec */ 	swc1	$f8,0xec($sp)
.L0f1342c8:
/*  f1342c8:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f1342cc:	8ecb0000 */ 	lw	$t3,0x0($s6)
/*  f1342d0:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*  f1342d4:	00950019 */ 	multu	$a0,$s5
/*  f1342d8:	0000c012 */ 	mflo	$t8
/*  f1342dc:	01781021 */ 	addu	$v0,$t3,$t8
/*  f1342e0:	c44a0024 */ 	lwc1	$f10,0x24($v0)
/*  f1342e4:	460a303e */ 	c.le.s	$f6,$f10
/*  f1342e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1342ec:	4502003b */ 	bc1fl	.L0f1343dc
/*  f1342f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1342f4:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f1342f8:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f1342fc:	4606203e */ 	c.le.s	$f4,$f6
/*  f134300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134304:	45020035 */ 	bc1fl	.L0f1343dc
/*  f134308:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f13430c:	c448002c */ 	lwc1	$f8,0x2c($v0)
/*  f134310:	4608503e */ 	c.le.s	$f10,$f8
/*  f134314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134318:	45020030 */ 	bc1fl	.L0f1343dc
/*  f13431c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f134320:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f134324:	c7a800e8 */ 	lwc1	$f8,0xe8($sp)
/*  f134328:	460a303e */ 	c.le.s	$f6,$f10
/*  f13432c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134330:	4502002a */ 	bc1fl	.L0f1343dc
/*  f134334:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f134338:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f13433c:	4604403e */ 	c.le.s	$f8,$f4
/*  f134340:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134344:	45020025 */ 	bc1fl	.L0f1343dc
/*  f134348:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f13434c:	c440001c */ 	lwc1	$f0,0x1c($v0)
/*  f134350:	4608003e */ 	c.le.s	$f0,$f8
/*  f134354:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134358:	45020020 */ 	bc1fl	.L0f1343dc
/*  f13435c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f134360:	c64a0014 */ 	lwc1	$f10,0x14($s2)
/*  f134364:	46165182 */ 	mul.s	$f6,$f10,$f22
/*  f134368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13436c:	4606a102 */ 	mul.s	$f4,$f20,$f6
/*  f134370:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f134374:	4600503c */ 	c.lt.s	$f10,$f0
/*  f134378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13437c:	45000016 */ 	bc1f	.L0f1343d8
/*  f134380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134384:	c6e63e80 */ 	lwc1	$f6,0x3e80($s7)
/*  f134388:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f13438c:	240f000f */ 	addiu	$t7,$zero,0xf
/*  f134390:	00002825 */ 	or	$a1,$zero,$zero
/*  f134394:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f134398:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f13439c:	26470010 */ 	addiu	$a3,$s2,0x10
/*  f1343a0:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f1343a4:	c44a001c */ 	lwc1	$f10,0x1c($v0)
/*  f1343a8:	46145183 */ 	div.s	$f6,$f10,$f20
/*  f1343ac:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f1343b0:	c6440008 */ 	lwc1	$f4,0x8($s2)
/*  f1343b4:	c6e83e88 */ 	lwc1	$f8,0x3e88($s7)
/*  f1343b8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1343bc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1343c0:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f1343c4:	0fc4be7c */ 	jal	func0f12f9f0
/*  f1343c8:	e7aa00dc */ 	swc1	$f10,0xdc($sp)
/*  f1343cc:	8fae0d80 */ 	lw	$t6,0xd80($sp)
/*  f1343d0:	25ccffff */ 	addiu	$t4,$t6,-1
/*  f1343d4:	afac0d80 */ 	sw	$t4,0xd80($sp)
.L0f1343d8:
/*  f1343d8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1343dc:
/*  f1343dc:	1614ffba */ 	bne	$s0,$s4,.L0f1342c8
/*  f1343e0:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f1343e4:
/*  f1343e4:	0c012144 */ 	jal	osGetCount
/*  f1343e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1343ec:	8fb90dc0 */ 	lw	$t9,0xdc0($sp)
/*  f1343f0:	8fab0d94 */ 	lw	$t3,0xd94($sp)
/*  f1343f4:	03226821 */ 	addu	$t5,$t9,$v0
/*  f1343f8:	01abc023 */ 	subu	$t8,$t5,$t3
/*  f1343fc:	0c012144 */ 	jal	osGetCount
/*  f134400:	afb80dc0 */ 	sw	$t8,0xdc0($sp)
/*  f134404:	afa20d98 */ 	sw	$v0,0xd98($sp)
/*  f134408:	24030100 */ 	addiu	$v1,$zero,0x100
/*  f13440c:	a663000a */ 	sh	$v1,0xa($s3)
/*  f134410:	a6630014 */ 	sh	$v1,0x14($s3)
/*  f134414:	a6630016 */ 	sh	$v1,0x16($s3)
/*  f134418:	a6630020 */ 	sh	$v1,0x20($s3)
/*  f13441c:	a660002e */ 	sh	$zero,0x2e($s3)
/*  f134420:	a660002c */ 	sh	$zero,0x2c($s3)
/*  f134424:	a6600022 */ 	sh	$zero,0x22($s3)
/*  f134428:	0c012144 */ 	jal	osGetCount
/*  f13442c:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f134430:	8faf0dc4 */ 	lw	$t7,0xdc4($sp)
/*  f134434:	8fac0d98 */ 	lw	$t4,0xd98($sp)
/*  f134438:	01e27021 */ 	addu	$t6,$t7,$v0
/*  f13443c:	01ccc823 */ 	subu	$t9,$t6,$t4
/*  f134440:	0c012144 */ 	jal	osGetCount
/*  f134444:	afb90dc4 */ 	sw	$t9,0xdc4($sp)
/*  f134448:	c7a60198 */ 	lwc1	$f6,0x198($sp)
/*  f13444c:	afa20d9c */ 	sw	$v0,0xd9c($sp)
/*  f134450:	24010003 */ 	addiu	$at,$zero,0x3
/*  f134454:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f134458:	440b4000 */ 	mfc1	$t3,$f8
/*  f13445c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134460:	a66b0000 */ 	sh	$t3,0x0($s3)
/*  f134464:	c7a4019c */ 	lwc1	$f4,0x19c($sp)
/*  f134468:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f13446c:	440f5000 */ 	mfc1	$t7,$f10
/*  f134470:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134474:	a66f0002 */ 	sh	$t7,0x2($s3)
/*  f134478:	c7a601a0 */ 	lwc1	$f6,0x1a0($sp)
/*  f13447c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f134480:	440c4000 */ 	mfc1	$t4,$f8
/*  f134484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134488:	a66c0004 */ 	sh	$t4,0x4($s3)
/*  f13448c:	c7a401a4 */ 	lwc1	$f4,0x1a4($sp)
/*  f134490:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f134494:	440d5000 */ 	mfc1	$t5,$f10
/*  f134498:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13449c:	a66d000c */ 	sh	$t5,0xc($s3)
/*  f1344a0:	c7a601a8 */ 	lwc1	$f6,0x1a8($sp)
/*  f1344a4:	3c0d04b0 */ 	lui	$t5,0x4b0
/*  f1344a8:	35ad0090 */ 	ori	$t5,$t5,0x90
/*  f1344ac:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1344b0:	44184000 */ 	mfc1	$t8,$f8
/*  f1344b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1344b8:	a678000e */ 	sh	$t8,0xe($s3)
/*  f1344bc:	c7a401ac */ 	lwc1	$f4,0x1ac($sp)
/*  f1344c0:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f1344c4:	440e5000 */ 	mfc1	$t6,$f10
/*  f1344c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1344cc:	a66e0010 */ 	sh	$t6,0x10($s3)
/*  f1344d0:	c7a601b0 */ 	lwc1	$f6,0x1b0($sp)
/*  f1344d4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1344d8:	44194000 */ 	mfc1	$t9,$f8
/*  f1344dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1344e0:	a6790018 */ 	sh	$t9,0x18($s3)
/*  f1344e4:	c7a401b4 */ 	lwc1	$f4,0x1b4($sp)
/*  f1344e8:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f1344ec:	440b5000 */ 	mfc1	$t3,$f10
/*  f1344f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1344f4:	a66b001a */ 	sh	$t3,0x1a($s3)
/*  f1344f8:	c7a601b8 */ 	lwc1	$f6,0x1b8($sp)
/*  f1344fc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f134500:	440f4000 */ 	mfc1	$t7,$f8
/*  f134504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134508:	a66f001c */ 	sh	$t7,0x1c($s3)
/*  f13450c:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f134510:	8fac0194 */ 	lw	$t4,0x194($sp)
/*  f134514:	8fb00de8 */ 	lw	$s0,0xde8($sp)
/*  f134518:	15c10012 */ 	bne	$t6,$at,.L0f134564
/*  f13451c:	25990001 */ 	addiu	$t9,$t4,0x1
/*  f134520:	26190008 */ 	addiu	$t9,$s0,0x8
/*  f134524:	afb90de8 */ 	sw	$t9,0xde8($sp)
/*  f134528:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f13452c:	afa00194 */ 	sw	$zero,0x194($sp)
/*  f134530:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f134534:	8fa40210 */ 	lw	$a0,0x210($sp)
/*  f134538:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f13453c:	8fab0de8 */ 	lw	$t3,0xde8($sp)
/*  f134540:	3c0fb100 */ 	lui	$t7,0xb100
/*  f134544:	3c0ea976 */ 	lui	$t6,0xa976
/*  f134548:	25780008 */ 	addiu	$t8,$t3,0x8
/*  f13454c:	afb80de8 */ 	sw	$t8,0xde8($sp)
/*  f134550:	35ce4310 */ 	ori	$t6,$t6,0x4310
/*  f134554:	35efb852 */ 	ori	$t7,$t7,0xb852
/*  f134558:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f13455c:	10000002 */ 	beqz	$zero,.L0f134568
/*  f134560:	ad6e0004 */ 	sw	$t6,0x4($t3)
.L0f134564:
/*  f134564:	afb90194 */ 	sw	$t9,0x194($sp)
.L0f134568:
/*  f134568:	0c012144 */ 	jal	osGetCount
/*  f13456c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134570:	8fad0dc8 */ 	lw	$t5,0xdc8($sp)
/*  f134574:	8fb80d9c */ 	lw	$t8,0xd9c($sp)
/*  f134578:	01a25821 */ 	addu	$t3,$t5,$v0
/*  f13457c:	01787823 */ 	subu	$t7,$t3,$t8
/*  f134580:	0c012144 */ 	jal	osGetCount
/*  f134584:	afaf0dc8 */ 	sw	$t7,0xdc8($sp)
/*  f134588:	8fae0db4 */ 	lw	$t6,0xdb4($sp)
/*  f13458c:	8fb90d88 */ 	lw	$t9,0xd88($sp)
/*  f134590:	01c26021 */ 	addu	$t4,$t6,$v0
/*  f134594:	01996823 */ 	subu	$t5,$t4,$t9
/*  f134598:	afad0db4 */ 	sw	$t5,0xdb4($sp)
.L0f13459c:
/*  f13459c:	8fa30088 */ 	lw	$v1,0x88($sp)
.L0f1345a0:
/*  f1345a0:	24013e80 */ 	addiu	$at,$zero,0x3e80
/*  f1345a4:	26520020 */ 	addiu	$s2,$s2,0x20
/*  f1345a8:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f1345ac:	5461fdbd */ 	bnel	$v1,$at,.L0f133ca4
/*  f1345b0:	afa30088 */ 	sw	$v1,0x88($sp)
/*  f1345b4:	8fab0194 */ 	lw	$t3,0x194($sp)
/*  f1345b8:	8fb00de8 */ 	lw	$s0,0xde8($sp)
/*  f1345bc:	3c0e04b0 */ 	lui	$t6,0x4b0
/*  f1345c0:	19600029 */ 	blez	$t3,.L0f134668
/*  f1345c4:	260f0008 */ 	addiu	$t7,$s0,0x8
/*  f1345c8:	afaf0de8 */ 	sw	$t7,0xde8($sp)
/*  f1345cc:	35ce0090 */ 	ori	$t6,$t6,0x90
/*  f1345d0:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f1345d4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1345d8:	8fa40210 */ 	lw	$a0,0x210($sp)
/*  f1345dc:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f1345e0:	8fac0194 */ 	lw	$t4,0x194($sp)
/*  f1345e4:	8fb90de8 */ 	lw	$t9,0xde8($sp)
/*  f1345e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1345ec:	15810007 */ 	bne	$t4,$at,.L0f13460c
/*  f1345f0:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f1345f4:	afad0de8 */ 	sw	$t5,0xde8($sp)
/*  f1345f8:	3c0bb100 */ 	lui	$t3,0xb100
/*  f1345fc:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f134600:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f134604:	af380004 */ 	sw	$t8,0x4($t9)
/*  f134608:	af2b0000 */ 	sw	$t3,0x0($t9)
.L0f13460c:
/*  f13460c:	8faf0194 */ 	lw	$t7,0x194($sp)
/*  f134610:	8fae0de8 */ 	lw	$t6,0xde8($sp)
/*  f134614:	24010002 */ 	addiu	$at,$zero,0x2
/*  f134618:	15e10007 */ 	bne	$t7,$at,.L0f134638
/*  f13461c:	25cc0008 */ 	addiu	$t4,$t6,0x8
/*  f134620:	afac0de8 */ 	sw	$t4,0xde8($sp)
/*  f134624:	3c19b100 */ 	lui	$t9,0xb100
/*  f134628:	37390052 */ 	ori	$t9,$t9,0x52
/*  f13462c:	240d4310 */ 	addiu	$t5,$zero,0x4310
/*  f134630:	adcd0004 */ 	sw	$t5,0x4($t6)
/*  f134634:	add90000 */ 	sw	$t9,0x0($t6)
.L0f134638:
/*  f134638:	8fab0194 */ 	lw	$t3,0x194($sp)
/*  f13463c:	8fb80de8 */ 	lw	$t8,0xde8($sp)
/*  f134640:	24010003 */ 	addiu	$at,$zero,0x3
/*  f134644:	15610008 */ 	bne	$t3,$at,.L0f134668
/*  f134648:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f13464c:	afaf0de8 */ 	sw	$t7,0xde8($sp)
/*  f134650:	3c0eb100 */ 	lui	$t6,0xb100
/*  f134654:	3c0c0076 */ 	lui	$t4,0x76
/*  f134658:	358c4310 */ 	ori	$t4,$t4,0x4310
/*  f13465c:	35ce0852 */ 	ori	$t6,$t6,0x852
/*  f134660:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f134664:	af0c0004 */ 	sw	$t4,0x4($t8)
.L0f134668:
/*  f134668:	0c012144 */ 	jal	osGetCount
/*  f13466c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134670:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f134674:	8fa20de8 */ 	lw	$v0,0xde8($sp)
/*  f134678:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f13467c:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f134680:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f134684:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f134688:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f13468c:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f134690:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f134694:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f134698:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f13469c:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f1346a0:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f1346a4:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f1346a8:	03e00008 */ 	jr	$ra
/*  f1346ac:	27bd0de8 */ 	addiu	$sp,$sp,0xde8
);

GLOBAL_ASM(
glabel weatherRenderSnow
.late_rodata
glabel var7f1b5784
.word 0x4096cbe4
glabel var7f1b5788
.word 0x40490fdb
glabel var7f1b578c
.word 0x3fc90fdb
glabel var7f1b5790
.word 0x3727c5ac
.text
/*  f1346b0:	27bdec68 */ 	addiu	$sp,$sp,-5016
/*  f1346b4:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f1346b8:	00a08825 */ 	or	$s1,$a1,$zero
/*  f1346bc:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f1346c0:	00c09825 */ 	or	$s3,$a2,$zero
/*  f1346c4:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f1346c8:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f1346cc:	afa41398 */ 	sw	$a0,0x1398($sp)
/*  f1346d0:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f1346d4:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f1346d8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1346dc:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f1346e0:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f1346e4:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f1346e8:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f1346ec:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f1346f0:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f1346f4:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f1346f8:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f1346fc:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f134700:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f134704:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f134708:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f13470c:	0000b825 */ 	or	$s7,$zero,$zero
/*  f134710:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f134714:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f134718:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f13471c:	27a41398 */ 	addiu	$a0,$sp,0x1398
/*  f134720:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f134724:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f134728:	afa01268 */ 	sw	$zero,0x1268($sp)
/*  f13472c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f134730:	00003825 */ 	or	$a3,$zero,$zero
/*  f134734:	8fb81398 */ 	lw	$t8,0x1398($sp)
/*  f134738:	8fa81268 */ 	lw	$t0,0x1268($sp)
/*  f13473c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f134740:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f134744:	afb91398 */ 	sw	$t9,0x1398($sp)
/*  f134748:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f13474c:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f134750:	af000004 */ 	sw	$zero,0x4($t8)
/*  f134754:	8faf1398 */ 	lw	$t7,0x1398($sp)
/*  f134758:	3c19ba00 */ 	lui	$t9,0xba00
/*  f13475c:	37390602 */ 	ori	$t9,$t9,0x602
/*  f134760:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f134764:	afb81398 */ 	sw	$t8,0x1398($sp)
/*  f134768:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f13476c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f134770:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f134774:	8faf1398 */ 	lw	$t7,0x1398($sp)
/*  f134778:	3c19b900 */ 	lui	$t9,0xb900
/*  f13477c:	3c0e0040 */ 	lui	$t6,0x40
/*  f134780:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f134784:	afb81398 */ 	sw	$t8,0x1398($sp)
/*  f134788:	35ce49d8 */ 	ori	$t6,$t6,0x49d8
/*  f13478c:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f134790:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f134794:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f134798:	8faf1398 */ 	lw	$t7,0x1398($sp)
/*  f13479c:	3c19b900 */ 	lui	$t9,0xb900
/*  f1347a0:	37390002 */ 	ori	$t9,$t9,0x2
/*  f1347a4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f1347a8:	afb81398 */ 	sw	$t8,0x1398($sp)
/*  f1347ac:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f1347b0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f1347b4:	8fae1398 */ 	lw	$t6,0x1398($sp)
/*  f1347b8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1347bc:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f1347c0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1347c4:	afaf1398 */ 	sw	$t7,0x1398($sp)
/*  f1347c8:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1347cc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1347d0:	8fb91398 */ 	lw	$t9,0x1398($sp)
/*  f1347d4:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1347d8:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f1347dc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f1347e0:	afae1398 */ 	sw	$t6,0x1398($sp)
/*  f1347e4:	24180c00 */ 	addiu	$t8,$zero,0xc00
/*  f1347e8:	af380004 */ 	sw	$t8,0x4($t9)
/*  f1347ec:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f1347f0:	8fb91398 */ 	lw	$t9,0x1398($sp)
/*  f1347f4:	3c0ffcff */ 	lui	$t7,0xfcff
/*  f1347f8:	3c18ff32 */ 	lui	$t8,0xff32
/*  f1347fc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f134800:	afae1398 */ 	sw	$t6,0x1398($sp)
/*  f134804:	37187f3f */ 	ori	$t8,$t8,0x7f3f
/*  f134808:	35ef99ff */ 	ori	$t7,$t7,0x99ff
/*  f13480c:	3c047f1b */ 	lui	$a0,%hi(var7f1b569c)
/*  f134810:	3c058008 */ 	lui	$a1,%hi(var8007f104)
/*  f134814:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f134818:	af380004 */ 	sw	$t8,0x4($t9)
/*  f13481c:	24a5f104 */ 	addiu	$a1,$a1,%lo(var8007f104)
/*  f134820:	2484569c */ 	addiu	$a0,$a0,%lo(var7f1b569c)
/*  f134824:	0c0036cc */ 	jal	func0000db30
/*  f134828:	afa81268 */ 	sw	$t0,0x1268($sp)
/*  f13482c:	3c047f1b */ 	lui	$a0,%hi(var7f1b56a8)
/*  f134830:	3c058008 */ 	lui	$a1,%hi(var8007f108)
/*  f134834:	24a5f108 */ 	addiu	$a1,$a1,%lo(var8007f108)
/*  f134838:	0c0036cc */ 	jal	func0000db30
/*  f13483c:	248456a8 */ 	addiu	$a0,$a0,%lo(var7f1b56a8)
/*  f134840:	3c047f1b */ 	lui	$a0,%hi(var7f1b56b4)
/*  f134844:	3c058008 */ 	lui	$a1,%hi(var8007f10c)
/*  f134848:	24a5f10c */ 	addiu	$a1,$a1,%lo(var8007f10c)
/*  f13484c:	0c0036cc */ 	jal	func0000db30
/*  f134850:	248456b4 */ 	addiu	$a0,$a0,%lo(var7f1b56b4)
/*  f134854:	3c047f1b */ 	lui	$a0,%hi(var7f1b56c0)
/*  f134858:	3c058008 */ 	lui	$a1,%hi(var8007f110)
/*  f13485c:	24a5f110 */ 	addiu	$a1,$a1,%lo(var8007f110)
/*  f134860:	0c0036cc */ 	jal	func0000db30
/*  f134864:	248456c0 */ 	addiu	$a0,$a0,%lo(var7f1b56c0)
/*  f134868:	0013c880 */ 	sll	$t9,$s3,0x2
/*  f13486c:	02397021 */ 	addu	$t6,$s1,$t9
/*  f134870:	27b001cc */ 	addiu	$s0,$sp,0x1cc
/*  f134874:	8dd20024 */ 	lw	$s2,0x24($t6)
/*  f134878:	afa00198 */ 	sw	$zero,0x198($sp)
/*  f13487c:	0c00566c */ 	jal	func000159b0
/*  f134880:	02002025 */ 	or	$a0,$s0,$zero
/*  f134884:	0fc2d5be */ 	jal	currentPlayerGetUnk1740
/*  f134888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13488c:	00402025 */ 	or	$a0,$v0,$zero
/*  f134890:	0c0056f8 */ 	jal	func00015be0
/*  f134894:	02002825 */ 	or	$a1,$s0,$zero
/*  f134898:	4480a000 */ 	mtc1	$zero,$f20
/*  f13489c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1348a0:	e7b401fc */ 	swc1	$f20,0x1fc($sp)
/*  f1348a4:	e7b40200 */ 	swc1	$f20,0x200($sp)
/*  f1348a8:	0fc59e66 */ 	jal	func0f167998
/*  f1348ac:	e7b40204 */ 	swc1	$f20,0x204($sp)
/*  f1348b0:	00408825 */ 	or	$s1,$v0,$zero
/*  f1348b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1348b8:	0c005815 */ 	jal	func00016054
/*  f1348bc:	00402825 */ 	or	$a1,$v0,$zero
/*  f1348c0:	8fb01398 */ 	lw	$s0,0x1398($sp)
/*  f1348c4:	3c190102 */ 	lui	$t9,0x102
/*  f1348c8:	37390040 */ 	ori	$t9,$t9,0x40
/*  f1348cc:	26180008 */ 	addiu	$t8,$s0,0x8
/*  f1348d0:	afb81398 */ 	sw	$t8,0x1398($sp)
/*  f1348d4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1348d8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1348dc:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f1348e0:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f1348e4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f1348e8:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f1348ec:	8ca30284 */ 	lw	$v1,0x284($a1)
/*  f1348f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1348f4:	02408025 */ 	or	$s0,$s2,$zero
/*  f1348f8:	c4641bb0 */ 	lwc1	$f4,0x1bb0($v1)
/*  f1348fc:	0000f025 */ 	or	$s8,$zero,$zero
/*  f134900:	e7a40234 */ 	swc1	$f4,0x234($sp)
/*  f134904:	c4661bb4 */ 	lwc1	$f6,0x1bb4($v1)
/*  f134908:	c7aa0234 */ 	lwc1	$f10,0x234($sp)
/*  f13490c:	e7a60238 */ 	swc1	$f6,0x238($sp)
/*  f134910:	c4681bb8 */ 	lwc1	$f8,0x1bb8($v1)
/*  f134914:	e7a8023c */ 	swc1	$f8,0x23c($sp)
/*  f134918:	c6443e80 */ 	lwc1	$f4,0x3e80($s2)
/*  f13491c:	c7a80238 */ 	lwc1	$f8,0x238($sp)
/*  f134920:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f134924:	e7a60228 */ 	swc1	$f6,0x228($sp)
/*  f134928:	c64a3e84 */ 	lwc1	$f10,0x3e84($s2)
/*  f13492c:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f134930:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f134934:	c7a8023c */ 	lwc1	$f8,0x23c($sp)
/*  f134938:	e7a4022c */ 	swc1	$f4,0x22c($sp)
/*  f13493c:	c64a3e88 */ 	lwc1	$f10,0x3e88($s2)
/*  f134940:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f134944:	45000003 */ 	bc1f	.L0f134954
/*  f134948:	e7a40230 */ 	swc1	$f4,0x230($sp)
/*  f13494c:	10000003 */ 	beqz	$zero,.L0f13495c
/*  f134950:	46003006 */ 	mov.s	$f0,$f6
.L0f134954:
/*  f134954:	c7a00228 */ 	lwc1	$f0,0x228($sp)
/*  f134958:	46000007 */ 	neg.s	$f0,$f0
.L0f13495c:
/*  f13495c:	c6423e98 */ 	lwc1	$f2,0x3e98($s2)
/*  f134960:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f134964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134968:	45020004 */ 	bc1fl	.L0f13497c
/*  f13496c:	46001387 */ 	neg.s	$f14,$f2
/*  f134970:	10000002 */ 	beqz	$zero,.L0f13497c
/*  f134974:	46001386 */ 	mov.s	$f14,$f2
/*  f134978:	46001387 */ 	neg.s	$f14,$f2
.L0f13497c:
/*  f13497c:	c6423e8c */ 	lwc1	$f2,0x3e8c($s2)
/*  f134980:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f134984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134988:	45020004 */ 	bc1fl	.L0f13499c
/*  f13498c:	46001307 */ 	neg.s	$f12,$f2
/*  f134990:	10000002 */ 	beqz	$zero,.L0f13499c
/*  f134994:	46001306 */ 	mov.s	$f12,$f2
/*  f134998:	46001307 */ 	neg.s	$f12,$f2
.L0f13499c:
/*  f13499c:	460e6200 */ 	add.s	$f8,$f12,$f14
/*  f1349a0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f1349a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1349a8:	4503003b */ 	bc1tl	.L0f134a98
/*  f1349ac:	3c013f00 */ 	lui	$at,0x3f00
/*  f1349b0:	c7a0022c */ 	lwc1	$f0,0x22c($sp)
/*  f1349b4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1349b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1349bc:	45020004 */ 	bc1fl	.L0f1349d0
/*  f1349c0:	46000387 */ 	neg.s	$f14,$f0
/*  f1349c4:	10000002 */ 	beqz	$zero,.L0f1349d0
/*  f1349c8:	46000386 */ 	mov.s	$f14,$f0
/*  f1349cc:	46000387 */ 	neg.s	$f14,$f0
.L0f1349d0:
/*  f1349d0:	c64c3e9c */ 	lwc1	$f12,0x3e9c($s2)
/*  f1349d4:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f1349d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1349dc:	45020004 */ 	bc1fl	.L0f1349f0
/*  f1349e0:	46006407 */ 	neg.s	$f16,$f12
/*  f1349e4:	10000002 */ 	beqz	$zero,.L0f1349f0
/*  f1349e8:	46006406 */ 	mov.s	$f16,$f12
/*  f1349ec:	46006407 */ 	neg.s	$f16,$f12
.L0f1349f0:
/*  f1349f0:	c6403e90 */ 	lwc1	$f0,0x3e90($s2)
/*  f1349f4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1349f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1349fc:	45020004 */ 	bc1fl	.L0f134a10
/*  f134a00:	46000087 */ 	neg.s	$f2,$f0
/*  f134a04:	10000002 */ 	beqz	$zero,.L0f134a10
/*  f134a08:	46000086 */ 	mov.s	$f2,$f0
/*  f134a0c:	46000087 */ 	neg.s	$f2,$f0
.L0f134a10:
/*  f134a10:	46101280 */ 	add.s	$f10,$f2,$f16
/*  f134a14:	c7a00230 */ 	lwc1	$f0,0x230($sp)
/*  f134a18:	460e503c */ 	c.lt.s	$f10,$f14
/*  f134a1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134a20:	4503001d */ 	bc1tl	.L0f134a98
/*  f134a24:	3c013f00 */ 	lui	$at,0x3f00
/*  f134a28:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f134a2c:	44802000 */ 	mtc1	$zero,$f4
/*  f134a30:	45020004 */ 	bc1fl	.L0f134a44
/*  f134a34:	46000307 */ 	neg.s	$f12,$f0
/*  f134a38:	10000002 */ 	beqz	$zero,.L0f134a44
/*  f134a3c:	46000306 */ 	mov.s	$f12,$f0
/*  f134a40:	46000307 */ 	neg.s	$f12,$f0
.L0f134a44:
/*  f134a44:	c64e3ea0 */ 	lwc1	$f14,0x3ea0($s2)
/*  f134a48:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f134a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134a50:	45020004 */ 	bc1fl	.L0f134a64
/*  f134a54:	46007407 */ 	neg.s	$f16,$f14
/*  f134a58:	10000002 */ 	beqz	$zero,.L0f134a64
/*  f134a5c:	46007406 */ 	mov.s	$f16,$f14
/*  f134a60:	46007407 */ 	neg.s	$f16,$f14
.L0f134a64:
/*  f134a64:	c6403e94 */ 	lwc1	$f0,0x3e94($s2)
/*  f134a68:	4600203c */ 	c.lt.s	$f4,$f0
/*  f134a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134a70:	45020004 */ 	bc1fl	.L0f134a84
/*  f134a74:	46000087 */ 	neg.s	$f2,$f0
/*  f134a78:	10000002 */ 	beqz	$zero,.L0f134a84
/*  f134a7c:	46000086 */ 	mov.s	$f2,$f0
/*  f134a80:	46000087 */ 	neg.s	$f2,$f0
.L0f134a84:
/*  f134a84:	46101180 */ 	add.s	$f6,$f2,$f16
/*  f134a88:	460c303c */ 	c.lt.s	$f6,$f12
/*  f134a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134a90:	4500000b */ 	bc1f	.L0f134ac0
/*  f134a94:	3c013f00 */ 	lui	$at,0x3f00
.L0f134a98:
/*  f134a98:	44810000 */ 	mtc1	$at,$f0
/*  f134a9c:	c6483ea4 */ 	lwc1	$f8,0x3ea4($s2)
/*  f134aa0:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f134aa4:	e7aa0228 */ 	swc1	$f10,0x228($sp)
/*  f134aa8:	c6443ea8 */ 	lwc1	$f4,0x3ea8($s2)
/*  f134aac:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f134ab0:	e7a6022c */ 	swc1	$f6,0x22c($sp)
/*  f134ab4:	c6483eac */ 	lwc1	$f8,0x3eac($s2)
/*  f134ab8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f134abc:	e7aa0230 */ 	swc1	$f10,0x230($sp)
.L0f134ac0:
/*  f134ac0:	4480a000 */ 	mtc1	$zero,$f20
/*  f134ac4:	24043e80 */ 	addiu	$a0,$zero,0x3e80
.L0f134ac8:
/*  f134ac8:	c6423e98 */ 	lwc1	$f2,0x3e98($s2)
/*  f134acc:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f134ad0:	c7a80228 */ 	lwc1	$f8,0x228($sp)
/*  f134ad4:	02001825 */ 	or	$v1,$s0,$zero
/*  f134ad8:	46022181 */ 	sub.s	$f6,$f4,$f2
/*  f134adc:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f134ae0:	4614003c */ 	c.lt.s	$f0,$f20
/*  f134ae4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134ae8:	45020004 */ 	bc1fl	.L0f134afc
/*  f134aec:	c64c3ea4 */ 	lwc1	$f12,0x3ea4($s2)
/*  f134af0:	c64a3ea4 */ 	lwc1	$f10,0x3ea4($s2)
/*  f134af4:	460a0000 */ 	add.s	$f0,$f0,$f10
/*  f134af8:	c64c3ea4 */ 	lwc1	$f12,0x3ea4($s2)
.L0f134afc:
/*  f134afc:	4600603c */ 	c.lt.s	$f12,$f0
/*  f134b00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134b04:	45020003 */ 	bc1fl	.L0f134b14
/*  f134b08:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f134b0c:	460c0001 */ 	sub.s	$f0,$f0,$f12
/*  f134b10:	46001100 */ 	add.s	$f4,$f2,$f0
.L0f134b14:
/*  f134b14:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f134b18:	e6040000 */ 	swc1	$f4,0x0($s0)
/*  f134b1c:	c64c3e9c */ 	lwc1	$f12,0x3e9c($s2)
/*  f134b20:	c7aa022c */ 	lwc1	$f10,0x22c($sp)
/*  f134b24:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*  f134b28:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f134b2c:	4614003c */ 	c.lt.s	$f0,$f20
/*  f134b30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134b34:	45020004 */ 	bc1fl	.L0f134b48
/*  f134b38:	c6423ea8 */ 	lwc1	$f2,0x3ea8($s2)
/*  f134b3c:	c6443ea8 */ 	lwc1	$f4,0x3ea8($s2)
/*  f134b40:	46040000 */ 	add.s	$f0,$f0,$f4
/*  f134b44:	c6423ea8 */ 	lwc1	$f2,0x3ea8($s2)
.L0f134b48:
/*  f134b48:	4600103c */ 	c.lt.s	$f2,$f0
/*  f134b4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134b50:	45020003 */ 	bc1fl	.L0f134b60
/*  f134b54:	46006180 */ 	add.s	$f6,$f12,$f0
/*  f134b58:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f134b5c:	46006180 */ 	add.s	$f6,$f12,$f0
.L0f134b60:
/*  f134b60:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f134b64:	e6060004 */ 	swc1	$f6,0x4($s0)
/*  f134b68:	c64e3ea0 */ 	lwc1	$f14,0x3ea0($s2)
/*  f134b6c:	c7a40230 */ 	lwc1	$f4,0x230($sp)
/*  f134b70:	460e4281 */ 	sub.s	$f10,$f8,$f14
/*  f134b74:	46045001 */ 	sub.s	$f0,$f10,$f4
/*  f134b78:	4614003c */ 	c.lt.s	$f0,$f20
/*  f134b7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134b80:	45020004 */ 	bc1fl	.L0f134b94
/*  f134b84:	c6423eac */ 	lwc1	$f2,0x3eac($s2)
/*  f134b88:	c6463eac */ 	lwc1	$f6,0x3eac($s2)
/*  f134b8c:	46060000 */ 	add.s	$f0,$f0,$f6
/*  f134b90:	c6423eac */ 	lwc1	$f2,0x3eac($s2)
.L0f134b94:
/*  f134b94:	4600103c */ 	c.lt.s	$f2,$f0
/*  f134b98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134b9c:	45020003 */ 	bc1fl	.L0f134bac
/*  f134ba0:	46007200 */ 	add.s	$f8,$f14,$f0
/*  f134ba4:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f134ba8:	46007200 */ 	add.s	$f8,$f14,$f0
.L0f134bac:
/*  f134bac:	24420020 */ 	addiu	$v0,$v0,0x20
/*  f134bb0:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f134bb4:	1444ffc4 */ 	bne	$v0,$a0,.L0f134ac8
/*  f134bb8:	e4680008 */ 	swc1	$f8,0x8($v1)
/*  f134bbc:	c7aa0234 */ 	lwc1	$f10,0x234($sp)
/*  f134bc0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f134bc4:	00006825 */ 	or	$t5,$zero,$zero
/*  f134bc8:	e64a3e80 */ 	swc1	$f10,0x3e80($s2)
/*  f134bcc:	c7a40238 */ 	lwc1	$f4,0x238($sp)
/*  f134bd0:	c64a3e98 */ 	lwc1	$f10,0x3e98($s2)
/*  f134bd4:	27ac126c */ 	addiu	$t4,$sp,0x126c
/*  f134bd8:	e6443e84 */ 	swc1	$f4,0x3e84($s2)
/*  f134bdc:	c7a6023c */ 	lwc1	$f6,0x23c($sp)
/*  f134be0:	27b30144 */ 	addiu	$s3,$sp,0x144
/*  f134be4:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f134be8:	e6463e88 */ 	swc1	$f6,0x3e88($s2)
/*  f134bec:	8ca30284 */ 	lw	$v1,0x284($a1)
/*  f134bf0:	27b0126c */ 	addiu	$s0,$sp,0x126c
/*  f134bf4:	c4681bb0 */ 	lwc1	$f8,0x1bb0($v1)
/*  f134bf8:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f134bfc:	e7a4016c */ 	swc1	$f4,0x16c($sp)
/*  f134c00:	c6483e8c */ 	lwc1	$f8,0x3e8c($s2)
/*  f134c04:	c4661bb0 */ 	lwc1	$f6,0x1bb0($v1)
/*  f134c08:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f134c0c:	e7aa0178 */ 	swc1	$f10,0x178($sp)
/*  f134c10:	c6463e9c */ 	lwc1	$f6,0x3e9c($s2)
/*  f134c14:	c4641bb4 */ 	lwc1	$f4,0x1bb4($v1)
/*  f134c18:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f134c1c:	e7a80170 */ 	swc1	$f8,0x170($sp)
/*  f134c20:	c6443e90 */ 	lwc1	$f4,0x3e90($s2)
/*  f134c24:	c46a1bb4 */ 	lwc1	$f10,0x1bb4($v1)
/*  f134c28:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f134c2c:	e7a6017c */ 	swc1	$f6,0x17c($sp)
/*  f134c30:	c64a3ea0 */ 	lwc1	$f10,0x3ea0($s2)
/*  f134c34:	c4681bb8 */ 	lwc1	$f8,0x1bb8($v1)
/*  f134c38:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f134c3c:	e7a40174 */ 	swc1	$f4,0x174($sp)
/*  f134c40:	c6483e94 */ 	lwc1	$f8,0x3e94($s2)
/*  f134c44:	c4661bb8 */ 	lwc1	$f6,0x1bb8($v1)
/*  f134c48:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f134c4c:	e7aa0180 */ 	swc1	$f10,0x180($sp)
/*  f134c50:	8c6e1ba0 */ 	lw	$t6,0x1ba0($v1)
/*  f134c54:	1900005b */ 	blez	$t0,.L0f134dc4
/*  f134c58:	afae126c */ 	sw	$t6,0x126c($sp)
.L0f134c5c:
/*  f134c5c:	8d840000 */ 	lw	$a0,0x0($t4)
/*  f134c60:	afad0184 */ 	sw	$t5,0x184($sp)
/*  f134c64:	afac00ac */ 	sw	$t4,0xac($sp)
/*  f134c68:	afa81268 */ 	sw	$t0,0x1268($sp)
/*  f134c6c:	02602825 */ 	or	$a1,$s3,$zero
/*  f134c70:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f134c74:	0fc5916a */ 	jal	func0f1645a8
/*  f134c78:	00001025 */ 	or	$v0,$zero,$zero
/*  f134c7c:	8fa81268 */ 	lw	$t0,0x1268($sp)
/*  f134c80:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f134c84:	1840004a */ 	blez	$v0,.L0f134db0
/*  f134c88:	8fad0184 */ 	lw	$t5,0x184($sp)
/*  f134c8c:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f134c90:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f134c94:	0002c040 */ 	sll	$t8,$v0,0x1
/*  f134c98:	03075021 */ 	addu	$t2,$t8,$a3
/*  f134c9c:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f134ca0:	84e50000 */ 	lh	$a1,0x0($a3)
.L0f134ca4:
/*  f134ca4:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f134ca8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f134cac:	00b10019 */ 	multu	$a1,$s1
/*  f134cb0:	0000c812 */ 	mflo	$t9
/*  f134cb4:	01793021 */ 	addu	$a2,$t3,$t9
/*  f134cb8:	94ce0000 */ 	lhu	$t6,0x0($a2)
/*  f134cbc:	31d80004 */ 	andi	$t8,$t6,0x4
/*  f134cc0:	53000039 */ 	beqzl	$t8,.L0f134da8
/*  f134cc4:	00ea082b */ 	sltu	$at,$a3,$t2
/*  f134cc8:	19000009 */ 	blez	$t0,.L0f134cf0
/*  f134ccc:	00001025 */ 	or	$v0,$zero,$zero
/*  f134cd0:	27a3126c */ 	addiu	$v1,$sp,0x126c
.L0f134cd4:
/*  f134cd4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f134cd8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f134cdc:	15e50002 */ 	bne	$t7,$a1,.L0f134ce8
/*  f134ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134ce4:	00002025 */ 	or	$a0,$zero,$zero
.L0f134ce8:
/*  f134ce8:	1448fffa */ 	bne	$v0,$t0,.L0f134cd4
/*  f134cec:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f134cf0:
/*  f134cf0:	10800025 */ 	beqz	$a0,.L0f134d88
/*  f134cf4:	c7a40178 */ 	lwc1	$f4,0x178($sp)
/*  f134cf8:	c4c60018 */ 	lwc1	$f6,0x18($a2)
/*  f134cfc:	c7aa016c */ 	lwc1	$f10,0x16c($sp)
/*  f134d00:	4606203c */ 	c.lt.s	$f4,$f6
/*  f134d04:	c7a4017c */ 	lwc1	$f4,0x17c($sp)
/*  f134d08:	45030007 */ 	bc1tl	.L0f134d28
/*  f134d0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f134d10:	c4c80024 */ 	lwc1	$f8,0x24($a2)
/*  f134d14:	460a403c */ 	c.lt.s	$f8,$f10
/*  f134d18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134d1c:	45020003 */ 	bc1fl	.L0f134d2c
/*  f134d20:	c4c6001c */ 	lwc1	$f6,0x1c($a2)
/*  f134d24:	00002025 */ 	or	$a0,$zero,$zero
.L0f134d28:
/*  f134d28:	c4c6001c */ 	lwc1	$f6,0x1c($a2)
.L0f134d2c:
/*  f134d2c:	c7aa0170 */ 	lwc1	$f10,0x170($sp)
/*  f134d30:	4606203c */ 	c.lt.s	$f4,$f6
/*  f134d34:	c7a40180 */ 	lwc1	$f4,0x180($sp)
/*  f134d38:	45030007 */ 	bc1tl	.L0f134d58
/*  f134d3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f134d40:	c4c80028 */ 	lwc1	$f8,0x28($a2)
/*  f134d44:	460a403c */ 	c.lt.s	$f8,$f10
/*  f134d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134d4c:	45020003 */ 	bc1fl	.L0f134d5c
/*  f134d50:	c4c60020 */ 	lwc1	$f6,0x20($a2)
/*  f134d54:	00002025 */ 	or	$a0,$zero,$zero
.L0f134d58:
/*  f134d58:	c4c60020 */ 	lwc1	$f6,0x20($a2)
.L0f134d5c:
/*  f134d5c:	c7aa0174 */ 	lwc1	$f10,0x174($sp)
/*  f134d60:	4606203c */ 	c.lt.s	$f4,$f6
/*  f134d64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134d68:	45030007 */ 	bc1tl	.L0f134d88
/*  f134d6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f134d70:	c4c8002c */ 	lwc1	$f8,0x2c($a2)
/*  f134d74:	460a403c */ 	c.lt.s	$f8,$f10
/*  f134d78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134d7c:	45000002 */ 	bc1f	.L0f134d88
/*  f134d80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134d84:	00002025 */ 	or	$a0,$zero,$zero
.L0f134d88:
/*  f134d88:	10800006 */ 	beqz	$a0,.L0f134da4
/*  f134d8c:	29010032 */ 	slti	$at,$t0,0x32
/*  f134d90:	10200004 */ 	beqz	$at,.L0f134da4
/*  f134d94:	0008c880 */ 	sll	$t9,$t0,0x2
/*  f134d98:	02197021 */ 	addu	$t6,$s0,$t9
/*  f134d9c:	adc50000 */ 	sw	$a1,0x0($t6)
/*  f134da0:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f134da4:
/*  f134da4:	00ea082b */ 	sltu	$at,$a3,$t2
.L0f134da8:
/*  f134da8:	5420ffbe */ 	bnezl	$at,.L0f134ca4
/*  f134dac:	84e50000 */ 	lh	$a1,0x0($a3)
.L0f134db0:
/*  f134db0:	25ad0001 */ 	addiu	$t5,$t5,0x1
/*  f134db4:	01a8082a */ 	slt	$at,$t5,$t0
/*  f134db8:	1420ffa8 */ 	bnez	$at,.L0f134c5c
/*  f134dbc:	258c0004 */ 	addiu	$t4,$t4,0x4
/*  f134dc0:	00006825 */ 	or	$t5,$zero,$zero
.L0f134dc4:
/*  f134dc4:	19000037 */ 	blez	$t0,.L0f134ea4
/*  f134dc8:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f134dcc:	3c013f80 */ 	lui	$at,0x3f80
/*  f134dd0:	3c14800a */ 	lui	$s4,%hi(g_RoomPtrs)
/*  f134dd4:	4481a000 */ 	mtc1	$at,$f20
/*  f134dd8:	26944928 */ 	addiu	$s4,$s4,%lo(g_RoomPtrs)
/*  f134ddc:	27ac126c */ 	addiu	$t4,$sp,0x126c
/*  f134de0:	27b61078 */ 	addiu	$s6,$sp,0x1078
/*  f134de4:	27b50bc8 */ 	addiu	$s5,$sp,0xbc8
/*  f134de8:	2413000c */ 	addiu	$s3,$zero,0xc
/*  f134dec:	27b00e20 */ 	addiu	$s0,$sp,0xe20
.L0f134df0:
/*  f134df0:	8d840000 */ 	lw	$a0,0x0($t4)
/*  f134df4:	afad0184 */ 	sw	$t5,0x184($sp)
/*  f134df8:	afac00ac */ 	sw	$t4,0xac($sp)
/*  f134dfc:	0fc4ca87 */ 	jal	weatherIsRoomWeatherProof
/*  f134e00:	afa81268 */ 	sw	$t0,0x1268($sp)
/*  f134e04:	8fa81268 */ 	lw	$t0,0x1268($sp)
/*  f134e08:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f134e0c:	10400022 */ 	beqz	$v0,.L0f134e98
/*  f134e10:	8fad0184 */ 	lw	$t5,0x184($sp)
/*  f134e14:	02f30019 */ 	multu	$s7,$s3
/*  f134e18:	8d860000 */ 	lw	$a2,0x0($t4)
/*  f134e1c:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f134e20:	2ae10032 */ 	slti	$at,$s7,0x32
/*  f134e24:	0017c880 */ 	sll	$t9,$s7,0x2
/*  f134e28:	02d97021 */ 	addu	$t6,$s6,$t9
/*  f134e2c:	00002812 */ 	mflo	$a1
/*  f134e30:	02051821 */ 	addu	$v1,$s0,$a1
/*  f134e34:	02a52021 */ 	addu	$a0,$s5,$a1
/*  f134e38:	00d10019 */ 	multu	$a2,$s1
/*  f134e3c:	00007812 */ 	mflo	$t7
/*  f134e40:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f134e44:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f134e48:	46142183 */ 	div.s	$f6,$f4,$f20
/*  f134e4c:	e4660000 */ 	swc1	$f6,0x0($v1)
/*  f134e50:	c448001c */ 	lwc1	$f8,0x1c($v0)
/*  f134e54:	46144283 */ 	div.s	$f10,$f8,$f20
/*  f134e58:	e46a0004 */ 	swc1	$f10,0x4($v1)
/*  f134e5c:	c4440020 */ 	lwc1	$f4,0x20($v0)
/*  f134e60:	46142183 */ 	div.s	$f6,$f4,$f20
/*  f134e64:	e4660008 */ 	swc1	$f6,0x8($v1)
/*  f134e68:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f134e6c:	46144283 */ 	div.s	$f10,$f8,$f20
/*  f134e70:	e48a0000 */ 	swc1	$f10,0x0($a0)
/*  f134e74:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f134e78:	46142183 */ 	div.s	$f6,$f4,$f20
/*  f134e7c:	e4860004 */ 	swc1	$f6,0x4($a0)
/*  f134e80:	c448002c */ 	lwc1	$f8,0x2c($v0)
/*  f134e84:	46144283 */ 	div.s	$f10,$f8,$f20
/*  f134e88:	10200003 */ 	beqz	$at,.L0f134e98
/*  f134e8c:	e48a0008 */ 	swc1	$f10,0x8($a0)
/*  f134e90:	adc60000 */ 	sw	$a2,0x0($t6)
/*  f134e94:	26f70001 */ 	addiu	$s7,$s7,0x1
.L0f134e98:
/*  f134e98:	25ad0001 */ 	addiu	$t5,$t5,0x1
/*  f134e9c:	15a8ffd4 */ 	bne	$t5,$t0,.L0f134df0
/*  f134ea0:	258c0004 */ 	addiu	$t4,$t4,0x4
.L0f134ea4:
/*  f134ea4:	3c013f80 */ 	lui	$at,0x3f80
/*  f134ea8:	4481a000 */ 	mtc1	$at,$f20
/*  f134eac:	1ae0007c */ 	blez	$s7,.L0f1350a0
/*  f134eb0:	00001825 */ 	or	$v1,$zero,$zero
/*  f134eb4:	3c068008 */ 	lui	$a2,%hi(var8007f104)
/*  f134eb8:	8cc6f104 */ 	lw	$a2,%lo(var8007f104)($a2)
/*  f134ebc:	3c048008 */ 	lui	$a0,%hi(var8007f100)
/*  f134ec0:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f134ec4:	44862000 */ 	mtc1	$a2,$f4
/*  f134ec8:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f134ecc:	8c84f100 */ 	lw	$a0,%lo(var8007f100)($a0)
/*  f134ed0:	27a51078 */ 	addiu	$a1,$sp,0x1078
/*  f134ed4:	04c10005 */ 	bgez	$a2,.L0f134eec
/*  f134ed8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f134edc:	3c014f80 */ 	lui	$at,0x4f80
/*  f134ee0:	44813000 */ 	mtc1	$at,$f6
/*  f134ee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134ee8:	46060000 */ 	add.s	$f0,$f0,$f6
.L0f134eec:
/*  f134eec:	44844000 */ 	mtc1	$a0,$f8
/*  f134ef0:	27a20264 */ 	addiu	$v0,$sp,0x264
/*  f134ef4:	04810005 */ 	bgez	$a0,.L0f134f0c
/*  f134ef8:	468045a0 */ 	cvt.s.w	$f22,$f8
/*  f134efc:	3c014f80 */ 	lui	$at,0x4f80
/*  f134f00:	44815000 */ 	mtc1	$at,$f10
/*  f134f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f134f08:	460ab580 */ 	add.s	$f22,$f22,$f10
.L0f134f0c:
/*  f134f0c:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f134f10:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f134f14:	03110019 */ 	multu	$t8,$s1
/*  f134f18:	00007812 */ 	mflo	$t7
/*  f134f1c:	016f2021 */ 	addu	$a0,$t3,$t7
/*  f134f20:	50770034 */ 	beql	$v1,$s7,.L0f134ff4
/*  f134f24:	c4920018 */ 	lwc1	$f18,0x18($a0)
.L0f134f28:
/*  f134f28:	c4920018 */ 	lwc1	$f18,0x18($a0)
/*  f134f2c:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f134f30:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f134f34:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f134f38:	03110019 */ 	multu	$t8,$s1
/*  f134f3c:	24a50004 */ 	addiu	$a1,$a1,0x0004
/*  f134f40:	24420030 */ 	addiu	$v0,$v0,0x30
/*  f134f44:	00007812 */ 	mflo	$t7
/*  f134f48:	46009481 */ 	sub.s	$f18,$f18,$f0
/*  f134f4c:	e452ffd0 */ 	swc1	$f18,-0x30($v0)
/*  f134f50:	e452ffe8 */ 	swc1	$f18,-0x18($v0)
/*  f134f54:	c4920024 */ 	lwc1	$f18,0x24($a0)
/*  f134f58:	c450ffe8 */ 	lwc1	$f16,-0x18($v0)
/*  f134f5c:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f134f60:	46168401 */ 	sub.s	$f16,$f16,$f22
/*  f134f64:	e450ffe8 */ 	swc1	$f16,-0x18($v0)
/*  f134f68:	46009480 */ 	add.s	$f18,$f18,$f0
/*  f134f6c:	46169400 */ 	add.s	$f16,$f18,$f22
/*  f134f70:	e452ffdc */ 	swc1	$f18,-0x24($v0)
/*  f134f74:	e450fff4 */ 	swc1	$f16,-0xc($v0)
/*  f134f78:	c490001c */ 	lwc1	$f16,0x1c($a0)
/*  f134f7c:	46148403 */ 	div.s	$f16,$f16,$f20
/*  f134f80:	46008401 */ 	sub.s	$f16,$f16,$f0
/*  f134f84:	e450ffd4 */ 	swc1	$f16,-0x2c($v0)
/*  f134f88:	e450ffec */ 	swc1	$f16,-0x14($v0)
/*  f134f8c:	c4900028 */ 	lwc1	$f16,0x28($a0)
/*  f134f90:	c452ffec */ 	lwc1	$f18,-0x14($v0)
/*  f134f94:	46148403 */ 	div.s	$f16,$f16,$f20
/*  f134f98:	46169481 */ 	sub.s	$f18,$f18,$f22
/*  f134f9c:	e452ffec */ 	swc1	$f18,-0x14($v0)
/*  f134fa0:	46008400 */ 	add.s	$f16,$f16,$f0
/*  f134fa4:	46168480 */ 	add.s	$f18,$f16,$f22
/*  f134fa8:	e450ffe0 */ 	swc1	$f16,-0x20($v0)
/*  f134fac:	e452fff8 */ 	swc1	$f18,-0x8($v0)
/*  f134fb0:	c4920020 */ 	lwc1	$f18,0x20($a0)
/*  f134fb4:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f134fb8:	46009481 */ 	sub.s	$f18,$f18,$f0
/*  f134fbc:	e452ffd8 */ 	swc1	$f18,-0x28($v0)
/*  f134fc0:	e452fff0 */ 	swc1	$f18,-0x10($v0)
/*  f134fc4:	c492002c */ 	lwc1	$f18,0x2c($a0)
/*  f134fc8:	c450fff0 */ 	lwc1	$f16,-0x10($v0)
/*  f134fcc:	016f2021 */ 	addu	$a0,$t3,$t7
/*  f134fd0:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f134fd4:	46168401 */ 	sub.s	$f16,$f16,$f22
/*  f134fd8:	e450fff0 */ 	swc1	$f16,-0x10($v0)
/*  f134fdc:	46009480 */ 	add.s	$f18,$f18,$f0
/*  f134fe0:	46169400 */ 	add.s	$f16,$f18,$f22
/*  f134fe4:	e452ffe4 */ 	swc1	$f18,-0x1c($v0)
/*  f134fe8:	1477ffcf */ 	bne	$v1,$s7,.L0f134f28
/*  f134fec:	e450fffc */ 	swc1	$f16,-0x4($v0)
/*  f134ff0:	c4920018 */ 	lwc1	$f18,0x18($a0)
.L0f134ff4:
/*  f134ff4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f134ff8:	24420030 */ 	addiu	$v0,$v0,0x30
/*  f134ffc:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f135000:	46009481 */ 	sub.s	$f18,$f18,$f0
/*  f135004:	e452ffd0 */ 	swc1	$f18,-0x30($v0)
/*  f135008:	e452ffe8 */ 	swc1	$f18,-0x18($v0)
/*  f13500c:	c4920024 */ 	lwc1	$f18,0x24($a0)
/*  f135010:	c450ffe8 */ 	lwc1	$f16,-0x18($v0)
/*  f135014:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f135018:	46168401 */ 	sub.s	$f16,$f16,$f22
/*  f13501c:	e450ffe8 */ 	swc1	$f16,-0x18($v0)
/*  f135020:	46009480 */ 	add.s	$f18,$f18,$f0
/*  f135024:	46169400 */ 	add.s	$f16,$f18,$f22
/*  f135028:	e452ffdc */ 	swc1	$f18,-0x24($v0)
/*  f13502c:	e450fff4 */ 	swc1	$f16,-0xc($v0)
/*  f135030:	c490001c */ 	lwc1	$f16,0x1c($a0)
/*  f135034:	46148403 */ 	div.s	$f16,$f16,$f20
/*  f135038:	46008401 */ 	sub.s	$f16,$f16,$f0
/*  f13503c:	e450ffd4 */ 	swc1	$f16,-0x2c($v0)
/*  f135040:	e450ffec */ 	swc1	$f16,-0x14($v0)
/*  f135044:	c4900028 */ 	lwc1	$f16,0x28($a0)
/*  f135048:	c452ffec */ 	lwc1	$f18,-0x14($v0)
/*  f13504c:	46148403 */ 	div.s	$f16,$f16,$f20
/*  f135050:	46169481 */ 	sub.s	$f18,$f18,$f22
/*  f135054:	e452ffec */ 	swc1	$f18,-0x14($v0)
/*  f135058:	46008400 */ 	add.s	$f16,$f16,$f0
/*  f13505c:	46168480 */ 	add.s	$f18,$f16,$f22
/*  f135060:	e450ffe0 */ 	swc1	$f16,-0x20($v0)
/*  f135064:	e452fff8 */ 	swc1	$f18,-0x8($v0)
/*  f135068:	c4920020 */ 	lwc1	$f18,0x20($a0)
/*  f13506c:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f135070:	46009481 */ 	sub.s	$f18,$f18,$f0
/*  f135074:	e452ffd8 */ 	swc1	$f18,-0x28($v0)
/*  f135078:	e452fff0 */ 	swc1	$f18,-0x10($v0)
/*  f13507c:	c492002c */ 	lwc1	$f18,0x2c($a0)
/*  f135080:	c450fff0 */ 	lwc1	$f16,-0x10($v0)
/*  f135084:	46149483 */ 	div.s	$f18,$f18,$f20
/*  f135088:	46168401 */ 	sub.s	$f16,$f16,$f22
/*  f13508c:	e450fff0 */ 	swc1	$f16,-0x10($v0)
/*  f135090:	46009480 */ 	add.s	$f18,$f18,$f0
/*  f135094:	46169400 */ 	add.s	$f16,$f18,$f22
/*  f135098:	e452ffe4 */ 	swc1	$f18,-0x1c($v0)
/*  f13509c:	e450fffc */ 	swc1	$f16,-0x4($v0)
.L0f1350a0:
/*  f1350a0:	3c017f1b */ 	lui	$at,%hi(var7f1b5784)
/*  f1350a4:	c4385784 */ 	lwc1	$f24,%lo(var7f1b5784)($at)
/*  f1350a8:	3c017f1b */ 	lui	$at,%hi(var7f1b5788)
/*  f1350ac:	c4365788 */ 	lwc1	$f22,%lo(var7f1b5788)($at)
/*  f1350b0:	3c017f1b */ 	lui	$at,%hi(var7f1b578c)
/*  f1350b4:	c434578c */ 	lwc1	$f20,%lo(var7f1b578c)($at)
/*  f1350b8:	02408825 */ 	or	$s1,$s2,$zero
/*  f1350bc:	27b01168 */ 	addiu	$s0,$sp,0x1168
/*  f1350c0:	27b31268 */ 	addiu	$s3,$sp,0x1268
.L0f1350c4:
/*  f1350c4:	0c0068f7 */ 	jal	sinf
/*  f1350c8:	c62c3ec8 */ 	lwc1	$f12,0x3ec8($s1)
/*  f1350cc:	e6000000 */ 	swc1	$f0,0x0($s0)
/*  f1350d0:	0c0068f4 */ 	jal	cosf
/*  f1350d4:	c62c3ec8 */ 	lwc1	$f12,0x3ec8($s1)
/*  f1350d8:	e6000004 */ 	swc1	$f0,0x4($s0)
/*  f1350dc:	c6263ec8 */ 	lwc1	$f6,0x3ec8($s1)
/*  f1350e0:	0c0068f7 */ 	jal	sinf
/*  f1350e4:	46143300 */ 	add.s	$f12,$f6,$f20
/*  f1350e8:	e6000008 */ 	swc1	$f0,0x8($s0)
/*  f1350ec:	c6283ec8 */ 	lwc1	$f8,0x3ec8($s1)
/*  f1350f0:	0c0068f4 */ 	jal	cosf
/*  f1350f4:	46144300 */ 	add.s	$f12,$f8,$f20
/*  f1350f8:	e600000c */ 	swc1	$f0,0xc($s0)
/*  f1350fc:	c62a3ec8 */ 	lwc1	$f10,0x3ec8($s1)
/*  f135100:	0c0068f7 */ 	jal	sinf
/*  f135104:	46165300 */ 	add.s	$f12,$f10,$f22
/*  f135108:	e6000010 */ 	swc1	$f0,0x10($s0)
/*  f13510c:	c6243ec8 */ 	lwc1	$f4,0x3ec8($s1)
/*  f135110:	0c0068f4 */ 	jal	cosf
/*  f135114:	46162300 */ 	add.s	$f12,$f4,$f22
/*  f135118:	e6000014 */ 	swc1	$f0,0x14($s0)
/*  f13511c:	c6263ec8 */ 	lwc1	$f6,0x3ec8($s1)
/*  f135120:	0c0068f7 */ 	jal	sinf
/*  f135124:	46183300 */ 	add.s	$f12,$f6,$f24
/*  f135128:	e6000018 */ 	swc1	$f0,0x18($s0)
/*  f13512c:	c6283ec8 */ 	lwc1	$f8,0x3ec8($s1)
/*  f135130:	0c0068f4 */ 	jal	cosf
/*  f135134:	46184300 */ 	add.s	$f12,$f8,$f24
/*  f135138:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f13513c:	0213082b */ 	sltu	$at,$s0,$s3
/*  f135140:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f135144:	1420ffdf */ 	bnez	$at,.L0f1350c4
/*  f135148:	e600fffc */ 	swc1	$f0,-0x4($s0)
/*  f13514c:	0fc59e73 */ 	jal	func0f1679cc
/*  f135150:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f135154:	00408025 */ 	or	$s0,$v0,$zero
/*  f135158:	240310ef */ 	addiu	$v1,$zero,0x10ef
/*  f13515c:	00402025 */ 	or	$a0,$v0,$zero
/*  f135160:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f135164:	24060011 */ 	addiu	$a2,$zero,0x11
/*  f135168:	2405ff00 */ 	addiu	$a1,$zero,-256
.L0f13516c:
/*  f13516c:	0066001a */ 	div	$zero,$v1,$a2
/*  f135170:	3c198008 */ 	lui	$t9,%hi(var8007f10c)
/*  f135174:	8f39f10c */ 	lw	$t9,%lo(var8007f10c)($t9)
/*  f135178:	0000c012 */ 	mflo	$t8
/*  f13517c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f135180:	03257024 */ 	and	$t6,$t9,$a1
/*  f135184:	14c00002 */ 	bnez	$a2,.L0f135190
/*  f135188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13518c:	0007000d */ 	break	0x7
.L0f135190:
/*  f135190:	2401ffff */ 	addiu	$at,$zero,-1
/*  f135194:	14c10004 */ 	bne	$a2,$at,.L0f1351a8
/*  f135198:	3c018000 */ 	lui	$at,0x8000
/*  f13519c:	14610002 */ 	bne	$v1,$at,.L0f1351a8
/*  f1351a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1351a4:	0006000d */ 	break	0x6
.L0f1351a8:
/*  f1351a8:	2463ff01 */ 	addiu	$v1,$v1,-255
/*  f1351ac:	01d87825 */ 	or	$t7,$t6,$t8
/*  f1351b0:	14e3ffee */ 	bne	$a3,$v1,.L0f13516c
/*  f1351b4:	ac8ffffc */ 	sw	$t7,-0x4($a0)
/*  f1351b8:	8fb11398 */ 	lw	$s1,0x1398($sp)
/*  f1351bc:	3c18073c */ 	lui	$t8,0x73c
/*  f1351c0:	37180040 */ 	ori	$t8,$t8,0x40
/*  f1351c4:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f1351c8:	afae1398 */ 	sw	$t6,0x1398($sp)
/*  f1351cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1351d0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1351d4:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f1351d8:	27b301cc */ 	addiu	$s3,$sp,0x1cc
/*  f1351dc:	4480c000 */ 	mtc1	$zero,$f24
/*  f1351e0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f1351e4:	0260b025 */ 	or	$s6,$s3,$zero
/*  f1351e8:	0000f025 */ 	or	$s8,$zero,$zero
/*  f1351ec:	02408025 */ 	or	$s0,$s2,$zero
/*  f1351f0:	24150030 */ 	addiu	$s5,$zero,0x30
/*  f1351f4:	27b40264 */ 	addiu	$s4,$sp,0x264
.L0f1351f8:
/*  f1351f8:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f1351fc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f135200:	332e0003 */ 	andi	$t6,$t9,0x3
/*  f135204:	51c0024b */ 	beqzl	$t6,.L0f135b34
/*  f135208:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f13520c:	0c012144 */ 	jal	osGetCount
/*  f135210:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135214:	afa21354 */ 	sw	$v0,0x1354($sp)
/*  f135218:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f13521c:	c64a3e80 */ 	lwc1	$f10,0x3e80($s2)
/*  f135220:	27a40124 */ 	addiu	$a0,$sp,0x124
/*  f135224:	3c0540a0 */ 	lui	$a1,0x40a0
/*  f135228:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f13522c:	e7a60124 */ 	swc1	$f6,0x124($sp)
/*  f135230:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f135234:	c6483e84 */ 	lwc1	$f8,0x3e84($s2)
/*  f135238:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f13523c:	e7a40128 */ 	swc1	$f4,0x128($sp)
/*  f135240:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f135244:	c6463e88 */ 	lwc1	$f6,0x3e88($s2)
/*  f135248:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f13524c:	0fc2d6e7 */ 	jal	func0f0b5b9c
/*  f135250:	e7aa012c */ 	swc1	$f10,0x12c($sp)
/*  f135254:	50400237 */ 	beqzl	$v0,.L0f135b34
/*  f135258:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f13525c:	0c012144 */ 	jal	osGetCount
/*  f135260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135264:	8fb8137c */ 	lw	$t8,0x137c($sp)
/*  f135268:	8fb91354 */ 	lw	$t9,0x1354($sp)
/*  f13526c:	03027821 */ 	addu	$t7,$t8,$v0
/*  f135270:	01f97023 */ 	subu	$t6,$t7,$t9
/*  f135274:	afae137c */ 	sw	$t6,0x137c($sp)
/*  f135278:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f13527c:	e7a4021c */ 	swc1	$f4,0x21c($sp)
/*  f135280:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f135284:	c7a4021c */ 	lwc1	$f4,0x21c($sp)
/*  f135288:	e7a60220 */ 	swc1	$f6,0x220($sp)
/*  f13528c:	c7a80220 */ 	lwc1	$f8,0x220($sp)
/*  f135290:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f135294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135298:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f13529c:	0c012974 */ 	jal	sqrtf
/*  f1352a0:	46065300 */ 	add.s	$f12,$f10,$f6
/*  f1352a4:	3c017f1b */ 	lui	$at,%hi(var7f1b5790)
/*  f1352a8:	c4285790 */ 	lwc1	$f8,%lo(var7f1b5790)($at)
/*  f1352ac:	46000506 */ 	mov.s	$f20,$f0
/*  f1352b0:	4608003c */ 	c.lt.s	$f0,$f8
/*  f1352b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1352b8:	4503021e */ 	bc1tl	.L0f135b34
/*  f1352bc:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f1352c0:	8fb80198 */ 	lw	$t8,0x198($sp)
/*  f1352c4:	e7b80260 */ 	swc1	$f24,0x260($sp)
/*  f1352c8:	00187880 */ 	sll	$t7,$t8,0x2
/*  f1352cc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1352d0:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f1352d4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1352d8:	17000004 */ 	bnez	$t8,.L0f1352ec
/*  f1352dc:	afb90080 */ 	sw	$t9,0x80($sp)
/*  f1352e0:	0fc59e59 */ 	jal	func0f167964
/*  f1352e4:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f1352e8:	afa20214 */ 	sw	$v0,0x214($sp)
.L0f1352ec:
/*  f1352ec:	c7a4021c */ 	lwc1	$f4,0x21c($sp)
/*  f1352f0:	c7a60220 */ 	lwc1	$f6,0x220($sp)
/*  f1352f4:	8fae0214 */ 	lw	$t6,0x214($sp)
/*  f1352f8:	46142283 */ 	div.s	$f10,$f4,$f20
/*  f1352fc:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f135300:	27a2019c */ 	addiu	$v0,$sp,0x19c
/*  f135304:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f135308:	46143203 */ 	div.s	$f8,$f6,$f20
/*  f13530c:	e7aa021c */ 	swc1	$f10,0x21c($sp)
/*  f135310:	e7a80220 */ 	swc1	$f8,0x220($sp)
.L0f135314:
/*  f135314:	a4600008 */ 	sh	$zero,0x8($v1)
/*  f135318:	a460000a */ 	sh	$zero,0xa($v1)
/*  f13531c:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f135320:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f135324:	0053082b */ 	sltu	$at,$v0,$s3
/*  f135328:	e444fff4 */ 	swc1	$f4,-0xc($v0)
/*  f13532c:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f135330:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f135334:	e44afff8 */ 	swc1	$f10,-0x8($v0)
/*  f135338:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f13533c:	1420fff5 */ 	bnez	$at,.L0f135314
/*  f135340:	e446fffc */ 	swc1	$f6,-0x4($v0)
/*  f135344:	1ae00097 */ 	blez	$s7,.L0f1355a4
/*  f135348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13534c:	c6483e80 */ 	lwc1	$f8,0x3e80($s2)
/*  f135350:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f135354:	00001825 */ 	or	$v1,$zero,$zero
/*  f135358:	3c048008 */ 	lui	$a0,%hi(var8007f100)
/*  f13535c:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f135360:	e7aa0118 */ 	swc1	$f10,0x118($sp)
/*  f135364:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f135368:	c6463e84 */ 	lwc1	$f6,0x3e84($s2)
/*  f13536c:	c7ae0118 */ 	lwc1	$f14,0x118($sp)
/*  f135370:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f135374:	e7a4011c */ 	swc1	$f4,0x11c($sp)
/*  f135378:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f13537c:	c64a3e88 */ 	lwc1	$f10,0x3e88($s2)
/*  f135380:	c7a0011c */ 	lwc1	$f0,0x11c($sp)
/*  f135384:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f135388:	1ae00086 */ 	blez	$s7,.L0f1355a4
/*  f13538c:	e7a80120 */ 	swc1	$f8,0x120($sp)
/*  f135390:	c7b00120 */ 	lwc1	$f16,0x120($sp)
/*  f135394:	8c84f100 */ 	lw	$a0,%lo(var8007f100)($a0)
.L0f135398:
/*  f135398:	5220007e */ 	beqzl	$s1,.L0f135594
/*  f13539c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1353a0:	00750019 */ 	multu	$v1,$s5
/*  f1353a4:	0000c812 */ 	mflo	$t9
/*  f1353a8:	02991021 */ 	addu	$v0,$s4,$t9
/*  f1353ac:	c4520018 */ 	lwc1	$f18,0x18($v0)
/*  f1353b0:	460e903c */ 	c.lt.s	$f18,$f14
/*  f1353b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1353b8:	45020076 */ 	bc1fl	.L0f135594
/*  f1353bc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1353c0:	c4540024 */ 	lwc1	$f20,0x24($v0)
/*  f1353c4:	4614703c */ 	c.lt.s	$f14,$f20
/*  f1353c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1353cc:	45020071 */ 	bc1fl	.L0f135594
/*  f1353d0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1353d4:	c444001c */ 	lwc1	$f4,0x1c($v0)
/*  f1353d8:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1353dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1353e0:	4502006c */ 	bc1fl	.L0f135594
/*  f1353e4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1353e8:	c44a0028 */ 	lwc1	$f10,0x28($v0)
/*  f1353ec:	460a003c */ 	c.lt.s	$f0,$f10
/*  f1353f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1353f4:	45020067 */ 	bc1fl	.L0f135594
/*  f1353f8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1353fc:	c4580020 */ 	lwc1	$f24,0x20($v0)
/*  f135400:	4610c03c */ 	c.lt.s	$f24,$f16
/*  f135404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135408:	45020062 */ 	bc1fl	.L0f135594
/*  f13540c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f135410:	c45a002c */ 	lwc1	$f26,0x2c($v0)
/*  f135414:	461a803c */ 	c.lt.s	$f16,$f26
/*  f135418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13541c:	4502005d */ 	bc1fl	.L0f135594
/*  f135420:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f135424:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f135428:	460e003c */ 	c.lt.s	$f0,$f14
/*  f13542c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135430:	4502001e */ 	bc1fl	.L0f1354ac
/*  f135434:	44844000 */ 	mtc1	$a0,$f8
/*  f135438:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f13543c:	c7a2011c */ 	lwc1	$f2,0x11c($sp)
/*  f135440:	4606703c */ 	c.lt.s	$f14,$f6
/*  f135444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135448:	45020018 */ 	bc1fl	.L0f1354ac
/*  f13544c:	44844000 */ 	mtc1	$a0,$f8
/*  f135450:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f135454:	4602403c */ 	c.lt.s	$f8,$f2
/*  f135458:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13545c:	45020013 */ 	bc1fl	.L0f1354ac
/*  f135460:	44844000 */ 	mtc1	$a0,$f8
/*  f135464:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f135468:	4604103c */ 	c.lt.s	$f2,$f4
/*  f13546c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135470:	4502000e */ 	bc1fl	.L0f1354ac
/*  f135474:	44844000 */ 	mtc1	$a0,$f8
/*  f135478:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f13547c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f135480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135484:	45020009 */ 	bc1fl	.L0f1354ac
/*  f135488:	44844000 */ 	mtc1	$a0,$f8
/*  f13548c:	c4460014 */ 	lwc1	$f6,0x14($v0)
/*  f135490:	4606803c */ 	c.lt.s	$f16,$f6
/*  f135494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135498:	45020004 */ 	bc1fl	.L0f1354ac
/*  f13549c:	44844000 */ 	mtc1	$a0,$f8
/*  f1354a0:	1000003b */ 	beqz	$zero,.L0f135590
/*  f1354a4:	00008825 */ 	or	$s1,$zero,$zero
/*  f1354a8:	44844000 */ 	mtc1	$a0,$f8
.L0f1354ac:
/*  f1354ac:	44801000 */ 	mtc1	$zero,$f2
/*  f1354b0:	04810005 */ 	bgez	$a0,.L0f1354c8
/*  f1354b4:	468045a0 */ 	cvt.s.w	$f22,$f8
/*  f1354b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1354bc:	44812000 */ 	mtc1	$at,$f4
/*  f1354c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1354c4:	4604b580 */ 	add.s	$f22,$f22,$f4
.L0f1354c8:
/*  f1354c8:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1354cc:	44805000 */ 	mtc1	$zero,$f10
/*  f1354d0:	c44c000c */ 	lwc1	$f12,0xc($v0)
/*  f1354d4:	c45c0008 */ 	lwc1	$f28,0x8($v0)
/*  f1354d8:	45000002 */ 	bc1f	.L0f1354e4
/*  f1354dc:	c45e0014 */ 	lwc1	$f30,0x14($v0)
/*  f1354e0:	46127081 */ 	sub.s	$f2,$f14,$f18
.L0f1354e4:
/*  f1354e4:	460e603c */ 	c.lt.s	$f12,$f14
/*  f1354e8:	44804000 */ 	mtc1	$zero,$f8
/*  f1354ec:	45020003 */ 	bc1fl	.L0f1354fc
/*  f1354f0:	4602503c */ 	c.lt.s	$f10,$f2
/*  f1354f4:	46147081 */ 	sub.s	$f2,$f14,$f20
/*  f1354f8:	4602503c */ 	c.lt.s	$f10,$f2
.L0f1354fc:
/*  f1354fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135500:	45020004 */ 	bc1fl	.L0f135514
/*  f135504:	46001307 */ 	neg.s	$f12,$f2
/*  f135508:	10000002 */ 	beqz	$zero,.L0f135514
/*  f13550c:	46001306 */ 	mov.s	$f12,$f2
/*  f135510:	46001307 */ 	neg.s	$f12,$f2
.L0f135514:
/*  f135514:	46166003 */ 	div.s	$f0,$f12,$f22
/*  f135518:	c7a60260 */ 	lwc1	$f6,0x260($sp)
/*  f13551c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f135520:	46000086 */ 	mov.s	$f2,$f0
/*  f135524:	45020003 */ 	bc1fl	.L0f135534
/*  f135528:	461c803c */ 	c.lt.s	$f16,$f28
/*  f13552c:	e7a00260 */ 	swc1	$f0,0x260($sp)
/*  f135530:	461c803c */ 	c.lt.s	$f16,$f28
.L0f135534:
/*  f135534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135538:	45020003 */ 	bc1fl	.L0f135548
/*  f13553c:	4610f03c */ 	c.lt.s	$f30,$f16
/*  f135540:	46188081 */ 	sub.s	$f2,$f16,$f24
/*  f135544:	4610f03c */ 	c.lt.s	$f30,$f16
.L0f135548:
/*  f135548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13554c:	45020003 */ 	bc1fl	.L0f13555c
/*  f135550:	4602403c */ 	c.lt.s	$f8,$f2
/*  f135554:	461a8081 */ 	sub.s	$f2,$f16,$f26
/*  f135558:	4602403c */ 	c.lt.s	$f8,$f2
.L0f13555c:
/*  f13555c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135560:	45020004 */ 	bc1fl	.L0f135574
/*  f135564:	46001307 */ 	neg.s	$f12,$f2
/*  f135568:	10000002 */ 	beqz	$zero,.L0f135574
/*  f13556c:	46001306 */ 	mov.s	$f12,$f2
/*  f135570:	46001307 */ 	neg.s	$f12,$f2
.L0f135574:
/*  f135574:	46166003 */ 	div.s	$f0,$f12,$f22
/*  f135578:	c7a40260 */ 	lwc1	$f4,0x260($sp)
/*  f13557c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f135580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135584:	45020003 */ 	bc1fl	.L0f135594
/*  f135588:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13558c:	e7a00260 */ 	swc1	$f0,0x260($sp)
.L0f135590:
/*  f135590:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f135594:
/*  f135594:	1477ff80 */ 	bne	$v1,$s7,.L0f135398
/*  f135598:	c7a0011c */ 	lwc1	$f0,0x11c($sp)
/*  f13559c:	4480c000 */ 	mtc1	$zero,$f24
/*  f1355a0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1355a4:
/*  f1355a4:	52200163 */ 	beqzl	$s1,.L0f135b34
/*  f1355a8:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f1355ac:	c6000000 */ 	lwc1	$f0,0x0($s0)
/*  f1355b0:	c60e0004 */ 	lwc1	$f14,0x4($s0)
/*  f1355b4:	c6020008 */ 	lwc1	$f2,0x8($s0)
/*  f1355b8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f1355bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1355c0:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f1355c4:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f1355c8:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f1355cc:	0c012974 */ 	jal	sqrtf
/*  f1355d0:	46082300 */ 	add.s	$f12,$f4,$f8
/*  f1355d4:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f1355d8:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f1355dc:	46003103 */ 	div.s	$f4,$f6,$f0
/*  f1355e0:	46005603 */ 	div.s	$f24,$f10,$f0
/*  f1355e4:	e7a40108 */ 	swc1	$f4,0x108($sp)
/*  f1355e8:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f1355ec:	46004683 */ 	div.s	$f26,$f8,$f0
/*  f1355f0:	4618c282 */ 	mul.s	$f10,$f24,$f24
/*  f1355f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1355f8:	461ad182 */ 	mul.s	$f6,$f26,$f26
/*  f1355fc:	0c012974 */ 	jal	sqrtf
/*  f135600:	46065300 */ 	add.s	$f12,$f10,$f6
/*  f135604:	4600c083 */ 	div.s	$f2,$f24,$f0
/*  f135608:	c7a40108 */ 	lwc1	$f4,0x108($sp)
/*  f13560c:	3c013f80 */ 	lui	$at,0x3f80
/*  f135610:	3c068008 */ 	lui	$a2,%hi(var8007f104)
/*  f135614:	46000287 */ 	neg.s	$f10,$f0
/*  f135618:	8cc6f104 */ 	lw	$a2,%lo(var8007f104)($a2)
/*  f13561c:	e7aa1148 */ 	swc1	$f10,0x1148($sp)
/*  f135620:	c7aa0220 */ 	lwc1	$f10,0x220($sp)
/*  f135624:	27a2019c */ 	addiu	$v0,$sp,0x19c
/*  f135628:	001ec083 */ 	sra	$t8,$s8,0x2
/*  f13562c:	4600d703 */ 	div.s	$f28,$f26,$f0
/*  f135630:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f135634:	46001787 */ 	neg.s	$f30,$f2
/*  f135638:	e7a8114c */ 	swc1	$f8,0x114c($sp)
/*  f13563c:	461c2182 */ 	mul.s	$f6,$f4,$f28
/*  f135640:	46005107 */ 	neg.s	$f4,$f10
/*  f135644:	44815000 */ 	mtc1	$at,$f10
/*  f135648:	e7a4115c */ 	swc1	$f4,0x115c($sp)
/*  f13564c:	c7a4021c */ 	lwc1	$f4,0x21c($sp)
/*  f135650:	e7aa1160 */ 	swc1	$f10,0x1160($sp)
/*  f135654:	44865000 */ 	mtc1	$a2,$f10
/*  f135658:	e7a41164 */ 	swc1	$f4,0x1164($sp)
/*  f13565c:	e7a61144 */ 	swc1	$f6,0x1144($sp)
/*  f135660:	04c10005 */ 	bgez	$a2,.L0f135678
/*  f135664:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f135668:	3c014f80 */ 	lui	$at,0x4f80
/*  f13566c:	44815000 */ 	mtc1	$at,$f10
/*  f135670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135674:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f135678:
/*  f135678:	461c2302 */ 	mul.s	$f12,$f4,$f28
/*  f13567c:	4486d000 */ 	mtc1	$a2,$f26
/*  f135680:	330e0007 */ 	andi	$t6,$t8,0x7
/*  f135684:	000e7940 */ 	sll	$t7,$t6,0x5
/*  f135688:	27b91168 */ 	addiu	$t9,$sp,0x1168
/*  f13568c:	01f92821 */ 	addu	$a1,$t7,$t9
/*  f135690:	4680d120 */ 	cvt.s.w	$f4,$f26
/*  f135694:	04c10005 */ 	bgez	$a2,.L0f1356ac
/*  f135698:	00002025 */ 	or	$a0,$zero,$zero
/*  f13569c:	3c014f80 */ 	lui	$at,0x4f80
/*  f1356a0:	44815000 */ 	mtc1	$at,$f10
/*  f1356a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1356a8:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f1356ac:
/*  f1356ac:	44865000 */ 	mtc1	$a2,$f10
/*  f1356b0:	46082382 */ 	mul.s	$f14,$f4,$f8
/*  f1356b4:	4480b000 */ 	mtc1	$zero,$f22
/*  f1356b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1356bc:	04c10004 */ 	bgez	$a2,.L0f1356d0
/*  f1356c0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f1356c4:	44814000 */ 	mtc1	$at,$f8
/*  f1356c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1356cc:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f1356d0:
/*  f1356d0:	c7aa1148 */ 	lwc1	$f10,0x1148($sp)
/*  f1356d4:	44864000 */ 	mtc1	$a2,$f8
/*  f1356d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1356dc:	460a2402 */ 	mul.s	$f16,$f4,$f10
/*  f1356e0:	04c10004 */ 	bgez	$a2,.L0f1356f4
/*  f1356e4:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f1356e8:	44815000 */ 	mtc1	$at,$f10
/*  f1356ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1356f0:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f1356f4:
/*  f1356f4:	44864000 */ 	mtc1	$a2,$f8
/*  f1356f8:	461e2482 */ 	mul.s	$f18,$f4,$f30
/*  f1356fc:	3c014f80 */ 	lui	$at,0x4f80
/*  f135700:	04c10004 */ 	bgez	$a2,.L0f135714
/*  f135704:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f135708:	44812000 */ 	mtc1	$at,$f4
/*  f13570c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135710:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f135714:
/*  f135714:	46065502 */ 	mul.s	$f20,$f10,$f6
/*  f135718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13571c:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f135720:	10560018 */ 	beq	$v0,$s6,.L0f135784
/*  f135724:	00a41821 */ 	addu	$v1,$a1,$a0
.L0f135728:
/*  f135728:	c47e0000 */ 	lwc1	$f30,0x0($v1)
/*  f13572c:	c47c0004 */ 	lwc1	$f28,0x4($v1)
/*  f135730:	c45afff4 */ 	lwc1	$f26,-0xc($v0)
/*  f135734:	461e6602 */ 	mul.s	$f24,$f12,$f30
/*  f135738:	c44afff8 */ 	lwc1	$f10,-0x8($v0)
/*  f13573c:	c448fffc */ 	lwc1	$f8,-0x4($v0)
/*  f135740:	461c7182 */ 	mul.s	$f6,$f14,$f28
/*  f135744:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f135748:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f13574c:	461c8102 */ 	mul.s	$f4,$f16,$f28
/*  f135750:	00a41821 */ 	addu	$v1,$a1,$a0
/*  f135754:	461e9782 */ 	mul.s	$f30,$f18,$f30
/*  f135758:	4606c180 */ 	add.s	$f6,$f24,$f6
/*  f13575c:	461ca702 */ 	mul.s	$f28,$f20,$f28
/*  f135760:	4604b100 */ 	add.s	$f4,$f22,$f4
/*  f135764:	4606d180 */ 	add.s	$f6,$f26,$f6
/*  f135768:	461cf700 */ 	add.s	$f28,$f30,$f28
/*  f13576c:	e446ffe8 */ 	swc1	$f6,-0x18($v0)
/*  f135770:	46045100 */ 	add.s	$f4,$f10,$f4
/*  f135774:	461c4700 */ 	add.s	$f28,$f8,$f28
/*  f135778:	e444ffec */ 	swc1	$f4,-0x14($v0)
/*  f13577c:	1456ffea */ 	bne	$v0,$s6,.L0f135728
/*  f135780:	e45cfff0 */ 	swc1	$f28,-0x10($v0)
.L0f135784:
/*  f135784:	c47e0000 */ 	lwc1	$f30,0x0($v1)
/*  f135788:	c47c0004 */ 	lwc1	$f28,0x4($v1)
/*  f13578c:	c45afff4 */ 	lwc1	$f26,-0xc($v0)
/*  f135790:	461e6602 */ 	mul.s	$f24,$f12,$f30
/*  f135794:	c44afff8 */ 	lwc1	$f10,-0x8($v0)
/*  f135798:	c448fffc */ 	lwc1	$f8,-0x4($v0)
/*  f13579c:	461c7182 */ 	mul.s	$f6,$f14,$f28
/*  f1357a0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1357a4:	461c8102 */ 	mul.s	$f4,$f16,$f28
/*  f1357a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1357ac:	461e9782 */ 	mul.s	$f30,$f18,$f30
/*  f1357b0:	4606c180 */ 	add.s	$f6,$f24,$f6
/*  f1357b4:	461ca702 */ 	mul.s	$f28,$f20,$f28
/*  f1357b8:	4604b100 */ 	add.s	$f4,$f22,$f4
/*  f1357bc:	4606d180 */ 	add.s	$f6,$f26,$f6
/*  f1357c0:	461cf700 */ 	add.s	$f28,$f30,$f28
/*  f1357c4:	e446fff4 */ 	swc1	$f6,-0xc($v0)
/*  f1357c8:	46045100 */ 	add.s	$f4,$f10,$f4
/*  f1357cc:	461c4700 */ 	add.s	$f28,$f8,$f28
/*  f1357d0:	e444fff8 */ 	swc1	$f4,-0x8($v0)
/*  f1357d4:	e45cfffc */ 	swc1	$f28,-0x4($v0)
/*  f1357d8:	3c014316 */ 	lui	$at,0x4316
/*  f1357dc:	4481b000 */ 	mtc1	$at,$f22
/*  f1357e0:	c6423e98 */ 	lwc1	$f2,0x3e98($s2)
/*  f1357e4:	c6000000 */ 	lwc1	$f0,0x0($s0)
/*  f1357e8:	4480c000 */ 	mtc1	$zero,$f24
/*  f1357ec:	46161100 */ 	add.s	$f4,$f2,$f22
/*  f1357f0:	3c014180 */ 	lui	$at,0x4180
/*  f1357f4:	33c40001 */ 	andi	$a0,$s8,0x1
/*  f1357f8:	4600c406 */ 	mov.s	$f16,$f24
/*  f1357fc:	4604003c */ 	c.lt.s	$f0,$f4
/*  f135800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135804:	45020004 */ 	bc1fl	.L0f135818
/*  f135808:	c6423e8c */ 	lwc1	$f2,0x3e8c($s2)
/*  f13580c:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f135810:	46164401 */ 	sub.s	$f16,$f8,$f22
/*  f135814:	c6423e8c */ 	lwc1	$f2,0x3e8c($s2)
.L0f135818:
/*  f135818:	46161281 */ 	sub.s	$f10,$f2,$f22
/*  f13581c:	4600503c */ 	c.lt.s	$f10,$f0
/*  f135820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135824:	45020004 */ 	bc1fl	.L0f135838
/*  f135828:	4610c03c */ 	c.lt.s	$f24,$f16
/*  f13582c:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f135830:	46163400 */ 	add.s	$f16,$f6,$f22
/*  f135834:	4610c03c */ 	c.lt.s	$f24,$f16
.L0f135838:
/*  f135838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13583c:	45020004 */ 	bc1fl	.L0f135850
/*  f135840:	46008307 */ 	neg.s	$f12,$f16
/*  f135844:	10000002 */ 	beqz	$zero,.L0f135850
/*  f135848:	46008306 */ 	mov.s	$f12,$f16
/*  f13584c:	46008307 */ 	neg.s	$f12,$f16
.L0f135850:
/*  f135850:	46166003 */ 	div.s	$f0,$f12,$f22
/*  f135854:	c7a40260 */ 	lwc1	$f4,0x260($sp)
/*  f135858:	4600203c */ 	c.lt.s	$f4,$f0
/*  f13585c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135860:	45020003 */ 	bc1fl	.L0f135870
/*  f135864:	c64c3e9c */ 	lwc1	$f12,0x3e9c($s2)
/*  f135868:	e7a00260 */ 	swc1	$f0,0x260($sp)
/*  f13586c:	c64c3e9c */ 	lwc1	$f12,0x3e9c($s2)
.L0f135870:
/*  f135870:	c60e0004 */ 	lwc1	$f14,0x4($s0)
/*  f135874:	c7b20260 */ 	lwc1	$f18,0x260($sp)
/*  f135878:	46166200 */ 	add.s	$f8,$f12,$f22
/*  f13587c:	4600c406 */ 	mov.s	$f16,$f24
/*  f135880:	8fb80214 */ 	lw	$t8,0x214($sp)
/*  f135884:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f135888:	4608703c */ 	c.lt.s	$f14,$f8
/*  f13588c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135890:	45020004 */ 	bc1fl	.L0f1358a4
/*  f135894:	c6403e90 */ 	lwc1	$f0,0x3e90($s2)
/*  f135898:	460c7281 */ 	sub.s	$f10,$f14,$f12
/*  f13589c:	46165401 */ 	sub.s	$f16,$f10,$f22
/*  f1358a0:	c6403e90 */ 	lwc1	$f0,0x3e90($s2)
.L0f1358a4:
/*  f1358a4:	46160181 */ 	sub.s	$f6,$f0,$f22
/*  f1358a8:	460e303c */ 	c.lt.s	$f6,$f14
/*  f1358ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1358b0:	45020004 */ 	bc1fl	.L0f1358c4
/*  f1358b4:	4610c03c */ 	c.lt.s	$f24,$f16
/*  f1358b8:	46007101 */ 	sub.s	$f4,$f14,$f0
/*  f1358bc:	46162400 */ 	add.s	$f16,$f4,$f22
/*  f1358c0:	4610c03c */ 	c.lt.s	$f24,$f16
.L0f1358c4:
/*  f1358c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1358c8:	45020004 */ 	bc1fl	.L0f1358dc
/*  f1358cc:	46008307 */ 	neg.s	$f12,$f16
/*  f1358d0:	10000002 */ 	beqz	$zero,.L0f1358dc
/*  f1358d4:	46008306 */ 	mov.s	$f12,$f16
/*  f1358d8:	46008307 */ 	neg.s	$f12,$f16
.L0f1358dc:
/*  f1358dc:	46166003 */ 	div.s	$f0,$f12,$f22
/*  f1358e0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1358e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1358e8:	45020003 */ 	bc1fl	.L0f1358f8
/*  f1358ec:	c64e3ea0 */ 	lwc1	$f14,0x3ea0($s2)
/*  f1358f0:	46000486 */ 	mov.s	$f18,$f0
/*  f1358f4:	c64e3ea0 */ 	lwc1	$f14,0x3ea0($s2)
.L0f1358f8:
/*  f1358f8:	c6020008 */ 	lwc1	$f2,0x8($s0)
/*  f1358fc:	4600c406 */ 	mov.s	$f16,$f24
/*  f135900:	46167200 */ 	add.s	$f8,$f14,$f22
/*  f135904:	33c70002 */ 	andi	$a3,$s8,0x2
/*  f135908:	4608103c */ 	c.lt.s	$f2,$f8
/*  f13590c:	44814000 */ 	mtc1	$at,$f8
/*  f135910:	45020004 */ 	bc1fl	.L0f135924
/*  f135914:	c6403e94 */ 	lwc1	$f0,0x3e94($s2)
/*  f135918:	460e1281 */ 	sub.s	$f10,$f2,$f14
/*  f13591c:	46165401 */ 	sub.s	$f16,$f10,$f22
/*  f135920:	c6403e94 */ 	lwc1	$f0,0x3e94($s2)
.L0f135924:
/*  f135924:	030e1021 */ 	addu	$v0,$t8,$t6
/*  f135928:	46160181 */ 	sub.s	$f6,$f0,$f22
/*  f13592c:	4602303c */ 	c.lt.s	$f6,$f2
/*  f135930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135934:	45020004 */ 	bc1fl	.L0f135948
/*  f135938:	4610c03c */ 	c.lt.s	$f24,$f16
/*  f13593c:	46001101 */ 	sub.s	$f4,$f2,$f0
/*  f135940:	46162400 */ 	add.s	$f16,$f4,$f22
/*  f135944:	4610c03c */ 	c.lt.s	$f24,$f16
.L0f135948:
/*  f135948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13594c:	45020004 */ 	bc1fl	.L0f135960
/*  f135950:	46008307 */ 	neg.s	$f12,$f16
/*  f135954:	10000002 */ 	beqz	$zero,.L0f135960
/*  f135958:	46008306 */ 	mov.s	$f12,$f16
/*  f13595c:	46008307 */ 	neg.s	$f12,$f16
.L0f135960:
/*  f135960:	46166003 */ 	div.s	$f0,$f12,$f22
/*  f135964:	4600903c */ 	c.lt.s	$f18,$f0
/*  f135968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13596c:	45000002 */ 	bc1f	.L0f135978
/*  f135970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135974:	46000486 */ 	mov.s	$f18,$f0
.L0f135978:
/*  f135978:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f13597c:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f135980:	00077043 */ 	sra	$t6,$a3,0x1
/*  f135984:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f135988:	00184140 */ 	sll	$t0,$t8,0x5
/*  f13598c:	25e50008 */ 	addiu	$a1,$t7,0x8
/*  f135990:	27060008 */ 	addiu	$a2,$t8,0x8
/*  f135994:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f135998:	0006c140 */ 	sll	$t8,$a2,0x5
/*  f13599c:	a4480008 */ 	sh	$t0,0x8($v0)
/*  f1359a0:	a4580014 */ 	sh	$t8,0x14($v0)
/*  f1359a4:	44033000 */ 	mfc1	$v1,$f6
/*  f1359a8:	a4580020 */ 	sh	$t8,0x20($v0)
/*  f1359ac:	a448002c */ 	sh	$t0,0x2c($v0)
/*  f1359b0:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1359b4:	a0590007 */ 	sb	$t9,0x7($v0)
/*  f1359b8:	a0590013 */ 	sb	$t9,0x13($v0)
/*  f1359bc:	a059001f */ 	sb	$t9,0x1f($v0)
/*  f1359c0:	a059002b */ 	sb	$t9,0x2b($v0)
/*  f1359c4:	0005c940 */ 	sll	$t9,$a1,0x5
/*  f1359c8:	000f1940 */ 	sll	$v1,$t7,0x5
/*  f1359cc:	a459000a */ 	sh	$t9,0xa($v0)
/*  f1359d0:	a4590016 */ 	sh	$t9,0x16($v0)
/*  f1359d4:	a4430022 */ 	sh	$v1,0x22($v0)
/*  f1359d8:	a443002e */ 	sh	$v1,0x2e($v0)
/*  f1359dc:	c7a4019c */ 	lwc1	$f4,0x19c($sp)
/*  f1359e0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1359e4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1359e8:	440f4000 */ 	mfc1	$t7,$f8
/*  f1359ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1359f0:	a44f0000 */ 	sh	$t7,0x0($v0)
/*  f1359f4:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
/*  f1359f8:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1359fc:	44183000 */ 	mfc1	$t8,$f6
/*  f135a00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a04:	a4580002 */ 	sh	$t8,0x2($v0)
/*  f135a08:	c7a401a4 */ 	lwc1	$f4,0x1a4($sp)
/*  f135a0c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f135a10:	440f4000 */ 	mfc1	$t7,$f8
/*  f135a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a18:	a44f0004 */ 	sh	$t7,0x4($v0)
/*  f135a1c:	c7aa01a8 */ 	lwc1	$f10,0x1a8($sp)
/*  f135a20:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f135a24:	44183000 */ 	mfc1	$t8,$f6
/*  f135a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a2c:	a458000c */ 	sh	$t8,0xc($v0)
/*  f135a30:	c7a401ac */ 	lwc1	$f4,0x1ac($sp)
/*  f135a34:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f135a38:	440f4000 */ 	mfc1	$t7,$f8
/*  f135a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a40:	a44f000e */ 	sh	$t7,0xe($v0)
/*  f135a44:	c7aa01b0 */ 	lwc1	$f10,0x1b0($sp)
/*  f135a48:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f135a4c:	44183000 */ 	mfc1	$t8,$f6
/*  f135a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a54:	a4580010 */ 	sh	$t8,0x10($v0)
/*  f135a58:	c7a401b4 */ 	lwc1	$f4,0x1b4($sp)
/*  f135a5c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f135a60:	440f4000 */ 	mfc1	$t7,$f8
/*  f135a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a68:	a44f0018 */ 	sh	$t7,0x18($v0)
/*  f135a6c:	c7aa01b8 */ 	lwc1	$f10,0x1b8($sp)
/*  f135a70:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f135a74:	44183000 */ 	mfc1	$t8,$f6
/*  f135a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a7c:	a458001a */ 	sh	$t8,0x1a($v0)
/*  f135a80:	c7a401bc */ 	lwc1	$f4,0x1bc($sp)
/*  f135a84:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f135a88:	440f4000 */ 	mfc1	$t7,$f8
/*  f135a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a90:	a44f001c */ 	sh	$t7,0x1c($v0)
/*  f135a94:	c7aa01c0 */ 	lwc1	$f10,0x1c0($sp)
/*  f135a98:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f135a9c:	44183000 */ 	mfc1	$t8,$f6
/*  f135aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135aa4:	a4580024 */ 	sh	$t8,0x24($v0)
/*  f135aa8:	c7a401c4 */ 	lwc1	$f4,0x1c4($sp)
/*  f135aac:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f135ab0:	440f4000 */ 	mfc1	$t7,$f8
/*  f135ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135ab8:	a44f0026 */ 	sh	$t7,0x26($v0)
/*  f135abc:	c7aa01c8 */ 	lwc1	$f10,0x1c8($sp)
/*  f135ac0:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f135ac4:	44183000 */ 	mfc1	$t8,$f6
/*  f135ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135acc:	a4580028 */ 	sh	$t8,0x28($v0)
/*  f135ad0:	8fae0198 */ 	lw	$t6,0x198($sp)
/*  f135ad4:	8fb11398 */ 	lw	$s1,0x1398($sp)
/*  f135ad8:	3c180470 */ 	lui	$t8,0x470
/*  f135adc:	15c10012 */ 	bne	$t6,$at,.L0f135b28
/*  f135ae0:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f135ae4:	afb91398 */ 	sw	$t9,0x1398($sp)
/*  f135ae8:	37180060 */ 	ori	$t8,$t8,0x60
/*  f135aec:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f135af0:	afa00198 */ 	sw	$zero,0x198($sp)
/*  f135af4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f135af8:	8fa40214 */ 	lw	$a0,0x214($sp)
/*  f135afc:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f135b00:	8fae1398 */ 	lw	$t6,0x1398($sp)
/*  f135b04:	3c19b100 */ 	lui	$t9,0xb100
/*  f135b08:	3c187654 */ 	lui	$t8,0x7654
/*  f135b0c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f135b10:	afaf1398 */ 	sw	$t7,0x1398($sp)
/*  f135b14:	37183210 */ 	ori	$t8,$t8,0x3210
/*  f135b18:	37394602 */ 	ori	$t9,$t9,0x4602
/*  f135b1c:	add90000 */ 	sw	$t9,0x0($t6)
/*  f135b20:	10000003 */ 	beqz	$zero,.L0f135b30
/*  f135b24:	add80004 */ 	sw	$t8,0x4($t6)
.L0f135b28:
/*  f135b28:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f135b2c:	afae0198 */ 	sw	$t6,0x198($sp)
.L0f135b30:
/*  f135b30:	27de0001 */ 	addiu	$s8,$s8,0x1
.L0f135b34:
/*  f135b34:	240101f4 */ 	addiu	$at,$zero,0x1f4
/*  f135b38:	17c1fdaf */ 	bne	$s8,$at,.L0f1351f8
/*  f135b3c:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f135b40:	8faf0198 */ 	lw	$t7,0x198($sp)
/*  f135b44:	8fb01398 */ 	lw	$s0,0x1398($sp)
/*  f135b48:	3c0e0470 */ 	lui	$t6,0x470
/*  f135b4c:	19e0000f */ 	blez	$t7,.L0f135b8c
/*  f135b50:	26180008 */ 	addiu	$t8,$s0,0x8
/*  f135b54:	afb81398 */ 	sw	$t8,0x1398($sp)
/*  f135b58:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f135b5c:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f135b60:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f135b64:	8fa40214 */ 	lw	$a0,0x214($sp)
/*  f135b68:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f135b6c:	8faf1398 */ 	lw	$t7,0x1398($sp)
/*  f135b70:	3c18b100 */ 	lui	$t8,0xb100
/*  f135b74:	37180002 */ 	ori	$t8,$t8,0x2
/*  f135b78:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f135b7c:	afb91398 */ 	sw	$t9,0x1398($sp)
/*  f135b80:	240e3210 */ 	addiu	$t6,$zero,0x3210
/*  f135b84:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f135b88:	adf80000 */ 	sw	$t8,0x0($t7)
.L0f135b8c:
/*  f135b8c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f135b90:	8fa21398 */ 	lw	$v0,0x1398($sp)
/*  f135b94:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f135b98:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f135b9c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f135ba0:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f135ba4:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f135ba8:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f135bac:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f135bb0:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f135bb4:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f135bb8:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f135bbc:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f135bc0:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f135bc4:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f135bc8:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f135bcc:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f135bd0:	03e00008 */ 	jr	$ra
/*  f135bd4:	27bd1398 */ 	addiu	$sp,$sp,0x1398
);

void weatherFree(void)
{
	if (g_WeatherData) {
		if (g_WeatherData->unk34) {
			func00033b24(g_WeatherData->unk34);
		}

		if (g_WeatherData->unk38) {
			func00033b24(g_WeatherData->unk38);
		}

		if (g_WeatherData->unk3c) {
			func00033b24(g_WeatherData->unk3c);
		}

		if (g_WeatherData->unk40) {
			func00033b24(g_WeatherData->unk40);
		}

		g_WeatherData = NULL;
	}
}
