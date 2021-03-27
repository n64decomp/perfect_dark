#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3e730.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003c890
/*    3c890:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c894:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c898:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c89c:	0c012194 */ 	jal	osSetIntMask
/*    3c8a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c8a4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c8a8:	3c0e8006 */ 	lui	$t6,%hi(alGlobals)
/*    3c8ac:	8dcef114 */ 	lw	$t6,%lo(alGlobals)($t6)
/*    3c8b0:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c8b4:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3c8b8:	af0f0010 */ 	sw	$t7,0x10($t8)
/*    3c8bc:	3c198006 */ 	lui	$t9,%hi(alGlobals)
/*    3c8c0:	8f39f114 */ 	lw	$t9,%lo(alGlobals)($t9)
/*    3c8c4:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c8c8:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c8cc:	ad280000 */ 	sw	$t0,0x0($t1)
/*    3c8d0:	3c0b8006 */ 	lui	$t3,%hi(alGlobals)
/*    3c8d4:	8d6bf114 */ 	lw	$t3,%lo(alGlobals)($t3)
/*    3c8d8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c8dc:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3c8e0:	0c012194 */ 	jal	osSetIntMask
/*    3c8e4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c8e8:	10000001 */ 	b	.L0003c8f0
/*    3c8ec:	00000000 */ 	nop
.L0003c8f0:
/*    3c8f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c8f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c8f8:	03e00008 */ 	jr	$ra
/*    3c8fc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c900
/*    3c900:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c904:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c908:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c90c:	0c012194 */ 	jal	osSetIntMask
/*    3c910:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c914:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c918:	3c0e8006 */ 	lui	$t6,%hi(alGlobals)
/*    3c91c:	8dcef114 */ 	lw	$t6,%lo(alGlobals)($t6)
/*    3c920:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c924:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3c928:	af0f0010 */ 	sw	$t7,0x10($t8)
/*    3c92c:	3c198006 */ 	lui	$t9,%hi(alGlobals)
/*    3c930:	8f39f114 */ 	lw	$t9,%lo(alGlobals)($t9)
/*    3c934:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c938:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c93c:	ad280000 */ 	sw	$t0,0x0($t1)
/*    3c940:	3c0b8006 */ 	lui	$t3,%hi(alGlobals)
/*    3c944:	8d6bf114 */ 	lw	$t3,%lo(alGlobals)($t3)
/*    3c948:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c94c:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3c950:	0c012194 */ 	jal	osSetIntMask
/*    3c954:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c958:	10000001 */ 	b	.L0003c960
/*    3c95c:	00000000 */ 	nop
.L0003c960:
/*    3c960:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c964:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c968:	03e00008 */ 	jr	$ra
/*    3c96c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c970
/*    3c970:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c974:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c978:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c97c:	0c012194 */ 	jal	osSetIntMask
/*    3c980:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c984:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c988:	3c0e8006 */ 	lui	$t6,%hi(alGlobals)
/*    3c98c:	8dcef114 */ 	lw	$t6,%lo(alGlobals)($t6)
/*    3c990:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c994:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3c998:	af0f0010 */ 	sw	$t7,0x10($t8)
/*    3c99c:	3c198006 */ 	lui	$t9,%hi(alGlobals)
/*    3c9a0:	8f39f114 */ 	lw	$t9,%lo(alGlobals)($t9)
/*    3c9a4:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c9a8:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c9ac:	ad280000 */ 	sw	$t0,0x0($t1)
/*    3c9b0:	3c0b8006 */ 	lui	$t3,%hi(alGlobals)
/*    3c9b4:	8d6bf114 */ 	lw	$t3,%lo(alGlobals)($t3)
/*    3c9b8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c9bc:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3c9c0:	0c012194 */ 	jal	osSetIntMask
/*    3c9c4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c9c8:	10000001 */ 	b	.L0003c9d0
/*    3c9cc:	00000000 */ 	nop
.L0003c9d0:
/*    3c9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c9d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c9d8:	03e00008 */ 	jr	$ra
/*    3c9dc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c9e0
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
/*    3ca44:	0c00f2ed */ 	jal	func0003cbb4
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
/*    3ca98:	0c00c541 */ 	jal	func00031504
/*    3ca9c:	00000000 */ 	nop
/*    3caa0:	afa20020 */ 	sw	$v0,0x20($sp)
/*    3caa4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3caa8:	13200015 */ 	beqz	$t9,.L0003cb00
/*    3caac:	00000000 */ 	nop
/*    3cab0:	3c088006 */ 	lui	$t0,%hi(alGlobals)
/*    3cab4:	8d08f114 */ 	lw	$t0,%lo(alGlobals)($t0)
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
/*    3caf0:	0c00fc79 */ 	jal	func0003f1e4
/*    3caf4:	8f040008 */ 	lw	$a0,0x8($t8)
/*    3caf8:	10000001 */ 	b	.L0003cb00
/*    3cafc:	00000000 */ 	nop
.L0003cb00:
/*    3cb00:	0c00c541 */ 	jal	func00031504
/*    3cb04:	00000000 */ 	nop
/*    3cb08:	afa20020 */ 	sw	$v0,0x20($sp)
/*    3cb0c:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3cb10:	13200015 */ 	beqz	$t9,.L0003cb68
/*    3cb14:	00000000 */ 	nop
/*    3cb18:	3c088006 */ 	lui	$t0,%hi(alGlobals)
/*    3cb1c:	8d08f114 */ 	lw	$t0,%lo(alGlobals)($t0)
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
/*    3cb58:	0c00fc79 */ 	jal	func0003f1e4
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

GLOBAL_ASM(
glabel func0003cbb4
/*    3cbb4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3cbb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3cbbc:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3cbc0:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3cbc4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    3cbc8:	3c0e8006 */ 	lui	$t6,%hi(alGlobals)
/*    3cbcc:	8dcef114 */ 	lw	$t6,%lo(alGlobals)($t6)
/*    3cbd0:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*    3cbd4:	11e0000d */ 	beqz	$t7,.L0003cc0c
/*    3cbd8:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    3cbdc:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3cbe0:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3cbe4:	af380000 */ 	sw	$t8,0x0($t9)
/*    3cbe8:	0c00c5e9 */ 	jal	alUnlink
/*    3cbec:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cbf0:	3c058006 */ 	lui	$a1,%hi(alGlobals)
/*    3cbf4:	8ca5f114 */ 	lw	$a1,%lo(alGlobals)($a1)
/*    3cbf8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cbfc:	0c00c5dc */ 	jal	alLink
/*    3cc00:	24a5000c */ 	addiu	$a1,$a1,12
/*    3cc04:	10000030 */ 	b	.L0003ccc8
/*    3cc08:	00000000 */ 	nop
.L0003cc0c:
/*    3cc0c:	3c088006 */ 	lui	$t0,%hi(alGlobals)
/*    3cc10:	8d08f114 */ 	lw	$t0,%lo(alGlobals)($t0)
/*    3cc14:	8d090004 */ 	lw	$t1,0x4($t0)
/*    3cc18:	1120000d */ 	beqz	$t1,.L0003cc50
/*    3cc1c:	afa90024 */ 	sw	$t1,0x24($sp)
/*    3cc20:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3cc24:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3cc28:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3cc2c:	0c00c5e9 */ 	jal	alUnlink
/*    3cc30:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cc34:	3c058006 */ 	lui	$a1,%hi(alGlobals)
/*    3cc38:	8ca5f114 */ 	lw	$a1,%lo(alGlobals)($a1)
/*    3cc3c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cc40:	0c00c5dc */ 	jal	alLink
/*    3cc44:	24a5000c */ 	addiu	$a1,$a1,12
/*    3cc48:	1000001f */ 	b	.L0003ccc8
/*    3cc4c:	00000000 */ 	nop
.L0003cc50:
/*    3cc50:	3c0c8006 */ 	lui	$t4,%hi(alGlobals)
/*    3cc54:	8d8cf114 */ 	lw	$t4,%lo(alGlobals)($t4)
/*    3cc58:	8d8d000c */ 	lw	$t5,0xc($t4)
/*    3cc5c:	11a0001a */ 	beqz	$t5,.L0003ccc8
/*    3cc60:	afad0024 */ 	sw	$t5,0x24($sp)
.L0003cc64:
/*    3cc64:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3cc68:	afae0020 */ 	sw	$t6,0x20($sp)
/*    3cc6c:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cc70:	87a8002e */ 	lh	$t0,0x2e($sp)
/*    3cc74:	8df80008 */ 	lw	$t8,0x8($t7)
/*    3cc78:	87190016 */ 	lh	$t9,0x16($t8)
/*    3cc7c:	0119082a */ 	slt	$at,$t0,$t9
/*    3cc80:	1420000d */ 	bnez	$at,.L0003ccb8
/*    3cc84:	00000000 */ 	nop
/*    3cc88:	8de90088 */ 	lw	$t1,0x88($t7)
/*    3cc8c:	1520000a */ 	bnez	$t1,.L0003ccb8
/*    3cc90:	00000000 */ 	nop
/*    3cc94:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3cc98:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3cc9c:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3cca0:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3cca4:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    3cca8:	85ae0016 */ 	lh	$t6,0x16($t5)
/*    3ccac:	a7ae002e */ 	sh	$t6,0x2e($sp)
/*    3ccb0:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3ccb4:	afb8001c */ 	sw	$t8,0x1c($sp)
.L0003ccb8:
/*    3ccb8:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3ccbc:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3ccc0:	1500ffe8 */ 	bnez	$t0,.L0003cc64
/*    3ccc4:	afa80024 */ 	sw	$t0,0x24($sp)
.L0003ccc8:
/*    3ccc8:	10000003 */ 	b	.L0003ccd8
/*    3cccc:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    3ccd0:	10000001 */ 	b	.L0003ccd8
/*    3ccd4:	00000000 */ 	nop
.L0003ccd8:
/*    3ccd8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3ccdc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3cce0:	03e00008 */ 	jr	$ra
/*    3cce4:	00000000 */ 	nop
);
