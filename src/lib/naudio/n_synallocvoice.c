#include <os_internal.h>
#include <ultraerror.h>
#include "n_synthInternals.h"

GLOBAL_ASM(
glabel n_alSynAllocVoice
/*    3c9e0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3c9e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c9e8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3c9ec:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3c9f0:	afa00024 */ 	sw	$zero,0x24($sp)
/*    3c9f4:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3c9f8:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3c9fc:	85cf0000 */ 	lh	$t7,0x0($t6)
/*    3ca00:	a70f0016 */ 	sh	$t7,0x16($t8)
/*    3ca04:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3ca08:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    3ca0c:	93280004 */ 	lbu	$t0,0x4($t9)
/*    3ca10:	a528001a */ 	sh	$t0,0x1a($t1)
/*    3ca14:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3ca18:	ad40000c */ 	sw	$zero,0xc($t2)
/*    3ca1c:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3ca20:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3ca24:	856c0002 */ 	lh	$t4,0x2($t3)
/*    3ca28:	a5ac0018 */ 	sh	$t4,0x18($t5)
/*    3ca2c:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3ca30:	a5c00014 */ 	sh	$zero,0x14($t6)
/*    3ca34:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3ca38:	ade00008 */ 	sw	$zero,0x8($t7)
/*    3ca3c:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3ca40:	27a40024 */ 	addiu	$a0,$sp,0x24
/*    3ca44:	0c00f2ed */ 	jal	_allocatePVoice
/*    3ca48:	87050000 */ 	lh	$a1,0x0($t8)
/*    3ca4c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3ca50:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3ca54:	1320004e */ 	beqz	$t9,.L0003cb90
/*    3ca58:	00000000 */ 	nop
/*    3ca5c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    3ca60:	11000043 */ 	beqz	$t0,.L0003cb70
/*    3ca64:	00000000 */ 	nop
/*    3ca68:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3ca6c:	24090228 */ 	addiu	$t1,$zero,0x228
/*    3ca70:	ad490088 */ 	sw	$t1,0x88($t2)
/*    3ca74:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3ca78:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*    3ca7c:	ad800008 */ 	sw	$zero,0x8($t4)
/*    3ca80:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3ca84:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3ca88:	adcd0008 */ 	sw	$t5,0x8($t6)
/*    3ca8c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3ca90:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3ca94:	af0f0008 */ 	sw	$t7,0x8($t8)
/*    3ca98:	0c00c541 */ 	jal	__n_allocParam
/*    3ca9c:	00000000 */ 	nop
/*    3caa0:	afa20020 */ 	sw	$v0,0x20($sp)
/*    3caa4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3caa8:	13200015 */ 	beqz	$t9,.L0003cb00
/*    3caac:	00000000 */ 	nop
/*    3cab0:	3c088006 */ 	lui	$t0,%hi(n_syn)
/*    3cab4:	8d08f114 */ 	lw	$t0,%lo(n_syn)($t0)
/*    3cab8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3cabc:	8d09001c */ 	lw	$t1,0x1c($t0)
/*    3cac0:	ad490004 */ 	sw	$t1,0x4($t2)
/*    3cac4:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3cac8:	240b000b */ 	addiu	$t3,$zero,0xb
/*    3cacc:	a58b0008 */ 	sh	$t3,0x8($t4)
/*    3cad0:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3cad4:	ada0000c */ 	sw	$zero,0xc($t5)
/*    3cad8:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cadc:	240e0170 */ 	addiu	$t6,$zero,0x170
/*    3cae0:	adee0010 */ 	sw	$t6,0x10($t7)
/*    3cae4:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3cae8:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3caec:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    3caf0:	0c00fc79 */ 	jal	n_alEnvmixerParam
/*    3caf4:	8f040008 */ 	lw	$a0,0x8($t8)
/*    3caf8:	10000001 */ 	b	.L0003cb00
/*    3cafc:	00000000 */ 	nop
.L0003cb00:
/*    3cb00:	0c00c541 */ 	jal	__n_allocParam
/*    3cb04:	00000000 */ 	nop
/*    3cb08:	afa20020 */ 	sw	$v0,0x20($sp)
/*    3cb0c:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3cb10:	13200015 */ 	beqz	$t9,.L0003cb68
/*    3cb14:	00000000 */ 	nop
/*    3cb18:	3c088006 */ 	lui	$t0,%hi(n_syn)
/*    3cb1c:	8d08f114 */ 	lw	$t0,%lo(n_syn)($t0)
/*    3cb20:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3cb24:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3cb28:	8d09001c */ 	lw	$t1,0x1c($t0)
/*    3cb2c:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3cb30:	012b6021 */ 	addu	$t4,$t1,$t3
/*    3cb34:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3cb38:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cb3c:	240e000f */ 	addiu	$t6,$zero,0xf
/*    3cb40:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3cb44:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3cb48:	af000000 */ 	sw	$zero,0x0($t8)
/*    3cb4c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3cb50:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3cb54:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    3cb58:	0c00fc79 */ 	jal	n_alEnvmixerParam
/*    3cb5c:	8f240008 */ 	lw	$a0,0x8($t9)
/*    3cb60:	10000001 */ 	b	.L0003cb68
/*    3cb64:	00000000 */ 	nop
.L0003cb68:
/*    3cb68:	10000009 */ 	b	.L0003cb90
/*    3cb6c:	00000000 */ 	nop
.L0003cb70:
/*    3cb70:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    3cb74:	ad000088 */ 	sw	$zero,0x88($t0)
/*    3cb78:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3cb7c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3cb80:	ad2a0008 */ 	sw	$t2,0x8($t1)
/*    3cb84:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3cb88:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    3cb8c:	ad8b0008 */ 	sw	$t3,0x8($t4)
.L0003cb90:
/*    3cb90:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    3cb94:	10000003 */ 	b	.L0003cba4
/*    3cb98:	0002102b */ 	sltu	$v0,$zero,$v0
/*    3cb9c:	10000001 */ 	b	.L0003cba4
/*    3cba0:	00000000 */ 	nop
.L0003cba4:
/*    3cba4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3cba8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3cbac:	03e00008 */ 	jr	$ra
/*    3cbb0:	00000000 */ 	nop
);

s32 _allocatePVoice(N_PVoice **pvoice, s16 priority)
{
	ALLink *dl;
	N_PVoice *pv;
	s32 stolen = 0;

	if ((dl = n_syn->pLameList.next) != 0) { /* check the lame list first */
		*pvoice = (N_PVoice *)dl;
		alUnlink(dl);
		alLink(dl, &n_syn->pAllocList);
	} else if ((dl = n_syn->pFreeList.next) != 0) { /* from the free list */
		*pvoice = (N_PVoice *) dl;
		alUnlink(dl);
		alLink(dl, &n_syn->pAllocList);
	} else { /* steal one */
		for (dl = n_syn->pAllocList.next; dl != 0; dl = dl->next) {
			pv = (N_PVoice *)dl;

			/*
			 * if it is lower priority and not already stolen, keep it
			 * as a candidate for stealing
			 */
			if ((pv->vvoice->priority <= priority) && (pv->offset == 0)) {
				*pvoice = pv;
				priority = pv->vvoice->priority;
				stolen = 1;
			}
		}
	}

	return stolen;
}
