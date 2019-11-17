#include <ultra64.h>
#include "types.h"
#include "library/library_4ae00.h"

const char var70054030[] = "0123456789abcdefghijklmnopqrstuvwxyz";
const char var70054058[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

GLOBAL_ASM(
glabel func00013820
/*    13820:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    13824:	8fae0048 */ 	lw	$t6,0x48($sp)
/*    13828:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1382c:	afb10018 */ 	sw	$s1,0x18($sp)
/*    13830:	afb00014 */ 	sw	$s0,0x14($sp)
/*    13834:	afa40038 */ 	sw	$a0,0x38($sp)
/*    13838:	11c00004 */ 	beqz	$t6,.L0001384c
/*    1383c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    13840:	3c117005 */ 	lui	$s1,%hi(var70054058)
/*    13844:	10000003 */ 	beqz	$zero,.L00013854
/*    13848:	26314058 */ 	addiu	$s1,$s1,%lo(var70054058)
.L0001384c:
/*    1384c:	3c117005 */ 	lui	$s1,%hi(var70054030)
/*    13850:	26314030 */ 	addiu	$s1,$s1,%lo(var70054030)
.L00013854:
/*    13854:	00c08025 */ 	or	$s0,$a2,$zero
/*    13858:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    1385c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    13860:	17000003 */ 	bnez	$t8,.L00013870
/*    13864:	24080000 */ 	addiu	$t0,$zero,0x0
/*    13868:	53200018 */ 	beqzl	$t9,.L000138cc
/*    1386c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00013870:
/*    13870:	afa80020 */ 	sw	$t0,0x20($sp)
/*    13874:	afa70024 */ 	sw	$a3,0x24($sp)
.L00013878:
/*    13878:	2610ffff */ 	addiu	$s0,$s0,-1
.L0001387c:
/*    1387c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    13880:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*    13884:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    13888:	0c012b8b */ 	jal	func0004ae2c
/*    1388c:	8fa70024 */ 	lw	$a3,0x24($sp)
/*    13890:	00715021 */ 	addu	$t2,$v1,$s1
/*    13894:	914b0000 */ 	lbu	$t3,0x0($t2)
/*    13898:	a20b0000 */ 	sb	$t3,0x0($s0)
/*    1389c:	8fa70024 */ 	lw	$a3,0x24($sp)
/*    138a0:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    138a4:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*    138a8:	0c012b9a */ 	jal	func0004ae68
/*    138ac:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    138b0:	afa20038 */ 	sw	$v0,0x38($sp)
/*    138b4:	afa3003c */ 	sw	$v1,0x3c($sp)
/*    138b8:	1440ffef */ 	bnez	$v0,.L00013878
/*    138bc:	00606825 */ 	or	$t5,$v1,$zero
/*    138c0:	55a0ffee */ 	bnezl	$t5,.L0001387c
/*    138c4:	2610ffff */ 	addiu	$s0,$s0,-1
/*    138c8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L000138cc:
/*    138cc:	02001025 */ 	or	$v0,$s0,$zero
/*    138d0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    138d4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    138d8:	03e00008 */ 	jr	$ra
/*    138dc:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    138e0:	afa40000 */ 	sw	$a0,0x0($sp)
/*    138e4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    138e8:	afa60008 */ 	sw	$a2,0x8($sp)
/*    138ec:	03e00008 */ 	jr	$ra
/*    138f0:	00001025 */ 	or	$v0,$zero,$zero
/*    138f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    138f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    138fc:	00000000 */ 	sll	$zero,$zero,0x0
);
