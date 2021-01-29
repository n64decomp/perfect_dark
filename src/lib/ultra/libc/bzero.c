#include <ultra64.h>

GLOBAL_ASM(
glabel bzero
/*    4b0c0:	28a1000c */ 	slti	$at,$a1,0xc
/*    4b0c4:	1420001d */ 	bnez	$at,.L0004b13c
/*    4b0c8:	00041823 */ 	negu	$v1,$a0
/*    4b0cc:	30630003 */ 	andi	$v1,$v1,0x3
/*    4b0d0:	10600003 */ 	beqz	$v1,.L0004b0e0
/*    4b0d4:	00a32823 */ 	subu	$a1,$a1,$v1
/*    4b0d8:	a8800000 */ 	swl	$zero,0x0($a0)
/*    4b0dc:	00832021 */ 	addu	$a0,$a0,$v1
.L0004b0e0:
/*    4b0e0:	2401ffe0 */ 	addiu	$at,$zero,-32
/*    4b0e4:	00a13824 */ 	and	$a3,$a1,$at
/*    4b0e8:	10e0000c */ 	beqz	$a3,.L0004b11c
/*    4b0ec:	00a72823 */ 	subu	$a1,$a1,$a3
/*    4b0f0:	00e43821 */ 	addu	$a3,$a3,$a0
.L0004b0f4:
/*    4b0f4:	24840020 */ 	addiu	$a0,$a0,0x20
/*    4b0f8:	ac80ffe0 */ 	sw	$zero,-0x20($a0)
/*    4b0fc:	ac80ffe4 */ 	sw	$zero,-0x1c($a0)
/*    4b100:	ac80ffe8 */ 	sw	$zero,-0x18($a0)
/*    4b104:	ac80ffec */ 	sw	$zero,-0x14($a0)
/*    4b108:	ac80fff0 */ 	sw	$zero,-0x10($a0)
/*    4b10c:	ac80fff4 */ 	sw	$zero,-0xc($a0)
/*    4b110:	ac80fff8 */ 	sw	$zero,-0x8($a0)
/*    4b114:	1487fff7 */ 	bne	$a0,$a3,.L0004b0f4
/*    4b118:	ac80fffc */ 	sw	$zero,-0x4($a0)
.L0004b11c:
/*    4b11c:	2401fffc */ 	addiu	$at,$zero,-4
/*    4b120:	00a13824 */ 	and	$a3,$a1,$at
/*    4b124:	10e00005 */ 	beqz	$a3,.L0004b13c
/*    4b128:	00a72823 */ 	subu	$a1,$a1,$a3
/*    4b12c:	00e43821 */ 	addu	$a3,$a3,$a0
.L0004b130:
/*    4b130:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4b134:	1487fffe */ 	bne	$a0,$a3,.L0004b130
/*    4b138:	ac80fffc */ 	sw	$zero,-0x4($a0)
.L0004b13c:
/*    4b13c:	18a00005 */ 	blez	$a1,.L0004b154
/*    4b140:	00000000 */ 	nop
/*    4b144:	00a42821 */ 	addu	$a1,$a1,$a0
.L0004b148:
/*    4b148:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4b14c:	1485fffe */ 	bne	$a0,$a1,.L0004b148
/*    4b150:	a080ffff */ 	sb	$zero,-0x1($a0)
.L0004b154:
/*    4b154:	03e00008 */ 	jr	$ra
/*    4b158:	00000000 */ 	nop
/*    4b15c:	00000000 */ 	nop
);
