#include <libultra_internal.h>

GLOBAL_ASM(
glabel osCreateMesgQueue
/*    48340:	3c0e8006 */ 	lui	$t6,%hi(__osThreadTail)
/*    48344:	3c0f8006 */ 	lui	$t7,%hi(__osThreadTail)
/*    48348:	25ce0930 */ 	addiu	$t6,$t6,%lo(__osThreadTail)
/*    4834c:	25ef0930 */ 	addiu	$t7,$t7,%lo(__osThreadTail)
/*    48350:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*    48354:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*    48358:	ac800008 */ 	sw	$zero,0x8($a0)
/*    4835c:	ac80000c */ 	sw	$zero,0xc($a0)
/*    48360:	ac860010 */ 	sw	$a2,0x10($a0)
/*    48364:	03e00008 */ 	jr	$ra
/*    48368:	ac850014 */ 	sw	$a1,0x14($a0)
/*    4836c:	00000000 */ 	nop
);
