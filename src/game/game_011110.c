#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/inventory/items.h"
#include "game/game_011110.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/bondgun.h"
#include "game/game_0b69d0.h"
#include "game/inventory/inventory.h"
#include "game/game_1655c0.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/memory.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

void func0f011110(void)
{
	var800705a4 = 0;
	var800705a0 = 0;
}

void func0f011124(bool value)
{
	var800705a8 = value;
}

GLOBAL_ASM(
glabel func0f011130
/*  f011130:	3c01800a */ 	lui	$at,%hi(var8009dd08)
/*  f011134:	ac24dd08 */ 	sw	$a0,%lo(var8009dd08)($at)
/*  f011138:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f01113c:	3c01800a */ 	lui	$at,%hi(var8009dd0c)
/*  f011140:	254a0af0 */ 	addiu	$t2,$t2,%lo(g_Is4Mb)
/*  f011144:	ac25dd0c */ 	sw	$a1,%lo(var8009dd0c)($at)
/*  f011148:	91480000 */ 	lbu	$t0,0x0($t2)
/*  f01114c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f011150:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f011154:	15280003 */ 	bne	$t1,$t0,.L0f011164
/*  f011158:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01115c:	10000002 */ 	b	.L0f011168
/*  f011160:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f011164:
/*  f011164:	2402003c */ 	addiu	$v0,$zero,0x3c
.L0f011168:
/*  f011168:	00827021 */ 	addu	$t6,$a0,$v0
/*  f01116c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f011170:	25f80014 */ 	addiu	$t8,$t7,0x14
/*  f011174:	3c018007 */ 	lui	$at,%hi(var800705a0)
/*  f011178:	ac3805a0 */ 	sw	$t8,%lo(var800705a0)($at)
/*  f01117c:	3c018007 */ 	lui	$at,%hi(var800705a4)
/*  f011180:	24b90014 */ 	addiu	$t9,$a1,0x14
/*  f011184:	15280003 */ 	bne	$t1,$t0,.L0f011194
/*  f011188:	ac3905a4 */ 	sw	$t9,%lo(var800705a4)($at)
/*  f01118c:	10000002 */ 	b	.L0f011198
/*  f011190:	24030018 */ 	addiu	$v1,$zero,0x18
.L0f011194:
/*  f011194:	24030019 */ 	addiu	$v1,$zero,0x19
.L0f011198:
/*  f011198:	15280003 */ 	bne	$t1,$t0,.L0f0111a8
/*  f01119c:	3c07800a */ 	lui	$a3,%hi(var8009dd10)
/*  f0111a0:	10000002 */ 	b	.L0f0111ac
/*  f0111a4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0111a8:
/*  f0111a8:	24020023 */ 	addiu	$v0,$zero,0x23
.L0f0111ac:
/*  f0111ac:	15280003 */ 	bne	$t1,$t0,.L0f0111bc
/*  f0111b0:	24e7dd10 */ 	addiu	$a3,$a3,%lo(var8009dd10)
/*  f0111b4:	10000002 */ 	b	.L0f0111c0
/*  f0111b8:	00003025 */ 	or	$a2,$zero,$zero
.L0f0111bc:
/*  f0111bc:	24060014 */ 	addiu	$a2,$zero,0x14
.L0f0111c0:
/*  f0111c0:	00c27021 */ 	addu	$t6,$a2,$v0
/*  f0111c4:	01c35821 */ 	addu	$t3,$t6,$v1
/*  f0111c8:	000b78c0 */ 	sll	$t7,$t3,0x3
/*  f0111cc:	15280003 */ 	bne	$t1,$t0,.L0f0111dc
/*  f0111d0:	01e05825 */ 	or	$t3,$t7,$zero
/*  f0111d4:	10000002 */ 	b	.L0f0111e0
/*  f0111d8:	00003025 */ 	or	$a2,$zero,$zero
.L0f0111dc:
/*  f0111dc:	24060023 */ 	addiu	$a2,$zero,0x23
.L0f0111e0:
/*  f0111e0:	15280003 */ 	bne	$t1,$t0,.L0f0111f0
/*  f0111e4:	00061900 */ 	sll	$v1,$a2,0x4
/*  f0111e8:	10000002 */ 	b	.L0f0111f4
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
/*  f01120c:	10000001 */ 	b	.L0f011214
/*  f011210:	00000000 */ 	nop
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
/*  f011294:	0c0048f2 */ 	jal	malloc
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
/*  f0112d0:	10000002 */ 	b	.L0f0112dc
/*  f0112d4:	00003025 */ 	or	$a2,$zero,$zero
.L0f0112d8:
/*  f0112d8:	24060023 */ 	addiu	$a2,$zero,0x23
.L0f0112dc:
/*  f0112dc:	10c00009 */ 	beqz	$a2,.L0f011304
/*  f0112e0:	3c05800a */ 	lui	$a1,%hi(var8009dd00)
/*  f0112e4:	3c01800a */ 	lui	$at,%hi(var8009dd10)
/*  f0112e8:	15280003 */ 	bne	$t1,$t0,.L0f0112f8
/*  f0112ec:	ac22dd10 */ 	sw	$v0,%lo(var8009dd10)($at)
/*  f0112f0:	10000002 */ 	b	.L0f0112fc
/*  f0112f4:	00003025 */ 	or	$a2,$zero,$zero
.L0f0112f8:
/*  f0112f8:	24060023 */ 	addiu	$a2,$zero,0x23
.L0f0112fc:
/*  f0112fc:	000678c0 */ 	sll	$t7,$a2,0x3
/*  f011300:	004f2021 */ 	addu	$a0,$v0,$t7
.L0f011304:
/*  f011304:	15280003 */ 	bne	$t1,$t0,.L0f011314
/*  f011308:	24a5dd00 */ 	addiu	$a1,$a1,%lo(var8009dd00)
/*  f01130c:	10000002 */ 	b	.L0f011318
/*  f011310:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f011314:
/*  f011314:	24060019 */ 	addiu	$a2,$zero,0x19
.L0f011318:
/*  f011318:	10c00008 */ 	beqz	$a2,.L0f01133c
/*  f01131c:	3c0b800a */ 	lui	$t3,%hi(var8009dd04)
/*  f011320:	15280003 */ 	bne	$t1,$t0,.L0f011330
/*  f011324:	ace40004 */ 	sw	$a0,0x4($a3)
/*  f011328:	10000002 */ 	b	.L0f011334
/*  f01132c:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f011330:
/*  f011330:	24060019 */ 	addiu	$a2,$zero,0x19
.L0f011334:
/*  f011334:	0006c0c0 */ 	sll	$t8,$a2,0x3
/*  f011338:	00982021 */ 	addu	$a0,$a0,$t8
.L0f01133c:
/*  f01133c:	15280003 */ 	bne	$t1,$t0,.L0f01134c
/*  f011340:	256bdd04 */ 	addiu	$t3,$t3,%lo(var8009dd04)
/*  f011344:	10000002 */ 	b	.L0f011350
/*  f011348:	00003025 */ 	or	$a2,$zero,$zero
.L0f01134c:
/*  f01134c:	24060014 */ 	addiu	$a2,$zero,0x14
.L0f011350:
/*  f011350:	10c00008 */ 	beqz	$a2,.L0f011374
/*  f011354:	00001825 */ 	or	$v1,$zero,$zero
/*  f011358:	15280003 */ 	bne	$t1,$t0,.L0f011368
/*  f01135c:	ace40008 */ 	sw	$a0,0x8($a3)
/*  f011360:	10000002 */ 	b	.L0f01136c
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
/*  f01138c:	10000002 */ 	b	.L0f011398
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
/*  f0113d0:	00000000 */ 	nop
/*  f0113d4:	10000001 */ 	b	.L0f0113dc
/*  f0113d8:	00003025 */ 	or	$a2,$zero,$zero
.L0f0113dc:
/*  f0113dc:	0066082a */ 	slt	$at,$v1,$a2
/*  f0113e0:	5420fff0 */ 	bnezl	$at,.L0f0113a4
/*  f0113e4:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0113e8:	00001825 */ 	or	$v1,$zero,$zero
.L0f0113ec:
/*  f0113ec:	15280003 */ 	bne	$t1,$t0,.L0f0113fc
/*  f0113f0:	24060019 */ 	addiu	$a2,$zero,0x19
/*  f0113f4:	10000001 */ 	b	.L0f0113fc
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
/*  f011434:	00000000 */ 	nop
/*  f011438:	10000001 */ 	b	.L0f011440
/*  f01143c:	24060018 */ 	addiu	$a2,$zero,0x18
.L0f011440:
/*  f011440:	0066082a */ 	slt	$at,$v1,$a2
/*  f011444:	5420fff0 */ 	bnezl	$at,.L0f011408
/*  f011448:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f01144c:	00001825 */ 	or	$v1,$zero,$zero
.L0f011450:
/*  f011450:	15280003 */ 	bne	$t1,$t0,.L0f011460
/*  f011454:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f011458:	10000001 */ 	b	.L0f011460
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
/*  f011494:	00000000 */ 	nop
/*  f011498:	10000001 */ 	b	.L0f0114a0
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
/*  f011504:	00000000 */ 	nop
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
/*  f01152c:	3c018007 */ 	lui	$at,%hi(var800705ac)
/*  f011530:	ac2005ac */ 	sw	$zero,%lo(var800705ac)($at)
/*  f011534:	3c018007 */ 	lui	$at,%hi(var800705b0)
/*  f011538:	ac2005b0 */ 	sw	$zero,%lo(var800705b0)($at)
/*  f01153c:	3c018007 */ 	lui	$at,%hi(var800705b4)
/*  f011540:	ac2005b4 */ 	sw	$zero,%lo(var800705b4)($at)
/*  f011544:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f011548:	3c018007 */ 	lui	$at,%hi(var800705b8)
/*  f01154c:	ac2005b8 */ 	sw	$zero,%lo(var800705b8)($at)
/*  f011550:	3c018007 */ 	lui	$at,%hi(var800705bc)
/*  f011554:	ac2005bc */ 	sw	$zero,%lo(var800705bc)($at)
/*  f011558:	03e00008 */ 	jr	$ra
/*  f01155c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

bool weaponLoadProjectileModels(s32 weaponnum)
{
	bool result = false;
	struct weapon *weapon = g_Weapons[weaponnum];
	s32 i;

	for (i = 0; i != 2; i++) {
		if (weapon->functions[i]) {
			struct weaponfunc *genericfunc = weapon->functions[i];

			if (genericfunc->type == INVENTORYFUNCTYPE_SHOOT_PROJECTILE) {
				struct weaponfunc_shootprojectile *func = (struct weaponfunc_shootprojectile *)genericfunc;

				if (func->projectilemodelnum >= 0) {
					result |= modelLoad(func->projectilemodelnum);
				}
			} else if (genericfunc->type == INVENTORYFUNCTYPE_THROW) {
				struct weaponfunc_throw *func = (struct weaponfunc_throw *)genericfunc;

				if (func->projectilemodelnum >= 0) {
					result |= modelLoad(func->projectilemodelnum);
				}
			}
		}
	}

	return result;
}

void currentPlayerInitEyespy(void)
{
	struct prop *prop;
	struct pad pad;
	struct chrdata *propchr;
	struct chrdata *playerchr;
	static u8 nextpad = 0;

	if (g_Vars.currentplayer->eyespy == NULL) {
		/**
		 * To create the eyespy's prop, a pad must be passed to propAllocateEyespy.
		 * However the eyespy doesn't have a pad because it's held by the
		 * player, so it needs to choose one from the stage. The method used
		 * will increment the chosen pad number each time the stage is loaded
		 * and wrap at 256.
		 *
		 * @bug: This method means if you play G5 Building enough times then
		 * the camspy will start in a trigger point for the mid cutscene,
		 * causing the mid cutscene to play instead of the intro.
		 */
		padUnpack(nextpad++, PADFIELD_ROOM | PADFIELD_POS, &pad);
		prop = propAllocateEyespy(&pad, pad.room);

		if (prop) {
			g_Vars.currentplayer->eyespy = malloc(sizeof(struct eyespy), MEMPOOL_STAGE);

			if (g_Vars.currentplayer->eyespy) {
				g_Vars.currentplayer->eyespy->prop = prop;
				g_Vars.currentplayer->eyespy->look.x = 0;
				g_Vars.currentplayer->eyespy->look.y = 0;
				g_Vars.currentplayer->eyespy->look.z = 1;
				g_Vars.currentplayer->eyespy->up.x = 0;
				g_Vars.currentplayer->eyespy->up.y = 1;
				g_Vars.currentplayer->eyespy->up.z = 0;
				g_Vars.currentplayer->eyespy->theta = 0;
				g_Vars.currentplayer->eyespy->costheta = 1;
				g_Vars.currentplayer->eyespy->sintheta = 0;
				g_Vars.currentplayer->eyespy->verta = 0;
				g_Vars.currentplayer->eyespy->cosverta = 1;
				g_Vars.currentplayer->eyespy->sinverta = 0;
				g_Vars.currentplayer->eyespy->init = true;
				g_Vars.currentplayer->eyespy->initialised = false;
				g_Vars.currentplayer->eyespy->active = false;
				g_Vars.currentplayer->eyespy->buttonheld = false;
				g_Vars.currentplayer->eyespy->camerabuttonheld = false;
				g_Vars.currentplayer->eyespy->bobdir = 1;
				g_Vars.currentplayer->eyespy->bobtimer = 0;
				g_Vars.currentplayer->eyespy->bobactive = true;
				g_Vars.currentplayer->eyespy->vel.x = 0;
				g_Vars.currentplayer->eyespy->vel.y = 0;
				g_Vars.currentplayer->eyespy->vel.z = 0;
				g_Vars.currentplayer->eyespy->speed = 0;
				g_Vars.currentplayer->eyespy->oldground = 0;
				g_Vars.currentplayer->eyespy->height = 0;
				g_Vars.currentplayer->eyespy->gravity = 0;
				g_Vars.currentplayer->eyespy->hit = false;
				g_Vars.currentplayer->eyespy->opendoor = false;
				g_Vars.currentplayer->eyespy->mode = EYESPYMODE_CAMSPY;
				propchr = prop->chr;
				playerchr = g_Vars.currentplayer->prop->chr;
				propchr->team = playerchr->team;

				if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
					g_Vars.currentplayer->eyespy->mode = EYESPYMODE_DRUGSPY;
					g_Weapons[WEAPON_EYESPY]->name = L_GUN_061; // "DrugSpy"
					g_Weapons[WEAPON_EYESPY]->shortname = L_GUN_061; // "DrugSpy"
				} else if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR || stageGetIndex(g_Vars.stagenum) == STAGEINDEX_CHICAGO) {
					g_Vars.currentplayer->eyespy->mode = EYESPYMODE_BOMBSPY;
				} else {
					g_Vars.currentplayer->eyespy->mode = EYESPYMODE_CAMSPY;
				}
			}
		}
	}
}

struct coord var800623a4 = {0, 0, 0};

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel currentPlayerInit
.late_rodata
glabel var7f1a8240
.word currentPlayerInit+0x154
glabel var7f1a8244
.word currentPlayerInit+0x1a0
glabel var7f1a8248
.word currentPlayerInit+0x248
glabel var7f1a824c
.word currentPlayerInit+0x278
glabel var7f1a8250
.word currentPlayerInit+0x280
glabel var7f1a8254
.word currentPlayerInit+0x288
glabel var7f1a8258
.word currentPlayerInit+0x29c
glabel var7f1a825c
.word currentPlayerInit+0x2a4
glabel var7f1a8260
.word currentPlayerInit+0x340
glabel var7f1a8264
.word currentPlayerInit+0x190
glabel var7f1a8268
.word currentPlayerInit+0x190
glabel var7f1a826c
.word currentPlayerInit+0x198
glabel var7f1a8270
.word 0x40c907a9
glabel var7f1a8274
.word 0x40c907a9
glabel var7f1a8278
.word 0x40c907a9
glabel var7f1a827c
.word 0x40c907a9
.text
/*  f011914:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f011918:	3c0f8006 */ 	lui	$t7,0x8006
/*  f01191c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f011920:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f011924:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f011928:	25ef2074 */ 	addiu	$t7,$t7,0x2074
/*  f01192c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f011930:	27ae009c */ 	addiu	$t6,$sp,0x9c
/*  f011934:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f011938:	adc10000 */ 	sw	$at,0x0($t6)
/*  f01193c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f011940:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f011944:	44802000 */ 	mtc1	$zero,$f4
/*  f011948:	adc10008 */ 	sw	$at,0x8($t6)
/*  f01194c:	3c10800a */ 	lui	$s0,0x800a
/*  f011950:	afa00080 */ 	sw	$zero,0x80($sp)
/*  f011954:	8e10d59c */ 	lw	$s0,-0x2a64($s0)
/*  f011958:	a3a0007b */ 	sb	$zero,0x7b($sp)
/*  f01195c:	0fc2f254 */ 	jal	viResetDefaultModeIf4Mb
/*  f011960:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f011964:	0fc63d8b */ 	jal	func0f18e558
/*  f011968:	00000000 */ 	nop
/*  f01196c:	44803000 */ 	mtc1	$zero,$f6
/*  f011970:	3c018007 */ 	lui	$at,0x8007
/*  f011974:	ac200a44 */ 	sw	$zero,0xa44($at)
/*  f011978:	3c01800a */ 	lui	$at,0x800a
/*  f01197c:	e426e388 */ 	swc1	$f6,-0x1c78($at)
/*  f011980:	24030001 */ 	li	$v1,0x1
/*  f011984:	3c018007 */ 	lui	$at,0x8007
/*  f011988:	ac230a0c */ 	sw	$v1,0xa0c($at)
/*  f01198c:	3c018007 */ 	lui	$at,0x8007
/*  f011990:	ac200a18 */ 	sw	$zero,0xa18($at)
/*  f011994:	3c018007 */ 	lui	$at,0x8007
/*  f011998:	ac200a1c */ 	sw	$zero,0xa1c($at)
/*  f01199c:	3c11800a */ 	lui	$s1,0x800a
/*  f0119a0:	3c018007 */ 	lui	$at,0x8007
/*  f0119a4:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f0119a8:	ac200a20 */ 	sw	$zero,0xa20($at)
/*  f0119ac:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0119b0:	3c01800a */ 	lui	$at,0x800a
/*  f0119b4:	3c028007 */ 	lui	$v0,0x8007
/*  f0119b8:	ad401bf0 */ 	sw	$zero,0x1bf0($t2)
/*  f0119bc:	ac20e3d8 */ 	sw	$zero,-0x1c28($at)
/*  f0119c0:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f0119c4:	24420a30 */ 	addiu	$v0,$v0,0xa30
/*  f0119c8:	3c018007 */ 	lui	$at,0x8007
/*  f0119cc:	ad601b78 */ 	sw	$zero,0x1b78($t3)
/*  f0119d0:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0119d4:	00002025 */ 	move	$a0,$zero
/*  f0119d8:	ad801bd4 */ 	sw	$zero,0x1bd4($t4)
/*  f0119dc:	ac430000 */ 	sw	$v1,0x0($v0)
/*  f0119e0:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f0119e4:	ac430008 */ 	sw	$v1,0x8($v0)
/*  f0119e8:	ac43000c */ 	sw	$v1,0xc($v0)
/*  f0119ec:	0fc2e6d7 */ 	jal	setTickMode
/*  f0119f0:	ac200a40 */ 	sw	$zero,0xa40($at)
/*  f0119f4:	3c018007 */ 	lui	$at,0x8007
/*  f0119f8:	ac200a24 */ 	sw	$zero,0xa24($at)
/*  f0119fc:	3c018007 */ 	lui	$at,0x8007
/*  f011a00:	ac200a28 */ 	sw	$zero,0xa28($at)
/*  f011a04:	3c018007 */ 	lui	$at,0x8007
/*  f011a08:	ac200a2c */ 	sw	$zero,0xa2c($at)
/*  f011a0c:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011a10:	44804000 */ 	mtc1	$zero,$f8
/*  f011a14:	3c01800a */ 	lui	$at,0x800a
/*  f011a18:	ada01b7c */ 	sw	$zero,0x1b7c($t5)
/*  f011a1c:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f011a20:	e7281b80 */ 	swc1	$f8,0x1b80($t9)
/*  f011a24:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011a28:	af001b88 */ 	sw	$zero,0x1b88($t8)
/*  f011a2c:	ac20e344 */ 	sw	$zero,-0x1cbc($at)
/*  f011a30:	3c01800a */ 	lui	$at,0x800a
/*  f011a34:	120000a1 */ 	beqz	$s0,.PF0f011cbc
/*  f011a38:	ac20e340 */ 	sw	$zero,-0x1cc0($at)
/*  f011a3c:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f011a40:	2401000c */ 	li	$at,0xc
/*  f011a44:	1041009d */ 	beq	$v0,$at,.PF0f011cbc
/*  f011a48:	2c41000c */ 	sltiu	$at,$v0,0xc
.PF0f011a4c:
/*  f011a4c:	10200096 */ 	beqz	$at,.PF0f011ca8
/*  f011a50:	00027080 */ 	sll	$t6,$v0,0x2
/*  f011a54:	3c017f1b */ 	lui	$at,0x7f1b
/*  f011a58:	002e0821 */ 	addu	$at,$at,$t6
/*  f011a5c:	8c2e9450 */ 	lw	$t6,-0x6bb0($at)
/*  f011a60:	01c00008 */ 	jr	$t6
/*  f011a64:	00000000 */ 	nop
/*  f011a68:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f011a6c:	3c02800a */ 	lui	$v0,0x800a
/*  f011a70:	15e0000a */ 	bnez	$t7,.PF0f011a9c
/*  f011a74:	00000000 */ 	nop
/*  f011a78:	8c42e3d8 */ 	lw	$v0,-0x1c28($v0)
/*  f011a7c:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011a80:	3c01800a */ 	lui	$at,0x800a
/*  f011a84:	00025040 */ 	sll	$t2,$v0,0x1
/*  f011a88:	002a0821 */ 	addu	$at,$at,$t2
/*  f011a8c:	a429e3a8 */ 	sh	$t1,-0x1c58($at)
/*  f011a90:	3c01800a */ 	lui	$at,0x800a
/*  f011a94:	244b0001 */ 	addiu	$t3,$v0,0x1
/*  f011a98:	ac2be3d8 */ 	sw	$t3,-0x1c28($at)
.PF0f011a9c:
/*  f011a9c:	10000083 */ 	b	.PF0f011cac
/*  f011aa0:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011aa4:	10000081 */ 	b	.PF0f011cac
/*  f011aa8:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011aac:	1000007f */ 	b	.PF0f011cac
/*  f011ab0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011ab4:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f011ab8:	15800026 */ 	bnez	$t4,.PF0f011b54
/*  f011abc:	00000000 */ 	nop
/*  f011ac0:	8e2d02a8 */ 	lw	$t5,0x2a8($s1)
/*  f011ac4:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f011ac8:	11b90022 */ 	beq	$t5,$t9,.PF0f011b54
/*  f011acc:	00000000 */ 	nop
/*  f011ad0:	0fc04560 */ 	jal	weaponLoadProjectileModels
/*  f011ad4:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011ad8:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011adc:	04800008 */ 	bltz	$a0,.PF0f011b00
/*  f011ae0:	00000000 */ 	nop
/*  f011ae4:	0fc04560 */ 	jal	weaponLoadProjectileModels
/*  f011ae8:	00000000 */ 	nop
/*  f011aec:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011af0:	0fc44a42 */ 	jal	invGiveDoubleWeapon
/*  f011af4:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f011af8:	10000004 */ 	b	.PF0f011b0c
/*  f011afc:	8fb80080 */ 	lw	$t8,0x80($sp)
.PF0f011b00:
/*  f011b00:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011b04:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011b08:	8fb80080 */ 	lw	$t8,0x80($sp)
.PF0f011b0c:
/*  f011b0c:	240a0001 */ 	li	$t2,0x1
/*  f011b10:	5700000c */ 	bnezl	$t8,.PF0f011b44
/*  f011b14:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011b18:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f011b1c:	3c01800a */ 	lui	$at,0x800a
/*  f011b20:	240f0001 */ 	li	$t7,0x1
/*  f011b24:	ac2ee340 */ 	sw	$t6,-0x1cc0($at)
/*  f011b28:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011b2c:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f011b30:	3c01800a */ 	lui	$at,0x800a
/*  f011b34:	04820003 */ 	bltzl	$a0,.PF0f011b44
/*  f011b38:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011b3c:	ac24e344 */ 	sw	$a0,-0x1cbc($at)
/*  f011b40:	8e090004 */ 	lw	$t1,0x4($s0)
.PF0f011b44:
/*  f011b44:	2401002e */ 	li	$at,0x2e
/*  f011b48:	15210002 */ 	bne	$t1,$at,.PF0f011b54
/*  f011b4c:	00000000 */ 	nop
/*  f011b50:	a3aa007b */ 	sb	$t2,0x7b($sp)
.PF0f011b54:
/*  f011b54:	10000055 */ 	b	.PF0f011cac
/*  f011b58:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f011b5c:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f011b60:	15600008 */ 	bnez	$t3,.PF0f011b84
/*  f011b64:	00000000 */ 	nop
/*  f011b68:	8e2c02a8 */ 	lw	$t4,0x2a8($s1)
/*  f011b6c:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011b70:	118d0004 */ 	beq	$t4,$t5,.PF0f011b84
/*  f011b74:	00000000 */ 	nop
/*  f011b78:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011b7c:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011b80:	8e050008 */ 	lw	$a1,0x8($s0)
.PF0f011b84:
/*  f011b84:	10000049 */ 	b	.PF0f011cac
/*  f011b88:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f011b8c:	10000047 */ 	b	.PF0f011cac
/*  f011b90:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f011b94:	10000045 */ 	b	.PF0f011cac
/*  f011b98:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011b9c:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f011ba0:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011ba4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011ba8:	10000040 */ 	b	.PF0f011cac
/*  f011bac:	af190324 */ 	sw	$t9,0x324($t8)
/*  f011bb0:	1000003e */ 	b	.PF0f011cac
/*  f011bb4:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f011bb8:	44805000 */ 	mtc1	$zero,$f10
/*  f011bbc:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f011bc0:	2401003c */ 	li	$at,0x3c
/*  f011bc4:	e5ca1b80 */ 	swc1	$f10,0x1b80($t6)
/*  f011bc8:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011bcc:	5880000f */ 	blezl	$a0,.PF0f011c0c
/*  f011bd0:	8e030004 */ 	lw	$v1,0x4($s0)
/*  f011bd4:	0081001a */ 	div	$zero,$a0,$at
/*  f011bd8:	00007810 */ 	mfhi	$t7
/*  f011bdc:	000f48c0 */ 	sll	$t1,$t7,0x3
/*  f011be0:	012f4823 */ 	subu	$t1,$t1,$t7
/*  f011be4:	00094940 */ 	sll	$t1,$t1,0x5
/*  f011be8:	012f4821 */ 	addu	$t1,$t1,$t7
/*  f011bec:	00094900 */ 	sll	$t1,$t1,0x4
/*  f011bf0:	44899000 */ 	mtc1	$t1,$f18
/*  f011bf4:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011bf8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f011bfc:	c4501b80 */ 	lwc1	$f16,0x1b80($v0)
/*  f011c00:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f011c04:	e4461b80 */ 	swc1	$f6,0x1b80($v0)
/*  f011c08:	8e030004 */ 	lw	$v1,0x4($s0)
.PF0f011c0c:
/*  f011c0c:	2401000c */ 	li	$at,0xc
/*  f011c10:	1860000e */ 	blez	$v1,.PF0f011c4c
/*  f011c14:	00000000 */ 	nop
/*  f011c18:	0061001a */ 	div	$zero,$v1,$at
/*  f011c1c:	00005010 */ 	mfhi	$t2
/*  f011c20:	3c010003 */ 	lui	$at,0x3
/*  f011c24:	34214bc0 */ 	ori	$at,$at,0x4bc0
/*  f011c28:	01410019 */ 	multu	$t2,$at
/*  f011c2c:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011c30:	c4481b80 */ 	lwc1	$f8,0x1b80($v0)
/*  f011c34:	00005812 */ 	mflo	$t3
/*  f011c38:	448b5000 */ 	mtc1	$t3,$f10
/*  f011c3c:	00000000 */ 	nop
/*  f011c40:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f011c44:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f011c48:	e4501b80 */ 	swc1	$f16,0x1b80($v0)
.PF0f011c4c:
/*  f011c4c:	10000017 */ 	b	.PF0f011cac
/*  f011c50:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011c54:	3c0c800a */ 	lui	$t4,0x800a
/*  f011c58:	8d8cd5b0 */ 	lw	$t4,-0x2a50($t4)
/*  f011c5c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f011c60:	3c018007 */ 	lui	$at,0x8007
/*  f011c64:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f011c68:	ac220a20 */ 	sw	$v0,0xa20($at)
/*  f011c6c:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f011c70:	57200005 */ 	bnezl	$t9,.PF0f011c88
/*  f011c74:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f011c78:	94580002 */ 	lhu	$t8,0x2($v0)
/*  f011c7c:	13000008 */ 	beqz	$t8,.PF0f011ca0
/*  f011c80:	00000000 */ 	nop
/*  f011c84:	944e000c */ 	lhu	$t6,0xc($v0)
.PF0f011c88:
/*  f011c88:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f011c8c:	55c0fffe */ 	bnezl	$t6,.PF0f011c88
/*  f011c90:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f011c94:	944f0002 */ 	lhu	$t7,0x2($v0)
/*  f011c98:	55e0fffb */ 	bnezl	$t7,.PF0f011c88
/*  f011c9c:	944e000c */ 	lhu	$t6,0xc($v0)
.PF0f011ca0:
/*  f011ca0:	10000002 */ 	b	.PF0f011cac
/*  f011ca4:	26100008 */ 	addiu	$s0,$s0,0x8
.PF0f011ca8:
/*  f011ca8:	26100004 */ 	addiu	$s0,$s0,0x4
.PF0f011cac:
/*  f011cac:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f011cb0:	2401000c */ 	li	$at,0xc
/*  f011cb4:	5441ff65 */ 	bnel	$v0,$at,.PF0f011a4c
/*  f011cb8:	2c41000c */ 	sltiu	$at,$v0,0xc
.PF0f011cbc:
/*  f011cbc:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011cc0:	24040001 */ 	li	$a0,0x1
/*  f011cc4:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011cc8:	24040008 */ 	li	$a0,0x8
/*  f011ccc:	10400006 */ 	beqz	$v0,.PF0f011ce8
/*  f011cd0:	00000000 */ 	nop
/*  f011cd4:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011cd8:	24040009 */ 	li	$a0,0x9
/*  f011cdc:	2404000a */ 	li	$a0,0xa
/*  f011ce0:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011ce4:	24050050 */ 	li	$a1,0x50
.PF0f011ce8:
/*  f011ce8:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011cec:	24040009 */ 	li	$a0,0x9
/*  f011cf0:	10400006 */ 	beqz	$v0,.PF0f011d0c
/*  f011cf4:	00000000 */ 	nop
/*  f011cf8:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011cfc:	24040016 */ 	li	$a0,0x16
/*  f011d00:	24040006 */ 	li	$a0,0x6
/*  f011d04:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011d08:	24050050 */ 	li	$a1,0x50
.PF0f011d0c:
/*  f011d0c:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011d10:	24040001 */ 	li	$a0,0x1
/*  f011d14:	10400006 */ 	beqz	$v0,.PF0f011d30
/*  f011d18:	00000000 */ 	nop
/*  f011d1c:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011d20:	24040031 */ 	li	$a0,0x31
/*  f011d24:	24040014 */ 	li	$a0,0x14
/*  f011d28:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011d2c:	24051770 */ 	li	$a1,0x1770
.PF0f011d30:
/*  f011d30:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011d34:	24040015 */ 	li	$a0,0x15
/*  f011d38:	10400003 */ 	beqz	$v0,.PF0f011d48
/*  f011d3c:	00000000 */ 	nop
/*  f011d40:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011d44:	2404002d */ 	li	$a0,0x2d
.PF0f011d48:
/*  f011d48:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011d4c:	2404001a */ 	li	$a0,0x1a
/*  f011d50:	10400003 */ 	beqz	$v0,.PF0f011d60
/*  f011d54:	00000000 */ 	nop
/*  f011d58:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011d5c:	24040037 */ 	li	$a0,0x37
.PF0f011d60:
/*  f011d60:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011d64:	2404001b */ 	li	$a0,0x1b
/*  f011d68:	10400006 */ 	beqz	$v0,.PF0f011d84
/*  f011d6c:	00000000 */ 	nop
/*  f011d70:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011d74:	24040018 */ 	li	$a0,0x18
/*  f011d78:	24040008 */ 	li	$a0,0x8
/*  f011d7c:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011d80:	2405000a */ 	li	$a1,0xa
.PF0f011d84:
/*  f011d84:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011d88:	2404001c */ 	li	$a0,0x1c
/*  f011d8c:	10400006 */ 	beqz	$v0,.PF0f011da8
/*  f011d90:	00000000 */ 	nop
/*  f011d94:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011d98:	24040015 */ 	li	$a0,0x15
/*  f011d9c:	24040004 */ 	li	$a0,0x4
/*  f011da0:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011da4:	240500c8 */ 	li	$a1,0xc8
.PF0f011da8:
/*  f011da8:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011dac:	2404001d */ 	li	$a0,0x1d
/*  f011db0:	10400003 */ 	beqz	$v0,.PF0f011dc0
/*  f011db4:	00000000 */ 	nop
/*  f011db8:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011dbc:	2404002f */ 	li	$a0,0x2f
.PF0f011dc0:
/*  f011dc0:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011dc4:	2404001e */ 	li	$a0,0x1e
/*  f011dc8:	10400009 */ 	beqz	$v0,.PF0f011df0
/*  f011dcc:	00000000 */ 	nop
/*  f011dd0:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011dd4:	24040012 */ 	li	$a0,0x12
/*  f011dd8:	24040004 */ 	li	$a0,0x4
/*  f011ddc:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011de0:	240500c8 */ 	li	$a1,0xc8
/*  f011de4:	2404000b */ 	li	$a0,0xb
/*  f011de8:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011dec:	24050014 */ 	li	$a1,0x14
.PF0f011df0:
/*  f011df0:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011df4:	2404001f */ 	li	$a0,0x1f
/*  f011df8:	10400006 */ 	beqz	$v0,.PF0f011e14
/*  f011dfc:	00000000 */ 	nop
/*  f011e00:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011e04:	2404000e */ 	li	$a0,0xe
/*  f011e08:	24040002 */ 	li	$a0,0x2
/*  f011e0c:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011e10:	240500c8 */ 	li	$a1,0xc8
.PF0f011e14:
/*  f011e14:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011e18:	24040020 */ 	li	$a0,0x20
/*  f011e1c:	10400006 */ 	beqz	$v0,.PF0f011e38
/*  f011e20:	00000000 */ 	nop
/*  f011e24:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011e28:	24040007 */ 	li	$a0,0x7
/*  f011e2c:	24040001 */ 	li	$a0,0x1
/*  f011e30:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011e34:	240500c8 */ 	li	$a1,0xc8
.PF0f011e38:
/*  f011e38:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011e3c:	24040021 */ 	li	$a0,0x21
/*  f011e40:	54400005 */ 	bnezl	$v0,.PF0f011e58
/*  f011e44:	24040016 */ 	li	$a0,0x16
/*  f011e48:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011e4c:	24040003 */ 	li	$a0,0x3
/*  f011e50:	10400009 */ 	beqz	$v0,.PF0f011e78
/*  f011e54:	24040016 */ 	li	$a0,0x16
.PF0f011e58:
/*  f011e58:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011e5c:	24050004 */ 	li	$a1,0x4
/*  f011e60:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011e64:	24040021 */ 	li	$a0,0x21
/*  f011e68:	10400003 */ 	beqz	$v0,.PF0f011e78
/*  f011e6c:	00000000 */ 	nop
/*  f011e70:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011e74:	2404002c */ 	li	$a0,0x2c
.PF0f011e78:
/*  f011e78:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011e7c:	24040022 */ 	li	$a0,0x22
/*  f011e80:	10400006 */ 	beqz	$v0,.PF0f011e9c
/*  f011e84:	00000000 */ 	nop
/*  f011e88:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011e8c:	24040024 */ 	li	$a0,0x24
/*  f011e90:	24040001 */ 	li	$a0,0x1
/*  f011e94:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011e98:	240500c8 */ 	li	$a1,0xc8
.PF0f011e9c:
/*  f011e9c:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011ea0:	24040023 */ 	li	$a0,0x23
/*  f011ea4:	10400006 */ 	beqz	$v0,.PF0f011ec0
/*  f011ea8:	00000000 */ 	nop
/*  f011eac:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011eb0:	24040025 */ 	li	$a0,0x25
/*  f011eb4:	24040004 */ 	li	$a0,0x4
/*  f011eb8:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011ebc:	240500c8 */ 	li	$a1,0xc8
.PF0f011ec0:
/*  f011ec0:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011ec4:	24040024 */ 	li	$a0,0x24
/*  f011ec8:	10400006 */ 	beqz	$v0,.PF0f011ee4
/*  f011ecc:	00000000 */ 	nop
/*  f011ed0:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011ed4:	24040026 */ 	li	$a0,0x26
/*  f011ed8:	24040002 */ 	li	$a0,0x2
/*  f011edc:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011ee0:	240500c8 */ 	li	$a1,0xc8
.PF0f011ee4:
/*  f011ee4:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011ee8:	24040025 */ 	li	$a0,0x25
/*  f011eec:	10400006 */ 	beqz	$v0,.PF0f011f08
/*  f011ef0:	00000000 */ 	nop
/*  f011ef4:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011ef8:	24040027 */ 	li	$a0,0x27
/*  f011efc:	24040004 */ 	li	$a0,0x4
/*  f011f00:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011f04:	240500c8 */ 	li	$a1,0xc8
.PF0f011f08:
/*  f011f08:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011f0c:	24040026 */ 	li	$a0,0x26
/*  f011f10:	10400006 */ 	beqz	$v0,.PF0f011f2c
/*  f011f14:	00000000 */ 	nop
/*  f011f18:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011f1c:	24040028 */ 	li	$a0,0x28
/*  f011f20:	24040002 */ 	li	$a0,0x2
/*  f011f24:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011f28:	240500c8 */ 	li	$a1,0xc8
.PF0f011f2c:
/*  f011f2c:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011f30:	24040027 */ 	li	$a0,0x27
/*  f011f34:	10400006 */ 	beqz	$v0,.PF0f011f50
/*  f011f38:	00000000 */ 	nop
/*  f011f3c:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011f40:	24040029 */ 	li	$a0,0x29
/*  f011f44:	24040002 */ 	li	$a0,0x2
/*  f011f48:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011f4c:	240500c8 */ 	li	$a1,0xc8
.PF0f011f50:
/*  f011f50:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011f54:	24040028 */ 	li	$a0,0x28
/*  f011f58:	10400006 */ 	beqz	$v0,.PF0f011f74
/*  f011f5c:	00000000 */ 	nop
/*  f011f60:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011f64:	2404002a */ 	li	$a0,0x2a
/*  f011f68:	24040004 */ 	li	$a0,0x4
/*  f011f6c:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011f70:	240500c8 */ 	li	$a1,0xc8
.PF0f011f74:
/*  f011f74:	0fc41dd5 */ 	jal	cheatIsActive
/*  f011f78:	24040029 */ 	li	$a0,0x29
/*  f011f7c:	50400007 */ 	beqzl	$v0,.PF0f011f9c
/*  f011f80:	8fa90080 */ 	lw	$t1,0x80($sp)
/*  f011f84:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f011f88:	2404002b */ 	li	$a0,0x2b
/*  f011f8c:	24040002 */ 	li	$a0,0x2
/*  f011f90:	0fc2a69d */ 	jal	bgunSetAmmoQuantity
/*  f011f94:	240500c8 */ 	li	$a1,0xc8
/*  f011f98:	8fa90080 */ 	lw	$t1,0x80($sp)
.PF0f011f9c:
/*  f011f9c:	15200003 */ 	bnez	$t1,.PF0f011fac
/*  f011fa0:	240a0001 */ 	li	$t2,0x1
/*  f011fa4:	3c01800a */ 	lui	$at,0x800a
/*  f011fa8:	ac2ae340 */ 	sw	$t2,-0x1cc0($at)
.PF0f011fac:
/*  f011fac:	0fc1816e */ 	jal	propAllocate
/*  f011fb0:	00000000 */ 	nop
/*  f011fb4:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f011fb8:	24190006 */ 	li	$t9,0x6
/*  f011fbc:	ad6200bc */ 	sw	$v0,0xbc($t3)
/*  f011fc0:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f011fc4:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f011fc8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f011fcc:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011fd0:	8f0e00bc */ 	lw	$t6,0xbc($t8)
/*  f011fd4:	a1d90000 */ 	sb	$t9,0x0($t6)
/*  f011fd8:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f011fdc:	0fc181c7 */ 	jal	propActivate
/*  f011fe0:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f011fe4:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f011fe8:	0fc18154 */ 	jal	propEnable
/*  f011fec:	8d2400bc */ 	lw	$a0,0xbc($t1)
/*  f011ff0:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f011ff4:	00002825 */ 	move	$a1,$zero
/*  f011ff8:	0fc081dd */ 	jal	chrInit
/*  f011ffc:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f012000:	8e2b0298 */ 	lw	$t3,0x298($s1)
/*  f012004:	05620008 */ 	bltzl	$t3,.PF0f012028
/*  f012008:	8e2e029c */ 	lw	$t6,0x29c($s1)
/*  f01200c:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f012010:	240c0010 */ 	li	$t4,0x10
/*  f012014:	8db800bc */ 	lw	$t8,0xbc($t5)
/*  f012018:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f01201c:	10000029 */ 	b	.PF0f0120c4
/*  f012020:	a32c0125 */ 	sb	$t4,0x125($t9)
/*  f012024:	8e2e029c */ 	lw	$t6,0x29c($s1)
.PF0f012028:
/*  f012028:	05c20010 */ 	bltzl	$t6,.PF0f01206c
/*  f01202c:	8e390314 */ 	lw	$t9,0x314($s1)
/*  f012030:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f012034:	8e2f02a0 */ 	lw	$t7,0x2a0($s1)
/*  f012038:	55e20007 */ 	bnel	$t7,$v0,.PF0f012058
/*  f01203c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f012040:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f012044:	24090010 */ 	li	$t1,0x10
/*  f012048:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f01204c:	1000001d */ 	b	.PF0f0120c4
/*  f012050:	a1690125 */ 	sb	$t1,0x125($t3)
/*  f012054:	8c5800bc */ 	lw	$t8,0xbc($v0)
.PF0f012058:
/*  f012058:	240d0002 */ 	li	$t5,0x2
/*  f01205c:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f012060:	10000018 */ 	b	.PF0f0120c4
/*  f012064:	a18d0125 */ 	sb	$t5,0x125($t4)
/*  f012068:	8e390314 */ 	lw	$t9,0x314($s1)
.PF0f01206c:
/*  f01206c:	53200011 */ 	beqzl	$t9,.PF0f0120b4
/*  f012070:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012074:	8e2e0288 */ 	lw	$t6,0x288($s1)
/*  f012078:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f01207c:	3c09800b */ 	lui	$t1,0x800b
/*  f012080:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f012084:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f012088:	240b0001 */ 	li	$t3,0x1
/*  f01208c:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f012090:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f012094:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f012098:	012a4821 */ 	addu	$t1,$t1,$t2
/*  f01209c:	9129cd69 */ 	lbu	$t1,-0x3297($t1)
/*  f0120a0:	8d990004 */ 	lw	$t9,0x4($t4)
/*  f0120a4:	012bc004 */ 	sllv	$t8,$t3,$t1
/*  f0120a8:	10000006 */ 	b	.PF0f0120c4
/*  f0120ac:	a3380125 */ 	sb	$t8,0x125($t9)
/*  f0120b0:	8e2f0284 */ 	lw	$t7,0x284($s1)
.PF0f0120b4:
/*  f0120b4:	240e0010 */ 	li	$t6,0x10
/*  f0120b8:	8dea00bc */ 	lw	$t2,0xbc($t7)
/*  f0120bc:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f0120c0:	a16e0125 */ 	sb	$t6,0x125($t3)
.PF0f0120c4:
/*  f0120c4:	93a9007b */ 	lbu	$t1,0x7b($sp)
/*  f0120c8:	11200003 */ 	beqz	$t1,.PF0f0120d8
/*  f0120cc:	00000000 */ 	nop
/*  f0120d0:	0fc04594 */ 	jal	currentPlayerInitEyespy
/*  f0120d4:	00000000 */ 	nop
.PF0f0120d8:
/*  f0120d8:	3c0d800a */ 	lui	$t5,0x800a
/*  f0120dc:	8dade3d8 */ 	lw	$t5,-0x1c28($t5)
/*  f0120e0:	59a0002f */ 	blezl	$t5,.PF0f0121a0
/*  f0120e4:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f0120e8:	8e2c0298 */ 	lw	$t4,0x298($s1)
/*  f0120ec:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0120f0:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0120f4:	0580000a */ 	bltz	$t4,.PF0f012120
/*  f0120f8:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0120fc:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f012100:	44816000 */ 	mtc1	$at,$f12
/*  f012104:	0fc61c60 */ 	jal	scenarioChooseSpawnLocation
/*  f012108:	8f0700bc */ 	lw	$a3,0xbc($t8)
/*  f01210c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f012110:	c4249480 */ 	lwc1	$f4,-0x6b80($at)
/*  f012114:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f012118:	10000020 */ 	b	.PF0f01219c
/*  f01211c:	e7a60088 */ 	swc1	$f6,0x88($sp)
.PF0f012120:
/*  f012120:	8e39029c */ 	lw	$t9,0x29c($s1)
/*  f012124:	3c0141f0 */ 	lui	$at,0x41f0
/*  f012128:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f01212c:	0720000c */ 	bltz	$t9,.PF0f012160
/*  f012130:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f012134:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012138:	44816000 */ 	mtc1	$at,$f12
/*  f01213c:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f012140:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f012144:	0fc61c60 */ 	jal	scenarioChooseSpawnLocation
/*  f012148:	8de700bc */ 	lw	$a3,0xbc($t7)
/*  f01214c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f012150:	c42a9484 */ 	lwc1	$f10,-0x6b7c($at)
/*  f012154:	46005201 */ 	sub.s	$f8,$f10,$f0
/*  f012158:	10000010 */ 	b	.PF0f01219c
/*  f01215c:	e7a80088 */ 	swc1	$f8,0x88($sp)
.PF0f012160:
/*  f012160:	8e2a0314 */ 	lw	$t2,0x314($s1)
/*  f012164:	240e0001 */ 	li	$t6,0x1
/*  f012168:	3c01800a */ 	lui	$at,0x800a
/*  f01216c:	55400003 */ 	bnezl	$t2,.PF0f01217c
/*  f012170:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012174:	ac2ee3d8 */ 	sw	$t6,-0x1c28($at)
/*  f012178:	8e2b0284 */ 	lw	$t3,0x284($s1)
.PF0f01217c:
/*  f01217c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f012180:	44816000 */ 	mtc1	$at,$f12
/*  f012184:	0fc61c60 */ 	jal	scenarioChooseSpawnLocation
/*  f012188:	8d6700bc */ 	lw	$a3,0xbc($t3)
/*  f01218c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f012190:	c4329488 */ 	lwc1	$f18,-0x6b78($at)
/*  f012194:	46009401 */ 	sub.s	$f16,$f18,$f0
/*  f012198:	e7b00088 */ 	swc1	$f16,0x88($sp)
.PF0f01219c:
/*  f01219c:	8e220284 */ 	lw	$v0,0x284($s1)
.PF0f0121a0:
/*  f0121a0:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f0121a4:	3c0541f0 */ 	lui	$a1,0x41f0
/*  f0121a8:	2449161e */ 	addiu	$t1,$v0,0x161e
/*  f0121ac:	244d161c */ 	addiu	$t5,$v0,0x161c
/*  f0121b0:	244c19b0 */ 	addiu	$t4,$v0,0x19b0
/*  f0121b4:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0121b8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0121bc:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0121c0:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0121c4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0121c8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0121cc:	0c00a6ac */ 	jal	cdFindGroundY
/*  f0121d0:	2447161a */ 	addiu	$a3,$v0,0x161a
/*  f0121d4:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f0121d8:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0121dc:	44814000 */ 	mtc1	$at,$f8
/*  f0121e0:	c44419c4 */ 	lwc1	$f4,0x19c4($v0)
/*  f0121e4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0121e8:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0121ec:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f0121f0:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f0121f4:	e4400074 */ 	swc1	$f0,0x74($v0)
/*  f0121f8:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0121fc:	e7000078 */ 	swc1	$f0,0x78($t8)
/*  f012200:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f012204:	c430948c */ 	lwc1	$f16,-0x6b74($at)
/*  f012208:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f01220c:	46085482 */ 	mul.s	$f18,$f10,$f8
/*  f012210:	46109103 */ 	div.s	$f4,$f18,$f16
/*  f012214:	e7240144 */ 	swc1	$f4,0x144($t9)
/*  f012218:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f01221c:	0fc2e2b0 */ 	jal	func0f0b85a0
/*  f012220:	2484036c */ 	addiu	$a0,$a0,0x36c
/*  f012224:	0c00685b */ 	jal	sinf
/*  f012228:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f01222c:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012230:	46000187 */ 	neg.s	$f6,$f0
/*  f012234:	44805000 */ 	mtc1	$zero,$f10
/*  f012238:	e5e6036c */ 	swc1	$f6,0x36c($t7)
/*  f01223c:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012240:	e54a0370 */ 	swc1	$f10,0x370($t2)
/*  f012244:	0c006858 */ 	jal	cosf
/*  f012248:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f01224c:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f012250:	e5c00374 */ 	swc1	$f0,0x374($t6)
/*  f012254:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012258:	c7a2009c */ 	lwc1	$f2,0x9c($sp)
/*  f01225c:	e5620310 */ 	swc1	$f2,0x310($t3)
/*  f012260:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f012264:	8d2d00bc */ 	lw	$t5,0xbc($t1)
/*  f012268:	e5a20008 */ 	swc1	$f2,0x8($t5)
/*  f01226c:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f012270:	c7a200a0 */ 	lwc1	$f2,0xa0($sp)
/*  f012274:	e5820314 */ 	swc1	$f2,0x314($t4)
/*  f012278:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f01227c:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f012280:	e722000c */ 	swc1	$f2,0xc($t9)
/*  f012284:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012288:	c7a200a4 */ 	lwc1	$f2,0xa4($sp)
/*  f01228c:	e5e20318 */ 	swc1	$f2,0x318($t7)
/*  f012290:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012294:	8d4e00bc */ 	lw	$t6,0xbc($t2)
/*  f012298:	e5c20010 */ 	swc1	$f2,0x10($t6)
/*  f01229c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f0122a0:	0fc197b5 */ 	jal	propDeregisterRooms
/*  f0122a4:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f0122a8:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f0122ac:	87a9008c */ 	lh	$t1,0x8c($sp)
/*  f0122b0:	2418ffff */ 	li	$t8,-1
/*  f0122b4:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f0122b8:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f0122bc:	a5890028 */ 	sh	$t1,0x28($t4)
/*  f0122c0:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0122c4:	8f2f00bc */ 	lw	$t7,0xbc($t9)
/*  f0122c8:	a5f8002a */ 	sh	$t8,0x2a($t7)
/*  f0122cc:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f0122d0:	87a7008c */ 	lh	$a3,0x8c($sp)
/*  f0122d4:	24450394 */ 	addiu	$a1,$v0,0x394
/*  f0122d8:	0fc30864 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0122dc:	24460388 */ 	addiu	$a2,$v0,0x388
/*  f0122e0:	0fc0797c */ 	jal	getNumChrSlots
/*  f0122e4:	00000000 */ 	nop
/*  f0122e8:	18400026 */ 	blez	$v0,.PF0f012384
/*  f0122ec:	00402025 */ 	move	$a0,$v0
/*  f0122f0:	000428c0 */ 	sll	$a1,$a0,0x3
/*  f0122f4:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f0122f8:	00052880 */ 	sll	$a1,$a1,0x2
/*  f0122fc:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f012300:	00052880 */ 	sll	$a1,$a1,0x2
/*  f012304:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f012308:	3c068006 */ 	lui	$a2,0x8006
/*  f01230c:	24c62668 */ 	addiu	$a2,$a2,0x2668
/*  f012310:	000528c0 */ 	sll	$a1,$a1,0x3
/*  f012314:	00001025 */ 	move	$v0,$zero
/*  f012318:	24080048 */ 	li	$t0,0x48
/*  f01231c:	2407fffe */ 	li	$a3,-2
/*  f012320:	8cca0000 */ 	lw	$t2,0x0($a2)
.PF0f012324:
/*  f012324:	004a1821 */ 	addu	$v1,$v0,$t2
/*  f012328:	846e017e */ 	lh	$t6,0x17e($v1)
/*  f01232c:	24420368 */ 	addiu	$v0,$v0,0x368
/*  f012330:	54ee0012 */ 	bnel	$a3,$t6,.PF0f01237c
/*  f012334:	0045082a */ 	slt	$at,$v0,$a1
/*  f012338:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f01233c:	8e290338 */ 	lw	$t1,0x338($s1)
/*  f012340:	8d6d00bc */ 	lw	$t5,0xbc($t3)
/*  f012344:	01a96023 */ 	subu	$t4,$t5,$t1
/*  f012348:	0188001a */ 	div	$zero,$t4,$t0
/*  f01234c:	0000c812 */ 	mflo	$t9
/*  f012350:	a479017e */ 	sh	$t9,0x17e($v1)
/*  f012354:	15000002 */ 	bnez	$t0,.PF0f012360
/*  f012358:	00000000 */ 	nop
/*  f01235c:	0007000d */ 	break	0x7
.PF0f012360:
/*  f012360:	2401ffff */ 	li	$at,-1
/*  f012364:	15010004 */ 	bne	$t0,$at,.PF0f012378
/*  f012368:	3c018000 */ 	lui	$at,0x8000
/*  f01236c:	15810002 */ 	bne	$t4,$at,.PF0f012378
/*  f012370:	00000000 */ 	nop
/*  f012374:	0006000d */ 	break	0x6
.PF0f012378:
/*  f012378:	0045082a */ 	slt	$at,$v0,$a1
.PF0f01237c:
/*  f01237c:	5420ffe9 */ 	bnezl	$at,.PF0f012324
/*  f012380:	8cca0000 */ 	lw	$t2,0x0($a2)
.PF0f012384:
/*  f012384:	0fc32f95 */ 	jal	bmove0f0cb8c4
/*  f012388:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f01238c:	8e380318 */ 	lw	$t8,0x318($s1)
/*  f012390:	13000005 */ 	beqz	$t8,.PF0f0123a8
/*  f012394:	00000000 */ 	nop
/*  f012398:	0fc2e6e5 */ 	jal	func0f0b9674
/*  f01239c:	00000000 */ 	nop
/*  f0123a0:	10000003 */ 	b	.PF0f0123b0
/*  f0123a4:	00000000 */ 	nop
.PF0f0123a8:
/*  f0123a8:	0fc2e7d0 */ 	jal	func0f0b9a20
/*  f0123ac:	00000000 */ 	nop
.PF0f0123b0:
/*  f0123b0:	3c048007 */ 	lui	$a0,0x8007
/*  f0123b4:	24840a48 */ 	addiu	$a0,$a0,0xa48
/*  f0123b8:	00007840 */ 	sll	$t7,$zero,0x1
/*  f0123bc:	008f5021 */ 	addu	$t2,$a0,$t7
/*  f0123c0:	854e0000 */ 	lh	$t6,0x0($t2)
/*  f0123c4:	3c038007 */ 	lui	$v1,0x8007
/*  f0123c8:	24630a5c */ 	addiu	$v1,$v1,0xa5c
/*  f0123cc:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0123d0:	19c00009 */ 	blez	$t6,.PF0f0123f8
/*  f0123d4:	00001025 */ 	move	$v0,$zero
/*  f0123d8:	244b0001 */ 	addiu	$t3,$v0,0x1
.PF0f0123dc:
/*  f0123dc:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f0123e0:	008d4821 */ 	addu	$t1,$a0,$t5
/*  f0123e4:	852c0000 */ 	lh	$t4,0x0($t1)
/*  f0123e8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0123ec:	01601025 */ 	move	$v0,$t3
/*  f0123f0:	5d80fffa */ 	bgtzl	$t4,.PF0f0123dc
/*  f0123f4:	244b0001 */ 	addiu	$t3,$v0,0x1
.PF0f0123f8:
/*  f0123f8:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0123fc:	3c02800a */ 	lui	$v0,0x800a
/*  f012400:	3c03800a */ 	lui	$v1,0x800a
/*  f012404:	af201b84 */ 	sw	$zero,0x1b84($t9)
/*  f012408:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f01240c:	2463a520 */ 	addiu	$v1,$v1,-23264
/*  f012410:	2442a510 */ 	addiu	$v0,$v0,-23280
/*  f012414:	af0000e0 */ 	sw	$zero,0xe0($t8)
.PF0f012418:
/*  f012418:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f01241c:	1443fffe */ 	bne	$v0,$v1,.PF0f012418
/*  f012420:	ac4004b4 */ 	sw	$zero,0x4b4($v0)
/*  f012424:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f012428:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f01242c:	0fc2e313 */ 	jal	currentPlayerChooseBodyAndHead
/*  f012430:	00003025 */ 	move	$a2,$zero
/*  f012434:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012438:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f01243c:	8d4e00bc */ 	lw	$t6,0xbc($t2)
/*  f012440:	8dcb0004 */ 	lw	$t3,0x4($t6)
/*  f012444:	a56f0010 */ 	sh	$t7,0x10($t3)
/*  f012448:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f01244c:	8fad0044 */ 	lw	$t5,0x44($sp)
/*  f012450:	8d2c00bc */ 	lw	$t4,0xbc($t1)
/*  f012454:	8d990004 */ 	lw	$t9,0x4($t4)
/*  f012458:	a32d0006 */ 	sb	$t5,0x6($t9)
/*  f01245c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f012460:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f012464:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f012468:	03e00008 */ 	jr	$ra
/*  f01246c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel currentPlayerInit
.late_rodata
glabel var7f1a8240
.word currentPlayerInit+0x150 # f011a44
glabel var7f1a8244
.word currentPlayerInit+0x19c # f011a90
glabel var7f1a8248
.word currentPlayerInit+0x244 # f011b38
glabel var7f1a824c
.word currentPlayerInit+0x274 # f011b68
glabel var7f1a8250
.word currentPlayerInit+0x27c # f011b70
glabel var7f1a8254
.word currentPlayerInit+0x284 # f011b78
glabel var7f1a8258
.word currentPlayerInit+0x298 # f011b8c
glabel var7f1a825c
.word currentPlayerInit+0x2a0 # f011b94
glabel var7f1a8260
.word currentPlayerInit+0x33c # f011c30
glabel var7f1a8264
.word currentPlayerInit+0x18c # f011a80
glabel var7f1a8268
.word currentPlayerInit+0x18c # f011a80
glabel var7f1a826c
.word currentPlayerInit+0x194 # f011a88
glabel var7f1a8270
.word 0x40c907a9
glabel var7f1a8274
.word 0x40c907a9
glabel var7f1a8278
.word 0x40c907a9
glabel var7f1a827c
.word 0x40c907a9
.text
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
/*  f01192c:	3c10800a */ 	lui	$s0,%hi(g_StageSetup+0xc)
/*  f011930:	afa00080 */ 	sw	$zero,0x80($sp)
/*  f011934:	8e10d03c */ 	lw	$s0,%lo(g_StageSetup+0xc)($s0)
/*  f011938:	a3a0007b */ 	sb	$zero,0x7b($sp)
/*  f01193c:	0fc2f0fc */ 	jal	viResetDefaultModeIf4Mb
/*  f011940:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f011944:	0fc63956 */ 	jal	func0f18e558
/*  f011948:	00000000 */ 	nop
/*  f01194c:	3c018007 */ 	lui	$at,%hi(g_InCutscene)
/*  f011950:	ac200764 */ 	sw	$zero,%lo(g_InCutscene)($at)
/*  f011954:	3c01800a */ 	lui	$at,%hi(g_CutsceneFrameOverrun240)
/*  f011958:	ac20de20 */ 	sw	$zero,%lo(g_CutsceneFrameOverrun240)($at)
/*  f01195c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f011960:	3c018007 */ 	lui	$at,%hi(var8007072c)
/*  f011964:	ac23072c */ 	sw	$v1,%lo(var8007072c)($at)
/*  f011968:	3c018007 */ 	lui	$at,%hi(var80070738)
/*  f01196c:	ac200738 */ 	sw	$zero,%lo(var80070738)($at)
/*  f011970:	3c018007 */ 	lui	$at,%hi(var8007073c)
/*  f011974:	ac20073c */ 	sw	$zero,%lo(var8007073c)($at)
/*  f011978:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f01197c:	3c018007 */ 	lui	$at,%hi(g_CurrentGeCreditsData)
/*  f011980:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f011984:	ac200740 */ 	sw	$zero,%lo(g_CurrentGeCreditsData)($at)
/*  f011988:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f01198c:	3c01800a */ 	lui	$at,%hi(g_NumSpawnPoints)
/*  f011990:	3c028007 */ 	lui	$v0,%hi(g_PlayersWithControl)
/*  f011994:	ad401bf0 */ 	sw	$zero,0x1bf0($t2)
/*  f011998:	ac20de68 */ 	sw	$zero,%lo(g_NumSpawnPoints)($at)
/*  f01199c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f0119a0:	24420750 */ 	addiu	$v0,$v0,%lo(g_PlayersWithControl)
/*  f0119a4:	3c018007 */ 	lui	$at,%hi(g_PlayerInvincible)
/*  f0119a8:	ad601b78 */ 	sw	$zero,0x1b78($t3)
/*  f0119ac:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0119b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0119b4:	ad801bd4 */ 	sw	$zero,0x1bd4($t4)
/*  f0119b8:	ac430000 */ 	sw	$v1,0x0($v0)
/*  f0119bc:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f0119c0:	ac430008 */ 	sw	$v1,0x8($v0)
/*  f0119c4:	ac43000c */ 	sw	$v1,0xc($v0)
/*  f0119c8:	0fc2e58f */ 	jal	setTickMode
/*  f0119cc:	ac200760 */ 	sw	$zero,%lo(g_PlayerInvincible)($at)
/*  f0119d0:	3c018007 */ 	lui	$at,%hi(var80070744)
/*  f0119d4:	ac200744 */ 	sw	$zero,%lo(var80070744)($at)
/*  f0119d8:	3c018007 */ 	lui	$at,%hi(var80070748)
/*  f0119dc:	ac200748 */ 	sw	$zero,%lo(var80070748)($at)
/*  f0119e0:	3c018007 */ 	lui	$at,%hi(var8007074c)
/*  f0119e4:	ac20074c */ 	sw	$zero,%lo(var8007074c)($at)
/*  f0119e8:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f0119ec:	44803000 */ 	mtc1	$zero,$f6
/*  f0119f0:	3c01800a */ 	lui	$at,%hi(g_DefaultWeapons+0x4)
/*  f0119f4:	ada01b7c */ 	sw	$zero,0x1b7c($t5)
/*  f0119f8:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0119fc:	e7261b80 */ 	swc1	$f6,0x1b80($t9)
/*  f011a00:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011a04:	af001b88 */ 	sw	$zero,0x1b88($t8)
/*  f011a08:	ac20ddd4 */ 	sw	$zero,%lo(g_DefaultWeapons+0x4)($at)
/*  f011a0c:	3c01800a */ 	lui	$at,%hi(g_DefaultWeapons)
/*  f011a10:	120000a1 */ 	beqz	$s0,.L0f011c98
/*  f011a14:	ac20ddd0 */ 	sw	$zero,%lo(g_DefaultWeapons)($at)
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
/*  f011a40:	00000000 */ 	nop
/*  f011a44:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f011a48:	3c02800a */ 	lui	$v0,%hi(g_NumSpawnPoints)
/*  f011a4c:	15e0000a */ 	bnez	$t7,.L0f011a78
/*  f011a50:	00000000 */ 	nop
/*  f011a54:	8c42de68 */ 	lw	$v0,%lo(g_NumSpawnPoints)($v0)
/*  f011a58:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011a5c:	3c01800a */ 	lui	$at,%hi(g_SpawnPoints)
/*  f011a60:	00025040 */ 	sll	$t2,$v0,0x1
/*  f011a64:	002a0821 */ 	addu	$at,$at,$t2
/*  f011a68:	a429de38 */ 	sh	$t1,%lo(g_SpawnPoints)($at)
/*  f011a6c:	3c01800a */ 	lui	$at,%hi(g_NumSpawnPoints)
/*  f011a70:	244b0001 */ 	addiu	$t3,$v0,0x1
/*  f011a74:	ac2bde68 */ 	sw	$t3,%lo(g_NumSpawnPoints)($at)
.L0f011a78:
/*  f011a78:	10000083 */ 	b	.L0f011c88
/*  f011a7c:	2610000c */ 	addiu	$s0,$s0,12
/*  f011a80:	10000081 */ 	b	.L0f011c88
/*  f011a84:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011a88:	1000007f */ 	b	.L0f011c88
/*  f011a8c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011a90:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f011a94:	15800026 */ 	bnez	$t4,.L0f011b30
/*  f011a98:	00000000 */ 	nop
/*  f011a9c:	8e2d02a8 */ 	lw	$t5,0x2a8($s1)
/*  f011aa0:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f011aa4:	11b90022 */ 	beq	$t5,$t9,.L0f011b30
/*  f011aa8:	00000000 */ 	nop
/*  f011aac:	0fc04558 */ 	jal	weaponLoadProjectileModels
/*  f011ab0:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011ab4:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011ab8:	04800008 */ 	bltz	$a0,.L0f011adc
/*  f011abc:	00000000 */ 	nop
/*  f011ac0:	0fc04558 */ 	jal	weaponLoadProjectileModels
/*  f011ac4:	00000000 */ 	nop
/*  f011ac8:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011acc:	0fc4478a */ 	jal	invGiveDoubleWeapon
/*  f011ad0:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f011ad4:	10000004 */ 	b	.L0f011ae8
/*  f011ad8:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f011adc:
/*  f011adc:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011ae0:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011ae4:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f011ae8:
/*  f011ae8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f011aec:	5700000c */ 	bnezl	$t8,.L0f011b20
/*  f011af0:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011af4:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f011af8:	3c01800a */ 	lui	$at,%hi(g_DefaultWeapons)
/*  f011afc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f011b00:	ac2eddd0 */ 	sw	$t6,%lo(g_DefaultWeapons)($at)
/*  f011b04:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011b08:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f011b0c:	3c01800a */ 	lui	$at,%hi(g_DefaultWeapons+0x4)
/*  f011b10:	04820003 */ 	bltzl	$a0,.L0f011b20
/*  f011b14:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011b18:	ac24ddd4 */ 	sw	$a0,%lo(g_DefaultWeapons+0x4)($at)
/*  f011b1c:	8e090004 */ 	lw	$t1,0x4($s0)
.L0f011b20:
/*  f011b20:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f011b24:	15210002 */ 	bne	$t1,$at,.L0f011b30
/*  f011b28:	00000000 */ 	nop
/*  f011b2c:	a3aa007b */ 	sb	$t2,0x7b($sp)
.L0f011b30:
/*  f011b30:	10000055 */ 	b	.L0f011c88
/*  f011b34:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f011b38:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f011b3c:	15600008 */ 	bnez	$t3,.L0f011b60
/*  f011b40:	00000000 */ 	nop
/*  f011b44:	8e2c02a8 */ 	lw	$t4,0x2a8($s1)
/*  f011b48:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011b4c:	118d0004 */ 	beq	$t4,$t5,.L0f011b60
/*  f011b50:	00000000 */ 	nop
/*  f011b54:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011b58:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011b5c:	8e050008 */ 	lw	$a1,0x8($s0)
.L0f011b60:
/*  f011b60:	10000049 */ 	b	.L0f011c88
/*  f011b64:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f011b68:	10000047 */ 	b	.L0f011c88
/*  f011b6c:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f011b70:	10000045 */ 	b	.L0f011c88
/*  f011b74:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011b78:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f011b7c:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011b80:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f011b84:	10000040 */ 	b	.L0f011c88
/*  f011b88:	af190324 */ 	sw	$t9,0x324($t8)
/*  f011b8c:	1000003e */ 	b	.L0f011c88
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
/*  f011bf0:	00000000 */ 	nop
/*  f011bf4:	0061001a */ 	div	$zero,$v1,$at
/*  f011bf8:	00005010 */ 	mfhi	$t2
/*  f011bfc:	3c010003 */ 	lui	$at,0x3
/*  f011c00:	34214bc0 */ 	ori	$at,$at,0x4bc0
/*  f011c04:	01410019 */ 	multu	$t2,$at
/*  f011c08:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011c0c:	c4461b80 */ 	lwc1	$f6,0x1b80($v0)
/*  f011c10:	00005812 */ 	mflo	$t3
/*  f011c14:	448b4000 */ 	mtc1	$t3,$f8
/*  f011c18:	00000000 */ 	nop
/*  f011c1c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f011c20:	46103280 */ 	add.s	$f10,$f6,$f16
/*  f011c24:	e44a1b80 */ 	swc1	$f10,0x1b80($v0)
.L0f011c28:
/*  f011c28:	10000017 */ 	b	.L0f011c88
/*  f011c2c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011c30:	3c0c800a */ 	lui	$t4,%hi(g_GeCreditsData)
/*  f011c34:	8d8cd050 */ 	lw	$t4,%lo(g_GeCreditsData)($t4)
/*  f011c38:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f011c3c:	3c018007 */ 	lui	$at,%hi(g_CurrentGeCreditsData)
/*  f011c40:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f011c44:	ac220740 */ 	sw	$v0,%lo(g_CurrentGeCreditsData)($at)
/*  f011c48:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f011c4c:	57200005 */ 	bnezl	$t9,.L0f011c64
/*  f011c50:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f011c54:	94580002 */ 	lhu	$t8,0x2($v0)
/*  f011c58:	13000008 */ 	beqz	$t8,.L0f011c7c
/*  f011c5c:	00000000 */ 	nop
/*  f011c60:	944e000c */ 	lhu	$t6,0xc($v0)
.L0f011c64:
/*  f011c64:	2442000c */ 	addiu	$v0,$v0,12
/*  f011c68:	55c0fffe */ 	bnezl	$t6,.L0f011c64
/*  f011c6c:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f011c70:	944f0002 */ 	lhu	$t7,0x2($v0)
/*  f011c74:	55e0fffb */ 	bnezl	$t7,.L0f011c64
/*  f011c78:	944e000c */ 	lhu	$t6,0xc($v0)
.L0f011c7c:
/*  f011c7c:	10000002 */ 	b	.L0f011c88
/*  f011c80:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f011c84:
/*  f011c84:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f011c88:
/*  f011c88:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f011c8c:	2401000c */ 	addiu	$at,$zero,0xc
/*  f011c90:	5441ff65 */ 	bnel	$v0,$at,.L0f011a28
/*  f011c94:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f011c98:
/*  f011c98:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011c9c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011ca0:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ca4:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f011ca8:	10400006 */ 	beqz	$v0,.L0f011cc4
/*  f011cac:	00000000 */ 	nop
/*  f011cb0:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011cb4:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f011cb8:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f011cbc:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011cc0:	24050050 */ 	addiu	$a1,$zero,0x50
.L0f011cc4:
/*  f011cc4:	0fc41b99 */ 	jal	cheatIsActive
/*  f011cc8:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f011ccc:	10400006 */ 	beqz	$v0,.L0f011ce8
/*  f011cd0:	00000000 */ 	nop
/*  f011cd4:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011cd8:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f011cdc:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f011ce0:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011ce4:	24050050 */ 	addiu	$a1,$zero,0x50
.L0f011ce8:
/*  f011ce8:	0fc41b99 */ 	jal	cheatIsActive
/*  f011cec:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011cf0:	10400006 */ 	beqz	$v0,.L0f011d0c
/*  f011cf4:	00000000 */ 	nop
/*  f011cf8:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011cfc:	24040031 */ 	addiu	$a0,$zero,0x31
/*  f011d00:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f011d04:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011d08:	24051c20 */ 	addiu	$a1,$zero,0x1c20
.L0f011d0c:
/*  f011d0c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d10:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f011d14:	10400003 */ 	beqz	$v0,.L0f011d24
/*  f011d18:	00000000 */ 	nop
/*  f011d1c:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011d20:	2404002d */ 	addiu	$a0,$zero,0x2d
.L0f011d24:
/*  f011d24:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d28:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f011d2c:	10400003 */ 	beqz	$v0,.L0f011d3c
/*  f011d30:	00000000 */ 	nop
/*  f011d34:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011d38:	24040037 */ 	addiu	$a0,$zero,0x37
.L0f011d3c:
/*  f011d3c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d40:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f011d44:	10400006 */ 	beqz	$v0,.L0f011d60
/*  f011d48:	00000000 */ 	nop
/*  f011d4c:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011d50:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f011d54:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f011d58:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011d5c:	2405000a */ 	addiu	$a1,$zero,0xa
.L0f011d60:
/*  f011d60:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d64:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f011d68:	10400006 */ 	beqz	$v0,.L0f011d84
/*  f011d6c:	00000000 */ 	nop
/*  f011d70:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011d74:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f011d78:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011d7c:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011d80:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011d84:
/*  f011d84:	0fc41b99 */ 	jal	cheatIsActive
/*  f011d88:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f011d8c:	10400003 */ 	beqz	$v0,.L0f011d9c
/*  f011d90:	00000000 */ 	nop
/*  f011d94:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011d98:	2404002f */ 	addiu	$a0,$zero,0x2f
.L0f011d9c:
/*  f011d9c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011da0:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f011da4:	10400009 */ 	beqz	$v0,.L0f011dcc
/*  f011da8:	00000000 */ 	nop
/*  f011dac:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011db0:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f011db4:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011db8:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011dbc:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f011dc0:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f011dc4:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011dc8:	24050014 */ 	addiu	$a1,$zero,0x14
.L0f011dcc:
/*  f011dcc:	0fc41b99 */ 	jal	cheatIsActive
/*  f011dd0:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f011dd4:	10400006 */ 	beqz	$v0,.L0f011df0
/*  f011dd8:	00000000 */ 	nop
/*  f011ddc:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011de0:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f011de4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011de8:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011dec:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011df0:
/*  f011df0:	0fc41b99 */ 	jal	cheatIsActive
/*  f011df4:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f011df8:	10400006 */ 	beqz	$v0,.L0f011e14
/*  f011dfc:	00000000 */ 	nop
/*  f011e00:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011e04:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f011e08:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011e0c:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
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
/*  f011e34:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011e38:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f011e3c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e40:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f011e44:	10400003 */ 	beqz	$v0,.L0f011e54
/*  f011e48:	00000000 */ 	nop
/*  f011e4c:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011e50:	2404002c */ 	addiu	$a0,$zero,0x2c
.L0f011e54:
/*  f011e54:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e58:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f011e5c:	10400006 */ 	beqz	$v0,.L0f011e78
/*  f011e60:	00000000 */ 	nop
/*  f011e64:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011e68:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f011e6c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011e70:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011e74:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011e78:
/*  f011e78:	0fc41b99 */ 	jal	cheatIsActive
/*  f011e7c:	24040023 */ 	addiu	$a0,$zero,0x23
/*  f011e80:	10400006 */ 	beqz	$v0,.L0f011e9c
/*  f011e84:	00000000 */ 	nop
/*  f011e88:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011e8c:	24040025 */ 	addiu	$a0,$zero,0x25
/*  f011e90:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011e94:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011e98:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011e9c:
/*  f011e9c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ea0:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f011ea4:	10400006 */ 	beqz	$v0,.L0f011ec0
/*  f011ea8:	00000000 */ 	nop
/*  f011eac:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011eb0:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f011eb4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011eb8:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011ebc:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011ec0:
/*  f011ec0:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ec4:	24040025 */ 	addiu	$a0,$zero,0x25
/*  f011ec8:	10400006 */ 	beqz	$v0,.L0f011ee4
/*  f011ecc:	00000000 */ 	nop
/*  f011ed0:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011ed4:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f011ed8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011edc:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011ee0:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011ee4:
/*  f011ee4:	0fc41b99 */ 	jal	cheatIsActive
/*  f011ee8:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f011eec:	10400006 */ 	beqz	$v0,.L0f011f08
/*  f011ef0:	00000000 */ 	nop
/*  f011ef4:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011ef8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f011efc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011f00:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011f04:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011f08:
/*  f011f08:	0fc41b99 */ 	jal	cheatIsActive
/*  f011f0c:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f011f10:	10400006 */ 	beqz	$v0,.L0f011f2c
/*  f011f14:	00000000 */ 	nop
/*  f011f18:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011f1c:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f011f20:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011f24:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011f28:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011f2c:
/*  f011f2c:	0fc41b99 */ 	jal	cheatIsActive
/*  f011f30:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f011f34:	10400006 */ 	beqz	$v0,.L0f011f50
/*  f011f38:	00000000 */ 	nop
/*  f011f3c:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011f40:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f011f44:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011f48:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011f4c:	240500c8 */ 	addiu	$a1,$zero,0xc8
.L0f011f50:
/*  f011f50:	0fc41b99 */ 	jal	cheatIsActive
/*  f011f54:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f011f58:	50400007 */ 	beqzl	$v0,.L0f011f78
/*  f011f5c:	8fa90080 */ 	lw	$t1,0x80($sp)
/*  f011f60:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f011f64:	2404002b */ 	addiu	$a0,$zero,0x2b
/*  f011f68:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011f6c:	0fc2a58a */ 	jal	bgunSetAmmoQuantity
/*  f011f70:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f011f74:	8fa90080 */ 	lw	$t1,0x80($sp)
.L0f011f78:
/*  f011f78:	15200003 */ 	bnez	$t1,.L0f011f88
/*  f011f7c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f011f80:	3c01800a */ 	lui	$at,%hi(g_DefaultWeapons)
/*  f011f84:	ac2addd0 */ 	sw	$t2,%lo(g_DefaultWeapons)($at)
.L0f011f88:
/*  f011f88:	0fc180d6 */ 	jal	propAllocate
/*  f011f8c:	00000000 */ 	nop
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
/*  f011fb8:	0fc1812f */ 	jal	propActivate
/*  f011fbc:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f011fc0:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f011fc4:	0fc180bc */ 	jal	propEnable
/*  f011fc8:	8d2400bc */ 	lw	$a0,0xbc($t1)
/*  f011fcc:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f011fd0:	00002825 */ 	or	$a1,$zero,$zero
/*  f011fd4:	0fc0819a */ 	jal	chrInit
/*  f011fd8:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f011fdc:	8e2b0298 */ 	lw	$t3,0x298($s1)
/*  f011fe0:	05620008 */ 	bltzl	$t3,.L0f012004
/*  f011fe4:	8e2e029c */ 	lw	$t6,0x29c($s1)
/*  f011fe8:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011fec:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f011ff0:	8db800bc */ 	lw	$t8,0xbc($t5)
/*  f011ff4:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f011ff8:	10000029 */ 	b	.L0f0120a0
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
/*  f012028:	1000001d */ 	b	.L0f0120a0
/*  f01202c:	a1690125 */ 	sb	$t1,0x125($t3)
/*  f012030:	8c5800bc */ 	lw	$t8,0xbc($v0)
.L0f012034:
/*  f012034:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f012038:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f01203c:	10000018 */ 	b	.L0f0120a0
/*  f012040:	a18d0125 */ 	sb	$t5,0x125($t4)
/*  f012044:	8e390314 */ 	lw	$t9,0x314($s1)
.L0f012048:
/*  f012048:	53200011 */ 	beqzl	$t9,.L0f012090
/*  f01204c:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012050:	8e2e0288 */ 	lw	$t6,0x288($s1)
/*  f012054:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f012058:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers+0x11)
/*  f01205c:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f012060:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f012064:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f012068:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f01206c:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f012070:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f012074:	012a4821 */ 	addu	$t1,$t1,$t2
/*  f012078:	9129c7c9 */ 	lbu	$t1,%lo(g_MpPlayers+0x11)($t1)
/*  f01207c:	8d990004 */ 	lw	$t9,0x4($t4)
/*  f012080:	012bc004 */ 	sllv	$t8,$t3,$t1
/*  f012084:	10000006 */ 	b	.L0f0120a0
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
/*  f0120a8:	00000000 */ 	nop
/*  f0120ac:	0fc0458c */ 	jal	currentPlayerInitEyespy
/*  f0120b0:	00000000 */ 	nop
.L0f0120b4:
/*  f0120b4:	3c0d800a */ 	lui	$t5,%hi(g_NumSpawnPoints)
/*  f0120b8:	8dadde68 */ 	lw	$t5,%lo(g_NumSpawnPoints)($t5)
/*  f0120bc:	59a0002f */ 	blezl	$t5,.L0f01217c
/*  f0120c0:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f0120c4:	8e2c0298 */ 	lw	$t4,0x298($s1)
/*  f0120c8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0120cc:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0120d0:	0580000a */ 	bltz	$t4,.L0f0120fc
/*  f0120d4:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0120d8:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0120dc:	44816000 */ 	mtc1	$at,$f12
/*  f0120e0:	0fc6185f */ 	jal	scenarioChooseSpawnLocation
/*  f0120e4:	8f0700bc */ 	lw	$a3,0xbc($t8)
/*  f0120e8:	3c017f1b */ 	lui	$at,%hi(var7f1a8270)
/*  f0120ec:	c4328270 */ 	lwc1	$f18,%lo(var7f1a8270)($at)
/*  f0120f0:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f0120f4:	10000020 */ 	b	.L0f012178
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
/*  f012120:	0fc6185f */ 	jal	scenarioChooseSpawnLocation
/*  f012124:	8de700bc */ 	lw	$a3,0xbc($t7)
/*  f012128:	3c017f1b */ 	lui	$at,%hi(var7f1a8274)
/*  f01212c:	c4288274 */ 	lwc1	$f8,%lo(var7f1a8274)($at)
/*  f012130:	46004181 */ 	sub.s	$f6,$f8,$f0
/*  f012134:	10000010 */ 	b	.L0f012178
/*  f012138:	e7a60088 */ 	swc1	$f6,0x88($sp)
.L0f01213c:
/*  f01213c:	8e2a0314 */ 	lw	$t2,0x314($s1)
/*  f012140:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f012144:	3c01800a */ 	lui	$at,%hi(g_NumSpawnPoints)
/*  f012148:	55400003 */ 	bnezl	$t2,.L0f012158
/*  f01214c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012150:	ac2ede68 */ 	sw	$t6,%lo(g_NumSpawnPoints)($at)
/*  f012154:	8e2b0284 */ 	lw	$t3,0x284($s1)
.L0f012158:
/*  f012158:	3c0141f0 */ 	lui	$at,0x41f0
/*  f01215c:	44816000 */ 	mtc1	$at,$f12
/*  f012160:	0fc6185f */ 	jal	scenarioChooseSpawnLocation
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
/*  f0121a8:	0c00a86c */ 	jal	cdFindGroundY
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
/*  f012200:	0c0068f7 */ 	jal	sinf
/*  f012204:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f012208:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f01220c:	46000107 */ 	neg.s	$f4,$f0
/*  f012210:	44804000 */ 	mtc1	$zero,$f8
/*  f012214:	e5e4036c */ 	swc1	$f4,0x36c($t7)
/*  f012218:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f01221c:	e5480370 */ 	swc1	$f8,0x370($t2)
/*  f012220:	0c0068f4 */ 	jal	cosf
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
/*  f01227c:	0fc19711 */ 	jal	propDeregisterRooms
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
/*  f0122b4:	0fc30709 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0122b8:	24460388 */ 	addiu	$a2,$v0,0x388
/*  f0122bc:	0fc07934 */ 	jal	getNumChrSlots
/*  f0122c0:	00000000 */ 	nop
/*  f0122c4:	18400026 */ 	blez	$v0,.L0f012360
/*  f0122c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0122cc:	000428c0 */ 	sll	$a1,$a0,0x3
/*  f0122d0:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f0122d4:	00052880 */ 	sll	$a1,$a1,0x2
/*  f0122d8:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f0122dc:	00052880 */ 	sll	$a1,$a1,0x2
/*  f0122e0:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f0122e4:	3c068006 */ 	lui	$a2,%hi(g_ChrSlots)
/*  f0122e8:	24c62988 */ 	addiu	$a2,$a2,%lo(g_ChrSlots)
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
/*  f012334:	00000000 */ 	nop
/*  f012338:	0007000d */ 	break	0x7
.L0f01233c:
/*  f01233c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f012340:	15010004 */ 	bne	$t0,$at,.L0f012354
/*  f012344:	3c018000 */ 	lui	$at,0x8000
/*  f012348:	15810002 */ 	bne	$t4,$at,.L0f012354
/*  f01234c:	00000000 */ 	nop
/*  f012350:	0006000d */ 	break	0x6
.L0f012354:
/*  f012354:	0045082a */ 	slt	$at,$v0,$a1
.L0f012358:
/*  f012358:	5420ffe9 */ 	bnezl	$at,.L0f012300
/*  f01235c:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f012360:
/*  f012360:	0fc32e31 */ 	jal	bmove0f0cb8c4
/*  f012364:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f012368:	8e380318 */ 	lw	$t8,0x318($s1)
/*  f01236c:	13000005 */ 	beqz	$t8,.L0f012384
/*  f012370:	00000000 */ 	nop
/*  f012374:	0fc2e59d */ 	jal	func0f0b9674
/*  f012378:	00000000 */ 	nop
/*  f01237c:	10000003 */ 	b	.L0f01238c
/*  f012380:	00000000 */ 	nop
.L0f012384:
/*  f012384:	0fc2e688 */ 	jal	func0f0b9a20
/*  f012388:	00000000 */ 	nop
.L0f01238c:
/*  f01238c:	3c048007 */ 	lui	$a0,%hi(g_DeathAnimations)
/*  f012390:	24840768 */ 	addiu	$a0,$a0,%lo(g_DeathAnimations)
/*  f012394:	00007840 */ 	sll	$t7,$zero,0x1
/*  f012398:	008f5021 */ 	addu	$t2,$a0,$t7
/*  f01239c:	854e0000 */ 	lh	$t6,0x0($t2)
/*  f0123a0:	3c038007 */ 	lui	$v1,%hi(g_NumDeathAnimations)
/*  f0123a4:	2463077c */ 	addiu	$v1,$v1,%lo(g_NumDeathAnimations)
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
/*  f0123dc:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x10)
/*  f0123e0:	af201b84 */ 	sw	$zero,0x1b84($t9)
/*  f0123e4:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0123e8:	24639fd0 */ 	addiu	$v1,$v1,%lo(g_Vars+0x10)
/*  f0123ec:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0123f0:	af0000e0 */ 	sw	$zero,0xe0($t8)
.L0f0123f4:
/*  f0123f4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0123f8:	1443fffe */ 	bne	$v0,$v1,.L0f0123f4
/*  f0123fc:	ac4004b4 */ 	sw	$zero,0x4b4($v0)
/*  f012400:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f012404:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f012408:	0fc2e1cb */ 	jal	currentPlayerChooseBodyAndHead
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
);
#else
GLOBAL_ASM(
glabel currentPlayerInit
.late_rodata
glabel var7f1a8240
.word currentPlayerInit+0x150 # f011a44
glabel var7f1a8244
.word currentPlayerInit+0x19c # f011a90
glabel var7f1a8248
.word currentPlayerInit+0x244 # f011b38
glabel var7f1a824c
.word currentPlayerInit+0x274 # f011b68
glabel var7f1a8250
.word currentPlayerInit+0x27c # f011b70
glabel var7f1a8254
.word currentPlayerInit+0x284 # f011b78
glabel var7f1a8258
.word currentPlayerInit+0x298 # f011b8c
glabel var7f1a825c
.word currentPlayerInit+0x2a0 # f011b94
glabel var7f1a8260
.word currentPlayerInit+0x33c # f011c30
glabel var7f1a8264
.word currentPlayerInit+0x18c # f011a80
glabel var7f1a8268
.word currentPlayerInit+0x18c # f011a80
glabel var7f1a826c
.word currentPlayerInit+0x194 # f011a88
glabel var7f1a8270
.word 0x40c907a9
glabel var7f1a8274
.word 0x40c907a9
glabel var7f1a8278
.word 0x40c907a9
glabel var7f1a827c
.word 0x40c907a9
.text
/*  f011634:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f011638:	3c0f8006 */ 	lui	$t7,0x8006
/*  f01163c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f011640:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f011644:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f011648:	25ef48b4 */ 	addiu	$t7,$t7,0x48b4
/*  f01164c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f011650:	27ae009c */ 	addiu	$t6,$sp,0x9c
/*  f011654:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f011658:	adc10000 */ 	sw	$at,0x0($t6)
/*  f01165c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f011660:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f011664:	44802000 */ 	mtc1	$zero,$f4
/*  f011668:	adc10008 */ 	sw	$at,0x8($t6)
/*  f01166c:	3c10800a */ 	lui	$s0,0x800a
/*  f011670:	afa00080 */ 	sw	$zero,0x80($sp)
/*  f011674:	8e10176c */ 	lw	$s0,0x176c($s0)
/*  f011678:	a3a0007b */ 	sb	$zero,0x7b($sp)
/*  f01167c:	0fc2e831 */ 	jal	viResetDefaultModeIf4Mb
/*  f011680:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f011684:	0fc621c6 */ 	jal	func0f18e558
/*  f011688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01168c:	3c018007 */ 	lui	$at,0x8007
/*  f011690:	ac202e24 */ 	sw	$zero,0x2e24($at)
/*  f011694:	3c01800a */ 	lui	$at,0x800a
/*  f011698:	ac202600 */ 	sw	$zero,0x2600($at)
/*  f01169c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0116a0:	3c018007 */ 	lui	$at,0x8007
/*  f0116a4:	ac232dec */ 	sw	$v1,0x2dec($at)
/*  f0116a8:	3c018007 */ 	lui	$at,0x8007
/*  f0116ac:	ac202df8 */ 	sw	$zero,0x2df8($at)
/*  f0116b0:	3c018007 */ 	lui	$at,0x8007
/*  f0116b4:	ac202dfc */ 	sw	$zero,0x2dfc($at)
/*  f0116b8:	3c11800a */ 	lui	$s1,0x800a
/*  f0116bc:	3c018007 */ 	lui	$at,0x8007
/*  f0116c0:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f0116c4:	ac202e00 */ 	sw	$zero,0x2e00($at)
/*  f0116c8:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0116cc:	3c01800a */ 	lui	$at,0x800a
/*  f0116d0:	3c028007 */ 	lui	$v0,0x8007
/*  f0116d4:	ad401bf0 */ 	sw	$zero,0x1bf0($t2)
/*  f0116d8:	ac202648 */ 	sw	$zero,0x2648($at)
/*  f0116dc:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f0116e0:	24422e10 */ 	addiu	$v0,$v0,0x2e10
/*  f0116e4:	3c018007 */ 	lui	$at,0x8007
/*  f0116e8:	ad601b78 */ 	sw	$zero,0x1b78($t3)
/*  f0116ec:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0116f0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0116f4:	ad801bd4 */ 	sw	$zero,0x1bd4($t4)
/*  f0116f8:	ac430000 */ 	sw	$v1,0x0($v0)
/*  f0116fc:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f011700:	ac430008 */ 	sw	$v1,0x8($v0)
/*  f011704:	ac43000c */ 	sw	$v1,0xc($v0)
/*  f011708:	0fc2dcc6 */ 	jal	setTickMode
/*  f01170c:	ac202e20 */ 	sw	$zero,0x2e20($at)
/*  f011710:	3c018007 */ 	lui	$at,0x8007
/*  f011714:	ac202e04 */ 	sw	$zero,0x2e04($at)
/*  f011718:	3c018007 */ 	lui	$at,0x8007
/*  f01171c:	ac202e08 */ 	sw	$zero,0x2e08($at)
/*  f011720:	3c018007 */ 	lui	$at,0x8007
/*  f011724:	ac202e0c */ 	sw	$zero,0x2e0c($at)
/*  f011728:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f01172c:	44803000 */ 	mtc1	$zero,$f6
/*  f011730:	3c01800a */ 	lui	$at,0x800a
/*  f011734:	ada01b7c */ 	sw	$zero,0x1b7c($t5)
/*  f011738:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f01173c:	e7261b80 */ 	swc1	$f6,0x1b80($t9)
/*  f011740:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011744:	af001b88 */ 	sw	$zero,0x1b88($t8)
/*  f011748:	ac2025b4 */ 	sw	$zero,0x25b4($at)
/*  f01174c:	3c01800a */ 	lui	$at,0x800a
/*  f011750:	120000a1 */ 	beqz	$s0,.NB0f0119d8
/*  f011754:	ac2025b0 */ 	sw	$zero,0x25b0($at)
/*  f011758:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f01175c:	2401000c */ 	addiu	$at,$zero,0xc
/*  f011760:	1041009d */ 	beq	$v0,$at,.NB0f0119d8
/*  f011764:	2c41000c */ 	sltiu	$at,$v0,0xc
.NB0f011768:
/*  f011768:	10200096 */ 	beqz	$at,.NB0f0119c4
/*  f01176c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f011770:	3c017f1a */ 	lui	$at,0x7f1a
/*  f011774:	002e0821 */ 	addu	$at,$at,$t6
/*  f011778:	8c2e1ee0 */ 	lw	$t6,0x1ee0($at)
/*  f01177c:	01c00008 */ 	jr	$t6
/*  f011780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011784:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f011788:	3c02800a */ 	lui	$v0,0x800a
/*  f01178c:	15e0000a */ 	bnez	$t7,.NB0f0117b8
/*  f011790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011794:	8c422648 */ 	lw	$v0,0x2648($v0)
/*  f011798:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f01179c:	3c01800a */ 	lui	$at,0x800a
/*  f0117a0:	00025040 */ 	sll	$t2,$v0,0x1
/*  f0117a4:	002a0821 */ 	addu	$at,$at,$t2
/*  f0117a8:	a4292618 */ 	sh	$t1,0x2618($at)
/*  f0117ac:	3c01800a */ 	lui	$at,0x800a
/*  f0117b0:	244b0001 */ 	addiu	$t3,$v0,0x1
/*  f0117b4:	ac2b2648 */ 	sw	$t3,0x2648($at)
.NB0f0117b8:
/*  f0117b8:	10000083 */ 	beqz	$zero,.NB0f0119c8
/*  f0117bc:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0117c0:	10000081 */ 	beqz	$zero,.NB0f0119c8
/*  f0117c4:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0117c8:	1000007f */ 	beqz	$zero,.NB0f0119c8
/*  f0117cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0117d0:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0117d4:	15800026 */ 	bnez	$t4,.NB0f011870
/*  f0117d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0117dc:	8e2d02a8 */ 	lw	$t5,0x2a8($s1)
/*  f0117e0:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0117e4:	11b90022 */ 	beq	$t5,$t9,.NB0f011870
/*  f0117e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0117ec:	0fc044a8 */ 	jal	weaponLoadProjectileModels
/*  f0117f0:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f0117f4:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0117f8:	04800008 */ 	bltz	$a0,.NB0f01181c
/*  f0117fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011800:	0fc044a8 */ 	jal	weaponLoadProjectileModels
/*  f011804:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011808:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f01180c:	0fc430a2 */ 	jal	invGiveDoubleWeapon
/*  f011810:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f011814:	10000004 */ 	beqz	$zero,.NB0f011828
/*  f011818:	8fb80080 */ 	lw	$t8,0x80($sp)
.NB0f01181c:
/*  f01181c:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011820:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011824:	8fb80080 */ 	lw	$t8,0x80($sp)
.NB0f011828:
/*  f011828:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f01182c:	5700000c */ 	bnezl	$t8,.NB0f011860
/*  f011830:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011834:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f011838:	3c01800a */ 	lui	$at,0x800a
/*  f01183c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f011840:	ac2e25b0 */ 	sw	$t6,0x25b0($at)
/*  f011844:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f011848:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f01184c:	3c01800a */ 	lui	$at,0x800a
/*  f011850:	04820003 */ 	bltzl	$a0,.NB0f011860
/*  f011854:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f011858:	ac2425b4 */ 	sw	$a0,0x25b4($at)
/*  f01185c:	8e090004 */ 	lw	$t1,0x4($s0)
.NB0f011860:
/*  f011860:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f011864:	15210002 */ 	bne	$t1,$at,.NB0f011870
/*  f011868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01186c:	a3aa007b */ 	sb	$t2,0x7b($sp)
.NB0f011870:
/*  f011870:	10000055 */ 	beqz	$zero,.NB0f0119c8
/*  f011874:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f011878:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f01187c:	15600008 */ 	bnez	$t3,.NB0f0118a0
/*  f011880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011884:	8e2c02a8 */ 	lw	$t4,0x2a8($s1)
/*  f011888:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f01188c:	118d0004 */ 	beq	$t4,$t5,.NB0f0118a0
/*  f011890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011894:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f011898:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f01189c:	8e050008 */ 	lw	$a1,0x8($s0)
.NB0f0118a0:
/*  f0118a0:	10000049 */ 	beqz	$zero,.NB0f0119c8
/*  f0118a4:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f0118a8:	10000047 */ 	beqz	$zero,.NB0f0119c8
/*  f0118ac:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f0118b0:	10000045 */ 	beqz	$zero,.NB0f0119c8
/*  f0118b4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0118b8:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0118bc:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0118c0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0118c4:	10000040 */ 	beqz	$zero,.NB0f0119c8
/*  f0118c8:	af190324 */ 	sw	$t9,0x324($t8)
/*  f0118cc:	1000003e */ 	beqz	$zero,.NB0f0119c8
/*  f0118d0:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f0118d4:	44804000 */ 	mtc1	$zero,$f8
/*  f0118d8:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f0118dc:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f0118e0:	e5c81b80 */ 	swc1	$f8,0x1b80($t6)
/*  f0118e4:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0118e8:	5880000f */ 	blezl	$a0,.NB0f011928
/*  f0118ec:	8e030004 */ 	lw	$v1,0x4($s0)
/*  f0118f0:	0081001a */ 	div	$zero,$a0,$at
/*  f0118f4:	00007810 */ 	mfhi	$t7
/*  f0118f8:	000f48c0 */ 	sll	$t1,$t7,0x3
/*  f0118fc:	012f4823 */ 	subu	$t1,$t1,$t7
/*  f011900:	00094940 */ 	sll	$t1,$t1,0x5
/*  f011904:	012f4821 */ 	addu	$t1,$t1,$t7
/*  f011908:	00094900 */ 	sll	$t1,$t1,0x4
/*  f01190c:	44898000 */ 	mtc1	$t1,$f16
/*  f011910:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011914:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f011918:	c44a1b80 */ 	lwc1	$f10,0x1b80($v0)
/*  f01191c:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f011920:	e4441b80 */ 	swc1	$f4,0x1b80($v0)
/*  f011924:	8e030004 */ 	lw	$v1,0x4($s0)
.NB0f011928:
/*  f011928:	2401000c */ 	addiu	$at,$zero,0xc
/*  f01192c:	1860000e */ 	blez	$v1,.NB0f011968
/*  f011930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011934:	0061001a */ 	div	$zero,$v1,$at
/*  f011938:	00005010 */ 	mfhi	$t2
/*  f01193c:	3c010003 */ 	lui	$at,0x3
/*  f011940:	34214bc0 */ 	ori	$at,$at,0x4bc0
/*  f011944:	01410019 */ 	multu	$t2,$at
/*  f011948:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f01194c:	c4461b80 */ 	lwc1	$f6,0x1b80($v0)
/*  f011950:	00005812 */ 	mflo	$t3
/*  f011954:	448b4000 */ 	mtc1	$t3,$f8
/*  f011958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01195c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f011960:	46103280 */ 	add.s	$f10,$f6,$f16
/*  f011964:	e44a1b80 */ 	swc1	$f10,0x1b80($v0)
.NB0f011968:
/*  f011968:	10000017 */ 	beqz	$zero,.NB0f0119c8
/*  f01196c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f011970:	3c0c800a */ 	lui	$t4,0x800a
/*  f011974:	8d8c1780 */ 	lw	$t4,0x1780($t4)
/*  f011978:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f01197c:	3c018007 */ 	lui	$at,0x8007
/*  f011980:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f011984:	ac222e00 */ 	sw	$v0,0x2e00($at)
/*  f011988:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f01198c:	57200005 */ 	bnezl	$t9,.NB0f0119a4
/*  f011990:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f011994:	94580002 */ 	lhu	$t8,0x2($v0)
/*  f011998:	13000008 */ 	beqz	$t8,.NB0f0119bc
/*  f01199c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0119a0:	944e000c */ 	lhu	$t6,0xc($v0)
.NB0f0119a4:
/*  f0119a4:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f0119a8:	55c0fffe */ 	bnezl	$t6,.NB0f0119a4
/*  f0119ac:	944e000c */ 	lhu	$t6,0xc($v0)
/*  f0119b0:	944f0002 */ 	lhu	$t7,0x2($v0)
/*  f0119b4:	55e0fffb */ 	bnezl	$t7,.NB0f0119a4
/*  f0119b8:	944e000c */ 	lhu	$t6,0xc($v0)
.NB0f0119bc:
/*  f0119bc:	10000002 */ 	beqz	$zero,.NB0f0119c8
/*  f0119c0:	26100008 */ 	addiu	$s0,$s0,0x8
.NB0f0119c4:
/*  f0119c4:	26100004 */ 	addiu	$s0,$s0,0x4
.NB0f0119c8:
/*  f0119c8:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f0119cc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0119d0:	5441ff65 */ 	bnel	$v0,$at,.NB0f011768
/*  f0119d4:	2c41000c */ 	sltiu	$at,$v0,0xc
.NB0f0119d8:
/*  f0119d8:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f0119dc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0119e0:	0fc40ab9 */ 	jal	cheatIsActive
/*  f0119e4:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0119e8:	10400006 */ 	beqz	$v0,.NB0f011a04
/*  f0119ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0119f0:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f0119f4:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0119f8:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0119fc:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011a00:	24050050 */ 	addiu	$a1,$zero,0x50
.NB0f011a04:
/*  f011a04:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011a08:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f011a0c:	10400006 */ 	beqz	$v0,.NB0f011a28
/*  f011a10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a14:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011a18:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f011a1c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f011a20:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011a24:	24050050 */ 	addiu	$a1,$zero,0x50
.NB0f011a28:
/*  f011a28:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011a2c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011a30:	10400006 */ 	beqz	$v0,.NB0f011a4c
/*  f011a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a38:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011a3c:	24040031 */ 	addiu	$a0,$zero,0x31
/*  f011a40:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f011a44:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011a48:	24051c20 */ 	addiu	$a1,$zero,0x1c20
.NB0f011a4c:
/*  f011a4c:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011a50:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f011a54:	10400003 */ 	beqz	$v0,.NB0f011a64
/*  f011a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a5c:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011a60:	2404002d */ 	addiu	$a0,$zero,0x2d
.NB0f011a64:
/*  f011a64:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011a68:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f011a6c:	10400003 */ 	beqz	$v0,.NB0f011a7c
/*  f011a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a74:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011a78:	24040037 */ 	addiu	$a0,$zero,0x37
.NB0f011a7c:
/*  f011a7c:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011a80:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f011a84:	10400006 */ 	beqz	$v0,.NB0f011aa0
/*  f011a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011a8c:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011a90:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f011a94:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f011a98:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011a9c:	2405000a */ 	addiu	$a1,$zero,0xa
.NB0f011aa0:
/*  f011aa0:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011aa4:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f011aa8:	10400006 */ 	beqz	$v0,.NB0f011ac4
/*  f011aac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011ab0:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011ab4:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f011ab8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011abc:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011ac0:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011ac4:
/*  f011ac4:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011ac8:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f011acc:	10400003 */ 	beqz	$v0,.NB0f011adc
/*  f011ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011ad4:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011ad8:	2404002f */ 	addiu	$a0,$zero,0x2f
.NB0f011adc:
/*  f011adc:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011ae0:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f011ae4:	10400009 */ 	beqz	$v0,.NB0f011b0c
/*  f011ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011aec:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011af0:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f011af4:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011af8:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011afc:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f011b00:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f011b04:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011b08:	24050014 */ 	addiu	$a1,$zero,0x14
.NB0f011b0c:
/*  f011b0c:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011b10:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f011b14:	10400006 */ 	beqz	$v0,.NB0f011b30
/*  f011b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011b1c:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011b20:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f011b24:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011b28:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011b2c:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011b30:
/*  f011b30:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011b34:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f011b38:	10400006 */ 	beqz	$v0,.NB0f011b54
/*  f011b3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011b40:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011b44:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f011b48:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011b4c:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011b50:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011b54:
/*  f011b54:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011b58:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f011b5c:	10400006 */ 	beqz	$v0,.NB0f011b78
/*  f011b60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011b64:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011b68:	2404002c */ 	addiu	$a0,$zero,0x2c
/*  f011b6c:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f011b70:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011b74:	24050004 */ 	addiu	$a1,$zero,0x4
.NB0f011b78:
/*  f011b78:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011b7c:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f011b80:	10400006 */ 	beqz	$v0,.NB0f011b9c
/*  f011b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011b88:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011b8c:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f011b90:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f011b94:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011b98:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011b9c:
/*  f011b9c:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011ba0:	24040023 */ 	addiu	$a0,$zero,0x23
/*  f011ba4:	10400006 */ 	beqz	$v0,.NB0f011bc0
/*  f011ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011bac:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011bb0:	24040025 */ 	addiu	$a0,$zero,0x25
/*  f011bb4:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011bb8:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011bbc:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011bc0:
/*  f011bc0:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011bc4:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f011bc8:	10400006 */ 	beqz	$v0,.NB0f011be4
/*  f011bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011bd0:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011bd4:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f011bd8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011bdc:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011be0:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011be4:
/*  f011be4:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011be8:	24040025 */ 	addiu	$a0,$zero,0x25
/*  f011bec:	10400006 */ 	beqz	$v0,.NB0f011c08
/*  f011bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011bf4:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011bf8:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f011bfc:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011c00:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011c04:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011c08:
/*  f011c08:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011c0c:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f011c10:	10400006 */ 	beqz	$v0,.NB0f011c2c
/*  f011c14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011c18:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011c1c:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f011c20:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011c24:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011c28:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011c2c:
/*  f011c2c:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011c30:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f011c34:	10400006 */ 	beqz	$v0,.NB0f011c50
/*  f011c38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011c3c:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011c40:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f011c44:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011c48:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011c4c:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011c50:
/*  f011c50:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011c54:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f011c58:	10400006 */ 	beqz	$v0,.NB0f011c74
/*  f011c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011c60:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011c64:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f011c68:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f011c6c:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011c70:	240500c8 */ 	addiu	$a1,$zero,0xc8
.NB0f011c74:
/*  f011c74:	0fc40ab9 */ 	jal	cheatIsActive
/*  f011c78:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f011c7c:	50400007 */ 	beqzl	$v0,.NB0f011c9c
/*  f011c80:	8fa90080 */ 	lw	$t1,0x80($sp)
/*  f011c84:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f011c88:	2404002b */ 	addiu	$a0,$zero,0x2b
/*  f011c8c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f011c90:	0fc29cf2 */ 	jal	bgunSetAmmoQuantity
/*  f011c94:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f011c98:	8fa90080 */ 	lw	$t1,0x80($sp)
.NB0f011c9c:
/*  f011c9c:	15200003 */ 	bnez	$t1,.NB0f011cac
/*  f011ca0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f011ca4:	3c01800a */ 	lui	$at,0x800a
/*  f011ca8:	ac2a25b0 */ 	sw	$t2,0x25b0($at)
.NB0f011cac:
/*  f011cac:	0fc17d86 */ 	jal	propAllocate
/*  f011cb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011cb4:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f011cb8:	24190006 */ 	addiu	$t9,$zero,0x6
/*  f011cbc:	ad6200bc */ 	sw	$v0,0xbc($t3)
/*  f011cc0:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f011cc4:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f011cc8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f011ccc:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011cd0:	8f0e00bc */ 	lw	$t6,0xbc($t8)
/*  f011cd4:	a1d90000 */ 	sb	$t9,0x0($t6)
/*  f011cd8:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f011cdc:	0fc17ddf */ 	jal	propActivate
/*  f011ce0:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f011ce4:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f011ce8:	0fc17d6c */ 	jal	propEnable
/*  f011cec:	8d2400bc */ 	lw	$a0,0xbc($t1)
/*  f011cf0:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f011cf4:	00002825 */ 	or	$a1,$zero,$zero
/*  f011cf8:	0fc0806b */ 	jal	chrInit
/*  f011cfc:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f011d00:	8e2b0298 */ 	lw	$t3,0x298($s1)
/*  f011d04:	05620008 */ 	bltzl	$t3,.NB0f011d28
/*  f011d08:	8e2e029c */ 	lw	$t6,0x29c($s1)
/*  f011d0c:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011d10:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f011d14:	8db800bc */ 	lw	$t8,0xbc($t5)
/*  f011d18:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f011d1c:	10000029 */ 	beqz	$zero,.NB0f011dc4
/*  f011d20:	a32c0125 */ 	sb	$t4,0x125($t9)
/*  f011d24:	8e2e029c */ 	lw	$t6,0x29c($s1)
.NB0f011d28:
/*  f011d28:	05c20010 */ 	bltzl	$t6,.NB0f011d6c
/*  f011d2c:	8e390314 */ 	lw	$t9,0x314($s1)
/*  f011d30:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011d34:	8e2f02a0 */ 	lw	$t7,0x2a0($s1)
/*  f011d38:	55e20007 */ 	bnel	$t7,$v0,.NB0f011d58
/*  f011d3c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f011d40:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f011d44:	24090010 */ 	addiu	$t1,$zero,0x10
/*  f011d48:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f011d4c:	1000001d */ 	beqz	$zero,.NB0f011dc4
/*  f011d50:	a1690125 */ 	sb	$t1,0x125($t3)
/*  f011d54:	8c5800bc */ 	lw	$t8,0xbc($v0)
.NB0f011d58:
/*  f011d58:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f011d5c:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f011d60:	10000018 */ 	beqz	$zero,.NB0f011dc4
/*  f011d64:	a18d0125 */ 	sb	$t5,0x125($t4)
/*  f011d68:	8e390314 */ 	lw	$t9,0x314($s1)
.NB0f011d6c:
/*  f011d6c:	53200011 */ 	beqzl	$t9,.NB0f011db4
/*  f011d70:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f011d74:	8e2e0288 */ 	lw	$t6,0x288($s1)
/*  f011d78:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011d7c:	3c09800b */ 	lui	$t1,0x800b
/*  f011d80:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f011d84:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f011d88:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f011d8c:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f011d90:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f011d94:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f011d98:	012a4821 */ 	addu	$t1,$t1,$t2
/*  f011d9c:	91291079 */ 	lbu	$t1,0x1079($t1)
/*  f011da0:	8d990004 */ 	lw	$t9,0x4($t4)
/*  f011da4:	012bc004 */ 	sllv	$t8,$t3,$t1
/*  f011da8:	10000006 */ 	beqz	$zero,.NB0f011dc4
/*  f011dac:	a3380125 */ 	sb	$t8,0x125($t9)
/*  f011db0:	8e2f0284 */ 	lw	$t7,0x284($s1)
.NB0f011db4:
/*  f011db4:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f011db8:	8dea00bc */ 	lw	$t2,0xbc($t7)
/*  f011dbc:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f011dc0:	a16e0125 */ 	sb	$t6,0x125($t3)
.NB0f011dc4:
/*  f011dc4:	93a9007b */ 	lbu	$t1,0x7b($sp)
/*  f011dc8:	11200003 */ 	beqz	$t1,.NB0f011dd8
/*  f011dcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011dd0:	0fc044dc */ 	jal	currentPlayerInitEyespy
/*  f011dd4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f011dd8:
/*  f011dd8:	3c0d800a */ 	lui	$t5,0x800a
/*  f011ddc:	8dad2648 */ 	lw	$t5,0x2648($t5)
/*  f011de0:	59a0002f */ 	blezl	$t5,.NB0f011ea0
/*  f011de4:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011de8:	8e2c0298 */ 	lw	$t4,0x298($s1)
/*  f011dec:	3c0141f0 */ 	lui	$at,0x41f0
/*  f011df0:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f011df4:	0580000a */ 	bltz	$t4,.NB0f011e20
/*  f011df8:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f011dfc:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011e00:	44816000 */ 	mtc1	$at,$f12
/*  f011e04:	0fc60179 */ 	jal	scenarioChooseSpawnLocation
/*  f011e08:	8f0700bc */ 	lw	$a3,0xbc($t8)
/*  f011e0c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f011e10:	c4321f10 */ 	lwc1	$f18,0x1f10($at)
/*  f011e14:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f011e18:	10000020 */ 	beqz	$zero,.NB0f011e9c
/*  f011e1c:	e7a40088 */ 	swc1	$f4,0x88($sp)
.NB0f011e20:
/*  f011e20:	8e39029c */ 	lw	$t9,0x29c($s1)
/*  f011e24:	3c0141f0 */ 	lui	$at,0x41f0
/*  f011e28:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f011e2c:	0720000c */ 	bltz	$t9,.NB0f011e60
/*  f011e30:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f011e34:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f011e38:	44816000 */ 	mtc1	$at,$f12
/*  f011e3c:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f011e40:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f011e44:	0fc60179 */ 	jal	scenarioChooseSpawnLocation
/*  f011e48:	8de700bc */ 	lw	$a3,0xbc($t7)
/*  f011e4c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f011e50:	c4281f14 */ 	lwc1	$f8,0x1f14($at)
/*  f011e54:	46004181 */ 	sub.s	$f6,$f8,$f0
/*  f011e58:	10000010 */ 	beqz	$zero,.NB0f011e9c
/*  f011e5c:	e7a60088 */ 	swc1	$f6,0x88($sp)
.NB0f011e60:
/*  f011e60:	8e2a0314 */ 	lw	$t2,0x314($s1)
/*  f011e64:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f011e68:	3c01800a */ 	lui	$at,0x800a
/*  f011e6c:	55400003 */ 	bnezl	$t2,.NB0f011e7c
/*  f011e70:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f011e74:	ac2e2648 */ 	sw	$t6,0x2648($at)
/*  f011e78:	8e2b0284 */ 	lw	$t3,0x284($s1)
.NB0f011e7c:
/*  f011e7c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f011e80:	44816000 */ 	mtc1	$at,$f12
/*  f011e84:	0fc60179 */ 	jal	scenarioChooseSpawnLocation
/*  f011e88:	8d6700bc */ 	lw	$a3,0xbc($t3)
/*  f011e8c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f011e90:	c4301f18 */ 	lwc1	$f16,0x1f18($at)
/*  f011e94:	46008281 */ 	sub.s	$f10,$f16,$f0
/*  f011e98:	e7aa0088 */ 	swc1	$f10,0x88($sp)
.NB0f011e9c:
/*  f011e9c:	8e220284 */ 	lw	$v0,0x284($s1)
.NB0f011ea0:
/*  f011ea0:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f011ea4:	3c0541f0 */ 	lui	$a1,0x41f0
/*  f011ea8:	2449161e */ 	addiu	$t1,$v0,0x161e
/*  f011eac:	244d161c */ 	addiu	$t5,$v0,0x161c
/*  f011eb0:	244c19b0 */ 	addiu	$t4,$v0,0x19b0
/*  f011eb4:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f011eb8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f011ebc:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f011ec0:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f011ec4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f011ec8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f011ecc:	0c00ad7e */ 	jal	cdFindGroundY
/*  f011ed0:	2447161a */ 	addiu	$a3,$v0,0x161a
/*  f011ed4:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011ed8:	3c0143b4 */ 	lui	$at,0x43b4
/*  f011edc:	44813000 */ 	mtc1	$at,$f6
/*  f011ee0:	c45219c4 */ 	lwc1	$f18,0x19c4($v0)
/*  f011ee4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f011ee8:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f011eec:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f011ef0:	e7a400a0 */ 	swc1	$f4,0xa0($sp)
/*  f011ef4:	e4400074 */ 	swc1	$f0,0x74($v0)
/*  f011ef8:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011efc:	e7000078 */ 	swc1	$f0,0x78($t8)
/*  f011f00:	c7a80088 */ 	lwc1	$f8,0x88($sp)
/*  f011f04:	c42a1f1c */ 	lwc1	$f10,0x1f1c($at)
/*  f011f08:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f011f0c:	46064402 */ 	mul.s	$f16,$f8,$f6
/*  f011f10:	460a8483 */ 	div.s	$f18,$f16,$f10
/*  f011f14:	e7320144 */ 	swc1	$f18,0x144($t9)
/*  f011f18:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f011f1c:	0fc2d8ae */ 	jal	func0f0b85a0
/*  f011f20:	2484036c */ 	addiu	$a0,$a0,0x36c
/*  f011f24:	0c006d55 */ 	jal	sinf
/*  f011f28:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f011f2c:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f011f30:	46000107 */ 	neg.s	$f4,$f0
/*  f011f34:	44804000 */ 	mtc1	$zero,$f8
/*  f011f38:	e5e4036c */ 	swc1	$f4,0x36c($t7)
/*  f011f3c:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f011f40:	e5480370 */ 	swc1	$f8,0x370($t2)
/*  f011f44:	0c006d52 */ 	jal	cosf
/*  f011f48:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f011f4c:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f011f50:	e5c00374 */ 	swc1	$f0,0x374($t6)
/*  f011f54:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f011f58:	c7a2009c */ 	lwc1	$f2,0x9c($sp)
/*  f011f5c:	e5620310 */ 	swc1	$f2,0x310($t3)
/*  f011f60:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f011f64:	8d2d00bc */ 	lw	$t5,0xbc($t1)
/*  f011f68:	e5a20008 */ 	swc1	$f2,0x8($t5)
/*  f011f6c:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f011f70:	c7a200a0 */ 	lwc1	$f2,0xa0($sp)
/*  f011f74:	e5820314 */ 	swc1	$f2,0x314($t4)
/*  f011f78:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f011f7c:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f011f80:	e722000c */ 	swc1	$f2,0xc($t9)
/*  f011f84:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f011f88:	c7a200a4 */ 	lwc1	$f2,0xa4($sp)
/*  f011f8c:	e5e20318 */ 	swc1	$f2,0x318($t7)
/*  f011f90:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f011f94:	8d4e00bc */ 	lw	$t6,0xbc($t2)
/*  f011f98:	e5c20010 */ 	swc1	$f2,0x10($t6)
/*  f011f9c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f011fa0:	0fc193ab */ 	jal	propDeregisterRooms
/*  f011fa4:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f011fa8:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f011fac:	87a9008c */ 	lh	$t1,0x8c($sp)
/*  f011fb0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f011fb4:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f011fb8:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f011fbc:	a5890028 */ 	sh	$t1,0x28($t4)
/*  f011fc0:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f011fc4:	8f2f00bc */ 	lw	$t7,0xbc($t9)
/*  f011fc8:	a5f8002a */ 	sh	$t8,0x2a($t7)
/*  f011fcc:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f011fd0:	87a7008c */ 	lh	$a3,0x8c($sp)
/*  f011fd4:	24450394 */ 	addiu	$a1,$v0,0x394
/*  f011fd8:	0fc2fdfb */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f011fdc:	24460388 */ 	addiu	$a2,$v0,0x388
/*  f011fe0:	0fc0786c */ 	jal	getNumChrSlots
/*  f011fe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f011fe8:	18400026 */ 	blez	$v0,.NB0f012084
/*  f011fec:	00402025 */ 	or	$a0,$v0,$zero
/*  f011ff0:	000428c0 */ 	sll	$a1,$a0,0x3
/*  f011ff4:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f011ff8:	00052880 */ 	sll	$a1,$a1,0x2
/*  f011ffc:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f012000:	00052880 */ 	sll	$a1,$a1,0x2
/*  f012004:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f012008:	3c068006 */ 	lui	$a2,0x8006
/*  f01200c:	24c64e98 */ 	addiu	$a2,$a2,0x4e98
/*  f012010:	000528c0 */ 	sll	$a1,$a1,0x3
/*  f012014:	00001025 */ 	or	$v0,$zero,$zero
/*  f012018:	24080048 */ 	addiu	$t0,$zero,0x48
/*  f01201c:	2407fffe */ 	addiu	$a3,$zero,-2
/*  f012020:	8cca0000 */ 	lw	$t2,0x0($a2)
.NB0f012024:
/*  f012024:	004a1821 */ 	addu	$v1,$v0,$t2
/*  f012028:	846e017e */ 	lh	$t6,0x17e($v1)
/*  f01202c:	24420368 */ 	addiu	$v0,$v0,0x368
/*  f012030:	54ee0012 */ 	bnel	$a3,$t6,.NB0f01207c
/*  f012034:	0045082a */ 	slt	$at,$v0,$a1
/*  f012038:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f01203c:	8e290338 */ 	lw	$t1,0x338($s1)
/*  f012040:	8d6d00bc */ 	lw	$t5,0xbc($t3)
/*  f012044:	01a96023 */ 	subu	$t4,$t5,$t1
/*  f012048:	0188001a */ 	div	$zero,$t4,$t0
/*  f01204c:	0000c812 */ 	mflo	$t9
/*  f012050:	a479017e */ 	sh	$t9,0x17e($v1)
/*  f012054:	15000002 */ 	bnez	$t0,.NB0f012060
/*  f012058:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01205c:	0007000d */ 	break	0x7
.NB0f012060:
/*  f012060:	2401ffff */ 	addiu	$at,$zero,-1
/*  f012064:	15010004 */ 	bne	$t0,$at,.NB0f012078
/*  f012068:	3c018000 */ 	lui	$at,0x8000
/*  f01206c:	15810002 */ 	bne	$t4,$at,.NB0f012078
/*  f012070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012074:	0006000d */ 	break	0x6
.NB0f012078:
/*  f012078:	0045082a */ 	slt	$at,$v0,$a1
.NB0f01207c:
/*  f01207c:	5420ffe9 */ 	bnezl	$at,.NB0f012024
/*  f012080:	8cca0000 */ 	lw	$t2,0x0($a2)
.NB0f012084:
/*  f012084:	0fc3243d */ 	jal	bmove0f0cb8c4
/*  f012088:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f01208c:	8e380318 */ 	lw	$t8,0x318($s1)
/*  f012090:	13000005 */ 	beqz	$t8,.NB0f0120a8
/*  f012094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012098:	0fc2dcd4 */ 	jal	func0f0b9674
/*  f01209c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0120a0:	10000003 */ 	beqz	$zero,.NB0f0120b0
/*  f0120a4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0120a8:
/*  f0120a8:	0fc2ddbf */ 	jal	func0f0b9a20
/*  f0120ac:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0120b0:
/*  f0120b0:	3c048007 */ 	lui	$a0,0x8007
/*  f0120b4:	24842e28 */ 	addiu	$a0,$a0,0x2e28
/*  f0120b8:	00007840 */ 	sll	$t7,$zero,0x1
/*  f0120bc:	008f5021 */ 	addu	$t2,$a0,$t7
/*  f0120c0:	854e0000 */ 	lh	$t6,0x0($t2)
/*  f0120c4:	3c038007 */ 	lui	$v1,0x8007
/*  f0120c8:	24632e3c */ 	addiu	$v1,$v1,0x2e3c
/*  f0120cc:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0120d0:	19c00009 */ 	blez	$t6,.NB0f0120f8
/*  f0120d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0120d8:	244b0001 */ 	addiu	$t3,$v0,0x1
.NB0f0120dc:
/*  f0120dc:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f0120e0:	008d4821 */ 	addu	$t1,$a0,$t5
/*  f0120e4:	852c0000 */ 	lh	$t4,0x0($t1)
/*  f0120e8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0120ec:	01601025 */ 	or	$v0,$t3,$zero
/*  f0120f0:	5d80fffa */ 	bgtzl	$t4,.NB0f0120dc
/*  f0120f4:	244b0001 */ 	addiu	$t3,$v0,0x1
.NB0f0120f8:
/*  f0120f8:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0120fc:	3c02800a */ 	lui	$v0,0x800a
/*  f012100:	3c03800a */ 	lui	$v1,0x800a
/*  f012104:	af201b84 */ 	sw	$zero,0x1b84($t9)
/*  f012108:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f01210c:	2463e6d0 */ 	addiu	$v1,$v1,-6448
/*  f012110:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f012114:	af0000e0 */ 	sw	$zero,0xe0($t8)
.NB0f012118:
/*  f012118:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f01211c:	1443fffe */ 	bne	$v0,$v1,.NB0f012118
/*  f012120:	ac4004b4 */ 	sw	$zero,0x4b4($v0)
/*  f012124:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f012128:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f01212c:	0fc2d911 */ 	jal	currentPlayerChooseBodyAndHead
/*  f012130:	00003025 */ 	or	$a2,$zero,$zero
/*  f012134:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012138:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f01213c:	8d4e00bc */ 	lw	$t6,0xbc($t2)
/*  f012140:	8dcb0004 */ 	lw	$t3,0x4($t6)
/*  f012144:	a56f0010 */ 	sh	$t7,0x10($t3)
/*  f012148:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f01214c:	8fad0044 */ 	lw	$t5,0x44($sp)
/*  f012150:	8d2c00bc */ 	lw	$t4,0xbc($t1)
/*  f012154:	8d990004 */ 	lw	$t9,0x4($t4)
/*  f012158:	a32d0006 */ 	sb	$t5,0x6($t9)
/*  f01215c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f012160:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f012164:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f012168:	03e00008 */ 	jr	$ra
/*  f01216c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#endif

// regalloc
//void currentPlayerInit(void)
//{
//	struct coord pos = var800623a4;
//	s16 rooms[8];
//	f32 turnanglerad = 0;
//	f32 groundy;
//	bool hasdefaultweapon = false;
//	s32 *cmd = g_StageSetup.intro;
//	u8 haseyespy = false;
//	s32 stack[7];
//	s32 i;
//	s32 numchrs;
//	struct gecreditsdata *thing;
//	f32 tmp;
//	s32 bodynum;
//	s32 headnum;
//
//	viResetDefaultModeIf4Mb();
//	func0f18e558();
//
//	g_InCutscene = false;
//	g_CutsceneFrameOverrun240 = 0;
//	var8007072c = 1;
//	var80070738 = 0;
//	var8007073c = 0;
//
//	g_CurrentGeCreditsData = NULL;
//	g_Vars.currentplayer->bondexploding = false;
//	g_NumSpawnPoints = 0;
//	g_Vars.currentplayer->bondtankexplode = false;
//	g_Vars.currentplayer->unk1bd4 = 0;
//	g_PlayersWithControl[0] = true;
//	g_PlayersWithControl[1] = true;
//	g_PlayersWithControl[2] = true;
//	g_PlayersWithControl[3] = true;
//	g_PlayerInvincible = false;
//
//	setTickMode(TICKMODE_0);
//
//	var80070744 = 0;
//	var80070748 = 0;
//	var8007074c = 0;
//
//	g_Vars.currentplayer->bondviewlevtime60 = 0;
//	g_Vars.currentplayer->bondwatchtime60 = 0;
//	g_Vars.currentplayer->introanimnum = 0;
//
//	g_DefaultWeapons[HAND_LEFT] = 0;
//	g_DefaultWeapons[HAND_RIGHT] = 0;
//
//	if (cmd) {
//		while (cmd[0] != INTROCMD_END) {
//			switch (*cmd) {
//			case INTROCMD_SPAWN:
//				if (cmd[2] == 0) {
//					g_SpawnPoints[g_NumSpawnPoints++] = cmd[1];
//				}
//				cmd += 3;
//				break;
//			case INTROCMD_CASE:
//			case INTROCMD_CASERESPAWN:
//				cmd += 3;
//				break;
//			case INTROCMD_HILL:
//				cmd += 2;
//				break;
//			case INTROCMD_WEAPON:
//				if (cmd[3] == 0 && g_Vars.currentplayer != g_Vars.anti) {
//					weaponLoadProjectileModels(cmd[1]);
//
//					if (cmd[2] >= 0) {
//						weaponLoadProjectileModels(cmd[2]);
//						invGiveDoubleWeapon(cmd[1], cmd[2]);
//					} else {
//						invGiveSingleWeapon(cmd[1]);
//					}
//
//					if (!hasdefaultweapon) {
//						g_DefaultWeapons[HAND_RIGHT] = cmd[1];
//
//						if (cmd[2] >= 0) {
//							g_DefaultWeapons[HAND_LEFT] = cmd[2];
//						}
//
//						hasdefaultweapon = true;
//					}
//
//					if (cmd[1] == WEAPON_EYESPY) {
//						haseyespy = true;
//					}
//				}
//				cmd += 4;
//				break;
//			case INTROCMD_AMMO:
//				if (cmd[3] == 0 && g_Vars.currentplayer != g_Vars.anti) {
//					bgunSetAmmoQuantity(cmd[1], cmd[2]);
//				}
//				cmd += 4;
//				break;
//			case INTROCMD_3:
//				cmd += 8;
//				break;
//			case INTROCMD_4:
//				cmd += 2;
//				break;
//			case INTROCMD_OUTFIT:
//				g_Vars.currentplayer->bondtype = cmd[1];
//				cmd += 2;
//				break;
//			case INTROCMD_6:
//				cmd += 10;
//				break;
//			case INTROCMD_WATCHTIME:
//				g_Vars.currentplayer->bondwatchtime60 = 0;
//				if (cmd[2] > 0) {
//					g_Vars.currentplayer->bondwatchtime60 += (cmd[2] % 60) * 3600;
//				}
//				if (cmd[1] > 0) {
//					g_Vars.currentplayer->bondwatchtime60 += (cmd[1] % 12) * 3600 * 60;
//				}
//				cmd += 3;
//				break;
//			case INTROCMD_CREDITOFFSET:
//				thing = (struct gecreditsdata *)&g_GeCreditsData[cmd[1]];
//				g_CurrentGeCreditsData = thing;
//				while (thing->text1 || thing->text2) {
//					thing++;
//				}
//				cmd += 2;
//				break;
//			default:
//				cmd++;
//			}
//		}
//	}
//
//	invGiveSingleWeapon(WEAPON_UNARMED);
//
//	if (cheatIsActive(CHEAT_TRENTSMAGNUM)) {
//		invGiveSingleWeapon(WEAPON_DY357LX);
//		bgunSetAmmoQuantity(AMMOTYPE_MAGNUM, 80);
//	}
//
//	if (cheatIsActive(CHEAT_FARSIGHT)) {
//		invGiveSingleWeapon(WEAPON_FARSIGHT);
//		bgunSetAmmoQuantity(AMMOTYPE_FARSIGHT, 80);
//	}
//
//	if (cheatIsActive(CHEAT_CLOAKINGDEVICE)) {
//		invGiveSingleWeapon(WEAPON_CLOAKINGDEVICE);
//		bgunSetAmmoQuantity(AMMOTYPE_CLOAK, 7200);
//	}
//
//	if (cheatIsActive(CHEAT_PERFECTDARKNESS)) {
//		invGiveSingleWeapon(WEAPON_NIGHTVISION);
//	}
//
//	if (cheatIsActive(CHEAT_RTRACKER)) {
//		invGiveSingleWeapon(WEAPON_RTRACKER);
//	}
//
//	if (cheatIsActive(CHEAT_ROCKETLAUNCHER)) {
//		invGiveSingleWeapon(WEAPON_ROCKETLAUNCHER);
//		bgunSetAmmoQuantity(AMMOTYPE_ROCKET, 10);
//	}
//
//	if (cheatIsActive(CHEAT_SNIPERRIFLE)) {
//		invGiveSingleWeapon(WEAPON_SNIPERRIFLE);
//		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
//	}
//
//	if (cheatIsActive(CHEAT_XRAYSCANNER)) {
//		invGiveSingleWeapon(WEAPON_XRAYSCANNER);
//	}
//
//	if (cheatIsActive(CHEAT_SUPERDRAGON)) {
//		invGiveSingleWeapon(WEAPON_SUPERDRAGON);
//		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
//		bgunSetAmmoQuantity(AMMOTYPE_DEVASTATOR, 20);
//	}
//
//	if (cheatIsActive(CHEAT_LAPTOPGUN)) {
//		invGiveSingleWeapon(WEAPON_LAPTOPGUN);
//		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
//	}
//
//	if (cheatIsActive(CHEAT_PHOENIX)) {
//		invGiveSingleWeapon(WEAPON_PHOENIX);
//		bgunSetAmmoQuantity(AMMOTYPE_PISTOL, 200);
//	}
//
//	if (cheatIsActive(CHEAT_PSYCHOSISGUN) || cheatIsActive(CHEAT_ALLGUNS)) {
//		bgunSetAmmoQuantity(AMMOTYPE_PSYCHOSIS, 4);
//
//		if (cheatIsActive(CHEAT_PSYCHOSISGUN)) {
//			invGiveSingleWeapon(WEAPON_PSYCHOSISGUN);
//		}
//	}
//
//	if (cheatIsActive(CHEAT_PP9I)) {
//		invGiveSingleWeapon(WEAPON_PP9I);
//		bgunSetAmmoQuantity(AMMOTYPE_PISTOL, 200);
//	}
//
//	if (cheatIsActive(CHEAT_CC13)) {
//		invGiveSingleWeapon(WEAPON_CC13);
//		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
//	}
//
//	if (cheatIsActive(CHEAT_KL01313)) {
//		invGiveSingleWeapon(WEAPON_KL01313);
//		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
//	}
//
//	if (cheatIsActive(CHEAT_KF7SPECIAL)) {
//		invGiveSingleWeapon(WEAPON_KF7SPECIAL);
//		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
//	}
//
//	if (cheatIsActive(CHEAT_ZZT)) {
//		invGiveSingleWeapon(WEAPON_ZZT);
//		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
//	}
//
//	if (cheatIsActive(CHEAT_DMC)) {
//		invGiveSingleWeapon(WEAPON_DMC);
//		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
//	}
//
//	if (cheatIsActive(CHEAT_AR53)) {
//		invGiveSingleWeapon(WEAPON_AR53);
//		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
//	}
//
//	if (cheatIsActive(CHEAT_RCP45)) {
//		invGiveSingleWeapon(WEAPON_RCP45);
//		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
//	}
//
//	if (!hasdefaultweapon) {
//		g_DefaultWeapons[HAND_RIGHT] = WEAPON_UNARMED;
//	}
//
//	g_Vars.currentplayer->prop = propAllocate();
//	g_Vars.currentplayer->prop->chr = NULL;
//	g_Vars.currentplayer->prop->type = PROPTYPE_PLAYER;
//
//	propActivate(g_Vars.currentplayer->prop);
//	propEnable(g_Vars.currentplayer->prop);
//	chrInit(g_Vars.currentplayer->prop, NULL);
//
//	if (g_Vars.coopplayernum >= 0) {
//		g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
//	} else if (g_Vars.antiplayernum >= 0) {
//		if (g_Vars.currentplayer == g_Vars.bond) {
//			g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
//		} else {
//			g_Vars.currentplayer->prop->chr->team = TEAM_ENEMY;
//		}
//	} else {
//		if (g_Vars.mplayerisrunning) {
//			g_Vars.currentplayer->prop->chr->team = 1 << g_MpPlayers[g_Vars.currentplayerstats->mpindex].base.team;
//		} else {
//			g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
//		}
//	}
//
//	if (haseyespy) {
//		currentPlayerInitEyespy();
//	}
//
//	if (g_NumSpawnPoints > 0) {
//		if (g_Vars.coopplayernum >= 0) {
//			turnanglerad = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop);
//		} else if (g_Vars.antiplayernum >= 0) {
//			turnanglerad = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop);
//		} else {
//			if (g_Vars.mplayerisrunning == 0) {
//				g_NumSpawnPoints = 1;
//			}
//
//			turnanglerad = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop);
//		}
//	}
//
//	groundy = cdFindGroundY(&pos, 30, rooms,
//			&g_Vars.currentplayer->floorcol,
//			&g_Vars.currentplayer->floortype,
//			&g_Vars.currentplayer->floorflags,
//			&g_Vars.currentplayer->floorroom,
//			0, 0);
//
//	pos.y = g_Vars.currentplayer->vv_eyeheight + groundy;
//	g_Vars.currentplayer->vv_manground = groundy;
//	g_Vars.currentplayer->vv_ground = groundy;
//	g_Vars.currentplayer->vv_theta = (turnanglerad * 360.0f) / M_BADTAU;
//
//	func0f0b85a0(&g_Vars.currentplayer->bond2, &pos);
//
//	g_Vars.currentplayer->bond2.unk00.x = -sinf(turnanglerad);
//	g_Vars.currentplayer->bond2.unk00.y = 0;
//	g_Vars.currentplayer->bond2.unk00.z = cosf(turnanglerad);
//
//	g_Vars.currentplayer->bondprevpos.x = (tmp = pos.x);
//	g_Vars.currentplayer->prop->pos.x = tmp;
//	g_Vars.currentplayer->bondprevpos.y = (tmp = pos.y);
//	g_Vars.currentplayer->prop->pos.y = tmp;
//	g_Vars.currentplayer->bondprevpos.z = (tmp = pos.z);
//	g_Vars.currentplayer->prop->pos.z = tmp;
//
//	propDeregisterRooms(g_Vars.currentplayer->prop);
//
//	g_Vars.currentplayer->prop->rooms[0] = rooms[0];
//	g_Vars.currentplayer->prop->rooms[1] = -1;
//
//	currentPlayerSetCamPropertiesWithRoom(&pos,
//			&g_Vars.currentplayer->bond2.unk28,
//			&g_Vars.currentplayer->bond2.unk1c, rooms[0]);
//
//	numchrs = getNumChrSlots();
//
//	for (i = 0; i < numchrs; i++) {
//		if (g_ChrSlots[i].target == -2) {
//			g_ChrSlots[i].target = g_Vars.currentplayer->prop - g_Vars.props;
//		}
//	}
//
//	bmove0f0cb8c4(g_Vars.currentplayer);
//
//	if (g_Vars.normmplayerisrunning) {
//		func0f0b9674();
//	} else {
//		func0f0b9a20();
//	}
//
//	g_NumDeathAnimations = 0;
//
//	while (g_DeathAnimations[g_NumDeathAnimations] > 0) {
//		g_NumDeathAnimations++;
//	}
//
//	g_Vars.currentplayer->tickdiefinished = false;
//	g_Vars.currentplayer->unk00e0 = 0;
//
//	for (i = 0; i != 4; i++) {
//		g_Vars.aibuddies[i] = 0;
//	}
//
//	currentPlayerChooseBodyAndHead(&bodynum, &headnum, 0);
//	g_Vars.currentplayer->prop->chr->bodynum = bodynum;
//	g_Vars.currentplayer->prop->chr->headnum = headnum;
//}
