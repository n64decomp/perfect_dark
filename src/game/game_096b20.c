#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f096b20
/*  f096b20:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f096b24:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f096b28:	44866000 */ 	mtc1	$a2,$f12
/*  f096b2c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f096b30:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f096b34:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f096b38:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*  f096b3c:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f096b40:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*  f096b44:	46028481 */ 	sub.s	$f18,$f16,$f2
/*  f096b48:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f096b4c:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f096b50:	e4e60004 */ 	swc1	$f6,0x4($a3)
/*  f096b54:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*  f096b58:	c48e0008 */ 	lwc1	$f14,0x8($a0)
/*  f096b5c:	460e4281 */ 	sub.s	$f10,$f8,$f14
/*  f096b60:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f096b64:	460e8480 */ 	add.s	$f18,$f16,$f14
/*  f096b68:	03e00008 */ 	jr	$ra
/*  f096b6c:	e4f20008 */ 	swc1	$f18,0x8($a3)
);

GLOBAL_ASM(
glabel func0f096b70
/*  f096b70:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f096b74:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*  f096b78:	3c013f00 */ 	lui	$at,0x3f00
/*  f096b7c:	44813000 */ 	mtc1	$at,$f6
/*  f096b80:	460c6002 */ 	mul.s	$f0,$f12,$f12
/*  f096b84:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f096b88:	460c0082 */ 	mul.s	$f2,$f0,$f12
/*  f096b8c:	46001101 */ 	sub.s	$f4,$f2,$f0
/*  f096b90:	46026280 */ 	add.s	$f10,$f12,$f2
/*  f096b94:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f096b98:	44812000 */ 	mtc1	$at,$f4
/*  f096b9c:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f096ba0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f096ba4:	44815000 */ 	mtc1	$at,$f10
/*  f096ba8:	3c014020 */ 	lui	$at,0x4020
/*  f096bac:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*  f096bb0:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f096bb4:	46060381 */ 	sub.s	$f14,$f0,$f6
/*  f096bb8:	44813000 */ 	mtc1	$at,$f6
/*  f096bbc:	3c013f80 */ 	lui	$at,0x3f80
/*  f096bc0:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f096bc4:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f096bc8:	44812000 */ 	mtc1	$at,$f4
/*  f096bcc:	3c01bfc0 */ 	lui	$at,0xbfc0
/*  f096bd0:	44815000 */ 	mtc1	$at,$f10
/*  f096bd4:	46043400 */ 	add.s	$f16,$f6,$f4
/*  f096bd8:	3c013f00 */ 	lui	$at,0x3f00
/*  f096bdc:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f096be0:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f096be4:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f096be8:	44813000 */ 	mtc1	$at,$f6
/*  f096bec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096bf0:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*  f096bf4:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f096bf8:	46045480 */ 	add.s	$f18,$f10,$f4
/*  f096bfc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f096c00:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f096c04:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f096c08:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f096c0c:	46048102 */ 	mul.s	$f4,$f16,$f4
/*  f096c10:	46043180 */ 	add.s	$f6,$f6,$f4
/*  f096c14:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f096c18:	46049102 */ 	mul.s	$f4,$f18,$f4
/*  f096c1c:	46043180 */ 	add.s	$f6,$f6,$f4
/*  f096c20:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f096c24:	e5c40000 */ 	swc1	$f4,0x0($t6)
/*  f096c28:	c4ea0004 */ 	lwc1	$f10,0x4($a3)
/*  f096c2c:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f096c30:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f096c34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096c38:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f096c3c:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*  f096c40:	46048102 */ 	mul.s	$f4,$f16,$f4
/*  f096c44:	46045280 */ 	add.s	$f10,$f10,$f4
/*  f096c48:	c4c40004 */ 	lwc1	$f4,0x4($a2)
/*  f096c4c:	46049102 */ 	mul.s	$f4,$f18,$f4
/*  f096c50:	46045280 */ 	add.s	$f10,$f10,$f4
/*  f096c54:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f096c58:	e5c40004 */ 	swc1	$f4,0x4($t6)
/*  f096c5c:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f096c60:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f096c64:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f096c68:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*  f096c6c:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f096c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096c74:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f096c78:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f096c7c:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f096c80:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f096c84:	46069102 */ 	mul.s	$f4,$f18,$f6
/*  f096c88:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f096c8c:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f096c90:	03e00008 */ 	jr	$ra
/*  f096c94:	e5c80008 */ 	swc1	$f8,0x8($t6)
/*  f096c98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096c9c:	00000000 */ 	sll	$zero,$zero,0x0
);
