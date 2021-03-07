#include <ultra64.h>
#include "constants.h"
#include "game/game_005fd0.h"
#include "game/game_0d4690.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

const u32 var7f1b7410[] = {0x7f7fffff};
const u32 var7f1b7414[] = {0x7f7fffff};

GLOBAL_ASM(
glabel func0f1577f0
/*  f1577f0:	c4ce0000 */ 	lwc1	$f14,0x0($a2)
/*  f1577f4:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f1577f8:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f1577fc:	c4c20004 */ 	lwc1	$f2,0x4($a2)
/*  f157800:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f157804:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f157808:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15780c:	460e3301 */ 	sub.s	$f12,$f6,$f14
/*  f157810:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*  f157814:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*  f157818:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f15781c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157820:	46127281 */ 	sub.s	$f10,$f14,$f18
/*  f157824:	46061201 */ 	sub.s	$f8,$f2,$f6
/*  f157828:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f15782c:	00000000 */ 	nop
/*  f157830:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f157834:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f157838:	460a2400 */ 	add.s	$f16,$f4,$f10
/*  f15783c:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f157840:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f157844:	46124181 */ 	sub.s	$f6,$f8,$f18
/*  f157848:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f15784c:	00000000 */ 	nop
/*  f157850:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f157854:	44803000 */ 	mtc1	$zero,$f6
/*  f157858:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f15785c:	46064032 */ 	c.eq.s	$f8,$f6
/*  f157860:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f157864:	c7a40010 */ 	lwc1	$f4,0x10($sp)
/*  f157868:	45000004 */ 	bc1f	.L0f15787c
/*  f15786c:	00000000 */ 	nop
/*  f157870:	44810000 */ 	mtc1	$at,$f0
/*  f157874:	10000012 */ 	b	.L0f1578c0
/*  f157878:	00000000 */ 	nop
.L0f15787c:
/*  f15787c:	46048403 */ 	div.s	$f16,$f16,$f4
/*  f157880:	44805000 */ 	mtc1	$zero,$f10
/*  f157884:	3c013f80 */ 	lui	$at,0x3f80
/*  f157888:	460a803c */ 	c.lt.s	$f16,$f10
/*  f15788c:	00000000 */ 	nop
/*  f157890:	45030007 */ 	bc1tl	.L0f1578b0
/*  f157894:	3c013f80 */ 	lui	$at,0x3f80
/*  f157898:	44814000 */ 	mtc1	$at,$f8
/*  f15789c:	00000000 */ 	nop
/*  f1578a0:	4610403c */ 	c.lt.s	$f8,$f16
/*  f1578a4:	00000000 */ 	nop
/*  f1578a8:	45000004 */ 	bc1f	.L0f1578bc
/*  f1578ac:	3c013f80 */ 	lui	$at,0x3f80
.L0f1578b0:
/*  f1578b0:	44810000 */ 	mtc1	$at,$f0
/*  f1578b4:	10000002 */ 	b	.L0f1578c0
/*  f1578b8:	00000000 */ 	nop
.L0f1578bc:
/*  f1578bc:	46008006 */ 	mov.s	$f0,$f16
.L0f1578c0:
/*  f1578c0:	03e00008 */ 	jr	$ra
/*  f1578c4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f1578c8
/*  f1578c8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1578cc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1578d0:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f1578d4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f1578d8:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f1578dc:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f1578e0:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f1578e4:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f1578e8:	c4ae0000 */ 	lwc1	$f14,0x0($a1)
/*  f1578ec:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f1578f0:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f1578f4:	460c7102 */ 	mul.s	$f4,$f14,$f12
/*  f1578f8:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f1578fc:	3c017f1b */ 	lui	$at,%hi(var7f1b7410)
/*  f157900:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f157904:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f157908:	46007202 */ 	mul.s	$f8,$f14,$f0
/*  f15790c:	00000000 */ 	nop
/*  f157910:	46106282 */ 	mul.s	$f10,$f12,$f16
/*  f157914:	46149101 */ 	sub.s	$f4,$f18,$f20
/*  f157918:	46149180 */ 	add.s	$f6,$f18,$f20
/*  f15791c:	460a4080 */ 	add.s	$f2,$f8,$f10
/*  f157920:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f157924:	44805000 */ 	mtc1	$zero,$f10
/*  f157928:	00000000 */ 	nop
/*  f15792c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f157930:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f157934:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f157938:	45000003 */ 	bc1f	.L0f157948
/*  f15793c:	00000000 */ 	nop
/*  f157940:	1000001d */ 	b	.L0f1579b8
/*  f157944:	c4207410 */ 	lwc1	$f0,%lo(var7f1b7410)($at)
.L0f157948:
/*  f157948:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f15794c:	0c012974 */ 	jal	sqrtf
/*  f157950:	e7a2002c */ 	swc1	$f2,0x2c($sp)
/*  f157954:	c7a2002c */ 	lwc1	$f2,0x2c($sp)
/*  f157958:	44806000 */ 	mtc1	$zero,$f12
/*  f15795c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f157960:	46001081 */ 	sub.s	$f2,$f2,$f0
/*  f157964:	460c103c */ 	c.lt.s	$f2,$f12
/*  f157968:	00000000 */ 	nop
/*  f15796c:	45020012 */ 	bc1fl	.L0f1579b8
/*  f157970:	46001006 */ 	mov.s	$f0,$f2
/*  f157974:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f157978:	3c017f1b */ 	lui	$at,%hi(var7f1b7414)
/*  f15797c:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f157980:	00000000 */ 	nop
/*  f157984:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f157988:	00000000 */ 	nop
/*  f15798c:	4614a202 */ 	mul.s	$f8,$f20,$f20
/*  f157990:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f157994:	4604503e */ 	c.le.s	$f10,$f4
/*  f157998:	00000000 */ 	nop
/*  f15799c:	45000003 */ 	bc1f	.L0f1579ac
/*  f1579a0:	00000000 */ 	nop
/*  f1579a4:	10000004 */ 	b	.L0f1579b8
/*  f1579a8:	46006006 */ 	mov.s	$f0,$f12
.L0f1579ac:
/*  f1579ac:	10000002 */ 	b	.L0f1579b8
/*  f1579b0:	c4207414 */ 	lwc1	$f0,%lo(var7f1b7414)($at)
/*  f1579b4:	46001006 */ 	mov.s	$f0,$f2
.L0f1579b8:
/*  f1579b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1579bc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f1579c0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1579c4:	03e00008 */ 	jr	$ra
/*  f1579c8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1579cc
/*  f1579cc:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f1579d0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1579d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1579d8:	afa600b8 */ 	sw	$a2,0xb8($sp)
/*  f1579dc:	c4e00000 */ 	lwc1	$f0,0x0($a3)
/*  f1579e0:	c4e20004 */ 	lwc1	$f2,0x4($a3)
/*  f1579e4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f1579e8:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f1579ec:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f1579f0:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f1579f4:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f1579f8:	0c012974 */ 	jal	sqrtf
/*  f1579fc:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f157a00:	44803000 */ 	mtc1	$zero,$f6
/*  f157a04:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157a08:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f157a0c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f157a10:	46000386 */ 	mov.s	$f14,$f0
/*  f157a14:	3c013f80 */ 	lui	$at,0x3f80
/*  f157a18:	45020006 */ 	bc1fl	.L0f157a34
/*  f157a1c:	44814000 */ 	mtc1	$at,$f8
/*  f157a20:	3c013f80 */ 	lui	$at,0x3f80
/*  f157a24:	44810000 */ 	mtc1	$at,$f0
/*  f157a28:	100000dc */ 	b	.L0f157d9c
/*  f157a2c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157a30:	44814000 */ 	mtc1	$at,$f8
.L0f157a34:
/*  f157a34:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f157a38:	8fa200b8 */ 	lw	$v0,0xb8($sp)
/*  f157a3c:	460e4403 */ 	div.s	$f16,$f8,$f14
/*  f157a40:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f157a44:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f157a48:	c4e60004 */ 	lwc1	$f6,0x4($a3)
/*  f157a4c:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f157a50:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
/*  f157a54:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f157a58:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f157a5c:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f157a60:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f157a64:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f157a68:	e7b00044 */ 	swc1	$f16,0x44($sp)
/*  f157a6c:	e7ae00ac */ 	swc1	$f14,0xac($sp)
/*  f157a70:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f157a74:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f157a78:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f157a7c:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f157a80:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f157a84:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f157a88:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f157a8c:	0c012974 */ 	jal	sqrtf
/*  f157a90:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f157a94:	44803000 */ 	mtc1	$zero,$f6
/*  f157a98:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157a9c:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f157aa0:	46060032 */ 	c.eq.s	$f0,$f6
/*  f157aa4:	3c013f80 */ 	lui	$at,0x3f80
/*  f157aa8:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157aac:	45010077 */ 	bc1t	.L0f157c8c
/*  f157ab0:	00000000 */ 	nop
/*  f157ab4:	44814000 */ 	mtc1	$at,$f8
/*  f157ab8:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f157abc:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f157ac0:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f157ac4:	02001025 */ 	or	$v0,$s0,$zero
/*  f157ac8:	46003207 */ 	neg.s	$f8,$f6
/*  f157acc:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f157ad0:	00000000 */ 	nop
/*  f157ad4:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f157ad8:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*  f157adc:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f157ae0:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f157ae4:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f157ae8:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f157aec:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f157af0:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*  f157af4:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f157af8:	460a4382 */ 	mul.s	$f14,$f8,$f10
/*  f157afc:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f157b00:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f157b04:	46044402 */ 	mul.s	$f16,$f8,$f4
/*  f157b08:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f157b0c:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f157b10:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f157b14:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f157b18:	46024101 */ 	sub.s	$f4,$f8,$f2
/*  f157b1c:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f157b20:	460c5201 */ 	sub.s	$f8,$f10,$f12
/*  f157b24:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f157b28:	00000000 */ 	nop
/*  f157b2c:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f157b30:	44804000 */ 	mtc1	$zero,$f8
/*  f157b34:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f157b38:	4608503c */ 	c.lt.s	$f10,$f8
/*  f157b3c:	00000000 */ 	nop
/*  f157b40:	45000003 */ 	bc1f	.L0f157b50
/*  f157b44:	00000000 */ 	nop
/*  f157b48:	46007387 */ 	neg.s	$f14,$f14
/*  f157b4c:	46008407 */ 	neg.s	$f16,$f16
.L0f157b50:
/*  f157b50:	460e1180 */ 	add.s	$f6,$f2,$f14
/*  f157b54:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f157b58:	46106100 */ 	add.s	$f4,$f12,$f16
/*  f157b5c:	e7a60078 */ 	swc1	$f6,0x78($sp)
/*  f157b60:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f157b64:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f157b68:	460e5200 */ 	add.s	$f8,$f10,$f14
/*  f157b6c:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f157b70:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f157b74:	46103100 */ 	add.s	$f4,$f6,$f16
/*  f157b78:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f157b7c:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f157b80:	c4ea0004 */ 	lwc1	$f10,0x4($a3)
/*  f157b84:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f157b88:	e7aa0048 */ 	swc1	$f10,0x48($sp)
/*  f157b8c:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*  f157b90:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f157b94:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f157b98:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f157b9c:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f157ba0:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f157ba4:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f157ba8:	46044202 */ 	mul.s	$f8,$f8,$f4
/*  f157bac:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f157bb0:	46085281 */ 	sub.s	$f10,$f10,$f8
/*  f157bb4:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f157bb8:	e7aa0068 */ 	swc1	$f10,0x68($sp)
/*  f157bbc:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f157bc0:	46064202 */ 	mul.s	$f8,$f8,$f6
/*  f157bc4:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*  f157bc8:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*  f157bcc:	46044381 */ 	sub.s	$f14,$f8,$f4
/*  f157bd0:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f157bd4:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f157bd8:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f157bdc:	e7ae006c */ 	swc1	$f14,0x6c($sp)
/*  f157be0:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*  f157be4:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f157be8:	46005306 */ 	mov.s	$f12,$f10
/*  f157bec:	46043481 */ 	sub.s	$f18,$f6,$f4
/*  f157bf0:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f157bf4:	460a903c */ 	c.lt.s	$f18,$f10
/*  f157bf8:	00000000 */ 	nop
/*  f157bfc:	4502000a */ 	bc1fl	.L0f157c28
/*  f157c00:	460c9032 */ 	c.eq.s	$f18,$f12
/*  f157c04:	46008407 */ 	neg.s	$f16,$f16
/*  f157c08:	46003107 */ 	neg.s	$f4,$f6
/*  f157c0c:	46009306 */ 	mov.s	$f12,$f18
/*  f157c10:	00608025 */ 	or	$s0,$v1,$zero
/*  f157c14:	46005486 */ 	mov.s	$f18,$f10
/*  f157c18:	00401825 */ 	or	$v1,$v0,$zero
/*  f157c1c:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f157c20:	e7b00088 */ 	swc1	$f16,0x88($sp)
/*  f157c24:	460c9032 */ 	c.eq.s	$f18,$f12
.L0f157c28:
/*  f157c28:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f157c2c:	02003025 */ 	or	$a2,$s0,$zero
/*  f157c30:	45020012 */ 	bc1fl	.L0f157c7c
/*  f157c34:	460e903c */ 	c.lt.s	$f18,$f14
/*  f157c38:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157c3c:	afa300b8 */ 	sw	$v1,0xb8($sp)
/*  f157c40:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c44:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f157c48:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157c4c:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157c50:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f157c54:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c58:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f157c5c:	c7a20060 */ 	lwc1	$f2,0x60($sp)
/*  f157c60:	4602003c */ 	c.lt.s	$f0,$f2
/*  f157c64:	00000000 */ 	nop
/*  f157c68:	45020038 */ 	bc1fl	.L0f157d4c
/*  f157c6c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f157c70:	10000035 */ 	b	.L0f157d48
/*  f157c74:	46000086 */ 	mov.s	$f2,$f0
/*  f157c78:	460e903c */ 	c.lt.s	$f18,$f14
.L0f157c7c:
/*  f157c7c:	00000000 */ 	nop
/*  f157c80:	45020007 */ 	bc1fl	.L0f157ca0
/*  f157c84:	460c703c */ 	c.lt.s	$f14,$f12
/*  f157c88:	afa300b8 */ 	sw	$v1,0xb8($sp)
.L0f157c8c:
/*  f157c8c:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c90:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f157c94:	1000002c */ 	b	.L0f157d48
/*  f157c98:	46000086 */ 	mov.s	$f2,$f0
/*  f157c9c:	460c703c */ 	c.lt.s	$f14,$f12
.L0f157ca0:
/*  f157ca0:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157ca4:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f157ca8:	45020006 */ 	bc1fl	.L0f157cc4
/*  f157cac:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f157cb0:	0fc55e32 */ 	jal	func0f1578c8
/*  f157cb4:	02003025 */ 	or	$a2,$s0,$zero
/*  f157cb8:	10000023 */ 	b	.L0f157d48
/*  f157cbc:	46000086 */ 	mov.s	$f2,$f0
/*  f157cc0:	c60c0004 */ 	lwc1	$f12,0x4($s0)
.L0f157cc4:
/*  f157cc4:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*  f157cc8:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f157ccc:	460c4181 */ 	sub.s	$f6,$f8,$f12
/*  f157cd0:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f157cd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f157cd8:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f157cdc:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f157ce0:	46023281 */ 	sub.s	$f10,$f6,$f2
/*  f157ce4:	46105282 */ 	mul.s	$f10,$f10,$f16
/*  f157ce8:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f157cec:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f157cf0:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f157cf4:	46022181 */ 	sub.s	$f6,$f4,$f2
/*  f157cf8:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f157cfc:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f157d00:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f157d04:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*  f157d08:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*  f157d0c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f157d10:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f157d14:	46065380 */ 	add.s	$f14,$f10,$f6
/*  f157d18:	460e0032 */ 	c.eq.s	$f0,$f14
/*  f157d1c:	00000000 */ 	nop
/*  f157d20:	45020005 */ 	bc1fl	.L0f157d38
/*  f157d24:	46040201 */ 	sub.s	$f8,$f0,$f4
/*  f157d28:	44810000 */ 	mtc1	$at,$f0
/*  f157d2c:	1000001b */ 	b	.L0f157d9c
/*  f157d30:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157d34:	46040201 */ 	sub.s	$f8,$f0,$f4
.L0f157d38:
/*  f157d38:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f157d3c:	460e0101 */ 	sub.s	$f4,$f0,$f14
/*  f157d40:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f157d44:	46043083 */ 	div.s	$f2,$f6,$f4
.L0f157d48:
/*  f157d48:	c7a800ac */ 	lwc1	$f8,0xac($sp)
.L0f157d4c:
/*  f157d4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157d50:	4602403c */ 	c.lt.s	$f8,$f2
/*  f157d54:	00000000 */ 	nop
/*  f157d58:	45020005 */ 	bc1fl	.L0f157d70
/*  f157d5c:	44805000 */ 	mtc1	$zero,$f10
/*  f157d60:	44810000 */ 	mtc1	$at,$f0
/*  f157d64:	1000000d */ 	b	.L0f157d9c
/*  f157d68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157d6c:	44805000 */ 	mtc1	$zero,$f10
.L0f157d70:
/*  f157d70:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f157d74:	460a103c */ 	c.lt.s	$f2,$f10
/*  f157d78:	00000000 */ 	nop
/*  f157d7c:	45000004 */ 	bc1f	.L0f157d90
/*  f157d80:	00000000 */ 	nop
/*  f157d84:	44800000 */ 	mtc1	$zero,$f0
/*  f157d88:	10000004 */ 	b	.L0f157d9c
/*  f157d8c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f157d90:
/*  f157d90:	46061002 */ 	mul.s	$f0,$f2,$f6
/*  f157d94:	00000000 */ 	nop
/*  f157d98:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f157d9c:
/*  f157d9c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f157da0:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f157da4:	03e00008 */ 	jr	$ra
/*  f157da8:	00000000 */ 	nop
/*  f157dac:	00000000 */ 	nop
);
