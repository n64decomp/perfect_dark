#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_19aa80.h"
#include "game/mplayer.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f00b210
/*  f00b210:	27bdfdf8 */ 	addiu	$sp,$sp,-520
/*  f00b214:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f00b218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00b21c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f00b220:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00b224:	3c108009 */ 	lui	$s0,%hi(g_MpChallenges)
/*  f00b228:	3c128009 */ 	lui	$s2,%hi(g_MpChallenges+0x9)
/*  f00b22c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f00b230:	265284c1 */ 	addiu	$s2,$s2,%lo(g_MpChallenges+0x9)
/*  f00b234:	261084b8 */ 	addiu	$s0,$s0,%lo(g_MpChallenges)
/*  f00b238:	00008825 */ 	or	$s1,$zero,$zero
/*  f00b23c:	27b30038 */ 	addiu	$s3,$sp,0x38
.L0f00b240:
/*  f00b240:	a2000004 */ 	sb	$zero,0x4($s0)
/*  f00b244:	a2000005 */ 	sb	$zero,0x5($s0)
/*  f00b248:	a2000006 */ 	sb	$zero,0x6($s0)
/*  f00b24c:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f00b250:	a2000008 */ 	sb	$zero,0x8($s0)
/*  f00b254:	02202025 */ 	or	$a0,$s1,$zero
/*  f00b258:	02602825 */ 	or	$a1,$s3,$zero
/*  f00b25c:	0fc66e96 */ 	jal	mpLoadChallenge
/*  f00b260:	240601ca */ 	addiu	$a2,$zero,0x1ca
/*  f00b264:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b268:	02402825 */ 	or	$a1,$s2,$zero
/*  f00b26c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f00b270:	0fc66f53 */ 	jal	func0f19bd4c
/*  f00b274:	02203825 */ 	or	$a3,$s1,$zero
/*  f00b278:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00b27c:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f00b280:	2610001a */ 	addiu	$s0,$s0,0x1a
/*  f00b284:	1420ffee */ 	bnez	$at,.L0f00b240
/*  f00b288:	2652001a */ 	addiu	$s2,$s2,0x1a
/*  f00b28c:	0fc636df */ 	jal	mpGetNumPresets
/*  f00b290:	00008825 */ 	or	$s1,$zero,$zero
/*  f00b294:	18400017 */ 	blez	$v0,.L0f00b2f4
/*  f00b298:	00117080 */ 	sll	$t6,$s1,0x2
/*  f00b29c:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f00b2a0:	3c0f8008 */ 	lui	$t7,%hi(g_MpPresets)
/*  f00b2a4:	25ef7b6c */ 	addiu	$t7,$t7,%lo(g_MpPresets)
/*  f00b2a8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f00b2ac:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f00b2b0:	26120008 */ 	addiu	$s2,$s0,0x8
/*  f00b2b4:	8e040004 */ 	lw	$a0,0x4($s0)
.L0f00b2b8:
/*  f00b2b8:	02602825 */ 	or	$a1,$s3,$zero
/*  f00b2bc:	0fc66e45 */ 	jal	mpLoadConfig
/*  f00b2c0:	240601ca */ 	addiu	$a2,$zero,0x1ca
/*  f00b2c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b2c8:	02402825 */ 	or	$a1,$s2,$zero
/*  f00b2cc:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f00b2d0:	0fc66f53 */ 	jal	func0f19bd4c
/*  f00b2d4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f00b2d8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00b2dc:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f00b2e0:	0fc636df */ 	jal	mpGetNumPresets
/*  f00b2e4:	26520018 */ 	addiu	$s2,$s2,24
/*  f00b2e8:	0222082a */ 	slt	$at,$s1,$v0
/*  f00b2ec:	5420fff2 */ 	bnezl	$at,.L0f00b2b8
/*  f00b2f0:	8e040004 */ 	lw	$a0,0x4($s0)
.L0f00b2f4:
/*  f00b2f4:	0fc66bf7 */ 	jal	func0f19afdc
/*  f00b2f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b2fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f00b300:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00b304:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00b308:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f00b30c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f00b310:	03e00008 */ 	jr	$ra
/*  f00b314:	27bd0208 */ 	addiu	$sp,$sp,0x208
/*  f00b318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b31c:	00000000 */ 	sll	$zero,$zero,0x0
);
