#include <ultra64.h>
#include "boot/boot.h"
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_04a80.h"
#include "lib/lib_16110.h"
#include "lib/lib_48150.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4a5e0.h"
#include "lib/lib_4a680.h"
#include "lib/libc/ll.h"
#include "types.h"

GLOBAL_ASM(
glabel func00005a60
/*     5a60:	46006109 */ 	trunc.l.s	$f4,$f12
/*     5a64:	44222000 */ 	dmfc1	$v0,$f4
/*     5a68:	00000000 */ 	nop
/*     5a6c:	0002183c */ 	dsll32	$v1,$v0,0x0
/*     5a70:	0003183f */ 	dsra32	$v1,$v1,0x0
/*     5a74:	03e00008 */ 	jr	$ra
/*     5a78:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func00005a7c
/*     5a7c:	444ef800 */ 	cfc1	$t6,$31
/*     5a80:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5a84:	44c2f800 */ 	ctc1	$v0,$31
/*     5a88:	00000000 */ 	nop
/*     5a8c:	46006125 */ 	cvt.l.s	$f4,$f12
/*     5a90:	4442f800 */ 	cfc1	$v0,$31
/*     5a94:	00000000 */ 	nop
/*     5a98:	30410004 */ 	andi	$at,$v0,0x4
/*     5a9c:	30420078 */ 	andi	$v0,$v0,0x78
/*     5aa0:	10400014 */ 	beqz	$v0,.L00005af4
/*     5aa4:	3c015f00 */ 	lui	$at,0x5f00
/*     5aa8:	44812000 */ 	mtc1	$at,$f4
/*     5aac:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5ab0:	46046101 */ 	sub.s	$f4,$f12,$f4
/*     5ab4:	44c2f800 */ 	ctc1	$v0,$31
/*     5ab8:	00000000 */ 	nop
/*     5abc:	46002125 */ 	cvt.l.s	$f4,$f4
/*     5ac0:	4442f800 */ 	cfc1	$v0,$31
/*     5ac4:	00000000 */ 	nop
/*     5ac8:	30410004 */ 	andi	$at,$v0,0x4
/*     5acc:	30420078 */ 	andi	$v0,$v0,0x78
/*     5ad0:	14400006 */ 	bnez	$v0,.L00005aec
/*     5ad4:	00000000 */ 	nop
/*     5ad8:	3c0f8000 */ 	lui	$t7,0x8000
/*     5adc:	000f783c */ 	dsll32	$t7,$t7,0x0
/*     5ae0:	44222000 */ 	dmfc1	$v0,$f4
/*     5ae4:	10000007 */ 	b	.L00005b04
/*     5ae8:	004f1025 */ 	or	$v0,$v0,$t7
.L00005aec:
/*     5aec:	10000005 */ 	b	.L00005b04
/*     5af0:	2402ffff */ 	addiu	$v0,$zero,-1
.L00005af4:
/*     5af4:	44222000 */ 	dmfc1	$v0,$f4
/*     5af8:	00000000 */ 	nop
/*     5afc:	0440fffb */ 	bltz	$v0,.L00005aec
/*     5b00:	00000000 */ 	nop
.L00005b04:
/*     5b04:	44cef800 */ 	ctc1	$t6,$31
/*     5b08:	0002183c */ 	dsll32	$v1,$v0,0x0
/*     5b0c:	0003183f */ 	dsra32	$v1,$v1,0x0
/*     5b10:	03e00008 */ 	jr	$ra
/*     5b14:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func00005b18
/*     5b18:	afa40000 */ 	sw	$a0,0x0($sp)
/*     5b1c:	afa50004 */ 	sw	$a1,0x4($sp)
/*     5b20:	dfae0000 */ 	ld	$t6,0x0($sp)
/*     5b24:	44ae2000 */ 	dmtc1	$t6,$f4
/*     5b28:	03e00008 */ 	jr	$ra
/*     5b2c:	46a02021 */ 	cvt.d.l	$f0,$f4
);

GLOBAL_ASM(
glabel func00005b30
/*     5b30:	afa40000 */ 	sw	$a0,0x0($sp)
/*     5b34:	afa50004 */ 	sw	$a1,0x4($sp)
/*     5b38:	dfae0000 */ 	ld	$t6,0x0($sp)
/*     5b3c:	44ae2000 */ 	dmtc1	$t6,$f4
/*     5b40:	05c10005 */ 	bgez	$t6,.L00005b58
/*     5b44:	46a02020 */ 	cvt.s.l	$f0,$f4
/*     5b48:	3c014f80 */ 	lui	$at,0x4f80
/*     5b4c:	44813000 */ 	mtc1	$at,$f6
/*     5b50:	00000000 */ 	nop
/*     5b54:	46060000 */ 	add.s	$f0,$f0,$f6
.L00005b58:
/*     5b58:	03e00008 */ 	jr	$ra
/*     5b5c:	00000000 */ 	nop
);
