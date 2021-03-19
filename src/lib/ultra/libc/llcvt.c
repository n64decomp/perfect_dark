#include "constants.h"

long long __f_to_ll(float f)
{
	return f;
}

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00005abcnb
/*     5abc:	46006109 */ 	trunc.l.s	$f4,$f12
/*     5ac0:	44222000 */ 	dmfc1	$v0,$f4
/*     5ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ac8:	0002183c */ 	dsll32	$v1,$v0,0x0
/*     5acc:	0003183f */ 	dsra32	$v1,$v1,0x0
/*     5ad0:	03e00008 */ 	jr	$ra
/*     5ad4:	0002103f */ 	dsra32	$v0,$v0,0x0
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00005b74nb
/*     5b74:	444ef800 */ 	cfc1	$t6,$31
/*     5b78:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5b7c:	44c2f800 */ 	ctc1	$v0,$31
/*     5b80:	00000000 */ 	sll	$zero,$zero,0x0
/*     5b84:	46006125 */ 	cvt.l.s	$f4,$f12
/*     5b88:	4442f800 */ 	cfc1	$v0,$31
/*     5b8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5b90:	30410004 */ 	andi	$at,$v0,0x4
/*     5b94:	30420078 */ 	andi	$v0,$v0,0x78
/*     5b98:	10400014 */ 	beqz	$v0,.NB00005bec
/*     5b9c:	3c015f00 */ 	lui	$at,0x5f00
/*     5ba0:	44812000 */ 	mtc1	$at,$f4
/*     5ba4:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5ba8:	46046101 */ 	sub.s	$f4,$f12,$f4
/*     5bac:	44c2f800 */ 	ctc1	$v0,$31
/*     5bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*     5bb4:	46002125 */ 	cvt.l.s	$f4,$f4
/*     5bb8:	4442f800 */ 	cfc1	$v0,$31
/*     5bbc:	00000000 */ 	sll	$zero,$zero,0x0
/*     5bc0:	30410004 */ 	andi	$at,$v0,0x4
/*     5bc4:	30420078 */ 	andi	$v0,$v0,0x78
/*     5bc8:	14400006 */ 	bnez	$v0,.NB00005be4
/*     5bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*     5bd0:	3c0f8000 */ 	lui	$t7,0x8000
/*     5bd4:	000f783c */ 	dsll32	$t7,$t7,0x0
/*     5bd8:	44222000 */ 	dmfc1	$v0,$f4
/*     5bdc:	10000007 */ 	beqz	$zero,.NB00005bfc
/*     5be0:	004f1025 */ 	or	$v0,$v0,$t7
.NB00005be4:
/*     5be4:	10000005 */ 	beqz	$zero,.NB00005bfc
/*     5be8:	2402ffff */ 	addiu	$v0,$zero,-1
.NB00005bec:
/*     5bec:	44222000 */ 	dmfc1	$v0,$f4
/*     5bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*     5bf4:	0440fffb */ 	bltz	$v0,.NB00005be4
/*     5bf8:	00000000 */ 	sll	$zero,$zero,0x0
.NB00005bfc:
/*     5bfc:	44cef800 */ 	ctc1	$t6,$31
/*     5c00:	0002183c */ 	dsll32	$v1,$v0,0x0
/*     5c04:	0003183f */ 	dsra32	$v1,$v1,0x0
/*     5c08:	03e00008 */ 	jr	$ra
/*     5c0c:	0002103f */ 	dsra32	$v0,$v0,0x0
);
#endif

GLOBAL_ASM(
glabel __f_to_ull
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

// Mismatch: Goal loads 0x80000000 then shifts it left by 32,
// while the below stores it in .rodata and loads it.
//unsigned long long __f_to_ull(float f)
//{
//	return f;
//}

double __ll_to_d(long long s)
{
	return s;
}

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00005c28nb
/*     5c28:	afa40000 */ 	sw	$a0,0x0($sp)
/*     5c2c:	afa50004 */ 	sw	$a1,0x4($sp)
/*     5c30:	dfae0000 */ 	ld	$t6,0x0($sp)
/*     5c34:	44ae2000 */ 	dmtc1	$t6,$f4
/*     5c38:	03e00008 */ 	jr	$ra
/*     5c3c:	46a02020 */ 	cvt.s.l	$f0,$f4
);
#endif

float __ull_to_f(unsigned long long u)
{
	return u;
}

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00005c70nb
/*     5c70:	afa40000 */ 	sw	$a0,0x0($sp)
/*     5c74:	afa50004 */ 	sw	$a1,0x4($sp)
/*     5c78:	dfae0000 */ 	ld	$t6,0x0($sp)
/*     5c7c:	44ae2000 */ 	dmtc1	$t6,$f4
/*     5c80:	05c10005 */ 	bgez	$t6,.NB00005c98
/*     5c84:	46a02020 */ 	cvt.s.l	$f0,$f4
/*     5c88:	3c014f80 */ 	lui	$at,0x4f80
/*     5c8c:	44813000 */ 	mtc1	$at,$f6
/*     5c90:	00000000 */ 	sll	$zero,$zero,0x0
/*     5c94:	46060000 */ 	add.s	$f0,$f0,$f6
.NB00005c98:
/*     5c98:	03e00008 */ 	jr	$ra
/*     5c9c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
