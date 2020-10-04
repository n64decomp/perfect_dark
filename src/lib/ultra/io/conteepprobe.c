#include <libultra_internal.h>

GLOBAL_ASM(
glabel osEepromProbe
/*    50130:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    50134:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    50138:	0c012a18 */ 	jal	__osSiGetAccess
/*    5013c:	afa40030 */ 	sw	$a0,0x30($sp)
/*    50140:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    50144:	0c012fb9 */ 	jal	__osEepStatus
/*    50148:	27a50024 */ 	addiu	$a1,$sp,0x24
/*    5014c:	10400003 */ 	beqz	$v0,.L0005015c
/*    50150:	97ae0024 */ 	lhu	$t6,0x24($sp)
/*    50154:	1000000b */ 	b	.L00050184
/*    50158:	00001825 */ 	or	$v1,$zero,$zero
.L0005015c:
/*    5015c:	31cfc000 */ 	andi	$t7,$t6,0xc000
/*    50160:	34018000 */ 	dli	$at,0x8000
/*    50164:	11e10005 */ 	beq	$t7,$at,.L0005017c
/*    50168:	3401c000 */ 	dli	$at,0xc000
/*    5016c:	11e10005 */ 	beq	$t7,$at,.L00050184
/*    50170:	24030002 */ 	addiu	$v1,$zero,0x2
/*    50174:	10000003 */ 	b	.L00050184
/*    50178:	00001825 */ 	or	$v1,$zero,$zero
.L0005017c:
/*    5017c:	10000001 */ 	b	.L00050184
/*    50180:	24030001 */ 	addiu	$v1,$zero,0x1
.L00050184:
/*    50184:	0c012a29 */ 	jal	__osSiRelAccess
/*    50188:	afa3002c */ 	sw	$v1,0x2c($sp)
/*    5018c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    50190:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*    50194:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    50198:	03e00008 */ 	jr	$ra
/*    5019c:	00000000 */ 	nop
);
