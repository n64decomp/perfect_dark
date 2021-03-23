#include "constants.h"

#if VERSION < VERSION_NTSC_1_0
long long __d_to_ll(double f)
{
	return f;
}
#endif

long long __f_to_ll(float f)
{
	return f;
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel __d_to_ull
/*     5ad8:	444ef800 */ 	cfc1	$t6,$31
/*     5adc:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5ae0:	44c2f800 */ 	ctc1	$v0,$31
/*     5ae4:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ae8:	46206125 */ 	cvt.l.d	$f4,$f12
/*     5aec:	4442f800 */ 	cfc1	$v0,$31
/*     5af0:	00000000 */ 	sll	$zero,$zero,0x0
/*     5af4:	30410004 */ 	andi	$at,$v0,0x4
/*     5af8:	30420078 */ 	andi	$v0,$v0,0x78
/*     5afc:	10400014 */ 	beqz	$v0,.NB00005b50
/*     5b00:	3c0143e0 */ 	lui	$at,0x43e0
/*     5b04:	44812000 */ 	mtc1	$at,$f4
/*     5b08:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5b0c:	46246101 */ 	sub.d	$f4,$f12,$f4
/*     5b10:	44c2f800 */ 	ctc1	$v0,$31
/*     5b14:	00000000 */ 	sll	$zero,$zero,0x0
/*     5b18:	46202125 */ 	cvt.l.d	$f4,$f4
/*     5b1c:	4442f800 */ 	cfc1	$v0,$31
/*     5b20:	00000000 */ 	sll	$zero,$zero,0x0
/*     5b24:	30410004 */ 	andi	$at,$v0,0x4
/*     5b28:	30420078 */ 	andi	$v0,$v0,0x78
/*     5b2c:	14400006 */ 	bnez	$v0,.NB00005b48
/*     5b30:	00000000 */ 	sll	$zero,$zero,0x0
/*     5b34:	3c0f8000 */ 	lui	$t7,0x8000
/*     5b38:	000f783c */ 	dsll32	$t7,$t7,0x0
/*     5b3c:	44222000 */ 	dmfc1	$v0,$f4
/*     5b40:	10000007 */ 	beqz	$zero,.NB00005b60
/*     5b44:	004f1025 */ 	or	$v0,$v0,$t7
.NB00005b48:
/*     5b48:	10000005 */ 	beqz	$zero,.NB00005b60
/*     5b4c:	2402ffff */ 	addiu	$v0,$zero,-1
.NB00005b50:
/*     5b50:	44222000 */ 	dmfc1	$v0,$f4
/*     5b54:	00000000 */ 	sll	$zero,$zero,0x0
/*     5b58:	0440fffb */ 	bltz	$v0,.NB00005b48
/*     5b5c:	00000000 */ 	sll	$zero,$zero,0x0
.NB00005b60:
/*     5b60:	44cef800 */ 	ctc1	$t6,$31
/*     5b64:	0002183c */ 	dsll32	$v1,$v0,0x0
/*     5b68:	0003183f */ 	dsra32	$v1,$v1,0x0
/*     5b6c:	03e00008 */ 	jr	$ra
/*     5b70:	0002103f */ 	dsra32	$v0,$v0,0x0
);

//unsigned long long __d_to_ull(double d)
//{
//	return d;
//}
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

#if VERSION < VERSION_NTSC_1_0
float __ll_to_f(long long s)
{
	return s;
}
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel __ull_to_d
/*     5c40:	afa40000 */ 	sw	$a0,0x0($sp)
/*     5c44:	afa50004 */ 	sw	$a1,0x4($sp)
/*     5c48:	dfae0000 */ 	ld	$t6,0x0($sp)
/*     5c4c:	44ae2000 */ 	dmtc1	$t6,$f4
/*     5c50:	05c10005 */ 	bgez	$t6,.NB00005c68
/*     5c54:	46a02021 */ 	cvt.d.l	$f0,$f4
/*     5c58:	3c0141f0 */ 	lui	$at,0x41f0
/*     5c5c:	44813000 */ 	mtc1	$at,$f6
/*     5c60:	00000000 */ 	sll	$zero,$zero,0x0
/*     5c64:	46260000 */ 	add.d	$f0,$f0,$f6
.NB00005c68:
/*     5c68:	03e00008 */ 	jr	$ra
/*     5c6c:	00000000 */ 	sll	$zero,$zero,0x0
);

//double __ull_to_d(unsigned long long u)
//{
//	return u;
//}
#endif

float __ull_to_f(unsigned long long u)
{
	return u;
}
