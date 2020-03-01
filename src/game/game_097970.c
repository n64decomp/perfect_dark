#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f097970
/*  f097970:	44802000 */ 	mtc1	$zero,$f4
/*  f097974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097978:	4604603e */ 	c.le.s	$f12,$f4
/*  f09797c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097980:	45020008 */ 	bc1fl	.L0f0979a4
/*  f097984:	4600628d */ 	trunc.w.s	$f10,$f12
/*  f097988:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f09798c:	440f3000 */ 	mfc1	$t7,$f6
/*  f097990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097994:	448f4000 */ 	mtc1	$t7,$f8
/*  f097998:	03e00008 */ 	jr	$ra
/*  f09799c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f0979a0:	4600628d */ 	trunc.w.s	$f10,$f12
.L0f0979a4:
/*  f0979a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0979a8:	44195000 */ 	mfc1	$t9,$f10
/*  f0979ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0979b0:	44998000 */ 	mtc1	$t9,$f16
/*  f0979b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0979b8:	468080a0 */ 	cvt.s.w	$f2,$f16
/*  f0979bc:	46026032 */ 	c.eq.s	$f12,$f2
/*  f0979c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0979c4:	45020004 */ 	bc1fl	.L0f0979d8
/*  f0979c8:	44819000 */ 	mtc1	$at,$f18
/*  f0979cc:	03e00008 */ 	jr	$ra
/*  f0979d0:	46001006 */ 	mov.s	$f0,$f2
/*  f0979d4:	44819000 */ 	mtc1	$at,$f18
.L0f0979d8:
/*  f0979d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0979dc:	46121000 */ 	add.s	$f0,$f2,$f18
/*  f0979e0:	03e00008 */ 	jr	$ra
/*  f0979e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0979e8
/*  f0979e8:	44802000 */ 	mtc1	$zero,$f4
/*  f0979ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0979f0:	4604603e */ 	c.le.s	$f12,$f4
/*  f0979f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0979f8:	45020006 */ 	bc1fl	.L0f097a14
/*  f0979fc:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f097a00:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f097a04:	44023000 */ 	mfc1	$v0,$f6
/*  f097a08:	03e00008 */ 	jr	$ra
/*  f097a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a10:	4600620d */ 	trunc.w.s	$f8,$f12
.L0f097a14:
/*  f097a14:	44034000 */ 	mfc1	$v1,$f8
/*  f097a18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a1c:	44835000 */ 	mtc1	$v1,$f10
/*  f097a20:	24620001 */ 	addiu	$v0,$v1,0x1
/*  f097a24:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f097a28:	46106032 */ 	c.eq.s	$f12,$f16
/*  f097a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a30:	45000003 */ 	bc1f	.L0f097a40
/*  f097a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a38:	03e00008 */ 	jr	$ra
/*  f097a3c:	00601025 */ 	or	$v0,$v1,$zero
.L0f097a40:
/*  f097a40:	03e00008 */ 	jr	$ra
/*  f097a44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a4c:	00000000 */ 	sll	$zero,$zero,0x0
);
