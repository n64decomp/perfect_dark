#include <ultra64.h>
#include <n_libaudio.h>
#include "synthInternals.h"
#include "naudio/n_synthInternals.h"
#include "constants.h"
#include "game/atan2f.h"
#include "bss.h"
#include "lib/lib_3a100.h"
#include "lib/lib_446d0.h"
#include "data.h"
#include "types.h"

#define RANGE 2.0f

Acmd *_n_loadBuffer(ALFx *r, s32 arg1, s16 *curr_ptr, s32 buff,s32 count, Acmd *p);
Acmd *_n_saveBuffer(ALFx *r, s32 arg1, s16 *curr_ptr, s32 buff, Acmd *p);
Acmd *_n_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p);

GLOBAL_ASM(
glabel n_alAuxBusPull
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
/*    3a11c:	3c0f8006 */ 	lui	$t7,%hi(n_syn)
/*    3a120:	8deff114 */ 	lw	$t7,%lo(n_syn)($t7)
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
/*    3a188:	3c19800a */ 	lui	$t9,%hi(var8009c340+0x4)
/*    3a18c:	032fc821 */ 	addu	$t9,$t9,$t7
/*    3a190:	9339c344 */ 	lbu	$t9,%lo(var8009c340+0x4)($t9)
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
/*    3a224:	0c00ecdc */ 	jal	_n_saveBuffer
/*    3a228:	afae0010 */ 	sw	$t6,0x10($sp)
/*    3a22c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    3a230:	8faf0088 */ 	lw	$t7,0x88($sp)
/*    3a234:	3c19800a */ 	lui	$t9,%hi(var8009c340+0x4)
/*    3a238:	032fc821 */ 	addu	$t9,$t9,$t7
/*    3a23c:	9339c344 */ 	lbu	$t9,%lo(var8009c340+0x4)($t9)
/*    3a240:	1320000a */ 	beqz	$t9,.L0003a26c
/*    3a244:	00000000 */ 	nop
/*    3a248:	8fb80078 */ 	lw	$t8,0x78($sp)
/*    3a24c:	8fa8007c */ 	lw	$t0,0x7c($sp)
/*    3a250:	24050001 */ 	addiu	$a1,$zero,0x1
/*    3a254:	8f06002c */ 	lw	$a2,0x2c($t8)
/*    3a258:	24070930 */ 	addiu	$a3,$zero,0x930
/*    3a25c:	03002025 */ 	or	$a0,$t8,$zero
/*    3a260:	0c00ecdc */ 	jal	_n_saveBuffer
/*    3a264:	afa80010 */ 	sw	$t0,0x10($sp)
/*    3a268:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a26c:
/*    3a26c:	8fa90088 */ 	lw	$t1,0x88($sp)
/*    3a270:	3c0a800a */ 	lui	$t2,%hi(var8009c340+0x4)
/*    3a274:	afa00054 */ 	sw	$zero,0x54($sp)
/*    3a278:	01495021 */ 	addu	$t2,$t2,$t1
/*    3a27c:	914ac344 */ 	lbu	$t2,%lo(var8009c340+0x4)($t2)
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
/*    3a34c:	3c18800a */ 	lui	$t8,%hi(var8009c340+0x6)
/*    3a350:	0319c021 */ 	addu	$t8,$t8,$t9
/*    3a354:	9318c346 */ 	lbu	$t8,%lo(var8009c340+0x6)($t8)
/*    3a358:	1300000e */ 	beqz	$t8,.L0003a394
/*    3a35c:	00000000 */ 	nop
/*    3a360:	3c08800a */ 	lui	$t0,%hi(var8009c340+0x4)
/*    3a364:	01194021 */ 	addu	$t0,$t0,$t9
/*    3a368:	9108c344 */ 	lbu	$t0,%lo(var8009c340+0x4)($t0)
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
/*    3a3e0:	0c00ec5e */ 	jal	_n_loadBuffer
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
/*    3a498:	0c00ecdc */ 	jal	_n_saveBuffer
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
/*    3a514:	0c00ecdc */ 	jal	_n_saveBuffer
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
/*    3a540:	0c00ed53 */ 	jal	_n_filterBuffer
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
/*    3a570:	0c00ecdc */ 	jal	_n_saveBuffer
/*    3a574:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    3a578:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0003a57c:
/*    3a57c:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    3a580:	8719000c */ 	lh	$t9,0xc($t8)
/*    3a584:	13200062 */ 	beqz	$t9,.L0003a710
/*    3a588:	00000000 */ 	nop
/*    3a58c:	8fa80088 */ 	lw	$t0,0x88($sp)
/*    3a590:	3c0c800a */ 	lui	$t4,%hi(var8009c340+0x4)
/*    3a594:	01886021 */ 	addu	$t4,$t4,$t0
/*    3a598:	918cc344 */ 	lbu	$t4,%lo(var8009c340+0x4)($t4)
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
/*    3a764:	3c19800a */ 	lui	$t9,%hi(var8009c340+0x4)
/*    3a768:	0328c821 */ 	addu	$t9,$t9,$t0
/*    3a76c:	9339c344 */ 	lbu	$t9,%lo(var8009c340+0x4)($t9)
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
/*    3a7a4:	0c00ec5e */ 	jal	_n_loadBuffer
/*    3a7a8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    3a7ac:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    3a7b0:	8fae0088 */ 	lw	$t6,0x88($sp)
/*    3a7b4:	3c18800a */ 	lui	$t8,%hi(var8009c340+0x6)
/*    3a7b8:	030ec021 */ 	addu	$t8,$t8,$t6
/*    3a7bc:	9318c346 */ 	lbu	$t8,%lo(var8009c340+0x6)($t8)
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
/*    3a8fc:	3c0c800a */ 	lui	$t4,%hi(var8009c340+0x4)
/*    3a900:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3a904:	01996021 */ 	addu	$t4,$t4,$t9
/*    3a908:	918cc344 */ 	lbu	$t4,%lo(var8009c340+0x4)($t4)
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

/*
 * This routine gets called by alSynSetFXParam. No checking takes place to
 * verify the validity of the paramID or the param value. input and output
 * values must be 8 byte aligned, so round down any param passed.
 */
s32 n_alFxParamHdl(void *filter, s32 paramID, void *param)
{
	ALFx *f = (ALFx *) filter;
	s32 p = paramID & 7;
	s32 s = paramID >> 3;
	s32 val = *(s32*)param;
	f32 rsgain;

	if (s >= f->section_count) {
		return 0;
	}

#define INPUT_PARAM         0
#define OUTPUT_PARAM        1
#define FBCOEF_PARAM        2
#define FFCOEF_PARAM        3
#define GAIN_PARAM          4
#define CHORUSRATE_PARAM    5
#define CHORUSDEPTH_PARAM   6
#define LPFILT_PARAM        7

	switch (p) {
	case INPUT_PARAM:
		f->delay[s].input = ((s32)val * n_syn->outputRate / 1000) & 0xfffffff8;
		break;
	case OUTPUT_PARAM:
		f->delay[s].output = ((s32)val * n_syn->outputRate / 1000) & 0xfffffff8;
		break;
	case FBCOEF_PARAM:
		f->delay[s].fbcoef = (s16)val;
		break;
	case FFCOEF_PARAM:
		f->delay[s].ffcoef = (s16)val;
		break;
	case GAIN_PARAM:
		f->delay[s].gain = (s16)val;
		break;
	case CHORUSRATE_PARAM:
		f->delay[s].rsinc = ((((f32)val)/1000) * RANGE)/n_syn->outputRate;
		break;
	case CHORUSDEPTH_PARAM:
		rsgain = val;
		break;
	case LPFILT_PARAM:
		if (f->delay[s].lp) {
			f->delay[s].lp->fc = (s16)val;
			_init_lpfilter(f->delay[s].lp);
		}
		break;
	}

	if (f->delay[s].input >= f->length - 16) {
		f->delay[s].input = f->length - 16;
	}

	if (f->delay[s].input >= f->length - 8) {
		f->delay[s].input = f->length - 8;
	}

	if (f->delay[s].input >= f->delay[s].output) {
		f->delay[s].output = f->delay[s].input + 8;
	}

	/**
	 * the following constant is derived from:
	 *
	 *      ratio = 2^(cents/1200)
	 *
	 * and therefore for hundredths of a cent
	 *                     x
	 *      ln(ratio) = ---------------
	 *              (120,000)/ln(2)
	 * where
	 *      120,000/ln(2) = 173123.40...
	 */
#define CONVERT 173123.404906676f
#define LENGTH  (f->delay[s].output - f->delay[s].input)

	if (f->delay[s].rs) {
		if (p != 6) {
			if (LENGTH != 0) {
				rsgain = (f32)f->delay[s].rsgain / (f->delay[s].output - f->delay[s].input) * CONVERT;
			} else {
				rsgain = 0;
			}
		}

		f->delay[s].rsgain = (f->delay[s].output - f->delay[s].input) * (rsgain / CONVERT);
	}

	return 0;
}

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
/*    3aebc:	0c00ed93 */ 	jal	_doModFunc
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
/*    3b004:	0c00ec5e */ 	jal	_n_loadBuffer
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
/*    3b14c:	0c00ec5e */ 	jal	_n_loadBuffer
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

Acmd *_n_loadBuffer(ALFx *r, s32 arg1, s16 *curr_ptr, s32 buff,s32 count, Acmd *p)
{
	Acmd *ptr = p;
	s32 after_end, before_end;
	s16 *updated_ptr, *delay_end;

	delay_end = &r->base[arg1][r->length];

	if (curr_ptr < r->base[arg1]) {
		curr_ptr += r->length;
	}

	updated_ptr = curr_ptr + count;

	if (updated_ptr > delay_end) {
		after_end = updated_ptr - delay_end;
		before_end = delay_end - curr_ptr;

		n_aLoadBuffer(ptr++, before_end << 1, buff, osVirtualToPhysical(curr_ptr));
		n_aLoadBuffer(ptr++, after_end << 1, buff + (before_end << 1), osVirtualToPhysical(r->base[arg1]));
	} else {
		n_aLoadBuffer(ptr++, count << 1, buff, osVirtualToPhysical(curr_ptr));
	}

	return ptr;
}

Acmd *_n_saveBuffer(ALFx *r, s32 arg1, s16 *curr_ptr, s32 buff, Acmd *p)
{
	Acmd *ptr = p;
	s32 after_end, before_end;
	s16 *updated_ptr, *delay_end;

	delay_end = &r->base[arg1][r->length];

	if (curr_ptr < r->base[arg1]) {    /* probably just security */
		curr_ptr += r->length;         /* shouldn't occur */
	}

	updated_ptr = curr_ptr + FIXED_SAMPLE;

	if (updated_ptr > delay_end) { /* if the data wraps past end of r->base */
		after_end = updated_ptr - delay_end;
		before_end = delay_end - curr_ptr;

		n_aSaveBuffer(ptr++, before_end << 1, buff, osVirtualToPhysical(curr_ptr));
		n_aSaveBuffer(ptr++, after_end << 1, buff + (before_end << 1), osVirtualToPhysical(r->base[arg1]));
	} else {
		n_aSaveBuffer(ptr++, FIXED_SAMPLE << 1, buff, osVirtualToPhysical(curr_ptr));
	}

	return ptr;
}

Acmd *_n_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p)
{
	Acmd *ptr = p;
	s16 tmp = count >> 8;

	n_aLoadADPCM(ptr++, 32, osVirtualToPhysical(lp->fcvec.fccoef));
	n_aPoleFilter(ptr++, lp->first, lp->fgain, tmp, osVirtualToPhysical(lp->fstate[buff]));
	lp->first = 0;

	return ptr;
}

/**
 * Generate a triangle wave from -1 to 1, and find the current position
 * in the wave. (Rate of the wave is controlled by d->rsinc, which is chorus
 * rate) Multiply the current triangle wave value by d->rsgain, (chorus depth)
 * which is expressed in number of samples back from output pointer the chorus
 * should go at it's full chorus. In otherwords, this function returns a number
 * of samples the output pointer should modulate backwards.
 */
f32 _doModFunc(ALDelay *d, s32 count)
{
	f32 val;

	/*
	 * generate bipolar sawtooth
	 * from -RANGE to +RANGE
	 */
	d->rsval += d->rsinc * count;
	d->rsval = (d->rsval > RANGE) ? d->rsval - (RANGE * 2) : d->rsval;

	/*
	 * convert to monopolar triangle
	 * from 0 to RANGE
	 */
	val = d->rsval;
	val = (val < 0) ? -val : val;

	/*
	 * convert to bipolar triangle
	 * from -1 to 1
	 */
	val -= RANGE/2;

	return d->rsgain * val;
}
