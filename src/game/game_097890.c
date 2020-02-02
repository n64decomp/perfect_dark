#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
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

GLOBAL_ASM(
glabel func0f097908
/*  f097908:	44802000 */ 	mtc1	$zero,$f4
/*  f09790c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097910:	460c203e */ 	c.le.s	$f4,$f12
/*  f097914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097918:	45020006 */ 	bc1fl	.L0f097934
/*  f09791c:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f097920:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f097924:	44023000 */ 	mfc1	$v0,$f6
/*  f097928:	03e00008 */ 	jr	$ra
/*  f09792c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097930:	4600620d */ 	trunc.w.s	$f8,$f12
.L0f097934:
/*  f097934:	44034000 */ 	mfc1	$v1,$f8
/*  f097938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09793c:	44835000 */ 	mtc1	$v1,$f10
/*  f097940:	2462ffff */ 	addiu	$v0,$v1,-1
/*  f097944:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f097948:	46106032 */ 	c.eq.s	$f12,$f16
/*  f09794c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097950:	45000003 */ 	bc1f	.L0f097960
/*  f097954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097958:	03e00008 */ 	jr	$ra
/*  f09795c:	00601025 */ 	or	$v0,$v1,$zero
.L0f097960:
/*  f097960:	03e00008 */ 	jr	$ra
/*  f097964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09796c:	00000000 */ 	sll	$zero,$zero,0x0
);
