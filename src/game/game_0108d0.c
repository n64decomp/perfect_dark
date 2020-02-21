#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0108d0
/*  f0108d0:	3c088009 */ 	lui	$t0,%hi(g_Is4Mb)
/*  f0108d4:	25080af0 */ 	addiu	$t0,$t0,%lo(g_Is4Mb)
/*  f0108d8:	910e0000 */ 	lbu	$t6,0x0($t0)
/*  f0108dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0108e0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0108e4:	14ee0003 */ 	bne	$a3,$t6,.L0f0108f4
/*  f0108e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0108ec:	10000002 */ 	beqz	$zero,.L0f0108f8
/*  f0108f0:	2403001e */ 	addiu	$v1,$zero,0x1e
.L0f0108f4:
/*  f0108f4:	24030028 */ 	addiu	$v1,$zero,0x28
.L0f0108f8:
/*  f0108f8:	00032100 */ 	sll	$a0,$v1,0x4
/*  f0108fc:	00832023 */ 	subu	$a0,$a0,$v1
/*  f010900:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f010904:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f010908:	348f000f */ 	ori	$t7,$a0,0xf
/*  f01090c:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f010910:	0c0048f2 */ 	jal	malloc
/*  f010914:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f010918:	3c088009 */ 	lui	$t0,%hi(g_Is4Mb)
/*  f01091c:	25080af0 */ 	addiu	$t0,$t0,%lo(g_Is4Mb)
/*  f010920:	91190000 */ 	lbu	$t9,0x0($t0)
/*  f010924:	3c058007 */ 	lui	$a1,%hi(var8006ae10)
/*  f010928:	24a5ae10 */ 	addiu	$a1,$a1,%lo(var8006ae10)
/*  f01092c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f010930:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f010934:	14f90003 */ 	bne	$a3,$t9,.L0f010944
/*  f010938:	00002025 */ 	or	$a0,$zero,$zero
/*  f01093c:	10000002 */ 	beqz	$zero,.L0f010948
/*  f010940:	2403001e */ 	addiu	$v1,$zero,0x1e
.L0f010944:
/*  f010944:	24030028 */ 	addiu	$v1,$zero,0x28
.L0f010948:
/*  f010948:	1860001a */ 	blez	$v1,.L0f0109b4
/*  f01094c:	00041100 */ 	sll	$v0,$a0,0x4
/*  f010950:	3c01bf80 */ 	lui	$at,0xbf80
/*  f010954:	00441023 */ 	subu	$v0,$v0,$a0
/*  f010958:	44810000 */ 	mtc1	$at,$f0
/*  f01095c:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f010960:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f010964:	8ca90000 */ 	lw	$t1,0x0($a1)
.L0f010968:
/*  f010968:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f01096c:	24030028 */ 	addiu	$v1,$zero,0x28
/*  f010970:	01225021 */ 	addu	$t2,$t1,$v0
/*  f010974:	a5460030 */ 	sh	$a2,0x30($t2)
/*  f010978:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f01097c:	01626021 */ 	addu	$t4,$t3,$v0
/*  f010980:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f010984:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f010988:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f01098c:	e5c0004c */ 	swc1	$f0,0x4c($t6)
/*  f010990:	910f0000 */ 	lbu	$t7,0x0($t0)
/*  f010994:	24420078 */ 	addiu	$v0,$v0,0x78
/*  f010998:	14ef0003 */ 	bne	$a3,$t7,.L0f0109a8
/*  f01099c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0109a0:	10000001 */ 	beqz	$zero,.L0f0109a8
/*  f0109a4:	2403001e */ 	addiu	$v1,$zero,0x1e
.L0f0109a8:
/*  f0109a8:	0083082a */ 	slt	$at,$a0,$v1
/*  f0109ac:	5420ffee */ 	bnezl	$at,.L0f010968
/*  f0109b0:	8ca90000 */ 	lw	$t1,0x0($a1)
.L0f0109b4:
/*  f0109b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0109b8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0109bc:	03e00008 */ 	jr	$ra
/*  f0109c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0109c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0109c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0109cc:	00000000 */ 	sll	$zero,$zero,0x0
);
