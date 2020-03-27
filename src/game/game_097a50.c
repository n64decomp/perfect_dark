#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f097a50
/*  f097a50:	3c013f80 */ 	lui	$at,0x3f80
/*  f097a54:	44819000 */ 	mtc1	$at,$f18
/*  f097a58:	44808000 */ 	mtc1	$zero,$f16
/*  f097a5c:	46009386 */ 	mov.s	$f14,$f18
/*  f097a60:	46109032 */ 	c.eq.s	$f18,$f16
/*  f097a64:	46008006 */ 	mov.s	$f0,$f16
/*  f097a68:	46008086 */ 	mov.s	$f2,$f16
/*  f097a6c:	45010009 */ 	bc1t	.L0f097a94
/*  f097a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a74:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f097a78:
/*  f097a78:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f097a7c:	46006103 */ 	div.s	$f4,$f12,$f0
/*  f097a80:	46047382 */ 	mul.s	$f14,$f14,$f4
/*  f097a84:	46107032 */ 	c.eq.s	$f14,$f16
/*  f097a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a8c:	4502fffa */ 	bc1fl	.L0f097a78
/*  f097a90:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f097a94:
/*  f097a94:	03e00008 */ 	jr	$ra
/*  f097a98:	46001006 */ 	mov.s	$f0,$f2
/*  f097a9c:	00000000 */ 	sll	$zero,$zero,0x0
);
