#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096890.h"
#include "gvars/gvars.h"
#include "types.h"

f32 func0f0969d0(f32 value)
{
	s16 intval;

	if (value >= 1) {
		intval = 0x7fff;
	} else if (value <= -1) {
		intval = -0x7fff;
	} else {
		intval = value * 32767.0f;
	}

	return (func0f096910(intval) * M_PI) / 65535.0f;
}

GLOBAL_ASM(
glabel func0f096a7c
.late_rodata
glabel var7f1ab85c
.word 0x46fffe00
glabel var7f1ab860
.word 0x40490fdb
glabel var7f1ab864
.word 0x477fff00
.text
/*  f096a7c:	3c013f80 */ 	lui	$at,0x3f80
/*  f096a80:	44812000 */ 	mtc1	$at,$f4
/*  f096a84:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f096a88:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f096a8c:	460c203e */ 	c.le.s	$f4,$f12
/*  f096a90:	3c01bf80 */ 	lui	$at,0xbf80
/*  f096a94:	45020004 */ 	bc1fl	.L0f096aa8
/*  f096a98:	44813000 */ 	mtc1	$at,$f6
/*  f096a9c:	10000010 */ 	beqz	$zero,.L0f096ae0
/*  f096aa0:	24047fff */ 	addiu	$a0,$zero,0x7fff
/*  f096aa4:	44813000 */ 	mtc1	$at,$f6
.L0f096aa8:
/*  f096aa8:	3c017f1b */ 	lui	$at,%hi(var7f1ab85c)
/*  f096aac:	4606603e */ 	c.le.s	$f12,$f6
/*  f096ab0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096ab4:	45000003 */ 	bc1f	.L0f096ac4
/*  f096ab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096abc:	10000008 */ 	beqz	$zero,.L0f096ae0
/*  f096ac0:	24048001 */ 	addiu	$a0,$zero,-32767
.L0f096ac4:
/*  f096ac4:	c428b85c */ 	lwc1	$f8,%lo(var7f1ab85c)($at)
/*  f096ac8:	46086282 */ 	mul.s	$f10,$f12,$f8
/*  f096acc:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f096ad0:	44048000 */ 	mfc1	$a0,$f16
/*  f096ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096ad8:	00047c00 */ 	sll	$t7,$a0,0x10
/*  f096adc:	000f2403 */ 	sra	$a0,$t7,0x10
.L0f096ae0:
/*  f096ae0:	0fc25a59 */ 	jal	func0f096964
/*  f096ae4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096ae8:	44829000 */ 	mtc1	$v0,$f18
/*  f096aec:	3c017f1b */ 	lui	$at,%hi(var7f1ab860)
/*  f096af0:	c426b860 */ 	lwc1	$f6,%lo(var7f1ab860)($at)
/*  f096af4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f096af8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f096afc:	3c017f1b */ 	lui	$at,%hi(var7f1ab864)
/*  f096b00:	c42ab864 */ 	lwc1	$f10,%lo(var7f1ab864)($at)
/*  f096b04:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f096b08:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f096b0c:	03e00008 */ 	jr	$ra
/*  f096b10:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f096b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096b1c:	00000000 */ 	sll	$zero,$zero,0x0
);
