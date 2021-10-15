#include "n_synthInternals.h"
#include <os.h>

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
glabel n_alFxNew
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

void alN_PVoiceNew(N_PVoice *mv, ALDMANew dmaNew, ALHeap *hp)
{
	mv->dc_state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
	mv->dc_lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
	mv->dc_dma = dmaNew(&mv->dc_dmaState);
	mv->dc_lastsam = 0;
	mv->dc_first = 1;
	mv->dc_memin = 0;

	mv->rs_state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
	mv->rs_delta  = 0.0f;
	mv->rs_first  = 1;
	mv->rs_ratio = 1.0f;
	mv->rs_upitch = 0;

	mv->em_state = alHeapAlloc(hp, 1, sizeof(ENVMIX_STATE));
	mv->em_first = 1;
	mv->em_motion = AL_STOPPED;
	mv->em_volume = 1;
	mv->em_ltgt = 1;
	mv->em_rtgt = 1;
	mv->em_cvolL = 1;
	mv->em_cvolR = 1;
	mv->em_dryamt = 0;
	mv->em_wetamt = 0;
	mv->em_lratm = 1;
	mv->em_lratl = 0;
	mv->em_lratm = 1;
	mv->em_lratl = 0;
	mv->em_delta = 0;
	mv->em_segEnd = 0;
	mv->em_pan = 0;
	mv->em_ctrlList = 0;
	mv->em_ctrlTail = 0;
	mv->unk8c = 0;
	mv->unk92 = 0;
	mv->unk90 = 0;
	mv->unkbc = alHeapAlloc(hp, 1, 8);
	mv->unkb8 = 0;
}
