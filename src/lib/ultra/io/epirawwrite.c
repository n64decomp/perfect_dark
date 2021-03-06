#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel osEPiRawWriteIo
/*    51900:	3c03a460 */ 	lui	$v1,0xa460
/*    51904:	34630010 */ 	ori	$v1,$v1,0x10
/*    51908:	8c620000 */ 	lw	$v0,0x0($v1)
/*    5190c:	00a03825 */ 	or	$a3,$a1,$zero
/*    51910:	304e0003 */ 	andi	$t6,$v0,0x3
/*    51914:	51c00006 */ 	beqzl	$t6,.L00051930
/*    51918:	90820009 */ 	lbu	$v0,0x9($a0)
/*    5191c:	8c620000 */ 	lw	$v0,0x0($v1)
.L00051920:
/*    51920:	304f0003 */ 	andi	$t7,$v0,0x3
/*    51924:	55e0fffe */ 	bnezl	$t7,.L00051920
/*    51928:	8c620000 */ 	lw	$v0,0x0($v1)
/*    5192c:	90820009 */ 	lbu	$v0,0x9($a0)
.L00051930:
/*    51930:	3c038006 */ 	lui	$v1,%hi(__osCurrentHandle)
/*    51934:	90990004 */ 	lbu	$t9,0x4($a0)
/*    51938:	0002c080 */ 	sll	$t8,$v0,0x2
/*    5193c:	00781821 */ 	addu	$v1,$v1,$t8
/*    51940:	8c63cf20 */ 	lw	$v1,%lo(__osCurrentHandle)($v1)
/*    51944:	90680004 */ 	lbu	$t0,0x4($v1)
/*    51948:	5328003d */ 	beql	$t9,$t0,.L00051a40
/*    5194c:	8c8a000c */ 	lw	$t2,0xc($a0)
/*    51950:	14400019 */ 	bnez	$v0,.L000519b8
/*    51954:	00602825 */ 	or	$a1,$v1,$zero
/*    51958:	90820005 */ 	lbu	$v0,0x5($a0)
/*    5195c:	90690005 */ 	lbu	$t1,0x5($v1)
/*    51960:	3c0aa460 */ 	lui	$t2,0xa460
/*    51964:	3c0ca460 */ 	lui	$t4,0xa460
/*    51968:	10490002 */ 	beq	$v0,$t1,.L00051974
/*    5196c:	3c0ea460 */ 	lui	$t6,0xa460
/*    51970:	ad420014 */ 	sw	$v0,0x14($t2)
.L00051974:
/*    51974:	90820006 */ 	lbu	$v0,0x6($a0)
/*    51978:	90ab0006 */ 	lbu	$t3,0x6($a1)
/*    5197c:	3c18a460 */ 	lui	$t8,0xa460
/*    51980:	504b0003 */ 	beql	$v0,$t3,.L00051990
/*    51984:	90820007 */ 	lbu	$v0,0x7($a0)
/*    51988:	ad82001c */ 	sw	$v0,0x1c($t4)
/*    5198c:	90820007 */ 	lbu	$v0,0x7($a0)
.L00051990:
/*    51990:	90ad0007 */ 	lbu	$t5,0x7($a1)
/*    51994:	504d0003 */ 	beql	$v0,$t5,.L000519a4
/*    51998:	90820008 */ 	lbu	$v0,0x8($a0)
/*    5199c:	adc20020 */ 	sw	$v0,0x20($t6)
/*    519a0:	90820008 */ 	lbu	$v0,0x8($a0)
.L000519a4:
/*    519a4:	90af0008 */ 	lbu	$t7,0x8($a1)
/*    519a8:	504f001b */ 	beql	$v0,$t7,.L00051a18
/*    519ac:	908f0004 */ 	lbu	$t7,0x4($a0)
/*    519b0:	10000018 */ 	b	.L00051a14
/*    519b4:	af020018 */ 	sw	$v0,0x18($t8)
.L000519b8:
/*    519b8:	90820005 */ 	lbu	$v0,0x5($a0)
/*    519bc:	90b90005 */ 	lbu	$t9,0x5($a1)
/*    519c0:	3c08a460 */ 	lui	$t0,0xa460
/*    519c4:	3c0aa460 */ 	lui	$t2,0xa460
/*    519c8:	10590002 */ 	beq	$v0,$t9,.L000519d4
/*    519cc:	3c0ca460 */ 	lui	$t4,0xa460
/*    519d0:	ad020024 */ 	sw	$v0,0x24($t0)
.L000519d4:
/*    519d4:	90820006 */ 	lbu	$v0,0x6($a0)
/*    519d8:	90a90006 */ 	lbu	$t1,0x6($a1)
/*    519dc:	3c0ea460 */ 	lui	$t6,0xa460
/*    519e0:	50490003 */ 	beql	$v0,$t1,.L000519f0
/*    519e4:	90820007 */ 	lbu	$v0,0x7($a0)
/*    519e8:	ad42002c */ 	sw	$v0,0x2c($t2)
/*    519ec:	90820007 */ 	lbu	$v0,0x7($a0)
.L000519f0:
/*    519f0:	90ab0007 */ 	lbu	$t3,0x7($a1)
/*    519f4:	504b0003 */ 	beql	$v0,$t3,.L00051a04
/*    519f8:	90820008 */ 	lbu	$v0,0x8($a0)
/*    519fc:	ad820030 */ 	sw	$v0,0x30($t4)
/*    51a00:	90820008 */ 	lbu	$v0,0x8($a0)
.L00051a04:
/*    51a04:	90ad0008 */ 	lbu	$t5,0x8($a1)
/*    51a08:	504d0003 */ 	beql	$v0,$t5,.L00051a18
/*    51a0c:	908f0004 */ 	lbu	$t7,0x4($a0)
/*    51a10:	adc20028 */ 	sw	$v0,0x28($t6)
.L00051a14:
/*    51a14:	908f0004 */ 	lbu	$t7,0x4($a0)
.L00051a18:
/*    51a18:	a0af0004 */ 	sb	$t7,0x4($a1)
/*    51a1c:	90980005 */ 	lbu	$t8,0x5($a0)
/*    51a20:	a0b80005 */ 	sb	$t8,0x5($a1)
/*    51a24:	90990006 */ 	lbu	$t9,0x6($a0)
/*    51a28:	a0b90006 */ 	sb	$t9,0x6($a1)
/*    51a2c:	90880007 */ 	lbu	$t0,0x7($a0)
/*    51a30:	a0a80007 */ 	sb	$t0,0x7($a1)
/*    51a34:	90890008 */ 	lbu	$t1,0x8($a0)
/*    51a38:	a0a90008 */ 	sb	$t1,0x8($a1)
/*    51a3c:	8c8a000c */ 	lw	$t2,0xc($a0)
.L00051a40:
/*    51a40:	3c01a000 */ 	lui	$at,0xa000
/*    51a44:	00001025 */ 	or	$v0,$zero,$zero
/*    51a48:	01475825 */ 	or	$t3,$t2,$a3
/*    51a4c:	01616025 */ 	or	$t4,$t3,$at
/*    51a50:	03e00008 */ 	jr	$ra
/*    51a54:	ad860000 */ 	sw	$a2,0x0($t4)
);
