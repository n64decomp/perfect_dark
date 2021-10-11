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

void speakersSetMode(u8 mode)
{
	s32 i;

	var8009c340.surround = 0;
	var8009c340.mono = 0;
	var8009c340.headphone = 0;

	switch (mode) {
	case SPEAKERMODE_MONO:
		var8009c340.mono = 1;
		break;
	case SPEAKERMODE_HEADPHONE:
		var8009c340.headphone = 1;
		break;
	case SPEAKERMODE_SURROUND:
		var8009c340.surround = 1;
		break;
	}

	for (i = 0; i < 2; i++) {
		speaker00034104(i, 0);
	}
}

GLOBAL_ASM(
glabel speaker00034104
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
