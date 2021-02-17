#include <ultra64.h>
#include "constants.h"
#include "game/game_097a50.h"
#include "game/game_097aa0.h"
#include "gvars/gvars.h"
#include "data.h"
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
);

f32 func0f097b10(f32 arg0, f32 arg1)
{
	return func0f097a50(func0f097aa0(arg0) * arg1);
}

void func0f097b40(f32 *a, f32 *b, f32 *dst)
{
	dst[0] = b[0] * a[0];
	dst[1] = b[1] * a[1];
}

void func0f097b64(f32 *a, f32 *b, f32 scale, f32 *dst)
{
	dst[0] = (b[0] - a[0]) * scale + a[0];
	dst[1] = (b[1] - a[1]) * scale + a[1];
}
