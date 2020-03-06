#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_481e0.h"
#include "lib/lib_491b0.h"
#include "lib/lib_4b500.h"
#include "types.h"

GLOBAL_ASM(
glabel func000490b0
/*    490b0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    490b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    490b8:	0c01256c */ 	jal	__osDisableInt
/*    490bc:	afa40020 */ 	sw	$a0,0x20($sp)
/*    490c0:	3c0f8006 */ 	lui	$t7,%hi(var80060914)
/*    490c4:	8def0914 */ 	lw	$t7,%lo(var80060914)($t7)
/*    490c8:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    490cc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    490d0:	3c188006 */ 	lui	$t8,%hi(var80060914)
/*    490d4:	adee0004 */ 	sw	$t6,0x4($t7)
/*    490d8:	8f180914 */ 	lw	$t8,%lo(var80060914)($t8)
/*    490dc:	97190000 */ 	lhu	$t9,0x0($t8)
/*    490e0:	37280010 */ 	ori	$t0,$t9,0x10
/*    490e4:	a7080000 */ 	sh	$t0,0x0($t8)
/*    490e8:	0c012588 */ 	jal	__osRestoreInt
/*    490ec:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    490f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    490f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    490f8:	03e00008 */ 	jr	$ra
/*    490fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00049100
/*    49100:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    49104:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49108:	0c012d40 */ 	jal	func0004b500
/*    4910c:	24040400 */ 	addiu	$a0,$zero,0x400
/*    49110:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    49114:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    49118:	03e00008 */ 	jr	$ra
/*    4911c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00049120
/*    49120:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    49124:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    49128:	0c01256c */ 	jal	__osDisableInt
/*    4912c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    49130:	0c012144 */ 	jal	func00048510
/*    49134:	00408025 */ 	or	$s0,$v0,$zero
/*    49138:	afa20034 */ 	sw	$v0,0x34($sp)
/*    4913c:	3c0f800a */ 	lui	$t7,%hi(var8009c788)
/*    49140:	8defc788 */ 	lw	$t7,%lo(var8009c788)($t7)
/*    49144:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    49148:	3c08800a */ 	lui	$t0,%hi(var8009c780)
/*    4914c:	3c09800a */ 	lui	$t1,%hi(var8009c784)
/*    49150:	8d29c784 */ 	lw	$t1,%lo(var8009c784)($t1)
/*    49154:	8d08c780 */ 	lw	$t0,%lo(var8009c780)($t0)
/*    49158:	01cfc023 */ 	subu	$t8,$t6,$t7
/*    4915c:	afb80030 */ 	sw	$t8,0x30($sp)
/*    49160:	02002025 */ 	or	$a0,$s0,$zero
/*    49164:	afa9002c */ 	sw	$t1,0x2c($sp)
/*    49168:	0c012588 */ 	jal	__osRestoreInt
/*    4916c:	afa80028 */ 	sw	$t0,0x28($sp)
/*    49170:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    49174:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    49178:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4917c:	03205825 */ 	or	$t3,$t9,$zero
/*    49180:	016d1821 */ 	addu	$v1,$t3,$t5
/*    49184:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    49188:	240a0000 */ 	addiu	$t2,$zero,0x0
/*    4918c:	006d082b */ 	sltu	$at,$v1,$t5
/*    49190:	002a1021 */ 	addu	$v0,$at,$t2
/*    49194:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    49198:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    4919c:	03e00008 */ 	jr	$ra
/*    491a0:	004c1021 */ 	addu	$v0,$v0,$t4
/*    491a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    491a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    491ac:	00000000 */ 	sll	$zero,$zero,0x0
);