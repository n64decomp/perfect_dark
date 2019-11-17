#include <ultra64.h>
#include "types.h"
#include "library/library_03050.h"

GLOBAL_ASM(
glabel func00013710
/*    13710:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    13714:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13718:	3c05800a */ 	lui	$a1,%hi(var80099a00)
/*    1371c:	3c06800a */ 	lui	$a2,%hi(var80099900)
/*    13720:	24c69900 */ 	addiu	$a2,$a2,%lo(var80099900)
/*    13724:	24a59a00 */ 	addiu	$a1,$a1,%lo(var80099a00)
/*    13728:	24040096 */ 	addiu	$a0,$zero,0x96
/*    1372c:	0c000cd8 */ 	jal	func00003360
/*    13730:	24070040 */ 	addiu	$a3,$zero,0x40
/*    13734:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13738:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1373c:	03e00008 */ 	jr	$ra
/*    13740:	00000000 */ 	sll	$zero,$zero,0x0
/*    13744:	00000000 */ 	sll	$zero,$zero,0x0
/*    13748:	00000000 */ 	sll	$zero,$zero,0x0
/*    1374c:	00000000 */ 	sll	$zero,$zero,0x0
);
