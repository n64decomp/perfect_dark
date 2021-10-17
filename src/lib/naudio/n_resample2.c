#include "n_synthInternals.h"
#include <os.h>

const u32 var70059c80[] = {0x46d10600};
const u32 var70059c84[] = {0x45f15800};
const u32 var70059c88[] = {0x45f15800};

GLOBAL_ASM(
glabel n_alResamplePull2
/*    45ab0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    45ab4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    45ab8:	afa40030 */ 	sw	$a0,0x30($sp)
/*    45abc:	afa50034 */ 	sw	$a1,0x34($sp)
/*    45ac0:	afa60038 */ 	sw	$a2,0x38($sp)
/*    45ac4:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    45ac8:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    45acc:	afae002c */ 	sw	$t6,0x2c($sp)
/*    45ad0:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    45ad4:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    45ad8:	0c011ea4 */ 	jal	func00047a90
/*    45adc:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*    45ae0:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    45ae4:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    45ae8:	91f8008c */ 	lbu	$t8,0x8c($t7)
/*    45aec:	1300006a */ 	beqz	$t8,.L00045c98
/*    45af0:	00000000 */ 	nop
/*    45af4:	2b010040 */ 	slti	$at,$t8,0x40
/*    45af8:	10200067 */ 	beqz	$at,.L00045c98
/*    45afc:	00000000 */ 	nop
/*    45b00:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    45b04:	9328008c */ 	lbu	$t0,0x8c($t9)
/*    45b08:	29010006 */ 	slti	$at,$t0,0x6
/*    45b0c:	14200013 */ 	bnez	$at,.L00045b5c
/*    45b10:	00000000 */ 	nop
/*    45b14:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    45b18:	912a008c */ 	lbu	$t2,0x8c($t1)
/*    45b1c:	448a2000 */ 	mtc1	$t2,$f4
/*    45b20:	05410005 */ 	bgez	$t2,.L00045b38
/*    45b24:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    45b28:	3c014f80 */ 	lui	$at,0x4f80
/*    45b2c:	44814000 */ 	mtc1	$at,$f8
/*    45b30:	00000000 */ 	nop
/*    45b34:	46083180 */ 	add.s	$f6,$f6,$f8
.L00045b38:
/*    45b38:	3c013f80 */ 	lui	$at,0x3f80
/*    45b3c:	44815000 */ 	mtc1	$at,$f10
/*    45b40:	0c012974 */ 	jal	sqrtf
/*    45b44:	460a3300 */ 	add.s	$f12,$f6,$f10
/*    45b48:	3c017006 */ 	lui	$at,%hi(var70059c80)
/*    45b4c:	c4309c80 */ 	lwc1	$f16,%lo(var70059c80)($at)
/*    45b50:	46008483 */ 	div.s	$f18,$f16,$f0
/*    45b54:	10000011 */ 	b	.L00045b9c
/*    45b58:	e7b20028 */ 	swc1	$f18,0x28($sp)
.L00045b5c:
/*    45b5c:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    45b60:	916c008c */ 	lbu	$t4,0x8c($t3)
/*    45b64:	448c2000 */ 	mtc1	$t4,$f4
/*    45b68:	05810005 */ 	bgez	$t4,.L00045b80
/*    45b6c:	46802220 */ 	cvt.s.w	$f8,$f4
/*    45b70:	3c014f80 */ 	lui	$at,0x4f80
/*    45b74:	44813000 */ 	mtc1	$at,$f6
/*    45b78:	00000000 */ 	nop
/*    45b7c:	46064200 */ 	add.s	$f8,$f8,$f6
.L00045b80:
/*    45b80:	3c013f80 */ 	lui	$at,0x3f80
/*    45b84:	44815000 */ 	mtc1	$at,$f10
/*    45b88:	3c014780 */ 	lui	$at,0x4780
/*    45b8c:	44819000 */ 	mtc1	$at,$f18
/*    45b90:	460a4400 */ 	add.s	$f16,$f8,$f10
/*    45b94:	46109103 */ 	div.s	$f4,$f18,$f16
/*    45b98:	e7a40028 */ 	swc1	$f4,0x28($sp)
.L00045b9c:
/*    45b9c:	3c017006 */ 	lui	$at,%hi(var70059c84)
/*    45ba0:	c4289c84 */ 	lwc1	$f8,%lo(var70059c84)($at)
/*    45ba4:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*    45ba8:	4608303c */ 	c.lt.s	$f6,$f8
/*    45bac:	00000000 */ 	nop
/*    45bb0:	45000004 */ 	bc1f	.L00045bc4
/*    45bb4:	00000000 */ 	nop
/*    45bb8:	3c017006 */ 	lui	$at,%hi(var70059c88)
/*    45bbc:	c42a9c88 */ 	lwc1	$f10,%lo(var70059c88)($at)
/*    45bc0:	e7aa0028 */ 	swc1	$f10,0x28($sp)
.L00045bc4:
/*    45bc4:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    45bc8:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*    45bcc:	afae002c */ 	sw	$t6,0x2c($sp)
/*    45bd0:	afad0024 */ 	sw	$t5,0x24($sp)
/*    45bd4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    45bd8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    45bdc:	85f80000 */ 	lh	$t8,0x0($t7)
/*    45be0:	3319ffff */ 	andi	$t9,$t8,0xffff
/*    45be4:	ad190000 */ 	sw	$t9,0x0($t0)
/*    45be8:	4449f800 */ 	cfc1	$t1,$31
/*    45bec:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    45bf0:	44caf800 */ 	ctc1	$t2,$31
/*    45bf4:	c7b20028 */ 	lwc1	$f18,0x28($sp)
/*    45bf8:	46009424 */ 	cvt.w.s	$f16,$f18
/*    45bfc:	444af800 */ 	cfc1	$t2,$31
/*    45c00:	00000000 */ 	nop
/*    45c04:	31410004 */ 	andi	$at,$t2,0x4
/*    45c08:	314a0078 */ 	andi	$t2,$t2,0x78
/*    45c0c:	11400014 */ 	beqz	$t2,.L00045c60
/*    45c10:	00000000 */ 	nop
/*    45c14:	3c014f00 */ 	lui	$at,0x4f00
/*    45c18:	44818000 */ 	mtc1	$at,$f16
/*    45c1c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    45c20:	46109401 */ 	sub.s	$f16,$f18,$f16
/*    45c24:	44caf800 */ 	ctc1	$t2,$31
/*    45c28:	00000000 */ 	nop
/*    45c2c:	46008424 */ 	cvt.w.s	$f16,$f16
/*    45c30:	444af800 */ 	cfc1	$t2,$31
/*    45c34:	00000000 */ 	nop
/*    45c38:	31410004 */ 	andi	$at,$t2,0x4
/*    45c3c:	314a0078 */ 	andi	$t2,$t2,0x78
/*    45c40:	15400005 */ 	bnez	$t2,.L00045c58
/*    45c44:	00000000 */ 	nop
/*    45c48:	440a8000 */ 	mfc1	$t2,$f16
/*    45c4c:	3c018000 */ 	lui	$at,0x8000
/*    45c50:	10000007 */ 	b	.L00045c70
/*    45c54:	01415025 */ 	or	$t2,$t2,$at
.L00045c58:
/*    45c58:	10000005 */ 	b	.L00045c70
/*    45c5c:	240affff */ 	addiu	$t2,$zero,-1
.L00045c60:
/*    45c60:	440a8000 */ 	mfc1	$t2,$f16
/*    45c64:	00000000 */ 	nop
/*    45c68:	0540fffb */ 	bltz	$t2,.L00045c58
/*    45c6c:	00000000 */ 	nop
.L00045c70:
/*    45c70:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    45c74:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    45c78:	314bffff */ 	andi	$t3,$t2,0xffff
/*    45c7c:	91ae008c */ 	lbu	$t6,0x8c($t5)
/*    45c80:	000b6400 */ 	sll	$t4,$t3,0x10
/*    45c84:	44c9f800 */ 	ctc1	$t1,$31
/*    45c88:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    45c8c:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    45c90:	0198c825 */ 	or	$t9,$t4,$t8
/*    45c94:	ad190004 */ 	sw	$t9,0x4($t0)
.L00045c98:
/*    45c98:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    45c9c:	852a0092 */ 	lh	$t2,0x92($t1)
/*    45ca0:	19400039 */ 	blez	$t2,.L00045d88
/*    45ca4:	00000000 */ 	nop
/*    45ca8:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    45cac:	8d6d00b8 */ 	lw	$t5,0xb8($t3)
/*    45cb0:	11a00006 */ 	beqz	$t5,.L00045ccc
/*    45cb4:	00000000 */ 	nop
/*    45cb8:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    45cbc:	3c0546ac */ 	lui	$a1,0x46ac
/*    45cc0:	34a54400 */ 	ori	$a1,$a1,0x4400
/*    45cc4:	0c00ee99 */ 	jal	func0003ba64
/*    45cc8:	24840090 */ 	addiu	$a0,$a0,0x90
.L00045ccc:
/*    45ccc:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    45cd0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*    45cd4:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    45cd8:	afae0020 */ 	sw	$t6,0x20($sp)
/*    45cdc:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    45ce0:	3c0c0b00 */ 	lui	$t4,0xb00
/*    45ce4:	358c0020 */ 	ori	$t4,$t4,0x20
/*    45ce8:	af0c0000 */ 	sw	$t4,0x0($t8)
/*    45cec:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    45cf0:	0c012d20 */ 	jal	osVirtualToPhysical
/*    45cf4:	24840098 */ 	addiu	$a0,$a0,0x98
/*    45cf8:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    45cfc:	af220004 */ 	sw	$v0,0x4($t9)
/*    45d00:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    45d04:	24010002 */ 	addiu	$at,$zero,0x2
/*    45d08:	8d0900b8 */ 	lw	$t1,0xb8($t0)
/*    45d0c:	15210003 */ 	bne	$t1,$at,.L00045d1c
/*    45d10:	00000000 */ 	nop
/*    45d14:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    45d18:	ad4000b8 */ 	sw	$zero,0xb8($t2)
.L00045d1c:
/*    45d1c:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    45d20:	256d0008 */ 	addiu	$t5,$t3,0x8
/*    45d24:	afad002c */ 	sw	$t5,0x2c($sp)
/*    45d28:	afab001c */ 	sw	$t3,0x1c($sp)
/*    45d2c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    45d30:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    45d34:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    45d38:	8f1900b8 */ 	lw	$t9,0xb8($t8)
/*    45d3c:	85cf0000 */ 	lh	$t7,0x0($t6)
/*    45d40:	3c010e00 */ 	lui	$at,0xe00
/*    45d44:	332800ff */ 	andi	$t0,$t9,0xff
/*    45d48:	00084c00 */ 	sll	$t1,$t0,0x10
/*    45d4c:	01215025 */ 	or	$t2,$t1,$at
/*    45d50:	31ecffff */ 	andi	$t4,$t7,0xffff
/*    45d54:	018a5825 */ 	or	$t3,$t4,$t2
/*    45d58:	adab0000 */ 	sw	$t3,0x0($t5)
/*    45d5c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    45d60:	0c012d20 */ 	jal	osVirtualToPhysical
/*    45d64:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*    45d68:	3c0100ff */ 	lui	$at,0xff
/*    45d6c:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    45d70:	3421ffff */ 	ori	$at,$at,0xffff
/*    45d74:	00417824 */ 	and	$t7,$v0,$at
/*    45d78:	01e1c024 */ 	and	$t8,$t7,$at
/*    45d7c:	af380004 */ 	sw	$t8,0x4($t9)
/*    45d80:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    45d84:	ad0000b8 */ 	sw	$zero,0xb8($t0)
.L00045d88:
/*    45d88:	10000003 */ 	b	.L00045d98
/*    45d8c:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*    45d90:	10000001 */ 	b	.L00045d98
/*    45d94:	00000000 */ 	nop
.L00045d98:
/*    45d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    45d9c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    45da0:	03e00008 */ 	jr	$ra
/*    45da4:	00000000 */ 	nop
);

s32 n_alResampleParam2(N_PVoice *filter, s32 paramID, void *param)
{
	f32 *f = (f32 *) &param;

	switch (paramID) {
	case (AL_FILTER_RESET):
		filter->unk92 = 0;
		n_alLoadParam(filter, AL_FILTER_RESET, param);
		break;
	case (AL_FILTER_12):
		filter->unk92 = (s32) param;
		filter->unkb8 |= 2;
		break;
	case (AL_FILTER_13):
		filter->unk90 = *f;
		filter->unkb8 |= 2;
		break;
	case (AL_FILTER_11):
		filter->unk8c = (u8)param;
		break;
	default:
		n_alLoadParam(filter, paramID, param);
		break;
	}

	return 0;
}
