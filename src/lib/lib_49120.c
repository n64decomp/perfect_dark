#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func00049120
/*    49120:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    49124:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    49128:	0c01256c */ 	jal	__osDisableInt
/*    4912c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    49130:	0c012144 */ 	jal	osGetCount
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
/*    491a4:	00000000 */ 	nop
/*    491a8:	00000000 */ 	nop
/*    491ac:	00000000 */ 	nop
);
