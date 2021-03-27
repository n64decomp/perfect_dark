#include <ultra64.h>
#include "PR/seqp.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3ccf0.h"
#include "lib/lib_3d280.h"
#include "lib/lib_44bc0.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003d280
/*    3d280:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3d284:	afa00004 */ 	sw	$zero,0x4($sp)
/*    3d288:	8c8e0064 */ 	lw	$t6,0x64($a0)
/*    3d28c:	afae0000 */ 	sw	$t6,0x0($sp)
/*    3d290:	8faf0000 */ 	lw	$t7,0x0($sp)
/*    3d294:	11e00026 */ 	beqz	$t7,.L0003d330
/*    3d298:	00000000 */ 	nop
.L0003d29c:
/*    3d29c:	8fb80000 */ 	lw	$t8,0x0($sp)
/*    3d2a0:	27190004 */ 	addiu	$t9,$t8,0x4
/*    3d2a4:	1725001c */ 	bne	$t9,$a1,.L0003d318
/*    3d2a8:	00000000 */ 	nop
/*    3d2ac:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    3d2b0:	11000006 */ 	beqz	$t0,.L0003d2cc
/*    3d2b4:	00000000 */ 	nop
/*    3d2b8:	8fa90000 */ 	lw	$t1,0x0($sp)
/*    3d2bc:	8fab0004 */ 	lw	$t3,0x4($sp)
/*    3d2c0:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    3d2c4:	10000004 */ 	b	.L0003d2d8
/*    3d2c8:	ad6a0000 */ 	sw	$t2,0x0($t3)
.L0003d2cc:
/*    3d2cc:	8fac0000 */ 	lw	$t4,0x0($sp)
/*    3d2d0:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    3d2d4:	ac8d0064 */ 	sw	$t5,0x64($a0)
.L0003d2d8:
/*    3d2d8:	8c8e0068 */ 	lw	$t6,0x68($a0)
/*    3d2dc:	8faf0000 */ 	lw	$t7,0x0($sp)
/*    3d2e0:	15cf0003 */ 	bne	$t6,$t7,.L0003d2f0
/*    3d2e4:	00000000 */ 	nop
/*    3d2e8:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3d2ec:	ac980068 */ 	sw	$t8,0x68($a0)
.L0003d2f0:
/*    3d2f0:	8c99006c */ 	lw	$t9,0x6c($a0)
/*    3d2f4:	8fa80000 */ 	lw	$t0,0x0($sp)
/*    3d2f8:	ad190000 */ 	sw	$t9,0x0($t0)
/*    3d2fc:	8fa90000 */ 	lw	$t1,0x0($sp)
/*    3d300:	ac89006c */ 	sw	$t1,0x6c($a0)
/*    3d304:	908a0089 */ 	lbu	$t2,0x89($a0)
/*    3d308:	254bffff */ 	addiu	$t3,$t2,-1
/*    3d30c:	a08b0089 */ 	sb	$t3,0x89($a0)
/*    3d310:	10000009 */ 	b	.L0003d338
/*    3d314:	00000000 */ 	nop
.L0003d318:
/*    3d318:	8fac0000 */ 	lw	$t4,0x0($sp)
/*    3d31c:	afac0004 */ 	sw	$t4,0x4($sp)
/*    3d320:	8fad0000 */ 	lw	$t5,0x0($sp)
/*    3d324:	8dae0000 */ 	lw	$t6,0x0($t5)
/*    3d328:	15c0ffdc */ 	bnez	$t6,.L0003d29c
/*    3d32c:	afae0000 */ 	sw	$t6,0x0($sp)
.L0003d330:
/*    3d330:	10000001 */ 	b	.L0003d338
/*    3d334:	00000000 */ 	nop
.L0003d338:
/*    3d338:	03e00008 */ 	jr	$ra
/*    3d33c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0003d340
/*    3cc40:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    3cc44:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3cc48:	afa40040 */ 	sw	$a0,0x40($sp)
/*    3cc4c:	afa50044 */ 	sw	$a1,0x44($sp)
/*    3cc50:	afa60048 */ 	sw	$a2,0x48($sp)
/*    3cc54:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    3cc58:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*    3cc5c:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    3cc60:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3cc64:	93190034 */ 	lbu	$t9,0x34($t8)
/*    3cc68:	1720002c */ 	bnez	$t9,.PF0003cd1c
/*    3cc6c:	00000000 */ 	nop
/*    3cc70:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    3cc74:	8d090050 */ 	lw	$t1,0x50($t0)
/*    3cc78:	afa90028 */ 	sw	$t1,0x28($sp)
/*    3cc7c:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3cc80:	11400026 */ 	beqz	$t2,.PF0003cd1c
/*    3cc84:	00000000 */ 	nop
.PF0003cc88:
/*    3cc88:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3cc8c:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    3cc90:	afac0024 */ 	sw	$t4,0x24($sp)
/*    3cc94:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3cc98:	afad0020 */ 	sw	$t5,0x20($sp)
/*    3cc9c:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3cca0:	afae001c */ 	sw	$t6,0x1c($sp)
/*    3cca4:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cca8:	24010006 */ 	li	$at,0x6
/*    3ccac:	85f8000c */ 	lh	$t8,0xc($t7)
/*    3ccb0:	17010015 */ 	bne	$t8,$at,.PF0003cd08
/*    3ccb4:	00000000 */ 	nop
/*    3ccb8:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3ccbc:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    3ccc0:	8f280010 */ 	lw	$t0,0x10($t9)
/*    3ccc4:	15090010 */ 	bne	$t0,$t1,.PF0003cd08
/*    3ccc8:	00000000 */ 	nop
/*    3cccc:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    3ccd0:	11400007 */ 	beqz	$t2,.PF0003ccf0
/*    3ccd4:	00000000 */ 	nop
/*    3ccd8:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    3ccdc:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3cce0:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*    3cce4:	8dae0008 */ 	lw	$t6,0x8($t5)
/*    3cce8:	018e7821 */ 	addu	$t7,$t4,$t6
/*    3ccec:	ad6f0008 */ 	sw	$t7,0x8($t3)
.PF0003ccf0:
/*    3ccf0:	0c00c429 */ 	jal	alUnlink
/*    3ccf4:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    3ccf8:	8fa50040 */ 	lw	$a1,0x40($sp)
/*    3ccfc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    3cd00:	0c00c41c */ 	jal	alLink
/*    3cd04:	24a50048 */ 	addiu	$a1,$a1,0x48
.PF0003cd08:
/*    3cd08:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3cd0c:	afb80028 */ 	sw	$t8,0x28($sp)
/*    3cd10:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3cd14:	1720ffdc */ 	bnez	$t9,.PF0003cc88
/*    3cd18:	00000000 */ 	nop
.PF0003cd1c:
/*    3cd1c:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3cd20:	a1000033 */ 	sb	$zero,0x33($t0)
/*    3cd24:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    3cd28:	24090003 */ 	li	$t1,0x3
/*    3cd2c:	a1490034 */ 	sb	$t1,0x34($t2)
/*    3cd30:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3cd34:	a1a00030 */ 	sb	$zero,0x30($t5)
/*    3cd38:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3cd3c:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    3cd40:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3cd44:	8d8e001c */ 	lw	$t6,0x1c($t4)
/*    3cd48:	01cf5821 */ 	addu	$t3,$t6,$t7
/*    3cd4c:	af0b0024 */ 	sw	$t3,0x24($t8)
/*    3cd50:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    3cd54:	0c011210 */ 	jal	func00044f40
/*    3cd58:	00002825 */ 	move	$a1,$zero
/*    3cd5c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    3cd60:	00002825 */ 	move	$a1,$zero
/*    3cd64:	0c00f17c */ 	jal	func0003ccf0
/*    3cd68:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    3cd6c:	24190005 */ 	li	$t9,0x5
/*    3cd70:	a7b90030 */ 	sh	$t9,0x30($sp)
/*    3cd74:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    3cd78:	afa80034 */ 	sw	$t0,0x34($sp)
/*    3cd7c:	8fa90048 */ 	lw	$t1,0x48($sp)
/*    3cd80:	34019c40 */ 	li	$at,0x9c40
/*    3cd84:	01215021 */ 	addu	$t2,$t1,$at
/*    3cd88:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    3cd8c:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    3cd90:	27a50030 */ 	addiu	$a1,$sp,0x30
/*    3cd94:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    3cd98:	00003825 */ 	move	$a3,$zero
/*    3cd9c:	0c00efc4 */ 	jal	alEvtqPostEvent
/*    3cda0:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3cda4:	10000001 */ 	b	.PF0003cdac
/*    3cda8:	00000000 */ 	nop
.PF0003cdac:
/*    3cdac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3cdb0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    3cdb4:	03e00008 */ 	jr	$ra
/*    3cdb8:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0003d340
/*    3d340:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    3d344:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3d348:	afa40040 */ 	sw	$a0,0x40($sp)
/*    3d34c:	afa50044 */ 	sw	$a1,0x44($sp)
/*    3d350:	afa60048 */ 	sw	$a2,0x48($sp)
/*    3d354:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    3d358:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*    3d35c:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    3d360:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3d364:	93190034 */ 	lbu	$t9,0x34($t8)
/*    3d368:	1720002c */ 	bnez	$t9,.L0003d41c
/*    3d36c:	00000000 */ 	nop
/*    3d370:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    3d374:	8d090050 */ 	lw	$t1,0x50($t0)
/*    3d378:	afa90028 */ 	sw	$t1,0x28($sp)
/*    3d37c:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3d380:	11400026 */ 	beqz	$t2,.L0003d41c
/*    3d384:	00000000 */ 	nop
.L0003d388:
/*    3d388:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3d38c:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    3d390:	afac0024 */ 	sw	$t4,0x24($sp)
/*    3d394:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3d398:	afad0020 */ 	sw	$t5,0x20($sp)
/*    3d39c:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3d3a0:	afae001c */ 	sw	$t6,0x1c($sp)
/*    3d3a4:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3d3a8:	24010006 */ 	addiu	$at,$zero,0x6
/*    3d3ac:	85f8000c */ 	lh	$t8,0xc($t7)
/*    3d3b0:	17010015 */ 	bne	$t8,$at,.L0003d408
/*    3d3b4:	00000000 */ 	nop
/*    3d3b8:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3d3bc:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    3d3c0:	8f280010 */ 	lw	$t0,0x10($t9)
/*    3d3c4:	15090010 */ 	bne	$t0,$t1,.L0003d408
/*    3d3c8:	00000000 */ 	nop
/*    3d3cc:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    3d3d0:	11400007 */ 	beqz	$t2,.L0003d3f0
/*    3d3d4:	00000000 */ 	nop
/*    3d3d8:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    3d3dc:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3d3e0:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*    3d3e4:	8dae0008 */ 	lw	$t6,0x8($t5)
/*    3d3e8:	018e7821 */ 	addu	$t7,$t4,$t6
/*    3d3ec:	ad6f0008 */ 	sw	$t7,0x8($t3)
.L0003d3f0:
/*    3d3f0:	0c00c5e9 */ 	jal	alUnlink
/*    3d3f4:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    3d3f8:	8fa50040 */ 	lw	$a1,0x40($sp)
/*    3d3fc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    3d400:	0c00c5dc */ 	jal	alLink
/*    3d404:	24a50048 */ 	addiu	$a1,$a1,0x48
.L0003d408:
/*    3d408:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3d40c:	afb80028 */ 	sw	$t8,0x28($sp)
/*    3d410:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3d414:	1720ffdc */ 	bnez	$t9,.L0003d388
/*    3d418:	00000000 */ 	nop
.L0003d41c:
/*    3d41c:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3d420:	a1000033 */ 	sb	$zero,0x33($t0)
/*    3d424:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    3d428:	24090003 */ 	addiu	$t1,$zero,0x3
/*    3d42c:	a1490034 */ 	sb	$t1,0x34($t2)
/*    3d430:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3d434:	a1a00030 */ 	sb	$zero,0x30($t5)
/*    3d438:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3d43c:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    3d440:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3d444:	8d8e001c */ 	lw	$t6,0x1c($t4)
/*    3d448:	01cf5821 */ 	addu	$t3,$t6,$t7
/*    3d44c:	af0b0024 */ 	sw	$t3,0x24($t8)
/*    3d450:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    3d454:	0c0113d0 */ 	jal	func00044f40
/*    3d458:	00002825 */ 	or	$a1,$zero,$zero
/*    3d45c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    3d460:	00002825 */ 	or	$a1,$zero,$zero
/*    3d464:	0c00f33c */ 	jal	func0003ccf0
/*    3d468:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    3d46c:	24190005 */ 	addiu	$t9,$zero,0x5
/*    3d470:	a7b90030 */ 	sh	$t9,0x30($sp)
/*    3d474:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    3d478:	afa80034 */ 	sw	$t0,0x34($sp)
/*    3d47c:	8fa90048 */ 	lw	$t1,0x48($sp)
/*    3d480:	252a7d00 */ 	addiu	$t2,$t1,0x7d00
/*    3d484:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    3d488:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    3d48c:	27a50030 */ 	addiu	$a1,$sp,0x30
/*    3d490:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    3d494:	00003825 */ 	or	$a3,$zero,$zero
/*    3d498:	0c00f184 */ 	jal	alEvtqPostEvent
/*    3d49c:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3d4a0:	10000001 */ 	b	.L0003d4a8
/*    3d4a4:	00000000 */ 	nop
.L0003d4a8:
/*    3d4a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3d4ac:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    3d4b0:	03e00008 */ 	jr	$ra
/*    3d4b4:	00000000 */ 	nop
);
#endif

char __voiceNeedsNoteKill(ALSeqPlayer *seqp, ALVoice *voice, ALMicroTime killTime)
{
	ALLink *thisNode;
	ALLink *nextNode;
	ALEventListItem *thisItem;
	ALMicroTime itemTime = 0;
	char needsNoteKill = TRUE;

	thisNode = seqp->evtq.allocList.next;

	while (thisNode != 0) {
		nextNode = thisNode->next;
		thisItem = (ALEventListItem *)thisNode;
		itemTime += thisItem->delta;

		if (thisItem->evt.type == AL_NOTE_END_EVT) {
			if (thisItem->evt.msg.note.voice == voice) {
				if (itemTime > killTime) {
					if ((ALEventListItem *)nextNode) {
						((ALEventListItem *)nextNode)->delta += thisItem->delta;
					}

					alUnlink(thisNode);
					alLink(thisNode, &seqp->evtq.freeList);
				} else {
					needsNoteKill = FALSE;
				}

				break;
			}
		}

		thisNode = nextNode;
	}

	return needsNoteKill;
}

GLOBAL_ASM(
glabel func0003d5d8
/*    3d5d8:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3d5dc:	30a500ff */ 	andi	$a1,$a1,0xff
/*    3d5e0:	30c600ff */ 	andi	$a2,$a2,0xff
/*    3d5e4:	30e700ff */ 	andi	$a3,$a3,0xff
/*    3d5e8:	8c8e006c */ 	lw	$t6,0x6c($a0)
/*    3d5ec:	afae0004 */ 	sw	$t6,0x4($sp)
/*    3d5f0:	908f0089 */ 	lbu	$t7,0x89($a0)
/*    3d5f4:	90980088 */ 	lbu	$t8,0x88($a0)
/*    3d5f8:	030f082a */ 	slt	$at,$t8,$t7
/*    3d5fc:	10200003 */ 	beqz	$at,.L0003d60c
/*    3d600:	00000000 */ 	nop
/*    3d604:	10000023 */ 	b	.L0003d694
/*    3d608:	00001025 */ 	or	$v0,$zero,$zero
.L0003d60c:
/*    3d60c:	8fb90004 */ 	lw	$t9,0x4($sp)
/*    3d610:	1320001c */ 	beqz	$t9,.L0003d684
/*    3d614:	00000000 */ 	nop
/*    3d618:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    3d61c:	8d090000 */ 	lw	$t1,0x0($t0)
/*    3d620:	ac89006c */ 	sw	$t1,0x6c($a0)
/*    3d624:	8faa0004 */ 	lw	$t2,0x4($sp)
/*    3d628:	ad400000 */ 	sw	$zero,0x0($t2)
/*    3d62c:	8c8b0064 */ 	lw	$t3,0x64($a0)
/*    3d630:	15600004 */ 	bnez	$t3,.L0003d644
/*    3d634:	00000000 */ 	nop
/*    3d638:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    3d63c:	10000004 */ 	b	.L0003d650
/*    3d640:	ac8c0064 */ 	sw	$t4,0x64($a0)
.L0003d644:
/*    3d644:	8fad0004 */ 	lw	$t5,0x4($sp)
/*    3d648:	8c8e0068 */ 	lw	$t6,0x68($a0)
/*    3d64c:	adcd0000 */ 	sw	$t5,0x0($t6)
.L0003d650:
/*    3d650:	8faf0004 */ 	lw	$t7,0x4($sp)
/*    3d654:	ac8f0068 */ 	sw	$t7,0x68($a0)
/*    3d658:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3d65c:	a3070031 */ 	sb	$a3,0x31($t8)
/*    3d660:	8fb90004 */ 	lw	$t9,0x4($sp)
/*    3d664:	a3250032 */ 	sb	$a1,0x32($t9)
/*    3d668:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    3d66c:	a1060033 */ 	sb	$a2,0x33($t0)
/*    3d670:	8fa90004 */ 	lw	$t1,0x4($sp)
/*    3d674:	ad290014 */ 	sw	$t1,0x14($t1)
/*    3d678:	908a0089 */ 	lbu	$t2,0x89($a0)
/*    3d67c:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    3d680:	a08b0089 */ 	sb	$t3,0x89($a0)
.L0003d684:
/*    3d684:	10000003 */ 	b	.L0003d694
/*    3d688:	8fa20004 */ 	lw	$v0,0x4($sp)
/*    3d68c:	10000001 */ 	b	.L0003d694
/*    3d690:	00000000 */ 	nop
.L0003d694:
/*    3d694:	03e00008 */ 	jr	$ra
/*    3d698:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003d69c
/*    3d69c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3d6a0:	30a500ff */ 	andi	$a1,$a1,0xff
/*    3d6a4:	30c600ff */ 	andi	$a2,$a2,0xff
/*    3d6a8:	8c8e0064 */ 	lw	$t6,0x64($a0)
/*    3d6ac:	afae0004 */ 	sw	$t6,0x4($sp)
/*    3d6b0:	8faf0004 */ 	lw	$t7,0x4($sp)
/*    3d6b4:	11e00017 */ 	beqz	$t7,.L0003d714
/*    3d6b8:	00000000 */ 	nop
.L0003d6bc:
/*    3d6bc:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3d6c0:	93190032 */ 	lbu	$t9,0x32($t8)
/*    3d6c4:	1725000d */ 	bne	$t9,$a1,.L0003d6fc
/*    3d6c8:	00000000 */ 	nop
/*    3d6cc:	93080031 */ 	lbu	$t0,0x31($t8)
/*    3d6d0:	1506000a */ 	bne	$t0,$a2,.L0003d6fc
/*    3d6d4:	00000000 */ 	nop
/*    3d6d8:	93090035 */ 	lbu	$t1,0x35($t8)
/*    3d6dc:	24010003 */ 	addiu	$at,$zero,0x3
/*    3d6e0:	11210006 */ 	beq	$t1,$at,.L0003d6fc
/*    3d6e4:	00000000 */ 	nop
/*    3d6e8:	24010004 */ 	addiu	$at,$zero,0x4
/*    3d6ec:	11210003 */ 	beq	$t1,$at,.L0003d6fc
/*    3d6f0:	00000000 */ 	nop
/*    3d6f4:	1000000b */ 	b	.L0003d724
/*    3d6f8:	8fa20004 */ 	lw	$v0,0x4($sp)
.L0003d6fc:
/*    3d6fc:	8faa0004 */ 	lw	$t2,0x4($sp)
/*    3d700:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    3d704:	afab0004 */ 	sw	$t3,0x4($sp)
/*    3d708:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    3d70c:	1580ffeb */ 	bnez	$t4,.L0003d6bc
/*    3d710:	00000000 */ 	nop
.L0003d714:
/*    3d714:	10000003 */ 	b	.L0003d724
/*    3d718:	00001025 */ 	or	$v0,$zero,$zero
/*    3d71c:	10000001 */ 	b	.L0003d724
/*    3d720:	00000000 */ 	nop
.L0003d724:
/*    3d724:	03e00008 */ 	jr	$ra
/*    3d728:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003d72c
/*    3d72c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3d730:	30a500ff */ 	andi	$a1,$a1,0xff
/*    3d734:	30c600ff */ 	andi	$a2,$a2,0xff
/*    3d738:	30e700ff */ 	andi	$a3,$a3,0xff
/*    3d73c:	00077880 */ 	sll	$t7,$a3,0x2
/*    3d740:	01e77823 */ 	subu	$t7,$t7,$a3
/*    3d744:	8c8e0060 */ 	lw	$t6,0x60($a0)
/*    3d748:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3d74c:	01e77821 */ 	addu	$t7,$t7,$a3
/*    3d750:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3d754:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    3d758:	8f190000 */ 	lw	$t9,0x0($t8)
/*    3d75c:	afb90014 */ 	sw	$t9,0x14($sp)
/*    3d760:	24080001 */ 	addiu	$t0,$zero,0x1
/*    3d764:	afa80010 */ 	sw	$t0,0x10($sp)
/*    3d768:	8fa90014 */ 	lw	$t1,0x14($sp)
/*    3d76c:	852a000e */ 	lh	$t2,0xe($t1)
/*    3d770:	afaa000c */ 	sw	$t2,0xc($sp)
/*    3d774:	8fab000c */ 	lw	$t3,0xc($sp)
/*    3d778:	8fac0010 */ 	lw	$t4,0x10($sp)
/*    3d77c:	016c082a */ 	slt	$at,$t3,$t4
/*    3d780:	14200042 */ 	bnez	$at,.L0003d88c
/*    3d784:	00000000 */ 	nop
.L0003d788:
/*    3d788:	8fad0010 */ 	lw	$t5,0x10($sp)
/*    3d78c:	8fae000c */ 	lw	$t6,0xc($sp)
/*    3d790:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    3d794:	05e10003 */ 	bgez	$t7,.L0003d7a4
/*    3d798:	000fc043 */ 	sra	$t8,$t7,0x1
/*    3d79c:	25e10001 */ 	addiu	$at,$t7,0x1
/*    3d7a0:	0001c043 */ 	sra	$t8,$at,0x1
.L0003d7a4:
/*    3d7a4:	afb80008 */ 	sw	$t8,0x8($sp)
/*    3d7a8:	8fa80008 */ 	lw	$t0,0x8($sp)
/*    3d7ac:	8fb90014 */ 	lw	$t9,0x14($sp)
/*    3d7b0:	00084880 */ 	sll	$t1,$t0,0x2
/*    3d7b4:	03295021 */ 	addu	$t2,$t9,$t1
/*    3d7b8:	8d4b000c */ 	lw	$t3,0xc($t2)
/*    3d7bc:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*    3d7c0:	afac0004 */ 	sw	$t4,0x4($sp)
/*    3d7c4:	8fad0004 */ 	lw	$t5,0x4($sp)
/*    3d7c8:	91ae0002 */ 	lbu	$t6,0x2($t5)
/*    3d7cc:	00ae082a */ 	slt	$at,$a1,$t6
/*    3d7d0:	14200015 */ 	bnez	$at,.L0003d828
/*    3d7d4:	00000000 */ 	nop
/*    3d7d8:	91af0003 */ 	lbu	$t7,0x3($t5)
/*    3d7dc:	01e5082a */ 	slt	$at,$t7,$a1
/*    3d7e0:	14200011 */ 	bnez	$at,.L0003d828
/*    3d7e4:	00000000 */ 	nop
/*    3d7e8:	91b80000 */ 	lbu	$t8,0x0($t5)
/*    3d7ec:	00d8082a */ 	slt	$at,$a2,$t8
/*    3d7f0:	1420000d */ 	bnez	$at,.L0003d828
/*    3d7f4:	00000000 */ 	nop
/*    3d7f8:	91a80001 */ 	lbu	$t0,0x1($t5)
/*    3d7fc:	0106082a */ 	slt	$at,$t0,$a2
/*    3d800:	14200009 */ 	bnez	$at,.L0003d828
/*    3d804:	00000000 */ 	nop
/*    3d808:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    3d80c:	8fb90014 */ 	lw	$t9,0x14($sp)
/*    3d810:	00095080 */ 	sll	$t2,$t1,0x2
/*    3d814:	032a5821 */ 	addu	$t3,$t9,$t2
/*    3d818:	10000020 */ 	b	.L0003d89c
/*    3d81c:	8d62000c */ 	lw	$v0,0xc($t3)
/*    3d820:	10000015 */ 	b	.L0003d878
/*    3d824:	00000000 */ 	nop
.L0003d828:
/*    3d828:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    3d82c:	918e0002 */ 	lbu	$t6,0x2($t4)
/*    3d830:	00ae082a */ 	slt	$at,$a1,$t6
/*    3d834:	14200009 */ 	bnez	$at,.L0003d85c
/*    3d838:	00000000 */ 	nop
/*    3d83c:	918f0000 */ 	lbu	$t7,0x0($t4)
/*    3d840:	00cf082a */ 	slt	$at,$a2,$t7
/*    3d844:	10200009 */ 	beqz	$at,.L0003d86c
/*    3d848:	00000000 */ 	nop
/*    3d84c:	91980003 */ 	lbu	$t8,0x3($t4)
/*    3d850:	0305082a */ 	slt	$at,$t8,$a1
/*    3d854:	14200005 */ 	bnez	$at,.L0003d86c
/*    3d858:	00000000 */ 	nop
.L0003d85c:
/*    3d85c:	8fad0008 */ 	lw	$t5,0x8($sp)
/*    3d860:	25a8ffff */ 	addiu	$t0,$t5,-1
/*    3d864:	10000004 */ 	b	.L0003d878
/*    3d868:	afa8000c */ 	sw	$t0,0xc($sp)
.L0003d86c:
/*    3d86c:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    3d870:	25390001 */ 	addiu	$t9,$t1,0x1
/*    3d874:	afb90010 */ 	sw	$t9,0x10($sp)
.L0003d878:
/*    3d878:	8faa000c */ 	lw	$t2,0xc($sp)
/*    3d87c:	8fab0010 */ 	lw	$t3,0x10($sp)
/*    3d880:	014b082a */ 	slt	$at,$t2,$t3
/*    3d884:	1020ffc0 */ 	beqz	$at,.L0003d788
/*    3d888:	00000000 */ 	nop
.L0003d88c:
/*    3d88c:	10000003 */ 	b	.L0003d89c
/*    3d890:	00001025 */ 	or	$v0,$zero,$zero
/*    3d894:	10000001 */ 	b	.L0003d89c
/*    3d898:	00000000 */ 	nop
.L0003d89c:
/*    3d89c:	03e00008 */ 	jr	$ra
/*    3d8a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0003d8a4
/*    3d8a4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3d8a8:	908e0036 */ 	lbu	$t6,0x36($a0)
/*    3d8ac:	908f0033 */ 	lbu	$t7,0x33($a0)
/*    3d8b0:	90990030 */ 	lbu	$t9,0x30($a0)
/*    3d8b4:	01cf0019 */ 	multu	$t6,$t7
/*    3d8b8:	0000c012 */ 	mflo	$t8
/*    3d8bc:	00000000 */ 	nop
/*    3d8c0:	00000000 */ 	nop
/*    3d8c4:	03190019 */ 	multu	$t8,$t9
/*    3d8c8:	00004012 */ 	mflo	$t0
/*    3d8cc:	00084983 */ 	sra	$t1,$t0,0x6
/*    3d8d0:	afa90004 */ 	sw	$t1,0x4($sp)
/*    3d8d4:	8c8f0020 */ 	lw	$t7,0x20($a0)
/*    3d8d8:	84b90032 */ 	lh	$t9,0x32($a1)
/*    3d8dc:	908b0031 */ 	lbu	$t3,0x31($a0)
/*    3d8e0:	91f8000d */ 	lbu	$t8,0xd($t7)
/*    3d8e4:	8caa0060 */ 	lw	$t2,0x60($a1)
/*    3d8e8:	000b6080 */ 	sll	$t4,$t3,0x2
/*    3d8ec:	03190019 */ 	multu	$t8,$t9
/*    3d8f0:	018b6023 */ 	subu	$t4,$t4,$t3
/*    3d8f4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3d8f8:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3d8fc:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3d900:	014c6821 */ 	addu	$t5,$t2,$t4
/*    3d904:	91ae0009 */ 	lbu	$t6,0x9($t5)
/*    3d908:	00004012 */ 	mflo	$t0
/*    3d90c:	00000000 */ 	nop
/*    3d910:	00000000 */ 	nop
/*    3d914:	01c80019 */ 	multu	$t6,$t0
/*    3d918:	00004812 */ 	mflo	$t1
/*    3d91c:	00095b83 */ 	sra	$t3,$t1,0xe
/*    3d920:	afab0000 */ 	sw	$t3,0x0($sp)
/*    3d924:	908c0031 */ 	lbu	$t4,0x31($a0)
/*    3d928:	8caa0060 */ 	lw	$t2,0x60($a1)
/*    3d92c:	240100ff */ 	addiu	$at,$zero,0xff
/*    3d930:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3d934:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    3d938:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3d93c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*    3d940:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3d944:	014d7821 */ 	addu	$t7,$t2,$t5
/*    3d948:	91f8000d */ 	lbu	$t8,0xd($t7)
/*    3d94c:	13010010 */ 	beq	$t8,$at,.L0003d990
/*    3d950:	00000000 */ 	nop
/*    3d954:	908e0031 */ 	lbu	$t6,0x31($a0)
/*    3d958:	8cb90060 */ 	lw	$t9,0x60($a1)
/*    3d95c:	8fac0000 */ 	lw	$t4,0x0($sp)
/*    3d960:	000e4080 */ 	sll	$t0,$t6,0x2
/*    3d964:	010e4023 */ 	subu	$t0,$t0,$t6
/*    3d968:	00084080 */ 	sll	$t0,$t0,0x2
/*    3d96c:	010e4021 */ 	addu	$t0,$t0,$t6
/*    3d970:	00084080 */ 	sll	$t0,$t0,0x2
/*    3d974:	03284821 */ 	addu	$t1,$t9,$t0
/*    3d978:	912b000d */ 	lbu	$t3,0xd($t1)
/*    3d97c:	016c0019 */ 	multu	$t3,$t4
/*    3d980:	00005012 */ 	mflo	$t2
/*    3d984:	254d0001 */ 	addiu	$t5,$t2,0x1
/*    3d988:	000d7a02 */ 	srl	$t7,$t5,0x8
/*    3d98c:	afaf0000 */ 	sw	$t7,0x0($sp)
.L0003d990:
/*    3d990:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3d994:	8fae0000 */ 	lw	$t6,0x0($sp)
/*    3d998:	030e0019 */ 	multu	$t8,$t6
/*    3d99c:	0000c812 */ 	mflo	$t9
/*    3d9a0:	afb90004 */ 	sw	$t9,0x4($sp)
/*    3d9a4:	00000000 */ 	nop
/*    3d9a8:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    3d9ac:	00084bc2 */ 	srl	$t1,$t0,0xf
/*    3d9b0:	afa90004 */ 	sw	$t1,0x4($sp)
/*    3d9b4:	10000003 */ 	b	.L0003d9c4
/*    3d9b8:	87a20006 */ 	lh	$v0,0x6($sp)
/*    3d9bc:	10000001 */ 	b	.L0003d9c4
/*    3d9c0:	00000000 */ 	nop
.L0003d9c4:
/*    3d9c4:	03e00008 */ 	jr	$ra
/*    3d9c8:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003d9cc
/*    3d9cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3d9d0:	908f0031 */ 	lbu	$t7,0x31($a0)
/*    3d9d4:	8cae0060 */ 	lw	$t6,0x60($a1)
/*    3d9d8:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3d9dc:	030fc023 */ 	subu	$t8,$t8,$t7
/*    3d9e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3d9e4:	030fc021 */ 	addu	$t8,$t8,$t7
/*    3d9e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3d9ec:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    3d9f0:	9329000a */ 	lbu	$t1,0xa($t9)
/*    3d9f4:	312a0080 */ 	andi	$t2,$t1,0x80
/*    3d9f8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    3d9fc:	3c0142fe */ 	lui	$at,0x42fe
/*    3da00:	44813000 */ 	mtc1	$at,$f6
/*    3da04:	c4a4007c */ 	lwc1	$f4,0x7c($a1)
/*    3da08:	908c0031 */ 	lbu	$t4,0x31($a0)
/*    3da0c:	8cab0060 */ 	lw	$t3,0x60($a1)
/*    3da10:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    3da14:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3da18:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    3da1c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3da20:	01ac6821 */ 	addu	$t5,$t5,$t4
/*    3da24:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3da28:	016d7821 */ 	addu	$t7,$t3,$t5
/*    3da2c:	4600428d */ 	trunc.w.s	$f10,$f8
/*    3da30:	91ee000a */ 	lbu	$t6,0xa($t7)
/*    3da34:	c4a40080 */ 	lwc1	$f4,0x80($a1)
/*    3da38:	44095000 */ 	mfc1	$t1,$f10
/*    3da3c:	31d8007f */ 	andi	$t8,$t6,0x7f
/*    3da40:	03095021 */ 	addu	$t2,$t8,$t1
/*    3da44:	448a8000 */ 	mtc1	$t2,$f16
/*    3da48:	00000000 */ 	nop
/*    3da4c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    3da50:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    3da54:	4600320d */ 	trunc.w.s	$f8,$f6
/*    3da58:	440b4000 */ 	mfc1	$t3,$f8
/*    3da5c:	00000000 */ 	nop
/*    3da60:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3da64:	8fad0010 */ 	lw	$t5,0x10($sp)
/*    3da68:	29a10080 */ 	slti	$at,$t5,0x80
/*    3da6c:	14200003 */ 	bnez	$at,.L0003da7c
/*    3da70:	00000000 */ 	nop
/*    3da74:	10000002 */ 	b	.L0003da80
/*    3da78:	2407007f */ 	addiu	$a3,$zero,0x7f
.L0003da7c:
/*    3da7c:	8fa70010 */ 	lw	$a3,0x10($sp)
.L0003da80:
/*    3da80:	04e10003 */ 	bgez	$a3,.L0003da90
/*    3da84:	00000000 */ 	nop
/*    3da88:	10000009 */ 	b	.L0003dab0
/*    3da8c:	00003025 */ 	or	$a2,$zero,$zero
.L0003da90:
/*    3da90:	8faf0010 */ 	lw	$t7,0x10($sp)
/*    3da94:	29e10080 */ 	slti	$at,$t7,0x80
/*    3da98:	14200003 */ 	bnez	$at,.L0003daa8
/*    3da9c:	00000000 */ 	nop
/*    3daa0:	10000002 */ 	b	.L0003daac
/*    3daa4:	2408007f */ 	addiu	$t0,$zero,0x7f
.L0003daa8:
/*    3daa8:	8fa80010 */ 	lw	$t0,0x10($sp)
.L0003daac:
/*    3daac:	01003025 */ 	or	$a2,$t0,$zero
.L0003dab0:
/*    3dab0:	8fae0014 */ 	lw	$t6,0x14($sp)
/*    3dab4:	00ce1025 */ 	or	$v0,$a2,$t6
/*    3dab8:	10000003 */ 	b	.L0003dac8
/*    3dabc:	304200ff */ 	andi	$v0,$v0,0xff
/*    3dac0:	10000001 */ 	b	.L0003dac8
/*    3dac4:	00000000 */ 	nop
.L0003dac8:
/*    3dac8:	03e00008 */ 	jr	$ra
/*    3dacc:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

ALMicroTime __vsDelta(ALVoiceState *vs, ALMicroTime t)
{
	/*
	 * If we are interrupting a previously set envelope segment, we
	 * need to recalculate the segment end time given the current
	 * time. Note: this routine assumes that the voice is currently
	 * playing.
	 */

	s32 delta = vs->envEndTime - t;

	if (delta >= 0) {
		return delta;
	} else {
		return AL_GAIN_CHANGE_TIME;
	}
}

ALPan __vsPan(ALVoiceState *vs, ALSeqPlayer *seqp)
{
	s32 tmp;

	tmp = seqp->chanState[vs->channel].pan - AL_PAN_CENTER + vs->sound->samplePan;
	tmp = MAX(tmp, AL_PAN_LEFT);
	tmp = MIN(tmp, AL_PAN_RIGHT);

	return (ALPan) tmp;
}

void __initFromBank(ALSeqPlayer *seqp, ALBank *b)
{
	/*
	 * init the chanState with the default instrument
	 */
	s32 i;
	ALInstrument *inst = 0;

	/* set to the first available instrument. */
	for (i = 0; !inst; i++) {
		inst = b->instArray[i];
	}

	/* sct 11/6/95 - Setup the channel state for the given instrument. */
	/* There is some wasted effort here since both calls the same state vars */
	/* but it's safer. */
	for (i = 0; i < seqp->maxChannels; i++) {
		__resetPerfChanState(seqp, i);
		__setInstChanState(seqp, inst, i);
	}

	if (b->percussion) {
		__resetPerfChanState(seqp, i);
		__setInstChanState(seqp, b->percussion, 9);
	}
}

void __initChanState(ALSeqPlayer *seqp)
{
	int i;

	for (i = 0; i < seqp->maxChannels; i++) {
		seqp->chanState[i].instrument = 0;
		__resetPerfChanState (seqp, i);
	}
}

void __resetPerfChanState(ALSeqPlayer *seqp, s32 chan)
{
	seqp->chanState[chan].fxId = AL_FX_NONE;
	seqp->chanState[chan].fxmix = AL_DEFAULT_FXMIX;
	seqp->chanState[chan].pan = AL_PAN_CENTER;
	seqp->chanState[chan].vol = AL_VOL_FULL;
	seqp->chanState[chan].priority = AL_DEFAULT_PRIORITY;
	seqp->chanState[chan].sustain = 0;
	seqp->chanState[chan].bendRange = 200;
	seqp->chanState[chan].pitchBend = 1;
	seqp->chanState[chan].unk10 = 0;
	seqp->chanState[chan].unk0d = 255;
	seqp->chanState[chan].unk0e = 255;
	seqp->chanState[chan].unk0f = 0;
	seqp->chanState[chan].unk0b = 0;
	seqp->chanState[chan].unk13 = 0;
	seqp->chanState[chan].unk12 = 0;
	seqp->chanState[chan].unk11 = 0;
	seqp->chanState[chan].unk32 = 0;
}

GLOBAL_ASM(
glabel __setInstChanState
/*    3df64:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3df68:	00067880 */ 	sll	$t7,$a2,0x2
/*    3df6c:	01e67823 */ 	subu	$t7,$t7,$a2
/*    3df70:	8c8e0060 */ 	lw	$t6,0x60($a0)
/*    3df74:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3df78:	01e67821 */ 	addu	$t7,$t7,$a2
/*    3df7c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3df80:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    3df84:	af050000 */ 	sw	$a1,0x0($t8)
/*    3df88:	00064880 */ 	sll	$t1,$a2,0x2
/*    3df8c:	01264823 */ 	subu	$t1,$t1,$a2
/*    3df90:	8c880060 */ 	lw	$t0,0x60($a0)
/*    3df94:	00094880 */ 	sll	$t1,$t1,0x2
/*    3df98:	90b90001 */ 	lbu	$t9,0x1($a1)
/*    3df9c:	01264821 */ 	addu	$t1,$t1,$a2
/*    3dfa0:	00094880 */ 	sll	$t1,$t1,0x2
/*    3dfa4:	01095021 */ 	addu	$t2,$t0,$t1
/*    3dfa8:	a1590007 */ 	sb	$t9,0x7($t2)
/*    3dfac:	00066880 */ 	sll	$t5,$a2,0x2
/*    3dfb0:	01a66823 */ 	subu	$t5,$t5,$a2
/*    3dfb4:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*    3dfb8:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3dfbc:	90ab0000 */ 	lbu	$t3,0x0($a1)
/*    3dfc0:	01a66821 */ 	addu	$t5,$t5,$a2
/*    3dfc4:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3dfc8:	018d7021 */ 	addu	$t6,$t4,$t5
/*    3dfcc:	a1cb0009 */ 	sb	$t3,0x9($t6)
/*    3dfd0:	00064080 */ 	sll	$t0,$a2,0x2
/*    3dfd4:	01064023 */ 	subu	$t0,$t0,$a2
/*    3dfd8:	8c980060 */ 	lw	$t8,0x60($a0)
/*    3dfdc:	00084080 */ 	sll	$t0,$t0,0x2
/*    3dfe0:	90af0002 */ 	lbu	$t7,0x2($a1)
/*    3dfe4:	01064021 */ 	addu	$t0,$t0,$a2
/*    3dfe8:	00084080 */ 	sll	$t0,$t0,0x2
/*    3dfec:	03084821 */ 	addu	$t1,$t8,$t0
/*    3dff0:	a12f0008 */ 	sb	$t7,0x8($t1)
/*    3dff4:	00066080 */ 	sll	$t4,$a2,0x2
/*    3dff8:	01866023 */ 	subu	$t4,$t4,$a2
/*    3dffc:	8c8a0060 */ 	lw	$t2,0x60($a0)
/*    3e000:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3e004:	84b9000c */ 	lh	$t9,0xc($a1)
/*    3e008:	01866021 */ 	addu	$t4,$t4,$a2
/*    3e00c:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3e010:	014c6821 */ 	addu	$t5,$t2,$t4
/*    3e014:	a5b90004 */ 	sh	$t9,0x4($t5)
/*    3e018:	84ab000e */ 	lh	$t3,0xe($a1)
/*    3e01c:	15600003 */ 	bnez	$t3,.L0003e02c
/*    3e020:	00000000 */ 	nop
/*    3e024:	1000009c */ 	b	.L0003e298
/*    3e028:	00000000 */ 	nop
.L0003e02c:
/*    3e02c:	8cae0010 */ 	lw	$t6,0x10($a1)
/*    3e030:	afae0004 */ 	sw	$t6,0x4($sp)
/*    3e034:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3e038:	00065080 */ 	sll	$t2,$a2,0x2
/*    3e03c:	01465023 */ 	subu	$t2,$t2,$a2
/*    3e040:	8f080000 */ 	lw	$t0,0x0($t8)
/*    3e044:	8c890060 */ 	lw	$t1,0x60($a0)
/*    3e048:	000a5080 */ 	sll	$t2,$t2,0x2
/*    3e04c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*    3e050:	01465021 */ 	addu	$t2,$t2,$a2
/*    3e054:	000a5080 */ 	sll	$t2,$t2,0x2
/*    3e058:	012a6021 */ 	addu	$t4,$t1,$t2
/*    3e05c:	ad8f0018 */ 	sw	$t7,0x18($t4)
/*    3e060:	8fb90004 */ 	lw	$t9,0x4($sp)
/*    3e064:	0006c080 */ 	sll	$t8,$a2,0x2
/*    3e068:	0306c023 */ 	subu	$t8,$t8,$a2
/*    3e06c:	8f2d0000 */ 	lw	$t5,0x0($t9)
/*    3e070:	8c8e0060 */ 	lw	$t6,0x60($a0)
/*    3e074:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3e078:	8dab0004 */ 	lw	$t3,0x4($t5)
/*    3e07c:	0306c021 */ 	addu	$t8,$t8,$a2
/*    3e080:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3e084:	01d84021 */ 	addu	$t0,$t6,$t8
/*    3e088:	ad0b001c */ 	sw	$t3,0x1c($t0)
/*    3e08c:	8fa90004 */ 	lw	$t1,0x4($sp)
/*    3e090:	0006c880 */ 	sll	$t9,$a2,0x2
/*    3e094:	0326c823 */ 	subu	$t9,$t9,$a2
/*    3e098:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    3e09c:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*    3e0a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3e0a4:	8d4f0008 */ 	lw	$t7,0x8($t2)
/*    3e0a8:	0326c821 */ 	addu	$t9,$t9,$a2
/*    3e0ac:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3e0b0:	01996821 */ 	addu	$t5,$t4,$t9
/*    3e0b4:	adaf0020 */ 	sw	$t7,0x20($t5)
/*    3e0b8:	8fae0004 */ 	lw	$t6,0x4($sp)
/*    3e0bc:	00064880 */ 	sll	$t1,$a2,0x2
/*    3e0c0:	01264823 */ 	subu	$t1,$t1,$a2
/*    3e0c4:	8dd80000 */ 	lw	$t8,0x0($t6)
/*    3e0c8:	8c880060 */ 	lw	$t0,0x60($a0)
/*    3e0cc:	00094880 */ 	sll	$t1,$t1,0x2
/*    3e0d0:	930b000c */ 	lbu	$t3,0xc($t8)
/*    3e0d4:	01264821 */ 	addu	$t1,$t1,$a2
/*    3e0d8:	00094880 */ 	sll	$t1,$t1,0x2
/*    3e0dc:	01095021 */ 	addu	$t2,$t0,$t1
/*    3e0e0:	a14b0025 */ 	sb	$t3,0x25($t2)
/*    3e0e4:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    3e0e8:	00067080 */ 	sll	$t6,$a2,0x2
/*    3e0ec:	01c67023 */ 	subu	$t6,$t6,$a2
/*    3e0f0:	8d990000 */ 	lw	$t9,0x0($t4)
/*    3e0f4:	8c8d0060 */ 	lw	$t5,0x60($a0)
/*    3e0f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3e0fc:	932f000d */ 	lbu	$t7,0xd($t9)
/*    3e100:	01c67021 */ 	addu	$t6,$t6,$a2
/*    3e104:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3e108:	01aec021 */ 	addu	$t8,$t5,$t6
/*    3e10c:	a30f0026 */ 	sb	$t7,0x26($t8)
/*    3e110:	00064880 */ 	sll	$t1,$a2,0x2
/*    3e114:	01264823 */ 	subu	$t1,$t1,$a2
/*    3e118:	8c880060 */ 	lw	$t0,0x60($a0)
/*    3e11c:	00094880 */ 	sll	$t1,$t1,0x2
/*    3e120:	01264821 */ 	addu	$t1,$t1,$a2
/*    3e124:	00094880 */ 	sll	$t1,$t1,0x2
/*    3e128:	01095821 */ 	addu	$t3,$t0,$t1
/*    3e12c:	a1600027 */ 	sb	$zero,0x27($t3)
/*    3e130:	0006c880 */ 	sll	$t9,$a2,0x2
/*    3e134:	0326c823 */ 	subu	$t9,$t9,$a2
/*    3e138:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*    3e13c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3e140:	90aa0004 */ 	lbu	$t2,0x4($a1)
/*    3e144:	0326c821 */ 	addu	$t9,$t9,$a2
/*    3e148:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3e14c:	01996821 */ 	addu	$t5,$t4,$t9
/*    3e150:	a1aa0028 */ 	sb	$t2,0x28($t5)
/*    3e154:	0006c080 */ 	sll	$t8,$a2,0x2
/*    3e158:	0306c023 */ 	subu	$t8,$t8,$a2
/*    3e15c:	8c8f0060 */ 	lw	$t7,0x60($a0)
/*    3e160:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3e164:	90ae0005 */ 	lbu	$t6,0x5($a1)
/*    3e168:	0306c021 */ 	addu	$t8,$t8,$a2
/*    3e16c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3e170:	01f84021 */ 	addu	$t0,$t7,$t8
/*    3e174:	a10e0029 */ 	sb	$t6,0x29($t0)
/*    3e178:	00066080 */ 	sll	$t4,$a2,0x2
/*    3e17c:	01866023 */ 	subu	$t4,$t4,$a2
/*    3e180:	8c8b0060 */ 	lw	$t3,0x60($a0)
/*    3e184:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3e188:	90a90006 */ 	lbu	$t1,0x6($a1)
/*    3e18c:	01866021 */ 	addu	$t4,$t4,$a2
/*    3e190:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3e194:	016cc821 */ 	addu	$t9,$t3,$t4
/*    3e198:	a329002a */ 	sb	$t1,0x2a($t9)
/*    3e19c:	00067880 */ 	sll	$t7,$a2,0x2
/*    3e1a0:	01e67823 */ 	subu	$t7,$t7,$a2
/*    3e1a4:	8c8d0060 */ 	lw	$t5,0x60($a0)
/*    3e1a8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3e1ac:	90aa0007 */ 	lbu	$t2,0x7($a1)
/*    3e1b0:	01e67821 */ 	addu	$t7,$t7,$a2
/*    3e1b4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3e1b8:	01afc021 */ 	addu	$t8,$t5,$t7
/*    3e1bc:	a30a002b */ 	sb	$t2,0x2b($t8)
/*    3e1c0:	00065880 */ 	sll	$t3,$a2,0x2
/*    3e1c4:	01665823 */ 	subu	$t3,$t3,$a2
/*    3e1c8:	8c880060 */ 	lw	$t0,0x60($a0)
/*    3e1cc:	000b5880 */ 	sll	$t3,$t3,0x2
/*    3e1d0:	90ae0008 */ 	lbu	$t6,0x8($a1)
/*    3e1d4:	01665821 */ 	addu	$t3,$t3,$a2
/*    3e1d8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    3e1dc:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3e1e0:	a18e002c */ 	sb	$t6,0x2c($t4)
/*    3e1e4:	00066880 */ 	sll	$t5,$a2,0x2
/*    3e1e8:	01a66823 */ 	subu	$t5,$t5,$a2
/*    3e1ec:	8c990060 */ 	lw	$t9,0x60($a0)
/*    3e1f0:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3e1f4:	90a90009 */ 	lbu	$t1,0x9($a1)
/*    3e1f8:	01a66821 */ 	addu	$t5,$t5,$a2
/*    3e1fc:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3e200:	032d7821 */ 	addu	$t7,$t9,$t5
/*    3e204:	a1e9002d */ 	sb	$t1,0x2d($t7)
/*    3e208:	00064080 */ 	sll	$t0,$a2,0x2
/*    3e20c:	01064023 */ 	subu	$t0,$t0,$a2
/*    3e210:	8c980060 */ 	lw	$t8,0x60($a0)
/*    3e214:	00084080 */ 	sll	$t0,$t0,0x2
/*    3e218:	90aa000a */ 	lbu	$t2,0xa($a1)
/*    3e21c:	01064021 */ 	addu	$t0,$t0,$a2
/*    3e220:	00084080 */ 	sll	$t0,$t0,0x2
/*    3e224:	03085821 */ 	addu	$t3,$t8,$t0
/*    3e228:	a16a002e */ 	sb	$t2,0x2e($t3)
/*    3e22c:	0006c880 */ 	sll	$t9,$a2,0x2
/*    3e230:	0326c823 */ 	subu	$t9,$t9,$a2
/*    3e234:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*    3e238:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3e23c:	90ae000b */ 	lbu	$t6,0xb($a1)
/*    3e240:	0326c821 */ 	addu	$t9,$t9,$a2
/*    3e244:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3e248:	01996821 */ 	addu	$t5,$t4,$t9
/*    3e24c:	a1ae002f */ 	sb	$t6,0x2f($t5)
/*    3e250:	00067880 */ 	sll	$t7,$a2,0x2
/*    3e254:	01e67823 */ 	subu	$t7,$t7,$a2
/*    3e258:	8c890060 */ 	lw	$t1,0x60($a0)
/*    3e25c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3e260:	01e67821 */ 	addu	$t7,$t7,$a2
/*    3e264:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3e268:	012fc021 */ 	addu	$t8,$t1,$t7
/*    3e26c:	a3000024 */ 	sb	$zero,0x24($t8)
/*    3e270:	00065080 */ 	sll	$t2,$a2,0x2
/*    3e274:	01465023 */ 	subu	$t2,$t2,$a2
/*    3e278:	8c880060 */ 	lw	$t0,0x60($a0)
/*    3e27c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    3e280:	01465021 */ 	addu	$t2,$t2,$a2
/*    3e284:	000a5080 */ 	sll	$t2,$t2,0x2
/*    3e288:	010a5821 */ 	addu	$t3,$t0,$t2
/*    3e28c:	a1600031 */ 	sb	$zero,0x31($t3)
/*    3e290:	10000001 */ 	b	.L0003e298
/*    3e294:	00000000 */ 	nop
.L0003e298:
/*    3e298:	03e00008 */ 	jr	$ra
/*    3e29c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003e2a0
/*    3e2a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3e2a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e2a8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3e2ac:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3e2b0:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3e2b4:	8dcf0050 */ 	lw	$t7,0x50($t6)
/*    3e2b8:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    3e2bc:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3e2c0:	13000040 */ 	beqz	$t8,.L0003e3c4
/*    3e2c4:	00000000 */ 	nop
.L0003e2c8:
/*    3e2c8:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3e2cc:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3e2d0:	afa80020 */ 	sw	$t0,0x20($sp)
/*    3e2d4:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3e2d8:	852a000c */ 	lh	$t2,0xc($t1)
/*    3e2dc:	a7aa001e */ 	sh	$t2,0x1e($sp)
/*    3e2e0:	87ab001e */ 	lh	$t3,0x1e($sp)
/*    3e2e4:	24010016 */ 	addiu	$at,$zero,0x16
/*    3e2e8:	11610004 */ 	beq	$t3,$at,.L0003e2fc
/*    3e2ec:	00000000 */ 	nop
/*    3e2f0:	24010017 */ 	addiu	$at,$zero,0x17
/*    3e2f4:	1561002e */ 	bne	$t3,$at,.L0003e3b0
/*    3e2f8:	00000000 */ 	nop
.L0003e2fc:
/*    3e2fc:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3e300:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3e304:	8d8d0010 */ 	lw	$t5,0x10($t4)
/*    3e308:	15ae0029 */ 	bne	$t5,$t6,.L0003e3b0
/*    3e30c:	00000000 */ 	nop
/*    3e310:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3e314:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3e318:	8f190078 */ 	lw	$t9,0x78($t8)
/*    3e31c:	8de40014 */ 	lw	$a0,0x14($t7)
/*    3e320:	0320f809 */ 	jalr	$t9
/*    3e324:	00000000 */ 	nop
/*    3e328:	0c00c5e9 */ 	jal	alUnlink
/*    3e32c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3e330:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3e334:	11000007 */ 	beqz	$t0,.L0003e354
/*    3e338:	00000000 */ 	nop
/*    3e33c:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e340:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3e344:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3e348:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*    3e34c:	014c6821 */ 	addu	$t5,$t2,$t4
/*    3e350:	ad2d0008 */ 	sw	$t5,0x8($t1)
.L0003e354:
/*    3e354:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    3e358:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3e35c:	0c00c5dc */ 	jal	alLink
/*    3e360:	24a50048 */ 	addiu	$a1,$a1,0x48
/*    3e364:	87ae001e */ 	lh	$t6,0x1e($sp)
/*    3e368:	24010016 */ 	addiu	$at,$zero,0x16
/*    3e36c:	15c10006 */ 	bne	$t6,$at,.L0003e388
/*    3e370:	00000000 */ 	nop
/*    3e374:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3e378:	91f80037 */ 	lbu	$t8,0x37($t7)
/*    3e37c:	331900fe */ 	andi	$t9,$t8,0xfe
/*    3e380:	10000005 */ 	b	.L0003e398
/*    3e384:	a1f90037 */ 	sb	$t9,0x37($t7)
.L0003e388:
/*    3e388:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3e38c:	910b0037 */ 	lbu	$t3,0x37($t0)
/*    3e390:	316a00fd */ 	andi	$t2,$t3,0xfd
/*    3e394:	a10a0037 */ 	sb	$t2,0x37($t0)
.L0003e398:
/*    3e398:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    3e39c:	918d0037 */ 	lbu	$t5,0x37($t4)
/*    3e3a0:	15a00003 */ 	bnez	$t5,.L0003e3b0
/*    3e3a4:	00000000 */ 	nop
/*    3e3a8:	10000008 */ 	b	.L0003e3cc
/*    3e3ac:	00000000 */ 	nop
.L0003e3b0:
/*    3e3b0:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e3b4:	afa90024 */ 	sw	$t1,0x24($sp)
/*    3e3b8:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3e3bc:	15c0ffc2 */ 	bnez	$t6,.L0003e2c8
/*    3e3c0:	00000000 */ 	nop
.L0003e3c4:
/*    3e3c4:	10000001 */ 	b	.L0003e3cc
/*    3e3c8:	00000000 */ 	nop
.L0003e3cc:
/*    3e3cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e3d0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3e3d4:	03e00008 */ 	jr	$ra
/*    3e3d8:	00000000 */ 	nop
);
