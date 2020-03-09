#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_48650.h"
#include "lib/lib_48b20.h"
#include "lib/lib_4ba90.h"
#include "types.h"

GLOBAL_ASM(
glabel osEepromLongWrite
/*     6440:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*     6444:	afb70040 */ 	sw	$s7,0x40($sp)
/*     6448:	afb6003c */ 	sw	$s6,0x3c($sp)
/*     644c:	afb2002c */ 	sw	$s2,0x2c($sp)
/*     6450:	afb10028 */ 	sw	$s1,0x28($sp)
/*     6454:	afb00024 */ 	sw	$s0,0x24($sp)
/*     6458:	00e08025 */ 	or	$s0,$a3,$zero
/*     645c:	30b100ff */ 	andi	$s1,$a1,0xff
/*     6460:	00c09025 */ 	or	$s2,$a2,$zero
/*     6464:	0080b825 */ 	or	$s7,$a0,$zero
/*     6468:	afbf0044 */ 	sw	$ra,0x44($sp)
/*     646c:	afb50038 */ 	sw	$s5,0x38($sp)
/*     6470:	afb40034 */ 	sw	$s4,0x34($sp)
/*     6474:	afb30030 */ 	sw	$s3,0x30($sp)
/*     6478:	afa5004c */ 	sw	$a1,0x4c($sp)
/*     647c:	18e00025 */ 	blez	$a3,.L00006514
/*     6480:	0000b025 */ 	or	$s6,$zero,$zero
/*     6484:	3c15800a */ 	lui	$s5,%hi(var8009c860)
/*     6488:	3c14800a */ 	lui	$s4,%hi(var8009c828)
/*     648c:	3c13800a */ 	lui	$s3,%hi(var8009c848)
/*     6490:	2673c848 */ 	addiu	$s3,$s3,%lo(var8009c848)
/*     6494:	2694c828 */ 	addiu	$s4,$s4,%lo(var8009c828)
/*     6498:	26b5c860 */ 	addiu	$s5,$s5,%lo(var8009c860)
/*     649c:	02e02025 */ 	or	$a0,$s7,$zero
.L000064a0:
/*     64a0:	322500ff */ 	andi	$a1,$s1,0xff
/*     64a4:	0c012f30 */ 	jal	func0004bcc0
/*     64a8:	02403025 */ 	or	$a2,$s2,$zero
/*     64ac:	10400003 */ 	beqz	$v0,.L000064bc
/*     64b0:	0040b025 */ 	or	$s6,$v0,$zero
/*     64b4:	10000019 */ 	beqz	$zero,.L0000651c
/*     64b8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L000064bc:
/*     64bc:	26310001 */ 	addiu	$s1,$s1,0x1
/*     64c0:	322e00ff */ 	andi	$t6,$s1,0xff
/*     64c4:	3c070008 */ 	lui	$a3,0x8
/*     64c8:	24180000 */ 	addiu	$t8,$zero,0x0
/*     64cc:	24190000 */ 	addiu	$t9,$zero,0x0
/*     64d0:	2610fff8 */ 	addiu	$s0,$s0,-8
/*     64d4:	01c08825 */ 	or	$s1,$t6,$zero
/*     64d8:	26520008 */ 	addiu	$s2,$s2,0x8
/*     64dc:	afb90014 */ 	sw	$t9,0x14($sp)
/*     64e0:	afb80010 */ 	sw	$t8,0x10($sp)
/*     64e4:	34e79544 */ 	ori	$a3,$a3,0x9544
/*     64e8:	02802025 */ 	or	$a0,$s4,$zero
/*     64ec:	24060000 */ 	addiu	$a2,$zero,0x0
/*     64f0:	afb30018 */ 	sw	$s3,0x18($sp)
/*     64f4:	0c0122c8 */ 	jal	func00048b20
/*     64f8:	afb5001c */ 	sw	$s5,0x1c($sp)
/*     64fc:	02602025 */ 	or	$a0,$s3,$zero
/*     6500:	00002825 */ 	or	$a1,$zero,$zero
/*     6504:	0c0121bc */ 	jal	osRecvMesg
/*     6508:	24060001 */ 	addiu	$a2,$zero,0x1
/*     650c:	5e00ffe4 */ 	bgtzl	$s0,.L000064a0
/*     6510:	02e02025 */ 	or	$a0,$s7,$zero
.L00006514:
/*     6514:	02c01025 */ 	or	$v0,$s6,$zero
/*     6518:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0000651c:
/*     651c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*     6520:	8fb10028 */ 	lw	$s1,0x28($sp)
/*     6524:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*     6528:	8fb30030 */ 	lw	$s3,0x30($sp)
/*     652c:	8fb40034 */ 	lw	$s4,0x34($sp)
/*     6530:	8fb50038 */ 	lw	$s5,0x38($sp)
/*     6534:	8fb6003c */ 	lw	$s6,0x3c($sp)
/*     6538:	8fb70040 */ 	lw	$s7,0x40($sp)
/*     653c:	03e00008 */ 	jr	$ra
/*     6540:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*     6544:	00000000 */ 	sll	$zero,$zero,0x0
/*     6548:	00000000 */ 	sll	$zero,$zero,0x0
/*     654c:	00000000 */ 	sll	$zero,$zero,0x0
);