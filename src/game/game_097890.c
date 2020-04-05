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
glabel func0f097890
/*  f097890:	44802000 */ 	mtc1	$zero,$f4
/*  f097894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097898:	460c203e */ 	c.le.s	$f4,$f12
/*  f09789c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0978a0:	45020008 */ 	bc1fl	.L0f0978c4
/*  f0978a4:	4600628d */ 	trunc.w.s	$f10,$f12
/*  f0978a8:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f0978ac:	440f3000 */ 	mfc1	$t7,$f6
/*  f0978b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0978b4:	448f4000 */ 	mtc1	$t7,$f8
/*  f0978b8:	03e00008 */ 	jr	$ra
/*  f0978bc:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f0978c0:	4600628d */ 	trunc.w.s	$f10,$f12
.L0f0978c4:
/*  f0978c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0978c8:	44195000 */ 	mfc1	$t9,$f10
/*  f0978cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0978d0:	44998000 */ 	mtc1	$t9,$f16
/*  f0978d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0978d8:	468080a0 */ 	cvt.s.w	$f2,$f16
/*  f0978dc:	46026032 */ 	c.eq.s	$f12,$f2
/*  f0978e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0978e4:	45020004 */ 	bc1fl	.L0f0978f8
/*  f0978e8:	44819000 */ 	mtc1	$at,$f18
/*  f0978ec:	03e00008 */ 	jr	$ra
/*  f0978f0:	46001006 */ 	mov.s	$f0,$f2
/*  f0978f4:	44819000 */ 	mtc1	$at,$f18
.L0f0978f8:
/*  f0978f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0978fc:	46121001 */ 	sub.s	$f0,$f2,$f18
/*  f097900:	03e00008 */ 	jr	$ra
/*  f097904:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 floor(f32 value)
{
	s32 ivalue;

	if (value >= 0) {
		return value;
	}

	ivalue = value;

	if (value == ivalue) {
		return ivalue;
	}

	return ivalue - 1;
}
