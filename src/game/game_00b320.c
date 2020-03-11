#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_166e40.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f00b320
/*  f00b320:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00b324:	3c02800b */ 	lui	$v0,%hi(g_LangBanks)
/*  f00b328:	3c03800b */ 	lui	$v1,%hi(var800aabb4)
/*  f00b32c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00b330:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00b334:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f00b338:	2463abb4 */ 	addiu	$v1,$v1,%lo(var800aabb4)
/*  f00b33c:	2442aaa0 */ 	addiu	$v0,$v0,%lo(g_LangBanks)
.L0f00b340:
/*  f00b340:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f00b344:	1443fffe */ 	bne	$v0,$v1,.L0f00b340
/*  f00b348:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f00b34c:	0fc5b9bd */ 	jal	langGetFileId
/*  f00b350:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f00b354:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b358:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b35c:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b360:	3c10800b */ 	lui	$s0,%hi(g_LangBanks)
/*  f00b364:	2610aaa0 */ 	addiu	$s0,$s0,%lo(g_LangBanks)
/*  f00b368:	ae020098 */ 	sw	$v0,0x98($s0)
/*  f00b36c:	0fc5b9bd */ 	jal	langGetFileId
/*  f00b370:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f00b374:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b378:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b37c:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b380:	ae0200a0 */ 	sw	$v0,0xa0($s0)
/*  f00b384:	0fc5b9bd */ 	jal	langGetFileId
/*  f00b388:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f00b38c:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b390:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b394:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b398:	ae0200a4 */ 	sw	$v0,0xa4($s0)
/*  f00b39c:	0fc5b9bd */ 	jal	langGetFileId
/*  f00b3a0:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f00b3a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b3a8:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b3ac:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b3b0:	ae0200a8 */ 	sw	$v0,0xa8($s0)
/*  f00b3b4:	0fc5b9bd */ 	jal	langGetFileId
/*  f00b3b8:	2404002b */ 	addiu	$a0,$zero,0x2b
/*  f00b3bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b3c0:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b3c4:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b3c8:	ae0200ac */ 	sw	$v0,0xac($s0)
/*  f00b3cc:	0fc5b9bd */ 	jal	langGetFileId
/*  f00b3d0:	2404002c */ 	addiu	$a0,$zero,0x2c
/*  f00b3d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b3d8:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b3dc:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b3e0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f00b3e4:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f00b3e8:	ae0200b0 */ 	sw	$v0,0xb0($s0)
/*  f00b3ec:	55c10008 */ 	bnel	$t6,$at,.L0f00b410
/*  f00b3f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00b3f4:	0fc5b9bd */ 	jal	langGetFileId
/*  f00b3f8:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f00b3fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b400:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b404:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b408:	ae02009c */ 	sw	$v0,0x9c($s0)
/*  f00b40c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f00b410:
/*  f00b410:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00b414:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00b418:	03e00008 */ 	jr	$ra
/*  f00b41c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00b420
/*  f00b420:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00b424:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b428:	3c018006 */ 	lui	$at,0x8006
/*  f00b42c:	ac202410 */ 	sw	$zero,0x2410($at)
/*  f00b430:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b434:	0c0048f2 */ 	jal	malloc
/*  f00b438:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b43c:	3c01800a */ 	lui	$at,%hi(var8009cc80)
/*  f00b440:	ac22cc80 */ 	sw	$v0,%lo(var8009cc80)($at)
/*  f00b444:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b448:	0c0048f2 */ 	jal	malloc
/*  f00b44c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b450:	3c01800a */ 	lui	$at,%hi(var8009cc84)
/*  f00b454:	ac22cc84 */ 	sw	$v0,%lo(var8009cc84)($at)
/*  f00b458:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b45c:	0c0048f2 */ 	jal	malloc
/*  f00b460:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b464:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b468:	3c01800a */ 	lui	$at,%hi(var8009cc88)
/*  f00b46c:	ac22cc88 */ 	sw	$v0,%lo(var8009cc88)($at)
/*  f00b470:	03e00008 */ 	jr	$ra
/*  f00b474:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00b478:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b47c:	00000000 */ 	sll	$zero,$zero,0x0
);
