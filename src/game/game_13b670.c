#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_13b670.h"
#include "gvars/gvars.h"
#include "lib/main.h"
#include "lib/lib_121e0.h"
#include "lib/lib_16110.h"
#include "types.h"

const char var7f1b5960[] = "modula";
const char var7f1b5968[] = "ripsize";

GLOBAL_ASM(
glabel func0f13b670
/*  f13b670:	3c018006 */ 	lui	$at,%hi(var80061634)
/*  f13b674:	c4241634 */ 	lwc1	$f4,%lo(var80061634)($at)
/*  f13b678:	3c014120 */ 	lui	$at,0x4120
/*  f13b67c:	44813000 */ 	mtc1	$at,$f6
/*  f13b680:	3c014580 */ 	lui	$at,0x4580
/*  f13b684:	44815000 */ 	mtc1	$at,$f10
/*  f13b688:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f13b68c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f13b690:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f13b694:	90a90001 */ 	lbu	$t1,0x1($a1)
/*  f13b698:	3c08800a */ 	lui	$t0,%hi(var800a418c)
/*  f13b69c:	00808025 */ 	or	$s0,$a0,$zero
/*  f13b6a0:	2508418c */ 	addiu	$t0,$t0,%lo(var800a418c)
/*  f13b6a4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f13b6a8:	00001825 */ 	or	$v1,$zero,$zero
/*  f13b6ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f13b6b0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f13b6b4:	44029000 */ 	mfc1	$v0,$f18
/*  f13b6b8:	00000000 */ 	nop
/*  f13b6bc:	04410004 */ 	bgez	$v0,.L0f13b6d0
/*  f13b6c0:	304f0fff */ 	andi	$t7,$v0,0xfff
/*  f13b6c4:	11e00002 */ 	beqz	$t7,.L0f13b6d0
/*  f13b6c8:	00000000 */ 	nop
/*  f13b6cc:	25eff000 */ 	addiu	$t7,$t7,-4096
.L0f13b6d0:
/*  f13b6d0:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f13b6d4:	1920001c */ 	blez	$t1,.L0f13b748
/*  f13b6d8:	00181403 */ 	sra	$v0,$t8,0x10
/*  f13b6dc:	94ab0002 */ 	lhu	$t3,0x2($a1)
.L0f13b6e0:
/*  f13b6e0:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*  f13b6e4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13b6e8:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f13b6ec:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f13b6f0:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f13b6f4:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f13b6f8:	01a63821 */ 	addu	$a3,$t5,$a2
/*  f13b6fc:	94ee0000 */ 	lhu	$t6,0x0($a3)
/*  f13b700:	84ef0004 */ 	lh	$t7,0x4($a3)
/*  f13b704:	01d02021 */ 	addu	$a0,$t6,$s0
/*  f13b708:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f13b70c:	a498000a */ 	sh	$t8,0xa($a0)
/*  f13b710:	94a90002 */ 	lhu	$t1,0x2($a1)
/*  f13b714:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f13b718:	00095880 */ 	sll	$t3,$t1,0x2
/*  f13b71c:	01695823 */ 	subu	$t3,$t3,$t1
/*  f13b720:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f13b724:	032b5021 */ 	addu	$t2,$t9,$t3
/*  f13b728:	01466021 */ 	addu	$t4,$t2,$a2
/*  f13b72c:	858d0002 */ 	lh	$t5,0x2($t4)
/*  f13b730:	24c60006 */ 	addiu	$a2,$a2,0x6
/*  f13b734:	a48d0008 */ 	sh	$t5,0x8($a0)
/*  f13b738:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f13b73c:	006e082a */ 	slt	$at,$v1,$t6
/*  f13b740:	5420ffe7 */ 	bnezl	$at,.L0f13b6e0
/*  f13b744:	94ab0002 */ 	lhu	$t3,0x2($a1)
.L0f13b748:
/*  f13b748:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f13b74c:	03e00008 */ 	jr	$ra
/*  f13b750:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f13b754
/*  f13b754:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f13b758:	00803025 */ 	or	$a2,$a0,$zero
/*  f13b75c:	00002025 */ 	or	$a0,$zero,$zero
/*  f13b760:	19c00014 */ 	blez	$t6,.L0f13b7b4
/*  f13b764:	00001025 */ 	or	$v0,$zero,$zero
/*  f13b768:	3c07800a */ 	lui	$a3,%hi(var800a418c)
/*  f13b76c:	24e7418c */ 	addiu	$a3,$a3,%lo(var800a418c)
/*  f13b770:	94b80002 */ 	lhu	$t8,0x2($a1)
.L0f13b774:
/*  f13b774:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f13b778:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f13b77c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13b780:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f13b784:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f13b788:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f13b78c:	01044821 */ 	addu	$t1,$t0,$a0
/*  f13b790:	952a0000 */ 	lhu	$t2,0x0($t1)
/*  f13b794:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f13b798:	01461821 */ 	addu	$v1,$t2,$a2
/*  f13b79c:	a4600008 */ 	sh	$zero,0x8($v1)
/*  f13b7a0:	a460000a */ 	sh	$zero,0xa($v1)
/*  f13b7a4:	90ab0001 */ 	lbu	$t3,0x1($a1)
/*  f13b7a8:	004b082a */ 	slt	$at,$v0,$t3
/*  f13b7ac:	5420fff1 */ 	bnezl	$at,.L0f13b774
/*  f13b7b0:	94b80002 */ 	lhu	$t8,0x2($a1)
.L0f13b7b4:
/*  f13b7b4:	03e00008 */ 	jr	$ra
/*  f13b7b8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f13b7bc
/*  f13b7bc:	3c018006 */ 	lui	$at,%hi(var80061634)
/*  f13b7c0:	c4241634 */ 	lwc1	$f4,%lo(var80061634)($at)
/*  f13b7c4:	3c014080 */ 	lui	$at,0x4080
/*  f13b7c8:	44813000 */ 	mtc1	$at,$f6
/*  f13b7cc:	3c014580 */ 	lui	$at,0x4580
/*  f13b7d0:	44815000 */ 	mtc1	$at,$f10
/*  f13b7d4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f13b7d8:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f13b7dc:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f13b7e0:	90a90001 */ 	lbu	$t1,0x1($a1)
/*  f13b7e4:	3c08800a */ 	lui	$t0,%hi(var800a418c)
/*  f13b7e8:	00808025 */ 	or	$s0,$a0,$zero
/*  f13b7ec:	2508418c */ 	addiu	$t0,$t0,%lo(var800a418c)
/*  f13b7f0:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f13b7f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f13b7f8:	00003025 */ 	or	$a2,$zero,$zero
/*  f13b7fc:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f13b800:	44029000 */ 	mfc1	$v0,$f18
/*  f13b804:	00000000 */ 	nop
/*  f13b808:	04410004 */ 	bgez	$v0,.L0f13b81c
/*  f13b80c:	304f0fff */ 	andi	$t7,$v0,0xfff
/*  f13b810:	11e00002 */ 	beqz	$t7,.L0f13b81c
/*  f13b814:	00000000 */ 	nop
/*  f13b818:	25eff000 */ 	addiu	$t7,$t7,-4096
.L0f13b81c:
/*  f13b81c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f13b820:	1920001c */ 	blez	$t1,.L0f13b894
/*  f13b824:	00181403 */ 	sra	$v0,$t8,0x10
/*  f13b828:	94ab0002 */ 	lhu	$t3,0x2($a1)
.L0f13b82c:
/*  f13b82c:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*  f13b830:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13b834:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f13b838:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f13b83c:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f13b840:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f13b844:	01a63821 */ 	addu	$a3,$t5,$a2
/*  f13b848:	94ee0000 */ 	lhu	$t6,0x0($a3)
/*  f13b84c:	84ef0004 */ 	lh	$t7,0x4($a3)
/*  f13b850:	01d02021 */ 	addu	$a0,$t6,$s0
/*  f13b854:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f13b858:	a498000a */ 	sh	$t8,0xa($a0)
/*  f13b85c:	94a90002 */ 	lhu	$t1,0x2($a1)
/*  f13b860:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f13b864:	00095880 */ 	sll	$t3,$t1,0x2
/*  f13b868:	01695823 */ 	subu	$t3,$t3,$t1
/*  f13b86c:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f13b870:	032b5021 */ 	addu	$t2,$t9,$t3
/*  f13b874:	01466021 */ 	addu	$t4,$t2,$a2
/*  f13b878:	858d0002 */ 	lh	$t5,0x2($t4)
/*  f13b87c:	24c60006 */ 	addiu	$a2,$a2,0x6
/*  f13b880:	a48d0008 */ 	sh	$t5,0x8($a0)
/*  f13b884:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f13b888:	006e082a */ 	slt	$at,$v1,$t6
/*  f13b88c:	5420ffe7 */ 	bnezl	$at,.L0f13b82c
/*  f13b890:	94ab0002 */ 	lhu	$t3,0x2($a1)
.L0f13b894:
/*  f13b894:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f13b898:	03e00008 */ 	jr	$ra
/*  f13b89c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f13b8a0
.late_rodata
glabel var7f1b5970
.word 0x40c907a9
.text
/*  f13b8a0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f13b8a4:	3c018006 */ 	lui	$at,%hi(var80061634)
/*  f13b8a8:	c4241634 */ 	lwc1	$f4,%lo(var80061634)($at)
/*  f13b8ac:	3c0140a0 */ 	lui	$at,0x40a0
/*  f13b8b0:	44813000 */ 	mtc1	$at,$f6
/*  f13b8b4:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f13b8b8:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f13b8bc:	00a09025 */ 	or	$s2,$a1,$zero
/*  f13b8c0:	0080a825 */ 	or	$s5,$a0,$zero
/*  f13b8c4:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f13b8c8:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f13b8cc:	3c047f1b */ 	lui	$a0,%hi(var7f1b5960)
/*  f13b8d0:	3c058008 */ 	lui	$a1,%hi(var8007f700)
/*  f13b8d4:	46062602 */ 	mul.s	$f24,$f4,$f6
/*  f13b8d8:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f13b8dc:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f13b8e0:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f13b8e4:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f13b8e8:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f13b8ec:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f13b8f0:	24a5f700 */ 	addiu	$a1,$a1,%lo(var8007f700)
/*  f13b8f4:	0c0036cc */ 	jal	func0000db30
/*  f13b8f8:	24845960 */ 	addiu	$a0,$a0,%lo(var7f1b5960)
/*  f13b8fc:	3c047f1b */ 	lui	$a0,%hi(var7f1b5968)
/*  f13b900:	3c058008 */ 	lui	$a1,%hi(var8007f6fc)
/*  f13b904:	24a5f6fc */ 	addiu	$a1,$a1,%lo(var8007f6fc)
/*  f13b908:	0c0036cc */ 	jal	func0000db30
/*  f13b90c:	24845968 */ 	addiu	$a0,$a0,%lo(var7f1b5968)
/*  f13b910:	924e0001 */ 	lbu	$t6,0x1($s2)
/*  f13b914:	00009825 */ 	or	$s3,$zero,$zero
/*  f13b918:	00008025 */ 	or	$s0,$zero,$zero
/*  f13b91c:	19c00083 */ 	blez	$t6,.L0f13bb2c
/*  f13b920:	3c017f1b */ 	lui	$at,%hi(var7f1b5970)
/*  f13b924:	3c11800a */ 	lui	$s1,%hi(var800a418c)
/*  f13b928:	2631418c */ 	addiu	$s1,$s1,%lo(var800a418c)
/*  f13b92c:	c4365970 */ 	lwc1	$f22,%lo(var7f1b5970)($at)
/*  f13b930:	96580002 */ 	lhu	$t8,0x2($s2)
.L0f13b934:
/*  f13b934:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f13b938:	3c0b8008 */ 	lui	$t3,%hi(var8007f700)
/*  f13b93c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13b940:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f13b944:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f13b948:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f13b94c:	8d6bf700 */ 	lw	$t3,%lo(var8007f700)($t3)
/*  f13b950:	01101021 */ 	addu	$v0,$t0,$s0
/*  f13b954:	844a0004 */ 	lh	$t2,0x4($v0)
/*  f13b958:	94490000 */ 	lhu	$t1,0x0($v0)
/*  f13b95c:	448b9000 */ 	mtc1	$t3,$f18
/*  f13b960:	014b001b */ 	divu	$zero,$t2,$t3
/*  f13b964:	00006010 */ 	mfhi	$t4
/*  f13b968:	448c4000 */ 	mtc1	$t4,$f8
/*  f13b96c:	0135a021 */ 	addu	$s4,$t1,$s5
/*  f13b970:	15600002 */ 	bnez	$t3,.L0f13b97c
/*  f13b974:	00000000 */ 	nop
/*  f13b978:	0007000d */ 	break	0x7
.L0f13b97c:
/*  f13b97c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13b980:	05810004 */ 	bgez	$t4,.L0f13b994
/*  f13b984:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b988:	44818000 */ 	mtc1	$at,$f16
/*  f13b98c:	00000000 */ 	nop
/*  f13b990:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f13b994:
/*  f13b994:	05610005 */ 	bgez	$t3,.L0f13b9ac
/*  f13b998:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13b99c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b9a0:	44813000 */ 	mtc1	$at,$f6
/*  f13b9a4:	00000000 */ 	nop
/*  f13b9a8:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f13b9ac:
/*  f13b9ac:	46045203 */ 	div.s	$f8,$f10,$f4
/*  f13b9b0:	46184400 */ 	add.s	$f16,$f8,$f24
/*  f13b9b4:	46168502 */ 	mul.s	$f20,$f16,$f22
/*  f13b9b8:	0c0068f7 */ 	jal	sinf
/*  f13b9bc:	4600a306 */ 	mov.s	$f12,$f20
/*  f13b9c0:	964e0002 */ 	lhu	$t6,0x2($s2)
/*  f13b9c4:	3c098008 */ 	lui	$t1,%hi(var8007f6fc)
/*  f13b9c8:	8d29f6fc */ 	lw	$t1,%lo(var8007f6fc)($t1)
/*  f13b9cc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f13b9d0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f13b9d4:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f13b9d8:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f13b9dc:	44899000 */ 	mtc1	$t1,$f18
/*  f13b9e0:	01b87821 */ 	addu	$t7,$t5,$t8
/*  f13b9e4:	01f0c821 */ 	addu	$t9,$t7,$s0
/*  f13b9e8:	87280004 */ 	lh	$t0,0x4($t9)
/*  f13b9ec:	05210005 */ 	bgez	$t1,.L0f13ba04
/*  f13b9f0:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f13b9f4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b9f8:	44815000 */ 	mtc1	$at,$f10
/*  f13b9fc:	00000000 */ 	nop
/*  f13ba00:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f13ba04:
/*  f13ba04:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f13ba08:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ba0c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f13ba10:	440c4000 */ 	mfc1	$t4,$f8
/*  f13ba14:	00000000 */ 	nop
/*  f13ba18:	000c5c00 */ 	sll	$t3,$t4,0x10
/*  f13ba1c:	000b7403 */ 	sra	$t6,$t3,0x10
/*  f13ba20:	01c86821 */ 	addu	$t5,$t6,$t0
/*  f13ba24:	a68d000a */ 	sh	$t5,0xa($s4)
/*  f13ba28:	964f0002 */ 	lhu	$t7,0x2($s2)
/*  f13ba2c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f13ba30:	3c0e8008 */ 	lui	$t6,%hi(var8007f700)
/*  f13ba34:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f13ba38:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f13ba3c:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f13ba40:	03194821 */ 	addu	$t1,$t8,$t9
/*  f13ba44:	01305021 */ 	addu	$t2,$t1,$s0
/*  f13ba48:	854c0002 */ 	lh	$t4,0x2($t2)
/*  f13ba4c:	8dcef700 */ 	lw	$t6,%lo(var8007f700)($t6)
/*  f13ba50:	258b0016 */ 	addiu	$t3,$t4,0x16
/*  f13ba54:	016e001b */ 	divu	$zero,$t3,$t6
/*  f13ba58:	00004010 */ 	mfhi	$t0
/*  f13ba5c:	44888000 */ 	mtc1	$t0,$f16
/*  f13ba60:	15c00002 */ 	bnez	$t6,.L0f13ba6c
/*  f13ba64:	00000000 */ 	nop
/*  f13ba68:	0007000d */ 	break	0x7
.L0f13ba6c:
/*  f13ba6c:	448e3000 */ 	mtc1	$t6,$f6
/*  f13ba70:	05010004 */ 	bgez	$t0,.L0f13ba84
/*  f13ba74:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f13ba78:	44815000 */ 	mtc1	$at,$f10
/*  f13ba7c:	00000000 */ 	nop
/*  f13ba80:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f13ba84:
/*  f13ba84:	05c10005 */ 	bgez	$t6,.L0f13ba9c
/*  f13ba88:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f13ba8c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ba90:	44814000 */ 	mtc1	$at,$f8
/*  f13ba94:	00000000 */ 	nop
/*  f13ba98:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f13ba9c:
/*  f13ba9c:	46049403 */ 	div.s	$f16,$f18,$f4
/*  f13baa0:	46188280 */ 	add.s	$f10,$f16,$f24
/*  f13baa4:	46165502 */ 	mul.s	$f20,$f10,$f22
/*  f13baa8:	0c0068f4 */ 	jal	cosf
/*  f13baac:	4600a306 */ 	mov.s	$f12,$f20
/*  f13bab0:	964f0002 */ 	lhu	$t7,0x2($s2)
/*  f13bab4:	3c0c8008 */ 	lui	$t4,%hi(var8007f6fc)
/*  f13bab8:	8d8cf6fc */ 	lw	$t4,%lo(var8007f6fc)($t4)
/*  f13babc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f13bac0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13bac4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f13bac8:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f13bacc:	448c3000 */ 	mtc1	$t4,$f6
/*  f13bad0:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f13bad4:	03304821 */ 	addu	$t1,$t9,$s0
/*  f13bad8:	852a0002 */ 	lh	$t2,0x2($t1)
/*  f13badc:	05810005 */ 	bgez	$t4,.L0f13baf4
/*  f13bae0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f13bae4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13bae8:	44819000 */ 	mtc1	$at,$f18
/*  f13baec:	00000000 */ 	nop
/*  f13baf0:	46124200 */ 	add.s	$f8,$f8,$f18
.L0f13baf4:
/*  f13baf4:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f13baf8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f13bafc:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f13bb00:	4600240d */ 	trunc.w.s	$f16,$f4
/*  f13bb04:	44088000 */ 	mfc1	$t0,$f16
/*  f13bb08:	00000000 */ 	nop
/*  f13bb0c:	00087400 */ 	sll	$t6,$t0,0x10
/*  f13bb10:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f13bb14:	01ea6821 */ 	addu	$t5,$t7,$t2
/*  f13bb18:	a68d0008 */ 	sh	$t5,0x8($s4)
/*  f13bb1c:	92580001 */ 	lbu	$t8,0x1($s2)
/*  f13bb20:	0278082a */ 	slt	$at,$s3,$t8
/*  f13bb24:	5420ff83 */ 	bnezl	$at,.L0f13b934
/*  f13bb28:	96580002 */ 	lhu	$t8,0x2($s2)
.L0f13bb2c:
/*  f13bb2c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f13bb30:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f13bb34:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f13bb38:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f13bb3c:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f13bb40:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f13bb44:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f13bb48:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f13bb4c:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f13bb50:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f13bb54:	03e00008 */ 	jr	$ra
/*  f13bb58:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f13bb5c
/*  f13bb5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13bb60:	44812000 */ 	mtc1	$at,$f4
/*  f13bb64:	3c018006 */ 	lui	$at,%hi(var80061634)
/*  f13bb68:	c4261634 */ 	lwc1	$f6,%lo(var80061634)($at)
/*  f13bb6c:	3c014270 */ 	lui	$at,0x4270
/*  f13bb70:	44815000 */ 	mtc1	$at,$f10
/*  f13bb74:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f13bb78:	3c014100 */ 	lui	$at,0x4100
/*  f13bb7c:	44819000 */ 	mtc1	$at,$f18
/*  f13bb80:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f13bb84:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f13bb88:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f13bb8c:	90b90001 */ 	lbu	$t9,0x1($a1)
/*  f13bb90:	3c08800a */ 	lui	$t0,%hi(var800a418c)
/*  f13bb94:	00808025 */ 	or	$s0,$a0,$zero
/*  f13bb98:	2508418c */ 	addiu	$t0,$t0,%lo(var800a418c)
/*  f13bb9c:	00001825 */ 	or	$v1,$zero,$zero
/*  f13bba0:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f13bba4:	00003025 */ 	or	$a2,$zero,$zero
/*  f13bba8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f13bbac:	44023000 */ 	mfc1	$v0,$f6
/*  f13bbb0:	00000000 */ 	nop
/*  f13bbb4:	04410004 */ 	bgez	$v0,.L0f13bbc8
/*  f13bbb8:	304f0007 */ 	andi	$t7,$v0,0x7
/*  f13bbbc:	11e00002 */ 	beqz	$t7,.L0f13bbc8
/*  f13bbc0:	00000000 */ 	nop
/*  f13bbc4:	25effff8 */ 	addiu	$t7,$t7,-8
.L0f13bbc8:
/*  f13bbc8:	1b20001c */ 	blez	$t9,.L0f13bc3c
/*  f13bbcc:	000f1200 */ 	sll	$v0,$t7,0x8
/*  f13bbd0:	94aa0002 */ 	lhu	$t2,0x2($a1)
.L0f13bbd4:
/*  f13bbd4:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f13bbd8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13bbdc:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f13bbe0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f13bbe4:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f13bbe8:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f13bbec:	01863821 */ 	addu	$a3,$t4,$a2
/*  f13bbf0:	94ed0000 */ 	lhu	$t5,0x0($a3)
/*  f13bbf4:	84ee0002 */ 	lh	$t6,0x2($a3)
/*  f13bbf8:	01b02021 */ 	addu	$a0,$t5,$s0
/*  f13bbfc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f13bc00:	a48f0008 */ 	sh	$t7,0x8($a0)
/*  f13bc04:	94b90002 */ 	lhu	$t9,0x2($a1)
/*  f13bc08:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f13bc0c:	00195080 */ 	sll	$t2,$t9,0x2
/*  f13bc10:	01595023 */ 	subu	$t2,$t2,$t9
/*  f13bc14:	000a5040 */ 	sll	$t2,$t2,0x1
/*  f13bc18:	030a4821 */ 	addu	$t1,$t8,$t2
/*  f13bc1c:	01265821 */ 	addu	$t3,$t1,$a2
/*  f13bc20:	856c0004 */ 	lh	$t4,0x4($t3)
/*  f13bc24:	24c60006 */ 	addiu	$a2,$a2,0x6
/*  f13bc28:	a48c000a */ 	sh	$t4,0xa($a0)
/*  f13bc2c:	90ad0001 */ 	lbu	$t5,0x1($a1)
/*  f13bc30:	006d082a */ 	slt	$at,$v1,$t5
/*  f13bc34:	5420ffe7 */ 	bnezl	$at,.L0f13bbd4
/*  f13bc38:	94aa0002 */ 	lhu	$t2,0x2($a1)
.L0f13bc3c:
/*  f13bc3c:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f13bc40:	03e00008 */ 	jr	$ra
/*  f13bc44:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f13bc48
.late_rodata
glabel var7f1b5974
.word func0f13bc48+0x2d8 # f13bf20
glabel var7f1b5978
.word func0f13bc48+0x32c # f13bf74
glabel var7f1b597c
.word func0f13bc48+0x348 # f13bf90
glabel var7f1b5980
.word func0f13bc48+0x2f4 # f13bf3c
glabel var7f1b5984
.word func0f13bc48+0x310 # f13bf58
glabel var7f1b5988
.word func0f13bc48+0x3c4 # f13c00c
glabel var7f1b598c
.word func0f13bc48+0x384 # f13bfcc
.text
/*  f13bc48:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f13bc4c:	3c038008 */ 	lui	$v1,%hi(var8007f6f0)
/*  f13bc50:	8c63f6f0 */ 	lw	$v1,%lo(var8007f6f0)($v1)
/*  f13bc54:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f13bc58:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f13bc5c:	00a09825 */ 	or	$s3,$a1,$zero
/*  f13bc60:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f13bc64:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f13bc68:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f13bc6c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f13bc70:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f13bc74:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f13bc78:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f13bc7c:	1860000c */ 	blez	$v1,.L0f13bcb0
/*  f13bc80:	00008825 */ 	or	$s1,$zero,$zero
/*  f13bc84:	3c02800a */ 	lui	$v0,%hi(var800a4194)
/*  f13bc88:	8c424194 */ 	lw	$v0,%lo(var800a4194)($v0)
.L0f13bc8c:
/*  f13bc8c:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f13bc90:	548e0004 */ 	bnel	$a0,$t6,.L0f13bca4
/*  f13bc94:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f13bc98:	10000005 */ 	b	.L0f13bcb0
/*  f13bc9c:	02203025 */ 	or	$a2,$s1,$zero
/*  f13bca0:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f13bca4:
/*  f13bca4:	0223082a */ 	slt	$at,$s1,$v1
/*  f13bca8:	1420fff8 */ 	bnez	$at,.L0f13bc8c
/*  f13bcac:	2442000c */ 	addiu	$v0,$v0,12
.L0f13bcb0:
/*  f13bcb0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f13bcb4:	10c100e7 */ 	beq	$a2,$at,.L0f13c054
/*  f13bcb8:	3c03800a */ 	lui	$v1,%hi(g_Vars+0xc)
/*  f13bcbc:	3c0f800a */ 	lui	$t7,%hi(var800a4194)
/*  f13bcc0:	8def4194 */ 	lw	$t7,%lo(var800a4194)($t7)
/*  f13bcc4:	0006a080 */ 	sll	$s4,$a2,0x2
/*  f13bcc8:	0286a023 */ 	subu	$s4,$s4,$a2
/*  f13bccc:	0014a080 */ 	sll	$s4,$s4,0x2
/*  f13bcd0:	01f41021 */ 	addu	$v0,$t7,$s4
/*  f13bcd4:	8c580008 */ 	lw	$t8,0x8($v0)
/*  f13bcd8:	8c639fcc */ 	lw	$v1,%lo(g_Vars+0xc)($v1)
/*  f13bcdc:	507800de */ 	beql	$v1,$t8,.L0f13c058
/*  f13bce0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f13bce4:	94590004 */ 	lhu	$t9,0x4($v0)
/*  f13bce8:	3c16800a */ 	lui	$s6,%hi(var800a4190)
/*  f13bcec:	26d64190 */ 	addiu	$s6,$s6,%lo(var800a4190)
/*  f13bcf0:	1b2000d7 */ 	blez	$t9,.L0f13c050
/*  f13bcf4:	00008825 */ 	or	$s1,$zero,$zero
/*  f13bcf8:	3c12800a */ 	lui	$s2,%hi(var800a418c)
/*  f13bcfc:	2652418c */ 	addiu	$s2,$s2,%lo(var800a418c)
/*  f13bd00:	3c150001 */ 	lui	$s5,0x1
/*  f13bd04:	944c0002 */ 	lhu	$t4,0x2($v0)
.L0f13bd08:
/*  f13bd08:	8ecf0000 */ 	lw	$t7,0x0($s6)
/*  f13bd0c:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f13bd10:	01916821 */ 	addu	$t5,$t4,$s1
/*  f13bd14:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f13bd18:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f13bd1c:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f13bd20:	24078002 */ 	addiu	$a3,$zero,-32766
/*  f13bd24:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f13bd28:	30780001 */ 	andi	$t8,$v1,0x1
/*  f13bd2c:	17000068 */ 	bnez	$t8,.L0f13bed0
/*  f13bd30:	24098002 */ 	addiu	$t1,$zero,-32766
/*  f13bd34:	92190001 */ 	lbu	$t9,0x1($s0)
/*  f13bd38:	00005025 */ 	or	$t2,$zero,$zero
/*  f13bd3c:	00005825 */ 	or	$t3,$zero,$zero
/*  f13bd40:	1b20002f */ 	blez	$t9,.L0f13be00
/*  f13bd44:	00008825 */ 	or	$s1,$zero,$zero
/*  f13bd48:	00002025 */ 	or	$a0,$zero,$zero
/*  f13bd4c:	960d0002 */ 	lhu	$t5,0x2($s0)
.L0f13bd50:
/*  f13bd50:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f13bd54:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f13bd58:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f13bd5c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f13bd60:	018e7821 */ 	addu	$t7,$t4,$t6
/*  f13bd64:	01e41021 */ 	addu	$v0,$t7,$a0
/*  f13bd68:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f13bd6c:	03131821 */ 	addu	$v1,$t8,$s3
/*  f13bd70:	84790008 */ 	lh	$t9,0x8($v1)
/*  f13bd74:	a4590002 */ 	sh	$t9,0x2($v0)
/*  f13bd78:	960e0002 */ 	lhu	$t6,0x2($s0)
/*  f13bd7c:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f13bd80:	846d000a */ 	lh	$t5,0xa($v1)
/*  f13bd84:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f13bd88:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f13bd8c:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f13bd90:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f13bd94:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f13bd98:	a72d0004 */ 	sh	$t5,0x4($t9)
/*  f13bd9c:	84650008 */ 	lh	$a1,0x8($v1)
/*  f13bda0:	00a6082a */ 	slt	$at,$a1,$a2
/*  f13bda4:	50200003 */ 	beqzl	$at,.L0f13bdb4
/*  f13bda8:	8462000a */ 	lh	$v0,0xa($v1)
/*  f13bdac:	00a03025 */ 	or	$a2,$a1,$zero
/*  f13bdb0:	8462000a */ 	lh	$v0,0xa($v1)
.L0f13bdb4:
/*  f13bdb4:	0048082a */ 	slt	$at,$v0,$t0
/*  f13bdb8:	50200003 */ 	beqzl	$at,.L0f13bdc8
/*  f13bdbc:	00e5082a */ 	slt	$at,$a3,$a1
/*  f13bdc0:	00404025 */ 	or	$t0,$v0,$zero
/*  f13bdc4:	00e5082a */ 	slt	$at,$a3,$a1
.L0f13bdc8:
/*  f13bdc8:	50200003 */ 	beqzl	$at,.L0f13bdd8
/*  f13bdcc:	0122082a */ 	slt	$at,$t1,$v0
/*  f13bdd0:	00a03825 */ 	or	$a3,$a1,$zero
/*  f13bdd4:	0122082a */ 	slt	$at,$t1,$v0
.L0f13bdd8:
/*  f13bdd8:	50200003 */ 	beqzl	$at,.L0f13bde8
/*  f13bddc:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f13bde0:	00404825 */ 	or	$t1,$v0,$zero
/*  f13bde4:	920e0001 */ 	lbu	$t6,0x1($s0)
.L0f13bde8:
/*  f13bde8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f13bdec:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f13bdf0:	022e082a */ 	slt	$at,$s1,$t6
/*  f13bdf4:	5420ffd6 */ 	bnezl	$at,.L0f13bd50
/*  f13bdf8:	960d0002 */ 	lhu	$t5,0x2($s0)
/*  f13bdfc:	92030000 */ 	lbu	$v1,0x0($s0)
.L0f13be00:
/*  f13be00:	346f0001 */ 	ori	$t7,$v1,0x1
/*  f13be04:	28c1a300 */ 	slti	$at,$a2,-23808
/*  f13be08:	10200002 */ 	beqz	$at,.L0f13be14
/*  f13be0c:	a20f0000 */ 	sb	$t7,0x0($s0)
/*  f13be10:	240a2000 */ 	addiu	$t2,$zero,0x2000
.L0f13be14:
/*  f13be14:	2901a300 */ 	slti	$at,$t0,-23808
/*  f13be18:	50200003 */ 	beqzl	$at,.L0f13be28
/*  f13be1c:	28e15d01 */ 	slti	$at,$a3,0x5d01
/*  f13be20:	240b2000 */ 	addiu	$t3,$zero,0x2000
/*  f13be24:	28e15d01 */ 	slti	$at,$a3,0x5d01
.L0f13be28:
/*  f13be28:	54200003 */ 	bnezl	$at,.L0f13be38
/*  f13be2c:	29215d01 */ 	slti	$at,$t1,0x5d01
/*  f13be30:	240ae000 */ 	addiu	$t2,$zero,-8192
/*  f13be34:	29215d01 */ 	slti	$at,$t1,0x5d01
.L0f13be38:
/*  f13be38:	14200002 */ 	bnez	$at,.L0f13be44
/*  f13be3c:	00000000 */ 	nop
/*  f13be40:	240be000 */ 	addiu	$t3,$zero,-8192
.L0f13be44:
/*  f13be44:	55400004 */ 	bnezl	$t2,.L0f13be58
/*  f13be48:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f13be4c:	11600020 */ 	beqz	$t3,.L0f13bed0
/*  f13be50:	00000000 */ 	nop
/*  f13be54:	92180001 */ 	lbu	$t8,0x1($s0)
.L0f13be58:
/*  f13be58:	00008825 */ 	or	$s1,$zero,$zero
/*  f13be5c:	00002025 */ 	or	$a0,$zero,$zero
/*  f13be60:	1b00001b */ 	blez	$t8,.L0f13bed0
/*  f13be64:	00000000 */ 	nop
/*  f13be68:	96190002 */ 	lhu	$t9,0x2($s0)
.L0f13be6c:
/*  f13be6c:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f13be70:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f13be74:	00197080 */ 	sll	$t6,$t9,0x2
/*  f13be78:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f13be7c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f13be80:	01ae6021 */ 	addu	$t4,$t5,$t6
/*  f13be84:	01841021 */ 	addu	$v0,$t4,$a0
/*  f13be88:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f13be8c:	01eac021 */ 	addu	$t8,$t7,$t2
/*  f13be90:	a4580002 */ 	sh	$t8,0x2($v0)
/*  f13be94:	960d0002 */ 	lhu	$t5,0x2($s0)
/*  f13be98:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f13be9c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f13bea0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f13bea4:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f13bea8:	032e6021 */ 	addu	$t4,$t9,$t6
/*  f13beac:	01841021 */ 	addu	$v0,$t4,$a0
/*  f13beb0:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f13beb4:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f13beb8:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f13bebc:	a4580004 */ 	sh	$t8,0x4($v0)
/*  f13bec0:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f13bec4:	022d082a */ 	slt	$at,$s1,$t5
/*  f13bec8:	5420ffe8 */ 	bnezl	$at,.L0f13be6c
/*  f13becc:	96190002 */ 	lhu	$t9,0x2($s0)
.L0f13bed0:
/*  f13bed0:	3c19800a */ 	lui	$t9,%hi(var800a4194)
/*  f13bed4:	8f394194 */ 	lw	$t9,%lo(var800a4194)($t9)
/*  f13bed8:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f13bedc:	00116880 */ 	sll	$t5,$s1,0x2
/*  f13bee0:	03341021 */ 	addu	$v0,$t9,$s4
/*  f13bee4:	944c0002 */ 	lhu	$t4,0x2($v0)
/*  f13bee8:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f13beec:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f13bef0:	030dc821 */ 	addu	$t9,$t8,$t5
/*  f13bef4:	972c0000 */ 	lhu	$t4,0x0($t9)
/*  f13bef8:	000c7242 */ 	srl	$t6,$t4,0x9
/*  f13befc:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f13bf00:	2de10007 */ 	sltiu	$at,$t7,0x7
/*  f13bf04:	1020004b */ 	beqz	$at,.L0f13c034
/*  f13bf08:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f13bf0c:	3c017f1b */ 	lui	$at,%hi(var7f1b5974)
/*  f13bf10:	002f0821 */ 	addu	$at,$at,$t7
/*  f13bf14:	8c2f5974 */ 	lw	$t7,%lo(var7f1b5974)($at)
/*  f13bf18:	01e00008 */ 	jr	$t7
/*  f13bf1c:	00000000 */ 	nop
/*  f13bf20:	02602025 */ 	or	$a0,$s3,$zero
/*  f13bf24:	0fc4ed9c */ 	jal	func0f13b670
/*  f13bf28:	02002825 */ 	or	$a1,$s0,$zero
/*  f13bf2c:	3c18800a */ 	lui	$t8,%hi(var800a4194)
/*  f13bf30:	8f184194 */ 	lw	$t8,%lo(var800a4194)($t8)
/*  f13bf34:	1000003f */ 	b	.L0f13c034
/*  f13bf38:	03141021 */ 	addu	$v0,$t8,$s4
/*  f13bf3c:	02602025 */ 	or	$a0,$s3,$zero
/*  f13bf40:	0fc4edef */ 	jal	func0f13b7bc
/*  f13bf44:	02002825 */ 	or	$a1,$s0,$zero
/*  f13bf48:	3c0d800a */ 	lui	$t5,%hi(var800a4194)
/*  f13bf4c:	8dad4194 */ 	lw	$t5,%lo(var800a4194)($t5)
/*  f13bf50:	10000038 */ 	b	.L0f13c034
/*  f13bf54:	01b41021 */ 	addu	$v0,$t5,$s4
/*  f13bf58:	02602025 */ 	or	$a0,$s3,$zero
/*  f13bf5c:	0fc4ee28 */ 	jal	func0f13b8a0
/*  f13bf60:	02002825 */ 	or	$a1,$s0,$zero
/*  f13bf64:	3c19800a */ 	lui	$t9,%hi(var800a4194)
/*  f13bf68:	8f394194 */ 	lw	$t9,%lo(var800a4194)($t9)
/*  f13bf6c:	10000031 */ 	b	.L0f13c034
/*  f13bf70:	03341021 */ 	addu	$v0,$t9,$s4
/*  f13bf74:	02602025 */ 	or	$a0,$s3,$zero
/*  f13bf78:	0fc4eed7 */ 	jal	func0f13bb5c
/*  f13bf7c:	02002825 */ 	or	$a1,$s0,$zero
/*  f13bf80:	3c0c800a */ 	lui	$t4,%hi(var800a4194)
/*  f13bf84:	8d8c4194 */ 	lw	$t4,%lo(var800a4194)($t4)
/*  f13bf88:	1000002a */ 	b	.L0f13c034
/*  f13bf8c:	01941021 */ 	addu	$v0,$t4,$s4
/*  f13bf90:	00002025 */ 	or	$a0,$zero,$zero
/*  f13bf94:	0fc127da */ 	jal	chrHasStageFlag
/*  f13bf98:	24050100 */ 	addiu	$a1,$zero,0x100
/*  f13bf9c:	10400007 */ 	beqz	$v0,.L0f13bfbc
/*  f13bfa0:	00002025 */ 	or	$a0,$zero,$zero
/*  f13bfa4:	0fc127da */ 	jal	chrHasStageFlag
/*  f13bfa8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f13bfac:	14400003 */ 	bnez	$v0,.L0f13bfbc
/*  f13bfb0:	02602025 */ 	or	$a0,$s3,$zero
/*  f13bfb4:	0fc4ed9c */ 	jal	func0f13b670
/*  f13bfb8:	02002825 */ 	or	$a1,$s0,$zero
.L0f13bfbc:
/*  f13bfbc:	3c0e800a */ 	lui	$t6,%hi(var800a4194)
/*  f13bfc0:	8dce4194 */ 	lw	$t6,%lo(var800a4194)($t6)
/*  f13bfc4:	1000001b */ 	b	.L0f13c034
/*  f13bfc8:	01d41021 */ 	addu	$v0,$t6,$s4
/*  f13bfcc:	00002025 */ 	or	$a0,$zero,$zero
/*  f13bfd0:	0fc127da */ 	jal	chrHasStageFlag
/*  f13bfd4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f13bfd8:	10400006 */ 	beqz	$v0,.L0f13bff4
/*  f13bfdc:	02602025 */ 	or	$a0,$s3,$zero
/*  f13bfe0:	02602025 */ 	or	$a0,$s3,$zero
/*  f13bfe4:	0fc4edd5 */ 	jal	func0f13b754
/*  f13bfe8:	02002825 */ 	or	$a1,$s0,$zero
/*  f13bfec:	10000003 */ 	b	.L0f13bffc
/*  f13bff0:	00000000 */ 	nop
.L0f13bff4:
/*  f13bff4:	0fc4ed9c */ 	jal	func0f13b670
/*  f13bff8:	02002825 */ 	or	$a1,$s0,$zero
.L0f13bffc:
/*  f13bffc:	3c0f800a */ 	lui	$t7,%hi(var800a4194)
/*  f13c000:	8def4194 */ 	lw	$t7,%lo(var800a4194)($t7)
/*  f13c004:	1000000b */ 	b	.L0f13c034
/*  f13c008:	01f41021 */ 	addu	$v0,$t7,$s4
/*  f13c00c:	00002025 */ 	or	$a0,$zero,$zero
/*  f13c010:	0fc127da */ 	jal	chrHasStageFlag
/*  f13c014:	02a02825 */ 	or	$a1,$s5,$zero
/*  f13c018:	14400003 */ 	bnez	$v0,.L0f13c028
/*  f13c01c:	02602025 */ 	or	$a0,$s3,$zero
/*  f13c020:	0fc4ed9c */ 	jal	func0f13b670
/*  f13c024:	02002825 */ 	or	$a1,$s0,$zero
.L0f13c028:
/*  f13c028:	3c18800a */ 	lui	$t8,%hi(var800a4194)
/*  f13c02c:	8f184194 */ 	lw	$t8,%lo(var800a4194)($t8)
/*  f13c030:	03141021 */ 	addu	$v0,$t8,$s4
.L0f13c034:
/*  f13c034:	944d0004 */ 	lhu	$t5,0x4($v0)
/*  f13c038:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f13c03c:	022d082a */ 	slt	$at,$s1,$t5
/*  f13c040:	5420ff31 */ 	bnezl	$at,.L0f13bd08
/*  f13c044:	944c0002 */ 	lhu	$t4,0x2($v0)
/*  f13c048:	3c03800a */ 	lui	$v1,%hi(g_Vars+0xc)
/*  f13c04c:	8c639fcc */ 	lw	$v1,%lo(g_Vars+0xc)($v1)
.L0f13c050:
/*  f13c050:	ac430008 */ 	sw	$v1,0x8($v0)
.L0f13c054:
/*  f13c054:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f13c058:
/*  f13c058:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f13c05c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f13c060:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f13c064:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f13c068:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f13c06c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f13c070:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f13c074:	03e00008 */ 	jr	$ra
/*  f13c078:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f13c07c
/*  f13c07c:	3c088008 */ 	lui	$t0,%hi(var8007f6e0)
/*  f13c080:	2508f6e0 */ 	addiu	$t0,$t0,%lo(var8007f6e0)
/*  f13c084:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f13c088:	3c038008 */ 	lui	$v1,%hi(var8007f6f8)
/*  f13c08c:	2463f6f8 */ 	addiu	$v1,$v1,%lo(var8007f6f8)
/*  f13c090:	04a00093 */ 	bltz	$a1,.L0f13c2e0
/*  f13c094:	3c0e800a */ 	lui	$t6,%hi(var800a4180)
/*  f13c098:	8dce4180 */ 	lw	$t6,%lo(var800a4180)($t6)
/*  f13c09c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f13c0a0:	3c098008 */ 	lui	$t1,%hi(var8007f6e8)
/*  f13c0a4:	2529f6e8 */ 	addiu	$t1,$t1,%lo(var8007f6e8)
/*  f13c0a8:	11cf008d */ 	beq	$t6,$t7,.L0f13c2e0
/*  f13c0ac:	00000000 */ 	nop
/*  f13c0b0:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f13c0b4:	3c028008 */ 	lui	$v0,%hi(var8007f6f4)
/*  f13c0b8:	2442f6f4 */ 	addiu	$v0,$v0,%lo(var8007f6f4)
/*  f13c0bc:	17000039 */ 	bnez	$t8,.L0f13c1a4
/*  f13c0c0:	3c0d800a */ 	lui	$t5,%hi(var800a4184)
/*  f13c0c4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f13c0c8:	8dad4184 */ 	lw	$t5,%lo(var800a4184)($t5)
/*  f13c0cc:	3c0a8008 */ 	lui	$t2,%hi(var8007f6f0)
/*  f13c0d0:	254af6f0 */ 	addiu	$t2,$t2,%lo(var8007f6f0)
/*  f13c0d4:	032d082a */ 	slt	$at,$t9,$t5
/*  f13c0d8:	10200081 */ 	beqz	$at,.L0f13c2e0
/*  f13c0dc:	3c0e800a */ 	lui	$t6,%hi(var800a4188)
/*  f13c0e0:	8d460000 */ 	lw	$a2,0x0($t2)
/*  f13c0e4:	8dce4188 */ 	lw	$t6,%lo(var800a4188)($t6)
/*  f13c0e8:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f13c0ec:	00ce082a */ 	slt	$at,$a2,$t6
/*  f13c0f0:	1020007b */ 	beqz	$at,.L0f13c2e0
/*  f13c0f4:	00000000 */ 	nop
/*  f13c0f8:	00cc0019 */ 	multu	$a2,$t4
/*  f13c0fc:	3c0b800a */ 	lui	$t3,%hi(var800a4194)
/*  f13c100:	256b4194 */ 	addiu	$t3,$t3,%lo(var800a4194)
/*  f13c104:	8d6f0000 */ 	lw	$t7,0x0($t3)
/*  f13c108:	0000c012 */ 	mflo	$t8
/*  f13c10c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f13c110:	a7250000 */ 	sh	$a1,0x0($t9)
/*  f13c114:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f13c118:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f13c11c:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f13c120:	01ec0019 */ 	multu	$t7,$t4
/*  f13c124:	0000c012 */ 	mflo	$t8
/*  f13c128:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f13c12c:	a72d0002 */ 	sh	$t5,0x2($t9)
/*  f13c130:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f13c134:	8d6f0000 */ 	lw	$t7,0x0($t3)
/*  f13c138:	01cc0019 */ 	multu	$t6,$t4
/*  f13c13c:	0000c012 */ 	mflo	$t8
/*  f13c140:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f13c144:	a5a00004 */ 	sh	$zero,0x4($t5)
/*  f13c148:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f13c14c:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f13c150:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f13c154:	01cc0019 */ 	multu	$t6,$t4
/*  f13c158:	00007812 */ 	mflo	$t7
/*  f13c15c:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f13c160:	af000008 */ 	sw	$zero,0x8($t8)
/*  f13c164:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f13c168:	8dad4928 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f13c16c:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f13c170:	032ec821 */ 	addu	$t9,$t9,$t6
/*  f13c174:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13c178:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f13c17c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13c180:	01b93821 */ 	addu	$a3,$t5,$t9
/*  f13c184:	94ef0000 */ 	lhu	$t7,0x0($a3)
/*  f13c188:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f13c18c:	35f80002 */ 	ori	$t8,$t7,0x2
/*  f13c190:	a4f80000 */ 	sh	$t8,0x0($a3)
/*  f13c194:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f13c198:	ad390000 */ 	sw	$t9,0x0($t1)
/*  f13c19c:	25cd0001 */ 	addiu	$t5,$t6,0x1
/*  f13c1a0:	ad4d0000 */ 	sw	$t5,0x0($t2)
.L0f13c1a4:
/*  f13c1a4:	3c088008 */ 	lui	$t0,%hi(var8007f6ec)
/*  f13c1a8:	2508f6ec */ 	addiu	$t0,$t0,%lo(var8007f6ec)
/*  f13c1ac:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f13c1b0:	3c028008 */ 	lui	$v0,%hi(var8007f6f4)
/*  f13c1b4:	3c0a8008 */ 	lui	$t2,%hi(var8007f6f0)
/*  f13c1b8:	3c0b800a */ 	lui	$t3,%hi(var800a4194)
/*  f13c1bc:	256b4194 */ 	addiu	$t3,$t3,%lo(var800a4194)
/*  f13c1c0:	254af6f0 */ 	addiu	$t2,$t2,%lo(var8007f6f0)
/*  f13c1c4:	2442f6f4 */ 	addiu	$v0,$v0,%lo(var8007f6f4)
/*  f13c1c8:	15e00031 */ 	bnez	$t7,.L0f13c290
/*  f13c1cc:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f13c1d0:	3c18800a */ 	lui	$t8,%hi(var800a4184)
/*  f13c1d4:	8f184184 */ 	lw	$t8,%lo(var800a4184)($t8)
/*  f13c1d8:	8c450000 */ 	lw	$a1,0x0($v0)
/*  f13c1dc:	3c09800a */ 	lui	$t1,%hi(var800a4190)
/*  f13c1e0:	25294190 */ 	addiu	$t1,$t1,%lo(var800a4190)
/*  f13c1e4:	00b8082a */ 	slt	$at,$a1,$t8
/*  f13c1e8:	1020003d */ 	beqz	$at,.L0f13c2e0
/*  f13c1ec:	00056880 */ 	sll	$t5,$a1,0x2
/*  f13c1f0:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f13c1f4:	3c198008 */ 	lui	$t9,%hi(var8007f6e4)
/*  f13c1f8:	8f2ff6e4 */ 	lw	$t7,%lo(var8007f6e4)($t9)
/*  f13c1fc:	01cd3821 */ 	addu	$a3,$t6,$t5
/*  f13c200:	90ed0000 */ 	lbu	$t5,0x0($a3)
/*  f13c204:	000f7040 */ 	sll	$t6,$t7,0x1
/*  f13c208:	31b9ff01 */ 	andi	$t9,$t5,0xff01
/*  f13c20c:	01d97825 */ 	or	$t7,$t6,$t9
/*  f13c210:	a0ef0000 */ 	sb	$t7,0x0($a3)
/*  f13c214:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f13c218:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f13c21c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f13c220:	030e3821 */ 	addu	$a3,$t8,$t6
/*  f13c224:	90f90000 */ 	lbu	$t9,0x0($a3)
/*  f13c228:	332ffffe */ 	andi	$t7,$t9,0xfffe
/*  f13c22c:	a0ef0000 */ 	sb	$t7,0x0($a3)
/*  f13c230:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f13c234:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f13c238:	00187080 */ 	sll	$t6,$t8,0x2
/*  f13c23c:	01aec821 */ 	addu	$t9,$t5,$t6
/*  f13c240:	a3200001 */ 	sb	$zero,0x1($t9)
/*  f13c244:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f13c248:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f13c24c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f13c250:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f13c254:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f13c258:	a72f0002 */ 	sh	$t7,0x2($t9)
/*  f13c25c:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f13c260:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f13c264:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f13c268:	01ec0019 */ 	multu	$t7,$t4
/*  f13c26c:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f13c270:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f13c274:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f13c278:	0000c812 */ 	mflo	$t9
/*  f13c27c:	01d93021 */ 	addu	$a2,$t6,$t9
/*  f13c280:	94cdfff8 */ 	lhu	$t5,-0x8($a2)
/*  f13c284:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f13c288:	a4d8fff8 */ 	sh	$t8,-0x8($a2)
/*  f13c28c:	ad0f0000 */ 	sw	$t7,0x0($t0)
.L0f13c290:
/*  f13c290:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f13c294:	3c0e800a */ 	lui	$t6,%hi(var800a418c)
/*  f13c298:	8dce418c */ 	lw	$t6,%lo(var800a418c)($t6)
/*  f13c29c:	00196880 */ 	sll	$t5,$t9,0x2
/*  f13c2a0:	01b96823 */ 	subu	$t5,$t5,$t9
/*  f13c2a4:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f13c2a8:	01cdc021 */ 	addu	$t8,$t6,$t5
/*  f13c2ac:	a7040000 */ 	sh	$a0,0x0($t8)
/*  f13c2b0:	3c09800a */ 	lui	$t1,%hi(var800a4190)
/*  f13c2b4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f13c2b8:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f13c2bc:	25294190 */ 	addiu	$t1,$t1,%lo(var800a4190)
/*  f13c2c0:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f13c2c4:	25f90001 */ 	addiu	$t9,$t7,0x1
/*  f13c2c8:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f13c2cc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f13c2d0:	01d83821 */ 	addu	$a3,$t6,$t8
/*  f13c2d4:	90effffd */ 	lbu	$t7,-0x3($a3)
/*  f13c2d8:	25f90001 */ 	addiu	$t9,$t7,0x1
/*  f13c2dc:	a0f9fffd */ 	sb	$t9,-0x3($a3)
.L0f13c2e0:
/*  f13c2e0:	03e00008 */ 	jr	$ra
/*  f13c2e4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f13c2e8
/*  f13c2e8:	3c028008 */ 	lui	$v0,%hi(g_StageIndex)
/*  f13c2ec:	8c42fc00 */ 	lw	$v0,%lo(g_StageIndex)($v0)
/*  f13c2f0:	00047400 */ 	sll	$t6,$a0,0x10
/*  f13c2f4:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f13c2f8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f13c2fc:	24010013 */ 	addiu	$at,$zero,0x13
/*  f13c300:	10410019 */ 	beq	$v0,$at,.L0f13c368
/*  f13c304:	01e02025 */ 	or	$a0,$t7,$zero
/*  f13c308:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f13c30c:	14410002 */ 	bne	$v0,$at,.L0f13c318
/*  f13c310:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13c314:	11e10014 */ 	beq	$t7,$at,.L0f13c368
.L0f13c318:
/*  f13c318:	24010018 */ 	addiu	$at,$zero,0x18
/*  f13c31c:	14410002 */ 	bne	$v0,$at,.L0f13c328
/*  f13c320:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13c324:	10810010 */ 	beq	$a0,$at,.L0f13c368
.L0f13c328:
/*  f13c328:	24010020 */ 	addiu	$at,$zero,0x20
/*  f13c32c:	10410006 */ 	beq	$v0,$at,.L0f13c348
/*  f13c330:	24010006 */ 	addiu	$at,$zero,0x6
/*  f13c334:	10810003 */ 	beq	$a0,$at,.L0f13c344
/*  f13c338:	24010007 */ 	addiu	$at,$zero,0x7
/*  f13c33c:	14810002 */ 	bne	$a0,$at,.L0f13c348
/*  f13c340:	00000000 */ 	nop
.L0f13c344:
/*  f13c344:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f13c348:
/*  f13c348:	3c028008 */ 	lui	$v0,%hi(var8007f6e4)
/*  f13c34c:	2442f6e4 */ 	addiu	$v0,$v0,%lo(var8007f6e4)
/*  f13c350:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f13c354:	3c018008 */ 	lui	$at,%hi(var8007f6ec)
/*  f13c358:	50980003 */ 	beql	$a0,$t8,.L0f13c368
/*  f13c35c:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f13c360:	ac20f6ec */ 	sw	$zero,%lo(var8007f6ec)($at)
/*  f13c364:	ac440000 */ 	sw	$a0,0x0($v0)
.L0f13c368:
/*  f13c368:	03e00008 */ 	jr	$ra
/*  f13c36c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f13c370
/*  f13c370:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f13c374:	00047400 */ 	sll	$t6,$a0,0x10
/*  f13c378:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f13c37c:	0480000e */ 	bltz	$a0,.L0f13c3b8
/*  f13c380:	3c038008 */ 	lui	$v1,%hi(var8007f6f0)
/*  f13c384:	8c63f6f0 */ 	lw	$v1,%lo(var8007f6f0)($v1)
/*  f13c388:	00001025 */ 	or	$v0,$zero,$zero
/*  f13c38c:	3c05800a */ 	lui	$a1,%hi(var800a4194)
/*  f13c390:	18600009 */ 	blez	$v1,.L0f13c3b8
/*  f13c394:	00000000 */ 	nop
/*  f13c398:	8ca54194 */ 	lw	$a1,%lo(var800a4194)($a1)
.L0f13c39c:
/*  f13c39c:	94b80000 */ 	lhu	$t8,0x0($a1)
/*  f13c3a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f13c3a4:	0043082a */ 	slt	$at,$v0,$v1
/*  f13c3a8:	10980010 */ 	beq	$a0,$t8,.L0f13c3ec
/*  f13c3ac:	00000000 */ 	nop
/*  f13c3b0:	1420fffa */ 	bnez	$at,.L0f13c39c
/*  f13c3b4:	24a5000c */ 	addiu	$a1,$a1,12
.L0f13c3b8:
/*  f13c3b8:	3c19800a */ 	lui	$t9,%hi(var800a4194)
/*  f13c3bc:	8f394194 */ 	lw	$t9,%lo(var800a4194)($t9)
/*  f13c3c0:	3c018008 */ 	lui	$at,%hi(var8007f6e8)
/*  f13c3c4:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f13c3c8:	13200008 */ 	beqz	$t9,.L0f13c3ec
/*  f13c3cc:	00000000 */ 	nop
/*  f13c3d0:	ac20f6e8 */ 	sw	$zero,%lo(var8007f6e8)($at)
/*  f13c3d4:	3c018008 */ 	lui	$at,%hi(var8007f6ec)
/*  f13c3d8:	ac20f6ec */ 	sw	$zero,%lo(var8007f6ec)($at)
/*  f13c3dc:	3c018008 */ 	lui	$at,%hi(var8007f6e0)
/*  f13c3e0:	ac24f6e0 */ 	sw	$a0,%lo(var8007f6e0)($at)
/*  f13c3e4:	3c018008 */ 	lui	$at,%hi(var8007f6e4)
/*  f13c3e8:	ac28f6e4 */ 	sw	$t0,%lo(var8007f6e4)($at)
.L0f13c3ec:
/*  f13c3ec:	03e00008 */ 	jr	$ra
/*  f13c3f0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f13c3f4
/*  f13c3f4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f13c3f8:	3c018008 */ 	lui	$at,%hi(var8007f6e0)
/*  f13c3fc:	ac22f6e0 */ 	sw	$v0,%lo(var8007f6e0)($at)
/*  f13c400:	3c018008 */ 	lui	$at,%hi(var8007f6e4)
/*  f13c404:	ac22f6e4 */ 	sw	$v0,%lo(var8007f6e4)($at)
/*  f13c408:	3c018008 */ 	lui	$at,%hi(var8007f6e8)
/*  f13c40c:	ac20f6e8 */ 	sw	$zero,%lo(var8007f6e8)($at)
/*  f13c410:	3c018008 */ 	lui	$at,%hi(var8007f6f0)
/*  f13c414:	ac20f6f0 */ 	sw	$zero,%lo(var8007f6f0)($at)
/*  f13c418:	3c018008 */ 	lui	$at,%hi(var8007f6f4)
/*  f13c41c:	ac20f6f4 */ 	sw	$zero,%lo(var8007f6f4)($at)
/*  f13c420:	3c018008 */ 	lui	$at,%hi(var8007f6f8)
/*  f13c424:	ac20f6f8 */ 	sw	$zero,%lo(var8007f6f8)($at)
/*  f13c428:	3c01800a */ 	lui	$at,%hi(var800a4180)
/*  f13c42c:	240e04b0 */ 	addiu	$t6,$zero,0x4b0
/*  f13c430:	3c06800a */ 	lui	$a2,%hi(var800a4184)
/*  f13c434:	ac2e4180 */ 	sw	$t6,%lo(var800a4180)($at)
/*  f13c438:	24c64184 */ 	addiu	$a2,$a2,%lo(var800a4184)
/*  f13c43c:	24030032 */ 	addiu	$v1,$zero,0x32
/*  f13c440:	acc30000 */ 	sw	$v1,0x0($a2)
/*  f13c444:	3c01800a */ 	lui	$at,%hi(var800a4188)
/*  f13c448:	ac234188 */ 	sw	$v1,%lo(var800a4188)($at)
/*  f13c44c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f13c450:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f13c454:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f13c458:	00047880 */ 	sll	$t7,$a0,0x2
/*  f13c45c:	25e4003f */ 	addiu	$a0,$t7,0x3f
/*  f13c460:	3498003f */ 	ori	$t8,$a0,0x3f
/*  f13c464:	3b04003f */ 	xori	$a0,$t8,0x3f
/*  f13c468:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f13c46c:	0c0048f2 */ 	jal	malloc
/*  f13c470:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f13c474:	3c04800a */ 	lui	$a0,%hi(var800a4180)
/*  f13c478:	8c844180 */ 	lw	$a0,%lo(var800a4180)($a0)
/*  f13c47c:	3c01800a */ 	lui	$at,%hi(var800a4190)
/*  f13c480:	ac224190 */ 	sw	$v0,%lo(var800a4190)($at)
/*  f13c484:	00044080 */ 	sll	$t0,$a0,0x2
/*  f13c488:	01044023 */ 	subu	$t0,$t0,$a0
/*  f13c48c:	00084040 */ 	sll	$t0,$t0,0x1
/*  f13c490:	2504003f */ 	addiu	$a0,$t0,0x3f
/*  f13c494:	3489003f */ 	ori	$t1,$a0,0x3f
/*  f13c498:	3924003f */ 	xori	$a0,$t1,0x3f
/*  f13c49c:	0c0048f2 */ 	jal	malloc
/*  f13c4a0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f13c4a4:	3c04800a */ 	lui	$a0,%hi(var800a4188)
/*  f13c4a8:	8c844188 */ 	lw	$a0,%lo(var800a4188)($a0)
/*  f13c4ac:	3c01800a */ 	lui	$at,%hi(var800a418c)
/*  f13c4b0:	ac22418c */ 	sw	$v0,%lo(var800a418c)($at)
/*  f13c4b4:	00045880 */ 	sll	$t3,$a0,0x2
/*  f13c4b8:	01645823 */ 	subu	$t3,$t3,$a0
/*  f13c4bc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f13c4c0:	2564003f */ 	addiu	$a0,$t3,0x3f
/*  f13c4c4:	348c003f */ 	ori	$t4,$a0,0x3f
/*  f13c4c8:	3984003f */ 	xori	$a0,$t4,0x3f
/*  f13c4cc:	0c0048f2 */ 	jal	malloc
/*  f13c4d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f13c4d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f13c4d8:	3c01800a */ 	lui	$at,%hi(var800a4194)
/*  f13c4dc:	ac224194 */ 	sw	$v0,%lo(var800a4194)($at)
/*  f13c4e0:	03e00008 */ 	jr	$ra
/*  f13c4e4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f13c4e8:	03e00008 */ 	jr	$ra
/*  f13c4ec:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f13c4f0
/*  f13c4f0:	3c028008 */ 	lui	$v0,%hi(var8007f6e0)
/*  f13c4f4:	8c42f6e0 */ 	lw	$v0,%lo(var8007f6e0)($v0)
/*  f13c4f8:	284e0000 */ 	slti	$t6,$v0,0x0
/*  f13c4fc:	03e00008 */ 	jr	$ra
/*  f13c500:	39c20001 */ 	xori	$v0,$t6,0x1
/*  f13c504:	00000000 */ 	nop
/*  f13c508:	00000000 */ 	nop
/*  f13c50c:	00000000 */ 	nop
);
