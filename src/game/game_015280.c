#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0601b0.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f015280
/*  f015280:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f015284:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f015288:	3c018008 */ 	lui	$at,%hi(var8007e4a0)
/*  f01528c:	44806000 */ 	mtc1	$zero,$f12
/*  f015290:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f015294:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f015298:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f01529c:	0c002a94 */ 	jal	func0000aa50
/*  f0152a0:	ac20e4a0 */ 	sw	$zero,%lo(var8007e4a0)($at)
/*  f0152a4:	3c11800a */ 	lui	$s1,%hi(var800a3430)
/*  f0152a8:	26313430 */ 	addiu	$s1,$s1,%lo(var800a3430)
/*  f0152ac:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0152b0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0152b4:	24121ad0 */ 	addiu	$s2,$zero,0x1ad0
/*  f0152b8:	51c00017 */ 	beqzl	$t6,.L0f015318
/*  f0152bc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0152c0:	8e2f0000 */ 	lw	$t7,0x0($s1)
.L0f0152c4:
/*  f0152c4:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f0152c8:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f0152cc:	5080000f */ 	beqzl	$a0,.L0f01530c
/*  f0152d0:	26100478 */ 	addiu	$s0,$s0,0x478
/*  f0152d4:	0fc18171 */ 	jal	func0f0605c4
/*  f0152d8:	00000000 */ 	nop
/*  f0152dc:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0152e0:	03304021 */ 	addu	$t0,$t9,$s0
/*  f0152e4:	0fc180c0 */ 	jal	func0f060300
/*  f0152e8:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f0152ec:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f0152f0:	01305021 */ 	addu	$t2,$t1,$s0
/*  f0152f4:	0fc1810e */ 	jal	propFree
/*  f0152f8:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f0152fc:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f015300:	01706021 */ 	addu	$t4,$t3,$s0
/*  f015304:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f015308:	26100478 */ 	addiu	$s0,$s0,0x478
.L0f01530c:
/*  f01530c:	5612ffed */ 	bnel	$s0,$s2,.L0f0152c4
/*  f015310:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f015314:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f015318:
/*  f015318:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f01531c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f015320:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f015324:	03e00008 */ 	jr	$ra
/*  f015328:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f01532c:	00000000 */ 	nop
);
