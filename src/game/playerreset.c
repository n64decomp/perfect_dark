#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/inv.h"
#include "game/playerreset.h"
#include "game/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/inv.h"
#include "game/stagetable.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/collision.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "lib/anim.h"
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
/*  f011294:	0c0048f2 */ 	jal	mempAlloc
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

void playerInitEyespy(void)
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
			g_Vars.currentplayer->eyespy = mempAlloc(sizeof(struct eyespy), MEMPOOL_STAGE);

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
				g_Vars.currentplayer->eyespy->held = true;
				g_Vars.currentplayer->eyespy->deployed = false;
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

struct cmd32 {
	s32 type;
	s32 param1;
	s32 param2;
	s32 param3;
};

void playerReset(void)
{
	struct coord pos = {0, 0, 0};
	s16 rooms[8];
	f32 turnanglerad = 0;
	f32 groundy;
	bool hasdefaultweapon = false;
	struct cmd32 *cmd = (struct cmd32 *)g_StageSetup.intro;
	u8 haseyespy = false;
	s32 stack[7];
	s32 i;
	s32 numchrs;
	struct gecreditsdata *thing;
	struct chrdata *chr;
	s32 bodynum;
	s32 headnum;

	playerResetLoResIf4Mb();
	func0f18e558();

	g_InCutscene = false;

#if PAL
	var8009e388pf = 0;
#else
	g_CutsceneFrameOverrun240 = 0;
#endif

	var8007072c = 1;
	var80070738 = 0;
	var8007073c = 0;

	g_CurrentGeCreditsData = NULL;
	g_Vars.currentplayer->bondexploding = false;
	g_NumSpawnPoints = 0;
	g_Vars.currentplayer->bondtankexplode = false;
	g_Vars.currentplayer->gunmem2 = NULL;
	g_PlayersWithControl[0] = true;
	g_PlayersWithControl[1] = true;
	g_PlayersWithControl[2] = true;
	g_PlayersWithControl[3] = true;
	g_PlayerInvincible = false;

	playerSetTickMode(TICKMODE_GE_FADEIN);

	g_PlayerTriggerGeFadeIn = 0;
	var80070748 = 0;
	var8007074c = 0;

	g_Vars.currentplayer->bondviewlevtime60 = 0;
	g_Vars.currentplayer->bondwatchtime60 = 0;
	g_Vars.currentplayer->introanimnum = 0;

	g_DefaultWeapons[HAND_LEFT] = 0;
	g_DefaultWeapons[HAND_RIGHT] = 0;

	if (cmd) {
		while (cmd->type != INTROCMD_END) {
			switch (cmd->type) {
			case INTROCMD_SPAWN:
				if (cmd->param2 == 0) {
					g_SpawnPoints[g_NumSpawnPoints++] = cmd->param1;
				}
				cmd = (struct cmd32 *)((u32)cmd + 12);
				break;
			case INTROCMD_CASE:
			case INTROCMD_CASERESPAWN:
				cmd = (struct cmd32 *)((u32)cmd + 12);
				break;
			case INTROCMD_HILL:
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			case INTROCMD_WEAPON:
				if (cmd->param3 == 0 && g_Vars.currentplayer != g_Vars.anti) {
					weaponLoadProjectileModels(cmd->param1);

					if (cmd->param2 >= 0) {
						weaponLoadProjectileModels(cmd->param2);
						invGiveDoubleWeapon(cmd->param1, cmd->param2);
					} else {
						invGiveSingleWeapon(cmd->param1);
					}

					if (!hasdefaultweapon) {
						g_DefaultWeapons[HAND_RIGHT] = cmd->param1;

						if (cmd->param2 >= 0) {
							g_DefaultWeapons[HAND_LEFT] = cmd->param2;
						}

						hasdefaultweapon = true;
					}

					if (cmd->param1 == WEAPON_EYESPY) {
						haseyespy = true;
					}
				}
				cmd = (struct cmd32 *)((u32)cmd + 16);
				break;
			case INTROCMD_AMMO:
				if (cmd->param3 == 0 && g_Vars.currentplayer != g_Vars.anti) {
					bgunSetAmmoQuantity(cmd->param1, cmd->param2);
				}
				cmd = (struct cmd32 *)((u32)cmd + 16);
				break;
			case INTROCMD_3:
				cmd = (struct cmd32 *)((u32)cmd + 32);
				break;
			case INTROCMD_4:
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			case INTROCMD_OUTFIT:
				g_Vars.currentplayer->bondtype = cmd->param1;
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			case INTROCMD_6:
				cmd = (struct cmd32 *)((u32)cmd + 40);
				break;
			case INTROCMD_WATCHTIME:
				g_Vars.currentplayer->bondwatchtime60 = 0;
				if (cmd->param2 > 0) {
					g_Vars.currentplayer->bondwatchtime60 += (cmd->param2 % 60) * 3600;
				}
				if (cmd->param1 > 0) {
					g_Vars.currentplayer->bondwatchtime60 += (cmd->param1 % 12) * 3600 * 60;
				}
				cmd = (struct cmd32 *)((u32)cmd + 12);
				break;
			case INTROCMD_CREDITOFFSET:
				thing = (struct gecreditsdata *)((s32)g_GeCreditsData + cmd->param1);
				g_CurrentGeCreditsData = thing;
				while (thing->text1 || thing->text2) {
					thing++;
				}
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			default:
				cmd = (struct cmd32 *)((u32)cmd + 4);
			}
		}
	}

	invGiveSingleWeapon(WEAPON_UNARMED);

	if (cheatIsActive(CHEAT_TRENTSMAGNUM)) {
		invGiveSingleWeapon(WEAPON_DY357LX);
		bgunSetAmmoQuantity(AMMOTYPE_MAGNUM, 80);
	}

	if (cheatIsActive(CHEAT_FARSIGHT)) {
		invGiveSingleWeapon(WEAPON_FARSIGHT);
		bgunSetAmmoQuantity(AMMOTYPE_FARSIGHT, 80);
	}

	if (cheatIsActive(CHEAT_CLOAKINGDEVICE)) {
		invGiveSingleWeapon(WEAPON_CLOAKINGDEVICE);
#if VERSION >= VERSION_PAL_FINAL
		bgunSetAmmoQuantity(AMMOTYPE_CLOAK, TICKS(7200));
#else
		bgunSetAmmoQuantity(AMMOTYPE_CLOAK, 7200);
#endif
	}

	if (cheatIsActive(CHEAT_PERFECTDARKNESS)) {
		invGiveSingleWeapon(WEAPON_NIGHTVISION);
	}

	if (cheatIsActive(CHEAT_RTRACKER)) {
		invGiveSingleWeapon(WEAPON_RTRACKER);
	}

	if (cheatIsActive(CHEAT_ROCKETLAUNCHER)) {
		invGiveSingleWeapon(WEAPON_ROCKETLAUNCHER);
		bgunSetAmmoQuantity(AMMOTYPE_ROCKET, 10);
	}

	if (cheatIsActive(CHEAT_SNIPERRIFLE)) {
		invGiveSingleWeapon(WEAPON_SNIPERRIFLE);
		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheatIsActive(CHEAT_XRAYSCANNER)) {
		invGiveSingleWeapon(WEAPON_XRAYSCANNER);
	}

	if (cheatIsActive(CHEAT_SUPERDRAGON)) {
		invGiveSingleWeapon(WEAPON_SUPERDRAGON);
		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
		bgunSetAmmoQuantity(AMMOTYPE_DEVASTATOR, 20);
	}

	if (cheatIsActive(CHEAT_LAPTOPGUN)) {
		invGiveSingleWeapon(WEAPON_LAPTOPGUN);
		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
	}

	if (cheatIsActive(CHEAT_PHOENIX)) {
		invGiveSingleWeapon(WEAPON_PHOENIX);
		bgunSetAmmoQuantity(AMMOTYPE_PISTOL, 200);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (cheatIsActive(CHEAT_PSYCHOSISGUN) || cheatIsActive(CHEAT_ALLGUNS)) {
		bgunSetAmmoQuantity(AMMOTYPE_PSYCHOSIS, 4);

		if (cheatIsActive(CHEAT_PSYCHOSISGUN)) {
			invGiveSingleWeapon(WEAPON_PSYCHOSISGUN);
		}
	}
#else
	if (cheatIsActive(CHEAT_PSYCHOSISGUN)) {
		invGiveSingleWeapon(WEAPON_PSYCHOSISGUN);
		bgunSetAmmoQuantity(AMMOTYPE_PSYCHOSIS, 4);
	}
#endif

	if (cheatIsActive(CHEAT_PP9I)) {
		invGiveSingleWeapon(WEAPON_PP9I);
		bgunSetAmmoQuantity(AMMOTYPE_PISTOL, 200);
	}

	if (cheatIsActive(CHEAT_CC13)) {
		invGiveSingleWeapon(WEAPON_CC13);
		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheatIsActive(CHEAT_KL01313)) {
		invGiveSingleWeapon(WEAPON_KL01313);
		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
	}

	if (cheatIsActive(CHEAT_KF7SPECIAL)) {
		invGiveSingleWeapon(WEAPON_KF7SPECIAL);
		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheatIsActive(CHEAT_ZZT)) {
		invGiveSingleWeapon(WEAPON_ZZT);
		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
	}

	if (cheatIsActive(CHEAT_DMC)) {
		invGiveSingleWeapon(WEAPON_DMC);
		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
	}

	if (cheatIsActive(CHEAT_AR53)) {
		invGiveSingleWeapon(WEAPON_AR53);
		bgunSetAmmoQuantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheatIsActive(CHEAT_RCP45)) {
		invGiveSingleWeapon(WEAPON_RCP45);
		bgunSetAmmoQuantity(AMMOTYPE_SMG, 200);
	}

	if (!hasdefaultweapon) {
		g_DefaultWeapons[HAND_RIGHT] = WEAPON_UNARMED;
	}

	g_Vars.currentplayer->prop = propAllocate();
	g_Vars.currentplayer->prop->chr = NULL;
	g_Vars.currentplayer->prop->type = PROPTYPE_PLAYER;

	propActivate(g_Vars.currentplayer->prop);
	propEnable(g_Vars.currentplayer->prop);
	chrInit(g_Vars.currentplayer->prop, NULL);

	if (g_Vars.coopplayernum >= 0) {
		g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
	} else if (g_Vars.antiplayernum >= 0) {
		if (g_Vars.currentplayer == g_Vars.bond) {
			g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
		} else {
			g_Vars.currentplayer->prop->chr->team = TEAM_ENEMY;
		}
	} else {
		if (g_Vars.mplayerisrunning) {
			g_Vars.currentplayer->prop->chr->team = 1 << g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.team;
		} else {
			g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
		}
	}

	if (haseyespy) {
		playerInitEyespy();
	}

	if (g_NumSpawnPoints > 0) {
		if (g_Vars.coopplayernum >= 0) {
			turnanglerad = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop);
		} else if (g_Vars.antiplayernum >= 0) {
			turnanglerad = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop);
		} else {
			if (g_Vars.mplayerisrunning == 0) {
				g_NumSpawnPoints = 1;
			}

			turnanglerad = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop);
		}
	}

	groundy = cdFindGroundY(&pos, 30, rooms,
			&g_Vars.currentplayer->floorcol,
			&g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags,
			&g_Vars.currentplayer->floorroom,
			0, 0);

	pos.y = g_Vars.currentplayer->vv_eyeheight + groundy;
	g_Vars.currentplayer->vv_manground = groundy;
	g_Vars.currentplayer->vv_ground = groundy;
	g_Vars.currentplayer->vv_theta = (turnanglerad * 360.0f) / M_BADTAU;

	playerResetBond(&g_Vars.currentplayer->bond2, &pos);

	g_Vars.currentplayer->bond2.unk00.x = -sinf(turnanglerad);
	g_Vars.currentplayer->bond2.unk00.y = 0;
	g_Vars.currentplayer->bond2.unk00.z = cosf(turnanglerad);

	g_Vars.currentplayer->prop->pos.f[0] = g_Vars.currentplayer->bondprevpos.f[0] = pos.f[0];
	g_Vars.currentplayer->prop->pos.f[1] = g_Vars.currentplayer->bondprevpos.f[1] = pos.f[1];
	g_Vars.currentplayer->prop->pos.f[2] = g_Vars.currentplayer->bondprevpos.f[2] = pos.f[2];

	propDeregisterRooms(g_Vars.currentplayer->prop);

	g_Vars.currentplayer->prop->rooms[0] = rooms[0];
	g_Vars.currentplayer->prop->rooms[1] = -1;

	playerSetCamPropertiesWithRoom(&pos,
			&g_Vars.currentplayer->bond2.unk28,
			&g_Vars.currentplayer->bond2.unk1c, rooms[0]);

	numchrs = chrsGetNumSlots();

	for (i = 0; i < numchrs; i++) {
		chr = &g_ChrSlots[i];

		if (chr->target == -2) {
			chr->target = g_Vars.currentplayer->prop - g_Vars.props;
		}
	}

	bmove0f0cb8c4(g_Vars.currentplayer);

	if (g_Vars.normmplayerisrunning) {
		playersBeginMpSwirl();
	} else {
		player0f0b9a20();
	}

	g_NumDeathAnimations = 0;

	while (g_DeathAnimations[g_NumDeathAnimations] > 0) {
		g_NumDeathAnimations++;
	}

	g_Vars.currentplayer->tickdiefinished = false;
	g_Vars.currentplayer->chokehandle = NULL;

	for (i = 0; i != 4; i++) {
		g_Vars.aibuddies[i] = 0;
	}

	playerChooseBodyAndHead(&bodynum, &headnum, 0);
	g_Vars.currentplayer->prop->chr->bodynum = bodynum;
	g_Vars.currentplayer->prop->chr->headnum = headnum;
}
