#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_48650.h"
#include "library/library_4a810.h"
#include "library/library_4a980.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004f350
/*    4f350:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4f354:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4f358:	afa40020 */ 	sw	$a0,0x20($sp)
/*    4f35c:	0c012a18 */ 	jal	func0004a860
/*    4f360:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    4f364:	3c0e800a */ 	lui	$t6,0x800a
/*    4f368:	91cec820 */ 	lbu	$t6,-0x37e0($t6)
/*    4f36c:	11c0000c */ 	beqz	$t6,.L0004f3a0
/*    4f370:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f374:	0c012af0 */ 	jal	func0004abc0
/*    4f378:	00002025 */ 	or	$a0,$zero,$zero
/*    4f37c:	3c05800a */ 	lui	$a1,%hi(var8009c7e0)
/*    4f380:	24a5c7e0 */ 	addiu	$a1,$a1,%lo(var8009c7e0)
/*    4f384:	0c012a34 */ 	jal	func0004a8d0
/*    4f388:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4f38c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    4f390:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    4f394:	00002825 */ 	or	$a1,$zero,$zero
/*    4f398:	0c0121bc */ 	jal	func000486f0
/*    4f39c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0004f3a0:
/*    4f3a0:	3c05800a */ 	lui	$a1,%hi(var8009c7e0)
/*    4f3a4:	24a5c7e0 */ 	addiu	$a1,$a1,%lo(var8009c7e0)
/*    4f3a8:	0c012a34 */ 	jal	func0004a8d0
/*    4f3ac:	00002025 */ 	or	$a0,$zero,$zero
/*    4f3b0:	3c01800a */ 	lui	$at,0x800a
/*    4f3b4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    4f3b8:	0c012a29 */ 	jal	func0004a8a4
/*    4f3bc:	a020c820 */ 	sb	$zero,-0x37e0($at)
/*    4f3c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4f3c4:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    4f3c8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4f3cc:	03e00008 */ 	jr	$ra
/*    4f3d0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004f3d4
/*    4f3d4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4f3d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4f3dc:	afa40020 */ 	sw	$a0,0x20($sp)
/*    4f3e0:	8fa50020 */ 	lw	$a1,0x20($sp)
/*    4f3e4:	0c012abc */ 	jal	func0004aaf0
/*    4f3e8:	27a4001f */ 	addiu	$a0,$sp,0x1f
/*    4f3ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4f3f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4f3f4:	03e00008 */ 	jr	$ra
/*    4f3f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f3fc:	00000000 */ 	sll	$zero,$zero,0x0
);