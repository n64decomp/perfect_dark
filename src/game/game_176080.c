#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_0b28d0.h"
#include "game/game_152710.h"
#include "game/game_176080.h"
#include "game/game_187770.h"

GLOBAL_ASM(
glabel func0f176080
/*  f176080:	3c028008 */ 	lui	$v0,0x8008
/*  f176084:	03e00008 */ 	jr	$ra
/*  f176088:	8c4244f0 */ 	lw	$v0,0x44f0($v0)
);

GLOBAL_ASM(
glabel func0f17608c
/*  f17608c:	3c018008 */ 	lui	$at,0x8008
/*  f176090:	ac2044f0 */ 	sw	$zero,0x44f0($at)
/*  f176094:	3c018008 */ 	lui	$at,0x8008
/*  f176098:	ac2044f4 */ 	sw	$zero,0x44f4($at)
/*  f17609c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1760a0:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f1760a4:	10810003 */ 	beq	$a0,$at,.L0f1760b4
/*  f1760a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1760ac:	0fc5d831 */ 	jal	func0f1760c4
/*  f1760b0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1760b4:
/*  f1760b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1760b8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1760bc:	03e00008 */ 	jr	$ra
/*  f1760c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1760c4
/*  f1760c4:	3c0e8009 */ 	lui	$t6,0x8009
/*  f1760c8:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f1760cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1760d0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1760d4:	15c1002f */ 	bne	$t6,$at,.L0f176194
/*  f1760d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1760dc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1760e0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1760e4:	8c580318 */ 	lw	$t8,0x318($v0)
/*  f1760e8:	3c06800b */ 	lui	$a2,%hi(var800ab7c0)
/*  f1760ec:	24c6b7c0 */ 	addiu	$a2,$a2,%lo(var800ab7c0)
/*  f1760f0:	240f0140 */ 	addiu	$t7,$zero,0x140
/*  f1760f4:	13000022 */ 	beqz	$t8,.L0f176180
/*  f1760f8:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1760fc:	8c59006c */ 	lw	$t9,0x6c($v0)
/*  f176100:	00002825 */ 	or	$a1,$zero,$zero
/*  f176104:	00002025 */ 	or	$a0,$zero,$zero
/*  f176108:	13200003 */ 	beqz	$t9,.L0f176118
/*  f17610c:	00001825 */ 	or	$v1,$zero,$zero
/*  f176110:	10000001 */ 	beqz	$zero,.L0f176118
/*  f176114:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f176118:
/*  f176118:	8c480068 */ 	lw	$t0,0x68($v0)
/*  f17611c:	240e006e */ 	addiu	$t6,$zero,0x6e
/*  f176120:	11000003 */ 	beqz	$t0,.L0f176130
/*  f176124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176128:	10000001 */ 	beqz	$zero,.L0f176130
/*  f17612c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f176130:
/*  f176130:	8c490064 */ 	lw	$t1,0x64($v0)
/*  f176134:	11200003 */ 	beqz	$t1,.L0f176144
/*  f176138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17613c:	10000001 */ 	beqz	$zero,.L0f176144
/*  f176140:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f176144:
/*  f176144:	8c4a0070 */ 	lw	$t2,0x70($v0)
/*  f176148:	00001025 */ 	or	$v0,$zero,$zero
/*  f17614c:	11400003 */ 	beqz	$t2,.L0f17615c
/*  f176150:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176154:	10000001 */ 	beqz	$zero,.L0f17615c
/*  f176158:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17615c:
/*  f17615c:	00435821 */ 	addu	$t3,$v0,$v1
/*  f176160:	01646021 */ 	addu	$t4,$t3,$a0
/*  f176164:	01856821 */ 	addu	$t5,$t4,$a1
/*  f176168:	29a10002 */ 	slti	$at,$t5,0x2
/*  f17616c:	14200004 */ 	bnez	$at,.L0f176180
/*  f176170:	3c02800b */ 	lui	$v0,%hi(var800ab7c4)
/*  f176174:	2442b7c4 */ 	addiu	$v0,$v0,%lo(var800ab7c4)
/*  f176178:	10000033 */ 	beqz	$zero,.L0f176248
/*  f17617c:	ac4e0000 */ 	sw	$t6,0x0($v0)
.L0f176180:
/*  f176180:	3c02800b */ 	lui	$v0,%hi(var800ab7c4)
/*  f176184:	2442b7c4 */ 	addiu	$v0,$v0,%lo(var800ab7c4)
/*  f176188:	240f00dc */ 	addiu	$t7,$zero,0xdc
/*  f17618c:	1000002e */ 	beqz	$zero,.L0f176248
/*  f176190:	ac4f0000 */ 	sw	$t7,0x0($v0)
.L0f176194:
/*  f176194:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f176198:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17619c:	8c590318 */ 	lw	$t9,0x318($v0)
/*  f1761a0:	3c06800b */ 	lui	$a2,%hi(var800ab7c0)
/*  f1761a4:	24c6b7c0 */ 	addiu	$a2,$a2,%lo(var800ab7c0)
/*  f1761a8:	24180280 */ 	addiu	$t8,$zero,0x280
/*  f1761ac:	13200022 */ 	beqz	$t9,.L0f176238
/*  f1761b0:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f1761b4:	8c48006c */ 	lw	$t0,0x6c($v0)
/*  f1761b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1761bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1761c0:	11000003 */ 	beqz	$t0,.L0f1761d0
/*  f1761c4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1761c8:	10000001 */ 	beqz	$zero,.L0f1761d0
/*  f1761cc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1761d0:
/*  f1761d0:	8c490068 */ 	lw	$t1,0x68($v0)
/*  f1761d4:	240f00dc */ 	addiu	$t7,$zero,0xdc
/*  f1761d8:	11200003 */ 	beqz	$t1,.L0f1761e8
/*  f1761dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1761e0:	10000001 */ 	beqz	$zero,.L0f1761e8
/*  f1761e4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1761e8:
/*  f1761e8:	8c4a0064 */ 	lw	$t2,0x64($v0)
/*  f1761ec:	11400003 */ 	beqz	$t2,.L0f1761fc
/*  f1761f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1761f4:	10000001 */ 	beqz	$zero,.L0f1761fc
/*  f1761f8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1761fc:
/*  f1761fc:	8c4b0070 */ 	lw	$t3,0x70($v0)
/*  f176200:	00001025 */ 	or	$v0,$zero,$zero
/*  f176204:	11600003 */ 	beqz	$t3,.L0f176214
/*  f176208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17620c:	10000001 */ 	beqz	$zero,.L0f176214
/*  f176210:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f176214:
/*  f176214:	00436021 */ 	addu	$t4,$v0,$v1
/*  f176218:	01846821 */ 	addu	$t5,$t4,$a0
/*  f17621c:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f176220:	29c10002 */ 	slti	$at,$t6,0x2
/*  f176224:	14200004 */ 	bnez	$at,.L0f176238
/*  f176228:	3c02800b */ 	lui	$v0,%hi(var800ab7c4)
/*  f17622c:	2442b7c4 */ 	addiu	$v0,$v0,%lo(var800ab7c4)
/*  f176230:	10000005 */ 	beqz	$zero,.L0f176248
/*  f176234:	ac4f0000 */ 	sw	$t7,0x0($v0)
.L0f176238:
/*  f176238:	3c02800b */ 	lui	$v0,%hi(var800ab7c4)
/*  f17623c:	2442b7c4 */ 	addiu	$v0,$v0,%lo(var800ab7c4)
/*  f176240:	241800dc */ 	addiu	$t8,$zero,0xdc
/*  f176244:	ac580000 */ 	sw	$t8,0x0($v0)
.L0f176248:
/*  f176248:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f17624c:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f176250:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f176254:	03280019 */ 	multu	$t9,$t0
/*  f176258:	00002012 */ 	mflo	$a0
/*  f17625c:	00044840 */ 	sll	$t1,$a0,0x1
/*  f176260:	0c0048f2 */ 	jal	func000123c8
/*  f176264:	25240040 */ 	addiu	$a0,$t1,0x40
/*  f176268:	3c038008 */ 	lui	$v1,%hi(var800844f0)
/*  f17626c:	244b003f */ 	addiu	$t3,$v0,0x3f
/*  f176270:	2401ffc0 */ 	addiu	$at,$zero,-64
/*  f176274:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f176278:	246344f0 */ 	addiu	$v1,$v1,%lo(var800844f0)
/*  f17627c:	01616024 */ 	and	$t4,$t3,$at
/*  f176280:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f176284:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f176288:	3c018008 */ 	lui	$at,0x8008
/*  f17628c:	ac2c44f4 */ 	sw	$t4,0x44f4($at)
/*  f176290:	03e00008 */ 	jr	$ra
/*  f176294:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f176298
/*  f176298:	3c0e8008 */ 	lui	$t6,0x8008
/*  f17629c:	8dce44f0 */ 	lw	$t6,0x44f0($t6)
/*  f1762a0:	3c018008 */ 	lui	$at,0x8008
/*  f1762a4:	03e00008 */ 	jr	$ra
/*  f1762a8:	ac2e44f4 */ 	sw	$t6,0x44f4($at)
);

GLOBAL_ASM(
glabel func0f1762ac
/*  f1762ac:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1762b0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1762b4:	8c4e0318 */ 	lw	$t6,0x318($v0)
/*  f1762b8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1762bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1762c0:	11c0003a */ 	beqz	$t6,.L0f1763ac
/*  f1762c4:	00803825 */ 	or	$a3,$a0,$zero
/*  f1762c8:	8c46028c */ 	lw	$a2,0x28c($v0)
/*  f1762cc:	28c10002 */ 	slti	$at,$a2,0x2
/*  f1762d0:	10200020 */ 	beqz	$at,.L0f176354
/*  f1762d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1762d8:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f1762dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1762e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1762e4:	11e00003 */ 	beqz	$t7,.L0f1762f4
/*  f1762e8:	00001825 */ 	or	$v1,$zero,$zero
/*  f1762ec:	10000001 */ 	beqz	$zero,.L0f1762f4
/*  f1762f0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1762f4:
/*  f1762f4:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f1762f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1762fc:	13000003 */ 	beqz	$t8,.L0f17630c
/*  f176300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176304:	10000001 */ 	beqz	$zero,.L0f17630c
/*  f176308:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f17630c:
/*  f17630c:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f176310:	13200003 */ 	beqz	$t9,.L0f176320
/*  f176314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176318:	10000001 */ 	beqz	$zero,.L0f176320
/*  f17631c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f176320:
/*  f176320:	8c480070 */ 	lw	$t0,0x70($v0)
/*  f176324:	00001025 */ 	or	$v0,$zero,$zero
/*  f176328:	11000003 */ 	beqz	$t0,.L0f176338
/*  f17632c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176330:	10000001 */ 	beqz	$zero,.L0f176338
/*  f176334:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f176338:
/*  f176338:	00444821 */ 	addu	$t1,$v0,$a0
/*  f17633c:	01235021 */ 	addu	$t2,$t1,$v1
/*  f176340:	01455821 */ 	addu	$t3,$t2,$a1
/*  f176344:	15610019 */ 	bne	$t3,$at,.L0f1763ac
/*  f176348:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17634c:	54c10018 */ 	bnel	$a2,$at,.L0f1763b0
/*  f176350:	00003025 */ 	or	$a2,$zero,$zero
.L0f176354:
/*  f176354:	0fc2f113 */ 	jal	func0f0bc44c
/*  f176358:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f17635c:	0fc2f11e */ 	jal	func0f0bc478
/*  f176360:	a7a2001e */ 	sh	$v0,0x1e($sp)
/*  f176364:	87ac001e */ 	lh	$t4,0x1e($sp)
/*  f176368:	3c0d8009 */ 	lui	$t5,0x8009
/*  f17636c:	91ad0af0 */ 	lbu	$t5,0xaf0($t5)
/*  f176370:	004c0019 */ 	multu	$v0,$t4
/*  f176374:	24010001 */ 	addiu	$at,$zero,0x1
/*  f176378:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f17637c:	00003012 */ 	mflo	$a2
/*  f176380:	11a10008 */ 	beq	$t5,$at,.L0f1763a4
/*  f176384:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176388:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f17638c:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f176390:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f176394:	24010001 */ 	addiu	$at,$zero,0x1
/*  f176398:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f17639c:	14410004 */ 	bne	$v0,$at,.L0f1763b0
/*  f1763a0:	8fa70040 */ 	lw	$a3,0x40($sp)
.L0f1763a4:
/*  f1763a4:	10000002 */ 	beqz	$zero,.L0f1763b0
/*  f1763a8:	00003025 */ 	or	$a2,$zero,$zero
.L0f1763ac:
/*  f1763ac:	00003025 */ 	or	$a2,$zero,$zero
.L0f1763b0:
/*  f1763b0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1763b4:	8dce44f4 */ 	lw	$t6,0x44f4($t6)
/*  f1763b8:	3c18e700 */ 	lui	$t8,0xe700
/*  f1763bc:	2401ffc0 */ 	addiu	$at,$zero,-64
/*  f1763c0:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f1763c4:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f1763c8:	24e50008 */ 	addiu	$a1,$a3,0x8
/*  f1763cc:	01c61823 */ 	subu	$v1,$t6,$a2
/*  f1763d0:	00617824 */ 	and	$t7,$v1,$at
/*  f1763d4:	3c19fe00 */ 	lui	$t9,0xfe00
/*  f1763d8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f1763dc:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f1763e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1763e4:	24a20008 */ 	addiu	$v0,$a1,0x8
/*  f1763e8:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f1763ec:	03e00008 */ 	jr	$ra
/*  f1763f0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1763f4
/*  f1763f4:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f1763f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1763fc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f176400:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f176404:	3c0ee700 */ 	lui	$t6,0xe700
/*  f176408:	02001825 */ 	or	$v1,$s0,$zero
/*  f17640c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f176410:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f176414:	3c0fb900 */ 	lui	$t7,0xb900
/*  f176418:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f17641c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176420:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f176424:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f176428:	02002825 */ 	or	$a1,$s0,$zero
/*  f17642c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f176430:	0c002f02 */ 	jal	func0000bc08
/*  f176434:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176438:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f17643c:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f176440:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f176444:	3c01ff10 */ 	lui	$at,0xff10
/*  f176448:	03214025 */ 	or	$t0,$t9,$at
/*  f17644c:	3c098008 */ 	lui	$t1,0x8008
/*  f176450:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f176454:	8d2944f4 */ 	lw	$t1,0x44f4($t1)
/*  f176458:	3c018000 */ 	lui	$at,0x8000
/*  f17645c:	02001825 */ 	or	$v1,$s0,$zero
/*  f176460:	01215021 */ 	addu	$t2,$t1,$at
/*  f176464:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176468:	3c0bba00 */ 	lui	$t3,0xba00
/*  f17646c:	acaa0004 */ 	sw	$t2,0x4($a1)
/*  f176470:	356b1402 */ 	ori	$t3,$t3,0x1402
/*  f176474:	3c0c0030 */ 	lui	$t4,0x30
/*  f176478:	02002025 */ 	or	$a0,$s0,$zero
/*  f17647c:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f176480:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f176484:	3c0efffc */ 	lui	$t6,0xfffc
/*  f176488:	35cefffc */ 	ori	$t6,$t6,0xfffc
/*  f17648c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176490:	3c0df700 */ 	lui	$t5,0xf700
/*  f176494:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f176498:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f17649c:	02003025 */ 	or	$a2,$s0,$zero
/*  f1764a0:	3c0fed00 */ 	lui	$t7,0xed00
/*  f1764a4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1764a8:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f1764ac:	0fc2f113 */ 	jal	func0f0bc44c
/*  f1764b0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1764b4:	0fc2f11e */ 	jal	func0f0bc478
/*  f1764b8:	a7a20026 */ 	sh	$v0,0x26($sp)
/*  f1764bc:	44822000 */ 	mtc1	$v0,$f4
/*  f1764c0:	87a90026 */ 	lh	$t1,0x26($sp)
/*  f1764c4:	3c014080 */ 	lui	$at,0x4080
/*  f1764c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1764cc:	44898000 */ 	mtc1	$t1,$f16
/*  f1764d0:	44810000 */ 	mtc1	$at,$f0
/*  f1764d4:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f1764d8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f1764dc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1764e0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f1764e4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f1764e8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1764ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f1764f0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1764f4:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f1764f8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1764fc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f176500:	44195000 */ 	mfc1	$t9,$f10
/*  f176504:	440b3000 */ 	mfc1	$t3,$f6
/*  f176508:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f17650c:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f176510:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f176514:	010d7025 */ 	or	$t6,$t0,$t5
/*  f176518:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f17651c:	8cb8006c */ 	lw	$t8,0x6c($a1)
/*  f176520:	13000003 */ 	beqz	$t8,.L0f176530
/*  f176524:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176528:	10000001 */ 	beqz	$zero,.L0f176530
/*  f17652c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f176530:
/*  f176530:	8cb90068 */ 	lw	$t9,0x68($a1)
/*  f176534:	00001025 */ 	or	$v0,$zero,$zero
/*  f176538:	13200003 */ 	beqz	$t9,.L0f176548
/*  f17653c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176540:	10000001 */ 	beqz	$zero,.L0f176548
/*  f176544:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f176548:
/*  f176548:	8ca90064 */ 	lw	$t1,0x64($a1)
/*  f17654c:	11200003 */ 	beqz	$t1,.L0f17655c
/*  f176550:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176554:	10000001 */ 	beqz	$zero,.L0f17655c
/*  f176558:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f17655c:
/*  f17655c:	8caa0070 */ 	lw	$t2,0x70($a1)
/*  f176560:	11400003 */ 	beqz	$t2,.L0f176570
/*  f176564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176568:	10000001 */ 	beqz	$zero,.L0f176570
/*  f17656c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f176570:
/*  f176570:	00445821 */ 	addu	$t3,$v0,$a0
/*  f176574:	01636021 */ 	addu	$t4,$t3,$v1
/*  f176578:	01864021 */ 	addu	$t0,$t4,$a2
/*  f17657c:	29010003 */ 	slti	$at,$t0,0x3
/*  f176580:	50200006 */ 	beqzl	$at,.L0f17659c
/*  f176584:	8ca2028c */ 	lw	$v0,0x28c($a1)
/*  f176588:	0fc2f113 */ 	jal	func0f0bc44c
/*  f17658c:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f176590:	10000018 */ 	beqz	$zero,.L0f1765f4
/*  f176594:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f176598:	8ca2028c */ 	lw	$v0,0x28c($a1)
.L0f17659c:
/*  f17659c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1765a0:	10400003 */ 	beqz	$v0,.L0f1765b0
/*  f1765a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1765a8:	14410009 */ 	bne	$v0,$at,.L0f1765d0
/*  f1765ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1765b0:
/*  f1765b0:	0fc2f113 */ 	jal	func0f0bc44c
/*  f1765b4:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f1765b8:	04410003 */ 	bgez	$v0,.L0f1765c8
/*  f1765bc:	00022043 */ 	sra	$a0,$v0,0x1
/*  f1765c0:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1765c4:	00012043 */ 	sra	$a0,$at,0x1
.L0f1765c8:
/*  f1765c8:	1000000a */ 	beqz	$zero,.L0f1765f4
/*  f1765cc:	2484ffff */ 	addiu	$a0,$a0,-1
.L0f1765d0:
/*  f1765d0:	0fc2f113 */ 	jal	func0f0bc44c
/*  f1765d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1765d8:	04410003 */ 	bgez	$v0,.L0f1765e8
/*  f1765dc:	00026843 */ 	sra	$t5,$v0,0x1
/*  f1765e0:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1765e4:	00016843 */ 	sra	$t5,$at,0x1
.L0f1765e8:
/*  f1765e8:	0fc2f113 */ 	jal	func0f0bc44c
/*  f1765ec:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f1765f0:	2444ffff */ 	addiu	$a0,$v0,-1
.L0f1765f4:
/*  f1765f4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1765f8:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f1765fc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176600:	0fc2f11e */ 	jal	func0f0bc478
/*  f176604:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f176608:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f17660c:	244effff */ 	addiu	$t6,$v0,-1
/*  f176610:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f176614:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f176618:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f17661c:	3c01f600 */ 	lui	$at,0xf600
/*  f176620:	308903ff */ 	andi	$t1,$a0,0x3ff
/*  f176624:	00095380 */ 	sll	$t2,$t1,0xe
/*  f176628:	0301c825 */ 	or	$t9,$t8,$at
/*  f17662c:	032a5825 */ 	or	$t3,$t9,$t2
/*  f176630:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f176634:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f176638:	02001825 */ 	or	$v1,$s0,$zero
/*  f17663c:	3c0ee700 */ 	lui	$t6,0xe700
/*  f176640:	318803ff */ 	andi	$t0,$t4,0x3ff
/*  f176644:	00086b80 */ 	sll	$t5,$t0,0xe
/*  f176648:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f17664c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f176650:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f176654:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f176658:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f17665c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f176660:	03e00008 */ 	jr	$ra
/*  f176664:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f176668
/*  f176668:	14800004 */ 	bnez	$a0,.L0f17667c
/*  f17666c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f176670:	3c03800b */ 	lui	$v1,%hi(var800ab7c8)
/*  f176674:	2463b7c8 */ 	addiu	$v1,$v1,%lo(var800ab7c8)
/*  f176678:	afa30004 */ 	sw	$v1,0x4($sp)
.L0f17667c:
/*  f17667c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f176680:	14810003 */ 	bne	$a0,$at,.L0f176690
/*  f176684:	8fa30004 */ 	lw	$v1,0x4($sp)
/*  f176688:	3c03800b */ 	lui	$v1,%hi(var800abac8)
/*  f17668c:	2463bac8 */ 	addiu	$v1,$v1,%lo(var800abac8)
.L0f176690:
/*  f176690:	24010002 */ 	addiu	$at,$zero,0x2
/*  f176694:	14810003 */ 	bne	$a0,$at,.L0f1766a4
/*  f176698:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f17669c:	3c03800b */ 	lui	$v1,%hi(var800abdc8)
/*  f1766a0:	2463bdc8 */ 	addiu	$v1,$v1,%lo(var800abdc8)
.L0f1766a4:
/*  f1766a4:	2463003f */ 	addiu	$v1,$v1,0x3f
/*  f1766a8:	2401ffc0 */ 	addiu	$at,$zero,-64
/*  f1766ac:	03e00008 */ 	jr	$ra
/*  f1766b0:	00611024 */ 	and	$v0,$v1,$at
);

GLOBAL_ASM(
glabel func0f1766b4
/*  f1766b4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f1766b8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1766bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1766c0:	00808025 */ 	or	$s0,$a0,$zero
/*  f1766c4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f1766c8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1766cc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1766d0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1766d4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1766d8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1766dc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1766e0:	0c000913 */ 	jal	func0000244c
/*  f1766e4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1766e8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1766ec:	8dce44f0 */ 	lw	$t6,0x44f0($t6)
/*  f1766f0:	00409025 */ 	or	$s2,$v0,$zero
/*  f1766f4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1766f8:	0c002ac7 */ 	jal	func0000ab1c
/*  f1766fc:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f176700:	3c138009 */ 	lui	$s3,%hi(var8008fa6c)
/*  f176704:	2673fa6c */ 	addiu	$s3,$s3,%lo(var8008fa6c)
/*  f176708:	0fc5d99a */ 	jal	func0f176668
/*  f17670c:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f176710:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f176714:	3c018009 */ 	lui	$at,0x8009
/*  f176718:	02001825 */ 	or	$v1,$s0,$zero
/*  f17671c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f176720:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176724:	00380821 */ 	addu	$at,$at,$t8
/*  f176728:	3c16e700 */ 	lui	$s6,0xe700
/*  f17672c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f176730:	a02ffa68 */ 	sb	$t7,-0x598($at)
/*  f176734:	02008825 */ 	or	$s1,$s0,$zero
/*  f176738:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f17673c:	ac760000 */ 	sw	$s6,0x0($v1)
/*  f176740:	0c002ef1 */ 	jal	func0000bbc4
/*  f176744:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176748:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f17674c:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f176750:	3c01ff10 */ 	lui	$at,0xff10
/*  f176754:	01014825 */ 	or	$t1,$t0,$at
/*  f176758:	ae290000 */ 	sw	$t1,0x0($s1)
/*  f17675c:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f176760:	3c018000 */ 	lui	$at,0x8000
/*  f176764:	02001825 */ 	or	$v1,$s0,$zero
/*  f176768:	01415821 */ 	addu	$t3,$t2,$at
/*  f17676c:	ae2b0004 */ 	sw	$t3,0x4($s1)
/*  f176770:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176774:	3c0ced00 */ 	lui	$t4,0xed00
/*  f176778:	3c0d0050 */ 	lui	$t5,0x50
/*  f17677c:	35ad03c0 */ 	ori	$t5,$t5,0x3c0
/*  f176780:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f176784:	02002025 */ 	or	$a0,$s0,$zero
/*  f176788:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f17678c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176790:	3c0eba00 */ 	lui	$t6,0xba00
/*  f176794:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f176798:	3c0f0020 */ 	lui	$t7,0x20
/*  f17679c:	02002825 */ 	or	$a1,$s0,$zero
/*  f1767a0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1767a4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1767a8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767ac:	3c190500 */ 	lui	$t9,0x500
/*  f1767b0:	3c18f510 */ 	lui	$t8,0xf510
/*  f1767b4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1767b8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1767bc:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1767c0:	3c08f510 */ 	lui	$t0,0xf510
/*  f1767c4:	35080080 */ 	ori	$t0,$t0,0x80
/*  f1767c8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767cc:	3c090400 */ 	lui	$t1,0x400
/*  f1767d0:	acc90004 */ 	sw	$t1,0x4($a2)
/*  f1767d4:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f1767d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1767dc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767e0:	3c0af511 */ 	lui	$t2,0xf511
/*  f1767e4:	354a4000 */ 	ori	$t2,$t2,0x4000
/*  f1767e8:	02001825 */ 	or	$v1,$s0,$zero
/*  f1767ec:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f1767f0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1767f4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1767f8:	3c0c0100 */ 	lui	$t4,0x100
/*  f1767fc:	3c0bf589 */ 	lui	$t3,0xf589
/*  f176800:	356b4080 */ 	ori	$t3,$t3,0x4080
/*  f176804:	358c000f */ 	ori	$t4,$t4,0xf
/*  f176808:	02002025 */ 	or	$a0,$s0,$zero
/*  f17680c:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f176810:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f176814:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176818:	3c0dbb00 */ 	lui	$t5,0xbb00
/*  f17681c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f176820:	35ad0001 */ 	ori	$t5,$t5,0x1
/*  f176824:	02002825 */ 	or	$a1,$s0,$zero
/*  f176828:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f17682c:	ac870004 */ 	sw	$a3,0x4($a0)
/*  f176830:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176834:	3c0efb00 */ 	lui	$t6,0xfb00
/*  f176838:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f17683c:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f176840:	02003025 */ 	or	$a2,$s0,$zero
/*  f176844:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176848:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f17684c:	02001025 */ 	or	$v0,$s0,$zero
/*  f176850:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f176854:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f176858:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17685c:	3c18b900 */ 	lui	$t8,0xb900
/*  f176860:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f176864:	02001825 */ 	or	$v1,$s0,$zero
/*  f176868:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f17686c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f176870:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176874:	3c08fffc */ 	lui	$t0,0xfffc
/*  f176878:	3c19fcff */ 	lui	$t9,0xfcff
/*  f17687c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f176880:	3508f279 */ 	ori	$t0,$t0,0xf279
/*  f176884:	02002025 */ 	or	$a0,$s0,$zero
/*  f176888:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f17688c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f176890:	3c09ba00 */ 	lui	$t1,0xba00
/*  f176894:	35290c02 */ 	ori	$t1,$t1,0xc02
/*  f176898:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17689c:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f1768a0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1768a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1768a8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1768ac:	3c0aba00 */ 	lui	$t2,0xba00
/*  f1768b0:	354a1301 */ 	ori	$t2,$t2,0x1301
/*  f1768b4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1768b8:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f1768bc:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1768c0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1768c4:	3c0bba00 */ 	lui	$t3,0xba00
/*  f1768c8:	356b0602 */ 	ori	$t3,$t3,0x602
/*  f1768cc:	240c00c0 */ 	addiu	$t4,$zero,0xc0
/*  f1768d0:	02001025 */ 	or	$v0,$s0,$zero
/*  f1768d4:	accc0004 */ 	sw	$t4,0x4($a2)
/*  f1768d8:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f1768dc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1768e0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f1768e4:	35ad0402 */ 	ori	$t5,$t5,0x402
/*  f1768e8:	240e0030 */ 	addiu	$t6,$zero,0x30
/*  f1768ec:	02001825 */ 	or	$v1,$s0,$zero
/*  f1768f0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1768f4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1768f8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1768fc:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f176900:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176904:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f176908:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f17690c:	02002025 */ 	or	$a0,$s0,$zero
/*  f176910:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176914:	3c18ba00 */ 	lui	$t8,0xba00
/*  f176918:	37181102 */ 	ori	$t8,$t8,0x1102
/*  f17691c:	02002825 */ 	or	$a1,$s0,$zero
/*  f176920:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f176924:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f176928:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17692c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f176930:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f176934:	02003025 */ 	or	$a2,$s0,$zero
/*  f176938:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f17693c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f176940:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176944:	3c08b900 */ 	lui	$t0,0xb900
/*  f176948:	35080002 */ 	ori	$t0,$t0,0x2
/*  f17694c:	02001025 */ 	or	$v0,$s0,$zero
/*  f176950:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f176954:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f176958:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17695c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f176960:	3c09b600 */ 	lui	$t1,0xb600
/*  f176964:	02001825 */ 	or	$v1,$s0,$zero
/*  f176968:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f17696c:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f176970:	3c0be800 */ 	lui	$t3,0xe800
/*  f176974:	3c1efd10 */ 	lui	$s8,0xfd10
/*  f176978:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f17697c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f176980:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176984:	37de013f */ 	ori	$s8,$s8,0x13f
/*  f176988:	02408825 */ 	or	$s1,$s2,$zero
/*  f17698c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f176990:	3c17e600 */ 	lui	$s7,0xe600
.L0f176994:
/*  f176994:	962c0000 */ 	lhu	$t4,0x0($s1)
/*  f176998:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f17699c:	1180004a */ 	beqz	$t4,.L0f176ac8
/*  f1769a0:	00146840 */ 	sll	$t5,$s4,0x1
/*  f1769a4:	0c002f02 */ 	jal	func0000bc08
/*  f1769a8:	01ae9021 */ 	addu	$s2,$t5,$t6
/*  f1769ac:	962f000c */ 	lhu	$t7,0xc($s1)
/*  f1769b0:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f1769b4:	02001825 */ 	or	$v1,$s0,$zero
/*  f1769b8:	004f0019 */ 	multu	$v0,$t7
/*  f1769bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1769c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1769c4:	ac760000 */ 	sw	$s6,0x0($v1)
/*  f1769c8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1769cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1769d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1769d4:	ac9e0000 */ 	sw	$s8,0x0($a0)
/*  f1769d8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1769dc:	02009825 */ 	or	$s3,$s0,$zero
/*  f1769e0:	0000c012 */ 	mflo	$t8
/*  f1769e4:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f1769e8:	03283021 */ 	addu	$a2,$t9,$t0
/*  f1769ec:	ac860004 */ 	sw	$a2,0x4($a0)
/*  f1769f0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1769f4:	acb70000 */ 	sw	$s7,0x0($a1)
/*  f1769f8:	3c09f300 */ 	lui	$t1,0xf300
/*  f1769fc:	ae690000 */ 	sw	$t1,0x0($s3)
/*  f176a00:	0c002f02 */ 	jal	func0000bc08
/*  f176a04:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a08:	244affff */ 	addiu	$t2,$v0,-1
/*  f176a0c:	294107ff */ 	slti	$at,$t2,0x7ff
/*  f176a10:	10200005 */ 	beqz	$at,.L0f176a28
/*  f176a14:	240507ff */ 	addiu	$a1,$zero,0x7ff
/*  f176a18:	0c002f02 */ 	jal	func0000bc08
/*  f176a1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176a20:	10000001 */ 	beqz	$zero,.L0f176a28
/*  f176a24:	2445ffff */ 	addiu	$a1,$v0,-1
.L0f176a28:
/*  f176a28:	30ab0fff */ 	andi	$t3,$a1,0xfff
/*  f176a2c:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f176a30:	3c010500 */ 	lui	$at,0x500
/*  f176a34:	01816825 */ 	or	$t5,$t4,$at
/*  f176a38:	02001025 */ 	or	$v0,$s0,$zero
/*  f176a3c:	268e0003 */ 	addiu	$t6,$s4,0x3
/*  f176a40:	ae6d0004 */ 	sw	$t5,0x4($s3)
/*  f176a44:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a48:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f176a4c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f176a50:	02001825 */ 	or	$v1,$s0,$zero
/*  f176a54:	00144880 */ 	sll	$t1,$s4,0x2
/*  f176a58:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f176a5c:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f176a60:	312a0fff */ 	andi	$t2,$t1,0xfff
/*  f176a64:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f176a68:	3c01e400 */ 	lui	$at,0xe400
/*  f176a6c:	03214025 */ 	or	$t0,$t9,$at
/*  f176a70:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f176a74:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a78:	02002025 */ 	or	$a0,$s0,$zero
/*  f176a7c:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f176a80:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f176a84:	3c0cb400 */ 	lui	$t4,0xb400
/*  f176a88:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f176a8c:	962d000e */ 	lhu	$t5,0xe($s1)
/*  f176a90:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176a94:	02003025 */ 	or	$a2,$s0,$zero
/*  f176a98:	000d7140 */ 	sll	$t6,$t5,0x5
/*  f176a9c:	25d80010 */ 	addiu	$t8,$t6,0x10
/*  f176aa0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f176aa4:	37280010 */ 	ori	$t0,$t9,0x10
/*  f176aa8:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f176aac:	3c0a1000 */ 	lui	$t2,0x1000
/*  f176ab0:	3c09b300 */ 	lui	$t1,0xb300
/*  f176ab4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f176ab8:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f176abc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176ac0:	ae32000c */ 	sw	$s2,0xc($s1)
/*  f176ac4:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f176ac8:
/*  f176ac8:	26b50014 */ 	addiu	$s5,$s5,0x14
/*  f176acc:	24010960 */ 	addiu	$at,$zero,0x960
/*  f176ad0:	16a1ffb0 */ 	bne	$s5,$at,.L0f176994
/*  f176ad4:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f176ad8:	02001025 */ 	or	$v0,$s0,$zero
/*  f176adc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176ae0:	02001825 */ 	or	$v1,$s0,$zero
/*  f176ae4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176ae8:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f176aec:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f176af0:	02002025 */ 	or	$a0,$s0,$zero
/*  f176af4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176af8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f176afc:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f176b00:	3c0be800 */ 	lui	$t3,0xe800
/*  f176b04:	02008825 */ 	or	$s1,$s0,$zero
/*  f176b08:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f176b0c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f176b10:	0c002ef1 */ 	jal	func0000bbc4
/*  f176b14:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b18:	244cffff */ 	addiu	$t4,$v0,-1
/*  f176b1c:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f176b20:	3c01ff10 */ 	lui	$at,0xff10
/*  f176b24:	01a17025 */ 	or	$t6,$t5,$at
/*  f176b28:	0c002ac7 */ 	jal	func0000ab1c
/*  f176b2c:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f176b30:	3c018000 */ 	lui	$at,0x8000
/*  f176b34:	00417821 */ 	addu	$t7,$v0,$at
/*  f176b38:	ae2f0004 */ 	sw	$t7,0x4($s1)
/*  f176b3c:	02009025 */ 	or	$s2,$s0,$zero
/*  f176b40:	3c18ed00 */ 	lui	$t8,0xed00
/*  f176b44:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f176b48:	0c002f02 */ 	jal	func0000bc08
/*  f176b4c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b50:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f176b54:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f176b58:	0c002f06 */ 	jal	func0000bc18
/*  f176b5c:	03208825 */ 	or	$s1,$t9,$zero
/*  f176b60:	44822000 */ 	mtc1	$v0,$f4
/*  f176b64:	44918000 */ 	mtc1	$s1,$f16
/*  f176b68:	3c014080 */ 	lui	$at,0x4080
/*  f176b6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f176b70:	44810000 */ 	mtc1	$at,$f0
/*  f176b74:	02001825 */ 	or	$v1,$s0,$zero
/*  f176b78:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b7c:	3c18b700 */ 	lui	$t8,0xb700
/*  f176b80:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f176b84:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f176b88:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f176b8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f176b90:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176b94:	3c08ba00 */ 	lui	$t0,0xba00
/*  f176b98:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f176b9c:	35080c02 */ 	ori	$t0,$t0,0xc02
/*  f176ba0:	02002825 */ 	or	$a1,$s0,$zero
/*  f176ba4:	3c0bba00 */ 	lui	$t3,0xba00
/*  f176ba8:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f176bac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f176bb0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f176bb4:	02003025 */ 	or	$a2,$s0,$zero
/*  f176bb8:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f176bbc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f176bc0:	44095000 */ 	mfc1	$t1,$f10
/*  f176bc4:	440c3000 */ 	mfc1	$t4,$f6
/*  f176bc8:	312a0fff */ 	andi	$t2,$t1,0xfff
/*  f176bcc:	24092000 */ 	addiu	$t1,$zero,0x2000
/*  f176bd0:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f176bd4:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f176bd8:	014e7825 */ 	or	$t7,$t2,$t6
/*  f176bdc:	ae4f0004 */ 	sw	$t7,0x4($s2)
/*  f176be0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f176be4:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f176be8:	ac890004 */ 	sw	$t1,0x4($a0)
/*  f176bec:	ac880000 */ 	sw	$t0,0x0($a0)
/*  f176bf0:	3c0c0008 */ 	lui	$t4,0x8
/*  f176bf4:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f176bf8:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f176bfc:	3c0dba00 */ 	lui	$t5,0xba00
/*  f176c00:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f176c04:	240a0040 */ 	addiu	$t2,$zero,0x40
/*  f176c08:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f176c0c:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f176c10:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f176c14:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f176c18:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f176c1c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f176c20:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f176c24:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f176c28:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f176c2c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f176c30:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f176c34:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f176c38:	03e00008 */ 	jr	$ra
/*  f176c3c:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f176c40
/*  f176c40:	3c0e800a */ 	lui	$t6,0x800a
/*  f176c44:	8dcea2d8 */ 	lw	$t6,-0x5d28($t6)
/*  f176c48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f176c4c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f176c50:	11c00005 */ 	beqz	$t6,.L0f176c68
/*  f176c54:	3c0f8008 */ 	lui	$t7,0x8008
/*  f176c58:	0fc63130 */ 	jal	func0f18c4c0
/*  f176c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176c60:	1000001a */ 	beqz	$zero,.L0f176ccc
/*  f176c64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f176c68:
/*  f176c68:	85ef4500 */ 	lh	$t7,0x4500($t7)
/*  f176c6c:	3c188008 */ 	lui	$t8,0x8008
/*  f176c70:	27024500 */ 	addiu	$v0,$t8,0x4500
/*  f176c74:	11e00012 */ 	beqz	$t7,.L0f176cc0
/*  f176c78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176c7c:	84430000 */ 	lh	$v1,0x0($v0)
.L0f176c80:
/*  f176c80:	5483000c */ 	bnel	$a0,$v1,.L0f176cb4
/*  f176c84:	84430008 */ 	lh	$v1,0x8($v0)
/*  f176c88:	84430002 */ 	lh	$v1,0x2($v0)
/*  f176c8c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f176c90:	14610005 */ 	bne	$v1,$at,.L0f176ca8
/*  f176c94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176c98:	0fc63130 */ 	jal	func0f18c4c0
/*  f176c9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176ca0:	1000000a */ 	beqz	$zero,.L0f176ccc
/*  f176ca4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f176ca8:
/*  f176ca8:	10000007 */ 	beqz	$zero,.L0f176cc8
/*  f176cac:	00601025 */ 	or	$v0,$v1,$zero
/*  f176cb0:	84430008 */ 	lh	$v1,0x8($v0)
.L0f176cb4:
/*  f176cb4:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f176cb8:	1460fff1 */ 	bnez	$v1,.L0f176c80
/*  f176cbc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f176cc0:
/*  f176cc0:	0fc63130 */ 	jal	func0f18c4c0
/*  f176cc4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f176cc8:
/*  f176cc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f176ccc:
/*  f176ccc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f176cd0:	03e00008 */ 	jr	$ra
/*  f176cd4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f176cd8
/*  f176cd8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f176cdc:	85ce4500 */ 	lh	$t6,0x4500($t6)
/*  f176ce0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f176ce4:	25e34500 */ 	addiu	$v1,$t7,0x4500
/*  f176ce8:	51c0000b */ 	beqzl	$t6,.L0f176d18
/*  f176cec:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f176cf0:	84620000 */ 	lh	$v0,0x0($v1)
.L0f176cf4:
/*  f176cf4:	54820004 */ 	bnel	$a0,$v0,.L0f176d08
/*  f176cf8:	84620008 */ 	lh	$v0,0x8($v1)
/*  f176cfc:	03e00008 */ 	jr	$ra
/*  f176d00:	84620004 */ 	lh	$v0,0x4($v1)
/*  f176d04:	84620008 */ 	lh	$v0,0x8($v1)
.L0f176d08:
/*  f176d08:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f176d0c:	1440fff9 */ 	bnez	$v0,.L0f176cf4
/*  f176d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176d14:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f176d18:
/*  f176d18:	03e00008 */ 	jr	$ra
/*  f176d1c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f176d20
/*  f176d20:	3c0e8008 */ 	lui	$t6,0x8008
/*  f176d24:	85ce4500 */ 	lh	$t6,0x4500($t6)
/*  f176d28:	3c0f8008 */ 	lui	$t7,0x8008
/*  f176d2c:	25e34500 */ 	addiu	$v1,$t7,0x4500
/*  f176d30:	51c0000b */ 	beqzl	$t6,.L0f176d60
/*  f176d34:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f176d38:	84620000 */ 	lh	$v0,0x0($v1)
.L0f176d3c:
/*  f176d3c:	54820004 */ 	bnel	$a0,$v0,.L0f176d50
/*  f176d40:	84620008 */ 	lh	$v0,0x8($v1)
/*  f176d44:	03e00008 */ 	jr	$ra
/*  f176d48:	84620006 */ 	lh	$v0,0x6($v1)
/*  f176d4c:	84620008 */ 	lh	$v0,0x8($v1)
.L0f176d50:
/*  f176d50:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f176d54:	1440fff9 */ 	bnez	$v0,.L0f176d3c
/*  f176d58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176d5c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f176d60:
/*  f176d60:	03e00008 */ 	jr	$ra
/*  f176d64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176d68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176d6c:	00000000 */ 	sll	$zero,$zero,0x0
);
