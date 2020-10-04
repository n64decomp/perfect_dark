#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osSiRawStartDma
/*    4a8d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4a8d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a8d8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4a8dc:	3c0ea480 */ 	lui	$t6,0xa480
/*    4a8e0:	8dcf0018 */ 	lw	$t7,0x18($t6)
/*    4a8e4:	00803025 */ 	or	$a2,$a0,$zero
/*    4a8e8:	24010001 */ 	addiu	$at,$zero,0x1
/*    4a8ec:	31f80003 */ 	andi	$t8,$t7,0x3
/*    4a8f0:	13000003 */ 	beqz	$t8,.L0004a900
/*    4a8f4:	00000000 */ 	nop
/*    4a8f8:	1000001c */ 	b	.L0004a96c
/*    4a8fc:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004a900:
/*    4a900:	14c10005 */ 	bne	$a2,$at,.L0004a918
/*    4a904:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4a908:	24050040 */ 	addiu	$a1,$zero,0x40
/*    4a90c:	0c012b60 */ 	jal	osWritebackDCache
/*    4a910:	afa60018 */ 	sw	$a2,0x18($sp)
/*    4a914:	8fa60018 */ 	lw	$a2,0x18($sp)
.L0004a918:
/*    4a918:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4a91c:	0c012d20 */ 	jal	osVirtualToPhysical
/*    4a920:	afa60018 */ 	sw	$a2,0x18($sp)
/*    4a924:	8fa60018 */ 	lw	$a2,0x18($sp)
/*    4a928:	3c19a480 */ 	lui	$t9,0xa480
/*    4a92c:	af220000 */ 	sw	$v0,0x0($t9)
/*    4a930:	14c00006 */ 	bnez	$a2,.L0004a94c
/*    4a934:	3c0a1fc0 */ 	lui	$t2,0x1fc0
/*    4a938:	3c081fc0 */ 	lui	$t0,0x1fc0
/*    4a93c:	350807c0 */ 	ori	$t0,$t0,0x7c0
/*    4a940:	3c09a480 */ 	lui	$t1,0xa480
/*    4a944:	10000004 */ 	b	.L0004a958
/*    4a948:	ad280004 */ 	sw	$t0,0x4($t1)
.L0004a94c:
/*    4a94c:	354a07c0 */ 	ori	$t2,$t2,0x7c0
/*    4a950:	3c0ba480 */ 	lui	$t3,0xa480
/*    4a954:	ad6a0010 */ 	sw	$t2,0x10($t3)
.L0004a958:
/*    4a958:	14c00003 */ 	bnez	$a2,.L0004a968
/*    4a95c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4a960:	0c013920 */ 	jal	osInvalDCache
/*    4a964:	24050040 */ 	addiu	$a1,$zero,0x40
.L0004a968:
/*    4a968:	00001025 */ 	or	$v0,$zero,$zero
.L0004a96c:
/*    4a96c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a970:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4a974:	03e00008 */ 	jr	$ra
/*    4a978:	00000000 */ 	nop
/*    4a97c:	00000000 */ 	nop
);
