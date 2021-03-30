#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_39c80.h"
#include "lib/lib_39fe0.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3ccf0.h"
#include "lib/lib_3cdc0.h"
#include "lib/lib_3cef0.h"
#include "lib/lib_3d280.h"
#include "lib/lib_3e3e0.h"
#include "lib/lib_3e730.h"
#include "data.h"
#include "types.h"

struct var8009c340 var8009c340;
u32 var8009c344;
u32 var8009c348;

GLOBAL_ASM(
glabel func00034030
/*    34030:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    34034:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    34038:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3403c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    34040:	3c01800a */ 	lui	$at,%hi(var8009c340)
/*    34044:	a020c340 */ 	sb	$zero,%lo(var8009c340)($at)
/*    34048:	3c01800a */ 	lui	$at,%hi(var8009c340+0x1)
/*    3404c:	a020c341 */ 	sb	$zero,%lo(var8009c340+0x1)($at)
/*    34050:	3c01800a */ 	lui	$at,%hi(var8009c340+0x2)
/*    34054:	a020c342 */ 	sb	$zero,%lo(var8009c340+0x2)($at)
/*    34058:	93b0002b */ 	lbu	$s0,0x2b($sp)
/*    3405c:	24010001 */ 	addiu	$at,$zero,0x1
/*    34060:	12010009 */ 	beq	$s0,$at,.L00034088
/*    34064:	00000000 */ 	nop
/*    34068:	24010003 */ 	addiu	$at,$zero,0x3
/*    3406c:	1201000b */ 	beq	$s0,$at,.L0003409c
/*    34070:	00000000 */ 	nop
/*    34074:	24010004 */ 	addiu	$at,$zero,0x4
/*    34078:	1201000d */ 	beq	$s0,$at,.L000340b0
/*    3407c:	00000000 */ 	nop
/*    34080:	10000010 */ 	b	.L000340c4
/*    34084:	00000000 */ 	nop
.L00034088:
/*    34088:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3408c:	3c01800a */ 	lui	$at,%hi(var8009c340+0x1)
/*    34090:	a02ec341 */ 	sb	$t6,%lo(var8009c340+0x1)($at)
/*    34094:	1000000b */ 	b	.L000340c4
/*    34098:	00000000 */ 	nop
.L0003409c:
/*    3409c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    340a0:	3c01800a */ 	lui	$at,%hi(var8009c340+0x2)
/*    340a4:	a02fc342 */ 	sb	$t7,%lo(var8009c340+0x2)($at)
/*    340a8:	10000006 */ 	b	.L000340c4
/*    340ac:	00000000 */ 	nop
.L000340b0:
/*    340b0:	24180001 */ 	addiu	$t8,$zero,0x1
/*    340b4:	3c01800a */ 	lui	$at,%hi(var8009c340)
/*    340b8:	a038c340 */ 	sb	$t8,%lo(var8009c340)($at)
/*    340bc:	10000001 */ 	b	.L000340c4
/*    340c0:	00000000 */ 	nop
.L000340c4:
/*    340c4:	afa00024 */ 	sw	$zero,0x24($sp)
.L000340c8:
/*    340c8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    340cc:	0c00d041 */ 	jal	func00034104
/*    340d0:	00002825 */ 	or	$a1,$zero,$zero
/*    340d4:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    340d8:	27280001 */ 	addiu	$t0,$t9,0x1
/*    340dc:	29010002 */ 	slti	$at,$t0,0x2
/*    340e0:	1420fff9 */ 	bnez	$at,.L000340c8
/*    340e4:	afa80024 */ 	sw	$t0,0x24($sp)
/*    340e8:	10000001 */ 	b	.L000340f0
/*    340ec:	00000000 */ 	nop
.L000340f0:
/*    340f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    340f4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    340f8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    340fc:	03e00008 */ 	jr	$ra
/*    34100:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00034104
/*    34104:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    34108:	14a00004 */ 	bnez	$a1,.L0003411c
/*    3410c:	00000000 */ 	nop
/*    34110:	3c05800a */ 	lui	$a1,%hi(var8009c348)
/*    34114:	00a42821 */ 	addu	$a1,$a1,$a0
/*    34118:	90a5c348 */ 	lbu	$a1,%lo(var8009c348)($a1)
.L0003411c:
/*    3411c:	3c01800a */ 	lui	$at,%hi(var8009c344)
/*    34120:	00240821 */ 	addu	$at,$at,$a0
/*    34124:	a020c344 */ 	sb	$zero,%lo(var8009c344)($at)
/*    34128:	3c01800a */ 	lui	$at,%hi(var8009c344+0x2)
/*    3412c:	00240821 */ 	addu	$at,$at,$a0
/*    34130:	a020c346 */ 	sb	$zero,%lo(var8009c344+0x2)($at)
/*    34134:	00a03025 */ 	or	$a2,$a1,$zero
/*    34138:	24010002 */ 	addiu	$at,$zero,0x2
/*    3413c:	10c1000c */ 	beq	$a2,$at,.L00034170
/*    34140:	00000000 */ 	nop
/*    34144:	24010003 */ 	addiu	$at,$zero,0x3
/*    34148:	10c10013 */ 	beq	$a2,$at,.L00034198
/*    3414c:	00000000 */ 	nop
/*    34150:	24010004 */ 	addiu	$at,$zero,0x4
/*    34154:	10c1001a */ 	beq	$a2,$at,.L000341c0
/*    34158:	00000000 */ 	nop
/*    3415c:	24010005 */ 	addiu	$at,$zero,0x5
/*    34160:	10c10021 */ 	beq	$a2,$at,.L000341e8
/*    34164:	00000000 */ 	nop
/*    34168:	1000002d */ 	b	.L00034220
/*    3416c:	00000000 */ 	nop
.L00034170:
/*    34170:	3c0e800a */ 	lui	$t6,%hi(var8009c340)
/*    34174:	91cec340 */ 	lbu	$t6,%lo(var8009c340)($t6)
/*    34178:	11c00005 */ 	beqz	$t6,.L00034190
/*    3417c:	00000000 */ 	nop
/*    34180:	3c01800a */ 	lui	$at,%hi(var8009c344+0x2)
/*    34184:	00240821 */ 	addu	$at,$at,$a0
/*    34188:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    3418c:	a02fc346 */ 	sb	$t7,%lo(var8009c344+0x2)($at)
.L00034190:
/*    34190:	10000023 */ 	b	.L00034220
/*    34194:	00000000 */ 	nop
.L00034198:
/*    34198:	3c18800a */ 	lui	$t8,%hi(var8009c340)
/*    3419c:	9318c340 */ 	lbu	$t8,%lo(var8009c340)($t8)
/*    341a0:	13000005 */ 	beqz	$t8,.L000341b8
/*    341a4:	00000000 */ 	nop
/*    341a8:	3c01800a */ 	lui	$at,%hi(var8009c344)
/*    341ac:	00240821 */ 	addu	$at,$at,$a0
/*    341b0:	24190001 */ 	addiu	$t9,$zero,0x1
/*    341b4:	a039c344 */ 	sb	$t9,%lo(var8009c344)($at)
.L000341b8:
/*    341b8:	10000019 */ 	b	.L00034220
/*    341bc:	00000000 */ 	nop
.L000341c0:
/*    341c0:	3c08800a */ 	lui	$t0,%hi(var8009c340+0x1)
/*    341c4:	9108c341 */ 	lbu	$t0,%lo(var8009c340+0x1)($t0)
/*    341c8:	15000005 */ 	bnez	$t0,.L000341e0
/*    341cc:	00000000 */ 	nop
/*    341d0:	3c01800a */ 	lui	$at,%hi(var8009c344)
/*    341d4:	00240821 */ 	addu	$at,$at,$a0
/*    341d8:	24090001 */ 	addiu	$t1,$zero,0x1
/*    341dc:	a029c344 */ 	sb	$t1,%lo(var8009c344)($at)
.L000341e0:
/*    341e0:	1000000f */ 	b	.L00034220
/*    341e4:	00000000 */ 	nop
.L000341e8:
/*    341e8:	3c0a800a */ 	lui	$t2,%hi(var8009c340+0x1)
/*    341ec:	914ac341 */ 	lbu	$t2,%lo(var8009c340+0x1)($t2)
/*    341f0:	15400009 */ 	bnez	$t2,.L00034218
/*    341f4:	00000000 */ 	nop
/*    341f8:	3c01800a */ 	lui	$at,%hi(var8009c344)
/*    341fc:	00240821 */ 	addu	$at,$at,$a0
/*    34200:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    34204:	a02bc344 */ 	sb	$t3,%lo(var8009c344)($at)
/*    34208:	3c01800a */ 	lui	$at,%hi(var8009c344+0x2)
/*    3420c:	00240821 */ 	addu	$at,$at,$a0
/*    34210:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    34214:	a02cc346 */ 	sb	$t4,%lo(var8009c344+0x2)($at)
.L00034218:
/*    34218:	10000001 */ 	b	.L00034220
/*    3421c:	00000000 */ 	nop
.L00034220:
/*    34220:	3c01800a */ 	lui	$at,%hi(var8009c348)
/*    34224:	00240821 */ 	addu	$at,$at,$a0
/*    34228:	a025c348 */ 	sb	$a1,%lo(var8009c348)($at)
/*    3422c:	10000001 */ 	b	.L00034234
/*    34230:	00000000 */ 	nop
.L00034234:
/*    34234:	03e00008 */ 	jr	$ra
/*    34238:	27bd0008 */ 	addiu	$sp,$sp,0x8
);
