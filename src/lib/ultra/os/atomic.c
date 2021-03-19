#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel __osAtomicDec
/*    4b730:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4b734:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4b738:	0c012a60 */ 	jal	0x4a980
/*    4b73c:	afa40020 */ 	sw	$a0,0x20($sp)
/*    4b740:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    4b744:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    4b748:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    4b74c:	11e00006 */ 	beqz	$t7,.NB0004b768
/*    4b750:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b754:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    4b758:	add80000 */ 	sw	$t8,0x0($t6)
/*    4b75c:	24190001 */ 	addiu	$t9,$zero,0x1
/*    4b760:	10000002 */ 	beqz	$zero,.NB0004b76c
/*    4b764:	afb90018 */ 	sw	$t9,0x18($sp)
.NB0004b768:
/*    4b768:	afa00018 */ 	sw	$zero,0x18($sp)
.NB0004b76c:
/*    4b76c:	0c012a7c */ 	jal	0x4a9f0
/*    4b770:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4b774:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4b778:	8fa20018 */ 	lw	$v0,0x18($sp)
/*    4b77c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4b780:	03e00008 */ 	jr	$ra
/*    4b784:	00000000 */ 	sll	$zero,$zero,0x0
);
