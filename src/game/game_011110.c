#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_011110.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_097a50.h"
#include "game/game_0b28d0.h"
#include "game/game_0c79f0.h"
#include "game/cheats.h"
#include "game/game_111600.h"
#include "game/pad.h"
#include "game/game_157db0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"

const u32 var7f1a8240[] = {0x7f011a44};
const u32 var7f1a8244[] = {0x7f011a90};
const u32 var7f1a8248[] = {0x7f011b38};
const u32 var7f1a824c[] = {0x7f011b68};
const u32 var7f1a8250[] = {0x7f011b70};
const u32 var7f1a8254[] = {0x7f011b78};
const u32 var7f1a8258[] = {0x7f011b8c};
const u32 var7f1a825c[] = {0x7f011b94};
const u32 var7f1a8260[] = {0x7f011c30};
const u32 var7f1a8264[] = {0x7f011a80};
const u32 var7f1a8268[] = {0x7f011a80};
const u32 var7f1a826c[] = {0x7f011a88};
const u32 var7f1a8270[] = {0x40c907a9};
const u32 var7f1a8274[] = {0x40c907a9};
const u32 var7f1a8278[] = {0x40c907a9};
const u32 var7f1a827c[] = {0x40c907a9};

void func0f011110(void)
{
	var800705a4 = 0;
	var800705a0 = 0;
}

void func0f011124(s32 value)
{
	var800705a8 = value;
}

GLOBAL_ASM(
glabel func0f011130
/*  f011130:	3c01800a */ 	lui	$at,0x800a
/*  f011134:	ac24dd08 */ 	sw	$a0,-0x22f8($at)
/*  f011138:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f01113c:	3c01800a */ 	lui	$at,0x800a
/*  f011140:	254a0af0 */ 	addiu	$t2,$t2,%lo(g_Is4Mb)
/*  f011144:	ac25dd0c */ 	sw	$a1,-0x22f4($at)
/*  f011148:	91480000 */ 	lbu	$t0,0x0($t2)
/*  f01114c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f011150:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f011154:	15280003 */ 	bne	$t1,$t0,.L0f011164
/*  f011158:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01115c:	10000002 */ 	beqz	$zero,.L0f011168
/*  f011160:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f011164:
/*  f011164:	2402003c */ 	addiu	$v0,$zero,0x3c
.L0f011168:
/*  f011168:	00827021 */ 	addu	$t6,$a0,$v0
/*  f01116c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f011170:	25f80014 */ 	addiu	$t8,$t7,0x14
/*  f011174:	3c018007 */ 	lui	$at,0x8007
/*  f011178:	ac3805a0 */ 	sw	$t8,0x5a0($at)
/*  f01117c:	3c018007 */ 	lui	$at,0x8007
/*  f011180:	24b90014 */ 	addiu	$t9,$a1,0x14
/*  f011184:	15280003 */ 	bne	$t1,$t0,.L0f011194
/*  f011188:	ac3905a4 */ 	sw	$t9,0x5a4($at)
/*  f01118c:	10000002 */ 	beqz	$zero,.L0f011198
/*  f011190:	24030018 */ 	addiu	$v1,$zero,0x18
.L0f011194:
/*  f011194:	24030019 */ 	addiu	$v1,$zero,0x19
.L0f011198:
/*  f011198:	15280003 */ 	bne	$t1,$t0,.L0f0111a8
/*  f01119c:	3c07800a */ 	lui	$a3,%hi(var8009dd10)
/*  f0111a0:	10000002 */ 	beqz	$zero,.L0f0111ac
/*  f0111a4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0111a8:
/*  f0111a8:	24020023 */ 	addiu	$v0,$zero,0x23
.L0f0111ac:
/*  f0111ac:	15280003 */ 	bne	$t1,$t0,.L0f0111bc
/*  f0111b0:	24e7dd10 */ 	addiu	$a3,$a3,%lo(var8009dd10)
/*  f0111b4:	10000002 */ 	beqz	$zero,.L0f0111c0
/*  f0111b8:	00003025 */ 	or	$a2,$zero,$zero
.L0f0111bc:
/*  f0111bc:	24060014 */ 	addiu	$a2,$zero,0x14
.L0f0111c0:
/*  f0111c0:	00c27021 */ 	addu	$t6,$a2,$v0
/*  f0111c4:	01c35821 */ 	addu	$t3,$t6,$v1
/*  f0111c8:	000b78c0 */ 	sll	$t7,$t3,0x3
/*  f0111cc:	15280003 */ 	bne	$t1,$t0,.L0f0111dc
/*  f0111d0:	01e05825 */ 	or	$t3,$t7,$zero
/*  f0111d4:	10000002 */ 	beqz	$zero,.L0f0111e0
/*  f0111d8:	00003025 */ 	or	$a2,$zero,$zero
.L0f0111dc:
/*  f0111dc:	24060023 */ 	addiu	$a2,$zero,0x23
.L0f0111e0:
/*  f0111e0:	15280003 */ 	bne	$t1,$t0,.L0f0111f0
/*  f0111e4:	00061900 */ 	sll	$v1,$a2,0x4
/*  f0111e8:	10000002 */ 	beqz	$zero,.L0f0111f4
/*  f0111ec:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f0111f0:
/*  f0111f0:	24060019 */ 	addiu	$a2,$zero,0x19
.L0f0111f4:
/*  f0111f4:	00061080 */ 	sll	$v0,$a2,0x2
/*  f0111f8:	00461023 */ 	subu	$v0,$v0,$a2
/*  f0111fc:	00021080 */ 	sll	$v0,$v0,0x2
/*  f011200:	00461021 */ 	addu	$v0,$v0,$a2
/*  f011204:	15280003 */ 	bne	$t1,$t0,.L0f011214
/*  f011208:	00021100 */ 	sll	$v0,$v0,0x4
/*  f01120c:	10000001 */ 	beqz	$zero,.L0f011214
/*  f011210:	00000000 */ 	sll	$zero,$zero,0x0
.L0f011214:
/*  f011214:	3c0d8007 */ 	lui	$t5,%hi(var800705a4)
/*  f011218:	25ad05a4 */ 	addiu	$t5,$t5,%lo(var800705a4)
/*  f01121c:	8da80000 */ 	lw	$t0,0x0($t5)
/*  f011220:	3c0c8007 */ 	lui	$t4,%hi(var800705a0)
/*  f011224:	258c05a0 */ 	addiu	$t4,$t4,%lo(var800705a0)
/*  f011228:	8d9f0000 */ 	lw	$ra,0x0($t4)
/*  f01122c:	000878c0 */ 	sll	$t7,$t0,0x3
/*  f011230:	01e87821 */ 	addu	$t7,$t7,$t0
/*  f011234:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f011238:	001fc0c0 */ 	sll	$t8,$ra,0x3
/*  f01123c:	01e87823 */ 	subu	$t7,$t7,$t0
/*  f011240:	031fc021 */ 	addu	$t8,$t8,$ra
/*  f011244:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f011248:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f01124c:	271f000f */ 	addiu	$ra,$t8,0xf
/*  f011250:	25e8000f */ 	addiu	$t0,$t7,0xf
/*  f011254:	37f9000f */ 	ori	$t9,$ra,0xf
/*  f011258:	3518000f */ 	ori	$t8,$t0,0xf
/*  f01125c:	01637021 */ 	addu	$t6,$t3,$v1
/*  f011260:	3b3f000f */ 	xori	$ra,$t9,0xf
/*  f011264:	3b08000f */ 	xori	$t0,$t8,0xf
/*  f011268:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f01126c:	01ffc021 */ 	addu	$t8,$t7,$ra
/*  f011270:	03082021 */ 	addu	$a0,$t8,$t0
/*  f011274:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f011278:	3499000f */ 	ori	$t9,$a0,0xf
/*  f01127c:	afbf0020 */ 	sw	$ra,0x20($sp)
/*  f011280:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f011284:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f011288:	ace00008 */ 	sw	$zero,0x8($a3)
/*  f01128c:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f011290:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f011294:	0c0048f2 */ 	jal	func000123c8
/*  f011298:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01129c:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0112a0:	254a0af0 */ 	addiu	$t2,$t2,%lo(g_Is4Mb)
/*  f0112a4:	91480000 */ 	lbu	$t0,0x0($t2)
/*  f0112a8:	3c07800a */ 	lui	$a3,%hi(var8009dd10)
/*  f0112ac:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0112b0:	3c0c8007 */ 	lui	$t4,%hi(var800705a0)
/*  f0112b4:	3c0d8007 */ 	lui	$t5,%hi(var800705a4)
/*  f0112b8:	25ad05a4 */ 	addiu	$t5,$t5,%lo(var800705a4)
/*  f0112bc:	258c05a0 */ 	addiu	$t4,$t4,%lo(var800705a0)
/*  f0112c0:	24e7dd10 */ 	addiu	$a3,$a3,%lo(var8009dd10)
/*  f0112c4:	8fbf0020 */ 	lw	$ra,0x20($sp)
/*  f0112c8:	15280003 */ 	bne	$t1,$t0,.L0f0112d8
/*  f0112cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0112d0:	10000002 */ 	beqz	$zero,.L0f0112dc
/*  f0112d4:	00003025 */ 	or	$a2,$zero,$zero
.L0f0112d8:
/*  f0112d8:	24060023 */ 	addiu	$a2,$zero,0x23
.L0f0112dc:
/*  f0112dc:	10c00009 */ 	beqz	$a2,.L0f011304
/*  f0112e0:	3c05800a */ 	lui	$a1,%hi(var8009dd00)
/*  f0112e4:	3c01800a */ 	lui	$at,0x800a
/*  f0112e8:	15280003 */ 	bne	$t1,$t0,.L0f0112f8
/*  f0112ec:	ac22dd10 */ 	sw	$v0,-0x22f0($at)
/*  f0112f0:	10000002 */ 	beqz	$zero,.L0f0112fc
/*  f0112f4:	00003025 */ 	or	$a2,$zero,$zero
.L0f0112f8:
/*  f0112f8:	24060023 */ 	addiu	$a2,$zero,0x23
.L0f0112fc:
/*  f0112fc:	000678c0 */ 	sll	$t7,$a2,0x3
/*  f011300:	004f2021 */ 	addu	$a0,$v0,$t7
.L0f011304:
/*  f011304:	15280003 */ 	bne	$t1,$t0,.L0f011314
/*  f011308:	24a5dd00 */ 	addiu	$a1,$a1,%lo(var8009dd00)
/*  f01130c:	10000002 */ 	beqz	$zero,.L0f011318
/*  f011310:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f011314:
/*  f011314:	24060019 */ 	addiu	$a2,$zero,0x19
.L0f011318:
/*  f011318:	10c00008 */ 	beqz	$a2,.L0f01133c
/*  f01131c:	3c0b800a */ 	lui	$t3,%hi(var8009dd04)
/*  f011320:	15280003 */ 	bne	$t1,$t0,.L0f011330
/*  f011324:	ace40004 */ 	sw	$a0,0x4($a3)
/*  f011328:	10000002 */ 	beqz	$zero,.L0f011334
/*  f01132c:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f011330:
/*  f011330:	24060019 */ 	addiu	$a2,$zero,0x19
.L0f011334:
/*  f011334:	0006c0c0 */ 	sll	$t8,$a2,0x3
/*  f011338:	00982021 */ 	addu	$a0,$a0,$t8
.L0f01133c:
/*  f01133c:	15280003 */ 	bne	$t1,$t0,.L0f01134c
/*  f011340:	256bdd04 */ 	addiu	$t3,$t3,%lo(var8009dd04)
/*  f011344:	10000002 */ 	beqz	$zero,.L0f011350
/*  f011348:	00003025 */ 	or	$a2,$zero,$zero
.L0f01134c:
/*  f01134c:	24060014 */ 	addiu	$a2,$zero,0x14
.L0f011350:
/*  f011350:	10c00008 */ 	beqz	$a2,.L0f011374
/*  f011354:	00001825 */ 	or	$v1,$zero,$zero
/*  f011358:	15280003 */ 	bne	$t1,$t0,.L0f011368
/*  f01135c:	ace40008 */ 	sw	$a0,0x8($a3)
/*  f011360:	10000002 */ 	beqz	$zero,.L0f01136c
/*  f011364:	00003025 */ 	or	$a2,$zero,$zero
.L0f011368:
/*  f011368:	24060014 */ 	addiu	$a2,$zero,0x14
.L0f01136c:
/*  f01136c:	0006c8c0 */ 	sll	$t9,$a2,0x3
/*  f011370:	00992021 */ 	addu	$a0,$a0,$t9
.L0f011374:
/*  f011374:	aca40000 */ 	sw	$a0,0x0($a1)
/*  f011378:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f01137c:	009f2021 */ 	addu	$a0,$a0,$ra
/*  f011380:	ad640000 */ 	sw	$a0,0x0($t3)
/*  f011384:	15280003 */ 	bne	$t1,$t0,.L0f011394
/*  f011388:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f01138c:	10000002 */ 	beqz	$zero,.L0f011398
/*  f011390:	00003025 */ 	or	$a2,$zero,$zero
.L0f011394:
/*  f011394:	24060023 */ 	addiu	$a2,$zero,0x23
.L0f011398:
/*  f011398:	18c00014 */ 	blez	$a2,.L0f0113ec
/*  f01139c:	000310c0 */ 	sll	$v0,$v1,0x3
/*  f0113a0:	8cef0000 */ 	lw	$t7,0x0($a3)
.L0f0113a4:
/*  f0113a4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0113a8:	24060023 */ 	addiu	$a2,$zero,0x23
/*  f0113ac:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f0113b0:	af040004 */ 	sw	$a0,0x4($t8)
/*  f0113b4:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0113b8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0113bc:	03227021 */ 	addu	$t6,$t9,$v0
/*  f0113c0:	adc00000 */ 	sw	$zero,0x0($t6)
/*  f0113c4:	91480000 */ 	lbu	$t0,0x0($t2)
/*  f0113c8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0113cc:	15280003 */ 	bne	$t1,$t0,.L0f0113dc
/*  f0113d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0113d4:	10000001 */ 	beqz	$zero,.L0f0113dc
/*  f0113d8:	00003025 */ 	or	$a2,$zero,$zero
.L0f0113dc:
/*  f0113dc:	0066082a */ 	slt	$at,$v1,$a2
/*  f0113e0:	5420fff0 */ 	bnezl	$at,.L0f0113a4
/*  f0113e4:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0113e8:	00001825 */ 	or	$v1,$zero,$zero
.L0f0113ec:
/*  f0113ec:	15280003 */ 	bne	$t1,$t0,.L0f0113fc
/*  f0113f0:	24060019 */ 	addiu	$a2,$zero,0x19
/*  f0113f4:	10000001 */ 	beqz	$zero,.L0f0113fc
/*  f0113f8:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f0113fc:
/*  f0113fc:	18c00014 */ 	blez	$a2,.L0f011450
/*  f011400:	000310c0 */ 	sll	$v0,$v1,0x3
/*  f011404:	8cef0004 */ 	lw	$t7,0x4($a3)
.L0f011408:
/*  f011408:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01140c:	24060019 */ 	addiu	$a2,$zero,0x19
/*  f011410:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f011414:	af040004 */ 	sw	$a0,0x4($t8)
/*  f011418:	8cf90004 */ 	lw	$t9,0x4($a3)
/*  f01141c:	248400d0 */ 	addiu	$a0,$a0,0xd0
/*  f011420:	03227021 */ 	addu	$t6,$t9,$v0
/*  f011424:	adc00000 */ 	sw	$zero,0x0($t6)
/*  f011428:	91480000 */ 	lbu	$t0,0x0($t2)
/*  f01142c:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f011430:	15280003 */ 	bne	$t1,$t0,.L0f011440
/*  f011434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011438:	10000001 */ 	beqz	$zero,.L0f011440
/*  f01143c:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f011440:
/*  f011440:	0066082a */ 	slt	$at,$v1,$a2
/*  f011444:	5420fff0 */ 	bnezl	$at,.L0f011408
/*  f011448:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f01144c:	00001825 */ 	or	$v1,$zero,$zero
.L0f011450:
/*  f011450:	15280003 */ 	bne	$t1,$t0,.L0f011460
/*  f011454:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f011458:	10000001 */ 	beqz	$zero,.L0f011460
/*  f01145c:	00003025 */ 	or	$a2,$zero,$zero
.L0f011460:
/*  f011460:	18c00013 */ 	blez	$a2,.L0f0114b0
/*  f011464:	000310c0 */ 	sll	$v0,$v1,0x3
/*  f011468:	8cef0008 */ 	lw	$t7,0x8($a3)
.L0f01146c:
/*  f01146c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f011470:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f011474:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f011478:	af000004 */ 	sw	$zero,0x4($t8)
/*  f01147c:	8cf90008 */ 	lw	$t9,0x8($a3)
/*  f011480:	03227021 */ 	addu	$t6,$t9,$v0
/*  f011484:	adc00000 */ 	sw	$zero,0x0($t6)
/*  f011488:	914f0000 */ 	lbu	$t7,0x0($t2)
/*  f01148c:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f011490:	152f0003 */ 	bne	$t1,$t7,.L0f0114a0
/*  f011494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011498:	10000001 */ 	beqz	$zero,.L0f0114a0
/*  f01149c:	00003025 */ 	or	$a2,$zero,$zero
.L0f0114a0:
/*  f0114a0:	0066082a */ 	slt	$at,$v1,$a2
/*  f0114a4:	5420fff1 */ 	bnezl	$at,.L0f01146c
/*  f0114a8:	8cef0008 */ 	lw	$t7,0x8($a3)
/*  f0114ac:	00001825 */ 	or	$v1,$zero,$zero
.L0f0114b0:
/*  f0114b0:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0114b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0114b8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0114bc:	5b00000f */ 	blezl	$t8,.L0f0114fc
/*  f0114c0:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f0114c4:	8cb90000 */ 	lw	$t9,0x0($a1)
.L0f0114c8:
/*  f0114c8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0114cc:	03227021 */ 	addu	$t6,$t9,$v0
/*  f0114d0:	adc00008 */ 	sw	$zero,0x8($t6)
/*  f0114d4:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f0114d8:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f0114dc:	af000010 */ 	sw	$zero,0x10($t8)
/*  f0114e0:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0114e4:	24420024 */ 	addiu	$v0,$v0,0x24
/*  f0114e8:	0079082a */ 	slt	$at,$v1,$t9
/*  f0114ec:	5420fff6 */ 	bnezl	$at,.L0f0114c8
/*  f0114f0:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f0114f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0114f8:	8dae0000 */ 	lw	$t6,0x0($t5)
.L0f0114fc:
/*  f0114fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f011500:	19c0000a */ 	blez	$t6,.L0f01152c
/*  f011504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011508:	8d6f0000 */ 	lw	$t7,0x0($t3)
.L0f01150c:
/*  f01150c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f011510:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f011514:	a7040000 */ 	sh	$a0,0x0($t8)
/*  f011518:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f01151c:	2442008c */ 	addiu	$v0,$v0,0x8c
/*  f011520:	0079082a */ 	slt	$at,$v1,$t9
/*  f011524:	5420fff9 */ 	bnezl	$at,.L0f01150c
/*  f011528:	8d6f0000 */ 	lw	$t7,0x0($t3)
.L0f01152c:
/*  f01152c:	3c018007 */ 	lui	$at,0x8007
/*  f011530:	ac2005ac */ 	sw	$zero,0x5ac($at)
/*  f011534:	3c018007 */ 	lui	$at,0x8007
/*  f011538:	ac2005b0 */ 	sw	$zero,0x5b0($at)
/*  f01153c:	3c018007 */ 	lui	$at,0x8007
/*  f011540:	ac2005b4 */ 	sw	$zero,0x5b4($at)
/*  f011544:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f011548:	3c018007 */ 	lui	$at,0x8007
/*  f01154c:	ac2005b8 */ 	sw	$zero,0x5b8($at)
/*  f011550:	3c018007 */ 	lui	$at,0x8007
/*  f011554:	ac2005bc */ 	sw	$zero,0x5bc($at)
/*  f011558:	03e00008 */ 	jr	$ra
/*  f01155c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f011560
/*  f011560:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f011564:	00047080 */ 	sll	$t6,$a0,0x2
/*  f011568:	3c028007 */ 	lui	$v0,0x8007
/*  f01156c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f011570:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f011574:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f011578:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f01157c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f011580:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f011584:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f011588:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f01158c:	00008025 */ 	or	$s0,$zero,$zero
/*  f011590:	8c52ff18 */ 	lw	$s2,-0xe8($v0)
/*  f011594:	00008825 */ 	or	$s1,$zero,$zero
/*  f011598:	24130201 */ 	addiu	$s3,$zero,0x201
/*  f01159c:	24140008 */ 	addiu	$s4,$zero,0x8
/*  f0115a0:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f0115a4:
/*  f0115a4:	8e430014 */ 	lw	$v1,0x14($s2)
/*  f0115a8:	50600015 */ 	beqzl	$v1,.L0f011600
/*  f0115ac:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0115b0:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f0115b4:	00601025 */ 	or	$v0,$v1,$zero
/*  f0115b8:	16640008 */ 	bne	$s3,$a0,.L0f0115dc
/*  f0115bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0115c0:	8c640040 */ 	lw	$a0,0x40($v1)
/*  f0115c4:	0482000e */ 	bltzl	$a0,.L0f011600
/*  f0115c8:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0115cc:	0fc2486d */ 	jal	func0f0921b4
/*  f0115d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0115d4:	10000009 */ 	beqz	$zero,.L0f0115fc
/*  f0115d8:	02028025 */ 	or	$s0,$s0,$v0
.L0f0115dc:
/*  f0115dc:	56a40008 */ 	bnel	$s5,$a0,.L0f011600
/*  f0115e0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0115e4:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0115e8:	04820005 */ 	bltzl	$a0,.L0f011600
/*  f0115ec:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0115f0:	0fc2486d */ 	jal	func0f0921b4
/*  f0115f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0115f8:	02028025 */ 	or	$s0,$s0,$v0
.L0f0115fc:
/*  f0115fc:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f011600:
/*  f011600:	1634ffe8 */ 	bne	$s1,$s4,.L0f0115a4
/*  f011604:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f011608:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f01160c:	02001025 */ 	or	$v0,$s0,$zero
/*  f011610:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f011614:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f011618:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f01161c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f011620:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f011624:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f011628:	03e00008 */ 	jr	$ra
/*  f01162c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f011630
/*  f011630:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f011634:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f011638:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f01163c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f011640:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f011644:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f011648:	3c028006 */ 	lui	$v0,0x8006
/*  f01164c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f011650:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f011654:	55e000a3 */ 	bnezl	$t7,.L0f0118e4
/*  f011658:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f01165c:	904223a0 */ 	lbu	$v0,0x23a0($v0)
/*  f011660:	3c018006 */ 	lui	$at,0x8006
/*  f011664:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f011668:	00402025 */ 	or	$a0,$v0,$zero
/*  f01166c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f011670:	305800ff */ 	andi	$t8,$v0,0xff
/*  f011674:	03001025 */ 	or	$v0,$t8,$zero
/*  f011678:	0fc456ac */ 	jal	padUnpack
/*  f01167c:	a03823a0 */ 	sb	$t8,0x23a0($at)
/*  f011680:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f011684:	0fc0b6eb */ 	jal	func0f02dbac
/*  f011688:	87a5007a */ 	lh	$a1,0x7a($sp)
/*  f01168c:	10400094 */ 	beqz	$v0,.L0f0118e0
/*  f011690:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f011694:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f011698:	0c0048f2 */ 	jal	func000123c8
/*  f01169c:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f0116a0:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0116a4:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0116a8:	af220480 */ 	sw	$v0,0x480($t9)
/*  f0116ac:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0116b0:	8d050480 */ 	lw	$a1,0x480($t0)
/*  f0116b4:	50a0008b */ 	beqzl	$a1,.L0f0118e4
/*  f0116b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0116bc:	aca60000 */ 	sw	$a2,0x0($a1)
/*  f0116c0:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0116c4:	44800000 */ 	mtc1	$zero,$f0
/*  f0116c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0116cc:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0116d0:	44811000 */ 	mtc1	$at,$f2
/*  f0116d4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0116d8:	e5400004 */ 	swc1	$f0,0x4($t2)
/*  f0116dc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0116e0:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0116e4:	e5800008 */ 	swc1	$f0,0x8($t4)
/*  f0116e8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0116ec:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f0116f0:	e5c2000c */ 	swc1	$f2,0xc($t6)
/*  f0116f4:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0116f8:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0116fc:	e7000010 */ 	swc1	$f0,0x10($t8)
/*  f011700:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f011704:	8f280480 */ 	lw	$t0,0x480($t9)
/*  f011708:	e5020014 */ 	swc1	$f2,0x14($t0)
/*  f01170c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f011710:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f011714:	e5400018 */ 	swc1	$f0,0x18($t2)
/*  f011718:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f01171c:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f011720:	e580001c */ 	swc1	$f0,0x1c($t4)
/*  f011724:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f011728:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f01172c:	e5c20020 */ 	swc1	$f2,0x20($t6)
/*  f011730:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f011734:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f011738:	e7000024 */ 	swc1	$f0,0x24($t8)
/*  f01173c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f011740:	8f280480 */ 	lw	$t0,0x480($t9)
/*  f011744:	e5000028 */ 	swc1	$f0,0x28($t0)
/*  f011748:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f01174c:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f011750:	e542002c */ 	swc1	$f2,0x2c($t2)
/*  f011754:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f011758:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f01175c:	e5800030 */ 	swc1	$f0,0x30($t4)
/*  f011760:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f011764:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f011768:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f01176c:	a1c70034 */ 	sb	$a3,0x34($t6)
/*  f011770:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f011774:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f011778:	a3000035 */ 	sb	$zero,0x35($t8)
/*  f01177c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f011780:	8f280480 */ 	lw	$t0,0x480($t9)
/*  f011784:	a1000037 */ 	sb	$zero,0x37($t0)
/*  f011788:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f01178c:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f011790:	a1400038 */ 	sb	$zero,0x38($t2)
/*  f011794:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f011798:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f01179c:	a1800039 */ 	sb	$zero,0x39($t4)
/*  f0117a0:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0117a4:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0117a8:	a5ed003a */ 	sh	$t5,0x3a($t7)
/*  f0117ac:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0117b0:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0117b4:	a320003c */ 	sb	$zero,0x3c($t9)
/*  f0117b8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0117bc:	8d090480 */ 	lw	$t1,0x480($t0)
/*  f0117c0:	a127003d */ 	sb	$a3,0x3d($t1)
/*  f0117c4:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0117c8:	8d4b0480 */ 	lw	$t3,0x480($t2)
/*  f0117cc:	e5600040 */ 	swc1	$f0,0x40($t3)
/*  f0117d0:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0117d4:	8d8e0480 */ 	lw	$t6,0x480($t4)
/*  f0117d8:	e5c00044 */ 	swc1	$f0,0x44($t6)
/*  f0117dc:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0117e0:	8daf0480 */ 	lw	$t7,0x480($t5)
/*  f0117e4:	e5e00048 */ 	swc1	$f0,0x48($t7)
/*  f0117e8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0117ec:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0117f0:	e7200058 */ 	swc1	$f0,0x58($t9)
/*  f0117f4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0117f8:	8d090480 */ 	lw	$t1,0x480($t0)
/*  f0117fc:	e520005c */ 	swc1	$f0,0x5c($t1)
/*  f011800:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f011804:	8d4b0480 */ 	lw	$t3,0x480($t2)
/*  f011808:	e5600060 */ 	swc1	$f0,0x60($t3)
/*  f01180c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f011810:	8d8e0480 */ 	lw	$t6,0x480($t4)
/*  f011814:	e5c00064 */ 	swc1	$f0,0x64($t6)
/*  f011818:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f01181c:	8daf0480 */ 	lw	$t7,0x480($t5)
/*  f011820:	a1e00069 */ 	sb	$zero,0x69($t7)
/*  f011824:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f011828:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f01182c:	a320006a */ 	sb	$zero,0x6a($t9)
/*  f011830:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f011834:	8d090480 */ 	lw	$t1,0x480($t0)
/*  f011838:	a120006b */ 	sb	$zero,0x6b($t1)
/*  f01183c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f011840:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f011844:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f011848:	8d630004 */ 	lw	$v1,0x4($t3)
/*  f01184c:	906c0125 */ 	lbu	$t4,0x125($v1)
/*  f011850:	a04c0125 */ 	sb	$t4,0x125($v0)
/*  f011854:	0fc59585 */ 	jal	stageGetIndex
/*  f011858:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f01185c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f011860:	1441000d */ 	bne	$v0,$at,.L0f011898
/*  f011864:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011868:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f01186c:	3c028007 */ 	lui	$v0,%hi(g_Weapons)
/*  f011870:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f011874:	8daf0480 */ 	lw	$t7,0x480($t5)
/*  f011878:	2442ff18 */ 	addiu	$v0,$v0,%lo(g_Weapons)
/*  f01187c:	24034c3d */ 	addiu	$v1,$zero,0x4c3d
/*  f011880:	a1ee006b */ 	sb	$t6,0x6b($t7)
/*  f011884:	8c5800b8 */ 	lw	$t8,0xb8($v0)
/*  f011888:	a7030046 */ 	sh	$v1,0x46($t8)
/*  f01188c:	8c5900b8 */ 	lw	$t9,0xb8($v0)
/*  f011890:	10000013 */ 	beqz	$zero,.L0f0118e0
/*  f011894:	a7230044 */ 	sh	$v1,0x44($t9)
.L0f011898:
/*  f011898:	0fc59585 */ 	jal	stageGetIndex
/*  f01189c:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f0118a0:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0118a4:	50410007 */ 	beql	$v0,$at,.L0f0118c4
/*  f0118a8:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0118ac:	0fc59585 */ 	jal	stageGetIndex
/*  f0118b0:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f0118b4:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0118b8:	54410007 */ 	bnel	$v0,$at,.L0f0118d8
/*  f0118bc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0118c0:	8e090284 */ 	lw	$t1,0x284($s0)
.L0f0118c4:
/*  f0118c4:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0118c8:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0118cc:	10000004 */ 	beqz	$zero,.L0f0118e0
/*  f0118d0:	a148006b */ 	sb	$t0,0x6b($t2)
/*  f0118d4:	8e0b0284 */ 	lw	$t3,0x284($s0)
.L0f0118d8:
/*  f0118d8:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0118dc:	a180006b */ 	sb	$zero,0x6b($t4)
.L0f0118e0:
/*  f0118e0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0118e4:
/*  f0118e4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0118e8:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f0118ec:	03e00008 */ 	jr	$ra
/*  f0118f0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0118f4
/*  f0118f4:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0118f8:	3c0f8006 */ 	lui	$t7,%hi(var800623a4)
/*  f0118fc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f011900:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f011904:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f011908:	25ef23a4 */ 	addiu	$t7,$t7,%lo(var800623a4)
/*  f01190c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f011910:	27ae009c */ 	addiu	$t6,$sp,0x9c
/*  f011914:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f011918:	adc10000 */ 	sw	$at,0x0($t6)
/*  f01191c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f011920:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f011924:	44802000 */ 	mtc1	$zero,$f4
/*  f011928:	adc10008 */ 	sw	$at,0x8($t6)
/*  f01192c:	3c10800a */ 	lui	$s0,%hi(var800a000c)
/*  f011930:	afa00080 */ 	sw	$zero,0x80($sp)
/*  f011934:	8e10d03c */ 	lw	$s0,-0x2fc4($s0)
/*  f011938:	a3a0007b */ 	sb	$zero,0x7b($sp)
/*  f01193c:	0fc2f0fc */ 	jal	func0f0bc3f0
/*  f011940:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f011944:	0fc63956 */ 	jal	func0f18e558
/*  f011948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01194c:	3c018007 */ 	lui	$at,0x8007
/*  f011950:	ac200764 */ 	sw	$zero,0x764($at)
/*  f011954:	3c01800a */ 	lui	$at,0x800a
/*  f011958:	ac20de20 */ 	sw	$zero,-0x21e0($at)
/*  f01195c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f011960:	3c018007 */ 	lui	$at,0x8007
/*  f011964:	ac23072c */ 	sw	$v1,0x72c($at)
/*  f011968:	3c018007 */ 	lui	$at,0x8007
/*  f01196c:	ac200738 */ 	sw	$zero,0x738($at)
/*  f011970:	3c018007 */ 	lui	$at,0x8007
/*  f011974:	ac20073c */ 	sw	$zero,0x73c($at)
/*  f011978:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f01197c:	3c018007 */ 	lui	$at,0x8007
/*  f011980:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f011984:	ac200740 */ 	sw	$zero,0x740($at)
/*  f011988:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f01198c:	3c01800a */ 	lui	$at,0x800a
/*  f011990:	3c028007 */ 	lui	$v0,%hi(g_PlayersWithControl)
/*  f011994:	ad401bf0 */ 	sw	$zero,0x1bf0($t2)
/*  f011998:	ac20de68 */ 	sw	$zero,-0x2198($at)
/*  f01199c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f0119a0:	24420750 */ 	addiu	$v0,$v0,%lo(g_PlayersWithControl)
/*  f0119a4:	3c018007 */ 	lui	$at,0x8007
/*  f0119a8:	ad601b78 */ 	sw	$zero,0x1b78($t3)
/*  f0119ac:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0119b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0119b4:	ad801bd4 */ 	sw	$zero,0x1bd4($t4)
/*  f0119b8:	ac430000 */ 	sw	$v1,0x0($v0)
/*  f0119bc:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f0119c0:	ac430008 */ 	sw	$v1,0x8($v0)
/*  f0119c4:	ac43000c */ 	sw	$v1,0xc($v0)
/*  f0119c8:	0fc2e58f */ 	jal	func0f0b963c
/*  f0119cc:	ac200760 */ 	sw	$zero,0x760($at)
/*  f0119d0:	3c018007 */ 	lui	$at,0x8007
/*  f0119d4:	ac200744 */ 	sw	$zero,0x744($at)
/*  f0119d8:	3c018007 */ 	lui	$at,0x8007
/*  f0119dc:	ac200748 */ 	sw	$zero,0x748($at)
/*  f0119e0:	3c018007 */ 	lui	$at,0x8007
/*  f0119e4:	ac20074c */ 	sw	$zero,0x74c($at)
/*  f0119e8:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f0119ec:	44803000 */ 	mtc1	$zero,$f6
/*  f0119f0:	3c01800a */ 	lui	$at,0x800a
/*  f0119f4:	ada01b7c */ 	sw	$zero,0x1b7c($t5)
/*  f0119f8:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0119fc:	e7261b80 */ 	swc1	$f6,0x1b80($t9)
/*  f011a00:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011a04:	af001b88 */ 	sw	$zero,0x1b88($t8)
/*  f011a08:	ac20ddd4 */ 	sw	$zero,-0x222c($at)
/*  f011a0c:	3c01800a */ 	lui	$at,0x800a
/*  f011a10:	120000a1 */ 	beqz	$s0,.L0f011c98
/*  f011a14:	ac20ddd0 */ 	sw	$zero,-0x2230($at)
/*  f011a18:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f011a1c:	2401000c */ 	addiu	$at,$zero,0xc
/*  f011a20:	1041009d */ 	beq	$v0,$at,.L0f011c98
/*  f011a24:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f011a28:
/*  f011a28:	10200096 */ 	beqz	$at,.L0f011c84
/*  f011a2c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f011a30:	3c017f1b */ 	lui	$at,%hi(var7f1a8240)
/*  f011a34:	002e0821 */ 	addu	$at,$at,$t6
/*  f011a38:	8c2e8240 */ 	lw	$t6,%lo(var7f1a8240)($at)
/*  f011a3c:	01c00008 */ 	jr	$t6
/*  f011a40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a44:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f011a48:	3c02800a */ 	lui	$v0,%hi(var800a000c)
/*  f011a4c:	15e0000a */ 	bnez	$t7,.L0f011a78
/*  f011a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a54:	8c42de68 */ 	lw	$v0,-0x2198($v0)
/*  f011a58:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011a5c:	3c01800a */ 	lui	$at,0x800a
/*  f011a60:	00025040 */ 	sll	$t2,$v0,0x1
/*  f011a64:	002a0821 */ 	addu	$at,$at,$t2
/*  f011a68:	a429de38 */ 	sh	$t1,-0x21c8($at)
/*  f011a6c:	3c01800a */ 	lui	$at,0x800a
/*  f011a70:	244b0001 */ 	addiu	$t3,$v0,0x1
/*  f011a74:	ac2bde68 */ 	sw	$t3,-0x2198($at)
.L0f011a78:
/*  f011a78:	10000083 */ 	beqz	$zero,.L0f011c88
/*  f011a7c:	2610000c */ 	addiu	$s0,$s0,%lo(var800a000c)
/*  f011a80:	10000081 */ 	beqz	$zero,.L0f011c88
/*  f011a84:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011a88:	1000007f */ 	beqz	$zero,.L0f011c88
/*  f011a8c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011a90:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f011a94:	15800026 */ 	bnez	$t4,.L0f011b30
/*  f011a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a9c:	8e2d02a8 */ 	lw	$t5,0x2a8($s1)
/*  f011aa0:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f011aa4:	11b90022 */ 	beq	$t5,$t9,.L0f011b30
/*  f011aa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011aac:	0fc04558 */ 	jal	func0f011560
/*  f011ab0:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011ab4:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011ab8:	04800008 */ 	bltz	$a0,.L0f011adc
/*  f011abc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011ac0:	0fc04558 */ 	jal	func0f011560
/*  f011ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011ac8:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011acc:	0fc4478a */ 	jal	func0f111e28
/*  f011ad0:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f011ad4:	10000004 */ 	beqz	$zero,.L0f011ae8
/*  f011ad8:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f011adc:
/*  f011adc:	0fc44762 */ 	jal	func0f111d88
/*  f011ae0:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011ae4:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f011ae8:
/*  f011ae8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f011aec:	5700000c */ 	bnezl	$t8,.L0f011b20
/*  f011af0:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011af4:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f011af8:	3c01800a */ 	lui	$at,0x800a
/*  f011afc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f011b00:	ac2eddd0 */ 	sw	$t6,-0x2230($at)
/*  f011b04:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011b08:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f011b0c:	3c01800a */ 	lui	$at,0x800a
/*  f011b10:	04820003 */ 	bltzl	$a0,.L0f011b20
/*  f011b14:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011b18:	ac24ddd4 */ 	sw	$a0,-0x222c($at)
/*  f011b1c:	8e090004 */ 	lw	$t1,0x4($s0)
.L0f011b20:
/*  f011b20:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f011b24:	15210002 */ 	bne	$t1,$at,.L0f011b30
/*  f011b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011b2c:	a3aa007b */ 	sb	$t2,0x7b($sp)
.L0f011b30:
/*  f011b30:	10000055 */ 	beqz	$zero,.L0f011c88
/*  f011b34:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f011b38:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f011b3c:	15600008 */ 	bnez	$t3,.L0f011b60
/*  f011b40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011b44:	8e2c02a8 */ 	lw	$t4,0x2a8($s1)
/*  f011b48:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011b4c:	118d0004 */ 	beq	$t4,$t5,.L0f011b60
/*  f011b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011b54:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011b58:	0fc2a58a */ 	jal	func0f0a9628
/*  f011b5c:	8e050008 */ 	lw	$a1,0x8($s0)
.L0f011b60:
/*  f011b60:	10000049 */ 	beqz	$zero,.L0f011c88
/*  f011b64:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f011b68:	10000047 */ 	beqz	$zero,.L0f011c88
/*  f011b6c:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f011b70:	10000045 */ 	beqz	$zero,.L0f011c88
/*  f011b74:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011b78:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f011b7c:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011b80:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011b84:	10000040 */ 	beqz	$zero,.L0f011c88
/*  f011b88:	af190324 */ 	sw	$t9,0x324($t8)
/*  f011b8c:	1000003e */ 	beqz	$zero,.L0f011c88
/*  f011b90:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f011b94:	44804000 */ 	mtc1	$zero,$f8
/*  f011b98:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f011b9c:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f011ba0:	e5c81b80 */ 	swc1	$f8,0x1b80($t6)
/*  f011ba4:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011ba8:	5880000f */ 	blezl	$a0,.L0f011be8
/*  f011bac:	8e030004 */ 	lw	$v1,0x4($s0)
/*  f011bb0:	0081001a */ 	div	$zero,$a0,$at
/*  f011bb4:	00007810 */ 	mfhi	$t7
/*  f011bb8:	000f48c0 */ 	sll	$t1,$t7,0x3
/*  f011bbc:	012f4823 */ 	subu	$t1,$t1,$t7
/*  f011bc0:	00094940 */ 	sll	$t1,$t1,0x5
/*  f011bc4:	012f4821 */ 	addu	$t1,$t1,$t7
/*  f011bc8:	00094900 */ 	sll	$t1,$t1,0x4
/*  f011bcc:	44898000 */ 	mtc1	$t1,$f16
/*  f011bd0:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011bd4:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f011bd8:	c44a1b80 */ 	lwc1	$f10,0x1b80($v0)
/*  f011bdc:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f011be0:	e4441b80 */ 	swc1	$f4,0x1b80($v0)
/*  f011be4:	8e030004 */ 	lw	$v1,0x4($s0)
.L0f011be8:
/*  f011be8:	2401000c */ 	addiu	$at,$zero,0xc
/*  f011bec:	1860000e */ 	blez	$v1,.L0f011c28
/*  f011bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011bf4:	0061001a */ 	div	$zero,$v1,$at
/*  f011bf8:	00005010 */ 	mfhi	$t2
/*  f011bfc:	3c010003 */ 	lui	$at,0x3
/*  f011c00:	34214bc0 */ 	ori	$at,$at,0x4bc0
/*  f011c04:	01410019 */ 	multu	$t2,$at
/*  f011c08:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011c0c:	c4461b80 */ 	lwc1	$f6,0x1b80($v0)
/*  f011c10:	00005812 */ 	mflo	$t3
/*  f011c14:	448b4000 */ 	mtc1	$t3,$f8
/*  f011c18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011c1c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f011c20:	46103280 */ 	add.s	$f10,$f6,$f16
/*  f011c24:	e44a1b80 */ 	swc1	$f10,0x1b80($v0)
.L0f011c28:
/*  f011c28:	10000017 */ 	beqz	$zero,.L0f011c88
/*  f011c2c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011c30:	3c0c800a */ 	lui	$t4,0x800a
/*  f011c34:	8d8cd050 */ 	lw	$t4,-0x2fb0($t4)
/*  f011c38:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f011c3c:	3c018007 */ 	lui	$at,0x8007
/*  f011c40:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f011c44:	ac220740 */ 	sw	$v0,0x740($at)
/*  f011c48:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f011c4c:	57200005 */ 	bnezl	$t9,.L0f011c64
/*  f011c50:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f011c54:	94580002 */ 	lhu	$t8,0x2($v0)
/*  f011c58:	13000008 */ 	beqz	$t8,.L0f011c7c
/*  f011c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011c60:	944e000c */ 	lhu	$t6,0xc($v0)
.L0f011c64:
/*  f011c64:	2442000c */ 	addiu	$v0,$v0,%lo(var800a000c)
/*  f011c68:	55c0fffe */ 	bnezl	$t6,.L0f011c64
/*  f011c6c:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f011c70:	944f0002 */ 	lhu	$t7,0x2($v0)
/*  f011c74:	55e0fffb */ 	bnezl	$t7,.L0f011c64
/*  f011c78:	944e000c */ 	lhu	$t6,0xc($v0)
.L0f011c7c:
/*  f011c7c:	10000002 */ 	beqz	$zero,.L0f011c88
/*  f011c80:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f011c84:
/*  f011c84:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f011c88:
/*  f011c88:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f011c8c:	2401000c */ 	addiu	$at,$zero,0xc
/*  f011c90:	5441ff65 */ 	bnel	$v0,$at,.L0f011a28
/*  f011c94:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f011c98:
/*  f011c98:	0fc44762 */ 	jal	func0f111d88
/*  f011c9c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011ca0:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ca4:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f011ca8:	10400006 */ 	beqz	$v0,.L0f011cc4
/*  f011cac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011cb0:	0fc44762 */ 	jal	func0f111d88
/*  f011cb4:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f011cb8:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f011cbc:	0fc2a58a */ 	jal	func0f0a9628
/*  f011cc0:	24050050 */ 	addiu	$a1,$zero,0x50
.L0f011cc4:
/*  f011cc4:	0fc41b99 */ 	jal	cheatIsActive
/*  f011cc8:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f011ccc:	10400006 */ 	beqz	$v0,.L0f011ce8
/*  f011cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011cd4:	0fc44762 */ 	jal	func0f111d88
/*  f011cd8:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f011cdc:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f011ce0:	0fc2a58a */ 	jal	func0f0a9628
/*  f011ce4:	24050050 */ 	addiu	$a1,$zero,0x50
.L0f011ce8:
/*  f011ce8:	0fc41b99 */ 	jal	cheatIsActive
/*  f011cec:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011cf0:	10400006 */ 	beqz	$v0,.L0f011d0c
/*  f011cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011cf8:	0fc44762 */ 	jal	func0f111d88
/*  f011cfc:	24040031 */ 	addiu	$a0,$zero,0x31
/*  f011d00:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f011d04:	0fc2a58a */ 	jal	func0f0a9628
/*  f011d08:	24051c20 */ 	addiu	$a1,$zero,0x1c20
.L0f011d0c:
/*  f011d0c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d10:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f011d14:	10400003 */ 	beqz	$v0,.L0f011d24
/*  f011d18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011d1c:	0fc44762 */ 	jal	func0f111d88
/*  f011d20:	2404002d */ 	addiu	$a0,$zero,0x2d
.L0f011d24:
/*  f011d24:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d28:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f011d2c:	10400003 */ 	beqz	$v0,.L0f011d3c
/*  f011d30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011d34:	0fc44762 */ 	jal	func0f111d88
/*  f011d38:	24040037 */ 	addiu	$a0,$zero,0x37
.L0f011d3c:
/*  f011d3c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d40:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f011d44:	10400006 */ 	beqz	$v0,.L0f011d60
/*  f011d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011d4c:	0fc44762 */ 	jal	func0f111d88
/*  f011d50:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f011d54:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f011d58:	0fc2a58a */ 	jal	func0f0a9628
/*  f011d5c:	2405000a */ 	addiu	$a1,$zero,0xa
.L0f011d60:
/*  f011d60:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d64:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f011d68:	10400006 */ 	beqz	$v0,.L0f011d84
/*  f011d6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011d70:	0fc44762 */ 	jal	func0f111d88
/*  f011d74:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f011d78:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011d7c:	0fc2a58a */ 	jal	func0f0a9628
/*  f011d80:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011d84:
/*  f011d84:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d88:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f011d8c:	10400003 */ 	beqz	$v0,.L0f011d9c
/*  f011d90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011d94:	0fc44762 */ 	jal	func0f111d88
/*  f011d98:	2404002f */ 	addiu	$a0,$zero,0x2f
.L0f011d9c:
/*  f011d9c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011da0:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f011da4:	10400009 */ 	beqz	$v0,.L0f011dcc
/*  f011da8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011dac:	0fc44762 */ 	jal	func0f111d88
/*  f011db0:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f011db4:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011db8:	0fc2a58a */ 	jal	func0f0a9628
/*  f011dbc:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f011dc0:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f011dc4:	0fc2a58a */ 	jal	func0f0a9628
/*  f011dc8:	24050014 */ 	addiu	$a1,$zero,0x14
.L0f011dcc:
/*  f011dcc:	0fc41b99 */ 	jal	cheatIsActive
/*  f011dd0:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f011dd4:	10400006 */ 	beqz	$v0,.L0f011df0
/*  f011dd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011ddc:	0fc44762 */ 	jal	func0f111d88
/*  f011de0:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f011de4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011de8:	0fc2a58a */ 	jal	func0f0a9628
/*  f011dec:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011df0:
/*  f011df0:	0fc41b99 */ 	jal	cheatIsActive
/*  f011df4:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f011df8:	10400006 */ 	beqz	$v0,.L0f011e14
/*  f011dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011e00:	0fc44762 */ 	jal	func0f111d88
/*  f011e04:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f011e08:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011e0c:	0fc2a58a */ 	jal	func0f0a9628
/*  f011e10:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011e14:
/*  f011e14:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e18:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f011e1c:	54400005 */ 	bnezl	$v0,.L0f011e34
/*  f011e20:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f011e24:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e28:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f011e2c:	10400009 */ 	beqz	$v0,.L0f011e54
/*  f011e30:	24040016 */ 	addiu	$a0,$zero,0x16
.L0f011e34:
/*  f011e34:	0fc2a58a */ 	jal	func0f0a9628
/*  f011e38:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f011e3c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e40:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f011e44:	10400003 */ 	beqz	$v0,.L0f011e54
/*  f011e48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011e4c:	0fc44762 */ 	jal	func0f111d88
/*  f011e50:	2404002c */ 	addiu	$a0,$zero,0x2c
.L0f011e54:
/*  f011e54:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e58:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f011e5c:	10400006 */ 	beqz	$v0,.L0f011e78
/*  f011e60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011e64:	0fc44762 */ 	jal	func0f111d88
/*  f011e68:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f011e6c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011e70:	0fc2a58a */ 	jal	func0f0a9628
/*  f011e74:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011e78:
/*  f011e78:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e7c:	24040023 */ 	addiu	$a0,$zero,0x23
/*  f011e80:	10400006 */ 	beqz	$v0,.L0f011e9c
/*  f011e84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011e88:	0fc44762 */ 	jal	func0f111d88
/*  f011e8c:	24040025 */ 	addiu	$a0,$zero,0x25
/*  f011e90:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011e94:	0fc2a58a */ 	jal	func0f0a9628
/*  f011e98:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011e9c:
/*  f011e9c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ea0:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f011ea4:	10400006 */ 	beqz	$v0,.L0f011ec0
/*  f011ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011eac:	0fc44762 */ 	jal	func0f111d88
/*  f011eb0:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f011eb4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011eb8:	0fc2a58a */ 	jal	func0f0a9628
/*  f011ebc:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011ec0:
/*  f011ec0:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ec4:	24040025 */ 	addiu	$a0,$zero,0x25
/*  f011ec8:	10400006 */ 	beqz	$v0,.L0f011ee4
/*  f011ecc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011ed0:	0fc44762 */ 	jal	func0f111d88
/*  f011ed4:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f011ed8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011edc:	0fc2a58a */ 	jal	func0f0a9628
/*  f011ee0:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011ee4:
/*  f011ee4:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ee8:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f011eec:	10400006 */ 	beqz	$v0,.L0f011f08
/*  f011ef0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011ef4:	0fc44762 */ 	jal	func0f111d88
/*  f011ef8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f011efc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011f00:	0fc2a58a */ 	jal	func0f0a9628
/*  f011f04:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011f08:
/*  f011f08:	0fc41b99 */ 	jal	cheatIsActive
/*  f011f0c:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f011f10:	10400006 */ 	beqz	$v0,.L0f011f2c
/*  f011f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011f18:	0fc44762 */ 	jal	func0f111d88
/*  f011f1c:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f011f20:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011f24:	0fc2a58a */ 	jal	func0f0a9628
/*  f011f28:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011f2c:
/*  f011f2c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011f30:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f011f34:	10400006 */ 	beqz	$v0,.L0f011f50
/*  f011f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011f3c:	0fc44762 */ 	jal	func0f111d88
/*  f011f40:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f011f44:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011f48:	0fc2a58a */ 	jal	func0f0a9628
/*  f011f4c:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011f50:
/*  f011f50:	0fc41b99 */ 	jal	cheatIsActive
/*  f011f54:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f011f58:	50400007 */ 	beqzl	$v0,.L0f011f78
/*  f011f5c:	8fa90080 */ 	lw	$t1,0x80($sp)
/*  f011f60:	0fc44762 */ 	jal	func0f111d88
/*  f011f64:	2404002b */ 	addiu	$a0,$zero,0x2b
/*  f011f68:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011f6c:	0fc2a58a */ 	jal	func0f0a9628
/*  f011f70:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f011f74:	8fa90080 */ 	lw	$t1,0x80($sp)
.L0f011f78:
/*  f011f78:	15200003 */ 	bnez	$t1,.L0f011f88
/*  f011f7c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f011f80:	3c01800a */ 	lui	$at,0x800a
/*  f011f84:	ac2addd0 */ 	sw	$t2,-0x2230($at)
.L0f011f88:
/*  f011f88:	0fc180d6 */ 	jal	func0f060358
/*  f011f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011f90:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f011f94:	24190006 */ 	addiu	$t9,$zero,0x6
/*  f011f98:	ad6200bc */ 	sw	$v0,0xbc($t3)
/*  f011f9c:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f011fa0:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f011fa4:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f011fa8:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011fac:	8f0e00bc */ 	lw	$t6,0xbc($t8)
/*  f011fb0:	a1d90000 */ 	sb	$t9,0x0($t6)
/*  f011fb4:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f011fb8:	0fc1812f */ 	jal	func0f0604bc
/*  f011fbc:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f011fc0:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f011fc4:	0fc180bc */ 	jal	propHide
/*  f011fc8:	8d2400bc */ 	lw	$a0,0xbc($t1)
/*  f011fcc:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f011fd0:	00002825 */ 	or	$a1,$zero,$zero
/*  f011fd4:	0fc0819a */ 	jal	func0f020668
/*  f011fd8:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f011fdc:	8e2b0298 */ 	lw	$t3,0x298($s1)
/*  f011fe0:	05620008 */ 	bltzl	$t3,.L0f012004
/*  f011fe4:	8e2e029c */ 	lw	$t6,0x29c($s1)
/*  f011fe8:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011fec:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f011ff0:	8db800bc */ 	lw	$t8,0xbc($t5)
/*  f011ff4:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f011ff8:	10000029 */ 	beqz	$zero,.L0f0120a0
/*  f011ffc:	a32c0125 */ 	sb	$t4,0x125($t9)
/*  f012000:	8e2e029c */ 	lw	$t6,0x29c($s1)
.L0f012004:
/*  f012004:	05c20010 */ 	bltzl	$t6,.L0f012048
/*  f012008:	8e390314 */ 	lw	$t9,0x314($s1)
/*  f01200c:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f012010:	8e2f02a0 */ 	lw	$t7,0x2a0($s1)
/*  f012014:	55e20007 */ 	bnel	$t7,$v0,.L0f012034
/*  f012018:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f01201c:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f012020:	24090010 */ 	addiu	$t1,$zero,0x10
/*  f012024:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f012028:	1000001d */ 	beqz	$zero,.L0f0120a0
/*  f01202c:	a1690125 */ 	sb	$t1,0x125($t3)
/*  f012030:	8c5800bc */ 	lw	$t8,0xbc($v0)
.L0f012034:
/*  f012034:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f012038:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f01203c:	10000018 */ 	beqz	$zero,.L0f0120a0
/*  f012040:	a18d0125 */ 	sb	$t5,0x125($t4)
/*  f012044:	8e390314 */ 	lw	$t9,0x314($s1)
.L0f012048:
/*  f012048:	53200011 */ 	beqzl	$t9,.L0f012090
/*  f01204c:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012050:	8e2e0288 */ 	lw	$t6,0x288($s1)
/*  f012054:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f012058:	3c09800b */ 	lui	$t1,0x800b
/*  f01205c:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f012060:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f012064:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f012068:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f01206c:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f012070:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f012074:	012a4821 */ 	addu	$t1,$t1,$t2
/*  f012078:	9129c7c9 */ 	lbu	$t1,-0x3837($t1)
/*  f01207c:	8d990004 */ 	lw	$t9,0x4($t4)
/*  f012080:	012bc004 */ 	sllv	$t8,$t3,$t1
/*  f012084:	10000006 */ 	beqz	$zero,.L0f0120a0
/*  f012088:	a3380125 */ 	sb	$t8,0x125($t9)
/*  f01208c:	8e2f0284 */ 	lw	$t7,0x284($s1)
.L0f012090:
/*  f012090:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f012094:	8dea00bc */ 	lw	$t2,0xbc($t7)
/*  f012098:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f01209c:	a16e0125 */ 	sb	$t6,0x125($t3)
.L0f0120a0:
/*  f0120a0:	93a9007b */ 	lbu	$t1,0x7b($sp)
/*  f0120a4:	11200003 */ 	beqz	$t1,.L0f0120b4
/*  f0120a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0120ac:	0fc0458c */ 	jal	func0f011630
/*  f0120b0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0120b4:
/*  f0120b4:	3c0d800a */ 	lui	$t5,0x800a
/*  f0120b8:	8dadde68 */ 	lw	$t5,-0x2198($t5)
/*  f0120bc:	59a0002f */ 	blezl	$t5,.L0f01217c
/*  f0120c0:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f0120c4:	8e2c0298 */ 	lw	$t4,0x298($s1)
/*  f0120c8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0120cc:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0120d0:	0580000a */ 	bltz	$t4,.L0f0120fc
/*  f0120d4:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0120d8:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0120dc:	44816000 */ 	mtc1	$at,$f12
/*  f0120e0:	0fc6185f */ 	jal	scenarioCallback2c
/*  f0120e4:	8f0700bc */ 	lw	$a3,0xbc($t8)
/*  f0120e8:	3c017f1b */ 	lui	$at,%hi(var7f1a8270)
/*  f0120ec:	c4328270 */ 	lwc1	$f18,%lo(var7f1a8270)($at)
/*  f0120f0:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f0120f4:	10000020 */ 	beqz	$zero,.L0f012178
/*  f0120f8:	e7a40088 */ 	swc1	$f4,0x88($sp)
.L0f0120fc:
/*  f0120fc:	8e39029c */ 	lw	$t9,0x29c($s1)
/*  f012100:	3c0141f0 */ 	lui	$at,0x41f0
/*  f012104:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f012108:	0720000c */ 	bltz	$t9,.L0f01213c
/*  f01210c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f012110:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012114:	44816000 */ 	mtc1	$at,$f12
/*  f012118:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f01211c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f012120:	0fc6185f */ 	jal	scenarioCallback2c
/*  f012124:	8de700bc */ 	lw	$a3,0xbc($t7)
/*  f012128:	3c017f1b */ 	lui	$at,%hi(var7f1a8274)
/*  f01212c:	c4288274 */ 	lwc1	$f8,%lo(var7f1a8274)($at)
/*  f012130:	46004181 */ 	sub.s	$f6,$f8,$f0
/*  f012134:	10000010 */ 	beqz	$zero,.L0f012178
/*  f012138:	e7a60088 */ 	swc1	$f6,0x88($sp)
.L0f01213c:
/*  f01213c:	8e2a0314 */ 	lw	$t2,0x314($s1)
/*  f012140:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f012144:	3c01800a */ 	lui	$at,0x800a
/*  f012148:	55400003 */ 	bnezl	$t2,.L0f012158
/*  f01214c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012150:	ac2ede68 */ 	sw	$t6,-0x2198($at)
/*  f012154:	8e2b0284 */ 	lw	$t3,0x284($s1)
.L0f012158:
/*  f012158:	3c0141f0 */ 	lui	$at,0x41f0
/*  f01215c:	44816000 */ 	mtc1	$at,$f12
/*  f012160:	0fc6185f */ 	jal	scenarioCallback2c
/*  f012164:	8d6700bc */ 	lw	$a3,0xbc($t3)
/*  f012168:	3c017f1b */ 	lui	$at,%hi(var7f1a8278)
/*  f01216c:	c4308278 */ 	lwc1	$f16,%lo(var7f1a8278)($at)
/*  f012170:	46008281 */ 	sub.s	$f10,$f16,$f0
/*  f012174:	e7aa0088 */ 	swc1	$f10,0x88($sp)
.L0f012178:
/*  f012178:	8e220284 */ 	lw	$v0,0x284($s1)
.L0f01217c:
/*  f01217c:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f012180:	3c0541f0 */ 	lui	$a1,0x41f0
/*  f012184:	2449161e */ 	addiu	$t1,$v0,0x161e
/*  f012188:	244d161c */ 	addiu	$t5,$v0,0x161c
/*  f01218c:	244c19b0 */ 	addiu	$t4,$v0,0x19b0
/*  f012190:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f012194:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f012198:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f01219c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0121a0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0121a4:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0121a8:	0c00a86c */ 	jal	func0002a1b0
/*  f0121ac:	2447161a */ 	addiu	$a3,$v0,0x161a
/*  f0121b0:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f0121b4:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0121b8:	44813000 */ 	mtc1	$at,$f6
/*  f0121bc:	c45219c4 */ 	lwc1	$f18,0x19c4($v0)
/*  f0121c0:	3c017f1b */ 	lui	$at,%hi(var7f1a827c)
/*  f0121c4:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0121c8:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f0121cc:	e7a400a0 */ 	swc1	$f4,0xa0($sp)
/*  f0121d0:	e4400074 */ 	swc1	$f0,0x74($v0)
/*  f0121d4:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0121d8:	e7000078 */ 	swc1	$f0,0x78($t8)
/*  f0121dc:	c7a80088 */ 	lwc1	$f8,0x88($sp)
/*  f0121e0:	c42a827c */ 	lwc1	$f10,%lo(var7f1a827c)($at)
/*  f0121e4:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0121e8:	46064402 */ 	mul.s	$f16,$f8,$f6
/*  f0121ec:	460a8483 */ 	div.s	$f18,$f16,$f10
/*  f0121f0:	e7320144 */ 	swc1	$f18,0x144($t9)
/*  f0121f4:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f0121f8:	0fc2e168 */ 	jal	func0f0b85a0
/*  f0121fc:	2484036c */ 	addiu	$a0,$a0,0x36c
/*  f012200:	0c0068f7 */ 	jal	func0001a3dc
/*  f012204:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f012208:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f01220c:	46000107 */ 	neg.s	$f4,$f0
/*  f012210:	44804000 */ 	mtc1	$zero,$f8
/*  f012214:	e5e4036c */ 	swc1	$f4,0x36c($t7)
/*  f012218:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f01221c:	e5480370 */ 	swc1	$f8,0x370($t2)
/*  f012220:	0c0068f4 */ 	jal	func0001a3d0
/*  f012224:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f012228:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f01222c:	e5c00374 */ 	swc1	$f0,0x374($t6)
/*  f012230:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012234:	c7a2009c */ 	lwc1	$f2,0x9c($sp)
/*  f012238:	e5620310 */ 	swc1	$f2,0x310($t3)
/*  f01223c:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f012240:	8d2d00bc */ 	lw	$t5,0xbc($t1)
/*  f012244:	e5a20008 */ 	swc1	$f2,0x8($t5)
/*  f012248:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f01224c:	c7a200a0 */ 	lwc1	$f2,0xa0($sp)
/*  f012250:	e5820314 */ 	swc1	$f2,0x314($t4)
/*  f012254:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f012258:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f01225c:	e722000c */ 	swc1	$f2,0xc($t9)
/*  f012260:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012264:	c7a200a4 */ 	lwc1	$f2,0xa4($sp)
/*  f012268:	e5e20318 */ 	swc1	$f2,0x318($t7)
/*  f01226c:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012270:	8d4e00bc */ 	lw	$t6,0xbc($t2)
/*  f012274:	e5c20010 */ 	swc1	$f2,0x10($t6)
/*  f012278:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f01227c:	0fc19711 */ 	jal	func0f065c44
/*  f012280:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f012284:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f012288:	87a9008c */ 	lh	$t1,0x8c($sp)
/*  f01228c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f012290:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f012294:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f012298:	a5890028 */ 	sh	$t1,0x28($t4)
/*  f01229c:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0122a0:	8f2f00bc */ 	lw	$t7,0xbc($t9)
/*  f0122a4:	a5f8002a */ 	sh	$t8,0x2a($t7)
/*  f0122a8:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f0122ac:	87a7008c */ 	lh	$a3,0x8c($sp)
/*  f0122b0:	24450394 */ 	addiu	$a1,$v0,0x394
/*  f0122b4:	0fc30709 */ 	jal	func0f0c1c24
/*  f0122b8:	24460388 */ 	addiu	$a2,$v0,0x388
/*  f0122bc:	0fc07934 */ 	jal	getNumChrs
/*  f0122c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0122c4:	18400026 */ 	blez	$v0,.L0f012360
/*  f0122c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0122cc:	000428c0 */ 	sll	$a1,$a0,0x3
/*  f0122d0:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f0122d4:	00052880 */ 	sll	$a1,$a1,0x2
/*  f0122d8:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f0122dc:	00052880 */ 	sll	$a1,$a1,0x2
/*  f0122e0:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f0122e4:	3c068006 */ 	lui	$a2,%hi(g_ChrsA)
/*  f0122e8:	24c62988 */ 	addiu	$a2,$a2,%lo(g_ChrsA)
/*  f0122ec:	000528c0 */ 	sll	$a1,$a1,0x3
/*  f0122f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0122f4:	24080048 */ 	addiu	$t0,$zero,0x48
/*  f0122f8:	2407fffe */ 	addiu	$a3,$zero,-2
/*  f0122fc:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f012300:
/*  f012300:	004a1821 */ 	addu	$v1,$v0,$t2
/*  f012304:	846e017e */ 	lh	$t6,0x17e($v1)
/*  f012308:	24420368 */ 	addiu	$v0,$v0,0x368
/*  f01230c:	54ee0012 */ 	bnel	$a3,$t6,.L0f012358
/*  f012310:	0045082a */ 	slt	$at,$v0,$a1
/*  f012314:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012318:	8e290338 */ 	lw	$t1,0x338($s1)
/*  f01231c:	8d6d00bc */ 	lw	$t5,0xbc($t3)
/*  f012320:	01a96023 */ 	subu	$t4,$t5,$t1
/*  f012324:	0188001a */ 	div	$zero,$t4,$t0
/*  f012328:	0000c812 */ 	mflo	$t9
/*  f01232c:	a479017e */ 	sh	$t9,0x17e($v1)
/*  f012330:	15000002 */ 	bnez	$t0,.L0f01233c
/*  f012334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012338:	0007000d */ 	break	0x7
.L0f01233c:
/*  f01233c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f012340:	15010004 */ 	bne	$t0,$at,.L0f012354
/*  f012344:	3c018000 */ 	lui	$at,0x8000
/*  f012348:	15810002 */ 	bne	$t4,$at,.L0f012354
/*  f01234c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012350:	0006000d */ 	break	0x6
.L0f012354:
/*  f012354:	0045082a */ 	slt	$at,$v0,$a1
.L0f012358:
/*  f012358:	5420ffe9 */ 	bnezl	$at,.L0f012300
/*  f01235c:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f012360:
/*  f012360:	0fc32e31 */ 	jal	func0f0cb8c4
/*  f012364:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f012368:	8e380318 */ 	lw	$t8,0x318($s1)
/*  f01236c:	13000005 */ 	beqz	$t8,.L0f012384
/*  f012370:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012374:	0fc2e59d */ 	jal	func0f0b9674
/*  f012378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01237c:	10000003 */ 	beqz	$zero,.L0f01238c
/*  f012380:	00000000 */ 	sll	$zero,$zero,0x0
.L0f012384:
/*  f012384:	0fc2e688 */ 	jal	func0f0b9a20
/*  f012388:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01238c:
/*  f01238c:	3c048007 */ 	lui	$a0,%hi(var80070768)
/*  f012390:	24840768 */ 	addiu	$a0,$a0,%lo(var80070768)
/*  f012394:	00007840 */ 	sll	$t7,$zero,0x1
/*  f012398:	008f5021 */ 	addu	$t2,$a0,$t7
/*  f01239c:	854e0000 */ 	lh	$t6,0x0($t2)
/*  f0123a0:	3c038007 */ 	lui	$v1,%hi(var8007077c)
/*  f0123a4:	2463077c */ 	addiu	$v1,$v1,%lo(var8007077c)
/*  f0123a8:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0123ac:	19c00009 */ 	blez	$t6,.L0f0123d4
/*  f0123b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0123b4:	244b0001 */ 	addiu	$t3,$v0,0x1
.L0f0123b8:
/*  f0123b8:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f0123bc:	008d4821 */ 	addu	$t1,$a0,$t5
/*  f0123c0:	852c0000 */ 	lh	$t4,0x0($t1)
/*  f0123c4:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0123c8:	01601025 */ 	or	$v0,$t3,$zero
/*  f0123cc:	5d80fffa */ 	bgtzl	$t4,.L0f0123b8
/*  f0123d0:	244b0001 */ 	addiu	$t3,$v0,0x1
.L0f0123d4:
/*  f0123d4:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0123d8:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0123dc:	3c03800a */ 	lui	$v1,0x800a
/*  f0123e0:	af201b84 */ 	sw	$zero,0x1b84($t9)
/*  f0123e4:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0123e8:	24639fd0 */ 	addiu	$v1,$v1,-24624
/*  f0123ec:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0123f0:	af0000e0 */ 	sw	$zero,0xe0($t8)
.L0f0123f4:
/*  f0123f4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0123f8:	1443fffe */ 	bne	$v0,$v1,.L0f0123f4
/*  f0123fc:	ac4004b4 */ 	sw	$zero,0x4b4($v0)
/*  f012400:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f012404:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f012408:	0fc2e1cb */ 	jal	func0f0b872c
/*  f01240c:	00003025 */ 	or	$a2,$zero,$zero
/*  f012410:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012414:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f012418:	8d4e00bc */ 	lw	$t6,0xbc($t2)
/*  f01241c:	8dcb0004 */ 	lw	$t3,0x4($t6)
/*  f012420:	a56f0010 */ 	sh	$t7,0x10($t3)
/*  f012424:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f012428:	8fad0044 */ 	lw	$t5,0x44($sp)
/*  f01242c:	8d2c00bc */ 	lw	$t4,0xbc($t1)
/*  f012430:	8d990004 */ 	lw	$t9,0x4($t4)
/*  f012434:	a32d0006 */ 	sb	$t5,0x6($t9)
/*  f012438:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f01243c:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f012440:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f012444:	03e00008 */ 	jr	$ra
/*  f012448:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f01244c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f012450
/*  f012450:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f012454:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f012458:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f01245c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f012460:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f012464:	11c00003 */ 	beqz	$t6,.L0f012474
/*  f012468:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01246c:	10000002 */ 	beqz	$zero,.L0f012478
/*  f012470:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f012474:
/*  f012474:	00003025 */ 	or	$a2,$zero,$zero
.L0f012478:
/*  f012478:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f01247c:	00001825 */ 	or	$v1,$zero,$zero
/*  f012480:	00002025 */ 	or	$a0,$zero,$zero
/*  f012484:	11e00003 */ 	beqz	$t7,.L0f012494
/*  f012488:	00001025 */ 	or	$v0,$zero,$zero
/*  f01248c:	10000001 */ 	beqz	$zero,.L0f012494
/*  f012490:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f012494:
/*  f012494:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f012498:	13000003 */ 	beqz	$t8,.L0f0124a8
/*  f01249c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0124a0:	10000001 */ 	beqz	$zero,.L0f0124a8
/*  f0124a4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0124a8:
/*  f0124a8:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f0124ac:	13200003 */ 	beqz	$t9,.L0f0124bc
/*  f0124b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0124b4:	10000001 */ 	beqz	$zero,.L0f0124bc
/*  f0124b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0124bc:
/*  f0124bc:	00444021 */ 	addu	$t0,$v0,$a0
/*  f0124c0:	01034821 */ 	addu	$t1,$t0,$v1
/*  f0124c4:	01265021 */ 	addu	$t2,$t1,$a2
/*  f0124c8:	5541000c */ 	bnel	$t2,$at,.L0f0124fc
/*  f0124cc:	8cad0284 */ 	lw	$t5,0x284($a1)
/*  f0124d0:	8cab0318 */ 	lw	$t3,0x318($a1)
/*  f0124d4:	55600009 */ 	bnezl	$t3,.L0f0124fc
/*  f0124d8:	8cad0284 */ 	lw	$t5,0x284($a1)
/*  f0124dc:	0fc41b99 */ 	jal	cheatIsActive
/*  f0124e0:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0124e4:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0124e8:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0124ec:	8cac0284 */ 	lw	$t4,0x284($a1)
/*  f0124f0:	10000003 */ 	beqz	$zero,.L0f012500
/*  f0124f4:	ad821870 */ 	sw	$v0,0x1870($t4)
/*  f0124f8:	8cad0284 */ 	lw	$t5,0x284($a1)
.L0f0124fc:
/*  f0124fc:	ada01870 */ 	sw	$zero,0x1870($t5)
.L0f012500:
/*  f012500:	00001025 */ 	or	$v0,$zero,$zero
/*  f012504:	24040078 */ 	addiu	$a0,$zero,0x78
/*  f012508:	2403ffff */ 	addiu	$v1,$zero,-1
.L0f01250c:
/*  f01250c:	8cae0284 */ 	lw	$t6,0x284($a1)
/*  f012510:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f012514:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f012518:	1444fffc */ 	bne	$v0,$a0,.L0f01250c
/*  f01251c:	ade31880 */ 	sw	$v1,0x1880($t7)
/*  f012520:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f012524:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f012528:	03e00008 */ 	jr	$ra
/*  f01252c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f012530
/*  f012530:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f012534:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f012538:	8c4f0284 */ 	lw	$t7,0x284($v0)
/*  f01253c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f012540:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f012544:	248e001e */ 	addiu	$t6,$a0,0x1e
/*  f012548:	adee186c */ 	sw	$t6,0x186c($t7)
/*  f01254c:	8c580284 */ 	lw	$t8,0x284($v0)
/*  f012550:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f012554:	8f04186c */ 	lw	$a0,0x186c($t8)
/*  f012558:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f01255c:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f012560:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f012564:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f012568:	3488000f */ 	ori	$t0,$a0,0xf
/*  f01256c:	0c0048f2 */ 	jal	func000123c8
/*  f012570:	3904000f */ 	xori	$a0,$t0,0xf
/*  f012574:	3c0a800a */ 	lui	$t2,0x800a
/*  f012578:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f01257c:	0fc44580 */ 	jal	func0f111600
/*  f012580:	ad421868 */ 	sw	$v0,0x1868($t2)
/*  f012584:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f012588:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01258c:	03e00008 */ 	jr	$ra
/*  f012590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01259c:	00000000 */ 	sll	$zero,$zero,0x0
);
