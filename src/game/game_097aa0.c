#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_097a50.h"
#include "game/game_097aa0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f097aa0
/*  f097aa0:	3c013f80 */ 	lui	$at,0x3f80
/*  f097aa4:	44819000 */ 	mtc1	$at,$f18
/*  f097aa8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f097aac:	f7b80018 */ 	sdc1	$f24,0x18($sp)
/*  f097ab0:	46126101 */ 	sub.s	$f4,$f12,$f18
/*  f097ab4:	f7b60010 */ 	sdc1	$f22,0x10($sp)
/*  f097ab8:	3c014000 */ 	lui	$at,0x4000
/*  f097abc:	46126180 */ 	add.s	$f6,$f12,$f18
/*  f097ac0:	44808000 */ 	mtc1	$zero,$f16
/*  f097ac4:	4481b000 */ 	mtc1	$at,$f22
/*  f097ac8:	4480c000 */ 	mtc1	$zero,$f24
/*  f097acc:	46062003 */ 	div.s	$f0,$f4,$f6
/*  f097ad0:	f7b40008 */ 	sdc1	$f20,0x8($sp)
/*  f097ad4:	46000382 */ 	mul.s	$f14,$f0,$f0
/*  f097ad8:	46000086 */ 	mov.s	$f2,$f0
/*  f097adc:	46120503 */ 	div.s	$f20,$f0,$f18
.L0f097ae0:
/*  f097ae0:	460e1082 */ 	mul.s	$f2,$f2,$f14
/*  f097ae4:	46169480 */ 	add.s	$f18,$f18,$f22
/*  f097ae8:	4618a032 */ 	c.eq.s	$f20,$f24
/*  f097aec:	46148400 */ 	add.s	$f16,$f16,$f20
/*  f097af0:	4502fffb */ 	bc1fl	.L0f097ae0
/*  f097af4:	46120503 */ 	div.s	$f20,$f0,$f18
/*  f097af8:	d7b40008 */ 	ldc1	$f20,0x8($sp)
/*  f097afc:	d7b60010 */ 	ldc1	$f22,0x10($sp)
/*  f097b00:	d7b80018 */ 	ldc1	$f24,0x18($sp)
/*  f097b04:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f097b08:	03e00008 */ 	jr	$ra
/*  f097b0c:	46108000 */ 	add.s	$f0,$f16,$f16
/*  f097b10:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f097b14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097b18:	0fc25ea8 */ 	jal	func0f097aa0
/*  f097b1c:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f097b20:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f097b24:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f097b28:	0fc25e94 */ 	jal	func0f097a50
/*  f097b2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097b30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f097b34:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f097b38:	03e00008 */ 	jr	$ra
/*  f097b3c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097b40
/*  f097b40:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f097b44:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f097b48:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f097b4c:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f097b50:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f097b54:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f097b58:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f097b5c:	03e00008 */ 	jr	$ra
/*  f097b60:	e4d20004 */ 	swc1	$f18,0x4($a2)
);

GLOBAL_ASM(
glabel func0f097b64
/*  f097b64:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f097b68:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f097b6c:	44866000 */ 	mtc1	$a2,$f12
/*  f097b70:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f097b74:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f097b78:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f097b7c:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*  f097b80:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f097b84:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*  f097b88:	46028481 */ 	sub.s	$f18,$f16,$f2
/*  f097b8c:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f097b90:	46041180 */ 	add.s	$f6,$f2,$f4
/*  f097b94:	03e00008 */ 	jr	$ra
/*  f097b98:	e4e60004 */ 	swc1	$f6,0x4($a3)
/*  f097b9c:	00000000 */ 	sll	$zero,$zero,0x0
);
