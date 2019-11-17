#include <ultra64.h>
#include "types.h"
#include "library/library_13750.h"
#include "library/library_481e0.h"

void func00013750(void)
{
	// empty
}

GLOBAL_ASM(
glabel func00013758
/*    13758:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1375c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13760:	3c04800a */ 	lui	$a0,%hi(var80099a40)
/*    13764:	3c05800a */ 	lui	$a1,%hi(var80099a20)
/*    13768:	24a59a20 */ 	addiu	$a1,$a1,%lo(var80099a20)
/*    1376c:	24849a40 */ 	addiu	$a0,$a0,%lo(var80099a40)
/*    13770:	0c0120d0 */ 	jal	func00048340
/*    13774:	24060008 */ 	addiu	$a2,$zero,0x8
/*    13778:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1377c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    13780:	03e00008 */ 	jr	$ra
/*    13784:	00000000 */ 	sll	$zero,$zero,0x0
/*    13788:	00000000 */ 	sll	$zero,$zero,0x0
/*    1378c:	00000000 */ 	sll	$zero,$zero,0x0
);