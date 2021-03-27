#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "bss.h"
#include "lib/lib_3a100.h"
#include "lib/lib_446d0.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003a100
.late_rodata
glabel var70054a90
.word 0x3fb50481
.text
/*    3a100:	27bdff80 */ 	addiu	$sp,$sp,-128
/*    3a104:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3a108:	afa40080 */ 	sw	$a0,0x80($sp)
/*    3a10c:	afa50084 */ 	sw	$a1,0x84($sp)
/*    3a110:	afa60088 */ 	sw	$a2,0x88($sp)
/*    3a114:	8fae0084 */ 	lw	$t6,0x84($sp)
/*    3a118:	afae007c */ 	sw	$t6,0x7c($sp)
/*    3a11c:	3c0f8006 */ 	lui	$t7,%hi(alGlobals)
/*    3a120:	8deff114 */ 	lw	$t7,%lo(alGlobals)($t7)
/*    3a124:	8fb90088 */ 	lw	$t9,0x88($sp)
/*    3a128:	8df80034 */ 	lw	$t8,0x34($t7)
/*    3a12c:	001940c0 */ 	sll	$t0,$t9,0x3
/*    3a130:	01194021 */ 	addu	$t0,$t0,$t9
/*    3a134:	000840c0 */ 	sll	$t0,$t0,0x3
/*    3a138:	03084821 */ 	addu	$t1,$t8,$t0
/*    3a13c:	8d2a0020 */ 	lw	$t2,0x20($t1)
/*    3a140:	afaa0078 */ 	sw	$t2,0x78($sp)
/*    3a144:	afa00060 */ 	sw	$zero,0x60($sp)
/*    3a148:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    3a14c:	afab0058 */ 	sw	$t3,0x58($sp)
/*    3a150:	8fa40080 */ 	lw	$a0,0x80($sp)
/*    3a154:	8fa50084 */ 	lw	$a1,0x84($sp)
/*    3a158:	8fa60088 */ 	lw	$a2,0x88($sp)
/*    3a15c:	0c0111b4 */ 	jal	func000446d0
/*    3a160:	27a70058 */ 	addiu	$a3,$sp,0x58
/*    3a164:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    3a168:	240c07c0 */ 	addiu	$t4,$zero,0x7c0
/*    3a16c:	a7ac0070 */ 	sh	$t4,0x70($sp)
/*    3a170:	240d0930 */ 	addiu	$t5,$zero,0x930
/*    3a174:	a7ad006e */ 	sh	$t5,0x6e($sp)
/*    3a178:	a7a00074 */ 	sh	$zero,0x74($sp)
/*    3a17c:	240e0170 */ 	addiu	$t6,$zero,0x170
/*    3a180:	a7ae0072 */ 	sh	$t6,0x72($sp)
/*    3a184:	8faf0088 */ 	lw	$t7,0x88($sp)
/*    3a188:	3c19800a */ 	lui	$t9,%hi(var8009c344)
/*    3a18c:	032fc821 */ 	addu	$t9,$t9,$t7
/*    3a190:	9339c344 */ 	lbu	$t9,%lo(var8009c344)($t9)
/*    3a194:	1720001d */ 	bnez	$t9,.L0003a20c
/*    3a198:	00000000 */ 	nop
/*    3a19c:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*    3a1a0:	27080008 */ 	addiu	$t0,$t8,0x8
/*    3a1a4:	afa8007c */ 	sw	$t0,0x7c($sp)
/*    3a1a8:	afb80050 */ 	sw	$t8,0x50($sp)
/*    3a1ac:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3a1b0:	3c090c00 */ 	lui	$t1,0xc00
/*    3a1b4:	3529c000 */ 	ori	$t1,$t1,0xc000
/*    3a1b8:	ad490000 */ 	sw	$t1,0x0($t2)
/*    3a1bc:	87ab0070 */ 	lh	$t3,0x70($sp)
/*    3a1c0:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3a1c4:	3c0107c0 */ 	lui	$at,0x7c0
/*    3a1c8:	316cffff */ 	andi	$t4,$t3,0xffff
/*    3a1cc:	01816825 */ 	or	$t5,$t4,$at
/*    3a1d0:	adcd0004 */ 	sw	$t5,0x4($t6)
/*    3a1d4:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    3a1d8:	25f90008 */ 	addiu	$t9,$t7,0x8
/*    3a1dc:	afb9007c */ 	sw	$t9,0x7c($sp)
/*    3a1e0:	afaf004c */ 	sw	$t7,0x4c($sp)
/*    3a1e4:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*    3a1e8:	3c180c00 */ 	lui	$t8,0xc00
/*    3a1ec:	37184000 */ 	ori	$t8,$t8,0x4000
/*    3a1f0:	ad180000 */ 	sw	$t8,0x0($t0)
/*    3a1f4:	87a90070 */ 	lh	$t1,0x70($sp)
/*    3a1f8:	8fac004c */ 	lw	$t4,0x4c($sp)
/*    3a1fc:	3c010930 */ 	lui	$at,0x930
/*    3a200:	312affff */ 	andi	$t2,$t1,0xffff
/*    3a204:	01415825 */ 	or	$t3,$t2,$at
/*    3a208:	ad8b0004 */ 	sw	$t3,0x4($t4)
.L0003a20c:
/*    3a20c:	8fad0078 */ 	lw	$t5,0x78($sp)
/*    3a210:	8fae007c */ 	lw	$t6,0x7c($sp)
/*    3a214:	00002825 */ 	or	$a1,$zero,$zero
/*    3a218:	8da60028 */ 	lw	$a2,0x28($t5)
/*    3a21c:	87a70070 */ 	lh	$a3,0x70($sp)
/*    3a220:	01a02025 */ 	or	$a0,$t5,$zero
/*    3a224:	0c00ecdc */ 	jal	func0003b370
/*    3a228:	afae0010 */ 	sw	$t6,0x10($sp)
/*    3a22c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    3a230:	8faf0088 */ 	lw	$t7,0x88($sp)
/*    3a234:	3c19800a */ 	lui	$t9,%hi(var8009c344)
/*    3a238:	032fc821 */ 	addu	$t9,$t9,$t7
/*    3a23c:	9339c344 */ 	lbu	$t9,%lo(var8009c344)($t9)
/*    3a240:	1320000a */ 	beqz	$t9,.L0003a26c
/*    3a244:	00000000 */ 	nop
/*    3a248:	8fb80078 */ 	lw	$t8,0x78($sp)
/*    3a24c:	8fa8007c */ 	lw	$t0,0x7c($sp)
/*    3a250:	24050001 */ 	addiu	$a1,$zero,0x1
/*    3a254:	8f06002c */ 	lw	$a2,0x2c($t8)
/*    3a258:	24070930 */ 	addiu	$a3,$zero,0x930
/*    3a25c:	03002025 */ 	or	$a0,$t8,$zero
/*    3a260:	0c00ecdc */ 	jal	func0003b370
/*    3a264:	afa80010 */ 	sw	$t0,0x10($sp)
/*    3a268:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a26c:
/*    3a26c:	8fa90088 */ 	lw	$t1,0x88($sp)
/*    3a270:	3c0a800a */ 	lui	$t2,%hi(var8009c344)
/*    3a274:	afa00054 */ 	sw	$zero,0x54($sp)
/*    3a278:	01495021 */ 	addu	$t2,$t2,$t1
/*    3a27c:	914ac344 */ 	lbu	$t2,%lo(var8009c344)($t2)
.L0003a280:
/*    3a280:	8fab007c */ 	lw	$t3,0x7c($sp)
/*    3a284:	256c0008 */ 	addiu	$t4,$t3,0x8
/*    3a288:	afac007c */ 	sw	$t4,0x7c($sp)
/*    3a28c:	afab0048 */ 	sw	$t3,0x48($sp)
/*    3a290:	87ad006e */ 	lh	$t5,0x6e($sp)
/*    3a294:	3c0100ff */ 	lui	$at,0xff
/*    3a298:	3421ffff */ 	ori	$at,$at,0xffff
/*    3a29c:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    3a2a0:	01a17024 */ 	and	$t6,$t5,$at
/*    3a2a4:	3c010200 */ 	lui	$at,0x200
/*    3a2a8:	01c17825 */ 	or	$t7,$t6,$at
/*    3a2ac:	af2f0000 */ 	sw	$t7,0x0($t9)
/*    3a2b0:	8fa80048 */ 	lw	$t0,0x48($sp)
/*    3a2b4:	24180170 */ 	addiu	$t8,$zero,0x170
/*    3a2b8:	ad180004 */ 	sw	$t8,0x4($t0)
/*    3a2bc:	8fa90078 */ 	lw	$t1,0x78($sp)
/*    3a2c0:	a7a00076 */ 	sh	$zero,0x76($sp)
/*    3a2c4:	912a0008 */ 	lbu	$t2,0x8($t1)
/*    3a2c8:	19400125 */ 	blez	$t2,.L0003a760
/*    3a2cc:	00000000 */ 	nop
.L0003a2d0:
/*    3a2d0:	8fab0078 */ 	lw	$t3,0x78($sp)
/*    3a2d4:	87ad0076 */ 	lh	$t5,0x76($sp)
/*    3a2d8:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*    3a2dc:	000d7080 */ 	sll	$t6,$t5,0x2
/*    3a2e0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    3a2e4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    3a2e8:	018e7821 */ 	addu	$t7,$t4,$t6
/*    3a2ec:	afaf005c */ 	sw	$t7,0x5c($sp)
/*    3a2f0:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    3a2f4:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    3a2f8:	8fb90078 */ 	lw	$t9,0x78($sp)
/*    3a2fc:	00184080 */ 	sll	$t0,$t8,0x2
/*    3a300:	8d6d0000 */ 	lw	$t5,0x0($t3)
/*    3a304:	03284821 */ 	addu	$t1,$t9,$t0
/*    3a308:	8d2a0028 */ 	lw	$t2,0x28($t1)
/*    3a30c:	000d6023 */ 	negu	$t4,$t5
/*    3a310:	000c7040 */ 	sll	$t6,$t4,0x1
/*    3a314:	014e7821 */ 	addu	$t7,$t2,$t6
/*    3a318:	afaf0068 */ 	sw	$t7,0x68($sp)
/*    3a31c:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    3a320:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    3a324:	8fb80078 */ 	lw	$t8,0x78($sp)
/*    3a328:	00194080 */ 	sll	$t0,$t9,0x2
/*    3a32c:	8dac0004 */ 	lw	$t4,0x4($t5)
/*    3a330:	03084821 */ 	addu	$t1,$t8,$t0
/*    3a334:	8d2b0028 */ 	lw	$t3,0x28($t1)
/*    3a338:	000c5023 */ 	negu	$t2,$t4
/*    3a33c:	000a7040 */ 	sll	$t6,$t2,0x1
/*    3a340:	016e7821 */ 	addu	$t7,$t3,$t6
/*    3a344:	afaf0064 */ 	sw	$t7,0x64($sp)
/*    3a348:	8fb90088 */ 	lw	$t9,0x88($sp)
/*    3a34c:	3c18800a */ 	lui	$t8,%hi(var8009c344+0x2)
/*    3a350:	0319c021 */ 	addu	$t8,$t8,$t9
/*    3a354:	9318c346 */ 	lbu	$t8,%lo(var8009c344+0x2)($t8)
/*    3a358:	1300000e */ 	beqz	$t8,.L0003a394
/*    3a35c:	00000000 */ 	nop
/*    3a360:	3c08800a */ 	lui	$t0,%hi(var8009c344)
/*    3a364:	01194021 */ 	addu	$t0,$t0,$t9
/*    3a368:	9108c344 */ 	lbu	$t0,%lo(var8009c344)($t0)
/*    3a36c:	11000009 */ 	beqz	$t0,.L0003a394
/*    3a370:	00000000 */ 	nop
/*    3a374:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    3a378:	852d0008 */ 	lh	$t5,0x8($t1)
/*    3a37c:	000d6023 */ 	negu	$t4,$t5
/*    3a380:	a52c0008 */ 	sh	$t4,0x8($t1)
/*    3a384:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    3a388:	854b000a */ 	lh	$t3,0xa($t2)
/*    3a38c:	000b7023 */ 	negu	$t6,$t3
/*    3a390:	a54e000a */ 	sh	$t6,0xa($t2)
.L0003a394:
/*    3a394:	8faf0068 */ 	lw	$t7,0x68($sp)
/*    3a398:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    3a39c:	15f80009 */ 	bne	$t7,$t8,.L0003a3c4
/*    3a3a0:	00000000 */ 	nop
/*    3a3a4:	87b90072 */ 	lh	$t9,0x72($sp)
/*    3a3a8:	a7b90046 */ 	sh	$t9,0x46($sp)
/*    3a3ac:	87a80074 */ 	lh	$t0,0x74($sp)
/*    3a3b0:	a7a80072 */ 	sh	$t0,0x72($sp)
/*    3a3b4:	87ad0046 */ 	lh	$t5,0x46($sp)
/*    3a3b8:	a7ad0074 */ 	sh	$t5,0x74($sp)
/*    3a3bc:	1000000b */ 	b	.L0003a3ec
/*    3a3c0:	00000000 */ 	nop
.L0003a3c4:
/*    3a3c4:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*    3a3c8:	240c00b8 */ 	addiu	$t4,$zero,0xb8
/*    3a3cc:	afac0010 */ 	sw	$t4,0x10($sp)
/*    3a3d0:	8fa40078 */ 	lw	$a0,0x78($sp)
/*    3a3d4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*    3a3d8:	8fa60068 */ 	lw	$a2,0x68($sp)
/*    3a3dc:	87a70074 */ 	lh	$a3,0x74($sp)
/*    3a3e0:	0c00ec5e */ 	jal	func0003b178
/*    3a3e4:	afa90014 */ 	sw	$t1,0x14($sp)
/*    3a3e8:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a3ec:
/*    3a3ec:	8fab007c */ 	lw	$t3,0x7c($sp)
/*    3a3f0:	8fa40078 */ 	lw	$a0,0x78($sp)
/*    3a3f4:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*    3a3f8:	8fa60054 */ 	lw	$a2,0x54($sp)
/*    3a3fc:	87a70072 */ 	lh	$a3,0x72($sp)
/*    3a400:	0c00eb98 */ 	jal	func0003ae60
/*    3a404:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3a408:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    3a40c:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    3a410:	85ca0008 */ 	lh	$t2,0x8($t6)
/*    3a414:	11400023 */ 	beqz	$t2,.L0003a4a4
/*    3a418:	00000000 */ 	nop
/*    3a41c:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    3a420:	25f80008 */ 	addiu	$t8,$t7,0x8
/*    3a424:	afb8007c */ 	sw	$t8,0x7c($sp)
/*    3a428:	afaf0040 */ 	sw	$t7,0x40($sp)
/*    3a42c:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    3a430:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    3a434:	3c010c00 */ 	lui	$at,0xc00
/*    3a438:	97280008 */ 	lhu	$t0,0x8($t9)
/*    3a43c:	310dffff */ 	andi	$t5,$t0,0xffff
/*    3a440:	01a16025 */ 	or	$t4,$t5,$at
/*    3a444:	ad2c0000 */ 	sw	$t4,0x0($t1)
/*    3a448:	87ab0074 */ 	lh	$t3,0x74($sp)
/*    3a44c:	87af0072 */ 	lh	$t7,0x72($sp)
/*    3a450:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    3a454:	316effff */ 	andi	$t6,$t3,0xffff
/*    3a458:	000e5400 */ 	sll	$t2,$t6,0x10
/*    3a45c:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    3a460:	0158c825 */ 	or	$t9,$t2,$t8
/*    3a464:	ad190004 */ 	sw	$t9,0x4($t0)
/*    3a468:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    3a46c:	8dac0024 */ 	lw	$t4,0x24($t5)
/*    3a470:	1580000c */ 	bnez	$t4,.L0003a4a4
/*    3a474:	00000000 */ 	nop
/*    3a478:	8da90020 */ 	lw	$t1,0x20($t5)
/*    3a47c:	15200009 */ 	bnez	$t1,.L0003a4a4
/*    3a480:	00000000 */ 	nop
/*    3a484:	8fab007c */ 	lw	$t3,0x7c($sp)
/*    3a488:	8fa40078 */ 	lw	$a0,0x78($sp)
/*    3a48c:	8fa50054 */ 	lw	$a1,0x54($sp)
/*    3a490:	8fa60064 */ 	lw	$a2,0x64($sp)
/*    3a494:	87a70072 */ 	lh	$a3,0x72($sp)
/*    3a498:	0c00ecdc */ 	jal	func0003b370
/*    3a49c:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3a4a0:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a4a4:
/*    3a4a4:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    3a4a8:	85cf000a */ 	lh	$t7,0xa($t6)
/*    3a4ac:	11e0001c */ 	beqz	$t7,.L0003a520
/*    3a4b0:	00000000 */ 	nop
/*    3a4b4:	8faa007c */ 	lw	$t2,0x7c($sp)
/*    3a4b8:	25580008 */ 	addiu	$t8,$t2,0x8
/*    3a4bc:	afb8007c */ 	sw	$t8,0x7c($sp)
/*    3a4c0:	afaa003c */ 	sw	$t2,0x3c($sp)
/*    3a4c4:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    3a4c8:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    3a4cc:	3c010c00 */ 	lui	$at,0xc00
/*    3a4d0:	9728000a */ 	lhu	$t0,0xa($t9)
/*    3a4d4:	310cffff */ 	andi	$t4,$t0,0xffff
/*    3a4d8:	01816825 */ 	or	$t5,$t4,$at
/*    3a4dc:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*    3a4e0:	87ab0072 */ 	lh	$t3,0x72($sp)
/*    3a4e4:	87aa0074 */ 	lh	$t2,0x74($sp)
/*    3a4e8:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    3a4ec:	316effff */ 	andi	$t6,$t3,0xffff
/*    3a4f0:	000e7c00 */ 	sll	$t7,$t6,0x10
/*    3a4f4:	3158ffff */ 	andi	$t8,$t2,0xffff
/*    3a4f8:	01f8c825 */ 	or	$t9,$t7,$t8
/*    3a4fc:	ad190004 */ 	sw	$t9,0x4($t0)
/*    3a500:	8fac007c */ 	lw	$t4,0x7c($sp)
/*    3a504:	8fa40078 */ 	lw	$a0,0x78($sp)
/*    3a508:	8fa50054 */ 	lw	$a1,0x54($sp)
/*    3a50c:	8fa60068 */ 	lw	$a2,0x68($sp)
/*    3a510:	87a70074 */ 	lh	$a3,0x74($sp)
/*    3a514:	0c00ecdc */ 	jal	func0003b370
/*    3a518:	afac0010 */ 	sw	$t4,0x10($sp)
/*    3a51c:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a520:
/*    3a520:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    3a524:	8da90020 */ 	lw	$t1,0x20($t5)
/*    3a528:	11200008 */ 	beqz	$t1,.L0003a54c
/*    3a52c:	00000000 */ 	nop
/*    3a530:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    3a534:	8fa50054 */ 	lw	$a1,0x54($sp)
/*    3a538:	87a60072 */ 	lh	$a2,0x72($sp)
/*    3a53c:	8fa7007c */ 	lw	$a3,0x7c($sp)
/*    3a540:	0c00ed53 */ 	jal	func0003b54c
/*    3a544:	8d640020 */ 	lw	$a0,0x20($t3)
/*    3a548:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a54c:
/*    3a54c:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    3a550:	8dca0024 */ 	lw	$t2,0x24($t6)
/*    3a554:	15400009 */ 	bnez	$t2,.L0003a57c
/*    3a558:	00000000 */ 	nop
/*    3a55c:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    3a560:	8fa40078 */ 	lw	$a0,0x78($sp)
/*    3a564:	8fa50054 */ 	lw	$a1,0x54($sp)
/*    3a568:	8fa60064 */ 	lw	$a2,0x64($sp)
/*    3a56c:	87a70072 */ 	lh	$a3,0x72($sp)
/*    3a570:	0c00ecdc */ 	jal	func0003b370
/*    3a574:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    3a578:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a57c:
/*    3a57c:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    3a580:	8719000c */ 	lh	$t9,0xc($t8)
/*    3a584:	13200062 */ 	beqz	$t9,.L0003a710
/*    3a588:	00000000 */ 	nop
/*    3a58c:	8fa80088 */ 	lw	$t0,0x88($sp)
/*    3a590:	3c0c800a */ 	lui	$t4,%hi(var8009c344)
/*    3a594:	01886021 */ 	addu	$t4,$t4,$t0
/*    3a598:	918cc344 */ 	lbu	$t4,%lo(var8009c344)($t4)
/*    3a59c:	11800016 */ 	beqz	$t4,.L0003a5f8
/*    3a5a0:	00000000 */ 	nop
/*    3a5a4:	8fad007c */ 	lw	$t5,0x7c($sp)
/*    3a5a8:	25a90008 */ 	addiu	$t1,$t5,0x8
/*    3a5ac:	afa9007c */ 	sw	$t1,0x7c($sp)
/*    3a5b0:	afad0038 */ 	sw	$t5,0x38($sp)
/*    3a5b4:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    3a5b8:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    3a5bc:	3c010c00 */ 	lui	$at,0xc00
/*    3a5c0:	956e000c */ 	lhu	$t6,0xc($t3)
/*    3a5c4:	31caffff */ 	andi	$t2,$t6,0xffff
/*    3a5c8:	01417825 */ 	or	$t7,$t2,$at
/*    3a5cc:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    3a5d0:	87b90072 */ 	lh	$t9,0x72($sp)
/*    3a5d4:	87ad006e */ 	lh	$t5,0x6e($sp)
/*    3a5d8:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    3a5dc:	3328ffff */ 	andi	$t0,$t9,0xffff
/*    3a5e0:	00086400 */ 	sll	$t4,$t0,0x10
/*    3a5e4:	31a9ffff */ 	andi	$t1,$t5,0xffff
/*    3a5e8:	01895825 */ 	or	$t3,$t4,$t1
/*    3a5ec:	adcb0004 */ 	sw	$t3,0x4($t6)
/*    3a5f0:	10000047 */ 	b	.L0003a710
/*    3a5f4:	00000000 */ 	nop
.L0003a5f8:
/*    3a5f8:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    3a5fc:	3c017005 */ 	lui	$at,%hi(var70054a90)
/*    3a600:	c4284a90 */ 	lwc1	$f8,%lo(var70054a90)($at)
/*    3a604:	854f000c */ 	lh	$t7,0xc($t2)
/*    3a608:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3a60c:	448f2000 */ 	mtc1	$t7,$f4
/*    3a610:	00000000 */ 	nop
/*    3a614:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3a618:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    3a61c:	4458f800 */ 	cfc1	$t8,$31
/*    3a620:	44d9f800 */ 	ctc1	$t9,$31
/*    3a624:	00000000 */ 	nop
/*    3a628:	46005424 */ 	cvt.w.s	$f16,$f10
/*    3a62c:	4459f800 */ 	cfc1	$t9,$31
/*    3a630:	00000000 */ 	nop
/*    3a634:	33210004 */ 	andi	$at,$t9,0x4
/*    3a638:	33390078 */ 	andi	$t9,$t9,0x78
/*    3a63c:	13200014 */ 	beqz	$t9,.L0003a690
/*    3a640:	00000000 */ 	nop
/*    3a644:	3c014f00 */ 	lui	$at,0x4f00
/*    3a648:	44818000 */ 	mtc1	$at,$f16
/*    3a64c:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3a650:	46105401 */ 	sub.s	$f16,$f10,$f16
/*    3a654:	44d9f800 */ 	ctc1	$t9,$31
/*    3a658:	00000000 */ 	nop
/*    3a65c:	46008424 */ 	cvt.w.s	$f16,$f16
/*    3a660:	4459f800 */ 	cfc1	$t9,$31
/*    3a664:	00000000 */ 	nop
/*    3a668:	33210004 */ 	andi	$at,$t9,0x4
/*    3a66c:	33390078 */ 	andi	$t9,$t9,0x78
/*    3a670:	17200005 */ 	bnez	$t9,.L0003a688
/*    3a674:	00000000 */ 	nop
/*    3a678:	44198000 */ 	mfc1	$t9,$f16
/*    3a67c:	3c018000 */ 	lui	$at,0x8000
/*    3a680:	10000007 */ 	b	.L0003a6a0
/*    3a684:	0321c825 */ 	or	$t9,$t9,$at
.L0003a688:
/*    3a688:	10000005 */ 	b	.L0003a6a0
/*    3a68c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0003a690:
/*    3a690:	44198000 */ 	mfc1	$t9,$f16
/*    3a694:	00000000 */ 	nop
/*    3a698:	0720fffb */ 	bltz	$t9,.L0003a688
/*    3a69c:	00000000 */ 	nop
.L0003a6a0:
/*    3a6a0:	44d8f800 */ 	ctc1	$t8,$31
/*    3a6a4:	afb90034 */ 	sw	$t9,0x34($sp)
/*    3a6a8:	00000000 */ 	nop
/*    3a6ac:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    3a6b0:	34018000 */ 	dli	$at,0x8000
/*    3a6b4:	0101082b */ 	sltu	$at,$t0,$at
/*    3a6b8:	14200003 */ 	bnez	$at,.L0003a6c8
/*    3a6bc:	00000000 */ 	nop
/*    3a6c0:	240d7fff */ 	addiu	$t5,$zero,0x7fff
/*    3a6c4:	afad0034 */ 	sw	$t5,0x34($sp)
.L0003a6c8:
/*    3a6c8:	8fac007c */ 	lw	$t4,0x7c($sp)
/*    3a6cc:	25890008 */ 	addiu	$t1,$t4,0x8
/*    3a6d0:	afa9007c */ 	sw	$t1,0x7c($sp)
/*    3a6d4:	afac0030 */ 	sw	$t4,0x30($sp)
/*    3a6d8:	97ab0036 */ 	lhu	$t3,0x36($sp)
/*    3a6dc:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3a6e0:	3c010c00 */ 	lui	$at,0xc00
/*    3a6e4:	316effff */ 	andi	$t6,$t3,0xffff
/*    3a6e8:	01c15025 */ 	or	$t2,$t6,$at
/*    3a6ec:	adea0000 */ 	sw	$t2,0x0($t7)
/*    3a6f0:	87b80072 */ 	lh	$t8,0x72($sp)
/*    3a6f4:	87ad006e */ 	lh	$t5,0x6e($sp)
/*    3a6f8:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3a6fc:	3319ffff */ 	andi	$t9,$t8,0xffff
/*    3a700:	00194400 */ 	sll	$t0,$t9,0x10
/*    3a704:	31acffff */ 	andi	$t4,$t5,0xffff
/*    3a708:	010c4825 */ 	or	$t1,$t0,$t4
/*    3a70c:	ad690004 */ 	sw	$t1,0x4($t3)
.L0003a710:
/*    3a710:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3a714:	8fae0078 */ 	lw	$t6,0x78($sp)
/*    3a718:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    3a71c:	000a7880 */ 	sll	$t7,$t2,0x2
/*    3a720:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    3a724:	8da80004 */ 	lw	$t0,0x4($t5)
/*    3a728:	8f190028 */ 	lw	$t9,0x28($t8)
/*    3a72c:	00086040 */ 	sll	$t4,$t0,0x1
/*    3a730:	032c4821 */ 	addu	$t1,$t9,$t4
/*    3a734:	afa90060 */ 	sw	$t1,0x60($sp)
/*    3a738:	87ab0076 */ 	lh	$t3,0x76($sp)
/*    3a73c:	8fb80078 */ 	lw	$t8,0x78($sp)
/*    3a740:	256a0001 */ 	addiu	$t2,$t3,0x1
/*    3a744:	a7aa0076 */ 	sh	$t2,0x76($sp)
/*    3a748:	930d0008 */ 	lbu	$t5,0x8($t8)
/*    3a74c:	000a7400 */ 	sll	$t6,$t2,0x10
/*    3a750:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    3a754:	01ed082a */ 	slt	$at,$t7,$t5
/*    3a758:	1420fedd */ 	bnez	$at,.L0003a2d0
/*    3a75c:	00000000 */ 	nop
.L0003a760:
/*    3a760:	8fa80088 */ 	lw	$t0,0x88($sp)
/*    3a764:	3c19800a */ 	lui	$t9,%hi(var8009c344)
/*    3a768:	0328c821 */ 	addu	$t9,$t9,$t0
/*    3a76c:	9339c344 */ 	lbu	$t9,%lo(var8009c344)($t9)
/*    3a770:	13200035 */ 	beqz	$t9,.L0003a848
/*    3a774:	00000000 */ 	nop
/*    3a778:	8fac0054 */ 	lw	$t4,0x54($sp)
/*    3a77c:	15800032 */ 	bnez	$t4,.L0003a848
/*    3a780:	00000000 */ 	nop
/*    3a784:	8fa90078 */ 	lw	$t1,0x78($sp)
/*    3a788:	8faa007c */ 	lw	$t2,0x7c($sp)
/*    3a78c:	240b00b8 */ 	addiu	$t3,$zero,0xb8
/*    3a790:	8d26002c */ 	lw	$a2,0x2c($t1)
/*    3a794:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3a798:	24050001 */ 	addiu	$a1,$zero,0x1
/*    3a79c:	87a70070 */ 	lh	$a3,0x70($sp)
/*    3a7a0:	01202025 */ 	or	$a0,$t1,$zero
/*    3a7a4:	0c00ec5e */ 	jal	func0003b178
/*    3a7a8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    3a7ac:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    3a7b0:	8fae0088 */ 	lw	$t6,0x88($sp)
/*    3a7b4:	3c18800a */ 	lui	$t8,%hi(var8009c344+0x2)
/*    3a7b8:	030ec021 */ 	addu	$t8,$t8,$t6
/*    3a7bc:	9318c346 */ 	lbu	$t8,%lo(var8009c344+0x2)($t8)
/*    3a7c0:	13000011 */ 	beqz	$t8,.L0003a808
/*    3a7c4:	00000000 */ 	nop
/*    3a7c8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    3a7cc:	25ed0008 */ 	addiu	$t5,$t7,0x8
/*    3a7d0:	afad007c */ 	sw	$t5,0x7c($sp)
/*    3a7d4:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    3a7d8:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3a7dc:	3c080c00 */ 	lui	$t0,0xc00
/*    3a7e0:	35085a82 */ 	ori	$t0,$t0,0x5a82
/*    3a7e4:	af280000 */ 	sw	$t0,0x0($t9)
/*    3a7e8:	87ac006e */ 	lh	$t4,0x6e($sp)
/*    3a7ec:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3a7f0:	3189ffff */ 	andi	$t1,$t4,0xffff
/*    3a7f4:	00095c00 */ 	sll	$t3,$t1,0x10
/*    3a7f8:	356a0650 */ 	ori	$t2,$t3,0x650
/*    3a7fc:	adca0004 */ 	sw	$t2,0x4($t6)
/*    3a800:	1000000f */ 	b	.L0003a840
/*    3a804:	00000000 */ 	nop
.L0003a808:
/*    3a808:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*    3a80c:	270f0008 */ 	addiu	$t7,$t8,0x8
/*    3a810:	afaf007c */ 	sw	$t7,0x7c($sp)
/*    3a814:	afb80028 */ 	sw	$t8,0x28($sp)
/*    3a818:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    3a81c:	3c0d0c00 */ 	lui	$t5,0xc00
/*    3a820:	35ad5a82 */ 	ori	$t5,$t5,0x5a82
/*    3a824:	ad0d0000 */ 	sw	$t5,0x0($t0)
/*    3a828:	87b9006e */ 	lh	$t9,0x6e($sp)
/*    3a82c:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3a830:	332cffff */ 	andi	$t4,$t9,0xffff
/*    3a834:	000c4c00 */ 	sll	$t1,$t4,0x10
/*    3a838:	352b04e0 */ 	ori	$t3,$t1,0x4e0
/*    3a83c:	ad4b0004 */ 	sw	$t3,0x4($t2)
.L0003a840:
/*    3a840:	10000001 */ 	b	.L0003a848
/*    3a844:	00000000 */ 	nop
.L0003a848:
/*    3a848:	8fae007c */ 	lw	$t6,0x7c($sp)
/*    3a84c:	25d80008 */ 	addiu	$t8,$t6,0x8
/*    3a850:	afb8007c */ 	sw	$t8,0x7c($sp)
/*    3a854:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3a858:	87af006e */ 	lh	$t7,0x6e($sp)
/*    3a85c:	3c0100ff */ 	lui	$at,0xff
/*    3a860:	3421ffff */ 	ori	$at,$at,0xffff
/*    3a864:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3a868:	01e16824 */ 	and	$t5,$t7,$at
/*    3a86c:	3c010a00 */ 	lui	$at,0xa00
/*    3a870:	01a14025 */ 	or	$t0,$t5,$at
/*    3a874:	af280000 */ 	sw	$t0,0x0($t9)
/*    3a878:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3a87c:	3c0c07c0 */ 	lui	$t4,0x7c0
/*    3a880:	358c0170 */ 	ori	$t4,$t4,0x170
/*    3a884:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*    3a888:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3a88c:	8fab0078 */ 	lw	$t3,0x78($sp)
/*    3a890:	000a7080 */ 	sll	$t6,$t2,0x2
/*    3a894:	016ec021 */ 	addu	$t8,$t3,$t6
/*    3a898:	8f0f0028 */ 	lw	$t7,0x28($t8)
/*    3a89c:	25ed0170 */ 	addiu	$t5,$t7,0x170
/*    3a8a0:	af0d0028 */ 	sw	$t5,0x28($t8)
/*    3a8a4:	8fa80078 */ 	lw	$t0,0x78($sp)
/*    3a8a8:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    3a8ac:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*    3a8b0:	00196080 */ 	sll	$t4,$t9,0x2
/*    3a8b4:	010c4821 */ 	addu	$t1,$t0,$t4
/*    3a8b8:	8d2b0020 */ 	lw	$t3,0x20($t1)
/*    3a8bc:	8d2a0028 */ 	lw	$t2,0x28($t1)
/*    3a8c0:	000e7840 */ 	sll	$t7,$t6,0x1
/*    3a8c4:	016f6821 */ 	addu	$t5,$t3,$t7
/*    3a8c8:	01aa082b */ 	sltu	$at,$t5,$t2
/*    3a8cc:	1020000a */ 	beqz	$at,.L0003a8f8
/*    3a8d0:	00000000 */ 	nop
/*    3a8d4:	8fb80078 */ 	lw	$t8,0x78($sp)
/*    3a8d8:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    3a8dc:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*    3a8e0:	00196080 */ 	sll	$t4,$t9,0x2
/*    3a8e4:	030c4821 */ 	addu	$t1,$t8,$t4
/*    3a8e8:	8d280028 */ 	lw	$t0,0x28($t1)
/*    3a8ec:	000e5840 */ 	sll	$t3,$t6,0x1
/*    3a8f0:	010b7823 */ 	subu	$t7,$t0,$t3
/*    3a8f4:	ad2f0028 */ 	sw	$t7,0x28($t1)
.L0003a8f8:
/*    3a8f8:	8fb90088 */ 	lw	$t9,0x88($sp)
/*    3a8fc:	3c0c800a */ 	lui	$t4,%hi(var8009c344)
/*    3a900:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3a904:	01996021 */ 	addu	$t4,$t4,$t9
/*    3a908:	918cc344 */ 	lbu	$t4,%lo(var8009c344)($t4)
/*    3a90c:	254d0001 */ 	addiu	$t5,$t2,0x1
/*    3a910:	afad0054 */ 	sw	$t5,0x54($sp)
/*    3a914:	018d082b */ 	sltu	$at,$t4,$t5
/*    3a918:	1020fe59 */ 	beqz	$at,.L0003a280
/*    3a91c:	00000000 */ 	nop
/*    3a920:	10000003 */ 	b	.L0003a930
/*    3a924:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*    3a928:	10000001 */ 	b	.L0003a930
/*    3a92c:	00000000 */ 	nop
.L0003a930:
/*    3a930:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3a934:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*    3a938:	03e00008 */ 	jr	$ra
/*    3a93c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003a940
.late_rodata
glabel var70054a94
.word func0003a940+0x88
glabel var70054a98
.word func0003a940+0xe4
glabel var70054a9c
.word func0003a940+0x140
glabel var70054aa0
.word func0003a940+0x16c
glabel var70054aa4
.word func0003a940+0x198
glabel var70054aa8
.word func0003a940+0x1c4
glabel var70054aac
.word func0003a940+0x228
glabel var70054ab0
.word func0003a940+0x244
glabel var70054ab4
.word 0x482910da
glabel var70054ab8
.word 0x482910da
glabel var70054abc
.word 0x00000000
.text
/*    3a940:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    3a944:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3a948:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3a94c:	afa50034 */ 	sw	$a1,0x34($sp)
/*    3a950:	afa60038 */ 	sw	$a2,0x38($sp)
/*    3a954:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    3a958:	afae002c */ 	sw	$t6,0x2c($sp)
/*    3a95c:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3a960:	31f80007 */ 	andi	$t8,$t7,0x7
/*    3a964:	afb80028 */ 	sw	$t8,0x28($sp)
/*    3a968:	8fb90034 */ 	lw	$t9,0x34($sp)
/*    3a96c:	001940c3 */ 	sra	$t0,$t9,0x3
/*    3a970:	afa80024 */ 	sw	$t0,0x24($sp)
/*    3a974:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    3a978:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    3a97c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    3a980:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    3a984:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3a988:	918d0008 */ 	lbu	$t5,0x8($t4)
/*    3a98c:	016d082a */ 	slt	$at,$t3,$t5
/*    3a990:	14200003 */ 	bnez	$at,.L0003a9a0
/*    3a994:	00000000 */ 	nop
/*    3a998:	1000012d */ 	b	.L0003ae50
/*    3a99c:	00001025 */ 	or	$v0,$zero,$zero
.L0003a9a0:
/*    3a9a0:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3a9a4:	2dc10008 */ 	sltiu	$at,$t6,0x8
/*    3a9a8:	10200095 */ 	beqz	$at,.L0003ac00
/*    3a9ac:	00000000 */ 	nop
/*    3a9b0:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3a9b4:	3c017005 */ 	lui	$at,%hi(var70054a94)
/*    3a9b8:	002e0821 */ 	addu	$at,$at,$t6
/*    3a9bc:	8c2e4a94 */ 	lw	$t6,%lo(var70054a94)($at)
/*    3a9c0:	01c00008 */ 	jr	$t6
/*    3a9c4:	00000000 */ 	nop
/*    3a9c8:	3c188006 */ 	lui	$t8,%hi(alGlobals)
/*    3a9cc:	8f18f114 */ 	lw	$t8,%lo(alGlobals)($t8)
/*    3a9d0:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3a9d4:	240103e8 */ 	addiu	$at,$zero,0x3e8
/*    3a9d8:	8f190040 */ 	lw	$t9,0x40($t8)
/*    3a9dc:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    3a9e0:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3a9e4:	01f90019 */ 	multu	$t7,$t9
/*    3a9e8:	8d8b0004 */ 	lw	$t3,0x4($t4)
/*    3a9ec:	000d7080 */ 	sll	$t6,$t5,0x2
/*    3a9f0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    3a9f4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    3a9f8:	016ec021 */ 	addu	$t8,$t3,$t6
/*    3a9fc:	00004012 */ 	mflo	$t0
/*    3aa00:	00000000 */ 	nop
/*    3aa04:	00000000 */ 	nop
/*    3aa08:	0101001a */ 	div	$zero,$t0,$at
/*    3aa0c:	00004812 */ 	mflo	$t1
/*    3aa10:	2401fff8 */ 	addiu	$at,$zero,-8
/*    3aa14:	01215024 */ 	and	$t2,$t1,$at
/*    3aa18:	af0a0000 */ 	sw	$t2,0x0($t8)
/*    3aa1c:	10000078 */ 	b	.L0003ac00
/*    3aa20:	00000000 */ 	nop
/*    3aa24:	3c198006 */ 	lui	$t9,%hi(alGlobals)
/*    3aa28:	8f39f114 */ 	lw	$t9,%lo(alGlobals)($t9)
/*    3aa2c:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3aa30:	240103e8 */ 	addiu	$at,$zero,0x3e8
/*    3aa34:	8f280040 */ 	lw	$t0,0x40($t9)
/*    3aa38:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3aa3c:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3aa40:	01e80019 */ 	multu	$t7,$t0
/*    3aa44:	8d6e0004 */ 	lw	$t6,0x4($t3)
/*    3aa48:	000ac080 */ 	sll	$t8,$t2,0x2
/*    3aa4c:	030ac021 */ 	addu	$t8,$t8,$t2
/*    3aa50:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    3aa54:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    3aa58:	00004812 */ 	mflo	$t1
/*    3aa5c:	00000000 */ 	nop
/*    3aa60:	00000000 */ 	nop
/*    3aa64:	0121001a */ 	div	$zero,$t1,$at
/*    3aa68:	00006012 */ 	mflo	$t4
/*    3aa6c:	2401fff8 */ 	addiu	$at,$zero,-8
/*    3aa70:	01816824 */ 	and	$t5,$t4,$at
/*    3aa74:	af2d0004 */ 	sw	$t5,0x4($t9)
/*    3aa78:	10000061 */ 	b	.L0003ac00
/*    3aa7c:	00000000 */ 	nop
/*    3aa80:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3aa84:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3aa88:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3aa8c:	8d090004 */ 	lw	$t1,0x4($t0)
/*    3aa90:	000c5880 */ 	sll	$t3,$t4,0x2
/*    3aa94:	016c5821 */ 	addu	$t3,$t3,$t4
/*    3aa98:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    3aa9c:	012b5021 */ 	addu	$t2,$t1,$t3
/*    3aaa0:	a54f000a */ 	sh	$t7,0xa($t2)
/*    3aaa4:	10000056 */ 	b	.L0003ac00
/*    3aaa8:	00000000 */ 	nop
/*    3aaac:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3aab0:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3aab4:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3aab8:	8f0d0004 */ 	lw	$t5,0x4($t8)
/*    3aabc:	00194080 */ 	sll	$t0,$t9,0x2
/*    3aac0:	01194021 */ 	addu	$t0,$t0,$t9
/*    3aac4:	000840c0 */ 	sll	$t0,$t0,0x3
/*    3aac8:	01a86021 */ 	addu	$t4,$t5,$t0
/*    3aacc:	a58e0008 */ 	sh	$t6,0x8($t4)
/*    3aad0:	1000004b */ 	b	.L0003ac00
/*    3aad4:	00000000 */ 	nop
/*    3aad8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3aadc:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3aae0:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3aae4:	8d6f0004 */ 	lw	$t7,0x4($t3)
/*    3aae8:	000ac080 */ 	sll	$t8,$t2,0x2
/*    3aaec:	030ac021 */ 	addu	$t8,$t8,$t2
/*    3aaf0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    3aaf4:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    3aaf8:	a729000c */ 	sh	$t1,0xc($t9)
/*    3aafc:	10000040 */ 	b	.L0003ac00
/*    3ab00:	00000000 */ 	nop
/*    3ab04:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3ab08:	3c01447a */ 	lui	$at,0x447a
/*    3ab0c:	44814000 */ 	mtc1	$at,$f8
/*    3ab10:	448d2000 */ 	mtc1	$t5,$f4
/*    3ab14:	3c088006 */ 	lui	$t0,%hi(alGlobals)
/*    3ab18:	8d08f114 */ 	lw	$t0,%lo(alGlobals)($t0)
/*    3ab1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3ab20:	3c014000 */ 	lui	$at,0x4000
/*    3ab24:	8d0e0040 */ 	lw	$t6,0x40($t0)
/*    3ab28:	44818000 */ 	mtc1	$at,$f16
/*    3ab2c:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    3ab30:	448e2000 */ 	mtc1	$t6,$f4
/*    3ab34:	46083283 */ 	div.s	$f10,$f6,$f8
/*    3ab38:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3ab3c:	8d8b0004 */ 	lw	$t3,0x4($t4)
/*    3ab40:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3ab44:	000a7880 */ 	sll	$t7,$t2,0x2
/*    3ab48:	01ea7821 */ 	addu	$t7,$t7,$t2
/*    3ab4c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    3ab50:	016fc021 */ 	addu	$t8,$t3,$t7
/*    3ab54:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    3ab58:	46069203 */ 	div.s	$f8,$f18,$f6
/*    3ab5c:	e7080010 */ 	swc1	$f8,0x10($t8)
/*    3ab60:	10000027 */ 	b	.L0003ac00
/*    3ab64:	00000000 */ 	nop
/*    3ab68:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3ab6c:	44895000 */ 	mtc1	$t1,$f10
/*    3ab70:	00000000 */ 	nop
/*    3ab74:	46805420 */ 	cvt.s.w	$f16,$f10
/*    3ab78:	e7b0001c */ 	swc1	$f16,0x1c($sp)
/*    3ab7c:	10000020 */ 	b	.L0003ac00
/*    3ab80:	00000000 */ 	nop
/*    3ab84:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3ab88:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    3ab8c:	8f2d0004 */ 	lw	$t5,0x4($t9)
/*    3ab90:	00087080 */ 	sll	$t6,$t0,0x2
/*    3ab94:	01c87021 */ 	addu	$t6,$t6,$t0
/*    3ab98:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    3ab9c:	01ae6021 */ 	addu	$t4,$t5,$t6
/*    3aba0:	8d8a0020 */ 	lw	$t2,0x20($t4)
/*    3aba4:	11400014 */ 	beqz	$t2,.L0003abf8
/*    3aba8:	00000000 */ 	nop
/*    3abac:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3abb0:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3abb4:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3abb8:	8df80004 */ 	lw	$t8,0x4($t7)
/*    3abbc:	0009c880 */ 	sll	$t9,$t1,0x2
/*    3abc0:	0329c821 */ 	addu	$t9,$t9,$t1
/*    3abc4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    3abc8:	03194021 */ 	addu	$t0,$t8,$t9
/*    3abcc:	8d0d0020 */ 	lw	$t5,0x20($t0)
/*    3abd0:	a5ab0000 */ 	sh	$t3,0x0($t5)
/*    3abd4:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3abd8:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3abdc:	8dcc0004 */ 	lw	$t4,0x4($t6)
/*    3abe0:	000a7880 */ 	sll	$t7,$t2,0x2
/*    3abe4:	01ea7821 */ 	addu	$t7,$t7,$t2
/*    3abe8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    3abec:	018f4821 */ 	addu	$t1,$t4,$t7
/*    3abf0:	0c00ee21 */ 	jal	func0003b884
/*    3abf4:	8d240020 */ 	lw	$a0,0x20($t1)
.L0003abf8:
/*    3abf8:	10000001 */ 	b	.L0003ac00
/*    3abfc:	00000000 */ 	nop
.L0003ac00:
/*    3ac00:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3ac04:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    3ac08:	8f190004 */ 	lw	$t9,0x4($t8)
/*    3ac0c:	00085880 */ 	sll	$t3,$t0,0x2
/*    3ac10:	01685821 */ 	addu	$t3,$t3,$t0
/*    3ac14:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    3ac18:	8f0a0000 */ 	lw	$t2,0x0($t8)
/*    3ac1c:	032b6821 */ 	addu	$t5,$t9,$t3
/*    3ac20:	8dae0000 */ 	lw	$t6,0x0($t5)
/*    3ac24:	254cfff0 */ 	addiu	$t4,$t2,-16
/*    3ac28:	01cc082b */ 	sltu	$at,$t6,$t4
/*    3ac2c:	1420000b */ 	bnez	$at,.L0003ac5c
/*    3ac30:	00000000 */ 	nop
/*    3ac34:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3ac38:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3ac3c:	8de90000 */ 	lw	$t1,0x0($t7)
/*    3ac40:	8df90004 */ 	lw	$t9,0x4($t7)
/*    3ac44:	000b6880 */ 	sll	$t5,$t3,0x2
/*    3ac48:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    3ac4c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    3ac50:	2528fff0 */ 	addiu	$t0,$t1,-16
/*    3ac54:	032dc021 */ 	addu	$t8,$t9,$t5
/*    3ac58:	af080000 */ 	sw	$t0,0x0($t8)
.L0003ac5c:
/*    3ac5c:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    3ac60:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3ac64:	8d4e0004 */ 	lw	$t6,0x4($t2)
/*    3ac68:	000c4880 */ 	sll	$t1,$t4,0x2
/*    3ac6c:	012c4821 */ 	addu	$t1,$t1,$t4
/*    3ac70:	000948c0 */ 	sll	$t1,$t1,0x3
/*    3ac74:	8d590000 */ 	lw	$t9,0x0($t2)
/*    3ac78:	01c97821 */ 	addu	$t7,$t6,$t1
/*    3ac7c:	8deb0000 */ 	lw	$t3,0x0($t7)
/*    3ac80:	272dfff8 */ 	addiu	$t5,$t9,-8
/*    3ac84:	016d082b */ 	sltu	$at,$t3,$t5
/*    3ac88:	1420000b */ 	bnez	$at,.L0003acb8
/*    3ac8c:	00000000 */ 	nop
/*    3ac90:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3ac94:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3ac98:	8d180000 */ 	lw	$t8,0x0($t0)
/*    3ac9c:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*    3aca0:	00097880 */ 	sll	$t7,$t1,0x2
/*    3aca4:	01e97821 */ 	addu	$t7,$t7,$t1
/*    3aca8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    3acac:	270cfff8 */ 	addiu	$t4,$t8,-8
/*    3acb0:	01cf5021 */ 	addu	$t2,$t6,$t7
/*    3acb4:	ad4c0000 */ 	sw	$t4,0x0($t2)
.L0003acb8:
/*    3acb8:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3acbc:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3acc0:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*    3acc4:	000dc080 */ 	sll	$t8,$t5,0x2
/*    3acc8:	030dc021 */ 	addu	$t8,$t8,$t5
/*    3accc:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    3acd0:	01784021 */ 	addu	$t0,$t3,$t8
/*    3acd4:	8d090000 */ 	lw	$t1,0x0($t0)
/*    3acd8:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*    3acdc:	012e082b */ 	sltu	$at,$t1,$t6
/*    3ace0:	1420000b */ 	bnez	$at,.L0003ad10
/*    3ace4:	00000000 */ 	nop
/*    3ace8:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3acec:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3acf0:	8dec0004 */ 	lw	$t4,0x4($t7)
/*    3acf4:	000ac880 */ 	sll	$t9,$t2,0x2
/*    3acf8:	032ac821 */ 	addu	$t9,$t9,$t2
/*    3acfc:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    3ad00:	01996821 */ 	addu	$t5,$t4,$t9
/*    3ad04:	8dab0000 */ 	lw	$t3,0x0($t5)
/*    3ad08:	25780008 */ 	addiu	$t8,$t3,0x8
/*    3ad0c:	adb80004 */ 	sw	$t8,0x4($t5)
.L0003ad10:
/*    3ad10:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3ad14:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3ad18:	8d090004 */ 	lw	$t1,0x4($t0)
/*    3ad1c:	000e7880 */ 	sll	$t7,$t6,0x2
/*    3ad20:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    3ad24:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    3ad28:	012f5021 */ 	addu	$t2,$t1,$t7
/*    3ad2c:	8d4c0024 */ 	lw	$t4,0x24($t2)
/*    3ad30:	11800043 */ 	beqz	$t4,.L0003ae40
/*    3ad34:	00000000 */ 	nop
/*    3ad38:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3ad3c:	24010006 */ 	addiu	$at,$zero,0x6
/*    3ad40:	13210028 */ 	beq	$t9,$at,.L0003ade4
/*    3ad44:	00000000 */ 	nop
/*    3ad48:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3ad4c:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3ad50:	8d780004 */ 	lw	$t8,0x4($t3)
/*    3ad54:	000d4080 */ 	sll	$t0,$t5,0x2
/*    3ad58:	010d4021 */ 	addu	$t0,$t0,$t5
/*    3ad5c:	000840c0 */ 	sll	$t0,$t0,0x3
/*    3ad60:	03087021 */ 	addu	$t6,$t8,$t0
/*    3ad64:	8dc90004 */ 	lw	$t1,0x4($t6)
/*    3ad68:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    3ad6c:	012f5023 */ 	subu	$t2,$t1,$t7
/*    3ad70:	11400019 */ 	beqz	$t2,.L0003add8
/*    3ad74:	00000000 */ 	nop
/*    3ad78:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    3ad7c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3ad80:	8d990004 */ 	lw	$t9,0x4($t4)
/*    3ad84:	000b6880 */ 	sll	$t5,$t3,0x2
/*    3ad88:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    3ad8c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    3ad90:	032dc021 */ 	addu	$t8,$t9,$t5
/*    3ad94:	8f080004 */ 	lw	$t0,0x4($t8)
/*    3ad98:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*    3ad9c:	010e4823 */ 	subu	$t1,$t0,$t6
/*    3ada0:	44892000 */ 	mtc1	$t1,$f4
/*    3ada4:	05210005 */ 	bgez	$t1,.L0003adbc
/*    3ada8:	468024a0 */ 	cvt.s.w	$f18,$f4
/*    3adac:	3c014f80 */ 	lui	$at,0x4f80
/*    3adb0:	44813000 */ 	mtc1	$at,$f6
/*    3adb4:	00000000 */ 	nop
/*    3adb8:	46069480 */ 	add.s	$f18,$f18,$f6
.L0003adbc:
/*    3adbc:	c708001c */ 	lwc1	$f8,0x1c($t8)
/*    3adc0:	3c017005 */ 	lui	$at,%hi(var70054ab4)
/*    3adc4:	c4304ab4 */ 	lwc1	$f16,%lo(var70054ab4)($at)
/*    3adc8:	46124283 */ 	div.s	$f10,$f8,$f18
/*    3adcc:	46105102 */ 	mul.s	$f4,$f10,$f16
/*    3add0:	10000004 */ 	b	.L0003ade4
/*    3add4:	e7a4001c */ 	swc1	$f4,0x1c($sp)
.L0003add8:
/*    3add8:	44803000 */ 	mtc1	$zero,$f6
/*    3addc:	00000000 */ 	nop
/*    3ade0:	e7a6001c */ 	swc1	$f6,0x1c($sp)
.L0003ade4:
/*    3ade4:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3ade8:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3adec:	8dea0004 */ 	lw	$t2,0x4($t7)
/*    3adf0:	000c5880 */ 	sll	$t3,$t4,0x2
/*    3adf4:	016c5821 */ 	addu	$t3,$t3,$t4
/*    3adf8:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    3adfc:	014bc821 */ 	addu	$t9,$t2,$t3
/*    3ae00:	8f2d0004 */ 	lw	$t5,0x4($t9)
/*    3ae04:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3ae08:	01a87023 */ 	subu	$t6,$t5,$t0
/*    3ae0c:	448e4000 */ 	mtc1	$t6,$f8
/*    3ae10:	05c10005 */ 	bgez	$t6,.L0003ae28
/*    3ae14:	468044a0 */ 	cvt.s.w	$f18,$f8
/*    3ae18:	3c014f80 */ 	lui	$at,0x4f80
/*    3ae1c:	44815000 */ 	mtc1	$at,$f10
/*    3ae20:	00000000 */ 	nop
/*    3ae24:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0003ae28:
/*    3ae28:	3c017005 */ 	lui	$at,%hi(var70054ab8)
/*    3ae2c:	c4244ab8 */ 	lwc1	$f4,%lo(var70054ab8)($at)
/*    3ae30:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*    3ae34:	46048183 */ 	div.s	$f6,$f16,$f4
/*    3ae38:	46069202 */ 	mul.s	$f8,$f18,$f6
/*    3ae3c:	e728001c */ 	swc1	$f8,0x1c($t9)
.L0003ae40:
/*    3ae40:	10000003 */ 	b	.L0003ae50
/*    3ae44:	00001025 */ 	or	$v0,$zero,$zero
/*    3ae48:	10000001 */ 	b	.L0003ae50
/*    3ae4c:	00000000 */ 	nop
.L0003ae50:
/*    3ae50:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3ae54:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3ae58:	03e00008 */ 	jr	$ra
/*    3ae5c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003ae60
/*    3ae60:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    3ae64:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3ae68:	afa40058 */ 	sw	$a0,0x58($sp)
/*    3ae6c:	afa5005c */ 	sw	$a1,0x5c($sp)
/*    3ae70:	afa60060 */ 	sw	$a2,0x60($sp)
/*    3ae74:	afa70064 */ 	sw	$a3,0x64($sp)
/*    3ae78:	8fae0068 */ 	lw	$t6,0x68($sp)
/*    3ae7c:	afae0054 */ 	sw	$t6,0x54($sp)
/*    3ae80:	240f02e0 */ 	addiu	$t7,$zero,0x2e0
/*    3ae84:	afaf0048 */ 	sw	$t7,0x48($sp)
/*    3ae88:	afa00034 */ 	sw	$zero,0x34($sp)
/*    3ae8c:	241800b8 */ 	addiu	$t8,$zero,0xb8
/*    3ae90:	afb8002c */ 	sw	$t8,0x2c($sp)
/*    3ae94:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    3ae98:	8f280024 */ 	lw	$t0,0x24($t9)
/*    3ae9c:	11000099 */ 	beqz	$t0,.L0003b104
/*    3aea0:	00000000 */ 	nop
/*    3aea4:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    3aea8:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    3aeac:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*    3aeb0:	014b6023 */ 	subu	$t4,$t2,$t3
/*    3aeb4:	afac0030 */ 	sw	$t4,0x30($sp)
/*    3aeb8:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*    3aebc:	0c00ed93 */ 	jal	func0003b64c
/*    3aec0:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    3aec4:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*    3aec8:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    3aecc:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*    3aed0:	448d3000 */ 	mtc1	$t5,$f6
/*    3aed4:	00000000 */ 	nop
/*    3aed8:	46803220 */ 	cvt.s.w	$f8,$f6
/*    3aedc:	46082283 */ 	div.s	$f10,$f4,$f8
/*    3aee0:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*    3aee4:	3c014700 */ 	lui	$at,0x4700
/*    3aee8:	44819000 */ 	mtc1	$at,$f18
/*    3aeec:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*    3aef0:	46128182 */ 	mul.s	$f6,$f16,$f18
/*    3aef4:	4600310d */ 	trunc.w.s	$f4,$f6
/*    3aef8:	440f2000 */ 	mfc1	$t7,$f4
/*    3aefc:	00000000 */ 	nop
/*    3af00:	448f4000 */ 	mtc1	$t7,$f8
/*    3af04:	00000000 */ 	nop
/*    3af08:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    3af0c:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*    3af10:	3c014700 */ 	lui	$at,0x4700
/*    3af14:	44819000 */ 	mtc1	$at,$f18
/*    3af18:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*    3af1c:	46128183 */ 	div.s	$f6,$f16,$f18
/*    3af20:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*    3af24:	3c013f80 */ 	lui	$at,0x3f80
/*    3af28:	44812000 */ 	mtc1	$at,$f4
/*    3af2c:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*    3af30:	46082281 */ 	sub.s	$f10,$f4,$f8
/*    3af34:	e7aa003c */ 	swc1	$f10,0x3c($sp)
/*    3af38:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3af3c:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*    3af40:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    3af44:	44989000 */ 	mtc1	$t8,$f18
/*    3af48:	8f280024 */ 	lw	$t0,0x24($t9)
/*    3af4c:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    3af50:	c5080024 */ 	lwc1	$f8,0x24($t0)
/*    3af54:	46068102 */ 	mul.s	$f4,$f16,$f6
/*    3af58:	46044280 */ 	add.s	$f10,$f8,$f4
/*    3af5c:	e7aa0040 */ 	swc1	$f10,0x40($sp)
/*    3af60:	c7b20040 */ 	lwc1	$f18,0x40($sp)
/*    3af64:	4600940d */ 	trunc.w.s	$f16,$f18
/*    3af68:	440a8000 */ 	mfc1	$t2,$f16
/*    3af6c:	00000000 */ 	nop
/*    3af70:	afaa004c */ 	sw	$t2,0x4c($sp)
/*    3af74:	8fab004c */ 	lw	$t3,0x4c($sp)
/*    3af78:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    3af7c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    3af80:	448b4000 */ 	mtc1	$t3,$f8
/*    3af84:	8d8d0024 */ 	lw	$t5,0x24($t4)
/*    3af88:	46804120 */ 	cvt.s.w	$f4,$f8
/*    3af8c:	46043281 */ 	sub.s	$f10,$f6,$f4
/*    3af90:	e5aa0024 */ 	swc1	$f10,0x24($t5)
/*    3af94:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    3af98:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    3af9c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    3afa0:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    3afa4:	8d2b0018 */ 	lw	$t3,0x18($t1)
/*    3afa8:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3afac:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    3afb0:	8f280028 */ 	lw	$t0,0x28($t9)
/*    3afb4:	014b6023 */ 	subu	$t4,$t2,$t3
/*    3afb8:	000c6823 */ 	negu	$t5,$t4
/*    3afbc:	000d7840 */ 	sll	$t7,$t5,0x1
/*    3afc0:	010f7021 */ 	addu	$t6,$t0,$t7
/*    3afc4:	afae0044 */ 	sw	$t6,0x44($sp)
/*    3afc8:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    3afcc:	33190007 */ 	andi	$t9,$t8,0x7
/*    3afd0:	00194843 */ 	sra	$t1,$t9,0x1
/*    3afd4:	afa90034 */ 	sw	$t1,0x34($sp)
/*    3afd8:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    3afdc:	8fad004c */ 	lw	$t5,0x4c($sp)
/*    3afe0:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    3afe4:	8faf0054 */ 	lw	$t7,0x54($sp)
/*    3afe8:	000b6040 */ 	sll	$t4,$t3,0x1
/*    3afec:	01ab4021 */ 	addu	$t0,$t5,$t3
/*    3aff0:	afa80010 */ 	sw	$t0,0x10($sp)
/*    3aff4:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    3aff8:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    3affc:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    3b000:	014c3023 */ 	subu	$a2,$t2,$t4
/*    3b004:	0c00ec5e */ 	jal	func0003b178
/*    3b008:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    3b00c:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3b010:	3c014700 */ 	lui	$at,0x4700
/*    3b014:	44818000 */ 	mtc1	$at,$f16
/*    3b018:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*    3b01c:	46109202 */ 	mul.s	$f8,$f18,$f16
/*    3b020:	4600418d */ 	trunc.w.s	$f6,$f8
/*    3b024:	44183000 */ 	mfc1	$t8,$f6
/*    3b028:	00000000 */ 	nop
/*    3b02c:	afb80050 */ 	sw	$t8,0x50($sp)
/*    3b030:	8fb90064 */ 	lw	$t9,0x64($sp)
/*    3b034:	00194a03 */ 	sra	$t1,$t9,0x8
/*    3b038:	a7a9002a */ 	sh	$t1,0x2a($sp)
/*    3b03c:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3b040:	254c0008 */ 	addiu	$t4,$t2,0x8
/*    3b044:	afac0054 */ 	sw	$t4,0x54($sp)
/*    3b048:	afaa0024 */ 	sw	$t2,0x24($sp)
/*    3b04c:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    3b050:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    3b054:	8dab0024 */ 	lw	$t3,0x24($t5)
/*    3b058:	00087880 */ 	sll	$t7,$t0,0x2
/*    3b05c:	016f7021 */ 	addu	$t6,$t3,$t7
/*    3b060:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b064:	8dc40014 */ 	lw	$a0,0x14($t6)
/*    3b068:	3c0100ff */ 	lui	$at,0xff
/*    3b06c:	3421ffff */ 	ori	$at,$at,0xffff
/*    3b070:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3b074:	0041c024 */ 	and	$t8,$v0,$at
/*    3b078:	3c010500 */ 	lui	$at,0x500
/*    3b07c:	0301c825 */ 	or	$t9,$t8,$at
/*    3b080:	ad390000 */ 	sw	$t9,0x0($t1)
/*    3b084:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    3b088:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3b08c:	8fa90048 */ 	lw	$t1,0x48($sp)
/*    3b090:	8d4c0024 */ 	lw	$t4,0x24($t2)
/*    3b094:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    3b098:	31eeffff */ 	andi	$t6,$t7,0xffff
/*    3b09c:	8d8d0028 */ 	lw	$t5,0x28($t4)
/*    3b0a0:	000ec380 */ 	sll	$t8,$t6,0xe
/*    3b0a4:	000a6040 */ 	sll	$t4,$t2,0x1
/*    3b0a8:	31a80003 */ 	andi	$t0,$t5,0x3
/*    3b0ac:	00085f80 */ 	sll	$t3,$t0,0x1e
/*    3b0b0:	0178c825 */ 	or	$t9,$t3,$t8
/*    3b0b4:	87ab002a */ 	lh	$t3,0x2a($sp)
/*    3b0b8:	012c6821 */ 	addu	$t5,$t1,$t4
/*    3b0bc:	31a80fff */ 	andi	$t0,$t5,0xfff
/*    3b0c0:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3b0c4:	00087880 */ 	sll	$t7,$t0,0x2
/*    3b0c8:	032f7025 */ 	or	$t6,$t9,$t7
/*    3b0cc:	31780003 */ 	andi	$t8,$t3,0x3
/*    3b0d0:	01d85025 */ 	or	$t2,$t6,$t8
/*    3b0d4:	ad2a0004 */ 	sw	$t2,0x4($t1)
/*    3b0d8:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    3b0dc:	8d8d0024 */ 	lw	$t5,0x24($t4)
/*    3b0e0:	ada00028 */ 	sw	$zero,0x28($t5)
/*    3b0e4:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    3b0e8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*    3b0ec:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3b0f0:	8d6e0018 */ 	lw	$t6,0x18($t3)
/*    3b0f4:	01197823 */ 	subu	$t7,$t0,$t9
/*    3b0f8:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    3b0fc:	10000016 */ 	b	.L0003b158
/*    3b100:	ad780018 */ 	sw	$t8,0x18($t3)
.L0003b104:
/*    3b104:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    3b108:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    3b10c:	8faa0058 */ 	lw	$t2,0x58($sp)
/*    3b110:	00096080 */ 	sll	$t4,$t1,0x2
/*    3b114:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*    3b118:	014c6821 */ 	addu	$t5,$t2,$t4
/*    3b11c:	8da80028 */ 	lw	$t0,0x28($t5)
/*    3b120:	000e7823 */ 	negu	$t7,$t6
/*    3b124:	000fc040 */ 	sll	$t8,$t7,0x1
/*    3b128:	01185821 */ 	addu	$t3,$t0,$t8
/*    3b12c:	afab0044 */ 	sw	$t3,0x44($sp)
/*    3b130:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3b134:	240900b8 */ 	addiu	$t1,$zero,0xb8
/*    3b138:	afa90010 */ 	sw	$t1,0x10($sp)
/*    3b13c:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    3b140:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    3b144:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3b148:	8fa70064 */ 	lw	$a3,0x64($sp)
/*    3b14c:	0c00ec5e */ 	jal	func0003b178
/*    3b150:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    3b154:	afa20054 */ 	sw	$v0,0x54($sp)
.L0003b158:
/*    3b158:	10000003 */ 	b	.L0003b168
/*    3b15c:	8fa20054 */ 	lw	$v0,0x54($sp)
/*    3b160:	10000001 */ 	b	.L0003b168
/*    3b164:	00000000 */ 	nop
.L0003b168:
/*    3b168:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3b16c:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    3b170:	03e00008 */ 	jr	$ra
/*    3b174:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003b178
/*    3b178:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    3b17c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3b180:	afa40038 */ 	sw	$a0,0x38($sp)
/*    3b184:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    3b188:	afa60040 */ 	sw	$a2,0x40($sp)
/*    3b18c:	afa70044 */ 	sw	$a3,0x44($sp)
/*    3b190:	8fae004c */ 	lw	$t6,0x4c($sp)
/*    3b194:	afae0034 */ 	sw	$t6,0x34($sp)
/*    3b198:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3b19c:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    3b1a0:	8dea0000 */ 	lw	$t2,0x0($t7)
/*    3b1a4:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3b1a8:	01f94021 */ 	addu	$t0,$t7,$t9
/*    3b1ac:	8d090020 */ 	lw	$t1,0x20($t0)
/*    3b1b0:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3b1b4:	012b6021 */ 	addu	$t4,$t1,$t3
/*    3b1b8:	afac0024 */ 	sw	$t4,0x24($sp)
/*    3b1bc:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    3b1c0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    3b1c4:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    3b1c8:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3b1cc:	01d94021 */ 	addu	$t0,$t6,$t9
/*    3b1d0:	8d0f0020 */ 	lw	$t7,0x20($t0)
/*    3b1d4:	01af082b */ 	sltu	$at,$t5,$t7
/*    3b1d8:	10200007 */ 	beqz	$at,.L0003b1f8
/*    3b1dc:	00000000 */ 	nop
/*    3b1e0:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    3b1e4:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3b1e8:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*    3b1ec:	000b6040 */ 	sll	$t4,$t3,0x1
/*    3b1f0:	014cc021 */ 	addu	$t8,$t2,$t4
/*    3b1f4:	afb80040 */ 	sw	$t8,0x40($sp)
.L0003b1f8:
/*    3b1f8:	8fae0048 */ 	lw	$t6,0x48($sp)
/*    3b1fc:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    3b200:	000ec840 */ 	sll	$t9,$t6,0x1
/*    3b204:	03286821 */ 	addu	$t5,$t9,$t0
/*    3b208:	afad0028 */ 	sw	$t5,0x28($sp)
/*    3b20c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3b210:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3b214:	012f082b */ 	sltu	$at,$t1,$t7
/*    3b218:	1020003a */ 	beqz	$at,.L0003b304
/*    3b21c:	00000000 */ 	nop
/*    3b220:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3b224:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3b228:	016a6023 */ 	subu	$t4,$t3,$t2
/*    3b22c:	000cc043 */ 	sra	$t8,$t4,0x1
/*    3b230:	afb80030 */ 	sw	$t8,0x30($sp)
/*    3b234:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3b238:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    3b23c:	01d94023 */ 	subu	$t0,$t6,$t9
/*    3b240:	00086843 */ 	sra	$t5,$t0,0x1
/*    3b244:	afad002c */ 	sw	$t5,0x2c($sp)
/*    3b248:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3b24c:	25e90008 */ 	addiu	$t1,$t7,0x8
/*    3b250:	afa90034 */ 	sw	$t1,0x34($sp)
/*    3b254:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    3b258:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3b25c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*    3b260:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3b264:	000b5040 */ 	sll	$t2,$t3,0x1
/*    3b268:	314c0fff */ 	andi	$t4,$t2,0xfff
/*    3b26c:	000cc300 */ 	sll	$t8,$t4,0xc
/*    3b270:	3c010400 */ 	lui	$at,0x400
/*    3b274:	03017025 */ 	or	$t6,$t8,$at
/*    3b278:	33280fff */ 	andi	$t0,$t9,0xfff
/*    3b27c:	01c86825 */ 	or	$t5,$t6,$t0
/*    3b280:	aded0000 */ 	sw	$t5,0x0($t7)
/*    3b284:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b288:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    3b28c:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3b290:	ad220004 */ 	sw	$v0,0x4($t1)
/*    3b294:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    3b298:	256a0008 */ 	addiu	$t2,$t3,0x8
/*    3b29c:	afaa0034 */ 	sw	$t2,0x34($sp)
/*    3b2a0:	afab001c */ 	sw	$t3,0x1c($sp)
/*    3b2a4:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3b2a8:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    3b2ac:	8fac0044 */ 	lw	$t4,0x44($sp)
/*    3b2b0:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3b2b4:	000d7840 */ 	sll	$t7,$t5,0x1
/*    3b2b8:	31e90fff */ 	andi	$t1,$t7,0xfff
/*    3b2bc:	01997021 */ 	addu	$t6,$t4,$t9
/*    3b2c0:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    3b2c4:	00095b00 */ 	sll	$t3,$t1,0xc
/*    3b2c8:	3c010400 */ 	lui	$at,0x400
/*    3b2cc:	01615025 */ 	or	$t2,$t3,$at
/*    3b2d0:	31c80fff */ 	andi	$t0,$t6,0xfff
/*    3b2d4:	0148c025 */ 	or	$t8,$t2,$t0
/*    3b2d8:	ad980000 */ 	sw	$t8,0x0($t4)
/*    3b2dc:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    3b2e0:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    3b2e4:	000e6880 */ 	sll	$t5,$t6,0x2
/*    3b2e8:	032d7821 */ 	addu	$t7,$t9,$t5
/*    3b2ec:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b2f0:	8de40020 */ 	lw	$a0,0x20($t7)
/*    3b2f4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3b2f8:	ad220004 */ 	sw	$v0,0x4($t1)
/*    3b2fc:	10000014 */ 	b	.L0003b350
/*    3b300:	00000000 */ 	nop
.L0003b304:
/*    3b304:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    3b308:	256a0008 */ 	addiu	$t2,$t3,0x8
/*    3b30c:	afaa0034 */ 	sw	$t2,0x34($sp)
/*    3b310:	afab0018 */ 	sw	$t3,0x18($sp)
/*    3b314:	8fa80048 */ 	lw	$t0,0x48($sp)
/*    3b318:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    3b31c:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    3b320:	0008c040 */ 	sll	$t8,$t0,0x1
/*    3b324:	330c0fff */ 	andi	$t4,$t8,0xfff
/*    3b328:	000c7300 */ 	sll	$t6,$t4,0xc
/*    3b32c:	3c010400 */ 	lui	$at,0x400
/*    3b330:	01c1c825 */ 	or	$t9,$t6,$at
/*    3b334:	31af0fff */ 	andi	$t7,$t5,0xfff
/*    3b338:	032f4825 */ 	or	$t1,$t9,$t7
/*    3b33c:	ad690000 */ 	sw	$t1,0x0($t3)
/*    3b340:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b344:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    3b348:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    3b34c:	ad420004 */ 	sw	$v0,0x4($t2)
.L0003b350:
/*    3b350:	10000003 */ 	b	.L0003b360
/*    3b354:	8fa20034 */ 	lw	$v0,0x34($sp)
/*    3b358:	10000001 */ 	b	.L0003b360
/*    3b35c:	00000000 */ 	nop
.L0003b360:
/*    3b360:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3b364:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    3b368:	03e00008 */ 	jr	$ra
/*    3b36c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003b370
/*    3b370:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    3b374:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3b378:	afa40038 */ 	sw	$a0,0x38($sp)
/*    3b37c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    3b380:	afa60040 */ 	sw	$a2,0x40($sp)
/*    3b384:	afa70044 */ 	sw	$a3,0x44($sp)
/*    3b388:	8fae0048 */ 	lw	$t6,0x48($sp)
/*    3b38c:	afae0034 */ 	sw	$t6,0x34($sp)
/*    3b390:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3b394:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    3b398:	8dea0000 */ 	lw	$t2,0x0($t7)
/*    3b39c:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3b3a0:	01f94021 */ 	addu	$t0,$t7,$t9
/*    3b3a4:	8d090020 */ 	lw	$t1,0x20($t0)
/*    3b3a8:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3b3ac:	012b6021 */ 	addu	$t4,$t1,$t3
/*    3b3b0:	afac0024 */ 	sw	$t4,0x24($sp)
/*    3b3b4:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    3b3b8:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    3b3bc:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    3b3c0:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3b3c4:	01d94021 */ 	addu	$t0,$t6,$t9
/*    3b3c8:	8d0f0020 */ 	lw	$t7,0x20($t0)
/*    3b3cc:	01af082b */ 	sltu	$at,$t5,$t7
/*    3b3d0:	10200007 */ 	beqz	$at,.L0003b3f0
/*    3b3d4:	00000000 */ 	nop
/*    3b3d8:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    3b3dc:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3b3e0:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*    3b3e4:	000b6040 */ 	sll	$t4,$t3,0x1
/*    3b3e8:	014cc021 */ 	addu	$t8,$t2,$t4
/*    3b3ec:	afb80040 */ 	sw	$t8,0x40($sp)
.L0003b3f0:
/*    3b3f0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    3b3f4:	25d90170 */ 	addiu	$t9,$t6,0x170
/*    3b3f8:	afb90028 */ 	sw	$t9,0x28($sp)
/*    3b3fc:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    3b400:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3b404:	01a8082b */ 	sltu	$at,$t5,$t0
/*    3b408:	1020003a */ 	beqz	$at,.L0003b4f4
/*    3b40c:	00000000 */ 	nop
/*    3b410:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3b414:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3b418:	01e95823 */ 	subu	$t3,$t7,$t1
/*    3b41c:	000b5043 */ 	sra	$t2,$t3,0x1
/*    3b420:	afaa0030 */ 	sw	$t2,0x30($sp)
/*    3b424:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3b428:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    3b42c:	01987023 */ 	subu	$t6,$t4,$t8
/*    3b430:	000ec843 */ 	sra	$t9,$t6,0x1
/*    3b434:	afb9002c */ 	sw	$t9,0x2c($sp)
/*    3b438:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    3b43c:	250d0008 */ 	addiu	$t5,$t0,0x8
/*    3b440:	afad0034 */ 	sw	$t5,0x34($sp)
/*    3b444:	afa80020 */ 	sw	$t0,0x20($sp)
/*    3b448:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3b44c:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    3b450:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3b454:	000f4840 */ 	sll	$t1,$t7,0x1
/*    3b458:	312b0fff */ 	andi	$t3,$t1,0xfff
/*    3b45c:	000b5300 */ 	sll	$t2,$t3,0xc
/*    3b460:	3c010600 */ 	lui	$at,0x600
/*    3b464:	01416025 */ 	or	$t4,$t2,$at
/*    3b468:	330e0fff */ 	andi	$t6,$t8,0xfff
/*    3b46c:	018ec825 */ 	or	$t9,$t4,$t6
/*    3b470:	ad190000 */ 	sw	$t9,0x0($t0)
/*    3b474:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b478:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    3b47c:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3b480:	ada20004 */ 	sw	$v0,0x4($t5)
/*    3b484:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3b488:	25e90008 */ 	addiu	$t1,$t7,0x8
/*    3b48c:	afa90034 */ 	sw	$t1,0x34($sp)
/*    3b490:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    3b494:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    3b498:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    3b49c:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    3b4a0:	000ac040 */ 	sll	$t8,$t2,0x1
/*    3b4a4:	00194040 */ 	sll	$t0,$t9,0x1
/*    3b4a8:	310d0fff */ 	andi	$t5,$t0,0xfff
/*    3b4ac:	01786021 */ 	addu	$t4,$t3,$t8
/*    3b4b0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    3b4b4:	000d7b00 */ 	sll	$t7,$t5,0xc
/*    3b4b8:	3c010600 */ 	lui	$at,0x600
/*    3b4bc:	01e14825 */ 	or	$t1,$t7,$at
/*    3b4c0:	318e0fff */ 	andi	$t6,$t4,0xfff
/*    3b4c4:	012e5025 */ 	or	$t2,$t1,$t6
/*    3b4c8:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3b4cc:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    3b4d0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    3b4d4:	000cc880 */ 	sll	$t9,$t4,0x2
/*    3b4d8:	03194021 */ 	addu	$t0,$t8,$t9
/*    3b4dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b4e0:	8d040020 */ 	lw	$a0,0x20($t0)
/*    3b4e4:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3b4e8:	ada20004 */ 	sw	$v0,0x4($t5)
/*    3b4ec:	1000000f */ 	b	.L0003b52c
/*    3b4f0:	00000000 */ 	nop
.L0003b4f4:
/*    3b4f4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3b4f8:	25e90008 */ 	addiu	$t1,$t7,0x8
/*    3b4fc:	afa90034 */ 	sw	$t1,0x34($sp)
/*    3b500:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    3b504:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    3b508:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    3b50c:	3c010617 */ 	lui	$at,0x617
/*    3b510:	31ca0fff */ 	andi	$t2,$t6,0xfff
/*    3b514:	01415825 */ 	or	$t3,$t2,$at
/*    3b518:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*    3b51c:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b520:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    3b524:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    3b528:	af020004 */ 	sw	$v0,0x4($t8)
.L0003b52c:
/*    3b52c:	10000003 */ 	b	.L0003b53c
/*    3b530:	8fa20034 */ 	lw	$v0,0x34($sp)
/*    3b534:	10000001 */ 	b	.L0003b53c
/*    3b538:	00000000 */ 	nop
.L0003b53c:
/*    3b53c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3b540:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    3b544:	03e00008 */ 	jr	$ra
/*    3b548:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003b54c
/*    3b54c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3b550:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3b554:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3b558:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3b55c:	afa60030 */ 	sw	$a2,0x30($sp)
/*    3b560:	afa70034 */ 	sw	$a3,0x34($sp)
/*    3b564:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    3b568:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3b56c:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3b570:	000fc203 */ 	sra	$t8,$t7,0x8
/*    3b574:	a7b80022 */ 	sh	$t8,0x22($sp)
/*    3b578:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3b57c:	27280008 */ 	addiu	$t0,$t9,0x8
/*    3b580:	afa80024 */ 	sw	$t0,0x24($sp)
/*    3b584:	afb9001c */ 	sw	$t9,0x1c($sp)
/*    3b588:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    3b58c:	3c090b00 */ 	lui	$t1,0xb00
/*    3b590:	35290020 */ 	ori	$t1,$t1,0x20
/*    3b594:	ad490000 */ 	sw	$t1,0x0($t2)
/*    3b598:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    3b59c:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b5a0:	24840008 */ 	addiu	$a0,$a0,0x8
/*    3b5a4:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    3b5a8:	ad620004 */ 	sw	$v0,0x4($t3)
/*    3b5ac:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3b5b0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    3b5b4:	afad0024 */ 	sw	$t5,0x24($sp)
/*    3b5b8:	afac0018 */ 	sw	$t4,0x18($sp)
/*    3b5bc:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3b5c0:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    3b5c4:	3c010e00 */ 	lui	$at,0xe00
/*    3b5c8:	8dcf0028 */ 	lw	$t7,0x28($t6)
/*    3b5cc:	85c90002 */ 	lh	$t1,0x2($t6)
/*    3b5d0:	31f800ff */ 	andi	$t8,$t7,0xff
/*    3b5d4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*    3b5d8:	03214025 */ 	or	$t0,$t9,$at
/*    3b5dc:	312affff */ 	andi	$t2,$t1,0xffff
/*    3b5e0:	010a5825 */ 	or	$t3,$t0,$t2
/*    3b5e4:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*    3b5e8:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3b5ec:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3b5f0:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3b5f4:	01b8c821 */ 	addu	$t9,$t5,$t8
/*    3b5f8:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3b5fc:	8f24002c */ 	lw	$a0,0x2c($t9)
/*    3b600:	87a90022 */ 	lh	$t1,0x22($sp)
/*    3b604:	3c0100ff */ 	lui	$at,0xff
/*    3b608:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    3b60c:	3421ffff */ 	ori	$at,$at,0xffff
/*    3b610:	312800ff */ 	andi	$t0,$t1,0xff
/*    3b614:	00085600 */ 	sll	$t2,$t0,0x18
/*    3b618:	00417024 */ 	and	$t6,$v0,$at
/*    3b61c:	01ca5825 */ 	or	$t3,$t6,$t2
/*    3b620:	ad8b0004 */ 	sw	$t3,0x4($t4)
/*    3b624:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3b628:	ade00028 */ 	sw	$zero,0x28($t7)
/*    3b62c:	10000003 */ 	b	.L0003b63c
/*    3b630:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    3b634:	10000001 */ 	b	.L0003b63c
/*    3b638:	00000000 */ 	nop
.L0003b63c:
/*    3b63c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3b640:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3b644:	03e00008 */ 	jr	$ra
/*    3b648:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003b64c
/*    3b64c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3b650:	44853000 */ 	mtc1	$a1,$f6
/*    3b654:	c4840010 */ 	lwc1	$f4,0x10($a0)
/*    3b658:	c4900014 */ 	lwc1	$f16,0x14($a0)
/*    3b65c:	46803220 */ 	cvt.s.w	$f8,$f6
/*    3b660:	46082282 */ 	mul.s	$f10,$f4,$f8
/*    3b664:	460a8480 */ 	add.s	$f18,$f16,$f10
/*    3b668:	e4920014 */ 	swc1	$f18,0x14($a0)
/*    3b66c:	3c014000 */ 	lui	$at,0x4000
/*    3b670:	44812000 */ 	mtc1	$at,$f4
/*    3b674:	c4860014 */ 	lwc1	$f6,0x14($a0)
/*    3b678:	4606203c */ 	c.lt.s	$f4,$f6
/*    3b67c:	00000000 */ 	nop
/*    3b680:	45000007 */ 	bc1f	.L0003b6a0
/*    3b684:	00000000 */ 	nop
/*    3b688:	3c014080 */ 	lui	$at,0x4080
/*    3b68c:	44818000 */ 	mtc1	$at,$f16
/*    3b690:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*    3b694:	46104281 */ 	sub.s	$f10,$f8,$f16
/*    3b698:	10000003 */ 	b	.L0003b6a8
/*    3b69c:	e48a0014 */ 	swc1	$f10,0x14($a0)
.L0003b6a0:
/*    3b6a0:	c4920014 */ 	lwc1	$f18,0x14($a0)
/*    3b6a4:	e4920014 */ 	swc1	$f18,0x14($a0)
.L0003b6a8:
/*    3b6a8:	c4860014 */ 	lwc1	$f6,0x14($a0)
/*    3b6ac:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*    3b6b0:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    3b6b4:	44804000 */ 	mtc1	$zero,$f8
/*    3b6b8:	00000000 */ 	nop
/*    3b6bc:	4608203c */ 	c.lt.s	$f4,$f8
/*    3b6c0:	00000000 */ 	nop
/*    3b6c4:	45000004 */ 	bc1f	.L0003b6d8
/*    3b6c8:	00000000 */ 	nop
/*    3b6cc:	46002407 */ 	neg.s	$f16,$f4
/*    3b6d0:	10000001 */ 	b	.L0003b6d8
/*    3b6d4:	e7b00004 */ 	swc1	$f16,0x4($sp)
.L0003b6d8:
/*    3b6d8:	3c013f80 */ 	lui	$at,0x3f80
/*    3b6dc:	44819000 */ 	mtc1	$at,$f18
/*    3b6e0:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    3b6e4:	46125181 */ 	sub.s	$f6,$f10,$f18
/*    3b6e8:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*    3b6ec:	c488001c */ 	lwc1	$f8,0x1c($a0)
/*    3b6f0:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    3b6f4:	46044002 */ 	mul.s	$f0,$f8,$f4
/*    3b6f8:	10000003 */ 	b	.L0003b708
/*    3b6fc:	00000000 */ 	nop
/*    3b700:	10000001 */ 	b	.L0003b708
/*    3b704:	00000000 */ 	nop
.L0003b708:
/*    3b708:	03e00008 */ 	jr	$ra
/*    3b70c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003b710
.late_rodata
glabel var70054ac0
.word 0x40490fdb
glabel var70054ac4
.word 0x3fb504f4
.text
/*    3b710:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3b714:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3b718:	afa60030 */ 	sw	$a2,0x30($sp)
/*    3b71c:	afa70034 */ 	sw	$a3,0x34($sp)
/*    3b720:	e7ac0028 */ 	swc1	$f12,0x28($sp)
/*    3b724:	e7ae002c */ 	swc1	$f14,0x2c($sp)
/*    3b728:	3c014348 */ 	lui	$at,0x4348
/*    3b72c:	44814000 */ 	mtc1	$at,$f8
/*    3b730:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*    3b734:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*    3b738:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    3b73c:	4604503e */ 	c.le.s	$f10,$f4
/*    3b740:	00000000 */ 	nop
/*    3b744:	45000006 */ 	bc1f	.L0003b760
/*    3b748:	00000000 */ 	nop
/*    3b74c:	3c014348 */ 	lui	$at,0x4348
/*    3b750:	44819000 */ 	mtc1	$at,$f18
/*    3b754:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*    3b758:	46128181 */ 	sub.s	$f6,$f16,$f18
/*    3b75c:	e7a6002c */ 	swc1	$f6,0x2c($sp)
.L0003b760:
/*    3b760:	3c017005 */ 	lui	$at,%hi(var70054ac0)
/*    3b764:	c4244ac0 */ 	lwc1	$f4,%lo(var70054ac0)($at)
/*    3b768:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*    3b76c:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*    3b770:	46044282 */ 	mul.s	$f10,$f8,$f4
/*    3b774:	460083a1 */ 	cvt.d.s	$f14,$f16
/*    3b778:	0fc259d4 */ 	jal	atan2f
/*    3b77c:	46005321 */ 	cvt.d.s	$f12,$f10
/*    3b780:	44829000 */ 	mtc1	$v0,$f18
/*    3b784:	00000000 */ 	nop
/*    3b788:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    3b78c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*    3b790:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    3b794:	46084102 */ 	mul.s	$f4,$f8,$f8
/*    3b798:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*    3b79c:	3c017005 */ 	lui	$at,%hi(var70054ac4)
/*    3b7a0:	c4304ac4 */ 	lwc1	$f16,%lo(var70054ac4)($at)
/*    3b7a4:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*    3b7a8:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    3b7ac:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    3b7b0:	46069203 */ 	div.s	$f8,$f18,$f6
/*    3b7b4:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    3b7b8:	3c013f80 */ 	lui	$at,0x3f80
/*    3b7bc:	44812000 */ 	mtc1	$at,$f4
/*    3b7c0:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*    3b7c4:	c7b2001c */ 	lwc1	$f18,0x1c($sp)
/*    3b7c8:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    3b7cc:	460a2400 */ 	add.s	$f16,$f4,$f10
/*    3b7d0:	46128180 */ 	add.s	$f6,$f16,$f18
/*    3b7d4:	46065203 */ 	div.s	$f8,$f10,$f6
/*    3b7d8:	e5c80000 */ 	swc1	$f8,0x0($t6)
/*    3b7dc:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3b7e0:	3c014000 */ 	lui	$at,0x4000
/*    3b7e4:	44818000 */ 	mtc1	$at,$f16
/*    3b7e8:	c5e40000 */ 	lwc1	$f4,0x0($t7)
/*    3b7ec:	46102482 */ 	mul.s	$f18,$f4,$f16
/*    3b7f0:	e5f20004 */ 	swc1	$f18,0x4($t7)
/*    3b7f4:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    3b7f8:	c70a0000 */ 	lwc1	$f10,0x0($t8)
/*    3b7fc:	e70a0008 */ 	swc1	$f10,0x8($t8)
/*    3b800:	3c013f80 */ 	lui	$at,0x3f80
/*    3b804:	44814000 */ 	mtc1	$at,$f8
/*    3b808:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    3b80c:	3c014000 */ 	lui	$at,0x4000
/*    3b810:	44818000 */ 	mtc1	$at,$f16
/*    3b814:	46083101 */ 	sub.s	$f4,$f6,$f8
/*    3b818:	3c013f80 */ 	lui	$at,0x3f80
/*    3b81c:	44815000 */ 	mtc1	$at,$f10
/*    3b820:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    3b824:	46102482 */ 	mul.s	$f18,$f4,$f16
/*    3b828:	46065200 */ 	add.s	$f8,$f10,$f6
/*    3b82c:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*    3b830:	46044400 */ 	add.s	$f16,$f8,$f4
/*    3b834:	46109283 */ 	div.s	$f10,$f18,$f16
/*    3b838:	e72a0004 */ 	swc1	$f10,0x4($t9)
/*    3b83c:	3c013f80 */ 	lui	$at,0x3f80
/*    3b840:	44813000 */ 	mtc1	$at,$f6
/*    3b844:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    3b848:	44815000 */ 	mtc1	$at,$f10
/*    3b84c:	c7b2001c */ 	lwc1	$f18,0x1c($sp)
/*    3b850:	46083100 */ 	add.s	$f4,$f6,$f8
/*    3b854:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    3b858:	46085180 */ 	add.s	$f6,$f10,$f8
/*    3b85c:	46122401 */ 	sub.s	$f16,$f4,$f18
/*    3b860:	46123100 */ 	add.s	$f4,$f6,$f18
/*    3b864:	46048283 */ 	div.s	$f10,$f16,$f4
/*    3b868:	e50a0008 */ 	swc1	$f10,0x8($t0)
/*    3b86c:	10000001 */ 	b	.L0003b874
/*    3b870:	00000000 */ 	nop
.L0003b874:
/*    3b874:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3b878:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3b87c:	03e00008 */ 	jr	$ra
/*    3b880:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003b884
/*    3b884:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3b888:	848e0000 */ 	lh	$t6,0x0($a0)
/*    3b88c:	3c014680 */ 	lui	$at,0x4680
/*    3b890:	44814000 */ 	mtc1	$at,$f8
/*    3b894:	448e2000 */ 	mtc1	$t6,$f4
/*    3b898:	00000000 */ 	nop
/*    3b89c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3b8a0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    3b8a4:	4600540d */ 	trunc.w.s	$f16,$f10
/*    3b8a8:	44188000 */ 	mfc1	$t8,$f16
/*    3b8ac:	00000000 */ 	nop
/*    3b8b0:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3b8b4:	8fb90010 */ 	lw	$t9,0x10($sp)
/*    3b8b8:	001943c3 */ 	sra	$t0,$t9,0xf
/*    3b8bc:	a7a8000e */ 	sh	$t0,0xe($sp)
/*    3b8c0:	87a9000e */ 	lh	$t1,0xe($sp)
/*    3b8c4:	3c014680 */ 	lui	$at,0x4680
/*    3b8c8:	44819000 */ 	mtc1	$at,$f18
/*    3b8cc:	44892000 */ 	mtc1	$t1,$f4
/*    3b8d0:	00000000 */ 	nop
/*    3b8d4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3b8d8:	46069201 */ 	sub.s	$f8,$f18,$f6
/*    3b8dc:	4600428d */ 	trunc.w.s	$f10,$f8
/*    3b8e0:	440b5000 */ 	mfc1	$t3,$f10
/*    3b8e4:	00000000 */ 	nop
/*    3b8e8:	a48b0002 */ 	sh	$t3,0x2($a0)
/*    3b8ec:	ac800028 */ 	sw	$zero,0x28($a0)
/*    3b8f0:	afa00014 */ 	sw	$zero,0x14($sp)
.L0003b8f4:
/*    3b8f4:	8fac0014 */ 	lw	$t4,0x14($sp)
/*    3b8f8:	000c6840 */ 	sll	$t5,$t4,0x1
/*    3b8fc:	008d7021 */ 	addu	$t6,$a0,$t5
/*    3b900:	a5c00008 */ 	sh	$zero,0x8($t6)
/*    3b904:	8faf0014 */ 	lw	$t7,0x14($sp)
/*    3b908:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    3b90c:	2b010008 */ 	slti	$at,$t8,0x8
/*    3b910:	1420fff8 */ 	bnez	$at,.L0003b8f4
/*    3b914:	afb80014 */ 	sw	$t8,0x14($sp)
/*    3b918:	8fa80014 */ 	lw	$t0,0x14($sp)
/*    3b91c:	87b9000e */ 	lh	$t9,0xe($sp)
/*    3b920:	00084840 */ 	sll	$t1,$t0,0x1
/*    3b924:	00895021 */ 	addu	$t2,$a0,$t1
/*    3b928:	a5590008 */ 	sh	$t9,0x8($t2)
/*    3b92c:	8fab0014 */ 	lw	$t3,0x14($sp)
/*    3b930:	256c0001 */ 	addiu	$t4,$t3,0x1
/*    3b934:	afac0014 */ 	sw	$t4,0x14($sp)
/*    3b938:	3c014680 */ 	lui	$at,0x4680
/*    3b93c:	44818000 */ 	mtc1	$at,$f16
/*    3b940:	00000000 */ 	nop
/*    3b944:	e7b00000 */ 	swc1	$f16,0x0($sp)
/*    3b948:	87ad000e */ 	lh	$t5,0xe($sp)
/*    3b94c:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*    3b950:	448d2000 */ 	mtc1	$t5,$f4
/*    3b954:	00000000 */ 	nop
/*    3b958:	468024a0 */ 	cvt.s.w	$f18,$f4
/*    3b95c:	46069203 */ 	div.s	$f8,$f18,$f6
/*    3b960:	e7a80008 */ 	swc1	$f8,0x8($sp)
/*    3b964:	e7a80004 */ 	swc1	$f8,0x4($sp)
/*    3b968:	8fae0014 */ 	lw	$t6,0x14($sp)
/*    3b96c:	29c10010 */ 	slti	$at,$t6,0x10
/*    3b970:	10200014 */ 	beqz	$at,.L0003b9c4
/*    3b974:	00000000 */ 	nop
.L0003b978:
/*    3b978:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    3b97c:	c7b00008 */ 	lwc1	$f16,0x8($sp)
/*    3b980:	46105102 */ 	mul.s	$f4,$f10,$f16
/*    3b984:	e7a40004 */ 	swc1	$f4,0x4($sp)
/*    3b988:	c7b20004 */ 	lwc1	$f18,0x4($sp)
/*    3b98c:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*    3b990:	8fa80014 */ 	lw	$t0,0x14($sp)
/*    3b994:	46069202 */ 	mul.s	$f8,$f18,$f6
/*    3b998:	00084840 */ 	sll	$t1,$t0,0x1
/*    3b99c:	0089c821 */ 	addu	$t9,$a0,$t1
/*    3b9a0:	4600428d */ 	trunc.w.s	$f10,$f8
/*    3b9a4:	44185000 */ 	mfc1	$t8,$f10
/*    3b9a8:	00000000 */ 	nop
/*    3b9ac:	a7380008 */ 	sh	$t8,0x8($t9)
/*    3b9b0:	8faa0014 */ 	lw	$t2,0x14($sp)
/*    3b9b4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    3b9b8:	29610010 */ 	slti	$at,$t3,0x10
/*    3b9bc:	1420ffee */ 	bnez	$at,.L0003b978
/*    3b9c0:	afab0014 */ 	sw	$t3,0x14($sp)
.L0003b9c4:
/*    3b9c4:	10000001 */ 	b	.L0003b9cc
/*    3b9c8:	00000000 */ 	nop
.L0003b9cc:
/*    3b9cc:	03e00008 */ 	jr	$ra
/*    3b9d0:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0003b9d4
.late_rodata
glabel var70054ac8
.word 0x3f879c7d
glabel var70054acc
.word 0x3f71a1bf
.text
/*    3b9d4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3b9d8:	3c013f80 */ 	lui	$at,0x3f80
/*    3b9dc:	44812000 */ 	mtc1	$at,$f4
/*    3b9e0:	00000000 */ 	nop
/*    3b9e4:	e7a40000 */ 	swc1	$f4,0x0($sp)
/*    3b9e8:	04800005 */ 	bltz	$a0,.L0003ba00
/*    3b9ec:	00000000 */ 	nop
/*    3b9f0:	3c017005 */ 	lui	$at,%hi(var70054ac8)
/*    3b9f4:	c4264ac8 */ 	lwc1	$f6,%lo(var70054ac8)($at)
/*    3b9f8:	10000005 */ 	b	.L0003ba10
/*    3b9fc:	e7a60004 */ 	swc1	$f6,0x4($sp)
.L0003ba00:
/*    3ba00:	3c017005 */ 	lui	$at,%hi(var70054acc)
/*    3ba04:	c4284acc */ 	lwc1	$f8,%lo(var70054acc)($at)
/*    3ba08:	e7a80004 */ 	swc1	$f8,0x4($sp)
/*    3ba0c:	00042023 */ 	negu	$a0,$a0
.L0003ba10:
/*    3ba10:	1080000e */ 	beqz	$a0,.L0003ba4c
/*    3ba14:	00000000 */ 	nop
.L0003ba18:
/*    3ba18:	308e0001 */ 	andi	$t6,$a0,0x1
/*    3ba1c:	11c00005 */ 	beqz	$t6,.L0003ba34
/*    3ba20:	00000000 */ 	nop
/*    3ba24:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    3ba28:	c7b00004 */ 	lwc1	$f16,0x4($sp)
/*    3ba2c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    3ba30:	e7b20000 */ 	swc1	$f18,0x0($sp)
.L0003ba34:
/*    3ba34:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    3ba38:	46042182 */ 	mul.s	$f6,$f4,$f4
/*    3ba3c:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*    3ba40:	00042043 */ 	sra	$a0,$a0,0x1
/*    3ba44:	1480fff4 */ 	bnez	$a0,.L0003ba18
/*    3ba48:	00000000 */ 	nop
.L0003ba4c:
/*    3ba4c:	10000003 */ 	b	.L0003ba5c
/*    3ba50:	c7a00000 */ 	lwc1	$f0,0x0($sp)
/*    3ba54:	10000001 */ 	b	.L0003ba5c
/*    3ba58:	00000000 */ 	nop
.L0003ba5c:
/*    3ba5c:	03e00008 */ 	jr	$ra
/*    3ba60:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003ba64
.late_rodata
glabel var70054ad0
.word 0x46d12000
glabel var70054ad4
.word 0x46d12000
.text
/*    3ba64:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    3ba68:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3ba6c:	afa40040 */ 	sw	$a0,0x40($sp)
/*    3ba70:	afa50044 */ 	sw	$a1,0x44($sp)
/*    3ba74:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    3ba78:	85cf0002 */ 	lh	$t7,0x2($t6)
/*    3ba7c:	15e00003 */ 	bnez	$t7,.L0003ba8c
/*    3ba80:	00000000 */ 	nop
/*    3ba84:	1000006e */ 	b	.L0003bc40
/*    3ba88:	00000000 */ 	nop
.L0003ba8c:
/*    3ba8c:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    3ba90:	87190002 */ 	lh	$t9,0x2($t8)
/*    3ba94:	2b21000a */ 	slti	$at,$t9,0xa
/*    3ba98:	10200004 */ 	beqz	$at,.L0003baac
/*    3ba9c:	00000000 */ 	nop
/*    3baa0:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    3baa4:	2408000a */ 	addiu	$t0,$zero,0xa
/*    3baa8:	a5280002 */ 	sh	$t0,0x2($t1)
.L0003baac:
/*    3baac:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3bab0:	3c014120 */ 	lui	$at,0x4120
/*    3bab4:	44819000 */ 	mtc1	$at,$f18
/*    3bab8:	854c0002 */ 	lh	$t4,0x2($t2)
/*    3babc:	854b0000 */ 	lh	$t3,0x0($t2)
/*    3bac0:	44814000 */ 	mtc1	$at,$f8
/*    3bac4:	448c5000 */ 	mtc1	$t4,$f10
/*    3bac8:	448b2000 */ 	mtc1	$t3,$f4
/*    3bacc:	27ad0024 */ 	addiu	$t5,$sp,0x24
/*    3bad0:	46805420 */ 	cvt.s.w	$f16,$f10
/*    3bad4:	afad0010 */ 	sw	$t5,0x10($sp)
/*    3bad8:	c7ac0044 */ 	lwc1	$f12,0x44($sp)
/*    3badc:	27a70030 */ 	addiu	$a3,$sp,0x30
/*    3bae0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3bae4:	46128103 */ 	div.s	$f4,$f16,$f18
/*    3bae8:	46083380 */ 	add.s	$f14,$f6,$f8
/*    3baec:	44062000 */ 	mfc1	$a2,$f4
/*    3baf0:	0c00edc4 */ 	jal	func0003b710
/*    3baf4:	00000000 */ 	nop
/*    3baf8:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    3bafc:	afae003c */ 	sw	$t6,0x3c($sp)
.L0003bb00:
/*    3bb00:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    3bb04:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    3bb08:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3bb0c:	01f94021 */ 	addu	$t0,$t7,$t9
/*    3bb10:	a5000008 */ 	sh	$zero,0x8($t0)
/*    3bb14:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    3bb18:	252b0001 */ 	addiu	$t3,$t1,0x1
/*    3bb1c:	29610008 */ 	slti	$at,$t3,0x8
/*    3bb20:	1420fff7 */ 	bnez	$at,.L0003bb00
/*    3bb24:	afab003c */ 	sw	$t3,0x3c($sp)
/*    3bb28:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3bb2c:	3c014300 */ 	lui	$at,0x4300
/*    3bb30:	44815000 */ 	mtc1	$at,$f10
/*    3bb34:	854c0002 */ 	lh	$t4,0x2($t2)
/*    3bb38:	3c017005 */ 	lui	$at,%hi(var70054ad0)
/*    3bb3c:	c4324ad0 */ 	lwc1	$f18,%lo(var70054ad0)($at)
/*    3bb40:	448c3000 */ 	mtc1	$t4,$f6
/*    3bb44:	27ad0030 */ 	addiu	$t5,$sp,0x30
/*    3bb48:	46803220 */ 	cvt.s.w	$f8,$f6
/*    3bb4c:	c5a60000 */ 	lwc1	$f6,0x0($t5)
/*    3bb50:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    3bb54:	46109101 */ 	sub.s	$f4,$f18,$f16
/*    3bb58:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    3bb5c:	4600428d */ 	trunc.w.s	$f10,$f8
/*    3bb60:	44185000 */ 	mfc1	$t8,$f10
/*    3bb64:	00000000 */ 	nop
/*    3bb68:	a5580008 */ 	sh	$t8,0x8($t2)
/*    3bb6c:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    3bb70:	3c014300 */ 	lui	$at,0x4300
/*    3bb74:	44813000 */ 	mtc1	$at,$f6
/*    3bb78:	85f90002 */ 	lh	$t9,0x2($t7)
/*    3bb7c:	3c017005 */ 	lui	$at,%hi(var70054ad4)
/*    3bb80:	c4284ad4 */ 	lwc1	$f8,%lo(var70054ad4)($at)
/*    3bb84:	44999000 */ 	mtc1	$t9,$f18
/*    3bb88:	27a80030 */ 	addiu	$t0,$sp,0x30
/*    3bb8c:	46809420 */ 	cvt.s.w	$f16,$f18
/*    3bb90:	c5120004 */ 	lwc1	$f18,0x4($t0)
/*    3bb94:	46068102 */ 	mul.s	$f4,$f16,$f6
/*    3bb98:	46044281 */ 	sub.s	$f10,$f8,$f4
/*    3bb9c:	460a9402 */ 	mul.s	$f16,$f18,$f10
/*    3bba0:	4600818d */ 	trunc.w.s	$f6,$f16
/*    3bba4:	440b3000 */ 	mfc1	$t3,$f6
/*    3bba8:	00000000 */ 	nop
/*    3bbac:	a5eb000a */ 	sh	$t3,0xa($t7)
/*    3bbb0:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3bbb4:	a580000c */ 	sh	$zero,0xc($t4)
/*    3bbb8:	27ad0024 */ 	addiu	$t5,$sp,0x24
/*    3bbbc:	3c01c680 */ 	lui	$at,0xc680
/*    3bbc0:	44812000 */ 	mtc1	$at,$f4
/*    3bbc4:	c5a80004 */ 	lwc1	$f8,0x4($t5)
/*    3bbc8:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3bbcc:	46044482 */ 	mul.s	$f18,$f8,$f4
/*    3bbd0:	4600928d */ 	trunc.w.s	$f10,$f18
/*    3bbd4:	44185000 */ 	mfc1	$t8,$f10
/*    3bbd8:	00000000 */ 	nop
/*    3bbdc:	a5580018 */ 	sh	$t8,0x18($t2)
/*    3bbe0:	27b90024 */ 	addiu	$t9,$sp,0x24
/*    3bbe4:	3c01c680 */ 	lui	$at,0xc680
/*    3bbe8:	44813000 */ 	mtc1	$at,$f6
/*    3bbec:	c7300008 */ 	lwc1	$f16,0x8($t9)
/*    3bbf0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    3bbf4:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    3bbf8:	4600410d */ 	trunc.w.s	$f4,$f8
/*    3bbfc:	44092000 */ 	mfc1	$t1,$f4
/*    3bc00:	00000000 */ 	nop
/*    3bc04:	a569001a */ 	sh	$t1,0x1a($t3)
/*    3bc08:	240f000a */ 	addiu	$t7,$zero,0xa
/*    3bc0c:	afaf003c */ 	sw	$t7,0x3c($sp)
.L0003bc10:
/*    3bc10:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    3bc14:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3bc18:	000d7040 */ 	sll	$t6,$t5,0x1
/*    3bc1c:	018ec021 */ 	addu	$t8,$t4,$t6
/*    3bc20:	a7000008 */ 	sh	$zero,0x8($t8)
/*    3bc24:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    3bc28:	25590001 */ 	addiu	$t9,$t2,0x1
/*    3bc2c:	2b210010 */ 	slti	$at,$t9,0x10
/*    3bc30:	1420fff7 */ 	bnez	$at,.L0003bc10
/*    3bc34:	afb9003c */ 	sw	$t9,0x3c($sp)
/*    3bc38:	10000001 */ 	b	.L0003bc40
/*    3bc3c:	00000000 */ 	nop
.L0003bc40:
/*    3bc40:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3bc44:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    3bc48:	03e00008 */ 	jr	$ra
/*    3bc4c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003bc50
.late_rodata
glabel var70054ad8
.word 0x482910da
.text
/*    3bc50:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    3bc54:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3bc58:	afa40038 */ 	sw	$a0,0x38($sp)
/*    3bc5c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    3bc60:	afa60040 */ 	sw	$a2,0x40($sp)
/*    3bc64:	afa70044 */ 	sw	$a3,0x44($sp)
/*    3bc68:	afa0002c */ 	sw	$zero,0x2c($sp)
/*    3bc6c:	240e0030 */ 	addiu	$t6,$zero,0x30
/*    3bc70:	afae0010 */ 	sw	$t6,0x10($sp)
/*    3bc74:	00002025 */ 	or	$a0,$zero,$zero
/*    3bc78:	00002825 */ 	or	$a1,$zero,$zero
/*    3bc7c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3bc80:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3bc84:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3bc88:	afa20024 */ 	sw	$v0,0x24($sp)
/*    3bc8c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3bc90:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    3bc94:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    3bc98:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    3bc9c:	87a80042 */ 	lh	$t0,0x42($sp)
/*    3bca0:	24010006 */ 	addiu	$at,$zero,0x6
/*    3bca4:	03284821 */ 	addu	$t1,$t9,$t0
/*    3bca8:	912a001c */ 	lbu	$t2,0x1c($t1)
/*    3bcac:	1541000b */ 	bne	$t2,$at,.L0003bcdc
/*    3bcb0:	00000000 */ 	nop
/*    3bcb4:	10000001 */ 	b	.L0003bcbc
/*    3bcb8:	00000000 */ 	nop
.L0003bcbc:
/*    3bcbc:	87ac0042 */ 	lh	$t4,0x42($sp)
/*    3bcc0:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    3bcc4:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3bcc8:	016d7021 */ 	addu	$t6,$t3,$t5
/*    3bccc:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3bcd0:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    3bcd4:	10000006 */ 	b	.L0003bcf0
/*    3bcd8:	00000000 */ 	nop
.L0003bcdc:
/*    3bcdc:	3c188006 */ 	lui	$t8,%hi(var8005f548)
/*    3bce0:	2718f548 */ 	addiu	$t8,$t8,%lo(var8005f548)
/*    3bce4:	afb8002c */ 	sw	$t8,0x2c($sp)
/*    3bce8:	10000001 */ 	b	.L0003bcf0
/*    3bcec:	00000000 */ 	nop
.L0003bcf0:
/*    3bcf0:	a7a00034 */ 	sh	$zero,0x34($sp)
/*    3bcf4:	97a80034 */ 	lhu	$t0,0x34($sp)
/*    3bcf8:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3bcfc:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3bd00:	00084880 */ 	sll	$t1,$t0,0x2
/*    3bd04:	03295021 */ 	addu	$t2,$t9,$t1
/*    3bd08:	8d4c0000 */ 	lw	$t4,0x0($t2)
/*    3bd0c:	a16c0008 */ 	sb	$t4,0x8($t3)
/*    3bd10:	97ad0034 */ 	lhu	$t5,0x34($sp)
/*    3bd14:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    3bd18:	a7ae0034 */ 	sh	$t6,0x34($sp)
/*    3bd1c:	97b80034 */ 	lhu	$t8,0x34($sp)
/*    3bd20:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3bd24:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3bd28:	00184080 */ 	sll	$t0,$t8,0x2
/*    3bd2c:	01e8c821 */ 	addu	$t9,$t7,$t0
/*    3bd30:	8f290000 */ 	lw	$t1,0x0($t9)
/*    3bd34:	ad490000 */ 	sw	$t1,0x0($t2)
/*    3bd38:	97ac0034 */ 	lhu	$t4,0x34($sp)
/*    3bd3c:	258b0001 */ 	addiu	$t3,$t4,0x1
/*    3bd40:	a7ab0034 */ 	sh	$t3,0x34($sp)
/*    3bd44:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3bd48:	240e0028 */ 	addiu	$t6,$zero,0x28
/*    3bd4c:	00002025 */ 	or	$a0,$zero,$zero
/*    3bd50:	91a70008 */ 	lbu	$a3,0x8($t5)
/*    3bd54:	afae0010 */ 	sw	$t6,0x10($sp)
/*    3bd58:	00002825 */ 	or	$a1,$zero,$zero
/*    3bd5c:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3bd60:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3bd64:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3bd68:	af020004 */ 	sw	$v0,0x4($t8)
/*    3bd6c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3bd70:	24080002 */ 	addiu	$t0,$zero,0x2
/*    3bd74:	00002025 */ 	or	$a0,$zero,$zero
/*    3bd78:	8de70000 */ 	lw	$a3,0x0($t7)
/*    3bd7c:	afa80010 */ 	sw	$t0,0x10($sp)
/*    3bd80:	00002825 */ 	or	$a1,$zero,$zero
/*    3bd84:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3bd88:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3bd8c:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3bd90:	af220020 */ 	sw	$v0,0x20($t9)
/*    3bd94:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3bd98:	8d2a0020 */ 	lw	$t2,0x20($t1)
/*    3bd9c:	ad2a0028 */ 	sw	$t2,0x28($t1)
/*    3bda0:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3bda4:	240b0002 */ 	addiu	$t3,$zero,0x2
/*    3bda8:	00002025 */ 	or	$a0,$zero,$zero
/*    3bdac:	8d870000 */ 	lw	$a3,0x0($t4)
/*    3bdb0:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3bdb4:	00002825 */ 	or	$a1,$zero,$zero
/*    3bdb8:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3bdbc:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3bdc0:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3bdc4:	ada20024 */ 	sw	$v0,0x24($t5)
/*    3bdc8:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3bdcc:	8dd80024 */ 	lw	$t8,0x24($t6)
/*    3bdd0:	add8002c */ 	sw	$t8,0x2c($t6)
/*    3bdd4:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3bdd8:	a7a00032 */ 	sh	$zero,0x32($sp)
/*    3bddc:	8de80000 */ 	lw	$t0,0x0($t7)
/*    3bde0:	11000019 */ 	beqz	$t0,.L0003be48
/*    3bde4:	00000000 */ 	nop
.L0003bde8:
/*    3bde8:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3bdec:	97a90032 */ 	lhu	$t1,0x32($sp)
/*    3bdf0:	8f2a0024 */ 	lw	$t2,0x24($t9)
/*    3bdf4:	00096040 */ 	sll	$t4,$t1,0x1
/*    3bdf8:	014c5821 */ 	addu	$t3,$t2,$t4
/*    3bdfc:	a5600000 */ 	sh	$zero,0x0($t3)
/*    3be00:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3be04:	97ae0032 */ 	lhu	$t6,0x32($sp)
/*    3be08:	8db80024 */ 	lw	$t8,0x24($t5)
/*    3be0c:	000e7840 */ 	sll	$t7,$t6,0x1
/*    3be10:	8da90020 */ 	lw	$t1,0x20($t5)
/*    3be14:	030f4021 */ 	addu	$t0,$t8,$t7
/*    3be18:	85190000 */ 	lh	$t9,0x0($t0)
/*    3be1c:	012f5021 */ 	addu	$t2,$t1,$t7
/*    3be20:	a5590000 */ 	sh	$t9,0x0($t2)
/*    3be24:	97ac0032 */ 	lhu	$t4,0x32($sp)
/*    3be28:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3be2c:	258b0001 */ 	addiu	$t3,$t4,0x1
/*    3be30:	a7ab0032 */ 	sh	$t3,0x32($sp)
/*    3be34:	8f080000 */ 	lw	$t0,0x0($t8)
/*    3be38:	316effff */ 	andi	$t6,$t3,0xffff
/*    3be3c:	01c8082b */ 	sltu	$at,$t6,$t0
/*    3be40:	1420ffe9 */ 	bnez	$at,.L0003bde8
/*    3be44:	00000000 */ 	nop
.L0003be48:
/*    3be48:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3be4c:	a7a00036 */ 	sh	$zero,0x36($sp)
/*    3be50:	91a90008 */ 	lbu	$t1,0x8($t5)
/*    3be54:	192000e9 */ 	blez	$t1,.L0003c1fc
/*    3be58:	00000000 */ 	nop
.L0003be5c:
/*    3be5c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3be60:	97aa0036 */ 	lhu	$t2,0x36($sp)
/*    3be64:	8df90004 */ 	lw	$t9,0x4($t7)
/*    3be68:	000a6080 */ 	sll	$t4,$t2,0x2
/*    3be6c:	018a6021 */ 	addu	$t4,$t4,$t2
/*    3be70:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    3be74:	032c5821 */ 	addu	$t3,$t9,$t4
/*    3be78:	afab0028 */ 	sw	$t3,0x28($sp)
/*    3be7c:	97ae0034 */ 	lhu	$t6,0x34($sp)
/*    3be80:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3be84:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3be88:	000e4080 */ 	sll	$t0,$t6,0x2
/*    3be8c:	03086821 */ 	addu	$t5,$t8,$t0
/*    3be90:	8da90000 */ 	lw	$t1,0x0($t5)
/*    3be94:	ade90000 */ 	sw	$t1,0x0($t7)
/*    3be98:	97aa0034 */ 	lhu	$t2,0x34($sp)
/*    3be9c:	25590001 */ 	addiu	$t9,$t2,0x1
/*    3bea0:	a7b90034 */ 	sh	$t9,0x34($sp)
/*    3bea4:	97ab0034 */ 	lhu	$t3,0x34($sp)
/*    3bea8:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    3beac:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3beb0:	000b7080 */ 	sll	$t6,$t3,0x2
/*    3beb4:	018ec021 */ 	addu	$t8,$t4,$t6
/*    3beb8:	8f080000 */ 	lw	$t0,0x0($t8)
/*    3bebc:	ada80004 */ 	sw	$t0,0x4($t5)
/*    3bec0:	97a90034 */ 	lhu	$t1,0x34($sp)
/*    3bec4:	252f0001 */ 	addiu	$t7,$t1,0x1
/*    3bec8:	a7af0034 */ 	sh	$t7,0x34($sp)
/*    3becc:	97b90034 */ 	lhu	$t9,0x34($sp)
/*    3bed0:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    3bed4:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3bed8:	00195880 */ 	sll	$t3,$t9,0x2
/*    3bedc:	014b6021 */ 	addu	$t4,$t2,$t3
/*    3bee0:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*    3bee4:	a70e000a */ 	sh	$t6,0xa($t8)
/*    3bee8:	97a80034 */ 	lhu	$t0,0x34($sp)
/*    3beec:	250d0001 */ 	addiu	$t5,$t0,0x1
/*    3bef0:	a7ad0034 */ 	sh	$t5,0x34($sp)
/*    3bef4:	97af0034 */ 	lhu	$t7,0x34($sp)
/*    3bef8:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3befc:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    3bf00:	000fc880 */ 	sll	$t9,$t7,0x2
/*    3bf04:	01395021 */ 	addu	$t2,$t1,$t9
/*    3bf08:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    3bf0c:	a58b0008 */ 	sh	$t3,0x8($t4)
/*    3bf10:	97ae0034 */ 	lhu	$t6,0x34($sp)
/*    3bf14:	25d80001 */ 	addiu	$t8,$t6,0x1
/*    3bf18:	a7b80034 */ 	sh	$t8,0x34($sp)
/*    3bf1c:	97ad0034 */ 	lhu	$t5,0x34($sp)
/*    3bf20:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3bf24:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3bf28:	000d7880 */ 	sll	$t7,$t5,0x2
/*    3bf2c:	010f4821 */ 	addu	$t1,$t0,$t7
/*    3bf30:	8d390000 */ 	lw	$t9,0x0($t1)
/*    3bf34:	a559000c */ 	sh	$t9,0xc($t2)
/*    3bf38:	97ab0034 */ 	lhu	$t3,0x34($sp)
/*    3bf3c:	256c0001 */ 	addiu	$t4,$t3,0x1
/*    3bf40:	a7ac0034 */ 	sh	$t4,0x34($sp)
/*    3bf44:	97b80034 */ 	lhu	$t8,0x34($sp)
/*    3bf48:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3bf4c:	00186880 */ 	sll	$t5,$t8,0x2
/*    3bf50:	01cd4021 */ 	addu	$t0,$t6,$t5
/*    3bf54:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*    3bf58:	11e0005e */ 	beqz	$t7,.L0003c0d4
/*    3bf5c:	00000000 */ 	nop
/*    3bf60:	97b90034 */ 	lhu	$t9,0x34($sp)
/*    3bf64:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3bf68:	3c01447a */ 	lui	$at,0x447a
/*    3bf6c:	00195080 */ 	sll	$t2,$t9,0x2
/*    3bf70:	012a5821 */ 	addu	$t3,$t1,$t2
/*    3bf74:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    3bf78:	44814000 */ 	mtc1	$at,$f8
/*    3bf7c:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    3bf80:	448c2000 */ 	mtc1	$t4,$f4
/*    3bf84:	3c014000 */ 	lui	$at,0x4000
/*    3bf88:	8f0e0018 */ 	lw	$t6,0x18($t8)
/*    3bf8c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3bf90:	44818000 */ 	mtc1	$at,$f16
/*    3bf94:	448e2000 */ 	mtc1	$t6,$f4
/*    3bf98:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3bf9c:	46083283 */ 	div.s	$f10,$f6,$f8
/*    3bfa0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3bfa4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    3bfa8:	46069203 */ 	div.s	$f8,$f18,$f6
/*    3bfac:	e5a80010 */ 	swc1	$f8,0x10($t5)
/*    3bfb0:	97a80034 */ 	lhu	$t0,0x34($sp)
/*    3bfb4:	250f0001 */ 	addiu	$t7,$t0,0x1
/*    3bfb8:	a7af0034 */ 	sh	$t7,0x34($sp)
/*    3bfbc:	97a90034 */ 	lhu	$t1,0x34($sp)
/*    3bfc0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3bfc4:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3bfc8:	00095080 */ 	sll	$t2,$t1,0x2
/*    3bfcc:	032a5821 */ 	addu	$t3,$t9,$t2
/*    3bfd0:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    3bfd4:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*    3bfd8:	8f0d0000 */ 	lw	$t5,0x0($t8)
/*    3bfdc:	448c5000 */ 	mtc1	$t4,$f10
/*    3bfe0:	3c017005 */ 	lui	$at,%hi(var70054ad8)
/*    3bfe4:	01cd4023 */ 	subu	$t0,$t6,$t5
/*    3bfe8:	46805420 */ 	cvt.s.w	$f16,$f10
/*    3bfec:	44883000 */ 	mtc1	$t0,$f6
/*    3bff0:	c4244ad8 */ 	lwc1	$f4,%lo(var70054ad8)($at)
/*    3bff4:	46803220 */ 	cvt.s.w	$f8,$f6
/*    3bff8:	05010005 */ 	bgez	$t0,.L0003c010
/*    3bffc:	46048483 */ 	div.s	$f18,$f16,$f4
/*    3c000:	3c014f80 */ 	lui	$at,0x4f80
/*    3c004:	44815000 */ 	mtc1	$at,$f10
/*    3c008:	00000000 */ 	nop
/*    3c00c:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0003c010:
/*    3c010:	46089402 */ 	mul.s	$f16,$f18,$f8
/*    3c014:	e710001c */ 	swc1	$f16,0x1c($t8)
/*    3c018:	97af0034 */ 	lhu	$t7,0x34($sp)
/*    3c01c:	25e90001 */ 	addiu	$t1,$t7,0x1
/*    3c020:	a7a90034 */ 	sh	$t1,0x34($sp)
/*    3c024:	3c013f80 */ 	lui	$at,0x3f80
/*    3c028:	44812000 */ 	mtc1	$at,$f4
/*    3c02c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3c030:	e7240014 */ 	swc1	$f4,0x14($t9)
/*    3c034:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3c038:	ad400018 */ 	sw	$zero,0x18($t2)
/*    3c03c:	240b0038 */ 	addiu	$t3,$zero,0x38
/*    3c040:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3c044:	00002025 */ 	or	$a0,$zero,$zero
/*    3c048:	00002825 */ 	or	$a1,$zero,$zero
/*    3c04c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3c050:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c054:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c058:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    3c05c:	ad820024 */ 	sw	$v0,0x24($t4)
/*    3c060:	240e0020 */ 	addiu	$t6,$zero,0x20
/*    3c064:	afae0010 */ 	sw	$t6,0x10($sp)
/*    3c068:	00002025 */ 	or	$a0,$zero,$zero
/*    3c06c:	00002825 */ 	or	$a1,$zero,$zero
/*    3c070:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3c074:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c078:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c07c:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3c080:	8da80024 */ 	lw	$t0,0x24($t5)
/*    3c084:	ad020014 */ 	sw	$v0,0x14($t0)
/*    3c088:	24180020 */ 	addiu	$t8,$zero,0x20
/*    3c08c:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3c090:	00002025 */ 	or	$a0,$zero,$zero
/*    3c094:	00002825 */ 	or	$a1,$zero,$zero
/*    3c098:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3c09c:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c0a0:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c0a4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3c0a8:	8de90024 */ 	lw	$t1,0x24($t7)
/*    3c0ac:	ad220018 */ 	sw	$v0,0x18($t1)
/*    3c0b0:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3c0b4:	44803000 */ 	mtc1	$zero,$f6
/*    3c0b8:	8f2a0024 */ 	lw	$t2,0x24($t9)
/*    3c0bc:	e5460024 */ 	swc1	$f6,0x24($t2)
/*    3c0c0:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    3c0c4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    3c0c8:	8d8e0024 */ 	lw	$t6,0x24($t4)
/*    3c0cc:	10000009 */ 	b	.L0003c0f4
/*    3c0d0:	adcb0028 */ 	sw	$t3,0x28($t6)
.L0003c0d4:
/*    3c0d4:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3c0d8:	ada00024 */ 	sw	$zero,0x24($t5)
/*    3c0dc:	97a80034 */ 	lhu	$t0,0x34($sp)
/*    3c0e0:	25180001 */ 	addiu	$t8,$t0,0x1
/*    3c0e4:	a7b80034 */ 	sh	$t8,0x34($sp)
/*    3c0e8:	97af0034 */ 	lhu	$t7,0x34($sp)
/*    3c0ec:	25e90001 */ 	addiu	$t1,$t7,0x1
/*    3c0f0:	a7a90034 */ 	sh	$t1,0x34($sp)
.L0003c0f4:
/*    3c0f4:	97aa0034 */ 	lhu	$t2,0x34($sp)
/*    3c0f8:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3c0fc:	000a6080 */ 	sll	$t4,$t2,0x2
/*    3c100:	032c5821 */ 	addu	$t3,$t9,$t4
/*    3c104:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*    3c108:	11c0002e */ 	beqz	$t6,.L0003c1c4
/*    3c10c:	00000000 */ 	nop
/*    3c110:	240d0038 */ 	addiu	$t5,$zero,0x38
/*    3c114:	afad0010 */ 	sw	$t5,0x10($sp)
/*    3c118:	00002025 */ 	or	$a0,$zero,$zero
/*    3c11c:	00002825 */ 	or	$a1,$zero,$zero
/*    3c120:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3c124:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c128:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c12c:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    3c130:	ad020020 */ 	sw	$v0,0x20($t0)
/*    3c134:	24180008 */ 	addiu	$t8,$zero,0x8
/*    3c138:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3c13c:	00002025 */ 	or	$a0,$zero,$zero
/*    3c140:	00002825 */ 	or	$a1,$zero,$zero
/*    3c144:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3c148:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c14c:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c150:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3c154:	8de90020 */ 	lw	$t1,0x20($t7)
/*    3c158:	ad22002c */ 	sw	$v0,0x2c($t1)
/*    3c15c:	240a0008 */ 	addiu	$t2,$zero,0x8
/*    3c160:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    3c164:	00002025 */ 	or	$a0,$zero,$zero
/*    3c168:	00002825 */ 	or	$a1,$zero,$zero
/*    3c16c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3c170:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c174:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c178:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3c17c:	8f2c0020 */ 	lw	$t4,0x20($t9)
/*    3c180:	ad820030 */ 	sw	$v0,0x30($t4)
/*    3c184:	97ae0034 */ 	lhu	$t6,0x34($sp)
/*    3c188:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3c18c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3c190:	000e6880 */ 	sll	$t5,$t6,0x2
/*    3c194:	016d4021 */ 	addu	$t0,$t3,$t5
/*    3c198:	8d180000 */ 	lw	$t8,0x0($t0)
/*    3c19c:	8de90020 */ 	lw	$t1,0x20($t7)
/*    3c1a0:	a5380000 */ 	sh	$t8,0x0($t1)
/*    3c1a4:	97aa0034 */ 	lhu	$t2,0x34($sp)
/*    3c1a8:	25590001 */ 	addiu	$t9,$t2,0x1
/*    3c1ac:	a7b90034 */ 	sh	$t9,0x34($sp)
/*    3c1b0:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    3c1b4:	0c00ee21 */ 	jal	func0003b884
/*    3c1b8:	8d840020 */ 	lw	$a0,0x20($t4)
/*    3c1bc:	10000006 */ 	b	.L0003c1d8
/*    3c1c0:	00000000 */ 	nop
.L0003c1c4:
/*    3c1c4:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3c1c8:	adc00020 */ 	sw	$zero,0x20($t6)
/*    3c1cc:	97ab0034 */ 	lhu	$t3,0x34($sp)
/*    3c1d0:	256d0001 */ 	addiu	$t5,$t3,0x1
/*    3c1d4:	a7ad0034 */ 	sh	$t5,0x34($sp)
.L0003c1d8:
/*    3c1d8:	97a80036 */ 	lhu	$t0,0x36($sp)
/*    3c1dc:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3c1e0:	250f0001 */ 	addiu	$t7,$t0,0x1
/*    3c1e4:	a7af0036 */ 	sh	$t7,0x36($sp)
/*    3c1e8:	912a0008 */ 	lbu	$t2,0x8($t1)
/*    3c1ec:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    3c1f0:	030a082a */ 	slt	$at,$t8,$t2
/*    3c1f4:	1420ff19 */ 	bnez	$at,.L0003be5c
/*    3c1f8:	00000000 */ 	nop
.L0003c1fc:
/*    3c1fc:	10000001 */ 	b	.L0003c204
/*    3c200:	00000000 */ 	nop
.L0003c204:
/*    3c204:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3c208:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    3c20c:	03e00008 */ 	jr	$ra
/*    3c210:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c214
/*    3c214:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c218:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3c21c:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c220:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3c224:	afa60028 */ 	sw	$a2,0x28($sp)
/*    3c228:	240e0020 */ 	addiu	$t6,$zero,0x20
/*    3c22c:	afae0010 */ 	sw	$t6,0x10($sp)
/*    3c230:	00002025 */ 	or	$a0,$zero,$zero
/*    3c234:	00002825 */ 	or	$a1,$zero,$zero
/*    3c238:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    3c23c:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c240:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c244:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3c248:	ade2000c */ 	sw	$v0,0xc($t7)
/*    3c24c:	24180020 */ 	addiu	$t8,$zero,0x20
/*    3c250:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3c254:	00002025 */ 	or	$a0,$zero,$zero
/*    3c258:	00002825 */ 	or	$a1,$zero,$zero
/*    3c25c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    3c260:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c264:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c268:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3c26c:	af220010 */ 	sw	$v0,0x10($t9)
/*    3c270:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3c274:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    3c278:	0320f809 */ 	jalr	$t9
/*    3c27c:	2484002c */ 	addiu	$a0,$a0,0x2c
/*    3c280:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3c284:	ad020028 */ 	sw	$v0,0x28($t0)
/*    3c288:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c28c:	ad200034 */ 	sw	$zero,0x34($t1)
/*    3c290:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3c294:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    3c298:	ad6a0038 */ 	sw	$t2,0x38($t3)
/*    3c29c:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3c2a0:	ad80003c */ 	sw	$zero,0x3c($t4)
/*    3c2a4:	240d0020 */ 	addiu	$t5,$zero,0x20
/*    3c2a8:	afad0010 */ 	sw	$t5,0x10($sp)
/*    3c2ac:	00002025 */ 	or	$a0,$zero,$zero
/*    3c2b0:	00002825 */ 	or	$a1,$zero,$zero
/*    3c2b4:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    3c2b8:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c2bc:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c2c0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3c2c4:	adc20040 */ 	sw	$v0,0x40($t6)
/*    3c2c8:	44802000 */ 	mtc1	$zero,$f4
/*    3c2cc:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3c2d0:	e5e4004c */ 	swc1	$f4,0x4c($t7)
/*    3c2d4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3c2d8:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3c2dc:	af380050 */ 	sw	$t8,0x50($t9)
/*    3c2e0:	3c013f80 */ 	lui	$at,0x3f80
/*    3c2e4:	44813000 */ 	mtc1	$at,$f6
/*    3c2e8:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3c2ec:	e5060044 */ 	swc1	$f6,0x44($t0)
/*    3c2f0:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c2f4:	ad200048 */ 	sw	$zero,0x48($t1)
/*    3c2f8:	240a0050 */ 	addiu	$t2,$zero,0x50
/*    3c2fc:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    3c300:	00002025 */ 	or	$a0,$zero,$zero
/*    3c304:	00002825 */ 	or	$a1,$zero,$zero
/*    3c308:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    3c30c:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c310:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c314:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3c318:	ad620054 */ 	sw	$v0,0x54($t3)
/*    3c31c:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3c320:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    3c324:	adac0078 */ 	sw	$t4,0x78($t5)
/*    3c328:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3c32c:	adc00084 */ 	sw	$zero,0x84($t6)
/*    3c330:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c334:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    3c338:	a70f005a */ 	sh	$t7,0x5a($t8)
/*    3c33c:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3c340:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3c344:	a5190068 */ 	sh	$t9,0x68($t0)
/*    3c348:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c34c:	24090001 */ 	addiu	$t1,$zero,0x1
/*    3c350:	a549006e */ 	sh	$t1,0x6e($t2)
/*    3c354:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3c358:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    3c35c:	a58b005c */ 	sh	$t3,0x5c($t4)
/*    3c360:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3c364:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    3c368:	a5cd005e */ 	sh	$t5,0x5e($t6)
/*    3c36c:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3c370:	a5e00060 */ 	sh	$zero,0x60($t7)
/*    3c374:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c378:	a7000062 */ 	sh	$zero,0x62($t8)
/*    3c37c:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3c380:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3c384:	a5190066 */ 	sh	$t9,0x66($t0)
/*    3c388:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c38c:	a5200064 */ 	sh	$zero,0x64($t1)
/*    3c390:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3c394:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    3c398:	a56a0066 */ 	sh	$t2,0x66($t3)
/*    3c39c:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3c3a0:	a5800064 */ 	sh	$zero,0x64($t4)
/*    3c3a4:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3c3a8:	ada00070 */ 	sw	$zero,0x70($t5)
/*    3c3ac:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3c3b0:	adc00074 */ 	sw	$zero,0x74($t6)
/*    3c3b4:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3c3b8:	a5e00058 */ 	sh	$zero,0x58($t7)
/*    3c3bc:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c3c0:	af00007c */ 	sw	$zero,0x7c($t8)
/*    3c3c4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3c3c8:	af200080 */ 	sw	$zero,0x80($t9)
/*    3c3cc:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3c3d0:	a100008c */ 	sb	$zero,0x8c($t0)
/*    3c3d4:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c3d8:	a5200092 */ 	sh	$zero,0x92($t1)
/*    3c3dc:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c3e0:	a5400090 */ 	sh	$zero,0x90($t2)
/*    3c3e4:	240b0008 */ 	addiu	$t3,$zero,0x8
/*    3c3e8:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3c3ec:	00002025 */ 	or	$a0,$zero,$zero
/*    3c3f0:	00002825 */ 	or	$a1,$zero,$zero
/*    3c3f4:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    3c3f8:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    3c3fc:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3c400:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3c404:	ad8200bc */ 	sw	$v0,0xbc($t4)
/*    3c408:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3c40c:	ada000b8 */ 	sw	$zero,0xb8($t5)
/*    3c410:	10000001 */ 	b	.L0003c418
/*    3c414:	00000000 */ 	nop
.L0003c418:
/*    3c418:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3c41c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c420:	03e00008 */ 	jr	$ra
/*    3c424:	00000000 */ 	nop
);
