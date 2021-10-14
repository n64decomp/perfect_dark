#include <libaudio.h>
#include <os_internal.h>
#include <ultraerror.h>
#include "n_libaudio.h"
#include "n_seqp.h"
#include "seq.h"

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

void __seqpReleaseVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime deltaTime)
{
	N_ALEvent evt;
	N_ALVoiceState *vs = (N_ALVoiceState *)voice->clientPrivate;

	/*
	 * if in attack phase, remove all pending volume
	 * events for this voice from the queue
	 */

	if (vs->envPhase == AL_PHASE_ATTACK) {
		ALLink *thisNode;
		ALLink *nextNode;
		N_ALEventListItem *thisItem, *nextItem;

		thisNode = seqp->evtq.allocList.next;

		while (thisNode != 0) {
			nextNode = thisNode->next;
			thisItem = (N_ALEventListItem *)thisNode;
			nextItem = (N_ALEventListItem *)nextNode;

			if (thisItem->evt.type == AL_SEQP_ENV_EVT) {
				if (thisItem->evt.msg.vol.voice == voice) {
					if (nextItem) {
						nextItem->delta += thisItem->delta;
					}

					alUnlink(thisNode);
					alLink(thisNode, &seqp->evtq.freeList);
				}
			}

			thisNode = nextNode;
		}
	}

	vs->velocity = 0;
	vs->envPhase = AL_PHASE_RELEASE;
	vs->envGain  = 0;
	vs->envEndTime = seqp->curTime + deltaTime;

	n_alSynSetPriority(voice, 0); /* make candidate for stealing */
	n_alSynSetVol(voice, 0, deltaTime);

	evt.type = AL_NOTE_END_EVT;
	evt.msg.note.voice = voice;

	deltaTime += (PAL ? 40000 : 32000);

	n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);
}

char __n_voiceNeedsNoteKill(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime killTime)
{
	ALLink *thisNode;
	ALLink *nextNode;
	N_ALEventListItem *thisItem;
	ALMicroTime itemTime = 0;
	char needsNoteKill = TRUE;

	thisNode = seqp->evtq.allocList.next;

	while (thisNode != 0) {
		nextNode = thisNode->next;
		thisItem = (N_ALEventListItem *)thisNode;
		itemTime += thisItem->delta;

		if (thisItem->evt.type == AL_NOTE_END_EVT) {
			if (thisItem->evt.msg.note.voice == voice) {
				if (itemTime > killTime) {
					if ((N_ALEventListItem *)nextNode) {
						((N_ALEventListItem *)nextNode)->delta += thisItem->delta;
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

N_ALVoiceState *__n_lookupVoice(N_ALSeqPlayer *seqp, u8 key, u8 channel)
{
	N_ALVoiceState *vs = seqp->vAllocHead;

	while (vs != 0) {
		if (vs->key == key
				&& vs->channel == channel
				&& vs->phase != AL_PHASE_RELEASE
				&& vs->phase != AL_PHASE_SUSTREL) {
			return vs;
		}

		vs = vs->next;
	}

	return 0;
}

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
glabel __n_vsVol
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

ALMicroTime __n_vsDelta(N_ALVoiceState *vs, ALMicroTime t)
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

ALPan __vsPan(N_ALVoiceState *vs, N_ALSeqPlayer *seqp)
{
	s32 tmp;

	tmp = seqp->chanState[vs->channel].pan - AL_PAN_CENTER + vs->sound->samplePan;
	tmp = MAX(tmp, AL_PAN_LEFT);
	tmp = MIN(tmp, AL_PAN_RIGHT);

	return (ALPan) tmp;
}

void __n_initFromBank(N_ALSeqPlayer *seqp, ALBank *b)
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
		__n_resetPerfChanState(seqp, i);
		__n_setInstChanState(seqp, inst, i);
	}

	if (b->percussion) {
		__n_resetPerfChanState(seqp, i);
		__n_setInstChanState(seqp, b->percussion, 9);
	}
}

void __n_initChanState(N_ALSeqPlayer *seqp)
{
	int i;

	for (i = 0; i < seqp->maxChannels; i++) {
		seqp->chanState[i].instrument = 0;
		__n_resetPerfChanState (seqp, i);
	}
}

void __n_resetPerfChanState(N_ALSeqPlayer *seqp, s32 chan)
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

void __n_setInstChanState(N_ALSeqPlayer *seqp, ALInstrument *inst, s32 chan)
{
	ALSound *sound;

	seqp->chanState[chan].instrument = inst;
	seqp->chanState[chan].pan = inst->pan;
	seqp->chanState[chan].vol = inst->volume;
	seqp->chanState[chan].priority = inst->priority;
	seqp->chanState[chan].bendRange = inst->bendRange;

	if (inst->soundCount == 0) {
		return;
	}

	sound = inst->soundArray[0];

	seqp->chanState[chan].attackTime = sound->envelope->attackTime;
	seqp->chanState[chan].decayTime = sound->envelope->decayTime;
	seqp->chanState[chan].releaseTime = sound->envelope->releaseTime;
	seqp->chanState[chan].attackVolume = sound->envelope->attackVolume;
	seqp->chanState[chan].decayVolume = sound->envelope->decayVolume;

	seqp->chanState[chan].unk27 = 0;
	seqp->chanState[chan].tremType = inst->tremType;
	seqp->chanState[chan].tremRate = inst->tremRate;
	seqp->chanState[chan].tremDepth = inst->tremDepth;
	seqp->chanState[chan].tremDelay = inst->tremDelay;
	seqp->chanState[chan].vibType = inst->vibType;
	seqp->chanState[chan].ribRate = inst->vibRate;
	seqp->chanState[chan].vibDepth = inst->vibDepth;
	seqp->chanState[chan].vibDelay = inst->vibDelay;

	seqp->chanState[chan].unk24 = 0;
	seqp->chanState[chan].unk31 = 0;
}

void __n_seqpStopOsc(N_ALSeqPlayer *seqp, N_ALVoiceState *vs)
{
	N_ALEventListItem *thisNode,*nextNode;
	s16 evtType;

	thisNode = (N_ALEventListItem*)seqp->evtq.allocList.next;

	while (thisNode) {
		nextNode = (N_ALEventListItem*)thisNode->node.next;
		evtType = thisNode->evt.type;

		if (evtType == AL_TREM_OSC_EVT || evtType == AL_VIB_OSC_EVT) {
			if (thisNode->evt.msg.osc.vs == vs) {
				(*seqp->stopOsc)(thisNode->evt.msg.osc.oscState);
				alUnlink((ALLink*)thisNode);

				if (nextNode) {
					nextNode->delta += thisNode->delta;
				}

				alLink((ALLink*)thisNode, &seqp->evtq.freeList);

				if (evtType == AL_TREM_OSC_EVT) {
					vs->flags &= 0xfe;
				} else { /* must be a AL_VIB_OSC_EVT */
					vs->flags &= 0xfd;
				}

				if (!vs->flags) {
					return;  /* there should be no more events */
				}
			}
		}

		thisNode = nextNode;
	}
}
