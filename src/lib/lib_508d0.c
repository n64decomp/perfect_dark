#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_50480.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func000508d0
/*    508d0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    508d4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    508d8:	afb30020 */ 	sw	$s3,0x20($sp)
/*    508dc:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    508e0:	afb10018 */ 	sw	$s1,0x18($sp)
/*    508e4:	afb00014 */ 	sw	$s0,0x14($sp)
/*    508e8:	afa5005c */ 	sw	$a1,0x5c($sp)
/*    508ec:	afa60060 */ 	sw	$a2,0x60($sp)
/*    508f0:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*    508f4:	00808825 */ 	or	$s1,$a0,$zero
/*    508f8:	00009025 */ 	or	$s2,$zero,$zero
/*    508fc:	31cf0001 */ 	andi	$t7,$t6,0x1
/*    50900:	15e00003 */ 	bnez	$t7,.L00050910
/*    50904:	00000000 */ 	nop
/*    50908:	10000034 */ 	b	.L000509dc
/*    5090c:	24020005 */ 	addiu	$v0,$zero,0x5
.L00050910:
/*    50910:	0c013218 */ 	jal	__osCheckId
/*    50914:	02202025 */ 	or	$a0,$s1,$zero
/*    50918:	50400004 */ 	beqzl	$v0,.L0005092c
/*    5091c:	92380065 */ 	lbu	$t8,0x65($s1)
/*    50920:	1000002f */ 	b	.L000509e0
/*    50924:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    50928:	92380065 */ 	lbu	$t8,0x65($s1)
.L0005092c:
/*    5092c:	02202025 */ 	or	$a0,$s1,$zero
/*    50930:	53000008 */ 	beqzl	$t8,.L00050954
/*    50934:	8e390050 */ 	lw	$t9,0x50($s1)
/*    50938:	0c013378 */ 	jal	__osPfsSelectBank
/*    5093c:	00002825 */ 	or	$a1,$zero,$zero
/*    50940:	50400004 */ 	beqzl	$v0,.L00050954
/*    50944:	8e390050 */ 	lw	$t9,0x50($s1)
/*    50948:	10000025 */ 	b	.L000509e0
/*    5094c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    50950:	8e390050 */ 	lw	$t9,0x50($s1)
.L00050954:
/*    50954:	00008025 */ 	or	$s0,$zero,$zero
/*    50958:	27b30030 */ 	addiu	$s3,$sp,0x30
/*    5095c:	5b200018 */ 	blezl	$t9,.L000509c0
/*    50960:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    50964:	8e28005c */ 	lw	$t0,0x5c($s1)
.L00050968:
/*    50968:	8e240004 */ 	lw	$a0,0x4($s1)
/*    5096c:	8e250008 */ 	lw	$a1,0x8($s1)
/*    50970:	01103021 */ 	addu	$a2,$t0,$s0
/*    50974:	30c9ffff */ 	andi	$t1,$a2,0xffff
/*    50978:	01203025 */ 	or	$a2,$t1,$zero
/*    5097c:	0c012e18 */ 	jal	__osContRamRead
/*    50980:	02603825 */ 	or	$a3,$s3,$zero
/*    50984:	10400003 */ 	beqz	$v0,.L00050994
/*    50988:	97aa0034 */ 	lhu	$t2,0x34($sp)
/*    5098c:	10000014 */ 	b	.L000509e0
/*    50990:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00050994:
/*    50994:	11400004 */ 	beqz	$t2,.L000509a8
/*    50998:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    5099c:	51600003 */ 	beqzl	$t3,.L000509ac
/*    509a0:	8e2c0050 */ 	lw	$t4,0x50($s1)
/*    509a4:	26520001 */ 	addiu	$s2,$s2,0x1
.L000509a8:
/*    509a8:	8e2c0050 */ 	lw	$t4,0x50($s1)
.L000509ac:
/*    509ac:	26100001 */ 	addiu	$s0,$s0,0x1
/*    509b0:	020c082a */ 	slt	$at,$s0,$t4
/*    509b4:	5420ffec */ 	bnezl	$at,.L00050968
/*    509b8:	8e28005c */ 	lw	$t0,0x5c($s1)
/*    509bc:	8fad0060 */ 	lw	$t5,0x60($sp)
.L000509c0:
/*    509c0:	adb20000 */ 	sw	$s2,0x0($t5)
/*    509c4:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    509c8:	8e2e0050 */ 	lw	$t6,0x50($s1)
/*    509cc:	adee0000 */ 	sw	$t6,0x0($t7)
/*    509d0:	8e250008 */ 	lw	$a1,0x8($s1)
/*    509d4:	0c012ea4 */ 	jal	__osPfsGetStatus
/*    509d8:	8e240004 */ 	lw	$a0,0x4($s1)
.L000509dc:
/*    509dc:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L000509e0:
/*    509e0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    509e4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    509e8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    509ec:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    509f0:	03e00008 */ 	jr	$ra
/*    509f4:	27bd0058 */ 	addiu	$sp,$sp,0x58
);
